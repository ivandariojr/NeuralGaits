#include <iostream>
#include <Eigen/Dense>
#include <stdexcept>
#include <string>
#include "../include/estimator.hpp"
#include "../include/controller.hpp"
#include "../include/robot.hpp"
#include "../include/lib.hpp"
#include <pthread.h>
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <stdio.h> 

using namespace Eigen;
using namespace std;

VectorXd Dummy::getState(Robot *r) {
  VectorXd state(2*r->getNumStates());
  state = VectorXd::LinSpaced(10,0,1);
  return state;
};	

void Dummy::getEstimatorType(std::string *a) {
  *a = "Dummy";
};

RaiSim::RaiSim(int sock) {
  this->sock = sock;
}

VectorXd RaiSim::getState(Robot *r) {
  VectorXd state(11);
  double raisimState[11] = {0,0,0,0,0,0,0,0,0,0,0};
  int valread = read(sock, &raisimState, sizeof(raisimState)); 
  for (int i=0; i < 11; i++) {
    state(i) = raisimState[i];
  }
  return state;
};  

void RaiSim::getEstimatorType(std::string *a) {
  *a = "RaiSim";
};

VectorXd getActState(VectorXd state) {
  VectorXd a_state(8);
  a_state << state.segment(1,4),state.segment(6,4);
  return a_state;
}