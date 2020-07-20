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

String readIn, base, shoulder, joint1, joint2, joint3, effector;
const int NUMJOINTS = 6;

String jointStrThetas[NUMJOINTS] {"0", "0", "0", "0", "0", "0"};
int jointThetas[NUMJOINTS];
int masterThetas[NUMJOINTS];
bool flag;

void setup() {
  // put your setup code here, to run once:
  int index = 0;
  for (int theta : jointThetas) {
    masterThetas[index] = theta;
    index++;
  }
  // Initialize Servos to pins
  servo_base.attach(8);
  servo_shoulder.attach(9);
  servo_arm1.attach(10);
  servo_arm2.attach(11);
  servo_arm3.attach(12); //MICROSERVO PIN
  end_effector.attach(13);
  delay(1000);

  Serial.begin(9600);
  Serial.flush();
  Serial.println("Beginning program-----");
  delay(5000);

  servo_base.write(90);
  servo_shoulder.write(90);
  servo_arm1.write(90);
  servo_arm2.write(90);
  servo_arm3.write(90);  //MICROSERVO WRITE
  end_effector.write(90);
  delay(1000);
  Serial.println("Joints Initialized-----");
  Serial.flush();
}

int ctr = 0;
int joint = 0;
int j = 0;

void loop() {
  //gets serial input
  while (Serial.available()) {
    delay(3);
    if (Serial.available() > 0) {
      char c = Serial.read();
      readIn += c;
    }
    //Serial.println("test");
    //Serial.println(readIn);
    flag = true;
  }
  //reads serial input
  if (readIn.length() > 0 && flag) {
    //Serial.println(readIn);
    //Serial.println("is this many chars long: ");
    //Serial.println(readIn.length());
    //flag = false;
    //enters valid values into array
    for (int k = 0; k < readIn.length(); k++) {
      //Serial.println(readIn.charAt(k));
      if (isSpace(readIn.charAt(k))) {
        //Serial.print("whitespace at ");
        //Serial.print(k);
        //Serial.println();
        String temp = readIn.substring(j, k);
        if (ctr < 6) {
          jointStrThetas[ctr] = temp;
          ctr++;
        }
        //Serial.println(temp);
        j = k + 1;
      }
      //base = readIn.substring(0, 4);
      //jointThetas[0] = base.toInt();
      //servo_base.write(jointThetas[0]);
    }
    //resets counter
    ctr = 0;

    Serial.println(readIn);
    //writes input string values to array
    for (int l = 0; l < 6; l++) {
      //Serial.print("printing");
      //Serial.println(jointStrThetas[l]);
      jointThetas[l] = jointStrThetas[l].toInt();
      //Serial.println(jointThetas[l]);
    }

    //Serial.print(getInputThetas(jointThetas));
    Serial.print(getMasterThetas());
  }


  //check to see if joint angles are not at target orientation
  //rotate servos and update master array of thetas
  if (!areJointsAtTarget(jointThetas)) {
    rotateServos(jointThetas);
    int index = 0;
    for (int theta : jointThetas) {
      masterThetas[index] = theta;
      index++;
    }
  }
  else{
    Serial.println("Joints Already At Target---");
    delay(1000);
    Serial.print(getMasterThetas());
    delay(5000);
  }
  //reset input reading variables and Serial buffer
  readIn = "";
  flag = false;
  Serial.flush();
}

bool areJointsAtTarget(int joints[]) {
  for (int k = 0; k < sizeof(joints) / sizeof(joints[0]); k++) {
    if (joints[k] != masterThetas[k]) {
      Serial.println("Joints not at target---");
      return false;
    }
  }
  //Serial.println("joints at target");
  return true;
}

void rotateServos(int joints[]) {
  Serial.println("Aligning Joints---");
  //if (sizeof(joints) / sizeof(joints[0]) == NUMJOINTS) {
  //Serial.println("TEST");
  delay(1000);
  servo_base.write(joints[0]);
  servo_shoulder.write(joints[1]);
  servo_arm1.write(joints[2]);
  servo_arm2.write(joints[3]);
  servo_arm3.write(joints[4]);
  end_effector.write(joints[5]);
  delay(500);
  //}
}

String getInputThetas(int joints[]) {
  String thetas = "";
  thetas += "\n--printing input list--\n";
  for (int n = 0; sizeof(joints) / sizeof(joints[0]); n++) {
    thetas += String(joints[n]);
    thetas += " ";
  }
  thetas += "\n--Done printing--\n";

  return thetas;
}

String getMasterThetas() {
  String thetas = "";
  thetas += "\n--printing master list--\n";
  for (int k : masterThetas) {
    thetas += String(k);
    thetas += " ";
  }
  thetas += "\n--Done printing--\n";

  return thetas;
}
