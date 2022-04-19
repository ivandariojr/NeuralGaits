//
// Created by ivan on 10/25/20.
//


#include <torch/torch.h>
#include <torch/script.h>
#include <array>
#include <iostream>
#include <gtest/gtest.h>
#include <eigen3/Eigen/Dense>
#include "torch_utils.h"

template<int n>
constexpr std::array<float, n> arange() {
  std::array<float, n> return_array;
  for(int i=1; i<n; i++){
    return_array[i-1] = float (i);
  }
  return return_array;
}


torch::Tensor th_vector = torch::arange(1,10).to(c10::ScalarType::Float);
torch::Tensor non_square_tensor = torch::arange(1,7).reshape({2,3}).to(c10::ScalarType::Float);
torch::Tensor tall_non_square_tensor = torch::arange(1,7).reshape({3,2}).to(c10::ScalarType::Float);
torch::Tensor square_tensor = torch::arange(1,10).reshape({3,3}).to(c10::ScalarType::Float);
torch::Tensor cube_tensor = torch::arange(1, 28).reshape({3,3,3}).to(c10::ScalarType::Float);

auto non_square_entries = arange<7>();
auto square_entries = arange<10>();
auto cube_entries = arange<28>();

Eigen::Matrix<float, 2,3, Eigen::RowMajor> non_square_matrix(non_square_entries.data());
Eigen::Matrix<float, 3,2, Eigen::RowMajor> tall_non_square_matrix(non_square_entries.data());
Eigen::Matrix<float, 3,3, Eigen::RowMajor> square_matrix(square_entries.data());
Eigen::Matrix<float, 9,1> eig_vector(square_entries.data());
Eigen::TensorMap<Eigen::TensorFixedSize<float, Eigen::Sizes<3,3,3>, Eigen::RowMajor>> eig_cube_tensor(cube_entries.data(),
                                                                                                       Eigen::Sizes<3,3,3>());


TEST(test_torch_eigen_interface, test_torch_to_eigen_vec) {
  EXPECT_NEAR(0.0,
              (torchToEigen<9,1>(th_vector) - eig_vector).cwiseAbs().maxCoeff(),
              1e-12);
}

TEST(test_torch_eigen_interface, test_torch_to_eigen_square) {
  EXPECT_NEAR(0.0,
              (torchToEigen<3,3>(square_tensor) - square_matrix).cwiseAbs().maxCoeff(),
              1e-12);
}

TEST(test_torch_eigen_interface, test_torch_to_eigen_non_square) {
  EXPECT_NEAR(0.0,
              (torchToEigen<2,3>(non_square_tensor) - non_square_matrix).cwiseAbs().maxCoeff(),
              1e-12);
}

TEST(test_torch_eigen_interface, test_torch_to_eigen_tall_non_square) {
  EXPECT_NEAR(0.0,
              (torchToEigen<3,2>(tall_non_square_tensor) - tall_non_square_matrix).cwiseAbs().maxCoeff(),
              1e-12);
}

TEST(test_torch_eigen_interface, test_eigen_to_torch_vec) {
  EXPECT_NEAR(0.0,
              (eigenToTorch(eig_vector) - th_vector).norm(2).max().item().toFloat(),
              1e-12);
}

TEST(test_torch_eigen_interface, test_eigen_to_torch_square) {
  EXPECT_NEAR(0.0,
              (eigenToTorch(square_matrix) - square_tensor).flatten().norm(2).max().item().toFloat(),
              1e-12);
}

TEST(test_torch_eigen_interface, test_eigen_to_torch_cube) {
  EXPECT_NEAR(0.0,
              (dynEigenTensorToTorch<3,3,3>(eig_cube_tensor) - cube_tensor).flatten().norm(2).max().item().toFloat(),
              1e-12);
}

TEST(test_torch_eigen_interface, test_dyn_eigen_to_torch_tall_non_square) {
    EXPECT_NEAR(0.0,
                (dynEigenToTorch<3,2>(tall_non_square_matrix) - tall_non_square_tensor).flatten().norm(2).max().item().toFloat(),
                1e-12);
}
TEST(test_torch_eigen_interface, test_dyn_eigen_to_torch_non_square) {
    EXPECT_NEAR(0.0,
                (dynEigenToTorch<2,3>(non_square_matrix) - non_square_tensor).flatten().norm(2).max().item().to<float>(),
                1e-12);
}
TEST(test_torch_eigen_interface, test_eigen_to_torch_non_square) {
  EXPECT_NEAR(0.0,
              (eigenToTorch(non_square_matrix) - non_square_tensor).flatten().norm(2).max().item().to<float>(),
              1e-12);
}
TEST(test_torch_eigen_interface, test_eigen_to_torch_tall_non_square) {
  EXPECT_NEAR(0.0,
              (eigenToTorch(tall_non_square_matrix) - tall_non_square_tensor).flatten().norm(2).max().item().to<float>(),
              1e-12);
}

TEST(test_torch_eigen_interface, test_torch_to_eigen_cube) {
  Eigen::Tensor<float, 0, Eigen::RowMajor> max_error = (eig_cube_tensor - torchToEigenTensor<3,3,3>(cube_tensor)).abs().maximum();
  EXPECT_NEAR(0.0,
              max_error(0),
              1e-12);
}

TEST(test_torch_eigen_interface, test_torch_to_dyn_eigen_cube) {
    Eigen::Tensor<float, 0, Eigen::RowMajor> max_error = (eig_cube_tensor - torchToDynEigenTensor<3,3,3>(cube_tensor)).abs().maximum();
    EXPECT_NEAR(0.0,
                max_error(0),
                1e-12);
}