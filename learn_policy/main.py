from pathlib import Path
import hydra
import pytorch_lightning as pl
from common.models import D1MLP
import torch.utils.data
from torch.utils.data import Dataset
import torch as th
from omegaconf import OmegaConf
from pytorch_lightning import loggers as pl_loggers
from dynamics import RefinementZeroDynamics, ZeroDynamics

from common import exp_cfg

ROOT = Path(__file__).parent
run_data_root = ROOT / 'run_data'
config_path = ROOT / 'configs'

# def set_debug_apis(state: bool = False):
#     # torch.autograd.profiler.profile(enabled=state)
#     # torch.autograd.profiler.emit_nvtx(enabled=state)
#     torch.autograd.set_detect_anomaly(mode=state)
#
#
# # Then in training code before the train loop
# set_debug_apis(state=True)

def get_module_name(config):
    return str(config._metadata.object_type).split('.')[-1][:-2]

class ZCubeSamplerDataSet(Dataset):
    def __init__(self, batch_size, zdyn):
        super().__init__()
        self.zdyn = zdyn
        self.batch_size = batch_size
        self.z1_sampler = th.distributions.Uniform(th.tensor(-1.), th.tensor(1.))
        self.z2_sampler = th.distributions.Uniform(th.tensor(-1.), th.tensor(1.))

    def __getitem__(self, item):
        stop = False
        patience = 30
        while not stop:
            z1_samples = self.z1_sampler.sample((1,))
            z2_samples = self.z2_sampler.sample((1,))
            z_samples = th.stack([z1_samples, z2_samples], dim=1)
            z_samples = z_samples @ th.tensor([[0.3, 0.], [0.0, 50.]])
            collision_mask = self.zdyn.pos_event_function(0.0, z_samples) <= -0
            if ~collision_mask[0, 0].item():
                return z_samples[0]
            patience -= 1
            if patience == 0:
                raise RuntimeError("[ERROR] You ran out of patience.")

    def __len__(self):
        return self.batch_size

from torch.utils.data.dataset import IterableDataset
class BatchZCubeSamplerDataSet(IterableDataset):
    def __init__(self, batch_size, zdyn):
        super().__init__()
        self.zdyn = zdyn
        self.batch_size = batch_size
        self.z1_sampler = th.distributions.Uniform(th.tensor(-1.), th.tensor(1.))
        self.z2_sampler = th.distributions.Uniform(th.tensor(-1.), th.tensor(1.))
        self.scale_mat = th.tensor([[0.3, 0.], [0.0, 50.]])
    def match_device(self):
        device = next(self.zdyn.parameters()).device
        curr_device = self.z1_sampler.low.device
        if device != curr_device:
            self.z1_sampler.low = self.z1_sampler.low.to(device)
            self.z1_sampler.high = self.z1_sampler.high.to(device)
            self.z2_sampler.low = self.z2_sampler.low.to(device)
            self.z2_sampler.high =self.z2_sampler.high.to(device)
            self.scale_mat = self.scale_mat.to(device)
    def __iter__(self):
        with torch.no_grad():
            stop = False
            idx = 0
            z_samples = None
            while not stop:
                self.match_device()
                z1_samples = self.z1_sampler.sample((self.batch_size,))
                z2_samples = self.z2_sampler.sample((self.batch_size,))
                temp_z_samples = th.stack([z1_samples, z2_samples], dim=1)
                # z_samples = z_samples @ th.tensor([[0.3, -15.], [0.0, 25.]], device=device_name)
                temp_z_samples = temp_z_samples @ self.scale_mat
                #TODO: We shouldn't lose the lottery here
                #This is a hack and needs to be fixed.
                z_samples = temp_z_samples
                break
                collision_mask = self.zdyn.pos_event_function(0.0,  temp_z_samples) <=-0
                valid_zs = temp_z_samples[~collision_mask[:, 0]]
                #uncomment for COT
                # valid_zs = th.cat([valid_zs, th.zeros(valid_zs.shape[0], 1, device=device_name)], dim=1)
                # if valid_zs.shape[0] < n_batch:
                #     raise RuntimeError("[ERROR] You lost the lottery.")
                # z_samples = valid_zs[:n_batch]
                # z_samples = th.cat([z_samples, th.zeros(n_batch, 1, device=z_samples.device)], dim=1)
                if z_samples is None:
                    combined_size = valid_zs.shape[0]
                else:
                    combined_size = z_samples.shape[0] + valid_zs.shape[0]

                if combined_size < self.batch_size:
                    if z_samples is None:
                        z_samples = valid_zs
                    else:
                        z_samples = th.cat([z_samples, valid_zs], dim=0)
                    idx += 1
                else:
                    if z_samples is None:
                        z_samples = valid_zs
                    else:
                        z_samples = th.cat([z_samples, valid_zs[:(
                            self.batch_size - combined_size)]], dim=0)
                    stop = True
                if idx >= 15:
                    raise RuntimeError("[ERROR] You REALLY lost the lottery.")
            yield z_samples

