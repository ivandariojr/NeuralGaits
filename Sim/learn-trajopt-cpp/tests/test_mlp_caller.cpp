//
// Created by ivan on 9/2/21.
//

#include <iostream>
#include <gtest/gtest.h>
#include <eigen3/Eigen/Dense>
#include <memory>
#include "mlp_caller.h"
#include <chrono>




MLPCaller<2,4> caller("data/sample.th");


TEST(test_uncertainty_predictor, test_call) {

  typedef std::chrono::high_resolution_clock Clock;
  typedef std::chrono::milliseconds milliseconds;

  Clock::time_point t0 = Clock::now();
  Clock::time_point t1 = Clock::now();

  ZVector z = ZVector::Random();
  ZVector z_dot = ZVector::Random();

  YDesReturnVector network_output = caller.call(z, z_dot);

  while(1) {
    t0 = Clock::now();
    network_output = caller.call(z, z_dot);

    //std::cout << "I Build." << std::endl;
    //std::cout << "yd:" << network_output.head(4) << std::endl;
    //std::cout << "yd_dot:" << network_output.tail(4) << std::endl;
    t1 = Clock::now();
    std::cout << "dt: " << std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count() << std::endl;
  }
}