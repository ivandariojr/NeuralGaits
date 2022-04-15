/** \file */
#include <iostream>
#include <Eigen/Dense>
#include <string>
#include <vector>
#include "../include/estimator.hpp"
#include "../include/controller.hpp"
#include "../include/robot.hpp"

using namespace Eigen;
using namespace std;

void Robot::setTorque(VectorXd torque) {
  for (int i = 0; i < torque.size(); i++)
    this->estimator->data->torque[i] = torque(i);
}

void Robot::setNumActuators(int a) {
	numActuators = a;
  for (int i = 0; i < a; i++) {
	cout << "Added actuator " << i << endl;
  }
};

int Robot::getNumActuators() {
	return numActuators;
};

void Robot::setActuatedIndeces(ArrayXi ind) {
  this->actuatedIndeces = ind;
}

ArrayXi Robot::getActuatedIndeces() {
  return this->actuatedIndeces;
}

void Robot::setNumStates(int s) {
	numStates = s;
  for (int i = 0; i < s; i++) {
	cout << "Added state " << i << endl;
  }
};

int Robot::getNumStates() {
	return numStates;
};

void Robot::setController(Controller* controller) {
  this->controller = controller;
};

VectorXd Robot::getControl(float time, VectorXd actualState, VectorXd desiredState) {
  return controller->getControl(this, time, actualState, desiredState);
};

void Robot::setEstimator(Estimator* estimator) {
  this->estimator = estimator;
};

VectorXd Robot::getState() {
  return estimator->getState(this);
};

/** Gets the actuates states
* as indexed by the actuatedIndeces property
* @return the actuates states
*/
VectorXd Robot::getActuatedState(VectorXd state) {
  return getActState(state);
};

void Robot::getEstimatorType(std::string *s) {
  estimator->getEstimatorType(s);
}

AMBERPointFoot::AMBERPointFoot(void) {
  setNumActuators(4);
  setNumStates(6);
  ArrayXi actuatorIndeces(4);
  actuatorIndeces << 1,2,3,4;
  setActuatedIndeces(actuatorIndeces);
};

AMBERWithFeet::AMBERWithFeet(void) {
  setNumActuators(6);
  setNumStates(7);
  ArrayXi actuatorIndeces(6);
  actuatorIndeces << 0,1,2,3,4,5;
  setActuatedIndeces(actuatorIndeces);
};


