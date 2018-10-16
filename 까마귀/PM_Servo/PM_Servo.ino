#include <Servo.h>
int PM = A0;
Servo myServo;

void setup() {
  myServo.attach(5);
  pinMode(PM, INPUT);
  
}

void loop() {
  int value = analogRead(PM);
  int angle = map(value, 0, 1023, 0, 180);
  
  myServo.write(angle);
  delay(20);

}
