import torch as th
import torch.nn as nn
from torso_angle import torso_angle
from p_z_swing import p_z_swing
from p_z_com import p_z_com
from v_x_com import v_x_com
from v_z_com import v_z_com
from p_x_swing import p_x_swing
from p_x_com import p_x_com
from D_matrix import D_matrix
from H_vector import H_vector
from B_matrix import B_matrix
from J_contact import J_contact
# from dJ_contact import dJ_contact
from utils import to_tuple
import numpy as np
from math import sqrt
import omegaconf
import hydra

class MaskBarrierPair(nn.Module):
    def __init__(self, mask, barriers_list) -> None:
        super().__init__()
        self.mask = mask
        self.barriers_list = nn.ModuleList(barriers_list)

    def forward(self, *params):
        masked_params = [p[self.mask(params[0]), :] for p in params]
        violations = []
        for barrier in self.barriers_list:
            violations += [barrier.violation(*masked_params)]
        violations = th.cat(violations, dim=-1)
        return violations

    def make_name_list(self):
        mask_name = type(self.mask).__name__
        all_names = []
        for b in self.barriers_list:
            for b_name in b.col_names():
                all_names += [f'{mask_name}:{b_name}']
        return all_names

class CompositeBarrier(nn.Module):
    def __init__(self, mask_barriers_pairs):
        super().__init__()
        self.pairs = nn.ModuleList(mask_barriers_pairs)

    def forward(self, zs, zdots, zddots, zs_pi, zdots_pi, zddots_pi):
        #TODO: are we dealing with post impact correctly here (?)
        all_barriers = list()
        params = [zs, zdots, zddots, zs_pi, zdots_pi, zddots_pi]
        for pair in self.pairs:
            all_barriers += [pair(*params)]
        return all_barriers

    def make_name_list(self):
        return [p.make_name_list() for p in self.pairs]


class AbstractBarrier(nn.Module):
    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub,
                 apply_to_post_impact=False):
        super().__init__()
        if lb is not None:
            self.register_buffer('lb', th.tensor(lb))
            self.register_buffer('alpha_lb', th.tensor(alpha_lb))
        else:
            self.lb = None
        if ub is not None:
            self.register_buffer('ub', th.tensor(ub))
            self.register_buffer('alpha_ub', th.tensor(alpha_ub))
        else:
            self.ub = None
        self.zdyn = zdyn
        self.apply_to_post_impact = apply_to_post_impact

    def forward(self, zs, zdots):
        raise NotImplementedError()

    def violation(self, zs, zdots, zddots,
                        zs_pi, zdots_pi, zddots_pi):
        if self.apply_to_post_impact:
            return th.cat([self._violation(zs, zdots, zddots),
                           self._violation(zs_pi, zdots_pi, zddots_pi)], dim=-1)
        else:
            return self._violation(zs, zdots, zddots)

    def _violation(self, zs, zdots, zddots):
        h, hdot = th.autograd.functional.jvp(
            func=self,
            inputs=(zs, zdots),
            v=(zdots, zddots), create_graph=True)

        if self.lb is not None:
            lb_violation = th.relu(-hdot - self.alpha_lb * (h - self.lb))
        else:
            lb_violation = 0.0
        if self.ub is not None:
            ub_violation = th.relu(hdot - self.alpha_ub * (self.ub - h))
        else:
            ub_violation = 0.0
        return lb_violation + ub_violation

    def col_names(self):
        this_names = []
        if self.apply_to_post_impact:
            this_names += [f'{type(self).__name__}-']
            this_names += [f'{type(self).__name__}+']
        else:
            this_names += [f'{type(self).__name__}']
        return this_names

class TorsoAngle(AbstractBarrier):
    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)

    def forward(self, zs, zdots):
        return torso_angle(*to_tuple(self.zdyn.phi_inv(zs), dim=-1))

class FootOnGuard(AbstractBarrier):
    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)

    def forward(self, zs, zdots):
        return p_z_swing(*to_tuple(self.zdyn.phi_inv(zs), dim=-1))

class PelvisX(AbstractBarrier):
    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)

    def forward(self, zs, zdots):
        return p_x_com(*to_tuple(self.zdyn.phi_inv(zs), dim=-1))

