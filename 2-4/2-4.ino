// 人感センサー

// 36はGPI
const byte MOTN_SNR = 36;

void setup() {
  Serial.begin(115200);
  pinMode(MOTN_SNR, INPUT);
}

void loop() {
  delay(1000);
  if (digitalRead(MOTN_SNR)) {
    Serial.println("Detected");
  } else {
    Serial.println("No detected.");
  }
}
