import torch as th
from torch import cos,sin,arcsin,arccos

def C_matrix_1_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.5*dqnsh*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) - 0.8010225648776*sin(qsh - 1.0*qnsh + qsk) + 0.13671838506144000795476856069399*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk)) - 0.5*dqsk*(3.459096394*sin(qsh + qsk) - 0.8010225648776*sin(qsh - 1.0*qnsh + qsk) + 0.13671838506144000795476856069399*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk) + 7.3760932192376*sin(qsk)) - 0.5*dqsh*(0.6975263988992*sin(qnsh - 1.0*qsh) + 3.459096394*sin(qsh + qsk) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) - 0.8010225648776*sin(qsh - 1.0*qnsh + qsk) + 0.13671838506144000795476856069399*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk) + 3.012163648*sin(qsh)) + 0.5*dqnsk*(0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) + 0.13671838506144000795476856069399*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk) - 0.11905367835648000692697223712457*sin(qnsk))+0*qsf

def C_matrix_1_2(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.5*dqnsh*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) - 0.8010225648776*sin(qsh - 1.0*qnsh + qsk) + 0.13671838506144000795476856069399*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk)) - 0.5*dqsf*(3.459096394*sin(qsh + qsk) - 0.8010225648776*sin(qsh - 1.0*qnsh + qsk) + 0.13671838506144000795476856069399*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk) + 7.3760932192376*sin(qsk)) - 0.5*dqsk*(3.459096394*sin(qsh + qsk) - 0.8010225648776*sin(qsh - 1.0*qnsh + qsk) + 0.13671838506144000795476856069399*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk) + 7.3760932192376*sin(qsk)) - 0.5*dqsh*(0.6975263988992*sin(qnsh - 1.0*qsh) + 3.459096394*sin(qsh + qsk) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) - 0.8010225648776*sin(qsh - 1.0*qnsh + qsk) + 0.13671838506144000795476856069399*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk) + 3.012163648*sin(qsh)) + 0.5*dqnsk*(0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) + 0.13671838506144000795476856069399*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk) - 0.11905367835648000692697223712457*sin(qnsk))+0*qsf

def C_matrix_1_3(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.3487631994496*dqnsh*sin(qnsh - 1.0*qsh) - 0.3487631994496*dqsf*sin(qnsh - 1.0*qsh) - 0.3487631994496*dqsh*sin(qnsh - 1.0*qsh) - 0.3487631994496*dqsk*sin(qnsh - 1.0*qsh) - 1.729548197*dqsf*sin(qsh + qsk) - 1.729548197*dqsh*sin(qsh + qsk) - 1.729548197*dqsk*sin(qsh + qsk) + 0.059526839178240003463486118562287*dqnsh*sin(qnsh + qnsk - 1.0*qsh) + 0.059526839178240003463486118562287*dqnsk*sin(qnsh + qnsk - 1.0*qsh) - 0.059526839178240003463486118562287*dqsf*sin(qnsh + qnsk - 1.0*qsh) - 0.059526839178240003463486118562287*dqsh*sin(qnsh + qnsk - 1.0*qsh) - 0.059526839178240003463486118562287*dqsk*sin(qnsh + qnsk - 1.0*qsh) - 0.4005112824388*dqnsh*sin(qsh - 1.0*qnsh + qsk) + 0.4005112824388*dqsf*sin(qsh - 1.0*qnsh + qsk) + 0.4005112824388*dqsh*sin(qsh - 1.0*qnsh + qsk) + 0.4005112824388*dqsk*sin(qsh - 1.0*qnsh + qsk) + 0.068359192530720003977384280346996*dqnsh*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk) + 0.068359192530720003977384280346996*dqnsk*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk) - 0.068359192530720003977384280346996*dqsf*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk) - 0.068359192530720003977384280346996*dqsh*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk) - 0.068359192530720003977384280346996*dqsk*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk) - 0.059526839178240003463486118562287*dqnsk*sin(qnsk) - 1.506081824*dqsf*sin(qsh) - 1.506081824*dqsh*sin(qsh) - 1.506081824*dqsk*sin(qsh)+0*qsf

