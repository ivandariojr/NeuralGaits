import torch as th
from torch import cos,sin,arcsin,arccos

def D_matrix_1_1(qsf, qsk, qsh, qnsh, qnsk):
    return 3.459096394*cos(qsh + qsk) - 0.6975263988992*cos(qnsh - 1.0*qsh) - 0.11905367835648000692697223712457*cos(qnsh + qnsk - 1.0*qsh) - 0.8010225648776*cos(qsh - 1.0*qnsh + qsk) - 0.13671838506144000795476856069399*cos(qnsh + qnsk - 1.0*qsh - 1.0*qsk) + 0.11905367835648000692697223712457*cos(qnsk) + 3.012163648*cos(qsh) + 7.3760932192376*cos(qsk) + 9.2728521613209919963957919167115+0*qsf

def D_matrix_1_2(qsf, qsk, qsh, qnsh, qnsk):
    return 1.729548197*cos(qsh + qsk) - 0.6975263988992*cos(qnsh - 1.0*qsh) - 0.11905367835648000692697223712457*cos(qnsh + qnsk - 1.0*qsh) - 0.4005112824388*cos(qsh - 1.0*qnsh + qsk) - 0.068359192530720003977384280346996*cos(qnsh + qnsk - 1.0*qsh - 1.0*qsk) + 0.11905367835648000692697223712457*cos(qnsk) + 3.012163648*cos(qsh) + 3.6880466096188*cos(qsk) + 4.6699062266594160012381062454665+0*qsf

def D_matrix_1_3(qsf, qsk, qsh, qnsh, qnsk):
    return 1.729548197*cos(qsh + qsk) - 0.3487631994496*cos(qnsh - 1.0*qsh) - 0.059526839178240003463486118562287*cos(qnsh + qnsk - 1.0*qsh) - 0.4005112824388*cos(qsh - 1.0*qnsh + qsk) - 0.068359192530720003977384280346996*cos(qnsh + qnsk - 1.0*qsh - 1.0*qsk) + 0.11905367835648000692697223712457*cos(qnsk) + 1.506081824*cos(qsh) + 1.5510217390298160012381062454665+0*qsf

def D_matrix_1_4(qsf, qsk, qsh, qnsh, qnsk):
    return 0.3487631994496*cos(qnsh - 1.0*qsh) + 0.059526839178240003463486118562287*cos(qnsh + qnsk - 1.0*qsh) + 0.4005112824388*cos(qsh - 1.0*qnsh + qsk) + 0.068359192530720003977384280346996*cos(qnsh + qnsk - 1.0*qsh - 1.0*qsk) - 0.11905367835648000692697223712457*cos(qnsk) - 0.3005779753298160012381062454665+0*qsf

def D_matrix_1_5(qsf, qsk, qsh, qnsh, qnsk):
    return 0.059526839178240003463486118562287*cos(qnsh + qnsk - 1.0*qsh) + 0.068359192530720003977384280346996*cos(qnsh + qnsk - 1.0*qsh - 1.0*qsk) - 0.059526839178240003463486118562287*cos(qnsk) - 0.044462626260216001238106245466497+0*qsf

def D_matrix_2_1(qsf, qsk, qsh, qnsh, qnsk):
    return 1.729548197*cos(qsh + qsk) - 0.6975263988992*cos(qnsh - 1.0*qsh) - 0.11905367835648000692697223712457*cos(qnsh + qnsk - 1.0*qsh) - 0.4005112824388*cos(qsh - 1.0*qnsh + qsk) - 0.068359192530720003977384280346996*cos(qnsh + qnsk - 1.0*qsh - 1.0*qsk) + 0.11905367835648000692697223712457*cos(qnsk) + 3.012163648*cos(qsh) + 3.6880466096188*cos(qsk) + 4.6699062266594160012381062454665+0*qsf

def D_matrix_2_2(qsf, qsk, qsh, qnsh, qnsk):
    return 0.11905367835648000692697223712457*cos(qnsk) - 0.11905367835648000692697223712457*cos(qnsh + qnsk - 1.0*qsh) - 0.6975263988992*cos(qnsh - 1.0*qsh) + 3.012163648*cos(qsh) + 4.6699062266594160012381062454665+0*qsf

