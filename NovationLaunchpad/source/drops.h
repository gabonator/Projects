class CAppDrops : public CApp
{
  struct drop_t
  {
    bool active;
    uint32_t color;
    int x, y, vy;
  };
  CArray<drop_t, 10> drops;
  int32_t last;
  CPRNG random;
  int counter{0};
  int snow[8];
  int active{0};
public:
  virtual void enter() override
  {
    for (int y=0; y<9; y++)
      for (int x=0; x<9; x++)
        pixel(x, y) = 0;

    for (int i=0; i<10; i++)
      drops[i].active = false;
    for (int i=0; i<8; i++)
      snow[i] = 0;
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
    drops.count = 10;
    if (active < 3 && random.get()%17 == 0)
    {
      counter = 0;
      for (int i=0; i<drops.count; i++)
      {
        drop_t& drop = drops[i];
        if (drop.active)
          continue;
        drop.active = true;
        drop.x = random.get()%8;
        drop.y = 0;
        drop.color = hue(random.get());
        drop.vy = 200  + random.get()%2000;
        pixel(drop.x, drop.y >> 16) = drop.color;
        active++;
        break;
      }
    }
    
    for (int i=0; i<drops.count; i++)
    {
      drop_t& drop = drops[i];
      if (!drop.active)
        continue;
      int lasty = drop.y >> 16;
      drop.y += drop.vy;
      int newy = drop.y >> 16;
      if (lasty != newy)
      {
        pixel(drop.x, lasty) = 0;
        pixel(drop.x, newy) = drop.color;
        if (newy > 7-snow[drop.x])
        {
          snow[drop.x]++;
          pixel(drop.x, newy) = drop.color;
          drop.active = false; 
          active--;
        }
      }
    }
  }

  virtual void onPress(int x, int y, int v) override
  {
    random.addEntropy(ticks());
    for (int i=0; i<drops.count; i++)
    {
      drop_t& drop = drops[i];
      if (!drop.active)
        continue;
      if (x == drop.x && y == (drop.y >> 16))
      {
        pixel(x, y) = 0;
        drop.active = false;
        active--;
      }
    }
  }
};
