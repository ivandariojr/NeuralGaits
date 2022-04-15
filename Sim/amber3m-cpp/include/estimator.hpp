#ifndef ESTIMATOR_H
#define ESTIMATOR_H

#include <Eigen/Dense>

// Define Robot class to pass in as argument
class Robot;

struct Data{
    char port[1028];
    int commStatus;
    double torque[4];
    double torso;
    double torso_d;
    double pos[4];
    double vel[4];
    double inputs[4];
    double status[4];
};

#define actuator_conversion_factor 2*M_PI/8192.0/91.4285714286 // 2*PI*ticks/res_of_encoder/GEAR_RATIO
#define gear_ratio 91.4285714286
#define torso_conversion_factor 2*M_PI/8192.0/3 // 2*PI*ticks/res_of_encoder/GEAR_RATIO

/** An abstract class for estimators */
class Estimator {
	public:
	  virtual ~Estimator() {}
	  virtual Eigen::VectorXd getState(Robot *r) = 0;
	  // virtual Eigen::VectorXd getActuatedState(Robot *r) = 0;
	  virtual void getEstimatorType(std::string *a) = 0;
    struct Data *data;
};

/** A class that returns fake data while not connected to the robot */
class Dummy: public Estimator {
  public:
    Eigen::VectorXd getState(Robot *r);
    // Eigen::VectorXd getActuatedState(Robot *r);
    void getEstimatorType(std::string *a);
};

/** A class that returns the data from the RaiSim environment. */
class RaiSim: public Estimator {
  public:
    int sock;
    RaiSim(int sock);
    Eigen::VectorXd getState(Robot *r);
    // Eigen::VectorXd getActuatedState(Robot *r);
    void getEstimatorType(std::string *a);
};

Eigen::VectorXd getActState(Eigen::VectorXd state);

#endif
