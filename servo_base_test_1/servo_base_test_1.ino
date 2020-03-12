#include <SoftwareSerial.h>
#include <Servo.h>
#include <math.h>

Servo servo_base;
Servo servo_shoulder;
Servo servo_arm1;
Servo servo_arm2;
Servo servo_arm3;

int rotStart, rotEnd, counter, rotRate;

void setup() {
  // put your setup code here, to run once:
  servo_base.attach(9);
  servo_shoulder.attach(6);
  servo_arm1.attach(5);
  servo_arm2.attach(3);

  //rotation smoothing test init
  rotStart = 0;
  rotEnd = 180;
  rotRate = 4; //1 degree per 100 ms

  delay(1000);
  //servo_base.write(90);
  //delay(5000);
  servo_shoulder.write(90);
  //delay(5000);
  //servo_arm1.write(90);
  //delay(5000);
  //servo_arm2.write(90);
  //delay(10000);
  /*
  servo_base.write(0);
  delay(1000);
  servo_base.write(45);
  delay(1000);
  servo_base.write(90);
  delay(1000);
  servo_base.write(120);
  delay(1000);
  servo_base.write(180);
  delay(5000);
  servo_base.write(90);
  delay(5000);
  */
  /*
  servo_shoulder.write(0);
  delay(1000);
  servo_shoulder.write(45);
  delay(1000);
  servo_shoulder.write(90);
  delay(1000);
  servo_shoulder.write(120);
  delay(1000);
  servo_shoulder.write(180);
  delay(5000);
  servo_shoulder.write(90);
  delay(5000);
  
  /*
  servo_arm1.write(0);
  delay(1000);
  servo_arm1.write(45);
  delay(1000);
  servo_arm1.write(90);
  delay(1000);
  servo_arm1.write(120);
  delay(1000);
  servo_arm1.write(180);
  delay(5000);
  servo_arm1.write(90);
*/
  
}

void loop() {

  //rotation smoothing test 
  /*
   for(counter = rotStart; counter < rotEnd; counter += rotRate)
  {
    //increment servo by 1 degree
    servo_arm1.write(fabs(counter));
    //servo_shoulder.write(fabs(counter));
    servo_base.write(fabs(counter));
    delay(100);
  }
  //flips initial and final rotation bounds
  int temp = rotStart;
  rotStart = rotEnd * -1;
  rotEnd = temp;
  */
}
