#include <Servo.h>
Servo servo1;
Servo servo2;

void setup() {
  servo1.attach(3);  
  servo2.attach(5);
}

void loop() {
  servo1.write(90);
  servo2.write(90);
  delay(1000); 

  for (int pos = 0; pos <= 30; pos++) {
    servo1.write(90 + pos); 
    servo2.write(90 - pos);  
    delay(100);  
  }

  for (int pos = 30; pos >= 0; pos--) {
    servo1.write(90 + pos); 
    servo2.write(90 - pos);  
    delay(100);  
  }
  delay(1000); 
}