class BatchOrbitalEnergySampler(IterableDataset):
    def __init__(self, batch_size, zdyn):
        super().__init__()
        self.zdyn = zdyn
        self.batch_size = batch_size
        self.z1_sampler = th.distributions.Uniform(th.tensor(-0.2), th.tensor(0.2))
        self.orbital_energy_sampler = th.distributions.Uniform(th.tensor(0.0),
                                                               th.tensor(1.))
        self.mass = th.tensor(21.5562)
        self.g = th.tensor(9.81)
        self.z = th.tensor(0.9)

    def match_device(self):
        device = next(self.zdyn.parameters()).device
        curr_device = self.z1_sampler.low.device
        if device != curr_device:
            self.z1_sampler.low = self.z1_sampler.low.to(device)
            self.z1_sampler.high = self.z1_sampler.high.to(device)
            self.orbital_energy_sampler.low = self.orbital_energy_sampler.low.to(device)
            self.orbital_energy_sampler.high = self.orbital_energy_sampler.high.to(device)
            self.mass = self.mass.to(device)
            self.g = self.g.to(device)
            self.z = self.z.to(device)

    def __iter__(self):
        with torch.no_grad():
            self.match_device()
            z1_samples = self.z1_sampler.sample((self.batch_size,))
            orbital_energy_samples = self.orbital_energy_sampler.sample((self.batch_size,))
            z2 = -th.sqrt(orbital_energy_samples + (self.g / self.z) * z1_samples**2 )
            yield th.stack([z1_samples, z2*self.mass*self.z], dim=-1)

