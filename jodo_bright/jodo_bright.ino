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

//    digitalWrite(led3, HIGH);
//    delay(value);
//    digitalWrite(led3, LOW);
//    delay(value);
  
    analogWrite(led3, value/4);
//
//    analogWrite(led3, 50);
//    delay(delayTime);
//    analogWrite(led3, 50);
//    delay(delayTime);
}
