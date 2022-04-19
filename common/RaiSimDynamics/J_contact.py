import torch as th
from torch import cos,sin,arcsin,arccos

def J_contact_1_1(qsf, qsk, qsh, qnsh, qnsk):
    return - 0.4064*sin(qsf + qsk + 1.5707963267948966192313216916398) - 0.4064*sin(qsf - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193) - 0.4667*sin(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193) - 0.4667*sin(qsf + 1.5707963267948966192313216916398)+0*qsf

def J_contact_1_2(qsf, qsk, qsh, qnsh, qnsk):
    return - 0.4064*sin(qsf + qsk + 1.5707963267948966192313216916398) - 0.4064*sin(qsf - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193) - 0.4667*sin(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193)+0*qsf

def J_contact_1_3(qsf, qsk, qsh, qnsh, qnsk):
    return - 0.4064*sin(qsf - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193) - 0.4667*sin(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193)+0*qsf

def J_contact_1_4(qsf, qsk, qsh, qnsh, qnsk):
    return 0.4064*sin(qsf - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193) + 0.4667*sin(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193)+0*qsf

def J_contact_1_5(qsf, qsk, qsh, qnsh, qnsk):
    return 0.4667*sin(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193)+0*qsf

def J_contact_2_1(qsf, qsk, qsh, qnsh, qnsk):
    return 0.4064*cos(qsf + qsk + 1.5707963267948966192313216916398) + 0.4064*cos(qsf - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193) + 0.4667*cos(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193) + 0.4667*cos(qsf + 1.5707963267948966192313216916398)+0*qsf

def J_contact_2_2(qsf, qsk, qsh, qnsh, qnsk):
    return 0.4064*cos(qsf + qsk + 1.5707963267948966192313216916398) + 0.4064*cos(qsf - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193) + 0.4667*cos(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193)+0*qsf

def J_contact_2_3(qsf, qsk, qsh, qnsh, qnsk):
    return 0.4064*cos(qsf - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193) + 0.4667*cos(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193)+0*qsf

def J_contact_2_4(qsf, qsk, qsh, qnsh, qnsk):
    return - 0.4064*cos(qsf - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193) - 0.4667*cos(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193)+0*qsf

def J_contact_2_5(qsf, qsk, qsh, qnsh, qnsk):
    return -0.4667*cos(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk + 4.7123889803846898576939650749193)+0*qsf

def J_contact(qsf, qsk, qsh, qnsh, qnsk):
    theMatrix = th.stack([th.stack([J_contact_1_1(qsf, qsk, qsh, qnsh, qnsk),J_contact_1_2(qsf, qsk, qsh, qnsh, qnsk),J_contact_1_3(qsf, qsk, qsh, qnsh, qnsk),J_contact_1_4(qsf, qsk, qsh, qnsh, qnsk),J_contact_1_5(qsf, qsk, qsh, qnsh, qnsk)],dim=-1),th.stack([J_contact_2_1(qsf, qsk, qsh, qnsh, qnsk),J_contact_2_2(qsf, qsk, qsh, qnsh, qnsk),J_contact_2_3(qsf, qsk, qsh, qnsh, qnsk),J_contact_2_4(qsf, qsk, qsh, qnsh, qnsk),J_contact_2_5(qsf, qsk, qsh, qnsh, qnsk)],dim=-1)],dim=1)
    return theMatrix

