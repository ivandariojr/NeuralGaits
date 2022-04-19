import torch as th
from torch import cos,sin,arcsin,arccos

def p_hip_1_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.4064*cos(qsf + qsk + 1.5707963267948966192313216916398) + 0.4667*cos(qsf + 1.5707963267948966192313216916398)+0*qsf

def p_hip_2_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.4064*sin(qsf + qsk + 1.5707963267948966192313216916398) + 0.4667*sin(qsf + 1.5707963267948966192313216916398)+0*qsf

def p_hip(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    theMatrix = th.stack([th.stack([p_hip_1_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk)],dim=-1),th.stack([p_hip_2_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk)],dim=-1)],dim=1)
    return theMatrix

