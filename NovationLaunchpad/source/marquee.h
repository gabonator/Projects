class CAppMarquee : public CApp
{
  int32_t last{0};
  CApp* retApp;
  char msg[128];
  int x = 0;
  int maxx = 0;
  char message[128];
  bool single{false};
  int speed{45};

public:
  virtual void enter() override
  {
    last = ticks();
    x = -10;
  }

  void showSingle(CApp* ret, const char* msg)
  {
    speed = 80;
    single = true;
    retApp = ret;
    strcpy(message, msg);
    maxx = getTextWidth(message);
  }

  void show(CApp* ret, const char* msg, int value)
  {
    speed = 45;
    single = false;
    retApp = ret;
    strcpy(message, msg);
    char* end = message + strlen(message);
    itoa(value, end, 10);
    maxx = getTextWidth(message);
  }

  virtual void loop() override
  {
    if (ticks() - last < speed)
      return;
    last = ticks();

    uint8_t buffer[9] = {0};
    renderText(buffer, -x, 0, message);
    if (x++ > maxx)
    {
      x = -10;
      if (single && retApp)
      {
        go(*retApp);
        retApp = nullptr;
      }
    }

    for (int y=0; y<8; y++)
      for (int x=0; x<9; x++)   
        pixel(x, y+1) = (buffer[x] & (1<<y)) ? 0xffffff : 0x000000;
  }

  virtual void onRelease(int x, int y) override
  {
    if (retApp)
    {
      go(*retApp);
      retApp = nullptr;
    }
  }
};
