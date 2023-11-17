class CAppSnake : public CApp
{
  struct vector_t {
    int8_t dx;
    int8_t dy;
    bool operator != (const vector_t& v)
    {
      return dx != v.dx || dy != v.dy;
    }
  };
  struct point_t {
    uint8_t x{0};
    uint8_t y{0};
    point_t() = default;
    point_t(uint8_t _x, uint8_t _y) : x{_x}, y{_y} {}
    void operator += (const vector_t& v)
    {
      x += v.dx;
      y += v.dy;
    }
    bool operator == (const point_t& p)
    {
      return x == p.x && y == p.y;
    }
    bool operator != (const point_t& p)
    {
      return x != p.x || y != p.y;
    }
  };
  point_t pos{8, 8};
  vector_t dir{0, 0};

  CArray<point_t, 32> tail;
  int tailLen = 4;
  point_t tailLast{0, 0};
  int32_t tailTime{0};

  point_t apple{0, 0};
  int appleLevel{0};
  int32_t appleDisappear{0};
  int32_t appleAppear{0};

  int score{0};
  int speed{400};
  char game[16*16+1] = 
    "################"
    "#              #"
    "#      ####    #"
    "#      #       #"
    "#  #   #   #   #"
    "#  #   #   #   #"
    "#  #       #   #"
    "#  #      ##   #"
    "#  #           #"
    "#  #        #  #"
    "#  ######   #  #"
    "#           #  #"
    "#    ########  #"
    "#              #"
    "#              #"
    "################";

  int32_t passed = 0;
  int32_t last = 0;

public:
  void reset()
  {
    score = 0;
    speed = 400;
    pos = {8, 8};
    dir = {0, 0};
    tail.count = 0;
    tailTime = 0;
    tailLen = 4;
    for (int y=0; y<16; y++)
      for (int x=0; x<16; x++)
        if (game[y*16+x] == 'h' || game[y*16+x] == 'o')
          game[y*16+x] = ' ';
  }

  virtual void enter() override
  {
    last = ticks();
  }

  void doApple()
  {
    if (appleDisappear != 0)
    {
      int32_t sinceEat = ticks() - appleDisappear;
      appleLevel = (1000-sinceEat) * 32 / 1000;
      if (appleLevel <= 0)
      {
        appleLevel = 0;
        apple = {0, 0};
        appleDisappear = 0;
      }
    }
    if (appleAppear != 0)
    {
      int32_t sinceShow = ticks() - appleAppear;
      appleLevel = sinceShow * 32 / 1000;
      if (appleLevel >= 32)
      {
        appleLevel = 32;
        appleAppear = 0;
      }
    }
    if (apple == point_t{0, 0})
    {
      apple.x = gRandom.get() % 16;
      apple.y = gRandom.get() % 16;
      if (game[apple.y*16+apple.x] == ' ')
      {
        game[apple.y*16+apple.x] = '*';
        appleLevel = 0;
        appleAppear = ticks();
      } else {
        apple = {0, 0};
        appleLevel = 0;
      }
    }
  }

  virtual void loop() override
  {
    doApple();
    if (!doMove())
    {
      die();
      reset();
      return;
    }
    doDraw();
  }

  void die()
  {
    if (score > 2)
    {
      appMarquee.show(this, "Game over   Snake score \x7f ", score);
      appTransition.chain(&appMarquee);
      go(appTransition);
    } else {
      appTransition.chain(this);
      go(appTransition);
    }
  }

  bool doMove()
  {
    passed += ticks()-last;
    last = ticks();
    while (passed > speed)
    {
      passed -= speed;
      pos += dir;
      if (dir != vector_t{0, 0} && game[pos.y*16+pos.x] != ' ')
      {
        if (game[pos.y*16+pos.x] == '*')
        {
          score++;
          if (speed > 100)
            speed -= 5;
          appleDisappear = ticks();
          if (tailLen < 63)
            tailLen++;
        } else {
          return false;
        }
      }
      game[pos.y*16+pos.x] = 'h';
      if (tail[0] != pos)
      {
        if (tail.count == tailLen-1)
        {
          tailLast = tail.last();
          tailTime = ticks();
          game[tail.last().y*16+tail.last().x] = ' ';
          tail.count--;
        }
        for (int i=tail.count-1; i>=0; i--)
        {
          game[tail[i].y*16+tail[i].x] = 'o';
          tail[i+1] = tail[i];
        }
        tail.count++;
        tail[0] = pos;
      }
    }
    return true;
  }
  virtual uint32_t getMapPixel(int x, int y)
  {
    point_t mappos(x, y);
    mappos.x = min<int>(max<int>(0, mappos.x), 15);
    mappos.y = min<int>(max<int>(0, mappos.y), 15);
    uint32_t color = 0;
    if (apple != point_t{0, 0})
    {
      int dist = (mappos.x-apple.x)*(mappos.x-apple.x)+(mappos.y-apple.y)*(mappos.y-apple.y);
      dist = (60-(dist))*appleLevel/60;
      if (dist < 0)
        dist = 0;
      color = dist;
    }
    switch (game[mappos.y*16+mappos.x])
    {
      case ' ': break;
      case '#': color = 0x404040; break;
      case '*': color = 0x0000b0; break;
      case 'o': color = (color & 0xff00ff) | 0x008000; break;
      case 'h':
      {
        int tim = (ticks()>>2)&511;
        tim = tim <= 255 ? tim : 511-tim;
        color = (color & 0xff00ff) | (tim << 8);
      }
      break;
    }
    if (tailLast == mappos && tailTime != 0)
    {
      int passed = ticks() - tailTime;
      if (passed > 200)
        tailTime = 0;
      else
        color = (color & 0xff00ff) | (((200-passed)*0x80/200) << 8);
    }   
    return color;
  }

  void doDraw()
  {
    for (int y=0; y<9; y++)
      for (int x=0; x<9; x++)
      {
        uint32_t color = getMapPixel(pos.x+x-4, pos.y+y-4);
        if ((y == 7 && x == 7) || (y == 8 && x >= 6))
          color |= 0x8f8f00;
        pixel(x, y) = color;
      }
  }

  virtual void onPress(int x, int y, int v) override
  {
    auto safe = [&](int dx, int dy) -> bool {
      char b = game[(pos.y+dy)*16+pos.x+dx];
      return b == ' ' || b == '*';
    };

    gRandom.addEntropy(ticks());
    switch (y*10+x)
    {
      case 77: if (safe(0, -1)) {dir.dx = 0; dir.dy = -1;} break;
      case 86: if (safe(-1, 0)) {dir.dx = -1; dir.dy = 0;} break;
      case 87: if (safe(0, 1)) {dir.dx = 0; dir.dy = +1;} break;
      case 88: if (safe(1, 0)) {dir.dx = +1; dir.dy = 0;} break;
    }
  }

  uintptr_t api(EApiCall e, int x, int y) override
  {
    switch (e)
    {
      case EApiCall::Name: return (uintptr_t)"Snake";
      case EApiCall::Type: return (uintptr_t)EApiValue::TypeDynamic | (uintptr_t)EApiValue::TypeArrows;
      case EApiCall::Width: return 16;
      case EApiCall::Height: return 16;
      case EApiCall::GetPixel: return getMapPixel(x, y);
      case EApiCall::GetPosX: return pos.x-3;
      case EApiCall::GetPosY: return pos.y-3;
      default: return 0;
    }
  }
};
