#include <Servo.h>


Servo servoOne;
Servo servoTwo;
int posOne;
int posTwo;


void setup() {
Serial.begin(9600);
servoOne.attach(3);
servoTwo.attach(5);
}


void loop() {
posOne = analogRead(A0);
posOne = map(posOne, 0, 1023, 0, 180);
posTwo = analogRead(A1);
posTwo = map(posTwo, 0, 1023, 0, 180);
servoOne.write(posOne);
servoTwo.write(posTwo);
Serial.print("Servo One: ");
Serial.print(posOne);
Serial.print(" Servo Two: ");
Serial.println(posTwo);
delay(100);
}
