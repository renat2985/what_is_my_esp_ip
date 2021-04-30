#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
const char* ssid = "yourNetworkName";
const char* password = "yourNetworkPassword";
void setup () {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Connecting..");
  }
}
void loop() {
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
    HTTPClient http;  //Declare an object of class HTTPClient
    http.begin("http://onclick.lv/ip/get.php?mac="+(String)WiFi.macAddress()+"&ip="+WiFi.localIP());
    int httpCode = http.GET();                                  //Send the request
    if (httpCode > 0) { //Check the returning code
      String payload = http.getString();   //Get the request response payload
    }
    http.end();   //Close connection
  }
  delay(30000);    //Send a request every 30 seconds
}
