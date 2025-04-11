int joyX;
int joyY;

void setup() {
Serial.begin(9600);
}


void loop() {
joyX = analogRead(A0);
joyY = analogRead(A1);
Serial.print("Joystick X Value: ");
Serial.print(joyX);
Serial.print(" Joystick Y Value: ");
Serial.println(joyY);
delay(10);
}
