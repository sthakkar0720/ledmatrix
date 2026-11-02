#include <LedControl.h>

const int PIN_DATA = 12;
const int PIN_CLK  = 11;
const int PIN_CS   = 10;
const int INTENSITY = 8; 

LedControl lc = LedControl(PIN_DATA, PIN_CLK, PIN_CS, 1);

const byte DATA_ARRAY[] = {
  B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10100101,
  B10011001,
  B01000010,
  B00111100
};

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, INTENSITY);
  lc.clearDisplay(0);
  
  initDisplay();
}

void loop() {
  // Loop logic can be inserted here if dynamic updates are required.
}

void initDisplay() {
  for (int i = 0; i < 8; i++) {
    lc.setRow(0, i, DATA_ARRAY[i]);
  }
}
