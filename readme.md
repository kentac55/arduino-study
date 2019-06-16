# Arduinoのお勉強

http://kit.socinno.com/ を買ったので

## 環境構築

1. `/dev/ttyACM0`とか`/dev/ttyUSB0`をsudo無しで開くために・・・
    - `sudo gpasswd -a kentac55 uucp`
    - `sudo gpasswd -a kentac55 lock`
1. ログアウト&ログイン
1. modprobe
    - `sudo modprobe cdc_acm`
1. パッケージ追加
    - `sudo pacman -S arduino-cli uucp`
    - [Fritzing](https://aur.archlinux.org/packages/fritzing/)あると便利
1. 初期設定
    1. 以下を`~/.arduino15/arduino-cli.yaml`として保存
        ```yaml
        proxy_type: auto
        sketchbook_path: /home/kentac55/src/github.com/kentac55/arduino-study
        arduino_data: /home/kentac55/.arduino15
        board_manager:
          additional_urls:
            - https://dl.espressif.com/dl/package_esp32_index.json
        ```
    1. `arduino-cli core update-index`
    1. `arduino-cli core install esp32:esp32`

## 作る

1. 回路を設計する
    - `Fritzing`
1. 回路を実装する
1. 作成
    - `arduino-cli sketch new test`
    - `cd /home/kentac55/src/github.com/kentac55/arduino-study`
    - `vim test/test.ino`
1. コンパイル
    - `arduino-cli compile --fqbn esp32:esp32:esp32 /test`
1. [こういう](https://github.com/arduino/arduino-cli/issues/163)トラブルがあるので**手動で**`partition.bin`を`/tmp/arduino-sketch-****`から`/home/kentac55/src/github.com/kentac55/arduino-study/test`にコピーする
    - `cp /tmp/arduino-sketch-***/test.ino.partitions.bin ./test/test.esp32.esp32.esp32.partitions.bin`
1. upload
    - ` arduino-cli upload -p /dev/ttyUSB0 --fqbn esp32:esp32:esp32 /home/kentac55/src/github.com/kentac55/arduino-study/test`
