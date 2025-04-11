int DT = 11;
int CLK = 12;
int SW = 13;
int counter = 0;
int currentStateCLK;
int lastStateCLK;


void setup() {
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  pinMode(SW, INPUT_PULLUP);
  lastStateCLK = digitalRead(CLK);
  
  Serial.begin(9600);
}

void loop() {
  currentStateCLK = digitalRead(CLK);
  if (currentStateCLK != lastStateCLK) {
    if (digitalRead(DT) == currentStateCLK) {
      counter--;
    } else {
      counter++;
    }
    Serial.print("Counter: ");
    Serial.println(counter);
  }


  lastStateCLK = currentStateCLK;
  int btnState = digitalRead(SW);
  
  if (btnState == LOW ) {
    Serial.println("Button Pressed!");
    delay(100);
  }
  delay(1);
}
