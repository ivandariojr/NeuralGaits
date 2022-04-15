from dataclasses import dataclass, field
from math import pi
from typing import List, Tuple, Optional, Any
from pathlib import Path
from hydra.core.config_store import ConfigStore
from omegaconf import II, MISSING
from dynamics import ZeroDynamics


# Models

@dataclass
class AbstractModel:
    pass

@dataclass
class TrueMLP(AbstractModel):
    _target_: str = "models.TrueMLP.get_instance"
    n_input: int = 2
    n_output: int = 4
    n_hidden: int = 256

@dataclass
class MLP(AbstractModel):
    _target_: str = "models.MLP.get_instance"
    n_input: int = 2
    n_output: int = 4
    n_hidden: int = 256
    neg_lim: Tuple[float] = field(default_factory=lambda: [0.2, -1., -1., 0.2])
    pos_lim: Tuple[float] = field(default_factory=lambda: [1.5, 1, 1, 1.5])

@dataclass
class CubicMLP(AbstractModel):
    _target_: str = "models.CubicMLP.get_instance"
    n_input: int = 2
    n_output: int = 4
    n_hidden: int = 16
    neg_lim: Tuple[float] = field(default_factory=lambda: [0.2, -1., -1., 0.2])
    pos_lim: Tuple[float] = field(default_factory=lambda: [1.5, 1, 1, 1.5])


@dataclass
class D1MLP(AbstractModel):
    _target_: str = "models.D1MLP.get_instance"
    n_input: int = 1
    n_output: int = 4
    n_hidden: int = 256
    neg_lim: Tuple[float] = field(default_factory=lambda: [0.2, -1., -1., 0.2])
    pos_lim: Tuple[float] = field(default_factory=lambda: [1.5, 1, 1, 1.5])


@dataclass
class GaitCSV(AbstractModel):
    _target_: str = "models.GaitCSV.get_instance"
    gait_params_file: str = str(Path(__file__).parent / "AmberGait.mat")

# Masks
@dataclass
class AbstractMask:
    pass


@dataclass
class AllMask(AbstractMask):
    _target_: str = 'utils.AllMask'


@dataclass
class AboveLineMask(AbstractMask):
    _target_: str = 'utils.AboveLineMask'
    slope: float = (-10. / -.1)
    y_intercept: float = 0.0

@dataclass
class GuardMask(AbstractMask):
    _target_: str = 'utils.GuardMask'
    edge: float = 0.3
    offset: float = 0.05

@dataclass
class BothGuardMask(AbstractMask):
    _target_: str = 'utils.BothGuardMask'
    edge: float = 0.3
    offset: float = 0.05

@dataclass
class NotBothGuardMask(BothGuardMask):
    _target_: str = 'utils.NotBothGuardMask'

@dataclass
class ForwardGuardMask(AbstractMask):
    _target_: str = 'utils.ForwardGuardMask'
    edge: float = 0.3
    offset: float = 0.05

@dataclass
class RealGuardMask(AbstractMask):
    _target_: str = 'utils.RealGuardMask'
    tol: float = 1e-3
    zdyn: Any = II('module.zdyn')

@dataclass
class ZeroDynamics:
    _target_: str = 'dynamics.ZeroDynamics.get_instance'
    yd: Any = II('module.yd')

@dataclass
class ROZeroDynamics(ZeroDynamics):
    _target_: str = 'dynamics.ROZeroDynamics.get_instance'

@dataclass
class COTDynamics(ZeroDynamics):
    _target_: str = 'dynamics.COTDynamics.get_instance'

@dataclass
class LearnableZeroDynamics(ZeroDynamics):
    _target_ = str = 'dynamics.LearnableZeroDynamics.get_instance'
    epsilon: Any = None

# Barriers
@dataclass
class AbstractBarrier:
    lb: Optional[float] = MISSING
    ub: Optional[float] = MISSING
    zdyn: Any = II('module.zdyn')
    alpha_lb: float = 1.0
    alpha_ub: float = 1.0
    apply_to_post_impact: bool = False


@dataclass
class TorsoAngle(AbstractBarrier):
    _target_: str = 'barriers.TorsoAngle'
    lb: float = -pi / 6
    ub: float = pi / 10


@dataclass
class FootOnGuard(AbstractBarrier):
    _target_: str = 'barriers.FootOnGuard'
    lb: float = 0.0
    ub: Optional[float] = None

@dataclass
class FootOnGuardLoss(AbstractBarrier):
    _target_: str = 'barriers.FootOnGuardLoss'
    lb: float = 0.0
    ub: float = 0.0
    loss_gain: float = 1e0

@dataclass
class Z0Dot(AbstractBarrier):
    _target_: str = 'barriers.Z0Dot'
    lb: float = 0.0
    ub: Optional[float] = None


@dataclass
class PelvisHeight(AbstractBarrier):
    _target_: str = 'barriers.PelvisHeight'
    lb: float = .5
    ub: Optional[float] = None

