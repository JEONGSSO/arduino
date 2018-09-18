#include <Servo.h>
Servo sv;

int poten = A0;
int led = 3;
int serialVal = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(poten, INPUT);
  sv.attach(9);
  Serial.begin(9600);
}
void loop() 
{
  int potenVal = analogRead(potenVal);
  int brightness = map(potenVal, 0, 1023, 0, 255);
  int moving = map(potenVal, 0, 1023, 0, 179);
  
  serialVal = Serial.read();  //형변환 필요
//  Serial.println(serialVal);
//  delay(300);
  
  Poten_Led(brightness);  //led 포텐시오미터로 제어
  Poten_Servo(moving, serialVal);
}
 
void Poten_Servo(int moving, int serialVal)
{
  int degree = 0;
      if(serialVal == 48) //0 아스키코드
      {
        while (degree < 179)  //디지털 서보
        {
          sv.attach(9);
          sv.write(degree++);
          delay(15);
        }
         sv.detach();
      }
      
      else if(serialVal == 49)  //1 아스키코드
      {
        sv.attach(9);
        sv.write(0);
        delay(15);
        sv.detach();
      }
}

void Poten_Led(int brightness)
{
  analogWrite(led, brightness);
//  if(potenVal > 100)
//    analogWrite(led, brightness);
//  else
//    analogWrite(led, 0);
}
