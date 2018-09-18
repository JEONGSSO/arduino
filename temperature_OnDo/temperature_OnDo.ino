
void setup() {
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
   int value = analogRead(A1);
   float volt = value * 5.0/ 1024;
   float temper = (volt - 0.5)*100;
   
   Serial.print(volt);
   Serial.print("  V    ");
   Serial.print(temper);
   Serial.println("  C");
   delay(500);

   
}
