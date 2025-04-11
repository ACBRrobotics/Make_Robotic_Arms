#include "Servo.h"
Servo servoOne;
Servo servoTwo;
int posOne = 90;
int posTwo = 180;
int btnOne;
int btnTwo;
int btnThree;
int btnFour;

void setup() {
pinMode(6, INPUT_PULLUP);
pinMode(7, INPUT_PULLUP);
pinMode(8, INPUT_PULLUP);
pinMode(9, INPUT_PULLUP);
servoOne.attach(3);
servoTwo.attach(5);
}

void loop() {
btnOne = digitalRead(6);
btnTwo = digitalRead(7);
btnThree = digitalRead(8);
btnFour = digitalRead(9);

if(btnOne == LOW){
  posOne--;
  delay(10);
}

if(btnTwo == LOW){
  posOne++;
  delay(10);
}

if(btnThree == LOW){
  posTwo--;
  delay(10);
}

if(btnFour == LOW){
  posTwo++;
  delay(10);
}

servoOne.write(posOne);
servoTwo.write(posTwo);
}
