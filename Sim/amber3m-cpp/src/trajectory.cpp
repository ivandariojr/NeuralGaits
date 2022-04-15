/** \file */
#include <iostream>
#include <Eigen/Dense>
#include "../include/lib.hpp"
#include "../include/trajectory.hpp"
#include "../include/Bezier.hpp"
#include "../include/robotParams.hpp"

#include "../include/vars.h"

using namespace Eigen;
using namespace std;

extern double tau_strike;

extern bool stance;
MatrixXd c;

extern double xmin;

Constant::Constant(MatrixXd alpha) {
	this->alpha = alpha;
	this->size = 4;
};

VectorXd Constant::getDesiredPos() {
	VectorXd tmp(this->size);
	for (int i = 0; i < this->size; i ++) {
		tmp(i) = alpha(i);
	}
	return tmp;
};

VectorXd Constant::getDesiredVel() {
	VectorXd tmp(this->size);
	for (int i = 0; i < this->size; i ++) {
		tmp(i) = 0;
	}
	return tmp;
};

VectorXd Constant::getDesiredState() {
	VectorXd pos(this->size);
	VectorXd vel(this->size);
	VectorXd state(this->size*2);

	pos = getDesiredPos();
	vel = getDesiredVel();
	state << pos, vel;
	return state;
};

MLP::MLP(const std::string& filepath) : caller(filepath) {
}

Eigen::VectorXd MLP::getDesiredState(Robot *r, float *t, float *tau_d, float* tau_a, Eigen::VectorXd fullState) {
    if (*tau_a >= TAUMAX) {
        stance = (stance == 0)? 1 : 0;
        *tau_a=0;
    }

    VectorXd q(5), dq(5);
    q << fullState.segment(0,5);
    dq << fullState.segment(5,5);

    if (stance == 1) {
        q.segment(1, 4).reverseInPlace();
        dq.segment(1, 4).reverseInPlace();
    }

    VectorXd y2d(NRD2);
    VectorXd y2dDot(NRD2);
    VectorXd z(2);
    VectorXd desState(8);
    VectorXd state(10);
    double torso;
    double torsthetampd;
    double phip, vhip;
    double switchBack;

    // initial hip position & velocity
    double phip0, vhip0;
    phip0 = PHIP0;
    vhip0 = VHIP0;

    state << fullState;
    torso = fullState(0);
    torsthetampd = fullState(5);

    // start the controller ...
//    static int nTau_d_increment;
    static double tau_d_prev, tau_a_prev;

    //  switch to Stance & nonStance -- needed for state based control, but only in PHZD
        if(stance == 1)//when right foot is stance
        {
            state.segment(1,4).reverseInPlace();
            state.segment(6,4).reverseInPlace();
            switchBack = true;
        } else {
            switchBack = false;
        }

        // Current linearized hip position & velocity
        phip = getPhip(state.segment(1,4), torso);
        vhip = getVhip(state.segment(2,8), torsthetampd);
        if(vhip >  VHIP0*1.4)  vhip =  VHIP0*1.4;
        if(vhip < -VHIP0*0.9)  vhip = -VHIP0*0.9;

        // actual tau
        *tau_a = ( phip - phip0 ) / (PHIPF - PHIP0);
        tau_a_prev = *tau_a;

    // desired tau
        *tau_d = *tau_a;
    /* Saturate tau_d. */
    *tau_d = (*tau_d > TAUMAX) ? TAUMAX : *tau_d;
    *tau_d = (*tau_d < 0) ? 0 : *tau_d;

    desState = evalMLP(state);

    // switch back to Left & Right
    if (switchBack) {
        state.segment(1,4).reverseInPlace();
        state.segment(6,4).reverseInPlace();
    }

    if(stance == 1) //right is stance
    {
        desState.head(4).reverseInPlace();
        desState.tail(4).reverseInPlace();
    }

    return desState;
};

Eigen::VectorXd MLP::evalMLP(Eigen::VectorXd fullState) {
    VectorXd q(5);
    VectorXd dq(5);
    fullState = Noel2Min(fullState);
    q = fullState.segment(0,5);
    dq = fullState.segment(5,5);

    VectorXd c(5);
    VectorXd N(5);
    MatrixXd D_mat(5,5);
    D_mat = D(q);
    double dz_2 = -dz(q);

    c << -0.873, -0.4604, 0, 0, 0;
    N << 1, 0, 0, 0, 0;
    ZVector z;
    z << (c.transpose()*q).cast<float>(), (N.transpose()*D_mat*dq).cast<float>();
    ZVector z_dot;
    z_dot << (c.transpose()*dq).cast<float>(), (float) dz_2;
    z(1) = 0;
    z_dot(1) = 0;

    if (z(0) < PHIP0) {
        z(0) = PHIP0;
    } else if(z(0) > PHIPF) {
        z(0) = PHIPF;
    }

    VectorXd ydes_return(8);
    ydes_return = this->evalMLPZDCoord(z, z_dot);
    return ydes_return;
}

Eigen::VectorXd MLP::evalMLPZDCoord(ZVector z, ZVector z_dot) {
    YDesReturnVector ydes = caller.call(z, z_dot);
    VectorXd ydes_return(8);
    ydes_return << double(ydes(0)),
            double(ydes(1)),
            double(ydes(2)),
            double(ydes(3)),
            double(ydes(4)),
            double(ydes(5)),
            double(ydes(6)),
            double(ydes(7));
    return ydes_return;
}

VectorXd MLP::getDesiredPos(Robot *r, float *t, float *tau_d, float* tau_a, Eigen::VectorXd fullState) {
    VectorXd state = getDesiredState(r, t, tau_d, tau_a, fullState);
    return state.head(4);
};

VectorXd MLP::getDesiredVel(Robot *r, float *t, float *tau_d, float* tau_a, Eigen::VectorXd fullState) {
    VectorXd state = getDesiredState(r, t, tau_d, tau_a, fullState);
    return state.tail(4);
};