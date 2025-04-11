#include <Servo.h>

Servo servoOne;
Servo servoTwo;

int joyX;
int joyY;


void setup() {
Serial.begin(9600);
servoOne.attach(3);
servoTwo.attach(5);
}

void loop() {
joyX = analogRead(A0);
joyX = map(joyX, 0, 1023, 90, 135);
joyY = analogRead(A1);
joyY = map(joyY, 0, 1023, 45, 90);
Serial.print("Joystick X Value:");
Serial.print(joyX);
Serial.print(" Joystick Y Value:");
Serial.println(joyY);
servoOne.write(joyX);
servoTwo.write(joyY);
delay(100);
}
