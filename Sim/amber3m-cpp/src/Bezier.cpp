#include "../include/Bezier.hpp"

void_f1_ptr genBezier(int size, void_f1_ptr fp) {
  switch(size){
  case 2:
  	fp = &B2; break;
  case 3:
  	fp = &B3; break;
  case 4:
  	fp = &B4; break;
  case 5:
  	fp = &B5; break;
  case 6:
  	fp = &B6; break;
  }
  return fp;
}

void_f1_ptr genBezierDot(int size, void_f1_ptr fp) {
  switch(size){
  case 2:
  	fp = &B2_dot; break;
  case 3:
  	fp = &B3_dot; break;
  case 4:
  	fp = &B4_dot; break;
  case 5:
  	fp = &B5_dot; break;
  case 6:
  	fp = &B6_dot; break;
  }
  return fp;
}

float B2(float t,Eigen::VectorXd alpha){return pow(1-t,2)*alpha[0]+2*pow(1-t,1)*pow(t,1)*alpha[1]+pow(t,2)*alpha[2];}
float B2_dot(float t,Eigen::VectorXd alpha){return 2*pow(1-t,1)*(alpha[1]-alpha[0])+pow(t,1)*(alpha[2]-alpha[1]);}
float B3(float t,Eigen::VectorXd alpha){return pow(1-t,3)*alpha[0]+3*pow(1-t,2)*pow(t,1)*alpha[1]+3*pow(1-t,1)*pow(t,2)*alpha[2]+pow(t,3)*alpha[3];}
float B3_dot(float t,Eigen::VectorXd alpha){return 3*pow(1-t,2)*(alpha[1]-alpha[0])+2*pow(1-t,1)*pow(t,1)*(alpha[2]-alpha[1])+pow(t,2)*(alpha[3]-alpha[2]);}
float B4(float t,Eigen::VectorXd alpha){return pow(1-t,4)*alpha[0]+4*pow(1-t,3)*pow(t,1)*alpha[1]+6*pow(1-t,2)*pow(t,2)*alpha[2]+4*pow(1-t,1)*pow(t,3)*alpha[3]+pow(t,4)*alpha[4];}
float B4_dot(float t,Eigen::VectorXd alpha){return 4*pow(1-t,3)*(alpha[1]-alpha[0])+3*pow(1-t,2)*pow(t,1)*(alpha[2]-alpha[1])+3*pow(1-t,1)*pow(t,2)*(alpha[3]-alpha[2])+pow(t,3)*(alpha[4]-alpha[3]);}
float B5(float t,Eigen::VectorXd alpha){return pow(1-t,5)*alpha[0]+5*pow(1-t,4)*pow(t,1)*alpha[1]+10*pow(1-t,3)*pow(t,2)*alpha[2]+10*pow(1-t,2)*pow(t,3)*alpha[3]+5*pow(1-t,1)*pow(t,4)*alpha[4]+pow(t,5)*alpha[5];}
float B5_dot(float t,Eigen::VectorXd alpha){return 5*pow(1-t,4)*(alpha[1]-alpha[0])+4*pow(1-t,3)*pow(t,1)*(alpha[2]-alpha[1])+6*pow(1-t,2)*pow(t,2)*(alpha[3]-alpha[2])+4*pow(1-t,1)*pow(t,3)*(alpha[4]-alpha[3])+pow(t,4)*(alpha[5]-alpha[4]);}
float B6(float t,Eigen::VectorXd alpha){return pow(1-t,6)*alpha[0]+6*pow(1-t,5)*pow(t,1)*alpha[1]+15*pow(1-t,4)*pow(t,2)*alpha[2]+20*pow(1-t,3)*pow(t,3)*alpha[3]+15*pow(1-t,2)*pow(t,4)*alpha[4]+6*pow(1-t,1)*pow(t,5)*alpha[5]+pow(t,6)*alpha[6];}
float B6_dot(float t,Eigen::VectorXd alpha){return 6*pow(1-t,5)*(alpha[1]-alpha[0])+5*pow(1-t,4)*pow(t,1)*(alpha[2]-alpha[1])+10*pow(1-t,3)*pow(t,2)*(alpha[3]-alpha[2])+10*pow(1-t,2)*pow(t,3)*(alpha[4]-alpha[3])+5*pow(1-t,1)*pow(t,4)*(alpha[5]-alpha[4])+pow(t,5)*(alpha[6]-alpha[5]);}
