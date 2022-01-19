#ifndef KEYB35_H
#define KEYB35_H

#include <Adafruit_FT6206.h>

class Point {
  public:
    Point(void);
    Point(uint8_t x, uint16_t y);
    uint8_t  x;
    uint16_t  y;
};

class KeyData {
  public:
    KeyData(void);
    KeyData(Point c, uint8_t kc);
    Point     c;          // Center position
    uint8_t   kc;         // HP35 Key code
};

class KeyB35 {
  public:
    KeyB35(Adafruit_FT6206 *ctp);
    bool isTapped(void);
    byte getKey(void);
    Point getPoint(void);
    Point getCenter(uint8_t i);
  protected:
    void initKeyLookup(void);
  private:
    Adafruit_FT6206 *ctp;
    Point lastPoint;
};

#endif
