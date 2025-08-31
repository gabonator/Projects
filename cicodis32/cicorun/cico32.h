#include <stdint.h>
#include <assert.h>

uint32_t eax;
uint16_t& ax = *reinterpret_cast<uint16_t*>(&eax);
uint8_t& al = *reinterpret_cast<uint8_t*>(&ax);
uint8_t& ah = *(reinterpret_cast<uint8_t*>(&ax) + 1);
uint32_t ebx;
uint16_t& bx = *reinterpret_cast<uint16_t*>(&ebx);
uint8_t& bl = *reinterpret_cast<uint8_t*>(&bx);
uint8_t& bh = *(reinterpret_cast<uint8_t*>(&bx) + 1);
uint32_t ecx;
uint16_t& cx = *reinterpret_cast<uint16_t*>(&ecx);
uint8_t& cl = *reinterpret_cast<uint8_t*>(&cx);
uint8_t& ch = *(reinterpret_cast<uint8_t*>(&cx) + 1);
uint32_t edx;
uint16_t& dx = *reinterpret_cast<uint16_t*>(&edx);
uint8_t& dl = *reinterpret_cast<uint8_t*>(&dx);
uint8_t& dh = *(reinterpret_cast<uint8_t*>(&dx) + 1);
uint16_t tx;
uint8_t& tl = *reinterpret_cast<uint8_t*>(&tx);
uint8_t& th = *(reinterpret_cast<uint8_t*>(&tx) + 1);
//uint16_t cs, ds, es, ss, sp, si, di, bp;
uint32_t esi, edi, esp, ebp, ds, ss, es, gs, cs, fs, bp;
uint16_t& di = *reinterpret_cast<uint16_t*>(&edi);
uint16_t& si = *reinterpret_cast<uint16_t*>(&esi);

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
void memoryASet32(int s, int o, uint32_t v);
uint8_t memoryAGet(int s, int o);
uint16_t memoryAGet16(int s, int o);
uint32_t memoryAGet32(int s, int o);

void memoryASet32(int s, int o, uint32_t v)
{
    memoryASet16(s, o, (uint16_t)v);
    memoryASet16(s, o+2, (uint16_t)(v>>16));
}

uint16_t pop()
{
  assert(esp <= 0xffff);
  uint16_t aux = memoryAGet16(ss, esp);
  esp += 2;
  return aux;
}
void push(uint16_t w)
{
  esp -= 2;
  memoryASet16(ss, esp, w);
  assert(esp > 0);
}
uint32_t pop32()
{
  uint32_t aux = memoryAGet32(0, esp);
  esp += 4;
  return aux;
}

