int btn = 2;
int led = 3;

int value = 0;
int oldVal = 0;
int ledstate = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT);
}

void loop() {
  value = digitalRead(btn);
  if(value == 1 && oldVal ==0)
    ledstate = 1 - ledstate;

    oldVal = value;

  if(ledstate == 1)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);
}
