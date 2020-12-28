typedef uint16_t WORD;
typedef uint8_t BYTE;
typedef uint8_t FLAG;
typedef uint16_t WORD;

struct reg_t {
  struct register_t
  {
    union {
      WORD r16;
      struct {
        BYTE l;
        BYTE h;
      } r8;
    };
  } a, b, c, d;

  struct {
      union {
          struct {
              FLAG interrupt:1;
              FLAG direction:1;
              FLAG carry:1;
              FLAG aux:1;
              FLAG zero:1;
              FLAG sign:1;
          } bit;
          WORD f16;
      };
  } flags;

  WORD ds;
  WORD es;
  WORD si;
  WORD di;
  WORD bp;
  WORD cs;
  WORD sp;
  WORD ss;
};

extern reg_t _reg;

#define _flags _reg.flags.bit
#define _ax _reg.a.r16
#define _ah _reg.a.r8.h
#define _al _reg.a.r8.l

#define _bx _reg.b.r16
#define _bh _reg.b.r8.h
#define _bl _reg.b.r8.l

#define _cx _reg.c.r16
#define _ch _reg.c.r8.h
#define _cl _reg.c.r8.l

#define _dx _reg.d.r16
#define _dh _reg.d.r8.h
#define _dl _reg.d.r8.l

#define _ds _reg.ds
#define _es _reg.es
#define _si _reg.si
#define _di _reg.di
#define _bp _reg.bp
//#define _cs _reg.cs
#define _sp _reg.sp
#define _ss _reg.ss

#define _cli() _reg.flags.bit.intr = 0
#define _sti() _reg.flags.bit.intr = 1
#define _cld() _reg.flags.bit.dir = 0
#define _std() _reg.flags.bit.dir = 1
#define _clc() _reg.flags.bit.carry = 0
#define _stc() _reg.flags.bit.carry = 1
#define af _reg.flags.bit.aux
#define cf _reg.flags.bit.carry
#define zf _reg.flags.bit.zero


WORD& memory16(WORD segment, WORD offset);
BYTE& memory(WORD segment, WORD offset);

void _push(WORD w);
WORD _pop();
void _interrupt(BYTE n);
void _out(WORD, BYTE);
void _out(WORD, WORD);

template <class SRC, class DIR> void _lodsb();
template <class SRC, class DIR> void _lodsw();
template <class DST, class DIR> void _stosw();
template <class DST, class SRC, class DIR> void _rep_movsb();
template <class DST, class DIR> void _rep_stosb();
template <class DST, class SRC, class DIR> void _rep_movsw();
template <class DST, class DIR> void _rep_stosw();

template <class DST, class DIR> void _stosb();


#define _ASSERT assert

void _STOP_(const char*) { assert(0); }


void _xlat();
void _in(BYTE& value, WORD port);

struct MemVideo
{
    static BYTE Get8(WORD seg, WORD nAddr);
    static void Set8(WORD seg, WORD nAddr, BYTE nData);
    static WORD Get16(WORD seg, WORD nAddr);
    static void Set16(WORD seg, WORD nAddr, WORD nData);
};

struct MemAuto
{
    static BYTE Get8(WORD seg, WORD nAddr);
    static void Set8(WORD seg, WORD nAddr, BYTE nData);
    static WORD Get16(WORD seg, WORD nAddr);
    static void Set16(WORD seg, WORD nAddr, WORD nData);
};

struct DirForward
{
    static void Assert()
    {
        _ASSERT(_flags.direction==0);
    }
    template<class T>
    static T Move(T& i)
    {
        return i++;
    }
};

struct DirBackward
{
    static void Assert()
    {
        _ASSERT(_flags.direction==1);
    }
    template<class T>
    static T Move(T& i)
    {
        return i--;
    }
};

struct DirAuto
{
    static void Assert()
    {
    }
    template<class T>
    static T Move(T& i)
    {
        if (_flags.direction)
        {
            _ASSERT(0);
            return i--;
        }
        else
            return i++;
    }
};

template <class DST, class SRC, class DIR>
void _movsb()
{
    //memory[adr(_es, _di)] = memory[adr(_ds, _si)];
    DIR::Assert();
    DST::Set8(_es, DIR::Move(_di), SRC::Get8(_ds, DIR::Move(_si)));
}



template <class DST, class SRC, class DIR>
void _rep_movsb()
{
    _ASSERT(_cx < 0x6000);
    _ASSERT(_cx);
    while (_cx--)
        _movsb<DST, SRC, DIR>();
    _cx = 0;
}

