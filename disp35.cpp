#include <Adafruit_ILI9341.h>           
#include <Adafruit_ImageReader.h> 

#include "disp35.h"
#include "disp35_defs.h"

#define KEYB_FILE       "/hp35_240x298.bmp"

#define BLACK   0x0000
#define RED     0xF800

#define SD_CS   4 // SD card select pin

SdFat                   SD;         // SD card filesystem
Adafruit_ImageReader    reader(SD); // Image-reader object
Adafruit_Image          img;        // An image loaded into RAM

Disp35::Disp35(Adafruit_ILI9341 *tft) {
  this->tft = tft;
  tft->begin();
  tft->fillScreen(BLACK);
  SD.begin(SD_CS, SD_SCK_MHZ(25));
  reader.drawBMP(KEYB_FILE, *tft, 0, 22); 
}

void Disp35::drawCross(Point center, uint8_t len) {
  tft->drawFastHLine(center.x - len, center.y, 2 * len, ILI9341_RED);
  tft->drawFastVLine(center.x, center.y - len, 2 * len, ILI9341_RED);
}

void Disp35::drawSegments(byte pos, bool a, bool b, bool c, bool d, bool e, bool f, bool g, bool dp) {
  if ((pos < 0) || (pos > 14)) return;
  if (a)
    tft->drawFastHLine(PA(pos), RED);
  else
    tft->drawFastHLine(PA(pos), BLACK);
  if (b)
    tft->drawFastVLine(PB(pos), RED);
  else
    tft->drawFastVLine(PB(pos), BLACK);
  if (c)
    tft->drawFastVLine(PC(pos), RED);
  else
    tft->drawFastVLine(PC(pos), BLACK);
  if (d)
    tft->drawFastHLine(PD(pos), RED);
  else
    tft->drawFastHLine(PD(pos), BLACK);
  if (e)
    tft->drawFastVLine(PE(pos), RED);
  else
    tft->drawFastVLine(PE(pos), BLACK);
  if (f)
    tft->drawFastVLine(PF(pos), RED);
  else
    tft->drawFastVLine(PF(pos), BLACK);
  if (g)
    tft->drawFastHLine(PG(pos), RED);
  else
    tft->drawFastHLine(PG(pos), BLACK);
  if (dp) {
    tft->drawFastHLine(PDP(pos), RED);
    tft->drawFastHLine(PDP2(pos), RED);
  } else {
    tft->drawFastHLine(PDP(pos), BLACK);
    tft->drawFastHLine(PDP2(pos), BLACK);
  }
}

void Disp35::drawDigit(byte pos, int digit, bool dp) {
  switch (digit) {
    case 0:
      drawSegments(pos, 1, 1, 1, 1, 1, 1, 0, dp);
      break;
    case 1:
      drawSegments(pos, 0, 1, 1, 0, 0, 0, 0, dp);
      break;
    case 2:
      drawSegments(pos, 1, 1, 0, 1, 1, 0, 1, dp);
      break;
    case 3:
      drawSegments(pos, 1, 1, 1, 1, 0, 0, 1, dp);
      break;
    case 4:
      drawSegments(pos, 0, 1, 1, 0, 0, 1, 1, dp);
      break;
    case 5:
      drawSegments(pos, 1, 0, 1, 1, 0, 1, 1, dp);
      break;
    case 6:
      drawSegments(pos, 1, 0, 1, 1, 1, 1, 1, dp);
      break;
    case 7:
      drawSegments(pos, 1, 1, 1, 0, 0, 0, 0, dp);
      break;
    case 8:
      drawSegments(pos, 1, 1, 1, 1, 1, 1, 1, dp);
      break;
    case 9:
      drawSegments(pos, 1, 1, 1, 1, 0, 1, 1, dp);
      break;
    case 10: // -
      drawSegments(pos, 0, 0, 0, 0, 0, 0, 1, dp);
      break;
    case 99: // DP
      drawSegments(pos, 0, 0, 0, 0, 0, 0, 0, dp);
      break;
    default: // Blank
      drawSegments(pos, 0, 0, 0, 0, 0, 0, 0, 0);
      break;
  }
}

// EOF
