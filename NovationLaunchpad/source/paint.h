class CAppPaint : public CApp
{
  enum {Width = 32};
  uint32_t image[Width][8] = {0};
  uint32_t color = 0xab00cd;
  int scroll;
  int scrollTarget;
  bool blinking{false};
  bool scrollLeftPressed{false};
  bool scrollRightPressed{false};
  int32_t scrollLast{0};
  int speed{1000};

  const uint32_t palette[8] = {
    0x000000, 0xff0000, 0x00ff00, 0x0000ff,
    0xffff00, 0xff00ff, 0x00ffff, 0xffffff};

public:
  virtual void enter() override
  {
    for (int y=0; y<8; y++)
      for (int x=0; x<8; x++)
        pixel(x, y+1) = image[x+scroll][y];

    for (int y=0; y<8; y++)
      pixel(8, y+1) = palette[y];
    pixel(2, 0) = 0x404040;
    pixel(3, 0) = 0x404040;
  }

  virtual void loop() override
  {
    if (blinking)
    {
      if (scrollLast == 0)
        scrollLast = ticks();
      int passed = ticks() - scrollLast;
      if (passed > speed)
      {
        scrollLast = ticks();

        scroll += 8;
        if (scroll >= Width)
          scroll = 0;
        scrollTarget = scroll;

        for (int y=0; y<8; y++)
          for (int x=0; x<8; x++)
            pixel(x, y+1) = image[x+scroll][y];
      }
    }

    if (scroll != scrollTarget)
    {
      int passed = ticks() - scrollLast;
      if (passed > 50)
      {
        scrollLast = ticks();
        if (scrollTarget > scroll)
          scroll++;
        if (scrollTarget < scroll)
          scroll--;

        for (int y=0; y<8; y++)
          for (int x=0; x<8; x++)
            pixel(x, y+1) = image[x+scroll][y];
      }
    }
  }

  virtual void onRelease(int x, int y) override
  {
    int a = y*10 + x;
    if (a == 2)
      scrollLeftPressed = false;
    if (a == 3)
      scrollRightPressed = false;
  }

  virtual void onPress(int x, int y, int v) override
  {
    int a = y*10 + x;
    if (a == 2)
      scrollLeftPressed = true;
    if (a == 3)
      scrollRightPressed = true;

    if (blinking)
    {
      if (a == 2 && speed < 5000)
        speed += 200;
      if (a == 3 && speed > 200)
        speed -= 200;
    } else 
    {
      if (a == 2 && scrollTarget > 0)
        scrollTarget -= 8;
      if (a == 3 && scrollTarget < Width-8)
        scrollTarget += 8;
    }

    if (scrollLeftPressed && scrollRightPressed)
    {
      if (blinking)
      {
        for (int y=0; y<8; y++)
          pixel(8, y+1) = palette[y];
        pixel(2, 0) = 0x404040;
        pixel(3, 0) = 0x404040;
        blinking = false;
      } else
      {
        for (int y=0; y<8; y++)
          pixel(8, y+1) = 0x000000;
        pixel(2, 0) = 0x40b040;
        pixel(3, 0) = 0x40b040;
        blinking = true;
      }
    }

    if (x == 8 && y >= 1 && y <= 8)
      color = palette[y-1];
    if (x>=0 && x<=7 && y >= 1 && y <= 8)
    {
      y--;
      if (pixel(x, y+1) == color)
        image[x+scroll][y] = 0;
      else
        image[x+scroll][y] = color;
      pixel(x, y+1) = image[x+scroll][y];
    }
  }
};
