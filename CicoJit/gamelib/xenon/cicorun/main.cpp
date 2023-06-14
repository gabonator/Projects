// Other linker flags: /opt/homebrew/lib/libSDL2.dylib
// System header search paths: /opt/homebrew/include/SDL2
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "sdl.h"
#define _HOST
#include "cicoemu.h"
#include "ega.h"
#include <list>
//#include "game/game.h"

bool tracenow = false;
namespace CicoContext{
    cicocontext_t* ctx;
}

CSdl mSdl;
//CEga mVideo;
CEga mEga;
CCga mCga;
CVga mVga;
CText mText;
CVideoAdapter* mVideo = &mEga;
int lastKey = -1;
char root[1024];
uint8_t mem[0xa0000];
extern unsigned char font[2048];
int headerSize = 0;
int loadAddress = 0;
//int ticksPastSync = 0;
//int internaltick = 0;
//int tickrequestspastsync = 0;
std::list<char> keyBuffer;
int newkey = -1;

void _sync()
{
    for (int y=0; y<200; y++)
      for (int x=0; x<320; x++)
        mSdl.SetPixel(x, y, mVideo->GetPixel(x, y));
    mSdl.Loop();
}
static int keys = 0;

void syncKeyb()
{
    mSdl.Loop(true);
}
void onKey(int k, int p)
{
//    if (p && k == SDL_SCANCODE_RETURN)
//        keyboardBuffer.push_back(0x1c0d);
  if (k == SDL_SCANCODE_ESCAPE) exit(1);
        
    int code = 0;
    switch (k)
    {
        case SDL_SCANCODE_UP: code = 1; break;
        case SDL_SCANCODE_DOWN: code = 2; break;
        case SDL_SCANCODE_LEFT: code = 4; break;
        case SDL_SCANCODE_RIGHT: code = 8; break;
        case SDL_SCANCODE_SPACE: code = 0x80;
            if (p && !(CicoContext::ctx->memory8(0x2853, 0x8f59) & 0x80))
                CicoContext::ctx->memory8(0x2853, 0x8F5B) = 0xff;
            break;
        case SDL_SCANCODE_A: CicoContext::ctx->memoryASet16(0x2853, 0x9190, CicoContext::ctx->memoryAGet16(0x2853, 0x9190) - 0x100); break;
        case SDL_SCANCODE_B: code = 0x20; break;
        case SDL_SCANCODE_C: code = 0x40; break;
            
        case SDL_SCANCODE_RETURN: code = 0x80;
            CicoContext::ctx->memory8(0x2853, 0x8f5b) = 0xff; break;
    }
    if (p)
        CicoContext::ctx->memory8(0x2853, 0x8f59) |= code;
    else
        CicoContext::ctx->memory8(0x2853, 0x8f59) &= ~code;    
}



