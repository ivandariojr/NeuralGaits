import numpy as np
import scipy.io
import torch as th
from matplotlib import pyplot as plt
from torch import nn as nn
from torchdiffeq import odeint_event, odeint_adjoint, odeint

import D_matrix
from Phi import Phi
from p_z_swing import p_z_swing
from v_z_swing import v_z_swing
from utils import to_tuple
from zero_dynamics import dz_2, Psi_Z_intermediate_1
from amber_dynamics import AmberDynamics

class ZeroDynamics(nn.Module):
    def __init__(self, yd):
        super().__init__()
        self.yd = yd
        self.register_buffer("c", th.tensor([-0.873, -0.4604, 0,0,0]))
        H = th.zeros((4,5))
        H[0, 1] = 1
        H[1, 2] = 1
        H[2, 3] = 1
        H[3, 4] = 1
        self.register_buffer("H", H)
        self.guard_tol = 1e-4

    def forward(self, z):
        return self.zdot(z)

    def _dynamics(self, t, z):
        return self(z)

    def Psi(self, z):
        z1, z2 = to_tuple(z, dim=1)
        with th.enable_grad():
            # if not z.requires_grad:
            #     z.requires_grad = True
            z_in = th.stack(th.autograd.functional._grad_preprocess(z, create_graph=True, need_graph=True), dim=0)
            ydz = self.yd(z_in)
            jacobian_yd = []
            for ydz_idx in range(ydz.shape[1]):
                jacobian_yd +=[th.autograd.grad(outputs=ydz[:, ydz_idx].sum(), inputs=z_in,
                                                create_graph=True, retain_graph=True, allow_unused=True)[0]]
        jacobian_yd = th.stack(jacobian_yd, dim=1)
        yd_params = to_tuple(ydz, dim=1)
        # jacobian_yd_slow = th.autograd.functional.jacobian(self.yd, z, create_graph=True,
        #                                               vectorize=True).diagonal(dim1=0, dim2=2).permute((2, 0 , 1))
        # assert (jacobian_yd - jacobian_yd_slow).abs().sum().item() < 1e-6
        outer_product = th.einsum("ij,k ->ijk", jacobian_yd[:,:, 0], self.c)
        kappa2 = -dz_2(z1, z2, *yd_params)
        inversion = th.inverse(
            th.cat([(Psi_Z_intermediate_1(z1, *yd_params)[:, 0]), (self.H[None] - outer_product)], dim=1))
        rhs = th.cat([z2, jacobian_yd[:, :, 1] * kappa2], dim=-1)
        psi = inversion @ rhs[:, :, None]
        return psi

    def reset_map(self, z):
        ydz, ydz_dot = self.yd.time_derivative(z, self.zdot(z))
        x = self.phi_inv(z)
        x_reseted = AmberDynamics.reset_map(x)
        reseted_z = Phi(*to_tuple(x_reseted, dim=1), *to_tuple(ydz, dim=1), *to_tuple(ydz_dot, dim=1))[:, :, 0, 0]
        return reseted_z[:, -2:]

    def _int_reset_map(self, z):
        reseted_z =  self.reset_map(z)
        collided = self.event_function(0.0, z) < self.guard_tol
        returns = z * ~collided + reseted_z * collided
        return returns

    def pos_event_function(self, t, z):
        state = self.phi_inv(z)
        z_swing = p_z_swing(*to_tuple(state, dim=1))
        vel_swing = v_z_swing(*to_tuple(state, dim=1))
        # z_com = p_z_com(*to_tuple(state, dim=1))
        # min_z_com = z_com - 0.5

        # torso_angles = torso_angle(*to_tuple(state, dim=1))
        # min_ta = torso_angles + (math.pi /3)
        # max_ta = (math.pi /3) - torso_angles
        # stance_hip = state[:, 2]
        # nonstance_hip = state[:, 3]
        # min_sh = stance_hip + (math.pi /4)
        # max_sh = (math.pi / 4) - stance_hip
        # min_nsh = nonstance_hip + (math.pi / 4)
        # max_nsh = (math.pi / 4) - nonstance_hip

        # constraints = th.cat([z_swing, max_ta, min_ta, min_sh[:,None], max_sh[:,None], min_nsh[:,None], max_nsh[:,None]], dim=-1)
        # constraints = th.cat([z_swing, min_z_com], dim=-1)
        # tmp2 = v_z_swing(*to_tuple(state, dim=1))
        # cond1 = abs(tmp1) < 1e-3
        # cond2 = th.relu(tmp2) < 0
        # cond3 = abs(np.pi /2) > state[:, 0].abs()
        # full_cond = cond1 * cond2 + cond3[:, None]
        # return full_cond

        constraints = z_swing
        return th.min(constraints, dim=-1).values[:, None]

        # constraints = th.cat([z_swing, vel_swing], dim=-1)
        # return th.max(constraints, dim=-1).values[:, None]

    def event_function(self, t, z):
        state = self.phi_inv(z)
        z_swing = p_z_swing(*to_tuple(state, dim=1))
        vel_swing = v_z_swing(*to_tuple(state, dim=1))
        # z_com = p_z_com(*to_tuple(state, dim=1))
        # min_z_com = z_com - 0.5

        # torso_angles = torso_angle(*to_tuple(state, dim=1))
        # min_ta = torso_angles + (math.pi /3)
        # max_ta = (math.pi /3) - torso_angles
        # stance_hip = state[:, 2]
        # nonstance_hip = state[:, 3]
        # min_sh = stance_hip + (math.pi /4)
        # max_sh = (math.pi / 4) - stance_hip
        # min_nsh = nonstance_hip + (math.pi / 4)
        # max_nsh = (math.pi / 4) - nonstance_hip

        # constraints = th.cat([z_swing, max_ta, min_ta, min_sh[:,None], max_sh[:,None], min_nsh[:,None], max_nsh[:,None]], dim=-1)
        # constraints = th.cat([z_swing, min_z_com], dim=-1)
        # tmp2 = v_z_swing(*to_tuple(state, dim=1))
        # cond1 = abs(tmp1) < 1e-3
        # cond2 = th.relu(tmp2) < 0
        # cond3 = abs(np.pi /2) > state[:, 0].abs()
        # full_cond = cond1 * cond2 + cond3[:, None]
        # return full_cond

        # constraints = z_swing
        # return th.min(constraints, dim=-1).values[:, None]

        constraints = th.cat([z_swing, vel_swing], dim=-1)
        return th.max(constraints, dim=-1).values[:, None]

    def phi_inv(self, z):
        z1, z2 = to_tuple(z, dim=1)
        y_des = self.yd(z)
        psi = self.Psi(z)
        # q = th.linalg.lstsq(th.cat([self.c[None],self.H])[None].expand(z1.shape[0],-1,-1),th.cat([z1, y_des],dim=-1))
        q = th.inverse(th.cat([self.c[None], self.H]))[None].expand(z1.shape[0], -1, -1) @ th.cat([z1, y_des], dim=-1).unsqueeze(-1)
        dq = psi
        state = th.cat([q, dq], dim = 1)
        return state[:,:,0]

    def phi(self, x):
        q, qdot = x[:, :5], x[:, 5:]
        z1 = (self.c[None] * q).sum(dim=-1)
        D = D_matrix.D_matrix(*to_tuple(q, dim=-1))
        ND = D[:, 0, 0 , None,  :]
        z2 = (ND @ qdot[:, :, None])[:, 0]
        return th.cat([z1[:, None], z2], dim=-1)

    def get_event_time(self, z0, max_t, tol=1e-3):
        # z0 = tensor([[ -0.1888,  48.8366,   0.0000],
        # [  0.2672, -15.2190,   0.0000]])
        state = [z0]
        t0 = th.tensor([0.0], device=z0.device, dtype=z0.dtype)
        collided = th.zeros((z0.shape[0],), dtype=th.bool, device=z0.device)
        event_time = t0.clone()
        collision_states = th.zeros_like(z0)
        event_times = th.zeros((z0.shape[0],))
        while (event_time < max_t).item() and (~collided).any().item():
            event_time, soln = odeint_event(self._dynamics, state[-1][~collided, :], t0,
                                            event_fn=self.event_function,
                                            atol=tol, rtol=tol,
                                            adjoint_atol=tol, adjoint_rtol=tol,
                                            # method='rk4',
                                            # options=dict(
                                            #     step_size=1e-3,
                                            #     perturb=True
                                            # ),
                                            adjoint_params=tuple(self.parameters()),
                                            # adjoint_options=dict(atol=1e-3, rtol=1e-3),
                                            odeint_interface=odeint_adjoint
                                            )
            collided_now = (self.event_function(0.0, soln[-1]) <= self.guard_tol)[:, 0]
            old_collided = collided.clone()
            collided[~collided] = collided_now
            need_update = collided & ~old_collided
            collision_states[need_update , :] = collision_states[need_update,:] + soln[-1][collided_now, :]
            event_times[need_update] = event_times[need_update] + event_time[None].expand(collided_now.sum().item())
            new_state_idx = np.array([i for i in range(z0.shape[0])])
            new_state = [None for _ in range(z0.shape[0])]
            if collided.sum().item() != 0:
                # new_state[old_collided.detach().numpy()] = to_tuple(state[-1][old_collided,:], dim=0)
                for idx in new_state_idx[old_collided.detach().numpy()]:
                    new_state[idx] = state[-1][idx, None,:]
            for i, idx in enumerate(new_state_idx[~old_collided.detach().numpy()]):
                new_state[idx] = soln[-1][i, None]
            # new_state[~old_collided.detach().numpy()] = np.array(to_tuple(soln[-1], dim=0))
            state += [
                 th.cat(new_state, dim=0)
            ]
            t0 = event_time
        return  collision_states, event_times

    def masked_dynamics(self, t, z):
        events = self.event_function(t, z)[:, 0]
        collisions = events < self.guard_tol
        zdot = self._dynamics(t, z)
        return zdot * ~collisions[:, None]

    def integrate_to_preimact(self, z0, tol=1e-3):
        # time = th.linspace(0.0, 5.0, 2)
        # t0 = th.tensor([0.0], device=z0.device, dtype=z0.dtype)
        return self.get_event_time(z0, max_t=5.0, tol=tol)
        # with torch.no_grad():
        #     event_times, mask = self.get_event_time(z0, max_t=5.0)
        # ts = th.cat([th.tensor([0], dtype=event_times.dtype, device=event_times.device), event_times])
        # solution = odeint(self._dynamics, z0, ts,
        #                   atol=1e-3, rtol=1e-3)
        # pre_impact_states = (solution[1:] * mask[:, :, None]).sum(dim=0)
        # batch_event_times = event_times[None, :].expand(z0.shape[0], z0.shape[0]) * mask
        # return pre_impact_states, batch_event_times
        ##################################################################################################
        #############################YEEEHAH #############################################################
        ##################################################################################################
        # plt.scatter(pre_impact_states[:,0].detach().numpy(),pre_impact_states[:,1].detach().numpy())
        # plt.show()

        # collided = zdyn.event_function(0.0, solution[-1, :, :]) < 1e-3
        # t = th.linspace(0,event_times[0].item(),100)
        # solution = odeint(self._dynamics, z0, t,
        #                   atol=1e-3, rtol=1e-3)
        # collided = zdyn.event_function(0.0, solution[-1, :, :]) < 1e-3
        # z0_1 =solution[-1,~collided.squeeze(),:]
        # t = th.linspace(event_times[0].item(),event_times[1].item(), 100)
        # solution = odeint(self._dynamics, z0_1, t,
        #                   atol=1e-3, rtol=1e-3)
        # plt.plot(ts.detach().numpy(),solution[:, :, 0].detach().numpy())
        # plt.show()
        # plt.plot(ts.detach().numpy(), solution[:, :, 1].detach().numpy())
        # plt.show()

        # plotZtrajectories(time,solution)
        # qts = self.phi_inv(solution.flatten(0,1)).unflatten(0, solution.shape[:2])
        # plotQtrajectories(time, qts)
        # yd_t = self.yd(solution.flatten(0,1)[:, 0, None]).unflatten(0, solution.shape[:2])
        # plotYd(time, yd_t)
        # event_t, solution = odeint_event(func=self._dynamics,
        #                                  y0=z0,
        #                                  t0=th.tensor(0.0, device=z0.device),
        #                                  event_fn=self.event_function,
        #                                  odeint_interface=odeint)
        # return None

    def save_states(self, z0,ind, event_times):
        # This code uses too much memory to ever be run on cuda.
        # This might change if we use the cluster
        prev_device = z0.device
        z0 = z0.cpu()
        self.cpu()
        with th.no_grad():
            # _, event_times = self.get_event_time(z0, max_t=5.0)
            ts = th.linspace(0.0, th.max(event_times).item(),100)
            solution = odeint(self._dynamics, z0, ts,
                              atol=1e-3, rtol=1e-3)
            z_solution = solution[:,:,:2]
            # pre_impacts = self.integrate_to_preimact(z0)

            # z = solution.flatten(0,1)
            # self.plotZquiver(z)
            Z1, Z2 = th.meshgrid(
                th.linspace(-1, 1, steps=50),
                th.linspace(-100, 100, steps=50), indexing='ij')
            ZS = th.stack([Z1, Z2], dim=-1).to(z0.device)
            policy = self.yd(ZS.flatten(0,1)).unflatten(0, ZS.shape[:2])

            state = self.phi_inv(solution.flatten(0,1)).unflatten(0, solution.shape[:2])
            data = dict(time=ts.cpu().detach().numpy(),
                        state=state.cpu().detach().numpy(),
                        z_interp=ZS.cpu().detach().numpy(),
                        policy=policy.cpu().detach().numpy())

            scipy.io.savemat('tmp_' + ind + '.mat', data)
        self.to(prev_device)

    def zdot(self, z):
        z1, z2 = to_tuple(z, dim=1)
        ydz = self.yd(z)
        yd_params = to_tuple(ydz, dim=1)
        # jacobian_yd = th.autograd.functional.jacobian(self.yd, z, create_graph=True, vectorize=True).diagonal(dim1=0, dim2=2)
        # outer_product = th.einsum("ij,k ->ijk", jacobian_yd[:, 0], self.c)
        # psi = th.inverse(th.cat([
        #     (Psi_Z_intermediate_1(z1, *yd_params)[:, 0]),
        #     (self.H[None] - outer_product)
        # ], dim=1)) @ th.cat([th.ones((1,1)), th.zeros(4,1)], dim=0)
        psi = self.Psi(z)
        kappa1 = (psi.transpose(2,1) @ self.c[:, None])[:, 0, 0]
        z1_dot = kappa1[:, None]
        z2_dot = -dz_2(z1, z2, *yd_params)
        z_dot = th.cat([z1_dot, z2_dot], dim=-1)
        return z_dot

    def zddot(self, z, zdot):
        _, ddz = th.autograd.functional.jvp(self.zdot, z, zdot, create_graph=True)
        return ddz

    def plotZquiver(self,z):
        zdot = self.forward(z)
        fig, ax = plt.subplots(dpi=300)
        q = ax.quiver(z.detach().numpy()[:, 0], z.detach().numpy()[:, 1], zdot.detach().numpy()[:, 0],
                      zdot.detach().numpy()[:, 1])
        ax.quiverkey(q, X=0.3, Y=1.1, U=50,
                     label='Zero Dynamics For Offline Gait', labelpos='E')
        plt.show()

    def input(self, z):
        state = self.phi_inv(z)
        zdot = self.zdot(z)
        _, ddyd = self.yd.time2_derivative(z, zdot, self.zddot(z, zdot))
        return AmberDynamics.input(self.H, state, ddyd)

    instance = None
    @staticmethod
    def get_instance(**params):
        # This is dangerous.
        # this is only meant for the config generation
        if ZeroDynamics.instance is None:
            ZeroDynamics.instance = ZeroDynamics(**params)
        return ZeroDynamics.instance



