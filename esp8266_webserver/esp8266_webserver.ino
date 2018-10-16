
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiClient.h>
#include <ESP8266mDNS.h>
 
const char* ssid = "tjoeun604";
const char* password = "029381119";
 
ESP8266WebServer server(80);
 
void handleRoot() {
  // 루트로 접속한 클라이언트에게 전송 폼을 보여준다
  String res = "<!doctype html>\n";
  res += "<html><head><title>ESP8266 jQuery AJAX example</title>\n";
  res += "<script src='https://code.jquery.com/jquery-2.2.4.min.js'   integrity='sha256-BbhdlvQf/xTY9gja0Dq3HiwQF8LaCRTXxZKRutelT44=' crossorigin='anonymous'></script>\n";
  res += "<script>\n";
  res += "$(function() { alert('jQuery ready!'); });\n";
  // jQuery AJAX request function start-------------
  res += "function ajaxRequest(){ \n";
  res += "   var params = {}; \n";
  res += "    params.param1 = $('input [name=param1]').val(); \n";
  res += "    params.param2 = $('input [name=param2]').val(); \n";
  res += "    $.ajax( { \n";
  res += "      url:'/ajaxReq', \n";
  res += "      type:'post', \n";
  res += "      data: params, \n";
  res += "      dataType:'json', \n";
  res += "      success:function(jsObj){  \n";
  res += "        $('#result').val(jsObj.success); \n";
  res += "        alert(jsObj.success); \n";
  res += "      }, \n";
  res += "      error:function(error){ \n";
  res += "        alert('error'); \n";
  res += "      } \n";
  res += "    }); \n";
  res += "  } \n";
  // jQuery AJAX request function end --------------
  res += "</script>\n";
  res += "</head>\n";
  res += "<body>\n";
  res += "<form method='post' action='/params'>\n";
  res += "Param1 <input type='text' name='param1'><br>\n";
  res += "Param2 <input type='text' name='param2'><br>\n";
  res += "<button type='button' onclick='ajaxRequest();'>SUBMIT</button>\n";
  res += "</form>\n";
  res += "ESP8266 processing result: <output id='result'> \n";
  res += "</body></html>\n";
 
  server.send(200, "text/html", res);
}
 
void handleNotFound(){
  //digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}
 
void setup(void){
  //pinMode(led, OUTPUT);
  //digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");
 
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
 
  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }
 
  server.on("/", handleRoot);
 
  server.on("/inline", [](){
    server.send(200, "text/plain", "this works as well");
  });
 
  // AJAX 요청일 경우의 파라미터 처리 및 JSON 응답 전송
  server.on("/ajaxReq", [](){
    String param1 = server.arg("param1");
    String param2 = server.arg("param2");
    server.send( 200, "text/json", "{\"success\":\"true\"}" );
  });
   
  // 파라미터를 수신하여 다시 클라이언트측으로 송신하는 예
  server.on("/params", [](){
    String param1 = server.arg("param1");
    String param2 = server.arg("param2");
    String res = "param1="+param1+", param2="+param2;
 
    // 클라이언트에게 응답 데이터 출력
    server.send(200, "text/plain", "Parameters received: "+res);
     
    // 디버깅을 위해 시리얼 모니터에 출력해본다
    Serial.print("param1=");
    Serial.print(param1);
    Serial.print(",   param2=");
    Serial.println(param2);
  });
   
  server.onNotFound(handleNotFound);
 
  server.begin();
  Serial.println("HTTP server started");
}
 
void loop(void){
  server.handleClient();
}
