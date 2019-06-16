// 光度計
// 0-100までの数字で照度を出力する
// 抵抗を変えることで感度が変わる

// 抵抗(Ω): 蛍光灯/なんか眩しいやつ
// (抵抗なし): 80/90
// 10: 0/5
// 200: 0/70
// 1k: 4/75
// 10k: 75/80
// 200k: 80/85

// ボードにはVPと書かれている(よくわからん)
// 36はGPI、つまり入力専用
const byte LIGH_SNR = 36;

void setup() {
  // cu -s 115200 -l /dev/ttyUSB0
  Serial.begin(115200);
  Serial.println();
  Serial.println("LightStart");
}

void loop() {
  delay(1000);
  // analogRead()はpinから0-3.3Vの間を0から4095の数字で読み取る
  // なので百分率で表示するように4095で割って100を掛ける
  unsigned short g_light = analogRead(LIGH_SNR) * 100 / 4095;
  Serial.println(String(g_light));
}
