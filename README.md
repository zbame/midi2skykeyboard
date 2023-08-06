# midi2skykeyboard

Skyの楽器をMIDIキーボードで鳴らしたい。Apple Silicon Mac上のSkyならば、楽器の演奏はキーボードで可能なので、MIDIキーボードから送られてきたMIDIノート情報をHID KEYBOARDのキー押し放しに変換すればSkyの楽器をMIDI楽器として扱うことができます。Arduinoならば簡単に作ることができます。Arduino LoenardoやArduino Pro Micro等のATmega32U4を搭載したArduinoボードで作ることができます。

## 必要なもの

midi2skykeyboardを使用してSkyの楽器をMIDIキーボードで鳴らすのに必要なもの

- Apple Silicon搭載のMac
- Sky (Mac OS版）
- Locig Pro等のDAW (MIDIデータのルーティングに必要)
- USB MIDIキーボード
- Arduino Pro Micro
- USBケーブルなど
- Arduino IDE
- MIDIUSB.h keyboard.h 等のライブラリ
- midi2skykeyboard のコード
