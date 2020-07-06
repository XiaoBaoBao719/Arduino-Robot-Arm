#include <SoftwareSerial.h>
#include <stdlib.h>
#include <Servo.h>
#include <math.h>

Servo servo_base;
Servo servo_shoulder;
Servo servo_arm1;
Servo servo_arm2;
Servo servo_arm3;
Servo end_effector;

int rotStart, rotEnd, counter, rotRate;

int rotationInput;
const int numActuators = 6;
int rotValues [numActuators];
int inputCtr;

long receive;

void setup() {
  // Initialize Servos to pins
  servo_base.attach(2);
  servo_shoulder.attach(3);
  servo_arm1.attach(4);
  servo_arm2.attach(5);
  servo_arm3.attach(6);
  end_effector.attach(7);

  inputCtr = 0;
  //rotation smoothing test init
  rotStart = 0;
  rotEnd = 180;
  rotRate = 1; //1 degree per 100 ms
  Serial.println("test1");
  //Initialize servo rotations
  for(int k = 0; k < sizeof(rotValues); k++){
    rotValues[k] = 90;
  }
  Serial.println("test2");
  delay(1000);
  //Start Serial Comm
  Serial.begin(9600);
  Serial.flush();

  Serial.println("Initiating Calibration ------");
  servo_base.write(0);
  delay(1000);
  servo_base.write(90);
  delay(1000);
  servo_base.write(180);
  delay(1000);
  servo_base.write(90);
  Serial.println("Calibration complete -------");
  printServoMenu();
}

void loop() {
  while (Serial.available() > 0) {

    //printServoMenu();
    receive = Serial.parseInt();
    Serial.flush();

    if (receive != NULL) {
      //++inputCtr;
      Serial.println("Changing Servo Number: " + receive);
      /*
        try {
        rotationInput = (int) receive;
        Serial.println("Value of input is : %d" + rotationInput);
        }
        catch (int e) {
        Serial.println("int excpetion occured");
        Serial.println("Please input a rotation in degrees");
        }
      */
      Serial.println("Enter rotation value 1-180 degrees");
      rotationInput = Serial.parseInt();
      Serial.flush();
      if (rotationInput != NULL && receive < sizeof(rotValues) && receive >= 0) {
        Serial.println(rotationInput);
        rotValues[receive] = rotationInput;
        //Serial.println("input: " + rotationInput);
        //servo_base.write(receive);
        Serial.println("Servo rotation recorded----");

        rotateServos();
      }
      
      rotationInput = NULL;
      receive = NULL;
      Serial.flush();
    }
  }
  //rotateServos();
  //inputCtr = 0;
}

void rotateServos(void) {
  Serial.println("Rotating---------");
  servo_base.write(rotValues[0]);
  servo_shoulder.write(rotValues[1]);
  servo_arm1.write(rotValues[2]);
  servo_arm2.write(rotValues[3]);
  servo_arm3.write(rotValues[4]);
  end_effector.write(rotValues[5]);
  Serial.println("Rotation Finished-------");
}

void printServoMenu(void) {
  Serial.println("Please select a Servo to control:");
  Serial.println("1: base");
  Serial.println("2: shoulder");
  Serial.println("3: joint 1");
  Serial.println("4: joint 2");
  Serial.println("5: joint 3");
  Serial.println("6: gripper");
}

//WORK IN PROGRESS
void smoothRotate(float theta, int servoNum) {
  //rotation smoothing test
  rotEnd = theta;
  for (counter = rotStart; counter < rotEnd; counter += rotRate)
  {
    //increment servo by 1 degree
    //servo_base.write(fabs(counter));
    //servo_shoulder.write(fabs(counter));
    //servo_arm1.write(fabs(counter));
    //servo_arm2.write(fabs(counter));
    //servo_arm3.write(fabs(counter));
    //end_effector.write(fabs(counter));
    delay(100);
  }
  //flips initial and final rotation bounds
  //int temp = rotStart;
  //rotStart = rotEnd * -1;
  //rotEnd = temp;
}
