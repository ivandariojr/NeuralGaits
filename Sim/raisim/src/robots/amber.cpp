//
// Created by Jemin Hwangbo on 2/28/11.
// MIT License
//
// Copyright (c) 2011-2011 Robotic Systems Lab, ETH Zurich
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


#include <raisim/OgreVis.hpp>
#include "raisimBasicImguiPanel.hpp"
#include "raisimKeyboardCallback.hpp"
#include "helper.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <Eigen/Geometry>
#include <Eigen/Dense>
#include "yaml-cpp/yaml.h"
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define PORT 8081

#define PI 3.1415926535
#define BezOrd 4

constexpr size_t JointsDim = 4;
using JointPositions = Eigen::Matrix<double, JointsDim, 1>;

void setupCallback() {
    auto vis = raisim::OgreVis::get();

    /// shdow setting
    vis->getSceneManager()->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_ADDITIVE );
    vis->getSceneManager()->setShadowTextureSettings(2048, 3);

    /// light
    vis->getLight()->setDiffuseColour(1, 1, 1);
    vis->getLight()->setCastShadows(true);
    Ogre::Vector3 lightdir(-3,-3,-1.5);
    lightdir.normalise();
    vis->getLightNode()->setDirection({lightdir});
    vis->setCameraSpeed(300);

    /// load  textures
    vis->addResourceDirectory(vis->getResourceDir() + "/material/checkerboard");
    vis->loadMaterialFile("checkerboard.material");

    /// scale related settings!! Please adapt it depending on your map size
    // beyond this distance, shadow disappears
    vis->getSceneManager()->setShadowFarDistance(100);
    // size of contact points and contact forces
    vis->setContactVisObjectSize(0.03, 0.6);
    // speed of camera motion in freelook mode
    vis->getCameraMan()->setTopSpeed(5);

    /// skybox
    Ogre::Quaternion quat;
    quat.FromAngleAxis(Ogre::Radian(M_PI_2), {1., 0, 0});
    vis->getSceneManager()->setSkyBox(true,
                                      "gray",
                                      500,
                                      true,
                                      quat);
}