void sub_1f2ff();
void sub_208f9();
void sub_208dc();
void sub_20854();
void sub_1f3b5();
void sub_1f3ae();
void sub_1f3a7();
void sub_1f325();
void sub_1f324();
void sub_1f3d7();
void sub_1f3c7();
void sub_211cc();
void sub_21132();
void sub_21090();
void sub_20f54();
void sub_20d8a();
void sub_20d18();
void sub_20c7b();
void sub_20c5e();
void sub_20be5();
void sub_20b8a();
void sub_20b5b();
void sub_20ad0();
void sub_20a39();
void sub_209e9();
void sub_2098c();
void sub_20708();
void sub_20653();
void sub_205ed();
void sub_205ae();
void sub_205ae();
void sub_205a9();
void sub_2058d();
void sub_20568();
void sub_20482();
void sub_1ebd7();
void sub_1ebd0();
void sub_203da();
void sub_1ff41();
void sub_1fea1();
void sub_1f585();
void sub_1f57c();
void sub_1f492();
void sub_1f3ef();
void sub_1f2ba();
void sub_16284();
void sub_1758f();
void sub_1655b();
void sub_14311();
void sub_14759();
void sub_137df();
void sub_10853();
void sub_10761();
void sub_170f1();
void sub_16eef();
void sub_10761();
void sub_10853();
void sub_10897();
void sub_108b9();
void sub_1091f();
void sub_10ab7();
void sub_10f2b();
void sub_11f4d();
void sub_11fb4();
void sub_11ff3();
void sub_120f7();
void sub_1213c();
void sub_121e9();
void sub_1221a();
void sub_1229b();
void sub_1237e();
void sub_123ed();
void sub_1246d();
void sub_1250b();
void sub_125a8();
void sub_1262d();
void sub_12697();
void sub_128b8();
void sub_128df();
void sub_137df();
void sub_13801();
void sub_13835();
void sub_13872();
void sub_13900();
void sub_13998();
void sub_1399c();
void sub_139ee();
void sub_13a99();
void sub_13aa7();
void sub_13b55();
void sub_13b76();
void sub_13bdf();
void sub_14311();
void sub_14759();
void sub_169c8();
void sub_169d0();
void sub_16a0a();
void sub_16aad();
void sub_16ac7();
void sub_16bca();
void sub_16d22();
void sub_16e2c();
void sub_1714d();
void sub_171dd();
void sub_172c4();
void sub_17520();
void sub_17569();
void sub_17dde();
void sub_17e87();
void sub_1830c();
void sub_183bd();
void sub_185d0();
void sub_1866d();
void sub_18745();
void sub_18783();
void sub_187d5();
void sub_188a9();
void sub_189ae();
void sub_18c3e();
void sub_12ab2();
void sub_12aa4();
void sub_12a48();
void sub_12a66();
void sub_1308c();
void sub_12aca();
void sub_12a6e();
void sub_13246();
void sub_12e84();
void sub_131b6();
void sub_12f08();
void sub_12f7c();
void sub_13126();
void sub_12d86();
void sub_12df0();
void sub_12d2a();
void sub_12b80();
void sub_12ac4();
void sub_12ad0();
void sub_13360();
void sub_135ce();
void sub_1714a();
void sub_172c4();
void sub_17520();
void sub_1480b();
void sub_1ebd0();
void sub_11e61();
void sub_13aa7();
void sub_1714a();
void sub_108b9();
void sub_1ff41();
void sub_13a39();
void sub_10f2b();
void sub_13998();
void sub_128df();
void sub_12a6e();
void sub_12ab2();
void sub_137ca();
void sub_16d22();
void sub_11f4d();
void sub_1308c();
void sub_16a0a();
void sub_125a8();
void sub_13835();
void sub_139ee();
void sub_1091f();
void sub_13a39();
void sub_13b76();
void sub_16aad();
void sub_16696();
void sub_166a6();
void sub_209a6();
void sub_244a3();
void sub_224b0();
void sub_209a6();
void sub_224b0();
void sub_16ac7();
void sub_12ad0();
void sub_18e01();
void sub_128b8();
void sub_17f32();
void sub_18e01();
void sub_18ca7();
void sub_188a9();
void sub_119bc();
void sub_100a4();
void sub_14311();
void sub_103a8();
void sub_189ae();
void sub_18c3e();
void sub_17f79();
void sub_1866d();
void sub_17dde();
void sub_180ca();
void sub_18114();
void sub_18126();
void sub_180f5();
void sub_187d5();
void sub_18783();
void sub_17ce6();
void sub_17bef();
void sub_17ac4();
void sub_17e87();
void sub_185d0();
void sub_13b55();
void sub_1830c();
void sub_18d18();
void sub_183bd();
void sub_184e1();
void sub_18c5f();
void CicoContext::cicocontext_t::callIndirect(int seg, int ofs)
{
    switch (seg*0x10000+ofs)
    {
        case 0x1f29006f: sub_1f2ff(); break;
        case 0x1f291669: sub_208f9(); break;
        case 0x1f29164c: sub_208dc(); break;
        case 0x1f2915c4: sub_20854(); break;
        case 0x1f290125: sub_1f3b5(); break;
        case 0x1f29011e: sub_1f3ae(); break;
        case 0x1f290117: sub_1f3a7(); break;
        case 0x1f290095: sub_1f325(); break;
        case 0x1f290094: sub_1f324(); break;
        case 0x1f290147: sub_1f3d7(); break;
        case 0x1f290137: sub_1f3c7(); break;
        case 0x1f291f3c: sub_211cc(); break;
        case 0x1f291ea2: sub_21132(); break;
        case 0x1f291e00: sub_21090(); break;
        case 0x1f291cc4: sub_20f54(); break;
        case 0x1f291afa: sub_20d8a(); break;
        case 0x1f291a88: sub_20d18(); break;
        case 0x1f2919eb: sub_20c7b(); break;
        case 0x1f2919ce: sub_20c5e(); break;
        case 0x1f291955: sub_20be5(); break;
        case 0x1f2918fa: sub_20b8a(); break;
        case 0x1f2918cb: sub_20b5b(); break;
        case 0x1f291840: sub_20ad0(); break;
        case 0x1f2917a9: sub_20a39(); break;
        case 0x1f291759: sub_209e9(); break;
        case 0x1f2916fc: sub_2098c(); break;
        case 0x1f291478: sub_20708(); break;
        case 0x1f2913c3: sub_20653(); break;
        case 0x1f29135d: sub_205ed(); break;
        case 0x1f29131e: sub_205ae(); break;
        case 0x1f291319: sub_205a9(); break;
        case 0x1f2912fd: sub_2058d(); break;
        case 0x1f2912d8: sub_20568(); break;
        case 0x1f2911f2: sub_20482(); break;
        case 0x1000ebd7: sub_1ebd7(); break;
        case 0x1000ebd0: sub_1ebd0(); break;
        case 0x1f29114a: sub_203da(); break;
        case 0x1f290cb1: sub_1ff41(); break;
        case 0x1f290c11: sub_1fea1(); break;
        case 0x1f2902f5: sub_1f585(); break;
        case 0x1f2902ec: sub_1f57c(); break;
        case 0x1f290202: sub_1f492(); break;
        case 0x1f29015f: sub_1f3ef(); break;
        case 0x1f29002a: sub_1f2ba(); break;
        case 0x10006284: sub_16284(); break;
        case 0x1000758f: sub_1758f(); break;
        case 0x1000655b: sub_1655b(); break;
        case 0x10004311: sub_14311(); break;
        case 0x10004759: sub_14759(); break;
        case 0x100037df: sub_137df(); break;
        case 0x10000853: sub_10853(); break;
        case 0x10000761: sub_10761(); break;
        case 0x100070f1: sub_170f1(); break;
        case 0x10006eef: sub_16eef(); break;
        case 0x10000897: sub_10897(); break;
        case 0x100008b9: sub_108b9(); break;
        case 0x1000091f: sub_1091f(); break;
        case 0x10000ab7: sub_10ab7(); break;
        case 0x10000f2b: sub_10f2b(); break;
        case 0x10001f4d: sub_11f4d(); break;
        case 0x10001fb4: sub_11fb4(); break;
        case 0x10001ff3: sub_11ff3(); break;
        case 0x100020f7: sub_120f7(); break;
        case 0x1000213c: sub_1213c(); break;
        case 0x100021e9: sub_121e9(); break;
        case 0x1000221a: sub_1221a(); break;
        case 0x1000229b: sub_1229b(); break;
        case 0x1000237e: sub_1237e(); break;
        case 0x100023ed: sub_123ed(); break;
        case 0x1000246d: sub_1246d(); break;
        case 0x1000250b: sub_1250b(); break;
        case 0x100025a8: sub_125a8(); break;
        case 0x1000262d: sub_1262d(); break;
        case 0x10002697: sub_12697(); break;
        case 0x100028b8: sub_128b8(); break;
        case 0x100028df: sub_128df(); break;
        case 0x10003801: sub_13801(); break;
        case 0x10003835: sub_13835(); break;
        case 0x10003872: sub_13872(); break;
        case 0x10003900: sub_13900(); break;
        case 0x10003998: sub_13998(); break;
        case 0x1000399c: sub_1399c(); break;
        case 0x100039ee: sub_139ee(); break;
        case 0x10003a99: sub_13a99(); break;
        case 0x10003aa7: sub_13aa7(); break;
        case 0x10003b55: sub_13b55(); break;
        case 0x10003b76: sub_13b76(); break;
        case 0x10003bdf: sub_13bdf(); break;
        case 0x100069c8: sub_169c8(); break;
        case 0x100069d0: sub_169d0(); break;
        case 0x10006a0a: sub_16a0a(); break;
        case 0x10006aad: sub_16aad(); break;
        case 0x10006ac7: sub_16ac7(); break;
        case 0x10006bca: sub_16bca(); break;
        case 0x10006d22: sub_16d22(); break;
        case 0x10006e2c: sub_16e2c(); break;
        case 0x1000714d: sub_1714d(); break;
        case 0x100071dd: sub_171dd(); break;
        case 0x100072c4: sub_172c4(); break;
        case 0x10007520: sub_17520(); break;
        case 0x10007569: sub_17569(); break;
        case 0x10007dde: sub_17dde(); break;
        case 0x10007e87: sub_17e87(); break;
        case 0x1000830c: sub_1830c(); break;
        case 0x100083bd: sub_183bd(); break;
        case 0x100085d0: sub_185d0(); break;
        case 0x1000866d: sub_1866d(); break;
        case 0x10008745: sub_18745(); break;
        case 0x10008783: sub_18783(); break;
        case 0x100087d5: sub_187d5(); break;
        case 0x100088a9: sub_188a9(); break;
        case 0x100089ae: sub_189ae(); break;
        case 0x10008c3e: sub_18c3e(); break;
        case 0x10002ab2: sub_12ab2(); break;
        case 0x10002aa4: sub_12aa4(); break;
        case 0x10002a48: sub_12a48(); break;
        case 0x10002a66: sub_12a66(); break;
        case 0x1000308c: sub_1308c(); break;
        case 0x10002aca: sub_12aca(); break;
        case 0x10002a6e: sub_12a6e(); break;
        case 0x10003246: sub_13246(); break;
        case 0x10002e84: sub_12e84(); break;
        case 0x100031b6: sub_131b6(); break;
        case 0x10002f08: sub_12f08(); break;
        case 0x10002f7c: sub_12f7c(); break;
        case 0x10003126: sub_13126(); break;
        case 0x10002d86: sub_12d86(); break;
        case 0x10002df0: sub_12df0(); break;
        case 0x10002d2a: sub_12d2a(); break;
        case 0x10002b80: sub_12b80(); break;
        case 0x10002ac4: sub_12ac4(); break;
        case 0x10002ad0: sub_12ad0(); break;
        case 0x10003360: sub_13360(); break;
        case 0x100035ce: sub_135ce(); break;
        case 0x1000714a: sub_1714a(); break;
        case 0x1000480b: sub_1480b(); break;
        case 0x10001e61: sub_11e61(); break;
        case 0x10003a39: sub_13a39(); break;
        case 0x100037ca: sub_137ca(); break;
        case 0x10006696: sub_16696(); break;
        case 0x100066a6: sub_166a6(); break;
        case 0x1f291716: sub_209a6(); break;
        case 0x1f295213: sub_244a3(); break;
        case 0x1f293220: sub_224b0(); break;
        case 0x10008e01: sub_18e01(); break;
        case 0x10007f32: sub_17f32(); break;
        case 0x10008ca7: sub_18ca7(); break;
        case 0x100019bc: sub_119bc(); break;
        case 0x100000a4: sub_100a4(); break;
        case 0x100003a8: sub_103a8(); break;
        case 0x10007f79: sub_17f79(); break;
        case 0x100080ca: sub_180ca(); break;
        case 0x10008114: sub_18114(); break;
        case 0x10008126: sub_18126(); break;
        case 0x100080f5: sub_180f5(); break;
        case 0x10007ce6: sub_17ce6(); break;
        case 0x10007bef: sub_17bef(); break;
        case 0x10007ac4: sub_17ac4(); break;
        case 0x10008d18: sub_18d18(); break;
        case 0x100084e1: sub_184e1(); break;
        case 0x10008c5f: sub_18c5f(); break;
  
        default:
            printf("Skip indirect: %04x:%04x\n", seg, ofs);
    }
}





uint8_t memoryBiosGet8(int seg, int ofs)
{
    if (seg == 0xffff && ofs == 0x000e)
        return 0xfc;
    if (seg == 0xf000 && ofs == 0xfffe)
        return 0xfc; // pc at
    if (seg == 0x0040 && ofs == 0x0087)
        return 0x00; // ega active
    if (seg == 0x0040 && ofs == 0x0088)
        return 0x09;
    if (seg == 0x0040 && ofs == 0x0017) // http://www.powernet.co.za/info/bios/mem/40_0017.htm
        return 0x00; // shift keys
    if (seg == 0xf000 && ofs >= 0xfa6e && ofs < (0xfa6e + sizeof(font)))
        return font[ofs-0xfa6e];
    if (seg == 0x0040 && ofs == 0x0010)
        return 0x26;
    if (seg == 0x0040 && ofs == 0x006c)
    {
        auto getTick = []() -> uint32_t {
            struct timespec ts;
            unsigned theTick = 0U;
            clock_gettime( CLOCK_REALTIME, &ts );
            theTick  = ts.tv_nsec / 1000000;
            theTick += ts.tv_sec * 1000;
            return theTick;
        };

        return getTick()/54; // 0xd1; // number of ticks since midnight 54ms
    }
    if (seg == 0x0000 && ofs == 0x0000)
        return 0x1a;
    if (seg == 0x0000 && ofs == 0x041a)
        return 0x00;
    if (seg == 0x0000 && ofs == 0x0484)
        return 40;
    if (seg == 0x0040 && ofs == 0x0012) 
        return 0x0;
    assert(0);
    return 0;
}
uint8_t memoryPsp(int seg, int ofs)
{
    if (seg == 0x1d3)
    {
        const char env[] = "PATH=Z:\\" "\x00" "COMSPEC=Z:\\COMMAND.COM" "\x00"
          "BLASTER=A220 I7 D1 H5 T6" "\x00\x00\x01\x00" "C:\\PRE\\HISTORIK.EXE"
          "\x00\x00\x00\x00\x00\x00\x00";
        if (ofs<sizeof(env))
            return env[ofs];
        if (ofs<0xc0)
            return 0;
        
        assert(0);
        return 0;
    }
    if (seg == 0x1dd && ofs == 0x80)
        return 0;
    if (seg == 0x1dd && ofs == 0x81)
        return 0x0d;

    assert(0);
}
uint16_t memoryPsp16(int seg, int ofs)
{
    if (seg==0x1d3)
        return memoryPsp(seg, ofs) | (memoryPsp(seg, ofs+1)<<8);
    
//    assert(seg == 0x1dd);
    // https://en.wikipedia.org/wiki/Program_Segment_Prefix
    switch (ofs)
    {
        case 0x02:
            //     Segment of the first byte beyond the memory allocated to the program
            return 0x9fff;
        case 0x2c:
            // Environment segment;
            return 0x1d3;
        default:
            assert(0);
            return 0;
    }
}
void memoryBiosSet8(int seg, int ofs, uint8_t v)
{
    printf("skip bios write %x:%x = %x\n", seg, ofs, v);
}
void memoryBiosSet16(int seg, int ofs, uint16_t v)
{
    printf("skip bios write %x:%x = %x\n", seg, ofs, v);
}

