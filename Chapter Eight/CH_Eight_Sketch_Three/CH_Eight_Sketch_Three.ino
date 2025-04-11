int motorSelector = 1;
int btnVal;


void setup() {
Serial.begin(9600);
pinMode(13, INPUT_PULLUP);
}


void loop() {
btnVal = digitalRead(13);


if(btnVal == LOW){
  motorSelector++;
  delay(250);
}


if(motorSelector == 6){
  motorSelector = 1;
}
Serial.print("Active Motor: ");
Serial.println(motorSelector);
}
