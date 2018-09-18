int Trigpin = 8;  //쏘는거(방아쇠)
int EchoPin = 9;
int piezo = 6;

#define NOTE_C6 1047

void setup() {
  pinMode(Trigpin, OUTPUT);
  pinMode(EchoPin, INPUT);
  pinMode(A0, INPUT);
  Serial.begin(115200);
}

void loop() {
  
  Ultrasonic(); //초음파
  Temperture();
}

void Ultrasonic()
{
  float distance, duration;
  //Trigpin 음파를 쏘아 Echo에서 받아 계산   
  // 속도 = 거리 / 시간  // 거리 = 시간 * 속도
  digitalWrite(Trigpin, 1);
  delayMicroseconds(10);
  digitalWrite(Trigpin, 0);
  duration = pulseIn(EchoPin, 1); //시간
//  Serial.println ("시간 : " + (String)duration); 
  distance = (duration*34000)/1000000/2; //거리
  Serial.println ("거리 : " + (String)distance + "cm"); 
  delay(500);

  if(distance < 150 && distance >= 10)
  {
     analogWrite(piezo, NOTE_C6);
     delay(500);
     analogWrite(piezo, 0);
     delay(500);
  } 
      else if(distance < 10)
  {
    analogWrite(piezo, NOTE_C6);
    delay(200);
    analogWrite(piezo, 0);
    delay(200);
  }
}

void Temperture()
{
   int value = analogRead(A0);
   float volt = value * 5.0/ 1024;
   float temper = (volt - 0.5)*100;
   
   Serial.print(volt);
   Serial.print("  V    ");
   Serial.print(temper);
   Serial.println("  C");
   delay(500);
}
