// http server

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

  webServer.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/html", "Hello World!");
    Serial.println("send html");
  });
  webServer.begin();
  Serial.println("Http server started");
}

void loop() {
}
