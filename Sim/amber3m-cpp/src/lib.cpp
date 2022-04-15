/** \file */
#include <fstream>
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <vector>
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include "../include/lib.hpp"
#include "../include/robotParams.hpp"
#include "../include/trajectory.hpp"
#include "../include/estimator.hpp"
#include <stdlib.h> 
#include <unistd.h> 
#include <stdio.h> 


#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
//#define INCLUDE_DIR include_hardware
#define INCLUDE_DIR include_sim

#define stringify(x) #x
#define FILE(a, b) stringify(../a/codegen/lib/b/b.h)

extern "C" {
#include FILE(INCLUDE_DIR, C_matrix)
#include FILE(INCLUDE_DIR, D_matrix)
#include FILE(INCLUDE_DIR, dz_2)
}
#include "../include/vars.h"

using namespace Eigen;
using namespace std;

double xmin;
//extern VectorXd foot_pos_last;
extern VectorXd q_last;
extern VectorXd dq_last;
VectorXd p_min;
extern VectorXd q0_v;
double tau_strike;
extern MatrixXd c;

extern double currentStoneDist;

const int BezOrder = 4;


void init() {
		stance = 1; // Hardware starts in stance = 1 (right, and switches immediately)
		stance_last = 0; // To ensure stance switching logic is triggered at start
		maxTorque = VectorXd(4);
		zeros = VectorXd(4);
		maxTorque << MAXTORQUE,MAXTORQUE,MAXTORQUE,MAXTORQUE;
		zeros << 0,0,0,0;

		c = MatrixXd(4,3);
}

bool solveRiccatiIterationC(const Eigen::MatrixXd &A, const Eigen::MatrixXd &B,
                            const Eigen::MatrixXd &Q, const Eigen::MatrixXd &R,
                            Eigen::MatrixXd &P, const double dt,
                            const double &tolerance,
                            const uint iter_max) {
  P = Q; // initialize

  Eigen::MatrixXd P_next;

  Eigen::MatrixXd AT = A.transpose();
  Eigen::MatrixXd BT = B.transpose();
  Eigen::MatrixXd Rinv = R.inverse();

  double diff;
  for (uint i = 0; i < iter_max; ++i) {
    P_next = P + (P * A + AT * P - P * B * Rinv * BT * P + Q) * dt;
    diff = fabs((P_next - P).maxCoeff());
    P = P_next;
    if (diff < tolerance) {
      std::cout << "iteration mumber = " << i << std::endl;
      return true;
    }
  }
  return false; // over iteration limit
}

void setupSimSocket(int* server_fd, int* new_socket, int opt, int addrlen, struct sockaddr_in *address) {
			// Creating socket file descriptor 
    if ((*server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(*server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address->sin_family = AF_INET; 
    address->sin_addr.s_addr = INADDR_ANY; 
    address->sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(*server_fd, (struct sockaddr *)address,  
                                 sizeof(*address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(*server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((*new_socket = accept(*server_fd, (struct sockaddr *)address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
}

/** Convert an Eigen::VectorXd to a string.
* This is useful for when trying to file write the state of the robot,
* but I have noticed this cause a slowdown of the system. A better solution
* should be found in the future
*/
string tthetampstring(VectorXd mat){
    stringstream ss;
    ss << mat.transpose();
    return ss.str();
}

/** Function called on Ctrl-c to handle file closing properly */
void exitMain(ofstream *fileHandle) {
	fileHandle->close();
	exit(2);
}

/** SIGINT callback. File changes the programState to "Exit" status, 
* calling exitMain().
*/
void signal_callback_handler(int signum) {
   cout << "Caught signal " << signum << ", starting exit procedure." << endl;
   progState = Exit;
}


/** Convert a vector of vectors to an eigen Matrix */
MatrixXd ConvertToEigenMatrix(std::vector<std::vector<double>> data)
{
    MatrixXd eMatrix(data.size(), data[0].size());
    for (int i = 0; i < data.size(); ++i)
        eMatrix.row(i) = VectorXd::Map(&data[i][0], data[0].size());
    return eMatrix;
}

/** Convert a n array of double arrays to an eigen Matrix */
MatrixXd ConvertToEigenMatrix(const double* M, int rows, int cols)
{
    MatrixXd eMatrix(rows, cols);
    for (int i = 0; i < cols; i++)
    	for (int j = 0; j < rows; j++)
    		eMatrix(j,i) = M[i*rows+j];
    return eMatrix;
}

/** Convert a n array of double arrays to an eigen Matrix */
VectorXd ConvertToEigenVector(const double* M, int rows)
{
    VectorXd eVector(rows);
    	for (int j = 0; j < rows; j++)
    		eVector(j) = M[j];
    return eVector;
}

/** Convert a vector of vectors to an eigen Vector */
VectorXd ConvertToEigenVector(std::vector<double> data)
{
    VectorXd eVector(data.size());
    for (int i = 0; i < data.size(); ++i)
        eVector(i) = data[i];
    return eVector;
}


// Linearized hip position
double getPhip(VectorXd xa, double Tor)
{
	return (LC + LT)*(-Tor + xa(SH)) + LC*xa(SK);
}

// Linearized hip velocity
double getVhip(VectorXd xa, double TorD)
{
	return (LC + LT)*(-TorD + xa(SH+NDOF)) + LC*xa(SK+NDOF);
}

VectorXd Noel2Min(VectorXd vec) {
	VectorXd vec_reorg(vec.size());
	if (vec.size() == 5) {
		vec_reorg << vec(0) - vec(1) - vec(2), vec(1), vec(2), vec(3), vec(4);
	} else if (vec.size() == 10) {
		vec_reorg << vec(0) - vec(1) - vec(2), vec(1), vec(2), vec(3), vec(4),
								 vec(5) - vec(6) - vec(7), vec(6), vec(7), vec(8), vec(9);
	} else {
		std::cout << "WRONG SIZE" <<std::endl;
		vec_reorg = vec; // Exit instead in the future
	}
	return vec_reorg;
}

VectorXd Min2Noel(VectorXd vec) {
    VectorXd vec_reorg(vec.size());
    if (vec.size() == 5) {
        vec_reorg << vec(0) + vec(1) + vec(2), vec(1), vec(2), vec(3), vec(4);
    } else if (vec.size() == 10) {
        vec_reorg << vec(0) + vec(1) + vec(2), vec(1), vec(2), vec(3), vec(4),
                vec(5) + vec(6) + vec(7), vec(6), vec(7), vec(8), vec(9);
    } else {
        std::cout << "WRONG SIZE" <<std::endl;
        vec_reorg = vec; // Exit instead in the future
    }
    return vec_reorg;
}

MatrixXd D(VectorXd q) {
	double q_[5];
	Map<VectorXd>(&q_[0], 5) = Noel2Min(q);
	double D_[25];
	D_matrix(q_, D_);
	MatrixXd D(5,5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			D(i,j) = D_[i*5+j];
		}
	}
	return D;
}

double dz(VectorXd q) {
    double q_[5];
    Map<VectorXd>(&q_[0], 5) = Noel2Min(q);
    return dz_2(q_);
}


#pragma clang diagnostic pop
