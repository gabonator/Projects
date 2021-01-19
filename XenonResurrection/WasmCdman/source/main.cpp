#include "app/cdman.h"
#include "machine.h"
#include "interface.h"

void appInit()
{
    _sp = 64;
    _ds = 0x6666;
    _es = 0x6666;
    _di = 0x6666;
    _bp = 0x6666;
}

bool appLoop()
{
  bool b = start();
  updateVideoBuffer();
  return b;
}

void appFinish()
{
}