def D_matrix_2_3(qsf, qsk, qsh, qnsh, qnsk):
    return 0.11905367835648000692697223712457*cos(qnsk) - 0.059526839178240003463486118562287*cos(qnsh + qnsk - 1.0*qsh) - 0.3487631994496*cos(qnsh - 1.0*qsh) + 1.506081824*cos(qsh) + 1.5510217390298160012381062454665+0*qsf

def D_matrix_2_4(qsf, qsk, qsh, qnsh, qnsk):
    return 0.3487631994496*cos(qnsh - 1.0*qsh) + 0.059526839178240003463486118562287*cos(qnsh + qnsk - 1.0*qsh) - 0.11905367835648000692697223712457*cos(qnsk) - 0.3005779753298160012381062454665+0*qsf

def D_matrix_2_5(qsf, qsk, qsh, qnsh, qnsk):
    return 0.059526839178240003463486118562287*cos(qnsh + qnsk - 1.0*qsh) - 0.059526839178240003463486118562287*cos(qnsk) - 0.044462626260216001238106245466497+0*qsf

def D_matrix_3_1(qsf, qsk, qsh, qnsh, qnsk):
    return 1.729548197*cos(qsh + qsk) - 0.3487631994496*cos(qnsh - 1.0*qsh) - 0.059526839178240003463486118562287*cos(qnsh + qnsk - 1.0*qsh) - 0.4005112824388*cos(qsh - 1.0*qnsh + qsk) - 0.068359192530720003977384280346996*cos(qnsh + qnsk - 1.0*qsh - 1.0*qsk) + 0.11905367835648000692697223712457*cos(qnsk) + 1.506081824*cos(qsh) + 1.5510217390298160012381062454665+0*qsf

def D_matrix_3_2(qsf, qsk, qsh, qnsh, qnsk):
    return 0.11905367835648000692697223712457*cos(qnsk) - 0.059526839178240003463486118562287*cos(qnsh + qnsk - 1.0*qsh) - 0.3487631994496*cos(qnsh - 1.0*qsh) + 1.506081824*cos(qsh) + 1.5510217390298160012381062454665+0*qsf

def D_matrix_3_3(qsf, qsk, qsh, qnsh, qnsk):
    return 0.11905367835648000692697223712457*cos(qnsk) + 1.5510217390298160012381062454665+0*qsf

def D_matrix_3_4(qsf, qsk, qsh, qnsh, qnsk):
    return - 0.11905367835648000692697223712457*cos(qnsk) - 0.3005779753298160012381062454665+0*qsf

def D_matrix_3_5(qsf, qsk, qsh, qnsh, qnsk):
    return - 0.059526839178240003463486118562287*cos(qnsk) - 0.044462626260216001238106245466497+0*qsf

def D_matrix_4_1(qsf, qsk, qsh, qnsh, qnsk):
    return 0.3487631994496*cos(qnsh - 1.0*qsh) + 0.059526839178240003463486118562287*cos(qnsh + qnsk - 1.0*qsh) + 0.4005112824388*cos(qsh - 1.0*qnsh + qsk) + 0.068359192530720003977384280346996*cos(qnsh + qnsk - 1.0*qsh - 1.0*qsk) - 0.11905367835648000692697223712457*cos(qnsk) - 0.3005779753298160012381062454665+0*qsf

def D_matrix_4_2(qsf, qsk, qsh, qnsh, qnsk):
    return 0.3487631994496*cos(qnsh - 1.0*qsh) + 0.059526839178240003463486118562287*cos(qnsh + qnsk - 1.0*qsh) - 0.11905367835648000692697223712457*cos(qnsk) - 0.3005779753298160012381062454665+0*qsf

def D_matrix_4_3(qsf, qsk, qsh, qnsh, qnsk):
    return - 0.11905367835648000692697223712457*cos(qnsk) - 0.3005779753298160012381062454665+0*qsf

