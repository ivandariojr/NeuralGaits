# README #

Run:
```cmake .. -DTorch_DIR=/home/noel/repos/libtorch/share/cmake/Torch -DCMAKE_PREFIX_PATH="/home/noel/repos/libtorch_install;/home/noel/repos/libtorch_install/share/learn_trajopt_cpp" -Dyaml-cpp_DIR=/home/noel/repos/yaml_install/share/cmake/yaml-cpp'''


## Introduction
Repository for the updated C++ code on the Jetson TX2 for AMBER-3M.

## Dependencies
This requires the Eigen toolbox to run. Follow "installation" instructions and set the environment variable EIGEN3_INCLUDE_DIR to the appropriate location.

Additionally, the yaml-cpp library needs to be built. Once completed, add the location of the libyaml-cpp.a file to an environment variable YAMLCPP_LIB

Additionally, the SOEM ethercat library needs to be built. No environment variable is needed as long as it has been installed properly. When running cmake, use 
```cmake -DCMAKE_PREFIX_PATH=/usr/local ..``` 
to allow the ```find_package``` command to be used by the library.

Finally, OSQP and OSQP-eigen are required. Again, no environment variables are needed.

## How to get started
Clone the repo, go to the main directory and run
```cd build &&
cmake .. && 
make &&
./amber-cpp```

* Version 0.0

## Documentation
This repository supports Doxygen documentation, with Doxyfile included. Once doxygen has been installed, create a folder "documentation", then run ```doxygen Doxyfile``` in the base directory to generate html documentation. To view the documentation, go to the ```documentation/html``` directory, and open ```index.html```. 

## Jetson Info
* [https://elinux.org/GPIO](GPIO on Linux)
* [https://www.jetsonhacks.com/nvidia-jetson-tx1-j21-header-pinout/](TX2 Pinout)
* [https://elinux.org/Jetson/TX2_SPI](TX2 SPI)
* [https://www.arduino.cc/en/reference/SPI](Arduino SPI)

## ELMO Info
* [https://www.motorpowerco.com/media/filer_public/f0/3c/f03c5391-7827-4902-8e16-3dbb8a16f19a/man-can402ig.pdf](CAN Message Guide)
* [https://gist.github.com/mgruhler/7ccb12d95c4d171b64aa3d7ea82cc1a7] (Basic Gold Whistle Control Script)
* [https://openethercatsociety.github.io/doc/soem/tutorial_8txt.html] (SOEM tutorial)
* [https://github.com/OpenEtherCATsociety/SOEM/issues] (More info about SDO/PDO)
* [https://www.elmomc.com/product/gold-whistle/] (Communication Speeds)
* [https://www.elmomc.com/product/gold-whistle/] (Hardware (Wiring Info))
* [https://www.elmomc.com/wp-content/uploads/2018/03/EtherCAT_Communication.pdf] (EtherCAT Info)
* [http://www.pk-rus.ru/fileadmin/download/ethercat_application_manual.pdf] (More EtherCAT Info)
