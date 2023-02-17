#include <stdint.h>
#include <stdbool.h>

extern uint32_t LED_BUFFER[];
extern uint8_t MODE;
extern uint32_t TICK;
uint32_t image[8][8];
uint32_t color;
uint8_t prevMode;

const static uint32_t palette[] = {
  0x000000, 0xff0000, 0x00ff00, 0x0000ff,
  0xffff00, 0xff00ff, 0x00ffff, 0xffffff};

bool colorSet;

uint32_t getPixel(int x, int y)
{
  uint8_t f = (y+1)*10 + x+1;
  return LED_BUFFER[f];
}

uint8_t setPixel(int x, int y, uint32_t c)
{
  uint8_t f = (y+1)*10 + x+1;
  LED_BUFFER[f] = c;
}

uint8_t getButton(int x, int y)
{
  uint8_t* buttons = (uint8_t*)0x20001dd0;

  static const uint8_t ofs[] = {
   64, 65, 66, 67,   96, 97, 98, 99,
   60, 61, 62, 63,   92, 93, 94, 95,
   56, 57, 58, 59,   88, 89, 90, 91,
   52, 53, 54, 55,   84, 85, 86, 87,

   48, 49, 50, 51,   80, 81, 82, 83,
   44, 45, 46, 47,   76, 77, 78, 79,
   40, 41, 42, 43,   72, 73, 74, 75,
   36, 37, 38, 39,   68, 69, 70, 71,
  };
  return !!buttons[ofs[y*8+x]];
}

void old_updateScreen();
void new_updateScreen()
{
  if (MODE != 5)
    old_updateScreen();
}

void old_loop();
int mytick = 0;
void new_loop()
{
  old_loop();        

  if (MODE != 5)
  {
    prevMode = MODE;
    return;
  }

  if (prevMode != 5)
  {
    prevMode = MODE;
    if (colorSet != true)
    {
      colorSet = true;
      color = 0xff0000;
    }

    for (int y=0; y<8; y++)
      for (int x=0; x<8; x++)
        setPixel(x, y, image[x][y]);

    for (int y=0; y<8; y++)
      setPixel(8, y, palette[y]);
  }
}

void old_onKeyDown(int, int);
void new_onKeyDown(int a, int b)
{
  // top buttons: 1 2 3 4 5
  // right buttons: 19 29 39..89
  old_onKeyDown(a, b);
  if (MODE != 5)
    return;
  if ((a%10) == 9 && a >= 19 && a <= 89)
    color = palette[(a-19)/10];
  int x = a%10;
  int y = a/10;
  if (x>=1 && x<=8 && y >= 1 && y <= 8)
  {
    x--;
    y--;
    if ((getPixel(x, y)<<8) == (color<<8))
      image[x][y] = 0;
    else
      image[x][y] = color;
    setPixel(x, y, image[x][y]);
  }
}

void old_timer();
void new_timer()
{
  old_timer();
}