class FootOnGuardLoss(AbstractBarrier):
    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub, loss_gain,
                 apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
        self.register_buffer("loss_gain", th.tensor(loss_gain))

    def forward(self, zs, zdots):
        return p_z_swing(*to_tuple(self.zdyn.phi_inv(zs), dim=-1))

    def violation(self, zs, zdots, zddots, zs_pi, zdots_pi, zddots_pi):
        return th.abs(self(zs, zdots)) * self.loss_gain

class Z0Dot(AbstractBarrier):
    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)

    def forward(self, zs, zdots):
        return zdots[:, 0, None]

class PelvisHeight(AbstractBarrier):
    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)

    def forward(self, zs, zdots):
        return p_z_com(*to_tuple(self.zdyn.phi_inv(zs), dim=-1))

class HorizontalVelocity(AbstractBarrier):
    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)

    def forward(self, zs, zdots):
        return v_x_com(*to_tuple(self.zdyn.phi_inv(zs), dim=-1))

class StepWidth(AbstractBarrier):
    def __init__(self, zdyn, alpha, lb, ub, alpha_lb, alpha_ub,
                 apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
        self.register_buffer("alpha", th.tensor(alpha))

    def forward(self, zs, zdots):
        #old version
        # def h_step_width(*z_samples_in):
        #     alpha = 2
        #     tmp = p_x_swing(*to_tuple(zdyn.phi_inv(*z_samples_in), dim=-1))
        #     return (tmp - alpha * z_samples_in[0][:, 0, None])[:, :, None]
        return p_x_swing(*to_tuple(self.zdyn.phi_inv(zs), dim=-1)) - \
               self.alpha * zs[:, 0, None]

class HDeltaJacobian(AbstractBarrier):

    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub,
                 apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)

    def forward(self, zs, zdots):
        return th.autograd.grad(self.zdyn.reset_map(zs)[:, 0].sum(),
                                zs,
                                create_graph=True,
                                retain_graph=True)[0][:, 0, None]

class HDeltaExplicit(AbstractBarrier):

    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub, alpha,
                 apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
        self.register_buffer("alpha", th.tensor(alpha))

    def forward(self, zs, zdots):
        return (self.zdyn.reset_map(zs)[:, 0] + self.alpha*zs[:, 0])[:, None]

class HDeltaExplicitBent(AbstractBarrier):

    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub, alpha,
                 apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
        self.register_buffer("alpha", th.tensor(alpha))

    def forward(self, zs, zdots):
        return (self.zdyn.reset_map(zs)[:, 0] + self.alpha*zs[:, 0])[:, None]

    def violation(self, zs, zdots, zddots,
                        zs_pi, zdots_pi, zddots_pi):
        if self.apply_to_post_impact:
            return th.cat([self._violation(zs, zdots, zddots),
                           self._violation(zs_pi, zdots_pi, zddots_pi)], dim=-1)
        else:
            return self._violation(zs, zdots, zddots)

    def alpha_lb_func(self, r):
        if r > 0:
            return self.alpha_lb * r
        else:
            return 1./self.alpha_lb * r

    def alpha_ub_func(self, r):
        if r > 0:
            return self.alpha_ub * r
        else:
            return 1./self.alpha_ub * r

    def _violation(self, zs, zdots, zddots):
        h, hdot = th.autograd.functional.jvp(
            func=self,
            inputs=(zs, zdots),
            v=(zdots, zddots), create_graph=True)

        if self.lb is not None:
            lb_violation = th.relu(-hdot - self.alpha_lb_func(h - self.lb))
        else:
            lb_violation = 0.0
        if self.ub is not None:
            ub_violation = th.relu(hdot - self.alpha_ub_func(self.ub - h))
        else:
            ub_violation = 0.0
        return lb_violation + ub_violation

class HDeltaExplicitLoss(AbstractBarrier):

    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub, alpha, loss_gain,
                 apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
        self.register_buffer("alpha", th.tensor(alpha))
        self.register_buffer("loss_gain", th.tensor(loss_gain))

    def forward(self, zs, zdots):
        return (self.zdyn.reset_map(zs)[:, 0] + self.alpha*zs[:, 0])[:, None]

    def violation(self, zs, zdots, zddots, zs_pi, zdots_pi, zddots_pi):
        return th.abs(self(zs, zdots))*self.loss_gain