@dataclass
class PelvisX(AbstractBarrier):
    _target_: str = 'barriers.PelvisX'
    lb: Optional[float] = None
    ub: Optional[float] = 0.5

@dataclass
class HorizontalVelocity(AbstractBarrier):
    _target_: str = 'barriers.HorizontalVelocity'
    lb: float = 1.2
    ub: Optional[float] = 3.


@dataclass
class StepWidth(AbstractBarrier):
    _target_: str = 'barriers.StepWidth'
    lb: float = -0.05
    ub: float = 0.05
    alpha: float = 2.


@dataclass
class HDeltaJacobian(AbstractBarrier):
    _target_: str = 'barriers.HDeltaJacobian'
    lb: Optional[float] = None
    ub: float = 0.0

@dataclass
class HDeltaExplicit(AbstractBarrier):
    _target_: str = 'barriers.HDeltaExplicit'
    lb: Optional[float] = None
    ub: float = 0.0
    alpha: float = 1.0

@dataclass
class HDeltaExplicitBent(AbstractBarrier):
    _target_: str = 'barriers.HDeltaExplicit'
    lb: Optional[float] = None
    ub: float = 0.0
    alpha: float = 1.0

@dataclass
class HDeltaExplicitLoss(AbstractBarrier):
    _target_: str = 'barriers.HDeltaExplicitLoss'
    lb: Optional[float] = None
    ub: float = 0.0
    alpha: float = 1.0
    loss_gain: float = 1e0

@dataclass
class InputBounds(AbstractBarrier):
    _target_: str = 'barriers.InputBounds'
    lb: float = -15.
    ub: float = 15.


@dataclass
class StepPoly(AbstractBarrier):
    _target_: str = 'barriers.StepPoly'
    lb: float = -0.5
    ub: float = 0.5
    alpha: float = .15
    beta: float = .1

@dataclass
class OutputSymmetry(AbstractBarrier):
    _target_: str = 'barriers.OutputSymmetry'
    lb: float = 0.0
    ub: Optional[float] = None

@dataclass
class OutputSymmetryLoss(AbstractBarrier):
    _target_: str = 'barriers.OutputSymmetryLoss'
    lb: float = 0.0
    loss_gain: float = 1e0
    ub: Optional[float] = None

@dataclass
class OutputSymmetryWithVel(AbstractBarrier):
    _target_: str = 'barriers.OutputSymmetryWithVel'
    lb: float = 0.0
    ub: Optional[float] = None

@dataclass
class OutputSymmetryWithVelBent(AbstractBarrier):
    _target_: str = 'barriers.OutputSymmetryWithVel'
    lb: float = 0.0
    ub: Optional[float] = None

@dataclass
class OutputSymmetryWithVelLoss(AbstractBarrier):
    _target_: str = 'barriers.OutputSymmetryWithVelLoss'
    lb: float = 0.0
    loss_gain: float = 1e0
    ub: Optional[float] = None

@dataclass
class GRF(AbstractBarrier):
    _target_: str = 'barriers.GRF'
    lb: float = 0.0
    mu: float = 5e-1
    ub: Optional[float] = None

@dataclass
class GRFCorrect(AbstractBarrier):
    _target_: str = 'barriers.GRFCorrect'
    lb: float = 0.0
    mu: float = 5e-1
    ub: Optional[float] = None

@dataclass
class GRFCorrectLoss(AbstractBarrier):
    _target_: str = 'barriers.GRFCorrectLoss'
    lb: float = 0.0
    mu: float = 5e-1
    loss_gain: float = 1e0
    ub: Optional[float] = None

@dataclass
class StepCircle(AbstractBarrier):
    _target_: str = 'barriers.StepCircle'
    lb: float = 0.0
    ub: Optional[float] = None
    left: float = -0.3
    right: float = 0.3
    center: float = 0.0
    apex: float = 0.15

@dataclass
class StepCircleExtended(AbstractBarrier):
    _target_: str = 'barriers.StepCircleExtended'
    lb: float = 0.0
    ub: Optional[float] = None
    alpha_e_lb: float = 1e0
    alpha_e_ub: float = 1e0
    left: float = -0.3
    right: float = 0.3
    center: float = 0.0
    apex: float = 0.15

@dataclass
class StepCircleLoss(AbstractBarrier):
    _target_: str = 'barriers.StepCircleLoss'
    lb: float = 0.0
    ub: Optional[float] = None
    left: float = -0.3
    right: float = 0.3
    center: float = 0.0
    apex: float = 0.15
    loss_gain: float = 1e0

@dataclass
class FullStateSymmetry(AbstractBarrier):
    _target_: str = 'barriers.FullStateSymmetry'
    lb: float = 0.0
    ub: Optional[float] = None

@dataclass
class OrbitalBarrier(AbstractBarrier):
    _target_: str = 'barriers.OrbitalBarrier'
    lb: float = 1.5
    ub: float = 2.5

@dataclass
class DiscreteTimeOrbitalBarrier(AbstractBarrier):
    _target_: str = 'barriers.DiscreteTimeOrbitalBarrier'
    lb: Optional[float] = 1.5
    ub: Optional[float] = 2.5