def C_matrix_1_4(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.5*dqsf*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) - 0.8010225648776*sin(qsh - 1.0*qnsh + qsk) + 0.13671838506144000795476856069399*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk)) - 0.5*dqnsh*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) - 0.8010225648776*sin(qsh - 1.0*qnsh + qsk) + 0.13671838506144000795476856069399*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk)) + 0.5*dqsh*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) - 0.8010225648776*sin(qsh - 1.0*qnsh + qsk) + 0.13671838506144000795476856069399*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk)) + 0.5*dqsk*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) - 0.8010225648776*sin(qsh - 1.0*qnsh + qsk) + 0.13671838506144000795476856069399*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk)) - 0.5*dqnsk*(0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) + 0.13671838506144000795476856069399*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk) - 0.11905367835648000692697223712457*sin(qnsk))+0*qsf

def C_matrix_1_5(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.000014647352160000000852235757520248*(4064.0*sin(qnsh + qnsk - 1.0*qsh) + 4667.0*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk) - 4064.0*sin(qnsk))*(dqsf - 1.0*dqnsk - 1.0*dqnsh + dqsh + dqsk)+0*qsf

def C_matrix_2_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.5*dqsf*(3.459096394*sin(qsh + qsk) - 0.8010225648776*sin(qsh - 1.0*qnsh + qsk) + 0.13671838506144000795476856069399*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk) + 7.3760932192376*sin(qsk)) - 0.5*dqsh*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) + 3.012163648*sin(qsh)) + 0.5*dqnsk*(0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) - 0.11905367835648000692697223712457*sin(qnsk)) + 0.5*dqnsh*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh))+0*qsf

def C_matrix_2_2(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.5*dqnsk*(0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) - 0.11905367835648000692697223712457*sin(qnsk)) - 0.5*dqsh*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) + 3.012163648*sin(qsh)) + 0.5*dqnsh*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh))+0*qsf

def C_matrix_2_3(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.5*dqnsk*(0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) - 0.11905367835648000692697223712457*sin(qnsk)) - 0.5*dqsh*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) + 3.012163648*sin(qsh)) - 0.5*dqsk*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) + 3.012163648*sin(qsh)) - 0.5*dqsf*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) + 3.012163648*sin(qsh)) + 0.5*dqnsh*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh))+0*qsf

def C_matrix_2_4(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.5*dqsf*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh)) - 0.5*dqnsh*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh)) - 0.5*dqnsk*(0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) - 0.11905367835648000692697223712457*sin(qnsk)) + 0.5*dqsh*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh)) + 0.5*dqsk*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh))+0*qsf

def C_matrix_2_5(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.059526839178240003463486118562287*(sin(qnsh + qnsk - 1.0*qsh) - 1.0*sin(qnsk))*(dqsf - 1.0*dqnsk - 1.0*dqnsh + dqsh + dqsk)+0*qsf

def C_matrix_3_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.3487631994496*dqsf*sin(qnsh - 1.0*qsh) + 0.3487631994496*dqsk*sin(qnsh - 1.0*qsh) + 1.729548197*dqsf*sin(qsh + qsk) + 0.059526839178240003463486118562287*dqsf*sin(qnsh + qnsk - 1.0*qsh) + 0.059526839178240003463486118562287*dqsk*sin(qnsh + qnsk - 1.0*qsh) - 0.4005112824388*dqsf*sin(qsh - 1.0*qnsh + qsk) + 0.068359192530720003977384280346996*dqsf*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk) - 0.059526839178240003463486118562287*dqnsk*sin(qnsk) + 1.506081824*dqsf*sin(qsh) + 1.506081824*dqsk*sin(qsh)+0*qsf

def C_matrix_3_2(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.5*dqsf*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) + 3.012163648*sin(qsh)) + 0.5*dqsk*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) + 3.012163648*sin(qsh)) - 0.059526839178240003463486118562287*dqnsk*sin(qnsk)+0*qsf

