// Lチカ

const byte LED_PIN = 25; // PINが25ってなってるやつ(GPIO25)

// arduinoファイルはsetup()とloop()の2つの関数で構成される
void setup() {
  // GPIO0-33, GPI34-39はIOの両方に対応しているのでpinMode()でIとOを決定できる
  pinMode(LED_PIN, OUTPUT); // 今回はOutput
}

void loop() {
  // arduinoの出力電圧はHIGHの3.3VとLOWの0Vのデジタル出力
  // このうちGPIO25, 26はアナログ出力もできる
  digitalWrite(LED_PIN, HIGH); // HIGHは3.3V
  delay(1000); // msec
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
