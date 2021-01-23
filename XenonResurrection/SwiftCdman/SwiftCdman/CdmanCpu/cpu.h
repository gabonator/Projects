#pragma once

#include <stdint.h>
#include "interface.h"
#include <assert.h>
#define _ASSERT assert


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


void _STOP_(const char*);

void _xlat();
void _in(BYTE& value, WORD port);

struct MemVideo
{
    static BYTE Get8(WORD seg, WORD nAddr);
    static void Set8(WORD seg, WORD nAddr, BYTE nData);
    static WORD Get16(WORD seg, WORD nAddr);
    static void Set16(WORD seg, WORD nAddr, WORD nData);
};

struct MemData
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

template <class DST, class SRC, class DIR>
void _movsb()
{
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
    _ASSERT(_cx < 0x7000);
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

void _push(WORD data);
WORD _pop();


void _xchg(BYTE& a, BYTE& b);
void _xchg(WORD& a, WORD& b); 
void _lea(WORD& r, WORD s, WORD o);
void _repne_scasw();
void _les(WORD& reg, WORD addr);
void _rol(WORD& b, BYTE l);
void _rol(BYTE& b, BYTE l);
void _ror(WORD & b, BYTE l);
void _ror(BYTE& b, BYTE l);
void _div(WORD& r);
void _rcl(WORD& r, BYTE c);
void _cwd();
void _rcl(BYTE& r, BYTE c);
void _repne_scasb();
BYTE memoryVideoGet(WORD seg, WORD ofs);
void memoryVideoSet(WORD seg, WORD ofs, BYTE data);
void _sync();
void _idiv(WORD d);
void _div(BYTE dby);
void _sar(WORD& a, BYTE b);
void _cbw();
void _indirectCall(WORD seg, WORD ptr);

void memoryVideoSet16(WORD seg, WORD ofs, WORD w);
void memoryVideoOr16(WORD seg, WORD ofs, WORD x);
void memoryVideoOr(WORD seg, WORD ofs, BYTE x);
WORD memoryVideoGet16(WORD seg, WORD ofs);
WORD memoryBiosGet16(WORD seg, WORD ofs);
