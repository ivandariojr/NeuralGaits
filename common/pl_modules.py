from typing import Any, Dict, Iterator
from math import sqrt

import matplotlib.pyplot as plt
import numpy as np
import pytorch_lightning as pl
import torch
import torch as th
from torch import nn
from torch.autograd.functional import jvp
from torch.nn import functional as F, Parameter
from torchdiffeq import odeint_event, odeint_adjoint, odeint

class GeneralLearning(pl.LightningModule):
    def __init__(self,
                 composite_barrier,
                 yd,
                 zdyn,
                 opt_name="SGD",
                 lr=1e-3,
                 momentum=0.9,
                 weight_decay=1e-4,
                 decay_epochs=[30, 60, 90],
                 beta1=0.9,
                 beta2=0.999,
                 eps=1e-8):
        super().__init__()
        self.opt_name = opt_name
        self.lr = lr
        self.betas = (beta1, beta2)
        self.eps = eps
        self.decay_epochs = decay_epochs
        self.weight_decay = weight_decay
        self.momentum = momentum
        self.yd = yd
        self.model = yd
        self.zdyn = zdyn
        self.composite_barrier = composite_barrier
        self.cb_name_list = sum(self.composite_barrier.make_name_list(), [])

    def configure_optimizers(self):
        if self.opt_name == 'Adam':
            optimizer = th.optim.Adam(self.parameters(),
                                      lr=self.lr,
                                      weight_decay=self.weight_decay,
                                      amsgrad=False,
                                      betas=self.betas, eps=self.eps)
        elif self.opt_name == "AdamW":
            optimizer = th.optim.AdamW(self.parameters(), lr=self.lr,
                                       weight_decay=self.weight_decay,
                                       amsgrad=False,
                                       betas=self.betas, eps=self.eps)
        elif self.opt_name == 'SGD':
            optimizer = torch.optim.SGD(self.parameters(),
                                        lr=self.lr,
                                        momentum=self.momentum,
                                        weight_decay=self.weight_decay)
        elif self.opt_name == 'RMSprop':
            optimizer = torch.optim.RMSprop(self.parameters(),
                                            lr=self.lr,
                                            centered=True,
                                            momentum=self.momentum,
                                            weight_decay=self.weight_decay)
        elif self.opt_name == 'Nero':
            from libs.nero.optim.nero import Nero
            biases = list()
            weights = list()
            for name, param in self.named_parameters():
                if name .split('.')[-1] == 'bias' or (param.ndim == 2 and
                                                      param.shape):
                    biases += [param]
                else:
                    weights += [param]
            optimizer = Nero([
                dict(params=biases, constraints=False),
                dict(params=weights)],
                lr=self.lr,
                beta=self.betas[0])
        else:
            raise RuntimeError(
                f"[ERROR] Invalid Optimizer Param: {self.opt_name}")

        scheduler = th.optim.lr_scheduler.MultiStepLR(optimizer=optimizer,
                                               milestones=self.decay_epochs,
                                               gamma=0.1)
        lr_scheduler = {
            'scheduler': scheduler,
            'name': 'learning_rate',
            'monitor': 'training_loss',
            'interval': 'epoch',
            'frequency': 1
        }
        return [optimizer], [lr_scheduler]

    def _weight_decay(self):
        wd_term = 0.0
        for param in self.parameters():
            wd_term = param.norm(p=2) + wd_term
        return wd_term * self.weight_decay

    def training_step(self, batch, batch_idx):
        zs = batch[0]
        zs_dot = self.zdyn(zs)
        zs_ddot = self.zdyn.zddot(zs, zs_dot)
        zs_post = self.zdyn.reset_map(zs)
        zs_post_dot = self.zdyn(zs_post)
        zs_post_ddot = self.zdyn.zddot(zs_post, zs_post_dot)
        z_params = (zs, zs_dot, zs_ddot, zs_post, zs_post_dot, zs_post_ddot)
        batch_size = zs.shape[0]

        barrier_violations = self.composite_barrier(*z_params)

        loss = 0.0
        violation_means = []
        #doing this here to log more detailed  violations if necessary
        for b_violation in barrier_violations:
            b_violation_mean = b_violation.mean(dim=0)
            violation_means += [b_violation_mean]
            loss = b_violation_mean.sum() + loss

        violation_means = th.cat(violation_means, dim=0)
        assert len(violation_means.detach().cpu().numpy()) == len(self.cb_name_list), "[ERROR] Col Names doesnt match barrier output"
        self.log('training_loss', loss, on_step=False,
                                        on_epoch=True,
                                        logger=True)
        if self.opt_name == 'Nero':
            return loss + self._weight_decay()
        else:
            return loss

    def validation_step(self, batch, batch_idxs):
        raise NotImplementedError("[ERROR] Does not make sense for this.")

    def test_step(self, batch, batch_idx):
        raise NotImplementedError("[ERROR] Does not make sense for this.")

    def on_save_checkpoint(self, checkpoint: Dict[str, Any]) -> None:
        checkpoint['yd'] = self.yd