def D_matrix_4_4(qsf, qsk, qsh, qnsh, qnsk):
    return 0.11905367835648000692697223712457*cos(qnsk) + 0.3005779753298160012381062454665+0*qsf

def D_matrix_4_5(qsf, qsk, qsh, qnsh, qnsk):
    return 0.059526839178240003463486118562287*cos(qnsk) + 0.044462626260216001238106245466497+0*qsf

def D_matrix_5_1(qsf, qsk, qsh, qnsh, qnsk):
    return 0.059526839178240003463486118562287*cos(qnsh + qnsk - 1.0*qsh) + 0.068359192530720003977384280346996*cos(qnsh + qnsk - 1.0*qsh - 1.0*qsk) - 0.059526839178240003463486118562287*cos(qnsk) - 0.044462626260216001238106245466497+0*qsf

def D_matrix_5_2(qsf, qsk, qsh, qnsh, qnsk):
    return 0.059526839178240003463486118562287*cos(qnsh + qnsk - 1.0*qsh) - 0.059526839178240003463486118562287*cos(qnsk) - 0.044462626260216001238106245466497+0*qsf

def D_matrix_5_3(qsf, qsk, qsh, qnsh, qnsk):
    return - 0.059526839178240003463486118562287*cos(qnsk) - 0.044462626260216001238106245466497+0*qsf

def D_matrix_5_4(qsf, qsk, qsh, qnsh, qnsk):
    return 0.059526839178240003463486118562287*cos(qnsk) + 0.044462626260216001238106245466497+0*qsf

def D_matrix_5_5(qsf, qsk, qsh, qnsh, qnsk):
    return 0.044462626260216001238106245466497+0*qsf

def D_matrix(qsf, qsk, qsh, qnsh, qnsk):
    theMatrix = th.stack([th.stack([D_matrix_1_1(qsf, qsk, qsh, qnsh, qnsk),D_matrix_1_2(qsf, qsk, qsh, qnsh, qnsk),D_matrix_1_3(qsf, qsk, qsh, qnsh, qnsk),D_matrix_1_4(qsf, qsk, qsh, qnsh, qnsk),D_matrix_1_5(qsf, qsk, qsh, qnsh, qnsk)],dim=-1),th.stack([D_matrix_2_1(qsf, qsk, qsh, qnsh, qnsk),D_matrix_2_2(qsf, qsk, qsh, qnsh, qnsk),D_matrix_2_3(qsf, qsk, qsh, qnsh, qnsk),D_matrix_2_4(qsf, qsk, qsh, qnsh, qnsk),D_matrix_2_5(qsf, qsk, qsh, qnsh, qnsk)],dim=-1),th.stack([D_matrix_3_1(qsf, qsk, qsh, qnsh, qnsk),D_matrix_3_2(qsf, qsk, qsh, qnsh, qnsk),D_matrix_3_3(qsf, qsk, qsh, qnsh, qnsk),D_matrix_3_4(qsf, qsk, qsh, qnsh, qnsk),D_matrix_3_5(qsf, qsk, qsh, qnsh, qnsk)],dim=-1),th.stack([D_matrix_4_1(qsf, qsk, qsh, qnsh, qnsk),D_matrix_4_2(qsf, qsk, qsh, qnsh, qnsk),D_matrix_4_3(qsf, qsk, qsh, qnsh, qnsk),D_matrix_4_4(qsf, qsk, qsh, qnsh, qnsk),D_matrix_4_5(qsf, qsk, qsh, qnsh, qnsk)],dim=-1),th.stack([D_matrix_5_1(qsf, qsk, qsh, qnsh, qnsk),D_matrix_5_2(qsf, qsk, qsh, qnsh, qnsk),D_matrix_5_3(qsf, qsk, qsh, qnsh, qnsk),D_matrix_5_4(qsf, qsk, qsh, qnsh, qnsk),D_matrix_5_5(qsf, qsk, qsh, qnsh, qnsk)],dim=-1)],dim=1)
    return theMatrix

