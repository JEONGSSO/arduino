int PM = A0;
int speaker = 9;

void setup() {
#define NOTE_C3  131
#define NOTE_D3  147
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
  pinMode(PM, INPUT);
  pinMode(speaker, OUTPUT);
}

void loop() {
  int value = analogRead(PM);
  int sound = map(value, 0, 1023, 0, 255);
  if(value<200 && value>=10)
  {
    tone(speaker,NOTE_C3, 250);
  }
  else if(value<400 && value>=200)
  {
    tone(speaker,NOTE_D3, 250);
  }
  else if(value<600 && value>=400)
  {
    tone(speaker,NOTE_E3, 250);
  }
  else if(value<800 && value>=600)
  {
    tone(speaker,NOTE_F3, 250);
  }
  else if(value<1000 && value>=800)
  {
    tone(speaker,NOTE_G3, 250);
  }
  else if(value<1024 && value>=100)
  {
    tone(speaker,NOTE_A3, 250);
  }
  else if(value>0 && value<10)
  {
    noTone(speaker);
  }
  
  

}
