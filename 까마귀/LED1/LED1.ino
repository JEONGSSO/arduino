void setup() {
  pinMode(9, OUTPUT);  //핀번호, 출력 ,입력은 INPUT

}

void loop() {
  for(int i=0; i<20; i++)
  {
    digitalWrite(9, HIGH); // 전기를 넣기 위해서 HIGH, 끄려면 LOW
    delay(100); // 1초동안 지연시키기, ms임
    digitalWrite(9, LOW);
    delay(100); 
  }
  delay(3000);
}
