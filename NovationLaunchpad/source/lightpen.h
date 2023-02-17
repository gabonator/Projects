class CAppLightpen : public CApp
{
  uint32_t clr{0xff00ab};
  uint8_t map[100] = {0};
  int32_t last{0};

public:

  uint32_t fade(uint8_t& v)
  {
    if (v == 0)
      return 0;
    int r = (clr >> 16) & 255;
    int g = (clr >> 8) & 255;
    int b = (clr >> 0) & 255;
    r = r * v / 256;
    g = g * v / 256;
    b = b * v / 256;
    v--;
    return (r<<16) | (g<<8) | b;
  }

  uint32_t hue(int h)
  {
    auto RGB = [](int r, int g, int b) { 
      return (r << 16) | (g << 8) | b;
    };

    h %= 1536;

    if (h >= 0 && h < 256)
      return RGB(255, h, 0);
    else if (h >= 256 && h < 512)
      return RGB(255 - h % 256, 255, 0);
    else if (h >= 512 && h < 768)
      return RGB(0, 255, h % 256);
    else if (h >= 768 && h < 1024)
      return RGB(0, 255 - h % 256, 255);
    else if (h >= 1024 && h < 1280)
      return RGB(h % 256, 0, 255);
    else
      return RGB(255, 0, 255 - h % 256);
  }

  virtual void loop() override
  {
    if (ticks() - last < 5)
      return;
    last = ticks();

    clr = hue(ticks() >> 2);

    for (int y=0; y<9; y++)
      for (int x=0; x<9; x++)
        pixel(x, y) = fade(map[y*10+x]);
  }

  virtual void onPress(int x, int y, int v) override
  {
    map[y*10 + x] = 255;
  }
};
