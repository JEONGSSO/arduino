int pins[8] = {2, 3, 4, 5, 6, 7, 8, 9}; //8번 가운데 9번 오른쪽 밑 점
int i, j ;
int led = 13;
int btn12 = 12;
int n = 0;
int digits[10][7] = 
{
  {0,0,0,0,0,0,1},  // 0
  {1,0,0,1,1,1,1},  // 1
  {0,0,1,0,0,1,0},  // 2
  {0,0,0,0,1,1,0},  // 3
  {1,0,0,1,1,0,0},  // 4
  {1,0,0,1,1,0,0},  // 5
  {0,1,0,0,0,0,0},  // 6
  {0,0,0,1,1,0,1},  // 7
  {0,0,0,0,0,0,0},  // 8
  {0,0,0,0,1,0,0},  // 9
};

void setup() {
  for(int i = 0 ; i < 8 ; ++i)
  {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], 1);
  }
  pinMode(btn12, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
//  bzling();
//numberLoop();
//readNumber();
   btn();
}

void bzling()
{
  for(int i = 0 ; i < 6 ; ++i)
  {
    digitalWrite(pins[i], 0);   //low(0)가 켜지는거 a
    analogWrite(10, 500);
    delay(100);
    analogWrite(10, 0);
    delay(100);
  }
  for(int i = 6 ; i >= 0 ; --i)
  {
    digitalWrite(pins[i], 1);
    analogWrite(10, 500);
    delay(100);
    analogWrite(10, 0);
    delay(100);
   }
}

void numberLoop()
{
  for(i = 0; i < 10; ++i)
    {
      for(j = 0; j < 7; ++j)
      {
        digitalWrite(pins[j], digits[i][j]);
      }
      delay(500);
    }
}

void readNumber()
{
  int value = Serial.read();
//  Serial.println(value);
  delay(700);
  if(value == 49)
  {
     for(j = 0; j < 7; ++j)
      {
        digitalWrite(pins[j], digits[1][j]);
      }
  }
}

void btn()
{ 
  
  int value = digitalRead(btn12);
//  Serial.println(value);

  for(i = 0; i < 10; ++i)
  {
    for(j = 0; j < 7; ++j)
    {
      digitalWrite(pins[i], digits[n][i]);
    }
  }
  
  if(value == 0)
  {
      n++;
      if(n > 9)
        n = 0;
  }
   delay(300);
}
