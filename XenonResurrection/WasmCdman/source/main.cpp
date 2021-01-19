#include "app/cdman.h"
#include "machine.h"

extern "C" void appInit();
extern "C" bool appLoop();
extern "C" void appFinish();

extern "C" uint8_t* appVideoBuffer();
extern "C" uint8_t* appMemory();

void appInit()
{
    js_debug(66);
    js_debug(_sp);
    _sp = 64;
//    _ds = _es = _di = _bp = 0x6666;
    js_debug(77);
    js_debug(_sp);
}

bool appLoop()
{
    js_debug(88);
    js_debug(_sp);
  return start();
}

void appFinish()
{
}
