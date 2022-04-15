#ifndef EXTERN
#define EXTERN extern
#endif

#include <Eigen/Dense>

using namespace Eigen;

EXTERN programState progState;
EXTERN double TMAX, TAUMAX, VHIP0, PHIP0, PHIPF, Torso0;
EXTERN bool stance, stance_last;
EXTERN VectorXd maxTorque;
EXTERN VectorXd zeros;
// EXTERN double tau_min;

// Stepping stone variables
//EXTERN VectorXd foot_pos;
//EXTERN VectorXd hip_pos;

EXTERN VectorXd q0_v;
EXTERN Vector4d u_des;
EXTERN float* tau_a;
EXTERN float* tau_d;