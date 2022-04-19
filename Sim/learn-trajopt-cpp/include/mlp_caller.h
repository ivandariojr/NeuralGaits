//
// Created by ivan on 9/2/21.
//

#ifndef FULL_STACK_UNCERTAINTY_PREDICTOR_H
#define FULL_STACK_UNCERTAINTY_PREDICTOR_H

#include <vector>
#include <iostream>
#include <torch/torch.h>
#include <torch/script.h>
#include <eigen3/unsupported/Eigen/CXX11/Tensor>
#include "torch_utils.h"

using ZVector  = Eigen::Matrix<float, 2, 1, Eigen::ColMajor>;
using YDesVector  = Eigen::Matrix<float, 4, 1, Eigen::ColMajor>;
using YDesReturnVector  = Eigen::Matrix<float, 8, 1, Eigen::ColMajor>;

//using MatrixXfRow = Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>;
//using TensorXfRow = Eigen::Tensor<float, 3, Eigen::RowMajor>;

std::vector<at::Tensor> make_paramter_vector(const torch::jit::script::Module & module){
  std::vector<at::Tensor> paramlist;
  for (const auto &parameter: module.parameters()) {
    paramlist.push_back(parameter);
  }
  return paramlist;
}


template<int n_input, int n_output>
class MLPCaller {
 public:
  MLPCaller(const std::string & model_path, const torch::DeviceType device = torch::kCPU) :
  model_(torch::jit::load(model_path)),
  device_(device)
  {
    model_.to(device);
    model_.eval();
  }

  YDesReturnVector call(
    const ZVector& z,
    const ZVector& z_dot) {
//    torch::NoGradGuard no_grad;
    torch::Tensor z_tensor = eigenToTorch<n_input, 1>(z).unsqueeze(0);
    torch::Tensor z_dot_tensor = eigenToTorch<n_input, 1>(z_dot).unsqueeze(0);
    auto level = torch::autograd::forward_ad::enter_dual_level();
    auto dual_z = torch::_make_dual(z_tensor, z_dot_tensor, level);
    auto result = model_.clone(true).forward({dual_z}).toTensor().squeeze();
    auto result_dual = torch::_unpack_dual(result, level);
//    std::cout << "z_tensor.requires_grad():"  << std::endl << z_tensor.requires_grad() << std::endl;
//    std::cout << "result:"  << std::endl << result << std::endl;
//    std::cout << "z:"  << std::endl << z << std::endl;
//    std::cout << "z_dot:"  << std::endl << z_dot << std::endl;
//    std::cout << "std::get<0>(result_dual).sizes():"  << std::endl << std::get<0>(result_dual).sizes() << std::endl;
//    std::cout << "std::get<1>(result_dual).sizes():"  << std::endl << std::get<1>(result_dual).sizes() << std::endl;
    torch::autograd::forward_ad::exit_dual_level(level); // Primal, Tangent
    YDesReturnVector ydes_return;
    ydes_return << torchToEigen<n_output,1>(std::get<0>(result_dual)),
                   torchToEigen<n_output,1>(std::get<1>(result_dual));
    //return std::make_pair(
     // torchToEigen<n_output,1>(std::get<0>(result_dual)),
     // torchToEigen<n_output,1>(std::get<1>(result_dual))
     // );
     return ydes_return;
  }

  torch::jit::script::Module model_;
  torch::DeviceType device_;
};

#endif //FULL_STACK_UNCERTAINTY_PREDICTOR_H