uint16_t memoryBiosGet16(int seg, int ofs)
{
    if (seg == 0x0040 && ofs == 0x006c) // timer
        return 0;
    if (seg == 0x0000 && ofs == 0x041a) // int?
        return 0;
    if (seg == 0x0040 && ofs == 0x0063) // int?
        return 0x3d4;
    if (seg == 0x0000 && ofs < 400)
        return 0;
    if (seg == 0x0040 && ofs == 0x0080)
        return 0x1e;
    if (seg == 0x0000 && ofs == 0x046c)
        return 0;
    if (seg == 0x0000 && ofs == 0x046e)
    {
        static int c = 0;
        c += 100;
        return c;
    }
    if (seg == 0x0040 && ofs == 0x0010) // int?
        return 0;
    assert(0);
    return 0;
}

namespace CicoContext
{

uint8_t cicocontext_t::memoryAGet8(int seg, int ofs)
{
    if (seg == 0xf000)
    {
        int f= 9 ;
    }
//    assert(seg >= 0x01ed && seg < 0xa000);
//    assert(ofs >= 0x0000 && ofs <= 0xffff);
    if (seg == 0x1fe8 && ofs ==4)
    {
        int f = 9;
    }
    ofs &= 0xffff;
    if ((seg == 0x01ed || seg == 0x01dd || seg == 0x01d3) && ofs < 256)
        return memoryPsp(seg, ofs);
    else
    if (seg >= loadAddress && seg < 0xa000)
        return memory8(seg, ofs);
    else if (seg >= 0xa000 && seg < 0xe000)
        return memoryVideoGet8(seg, ofs);
    else
        return memoryBiosGet8(seg, ofs); // bios
}
uint8_t cicocontext_t::memoryBiosGet8(int seg, int ofs)
{
    if ((seg == 0x01dd || seg == loadAddress || seg == 0x01d3) && ofs < 256)
        return ::memoryPsp(seg, ofs);
    return ::memoryBiosGet8(seg, ofs);
}
void cicocontext_t::memoryBiosSet8(int seg, int ofs, uint8_t val)
{
//    assert(0);
}
uint16_t cicocontext_t::memoryBiosGet16(int seg, int ofs)
{
    if ((seg == 0x01dd || seg == loadAddress || seg == 0x01d3) && ofs < 256)
        return ::memoryPsp16(seg, ofs);
    return ::memoryBiosGet16(seg, ofs);
}
void cicocontext_t::memoryBiosSet16(int seg, int ofs, uint16_t val)
{
    if ((seg == 0x01dd || seg == loadAddress) && ofs < 256)
        assert(0); // ???
    else
        ::memoryBiosSet16(seg, ofs, val);
}

uint16_t cicocontext_t::memoryAGet16(int seg, int ofs)
{
//    assert(seg >= 0x01ed && seg < 0xa000);
//    assert(ofs >= 0 && ofs <= 0xffff);
    ofs &= 0xffff;
    if ((seg == 0x01dd || /*seg == loadAddress ||*/ seg == 0x01d3) && ofs < 256)
        return memoryPsp16(seg, ofs);
    else if (seg >= loadAddress && seg < 0xa000)
        return memory16(seg, ofs);
    else if (seg >= 0xa000 && seg < 0xe000)
        return memoryVideoGet16(seg, ofs);
    else
        return memoryBiosGet16(seg, ofs);
        //assert(0); // bios
}

void cicocontext_t::memoryASet8(int seg, int ofs, uint8_t val)
{
//    assert (seg >= 0x01ed && seg < 0xa000);
//    assert(ofs >= 0 && ofs <= 0xffff);
    ofs &= 0xffff;
    if ((seg == 0x01dd /*|| seg == loadAddress*/) && ofs < 256)
        assert(0);
    else if (seg >= loadAddress && seg < 0xa000)
        memory8(seg, ofs) = val;
    else if (seg >= 0xa000 && seg < 0xe000)
        memoryVideoSet8(seg, ofs, val);
    else
        memoryBiosSet8(seg, ofs, val);
}

void cicocontext_t::memoryASet16(int seg, int ofs, uint16_t val)
{
//    assert(seg >= 0x01ed && seg < 0xa000);
//    assert(ofs >= 0x0000 && ofs <= 0xffff);

    ofs &= 0xffff;

    if ((seg == 0x01dd || seg == 0x01ed) && ofs < 256)
    {
        printf("Skip set before app\n");
//        assert(0); // ???
    }
    else
    if (seg >= loadAddress && seg < 0xa000)
        memory16(seg, ofs) = val;
    else if (seg >= 0xa000 && seg < 0xe000)
        memoryVideoSet16(seg, ofs, val);
    else
        memoryBiosSet16(seg, ofs, val);
}

uint8_t& cicocontext_t::memory8(int seg, int ofs){
    if (seg*16+ofs == 0x10000 + 0x4093)
    {
        int f = 9;//(0x1ed, 0x387+0x1)
    }
    if (seg*16+ofs == 0x10000+0x112 ||seg*16+ofs == 0x10000+0x113 )
    {
        int f = 9;
    }

    assert(seg >= loadAddress && seg < 0xa000 && ofs >= 0 && ofs <= 0xffff);
    int addr = seg*16 + ofs;
    addr -= loadAddress*16 - headerSize;
    assert(addr > 0 && addr < sizeof(mem));
    return mem[addr];
}

uint16_t& cicocontext_t::memory16(int seg, int ofs){
    if (seg*16+ofs == 0x10000 + 0x4093 || seg*16+ofs == 0x10000 + 0x4094)
    {
        int f = 9;
    }
    assert(seg >= loadAddress && seg < 0xa000 && ofs >= 0 && ofs <= 0xffff);
    int addr = seg*16 + ofs;
    addr -= loadAddress*16 - headerSize;
    assert(addr > 0 && addr < sizeof(mem));
    return *(uint16_t*)&mem[addr];
}

uint8_t cicocontext_t::memoryVideoGet8(int seg, int ofs)
{
    return mVideo->Read(seg*16+ofs);
}

void cicocontext_t::memoryVideoSet8(int seg, int ofs, uint8_t data)
{
    mVideo->Write(seg*16+ofs, data);
}

uint16_t cicocontext_t::memoryVideoGet16(int seg, int ofs)
{
    return memoryVideoGet8(seg, ofs) | (memoryVideoGet8(seg, ofs+1) << 8);
}

void cicocontext_t::memoryVideoSet16(int seg, int ofs, uint16_t data)
{
    memoryVideoSet8(seg, ofs, data & 0xff);
    memoryVideoSet8(seg, ofs+1, data >> 8);
}

void cicocontext_t::_int(int i)
{
    static FILE* f = nullptr;
    static int curhandle = 5;
    if (i == 0x10 && ctx->a.r16 == 0x1012)
    {
        int f = 9;
    }
    if (i == 0x12)
    {
        ctx->a.r16 = 0x800;
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x09)
    {
        for(int i=0; i<200; i++)
        {
            char c = ctx->memory8(ctx->_ds, ctx->d.r16+i);
            assert(c);
            if (c == '$')
            {
                fflush(stdout);
                return;
            }
            printf("%c", c);
        }
        assert(0);
    }

    if (i == 0x21 && ctx->a.r8.h == 0x3d)
    {
        // read file DS:DX filename
        // AX = file handle
        char filename[100];
        int j = 0;
        for (int i=0; i<100; i++)
        {
            char c = ctx->memory8(ctx->_ds, ctx->d.r16+i);
            if (!c)
                break;
            if (c >= 'a' && c <= 'z')
                c -= 'a' - 'A';
            if (c != ' ')
            {
                filename[j++] = c;
                filename[j] = 0;
            }
        }
        //curhandle++;
        printf("Opening %s as %x\n", filename, curhandle);
        //char fullname[128] = "/Users/gabrielvalky/Documents/git/Projects/XenonResurrection/Input/binary/";
        char fullname[1024];
        strcpy(fullname, root);
        strcat(fullname, "/");
        strcat(fullname, filename);
        for (int i=0; i<128 && fullname[i]; i++)
            if (fullname[i] == '\\')
                fullname[i] = '/';
        
        ctx->carry = 0;
        assert(f == nullptr);
        ctx->a.r16 = curhandle;
        
        f = fopen(fullname, "rb");
        if(!f)
        {
            printf("Not found: %s\n", filename);
//            assert(0);
            ctx->carry = 1;
            ctx->a.r16 = 0;
        }
        return;

    }
    if (i == 0x21 && ctx->a.r8.h == 0x3f)
    {
        // read file CX bytes => CS:DX
        assert(ctx->b.r16 == curhandle);
        if (!f)
        {
            printf("no file opened!\n");
            return;
        } else {
            printf("Read %d bytes -> %04x:%04x\n", ctx->c.r16, ctx->_ds, ctx->d.r16);
            uint8_t* buf = new uint8_t[ctx->c.r16];
            int c = fread(buf, 1, (size_t)ctx->c.r16, f);
            if (ctx->_ds >= 0xa000)
            {
                const int bittoshift[] = {0, 1, 2, 0, 3, 0, 0, 0, 4};
                //printf("cfg=%d\n", mEga.cfgDataRotate);
                int a =mEga.cfgMapMask;
                int b =mEga.cfgReadMapSelect;
                int shift = (bittoshift[mEga.cfgMapMask]-1)*8;
//                int shift = (mEga.cfgReadMapSelect*8);
                uint32_t mask = ~(0xff << shift);
                for (int i=0; i<c; i++)
                    mEga.egamemory[ctx->d.r16+i] &= mask;
                for (int i=0; i<c; i++)
                    mEga.egamemory[ctx->d.r16+i] |= buf[i]<<shift;
                //ctx->memoryASet8(ctx->_ds+overlap, (ctx->d.r16+i)&65535, buf[i]);
            } else {
                for (int i=0; i<c; i++)
                {
                    // memory overlap!
                    int overlap = ((ctx->d.r16+i) >> 16) ? 0x1000 : 0;
                    ctx->memoryASet8(ctx->_ds+overlap, (ctx->d.r16+i)&65535, buf[i]);
                }
            }
            delete[] buf;
            //std::cout << "read " << _cx << " (" << c << ")" << endl;
//            assert(c);
            ctx->a.r16 = c;
            ctx->carry = 0;
            return;
        }
    }
    if (i == 0x21 && ctx->a.r8.h == 0x3e)
    {
        printf("Closing file %x!\n", ctx->b.r16);
        fclose(f);
        f = nullptr;
        ctx->carry = 0;
        return;
    }
    static int _videoMode = -1;
    if (i == 0x10 && ctx->a.r8.h == 0x00)
    {
        // set video mode
        printf("Set video mode: %x\n", ctx->a.r8.l);
        _videoMode = ctx->a.r8.l;
        switch (ctx->a.r8.l)
        {
            case 0x13:
                mVideo = &mVga; break;
            case 13:
            case 0x12:
            case 0x10:
            case 0x02: // 80x25 16 shades of gray text (CGA,EGA,MCGA,VGA)?

            case 1:
                mVideo = &mEga; break;
            case 4:
            case 5:
                mVideo = &mCga; break;
            case 3: // exit
                mVideo = &mText;
                break;
            default:
                assert(0);
        }
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x25)
    {
        // set int vect AL DS:DX
        printf("Set int vector - ignore al=%02x to %04x:%04x\n", ctx->a.r8.l, ctx->_ds, ctx->d.r16);
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x35)
    {
        printf("Get int vector - ignore\n");
        ctx->_es = 0;
        ctx->b.r16 = 0;
        
        ctx->b.r16 = 0x1060;
        ctx->_es = 0xf000;
        return;
    }
    if (i == 0x33 && ctx->a.r8.h == 0)
    {
        // mouse
        ctx->a.r16 = 0;
//        ctx->a.r16 = -1;
//        ctx->b.r16 = 3;
        return;
    }
    if (i == 0x33 && ctx->a.r8.h == 0x03)
    {
        // mouse
        ctx->b.r16 = 0;
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x3c)
    {
        // create file
        ctx->carry = true;
        return;
    }
    //static int lastKey = -1;
    if (i == 0x16 && ctx->a.r8.h == 0x00)
    {
        while (lastKey == -1)
            sync();
            
        // wait for keystroke!
        ctx->a.r16 = lastKey;
        lastKey = -1;
        return;
    }
    if (i == 0x16 && ctx->a.r8.h == 0x01)
    {
        ctx->zero = lastKey == -1;
        return;
    }
    if (i == 0x16 && ctx->a.r8.h == 0x02)
        return;
    if (i == 0x10 && ctx->a.r8.h == 0x06)
        return;
    if (i == 0x21 && ctx->a.r8.h == 0x4a)
    {
        ctx->carry = false;
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x48)
    {
        //static int freeMem = 0x1D9E; // TODO:!!!!
        static int freeMem = 0x2000;
        // _bx size
        printf("malloc %d bytes -> %04x:0000\n", ctx->b.r16, freeMem);
        ctx->a.r16 = freeMem;
        freeMem += ctx->b.r16;
        freeMem ++;
        ctx->carry = false;
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x40)
    {
        for (int j=0; j<ctx->c.r16; j++)
            printf("%c", ctx->memory8(ctx->_ds, ctx->d.r16 + j));
        ctx->carry = false;
        ctx->a.r16 = ctx->c.r16;
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x3e)
        return;
    if (i == 0x21 && ctx->a.r8.h == 0x49)
        return;
    if (i == 0x21 && ctx->a.r8.h == 0x0a)
    {
        memory8(ctx->_ds, ctx->d.r16) = 'n';
        return;
    }
    if (i == 0x10 && ctx->a.r8.h == 0x0f)
    {
        if (_videoMode==-1)
        {
            ctx->a.r16 = 0x5003;
            ctx->b.r8.h = 0x00;
            return;
        }
        if (_videoMode==0x12)
        {
            ctx->a.r16 = 0x5012;
            ctx->b.r8.h = 0x00;
            return;
        }
        if (_videoMode==0x13)
        {
            ctx->a.r16 = 0x2813;
            ctx->b.r8.h = 0x00;
            return;
        }
        if (_videoMode==0x10)
        {
            ctx->a.r16 = 0x5010;
            ctx->b.r8.h = 0x00;
            return;
        }
        if (_videoMode==0x4)
        {
            ctx->a.r16 = 0x2804;
            ctx->b.r8.h = 0x00;
            return;
        }
        if (_videoMode==0xd)
        {
            ctx->a.r16 = 0x280d;
            ctx->b.r8.h = 0x00;
            return;
        }
        assert(0);
    }
    if (i == 0x10 && ctx->a.r8.h == 0x1a)
    {
        //https://dos4gw.org/INT_10H_1aH_Set_or_Query_Display_Combination_Code
        ctx->a.r8.l = 0x1a;
        ctx->b.r8.l = 0x08; // vga color
        return;
        
    }
    if (i == 0x10 && ctx->a.r8.h == 0x10 && ctx->a.r8.l == 0)
    {
        //cout << hex << "\nset text palette[" << (int)_bl << "] = " << (int)_bh << endl;
        printf("palette [%x] <- %x\n", ctx->b.r8.l, ctx->b.r8.h);
        mEga.SetPaletteIndex(ctx->b.r8.l, ctx->b.r8.h);
        return;
    }
    if (i == 0x10 && ctx->a.r16 == 0x1012)
    {
        mEga.Interrupt(ctx);
        return;
    }
    if (i == 0x10 && ctx->a.r16 == 0x1200 && ctx->b.r8.l == 0x10)
    {
        ctx->b.r16 = 0x0003;
        return;
    }
    if (i == 0x10 && ctx->a.r8.h == 0x0e)
    {
        printf("%c", ctx->a.r8.l);
        fflush(stdout);
        return;
    }
    if (i == 0x10 && mVideo)
    {
        if (mVideo->Interrupt(ctx))
            return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x2c)
    {
        printf("get time\n");
        ctx->c.r8.h = 1; // hr
        ctx->c.r8.l = 20; // min
        ctx->d.r8.h = 17; // sec
        ctx->d.r8.l = 50; // hundredths
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x44)
    {
        ctx->a.r16 = 2; //ctx->a.r16 = 0x80d3;
        ctx->d.r16 = 2; //ctx->d.r16 = 0x80d3;
        ctx->carry = 0;
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x30)
    {
        ctx->a.r16 = 0x0005;
        ctx->b.r16 = 0xff00;
        ctx->c.r16 = 0x0000;
        return;
    }
    if (i == 0x1A)
    {
        auto getTick = []() -> uint32_t {
            struct timespec ts;
            unsigned theTick = 0U;
            clock_gettime( CLOCK_REALTIME, &ts );
            theTick  = ts.tv_nsec / 1000000;
            theTick += ts.tv_sec * 1000;
            return theTick;
        };

        static uint32_t base = 0;
        int now = getTick();
        if (ctx->a.r8.h == 4)
        {
            
        }
        else if (ctx->a.r8.h == 0)
        {
            if (base == 0)
                base = now;
            now -= base;
            now = now /6 /10; // + temp; //* 65536 / (1000*60*60);  gabo!!
            ctx->c.r16 = now >> 16;
            ctx->d.r16 = now & 0xffff;
        } else {
            assert(ctx->a.r8.h == 1 && ctx->c.r16 == 0 && ctx->d.r16 == 0);
            base = now;
        }
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x42)
    {
        if (ctx->a.r8.l == 2 && ctx->c.r16 == 0 && ctx->d.r16 == 0)
        {
            assert(f);
            fseek(f, 0L, SEEK_END);
            ctx->a.r16 = ftell(f);
            fseek(f, 0L, SEEK_SET);
            ctx->d.r16 = 0;
            return;
        }
        if (ctx->a.r8.l == 0)
        {
            assert(f);
            fseek(f, ctx->c.r16*0x10000 + ctx->d.r16, SEEK_SET);
            ctx->carry = false;
            return;
        }

    }
    if (i == 0x21 && ctx->a.r8.h == 0x0b)
    {
        ctx->a.r8.l = keyBuffer.empty() ? 0 : 0xff; // check key
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x07)
    {
        ctx->a.r8.l = keyBuffer.front(); // key stdin
        keyBuffer.pop_front();
        return;
    }
    if (i == 0x11)
    {
        ctx->a.r16 = 0;
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x42)
    {
        if (ctx->a.r8.l == 2 && ctx->c.r16 == 0 && ctx->d.r16 == 0)
        {
            assert(f);
            fseek(f, 0L, SEEK_END);
            ctx->a.r16 = ftell(f);
            fseek(f, 0L, SEEK_SET);
            ctx->d.r16 = 0;
            return;
        }
        if (ctx->a.r8.l == 1)
        {
            assert(ctx->c.r16 == 0);
            assert(f);
            fseek(f, ctx->d.r16, SEEK_CUR);
            ctx->d.r16 = ftell(f);
            ctx->a.r16 = 0;
            return;
        }
        if (ctx->a.r8.l == 1 && ctx->d.r16 == 0)
        {
            assert(f);
            fseek(f, ctx->c.r16, SEEK_CUR);
            return;
        }
        /*
        if (ctx->a.r8.l == 0)
        {
            assert(f);
            fseek(f, ctx->d.r16, SEEK_SET);
            return;
        }*/

    }
    if (i == 0x21 && ctx->a.r8.h == 0x19)
    {
        ctx->a.r8.l = 0x02;
        return;
    }
    if (i == 0x15 && ctx->a.r8.h == 0x06)
    {
        //wtf?
        return;
    }
    if (i == 0x21 && ctx->a.r8.h == 0x43)
    {
        // read file DS:DX filename
        // AX = file handle
        char filename[100];
        for (int i=0; i<100; i++)
        {
            char c = ctx->memory8(ctx->_ds, ctx->d.r16+i);
            if (!c)
                break;
            if (c >= 'a' && c <= 'z')
                c -= 'a' - 'A';
            filename[i] = c;
            filename[i+1] = 0;
        }
        printf("GetAttribute %s\n", filename);
        ctx->c.r16 = 1<<5;
        return;
    }

    if (i == 0x10 && ctx->a.r16 == 0x1015)
    {
        // read dac @ bx, ch, cl, dh
        return;
    }
    if (i == 0x21  && ctx->a.r8.h == 0x4c)
    {
        printf("Terminate app\n");
        exit(0);
    }
    if (i == 0x80)
    {
        return;
    }
    printf("int %d\n", i);
    assert(0);
}
void cicocontext_t::out(int port, uint16_t val)
{
//    printf("port16 write %x = %x\n", port, val);
    if (mVideo->PortWrite16(port, val))
    {
        return;
    }
    printf("skip write %x, %x\n", port, val);
}
void cicocontext_t::out(int port, uint8_t val)
{
//    printf("port8 write %x = %x\n", port, val);

    if (port == 0x3c8)
    {
        int f = 9;
    }
    if (mVideo->PortWrite8(port, val))
        return;
    // titus uses for checking vga support
//    if (mVga.PortWrite8(port, val))
//        return;
    printf("skip write %x, %x\n", port, val);
    
//    if (port == 0x201 || port == 0x388 || port == 0x389)
//        return;
//    assert(0);
}

void cicocontext_t::in(uint8_t& val, int port)
{
    if (port == 0x3da)
    {
        static int retrace = 0;
        retrace++;
        val = (retrace & 1) ? 9 : 0;
        return;
    }
    if (port == 0x201)
    {
//        printf("joystick skip\n");
        val = 0;
        return;
    }
    if (port == 0x61)
    {
        printf("timer skip\n");
        return;
    }
    if (port == 0x3c9)
    {
        if (mVideo->PortRead8(port, val))
            return;
    }
    if (port == 0x388) //audio
    {
        val = 0x60;
        return;
    }
    if (port == 0x3b5) //mono
    {
        val = 0xff;
        return;
    }
    if (port == 0x301)
    {
        val = 0xff;
        //?
        return;
    }
    if (port == 0x331)
    {
        val = 0xbf;
        //?
        return;
    }
    if (port == 0x40)
    {
        static int counter = 0;
        val = (counter++ & 2) ? 0xff:0x00;
        return;
    }

    if (port == 0x3d4 || port == 0x3d5)
    {
        if (mVideo->PortRead8(port, val))
            return;
    }

    assert(0);
}

void cicocontext_t::push(const uint16_t& r)
{
    assert (ctx->_sp > 10);
    ctx->_sp -= 2;
    memory16(ctx->_ss, ctx->_sp) = r;
    assert(ctx->_sp > 0);
}
int checksp = -1;
uint16_t cicocontext_t::pop(void)
{
    assert(ctx->_sp <= 0xffff);
    uint16_t aux = memory16(ctx->_ss, ctx->_sp);
    if (checksp)
    {
        if (aux == checksp)
        {
            int f = 9;
        }
        
    }
    ctx->_sp += 2;
    return aux;
}
void cicocontext_t::push(const int& r)
{
    assert(r >= 0 && r <= 0xffff);
    ctx->_sp -= 2;
    memory16(ctx->_ss, ctx->_sp) = r;
}
//void cicocontext_t::pop(int& r)
//{
//    ctx->_sp += 2;
//    r = memory16(ctx->_ss, ctx->_sp);
//}
bool cicocontext_t::stop(const char* msg)
{
    assert(0);
    return false;
}

void cicocontext_t::cbw()
{
    ctx->a.r8.h = (ctx->a.r8.l & 0x80) ? 0xff : 0;
}
void cicocontext_t::div(uint16_t r)
{
    uint16_t result = ctx->a.r16 / r;
    uint16_t remain = ctx->a.r16 % r;
    ctx->a.r16 = result;
    ctx->d.r16 = remain;
}
void cicocontext_t::div(uint8_t r)
{
    uint16_t result = ctx->a.r16 / r;
    uint16_t remain = ctx->a.r16 % r;
    ctx->a.r8.l = result;
    ctx->d.r8.h = remain;
}
}

