int LED = 9;
int button = 11;
int oldValue =0;
int LedState=0;
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);
   digitalWrite(LED, LOW);
}

void loop() {
  int value = digitalRead(button);

  if(value==1 && oldValue ==0)
  {
    LedState =1 -LedState;
    //delay(20);
  }
    oldValue = value;
    if(LedState==1)
     {
       digitalWrite(LED, HIGH);
     }
    else
   {
    digitalWrite(LED, LOW);
   }
  
  /*
  if(oldValue ==1 && value ==1)
  {
    digitalWrite(LED, LOW);
    oldValue = 0;
    delay(100);
  }*/


}
