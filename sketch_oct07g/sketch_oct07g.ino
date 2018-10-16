int led_pin = 13;       //LED 핀 번호
int motion_pin = A0;    //인체감지 센서 핀 번호
 
void setup()
{
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);     //LED 핀을 출력으로 설정
  pinMode(motion_pin, INPUT);   //인체감지센서 입력핀 설정
}
 
void loop()
{
  Serial.println(analogRead(motion_pin));
  if(digitalRead(motion_pin) == 1)  //인체감지 센서에서 움직임이 감지되면 수행
  {
     digitalWrite(led_pin, HIGH);       //LED를 켬
     Serial.println("Motion detected!");//"Motion detected!"출력
     
  }
  else  //움직임이 없는경우 수행
  {
    digitalWrite(led_pin, LOW);         //LED를 끔
  }
  delay(500);
}
