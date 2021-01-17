#include <stdint.h>
#include <cassert>

extern "C" void appInit();
extern "C" bool appLoop();
extern "C" void appFinish();

typedef uint16_t WORD;
constexpr WORD appBase = 0x1020;
//constexpr WORD _seg000 = 0x1000 - appBase;
constexpr WORD _seg001 = 0x1020 - appBase;
constexpr WORD _seg002 = 0x13EC - appBase;

#include "cpu.h"
#include "indirect.h"
#include "cdman.h"

void StackWrite(int nOffset, WORD nData) {}
WORD StackRead(int nOffset) { return 0; }
void _out(WORD port, WORD val) {}
void _out(WORD port, BYTE val) {}
void _interrupt(BYTE i) {}
void _in(BYTE& val, WORD port) {}
WORD memoryVideoGet16(WORD seg, WORD ofs) { return 0;}
void memoryVideoSet16(WORD seg, WORD ofs, WORD d) {}
WORD memoryBiosGet16(WORD seg, WORD ofs) {return 0;}
BYTE memoryVideoGet(WORD seg, WORD ofs) {return 0;}
void memoryVideoSet(WORD seg, WORD ofs, BYTE b) {}
BYTE& memory(WORD segment, WORD offset) { static BYTE b; return b; }
WORD& memory16(WORD segment, WORD offset) { static WORD w; return w; }
BYTE MemAuto::Get8(WORD seg, WORD ofs) { return 0; }
void MemAuto::Set8(WORD seg, WORD ofs, BYTE data) { }
BYTE MemVideo::Get8(WORD seg, WORD ofs) { return 0; }
void MemVideo::Set8(WORD seg, WORD ofs, BYTE data) {}


void appInit()
{
}
bool appLoop()
{
  start();
  return true;
}

void appFinish()
{
}
