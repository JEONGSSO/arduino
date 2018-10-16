int TrigPin = 8;
int EchoPin = 9;
int LED = 10;
int Speaker = 11;

void setup() {
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(Speaker, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  float duration, distance;  
  digitalWrite(TrigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  duration = pulseIn(EchoPin, HIGH); 
  distance = (34000*duration)/1000000/2; 
  
  int value = analogRead(distance);
  if(value<=30 && value>20)
  {
    flash(500);
    beat(1, 500);
    
  }
  else if(value<=20 && value>10)
  {
    flash(250);
    beat(2, 250);
  }
  else if(value<=10 && value>0)
  {
    flash(100);
    beat(3, 100);
  }
  else
  {
    analogWrite(LED, LOW);
    noTone(Speaker);
  }
  delay(100);
  
  Serial.println("거리는: " + String(distance) + "cm");
  delay(100);
}
void flash(int i)
{
  analogWrite(LED, HIGH);
  delay(i);
  analogWrite(LED, LOW);
  delay(i);
}

void beat(int n, int t)
{
  for(int j=0; j<n; j++)
  {
    analogWrite(Speaker, 255);
    delay(t);
    analogWrite(Speaker, 0);
    delay(t);
  }
}
