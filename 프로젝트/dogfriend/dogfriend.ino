#include <SoftwareSerial.h>
SoftwareSerial BT(13, 12); // RX, TX 

int Trigpin = 10;  //쏘는거(방아쇠)
int EchoPin = 9;

String str =""; //블루투스 신호 문자로받기
char BTdata;     //블루투스 신호 문자로받기

boolean Moving; // 자동모드 동작 유지

void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT); //모터 바퀴 핀들
   
  pinMode(Trigpin, OUTPUT);
  pinMode(EchoPin, INPUT);  //초음파 센서 
  
  Serial.begin(9600);
  BT.begin(9600);     //115200하면 블루투스가 되다가 안됐다가 한다>
}
 
void loop() //오른쪽 모터 하나가 힘이 약하다.
{
//   while (BT.available()) // 블루투스 사용
//   {
//      BTdata = (char)BT.read(); //BT값 받기
//      delay(10);
//      
//      if(BTdata == 'a')  //만약에 'a'가 입력되면 자동모드로
//        {
//          Moving = true;  // 자동 움직임 유지
          autoMode();
//        }
//    }
}

/*
//----------------------------수동모드------------------------------
while (BTdata == 'm') 
{
  if
}
  manualMode();
}

void manualFoword()  
{
  
}

void manualBack()  
{
  
}

void Right()  
{
  
}

void Left()  
{
  
}
*/
//-------------------------------수동모드 끝---------------------------
/*
void melody() //음악
{
  
}

void ballTrigger() // 투석기
{
  
}

void Pressure()   //압력 
{
  
}
*/

//========================구현완료========================

//----------------------자동모드------------------------
void autoMode()             
{
//  while(Moving) 1008 블루투스 일단삭제
//  {
//     BTdata = (char)BT.read(); //BT값 받기
//     delay(10);
//
//     if (BTdata == 's')
//       {
//         Moving = false;
//         Serial.println ("Stop"); 
//       }

    float distance, duration;   //거리, 시간
    digitalWrite(Trigpin, 1);
    delayMicroseconds(10);
    digitalWrite(Trigpin, 0);
    duration = pulseIn(EchoPin, 1); //시간
    distance = (duration*34000)/1000000/2; //거리 계산
    Serial.println ("거리 : " + (String)distance + "cm"); 
    delay(15); // 주석한이유는 거리탐지 딜레이 때문에
    
     if(distance > 15) // 16cm 이상
     {
       autoFoward();
       if(Moving == false)
        Stop();
     }
        
     else if(distance <= 15) //15cm 이하
    {    
      autoBack();
      Stop();
      if(Moving == false)
        Stop();
    }
//  }
}
void autoFoward() 
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

void autoBack()
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
//--------------------------자동모드 끝----------------------------------

void Stop() //자동, 수동 멈춤
{
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    analogWrite(3, 0);
    analogWrite(11, 0);
    delay(500);
}
