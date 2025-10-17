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

uint32_t esi, edi, esp, ebp;
uint16_t& bp = *reinterpret_cast<uint16_t*>(&ebp);

uint16_t ds, ss, es, gs, cs, fs;
uint16_t& di = *reinterpret_cast<uint16_t*>(&edi);
uint16_t& si = *reinterpret_cast<uint16_t*>(&esi);
uint32_t etx;
uint32_t cr0;

struct flags_t {
  bool carry, zero, sign, interrupts, direction;
};

flags_t flags;

void loadOverlay(const char*, int);
/*
void memoryASet(int s, int o, int v);
void memoryASet16(int s, int o, int v);
void memoryASet32(int s, int o, uint32_t v);
void memoryASet64(int s, int o, uint64_t v);
uint8_t memoryAGet(int s, int o);
uint16_t memoryAGet16(int s, int o);
uint32_t memoryAGet32(int s, int o);
uint64_t memoryAGet64(int s, int o);
*/
/*
void memoryASet(int s, int o, int v)
{
  *((uint8_t*)o) = v;
}
void memoryASet16(int s, int o, int v)
{
  *((uint16_t*)o) = v;
}
void memoryASet32(int s, int o, uint32_t v)
{
  *((uint32_t*)o) = v;
}
void memoryASet64(int s, int o, uint64_t v)
{
  *((uint64_t*)o) = v;
}
uint8_t memoryAGet(int s, int o)
{
  return *((uint8_t*)o);
}
uint16_t memoryAGet16(int s, int o)
{
  return *((uint16_t*)o);
}
uint32_t memoryAGet32(int s, int o)
{
  return *((uint32_t*)o);
}
uint64_t memoryAGet64(int s, int o)
{
  return *((uint64_t*)o);
}
*/

#define memoryASet(s, o, v) *((uint8_t*)(o)) = v
#define memoryASet16(s, o, v) *((uint16_t*)(o)) = v
#define memoryASet32(s, o, v) *((uint32_t*)(o)) = v
#define memoryASet64(s, o, v) *((uint64_t*)(o)) = v
#define memoryAGet(s, o) *((uint8_t*)(o))
#define memoryAGet16(s, o) *((uint16_t*)(o))
#define memoryAGet32(s, o) *((uint32_t*)(o))

void memoryVideoSet(int s, int o, int v);
void memoryVideoSet32(int s, int o, uint32_t v);

uint8_t memoryPspGet(int s, int o);
uint16_t memoryPspGet16(int s, int o);
uint32_t memoryPspGet32(int s, int o);

uint8_t memorySkipGet(int s, int o) { return 0; }
uint16_t memorySkipGet16(int s, int o) { return 0; }
uint32_t memorySkipGet32(int s, int o) { return 0; }
void memorySkipSet(int s, int o, uint8_t v) {}
void memorySkipSet16(int s, int o, uint16_t v) {}
void memorySkipSet32(int s, int o, uint32_t v) {}

uint32_t pop32()
{
  uint32_t aux = memoryAGet32(ss, esp);
  esp += 4;
  return aux;
}

void push32(uint32_t w)
{
  esp -= 4;
  memoryASet32(ss, esp, w);
  assert(esp > 0);
}

uint16_t pop()
{
  uint16_t aux = memoryAGet16(ss, esp);
  esp += 4;
  return aux;
}

void push(uint16_t w)
{
  esp -= 4;
  memoryASet32(ss, esp, w);
  assert(esp > 0);
}

struct MemAuto {
    static uint8_t Get8(int s, int o) { return memoryAGet(s, o); }
    static uint16_t Get16(int s, int o) { return memoryAGet16(s, o); }
    static uint32_t Get32(int s, int o) { return memoryAGet32(s, o); }
    static void Set8(int s, int o, uint8_t v) { memoryASet(s, o, v); }
    static void Set16(int s, int o, uint16_t v) { memoryASet16(s, o, v); }
    static void Set32(int s, int o, uint32_t v) { memoryASet32(s, o, v); }
};

struct MemPsp {
    static uint8_t Get8(int s, int o) { return memoryPspGet(s, o); }
    static uint16_t Get16(int s, int o) { return memoryPspGet16(s, o); }
    static uint16_t Get32(int s, int o) { assert(0); return 0; }
    static void Set8(int, int, uint8_t) { assert(0); }
    static void Set16(int, int, uint8_t) { assert(0); }
    static void Set32(int, int, uint8_t) { assert(0); }
};