void sub_bb32();
void sub_c91e();
void sub_df4f();
void sub_fb7f();
void sub_c27e();
void sub_f9c4();
void sub_e600();
void sub_e2e4();
void sub_ca60();
void sub_ca8b();
void sub_12245();
void sub_d016();
void sub_d080();
void sub_d0d7();
void sub_d500();
void sub_d530();
void sub_d250();
void sub_d283();
void sub_dac0();
void sub_dae7();
void sub_fbb9();
void sub_fdcd();
void sub_e067();
void sub_fe71();
void sub_d810();
void sub_d840();
void sub_d593();
void sub_8fe1();
void sub_85e7();
void sub_841e();
void sub_8457();
void sub_84cb();
void sub_47c9();
void sub_4286();
void sub_42f3();
void sub_4340();
void sub_435e();
void sub_8518();
void sub_85a8();
void sub_8242();
void sub_8405();
void sub_84b5();
void sub_84f7();
void sub_8569();
void sub_84e1();
void sub_81f6();
void sub_83ec();
void sub_81f6();

void sub_860a();
void sub_83b2();
void sub_83cf();
void sub_3d0d();
void sub_834e();
void sub_8659();
void sub_8618();
void sub_84a2();
void sub_880a();
void sub_82dc();
void sub_87ce();


