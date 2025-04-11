

#include <Servo.h>
Servo servoOne;
Servo servoTwo;


int thetaOne = 77;
int thetaTwo = 116;


void setup() {


servoOne.attach(3);
servoTwo.attach(5);
}


void loop() {
servoOne.write(thetaOne);
servoTwo.write(thetaTwo);
}