template <typename Mem> struct Mem_DS_ESI {
  static uint8_t Get8() { return Mem::Get8(ds, esi); }
  static uint16_t Get16() { return Mem::Get16(ds, esi); }
  static uint32_t Get32() { return Mem::Get32(ds, esi); }
  static void Advance(int n) { esi += flags.direction ? -n : n; }
};

template <typename Mem> struct Mem_ES_EDI  {
  static uint8_t Get8() { return Mem::Get8(es, edi); }
  static uint16_t Get16() { return Mem::Get16(es, edi); }
  static uint16_t Get32() { return Mem::Get32(es, edi); }
  static void Set8(uint8_t v) { return Mem::Set8(es, edi, v); }
  static void Set16(uint16_t v) { return Mem::Set16(es, edi, v); }
  static void Set32(uint32_t v) { return Mem::Set32(es, edi, v); }
  static void Advance(int n) { edi += flags.direction ? -n : n; }
};

using ES_EDI = Mem_ES_EDI<MemAuto>;
using ES_EDI_PSP = Mem_ES_EDI<MemPsp>;
using DS_ESI = Mem_DS_ESI<MemAuto>;
using DS_ESI_PSP = Mem_DS_ESI<MemPsp>;

template <typename dst, typename src> void movsw()
{
  dst::Set16(src::Get16());
  dst::Advance(2);
  src::Advance(2);
}

template <typename dst, typename src> void movsd()
{
  dst::Set32(src::Get32());
  dst::Advance(4);
  src::Advance(4);
}

template <typename dst, typename src> void movsb()
{
  dst::Set8(src::Get8());
  dst::Advance(1);
  src::Advance(1);
}

template <typename dst> void stosb(int v)
{
  dst::Set8(v);
  dst::Advance(1);
}

template <typename dst> void stosd(uint32_t v)
{
  dst::Set32(v);
  dst::Advance(4);
}
template <typename src> int lodsb()
{
  int temp = src::Get8();
  src::Advance(1);
  return temp;
}

uint32_t sar32(uint32_t a, uint32_t b)
{
    int32_t sa = (int32_t)a;
    sa >>= b;
    return sa;
}

bool stop(const char* msg = nullptr, const char* info = nullptr);
//{
//    assert(0);
//    return false;
//}

void indirectCall(int s, int o)
{
    stop();
}

void indirectJump(int s, int o)
{
    stop();
}

void idiv32(int32_t r)
{
    int64_t num = ((uint64_t)edx<<32) | eax;
    eax = num / r;
    edx = num % r;
}

void div32(uint32_t r)
{
    uint64_t num = ((uint64_t)edx<<32) | eax;
    eax = num / r;
    edx = num % r;
}

void mul16(uint16_t r)
{
    int v = r * ax;
    ax = v & 0xffff;
    dx = v >> 16;
}

void mul32(uint32_t r)
{
    uint64_t v = (uint64_t)ax * (uint64_t)r;
    eax = (uint32_t)v;
    edx = v >> 32;
}

void div16(uint16_t r)
{
    uint16_t result = ax / r;
    uint16_t remain = ax % r;
    ax = result;
    dx = remain;
}

void mul8(uint8_t r)
{
    int v = r * al;
    ax = v & 0xffff;
}
    
void div8(int r)
{
    uint16_t result = ax / r;
    uint16_t remain = ax % r;
    al = result;
    ah = remain;
}

uint8_t ror8(uint8_t r, int l)
{
    return (r>>l) | (r<<(8-l));
}

