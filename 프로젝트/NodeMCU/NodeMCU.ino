void setup() {
  pinMode(D0, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(115200);
}

void loop() {
  int value = analogRead(A0);
  
  if(value > 300)
  {
    digitalWrite(D0, 1);
    delay(500);
  }
  
  else 
  {
    digitalWrite(D0, 0);
    Serial.println(value);
    delay(500);
  }
  
}