int main(int argc, char **argv) {

    int sock = 0;
    struct sockaddr_in serv_addr;
    // char buffer[1024] = {0};
    double buffer[4] = {0,0,0,0};
    double actState[11] = {0,0,0,0,0,0,0,0,0,0,0}; // TORSO, LK,LH,RH,RK, vels
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    YAML::Node gains = YAML::LoadFile("param_gain.yaml");
    double td0 = gains["td0"].as<double>();
    double xd0 = gains["xd0"].as<double>();
    double z0 = gains["z0"].as<double>();
    double T0 = gains["Torso0"].as<double>();

    // License nonsense
    raisim::World::setActivationKey(raisim::loadResource("activation.raisim"));

    /// create raisim world
    raisim::World world;
    double ts = 0.002;
    // double ts = 0.00025;
    double freq = 1.0/ts;
    world.setTimeStep(ts);
    // Material
    float mu = .6;
    world.setDefaultMaterial(mu, 0., 0.);
    world.setMaterialPairProp("steel","steel", mu, 0., 1);

    auto vis = raisim::OgreVis::get();

    /// these method must be called before initApp
    vis->setWorld(&world);
    vis->setWindowSize(1000, 400);
    vis->setImguiSetupCallback(imguiSetupCallback);
    vis->setImguiRenderCallback(imguiRenderCallBack);
    vis->setKeyboardCallback(raisimKeyboardCallback);
    vis->setSetUpCallback(setupCallback);
    vis->setAntiAliasing(2);

    /// starts visualizer thread
    vis->initApp();

    /// create raisim objects
    auto ground = world.addGround(0,"steel");
    ground->setName("checkerboard");

    std::vector<raisim::ArticulatedSystem*> amber;

    /// create visualizer objects
    vis->createGraphicalObject(ground, 20, "floor", "checkerboard_green");

    /// ANYmal joint PD controller
    Eigen::VectorXd jointNominalConfig(4), jointVelocityTarget(4);

    amber.push_back(world.addArticulatedSystem(raisim::loadResource("amber/amber.urdf")));
    vis->createGraphicalObject(amber.back(), "amber");
    amber.back()->setGeneralizedForce(Eigen::VectorXd::Zero(amber.back()->getDOF()));
    amber.back()->setControlMode(raisim::ControlMode::FORCE_AND_TORQUE);
    amber.back()->setName("amber");
    amber.back()->getCollisionBody("left_toe/0").setMaterial("steel");
    amber.back()->getCollisionBody("right_toe/0").setMaterial("steel");

    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.0, 0.05);
    std::srand(std::time(nullptr));
    amber.back()->printOutBodyNamesInOrder();

    std::cout<<"Start"<<std::endl;

    // lambda function for the controller
    auto controller = [&vis, &amber, &generator, &distribution, freq, ts, sock, &buffer, &actState]() {
        int  valread;
        double t;
        std::ofstream jointFile;
        jointFile.open("jointFile.csv",std::ios_base::app);
        const raisim::Vec<3> gravity = {0,0,-9.81};
        Eigen::VectorXd jointNominalConfig(4), jointVelocityTarget(4);
        Eigen::VectorXd actJointPos(11), actJointVel(10);
        static size_t controlDecimation = 0;
        controlDecimation++;
        t = ((float)controlDecimation/freq)*1000;

        amber[0]->getState(actJointPos, actJointVel);
        actState[0] = -actJointPos[0];
        actState[5] = -actJointVel[0];
        for (int i = 1; i < 5; i++) {
            actState[i] = actJointPos[i+2];
            actState[i+5] = actJointVel[i+2];
        }
        double tmp1 = actState[2];
        double tmp2 = actState[7];
        actState[2] = actState[1];
        actState[7] = actState[6];
        actState[1] = tmp1;
        actState[6] = tmp2;

        // actState[2] -= PI;
        // actState[3] -= PI;
        actState[10] = t;


        send(sock , &actState , sizeof(actState) , 0 );
        valread = read( sock , &buffer, sizeof(buffer));

        dContactGeom* contactTmp = new dContactGeom;
        raisim::CollisionSet* collbods = new raisim::CollisionSet();
        collbods[0] = amber[0]->getCollisionBodies();

        Eigen::VectorXd force(7);
        Eigen::VectorXd desState(4);
        for (int i = 0; i < 4; i ++)
            desState(i) = buffer[i];

        double tmp = desState(1);
        desState(1) = desState(0);
        desState(0) = tmp;

        force << 0,0,0,desState;
        amber[0]->setGeneralizedForce(force);

        jointFile<<std::endl;
        jointFile.close();
    };

    vis->setControlCallback(controller);

    // Start "paused"
    vis->getRealTimeFactorReference() = 0.00001f;

    // set camera
    vis->getCameraMan()->getCamera()->setPosition(1, -3, 2.5);
    vis->getCameraMan()->getCamera()->pitch(Ogre::Radian(1));

    // Initialize nominal joint config
    amber[0]->getState(jointNominalConfig, jointVelocityTarget);

    for (int k = 0; k<3; k++){
        jointNominalConfig[k] = 0;
        jointVelocityTarget[k] = 0;
    }
    Eigen::VectorXd desState(4);
    int  valread;
    // send(sock , ping , strlen(ping) , 0 ); 
    for (int i = 0; i < 11; i++)
        actState[i] = 0;
    send(sock , &actState , sizeof(actState) , 0 );
    valread = read( sock , &buffer, sizeof(buffer));
    for (int i = 0; i < 4; i ++)
        desState(i) = buffer[i];
    // desState(i) = 0;
    double tmp = desState(1);
    desState(1) = desState(0);
    desState(0) = tmp;

    jointNominalConfig[0] = -T0;
    jointNominalConfig[1] = z0;

    for (int k=0; k < 4; k++) {
        jointNominalConfig[k+3] = desState(k);
        jointVelocityTarget[k+3] = 0;
    }

    jointVelocityTarget[0] += td0;
    jointVelocityTarget[2] += xd0;

    amber[0]->setState(jointNominalConfig, jointVelocityTarget);

    /// run the app
    vis->run();

    /// terminate
    vis->closeApp();
    std::cout<<"Stop"<<std::endl;

    return 0;
}
