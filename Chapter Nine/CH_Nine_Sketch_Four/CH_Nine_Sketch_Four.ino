 
  #include <Servo.h>
  Servo servoOne;
  Servo servoTwo;
  Servo servoThree;
  Servo servoFour;
  Servo servoFive;
  int claw = 90;
  int DT = 11;
  int CLK = 12;
  int SW = 13;
  int currentStateCLK;
  int lastStateCLK;
  int valueSelector = 1;
  double linkOne = 48.0;
  double linkTwo = 120.0;
  double linkThree = 150.0;  
  double x = 120.0;
  double y = 120.0;
  double z = 120.0;
  double c;
  double d;
  double Zoffset;
  double theta;
  double alphaOne;
  double alphaTwo;
  double alphaFinal;
  double beta;


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
  int btnState = digitalRead(SW); 
  if (btnState == LOW ) {
    valueSelector++;
    delay(250);
  }
  if(valueSelector == 5){
    valueSelector = 1;
  }
  if (currentStateCLK != lastStateCLK) {
    if (digitalRead(DT) == currentStateCLK) {
      if(valueSelector == 1){
      x-=5;
      }
      else if(valueSelector == 2){
      y-=5;
      }
      else if(valueSelector == 3){
      z-=5;
      }
      else if(valueSelector == 4){
      claw-=5;
      }
    } else {
      if(valueSelector == 1){
      x+=5;
      }
      else if(valueSelector == 2){
      y+=5;
      }
      else if(valueSelector == 3){
      z+=5;
      }
      else if(valueSelector == 4){
      claw+=5;
      }
    }
  lastStateCLK = currentStateCLK;

  d = sqrt((x*x)+(y*y));
  theta = atan(y/x)*(180/PI);
  Zoffset = (z - linkOne);
  c = sqrt((d*d)+(Zoffset*Zoffset));
  beta = acos((linkTwo*linkTwo + linkThree*linkThree -
  c*c)/(2*linkTwo*linkThree))*(180/PI);        
  alphaOne = acos(d/c);
  alphaTwo = acos((linkTwo*linkTwo + c*c -
  linkThree*linkThree)/(2*linkTwo*c));
  if(z > linkOne){
    alphaFinal = (alphaOne+alphaTwo)*(180/PI);
  }
  else if(z < linkOne){
    alphaFinal = -1 * (alphaOne-alphaTwo)*(180/PI);
  }
  servoOne.write(theta);
  servoTwo.write(alphaFinal);
  servoThree.write(180-alphaFinal);
  servoFour.write(beta);
  servoFive.write(claw);
  Serial.print("Value Selector: ");
  Serial.print(valueSelector);
  Serial.print(" Theta: ");
  Serial.print(theta);
  Serial.print(" Alpha: ");
  Serial.print(alphaFinal);
  Serial.print(" Beta: ");
  Serial.println(beta);
}
}
