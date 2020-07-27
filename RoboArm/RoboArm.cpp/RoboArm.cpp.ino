/*
 * RoboArm.cpp
 */

#include "Arduino.h"
#include "RoboArm.h"
#include "math.h"
#include "Servo.h"

RoboArm::RoboArm(){
  defaultAngles = {90, 90, 90, 90, 90, 90};
  servoPins = {8, 9, 10, 11, 12, 13};
}
