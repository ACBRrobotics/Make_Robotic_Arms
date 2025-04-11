

#include <Servo.h>


Servo servoOne;  
Servo servoTwo;
Servo servoThree;


int pos;    


void setup() {
  servoOne.attach(3);  
  servoTwo.attach(5);
  servoThree.attach(6);
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
}
