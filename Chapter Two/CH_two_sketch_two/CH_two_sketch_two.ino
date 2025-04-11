#include <Servo.h>

Servo servoOne;
Servo servoTwo;

int randomOne;
int randomTwo;

void setup() {
servoOne.attach(3);
servoTwo.attach(5);
randomSeed(analogRead(A0));
randomOne = random(45,90);
randomTwo = random(90,180);
servoOne.write(randomOne);
servoTwo.write(randomTwo);
}

void loop() {

}
