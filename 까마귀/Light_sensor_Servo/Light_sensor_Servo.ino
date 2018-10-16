#include <Servo.h>
int LS = A1;
Servo myServo;

void setup() {
  myServo.attach(5);
  pinMode(LS, INPUT);

}

void loop() {
  int value = analogRead(LS);
  int angle = map(value, 0, 1023, 0, 180);
  myServo.write(angle);
  delay(20);
}
