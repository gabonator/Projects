#include <stdint.h>
#include <assert.h>
#include <string.h>

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
uint16_t tx;
uint8_t& tl = *reinterpret_cast<uint8_t*>(&tx);
uint8_t& th = *(reinterpret_cast<uint8_t*>(&tx) + 1);
uint16_t cs, ds, es, ss, sp, si, di, bp;

struct flags_t {
  bool carry, zero, sign, interrupts, direction;
};

int headerSize, loadAddress, endAddress;
flags_t flags;

void sync();
void load(const char*, const char*, int);
//uint16_t& memory16(int s, int o);
void memoryASet(int s, int o, int v);
void memoryASet16(int s, int o, int v);
uint8_t memoryAGet(int s, int o);
uint16_t memoryAGet16(int s, int o);
uint32_t memoryAGet32(int s, int o);

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
bool stop(const char* msg = nullptr)
{
    if (msg && strstr(msg, "stack_below_retf"))
        return false;
    if (msg == "stack_bad")
        return false;
    assert(0);
    return false;
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
    int16_t sa = (int16_t)a;
    sa >>= b;
    return sa;
}

void mul16(uint16_t r)
{
    int v = r * ax;
    ax = v & 0xffff;
    dx = v >> 16;
}

uint8_t rcr8(uint8_t r, int i)
{
    assert(i == 1);
    int newCarry = !!(r & 0x1);
    r >>= 1;
    r |= flags.carry ? 0x80 : 0;
    flags.carry = newCarry;
    return r;
}

uint8_t sar8(uint8_t a, uint8_t b)
{
    int8_t sa = (char)a;
    sa >>= b;
    return sa;
}

uint16_t rol16(uint16_t r, int l)
{
    return (r<<l) | (r>>(16-l));
}

uint16_t ror16(uint16_t r, int l)
{
    return (r>>l) | (r<<(16-l));
}

uint8_t ror8(uint8_t r, int l)
{
    return (r>>l) | (r<<(8-l));
}

uint8_t rol8(uint8_t r, int l)
{
    return (r<<l) | (r>>(8-l));
}

void div8(uint8_t r)
{
    uint16_t result = ax / r;
    uint16_t remain = ax % r;
    al = result;
    ah = remain;
}

void div16(uint16_t r)
{
    uint16_t result = ax / r;
    uint16_t remain = ax % r;
    ax = result;
    dx = remain;
}


void idiv8(uint8_t r)
{
    int32_t dw = (dx << 16) | ax;
    uint16_t result = dw / r;
    uint16_t remainder = dw % r;
    ax = result;
    dx = remainder;
}

void imul16(uint16_t r)
{
    int v = (int16_t)ax * (int16_t)r;
    ax = v & 0xffff;
    dx = v >> 16;
}

void idiv16(uint16_t r)
{
    int32_t n = (dx << 16) | ax;
    ax = n / (int16_t)r;
    dx = n % (int16_t)r;
}

uint16_t rcl16(uint16_t r, int i)
{
    while (i > 0)
    {
        int newCarry = !!(r & 0x8000);
        r <<= 1;
        r |= flags.carry ? 0x0001 : 0x0000;
        flags.carry = newCarry;
        i--;
    }
    return r;
}

uint16_t rcr16(uint16_t r, int i)
{
    while (i > 0)
    {
        int newCarry = !!(r & 0x0001);
        r >>= 1;
        r |= flags.carry ? 0x8000 : 0x0000;
        flags.carry = newCarry;
        i--;
    }
    return r;
}

uint8_t rcl8(uint8_t r, int i)
{
    assert(i == 1);
    int newCarry = !!(r & 0x80);
    r <<= 1;
    r |= flags.carry;
    flags.carry = newCarry;
    return r;
}


void mul8(uint8_t r)
{
    int v = r * al;
    ax = v & 0xffff;
}



int flagAsReg()
{
    return flags.carry | (flags.zero << 1);
}
void flagsFromReg(int r)
{
    flags.carry = r & 1;
    flags.zero = (r>>1) & 1;
}

struct DS_SI {
  static uint8_t Get8() { return memoryAGet(ds, si); } 
  static uint16_t Get16() { return memoryAGet16(ds, si); } 
  static void Advance(int n) { si += flags.direction ? -n : n; }
};

struct ES_DI { 
  static uint8_t Get8() { return memoryAGet(es, di); }
  static void Set8(uint8_t v) { return memoryASet(es, di, v); }
  static void Set16(uint16_t v) { return memoryASet16(es, di, v); }
  static void Advance(int n) { di += flags.direction ? -n : n; }
};

struct ES_SI {
  static uint8_t Get8() { return memoryAGet(es, si); }
  static uint16_t Get16() { return memoryAGet16(es, si); }
  static void Set8(uint8_t v) { return memoryASet(es, si, v); }
  static void Set16(uint16_t v) { return memoryASet16(es, si, v); }
  static void Advance(int n) { si += flags.direction ? -n : n; }
};

struct SS_SI {
    static uint8_t Get8() { return memoryAGet(ss, si); }
  static void Set8(uint8_t v) { return memoryASet(ss, si, v); }
  static void Set16(uint16_t v) { return memoryASet16(ss, si, v); }
  static void Advance(int n) { si += flags.direction ? -n : n; }
};

struct CS_SI {
  static uint8_t Get8() { return memoryAGet(cs, si); }
  static uint16_t Get16() { return memoryAGet16(cs, si); }
  static void Advance(int n) { si += flags.direction ? -n : n; }
};


template <typename src> int lodsb()
{
  int temp = src::Get8();
  src::Advance(1);
  return temp;
}

template <typename src> int lodsw()
{
  int temp = src::Get16();
  src::Advance(2);
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
  dst::Set8(src::Get8());
  dst::Advance(1);
  src::Advance(1);
}

template <class dst, class src> void cmpsb()
{
    // TODO: should set carry?
    flags.zero = src::Get8() == dst::Get8();
    dst::Advance(1);
    src::Advance(1);
}

template <typename src> void scasb_inv(uint8_t b)
{
    // TODO: should set carry?
    flags.zero = src::Get8() == b;
    src::Advance(1);
}

//template <class SRC> void repne_scasb)nv(uint8_t value)
//{
//    assert(flags.direction == 0);
//    flags.zero = 0;
//    while (cx != 0 && flags.zero == 0 )
//    {
//        flags.zero = value - SRC::Get8(es, di) == 0;
//        DIR::Move(di);
//        cx--;
//    }
//}
