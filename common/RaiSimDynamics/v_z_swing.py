import torch as th
from torch import cos,sin,arcsin,arccos

def v_z_swing(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return dqsk*(0.4064*cos(qsf + qsk + 1.5707963267948966192313216916398) + 0.4064*cos(qsf - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193) + 0.4667*cos(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193)) - 0.4667*dqnsk*cos(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193) - 1.0*dqnsh*(0.4064*cos(qsf - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193) + 0.4667*cos(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193)) + dqsh*(0.4064*cos(qsf - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193) + 0.4667*cos(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193)) + dqsf*(0.4064*cos(qsf + qsk + 1.5707963267948966192313216916398) + 0.4064*cos(qsf - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193) + 0.4667*cos(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193) + 0.4667*cos(qsf + 1.5707963267948966192313216916398))+0*qsf

