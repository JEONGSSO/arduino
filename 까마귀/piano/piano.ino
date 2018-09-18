int pins[4] = {2,3,4,5};
int value[4] = {0,0,0,0};
int lightSensor = A1;
int bz = 11;
#define NOTE_C4  262
#define NOTE_D4  294 
#define NOTE_E4  330
#define NOTE_F4  349 
#define NOTE_G4  392 
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
int notes[8] = {NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};

void setup() {
  for(int i=0; i<4; i++){
     pinMode(pins[i], OUTPUT);
  }
  
  pinMode(lightSensor, INPUT);  
  Serial.begin(9600);
}

void loop() {
  for(int i=0; i<4; i++)
  {
    value[i] = digitalRead(pins[i]);
  }
  int lightVal = analogRead(lightSensor);
  Serial.println(lightVal);
  if(lightVal<400){
    for(int i=0; i<4; i++){
    if(value[i]==1){  
      tone(bz, notes[i], 200);
    }
  }
  }else{
    for(int i=0; i<4; i++){
      tone(bz, notes[i+4], 200);
    }
  }
  
  
}
