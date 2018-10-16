#include <WiFiClient.h>
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>

const char* ssid = "tjoeun604";
const char* password = "029381119";
ESP8266WebServer server(80);

void handleRoot(){
  String message ="<html><body>\n";
  message += "<h1>Arduino Server</h1>\n";
  message += "<p>A0= ";
  message += analogRead(A0);
  message += "</p>";
  message += "<p>millis = ";
  message += millis();
  message += "</p>";
  message += "</body></html>\n";
  server.send(200, "text/html", message);
}

void connectToWiFi(){
  Serial.print("\n\nConnecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.print("IP address : ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  connectToWiFi();

  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();

}