class Experiment:
    def __init__(self, cfg, progbar=True,
                 project="SampledWalking"):

        self.cfg = cfg

        # logger = pl_loggers.WandbLogger(
        #     name=self.create_log_name(),
        #     entity="ivan",
        #     project=project,
        #     log_model = "all",
        #     save_dir=str(run_data_root / 'wandb_output'),
        # )
        logger = pl_loggers.TensorBoardLogger(
            name=self.create_log_name(),
            # project=project,
            # log_model = "all",
            save_dir=str(run_data_root / 'tensorboard_output'),
        )
        logger.log_hyperparams(dict(self.cfg))
        OmegaConf.resolve(cfg)
        callbacks = []
        if not cfg.disable_logs:
            callbacks = [
                pl.callbacks.LearningRateMonitor(logging_interval='step'),
                pl.callbacks.ModelCheckpoint(monitor='training_loss',
                                             save_top_k=1000,
                                             mode='min',
                                             every_n_epochs=1,
                                             save_on_train_epoch_end=True),
            ]
        self.trainer = pl.Trainer(
            logger = logger if not cfg.disable_logs else False,
            max_epochs = cfg.max_epochs,
            log_every_n_steps=1,
            check_val_every_n_epoch=cfg.max_epochs,
            default_root_dir=str(run_data_root / 'lightning_logs' / self.create_log_name()),
            gpus=cfg.gpus,
            callbacks=callbacks,
            progress_bar_refresh_rate=None if progbar else 0
        )
        pl.seed_everything(cfg.seed)

    def run(self, checkpoint_module=None):
        if checkpoint_module is None:
            #TODO: Dangerous don't this at home.
            if self.cfg.pretrained_model is not None:
                pretrained = th.load(self.cfg.pretrained_model)
                D1MLP.instance = pretrained
            if self.cfg.pretrained_zdyn is not None:
                print("[INFO] Refining Pretrained Zdyn")
                # download and instantiate zdyn ignore everything else
                save_dir = Path(__file__).parent / "run_data" / "wandb_saves"
                import wandb
                api = wandb.Api()
                artifact = api.artifact(f"ivan/SampledWalkingDyn/{self.cfg.pretrained_zdyn}")
                file_location = artifact.file(root=str(save_dir))
                model_ckpt = th.load(file_location)
                learned_zdyn = model_ckpt['zdyn'].to('cpu')
                refinement_zdyn = RefinementZeroDynamics(yd=learned_zdyn.yd,
                                                     epsilon=learned_zdyn.epsilon)
                for p in learned_zdyn.yd.parameters():
                    p.requires_grad = True
                eval(self.cfg.module.yd._target_.split('.')[1]).instance = learned_zdyn.yd

                ZeroDynamics.instance = refinement_zdyn
            module = hydra.utils.instantiate(self.cfg.module)
        else:
            module = checkpoint_module
        if self.cfg.dataset == "CubeSampler":
            dataset = BatchZCubeSamplerDataSet(batch_size=self.cfg.batch_size, zdyn=module.zdyn)
        elif self.cfg.dataset == "OrbitalSampler":
            dataset = BatchOrbitalEnergySampler(batch_size=self.cfg.batch_size, zdyn=module.zdyn)
        else:
            raise Exception(f"[ERROR] Invalid Dataset {self.cfg.dataset}")
        train_loader = torch.utils.data.DataLoader(
            dataset,
            num_workers=0
        )
        self.trainer.fit(module,
                         train_dataloaders=train_loader)
        return module

    def create_log_name(self):
        if self.cfg.pretrained_zdyn is not None:
            returns = f'[REFINED]{self.cfg.name_prefix}'
        else:
            returns = self.cfg.name_prefix
        returns += f'zdyn:{get_module_name(self.cfg.module.zdyn)}'
        returns += f'_yd:{get_module_name(self.cfg.module.yd)}'
        num_composites = [str(len(bs.barriers_list)) for bs in
                          self.cfg.module.composite_barrier.mask_barriers_pairs]
        returns += f'_cb:({",".join(num_composites)})'
        returns += f'_b:{self.cfg.batch_size}'
        returns += f'_lr:{self.cfg.module.lr}'
        returns += f'_opt:{self.cfg.module.opt_name}'
        return returns

