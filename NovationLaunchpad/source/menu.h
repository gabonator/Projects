extern "C" {
  extern uint16_t fontOffsets[97];
  extern uint8_t fontData[425];
}

static const char* labels[] = {
  "Paint", "Color test", "Snake", "Light pen", "Rain", 
  "Flappy bird", "Tic tac toe", "Adventure", 
  "Water"
};

static const uint32_t colors[] = {
  0xff0000, 0x0020ff, 0x00ff00, 0xff0080, 
  0x00ff80, 0x80ff00, 0x80ff80, 0x00ff00,
  0xff0000
};

CApp* apps[] = {
  &appPaint, &appColortest, &appSnake, &appLightpen, 
  &appDrops, &appFlappybird, &appTictactoe, &appAdventure,
  &appWater};

class CAppMenu : public CApp
{
  int sx{0};
  int sy{5*8};
  int ty{5*8};
  int last;
  int wait;
  int dir;

public:
  virtual void enter() override
  {
    for (int x=0; x<9; x++)   
      pixel(x, 0) = 0;
    last = 0;
    wait = 10;
    dir = 1;
  }

  virtual void loop() override
  {
    if (ticks() - last < 60)
      return;
    last = ticks();

    if (ty>sy+8)
      sy++;
    if (ty<sy-8)
      sy--;

    if (ty>sy)
      sy++;
    else if (ty<sy)
      sy--;
    if (wait > 0)
      wait--;
    else
    {
      sx += dir;

      if (dir == 1 && sx > getTextWidth(labels[sy/8])-9)
      {
        wait = 50;
        dir = -1;
      }
      if (dir == -1 && sx <= 0)
      {
        sx = 0;
        dir = 1;
        wait = 100;
      }
    }

    uint8_t buffer[9] = {0};
    renderText(buffer, -sx, sy%8, labels[sy/8]);
    if (sy/8+1 < sizeof(labels)/sizeof(labels[0]))
      renderText(buffer, -sx, (sy%8)-8, labels[sy/8+1]);

    for (int y=0; y<8; y++)
      for (int x=0; x<9; x++)   
        pixel(x, y+1) = (buffer[x] & (1<<y)) ? colors[(y+sy)/8] : 0x000000;
  }

  virtual void onPress(int x, int y, int v) override
  {
    if (x+y*10 == 0 && ty > 0)
    {
      ty -= 8;
      wait = 0;
      dir = -1;
    }
    if (x+y*10 == 1 && ty+8 < sizeof(labels)/sizeof(labels[0])*8)
    {
      ty += 8;
      wait = 0;
      dir = -1;
    }
    if (x+y*10 == 2 || x+y*10 == 3)
    {
      sx = 0;
      wait = 100;
      dir = 1;
      go(*apps[sy/8]);
    }
  }
};
