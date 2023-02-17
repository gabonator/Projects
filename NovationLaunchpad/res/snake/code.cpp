#include <stdint.h>
#include <stdbool.h>
#include <string.h>

class CPRNG
{
private:
  unsigned int nSeed;
  unsigned int nX;

public:
  CPRNG() : nSeed(5323), nX(0)
  {
  }
  void addEntropy(int s)
  {
    nSeed += s; 
  }
  unsigned int get()
  {
    nSeed = (8253729 * nSeed + 2396403);
    nSeed += nX++;
    return nSeed & 32767;
  }
};

CPRNG random;

template <typename T> T min(T a, T b)
{
  return a < b ? a : b;
}
template <typename T> T max(T a, T b)
{
  return a > b ? a : b;
}

extern "C" uint32_t LED_BUFFER[];
extern "C" uint8_t MODE;
extern "C" int32_t TICKSMS;
enum {Width = 32};
uint32_t image[Width][8] = {0};
uint32_t color = 0xab00cd;
uint8_t prevMode;
int scroll;
int scrollTarget;
bool blinking{false};
bool scrollLeftPressed{false};
bool scrollRightPressed{false};
int32_t scrollLast{0};
int posx = 8, posy = 8;
int dirx = 0, diry = 0;
int tailx[32];
int taily[32];
int tailn = 0;
int taillen = 4;
int taillx{0}, tailly{0};
int applex{0}, appley{0};
int applel{0};
int32_t applee{0};
int32_t apples{0};
int speed{400};
int32_t taillt{0};
/*const static*/ char game[] = 
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

uint32_t& pixel(int x, int y)
{
  uint8_t f = (y+1)*10 + x+1;
  return LED_BUFFER[f];
}

extern "C" void old_loop();
extern "C" void new_loop()
{
  old_loop();        

  if (MODE != 5)
  {
    prevMode = MODE;
    last = TICKSMS;
    return;
  }
  if (applee != 0)
  {
    int32_t sinceEat = TICKSMS - applee;
    applel = (1000-sinceEat) * 32 / 1000;
    if (applel <= 0)
    {
      applel = 0;
      applex = 0;
      appley = 0;
      applee = 0;
    }
  }
  if (apples != 0)
  {
    int32_t sinceShow = TICKSMS - apples;
    applel = sinceShow * 32 / 1000;
    if (applel >= 32)
    {
      applel = 32;
      apples = 0;
    }
  }
  if (applex == 0 && appley == 0)
  {
    applex = random.get() % 16;
    appley = random.get() % 16;
    if (game[appley*16+applex] == ' ')
    {
      game[appley*16+applex] = '*';
      applel = 0;
      apples = TICKSMS;
    } else {
      applex = 0;
      appley = 0;
      applel = 0;
    }
  }
  passed += TICKSMS-last;
  last = TICKSMS;
  while (passed > speed)
  {
    passed -= speed;
    posx += dirx;
    posy += diry;
    if ((dirx != 0 || diry != 0) && game[posy*16+posx] != ' ')
    {
      if (game[posy*16+posx] == '*')
      {
        if (speed > 100)
          speed -= 5;
        applee = TICKSMS;
        if (taillen < 63)
          taillen++;
      } else {
        speed = 400;
        posx = 8;
        posy = 8;
        dirx = 0;
        diry = 0;
        tailn = 0;
        taillt = 0;
        taillen = 4;
        for (int y=0; y<16; y++)
          for (int x=0; x<16; x++)
            if (game[y*16+x] == 'h' || game[y*16+x] == 'o')
              game[y*16+x] = ' ';
        break;
      }
    }
    game[posy*16+posx] = 'h';
    if (tailx[0] != posx || taily[0] != posy)
    {
      if (tailn == taillen-1)
      {
        tailn--;
        game[taily[tailn]*16+tailx[tailn]] = ' ';
        taillx = tailx[tailn];
        tailly = taily[tailn];
        taillt = TICKSMS;
      }
      for (int i=tailn-1; i>=0; i--)
      {
        game[taily[i]*16+tailx[i]] = 'o';
        tailx[i+1] = tailx[i];
        taily[i+1] = taily[i];
      }
      tailn++;
      tailx[0] = posx;
      taily[0] = posy;
    }
  }
  for (int y=0; y<9; y++)
    for (int x=0; x<9; x++)
    {
      int mapx = posx+x-4;
      int mapy = posy+y-4;
      mapx = min(max(0, mapx), 15);
      mapy = min(max(0, mapy), 15);
      uint32_t color = 0;
      if (applex != 0 || appley != 0)
      {
        int dist = (mapx-applex)*(mapx-applex)+(mapy-appley)*(mapy-appley);
        dist = (60-(dist))*applel/60;
        if (dist < 0)
          dist = 0;
        color = dist;
      }
      switch (game[mapy*16+mapx])
      {
        case ' ': break;
        case '#': color = 0x404040; break;
        case '*': color = 0x0000b0; break;
        case 'o': color = (color & 0xff00ff) | 0x008000; break;
        case 'h':
        {
          int tim = (TICKSMS>>2)&511;
          tim = tim <= 255 ? tim : 511-tim;
          color = (color & 0xff00ff) | (tim << 8);
        }
        break;
      }
      if (mapx == taillx && mapy == tailly && taillt != 0)
      {
        int passed = TICKSMS - taillt;
        if (passed > 200)
          taillt = 0;
        else
          color = (color & 0xff00ff) | (((200-passed)*0x80/200) << 8);
      }   
      if ((y == 7 && x == 7) || (y == 8 && x >= 6))
        color |= 0x8f8f00;
      pixel(x, y-1) = color;
    }
}

extern "C" void old_onPress(int, int);
extern "C" void new_onPress(int a, int b)
{
  auto safe = [](int dx, int dy) -> bool {
    char b = game[(posy+dy)*16+posx+dx];
    return b == ' ' || b == '*';
  };

  random.addEntropy(TICKSMS);
  switch (a)
  {
    case 78: if (safe(0, -1)) {dirx = 0; diry = -1;} break;
    case 87: if (safe(-1, 0)) {dirx = -1; diry = 0;} break;
    case 88: if (safe(0, 1)) {dirx = 0; diry = +1;} break;
    case 89: if (safe(1, 0)) {dirx = +1; diry = 0;} break;
  }
  old_onPress(a, b);
}

extern "C" void old_onRelease(int);
extern "C" void new_onRelease(int a)
{
  old_onRelease(a);
}

extern "C" int new_usbStatus()
{
  return 1;
}

extern "C" void old_updateScreen();
extern "C" void new_updateScreen()
{
  if (MODE != 5)
    old_updateScreen();
}

extern unsigned long _sidata;
extern unsigned long _sdata;
extern unsigned long _edata;
extern unsigned long _sbss;
extern unsigned long _ebss;

extern "C" void old_startup();
extern "C" void new_startup()
{
  unsigned long *src, *dst;
  src = &_sidata;
  dst = &_sdata;
  if (src != dst)
  	while(dst < &_edata)
  		*(dst++) = *(src++);
  dst = &_sbss;
  while(dst < &_ebss)
  	*(dst++) = 0;
  old_startup();
}