void push32(uint32_t w)
{
  esp -= 4;
  memoryASet32(0, esp, w);
  assert(esp > 0);
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

//struct DS_SI {
//  static uint8_t Get8() { return memoryAGet(ds, si); } 
//  static uint16_t Get16() { return memoryAGet16(ds, si); } 
//  static void Advance(int n) { si += flags.direction ? -n : n; }
//};
//
//struct ES_DI { 
//  static uint8_t Get8() { return memoryAGet(es, di); }
//  static void Set8(uint8_t v) { return memoryASet(es, di, v); }
//  static void Set16(uint16_t v) { return memoryASet16(es, di, v); }
//  static void Advance(int n) { di += flags.direction ? -n : n; }
//};
//
//struct ES_SI {
//  static uint8_t Get8() { return memoryAGet(es, si); }
//  static void Set8(uint8_t v) { return memoryASet(es, si, v); }
//  static void Set16(uint16_t v) { return memoryASet16(es, si, v); }
//  static void Advance(int n) { si += flags.direction ? -n : n; }
//};
//
//struct SS_SI {
//    static uint8_t Get8() { return memoryAGet(ss, si); }
//  static void Set8(uint8_t v) { return memoryASet(ss, si, v); }
//  static void Set16(uint16_t v) { return memoryASet16(ss, si, v); }
//  static void Advance(int n) { si += flags.direction ? -n : n; }
//};
//
struct DS_ESI {
  static uint8_t Get8() { return memoryAGet(ds, esi); }
  static uint16_t Get16() { return memoryAGet16(ds, esi); }
  static void Advance(int n) { esi += flags.direction ? -n : n; }
};
struct ES_EDI {
  static uint8_t Get8() { return memoryAGet(es, edi); }
  static uint16_t Get16() { return memoryAGet16(es, edi); }
  static void Set8(uint8_t v) { return memoryASet(es, edi, v); }
  static void Advance(int n) { esi += flags.direction ? -n : n; }
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

#include <vector>

namespace fpuinsns {
std::vector<double> fpu;
bool fpuc0, fpuc2, fpuc3;

void fild32(uint32_t v)
{
    assert(fpu.size() < 8);
    fpu.insert(fpu.begin(), v);
}
void fmul64(uint64_t v)
{
    double m;
    memcpy(&m, &v, sizeof(m));
    fpu[0] *= m;
}
void fld1()
{
    fpu.insert(fpu.begin(), 1.0);
}
void fcos()
{
    fpu[0] = cos(fpu[0]);
}
void fld64(uint64_t v)
{
    double f;
    memcpy(&f, &v, sizeof(f));
    assert(fpu.size() < 8);
    fpu.insert(fpu.begin(), f);
}
void fsubr64(uint64_t v)
{
    double m;
    memcpy(&m, &v, sizeof(m));
    fpu[0] = m - fpu[0];
}
uint64_t fstp64()
{
    uint64_t v;
    memcpy(&v, &fpu[0], sizeof(uint64_t));
    fpu.erase(fpu.begin());
    return v;
}
uint64_t fistp64()
{
    int aux = (int)fpu[0];
    fpu.erase(fpu.begin());
    return aux;
}
uint32_t fistp32()
{
    int aux = (int)fpu[0];
    fpu.erase(fpu.begin());
    return aux;
}
uint64_t st(int n)
{
    assert(n < fpu.size());
    uint64_t v;
    memcpy(&v, &fpu[n], sizeof(uint64_t));
    return v;
}
void fmul80(uint64_t v)
{
    fmul64(v);
}
void fdiv64(uint64_t v);
void fdiv80(uint64_t v)
{
    fdiv64(v);
}
void fsubp80()
{
    assert(fpu.size() >= 2);
    fpu[1] -= fpu[0]; // gabo!
    fpu.erase(fpu.begin());
}
void fadd64(uint64_t v);
void fadd80(uint64_t v)
{
    fadd64(v);
}
void faddp64(uint64_t v);
void faddp80(uint64_t v)
{
    faddp64(v);
}
void fdiv64(uint64_t v)
{
    double m;
    memcpy(&m, &v, sizeof(m));
    fpu[0] /= m;
}
void fadd64(uint64_t v)
{
    double m;
    memcpy(&m, &v, sizeof(m));
    fpu[0] += m;
}
void faddp64(uint64_t v)
{
    double m;
    memcpy(&m, &v, sizeof(m));
    fpu[0] += m;
    fpu.erase(fpu.begin());
}
void fcomp64(uint64_t v)
{
    double m;
    memcpy(&m, &v, sizeof(m));
    fpuc3 = fpuc2 = fpuc0 = 0;
    if (fpu[0] > m)
    {
    } else if (fpu[0] < m)
    {
        fpuc0 = 1;
    } else if (fpu[0] == m)
    {
        fpuc3 = 0;
    }
    fpu.erase(fpu.begin());
}
uint16_t fnstsw()
{
    return (fpuc0 + fpuc2 * 4 + fpuc3*8) << 8;
}
void frndtint()
{
    fpu[0] = (int)fpu[0];
}


// remove!!!
uint64_t memoryAGet64(int seg, int ofs)
{
    switch (ofs)
    {
        case 0x17c004: return 0x3f916872b020c49c; // 0.017
        case 0x17c00c: return 0x403f000000000000; // 31
        case 0x17c014: return 0x4040000000000000; // 32
        case 0x17c01c: return 0x4008000000000000; // 3
        case 0x17c024: return 0x4014000000000000; // 5
        case 0x17c02c: return 0x4069000000000000; // 200
        case 0x17c034: return 0x4074000000000000; // 320
        case 0x17c03c: return 0x4000000000000000; // 2
        case 0x17c044: return 0x4010000000000000; // 4
        case 0x17c04c: return 0x3f70000000000000; // 0.00390625
        case 0x17c054: return 0x406fe00000000000; // 255
    }
    uint32_t low = memoryAGet32(seg, ofs);
    uint32_t high = memoryAGet32(seg, ofs+4);
    //assert(ofs > 0 && ofs+8 < sizeof(memory));
    return low | ((uint64_t)high<<32);
}

void memoryASet64(int seg, int ofs, uint64_t v)
{
    memoryASet32(seg, ofs, (uint32_t)v);
    memoryASet32(seg, ofs+4, (uint32_t)(v>>32));
}
}

void sahf()
{
    flags.carry = ax & 0x100;
}

void callIndirect(int s, int o)
{
    stop();
}
using namespace fpuinsns;
