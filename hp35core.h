#ifndef HP35CORE_H
#define HP35CORE_H

#include "disp35.h"
#include "keyb35.h"

class HP35Core {
  public:
    HP35Core(Disp35 *disp, KeyB35 *keyb);
    void processKey(byte key);
    void process_rom(void);
    void allDigitsOff(void);
  protected:
    void lcd_HP35(void);
    void print_lcd(unsigned char m);
    byte do_add(byte x, byte y);
    byte do_sub(byte x, byte y);
  private:
    Disp35 *disp;
    KeyB35 *keyb;
};

#endif
