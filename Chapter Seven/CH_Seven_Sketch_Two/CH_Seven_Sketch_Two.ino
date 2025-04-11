#include <Servo.h>
Servo servoOne;  

int pos;    

void setup() {
  servoOne.attach(3);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 0; pos <= 90; pos += 1) {
    servoOne.write(pos);            
    delay(50);                
  }
  for (pos = 90; pos >= 0; pos -= 1) {
    servoOne.write(pos);          
    delay(50);                      
  }
}
