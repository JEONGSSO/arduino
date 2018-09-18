

int light = A1;
int led = 10;
int bz = 11; // 버저 = 스피커
void sound();
void melody();

void setup() {
  pinMode(light, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  #define NOTE_C4  262 
  #define NOTE_D4  294
  #define NOTE_E4  330
  #define NOTE_F4  349
  #define NOTE_G4  392
  #define NOTE_A4  440
  
}

void loop() {
  int value = analogRead(light);
  Serial.println(value);
  delay(50);
  if(value>500)
  {
    analogWrite(led, 230);
    melody();
  }
  else
  {
    analogWrite(led, 0);
    analogWrite(bz, 0);
  }
}
void sound()
{
    analogWrite(bz, 500);
    delay(100);
    analogWrite(bz, 0);
    analogWrite(bz, 200);
    delay(10);
    analogWrite(bz,0);
    delay(10);
}
void melody(){
  tone(bz, NOTE_C4, 100);
  delay(300);
  tone(bz, NOTE_E4, 100);
  delay(300);
  tone(bz, NOTE_G4, 100);
  delay(300);
  tone(bz, NOTE_C4, 100);
  delay(300);
  tone(bz, NOTE_E4, 100);
  delay(300);
  tone(bz, NOTE_G4, 100);
  delay(300);
  tone(bz, NOTE_A4, 100);
  delay(300);
  tone(bz, NOTE_A4, 100);
  delay(300);
  tone(bz, NOTE_A4, 100);
  delay(300);
  tone(bz, NOTE_G4, 100);
  delay(600);
  tone(bz, NOTE_F4, 100);
  delay(300);
  tone(bz, NOTE_F4, 100);
  delay(300);
  tone(bz, NOTE_F4, 100);
  delay(300);
  tone(bz, NOTE_E4, 100);
  delay(300);
  tone(bz, NOTE_E4, 100);
  delay(300);
  tone(bz, NOTE_E4, 100);
  delay(300);
  tone(bz, NOTE_D4, 100);
  delay(300);
  tone(bz, NOTE_D4, 100);
  delay(300);
  tone(bz, NOTE_D4, 100);
  delay(300);
  tone(bz, NOTE_C4, 100);
  delay(600);
}