class LearnableZeroDynamics(ZeroDynamics):
    def __init__(self, yd, epsilon):
        super().__init__(yd)
        self.epsilon = epsilon

    def zdot(self, z):
        nominal_zdot = super().zdot(z)
        residual = self.epsilon(z)
        return nominal_zdot + residual

    instance = None
    @staticmethod
    def get_instance(**params):
        # This is dangerous.
        # this is only meant for the config generation
        if LearnableZeroDynamics.instance is None:
            LearnableZeroDynamics.instance = LearnableZeroDynamics(**params)
        return LearnableZeroDynamics.instance


class RefinementZeroDynamics(LearnableZeroDynamics):
    def __init__(self, yd, epsilon):
        super().__init__(yd, epsilon)

    def parameters(self, recurse: bool = True):
        return self.yd.parameters()

    instance = None
    @staticmethod
    def get_instance(**params):
        # This is dangerous.
        # this is only meant for the config generation
        if LearnableZeroDynamics.instance is None:
            LearnableZeroDynamics.instance = LearnableZeroDynamics(**params)
        return LearnableZeroDynamics.instance


class ROZeroDynamics(ZeroDynamics):

    def __init__(self, yd):
        super().__init__(yd)


    def Psi(self, z):
        z1, z2 = to_tuple(z, dim=1)
        with th.enable_grad():
            # if not z.requires_grad:
            #     z.requires_grad = True
            z_in = th.stack(th.autograd.functional._grad_preprocess(z, create_graph=True, need_graph=True), dim=0)
            ydz = self.yd(z_in)
            jacobian_yd = []
            for ydz_idx in range(ydz.shape[1]):
                jacobian_yd += [th.autograd.grad(outputs=ydz[:, ydz_idx].sum(), inputs=z_in,
                                                 create_graph=True, retain_graph=True, allow_unused=True)[0]]
        jacobian_yd = th.stack(jacobian_yd, dim=1)
        yd_params = to_tuple(ydz, dim=1)
        # jacobian_yd_slow = th.autograd.functional.jacobian(self.yd, z, create_graph=True,
        #                                               vectorize=True).diagonal(dim1=0, dim2=2).permute((2, 0 , 1))
        # assert (jacobian_yd - jacobian_yd_slow).abs().sum().item() < 1e-6
        outer_product = th.einsum("ij,k ->ijk", jacobian_yd[:, :, 0], self.c)
        kappa2 = -dz_2(z1, z2, *yd_params)
        inversion = th.inverse(
            th.cat([self.c[None, None].expand(z.shape[0], -1, -1),
                    (self.H[None] - outer_product)], dim=1))
        rhs = th.cat([z2, jacobian_yd[:, :, 1] * kappa2], dim=-1)
        psi = inversion @ rhs[:, :, None]
        return psi

    def zdot(self, z):
        # z1, z2 = to_tuple(z, dim=1)
        # ydz = self.yd(z)
        # yd_params = to_tuple(ydz, dim=1)
        # jacobian_yd = th.autograd.functional.jacobian(self.yd, z, create_graph=True, vectorize=True).diagonal(dim1=0, dim2=2)
        # outer_product = th.einsum("ij,k ->ijk", jacobian_yd[:, 0], self.c)
        # psi = th.inverse(th.cat([
        #     (Psi_Z_intermediate_1(z1, *yd_params)[:, 0]),
        #     (self.H[None] - outer_product)
        # ], dim=1)) @ th.cat([th.ones((1,1)), th.zeros(4,1)], dim=0)
        psi = self.Psi(z)
        kappa1 = (psi.transpose(2, 1) @ self.c[:, None])[:, 0, 0]
        z1_dot = kappa1[:, None]
        z2_dot = AmberDynamics.xddot(self.phi_inv(z), self.input(z))
        z_dot = th.cat([z1_dot, z2_dot], dim=-1)
        return z_dot


    instance = None
    @staticmethod
    def get_instance(**params):
        # This is dangerous.
        # this is only meant for the config generation
        if ROZeroDynamics.instance is None:
            ROZeroDynamics.instance = ROZeroDynamics(**params)
        return ROZeroDynamics.instance

class COTDynamics(ZeroDynamics):

    def __init__(self, yd):
        super(COTDynamics, self).__init__(yd)

    def forward(self, aug_z):
        z = aug_z[:, :2]
        zdot = self.zdot(z)
        u = self.input(aug_z)
        state = self.phi_inv(z)
        power = th.abs(state[:, None, 6:10] @ u)
        z_dot = th.cat([zdot, power[:, :, 0]], dim=-1)
        return z_dot

    def input(self, aug_z):
        return super(COTDynamics, self).input(aug_z[:, :2])
    def zdot(self, z):
        return super(COTDynamics, self).zdot(z[:, :2])
    def phi_inv(self, z):
        return super(COTDynamics, self).phi_inv(z[:,:2])
    def reset_map(self, z):
        reseted_z = super(COTDynamics, self).reset_map(z[:, :2])
        return th.cat([reseted_z, z[:,-1][:, None]], dim=-1)

    instance = None
    @staticmethod
    def get_instance(**params):
        # This is dangerous.
        # this is only meant for the config generation
        if COTDynamics.instance is None:
            COTDynamics.instance = COTDynamics(**params)
        return COTDynamics.instance