//
// Created by ivan on 8/29/21.
//

#ifndef FULL_STACK_TORCH_UTILS_H
#define FULL_STACK_TORCH_UTILS_H

#include <Eigen/Dense>
#include <torch/torch.h>
#include <eigen3/unsupported/Eigen/CXX11/Tensor>

constexpr Eigen::StorageOptions VecIsColMajor(int m){
  if (m==1){
    return Eigen::ColMajor;
  } else {
    return Eigen::RowMajor;
  }
}
template <int n, int m>
using MatColFix = Eigen::Matrix<float, n, m, VecIsColMajor(m)>;

template<int ... ns>
Eigen::TensorMap< const Eigen::TensorFixedSize<float, Eigen::Sizes<ns...>, Eigen::RowMajor>> torchToEigenTensor(const torch::Tensor &tensor){
  using RetType = const Eigen::TensorFixedSize<float, Eigen::Sizes<ns...>, Eigen::RowMajor>;
  return Eigen::TensorMap<RetType>(tensor.data_ptr<float>(), Eigen::Sizes<ns...>());
}

template<int ... ns>
Eigen::TensorMap< const Eigen::Tensor<float, sizeof...(ns), Eigen::RowMajor>> torchToDynEigenTensor(const torch::Tensor &tensor){
  using RetType = const Eigen::Tensor<float, sizeof...(ns), Eigen::RowMajor>;
  return Eigen::TensorMap<RetType>(tensor.data_ptr<float>(), ns...);
}

template<int n, int m>
MatColFix<n,m> torchToEigen(const torch::Tensor &tensor) {
  assert(n == tensor.size(0)); // Invalid rows
  assert((tensor.dim() == 1 and m == 1) or m == tensor.size(1)); //Invalid cols
  auto data = tensor.data_ptr<float>();
//  Eigen::Map<Eigen::Matrix<float, m, n>> swapped(data);
//  return swapped.transpose();
  return MatColFix<n,m>(data);
}



template<int n, int m>
torch::Tensor eigenToTorch(const MatColFix<n,m> &mat) {
  torch::Tensor tensor;
  if constexpr (m != 1) {
    tensor = torch::zeros({n, m}, c10::ScalarType::Float);
  } else {
    tensor = torch::zeros({n}, c10::ScalarType::Float);
  }

  auto data = tensor.data_ptr<float>();

//  Eigen::Map<Eigen::Matrix<float, m, n>> map(data, m, n);
  Eigen::Map<MatColFix<n,m>> map(data, n, m);
//  map = mat.transpose();
  map = mat;
  return tensor;
}

using MatrixXfR = Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor>;

template<int n, int m>
torch::Tensor dynEigenToTorch(const MatrixXfR & mat){
  torch::Tensor tensor = torch::zeros({n,m}, c10::ScalarType::Float);
  auto data = tensor.data_ptr<float>();
  Eigen::Map<MatrixXfR> map(data, n, m);
//  map = mat.transpose();
  map = mat;
  return tensor;
}
template<int ... ns>
using TensorXfR = Eigen::Tensor<float, sizeof...(ns), Eigen::RowMajor>;

template<int ... ns>
torch::Tensor dynEigenTensorToTorch(const TensorXfR<ns...> & eig_tensor){
  torch::Tensor tensor = torch::zeros(at::IntArrayRef({ns ...}),
                                      c10::ScalarType::Float);
  auto data = tensor.data_ptr<float>();
  Eigen::TensorMap<TensorXfR<ns ...>> map(data, ns ...);
//  map = mat.transpose();
  map = eig_tensor;
  return tensor;
}






#endif //FULL_STACK_TORCH_UTILS_H
