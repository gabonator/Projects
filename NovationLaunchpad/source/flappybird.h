class CAppFlappybird : public CApp
{
  uint8_t map[9][8];
  int dy{0};
  int y{4*256};
  int tick;
  int walltick;
  int multitick;
  int wallr;
  int32_t last;
  int score;
  int high{10};

public:
  virtual void enter() override
  {
    for (int y=0; y<8; y++)
      for (int x=0; x<9; x++)
        pixel(x, y+1) = 0;
    last = ticks();
    reset();
  }

  void reset()
  {
    for (int y=0; y<8; y++)
      for (int x=0; x<9; x++)
        map[x][y] = 0;

    y = 4*256;
    dy = 0;
    tick = 0;
    walltick = 0;
    multitick = 0;
    score = 0;
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
    int multi = 1;
    int hole = 3;
    uint32_t color = 0xff0000;
    uint32_t back = 0x000000;
    setLevelByScore(score, speed, distance, multi, hole, color, back);

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
        if (multitick == 0)
        {
          wallr = gRandom.get();
        }
        if (++multitick >= multi)
        {
          score++;
          walltick = 0;	
          multitick = 0;
        }

        makeWall(wallr, hole);
      }
    }
    for (int y=0; y<8; y++)
      for (int x=0; x<9; x++)
        pixel(x, y+1) = map[x][y] ? color : back;

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
        if (score > 2)
        {
          if (score > high)
          {
            high = score;
            appMarquee.show(this, "Game over   Flappy bird   New high score \x7f ", score);
          } else {
            appMarquee.show(this, "Game over   Flappy bird score \x7f ", score);
          }
          reset();
          appTransition.chain(&appMarquee);
          go(appTransition);
        } else {
          reset();
          appTransition.chain(this);
          go(appTransition);
        }
      }
    }
  }

  virtual void onPress(int x, int y, int v) override
  {
    dy = -20;
  }

  void setLevelByScore(int score, int& speed, int& distance, int& multi, int& hole, uint32_t& color, uint32_t& back)
  {
    int level = score/10;
    int spd = max(4, 20 - level/4);
    switch (level/4)
    {
      case 0: 
        back = 0x000000;
        break;
      case 1: 
        back = 0x000040;
        break;
      case 2: 
        back = 0x0000b0;
        break;
      case 3: 
        back = 0x004000;
        break;
      case 4: 
        back = 0x00b000;
        break;
    }
    switch (level % 4)
    {
      case 0:
        color = 0xff0000;
        speed = spd;
        distance = 5;
        multi = 1;
        hole = 2;
        break;
      case 1:
        color = 0xffff00;
        speed = max(4, spd - 10);
        distance = 5;
        multi = 1;
        hole = 3;
        break;
      case 2:
        color = 0x00ff00;
        speed = spd;
        distance = 3;
        multi = 1;
        hole = 2;
        break;
      case 3:
        color = 0x00ffff;
        speed = spd;
        distance = 5;
        multi = 2;
        hole = 2;
        break;
    }
  }

  void makeWall(int r, int hole)
  {
    if (hole == 2)
      r %= 9;
    else
      r %= 4;

    for (int y=0; y<8; y++)
      map[8][y] = 1;
    switch (r)
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
};
