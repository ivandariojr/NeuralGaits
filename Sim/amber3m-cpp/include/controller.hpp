#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Eigen/Dense>
#include <vector>
#include "trajectory.hpp"
#include "osqp.h"
#include "OsqpEigen/OsqpEigen.h"

// Define Robot class to pass in as argument
class Robot;

enum Mode {timeBased, stateBased};

/** An abstract class for controllers */
class Controller {
	public:
		virtual ~Controller() {}
		virtual Eigen::VectorXd getControl(Robot *r, float time, Eigen::VectorXd actualState, Eigen::VectorXd desState) = 0;
		void setMode(Mode m);
		float epsilon;
		float gamma;
		float regulator;
		Eigen::MatrixXd P_e;
	protected:
		Mode mode;
};

// PD Controller
class PD: public Controller {
	public:
		PD(float Kp, float Kd);
		Eigen::VectorXd getControl(Robot *r, float time, Eigen::VectorXd actualState, Eigen::VectorXd desState);
		void setGains(float Kp, float Kd);
	protected: 
		float Kp; 
		float Kd;
};

#endif

