#include "DigiKeyboard.h" // library for emulate keyboard
#define COPY 2 // copy button pin
#define PASTE 0// paste button pin
#define GND 1// center must be connected to ground
void setup() {
  pinMode(COPY, INPUT); // set pin to input
  digitalWrite(COPY, HIGH);// turn on pullup
  pinMode(PASTE, INPUT);
  digitalWrite(PASTE, HIGH);
  pinMode(GND, OUTPUT); // set pin to output
  digitalWrite(GND, LOW);// and set on pin GND
}


void loop() {
  // if something COPY or PASTE clicked
  if (!digitalRead(COPY) || !digitalRead(PASTE)) {
    delay(30); // wait(debounce)
    if (!digitalRead(COPY)) { // if copy still pressed send CTRL+C
      DigiKeyboard.sendKeyStroke(KEY_C , MOD_CONTROL_LEFT);
      delay(30);
    }
    else if (!digitalRead(PASTE)) {// if paste still pressed send CTRL+V
      DigiKeyboard.sendKeyStroke(KEY_V , MOD_CONTROL_LEFT);
      delay(200);
    }
  }
}
