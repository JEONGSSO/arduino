#include <SoftwareSerial.h>
SoftwareSerial BTSerial(11, 12); // rx , tx
String myString = "";

char data2;
int Ain1 =7;
int Ain2 =8;
int pwmA =9;
int Bin1 =5;
int Bin2 =4;
int pwmB =3;
void setup() {
  pinMode(Ain1, OUTPUT);
  pinMode(Ain2, OUTPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(Bin1, OUTPUT);
  pinMode(Bin2, OUTPUT);
  pinMode(pwmB, OUTPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  if(BTSerial.available()){
    data2 = BTSerial.read();
    myString += data2;
    delay(5);
  }
  if(!myString.equals("")){ // myString이 공백이 아니다
    Serial.println(myString);
    myString = "";
  }
  if(BTSerial.available()){
    char data = BTSerial.read();
    switch(data){
      case '1':  //직진
        rotate(1, 0, 255, 255);
        break;
      case '2': // 후진
       rotate(0, 1, 255, 255);
        break;
      case '3': // 정지
        rotate(0,0,0,0);
        break;
      case '4': // 직우회전
        rotate(1, 0, 255, 0); 
        break;
        case '5': // 직좌회전
        rotate(1, 0, 0, 255);
        break;
        }
  }
}

void rotate(int i, int j, int left, int right){
digitalWrite(Ain1, i);
digitalWrite(Ain2, j);
analogWrite(pwmA, left);
digitalWrite(Bin1, i);
digitalWrite(Bin2, j);
analogWrite(pwmB, right);
}
