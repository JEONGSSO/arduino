int led3 = 3;
int btn = 2;
int PhotoR = A0;
int speaker = 5;

#define NOTE_C4  3000
#define NOTE_D4  2940
#define NOTE_E4  3300

void setup() {
  pinMode(led3, OUTPUT);
  pinMode(PhotoR, INPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(PhotoR);
  Serial.println(value);
  delay(500);

  if(value > 980)
  {
    digitalWrite(led3, HIGH);
//    analogWrite(speaker, HIGH);
    tone(speaker, NOTE_C4, 200); delay(300);
    tone(speaker, NOTE_C4, 200); delay(300);
    
    tone(speaker, NOTE_D4, 200); delay(300);
    tone(speaker, NOTE_D4, 200); delay(300);
    
    tone(speaker, NOTE_E4, 200); delay(300);
    tone(speaker, NOTE_E4, 200); delay(300);
    
    tone(speaker, NOTE_D4, 200); delay(300);
    tone(speaker, NOTE_C4, 200); delay(300);
  }
    
  else
  {
    digitalWrite(led3, LOW);
    analogWrite(speaker, LOW);
    noTone(speaker);
  }
}
