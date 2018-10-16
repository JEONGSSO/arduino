#include <Servo.h>
Servo myServo;

void setup() {
  myServo.attach(5);

}

void loop() {
  //myServo.write(0); // 괄호안이 각도
  //delay(1000);
  //myServo.write(10);
  //delay(1000);

  int angle;
  for(angle=0; angle<180; angle++)
  {
    myServo.write(angle);
    delay(50);
  }
  delay(1000);
  for(angle=180; angle>=0; angle--)
  {
    myServo.write(angle);
    delay(50);
  }
  delay(1000);

}
