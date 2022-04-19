import torch as th
from torch import cos,sin

def Phi_Inv_1_1(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    return - 0.52737686139747995418098510882016*yd1 - 1.145475372279495990836197021764*z1+0*n1

def Phi_Inv_2_1(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    return yd1+0*n1

def Phi_Inv_3_1(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    return yd2+0*n1

def Phi_Inv_4_1(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    return yd3+0*n1

def Phi_Inv_5_1(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    return yd4+0*n1

def Phi_Inv_6_1(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    return -(1.0*(dyd4*(0.059526839178240003463486118562287*cos(yd3 - 1.0*yd2 + yd4) - 0.059526839178240003463486118562287*cos(yd4) + 0.068359192530720003977384280346996*cos(yd1 + yd2 - 1.0*yd3 - 1.0*yd4) - 0.044462626260216001238106245466497) - 1.0*dyd2*(0.3487631994496*cos(yd2 - 1.0*yd3) - 1.729548197*cos(yd1 + yd2) + 0.4005112824388*cos(yd1 + yd2 - 1.0*yd3) + 0.059526839178240003463486118562287*cos(yd3 - 1.0*yd2 + yd4) - 1.506081824*cos(yd2) - 0.11905367835648000692697223712457*cos(yd4) + 0.068359192530720003977384280346996*cos(yd1 + yd2 - 1.0*yd3 - 1.0*yd4) - 1.5510217390298160012381062454665) - 1.0*z2 + dyd1*(1.729548197*cos(yd1 + yd2) - 0.6975263988992*cos(yd2 - 1.0*yd3) - 0.4005112824388*cos(yd1 + yd2 - 1.0*yd3) - 0.11905367835648000692697223712457*cos(yd3 - 1.0*yd2 + yd4) + 3.6880466096188*cos(yd1) + 3.012163648*cos(yd2) + 0.11905367835648000692697223712457*cos(yd4) - 0.068359192530720003977384280346996*cos(yd1 + yd2 - 1.0*yd3 - 1.0*yd4) + 4.6699062266594160012381062454665) + dyd3*(0.3487631994496*cos(yd2 - 1.0*yd3) + 0.4005112824388*cos(yd1 + yd2 - 1.0*yd3) + 0.059526839178240003463486118562287*cos(yd3 - 1.0*yd2 + yd4) - 0.11905367835648000692697223712457*cos(yd4) + 0.068359192530720003977384280346996*cos(yd1 + yd2 - 1.0*yd3 - 1.0*yd4) - 0.3005779753298160012381062454665)))/(3.459096394*cos(yd1 + yd2) - 0.6975263988992*cos(yd2 - 1.0*yd3) - 0.8010225648776*cos(yd1 + yd2 - 1.0*yd3) - 0.11905367835648000692697223712457*cos(yd3 - 1.0*yd2 + yd4) + 7.3760932192376*cos(yd1) + 3.012163648*cos(yd2) + 0.11905367835648000692697223712457*cos(yd4) - 0.13671838506144000795476856069399*cos(yd1 + yd2 - 1.0*yd3 - 1.0*yd4) + 9.2728521613209919963957919167115)+0*n1

def Phi_Inv_7_1(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    return dyd1+0*n1

def Phi_Inv_8_1(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    return dyd2+0*n1

def Phi_Inv_9_1(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    return dyd3+0*n1

def Phi_Inv_10_1(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    return dyd4+0*n1

def Phi_Inv(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4):
    theMatrix = th.stack([th.stack([Phi_Inv_1_1(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4)],dim=-1),th.stack([Phi_Inv_2_1(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4)],dim=-1),th.stack([Phi_Inv_3_1(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4)],dim=-1),th.stack([Phi_Inv_4_1(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4)],dim=-1),th.stack([Phi_Inv_5_1(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4)],dim=-1),th.stack([Phi_Inv_6_1(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4)],dim=-1),th.stack([Phi_Inv_7_1(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4)],dim=-1),th.stack([Phi_Inv_8_1(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4)],dim=-1),th.stack([Phi_Inv_9_1(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4)],dim=-1),th.stack([Phi_Inv_10_1(n1, n2, n3, n4, n5, n6, n7, n8, z1, z2, yd1, yd2, yd3, yd4, dyd1, dyd2, dyd3, dyd4)],dim=-1)],dim=1)
    return theMatrix

