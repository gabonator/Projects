class CAppFlappybird : public CApp
{
  uint8_t map[9][8];
  int dy{0};
  int y{4*256};
  int tick;
  int walltick;
  int32_t last;
  int score;

public:
  virtual void enter() override
  {
    for (int y=0; y<8; y++)
      for (int x=0; x<9; x++)
      {
        map[x][y] = 0;
        pixel(x, y+1) = 0;
      }
    y = 4*256;
    dy = 0;
    tick = 0;
    walltick = 0;
    score = 0;
    last = ticks();
  }

  virtual void loop() override
  {
    if (ticks() - last < 20)
      return;
    last = ticks();

    dy += 1;
    dy = max(-40, min(dy, 40));
    y += dy;
    if (y >= 8*256-1)
      y = 8*256-1;
    if (y < 0)
      y = 0;
    
    int speed = 20;
    int distance = 5;
    if (score > 10)
    {
    }


    if (tick++ >= speed)
    {
      tick = 0;
      for (int y=0; y<8; y++)
        for (int x=1; x<9; x++)
          map[x-1][y] = map[x][y];
      for (int y=0; y<8; y++)
          map[8][y] = 0;

      if (walltick++ >= distance)
      {
        score++;

        walltick = 0;	
        for (int y=0; y<8; y++)
          map[8][y] = 1;
        switch (gRandom.get() % 9)
        {
          case 0:
            map[8][3] = 0;
            map[8][4] = 0;
            map[8][5] = 0;
          break;
          case 1:
            map[8][2] = 0;
            map[8][3] = 0;
            map[8][4] = 0;
          break;
          case 2:
            map[8][1] = 0;
            map[8][2] = 0;
            map[8][3] = 0;
          break;
          case 3:
            map[8][4] = 0;
            map[8][5] = 0;
            map[8][6] = 0;
          break;

          case 4:
            map[8][1] = 0;
            map[8][2] = 0;
          break;
          case 5:
            map[8][2] = 0;
            map[8][3] = 0;
          break;
          case 6:
            map[8][3] = 0;
            map[8][4] = 0;
          break;
          case 7:
            map[8][4] = 0;
            map[8][5] = 0;
          break;
          case 8:
            map[8][5] = 0;
            map[8][6] = 0;
          break;
        }
      }
    }
    for (int y=0; y<8; y++)
      for (int x=0; x<9; x++)
        pixel(x, y+1) = map[x][y] ? 0xff0000 : 0x000000;

    int birdx = 1;
    int birdy = y / 256;
    if (birdy >= 0 && birdy < 8)
    {
      uint32_t clr = 0x00ff00;
      if (dy < 0) // falling, fade to yellow
        clr |= -dy*5;
      else // climbing, fade to cyan
        clr |= (dy*5) << 16;

      pixel(birdx, birdy+1) = clr;
      if (map[birdx][birdy])
      {
        // death
        enter();
      }
    }
  }

  virtual void onPress(int x, int y, int v) override
  {
    dy = -20;
  }
};