@dataclass
class ZBounds(AbstractBarrier):
    _target_: str = 'barriers.ZBounds'
    lb: float = 0.
    ub: Optional[float] = None
    apply_to_post_impact: bool = True


@dataclass
class MaskBarrierPair:
    _target_: str = 'barriers.MaskBarrierPair'
    mask: AbstractMask = MISSING
    barriers_list: List[AbstractBarrier] = MISSING


@dataclass
class CompositeBarrier:
    _target_: str = 'barriers.CompositeBarrier'
    mask_barriers_pairs: List[MaskBarrierPair] = MISSING

@dataclass
class GeneralLearning:
    _target_: str = 'pl_modules.GeneralLearning'
    composite_barrier: CompositeBarrier = MISSING
    yd: AbstractModel = MISSING
    zdyn: ZeroDynamics = MISSING
    decay_epochs: List[int] = field(default_factory=lambda: [30, 60, 90])
    weight_decay: float = 0.0
    lr: float = 1e-3
    opt_name: str = 'SGD'
    momentum: float = 0.9
    beta1: float = 0.9
    beta2: float = 0.999
    eps: float = 1e-8


@dataclass
class DynLearning:
    _target_: str = 'pl_modules.DynLearning'
    yd: AbstractModel = MISSING
    zdyn: ZeroDynamics = MISSING
    decay_epochs: List[int] = field(default_factory=lambda: [30, 60, 90])
    weight_decay: float = 0.0
    lr: float = 1e-3
    opt_name: str = 'SGD'
    momentum: float = 0.9
    beta1: float = 0.9
    beta2: float = 0.999
    eps: float = 1e-8

@dataclass
class NumDynLearning(DynLearning):
    _target_: str = 'pl_modules.NumDynLearning'

@dataclass
class ExpCfg:
    batch_size: int = 32
    data_loader_workers: int = 4
    prefetch_factor: int = 4
    disable_logs: bool = False
    module: GeneralLearning = MISSING
    max_epochs: int = 120
    gpus: int = 0
    seed: int = 0
    dataset:str = 'CubeSampler'
    name_prefix : str = ''
    pretrained_model: Optional[str] = None
    pretrained_zdyn: Optional[str] = None


@dataclass
class DynLearnExpCfg:
    batch_size: int = 32
    data_loader_workers: int = 4
    prefetch_factor: int = 4
    disable_logs: bool = False
    module: DynLearning = MISSING
    max_epochs: int = 120
    gpus: int = 0
    seed: int = 0
    datasets: List[str] = MISSING
    delta_t: float = 0.05
    n_steps: int = 10
    name_prefix : str = ''
    pretrained_yd: Optional[str] = None

cs = ConfigStore.instance()
cs.store(group='module/composite_barrier/mask_barriers_pairs/barriers',
         name='TorsoAngle',
         node=TorsoAngle)
cs.store(group='module/composite_barrier/mask_barriers_pairs/barriers',
         name='FootOnGuard',
         node=FootOnGuard)
cs.store(group='module/composite_barrier/mask_barriers_pairs/barriers',
         name='Z0Dot',
         node=Z0Dot)
cs.store(group='module/composite_barrier/mask_barriers_pairs/mask',
         name='AllMask',
         node=AllMask)
cs.store(group='module/composite_barrier/mask_barriers_pairs/mask',
         name='AboveLineMask',
         node=AboveLineMask)
cs.store(group='module/composite_barrier/mask_barriers_pairs',
         name='MaskBarrierPair',
         node=MaskBarrierPair)
cs.store(group='module/composite_barrier',
         name='CompositeBarrier',
         node=CompositeBarrier)
cs.store(group='module/zdyn/epsilon', name='MLP', node=MLP)
cs.store(group='module/zdyn/epsilon', name='TrueMLP', node=TrueMLP)
cs.store(group='module/zdyn', name='LearnableZeroDynamics', node=LearnableZeroDynamics)
cs.store(group='module/zdyn', name='ROZeroDynamics', node=ROZeroDynamics)
cs.store(group='module/zdyn', name='ZeroDynamics', node=ZeroDynamics)
cs.store(group='module/zdyn', name='COTDynamics', node=COTDynamics)
cs.store(group='module/yd', name='GaitCSV', node=GaitCSV)
cs.store(group='module/yd', name='MLP', node=MLP)
cs.store(group='module/yd', name='CubicMLP', node=CubicMLP)
cs.store(group='module/yd', name='TrueMLP', node=TrueMLP)
cs.store(group='module/yd', name='D1MLP', node=D1MLP)
cs.store(group='module', name='GeneralLearning', node=GeneralLearning)
cs.store(group='module', name='DynLearning', node=DynLearning)
cs.store(group='module', name='NumDynLearning', node=NumDynLearning)
cs.store(group='module', name='LearnableZeroDynamics', node=LearnableZeroDynamics)
cs.store(name='experiment', node=ExpCfg)
cs.store(name='dyn_experiment', node=DynLearnExpCfg)