class InputBounds(AbstractBarrier):

    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub,
                 apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)

    def forward(self, zs, zdots):
        return self.zdyn.input(zs)[:, :, 0]

    def col_names(self):
        return [f"InputBounds{i}" for i in range(4)]


class StepPoly(AbstractBarrier):
    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub, alpha, beta,
                 apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
        self.register_buffer("alpha", th.tensor(alpha))
        self.register_buffer('beta', th.tensor(beta))

    def forward(self, zs, zdots):
        p_z_swing_eval = p_z_swing(*to_tuple(self.zdyn.phi_inv(zs), dim=-1))
        z1 = zs[:, 0, None]
        poly_eval = - (z1 - self.beta) * (z1 + self.beta) * (self.alpha / (self.beta ** 2))
        return p_z_swing_eval - poly_eval

class StepCircleLoss(AbstractBarrier):
    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub, left, right, center, apex, loss_gain,
                 apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
        h, k, r = findCircle(left, 0, right, 0, center, apex)
        # h_o, k_o, r_o = findCircle(left_o, 0, right_o, 0, center_o, apex_o)
        self.register_buffer("h", th.tensor(h))
        self.register_buffer('k', th.tensor(k))
        self.register_buffer('r', th.tensor(r))
        self.register_buffer('loss_gain', th.tensor(loss_gain))
        # self.register_buffer("h_o", th.tensor(h_o))
        # self.register_buffer('k_o', th.tensor(k_o))
        # self.register_buffer('r_o', th.tensor(r_o))

    def forward(self, zs, zdots):
        p_z_swing_eval = p_z_swing(*to_tuple(self.zdyn.phi_inv(zs), dim=-1))
        p_x_swing_eval = p_x_swing(*to_tuple(self.zdyn.phi_inv(zs), dim=-1))
        return self.loss_gain*(th.relu(-((p_x_swing_eval - self.h) ** 2 + (p_z_swing_eval - self.k) ** 2 - self.r ** 2 - self.lb)) \
                + th.relu(-(self.ub - ((p_x_swing_eval - self.h) ** 2 + (p_z_swing_eval - self.k) ** 2 - self.r ** 2))))

class StepCircle(AbstractBarrier):
    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub, left, right, center, apex,
                 apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
        h, k, r = findCircle(left, 0, right, 0, center, apex)
        # h_o, k_o, r_o = findCircle(left_o, 0, right_o, 0, center_o, apex_o)
        self.register_buffer("h", th.tensor(h))
        self.register_buffer('k', th.tensor(k))
        self.register_buffer('r', th.tensor(r))
        # self.register_buffer("h_o", th.tensor(h_o))
        # self.register_buffer('k_o', th.tensor(k_o))
        # self.register_buffer('r_o', th.tensor(r_o))

    def forward(self, zs, zdots):
        p_z_swing_eval = p_z_swing(*to_tuple(self.zdyn.phi_inv(zs), dim=-1))
        p_x_swing_eval = p_x_swing(*to_tuple(self.zdyn.phi_inv(zs), dim=-1))
        return (p_x_swing_eval - self.h) ** 2 + (p_z_swing_eval - self.k) ** 2 - self.r ** 2

    # def col_names(self):
    #     return [f"StepCircle{i}" for i in range(5)]

