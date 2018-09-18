int button =2;
int ledG = 9;
int ledR = 10;

void setup() {
  pinMode(button, INPUT);  // 풀다운 저항연결. 버튼
  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int value = digitalRead(button);
  Serial.println(value);
  delay(100);
  if(value == 1)
  {
    digitalWrite(ledG, HIGH);
    //delay(100);
    //digitalWrite(ledG, LOW);
    //delay(100);
  }
  else
  {
    //digitalWrite(ledR, HIGH);
    //delay(100);
    digitalWrite(ledG, LOW);
    //delay(100);  
  }

}