uint8_t rol8(uint8_t r, int l)
{
    return (r<<l) | (r>>(8-l));
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

uint16_t sar16(uint16_t r, int n)
{
    return stop();
}

uint32_t flagAsReg32()
{
    return 0;
}

void flagsFromReg32(uint32_t)
{
//    stop();
}

template <typename src> void scasb_inv(uint8_t b)
{
    flags.zero = src::Get8() == b;
    src::Advance(1);
}

template <typename src> void scasw_inv(uint8_t w)
{
    flags.zero = src::Get16() == w;
    src::Advance(2);
}

template <typename dst> void stosw(int v)
{
  dst::Set16(v);
  dst::Advance(2);
}

template <typename src> int lodsw()
{
  int temp = src::Get16();
  src::Advance(2);
  return temp;
}

template <class dst, class src> void cmpsb()
{
    // TODO: should set carry?
    flags.zero = src::Get8() == dst::Get8();
    dst::Advance(1);
    src::Advance(1);
}

template <class dst, class src> void cmpsd()
{
    // TODO: should set carry?
    flags.zero = src::Get32() == dst::Get32();
    dst::Advance(4);
    src::Advance(4);
}

void sahf() { stop(); }

uint32_t ror32(uint32_t r, int l)
{
    return (r>>l) | (r<<(32-l));
}
uint32_t rol32(uint32_t r, int l)
{
    return (r<<l) | (r>>(32-l));
}

uint32_t rcr32(uint32_t r, int l) {
    while (l > 0)
    {
        int newCarry = !!(r & 1);
        r >>= 1;
        r |= flags.carry ? 0x80000000 : 0x00000000;
        flags.carry = newCarry;
        l--;
    }
    return r;
}

uint32_t rcl32(uint32_t r, int l) {
    while (l > 0)
    {
        int newCarry = !!(r & 0x80000000);
        r <<= 1;
        r |= flags.carry ? 0x00000001 : 0x00000000;
        flags.carry = newCarry;
        l--;
    }
    return r;
}

//uint16_t rcr16(uint16_t r, int l) { stop(); return 0;}
uint16_t rcl16(uint16_t r, int l) { stop(); return 0;}
uint16_t rol16(uint16_t r, int l)
{
    return (r<<l) | (r>>(16-l));
}

uint16_t ror16(uint16_t r, int l)
{
    return (r>>l) | (r<<(16-l));
}

uint16_t rcr16(uint8_t r, int i)
{
    assert(i == 1);
    int newCarry = !!(r & 0x1);
    r >>= 1;
    r |= flags.carry ? 0x8000 : 0;
    flags.carry = newCarry;
    return r;
}

namespace fpuinsns {
void fild32(uint32_t v) {stop();}
void fadd32(uint32_t v) {stop();}
void fdiv32(uint32_t v) {stop();}
void fmul64(uint64_t v) {stop();}
void fld1() {stop();}
void fcos() {stop();}
void fld64(uint64_t v) {stop();}
void fsubr64(uint64_t v) {stop();}
uint64_t fstp64() {stop(); return 0;}
uint64_t fistp64() {stop(); return 0;}
uint32_t fistp32() {stop(); return 0;}
uint64_t& st(int n) {static uint64_t x; stop(); return x;}
uint64_t fstp80() {stop(); return 0;}
void fmul80(uint64_t v) {stop();}
void fdiv64(uint64_t v) {stop();}
void fdiv80(uint64_t v) {stop();}
void fsubp80() {stop();}
void fadd64(uint64_t v) {stop();}
void fadd80(uint64_t v) {stop();}
void faddp64(uint64_t v) {stop();}
void faddp80(uint64_t v) {stop();}
//void fdiv64(uint64_t v) {stop();}
//void fadd64(uint64_t v) {stop();}
//void faddp64(uint64_t v) {stop();}
void fcomp64(uint64_t v) {stop();}
void fcomp32(uint32_t v) {stop();}
void fcomp80(uint64_t v) {stop();}
void fmul32(uint32_t v) {stop();}
uint32_t fstp32() {stop(); return 0;}
void fld32(uint32_t v) {stop();}
void fld16(uint16_t v) {stop();}
void fild16(uint16_t v) {stop();}
uint16_t fnstsw() {stop(); return 0;}
void fldcw(uint16_t) {stop();}
void frndtint() {stop();}
uint16_t fnstcw() {stop(); return 0;}
void fld80(uint64_t) {stop();}
void fprem() {stop();}
void fxch(uint64_t) {stop();}
}
using namespace fpuinsns;

void out16(int, int);
void out8(int, int);
int in8(int port);
int in16(int port);
void playSound(int seg, uint32_t ofs, int len, int samplerate, const char* fmt);
void sync();
void interrupt(int i);

