#include "gpio_digital.h"

class CAppTemperature : public CApp, CGpio
{
  int32_t last;
  uint32_t tick{0};
  uint32_t phase{0};

public:
  virtual void enter() override
  {
    GpioSet();
    pinMode(CGpio::P1, CGpio::INPUT);
    for (int y=0; y<9; y++)
      for (int x=0; x<9; x++)
        pixel(x, y) = 0;
  }

  virtual void leave() override
  {
    GpioReset();
  }

  int waitHigh()
  {
    int count = 0;
    while (digitalRead(CGpio::P1))
    {
      delayUs(10);
      count++;
      if (count > 20) // 200 us max
        break;
    }
    return count;
  }

  int waitLow()
  {
    int count = 0;
    while (!digitalRead(CGpio::P1))
    {
      delayUs(10);
      count++;
      if (count > 20) // 200 us max
        break;
    }
    return count;
  }

  const char* measure(int& deg10, int& hum10)
  {
    waitHigh(); // 20-40 us
    int syncLow = waitLow(); // 7-8 -> 80 us
    if (syncLow < 6 || syncLow > 9)
      return "Error: sync-low";

    int syncHigh = waitHigh(); // 7-8 -> 80 us
    if (syncHigh < 6 || syncHigh > 9)
      return "Error: sync-high";

    uint8_t data[5] = {0};
    for (int j=0; j<5; j++)
      for (int i=0; i<8; i++)
      {
        int low = waitLow(); // 5-6 -> 50 us
        int high = waitHigh(); // 3 -> log 0: 20-30 us, log1: 70us
        if (low < 4 || low > 7)
          return "Error: bit-low";
        data[j] <<= 1;
        if (high >= low)
          data[j] |= 1;
      }

    if (data[4] != (uint8_t)(data[0] + data[1] + data[2] + data[3]))
      return "Error: crc";

    hum10 = (int16_t)((data[0]<<8) | data[1]);
    deg10 = (int16_t)((data[2]<<8) | data[3]);
    return nullptr;
  }

  virtual void loop() override
  {
    // called every 300us
    if (ticks() - last < 10)
      return;
    last = ticks();

    if (tick == 0)
    {
      pinMode(CGpio::P1, CGpio::OUTPUT);
      digitalWrite(CGpio::P1, CGpio::LOW);
    }
    else if (tick == 2) // 20 ms reset pulse
    {
      digitalWrite(CGpio::P1, CGpio::HIGH);
      delayUs(20);
      pinMode(CGpio::P1, CGpio::INPUT);
      digitalWrite(CGpio::P1, CGpio::HIGH);
      int hum10, deg10;
      const char* status = measure(deg10, hum10);
      if (status == nullptr)
      {
        char temp[20];
        if (phase++ % 2 == 0)
          format(temp, "Temperature ", deg10, " C");
        else
          format(temp, "Humidity ", hum10, "%");
        appMarquee.showSingle(this, temp);
      }
      else
        appMarquee.showSingle(this, status);
      go(appMarquee);
    }
    else if (tick >= 100)
    {
      // retry in 1 second
      tick = 0;
      return;
    }
    tick++;
  }

  virtual void onPress(int x, int y, int v) override
  {
  }

  void format(char* text, const char* prefix, int num, const char* suffix)
  {
    strcpy(text, prefix);
    char* p = text+strlen(text);
    if (num < 0)
    {
      *p++ = '-';
      num = -num;
    }
    if (num >= 100)
    {
      *p = '0';
      while (num >= 100)
      {
        (*p)++;
        num -= 100;
      }
      p++;
    }
    if (num >= 10)
    {
      *p = '0';
      while (num >= 10)
      {
        (*p)++;
        num -= 10;
      }
      p++;
    }
    *p++ = '.';
    *p++ = '0' + num;
    *p = 0;
    strcat(text, suffix);
  }

  void debugIntervals(int row, int num)
  {
    if (num <= 0)
    {
      pixel(0, row) = 0x0000ff;
      pixel(1, row) = 0x000040;
      pixel(2, row) = 0x000040;
      pixel(3, row) = 0x000040;
      pixel(4, row) = 0x000040;
      pixel(5, row) = 0x000040;
      pixel(6, row) = 0x000040;
      pixel(7, row) = 0x000000;
      return;
    }
    if (num >= 9)
    {
      pixel(0, row) = 0xff0000;
      pixel(1, row) = 0x400000;
      pixel(2, row) = 0x400000;
      pixel(3, row) = 0x400000;
      pixel(4, row) = 0x400000;
      pixel(5, row) = 0x400000;
      pixel(6, row) = 0x000000;
      pixel(7, row) = 0x000000;
      return;
    }
    pixel(0, row) = 0x00ff00;
    pixel(1, row) = num >= 1 ? 0x808080 : 0x000000;
    pixel(2, row) = num >= 2 ? 0x808080 : 0x000000;
    pixel(3, row) = num >= 3 ? 0x808080 : 0x000000;
    pixel(4, row) = num >= 4 ? 0x808080 : 0x000000;
    pixel(5, row) = num >= 5 ? 0x808080 : 0x000000;
    pixel(6, row) = num >= 6 ? 0x808080 : 0x000000;
    pixel(7, row) = num >= 7 ? 0x808080 : 0x000000;
    pixel(8, row) = num >= 8 ? 0x808080 : 0x000000;
  }
};
