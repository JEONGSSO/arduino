int ledR = 10;
int ledG = 9;
void flash(int led, int led2);

void setup() {
  pinMode(9, OUTPUT);  //핀번호, 출력 ,입력은 INPUT
  pinMode(10, OUTPUT);
}

void loop() {
 flash(ledG, ledR);
 
}

void flash(int led, int led2)
{
  digitalWrite(led, HIGH);
  digitalWrite(led2, HIGH);
  delay(100);
  digitalWrite(led, LOW);
  digitalWrite(led2, LOW);
  delay(100);
}