template <class DST, class SRC, class DIR>
void _movsw()
{
    DIR::Assert();
    DST::Set8(_es, DIR::Move(_di), SRC::Get8(_ds, DIR::Move(_si)));
    DST::Set8(_es, DIR::Move(_di), SRC::Get8(_ds, DIR::Move(_si)));
}

template <class DST, class SRC, class DIR>
void _rep_movsw()
{
    _ASSERT(_cx < 0x6000);
    _ASSERT(_cx);
    while (_cx--)
        _movsw<DST, SRC, DIR>();
    _cx = 0;
}

template <class DST, class DIR>
void _rep_stosb()
{
    _ASSERT(_cx < 0x6000);
    _ASSERT(_cx);
    while (_cx--)
        _stosb<DST, DIR>();
    _cx = 0;
}

template <class DST, class DIR>
void _stosb()
{
    DIR::Assert();
    DST::Set8(_es, DIR::Move(_di), _al);
}

template <class DST, class DIR>
void _rep_stosw()
{
    _ASSERT(_cx == 0x7a34 || _cx < 0x5000);
    if (_cx)
    {
        while (_cx--)
            _stosw<DST, DIR>();
        _cx = 0;

    }
}

template <class DST, class DIR>
void _stosw()
{
    DIR::Assert();
    DST::Set8(_es, DIR::Move(_di), _al);
    DST::Set8(_es, DIR::Move(_di), _ah);
}
/*
template <class SRC, class DIR>
void _rep_lodsw()
{
    _ASSERT(_cx);
    while (_cx--)
        _lodsw<SRC, DIR>();
    _cx = 0;
}*/

template <class SRC, class DIR>
void _lodsw()
{
    DIR::Assert();
    _al = SRC::Get8(_ds, DIR::Move(_si));
    _ah = SRC::Get8(_ds, DIR::Move(_si));
}

template <class SRC, class DIR>
void _lodsb()
{
    DIR::Assert();
    _al = SRC::Get8(_ds, DIR::Move(_si));
}



//
std::vector<int> m_arrStack;
void StackWrite(int nOffset, WORD nData)
{
    _ASSERT(nOffset/2 >= 0 && nOffset/2 < (int)m_arrStack.size());
    _ASSERT((nOffset&1) == 0);
    m_arrStack[nOffset/2] = nData;
}

WORD StackRead(int nOffset)
{
    _ASSERT(nOffset/2 >= 0 && nOffset/2 < (int)m_arrStack.size());
    _ASSERT((nOffset&1) == 0);
    return m_arrStack[nOffset/2];
}

void _push(WORD data)
{
    StackWrite(_sp, data);
    _sp -= 2;
}

WORD _pop()
{
    _sp += 2;
    return StackRead(_sp);
}

void _xchg(BYTE& a, BYTE& b) { BYTE t = a; a = b; b = t; }
void _xchg(WORD& a, WORD& b) { WORD t = a; a = b; b = t; }
void _lea(WORD a, WORD b) {_ASSERT(0);}
void _repne_scasw();
void _les(WORD& reg, WORD addr)
{
    reg = memory16(_ds, addr);
    _es = memory16(_ds, addr+2);
}
template <typename INT>
INT rol(INT val) {
    return (val << 1) | (val >> (sizeof(INT)*CHAR_BIT-1));
}
template <typename INT>
INT ror(INT val) {
    return (val >> 1) | (val << (sizeof(INT)*CHAR_BIT-1));
}

void _rol(WORD& b, BYTE l)
{
    _ASSERT(l>=0 && l <= 7);
    while (l--) b = rol<WORD>(b);    
}

void _ror(WORD & b, BYTE l)
{
    //if (l==0)
    //    std::cout << "_ror 0\n";
    
    //_ASSERT(l == 1 || l == 4 || l == 0 || l == 6);
    while (l--)
        b = ror<WORD>(b);
}


void _ror(BYTE& b, BYTE l)
{
    _ASSERT(l == 1);
    b = ror<BYTE>(b);
}

void _div(WORD& r)
{
//    _ASSERT(_dx == 0);
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

BYTE memoryVideoGet(WORD seg, WORD ofs);
void memoryVideoSet(WORD seg, WORD ofs, BYTE data);
void _sync();
void _idiv(WORD d)
{
    // DX:AX / d -> AX result, DX remainder
    int32_t dw = (_dx << 16) | _ax;
    WORD result = dw / d;
    WORD remainder = dw % d;
    _ax = result;
    _dx = remainder;
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
