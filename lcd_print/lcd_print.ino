#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 4, 5, 6, 7);
int Trigpin = 8;  //쏘는거(방아쇠)
int EchoPin = 9;
int piezo = 6;


void setup() {
  lcd.begin(16, 2);
  pinMode(Trigpin, OUTPUT);
  pinMode(EchoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
   float distance, duration;
   digitalWrite(Trigpin, 1);
  delayMicroseconds(10);
  digitalWrite(Trigpin, 0);
  duration = pulseIn(EchoPin, 1); //시간
  //Serial.println ("시간 : " + (String)duration); 
  distance = (duration*34000)/1000000/2; //거리
  lcd.println ("dis : " + (String)distance + "cm"); 
  delay(500);
  lcd.clear();
  
//  lcd.setCursor(5,0);
//  lcd.print("Hello");
//  lcd.setCursor(4, 1);
//  lcd.print("Arduino");
//  delay(2000);
//  lcd.clear();
//  lcd.setCursor(3, 0);
//  lcd.print("Thank You");
//  
//  delay(2000);
//  lcd.clear();
}
