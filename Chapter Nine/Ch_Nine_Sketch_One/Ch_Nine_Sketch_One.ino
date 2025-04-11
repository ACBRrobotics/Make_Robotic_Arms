  double linkOne = 48.0;
  double linkTwo = 120.0;
  double linkThree = 100.0;  
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
   Serial.begin(9600);
  }

void loop() {                 
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

  Serial.print("Theta: ");
  Serial.print(theta);
  Serial.print(" Alpha: ");
  Serial.print(alphaFinal);
  Serial.print(" Beta: ");
  Serial.println(beta);
  delay(100);
}

