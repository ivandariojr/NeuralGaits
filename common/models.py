import numpy as np
import scipy.io
import torch as th
from torch import nn as nn

from utils import clamp, ncr


class TrueMLP(nn.Module):
    
    def __init__(self, n_input, n_output, n_hidden):
        super().__init__()
        self.l1 = nn.Linear(n_input, n_hidden)
        self.lh = nn.Linear(n_hidden, n_hidden)
        self.lout = nn.Linear(n_hidden, n_output)
        self.activation = nn.ReLU()
        self.register_buffer("input_scale", th.tensor([.3, 50]))

    def forward(self, x):

        x = self.l1(th.cat(
            [x[:, i, None] / self.input_scale[i] for i in range(x.shape[1])],
            dim=-1))
        x = self.activation(x)
        x = self.lh(x)
        x = self.activation(x)
        x = self.lout(x)
        return x

    def time2_derivative(self, x, xdot, xddot):
        out, out_dot = th.autograd.functional.jvp(
            lambda x_in, xd_in: self.time_derivative(x_in, xd_in)[1],
            inputs=(x, xdot),
            v=(xdot, xddot),
            create_graph=True)
        return out, out_dot

    # @torch.jit.export
    def time_derivative(self, x, xdot):
        out, out_dot = th.autograd.functional.jvp(self,
                                                  x,
                                                  xdot,
                                                  create_graph=True)
        return out, out_dot

    def jacobian(self, x):
        raw_jacobian = th.autograd.functional.jacobian(self,
                                                       x,
                                                       create_graph=True,
                                                       vectorize=True)
        idx = list(range(x.shape[0]))
        return raw_jacobian[idx, :, idx, :]

    def jacobiandot(self, x, xdot):
        raw_jacobian = th.autograd.functional.jacobian(
            lambda x: self.time_derivative(x, xdot)[1],
            x,
            create_graph=True, vectorize=True)
        idx = list(range(x.shape[0]))
        return raw_jacobian[idx, :, idx, :]

    instance = None

    @staticmethod
    def get_instance(**params):
        # This is dangerous.
        # this is only meant for the config generation
        if TrueMLP.instance is None:
            TrueMLP.instance = TrueMLP(**params)
        return TrueMLP.instance

class MLP(nn.Module):

    def __init__(self, n_input, n_output, n_hidden, neg_lim, pos_lim):
        super().__init__()
        assert len(neg_lim) == n_output
        assert len(pos_lim) == n_output
        self.l1 = nn.Linear(n_input, n_hidden)
        self.lh = nn.Linear(n_hidden, n_hidden)
        self.lout = nn.Linear(n_hidden, n_output)
        self.activation = nn.ReLU()

        self.register_buffer("neg_lim", th.tensor(neg_lim))
        self.register_buffer("pos_lim", th.tensor(pos_lim))
        self.register_buffer("range", self.pos_lim - self.neg_lim)
        self.register_buffer("input_scale", th.tensor([.3, 50]))
        # self.bounded_activations = nn.ModuleList([nn.Hardtanh(lb, ub) for lb, ub, in zip(self.neg_lim, self.pos_lim)])

    def forward(self, x):
        x = self.l1(th.cat(
            [x[:, i, None] / self.input_scale[i] for i in range(x.shape[1])],
            dim=-1))
        x = self.activation(x)
        x = self.lh(x)
        x = self.activation(x)
        x = self.lout(x)
        # x = th.stack([self.bounded_activations[i](x[:, i]) for i in range(len(self.bounded_activations))], dim=-1)
        # return x
        x = th.sigmoid(x) * self.range[None] + self.neg_lim[None]
        return x

    def time2_derivative(self, x, xdot, xddot):
        out, out_dot = th.autograd.functional.jvp(
            lambda x_in, xd_in: self.time_derivative(x_in, xd_in)[1],
            inputs=(x, xdot),
            v=(xdot, xddot),
            create_graph=True)
        return out, out_dot

    # @torch.jit.export
    def time_derivative(self, x, xdot):
        out, out_dot = th.autograd.functional.jvp(self,
                                                  x,
                                                  xdot,
                                                  create_graph=True)
        return out, out_dot

    def jacobian(self, x):
        raw_jacobian = th.autograd.functional.jacobian(self,
                                                       x,
                                                       create_graph=True,
                                                       vectorize=True)
        idx = list(range(x.shape[0]))
        return raw_jacobian[idx, :, idx, :]

    def jacobiandot(self, x, xdot):
        raw_jacobian = th.autograd.functional.jacobian(
            lambda x: self.time_derivative(x, xdot)[1],
            x,
            create_graph=True, vectorize=True)
        idx = list(range(x.shape[0]))
        return raw_jacobian[idx, :, idx, :]

    instance = None

    @staticmethod
    def get_instance(**params):
        # This is dangerous.
        # this is only meant for the config generation
        if MLP.instance is None:
            MLP.instance = MLP(**params)
        return MLP.instance

