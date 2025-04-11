#include <Servo.h>

Servo servoOne;
int pos;

void setup() {
Serial.begin(9600);
servoOne.attach(3);
}

void loop() {
pos = analogRead(A0);
pos = map(pos, 0, 1023, 0, 180);
servoOne.write(pos);
Serial.print("Servo Position: ");
Serial.println(pos);
delay(100);
}
