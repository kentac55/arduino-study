// wifi

#include <WiFi.h>

const byte LED_PIN = 25;
bool ledFlag = true;

const char *ssid = "";
const char *password = "";
IPAddress ip(192, 168, 30, 100);
IPAddress gateway(192, 168, 30, 1);
IPAddress subnet(255, 255, 255, 0);

void setup() {
  Serial.begin(115200);
  Serial.println();
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
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
}

void loop() {
}
