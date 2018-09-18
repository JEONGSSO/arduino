void setup() {
  Serial.begin(9600);
  //int n1 = 10, n2 = 20;
  //n = n+1;
  //Serial.print("두 수의 합 " + String(n1+n2)); // 문자랑 같이 쓸때는 String을 이용해서 숫자도 문자처럼 만들어준다. 숫자와 문자사이는 + 로 이어준다.
  int i, j;
  for(i=1; i<100; i++)
  {
    for(j=1; j<100; j++)
    {
      Serial.println(String(i) + "x" + String(j) + "=" + String(i*j));
      //delay(500);
    }
    Serial.println("--------------------");
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
