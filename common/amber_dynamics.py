from torch import nn as nn
import torch as th
from B_matrix import B_matrix
from D_matrix import D_matrix
from H_vector import H_vector
from J_contact import J_contact
from utils import to_tuple


class AmberDynamics(nn.Module):
    def __init__(self):
        super().__init__()

    def forward(self, t, state, input):
        return AmberDynamics.xddot(state, input)

    @staticmethod
    def xddot(state, input):
        n_batch = state.shape[0]
        q = state[:, :5]
        qdot = state[:, 5:10]
        q_params = to_tuple(q, dim=1)
        qdot_params = to_tuple(qdot, dim=1)
        D = D_matrix(*q_params).squeeze()
        # G = G_matrix(*q_params)[:,:,0,:]
        # C = C_matrix(*q_params, *qdot_params)
        H = H_vector(*q_params, *qdot_params)[:,:,0,:]
        B = B_matrix(*q_params)[:,:,0,:]
        f = th.cat([
            qdot[:, :, None],
            -th.inverse(D) @ H
        ], dim=1)
        g = th.cat([
            th.zeros(n_batch, 5, 4, device=state.device),
            th.inverse(D) @ B], dim=1)
        return f + g @ input

    @staticmethod
    def reset_map(state):
        q = state[:, :5]
        qdot = state[:, 5:10]
        q_params = to_tuple(q, dim=1)
        qdot_params = to_tuple(qdot, dim=1)
        D = D_matrix(*q_params)[:, :, 0]
        J = J_contact(*q_params)[:, :, 0]
        DJ = th.cat([D, J], dim=1)
        Jtop = th.cat([J.transpose(2, 1),
                       th.zeros((J.shape[0], 2, 2), device=J.device, dtype=J.dtype)], dim=1)
        JDJ = th.cat([DJ, -Jtop], dim=-1)

        rhs = th.cat([D @ qdot[:, :, None],
                      th.zeros(state.shape[0], 2, 1, device=state.device, dtype=state.dtype)], dim=1)
        soln = th.inverse(JDJ) @ rhs
        # qsf_at_liftoff_eval = qsf_at_liftoff(*q_params)
        # DeltaFactor = th.cat([
        #     th.zeros((4, 1), dtype=J.dtype, device=J.device),
        #     th.eye(4, dtype=J.dtype, device=J.device)
        # ], dim=1)
        # q_plus = th.cat([qsf_at_liftoff_eval, q @ DeltaFactor.transpose(1,0)], dim=1)
        DeltaFactor = th.tensor([[1, 1, 1, -1, -1], [0, 0, 0, 0, 1], [0, 0, 0, 1, 0], [0, 0, 1, 0, 0], [0, 1, 0, 0, 0]], device=J.device, dtype=J.dtype)
        q_plus = q @ DeltaFactor.transpose(1, 0)
        after_reset_state = th.cat([q_plus, soln[:, :5, 0]], dim=1)
        # th.cat([state, after_reset_state], dim=-1).detach().numpy()
        return after_reset_state

    @staticmethod
    def input(H, state, yddot):
        g = AmberDynamics.g(state)
        f = AmberDynamics.f(state)
        u = th.pinverse(H[None] @ g) @ (-H[None] @ f + yddot[:,:,None])
        return u


    @staticmethod
    def g(state):
        n_batch = state.shape[0]
        q = state[:, :5]
        qdot = state[:, 5:10]
        q_params = to_tuple(q, dim=1)
        qdot_params = to_tuple(qdot, dim=1)
        D = D_matrix(*q_params).squeeze()
        B = B_matrix(*q_params)[:, :, 0, :]
        return th.inverse(D) @ B

    @staticmethod
    def f(state):
        n_batch = state.shape[0]
        q = state[:, :5]
        qdot = state[:, 5:10]
        q_params = to_tuple(q, dim=1)
        qdot_params = to_tuple(qdot, dim=1)
        D = D_matrix(*q_params).squeeze()
        H = H_vector(*q_params, *qdot_params)[:,:,0,:]
        return -th.inverse(D) @ H