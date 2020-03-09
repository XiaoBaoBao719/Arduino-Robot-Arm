#include <SoftwareSerial.h>
#include <Servo.h>

Servo servo_base;
Servo servo_shoulder;
Servo servo_arm1;
Servo servo_arm2;
Servo servo_arm3;

void setup() {
  // put your setup code here, to run once:
  servo_base.attach(3);
  servo_shoulder.attach(5);
  servo_arm1.attach(6);

  delay(1000);
  servo_base.write(90);
  //delay(5000);
  servo_shoulder.write(120);
  //delay(5000);
  servo_arm1.write(180);
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
  // put your main code here, to run repeatedly:
  //servo_shoulder.write(110);
  //delay(5000);
  //servo_shoulder.write(80);
  //delay(5000);
}
