import torch as th
from torch import cos,sin,arcsin,arccos

def p_z_swing(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.4064*sin(qsf + qsk + 1.5707963267948966192313216916398) + 0.4064*sin(qsf - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193) + 0.4667*sin(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193) + 0.4667*sin(qsf + 1.5707963267948966192313216916398)+0*qsf

