#ifndef TRAJECTORY_H
#define TRAJECTORY_H

#include "lib.hpp"
#include "Bezier.hpp"
#include <Eigen/Dense>
#include "mlp_caller.h"

enum TrajType {Periodic, Aperiodic};

class Robot;

class Trajectory {
	public:
		virtual ~Trajectory() {}
		// virtual Eigen::VectorXd getDesiredState(Robot *r, float t) = 0;
		// virtual Eigen::VectorXd getDesiredPos(Robot *r, float t) = 0;
		// virtual Eigen::VectorXd getDesiredVel(Robot *r, float t) = 0;
		TrajType type;
		int size;
		bool stateBased;
};

class MLP: public Trajectory {
    public:
        MLP(const std::string& filepath);
        Eigen::VectorXd getDesiredState(Robot *r, float *t, float *tau_d, float* tau_a, Eigen::VectorXd fullState);
        Eigen::VectorXd getDesiredPos(Robot *r, float *t, float *tau_d, float* tau_a, Eigen::VectorXd fullState);
        Eigen::VectorXd getDesiredVel(Robot *r, float *t, float *tau_d, float* tau_a, Eigen::VectorXd fullState);
        Eigen::VectorXd evalMLPZDCoord(ZVector z, ZVector z_dot);
        Eigen::VectorXd evalMLP(Eigen::VectorXd fullState);
    private:
        MLPCaller<2,4> caller;
};

class Constant: public Trajectory {
	public:
		Constant(Eigen::MatrixXd alpha);
		Constant() {};
		Eigen::MatrixXd alpha;
		Eigen::VectorXd getDesiredState();
		Eigen::VectorXd getDesiredPos();
		Eigen::VectorXd getDesiredVel();
};

#endif