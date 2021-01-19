#include "cpu.h"

void _STOP_(const char*) { assert(0); }

void _xchg(BYTE& a, BYTE& b) { BYTE t = a; a = b; b = t; }
void _xchg(WORD& a, WORD& b) { WORD t = a; a = b; b = t; }
void _lea(WORD& r, WORD s, WORD o)
{
    r = o;
}

void _repne_scasw();
void _les(WORD& reg, WORD addr)
{
    reg = memory16(_ds, addr);
    _es = memory16(_ds, addr+2);
}

template <typename INT>
INT rol(INT val) {
    return (val << 1) | (val >> (sizeof(INT)*8-1));
}
template <typename INT>
INT ror(INT val) {
    return (val >> 1) | (val << (sizeof(INT)*8-1));
}

void _rol(WORD& b, BYTE l)
{
    _ASSERT(l>=0 && l <= 7);
    while (l--) b = rol<WORD>(b);    
}

void _rol(BYTE& b, BYTE l)
{
    _ASSERT(l>=0 && l <= 7);
    while (l--) b = rol<BYTE>(b);
}

void _ror(WORD & b, BYTE l)
{
    _ASSERT(l == 1);
    b = ror<WORD>(b);
}


void _ror(BYTE& b, BYTE l)
{
    _ASSERT(l == 1);
    b = ror<BYTE>(b);
}

void _div(WORD& r)
{
    _ASSERT(r != 0);
    WORD result = _ax / r;
    WORD remain = _ax % r;
    _ax = result;
    _dx = remain;
}

void _rcl(WORD& r, BYTE c)
{
    _ASSERT(c == 1);
    int newCarry = !!(r & 0x8000);
    r <<= 1;
    r |= _flags.carry;
    _flags.carry = newCarry;
}

void _cwd()
{
    if (_ax & 0x8000)
        _dx = 0xffff;
    else
        _dx = 0x0000;
}

void _rcl(BYTE& r, BYTE c)
{
    _ASSERT(c == 1);
    int newCarry = !!(r & 0x80);
    r <<= 1;
    r |= _flags.carry;
    _flags.carry = newCarry;
}

void _repne_scasb()
{
    _ASSERT(_flags.direction == 0);
    _flags.zero = 0;
    while ( _cx-- && _flags.zero == 0 )
    {
        _flags.zero = (_al - memory(_es, _di)) == 0;
        _di++;
    }
}

void _idiv(WORD d)
{
    // DX:AX / d -> AX result, DX remainder
    int32_t dw = (_dx << 16) | _ax;
    WORD result = dw / d;
    WORD remainder = dw % d;
    _ax = result;
    _dx = remainder;
}

void _div(BYTE dby)
{
  int res = _ax / dby;
  int rem = _ax % dby;
  _al = res;
  _ah = rem;
}

void _sar(WORD& a, BYTE b)
{
    int16_t& sa = (short&)a;
    sa >>= b;
}

void _cbw()
{
    if (_al & 0x80)
        _ah = 0xff;
    else
        _ah = 0;
}

BYTE MemData::Get8(WORD seg, WORD ofs) { return memory(seg, ofs); }
void MemData::Set8(WORD seg, WORD ofs, BYTE data) { memory(seg, ofs) = data; }
BYTE MemVideo::Get8(WORD seg, WORD ofs) { return memoryVideoGet(seg, ofs); }
void MemVideo::Set8(WORD seg, WORD ofs, BYTE data) { memoryVideoSet(seg, ofs, data); }

WORD memoryVideoGet16(WORD seg, WORD ofs)
{
    return memoryVideoGet(seg, ofs) | (memoryVideoGet(seg, ofs+1)<<8);
}
void memoryVideoSet16(WORD seg, WORD ofs, WORD w)
{
    memoryVideoSet(seg, ofs+1, w>>8);
    memoryVideoSet(seg, ofs, w & 255);
}

void memoryVideoOr(WORD seg, WORD ofs, BYTE data)
{
    memoryVideoSet(seg, ofs, memoryVideoGet(seg, ofs) | data);
}
