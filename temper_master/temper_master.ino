#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1);

void setup() {
 Serial.begin(9600);
 mySerial.begin(9600);
}

void loop() {

 if(mySerial.available())
   Serial.write(mySerial.read());
 delay(500);
}
