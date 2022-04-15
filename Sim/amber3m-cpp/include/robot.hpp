#ifndef ROBOT_H
#define ROBOT_H

#include <Eigen/Dense>
#include <vector>

/** An abstract class for robots */
class Robot {
	public:
    void setTorque(Eigen::VectorXd torque);
	void setNumActuators(int a);
	int getNumActuators();
    void setActuatedIndeces(Eigen::ArrayXi ind);
    Eigen::ArrayXi getActuatedIndeces();

    void setNumStates(int s);
	int getNumStates();

    void setController(Controller* controller);
    Eigen::VectorXd getControl(float time, Eigen::VectorXd actualState, Eigen::VectorXd desiredState);

    void setEstimator(Estimator* estimator);
    Eigen::VectorXd getState();
    Eigen::VectorXd getActuatedState(Eigen::VectorXd state);
    void getEstimatorType(std::string *s);
		
	// protected:
	int numActuators;
    int numStates;
    Eigen::ArrayXi actuatedIndeces;
	// Instantiate temporary variables to not have empty pointers
    PD c = PD(0,0);
    Dummy e = Dummy();
    Controller* controller = &c;
	Estimator* estimator = &e;
};

/** A class for the point foot configuration of AMBER3M */
class AMBERPointFoot: public Robot {
  public:
    AMBERPointFoot(void);
};

/** A class for the actuated foot configuration of AMBER3M */
class AMBERWithFeet: public Robot {
  public:
    AMBERWithFeet(void);
};

#endif
