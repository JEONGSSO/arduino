int led = 13;
int motionS = A0;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(motionS, INPUT);
}

void loop() {
  int value = analogRead(motionS);
  Serial.println(value);
  if(digitalRead(motionS) ==1){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
  delay(100);
}