def C_matrix_3_3(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return -0.059526839178240003463486118562287*dqnsk*sin(qnsk)+0*qsf

def C_matrix_3_4(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.059526839178240003463486118562287*dqnsk*sin(qnsk)+0*qsf

def C_matrix_3_5(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return -0.059526839178240003463486118562287*sin(qnsk)*(dqsf - 1.0*dqnsk - 1.0*dqnsh + dqsh + dqsk)+0*qsf

def C_matrix_4_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.059526839178240003463486118562287*dqnsk*sin(qnsk) - 0.5*dqsk*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh)) - 0.5*dqsf*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) - 0.8010225648776*sin(qsh - 1.0*qnsh + qsk) + 0.13671838506144000795476856069399*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk))+0*qsf

def C_matrix_4_2(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.059526839178240003463486118562287*dqnsk*sin(qnsk) - 0.5*dqsf*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh)) - 0.5*dqsk*(0.6975263988992*sin(qnsh - 1.0*qsh) + 0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh))+0*qsf

def C_matrix_4_3(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.059526839178240003463486118562287*dqnsk*sin(qnsk)+0*qsf

def C_matrix_4_4(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return -0.059526839178240003463486118562287*dqnsk*sin(qnsk)+0*qsf

def C_matrix_4_5(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.059526839178240003463486118562287*sin(qnsk)*(dqsf - 1.0*dqnsk - 1.0*dqnsh + dqsh + dqsk)+0*qsf

def C_matrix_5_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.059526839178240003463486118562287*dqsh*sin(qnsk) - 0.059526839178240003463486118562287*dqnsh*sin(qnsk) - 0.5*dqsk*(0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) - 0.11905367835648000692697223712457*sin(qnsk)) - 0.5*dqsf*(0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) + 0.13671838506144000795476856069399*sin(qnsh + qnsk - 1.0*qsh - 1.0*qsk) - 0.11905367835648000692697223712457*sin(qnsk))+0*qsf

def C_matrix_5_2(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.059526839178240003463486118562287*dqsh*sin(qnsk) - 0.5*dqsk*(0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) - 0.11905367835648000692697223712457*sin(qnsk)) - 0.059526839178240003463486118562287*dqnsh*sin(qnsk) - 0.5*dqsf*(0.11905367835648000692697223712457*sin(qnsh + qnsk - 1.0*qsh) - 0.11905367835648000692697223712457*sin(qnsk))+0*qsf

def C_matrix_5_3(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.059526839178240003463486118562287*sin(qnsk)*(dqsf - 1.0*dqnsh + dqsh + dqsk)+0*qsf

def C_matrix_5_4(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return -0.059526839178240003463486118562287*sin(qnsk)*(dqsf - 1.0*dqnsh + dqsh + dqsk)+0*qsf

def C_matrix_5_5(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return 0.0+0*qsf

def C_matrix(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    theMatrix = th.stack([th.stack([C_matrix_1_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk),C_matrix_1_2(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk),C_matrix_1_3(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk),C_matrix_1_4(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk),C_matrix_1_5(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk)],dim=-1),th.stack([C_matrix_2_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk),C_matrix_2_2(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk),C_matrix_2_3(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk),C_matrix_2_4(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk),C_matrix_2_5(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk)],dim=-1),th.stack([C_matrix_3_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk),C_matrix_3_2(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk),C_matrix_3_3(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk),C_matrix_3_4(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk),C_matrix_3_5(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk)],dim=-1),th.stack([C_matrix_4_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk),C_matrix_4_2(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk),C_matrix_4_3(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk),C_matrix_4_4(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk),C_matrix_4_5(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk)],dim=-1),th.stack([C_matrix_5_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk),C_matrix_5_2(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk),C_matrix_5_3(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk),C_matrix_5_4(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk),C_matrix_5_5(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk)],dim=-1)],dim=1)
    return theMatrix

