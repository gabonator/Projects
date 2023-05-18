#pragma once
#include <stdint.h>
#include <assert.h>

#define import(name) void name() { ctx->call(#name); }
#define L(l) ctx->onLine(l);

namespace CicoContext
{

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
    } a, b, c, d, temp;

    uint16_t _si, _di, _bp;
    uint16_t _cs, _ds, _ss, _es, _sp;

    int _headerSize;
    bool interrupts, direction, carry, zero /*, sign*/;

    virtual void memoryASet8(int seg, int ofs, uint8_t v);
    virtual void memoryASet16(int seg, int ofs, uint16_t v);
    virtual uint8_t memoryAGet8(int seg, int ofs);
    virtual uint16_t memoryAGet16(int seg, int ofs);

    virtual void memoryBiosSet8(int seg, int ofs, uint8_t v);
    virtual void memoryBiosSet16(int seg, int ofs, uint16_t v);
    virtual uint8_t memoryBiosGet8(int seg, int ofs);
    virtual uint16_t memoryBiosGet16(int seg, int ofs);

    virtual uint8_t& memory8(int seg, int ofs);
    virtual uint16_t& memory16(int seg, int ofs);
    virtual uint8_t memoryVideoGet8(int seg, int ofs);
    virtual void memoryVideoSet8(int seg, int ofs, uint8_t data);
    virtual uint16_t memoryVideoGet16(int seg, int ofs);
    virtual void memoryVideoSet16(int seg, int ofs, uint16_t data);
    virtual void _int(int i);
    virtual void out(int port, uint8_t val);
    virtual void in(uint8_t& val, int port);
    virtual void out(int port, uint16_t val);
    virtual void push(const uint16_t& r);
    virtual uint16_t pop();
    virtual void push(const int& r);
    //virtual uint16_t pop();
    virtual bool stop(const char* msg = nullptr);
    virtual void callIndirect(int a);
    //virtual void call(const char* n);
    virtual void cbw();
    virtual void div(uint8_t r);
    virtual void div(uint16_t r);
    virtual void idiv(uint8_t r);
    virtual void idiv(uint16_t r);
    virtual void mul(uint8_t r);
    virtual void mul(uint16_t r);
    virtual void imul(uint8_t r);
    virtual void imul(uint16_t r);
    virtual uint8_t rcl(uint8_t r, int n);
    virtual uint16_t rcl(uint16_t r, int n);
    virtual uint8_t rcr(uint8_t r, int n);
    virtual uint16_t rcr(uint16_t r, int n);
    virtual uint8_t rol(uint8_t r, int n);
    virtual uint16_t rol(uint16_t r, int n);
    virtual uint8_t ror(uint8_t r, int n);
    virtual uint16_t ror(uint16_t r, int n);

    virtual uint16_t sar(uint16_t a, uint8_t b);
    virtual uint8_t sar(uint8_t a, uint8_t b);
    virtual void sync();
    //virtual void onLine(int a);
    virtual void cmc();
    virtual void aaa();
    virtual void load(const char* path, const char* file, int size);
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
#define tl ctx->temp.r8.l
#define tx ctx->temp.r16
#define headerSize ctx->_headerSize

#define memory ctx->memory8
#define memory16 ctx->memory16
#define memoryVideoGet ctx->memoryVideoGet8
#define memoryVideoSet ctx->memoryVideoSet8
#define memoryVideoGet16 ctx->memoryVideoGet16
#define memoryVideoSet16 ctx->memoryVideoSet16
#define memoryVideoAnd(seg, ofs, val) memoryVideoSet(seg, ofs, memoryVideoGet(seg, ofs) & val)
#define memoryVideoOr(seg, ofs, val) memoryVideoSet(seg, ofs, memoryVideoGet(seg, ofs) | val)
#define memoryASet ctx->memoryASet8
#define memoryASet16 ctx->memoryASet16
#define memoryAGet ctx->memoryAGet8
#define memoryAGet16 ctx->memoryAGet16

#define memoryBiosSet ctx->memoryBiosSet8
#define memoryBiosSet16 ctx->memoryBiosSet16
#define memoryBiosGet ctx->memoryBiosGet8
#define memoryBiosGet16 ctx->memoryBiosGet16

#define out ctx->out
#define in ctx->in
#define push ctx->push
#define pop ctx->pop
#define interrupt ctx->_int
#define stop ctx->stop
#define callIndirect ctx->callIndirect
#define load ctx->load


