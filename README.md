# Neural Gaits

## Setting up the Simulation Environment
### RaiSim
As the RaiSim environment is used for the robot simulation, the first step is to get a license key [here](https://raisim.com/sections/License.html) (free for academic use). Next, follow the [installation instructions](https://raisim.com/sections/Installation.html), making sure to build with examples (include the cmake argument -DRAISIM_EXAMPLE=ON) and setting -DCMAKE_INSTALL_PREFIX=$LOCAL_INSTALL, replacing $LOCAL_INSTALL with the directory you would like to install to. Additionally, the RaiSim Ogre (an Ogre based visualizer) is used to see the robot simulation, found [here](https://github.com/raisimTech/raisimOgre).

Once installed, check to make sure the included examples run properly. To do this, cd to the ```raisimOgre/build/examples``` directory and try executing one of the examples (make sure to put your activation key in the right place). Then, in the folder where raisimOgre was cloned (the src folder), delete the examples folder, and add a symlink to the NeuralGaits/Sim/raisim folder:
```ln -s ${REPO_DIR}/NeuralGaits/Sim/raisim examples```
Then, go to the raisimOgre/build/exmaples folder, and re-make. After this step, there should be an executable titled ''amber''.
### amber3m-cpp
Let ```${TORCH_DIR}``` denote the directory where torch was installed (e.g. ```~/repos/libtorch```) and ```${YAML_DIR}``` the directory where yaml-cpp was installed (e.g. ```~/repos/yaml_install```).
Go to the amber3m-cpp subdirectory of the folder where the NeuralGaits repo was cloned, and run
```
mkdir build
cd build
cmake .. -DTorch_DIR=${TORCH_DIR}/share/cmake/Torch -DCMAKE_PREFIX_PATH="${TORCH_DIR};${TORCH_DIR}/share/learn_trajopt_cpp" -Dyaml-cpp_DIR=${YAML_DIR}/share/cmake/yaml-cpp
make -j8
```

## Training Policy

## Running A Simulation
To run a simulation, open two terminals. In one terminal, change to the amber3m-cpp build subdirectory, and run:
```./amber-cpp```
and in the other, change to the raisimOgre/build/examples directory, and run:
```./amber```
When the Ogre environment loads, click "set to real time" to see the robot execute the trained policy.
## Refining a Model using Hardware Data

