int TrigPin = 8;
int EchoPin = 9;
int LED = 10;
int Speaker = 11;

void setup() {
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(Speaker, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  float duration, distance;  // 실수형 변수 시간과 거리 선언.
  digitalWrite(TrigPin, HIGH);  // 초음파 발사
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  duration = pulseIn(EchoPin, HIGH); // 송신부에서 음파를 받아서 시간변수에 저장
  distance = (34000*duration)/1000000/2; // 340미터를 cm로 환산, 백만분의 1초(마이크로초), 속도가 왕복이기 때문에 2로 나눔.
 
  if(distance<=30 && distance>20)
  {
    flash(250);
    beat(1, 250);
    
  }
  else if(distance<=20 && distance>10)
  {
    flash(100);
    beat(2, 100);
  }
  else if(distance<=10 && distance>0)
  {
    flash(30);
    beat(3, 30);
  }
  else
  {
    flash(0);
    beat(0,0);
  }
  
  
  Serial.println("거리는: " + String(distance) + "cm");
  delay(10);
}
void flash(int i)
{
  digitalWrite(LED, HIGH);
  delay(i);
  digitalWrite(LED, LOW);
  delay(i);
}

void beat(int n, int t)
{
  for(int j=0; j<n; j++)
  {
    analogWrite(Speaker, 255);
    delay(t);
    analogWrite(Speaker, 0);
    delay(t);
  }
}
