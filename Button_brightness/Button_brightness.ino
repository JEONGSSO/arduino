int btn = 2;
int led = 3;

int value = 0;
int oldVal = 0;
int ledstate = 0;

unsigned long startTime = 0; //버튼을 누르기 시작한 시간
int brightness = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT);
}

void loop() {
  value = digitalRead(btn);
  if(value == 1 && oldVal ==0)
  {
    ledstate = 1 - ledstate;
    startTime = millis();
    delay(10);
  }
  
  if(value == 1 && (millis() - startTime) > 500)
  {
    brightness++;
    delay(10);

    if(brightness > 255)
        brightness = 0;
  }
    oldVal = value;

  if(ledstate == 1)
    analogWrite(led, brightness);
  else
    analogWrite(led, 0);
}
