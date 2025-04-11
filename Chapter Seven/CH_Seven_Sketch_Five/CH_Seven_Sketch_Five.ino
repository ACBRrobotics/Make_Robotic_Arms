

#include <Servo.h>


Servo servoOne;  
Servo servoTwo;
Servo servoThree;
Servo servoFour;
Servo servoFive;


int pos;    


void setup() {
  servoOne.attach(3);  
  servoTwo.attach(5);
  servoThree.attach(6);
  servoFour.attach(9);
  servoFive.attach(10);
}


void loop() {
  for (pos = 0; pos <= 90; pos++) {
    servoOne.write(pos);            
    delay(50);                
  }
  for (pos = 90; pos >= 0; pos--) {
    servoOne.write(pos);          
    delay(50);                      
  }
  for (pos = 0; pos <= 90; pos++) {
    servoTwo.write(45 + pos);  
    servoThree.write(135 - pos);  
    delay(50); 
  }
  for (pos = 0; pos <= 90; pos++) {
    servoTwo.write(135 - pos);  
    servoThree.write(45 + pos);   
    delay(50);  
  }
  for (pos = 45; pos <= 135; pos++) {
    servoFour.write(pos);            
    delay(50);                
  }
  for (pos = 135; pos >= 45; pos--) {
    servoFour.write(pos);          
    delay(50);                      
  }
  for (pos = 45; pos <= 135; pos++) {
    servoFive.write(pos);            
    delay(50);                
  }
  for (pos = 135; pos >= 45; pos--) {
    servoFive.write(pos);          
    delay(50);                      
  }
}
