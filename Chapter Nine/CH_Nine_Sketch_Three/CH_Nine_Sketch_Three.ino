  #include <Servo.h>
  Servo servoOne;
  Servo servoTwo;
  Servo servoThree;
  Servo servoFour;
  Servo servoFive;

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
  Serial.begin(9600);
  }


void loop() {  
   int points[8][3] = {
    {0, 80, 120},
    {80, 80, 120},
    {80, 160, 120},
    {0, 160, 120},
    {0, 80, 200},
    {80, 80, 200},
    {80, 160, 200},
    {0, 160, 200}
  };  


  for (int i = 0; i < 8; i++) {
    x = points[i][0];
    y = points[i][1];
    z = points[i][2];
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
      alphaFinal = (alphaOne-alphaTwo)*(180/PI);
    }
    servoOne.write(theta);
    servoTwo.write(alphaFinal);
    servoThree.write(180-alphaFinal);
    servoFour.write(beta);
    Serial.print("Theta: ");
    Serial.print(theta);
    Serial.print(" Alpha: ");
    Serial.print(alphaFinal);
    Serial.print(" Beta: ");
    Serial.println(beta);
    delay(3000);
    }    
  }