# class StepCircleExtended(AbstractBarrier):
#     def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub, left, right, center, apex, alpha_e_lb, alpha_e_ub,
#                  apply_to_post_impact=False):
#         super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
#         h, k, r = findCircle(left, 0, right, 0, center, apex)
#         # h_o, k_o, r_o = findCircle(left_o, 0, right_o, 0, center_o, apex_o)
#         self.register_buffer("h", th.tensor(h))
#         self.register_buffer('k', th.tensor(k))
#         self.register_buffer('r', th.tensor(r))
#         self.register_buffer('alpha_e_lb', th.tensor(alpha_e_lb))
#         self.register_buffer('alpha_e_ub', th.tensor(alpha_e_ub))
#         # self.register_buffer("h_o", th.tensor(h_o))
#         # self.register_buffer('k_o', th.tensor(k_o))
#         # self.register_buffer('r_o', th.tensor(r_o))
#
#     def forward(self, zs, zdots):
#         p_z_swing_eval = p_z_swing(*to_tuple(self.zdyn.phi_inv(zs), dim=-1))
#         p_x_swing_eval = p_x_swing(*to_tuple(self.zdyn.phi_inv(zs), dim=-1))
#         h1 = (p_x_swing_eval - self.h) ** 2 + (p_z_swing_eval - self.k) ** 2 - self.r ** 2  - self.lb
#         h2 = self.ub - (p_x_swing_eval - self.h) ** 2 + (p_z_swing_eval - self.k) ** 2 - self.r ** 2
#         _, hdot1 = th.autograd.functional.jvp(
#             func=h1,
#             inputs=zs,
#             v=zdots, create_graph=True)
#         _, hdot2 = th.autograd.functional.jvp(
#             func=h2,
#             inputs=zs,
#             v=zdots, create_graph=True)
#         return th.stackhdot +

class OutputSymmetry(AbstractBarrier):
    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub,
                 apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
        self.register_buffer("R", th.tensor([[0, 0, 0, 1], [0, 0, 1, 0], [0, 1, 0, 0], [1, 0, 0, 0]],dtype=th.float32))

    def forward(self, zs, zs_pi):
        return -th.norm(self.zdyn.yd(zs) - self.zdyn.yd(zs_pi)@self.R, p=2, dim=-1)[:,None]

    def col_names(self):
        return [f"OutputSymmetry{i}" for i in range(1)]

    def violation(self, zs, zdots, zddots,
                  zs_pi, zdots_pi, zddots_pi):
            return self._violation(zs, zdots, zddots, zs_pi, zdots_pi, zddots_pi)

    def _violation(self, zs, zdots, zddots, zs_pi, zdots_pi, zddots_pi):
        h, h_dot = th.autograd.functional.jvp(
            func=self,
            inputs=(zs, zs_pi),
            v=(zdots,  zdots_pi), create_graph=True)

        if self.lb is not None:
            lb_violation = th.relu(-h_dot - self.alpha_lb * (h - self.lb))
        else:
            lb_violation = 0.0
        if self.ub is not None:
            ub_violation = th.relu(h_dot - self.alpha_ub * (self.ub - h))
        else:
            ub_violation = 0.0
        return lb_violation + ub_violation

class OutputSymmetryLoss(AbstractBarrier):
    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub, loss_gain,
                 apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
        self.register_buffer("R", th.tensor([[0, 0, 0, 1], [0, 0, 1, 0], [0, 1, 0, 0], [1, 0, 0, 0]],dtype=th.float32))
        self.register_buffer("loss_gain", th.tensor(loss_gain, dtype=th.float32))

    def forward(self, zs, zdots):
        return -th.abs(self.zdyn.yd(zs) - self.zdyn.yd(self.zdyn.reset_map(zs))@self.R)

    def violation(self, zs, zdots, zddots, zs_pi, zdots_pi, zddots_pi):
        return th.relu(-self(zs, zdots))*self.loss_gain

    def col_names(self):
        return [f"OutputSymmetryLoss{i}" for i in range(4)]

