#include <SoftwareSerial.h>

SoftwareSerial BT(2,3); //RX, TX
int led = 7;
String str ="";
char data ;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  BT.begin(9600);
//  Serial.println("연결 됨");
}

void loop() { 
  while (BT.available())  //블루투스 사용하는동안
  {
     data = (char)BT.read();
     str += data;
     delay(5);
    if (data == 'a')
    {
      digitalWrite(led, 1);
    }
    else if (data == 's')
    {
      digitalWrite(led, 0);
    }
    delay(100);
} 
  if(!str.equals(""))  //myString 값이 있다면
  {
    Serial.println(str); //시리얼모니터에 myString값 출력
    str="";  //myString 변수값 초기화
  }
}
