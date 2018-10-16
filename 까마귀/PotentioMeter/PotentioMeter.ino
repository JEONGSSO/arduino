/*
 * 가변저항값 읽어오기
 */

int PM = A0; //가변저항
int Yellow = 10;
int Red = 9;
int Green = 11;
void setup() {
  pinMode(PM, INPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(PM);
  Serial.println(value);
  delay(500);

  if(value<400 && value>=0)
  {
    analogWrite(Red,0);
    analogWrite(Yellow,0);
    analogWrite(Green,0);
  }
  else if(value>=400 && value<700)
  {
    analogWrite(Red,value/4);
    analogWrite(Yellow,0);
    analogWrite(Green,0);
  }
  else if(value>=700 && value<900)
  {
    analogWrite(Red,value/4);
    analogWrite(Yellow,value/4);
    analogWrite(Green,0);
  }
  else if(value>=900 && value<1024)
  {
    analogWrite(Red,value/4);
    analogWrite(Yellow,value/4);
    analogWrite(Green,value/4);
    delay(20);
  }
 
}