class OutputSymmetryWithVel(AbstractBarrier):
    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub,
                 apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
        self.register_buffer("R", th.tensor([[0, 0, 0, 1], [0, 0, 1, 0], [0, 1, 0, 0], [1, 0, 0, 0]],dtype=th.float32))

    def forward(self, zs, zdots, zs_pi, zdots_pi):
        return th.stack([
            -th.norm(self.zdyn.yd(zs) - self.zdyn.yd(zs_pi) @ self.R, dim=-1, p=2),
            -th.norm(self.zdyn.yd.time_derivative(zs, zdots)[0] - self.zdyn.yd.time_derivative(zs_pi, zdots_pi)[0] @ self.R, p=2,
                     dim=-1)
        ], dim=-1)
        # return -th.abs(self.zdyn.yd(zs) - self.zdyn.yd(self.zdyn.reset_map(zs))@self.R) \
        #        - th.abs(self.zdyn.yd.time_derivative(zs, zdots)[0] - self.zdyn.yd.time_derivative(self.zdyn.reset_map(zs), self.zdyn.zdot(self.zdyn.reset_map(zs)))[0]@self.R)

    def col_names(self):
        return [f"OutputSymmetryWithVel{i}" for i in range(2)]

    def violation(self, zs, zdots, zddots,
                  zs_pi, zdots_pi, zddots_pi):
            return self._violation(zs, zdots, zddots, zs_pi, zdots_pi, zddots_pi)

    def _violation(self, zs, zdots, zddots, zs_pi, zdots_pi, zddots_pi):
        h, h_dot = th.autograd.functional.jvp(
            func=self,
            inputs=(zs, zdots, zs_pi, zdots_pi),
            v=(zdots, zddots,  zdots_pi, zddots_pi), create_graph=True)

        if self.lb is not None:
            lb_violation = th.relu(-h_dot - self.alpha_lb * (h - self.lb))
        else:
            lb_violation = 0.0
        if self.ub is not None:
            ub_violation = th.relu(h_dot - self.alpha_ub * (self.ub - h))
        else:
            ub_violation = 0.0
        return lb_violation + ub_violation

class OutputSymmetryWithVelBent(AbstractBarrier):
    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub,
                 apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
        self.register_buffer("R", th.tensor([[0, 0, 0, 1], [0, 0, 1, 0], [0, 1, 0, 0], [1, 0, 0, 0]],dtype=th.float32))

    def forward(self, zs, zdots):
        return -th.abs(self.zdyn.yd(zs) - self.zdyn.yd(self.zdyn.reset_map(zs))@self.R) \
               - th.abs(self.zdyn.yd.time_derivative(zs, zdots)[0] - self.zdyn.yd.time_derivative(self.zdyn.reset_map(zs), self.zdyn.zdot(self.zdyn.reset_map(zs)))[0]@self.R)

    def col_names(self):
        return [f"OutputSymmetryWithVelBent{i}" for i in range(4)]

    def alpha_lb_func(self, r):
        if r > 0:
            return self.alpha_lb * r
        else:
            return 1./self.alpha_lb * r

    def alpha_ub_func(self, r):
        if r > 0:
            return self.alpha_ub * r
        else:
            return 1./self.alpha_ub * r

    def _violation(self, zs, zdots, zddots):
        h, hdot = th.autograd.functional.jvp(
            func=self,
            inputs=(zs, zdots),
            v=(zdots, zddots), create_graph=True)

        if self.lb is not None:
            lb_violation = th.relu(-hdot - self.alpha_lb_func(h - self.lb))
        else:
            lb_violation = 0.0
        if self.ub is not None:
            ub_violation = th.relu(hdot - self.alpha_ub_func(self.ub - h))
        else:
            ub_violation = 0.0
        return lb_violation + ub_violation

class OutputSymmetryWithVelLoss(AbstractBarrier):
    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub, loss_gain,
                 apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
        self.register_buffer("R", th.tensor([[0, 0, 0, 1], [0, 0, 1, 0], [0, 1, 0, 0], [1, 0, 0, 0]],dtype=th.float32))
        self.register_buffer("loss_gain", th.tensor(loss_gain, dtype=th.float32))

    def forward(self, zs, zdots):
        return th.stack([
            -th.norm(self.zdyn.yd(zs) - self.zdyn.yd(self.zdyn.reset_map(zs)) @ self.R, p=2, dim=-1),
            -th.norm(self.zdyn.yd.time_derivative(zs, zdots)[0] -
                     self.zdyn.yd.time_derivative(self.zdyn.reset_map(zs), self.zdyn.zdot(self.zdyn.reset_map(zs)))[
                         0] @ self.R, p=2, dim=-1)
        ], dim=-1)
        # return -th.norm(self.zdyn.yd(zs) - self.zdyn.yd(self.zdyn.reset_map(zs))@self.R,p=2,dim=-1) \
        #        -th.norm(self.zdyn.yd.time_derivative(zs, zdots)[0] - self.zdyn.yd.time_derivative(self.zdyn.reset_map(zs), self.zdyn.zdot(self.zdyn.reset_map(zs)))[0]@self.R,p=2,dim=-1)

    def violation(self, zs, zdots, zddots, zs_pi, zdots_pi, zddots_pi):
        return th.relu(-self(zs, zdots))*self.loss_gain

    def col_names(self):
        return [f"OutputSymmetryWithVelLoss{i}" for i in range(2)]

