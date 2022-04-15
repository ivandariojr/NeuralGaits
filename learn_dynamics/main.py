import os
from pathlib import Path
import pl_modules
import barriers
import hydra
import pytorch_lightning as pl
from models import D1MLP
import torch.utils.data
from torch.utils.data import Dataset
import torch as th
from omegaconf import OmegaConf
from pytorch_lightning import loggers as pl_loggers
from load_amber_data import AmberRealDataSet
from torch.utils.data import random_split

import exp_cfg

ROOT = Path(__file__).parent.parent
run_data_root = ROOT / 'run_data'
config_path = ROOT / 'configs'

def get_module_name(config):
    return str(config._metadata.object_type).split('.')[-1][:-2]

class Experiment:
    def __init__(self, cfg, progbar=True,
                 project="SampledWalkingDyn"):

        self.cfg = cfg

        logger = pl_loggers.WandbLogger(
            name=self.create_log_name(),
            entity="ivan",
            project=project,
            log_model = "all",
            save_dir=str(run_data_root / 'wandb_output'),
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
                                             every_n_train_steps=1,
                                             save_on_train_epoch_end=True),
            ]
        self.trainer = pl.Trainer(
            logger = logger if not cfg.disable_logs else False,
            max_epochs = cfg.max_epochs,
            log_every_n_steps=1,
            check_val_every_n_epoch=1,
            default_root_dir=str(run_data_root / 'lightning_logs' / self.create_log_name()),
            gpus=cfg.gpus,
            callbacks=callbacks,
            progress_bar_refresh_rate=None if progbar else 0,
        )
        pl.seed_everything(cfg.seed)
    def run(self, checkpoint_module=None):
        if checkpoint_module is None:
            #TODO: Dangerous don't this at home.
            if self.cfg.pretrained_yd is not None:
                save_dir = Path(__file__).parent.parent / "run_data" / "wandb_saves"
                import wandb
                api = wandb.Api()
                artifact = api.artifact(f"ivan/SampledWalking/{self.cfg.pretrained_yd}")
                file_location = artifact.file(root=str(save_dir))
                model_ckpt = th.load(file_location)
                pretrained = model_ckpt['yd']
                D1MLP.instance = pretrained
            module = hydra.utils.instantiate(self.cfg.module)
        else:
            module = checkpoint_module
        dataset = AmberRealDataSet(dataset_names=self.cfg.datasets,
                                   delta_t=self.cfg.delta_t,
                                   n_steps=self.cfg.n_steps)
        train_len = int(len(dataset)*.7)
        val_len = int(len(dataset)*.1)
        test_len = len(dataset) - (train_len + val_len)
        train_ds, val_ds, test_ds = random_split(dataset,
                                                 [train_len, val_len, test_len])
        train_loader = torch.utils.data.DataLoader(
            train_ds,
            num_workers=self.cfg.data_loader_workers,
            batch_size=self.cfg.batch_size)
        val_loader = torch.utils.data.DataLoader(
            val_ds,
            num_workers=self.cfg.data_loader_workers,
            batch_size=val_len)
        test_loader = torch.utils.data.DataLoader(
            test_ds,
            num_workers=self.cfg.data_loader_workers,
            batch_size=test_len)
        self.trainer.fit(module,
                         train_dataloader=train_loader,
                         val_dataloaders=val_loader)
        self.trainer.test(module, test_loader)
        return module

    def create_log_name(self):
        returns = self.cfg.name_prefix
        returns += f'zdyn:{get_module_name(self.cfg.module.zdyn)}'
        returns += f'_yd:{get_module_name(self.cfg.module.yd)}'
        # num_composites = [str(len(bs.barriers_list)) for bs in
        #                   self.cfg.module.composite_barrier.mask_barriers_pairs]
        # returns += f'_cb:({",".join(num_composites)})'
        returns += f'_b:{self.cfg.batch_size}'
        returns += f'_lr:{self.cfg.module.lr}'
        returns += f'_opt:{self.cfg.module.opt_name}'
        return returns


@hydra.main(
    config_path=str(config_path),
    config_name='dyn_learn'
)
def main(cfg: exp_cfg.ExpCfg):
    OmegaConf.resolve(cfg)
    pipeline = Experiment(cfg)
    pipeline.run()

if __name__ == '__main__':
    main()