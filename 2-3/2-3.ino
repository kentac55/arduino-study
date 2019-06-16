// 温湿度計

// arduino-cli lib install "Adafruit Unified Sensor"
// arduino-cli lib install "DHT sensor library"
#include <DHT.h>
const byte TEMP_SNR = 32;

DHT dht(TEMP_SNR, DHT11);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  delay(5000);
  float g_humidity = dht.readHumidity();
  float g_temperature = dht.readTemperature();

  Serial.print(String(g_temperature));
  Serial.print(" / ");
  Serial.println(String(g_humidity));
}