# class FullStateSymmetry(AbstractBarrier):
#     def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub,
#                  apply_to_post_impact=False):
#         super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
#         self.register_buffer("R", th.tensor([[0, 0, 0, 1], [0, 0, 1, 0], [0, 1, 0, 0], [1, 0, 0, 0]],dtype=th.float32))
#
#     def forward(self, zs, zdots):
#         return (-th.abs(self.zdyn.phi_inv(self.zdyn.reset_map(zs)) - AmberDynamics.reset_map(self.zdyn.phi_inv(zs))))[:, :5]

class OrbitalBarrier(AbstractBarrier):
    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub,
                 apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
        self.register_buffer("mass", th.tensor(21.5562))
        self.register_buffer("g", th.tensor(9.81))
        self.register_buffer("z", th.tensor(0.8))

    def forward(self, zs, zdots):
        z1, z2 = to_tuple(zs, dim=-1)
        return (z2 / (self.mass * self.z))**2 - (self.g / self.z) * z1**2

class DiscreteTimeOrbitalBarrier(AbstractBarrier):
    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub,
                 apply_to_post_impact=False):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
        self.register_buffer("mass", th.tensor(21.5562))
        self.register_buffer("g", th.tensor(9.81))
        self.register_buffer("z", th.tensor(0.8))

    def forward(self, zs, zdots):
        z1, z2 = to_tuple(zs, dim=-1)
        return (z2 / (self.mass * self.z))**2 - (self.g / self.z) * z1**2

    def violation(self, zs, zdots, zddots,
                        zs_pi, zdots_pi, zddots_pi):

        delta_h = self(zs_pi, zdots) - self(zs, zdots)
        h = self(zs, zdots)

        if self.lb is not None:
            lb_violation = th.relu(-delta_h - self.alpha_lb * (h - self.lb))
        else:
            lb_violation = 0.0
        if self.ub is not None:
            ub_violation = th.relu(delta_h - self.alpha_ub * (self.ub - h))
        else:
            ub_violation = 0.0
        return lb_violation + ub_violation



class ZBounds(AbstractBarrier):
    def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub,
                 apply_to_post_impact=True,):
        super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
        self.register_buffer("scaling_matrix", th.tensor([[1 / .3, 0.], [0., 0.]]))

    def forward(self, zs, zdots):
        # Old Constraints
        ### SQUARE INTREGRAL CONSTRAINT BLOCK ###
        # scaling_matrix = th.tensor([[1 / .3, 0.], [0., 1 / 50.]],
        #                            device=device_name)
        # h_tp1 = 1 - th.norm(z_post_impact[:, :2] @ scaling_matrix, float('inf'),
        #                     dim=-1)
        # h_t = 1 - th.norm(z_samples[:, :2] @ scaling_matrix, float('inf'),
        #                   dim=-1)
        # delta_h = h_tp1 - h_t
        # violations = constraint_activation(- delta_h - 1. * h_t)
        ### SQUARE INTREGRAL CONSTRAINT BLOCK ###
        return (1 - th.norm(zs @ self.scaling_matrix, float('Inf'),dim=-1)).unsqueeze(-1)

    def col_names(self):
        return [f"ZBounds{i}" for i in range(2)]

