int button =7;
int led = 10;
int OldValue = 0;
int ledState = 0; 
int brightness;
int startTime;

void setup() {
  pinMode(button, INPUT);  
  pinMode(led, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int value = digitalRead(button);
  
  if(value == 1 && OldValue ==0)
  {
    ledState = 1 - ledState;
    startTime=millis();
    delay(10);
  }
  
  OldValue = value;
  if(value == 1 && OldValue ==1){
    if(ledState ==1 && (millis()-startTime)>500){
      brightness +=1;
      delay(10);

      if(brightness > 255)
        brightness =0;           
    }
  }

  
  if(ledState ==1){
    analogWrite(led, brightness);
  }
  else{
    analogWrite(led, 0);
  }

}
