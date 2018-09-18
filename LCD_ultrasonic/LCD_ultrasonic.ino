/*
 LCD 연결해서 글자 출력하기
 
 이 스케치는 KocoaFab에서 만들었습니다.
 이 스케치는 누구든 무료로 사용할 수 있습니다.
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,4,5,6,7);        //RS 핀, E핀, 데이터 핀 4개
String lcdString = "";                   //객체 선언 : 출력 할 글자 저장

int Trigpin = 8;  //쏘는거(방아쇠)
int EchoPin = 9;
int piezo = 6;

void setup() {                   
  lcd.begin(16,2);                       //LCD 크기 지정, 2줄 16칸
  lcd.clear();                           //화면 초기화
  Serial.begin(115200);                    //시리얼 통신 초기화
}

void loop() {
  float distance, duration;

  digitalWrite(Trigpin, 1);
  delayMicroseconds(10);
  digitalWrite(Trigpin, 0);
  duration = pulseIn(EchoPin, 1); //시간
//  Serial.println ("시간 : " + (String)duration); 
  distance = (duration*34000)/1000000/2; //거리
  Serial.println ("거리 : " + (String)distance + "cm"); 
  delay(500);
  
  lcd.setCursor(0,0);                    //커서를 0,0에 지정
   
  if(Serial.available()) {               //입력받은 데이터가 있으면
    delay(200);                          //0.2초 대기
    
    while(Serial.available() > 0) {      //문자 수 만큼 반복
      char lcdChar = (char)Serial.read();//문자 하나씩 읽고
      lcdString += lcdChar;              //읽은 문자를 하나씩 더해 문자열을 만듬
    }
    
    lcd.print((String)distance);                //문자열 LCD에 출력
    Serial.println((String)distance);           //시리얼 모니터에 입력한 값 출력
    lcdString = "";                      //문자열 초기화
    lcd.print("               ");        //전 글씨 삭제

//  if(distance < 150 && distance >= 10)
//  {
//     analogWrite(piezo, NOTE_C6);
//     delay(500);
//     analogWrite(piezo, 0);
//     delay(500);
//  }
//    else if(distance < 10)
//  {
//    analogWrite(piezo, NOTE_C6);
//    delay(200);
//    analogWrite(piezo, 0);
//    delay(200);
//  }
    
  }
}
