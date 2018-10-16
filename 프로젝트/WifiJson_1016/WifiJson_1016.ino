#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
#include <WiFiClient.h>
//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager

  String ssid = WiFi.SSID();  // 폰에서 저장한 ssid 스트링으로 넣음
  String password = WiFi.psk();

  int temp = 23;
  int humi = 10;

  String jsondata = ""; //Json을 담을 곳

//  char* ssid = "tjoeun604";
//  char* password = "029381119";

  char* serverip = "www.dogfriends.site";    //ipconfig ipv4 적으세요
  String localp = (String)WiFi.localIP();
  
  // Json변환에 필요한 버퍼 용량은 200
  StaticJsonBuffer<200> jsonBuffer;
  WiFiClient client;
  
  // Json형식을 만들어 낼 수 있는객체를 선언한다.
  JsonObject & root = jsonBuffer.createObject();

void setup()
{
    // put your setup code here, to run once:
    //WiFiManager
    //Local intialization. Once its business is done, there is no need to keep it around

    //reset saved settings  
    //wifiManager.resetSettings();

    //set custom ip for portal
    //wifiManager.setAPStaticIPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));

    //fetches ssid and pass from eeprom and tries to connect
    //if it does not connect it starts an access point with the specified name
    //here  "AutoConnectAP"
    //and goes into a blocking loop awaiting configuration

    //or use this for auto generated name ESP + ChipID
    //wifiManager.autoConnect();
    
    //if you get here you have connected to the WiFi
    //Serial.println("connected...yeey :)");
    
    Serial.begin(9600);

//    pinMode(TRIGGER_PIN,INPUT); //와이파이 리셋할때 쓸 버튼 아직 구현 X
    
    //WiFiManager 자세한 설명 https://www.instructables.com/id/ESP8266-and-ESP32-With-WiFiManager/
    WiFiManager wifiManager;  //http://www.jy-soft.net:369/index.php?mid=ARDUINO&document_srl=46512&listStyle=viewer

//    WiFi.begin((const char*)ssid.c_str(), (const char*)password.c_str()); //String 문자열 변환
  wifiManager.startConfigPortal("Dogfriend"); //와이파이 이름
  wifiManager.autoConnect((const char*)ssid.c_str(), (const char*)password.c_str()); //이 이름으로 자동 연결
  Serial.println("success!");
  Serial.print("IP Address is: ");
  Serial.println(WiFi.localIP());
  
}

void loop()
{
   /* if (btn == LOW){  //안드로이드 와이파이 리셋 버튼 누르면 와이파이 재설정
      wifiManager.startConfigPortal("Dogfriend"); //와이파이 이름
      //안드로이드에 재설정 보내기
    }
*/
    root["temp"] = temp;  
    root["humi"] = humi;
    
    root.printTo(jsondata);
  
    SendTemp();
    delay(1000);
    jsondata = "";    //데이터 초기화
}
void SendTemp(){
  if(client.connect(serverip, 8080)){ //ipconfig ipv4 적으세요
    //온습도 받는 페이지 post방식
    client.print("POST /setTempHumi");
    client.print(" HTTP/1.1\r\n");
    client.print("Host:"+localp+":8080\r\n");   //ipconfig ipv4 적으세요
    client.print("Content-Type:application/json\r\n");
    client.print("Content-Length: ");
    client.println(jsondata.length());
    client.println();
    client.println(jsondata);
    client.println("\r\n\r\n");
  }
}
