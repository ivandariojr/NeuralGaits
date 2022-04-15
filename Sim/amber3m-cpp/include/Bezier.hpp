#ifndef BEZIER_H
#define BEZIER_H
#include<Eigen/Dense>

using void_f1_ptr = float (*)(float, Eigen::VectorXd);void_f1_ptr genBezier(int size, void_f1_ptr fp);
void_f1_ptr genBezierDot(int size,void_f1_ptr fp);

float B2(float t, Eigen::VectorXd alpha);
float B2_dot(float t,Eigen::VectorXd alpha);
float B3(float t, Eigen::VectorXd alpha);
float B3_dot(float t,Eigen::VectorXd alpha);
float B4(float t, Eigen::VectorXd alpha);
float B4_dot(float t,Eigen::VectorXd alpha);
float B5(float t, Eigen::VectorXd alpha);
float B5_dot(float t,Eigen::VectorXd alpha);
float B6(float t, Eigen::VectorXd alpha);
float B6_dot(float t,Eigen::VectorXd alpha);
#endif