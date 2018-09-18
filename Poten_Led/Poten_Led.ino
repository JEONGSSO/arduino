#include <Servo.h>
Servo sv;

int poten = A0;
int led = 3;


void setup() {
  pinMode(led, OUTPUT);
  pinMode(poten, INPUT);
  sv.attach(9);
  Serial.begin(9600);
}
void loop() 
{
  int potenVal = analogRead(potenVal);
  int potenVal_map = map(potenVal, 0, 1023, 0, 255);
  Serial.println(potenVal_map);
  delay(10);
  
  Poten_Led(potenVal_map);  //led 포텐시오미터로 제어
  Poten_Servo(potenVal_map);
}
 
  void Poten_Servo(int potenVal)
  {
    sv.write(potenVal);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  void Poten_Led(int brightness)
  {
  analogWrite(led, brightness);

//  if(potenVal > 100)
//    analogWrite(led, brightness);
//  else
//    analogWrite(led, 0);
  }
