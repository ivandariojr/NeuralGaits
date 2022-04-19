import torch as th
from torch import cos,sin,arcsin,arccos

def B_matrix_1_1(qsf, qsk, qsh, qnsh, qnsk):
    return 0.0+0*qsf

def B_matrix_1_2(qsf, qsk, qsh, qnsh, qnsk):
    return 0.0+0*qsf

def B_matrix_1_3(qsf, qsk, qsh, qnsh, qnsk):
    return 0.0+0*qsf

def B_matrix_1_4(qsf, qsk, qsh, qnsh, qnsk):
    return 0.0+0*qsf

def B_matrix_2_1(qsf, qsk, qsh, qnsh, qnsk):
    return 1.0+0*qsf

def B_matrix_2_2(qsf, qsk, qsh, qnsh, qnsk):
    return 0.0+0*qsf

def B_matrix_2_3(qsf, qsk, qsh, qnsh, qnsk):
    return 0.0+0*qsf

def B_matrix_2_4(qsf, qsk, qsh, qnsh, qnsk):
    return 0.0+0*qsf

def B_matrix_3_1(qsf, qsk, qsh, qnsh, qnsk):
    return 0.0+0*qsf

def B_matrix_3_2(qsf, qsk, qsh, qnsh, qnsk):
    return 1.0+0*qsf

def B_matrix_3_3(qsf, qsk, qsh, qnsh, qnsk):
    return 0.0+0*qsf

def B_matrix_3_4(qsf, qsk, qsh, qnsh, qnsk):
    return 0.0+0*qsf

def B_matrix_4_1(qsf, qsk, qsh, qnsh, qnsk):
    return 0.0+0*qsf

def B_matrix_4_2(qsf, qsk, qsh, qnsh, qnsk):
    return 0.0+0*qsf

def B_matrix_4_3(qsf, qsk, qsh, qnsh, qnsk):
    return 1.0+0*qsf

def B_matrix_4_4(qsf, qsk, qsh, qnsh, qnsk):
    return 0.0+0*qsf

def B_matrix_5_1(qsf, qsk, qsh, qnsh, qnsk):
    return 0.0+0*qsf

def B_matrix_5_2(qsf, qsk, qsh, qnsh, qnsk):
    return 0.0+0*qsf

def B_matrix_5_3(qsf, qsk, qsh, qnsh, qnsk):
    return 0.0+0*qsf

def B_matrix_5_4(qsf, qsk, qsh, qnsh, qnsk):
    return 1.0+0*qsf

def B_matrix(qsf, qsk, qsh, qnsh, qnsk):
    theMatrix = th.stack([th.stack([B_matrix_1_1(qsf, qsk, qsh, qnsh, qnsk),B_matrix_1_2(qsf, qsk, qsh, qnsh, qnsk),B_matrix_1_3(qsf, qsk, qsh, qnsh, qnsk),B_matrix_1_4(qsf, qsk, qsh, qnsh, qnsk)],dim=-1),th.stack([B_matrix_2_1(qsf, qsk, qsh, qnsh, qnsk),B_matrix_2_2(qsf, qsk, qsh, qnsh, qnsk),B_matrix_2_3(qsf, qsk, qsh, qnsh, qnsk),B_matrix_2_4(qsf, qsk, qsh, qnsh, qnsk)],dim=-1),th.stack([B_matrix_3_1(qsf, qsk, qsh, qnsh, qnsk),B_matrix_3_2(qsf, qsk, qsh, qnsh, qnsk),B_matrix_3_3(qsf, qsk, qsh, qnsh, qnsk),B_matrix_3_4(qsf, qsk, qsh, qnsh, qnsk)],dim=-1),th.stack([B_matrix_4_1(qsf, qsk, qsh, qnsh, qnsk),B_matrix_4_2(qsf, qsk, qsh, qnsh, qnsk),B_matrix_4_3(qsf, qsk, qsh, qnsh, qnsk),B_matrix_4_4(qsf, qsk, qsh, qnsh, qnsk)],dim=-1),th.stack([B_matrix_5_1(qsf, qsk, qsh, qnsh, qnsk),B_matrix_5_2(qsf, qsk, qsh, qnsh, qnsk),B_matrix_5_3(qsf, qsk, qsh, qnsh, qnsk),B_matrix_5_4(qsf, qsk, qsh, qnsh, qnsk)],dim=-1)],dim=1)
    return theMatrix

