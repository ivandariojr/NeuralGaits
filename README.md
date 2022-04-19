# Neural Gaits

## Setting up the Simulation Environment
First, we recommend setting ```${INSTALL_DIR}``` to be a convenient directory where you would like everything to be installed (via the export command in your bashrc, for example). Then, for all cmake commands below, add
```
-DCMAKE_INSTALL_PREFIX=${INSTALL_DIR} -DCMAKE_PREFIX_PATH=${INSTALL_DIR}
```
### RaiSim
As the RaiSim environment is used for the robot simulation, the first step is to get a license key [here](https://raisim.com/sections/License.html) (free for academic use). Next, follow the [installation instructions](https://raisim.com/sections/Installation.html), making sure to build with examples (include the cmake argument -DRAISIM_EXAMPLE=ON) and setting -DCMAKE_INSTALL_PREFIX=$LOCAL_INSTALL, replacing $LOCAL_INSTALL with the directory you would like to install to (${INSTALL_DIR}, as recommended above). Additionally, the RaiSim Ogre (an Ogre based visualizer) is used to see the robot simulation, found [here](https://github.com/raisimTech/raisimOgre).

Once installed, check to make sure the included examples run properly. To do this, cd to the ```raisimOgre/build/examples``` directory and try executing one of the examples (make sure to put your activation key in the right place). Then, in the folder where raisimOgre was cloned (the src folder), delete the examples folder, and add a symlink to the NeuralGaits/Sim/raisim folder:
```ln -s ${REPO_DIR}/NeuralGaits/Sim/raisim examples```.
Then, re-run the cmake command for raisimOgre, and re-make. After this step, there should be an executable titled ''amber'' in the raisimOgre/build/exmaples folder.
### amber3m-cpp
First, install [yaml-cpp](https://github.com/jbeder/yaml-cpp), [osqp](https://osqp.org/docs/get_started/sources.html), and [osqp-eigen](https://github.com/robotology/osqp-eigen). Go to the amber3m-cpp subdirectory of the folder where the NeuralGaits repo was cloned, and run
```
mkdir build
cd build
cmake .. -DTorch_DIR=${INSTALL_DIR}/share/cmake/Torch -DCMAKE_PREFIX_PATH="${INSTALL_DIR};${INSTALL_DIR}/share/learn-trajopt-cpp" -Dyaml-cpp_DIR=${INSTALL_DIR}/share/cmake/yaml-cpp
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

