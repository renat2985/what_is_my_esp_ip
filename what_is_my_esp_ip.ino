#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
const char* ssid = "yourNetworkName";
const char* password = "yourNetworkPassword";
String url = "http://www.onclick.lv/esp/?mac="+WiFi.macAddress()+"&ip="+WiFi.localIP().toString();
void setup () {
 // Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
//    Serial.print("Connecting..");
  }
}
void loop() {
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
    HTTPClient http;  //Declare an object of class HTTPClient
    http.begin(url);
    int httpCode = http.GET();                                  //Send the request
    http.end();   //Close connection
  }
  delay(30000);    //Send a request every 30 seconds
}
