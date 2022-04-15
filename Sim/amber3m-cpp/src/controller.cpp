/** \file */
#include <iostream>
#include <Eigen/Dense>
#include <vector>
#include "../include/estimator.hpp"
#include "../include/controller.hpp"
#include "../include/robot.hpp"
#include "../include/lib.hpp"
#include "../include/trajectory.hpp"

#include "../include/vars.h"

using namespace Eigen;
using namespace std;

#define CurrentToTau 23.13

extern bool stance;

extern Vector4d u_des;
extern MatrixXd Bez;

extern double V_;
extern double LfV_;
extern VectorXd LgV_;

extern double xmin;

extern float* tau_d;

void Controller::setMode(Mode m) {
	this->mode = m;
}

PD::PD(float Kp, float Kd) {
  setGains(Kp, Kd);
};

VectorXd PD::getControl(Robot *r, float time, VectorXd actualState, VectorXd desiredState) {
VectorXd q(5);
	VectorXd dq(5);
	VectorXd x(10);
	q = actualState.head(5);
	dq = actualState.tail(5);

	if(stance == 1)//when right foot is stance
	{	
		q.segment(1,4).reverseInPlace();
		dq.segment(1,4).reverseInPlace();
		desiredState.segment(0,4).reverseInPlace();
		desiredState.segment(4,4).reverseInPlace();
	}

//	foot_pos = Foot_Pos(q);
//	hip_pos = Hip_Pos(q);

	VectorXd error(8);
	error << q.segment(1,4)-desiredState.segment(0,4), dq.segment(1,4) - desiredState.segment(4,4);

//	foot_pos = Foot_Pos(q);
//	hip_pos = Hip_Pos(q);

	VectorXd u(4);
	u = CurrentToTau*(error.segment(0,4)*Kp + error.segment(4,4)*Kd);
	if (stance == 1)
		u.reverseInPlace();

	return u;	
};	

void PD::setGains(float Kp, float Kd) {
	this->Kp = Kp;
	this->Kd = Kd;
}
