#include <Servo.h>
Servo servoOne;
Servo servoTwo;
int posOne = 90;
int posTwo = 90;
int joyX;
int joyY;

void setup()
{
Serial.begin(9600);
servoOne.attach(3);
servoTwo.attach(5);
}

void loop() {
joyX = analogRead(A0);
joyY = analogRead(A1);
if(joyX > 800){
  posOne++;
  delay(10);
}
if(joyX < 400){
  posOne--;
  delay(10);
}
if(joyY > 800){
  posTwo++;
  delay(10);
}
if(joyY < 400){
  posTwo--;
  delay(10);
}
Serial.print("Position One: ");
servoOne.write(posOne);
Serial.print(posOne);
Serial.print(" Position Two: ");
servoTwo.write(posTwo);
Serial.println(posTwo);
}
