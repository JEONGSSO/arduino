int ledP13 = 13;
int ledP9 = 9;
int leddelay = 100;

void setup() 
{
  pinMode(ledP9, OUTPUT);
}

void loop() 
{
  flash();
  leddelay += 100;
  if(leddelay == 1000)
      leddelay = 100;
}

void flash()
{
    digitalWrite(ledP9, HIGH);
    delay(leddelay);
    digitalWrite(ledP9, LOW);
    delay(leddelay);
}
