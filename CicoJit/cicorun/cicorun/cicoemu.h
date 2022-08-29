#pragma once
#include <stdint.h>
#include <assert.h>

namespace CicoContext
{

/*
template <MemAuto, DirAuto> void rep_stosw();
template <MemAuto, DirAuto> void rep_stosb();
template <MemAuto, DirAuto> void rep_movsw();
template <MemAuto, DirAuto> void rep_movsb();
template <MemAuto, DirAuto> void lodsw();
template <MemAuto, DirAuto> void lodsb();
*/
class cicocontext_t {
public:
    struct register_t
    {
      union {
        uint16_t r16;
        struct {
          uint8_t l;
          uint8_t h;
        } r8;
      };
    } a, b, c, d;

  //int _ah, _al, _bh, _bl, _ch, _cl, _dh, _dl;
  //int _ax, _bx, _cx, _dx,
  int _si, _di, _bp;
  int _cs, _ds, _ss, _es, _sp;
    
  bool interrupts, direction, carry;
  uint8_t& memory8(int seg, int ofs);
  uint16_t& memory16(int seg, int ofs);
    uint8_t memoryVideoGet8(int seg, int ofs);
    void memoryVideoSet8(int seg, int ofs, uint8_t data);
    uint16_t memoryVideoGet16(int seg, int ofs);
    void memoryVideoSet16(int seg, int ofs, uint16_t data);
  void _int(int i);
  void out(int port, int val);
  void in(uint8_t& val, int port);
  void push(const uint16_t& r);
  void pop(uint16_t& r);
    void push(const int& r);
    void pop(int& r);
  void stop(int a = 0);
  void callIndirect(int a);
    void cbw();
    void div(int);
    void sar(int, int);
};
#ifndef _HOST
#define ax ctx->a.r16
#define bx ctx->b.r16
#define cx ctx->c.r16
#define dx ctx->d.r16
#define ah ctx->a.r8.h
#define bh ctx->b.r8.h
#define ch ctx->c.r8.h
#define dh ctx->d.r8.h
#define al ctx->a.r8.l
#define bl ctx->b.r8.l
#define cl ctx->c.r8.l
#define dl ctx->d.r8.l
#define si ctx->_si
#define di ctx->_di
#define ds ctx->_ds
#define cs ctx->_cs
#define es ctx->_es
#define ss ctx->_ss
#define sp ctx->_sp
#define bp ctx->_bp
#define flags (*ctx)

#define memory ctx->memory8
#define memory16 ctx->memory16
#define memoryVideoGet ctx->memoryVideoGet8
#define memoryVideoSet ctx->memoryVideoSet8
#define memoryVideoGet16 ctx->memoryVideoGet16
#define memoryVideoSet16 ctx->memoryVideoSet16
#define memoryVideoAnd(seg, ofs, val) memoryVideoSet(seg, ofs, memoryVideoGet(seg, ofs) & val)
#define out ctx->out
#define in ctx->in
#define push ctx->push
#define pop ctx->pop
#define interrupt ctx->_int
#define stop ctx->stop
#define callIndirect ctx->callIndirect


#define cbw ctx->cbw
#define div ctx->div
#define sar ctx->sar
cicocontext_t* ctx;

struct MemAuto
{
    static uint8_t Get8(int seg, int nAddr) { return memory(seg, nAddr); }
    static void Set8(int seg, int nAddr, uint8_t nData) { memory(seg, nAddr) = nData; }
    static uint16_t Get16(int seg, int nAddr) { return memory16(seg, nAddr); }
    static void Set16(int seg, int nAddr, uint16_t nData) { memory16(seg, nAddr) = nData; }
};

struct MemVideo
{
    static uint8_t Get8(int seg, int nAddr) { return memoryVideoGet(seg, nAddr); }
    static void Set8(int seg, int nAddr, uint8_t nData) { memoryVideoSet(seg, nAddr, nData); }
    static uint16_t Get16(int seg, int nAddr) { return memoryVideoGet16(seg, nAddr); }
    static void Set16(int seg, int nAddr, uint16_t nData) { memoryVideoSet16(seg, nAddr, nData); }
};

struct DirAuto
{
    static void Assert()
    {
    }
    template<class T>
    static T Move(T& i)
    {
        if (flags.direction)
            return i--;
        else
            return i++ & 0xffff;
    }
};

template <typename SRC, typename DST, typename DIR> void movsw()
{
    DIR::Assert();
    DST::Set8(es, DIR::Move(di), SRC::Get8(ds, DIR::Move(si)));
    DST::Set8(es, DIR::Move(di), SRC::Get8(ds, DIR::Move(si)));
}
template <typename SRC, typename DST, typename DIR> void movsb ()
{
    DIR::Assert();
    DST::Set8(es, DIR::Move(di), SRC::Get8(ds, DIR::Move(si)));
}

template <class DST, class DIR> void stosw()
{
    DIR::Assert();
    DST::Set8(es, DIR::Move(di), al);
    DST::Set8(es, DIR::Move(di), ah);
}

template <typename DST, typename DIR> void rep_stosw()
{
    assert(cx == 0x7a34 || cx < 0x5000);
    if (cx)
    {
        while (cx--)
            stosw<DST, DIR>();
        cx = 0;
    }
}
template <typename SRC, typename DIR> void rep_stosb() { assert(0); }
template <typename SRC, typename DST, typename DIR> void rep_movsw()
{
    assert(cx < 0x6000);
    assert(cx);
    while (cx--)
        movsw<DST, SRC, DIR>();
    cx = 0;
}
template <typename SRC, typename DST, typename DIR> void rep_movsb()
{
    assert(cx < 0x6000);
    assert(cx);
    while (cx--)
        movsb<DST, SRC, DIR>();
    cx = 0;
}
template <typename SRC, typename DIR> void lodsw()
{
    DIR::Assert();
    al = SRC::Get8(ds, DIR::Move(si));
    ah = SRC::Get8(ds, DIR::Move(si));
}

template <typename SRC, typename DIR> void lodsb()
{
    DIR::Assert();
    al = SRC::Get8(ds, DIR::Move(si));
}




#else
extern cicocontext_t* ctx;
#endif





/*

void interrupt(int i)
{
    ctx->_int(i);
}
void out(int a, int b)
{
    ctx->out(a, b);
}
void in(int a, int b)
{
    ctx->in(a, b);
}
//  {  }
void push(int a)
{
    ctx->push(a);
}
//  {  }
void pop(int a)
{
    ctx->pop(a);

}
//  {  }
void stop(int a = 0)
{
    ctx->stop(a);
}
//  {  }
void callIndirect(int a)
{
    ctx->callIndirect(a);
}
uint8_t& memory(int seg, int ofs)
{
    return ctx->memory8(seg, ofs);
}

uint16_t& memory16(int seg, int ofs)
{
    return ctx->memory16(seg, ofs);
}
void cbw();
void div(int);
void sar(int, int);
 */
}
