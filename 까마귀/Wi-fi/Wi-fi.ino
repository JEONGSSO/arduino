
void setup() {
  pinMode(D1, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  Serial.println(A0);
  int value = analogRead(A0);
  delay(50);
  if(value>800)
  {
    digitalWrite(D1, HIGH);
    delay(500);
    digitalWrite(D1, LOW);
    delay(500);
  }
  else{
    digitalWrite(D1,LOW);
  }
 
}
