import torch as th
from torch import cos,sin,arcsin,arccos

def torso_angle(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return qsf + qsh + qsk+0*qsf

