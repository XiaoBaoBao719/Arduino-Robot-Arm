/*
   RoboArm.h - Library for controlling n - degrees of freedom robotic arm
   Created by Xiao-Bao Bao, 2020 
   Based on RobotArm Library by Darko Lukic (lukicdarkoo@gmail.com)
   Public domain shit released
*/

#ifndef RoboArm_h
#define RoboArm_h

#include "Arduino.h"
#include "Servo.h"
#include "math.h"
//#include <PID_v1.h>
#include "inttypes.h"

/*
#define PI = 3.14159265

#define ROBOARM_BASE 0
#define ROBOARM_SHOULDER 1
#define ROBOARM_JOINT3 2
#define ROBOARM_JOINT4 3
#define ROBOARM_JOINT5 4
#define ROBOARM_GRIPPER  5
*/

class RoboArm
{
  public:
    RoboArm();

    void attachPins(); //called in setup
    void updateArm(); //call every 50ms

    void setJointAngle(uint8_t, uint8_t);
    void homeAll();

    uint8_t readAngle(uint8_t);
    void printAngles();

    bool smoothEnabled;
    bool jointsAtTarget;

    uint8_t defaultAngles[6];
    uint8_t servoPins[6];
  private:

    double lastJointAngles[6];
    double curJointAngles[6];
    double nextJointAngles[6];

};

#endif
