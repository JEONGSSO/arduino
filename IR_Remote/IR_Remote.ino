#include <IRremote.h>

int RECV_PIN = 11;  //적외선 수신기의 데이터 핀
int led = 2;

IRrecv irrecv(RECV_PIN);  //적외선 초기화
decode_results results; //수신데이터

void setup() {
  Serial.begin(9600); 
  irrecv.enableIRIn();  //적외선 수신기 시작
  pinMode(led, OUTPUT);
}

void loop() {
  if(irrecv.decode(&results))//디코딩 결과
  {
  int res = results.value;
    if(res == 0x6897) 
      digitalWrite(led, HIGH);
    else if(res == 0xFFFF9867)
      digitalWrite(led, LOW);
    else if (res == 0xFFB04F)
      digitalWrite(3, HIGH);
    else if(res == 0xFF30CF)
      digitalWrite(3, LOW);
        
    Serial.print("리시브 데이터 : 0x");
    Serial.println(results.value, HEX); //HEX 16진수 DEC 10진수 BIN 2진수 출력 
    irrecv.resume();  //다음데이터 수신
    } 
    delay(200);
  }
