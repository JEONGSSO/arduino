int Bin1 =4;
int Bin2 =5;
int pwmB =3;
void setup() {
  //pinMode(Ain1, OUTPUT);
  //pinMode(Ain2, OUTPUT);
  //pinMode(pwmA, OUTPUT);
  pinMode(Bin1, OUTPUT);
  pinMode(Bin2, OUTPUT);
  pinMode(pwmB, OUTPUT);
  //Serial.begin(9600);
}

void loop() {
  digitalWrite(Bin1, HIGH);
  digitalWrite(Bin2, LOW);
  analogWrite(pwmB, 200);
  delay(3000);
  digitalWrite(Bin1, LOW);
  digitalWrite(Bin2, HIGH);
  analogWrite(pwmB, 200);
  delay(3000);

}
