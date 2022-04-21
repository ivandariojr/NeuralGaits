#ifndef LIB_H
#define LIB_H

#include <Eigen/Dense>
#include <Eigen/Core>
#include <vector>

#define PORT 8081

enum programState {Running, Exit, Initializing};
class Robot;
class Trajectory;

void init();
/* https://github.com/TakaHoribe/Riccati_Solver */
bool solveRiccatiIterationC(const Eigen::MatrixXd &A, const Eigen::MatrixXd &B,
                            const Eigen::MatrixXd &Q, const Eigen::MatrixXd &R,
                            Eigen::MatrixXd &P, const double dt = 0.001,
                            const double &tolerance = 1.E-20,
                            const uint iter_max = 100000);
void setupSimSocket(int* server_fd, int* new_socket, int opt, int addrlen, struct sockaddr_in *address);
std::string to_string(Eigen::VectorXd mat);
void exitMain(std::ofstream *fileHandle);
void signal_callback_handler(int signum);
void writeData(auto fileHandle, std::vector<uint64_t> data);
Eigen::MatrixXd ConvertToEigenMatrix(std::vector<std::vector<double>> data);
Eigen::MatrixXd ConvertToEigenMatrix(const double* M, int rows, int cols);
Eigen::VectorXd ConvertToEigenVector(std::vector<double> data);
Eigen::VectorXd ConvertToEigenVector(const double* M, int rows);
double getPhip(Eigen::VectorXd xa, double Tor);
double getVhip(Eigen::VectorXd xa, double TorD);

// Model Based Control
Eigen::VectorXd Noel2Min(Eigen::VectorXd vec);
Eigen::VectorXd Min2Noel(Eigen::VectorXd vec);
Eigen::MatrixXd D(Eigen::VectorXd q);
double dz(Eigen::VectorXd  q);


#endif