# def fill_mask_pairs(cfg):
#     cfg.module.composite_barrier.mask_barriers_pairs = [
#         exp_cfg.MaskBarrierPair(
#             mask=exp_cfg.AllMask(),
#             barriers_list=[
#                       exp_cfg.TorsoAngle(lb=-math.pi/4., ub=math.pi/10., alpha_lb=10., alpha_ub=10., apply_to_post_impact=True),
#                       exp_cfg.StepCircle(lb=0.0, ub=0.15, alpha_lb=50., alpha_ub=50., left=-0.3, right=0.3, center=0.0, apex=0.15),
#                       exp_cfg.StepWidth(),
#                       # exp_cfg.PelvisHeight(),
#                       # exp_cfg.Z0Dot(),
#                       # exp_cfg.InputBounds()
#                       ]
#         ),
#         exp_cfg.MaskBarrierPair(
#             # mask=exp_cfg.ForwardGuardMask(edge=0.3),
#             # mask=exp_cfg.GuardMask(edge=0.3),
#             mask=exp_cfg.RealGuardMask(tol=1e-3),
#             barriers_list=[
#                       exp_cfg.HorizontalVelocity(lb=0.1, ub=0.1, alpha_lb=1., alpha_ub=1.),
#                       # exp_cfg.HDeltaExplicit(lb=-0.05, ub=0.05, alpha=1., alpha_lb=1., alpha_ub=1., ),
#                       exp_cfg.OutputSymmetryLoss(lb=0.0, ub=None, alpha_lb=5., alpha_ub=5., loss_gain=1e0),
#                       # exp_cfg.OutputSymmetry(lb=0., ub=None, alpha_lb=20., alpha_ub=20.),
#                       # exp_cfg.ZBounds()
#             ]
#         ),
#         exp_cfg.MaskBarrierPair(
#             mask=exp_cfg.GuardMask(edge=0.3),
#             barriers_list=[
#                 exp_cfg.HDeltaExplicitLoss(lb=-0.05, ub=0.05, alpha=1., alpha_lb=1., alpha_ub=1., loss_gain=1e1),
#                 exp_cfg.FootOnGuard(lb=0, ub=0, alpha_lb=1, alpha_ub=1)
#             ]
#         )
#     ]
def fill_mask_pairs(cfg):
    cfg.module.composite_barrier.mask_barriers_pairs = OmegaConf.structured([
        exp_cfg.MaskBarrierPair(
            mask=exp_cfg.AllMask(),
            barriers_list=[
                exp_cfg.TorsoAngle(lb=-0.2, ub=0.05, alpha_lb=10.,
                                   alpha_ub=10.,
                                   apply_to_post_impact=True),
                # exp_cfg.OrbitalBarrier(lb=1.5, ub=3.5, alpha_lb=.1, alpha_ub=1., apply_to_post_impact=False),
                exp_cfg.StepCircle(lb=0.0, ub=0.8,
                                   alpha_lb=50., alpha_ub=50., left=-0.2,
                                   right=0.3, center=0.2,
                                   apex=0.03),
                # exp_cfg.StepCircleLoss(lb=0.0, ub=0.5, alpha_lb=50., alpha_ub=50., left=-0.4, right=0.4, center=0.0,
                #                    apex=0.1, loss_gain=1.),
                # exp_cfg.GRF(lb=0, alpha_lb=1.),
                # exp_cfg.StepWidth(alpha=0.5, lb=-0.1, ub=0.1),
                # exp_cfg.PelvisHeight(),
                # exp_cfg.Z0Dot(),
                # exp_cfg.HorizontalVelocity(),
                # exp_cfg.InputBounds()
            ]
        ),
        exp_cfg.MaskBarrierPair(
            mask=exp_cfg.BothGuardMask(edge=0.2, offset=0.01),
            # mask=exp_cfg.RealGuardMask(),
            barriers_list=[
                # exp_cfg.DiscreteTimeOrbitalBarrier(lb=.5, ub=1.5, alpha_lb=0, alpha_ub=0),
                exp_cfg.HDeltaExplicitLoss(lb=-0.15, ub=0.15, alpha=1., alpha_lb=1., alpha_ub=1., loss_gain=10),
                exp_cfg.OutputSymmetryWithVelLoss(lb=-10000.0, ub=None, alpha_lb=5., alpha_ub=5., loss_gain=3e0),
                exp_cfg.FootOnGuardLoss(lb=0, ub=0, alpha_lb=1, alpha_ub=1, loss_gain=10),

                # exp_cfg.ZBounds()
            ]),
        exp_cfg.MaskBarrierPair(
            mask=exp_cfg.ForwardGuardMask(edge=0.2, offset=0.05),
            barriers_list=[
                exp_cfg.HDeltaExplicit(lb=-0.15, ub=0.15, alpha=1., alpha_lb=1., alpha_ub=1.),
                exp_cfg.OutputSymmetry(lb=-0.0, ub=None, alpha_lb=0.1, alpha_ub=5.),
                # exp_cfg.FootOnGuard(lb=0., ub=None, alpha_lb=0., alpha_ub=1),
                # exp_cfg.ZBounds()
            ])
    ])

@hydra.main(
    config_path=str(config_path),
    config_name='default'
)
def main(cfg: exp_cfg.ExpCfg):
    fill_mask_pairs(cfg)
    OmegaConf.resolve(cfg)
    pipeline = Experiment(cfg)
    pipeline.run()

if __name__ == '__main__':
    main()