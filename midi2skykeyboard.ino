// 受信した USB MIDI ノート情報を USB HID KEYBOARD のキー情報に変換します

#include <MIDIUSB.h>
#include <USBCore.h>
#include <Keyboard.h>

// MIDIノート番号と対応するキーのテーブル
const struct {
  int midiNote;
  char key;
} midiNoteTable[] = {
  {48, 'Y'}, // MIDIノート番号48に対応するキーは'Y'
  {50, 'U'}, // MIDIノート番号50に対応するキーは'U'
  {52, 'I'}, // MIDIノート番号52に対応するキーは'I'
  {53, 'O'}, // MIDIノート番号53に対応するキーは'O'
  {55, 'P'}, // MIDIノート番号55に対応するキーは'P'
  {57, 'H'}, // MIDIノート番号57に対応するキーは'H'
  {59, 'J'}, // MIDIノート番号59に対応するキーは'J'
  {60, 'K'}, // MIDIノート番号60に対応するキーは'K'
  {62, 'L'}, // MIDIノート番号62に対応するキーは'L'
  {64, ';'}, // MIDIノート番号64に対応するキーは';'
  {65, 'N'}, // MIDIノート番号65に対応するキーは'N'
  {67, 'M'}, // MIDIノート番号67に対応するキーは'M'
  {69, ','}, // MIDIノート番号69に対応するキーは','
  {71, '.'}, // MIDIノート番号71に対応するキーは'.'
  {72, '/'}, // MIDIノート番号72に対応するキーは'/'
};

void setup() {
  Keyboard.begin();
  delay(100); // 初期化のために少し待つ
}

void loop() {
  int note;

  midiEventPacket_t rx;
  rx = MidiUSB.read();
  if (rx.header != 0) {
    note = rx.byte2;
    if (rx.byte1 == 0x90) {
      if (rx.byte3 == 0) {
        // ノートオンメッセージをベロシティー０で受信したらキーを放す
        sendKeyFromMidiNoteOff(note);
      } else {
        // ノートオンメッセージを受信したらキーを押す
        sendKeyFromMidiNoteOn(note);
      }
    } else if (rx.byte1 == 0x80) {
      // ノートオフメッセージを受信したらキーを放す
      sendKeyFromMidiNoteOff(note);
    }
  }
}

// MIDIノート番号に対応するキー押しを送信する関数
void sendKeyFromMidiNoteOn(int midiNote) {
  // MIDIノート番号と対応するキーのテーブルを検索
  int tableSize = sizeof(midiNoteTable) / sizeof(midiNoteTable[0]);
  for (int i = 0; i < tableSize; i++) {
    if (midiNote == midiNoteTable[i].midiNote) {
      // MIDIノート番号に対応するキーを押す
      char key = midiNoteTable[i].key;
      Keyboard.press(key);
      break;
    }
  }
}

// MIDIノート番号に対応するキー放しを送信する関数
void sendKeyFromMidiNoteOff(int midiNote) {
  // MIDIノート番号と対応するキーのテーブルを検索
  int tableSize = sizeof(midiNoteTable) / sizeof(midiNoteTable[0]);
  for (int i = 0; i < tableSize; i++) {
    if (midiNote == midiNoteTable[i].midiNote) {
      // MIDIノート番号に対応するキーを放す
      char key = midiNoteTable[i].key;
      Keyboard.release(key);
      break;
    }
  }
}
