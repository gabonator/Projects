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
  "                                             #####         ",
  "                                           ###   ##        ",
  "                                         ###      ##       ",
  "                                       ###         ###     ",
  "#####~-~~~~#############################             ##    ",
  "#####~~~~-~############################               #####",
};

const static char player[] = 
  "\x03\x04"
  "\x01\x03"
  " * "
  "..."
  " . "
  ". .";

const static char player_crawl[] = 
  "\x04\x02"
  "\x02\x01"
  " ..*"
  ".. .";

class CAppAdventure : public CApp
{
  int x{0};
  int y{0};
  int tx{0};
  int ty{0};
  int dx{0};
  int dy{0};
  int32_t last{0};
  int playerx{3};
  int playery{15};
  int jump{0};
  bool crawl{false};
  int moveRight{true};

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
    //x += dx;
    //y += dy;
    if (dx != 0)
    {
      if (jump && admap[playery][playerx+dx] == ' ')
      {
        playerx += dx;
      }
      else
      if (admap[playery+1][playerx+dx] != ' ' &&
          admap[playery][playerx+dx] == ' ')
      {
        playerx += dx;
      }
      else 
      if (admap[playery][playerx+dx] != ' ' &&
          admap[playery-1][playerx+dx] == ' ')
      {
        playerx += dx;
        playery--;
      } 
      else 
      if (admap[playery+1][playerx+dx] == ' ' &&
          admap[playery][playerx+dx] == ' ' &&
          admap[playery+2][playerx+dx] != ' ')
      {
        playerx += dx;
        playery++;
      }
      else 
      if (admap[playery+1][playerx+dx] == ' ' &&
          admap[playery][playerx+dx] == ' ' &&
          admap[playery+2][playerx+dx] == ' ')
      {
        playerx += dx;
      }
    }

    if (dy < 0 && jump > 0)
    {
      jump--;
      playery--;
    }
    else if (admap[playery+1][playerx] == ' ')
      playery++;

    if (tx > x)
      x++;
    if (tx < x)
      x--;
    
    tx = playerx-(moveRight ? 2 : 6);
    ty = playery-6;
    y = ty;

    for (int _y=0; _y<9; _y++)
    {
      int h = min(max(0, 20-y-_y), 255);
      uint32_t clear = h | (h<<8);

      for (int _x=0; _x<9; _x++)
      {
        uint32_t background = (((_x+x/3+1024)/2+(_y+y/3+1024)/2) & 1) ? 0 : 0x202020;
        pixel(_x, _y) = color(getmap(x+_x, y+_y), background, clear);
//        if (x+_x == playerx && y+_y == playery)
//          pixel(_x, _y) = 0xff0000;
      }
    }
  }
  int _strlen(const char* c)
  {
    const char* _c = c;
    while (*c++);
    return (uintptr_t)c-(uintptr_t)_c;
  }
  char checkObj(int x, int y, const char* obj, int bx, int by)
  {
    x -= bx - obj[2];
    y -= by - obj[3];
    if (!moveRight)
      x = obj[0]-1-x;
    if (x < 0 || x >= obj[0] || y < 0 || y >= obj[1])
      return 0;
    return obj[y*obj[0]+x+4];
  }

  char getmap(int x, int y)
  {
    char c = checkObj(x, y, crawl ? player_crawl : player, playerx, playery);
    if (c != 0 && c != ' ')
      return c;

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
      case 77: dy = -1; jump = 8; break;
      case 86: dx = -1; moveRight = false; break;
      case 87: dy = +1; crawl = true; break;
      case 88: dx = +1; moveRight = true; break;
    }
  }
  virtual void onRelease(int x, int y) override
  {
    switch (y*10+x)
    {
      case 77: dy = 0; jump = 0; break;
      case 86: dx = 0; break;
      case 87: dy = 0; crawl = false; break;
      case 88: dx = 0; break;
    }
  }
};
