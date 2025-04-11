

#include "Servo.h"
Servo servo1;
Servo servo2;


int count;


void setup() {
  servo1.attach(3);
  servo2.attach(5);
 
 Serial.begin(9600);
}


void loop() {
 
  servo1.write(90);
  servo2.write(90);
 
  for (count = 90; count < 180; count++) {
    Serial.print("Servo One Position: ");
    Serial.println(count);
    servo1.write(count);
    delay(10);
    }
  for (count = 180; count > 90; count--) {
    Serial.print("Servo One Position: ");
    Serial.println(count);
    servo1.write(count);
    delay(10);
    
    }

  for (count = 90; count > 0; count--) {
    Serial.print("Servo Two Position: ");
    Serial.println(count);
    servo2.write(count);
    delay(10);
    }
  for (count = 0; count < 90; count++) {
    Serial.print("Servo Two Position: ");
    Serial.println(count);
    servo2.write(count);
    delay(10);
    }
}
