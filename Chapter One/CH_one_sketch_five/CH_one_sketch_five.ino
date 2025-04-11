#include <Servo.h>

int pos;
void setup() {
Serial.begin(9600);
}

void loop() {
pos = analogRead(A0);
Serial.println(pos);
delay(100);
}