class DynLearning(pl.LightningModule):
    def __init__(self,
                 yd,
                 zdyn,
                 opt_name="SGD",
                 lr=1e-3,
                 momentum=0.9,
                 weight_decay=1e-4,
                 decay_epochs=[30, 60, 90],
                 beta1=0.9,
                 beta2=0.999,
                 eps=1e-8):
        super().__init__()
        self.opt_name = opt_name
        self.lr = lr
        self.betas = (beta1, beta2)
        self.eps = eps
        self.decay_epochs = decay_epochs
        self.weight_decay = weight_decay
        self.momentum = momentum
        self.yd = yd
        self.model = yd
        self.zdyn = zdyn

    def parameters(self, recurse: bool = True) -> Iterator[Parameter]:
        for k, v in self.named_parameters():
            if k.split('.')[1] == "epsilon":
                yield v
            else:
                v.requires_grad = False

    def configure_optimizers(self):
        if self.opt_name == 'Adam':
            optimizer = th.optim.Adam(self.parameters(),
                                      lr=self.lr,
                                      weight_decay=self.weight_decay,
                                      amsgrad=False,
                                      betas=self.betas, eps=self.eps)
        elif self.opt_name == "AdamW":
            optimizer = th.optim.AdamW(self.parameters(), lr=self.lr,
                                       weight_decay=self.weight_decay,
                                       amsgrad=False,
                                       betas=self.betas, eps=self.eps)
        elif self.opt_name == 'SGD':
            optimizer = torch.optim.SGD(self.parameters(),
                                        lr=self.lr,
                                        momentum=self.momentum,
                                        weight_decay=self.weight_decay)
        elif self.opt_name == 'RMSprop':
            optimizer = torch.optim.RMSprop(self.parameters(),
                                            lr=self.lr,
                                            centered=True,
                                            momentum=self.momentum,
                                            weight_decay=self.weight_decay)
        elif self.opt_name == 'Nero':
            from libs.nero.optim.nero import Nero
            biases = list()
            weights = list()
            for name, param in self.named_parameters():
                if name .split('.')[-1] == 'bias' or (param.ndim == 2 and
                                                      param.shape):
                    biases += [param]
                else:
                    weights += [param]
            optimizer = Nero([
                dict(params=biases, constraints=False),
                dict(params=weights)],
                lr=self.lr,
                beta=self.betas[0])
        else:
            raise RuntimeError(
                f"[ERROR] Invalid Optimizer Param: {self.opt_name}")

        scheduler = th.optim.lr_scheduler.ReduceLROnPlateau(
            optimizer=optimizer,
            factor=0.9,
            patience=5,
            min_lr=1e-8)
        lr_scheduler = {
            'scheduler': scheduler,
            'name': 'learning_rate',
            'monitor': 'training_loss',
            'interval': 'step',
            'frequency': 1
        }
        return [optimizer], [lr_scheduler]
    def _weight_decay(self):
        wd_term = 0.0
        for param in self.parameters():
            wd_term = param.norm(p=2) + wd_term
        return wd_term * self.weight_decay

    def _compute_loss(self, batch):
        return self._integration_error(batch)

    def _integration_error(self, batch):
        # (0,1,2,3,4) t, tau, switchBack, tau_d, tau_a,
        # (5) stance,
        # (6,7,8,9,10) a_state_1, a_state_2, a_state_3, a_state_4, a_state_5,
        # (11,12,13,14,15) a_state_6, a_state_7, a_state_8, a_state_9, a_state_10
        # (16, 17, 18, 19, 20) d_state_1, d_state_2, d_state_3, d_state_4,  d_state_5,
        # (21, 22, 23) d_state_6, d_state_7, d_state_8
        # (24, 25, 26, 27) d_torque_1, d_torque_2, d_torque_3, d_torque_4
        t = batch[:, :, 0]
        xt = batch[:, :, 6:16]
        ut = batch[:, :, 24:]
        stancet = batch[:, :, 5]
        impactt = th.round(stancet[:, 1:]).bool() ^ th.round(stancet[:, :-1]).bool()
        zt = self.zdyn.phi(xt.flatten(0, 1)).unflatten(0, xt.shape[:2])
        if impactt.any().item():
            raise NotImplementedError("[ERROR] There shouldn't be any times "
                                      "left.")
            # integrate until impact time, apply reset_map, restart integration
            # impact_mask = impactt.any(dim=-1)
            # impact_times = t[impact_mask]
        else:
            t_normalized = t - t[:, 0, None]
            t_unique, inverse = t_normalized.unique(return_inverse=True)
            delta_t = t[:, 1:] - t[:, :-1]
            step_size = delta_t.min().item()/100
            # zt_hat_lined = odeint_adjoint(self.zdyn._dynamics, zt[:, 0, :],
            #                           t_unique,
            #                         adjoint_atol=1e-3, adjoint_rtol=1e-3,
            #                         adjoint_params=self.parameters(),
            #                         atol=1e-3, rtol=1e-3).permute(1, 0, 2)
            zt_hat_lined = odeint(self.zdyn._dynamics, zt[:, 0, :],
                                          t_unique, method='rk4',
                                          options=dict(step_size=step_size)).permute(1,0, 2)
            zt_hat = th.gather(zt_hat_lined, 1, inverse[:, :, None].expand(-1, -1, zt_hat_lined.shape[2]))
        return th.norm(zt_hat - zt, dim=-1).mean()

    def training_step(self, batch, batch_idx):
        loss = self._compute_loss(batch)
        self.log('training_loss', loss, on_step=True, on_epoch=True, logger=True)
        if self.opt_name == 'Nero':
            return loss + self._weight_decay()
        else:
            return loss


    def validation_step(self, batch, batch_idxs):
        loss = self._integration_error(batch)
        self.log('validation_loss', loss, on_epoch=True, on_step=False, logger=True)

    def test_step(self, batch, batch_idx):
        loss = self._integration_error(batch)
        self.log('test_loss', loss, on_epoch=True, on_step=False, logger=True)
        raise NotImplementedError("[ERROR] Does not make sense in this case.")

    def on_save_checkpoint(self, checkpoint: Dict[str, Any]) -> None:
        # super().on_save_checkpoint(checkpoint)
        checkpoint['yd'] = self.yd
        #includes yd
        checkpoint['zdyn'] = self.zdyn