#define cbw ctx->cbw
#define div ctx->div
#define idiv ctx->idiv
#define mul ctx->mul
#define imul ctx->imul
#define sar ctx->sar
#define rol ctx->rol
#define ror ctx->ror
#define rcl ctx->rcl
#define rcr ctx->rcr
#define sync ctx->sync
#define cmc ctx->cmc
#define aaa ctx->aaa

extern cicocontext_t* ctx;

struct MemAuto
{
    static uint8_t Get8(int seg, int nAddr) { return memoryAGet(seg, nAddr); }
    static void Set8(int seg, int nAddr, uint8_t nData) { memoryASet(seg, nAddr, nData); }
    static uint16_t Get16(int seg, int nAddr) { return memoryAGet16(seg, nAddr); }
    static void Set16(int seg, int nAddr, uint16_t nData) { memoryASet16(seg, nAddr, nData); }
};

struct MemData
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

struct MemBios
{
    static uint8_t Get8(int seg, int nAddr) { return memoryBiosGet(seg, nAddr); }
    static void Set8(int seg, int nAddr, uint8_t nData) { memoryBiosSet(seg, nAddr, nData); }
    static uint16_t Get16(int seg, int nAddr) { return memoryBiosGet16(seg, nAddr); }
    static void Set16(int seg, int nAddr, uint16_t nData) { memoryBiosSet16(seg, nAddr, nData); }
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

struct DirForward
{
    static void Assert()
    {
    }
    template<class T>
    static T Move(T& i)
    {
        assert(!flags.direction);
        return i++;
    }
};

template <typename DST, typename SRC, typename DIR> void movsw()
{
    DIR::Assert();
    DST::Set8(es, DIR::Move(di), SRC::Get8(ds, DIR::Move(si)));
    DST::Set8(es, DIR::Move(di), SRC::Get8(ds, DIR::Move(si)));
}
template <typename DST, typename SRC, typename DIR> void movsb ()
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

template <class DST, class DIR> void stosb()
{
    DIR::Assert();
    DST::Set8(es, DIR::Move(di), al);
}

template <typename DST, typename DIR> void rep_stosw()
{
    if (cx)
    {
        while (cx--)
            stosw<DST, DIR>();
        cx = 0;
    }
}
template <typename DST, typename DIR> void rep_stosb()
{
    if (cx)
    {
        while (cx--)
            stosb<DST, DIR>();
        cx = 0;
    }
}
template <typename DST, typename SRC, typename DIR> void rep_movsw()
{
    if (!cx)
        return;
    while (cx--)
        movsw<DST, SRC, DIR>();
    cx = 0;
}
template <typename DST, typename SRC, typename DIR> void rep_movsb()
{
    if (cx == 0) return;
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
template <typename SRC, typename DIR> void rep_lodsb()
{
    assert(0);
}

template <typename SRC, typename DIR> void lodsb_es()
{
    DIR::Assert();
    al = SRC::Get8(es, DIR::Move(si));
}

template <typename SRC, typename DIR> void lodsb_ss()
{
    DIR::Assert();
    al = SRC::Get8(ss, DIR::Move(si));
}

template <class DST, class SRC, class DIR> void cmpsb()
{
    int a = SRC::Get8(ds, DIR::Move(si));
    int b = SRC::Get8(es, DIR::Move(di));
    flags.zero = a==b ? 1 : 0;
}

template <class DST, class SRC, class DIR> void cmpsw()
{
    int a = SRC::Get16(ds, DIR::Move(si));
    DIR::Move(si);
    int b = SRC::Get16(es, DIR::Move(di));
    DIR::Move(di);
    flags.carry = b < a;
    flags.zero = a==b ? 1 : 0;
}

template <class DST, class SRC, class DIR> void repe_cmpsw()
{
    flags.zero = 1;
    while (cx-- && flags.zero == 1 )
        cmpsw<DST, SRC, DIR>();
}

template <class SRC, class DIR> void repne_scasb(uint8_t value)
{
    assert(flags.direction == 0);
    flags.zero = 0;
    while (cx != 0 && flags.zero == 0 )
    {
        flags.zero = value - SRC::Get8(es, di) == 0;
        DIR::Move(di);
        cx--;
    }
}

#else
extern cicocontext_t* ctx;
#endif
}
