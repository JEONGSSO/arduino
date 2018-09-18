int ledP2 = 2;  //Green
int ledP3 = 3;  //Yellow
int ledP4 = 4;  // Red
int leddelay = 500;

void setup() 
{
  pinMode(ledP2, OUTPUT);
  pinMode(ledP3, OUTPUT);
  pinMode(ledP4, OUTPUT);
}

void loop() 
{
  int i = 2;
  while(i <= 4)
  flash(i++);
}

void flash(int led)
{
    digitalWrite(led, HIGH);
    delay(leddelay);
    digitalWrite(led, LOW);
    delay(leddelay);
}
