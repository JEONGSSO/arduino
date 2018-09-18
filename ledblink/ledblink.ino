int led3 = 3;
int delayTime;

void setup() {
  pinMode(led3, OUTPUT);
}
void loop() {
  ledd(200);
  ledd(500);
  ledd(200);
  delay(1000);
}

void ledd(int delayTime)
{
  for(int i = 0 ; i < 3 ; ++i)
  {
    digitalWrite(led3, HIGH);
    delay(delayTime);
    digitalWrite(led3, LOW);
    delay(delayTime);
  }
}
