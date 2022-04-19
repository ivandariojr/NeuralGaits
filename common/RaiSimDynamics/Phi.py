import torch as th
from torch import cos,sin

def Phi_1_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    return qsk - 1.0*yd1+0*qsf

def Phi_2_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    return qsh - 1.0*yd2+0*qsf

def Phi_3_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    return qnsh - 1.0*yd3+0*qsf

def Phi_4_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    return qnsk - 1.0*yd4+0*qsf

def Phi_5_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    return dqsk - 1.0*dyd1+0*qsf

def Phi_6_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    return dqsh - 1.0*dyd2+0*qsf

def Phi_7_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    return dqnsh - 1.0*dyd3+0*qsf

def Phi_8_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    return dqnsk - 1.0*dyd4+0*qsf

def Phi_9_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    return - 0.873*qsf - 0.4604*qsk+0*qsf

def Phi_10_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    return dqnsk*(0.059526839178240003463486118562287*cos(qnsh + qnsk - 1.0*qsh) + 0.068359192530720003977384280346996*cos(qnsh + qnsk - 1.0*qsh - 1.0*qsk) - 0.059526839178240003463486118562287*cos(qnsk) - 0.044462626260216001238106245466497) + dqsf*(3.459096394*cos(qsh + qsk) - 0.6975263988992*cos(qnsh - 1.0*qsh) - 0.11905367835648000692697223712457*cos(qnsh + qnsk - 1.0*qsh) - 0.8010225648776*cos(qsh - 1.0*qnsh + qsk) - 0.13671838506144000795476856069399*cos(qnsh + qnsk - 1.0*qsh - 1.0*qsk) + 0.11905367835648000692697223712457*cos(qnsk) + 3.012163648*cos(qsh) + 7.3760932192376*cos(qsk) + 9.2728521613209919963957919167115) + dqsk*(1.729548197*cos(qsh + qsk) - 0.6975263988992*cos(qnsh - 1.0*qsh) - 0.11905367835648000692697223712457*cos(qnsh + qnsk - 1.0*qsh) - 0.4005112824388*cos(qsh - 1.0*qnsh + qsk) - 0.068359192530720003977384280346996*cos(qnsh + qnsk - 1.0*qsh - 1.0*qsk) + 0.11905367835648000692697223712457*cos(qnsk) + 3.012163648*cos(qsh) + 3.6880466096188*cos(qsk) + 4.6699062266594160012381062454665) + dqnsh*(0.3487631994496*cos(qnsh - 1.0*qsh) + 0.059526839178240003463486118562287*cos(qnsh + qnsk - 1.0*qsh) + 0.4005112824388*cos(qsh - 1.0*qnsh + qsk) + 0.068359192530720003977384280346996*cos(qnsh + qnsk - 1.0*qsh - 1.0*qsk) - 0.11905367835648000692697223712457*cos(qnsk) - 0.3005779753298160012381062454665) - 1.0*dqsh*(0.3487631994496*cos(qnsh - 1.0*qsh) - 1.729548197*cos(qsh + qsk) + 0.059526839178240003463486118562287*cos(qnsh + qnsk - 1.0*qsh) + 0.4005112824388*cos(qsh - 1.0*qnsh + qsk) + 0.068359192530720003977384280346996*cos(qnsh + qnsk - 1.0*qsh - 1.0*qsk) - 0.11905367835648000692697223712457*cos(qnsk) - 1.506081824*cos(qsh) - 1.5510217390298160012381062454665)+0*qsf

def Phi(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    theMatrix = th.stack([th.stack([Phi_1_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4)],dim=-1),th.stack([Phi_2_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4)],dim=-1),th.stack([Phi_3_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4)],dim=-1),th.stack([Phi_4_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4)],dim=-1),th.stack([Phi_5_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4)],dim=-1),th.stack([Phi_6_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4)],dim=-1),th.stack([Phi_7_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4)],dim=-1),th.stack([Phi_8_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4)],dim=-1),th.stack([Phi_9_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4)],dim=-1),th.stack([Phi_10_1(qsf, qsk, qsh, qnsh, qnsk, dqsf, dqsk, dqsh, dqnsh, dqnsk, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4)],dim=-1)],dim=1)
    return theMatrix

