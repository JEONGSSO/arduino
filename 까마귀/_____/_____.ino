int button =2;
int led = 9;
int OldValue = 0;
int ledState = 0; // 0이면 꺼진상태, 1이면 켜기

void setup() {
  pinMode(button, INPUT);  // 풀다운 저항연결. 버튼
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int value = digitalRead(button);
  
  if(value == 1 && OldValue ==0)
  {
    ledState = 1 - ledState;
  }
  
  OldValue = value;
  
  if(ledState ==1){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }

}
