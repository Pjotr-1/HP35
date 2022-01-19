#include <Adafruit_ILI9341.h>
#include <Adafruit_FT6206.h>

#include "disp35.h"
#include "keyb35.h"
#include "hp35core.h"

#define TFT_DC 9
#define TFT_CS 10
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
Adafruit_FT6206 ctp = Adafruit_FT6206();

Disp35* disp35;
KeyB35* keyb35;
HP35Core* hp35core;

void setup() {
  disp35 = new Disp35(&tft);
  keyb35 = new KeyB35(&ctp);
  hp35core = new HP35Core(disp35, keyb35);
}

void loop() {
  hp35core->process_rom();
  if (keyb35->isTapped()) {
    uint8_t key = keyb35->getKey();
    hp35core->processKey(key);
    delay(200);
  }
}

// EOF