void sub_d37f();
void sub_d65d();
void sub_d665();
void sub_4191();
void sub_4180();
void sub_81d5();
void sub_447d();
void sub_6c8f();
void sub_6f29();
void sub_6d99();
void sub_6e1e();
void sub_6f3f();
void sub_41a2();
void sub_6ef5();
void sub_6f0f();
void sub_6d14();
void sub_3d2e();
void sub_8391();
void sub_86e3();
void sub_40b7();
void sub_86cb();
void sub_46e0();
void sub_3d60();
void sub_6214();
void sub_6307();
void sub_43a7();
void sub_86b2();
void sub_4008();
void sub_8702();
void sub_871b();
void sub_87b6();
void sub_87f2();
void sub_8760();
void sub_878b();
void sub_832d();
void sub_869a();
void sub_43da();

void sub_3d92();
void sub_3e0e();
/*
 // 11d7a-11dfa, 80 b, 40 w
 {
     bool tmp[65536] = {0};
     for (int i=0; i<40; i++)
     {
         int adr =memoryAGet16(ds, 1994+i*2);
         if (tmp[adr])
             continue;
         tmp[adr] =1;
         printf("case 0x%x: sub_%x(); break; // %04x:%04x\n",
                cs*16+adr, cs*16+adr, cs, adr);
     }
 }
 printf("%02x %02x %02x %02x  %02x %02x %02x %02x\n",
        memoryAGet(ds, 1994), memoryAGet(ds, 1994+1),
        memoryAGet(ds, 1994+2), memoryAGet(ds, 1994+3),
        memoryAGet(ds, 1994+4), memoryAGet(ds, 1994+5),
        memoryAGet(ds, 1994+6), memoryAGet(ds, 1994+7));

 */


