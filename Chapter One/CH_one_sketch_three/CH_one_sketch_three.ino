int btn;

void setup() {
Serial.begin(9600);
pinMode(2, INPUT_PULLUP);
}
void loop() {
btn = digitalRead(2);
Serial.println(btn);
delay(100);
}
