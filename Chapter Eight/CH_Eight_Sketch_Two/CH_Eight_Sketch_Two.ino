

#include <Servo.h>
Servo servoOne;
Servo servoTwo;
Servo servoThree;
Servo servoFour;
Servo servoFive;


int DT = 11;
int CLK = 12;
int SW = 13;
int posOne = 90;


int posTwo = 90;
int posThree = 90;
int posFour = 90;
int posFive = 90;
int currentStateCLK;
int lastStateCLK;


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
      posOne--;
    } else {
      posOne++;
    }
    servoOne.write(posOne);
    servoTwo.write(posTwo);
    servoThree.write(posThree);
    servoFour.write(posFour);
    servoFive.write(posFive);
    Serial.print("Servo One: ");
    Serial.println(posOne);
  }


  lastStateCLK = currentStateCLK;
  int btnState = digitalRead(SW);


  if (btnState == LOW ) {
    Serial.println("Button pressed!");
    delay(100);
  }
  delay(1);
}