void CicoContext::cicocontext_t::cmc()
{
    ctx->carry = !ctx->carry;
}
void CicoContext::cicocontext_t::aaa()
{
    if ((ctx->a.r8.l & 0x0F) > 9 /*|| (r8[af] = 1)*/)
    {
        ctx->a.r8.l = (ctx->a.r8.l + 6) & 0x0f;
        ctx->a.r8.h ++;
        //af = 1;
        ctx->carry = 1;
    } else {
        ctx->carry = 0;
        //af = 0;
    }
}
void CicoContext::cicocontext_t::das()
{
    // TODO: set carry before!
    //https://www.felixcloutier.com/x86/das
    int oldal = ctx->a.r8.l;
    int oldcf = ctx->carry;
    int af = 0;
    if ((ctx->a.r8.l & 0x0f) > 9 || af == 1)
    {
        ctx->a.r8.l -= 6;
        ctx->carry = false;
    } else
        af = 0;
    
    if (oldal > 0x99 || oldcf)
    {
        ctx->a.r8.l -= 0x60;
        ctx->carry = true;
    }
}
void CicoContext::cicocontext_t::daa()
{
    // TODO: set carry before!

}
namespace CicoContext {
void cicocontext_t::mul(uint8_t r)
{
    int v = r * ctx->a.r8.l; // GABO PROBLEM MUL alley cat r8.l, else r16
    ctx->a.r16 = v & 0xffff;
}
void cicocontext_t::mul(uint16_t r)
{
    int v = r * ctx->a.r16;
    ctx->a.r16 = v & 0xffff;
    ctx->d.r16 = v >> 16;
}
void cicocontext_t::imul(uint16_t r)
{
    int v = (int16_t)ctx->a.r16 * (int16_t)r;
    ctx->a.r16 = v & 0xffff;
    ctx->d.r16 = v >> 16;
}
void cicocontext_t::imul(uint8_t r)
{
    int v = (char)r * (short)ctx->a.r16;
    ctx->a.r16 = v & 0xffff;
}
void cicocontext_t::idiv(uint16_t r)
{
    int32_t n = (ctx->d.r16 << 16) | ctx->a.r16;
    ctx->a.r16 = n / (int16_t)r;
    ctx->d.r16 = n % (int16_t)r;
}
void cicocontext_t::idiv(uint8_t r)
{
    int32_t dw = (ctx->d.r16 << 16) | ctx->a.r16;
    uint16_t result = dw / r;
    uint16_t remainder = dw % r;
    ctx->a.r16 = result;
    ctx->d.r16 = remainder;
}

uint8_t cicocontext_t::rcr(uint8_t r, int i)
{
    assert(i == 1);
    int newCarry = !!(r & 0x1);
    r >>= 1;
    r |= ctx->carry ? 0x80 : 0;
    ctx->carry = newCarry;
    return r;
}
uint8_t cicocontext_t::rcl(uint8_t r, int i)
{
    assert(i == 1);
    int newCarry = !!(r & 0x80);
    r <<= 1;
    r |= ctx->carry;
    ctx->carry = newCarry;
    return r;
}
uint16_t cicocontext_t::rcl(uint16_t r, int i)
{
    while (i > 0)
    {
        int newCarry = !!(r & 0x8000);
        r <<= 1;
        r |= ctx->carry ? 0x0001 : 0x0000;
        ctx->carry = newCarry;
        i--;
    }
    return r;
}
uint16_t cicocontext_t::rcr(uint16_t r, int i)
{
    while (i > 0)
    {
        int newCarry = !!(r & 0x0001);
        r >>= 1;
        r |= ctx->carry ? 0x8000 : 0x0000;
        ctx->carry = newCarry;
        i--;
    }
    return r;
}
template <typename INT>
INT _rol(INT val) {
    return (val << 1) | (val >> (sizeof(INT)*CHAR_BIT-1));
}

uint8_t cicocontext_t::rol(uint8_t r, int l)
{
    while (l--)
        r = _rol<uint8_t>(r);
    return r;
}
uint16_t cicocontext_t::rol(uint16_t r, int l)
{
    while (l--)
        r = _rol<uint16_t>(r);
    return r;
}
uint16_t cicocontext_t::sar(uint16_t a, uint8_t b)
{
    int16_t sa = (short)a;
    sa >>= b;
    return sa;
}
uint8_t cicocontext_t::sar(uint8_t a, uint8_t b)
{
    int8_t sa = (char)a;
    sa >>= b;
    return sa;
}

uint8_t cicocontext_t::ror(uint8_t r, int l)
{
    return (r >> l) | (r << (8-l));
}
uint16_t cicocontext_t::ror(uint16_t r, int l)
{
    return (r >> l) | (r << (16-l));
}
void cicocontext_t::sync(void)
{
//    memory16(0x1f86, 0x8dd8)++;
//    memory16(0x1000, 0x35e2)++;
    _sync();
}
void cicocontext_t::load(const char* path, const char* file, int size)
{
    char fpath[1024];
    sprintf(root, path);
    sprintf(fpath, "%s/%s", path, file);
    FILE* f = fopen(fpath, "rb");
    fread(mem, size, 1, f);
    fclose(f);
    headerSize = this->_headerSize;
    loadAddress = this->_loadAddress; // - 0x0130; //CicoContext::ctx->_cs;
}

}
void start();
int main(int argc, const char * argv[])
{
    CicoContext::ctx = new CicoContext::cicocontext_t();

    memset(mem, 0, sizeof(mem));

    mSdl.Init();
    start();
    mSdl.Deinit();
    return 0;
}


//#include "goose.cpp"


