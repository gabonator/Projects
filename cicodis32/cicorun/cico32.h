#include <stdint.h>
#include <assert.h>

uint16_t ax;
uint8_t& al = *reinterpret_cast<uint8_t*>(&ax);
uint8_t& ah = *(reinterpret_cast<uint8_t*>(&ax) + 1);
uint16_t bx;
uint8_t& bl = *reinterpret_cast<uint8_t*>(&bx);
uint8_t& bh = *(reinterpret_cast<uint8_t*>(&bx) + 1);
uint16_t cx;
uint8_t& cl = *reinterpret_cast<uint8_t*>(&cx);
uint8_t& ch = *(reinterpret_cast<uint8_t*>(&cx) + 1);
uint16_t dx;
uint8_t& dl = *reinterpret_cast<uint8_t*>(&dx);
uint8_t& dh = *(reinterpret_cast<uint8_t*>(&dx) + 1);
uint16_t cs, ds, es, ss, sp, si, di, bp;

struct flags_t {
  bool carry, zero, interrupts, direction;
};

int headerSize, loadAddress, endAddress;
flags_t flags;

void load(const char*, const char*, int);
//uint16_t& memory16(int s, int o);
void memoryASet(int s, int o, int v);
void memoryASet16(int s, int o, int v);
uint8_t memoryAGet(int s, int o);
uint16_t memoryAGet16(int s, int o);
uint16_t pop()
{
  assert(sp <= 0xffff);
  uint16_t aux = memoryAGet16(ss, sp);
  sp += 2;
  return aux;
}
void push(uint16_t w)
{
  sp -= 2;
  memoryASet16(ss, sp, w);
  assert(sp > 0);
}
void interrupt(int);
void cbw()
{
  ah = (al & 0x80) ? 0xff : 0;
}
void cwde()
{
  assert(0);
}
void out16(int, int);
void out8(int, int);
int in8(int);
void stop(const char* msg = nullptr)
{
  assert(0);
}
void div8(int r)
{
    uint16_t result = ax / r;
    uint16_t remain = ax % r;
    al = result;
    ah = remain;
}
void callIndirect(int, int);

int sar16(int a, int b)
{
    int16_t sa = (short)a;
    sa >>= b;
    return sa;
}

struct DS_SI { 
  static uint8_t Get8() { return memoryAGet(ds, si); } 
  static uint16_t Get16() { return memoryAGet16(ds, si); } 
  static void Advance(int n) { si += flags.direction ? n : -n; }
};

struct ES_DI { 
  static void Set8(uint8_t v) { return memoryASet(es, di, v); }
  static void Set16(uint16_t v) { return memoryASet16(es, di, v); }
  static void Advance(int n) { di += flags.direction ? n : -n; }
};

template <typename src> int lodsb()
{
  int temp = src::Get8();
  src::Advance(1);
  return temp;
}

template <typename dst> void stosw(int v)
{
  dst::Set16(v);
  dst::Advance(2);
}

template <typename dst> void stosb(int v)
{
  dst::Set8(v);
  dst::Advance(1);
}

template <typename dst, typename src> void movsw()
{
  dst::Set16(src::Get16());
  dst::Advance(2);
  src::Advance(2);
}

template <typename dst, typename src> void movsb()
{
  dst::Set16(src::Get16());
  dst::Advance(1);
  src::Advance(1);
}

