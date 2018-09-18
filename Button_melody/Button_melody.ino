#include "pitches.h"
int led2 = 2;
int btn[] = {4, 5, 6, 7};
int btnValue[] = {0, 0, 0 ,0}; 
int value;
int piezo8 = 8;
int melody[8] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,
                 NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};
int PhotoR = A0;
void setup()
{
  pinMode(led2, OUTPUT);
  pinMode(PhotoR, INPUT);
  for(int i = 0; i < 4 ; ++i)
  {
     pinMode(btn[i], INPUT);
  }
  Serial.begin(9600);
}

void loop() 
{
 for(int i = 0 ; i < 4 ; ++i)
 {
  int btnValue = digitalRead(btn[i]);
  value = analogRead(PhotoR);
  Serial.println(value);
  Serial.println(btnValue);
  delay(500);

  if(value > 500)
    {
      for(int j = 0 ; j < 4 ; ++j)
      {
        if(btnValue == 1)
      {
        tone(piezo8, melody[j]);
        delay(300);
        noTone(piezo8);
      }
      if(btnValue == 1)
      {
        tone(piezo8, melody[1]);
        delay(300);
        noTone(piezo8);
      }
      if(btnValue == 1)
      {
        tone(piezo8, melody[2]);
        delay(300);
        noTone(piezo8);
      }if(btnValue == 1)
      {
        tone(piezo8, melody[3]);
        delay(300);
        noTone(piezo8);
      }
    }
    
  }
  else
    {
      if(btnValue == 1)
    {
      tone(piezo8, melody[4]);
      delay(300);
      noTone(piezo8);
    }
    if(btnValue == 1)
    {
      tone(piezo8, melody[5]);
      delay(300);
      noTone(piezo8);
    }
    if(btnValue == 1)
    {
      tone(piezo8, melody[6]);
      delay(300);
      noTone(piezo8);
    }if(btnValue == 1)
    {
      tone(piezo8, melody[7]);
      delay(300);
      noTone(piezo8);
    }
    }
  }
}
