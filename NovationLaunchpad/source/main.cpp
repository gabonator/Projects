#include <stdint.h>
#include "utils.h"
#include "app.h"
#include "lightpen.h"
#include "snake.h"
#include "paint.h"
#include "drops.h"
CAppLightpen appLightpen;
CAppSnake appSnake;
CAppPaint appPaint;
CAppDrops appDrops;
#include "menu.h"

CAppMenu appMenu;
CApp* appCurrent = &appMenu;
CApp* appLast = nullptr;

extern "C" {
  extern uint32_t LED_BUFFER[];
  extern uint8_t MODE;
  extern int32_t TICKSMS;

  void old_loop();
  void new_loop();
  void old_onPress(int, int);
  void new_onPress(int, int);
  void old_onRelease(int);
  void new_onRelease(int);
  void old_updateScreen();
  void new_updateScreen();
  int old_usbStatus();
  int new_usbStatus();
  void old_startup();
  void new_startup();

  extern uint32_t _sidata;
  extern uint32_t _sdata;
  extern uint32_t _edata;
  extern uint32_t _sbss;
  extern uint32_t _ebss;
  extern uint32_t _sinit;
  extern uint32_t _einit;
}

const int32_t& CApp::ticks()
{
  return TICKSMS;
}

uint32_t& CApp::pixel(int x, int y)
{
  uint8_t f = y*10 + x + 1;
  return LED_BUFFER[f];
}

const uint8_t& CApp::mode()
{
  return MODE;
}

void CApp::enter()
{
}

void CApp::leave()
{
}

void CApp::loop() 
{
}

void CApp::onPress(int x, int y, int v) 
{ 
}

void CApp::onRelease(int x, int y) 
{ 
}

void CApp::go(CApp& app)
{
  appCurrent->leave();
  appCurrent = &app;
  appCurrent->enter();
  appLast = appCurrent;
}

void new_loop()
{
  old_loop();
  if (MODE == 5)
  {
    if (appLast != appCurrent)
    {
      if (appLast)
        appLast->leave();
      if (appCurrent)
        appCurrent->enter();
    }
    if (appCurrent)
      appCurrent->loop();
    appLast = appCurrent;
  }
}

void new_onPress(int a, int b)
{
  if (MODE == 5)
  {
    if (a == 5 || a == 6 || a == 7 || a == 8)
    {
      appCurrent->leave();
      appCurrent = &appMenu;
    }
    else
      appCurrent->onPress(a%10-1, a/10, b);
  }
  old_onPress(a, b);
}

void new_onRelease(int a)
{
  old_onRelease(a);
  if (MODE == 5)
    appCurrent->onRelease(a%10-1, a/10);
}

int new_usbStatus()
{
  // always connected
  return 1; 
}

void new_updateScreen()
{
  if (MODE != 5)
    old_updateScreen();
}

void new_startup()
{
  uint32_t *src, *dst;
  src = &_sidata;
  dst = &_sdata;
  if (src != dst)
  	while(dst < &_edata)
  		*(dst++) = *(src++);
  dst = &_sbss;
  while(dst < &_ebss)
  	*(dst++) = 0;

  src = &_sinit;
  while (src < &_einit)
  {
    uintptr_t ifunc = *src;
    ((void(*)())ifunc)();
    src++;
  }
  old_startup();
}

#ifdef __EMSCRIPTEN__
extern "C" {
  uint32_t LED_BUFFER[10*10];
  uint8_t MODE;
  int32_t TICKSMS;

  uint32_t _sidata;
  uint32_t _sdata;
  uint32_t _edata;
  uint32_t _sbss;
  uint32_t _ebss;
  uint32_t _sinit;
  uint32_t _einit;

  void old_loop() {}
  void old_onPress(int, int) {}
  void old_onRelease(int) {}
  void old_updateScreen() {}
  int old_usbStatus() { return 0; }
  void old_startup() {}
}
#endif
