int Trigpin = 10;  //쏘는거(방아쇠)
int EchoPin = 9;

void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(Trigpin, OUTPUT);
  pinMode(EchoPin, INPUT);
  Serial.begin(115200);
}
 
void loop() 
{
  float distance, duration;

  digitalWrite(Trigpin, 1);
  delayMicroseconds(10);
  digitalWrite(Trigpin, 0);
  duration = pulseIn(EchoPin, 1); //시간
//  Serial.println ("시간 : " + (String)duration); 
  distance = (duration*34000)/1000000/2; //거리
  Serial.println ("거리 : " + (String)distance + "cm"); 
  delay(500);

//  if(distance < 150 && distance >= 10)
  if(distance > 20)
  {
     //최대속도의 50% 역회전
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        analogWrite(6, 127);
        delay(1000);
  }
   else if(distance < 10)
  {
    //최대속도의 50%로 정회전
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        analogWrite(6, 0);
        delay(1000);
  }
//        //최대속도의 50%로 정회전
//        digitalWrite(7, HIGH);
//        digitalWrite(8, LOW);
//        analogWrite(6, 33);
//        delay(3000);
 
//        //최대속도의 50% 역회전
//        digitalWrite(7, LOW);
//        digitalWrite(8, HIGH);
//        analogWrite(6, 33);
//        delay(3000);
 
//        //최대속도로 정회전
//        digitalWrite(7, HIGH);
//        digitalWrite(8, LOW);
//        analogWrite(6, 255);
//        delay(3000);
// 
//        //최대속도로 역회전
//        digitalWrite(7, LOW);
//        digitalWrite(8, HIGH);
//        analogWrite(6, 255);
//        delay(3000);
 
        //정지 (7번핀에 HIGH를 주어도 PWM 핀에 값을 0을 주었기 때문에 정지함)
//        digitalWrite(7, HIGH);
//        digitalWrite(8, LOW);
//        analogWrite(6, 0);
//        delay(3000);

        
}
