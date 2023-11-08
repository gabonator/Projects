class CAppDrops : public CApp
{
  struct drop_t
  {
    int x, y, vy;
    bool active;
    uint32_t color;
    int timer;
    bool bomb;
  };
  drop_t explosion;
  CArray<drop_t, 10> drops;
  int32_t last;
  CPRNG random;
  int snow[8];
  int active{0};
  uint8_t activeColumn[8];
  int score{0};
  bool godMode{false};
  bool gameOver{false};
public:
  virtual void enter() override
  {
    for (int y=0; y<9; y++)
      for (int x=0; x<9; x++)
        pixel(x, y) = 0;

    drops.count = 10;
    for (int i=0; i<drops.count; i++)
      drops[i].active = false;
    for (int i=0; i<8; i++)
    {
      snow[i] = 0;
      activeColumn[i] = 0;
    }
    score = 0;
    explosion.active = false;
    active = 0;
    gameOver = false;
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
  bool shouldAddNewDrop()
  {
    int maxDrops = 2;
    if (score > 5)
      maxDrops = 3;
    if (score > 50)
      maxDrops = 4;
    if (score > 100)
      maxDrops = 5;
    if (score > 150)
      maxDrops = 6;
    if (score > 300)
      maxDrops = 7;
    if (score > 400)
      maxDrops = 8;
    return active < maxDrops && random.get()%17 == 0;
  }
  bool addRandomDropAt(int column)
  {
    if (column == -1)
      return false;
    score++;
    for (int i=0; i<drops.count; i++)
    {
      drop_t& drop = drops[i];
      if (drop.active)
        continue;
      drop.active = true;
      drop.x = column;
      drop.y = 0;
      drop.color = hue(random.get());
      if (score < 25)
        drop.vy = 400 + random.get()%500;
      else if (score < 75)
        drop.vy = 300 + random.get()%1000;
      else if (score < 200)
        drop.vy = 200 + random.get()%1500;
      else
        drop.vy = 200 + random.get()%2000;
      drop.timer = -100;
      drop.bomb = random.get() % 16 == 0;
      if (drop.bomb)
        drop.vy = 400; ///= 2;
      pixel(drop.x, drop.y >> 16) = drop.color;
      active++;
      activeColumn[column] = 1;
      return true;
    }
    return false;
  }
  int findRandomFreeColumn()
  {
    for (int i=0; i<5; i++)
    {
      int c = random.get()%8;
      if (activeColumn[c] == 0 && snow[c] < 8)
        return c;
    }
    return -1;
  }
  uint32_t bombAnim(uint32_t c, int t)
  {
    const uint8_t fade[8] = {0, 31, 63, 127, 100, 63, 31, 15};
    uint32_t clr = fade[t%8];
    return c | clr | (clr<<8) | (clr<<16);
  }
  bool isFull()
  {
    for (int i=0; i<8; i++)
      if (snow[i] < 8)
        return false;
    return true;
  }
  bool isClear()
  {
    for (int i=0; i<8; i++)
      if (snow[i] > 0)
        return false;
    return true;
  }
  virtual void loop() override
  {
    if (ticks() - last < 5)
      return;
    last = ticks();

    doExplosion();
    if (gameOver || isFull())
    {
      gameOver = true;
      doGameOver();
      if (isClear())
      {
        gameOver = false;
        appMarquee.show(this, "Game over   Rain score \x7f ", score);
        appTransition.chain(&appMarquee);
        go(appTransition);
        score = 0;
      }
      return;
    }
    if (shouldAddNewDrop())
    {
      int c = findRandomFreeColumn();
      addRandomDropAt(c);
    }
    
    for (int i=0; i<drops.count; i++)
    {
      drop_t& drop = drops[i];
      if (!drop.active)
        continue;
      if (drop.bomb)
        pixel(drop.x, drop.y >> 16) = bombAnim(drop.color, drop.timer);
      if (drop.timer++ < 0)
        continue;
      int lasty = drop.y >> 16;
      drop.y += drop.vy;
      int newy = drop.y >> 16;
      if (lasty != newy)
      {
        if (newy > 8-snow[drop.x])
        {
          if (!explosion.active && drop.bomb)
            explosion = drop;
          snow[drop.x]++;
          drop.active = false; 
          active--;
          activeColumn[drop.x] = 0;
        } else if (newy <= 8)
        {
          pixel(drop.x, lasty) = 0;
          pixel(drop.x, newy) = drop.color;
        }
      }
    }
  }
  void doGameOver()
  {
    if (!explosion.active)
    {
      int x = random.get() % 8;
      if (snow[x] > 0)
      {
        int y = 8-(random.get() % snow[x]);
        explosion.x = x;
        explosion.y = y << 16;
        explosion.active = true;
        explosion.color = 0xff0000;
      }  
    }
  }
  void doExplosion()
  {
    if (!explosion.active)
      return;

    int r = explosion.color >> 16;
    int g = (explosion.color >> 8) & 255;
    int b = (explosion.color >> 0) & 255;
    bool animFinished = r == 0 && g == 0 && b == 0;
    r = max(0, r-4);
    g = max(0, g-4);
    b = max(0, b-4);
    explosion.color = (r<<16) | (g<<8) | b;
    if (animFinished)
    {
      if (explosion.timer == 0)
      {
        explosion.timer = gameOver ? 5 : 30;
        bool nogap = true;
        for (int _x=0; _x<8 && nogap; _x++)
          for (int _y=9-snow[_x]; _y<9 && nogap; _y++)
            if (pixel(_x, _y) == 0)
            {
              nogap = false;
              for (int __y=_y; __y > 9-snow[_x]; __y--)
                pixel(_x, __y) = pixel(_x, __y-1);
              pixel(_x, 9-snow[_x]) = 0;
              snow[_x]--;
            }
        if (nogap)
          explosion.active = false;
      } else {
        explosion.timer--;
      }
    } else
    {
      explosion.timer = gameOver ? 10 : 100;
      for (int _x=-1; _x<=1; _x++)
        for (int _y=-1; _y<=1; _y++)
        {
          int __x = _x + explosion.x;
          int __y = _y + (explosion.y>>16);
          if (__x >= 0 && __x < 8 && __y >= 0 && __y < 9)
            pixel(__x, __y) = explosion.color;
        }
    }
  }
  virtual void onPress(int x, int y, int v) override
  {
    if (godMode)
    {
      explosion.x = x;
      explosion.y = y << 16;
      explosion.active = true;
      explosion.color = 0xffffff;
      return;
    }
    random.addEntropy(ticks());
    for (int i=0; i<drops.count; i++)
    {
      drop_t& drop = drops[i];
      if (!drop.active)
        continue;
      if (x == drop.x && y == (drop.y >> 16))
      {
        activeColumn[x] = 0;
        pixel(x, y) = 0;
        drop.active = false;
        active--;
      }
    }
  }
};
