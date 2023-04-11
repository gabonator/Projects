#include "cicoemu.h"
#include <time.h>
using namespace CicoContext;

void sub_17230();

void start()
{
  headerSize = 0x0200;
  ds = 0x1723;
  cs = 0x1723;
  ss = 0x1000;
  sp = 0x0100;
  sub_17230();
}
// skipping indirect jump
void sub_17230();
void sub_176d0();
void sub_17863();
void sub_17888();
void sub_178ad();
void sub_1790e();
void sub_17930();
void sub_1793d();
void sub_179d1();
void sub_17aa2();
void sub_17b15();
void sub_181b7();
void sub_181f9();
void sub_18250();
void sub_18299();
void sub_1830d();
void sub_18342();
void sub_18354();
void sub_18375();
void sub_18396();
void sub_18413();
void sub_18430();
void sub_184d1();
void sub_184f1();
void sub_18568();
void sub_185da();
void sub_185e7();
void sub_18608();
void sub_18618();
void sub_18649();
void sub_186af();
void sub_18800();
void sub_18838();
void sub_18887();
void sub_188f6();
void sub_189c9();
void sub_189dd();
void sub_18a60();
void sub_18a7b();
void sub_18b52();
void sub_18b66();
void sub_18d1a();
void sub_18d35();
void sub_18d7c();
void sub_18daa();
void sub_18e20();
void sub_18e97();
void sub_18f61();
void sub_18f9e();
void sub_18fa6();
void sub_19047();
void sub_19070();
void sub_19093();
void sub_19252();
void sub_19289();
void sub_192cb();
void sub_19311();
void sub_19325();
void sub_19366();
void sub_19410();
void sub_19440();
void sub_19446();
void sub_1950c();
void sub_19527();
void sub_19560();
void sub_195ab();
void sub_1977d();
void sub_19797();
void sub_1988e();
void sub_198c0();
void sub_198e3();
void sub_1990a();
void sub_19911();
void sub_19918();
void sub_19922();
void sub_1992c();
void sub_19936();
void sub_1994e();
void sub_19969();
void sub_199c0();
void sub_19b75();
void sub_19b88();
void sub_19ba0();
void sub_19bb8();
void sub_19bd0();
void sub_19c11();
void sub_19c30();
void sub_19c60();
void sub_19c98();
void sub_19cb0();
void sub_19cf6();
void sub_19d54();
void sub_19da1();
void sub_19dbb();
void sub_19dce();
void sub_19e6d();
void sub_19eb4();
void sub_19ee0();
void sub_19efc();
void sub_19f65();
void sub_19fa0();
void sub_19fcd();
void sub_19ffa();
void sub_1a02d();
void sub_1a040();
void sub_1a059();
void sub_1a090();
void sub_1a196();
void sub_1a23f();
void sub_1a313();
void sub_1a32a();
void sub_1a380();
void sub_1a569();
void sub_1a5d0();
void sub_1a5ea();
void sub_1a635();
void sub_1a675();
void sub_1a6af();
void sub_1a6d0();
void sub_1a7f9();
void sub_1a86d();
void sub_1a8a5();
void sub_1a9f1();
void sub_1aa15();
void sub_1aa80();
void sub_1aae0();
void sub_1ac2a();
void sub_1ac4c();
void sub_1ac6a();
void sub_1ac9c();
void sub_1acc6();
void sub_1acdc();
void sub_1ad24();
void sub_1ad60();
void sub_1ad72();
void sub_1add3();
void sub_1ae0b();
void sub_1ae73();
void sub_1aec0();
void sub_1aee1();
void sub_1b044();
void sub_1b068();
void sub_1b082();
void sub_1b09e();
void sub_1b0c0();
void sub_1b1ce();
void sub_1b295();
void sub_1b2c0();
void sub_1b2f2();
void sub_1b484();
void sub_1b4a7();
void sub_1b4e4();
void sub_1b50b();
void sub_1b52c();
void sub_1b54c();
void sub_1b570();
void sub_1b717();
void sub_1b72b();
void sub_1b75d();
void sub_1b787();
void sub_1b7aa();
void sub_1b7db();
void sub_1b96e();
void sub_1b989();
void sub_1b9a3();
void sub_1b9b6();
void sub_1b9e0();
void sub_1ba06();
void sub_1babd();
void sub_1bad1();
void sub_1baf1();
void sub_1bb07();
void sub_1bb46();
void sub_1bb73();
void sub_1bd33();
void sub_1bd4d();
void sub_1bd77();
void sub_1bdf8();
void sub_1be18();
void sub_1be30();
void sub_1be40();
void sub_1c000();
void sub_1c06e();
void sub_1c0a5();
void sub_1c140();
void sub_1c17a();
void sub_1c189();
void sub_1c1eb();
void sub_1c1fd();
void sub_1c20f();
void sub_1c238();
void sub_1c25d();
void sub_1c290();
void sub_1c37a();
void sub_1c3cb();
void sub_1c45a();
void sub_1c4bb();
void sub_1c500();
void sub_1c543();
void sub_1c598();
void sub_1c5e0();
void sub_1c630();
void sub_1c680();
void sub_1c69d();
void sub_1c8c1();
void sub_1c924();
void sub_1c934();
void sub_1c95e();
void sub_1c99e();
void sub_1c9c7();
void sub_1c9d6();
void sub_1ca05();
void sub_1ca14();
void sub_1ca59();
void sub_1ca65();
void sub_1ca99();
void sub_1cab9();
void sub_1cac6();
void sub_1cac7();
void sub_1caed();
void sub_1cb28();
void sub_1cb3e();
void sub_1cb4f();
void sub_1cb6b();
void sub_1cb8d();
void sub_1cbaf();
void sub_1cbd3();
void sub_1cbfb();
void sub_1cc4c();
void sub_1ccc0();
void sub_1ccf2();
void sub_1cd51();
void sub_1cd58();
void sub_1cd84();
void sub_1cd93();
void sub_1cdef();
void sub_1ce10();
void sub_1ce90();
void sub_1cece();
void sub_1cee0();
void sub_1d004();
void sub_1d05b();
void sub_1d06b();
void sub_1d08b();
void sub_1d0a0();
void sub_1d115();
void sub_1d1c7();
void sub_1d1e1();
void sub_1d1fd();
void sub_1d215();
void sub_1d23f();
void sub_1d270();
void sub_1d330();
void sub_1d336();
void sub_1d42a();
void sub_1d45b();
void sub_1d475();
void sub_1d4d6();
// skipping indirect jump
// skipping indirect jump
void sub_17230()
{
  push(ds);
  ax = 0x0000;
  push(ax);
  sub_1ce90();
  ax = 0x1010;
  ds = ax;
  sub_185da();
  memoryASet(ds, 0x0690, 0x04);
  memoryASet16(ds, 0x6df8, 0x0000);
  memoryASet(ds, 0x069b, 0x00);
  sub_18649();
  sub_18618();
  ax = memoryAGet16(ds, 0x0693);
  ax += 0x0240;
  memoryASet16(ds, 0x6e00, ax);
  ax = 0x0004;
  interrupt(0x10);
  al = 0x04;
  if (memoryAGet(ds, 0x0697) == 0xfd)
    goto loc_1726f;
  al = 0x06;
loc_1726f:
  memoryASet(ds, 0x0690, al);
  ah = 0x0b;
  bx = 0x0101;
  interrupt(0x10);
  memoryASet16(ds, 0x0416, 0x0000);
  memoryASet16(ds, 0x0004, 0x0000);
  sub_18f61();
  if (memoryAGet(ds, 0x0697) == 0xfd)
    goto loc_17295;
  dx = 0x03d9;
  al = 0x20;
  out(dx, al);
loc_17295:
  sub_1a040();
  sub_19911();
  sub_1990a();
  memoryASet(ds, 0x041a, 0x00);
  ax = 0xffff;
  memoryASet16(ds, 0x041d, ax);
  memoryASet16(ds, 0x041f, ax);
  memoryASet(ds, 0x0000, 0xff);
loc_172b1:
  sub_198c0();
  memoryASet16(ds, 0x0008, 0x0000);
  memoryASet16(ds, 0x0004, 0x0000);
  sub_18f61();
  sub_1cd51();
  sub_1cee0();
  sub_1cd51();
  if (memoryAGet(ds, 0x041a) != 0x00)
    goto loc_172de;
loc_172d3:
  sub_1cd51();
  sub_1d115();
  memoryASet(ds, 0x041a, 0x01);
loc_172de:
  ax = memoryAGet16(ds, 0x6df8);
  memoryASet16(ds, 0x0008, ax);
  memoryASet(ds, 0x1f80, 0x03);
  sub_1990a();
  memoryASet16(ds, 0x0004, 0x0000);
  sub_18f61();
  sub_1cd51();
  memoryASet16(ds, 0x1c30, 0x0000);
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x0412, dx);
  memoryASet16(ds, 0x0414, 0x0000);
  memoryASet(ds, 0x0418, 0x00);
  memoryASet(ds, 0x0419, 0x00);
  memoryASet(ds, 0x041c, 0x00);
  memoryASet(ds, 0x041b, 0x00);
  sub_1cd51();
loc_17323:
  if (memoryAGet(ds, 0x1f80) == 0x00)
    goto loc_172b1;
  if (memoryAGet(ds, 0x041b) != 0x00)
    goto loc_172de;
  if (memoryAGet(ds, 0x041c) != 0x00)
    goto loc_172d3;
  sub_19c30();
  sub_1c630();
  memoryASet(ds, 0x1f81, 0xff);
  sub_1cd51();
  memoryASet16(ds, 0x0004, 0x0000);
  if (memoryAGet(ds, 0x0419) == 0x00)
    goto loc_17367;
  sub_179d1();
  memoryASet(ds, 0x0550, 0x02);
  memoryASet(ds, 0x0576, 0x01);
  memoryASet(ds, 0x0578, 0x20);
  goto loc_17370;
loc_17367:
  memoryASet16(ds, 0x0579, 0x0000);
  sub_1793d();
loc_17370:
  sub_19070();
  sub_18a60();
  sub_19440();
  sub_19560();
  sub_19922();
  sub_1992c();
  sub_1caed();
loc_17385:
  if (memoryAGet(ds, 0x1f80) != 0x00)
    goto loc_1738f;
  goto loc_172b1;
loc_1738f:
  sub_18568();
  if (memoryAGet(ds, 0x041c) == 0x00)
    goto loc_1739c;
  goto loc_172d3;
loc_1739c:
  if (memoryAGet(ds, 0x041b) == 0x00)
    goto loc_173a6;
  goto loc_172de;
loc_173a6:
  sub_18430();
  sub_17b15();
  sub_19093();
  if (memoryAGet(ds, 0x1cb8) != 0x00)
    goto loc_173c1;
  memoryASet(ds, 0x040f, memoryAGet(ds, 0x040f) + 1);
  if (memoryAGet(ds, 0x040f) & 0x03)
    goto loc_17385;
loc_173c1:
  sub_1c69d();
  sub_176d0();
  sub_18b66();
  sub_18a7b();
  sub_19446();
  sub_195ab();
  sub_198e3();
  if (memoryAGet(ds, 0x0551) == 0x00)
    goto loc_17385;
  if (memoryAGet(ds, 0x1f80) != 0x00)
    goto loc_173e7;
  goto loc_172b1;
loc_173e7:
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x0410, dx);
  ax = memoryAGet16(ds, 0x0579);
  memoryASet16(ds, 0x0001, ax);
  al = memoryAGet(ds, 0x057b);
  memoryASet(ds, 0x0003, al);
  memoryASet(ds, 0x0419, 0x01);
  if (memoryAGet(ds, 0x0418) == 0x00)
    goto loc_17415;
  memoryASet(ds, 0x0418, 0x00);
  memoryASet16(ds, 0x0004, 0x0007);
  goto loc_17468;
  //   gap of 1 bytes
loc_17415:
  sub_1a02d();
  if (!(dl & 0xa0))
    goto loc_1743a;
  bx = memoryAGet16(ds, 0x0008);
  bx &= 0x0003;
  if (bx == 0x0003)
    goto loc_1743a;
  cl = 0x02;
  bx <<= cl;
  dx &= 0x0003;
  bx += dx;
  al = memoryAGet(ds, bx + 1057);
  goto loc_1744c;
loc_1743a:
  sub_1a02d();
  dx &= 0x0007;
  if (dx >= 0x0005)
    goto loc_1743a;
  bx = dx;
  al = memoryAGet(ds, bx + 1069);
loc_1744c:
  ah = 0;
  if (ax != memoryAGet16(ds, 0x041d))
    goto loc_1745a;
  if (ax == memoryAGet16(ds, 0x041f))
    goto loc_17415;
loc_1745a:
  memoryASet16(ds, 0x0004, ax);
  cx = memoryAGet16(ds, 0x041d);
  memoryASet16(ds, 0x041f, cx);
  memoryASet16(ds, 0x041d, ax);
loc_17468:
  memoryASet16(ds, 0x0006, 0x0000);
  bx = memoryAGet16(ds, 0x0004);
  if (bx <= 0x0007)
    goto loc_17479;
  bx = 0;
loc_17479:
  bx <<= 1;
    switch (bx)
    {
    case 0: goto loc_17612;
    case 2: goto loc_17612;
    case 4: goto loc_17689;
    case 6: goto loc_175c4;
    case 8: goto loc_17579;
    case 10: goto loc_1752e;
    case 12: goto loc_174da;
    case 14: goto loc_17490;
    default:
    assert(0);
    }
loc_17490:
  memoryASet16(ds, 0x0004, 0x0007);
  sub_18e20();
  sub_199c0();
  sub_179d1();
  sub_19070();
  sub_1a635();
  sub_1d330();
  sub_1c189();
  sub_1caed();
loc_174ae:
  sub_18568();
  sub_18430();
  sub_1c69d();
  sub_17b15();
  sub_1d336();
  sub_1a196();
  sub_1a090();
  sub_1be40();
  al = memoryAGet(ds, 0x0551);
  al |= memoryAGet(ds, 0x0553);
  al |= memoryAGet(ds, 0x041c);
  al |= memoryAGet(ds, 0x041b);
  if (!al)
    goto loc_174ae;
  goto loc_17657;
loc_174da:
  memoryASet16(ds, 0x0004, 0x0006);
  sub_18e20();
  sub_199c0();
  sub_1be30();
  sub_179d1();
  sub_1a635();
  sub_19070();
  sub_1caed();
loc_174f5:
  sub_18568();
  sub_18430();
  sub_1c69d();
  sub_1bb73();
  sub_1ba06();
  sub_17b15();
  if (memoryAGet(ds, 0x1cb8) == 0x00)
    goto loc_17513;
  sub_19093();
  goto loc_17516;
loc_17513:
  sub_1a380();
loc_17516:
  al = memoryAGet(ds, 0x0551);
  al |= memoryAGet(ds, 0x0552);
  al |= memoryAGet(ds, 0x0553);
  al |= memoryAGet(ds, 0x041b);
  al |= memoryAGet(ds, 0x041c);
  if (!al)
    goto loc_174f5;
  goto loc_17657;
loc_1752e:
  memoryASet16(ds, 0x0004, 0x0005);
  sub_18e20();
  sub_199c0();
  sub_1b7aa();
  sub_179d1();
  sub_1a635();
  sub_19070();
  sub_1caed();
loc_17549:
  sub_18568();
  sub_18430();
  sub_1c69d();
  sub_1b7db();
  sub_1b570();
  sub_17b15();
  sub_1a380();
  sub_19093();
  al = memoryAGet(ds, 0x0552);
  al |= memoryAGet(ds, 0x0553);
  al |= memoryAGet(ds, 0x0551);
  al |= memoryAGet(ds, 0x041c);
  al |= memoryAGet(ds, 0x041b);
  if (!al)
    goto loc_17549;
  goto loc_17657;
loc_17579:
  memoryASet16(ds, 0x0004, 0x0004);
  sub_18e20();
  sub_199c0();
  sub_179d1();
  sub_1a635();
  sub_19070();
  sub_1b2c0();
  sub_1caed();
loc_17594:
  sub_18568();
  sub_18430();
  sub_1c69d();
  sub_17b15();
  sub_1b0c0();
  sub_1b2f2();
  sub_1a380();
  sub_19093();
  al = memoryAGet(ds, 0x0552);
  al |= memoryAGet(ds, 0x0553);
  al |= memoryAGet(ds, 0x0551);
  al |= memoryAGet(ds, 0x041c);
  al |= memoryAGet(ds, 0x041b);
  if (!al)
    goto loc_17594;
  goto loc_17657;
loc_175c4:
  memoryASet16(ds, 0x0004, 0x0003);
  sub_18e20();
  sub_199c0();
  sub_179d1();
  sub_1a635();
  sub_19070();
  sub_1ad60();
  sub_1aec0();
  sub_1caed();
loc_175e2:
  sub_18568();
  sub_18430();
  sub_1c69d();
  sub_17b15();
  sub_1aee1();
  sub_1ad72();
  sub_1a380();
  sub_19093();
  al = memoryAGet(ds, 0x0552);
  al |= memoryAGet(ds, 0x0553);
  al |= memoryAGet(ds, 0x0551);
  al |= memoryAGet(ds, 0x041c);
  al |= memoryAGet(ds, 0x041b);
  if (!al)
    goto loc_175e2;
  goto loc_17657;
  //   gap of 1 bytes
loc_17612:
  memoryASet16(ds, 0x0004, 0x0001);
  sub_18e20();
  sub_199c0();
  sub_179d1();
  sub_1a635();
  sub_19070();
  sub_1caed();
loc_1762a:
  sub_18568();
  sub_18430();
  sub_1c69d();
  sub_17b15();
  sub_1a380();
  sub_19093();
  sub_1aa80();
  if (memoryAGet(ds, 0x0554) != 0x00)
    goto loc_17689;
  al = memoryAGet(ds, 0x0552);
  al |= memoryAGet(ds, 0x0551);
  al |= memoryAGet(ds, 0x041b);
  al |= memoryAGet(ds, 0x041c);
  if (!al)
    goto loc_1762a;
loc_17657:
  if (memoryAGet(ds, 0x041b) == 0x00)
    goto loc_17661;
  goto loc_172de;
loc_17661:
  if (memoryAGet(ds, 0x041c) == 0x00)
    goto loc_1766b;
  goto loc_172d3;
loc_1766b:
  if (memoryAGet(ds, 0x0552) == 0x00)
    goto loc_17677;
  memoryASet(ds, 0x0419, 0x00);
loc_17677:
  ax = memoryAGet16(ds, 0x0004);
  memoryASet16(ds, 0x0006, ax);
  memoryASet16(ds, 0x0004, 0x0000);
  sub_18e20();
  goto loc_17323;
loc_17689:
  memoryASet16(ds, 0x0004, 0x0002);
  sub_18e20();
  sub_199c0();
  sub_1a7f9();
  sub_179d1();
  memoryASet(ds, 0x1cbf, 0x00);
  memoryASet(ds, 0x1cb8, 0x00);
  sub_1caed();
loc_176a8:
  sub_18568();
  sub_18430();
  sub_1c69d();
  sub_17b15();
  sub_1a8a5();
  sub_1aa15();
  al = memoryAGet(ds, 0x0552);
  al |= memoryAGet(ds, 0x0553);
  al |= memoryAGet(ds, 0x041c);
  al |= memoryAGet(ds, 0x041b);
  if (!al)
    goto loc_176a8;
  goto loc_17657;
}
void sub_176d0()
{
  memoryASet(ds, 0x0531, memoryAGet(ds, 0x0531) - 1);
  if (memoryAGet(ds, 0x0531) == 0)
    goto loc_176d7;
loc_176d6:
  return;
loc_176d7:
  memoryASet(ds, 0x0531, memoryAGet(ds, 0x0531) + 1);
  sub_18608();
  if (!flags.zero)
    goto loc_176d6;
  if (memoryAGet(ds, 0x055a) != 0x00)
    goto loc_176d6;
  if (memoryAGet(ds, 0x1673) != 0x00)
    goto loc_176d6;
  ah = 0;
  interrupt(0x1a);
  if (dx == memoryAGet16(ds, 0x0544))
    goto loc_176d6;
  memoryASet16(ds, 0x0544, dx);
  bx = memoryAGet16(ds, 0x0008);
  al = memoryAGet(ds, bx + 1330);
  if (memoryAGet(ds, 0x057b) > 0x60)
    goto loc_1770f;
  al >>= 1;
  al >>= 1;
loc_1770f:
  memoryASet(ds, 0x0531, al);
  bx = memoryAGet16(ds, 0x052f);
  sub_17888();
  if (flags.zero)
    goto loc_1773c;
  al = memoryAGet(ds, 0x0525);
  al += memoryAGet(ds, bx + 1321);
  if (al < 0x04)
    goto loc_176d6;
loc_17726:
  sub_1a02d();
  dl &= 0x03;
  if (dl == memoryAGet(ds, 0x052f))
    goto loc_17726;
  if (dl == 0x03)
    goto loc_17726;
  bl = dl;
  goto loc_17765;
  //   gap of 1 bytes
loc_1773c:
  al = memoryAGet(ds, bx + 1321);
  memoryASet(ds, 0x0525, memoryAGet(ds, 0x0525) + al);
  if (memoryAGet(ds, 0x0525) < 0x04)
    goto loc_177b3;
  sub_1a02d();
  if (dl > 0x40)
    goto loc_17769;
loc_17753:
  sub_1a02d();
  dl &= 0x03;
  if (dl == 0x03)
    goto loc_17753;
  bl = dl;
  sub_17888();
  if (!flags.zero)
    goto loc_17753;
loc_17765:
  memoryASet16(ds, 0x052f, bx);
loc_17769:
  al = memoryAGet(ds, bx + 1318);
  memoryASet(ds, 0x0525, al);
  ax = 0x1010;
  es = ax;
  di = 0x04d7;
  ah = memoryAGet(ds, bx + 1324);
  bx = memoryAGet16(ds, 0x0008);
  bl = memoryAGet(ds, bx + 10938);
  bh = ah;
  sub_178ad();
  if (memoryAGet16(ds, 0x052f) == 0x0001)
    goto loc_1779e;
  memoryASet(ds, 0x0540, memoryAGet(ds, 0x0540) >> 1);
  sub_17863();
  memoryASet(ds, 0x0540, memoryAGet(ds, 0x0540) >> 1);
  goto loc_177ac;
  //   gap of 1 bytes
loc_1779e:
  al = memoryAGet(ds, 0x0540);
  al >>= 1;
  al >>= 1;
  sub_17863();
  memoryASet(ds, 0x0540, memoryAGet(ds, 0x0540) >> 1);
loc_177ac:
  sub_17863();
  bx = memoryAGet16(ds, 0x052f);
loc_177b3:
  if (memoryAGet(ds, 0x04d6) == 0x00)
    goto loc_17800;
  ax = memoryAGet16(ds, 0x0579);
  if (bl == 0x01)
    goto loc_177ef;
  memoryASet16(ds, 0x055f, memoryAGet16(ds, 0x055f) + 1);
  ax += 0x0004;
  if (ax < 0x0123)
    goto loc_177fd;
loc_177ce:
  memoryASet(ds, 0x055b, 0x11);
  memoryASet(ds, 0x0571, 0x01);
  memoryASet(ds, 0x0576, 0x01);
  memoryASet(ds, 0x0578, 0x18);
  memoryASet(ds, 0x0572, 0x01);
  memoryASet(ds, 0x055c, 0x00);
  goto loc_17800;
  //   gap of 1 bytes
loc_177ef:
  memoryASet16(ds, 0x055f, memoryAGet16(ds, 0x055f) - 1);
  flags.carry = ax < 0x0004;
  ax -= 0x0004;
  if (flags.carry)
    goto loc_177ce;
  if (ax < 0x0008)
    goto loc_177ce;
loc_177fd:
  memoryASet16(ds, 0x0579, ax);
loc_17800:
  push(ds);
  bx <<= 1;
  ax = memoryAGet16(ds, bx + 1309);
  memoryASet16(ds, 0x0523, ax);
  si = memoryAGet16(ds, bx + 1303);
  ax = 0xb800;
  ds = ax;
  es = ax;
  di = si;
  if (bx != 0x0002)
    goto loc_17821;
  flags.direction = false;
  di--;
  goto loc_17823;
  //   gap of 1 bytes
loc_17821:
  flags.direction = true;
  di++;
loc_17823:
  cx = 0x027f;
  push(di);
  push(si);
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si = pop();
  di = pop();
  si += 0x2000;
  di += 0x2000;
  cx = 0x0280;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  ds = pop();
  di = memoryAGet16(ds, 0x0523);
  bl = memoryAGet(ds, 0x0525);
  bh = 0;
  bx += 0x04d7;
  cx = 0x0010;
loc_1784b:
  al = memoryAGet(ds, bx);
  memoryASet(es, di, al);
  bx += 0x0004;
  di ^= 0x2000;
  if (di & 0x2000)
    goto loc_17860;
  di += 0x0050;
loc_17860:
  if (--cx)
    goto loc_1784b;
}
void sub_17863()
{
  ah = flags.carry | (flags.zero << 1);
  bx = memoryAGet16(ds, 0x052f);
  bl = memoryAGet(ds, bx + 1345);
  cx = 0x0005;
  if (bl == 0x09)
    goto loc_1787e;
loc_17874:
  flags.carry = ah & 1;
  memoryASet(ds, bx + 4118, rcr(memoryAGet(ds, bx + 4118), 0x01));
  ah = flags.carry;
  bx++;
  if (--cx)
    goto loc_17874;
  return;
loc_1787e:
  flags.carry = ah & 1;
  memoryASet(ds, bx + 4118, rcl(memoryAGet(ds, bx + 4118), 0x01));
  ah = flags.carry;
  bx--;
  if (--cx)
    goto loc_1787e;
}
// INJECT: Error: cannot inject zero flag in sub_17888()!
void sub_17888()
{
  memoryASet(ds, 0x04d6, 0x00);
  al = memoryAGet(ds, 0x057c);
  if (al < memoryAGet(ds, bx + 1341))
    goto loc_178a9;
  if (al >= memoryAGet(ds, bx + 1338))
    goto loc_178a9;
  if (memoryAGet(ds, 0x055c) >= 0x01)
    goto loc_178a4;
  flags.zero = memoryAGet(ds, 0x055c) == 0x01;
  return;
loc_178a4:
  memoryASet(ds, 0x04d6, 0x01);
loc_178a9:
  flags.zero = al == al;
}
void sub_178ad()
{
  memoryASet(ds, 0x0540, 0x00);
  flags.direction = false;
  cx = 0x0020;
  ax = 0xaaaa;
  rep_stosw<MemAuto, DirAuto>();
  di -= 0x0040;
  ax = 0x4444;
  memoryASet16(es, di + 4, ax);
  memoryASet16(es, di + 6, ax);
  sub_1a02d();
  if (dl < bl)
    goto loc_178d4;
  if (dh > bh)
    goto loc_178d5;
loc_178d4:
  return;
loc_178d5:
  sub_1a02d();
  if (dl < 0x18)
    goto loc_178f7;
  if (dl < 0x60)
    goto loc_17900;
  push(di);
  sub_1790e();
  al <<= 1;
  memoryASet(ds, 0x0540, al);
  di = pop();
  di += 0x0002;
  sub_1790e();
  memoryASet(ds, 0x0540, memoryAGet(ds, 0x0540) | al);
  return;
loc_178f7:
  cx = 0x0020;
  si = 0x0490;
  goto loc_17906;
  //   gap of 1 bytes
loc_17900:
  cx = 0x0010;
  si = 0x0460;
loc_17906:
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  memoryASet(ds, 0x0540, 0x03);
}
void sub_1790e()
{
  sub_1a02d();
  dx &= 0x0006;
  if (dl != 0x06)
    goto loc_1791d;
  al = 0;
  return;
loc_1791d:
  bx = dx;
  si = memoryAGet16(ds, bx + 1232);
  cx = 0x0008;
loc_17926:
  lodsw<MemAuto, DirAuto>();
  stosw<MemAuto, DirAuto>();
  di += 0x0002;
  if (--cx)
    goto loc_17926;
  al = 0x01;
}
void sub_17930()
{
  memoryASet16(ds, 0x057d, 0x0000);
  memoryASet16(ds, 0x0684, 0x0000);
}
void sub_1793d()
{
  cx = 0x0000;
  ah = 0x01;
  if (memoryAGet16(ds, 0x0579) < 0x00a0)
    goto loc_1794f;
  cx = 0x0128;
  ah = 0xff;
loc_1794f:
  memoryASet(ds, 0x056e, ah);
  memoryASet(ds, 0x0558, 0x03);
  memoryASet(ds, 0x0559, 0x0c);
  dl = 0xb4;
  memoryASet16(ds, 0x0579, cx);
  memoryASet(ds, 0x057b, dl);
  memoryASet(ds, 0x057c, 0xe6);
  sub_19ee0();
  memoryASet16(ds, 0x055f, ax);
  memoryASet16(ds, 0x0561, 0x0b03);
  sub_18354();
  memoryASet(ds, 0x0571, 0x00);
  memoryASet16(ds, 0x0572, 0x0002);
  memoryASet(ds, 0x0576, 0x01);
  memoryASet(ds, 0x055b, 0x00);
  memoryASet(ds, 0x0550, 0x00);
  memoryASet(ds, 0x055c, 0x00);
  memoryASet(ds, 0x055a, 0x00);
  memoryASet(ds, 0x0583, 0x00);
  memoryASet(ds, 0x0698, 0x00);
  memoryASet(ds, 0x0699, 0x00);
  memoryASet(ds, 0x0551, 0x00);
  memoryASet(ds, 0x0584, 0x00);
  memoryASet(ds, 0x0552, 0x00);
  memoryASet16(ds, 0x0554, 0x0000);
  memoryASet(ds, 0x0553, 0x00);
  memoryASet(ds, 0x127c, 0x00);
  sub_17930();
}
void sub_179d1()
{
  bx = memoryAGet16(ds, 0x0004);
  if (bx != 0x0000)
    goto loc_179e5;
  cx = memoryAGet16(ds, 0x0001);
  dl = memoryAGet(ds, 0x0003);
  goto loc_179ef;
  //   gap of 1 bytes
loc_179e5:
  dl = memoryAGet(ds, bx + 1513);
  bl <<= 1;
  cx = memoryAGet16(ds, bx + 1497);
loc_179ef:
  memoryASet16(ds, 0x0579, cx);
  memoryASet(ds, 0x057b, dl);
  al = dl;
  al += 0x32;
  memoryASet(ds, 0x057c, al);
  sub_19ee0();
  memoryASet16(ds, 0x055f, ax);
  ax = memoryAGet16(ds, 0x0fb2);
  memoryASet16(ds, 0x0569, ax);
  ax = memoryAGet16(ds, 0x0fbe);
  memoryASet16(ds, 0x0567, ax);
  memoryASet16(ds, 0x0561, ax);
  sub_18354();
  memoryASet(ds, 0x0571, 0x01);
  memoryASet(ds, 0x056e, 0x00);
  memoryASet(ds, 0x0576, 0x01);
  memoryASet(ds, 0x0578, 0x40);
  al = 0x0a;
  if (memoryAGet16(ds, 0x0004) != 0x0007)
    goto loc_17a35;
  al = 0;
loc_17a35:
  memoryASet(ds, 0x055b, al);
  memoryASet(ds, 0x0550, 0x00);
  memoryASet(ds, 0x055c, 0x00);
  memoryASet(ds, 0x055a, 0x00);
  memoryASet(ds, 0x0583, 0x00);
  memoryASet(ds, 0x0698, 0x00);
  memoryASet(ds, 0x0699, 0x00);
  memoryASet(ds, 0x0551, 0x00);
  memoryASet(ds, 0x0584, 0x00);
  memoryASet(ds, 0x0552, 0x00);
  memoryASet16(ds, 0x0554, 0x0000);
  memoryASet(ds, 0x0553, 0x00);
  memoryASet(ds, 0x127c, 0x00);
  sub_17930();
  if (memoryAGet16(ds, 0x0004) != 0x0002)
    return;
  memoryASet(ds, 0x0576, 0x10);
  memoryASet16(ds, 0x0574, 0x0010);
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x05f1, dx);
  memoryASet(ds, 0x05f3, 0x00);
  memoryASet(ds, 0x05f4, 0x05);
  memoryASet(ds, 0x05f5, 0x01);
}
void sub_17aa2()
{
  memoryASet16(ds, 0x592a, 0x0400);
  if (memoryAGet(ds, 0x0584) == 0x00)
    goto loc_17ab0;
  return;
loc_17ab0:
  memoryASet(ds, 0x0576, 0x08);
  dl = 0xff;
  al = memoryAGet(ds, 0x057b);
  if (al >= memoryAGet(ds, 0x2652))
    goto loc_17ac2;
  dl = 0x01;
loc_17ac2:
  memoryASet(ds, 0x0571, dl);
  ax = memoryAGet16(ds, 0x0579);
  ax -= memoryAGet16(ds, 0x2650);
  dl = 0xff;
  if (stop(/*ja*/))
    goto loc_17ad5;
  dl = 0x01;
  ax = ~ax;
loc_17ad5:
  memoryASet(ds, 0x056e, dl);
  if (ah == 0x00)
    goto loc_17ae1;
  ax = 0x00ff;
loc_17ae1:
  al = ~al;
  if (al >= 0x30)
    goto loc_17ae9;
  al = 0x30;
loc_17ae9:
  bl = al;
  bl >>= 1;
  bl >>= 1;
  al -= bl;
  memoryASet(ds, 0x0578, al);
  cl = 0x05;
  al >>= cl;
  memoryASet16(ds, 0x0572, ax);
  memoryASet(ds, 0x055c, 0x00);
  memoryASet(ds, 0x39e0, 0x00);
  memoryASet(ds, 0x0577, 0x01);
  memoryASet(ds, 0x055b, 0x10);
  memoryASet(ds, 0x0584, 0x01);
}
void sub_17b15()
{
  ah = 0;
  interrupt(0x1a);
  if (dx != memoryAGet16(ds, 0x057d))
    goto loc_17b2d;
  if (memoryAGet16(ds, 0x0684) == 0x0000)
    goto loc_17b2c;
  memoryASet16(ds, 0x0684, memoryAGet16(ds, 0x0684) - 1);
  if (memoryAGet16(ds, 0x0684) == 0)
    goto loc_17b3c;
loc_17b2c:
  return;
loc_17b2d:
  ax = 0x0020;
  if (memoryAGet(ds, 0x0697) != 0xfd)
    goto loc_17b39;
  ax >>= 1;
loc_17b39:
  memoryASet16(ds, 0x0684, ax);
loc_17b3c:
  if (memoryAGet16(ds, 0x0004) == 0x0002)
    goto loc_17b4d;
  cl = memoryAGet(ds, 0x0571);
  cl |= memoryAGet(ds, 0x056e);
  if (cl)
    goto loc_17b56;
loc_17b4d:
  push(dx);
  push(ax);
  sub_18608();
  ax = pop();
  dx = pop();
  if (flags.zero)
    goto loc_17b2c;
loc_17b56:
  memoryASet16(ds, 0x057d, dx);
  memoryASet16(ds, 0x057f, ax);
  if (memoryAGet16(ds, 0x0004) != 0x0004)
    goto loc_17b6b;
  if (memoryAGet(ds, 0x39e1) != 0x00)
    goto loc_17b2c;
loc_17b6b:
  if (memoryAGet16(ds, 0x0004) != 0x0006)
    goto loc_17b79;
  if (memoryAGet(ds, 0x44bd) != 0x00)
    goto loc_17b2c;
loc_17b79:
  if (memoryAGet16(ds, 0x0004) == 0x0002)
    goto loc_17b83;
  goto loc_17ddc;
loc_17b83:
  si = memoryAGet16(ds, 0x0008);
  si <<= 1;
  ax = memoryAGet16(ds, 0x057d);
  ax -= memoryAGet16(ds, 0x05f1);
  if (ax < memoryAGet16(ds, si + 1417))
    goto loc_17c06;
  if (ax < memoryAGet16(ds, si + 1433))
    goto loc_17ba1;
  memoryASet(ds, 0x0552, 0x01);
loc_17ba1:
  memoryASet(ds, 0x05f5, memoryAGet(ds, 0x05f5) - 1);
  if (memoryAGet(ds, 0x05f5) != 0)
    goto loc_17be9;
  sub_1cbaf();
  memoryASet(ds, 0x05f5, 0x06);
  al = memoryAGet(ds, 0x05f4);
  if (memoryAGet(ds, 0x057b) < 0xb3)
    goto loc_17bc2;
  if (al >= 0xc8)
    goto loc_17bc2;
  al += 0x1e;
  memoryASet(ds, 0x05f4, al);
loc_17bc2:
  dl = memoryAGet(ds, 0x057b);
  flags.carry = dl < al;
  dl -= al;
  if (!flags.carry)
    goto loc_17bcc;
  dl = 0;
loc_17bcc:
  cx = memoryAGet16(ds, 0x0579);
  dl &= 0xf8;
  sub_19ee0();
  di = ax;
  si = 0x064e;
  ax = 0xb800;
  es = ax;
  bp = 0x000e;
  cx = 0x0503;
  sub_19f65();
loc_17be9:
  memoryASet(ds, 0x056e, 0x00);
  memoryASet(ds, 0x0571, 0x01);
  memoryASet(ds, 0x05f3, 0x01);
  memoryASet(ds, 0x0576, 0x20);
  bx = 0;
  ah = 0x0b;
  interrupt(0x10);
  goto loc_17cb6;
loc_17c06:
  si = memoryAGet16(ds, 0x0008);
  si <<= 1;
  bx = 0;
  if (ax < memoryAGet16(ds, si + 1449))
    goto loc_17c26;
  bl++;
  if (ax < memoryAGet16(ds, si + 1465))
    goto loc_17c26;
  bl = 0x05;
  if (ax < memoryAGet16(ds, si + 1481))
    goto loc_17c26;
  bl--;
loc_17c26:
  ah = 0x0b;
  interrupt(0x10);
  al = memoryAGet(ds, 0x056e);
  memoryASet(ds, 0x056f, al);
  al = memoryAGet(ds, 0x0571);
  memoryASet(ds, 0x0570, al);
  al = memoryAGet(ds, 0x0698);
  if (al != 0x00)
    goto loc_17c4a;
  if (memoryAGet16(ds, 0x0574) < 0x0010)
    goto loc_17c5e;
  memoryASet16(ds, 0x0574, memoryAGet16(ds, 0x0574) - 1);
  goto loc_17c67;
loc_17c4a:
  if (al != memoryAGet(ds, 0x056e))
    goto loc_17c5e;
  if (memoryAGet16(ds, 0x0574) >= 0x0030)
    goto loc_17c67;
  memoryASet16(ds, 0x0574, memoryAGet16(ds, 0x0574) + 0x0003);
  goto loc_17c67;
loc_17c5e:
  memoryASet(ds, 0x056e, al);
  memoryASet16(ds, 0x0574, 0x0020);
loc_17c67:
  ax = memoryAGet16(ds, 0x0574);
  cl = 0x03;
  ax >>= cl;
  bx = memoryAGet16(ds, 0x0008);
  bl <<= 1;
  if (ax <= memoryAGet16(ds, bx + 1644))
    goto loc_17c7e;
  ax = memoryAGet16(ds, bx + 1644);
loc_17c7e:
  memoryASet16(ds, 0x0572, ax);
  sub_181f9();
  al = memoryAGet(ds, 0x0699);
  if (al != 0x00)
    goto loc_17c9a;
  al = ~al;
  if (memoryAGet(ds, 0x0576) < 0x10)
    goto loc_17cae;
  memoryASet(ds, 0x0576, memoryAGet(ds, 0x0576) - 1);
  goto loc_17cb6;
loc_17c9a:
  if (al != memoryAGet(ds, 0x0571))
    goto loc_17cae;
  if (memoryAGet(ds, 0x0576) >= 0x40)
    goto loc_17cb6;
  memoryASet(ds, 0x0576, memoryAGet(ds, 0x0576) + 0x04);
  goto loc_17cb6;
loc_17cae:
  memoryASet(ds, 0x0571, al);
  memoryASet(ds, 0x0576, 0x20);
loc_17cb6:
  si = memoryAGet16(ds, 0x0008);
  dl = memoryAGet(ds, 0x057b);
  cl = 0x04;
  bl = memoryAGet(ds, 0x0576);
  bl >>= cl;
  if (bl <= memoryAGet(ds, si + 1660))
    goto loc_17cd0;
  bl = memoryAGet(ds, si + 1660);
loc_17cd0:
  al = memoryAGet(ds, 0x0571);
  if (al < 0x01)
    goto loc_17cfe;
  if (al != 0x01)
    goto loc_17ce4;
  dl += bl;
  if (dl < 0xb4)
    goto loc_17cfe;
  dl = 0xb3;
  goto loc_17cfe;
loc_17ce4:
  flags.carry = dl < bl;
  dl -= bl;
  if (flags.carry)
    goto loc_17ced;
  if (dl > 0x03)
    goto loc_17cfe;
loc_17ced:
  ax = memoryAGet16(ds, 0x09b8);
  if (ax != memoryAGet16(ds, 0x055d))
    goto loc_17cfc;
  ax = memoryAGet16(ds, 0x057d);
  memoryASet16(ds, 0x05f1, ax);
loc_17cfc:
  dl = 0x02;
loc_17cfe:
  memoryASet(ds, 0x057b, dl);
  cx = memoryAGet16(ds, 0x0579);
  sub_19ee0();
  memoryASet16(ds, 0x0563, ax);
  if (memoryAGet(ds, 0x05f3) == 0x00)
    goto loc_17d19;
  bx = 0x0010;
  goto loc_17d94;
  //   gap of 1 bytes
loc_17d19:
  al = memoryAGet(ds, 0x056e);
  if (al != memoryAGet(ds, 0x056f))
    goto loc_17d2b;
  al = memoryAGet(ds, 0x0571);
  if (al == memoryAGet(ds, 0x0570))
    goto loc_17d30;
loc_17d2b:
  bx = 0x0018;
  goto loc_17d94;
loc_17d30:
  memoryASet16(ds, 0x0587, memoryAGet16(ds, 0x0587) + 1);
  bx = memoryAGet16(ds, 0x0587);
  al = memoryAGet(ds, 0x0698);
  al |= memoryAGet(ds, 0x0699);
  if (al)
    goto loc_17d43;
  bl >>= 1;
loc_17d43:
  if (memoryAGet(ds, 0x057b) < 0xb3)
    goto loc_17d51;
  if (memoryAGet(ds, 0x0571) == 0x01)
    goto loc_17d6c;
loc_17d51:
  if (memoryAGet(ds, 0x057b) > 0x04)
    goto loc_17d5f;
  if (memoryAGet(ds, 0x0699) != 0x00)
    goto loc_17d83;
loc_17d5f:
  al = memoryAGet(ds, 0x0576);
  ah = 0;
  ax >>= 1;
  if (ax >= memoryAGet16(ds, 0x0574))
    goto loc_17d83;
loc_17d6c:
  if (memoryAGet(ds, 0x056e) == 0x00)
    goto loc_17d83;
  bx &= 0x0006;
  if (memoryAGet(ds, 0x056e) == 0x01)
    goto loc_17d94;
  bl |= 0x08;
  goto loc_17d94;
loc_17d83:
  bx &= 0x0002;
  bl |= 0x10;
  if (memoryAGet(ds, 0x0571) != 0x01)
    goto loc_17d94;
  bl += 0x04;
loc_17d94:
  ax = memoryAGet16(ds, bx + 2470);
  memoryASet16(ds, 0x055d, ax);
  ax = memoryAGet16(ds, bx + 2496);
  memoryASet16(ds, 0x0565, ax);
  al = 0x30;
  cx = 0x02bc;
  if (memoryAGet(ds, 0x0697) < 0xfd)
    goto loc_17dc7;
  if (memoryAGet(ds, 0x0697) == 0xfd)
    goto loc_17db5;
  al = 0x08;
  cx = 0x03e8;
loc_17db5:
  if (memoryAGet(ds, 0x057b) > al)
    goto loc_17dc7;
loc_17dbb:
  sub_18608();
  if (!flags.zero)
    goto loc_17dbb;
loc_17dc0:
  sub_18608();
  if (flags.zero)
    goto loc_17dc0;
loc_17dc5:
  if (--cx)
    goto loc_17dc5;
loc_17dc7:
  sub_18413();
  ax = memoryAGet16(ds, 0x0563);
  memoryASet16(ds, 0x055f, ax);
  sub_18375();
  sub_1a6d0();
  if (!flags.carry)
    goto loc_17ddb;
  sub_18375();
loc_17ddb:
  return;
loc_17ddc:
  sub_18daa();
  if (!flags.carry)
    goto loc_17de2;
loc_17de1:
  return;
loc_17de2:
  if (memoryAGet(ds, 0x1cb8) != 0x00)
    goto loc_17de1;
  if (memoryAGet(ds, 0x0558) == 0x00)
    goto loc_17e4c;
  if (memoryAGet(ds, 0x0559) == 0x00)
    goto loc_17e03;
  if (memoryAGet(ds, 0x1cbf) != 0x00)
    goto loc_17e02;
  memoryASet(ds, 0x0559, memoryAGet(ds, 0x0559) - 1);
loc_17e02:
  return;
loc_17e03:
  memoryASet(ds, 0x0558, memoryAGet(ds, 0x0558) - 1);
  if (memoryAGet(ds, 0x0558) != 0)
    goto loc_17e15;
  memoryASet16(ds, 0x0572, 0x0008);
  sub_181f9();
  goto loc_17e4c;
  //   gap of 1 bytes
loc_17e15:
  sub_18250();
  memoryASet16(ds, 0x055d, bx);
  al = memoryAGet(ds, 0x0558);
  ah = memoryAGet(ds, 0x056e);
  sub_181b7();
  if (memoryAGet(ds, 0x0558) == 0x02)
    goto loc_17e30;
  sub_18413();
loc_17e30:
  sub_18daa();
  if (flags.carry)
    goto loc_17e4b;
  sub_19325();
  if (flags.carry)
    goto loc_17e4b;
  dl = memoryAGet(ds, 0x057b);
  cx = memoryAGet16(ds, 0x0579);
  sub_19ee0();
  memoryASet16(ds, 0x055f, ax);
  sub_18375();
loc_17e4b:
  return;
loc_17e4c:
  if (memoryAGet(ds, 0x055c) < 0x01)
    goto loc_17e9a;
  if (memoryAGet(ds, 0x055c) != 0x01)
    goto loc_17e8f;
  memoryASet(ds, 0x055c, memoryAGet(ds, 0x055c) + 1);
  memoryASet16(ds, 0x0572, 0x0006);
  dl = memoryAGet(ds, 0x057b);
  cx = memoryAGet16(ds, 0x0579);
  sub_19ee0();
  memoryASet16(ds, 0x0563, ax);
  sub_18413();
  sub_18daa();
  if (flags.carry)
    goto loc_17e96;
  sub_19325();
  if (flags.carry)
    goto loc_17e96;
  ax = memoryAGet16(ds, 0x0563);
  memoryASet16(ds, 0x055f, ax);
  memoryASet16(ds, 0x0565, 0x0e03);
  memoryASet16(ds, 0x055d, 0x09da);
  sub_18375();
loc_17e8f:
  if (memoryAGet(ds, 0x0699) != 0x00)
    goto loc_17e97;
loc_17e96:
  return;
loc_17e97:
  goto loc_180a8;
loc_17e9a:
  if (memoryAGet(ds, 0x0571) != 0x00)
    goto loc_17ea4;
  goto loc_18053;
loc_17ea4:
  sub_181f9();
  if (!flags.carry)
    goto loc_17ec0;
  memoryASet(ds, 0x056e, 0x00);
  memoryASet(ds, 0x0576, 0x02);
  memoryASet(ds, 0x0571, 0x01);
  memoryASet(ds, 0x055b, 0x00);
  goto loc_17ef1;
  //   gap of 1 bytes
loc_17ec0:
  al = memoryAGet(ds, 0x0578);
  flags.carry = memoryAGet(ds, 0x0577) < al;
  memoryASet(ds, 0x0577, memoryAGet(ds, 0x0577) - al);
  if (!flags.carry)
    goto loc_17ef1;
  if (memoryAGet(ds, 0x0571) == 0x01)
    goto loc_17ee6;
  if (memoryAGet(ds, 0x0576) <= 0x01)
    goto loc_17ede;
  memoryASet(ds, 0x0576, memoryAGet(ds, 0x0576) - 1);
  goto loc_17ef1;
  //   gap of 1 bytes
loc_17ede:
  memoryASet(ds, 0x0571, 0x01);
  goto loc_17ef1;
  //   gap of 1 bytes
loc_17ee6:
  if (memoryAGet(ds, 0x0576) >= 0x04)
    goto loc_17ef1;
  memoryASet(ds, 0x0576, memoryAGet(ds, 0x0576) + 1);
loc_17ef1:
  if (memoryAGet(ds, 0x055a) != 0x00)
    goto loc_17f17;
  if (memoryAGet(ds, 0x055b) == 0x00)
    goto loc_17f05;
  memoryASet(ds, 0x055b, memoryAGet(ds, 0x055b) - 1);
  if (memoryAGet(ds, 0x055b) != 0)
    goto loc_17f17;
loc_17f05:
  if (memoryAGet(ds, 0x0571) != 0x01)
    goto loc_17f17;
  sub_18838();
  if (!flags.carry)
    goto loc_17f17;
  al = memoryAGet(ds, 0x057c);
  goto loc_17f59;
  //   gap of 1 bytes
loc_17f17:
  al = memoryAGet(ds, 0x057c);
  if (memoryAGet(ds, 0x0571) == 0x01)
    goto loc_17f36;
  flags.carry = al < memoryAGet(ds, 0x0576);
  al -= memoryAGet(ds, 0x0576);
  if (!flags.carry)
    goto loc_17f7f;
  al = 0;
  memoryASet(ds, 0x0571, 0x01);
  memoryASet(ds, 0x0576, 0x01);
  goto loc_17f7f;
  //   gap of 1 bytes
loc_17f36:
  al += memoryAGet(ds, 0x0576);
  if (al <= 0xe6)
    goto loc_17f7f;
  if (memoryAGet16(ds, 0x0004) != 0x0007)
    goto loc_17f52;
  if (al < 0xf8)
    goto loc_17f7f;
  al = 0xf8;
  memoryASet(ds, 0x0551, 0x01);
  goto loc_17f7f;
loc_17f52:
  al = 0xe6;
  memoryASet(ds, 0x0550, 0x00);
loc_17f59:
  memoryASet(ds, 0x0571, 0x00);
  memoryASet(ds, 0x0584, 0x00);
  memoryASet16(ds, 0x0572, 0x0002);
  memoryASet(ds, 0x055b, 0x00);
  memoryASet(ds, 0x055a, 0x00);
  if (memoryAGet(ds, 0x055c) == 0x00)
    goto loc_17f7f;
  push(ax);
  sub_1ccf2();
  ax = pop();
loc_17f7f:
  memoryASet(ds, 0x057c, al);
  flags.carry = al < 0x32;
  al -= 0x32;
  if (!flags.carry)
    goto loc_17f88;
  al = 0;
loc_17f88:
  memoryASet(ds, 0x057b, al);
  dl = memoryAGet(ds, 0x057b);
  cx = memoryAGet16(ds, 0x0579);
  sub_19ee0();
  memoryASet16(ds, 0x0563, ax);
  if (memoryAGet(ds, 0x0583) != 0x00)
    goto loc_17fa3;
  sub_18413();
loc_17fa3:
  sub_18daa();
  if (flags.carry)
    goto loc_17ff4;
  sub_19325();
  if (flags.carry)
    goto loc_17ff4;
  ax = memoryAGet16(ds, 0x0563);
  memoryASet16(ds, 0x055f, ax);
  if (memoryAGet(ds, 0x0584) == 0x00)
    goto loc_17fd1;
  memoryASet16(ds, 0x0585, memoryAGet16(ds, 0x0585) + 0x0002);
  bx = memoryAGet16(ds, 0x0585);
  bx &= 0x000e;
  ax = memoryAGet16(ds, bx + 4034);
  bx = memoryAGet16(ds, bx + 4050);
  goto loc_17fd8;
loc_17fd1:
  ax = memoryAGet16(ds, 0x0569);
  bx = memoryAGet16(ds, 0x0567);
loc_17fd8:
  memoryASet16(ds, 0x055d, ax);
  memoryASet16(ds, 0x0565, bx);
  al = 0x32;
  flags.carry = al < memoryAGet(ds, 0x057c);
  al -= memoryAGet(ds, 0x057c);
  if (al == 0)
    goto loc_1800e;
  if (flags.carry)
    goto loc_1800e;
  cx = 0x0168;
loc_17fec:
  if (--cx)
    goto loc_17fec;
  flags.carry = bh < al;
  bh -= al;
  if (bh == 0)
    goto loc_17ff4;
  if (!flags.carry)
    goto loc_17ffa;
loc_17ff4:
  memoryASet(ds, 0x0583, 0x01);
  return;
loc_17ffa:
  memoryASet16(ds, 0x0565, bx);
  ah = bl;
  ah <<= 1;
  mul(ah);
  ax += memoryAGet16(ds, 0x0569);
  memoryASet16(ds, 0x055d, ax);
  goto loc_1804f;
  //   gap of 1 bytes
loc_1800e:
  if (memoryAGet16(ds, 0x0004) != 0x0007)
    goto loc_1801e;
  al = memoryAGet(ds, 0x057b);
  flags.carry = al < 0xbb;
  al -= 0xbb;
  if (flags.carry)
    goto loc_1804f;
  if (!flags.carry)
    goto loc_1802c;
loc_1801e:
  if (memoryAGet(ds, 0x0550) != 0x02)
    goto loc_1804f;
  al = memoryAGet(ds, 0x057b);
  flags.carry = al < 0x5e;
  al -= 0x5e;
  if (flags.carry)
    goto loc_1804f;
loc_1802c:
  flags.carry = bh < al;
  bh -= al;
  if (bh == 0)
    goto loc_18032;
  if (!flags.carry)
    goto loc_18046;
loc_18032:
  if (memoryAGet16(ds, 0x0004) != 0x0007)
    goto loc_1803f;
  memoryASet(ds, 0x0551, 0x01);
  return;
loc_1803f:
  sub_1793d();
  sub_1cbfb();
  return;
loc_18046:
  memoryASet16(ds, 0x0565, bx);
  memoryASet(ds, 0x0576, 0x02);
loc_1804f:
  sub_18375();
  return;
loc_18053:
  if (memoryAGet16(ds, 0x0004) == 0x0007)
    goto loc_18061;
  if (memoryAGet(ds, 0x057b) >= 0xb4)
    goto loc_180a8;
loc_18061:
  sub_18838();
  if (flags.carry)
    goto loc_18073;
  memoryASet(ds, 0x056e, 0x00);
  memoryASet(ds, 0x0571, 0x01);
  goto loc_180e1;
  //   gap of 1 bytes
loc_18073:
  if (memoryAGet16(ds, 0x0004) != 0x0000)
    goto loc_180a8;
  sub_19527();
  if (flags.carry)
    goto loc_18086;
  memoryASet(ds, 0x056c, 0x00);
  goto loc_180a8;
loc_18086:
  if (memoryAGet(ds, 0x056c) != 0x00)
    goto loc_18090;
  sub_1cb4f();
loc_18090:
  memoryASet(ds, 0x0699, 0x01);
  memoryASet(ds, 0x056c, 0x01);
  sub_1a02d();
  dl &= 0x01;
  if (dl != 0)
    goto loc_180a4;
  dl = 0xff;
loc_180a4:
  memoryASet(ds, 0x0698, dl);
loc_180a8:
  al = memoryAGet(ds, 0x056e);
  memoryASet(ds, 0x056f, al);
  al = memoryAGet(ds, 0x0698);
  memoryASet(ds, 0x056e, al);
  al = memoryAGet(ds, 0x0699);
  memoryASet(ds, 0x0571, al);
  if (al != 0x00)
    goto loc_180c1;
  goto loc_18164;
loc_180c1:
  if (memoryAGet(ds, 0x0571) != 0x01)
    goto loc_180f9;
  if (memoryAGet(ds, 0x057b) < 0xb4)
    goto loc_180e1;
  memoryASet(ds, 0x0571, 0x00);
  memoryASet(ds, 0x0584, 0x00);
  memoryASet(ds, 0x0699, 0x00);
  goto loc_18164;
loc_180e1:
  ah = 0x01;
  al = 0x20;
  memoryASet(ds, 0x055b, 0x08);
  if (memoryAGet(ds, 0x0550) != 0x01)
    goto loc_18121;
  memoryASet(ds, 0x0550, 0x00);
  goto loc_18121;
  //   gap of 1 bytes
loc_180f9:
  memoryASet(ds, 0x055b, 0x00);
  ax = memoryAGet16(ds, 0x0572);
  bl = al;
  if (al <= 0x02)
    goto loc_18109;
  al -= 0x02;
loc_18109:
  memoryASet16(ds, 0x0572, ax);
  ah = 0x08;
  al = bl;
  al ^= 0x0f;
  cl = 0x04;
  al <<= cl;
  if (memoryAGet(ds, 0x0550) != 0x01)
    goto loc_18121;
  memoryASet(ds, 0x0550, memoryAGet(ds, 0x0550) + 1);
loc_18121:
  memoryASet(ds, 0x0578, al);
  memoryASet(ds, 0x0576, ah);
  memoryASet(ds, 0x0577, 0x01);
  memoryASet(ds, 0x055c, 0x00);
  bl = memoryAGet(ds, 0x056e);
  bl++;
  bl <<= 1;
  if (memoryAGet(ds, 0x0571) == 0xff)
    goto loc_18144;
  bl += 0x06;
loc_18144:
  bh = 0;
  ax = memoryAGet16(ds, bx + 4010);
  memoryASet16(ds, 0x0569, ax);
  ax = memoryAGet16(ds, bx + 4022);
  memoryASet16(ds, 0x0567, ax);
  memoryASet(ds, 0x39e0, 0x00);
  if (memoryAGet(ds, 0x127c) == 0x00)
    goto loc_18163;
  sub_1cb28();
loc_18163:
  return;
loc_18164:
  if (memoryAGet16(ds, 0x0004) == 0x0000)
    goto loc_18175;
  if (memoryAGet16(ds, 0x0004) == 0x0007)
    goto loc_18175;
  sub_1a675();
loc_18175:
  sub_181f9();
  dl = memoryAGet(ds, 0x057b);
  cx = memoryAGet16(ds, 0x0579);
  sub_19ee0();
  memoryASet16(ds, 0x0563, ax);
  al = memoryAGet(ds, 0x056e);
  al |= memoryAGet(ds, 0x0571);
  if (al)
    goto loc_18193;
  sub_18299();
  return;
loc_18193:
  sub_18250();
  memoryASet16(ds, 0x055d, bx);
  sub_18413();
  sub_18daa();
  if (flags.carry)
    return;
  sub_19325();
  if (flags.carry)
    return;
  ax = memoryAGet16(ds, 0x0563);
  memoryASet16(ds, 0x055f, ax);
  memoryASet16(ds, 0x0565, 0x0b03);
  sub_18375();
}
void sub_181b7()
{
  cx = 0x0b03;
  cl -= al;
  memoryASet16(ds, 0x0565, cx);
  if (ah == 0xff)
    goto loc_181d6;
  ah = 0;
  al <<= 1;
  memoryASet16(ds, 0x055d, memoryAGet16(ds, 0x055d) + ax);
  memoryASet16(ds, 0x0579, 0x0000);
  goto loc_181e4;
  //   gap of 1 bytes
loc_181d6:
  ah = 0;
  al <<= 1;
  al <<= 1;
  al <<= 1;
  ax += 0x0128;
  memoryASet16(ds, 0x0579, ax);
loc_181e4:
  push(ds);
  es = pop();
  si = memoryAGet16(ds, 0x055d);
  di = 0x000e;
  al = 0x03;
  sub_19fa0();
  memoryASet16(ds, 0x055d, 0x000e);
}
void sub_181f9()
{
  memoryASet16(ds, 0x05f6, 0x0008);
  memoryASet16(ds, 0x05f8, 0x0123);
  if (memoryAGet16(ds, 0x0004) != 0x0007)
    goto loc_18218;
  memoryASet16(ds, 0x05f6, 0x0024);
  memoryASet16(ds, 0x05f8, 0x010f);
loc_18218:
  ax = memoryAGet16(ds, 0x0579);
  if (memoryAGet(ds, 0x056e) < 0x01)
    goto loc_1824e;
  if (memoryAGet(ds, 0x056e) != 0x01)
    goto loc_18237;
  ax += memoryAGet16(ds, 0x0572);
  if (ax < memoryAGet16(ds, 0x05f8))
    goto loc_1824b;
  ax = memoryAGet16(ds, 0x05f8);
  ax--;
  memoryASet16(ds, 0x0579, ax);
  flags.carry = true;
  return;
loc_18237:
  flags.carry = ax < memoryAGet16(ds, 0x0572);
  ax -= memoryAGet16(ds, 0x0572);
  if (flags.carry)
    goto loc_18243;
  if (ax >= memoryAGet16(ds, 0x05f6))
    goto loc_1824b;
loc_18243:
  ax = memoryAGet16(ds, 0x05f6);
  memoryASet16(ds, 0x0579, ax);
  flags.carry = true;
  return;
loc_1824b:
  memoryASet16(ds, 0x0579, ax);
loc_1824e:
  flags.carry = false;
}
void sub_18250()
{
  al = memoryAGet(ds, 0x056e);
  if (al == memoryAGet(ds, 0x056f))
    goto loc_1825f;
  memoryASet16(ds, 0x0572, 0x0002);
loc_1825f:
  if (memoryAGet16(ds, 0x0572) >= 0x0008)
    goto loc_18275;
  memoryASet(ds, 0x0577, memoryAGet(ds, 0x0577) - 1);
  al = memoryAGet(ds, 0x0577);
  al &= 0x03;
  if (al != 0)
    goto loc_18275;
  memoryASet16(ds, 0x0572, memoryAGet16(ds, 0x0572) + 1);
loc_18275:
  bl = memoryAGet(ds, 0x056b);
  bl++;
  if (bl < 0x06)
    goto loc_18282;
  bl = 0x00;
loc_18282:
  memoryASet(ds, 0x056b, bl);
  if (memoryAGet(ds, 0x056e) != 0xff)
    goto loc_18290;
  bl += 0x06;
loc_18290:
  bl <<= 1;
  bh = 0;
  bx = memoryAGet16(ds, bx + 3962);
}
void sub_18299()
{
  memoryASet16(ds, 0x0572, 0x0002);
  memoryASet(ds, 0x0577, 0x08);
  if (memoryAGet16(ds, 0x0561) != 0x0c02)
    goto loc_182b7;
  memoryASet(ds, 0x056d, memoryAGet(ds, 0x056d) + 1);
  if (memoryAGet(ds, 0x056d) & 0x07)
    return;
loc_182b7:
  sub_18413();
  sub_18daa();
  if (flags.carry)
    return;
  sub_19325();
  if (flags.carry)
    return;
  sub_1a02d();
  bl = dl;
  bx &= 0x000e;
  si = memoryAGet16(ds, bx + 3986);
  ax = 0xb800;
  es = ax;
  di = memoryAGet16(ds, 0x055f);
  bp = 0x05fa;
  memoryASet16(ds, 0x0561, 0x0c02);
  cx = 0x0602;
  sub_19f65();
  sub_1a02d();
  bl = dl;
  bx &= 0x0006;
  si = memoryAGet16(ds, bx + 4002);
  di = memoryAGet16(ds, 0x055f);
  di += 0x00f0;
  bp = 0x0612;
  cx = 0x0602;
  sub_19f65();
  memoryASet(ds, 0x0583, 0x00);
}
void sub_1830d()
{
  memoryASet(ds, 0x055c, 0x00);
  memoryASet(ds, 0x0571, 0x01);
  memoryASet(ds, 0x0576, 0x02);
  memoryASet(ds, 0x0578, 0x01);
  memoryASet(ds, 0x0577, 0xff);
  memoryASet(ds, 0x056e, 0x00);
  memoryASet(ds, 0x055a, 0x01);
  ax = memoryAGet16(ds, 0x0fac);
  memoryASet16(ds, 0x0569, ax);
  ax = memoryAGet16(ds, 0x0fb8);
  memoryASet16(ds, 0x0567, ax);
  memoryASet(ds, 0x0550, 0x02);
}
void sub_18342()
{
  cx = memoryAGet16(ds, 0x0579);
  dl = memoryAGet(ds, 0x057b);
  sub_19ee0();
  memoryASet16(ds, 0x055f, ax);
  sub_18354();
}
void sub_18354()
{
  ax = 0x1010;
  es = ax;
  di = 0x05fa;
  push(ds);
  si = memoryAGet16(ds, 0x055f);
  ax = 0xb800;
  ds = ax;
  cx = memoryAGet16(es, 0x0561);
  sub_19ffa();
  ds = pop();
  memoryASet(ds, 0x0583, 0x00);
}
void sub_18375()
{
  ax = 0xb800;
  es = ax;
  di = memoryAGet16(ds, 0x055f);
  bp = 0x05fa;
  si = memoryAGet16(ds, 0x055d);
  cx = memoryAGet16(ds, 0x0565);
  memoryASet16(ds, 0x0561, cx);
  memoryASet(ds, 0x0583, 0x00);
  sub_19f65();
}
void sub_18396()
{
  dl = memoryAGet(ds, 0x057b);
  cx = memoryAGet16(ds, 0x0579);
  flags.carry = cx < 0x000c;
  cx -= 0x000c;
  if (!flags.carry)
    goto loc_183a5;
  cx = 0;
loc_183a5:
  if (cx < 0x010f)
    goto loc_183ae;
  cx = 0x010e;
loc_183ae:
  sub_19ee0();
  memoryASet16(ds, 0x0581, ax);
  di = ax;
  ax = 0xb800;
  es = ax;
  bp = 0x000e;
  si = 0x1679;
  cx = 0x1205;
  sub_19efc();
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x057f, dx);
  memoryASet16(ds, 0x5a3c, 0x0000);
  memoryASet16(ds, 0x5a3e, 0x0000);
loc_183db:
  sub_1cc4c();
  ah = 0;
  interrupt(0x1a);
  dx -= memoryAGet16(ds, 0x057f);
  if (dx < 0x000a)
    goto loc_183db;
  sub_1cd51();
  di = memoryAGet16(ds, 0x0581);
  si = 0x000e;
  cx = 0x1205;
  memoryASet(ds, 0x0583, 0x00);
  sub_19fcd();
  if (memoryAGet(ds, 0x1678) == 0x00)
    return;
  if (memoryAGet(ds, 0x1f80) == 0x00)
    return;
  memoryASet(ds, 0x1f80, memoryAGet(ds, 0x1f80) - 1);
}
void sub_18413()
{
  ax = 0xb800;
  es = ax;
  di = memoryAGet16(ds, 0x055f);
  si = 0x05fa;
  cx = memoryAGet16(ds, 0x0561);
  sub_19fcd();
}
void sub_18430()
{
  ah = 0;
  interrupt(0x1a);
  ax = dx;
  ax -= memoryAGet16(ds, 0x069f);
  if (ax >= 0x0002)
    goto loc_18440;
  return;
loc_18440:
  memoryASet16(ds, 0x069f, dx);
  if (memoryAGet(ds, 0x069b) != 0x00)
    goto loc_1845e;
  sub_184f1();
    sync();
//  sub_185e7();
//  dx = ax;
//loc_18453:
//  sub_185e7();
//  ax -= dx;
//  if (ax < 0xf8ed)
//    goto loc_18453;
  return;
loc_1845e:
  dx = 0x0201;
  in(al, dx);
  al &= 0x10;
  memoryASet(ds, 0x069a, al);
  memoryASet(ds, 0x069e, 0x03);
  sub_185e7();
  memoryASet16(ds, 0x069c, ax);
  out(dx, al);
  cx = 0x07d0;
loc_18476:
  in(al, dx);
  if (al & 0x01)
    goto loc_1848e;
  if (!(memoryAGet(ds, 0x069e) & 0x01))
    goto loc_1848e;
  memoryASet(ds, 0x069e, memoryAGet(ds, 0x069e) & 0xfe);
  sub_184d1();
  memoryASet(ds, 0x0698, bl);
loc_1848e:
  if (al & 0x02)
    goto loc_184a5;
  if (!(memoryAGet(ds, 0x069e) & 0x02))
    goto loc_184a5;
  memoryASet(ds, 0x069e, memoryAGet(ds, 0x069e) & 0xfd);
  sub_184d1();
  memoryASet(ds, 0x0699, bl);
loc_184a5:
  if (!(memoryAGet(ds, 0x069e) & 0x03))
    return;
  sub_185e7();
  ax -= memoryAGet16(ds, 0x069c);
  if (--cx && ax != 0x1964)
    goto loc_18476;
  if (!(memoryAGet(ds, 0x069e) & 0x01))
    goto loc_184c4;
  memoryASet(ds, 0x0698, 0xff);
loc_184c4:
  if (!(memoryAGet(ds, 0x069e) & 0x02))
    return;
  memoryASet(ds, 0x0699, 0xff);
}
void sub_184d1()
{
  push(ax);
  sub_185e7();
  ax -= memoryAGet16(ds, 0x069c);
  bx = ax;
  ax = pop();
  if (bx >= 0xf5e6)
    goto loc_184e5;
  bl = 0x01;
  return;
loc_184e5:
  if (bx >= 0xfafa)
    goto loc_184ee;
  bl = 0;
  return;
loc_184ee:
  bl = 0xff;
}
void sub_184f1()
{
  al = memoryAGet(ds, 0x06ba);
  if (memoryAGet(ds, 0x0697) == 0xfd)
    goto loc_18503;
  al &= memoryAGet(ds, 0x06bd);
  al &= memoryAGet(ds, 0x06be);
loc_18503:
  al ^= 0x80;
  if (!al)
    goto loc_18509;
  al = 0x01;
loc_18509:
  memoryASet(ds, 0x0699, al);
  al = memoryAGet(ds, 0x06b8);
  if (memoryAGet(ds, 0x0697) == 0xfd)
    goto loc_1851e;
  al &= memoryAGet(ds, 0x06bc);
  al &= memoryAGet(ds, 0x06bf);
loc_1851e:
  al ^= 0x80;
  if (!al)
    goto loc_18527;
  memoryASet(ds, 0x0699, 0xff);
loc_18527:
  al = memoryAGet(ds, 0x06b9);
  if (memoryAGet(ds, 0x0697) == 0xfd)
    goto loc_18539;
  al &= memoryAGet(ds, 0x06bc);
  al &= memoryAGet(ds, 0x06bd);
loc_18539:
  al ^= 0x80;
  if (!al)
    goto loc_1853f;
  al = 0x01;
loc_1853f:
  memoryASet(ds, 0x0698, al);
  al = memoryAGet(ds, 0x06bb);
  if (memoryAGet(ds, 0x0697) == 0xfd)
    goto loc_18554;
  al &= memoryAGet(ds, 0x06be);
  al &= memoryAGet(ds, 0x06bf);
loc_18554:
  al ^= 0x80;
  if (!al)
    goto loc_1855d;
  memoryASet(ds, 0x0698, 0xff);
loc_1855d:
  al = memoryAGet(ds, 0x06b7);
  cl = 0x03;
  al >>= cl;
  memoryASet(ds, 0x069a, al);
}
void sub_18568()
{
  ax = memoryAGet16(ds, 0x0693);
  if (ax == memoryAGet16(ds, 0x0691))
    goto loc_18587;
  memoryASet16(ds, 0x0691, ax);
  if (memoryAGet(ds, 0x06c0) & 0x80)
    goto loc_18588;
  ax = memoryAGet16(ds, 0x0693);
  if (ax == memoryAGet16(ds, 0x6e00))
    goto loc_18587;
  sub_1d0a0();
loc_18587:
  return;
loc_18588:
  if (!(memoryAGet(ds, 0x06c9) & 0x80))
    goto loc_18590;
  return;
loc_18590:
  if (memoryAGet(ds, 0x06cc) & 0x80)
    goto loc_1859d;
  memoryASet(ds, 0x1f80, 0x09);
  return;
loc_1859d:
  if (!(memoryAGet(ds, 0x06c1) & 0x80))
    goto loc_185d5;
  if (memoryAGet(ds, 0x06cb) & 0x80)
    goto loc_185b1;
  memoryASet(ds, 0x041c, 0xff);
  return;
loc_185b1:
  if (memoryAGet(ds, 0x06c8) & 0x80)
    goto loc_185be;
  memoryASet(ds, 0x041b, 0xff);
  return;
loc_185be:
  if (memoryAGet(ds, 0x06c7) & 0x80)
    goto loc_185d4;
  memoryASet(ds, 0x0000, ~memoryAGet(ds, 0x0000));
  if (memoryAGet(ds, 0x0000) != 0x00)
    goto loc_185d3;
  sub_1cd51();
loc_185d3:
  return;
loc_185d4:
  return;
loc_185d5:
  sub_186af();
  ax = pop();
}
void sub_185da()
{
  ax = 0xf000;
  es = ax;
  al = memoryAGet(es, 0xfffe);
  memoryASet(ds, 0x0697, al);
}
void sub_185e7()
{
    sync();
        struct timespec ts;
        unsigned theTick = 0U;
        clock_gettime( CLOCK_REALTIME, &ts );
        theTick  = ts.tv_nsec / 1000000;
        theTick += ts.tv_sec * 1000;
    ax = theTick*1193;
//  al = 0x00;
//  out(0x0043, al);
//  in(al, 0x40);
//  ah = al;
//  in(al, 0x40);
//  tl = ah;
//  ah = al;
//  al = tl;
}
void sub_18608()
{
  dx = 0x03da;
  in(al, dx);
  al &= 0x08;
  flags.zero = al == 0;
}
void sub_18618()
{
  push(ax);
  push(es);
  push(di);
  push(cx);
  ax = 0x1010;
  es = ax;
  flags.direction = false;
  di = 0x06b7;
  cx = 0x0016;
  al = 0x80;
  rep_stosb<MemAuto, DirAuto>();
  ax = memoryAGet16(es, 0x0693);
  ax -= 0x0070;
  memoryASet16(es, 0x0691, ax);
  ax = 0x0040;
  es = ax;
  al = memoryAGet(es, 0x0012);
  memoryASet(cs, 0x13e7, al);
  cx = pop();
  di = pop();
  es = pop();
  ax = pop();
}
void sub_18649()
{
  ax = 0;
  es = ax;
  ax = memoryAGet16(es, 0x0024);
  bx = memoryAGet16(es, 0x0026);
  cx = memoryAGet16(es, 0x0120);
  dx = memoryAGet16(es, 0x0122);
  memoryASet16(cs, 0x13df, ax);
  memoryASet16(cs, 0x13e1, bx);
  memoryASet16(cs, 0x13e3, cx);
  memoryASet16(cs, 0x13e5, dx);
  bx = 0x14b3;
  if (memoryAGet(ds, 0x0697) != 0xfd)
    goto loc_18680;
  bx = 0x14fb;
loc_18680:
  flags.interrupts = false;
  memoryASet16(es, 0x0024, bx);
  memoryASet16(es, 0x0026, cs);
  if (memoryAGet(ds, 0x0697) != 0xfd)
    goto loc_186ad;
  memoryASet16(es, 0x0120, 0x1554);
  memoryASet16(es, 0x0122, cs);
  ax = 0x0040;
  es = ax;
  al = memoryAGet(es, 0x0018);
  al |= 0x01;
  memoryASet(es, 0x0018, al);
loc_186ad:
  flags.interrupts = true;
}
void sub_186af()
{
  ax = 0;
  es = ax;
  ax = memoryAGet16(cs, 0x13df);
  bx = memoryAGet16(cs, 0x13e1);
  cx = memoryAGet16(cs, 0x13e3);
  dx = memoryAGet16(cs, 0x13e5);
  flags.interrupts = false;
  memoryASet16(es, 0x0024, ax);
  memoryASet16(es, 0x0026, bx);
  if (memoryAGet(ds, 0x0697) != 0xfd)
    goto loc_186e1;
  memoryASet16(es, 0x0120, cx);
  memoryASet16(es, 0x0122, dx);
loc_186e1:
  flags.interrupts = true;
}
void sub_18800()
{
  bx = memoryAGet16(ds, 0x0008);
  cl = memoryAGet(ds, bx + 4110);
loc_18808:
  sub_1a02d();
  dl &= 0x07;
  if (dl > cl)
    goto loc_18808;
  dl += memoryAGet(ds, bx + 4102);
  if (dl == memoryAGet(ds, 0x1028))
    goto loc_18808;
  memoryASet(ds, 0x1028, dl);
  bl = dl;
  cl = memoryAGet(ds, bx + 4080);
  dl = 0x88;
  if (cl & 0x80)
    goto loc_1882f;
  dl = 0x90;
loc_1882f:
  cx &= 0x007f;
  cx <<= 1;
  cx <<= 1;
}
// INJECT: Error: cannot inject carry flag in sub_18838()!
// INJECT: Error: cannot inject carry flag in sub_18838()!
// INJECT: Error: cannot inject carry flag in sub_18838()!
void sub_18838()
{
  if (memoryAGet16(ds, 0x0004) != 0x0007)
    goto loc_18843;
  sub_1a32a();
  stop(/*inject ret*/);
  return;
loc_18843:
  if (memoryAGet16(ds, 0x0004) == 0x0000)
    goto loc_1884e;
  sub_188f6();
  stop(/*inject ret*/);
  return;
loc_1884e:
  al = memoryAGet(ds, 0x057b);
  al &= 0xf8;
  if (al == 0x60)
    goto loc_18860;
  sub_18887();
  if (flags.carry)
    return;
  sub_189dd();
  return;
loc_18860:
  if (memoryAGet(ds, 0x0550) >= 0x02)
    goto loc_18885;
  memoryASet(ds, 0x057b, al);
  al += 0x32;
  memoryASet(ds, 0x057c, al);
  if (memoryAGet(ds, 0x0550) == 0x01)
    goto loc_18883;
  memoryASet(ds, 0x0550, 0x01);
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x0556, dx);
loc_18883:
  flags.carry = true;
  return;
loc_18885:
  flags.carry = false;
}
void sub_18887()
{
  cl = memoryAGet(ds, 0x057b);
  cl += 0x02;
  cl &= 0xf8;
  bx = memoryAGet16(ds, 0x0008);
  bl = memoryAGet(ds, bx + 4102);
loc_18899:
  al = memoryAGet(ds, bx + 4080);
  if (al != 0x00)
    goto loc_188a8;
  memoryASet(ds, 0x127c, 0x00);
  flags.carry = false;
  return;
loc_188a8:
  bx++;
  ch = 0x88;
  if (al & 0x80)
    goto loc_188b1;
  ch = 0x90;
loc_188b1:
  if (cl != ch)
    goto loc_18899;
  ax &= 0x007f;
  ax <<= 1;
  ax <<= 1;
  dx = memoryAGet16(ds, 0x0579);
  dx &= 0xfff8;
  if (dx < ax)
    goto loc_18899;
  dx = memoryAGet16(ds, 0x0579);
  dx -= 0x000f;
  dx &= 0xfff8;
  if (dx > ax)
    goto loc_18899;
  ch -= 0x02;
  memoryASet(ds, 0x057b, ch);
  ch += 0x32;
  memoryASet(ds, 0x057c, ch);
  if (memoryAGet(ds, 0x127c) != 0x00)
    goto loc_188f4;
  memoryASet(ds, 0x127c, 0x01);
  sub_1cb3e();
loc_188f4:
  flags.carry = true;
}
void sub_188f6()
{
  memoryASet(ds, 0x39e0, 0x00);
  if (memoryAGet(ds, 0x0571) != 0x01)
    goto loc_1892c;
  ax = memoryAGet16(ds, 0x2650);
  ax -= 0x0004;
  dl = memoryAGet(ds, 0x2652);
  dl -= 0x08;
  si = 0x000c;
  bx = memoryAGet16(ds, 0x0579);
  dh = memoryAGet(ds, 0x057b);
  di = 0x0018;
  cx = 0x0e10;
  sub_1a059();
  if (!flags.carry)
    goto loc_1892c;
  memoryASet(ds, 0x0551, 0x01);
  flags.carry = false;
  return;
loc_1892c:
  if (memoryAGet16(ds, 0x0004) != 0x0003)
    goto loc_1893e;
  sub_1ae73();
  if (!flags.carry)
    goto loc_1893e;
  memoryASet(ds, 0x055c, 0x01);
  return;
loc_1893e:
  cl = memoryAGet(ds, 0x057b);
  cl &= 0xf8;
  bx = memoryAGet16(ds, 0x0004);
  bx <<= 1;
  bx = memoryAGet16(ds, bx + 4713);
loc_1894f:
  ch = memoryAGet(ds, bx + 4137);
  if (ch != 0x00)
    goto loc_1895a;
  flags.carry = false;
  return;
loc_1895a:
  al = memoryAGet(ds, bx + 4233);
  memoryASet(ds, 0x127b, al);
  bl <<= 1;
  ax = memoryAGet16(ds, bx + 4521);
  memoryASet16(ds, 0x1279, ax);
  ax = memoryAGet16(ds, bx + 4329);
  bl >>= 1;
  bx++;
  if (cl != ch)
    goto loc_1894f;
  dx = memoryAGet16(ds, 0x0579);
  dx &= 0xfff8;
  if (dx < ax)
    goto loc_1894f;
  dx = memoryAGet16(ds, 0x0579);
  flags.carry = dx < memoryAGet16(ds, 0x1279);
  dx -= memoryAGet16(ds, 0x1279);
  if (!flags.carry)
    goto loc_1898d;
  dx = 0;
loc_1898d:
  dx &= 0xfffc;
  if (dx > ax)
    goto loc_1894f;
  memoryASet(ds, 0x057b, ch);
  ch += 0x32;
  memoryASet(ds, 0x057c, ch);
  al = memoryAGet(ds, 0x127b);
  memoryASet(ds, 0x055c, al);
  if (al == 0x00)
    goto loc_189b0;
  memoryASet16(ds, 0x0579, memoryAGet16(ds, 0x0579) & 0xfffc);
loc_189b0:
  if (memoryAGet16(ds, 0x0004) != 0x0004)
    goto loc_189c7;
  bx--;
  flags.carry = bx < 0x0027;
  bx -= 0x0027;
  if (flags.carry)
    goto loc_189c7;
  if (bx >= 0x0010)
    goto loc_189c7;
  bx++;
  memoryASet(ds, 0x39e0, bl);
loc_189c7:
  flags.carry = true;
}
void sub_189c9()
{
  cl = 0x03;
  bx >>= cl;
  ch = bl;
  cl = 0x03;
  bx >>= cl;
  cl = ch;
  cl &= 0x07;
  ch = 0x80;
  ch >>= cl;
}
void sub_189dd()
{
  dl = memoryAGet(ds, 0x057b);
  dl &= 0xf8;
  bx = 0;
  if (dl == 0x08)
    goto loc_189f9;
  bl++;
  if (dl == 0x28)
    goto loc_189f9;
  bl++;
  if (dl != 0x48)
    goto loc_18a40;
loc_189f9:
  ax = memoryAGet16(ds, 0x0579);
  if (bx != memoryAGet16(ds, 0x052f))
    goto loc_18a2c;
  if (memoryAGet(ds, 0x0525) > 0x03)
    goto loc_18a2c;
  if (bl == 0x01)
    goto loc_18a1e;
  cx = 0x0004;
  cl -= memoryAGet(ds, 0x0525);
  cl <<= 1;
  cl <<= 1;
  ax += cx;
  goto loc_18a2c;
  //   gap of 1 bytes
loc_18a1e:
  ch = 0;
  cl = memoryAGet(ds, 0x0525);
  cl++;
  cl <<= 1;
  cl <<= 1;
  ax -= cx;
loc_18a2c:
  bl = memoryAGet(ds, bx + 4133);
  si = bx;
  bx = ax;
  bx += 0x000a;
  sub_189c9();
  if (memoryAGet(ds, bx + si + 4118) & ch)
    goto loc_18a42;
loc_18a40:
  flags.carry = false;
  return;
loc_18a42:
  memoryASet(ds, 0x057b, dl);
  dl += 0x32;
  memoryASet(ds, 0x057c, dl);
  memoryASet16(ds, 0x0579, memoryAGet16(ds, 0x0579) & 0xfff8);
  memoryASet(ds, 0x055c, 0x01);
  flags.carry = true;
}
void sub_18a60()
{
  memoryASet(ds, 0x1665, 0x00);
  memoryASet(ds, 0x1673, 0x00);
  memoryASet(ds, 0x1677, 0x00);
  memoryASet(ds, 0x1678, 0x00);
  memoryASet16(ds, 0x166c, 0x0009);
}
void sub_18a7b()
{
  if (memoryAGet(ds, 0x1673) == 0x00)
    goto loc_18a8c;
  ah = 0;
  interrupt(0x1a);
  if (dx != memoryAGet16(ds, 0x17ec))
    goto loc_18a8d;
loc_18a8c:
  return;
loc_18a8d:
  memoryASet16(ds, 0x17ec, dx);
  if (memoryAGet(ds, 0x1677) == 0x00)
    goto loc_18aaf;
  ax = memoryAGet16(ds, 0x1671);
  ax &= 0xfff8;
  bx = memoryAGet16(ds, 0x0579);
  bx &= 0xfff8;
  if (ax != bx)
    goto loc_18aaf;
  memoryASet(ds, 0x1674, 0x00);
loc_18aaf:
  memoryASet(ds, 0x17e9, memoryAGet(ds, 0x17e9) + 1);
  if (memoryAGet16(ds, 0x17ea) > 0x0001)
    goto loc_18abe;
  memoryASet16(ds, 0x17ea, memoryAGet16(ds, 0x17ea) - 1);
loc_18abe:
  ax = memoryAGet16(ds, 0x1671);
  dx = memoryAGet16(ds, 0x17ea);
  cl = 0x03;
  dl >>= cl;
  if (memoryAGet(ds, 0x1674) < 0x01)
    goto loc_18ae5;
  if (memoryAGet(ds, 0x1674) != 0x01)
    goto loc_18adf;
  ax += dx;
  if (ax < 0x012f)
    goto loc_18ae5;
  ax = 0x012e;
  goto loc_18ae5;
  //   gap of 1 bytes
loc_18adf:
  flags.carry = ax < dx;
  ax -= dx;
  if (!flags.carry)
    goto loc_18ae5;
  ax = 0;
loc_18ae5:
  memoryASet16(ds, 0x1671, ax);
  bx = memoryAGet16(ds, 0x17df);
  al = memoryAGet(ds, 0x17e9);
  al >>= 1;
  al += memoryAGet(ds, 0x1673);
  dl = al;
  flags.carry = al < memoryAGet(ds, 0x1676);
  al -= memoryAGet(ds, 0x1676);
  if (flags.carry)
    goto loc_18b11;
  flags.carry = bh < al;
  bh -= al;
  if (bh == 0)
    goto loc_18b03;
  if (!flags.carry)
    goto loc_18b11;
loc_18b03:
  memoryASet(ds, 0x1673, 0x00);
  memoryASet(ds, 0x1678, 0x00);
  sub_18b52();
loc_18b10:
  return;
loc_18b11:
  memoryASet(ds, 0x1673, dl);
  cx = memoryAGet16(ds, 0x1671);
  memoryASet16(ds, 0x17e1, bx);
  sub_19ee0();
  memoryASet16(ds, 0x17e7, ax);
  if (memoryAGet(ds, 0x17e9) == 0x02)
    goto loc_18b2d;
  sub_18b52();
loc_18b2d:
  sub_18daa();
  if (flags.carry)
    goto loc_18b10;
  di = memoryAGet16(ds, 0x17e7);
  memoryASet16(ds, 0x17e5, di);
  cx = memoryAGet16(ds, 0x17e1);
  memoryASet16(ds, 0x17e3, cx);
  ax = 0xb800;
  es = ax;
  si = memoryAGet16(ds, 0x17dd);
  bp = 0x17ee;
  sub_19efc();
}
void sub_18b52()
{
  ax = 0xb800;
  es = ax;
  di = memoryAGet16(ds, 0x17e5);
  si = 0x17ee;
  cx = memoryAGet16(ds, 0x17e3);
  sub_19fcd();
}
void sub_18b66()
{
  memoryASet(ds, 0x166a, memoryAGet(ds, 0x166a) - 1);
  if (memoryAGet(ds, 0x166a) == 0)
    goto loc_18b6d;
loc_18b6c:
  return;
loc_18b6d:
  memoryASet(ds, 0x166a, 0x0d);
  sub_18608();
  if (!flags.zero)
    goto loc_18b6c;
  if (memoryAGet(ds, 0x1665) == 0x00)
    goto loc_18b81;
  sub_18d35();
loc_18b81:
  if (memoryAGet(ds, 0x1673) != 0x00)
    goto loc_18b6c;
  if (memoryAGet(ds, 0x1665) != 0x00)
    goto loc_18bfd;
  if (memoryAGet(ds, 0x057b) > 0x60)
    goto loc_18b6c;
  memoryASet(ds, 0x1677, 0x00);
  if (memoryAGet(ds, 0x0550) != 0x01)
    goto loc_18bba;
  if (memoryAGet(ds, 0x0418) != 0x00)
    goto loc_18bba;
  ah = 0;
  interrupt(0x1a);
  dx -= memoryAGet16(ds, 0x0556);
  if (dx < 0x0048)
    goto loc_18bba;
  memoryASet(ds, 0x1677, memoryAGet(ds, 0x1677) + 1);
loc_18bba:
  sub_1a02d();
  if (memoryAGet(ds, 0x1677) == 0x00)
    goto loc_18bca;
  dl &= 0x03;
  goto loc_18bd2;
  //   gap of 1 bytes
loc_18bca:
  dl &= 0x0f;
  if (dl >= 0x0c)
    goto loc_18b6c;
loc_18bd2:
  memoryASet(ds, 0x1669, dl);
  sub_18d1a();
  memoryASet16(ds, 0x1666, cx);
  memoryASet(ds, 0x1668, dl);
  sub_18d35();
  if (flags.carry)
    goto loc_18bba;
  memoryASet(ds, 0x1665, 0x1d);
  bx = memoryAGet16(ds, 0x0008);
  bl <<= 1;
  ax = memoryAGet16(ds, bx + 6174);
  memoryASet16(ds, 0x166c, ax);
  memoryASet(ds, 0x1670, 0x01);
loc_18bfd:
  sub_18d35();
  if (flags.carry)
    goto loc_18c10;
  memoryASet(ds, 0x1664, 0x00);
  sub_18d7c();
  if (!flags.carry)
    goto loc_18c11;
  memoryASet(ds, 0x1664, memoryAGet(ds, 0x1664) + 1);
loc_18c10:
  return;
loc_18c11:
  if (memoryAGet(ds, 0x1665) != 0x10)
    goto loc_18c20;
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x166e, dx);
loc_18c20:
  if (memoryAGet(ds, 0x1665) != 0x0f)
    goto loc_18ca6;
  ah = 0;
  interrupt(0x1a);
  dx -= memoryAGet16(ds, 0x166e);
  if (dx >= memoryAGet16(ds, 0x166c))
    goto loc_18ca6;
  if (memoryAGet(ds, 0x1670) == 0x00)
    goto loc_18ca5;
  if (memoryAGet(ds, 0x1673) != 0x00)
    goto loc_18ca5;
  if (memoryAGet(ds, 0x0418) != 0x00)
    goto loc_18ca5;
  memoryASet(ds, 0x1670, memoryAGet(ds, 0x1670) - 1);
  memoryASet(ds, 0x1678, 0x01);
  al = memoryAGet(ds, 0x1668);
  memoryASet(ds, 0x1673, al);
  sub_1a02d();
  dx &= 0x000f;
  dx += memoryAGet16(ds, 0x1666);
  memoryASet16(ds, 0x1671, dx);
  al = 0x01;
  if (dx < memoryAGet16(ds, 0x0579))
    goto loc_18c72;
  al = 0xff;
loc_18c72:
  memoryASet(ds, 0x1674, al);
  sub_1a02d();
  bl = dl;
  bx &= 0x0006;
  ax = memoryAGet16(ds, bx + 6089);
  memoryASet16(ds, 0x17dd, ax);
  ax = memoryAGet16(ds, bx + 6097);
  memoryASet16(ds, 0x17df, ax);
  bl >>= 1;
  al = memoryAGet(ds, bx + 6105);
  memoryASet(ds, 0x1676, al);
  memoryASet16(ds, 0x17ea, 0x0020);
  memoryASet(ds, 0x17e9, 0x01);
  memoryASet(ds, 0x1675, 0x00);
loc_18ca5:
  return;
loc_18ca6:
  memoryASet(ds, 0x1665, memoryAGet(ds, 0x1665) - 1);
  cx = memoryAGet16(ds, 0x1666);
  dl = memoryAGet(ds, 0x1668);
  if (memoryAGet(ds, 0x1665) <= 0x0e)
    goto loc_18cc3;
  dl += memoryAGet(ds, 0x1665);
  dl -= 0x0e;
  goto loc_18cca;
  //   gap of 1 bytes
loc_18cc3:
  dl += 0x0e;
  dl -= memoryAGet(ds, 0x1665);
loc_18cca:
  memoryASet(ds, 0x166b, dl);
  sub_19ee0();
  di = ax;
  ax = 0xb800;
  es = ax;
  flags.direction = false;
  cx = 0x0004;
  if (memoryAGet(ds, 0x1665) <= 0x0e)
    goto loc_18d07;
  if (memoryAGet(ds, 0x0418) == 0x00)
    goto loc_18d02;
  al = memoryAGet(ds, 0x166b);
  al -= memoryAGet(ds, 0x1668);
  ah = 0;
  cl = 0x03;
  ax <<= cl;
  ax += 0x15e0;
  si = ax;
  cx = 0x0004;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  return;
loc_18d02:
  ax = 0;
  rep_stosw<MemAuto, DirAuto>();
  return;
loc_18d07:
  al = memoryAGet(ds, 0x166b);
  al -= memoryAGet(ds, 0x1668);
  ah = 0x0a;
  mul(ah);
  ax += 0x2681;
  si = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
}
void sub_18d1a()
{
  bh = 0;
  bl = dl;
  bl &= 0x03;
  bl <<= 1;
  cx = memoryAGet16(ds, bx + 5720);
  bl = dl;
  bl >>= 1;
  bl >>= 1;
  bl &= 0x03;
  dl = memoryAGet(ds, bx + 5728);
}
void sub_18d35()
{
  ax = memoryAGet16(ds, 0x1666);
  dl = memoryAGet(ds, 0x1668);
  bx = memoryAGet16(ds, 0x0579);
  dh = memoryAGet(ds, 0x057b);
  si = 0x0020;
  di = 0x0018;
  cx = 0x0e0f;
  sub_1a059();
  if (!flags.carry)
    return;
  if (memoryAGet(ds, 0x0571) != 0x01)
    goto loc_18d7a;
  if (memoryAGet(ds, 0x055a) != 0x00)
    goto loc_18d7a;
  if (memoryAGet(ds, 0x057b) >= 0x60)
    goto loc_18d7a;
  if (memoryAGet(ds, 0x1665) < 0x05)
    goto loc_18d7a;
  if (memoryAGet(ds, 0x1665) >= 0x19)
    goto loc_18d7a;
  memoryASet(ds, 0x0551, 0x01);
loc_18d7a:
  flags.carry = true;
}
void sub_18d7c()
{
  al = memoryAGet(ds, 0x1669);
  if (al >= 0x08)
    goto loc_18da8;
  bx = 0x0002;
  if (!(al & 0x04))
    goto loc_18d8c;
  bl <<= 1;
loc_18d8c:
  ax = memoryAGet16(ds, bx + 7984);
  ax += 0x0010;
  if (ax < memoryAGet16(ds, 0x1666))
    goto loc_18da8;
  flags.carry = ax < 0x0030;
  ax -= 0x0030;
  if (!flags.carry)
    goto loc_18da0;
  ax = 0;
loc_18da0:
  if (ax > memoryAGet16(ds, 0x1666))
    goto loc_18da8;
  flags.carry = true;
  return;
loc_18da8:
  flags.carry = false;
}
void sub_18daa()
{
  if (memoryAGet16(ds, 0x0004) != 0x0000)
    goto loc_18e11;
  dl = memoryAGet(ds, 0x1673);
  if (dl == 0x00)
    goto loc_18e11;
  cx = memoryAGet16(ds, 0x17df);
  tl = ch;
  ch = cl;
  cl = tl;
  si = 0x0010;
  ax = memoryAGet16(ds, 0x1671);
  bx = memoryAGet16(ds, 0x0579);
  dh = memoryAGet(ds, 0x057b);
  di = 0x0018;
  ch = 0x0e;
  sub_1a059();
  if (!flags.carry)
    return;
  sub_18413();
  sub_18b52();
  sub_1830d();
  if (memoryAGet(ds, 0x1675) != 0x00)
    goto loc_18e0f;
  memoryASet(ds, 0x1675, 0x01);
  sub_18396();
  dl = 0x01;
  if (memoryAGet(ds, 0x1674) == 0xff)
    goto loc_18dfb;
  dl = 0xff;
loc_18dfb:
  memoryASet(ds, 0x1674, dl);
  memoryASet16(ds, 0x17ea, 0x0060);
  memoryASet(ds, 0x17e9, 0x01);
  memoryASet(ds, 0x055c, 0x00);
loc_18e0f:
  flags.carry = true;
  return;
loc_18e11:
  flags.carry = false;
}
void sub_18e20()
{
  bx = 0;
  ah = 0x0b;
  interrupt(0x10);
  if (memoryAGet16(ds, 0x0006) != 0x0007)
    goto loc_18e42;
  if (memoryAGet(ds, 0x0553) == 0x00)
    goto loc_18e42;
  sub_1c4bb();
  memoryASet16(ds, 0x0579, 0x0098);
  memoryASet(ds, 0x057b, 0x5f);
loc_18e42:
  ax = 0xb800;
  es = ax;
  flags.direction = false;
  memoryASet16(ds, 0x1839, 0x0000);
  sub_18e97();
  sub_1cd51();
  sub_18f61();
  if (memoryAGet16(ds, 0x0004) != 0x0000)
    goto loc_18e79;
  if (memoryAGet(ds, 0x0553) == 0x00)
    goto loc_18e76;
  if (memoryAGet16(ds, 0x0006) != 0x0007)
    goto loc_18e71;
  sub_1c543();
  goto loc_18e79;
loc_18e71:
  sub_1aae0();
  goto loc_18e79;
loc_18e76:
  sub_18fa6();
loc_18e79:
  if (memoryAGet16(ds, 0x0004) == 0x0007)
    goto loc_18e8a;
  ax = 0xaaaa;
  if (memoryAGet16(ds, 0x0004) != 0x0002)
    goto loc_18e8d;
loc_18e8a:
  ax = 0x5555;
loc_18e8d:
  memoryASet16(ds, 0x1839, ax);
  sub_18e97();
  sub_1cd51();
}
void sub_18e97()
{
  sub_1cac6();
  memoryASet16(ds, 0x1835, 0x0001);
  memoryASet(ds, 0x1837, 0x08);
  cx = memoryAGet16(ds, 0x0579);
  dl = memoryAGet(ds, 0x057b);
  cx += 0x000c;
  cx &= 0xfff0;
  dl += 0x08;
  memoryASet(ds, 0x1838, 0x00);
loc_18ebc:
  sub_1cac7();
  memoryASet16(ds, 0x1832, cx);
  memoryASet(ds, 0x1834, dl);
  sub_19ee0();
  di = ax;
  bl = memoryAGet(ds, 0x1837);
loc_18ed0:
  ax = memoryAGet16(ds, 0x1839);
  cx = memoryAGet16(ds, 0x1835);
  cx >>= 1;
  cx >>= 1;
  cx >>= 1;
  rep_stosw<MemAuto, DirAuto>();
  cx = memoryAGet16(ds, 0x1835);
  cx >>= 1;
  cx >>= 1;
  cx &= 0x00fe;
  di -= cx;
  di ^= 0x2000;
  if (di & 0x2000)
    goto loc_18efa;
  di += 0x0050;
loc_18efa:
  bl--;
  if (bl != 0)
    goto loc_18ed0;
  if (memoryAGet(ds, 0x1838) != 0x0f)
    goto loc_18f06;
  return;
loc_18f06:
  memoryASet16(ds, 0x1835, memoryAGet16(ds, 0x1835) + 0x0020);
  memoryASet(ds, 0x1837, memoryAGet(ds, 0x1837) + 0x10);
  cx = memoryAGet16(ds, 0x1832);
  dl = memoryAGet(ds, 0x1834);
  flags.carry = cx < 0x0010;
  cx -= 0x0010;
  if (!flags.carry)
    goto loc_18f24;
  cx = 0;
  memoryASet(ds, 0x1838, memoryAGet(ds, 0x1838) | 0x01);
loc_18f24:
  ax = memoryAGet16(ds, 0x1835);
  ax += cx;
  if (ax < 0x0140)
    goto loc_18f3b;
  ax = 0x0140;
  ax -= cx;
  memoryASet16(ds, 0x1835, ax);
  memoryASet(ds, 0x1838, memoryAGet(ds, 0x1838) | 0x02);
loc_18f3b:
  flags.carry = dl < 0x08;
  dl -= 0x08;
  if (!flags.carry)
    goto loc_18f47;
  dl = 0;
  memoryASet(ds, 0x1838, memoryAGet(ds, 0x1838) | 0x04);
loc_18f47:
  al = memoryAGet(ds, 0x1837);
  flags.carry = (al + dl) >= 0x100;
  al += dl;
  if (flags.carry)
    goto loc_18f52;
  if (al < 0xc8)
    goto loc_18f5e;
loc_18f52:
  al = 0xc8;
  al -= dl;
  memoryASet(ds, 0x1837, al);
  memoryASet(ds, 0x1838, memoryAGet(ds, 0x1838) | 0x08);
loc_18f5e:
  goto loc_18ebc;
}
void sub_18f61()
{
  if (memoryAGet(ds, 0x0697) == 0xfd)
    goto loc_18f78;
  ah = 0x0b;
  bh = 0x01;
  si = memoryAGet16(ds, 0x0004);
  bl = memoryAGet(ds, si + 6227);
  interrupt(0x10);
  goto loc_18f97;
loc_18f78:
  si = memoryAGet16(ds, 0x0004);
  bl = 0x01;
  bh = memoryAGet(ds, si + 6203);
  sub_18f9e();
  bl = 0x02;
  bh = memoryAGet(ds, si + 6211);
  sub_18f9e();
  bl = 0x03;
  bh = memoryAGet(ds, si + 6219);
  sub_18f9e();
loc_18f97:
  ah = 0x0b;
  bx = 0;
  interrupt(0x10);
}
void sub_18f9e()
{
  ax = 0x1000;
  push(si);
  interrupt(0x10);
  si = pop();
}
void sub_18fa6()
{
  if (memoryAGet16(ds, 0x0006) != 0x0007)
    goto loc_18fb1;
  sub_1d270();
  return;
loc_18fb1:
  sub_1ca05();
  ax = 0x185b;
  if (memoryAGet(ds, 0x0552) == 0x00)
    goto loc_18ff6;
  bx = memoryAGet16(ds, 0x1c30);
  memoryASet16(ds, 0x1c30, memoryAGet16(ds, 0x1c30) + 0x0002);
  bx &= 0x0006;
  ax = memoryAGet16(ds, bx + 7206);
  if (memoryAGet(ds, 0x1f80) == 0x00)
    goto loc_18fda;
  memoryASet(ds, 0x1f80, memoryAGet(ds, 0x1f80) - 1);
loc_18fda:
  if (memoryAGet(ds, 0x0552) != 0xdd)
    goto loc_18ff6;
  if (memoryAGet16(ds, 0x0008) == 0x0000)
    goto loc_18ff6;
  if (memoryAGet(ds, 0x1f80) < 0x01)
    goto loc_18ff6;
  sub_1ce10();
  sub_1cd51();
  return;
loc_18ff6:
  memoryASet16(ds, 0x1c2e, ax);
  memoryASet16(ds, 0x1c1b, 0x8080);
  memoryASet(ds, 0x1c1d, 0x1c);
loc_19004:
  sub_19047();
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x1830, dx);
loc_1900f:
  sub_1ca14();
  ah = 0;
  interrupt(0x1a);
  if (dx == memoryAGet16(ds, 0x1830))
    goto loc_1900f;
  if (memoryAGet(ds, 0x1c1d) > 0x14)
    goto loc_19032;
  bh = 0;
  bl = memoryAGet(ds, 0x1c1d);
  bl &= 0x06;
  ax = memoryAGet16(ds, bx + 7198);
  goto loc_1903a;
loc_19032:
  ax = memoryAGet16(ds, 0x1c1b);
  flags.carry = true;
  al = rcr(al, 0x01);
  ah = al;
loc_1903a:
  memoryASet16(ds, 0x1c1b, ax);
  memoryASet(ds, 0x1c1d, memoryAGet(ds, 0x1c1d) - 1);
  if (memoryAGet(ds, 0x1c1d) != 0)
    goto loc_19004;
  sub_1cd51();
}
void sub_19047()
{
  flags.direction = false;
  push(ds);
  es = pop();
  si = memoryAGet16(ds, 0x1c2e);
  di = 0x000e;
  cx = 0x0060;
loc_19054:
  lodsw<MemAuto, DirAuto>();
  ax &= memoryAGet16(ds, 0x1c1b);
  stosw<MemAuto, DirAuto>();
  if (--cx)
    goto loc_19054;
  ax = 0xb800;
  es = ax;
  si = 0x000e;
  di = 0x0ed0;
  cx = 0x0c08;
  sub_19fcd();
}
void sub_19070()
{
  memoryASet(ds, 0x1cbf, 0x00);
  memoryASet16(ds, 0x1ce1, 0x0000);
  memoryASet(ds, 0x1cc0, 0x00);
  memoryASet(ds, 0x1cc1, 0x00);
  memoryASet(ds, 0x1cb8, 0x00);
  memoryASet(ds, 0x1cc8, 0xb1);
  sub_1c680();
}
void sub_19093()
{
  ah = 0;
  interrupt(0x1a);
  cx = dx;
  dx -= memoryAGet16(ds, 0x1cc9);
  ax = memoryAGet16(ds, 0x1ce1);
  ax &= 0x0001;
  ax += 0x0001;
  if (dx >= ax)
    goto loc_190ab;
loc_190aa:
  return;
loc_190ab:
  sub_18608();
  if (flags.zero)
    goto loc_190aa;
  memoryASet16(ds, 0x1cc9, cx);
  memoryASet16(ds, 0x1ce1, memoryAGet16(ds, 0x1ce1) + 1);
  if (memoryAGet(ds, 0x1cc1) == 0x00)
    goto loc_19112;
  memoryASet(ds, 0x1cc1, memoryAGet(ds, 0x1cc1) - 1);
  if (memoryAGet(ds, 0x1cc1) != 0)
    goto loc_190f9;
  sub_1cd51();
  if (memoryAGet(ds, 0x1cb8) == 0x00)
    goto loc_190f2;
  if (memoryAGet16(ds, 0x0004) == 0x0000)
    goto loc_190e7;
  memoryASet(ds, 0x0552, 0xdd);
  memoryASet16(ds, 0x0579, 0x00a0);
  memoryASet(ds, 0x057b, 0x60);
  return;
loc_190e7:
  if (memoryAGet(ds, 0x1f80) == 0x00)
    goto loc_190f2;
  memoryASet(ds, 0x1f80, memoryAGet(ds, 0x1f80) - 1);
loc_190f2:
  sub_19311();
  sub_19070();
  return;
loc_190f9:
  sub_19252();
  ax = 0x0104;
  al -= memoryAGet(ds, 0x1cc1);
  if (memoryAGet(ds, 0x1cd0) == 0xff)
    goto loc_1910c;
  ah = 0xff;
loc_1910c:
  sub_19289();
  goto loc_1922b;
loc_19112:
  if (memoryAGet(ds, 0x1cb8) == 0x00)
    goto loc_1913c;
  dl = memoryAGet(ds, 0x1cb8);
  if (memoryAGet16(ds, 0x1cb9) == 0x0000)
    goto loc_19132;
  memoryASet16(ds, 0x1cb9, memoryAGet16(ds, 0x1cb9) - 1);
  sub_1a02d();
  dl &= 0x01;
  if (dl != 0)
    goto loc_19132;
  dl = 0xff;
loc_19132:
  memoryASet(ds, 0x1cd0, dl);
  ax = memoryAGet16(ds, 0x1cc6);
  goto loc_191db;
loc_1913c:
  if (memoryAGet(ds, 0x1cbf) != 0x00)
    goto loc_191a5;
  if (memoryAGet(ds, 0x1cc0) != 0x00)
    goto loc_19187;
  if (memoryAGet(ds, 0x1d58) != 0x00)
    goto loc_1916d;
  if (memoryAGet(ds, 0x057b) < 0xb4)
    goto loc_1916c;
  if (memoryAGet(ds, 0x0558) != 0x00)
    goto loc_1916c;
  sub_1a02d();
  bx = memoryAGet16(ds, 0x0008);
  if (dl < memoryAGet(ds, bx + 7377))
    goto loc_1916d;
loc_1916c:
  return;
loc_1916d:
  al = 0x01;
  memoryASet16(ds, 0x59ba, 0x0000);
  if (memoryAGet16(ds, 0x0579) >= 0x00a0)
    goto loc_1917f;
  al = 0xff;
loc_1917f:
  memoryASet(ds, 0x1cd0, al);
  memoryASet(ds, 0x1cc0, 0x04);
loc_19187:
  memoryASet(ds, 0x1cc0, memoryAGet(ds, 0x1cc0) - 1);
  if (memoryAGet(ds, 0x1cc0) != 0)
    goto loc_19195;
  memoryASet(ds, 0x1cbf, 0x01);
  goto loc_191a5;
  //   gap of 1 bytes
loc_19195:
  sub_19252();
  al = memoryAGet(ds, 0x1cc0);
  ah = memoryAGet(ds, 0x1cd0);
  sub_19289();
  goto loc_1922b;
loc_191a5:
  memoryASet(ds, 0x1d58, 0x00);
  ax = memoryAGet16(ds, 0x1cc6);
  if (memoryAGet(ds, 0x057b) < 0xb4)
    goto loc_191db;
  if (memoryAGet(ds, 0x0558) != 0x00)
    goto loc_191db;
  sub_1a02d();
  bx = memoryAGet16(ds, 0x0008);
  if (dl > memoryAGet(ds, bx + 7385))
    goto loc_191db;
  if (ax > memoryAGet16(ds, 0x0579))
    goto loc_191d6;
  memoryASet(ds, 0x1cd0, 0x01);
  goto loc_191db;
  //   gap of 1 bytes
loc_191d6:
  memoryASet(ds, 0x1cd0, 0xff);
loc_191db:
  if (memoryAGet(ds, 0x1cd0) < 0x01)
    goto loc_1921f;
  if (memoryAGet(ds, 0x1cd0) == 0x01)
    goto loc_19212;
  flags.carry = ax < 0x0008;
  ax -= 0x0008;
  if (!flags.carry)
    goto loc_1921f;
  ax = 0;
loc_191eb:
  if (memoryAGet(ds, 0x1cb8) == 0x00)
    goto loc_191fc;
  if (memoryAGet16(ds, 0x1cb9) != 0x0000)
    goto loc_1921f;
  goto loc_1920a;
  //   gap of 1 bytes
loc_191fc:
  if (memoryAGet(ds, 0x057b) < 0xb4)
    goto loc_1920a;
  if (memoryAGet(ds, 0x0558) == 0x00)
    goto loc_1921f;
loc_1920a:
  memoryASet(ds, 0x1cc1, 0x04);
  goto loc_1921f;
  //   gap of 1 bytes
loc_19212:
  ax += 0x0008;
  if (ax < 0x011e)
    goto loc_1921f;
  ax = 0x011e;
  goto loc_191eb;
loc_1921f:
  memoryASet16(ds, 0x1cc6, ax);
  sub_19252();
  memoryASet16(ds, 0x1cc4, 0x0f04);
loc_1922b:
  cx = memoryAGet16(ds, 0x1cc6);
  dl = memoryAGet(ds, 0x1cc8);
  sub_19ee0();
  memoryASet16(ds, 0x1ccd, ax);
  if (memoryAGet(ds, 0x1cc0) == 0x03)
    goto loc_19243;
  sub_19311();
loc_19243:
  sub_19325();
  if (flags.carry)
    return;
  ax = memoryAGet16(ds, 0x1ccd);
  memoryASet16(ds, 0x1cbd, ax);
  sub_192cb();
}
void sub_19252()
{
  bh = 0;
  if (memoryAGet(ds, 0x1cb8) == 0x00)
    goto loc_1926b;
  memoryASet(ds, 0x1ccf, memoryAGet(ds, 0x1ccf) + 1);
  bl = memoryAGet(ds, 0x1ccf);
  bl &= 0x06;
  bl |= 0x08;
  if (bl)
    goto loc_19281;
loc_1926b:
  memoryASet(ds, 0x1ccf, memoryAGet(ds, 0x1ccf) + 0x02);
  bl = memoryAGet(ds, 0x1ccf);
  bl &= 0x02;
  if (memoryAGet(ds, 0x1cd0) != 0x01)
    goto loc_19281;
  bl |= 0x04;
loc_19281:
  ax = memoryAGet16(ds, bx + 5576);
  memoryASet16(ds, 0x1cbb, ax);
}
void sub_19289()
{
  cx = 0x0f04;
  cl -= al;
  memoryASet16(ds, 0x1cc4, cx);
  if (ah == 0xff)
    goto loc_192a8;
  ah = 0;
  al <<= 1;
  memoryASet16(ds, 0x1cbb, memoryAGet16(ds, 0x1cbb) + ax);
  memoryASet16(ds, 0x1cc6, 0x0000);
  goto loc_192b6;
  //   gap of 1 bytes
loc_192a8:
  ah = 0;
  al <<= 1;
  al <<= 1;
  al <<= 1;
  ax += 0x0120;
  memoryASet16(ds, 0x1cc6, ax);
loc_192b6:
  push(ds);
  es = pop();
  si = memoryAGet16(ds, 0x1cbb);
  di = 0x000e;
  al = 0x04;
  sub_19fa0();
  memoryASet16(ds, 0x1cbb, 0x000e);
}
void sub_192cb()
{
  cx = memoryAGet16(ds, 0x1cc4);
  memoryASet16(ds, 0x1cc2, cx);
  ax = 0xb800;
  if (memoryAGet(ds, 0x1cb8) != 0x00)
    goto loc_192ee;
  es = ax;
  di = memoryAGet16(ds, 0x1cbd);
  si = memoryAGet16(ds, 0x1cbb);
  bp = 0x1c40;
  sub_19efc();
  return;
loc_192ee:
  push(ds);
  ds = ax;
  es = pop();
  push(es);
  push(ds);
  si = memoryAGet16(es, 0x1cbd);
  di = 0x1c40;
  sub_19ffa();
  es = pop();
  ds = pop();
  si = memoryAGet16(ds, 0x1cbb);
  di = memoryAGet16(ds, 0x1cbd);
  cx = memoryAGet16(ds, 0x1cc4);
  sub_19fcd();
}
void sub_19311()
{
  ax = 0xb800;
  es = ax;
  di = memoryAGet16(ds, 0x1cbd);
  si = 0x1c40;
  cx = memoryAGet16(ds, 0x1cc2);
  sub_19fcd();
}
// INJECT: Error: cannot inject carry flag in sub_19325()!
void sub_19325()
{
  if (memoryAGet(ds, 0x1cb8) != 0x00)
    goto loc_19364;
  al = memoryAGet(ds, 0x1cbf);
  al |= memoryAGet(ds, 0x1cc0);
  al |= memoryAGet(ds, 0x1cc1);
  if (!al)
    goto loc_19364;
  if (memoryAGet(ds, 0x057b) < 0xa3)
    goto loc_19364;
  if (memoryAGet(ds, 0x0558) != 0x00)
    goto loc_19364;
  ax = memoryAGet16(ds, 0x1cc6);
  ax += 0x0020;
  if (ax < memoryAGet16(ds, 0x0579))
    goto loc_19364;
  flags.carry = ax < 0x0038;
  ax -= 0x0038;
  if (!flags.carry)
    goto loc_1935a;
  ax = 0;
loc_1935a:
  if (ax > memoryAGet16(ds, 0x0579))
    goto loc_19364;
  sub_19366();
  stop(/*inject ret*/);
  return;
loc_19364:
  flags.carry = false;
}
void sub_19366()
{
  if (memoryAGet16(ds, 0x0004) != 0x0006)
    goto loc_19379;
  al = memoryAGet(ds, 0x057b);
  memoryASet(ds, 0x1cc8, al);
  ax = memoryAGet16(ds, 0x0579);
  memoryASet16(ds, 0x1cc6, ax);
loc_19379:
  ax = memoryAGet16(ds, 0x1cc6);
  ax += memoryAGet16(ds, 0x0579);
  ax >>= 1;
  if (ax < 0x0118)
    goto loc_1938a;
  ax = 0x0117;
loc_1938a:
  memoryASet16(ds, 0x1cc6, ax);
  bl = 0x01;
  if (ax > 0x00a0)
    goto loc_1939e;
  bl = 0xff;
  dx = 0x00a1;
  dx -= ax;
  goto loc_193a3;
  //   gap of 1 bytes
loc_1939e:
  ax -= 0x009f;
  dx = ax;
loc_193a3:
  memoryASet(ds, 0x1cb8, bl);
  memoryASet(ds, 0x1cbf, 0x01);
  memoryASet(ds, 0x1cc1, 0x00);
  cl = 0x03;
  dx >>= cl;
  memoryASet16(ds, 0x1cb9, dx);
  if (memoryAGet16(ds, 0x0004) != 0x0006)
    goto loc_193ed;
  sub_18413();
  al = memoryAGet(ds, 0x1cb8);
  push(ax);
  memoryASet(ds, 0x1cb8, 0x00);
  memoryASet16(ds, 0x1cc4, 0x0f04);
  ax = memoryAGet16(ds, 0x15c8);
  memoryASet16(ds, 0x1cbb, ax);
  cx = memoryAGet16(ds, 0x1cc6);
  dl = memoryAGet(ds, 0x1cc8);
  sub_19ee0();
  memoryASet16(ds, 0x1cbd, ax);
  sub_192cb();
  ax = pop();
  memoryASet(ds, 0x1cb8, al);
loc_193ed:
  sub_19311();
  sub_18413();
  ax = 0x0000;
  if (memoryAGet16(ds, 0x0579) >= 0x00a0)
    goto loc_19401;
  ax = 0x0122;
loc_19401:
  memoryASet16(ds, 0x0579, ax);
  if (memoryAGet16(ds, 0x0004) != 0x0000)
    goto loc_1940e;
  sub_1793d();
loc_1940e:
  flags.carry = true;
}
// INJECT: Error: cannot inject carry flag in sub_19410()!
void sub_19410()
{
  al = memoryAGet(ds, 0x1cbf);
  al |= memoryAGet(ds, 0x1cc0);
  al |= memoryAGet(ds, 0x1cc1);
  if (!al)
    goto loc_19439;
  ax = memoryAGet16(ds, 0x327d);
  dl = memoryAGet(ds, 0x327f);
  si = 0x0010;
  bx = memoryAGet16(ds, 0x1cc6);
  dh = memoryAGet(ds, 0x1cc8);
  di = 0x0020;
  cx = 0x0f1e;
  sub_1a059();
  stop(/*inject ret*/);
  return;
loc_19439:
  flags.carry = false;
}
void sub_19440()
{
  memoryASet(ds, 0x1d59, 0x00);
}
void sub_19446()
{
  ah = 0;
  interrupt(0x1a);
  if (dx != memoryAGet16(ds, 0x1d5a))
    goto loc_19451;
loc_19450:
  return;
loc_19451:
  cx = dx;
  sub_18608();
  if (flags.zero)
    goto loc_19450;
  memoryASet16(ds, 0x1d5a, cx);
  sub_19527();
  if (flags.carry)
    goto loc_19450;
  if (memoryAGet(ds, 0x1d59) != 0x00)
    goto loc_1949d;
  if (memoryAGet(ds, 0x057b) == 0x86)
    goto loc_1947e;
  if (memoryAGet(ds, 0x057b) == 0x8e)
    goto loc_1947e;
  sub_1a02d();
  if (dl > 0x05)
    goto loc_19450;
loc_1947e:
  sub_18800();
  dl += 0x03;
  memoryASet(ds, 0x1d5e, dl);
  sub_1a02d();
  dx &= 0x0007;
  cx += dx;
  cx += 0x0006;
  memoryASet16(ds, 0x1d5c, cx);
  memoryASet(ds, 0x1d59, 0x1b);
loc_1949d:
  memoryASet(ds, 0x1d59, memoryAGet(ds, 0x1d59) - 1);
  cx = memoryAGet16(ds, 0x1d5c);
  dl = memoryAGet(ds, 0x1d5e);
  if (memoryAGet(ds, 0x1d59) <= 0x0d)
    goto loc_194c1;
  dl += memoryAGet(ds, 0x1d59);
  dl -= 0x0f;
  bx = 0x1b02;
  bh -= memoryAGet(ds, 0x1d59);
  goto loc_194cf;
  //   gap of 1 bytes
loc_194c1:
  dl += 0x0c;
  dl -= memoryAGet(ds, 0x1d59);
  bx = 0x0002;
  bh += memoryAGet(ds, 0x1d59);
loc_194cf:
  memoryASet16(ds, 0x1d64, bx);
  memoryASet(ds, 0x1d5f, dl);
  sub_19ee0();
  memoryASet16(ds, 0x1d62, ax);
  sub_1950c();
  sub_19527();
  if (flags.carry)
    goto loc_194ec;
  if (memoryAGet(ds, 0x1d59) != 0x00)
    goto loc_194ed;
loc_194ec:
  return;
loc_194ed:
  ax = 0xb800;
  es = ax;
  di = memoryAGet16(ds, 0x1d62);
  si = 0x1cf0;
  memoryASet16(ds, 0x1d60, di);
  cx = memoryAGet16(ds, 0x1d64);
  memoryASet16(ds, 0x1d66, cx);
  bp = 0x1d24;
  sub_19efc();
}
void sub_1950c()
{
  if (memoryAGet(ds, 0x1d59) == 0x1a)
    return;
  ax = 0xb800;
  es = ax;
  di = memoryAGet16(ds, 0x1d60);
  si = 0x1d24;
  cx = memoryAGet16(ds, 0x1d66);
  sub_19fcd();
}
// INJECT: Error: cannot inject carry flag in sub_19527()!
void sub_19527()
{
  if (memoryAGet(ds, 0x1d59) != 0x00)
    goto loc_19530;
  flags.carry = false;
  return;
loc_19530:
  cx = memoryAGet16(ds, 0x1d64);
  tl = cl;
  cl = ch;
  ch = tl;
  ax = memoryAGet16(ds, 0x1d5c);
  dl = memoryAGet(ds, 0x1d5f);
  si = 0x0010;
  bx = memoryAGet16(ds, 0x0579);
  dh = memoryAGet(ds, 0x057b);
  di = 0x0018;
  ch = 0x0e;
  sub_1a059();
  if (!flags.carry)
    goto loc_19557;
  memoryASet(ds, 0x1d58, 0x01);
loc_19557:
    return;
}
void sub_19560()
{
  memoryASet16(ds, 0x1f6c, 0x0000);
  ax = 0;
  dl = 0x01;
  if (memoryAGet16(ds, 0x0579) > 0x00a0)
    goto loc_19577;
  ax = 0x012c;
  dl = 0xff;
loc_19577:
  memoryASet16(ds, 0x1f30, ax);
  memoryASet16(ds, 0x1f32, ax);
  memoryASet16(ds, 0x1f34, ax);
  memoryASet(ds, 0x1f3c, dl);
  memoryASet(ds, 0x1f3d, dl);
  memoryASet(ds, 0x1f3e, dl);
  memoryASet(ds, 0x1f48, 0x01);
  memoryASet(ds, 0x1f49, 0x01);
  memoryASet(ds, 0x1f4a, 0x01);
  memoryASet(ds, 0x1f50, 0x00);
  memoryASet(ds, 0x1f51, 0x00);
  memoryASet(ds, 0x1f52, 0x00);
}
void sub_195ab()
{
  ah = 0;
  interrupt(0x1a);
  if (dx != memoryAGet16(ds, 0x1f65))
    goto loc_195b6;
loc_195b5:
  return;
loc_195b6:
  memoryASet16(ds, 0x1f65, dx);
  if (memoryAGet(ds, 0x055a) != 0x00)
    goto loc_195b5;
  bx = memoryAGet16(ds, 0x1f6c);
  bx++;
  if (bx < 0x0003)
    goto loc_195ce;
  bx = 0x0000;
loc_195ce:
  memoryASet16(ds, 0x1f6c, bx);
  sub_1988e();
  if (flags.carry)
    goto loc_195b5;
  sub_19797();
  if (flags.carry)
    goto loc_195b5;
  bx = memoryAGet16(ds, 0x1f6c);
  if (memoryAGet(ds, bx + 8016) == 0x00)
    goto loc_1961b;
  ah = 0;
  interrupt(0x1a);
  bx = memoryAGet16(ds, 0x1f6c);
  bl <<= 1;
  dx -= memoryAGet16(ds, bx + 8019);
  if (dx < 0x0036)
    goto loc_195b5;
  dl = 0x01;
  ax = 0x0000;
  if (memoryAGet16(ds, 0x0579) > 0x00a0)
    goto loc_1960c;
  ax = 0x012c;
  dl = 0xff;
loc_1960c:
  memoryASet16(ds, bx + 7984, ax);
  bl >>= 1;
  memoryASet(ds, bx + 8016, 0x00);
  memoryASet(ds, bx + 7996, dl);
loc_1961b:
  dl = memoryAGet(ds, bx + 7996);
  memoryASet(ds, bx + 7999, dl);
  if (memoryAGet(ds, 0x1664) == 0x00)
    goto loc_19633;
  memoryASet16(ds, 0x1f69, 0x000c);
  goto loc_19648;
  //   gap of 1 bytes
loc_19633:
  ax = 0x0008;
  if (memoryAGet(ds, 0x057b) <= 0x60)
    goto loc_1963f;
  al >>= 1;
loc_1963f:
  memoryASet16(ds, 0x1f69, ax);
  if (bx != memoryAGet16(ds, 0x052f))
    goto loc_19655;
loc_19648:
  if (memoryAGet(ds, bx + 7996) != 0x00)
    goto loc_19655;
  sub_1a02d();
  goto loc_196ba;
  //   gap of 1 bytes
loc_19655:
  if (memoryAGet(ds, 0x055c) == 0x00)
    goto loc_19696;
  al = memoryAGet(ds, bx + 7990);
  if (al > memoryAGet(ds, 0x057b))
    goto loc_19696;
  al += 0x10;
  if (al < memoryAGet(ds, 0x057b))
    goto loc_19696;
  sub_1a02d();
  si = memoryAGet16(ds, 0x0008);
  if (dl > memoryAGet(ds, si + 8046))
    goto loc_19696;
  memoryASet16(ds, 0x1f69, 0x000c);
  al = 0x01;
  bl <<= 1;
  cx = memoryAGet16(ds, bx + 7984);
  bl >>= 1;
  if (cx < memoryAGet16(ds, 0x0579))
    goto loc_19693;
  al = 0xff;
loc_19693:
  goto loc_196c2;
  //   gap of 1 bytes
loc_19696:
  cl = 0x18;
  if (memoryAGet(ds, 0x057b) <= 0x60)
    goto loc_196aa;
  cl = 0x28;
  if (memoryAGet(ds, bx + 7996) != 0x00)
    goto loc_196aa;
  cl = 0x10;
loc_196aa:
  sub_1a02d();
  if (dl > cl)
    goto loc_196c6;
  al = 0x00;
  if (memoryAGet(ds, bx + 7996) != 0x00)
    goto loc_196c2;
loc_196ba:
  al = dl;
  al &= 0x01;
  if (al != 0)
    goto loc_196c2;
  al = 0xff;
loc_196c2:
  memoryASet(ds, bx + 7996, al);
loc_196c6:
  dl = memoryAGet(ds, bx + 7996);
  bl <<= 1;
  ax = memoryAGet16(ds, bx + 7984);
  if (dl < 0x01)
    goto loc_196f2;
  if (dl != 0x01)
    goto loc_196e8;
  ax += memoryAGet16(ds, 0x1f69);
  if (ax < 0x012f)
    goto loc_196f2;
  ax = 0x012e;
  dl = 0xff;
  goto loc_196f2;
  //   gap of 1 bytes
loc_196e8:
  flags.carry = ax < memoryAGet16(ds, 0x1f69);
  ax -= memoryAGet16(ds, 0x1f69);
  if (!flags.carry)
    goto loc_196f2;
  ax = 0;
  dl = 0x01;
loc_196f2:
  memoryASet16(ds, bx + 7984, ax);
  bl >>= 1;
  memoryASet(ds, bx + 7996, dl);
  dl = memoryAGet(ds, bx + 7990);
  cx = ax;
  sub_19ee0();
  memoryASet16(ds, 0x1f4b, ax);
  bx = memoryAGet16(ds, 0x1f6c);
  if (memoryAGet(ds, bx + 8008) != 0x00)
    goto loc_19720;
  al = memoryAGet(ds, bx + 7996);
  al |= memoryAGet(ds, bx + 7999);
  if (!al)
    goto loc_19720;
  sub_1977d();
loc_19720:
  sub_1988e();
  if (flags.carry)
    goto loc_1972a;
  sub_19797();
  if (!flags.carry)
    goto loc_1972b;
loc_1972a:
  return;
loc_1972b:
  bx = memoryAGet16(ds, 0x1f6c);
  memoryASet(ds, bx + 8008, 0x00);
  if (memoryAGet(ds, bx + 7996) != 0x00)
    goto loc_19748;
  if (memoryAGet(ds, bx + 7999) == 0x00)
    return;
  si = 0x1e30;
  goto loc_19763;
  //   gap of 1 bytes
loc_19748:
  si = 0x1e50;
  memoryASet(ds, bx + 8013, memoryAGet(ds, bx + 8013) + 1);
  if (memoryAGet(ds, bx + 8013) & 0x01)
    goto loc_19759;
  si += 0x0020;
loc_19759:
  if (memoryAGet(ds, bx + 7996) == 0x01)
    goto loc_19763;
  si += 0x0040;
loc_19763:
  bl <<= 1;
  di = memoryAGet16(ds, 0x1f4b);
  memoryASet16(ds, bx + 8002, di);
  ax = 0xb800;
  es = ax;
  bp = memoryAGet16(ds, bx + 8025);
  cx = 0x0802;
  sub_19f65();
}
void sub_1977d()
{
  bx = memoryAGet16(ds, 0x1f6c);
  bl <<= 1;
  ax = 0xb800;
  es = ax;
  di = memoryAGet16(ds, bx + 8002);
  si = memoryAGet16(ds, bx + 8025);
  cx = 0x0802;
  sub_19fcd();
}
void sub_19797()
{
  bx = memoryAGet16(ds, 0x1f6c);
  dl = memoryAGet(ds, bx + 7990);
  bl <<= 1;
  ax = memoryAGet16(ds, bx + 7984);
  si = 0x0010;
  bx = memoryAGet16(ds, 0x0579);
  dh = memoryAGet(ds, 0x057b);
  di = 0x0018;
  cx = 0x0e08;
  sub_1a059();
  if (flags.carry)
    goto loc_197be;
  return;
loc_197be:
  bx = memoryAGet16(ds, 0x1f6c);
  if (memoryAGet(ds, bx + 8016) != 0x00)
    goto loc_1983c;
  if (memoryAGet(ds, 0x057c) < 0x26)
    goto loc_1983c;
  if (memoryAGet(ds, 0x055c) == 0x00)
    goto loc_1983e;
  memoryASet(ds, 0x055c, 0x00);
  memoryASet(ds, 0x055b, 0x11);
  memoryASet(ds, 0x0571, 0x01);
  memoryASet(ds, 0x056e, 0x00);
  bx = memoryAGet16(ds, 0x1f6c);
  bl <<= 1;
  di = memoryAGet16(ds, bx + 8002);
  if (memoryAGet16(ds, bx + 7984) < 0x0010)
    goto loc_197ff;
  di -= 0x0004;
loc_197ff:
  memoryASet16(ds, 0x1f67, di);
  ax = 0xb800;
  es = ax;
  si = 0x1d70;
  bp = 0x000e;
  cx = 0x0806;
  sub_19efc();
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x1f65, dx);
loc_1981c:
  sub_1ccc0();
  ah = 0;
  interrupt(0x1a);
  dx -= memoryAGet16(ds, 0x1f65);
  if (dx < 0x0008)
    goto loc_1981c;
  sub_1cd51();
  di = memoryAGet16(ds, 0x1f67);
  si = 0x000e;
  cx = 0x0806;
  sub_19fcd();
loc_1983c:
  flags.carry = true;
  return;
loc_1983e:
  ah = 0;
  interrupt(0x1a);
  bx = memoryAGet16(ds, 0x1f6c);
  memoryASet(ds, bx + 8016, 0x01);
  memoryASet(ds, bx + 7996, 0x01);
  bl <<= 1;
  memoryASet16(ds, bx + 8019, dx);
  sub_18413();
  bx = memoryAGet16(ds, 0x1f6c);
  bl <<= 1;
  si = memoryAGet16(ds, bx + 8031);
  di = memoryAGet16(ds, bx + 8002);
  ax = 0xb800;
  es = ax;
  bp = 0x000e;
  cx = 0x0802;
  sub_19efc();
  sub_18354();
  bx = memoryAGet16(ds, 0x1f6c);
  al = memoryAGet(ds, bx + 7993);
  sub_19936();
  ax = 0x03e8;
  bx = 0x02ee;
  sub_1cb6b();
  flags.carry = true;
}
// INJECT: Error: cannot inject carry flag in sub_1988e()!
void sub_1988e()
{
  if (memoryAGet(ds, 0x1673) != 0x00)
    goto loc_19897;
  flags.carry = false;
  return;
loc_19897:
  bx = memoryAGet16(ds, 0x1f6c);
  dl = memoryAGet(ds, bx + 7990);
  bl <<= 1;
  ax = memoryAGet16(ds, bx + 7984);
  si = 0x0010;
  di = si;
  bx = memoryAGet16(ds, 0x1671);
  dh = memoryAGet(ds, 0x1673);
  cx = 0x0c08;
  sub_1a059();
  stop(/*inject ret*/);
}
void sub_198c0()
{
  push(ds);
  es = pop();
  cx = 0x0007;
  si = 0x1f82;
loc_198c8:
  lodsb<MemAuto, DirAuto>();
  bx = 0x0007;
  bx -= cx;
  if (--cx && al == memoryAGet(ds, bx + 8073))
    goto loc_198c8;
  if (al > memoryAGet(ds, bx + 8073)) // TODO: check!
    goto loc_198d7;
  return;
loc_198d7:
  si = 0x1f82;
  di = 0x1f89;
  cx = 0x0007;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
}
void sub_198e3()
{
  al = memoryAGet(ds, 0x1f80);
  if (al != memoryAGet(ds, 0x1f81))
    goto loc_198ed;
  return;
loc_198ed:
  memoryASet(ds, 0x1f81, al);
  ah = 0;
  cl = 0x04;
  ax <<= cl;
  ax += 0x2720;
  si = ax;
  ax = 0xb800;
  es = ax;
  di = 0x1260;
  cx = 0x0801;
  sub_19fcd();
}
void sub_1990a()
{
  di = 0x1f82;
  sub_19918();
}
void sub_19911()
{
  di = 0x1f89;
  sub_19918();
}
void sub_19918()
{
  push(ds);
  es = pop();
  cx = 0x0007;
  al = 0;
  rep_stosb<MemAuto, DirAuto>();
}
void sub_19922()
{
  bx = 0x1f89;
  di = 0x12ca;
  sub_19969();
}
void sub_1992c()
{
  bx = 0x1f82;
  di = 0x143c;
  sub_19969();
}
void sub_19936()
{
  cx = 0x0006;
loc_19939:
  bx = cx;
  ah = 0x00;
  al += memoryAGet(ds, bx + 8065);
  aaa();
  memoryASet(ds, bx + 8065, al);
  al = ah;
  if (--cx)
    goto loc_19939;
  sub_1992c();
}
void sub_1994e()
{
  push(cx);
  push(ax);
  push(bx);
  flags.carry = false;
  tx = flags.carry | (flags.zero << 1);
  push(tx);
  cx = 0x0007;
loc_19956:
  tx = pop();
  flags.carry = tx & 1;
  flags.zero = (tx << 1) & 1;
  bx = cx;
  flags.carry = bx == 0;
  bx--;
  al = memoryAGet(ds, bx + di);
  al += memoryAGet(ds, bx + si) + flags.carry;
  aaa();
  memoryASet(ds, bx + di, al);
  tx = flags.carry | (flags.zero << 1);
  push(tx);
  if (--cx)
    goto loc_19956;
  tx = pop();
  flags.carry = tx & 1;
  flags.zero = (tx << 1) & 1;
  bx = pop();
  ax = pop();
  cx = pop();
}
void sub_19969()
{
  ax = 0xb800;
  es = ax;
  memoryASet16(ds, 0x1f90, di);
  memoryASet16(ds, 0x1f93, bx);
  memoryASet(ds, 0x1f92, 0x00);
loc_1997b:
  bx = memoryAGet16(ds, 0x1f93);
  al = memoryAGet(ds, bx);
  ah = 0;
  cl = 0x04;
  ax <<= cl;
  ax += 0x2720;
  si = ax;
  di = memoryAGet16(ds, 0x1f90);
  cx = 0x0801;
  sub_19fcd();
  memoryASet16(ds, 0x1f90, memoryAGet16(ds, 0x1f90) + 0x0002);
  memoryASet16(ds, 0x1f93, memoryAGet16(ds, 0x1f93) + 1);
  memoryASet(ds, 0x1f92, memoryAGet(ds, 0x1f92) + 1);
  if (memoryAGet(ds, 0x1f92) == 0x07)
    return;
  if (memoryAGet(ds, 0x1f92) != 0x03)
    goto loc_1997b;
  memoryASet16(ds, 0x1f90, memoryAGet16(ds, 0x1f90) + 0x0002);
  goto loc_1997b;
}
void sub_199c0()
{
  ax = 0xb800;
  es = ax;
  if (memoryAGet16(ds, 0x0004) != 0x0002)
    goto loc_19a1e;
  flags.direction = false;
  di = 0;
  ax = 0xaaaa;
  cx = 0x0050;
  rep_stosw<MemAuto, DirAuto>();
  di = 0x2000;
  cx = 0x0050;
  rep_stosw<MemAuto, DirAuto>();
  memoryASet16(ds, 0x2654, 0x0000);
loc_199e5:
  sub_1a02d();
  dx &= 0x0018;
  if (dl == memoryAGet(ds, 0x2653))
    goto loc_199e5;
  memoryASet(ds, 0x2653, dl);
  bx = memoryAGet16(ds, 0x2654);
  memoryASet(ds, bx + 9814, dl);
  dx += 0x2020;
  si = dx;
  di = bx;
  di <<= 1;
  di += 0x00a0;
  cx = 0x0401;
  sub_19fcd();
  memoryASet16(ds, 0x2654, memoryAGet16(ds, 0x2654) + 1);
  if (memoryAGet16(ds, 0x2654) < 0x0028)
    goto loc_199e5;
  return;
loc_19a1e:
  if (memoryAGet16(ds, 0x0004) != 0x0007)
    goto loc_19a29;
  sub_1a23f();
  return;
loc_19a29:
  if (memoryAGet16(ds, 0x0004) != 0x0006)
    goto loc_19a6e;
  ax = 0;
  sub_19bd0();
  bx = 0x2570;
  ax = 0x064a;
  sub_19d54();
  memoryASet16(ds, 0x2650, 0x0048);
  memoryASet(ds, 0x2652, 0x38);
  ax = 0x0dd2;
  sub_19b88();
  ax = 0x0df6;
  sub_19ba0();
  si = 0x1fa0;
  di = 0x067e;
  cx = 0x1002;
  sub_19fcd();
  bx = 0x2344;
  ax = 0x0b84;
  sub_19d54();
  sub_1bd77();
  return;
loc_19a6e:
  if (memoryAGet16(ds, 0x0004) != 0x0005)
    goto loc_19abd;
  ax = 0x0640;
  sub_19bd0();
  bx = 0x2570;
  ax = 0x0cb6;
  sub_19d54();
  memoryASet16(ds, 0x2650, 0x00f8);
  memoryASet(ds, 0x2652, 0x60);
  ax = 0x140e;
  sub_19b88();
  ax = 0x1434;
  sub_19ba0();
  ax = 0x143e;
  sub_19ba0();
  ax = 0x16a0;
  sub_19bb8();
  bx = 0x2344;
  ax = 0x1184;
  sub_19d54();
  si = 0x1fe0;
  di = 0x0dd6;
  cx = 0x1002;
  sub_19fcd();
  return;
loc_19abd:
  if (memoryAGet16(ds, 0x0004) != 0x0004)
    goto loc_19aee;
  ax = 0x0640;
  sub_19bd0();
  bx = 0x2570;
  ax = 0x0cba;
  sub_19d54();
  memoryASet16(ds, 0x2650, 0x0108);
  memoryASet(ds, 0x2652, 0x60);
  ax = 0x1439;
  sub_19b88();
  ax = 0x16c0;
  sub_19b75();
  sub_1b1ce();
  return;
loc_19aee:
  if (memoryAGet16(ds, 0x0004) != 0x0003)
    goto loc_19b39;
  ax = 0x0640;
  sub_19bd0();
  bx = 0x2570;
  ax = 0x0c90;
  sub_19d54();
  memoryASet16(ds, 0x2650, 0x0060);
  memoryASet(ds, 0x2652, 0x60);
  ax = 0x140c;
  sub_19b88();
  ax = 0x1418;
  sub_19ba0();
  bx = 0x2344;
  ax = 0x1184;
  sub_19d54();
  bx = 0x2344;
  ax = 0x11a2;
  sub_19d54();
  bx = 0x2624;
  ax = 0;
  sub_19d54();
  sub_1ae0b();
  return;
loc_19b39:
  ax = 0x0640;
  sub_19bd0();
  bx = 0x2570;
  ax = 0x0ca0;
  sub_19d54();
  memoryASet16(ds, 0x2650, 0x00a0);
  memoryASet(ds, 0x2652, 0x60);
  ax = 0x1406;
  sub_19b88();
  bx = 0x2344;
  ax = 0x11c4;
  sub_19d54();
  ax = 0x1422;
  sub_19ba0();
  ax = 0x1690;
  sub_19bb8();
  ax = 0x16b6;
  sub_19b75();
}
void sub_19b75()
{
  memoryASet16(ds, 0x2634, ax);
  bx = 0x2384;
  sub_19d54();
  ax = memoryAGet16(ds, 0x2634);
  bx = 0x238c;
  sub_19d54();
}
void sub_19b88()
{
  memoryASet16(ds, 0x2634, ax);
  si = 0x0008;
loc_19b8e:
  ax = memoryAGet16(ds, 0x2634);
  bx = memoryAGet16(ds, si + 9780);
  push(si);
  sub_19d54();
  si = pop();
  si -= 0x0002;
  if (si != 0)
    goto loc_19b8e;
}
void sub_19ba0()
{
  memoryASet16(ds, 0x2634, ax);
  si = 0x000a;
loc_19ba6:
  ax = memoryAGet16(ds, 0x2634);
  bx = memoryAGet16(ds, si + 9788);
  push(si);
  sub_19d54();
  si = pop();
  si -= 0x0002;
  if (si != 0)
    goto loc_19ba6;
}
void sub_19bb8()
{
  memoryASet16(ds, 0x2634, ax);
  si = 0x0008;
loc_19bbe:
  ax = memoryAGet16(ds, 0x2634);
  bx = memoryAGet16(ds, si + 9798);
  push(si);
  sub_19d54();
  si = pop();
  si -= 0x0002;
  if (si != 0)
    goto loc_19bbe;
}
void sub_19bd0()
{
  memoryASet16(ds, 0x267e, ax);
  bx = 0x251c;
  sub_19d54();
  ax = 0;
  flags.direction = false;
  di = memoryAGet16(ds, 0x267e);
  di += 0x0284;
  cx = 0x0024;
  rep_stosw<MemAuto, DirAuto>();
  di = memoryAGet16(ds, 0x267e);
  di += 0x1184;
  cx = 0x0024;
  rep_stosw<MemAuto, DirAuto>();
  di = memoryAGet16(ds, 0x267e);
  di += 0x2284;
  al = 0x2a;
  sub_19c11();
  di = memoryAGet16(ds, 0x267e);
  di += 0x22cb;
  al = 0xa8;
  sub_19c11();
}
void sub_19c11()
{
  cx = 0x005f;
loc_19c14:
  memoryASet(es, di, al);
  di ^= 0x2000;
  if (di & 0x2000)
    goto loc_19c24;
  di += 0x0050;
loc_19c24:
  if (--cx)
    goto loc_19c14;
}
void sub_19c30()
{
  ax = 0xb800;
  es = ax;
  flags.direction = false;
  di = 0;
  ax = 0xaaaa;
  cx = 0x0fa0;
  rep_stosw<MemAuto, DirAuto>();
  di = 0x2000;
  cx = 0x0fa0;
  rep_stosw<MemAuto, DirAuto>();
  sub_19dce();
  bx = 0x28a0;
  ax = 0;
  sub_19d54();
  sub_19c98();
  sub_19eb4();
  sub_19dbb();
  sub_19cb0();
}
void sub_19c60()
{
  ax = 0xb800;
  es = ax;
  flags.direction = false;
  di = 0;
  ax = 0xaaaa;
  cx = 0x0fa0;
  rep_stosw<MemAuto, DirAuto>();
  di = 0x2000;
  cx = 0x0fa0;
  rep_stosw<MemAuto, DirAuto>();
  sub_19dce();
  bx = 0x28a0;
  ax = 0;
  sub_19d54();
  sub_19c98();
  ax = memoryAGet16(ds, 0x0008);
  push(ax);
  memoryASet16(ds, 0x0008, 0x0001);
  sub_19eb4();
  ax = pop();
  memoryASet16(ds, 0x0008, ax);
}
void sub_19c98()
{
  bx = memoryAGet16(ds, 0x6df8);
  bx &= 0x0003;
  bl <<= 1;
  si = memoryAGet16(ds, bx + 10961);
  di = 0x1902;
  cx = 0x0801;
  sub_19fcd();
}
void sub_19cb0()
{
  bx = 0x000f;
loc_19cb3:
  memoryASet(ds, bx + 4117, 0x00);
  bx--;
  if (bx != 0)
    goto loc_19cb3;
  di = 0x0140;
  bh = 0x80;
  memoryASet16(ds, 0x2aca, 0x0000);
  sub_19cf6();
  di = 0x0640;
  bh = 0x30;
  memoryASet16(ds, 0x2aca, 0x0005);
  sub_19cf6();
  di = 0x0b40;
  bh = 0x00;
  memoryASet16(ds, 0x2aca, 0x000a);
  sub_19cf6();
  memoryASet(ds, 0x0525, 0x10);
  memoryASet16(ds, 0x052f, 0x0000);
  memoryASet(ds, 0x0531, 0x01);
}
void sub_19cf6()
{
  memoryASet(ds, 0x2ac9, bh);
  memoryASet(ds, 0x2ac4, 0x00);
loc_19cff:
  push(di);
  push(es);
  bx = memoryAGet16(ds, 0x0008);
  bl = memoryAGet(ds, bx + 10938);
  bh = memoryAGet(ds, 0x2ac9);
  ax = 0x1010;
  es = ax;
  di = 0x04d7;
  sub_178ad();
  es = pop();
  di = pop();
  push(di);
  si = 0x04d7;
  cx = 0x1002;
  sub_19fcd();
  bh = 0;
  bl = memoryAGet(ds, 0x2ac4);
  cl = bl;
  bl >>= 1;
  bl >>= 1;
  cl = ~cl;
  cl &= 0x03;
  cl <<= 1;
  al = memoryAGet(ds, 0x0540);
  al <<= cl;
  si = memoryAGet16(ds, 0x2aca);
  memoryASet(ds, bx + si + 4118, memoryAGet(ds, bx + si + 4118) | al);
  di = pop();
  di += 0x0004;
  memoryASet(ds, 0x2ac4, memoryAGet(ds, 0x2ac4) + 1);
  if (memoryAGet(ds, 0x2ac4) < 0x14)
    goto loc_19cff;
}
void sub_19d54()
{
  cx = memoryAGet16(ds, bx);
  memoryASet16(ds, 0x2ac7, cx);
  memoryASet16(ds, 0x2acc, ax);
  bx += 0x0002;
loc_19d60:
  si = memoryAGet16(ds, bx);
  if (si != 0xffff)
    goto loc_19d69;
  return;
loc_19d69:
  di = memoryAGet16(ds, bx + 2);
  di += memoryAGet16(ds, 0x2acc);
  flags.direction = false;
  memoryASet(ds, 0x2ad0, ch);
  ch = 0;
  memoryASet16(ds, 0x2ace, cx);
loc_19d7b:
  cx = memoryAGet16(ds, 0x2ace);
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= memoryAGet16(ds, 0x2ace);
  di ^= 0x2000;
  if (di & 0x2000)
    goto loc_19d92;
  di += 0x0050;
loc_19d92:
  memoryASet(ds, 0x2ad0, memoryAGet(ds, 0x2ad0) - 1);
  if (memoryAGet(ds, 0x2ad0) != 0)
    goto loc_19d7b;
  bx += 0x0004;
  cx = memoryAGet16(ds, 0x2ac7);
  goto loc_19d60;
}
void sub_19da1()
{
  memoryASet(ds, 0x2ac4, 0x04);
loc_19da6:
  si = 0x2680;
  cx = 0x1005;
  push(di);
  sub_19fcd();
  di = pop();
  di += 0x0014;
  memoryASet(ds, 0x2ac4, memoryAGet(ds, 0x2ac4) - 1);
  if (memoryAGet(ds, 0x2ac4) != 0)
    goto loc_19da6;
}
void sub_19dbb()
{
  di = 0x03c5;
  sub_19da1();
  di = 0x08c5;
  sub_19da1();
  di = 0x0dc5;
  sub_19da1();
}
void sub_19dce()
{
  memoryASet16(ds, 0x2ac2, 0x103e);
loc_19dd4:
  memoryASet16(ds, 0x2ac2, memoryAGet16(ds, 0x2ac2) + 0x0002);
  di = memoryAGet16(ds, 0x2ac2);
  if (di >= 0x1090)
    goto loc_19e02;
loc_19de3:
  sub_1a02d();
  dx &= 0x0030;
  if (dl == memoryAGet(ds, 0x2ac4))
    goto loc_19de3;
  memoryASet(ds, 0x2ac4, dl);
  dx += 0x2904;
  si = dx;
  cx = 0x0801;
  sub_19fcd();
  goto loc_19dd4;
loc_19e02:
  di = 0x1180;
  ax = 0x5655;
  cx = 0x0500;
  flags.direction = false;
  rep_stosw<MemAuto, DirAuto>();
  di = 0x3180;
  cx = 0x0500;
  rep_stosw<MemAuto, DirAuto>();
  memoryASet16(ds, 0x2ac2, 0x2944);
loc_19e1c:
  memoryASet(ds, 0x2ac4, 0x09);
loc_19e21:
  sub_1a02d();
  dx &= 0x0776;
  dx += 0x12c0;
  di = dx;
  si = memoryAGet16(ds, 0x2ac2);
  cx = 0x0501;
  sub_19fcd();
  memoryASet(ds, 0x2ac4, memoryAGet(ds, 0x2ac4) - 1);
  if (memoryAGet(ds, 0x2ac4) != 0)
    goto loc_19e21;
  memoryASet16(ds, 0x2ac2, memoryAGet16(ds, 0x2ac2) + 0x000a);
  if (memoryAGet16(ds, 0x2ac2) < 0x296c)
    goto loc_19e1c;
  memoryASet(ds, 0x2ac4, 0x05);
loc_19e50:
  sub_1a02d();
  dx &= 0x003e;
  dx += 0x3a98;
  di = dx;
  si = 0x296c;
  cx = 0x0501;
  sub_19fcd();
  memoryASet(ds, 0x2ac4, memoryAGet(ds, 0x2ac4) - 1);
  if (memoryAGet(ds, 0x2ac4) != 0)
    goto loc_19e50;
}
void sub_19e6d()
{
  memoryASet16(ds, 0x2ac2, di);
  al = 0x03;
  if (di < 0x1720)
    goto loc_19e7b;
  al--;
loc_19e7b:
  memoryASet(ds, 0x2ac4, al);
  memoryASet16(ds, 0x2ac2, memoryAGet16(ds, 0x2ac2) + 0x01e0);
  si = 0x2976;
  cx = 0x0c05;
  sub_19fcd();
loc_19e8d:
  di = memoryAGet16(ds, 0x2ac2);
  memoryASet16(ds, 0x2ac2, memoryAGet16(ds, 0x2ac2) + 0x0140);
  si = 0x29ee;
  cx = 0x0804;
  sub_19fcd();
  memoryASet(ds, 0x2ac4, memoryAGet(ds, 0x2ac4) - 1);
  if (memoryAGet(ds, 0x2ac4) != 0)
    goto loc_19e8d;
  di = memoryAGet16(ds, 0x2ac2);
  si = 0x2a2e;
  cx = 0x0b04;
  sub_19fcd();
}
void sub_19eb4()
{
  bx = memoryAGet16(ds, 0x0008);
  bl = memoryAGet(ds, bx + 10930);
loc_19ebc:
  memoryASet16(ds, 0x2ac5, bx);
  di = memoryAGet16(ds, bx + 10886);
  if (di != 0x0000)
    goto loc_19eca;
  return;
loc_19eca:
  sub_19e6d();
  bx = memoryAGet16(ds, 0x2ac5);
  bx += 0x0002;
  goto loc_19ebc;
}
void sub_19ee0()
{
  al = dl;
  ah = 0x28;
  mul(ah);
  if (!(dl & 0x01))
    goto loc_19eee;
  ax += 0x1fd8;
loc_19eee:
  dx = cx;
  dx >>= 1;
  dx >>= 1;
  ax += dx;
  cl &= 0x03;
  cl <<= 1;
}
void sub_19efc()
{
  flags.direction = false;
  memoryASet(ds, 0x2ae0, cl);
  memoryASet(ds, 0x2ae2, ch);
  ch = 0;
  dx = 0x0ff0;
loc_19f0a:
  cl = memoryAGet(ds, 0x2ae0);
loc_19f0e:
  dx = 0x30c0;
  bx = memoryAGet16(es, di);
  memoryASet16(ds, bp, bx);
  lodsw<MemAuto, DirAuto>();
  memoryASet16(ds, 0x2ae3, ax);
loc_19f1c:
  if (dl & ah)
    goto loc_19f22;
  ah |= dl;
loc_19f22:
  if (dh & ah)
    goto loc_19f28;
  ah |= dh;
loc_19f28:
  if (dl & al)
    goto loc_19f2e;
  al |= dl;
loc_19f2e:
  if (dh & al)
    goto loc_19f34;
  al |= dh;
loc_19f34:
  dx ^= 0x33cc;
  if (dh & 0x03)
    goto loc_19f1c;
  ax &= bx;
  ax |= memoryAGet16(ds, 0x2ae3);
  stosw<MemAuto, DirAuto>();
  bp += 0x0002;
  if (--cx)
    goto loc_19f0e;
  di -= memoryAGet16(ds, 0x2ae0);
  di -= memoryAGet16(ds, 0x2ae0);
  di ^= 0x2000;
  if (di & 0x2000)
    goto loc_19f5e;
  di += 0x0050;
loc_19f5e:
  memoryASet(ds, 0x2ae2, memoryAGet(ds, 0x2ae2) - 1);
  if (memoryAGet(ds, 0x2ae2) != 0)
    goto loc_19f0a;
}
void sub_19f65()
{
  flags.direction = false;
  memoryASet(ds, 0x2ae0, cl);
  memoryASet(ds, 0x2ae2, ch);
  ch = 0;
loc_19f70:
  cl = memoryAGet(ds, 0x2ae0);
loc_19f74:
  bx = memoryAGet16(es, di);
  memoryASet16(ds, bp, bx);
  lodsw<MemAuto, DirAuto>();
  ax &= bx;
  stosw<MemAuto, DirAuto>();
  bp += 0x0002;
  if (--cx)
    goto loc_19f74;
  di -= memoryAGet16(ds, 0x2ae0);
  di -= memoryAGet16(ds, 0x2ae0);
  di ^= 0x2000;
  if (di & 0x2000)
    goto loc_19f99;
  di += 0x0050;
loc_19f99:
  memoryASet(ds, 0x2ae2, memoryAGet(ds, 0x2ae2) - 1);
  if (memoryAGet(ds, 0x2ae2) != 0)
    goto loc_19f70;
}
void sub_19fa0()
{
  flags.direction = false;
  memoryASet16(ds, 0x2ae9, si);
  memoryASet(ds, 0x2ae0, cl);
  memoryASet(ds, 0x2ae2, ch);
  al <<= 1;
  memoryASet(ds, 0x2aeb, al);
  ch = 0;
loc_19fb4:
  cl = memoryAGet(ds, 0x2ae0);
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  cl = memoryAGet(ds, 0x2aeb);
  memoryASet16(ds, 0x2ae9, memoryAGet16(ds, 0x2ae9) + cx);
  si = memoryAGet16(ds, 0x2ae9);
  memoryASet(ds, 0x2ae2, memoryAGet(ds, 0x2ae2) - 1);
  if (memoryAGet(ds, 0x2ae2) != 0)
    goto loc_19fb4;
}
void sub_19fcd()
{
  flags.direction = false;
  memoryASet(ds, 0x2ae0, cl);
  memoryASet(ds, 0x2ae2, ch);
  ch = 0;
loc_19fd8:
  cl = memoryAGet(ds, 0x2ae0);
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di -= memoryAGet16(ds, 0x2ae0);
  di -= memoryAGet16(ds, 0x2ae0);
  di ^= 0x2000;
  if (di & 0x2000)
    goto loc_19ff3;
  di += 0x0050;
loc_19ff3:
  memoryASet(ds, 0x2ae2, memoryAGet(ds, 0x2ae2) - 1);
  if (memoryAGet(ds, 0x2ae2) != 0)
    goto loc_19fd8;
}
void sub_19ffa()
{
  flags.direction = false;
  memoryASet(es, 0x2ae0, cl);
  memoryASet(es, 0x2ae2, ch);
  ch = 0;
loc_1a007:
  cl = memoryAGet(es, 0x2ae0);
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  si -= memoryAGet16(es, 0x2ae0);
  si -= memoryAGet16(es, 0x2ae0);
  si ^= 0x2000;
  if (si & 0x2000)
    goto loc_1a025;
  si += 0x0050;
loc_1a025:
  memoryASet(es, 0x2ae2, memoryAGet(es, 0x2ae2) - 1);
  if (memoryAGet(es, 0x2ae2) != 0)
    goto loc_1a007;
}
void sub_1a02d()
{
  dx = memoryAGet16(ds, 0x2ae5);
  dl ^= dh;
  dl >>= 1;
  flags.carry = dl & 1;
  dl >>= 1;
  memoryASet16(ds, 0x2ae5, rcr(memoryAGet16(ds, 0x2ae5), 0x0001));
  dx = memoryAGet16(ds, 0x2ae5);
}
void sub_1a040()
{
  al = 0x00;
  out(0x0043, al);
  in(al, 0x40);
  ah = al;
  in(al, 0x40);
  if (ax != 0x0000)
    goto loc_1a055;
  ax = 0xfa59;
loc_1a055:
  memoryASet16(ds, 0x2ae5, ax);
}
void sub_1a059()
{
  ax += si;
  if (ax < bx)
    goto loc_1a07f;
  ax -= si;
  flags.carry = ax < di;
  ax -= di;
  if (!flags.carry)
    goto loc_1a067;
  ax = 0;
loc_1a067:
  if (ax > bx)
    goto loc_1a07f;
  dl += cl;
  if (dl < dh)
    goto loc_1a07f;
  dl -= cl;
  flags.carry = dl < ch;
  dl -= ch;
  if (!flags.carry)
    goto loc_1a079;
  dl = 0;
loc_1a079:
  if (dl > dh)
    goto loc_1a07f;
  flags.carry = true;
  return;
loc_1a07f:
  flags.carry = false;
}
void sub_1a090()
{
  if (memoryAGet16(ds, 0x2e8d) < 0x0008)
    goto loc_1a098;
loc_1a097:
  return;
loc_1a098:
  if (memoryAGet(ds, 0x069a) != 0x00)
    goto loc_1a097;
  memoryASet16(ds, 0x2e92, 0xffff);
  memoryASet(ds, 0x2e91, 0xff);
  cx = 0x0007;
loc_1a0ad:
  bx = cx;
  bx--;
  al = memoryAGet(ds, 0x057b);
  flags.carry = al < memoryAGet(ds, bx + 11220);
  al -= memoryAGet(ds, bx + 11220);
  if (!flags.carry)
    goto loc_1a0bb;
  al = ~al;
loc_1a0bb:
  if (al > memoryAGet(ds, 0x2e91))
    goto loc_1a0c8;
  memoryASet(ds, 0x2e91, al);
  memoryASet16(ds, 0x2e92, bx);
loc_1a0c8:
  if (--cx)
    goto loc_1a0ad;
  if (memoryAGet16(ds, 0x2e92) != 0xffff)
    goto loc_1a0d8;
  memoryASet16(ds, 0x2e92, 0x0000);
loc_1a0d8:
  bx = memoryAGet16(ds, 0x2e8d);
  si = memoryAGet16(ds, 0x2e92);
  al = memoryAGet(ds, si + 11220);
  memoryASet(ds, bx + 11114, al);
  memoryASet(ds, 0x2e98, al);
  ax = memoryAGet16(ds, 0x0579);
  bl <<= 1;
  if (ax < 0x0108)
    goto loc_1a0f8;
  ax = 0x0107;
loc_1a0f8:
  ax &= 0x0ffc;
  memoryASet16(ds, bx + 11098, ax);
  memoryASet16(ds, 0x2e96, ax);
  cx = 0x0008;
loc_1a105:
  bx = cx;
  bx--;
  if (bx == memoryAGet16(ds, 0x2e8d))
    goto loc_1a137;
  if (memoryAGet(ds, bx + 11122) == 0x00)
    goto loc_1a137;
  push(cx);
  dl = memoryAGet(ds, bx + 11114);
  bl <<= 1;
  ax = memoryAGet16(ds, bx + 11098);
  bx = memoryAGet16(ds, 0x2e96);
  dh = memoryAGet(ds, 0x2e98);
  si = 0x0018;
  di = si;
  cx = 0x0f0f;
  sub_1a059();
  cx = pop();
  if (!flags.carry)
    goto loc_1a137;
  return;
loc_1a137:
  if (--cx)
    goto loc_1a105;
  sub_18413();
  if (memoryAGet(ds, 0x70f2) == 0x00)
    goto loc_1a146;
  sub_1d45b();
loc_1a146:
  bx = memoryAGet16(ds, 0x2e8d);
  memoryASet16(ds, 0x2e94, bx);
  memoryASet(ds, bx + 11122, 0x01);
  dl = memoryAGet(ds, bx + 11114);
  bl <<= 1;
  cx = memoryAGet16(ds, bx + 11098);
  sub_19ee0();
  di = ax;
  si = 0x2af0;
  ax = 0xb800;
  es = ax;
  cx = 0x0f03;
  sub_19fcd();
  memoryASet16(ds, 0x2e8d, 0xffff);
  bx = 0;
  ah = 0x0b;
  interrupt(0x10);
  sub_1c06e();
  if (memoryAGet(ds, 0x70f2) == 0x00)
    goto loc_1a189;
  sub_1d42a();
loc_1a189:
  sub_18375();
  ax = 0x03e8;
  bx = 0x04a5;
  sub_1cb6b();
}
void sub_1a196()
{
  ah = 0;
  interrupt(0x1a);
  if (dx != memoryAGet16(ds, 0x2e8f))
    goto loc_1a1a1;
  return;
loc_1a1a1:
  memoryASet16(ds, 0x2e8f, dx);
  if (memoryAGet16(ds, 0x2e8d) < 0x0008)
    goto loc_1a1dc;
  cx = 0x0008;
loc_1a1af:
  bx = cx;
  bx--;
  if (memoryAGet(ds, bx + 11122) == 0x00)
    goto loc_1a1da;
  push(cx);
  dl = memoryAGet(ds, bx + 11114);
  bl <<= 1;
  ax = memoryAGet16(ds, bx + 11098);
  si = 0x0018;
  di = si;
  bx = memoryAGet16(ds, 0x0579);
  dh = memoryAGet(ds, 0x057b);
  cx = 0x0e0f;
  sub_1a059();
  cx = pop();
  if (flags.carry)
    goto loc_1a1e3;
loc_1a1da:
  if (--cx)
    goto loc_1a1af;
loc_1a1dc:
  memoryASet16(ds, 0x2e94, 0xffff);
loc_1a1e2:
  return;
loc_1a1e3:
  bx = cx;
  bx--;
  if (bx == memoryAGet16(ds, 0x2e94))
    goto loc_1a1e2;
  push(bx);
  sub_18413();
  if (memoryAGet(ds, 0x70f2) == 0x00)
    goto loc_1a1fa;
  sub_1d45b();
loc_1a1fa:
  bx = pop();
  memoryASet(ds, bx + 11122, 0x00);
  dl = memoryAGet(ds, bx + 11114);
  memoryASet16(ds, 0x2e8d, bx);
  bl <<= 1;
  cx = memoryAGet16(ds, bx + 11098);
  sub_19ee0();
  di = ax;
  si = 0x2b7a;
  ax = 0xb800;
  es = ax;
  cx = 0x0f03;
  sub_19fcd();
  if (memoryAGet(ds, 0x70f2) == 0x00)
    goto loc_1a22b;
  sub_1d42a();
loc_1a22b:
  sub_18375();
  bx = 0x0001;
  ah = 0x0b;
  interrupt(0x10);
  ax = 0x03e8;
  bx = 0x0349;
  sub_1cb6b();
}
void sub_1a23f()
{
  ax = 0;
  bx = 0x2e24;
  sub_19d54();
  memoryASet(ds, 0x2e8a, 0xbf);
  memoryASet16(ds, 0x2e8b, 0x0000);
loc_1a252:
  memoryASet16(ds, 0x2e88, 0x0020);
loc_1a258:
  bx = 0;
  if (memoryAGet(ds, 0x2e8a) == 0xbf)
    goto loc_1a269;
  sub_1a02d();
  bl = dl;
  bl &= 0x02;
loc_1a269:
  cx = memoryAGet16(ds, 0x2e88);
  dl = memoryAGet(ds, 0x2e8a);
  push(bx);
  sub_1a313();
  bx = pop();
  si = memoryAGet16(ds, 0x2e8b);
  ax = memoryAGet16(ds, 0x2e88);
  cl = 0x04;
  ax >>= cl;
  flags.carry = ax < 0x0002;
  ax -= 0x0002;
  if (!flags.carry)
    goto loc_1a288;
  ax = 0;
loc_1a288:
  if (ax < 0x0012)
    goto loc_1a290;
  ax = 0x0011;
loc_1a290:
  dl = memoryAGet(ds, si + 11227);
  dh = 0;
  ax += dx;
  si = ax;
  memoryASet(ds, si + 11234, bl);
  memoryASet16(ds, 0x2e88, memoryAGet16(ds, 0x2e88) + 0x0010);
  if (memoryAGet16(ds, 0x2e88) < 0x0111)
    goto loc_1a258;
  memoryASet16(ds, 0x2e8b, memoryAGet16(ds, 0x2e8b) + 1);
  memoryASet(ds, 0x2e8a, memoryAGet(ds, 0x2e8a) - 0x18);
  if (memoryAGet(ds, 0x2e8a) >= 0x2f)
    goto loc_1a252;
  ax = 0xffff;
  memoryASet16(ds, 0x2e8d, ax);
  memoryASet16(ds, 0x2e94, ax);
  ax = 0;
  memoryASet16(ds, 0x2b72, ax);
  memoryASet16(ds, 0x2b74, ax);
  memoryASet16(ds, 0x2b76, ax);
  memoryASet16(ds, 0x2b78, ax);
  cx = memoryAGet16(ds, 0x0414);
  if (cx != 0x0000)
    goto loc_1a2e0;
  cx++;
  memoryASet16(ds, 0x0414, cx);
loc_1a2e0:
  if (cx <= 0x0008)
    goto loc_1a2e8;
  cx = 0x0008;
loc_1a2e8:
  bx = cx;
  bx--;
  memoryASet(ds, bx + 11122, 0x01);
  dl = 0xb0;
  memoryASet(ds, bx + 11114, dl);
  push(cx);
  bl <<= 1;
  cx = memoryAGet16(ds, bx + 11082);
  memoryASet16(ds, bx + 11098, cx);
  sub_19ee0();
  di = ax;
  si = 0x2af0;
  cx = 0x0f03;
  sub_19fcd();
  cx = pop();
  if (--cx)
    goto loc_1a2e8;
}
void sub_1a313()
{
  push(bx);
  sub_19ee0();
  di = ax;
  ax = 0xb800;
  es = ax;
  bx = pop();
  si = memoryAGet16(ds, bx + 11808);
  cx = 0x0802;
  sub_19fcd();
}
void sub_1a32a()
{
  al = memoryAGet(ds, 0x057b);
  al -= 0x05;
  al &= 0xf8;
  cx = 0x0007;
loc_1a334:
  bx = cx;
  bx--;
  if (al == memoryAGet(ds, bx + 11220))
    goto loc_1a341;
  if (--cx)
    goto loc_1a334;
  goto loc_1a37d;
loc_1a341:
  ch = al;
  ax = memoryAGet16(ds, 0x0579);
  ax += 0x0007;
  cl = 0x04;
  ax >>= cl;
  flags.carry = ax < 0x0002;
  ax -= 0x0002;
  if (!flags.carry)
    goto loc_1a354;
  ax = 0;
loc_1a354:
  if (ax < 0x0012)
    goto loc_1a35c;
  ax = 0x0011;
loc_1a35c:
  dl = memoryAGet(ds, bx + 11227);
  dh = 0;
  ax += dx;
  si = ax;
  if (memoryAGet(ds, si + 11234) != 0x00)
    goto loc_1a37d;
  ch += 0x05;
  memoryASet(ds, 0x057b, ch);
  ch += 0x32;
  memoryASet(ds, 0x057c, ch);
  flags.carry = true;
  return;
loc_1a37d:
  flags.carry = false;
}
void sub_1a380()
{
  ah = 0;
  interrupt(0x1a);
  bx = memoryAGet16(ds, 0x0004);
  bl <<= 1;
  cx = memoryAGet16(ds, bx + 13042);
  ax = dx;
  ax -= memoryAGet16(ds, 0x328c);
  if (ax >= cx)
    goto loc_1a399;
loc_1a398:
  return;
loc_1a399:
  memoryASet16(ds, 0x328c, dx);
  sub_1a5ea();
  if (flags.carry)
    goto loc_1a398;
  sub_19410();
  if (flags.carry)
    goto loc_1a398;
  memoryASet(ds, 0x32ea, memoryAGet(ds, 0x32ea) + 1);
  sub_1a02d();
  al = memoryAGet(ds, 0x32ea);
  al &= dl;
  memoryASet(ds, 0x32eb, memoryAGet(ds, 0x32eb) ^ al);
  ax = memoryAGet16(ds, 0x327d);
  flags.carry = ax < memoryAGet16(ds, 0x0579);
  ax -= memoryAGet16(ds, 0x0579);
  dl = 0xff;
  if (!flags.carry)
    goto loc_1a3c6;
  ax = ~ax;
  dl = 0x01;
loc_1a3c6:
  memoryASet(ds, 0x32ed, dl);
  bl = memoryAGet(ds, 0x327f);
  bl += 0x14;
  flags.carry = bl < memoryAGet(ds, 0x057b);
  bl -= memoryAGet(ds, 0x057b);
  dl = 0xff;
  if (!flags.carry)
    goto loc_1a3dd;
  bl = ~bl;
  dl = 0x01;
loc_1a3dd:
  memoryASet(ds, 0x32ee, dl);
  ax >>= 1;
  ax >>= 1;
  bl >>= 1;
  al += bl;
  memoryASet(ds, 0x32ec, al);
  bx = memoryAGet16(ds, 0x328a);
  if (bx < 0x0027)
    goto loc_1a3fc;
  bx = 0x0026;
  memoryASet16(ds, 0x328a, bx);
loc_1a3fc:
  if (memoryAGet(ds, bx + 12942) != 0x00)
    goto loc_1a47b;
  memoryASet16(ds, 0x328a, memoryAGet16(ds, 0x328a) - 1);
  ah = 0;
  interrupt(0x1a);
  dx -= memoryAGet16(ds, 0x0410);
  cl = 0x03;
  dx >>= cl;
  al = memoryAGet(ds, 0x32ec);
  flags.carry = al < dl;
  al -= dl;
  if (!flags.carry)
    goto loc_1a41c;
  al = 0;
loc_1a41c:
  if (al < memoryAGet(ds, 0x32eb))
    goto loc_1a442;
  memoryASet(ds, 0x3281, 0x01);
  sub_1a02d();
  if (dl == 0x00)
    goto loc_1a43b;
  if (dl > 0x07)
    goto loc_1a43f;
  dl &= 0x01;
  if (dl != 0)
    goto loc_1a43b;
  dl = 0xff;
loc_1a43b:
  memoryASet(ds, 0x3280, dl);
loc_1a43f:
  goto loc_1a4dc;
loc_1a442:
  al = memoryAGet(ds, 0x32eb);
  al &= 0x2f;
  if (al != 0)
    goto loc_1a468;
  sub_1a02d();
  dl &= 0x01;
  if (dl != 0)
    goto loc_1a453;
  dl = 0xff;
loc_1a453:
  memoryASet(ds, 0x3280, dl);
  sub_1a02d();
  dl &= 0x01;
  if (dl != 0)
    goto loc_1a461;
  dl = 0xff;
loc_1a461:
  memoryASet(ds, 0x3281, dl);
  goto loc_1a4dc;
  //   gap of 1 bytes
loc_1a468:
  al &= 0x07;
  if (al != 0)
    goto loc_1a4dc;
  al = memoryAGet(ds, 0x32ed);
  memoryASet(ds, 0x3280, al);
  al = memoryAGet(ds, 0x32ee);
  memoryASet(ds, 0x3281, al);
  goto loc_1a4dc;
  //   gap of 1 bytes
loc_1a47b:
  memoryASet(ds, 0x3281, 0x01);
  ax = bx;
  cl = 0x03;
  ax <<= cl;
  if (memoryAGet16(ds, 0x327d) == ax)
    goto loc_1a499;
  dl = 0x01;
  if (memoryAGet16(ds, 0x327d) < ax)
    goto loc_1a492;
  dl = 0xff;
loc_1a492:
  memoryASet(ds, 0x3280, dl);
  goto loc_1a4dc;
  //   gap of 1 bytes
loc_1a499:
  memoryASet(ds, 0x3280, 0x00);
  if (memoryAGet(ds, 0x327f) != 0xa5)
    goto loc_1a4dc;
  memoryASet(ds, 0x3281, 0x00);
  if (memoryAGet16(ds, 0x327a) == 0x0006)
    goto loc_1a4b8;
  if (memoryAGet16(ds, 0x327a) != 0x0012)
    goto loc_1a4dc;
loc_1a4b8:
  push(bx);
  si = 0x31e8;
  di = memoryAGet16(ds, 0x3282);
  cx = 0x1e02;
  ax = 0xb800;
  es = ax;
  sub_19fcd();
  bx = pop();
  memoryASet(ds, bx + 12942, memoryAGet(ds, bx + 12942) - 1);
  al = memoryAGet(ds, bx + 12942);
  sub_1a6af();
  memoryASet(ds, 0x3286, 0x01);
loc_1a4dc:
  cx = memoryAGet16(ds, 0x327d);
  dl = memoryAGet(ds, 0x327f);
  memoryASet16(ds, 0x32ef, cx);
  memoryASet(ds, 0x32f1, dl);
  if (memoryAGet(ds, 0x3280) < 0x01)
    goto loc_1a50a;
  if (memoryAGet(ds, 0x3280) != 0x01)
    goto loc_1a503;
  cx += 0x0008;
  if (cx < 0x0131)
    goto loc_1a50a;
  cx = 0x0130;
  goto loc_1a50a;
loc_1a503:
  flags.carry = cx < 0x0008;
  cx -= 0x0008;
  if (!flags.carry)
    goto loc_1a50a;
  cx = 0;
loc_1a50a:
  cx &= 0xfff8;
  memoryASet16(ds, 0x327d, cx);
  if (memoryAGet(ds, 0x3281) < 0x01)
    goto loc_1a52e;
  if (memoryAGet(ds, 0x3281) != 0x01)
    goto loc_1a527;
  dl += 0x02;
  if (dl < 0xa6)
    goto loc_1a52e;
  dl = 0xa5;
  goto loc_1a52e;
loc_1a527:
  flags.carry = dl < 0x02;
  dl -= 0x02;
  if (!flags.carry)
    goto loc_1a52e;
  dl = 0;
loc_1a52e:
  memoryASet(ds, 0x327f, dl);
  sub_19ee0();
  memoryASet16(ds, 0x3284, ax);
  sub_1a5ea();
  if (!flags.carry)
    goto loc_1a558;
loc_1a53d:
  memoryASet(ds, 0x3280, 0x00);
  memoryASet(ds, 0x3281, 0x00);
  cx = memoryAGet16(ds, 0x32ef);
  memoryASet16(ds, 0x327d, cx);
  dl = memoryAGet(ds, 0x32f1);
  memoryASet(ds, 0x327f, dl);
  return;
loc_1a558:
  sub_19410();
  if (flags.carry)
    goto loc_1a53d;
  sub_1a5d0();
  memoryASet16(ds, 0x327a, memoryAGet16(ds, 0x327a) + 0x0002);
  sub_1a569();
}
void sub_1a569()
{
loc_1a569:
  bx = memoryAGet16(ds, 0x327a);
  ax = memoryAGet16(ds, bx + 12896);
  if (ax != 0x0000)
    goto loc_1a57b;
  memoryASet16(ds, 0x327a, ax);
  goto loc_1a569;
loc_1a57b:
  si = ax;
  di = memoryAGet16(ds, 0x3284);
  memoryASet16(ds, 0x3282, di);
  bp = 0x31e8;
  ax = 0xb800;
  es = ax;
  cx = 0x1e02;
  memoryASet(ds, 0x3286, 0x00);
  flags.direction = false;
  memoryASet(ds, 0x3289, ch);
  ch = 0;
  memoryASet16(ds, 0x3287, cx);
loc_1a5a0:
  cx = memoryAGet16(ds, 0x3287);
loc_1a5a4:
  bx = memoryAGet16(es, di);
  memoryASet16(ds, bp, bx);
  lodsw<MemAuto, DirAuto>();
  ax |= bx;
  stosw<MemAuto, DirAuto>();
  bp += 0x0002;
  if (--cx)
    goto loc_1a5a4;
  di -= memoryAGet16(ds, 0x3287);
  di -= memoryAGet16(ds, 0x3287);
  di ^= 0x2000;
  if (di & 0x2000)
    goto loc_1a5c9;
  di += 0x0050;
loc_1a5c9:
  memoryASet(ds, 0x3289, memoryAGet(ds, 0x3289) - 1);
  if (memoryAGet(ds, 0x3289) != 0)
    goto loc_1a5a0;
}
void sub_1a5d0()
{
  if (memoryAGet(ds, 0x3286) != 0x00)
    return;
  ax = 0xb800;
  es = ax;
  si = 0x31e8;
  di = memoryAGet16(ds, 0x3282);
  cx = 0x1e02;
  sub_19fcd();
}
// INJECT: Error: cannot inject carry flag in sub_1a5ea()!
void sub_1a5ea()
{
  if (memoryAGet(ds, 0x1cb8) != 0x00)
    goto loc_1a633;
  if (memoryAGet16(ds, 0x0004) != 0x0006)
    goto loc_1a603;
  if (memoryAGet(ds, 0x44bd) == 0x00)
    goto loc_1a603;
  sub_1b9e0();
  stop(/*inject ret*/);
  return;
loc_1a603:
  ax = memoryAGet16(ds, 0x327d);
  dl = memoryAGet(ds, 0x327f);
  si = 0x0010;
  bx = memoryAGet16(ds, 0x0579);
  dh = memoryAGet(ds, 0x057b);
  di = 0x0018;
  cx = 0x0e1e;
  sub_1a059();
  if (!flags.carry)
    goto loc_1a633;
  if (memoryAGet16(ds, 0x0004) != 0x0004)
    goto loc_1a62e;
  if (memoryAGet(ds, 0x39e1) != 0x00)
    goto loc_1a631;
loc_1a62e:
  sub_17aa2();
loc_1a631:
  flags.carry = true;
  return;
loc_1a633:
  flags.carry = false;
}
void sub_1a635()
{
  flags.direction = false;
  ax = 0;
  push(ds);
  es = pop();
  di = 0x328e;
  cx = 0x0014;
  rep_stosw<MemAuto, DirAuto>();
  memoryASet16(ds, 0x32b6, 0x00ff);
  memoryASet16(ds, 0x327a, 0x0000);
  memoryASet16(ds, 0x327d, 0x0000);
  memoryASet(ds, 0x327f, 0xa0);
  memoryASet(ds, 0x3286, 0x01);
  memoryASet(ds, 0x3280, 0x00);
  memoryASet(ds, 0x3281, 0x00);
  sub_1a02d();
  memoryASet(ds, 0x32eb, dl);
  memoryASet(ds, 0x32ea, 0x6c);
}
void sub_1a675()
{
  if (memoryAGet(ds, 0x057b) < 0xb4)
    return;
  if (memoryAGet(ds, 0x056e) == 0x00)
    return;
  ax = memoryAGet16(ds, 0x0579);
  ax += 0x000c;
  cl = 0x03;
  ax >>= cl;
  if (ax > 0x0027)
    return;
  if (ax == memoryAGet16(ds, 0x32b6))
    return;
  memoryASet16(ds, 0x32b6, ax);
  bx = ax;
  al = memoryAGet(ds, bx + 12942);
  if (al >= 0x04)
    return;
  al++;
  memoryASet(ds, bx + 12942, al);
  sub_1a6af();
}
void sub_1a6af()
{
  ah = 0x0a;
  mul(ah);
  ax += 0x32b8;
  si = ax;
  di = bx;
  di <<= 1;
  di += 0x1e00;
  ax = 0xb800;
  es = ax;
  cx = 0x0501;
  sub_19fcd();
}
// INJECT: Error: cannot inject carry flag in sub_1a6d0()!
void sub_1a6d0()
{
  memoryASet16(ds, 0x3511, 0x0000);
  memoryASet(ds, 0x351b, 0x00);
loc_1a6db:
  bx = memoryAGet16(ds, 0x3511);
  if (memoryAGet(ds, bx + 13479) == 0x00)
    goto loc_1a6e9;
loc_1a6e6:
  goto loc_1a7dd;
loc_1a6e9:
  si = bx;
  si <<= 1;
  ax = memoryAGet16(ds, si + 13383);
  dl = memoryAGet(ds, bx + 13431);
  di = 0x0000;
  if (bx < 0x000c)
    goto loc_1a700;
  di = 0x0002;
loc_1a700:
  si = memoryAGet16(ds, di + 13587);
  cx = memoryAGet16(ds, di + 13591);
  bx = memoryAGet16(ds, 0x0579);
  dh = memoryAGet(ds, 0x057b);
  di = 0x0018;
  ch = 0x0e;
  sub_1a059();
  if (!flags.carry)
    goto loc_1a6e6;
  bx = memoryAGet16(ds, 0x3511);
  if (bx < 0x000c)
    goto loc_1a79f;
  if (memoryAGet(ds, 0x0553) != 0x00)
    goto loc_1a79f;
  if (memoryAGet(ds, 0x05f3) != 0x00)
    goto loc_1a79f;
  memoryASet(ds, 0x0552, 0x01);
  cx = memoryAGet16(ds, 0x0579);
  flags.carry = cx < 0x0008;
  cx -= 0x0008;
  if (!flags.carry)
    goto loc_1a741;
  cx = 0;
loc_1a741:
  if (cx < 0x0117)
    goto loc_1a74a;
  cx = 0x0116;
loc_1a74a:
  dl = memoryAGet(ds, 0x057b);
  if (dl < 0xb5)
    goto loc_1a755;
  dl = 0xb4;
loc_1a755:
  sub_19ee0();
  di = ax;
  si = 0x3350;
  ax = 0xb800;
  es = ax;
  cx = 0x1205;
  sub_19fcd();
  sub_1c9c7();
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x3509, dx);
loc_1a773:
  push(dx);
loc_1a774:
  sub_1c9d6();
  sub_18608();
  if (flags.zero)
    goto loc_1a774;
  sub_1c9d6();
  dx = pop();
  bx = 0x0001;
  if (dl & 0x01)
    goto loc_1a78a;
  bl = 0x0f;
loc_1a78a:
  ah = 0x0b;
  interrupt(0x10);
  sub_1c9d6();
  ah = 0;
  interrupt(0x1a);
  dx -= memoryAGet16(ds, 0x3509);
  if (dx < 0x000d)
    goto loc_1a773;
  stop(/*inject ret*/);
  return;
loc_1a79f:
  memoryASet(ds, 0x351b, memoryAGet(ds, 0x351b) + 1);
  ax = 0x05dc;
  bx = 0x0425;
  sub_1cb6b();
  if (memoryAGet(ds, 0x351b) != 0x01)
    goto loc_1a7b6;
  sub_18413();
loc_1a7b6:
  bx = memoryAGet16(ds, 0x3511);
  sub_1a9f1();
  bx = memoryAGet16(ds, 0x3511);
  memoryASet(ds, bx + 13479, 0x01);
  if (bx >= 0x000c)
    goto loc_1a7dd;
  memoryASet(ds, 0x3410, memoryAGet(ds, 0x3410) - 1);
  if (memoryAGet(ds, 0x3410) != 0)
    goto loc_1a7dd;
  if (memoryAGet(ds, 0x05f3) != 0x00)
    goto loc_1a7dd;
  memoryASet(ds, 0x0553, 0x01);
loc_1a7dd:
  memoryASet16(ds, 0x3511, memoryAGet16(ds, 0x3511) + 1);
  if (memoryAGet16(ds, 0x3511) >= 0x0018)
    goto loc_1a7eb;
  goto loc_1a6db;
loc_1a7eb:
  if (memoryAGet(ds, 0x351b) == 0x00)
    goto loc_1a7f7;
  sub_1a86d();
  flags.carry = true;
  return;
loc_1a7f7:
  flags.carry = false;
}
void sub_1a7f9()
{
  memoryASet16(ds, 0x3411, 0x0000);
  memoryASet16(ds, 0x3415, 0x0000);
  memoryASet(ds, 0x3410, 0x0c);
  cx = 0x0018;
loc_1a80d:
  bx = cx;
  bx--;
  memoryASet(ds, bx + 13455, 0x01);
  memoryASet(ds, bx + 13479, 0x00);
  al = memoryAGet(ds, bx + 13553);
  memoryASet(ds, bx + 13431, al);
  memoryASet(ds, bx + 13359, 0x01);
  sub_1a02d();
  dl &= 0x01;
  if (dl != 0)
    goto loc_1a831;
  dl = ~dl;
loc_1a831:
  memoryASet(ds, bx + 13335, dl);
  bx <<= 1;
  sub_1a02d();
  dh = 0;
  memoryASet16(ds, bx + 13383, dx);
  if (--cx)
    goto loc_1a80d;
  bx = memoryAGet16(ds, 0x0008);
  cl = memoryAGet(ds, bx + 13596);
  ch = 0;
loc_1a84c:
  sub_1a02d();
  dl &= 0x0f;
  if (dl >= 0x0c)
    goto loc_1a84c;
  bl = dl;
  bl += 0x0c;
  bh = 0;
  if (memoryAGet(ds, bx + 13479) != 0x00)
    goto loc_1a84c;
  memoryASet(ds, bx + 13479, 0x01);
  if (--cx)
    goto loc_1a84c;
}
void sub_1a86d()
{
loc_1a86d:
  cx = 0x000c;
loc_1a870:
  bx = cx;
  bx += 0x000b;
  if (memoryAGet(ds, bx + 13479) == 0x00)
    goto loc_1a8a2;
  ax = 0;
  dl = 0x01;
  memoryASet(ds, bx + 13479, al);
  if (memoryAGet16(ds, 0x0579) > 0x00a0)
    goto loc_1a891;
  ax = 0x012e;
  dl = 0xff;
loc_1a891:
  memoryASet(ds, bx + 13335, dl);
  bl <<= 1;
  memoryASet16(ds, bx + 13383, ax);
  memoryASet(ds, 0x351b, memoryAGet(ds, 0x351b) - 1);
  if (memoryAGet(ds, 0x351b) != 0)
    goto loc_1a86d;
  return;
loc_1a8a2:
  if (--cx)
    goto loc_1a870;
}
void sub_1a8a5()
{
  ah = 0;
  interrupt(0x1a);
  if (dx != memoryAGet16(ds, 0x3509))
    goto loc_1a8b0;
loc_1a8af:
  return;
loc_1a8b0:
  memoryASet16(ds, 0x350b, dx);
  memoryASet16(ds, 0x3415, memoryAGet16(ds, 0x3415) + 1);
  bx = memoryAGet16(ds, 0x3415);
  if (bx < 0x0018)
    goto loc_1a8d4;
  bx = 0;
  memoryASet16(ds, 0x3415, bx);
  memoryASet16(ds, 0x3411, memoryAGet16(ds, 0x3411) ^ 0x000c);
  memoryASet16(ds, 0x3413, memoryAGet16(ds, 0x3413) + 0x0008);
  goto loc_1a8e7;
loc_1a8d4:
  if (bx != 0x000c)
    goto loc_1a8ed;
  if (memoryAGet(ds, 0x0697) != 0xfd)
    goto loc_1a8e7;
  if (memoryAGet(ds, 0x057b) < 0x30)
    goto loc_1a8ed;
loc_1a8e7:
  ax = memoryAGet16(ds, 0x350b);
  memoryASet16(ds, 0x3509, ax);
loc_1a8ed:
  si = bx;
  si <<= 1;
  if (memoryAGet(ds, bx + 13479) != 0x00)
    goto loc_1a8af;
  sub_1a02d();
  if (dl > 0x10)
    goto loc_1a919;
  dl &= 0x01;
  if (dl != 0)
    goto loc_1a907;
  dl = ~dl;
loc_1a907:
  memoryASet(ds, bx + 13335, dl);
  sub_1a02d();
  dl &= 0x01;
  if (dl != 0)
    goto loc_1a915;
  dl = ~dl;
loc_1a915:
  memoryASet(ds, bx + 13359, dl);
loc_1a919:
  cx = 0x0004;
  if (bx < 0x000c)
    goto loc_1a923;
  cl >>= 1;
loc_1a923:
  ax = memoryAGet16(ds, si + 13383);
  if (memoryAGet(ds, bx + 13335) == 0x01)
    goto loc_1a93b;
  flags.carry = ax < cx;
  ax -= cx;
  if (!flags.carry)
    goto loc_1a94a;
  ax = 0;
  memoryASet(ds, bx + 13335, 0x01);
  goto loc_1a94a;
loc_1a93b:
  ax += cx;
  if (ax < 0x012f)
    goto loc_1a94a;
  ax = 0x012e;
  memoryASet(ds, bx + 13335, 0xff);
loc_1a94a:
  memoryASet16(ds, si + 13383, ax);
  al = memoryAGet(ds, bx + 13431);
  if (memoryAGet(ds, bx + 13359) == 0x01)
    goto loc_1a96c;
  al--;
  if (al >= memoryAGet(ds, bx + 13553))
    goto loc_1a980;
  al = memoryAGet(ds, bx + 13553);
  memoryASet(ds, bx + 13359, 0x01);
  goto loc_1a980;
loc_1a96c:
  al++;
  dl = memoryAGet(ds, bx + 13553);
  dl += 0x18;
  if (al <= dl)
    goto loc_1a980;
  al = dl;
  memoryASet(ds, bx + 13359, 0xff);
loc_1a980:
  memoryASet(ds, bx + 13431, al);
  dl = al;
  cx = memoryAGet16(ds, si + 13383);
  sub_19ee0();
  memoryASet16(ds, 0x34ef, ax);
  bx = memoryAGet16(ds, 0x3415);
  sub_1a9f1();
  bx = memoryAGet16(ds, 0x3415);
  si = bx;
  si <<= 1;
  di = memoryAGet16(ds, 0x34ef);
  memoryASet16(ds, si + 13503, di);
  memoryASet(ds, bx + 13455, 0x00);
  ax = 0xb800;
  es = ax;
  if (bx < 0x000c)
    goto loc_1a9cf;
  si = bx;
  cl = 0x03;
  si <<= cl;
  si += memoryAGet16(ds, 0x3413);
  si &= 0x0018;
  si += 0x3330;
  cx = 0x0202;
  sub_19fcd();
  return;
loc_1a9cf:
  si = memoryAGet16(ds, 0x3411);
  if (bl & 0x01)
    goto loc_1a9dc;
  si ^= 0x000c;
loc_1a9dc:
  if (memoryAGet(ds, bx + 13335) == 0x01)
    goto loc_1a9e6;
  si += 0x0018;
loc_1a9e6:
  si += 0x3300;
  cx = 0x0601;
  sub_19fcd();
}
void sub_1a9f1()
{
  if (memoryAGet(ds, bx + 13455) != 0x00)
    return;
  bx <<= 1;
  si = 0x3404;
  di = memoryAGet16(ds, bx + 13503);
  ax = 0xb800;
  es = ax;
  cx = 0x0601;
  if (bx < 0x0018)
    goto loc_1aa11;
  cx = 0x0202;
loc_1aa11:
  sub_19fcd();
}
void sub_1aa15()
{
  ah = 0;
  interrupt(0x1a);
  ax = dx;
  ax -= memoryAGet16(ds, 0x350f);
  if (ax < 0x0008)
    return;
  memoryASet16(ds, 0x350d, memoryAGet16(ds, 0x350d) + 1);
  bx = memoryAGet16(ds, 0x350d);
  if (bx < 0x0028)
    goto loc_1aa3b;
  bx = 0;
  memoryASet16(ds, 0x350d, bx);
  memoryASet16(ds, 0x350f, dx);
loc_1aa3b:
  di = bx;
  di <<= 1;
  if (memoryAGet(ds, 0x057b) > 0x07)
    goto loc_1aa59;
  ax = memoryAGet16(ds, 0x0579);
  cl = 0x02;
  ax >>= cl;
  ax++;
  flags.carry = ax < di;
  ax -= di;
  if (!flags.carry)
    goto loc_1aa54;
  ax = ~ax;
loc_1aa54:
  if (ax < 0x0004)
    return;
loc_1aa59:
  di += 0x00a0;
  al = memoryAGet(ds, bx + 9814);
  al += 0x08;
  memoryASet(ds, bx + 9814, al);
  ax &= 0x0018;
  ax += 0x2020;
  si = ax;
  ax = 0xb800;
  es = ax;
  cx = 0x0401;
  sub_19fcd();
}
void sub_1aa80()
{
  ah = 0;
  interrupt(0x1a);
  ax = dx;
  ax -= memoryAGet16(ds, 0x35da);
  if (ax >= 0x0006)
    goto loc_1aa90;
  return;
loc_1aa90:
  memoryASet16(ds, 0x35da, dx);
  memoryASet16(ds, 0x35d8, memoryAGet16(ds, 0x35d8) + 0x0002);
  bx = memoryAGet16(ds, 0x35d8);
  bx &= 0x0006;
  si = memoryAGet16(ds, bx + 13776);
  di = 0x15c9;
  ax = 0xb800;
  es = ax;
  cx = 0x0a02;
  sub_19fcd();
  ax = 0x00e4;
  dl = 0x8a;
  si = 0x0010;
  bx = memoryAGet16(ds, 0x0579);
  dh = memoryAGet(ds, 0x057b);
  di = 0x0018;
  cx = 0x0e0a;
  sub_1a059();
  if (!flags.carry)
    return;
  memoryASet(ds, 0x0554, 0x01);
}
void sub_1aae0()
{
  if (memoryAGet16(ds, 0x0006) != 0x0007)
    goto loc_1aaea;
  goto loc_1ab03;
  //   gap of 1 bytes
loc_1aaea:
  memoryASet16(ds, 0x0414, memoryAGet16(ds, 0x0414) + 1);
  memoryASet(ds, 0x0418, 0x01);
  dx = 0xaaaa;
  sub_1acc6();
  ax = 0;
  memoryASet(ds, 0x369f, 0x00);
  sub_1acdc();
loc_1ab03:
  ah = 0;
  interrupt(0x1a);
  if (memoryAGet16(ds, 0x0006) != 0x0007)
    goto loc_1ab1f;
  dx -= memoryAGet16(ds, 0x0412);
  ax = 0x2a30;
  flags.carry = ax < dx;
  ax -= dx;
  if (!flags.carry)
    goto loc_1ab1b;
  ax = 0;
loc_1ab1b:
  ax >>= 1;
  goto loc_1ab3e;
loc_1ab1f:
  dx -= memoryAGet16(ds, 0x0410);
  ax = 0x0546;
  if (memoryAGet16(ds, 0x0006) != 0x0006)
    goto loc_1ab2f;
  ax <<= 1;
loc_1ab2f:
  flags.carry = ax < dx;
  ax -= dx;
  if (!flags.carry)
    goto loc_1ab35;
  ax = 0;
loc_1ab35:
  if (memoryAGet16(ds, 0x0006) == 0x0006)
    goto loc_1ab3e;
  ax <<= 1;
loc_1ab3e:
  memoryASet16(ds, 0x3697, ax);
  sub_1ad24();
  bx = memoryAGet16(ds, 0x0006);
  bl <<= 1;
  si = memoryAGet16(ds, bx + 14028);
  di = 0x368d;
  sub_1994e();
  if (memoryAGet16(ds, 0x0006) != 0x0007)
    goto loc_1ab9e;
  bx = memoryAGet16(ds, 0x0008);
  bl <<= 1;
  ax = bx;
  cx = memoryAGet16(ds, bx + 14044);
  if (memoryAGet16(ds, 0x2e8d) >= 0x0008)
    goto loc_1ab73;
  cx <<= 1;
  ax += 0x0010;
loc_1ab73:
  memoryASet16(ds, 0x370c, ax);
loc_1ab76:
  si = 0x368d;
  di = 0x1f82;
  push(cx);
  sub_1994e();
  cx = pop();
  if (--cx)
    goto loc_1ab76;
  sub_1ac2a();
  memoryASet(ds, 0x369e, 0x38);
  memoryASet(ds, 0x3699, 0x01);
  memoryASet16(ds, 0x3722, 0x0044);
  sub_1ac6a();
  sub_1ac9c();
  goto loc_1abd7;
loc_1ab9e:
  si = 0x368d;
  di = 0x1f82;
  sub_1994e();
  memoryASet(ds, 0x3699, 0x02);
  memoryASet16(ds, 0x3722, 0x001e);
  dx = 0xffff;
  sub_1acc6();
  ax = 0x0a8c;
  ax -= memoryAGet16(ds, 0x3697);
  cl = 0x04;
  ax >>= cl;
  al &= 0xf0;
  memoryASet(ds, 0x369e, al);
  ah = 0x28;
  mul(ah);
  memoryASet(ds, 0x369f, 0x01);
  sub_1acdc();
  sub_1ac6a();
loc_1abd7:
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x3695, dx);
loc_1abdf:
  if (memoryAGet16(ds, 0x0006) != 0x0007)
    goto loc_1abeb;
  sub_1cd93();
  goto loc_1abee;
loc_1abeb:
  sub_1ca65();
loc_1abee:
  sub_1ac4c();
  dx -= memoryAGet16(ds, 0x3695);
  if (dx < memoryAGet16(ds, 0x3722))
    goto loc_1abdf;
  bx = 0;
  ah = 0x0b;
  interrupt(0x10);
  if (memoryAGet16(ds, 0x0006) == 0x0007)
    goto loc_1ac0c;
  sub_1cd51();
  return;
loc_1ac0c:
  ax = 0xb800;
  es = ax;
  si = 0x000e;
  di = 0x08e4;
  cx = 0x0804;
  sub_19fcd();
  si = 0x004e;
  di = 0x0c94;
  cx = 0x0814;
  sub_19fcd();
}
void sub_1ac2a()
{
  push(ds);
  es = pop();
  ax = 0xb800;
  ds = ax;
  cx = 0x0804;
  di = 0x000e;
  si = 0x08e4;
  sub_19ffa();
  cx = 0x0814;
  di = 0x004e;
  si = 0x0c94;
  sub_19ffa();
  push(es);
  ds = pop();
}
void sub_1ac4c()
{
  ah = 0;
  interrupt(0x1a);
  push(dx);
loc_1ac51:
  sub_18608();
  if (flags.zero)
    goto loc_1ac51;
  dx = pop();
  push(dx);
  bx = 0;
  if (dx & 0x0004)
    goto loc_1ac64;
  bl = memoryAGet(ds, 0x3699);
loc_1ac64:
  ah = 0x0b;
  interrupt(0x10);
  dx = pop();
}
void sub_1ac6a()
{
  ah = 0x02;
  dh = memoryAGet(ds, 0x369e);
  cl = 0x03;
  dh >>= cl;
  dl = 0x12;
  bh = 0;
  interrupt(0x10);
  memoryASet16(ds, 0x36a0, 0x0003);
loc_1ac80:
  bx = memoryAGet16(ds, 0x36a0);
  al = memoryAGet(ds, bx + 13965);
  al += 0x30;
  ah = 0x0e;
  bl = 0x03;
  interrupt(0x10);
  memoryASet16(ds, 0x36a0, memoryAGet16(ds, 0x36a0) + 1);
  if (memoryAGet16(ds, 0x36a0) < 0x0007)
    goto loc_1ac80;
}
void sub_1ac9c()
{
  ah = 0x02;
  dl = 0x0a;
  dh = dl;
  bx = 0;
  interrupt(0x10);
  bx = memoryAGet16(ds, 0x370c);
  ax = memoryAGet16(ds, bx + 14060);
  memoryASet16(ds, 0x3720, ax);
  bx = 0;
loc_1acb3:
  ah = 0x0e;
  al = memoryAGet(ds, bx + 14094);
  push(bx);
  bl = 0x03;
  interrupt(0x10);
  bx = pop();
  bx++;
  if (bx < 0x0014)
    goto loc_1acb3;
}
void sub_1acc6()
{
  flags.direction = false;
  ax = 0x1010;
  es = ax;
  di = 0x000e;
  si = 0x35e0;
  cx = 0x001e;
loc_1acd5:
  lodsw<MemAuto, DirAuto>();
  ax &= dx;
  stosw<MemAuto, DirAuto>();
  if (--cx)
    goto loc_1acd5;
}
void sub_1acdc()
{
  memoryASet16(ds, 0x369a, ax);
  ax = 0xb800;
  es = ax;
  sub_1ca59();
  ax = 0x1b80;
loc_1acea:
  bx = 0x361c;
  memoryASet16(ds, 0x369c, ax);
  sub_19d54();
  if (memoryAGet(ds, 0x369f) == 0x00)
    goto loc_1ad12;
  sub_1ca99();
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x3695, dx);
loc_1ad05:
  ah = 0;
  interrupt(0x1a);
  dx -= memoryAGet16(ds, 0x3695);
  if (dx < 0x0002)
    goto loc_1ad05;
loc_1ad12:
  ax = memoryAGet16(ds, 0x369c);
  flags.carry = ax < 0x0280;
  ax -= 0x0280;
  if (flags.carry)
    goto loc_1ad20;
  if (ax >= memoryAGet16(ds, 0x369a))
    goto loc_1acea;
loc_1ad20:
  sub_1cd51();
}
void sub_1ad24()
{
  memoryASet16(ds, 0x368b, ax);
  ax = 0;
  memoryASet16(ds, 0x368d, ax);
  memoryASet16(ds, 0x368f, ax);
  memoryASet16(ds, 0x3691, ax);
  memoryASet16(ds, 0x3693, ax);
  bx = 0x3684;
  dx = 0x1000;
loc_1ad3b:
  if (!(memoryAGet16(ds, 0x368b) & dx))
    goto loc_1ad49;
  si = bx;
  di = 0x368d;
  sub_1994e();
loc_1ad49:
  bx -= 0x0007;
  flags.carry = dx & 1;
  dx >>= 1;
  if (!flags.carry)
    goto loc_1ad3b;
}
void sub_1ad60()
{
  memoryASet(ds, 0x37af, 0x03);
  ax = 0x0001;
  memoryASet16(ds, 0x37b0, ax);
  memoryASet16(ds, 0x37b2, ax);
  memoryASet16(ds, 0x37b4, ax);
}
void sub_1ad72()
{
  ah = 0;
  interrupt(0x1a);
  if (dx != memoryAGet16(ds, 0x37b8))
    goto loc_1ad7d;
  return;
loc_1ad7d:
  memoryASet16(ds, 0x37b8, dx);
  memoryASet16(ds, 0x37b6, 0x0004);
loc_1ad87:
  bx = memoryAGet16(ds, 0x37b6);
  if (memoryAGet16(ds, bx + 14256) == 0x0000)
    goto loc_1adcb;
  ax = memoryAGet16(ds, bx + 14243);
  dl = 0x18;
  si = 0x0010;
  bx = memoryAGet16(ds, 0x0579);
  dh = memoryAGet(ds, 0x057b);
  di = 0x0018;
  cx = 0x0e10;
  sub_1a059();
  if (!flags.carry)
    goto loc_1adcb;
  ax = 0x0c00;
  bx = 0x08fd;
  sub_1cb6b();
  sub_18413();
  sub_1b068();
  bx = memoryAGet16(ds, 0x37b6);
  sub_1add3();
  sub_18354();
  sub_1b044();
  return;
loc_1adcb:
  flags.carry = memoryAGet16(ds, 0x37b6) < 0x0002;
  memoryASet16(ds, 0x37b6, memoryAGet16(ds, 0x37b6) - 0x0002);
  if (!flags.carry)
    goto loc_1ad87;
}
void sub_1add3()
{
  memoryASet16(ds, bx + 14256, 0x0000);
  push(ds);
  es = pop();
  flags.direction = false;
  ax = 0xaaaa;
  di = 0x000e;
  si = di;
  cx = 0x0020;
  rep_stosw<MemAuto, DirAuto>();
  di = memoryAGet16(ds, bx + 14249);
  ax = 0xb800;
  es = ax;
  cx = 0x1002;
  sub_19fcd();
  memoryASet(ds, 0x37af, memoryAGet(ds, 0x37af) - 1);
  if (memoryAGet(ds, 0x37af) != 0)
    return;
  if (memoryAGet(ds, 0x0552) != 0x00)
    return;
  memoryASet(ds, 0x0553, 0x01);
}
void sub_1ae0b()
{
  ax = 0xb800;
  es = ax;
  memoryASet16(ds, 0x37a0, 0x066a);
  cx = 0x0010;
loc_1ae19:
  ax = 0;
  bx = ax;
loc_1ae1d:
  memoryASet(ds, 0x37a2, al);
  ah = 0;
  ax += 0x3730;
  si = ax;
  di = memoryAGet16(ds, 0x37a0);
  di += bx;
  push(cx);
  cx = 0x0801;
  push(bx);
  sub_19fcd();
  bx = pop();
  cx = pop();
  bx += 0x0002;
  if (bx < 0x001e)
    goto loc_1ae4e;
  if (bx != 0x001e)
    goto loc_1ae45;
  al = 0x20;
  goto loc_1ae1d;
loc_1ae45:
  memoryASet16(ds, 0x37a0, memoryAGet16(ds, 0x37a0) + 0x0140);
  if (--cx)
    goto loc_1ae19;
  return;
loc_1ae4e:
  if (memoryAGet(ds, 0x37a2) == 0x50)
    goto loc_1ae66;
  if (cl & 0x01)
    goto loc_1ae66;
  sub_1a02d();
  if (dl < 0x40)
    goto loc_1ae66;
  al = 0x10;
  goto loc_1ae1d;
loc_1ae66:
  sub_1a02d();
  al = dl;
  al -= bl;
  al &= 0x30;
  al += 0x30;
  goto loc_1ae1d;
}
void sub_1ae73()
{
  ax = memoryAGet16(ds, 0x0579);
  ax &= 0xfffc;
  if (ax < 0x00a4)
    goto loc_1aeaf;
  if (ax > 0x0118)
    goto loc_1aeaf;
  dl = memoryAGet(ds, 0x057b);
  dl -= 0x02;
  dl &= 0xf8;
  if (!(dl & 0x08))
    goto loc_1aeaf;
  if (dl < 0x28)
    goto loc_1aeaf;
  if (dl > 0xa0)
    goto loc_1aeaf;
  memoryASet16(ds, 0x0579, ax);
  dl += 0x02;
  memoryASet(ds, 0x057b, dl);
  dl += 0x32;
  memoryASet(ds, 0x057c, dl);
  flags.carry = true;
  return;
loc_1aeaf:
  flags.carry = false;
}
void sub_1aec0()
{
  memoryASet(ds, 0x3966, 0x08);
  memoryASet(ds, 0x396a, 0x01);
  memoryASet(ds, 0x3967, 0x00);
  memoryASet(ds, 0x396d, 0x02);
  memoryASet16(ds, 0x3964, 0x0118);
  memoryASet16(ds, 0x396b, 0x0000);
}
void sub_1aee1()
{
  ah = 0;
  interrupt(0x1a);
  ax = dx;
  ax -= memoryAGet16(ds, 0x39c8);
  if (ax >= 0x0002)
    goto loc_1aef1;
loc_1aef0:
  return;
loc_1aef1:
  memoryASet16(ds, 0x39c8, dx);
  sub_1b082();
  if (flags.carry)
    goto loc_1aef0;
  sub_1b09e();
  if (!flags.carry)
    goto loc_1af02;
  goto loc_1afc0;
loc_1af02:
  bx = memoryAGet16(ds, 0x0008);
  bl <<= 1;
  ax = memoryAGet16(ds, bx + 14796);
  memoryASet16(ds, 0x39c6, ax);
  ax = memoryAGet16(ds, 0x3964);
  memoryASet16(ds, 0x39c3, ax);
  dl = memoryAGet(ds, 0x3966);
  memoryASet(ds, 0x39c5, dl);
  if (dl != 0x08)
    goto loc_1af55;
  ax &= 0xfff8;
  dx = memoryAGet16(ds, 0x0579);
  dx &= 0xfff8;
  if (ax != dx)
    goto loc_1af3d;
  memoryASet(ds, 0x3967, 0x01);
  memoryASet(ds, 0x396e, 0x01);
  goto loc_1af55;
loc_1af3d:
  ax = memoryAGet16(ds, 0x3964);
  if (stop(/*1*/))
    goto loc_1af4c;
  flags.carry = ax < memoryAGet16(ds, 0x39c6);
  ax -= memoryAGet16(ds, 0x39c6);
  if (!flags.carry)
    goto loc_1af50;
  ax = 0;
  goto loc_1af50;
loc_1af4c:
  ax += memoryAGet16(ds, 0x39c6);
loc_1af50:
  memoryASet16(ds, 0x3964, ax);
  goto loc_1afa9;
loc_1af55:
  al = memoryAGet(ds, 0x3966);
  memoryASet(ds, 0x396e, memoryAGet(ds, 0x396e) + 1);
  dl = memoryAGet(ds, 0x396e);
  dl >>= 1;
  dl >>= 1;
  dl &= 0x03;
  dl += 0x02;
  if (memoryAGet(ds, 0x3967) == 0x01)
    goto loc_1af82;
  flags.carry = al < dl;
  al -= dl;
  if (flags.carry)
    goto loc_1af79;
  if (al >= 0x09)
    goto loc_1afa6;
loc_1af79:
  al = 0x08;
  memoryASet(ds, 0x3967, 0x00);
  goto loc_1afa6;
loc_1af82:
  al += dl;
  if (al > memoryAGet(ds, 0x057b))
    goto loc_1afa1;
  bx = memoryAGet16(ds, 0x3964);
  flags.carry = bx < memoryAGet16(ds, 0x0579);
  bx -= memoryAGet16(ds, 0x0579);
  if (!flags.carry)
    goto loc_1af96;
  bx = ~bx;
loc_1af96:
  if (bx > 0x0030)
    goto loc_1afa1;
  if (al < 0xa0)
    goto loc_1afa6;
  al = 0x9f;
loc_1afa1:
  memoryASet(ds, 0x3967, 0xff);
loc_1afa6:
  memoryASet(ds, 0x3966, al);
loc_1afa9:
  sub_1b082();
  if (!flags.carry)
    goto loc_1afbb;
  ax = memoryAGet16(ds, 0x39c3);
  memoryASet16(ds, 0x3964, ax);
  al = memoryAGet(ds, 0x39c5);
  memoryASet(ds, 0x3966, al);
  return;
loc_1afbb:
  sub_1b09e();
  if (!flags.carry)
    goto loc_1b01e;
loc_1afc0:
  if (memoryAGet(ds, 0x0553) == 0x00)
    goto loc_1afc8;
  return;
loc_1afc8:
  cx = memoryAGet16(ds, 0x0579);
  flags.carry = cx < 0x000c;
  cx -= 0x000c;
  if (!flags.carry)
    goto loc_1afd3;
  cx = 0;
loc_1afd3:
  if (cx < 0x010f)
    goto loc_1afdc;
  cx = 0x010e;
loc_1afdc:
  dl = memoryAGet(ds, 0x057b);
  flags.carry = dl < 0x04;
  dl -= 0x04;
  if (!flags.carry)
    goto loc_1afe7;
  dl = 0;
loc_1afe7:
  sub_19ee0();
  di = ax;
  ax = 0xb800;
  es = ax;
  si = 0x37c0;
  bp = 0x000e;
  cx = 0x1506;
  sub_19efc();
  sub_1c924();
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x39c8, dx);
loc_1b008:
  sub_1c934();
  ah = 0;
  interrupt(0x1a);
  dx -= memoryAGet16(ds, 0x39c8);
  if (dx < 0x0009)
    goto loc_1b008;
  memoryASet(ds, 0x0552, 0x01);
  return;
loc_1b01e:
  cx = memoryAGet16(ds, 0x3964);
  dl = memoryAGet(ds, 0x3966);
  sub_19ee0();
  memoryASet16(ds, 0x39ca, ax);
  sub_1b068();
  memoryASet(ds, 0x396d, memoryAGet(ds, 0x396d) - 1);
  if (memoryAGet(ds, 0x396d) != 0)
    goto loc_1b040;
  memoryASet(ds, 0x396d, 0x02);
  memoryASet16(ds, 0x396b, memoryAGet16(ds, 0x396b) ^ 0x0054);
loc_1b040:
  sub_1b044();
}
void sub_1b044()
{
  ax = 0xb800;
  es = ax;
  di = memoryAGet16(ds, 0x39ca);
  memoryASet16(ds, 0x3968, di);
  bp = 0x396f;
  memoryASet(ds, 0x396a, 0x00);
  si = memoryAGet16(ds, 0x396b);
  si += 0x38bc;
  cx = 0x0e03;
  sub_19efc();
}
void sub_1b068()
{
  ax = 0xb800;
  es = ax;
  if (memoryAGet(ds, 0x396a) != 0x00)
    return;
  di = memoryAGet16(ds, 0x3968);
  si = 0x396f;
  cx = 0x0e03;
  sub_19fcd();
}
// INJECT: Error: cannot inject carry flag in sub_1b082()!
void sub_1b082()
{
  ax = memoryAGet16(ds, 0x3964);
  dl = memoryAGet(ds, 0x3966);
  si = 0x0018;
  bx = memoryAGet16(ds, 0x327d);
  dh = memoryAGet(ds, 0x327f);
  di = 0x0010;
  cx = 0x1e0e;
  sub_1a059();
  stop(/*inject ret*/);
}
// INJECT: Error: cannot inject carry flag in sub_1b09e()!
void sub_1b09e()
{
  ax = memoryAGet16(ds, 0x3964);
  dl = memoryAGet(ds, 0x3966);
  si = 0x0018;
  di = si;
  bx = memoryAGet16(ds, 0x0579);
  dh = memoryAGet(ds, 0x057b);
  cx = 0x0e0e;
  sub_1a059();
  stop(/*inject ret*/);
}
void sub_1b0c0()
{
  if (memoryAGet(ds, 0x39e1) == 0x00)
    goto loc_1b0d4;
  ah = 0;
  interrupt(0x1a);
  if (dx == memoryAGet16(ds, 0x3d16))
    goto loc_1b0e9;
  goto loc_1b165;
loc_1b0d4:
  if (memoryAGet(ds, 0x0584) != 0x00)
    goto loc_1b0e9;
  if (memoryAGet(ds, 0x069a) != 0x00)
    goto loc_1b0e9;
  if (memoryAGet(ds, 0x39e0) != 0x00)
    goto loc_1b0ea;
loc_1b0e9:
  return;
loc_1b0ea:
  sub_1b295();
  if (flags.carry)
    goto loc_1b0e9;
  ah = 0;
  interrupt(0x1a);
  ax = dx;
  ax -= memoryAGet16(ds, 0x3d18);
  if (ax < 0x000c)
    goto loc_1b0e9;
  memoryASet16(ds, 0x3d18, dx);
  memoryASet(ds, 0x055c, 0x00);
  bl = memoryAGet(ds, 0x39e0);
  bl--;
  bh = 0;
  si = bx;
  cl = 0x02;
  si <<= cl;
  ax = memoryAGet16(ds, si + 15450);
  memoryASet16(ds, 0x39e2, ax);
  ax = 0;
  if (bl >= 0x03)
    goto loc_1b125;
  al = 0x80;
loc_1b125:
  memoryASet16(ds, 0x39e4, ax);
  bl = memoryAGet(ds, bx + 15587);
  si = bx;
  cl = 0x02;
  si <<= cl;
  ax = memoryAGet16(ds, si + 15450);
  memoryASet16(ds, 0x39e6, ax);
  ax = 0;
  if (bl >= 0x03)
    goto loc_1b142;
  al = 0x80;
loc_1b142:
  memoryASet16(ds, 0x39e8, ax);
  al = memoryAGet(ds, bx + 4176);
  memoryASet(ds, 0x3d05, al);
  bl <<= 1;
  ax = memoryAGet16(ds, bx + 4407);
  ax += 0x0008;
  memoryASet16(ds, 0x3d03, ax);
  sub_18413();
  memoryASet(ds, 0x39e1, 0x0e);
  memoryASet(ds, 0x069a, 0x10);
loc_1b165:
  if (memoryAGet(ds, 0x1cbf) != 0x00)
    goto loc_1b16f;
  sub_1a5d0();
loc_1b16f:
  memoryASet(ds, 0x39e1, memoryAGet(ds, 0x39e1) - 0x02);
  bh = 0;
  bl = memoryAGet(ds, 0x39e1);
  if (bl < 0x08)
    goto loc_1b188;
  di = memoryAGet16(ds, 0x39e2);
  ax = memoryAGet16(ds, 0x39e4);
  goto loc_1b1a0;
loc_1b188:
  di = memoryAGet16(ds, 0x39e6);
  al = memoryAGet(ds, 0x3d05);
  memoryASet(ds, 0x057b, al);
  al += 0x32;
  memoryASet(ds, 0x057c, al);
  ax = memoryAGet16(ds, 0x3d03);
  memoryASet16(ds, 0x0579, ax);
  ax = memoryAGet16(ds, 0x39e8);
loc_1b1a0:
  ax += memoryAGet16(ds, bx + 15622);
  si = ax;
  ax = 0xb800;
  es = ax;
  cx = 0x1002;
  sub_19fcd();
  if (memoryAGet(ds, 0x1cbf) != 0x00)
    goto loc_1b1bb;
  sub_1a569();
loc_1b1bb:
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x3d16, dx);
  if (memoryAGet(ds, 0x39e1) != 0x00)
    return;
  sub_18342();
}
void sub_1b1ce()
{
  ax = 0xb800;
  es = ax;
  memoryASet(ds, 0x39e0, 0x00);
  memoryASet(ds, 0x39e1, 0x00);
  memoryASet16(ds, 0x3cbf, 0x0506);
  memoryASet16(ds, 0x3cc1, 0x0000);
loc_1b1e9:
  bx = memoryAGet16(ds, 0x3cc1);
  cl = memoryAGet(ds, bx + 15534);
  bx = 0;
  ch = bl;
loc_1b1f5:
  si = 0x3aea;
  sub_1a02d();
  if (dl > 0x30)
    goto loc_1b20b;
  si = 0x3af8;
  if (dl & 0x04)
    goto loc_1b20b;
  si = 0x3b02;
loc_1b20b:
  di = memoryAGet16(ds, 0x3cbf);
  di += bx;
  push(cx);
  push(bx);
  cx = 0x0801;
  sub_19fcd();
  bx = pop();
  cx = pop();
  bx += 0x0002;
  if (--cx)
    goto loc_1b1f5;
  memoryASet16(ds, 0x3cbf, memoryAGet16(ds, 0x3cbf) + 0x0140);
  memoryASet16(ds, 0x3cc1, memoryAGet16(ds, 0x3cc1) + 1);
  if (memoryAGet16(ds, 0x3cc1) < 0x0011)
    goto loc_1b1e9;
  bx = 0x3c22;
  ax = 0;
  sub_19d54();
  bx = 0x3c3e;
  ax = 0;
  sub_19d54();
  bx = 0x3c9a;
  ax = 0;
  sub_19d54();
  bx = 0x3c56;
  ax = 0;
  sub_19d54();
  si = 0x3caa;
  di = 0x08ec;
  cx = 0x0102;
  bp = 0x000e;
  sub_19f65();
  si = 0;
  bx = memoryAGet16(ds, 0x0008);
  cl = 0x03;
  bl &= cl;
  bl <<= cl;
loc_1b26c:
  al = memoryAGet(ds, bx + 15555);
  ah = al;
  cl = 0x04;
  al >>= cl;
  memoryASet(ds, si + 15587, al);
  memoryASet(ds, si + 15603, 0x00);
  ah &= 0x0f;
  memoryASet(ds, si + 15588, ah);
  memoryASet(ds, si + 15604, 0x00);
  si += 0x0002;
  bx++;
  if (si < 0x0010)
    goto loc_1b26c;
}
// INJECT: Error: cannot inject carry flag in sub_1b295()!
void sub_1b295()
{
  ax = memoryAGet16(ds, 0x327d);
  dl = memoryAGet(ds, 0x327f);
  si = 0x0010;
  bx = memoryAGet16(ds, 0x0579);
  dh = memoryAGet(ds, 0x057b);
  di = 0x0018;
  cx = 0x0e1e;
  sub_1a059();
  stop(/*inject ret*/);
}
void sub_1b2c0()
{
  cx = 0x0004;
loc_1b2c3:
  bx = cx;
  bx--;
  si = bx;
  si <<= 1;
  memoryASet(ds, bx + 16046, 0x01);
  memoryASet(ds, bx + 16050, 0x00);
  sub_1b4a7();
  sub_1a02d();
  dl &= 0x0f;
  dl += 0x14;
  memoryASet(ds, bx + 16054, dl);
  if (--cx)
    goto loc_1b2c3;
  memoryASet16(ds, 0x3eda, 0x0000);
  memoryASet(ds, 0x3ed8, 0x04);
}
void sub_1b2f2()
{
  ah = 0;
  interrupt(0x1a);
  if (dx != memoryAGet16(ds, 0x3edc))
    goto loc_1b2fd;
loc_1b2fc:
  return;
loc_1b2fd:
  memoryASet16(ds, 0x3eda, memoryAGet16(ds, 0x3eda) + 1);
  bx = memoryAGet16(ds, 0x3eda);
  if (bx <= 0x0002)
    goto loc_1b315;
  if (bx < 0x0004)
    goto loc_1b319;
  bx = 0;
  memoryASet16(ds, 0x3eda, bx);
loc_1b315:
  memoryASet16(ds, 0x3edc, dx);
loc_1b319:
  si = bx;
  si <<= 1;
  if (memoryAGet(ds, bx + 16050) != 0x00)
    goto loc_1b2fc;
  sub_1b50b();
  if (!flags.carry)
    goto loc_1b32c;
  goto loc_1b354;
  //   gap of 1 bytes
loc_1b32c:
  sub_1b52c();
  if (flags.carry)
    goto loc_1b2fc;
  if (memoryAGet(ds, bx + 16054) != 0x00)
    goto loc_1b348;
  sub_1b4a7();
  sub_1a02d();
  dl &= 0x07;
  dl += 0x14;
  memoryASet(ds, bx + 16054, dl);
loc_1b348:
  memoryASet(ds, bx + 16054, memoryAGet(ds, bx + 16054) - 1);
  sub_1b50b();
  if (flags.carry)
    goto loc_1b354;
  goto loc_1b3b1;
  //   gap of 1 bytes
loc_1b354:
  if (memoryAGet(ds, bx + 16046) != 0x00)
    goto loc_1b362;
  if (memoryAGet(ds, bx + 16054) < 0x14)
    goto loc_1b363;
loc_1b362:
  return;
loc_1b363:
  sub_18413();
  sub_1b484();
  bx = memoryAGet16(ds, 0x3eda);
  memoryASet(ds, bx + 16050, 0x01);
  sub_18354();
  memoryASet(ds, 0x055c, 0x00);
  memoryASet(ds, 0x3ed8, memoryAGet(ds, 0x3ed8) - 1);
  if (memoryAGet(ds, 0x3ed8) != 0)
    goto loc_1b385;
  memoryASet(ds, 0x0553, 0x01);
loc_1b385:
  al = 0x04;
  al -= memoryAGet(ds, 0x3ed8);
  cl = 0x02;
  al <<= cl;
  ah = 0;
  ax += 0x0051;
  di = ax;
  bp = 0x000e;
  si = 0x3d20;
  ax = 0xb800;
  es = ax;
  cx = 0x0c02;
  sub_19f65();
  ax = 0x03e8;
  bx = 0x02ee;
  sub_1cb6b();
  return;
loc_1b3b1:
  sub_1b4e4();
  di = memoryAGet16(ds, 0x0008);
  di <<= 1;
  bp = memoryAGet16(ds, di + 16094);
  sub_1b54c();
  if (!flags.carry)
    goto loc_1b3e0;
  if (memoryAGet(ds, bx + 16054) < 0x02)
    goto loc_1b3e0;
  al = 0x01;
  if (memoryAGet(ds, bx + 16054) <= 0x11)
    goto loc_1b3dc;
  if (memoryAGet(ds, bx + 16054) >= 0x14)
    goto loc_1b3e0;
  al--;
loc_1b3dc:
  memoryASet(ds, bx + 16054, al);
loc_1b3e0:
  al = memoryAGet(ds, bx + 16054);
  if (al <= 0x01)
    goto loc_1b408;
  if (al < 0x12)
    goto loc_1b428;
  al = 0x01;
  if (memoryAGet16(ds, si + 16058) >= 0x0003)
    goto loc_1b3f7;
  al = 0x03;
loc_1b3f7:
  memoryASet(ds, bx + 16084, memoryAGet(ds, bx + 16084) + al);
  if (memoryAGet(ds, bx + 16054) < 0x13)
    goto loc_1b423;
  if (memoryAGet(ds, bx + 16054) == 0x13)
    goto loc_1b41e;
  ax = 0;
  goto loc_1b434;
loc_1b408:
  al = 0x01;
  if (memoryAGet16(ds, si + 16058) >= 0x0003)
    goto loc_1b413;
  al = 0x03;
loc_1b413:
  memoryASet(ds, bx + 16084, memoryAGet(ds, bx + 16084) + al);
  if (memoryAGet(ds, bx + 16054) >= 0x01)
    goto loc_1b423;
loc_1b41e:
  ax = 0x3db0;
  goto loc_1b434;
loc_1b423:
  ax = 0x3d80;
  goto loc_1b434;
loc_1b428:
  al <<= 1;
  di = ax;
  di &= 0x0002;
  ax = memoryAGet16(ds, di + 15840);
loc_1b434:
  memoryASet16(ds, 0x3eca, ax);
  dl = memoryAGet(ds, bx + 16084);
  cx = memoryAGet16(ds, si + 16076);
  sub_19ee0();
  memoryASet16(ds, 0x3de4, ax);
  sub_1b484();
  bx = memoryAGet16(ds, 0x3eda);
  si = bx;
  si <<= 1;
  sub_1b52c();
  if (!flags.carry)
    goto loc_1b456;
  return;
loc_1b456:
  if (memoryAGet16(ds, 0x3eca) != 0x0000)
    goto loc_1b463;
  memoryASet(ds, bx + 16046, 0x01);
  return;
loc_1b463:
  memoryASet(ds, bx + 16046, 0x00);
  di = memoryAGet16(ds, 0x3de4);
  memoryASet16(ds, si + 16038, di);
  ax = 0xb800;
  es = ax;
  bp = memoryAGet16(ds, si + 16066);
  cx = 0x0c02;
  si = memoryAGet16(ds, 0x3eca);
  sub_19f65();
}
void sub_1b484()
{
  bx = memoryAGet16(ds, 0x3eda);
  si = bx;
  si <<= 1;
  if (memoryAGet(ds, bx + 16046) != 0x00)
    return;
  di = memoryAGet16(ds, si + 16038);
  cx = 0x0c02;
  si = memoryAGet16(ds, si + 16066);
  ax = 0xb800;
  es = ax;
  sub_19fcd();
}
void sub_1b4a7()
{
  memoryASet(ds, 0x3ed9, 0x20);
loc_1b4ac:
  sub_1a02d();
  dx &= 0x000f;
  di = 0;
loc_1b4b5:
  if (di == si)
    goto loc_1b4bf;
  if (dx == memoryAGet16(ds, di + 16058))
    goto loc_1b4ac;
loc_1b4bf:
  di += 0x0002;
  if (di < 0x0008)
    goto loc_1b4b5;
  memoryASet16(ds, si + 16058, dx);
  sub_1b4e4();
  if (memoryAGet(ds, 0x3ed9) == 0x00)
    return;
  bp = 0x0032;
  sub_1b54c();
  if (!flags.carry)
    return;
  memoryASet(ds, 0x3ed9, memoryAGet(ds, 0x3ed9) - 1);
  goto loc_1b4ac;
}
void sub_1b4e4()
{
  di = memoryAGet16(ds, si + 16058);
  al = memoryAGet(ds, di + 4176);
  dl = 0x0a;
  if (di >= 0x0003)
    goto loc_1b4f5;
  dl = 0;
loc_1b4f5:
  al -= dl;
  al += 0x03;
  memoryASet(ds, bx + 16084, al);
  di <<= 1;
  ax = memoryAGet16(ds, di + 4407);
  ax += 0x0008;
  memoryASet16(ds, si + 16076, ax);
}
// INJECT: Error: cannot inject carry flag in sub_1b50b()!
void sub_1b50b()
{
  push(si);
  push(bx);
  ax = memoryAGet16(ds, si + 16076);
  dl = memoryAGet(ds, bx + 16084);
  si = 0x0010;
  bx = memoryAGet16(ds, 0x0579);
  dh = memoryAGet(ds, 0x057b);
  di = 0x0018;
  cx = 0x0e0c;
  sub_1a059();
  bx = pop();
  si = pop();
}
// INJECT: Error: cannot inject carry flag in sub_1b52c()!
void sub_1b52c()
{
  push(si);
  push(bx);
  ax = memoryAGet16(ds, si + 16076);
  dl = memoryAGet(ds, bx + 16084);
  si = 0x0010;
  bx = memoryAGet16(ds, 0x327d);
  dh = memoryAGet(ds, 0x327f);
  di = si;
  cx = 0x1e0c;
  sub_1a059();
  bx = pop();
  si = pop();
  stop(/*inject ret*/);
}
void sub_1b54c()
{
  ax = memoryAGet16(ds, si + 16076);
  flags.carry = ax < memoryAGet16(ds, 0x0579);
  ax -= memoryAGet16(ds, 0x0579);
  if (!flags.carry)
    goto loc_1b558;
  ax = ~ax;
loc_1b558:
  dl = memoryAGet(ds, bx + 16084);
  flags.carry = dl < memoryAGet(ds, 0x057b);
  dl -= memoryAGet(ds, 0x057b);
  if (!flags.carry)
    goto loc_1b564;
  dl = ~dl;
loc_1b564:
  dh = 0;
  ax += dx;
  if (ax < bp)
    goto loc_1b56e;
  flags.carry = false;
  return;
loc_1b56e:
  flags.carry = true;
}
void sub_1b570()
{
  ah = 0;
  interrupt(0x1a);
  if (dx != memoryAGet16(ds, 0x40b5))
    goto loc_1b57b;
loc_1b57a:
  return;
loc_1b57b:
  memoryASet(ds, 0x40ff, memoryAGet(ds, 0x40ff) + 1);
  if (!(memoryAGet(ds, 0x40ff) & 0x03))
    goto loc_1b58a;
  memoryASet16(ds, 0x40b5, dx);
loc_1b58a:
  if (memoryAGet(ds, 0x40aa) < 0xa4)
    goto loc_1b57a;
  sub_1b75d();
  sub_1b787();
  if (flags.carry)
    goto loc_1b57a;
  sub_1a02d();
  if (dl > 0x30)
    goto loc_1b5cc;
  sub_1b72b();
  si = memoryAGet16(ds, 0x0008);
  si <<= 1;
  ax = memoryAGet16(ds, si + 16590);
  if (memoryAGet16(ds, 0x40cc) > ax)
    goto loc_1b5cc;
  sub_1cb8d();
  memoryASet16(ds, 0x40c8, 0x00ff);
  al = memoryAGet(ds, 0x40ca);
  memoryASet(ds, 0x40b7, al);
  al = memoryAGet(ds, 0x40cb);
  memoryASet(ds, 0x40b8, al);
  goto loc_1b65e;
loc_1b5cc:
  if (memoryAGet16(ds, 0x40c8) > 0x000a)
    goto loc_1b5e1;
  sub_1a02d();
  if (dl > 0x06)
    goto loc_1b5e4;
  memoryASet16(ds, 0x40c8, 0x00ff);
loc_1b5e1:
  goto loc_1b632;
  //   gap of 1 bytes
loc_1b5e4:
  bx = memoryAGet16(ds, 0x40c8);
  si = bx;
  si <<= 1;
  dl = 0;
  ax = memoryAGet16(ds, 0x40b2);
  ax &= 0x0ffc;
  if (ax == memoryAGet16(ds, si + 16606))
    goto loc_1b600;
  flags.carry = dl == 0xff;
  dl++;
  if (flags.carry)
    goto loc_1b600;
  dl = 0xff;
loc_1b600:
  memoryASet(ds, 0x40b7, dl);
  dl = 0;
  al = memoryAGet(ds, 0x40b4);
  al &= 0xfe;
  if (al == memoryAGet(ds, bx + 16628))
    goto loc_1b617;
  flags.carry = dl == 0xff;
  dl++;
  if (flags.carry)
    goto loc_1b617;
  dl = 0xff;
loc_1b617:
  memoryASet(ds, 0x40b8, dl);
  dl |= memoryAGet(ds, 0x40b7);
  if (dl)
    goto loc_1b65e;
  sub_1a02d();
  if (dl > 0x10)
    goto loc_1b65e;
  memoryASet16(ds, 0x40c8, 0x00ff);
  sub_1cb8d();
loc_1b632:
  sub_1a02d();
  if (dl > 0x30)
    goto loc_1b653;
  dl &= 0x01;
  if (dl != 0)
    goto loc_1b641;
  dl = 0xff;
loc_1b641:
  memoryASet(ds, 0x40b7, dl);
  sub_1a02d();
  dl &= 0x01;
  if (dl != 0)
    goto loc_1b64f;
  dl = 0xff;
loc_1b64f:
  memoryASet(ds, 0x40b8, dl);
loc_1b653:
  sub_1a02d();
  dx &= 0x00ff;
  memoryASet16(ds, 0x40c8, dx);
loc_1b65e:
  al = memoryAGet(ds, 0x40b4);
  if (memoryAGet(ds, 0x40b8) < 0x01)
    goto loc_1b689;
  if (memoryAGet(ds, 0x40b8) != 0x01)
    goto loc_1b679;
  al += 0x02;
  if (al < 0xa8)
    goto loc_1b686;
  al = 0xa7;
  memoryASet(ds, 0x40b8, 0xff);
  goto loc_1b686;
loc_1b679:
  al -= 0x02;
  if (al >= 0x30)
    goto loc_1b686;
  al = 0x30;
  memoryASet(ds, 0x40b8, 0x01);
loc_1b686:
  memoryASet(ds, 0x40b4, al);
loc_1b689:
  ax = memoryAGet16(ds, 0x40b2);
  if (memoryAGet(ds, 0x40b7) < 0x01)
    goto loc_1b6b6;
  if (memoryAGet(ds, 0x40b7) != 0x01)
    goto loc_1b6a7;
  ax += 0x0004;
  if (ax < 0x0136)
    goto loc_1b6b3;
  ax = 0x0135;
  memoryASet(ds, 0x40b7, 0xff);
  goto loc_1b6b3;
loc_1b6a7:
  flags.carry = ax < 0x0004;
  ax -= 0x0004;
  if (!flags.carry)
    goto loc_1b6b3;
  ax = 0;
  memoryASet(ds, 0x40b7, 0x01);
loc_1b6b3:
  memoryASet16(ds, 0x40b2, ax);
loc_1b6b6:
  sub_1b75d();
  cx = memoryAGet16(ds, 0x40b2);
  dl = memoryAGet(ds, 0x40b4);
  sub_19ee0();
  memoryASet16(ds, 0x40bc, ax);
  ax = 0xb800;
  es = ax;
  if (memoryAGet(ds, 0x40b9) != 0x00)
    goto loc_1b6e0;
  si = 0x3f2c;
  di = memoryAGet16(ds, 0x40ba);
  cx = 0x0501;
  sub_19fcd();
loc_1b6e0:
  sub_1b787();
  if (flags.carry)
    return;
  memoryASet(ds, 0x40b9, 0x00);
  memoryASet16(ds, 0x40be, memoryAGet16(ds, 0x40be) + 0x0002);
  bx = memoryAGet16(ds, 0x40be);
  bx &= 0x0006;
  si = memoryAGet16(ds, bx + 16576);
  if (memoryAGet(ds, 0x40b7) != 0xff)
    goto loc_1b705;
  si += 0x001e;
loc_1b705:
  di = memoryAGet16(ds, 0x40bc);
  memoryASet16(ds, 0x40ba, di);
  bp = 0x3f2c;
  cx = 0x0501;
  sub_19efc();
}
void sub_1b717()
{
  if (memoryAGet(ds, 0x0571) != 0x00)
    goto loc_1b729;
  al = memoryAGet(ds, 0x057b);
  al &= 0xf8;
  if (al != 0x88)
    goto loc_1b729;
  flags.carry = true;
  return;
loc_1b729:
  flags.carry = false;
}
void sub_1b72b()
{
  ax = memoryAGet16(ds, 0x40b2);
  dl = 0x01;
  flags.carry = ax < memoryAGet16(ds, 0x0579);
  ax -= memoryAGet16(ds, 0x0579);
  if (!flags.carry)
    goto loc_1b73a;
  ax = ~ax;
  dl = 0xff;
loc_1b73a:
  memoryASet(ds, 0x40ca, dl);
  memoryASet16(ds, 0x40cc, ax);
  al = memoryAGet(ds, 0x40b4);
  dl = 0x01;
  flags.carry = al < memoryAGet(ds, 0x057b);
  al -= memoryAGet(ds, 0x057b);
  if (!flags.carry)
    goto loc_1b750;
  al = ~al;
  dl = 0xff;
loc_1b750:
  memoryASet(ds, 0x40cb, dl);
  ah = 0;
  ax <<= 1;
  memoryASet16(ds, 0x40cc, memoryAGet16(ds, 0x40cc) + ax);
}
void sub_1b75d()
{
  ax = memoryAGet16(ds, 0x40b2);
  dl = memoryAGet(ds, 0x40b4);
  si = 0x0008;
  bx = memoryAGet16(ds, 0x0579);
  dh = memoryAGet(ds, 0x057b);
  di = 0x0018;
  cx = 0x0e05;
  sub_1a059();
  if (!flags.carry)
    return;
  if (memoryAGet(ds, 0x0552) != 0x00)
    return;
  memoryASet(ds, 0x0553, 0x01);
}
// INJECT: Error: cannot inject carry flag in sub_1b787()!
void sub_1b787()
{
  ax = memoryAGet16(ds, 0x40b2);
  dl = memoryAGet(ds, 0x40b4);
  si = 0x0008;
  bx = memoryAGet16(ds, 0x327d);
  dh = memoryAGet(ds, 0x327f);
  di = 0x0010;
  cx = 0x1e05;
  sub_1a059();
  if (!flags.carry)
    goto loc_1b7a9;
  memoryASet(ds, 0x40b8, 0xff);
loc_1b7a9:
  stop(/*inject ret*/);
}
void sub_1b7aa()
{
  cx = 0x0090;
  dl = 0x86;
  memoryASet16(ds, 0x40a8, cx);
  memoryASet(ds, 0x40aa, dl);
  sub_19ee0();
  memoryASet16(ds, 0x40ab, ax);
  sub_1b989();
  memoryASet(ds, 0x40af, 0x00);
  memoryASet(ds, 0x40b1, 0x00);
  memoryASet(ds, 0x40b9, 0x01);
  memoryASet(ds, 0x40b8, 0x00);
  memoryASet16(ds, 0x40c8, 0x00ff);
}
void sub_1b7db()
{
  ah = 0;
  interrupt(0x1a);
  if (dx != memoryAGet16(ds, 0x40ad))
    goto loc_1b7e6;
loc_1b7e5:
  return;
loc_1b7e6:
  memoryASet16(ds, 0x40ad, dx);
  if (memoryAGet(ds, 0x40aa) >= 0xa4)
    goto loc_1b7e5;
  sub_1b9b6();
  if (!flags.carry)
    goto loc_1b806;
  sub_1b717();
  if (!flags.carry)
    goto loc_1b7e5;
  memoryASet(ds, 0x0571, 0x01);
  memoryASet(ds, 0x055b, 0x10);
  return;
loc_1b806:
  sub_1b96e();
  if (!flags.carry)
    goto loc_1b879;
  if (memoryAGet(ds, 0x40af) != 0x00)
    goto loc_1b82a;
  al = memoryAGet(ds, 0x056e);
  if (al != 0x00)
    goto loc_1b827;
  al++;
  bx = memoryAGet16(ds, 0x40a8);
  if (bx > memoryAGet16(ds, 0x0579))
    goto loc_1b827;
  al = 0xff;
loc_1b827:
  memoryASet(ds, 0x40b0, al);
loc_1b82a:
  memoryASet(ds, 0x40af, 0x01);
  cx = 0x0020;
loc_1b832:
  ax = memoryAGet16(ds, 0x0579);
  dl = 0x01;
  if (memoryAGet(ds, 0x40b0) != 0x01)
    goto loc_1b845;
  ax -= 0x0008;
  dl = 0xff;
  goto loc_1b848;
loc_1b845:
  ax += 0x0008;
loc_1b848:
  memoryASet16(ds, 0x0579, ax);
  memoryASet(ds, 0x056e, dl);
  al = memoryAGet(ds, 0x057b);
  if (memoryAGet(ds, 0x0571) < 0x01)
    goto loc_1b869;
  if (memoryAGet(ds, 0x0571) != 0x01)
    goto loc_1b85f;
  al -= 0x03;
  goto loc_1b861;
loc_1b85f:
  al += 0x03;
loc_1b861:
  memoryASet(ds, 0x057b, al);
  al += 0x32;
  memoryASet(ds, 0x057c, al);
loc_1b869:
  push(cx);
  sub_1b96e();
  cx = pop();
  if (!flags.carry)
    goto loc_1b872;
  if (--cx)
    goto loc_1b832;
loc_1b872:
  sub_18413();
  sub_18342();
loc_1b878:
  return;
loc_1b879:
  if (memoryAGet(ds, 0x40b1) != 0x00)
    goto loc_1b8d2;
  if (memoryAGet(ds, 0x40af) == 0x00)
    goto loc_1b878;
  ax = memoryAGet16(ds, 0x40a8);
  if (memoryAGet(ds, 0x40b0) != 0x01)
    goto loc_1b896;
  ax += 0x0008;
  goto loc_1b899;
loc_1b896:
  ax -= 0x0008;
loc_1b899:
  memoryASet16(ds, 0x40a8, ax);
  sub_1b96e();
  if (!flags.carry)
    goto loc_1b8a2;
  return;
loc_1b8a2:
  ax = 0x0c00;
  bx = 0x0b54;
  sub_1cb6b();
  memoryASet(ds, 0x40af, 0x00);
  cx = memoryAGet16(ds, 0x40a8);
  dl = memoryAGet(ds, 0x40aa);
  sub_19ee0();
  memoryASet16(ds, 0x40ab, ax);
  sub_1b9a3();
  sub_1b989();
  ax = memoryAGet16(ds, 0x40a8);
  if (ax < 0x0078)
    goto loc_1b8d2;
  if (ax > 0x00a8)
    goto loc_1b8d2;
  return;
loc_1b8d2:
  memoryASet(ds, 0x40b1, 0x01);
  if (memoryAGet(ds, 0x1cbf) == 0x00)
    goto loc_1b8ee;
  sub_1b717();
  if (!flags.carry)
    goto loc_1b8ed;
  memoryASet(ds, 0x0571, 0x01);
  memoryASet(ds, 0x055b, 0x10);
loc_1b8ed:
  return;
loc_1b8ee:
  ah = 0;
  interrupt(0x1a);
  if (dx == memoryAGet16(ds, 0x40ad))
    goto loc_1b8d2;
  memoryASet16(ds, 0x40ad, dx);
  if (memoryAGet(ds, 0x0000) == 0x00)
    goto loc_1b91c;
  al = 0xb6;
  out(0x0043, al);
  al = memoryAGet(ds, 0x40aa);
  ah = 0;
  ax <<= 1;
  ax <<= 1;
  out(0x0042, al);
  al = ah;
  out(0x0042, al);
  in(al, 0x61);
  al |= 0x03;
  out(0x0061, al);
loc_1b91c:
  dl = memoryAGet(ds, 0x40aa);
  if (dl >= 0xa4)
    goto loc_1b93e;
  dl += 0x05;
  memoryASet(ds, 0x40aa, dl);
  cx = memoryAGet16(ds, 0x40a8);
  sub_19ee0();
  memoryASet16(ds, 0x40ab, ax);
  sub_1b9a3();
  sub_1b989();
  goto loc_1b8ee;
loc_1b93e:
  sub_1cd51();
  sub_1b9a3();
  bp = 0x401e;
  memoryASet16(ds, 0x40a6, memoryAGet16(ds, 0x40a6) - 1);
  di = memoryAGet16(ds, 0x40a6);
  si = 0x3f36;
  cx = 0x1104;
  sub_19f65();
  ax = memoryAGet16(ds, 0x40a8);
  memoryASet16(ds, 0x40b2, ax);
  al = memoryAGet(ds, 0x40aa);
  memoryASet(ds, 0x40b4, al);
  sub_1b72b();
  al = memoryAGet(ds, 0x40ca);
  memoryASet(ds, 0x40b7, al);
}
// INJECT: Error: cannot inject carry flag in sub_1b96e()!
void sub_1b96e()
{
  ax = memoryAGet16(ds, 0x40a8);
  dl = memoryAGet(ds, 0x40aa);
  si = 0x0018;
  bx = memoryAGet16(ds, 0x0579);
  dh = memoryAGet(ds, 0x057b);
  di = si;
  cx = 0x0e10;
  sub_1a059();
  stop(/*inject ret*/);
}
void sub_1b989()
{
  ax = 0xb800;
  es = ax;
  bp = 0x401e;
  si = 0x3fbe;
  di = memoryAGet16(ds, 0x40ab);
  memoryASet16(ds, 0x40a6, di);
  cx = 0x1003;
  sub_19f65();
}
void sub_1b9a3()
{
  ax = 0xb800;
  es = ax;
  si = 0x401e;
  di = memoryAGet16(ds, 0x40a6);
  cx = 0x1003;
  sub_19fcd();
}
void sub_1b9b6()
{
  if (memoryAGet(ds, 0x327f) < 0x66)
    goto loc_1b9d4;
  ax = memoryAGet16(ds, 0x40a8);
  ax -= 0x0014;
  if (ax > memoryAGet16(ds, 0x327d))
    goto loc_1b9d4;
  ax += 0x0030;
  if (ax < memoryAGet16(ds, 0x327d))
    goto loc_1b9d4;
  flags.carry = true;
  return;
loc_1b9d4:
  flags.carry = false;
}
// INJECT: Error: cannot inject carry flag in sub_1b9e0()!
void sub_1b9e0()
{
  ax = memoryAGet16(ds, 0x327d);
  dl = memoryAGet(ds, 0x327f);
  si = 0x0010;
  bx = memoryAGet16(ds, 0x0579);
  flags.carry = bx < 0x0008;
  bx -= 0x0008;
  if (!flags.carry)
    goto loc_1b9f5;
  bx = 0;
loc_1b9f5:
  dh = memoryAGet(ds, 0x057b);
  dh += 0x03;
  di = 0x0028;
  cx = 0x0e1e;
  sub_1a059();
  stop(/*inject ret*/);
}
void sub_1ba06()
{
  ah = 0;
  interrupt(0x1a);
  ax = dx;
  ax -= memoryAGet16(ds, 0x44d7);
  si = memoryAGet16(ds, 0x0008);
  si <<= 1;
  if (ax > memoryAGet16(ds, si + 17628))
    goto loc_1ba1d;
loc_1ba1c:
  return;
loc_1ba1d:
  memoryASet16(ds, 0x44d7, dx);
  if (memoryAGet(ds, 0x1cb8) != 0x00)
    goto loc_1ba1c;
  memoryASet(ds, 0x44fc, 0x00);
  cx = 0x000c;
loc_1ba30:
  bx = cx;
  bx--;
  bl <<= 1;
  if (memoryAGet16(ds, bx + 17473) == 0x0000)
    goto loc_1baad;
  ax = memoryAGet16(ds, bx + 17401);
  if (al != memoryAGet(ds, 0x057b))
    goto loc_1ba8d;
  ax = memoryAGet16(ds, bx + 17377);
  flags.carry = ax < memoryAGet16(ds, 0x0579);
  ax -= memoryAGet16(ds, 0x0579);
  if (!flags.carry)
    goto loc_1ba52;
  ax = ~ax;
loc_1ba52:
  si = memoryAGet16(ds, 0x0008);
  si <<= 1;
  if (ax > memoryAGet16(ds, si + 17644))
    goto loc_1ba8d;
  if (memoryAGet16(ds, bx + 17497) < 0x0002)
    goto loc_1ba7c;
  ax = memoryAGet16(ds, bx + 17425);
  memoryASet16(ds, 0x44da, ax);
  sub_1babd();
  sub_1bad1();
  sub_1a569();
  sub_18375();
  sub_19366();
  return;
loc_1ba7c:
  memoryASet16(ds, bx + 17497, memoryAGet16(ds, bx + 17497) + 1);
  if (memoryAGet16(ds, bx + 17497) < 0x0002)
    goto loc_1baa0;
  memoryASet(ds, 0x44fc, memoryAGet(ds, 0x44fc) + 1);
  goto loc_1baa0;
loc_1ba8d:
  if (memoryAGet16(ds, bx + 17497) == 0x0000)
    goto loc_1baad;
  sub_1a02d();
  if (dl > 0x38)
    goto loc_1baa0;
  memoryASet16(ds, bx + 17497, memoryAGet16(ds, bx + 17497) - 1);
loc_1baa0:
  push(cx);
  push(bx);
  sub_1bb07();
  bx = pop();
  sub_1bb46();
  sub_1baf1();
  cx = pop();
loc_1baad:
  if (--cx)
    goto loc_1baba;
  if (memoryAGet(ds, 0x44fc) == 0x00)
    goto loc_1bab9;
  sub_1c8c1();
loc_1bab9:
  return;
loc_1baba:
  goto loc_1ba30;
}
void sub_1babd()
{
  if (memoryAGet(ds, 0x44bd) == 0x00)
    goto loc_1bacd;
  sub_1bd33();
  memoryASet(ds, 0x44bd, 0x00);
  return;
loc_1bacd:
  sub_18413();
}
void sub_1bad1()
{
  push(ds);
  es = pop();
  flags.direction = false;
  di = 0x000e;
  si = di;
  ax = 0xaaaa;
  cx = 0x0041;
  rep_stosw<MemAuto, DirAuto>();
  ax = 0xb800;
  es = ax;
  di = memoryAGet16(ds, 0x44da);
  cx = 0x0d05;
  sub_19fcd();
}
void sub_1baf1()
{
  if (memoryAGet(ds, 0x44d9) == 0x00)
    goto loc_1bb02;
  if (memoryAGet(ds, 0x44bd) == 0x00)
    goto loc_1bb03;
  sub_1bd4d();
loc_1bb02:
  return;
loc_1bb03:
  sub_18375();
}
void sub_1bb07()
{
  memoryASet(ds, 0x44d9, 0x00);
  ax = memoryAGet16(ds, bx + 17377);
  dx = memoryAGet16(ds, bx + 17401);
  ax -= 0x0014;
  si = 0x0028;
  bx = memoryAGet16(ds, 0x0579);
  dh = memoryAGet(ds, 0x057b);
  cx = 0x0e06;
  di = 0x0018;
  sub_1a059();
  if (!flags.carry)
    return;
  memoryASet(ds, 0x44d9, 0x01);
loc_1bb32:
  sub_18608();
  if (flags.zero)
    goto loc_1bb32;
  if (memoryAGet(ds, 0x44bd) == 0x00)
    goto loc_1bb42;
  sub_1bd33();
  return;
loc_1bb42:
  sub_18413();
}
void sub_1bb46()
{
  ax = memoryAGet16(ds, bx + 17425);
  si = memoryAGet16(ds, bx + 17497);
  si <<= 1;
  si += 0x4100;
  ax += 0x00a7;
  if (memoryAGet16(ds, bx + 17449) == 0x429c)
    goto loc_1bb65;
  ax -= 0x0006;
  si += 0x0006;
loc_1bb65:
  di = ax;
  ax = 0xb800;
  es = ax;
  cx = 0x0101;
  sub_19fcd();
}
void sub_1bb73()
{
  if (memoryAGet(ds, 0x1cb8) != 0x00)
    goto loc_1bb96;
  if (memoryAGet(ds, 0x44be) == 0x00)
    goto loc_1bb8c;
  al = memoryAGet(ds, 0x44be);
  memoryASet(ds, 0x0698, al);
  memoryASet(ds, 0x0699, 0x00);
loc_1bb8c:
  ah = 0;
  interrupt(0x1a);
  if (dx != memoryAGet16(ds, 0x44d3))
    goto loc_1bb97;
loc_1bb96:
  return;
loc_1bb97:
  memoryASet16(ds, 0x44d3, dx);
  if (memoryAGet(ds, 0x0584) == 0x00)
    goto loc_1bbc5;
  if (memoryAGet(ds, 0x44bd) == 0x00)
    goto loc_1bbc4;
  sub_1bd33();
  sub_1a5d0();
  sub_18354();
  sub_1a569();
  memoryASet(ds, 0x44bd, 0x00);
  memoryASet(ds, 0x43e0, 0x01);
  memoryASet(ds, 0x44be, 0x00);
loc_1bbc4:
  return;
loc_1bbc5:
  if (memoryAGet(ds, 0x069a) == 0x00)
    goto loc_1bbcf;
  goto loc_1bc29;
  //   gap of 1 bytes
loc_1bbcf:
  ax = 0xffff;
  memoryASet16(ds, 0x44c1, ax);
  memoryASet16(ds, 0x44bf, ax);
  cx = 0x000c;
  si = memoryAGet16(ds, 0x0579);
  dl = memoryAGet(ds, 0x057b);
  dl += 0x08;
loc_1bbe6:
  bx = cx;
  bx--;
  if (memoryAGet(ds, bx + 17604) < 0x01)
    goto loc_1bc20;
  if (dl != memoryAGet(ds, bx + 17561))
    goto loc_1bc20;
  ax = si;
  bl <<= 1;
  dh = 0xff;
  flags.carry = ax < memoryAGet16(ds, bx + 17537);
  ax -= memoryAGet16(ds, bx + 17537);
  if (!flags.carry)
    goto loc_1bc06;
  ax = ~ax;
  dh = 0x01;
loc_1bc06:
  if (ax > memoryAGet16(ds, 0x44bf))
    goto loc_1bc20;
  memoryASet16(ds, 0x44bf, ax);
  ax = memoryAGet16(ds, bx + 17573);
  memoryASet16(ds, 0x44d1, ax);
  bl >>= 1;
  memoryASet16(ds, 0x44c1, bx);
  memoryASet(ds, 0x44c3, dh);
loc_1bc20:
  if (--cx)
    goto loc_1bbe6;
  if (memoryAGet16(ds, 0x44c1) < 0x000c)
    goto loc_1bc50;
loc_1bc29:
  if (memoryAGet(ds, 0x44bd) == 0x00)
    goto loc_1bc3b;
  sub_1bd33();
  sub_18375();
  memoryASet(ds, 0x069a, 0x10);
loc_1bc3b:
  memoryASet(ds, 0x44bd, 0x00);
  memoryASet(ds, 0x43e0, 0x01);
  memoryASet(ds, 0x44d0, 0x00);
  memoryASet(ds, 0x44be, 0x00);
  return;
loc_1bc50:
  if (memoryAGet16(ds, 0x44bf) < 0x0004)
    goto loc_1bc7b;
  if (memoryAGet16(ds, 0x44bf) > 0x0008)
    goto loc_1bc63;
  memoryASet(ds, 0x0572, 0x04);
loc_1bc63:
  al = memoryAGet(ds, 0x44c3);
  memoryASet(ds, 0x0698, al);
  memoryASet(ds, 0x056e, al);
  memoryASet(ds, 0x44be, al);
  memoryASet(ds, 0x0699, 0x00);
  memoryASet(ds, 0x0571, 0x00);
  goto loc_1bc29;
loc_1bc7b:
  memoryASet(ds, 0x44be, 0x00);
  if (memoryAGet(ds, 0x44bd) != 0x00)
    goto loc_1bc8d;
  sub_18413();
  sub_18354();
loc_1bc8d:
  memoryASet(ds, 0x44bd, 0x01);
  al = 0;
  flags.carry = (memoryAGet(ds, 0x44d0) + 0x30) >= 0x100;
  memoryASet(ds, 0x44d0, memoryAGet(ds, 0x44d0) + 0x30);
  if (!flags.carry)
    goto loc_1bc9d;
  al++;
loc_1bc9d:
  memoryASet(ds, 0x44d5, al);
  cx = memoryAGet16(ds, 0x0579);
  cx &= 0x0ffc;
  dl = memoryAGet(ds, 0x057b);
  dl += 0x03;
  if (memoryAGet16(ds, 0x44d1) == 0x410c)
    goto loc_1bcc5;
  cx += 0x0008;
  if (cx < 0x0127)
    goto loc_1bccc;
  cx = 0x0126;
  goto loc_1bccc;
loc_1bcc5:
  flags.carry = cx < 0x0008;
  cx -= 0x0008;
  if (!flags.carry)
    goto loc_1bccc;
  cx = 0;
loc_1bccc:
  sub_19ee0();
  memoryASet16(ds, 0x43dc, ax);
loc_1bcd2:
  sub_18608();
  if (flags.zero)
    goto loc_1bcd2;
  sub_1bd33();
  if (memoryAGet(ds, 0x44d5) == 0x00)
    goto loc_1bd2f;
  bx = memoryAGet16(ds, 0x44c1);
  if (memoryAGet(ds, bx + 17604) == 0x00)
    goto loc_1bd2f;
  memoryASet(ds, bx + 17604, memoryAGet(ds, bx + 17604) - 1);
  if (memoryAGet(ds, bx + 17604) != 0)
    goto loc_1bd17;
  push(bx);
  ax = 0x08fd;
  bx = 0x0723;
  sub_1cb6b();
  bx = pop();
  memoryASet(ds, 0x0698, 0x00);
  memoryASet(ds, 0x44be, 0x00);
  memoryASet(ds, 0x069a, 0x10);
  memoryASet(ds, 0x44d6, memoryAGet(ds, 0x44d6) - 1);
  if (memoryAGet(ds, 0x44d6) != 0)
    goto loc_1bd17;
  memoryASet(ds, 0x0553, 0x01);
loc_1bd17:
  push(bx);
  sub_1b9e0();
  bx = pop();
  if (!flags.carry)
    goto loc_1bd2c;
  push(bx);
  sub_1a5d0();
  bx = pop();
  sub_1bdf8();
  sub_1a569();
  goto loc_1bd2f;
  //   gap of 1 bytes
loc_1bd2c:
  sub_1bdf8();
loc_1bd2f:
  sub_1bd4d();
}
void sub_1bd33()
{
  if (memoryAGet(ds, 0x43e0) != 0x00)
    return;
  di = memoryAGet16(ds, 0x43de);
  si = 0x43a0;
  ax = 0xb800;
  es = ax;
  cx = 0x0a03;
  sub_19fcd();
}
void sub_1bd4d()
{
  memoryASet(ds, 0x43e0, 0x00);
  ax = 0xb800;
  es = ax;
  di = memoryAGet16(ds, 0x43dc);
  memoryASet16(ds, 0x43de, di);
  bp = 0x43a0;
  si = memoryAGet16(ds, 0x44d1);
  if (memoryAGet(ds, 0x44d0) < 0x80)
    goto loc_1bd70;
  si += 0x003c;
loc_1bd70:
  cx = 0x0a03;
  sub_19f65();
}
void sub_1bd77()
{
  push(ds);
  es = pop();
  ax = 0;
  di = 0x4441;
  cx = 0x000c;
  rep_stosw<MemAuto, DirAuto>();
  ax = 0xb800;
  es = ax;
  bx = memoryAGet16(ds, 0x0008);
  cl = memoryAGet(ds, bx + 17521);
  ch = 0;
loc_1bd92:
  sub_1a02d();
  bl = dl;
  bx &= 0x001e;
  if (bl >= 0x18)
    goto loc_1bd92;
  if (memoryAGet16(ds, bx + 17473) != 0x0000)
    goto loc_1bd92;
  memoryASet16(ds, bx + 17497, 0x0000);
  memoryASet16(ds, bx + 17473, 0x0001);
  push(cx);
  si = memoryAGet16(ds, bx + 17449);
  di = memoryAGet16(ds, bx + 17425);
  cx = 0x0d05;
  sub_19fcd();
  cx = pop();
  if (--cx)
    goto loc_1bd92;
  cx = 0x000c;
loc_1bdc8:
  bx = cx;
  bx--;
  si = memoryAGet16(ds, 0x0008);
  dl = memoryAGet(ds, si + 17529);
  memoryASet(ds, bx + 17604, dl);
  push(cx);
  sub_1bdf8();
  cx = pop();
  if (--cx)
    goto loc_1bdc8;
  memoryASet(ds, 0x44d0, 0x00);
  memoryASet(ds, 0x44bd, 0x00);
  memoryASet(ds, 0x43e0, 0x01);
  memoryASet(ds, 0x44d6, 0x0c);
  memoryASet(ds, 0x44be, 0x00);
}
void sub_1bdf8()
{
  sub_1be18();
  di = ax;
  al = memoryAGet(ds, bx + 17604);
  ah = 0;
  cl = 0x05;
  ax <<= cl;
  ax += 0x41fc;
  si = ax;
  cx = 0x0802;
  ax = 0xb800;
  es = ax;
  sub_19fcd();
}
void sub_1be18()
{
  push(bx);
  dl = memoryAGet(ds, bx + 17561);
  bl <<= 1;
  cx = memoryAGet16(ds, bx + 17537);
  sub_19ee0();
  bx = pop();
}
void sub_1be30()
{
}
void sub_1be40()
{
  ah = 0;
  interrupt(0x1a);
  if (dx != memoryAGet16(ds, 0x45b8))
    goto loc_1be4b;
  return;
loc_1be4b:
  memoryASet16(ds, 0x45b6, memoryAGet16(ds, 0x45b6) + 1);
  bx = memoryAGet16(ds, 0x45b6);
  if (bx == 0x0001)
    goto loc_1be68;
  if (bx == 0x0004)
    goto loc_1be68;
  if (bx < 0x0007)
    goto loc_1be6c;
  bx = 0;
  memoryASet16(ds, 0x45b6, bx);
loc_1be68:
  memoryASet16(ds, 0x45b8, dx);
loc_1be6c:
  sub_1c1fd();
  sub_1c25d();
  if (!flags.carry)
    goto loc_1be75;
loc_1be74:
  return;
loc_1be75:
  if (memoryAGet16(ds, 0x454f) == 0x0000)
    goto loc_1bebc;
  ah = 0;
  interrupt(0x1a);
  dx -= memoryAGet16(ds, 0x454f);
  bx = memoryAGet16(ds, 0x0008);
  bl <<= 1;
  ax = memoryAGet16(ds, bx + 17863);
  if (memoryAGet16(ds, 0x45b6) != 0x0000)
    goto loc_1be97;
  ax <<= 1;
loc_1be97:
  if (dx < ax)
    goto loc_1be74;
  memoryASet16(ds, 0x454f, 0x0000);
  memoryASet(ds, 0x454e, 0x01);
  ax = 0x0024;
  if (memoryAGet16(ds, 0x0579) > 0x00a0)
    goto loc_1beb4;
  ax = 0x0108;
loc_1beb4:
  memoryASet16(ds, 0x4548, ax);
  memoryASet(ds, 0x454a, 0x00);
loc_1bebc:
  sub_1c000();
  if (!flags.carry)
    goto loc_1bec9;
  bx = memoryAGet16(ds, 0x45b6);
  sub_1c1eb();
  return;
loc_1bec9:
  if (memoryAGet(ds, 0x4553) == 0x00)
    goto loc_1bee8;
  memoryASet(ds, 0x4553, memoryAGet(ds, 0x4553) - 1);
  if (memoryAGet(ds, 0x4553) != 0)
    goto loc_1bee5;
  dl = 0x01;
  if (memoryAGet(ds, 0x454a) == 0xff)
    goto loc_1bee1;
  dl = 0xff;
loc_1bee1:
  memoryASet(ds, 0x454a, dl);
loc_1bee5:
  goto loc_1bf44;
  //   gap of 1 bytes
loc_1bee8:
  al = memoryAGet(ds, 0x454b);
  if (al > memoryAGet(ds, 0x057b))
    goto loc_1bf44;
  if (memoryAGet16(ds, 0x45b6) != 0x0006)
    goto loc_1beff;
  if (memoryAGet(ds, 0x057b) < 0x28)
    goto loc_1bf0c;
loc_1beff:
  sub_1a02d();
  bx = memoryAGet16(ds, 0x0008);
  if (dl > memoryAGet(ds, bx + 17855))
    goto loc_1bf44;
loc_1bf0c:
  dl = 0;
  ax = memoryAGet16(ds, 0x4548);
  ax &= 0x0ff8;
  cx = memoryAGet16(ds, 0x0579);
  cx &= 0x0ff8;
  if (ax == cx)
    goto loc_1bf26;
  dl = 0x01;
  if (ax < cx)
    goto loc_1bf26;
  dl = 0xff;
loc_1bf26:
  memoryASet(ds, 0x454a, dl);
  if (memoryAGet(ds, 0x057b) < 0x28)
    goto loc_1bf44;
  if (memoryAGet16(ds, 0x45b6) != 0x0006)
    goto loc_1bf44;
  al = 0x01;
  if (dl == 0xff)
    goto loc_1bf41;
  al = 0xff;
loc_1bf41:
  memoryASet(ds, 0x454a, al);
loc_1bf44:
  memoryASet16(ds, 0x45bc, 0x0008);
  if (memoryAGet(ds, 0x4553) == 0x00)
    goto loc_1bf57;
  memoryASet16(ds, 0x45bc, 0x0004);
loc_1bf57:
  ax = memoryAGet16(ds, 0x4548);
  if (memoryAGet(ds, 0x454a) >= 0x01)
    goto loc_1bf76;
  sub_1a02d();
  if (dl > 0x10)
    goto loc_1bfd1;
  dl &= 0x01;
  if (dl != 0)
    goto loc_1bf70;
  dl = 0xff;
loc_1bf70:
  memoryASet(ds, 0x454a, dl);
  goto loc_1bfd1;
loc_1bf76:
  if (memoryAGet(ds, 0x454a) != 0x01)
    goto loc_1bf90;
  ax += memoryAGet16(ds, 0x45bc);
  if (ax < 0x010b)
    goto loc_1bfa8;
  ax = 0x010a;
  memoryASet(ds, 0x454a, 0xff);
  memoryASet(ds, 0x4553, 0x00);
  goto loc_1bfa8;
loc_1bf90:
  flags.carry = ax < memoryAGet16(ds, 0x45bc);
  ax -= memoryAGet16(ds, 0x45bc);
  if (flags.carry)
    goto loc_1bf9b;
  if (ax > 0x0024)
    goto loc_1bfa8;
loc_1bf9b:
  ax = 0x0025;
  memoryASet(ds, 0x454a, 0x01);
  memoryASet(ds, 0x4553, 0x00);
loc_1bfa8:
  memoryASet16(ds, 0x4548, ax);
  memoryASet16(ds, 0x4551, memoryAGet16(ds, 0x4551) + 0x0002);
  if (memoryAGet16(ds, 0x4551) < 0x000c)
    goto loc_1bfbd;
  memoryASet16(ds, 0x4551, 0x0000);
loc_1bfbd:
  if (memoryAGet(ds, 0x4553) != 0x00)
    goto loc_1bfd1;
  sub_1a02d();
  if (dl > 0x08)
    goto loc_1bfd1;
  memoryASet(ds, 0x454a, 0x00);
loc_1bfd1:
  cx = memoryAGet16(ds, 0x4548);
  dl = memoryAGet(ds, 0x454b);
  sub_19ee0();
  memoryASet16(ds, 0x45ba, ax);
  sub_1c25d();
  if (!flags.carry)
    goto loc_1bfe5;
  return;
loc_1bfe5:
  sub_1c000();
  if (flags.carry)
    goto loc_1bff8;
  sub_1c17a();
  sub_1c140();
  memoryASet(ds, 0x45be, 0x00);
  sub_1c0a5();
loc_1bff8:
  bx = memoryAGet16(ds, 0x45b6);
  sub_1c1eb();
}
void sub_1c000()
{
  ax = memoryAGet16(ds, 0x0579);
  dl = memoryAGet(ds, 0x057b);
  si = 0x0018;
  di = si;
  bx = memoryAGet16(ds, 0x4548);
  dh = memoryAGet(ds, 0x454b);
  cx = 0x0c0e;
  sub_1a059();
  if (!flags.carry)
    return;
  if (memoryAGet16(ds, 0x45b6) != 0x0006)
    goto loc_1c030;
  memoryASet(ds, 0x0553, 0x01);
  sub_18413();
  sub_1c17a();
  flags.carry = true;
  return;
loc_1c030:
  sub_18413();
  sub_1c17a();
  sub_18375();
  memoryASet(ds, 0x055b, 0x04);
  memoryASet(ds, 0x0571, 0x01);
  memoryASet(ds, 0x0576, 0x04);
  memoryASet(ds, 0x0578, 0x08);
  memoryASet(ds, 0x4553, 0x04);
  dl = 0x01;
  ax = memoryAGet16(ds, 0x4548);
  if (ax > memoryAGet16(ds, 0x0579))
    goto loc_1c05f;
  dl = 0xff;
loc_1c05f:
  memoryASet(ds, 0x454a, dl);
  ax = 0x0ce4;
  bx = 0x123b;
  sub_1cb6b();
  flags.carry = true;
}
void sub_1c06e()
{
  memoryASet(ds, 0x45be, 0x01);
  ax = memoryAGet16(ds, 0x45b6);
  push(ax);
  memoryASet16(ds, 0x45b6, 0x0000);
loc_1c07d:
  bx = memoryAGet16(ds, 0x45b6);
  sub_1c1fd();
  if (memoryAGet16(ds, 0x454f) != 0x0000)
    goto loc_1c095;
  sub_1c0a5();
  bx = memoryAGet16(ds, 0x45b6);
  sub_1c1eb();
loc_1c095:
  memoryASet16(ds, 0x45b6, memoryAGet16(ds, 0x45b6) + 1);
  if (memoryAGet16(ds, 0x45b6) < 0x0007)
    goto loc_1c07d;
  ax = pop();
  memoryASet16(ds, 0x45b6, ax);
}
void sub_1c0a5()
{
  cx = 0x0008;
loc_1c0a8:
  bx = cx;
  bx--;
  if (memoryAGet(ds, bx + 11122) == 0x00)
    goto loc_1c0d3;
  push(cx);
  dl = memoryAGet(ds, bx + 11114);
  bl <<= 1;
  ax = memoryAGet16(ds, bx + 11098);
  si = 0x0018;
  di = si;
  bx = memoryAGet16(ds, 0x4548);
  dh = memoryAGet(ds, 0x454b);
  cx = 0x0c0f;
  sub_1a059();
  cx = pop();
  if (flags.carry)
    goto loc_1c0d6;
loc_1c0d3:
  if (--cx)
    goto loc_1c0a8;
  return;
loc_1c0d6:
  push(cx);
  if (memoryAGet(ds, 0x45be) != 0x00)
    goto loc_1c0eb;
  sub_18413();
  if (memoryAGet(ds, 0x70f2) == 0x00)
    goto loc_1c0eb;
  sub_1d45b();
loc_1c0eb:
  sub_1c17a();
  cx = pop();
  bx = cx;
  bx--;
  memoryASet(ds, bx + 11122, 0x00);
  dl = memoryAGet(ds, bx + 11114);
  bl <<= 1;
  cx = memoryAGet16(ds, bx + 11098);
  sub_19ee0();
  di = ax;
  si = 0x2b7a;
  ax = 0xb800;
  es = ax;
  cx = 0x0f03;
  sub_19fcd();
  if (memoryAGet(ds, 0x45be) != 0x00)
    goto loc_1c128;
  if (memoryAGet(ds, 0x70f2) == 0x00)
    goto loc_1c125;
  sub_1d42a();
loc_1c125:
  sub_18375();
loc_1c128:
  dx = 0;
  if (memoryAGet16(ds, 0x45b6) == 0x0006)
    goto loc_1c13b;
  ah = 0;
  interrupt(0x1a);
  if (dx != 0x0000)
    goto loc_1c13b;
  dx--;
loc_1c13b:
  memoryASet16(ds, 0x454f, dx);
}
void sub_1c140()
{
  memoryASet(ds, 0x454e, 0x00);
  si = 0x4500;
  if (memoryAGet(ds, 0x454a) == 0x00)
    goto loc_1c16e;
  bx = memoryAGet16(ds, 0x4551);
  if (memoryAGet(ds, 0x4553) == 0x00)
    goto loc_1c160;
  bl &= 0x02;
  bl += 0x0c;
loc_1c160:
  if (memoryAGet(ds, 0x454a) != 0xff)
    goto loc_1c16a;
  bx += 0x0010;
loc_1c16a:
  si = memoryAGet16(ds, bx + 19040);
loc_1c16e:
  di = memoryAGet16(ds, 0x45ba);
  memoryASet16(ds, 0x454c, di);
  sub_1c20f();
}
void sub_1c17a()
{
  if (memoryAGet(ds, 0x454e) != 0x00)
    return;
  di = memoryAGet16(ds, 0x454c);
  sub_1c238();
}
void sub_1c189()
{
  memoryASet16(ds, 0x45b6, 0x0000);
loc_1c18f:
  sub_1a02d();
  dx &= 0x007f;
  dx += 0x0060;
  memoryASet16(ds, 0x4548, dx);
  memoryASet(ds, 0x454a, 0x00);
  memoryASet(ds, 0x454e, 0x01);
  memoryASet16(ds, 0x4551, 0x0000);
  memoryASet(ds, 0x4553, 0x00);
  dx = 0;
  if (memoryAGet16(ds, 0x45b6) != 0x0000)
    goto loc_1c1c5;
  ah = 0;
  interrupt(0x1a);
  if (dx != 0x0000)
    goto loc_1c1c5;
  dx--;
loc_1c1c5:
  memoryASet16(ds, 0x454f, dx);
  bx = memoryAGet16(ds, 0x45b6);
  al = memoryAGet(ds, bx + 11220);
  al += 0x03;
  memoryASet(ds, 0x454b, al);
  sub_1c1eb();
  memoryASet16(ds, 0x45b6, memoryAGet16(ds, 0x45b6) + 1);
  if (memoryAGet16(ds, 0x45b6) < 0x0007)
    goto loc_1c18f;
  memoryASet16(ds, 0x45b6, 0x0000);
}
void sub_1c1eb()
{
  push(ds);
  es = pop();
  bl <<= 1;
  flags.direction = false;
  di = memoryAGet16(ds, bx + 17832);
  si = 0x4548;
  cx = 0x000c;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
}
void sub_1c1fd()
{
  push(ds);
  es = pop();
  bl <<= 1;
  flags.direction = false;
  si = memoryAGet16(ds, bx + 17832);
  di = 0x4548;
  cx = 0x000c;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
}
void sub_1c20f()
{
  ax = 0xb800;
  es = ax;
  flags.direction = false;
  dh = 0x0c;
loc_1c217:
  cx = 0x0003;
loc_1c21a:
  bx = memoryAGet16(es, di);
  lodsw<MemAuto, DirAuto>();
  ax |= bx;
  stosw<MemAuto, DirAuto>();
  if (--cx)
    goto loc_1c21a;
  di -= 0x0006;
  di ^= 0x2000;
  if (di & 0x2000)
    goto loc_1c233;
  di += 0x0050;
loc_1c233:
  dh--;
  if (dh != 0)
    goto loc_1c217;
}
void sub_1c238()
{
  ax = 0xb800;
  es = ax;
  flags.direction = false;
  dh = 0x0c;
  ax = 0x5555;
loc_1c243:
  cx = 0x0003;
  rep_stosw<MemAuto, DirAuto>();
  di -= 0x0006;
  di ^= 0x2000;
  if (di & 0x2000)
    goto loc_1c258;
  di += 0x0050;
loc_1c258:
  dh--;
  if (dh != 0)
    goto loc_1c243;
}
// INJECT: Error: cannot inject carry flag in sub_1c25d()!
void sub_1c25d()
{
  if (memoryAGet(ds, 0x70f2) != 0x00)
    goto loc_1c266;
  flags.carry = false;
  return;
loc_1c266:
  ax = memoryAGet16(ds, 0x70f3);
  dl = memoryAGet(ds, 0x70f5);
  si = 0x0010;
  bx = memoryAGet16(ds, 0x4548);
  dh = memoryAGet(ds, 0x454b);
  di = 0x0018;
  cx = 0x0c08;
  sub_1a059();
  stop(/*inject ret*/);
}
void sub_1c290()
{
  ax = 0xb800;
  es = ax;
  ax = memoryAGet16(ds, 0x0579);
  if (ax < 0x0117)
    goto loc_1c2a0;
  ax = 0x0116;
loc_1c2a0:
  flags.carry = ax < 0x0010;
  ax -= 0x0010;
  if (!flags.carry)
    goto loc_1c2a7;
  ax = 0;
loc_1c2a7:
  ax &= 0x0ff0;
  memoryASet16(ds, 0x0579, ax);
  memoryASet(ds, 0x057b, 0x14);
  flags.carry = ax < 0x0080;
  ax -= 0x0080;
  if (!flags.carry)
    goto loc_1c2b9;
  ax = ~ax;
loc_1c2b9:
  cl = 0x03;
  ax >>= cl;
  if (ax <= 0x000d)
    goto loc_1c2c5;
  ax = 0x000d;
loc_1c2c5:
  ax += 0x0002;
  memoryASet16(ds, 0x4d6a, ax);
  memoryASet16(ds, 0x4dd6, 0x000a);
loc_1c2d1:
  if (memoryAGet16(ds, 0x4dd6) == 0x000a)
    goto loc_1c2db;
  sub_1cd93();
loc_1c2db:
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x4a80, dx);
  ax = memoryAGet16(ds, 0x0579);
  cx = ax;
  cx &= 0x0ff0;
  if (cx != 0x0080)
    goto loc_1c2f6;
  ax = cx;
  goto loc_1c302;
loc_1c2f6:
  if (cx < 0x0080)
    goto loc_1c2fe;
  ax -= memoryAGet16(ds, 0x4d6a);
  goto loc_1c302;
loc_1c2fe:
  ax += memoryAGet16(ds, 0x4d6a);
loc_1c302:
  memoryASet16(ds, 0x0579, ax);
  if (memoryAGet(ds, 0x057b) < 0x54)
    goto loc_1c30d;
  return;
loc_1c30d:
  memoryASet(ds, 0x057b, memoryAGet(ds, 0x057b) + 0x08);
  cx = memoryAGet16(ds, 0x0579);
  cx += 0x0004;
  dl = memoryAGet(ds, 0x057b);
  sub_19ee0();
  di = ax;
  memoryASet16(ds, 0x4dd8, di);
  si = 0x4b8a;
  bp = 0x000e;
  cx = 0x2007;
  sub_19efc();
  di = memoryAGet16(ds, 0x4dd8);
  di += 0x00f3;
  si = 0x4a82;
  cx = 0x0d04;
  sub_19fcd();
  if (memoryAGet16(ds, 0x4dd6) != 0x000a)
    goto loc_1c350;
  sub_1c95e();
  sub_1cd84();
loc_1c350:
  sub_1cd93();
  ah = 0;
  interrupt(0x1a);
  dx -= memoryAGet16(ds, 0x4a80);
  if (dx < memoryAGet16(ds, 0x4dd6))
    goto loc_1c350;
  if (memoryAGet16(ds, 0x4dd6) != 0x000a)
    goto loc_1c371;
  sub_1aae0();
  bx = 0;
  ah = 0x0b;
  interrupt(0x10);
loc_1c371:
  memoryASet16(ds, 0x4dd6, 0x0002);
  goto loc_1c2d1;
}
void sub_1c37a()
{
  cx = 0x0003;
loc_1c37d:
  bx = 0x0003;
  bx -= cx;
  bx <<= 1;
  ax = memoryAGet16(ds, bx + 19876);
  memoryASet16(ds, 0x4d6a, ax);
  ax = memoryAGet16(ds, bx + 19882);
  memoryASet16(ds, 0x4d6c, ax);
  ax = memoryAGet16(ds, bx + 19864);
  memoryASet16(ds, 0x4dcc, ax);
  ax = memoryAGet16(ds, bx + 19870);
  memoryASet16(ds, 0x4dce, ax);
  ax = memoryAGet16(ds, bx + 19888);
  memoryASet16(ds, 0x4dd0, ax);
  ax = memoryAGet16(ds, bx + 19894);
  memoryASet16(ds, 0x4dd2, ax);
  ax = memoryAGet16(ds, bx + 19900);
  memoryASet16(ds, 0x4dd4, ax);
  ax = memoryAGet16(ds, bx + 19858);
  memoryASet16(ds, 0x4dca, ax);
  ax = memoryAGet16(ds, bx + 19906);
  memoryASet16(ds, 0x4dc8, ax);
  push(cx);
  sub_1c3cb();
  cx = pop();
  if (--cx)
    goto loc_1c37d;
}
void sub_1c3cb()
{
  cx = 0x0008;
  memoryASet(ds, 0x4d91, 0x01);
loc_1c3d3:
  push(cx);
  sub_1cd93();
  cx = pop();
  bx = cx;
  bx--;
  bx <<= 1;
  ax = memoryAGet16(ds, 0x4dcc);
  memoryASet16(ds, bx + 19786, ax);
  ax = memoryAGet16(ds, 0x4dce);
  memoryASet16(ds, bx + 19802, ax);
  if (--cx)
    goto loc_1c3d3;
  ax = 0xb800;
  es = ax;
  memoryASet(ds, 0x4d6e, 0x00);
loc_1c3f7:
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x4a80, dx);
  cx = 0x0008;
loc_1c402:
  push(cx);
  sub_1cd93();
  cx = pop();
  bx = cx;
  bx--;
  bx <<= 1;
  push(cx);
  push(bx);
  if (memoryAGet(ds, 0x4d91) == 0x00)
    goto loc_1c41a;
  if (cx != 0x0008)
    goto loc_1c435;
loc_1c41a:
  cx = memoryAGet16(ds, bx + 19786);
  dx = memoryAGet16(ds, bx + 19802);
  sub_19ee0();
  di = ax;
  si = memoryAGet16(ds, 0x4dca);
  bp = 0x000e;
  cx = memoryAGet16(ds, 0x4dd4);
  sub_19efc();
loc_1c435:
  bx = pop();
  cx = pop();
  sub_1c45a();
  if (--cx)
    goto loc_1c402;
loc_1c43c:
  sub_1cd93();
  ah = 0;
  interrupt(0x1a);
  dx -= memoryAGet16(ds, 0x4a80);
  if (dx < memoryAGet16(ds, 0x4dc8))
    goto loc_1c43c;
  memoryASet(ds, 0x4d91, 0x00);
  if (memoryAGet(ds, 0x4d6e) == 0x00)
    goto loc_1c3f7;
}
void sub_1c45a()
{
  ax = memoryAGet16(ds, bx + 19786);
  if (memoryAGet16(ds, bx + 19823) < 0x0001)
    goto loc_1c48a;
  if (memoryAGet16(ds, bx + 19823) != 0x0001)
    goto loc_1c47a;
  ax += memoryAGet16(ds, 0x4d6a);
  if (ax <= memoryAGet16(ds, 0x4dd0))
    goto loc_1c486;
  ax = memoryAGet16(ds, 0x4dd0);
  memoryASet(ds, 0x4d6e, memoryAGet(ds, 0x4d6e) + 1);
  goto loc_1c486;
loc_1c47a:
  flags.carry = ax < memoryAGet16(ds, 0x4d6a);
  ax -= memoryAGet16(ds, 0x4d6a);
  if (!flags.carry)
    goto loc_1c486;
  ax = 0;
  memoryASet(ds, 0x4d6e, memoryAGet(ds, 0x4d6e) + 1);
loc_1c486:
  memoryASet16(ds, bx + 19786, ax);
loc_1c48a:
  ax = memoryAGet16(ds, bx + 19802);
  if (memoryAGet16(ds, bx + 19839) < 0x0001)
    return;
  if (memoryAGet16(ds, bx + 19839) != 0x0001)
    goto loc_1c4aa;
  ax += memoryAGet16(ds, 0x4d6c);
  if (ax <= memoryAGet16(ds, 0x4dd2))
    goto loc_1c4b6;
  ax = memoryAGet16(ds, 0x4dd2);
  memoryASet(ds, 0x4d6e, memoryAGet(ds, 0x4d6e) + 1);
  goto loc_1c4b6;
loc_1c4aa:
  flags.carry = ax < memoryAGet16(ds, 0x4d6c);
  ax -= memoryAGet16(ds, 0x4d6c);
  if (!flags.carry)
    goto loc_1c4b6;
  ax = 0;
  memoryASet(ds, 0x4d6e, memoryAGet(ds, 0x4d6e) + 1);
loc_1c4b6:
  memoryASet16(ds, bx + 19802, ax);
}
void sub_1c4bb()
{
  sub_1cd84();
  if (memoryAGet(ds, 0x0697) == 0xfd)
    goto loc_1c4cc;
  ah = 0x0b;
  bx = 0x0101;
  interrupt(0x10);
loc_1c4cc:
  sub_1c290();
  sub_1c37a();
  sub_1cdef();
  if (memoryAGet(ds, 0x1f80) >= 0x09)
    goto loc_1c4e0;
  memoryASet(ds, 0x1f80, memoryAGet(ds, 0x1f80) + 1);
loc_1c4e0:
  if (memoryAGet16(ds, 0x0008) >= 0x0007)
    goto loc_1c4eb;
  memoryASet16(ds, 0x0008, memoryAGet16(ds, 0x0008) + 1);
loc_1c4eb:
  memoryASet16(ds, 0x0414, 0x0000);
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x0412, dx);
  sub_1cd51();
}
void sub_1c500()
{
  if (memoryAGet(ds, 0x0000) == 0x00)
    return;
  ah = 0;
  interrupt(0x1a);
  if (dx == memoryAGet16(ds, 0x52c4))
    return;
  memoryASet16(ds, 0x52c4, dx);
  bx = memoryAGet16(ds, 0x52c6);
  memoryASet16(ds, 0x52c6, memoryAGet16(ds, 0x52c6) + 0x0002);
  ax = memoryAGet16(ds, bx + 21194);
  if (ax != memoryAGet16(ds, 0x52c8))
    goto loc_1c52c;
  sub_1cd51();
  return;
loc_1c52c:
  memoryASet16(ds, 0x52c8, ax);
  al = 0xb6;
  out(0x0043, al);
  ax = memoryAGet16(ds, 0x52c8);
  out(0x0042, al);
  al = ah;
  out(0x0042, al);
  in(al, 0x61);
  al |= 0x03;
  out(0x0061, al);
}
void sub_1c543()
{
  if (memoryAGet16(ds, 0x0008) < 0x0002)
    return;
  memoryASet16(ds, 0x5016, 0x0000);
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x52c0, dx);
  memoryASet16(ds, 0x52c2, dx);
  memoryASet16(ds, 0x52c4, dx);
  memoryASet16(ds, 0x52c6, 0x0000);
  memoryASet16(ds, 0x52c8, 0x0000);
loc_1c56c:
  sub_1c598();
  memoryASet16(ds, 0x5016, memoryAGet16(ds, 0x5016) ^ 0x0002);
loc_1c575:
  sub_1c500();
  ah = 0;
  interrupt(0x1a);
  ax = dx;
  ax -= memoryAGet16(ds, 0x52c0);
  if (ax < 0x0005)
    goto loc_1c575;
  memoryASet16(ds, 0x52c0, dx);
  dx -= memoryAGet16(ds, 0x52c2);
  if (dx < 0x0028)
    goto loc_1c56c;
  sub_1cd51();
}
void sub_1c598()
{
  ax = 0xb800;
  es = ax;
  bx = memoryAGet16(ds, 0x0008);
  bx <<= 1;
  ax = memoryAGet16(ds, bx + 21166);
  memoryASet16(ds, 0x5010, ax);
loc_1c5aa:
  bx = memoryAGet16(ds, 0x5010);
  di = memoryAGet16(ds, bx);
  if (di != 0x0000)
    goto loc_1c5b6;
  return;
loc_1c5b6:
  bx = memoryAGet16(ds, bx + 2);
  bx ^= memoryAGet16(ds, 0x5016);
  bx &= 0x0002;
  si = memoryAGet16(ds, bx + 20498);
  cx = 0x2304;
  sub_19fcd();
  sub_1c500();
  memoryASet16(ds, 0x5010, memoryAGet16(ds, 0x5010) + 0x0004);
  goto loc_1c5aa;
}
void sub_1c5e0()
{
  if (memoryAGet(ds, 0x0000) == 0x00)
    return;
  ah = 0;
  interrupt(0x1a);
  if (dx == memoryAGet16(ds, 0x5322))
    return;
  memoryASet16(ds, 0x5322, dx);
  bx = memoryAGet16(ds, 0x5320);
  bl = memoryAGet(ds, bx + 21388);
  if (bl == 0x66)
    goto loc_1c60d;
  bh = 0;
  memoryASet16(ds, 0x5320, memoryAGet16(ds, 0x5320) + 1);
  if (bx != 0x0000)
    goto loc_1c611;
loc_1c60d:
  sub_1cd51();
  return;
loc_1c611:
  al = 0xb6;
  out(0x0043, al);
  ax = memoryAGet16(ds, bx + 21284);
  out(0x0042, al);
  al = ah;
  out(0x0042, al);
  in(al, 0x61);
  al |= 0x03;
  out(0x0061, al);
}
void sub_1c630()
{
  ax = 0xb800;
  es = ax;
  bx = memoryAGet16(ds, 0x0008);
  bx &= 0x0007;
  bx <<= 1;
  ax = bx;
  bx = memoryAGet16(ds, bx + 22792);
  cl = 0x03;
  ax <<= cl;
  memoryASet16(ds, 0x5918, ax);
loc_1c64c:
  di = memoryAGet16(ds, bx);
  if (di == 0xffff)
    return;
  sub_1a02d();
  dx &= 0x000e;
  dx += memoryAGet16(ds, 0x5918);
  si = dx;
  si = memoryAGet16(ds, si + 22664);
  cx = memoryAGet16(ds, si + 22616);
  si = memoryAGet16(ds, si + 22604);
  push(bx);
  sub_19fcd();
  bx = pop();
  bx += 0x0002;
  goto loc_1c64c;
}
void sub_1c680()
{
  memoryASet(ds, 0x5b0f, 0x0c);
  memoryASet16(ds, 0x5b0c, 0x0001);
  memoryASet16(ds, 0x5b12, 0x01ff);
  memoryASet16(ds, 0x5b0a, 0x000f);
  memoryASet(ds, 0x5b0e, 0x01);
}
void sub_1c69d()
{
  if (memoryAGet(ds, 0x0000) == 0x00)
    goto loc_1c6d5;
  if (memoryAGet(ds, 0x1cb8) == 0x00)
    goto loc_1c728;
  ah = 0;
  interrupt(0x1a);
  if (memoryAGet(ds, 0x5b0f) != 0x00)
    goto loc_1c6d6;
  if (dx == memoryAGet16(ds, 0x5b10))
    goto loc_1c6d5;
  memoryASet16(ds, 0x5b10, dx);
  al = 0xb6;
  out(0x0043, al);
  ax = memoryAGet16(ds, 0x5b12);
  ax &= 0x01ff;
  ax += 0x00c8;
  sub_1cab9();
  memoryASet16(ds, 0x5b12, memoryAGet16(ds, 0x5b12) - 0x004b);
loc_1c6d5:
  return;
loc_1c6d6:
  if (dx == memoryAGet16(ds, 0x5b10))
    goto loc_1c6e4;
  memoryASet16(ds, 0x5b10, dx);
  memoryASet(ds, 0x5b0f, memoryAGet(ds, 0x5b0f) - 1);
loc_1c6e4:
  memoryASet(ds, 0x5b0e, memoryAGet(ds, 0x5b0e) - 1);
  if (memoryAGet(ds, 0x5b0e) != 0)
    goto loc_1c727;
  al = 0x01;
  if (memoryAGet(ds, 0x0697) == 0xfd)
    goto loc_1c6f5;
  al <<= 1;
loc_1c6f5:
  memoryASet(ds, 0x5b0e, al);
  sub_1a02d();
  if (dl > 0x04)
    goto loc_1c704;
  memoryASet16(ds, 0x5b0c, memoryAGet16(ds, 0x5b0c) + 1);
loc_1c704:
  if (!(memoryAGet16(ds, 0x5b0c) & 0x0001))
    goto loc_1c711;
  memoryASet16(ds, 0x5b0a, memoryAGet16(ds, 0x5b0a) + 0x0007);
loc_1c711:
  al = 0xb6;
  out(0x0043, al);
  sub_1a02d();
  ax = dx;
  ax &= memoryAGet16(ds, 0x5b0a);
  ax &= 0x01ff;
  ax += 0x0190;
  sub_1cab9();
loc_1c727:
  return;
loc_1c728:
  ah = 0;
  interrupt(0x1a);
  if (memoryAGet(ds, 0x5920) == 0x00)
    goto loc_1c752;
  if (dx == memoryAGet16(ds, 0x5921))
    goto loc_1c792;
  memoryASet16(ds, 0x5921, dx);
  memoryASet(ds, 0x5920, memoryAGet(ds, 0x5920) - 1);
  if (memoryAGet(ds, 0x5920) == 0)
    goto loc_1c74e;
  al = 0xb6;
  out(0x0043, al);
  ax = memoryAGet16(ds, 0x5923);
  sub_1cab9();
  return;
loc_1c74e:
  sub_1cd51();
  return;
loc_1c752:
  if (dx == memoryAGet16(ds, 0x5925))
    goto loc_1c792;
  si = 0x0003;
  al = memoryAGet(ds, 0x1cbf);
  al |= memoryAGet(ds, 0x5b07);
  if (al)
    goto loc_1c779;
  si = 0x0001;
  if (memoryAGet16(ds, 0x0004) != 0x0000)
    goto loc_1c779;
  si--;
  if (memoryAGet(ds, 0x1673) == 0x00)
    goto loc_1c779;
  si = 0x0002;
loc_1c779:
  di = si;
  di <<= 1;
  al = memoryAGet(ds, 0x0584);
  al |= memoryAGet(ds, 0x5b07);
  if (al)
    goto loc_1c793;
  ax = dx;
  ax -= memoryAGet16(ds, 0x5925);
  if (ax >= memoryAGet16(ds, di + 23026))
    goto loc_1c793;
loc_1c792:
  return;
loc_1c793:
  memoryASet16(ds, 0x5925, dx);
  if (memoryAGet(ds, 0x1cbf) != 0x00)
    goto loc_1c7a9;
  if (memoryAGet(ds, 0x5b07) == 0x00)
    goto loc_1c7ce;
  memoryASet(ds, 0x5b07, memoryAGet(ds, 0x5b07) - 1);
loc_1c7a9:
  memoryASet16(ds, 0x592e, 0x1200);
  bx = memoryAGet16(ds, 0x59ba);
  if (bx < 0x0006)
    goto loc_1c7be;
  bx = 0;
  memoryASet16(ds, 0x59ba, bx);
loc_1c7be:
  memoryASet16(ds, 0x59ba, memoryAGet16(ds, 0x59ba) + 0x0002);
  ax = memoryAGet16(ds, bx + 23108);
  memoryASet16(ds, 0x592a, ax);
  sub_1cd58();
  return;
loc_1c7ce:
  if (si != 0x0002)
    goto loc_1c7eb;
  al = memoryAGet(ds, 0x1673);
  ah = 0;
  cl = 0x04;
  ax <<= cl;
  ax += 0x0200;
  memoryASet16(ds, 0x592a, ax);
  memoryASet16(ds, 0x592e, 0x1800);
  goto loc_1c8bd;
loc_1c7eb:
  ax = memoryAGet16(ds, di + 23042);
  memoryASet16(ds, 0x592e, ax);
  flags.carry = memoryAGet(ds, 0x5927) & 1;
  memoryASet(ds, 0x5927, memoryAGet(ds, 0x5927) >> 1);
  if (!flags.carry)
    goto loc_1c853;
  memoryASet16(ds, 0x592e, 0x1000);
  memoryASet(ds, 0x5927, 0x80);
  memoryASet(ds, 0x5928, memoryAGet(ds, 0x5928) + 1);
  al = memoryAGet(ds, 0x5928);
  al &= memoryAGet(ds, si + 23034);
  if (al != 0)
    goto loc_1c846;
  dl = memoryAGet(ds, si + 23050);
  memoryASet(ds, 0x5929, memoryAGet(ds, 0x5929) + dl);
  sub_1a02d();
  if (dl > memoryAGet(ds, si + 23052))
    goto loc_1c828;
  dl &= 0x07;
  memoryASet(ds, 0x592d, dl);
loc_1c828:
  sub_1a02d();
  dx &= 0x00ff;
  dx <<= 1;
  cl = 0x01;
  if (!(dl & 0x02))
    goto loc_1c83e;
  cl = 0xff;
  dx += 0x0300;
loc_1c83e:
  memoryASet16(ds, 0x592a, dx);
  memoryASet(ds, 0x592c, cl);
loc_1c846:
  ah = memoryAGet(ds, 0x5929);
  ah &= memoryAGet(ds, si + 23036);
  al |= ah;
  memoryASet(ds, 0x5928, al);
loc_1c853:
  if (memoryAGet(ds, 0x592c) == 0xff)
    goto loc_1c870;
  memoryASet16(ds, 0x5a54, memoryAGet16(ds, 0x5a54) + 0x0002);
  bx = memoryAGet16(ds, 0x5a54);
  bx &= 0x000e;
  ax = memoryAGet16(ds, bx + 23108);
  memoryASet16(ds, 0x592a, ax);
  goto loc_1c883;
loc_1c870:
  if (memoryAGet16(ds, 0x592a) > 0x00c8)
    goto loc_1c87e;
  memoryASet16(ds, 0x592a, 0x0500);
loc_1c87e:
  memoryASet16(ds, 0x592a, memoryAGet16(ds, 0x592a) - 0x0019);
loc_1c883:
  if (memoryAGet(ds, 0x0584) == 0x00)
    goto loc_1c897;
  memoryASet16(ds, 0x592e, 0x2000);
  memoryASet(ds, 0x592c, 0xff);
  if (memoryAGet(ds, 0x0584) != 0x00)
    goto loc_1c8bd;
loc_1c897:
  bl = memoryAGet(ds, 0x5928);
  bh = 0;
  bx += memoryAGet16(ds, di + 23038);
  al = memoryAGet(ds, bx + 22978);
  al &= memoryAGet(ds, 0x5927);
  if (al != 0)
    goto loc_1c8bd;
  if (memoryAGet(ds, 0x592d) == 0x00)
    return;
  memoryASet(ds, 0x592d, memoryAGet(ds, 0x592d) - 1);
  ax = memoryAGet16(ds, di + 23046);
  memoryASet16(ds, 0x592e, ax);
loc_1c8bd:
  sub_1cd58();
}
void sub_1c8c1()
{
  sub_1cd51();
  ah = 0x0b;
  bx = 0x0004;
  interrupt(0x10);
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x5ae2, dx);
  memoryASet16(ds, 0x5ae4, 0x0000);
  al = 0x02;
  if (memoryAGet(ds, 0x0697) != 0xfd)
    goto loc_1c8e4;
  al >>= 1;
loc_1c8e4:
  memoryASet(ds, 0x5b06, al);
loc_1c8e7:
  if (memoryAGet(ds, 0x0000) == 0x00)
    goto loc_1c908;
  memoryASet16(ds, 0x5ae4, memoryAGet16(ds, 0x5ae4) + 1);
  bx = memoryAGet16(ds, 0x5ae4);
  cl = memoryAGet(ds, 0x5b06);
  bx >>= cl;
  bx &= 0x001f;
  in(al, 0x61);
  al ^= memoryAGet(ds, bx + 23270);
  out(0x0061, al);
loc_1c908:
  ah = 0;
  interrupt(0x1a);
  dx -= memoryAGet16(ds, 0x5ae2);
  if (dx < 0x0002)
    goto loc_1c8e7;
  ah = 0x0b;
  bx = 0;
  interrupt(0x10);
  memoryASet(ds, 0x5b07, 0x0c);
  sub_1cd51();
}
void sub_1c924()
{
  ax = 0x0200;
  if (memoryAGet(ds, 0x0697) != 0xfd)
    goto loc_1c930;
  ax <<= 1;
loc_1c930:
  memoryASet16(ds, 0x5ad0, ax);
}
void sub_1c934()
{
  memoryASet16(ds, 0x5ad0, memoryAGet16(ds, 0x5ad0) + 1);
  bx = memoryAGet16(ds, 0x5ad0);
  dx = bx;
  cl = 0x09;
  dx >>= cl;
  cl = dl;
  cl &= 0x0f;
  bx >>= cl;
  bx &= 0x000f;
  dl = memoryAGet(ds, bx + 23250);
  dl &= memoryAGet(ds, 0x0000);
  in(al, 0x61);
  al &= 0xfc;
  al |= dl;
  out(0x0061, al);
}
void sub_1c95e()
{
  memoryASet16(ds, 0x5acb, 0x01f4);
loc_1c964:
  sub_1c99e();
  memoryASet16(ds, 0x5acb, memoryAGet16(ds, 0x5acb) - 0x001e);
  if (memoryAGet16(ds, 0x5acb) > 0x00c8)
    goto loc_1c964;
  memoryASet16(ds, 0x5acb, 0x01f4);
loc_1c97a:
  sub_1c99e();
  memoryASet16(ds, 0x5acb, memoryAGet16(ds, 0x5acb) - 0x0014);
  if (memoryAGet16(ds, 0x5acb) > 0x012c)
    goto loc_1c97a;
loc_1c98a:
  sub_1c99e();
  memoryASet16(ds, 0x5acb, memoryAGet16(ds, 0x5acb) + 0x001e);
  if (memoryAGet16(ds, 0x5acb) < 0x0320)
    goto loc_1c98a;
  sub_1cd51();
}
void sub_1c99e()
{
  cx = 0x1000;
  if (memoryAGet(ds, 0x0697) != 0xfd)
    goto loc_1c9aa;
  cx >>= 1;
loc_1c9aa:
  if (--cx)
    goto loc_1c9aa;
  if (memoryAGet(ds, 0x0000) == 0x00)
    return;
  al = 0xb6;
  out(0x0043, al);
  ax = memoryAGet16(ds, 0x5acb);
  out(0x0042, al);
  al = ah;
  out(0x0042, al);
  in(al, 0x61);
  al |= 0x03;
  out(0x0061, al);
}
void sub_1c9c7()
{
  sub_1cd51();
  memoryASet(ds, 0x5acf, 0x00);
  memoryASet16(ds, 0x5acd, 0x0008);
}
void sub_1c9d6()
{
  memoryASet(ds, 0x5acf, memoryAGet(ds, 0x5acf) + 1);
  dl = 0;
  al = memoryAGet(ds, 0x5acf);
  al &= 0x3f;
  if (al != 0)
    goto loc_1c9e7;
  memoryASet16(ds, 0x5acd, memoryAGet16(ds, 0x5acd) + 1);
loc_1c9e7:
  bx = memoryAGet16(ds, 0x5acd);
  cl = 0x02;
  bx >>= cl;
  bl &= 0x1f;
  if (al < bl)
    goto loc_1c9f8;
  dl = 0x02;
loc_1c9f8:
  dl &= memoryAGet(ds, 0x0000);
  in(al, 0x61);
  al &= 0xfd;
  al |= dl;
  out(0x0061, al);
}
void sub_1ca05()
{
  memoryASet16(ds, 0x5a85, 0x0000);
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x5a83, dx);
}
void sub_1ca14()
{
  if (memoryAGet(ds, 0x0000) == 0x00)
    return;
  ah = 0;
  interrupt(0x1a);
  ax = dx;
  ax -= memoryAGet16(ds, 0x5a83);
  if (ax < 0x0002)
    return;
  memoryASet16(ds, 0x5a83, dx);
  bx = memoryAGet16(ds, 0x5a85);
  memoryASet16(ds, 0x5a85, memoryAGet16(ds, 0x5a85) + 0x0002);
  if (memoryAGet(ds, 0x0552) == 0x00)
    goto loc_1ca4b;
  ax = memoryAGet16(ds, bx + 23203);
  if (ax != 0x0000)
    goto loc_1ca4f;
  sub_1cd51();
  return;
loc_1ca4b:
  ax = memoryAGet16(ds, bx + 23175);
loc_1ca4f:
  push(ax);
  al = 0xb6;
  out(0x0043, al);
  ax = pop();
  sub_1cab9();
}
void sub_1ca59()
{
  memoryASet16(ds, 0x5a62, 0x0000);
  memoryASet(ds, 0x5a82, 0x00);
}
void sub_1ca65()
{
  if (memoryAGet(ds, 0x0000) == 0x00)
    goto loc_1ca76;
  ah = 0;
  interrupt(0x1a);
  if (dx != memoryAGet16(ds, 0x5a80))
    goto loc_1ca77;
loc_1ca76:
  return;
loc_1ca77:
  memoryASet16(ds, 0x5a80, dx);
  memoryASet(ds, 0x5a82, memoryAGet(ds, 0x5a82) + 1);
  al = 0xb6;
  out(0x0043, al);
  bx = memoryAGet16(ds, 0x5a62);
  if (memoryAGet(ds, 0x5a82) & 0x01)
    goto loc_1ca91;
  bx += 0x0002;
loc_1ca91:
  ax = memoryAGet16(ds, bx + 23140);
  sub_1cab9();
}
void sub_1ca99()
{
  if (memoryAGet(ds, 0x0000) == 0x00)
    return;
  push(bx);
  push(ax);
  al = 0xb6;
  out(0x0043, al);
  bx = memoryAGet16(ds, 0x5a62);
  memoryASet16(ds, 0x5a62, memoryAGet16(ds, 0x5a62) + 0x0002);
  ax = memoryAGet16(ds, bx + 23140);
  sub_1cab9();
  ax = pop();
  bx = pop();
}
void sub_1cab9()
{
  out(0x0042, al);
  al = ah;
  out(0x0042, al);
  in(al, 0x61);
  al |= 0x03;
  out(0x0061, al);
}
void sub_1cac6()
{
}
void sub_1cac7()
{
  if (memoryAGet(ds, 0x0000) == 0x00)
    return;
  push(ax);
  push(cx);
  push(dx);
  al = 0xb6;
  out(0x0043, al);
  bx = memoryAGet16(ds, 0x5a56);
  bx &= 0x0006;
  memoryASet16(ds, 0x5a56, memoryAGet16(ds, 0x5a56) + 0x0002);
  ax = memoryAGet16(ds, bx + 23130);
  sub_1cab9();
  dx = pop();
  cx = pop();
  ax = pop();
}
void sub_1caed()
{
  memoryASet(ds, 0x5927, 0x80);
  memoryASet(ds, 0x5928, 0x00);
  memoryASet(ds, 0x5929, 0x00);
  memoryASet16(ds, 0x592a, 0x0500);
  memoryASet(ds, 0x592c, 0xff);
  memoryASet(ds, 0x592d, 0x00);
  memoryASet(ds, 0x5920, 0x00);
  memoryASet(ds, 0x5b07, 0x00);
  memoryASet16(ds, 0x5b08, 0x0000);
  memoryASet16(ds, 0x5b0c, 0x0001);
  memoryASet(ds, 0x5b0e, 0x01);
}
void sub_1cb28()
{
  if (memoryAGet(ds, 0x1cbf) != 0x00)
    goto loc_1cb38;
  bx = 0x0390;
  cx = 0x1800;
  sub_1cbd3();
loc_1cb38:
  memoryASet(ds, 0x127c, 0x00);
}
void sub_1cb3e()
{
  if (memoryAGet(ds, 0x1cbf) != 0x00)
    return;
  bx = 0x0400;
  cx = 0x1800;
  sub_1cbd3();
}
void sub_1cb4f()
{
  bx = 0x07d0;
  cx = 0x1800;
  sub_1cbd3();
  bx = 0x0a6e;
  cx = 0x1800;
  sub_1cbd3();
  bx = 0x0dec;
  cx = 0x1800;
  sub_1cbd3();
}
void sub_1cb6b()
{
  if (memoryAGet(ds, 0x0000) == 0x00)
    return;
  memoryASet16(ds, 0x5923, bx);
  push(ax);
  al = 0xb6;
  out(0x0043, al);
  ax = pop();
  sub_1cab9();
  memoryASet(ds, 0x5920, 0x02);
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x5921, dx);
}
void sub_1cb8d()
{
  if (memoryAGet(ds, 0x0000) == 0x00)
    return;
  if (memoryAGet(ds, 0x5920) != 0x00)
    return;
  sub_1a02d();
  ax = dx;
  ax &= 0x007f;
  ax += 0x00aa;
  bx = ax;
  ax += 0x001e;
  sub_1cb6b();
}
void sub_1cbaf()
{
  if (memoryAGet(ds, 0x0000) == 0x00)
    return;
  ax = 0x1200;
  bx = 0x1312;
  ax += memoryAGet16(ds, 0x5b08);
  bx += memoryAGet16(ds, 0x5b08);
  memoryASet16(ds, 0x5b08, memoryAGet16(ds, 0x5b08) + 0x015e);
  sub_1cb6b();
  memoryASet(ds, 0x5b07, 0x18);
}
void sub_1cbd3()
{
  if (memoryAGet(ds, 0x0000) == 0x00)
    return;
  al = 0xb6;
  out(0x0043, al);
  ax = bx;
  out(0x0042, al);
  al = ah;
  out(0x0042, al);
  in(al, 0x61);
  al |= 0x03;
  out(0x0061, al);
  if (memoryAGet(ds, 0x0697) != 0xfd)
    goto loc_1cbf5;
  cx >>= 1;
loc_1cbf5:
  if (--cx)
    goto loc_1cbf5;
  sub_1cd51();
}
void sub_1cbfb()
{
  in(al, 0x61);
  al &= 0xfe;
  out(0x0061, al);
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x5a40, dx);
  memoryASet16(ds, 0x5a42, 0x0000);
loc_1cc0f:
  ax = memoryAGet16(ds, 0x5a42);
  cl = 0x06;
  ax >>= cl;
  if (ax != 0)
    goto loc_1cc19;
  ax++;
loc_1cc19:
  cx = ax;
loc_1cc1b:
  push(cx);
  ah = 0;
  interrupt(0x1a);
  cx = pop();
  dx -= memoryAGet16(ds, 0x5a40);
  if (dx < 0x0002)
    goto loc_1cc1b;
  if (dx >= 0x0007)
    goto loc_1cc48;
  if (--cx)
    goto loc_1cc1b;
  sub_1a02d();
  dl &= 0x02;
  dl &= memoryAGet(ds, 0x0000);
  in(al, 0x61);
  al ^= dl;
  out(0x0061, al);
  memoryASet16(ds, 0x5a42, memoryAGet16(ds, 0x5a42) + 0x0007);
  goto loc_1cc0f;
loc_1cc48:
  sub_1cd51();
}
void sub_1cc4c()
{
  if (memoryAGet(ds, 0x0000) == 0x00)
    goto loc_1cc64;
  sub_185e7();
  bx = memoryAGet16(ds, 0x5a16);
  flags.carry = bx < ax;
  bx -= ax;
  if (flags.carry)
    goto loc_1cc65;
  if (bx > 0x0260)
    goto loc_1cc65;
loc_1cc64:
  return;
loc_1cc65:
  memoryASet16(ds, 0x5a16, ax);
  al = 0xb6;
  out(0x0043, al);
  memoryASet16(ds, 0x5a18, memoryAGet16(ds, 0x5a18) + 1);
  bx = memoryAGet16(ds, 0x5a18);
  bx &= 0x001e;
  ax = memoryAGet16(ds, 0x5a3c);
  ax &= 0x03ff;
  if (ax < 0x0180)
    goto loc_1cc89;
  cx = 0x0180;
  cx -= ax;
  tx = ax;
  ax = cx;
  cx = tx;
loc_1cc89:
  ax >>= 1;
  ax >>= 1;
  ax += memoryAGet16(ds, bx + 23066);
  bx = 0x0001;
  if (memoryAGet(ds, 0x0697) != 0xfd)
    goto loc_1cc9d;
  bl <<= 1;
loc_1cc9d:
  memoryASet16(ds, 0x5a3e, memoryAGet16(ds, 0x5a3e) + bx);
  bx <<= 1;
  bx <<= 1;
  memoryASet16(ds, 0x5a3c, memoryAGet16(ds, 0x5a3c) + bx);
  dx = memoryAGet16(ds, 0x5a3e);
  cl = 0x03;
  dx >>= cl;
  ax += dx;
  out(0x0042, al);
  al = ah;
  out(0x0042, al);
  in(al, 0x61);
  al |= 0x03;
  out(0x0061, al);
}
void sub_1ccc0()
{
  if (memoryAGet(ds, 0x0000) == 0x00)
    goto loc_1ccd1;
  ah = 0;
  interrupt(0x1a);
  if (dx != memoryAGet16(ds, 0x5a14))
    goto loc_1ccd2;
loc_1ccd1:
  return;
loc_1ccd2:
  memoryASet16(ds, 0x5a14, dx);
  al = 0xb6;
  out(0x0043, al);
  sub_1a02d();
  ax = dx;
  ax &= 0x0070;
  ax += 0x0200;
  out(0x0042, al);
  al = ah;
  out(0x0042, al);
  in(al, 0x61);
  al |= 0x03;
  out(0x0061, al);
}
void sub_1ccf2()
{
  memoryASet16(ds, 0x5a12, 0x0338);
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x5a10, dx);
  sub_185e7();
  memoryASet16(ds, 0x5a0e, ax);
loc_1cd06:
  sub_185e7();
  dx = ax;
  ax -= memoryAGet16(ds, 0x5a0e);
  if (ax < 0x9c40)
    goto loc_1cd40;
  memoryASet16(ds, 0x5a0e, dx);
  if (memoryAGet(ds, 0x0000) == 0x00)
    goto loc_1cd40;
  al = 0xb6;
  out(0x0043, al);
  sub_1a02d();
  ax = dx;
  ax &= 0x07ff;
  ax += memoryAGet16(ds, 0x5a12);
  memoryASet16(ds, 0x5a12, memoryAGet16(ds, 0x5a12) - 0x0002);
  out(0x0042, al);
  al = ah;
  out(0x0042, al);
  in(al, 0x61);
  al |= 0x03;
  out(0x0061, al);
loc_1cd40:
  ah = 0;
  interrupt(0x1a);
  dx -= memoryAGet16(ds, 0x5a10);
  if (dx < 0x0002)
    goto loc_1cd06;
  sub_1cd51();
}
void sub_1cd51()
{
  in(al, 0x61);
  al &= 0xfc;
  out(0x0061, al);
}
void sub_1cd58()
{
  al = 0xb6;
  out(0x0043, al);
  ax = memoryAGet16(ds, 0x592a);
  out(0x0042, al);
  al = ah;
  out(0x0042, al);
  in(al, 0x61);
  al |= 0x03;
  out(0x0061, al);
  sub_185e7();
  cx = ax;
loc_1cd70:
  sub_185e7();
  dx = cx;
  dx -= ax;
  if (dx < memoryAGet16(ds, 0x592e))
    goto loc_1cd70;
  in(al, 0x61);
  al &= 0xfc;
  out(0x0061, al);
}
void sub_1cd84()
{
  memoryASet16(ds, 0x59be, 0x0000);
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x59c0, dx);
}
void sub_1cd93()
{
  if (memoryAGet(ds, 0x0000) == 0x00)
    goto loc_1cda9;
  ah = 0;
  interrupt(0x1a);
  ax = dx;
  ax -= memoryAGet16(ds, 0x59c0);
  if (ax >= 0x0002)
    goto loc_1cdaa;
loc_1cda9:
  return;
loc_1cdaa:
  memoryASet16(ds, 0x59c0, dx);
  bx = memoryAGet16(ds, 0x59be);
  bx &= 0x00fe;
  if (bx < 0x0086)
    goto loc_1cdc2;
  bx = 0;
  memoryASet16(ds, 0x59be, bx);
loc_1cdc2:
  memoryASet16(ds, 0x59be, memoryAGet16(ds, 0x59be) + 0x0002);
  ax = memoryAGet16(ds, bx + 22836);
  cx = memoryAGet16(ds, 0x59bc);
  memoryASet16(ds, 0x59bc, ax);
  if (ax != cx)
    goto loc_1cdda;
  sub_1cd51();
  return;
loc_1cdda:
  cx = ax;
  al = 0xb6;
  out(0x0043, al);
  ax = cx;
  out(0x0042, al);
  al = ah;
  out(0x0042, al);
  in(al, 0x61);
  al |= 0x03;
  out(0x0061, al);
}
void sub_1cdef()
{
loc_1cdef:
  if (memoryAGet(ds, 0x0000) == 0x00)
    return;
  sub_1cd93();
  if (memoryAGet16(ds, 0x59be) < 0x007c)
    goto loc_1cdef;
}
void sub_1ce10()
{
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x5f66, dx);
  memoryASet16(ds, 0x5f60, 0x0000);
loc_1ce1e:
  ax = 0xb800;
  es = ax;
  bx = memoryAGet16(ds, 0x5f60);
  memoryASet16(ds, 0x5f60, memoryAGet16(ds, 0x5f60) + 0x0002);
  bx &= 0x0002;
  si = memoryAGet16(ds, bx + 24418);
  di = 0x0a74;
  cx = 0x4404;
  sub_19fcd();
loc_1ce3d:
  sub_1ca14();
  ah = 0;
  interrupt(0x1a);
  ax = dx;
  ax -= memoryAGet16(ds, 0x5f66);
  if (ax < 0x0004)
    goto loc_1ce3d;
  memoryASet16(ds, 0x5f66, dx);
  if (memoryAGet16(ds, 0x5f60) != 0x0004)
    goto loc_1ce66;
  si = 0x5f68;
  di = 0x0668;
  cx = 0x1004;
  sub_19fcd();
loc_1ce66:
  bx = memoryAGet16(ds, 0x5f60);
  flags.carry = bx < 0x0008;
  bx -= 0x0008;
  if (flags.carry)
    goto loc_1ce81;
  if (bx >= 0x0006)
    goto loc_1ce81;
  si = 0x5fe8;
  di = memoryAGet16(ds, bx + 24804);
  cx = 0x1506;
  sub_19fcd();
loc_1ce81:
  if (memoryAGet16(ds, 0x5f60) < 0x0010)
    goto loc_1ce1e;
  sub_1cd51();
}
void sub_1ce90()
{
//  interrupt(0x11);
//  al &= 0x30;
//  if (al != 0x30)
//    goto loc_1cec5;
  ax = 0xb800;
  ds = ax;
  ax = 0x55aa;
  memoryASet16(ds, 0x0000, ax);
  ax = memoryAGet16(ds, 0x0000);
  if (ax != 0x55aa)
    goto loc_1cec6;
  si = 0x60f0;
  sub_1cece();
  ax = 0x0040;
  ds = ax;
  ax = memoryAGet16(ds, 0x0010);
  al &= 0xcf;
  al |= 0x10;
  memoryASet16(ds, 0x0010, ax);
  ax = 0x0004;
  interrupt(0x10);
loc_1cec5:
  return;
loc_1cec6:
  si = 0x6112;
  sub_1cece();
loc_1cecc:
  goto loc_1cecc;
}
void sub_1cece()
{
  ax = 0x1010;
  ds = ax;
  sub_1d05b();
}
void sub_1cee0()
{
  flags.direction = false;
  memoryASet16(ds, 0x0004, 0x0000);
  sub_18a60();
  sub_19560();
  sub_19c60();
  ax = 0xb800;
  es = ax;
  si = 0x6152;
  cx = 0x1d0b;
  di = 0x00bd;
  sub_19fcd();
  si = 0x63d0;
  cx = 0x160e;
  di = 0x069e;
  sub_19fcd();
  si = 0x6638;
  cx = 0x0c03;
  di = 0x0a78;
  sub_19fcd();
  si = 0x6680;
  cx = 0x080e;
  di = 0x0ca8;
  sub_19fcd();
  si = 0x6760;
  cx = 0x0b0c;
  di = 0x1d6e;
  sub_19fcd();
  si = 0x6868;
  cx = 0x0804;
  di = 0x1dec;
  sub_19fcd();
  memoryASet16(ds, 0x6a8d, 0x0000);
  sub_1d06b();
  memoryASet16(ds, 0x0579, 0x0000);
  sub_1793d();
  memoryASet(ds, 0x057b, 0x60);
  memoryASet(ds, 0x057c, 0x92);
  sub_19922();
  sub_1992c();
  memoryASet(ds, 0x1f80, 0x09);
  memoryASet(ds, 0x1f81, 0xff);
  sub_198e3();
  sub_19070();
  memoryASet(ds, 0x0698, 0x00);
  memoryASet(ds, 0x0699, 0x00);
  memoryASet(ds, 0x6a8a, 0x00);
  ax = memoryAGet16(ds, 0x0693);
  memoryASet16(ds, 0x6150, ax);
loc_1cf84:
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x6a8b, dx);
  memoryASet16(ds, 0x5322, dx);
  memoryASet16(ds, 0x6a93, dx);
  dx -= 0x0030;
  memoryASet16(ds, 0x6a88, dx);
  memoryASet16(ds, 0x5320, 0x0000);
loc_1cfa1:
  ah = 0;
  interrupt(0x1a);
  ax = dx;
  ax -= memoryAGet16(ds, 0x6a93);
  if (ax < 0x0024)
    goto loc_1cfb9;
  memoryASet16(ds, 0x6a93, dx);
  push(dx);
  sub_1d06b();
  dx = pop();
loc_1cfb9:
  dx -= memoryAGet16(ds, 0x6a8b);
  ax = memoryAGet16(ds, 0x56da);
  if (memoryAGet(ds, 0x041a) == 0x00)
    goto loc_1cfd0;
  ax += 0x0048;
  if (dx >= ax)
    goto loc_1cf84;
  goto loc_1cfd7;
loc_1cfd0:
  ax += 0x0006;
  if (dx > ax)
    return;
loc_1cfd7:
  sub_1c5e0();
  sub_1d004();
  if (memoryAGet(ds, 0x069b) == 0x00)
    goto loc_1cffa;
  dx = 0x0201;
  in(al, dx);
  al &= 0x10;
  if (al == 0)
    goto loc_1cff3;
  memoryASet(ds, 0x6a8a, 0x01);
  goto loc_1cffa;
loc_1cff3:
  if (memoryAGet(ds, 0x6a8a) != 0x00)
    return;
loc_1cffa:
  ax = memoryAGet16(ds, 0x6150);
  if (ax == memoryAGet16(ds, 0x0693))
    goto loc_1cfa1;
}
void sub_1d004()
{
  if (memoryAGet16(ds, 0x0579) > 0x0020)
    goto loc_1d012;
  memoryASet(ds, 0x0698, 0x01);
  goto loc_1d04c;
loc_1d012:
  if (memoryAGet16(ds, 0x0579) < 0x0120)
    goto loc_1d021;
  memoryASet(ds, 0x0698, 0xff);
  goto loc_1d04c;
loc_1d021:
  ah = 0;
  interrupt(0x1a);
  ax = dx;
  ax -= memoryAGet16(ds, 0x6a88);
  if (ax < 0x0012)
    goto loc_1d04c;
  memoryASet16(ds, 0x6a88, dx);
  sub_1a02d();
  memoryASet(ds, 0x0698, 0x00);
  if (dl > 0xa0)
    goto loc_1d04c;
  dl &= 0x01;
  if (dl != 0)
    goto loc_1d048;
  dl = 0xff;
loc_1d048:
  memoryASet(ds, 0x0698, dl);
loc_1d04c:
  sub_18608();
  if (flags.zero)
    return;
  memoryASet16(ds, 0x0572, 0x0004);
  sub_17b15();
}
void sub_1d05b()
{
loc_1d05b:
  lodsb<MemAuto, DirAuto>();
  if (al == 0x00)
    return;
  push(si);
  bl = 0x02;
  ah = 0x0e;
  interrupt(0x10);
  si = pop();
  goto loc_1d05b;
}
void sub_1d06b()
{
  ax = 0xb800;
  es = ax;
  memoryASet16(ds, 0x6a8d, memoryAGet16(ds, 0x6a8d) + 0x0002);
  bx = memoryAGet16(ds, 0x6a8d);
  bx &= 0x0002;
  si = memoryAGet16(ds, bx + 27279);
  cx = 0x0c0a;
  di = 0x1d38;
  sub_19fcd();
}
void sub_1d08b()
{
  dl = 0x00;
  bh = dl;
  ah = 0x02;
  interrupt(0x10);
}
void sub_1d0a0()
{
  sub_1cd51();
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x6dfc, dx);
  memoryASet16(ds, 0x6dfe, cx);
  push(ds);
  push(ds);
  es = pop();
  ax = 0xb800;
  ds = ax;
  si = 0x0dca;
  di = 0x000e;
  cx = 0x1020;
  sub_19ffa();
  ds = pop();
  dx = 0x0b05;
  bh = 0x00;
  ah = 0x02;
  interrupt(0x10);
  si = 0x6d91;
  flags.direction = false;
  sub_1d05b();
  dx = 0x0c05;
  bh = 0x00;
  ah = 0x02;
  interrupt(0x10);
  si = 0x6db2;
  if (memoryAGet(ds, 0x069b) == 0x00)
    goto loc_1d0ea;
  si = 0x6dd3;
loc_1d0ea:
  flags.direction = false;
  sub_1d05b();
  sub_1d1c7();
  ax = 0xb800;
  es = ax;
  si = 0x000e;
  di = 0x0dca;
  cx = 0x1020;
  sub_19fcd();
  ah = 0x01;
  cx = memoryAGet16(ds, 0x6dfe);
  dx = memoryAGet16(ds, 0x6dfc);
  interrupt(0x1a);
  ax = memoryAGet16(ds, 0x0693);
  memoryASet16(ds, 0x6e00, ax);
}
void sub_1d115()
{
  sub_1cd51();
loc_1d118:
  sub_1d1fd();
  memoryASet16(ds, 0x6d8f, 0x0000);
  sub_1d1e1();
loc_1d124:
  ax = memoryAGet16(ds, 0x0693);
loc_1d127:
    sync();
  if (ax == memoryAGet16(ds, 0x0693))
    goto loc_1d127;
  if (!(memoryAGet(ds, 0x06c1) & 0x80))
    goto loc_1d142;
  if (memoryAGet(ds, 0x06c2) & 0x80)
    goto loc_1d124;
  memoryASet(ds, 0x069b, 0x00);
  goto loc_1d14c;
loc_1d142:
  sub_1d215();
  if (flags.carry)
    goto loc_1d118;
  memoryASet(ds, 0x069b, 0x01);
loc_1d14c:
  cx = 0x0005;
loc_1d14f:
  push(cx);
  sub_1d1e1();
  cx = pop();
  if (--cx)
    goto loc_1d14f;
loc_1d156:
  ax = memoryAGet16(ds, 0x0693);
loc_1d159:
    sync();
  if (ax == memoryAGet16(ds, 0x0693))
    goto loc_1d159;
  ax = 0;
  if (!(memoryAGet(ds, 0x06c3) & 0x80))
    goto loc_1d180;
  ax++;
  if (!(memoryAGet(ds, 0x06c4) & 0x80))
    goto loc_1d180;
  ax++;
  if (!(memoryAGet(ds, 0x06c5) & 0x80))
    goto loc_1d180;
  ax++;
  if (memoryAGet(ds, 0x06c6) & 0x80)
    goto loc_1d156;
loc_1d180:
  memoryASet16(ds, 0x6df8, ax);
  cx = 0x0005;
loc_1d186:
  push(cx);
  sub_1d1e1();
  cx = pop();
  if (--cx)
    goto loc_1d186;
  if (memoryAGet(ds, 0x069b) == 0x00)
    goto loc_1d1ae;
  memoryASet16(ds, 0x6d8f, 0x0020);
  sub_1d1e1();
  sub_1d1e1();
  memoryASet16(ds, 0x6d8f, 0x0018);
  sub_1d1e1();
  sub_1d1e1();
  goto loc_1d1c3;
loc_1d1ae:
  memoryASet16(ds, 0x6d8f, 0x001c);
  sub_1d1e1();
  sub_1d1e1();
  memoryASet16(ds, 0x6d8f, 0x0016);
  sub_1d1e1();
loc_1d1c3:
  sub_1d1c7();
}
void sub_1d1c7()
{
  if (memoryAGet(ds, 0x069b) == 0x00)
    goto loc_1d1d7;
loc_1d1ce:
  dx = 0x0201;
  in(al, dx);
  al &= 0x10;
  if (al != 0)
    goto loc_1d1ce;
  return;
loc_1d1d7:
  ax = memoryAGet16(ds, 0x0693);
loc_1d1da:
    sync();
  if (ax == memoryAGet16(ds, 0x0693))
    goto loc_1d1da;
}
void sub_1d1e1()
{
  bx = memoryAGet16(ds, 0x6d8f);
  dx = memoryAGet16(ds, bx + 28003);
  sub_1d08b();
  bx = memoryAGet16(ds, 0x6d8f);
  memoryASet16(ds, 0x6d8f, memoryAGet16(ds, 0x6d8f) + 0x0002);
  si = memoryAGet16(ds, bx + 27959);
  sub_1d05b();
}
void sub_1d1fd()
{
  flags.direction = false;
  ax = 0xb800;
  es = ax;
  ax = 0;
  di = ax;
  cx = 0x0fa0;
  rep_stosw<MemAuto, DirAuto>();
  di = 0x2000;
  cx = 0x0fa0;
  rep_stosw<MemAuto, DirAuto>();
}
void sub_1d215()
{
  interrupt(0x11);
  if (!(ax & 0x1000))
    goto loc_1d226;
  sub_1d23f();
  if (!flags.carry)
    return;
  sub_1d23f();
  if (!flags.carry)
    return;
loc_1d226:
  memoryASet16(ds, 0x6d8f, 0x0024);
  cx = 0x0004;
loc_1d22f:
  sub_1d1e1();
  if (--cx)
    goto loc_1d22f;
  ax = memoryAGet16(ds, 0x0693);
loc_1d237:
  if (ax == memoryAGet16(ds, 0x0693))
    goto loc_1d237;
  flags.carry = true;
}
void sub_1d23f()
{
  dx = 0x0201;
  out(dx, al);
  ah = 0;
  interrupt(0x1a);
  memoryASet16(ds, 0x6dfa, dx);
loc_1d24b:
  dx = 0x0201;
  in(al, dx);
  if (al & 0x03)
    goto loc_1d255;
  flags.carry = false;
  return;
loc_1d255:
  ah = 0;
  interrupt(0x1a);
  dx -= memoryAGet16(ds, 0x6dfa);
  if (dx < 0x0012)
    goto loc_1d24b;
  flags.carry = true;
}
void sub_1d270()
{
  flags.direction = false;
  push(ds);
  es = pop();
  di = 0x000e;
  cx = 0x0024;
  ax = 0;
  rep_stosw<MemAuto, DirAuto>();
  memoryASet16(ds, 0x6f24, 0x0025);
  ax = 0xb800;
  es = ax;
loc_1d288:
  sub_18608();
  if (flags.zero)
    goto loc_1d288;
  si = 0x000e;
  di = memoryAGet16(ds, 0x6f24);
  cx = 0x0c03;
  sub_19fcd();
  memoryASet16(ds, 0x6f24, memoryAGet16(ds, 0x6f24) + 0x01e0);
  si = 0x6e10;
  di = memoryAGet16(ds, 0x6f24);
  cx = 0x0c03;
  sub_19fcd();
loc_1d2ad:
  ah = 0;
  interrupt(0x1a);
  if (dx == memoryAGet16(ds, 0x6f26))
    goto loc_1d2ad;
  memoryASet16(ds, 0x6f26, dx);
  if (memoryAGet(ds, 0x0000) == 0x00)
    goto loc_1d2d7;
  al = 0xb6;
  out(0x0043, al);
  ax = memoryAGet16(ds, 0x6f24);
  ax >>= 1;
  out(0x0042, al);
  al = ah;
  out(0x0042, al);
  in(al, 0x61);
  al |= 0x03;
  out(0x0061, al);
loc_1d2d7:
  if (memoryAGet16(ds, 0x6f24) < 0x1a40)
    goto loc_1d288;
  si = 0x6e58;
  di = memoryAGet16(ds, 0x6f24);
  cx = 0x1106;
  sub_19fcd();
loc_1d2ec:
  ah = 0;
  interrupt(0x1a);
  if (dx == memoryAGet16(ds, 0x6f28))
    goto loc_1d2ec;
  memoryASet16(ds, 0x6f28, dx);
  if (memoryAGet(ds, 0x0000) == 0x00)
    goto loc_1d316;
  al = 0xb6;
  out(0x0043, al);
  ax = 0x0c00;
  if (!(dl & 0x01))
    goto loc_1d310;
  ax = 0x0b54;
loc_1d310:
  out(0x0042, al);
  al = ah;
  out(0x0042, al);
loc_1d316:
  dx -= memoryAGet16(ds, 0x6f26);
  if (dx < 0x0012)
    goto loc_1d2ec;
  sub_1cd51();
}
void sub_1d330()
{
  memoryASet(ds, 0x70f2, 0x00);
}
void sub_1d336()
{
  ah = 0;
  interrupt(0x1a);
  if (dx != memoryAGet16(ds, 0x70ee))
    goto loc_1d341;
  return;
loc_1d341:
  memoryASet16(ds, 0x70ee, dx);
  sub_1d4d6();
  if (!flags.carry)
    goto loc_1d359;
  sub_18413();
  sub_1d45b();
  sub_18375();
  memoryASet(ds, 0x70f2, 0x00);
  return;
loc_1d359:
  if (memoryAGet(ds, 0x70f2) != 0x00)
    goto loc_1d3ce;
loc_1d360:
  sub_1a02d();
  bx = dx;
  bx &= 0x001f;
  if (bl < 0x10)
    goto loc_1d396;
  bl -= 0x10;
  if (bl > 0x09)
    goto loc_1d360;
  dl = 0x01;
  if (bl < 0x05)
    goto loc_1d37f;
  dl = 0xff;
loc_1d37f:
  memoryASet(ds, 0x70f6, dl);
  memoryASet(ds, 0x70f5, 0x06);
  bl <<= 1;
  ax = memoryAGet16(ds, bx + 28856);
  ax += 0x0004;
  memoryASet16(ds, 0x70f3, ax);
  goto loc_1d3b8;
loc_1d396:
  ax = 0x000c;
  dl = 0x01;
  if (!(bl & 0x08))
    goto loc_1d3a5;
  ax = 0x0120;
  dl = 0xff;
loc_1d3a5:
  memoryASet16(ds, 0x70f3, ax);
  memoryASet(ds, 0x70f6, dl);
  bl &= 0x07;
  al = memoryAGet(ds, bx + 28848);
  al += 0x08;
  memoryASet(ds, 0x70f5, al);
loc_1d3b8:
  memoryASet(ds, 0x70f2, 0x01);
  memoryASet(ds, 0x70f7, 0x01);
  memoryASet16(ds, 0x70f0, 0x0000);
  memoryASet16(ds, 0x70ec, 0xffff);
loc_1d3ce:
  if (memoryAGet16(ds, 0x70f0) >= 0x00a0)
    goto loc_1d3db;
  memoryASet16(ds, 0x70f0, memoryAGet16(ds, 0x70f0) + 0x0004);
loc_1d3db:
  memoryASet(ds, 0x70f5, memoryAGet(ds, 0x70f5) + 0x02);
  if (memoryAGet(ds, 0x70f5) > 0xbf)
    goto loc_1d404;
  if (memoryAGet(ds, 0x70f6) == 0x01)
    goto loc_1d3f7;
  flags.carry = memoryAGet16(ds, 0x70f3) < 0x0005;
  memoryASet16(ds, 0x70f3, memoryAGet16(ds, 0x70f3) - 0x0005);
  if (flags.carry)
    goto loc_1d404;
  goto loc_1d40d;
loc_1d3f7:
  memoryASet16(ds, 0x70f3, memoryAGet16(ds, 0x70f3) + 0x0005);
  if (memoryAGet16(ds, 0x70f3) < 0x012c)
    goto loc_1d40d;
loc_1d404:
  memoryASet(ds, 0x70f2, 0x00);
  sub_1d45b();
  return;
loc_1d40d:
  cx = memoryAGet16(ds, 0x70f3);
  dl = memoryAGet(ds, 0x70f5);
  sub_19ee0();
  memoryASet16(ds, 0x70fa, ax);
  sub_1d4d6();
  if (flags.carry)
    goto loc_1d404;
  sub_1d475();
  sub_1d45b();
  sub_1d42a();
}
void sub_1d42a()
{
  ax = 0xb800;
  es = ax;
  memoryASet(ds, 0x70f7, 0x00);
  ax = memoryAGet16(ds, 0x70f0);
  ax &= 0x01e0;
  ax += 0x6f30;
  if (memoryAGet(ds, 0x70f6) == 0xff)
    goto loc_1d447;
  ax += 0x00c0;
loc_1d447:
  si = ax;
  di = memoryAGet16(ds, 0x70fa);
  memoryASet16(ds, 0x70f8, di);
  bp = 0x70cc;
  cx = 0x0802;
  sub_19efc();
}
void sub_1d45b()
{
  if (memoryAGet(ds, 0x70f7) != 0x00)
    return;
  ax = 0xb800;
  es = ax;
  si = 0x70cc;
  di = memoryAGet16(ds, 0x70f8);
  cx = 0x0802;
  sub_19fcd();
}
void sub_1d475()
{
  al = memoryAGet(ds, 0x70f5);
  al -= 0x08;
  al &= 0xf8;
  cx = 0x0007;
loc_1d47f:
  bx = cx;
  bx--;
  if (al == memoryAGet(ds, bx + 11220))
    goto loc_1d48b;
  if (--cx)
    goto loc_1d47f;
loc_1d48a:
  return;
loc_1d48b:
  ax = memoryAGet16(ds, 0x70f3);
  cl = 0x04;
  ax >>= cl;
  flags.carry = ax < 0x0002;
  ax -= 0x0002;
  if (flags.carry)
    goto loc_1d48a;
  if (ax >= 0x0010)
    goto loc_1d48a;
  di = ax;
  dl = memoryAGet(ds, bx + 11227);
  dh = 0;
  ax += dx;
  if (ax == memoryAGet16(ds, 0x70ec))
    goto loc_1d48a;
  memoryASet16(ds, 0x70ec, ax);
  si = ax;
  memoryASet(ds, si + 11234, memoryAGet(ds, si + 11234) ^ 0x02);
  al = memoryAGet(ds, si + 11234);
  ah = 0;
  di <<= 1;
  cx = memoryAGet16(ds, di + 28924);
  dl = memoryAGet(ds, bx + 28960);
  push(ax);
  push(cx);
  push(dx);
  sub_1d45b();
  dx = pop();
  cx = pop();
  bx = pop();
  sub_1a313();
  sub_1d42a();
}
void sub_1d4d6()
{
  if (memoryAGet(ds, 0x70f2) != 0x00)
    goto loc_1d4df;
  flags.carry = false;
  return;
loc_1d4df:
  ax = memoryAGet16(ds, 0x70f3);
  dl = memoryAGet(ds, 0x70f5);
  si = 0x0010;
  bx = memoryAGet16(ds, 0x0579);
  dh = memoryAGet(ds, 0x057b);
  di = 0x0018;
  cx = 0x0e08;
  sub_1a059();
  if (!flags.carry)
    return;
  memoryASet(ds, 0x0571, 0x01);
  memoryASet(ds, 0x0576, 0x02);
  memoryASet(ds, 0x0578, 0x20);
  memoryASet(ds, 0x055b, 0x08);
  ax = 0x091d;
  bx = 0x0ce4;
  sub_1cb6b();
  flags.carry = true;
}
