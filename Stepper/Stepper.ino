#include <Stepper.h>
const int stepRevo = 2048; //360도 회전 1024 180도
Stepper steps(stepRevo, 8, 10, 9, 11);  //in 1, in 3, in2, in4

void setup() {
  steps.setSpeed(12);
  Serial.begin(9600);
}

void loop() {

  Serial.println(" + direction " ); //시계 방향 CW
  steps.step(stepRevo);
  delay(500);

  Serial.println(" + direction " );  //반시계  CCW
  steps.step(-stepRevo);
  delay(500);
}
