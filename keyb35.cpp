#include "keyb35.h"
#include "keyb35_defs.h"


KeyData keyLookup[35];  // Key lookup table. Why 35? :)

Point::Point(void) {}
Point::Point(uint8_t x, uint16_t y) {
  this->x = x;
  this->y = y;
}

KeyData::KeyData(void) {}
KeyData::KeyData(Point c, uint8_t kc) {
  this->c = c;
  this->kc = kc;
}

KeyB35::KeyB35(Adafruit_FT6206 *ctp) {
  this->ctp = ctp;
  ctp->begin(40);
  initKeyLookup();
}

void KeyB35::initKeyLookup(void) {
  for (int i = 0; i < 35; i++) {
    switch (i) {
      case 0: keyLookup[i] = KeyData(KEY0); break;
      case 1: keyLookup[i] = KeyData(KEY1); break;
      case 2: keyLookup[i] = KeyData(KEY2); break;
      case 3: keyLookup[i] = KeyData(KEY3); break;
      case 4: keyLookup[i] = KeyData(KEY4); break;
      case 5: keyLookup[i] = KeyData(KEY5); break;
      case 6: keyLookup[i] = KeyData(KEY6); break;
      case 7: keyLookup[i] = KeyData(KEY7); break;
      case 8: keyLookup[i] = KeyData(KEY8); break;
      case 9: keyLookup[i] = KeyData(KEY9); break;
      case 10: keyLookup[i] = KeyData(KEY10); break;
      case 11: keyLookup[i] = KeyData(KEY11); break;
      case 12: keyLookup[i] = KeyData(KEY12); break;
      case 13: keyLookup[i] = KeyData(KEY13); break;
      case 14: keyLookup[i] = KeyData(KEY14); break;
      case 15: keyLookup[i] = KeyData(KEY15); break;
      case 16: keyLookup[i] = KeyData(KEY16); break;
      case 17: keyLookup[i] = KeyData(KEY17); break;
      case 18: keyLookup[i] = KeyData(KEY18); break;
      case 19: keyLookup[i] = KeyData(KEY19); break;
      case 20: keyLookup[i] = KeyData(KEY20); break;
      case 21: keyLookup[i] = KeyData(KEY21); break;
      case 22: keyLookup[i] = KeyData(KEY22); break;
      case 23: keyLookup[i] = KeyData(KEY23); break;
      case 24: keyLookup[i] = KeyData(KEY24); break;
      case 25: keyLookup[i] = KeyData(KEY25); break;
      case 26: keyLookup[i] = KeyData(KEY26); break;
      case 27: keyLookup[i] = KeyData(KEY27); break;
      case 28: keyLookup[i] = KeyData(KEY28); break;
      case 29: keyLookup[i] = KeyData(KEY29); break;
      case 30: keyLookup[i] = KeyData(KEY30); break;
      case 31: keyLookup[i] = KeyData(KEY31); break;
      case 32: keyLookup[i] = KeyData(KEY32); break;
      case 33: keyLookup[i] = KeyData(KEY33); break;
      case 34: keyLookup[i] = KeyData(KEY34); break;
    }
  }
}

byte KeyB35::getKey(void) {
  byte key = 255;
  Point p = getPoint();
  for (int i = 0; i < 35; i++) {
    Point c = keyLookup[i].c;
    if ((abs(p.x - c.x) < DX) && (abs(p.y - c.y) < DY)) {
      key = keyLookup[i].kc;
      break;
    }
  }
  return key;
}

Point KeyB35::getPoint(void) {
  return lastPoint;
}

Point KeyB35::getCenter(uint8_t i) {
  return keyLookup[i].c;
}

bool KeyB35::isTapped(void) {
  bool isTapped = ctp->touched();
  if (isTapped) {
    TS_Point ts_p = ctp->getPoint();
    lastPoint.x = map(ts_p.x, 0, 240, 240, 0);
    lastPoint.y = map(ts_p.y, 0, 320, 320, 0);
  }
  return isTapped;
}

// EOF
