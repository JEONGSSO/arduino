int arr[] = {200, 200, 200, 500, 500, 500, 200, 200, 200};
int led3 = 3;
int delayTime;
int speaker = 5;

void setup() {
  pinMode(led3, OUTPUT);
  
}
void loop() {
  ledd();
}

void ledd()
{
  for(int i = 0 ; i < 9 ; ++i)
  {
    digitalWrite(led3, HIGH);
    delay(arr[i]);
    digitalWrite(led3, LOW);
    delay(arr[i]);
  }
  delay(1000);
}
