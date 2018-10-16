int TrigPin = 8;
int EchoPin = 9;

void setup() {
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  float duration, distance;  // 실수형 변수 시간과 거리 선언.
  digitalWrite(TrigPin, HIGH);  // 초음파 발사
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  duration = pulseIn(EchoPin, HIGH); // 송신부에서 음파를 받아서 시간변수에 저장
  distance = (34000*duration)/1000000/2; // 340미터를 cm로 환산, 백만분의 1초(마이크로초), 속도가 왕복이기 때문에 2로 나눔.

  Serial.println("거리는: " + String(distance) + "cm");
  delay(100);
}
