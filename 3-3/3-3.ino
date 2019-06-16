// remote controll

#include <WiFi.h>
// cd libraries
// git clone https://github.com/me-no-dev/ESPAsyncWebServer.git
// git clone https://github.com/me-no-dev/AsyncTCP.git
#include <ESPAsyncWebServer.h>

const byte LED_PIN = 25;
bool ledFlag = true;

const char *ssid = "";
const char *password = "";
IPAddress ip(192, 168, 30, 100);
IPAddress gateway(192, 168, 30, 1);
IPAddress subnet(255, 255, 255, 0);

AsyncWebServer webServer(80);

void setup() {
  Serial.begin(115200);
  Serial.println();
  pinMode(LED_PIN, OUTPUT);
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    ledFlag = !ledFlag;
    digitalWrite(LED_PIN, ledFlag);
    delay(100);
    Serial.print(".");
  }
  Serial.print("WiFi connected. IP address: ");
  Serial.println(WiFi.localIP());
  digitalWrite(LED_PIN, HIGH);

  webServer.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    sendHtml(request);
  });
  webServer.on("/on", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(LED_PIN, HIGH);
    sendHtml(request);
  });
  webServer.on("/off", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(LED_PIN, LOW);
    sendHtml(request);
  });
  webServer.begin();
  Serial.println("Http server started");
}

void loop() {
}

void sendHtml(AsyncWebServerRequest *request) {
  String res_html =
  "<center>\
    <h2>LED Control</h2>\
    <p><button type='button' onclick='location.href=\"/on\"' \
      style='width:250px;height:60px;'>LED-ON</button></p>\
    <p><button type='button' onclick='location.href=\"/off\"' \
      style='width:250px;height:60px;'>LED-OFF</button></p>\
  </center>";
  request->send(200, "text/html", res_html);
  Serial.println("send html");
}
