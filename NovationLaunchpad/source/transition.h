class CAppTransition : public CApp
{
  int32_t last{0};
  int phase;
  CApp* appChain;

public:
  virtual void enter() override
  {
    last = ticks();
    phase = 0;
  }

  void chain(CApp* app)
  {
    appChain = app;
  }

  virtual void loop() override
  {
    if (ticks() - last < 60)
      return;
    last = ticks();
    uint8_t gradient[] = {0x01, 0x03, 0x07, 0x0f, 0x1f, 
      0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, 
      0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00};
    auto grad = [&](int i){ return (i >= 0 && i < sizeof(gradient)) ? gradient[i] : 0;};
    auto rgb = [](int r, int g, int b) {return (r << 16) | (g<<8) | b; };
    if (phase ++ > 34)
    {
      for (int y=0; y<9; y++)
        for (int x=0; x<9; x++)
          pixel(x, y) = 0;
      go(*appChain);
      return;
    }

    for (int y=0; y<9; y++)
      for (int x=0; x<9; x++)
      {
        uint32_t rainbow = rgb(grad(x-y-10+phase), grad(x-y-12+phase), grad(x-y-14+phase));
        if (x-y-12+phase < 10)
          pixel(x, y) |= rainbow;
        else
          pixel(x, y) = rainbow;
      }
  }
};
