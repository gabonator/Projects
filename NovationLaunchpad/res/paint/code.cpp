#include <stdint.h>
#include <stdbool.h>
#include <string.h>

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
int speed{1000};

const static uint32_t palette[] = {
  0x000000, 0xff0000, 0x00ff00, 0x0000ff,
  0xffff00, 0xff00ff, 0x00ffff, 0xffffff};

uint32_t& pixel(int x, int y)
{
  uint8_t f = (y+1)*10 + x+1;
  return LED_BUFFER[f];
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

extern "C" void old_loop();
extern "C" void new_loop()
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

    for (int y=0; y<8; y++)
      for (int x=0; x<8; x++)
        pixel(x, y) = image[x+scroll][y];

    for (int y=0; y<8; y++)
      pixel(8, y) = palette[y];
    pixel(2, -1) = 0x404040;
    pixel(3, -1) = 0x404040;
  }

  if (blinking)
  {
    if (scrollLast == 0)
      scrollLast = TICKSMS;
    int passed = TICKSMS - scrollLast;
    if (passed > speed)
    {
      scrollLast = TICKSMS;

      scroll += 8;
      if (scroll >= Width)
        scroll = 0;
      scrollTarget = scroll;

      for (int y=0; y<8; y++)
        for (int x=0; x<8; x++)
          pixel(x, y) = image[x+scroll][y];
    }
  }

  if (scroll != scrollTarget)
  {
    int passed = TICKSMS - scrollLast;
    if (passed > 50)
    {
      scrollLast = TICKSMS;
      if (scrollTarget > scroll)
        scroll++;
      if (scrollTarget < scroll)
        scroll--;

      for (int y=0; y<8; y++)
        for (int x=0; x<8; x++)
          pixel(x, y) = image[x+scroll][y];
    }
  }
}

extern "C" void old_onPress(int, int);
extern "C" void new_onPress(int a, int b)
{
  // top buttons: 1 2 3 4 5
  // right buttons: 19 29 39..89
  old_onPress(a, b);
  if (MODE != 5)
    return;  

  if (a == 3)
    scrollLeftPressed = true;
  if (a == 4)
    scrollRightPressed = true;

  if (blinking)
  {
    if (a == 3 && speed < 5000)
      speed += 200;
    if (a == 4 && speed > 200)
      speed -= 200;
  } else 
  {
    if (a == 3 && scrollTarget > 0)
      scrollTarget -= 8;
    if (a == 4 && scrollTarget < Width-8)
      scrollTarget += 8;
  }

  if (scrollLeftPressed && scrollRightPressed)
  {
    if (blinking)
    {
      for (int y=0; y<8; y++)
        pixel(8, y) = palette[y];
      pixel(2, -1) = 0x404040;
      pixel(3, -1) = 0x404040;
      blinking = false;
    } else
    {
      for (int y=0; y<8; y++)
        pixel(8, y) = 0x000000;
      pixel(2, -1) = 0x40b040;
      pixel(3, -1) = 0x40b040;
      blinking = true;
    }
  }

  if ((a%10) == 9 && a >= 19 && a <= 89)
    color = palette[(a-19)/10];
  int x = a%10;
  int y = a/10;
  if (x>=1 && x<=8 && y >= 1 && y <= 8)
  {
    x--;
    y--;
    if (pixel(x, y) == color)
      image[x+scroll][y] = 0;
    else
      image[x+scroll][y] = color;
    pixel(x, y) = image[x+scroll][y];
  }
}

extern "C" void old_onRelease(int);
extern "C" void new_onRelease(int a)
{
  if (a == 3)
    scrollLeftPressed = false;
  if (a == 4)
    scrollRightPressed = false;
  old_onRelease(a);
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
