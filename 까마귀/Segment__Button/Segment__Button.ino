int pins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int button = 11;
int oldValue=0;
int n =0;

int digits[10][8]={
  {1,1,1,1,1,1,0,0}, // 0
  {0,1,1,0,0,0,0,0}, // 1
  {1,1,0,1,1,0,1,0}, // 2
  {1,1,1,1,0,0,1,0}, // 3
  {0,1,1,0,0,1,1,0}, // 4
  {1,0,1,1,0,1,1,0}, // 5
  {1,0,1,1,1,1,1,0}, // 6
  {1,1,1,0,0,1,0,0}, // 7
  {1,1,1,1,1,1,1,0}, // 8
  {1,1,1,0,0,1,1,0}  // 9
};


void setup() {
  for(int i=0; i<8; i++)
  {
    pinMode(pins[i], OUTPUT);
  }
  
  pinMode(button, INPUT);
}

void loop() {
  int value = digitalRead(button);
  
  
  if(value==0)
  {
    oldValue = 0;
    delay(20);
  } 
  
  else if(value==1 && oldValue ==0)
  {
    oldValue = 1;
    n = n+1; 
    if(n>9)
    {
      n=0;
    }
    for(int i=0; i<8; i++)
    {
      digitalWrite(pins[i], digits[n][i]);
    }  
    delay(300);   
  }
}
