#include <Servo.h>


Servo servoOne;


int btnOne;
int btnTwo;
int pos = 90;


void setup() {
Serial.begin(9600);
pinMode(2, INPUT_PULLUP);
pinMode(4, INPUT_PULLUP);
servoOne.attach(3);
}


void loop() {
btnOne = digitalRead(2);
btnTwo = digitalRead(4);


if(btnOne == LOW){
  pos++;
  delay(50);
}
else if(btnTwo == LOW){
  pos--;
  delay(50);
}
servoOne.write(pos);
}
