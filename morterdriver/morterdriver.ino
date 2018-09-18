int in1 = 7;
int in2 = 5;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  if(Serial.available() > 0)
  {
    char data = Serial.read();
    if(data == '1')
    {
      digitalWrite(in1, 1); //한쪽바퀴가 돌면
      digitalWrite(in2, 0); //한쪽바퀴가 멈춤
    }
    
    else if(data == '2')
    {
      digitalWrite(in2, 1); //한쪽바퀴가 돌면
      digitalWrite(in1, 0); //한쪽바퀴가 멈춤
    }
    
    else
    {
//     Serial.println("중지");
       digitalWrite(in2, 0); 
       digitalWrite(in1, 0);
    }
    Serial.println(data);
  }
}
