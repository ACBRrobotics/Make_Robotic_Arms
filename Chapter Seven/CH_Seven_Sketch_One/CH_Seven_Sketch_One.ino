#include "Servo.h"
Servo servoOne;
Servo servoTwo;
Servo servoThree;
Servo servoFour;
Servo servoFive;


void setup() {
  servoOne.attach(3);
  servoTwo.attach(5);
  servoThree.attach(6);
  
  servoFour.attach(9);
  servoFive.attach(10);
}

void loop() {
  servoOne.write(90);
  servoTwo.write(90);
  servoThree.write(90);
  servoFour.write(180);
  servoFive.write(90);
}