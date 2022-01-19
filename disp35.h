#ifndef DISP35_H
#define DISP35_H

#include <Adafruit_ILI9341.h>
#include "keyb35.h"

class Disp35 {
  public:
    Disp35(Adafruit_ILI9341 *tft);
    void drawDigit(byte pos, int digit, bool dp);
    void drawCross(Point center, uint8_t len);
  protected:
    void drawSegments(byte pos, bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool dp);
  private:
    Adafruit_ILI9341 *tft;
};

#endif
