//#include <string.h>

static const char* admap[] = {
  "                                                           ",
  "                            k                              ",  
  "                           k k                             ",  
  "                            k                              ",  
  "                            kk                             ",  
  "                            k                              ",  
  "                            kk                        ddd  ",  
  "                                                     ddddd ",  
  "             ###        ##############               ddddd ",
  "                                                     dd  d ",  
  "                                                     ddd d ",  
  "                                                     ddddd ",  
  "                                                    #######",  
  "                                                           ",  
  "                                                           ",  
  "             ##########%%%%%%%########                     ",
  "                                                           ",
  "                                                           ",
  "   *                                         #####         ",
  "  ...                                      ###   ##        ",
  "   .                                     ###      ##       ",
  "  . .                                  ###         ###     ",
  "#####~-~~~~#############################             ##    ",
  "#####~~~~-~############################               #####",
};

class CAppAdventure : public CApp
{
  int x{0};
  int y{0};
  int dx{0};
  int dy{0};
  int32_t last{0};

public:
  int triangle(int32_t t)
  {
    t &= 511;
    if (t >= 256)
      t = 511-t;
    return t;
  }
  uint32_t color(char c, uint32_t background, uint32_t clear)
  {
    switch (c)
    {
      case 0: return background;
      case ' ': return clear;
      case '#': return 0xb0b0b0;
      case '~': return 0x0000ff;
      case '-': return 0x000020;
      case '%': return 0xb04040;
      case 'k': return clear | (triangle(ticks()/4)<<16);
      case 'd': return 0x400000;
      case '.': return 0x808000;
      case '*': return 0xffff00;
    }
    return 0xff00ff;
  }

  virtual void loop() override
  {
    if (ticks() - last < 50)
      return;
    last = ticks();
    x += dx;
    y += dy;
    for (int _y=0; _y<9; _y++)
    {
      int h = min(max(0, 20-y-_y), 255);
      uint32_t clear = h | (h<<8);

      for (int _x=0; _x<9; _x++)
      {
        uint32_t background = (((_x+x/3+1024)/2+(_y+y/3+1024)/2) & 1) ? 0 : 0x202020;
        pixel(_x, _y) = color(getmap(x+_x, y+_y), background, clear);
      }
    }
  }
  int _strlen(const char* c)
  {
    const char* _c = c;
    while (*c++);
    return (uintptr_t)c-(uintptr_t)_c;
  }
  char getmap(int x, int y)
  {
    if (y < 0)
      return 0;
    if (y >= sizeof(admap)/sizeof(admap[0]))
      return 0;
    if (x < 0)
      return 0;

    if (x >= _strlen(admap[y]))
      return 0;
    return admap[y][x];
  }

  virtual void onPress(int x, int y, int v) override
  {
    switch (y*10+x)
    {
      case 77: dy = -1; break;
      case 86: dx = -1; break;
      case 87: dy = +1; break;
      case 88: dx = +1; break;
    }
  }
  virtual void onRelease(int x, int y) override
  {
    switch (y*10+x)
    {
      case 77: dy = 0; break;
      case 86: dx = 0; break;
      case 87: dy = 0; break;
      case 88: dx = 0; break;
    }
  }
};
