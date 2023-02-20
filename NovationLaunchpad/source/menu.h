
static const uint8_t menu[] = {
    0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
    0b00010000, 0b11111100, 0b01111100, 0b11110000, 0b11111000, 0b11111000, 0b01111000, 0b00000000,
    0b00101000, 0b10000010, 0b10000010, 0b10001000, 0b10000000, 0b10000000, 0b10000100, 0b00000000,
    0b00101000, 0b10000010, 0b10000000, 0b10000100, 0b10000000, 0b10000000, 0b10000000, 0b00000000,
    0b01000100, 0b11111100, 0b10000000, 0b10000100, 0b11110000, 0b11110000, 0b10011100, 0b00000000,
    0b01111100, 0b10000010, 0b10000000, 0b10000100, 0b10000000, 0b10000000, 0b10000100, 0b00000000,
    0b10000010, 0b10000010, 0b10000010, 0b10001000, 0b10000000, 0b10000000, 0b10000100, 0b00000000,
    0b10000010, 0b11111100, 0b01111100, 0b11110000, 0b11111000, 0b10000000, 0b01111000, 0b00000000,
    0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
  };

class CAppMenu : public CApp
{
// TODO: can't be inside class - check which section was used, bug in linker script?
#if 0
  /*const*/ uint8_t menu[9*5] = {
    0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000,
    0b00010000, 0b11111100, 0b01111100, 0b11110000, 0b00000000,
    0b00101000, 0b10000010, 0b10000010, 0b10001000, 0b00000000,
    0b00101000, 0b10000010, 0b10000000, 0b10000100, 0b00000000,
    0b01000100, 0b11111100, 0b10000000, 0b10000100, 0b00000000,
    0b01111100, 0b10000010, 0b10000000, 0b10000100, 0b00000000,
    0b10000010, 0b10000010, 0b10000010, 0b10001000, 0b00000000,
    0b10000010, 0b11111100, 0b01111100, 0b11110000, 0b00000000,
    0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000
  };
#endif
  int ofs{0};
  int target{0};
  int32_t last{0};

public:
  uint32_t getPixel(int x, int y)
  {
    int blk = x/8;
    x &= 7;
    return (menu[blk+y*8] & (128>>x)) ? 0x808080 : 0;
  }

  virtual void loop() override
  {
    if (ticks() - last < 10)
      return;
    last = ticks();

    const int k = 32;
    ofs = (ofs*(256-k) + target*k) / 256;

    for (int y=0; y<9; y++)
      for (int x=0; x<8; x++)
        pixel(x, y) = getPixel(ofs/1024+x, y);
  }

  virtual void onPress(int x, int y, int v) override
  {
    if (x == 2 && y == 0 && target > 0)
      target -= 1024*8;
    if (x == 3 && y == 0 && target < 1024*8*7)
      target += 1024*8;
    if (x==0 && y==0)
    {
      switch ((target+256)/1024/8)
      {
        case 0: go(appPaint); break;
        case 1: go(appSnake); break;
        case 2: go(appLightpen); break;
        case 3: go(appDrops); break;
        case 4: go(appFlappybird); break;
        case 5: go(appTictactoe); break;
        case 6: go(appAdventure); break;
      }
    }
  }
};
