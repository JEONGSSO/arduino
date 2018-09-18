int led3 = 3;
int PhotoR = A0;

void setup() {
  pinMode(led3, OUTPUT);
  pinMode(PhotoR, INPUT);
  Serial.begin(9600);
}

void loop() {

  int value = analogRead(PhotoR);
  Serial.println(value);
  delay(500);
  
  if(value > 850)
  { 
    digitalWrite(led3, HIGH);
    delay(1000);
    digitalWrite(led3, LOW);
    delay(1000);
  }

   else
  {
    digitalWrite(led3, HIGH);
    delay(300);
    digitalWrite(led3, LOW);
    delay(300);
  }
}