class NumDynLearning(DynLearning):
    def __init__(self, yd, zdyn, opt_name="SGD", lr=1e-3, momentum=0.9,
                 weight_decay=1e-4, decay_epochs=[30, 60, 90], beta1=0.9,
                 beta2=0.999, eps=1e-8):
        super().__init__(yd, zdyn, opt_name, lr, momentum, weight_decay,
                         decay_epochs, beta1, beta2, eps)

    def _compute_loss(self, batch):
        # (0,1,2,3,4) t, tau, switchBack, tau_d, tau_a,
        # (5) stance,
        # (6,7,8,9,10) a_state_1, a_state_2, a_state_3, a_state_4, a_state_5,
        # (11,12,13,14,15) a_state_6, a_state_7, a_state_8, a_state_9, a_state_10
        # (16, 17, 18, 19, 20) d_state_1, d_state_2, d_state_3, d_state_4,  d_state_5,
        # (21, 22, 23) d_state_6, d_state_7, d_state_8
        # (24, 25, 26, 27) d_torque_1, d_torque_2, d_torque_3, d_torque_4
        t = batch[:, :, 0]
        xt = batch[:, :, 6:16]
        ut = batch[:, :, 24:]
        stancet = batch[:, :, 5]
        impactt = th.round(stancet[:, 1:]).bool() ^ th.round(stancet[:, :-1]).bool()
        zt = self.zdyn.phi(xt.flatten(0, 1)).unflatten(0, xt.shape[:2])
        if impactt.any().item():
            raise NotImplementedError("[ERROR] There shouldn't be any times "
                                      "left.")
            # integrate until impact time, apply reset_map, restart integration
            # impact_mask = impactt.any(dim=-1)
            # impact_times = t[impact_mask]
        else:
            delta_t = (t[:, 1:] - t[:, :-1]).flatten(0, 1)
            dzt = (zt[:, 1:] - zt[:, :-1]).flatten(0,1)
            dztdt = (dzt / delta_t.unsqueeze(-1))
            zdot_hat = self.zdyn(dzt / 2)
        return th.norm(dztdt -  zdot_hat, dim=-1).mean()