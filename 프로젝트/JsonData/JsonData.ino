#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager

int temp = 23;
int humi = 10;

//--------------------Json 인코딩----------------
  String jsondata = ""; //Json을 담을 곳
  String result = "";

  char* ssid = "tjoeun604";
  char* password = "029381119";
  char* serverip = "192.168.0.58";    //ipconfig ipv4 적으세요
  
  // Json변환에 필요한 버퍼 용량은 200
  StaticJsonBuffer<200> jsonBuffer;
  WiFiClient client;
  
  // Json형식을 만들어 낼 수 있는객체를 선언한다.
  JsonObject & root = jsonBuffer.createObject();

void setup(){

  WiFiManager wifiManager;
  
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Serial.println();
  Serial.print("Connecting");
  
  while(WiFi.status() != WL_CONNECTED){
   delay(500);
   Serial.print(".");
 }

 Serial.println("success!");
 Serial.print("IP Address is: ");
 Serial.println(WiFi.localIP());
}


void loop() {
  root["temp"] = temp;  
  root["humi"] = humi;
  
  root.printTo(jsondata);
//  Serial.println(jsondata);

  SendTemp();
  jsondata = "";
}

void SendTemp(){
  if(client.connect(serverip, 8080)){ //ipconfig ipv4 적으세요
    //온습도 받는 페이지 get방식
    client.print("POST /setTempHumi");
    client.print(" HTTP/1.1\r\n");
    client.print("Host: 192.168.0.58:8080\r\n");   //ipconfig ipv4 적으세요
    client.print("Content-Type:application/json\r\n");
    client.print("Content-Length: ");
    client.println(jsondata.length());
    client.println();
    client.println(jsondata);
    client.println("\r\n\r\n");
    
//    Serial.print("POST /view");
//    Serial.print(" HTTP/1.1\r\n");
//    Serial.print("Host: 192.168.0.58:8080\r\n");
//    Serial.print("Content-Type:application/json\r\n");
//    Serial.print("Content-Length: ");
//    Serial.println(jsondata.length());
//    Serial.println();
//    Serial.println(jsondata);
//    Serial.println("\r\n\r\n");
  }
}


//  //-------------Json 디코딩 서버에서 받는 부분 ------------------
//  // Json변환에 필요한 버퍼 용량은 200
//  StaticJsonBuffer<200> jsonBuffer;
//  
//  // create 개념이 아닌 parse개념으로 jsonObj 객체 생성
//  // 생성자에는 파싱할 데이터값을 넣어준다.
//  JsonObject & root = jsonBuffer.parseObject(rcvbuf)
//
//  //root[result]로 key값을 정의하고 호출하면 해당하는 값을 얻는다.
//  String result - root["result"];
//
//  Serial.println(result);
