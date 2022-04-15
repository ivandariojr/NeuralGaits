import operator as op
from functools import reduce

import torch.nn as nn
import torch as th
from p_z_swing import p_z_swing


def to_tuple(x, dim: int):
    returns = list()
    device = x.device
    for i in range(x.shape[dim]):
        returns.append(th.index_select(x, dim, th.tensor([i], device=device)))
    return returns


def clamp(n, smallest, largest):
    return th.max(th.tensor([smallest]),
                  th.min(n,th.tensor([largest])))


def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer // denom  # or / in Python 2

class AllMask(nn.Module):

    def __init__(self):
       super().__init__()

    def forward(self, x):
        return th.ones_like(x, dtype=th.bool)[:, 0]

class GuardMask(nn.Module):
    def __init__(self, edge, offset):
        super().__init__()
        self.register_buffer('edge', th.tensor(edge))
        self.register_buffer('offset', th.tensor(offset))

    def forward(self, x):
        edge = self.edge
        offset = self.offset
        return (x[:, 0] < edge) * (x[:, 0] > (edge - offset)) * (x[:, 1] < 0) \
               + (x[:, 0] > -edge) * (x[:, 0] < (-edge + offset)) * (x[:, 1] > 0)

class BothGuardMask(nn.Module):
    def __init__(self, edge, offset):
        super().__init__()
        self.register_buffer('edge', th.tensor(edge))
        self.register_buffer('offset', th.tensor(offset))

    def forward(self, x):
        edge = self.edge
        offset = self.offset
        return (x[:, 0] < edge) * (x[:, 0] > (edge - offset)) * (x[:, 1] < 0) \
                + (x[:, 0] > -edge) * (x[:, 0] < (-edge + offset)) * (x[:, 1] < 0)

class NotBothGuardMask(BothGuardMask):

    def __init__(self, edge, offset):
        super().__init__(edge, offset)

    def forward(self, x):
        return ~super().forward(x)

class ForwardGuardMask(nn.Module):
    def __init__(self, edge, offset):
        super().__init__()
        self.register_buffer('edge', th.tensor(edge))
        self.register_buffer('offset', th.tensor(offset))

    def forward(self, x):
        edge = self.edge
        offset = self.offset
        return (x[:, 0] < edge) * (x[:, 0] > (edge - offset)) * (x[:, 1] < 0)

class RealGuardMask(nn.Module):
    def __init__(self, zdyn, tol):
        super().__init__()
        self.register_buffer('tol', th.tensor(tol))
        self.zdyn = zdyn

    def forward(self, x):
        tol = self.tol
        guard_samples = self.zdyn.pos_event_function(0.0, x)[:, 0]
        guard_sample_mask = (guard_samples > -1e-3) * (guard_samples < 0)
        if not any(guard_sample_mask):
            guard_sample_mask = (x[:, 0] < 0.3) * (x[:, 0] > (0.3 - 0.05)) * (x[:, 1] < 0)
        return guard_sample_mask

class AboveLineMask(nn.Module):
    def __init__(self, slope, y_intercept):
        super().__init__()
        self.register_buffer("slope", th.tensor(slope))
        self.register_buffer("y_intercept", th.tensor(y_intercept))

    def forward(self, x):
        return x[:, 1] > self.slope * x[:, 0] + self.y_intercept
