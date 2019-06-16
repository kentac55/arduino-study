// リモコン受信
// 赤外線通信するやつなくて検証できなかった・・・

const byte IR_R_PIN = 36;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if(irRecv()) {
    Serial.println();
    Serial.println("RcvOK");
  } else {
    Serial.println();
    Serial.println("NoSig");
  }
}

bool irRecv() {
  unsigned short irCount = 0;
  unsigned long lastt = 0;
  unsigned long deltt = 0;
  unsigned long sMilli;
  unsigned long sMicro;
  unsigned long wMicro;
  bool rState = 0;
  sMilli = millis();
  while(1) {
    wMicro = micros();
    while(digitalRead(IR_R_PIN) == rState) {
      if(micros() - wMicro > 500000) {
        if(irCount > 10) {
          return true;
        }
        irCount = 0;
      }
      if(millis() - sMilli > 15000) {
        return false;
      }
    }
    if(irCount == 0) {
      sMicro = micros();
      lastt = 0;
      irCount++;
      Serial.println("ir:");
    } else {
      deltt = ((micros() - sMicro)/10) - lastt;
      lastt = lastt + deltt;
      irCount++;
      Serial.print(deltt);
      Serial.print(",");
    }
    rState = !rState;
  }
}
