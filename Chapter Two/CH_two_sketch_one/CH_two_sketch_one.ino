#include <Servo.h>

Servo servoOne;
Servo servoTwo;

void setup() {
servoOne.attach(3);
servoTwo.attach(5);
}
void loop() {
servoOne.write(90);
servoTwo.write(180);
}
