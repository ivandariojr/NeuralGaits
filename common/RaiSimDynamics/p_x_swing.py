import torch as th
from torch import cos,sin,arcsin,arccos

def p_x_swing(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.4064*cos(qsf + qsk + 1.5707963267948966192313216916398) + 0.4064*cos(qsf - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193) + 0.4667*cos(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193) + 0.4667*cos(qsf + 1.5707963267948966192313216916398)+0*qsf

