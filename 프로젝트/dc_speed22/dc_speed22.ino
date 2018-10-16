int Trigpin = 10;  //쏘는거(방아쇠)
int EchoPin = 9;

void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
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
//  delay(500);

//  if(distance < 150 && distance >= 10)

  if(distance > 15) // 16cm 이상일때 앞으로
      Foward();
        
   else if(distance < 10) //10cm 미만일때 후진 과 스톱
  {    
    Back();
    Stop();
  }
}

void Foward()
{
  digitalWrite(7, 0);   
        digitalWrite(8, 1);   
        analogWrite(3, 255);
        delay(15);

        digitalWrite(5, 1);
        digitalWrite(6, 0);   
        analogWrite(11, 255);
        delay(1000);
}

void Back()
{
     digitalWrite(7, 1);   
        digitalWrite(8, 0);   
        analogWrite(3, 255);
        delay(1000);    //한쪽바퀴만 움직여 방향 전환. 1초동안 7, 8번만 움직이고 그 다음 5, 6번 핀이 작동

        digitalWrite(5, 0);
        digitalWrite(6, 1);   
        analogWrite(11, 255);
        delay(1000);  //1초동안 후진
}

void Stop()
{
      //멈춤
        digitalWrite(7, LOW);
        digitalWrite(8, LOW);
        analogWrite(3, 0);
        analogWrite(11, 0);
        
        delay(500);
}
