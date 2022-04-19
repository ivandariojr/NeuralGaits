//
// Created by ivan on 8/29/21.
//

#include <torch/script.h>
#include <experimental/filesystem>
#include <iostream>
#include <gtest/gtest.h>

torch::NoGradGuard no_grad;

class LoadModelTest : public ::testing::Test
{
 protected:
  LoadModelTest() :
    sample_model(torch::jit::load("data/sample.th"))
  {
    sample_model.to(torch::kCPU);
    sample_input = torch::rand({10, 2});
    pred = torch::rand({10, 4});
//    torch::jit::script::Module container(torch::jit::load("data/test_container.th"));
//    left = container.attr("test_left").toTensor();
//    right = container.attr("test_right").toTensor();
//    d3 = container.attr("test_d3").toTensor();
//    dr_hat = container.attr("test_dr_hat").toTensor();
//    pred = container.attr("test_pred").toTensor();
  }

  torch::jit::script::Module sample_model;
  torch::Tensor sample_input, pred;
};

TEST_F(LoadModelTest, Load){
  std::cout << "std::filesystem::current_path():"  << std::endl << std::experimental::filesystem::current_path() << std::endl;
  for (const auto &item: sample_model.named_buffers()) {
    std::cout << "sample_model.named_buffers():"  << item.name << std::endl;
  }

  for (const auto &attribute: sample_model.named_attributes()) {
    std::cout << "attribute.name:"  << std::endl << attribute.name << std::endl;
  }
  for (const auto &method: sample_model.get_methods()) {
    std::cout << "method.name():"  << std::endl << method.name() << std::endl;
  }
}

TEST_F(LoadModelTest, ForwardTest) {
  auto model_output = sample_model.forward({sample_input});
  std::cout << "model_output.toTensor().sizes():"  << std::endl << model_output.toTensor().sizes() << std::endl;
}

TEST_F(LoadModelTest, ForwardCudaTest) {
  sample_model.to(torch::kCUDA);
  auto model_output = sample_model.forward({sample_input.to(torch::kCUDA)});
  std::cout << "model_output.toTensor().sizes():"  << std::endl << model_output.toTensor().sizes() << std::endl;
}


