int ledG =10;
int ledR =9;

void setup() {
  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  if(Serial.available()){
    char data = Serial.read();
    if(data == '1'){
      digitalWrite(ledG, HIGH);
      while(1){    
        digitalWrite(ledR, HIGH);
        delay(100);
        digitalWrite(ledR, LOW);
        delay(100);
      }
      
    }
    else{
      digitalWrite(ledG, LOW);
      digitalWrite(ledR, LOW);
    }
    Serial.println(data);
  }
  

}
