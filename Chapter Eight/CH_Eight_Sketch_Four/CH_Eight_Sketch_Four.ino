#include <Servo.h>
Servo servoOne;
Servo servoTwo;
Servo servoThree;
Servo servoFour;
Servo servoFive;

int DT = 11;
int CLK = 12;
int SW = 13;
int currentStateCLK;
int lastStateCLK;
int posOne = 90;
int posTwo = 90;
int posThree = 90;
int posFour = 90;
int posFive = 90;
int motorSelector = 1;

void setup() {
  servoOne.attach(3);  
  servoTwo.attach(5);
  servoThree.attach(6);
  servoFour.attach(9);
  servoFive.attach(10);
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);
  lastStateCLK = digitalRead(CLK);
  Serial.begin(9600);
}

void loop() {
  currentStateCLK = digitalRead(CLK);
  if (currentStateCLK != lastStateCLK) {
    if (digitalRead(DT) == currentStateCLK) {
      if(motorSelector == 1){
      posOne-=5;
      }
      else if(motorSelector == 2){
      posTwo-=5;
      posThree+=5;
      }
      else if(motorSelector == 3){
      posFour-=5;
      }
      else if(motorSelector == 4){
      posFive-=5;
      }
    } else {
      if(motorSelector == 1){
      posOne+=5;
      }
      else if(motorSelector == 2){
      posTwo+=5;
      posThree-=5;
      }
      else if(motorSelector == 3){
      posFour+=5;
      }
  	  else if(motorSelector == 4){
      posFive+=5;
      }
    }
    servoOne.write(posOne);
    servoTwo.write(posTwo);
    servoThree.write(posThree);
    servoFour.write(posFour);
    servoFive.write(posFive);
    Serial.print("Servo One: ");
    Serial.print(posOne);
    Serial.print(" Servo Two: ");
    Serial.print(posTwo);
    Serial.print(" Servo Three: ");
    Serial.print(posThree);
    Serial.print(" Servo Four: ");
    Serial.print(posFour);
    Serial.print(" Servo Five: ");
    Serial.println(posFive);
  }

  lastStateCLK = currentStateCLK;
  int btnState = digitalRead(SW);

  if (btnState == LOW ) {
    motorSelector++;
   delay(250);
  }
  if(motorSelector == 5){
    motorSelector = 1;
  }
  delay(1);
}
