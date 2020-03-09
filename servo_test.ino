#include <Servo.h>

Servo servo_3;
//Servo servo_10;
//Servo servo_11;

void setup() {
  // put your setup code here, to run once:
  servo_3.attach(3); //attach to pin 3 PWM
  //servo_10.attach(10);
  //servo_11.attach(11);
}

void loop() {
  // put your main code here, to run repeatedly:
  //.write(180);
  //servo_5.write(180);
  //delay(5000);
  servo_3.write(0);
  //servo_10.write(0);
  //servo_11.write(0);
  delay(2500);
  servo_3.write(170);
  //servo_10.write(180);
  //servo_11.write(180);
  delay(30000);
}
