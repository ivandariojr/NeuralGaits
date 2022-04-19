import torch as th
from torch import cos,sin,arcsin,arccos

def G_matrix_1_1(qsf, qsk, qsh, qnsh, qnsk):
    return 8.4187179788400008462190271529835*sin(qsf - 1.0*qnsh + qsh + qsk) - 36.3549771*sin(qsf + qsh + qsk) + 1.43690524689600028366962982318*sin(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk) - 77.522471052840002130153607140528*sin(qsf + qsk) - 97.255892295144003165509786356324*sin(qsf)+0*qsf

def G_matrix_2_1(qsf, qsk, qsh, qnsh, qnsk):
    return 8.4187179788400008462190271529835*sin(qsf - 1.0*qnsh + qsh + qsk) - 36.3549771*sin(qsf + qsh + qsk) + 1.43690524689600028366962982318*sin(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk) - 77.522471052840002130153607140528*sin(qsf + qsk)+0*qsf

def G_matrix_3_1(qsf, qsk, qsh, qnsh, qnsk):
    return 8.4187179788400008462190271529835*sin(qsf - 1.0*qnsh + qsh + qsk) - 36.3549771*sin(qsf + qsh + qsk) + 1.43690524689600028366962982318*sin(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk)+0*qsf

def G_matrix_4_1(qsf, qsk, qsh, qnsh, qnsk):
    return - 8.4187179788400008462190271529835*sin(qsf - 1.0*qnsh + qsh + qsk) - 1.43690524689600028366962982318*sin(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk)+0*qsf

def G_matrix_5_1(qsf, qsk, qsh, qnsh, qnsk):
    return -1.43690524689600028366962982318*sin(qsf - 1.0*qnsk - 1.0*qnsh + qsh + qsk)+0*qsf

def G_matrix(qsf, qsk, qsh, qnsh, qnsk):
    theMatrix = th.stack([th.stack([G_matrix_1_1(qsf, qsk, qsh, qnsh, qnsk)],dim=-1),th.stack([G_matrix_2_1(qsf, qsk, qsh, qnsh, qnsk)],dim=-1),th.stack([G_matrix_3_1(qsf, qsk, qsh, qnsh, qnsk)],dim=-1),th.stack([G_matrix_4_1(qsf, qsk, qsh, qnsh, qnsk)],dim=-1),th.stack([G_matrix_5_1(qsf, qsk, qsh, qnsh, qnsk)],dim=-1)],dim=1)
    return theMatrix

