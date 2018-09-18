#include <SoftwareSerial.h>

SoftwareSerial BT(2,3); //RX, TX
int pins[] = {7, 8, 9, 10};
String str ="";
char data ;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  for(int i = 0 ; i < 4; ++i)
  {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], 0);
  }
}

void loop() {
  if(BT.available()) 
  {
    data = (char)BT.read();
    if(data < 0 || data > 255) //번위 검사
    Serial.println("Wrong");

    else
    {
      for(int i = 0 ; i < 4; ++i)
      {
        if (data & (1 << i))
          digitalWrite(pins[i], 1);
        else 
          digitalWrite(pins[i], 0);
      }
    }
  }
}