# class GRF(AbstractBarrier):
#     def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub, mu,
#                  apply_to_post_impact=True,):
#         super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
#         self.register_buffer("mu", th.tensor(mu))
#         self.register_buffer("mass", th.tensor(21.5562))
#
#     @staticmethod
#     def _v_com(state):
#         state_params = to_tuple(state, dim=-1)
#         v_x_com_eval = v_x_com(*state_params)
#         v_z_com_eval = v_z_com(*state_params)
#         return th.cat([v_x_com_eval, v_z_com_eval], dim=-1)
#
#     def forward(self, zs, zdots):
#         state = self.zdyn.phi_inv(zs)
#         xddot = AmberDynamics.xddot(state, self.zdyn.input(zs))
#         v_com, vcom_dot = th.autograd.functional.jvp(func=GRF._v_com,
#                                               inputs=state,
#                                               v=xddot[:, :, 0],
#                                               create_graph=True)
#         grf = -self.mass * vcom_dot
#         return (-grf[:, 0] + self.mu*grf[:, 1])[:, None]
#
# class GRFCorrect(AbstractBarrier):
#     def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub, mu,
#                  apply_to_post_impact=True,):
#         super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
#         self.register_buffer("mu", th.tensor(mu))
#         self.register_buffer("mass", th.tensor(21.5562))
#
#     @staticmethod
#     def _v_com(state):
#         state_params = to_tuple(state, dim=-1)
#         v_x_com_eval = v_x_com(*state_params)
#         v_z_com_eval = v_z_com(*state_params)
#         return th.cat([v_x_com_eval, v_z_com_eval], dim=-1)
#
#     def forward(self, zs, zdots):
#         state = self.zdyn.phi_inv(zs)
#         xddot = AmberDynamics.xddot(state, self.zdyn.input(zs))
#         v_com, vcom_dot = th.autograd.functional.jvp(func=GRF._v_com,
#                                               inputs=state,
#                                               v=xddot[:, :, 0],
#                                               create_graph=True)
#         grf = -self.mass * vcom_dot
#         return th.stack([(-grf[:, 0] + self.mu*grf[:, 1])[:, None], (grf[:, 0] + self.mu*grf[:, 1])[:, None]], dim=1)[:, :, 0]
#
#     def col_names(self):
#         return [f"GRF{i}" for i in range(2)]
#
# class GRFCorrectLoss(AbstractBarrier):
#     def __init__(self, zdyn, lb, ub, alpha_lb, alpha_ub, mu, loss_gain,
#                  apply_to_post_impact=True,):
#         super().__init__(zdyn, lb, ub, alpha_lb, alpha_ub, apply_to_post_impact)
#         self.register_buffer("mu", th.tensor(mu))
#         self.register_buffer("mass", th.tensor(21.5562))
#         self.register_buffer("loss_gain", th.tensor(loss_gain))
#
#     @staticmethod
#     def _v_com(state):
#         state_params = to_tuple(state, dim=-1)
#         v_x_com_eval = v_x_com(*state_params)
#         v_z_com_eval = -v_z_com(*state_params)
#         return th.cat([v_x_com_eval, v_z_com_eval], dim=-1)
#
#     def forward(self, zs, zdots):
#         state = self.zdyn.phi_inv(zs)
#         xddot = AmberDynamics.xddot(state, self.zdyn.input(zs))
#         v_com, vcom_dot = th.autograd.functional.jvp(func=GRF._v_com,
#                                               inputs=state,
#                                               v=xddot[:, :, 0],
#                                               create_graph=True)
#         grf = -self.mass * vcom_dot
#         return self.loss_gain*(th.relu(-((-grf[:, 0] + self.mu*grf[:, 1])[:, None])) + th.relu(-((grf[:, 0] + self.mu*grf[:, 1])[:, None])))

def findCircle(x1, y1, x2, y2, x3, y3):
    M = np.matrix([[x1 ** 2 + y1 ** 2, x1, y1, 1], [x2 ** 2 + y2 ** 2, x2, y2, 1], [x3 ** 2 + y3 ** 2, x3, y3, 1]])
    M11 = np.linalg.det(M[:, [1, 2, 3]])
    M12 = np.linalg.det(M[:, [0, 2, 3]])
    M13 = np.linalg.det(M[:, [0, 1, 3]])
    M14 = np.linalg.det(M[:, [0, 1, 2]])

    h = 1./2.*M12/M11
    k = -1. / 2. * M13 / M11
    r = np.sqrt(h**2 + k**2 + M14/M11)

    return h, k, r