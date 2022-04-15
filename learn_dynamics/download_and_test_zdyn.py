import os

from dynamics import ZeroDynamics
from deprecated import AmberDynamics
import torch as th
import torch
from torchdiffeq import odeint
import scipy
from pathlib import Path
import wandb
import os
import argparse
from pl_modules import GeneralLearning
from load_amber_data import AmberRealDataSet
from dynamics import ZeroDynamics
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np

def main(model_name:str):
    device_name = "cpu:0"
    n_batch = 10
    num_steps = 10
    ts_res = 100
    tol = 1e-5
    system = AmberDynamics()
    trial_name = "14"
    ind = 136
    save_dir = Path(f"run_data/wandb_saves")
    os.makedirs(save_dir, exist_ok=True)
    api = wandb.Api()
    artifact = api.artifact(f"ivan/SampledWalkingDyn/{model_name}")
    artifact.file(root=str(save_dir))
    api.runs()
    model_ckpt = th.load(str(save_dir / Path(f'model.ckpt')))
    zdyn = model_ckpt['zdyn'].to('cpu')

    yd = zdyn.yd
    nominal_zd = ZeroDynamics(yd=yd)
    th.save(zdyn, str(save_dir / f'zdyn.th'))
    dset = AmberRealDataSet(dataset_names=["LearnTrajopt_mh25_v519_trial4"],
                     delta_t=4,
                     n_steps=3)
    grid_size = 10
    with torch.no_grad():
        Z1, Z2 = th.meshgrid(
            th.linspace(-.4, .4, grid_size),
            th.linspace(-30, -5, grid_size)
        )
        Zs = th.stack([Z1, Z2], dim=-1)
        zdots = nominal_zd.zdot(Zs.flatten(0,1)).unflatten(0, (grid_size, )*2)
        zdots_hat = zdyn.zdot(Zs.flatten(0,1)).unflatten(0, (grid_size, )*2)
        diff = zdots_hat - zdots
        norm_img = th.norm(diff, dim=-1).detach().numpy()
        error_img = th.abs(diff).detach().numpy()
        #
        # batch = dset[:10]
        # t = batch[:, :, 0]
        # xt = batch[:, :, 6:16]
        # ut = batch[:, :, 24:]
        # zt = zdyn.phi(xt.flatten(0, 1)).unflatten(0, xt.shape[:2])
        # t_normalized = t - t[:, 0, None]
        # t_unique, inverse = t_normalized.unique(return_inverse=True)
        # delta_t = t[:, 1:] - t[:, :-1]
        # step_size = delta_t.min().item() / 100
        # zt_hat_lined = odeint(
        #     zdyn._dynamics, zt[:, 0, :],
        #     t_unique).permute(1,0,2)
        # zt_hat = th.gather(zt_hat_lined, 1, inverse[:, :, None].expand(-1, -1, zt_hat_lined.shape[2]))
        # zt_hat = zt_hat.detach().numpy()
        # zt = zt.detach().numpy()
        # error_t = abs(zt - zt_hat)
    fig, ax = plt.subplots(1, 3)
    sns.heatmap(norm_img, ax=ax[0])
    sns.heatmap(error_img[:, :, 0], ax=ax[1])
    sns.heatmap(error_img[:, :, 1], ax=ax[2])
    plt.show()
    # Z1, Z2 = np.meshgrid()
    # b_idx = 0
    # # for b_idx in range(10):
    # fig, ax = plt.subplots(1, 3)
    # ax[0].plot(zt_hat[b_idx], color='b')
    # ax[0].plot(zt[b_idx],color='g')
    # ax[1].plot(t_normalized[b_idx], error_t[b_idx, :, 0])
    # ax[2].plot(t_normalized[b_idx], error_t[b_idx, :, 1])
    # plt.show()

    # print("I Get Here")




if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--model_name', required=True)
    args = parser.parse_args()
    main(args.model_name)