unsigned char font[2048] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x81, 0xa5, 0x81,
  0xbd, 0x99, 0x81, 0x7e, 0x7e, 0xff, 0xdb, 0xff, 0xc3, 0xe7, 0xff, 0x7e,
  0x6c, 0xfe, 0xfe, 0xfe, 0x7c, 0x38, 0x10, 0x00, 0x10, 0x38, 0x7c, 0xfe,
  0x7c, 0x38, 0x10, 0x00, 0x38, 0x7c, 0x38, 0xfe, 0xfe, 0x7c, 0x38, 0x7c,
  0x10, 0x10, 0x38, 0x7c, 0xfe, 0x7c, 0x38, 0x7c, 0x00, 0x00, 0x18, 0x3c,
  0x3c, 0x18, 0x00, 0x00, 0xff, 0xff, 0xe7, 0xc3, 0xc3, 0xe7, 0xff, 0xff,
  0x00, 0x3c, 0x66, 0x42, 0x42, 0x66, 0x3c, 0x00, 0xff, 0xc3, 0x99, 0xbd,
  0xbd, 0x99, 0xc3, 0xff, 0x0f, 0x07, 0x0f, 0x7d, 0xcc, 0xcc, 0xcc, 0x78,
  0x3c, 0x66, 0x66, 0x66, 0x3c, 0x18, 0x7e, 0x18, 0x3f, 0x33, 0x3f, 0x30,
  0x30, 0x70, 0xf0, 0xe0, 0x7f, 0x63, 0x7f, 0x63, 0x63, 0x67, 0xe6, 0xc0,
  0x99, 0x5a, 0x3c, 0xe7, 0xe7, 0x3c, 0x5a, 0x99, 0x80, 0xe0, 0xf8, 0xfe,
  0xf8, 0xe0, 0x80, 0x00, 0x02, 0x0e, 0x3e, 0xfe, 0x3e, 0x0e, 0x02, 0x00,
  0x18, 0x3c, 0x7e, 0x18, 0x18, 0x7e, 0x3c, 0x18, 0x66, 0x66, 0x66, 0x66,
  0x66, 0x00, 0x66, 0x00, 0x7f, 0xdb, 0xdb, 0x7b, 0x1b, 0x1b, 0x1b, 0x00,
  0x3e, 0x63, 0x38, 0x6c, 0x6c, 0x38, 0xcc, 0x78, 0x00, 0x00, 0x00, 0x00,
  0x7e, 0x7e, 0x7e, 0x00, 0x18, 0x3c, 0x7e, 0x18, 0x7e, 0x3c, 0x18, 0xff,
  0x18, 0x3c, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x18,
  0x7e, 0x3c, 0x18, 0x00, 0x00, 0x18, 0x0c, 0xfe, 0x0c, 0x18, 0x00, 0x00,
  0x00, 0x30, 0x60, 0xfe, 0x60, 0x30, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0,
  0xc0, 0xfe, 0x00, 0x00, 0x00, 0x24, 0x66, 0xff, 0x66, 0x24, 0x00, 0x00,
  0x00, 0x18, 0x3c, 0x7e, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7e,
  0x3c, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x30, 0x78, 0x78, 0x30, 0x30, 0x00, 0x30, 0x00, 0x6c, 0x6c, 0x6c, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x6c, 0x6c, 0xfe, 0x6c, 0xfe, 0x6c, 0x6c, 0x00,
  0x30, 0x7c, 0xc0, 0x78, 0x0c, 0xf8, 0x30, 0x00, 0x00, 0xc6, 0xcc, 0x18,
  0x30, 0x66, 0xc6, 0x00, 0x38, 0x6c, 0x38, 0x76, 0xdc, 0xcc, 0x76, 0x00,
  0x60, 0x60, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x30, 0x60, 0x60,
  0x60, 0x30, 0x18, 0x00, 0x60, 0x30, 0x18, 0x18, 0x18, 0x30, 0x60, 0x00,
  0x00, 0x66, 0x3c, 0xff, 0x3c, 0x66, 0x00, 0x00, 0x00, 0x30, 0x30, 0xfc,
  0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x60,
  0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x30, 0x30, 0x00, 0x06, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0x80, 0x00,
  0x7c, 0xc6, 0xce, 0xde, 0xf6, 0xe6, 0x7c, 0x00, 0x30, 0x70, 0x30, 0x30,
  0x30, 0x30, 0xfc, 0x00, 0x78, 0xcc, 0x0c, 0x38, 0x60, 0xcc, 0xfc, 0x00,
  0x78, 0xcc, 0x0c, 0x38, 0x0c, 0xcc, 0x78, 0x00, 0x1c, 0x3c, 0x6c, 0xcc,
  0xfe, 0x0c, 0x1e, 0x00, 0xfc, 0xc0, 0xf8, 0x0c, 0x0c, 0xcc, 0x78, 0x00,
  0x38, 0x60, 0xc0, 0xf8, 0xcc, 0xcc, 0x78, 0x00, 0xfc, 0xcc, 0x0c, 0x18,
  0x30, 0x30, 0x30, 0x00, 0x78, 0xcc, 0xcc, 0x78, 0xcc, 0xcc, 0x78, 0x00,
  0x78, 0xcc, 0xcc, 0x7c, 0x0c, 0x18, 0x70, 0x00, 0x00, 0x30, 0x30, 0x00,
  0x00, 0x30, 0x30, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x30, 0x30, 0x60,
  0x18, 0x30, 0x60, 0xc0, 0x60, 0x30, 0x18, 0x00, 0x00, 0x00, 0xfc, 0x00,
  0x00, 0xfc, 0x00, 0x00, 0x60, 0x30, 0x18, 0x0c, 0x18, 0x30, 0x60, 0x00,
  0x78, 0xcc, 0x0c, 0x18, 0x30, 0x00, 0x30, 0x00, 0x7c, 0xc6, 0xde, 0xde,
  0xde, 0xc0, 0x78, 0x00, 0x30, 0x78, 0xcc, 0xcc, 0xfc, 0xcc, 0xcc, 0x00,
  0xfc, 0x66, 0x66, 0x7c, 0x66, 0x66, 0xfc, 0x00, 0x3c, 0x66, 0xc0, 0xc0,
  0xc0, 0x66, 0x3c, 0x00, 0xf8, 0x6c, 0x66, 0x66, 0x66, 0x6c, 0xf8, 0x00,
  0xfe, 0x62, 0x68, 0x78, 0x68, 0x62, 0xfe, 0x00, 0xfe, 0x62, 0x68, 0x78,
  0x68, 0x60, 0xf0, 0x00, 0x3c, 0x66, 0xc0, 0xc0, 0xce, 0x66, 0x3e, 0x00,
  0xcc, 0xcc, 0xcc, 0xfc, 0xcc, 0xcc, 0xcc, 0x00, 0x78, 0x30, 0x30, 0x30,
  0x30, 0x30, 0x78, 0x00, 0x1e, 0x0c, 0x0c, 0x0c, 0xcc, 0xcc, 0x78, 0x00,
  0xe6, 0x66, 0x6c, 0x78, 0x6c, 0x66, 0xe6, 0x00, 0xf0, 0x60, 0x60, 0x60,
  0x62, 0x66, 0xfe, 0x00, 0xc6, 0xee, 0xfe, 0xfe, 0xd6, 0xc6, 0xc6, 0x00,
  0xc6, 0xe6, 0xf6, 0xde, 0xce, 0xc6, 0xc6, 0x00, 0x38, 0x6c, 0xc6, 0xc6,
  0xc6, 0x6c, 0x38, 0x00, 0xfc, 0x66, 0x66, 0x7c, 0x60, 0x60, 0xf0, 0x00,
  0x78, 0xcc, 0xcc, 0xcc, 0xdc, 0x78, 0x1c, 0x00, 0xfc, 0x66, 0x66, 0x7c,
  0x6c, 0x66, 0xe6, 0x00, 0x78, 0xcc, 0xe0, 0x70, 0x1c, 0xcc, 0x78, 0x00,
  0xfc, 0xb4, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00, 0xcc, 0xcc, 0xcc, 0xcc,
  0xcc, 0xcc, 0xfc, 0x00, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0x78, 0x30, 0x00,
  0xc6, 0xc6, 0xc6, 0xd6, 0xfe, 0xee, 0xc6, 0x00, 0xc6, 0xc6, 0x6c, 0x38,
  0x38, 0x6c, 0xc6, 0x00, 0xcc, 0xcc, 0xcc, 0x78, 0x30, 0x30, 0x78, 0x00,
  0xfe, 0xc6, 0x8c, 0x18, 0x32, 0x66, 0xfe, 0x00, 0x78, 0x60, 0x60, 0x60,
  0x60, 0x60, 0x78, 0x00, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x02, 0x00,
  0x78, 0x18, 0x18, 0x18, 0x18, 0x18, 0x78, 0x00, 0x10, 0x38, 0x6c, 0xc6,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
  0x30, 0x30, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x0c,
  0x7c, 0xcc, 0x76, 0x00, 0xe0, 0x60, 0x60, 0x7c, 0x66, 0x66, 0xdc, 0x00,
  0x00, 0x00, 0x78, 0xcc, 0xc0, 0xcc, 0x78, 0x00, 0x1c, 0x0c, 0x0c, 0x7c,
  0xcc, 0xcc, 0x76, 0x00, 0x00, 0x00, 0x78, 0xcc, 0xfc, 0xc0, 0x78, 0x00,
  0x38, 0x6c, 0x60, 0xf0, 0x60, 0x60, 0xf0, 0x00, 0x00, 0x00, 0x76, 0xcc,
  0xcc, 0x7c, 0x0c, 0xf8, 0xe0, 0x60, 0x6c, 0x76, 0x66, 0x66, 0xe6, 0x00,
  0x30, 0x00, 0x70, 0x30, 0x30, 0x30, 0x78, 0x00, 0x0c, 0x00, 0x0c, 0x0c,
  0x0c, 0xcc, 0xcc, 0x78, 0xe0, 0x60, 0x66, 0x6c, 0x78, 0x6c, 0xe6, 0x00,
  0x70, 0x30, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00, 0x00, 0x00, 0xcc, 0xfe,
  0xfe, 0xd6, 0xc6, 0x00, 0x00, 0x00, 0xf8, 0xcc, 0xcc, 0xcc, 0xcc, 0x00,
  0x00, 0x00, 0x78, 0xcc, 0xcc, 0xcc, 0x78, 0x00, 0x00, 0x00, 0xdc, 0x66,
  0x66, 0x7c, 0x60, 0xf0, 0x00, 0x00, 0x76, 0xcc, 0xcc, 0x7c, 0x0c, 0x1e,
  0x00, 0x00, 0xdc, 0x76, 0x66, 0x60, 0xf0, 0x00, 0x00, 0x00, 0x7c, 0xc0,
  0x78, 0x0c, 0xf8, 0x00, 0x10, 0x30, 0x7c, 0x30, 0x30, 0x34, 0x18, 0x00,
  0x00, 0x00, 0xcc, 0xcc, 0xcc, 0xcc, 0x76, 0x00, 0x00, 0x00, 0xcc, 0xcc,
  0xcc, 0x78, 0x30, 0x00, 0x00, 0x00, 0xc6, 0xd6, 0xfe, 0xfe, 0x6c, 0x00,
  0x00, 0x00, 0xc6, 0x6c, 0x38, 0x6c, 0xc6, 0x00, 0x00, 0x00, 0xcc, 0xcc,
  0xcc, 0x7c, 0x0c, 0xf8, 0x00, 0x00, 0xfc, 0x98, 0x30, 0x64, 0xfc, 0x00,
  0x1c, 0x30, 0x30, 0xe0, 0x30, 0x30, 0x1c, 0x00, 0x18, 0x18, 0x18, 0x00,
  0x18, 0x18, 0x18, 0x00, 0xe0, 0x30, 0x30, 0x1c, 0x30, 0x30, 0xe0, 0x00,
  0x76, 0xdc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x6c,
  0xc6, 0xc6, 0xfe, 0x00, 0x78, 0xcc, 0xc0, 0xcc, 0x78, 0x18, 0x0c, 0x78,
  0x00, 0xcc, 0x00, 0xcc, 0xcc, 0xcc, 0x7e, 0x00, 0x1c, 0x00, 0x78, 0xcc,
  0xfc, 0xc0, 0x78, 0x00, 0x7e, 0xc3, 0x3c, 0x06, 0x3e, 0x66, 0x3f, 0x00,
  0xcc, 0x00, 0x78, 0x0c, 0x7c, 0xcc, 0x7e, 0x00, 0xe0, 0x00, 0x78, 0x0c,
  0x7c, 0xcc, 0x7e, 0x00, 0x30, 0x30, 0x78, 0x0c, 0x7c, 0xcc, 0x7e, 0x00,
  0x00, 0x00, 0x78, 0xc0, 0xc0, 0x78, 0x0c, 0x38, 0x7e, 0xc3, 0x3c, 0x66,
  0x7e, 0x60, 0x3c, 0x00, 0xcc, 0x00, 0x78, 0xcc, 0xfc, 0xc0, 0x78, 0x00,
  0xe0, 0x00, 0x78, 0xcc, 0xfc, 0xc0, 0x78, 0x00, 0xcc, 0x00, 0x70, 0x30,
  0x30, 0x30, 0x78, 0x00, 0x7c, 0xc6, 0x38, 0x18, 0x18, 0x18, 0x3c, 0x00,
  0xe0, 0x00, 0x70, 0x30, 0x30, 0x30, 0x78, 0x00, 0xc6, 0x38, 0x6c, 0xc6,
  0xfe, 0xc6, 0xc6, 0x00, 0x30, 0x30, 0x00, 0x78, 0xcc, 0xfc, 0xcc, 0x00,
  0x1c, 0x00, 0xfc, 0x60, 0x78, 0x60, 0xfc, 0x00, 0x00, 0x00, 0x7f, 0x0c,
  0x7f, 0xcc, 0x7f, 0x00, 0x3e, 0x6c, 0xcc, 0xfe, 0xcc, 0xcc, 0xce, 0x00,
  0x78, 0xcc, 0x00, 0x78, 0xcc, 0xcc, 0x78, 0x00, 0x00, 0xcc, 0x00, 0x78,
  0xcc, 0xcc, 0x78, 0x00, 0x00, 0xe0, 0x00, 0x78, 0xcc, 0xcc, 0x78, 0x00,
  0x78, 0xcc, 0x00, 0xcc, 0xcc, 0xcc, 0x7e, 0x00, 0x00, 0xe0, 0x00, 0xcc,
  0xcc, 0xcc, 0x7e, 0x00, 0x00, 0xcc, 0x00, 0xcc, 0xcc, 0x7c, 0x0c, 0xf8,
  0xc3, 0x18, 0x3c, 0x66, 0x66, 0x3c, 0x18, 0x00, 0xcc, 0x00, 0xcc, 0xcc,
  0xcc, 0xcc, 0x78, 0x00, 0x18, 0x18, 0x7e, 0xc0, 0xc0, 0x7e, 0x18, 0x18,
  0x38, 0x6c, 0x64, 0xf0, 0x60, 0xe6, 0xfc, 0x00, 0xcc, 0xcc, 0x78, 0xfc,
  0x30, 0xfc, 0x30, 0x30, 0xf8, 0xcc, 0xcc, 0xfa, 0xc6, 0xcf, 0xc6, 0xc7,
  0x0e, 0x1b, 0x18, 0x3c, 0x18, 0x18, 0xd8, 0x70, 0x1c, 0x00, 0x78, 0x0c,
  0x7c, 0xcc, 0x7e, 0x00, 0x38, 0x00, 0x70, 0x30, 0x30, 0x30, 0x78, 0x00,
  0x00, 0x1c, 0x00, 0x78, 0xcc, 0xcc, 0x78, 0x00, 0x00, 0x1c, 0x00, 0xcc,
  0xcc, 0xcc, 0x7e, 0x00, 0x00, 0xf8, 0x00, 0xf8, 0xcc, 0xcc, 0xcc, 0x00,
  0xfc, 0x00, 0xcc, 0xec, 0xfc, 0xdc, 0xcc, 0x00, 0x3c, 0x6c, 0x6c, 0x3e,
  0x00, 0x7e, 0x00, 0x00, 0x38, 0x6c, 0x6c, 0x38, 0x00, 0x7c, 0x00, 0x00,
  0x30, 0x00, 0x30, 0x60, 0xc0, 0xcc, 0x78, 0x00, 0x00, 0x00, 0x00, 0xfc,
  0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x0c, 0x0c, 0x00, 0x00,
  0xc3, 0xc6, 0xcc, 0xde, 0x33, 0x66, 0xcc, 0x0f, 0xc3, 0xc6, 0xcc, 0xdb,
  0x37, 0x6f, 0xcf, 0x03, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x18, 0x00,
  0x00, 0x33, 0x66, 0xcc, 0x66, 0x33, 0x00, 0x00, 0x00, 0xcc, 0x66, 0x33,
  0x66, 0xcc, 0x00, 0x00, 0x22, 0x88, 0x22, 0x88, 0x22, 0x88, 0x22, 0x88,
  0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0xdb, 0x77, 0xdb, 0xee,
  0xdb, 0x77, 0xdb, 0xee, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  0x18, 0x18, 0x18, 0x18, 0xf8, 0x18, 0x18, 0x18, 0x18, 0x18, 0xf8, 0x18,
  0xf8, 0x18, 0x18, 0x18, 0x36, 0x36, 0x36, 0x36, 0xf6, 0x36, 0x36, 0x36,
  0x00, 0x00, 0x00, 0x00, 0xfe, 0x36, 0x36, 0x36, 0x00, 0x00, 0xf8, 0x18,
  0xf8, 0x18, 0x18, 0x18, 0x36, 0x36, 0xf6, 0x06, 0xf6, 0x36, 0x36, 0x36,
  0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x00, 0x00, 0xfe, 0x06,
  0xf6, 0x36, 0x36, 0x36, 0x36, 0x36, 0xf6, 0x06, 0xfe, 0x00, 0x00, 0x00,
  0x36, 0x36, 0x36, 0x36, 0xfe, 0x00, 0x00, 0x00, 0x18, 0x18, 0xf8, 0x18,
  0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x18, 0x18, 0x18,
  0x18, 0x18, 0x18, 0x18, 0x1f, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18,
  0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x18, 0x18, 0x18,
  0x18, 0x18, 0x18, 0x18, 0x1f, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00,
  0xff, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0xff, 0x18, 0x18, 0x18,
  0x18, 0x18, 0x1f, 0x18, 0x1f, 0x18, 0x18, 0x18, 0x36, 0x36, 0x36, 0x36,
  0x37, 0x36, 0x36, 0x36, 0x36, 0x36, 0x37, 0x30, 0x3f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x3f, 0x30, 0x37, 0x36, 0x36, 0x36, 0x36, 0x36, 0xf7, 0x00,
  0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xf7, 0x36, 0x36, 0x36,
  0x36, 0x36, 0x37, 0x30, 0x37, 0x36, 0x36, 0x36, 0x00, 0x00, 0xff, 0x00,
  0xff, 0x00, 0x00, 0x00, 0x36, 0x36, 0xf7, 0x00, 0xf7, 0x36, 0x36, 0x36,
  0x18, 0x18, 0xff, 0x00, 0xff, 0x00, 0x00, 0x00, 0x36, 0x36, 0x36, 0x36,
  0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xff, 0x18, 0x18, 0x18,
  0x00, 0x00, 0x00, 0x00, 0xff, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
  0x3f, 0x00, 0x00, 0x00, 0x18, 0x18, 0x1f, 0x18, 0x1f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x1f, 0x18, 0x1f, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00,
  0x3f, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0xff, 0x36, 0x36, 0x36,
  0x18, 0x18, 0xff, 0x18, 0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
  0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x18, 0x18, 0x18,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
  0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
  0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x76, 0xdc, 0xc8, 0xdc, 0x76, 0x00,
  0x00, 0x78, 0xcc, 0xf8, 0xcc, 0xf8, 0xc0, 0xc0, 0x00, 0xfc, 0xcc, 0xc0,
  0xc0, 0xc0, 0xc0, 0x00, 0x00, 0xfe, 0x6c, 0x6c, 0x6c, 0x6c, 0x6c, 0x00,
  0xfc, 0xcc, 0x60, 0x30, 0x60, 0xcc, 0xfc, 0x00, 0x00, 0x00, 0x7e, 0xd8,
  0xd8, 0xd8, 0x70, 0x00, 0x00, 0x66, 0x66, 0x66, 0x66, 0x7c, 0x60, 0xc0,
  0x00, 0x76, 0xdc, 0x18, 0x18, 0x18, 0x18, 0x00, 0xfc, 0x30, 0x78, 0xcc,
  0xcc, 0x78, 0x30, 0xfc, 0x38, 0x6c, 0xc6, 0xfe, 0xc6, 0x6c, 0x38, 0x00,
  0x38, 0x6c, 0xc6, 0xc6, 0x6c, 0x6c, 0xee, 0x00, 0x1c, 0x30, 0x18, 0x7c,
  0xcc, 0xcc, 0x78, 0x00, 0x00, 0x00, 0x7e, 0xdb, 0xdb, 0x7e, 0x00, 0x00,
  0x06, 0x0c, 0x7e, 0xdb, 0xdb, 0x7e, 0x60, 0xc0, 0x38, 0x60, 0xc0, 0xf8,
  0xc0, 0x60, 0x38, 0x00, 0x78, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0x00,
  0x00, 0xfc, 0x00, 0xfc, 0x00, 0xfc, 0x00, 0x00, 0x30, 0x30, 0xfc, 0x30,
  0x30, 0x00, 0xfc, 0x00, 0x60, 0x30, 0x18, 0x30, 0x60, 0x00, 0xfc, 0x00,
  0x18, 0x30, 0x60, 0x30, 0x18, 0x00, 0xfc, 0x00, 0x0e, 0x1b, 0x1b, 0x18,
  0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xd8, 0xd8, 0x70,
  0x30, 0x30, 0x00, 0xfc, 0x00, 0x30, 0x30, 0x00, 0x00, 0x76, 0xdc, 0x00,
  0x76, 0xdc, 0x00, 0x00, 0x38, 0x6c, 0x6c, 0x38, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x18, 0x00, 0x00, 0x00, 0x0f, 0x0c, 0x0c, 0x0c, 0xec, 0x6c, 0x3c, 0x1c,
  0x78, 0x6c, 0x6c, 0x6c, 0x6c, 0x00, 0x00, 0x00, 0x70, 0x18, 0x30, 0x60,
  0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

