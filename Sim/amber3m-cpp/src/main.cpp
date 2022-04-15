#include <fstream>
#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <signal.h>
#include <Eigen/Dense>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include "../include/estimator.hpp"
#include "../include/controller.hpp"
#include "../include/robot.hpp"
#include "../include/timer.hpp"
#include "../include/trajectory.hpp"
#include "../include/robotParams.hpp"
#include "../include/lib.hpp"
#include "yaml-cpp/yaml.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
#define EXTERN

#include "../include/vars.h"

using namespace Eigen;
using namespace std;

#define ParamPort 8080

// Global Variables
pthread_t thread1, thread2, thread3;

bool switchBack;
    
int main(int argc, char **argv) {
    string YAMLfile = "../src/trajectoryParams.yaml";
    YAML::Node config = YAML::LoadFile(YAMLfile);
    string NeuralGaits = config["NeuralGaitLocation"].as<string>();
    YAML::Node NGconfig = YAML::LoadFile(NeuralGaits);
    string dataLog = config["dataLog"].as<string>();

    if (argc > 1) {
        dataLog = argv[1];
    }
	progState = Running;

	bool fileWrite = true;
	VectorXd state_tmp;

	// Define variables
	Timer timer;
	VectorXd state(8);
	VectorXd fullState(10);
	VectorXd desState;
	VectorXd torque;
	double torso_offset = 0;
	float t;
	float t_last;
	ofstream fileHandle; /**<- data logging*/
	const static IOFormat CSVFormat(StreamPrecision, DontAlignCols, ", ", "\n");
	float *tau = new float;
	tau_d = new float;
	tau_a = new float;

	*tau = 0;
	*tau_d = 0;
	*tau_a = 0;

	// Read data from YAML file (so that values can be changed without recompiling)
	vector<vector<double>> a = config["a"].as<vector<vector<double>>>();
	MatrixXd u_F = ConvertToEigenMatrix(config["u"].as<vector<vector<double>>>());
	vector<double> q0 = config["q0"].as<vector<double>>();
	q0_v = VectorXd(4);
	q0_v = ConvertToEigenVector(q0);
    double P, D;
        P = config["Sim_P"].as<double>();
        D = config["Sim_D"].as<double>();
    float z1_0 = NGconfig["z1_0"].as<float>();
    float z2_0 = NGconfig["z2_0"].as<float>();
    float dz1_0 = NGconfig["dz1_0"].as<float>();
    float dz2_0 = NGconfig["dz2_0"].as<float>();
    string Trial = std::to_string(config["Trial"].as<int>());
    string Iter = std::to_string(config["Iter"].as<int>());
	TMAX = config["TMAX"].as<double>();
	TAUMAX = config["TAUMAX"].as<double>();
	VHIP0 = config["VHIP0"].as<double>();
	PHIP0 = NGconfig["PHIP0"].as<double>();
	PHIPF = NGconfig["PHIPF"].as<double>();
	Torso0 = NGconfig["Torso0"].as<double>();

	init();

	// Socket stuff
	int* server_fd = new int;
	int* new_socket = new int;
	int valread;
  struct sockaddr_in *address = new sockaddr_in;
  int opt = 1;
  int addrlen = sizeof(*address);
  char buffer[1024] = {0};
  double TX_torque[4] = {0, 0, 0, 0};
  double RX_state[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  	setupSimSocket(server_fd, new_socket, opt, addrlen, address);

	// Define robot
	AMBERPointFoot amber;
	Controller *mainController = new PD(P,D);

	// Controller for initialization
	amber.setController(new PD(P,D));
	amber.controller->setMode(timeBased);

		amber.setEstimator(new RaiSim(*new_socket));

//    MLP traj = MLP("/home/noel/learn_trajoptss/AMBER/run_data/Trial" + Trial + "/mlp" + Iter + ".thc");
    MLP traj = MLP("/home/noel/learn_trajopt/AMBER/run_data/wandb_saves/model.thc");
//    MLP traj = MLP("/home/noel/learn_trajopt/AMBER/models/distilled9999.thc");
    ZVector z_0(2);
    ZVector dz_0(2);
    z_0 << z1_0, z2_0;
    dz_0 << dz1_0, dz2_0;

    q0_v = traj.MLP::evalMLPZDCoord(z_0, dz_0);
//    q0_v.head(4).reverseInPlace();
    std::cout << "Torso0: " << Torso0 << std::endl;
    std::cout << "q0_v: " << q0_v << std::endl;
    Eigen::VectorXd theta_0(5);
    theta_0 << Torso0 - q0_v(0) - q0_v(1), q0_v.head(4);
    VectorXd c(5);
    c << -0.873, -0.4604, 0, 0, 0;
    std::cout << "z_0: " << c.transpose()*theta_0 << std::endl;

    // IC
	MatrixXd alpha(1,4);
	alpha << q0_v[0], q0_v[1], q0_v[2], q0_v[3];
	Constant initTraj = Constant(alpha);

	// Set up Data logging
	fileHandle.open(dataLog);
	fileHandle << "t,tau,switchBack,tau_d,tau_a,stance,a_state_1,a_state_2,a_state_3,a_state_4,a_state_5,a_state_6,a_state_7,a_state_8,a_state_9,a_state_10";
	fileHandle << "d_state_1,d_state_2,d_state_3,d_state_4,d_state_5,d_state_6,d_state_7,d_state_8,";
	fileHandle << "d_torque_1,d_torque_2,d_torque_3,d_torque_4" << endl;

	// Set callback for kill (to close file)
	signal(SIGINT, signal_callback_handler);

	bool softStart = true;
	float initializingDuration; // in ms
	float initializingDuration2; // in ms
		initializingDuration = 0; // in ms
		initializingDuration2 = 0; // in ms

	progState = Initializing;
	timer.start();

	// Send initial state (improper use of TX_torque...)
		for (int i = 0; i < 4; i ++)
			TX_torque[i] = q0_v[i];
		state_tmp = amber.getState();
		t = state_tmp(10);
		t_last = t;
		send(*new_socket , &TX_torque , sizeof(TX_torque) , 0);

	while(1) {
		// Update relevant information
			state_tmp = amber.getState();
			t = state_tmp(10);
			fullState = state_tmp.segment(0,10);
			state = amber.getActuatedState(fullState);
		*tau += t-t_last;


		if (progState == Initializing && t > initializingDuration2) {
			progState = Running;
			torso_offset = fullState(0)-Torso0;
			std::cout << "Walking" << std::endl;
			amber.setController(mainController);
		}

		fullState(0) -= torso_offset;

		if (progState == Initializing)
			desState = initTraj.getDesiredState();
		else
			desState = traj.getDesiredState(&amber, tau, tau_d, tau_a, fullState);

			torque = amber.getControl(timer.elapsedSeconds(), fullState, desState);

		if (softStart) {
			if (t < initializingDuration) {
				torque = (1-cos(M_PI/2*t/initializingDuration))*torque; // change this to a smooth (pos&vel) kernel at some point
			}
		}


		// Saturate torque values
//			torque = torque.cwiseMin(maxTorque);
//			torque = torque.cwiseMax(-maxTorque);

		/* protection */
		if ( (state[SK]  > KNEEMAX && torque[SK]  > 0)|| (state[SK]  < KNEEMIN && torque[SK]  < 0) )	torque[SK]  = 0;
		if ( (state[NSK] > KNEEMAX && torque[NSK] > 0)|| (state[NSK] < KNEEMIN && torque[NSK] < 0) ) 	torque[NSK] = 0;
		if ( (state[SH]  > HIPMAX && torque[SH]   > 0)|| (state[SH]  < HIPMIN && torque[SH]   < 0) ) 	torque[SH]  = 0;
		if ( (state[NSH]  > HIPMAX && torque[NSH] > 0)|| (state[SH]  < HIPMIN && torque[NSH]  < 0) ) 	torque[NSH] = 0;

		if (desState[0] > KNEEMAX || desState[3] > KNEEMAX || desState[0] < KNEEMIN || desState[3] < KNEEMIN ||
			desState[1] > HIPMAX || desState[2] > HIPMAX || desState[1] < HIPMIN || desState[2] < HIPMIN) {
			std::cout << "Something wrong with desired trajectory, it is outside of range of motion. Exiting." <<std::endl;
			progState = Exit;
		}
		if (desState[4] > 100 || desState[7] > 100 || desState[4] < -100 || desState[7] < -100 ||
			desState[5] > 100 || desState[6] > 100 || desState[5] < -100 || desState[6] < -100) {
			std::cout << "Something wrong with desired trajectory, it is outside of range of motion. Exiting." <<std::endl;
			progState = Exit;
		}

		// Command Torques
        for (int i = 0; i < 4; i ++)
            TX_torque[i] = torque(i);
        send(*new_socket , &TX_torque , sizeof(TX_torque) , 0);

		// Log info
		if (fileWrite) {
			fileHandle << t << ",";
			fileHandle << *tau << ",";
			fileHandle << switchBack << ",";
			fileHandle << *tau_d << ",";
			fileHandle << *tau_a << ",";
			fileHandle << stance << ",";
			fileHandle << fullState.transpose().format(CSVFormat) << ",";
			fileHandle << desState.transpose().format(CSVFormat) << ",";
			fileHandle << torque.transpose().format(CSVFormat) << endl;
		}
		// Catch kill command and close file first
		if (progState == Exit) exitMain(&fileHandle);

		t_last = t;
	}
};

#pragma clang diagnostic pop
