#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <WiFiClient.h>

const char* ssid = "tjoeun604";
const char* password = "029381119";

ESP8266WebServer server(80);

void handleRoot()
{
  String msg = "<html><body>\n";
  msg += "<h1>Arduino Server</h1>\n";
  
  msg += "<p>A0 = ";
    msg += analogRead(A0);
  msg += "</p>";
  
  msg += "<p>millis = ";
    msg += millis();
  msg += "</p>";

  msg += "</body></html>\n";

  server.send(200, "text/html", msg);
}

void connectTowifi()
{
   Serial.print("connectin to ");
   Serial.print("ssid");
   WiFi.begin(ssid, password);
   
   while(WiFi.status() != WL_CONNECTED)
  {
     delay(500);
     Serial.print(".");
  }   
  Serial.println("connected");
  Serial.print("IP ADDRESS : ");
  Serial.print(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  connectTowifi();

  server.on("/", handleRoot);  //함수안에 함수는 가로빼기
  server.begin();
  Serial.println(" HTTP server started");
}

void loop() {
  server.handleClient();
}