class CubicMLP(nn.Module):

    def __init__(self, n_input, n_output, n_hidden, neg_lim, pos_lim):
        super().__init__()
        assert len(neg_lim) == n_output
        assert len(pos_lim) == n_output

        self.l1 = nn.Linear(n_input, n_hidden)
        # self.lh = nn.Parameter(th.randn((n_hidden,)+(n_hidden+1, )*3))
        # self.lh = nn.Parameter(th.randn((n_hidden,)*4))
        self.lh = nn.Parameter(th.randn((n_hidden,)*3))
        # self.lh = nn.Linear(n_hidden, n_hidden)
        self.lout = nn.Linear(n_hidden, n_output)
        self.activation = nn.ReLU()

        self.register_buffer("neg_lim", th.tensor(neg_lim))
        self.register_buffer("pos_lim", th.tensor(pos_lim))
        self.register_buffer("range", self.pos_lim - self.neg_lim)
        self.register_buffer("input_scale", th.tensor([.3, 50]))
        # self.bounded_activations = nn.ModuleList([nn.Hardtanh(lb, ub) for lb, ub, in zip(self.neg_lim, self.pos_lim)])

    def forward(self, x):
        x = self.l1(th.cat(
            [x[:, i, None] / self.input_scale[i] for i in range(x.shape[1])],
            dim=-1))
        x = self.activation(x)
        # x = th.cat([x, th.ones(x.shape[0], 1, device=x.device)], dim=-1)
        x = th.einsum('lmn,im,in->il', self.lh, x,x)
        # x = th.einsum('lmno,im,in,io->il', self.lh, x,x,x,x,x)
        x = self.activation(x)
        x = self.lout(x)
        # x = th.stack([self.bounded_activations[i](x[:, i]) for i in range(len(self.bounded_activations))], dim=-1)
        # return x
        x = th.sigmoid(x) * self.range[None] + self.neg_lim[None]
        return x

    def time2_derivative(self, x, xdot, xddot):
        out, out_dot = th.autograd.functional.jvp(
            lambda x_in, xd_in: self.time_derivative(x_in, xd_in)[1],
            inputs=(x, xdot),
            v=(xdot, xddot),
            create_graph=True)
        return out, out_dot

        # @torch.jit.export

    def time_derivative(self, x, xdot):
        out, out_dot = th.autograd.functional.jvp(self,
                                                  x,
                                                  xdot,
                                                  create_graph=True)
        return out, out_dot

    def jacobian(self, x):
        raw_jacobian = th.autograd.functional.jacobian(self,
                                                       x,
                                                       create_graph=True,
                                                       vectorize=True)
        idx = list(range(x.shape[0]))
        return raw_jacobian[idx, :, idx, :]

    def jacobiandot(self, x, xdot):
        raw_jacobian = th.autograd.functional.jacobian(
            lambda x: self.time_derivative(x, xdot)[1],
            x,
            create_graph=True, vectorize=True)
        idx = list(range(x.shape[0]))
        return raw_jacobian[idx, :, idx, :]

    instance = None

    @staticmethod
    def get_instance(**params):
        # This is dangerous.
        # this is only meant for the config generation
        if CubicMLP.instance is None:
            CubicMLP.instance = CubicMLP(**params)
        return CubicMLP.instance


class D1MLP(nn.Module):

    def __init__(self, n_input, n_output, n_hidden, neg_lim, pos_lim):
        super().__init__()
        self.inner_mlp = MLP(n_input, n_output, n_hidden, neg_lim, pos_lim)

    def forward(self, x):
        return self.inner_mlp(x[:, 0, None])

    # @torch.jit.export
    def time_derivative(self, x, xdot):
        out, out_dot = th.autograd.functional.jvp(self,
                                                  x,
                                                  xdot,
                                                  create_graph=True)
        return out, out_dot

    def time2_derivative(self, x, xdot, xddot):
        out, out_dot = th.autograd.functional.jvp(
            lambda x_in, xd_in: self.time_derivative(x_in, xd_in)[1],
            inputs=(x, xdot),
            v=(xdot, xddot),
            create_graph=True)
        return out, out_dot

    instance = None

    @staticmethod
    def get_instance(**params):
        # This is dangerous.
        # this is only meant for the config generation
        if D1MLP.instance is None:
            D1MLP.instance = D1MLP(**params)
        return D1MLP.instance

class GaitCSV(nn.Module):
    def __init__(self, gait_params_file):
        super().__init__()
        data = scipy.io.loadmat(gait_params_file)
        self.register_buffer("alpha", th.from_numpy(
            data['gait']['alpha'][0][0].astype(np.float32)))
        self.register_buffer("z_bounds", th.from_numpy(
            data['gait']['z1_bounds'][0][0][0].astype(np.float32)))
        self.n = self.alpha.shape[1] - 1

    def forward(self, x):
        B = 0
        t = (x[:, 0] - self.z_bounds[0]) / (self.z_bounds[1] - self.z_bounds[0])
        t = clamp(t, 0, 1)[:, None]
        for i in range(self.n + 1):
            B = B + ncr(self.n, i) * ((1 - t) ** (self.n - i)) * (
                    t ** i) * self.alpha[None, :, i]
        return B

    def time_derivative(self, x, xdot):
        B, dB = th.autograd.functional.jvp(self, x, xdot, create_graph=True)
        return B, dB

    def jacobian(self, x):
        raw_jacobian = th.autograd.functional.jacobian(self,
                                                       x,
                                                       create_graph=True,
                                                       vectorize=True)
        idx = list(range(x.shape[0]))
        return raw_jacobian[idx, :, idx, :]

    def jacobiandot(self, x, xdot):
        raw_jacobian = th.autograd.functional.jacobian(
            lambda x: self.time_derivative(x, xdot)[1],
            x,
            create_graph=True, vectorize=True)
        idx = list(range(x.shape[0]))
        return raw_jacobian[idx, :, idx, :]

    instance = None
    @staticmethod
    def get_instance(**params):
        # This is dangerous.
        # this is only meant for the config generation
        if GaitCSV.instance is None:
            GaitCSV.instance = GaitCSV(**params)
        return GaitCSV.instance