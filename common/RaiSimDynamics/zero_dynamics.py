import torch as th
from torch import cos,sin

def z_2(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk):
    return dqnsk*(0.059526839178240003463486118562287*cos(qnsh + qnsk - 1.0*qsh) + 0.068359192530720003977384280346996*cos(qnsh + qnsk - 1.0*qsh - 1.0*qsk) - 0.059526839178240003463486118562287*cos(qnsk) - 0.044462626260216001238106245466497) + dqsf*(3.459096394*cos(qsh + qsk) - 0.6975263988992*cos(qnsh - 1.0*qsh) - 0.11905367835648000692697223712457*cos(qnsh + qnsk - 1.0*qsh) - 0.8010225648776*cos(qsh - 1.0*qnsh + qsk) - 0.13671838506144000795476856069399*cos(qnsh + qnsk - 1.0*qsh - 1.0*qsk) + 0.11905367835648000692697223712457*cos(qnsk) + 3.012163648*cos(qsh) + 7.3760932192376*cos(qsk) + 9.2728521613209919963957919167115) + dqsk*(1.729548197*cos(qsh + qsk) - 0.6975263988992*cos(qnsh - 1.0*qsh) - 0.11905367835648000692697223712457*cos(qnsh + qnsk - 1.0*qsh) - 0.4005112824388*cos(qsh - 1.0*qnsh + qsk) - 0.068359192530720003977384280346996*cos(qnsh + qnsk - 1.0*qsh - 1.0*qsk) + 0.11905367835648000692697223712457*cos(qnsk) + 3.012163648*cos(qsh) + 3.6880466096188*cos(qsk) + 4.6699062266594160012381062454665) + dqnsh*(0.3487631994496*cos(qnsh - 1.0*qsh) + 0.059526839178240003463486118562287*cos(qnsh + qnsk - 1.0*qsh) + 0.4005112824388*cos(qsh - 1.0*qnsh + qsk) + 0.068359192530720003977384280346996*cos(qnsh + qnsk - 1.0*qsh - 1.0*qsk) - 0.11905367835648000692697223712457*cos(qnsk) - 0.3005779753298160012381062454665) - 1.0*dqsh*(0.3487631994496*cos(qnsh - 1.0*qsh) - 1.729548197*cos(qsh + qsk) + 0.059526839178240003463486118562287*cos(qnsh + qnsk - 1.0*qsh) + 0.4005112824388*cos(qsh - 1.0*qnsh + qsk) + 0.068359192530720003977384280346996*cos(qnsh + qnsk - 1.0*qsh - 1.0*qsk) - 0.11905367835648000692697223712457*cos(qnsk) - 1.506081824*cos(qsh) - 1.5510217390298160012381062454665)+0*qsf

def z_1(qsf, qsk, qsh, qnsh, qnsk):
    return - 0.873*qsf - 0.4604*qsk+0*qsf

def dz_2(z1, z2, yd1, yd2, yd3, yd4):
    return 8.4187179788400008462190271529835*cos(0.47262313860252004581901489117984*yd1 + yd2 - 1.0*yd3 - 1.145475372279495990836197021764*z1 + 4.7123889803846898576939650749193) + 36.3549771*cos(0.47262313860252004581901489117984*yd1 + yd2 - 1.145475372279495990836197021764*z1 + 1.5707963267948966192313216916398) + 1.43690524689600028366962982318*cos(0.47262313860252004581901489117984*yd1 + yd2 - 1.0*yd3 - 1.0*yd4 - 1.145475372279495990836197021764*z1 + 4.7123889803846898576939650749193) + 97.255892295144003165509786356324*cos(0.52737686139747995418098510882016*yd1 + 1.145475372279495990836197021764*z1 - 1.5707963267948966192313216916398) + 77.522471052840002130153607140528*cos(0.47262313860252004581901489117984*yd1 - 1.145475372279495990836197021764*z1 + 1.5707963267948966192313216916398)+0*z1

def Psi_Z_intermediate_1_1_1(z1, yd1, yd2, yd3, yd4):
    return 3.459096394*cos(yd1 + yd2) - 0.6975263988992*cos(yd2 - 1.0*yd3) - 0.8010225648776*cos(yd1 + yd2 - 1.0*yd3) - 0.11905367835648000692697223712457*cos(yd3 - 1.0*yd2 + yd4) + 7.3760932192376*cos(yd1) + 3.012163648*cos(yd2) + 0.11905367835648000692697223712457*cos(yd4) - 0.13671838506144000795476856069399*cos(yd1 + yd2 - 1.0*yd3 - 1.0*yd4) + 9.2728521613209919963957919167115+0*z1

def Psi_Z_intermediate_1_1_2(z1, yd1, yd2, yd3, yd4):
    return 1.729548197*cos(yd1 + yd2) - 0.6975263988992*cos(yd2 - 1.0*yd3) - 0.4005112824388*cos(yd1 + yd2 - 1.0*yd3) - 0.11905367835648000692697223712457*cos(yd3 - 1.0*yd2 + yd4) + 3.6880466096188*cos(yd1) + 3.012163648*cos(yd2) + 0.11905367835648000692697223712457*cos(yd4) - 0.068359192530720003977384280346996*cos(yd1 + yd2 - 1.0*yd3 - 1.0*yd4) + 4.6699062266594160012381062454665+0*z1

def Psi_Z_intermediate_1_1_3(z1, yd1, yd2, yd3, yd4):
    return 1.729548197*cos(yd1 + yd2) - 0.3487631994496*cos(yd2 - 1.0*yd3) - 0.4005112824388*cos(yd1 + yd2 - 1.0*yd3) - 0.059526839178240003463486118562287*cos(yd3 - 1.0*yd2 + yd4) + 1.506081824*cos(yd2) + 0.11905367835648000692697223712457*cos(yd4) - 0.068359192530720003977384280346996*cos(yd1 + yd2 - 1.0*yd3 - 1.0*yd4) + 1.5510217390298160012381062454665+0*z1

def Psi_Z_intermediate_1_1_4(z1, yd1, yd2, yd3, yd4):
    return 0.3487631994496*cos(yd2 - 1.0*yd3) + 0.4005112824388*cos(yd1 + yd2 - 1.0*yd3) + 0.059526839178240003463486118562287*cos(yd3 - 1.0*yd2 + yd4) - 0.11905367835648000692697223712457*cos(yd4) + 0.068359192530720003977384280346996*cos(yd1 + yd2 - 1.0*yd3 - 1.0*yd4) - 0.3005779753298160012381062454665+0*z1

def Psi_Z_intermediate_1_1_5(z1, yd1, yd2, yd3, yd4):
    return 0.059526839178240003463486118562287*cos(yd3 - 1.0*yd2 + yd4) - 0.059526839178240003463486118562287*cos(yd4) + 0.068359192530720003977384280346996*cos(yd1 + yd2 - 1.0*yd3 - 1.0*yd4) - 0.044462626260216001238106245466497+0*z1

def Psi_Z_intermediate_1(z1, yd1, yd2, yd3, yd4):
    theMatrix = th.stack([th.stack([Psi_Z_intermediate_1_1_1(z1, yd1, yd2, yd3, yd4),Psi_Z_intermediate_1_1_2(z1, yd1, yd2, yd3, yd4),Psi_Z_intermediate_1_1_3(z1, yd1, yd2, yd3, yd4),Psi_Z_intermediate_1_1_4(z1, yd1, yd2, yd3, yd4),Psi_Z_intermediate_1_1_5(z1, yd1, yd2, yd3, yd4)],dim=-1)],dim=1)
    return theMatrix
