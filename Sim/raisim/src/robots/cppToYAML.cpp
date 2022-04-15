#include "yaml-cpp/yaml.h"
#include "param_exp.cpp"
#include <iostream>
#include <fstream>

// g++ -I/usr/local/lib/yaml-cpp-yaml-cpp-0.6.0/include -L/usr/local/lib/yaml-cpp-yaml-cpp-0.6.0/build -lyaml-cpp -o testprogram YAMLwrite.cpp -std=c++11 -lyaml-cpp

int main()
{
  std::vector <float> x0_(x0,x0+sizeof(x0)/sizeof(*x0));
  std::vector <float> q0_(q0,q0+JOINTS_N);
  std::vector <float> ph_param_(ph_param,ph_param+sizeof(ph_param)/sizeof(*ph_param));
  std::vector <float> t_range1_(t_range1,t_range1+sizeof(t_range1)/sizeof(*t_range1));
  std::vector <float> t_range2_(t_range2,t_range2+sizeof(t_range2)/sizeof(*t_range2));
  std::vector<std::vector<float>> apos_x1_;
  std::vector<std::vector<float>> apos_x2_;
  for (int i = 0; i < JOINTS_N; i++) {
    std::vector <float> tmp1(apos_x1[i],apos_x1[i]+BEZ_ORD+1);
    std::vector <float> tmp2(apos_x2[i],apos_x2[i]+BEZ_ORD+1);
    apos_x1_.push_back(tmp1);
    apos_x2_.push_back(tmp2);
  }
  
  YAML::Emitter out;
  out << YAML::BeginMap;
  out << YAML::Key << "x0" << YAML::Value << YAML::Flow << x0_;
  out << YAML::Key << "q0" << YAML::Value << YAML::Flow << q0_;
  out << YAML::Key << "ph_param" << YAML::Value << YAML::Flow << ph_param_;
  out << YAML::Key << "t_range1" << YAML::Value << YAML::Flow << t_range1_;
  out << YAML::Key << "t_range2" << YAML::Value << YAML::Flow << t_range2_;
  out << YAML::Key << "apos_x1" << YAML::Value << YAML::Flow << apos_x1_;
  out << YAML::Key << "apos_x2" << YAML::Value << YAML::Flow << apos_x2_;
  out << YAML::EndMap;
  
  std::ofstream myfile;
  myfile.open ("param_exp.yaml");
  myfile << out.c_str();
  myfile.close();

  return 0;
}
