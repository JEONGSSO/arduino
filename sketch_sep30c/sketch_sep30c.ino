int pins[8] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  for(int i=0; i<8; i++)
  {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  for(int j=0; j<8; j++)
  {
    digitalWrite(pins[j], HIGH);
  }
  
}
