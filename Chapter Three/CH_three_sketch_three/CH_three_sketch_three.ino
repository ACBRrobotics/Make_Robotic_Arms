

#include <Servo.h>
Servo servoOne;
Servo servoTwo;
double x = 120.0;
double y = 120.0;
double linkOne = 100.0;
double linkTwo = 100.0;
double thetaOne;
double thetaTwo;


void setup() {
  Serial.begin(9600);
  servoOne.attach(3);
  servoTwo.attach(5);
}


void loop()
{
 
  thetaOne = (atan(y/x) + acos(((linkTwo*linkTwo)
             -((x*x)+(y*y))-(linkOne*linkOne))/
             (-2*(linkOne)*(sqrt((x*x)+(y*y))))));


  double thetaOneDeg = (thetaOne*(180/PI));
  thetaTwo = (acos((((x*x)+(y*y))-(linkTwo*linkTwo)
            -(linkOne*linkOne)) / (-2*(linkOne)*(linkTwo))));
  double thetaTwoDeg = (thetaTwo*(180/PI));
  servoOne.write(thetaOneDeg);
  servoTwo.write(thetaTwoDeg);
 
  Serial.print("Theta One: ");
  Serial.print(thetaOneDeg);
  Serial.print(" Theta Two: ");
  Serial.println(thetaTwoDeg);
  delay(100);
}
