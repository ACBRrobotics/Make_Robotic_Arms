#include "Servo.h"

Servo servoOne;
void setup() {
servoOne.attach(3);
}
void loop() {
servoOne.write(0);
delay(2000);
servoOne.write(180);
delay(2000);
}
