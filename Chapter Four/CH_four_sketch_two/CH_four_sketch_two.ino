

int count;


void setup() {
Serial.begin(9600);
}


void loop() {
   for (count = 0; count < 90; count++) {
  Serial.print("Our for loop is counting up! ");
    Serial.println(count);
    delay(100);
  }


  for (count = 90; count > 0; count--) {
  Serial.print("Our for loop is counting down! ");
    Serial.println(count);
    delay(100);
  }
}
