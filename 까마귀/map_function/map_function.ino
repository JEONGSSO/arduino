int light = A1;
int led = 10;

void setup() {
  pinMode(light, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  int value = analogRead(light);
  int br = map(value, 0, 1023, 0, 255);
  analogWrite(led, br);  //센서와 강도값은 4배 차이남.
  delay(value);
  analogWrite(led, 0);
  delay(100);
  
}
