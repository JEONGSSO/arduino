int button = 7;
int led = 10;
int oldValue = 0;
int ledState = 1;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);

}

void loop() {
  int value = digitalRead(button);
  
  if(value ==1 && oldValue==0)
  {
    ledState = value -1;
    delay(50);
  }
  if(ledState ==1)
  {
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  } 
  oldValue = value;
 
  
  

}
