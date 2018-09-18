int led = 10;

void setup() {
  pinMode(led, OUTPUT);

}

void loop() {
  for(int i=0; i<256; i++){
    analogWrite(led, i);  // digitalWrite에서는 0 아니면 255 -> HIGH or LOW, 아날로그는 숫자를 지정할 수 있다.
    delay(10);}
  if(int i=256)
    {
      for(i=255; i>-1; i--){
    analogWrite(led, i);  // digitalWrite에서는 0 아니면 255 -> HIGH or LOW, 아날로그는 숫자를 지정할 수 있다.
    delay(10);}
    }
  }
  
