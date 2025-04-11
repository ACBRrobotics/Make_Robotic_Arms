#include <Servo.h>

int pos;

void setup() {
Serial.begin(9600);
}

void loop() {
pos = analogRead(A0);
pos = map(pos, 0, 1023, 0, 180);
Serial.print("Servo Position: ");
Serial.println(pos);
delay(100);
}
