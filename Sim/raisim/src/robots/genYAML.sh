#!/bin/sh
for d in ./Gaits/*/; do cp cppToYAML.cpp "$d"; done
for d in ./Gaits/*/; do (cd "$d" && g++ -I/usr/local/lib/yaml-cpp-yaml-cpp-0.6.0/include -L/usr/local/lib/yaml-cpp-yaml-cpp-0.6.0/build -lyaml-cpp -o cppToYAML cppToYAML.cpp -std=c++11 -lyaml-cpp && ./cppToYAML); done
