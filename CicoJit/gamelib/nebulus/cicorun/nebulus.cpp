#include <stdio.h>
#include "cicoemu.h"
using namespace CicoContext;

void sub_104f8();

void start()
{
  headerSize = 0x0140;
  ds = 0x1000;
  cs = 0x1000;
  ss = 0x245e;
  sp = 0x0200;
  sub_104f8();
}
// skipping indirect jump
// skipping indirect jump
// skipping indirect jump
void sub_10000();
void sub_10021();
void sub_100d1();
void sub_100d8();
void sub_100e1();
void sub_10140();
void sub_101f0();
void sub_102a0();
void sub_102a9();
void sub_10306();
void sub_10321();
void sub_1034d();
void sub_104f8();
void sub_106b8();
void sub_10711();
void sub_107c0();
void sub_1080a();
void sub_108de();
void sub_108e9();
void sub_1097b();
void sub_109eb();
void sub_10adc();
void sub_10b14();
void sub_10b16();
void sub_10b17();
void sub_10c14();
void sub_10c7a();
void sub_10df0();
void sub_10e3b();
void sub_10e4a();
void sub_10f9e();
void sub_10fc7();
void sub_11132();
void sub_11149();
void sub_111ab();
void sub_11295();
void sub_11367();
void sub_11382();
void sub_113a2();
void sub_113ee();
void sub_113f1();
void sub_11417();
void sub_114e1();
void sub_114e7();
void sub_11517();
void sub_1152b();
void sub_11592();
void sub_115b0();
void sub_115b5();
void sub_115ee();
void sub_1163a();
void sub_11655();
void sub_1165c();
void sub_1169a();
void sub_116ac();
void sub_116cb();
void sub_11719();
void sub_1172b();
void sub_11738();
void sub_1174a();
void sub_1178e();
void sub_117ca();
void sub_11823();
void sub_11840();
void sub_11a3b();
void sub_11abc();
void sub_11cd7();
void sub_11e4d();
void sub_11eb2();
void sub_1226a();
void sub_12317();
void sub_12375();
void sub_123ba();
void sub_123d6();
void sub_123f7();
void sub_12407();
void sub_1242f();
void sub_125d7();
void sub_125fc();
void sub_1264f();
void sub_12672();
void sub_12676();
void sub_1269a();
void sub_126bb();
void sub_126d5();
void sub_1277f();
void sub_12799();
void sub_1285e();
void sub_129ad();
void sub_129e2();
void sub_12a22();
void sub_12a2f();
void sub_12a36();
void sub_12b00();
void sub_12b78();
void sub_12bc6();
void sub_12bd6();
void sub_12bef();
void sub_12bfa();
void sub_12c17();
void sub_12c41();
void sub_12c6a();
void sub_12c91();
void sub_12d22();
void sub_12d86();
void sub_12dc0();
void sub_12ec1();
void sub_12ef0();
void sub_12f58();
void sub_1305f();
void sub_13077();
void sub_13114();
void sub_1313f();
void sub_13252();
void sub_13277();
void sub_13741();
void sub_139f1();
void sub_13a0f();
void sub_13a39();
void sub_13be1();
void sub_13c09();
void sub_13c25();
void sub_13c31();
void sub_13c90();
void sub_13cc3();
void sub_13cde();
void sub_13ce7();
void sub_13d83();
void sub_13ef4();
void sub_13f00();
void sub_14093();
void sub_14132();
void sub_14172();
void sub_14219();
void sub_1422f();
void sub_1424e();
void sub_143f0();
void sub_14502();
void sub_1459e();
void sub_145f3();
void sub_14640();
void sub_146e0();
void sub_146eb();
void sub_149e0();
void sub_149f0();
void sub_14a91();
void sub_14ad4();
void sub_14d95();
void sub_14e2e();
void sub_14e44();
void sub_14e68();
void sub_14ea9();
void sub_14f15();
void sub_14f3a();
void sub_14f61();
void sub_1509e();
void sub_15164();
void sub_1518e();
void sub_151ab();
void sub_151c5();
void sub_151e8();
void sub_15253();
void sub_15275();
void sub_152ae();
void sub_152c7();
// skipping indirect jump
// skipping indirect jump
// skipping indirect jump
void sub_10000()
{
  push(ds);
  ah = 0x35;
  al = 0x1c;
  interrupt(0x21);
  ax = 0x1532;
  ds = ax;
  di = 0x000e;
  memoryASet16(ds, di, es);
  memoryASet16(ds, di + 2, bx);
  push(cs);
  ds = pop();
  dx = 0x0039;
  ah = 0x25;
  al = 0x1c;
  interrupt(0x21);
  ds = pop();
}
void sub_10021()
{
  push(ds);
  ax = 0x1532;
  ds = ax;
  di = 0x000e;
  dx = memoryAGet16(ds, di + 2);
  ax = memoryAGet16(ds, di);
  ds = ax;
  ah = 0x25;
  al = 0x1c;
  interrupt(0x21);
  ds = pop();
}
void sub_100d1()
{
  memoryASet(cs, 0x00cf, 0x00);
}
void sub_100d8()
{
//loc_100d8:
//  if (memoryAGet(cs, 0x00cf) == 0x00)
//    goto loc_100d8;
}
void sub_100e1()
{
  sub_15164();
  ax = 0x1532;
  ds = ax;
  memoryASet(ds, 0x0455, 0x00);
  bp = 0x0012;
  sub_14f3a();
loc_100f4:
    sync();
  if (memoryAGet(ds, 0xe5ea) == 0x01) // yn?
    goto loc_10137;
  if (memoryAGet(ds, 0xe5ce) != 0x01) // yn?
    goto loc_100f4;
  memoryASet(ds, 0x0455, 0x01);
  bp = 0x003c;
  sub_14f3a();
loc_1010d:
    sync();
  if (memoryAGet(ds, 0xe5bb) == 0x01)
    goto loc_1012a;
  if (memoryAGet(ds, 0xe5bc) == 0x01)
    goto loc_1011d;
  goto loc_1010d;
loc_1011d:
  memoryASet(ds, 0x006b, 0x02);
  sub_10140();
  sub_101f0();
  goto loc_10132;
loc_1012a:
  memoryASet(ds, 0x006b, 0x01);
  sub_10140();
loc_10132:
  memoryASet(ds, 0x0455, 0x01);
loc_10137:
  memoryASet(ds, 0x03db, 0x00);
  sub_15164();
}
void sub_10140()
{
  sub_15164();
  memoryASet(ds, 0x006a, 0x01);
  memoryASet(ds, 0x03db, 0x00);
  bp = 0x006c;
  sub_14f3a();
  sub_10321();
loc_10156:
  sub_10306();
  if (memoryAGet(ds, 0xe639) != 0x10)
    goto loc_10156;
  sub_102a9();
  memoryASet16(ds, 0x0112, bx);
  memoryASet16(ds, 0x0114, cx);
  sub_10321();
  bp = 0x00b5;
  sub_14f3a();
loc_10174:
  sub_10306();
  if (memoryAGet(ds, 0xe639) != 0x10)
    goto loc_10174;
  sub_102a9();
  memoryASet16(ds, 0x0116, bx);
  memoryASet16(ds, 0x0118, cx);
  sub_10321();
  bp = 0x00e3;
  sub_14f3a();
loc_10192:
  sub_10306();
  if (memoryAGet(ds, 0xe639) != 0x10)
    goto loc_10192;
  sub_102a9();
  memoryASet16(ds, 0x011a, bx);
  memoryASet16(ds, 0x011c, cx);
  bx = memoryAGet16(ds, 0x0116);
  bx -= memoryAGet16(ds, 0x011a);
  bx >>= 1;
  bx += memoryAGet16(ds, 0x011a);
  memoryASet16(ds, 0x010c, bx);
  bx = memoryAGet16(ds, 0x011a);
  bx -= memoryAGet16(ds, 0x0112);
  bx >>= 1;
  bx += memoryAGet16(ds, 0x0112);
  memoryASet16(ds, 0x010a, bx);
  bx = memoryAGet16(ds, 0x0118);
  bx -= memoryAGet16(ds, 0x011c);
  bx >>= 1;
  bx += memoryAGet16(ds, 0x011c);
  memoryASet16(ds, 0x0110, bx);
  bx = memoryAGet16(ds, 0x011c);
  bx -= memoryAGet16(ds, 0x0114);
  bx >>= 1;
  bx += memoryAGet16(ds, 0x0114);
  memoryASet16(ds, 0x010e, bx);
}
void sub_101f0()
{
  sub_15164();
  memoryASet(ds, 0x006a, 0x02);
  memoryASet(ds, 0x03db, 0x01);
  bp = 0x011e;
  sub_14f3a();
  sub_10321();
loc_10206:
  sub_10306();
  if (memoryAGet(ds, 0xe639) != 0x10)
    goto loc_10206;
  sub_102a9();
  memoryASet16(ds, 0x016f, bx);
  memoryASet16(ds, 0x0171, cx);
  sub_10321();
  bp = 0x00b5;
  sub_14f3a();
loc_10224:
  sub_10306();
  if (memoryAGet(ds, 0xe639) != 0x10)
    goto loc_10224;
  sub_102a9();
  memoryASet16(ds, 0x0173, bx);
  memoryASet16(ds, 0x0175, cx);
  sub_10321();
  bp = 0x00e3;
  sub_14f3a();
loc_10242:
  sub_10306();
  if (memoryAGet(ds, 0xe639) != 0x10)
    goto loc_10242;
  sub_102a9();
  memoryASet16(ds, 0x0177, bx);
  memoryASet16(ds, 0x0179, cx);
  bx = memoryAGet16(ds, 0x0173);
  bx -= memoryAGet16(ds, 0x0177);
  bx >>= 1;
  bx += memoryAGet16(ds, 0x0177);
  memoryASet16(ds, 0x0169, bx);
  bx = memoryAGet16(ds, 0x0177);
  bx -= memoryAGet16(ds, 0x016f);
  bx >>= 1;
  bx += memoryAGet16(ds, 0x016f);
  memoryASet16(ds, 0x0167, bx);
  bx = memoryAGet16(ds, 0x0175);
  bx -= memoryAGet16(ds, 0x0179);
  bx >>= 1;
  bx += memoryAGet16(ds, 0x0179);
  memoryASet16(ds, 0x016d, bx);
  bx = memoryAGet16(ds, 0x0179);
  bx -= memoryAGet16(ds, 0x0171);
  bx >>= 1;
  bx += memoryAGet16(ds, 0x0171);
  memoryASet16(ds, 0x016b, bx);
}
void sub_102a0()
{
  if (memoryAGet(ds, 0x006a) == 0x01)
    goto loc_102dd;
  goto loc_102b0;
  //   gap of 7 bytes
loc_102b0:
  bx = 0;
  cx = bx;
  si = 0xc350;
  dx = 0x0201;
  flags.interrupts = false;
  out(dx, al);
loc_102c7:
  in(al, dx);
  ax &= 0x000c;
  if (ax == 0)
    goto loc_102db;
  flags.carry = 0;
  ax = rcr(ax, 0x0001);
  ax = rcr(ax, 0x0001);
  stop(/*74*/);
  ax = rcr(ax, 0x0001);
  bx += flags.carry;
  cx += ax;
  si++;
  if (si != 0)
    goto loc_102c7;
loc_102db:
  flags.interrupts = true;
  return;
loc_102dd:
  bx = 0;
  cx = bx;
  si = 0xc350;
  dx = 0x0201;
  flags.interrupts = false;
  out(dx, al);
loc_102f4:
  in(al, dx);
  ax &= 0x0003;
  if (ax == 0)
    goto loc_10304;
  stop(/*74*/);
  flags.carry = 0;
  ax = rcr(ax, 0x0001);
  bx += flags.carry;
  cx += ax;
  si++;
  if (si != 0)
    goto loc_102f4;
loc_10304:
  flags.interrupts = true;
}
void sub_102a9()
{
  if (memoryAGet(ds, 0x006a) == 0x01)
    goto loc_102dd;
  bx = 0;
  cx = bx;
  si = 0xc350;
  dx = 0x0201;
  flags.interrupts = false;
  out(dx, al);
loc_102c7:
  in(al, dx);
  ax &= 0x000c;
  if (ax == 0)
    goto loc_102db;
  flags.carry = 0;
  ax = rcr(ax, 0x0001);
  ax = rcr(ax, 0x0001);
  stop(/*74*/);
  ax = rcr(ax, 0x0001);
  bx += flags.carry;
  cx += ax;
  si++;
  if (si != 0)
    goto loc_102c7;
loc_102db:
  flags.interrupts = true;
  return;
loc_102dd:
  bx = 0;
  cx = bx;
  si = 0xc350;
  dx = 0x0201;
  flags.interrupts = false;
  out(dx, al);
loc_102f4:
  in(al, dx);
  ax &= 0x0003;
  if (ax == 0)
    goto loc_10304;
  stop(/*74*/);
  flags.carry = 0;
  ax = rcr(ax, 0x0001);
  bx += flags.carry;
  cx += ax;
  si++;
  if (si != 0)
    goto loc_102f4;
loc_10304:
  flags.interrupts = true;
}
void sub_10306()
{
  push(ax);
  push(bx);
  push(cx);
  push(dx);
  push(di);
  push(si);
  push(bp);
  push(es);
  push(ds);
  sub_1034d();
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) & 0x10);
  ds = pop();
  es = pop();
  bp = pop();
  si = pop();
  di = pop();
  dx = pop();
  cx = pop();
  bx = pop();
  ax = pop();
}
void sub_10321()
{
  push(ax);
  push(bx);
  push(cx);
  push(dx);
  push(di);
  push(si);
  push(bp);
  push(es);
  push(ds);
loc_1032a:
  sub_1034d();
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) & 0x10);
  if (memoryAGet(ds, 0xe639) == 0x10)
    goto loc_1032a;
  cx = 0x0019;
loc_1033c:
  push(cx);
  sub_1518e();
  cx = pop();
  if (--cx)
    goto loc_1033c;
  ds = pop();
  es = pop();
  bp = pop();
  si = pop();
  di = pop();
  dx = pop();
  cx = pop();
  bx = pop();
  ax = pop();
}
void sub_1034d()
{
  ax = 0x1532;
  ds = ax;
  memoryASet(ds, 0xe639, 0x00);
  memoryASet(ds, 0x006a, 0x01);
  if (memoryAGet(ds, 0x006b) == 0x01)
    goto loc_103d7;
  if (memoryAGet(ds, 0x03db) == 0x00)
    goto loc_103d7;
  memoryASet(ds, 0x006a, memoryAGet(ds, 0x006a) + 1);
  sub_102a9();
  si = bx;
  if (si >= memoryAGet16(ds, 0x0167))
    goto loc_1037e;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x02);
loc_1037e:
  if (si <= memoryAGet16(ds, 0x0169))
    goto loc_10389;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x01);
loc_10389:
  sub_102a0();
  si = cx;
  if (si >= memoryAGet16(ds, 0x016b))
    goto loc_10399;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x08);
loc_10399:
  if (si <= memoryAGet16(ds, 0x016d))
    goto loc_103a4;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x04);
loc_103a4:
  dx = 0x0201;
  in(al, dx);
  cl = 0x20;
  ch = 0x10;
  if (memoryAGet(ds, 0x006a) == 0x01)
    goto loc_103b7;
  cl = 0x80;
  ch = 0x40;
loc_103b7:
  if (cl & al)
    goto loc_103c0;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x20);
loc_103c0:
  if (ch & al)
    goto loc_103c9;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x10);
loc_103c9:
  if (memoryAGet(ds, 0xe5f2) == 0x01)
    goto loc_103d1;
  return;
loc_103d1:
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x10);
  return;
loc_103d7:
  sub_102a9();
  si = bx;
  if (si >= memoryAGet16(ds, 0x010a))
    goto loc_103e7;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x02);
loc_103e7:
  if (si <= memoryAGet16(ds, 0x010c))
    goto loc_103f2;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x01);
loc_103f2:
  sub_102a0();
  si = cx;
  if (si >= memoryAGet16(ds, 0x010e))
    goto loc_10402;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x08);
loc_10402:
  if (si <= memoryAGet16(ds, 0x0110))
    goto loc_1040d;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x04);
loc_1040d:
  dx = 0x0201;
  in(al, dx);
  cl = 0x20;
  ch = 0x10;
  if (memoryAGet(ds, 0x006a) == 0x01)
    goto loc_10420;
  cl = 0x80;
  ch = 0x40;
loc_10420:
  if (cl & al)
    goto loc_10429;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x20);
loc_10429:
  if (ch & al)
    goto loc_10432;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x10);
loc_10432:
  if (memoryAGet(ds, 0xe5f2) == 0x01)
    goto loc_1043a;
  return;
loc_1043a:
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x10);
}
void sub_1530e();
void sub_104f8()
{
  push(es);
    sub_1530e();
  es = pop();
  ax = 0x1532;
  ds = ax;
  ax = es;
  bx = 0x5ada;
  bx -= ax;
  ah = 0x4a;
  interrupt(0x21);
  if (!flags.carry)
    goto loc_10520;
  dx = 0x0482;
loc_10517:
  ah = 0x09;
  interrupt(0x21);
  ax = 0x4cff;
  interrupt(0x21);
loc_10520:
  bx = 0x07d0;
  ah = 0x48;
  interrupt(0x21);
  if (!flags.carry)
    goto loc_1052e;
  dx = 0x0482;
  goto loc_10517;
loc_1052e:
  memoryASet16(ds, 0x0480, ax);
  ax = 0x000d;
  interrupt(0x10);
  ax = 0x1532;
  ds = ax;
  sub_125d7();
  ax = 0x1532;
  ds = ax;
  memoryASet(ds, 0xefc2, 0x01);
  sub_10adc();
  sub_1174a();
  sub_151c5();
  sub_11382();
  ax = 0x1532;
  ds = ax;
  dx = 0x03ce;
  ax = 0x0001;
  dx = 0x03ce;
  out(dx, ax);
  ax = 0x0005;
  dx = 0x03ce;
  out(dx, ax);
  sub_15164();
  ax = 0x1532;
  ds = ax;
  ax = 0xa000;
  es = ax;
  di = 0x0000;
  ax = 0x0005;
  dx = 0x03ce;
  out(dx, ax);
  memoryASet(ds, 0xefc2, 0x01);
  ax = 0x1532;
  ds = ax;
  al = 0;
  sub_15164();
  sub_10b14();
  sub_13ef4();
  memoryASet(ds, 0x03da, 0x01);
  memoryASet(ds, 0x03f1, 0x80);
  memoryASet(ds, 0x03cb, 0x00);
  memoryASet(ds, 0x0477, 0x00);
  sub_100e1();
  sub_13ef4();
loc_105b0:
  memoryASet(ds, 0x03cc, 0x00);
  sub_1285e();
  sub_13c25();
  sub_13ef4();
  sub_13c09();
  memoryASet(ds, 0x03db, 0x01);
loc_105c6:
  sub_13c31();
  tx = flags.carry;
  push(tx);
  sub_12bfa();
  tx = pop();
  if (!tx)
    goto loc_105b0;
loc_105d0:
  sub_11719();
  sub_1172b();
  sub_12c6a();
  memoryASet(ds, 0x047e, 0x00);
  memoryASet(ds, 0x047f, 0x00);
  sub_12b78();
  memoryASet(ds, 0x03b7, 0x00);
  memoryASet(ds, 0x03f0, 0xff);
  sub_123ba();
  sub_10711();
  sub_114e1();
loc_105f9:
  sub_1080a();
  if (memoryAGet(ds, 0x03b7) != 0x00)
    goto loc_10619;
  if (memoryAGet(ds, 0x03cd) == 0x02)
    goto loc_1064a;
  if (memoryAGet16(ds, 0x03ee) == 0x0000)
    goto loc_10616;
  sub_12dc0();
  goto loc_105f9;
loc_10616:
  sub_1269a();
loc_10619:
  memoryASet(ds, 0x03f0, 0xff);
  if (memoryAGet(ds, 0x03cb) != 0x00)
    goto loc_1063c;
  bx = 0x03dc;
  if (memoryAGet(ds, 0x03db) == 0x00)
    goto loc_10630;
  bx++;
loc_10630:
  memoryASet(ds, bx, memoryAGet(ds, bx) - 1);
  push(bx);
  sub_12c6a();
  bx = pop();
  if (memoryAGet(ds, bx) == 0x00)
    goto loc_10641;
loc_1063c:
  sub_12407();
  goto loc_105c6;
loc_10641:
  sub_123f7();
  sub_12676();
  goto loc_105c6;
loc_1064a:
  memoryASet(ds, 0x03f0, 0xff);
  al = memoryAGet(ds, 0x03ad);
  push(ax);
  push(memoryAGet16(ds, 0x03ae));
  push(memoryAGet16(ds, 0x046e));
  sub_126d5();
  sub_123ba();
  memoryASet(ds, 0x03cd, 0x03);
  sub_10711();
  memoryASet16(ds, 0x046e, pop());
  memoryASet16(ds, 0x03ae, pop());
  ax = pop();
  memoryASet(ds, 0x03ad, al);
  memoryASet(ds, 0x03b4, 0x04);
  memoryASet(ds, 0x03b3, 0x1d);
  memoryASet(ds, 0x03b6, 0x00);
loc_10684:
  sub_1080a();
  sub_12dc0();
  if (memoryAGet(ds, 0x03cd) != 0x04)
    goto loc_10684;
  memoryASet(ds, 0x03cd, 0x00);
  sub_123d6();
  if (al != 0x08)
    goto loc_106a6;
  sub_123f7();
  sub_126bb();
  goto loc_105c6;
loc_106a6:
  sub_12407();
  sub_12bfa();
  sub_11719();
  sub_1172b();
  sub_10b17();
  goto loc_105d0;
}
void sub_106b8()
{
  push(es);
  push(ds);
  bl = memoryAGet(ds, 0x03d4);
  bl &= 0x03;
  bh = 0;
  bx <<= 1;
  dx = bx;
  ax = 0x3581;
  ds = ax;
  ax = 0x247e;
  es = ax;
  di = 0x00b2;
  bx += 0x0000;
  si = memoryAGet16(ds, bx);
  cx = 0x3600;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di = 0x36b2;
  ax = 0x4302;
  ds = ax;
  dx += 0x0000;
  bx = dx;
  si = memoryAGet16(ds, bx);
  cx = 0x2400;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  ds = pop();
  es = pop();
  al = memoryAGet(ds, 0x03d4);
  al &= 0x03;
  if (al == 0x02)
    goto loc_10703;
  al = 0x13;
  goto loc_10705;
loc_10703:
  al = 0x17;
loc_10705:
  memoryASet(cs, 0x0ad9, al);
  push(es);
  push(ds);
  sub_10adc();
  ds = pop();
  es = pop();
}
void sub_10711()
{
  ax = 0x1532;
  es = ax;
  di = 0x055c;
  cx = 0x0800;
  ax = 0;
  rep_stosw<MemAuto, DirAuto>();
  sub_106b8();
  sub_117ca();
  if (memoryAGet(ds, 0x03d4) != 0x07)
    goto loc_10767;
  ax = 0x1532;
  es = ax;
  if (memoryAGet(ds, 0xeea7) == 0x00)
    goto loc_10751;
  ax = 0;
  di = 0x09b8;
  stosw<MemAuto, DirAuto>();
  stosb<MemAuto, DirAuto>();
  di = 0x0bb8;
  stosw<MemAuto, DirAuto>();
  stosb<MemAuto, DirAuto>();
  di = 0x11b7;
  stosw<MemAuto, DirAuto>();
  stosw<MemAuto, DirAuto>();
  di = 0x13b8;
  stosw<MemAuto, DirAuto>();
  stosb<MemAuto, DirAuto>();
  goto loc_10767;
loc_10751:
  ax = 0;
  di = 0x06b8;
  stosw<MemAuto, DirAuto>();
  stosb<MemAuto, DirAuto>();
  di = 0x08b8;
  stosw<MemAuto, DirAuto>();
  stosb<MemAuto, DirAuto>();
  di = 0x0eb7;
  stosw<MemAuto, DirAuto>();
  stosw<MemAuto, DirAuto>();
  di = 0x10b8;
  stosw<MemAuto, DirAuto>();
  stosb<MemAuto, DirAuto>();
loc_10767:
  sub_107c0();
  sub_108de();
  sub_149e0();
  sub_13cde();
  cx = 0x0004;
  di = 0x039d;
  al = 0xff;
  rep_stosb<MemAuto, DirAuto>();
  if (memoryAGet(ds, 0x03cd) == 0x03)
    goto loc_107b5;
  sub_10b16();
  memoryASet(ds, 0x03bd, 0x01);
  al = 0x24;
  al -= memoryAGet(ds, 0x03ad);
  al &= 0x7f;
  memoryASet(ds, 0x0470, al);
  sub_12375();
  sub_13114();
  memoryASet(ds, 0x03bd, memoryAGet(ds, 0x03bd) - 1);
  memoryASet(ds, 0x03cd, 0x00);
  memoryASet(ds, 0x043e, 0x7d);
  memoryASet(ds, 0x043f, 0x01);
  al = memoryAGet(ds, 0x03cb);
  goto loc_107b7;
loc_107b5:
  al = 0xff;
loc_107b7:
  memoryASet(ds, 0x03f0, al);
  memoryASet(ds, 0x0475, 0x02);
}
void sub_107c0()
{
  memoryASet(ds, 0x03ad, 0x04);
  al = 0x08;
  memoryASet(ds, 0x03ae, al);
  memoryASet(ds, 0x03b0, al);
    flags.carry = al < 0x28;
  al -= 0x28;
  memoryASet(ds, 0x046e, al);
  al = 0x00;
  memoryASet(ds, 0x03af, al);
  memoryASet(ds, 0x03b1, al);
    al -= flags.carry;
  al &= 0x03;
  memoryASet(ds, 0x046f, al);
  memoryASet(ds, 0x03d2, 0x00);
  memoryASet(ds, 0x03b3, 0x00);
  memoryASet(ds, 0x03b7, 0x00);
  memoryASet(ds, 0x045e, 0x00);
  memoryASet(ds, 0x03b9, 0x00);
  memoryASet(ds, 0x03b4, 0x00);
  memoryASet(ds, 0x03b2, 0x80);
  memoryASet(ds, 0x03b6, 0x01);
}
void sub_1080a()
{
  sub_100d1();
  if (memoryAGet(ds, 0x0475) == 0x00)
    goto loc_10829;
  memoryASet(ds, 0x0475, memoryAGet(ds, 0x0475) - 1);
  memoryASet(ds, 0x045b, 0x00);
  memoryASet(ds, 0x045c, 0x00);
  memoryASet(ds, 0x045a, 0x00);
  goto loc_1082c;
loc_10829:
  sub_13c90();
loc_1082c:
  if (memoryAGet(ds, 0x03cc) != 0x00)
    goto loc_10869;
  if (memoryAGet(ds, 0x03cd) != 0x03)
    goto loc_10847;
  sub_13741();
  if (memoryAGet(ds, 0x03cd) != 0x04)
    goto loc_10845;
  return;
loc_10845:
  goto loc_10869;
loc_10847:
  sub_12ef0();
  sub_13ce7();
  sub_13741();
  al = memoryAGet(ds, 0x043f);
  push(ax);
  sub_13d83();
  ax = pop();
  if (al == memoryAGet(ds, 0x043f))
    goto loc_10863;
  al = 0;
  sub_114e7();
loc_10863:
  sub_14ad4();
  sub_108e9();
loc_10869:
  al = 0x24;
  al -= memoryAGet(ds, 0x03ad);
  al &= 0x7f;
  memoryASet(ds, 0x0470, al);
  sub_12375();
  sub_116ac();
  sub_11e4d();
  sub_1178e();
  sub_11abc();
  sub_11cd7();
  sub_149f0();
  ax = memoryAGet16(ds, 0x047b);
  memoryASet16(ds, 0xe9b9, ax);
  al = memoryAGet(ds, 0x047d);
  memoryASet(ds, 0xe9b8, al);
  al = memoryAGet(ds, 0x047a);
  memoryASet(ds, 0xe9b7, al);
  memoryASet(ds, 0x047a, 0x00);
  sub_14a91();
  sub_14093();
  sub_13f00();
  sub_1152b();
  sub_11840();
  sub_12317();
  sub_1226a();
  if (memoryAGet(ds, 0x03cd) == 0x03)
    goto loc_108c5;
  sub_13be1();
  sub_12d22();
  sub_116cb();
loc_108c5:
  sub_100d8();
  memoryASet(ds, 0x047f, memoryAGet(ds, 0x047f) + 1);
  memoryASet(ds, 0x047f, memoryAGet(ds, 0x047f) & 0x01);
  if (memoryAGet(ds, 0x047f) != 0)
    goto loc_108d4;
  return;
loc_108d4:
  memoryASet(ds, 0x047e, memoryAGet(ds, 0x047e) + 1);
  memoryASet(ds, 0x047e, memoryAGet(ds, 0x047e) & 0x07);
}
void sub_108de()
{
  al = 0xff;
  memoryASet(ds, 0x03d3, al);
  memoryASet(ds, 0x047a, 0x00);
}
void sub_108e9()
{
  al = memoryAGet(ds, 0x03b4);
  if (al != 0x07)
    goto loc_108f1;
  return;
loc_108f1:
  if (al != 0x04)
    goto loc_10901;
  al = memoryAGet(ds, 0x03b3);
  if (al < 0x0a)
    goto loc_1090d;
  if (al >= 0x1f)
    goto loc_1090d;
  return;
loc_10901:
  if (al != 0x08)
    goto loc_10906;
  return;
loc_10906:
  al = memoryAGet(ds, 0x03b9);
  if (al)
    goto loc_10954;
loc_1090d:
  sub_1097b();
  if (flags.carry)
    goto loc_1092e;
  if (memoryAGet(ds, 0x03b4) == 0x06)
    goto loc_1091a;
  return;
loc_1091a:
  al = memoryAGet(ds, 0x03ad);
  bx = memoryAGet16(ds, 0x03ae);
  sub_139f1();
  if (flags.carry)
    goto loc_10927;
  return;
loc_10927:
  memoryASet(ds, 0xe947, 0x14);
  goto loc_10945;
loc_1092e:
  al = memoryAGet(ds, bp + 48);
  ch = 0x0f;
  if (al == 0x07)
    goto loc_1093a;
  ch = 0x14;
loc_1093a:
  memoryASet(ds, 0xe947, ch);
  al = memoryAGet(ds, 0x03b4);
  if (al != 0x06)
    goto loc_10951;
loc_10945:
  al = memoryAGet(ds, 0x03ae);
  al &= 0x03;
  if (al == 0)
    goto loc_10963;
  memoryASet(ds, 0x03b9, memoryAGet(ds, 0x03b9) + 1);
  return;
loc_10951:
  goto loc_13653;
loc_10954:
  al = memoryAGet(ds, 0x03b4);
  if (al != 0x06)
    goto loc_10973;
  al = memoryAGet(ds, 0x03ae);
  al &= 0x03;
  if (al == 0)
    goto loc_10963;
  return;
loc_10963:
  sub_12f58();
  sub_12ec1();
  if (!flags.carry)
    goto loc_1096e;
  memoryASet(ds, bx, 0x8d);
loc_1096e:
  memoryASet(ds, 0x03d3, 0xff);
loc_10973:
  memoryASet(ds, 0x03b9, 0x00);
  goto loc_13653;
  //   gap of 11480 bytes
loc_13653:
  memoryASet(ds, 0x03b4, 0x07);
  memoryASet(ds, 0x03b3, 0x00);
  memoryASet(ds, 0x03cd, 0x00);
  al = 0x02;
  sub_12c41();
  al = 0x05;
  sub_114e7();
}
void sub_1097b()
{
  bp = 0x03fb;
  al = memoryAGet(ds, 0x03ad);
  memoryASet(ds, bp, al);
  al = memoryAGet(ds, 0x03ae);
  flags.carry = (al + 0x01) >= 0x100;
  al += 0x01;
  memoryASet(ds, bp + 6, al);
  al = memoryAGet(ds, 0x03af);
  al += flags.carry;
  al &= 0x03;
  memoryASet(ds, bp + 12, al);
  sub_109eb();
  if (flags.carry)
    goto loc_109e7;
  cx = 0x0004;
  bp = 0x03f6;
loc_109a4:
  if (memoryAGet(ds, bp + 48) == 0x07)
    goto loc_109b0;
  bp++;
  if (--cx)
    goto loc_109a4;
loc_109ae:
  flags.carry = false;
  return;
loc_109b0:
  al = memoryAGet(ds, bp);
  if (al < 0x35)
    goto loc_109ae;
  if (al >= 0x44)
    goto loc_109ae;
  al = memoryAGet(ds, bp + 6);
  flags.carry = (al + 0x07) >= 0x100;
  al += 0x07;
  bl = al;
  al = memoryAGet(ds, bp + 12);
  al += flags.carry;
  bh = al;
  cx = memoryAGet16(ds, 0x03ae);
  flags.carry = bx < cx;
  bx -= cx;
  if (flags.carry)
    goto loc_109ae;
  bx = 0x0009;
  bx += cx;
  cl = memoryAGet(ds, bp + 6);
  ch = memoryAGet(ds, bp + 12);
  flags.carry = bx < cx;
  bx -= cx;
  if (flags.carry)
    goto loc_109ae;
  flags.carry = true;
  return;
loc_109e7:
  bp = bx;
  flags.carry = true;
}
void sub_109eb()
{
  al = 0x04;
  si = 0x03f6;
loc_109f0:
  tl = ah;
  ah = al;
  al = tl;
  cx = si;
  bx = bp;
  al = bh;
  if (al != ch)
    goto loc_10a05;
  al = bl;
  if (al != cl)
    goto loc_10a05;
  goto loc_10a93;
loc_10a05:
  al = memoryAGet(ds, si + 48);
  if (al != 0x07)
    goto loc_10a0f;
  goto loc_10a93;
loc_10a0f:
  if (al != 0x00)
    goto loc_10a15;
  goto loc_10a93;
loc_10a15:
  if (al != 0x04)
    goto loc_10a1b;
  goto loc_10a93;
loc_10a1b:
  if (al != 0x06)
    goto loc_10a21;
  goto loc_10a93;
loc_10a21:
  al = memoryAGet(ds, bp);
  al -= memoryAGet(ds, si);
  al &= 0x7f;
  if (al < 0x04)
    goto loc_10a33;
  if (al >= 0x7c)
    goto loc_10a33;
  goto loc_10a93;
loc_10a33:
  al += 0x03;
  al &= 0x07;
  memoryASet(ds, 0x04b7, al);
  al = memoryAGet(ds, bp + 6);
  al -= memoryAGet(ds, si + 6);
  bl = al;
  al = memoryAGet(ds, bp + 12);
  stop(/*PROBLEM-11g*/);
  al &= 0x03;
  if (al != 0)
    goto loc_10a56;
  al = bl;
  if (al < 0x08)
    goto loc_10a60;
  goto loc_10a93;
loc_10a56:
  if (al != 0x03)
    goto loc_10a93;
  al = bl;
  if (al < 0xf9)
    goto loc_10a93;
loc_10a60:
  al += 0x07;
  cl = al;
  ch = 0;
  bx = bp;
  bx -= 0x03f6;
  al = bl;
  bx += 0x03f6;
  if (al == 0x05)
    goto loc_10a90;
  bx = 0x0499;
  if (al != 0x04)
    goto loc_10a80;
  bx = 0x04a8;
loc_10a80:
  bx += cx;
  al = memoryAGet(ds, bx);
  memoryASet(ds, 0x04b7, memoryAGet(ds, 0x04b7) + 1);
  cl = memoryAGet(ds, 0x04b7);
  stop(/*carry1*/);
  al = rcr(al, cl);
  if (stop(/*70*/))
    goto loc_10a93;
loc_10a90:
  flags.carry = true;
  goto loc_10a9e;
loc_10a93:
  si++;
  tl = ah;
  ah = al;
  al = tl;
  al--;
  if (al == 0)
    goto loc_10a9d;
  goto loc_109f0;
loc_10a9d:
  flags.carry = false;
loc_10a9e:
  bx = si;
}
void sub_10adc()
{
  push(ds);
  si = 0x0aca;
  memoryASet(cs, 0x0adb, 0x00);
  cx = 0x0010;
loc_10ae9:
  push(cx);
  push(si);
  ah = 0x10;
  al = 0x00;
  bh = memoryAGet(cs, si);
  bl = memoryAGet(cs, 0x0adb);
  interrupt(0x10);
  memoryASet(cs, 0x0adb, memoryAGet(cs, 0x0adb) + 1);
  si = pop();
  si++;
  cx = pop();
  if (--cx)
    goto loc_10ae9;
  ds = pop();
}
void sub_10b14()
{
}
void sub_10b16()
{
}
void sub_10b17()
{
  sub_114e1();
  sub_123ba();
  al = 0x01;
  sub_113ee();
  bp = 0x04b8;
  sub_14f3a();
  sub_12bc6();
  bp = 0x04be;
  sub_14f3a();
loc_10b31:
  sub_11417();
  if (!flags.carry)
    goto loc_10b31;
  sub_123ba();
  ax = 0x4c03;
  es = ax;
  di = 0x0038;
  si = 0xeb7f;
  cx = 0x00c8;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  es = memoryAGet16(ds, 0x0480);
  di = 0x0000;
  al = 0xaa;
  cx = 0x7d00;
  rep_stosb<MemAuto, DirAuto>();
  ax = 0x4c03;
  ds = ax;
  memoryASet16(ds, 0x0032, 0x0266);
  memoryASet16(ds, 0x0034, 0x026a);
  memoryASet16(ds, 0x0036, 0x026e);
  al = 0;
  memoryASet(ds, 0x000e, al);
  memoryASet(ds, 0x0014, al);
  memoryASet(ds, 0x001a, al);
  memoryASet(ds, 0x0020, al);
  memoryASet(ds, 0x01ca, al);
  memoryASet(ds, 0x002c, al);
  memoryASet(ds, 0x01d4, 0x01);
  memoryASet(ds, 0x01d5, 0x00);
  memoryASet16(ds, 0x01d6, 0x0000);
  bp = 0x0026;
  memoryASet(ds, bp, 0x01);
  memoryASet(ds, bp + 1, 0x20);
  memoryASet(ds, bp + 2, 0x68);
  memoryASet(ds, bp + 3, 0x00);
  ax = 0x1532;
  ds = ax;
loc_10bae:
  sub_100d1();
  sub_111ab();
  sub_10c14();
  sub_10c7a();
  sub_11149();
  sub_1152b();
  sub_1264f();
  dl = memoryAGet(ds, 0xe639);
  ax = 0x4c03;
  ds = ax;
  memoryASet(ds, 0x01ca, dl);
  memoryASet(ds, 0x01d0, memoryAGet(ds, 0x01d0) + 1);
  memoryASet(ds, 0x01d0, memoryAGet(ds, 0x01d0) & 0x01);
  if (memoryAGet(ds, 0x01d4) == 0x00)
    goto loc_10be4;
  memoryASet16(ds, 0x01d6, memoryAGet16(ds, 0x01d6) + 1);
loc_10be4:
  ax = 0x1532;
  ds = ax;
  sub_12d22();
  sub_100d8();
  sub_11367();
  ax = 0x4c03;
  ds = ax;
  if (memoryAGet16(ds, 0x01d6) < 0x0258)
    goto loc_10bae;
  memoryASet(ds, 0x01d4, 0x00);
  if (memoryAGet(ds, 0x01d5) != 0x02)
    goto loc_10bae;
  ax = 0x1532;
  ds = ax;
  sub_123ba();
}
void sub_10c14()
{
  ax = 0x1532;
  ds = ax;
  es = memoryAGet16(ds, 0x0480);
  ax = 0x4c03;
  ds = ax;
  if (memoryAGet(ds, 0x01d4) == 0x00)
    goto loc_10c35;
  memoryASet16(ds, 0x0032, memoryAGet16(ds, 0x0032) - 1);
  memoryASet16(ds, 0x0034, memoryAGet16(ds, 0x0034) - 1);
  memoryASet16(ds, 0x0036, memoryAGet16(ds, 0x0036) - 1);
loc_10c35:
  if (memoryAGet16(ds, 0x0032) > 0x0024)
    goto loc_10c4a;
  di = 0x3200;
  di += memoryAGet16(ds, 0x0032);
  si = memoryAGet16(ds, 0x0a5c);
  sub_10fc7();
loc_10c4a:
  if (memoryAGet16(ds, 0x0034) > 0x0024)
    goto loc_10c5f;
  di = 0x3200;
  di += memoryAGet16(ds, 0x0034);
  si = memoryAGet16(ds, 0x0a5e);
  sub_10fc7();
loc_10c5f:
  if (memoryAGet16(ds, 0x0036) > 0x0024)
    goto loc_10c74;
  di = 0x3200;
  di += memoryAGet16(ds, 0x0036);
  si = memoryAGet16(ds, 0x0a60);
  sub_10fc7();
loc_10c74:
  ax = 0x1532;
  ds = ax;
}
void sub_10c7a()
{
  ax = 0x1532;
  ds = ax;
  es = memoryAGet16(ds, 0x0480);
  ax = 0x4c03;
  ds = ax;
  bp = 0x002c;
  si = 0x0a5a;
  if (memoryAGet(ds, bp + 1) < 0xf0)
    goto loc_10c9a;
  memoryASet(ds, bp, 0x00);
loc_10c9a:
  memoryASet(ds, bp + 1, memoryAGet(ds, bp + 1) + 0x08);
  sub_10f9e();
  cx = 0x0004;
loc_10ca5:
  push(cx);
  bx = 0x0004;
  cx <<= 1;
  bx += cx;
  bp = memoryAGet16(ds, bx);
  sub_10df0();
  sub_10e4a();
  si = 0x0a02;
  sub_10f9e();
  cx = pop();
  if (--cx)
    goto loc_10ca5;
  bp = 0x0026;
  si = 0x0a42;
  if (memoryAGet(ds, 0x01d4) == 0x01)
    goto loc_10d24;
  memoryASet(ds, 0x01ca, 0x00);
  if (memoryAGet(ds, 0x01d5) == 0x01)
    goto loc_10d11;
  if (memoryAGet(ds, bp + 1) == 0x64)
    goto loc_10cec;
  if (memoryAGet(ds, bp + 1) > 0x64)
    goto loc_10ce7;
  memoryASet(ds, 0x01ca, memoryAGet(ds, 0x01ca) | 0x01);
  goto loc_10cec;
loc_10ce7:
  memoryASet(ds, 0x01ca, memoryAGet(ds, 0x01ca) | 0x02);
loc_10cec:
  if (memoryAGet(ds, bp + 2) == 0x6a)
    goto loc_10d03;
  if (memoryAGet(ds, bp + 2) > 0x6a)
    goto loc_10cfc;
  memoryASet(ds, 0x01ca, memoryAGet(ds, 0x01ca) | 0x04);
  goto loc_10d24;
loc_10cfc:
  memoryASet(ds, 0x01ca, memoryAGet(ds, 0x01ca) | 0x08);
  goto loc_10d24;
loc_10d03:
  if (memoryAGet(ds, bp + 1) != 0x64)
    goto loc_10d24;
  memoryASet(ds, 0x01d5, 0x01);
  goto loc_10d24;
loc_10d11:
  if (memoryAGet(ds, bp + 2) == 0x40)
    goto loc_10d1f;
  memoryASet(ds, 0x01ca, memoryAGet(ds, 0x01ca) | 0x08);
  goto loc_10d24;
loc_10d1f:
  memoryASet(ds, 0x01d5, 0x02);
loc_10d24:
  al = memoryAGet(ds, bp + 3);
  al &= 0x01;
  al += 0x02;
  cl = 0xfe;
  if (memoryAGet(ds, 0x01ca) & 0x08)
    goto loc_10d40;
  cl = 0x02;
  if (memoryAGet(ds, 0x01ca) & 0x04)
    goto loc_10d40;
  cl = 0x00;
loc_10d40:
  al += cl;
  al += memoryAGet(ds, 0x01cf);
  memoryASet(ds, bp + 3, al);
  sub_10f9e();
  memoryASet(ds, 0x01cf, memoryAGet(ds, 0x01cf) ^ 0x06);
  if (!(memoryAGet(ds, 0x01ca) & 0x01))
    goto loc_10d6e;
  if (memoryAGet(ds, bp + 1) >= 0xc0)
    goto loc_10d6e;
  memoryASet(ds, bp + 3, memoryAGet(ds, bp + 3) + 1);
  memoryASet(ds, bp + 3, memoryAGet(ds, bp + 3) & 0x01);
  memoryASet(ds, bp + 1, memoryAGet(ds, bp + 1) + 0x04);
loc_10d6e:
  if (!(memoryAGet(ds, 0x01ca) & 0x02))
    goto loc_10d8a;
  if (memoryAGet(ds, bp + 1) < 0x04)
    goto loc_10d8a;
  memoryASet(ds, bp + 3, memoryAGet(ds, bp + 3) - 1);
  memoryASet(ds, bp + 3, memoryAGet(ds, bp + 3) & 0x01);
  memoryASet(ds, bp + 1, memoryAGet(ds, bp + 1) - 0x04);
loc_10d8a:
  if (!(memoryAGet(ds, 0x01ca) & 0x04))
    goto loc_10d9d;
  if (memoryAGet(ds, bp + 2) >= 0xa8)
    goto loc_10d9d;
  memoryASet(ds, bp + 2, memoryAGet(ds, bp + 2) + 0x02);
loc_10d9d:
  if (!(memoryAGet(ds, 0x01ca) & 0x08))
    goto loc_10db0;
  if (memoryAGet(ds, bp + 2) < 0x3e)
    goto loc_10db0;
  memoryASet(ds, bp + 2, memoryAGet(ds, bp + 2) - 0x02);
loc_10db0:
  if (!(memoryAGet(ds, 0x01ca) & 0x10))
    goto loc_10dea;
  al = memoryAGet(ds, bp + 1);
  ah = memoryAGet(ds, bp + 2);
  bp = 0x002c;
  if (memoryAGet(ds, bp) == 0x01)
    goto loc_10dea;
  al += 0x28;
  memoryASet(ds, bp + 1, al);
  ah += 0x10;
  memoryASet(ds, bp + 2, ah);
  memoryASet(ds, bp, 0x01);
  memoryASet(ds, bp + 3, 0x00);
  ax = 0x1532;
  ds = ax;
  al = 0x03;
  sub_114e7();
loc_10dea:
  ax = 0x1532;
  ds = ax;
}
void sub_10df0()
{
  if (memoryAGet(ds, bp) != 0x01)
    goto loc_10df8;
  return;
loc_10df8:
  if (memoryAGet(ds, 0x01d4) != 0x00)
    goto loc_10e00;
  return;
loc_10e00:
  memoryASet(ds, 0x01d1, memoryAGet(ds, 0x01d1) + 1);
  memoryASet(ds, 0x01d1, memoryAGet(ds, 0x01d1) & 0x1f);
  if (memoryAGet(ds, 0x01d1) == 0)
    goto loc_10e0c;
  return;
loc_10e0c:
  sub_10e3b();
  dl = al;
  al &= 0x01;
  memoryASet(ds, bp + 4, al);
  al = dl;
  al &= 0x0f;
  cl = 0x03;
  al <<= cl;
  al += 0x3e;
  memoryASet(ds, bp + 2, al);
  memoryASet(ds, bp + 1, 0xfc);
  memoryASet(ds, bp + 3, 0x00);
  memoryASet(ds, bp, 0x01);
  memoryASet(ds, bp + 5, 0x00);
}
void sub_10e3b()
{
  push(ds);
  push(cs);
  ds = pop();
  bx = 0;
  al = memoryAGet(ds, 0x0e3a);
  memoryASet(ds, 0x0e3a, memoryAGet(ds, 0x0e3a) + 1);
  al = memory(ds, bx+al);
  ds = pop();
}
void sub_10e4a()
{
  if (memoryAGet(ds, bp) != 0x00)
    goto loc_10e52;
  return;
loc_10e52:
  memoryASet16(ds, 0x01d2, bp);
  if (memoryAGet(ds, bp + 5) == 0x01)
    goto loc_10ea9;
  al = memoryAGet(ds, bp + 1);
  ah = memoryAGet(ds, bp + 2);
  bp = 0x002c;
  if (memoryAGet(ds, bp) == 0x00)
    goto loc_10ea9;
  if (ah > memoryAGet(ds, bp + 2))
    goto loc_10ea9;
  ah += 0x18;
  if (ah < memoryAGet(ds, bp + 2))
    goto loc_10ea9;
  if (al > memoryAGet(ds, bp + 1))
    goto loc_10ea9;
  al += 0x18;
  if (al < memoryAGet(ds, bp + 1))
    goto loc_10ea9;
  memoryASet(ds, bp, 0x00);
  bp = memoryAGet16(ds, 0x01d2);
  memoryASet(ds, bp + 5, 0x01);
  ax = 0x1532;
  ds = ax;
  al = 0x09;
  sub_114e7();
  ax = 0x4c03;
  ds = ax;
loc_10ea9:
  bp = memoryAGet16(ds, 0x01d2);
  if (memoryAGet(ds, bp + 5) == 0x00)
    goto loc_10f16;
  al = memoryAGet(ds, bp + 1);
  ah = memoryAGet(ds, bp + 2);
  bp = 0x0026;
  if (memoryAGet(ds, bp) == 0x00)
    goto loc_10f16;
  cl = memoryAGet(ds, bp + 2);
  cl += 0x1f;
  if (ah > cl)
    goto loc_10f16;
  cl -= 0x0f;
  ah += 0x18;
  if (ah < cl)
    goto loc_10f16;
  cl = memoryAGet(ds, bp + 1);
  cl += 0x40;
  if (al > cl)
    goto loc_10f16;
  cl -= 0x40;
  al += 0x18;
  if (al < cl)
    goto loc_10f16;
  bp = memoryAGet16(ds, 0x01d2);
  memoryASet(ds, bp, 0x00);
  ax = 0x1532;
  ds = ax;
  al = 0x09;
  sub_114e7();
  ax = 0x4c03;
  ds = ax;
  push(ds);
  ax = 0x1532;
  ds = ax;
  bx = 0x0050;
  push(es);
  sub_1242f();
  es = pop();
  ds = pop();
loc_10f16:
  bp = memoryAGet16(ds, 0x01d2);
  if (memoryAGet(ds, 0x01d0) != 0x01)
    goto loc_10f2a;
  memoryASet(ds, bp + 3, memoryAGet(ds, bp + 3) + 1);
  memoryASet(ds, bp + 3, memoryAGet(ds, bp + 3) & 0x07);
loc_10f2a:
  if (memoryAGet(ds, bp + 5) != 0x01)
    goto loc_10f38;
  memoryASet(ds, bp + 3, memoryAGet(ds, bp + 3) | 0x08);
  goto loc_10f3d;
loc_10f38:
  memoryASet(ds, bp + 3, memoryAGet(ds, bp + 3) & 0xf7);
loc_10f3d:
  if (memoryAGet(ds, bp + 5) == 0x01)
    goto loc_10f6b;
  if (memoryAGet(ds, bp + 2) < 0x36)
    goto loc_10f57;
  if (memoryAGet(ds, bp + 2) <= 0xac)
    goto loc_10f5c;
  memoryASet(ds, bp + 2, 0xac);
loc_10f57:
  memoryASet(ds, bp + 4, memoryAGet(ds, bp + 4) ^ 0x01);
loc_10f5c:
  al = 0xff;
  if (memoryAGet(ds, bp + 4) != 0x01)
    goto loc_10f67;
  al = 0x01;
loc_10f67:
  memoryASet(ds, bp + 2, memoryAGet(ds, bp + 2) + al);
loc_10f6b:
  memoryASet(ds, bp + 1, memoryAGet(ds, bp + 1) - 0x04);
  if (!(memoryAGet(ds, bp + 1) & 0x04))
    goto loc_10f7e;
  memoryASet(ds, bp + 3, memoryAGet(ds, bp + 3) | 0x10);
  goto loc_10f83;
loc_10f7e:
  memoryASet(ds, bp + 3, memoryAGet(ds, bp + 3) & 0xef);
loc_10f83:
  if (memoryAGet(ds, bp + 1) < 0x08)
    goto loc_10f8b;
  return;
loc_10f8b:
  memoryASet(ds, bp + 5, 0x00);
  if (memoryAGet(ds, 0x01d4) == 0x00)
    goto loc_10f98;
  return;
loc_10f98:
  memoryASet(ds, bp, 0x00);
}
void sub_10f9e()
{
  if (memoryAGet(ds, bp) != 0x00)
    goto loc_10fa6;
  return;
loc_10fa6:
  al = memoryAGet(ds, bp + 1);
  al >>= 1;
  al >>= 1;
  al >>= 1;
  ah = memoryAGet(ds, bp + 2);
  sub_11132();
  di = ax;
  bx = si;
  al = memoryAGet(ds, bp + 3);
  ah = 0;
  ax <<= 1;
  bx += ax;
  si = memoryAGet16(ds, bx);
  lodsw<MemAuto, DirAuto>();
  cx = ax;
  lodsw<MemAuto, DirAuto>();
  if (ax != 0x0004)
    goto loc_10fd3;
  goto loc_110be;
loc_10fd3:
  dx = ax;
loc_10fd5:
  ax = memoryAGet16(es, di);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 8);
  memoryASet16(es, di, ax);
  ax = memoryAGet16(es, di + 2);
  ax &= memoryAGet16(ds, si + 2);
  ax |= memoryAGet16(ds, si + 10);
  memoryASet16(es, di + 2, ax);
  ax = memoryAGet16(es, di + 4);
  ax &= memoryAGet16(ds, si + 4);
  ax |= memoryAGet16(ds, si + 12);
  memoryASet16(es, di + 4, ax);
  ax = memoryAGet16(es, di + 6);
  ax &= memoryAGet16(ds, si + 6);
  ax |= memoryAGet16(ds, si + 14);
  memoryASet16(es, di + 6, ax);
  ax = memoryAGet16(es, di + 40);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 16);
  memoryASet16(es, di + 40, ax);
  ax = memoryAGet16(es, di + 42);
  ax &= memoryAGet16(ds, si + 2);
  ax |= memoryAGet16(ds, si + 18);
  memoryASet16(es, di + 42, ax);
  ax = memoryAGet16(es, di + 44);
  ax &= memoryAGet16(ds, si + 4);
  ax |= memoryAGet16(ds, si + 20);
  memoryASet16(es, di + 44, ax);
  ax = memoryAGet16(es, di + 46);
  ax &= memoryAGet16(ds, si + 6);
  ax |= memoryAGet16(ds, si + 22);
  memoryASet16(es, di + 46, ax);
  ax = memoryAGet16(es, di + 80);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 24);
  memoryASet16(es, di + 80, ax);
  ax = memoryAGet16(es, di + 82);
  ax &= memoryAGet16(ds, si + 2);
  ax |= memoryAGet16(ds, si + 26);
  memoryASet16(es, di + 82, ax);
  ax = memoryAGet16(es, di + 84);
  ax &= memoryAGet16(ds, si + 4);
  ax |= memoryAGet16(ds, si + 28);
  memoryASet16(es, di + 84, ax);
  ax = memoryAGet16(es, di + 86);
  ax &= memoryAGet16(ds, si + 6);
  ax |= memoryAGet16(ds, si + 30);
  memoryASet16(es, di + 86, ax);
  ax = memoryAGet16(es, di + 120);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 32);
  memoryASet16(es, di + 120, ax);
  ax = memoryAGet16(es, di + 122);
  ax &= memoryAGet16(ds, si + 2);
  ax |= memoryAGet16(ds, si + 34);
  memoryASet16(es, di + 122, ax);
  ax = memoryAGet16(es, di + 124);
  ax &= memoryAGet16(ds, si + 4);
  ax |= memoryAGet16(ds, si + 36);
  memoryASet16(es, di + 124, ax);
  ax = memoryAGet16(es, di + 126);
  ax &= memoryAGet16(ds, si + 6);
  ax |= memoryAGet16(ds, si + 38);
  memoryASet16(es, di + 126, ax);
  si += 0x0028;
  di += 0x00a0;
  if (--cx)
    goto loc_110ba;
  goto loc_110bd;
loc_110ba:
  goto loc_10fd5;
loc_110bd:
  return;
loc_110be:
  ax = memoryAGet16(es, di);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 4);
  memoryASet16(es, di, ax);
  ax = memoryAGet16(es, di + 2);
  ax &= memoryAGet16(ds, si + 2);
  ax |= memoryAGet16(ds, si + 6);
  memoryASet16(es, di + 2, ax);
  ax = memoryAGet16(es, di + 40);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 8);
  memoryASet16(es, di + 40, ax);
  ax = memoryAGet16(es, di + 42);
  ax &= memoryAGet16(ds, si + 2);
  ax |= memoryAGet16(ds, si + 10);
  memoryASet16(es, di + 42, ax);
  ax = memoryAGet16(es, di + 80);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 12);
  memoryASet16(es, di + 80, ax);
  ax = memoryAGet16(es, di + 82);
  ax &= memoryAGet16(ds, si + 2);
  ax |= memoryAGet16(ds, si + 14);
  memoryASet16(es, di + 82, ax);
  ax = memoryAGet16(es, di + 120);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 16);
  memoryASet16(es, di + 120, ax);
  ax = memoryAGet16(es, di + 122);
  ax &= memoryAGet16(ds, si + 2);
  ax |= memoryAGet16(ds, si + 18);
  memoryASet16(es, di + 122, ax);
  si += 0x0014;
  di += 0x00a0;
  if (--cx)
    goto loc_110be;
}
void sub_10fc7()
{
  lodsw<MemAuto, DirAuto>();
  cx = ax;
  lodsw<MemAuto, DirAuto>();
  if (ax != 0x0004)
    goto loc_10fd3;
  goto loc_110be;
loc_10fd3:
  dx = ax;
loc_10fd5:
  ax = memoryAGet16(es, di);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 8);
  memoryASet16(es, di, ax);
  ax = memoryAGet16(es, di + 2);
  ax &= memoryAGet16(ds, si + 2);
  ax |= memoryAGet16(ds, si + 10);
  memoryASet16(es, di + 2, ax);
  ax = memoryAGet16(es, di + 4);
  ax &= memoryAGet16(ds, si + 4);
  ax |= memoryAGet16(ds, si + 12);
  memoryASet16(es, di + 4, ax);
  ax = memoryAGet16(es, di + 6);
  ax &= memoryAGet16(ds, si + 6);
  ax |= memoryAGet16(ds, si + 14);
  memoryASet16(es, di + 6, ax);
  ax = memoryAGet16(es, di + 40);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 16);
  memoryASet16(es, di + 40, ax);
  ax = memoryAGet16(es, di + 42);
  ax &= memoryAGet16(ds, si + 2);
  ax |= memoryAGet16(ds, si + 18);
  memoryASet16(es, di + 42, ax);
  ax = memoryAGet16(es, di + 44);
  ax &= memoryAGet16(ds, si + 4);
  ax |= memoryAGet16(ds, si + 20);
  memoryASet16(es, di + 44, ax);
  ax = memoryAGet16(es, di + 46);
  ax &= memoryAGet16(ds, si + 6);
  ax |= memoryAGet16(ds, si + 22);
  memoryASet16(es, di + 46, ax);
  ax = memoryAGet16(es, di + 80);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 24);
  memoryASet16(es, di + 80, ax);
  ax = memoryAGet16(es, di + 82);
  ax &= memoryAGet16(ds, si + 2);
  ax |= memoryAGet16(ds, si + 26);
  memoryASet16(es, di + 82, ax);
  ax = memoryAGet16(es, di + 84);
  ax &= memoryAGet16(ds, si + 4);
  ax |= memoryAGet16(ds, si + 28);
  memoryASet16(es, di + 84, ax);
  ax = memoryAGet16(es, di + 86);
  ax &= memoryAGet16(ds, si + 6);
  ax |= memoryAGet16(ds, si + 30);
  memoryASet16(es, di + 86, ax);
  ax = memoryAGet16(es, di + 120);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 32);
  memoryASet16(es, di + 120, ax);
  ax = memoryAGet16(es, di + 122);
  ax &= memoryAGet16(ds, si + 2);
  ax |= memoryAGet16(ds, si + 34);
  memoryASet16(es, di + 122, ax);
  ax = memoryAGet16(es, di + 124);
  ax &= memoryAGet16(ds, si + 4);
  ax |= memoryAGet16(ds, si + 36);
  memoryASet16(es, di + 124, ax);
  ax = memoryAGet16(es, di + 126);
  ax &= memoryAGet16(ds, si + 6);
  ax |= memoryAGet16(ds, si + 38);
  memoryASet16(es, di + 126, ax);
  si += 0x0028;
  di += 0x00a0;
  if (--cx)
    goto loc_110ba;
  goto loc_110bd;
loc_110ba:
  goto loc_10fd5;
loc_110bd:
  return;
loc_110be:
  ax = memoryAGet16(es, di);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 4);
  memoryASet16(es, di, ax);
  ax = memoryAGet16(es, di + 2);
  ax &= memoryAGet16(ds, si + 2);
  ax |= memoryAGet16(ds, si + 6);
  memoryASet16(es, di + 2, ax);
  ax = memoryAGet16(es, di + 40);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 8);
  memoryASet16(es, di + 40, ax);
  ax = memoryAGet16(es, di + 42);
  ax &= memoryAGet16(ds, si + 2);
  ax |= memoryAGet16(ds, si + 10);
  memoryASet16(es, di + 42, ax);
  ax = memoryAGet16(es, di + 80);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 12);
  memoryASet16(es, di + 80, ax);
  ax = memoryAGet16(es, di + 82);
  ax &= memoryAGet16(ds, si + 2);
  ax |= memoryAGet16(ds, si + 14);
  memoryASet16(es, di + 82, ax);
  ax = memoryAGet16(es, di + 120);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 16);
  memoryASet16(es, di + 120, ax);
  ax = memoryAGet16(es, di + 122);
  ax &= memoryAGet16(ds, si + 2);
  ax |= memoryAGet16(ds, si + 18);
  memoryASet16(es, di + 122, ax);
  si += 0x0014;
  di += 0x00a0;
  if (--cx)
    goto loc_110be;
}
void sub_11132()
{
  memoryASet(ds, 0x01c8, al);
  bl = ah;
  bh = 0;
  bx <<= 1;
  bx += 0x0038;
  ax = memoryAGet16(ds, bx);
  ax += memoryAGet16(ds, 0x01c8);
  ax += 0x0004;
}
void sub_11149()
{
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  ax = 0xa000;
  es = ax;
  ax = 0x1532;
  ds = ax;
  ds = memoryAGet16(ds, 0x0480);
  bp = 0x0090;
  si = 0x2304;
  di = 0x08c4;
loc_11167:
  al = 0x01;
  out(dx, al);
  cx = 0x0020;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x0008;
  di -= 0x0020;
  ax <<= 1;
  out(dx, al);
  cx = 0x0020;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x0008;
  di -= 0x0020;
  ax <<= 1;
  out(dx, al);
  cx = 0x0020;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x0008;
  di -= 0x0020;
  ax <<= 1;
  out(dx, al);
  cx = 0x0020;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x0008;
  di += 0x0008;
  bp--;
  if (bp != 0)
    goto loc_11167;
  al = 0x0f;
  out(dx, al);
  ax = 0x1532;
  ds = ax;
}
void sub_111ab()
{
  ax = 0x1532;
  ds = ax;
  es = memoryAGet16(ds, 0x0480);
  ax = 0x4c03;
  ds = ax;
  if (memoryAGet(ds, 0x01d4) == 0x00)
    goto loc_11203;
  memoryASet(ds, 0x0002, memoryAGet(ds, 0x0002) - 1);
  memoryASet(ds, 0x0002, memoryAGet(ds, 0x0002) - 1);
  memoryASet(ds, 0x0002, memoryAGet(ds, 0x0002) & 0x1f);
  memoryASet(ds, 0x0003, memoryAGet(ds, 0x0003) - 1);
  memoryASet(ds, 0x0003, memoryAGet(ds, 0x0003) & 0x1f);
  memoryASet(ds, 0x0000, memoryAGet(ds, 0x0000) - 1);
  memoryASet(ds, 0x0000, memoryAGet(ds, 0x0000) & 0x01);
  if (memoryAGet(ds, 0x0000) != 0)
    goto loc_111ea;
  memoryASet(ds, 0x0004, memoryAGet(ds, 0x0004) - 1);
  memoryASet(ds, 0x0004, memoryAGet(ds, 0x0004) & 0x1f);
loc_111ea:
  memoryASet(ds, 0x0001, memoryAGet(ds, 0x0001) - 1);
  memoryASet(ds, 0x0001, memoryAGet(ds, 0x0001) & 0x03);
  if (memoryAGet(ds, 0x0001) != 0x03)
    goto loc_11203;
  memoryASet(ds, 0x0005, memoryAGet(ds, 0x0005) - 1);
  memoryASet(ds, 0x0005, memoryAGet(ds, 0x0005) & 0x1f);
loc_11203:
  di = 0x2304;
  bx = 0x01e0;
  dx = 0x000c;
  al = 0;
  cl = memoryAGet(ds, 0x0002);
  sub_11295();
  bx = 0x01e2;
  dx = 0x0008;
  al = 0;
  cl = memoryAGet(ds, 0x0003);
  sub_11295();
  bx = 0x01e4;
  dx = 0x0008;
  al = memoryAGet(ds, 0x0000);
  cl = memoryAGet(ds, 0x0004);
  sub_11295();
  bx = 0x01e8;
  dx = 0x0004;
  al = memoryAGet(ds, 0x0001);
  cl = memoryAGet(ds, 0x0005);
  sub_11295();
  bx = 0x0200;
  dx = 0x0008;
  al = 0;
  cl = 0;
  sub_11295();
  bx = 0x01f8;
  dx = 0x0004;
  al = memoryAGet(ds, 0x0001);
  cl = memoryAGet(ds, 0x0005);
  sub_11295();
  bx = 0x01f4;
  dx = 0x0008;
  al = memoryAGet(ds, 0x0000);
  cl = memoryAGet(ds, 0x0004);
  sub_11295();
  bx = 0x01f2;
  dx = 0x0008;
  al = 0;
  cl = memoryAGet(ds, 0x0003);
  sub_11295();
  bx = 0x01f0;
  dx = 0x000c;
  al = 0;
  cl = memoryAGet(ds, 0x0002);
  sub_11295();
  ax = 0x1532;
  ds = ax;
}
void sub_11295()
{
  ah = 0;
  ax <<= 1;
  bx += ax;
  si = memoryAGet16(ds, bx);
  memoryASet(ds, 0x01cd, cl);
  al = 0x20;
  al -= cl;
  cl = al;
  memoryASet(ds, 0x01cb, cl);
  di += memoryAGet16(ds, 0x01cd);
loc_112af:
  cx = memoryAGet16(ds, 0x01cb);
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= memoryAGet16(ds, 0x01cb);
  cx = memoryAGet16(ds, 0x01cd);
  di -= cx;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0028;
  cx = memoryAGet16(ds, 0x01cb);
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= memoryAGet16(ds, 0x01cb);
  cx = memoryAGet16(ds, 0x01cd);
  di -= cx;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0028;
  cx = memoryAGet16(ds, 0x01cb);
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= memoryAGet16(ds, 0x01cb);
  cx = memoryAGet16(ds, 0x01cd);
  di -= cx;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0028;
  cx = memoryAGet16(ds, 0x01cb);
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= memoryAGet16(ds, 0x01cb);
  cx = memoryAGet16(ds, 0x01cd);
  di -= cx;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0028;
  cx = memoryAGet16(ds, 0x01cb);
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= memoryAGet16(ds, 0x01cb);
  cx = memoryAGet16(ds, 0x01cd);
  di -= cx;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0028;
  cx = memoryAGet16(ds, 0x01cb);
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= memoryAGet16(ds, 0x01cb);
  cx = memoryAGet16(ds, 0x01cd);
  di -= cx;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0028;
  cx = memoryAGet16(ds, 0x01cb);
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= memoryAGet16(ds, 0x01cb);
  cx = memoryAGet16(ds, 0x01cd);
  di -= cx;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0028;
  cx = memoryAGet16(ds, 0x01cb);
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= memoryAGet16(ds, 0x01cb);
  cx = memoryAGet16(ds, 0x01cd);
  di -= cx;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0028;
  dx--;
  if (dx == 0)
    goto loc_1135d;
  goto loc_112af;
loc_1135d:
  di -= memoryAGet16(ds, 0x01cd);
}
void sub_11367()
{
  goto loc_11367;
loc_11362:
  ax = pop();
  ax = pop();
  goto loc_1517b;
loc_11367:
  if (memoryAGet(ds, 0xe5ba) == 0x01)
    goto loc_11362;
  if (memoryAGet(ds, 0xe5fd) == 0x01)
    goto loc_11376;
  return;
loc_11376:
  sub_1264f();
  if (memoryAGet(ds, 0xe639) != 0x10)
    goto loc_11376;
  return;
  //   gap of 15866 bytes
loc_1517b:
  sub_125fc();
  sub_1509e();
  es = memoryAGet16(ds, 0x0480);
  ah = 0x49;
  interrupt(0x21);
  ax = 0x4c00;
  interrupt(0x21);
  dx = 0x03da;
loc_15191:
  in(al, dx);
  al &= 0x08;
  if (al == 0)
    goto loc_15191;
  dx = 0x03da;
loc_15199:
  in(al, dx);
  al &= 0x08;
  if (al != 0)
    goto loc_15199;
}
void sub_11382()
{
  ax = 0xa000;
  es = ax;
  ax = 0x2ce1;
  ds = ax;
  si = 0x0000;
  sub_113a2();
  cx = 0x01f4;
loc_11395:
  push(cx);
  sub_1518e();
  cx = pop();
  if (--cx)
    goto loc_11395;
  ax = 0x1532;
  ds = ax;
}
void sub_113a2()
{
  ax = 0xa000;
  es = ax;
  ax = 0x0005;
  dx = 0x03ce;
  out(dx, ax);
  di = 0x0000;
  cx = 0x00c8;
loc_113b4:
  push(cx);
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = 0x01;
  out(dx, al);
  cx = 0x0028;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= 0x0028;
  ax <<= 1;
  out(dx, al);
  cx = 0x0028;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= 0x0028;
  ax <<= 1;
  out(dx, al);
  cx = 0x0028;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= 0x0028;
  ax <<= 1;
  out(dx, al);
  cx = 0x0028;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  cx = pop();
  if (--cx)
    goto loc_113b4;
  ax = 0x000f;
  out(dx, al);
}
void sub_113ee()
{
  memoryASet(ds, 0xe2fe, al);
  al = memoryAGet(ds, 0xe2fe);
  bx = 0xe31c;
  ah = 0x09;
  if (!al)
    goto loc_11409;
  bx = 0xe32e;
  ah = 0x01;
  al--;
  if (al == 0)
    goto loc_11409;
  bx = 0xe330;
loc_11409:
  memoryASet16(ds, 0xe2f8, bx);
  memoryASet(ds, 0xe2fc, ah);
  memoryASet(ds, 0xe2fd, 0x01);
}
void sub_113f1()
{
  al = memoryAGet(ds, 0xe2fe);
  bx = 0xe31c;
  ah = 0x09;
  if (!al)
    goto loc_11409;
  bx = 0xe32e;
  ah = 0x01;
  al--;
  if (al == 0)
    goto loc_11409;
  bx = 0xe330;
loc_11409:
  memoryASet16(ds, 0xe2f8, bx);
  memoryASet(ds, 0xe2fc, ah);
  memoryASet(ds, 0xe2fd, 0x01);
}
void sub_11417()
{
  if (memoryAGet(ds, 0xe2fd) == 0x00)
    goto loc_1142f;
loc_1141e:
  memoryASet(ds, 0xe2fd, 0x00);
  si = memoryAGet16(ds, 0xe2f8);
  lodsw<MemAuto, DirAuto>();
  memoryASet16(ds, 0xe2f8, si);
  memoryASet16(ds, 0xe2fa, ax);
loc_1142f:
  bx = memoryAGet16(ds, 0xe2fa);
  al = memoryAGet(ds, bx);
  if (al != 0xff)
    goto loc_1144c;
  memoryASet(ds, 0xe2fc, memoryAGet(ds, 0xe2fc) - 1);
  if (memoryAGet(ds, 0xe2fc) != 0)
    goto loc_1141e;
  flags.carry = true;
  if (memoryAGet(ds, 0xe2fe) != 0)
    goto loc_1149a;
  sub_113f1();
  goto loc_1141e;
loc_1144c:
  bx++;
  memoryASet16(ds, 0xe2fa, bx);
  ah = 0;
  bx = 0xe2fc;
  bx += ax;
  if (memoryAGet(ds, 0x03f1) != 0x00)
    goto loc_1149b;
  ah = memoryAGet(ds, bx);
  al = 0x01;
  al += ah;
  memoryASet(ds, 0xe2ff, al);
  cl = 0x00;
  ch = 0x16;
  bh = ah;
loc_1146e:
  bh--;
  if (bh != 0)
    goto loc_11476;
  al |= 0x02;
  bh = ah;
loc_11476:
  bl--;
  if (bl != 0)
    goto loc_11480;
  al |= 0x02;
  bl = memoryAGet(ds, 0xe2ff);
loc_11480:
  al += 0x08;
  al &= 0xfd;
  push(cx);
  cx = memoryAGet16(ds, 0xe824);
loc_1148b:
  if (--cx)
    goto loc_1148b;
  cx = pop();
  al >>= 1;
  cl--;
  if (cl != 0)
    goto loc_1146e;
  ch--;
  if (ch != 0)
    goto loc_1146e;
  flags.carry = false;
loc_1149a:
  return;
loc_1149b:
  ah = memoryAGet(ds, bx);
  al = 0x01;
  al += ah;
  memoryASet(ds, 0xe2ff, al);
  cl = 0x00;
  ch = 0x16;
  bh = ah;
  in(al, 0x61);
  al &= 0x7c;
loc_114ae:
  bh--;
  if (bh != 0)
    goto loc_114b6;
  al |= 0x02;
  bh = ah;
loc_114b6:
  bl--;
  if (bl != 0)
    goto loc_114c0;
  al |= 0x02;
  bl = memoryAGet(ds, 0xe2ff);
loc_114c0:
  if (!(memoryAGet(ds, 0xe300) & 0x02))
    goto loc_114c9;
  al ^= 0x02;
loc_114c9:
  memoryASet(ds, 0xe300, al);
  out(0x0061, al);
  push(cx);
  cx = memoryAGet16(ds, 0xe824);
loc_114d3:
  if (--cx)
    goto loc_114d3;
  cx = pop();
  cl--;
  if (cl != 0)
    goto loc_114ae;
  ch--;
  if (ch != 0)
    goto loc_114ae;
  flags.carry = false;
}
void sub_114e1()
{
  memoryASet(ds, 0xe42d, 0xff);
}
void sub_114e7()
{
  push(ax);
  push(cx);
  push(bx);
  push(dx);
  if (al >= 0x0d)
    goto loc_11512;
  sub_11517();
  dh = al;
  if (memoryAGet(ds, 0xe42d) == 0xff)
    goto loc_11502;
  al = memoryAGet(ds, 0xe42e);
  if (al < ch)
    goto loc_11512;
loc_11502:
  memoryASet16(ds, 0xe42f, bx);
  memoryASet(ds, 0xe431, cl);
  memoryASet(ds, 0xe42d, dh);
  memoryASet(ds, 0xe42e, ch);
loc_11512:
  dx = pop();
  bx = pop();
  cx = pop();
  ax = pop();
}
void sub_11517()
{
  bl = al;
  bh = 0;
  dx = 0xe432;
  bx += bx;
  bx += dx;
  bx = memoryAGet16(ds, bx);
  ch = memoryAGet(ds, bx);
  bx++;
  cl = memoryAGet(ds, bx);
  bx++;
}
void sub_1152b()
{
  if (memoryAGet(ds, 0x03f1) != 0x00)
    goto loc_11535;
  return;
loc_11535:
  if (memoryAGet(ds, 0xe42d) != 0xff)
    goto loc_1153f;
  return;
loc_1153f:
  bx = memoryAGet16(ds, 0xe42f);
  al = memoryAGet(ds, bx);
  bx++;
  memoryASet16(ds, 0xe42f, bx);
  if (al < 0x80)
    goto loc_11582;
  if (al != 0x80)
    goto loc_11555;
  sub_115b0();
  goto loc_11585;
loc_11555:
  if (al != 0x81)
    goto loc_1155e;
  sub_11592();
  goto loc_11585;
loc_1155e:
  if (al != 0xc8)
    goto loc_11567;
  sub_115ee();
  goto loc_11585;
loc_11567:
  if (al != 0xc9)
    goto loc_11570;
  sub_11655();
  goto loc_11585;
loc_11570:
  if (al != 0xca)
    goto loc_11579;
  sub_1163a();
  goto loc_11585;
loc_11579:
  if (al < 0x82)
    goto loc_1158c;
  sub_115b5();
  goto loc_11585;
loc_11582:
  sub_1165c();
loc_11585:
  memoryASet(ds, 0xe431, memoryAGet(ds, 0xe431) - 1);
  if (memoryAGet(ds, 0xe431) == 0)
    goto loc_1158c;
  return;
loc_1158c:
  memoryASet(ds, 0xe42d, 0xff);
  return;
  //   gap of 194 bytes
}
void sub_11592()
{
  in(al, 0x61);
  al &= 0x7c;
  dl = al;
  ch = 0x12;
  dh = 0x80;
loc_1159c:
  al = dl;
  out(0x0061, al);
  al ^= 0x02;
  dl = al;
  cl = dh;
  stop(/*carry1*/);
  al = rcr(al, cl);
  dh -= 0x03;
  ch--;
  if (ch != 0)
    goto loc_1159c;
}
void sub_115b0()
{
  dx = 0x0143;
  goto loc_115d5;
  //   gap of 32 bytes
loc_115d5:
  in(al, 0x61);
  al &= 0x7c;
  cl = al;
  ch = 0x02;
loc_115dd:
  sub_1169a();
  al ^= dh;
  al += dl;
  al &= 0x02;
  al |= cl;
  out(0x0061, al);
  dx--;
  if (dx != 0)
    goto loc_115dd;
}
void sub_115b5()
{
  in(al, 0x61);
  al &= 0x7c;
  cl = al;
  ch = 0x02;
  bh = al;
  bl = 0;
  bx += 0xe44c;
  dx = 0x0143;
loc_115c8:
  al = memoryAGet(ds, bx);
  al &= 0x02;
  al |= cl;
  out(0x0061, al);
  bx++;
  dx--;
  if (dx != 0)
    goto loc_115c8;
}
void sub_115ee()
{
  sub_1169a();
  dl = al;
  bx = 0x2390;
  cx = 0x007a;
  in(al, 0x61);
  al &= 0x7c;
  dh = al;
loc_115ff:
  al = memoryAGet(ds, bx);
  al &= 0x02;
  al |= dh;
  out(0x0061, al);
  al = bl;
  al += dl;
  bl = al;
  al = memoryAGet(ds, bx);
  al &= 0x02;
  al |= dh;
  out(0x0061, al);
  al = bl;
  al += dl;
  bl = al;
  al = memoryAGet(ds, bx);
  al &= 0x02;
  al |= dh;
  out(0x0061, al);
  al = bl;
  al += dl;
  bl = al;
  al = memoryAGet(ds, bx);
  al &= 0x02;
  al |= dh;
  out(0x0061, al);
  al = bl;
  al += dl;
  bl = al;
  if (--cx)
    goto loc_115ff;
}
void sub_1163a()
{
  al = memoryAGet(ds, 0x03d5);
  al >>= 1;
  al >>= 1;
  if (al < 0x23)
    goto loc_11647;
  al = 0x22;
loc_11647:
  push(ax);
  sub_1169a();
  al &= 0x03;
  ch = al;
  ax = pop();
  al ^= ch;
  goto loc_1165c;
  //   gap of 8 bytes
loc_1165c:
  bl = al;
  bh = 0;
  bx += 0xe49d;
  dx = 0x0148;
  cl = memoryAGet(ds, bx);
  al = 0x02;
  tl = ah;
  ah = al;
  al = tl;
  in(al, 0x61);
  al &= 0x7c;
  ch = al;
  bl = cl;
loc_11675:
  bl--;
  if (bl != 0)
    goto loc_1168b;
  tl = ah;
  ah = al;
  al = tl;
  al ^= 0x02;
  al &= 0x02;
  al |= ch;
  out(0x0061, al);
  tl = ah;
  ah = al;
  al = tl;
  bl = cl;
loc_11687:
  dx--;
  if (dx != 0)
    goto loc_11675;
  return;
loc_1168b:
  al |= 0x00;
  push(cx);
  cx = memoryAGet16(ds, 0xe824);
loc_11692:
  if (--cx)
    goto loc_11692;
  cx = pop();
  goto loc_11687;
}
void sub_11655()
{
  sub_1169a();
  al &= 0x03;
  bl = al;
  bh = 0;
  bx += 0xe49d;
  dx = 0x0148;
  cl = memoryAGet(ds, bx);
  al = 0x02;
  tl = ah;
  ah = al;
  al = tl;
  in(al, 0x61);
  al &= 0x7c;
  ch = al;
  bl = cl;
loc_11675:
  bl--;
  if (bl != 0)
    goto loc_1168b;
  tl = ah;
  ah = al;
  al = tl;
  al ^= 0x02;
  al &= 0x02;
  al |= ch;
  out(0x0061, al);
  tl = ah;
  ah = al;
  al = tl;
  bl = cl;
loc_11687:
  dx--;
  if (dx != 0)
    goto loc_11675;
  return;
loc_1168b:
  al |= 0x00;
  push(cx);
  cx = memoryAGet16(ds, 0xe824);
loc_11692:
  if (--cx)
    goto loc_11692;
  cx = pop();
  goto loc_11687;
}
void sub_1165c()
{
  bl = al;
  bh = 0;
  bx += 0xe49d;
  dx = 0x0148;
  cl = memoryAGet(ds, bx);
  al = 0x02;
  tl = ah;
  ah = al;
  al = tl;
  in(al, 0x61);
  al &= 0x7c;
  ch = al;
  bl = cl;
loc_11675:
  bl--;
  if (bl != 0)
    goto loc_1168b;
  tl = ah;
  ah = al;
  al = tl;
  al ^= 0x02;
  al &= 0x02;
  al |= ch;
  out(0x0061, al);
  tl = ah;
  ah = al;
  al = tl;
  bl = cl;
loc_11687:
  dx--;
  if (dx != 0)
    goto loc_11675;
  return;
loc_1168b:
  al |= 0x00;
  push(cx);
  cx = memoryAGet16(ds, 0xe824);
loc_11692:
  if (--cx)
    goto loc_11692;
  cx = pop();
  goto loc_11687;
}
void sub_1169a()
{
  bx = 0xe4c1;
  memoryASet(ds, 0xe4d1, memoryAGet(ds, 0xe4d1) + 1);
  memoryASet(ds, 0xe4d1, memoryAGet(ds, 0xe4d1) & 0x0f);
  al = memoryAGet(ds, 0xe4d1);
  al = memory(ds, bx+al);
}
void sub_116ac()
{
  memoryASet(ds, 0xe4d2, memoryAGet(ds, 0xe4d2) + 1);
  memoryASet(ds, 0xe4d2, memoryAGet(ds, 0xe4d2) & 0x03);
  if (memoryAGet(ds, 0xe4d2) == 0)
    goto loc_116b8;
  return;
loc_116b8:
  memoryASet(ds, 0xe4d3, memoryAGet(ds, 0xe4d3) + 0x08);
  if (memoryAGet(ds, 0xe4d3) == 0x18)
    goto loc_116c5;
  return;
loc_116c5:
  memoryASet(ds, 0xe4d3, 0x00);
}
void sub_116cb()
{
  if (memoryAGet(ds, 0x03cb) != 0x01)
    goto loc_116d3;
  return;
loc_116d3:
  bx = 0x03f0;
  al = memoryAGet(ds, bx);
  if (!(al & 0x80))
    goto loc_116dd;
  return;
loc_116dd:
  al++;
  memoryASet(ds, bx, al);
  if (al >= 0x05)
    goto loc_116e6;
  return;
loc_116e6:
  memoryASet(ds, bx, 0x00);
  bx = 0x03ee;
  al = memoryAGet(ds, bx);
  al -= 0x01;
  stop(); // das 
  memoryASet(ds, bx, al);
  flags.carry = bx == 0xffff;
  bx++;
  al = memoryAGet(ds, bx);
  al -= flags.carry;
  stop(); // das 
  memoryASet(ds, bx, al);
  if (memoryAGet16(ds, 0x03ee) != 0x0000)
    goto loc_11707;
  memoryASet(ds, 0x03f0, 0xff);
loc_11707:
  goto loc_1172b;
  //   gap of 34 bytes
loc_1172b:
  memoryASet16(ds, 0xe8cb, 0x0012);
  bx = 0x03ef;
  sub_11738();
  bx--;
  al = memoryAGet(ds, bx);
  sub_12d86();
  al = memoryAGet(ds, bx);
  al <<= 1;
  al <<= 1;
  al <<= 1;
  al <<= 1;
  goto loc_12d86;
  //   gap of 5692 bytes
loc_12d86:
  cx = 0xa000;
  es = cx;
  al &= 0xf0;
  al >>= 1;
  ah = 0;
  ax += 0xf166;
  si = ax;
  di = memoryAGet16(ds, 0xe8cb);
  memoryASet16(ds, 0xe8cb, memoryAGet16(ds, 0xe8cb) + 1);
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
}
void sub_11719()
{
  bl = memoryAGet(ds, 0x03d4);
  bl += bl;
  bh = 0;
  bx += 0x1709;
  ax = memoryAGet16(cs, bx);
  memoryASet16(ds, 0x03ee, ax);
  memoryASet16(ds, 0xe8cb, 0x0012);
  bx = 0x03ef;
  sub_11738();
  bx--;
  al = memoryAGet(ds, bx);
  sub_12d86();
  al = memoryAGet(ds, bx);
  al <<= 1;
  al <<= 1;
  al <<= 1;
  al <<= 1;
  goto loc_12d86;
  //   gap of 5692 bytes
loc_12d86:
  cx = 0xa000;
  es = cx;
  al &= 0xf0;
  al >>= 1;
  ah = 0;
  ax += 0xf166;
  si = ax;
  di = memoryAGet16(ds, 0xe8cb);
  memoryASet16(ds, 0xe8cb, memoryAGet16(ds, 0xe8cb) + 1);
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
}
void sub_1172b()
{
  memoryASet16(ds, 0xe8cb, 0x0012);
  bx = 0x03ef;
  sub_11738();
  bx--;
  al = memoryAGet(ds, bx);
  sub_12d86();
  al = memoryAGet(ds, bx);
  al <<= 1;
  al <<= 1;
  al <<= 1;
  al <<= 1;
  goto loc_12d86;
  //   gap of 5692 bytes
loc_12d86:
  cx = 0xa000;
  es = cx;
  al &= 0xf0;
  al >>= 1;
  ah = 0;
  ax += 0xf166;
  si = ax;
  di = memoryAGet16(ds, 0xe8cb);
  memoryASet16(ds, 0xe8cb, memoryAGet16(ds, 0xe8cb) + 1);
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
}
void sub_11738()
{
  al = memoryAGet(ds, bx);
  sub_12d86();
  al = memoryAGet(ds, bx);
  al <<= 1;
  al <<= 1;
  al <<= 1;
  al <<= 1;
  goto loc_12d86;
  //   gap of 5692 bytes
loc_12d86:
  cx = 0xa000;
  es = cx;
  al &= 0xf0;
  al >>= 1;
  ah = 0;
  ax += 0xf166;
  si = ax;
  di = memoryAGet16(ds, 0xe8cb);
  memoryASet16(ds, 0xe8cb, memoryAGet16(ds, 0xe8cb) + 1);
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
}
void sub_1174a()
{
  ax = 0x1532;
  es = ax;
  ds = ax;
  cx = 0x01d8;
  di = 0xf0e6;
  si = di;
loc_11759:
  push(cx);
  lodsb<MemAuto, DirAuto>();
  al >>= 1;
  al |= memoryAGet(ds, si + 65535);
  stosb<MemAuto, DirAuto>();
  cx = pop();
  if (--cx)
    goto loc_11759;
  di = 0xeb7f;
  cx = 0x00c8;
  ax = 0;
loc_1176c:
  stosw<MemAuto, DirAuto>();
  ax += 0x00a0;
  if (--cx)
    goto loc_1176c;
  di = 0xed0f;
  cx = 0x00c8;
  ax = 0;
loc_1177a:
  stosw<MemAuto, DirAuto>();
  ax += 0x0028;
  if (--cx)
    goto loc_1177a;
  cx = 0x0100;
  di = 0x1dd0;
  al = 0;
loc_11788:
  stosb<MemAuto, DirAuto>();
  al++;
  if (--cx)
    goto loc_11788;
}
void sub_1178e()
{
  cl = 0;
  ax = memoryAGet16(ds, 0x046e);
  if (ah != 0x03)
    goto loc_117b0;
  if (al < 0xd8)
    goto loc_117b0;
  ax >>= 1;
  ax >>= 1;
  al += 0x15;
  if (al < memoryAGet(ds, 0x03d5))
    goto loc_117c4;
  al--;
  al -= memoryAGet(ds, 0x03d5);
  goto loc_117c2;
loc_117b0:
  ax >>= 1;
  ax >>= 1;
  al += 0x13;
  if (al < memoryAGet(ds, 0x03d5))
    goto loc_117c4;
  al++;
  al -= memoryAGet(ds, 0x03d5);
loc_117c2:
  cl = al;
loc_117c4:
  al = cl;
  memoryASet(ds, 0x0476, al);
}
void sub_117ca()
{
  dl = memoryAGet(ds, 0x03d4);
  ax = 0x247e;
  es = ax;
  ds = ax;
  bh = dl;
  bh <<= 1;
  bl = 0;
  bx += 0x5ab2;
  si = bx;
  al = dl;
  ah = 0;
  bx = 0x6ac2;
  al = memory(ds, bx+al);
  cx = ax;
  dh = al;
  al = dl;
  al <<= 1;
  ah = 0;
  ax += 0x6ab2;
  push(si);
  si = ax;
  lodsw<MemAuto, DirAuto>();
  ax += 0x5ab2;
  bp = ax;
  si = pop();
  ax = 0x1532;
  es = ax;
  di = 0x055c;
loc_11808:
  push(di);
  sub_11823();
  sub_11823();
  di = pop();
  di++;
  if (--cx)
    goto loc_11808;
  ax = 0x1532;
  ds = ax;
  memoryASet(ds, 0x03d5, dh);
  memoryASet16(ds, 0x0453, 0x055c);
}
void sub_11823()
{
  al = memoryAGet(ds, si);
  si++;
  push(cx);
  cx = 0x0008;
loc_1182a:
    flags.carry = al & 1;
  al = ror(al, 0x01);
  if (flags.carry == 0)
    goto loc_11838;
  push(ax);
  al = memoryAGet(ds, bp);
  bp++;
  memoryASet(es, di, al);
  ax = pop();
loc_11838:
  di += 0x0100;
  if (--cx)
    goto loc_1182a;
  cx = pop();
}
void sub_11840()
{
  ax = 0xa000;
  es = ax;
  cl = memoryAGet(ds, 0x045f);
  dh = cl;
  dl = memoryAGet(ds, 0x0476);
  al = cl;
  al >>= 1;
  ah = 0;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  cx = ax;
  ax <<= 1;
  ax <<= 1;
  ax += cx;
  ax <<= 1;
  ax <<= 1;
  memoryASet16(ds, 0xe4d4, ax);
  cx = memoryAGet16(ds, 0x0480);
  ds = cx;
  si = 0x140b;
  si -= ax;
  di = 0x050b;
  cx = 0x004c;
  al = dl;
  ah = 0;
  if (al)
    goto loc_11888;
  goto loc_11977;
loc_11888:
  al--;
  if (al != 0)
    goto loc_11899;
  dh >>= 1;
  if (dh)
    goto loc_11895;
  goto loc_11977;
loc_11895:
  al = dh;
  goto loc_118a1;
loc_11899:
  al <<= 1;
  al <<= 1;
  dh >>= 1;
  al += dh;
loc_118a1:
  push(si);
  push(ax);
  cx = ax;
  ax = 0x1532;
  ds = ax;
  dl = memoryAGet(ds, 0x0470);
  ax = 0x247e;
  ds = ax;
  al = dl;
  al = ~al;
  al &= 0x07;
  ah = 0;
  ax <<= 1;
  bx = ax;
  si = memoryAGet16(ds, bx);
  bx = si;
  bp = cx;
loc_118c7:
  si = 0x0020;
  if ((short)bp >= (short)0x000c)
    goto loc_118ea;
  si = bx;
  ax = 0x000c;
  ax -= bp;
  ax <<= 1;
  ax <<= 1;
  cx = ax;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax += cx;
  ax <<= 1;
  ax <<= 1;
  si += ax;
loc_118ea:
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = 0x01;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= 0x0012;
  ax <<= 1;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= 0x0012;
  ax <<= 1;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= 0x0012;
  ax <<= 1;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  al = 0x01;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= 0x0012;
  ax <<= 1;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= 0x0012;
  ax <<= 1;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= 0x0012;
  ax <<= 1;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  bp--;
  if (bp == 0)
    goto loc_1194f;
  goto loc_118c7;
loc_1194f:
  ax = 0x1532;
  ds = ax;
  ax = memoryAGet16(ss, 0x0480);
  ds = ax;
  ax = pop();
  si = pop();
  push(ax);
  cl = 0x04;
  ax <<= cl;
  cx = ax;
  ax <<= 1;
  ax <<= 1;
  ax += cx;
  ax <<= 1;
  ax <<= 1;
  si += ax;
  cx = pop();
  ax = 0x004c;
  ax -= cx;
  cx = ax;
loc_11977:
  ax = 0x1532;
  ds = ax;
  dl = memoryAGet(ds, 0x0498);
  dh = memoryAGet(ds, 0x045f);
  ax = memoryAGet16(ds, 0x0480);
  ds = ax;
  if (dl)
    goto loc_11990;
  goto loc_11a3b;
loc_11990:
  dl <<= 1;
  dl <<= 1;
  cl -= dl;
  dh >>= 1;
  cl += dh;
  sub_11a3b();
  di -= 0x000b;
  cl = memoryAGet(ds, 0x0498);
  ch = 0;
  cx <<= 1;
  cx <<= 1;
  si = 0x21d0;
  bp = cx;
loc_119af:
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = 0x01;
  out(dx, al);
  lodsb<MemAuto, DirAuto>();
  memoryASet(es, di, al);
  al = 0x02;
  out(dx, al);
  lodsb<MemAuto, DirAuto>();
  memoryASet(es, di, al);
  al = 0x04;
  out(dx, al);
  lodsb<MemAuto, DirAuto>();
  memoryASet(es, di, al);
  al = 0x08;
  out(dx, al);
  lodsb<MemAuto, DirAuto>();
  memoryASet(es, di, al);
  al = 0x0f;
  out(dx, al);
  ax = 0x0105;
  dx = 0x03ce;
  out(dx, ax);
  al = memoryAGet(es, di);
  cx = 0x0028;
  rep_stosb<MemAuto, DirAuto>();
  ax = 0x0005;
  dx = 0x03ce;
  out(dx, ax);
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = 0x01;
  out(dx, al);
  lodsb<MemAuto, DirAuto>();
  memoryASet(es, di, al);
  al = 0x02;
  out(dx, al);
  lodsb<MemAuto, DirAuto>();
  memoryASet(es, di, al);
  al = 0x04;
  out(dx, al);
  lodsb<MemAuto, DirAuto>();
  memoryASet(es, di, al);
  al = 0x08;
  out(dx, al);
  lodsb<MemAuto, DirAuto>();
  memoryASet(es, di, al);
  al = 0x0f;
  out(dx, al);
  ax = 0x0105;
  dx = 0x03ce;
  out(dx, ax);
  al = memoryAGet(es, di);
  cx = 0x0028;
  rep_stosb<MemAuto, DirAuto>();
  ax = 0x0005;
  dx = 0x03ce;
  out(dx, ax);
  if (di >= 0x1cc0)
    goto loc_11a33;
  bp--;
  if (bp == 0)
    goto loc_11a33;
  goto loc_119af;
loc_11a33:
  ax = 0x0005;
  dx = 0x03ce;
  out(dx, ax);
  return;
loc_11a3b:
  bp = cx;
  dx = 0x03c5;
loc_11a40:
  al = 0x01;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x0016;
  di -= 0x0012;
  ax <<= 1;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x0016;
  di -= 0x0012;
  ax <<= 1;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x0016;
  di -= 0x0012;
  ax <<= 1;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x0016;
  di += 0x0016;
  al = 0x01;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x0016;
  di -= 0x0012;
  ax <<= 1;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x0016;
  di -= 0x0012;
  ax <<= 1;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x0016;
  di -= 0x0012;
  ax <<= 1;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x0016;
  di += 0x0016;
  bp--;
  if (bp != 0)
    goto loc_11a40;
  al = 0x0f;
  out(dx, al);
  ax = 0x1532;
  ds = ax;
}
void sub_11a3b()
{
  bp = cx;
  dx = 0x03c5;
loc_11a40:
  al = 0x01;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x0016;
  di -= 0x0012;
  ax <<= 1;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x0016;
  di -= 0x0012;
  ax <<= 1;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x0016;
  di -= 0x0012;
  ax <<= 1;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x0016;
  di += 0x0016;
  al = 0x01;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x0016;
  di -= 0x0012;
  ax <<= 1;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x0016;
  di -= 0x0012;
  ax <<= 1;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x0016;
  di -= 0x0012;
  ax <<= 1;
  out(dx, al);
  cx = 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x0016;
  di += 0x0016;
  bp--;
  if (bp != 0)
    goto loc_11a40;
  al = 0x0f;
  out(dx, al);
  ax = 0x1532;
  ds = ax;
}
void sub_11abc()
{
  ax = memoryAGet16(ds, 0x0480);
  es = ax;
  dl = memoryAGet(ds, 0x046e);
  dh = memoryAGet(ds, 0x0470);
  ax = 0x247e;
  ds = ax;
  al = dh;
  al = ~al;
  al &= 0x07;
  ah = 0;
  ax <<= 1;
  bx = ax;
  si = memoryAGet16(ds, bx + 16);
  memoryASet16(ds, 0x00b0, si);
  di = 0x140b;
  al = dl;
  al &= 0x07;
  if (al >= 0x04)
    goto loc_11af3;
  di -= 0x0500;
  goto loc_11aff;
loc_11af3:
  di -= 0x0a00;
  cx = 0x000b;
  ax = 0x0012;
  goto loc_11b02;
loc_11aff:
  cx = 0x000a;
loc_11b02:
  bp = cx;
  ax = 0x0009;
loc_11b07:
  si = memoryAGet16(ds, 0x00b0);
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  cx = ax;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0016;
  bp--;
  if (bp == 0)
    goto loc_11cd1;
  goto loc_11b07;
loc_11cd1:
  ax = 0x1532;
  ds = ax;
}
void sub_11cd7()
{
  ax = memoryAGet16(ds, 0x0480);
  es = ax;
  memoryASet16(ds, 0xe4d6, 0x16d6);
  si = 0x155c;
  di = 0x0f0b;
  dx = 0x0014;
loc_11ceb:
  cx = 0x0012;
loc_11cee:
  bx = memoryAGet16(ds, 0xe4d6);
  if (memoryAGet(ds, bx) == 0x00)
    goto loc_11cfc;
  al = memoryAGet(ds, bx);
  goto loc_11da9;
loc_11cfc:
  if (memoryAGet(ds, si) == 0x00)
    goto loc_11d05;
  al = memoryAGet(ds, si);
  goto loc_11d15;
loc_11d05:
  si++;
  memoryASet16(ds, 0xe4d6, memoryAGet16(ds, 0xe4d6) + 1);
  di++;
  if (--cx)
    goto loc_11cee;
  di += 0x04ee;
  dx--;
  if (dx != 0)
    goto loc_11ceb;
  return;
loc_11d15:
  bx = 0x1fd0;
  al = memory(ds, bx+al);
  memoryASet(es, di, memoryAGet(es, di) | al);
  memoryASet(es, di + 40, memoryAGet(es, di + 40) | al);
  memoryASet(es, di + 80, memoryAGet(es, di + 80) | al);
  memoryASet(es, di + 120, memoryAGet(es, di + 120) | al);
  memoryASet(es, di + 320, memoryAGet(es, di + 320) | al);
  memoryASet(es, di + 360, memoryAGet(es, di + 360) | al);
  memoryASet(es, di + 400, memoryAGet(es, di + 400) | al);
  memoryASet(es, di + 440, memoryAGet(es, di + 440) | al);
  memoryASet(es, di + 640, memoryAGet(es, di + 640) | al);
  memoryASet(es, di + 680, memoryAGet(es, di + 680) | al);
  memoryASet(es, di + 720, memoryAGet(es, di + 720) | al);
  memoryASet(es, di + 760, memoryAGet(es, di + 760) | al);
  memoryASet(es, di + 960, memoryAGet(es, di + 960) | al);
  memoryASet(es, di + 1000, memoryAGet(es, di + 1000) | al);
  memoryASet(es, di + 1040, memoryAGet(es, di + 1040) | al);
  memoryASet(es, di + 1080, memoryAGet(es, di + 1080) | al);
  al = memoryAGet(ds, si);
  bx = 0x1dd0;
  al = memory(ds, bx+al);
  memoryASet(es, di + 800, memoryAGet(es, di + 800) | al);
  memoryASet(es, di + 840, memoryAGet(es, di + 840) | al);
  memoryASet(es, di + 880, memoryAGet(es, di + 880) | al);
  memoryASet(es, di + 920, memoryAGet(es, di + 920) | al);
  memoryASet(es, di + 480, memoryAGet(es, di + 480) | al);
  memoryASet(es, di + 520, memoryAGet(es, di + 520) | al);
  memoryASet(es, di + 560, memoryAGet(es, di + 560) | al);
  memoryASet(es, di + 600, memoryAGet(es, di + 600) | al);
  memoryASet(es, di + 160, memoryAGet(es, di + 160) | al);
  memoryASet(es, di + 200, memoryAGet(es, di + 200) | al);
  memoryASet(es, di + 240, memoryAGet(es, di + 240) | al);
  memoryASet(es, di + 280, memoryAGet(es, di + 280) | al);
  goto loc_11d05;
loc_11da9:
  bx = 0x1fd0;
  al = memory(ds, bx+al);
  al = ~al;
  memoryASet(es, di, memoryAGet(es, di) & al);
  memoryASet(es, di + 40, memoryAGet(es, di + 40) & al);
  memoryASet(es, di + 80, memoryAGet(es, di + 80) & al);
  memoryASet(es, di + 120, memoryAGet(es, di + 120) & al);
  memoryASet(es, di + 160, memoryAGet(es, di + 160) & al);
  memoryASet(es, di + 200, memoryAGet(es, di + 200) & al);
  memoryASet(es, di + 240, memoryAGet(es, di + 240) & al);
  memoryASet(es, di + 280, memoryAGet(es, di + 280) & al);
  memoryASet(es, di + 320, memoryAGet(es, di + 320) & al);
  memoryASet(es, di + 360, memoryAGet(es, di + 360) & al);
  memoryASet(es, di + 400, memoryAGet(es, di + 400) & al);
  memoryASet(es, di + 440, memoryAGet(es, di + 440) & al);
  memoryASet(es, di + 480, memoryAGet(es, di + 480) & al);
  memoryASet(es, di + 520, memoryAGet(es, di + 520) & al);
  memoryASet(es, di + 560, memoryAGet(es, di + 560) & al);
  memoryASet(es, di + 600, memoryAGet(es, di + 600) & al);
  memoryASet(es, di + 640, memoryAGet(es, di + 640) & al);
  memoryASet(es, di + 680, memoryAGet(es, di + 680) & al);
  memoryASet(es, di + 720, memoryAGet(es, di + 720) & al);
  memoryASet(es, di + 760, memoryAGet(es, di + 760) & al);
  memoryASet(es, di + 800, memoryAGet(es, di + 800) & al);
  memoryASet(es, di + 840, memoryAGet(es, di + 840) & al);
  memoryASet(es, di + 880, memoryAGet(es, di + 880) & al);
  memoryASet(es, di + 920, memoryAGet(es, di + 920) & al);
  memoryASet(es, di + 960, memoryAGet(es, di + 960) & al);
  memoryASet(es, di + 1000, memoryAGet(es, di + 1000) & al);
  memoryASet(es, di + 1040, memoryAGet(es, di + 1040) & al);
  memoryASet(es, di + 1080, memoryAGet(es, di + 1080) & al);
  memoryASet(es, di + 1120, memoryAGet(es, di + 1120) & al);
  memoryASet(es, di + 1160, memoryAGet(es, di + 1160) & al);
  memoryASet(es, di + 1200, memoryAGet(es, di + 1200) & al);
  memoryASet(es, di + 1240, memoryAGet(es, di + 1240) & al);
  goto loc_11cfc;
}
// skipping indirect jump
void sub_11e4d()
{
  ax = 0x1532;
  es = ax;
  memoryASet(ds, 0x0498, 0x00);
  di = 0x155c;
  cx = 0x017a;
  ax = 0;
  rep_stosw<MemAuto, DirAuto>();
  ax = memoryAGet16(ds, 0x046e);
  if (ax < 0x0190)
    goto loc_11eb2;
  ax = 0;
  sub_11eb2();
  memoryASet(ds, 0x0498, memoryAGet(ds, 0x0498) + 1);
  ax = memoryAGet16(ds, 0x046e);
loc_11e75:
  ax += 0x0004;
  if (ah == 0x04)
    goto loc_11e83;
  memoryASet(ds, 0x0498, memoryAGet(ds, 0x0498) + 1);
  goto loc_11e75;
loc_11e83:
  ax = 0;
  cl = memoryAGet(ds, 0x0498);
  ch = 0;
loc_11e8b:
  tx = dx;
  dx = cx;
  cx = tx;
  cx = 0x00ab;
  di = 0x155c;
  si = 0x156e;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  cx = 0x0009;
  rep_stosw<MemAuto, DirAuto>();
  cx = 0x00ab;
  di = 0x16d6;
  si = 0x16e8;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  cx = 0x0009;
  rep_stosw<MemAuto, DirAuto>();
  tx = dx;
  dx = cx;
  cx = tx;
  if (--cx)
    goto loc_11e8b;
  return;
loc_11eb2:
  ax >>= 1;
  ax >>= 1;
  memoryASet(ds, 0x048f, al);
  ax = memoryAGet16(ds, 0x046e);
  al &= 0x03;
  al <<= 1;
  memoryASet(ds, 0x045f, al);
  al = memoryAGet(ds, 0x0470);
  cl = al;
  al &= 0x07;
  al += 0x58;
  memoryASet(ds, 0x048e, al);
  cl >>= 1;
  cl >>= 1;
  cl >>= 1;
  al = 0x0b;
  al -= cl;
  al &= 0x0f;
  memoryASet(ds, 0x048d, al);
  memoryASet(ds, 0x0490, 0x00);
  memoryASet16(ds, 0x0491, 0xe4d8);
loc_11ee9:
  if (memoryAGet(ds, 0x0490) != 0x08)
    goto loc_11f03;
  di = 0x155f;
  bl = 0x14;
  ax = 0;
loc_11ef7:
  cx = 0x0006;
  rep_stosw<MemAuto, DirAuto>();
  di += 0x0006;
  bl--;
  if (bl != 0)
    goto loc_11ef7;
loc_11f03:
  al = memoryAGet(ds, 0x048f);
  ah = memoryAGet(ds, 0x048d);
  ax += 0x055c;
  memoryASet16(ds, 0x0493, ax);
  al = memoryAGet(ds, 0x048e);
  ah = 0;
  ax += 0x1c50;
  bx = ax;
  al = memoryAGet(ds, bx);
  if (!(al & 0x80))
    goto loc_11f23;
  goto loc_12013;
loc_11f23:
  al >>= 1;
  al >>= 1;
  memoryASet(ds, 0xe55d, al);
  memoryASet(ds, 0xe4f8, al);
  al = memoryAGet(ds, bx);
  al &= 0x03;
  memoryASet(ds, 0xe55c, al);
  memoryASet(ds, 0xe4f9, al);
  al = memoryAGet(ds, 0x048e);
  ah = 0;
  ax += 0x1cd0;
  bx = ax;
  al = memoryAGet(ds, bx);
  if (al & 0x80)
    goto loc_11f4b;
  al >>= 1;
  al >>= 1;
loc_11f4b:
  memoryASet(ds, 0xe55f, al);
  memoryASet(ds, 0xe560, al);
  al = memoryAGet(ds, bx);
  al &= 0x03;
  memoryASet(ds, 0xe55e, al);
  memoryASet(ds, 0xe561, al);
  memoryASet(ds, 0x0495, 0x14);
  si = 0x16b2;
loc_11f63:
  bx = memoryAGet16(ds, 0x0493);
  al = memoryAGet(ds, bx);
  memoryASet16(ds, 0x0493, memoryAGet16(ds, 0x0493) + 1);
  flags.carry = (al + al) >= 0x100;
  al += al;
  if (flags.carry)
    goto loc_11f85;
loc_11f71:
  si -= 0x0012;
  memoryASet(ds, 0x0495, memoryAGet(ds, 0x0495) - 1);
  if (memoryAGet(ds, 0x0495) != 0)
    goto loc_11f63;
  goto loc_12013;
  //   gap of 8 bytes
loc_11f85:
  al = ror(al, 0x01);
  cl = al;
  al &= 0x0c;
  if (al == 0)
    goto loc_11f92;
  if (cl & 0x01)
    goto loc_11fa1;
loc_11f92:
  al = cl;
  al &= 0x03;
  ah = 0;
  bx = ax;
  bx <<= 1;
  stop(/*2*/); // (jmp word ptr cs:[bx + 0x1f7d]) jump Indirect memoryAGet16(cs, bx + 8061)
loc_11fa1:
  al = memoryAGet(ds, 0xe4f8);
  ah = 0;
  if (al & 0x80)
    goto loc_11f71;
  push(si);
  si += ax;
  al = memoryAGet(ds, 0xe4f9);
  if (!al)
    goto loc_11ff3;
  al--;
  if (al == 0)
    goto loc_11fe1;
  al--;
  if (al == 0)
    goto loc_11fcf;
  memoryASet(ds, si + 1, 0x3f);
  memoryASet(ds, si + 2, 0xff);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) & 0x0f);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) | 0xc0);
  si = pop();
  goto loc_11f71;
loc_11fcf:
  memoryASet(ds, si, memoryAGet(ds, si) & 0xfc);
  memoryASet(ds, si + 1, 0xff);
  memoryASet(ds, si + 2, 0xff);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) & 0x3f);
  si = pop();
  goto loc_11f71;
loc_11fe1:
  memoryASet(ds, si, memoryAGet(ds, si) & 0xf0);
  memoryASet(ds, si, memoryAGet(ds, si) | 0x03);
  memoryASet(ds, si + 1, 0xff);
  memoryASet(ds, si + 2, 0xfc);
  si = pop();
  goto loc_11f71;
loc_11ff3:
  memoryASet(ds, si, memoryAGet(ds, si) & 0xc0);
  memoryASet(ds, si, memoryAGet(ds, si) | 0x0f);
  memoryASet(ds, si + 1, 0xff);
  memoryASet(ds, si + 2, memoryAGet(ds, si + 2) & 0x03);
  memoryASet(ds, si + 2, memoryAGet(ds, si + 2) | 0xf0);
  si = pop();
  goto loc_11f71;
  //   gap of 10 bytes
loc_12013:
  al = memoryAGet(ds, 0x048d);
  bx = memoryAGet16(ds, 0x0491);
  al += memoryAGet(ds, bx);
  al &= 0x0f;
  memoryASet(ds, 0x048d, al);
  bx++;
  al = memoryAGet(ds, 0x048e);
  al += memoryAGet(ds, bx);
  al &= 0x7f;
  memoryASet(ds, 0x048e, al);
  bx++;
  memoryASet16(ds, 0x0491, bx);
  memoryASet(ds, 0x0490, memoryAGet(ds, 0x0490) + 1);
  if (memoryAGet(ds, 0x0490) & 0x10)
    return;
  goto loc_11ee9;
}
void sub_11eb2()
{
  ax >>= 1;
  ax >>= 1;
  memoryASet(ds, 0x048f, al);
  ax = memoryAGet16(ds, 0x046e);
  al &= 0x03;
  al <<= 1;
  memoryASet(ds, 0x045f, al);
  al = memoryAGet(ds, 0x0470);
  cl = al;
  al &= 0x07;
  al += 0x58;
  memoryASet(ds, 0x048e, al);
  cl >>= 1;
  cl >>= 1;
  cl >>= 1;
  al = 0x0b;
  al -= cl;
  al &= 0x0f;
  memoryASet(ds, 0x048d, al);
  memoryASet(ds, 0x0490, 0x00);
  memoryASet16(ds, 0x0491, 0xe4d8);
loc_11ee9:
  if (memoryAGet(ds, 0x0490) != 0x08)
    goto loc_11f03;
  di = 0x155f;
  bl = 0x14;
  ax = 0;
loc_11ef7:
  cx = 0x0006;
  rep_stosw<MemAuto, DirAuto>();
  di += 0x0006;
  bl--;
  if (bl != 0)
    goto loc_11ef7;
loc_11f03:
  al = memoryAGet(ds, 0x048f);
  ah = memoryAGet(ds, 0x048d);
  ax += 0x055c;
  memoryASet16(ds, 0x0493, ax);
  al = memoryAGet(ds, 0x048e);
  ah = 0;
  ax += 0x1c50;
  bx = ax;
  al = memoryAGet(ds, bx);
  if (!(al & 0x80))
    goto loc_11f23;
  goto loc_12013;
loc_11f23:
  al >>= 1;
  al >>= 1;
  memoryASet(ds, 0xe55d, al);
  memoryASet(ds, 0xe4f8, al);
  al = memoryAGet(ds, bx);
  al &= 0x03;
  memoryASet(ds, 0xe55c, al);
  memoryASet(ds, 0xe4f9, al);
  al = memoryAGet(ds, 0x048e);
  ah = 0;
  ax += 0x1cd0;
  bx = ax;
  al = memoryAGet(ds, bx);
  if (al & 0x80)
    goto loc_11f4b;
  al >>= 1;
  al >>= 1;
loc_11f4b:
  memoryASet(ds, 0xe55f, al);
  memoryASet(ds, 0xe560, al);
  al = memoryAGet(ds, bx);
  al &= 0x03;
  memoryASet(ds, 0xe55e, al);
  memoryASet(ds, 0xe561, al);
  memoryASet(ds, 0x0495, 0x14);
  si = 0x16b2;
loc_11f63:
  bx = memoryAGet16(ds, 0x0493);
  al = memoryAGet(ds, bx);
  memoryASet16(ds, 0x0493, memoryAGet16(ds, 0x0493) + 1);
  flags.carry = (al + al) >= 0x100;
  al += al;
  if (flags.carry)
    goto loc_11f85;
loc_11f71:
  si -= 0x0012;
  memoryASet(ds, 0x0495, memoryAGet(ds, 0x0495) - 1);
  if (memoryAGet(ds, 0x0495) != 0)
    goto loc_11f63;
  goto loc_12013;
  //   gap of 8 bytes
loc_11f85:
  al = ror(al, 0x01);
  cl = al;
  al &= 0x0c;
  if (al == 0)
    goto loc_11f92;
  if (cl & 0x01)
    goto loc_11fa1;
loc_11f92:
  al = cl;
  al &= 0x03;
  ah = 0;
  bx = ax;
  bx <<= 1;
//    jump #0  1000:2181 12181
//    jump #1  1000:2114 12114
//    jump #2  1000:21dd 121dd
//    jump #3  1000:2009 12009
    switch(memoryAGet16(cs, bx + 0x1f7d))
    {
        case 0x2181: goto loc_12181;
        case 0x2114: goto loc_12114;
        case 0x21dd: goto loc_121dd;
        case 0x2009: goto loc_12009;
        default:
            assert(0);
    }loc_11fa1:
  al = memoryAGet(ds, 0xe4f8);
  ah = 0;
  if (al & 0x80)
    goto loc_11f71;
  push(si);
  si += ax;
  al = memoryAGet(ds, 0xe4f9);
  if (!al)
    goto loc_11ff3;
  al--;
  if (al == 0)
    goto loc_11fe1;
  al--;
  if (al == 0)
    goto loc_11fcf;
  memoryASet(ds, si + 1, 0x3f);
  memoryASet(ds, si + 2, 0xff);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) & 0x0f);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) | 0xc0);
  si = pop();
  goto loc_11f71;
loc_11fcf:
  memoryASet(ds, si, memoryAGet(ds, si) & 0xfc);
  memoryASet(ds, si + 1, 0xff);
  memoryASet(ds, si + 2, 0xff);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) & 0x3f);
  si = pop();
  goto loc_11f71;
loc_11fe1:
  memoryASet(ds, si, memoryAGet(ds, si) & 0xf0);
  memoryASet(ds, si, memoryAGet(ds, si) | 0x03);
  memoryASet(ds, si + 1, 0xff);
  memoryASet(ds, si + 2, 0xfc);
  si = pop();
  goto loc_11f71;
loc_11ff3:
  memoryASet(ds, si, memoryAGet(ds, si) & 0xc0);
  memoryASet(ds, si, memoryAGet(ds, si) | 0x0f);
  memoryASet(ds, si + 1, 0xff);
  memoryASet(ds, si + 2, memoryAGet(ds, si + 2) & 0x03);
  memoryASet(ds, si + 2, memoryAGet(ds, si + 2) | 0xf0);
  si = pop();
  goto loc_11f71;
loc_12009:
  al = memoryAGet(ds, 0x048e);
  if (al < 0x40)
    goto loc_12040;
  goto loc_11f71;
loc_12013:
  al = memoryAGet(ds, 0x048d);
  bx = memoryAGet16(ds, 0x0491);
  al += memoryAGet(ds, bx);
  al &= 0x0f;
  memoryASet(ds, 0x048d, al);
  bx++;
  al = memoryAGet(ds, 0x048e);
  al += memoryAGet(ds, bx);
  al &= 0x7f;
  memoryASet(ds, 0x048e, al);
  bx++;
  memoryASet16(ds, 0x0491, bx);
  memoryASet(ds, 0x0490, memoryAGet(ds, 0x0490) + 1);
  if (memoryAGet(ds, 0x0490) & 0x10)
    goto loc_1203f;
  goto loc_11ee9;
loc_1203f:
  return;
loc_12040:
  ah = 0;
  memoryASet16(ds, 0x0496, ax);
  ax += 0x1d50;
  di = ax;
  al = memoryAGet(ds, di);
  al += 0x03;
  ah = 0;
  ax += si;
  memoryASet16(ds, 0xe55a, ax);
  ax = memoryAGet16(ds, 0x0496);
  ax += 0x1d90;
  di = ax;
  al = memoryAGet(ds, di);
  if (!(al & 0x80))
    goto loc_12092;
  al &= 0x0f;
  al <<= 1;
  ah = 0;
  ax += 0xe4fa;
  di = ax;
  push(si);
  si = memoryAGet16(ds, 0xe55a);
  al = memoryAGet(ds, si);
  al &= memoryAGet(ds, di);
  al |= memoryAGet(ds, di + 1);
  memoryASet(ds, si, al);
  di += 0x0020;
  si += 0x017a;
  al = memoryAGet(ds, si);
  al |= memoryAGet(ds, di + 1);
  memoryASet(ds, si, al);
  si -= 0x017a;
  si = pop();
  goto loc_11f71;
loc_12092:
  push(si);
  cl = al;
  al &= 0x03;
  al <<= 1;
  ah = 0;
  ax += 0xe53a;
  di = ax;
  si = memoryAGet16(ds, 0xe55a);
  al = memoryAGet(ds, si);
  al &= memoryAGet(ds, di);
  al |= memoryAGet(ds, di + 1);
  memoryASet(ds, si, al);
  si += 0x017a;
  al |= memoryAGet(ds, di + 9);
  memoryASet(ds, si, al);
  si -= 0x0179;
  al = cl;
  al &= 0x30;
  if (al == 0)
    goto loc_120ef;
  tl = al;
  al = 0x00;
  if (stop(/*jb*/))
    goto loc_120e2;
  if (tl == 0)
    goto loc_120d5;
  memoryASet(ds, si, al);
  si += 0x017a;
  memoryASet(ds, si, 0xff);
  si -= 0x0179;
loc_120d5:
  memoryASet(ds, si, al);
  si += 0x017a;
  memoryASet(ds, si, 0xff);
  si -= 0x0179;
loc_120e2:
  memoryASet(ds, si, al);
  si += 0x017a;
  memoryASet(ds, si, 0xff);
  si -= 0x0179;
loc_120ef:
  al = cl;
  al = ror(al, 0x01);
  al &= 0x06;
  ah = 0;
  ax += 0xe54a;
  di = ax;
  al = memoryAGet(ds, si);
  al &= memoryAGet(ds, di);
  al |= memoryAGet(ds, di + 1);
  memoryASet(ds, si, al);
  si += 0x017a;
  al = memoryAGet(ds, si);
  al |= memoryAGet(ds, di + 9);
  memoryASet(ds, si, al);
  si = pop();
  goto loc_11f71;
loc_12114:
  push(si);
  al = memoryAGet(ds, 0xe55d);
  ah = 0;
  si += ax;
  al = memoryAGet(ds, 0xe55c);
  if (!al)
    goto loc_12142;
  al--;
  if (al == 0)
    goto loc_12151;
  al--;
  if (al == 0)
    goto loc_12167;
  memoryASet(ds, si, memoryAGet(ds, si) & 0xfc);
  memoryASet(ds, si + 1, 0x6f);
  memoryASet(ds, si + 2, 0xee);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) & 0x03);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) | 0x90);
  si = pop();
  goto loc_11f71;
loc_12142:
  memoryASet(ds, si, 0x1b);
  memoryASet(ds, si + 1, 0xfb);
  memoryASet(ds, si + 2, 0xa4);
  si = pop();
  goto loc_11f71;
loc_12151:
  memoryASet(ds, si, memoryAGet(ds, si) & 0xc0);
  memoryASet(ds, si, memoryAGet(ds, si) | 0x06);
  memoryASet(ds, si + 1, 0xfe);
  memoryASet(ds, si + 2, 0xe9);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) & 0x3f);
  si = pop();
  goto loc_11f71;
loc_12167:
  memoryASet(ds, si, memoryAGet(ds, si) & 0xf0);
  memoryASet(ds, si, memoryAGet(ds, si) | 0x01);
  memoryASet(ds, si + 1, 0xbf);
  memoryASet(ds, si + 2, 0xba);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) & 0x0f);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) | 0x40);
  si = pop();
  goto loc_11f71;
loc_12181:
  al = memoryAGet(ds, 0xe55f);
  ah = 0;
  if (!(al & 0x80))
    goto loc_1218d;
  goto loc_11f71;
loc_1218d:
  push(si);
  si += ax;
  al = memoryAGet(ds, 0xe55e);
  if (!al)
    goto loc_121ce;
  al--;
  if (al == 0)
    goto loc_121bc;
  al--;
  if (al == 0)
    goto loc_121ae;
  memoryASet(ds, si, memoryAGet(ds, si) & 0xfc);
  memoryASet(ds, si + 1, 0xbe);
  memoryASet(ds, si + 2, memoryAGet(ds, si + 2) & 0x3f);
  si = pop();
  goto loc_11f71;
loc_121ae:
  memoryASet(ds, si, memoryAGet(ds, si) & 0xf0);
  memoryASet(ds, si, memoryAGet(ds, si) | 0x02);
  memoryASet(ds, si + 1, 0xf8);
  si = pop();
  goto loc_11f71;
loc_121bc:
  memoryASet(ds, si, memoryAGet(ds, si) & 0xc0);
  memoryASet(ds, si, memoryAGet(ds, si) | 0x0b);
  memoryASet(ds, si + 1, memoryAGet(ds, si + 1) & 0x03);
  memoryASet(ds, si + 1, memoryAGet(ds, si + 1) | 0xe0);
  si = pop();
  goto loc_11f71;
loc_121ce:
  memoryASet(ds, si, 0x2f);
  memoryASet(ds, si + 1, memoryAGet(ds, si + 1) & 0x0f);
  memoryASet(ds, si + 1, memoryAGet(ds, si + 1) | 0x80);
  si = pop();
  goto loc_11f71;
loc_121dd:
  al = memoryAGet(ds, 0xe560);
  ah = 0;
  if (!(al & 0x80))
    goto loc_121e9;
  goto loc_11f71;
loc_121e9:
  push(si);
  si += ax;
  al = memoryAGet(ds, 0xe561);
  if (!al)
    goto loc_1224f;
  al--;
  if (al == 0)
    goto loc_12230;
  al--;
  if (al == 0)
    goto loc_12216;
  al = memoryAGet(ds, 0xe4d3);
  ax += 0xe568;
  bx = ax;
  al = memoryAGet(ds, si);
  al &= 0xfc;
  memoryASet(ds, si, al);
  al = memoryAGet(ds, bx);
  memoryASet(ds, si + 1, al);
  memoryASet(ds, si + 2, memoryAGet(ds, si + 2) & 0x3f);
  si = pop();
  goto loc_11f71;
loc_12216:
  al = memoryAGet(ds, 0xe4d3);
  ax += 0xe566;
  bx = ax;
  al = memoryAGet(ds, si);
  al &= 0xf0;
  al |= memoryAGet(ds, bx);
  memoryASet(ds, si, al);
  al = memoryAGet(ds, bx + 1);
  memoryASet(ds, si + 1, al);
  si = pop();
  goto loc_11f71;
loc_12230:
  al = memoryAGet(ds, 0xe4d3);
  ax += 0xe564;
  bx = ax;
  al = memoryAGet(ds, si);
  al &= 0xc0;
  al |= memoryAGet(ds, bx);
  memoryASet(ds, si, al);
  al = memoryAGet(ds, si + 1);
  al &= 0x03;
  al |= memoryAGet(ds, bx + 1);
  memoryASet(ds, si + 1, al);
  si = pop();
  goto loc_11f71;
loc_1224f:
  al = memoryAGet(ds, 0xe4d3);
  ax += 0xe562;
  bx = ax;
  al = memoryAGet(ds, bx);
  memoryASet(ds, si, al);
  al = memoryAGet(ds, si + 1);
  al &= 0x0f;
  al |= memoryAGet(ds, bx + 1);
  memoryASet(ds, si + 1, al);
  si = pop();
  goto loc_11f71;
}
/*
void sub_11eb2()
{
  ax >>= 1;
  ax >>= 1;
  memoryASet(ds, 0x048f, al);
  ax = memoryAGet16(ds, 0x046e);
  al &= 0x03;
  al <<= 1;
  memoryASet(ds, 0x045f, al);
  al = memoryAGet(ds, 0x0470);
  cl = al;
  al &= 0x07;
  al += 0x58;
  memoryASet(ds, 0x048e, al);
  cl >>= 1;
  cl >>= 1;
  cl >>= 1;
  al = 0x0b;
  al -= cl;
  al &= 0x0f;
  memoryASet(ds, 0x048d, al);
  memoryASet(ds, 0x0490, 0x00);
  memoryASet16(ds, 0x0491, 0xe4d8);
loc_11ee9:
  if (memoryAGet(ds, 0x0490) != 0x08)
    goto loc_11f03;
  di = 0x155f;
  bl = 0x14;
  ax = 0;
loc_11ef7:
  cx = 0x0006;
  rep_stosw<MemAuto, DirAuto>();
  di += 0x0006;
  bl--;
  if (bl != 0)
    goto loc_11ef7;
loc_11f03:
  al = memoryAGet(ds, 0x048f);
  ah = memoryAGet(ds, 0x048d);
  ax += 0x055c;
  memoryASet16(ds, 0x0493, ax);
  al = memoryAGet(ds, 0x048e);
  ah = 0;
  ax += 0x1c50;
  bx = ax;
  al = memoryAGet(ds, bx);
  if (!(al & 0x80))
    goto loc_11f23;
  goto loc_12013;
loc_11f23:
  al >>= 1;
  al >>= 1;
  memoryASet(ds, 0xe55d, al);
  memoryASet(ds, 0xe4f8, al);
  al = memoryAGet(ds, bx);
  al &= 0x03;
  memoryASet(ds, 0xe55c, al);
  memoryASet(ds, 0xe4f9, al);
  al = memoryAGet(ds, 0x048e);
  ah = 0;
  ax += 0x1cd0;
  bx = ax;
  al = memoryAGet(ds, bx);
  if (al & 0x80)
    goto loc_11f4b;
  al >>= 1;
  al >>= 1;
loc_11f4b:
  memoryASet(ds, 0xe55f, al);
  memoryASet(ds, 0xe560, al);
  al = memoryAGet(ds, bx);
  al &= 0x03;
  memoryASet(ds, 0xe55e, al);
  memoryASet(ds, 0xe561, al);
  memoryASet(ds, 0x0495, 0x14);
  si = 0x16b2;
loc_11f63:
  bx = memoryAGet16(ds, 0x0493);
  al = memoryAGet(ds, bx);
  memoryASet16(ds, 0x0493, memoryAGet16(ds, 0x0493) + 1);
  flags.carry = (al + al) >= 0x100;
  al += al;
  if (flags.carry)
    goto loc_11f85;
loc_11f71:
  si -= 0x0012;
  memoryASet(ds, 0x0495, memoryAGet(ds, 0x0495) - 1);
  if (memoryAGet(ds, 0x0495) != 0)
    goto loc_11f63;
  goto loc_12013;
  //   gap of 8 bytes
loc_11f85:
  al = ror(al, 0x01);
  cl = al;
  al &= 0x0c;
  if (al == 0)
    goto loc_11f92;
  if (cl & 0x01)
    goto loc_11fa1;
loc_11f92:
  al = cl;
  al &= 0x03;
  ah = 0;
  bx = ax;
    bx <<= 1;
    jump #0  1000:2181 12181
    jump #1  1000:2114 12114
    jump #2  1000:21dd 121dd
    jump #3  1000:2009 12009
    switch(memoryAGet16(cs, bx + 0x1f7d))
    {
        case 0x2181: goto loc_12181;
        case 0x2114: goto loc_12114;
        case 0x21dd: goto loc_121dd;
        case 0x2009: goto loc_12009;
        default:
            assert(0);
    }
//  stop(2); // (jmp word ptr cs:[bx + 0x1f7d]) jump Indirect memoryAGet16(cs, bx + 8061)
loc_11fa1:
  al = memoryAGet(ds, 0xe4f8);
  ah = 0;
  if (al & 0x80)
    goto loc_11f71;
  push(si);
  si += ax;
  al = memoryAGet(ds, 0xe4f9);
  if (!al)
    goto loc_11ff3;
  al--;
  if (al == 0)
    goto loc_11fe1;
  al--;
  if (al == 0)
    goto loc_11fcf;
  memoryASet(ds, si + 1, 0x3f);
  memoryASet(ds, si + 2, 0xff);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) & 0x0f);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) | 0xc0);
  si = pop();
  goto loc_11f71;
loc_11fcf:
  memoryASet(ds, si, memoryAGet(ds, si) & 0xfc);
  memoryASet(ds, si + 1, 0xff);
  memoryASet(ds, si + 2, 0xff);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) & 0x3f);
  si = pop();
  goto loc_11f71;
loc_11fe1:
  memoryASet(ds, si, memoryAGet(ds, si) & 0xf0);
  memoryASet(ds, si, memoryAGet(ds, si) | 0x03);
  memoryASet(ds, si + 1, 0xff);
  memoryASet(ds, si + 2, 0xfc);
  si = pop();
  goto loc_11f71;
loc_11ff3:
  memoryASet(ds, si, memoryAGet(ds, si) & 0xc0);
  memoryASet(ds, si, memoryAGet(ds, si) | 0x0f);
  memoryASet(ds, si + 1, 0xff);
  memoryASet(ds, si + 2, memoryAGet(ds, si + 2) & 0x03);
  memoryASet(ds, si + 2, memoryAGet(ds, si + 2) | 0xf0);
  si = pop();
  goto loc_11f71;
  al = memoryAGet(ds, 0x048e);
  if (al < 0x40)
    goto loc_12040;
  goto loc_11f71;
loc_12013:
  al = memoryAGet(ds, 0x048d);
  bx = memoryAGet16(ds, 0x0491);
  al += memoryAGet(ds, bx);
  al &= 0x0f;
  memoryASet(ds, 0x048d, al);
  bx++;
  al = memoryAGet(ds, 0x048e);
  al += memoryAGet(ds, bx);
  al &= 0x7f;
  memoryASet(ds, 0x048e, al);
  bx++;
  memoryASet16(ds, 0x0491, bx);
  memoryASet(ds, 0x0490, memoryAGet(ds, 0x0490) + 1);
  if (memoryAGet(ds, 0x0490) & 0x10)
    goto loc_1203f;
  goto loc_11ee9;
loc_1203f:
  return;
loc_12040:
  ah = 0;
  memoryASet16(ds, 0x0496, ax);
  ax += 0x1d50;
  di = ax;
  al = memoryAGet(ds, di);
  al += 0x03;
  ah = 0;
  ax += si;
  memoryASet16(ds, 0xe55a, ax);
  ax = memoryAGet16(ds, 0x0496);
  ax += 0x1d90;
  di = ax;
  al = memoryAGet(ds, di);
  if (!(al & 0x80))
    goto loc_12092;
  al &= 0x0f;
  al <<= 1;
  ah = 0;
  ax += 0xe4fa;
  di = ax;
  push(si);
  si = memoryAGet16(ds, 0xe55a);
  al = memoryAGet(ds, si);
  al &= memoryAGet(ds, di);
  al |= memoryAGet(ds, di + 1);
  memoryASet(ds, si, al);
  di += 0x0020;
  si += 0x017a;
  al = memoryAGet(ds, si);
  al |= memoryAGet(ds, di + 1);
  memoryASet(ds, si, al);
  si -= 0x017a;
  si = pop();
  goto loc_11f71;
loc_12092:
  push(si);
  cl = al;
  al &= 0x03;
  al <<= 1;
  ah = 0;
  ax += 0xe53a;
  di = ax;
  si = memoryAGet16(ds, 0xe55a);
  al = memoryAGet(ds, si);
  al &= memoryAGet(ds, di);
  al |= memoryAGet(ds, di + 1);
  memoryASet(ds, si, al);
  si += 0x017a;
  al |= memoryAGet(ds, di + 9);
  memoryASet(ds, si, al);
  si -= 0x0179;
  al = cl;
  al &= 0x30;
  if (al == 0)
    goto loc_120ef;
  tl = al;
  al = 0x00;
  if (stop(jb))
    goto loc_120e2;
  if (tl == 0)
    goto loc_120d5;
  memoryASet(ds, si, al);
  si += 0x017a;
  memoryASet(ds, si, 0xff);
  si -= 0x0179;
loc_120d5:
  memoryASet(ds, si, al);
  si += 0x017a;
  memoryASet(ds, si, 0xff);
  si -= 0x0179;
loc_120e2:
  memoryASet(ds, si, al);
  si += 0x017a;
  memoryASet(ds, si, 0xff);
  si -= 0x0179;
loc_120ef:
  al = cl;
  al = ror(al, 0x01);
  al &= 0x06;
  ah = 0;
  ax += 0xe54a;
  di = ax;
  al = memoryAGet(ds, si);
  al &= memoryAGet(ds, di);
  al |= memoryAGet(ds, di + 1);
  memoryASet(ds, si, al);
  si += 0x017a;
  al = memoryAGet(ds, si);
  al |= memoryAGet(ds, di + 9);
  memoryASet(ds, si, al);
  si = pop();
  goto loc_11f71;
  push(si);
  al = memoryAGet(ds, 0xe55d);
  ah = 0;
  si += ax;
  al = memoryAGet(ds, 0xe55c);
  if (!al)
    goto loc_12142;
  al--;
  if (al == 0)
    goto loc_12151;
  al--;
  if (al == 0)
    goto loc_12167;
  memoryASet(ds, si, memoryAGet(ds, si) & 0xfc);
  memoryASet(ds, si + 1, 0x6f);
  memoryASet(ds, si + 2, 0xee);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) & 0x03);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) | 0x90);
  si = pop();
  goto loc_11f71;
loc_12142:
  memoryASet(ds, si, 0x1b);
  memoryASet(ds, si + 1, 0xfb);
  memoryASet(ds, si + 2, 0xa4);
  si = pop();
  goto loc_11f71;
loc_12151:
  memoryASet(ds, si, memoryAGet(ds, si) & 0xc0);
  memoryASet(ds, si, memoryAGet(ds, si) | 0x06);
  memoryASet(ds, si + 1, 0xfe);
  memoryASet(ds, si + 2, 0xe9);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) & 0x3f);
  si = pop();
  goto loc_11f71;
loc_12167:
  memoryASet(ds, si, memoryAGet(ds, si) & 0xf0);
  memoryASet(ds, si, memoryAGet(ds, si) | 0x01);
  memoryASet(ds, si + 1, 0xbf);
  memoryASet(ds, si + 2, 0xba);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) & 0x0f);
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) | 0x40);
  si = pop();
  goto loc_11f71;
  al = memoryAGet(ds, 0xe55f);
  ah = 0;
  if (!(al & 0x80))
    goto loc_1218d;
  goto loc_11f71;
loc_1218d:
  push(si);
  si += ax;
  al = memoryAGet(ds, 0xe55e);
  if (!al)
    goto loc_121ce;
  al--;
  if (al == 0)
    goto loc_121bc;
  al--;
  if (al == 0)
    goto loc_121ae;
  memoryASet(ds, si, memoryAGet(ds, si) & 0xfc);
  memoryASet(ds, si + 1, 0xbe);
  memoryASet(ds, si + 2, memoryAGet(ds, si + 2) & 0x3f);
  si = pop();
  goto loc_11f71;
loc_121ae:
  memoryASet(ds, si, memoryAGet(ds, si) & 0xf0);
  memoryASet(ds, si, memoryAGet(ds, si) | 0x02);
  memoryASet(ds, si + 1, 0xf8);
  si = pop();
  goto loc_11f71;
loc_121bc:
  memoryASet(ds, si, memoryAGet(ds, si) & 0xc0);
  memoryASet(ds, si, memoryAGet(ds, si) | 0x0b);
  memoryASet(ds, si + 1, memoryAGet(ds, si + 1) & 0x03);
  memoryASet(ds, si + 1, memoryAGet(ds, si + 1) | 0xe0);
  si = pop();
  goto loc_11f71;
loc_121ce:
  memoryASet(ds, si, 0x2f);
  memoryASet(ds, si + 1, memoryAGet(ds, si + 1) & 0x0f);
  memoryASet(ds, si + 1, memoryAGet(ds, si + 1) | 0x80);
  si = pop();
  goto loc_11f71;
  al = memoryAGet(ds, 0xe560);
  ah = 0;
  if (!(al & 0x80))
    goto loc_121e9;
  goto loc_11f71;
loc_121e9:
  push(si);
  si += ax;
  al = memoryAGet(ds, 0xe561);
  if (!al)
    goto loc_1224f;
  al--;
  if (al == 0)
    goto loc_12230;
  al--;
  if (al == 0)
    goto loc_12216;
  al = memoryAGet(ds, 0xe4d3);
  ax += 0xe568;
  bx = ax;
  al = memoryAGet(ds, si);
  al &= 0xfc;
  memoryASet(ds, si, al);
  al = memoryAGet(ds, bx);
  memoryASet(ds, si + 1, al);
  memoryASet(ds, si + 2, memoryAGet(ds, si + 2) & 0x3f);
  si = pop();
  goto loc_11f71;
loc_12216:
  al = memoryAGet(ds, 0xe4d3);
  ax += 0xe566;
  bx = ax;
  al = memoryAGet(ds, si);
  al &= 0xf0;
  al |= memoryAGet(ds, bx);
  memoryASet(ds, si, al);
  al = memoryAGet(ds, bx + 1);
  memoryASet(ds, si + 1, al);
  si = pop();
  goto loc_11f71;
loc_12230:
  al = memoryAGet(ds, 0xe4d3);
  ax += 0xe564;
  bx = ax;
  al = memoryAGet(ds, si);
  al &= 0xc0;
  al |= memoryAGet(ds, bx);
  memoryASet(ds, si, al);
  al = memoryAGet(ds, si + 1);
  al &= 0x03;
  al |= memoryAGet(ds, bx + 1);
  memoryASet(ds, si + 1, al);
  si = pop();
  goto loc_11f71;
loc_1224f:
  al = memoryAGet(ds, 0xe4d3);
  ax += 0xe562;
  bx = ax;
  al = memoryAGet(ds, bx);
  memoryASet(ds, si, al);
  al = memoryAGet(ds, si + 1);
  al &= 0x0f;
  al |= memoryAGet(ds, bx + 1);
  memoryASet(ds, si + 1, al);
  si = pop();
  goto loc_11f71;
}*/
void sub_1226a()
{
  ax = 0xa000;
  es = ax;
  al = memoryAGet(ds, 0x0470);
  memoryASet(ds, 0xe57a, al);
  memoryASet(ds, 0xe57f, al);
  cl = 0x20;
  al = memoryAGet(ds, 0x046e);
  if (!(al & 0x04))
    goto loc_12287;
  cl = 0x28;
  memoryASet(ds, 0x0476, memoryAGet(ds, 0x0476) - 1);
loc_12287:
  al &= 0x03;
  al <<= 1;
  al += cl;
  cl = al;
  memoryASet(ds, 0xe57b, al);
  al = memoryAGet(ds, 0x046e);
  al = ror(al, 0x01);
  al = ror(al, 0x01);
  al = ror(al, 0x01);
  al ^= 0x0f;
  al &= 0x0f;
  ah = 0;
  ax += 0xe582;
  memoryASet16(ds, 0xe57d, ax);
  memoryASet16(ds, 0x0496, ax);
  memoryASet(ds, 0xe581, cl);
  al = memoryAGet(ds, 0x0476);
  memoryASet(ds, 0x0495, al);
  cx = 0x000a;
loc_122b7:
  if (cx == 0x000a)
    goto loc_122fc;
  bx = memoryAGet16(ds, 0x0496);
  al = memoryAGet(ds, bx);
  al -= memoryAGet(ds, 0xe57f);
  al &= 0x3f;
  if (al >= 0x24)
    goto loc_122fc;
  if (!(memoryAGet(ds, 0x0495) & 0x80))
    goto loc_122db;
  if (al < 0x0c)
    goto loc_122db;
  if (al < 0x18)
    goto loc_122fc;
loc_122db:
  al += 0x02;
  ah = memoryAGet(ds, 0xe581);
  sub_14e2e();
  si = ax;
  if (memoryAGet(es, si) != 0x00)
    goto loc_122fc;
  memoryASet(es, si, 0x18);
  if (memoryAGet(es, si + 40) != 0x00)
    goto loc_122fc;
  memoryASet(es, si + 40, 0x18);
loc_122fc:
  memoryASet16(ds, 0x0496, memoryAGet16(ds, 0x0496) + 1);
  memoryASet(ds, 0xe581, memoryAGet(ds, 0xe581) + 0x10);
  if (memoryAGet(ds, 0xe581) >= 0xb8)
    return;
  memoryASet(ds, 0x0495, memoryAGet(ds, 0x0495) - 1);
  memoryASet(ds, 0x0495, memoryAGet(ds, 0x0495) - 1);
  if (--cx)
    goto loc_122b7;
}
void sub_12317()
{
  ax = 0xa000;
  es = ax;
  ax = memoryAGet16(ds, 0xe57d);
  memoryASet16(ds, 0x0496, ax);
  al = memoryAGet(ds, 0xe57b);
  memoryASet(ds, 0xe581, al);
  cx = 0x000a;
  al = memoryAGet(ds, 0xe57a);
  memoryASet(ds, 0xe580, al);
loc_12331:
  bx = memoryAGet16(ds, 0x0496);
  al = memoryAGet(ds, bx);
  al -= memoryAGet(ds, 0xe580);
  al &= 0x3f;
  if (al >= 0x24)
    goto loc_12362;
  al += 0x02;
  ah = memoryAGet(ds, 0xe581);
  sub_14e2e();
  si = ax;
  if (memoryAGet(es, si) != 0x18)
    goto loc_12362;
  memoryASet(es, si, 0x00);
  if (memoryAGet(es, si + 40) != 0x18)
    goto loc_12362;
  memoryASet(es, si + 40, 0x00);
loc_12362:
  memoryASet16(ds, 0x0496, memoryAGet16(ds, 0x0496) + 1);
  memoryASet(ds, 0xe581, memoryAGet(ds, 0xe581) + 0x10);
  if (memoryAGet(ds, 0xe581) >= 0xb8)
    return;
  if (--cx)
    goto loc_12331;
}
void sub_12375()
{
  ax = memoryAGet16(ds, 0x03ae);
  flags.carry = al < 0x28;
  al -= 0x28;
  ah -= flags.carry;
  ah &= 0x03;
  bl = 0;
  cx = memoryAGet16(ds, 0x046e);
  flags.carry = al < cl;
  al -= cl;
  ah -= ch + flags.carry;
  ah &= 0x03;
  if (ah < 0x02)
    goto loc_12396;
  bl--;
  al = -al;
loc_12396:
  if (al == 0x00)
    return;
  al += 0x03;
  al >>= 1;
  al >>= 1;
  if (!(bl & 0x80))
    goto loc_123a7;
  al = -al;
loc_123a7:
  flags.carry = (al + memoryAGet(ds, 0x046e)) >= 0x100;
  al += memoryAGet(ds, 0x046e);
  memoryASet(ds, 0x046e, al);
  bl += memoryAGet(ds, 0x046f) + flags.carry;
  bl &= 0x03;
  memoryASet(ds, 0x046f, bl);
}
void sub_123ba()
{
  ax = 0xa000;
  es = ax;
  di = 0x03c0;
  cx = 0x0058;
  al = 0;
loc_123c7:
  push(cx);
  cx = 0x0028;
  rep_stosb<MemAuto, DirAuto>();
  cx = 0x0028;
  rep_stosb<MemAuto, DirAuto>();
  cx = pop();
  if (--cx)
    goto loc_123c7;
}
void sub_123d6()
{
  al = memoryAGet(ds, 0x03d4);
  ah = 0;
  ax += 0x03bf;
  bx = ax;
  memoryASet(ds, bx, 0x00);
  bx = 0x0471;
  if (memoryAGet(ds, 0x03db) == 0x00)
    goto loc_123ef;
  bx++;
  bx++;
loc_123ef:
  memoryASet(ds, bx, memoryAGet(ds, bx) + 1);
  al = memoryAGet(ds, bx);
  memoryASet(ds, 0x03d4, al);
}
void sub_123f7()
{
  bx = 0x0472;
  if (memoryAGet(ds, 0x03db) == 0x00)
    goto loc_12403;
  bx++;
  bx++;
loc_12403:
  memoryASet(ds, bx, 0x00);
}
void sub_12407()
{
  bx = 0x0471;
  if (memoryAGet(ds, 0x03db) == 0x00)
    goto loc_12413;
  bx++;
  bx++;
loc_12413:
  al = memoryAGet(ds, 0x03d4);
  memoryASet(ds, bx, al);
  bx++;
  push(bx);
  cx = 0x0008;
  al = 0;
  bx = 0x03bf;
loc_12422:
  ah = memoryAGet(ds, bx);
  stop(/*carry1*/);
  ah = rcr(ah, 0x01);
  al = rcr(al, 0x01);
  bx++;
  if (--cx)
    goto loc_12422;
  bx = pop();
  memoryASet(ds, bx, al);
}
void sub_1242f()
{
  bp = 0x03de;
  if (memoryAGet(ds, 0x03db) == 0x00)
    goto loc_1243c;
  bp = 0x03e2;
loc_1243c:
  al = memoryAGet(ds, bp);
  al += bl;
  stop(); // daa 
  memoryASet(ds, bp, al);
  flags.carry = bp == 0xffff;
  bp++;
  al = memoryAGet(ds, bp);
  dh = al;
  al += bh + flags.carry;
  stop(); // daa 
  memoryASet(ds, bp, al);
  dl = al;
  flags.carry = bp == 0xffff;
  bp++;
  al = memoryAGet(ds, bp);
  al += flags.carry;
  stop(); // daa 
  memoryASet(ds, bp, al);
  flags.carry = bp == 0xffff;
  bp++;
  al = memoryAGet(ds, bp);
  al += flags.carry;
  stop(); // daa 
  memoryASet(ds, bp, al);
  bp++;
  al = dh;
  al &= 0xf0;
  if (al != 0x40)
    goto loc_12480;
  al = dl;
  al &= 0xf0;
  if (al == 0x50)
    goto loc_1248e;
loc_12480:
  al = dh;
  al &= 0xf0;
  if (al != 0x90)
    return;
  al = dl;
  al &= 0xf0;
  if (al != 0)
    return;
loc_1248e:
  bx = 0x03dc;
  if (memoryAGet(ds, 0x03db) == 0x00)
    goto loc_12499;
  bx++;
loc_12499:
  memoryASet(ds, bx, memoryAGet(ds, bx) + 1);
  if (memoryAGet(ds, bx) < 0x08)
    goto loc_124a3;
  memoryASet(ds, bx, 0x08);
loc_124a3:
  sub_12c6a();
}
void sub_125d7()
{
  sub_10000();
  push(es);
  ah = 0x35;
  al = 0x09;
  interrupt(0x21);
  di = 0xe5b5;
  memoryASet16(ds, di, es);
  memoryASet16(ds, di + 2, bx);
  es = pop();
  push(ds);
  push(cs);
  ds = pop();
  dx = 0x2616;
  ah = 0x25;
  al = 0x09;
  interrupt(0x21);
  ds = pop();
  al = 0xfc;
  out(0x0021, al);
}
void sub_125fc()
{
  sub_10021();
  push(ds);
  di = 0xe5b5;
  dx = memoryAGet16(ds, di + 2);
  ax = memoryAGet16(ds, di);
  ds = ax;
  ah = 0x25;
  al = 0x09;
  interrupt(0x21);
  ds = pop();
  al = 0;
  out(0x0021, al);
}
void sub_1264f()
{
  goto loc_1264f;
loc_1034d:
  ax = 0x1532;
  ds = ax;
  memoryASet(ds, 0xe639, 0x00);
  memoryASet(ds, 0x006a, 0x01);
  if (memoryAGet(ds, 0x006b) == 0x01)
    goto loc_103d7;
  if (memoryAGet(ds, 0x03db) == 0x00)
    goto loc_103d7;
  memoryASet(ds, 0x006a, memoryAGet(ds, 0x006a) + 1);
  sub_102a9();
  si = bx;
  if (si >= memoryAGet16(ds, 0x0167))
    goto loc_1037e;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x02);
loc_1037e:
  if (si <= memoryAGet16(ds, 0x0169))
    goto loc_10389;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x01);
loc_10389:
  sub_102a0();
  si = cx;
  if (si >= memoryAGet16(ds, 0x016b))
    goto loc_10399;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x08);
loc_10399:
  if (si <= memoryAGet16(ds, 0x016d))
    goto loc_103a4;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x04);
loc_103a4:
  dx = 0x0201;
  in(al, dx);
  cl = 0x20;
  ch = 0x10;
  if (memoryAGet(ds, 0x006a) == 0x01)
    goto loc_103b7;
  cl = 0x80;
  ch = 0x40;
loc_103b7:
  if (cl & al)
    goto loc_103c0;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x20);
loc_103c0:
  if (ch & al)
    goto loc_103c9;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x10);
loc_103c9:
  if (memoryAGet(ds, 0xe5f2) == 0x01)
    goto loc_103d1;
  return;
loc_103d1:
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x10);
  return;
loc_103d7:
  sub_102a9();
  si = bx;
  if (si >= memoryAGet16(ds, 0x010a))
    goto loc_103e7;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x02);
loc_103e7:
  if (si <= memoryAGet16(ds, 0x010c))
    goto loc_103f2;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x01);
loc_103f2:
  sub_102a0();
  si = cx;
  if (si >= memoryAGet16(ds, 0x010e))
    goto loc_10402;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x08);
loc_10402:
  if (si <= memoryAGet16(ds, 0x0110))
    goto loc_1040d;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x04);
loc_1040d:
  dx = 0x0201;
  in(al, dx);
  cl = 0x20;
  ch = 0x10;
  if (memoryAGet(ds, 0x006a) == 0x01)
    goto loc_10420;
  cl = 0x80;
  ch = 0x40;
loc_10420:
  if (cl & al)
    goto loc_10429;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x20);
loc_10429:
  if (ch & al)
    goto loc_10432;
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x10);
loc_10432:
  if (memoryAGet(ds, 0xe5f2) == 0x01)
    goto loc_1043a;
  return;
loc_1043a:
  memoryASet(ds, 0xe639, memoryAGet(ds, 0xe639) | 0x10);
  return;
  //   gap of 8719 bytes
loc_1264f:
  if (memoryAGet(ds, 0x0455) != 0x01)
    goto loc_12659;
  goto loc_1034d;
loc_12659:
  cx = 0x0008;
  bx = 0;
  si = 0xe63a;
  di = 0xe5b9;
loc_12664:
  bl = memoryAGet(ds, si);
  al = memoryAGet(ds, bx + di);
  flags.carry = al & 1;
  al >>= 1;
  memoryASet(ds, 0xe639, rcl(memoryAGet(ds, 0xe639), 0x01));
  si++;
  if (--cx)
    goto loc_12664;
}
void sub_12672()
{
  sub_123ba();
}
void sub_12676()
{
  sub_12672();
  al = 0x02;
  sub_113ee();
  bp = 0xe690;
  sub_14f3a();
  sub_12bc6();
  bp = 0xe6ab;
  sub_14f3a();
loc_1268d:
  sub_11417();
  if (!flags.carry)
    goto loc_1268d;
  al = 0x19;
  sub_12bd6();
  goto loc_12a67;
  //   gap of 973 bytes
loc_12a67:
  sub_12b00();
  if (flags.carry)
    goto loc_12a6d;
  return;
loc_12a6d:
  memoryASet(ds, bp + 4, 0x41);
  memoryASet(ds, bp + 5, 0x20);
  memoryASet(ds, bp + 6, 0x20);
  memoryASet16(ds, 0xe8a2, bp);
  memoryASet(ds, 0xe8a1, 0x04);
  sub_12672();
loc_12a88:
  sub_129ad();
  bp = 0xe8a4;
  sub_14f3a();
  sub_1518e();
loc_12a94:
  sub_13c90();
  al = memoryAGet(ds, 0x045a);
  if (al)
    goto loc_12a94;
loc_12a9e:
  cx = 0x0006;
loc_12aa1:
  sub_1518e();
  if (--cx)
    goto loc_12aa1;
  sub_13c90();
  al = memoryAGet(ds, 0x045b);
  al |= memoryAGet(ds, 0x045a);
  if (!al)
    goto loc_12a9e;
  al = memoryAGet(ds, 0x045b);
  if (!al)
    goto loc_12ad5;
  bp = memoryAGet16(ds, 0xe8a2);
  al += memoryAGet(ds, bp + 4);
  if (al != 0x40)
    goto loc_12ac9;
  al = 0x5a;
  goto loc_12acf;
loc_12ac9:
  if (al != 0x5b)
    goto loc_12acf;
  al = 0x41;
loc_12acf:
  memoryASet(ds, bp + 4, al);
  goto loc_12a88;
loc_12ad5:
  bp = memoryAGet16(ds, 0xe8a2);
  bp++;
  memoryASet16(ds, 0xe8a2, bp);
  al = memoryAGet(ds, 0xe8a1);
  al++;
  memoryASet(ds, 0xe8a1, al);
  if (al == 0x07)
    goto loc_12af4;
  al = memoryAGet(ds, bp + 3);
  memoryASet(ds, bp + 4, al);
  goto loc_12a88;
loc_12af4:
  cx = 0x0019;
loc_12af7:
  sub_1518e();
  if (--cx)
    goto loc_12af7;
  sub_151ab();
}
void sub_1269a()
{
  sub_12672();
  al = 0x02;
  sub_113ee();
  bp = 0xe79c;
  sub_14f3a();
  sub_12bc6();
  bp = 0xe773;
  sub_14f3a();
loc_126b1:
  sub_11417();
  if (!flags.carry)
    goto loc_126b1;
  al = 0x19;
  goto loc_12bd6;
  //   gap of 1307 bytes
loc_12bd6:
  memoryASet(ds, 0xe8ca, al);
  sub_12bef();
loc_12bdc:
  sub_1518e();
  memoryASet(ds, 0xe8ca, memoryAGet(ds, 0xe8ca) - 1);
  if (memoryAGet(ds, 0xe8ca) == 0)
    return;
  sub_13c90();
  if (memoryAGet(ds, 0x045a) == 0x00)
    goto loc_12bdc;
loc_12bef:
  sub_13c90();
  if (memoryAGet(ds, 0x045a) != 0x00)
    goto loc_12bef;
}
void sub_126bb()
{
  sub_12672();
  bp = 0xe730;
  sub_14f3a();
  sub_12bc6();
  bp = 0xe74a;
  sub_14f3a();
  al = 0xff;
  sub_12bd6();
  goto loc_12a67;
  //   gap of 914 bytes
loc_12a67:
  sub_12b00();
  if (flags.carry)
    goto loc_12a6d;
  return;
loc_12a6d:
  memoryASet(ds, bp + 4, 0x41);
  memoryASet(ds, bp + 5, 0x20);
  memoryASet(ds, bp + 6, 0x20);
  memoryASet16(ds, 0xe8a2, bp);
  memoryASet(ds, 0xe8a1, 0x04);
  sub_12672();
loc_12a88:
  sub_129ad();
  bp = 0xe8a4;
  sub_14f3a();
  sub_1518e();
loc_12a94:
  sub_13c90();
  al = memoryAGet(ds, 0x045a);
  if (al)
    goto loc_12a94;
loc_12a9e:
  cx = 0x0006;
loc_12aa1:
  sub_1518e();
  if (--cx)
    goto loc_12aa1;
  sub_13c90();
  al = memoryAGet(ds, 0x045b);
  al |= memoryAGet(ds, 0x045a);
  if (!al)
    goto loc_12a9e;
  al = memoryAGet(ds, 0x045b);
  if (!al)
    goto loc_12ad5;
  bp = memoryAGet16(ds, 0xe8a2);
  al += memoryAGet(ds, bp + 4);
  if (al != 0x40)
    goto loc_12ac9;
  al = 0x5a;
  goto loc_12acf;
loc_12ac9:
  if (al != 0x5b)
    goto loc_12acf;
  al = 0x41;
loc_12acf:
  memoryASet(ds, bp + 4, al);
  goto loc_12a88;
loc_12ad5:
  bp = memoryAGet16(ds, 0xe8a2);
  bp++;
  memoryASet16(ds, 0xe8a2, bp);
  al = memoryAGet(ds, 0xe8a1);
  al++;
  memoryASet(ds, 0xe8a1, al);
  if (al == 0x07)
    goto loc_12af4;
  al = memoryAGet(ds, bp + 3);
  memoryASet(ds, bp + 4, al);
  goto loc_12a88;
loc_12af4:
  cx = 0x0019;
loc_12af7:
  sub_1518e();
  if (--cx)
    goto loc_12af7;
  sub_151ab();
}
void sub_126d5()
{
  sub_12672();
  memoryASet(ds, 0xe7a2, 0x00);
  sub_12799();
  al = 0x64;
  sub_12bd6();
  memoryASet16(ds, 0x03ee, memoryAGet16(ds, 0x03ee) & 0x00f0);
loc_126eb:
  if (memoryAGet16(ds, 0x03ee) == 0x0000)
    goto loc_12715;
  al = memoryAGet(ds, 0x03ee);
  al -= 0x10;
  stop(); // das 
  memoryASet(ds, 0x03ee, al);
  al = memoryAGet(ds, 0x03ef);
  stop(/*81*/);
  al -= flags.carry;
  stop(); // das 
  memoryASet(ds, 0x03ef, al);
  sub_12799();
  sub_1172b();
  bx = 0x0014;
  sub_1242f();
  sub_12d22();
  goto loc_126eb;
loc_12715:
  bx = 0x03e6;
  if (memoryAGet(ds, 0x03db) == 0x00)
    goto loc_12721;
  bx++;
  bx++;
loc_12721:
  al = memoryAGet(ds, bx);
  al |= memoryAGet(ds, bx + 1);
  if (!al)
    goto loc_12746;
  al = memoryAGet(ds, bx);
  al -= 0x01;
  stop(); // das 
  memoryASet(ds, bx, al);
  al = memoryAGet(ds, bx + 1);
  stop(/*81*/);
  al -= flags.carry;
  stop(); // das 
  memoryASet(ds, bx + 1, al);
  sub_12799();
  bx = 0x0014;
  sub_1242f();
  sub_12d22();
  goto loc_12715;
loc_12746:
  bx = 0x03ea;
  if (memoryAGet(ds, 0x03db) == 0x00)
    goto loc_12752;
  bx++;
  bx++;
loc_12752:
  al = memoryAGet(ds, bx);
  al |= memoryAGet(ds, bx + 1);
  if (!al)
    goto loc_12777;
  al = memoryAGet(ds, bx);
  al -= 0x01;
  stop(); // das 
  memoryASet(ds, bx, al);
  al = memoryAGet(ds, bx + 1);
  stop(/*81*/);
  al -= flags.carry;
  stop(); // das 
  memoryASet(ds, bx + 1, al);
  sub_12799();
  bx = 0x0014;
  sub_1242f();
  sub_12d22();
  goto loc_12746;
loc_12777:
  sub_12799();
  al = 0x64;
  goto loc_12bd6;
  //   gap of 1111 bytes
loc_12bd6:
  memoryASet(ds, 0xe8ca, al);
  sub_12bef();
loc_12bdc:
  sub_1518e();
  memoryASet(ds, 0xe8ca, memoryAGet(ds, 0xe8ca) - 1);
  if (memoryAGet(ds, 0xe8ca) == 0)
    return;
  sub_13c90();
  if (memoryAGet(ds, 0x045a) == 0x00)
    goto loc_12bdc;
loc_12bef:
  sub_13c90();
  if (memoryAGet(ds, 0x045a) != 0x00)
    goto loc_12bef;
}
void sub_1277f()
{
  if (memoryAGet(ds, 0x03f1) != 0x00)
    goto loc_12787;
  return;
loc_12787:
  memoryASet(ds, 0xe7a3, memoryAGet(ds, 0xe7a3) + 1);
  memoryASet(ds, 0xe7a3, memoryAGet(ds, 0xe7a3) & 0x1f);
  al = memoryAGet(ds, 0xe7a3);
  cx = 0x1388;
  goto loc_150c3;
  //   gap of 10538 bytes
loc_150c3:
  push(ax);
  in(al, 0x61);
  al |= 0x03;
  out(0x0061, al);
  ax = pop();
  out(0x0042, al);
loc_150cd:
  if (--cx)
    goto loc_150cd;
  in(al, 0x61);
  al &= 0xfc;
  out(0x0061, al);
}
void sub_12799()
{
  if (memoryAGet(ds, 0x03f1) == 0x00)
    goto loc_127a3;
  sub_1277f();
loc_127a3:
  al = memoryAGet(ds, 0x03ef);
  al >>= 1;
  al >>= 1;
  al >>= 1;
  al >>= 1;
  al += 0x30;
  memoryASet(ds, 0xe6fa, al);
  al = memoryAGet(ds, 0x03ef);
  al &= 0x0f;
  al += 0x30;
  memoryASet(ds, 0xe6fb, al);
  al = memoryAGet(ds, 0x03ee);
  al >>= 1;
  al >>= 1;
  al >>= 1;
  al >>= 1;
  al += 0x30;
  memoryASet(ds, 0xe6fc, al);
  bx = 0x03e6;
  if (memoryAGet(ds, 0x03db) == 0x00)
    goto loc_127d9;
  bx++;
  bx++;
loc_127d9:
  al = memoryAGet(ds, bx + 1);
  al += 0x30;
  memoryASet(ds, 0xe713, al);
  al = memoryAGet(ds, bx);
  al &= 0x0f;
  al += 0x30;
  memoryASet(ds, 0xe715, al);
  al = memoryAGet(ds, bx);
  al >>= 1;
  al >>= 1;
  al >>= 1;
  al >>= 1;
  al += 0x30;
  memoryASet(ds, 0xe714, al);
  bx += 0x0004;
  al = memoryAGet(ds, bx + 1);
  al += 0x30;
  memoryASet(ds, 0xe72c, al);
  al = memoryAGet(ds, bx);
  al &= 0x0f;
  al += 0x30;
  memoryASet(ds, 0xe72e, al);
  al = memoryAGet(ds, bx);
  al >>= 1;
  al >>= 1;
  al >>= 1;
  al >>= 1;
  al += 0x30;
  memoryASet(ds, 0xe72d, al);
  if (memoryAGet(ds, 0xe7a2) != 0x00)
    goto loc_1284c;
  memoryASet(ds, 0xe7a2, 0x01);
  bp = 0xe6be;
  sub_14f3a();
  bp = 0xe6f7;
  sub_14f3a();
  bp = 0xe6fe;
  sub_14f3a();
  bp = 0xe710;
  sub_14f3a();
  bp = 0xe717;
  sub_14f3a();
  bp = 0xe729;
  goto loc_14f3a;
loc_1284c:
  bp = 0xe6f5;
  sub_14f3a();
  bp = 0xe710;
  sub_14f3a();
  bp = 0xe729;
  goto loc_14f3a;
  //   gap of 9948 bytes
loc_14f3a:
  ax = 0x0001;
  dx = 0x03ce;
  out(dx, ax);
  ax = 0x0005;
  dx = 0x03ce;
  out(dx, ax);
  al = 0x08;
  ah = 0xff;
  out(dx, ax);
  al = 0x03;
  ah = 0x00;
  out(dx, ax);
loc_14f52:
  al = memoryAGet(ds, bp);
  if (al)
    goto loc_14f5b;
  return;
loc_14f5b:
  sub_14f61();
  bp++;
  goto loc_14f52;
}
void sub_1285e()
{
  sub_12672();
  al = 0;
  sub_113ee();
  memoryASet(ds, 0xe799, 0x00);
  memoryASet(ds, 0xe79a, 0xc0);
  memoryASet(ds, 0xe79b, 0x00);
  goto loc_1287a;
loc_12877:
  sub_123ba();
loc_1287a:
  if (memoryAGet(ds, 0xe799) == 0x00)
    goto loc_12889;
  sub_129ad();
  sub_12a36();
  goto loc_128a0;
loc_12889:
  cx = 0x0034;
  dx = 0x0010;
  di = 0x050c;
  si = 0;
  sub_14e68();
  bp = 0xe7a4;
  sub_14f3a();
  sub_12a36();
loc_128a0:
  if (memoryAGet(ds, 0xe79b) != 0x00)
    goto loc_128b1;
loc_128a7:
  sub_13c90();
  if (memoryAGet(ds, 0x045a) != 0x00)
    goto loc_128a7;
loc_128b1:
  memoryASet(ds, 0xe79b, 0x01);
  sub_11417(); // gabo delay?
    sync();

  if (memoryAGet(ds, 0xe602) != 0x01)
    goto loc_128ce;
  if (memoryAGet16(ds, 0xe824) == 0x0001)
    goto loc_128ce;
  memoryASet16(ds, 0xe824, memoryAGet16(ds, 0xe824) - 1);
  sub_14ea9();
loc_128ce:
  if (memoryAGet(ds, 0xe60a) != 0x01)
    goto loc_128e3;
  if (memoryAGet16(ds, 0xe824) == 0xffff)
    goto loc_128e3;
  memoryASet16(ds, 0xe824, memoryAGet16(ds, 0xe824) + 1);
  sub_14ea9();
loc_128e3:
  if (memoryAGet(ds, 0xe608) != 0x01)
    goto loc_128f4;
loc_128ea:
  if (memoryAGet(ds, 0xe608) == 0x01)
    goto loc_128ea;
  sub_151ab();
loc_128f4:
  sub_1264f();
  if (memoryAGet(ds, 0xe639) != 0x10)
    goto loc_12901;
  goto loc_12bef;
loc_12901:
  if (memoryAGet(ds, 0xe5bb) == 0x01)
    goto loc_12911;
  if (memoryAGet(ds, 0xe5f4) == 0x01)
    goto loc_12911;
  goto loc_12919;
loc_12911:
  memoryASet(ds, 0x03da, 0x01);
  goto loc_1287a;
loc_12919:
  if (memoryAGet(ds, 0xe5bc) == 0x01)
    goto loc_12929;
  if (memoryAGet(ds, 0xe5f5) == 0x01)
    goto loc_12929;
  goto loc_12931;
loc_12929:
  memoryASet(ds, 0x03da, 0x02);
  goto loc_1287a;
loc_12931:
  if (memoryAGet(ds, 0xe5bd) == 0x01)
    goto loc_12941;
  if (memoryAGet(ds, 0xe5f6) == 0x01)
    goto loc_12941;
  goto loc_12949;
loc_12941:
  memoryASet(ds, 0x03f1, 0x80);
  goto loc_1287a;
loc_12949:
  if (memoryAGet(ds, 0xe5be) == 0x01)
    goto loc_12959;
  if (memoryAGet(ds, 0xe5f7) == 0x01)
    goto loc_12959;
  goto loc_12961;
loc_12959:
  memoryASet(ds, 0x03f1, 0x00);
  goto loc_1287a;
loc_12961:
  if (memoryAGet(ds, 0xeea7) == 0x00)
    goto loc_1297e;
  if (memoryAGet(ds, 0xe5f8) == 0x01)
    goto loc_12978;
  if (memoryAGet(ds, 0xe5bf) == 0x01)
    goto loc_12978;
  goto loc_1297e;
loc_12978:
  sub_14f15();
  goto loc_1287a;
loc_1297e:
  if (memoryAGet(ds, 0xeea7) == 0xff)
    goto loc_12993;
  if (memoryAGet(ds, 0xe5f9) == 0x01)
    goto loc_12978;
  if (memoryAGet(ds, 0xe5c0) == 0x01)
    goto loc_12978;
loc_12993:
  memoryASet(ds, 0xe79a, memoryAGet(ds, 0xe79a) - 1);
  if (memoryAGet(ds, 0xe79a) == 0)
    goto loc_1299c;
  goto loc_128b1;
loc_1299c:
  al = 0x01;
  al -= memoryAGet(ds, 0xe799);
  memoryASet(ds, 0xe799, al);
  memoryASet(ds, 0xe79a, 0xc0);
  goto loc_12877;
  //   gap of 578 bytes
loc_12bef:
  sub_13c90();
    sync();
//  if (memoryAGet(ds, 0x045a) != 0x00)
//    goto loc_12bef;
}
void sub_129ad()
{
  bp = 0xe839;
  sub_14f3a();
  bp = 0xe826;
  sub_14f3a();
  bp = 0xe808;
  sub_129e2();
  bp = 0xe82c;
  sub_14f3a();
  bp = 0xe80f;
  sub_129e2();
  bp = 0xe830;
  sub_14f3a();
  bp = 0xe816;
  sub_129e2();
  bp = 0xe834;
  sub_14f3a();
  bp = 0xe81d;
  al = memoryAGet(ds, bp + 3);
  sub_12a22();
  al = memoryAGet(ds, bp + 2);
  sub_12a22();
  al = memoryAGet(ds, bp + 1);
  sub_12a22();
  al = memoryAGet(ds, bp);
  sub_12a22();
  al = 0x20;
  sub_14f61();
  al = 0x20;
  sub_14f61();
  al = 0x20;
  sub_14f61();
  al = memoryAGet(ds, bp + 4);
  sub_14f61();
  al = memoryAGet(ds, bp + 5);
  sub_14f61();
  al = memoryAGet(ds, bp + 6);
  goto loc_14f61;
  //   gap of 9535 bytes
loc_14f61:
  bx = 0x1532;
  es = bx;
  if (memoryAGet(ds, 0xefc2) != 0x00)
    goto loc_14f70;
  goto loc_15032;
loc_14f70:
  if (al != 0x10)
    goto loc_14f77;
  goto loc_15029;
loc_14f77:
  if (al != 0x11)
    goto loc_14f7e;
  goto loc_15010;
loc_14f7e:
  ah = 0;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax += 0xefe6;
  si = ax;
  ax = 0xa000;
  es = ax;
  ax = 0;
  al = memoryAGet(ds, 0xeeaa);
  ax += memoryAGet16(ds, 0xeeab);
  di = ax;
  if (memoryAGet(ds, 0xf0b2) == 0x01)
    goto loc_14fc7;
  al = 0;
  memoryASet(es, di, al);
  memoryASet(es, di + 40, al);
  memoryASet(es, di + 80, al);
  memoryASet(es, di + 120, al);
  memoryASet(es, di + 160, al);
  memoryASet(es, di + 200, al);
  memoryASet(es, di + 240, al);
  memoryASet(es, di + 280, al);
loc_14fc7:
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = memoryAGet(ds, 0xeea8);
  out(dx, al);
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = 0x0f;
  out(dx, al);
  memoryASet(ds, 0xeeaa, memoryAGet(ds, 0xeeaa) + 1);
  if (memoryAGet(ds, 0xeeaa) < 0x28)
    goto loc_1500f;
  memoryASet(ds, 0xeeaa, 0x00);
  memoryASet16(ds, 0xeeab, memoryAGet16(ds, 0xeeab) + 0x0140);
loc_1500f:
  return;
loc_15010:
  al = memoryAGet(ds, bp + 1);
  cx = 0x0140;
  ah = 0;
  mul(cx);
  memoryASet16(ds, 0xeeab, ax);
  al = memoryAGet(ds, bp + 2);
  memoryASet(ds, 0xeeaa, al);
  bp += 0x0002;
  return;
loc_15029:
  bp++;
  al = memoryAGet(ds, bp);
  memoryASet(ds, 0xeea8, al);
  return;
loc_15032:
  if (al != 0x10)
    goto loc_15038;
  goto loc_15078;
loc_15038:
  if (al != 0x11)
    goto loc_1503e;
  goto loc_15059;
loc_1503e:
  push(ax);
  ax = 0xa000;
  es = ax;
  ax = pop();
  di = memoryAGet16(ds, 0xeeab);
  memoryASet(es, di, al);
  al = memoryAGet(ds, 0xeea8);
  memoryASet(es, di + 1, al);
  memoryASet16(ds, 0xeeab, memoryAGet16(ds, 0xeeab) + 0x0002);
  return;
loc_15059:
  al = memoryAGet(ds, bp + 1);
  cx = 0x0050;
  ah = 0;
  mul(cx);
  bx = ax;
  al = memoryAGet(ds, bp + 2);
  al += al;
  ah = 0;
  bx += ax;
  memoryASet16(ds, 0xeeab, bx);
  bp += 0x0002;
  return;
loc_15078:
  bp++;
  al = memoryAGet(ds, bp);
  memoryASet(ds, 0xeea8, al);
}
void sub_129e2()
{
  al = memoryAGet(ds, bp + 3);
  sub_12a22();
  al = memoryAGet(ds, bp + 2);
  sub_12a22();
  al = memoryAGet(ds, bp + 1);
  sub_12a22();
  al = memoryAGet(ds, bp);
  sub_12a22();
  al = 0x20;
  sub_14f61();
  al = 0x20;
  sub_14f61();
  al = 0x20;
  sub_14f61();
  al = memoryAGet(ds, bp + 4);
  sub_14f61();
  al = memoryAGet(ds, bp + 5);
  sub_14f61();
  al = memoryAGet(ds, bp + 6);
  goto loc_14f61;
  //   gap of 9535 bytes
loc_14f61:
  bx = 0x1532;
  es = bx;
  if (memoryAGet(ds, 0xefc2) != 0x00)
    goto loc_14f70;
  goto loc_15032;
loc_14f70:
  if (al != 0x10)
    goto loc_14f77;
  goto loc_15029;
loc_14f77:
  if (al != 0x11)
    goto loc_14f7e;
  goto loc_15010;
loc_14f7e:
  ah = 0;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax += 0xefe6;
  si = ax;
  ax = 0xa000;
  es = ax;
  ax = 0;
  al = memoryAGet(ds, 0xeeaa);
  ax += memoryAGet16(ds, 0xeeab);
  di = ax;
  if (memoryAGet(ds, 0xf0b2) == 0x01)
    goto loc_14fc7;
  al = 0;
  memoryASet(es, di, al);
  memoryASet(es, di + 40, al);
  memoryASet(es, di + 80, al);
  memoryASet(es, di + 120, al);
  memoryASet(es, di + 160, al);
  memoryASet(es, di + 200, al);
  memoryASet(es, di + 240, al);
  memoryASet(es, di + 280, al);
loc_14fc7:
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = memoryAGet(ds, 0xeea8);
  out(dx, al);
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = 0x0f;
  out(dx, al);
  memoryASet(ds, 0xeeaa, memoryAGet(ds, 0xeeaa) + 1);
  if (memoryAGet(ds, 0xeeaa) < 0x28)
    goto loc_1500f;
  memoryASet(ds, 0xeeaa, 0x00);
  memoryASet16(ds, 0xeeab, memoryAGet16(ds, 0xeeab) + 0x0140);
loc_1500f:
  return;
loc_15010:
  al = memoryAGet(ds, bp + 1);
  cx = 0x0140;
  ah = 0;
  mul(cx);
  memoryASet16(ds, 0xeeab, ax);
  al = memoryAGet(ds, bp + 2);
  memoryASet(ds, 0xeeaa, al);
  bp += 0x0002;
  return;
loc_15029:
  bp++;
  al = memoryAGet(ds, bp);
  memoryASet(ds, 0xeea8, al);
  return;
loc_15032:
  if (al != 0x10)
    goto loc_15038;
  goto loc_15078;
loc_15038:
  if (al != 0x11)
    goto loc_1503e;
  goto loc_15059;
loc_1503e:
  push(ax);
  ax = 0xa000;
  es = ax;
  ax = pop();
  di = memoryAGet16(ds, 0xeeab);
  memoryASet(es, di, al);
  al = memoryAGet(ds, 0xeea8);
  memoryASet(es, di + 1, al);
  memoryASet16(ds, 0xeeab, memoryAGet16(ds, 0xeeab) + 0x0002);
  return;
loc_15059:
  al = memoryAGet(ds, bp + 1);
  cx = 0x0050;
  ah = 0;
  mul(cx);
  bx = ax;
  al = memoryAGet(ds, bp + 2);
  al += al;
  ah = 0;
  bx += ax;
  memoryASet16(ds, 0xeeab, bx);
  bp += 0x0002;
  return;
loc_15078:
  bp++;
  al = memoryAGet(ds, bp);
  memoryASet(ds, 0xeea8, al);
}
void sub_12a22()
{
  push(ax);
  al >>= 1;
  al >>= 1;
  al >>= 1;
  al >>= 1;
  sub_12a2f();
  ax = pop();
  al &= 0x0f;
  al += 0x30;
  goto loc_14f61;
  //   gap of 9515 bytes
loc_14f61:
  bx = 0x1532;
  es = bx;
  if (memoryAGet(ds, 0xefc2) != 0x00)
    goto loc_14f70;
  goto loc_15032;
loc_14f70:
  if (al != 0x10)
    goto loc_14f77;
  goto loc_15029;
loc_14f77:
  if (al != 0x11)
    goto loc_14f7e;
  goto loc_15010;
loc_14f7e:
  ah = 0;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax += 0xefe6;
  si = ax;
  ax = 0xa000;
  es = ax;
  ax = 0;
  al = memoryAGet(ds, 0xeeaa);
  ax += memoryAGet16(ds, 0xeeab);
  di = ax;
  if (memoryAGet(ds, 0xf0b2) == 0x01)
    goto loc_14fc7;
  al = 0;
  memoryASet(es, di, al);
  memoryASet(es, di + 40, al);
  memoryASet(es, di + 80, al);
  memoryASet(es, di + 120, al);
  memoryASet(es, di + 160, al);
  memoryASet(es, di + 200, al);
  memoryASet(es, di + 240, al);
  memoryASet(es, di + 280, al);
loc_14fc7:
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = memoryAGet(ds, 0xeea8);
  out(dx, al);
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = 0x0f;
  out(dx, al);
  memoryASet(ds, 0xeeaa, memoryAGet(ds, 0xeeaa) + 1);
  if (memoryAGet(ds, 0xeeaa) < 0x28)
    goto loc_1500f;
  memoryASet(ds, 0xeeaa, 0x00);
  memoryASet16(ds, 0xeeab, memoryAGet16(ds, 0xeeab) + 0x0140);
loc_1500f:
  return;
loc_15010:
  al = memoryAGet(ds, bp + 1);
  cx = 0x0140;
  ah = 0;
  mul(cx);
  memoryASet16(ds, 0xeeab, ax);
  al = memoryAGet(ds, bp + 2);
  memoryASet(ds, 0xeeaa, al);
  bp += 0x0002;
  return;
loc_15029:
  bp++;
  al = memoryAGet(ds, bp);
  memoryASet(ds, 0xeea8, al);
  return;
loc_15032:
  if (al != 0x10)
    goto loc_15038;
  goto loc_15078;
loc_15038:
  if (al != 0x11)
    goto loc_1503e;
  goto loc_15059;
loc_1503e:
  push(ax);
  ax = 0xa000;
  es = ax;
  ax = pop();
  di = memoryAGet16(ds, 0xeeab);
  memoryASet(es, di, al);
  al = memoryAGet(ds, 0xeea8);
  memoryASet(es, di + 1, al);
  memoryASet16(ds, 0xeeab, memoryAGet16(ds, 0xeeab) + 0x0002);
  return;
loc_15059:
  al = memoryAGet(ds, bp + 1);
  cx = 0x0050;
  ah = 0;
  mul(cx);
  bx = ax;
  al = memoryAGet(ds, bp + 2);
  al += al;
  ah = 0;
  bx += ax;
  memoryASet16(ds, 0xeeab, bx);
  bp += 0x0002;
  return;
loc_15078:
  bp++;
  al = memoryAGet(ds, bp);
  memoryASet(ds, 0xeea8, al);
}
void sub_12a2f()
{
  al &= 0x0f;
  al += 0x30;
  goto loc_14f61;
  //   gap of 9515 bytes
loc_14f61:
  bx = 0x1532;
  es = bx;
  if (memoryAGet(ds, 0xefc2) != 0x00)
    goto loc_14f70;
  goto loc_15032;
loc_14f70:
  if (al != 0x10)
    goto loc_14f77;
  goto loc_15029;
loc_14f77:
  if (al != 0x11)
    goto loc_14f7e;
  goto loc_15010;
loc_14f7e:
  ah = 0;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax += 0xefe6;
  si = ax;
  ax = 0xa000;
  es = ax;
  ax = 0;
  al = memoryAGet(ds, 0xeeaa);
  ax += memoryAGet16(ds, 0xeeab);
  di = ax;
  if (memoryAGet(ds, 0xf0b2) == 0x01)
    goto loc_14fc7;
  al = 0;
  memoryASet(es, di, al);
  memoryASet(es, di + 40, al);
  memoryASet(es, di + 80, al);
  memoryASet(es, di + 120, al);
  memoryASet(es, di + 160, al);
  memoryASet(es, di + 200, al);
  memoryASet(es, di + 240, al);
  memoryASet(es, di + 280, al);
loc_14fc7:
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = memoryAGet(ds, 0xeea8);
  out(dx, al);
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = 0x0f;
  out(dx, al);
  memoryASet(ds, 0xeeaa, memoryAGet(ds, 0xeeaa) + 1);
  if (memoryAGet(ds, 0xeeaa) < 0x28)
    goto loc_1500f;
  memoryASet(ds, 0xeeaa, 0x00);
  memoryASet16(ds, 0xeeab, memoryAGet16(ds, 0xeeab) + 0x0140);
loc_1500f:
  return;
loc_15010:
  al = memoryAGet(ds, bp + 1);
  cx = 0x0140;
  ah = 0;
  mul(cx);
  memoryASet16(ds, 0xeeab, ax);
  al = memoryAGet(ds, bp + 2);
  memoryASet(ds, 0xeeaa, al);
  bp += 0x0002;
  return;
loc_15029:
  bp++;
  al = memoryAGet(ds, bp);
  memoryASet(ds, 0xeea8, al);
  return;
loc_15032:
  if (al != 0x10)
    goto loc_15038;
  goto loc_15078;
loc_15038:
  if (al != 0x11)
    goto loc_1503e;
  goto loc_15059;
loc_1503e:
  push(ax);
  ax = 0xa000;
  es = ax;
  ax = pop();
  di = memoryAGet16(ds, 0xeeab);
  memoryASet(es, di, al);
  al = memoryAGet(ds, 0xeea8);
  memoryASet(es, di + 1, al);
  memoryASet16(ds, 0xeeab, memoryAGet16(ds, 0xeeab) + 0x0002);
  return;
loc_15059:
  al = memoryAGet(ds, bp + 1);
  cx = 0x0050;
  ah = 0;
  mul(cx);
  bx = ax;
  al = memoryAGet(ds, bp + 2);
  al += al;
  ah = 0;
  bx += ax;
  memoryASet16(ds, 0xeeab, bx);
  bp += 0x0002;
  return;
loc_15078:
  bp++;
  al = memoryAGet(ds, bp);
  memoryASet(ds, 0xeea8, al);
}
void sub_12a36()
{
  bp = 0xe84b;
  if (memoryAGet(ds, 0x03da) == 0x01)
    goto loc_12a43;
  bp = 0xe859;
loc_12a43:
  sub_14f3a();
  bp = 0xe875;
  if (memoryAGet(ds, 0x03f1) == 0x00)
    goto loc_12a53;
  bp = 0xe867;
loc_12a53:
  sub_14f3a();
  bp = 0xe883;
  if (memoryAGet(ds, 0xeea7) == 0x00)
    goto loc_12a63;
  bp = 0xe892;
loc_12a63:
  sub_14f3a();
}
void sub_12b00()
{
  al = memoryAGet(ds, 0x03db);
  bp = 0x03de;
  if (!al)
    goto loc_12b0d;
  bp = 0x03e2;
loc_12b0d:
  si = 0xe808;
  cx = 0x0004;
loc_12b13:
  al = memoryAGet(ds, si);
  al -= memoryAGet(ds, bp);
  al = memoryAGet(ds, si + 1);
  stop(/*PROBLEM-11g*/);
  al = memoryAGet(ds, si + 2);
  stop(/*81*/);
  al -= memoryAGet(ds, bp + 2) + flags.carry;
  al = memoryAGet(ds, si + 3);
  stop(/*PROBLEM-11g*/);
  if (stop(/*1*/))
    goto loc_12b37;
  si += 0x0007;
  if (--cx)
    goto loc_12b13;
  flags.carry = false;
  return;
loc_12b37:
  dx = si;
  si = 0xe81d;
loc_12b3c:
  bx = si;
  al = bl;
  if (al != dl)
    goto loc_12b4a;
  al = bh;
  if (al == dh)
    goto loc_12b59;
loc_12b4a:
  cx = 0x0007;
loc_12b4d:
  si--;
  al = memoryAGet(ds, si);
  si++;
  memoryASet(ds, si + 6, al);
  si--;
  if (--cx)
    goto loc_12b4d;
  goto loc_12b3c;
loc_12b59:
  al = memoryAGet(ds, bp);
  memoryASet(ds, si, al);
  al = memoryAGet(ds, bp + 1);
  memoryASet(ds, si + 1, al);
  al = memoryAGet(ds, bp + 2);
  memoryASet(ds, si + 2, al);
  al = memoryAGet(ds, bp + 3);
  memoryASet(ds, si + 3, al);
  bp = si;
  flags.carry = true;
}
void sub_12b78()
{
  sub_12672();
  sub_12c6a();
  al = 0x01;
  sub_113ee();
  bp = 0xe64a;
  sub_14f3a();
  sub_12bc6();
  bp = 0xe679;
  sub_14f3a();
  al = memoryAGet(ds, 0x03d4);
  cl = 0x13;
  mul(cl);
  si = 0x24a7;
  if (memoryAGet(ds, 0xeea7) == 0x00)
    goto loc_12ba6;
  si = 0x253f;
loc_12ba6:
  si += ax;
  di = 0xe5a2;
  cx = 0x0012;
loc_12bae:
  al = memoryAGet(cs, si);
  memoryASet(ds, di, al);
  si++;
  di++;
  if (--cx)
    goto loc_12bae;
  bp = 0xe5a2;
  sub_14f3a();
loc_12bbd:
  sub_11417();
  if (!flags.carry)
    goto loc_12bbd;
  al = 0x19;
  goto loc_12bd6;
  //   gap of 16 bytes
loc_12bd6:
  memoryASet(ds, 0xe8ca, al);
  sub_12bef();
loc_12bdc:
  sub_1518e();
  memoryASet(ds, 0xe8ca, memoryAGet(ds, 0xe8ca) - 1);
  if (memoryAGet(ds, 0xe8ca) == 0)
    return;
  sub_13c90();
  if (memoryAGet(ds, 0x045a) == 0x00)
    goto loc_12bdc;
loc_12bef:
  sub_13c90();
  if (memoryAGet(ds, 0x045a) != 0x00)
    goto loc_12bef;
}
void sub_12bc6()
{
  bp = 0xe663;
  if (memoryAGet(ds, 0x03db) == 0x00)
    goto loc_12bd3;
  bp = 0xe66e;
loc_12bd3:
  goto loc_14f3a;
  //   gap of 9060 bytes
loc_14f3a:
  ax = 0x0001;
  dx = 0x03ce;
  out(dx, ax);
  ax = 0x0005;
  dx = 0x03ce;
  out(dx, ax);
  al = 0x08;
  ah = 0xff;
  out(dx, ax);
  al = 0x03;
  ah = 0x00;
  out(dx, ax);
loc_14f52:
  al = memoryAGet(ds, bp);
  if (al)
    goto loc_14f5b;
  return;
loc_14f5b:
  sub_14f61();
  bp++;
  goto loc_14f52;
}
void sub_12bd6()
{
  memoryASet(ds, 0xe8ca, al);
  sub_12bef();
loc_12bdc:
  sub_1518e();
  memoryASet(ds, 0xe8ca, memoryAGet(ds, 0xe8ca) - 1);
  if (memoryAGet(ds, 0xe8ca) == 0)
    return;
  sub_13c90();
  if (memoryAGet(ds, 0x045a) == 0x00)
    goto loc_12bdc;
loc_12bef:
  sub_13c90();
  if (memoryAGet(ds, 0x045a) != 0x00)
    goto loc_12bef;
}
void sub_12bef()
{
loc_12bef:
  sub_13c90();
  if (memoryAGet(ds, 0x045a) != 0x00)
    goto loc_12bef;
}
void sub_12bfa()
{
  bx = 0x03e6;
  if (memoryAGet(ds, 0x03db) == 0x00)
    goto loc_12c07;
  bx += 0x0002;
loc_12c07:
  memoryASet(ds, bx, 0x00);
  memoryASet(ds, bx + 1, 0x01);
  memoryASet(ds, bx + 4, 0x00);
  memoryASet(ds, bx + 5, 0x00);
}
void sub_12c17()
{
  ch = al;
  bx = 0x03ea;
  if (memoryAGet(ds, 0x03db) == 0x00)
    goto loc_12c26;
  bx += 0x0002;
loc_12c26:
  al = memoryAGet(ds, bx);
  al += ch;
  stop(); // daa 
  memoryASet(ds, bx, al);
  flags.carry = bx == 0xffff;
  bx++;
  al = memoryAGet(ds, bx);
  al += flags.carry;
  memoryASet(ds, bx, al);
  if (al >= 0x06)
    goto loc_12c39;
  return;
loc_12c39:
  memoryASet(ds, bx, 0x05);
  bx--;
  memoryASet(ds, bx, 0x00);
}
void sub_12c41()
{
  ch = al;
  bx = 0x03e6;
  if (memoryAGet(ds, 0x03db) == 0x00)
    goto loc_12c50;
  bx += 0x0002;
loc_12c50:
  al = memoryAGet(ds, bx);
  al -= ch;
  stop(); // das 
  memoryASet(ds, bx, al);
  flags.carry = bx == 0xffff;
  bx++;
  al = memoryAGet(ds, bx);
  al -= flags.carry;
  stop(); // das 
  memoryASet(ds, bx, al);
  if (stop(/*1*/))
    goto loc_12c62;
  return;
loc_12c62:
  memoryASet(ds, bx, 0x00);
  bx--;
  memoryASet(ds, bx, 0x00);
}
void sub_12c6a()
{
  sub_12d22();
  memoryASet(ds, 0x03db, memoryAGet(ds, 0x03db) ^ 0x01);
  sub_12d22();
  memoryASet(ds, 0x03db, memoryAGet(ds, 0x03db) ^ 0x01);
  memoryASet16(ds, 0xe8cb, 0x02c8);
  dl = memoryAGet(ds, 0x03dd);
  sub_12c91();
  memoryASet16(ds, 0xe8cb, 0x02a8);
  dl = memoryAGet(ds, 0x03dc);
  cx = 0x0008;
loc_12c94:
  al = 0x7e;
  dl--;
  if (!(dl & 0x80))
    goto loc_12c9f;
  al = 0;
loc_12c9f:
  di = memoryAGet16(ds, 0xe8cb);
  memoryASet16(ds, 0xe8cb, memoryAGet16(ds, 0xe8cb) + 1);
  memoryASet(es, di + 40, al);
  memoryASet(es, di + 80, al);
  memoryASet(es, di + 120, al);
  memoryASet(es, di + 160, al);
  memoryASet(es, di + 200, al);
  memoryASet(es, di + 240, al);
  if (--cx)
    goto loc_12c94;
}
void sub_12c91()
{
  cx = 0x0008;
loc_12c94:
  al = 0x7e;
  dl--;
  if (!(dl & 0x80))
    goto loc_12c9f;
  al = 0;
loc_12c9f:
  di = memoryAGet16(ds, 0xe8cb);
  memoryASet16(ds, 0xe8cb, memoryAGet16(ds, 0xe8cb) + 1);
  memoryASet(es, di + 40, al);
  memoryASet(es, di + 80, al);
  memoryASet(es, di + 120, al);
  memoryASet(es, di + 160, al);
  memoryASet(es, di + 200, al);
  memoryASet(es, di + 240, al);
  if (--cx)
    goto loc_12c94;
}
void sub_12d22()
{
  goto loc_12d22;
loc_12cc5:
  memoryASet16(ds, 0xe8cb, 0x0160);
  al = memoryAGet(ds, 0x03e5);
  sub_12d86();
  al = memoryAGet(ds, 0x03e5);
  al &= 0x0f;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  sub_12d86();
  al = memoryAGet(ds, 0x03e4);
  sub_12d86();
  al = memoryAGet(ds, 0x03e4);
  al &= 0x0f;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  sub_12d86();
  al = memoryAGet(ds, 0x03e3);
  sub_12d86();
  al = memoryAGet(ds, 0x03e3);
  al &= 0x0f;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  sub_12d86();
  al = memoryAGet(ds, 0x03e2);
  sub_12d86();
  al = memoryAGet(ds, 0x03e2);
  al &= 0x0f;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  goto loc_12d86;
loc_12d22:
  if (memoryAGet(ds, 0x03db) != 0x01)
    goto loc_12d2b;
  goto loc_12cc5;
loc_12d2b:
  memoryASet16(ds, 0xe8cb, 0x0140);
  al = memoryAGet(ds, 0x03e1);
  sub_12d86();
  al = memoryAGet(ds, 0x03e1);
  al &= 0x0f;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  sub_12d86();
  al = memoryAGet(ds, 0x03e0);
  sub_12d86();
  al = memoryAGet(ds, 0x03e0);
  al &= 0x0f;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  sub_12d86();
  al = memoryAGet(ds, 0x03df);
  sub_12d86();
  al = memoryAGet(ds, 0x03df);
  al &= 0x0f;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  sub_12d86();
  al = memoryAGet(ds, 0x03de);
  sub_12d86();
  al = memoryAGet(ds, 0x03de);
  al &= 0x0f;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
loc_12d86:
  cx = 0xa000;
  es = cx;
  al &= 0xf0;
  al >>= 1;
  ah = 0;
  ax += 0xf166;
  si = ax;
  di = memoryAGet16(ds, 0xe8cb);
  memoryASet16(ds, 0xe8cb, memoryAGet16(ds, 0xe8cb) + 1);
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
}
void sub_12d86()
{
  cx = 0xa000;
  es = cx;
  al &= 0xf0;
  al >>= 1;
  ah = 0;
  ax += 0xf166;
  si = ax;
  di = memoryAGet16(ds, 0xe8cb);
  memoryASet16(ds, 0xe8cb, memoryAGet16(ds, 0xe8cb) + 1);
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
}
void sub_12dc0()
{
  goto loc_12dc0;
loc_105b0:
  memoryASet(ds, 0x03cc, 0x00);
  sub_1285e();
loc_105b8:
  sub_13c25();
  sub_13ef4();
  sub_13c09();
  memoryASet(ds, 0x03db, 0x01);
loc_105c6:
  sub_13c31();
  tx = flags.carry | (flags.zero << 1);
  push(tx);
  sub_12bfa();
  tx = pop();
  flags.carry = tx & 1;
  flags.zero = (tx << 1) & 1;
  if (stop(/*1*/))
    goto loc_105b0;
loc_105d0:
  sub_11719();
  sub_1172b();
  sub_12c6a();
  memoryASet(ds, 0x047e, 0x00);
  memoryASet(ds, 0x047f, 0x00);
  sub_12b78();
  memoryASet(ds, 0x03b7, 0x00);
  memoryASet(ds, 0x03f0, 0xff);
  sub_123ba();
  sub_10711();
  sub_114e1();
loc_105f9:
  sub_1080a();
  if (memoryAGet(ds, 0x03b7) != 0x00)
    goto loc_10619;
  if (memoryAGet(ds, 0x03cd) == 0x02)
    goto loc_1064a;
  if (memoryAGet16(ds, 0x03ee) == 0x0000)
    goto loc_10616;
  sub_12dc0();
  goto loc_105f9;
loc_10616:
  sub_1269a();
loc_10619:
  memoryASet(ds, 0x03f0, 0xff);
  if (memoryAGet(ds, 0x03cb) != 0x00)
    goto loc_1063c;
  bx = 0x03dc;
  if (memoryAGet(ds, 0x03db) == 0x00)
    goto loc_10630;
  bx++;
loc_10630:
  memoryASet(ds, bx, memoryAGet(ds, bx) - 1);
  push(bx);
  sub_12c6a();
  bx = pop();
  if (memoryAGet(ds, bx) == 0x00)
    goto loc_10641;
loc_1063c:
  sub_12407();
  goto loc_105c6;
loc_10641:
  sub_123f7();
  sub_12676();
  goto loc_105c6;
loc_1064a:
  memoryASet(ds, 0x03f0, 0xff);
  al = memoryAGet(ds, 0x03ad);
  push(ax);
  push(memoryAGet16(ds, 0x03ae));
  push(memoryAGet16(ds, 0x046e));
  sub_126d5();
  sub_123ba();
  memoryASet(ds, 0x03cd, 0x03);
  sub_10711();
  memoryASet16(ds, 0x046e, pop());
  memoryASet16(ds, 0x03ae, pop());
  ax = pop();
  memoryASet(ds, 0x03ad, al);
  memoryASet(ds, 0x03b4, 0x04);
  memoryASet(ds, 0x03b3, 0x1d);
  memoryASet(ds, 0x03b6, 0x00);
loc_10684:
  sub_1080a();
  sub_12dc0();
  if (memoryAGet(ds, 0x03cd) != 0x04)
    goto loc_10684;
  memoryASet(ds, 0x03cd, 0x00);
  sub_123d6();
  if (al != 0x08)
    goto loc_106a6;
  sub_123f7();
  sub_126bb();
  goto loc_105c6;
loc_106a6:
  sub_12407();
  sub_12bfa();
  sub_11719();
  sub_1172b();
  sub_10b17();
  goto loc_105d0;
  //   gap of 9988 bytes
loc_12dbc:
  ax = pop();
  goto loc_1517b;
loc_12dc0:
  if (memoryAGet(ds, 0x0475) == 0x00)
    goto loc_12dc8;
  return;
loc_12dc8:
  if (memoryAGet(ds, 0xe5ba) == 0x01)
    goto loc_12dbc;
  goto loc_12dfc;
  //   gap of 43 bytes
loc_12dfc:
  if (memoryAGet(ds, 0x03cc) != 0x00)
    goto loc_12e1d;
  if (memoryAGet(ds, 0x03f0) != 0x00)
    goto loc_12e38;
  if (memoryAGet(ds, 0xe5fd) != 0x01)
    goto loc_12e38;
  memoryASet(ds, 0x03cc, 0xff);
  memoryASet(ds, 0x03f0, 0xff);
  goto loc_12e38;
loc_12e1d:
  sub_1264f();
  if (memoryAGet(ds, 0xe639) != 0x10)
    goto loc_12e38;
  memoryASet(ds, 0x03cc, 0x00);
  al = memoryAGet(ds, 0x03cb);
  if (al & 0x80)
    goto loc_12e35;
  al = 0x01;
loc_12e35:
  memoryASet(ds, 0x03f0, al);
loc_12e38:
  if (memoryAGet(ds, 0x03cb) != 0x00)
    goto loc_12e40;
  return;
loc_12e40:
  if (memoryAGet(ds, 0xe5e3) == 0x01)
    goto loc_12e48;
  return;
loc_12e48:
  bl = 0;
  if (memoryAGet(ds, 0xe5bb) == 0x01)
    goto loc_12e91;
  bl++;
  if (memoryAGet(ds, 0xe5bc) == 0x01)
    goto loc_12e91;
  bl++;
  if (memoryAGet(ds, 0xe5bd) == 0x01)
    goto loc_12e91;
  bl++;
  if (memoryAGet(ds, 0xe5be) == 0x01)
    goto loc_12e91;
  bl++;
  if (memoryAGet(ds, 0xe5bf) == 0x01)
    goto loc_12e91;
  bl++;
  if (memoryAGet(ds, 0xe5c0) == 0x01)
    goto loc_12e91;
  bl++;
  if (memoryAGet(ds, 0xe5c1) == 0x01)
    goto loc_12e91;
  bl++;
  if (memoryAGet(ds, 0xe5c2) == 0x01)
    goto loc_12e91;
  return;
loc_12e91:
  memoryASet(ds, 0x0477, bl);
  ax = pop();
  memoryASet(ds, 0x03cc, 0x00);
  goto loc_105b8;
  //   gap of 8925 bytes
loc_1517b:
  sub_125fc();
  sub_1509e();
  es = memoryAGet16(ds, 0x0480);
  ah = 0x49;
  interrupt(0x21);
  ax = 0x4c00;
  interrupt(0x21);
  dx = 0x03da;
loc_15191:
  in(al, dx);
  al &= 0x08;
  if (al == 0)
    goto loc_15191;
  dx = 0x03da;
loc_15199:
  in(al, dx);
  al &= 0x08;
  if (al != 0)
    goto loc_15199;
}
void sub_12ec1()
{
  bp = 0x039d;
  cx = 0x0004;
loc_12ec7:
  if (memoryAGet(ds, bp) != 0xff)
    goto loc_12eeb;
  al = memoryAGet(ds, bx);
  al &= 0x0c;
  if (al == 0x04)
    goto loc_12eee;
  al = memoryAGet(ds, bx);
  memoryASet(ds, bp + 12, al);
  memoryASet(ds, bp + 4, bl);
  memoryASet(ds, bp + 8, bh);
  memoryASet(ds, bp, 0x7d);
  flags.carry = true;
  return;
loc_12eeb:
  bp++;
  if (--cx)
    goto loc_12ec7;
loc_12eee:
  flags.carry = false;
}
void sub_12ef0()
{
  bp = 0x039d;
  cx = 0x0004;
loc_12ef6:
  al = memoryAGet(ds, bp);
  if (!al)
    goto loc_12f08;
  if (al == 0xff)
    goto loc_12f43;
  memoryASet(ds, bp, memoryAGet(ds, bp) - 1);
  goto loc_12f43;
loc_12f08:
  bl = memoryAGet(ds, bp + 4);
  bh = memoryAGet(ds, bp + 8);
  al = memoryAGet(ds, bp + 12);
  al &= 0x0c;
  memoryASet(ds, bx, al);
  bx--;
  dl = memoryAGet(ds, bp + 4);
  dh = memoryAGet(ds, bp + 8);
  dx--;
  memoryASet(ds, bp + 4, dl);
  memoryASet(ds, bp + 8, dh);
  al = memoryAGet(ds, bx);
  memoryASet(ds, bp + 12, al);
  al &= 0x0c;
  if (al == 0x04)
    goto loc_12f3b;
  memoryASet(ds, bx, 0x8d);
  goto loc_12f43;
loc_12f3b:
  memoryASet(ds, bx, 0x85);
  memoryASet(ds, bp, 0xff);
loc_12f43:
  bp++;
  if (--cx)
    goto loc_12ef6;
}
void sub_12f58()
{
  sub_1305f();
  bx--;
  if (memoryAGet(ds, bx) == 0x85)
    goto loc_12f6d;
  if (memoryAGet(ds, bx) == 0x89)
    goto loc_12f71;
  if (memoryAGet(ds, bx) == 0x8d)
    goto loc_12f73;
  flags.carry = false;
  return;
loc_12f6d:
  al = 0x01;
  flags.carry = true;
  return;
loc_12f71:
  al = 0xff;
loc_12f73:
  flags.carry = true;
}
void sub_1305f()
{
  bx = memoryAGet16(ds, 0x03ae);
  sub_13077();
  bl = al;
  bh = memoryAGet(ds, 0x03ad);
  bh >>= 1;
  bh >>= 1;
  bh >>= 1;
  bx += 0x055c;
}
void sub_13077()
{
  push(bx);
  al = bl;
  bh >>= 1;
  stop(/*carry1*/);
  al = rcr(al, 0x01);
  bh >>= 1;
  stop(/*carry1*/);
  al = rcr(al, 0x01);
  bx = pop();
}
void sub_13114()
{
  ax = 0x1532;
  es = ax;
  si = 0xe901;
  di = 0xe8fc;
  cx = 0x0005;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  memoryASet(ds, 0xe8f2, 0xff);
  al = 0x01;
  memoryASet(ds, 0xe910, al);
  sub_13252();
  cx = 0x0032;
loc_13134:
  sub_1518e();
  if (--cx)
    goto loc_13134;
  al = 0;
  sub_1313f();
}
void sub_1313f()
{
  memoryASet(ds, 0xe912, al);
  sub_114e1();
loc_13145:
  sub_13252();
  al = memoryAGet(ds, 0xe910);
  if (al != 0x01)
    goto loc_13177;
  al = 0x0b;
  sub_114e7();
  bx = 0xe8fd;
  cx = 0x0004;
loc_1315a:
  al = memoryAGet(ds, bx);
  al -= 0x02;
  memoryASet(ds, bx, al);
  bx++;
  if (--cx)
    goto loc_1315a;
  if (al != 0x68)
    goto loc_13145;
  memoryASet(ds, 0xe910, memoryAGet(ds, 0xe910) + 1);
  memoryASet(ds, 0xe911, 0x00);
  al = 0x03;
  sub_114e7();
  goto loc_13145;
loc_13177:
  if (al != 0x02)
    goto loc_131ab;
  al = memoryAGet(ds, 0xe911);
  al >>= 1;
  ah = 0;
  cx = ax;
  bx = 0xe906;
  bx += cx;
  al = memoryAGet(ds, bx);
  memoryASet(ds, 0xe8f8, al);
  bx = 0xe90b;
  bx += cx;
  al = memoryAGet(ds, bx);
  memoryASet(ds, 0xe8f3, al);
  memoryASet(ds, 0xe911, memoryAGet(ds, 0xe911) + 1);
  if (memoryAGet(ds, 0xe911) == 0x09)
    goto loc_131a5;
  goto loc_13145;
loc_131a5:
  memoryASet(ds, 0xe910, memoryAGet(ds, 0xe910) + 1);
  goto loc_13145;
loc_131ab:
  if (al != 0x03)
    goto loc_13200;
  if (memoryAGet(ds, 0xe912) != 0x00)
    goto loc_131db;
  memoryASet(ds, 0xe8f2, 0x00);
  al = memoryAGet(ds, 0xe8fc);
  al -= 0x02;
  memoryASet(ds, 0xe8fc, al);
  if (al == 0x54)
    goto loc_131ca;
  goto loc_13145;
loc_131ca:
  memoryASet(ds, 0xe910, memoryAGet(ds, 0xe910) + 1);
  memoryASet(ds, 0xe911, 0x08);
  al = 0x03;
  sub_114e7();
  goto loc_13145;
loc_131db:
  al = memoryAGet(ds, 0xe8fc);
  al += 0x02;
  memoryASet(ds, 0xe8fc, al);
  if (al == 0x66)
    goto loc_131ea;
  goto loc_13145;
loc_131ea:
  memoryASet(ds, 0xe910, memoryAGet(ds, 0xe910) + 1);
  memoryASet(ds, 0xe8f2, 0xff);
  memoryASet(ds, 0xe911, 0x08);
  al = 0x03;
  sub_114e7();
  goto loc_13145;
loc_13200:
  if (al != 0x04)
    goto loc_13236;
  al = memoryAGet(ds, 0xe911);
  al >>= 1;
  ah = 0;
  cx = ax;
  bx = 0xe906;
  bx += cx;
  al = memoryAGet(ds, bx);
  memoryASet(ds, 0xe8f8, al);
  bx = 0xe90b;
  bx += cx;
  al = memoryAGet(ds, bx);
  memoryASet(ds, 0xe8f3, al);
  memoryASet(ds, 0xe911, memoryAGet(ds, 0xe911) - 1);
  if (memoryAGet(ds, 0xe911) & 0x80)
    goto loc_1322f;
  goto loc_13145;
loc_1322f:
  memoryASet(ds, 0xe910, memoryAGet(ds, 0xe910) + 1);
  goto loc_13145;
loc_13236:
  al = 0x0b;
  sub_114e7();
  bx = 0xe8fd;
  cx = 0x0004;
loc_13241:
  al = memoryAGet(ds, bx);
  al += 0x02;
  memoryASet(ds, bx, al);
  bx++;
  if (--cx)
    goto loc_13241;
  if (al == 0x90)
    return;
  goto loc_13145;
}
void sub_13252()
{
  sub_100d1();
  sub_11e4d();
  sub_1178e();
  sub_1518e();
  sub_1152b();
  sub_11abc();
  sub_11cd7();
  sub_13277();
  sub_11840();
  sub_12317();
  sub_1226a();
  sub_100d8();
}
void sub_13277()
{
  ax = memoryAGet16(ds, 0x0480);
  es = ax;
  bp = 0xe8f2;
  cx = 0x0005;
loc_13282:
  push(bp);
  push(cx);
  if (memoryAGet(ds, bp) != 0xff)
    goto loc_1328e;
  goto loc_133d4;
loc_1328e:
  al = memoryAGet(ds, bp + 5);
  al >>= 1;
  al >>= 1;
  al >>= 1;
  ah = memoryAGet(ds, bp + 10);
  ah -= 0x08;
  sub_14e44();
  ax -= 0x0007;
  if (memoryAGet(ds, bp) != 0x00)
    goto loc_132b0;
  ax++;
  ax += 0x00a0;
loc_132b0:
  push(ax);
  al = memoryAGet(ds, bp);
  sub_13cc3();
  si = bx;
  di = pop();
  al = memoryAGet(ds, bp + 10);
  if (al < 0x7c)
    goto loc_132c6;
  goto loc_133d4;
loc_132c6:
  ah = cl;
  cl = 0x14;
  if (al < 0x6a)
    goto loc_132d6;
  cl = al;
  al = 0x7c;
  al -= cl;
  cl = al;
loc_132d6:
  ch = 0;
  bx = 0x0004;
  if (ah != 0x04)
    goto loc_132e3;
  goto loc_1339d;
loc_132e3:
  if (ah != 0x03)
    goto loc_132ea;
  goto loc_13328;
loc_132ea:
  ax = memoryAGet16(es, di);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 2);
  memoryASet16(es, di, ax);
  ax = memoryAGet16(es, di + 40);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 4);
  memoryASet16(es, di + 40, ax);
  ax = memoryAGet16(es, di + 80);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 6);
  memoryASet16(es, di + 80, ax);
  ax = memoryAGet16(es, di + 120);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 8);
  memoryASet16(es, di + 120, ax);
  di += 0x00a0;
  si += 0x000a;
  if (--cx)
    goto loc_132ea;
  goto loc_133d4;
loc_13328:
  ax = memoryAGet16(es, di);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 3);
  memoryASet16(es, di, ax);
  al = memoryAGet(es, di + 2);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 5);
  memoryASet(es, di + 2, al);
  ax = memoryAGet16(es, di + 40);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 6);
  memoryASet16(es, di + 40, ax);
  al = memoryAGet(es, di + 42);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 8);
  memoryASet(es, di + 42, al);
  ax = memoryAGet16(es, di + 80);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 9);
  memoryASet16(es, di + 80, ax);
  al = memoryAGet(es, di + 82);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 11);
  memoryASet(es, di + 82, al);
  ax = memoryAGet16(es, di + 120);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 12);
  memoryASet16(es, di + 120, ax);
  al = memoryAGet(es, di + 122);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 14);
  memoryASet(es, di + 122, al);
  di += 0x00a0;
  si += 0x000f;
  if (--cx)
    goto loc_13328;
  goto loc_133d4;
loc_1339d:
  goto loc_133d4;
  //   gap of 53 bytes
loc_133d4:
  cx = pop();
  bp = pop();
  bp++;
  cx--;
  if (cx == 0)
    return;
  goto loc_13282;
}
// skipping indirect jump
void sub_13741()
{
  bx = 0x045e;
  if (memoryAGet(ds, bx) != 0x00)
    goto loc_13754;
  al = memoryAGet(ds, 0x045a);
  if (!al)
    goto loc_13764;
  memoryASet(ds, bx, al);
  goto loc_13764;
loc_13754:
  al = memoryAGet(ds, 0x045a);
  if (al)
    goto loc_1375f;
  memoryASet(ds, bx, al);
  goto loc_13764;
loc_1375f:
  memoryASet(ds, 0x045a, 0x00);
loc_13764:
  al = memoryAGet(ds, 0x03b4);
  ah = 0;
  bx = ax;
  bx <<= 1;
  stop(/*2*/); // (jmp word ptr cs:[bx + 0x3772]) jump Indirect memoryAGet16(cs, bx + 14194)
}
void sub_139f1()
{
  memoryASet(ds, 0xe974, al);
  memoryASet(ds, 0xe975, 0xfd);
  memoryASet(ds, 0xe976, 0x02);
  memoryASet(ds, 0xe977, 0x00);
  memoryASet(ds, 0xe97b, 0x00);
  memoryASet(ds, 0xe97c, 0x09);
  goto loc_13a61;
  //   gap of 82 bytes
loc_13a61:
  al = memoryAGet(ds, 0xe974);
  al += memoryAGet(ds, 0xe975);
  al >>= 1;
  al >>= 1;
  al >>= 1;
  al &= 0x0f;
  memoryASet(ds, 0xe972, al);
  al = memoryAGet(ds, 0xe974);
  al += memoryAGet(ds, 0xe976);
  al >>= 1;
  al >>= 1;
  al >>= 1;
  al++;
  al &= 0x0f;
  memoryASet(ds, 0xe973, al);
  al = bl;
  bx >>= 1;
  bx >>= 1;
  ch = al;
  al = memoryAGet(ds, 0xe977);
  tl = al;
  cl = al;
  al = ch;
  if (tl == 0)
    goto loc_13aa0;
  cl--;
  if (cl != 0)
    goto loc_13ab5;
  goto loc_13ab9;
loc_13aa0:
  al &= 0x03;
  flags.carry = !flags.carry;
  al = 0x02;
  stop(/*8*/); // inject carry failed
  al += flags.carry;
  memoryASet(ds, 0x03d1, al);
  al = memoryAGet(ds, 0xe972);
  memoryASet(ds, 0xe97f, bl);
  goto loc_13acc;
loc_13ab5:
  ch = 0x00;
  goto loc_13abb;
loc_13ab9:
  ch = 0x01;
loc_13abb:
  al &= 0x03;
  if (al == 0)
    goto loc_13ac1;
  ch++;
loc_13ac1:
  memoryASet(ds, 0x03d1, ch);
  al = memoryAGet(ds, 0xe972);
  memoryASet(ds, 0xe97f, bl);
loc_13acc:
  bh = al;
  bl = memoryAGet(ds, 0xe97f);
  bx += 0x055c;
  al = memoryAGet(ds, 0x03d1);
  ah = 0;
  memoryASet16(ds, 0xe97d, ax);
loc_13ade:
  memoryASet16(ds, 0xe979, bx);
  bx += memoryAGet16(ds, 0xe97d);
  al = memoryAGet(ds, bx);
  if (!(al & 0x80))
    goto loc_13b5a;
  al &= 0x0f;
  if (al < 0x04)
    goto loc_13afc;
  al &= 0x03;
  if (al != 0x01)
    goto loc_13afc;
  al = 0;
  goto loc_13b08;
loc_13afc:
  al &= 0x03;
  if (al == 0x03)
    goto loc_13b5a;
  flags.carry = al & 1;
  al >>= 1;
  if (!flags.carry)
    goto loc_13b08;
  goto loc_13b81;
loc_13b08:
  memoryASet(ds, 0xe978, al);
  al = memoryAGet(ds, 0xe972);
  al += al;
  al += al;
  flags.carry = (al + al) >= 0x100;
  al += al;
  tl = flags.carry;
  flags.carry = (al + memoryAGet(ds, 0xe97b) + tl) >= 0x100;
  al += memoryAGet(ds, 0xe97b) + tl;
  memoryASet(ds, 0xe980, al);
  al += memoryAGet(ds, 0xe97c) + flags.carry;
  memoryASet(ds, 0xe981, al);
  al = memoryAGet(ds, 0xe974);
  if (al < memoryAGet(ds, 0xe980))
    goto loc_13b5a;
  if (al >= memoryAGet(ds, 0xe981))
    goto loc_13b5a;
  al = memoryAGet(ds, 0xe978);
  if (!al)
    goto loc_13b81;
  if (memoryAGet(ds, 0xe977) != 0x02)
    goto loc_13b81;
  memoryASet(ds, 0x03d9, memoryAGet(ds, 0x03d9) + 1);
  memoryASet(ds, bx, 0x00);
  push(bx);
  bx = 0x0050;
  sub_1242f();
  al = 0x02;
  sub_12c17();
  al = 0x09;
  sub_114e7();
  bx = pop();
  goto loc_13b81;
loc_13b5a:
  bx = memoryAGet16(ds, 0xe979);
  memoryASet(ds, 0xe97d, memoryAGet(ds, 0xe97d) - 1);
  if (memoryAGet(ds, 0xe97d) == 0xff)
    goto loc_13b6c;
  goto loc_13ade;
loc_13b6c:
  al = memoryAGet(ds, 0xe972);
  al++;
  al &= 0x0f;
  memoryASet(ds, 0xe972, al);
  if (al == memoryAGet(ds, 0xe973))
    goto loc_13b7f;
  goto loc_13acc;
loc_13b7f:
  flags.carry = false;
  return;
loc_13b81:
  flags.carry = true;
}
void sub_13a0f()
{
  al = memoryAGet(ds, bp);
  memoryASet(ds, 0xe974, al);
  bl = memoryAGet(ds, bp + 6);
  bh = memoryAGet(ds, bp + 12);
  memoryASet(ds, 0xe975, 0xfe);
  memoryASet(ds, 0xe976, 0x01);
  memoryASet(ds, 0xe977, 0x01);
  memoryASet(ds, 0xe97b, 0x01);
  memoryASet(ds, 0xe97c, 0x07);
  goto loc_13a61;
  //   gap of 40 bytes
loc_13a61:
  al = memoryAGet(ds, 0xe974);
  al += memoryAGet(ds, 0xe975);
  al >>= 1;
  al >>= 1;
  al >>= 1;
  al &= 0x0f;
  memoryASet(ds, 0xe972, al);
  al = memoryAGet(ds, 0xe974);
  al += memoryAGet(ds, 0xe976);
  al >>= 1;
  al >>= 1;
  al >>= 1;
  al++;
  al &= 0x0f;
  memoryASet(ds, 0xe973, al);
  al = bl;
  bx >>= 1;
  bx >>= 1;
  ch = al;
  al = memoryAGet(ds, 0xe977);
  tl = al;
  cl = al;
  al = ch;
  if (tl == 0)
    goto loc_13aa0;
  cl--;
  if (cl != 0)
    goto loc_13ab5;
  goto loc_13ab9;
loc_13aa0:
  al &= 0x03;
  flags.carry = !flags.carry;
  al = 0x02;
  stop(/*8*/); // inject carry failed
  al += flags.carry;
  memoryASet(ds, 0x03d1, al);
  al = memoryAGet(ds, 0xe972);
  memoryASet(ds, 0xe97f, bl);
  goto loc_13acc;
loc_13ab5:
  ch = 0x00;
  goto loc_13abb;
loc_13ab9:
  ch = 0x01;
loc_13abb:
  al &= 0x03;
  if (al == 0)
    goto loc_13ac1;
  ch++;
loc_13ac1:
  memoryASet(ds, 0x03d1, ch);
  al = memoryAGet(ds, 0xe972);
  memoryASet(ds, 0xe97f, bl);
loc_13acc:
  bh = al;
  bl = memoryAGet(ds, 0xe97f);
  bx += 0x055c;
  al = memoryAGet(ds, 0x03d1);
  ah = 0;
  memoryASet16(ds, 0xe97d, ax);
loc_13ade:
  memoryASet16(ds, 0xe979, bx);
  bx += memoryAGet16(ds, 0xe97d);
  al = memoryAGet(ds, bx);
  if (!(al & 0x80))
    goto loc_13b5a;
  al &= 0x0f;
  if (al < 0x04)
    goto loc_13afc;
  al &= 0x03;
  if (al != 0x01)
    goto loc_13afc;
  al = 0;
  goto loc_13b08;
loc_13afc:
  al &= 0x03;
  if (al == 0x03)
    goto loc_13b5a;
  flags.carry = al & 1;
  al >>= 1;
  if (!flags.carry)
    goto loc_13b08;
  goto loc_13b81;
loc_13b08:
  memoryASet(ds, 0xe978, al);
  al = memoryAGet(ds, 0xe972);
  al += al;
  al += al;
  flags.carry = (al + al) >= 0x100;
  al += al;
  tl = flags.carry;
  flags.carry = (al + memoryAGet(ds, 0xe97b) + tl) >= 0x100;
  al += memoryAGet(ds, 0xe97b) + tl;
  memoryASet(ds, 0xe980, al);
  al += memoryAGet(ds, 0xe97c) + flags.carry;
  memoryASet(ds, 0xe981, al);
  al = memoryAGet(ds, 0xe974);
  if (al < memoryAGet(ds, 0xe980))
    goto loc_13b5a;
  if (al >= memoryAGet(ds, 0xe981))
    goto loc_13b5a;
  al = memoryAGet(ds, 0xe978);
  if (!al)
    goto loc_13b81;
  if (memoryAGet(ds, 0xe977) != 0x02)
    goto loc_13b81;
  memoryASet(ds, 0x03d9, memoryAGet(ds, 0x03d9) + 1);
  memoryASet(ds, bx, 0x00);
  push(bx);
  bx = 0x0050;
  sub_1242f();
  al = 0x02;
  sub_12c17();
  al = 0x09;
  sub_114e7();
  bx = pop();
  goto loc_13b81;
loc_13b5a:
  bx = memoryAGet16(ds, 0xe979);
  memoryASet(ds, 0xe97d, memoryAGet(ds, 0xe97d) - 1);
  if (memoryAGet(ds, 0xe97d) == 0xff)
    goto loc_13b6c;
  goto loc_13ade;
loc_13b6c:
  al = memoryAGet(ds, 0xe972);
  al++;
  al &= 0x0f;
  memoryASet(ds, 0xe972, al);
  if (al == memoryAGet(ds, 0xe973))
    goto loc_13b7f;
  goto loc_13acc;
loc_13b7f:
  flags.carry = false;
  return;
loc_13b81:
  flags.carry = true;
}
void sub_13a39()
{
  al = memoryAGet(ds, bp);
  memoryASet(ds, 0xe974, al);
  bl = memoryAGet(ds, bp + 6);
  bh = memoryAGet(ds, bp + 12);
  memoryASet(ds, 0xe975, 0xff);
  memoryASet(ds, 0xe976, 0x00);
  memoryASet(ds, 0xe977, 0x02);
  memoryASet(ds, 0xe97b, 0x02);
  memoryASet(ds, 0xe97c, 0x05);
  al = memoryAGet(ds, 0xe974);
  al += memoryAGet(ds, 0xe975);
  al >>= 1;
  al >>= 1;
  al >>= 1;
  al &= 0x0f;
  memoryASet(ds, 0xe972, al);
  al = memoryAGet(ds, 0xe974);
  al += memoryAGet(ds, 0xe976);
  al >>= 1;
  al >>= 1;
  al >>= 1;
  al++;
  al &= 0x0f;
  memoryASet(ds, 0xe973, al);
  al = bl;
  bx >>= 1;
  bx >>= 1;
  ch = al;
  al = memoryAGet(ds, 0xe977);
  tl = al;
  cl = al;
  al = ch;
  if (tl == 0)
    goto loc_13aa0;
  cl--;
  if (cl != 0)
    goto loc_13ab5;
  goto loc_13ab9;
loc_13aa0:
  al &= 0x03;
  flags.carry = !flags.carry;
  al = 0x02;
  stop(/*8*/); // inject carry failed
  al += flags.carry;
  memoryASet(ds, 0x03d1, al);
  al = memoryAGet(ds, 0xe972);
  memoryASet(ds, 0xe97f, bl);
  goto loc_13acc;
loc_13ab5:
  ch = 0x00;
  goto loc_13abb;
loc_13ab9:
  ch = 0x01;
loc_13abb:
  al &= 0x03;
  if (al == 0)
    goto loc_13ac1;
  ch++;
loc_13ac1:
  memoryASet(ds, 0x03d1, ch);
  al = memoryAGet(ds, 0xe972);
  memoryASet(ds, 0xe97f, bl);
loc_13acc:
  bh = al;
  bl = memoryAGet(ds, 0xe97f);
  bx += 0x055c;
  al = memoryAGet(ds, 0x03d1);
  ah = 0;
  memoryASet16(ds, 0xe97d, ax);
loc_13ade:
  memoryASet16(ds, 0xe979, bx);
  bx += memoryAGet16(ds, 0xe97d);
  al = memoryAGet(ds, bx);
  if (!(al & 0x80))
    goto loc_13b5a;
  al &= 0x0f;
  if (al < 0x04)
    goto loc_13afc;
  al &= 0x03;
  if (al != 0x01)
    goto loc_13afc;
  al = 0;
  goto loc_13b08;
loc_13afc:
  al &= 0x03;
  if (al == 0x03)
    goto loc_13b5a;
  flags.carry = al & 1;
  al >>= 1;
  if (!flags.carry)
    goto loc_13b08;
  goto loc_13b81;
loc_13b08:
  memoryASet(ds, 0xe978, al);
  al = memoryAGet(ds, 0xe972);
  al += al;
  al += al;
  flags.carry = (al + al) >= 0x100;
  al += al;
  tl = flags.carry;
  flags.carry = (al + memoryAGet(ds, 0xe97b) + tl) >= 0x100;
  al += memoryAGet(ds, 0xe97b) + tl;
  memoryASet(ds, 0xe980, al);
  al += memoryAGet(ds, 0xe97c) + flags.carry;
  memoryASet(ds, 0xe981, al);
  al = memoryAGet(ds, 0xe974);
  if (al < memoryAGet(ds, 0xe980))
    goto loc_13b5a;
  if (al >= memoryAGet(ds, 0xe981))
    goto loc_13b5a;
  al = memoryAGet(ds, 0xe978);
  if (!al)
    goto loc_13b81;
  if (memoryAGet(ds, 0xe977) != 0x02)
    goto loc_13b81;
  memoryASet(ds, 0x03d9, memoryAGet(ds, 0x03d9) + 1);
  memoryASet(ds, bx, 0x00);
  push(bx);
  bx = 0x0050;
  sub_1242f();
  al = 0x02;
  sub_12c17();
  al = 0x09;
  sub_114e7();
  bx = pop();
  goto loc_13b81;
loc_13b5a:
  bx = memoryAGet16(ds, 0xe979);
  memoryASet(ds, 0xe97d, memoryAGet(ds, 0xe97d) - 1);
  if (memoryAGet(ds, 0xe97d) == 0xff)
    goto loc_13b6c;
  goto loc_13ade;
loc_13b6c:
  al = memoryAGet(ds, 0xe972);
  al++;
  al &= 0x0f;
  memoryASet(ds, 0xe972, al);
  if (al == memoryAGet(ds, 0xe973))
    goto loc_13b7f;
  goto loc_13acc;
loc_13b7f:
  flags.carry = false;
  return;
loc_13b81:
  flags.carry = true;
}
void sub_13be1()
{
  ax = memoryAGet16(ds, 0x03b0);
  flags.carry = ax < memoryAGet16(ds, 0x03ae);
  ax -= memoryAGet16(ds, 0x03ae);
  if (flags.carry)
    goto loc_13beb;
  return;
loc_13beb:
  ax = memoryAGet16(ds, 0x03b0);
  cx = memoryAGet16(ds, 0x03ae);
  if (al != cl)
    goto loc_13bfb;
  if (ah != ch)
    goto loc_13bfb;
  return;
loc_13bfb:
  push(ax);
  bx = 0x0010;
  sub_1242f();
  ax = pop();
  ax++;
  memoryASet16(ds, 0x03b0, ax);
  goto loc_13beb;
}
void sub_13c09()
{
  memoryASet(ds, 0x03dc, 0x03);
  memoryASet(ds, 0x03dd, 0x03);
  memoryASet(ds, 0x03b6, 0x00);
  bx = 0x03de;
  cx = 0x0008;
loc_13c1e:
  memoryASet(ds, bx, 0x00);
  bx++;
  if (--cx)
    goto loc_13c1e;
}
void sub_13c25()
{
  al = memoryAGet(ds, 0x0477);
  ah = 0xff;
  memoryASet16(ds, 0x0471, ax);
  memoryASet16(ds, 0x0473, ax);
}
void sub_13c31()
{
  al = 0;
  bx = 0x03db;
  if (memoryAGet(ds, 0x03da) == 0x01)
    goto loc_13c41;
  al++;
  al -= memoryAGet(ds, bx);
loc_13c41:
  memoryASet(ds, bx, al);
  bx = 0x0472;
  if (!al)
    goto loc_13c4c;
  bx++;
  bx++;
loc_13c4c:
  if (memoryAGet(ds, bx) != 0x00)
    goto loc_13c70;
  if (memoryAGet(ds, 0x03da) == 0x01)
    goto loc_13c8e;
  al = 0x01;
  al -= memoryAGet(ds, 0x03db);
  memoryASet(ds, 0x03db, al);
  bx = 0x0472;
  if (!al)
    goto loc_13c6a;
  bx++;
  bx++;
loc_13c6a:
  al = memoryAGet(ds, bx);
  if (!al)
    goto loc_13c8e;
loc_13c70:
  bx--;
  al = memoryAGet(ds, bx);
  memoryASet(ds, 0x03d4, al);
  bx++;
  ah = memoryAGet(ds, bx);
  bx = 0x03bf;
  cx = 0x0008;
loc_13c7f:
  al = 0;
    flags.carry = false;
  ah = rcr(ah, 0x01);
  if (!flags.carry)
    goto loc_13c87;
  al++;
loc_13c87:
  memoryASet(ds, bx, al);
  bx++;
  if (--cx)
    goto loc_13c7f;
  flags.carry = true;
  return;
loc_13c8e:
  flags.carry = false;
}
void sub_13c90()
{
  if (memoryAGet(ds, 0x0455) == 0x00)
    goto loc_13c9c;
  sub_1034d();
  goto loc_13c9f;
loc_13c9c:
  sub_1264f();
loc_13c9f:
  al = memoryAGet(ds, 0xe639);
  ah = al;
  al &= 0x01;
  ah >>= 1;
  flags.carry = ah & 1;
  ah >>= 1;
  al -= flags.carry;
  memoryASet(ds, 0x045b, al);
  al = ah;
  al &= 0x01;
  ah >>= 1;
  flags.carry = ah & 1;
  ah >>= 1;
  al -= flags.carry;
  al = -al;
  memoryASet(ds, 0x045c, al);
  memoryASet(ds, 0x045a, ah);
}
void sub_13cc3()
{
  bl = memoryAGet(ds, 0x047e);
  bh = 0;
  bx <<= 1;
  bx += 0xe982;
  bx = memoryAGet16(ds, bx);
  ah = 0;
  ax <<= 1;
  bx += ax;
  bx = memoryAGet16(ds, bx);
  cx = memoryAGet16(ds, bx);
  bx++;
  bx++;
}
void sub_13cde()
{
  bp = 0x03fa;
  memoryASet(ds, bp + 42, 0xff);
}
void sub_13ce7()
{
  bp = 0x03fa;
  memoryASet(ds, bp + 18, 0x00);
  al = memoryAGet(ds, bp + 42);
  if (al != 0xff)
    goto loc_13cf8;
  return;
loc_13cf8:
  if (al != 0x0c)
    goto loc_13d02;
loc_13cfc:
  memoryASet(ds, bp + 42, 0xff);
  return;
loc_13d02:
  cl = al;
  memoryASet(ds, bp + 42, memoryAGet(ds, bp + 42) + 1);
  al = memoryAGet(ds, bp + 54);
  al <<= 1;
  al += memoryAGet(ds, bp);
  al &= 0x7f;
  memoryASet(ds, bp, al);
  ch = 0;
  bx = 0xe992;
  bx += cx;
  al = memoryAGet(ds, bp + 6);
  flags.carry = (al + memoryAGet(ds, bx)) >= 0x100;
  al += memoryAGet(ds, bx);
  memoryASet(ds, bp + 6, al);
  al = memoryAGet(ds, bp + 12);
  al += flags.carry;
  al &= 0x03;
  memoryASet(ds, bp + 12, al);
  push(bp);
  sub_13a39();
  bp = pop();
  if (flags.carry)
    goto loc_13cfc;
  sub_109eb();
  if (flags.carry)
    goto loc_13d42;
  return;
loc_13d42:
  push(bp);
  bp = bx;
  al = memoryAGet(ds, bp + 48);
  if (al == 0x05)
    goto loc_13d7f;
  if (al == 0x08)
    goto loc_13d7f;
  if (al == 0x09)
    goto loc_13d7f;
  if (al != 0x02)
    goto loc_13d65;
  memoryASet(ds, bp + 42, 0x4b);
  memoryASet(ds, bp + 48, 0x05);
  goto loc_13d7f;
loc_13d65:
  memoryASet(ds, bp + 48, 0x04);
  memoryASet(ds, bp + 42, 0x00);
  bx = 0x0100;
  sub_1242f();
  al = 0x05;
  sub_12c17();
  al = 0x09;
  sub_114e7();
loc_13d7f:
  bp = pop();
  goto loc_13cfc;
}
void sub_13d83()
{
  if (memoryAGet(ds, 0x03b4) != 0x08)
    goto loc_13d8b;
  return;
loc_13d8b:
  if (memoryAGet(ds, 0x03b4) != 0x09)
    goto loc_13d93;
  return;
loc_13d93:
  bx = memoryAGet16(ds, 0x03f4);
  stop(/*carry1*/);
  bx = rcr(bx, 0x0001);
  bx = rcr(bx, 0x0001);
  memoryASet(ds, 0x03d1, bl);
  bp = 0x03f6;
  cx = 0x0004;
loc_13da5:
  al = memoryAGet(ds, bp + 48);
  if (al == 0x00)
    goto loc_13db1;
  bp++;
  if (--cx)
    goto loc_13da5;
  return;
loc_13db1:
  bx = memoryAGet16(ds, 0x0453);
  bx -= 0x055c;
  if (memoryAGet(ds, 0x03d5) != bl)
    goto loc_13dc2;
  goto loc_13eb3;
loc_13dc2:
  if (memoryAGet(ds, 0x03d1) != bl)
    goto loc_13dcb;
  goto loc_13eb3;
loc_13dcb:
  if (memoryAGet(ds, 0x03d1) >= bl)
    goto loc_13dd0;
  goto loc_13eb3;
loc_13dd0:
  bx += 0x055c;
loc_13dd4:
  al = memoryAGet(ds, bx);
  if (!(al & 0x80))
    goto loc_13ddc;
  goto loc_13de0;
loc_13ddc:
  al &= 0x70;
  if (al != 0)
    goto loc_13df9;
loc_13de0:
  bx -= 0x055c;
  bh++;
  bh &= 0x0f;
  al = bh;
  bx += 0x055c;
  if (al != 0x00)
    goto loc_13dd4;
  bx++;
  memoryASet16(ds, 0x0453, bx);
  return;
loc_13df9:
  memoryASet16(ds, 0x0453, bx);
  al = memoryAGet(ds, bx);
  push(ax);
  push(bx);
  bx -= 0x055c;
  bh++;
  bh &= 0x0f;
  al = bh;
  bx += 0x055c;
  if (al != 0x00)
    goto loc_13e15;
  bx++;
loc_13e15:
  memoryASet16(ds, 0x0453, bx);
  bx = pop();
  ax = pop();
  al &= 0x70;
  if (al == 0x10)
    goto loc_13e73;
  if (al >= 0x60)
    goto loc_13e5b;
  if (al >= 0x40)
    goto loc_13e43;
  if (al == 0x20)
    goto loc_13e31;
  al = 0;
  goto loc_13e33;
loc_13e31:
  al = 0x01;
loc_13e33:
  memoryASet(ds, bp + 54, al);
  memoryASet(ds, bp + 66, 0x01);
  memoryASet(ds, bp + 60, 0x00);
  goto loc_13e82;
loc_13e43:
  al &= 0x10;
  if (al == 0)
    goto loc_13e49;
  al = 0x01;
loc_13e49:
  al++;
  memoryASet(ds, bp + 54, al);
  memoryASet(ds, bp + 66, 0x08);
  memoryASet(ds, bp + 60, 0x00);
  goto loc_13e82;
loc_13e5b:
  al &= 0x10;
  if (al == 0)
    goto loc_13e61;
  al = 0x01;
loc_13e61:
  al++;
  memoryASet(ds, bp + 54, al);
  memoryASet(ds, bp + 66, 0x09);
  memoryASet(ds, bp + 60, 0x00);
  goto loc_13e82;
loc_13e73:
  memoryASet(ds, bp + 54, 0x01);
  memoryASet(ds, bp + 66, 0x02);
  memoryASet(ds, bp + 60, 0x00);
loc_13e82:
  bx -= 0x055c;
  al = bh;
  al <<= 1;
  al <<= 1;
  al <<= 1;
  al += 0x04;
  al &= 0x7f;
  memoryASet(ds, bp, al);
  stop(/*74*/);
  al = 0;
  bl = rcl(bl, 0x01);
  stop(/*carry2*/);
  al = rcl(al, 0x01);
  stop(/*carry2*/);
  bl = rcl(bl, 0x01);
  stop(/*carry2*/);
  al = rcl(al, 0x01);
  memoryASet(ds, bp + 6, bl);
  memoryASet(ds, bp + 12, al);
  memoryASet(ds, bp + 48, 0x06);
  memoryASet(ds, bp + 42, 0x00);
  return;
loc_13eb3:
  al = memoryAGet(ds, 0x043e);
  if (al != 0xff)
    goto loc_13ebb;
  return;
loc_13ebb:
  al--;
  memoryASet(ds, 0x043e, al);
  if (al == 0xff)
    goto loc_13ec5;
  return;
loc_13ec5:
  memoryASet(ds, bp + 48, 0x07);
  memoryASet(ds, bp + 42, 0x00);
  al = memoryAGet(ds, 0x043f);
  al = -al;
  memoryASet(ds, 0x043f, al);
  memoryASet(ds, bp + 54, al);
  tl = al;
  al += al;
  al = 0x00;
  if (tl >= al)
    goto loc_13ee3;
  al = 0x78;
loc_13ee3:
  memoryASet(ds, bp, al);
  bx = memoryAGet16(ds, 0x03ae);
  memoryASet(ds, bp + 6, bl);
  memoryASet(ds, bp + 12, bh);
}
void sub_13ef4()
{
  goto loc_13ef4;
loc_12c6a:
  sub_12d22();
  memoryASet(ds, 0x03db, memoryAGet(ds, 0x03db) ^ 0x01);
  sub_12d22();
  memoryASet(ds, 0x03db, memoryAGet(ds, 0x03db) ^ 0x01);
  memoryASet16(ds, 0xe8cb, 0x02c8);
  dl = memoryAGet(ds, 0x03dd);
  sub_12c91();
  memoryASet16(ds, 0xe8cb, 0x02a8);
  dl = memoryAGet(ds, 0x03dc);
  cx = 0x0008;
loc_12c94:
  al = 0x7e;
  dl--;
  if (!(dl & 0x80))
    goto loc_12c9f;
  al = 0;
loc_12c9f:
  di = memoryAGet16(ds, 0xe8cb);
  memoryASet16(ds, 0xe8cb, memoryAGet16(ds, 0xe8cb) + 1);
  memoryASet(es, di + 40, al);
  memoryASet(es, di + 80, al);
  memoryASet(es, di + 120, al);
  memoryASet(es, di + 160, al);
  memoryASet(es, di + 200, al);
  memoryASet(es, di + 240, al);
  if (--cx)
    goto loc_12c94;
  return;
  //   gap of 4655 bytes
loc_13ef4:
  bp = 0xe99e;
  sub_14f3a();
  sub_13c09();
  goto loc_12c6a;
}
void sub_13f00()
{
  ax = memoryAGet16(ds, 0x0480);
  es = ax;
  if (memoryAGet(ds, 0x03b6) != 0x00)
    goto loc_13f0d;
  return;
loc_13f0d:
  al = memoryAGet(ds, 0x03b5);
  if (memoryAGet(ds, 0x03b4) != 0x08)
    goto loc_13f27;
  bx = 0x03b2;
  if (!(memoryAGet(ds, bx) & 0x80))
    goto loc_13f23;
  al += 0x1f;
  goto loc_13f36;
loc_13f23:
  al += 0x44;
  goto loc_13f36;
loc_13f27:
  bh = al;
  al &= 0x7f;
  if (bh & 0x80)
    goto loc_13f34;
  al += 0x25;
  goto loc_13f36;
loc_13f34:
  al += 0x00;
loc_13f36:
  sub_13cc3();
  push(bx);
  push(cx);
  al = memoryAGet(ds, 0x03ae);
  al -= memoryAGet(ds, 0x046e);
  al <<= 1;
  cl = al;
  al = 0x9c;
  al -= cl;
  ah = al;
  al = 0x08;
  memoryASet16(ds, 0x0478, ax);
  sub_14e44();
  di = ax;
  di += 0x00a0;
  cx = pop();
  si = pop();
  bx = 0x0004;
  al = cl;
  cx = 0x0015;
  if (al == 0x03)
    goto loc_13fa5;
loc_13f68:
  ax = memoryAGet16(es, di);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 2);
  memoryASet16(es, di, ax);
  ax = memoryAGet16(es, di + 40);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 4);
  memoryASet16(es, di + 40, ax);
  ax = memoryAGet16(es, di + 80);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 6);
  memoryASet16(es, di + 80, ax);
  ax = memoryAGet16(es, di + 120);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 8);
  memoryASet16(es, di + 120, ax);
  si += 0x000a;
  di += 0x00a0;
  if (--cx)
    goto loc_13f68;
  goto loc_14018;
loc_13fa5:
  ax = memoryAGet16(es, di);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 3);
  memoryASet16(es, di, ax);
  al = memoryAGet(es, di + 2);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 5);
  memoryASet(es, di + 2, al);
  ax = memoryAGet16(es, di + 40);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 6);
  memoryASet16(es, di + 40, ax);
  al = memoryAGet(es, di + 42);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 8);
  memoryASet(es, di + 42, al);
  ax = memoryAGet16(es, di + 80);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 9);
  memoryASet16(es, di + 80, ax);
  al = memoryAGet(es, di + 82);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 11);
  memoryASet(es, di + 82, al);
  ax = memoryAGet16(es, di + 120);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 12);
  memoryASet16(es, di + 120, ax);
  al = memoryAGet(es, di + 122);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 14);
  memoryASet(es, di + 122, al);
  si += 0x000f;
  di += 0x00a0;
  if (--cx)
    goto loc_13fa5;
loc_14018:
  if (memoryAGet(ds, 0x03d3) != 0xff)
    goto loc_14020;
  return;
loc_14020:
  ax = memoryAGet16(ds, 0x0478);
  ah += 0x14;
  sub_14e44();
  di = ax;
  ax = 0;
  memoryASet16(es, di, ax);
  memoryASet16(es, di + 40, ax);
  memoryASet16(es, di + 80, ax);
  memoryASet16(es, di + 120, ax);
  ax = 0xffff;
  cx = 0x0003;
loc_14042:
  di += 0x00a0;
  memoryASet16(es, di, ax);
  memoryASet16(es, di + 40, ax);
  memoryASet16(es, di + 80, ax);
  memoryASet16(es, di + 120, ax);
  di += 0x00a0;
  memoryASet16(es, di, ax);
  memoryASet16(es, di + 40, ax);
  memoryASet16(es, di + 80, ax);
  memoryASet16(es, di + 120, ax);
  if (--cx)
    goto loc_14042;
  di += 0x00a0;
  memoryASet16(es, di, ax);
  memoryASet16(es, di + 40, ax);
  memoryASet16(es, di + 80, ax);
  memoryASet16(es, di + 120, ax);
  di += 0x00a0;
  ax = 0;
  memoryASet16(es, di, ax);
  memoryASet16(es, di + 40, ax);
  memoryASet16(es, di + 80, ax);
  memoryASet16(es, di + 120, ax);
}
void sub_14093()
{
  if (memoryAGet(ds, 0xe9b7) != 0x00)
    goto loc_1409b;
  return;
loc_1409b:
  memoryASet(ds, 0xe9b7, 0x00);
  bx = memoryAGet16(ds, 0xe9b9);
  ch = memoryAGet(ds, 0xe9b8);
  al = bl;
  if (al < 0x07)
    goto loc_140b3;
  if (al >= 0x17)
    goto loc_140b3;
  return;
loc_140b3:
  if (al < 0x1e)
    goto loc_140b8;
  return;
loc_140b8:
  cl = 0x02;
  if (al < 0x05)
    goto loc_140db;
  if (al == 0x05)
    goto loc_140e3;
  cl--;
  if (al == 0x06)
    goto loc_140e3;
  if (al != 0x17)
    goto loc_140d1;
  al = ch;
  if (al)
    goto loc_140d1;
  return;
loc_140d1:
  cl++;
  if (al >= 0x19)
    goto loc_140db;
  bl++;
  cl--;
loc_140db:
  al = ch;
  if (!al)
    goto loc_140e3;
  cl++;
loc_140e3:
  ax = bx;
  sub_14e2e();
  di = ax;
  di += 0x0004;
  ax = 0xa000;
  es = ax;
  cl--;
  if (cl == 0)
    goto loc_140fc;
  cl--;
  if (cl == 0)
    goto loc_14109;
  goto loc_1411b;
loc_140fc:
  cx = 0x0010;
loc_140ff:
  memoryASet(es, di, 0x00);
  di += 0x0028;
  if (--cx)
    goto loc_140ff;
  return;
loc_14109:
  cx = 0x0010;
loc_1410c:
  memoryASet(es, di, 0x00);
  memoryASet(es, di + 1, 0x00);
  di += 0x0028;
  if (--cx)
    goto loc_1410c;
  return;
loc_1411b:
  cx = 0x0010;
loc_1411e:
  memoryASet(es, di, 0x00);
  memoryASet(es, di + 1, 0x00);
  memoryASet(es, di + 2, 0x00);
  di += 0x0028;
  if (--cx)
    goto loc_1411e;
}
void sub_14132()
{
  al = memoryAGet(ds, bp);
  al += 0x20;
  al -= memoryAGet(ds, 0x03ad);
  al &= 0x7f;
  ah = 0;
  ax += 0x2310;
  bx = ax;
  al = memoryAGet(ds, bx);
  if (bp != 0x03fa)
    goto loc_1414f;
  al += 0x02;
loc_1414f:
  al <<= 1;
  al += 0x78;
  memoryASet(ds, 0x039a, al);
  al = memoryAGet(ds, bp + 6);
  al -= memoryAGet(ds, 0x046e);
  al <<= 1;
  cl = al;
  al = 0xa8;
  al -= cl;
  if (bp != 0x03fa)
    goto loc_1416e;
  al += 0x08;
loc_1416e:
  memoryASet(ds, 0x039c, al);
}
void sub_14172()
{
  bx = 0x03ad;
  al = 0x04;
  al -= memoryAGet(ds, bx);
  al &= 0x07;
  bl = 0;
  al >>= 1;
  stop(/*carry1*/);
  bl = rcr(bl, 0x01);
  bh = al;
  cx = 0x1850;
  bx += cx;
  memoryASet16(ds, 0x0448, bx);
  bx = 0xe9bb;
  al = 0x04;
loc_14191:
  push(ax);
  sub_14219();
  al += 0x1e;
  memoryASet(ds, bx, al);
  bx++;
  ax = pop();
  al += 0x08;
  if (al != 0x84)
    goto loc_14191;
  bx = 0xe9cb;
  al = 0x04;
loc_141a6:
  push(ax);
  sub_1422f();
  memoryASet(ds, bx, al);
  bx++;
  ax = pop();
  al += 0x08;
  if (al != 0x84)
    goto loc_141a6;
  bp = 0x03f6;
  cx = 0x0004;
loc_141ba:
  push(cx);
  al = memoryAGet(ds, bp + 18);
  memoryASet(ds, bp + 24, al);
  al = memoryAGet(ds, bp + 48);
  if (al == 0x00)
    goto loc_14201;
  tl = al;
  al = 0x40;
  if (tl == 0)
    goto loc_141d8;
  al = memoryAGet(ds, bp);
  sub_1422f();
loc_141d8:
  memoryASet(ds, bp + 30, al);
  bl = memoryAGet(ds, bp + 6);
  bh = memoryAGet(ds, bp + 12);
  cx = memoryAGet16(ds, 0x03f2);
  if (bx < cx)
    goto loc_1420b;
  cx = memoryAGet16(ds, 0x03f4);
  flags.carry = bx < cx;
  bx -= cx;
  if (!flags.carry)
    goto loc_14201;
  al = memoryAGet(ds, bp + 48);
  if (al == 0x07)
    goto loc_14206;
  sub_1424e();
  if (!flags.carry)
    goto loc_14206;
loc_14201:
  memoryASet(ds, bp + 24, 0xff);
loc_14206:
  cx = pop();
  bp++;
  if (--cx)
    goto loc_141ba;
  return;
loc_1420b:
  if (memoryAGet(ds, bp + 48) == 0x07)
    goto loc_14201;
  memoryASet(ds, bp + 48, 0x00);
  goto loc_14201;
}
void sub_14219()
{
  push(bx);
  al += 0x20;
  al -= memoryAGet(ds, 0x03ad);
  al &= 0x7f;
  cl = al;
  ch = 0;
  bx = 0x2310;
  bx += cx;
  al = memoryAGet(ds, bx);
  bx = pop();
}
void sub_1422f()
{
  al += 0x20;
  al -= memoryAGet(ds, 0x03ad);
  al &= 0x7f;
  if (al >= 0x20)
    goto loc_1423f;
  al += 0x20;
  return;
loc_1423f:
  if (al < 0x60)
    goto loc_14247;
  al -= 0x60;
  return;
loc_14247:
  ah = al;
  al = 0x60;
  al -= ah;
}
// INJECT: Error: cannot inject carry flag in sub_1424e()!
// INJECT: Error: cannot inject carry flag in sub_1424e()!
// INJECT: Error: cannot inject carry flag in sub_1424e()!
void sub_1424e()
{
  al = memoryAGet(ds, bp);
  sub_14219();
  al += 0x20;
  al &= 0xfc;
  memoryASet(ds, 0xea9d, al);
  bx = memoryAGet16(ds, 0x0448);
  bx += cx;
  al = memoryAGet(ds, bx);
  if (al != 0x0f)
    goto loc_14269;
  stop(/*inject ret*/);
  return;
loc_14269:
  flags.carry = !flags.carry;
  if (stop(/*1*/))
    goto loc_1426f;
  stop(/*inject ret*/);
  return;
loc_1426f:
  ah = al;
  al = memoryAGet(ds, 0x03ad);
  al -= 0x1d;
  al &= 0x7f;
  al >>= 1;
  al >>= 1;
  al >>= 1;
  cl = al;
  al += ah;
  al &= 0x0f;
  memoryASet(ds, 0xea8b, al);
  ah = al;
  al >>= 1;
  al >>= 1;
  al >>= 1;
  al >>= 1;
  al += cl;
  al &= 0x0f;
  memoryASet(ds, 0xea8a, al);
  ax = 0x1532;
  es = ax;
  al = 0xff;
  di = 0x044a;
  cx = 0x0009;
  rep_stosb<MemAuto, DirAuto>();
  memoryASet(ds, 0xea8c, 0x00);
  al = memoryAGet(ds, bp);
  sub_14219();
  memoryASet(ds, 0xea9f, al);
  if (!(cl & 0x40))
    goto loc_142fb;
  al += 0x1e;
  cl = al;
  ch = 0;
  bx = 0xeaa1;
  bx += cx;
  al = memoryAGet(ds, bx);
  if (al == 0xff)
    goto loc_142fb;
  al <<= 1;
  cl = al;
  al <<= 1;
  cl += al;
  si = 0xe9db;
  si += cx;
  lodsw<MemAuto, DirAuto>();
  memoryASet(ds, 0x044a, al);
  memoryASet(ds, 0x044d, al);
  memoryASet(ds, 0x0450, al);
  lodsw<MemAuto, DirAuto>();
  memoryASet(ds, 0x044b, al);
  memoryASet(ds, 0x044e, al);
  memoryASet(ds, 0x0451, al);
  lodsw<MemAuto, DirAuto>();
  memoryASet(ds, 0x044c, al);
  memoryASet(ds, 0x044f, al);
  memoryASet(ds, 0x0452, al);
  memoryASet(ds, 0xea8c, memoryAGet(ds, 0xea8c) + 1);
loc_142fb:
  al = memoryAGet(ds, bp + 6);
  al &= 0x03;
  memoryASet(ds, 0xea9e, al);
  bl = memoryAGet(ds, bp + 6);
  al = memoryAGet(ds, bp + 12);
  flags.carry = 0;
  al = rcr(al, 0x01);
  bl = rcr(bl, 0x01);
  al = rcr(al, 0x01);
  bl = rcr(bl, 0x01);
  ah = memoryAGet(ds, 0xea8b);
  al = memoryAGet(ds, 0xea8a);
loc_1431b:
  push(ax);
  push(bx);
  sub_1459e();
  bx = pop();
  ax = pop();
  al++;
  al &= 0x0f;
  if (al != ah)
    goto loc_1431b;
  if (memoryAGet(ds, 0xea8c) != 0x00)
    goto loc_14332;
  stop(/*inject ret*/);
  return;
loc_14332:
  cx = bp;
  cx -= 0x03f6;
  al = memoryAGet(ds, 0xea9f);
  al += 0x3c;
  al &= 0x03;
  al += memoryAGet(ds, bp + 18);
  push(ax);
  al = cl;
  al += 0x7c;
  memoryASet(ds, bp + 24, al);
  al -= 0x7c;
  ah = 0;
  ax <<= 1;
  cx = ax;
  ax <<= 1;
  bx = ax;
  ax <<= 1;
  si = ax;
  ax <<= 1;
  ax += bx;
  ax += cx;
  ax += si;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  di = 0x2fcd;
  di += ax;
  ax = pop();
  sub_13cc3();
  si = bx;
  if (cl == 0x02)
    goto loc_1437d;
  goto loc_1446e;
loc_1437d:
  bl = memoryAGet(ds, 0xea9e);
  bl += bl;
  bl += bl;
  bh = 0;
  bx += 0xea8d;
  ax = memoryAGet16(ds, bx);
  memoryASet16(ds, 0xeade, ax);
  ax = memoryAGet16(ds, bx + 2);
  memoryASet16(ds, 0xeae0, ax);
  if (memoryAGet(ds, 0xea9e) == 0x00)
    goto loc_143ba;
  al = memoryAGet(ds, 0x044a);
  memoryASet(ds, 0xeae2, al);
  al = ~al;
  memoryASet(ds, 0xeae3, al);
  al = memoryAGet(ds, 0x044b);
  memoryASet(ds, 0xeae4, al);
  al = ~al;
  memoryASet(ds, 0xeae5, al);
  cx = memoryAGet16(ds, 0xeade);
  sub_143f0();
loc_143ba:
  al = memoryAGet(ds, 0x044d);
  memoryASet(ds, 0xeae2, al);
  al = ~al;
  memoryASet(ds, 0xeae3, al);
  al = memoryAGet(ds, 0x044e);
  memoryASet(ds, 0xeae4, al);
  al = ~al;
  memoryASet(ds, 0xeae5, al);
  cx = 0x0008;
  sub_143f0();
  al = memoryAGet(ds, 0x0450);
  memoryASet(ds, 0xeae2, al);
  al = ~al;
  memoryASet(ds, 0xeae3, al);
  al = memoryAGet(ds, 0x0451);
  memoryASet(ds, 0xeae4, al);
  al = ~al;
  memoryASet(ds, 0xeae5, al);
  cx = memoryAGet16(ds, 0xeae0);
loc_143f0:
  ah = memoryAGet(ds, 0xeae2);
  al = memoryAGet(ds, si + 2);
  al &= ah;
  memoryASet(es, di + 3, al);
  al = memoryAGet(ds, si + 4);
  al &= ah;
  memoryASet(es, di + 6, al);
  al = memoryAGet(ds, si + 6);
  al &= ah;
  memoryASet(es, di + 9, al);
  al = memoryAGet(ds, si + 8);
  al &= ah;
  memoryASet(es, di + 12, al);
  lodsb<MemAuto, DirAuto>();
  al |= memoryAGet(ds, 0xeae3);
  stosb<MemAuto, DirAuto>();
  ah = memoryAGet(ds, 0xeae4);
  al = memoryAGet(ds, si + 2);
  al &= ah;
  memoryASet(es, di + 3, al);
  al = memoryAGet(ds, si + 4);
  al &= ah;
  memoryASet(es, di + 6, al);
  al = memoryAGet(ds, si + 6);
  al &= ah;
  memoryASet(es, di + 9, al);
  al = memoryAGet(ds, si + 8);
  al &= ah;
  memoryASet(es, di + 12, al);
  lodsb<MemAuto, DirAuto>();
  al |= memoryAGet(ds, 0xeae5);
  stosb<MemAuto, DirAuto>();
  memoryASet(es, di, 0xff);
  memoryASet(es, di + 3, 0x00);
  memoryASet(es, di + 6, 0x00);
  memoryASet(es, di + 9, 0x00);
  memoryASet(es, di + 12, 0x00);
  si += 0x0008;
  di += 0x000d;
  if (--cx)
    goto loc_143f0;
  flags.carry = false;
  return;
loc_1446e:
  bl = memoryAGet(ds, 0xea9e);
  bl += bl;
  bl += bl;
  bh = 0;
  bx += 0xea8d;
  ax = memoryAGet16(ds, bx);
  memoryASet16(ds, 0xeae6, ax);
  ax = memoryAGet16(ds, bx + 2);
  memoryASet16(ds, 0xeae8, ax);
  if (memoryAGet(ds, 0xea9e) == 0x00)
    goto loc_144b6;
  al = memoryAGet(ds, 0x044a);
  memoryASet(ds, 0xeaea, al);
  al = ~al;
  memoryASet(ds, 0xeaeb, al);
  al = memoryAGet(ds, 0x044b);
  memoryASet(ds, 0xeaec, al);
  al = ~al;
  memoryASet(ds, 0xeaed, al);
  al = memoryAGet(ds, 0x044c);
  memoryASet(ds, 0xeaee, al);
  al = ~al;
  memoryASet(ds, 0xeaef, al);
  cx = memoryAGet16(ds, 0xeae6);
  sub_14502();
loc_144b6:
  al = memoryAGet(ds, 0x044d);
  memoryASet(ds, 0xeaea, al);
  al = ~al;
  memoryASet(ds, 0xeaeb, al);
  al = memoryAGet(ds, 0x044e);
  memoryASet(ds, 0xeaec, al);
  al = ~al;
  memoryASet(ds, 0xeaed, al);
  al = memoryAGet(ds, 0x044f);
  memoryASet(ds, 0xeaee, al);
  al = ~al;
  memoryASet(ds, 0xeaef, al);
  cx = 0x0008;
  sub_14502();
  al = memoryAGet(ds, 0x0450);
  memoryASet(ds, 0xeaea, al);
  al = ~al;
  memoryASet(ds, 0xeaeb, al);
  al = memoryAGet(ds, 0x0451);
  memoryASet(ds, 0xeaec, al);
  al = ~al;
  memoryASet(ds, 0xeaed, al);
  al = memoryAGet(ds, 0x0452);
  memoryASet(ds, 0xeaee, al);
  al = ~al;
  memoryASet(ds, 0xeaef, al);
  cx = memoryAGet16(ds, 0xeae8);
loc_14502:
  ah = memoryAGet(ds, 0xeaea);
  al = memoryAGet(ds, si + 3);
  al &= ah;
  memoryASet(es, di + 3, al);
  al = memoryAGet(ds, si + 6);
  al &= ah;
  memoryASet(es, di + 6, al);
  al = memoryAGet(ds, si + 9);
  al &= ah;
  memoryASet(es, di + 9, al);
  al = memoryAGet(ds, si + 12);
  al &= ah;
  memoryASet(es, di + 12, al);
  lodsb<MemAuto, DirAuto>();
  al |= memoryAGet(ds, 0xeaeb);
  stosb<MemAuto, DirAuto>();
  ah = memoryAGet(ds, 0xeaec);
  al = memoryAGet(ds, si + 3);
  al &= ah;
  memoryASet(es, di + 3, al);
  al = memoryAGet(ds, si + 6);
  al &= ah;
  memoryASet(es, di + 6, al);
  al = memoryAGet(ds, si + 9);
  al &= ah;
  memoryASet(es, di + 9, al);
  al = memoryAGet(ds, si + 12);
  al &= ah;
  memoryASet(es, di + 12, al);
  lodsb<MemAuto, DirAuto>();
  al |= memoryAGet(ds, 0xeaed);
  stosb<MemAuto, DirAuto>();
  al = memoryAGet(ds, si);
  al |= memoryAGet(ds, 0xeaef);
  memoryASet(es, di, al);
  ah = memoryAGet(ds, 0xeaee);
  al = memoryAGet(ds, si + 3);
  al &= ah;
  memoryASet(es, di + 3, al);
  al = memoryAGet(ds, si + 6);
  al &= ah;
  memoryASet(es, di + 6, al);
  al = memoryAGet(ds, si + 9);
  al &= ah;
  memoryASet(es, di + 9, al);
  al = memoryAGet(ds, si + 12);
  al &= ah;
  memoryASet(es, di + 12, al);
  di += 0x000d;
  si += 0x000d;
  if (--cx)
    goto loc_14599;
  goto loc_1459c;
loc_14599:
  goto loc_14502;
loc_1459c:
  flags.carry = false;
}
void sub_143f0()
{
loc_143f0:
  ah = memoryAGet(ds, 0xeae2);
  al = memoryAGet(ds, si + 2);
  al &= ah;
  memoryASet(es, di + 3, al);
  al = memoryAGet(ds, si + 4);
  al &= ah;
  memoryASet(es, di + 6, al);
  al = memoryAGet(ds, si + 6);
  al &= ah;
  memoryASet(es, di + 9, al);
  al = memoryAGet(ds, si + 8);
  al &= ah;
  memoryASet(es, di + 12, al);
  lodsb<MemAuto, DirAuto>();
  al |= memoryAGet(ds, 0xeae3);
  stosb<MemAuto, DirAuto>();
  ah = memoryAGet(ds, 0xeae4);
  al = memoryAGet(ds, si + 2);
  al &= ah;
  memoryASet(es, di + 3, al);
  al = memoryAGet(ds, si + 4);
  al &= ah;
  memoryASet(es, di + 6, al);
  al = memoryAGet(ds, si + 6);
  al &= ah;
  memoryASet(es, di + 9, al);
  al = memoryAGet(ds, si + 8);
  al &= ah;
  memoryASet(es, di + 12, al);
  lodsb<MemAuto, DirAuto>();
  al |= memoryAGet(ds, 0xeae5);
  stosb<MemAuto, DirAuto>();
  memoryASet(es, di, 0xff);
  memoryASet(es, di + 3, 0x00);
  memoryASet(es, di + 6, 0x00);
  memoryASet(es, di + 9, 0x00);
  memoryASet(es, di + 12, 0x00);
  si += 0x0008;
  di += 0x000d;
  if (--cx)
    goto loc_143f0;
  flags.carry = false;
}
void sub_14502()
{
loc_14502:
  ah = memoryAGet(ds, 0xeaea);
  al = memoryAGet(ds, si + 3);
  al &= ah;
  memoryASet(es, di + 3, al);
  al = memoryAGet(ds, si + 6);
  al &= ah;
  memoryASet(es, di + 6, al);
  al = memoryAGet(ds, si + 9);
  al &= ah;
  memoryASet(es, di + 9, al);
  al = memoryAGet(ds, si + 12);
  al &= ah;
  memoryASet(es, di + 12, al);
  lodsb<MemAuto, DirAuto>();
  al |= memoryAGet(ds, 0xeaeb);
  stosb<MemAuto, DirAuto>();
  ah = memoryAGet(ds, 0xeaec);
  al = memoryAGet(ds, si + 3);
  al &= ah;
  memoryASet(es, di + 3, al);
  al = memoryAGet(ds, si + 6);
  al &= ah;
  memoryASet(es, di + 6, al);
  al = memoryAGet(ds, si + 9);
  al &= ah;
  memoryASet(es, di + 9, al);
  al = memoryAGet(ds, si + 12);
  al &= ah;
  memoryASet(es, di + 12, al);
  lodsb<MemAuto, DirAuto>();
  al |= memoryAGet(ds, 0xeaed);
  stosb<MemAuto, DirAuto>();
  al = memoryAGet(ds, si);
  al |= memoryAGet(ds, 0xeaef);
  memoryASet(es, di, al);
  ah = memoryAGet(ds, 0xeaee);
  al = memoryAGet(ds, si + 3);
  al &= ah;
  memoryASet(es, di + 3, al);
  al = memoryAGet(ds, si + 6);
  al &= ah;
  memoryASet(es, di + 6, al);
  al = memoryAGet(ds, si + 9);
  al &= ah;
  memoryASet(es, di + 9, al);
  al = memoryAGet(ds, si + 12);
  al &= ah;
  memoryASet(es, di + 12, al);
  di += 0x000d;
  si += 0x000d;
  if (--cx)
    goto loc_14599;
  goto loc_1459c;
loc_14599:
  goto loc_14502;
loc_1459c:
  flags.carry = false;
}
void sub_1459e()
{
  cl = al;
  bh = al;
  bx += 0x055c;
  ch = 0;
  push(bx);
  bx = 0xe9bb;
  bx += cx;
  al = memoryAGet(ds, bx);
  cx = 0x0010;
  bx += cx;
  cl = al;
  al = memoryAGet(ds, bx);
  if (al >= memoryAGet(ds, bp + 30))
    goto loc_145c1;
  bx = pop();
  return;
loc_145c1:
  al = cl;
  al -= memoryAGet(ds, 0xea9d);
  al += 0x0b;
  bx = pop();
  if (!(al & 0x80))
    goto loc_145cf;
  return;
loc_145cf:
  if (al < 0x16)
    goto loc_145d4;
  return;
loc_145d4:
  cl = al;
  push(cx);
  di = 0x0450;
  sub_145f3();
  bx++;
  cx = pop();
  push(cx);
  di = 0x044d;
  sub_145f3();
  bx++;
  cx = pop();
  if (memoryAGet(ds, 0xea9e) != 0x00)
    goto loc_145f0;
  return;
loc_145f0:
  di = 0x044a;
  push(bx);
  al = memoryAGet(ds, bx);
  if (!(al & 0x80))
    goto loc_1463e;
  ah = al;
  al &= 0x03;
  if (al == 0x03)
    goto loc_1463e;
  flags.carry = al & 1;
  al >>= 1;
  if (!flags.carry)
    goto loc_14616;
  al = ah;
  al &= 0x0c;
  if (al == 0)
    goto loc_14611;
  bx = 0xeb06;
  goto loc_14619;
loc_14611:
  bx = 0xeaf0;
  goto loc_14619;
loc_14616:
  bx = 0xeb1c;
loc_14619:
  bx += cx;
  al = memoryAGet(ds, bx);
  if (al & 0x80)
    goto loc_1463e;
  al <<= 1;
  cl = al;
  al <<= 1;
  cl += al;
  si = 0xe9db;
  si += cx;
  lodsw<MemAuto, DirAuto>();
  al &= memoryAGet(ds, di);
  stosb<MemAuto, DirAuto>();
  lodsw<MemAuto, DirAuto>();
  al &= memoryAGet(ds, di);
  stosb<MemAuto, DirAuto>();
  lodsw<MemAuto, DirAuto>();
  al &= memoryAGet(ds, di);
  stosb<MemAuto, DirAuto>();
  memoryASet(ds, 0xea8c, memoryAGet(ds, 0xea8c) + 1);
loc_1463e:
  bx = pop();
}
void sub_145f3()
{
  push(bx);
  al = memoryAGet(ds, bx);
  if (!(al & 0x80))
    goto loc_1463e;
  ah = al;
  al &= 0x03;
  if (al == 0x03)
    goto loc_1463e;
  flags.carry = al & 1;
  al >>= 1;
  if (!flags.carry)
    goto loc_14616;
  al = ah;
  al &= 0x0c;
  if (al == 0)
    goto loc_14611;
  bx = 0xeb06;
  goto loc_14619;
loc_14611:
  bx = 0xeaf0;
  goto loc_14619;
loc_14616:
  bx = 0xeb1c;
loc_14619:
  bx += cx;
  al = memoryAGet(ds, bx);
  if (al & 0x80)
    goto loc_1463e;
  al <<= 1;
  cl = al;
  al <<= 1;
  cl += al;
  si = 0xe9db;
  si += cx;
  lodsw<MemAuto, DirAuto>();
  al &= memoryAGet(ds, di);
  stosb<MemAuto, DirAuto>();
  lodsw<MemAuto, DirAuto>();
  al &= memoryAGet(ds, di);
  stosb<MemAuto, DirAuto>();
  lodsw<MemAuto, DirAuto>();
  al &= memoryAGet(ds, di);
  stosb<MemAuto, DirAuto>();
  memoryASet(ds, 0xea8c, memoryAGet(ds, 0xea8c) + 1);
loc_1463e:
  bx = pop();
}
void sub_14640()
{
  al = memoryAGet(ds, bp + 24);
  if (al != 0xff)
    goto loc_14649;
  return;
loc_14649:
  sub_14132();
  if (memoryAGet(ds, bp + 48) != 0x07)
    goto loc_1465c;
  al = memoryAGet(ds, bp);
  al <<= 1;
  memoryASet(ds, 0x039a, al);
loc_1465c:
  ax = memoryAGet16(ds, 0x0480);
  es = ax;
  al = memoryAGet(ds, 0x039c);
  if (al >= 0x18)
    goto loc_14669;
  return;
loc_14669:
  if (al < 0xb0)
    goto loc_1466e;
  return;
loc_1466e:
  bh = al;
  bl = memoryAGet(ds, 0x039a);
  stop(/*carry1*/);
  bl = rcr(bl, 0x01);
  bl = rcr(bl, 0x01);
  bl = rcr(bl, 0x01);
  bl &= 0x1f;
  memoryASet(ds, 0xeb32, 0x00);
  if (memoryAGet(ds, bp + 48) != 0x07)
    goto loc_146e0;
  memoryASet16(ds, 0x047b, bx);
  al = memoryAGet(ds, 0x039c);
  if (al >= 0x20)
    goto loc_14695;
  return;
loc_14695:
  if (al < 0xa8)
    goto loc_1469a;
  return;
loc_1469a:
  al = memoryAGet(ds, 0x039a);
  al >>= 1;
  al &= 0x03;
  memoryASet(ds, 0x047d, al);
  memoryASet(ds, 0x047a, 0x01);
  ax = memoryAGet16(ds, 0x0480);
  es = ax;
  push(bx);
  sub_146e0();
  sub_14093();
  bx = pop();
  al = memoryAGet(ds, 0xe9b9);
  if (al < 0x07)
    goto loc_146c2;
  if (al > 0x17)
    goto loc_146c2;
  return;
loc_146c2:
  memoryASet(ds, 0xeb32, 0x01);
  ax = 0xa000;
  es = ax;
  ax = bx;
  ah -= 0x01;
  sub_14e2e();
  ax += 0x0004;
  sub_146eb();
  memoryASet(ds, 0xeb32, 0x00);
  return;
loc_146e0:
  ax = bx;
  ah -= 0x08;
  sub_14e44();
  ax -= 0x0007;
  bx = ax;
  push(bx);
  al = memoryAGet(ds, bp + 24);
  if (al < 0x7c)
    goto loc_1471f;
  al -= 0x7c;
  ah = 0;
  ax <<= 1;
  cx = ax;
  ax <<= 1;
  bx = ax;
  ax <<= 1;
  dx = ax;
  ax <<= 1;
  ax += bx;
  ax += cx;
  ax += dx;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  bx = 0x2fcd;
  bx += ax;
  dl = 0x03;
  dh = 0x10;
  goto loc_14739;
loc_1471f:
  cl = al;
  al = memoryAGet(ds, 0x039a);
  al >>= 1;
  al &= 0x03;
  al += cl;
  push(ax);
  sub_13cc3();
  dl = cl;
  ax = pop();
  dh = 0x10;
  if (al >= 0x4e)
    goto loc_14739;
  dh = 0x08;
loc_14739:
  di = pop();
  si = bx;
  bx = 0x0004;
  if (memoryAGet(ds, 0xeb32) == 0x01)
    goto loc_14749;
  goto loc_148e6;
loc_14749:
  cl = dh;
  ch = 0;
  dl--;
  if (dl == 0)
    goto loc_14758;
  dl--;
  if (dl == 0)
    goto loc_147a3;
  goto loc_14826;
loc_14758:
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
loc_1475f:
  al = 0x01;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 1);
  memoryASet(es, di, al);
  al = 0x02;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 2);
  memoryASet(es, di, al);
  al = 0x04;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 3);
  memoryASet(es, di, al);
  al = 0x08;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 4);
  memoryASet(es, di, al);
  si += 0x0005;
  di += 0x0028;
  if (--cx)
    goto loc_1475f;
  al = 0x0f;
  out(dx, al);
  return;
loc_147a3:
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
loc_147aa:
  al = 0x01;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 2);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 3);
  memoryASet(es, di + 1, al);
  al = 0x02;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 4);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 5);
  memoryASet(es, di + 1, al);
  al = 0x04;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 6);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 7);
  memoryASet(es, di + 1, al);
  al = 0x08;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 8);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 9);
  memoryASet(es, di + 1, al);
  si += 0x000a;
  di += 0x0028;
  if (--cx)
    goto loc_147aa;
  al = 0x0f;
  out(dx, al);
  return;
loc_14826:
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
loc_1482d:
  al = 0x01;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 3);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 4);
  memoryASet(es, di + 1, al);
  al = memoryAGet(es, di + 2);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 5);
  memoryASet(es, di + 2, al);
  al = 0x02;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 6);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 7);
  memoryASet(es, di + 1, al);
  al = memoryAGet(es, di + 2);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 8);
  memoryASet(es, di + 2, al);
  al = 0x04;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 9);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 10);
  memoryASet(es, di + 1, al);
  al = memoryAGet(es, di + 2);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 11);
  memoryASet(es, di + 2, al);
  al = 0x08;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 12);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 13);
  memoryASet(es, di + 1, al);
  al = memoryAGet(es, di + 2);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 14);
  memoryASet(es, di + 2, al);
  si += 0x000f;
  di += 0x0028;
  if (--cx)
    goto loc_148df;
  goto loc_148e2;
loc_148df:
  goto loc_1482d;
loc_148e2:
  al = 0x0f;
  out(dx, al);
  return;
loc_148e6:
  cl = dh;
  ch = 0;
  dl--;
  if (dl == 0)
    goto loc_148f4;
  dl--;
  if (dl == 0)
    goto loc_14930;
  goto loc_1496c;
loc_148f4:
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 1);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 40);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 2);
  memoryASet(es, di + 40, al);
  al = memoryAGet(es, di + 80);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 3);
  memoryASet(es, di + 80, al);
  al = memoryAGet(es, di + 120);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 4);
  memoryASet(es, di + 120, al);
  di += 0x00a0;
  si += 0x0005;
  if (--cx)
    goto loc_148f4;
  return;
loc_14930:
  ax = memoryAGet16(es, di);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 2);
  memoryASet16(es, di, ax);
  ax = memoryAGet16(es, di + 40);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 4);
  memoryASet16(es, di + 40, ax);
  ax = memoryAGet16(es, di + 80);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 6);
  memoryASet16(es, di + 80, ax);
  ax = memoryAGet16(es, di + 120);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 8);
  memoryASet16(es, di + 120, ax);
  di += 0x00a0;
  si += 0x000a;
  if (--cx)
    goto loc_14930;
  return;
loc_1496c:
  ax = memoryAGet16(es, di);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 3);
  memoryASet16(es, di, ax);
  al = memoryAGet(es, di + 2);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 5);
  memoryASet(es, di + 2, al);
  ax = memoryAGet16(es, di + 40);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 6);
  memoryASet16(es, di + 40, ax);
  al = memoryAGet(es, di + 42);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 8);
  memoryASet(es, di + 42, al);
  ax = memoryAGet16(es, di + 80);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 9);
  memoryASet16(es, di + 80, ax);
  al = memoryAGet(es, di + 82);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 11);
  memoryASet(es, di + 82, al);
  ax = memoryAGet16(es, di + 120);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 12);
  memoryASet16(es, di + 120, ax);
  al = memoryAGet(es, di + 122);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 14);
  memoryASet(es, di + 122, al);
  di += 0x00a0;
  si += 0x000f;
  if (--cx)
    goto loc_1496c;
}
void sub_146e0()
{
  ax = bx;
  ah -= 0x08;
  sub_14e44();
  ax -= 0x0007;
  bx = ax;
  push(bx);
  al = memoryAGet(ds, bp + 24);
  if (al < 0x7c)
    goto loc_1471f;
  al -= 0x7c;
  ah = 0;
  ax <<= 1;
  cx = ax;
  ax <<= 1;
  bx = ax;
  ax <<= 1;
  dx = ax;
  ax <<= 1;
  ax += bx;
  ax += cx;
  ax += dx;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  bx = 0x2fcd;
  bx += ax;
  dl = 0x03;
  dh = 0x10;
  goto loc_14739;
loc_1471f:
  cl = al;
  al = memoryAGet(ds, 0x039a);
  al >>= 1;
  al &= 0x03;
  al += cl;
  push(ax);
  sub_13cc3();
  dl = cl;
  ax = pop();
  dh = 0x10;
  if (al >= 0x4e)
    goto loc_14739;
  dh = 0x08;
loc_14739:
  di = pop();
  si = bx;
  bx = 0x0004;
  if (memoryAGet(ds, 0xeb32) == 0x01)
    goto loc_14749;
  goto loc_148e6;
loc_14749:
  cl = dh;
  ch = 0;
  dl--;
  if (dl == 0)
    goto loc_14758;
  dl--;
  if (dl == 0)
    goto loc_147a3;
  goto loc_14826;
loc_14758:
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
loc_1475f:
  al = 0x01;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 1);
  memoryASet(es, di, al);
  al = 0x02;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 2);
  memoryASet(es, di, al);
  al = 0x04;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 3);
  memoryASet(es, di, al);
  al = 0x08;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 4);
  memoryASet(es, di, al);
  si += 0x0005;
  di += 0x0028;
  if (--cx)
    goto loc_1475f;
  al = 0x0f;
  out(dx, al);
  return;
loc_147a3:
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
loc_147aa:
  al = 0x01;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 2);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 3);
  memoryASet(es, di + 1, al);
  al = 0x02;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 4);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 5);
  memoryASet(es, di + 1, al);
  al = 0x04;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 6);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 7);
  memoryASet(es, di + 1, al);
  al = 0x08;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 8);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 9);
  memoryASet(es, di + 1, al);
  si += 0x000a;
  di += 0x0028;
  if (--cx)
    goto loc_147aa;
  al = 0x0f;
  out(dx, al);
  return;
loc_14826:
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
loc_1482d:
  al = 0x01;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 3);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 4);
  memoryASet(es, di + 1, al);
  al = memoryAGet(es, di + 2);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 5);
  memoryASet(es, di + 2, al);
  al = 0x02;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 6);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 7);
  memoryASet(es, di + 1, al);
  al = memoryAGet(es, di + 2);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 8);
  memoryASet(es, di + 2, al);
  al = 0x04;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 9);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 10);
  memoryASet(es, di + 1, al);
  al = memoryAGet(es, di + 2);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 11);
  memoryASet(es, di + 2, al);
  al = 0x08;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 12);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 13);
  memoryASet(es, di + 1, al);
  al = memoryAGet(es, di + 2);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 14);
  memoryASet(es, di + 2, al);
  si += 0x000f;
  di += 0x0028;
  if (--cx)
    goto loc_148df;
  goto loc_148e2;
loc_148df:
  goto loc_1482d;
loc_148e2:
  al = 0x0f;
  out(dx, al);
  return;
loc_148e6:
  cl = dh;
  ch = 0;
  dl--;
  if (dl == 0)
    goto loc_148f4;
  dl--;
  if (dl == 0)
    goto loc_14930;
  goto loc_1496c;
loc_148f4:
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 1);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 40);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 2);
  memoryASet(es, di + 40, al);
  al = memoryAGet(es, di + 80);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 3);
  memoryASet(es, di + 80, al);
  al = memoryAGet(es, di + 120);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 4);
  memoryASet(es, di + 120, al);
  di += 0x00a0;
  si += 0x0005;
  if (--cx)
    goto loc_148f4;
  return;
loc_14930:
  ax = memoryAGet16(es, di);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 2);
  memoryASet16(es, di, ax);
  ax = memoryAGet16(es, di + 40);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 4);
  memoryASet16(es, di + 40, ax);
  ax = memoryAGet16(es, di + 80);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 6);
  memoryASet16(es, di + 80, ax);
  ax = memoryAGet16(es, di + 120);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 8);
  memoryASet16(es, di + 120, ax);
  di += 0x00a0;
  si += 0x000a;
  if (--cx)
    goto loc_14930;
  return;
loc_1496c:
  ax = memoryAGet16(es, di);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 3);
  memoryASet16(es, di, ax);
  al = memoryAGet(es, di + 2);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 5);
  memoryASet(es, di + 2, al);
  ax = memoryAGet16(es, di + 40);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 6);
  memoryASet16(es, di + 40, ax);
  al = memoryAGet(es, di + 42);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 8);
  memoryASet(es, di + 42, al);
  ax = memoryAGet16(es, di + 80);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 9);
  memoryASet16(es, di + 80, ax);
  al = memoryAGet(es, di + 82);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 11);
  memoryASet(es, di + 82, al);
  ax = memoryAGet16(es, di + 120);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 12);
  memoryASet16(es, di + 120, ax);
  al = memoryAGet(es, di + 122);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 14);
  memoryASet(es, di + 122, al);
  di += 0x00a0;
  si += 0x000f;
  if (--cx)
    goto loc_1496c;
}
void sub_146eb()
{
  bx = ax;
  push(bx);
  al = memoryAGet(ds, bp + 24);
  if (al < 0x7c)
    goto loc_1471f;
  al -= 0x7c;
  ah = 0;
  ax <<= 1;
  cx = ax;
  ax <<= 1;
  bx = ax;
  ax <<= 1;
  dx = ax;
  ax <<= 1;
  ax += bx;
  ax += cx;
  ax += dx;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  bx = 0x2fcd;
  bx += ax;
  dl = 0x03;
  dh = 0x10;
  goto loc_14739;
loc_1471f:
  cl = al;
  al = memoryAGet(ds, 0x039a);
  al >>= 1;
  al &= 0x03;
  al += cl;
  push(ax);
  sub_13cc3();
  dl = cl;
  ax = pop();
  dh = 0x10;
  if (al >= 0x4e)
    goto loc_14739;
  dh = 0x08;
loc_14739:
  di = pop();
  si = bx;
  bx = 0x0004;
  if (memoryAGet(ds, 0xeb32) == 0x01)
    goto loc_14749;
  goto loc_148e6;
loc_14749:
  cl = dh;
  ch = 0;
  dl--;
  if (dl == 0)
    goto loc_14758;
  dl--;
  if (dl == 0)
    goto loc_147a3;
  goto loc_14826;
loc_14758:
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
loc_1475f:
  al = 0x01;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 1);
  memoryASet(es, di, al);
  al = 0x02;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 2);
  memoryASet(es, di, al);
  al = 0x04;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 3);
  memoryASet(es, di, al);
  al = 0x08;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 4);
  memoryASet(es, di, al);
  si += 0x0005;
  di += 0x0028;
  if (--cx)
    goto loc_1475f;
  al = 0x0f;
  out(dx, al);
  return;
loc_147a3:
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
loc_147aa:
  al = 0x01;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 2);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 3);
  memoryASet(es, di + 1, al);
  al = 0x02;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 4);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 5);
  memoryASet(es, di + 1, al);
  al = 0x04;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 6);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 7);
  memoryASet(es, di + 1, al);
  al = 0x08;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 8);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 9);
  memoryASet(es, di + 1, al);
  si += 0x000a;
  di += 0x0028;
  if (--cx)
    goto loc_147aa;
  al = 0x0f;
  out(dx, al);
  return;
loc_14826:
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
loc_1482d:
  al = 0x01;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 3);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 4);
  memoryASet(es, di + 1, al);
  al = memoryAGet(es, di + 2);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 5);
  memoryASet(es, di + 2, al);
  al = 0x02;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 6);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 7);
  memoryASet(es, di + 1, al);
  al = memoryAGet(es, di + 2);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 8);
  memoryASet(es, di + 2, al);
  al = 0x04;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 9);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 10);
  memoryASet(es, di + 1, al);
  al = memoryAGet(es, di + 2);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 11);
  memoryASet(es, di + 2, al);
  al = 0x08;
  out(dx, al);
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 12);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 1);
  al &= memoryAGet(ds, si + 1);
  al |= memoryAGet(ds, si + 13);
  memoryASet(es, di + 1, al);
  al = memoryAGet(es, di + 2);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 14);
  memoryASet(es, di + 2, al);
  si += 0x000f;
  di += 0x0028;
  if (--cx)
    goto loc_148df;
  goto loc_148e2;
loc_148df:
  goto loc_1482d;
loc_148e2:
  al = 0x0f;
  out(dx, al);
  return;
loc_148e6:
  cl = dh;
  ch = 0;
  dl--;
  if (dl == 0)
    goto loc_148f4;
  dl--;
  if (dl == 0)
    goto loc_14930;
  goto loc_1496c;
loc_148f4:
  al = memoryAGet(es, di);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 1);
  memoryASet(es, di, al);
  al = memoryAGet(es, di + 40);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 2);
  memoryASet(es, di + 40, al);
  al = memoryAGet(es, di + 80);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 3);
  memoryASet(es, di + 80, al);
  al = memoryAGet(es, di + 120);
  al &= memoryAGet(ds, si);
  al |= memoryAGet(ds, si + 4);
  memoryASet(es, di + 120, al);
  di += 0x00a0;
  si += 0x0005;
  if (--cx)
    goto loc_148f4;
  return;
loc_14930:
  ax = memoryAGet16(es, di);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 2);
  memoryASet16(es, di, ax);
  ax = memoryAGet16(es, di + 40);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 4);
  memoryASet16(es, di + 40, ax);
  ax = memoryAGet16(es, di + 80);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 6);
  memoryASet16(es, di + 80, ax);
  ax = memoryAGet16(es, di + 120);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 8);
  memoryASet16(es, di + 120, ax);
  di += 0x00a0;
  si += 0x000a;
  if (--cx)
    goto loc_14930;
  return;
loc_1496c:
  ax = memoryAGet16(es, di);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 3);
  memoryASet16(es, di, ax);
  al = memoryAGet(es, di + 2);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 5);
  memoryASet(es, di + 2, al);
  ax = memoryAGet16(es, di + 40);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 6);
  memoryASet16(es, di + 40, ax);
  al = memoryAGet(es, di + 42);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 8);
  memoryASet(es, di + 42, al);
  ax = memoryAGet16(es, di + 80);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 9);
  memoryASet16(es, di + 80, ax);
  al = memoryAGet(es, di + 82);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 11);
  memoryASet(es, di + 82, al);
  ax = memoryAGet16(es, di + 120);
  ax &= memoryAGet16(ds, si);
  ax |= memoryAGet16(ds, si + 12);
  memoryASet16(es, di + 120, ax);
  al = memoryAGet(es, di + 122);
  al &= memoryAGet(ds, si + 2);
  al |= memoryAGet(ds, si + 14);
  memoryASet(es, di + 122, al);
  di += 0x00a0;
  si += 0x000f;
  if (--cx)
    goto loc_1496c;
}
void sub_149e0()
{
  bp = 0x03f6;
  al = 0x00;
  cx = 0x0004;
loc_149e8:
  memoryASet(ds, bp + 48, al);
  bp++;
  if (--cx)
    goto loc_149e8;
}
void sub_149f0()
{
  ax = 0x1532;
  es = ax;
  bx = memoryAGet16(ds, 0x046e);
  flags.carry = bl < 0x08;
  bl -= 0x08;
  bh -= flags.carry;
  bh &= 0x03;
  if (bh != 0x03)
    goto loc_14a0e;
  if (bl < 0xd0)
    goto loc_14a0e;
  bx = 0;
loc_14a0e:
  memoryASet16(ds, 0x03f2, bx);
  bx = memoryAGet16(ds, 0x046e);
  flags.carry = (bl + 0x4d) >= 0x100;
  bl += 0x4d;
  bh += flags.carry;
  bh &= 0x03;
  memoryASet16(ds, 0x03f4, bx);
  sub_14172();
  bp = 0x03f6;
  cx = 0;
  al = memoryAGet(ds, bp + 30);
  stop(/*74*/);
  cl = rcl(cl, 0x01);
  stop(/*74*/);
  cl = rcl(cl, 0x01);
  stop(/*74*/);
  cl = rcl(cl, 0x01);
  al = memoryAGet(ds, bp + 31);
  stop(/*74*/);
  cl = rcl(cl, 0x01);
  stop(/*74*/);
  cl = rcl(cl, 0x01);
  al = memoryAGet(ds, bp + 32);
  stop(/*74*/);
  cl = rcl(cl, 0x01);
  cl ^= 0x3f;
  bx = 0xeb33;
  bx += cx;
  cl = memoryAGet(ds, bx);
  al = cl;
  al &= 0x03;
  memoryASet(ds, bp + 39, al);
  flags.carry = 0;
  cl = rcr(cl, 0x01);
  cl = rcr(cl, 0x01);
  al = cl;
  al &= 0x03;
  memoryASet(ds, bp + 38, al);
  flags.carry = 0;
  cl = rcr(cl, 0x01);
  cl = rcr(cl, 0x01);
  al = cl;
  al &= 0x03;
  memoryASet(ds, bp + 37, al);
  flags.carry = 0;
  cl = rcr(cl, 0x01);
  cl = rcr(cl, 0x01);
  cl &= 0x03;
  memoryASet(ds, bp + 36, cl);
}
void sub_14a91()
{
  cl = 0x03;
loc_14a93:
  bp = 0x03f6;
  ch = 0x04;
  al = cl;
loc_14a9a:
  if (al == memoryAGet(ds, bp + 36))
    goto loc_14aae;
  bp++;
  ch--;
  if (ch != 0)
    goto loc_14a9a;
loc_14aa5:
  cl--;
  if (!(cl & 0x80))
    goto loc_14a93;
  goto loc_14ab5;
loc_14aae:
  push(cx);
  sub_14640();
  cx = pop();
  goto loc_14aa5;
loc_14ab5:
  bp = 0x03fa;
  if (memoryAGet(ds, bp + 42) != 0xff)
    goto loc_14ac0;
  return;
loc_14ac0:
  al = memoryAGet(ds, bp + 18);
  al += 0x4a;
  memoryASet(ds, bp + 24, al);
  sub_14640();
  al = memoryAGet(ds, 0x039a);
  memoryASet(ds, 0x0399, al);
}
void sub_14ad4()
{
  bp = 0x03f6;
  cx = 0x0004;
loc_14ada:
  push(cx);
  al = memoryAGet(ds, bp + 48);
  if (al != 0x00)
    goto loc_14ae6;
  goto loc_14d8c;
loc_14ae6:
  if (al != 0x07)
    goto loc_14b31;
  memoryASet(ds, bp + 18, 0x4e);
  al = memoryAGet(ds, bp);
  al += memoryAGet(ds, bp + 54);
  memoryASet(ds, bp, al);
  if (memoryAGet(ds, 0x043f) & 0x80)
    goto loc_14b13;
  if (al == 0x3c)
    goto loc_14b0c;
  if (al != 0x78)
    goto loc_14b2e;
  goto loc_14b24;
loc_14b0c:
  memoryASet(ds, bp + 54, 0x02);
  goto loc_14b2e;
loc_14b13:
  if (al == 0x3c)
    goto loc_14b1d;
  if (al)
    goto loc_14b2e;
  goto loc_14b24;
loc_14b1d:
  memoryASet(ds, bp + 54, 0xfe);
  goto loc_14b2e;
loc_14b24:
  memoryASet(ds, bp + 48, 0x00);
  memoryASet(ds, 0x043e, 0x7d);
loc_14b2e:
  goto loc_14d8c;
loc_14b31:
  if (al != 0x04)
    goto loc_14b37;
  goto loc_14b65;
loc_14b37:
  if (al != 0x06)
    goto loc_14b3d;
  goto loc_14b65;
loc_14b3d:
  if (al == 0x05)
    goto loc_14b43;
  goto loc_14b56;
loc_14b43:
  memoryASet(ds, bp + 42, memoryAGet(ds, bp + 42) - 1);
  if (!(memoryAGet(ds, bp + 42) & 0x80))
    goto loc_14b53;
  memoryASet(ds, bp + 48, 0x02);
loc_14b53:
  goto loc_14d8c;
loc_14b56:
  sub_13a0f();
  if (!flags.carry)
    goto loc_14b65;
  memoryASet(ds, bp + 48, 0x04);
  memoryASet(ds, bp + 42, 0x00);
loc_14b65:
  al = memoryAGet(ds, bp + 48);
  if (al == 0x04)
    goto loc_14b97;
  if (al != 0x06)
    goto loc_14bbe;
  al = memoryAGet(ds, bp + 42);
  if (al == 0x06)
    goto loc_14b7f;
  al = -al;
  al += 0x05;
  goto loc_14ba7;
loc_14b7f:
  al = memoryAGet(ds, bp + 66);
  memoryASet(ds, bp + 48, al);
  al = memoryAGet(ds, bp + 60);
  memoryASet(ds, bp + 42, al);
  memoryASet(ds, bp + 18, 0x52);
  goto loc_14d8c;
loc_14b97:
  al = memoryAGet(ds, bp + 42);
  if (al != 0x06)
    goto loc_14ba7;
  memoryASet(ds, bp + 48, 0x00);
  goto loc_14d8c;
loc_14ba7:
  if (al < 0x03)
    goto loc_14bad;
  al -= 0x03;
loc_14bad:
  al <<= 1;
  al <<= 1;
  al += 0x5a;
  memoryASet(ds, bp + 18, al);
  memoryASet(ds, bp + 42, memoryAGet(ds, bp + 42) + 1);
  goto loc_14d8c;
loc_14bbe:
  if (al != 0x03)
    goto loc_14bc5;
  goto loc_14c56;
loc_14bc5:
  if (al != 0x08)
    goto loc_14c2a;
  bl = memoryAGet(ds, bp + 6);
  bh = memoryAGet(ds, bp + 12);
  memoryASet16(ds, 0x03cf, bx);
  cl = memoryAGet(ds, bp + 54);
  ch = 0x00;
  if (!(cl & 0x80))
    goto loc_14be2;
  ch--;
loc_14be2:
  bx += cx;
  if (!(bh & 0x80))
    goto loc_14bec;
  goto loc_14d79;
loc_14bec:
  memoryASet(ds, bp + 6, bl);
  al = bh;
  al &= 0x03;
  memoryASet(ds, bp + 12, al);
  sub_13a0f();
  if (flags.carry)
    goto loc_14c02;
  sub_109eb();
  if (!flags.carry)
    goto loc_14c18;
loc_14c02:
  bx = memoryAGet16(ds, 0x03cf);
  memoryASet(ds, bp + 6, bl);
  memoryASet(ds, bp + 12, bh);
  al = 0;
  al -= memoryAGet(ds, bp + 54);
  memoryASet(ds, bp + 54, al);
loc_14c18:
  al = memoryAGet(ds, 0x03d4);
  al &= 0x03;
  al <<= 1;
  al <<= 1;
  al += 0x66;
  memoryASet(ds, bp + 18, al);
  goto loc_14d8c;
loc_14c2a:
  al = memoryAGet(ds, bp);
  memoryASet(ds, 0x03ce, al);
  al += memoryAGet(ds, bp + 54);
  al &= 0x7f;
  memoryASet(ds, bp, al);
  sub_13a0f();
  if (flags.carry)
    goto loc_14c45;
  sub_109eb();
  if (!flags.carry)
    goto loc_14c56;
loc_14c45:
  al = memoryAGet(ds, 0x03ce);
  memoryASet(ds, bp, al);
  al = 0;
  al -= memoryAGet(ds, bp + 54);
  memoryASet(ds, bp + 54, al);
loc_14c56:
  al = memoryAGet(ds, bp + 48);
  if (al != 0x02)
    goto loc_14c61;
  goto loc_14d4e;
loc_14c61:
  if (al != 0x09)
    goto loc_14c67;
  goto loc_14c18;
loc_14c67:
  cl = memoryAGet(ds, bp + 42);
  ch = 0;
  bx = 0xeb73;
  bx += cx;
  al = memoryAGet(ds, bx);
  if (al)
    goto loc_14c7b;
  goto loc_14d3c;
loc_14c7b:
  memoryASet(ds, 0xeb7e, al);
  cl = al;
  flags.carry = (al + al) >= 0x100;
  al += al;
  al -= al + flags.carry;
  ch = al;
  bl = memoryAGet(ds, bp + 6);
  bh = memoryAGet(ds, bp + 12);
  memoryASet16(ds, 0x03cf, bx);
  bx += cx;
  if (!(bh & 0x80))
    goto loc_14c9c;
  goto loc_14d79;
loc_14c9c:
  memoryASet(ds, bp + 6, bl);
  al = bh;
  al &= 0x03;
  memoryASet(ds, bp + 12, al);
  sub_13a0f();
  if (flags.carry)
    goto loc_14cb5;
  sub_109eb();
  if (flags.carry)
    goto loc_14cb5;
  goto loc_14d3c;
loc_14cb5:
  bx = memoryAGet16(ds, 0x03cf);
  memoryASet(ds, bp + 6, bl);
  memoryASet(ds, bp + 12, bh);
  al = memoryAGet(ds, 0xeb7e);
  if (al & 0x80)
    goto loc_14cce;
  al--;
  if (al != 0)
    goto loc_14c7b;
  goto loc_14d3c;
loc_14cce:
  al++;
  if (al != 0)
    goto loc_14c7b;
  al = memoryAGet(ds, bp + 48);
  if (al != 0x03)
    goto loc_14ce7;
  memoryASet(ds, bp + 48, 0x02);
  memoryASet(ds, bp + 42, 0x00);
  goto loc_14d8c;
loc_14ce7:
  if (memoryAGet(ds, bp + 54) != 0x00)
    goto loc_14d30;
  if (memoryAGet(ds, 0x03b6) == 0x00)
    goto loc_14d30;
  if (memoryAGet(ds, 0x03b4) != 0x00)
    goto loc_14d30;
  al = memoryAGet(ds, 0x03ae);
  if (al != memoryAGet(ds, bp + 6))
    goto loc_14d30;
  al = memoryAGet(ds, 0x03af);
  if (al != memoryAGet(ds, bp + 12))
    goto loc_14d30;
  ch = 0xff;
  al = memoryAGet(ds, bp);
  al -= memoryAGet(ds, 0x03ad);
  al &= 0x7f;
  if (al < 0x40)
    goto loc_14d20;
  al |= 0x80;
loc_14d20:
  if (al < 0x80)
    goto loc_14d28;
  al = -al;
  ch = 0x01;
loc_14d28:
  if (al >= 0x20)
    goto loc_14d30;
  memoryASet(ds, bp + 54, ch);
loc_14d30:
  memoryASet(ds, bp + 42, 0x00);
  al = 0x01;
  sub_114e7();
  goto loc_14d8c;
loc_14d3c:
  al = memoryAGet(ds, bp + 42);
  al++;
  if (al < 0x0a)
    goto loc_14d48;
  al = 0x0a;
loc_14d48:
  memoryASet(ds, bp + 42, al);
  goto loc_14d8c;
loc_14d4e:
  al = 0x56;
  memoryASet(ds, bp + 18, al);
  sub_14d95();
  if (al)
    goto loc_14d5d;
  goto loc_14d8c;
loc_14d5d:
  if (al == 0x01)
    goto loc_14d6d;
  al = 0;
  al -= memoryAGet(ds, bp + 54);
  memoryASet(ds, bp + 54, al);
  goto loc_14d8c;
loc_14d6d:
  memoryASet(ds, bp + 48, 0x03);
  memoryASet(ds, bp + 42, 0x0a);
  goto loc_14d8c;
loc_14d79:
  al = 0;
  memoryASet(ds, bp + 6, al);
  memoryASet(ds, bp + 12, al);
  memoryASet(ds, bp + 42, al);
  memoryASet(ds, bp + 48, 0x04);
loc_14d8c:
  bp++;
  cx = pop();
  cx--;
  if (cx == 0)
    return;
  goto loc_14ada;
}
void sub_14d95()
{
  al = memoryAGet(ds, bp);
  stop(/*carry1*/);
  al = rcr(al, 0x01);
  al = rcr(al, 0x01);
  al = rcr(al, 0x01);
  al &= 0x0f;
  bh = al;
  bl = memoryAGet(ds, bp + 6);
  al = memoryAGet(ds, bp + 12);
  flags.carry = 0;
  al = rcr(al, 0x01);
  bl = rcr(bl, 0x01);
  al = rcr(al, 0x01);
  bl = rcr(bl, 0x01);
  bl--;
  bx += 0x055c;
  al = memoryAGet(ds, bx);
  if (!(al & 0x80))
    goto loc_14dd1;
  al &= 0x03;
  if (al != 0x01)
    goto loc_14dcd;
  al = memoryAGet(ds, bx);
  al &= 0x0c;
  if (al == 0)
    goto loc_14e2b;
  goto loc_14e28;
loc_14dcd:
  if (al != 0x03)
    goto loc_14e2b;
loc_14dd1:
  al = memoryAGet(ds, bp);
  al &= 0x07;
  if (al < 0x02)
    goto loc_14de1;
  if (al < 0x07)
    goto loc_14e25;
  goto loc_14e03;
loc_14de1:
  bx -= 0x055c;
  bh--;
  bh &= 0x0f;
  bx += 0x055c;
  al = memoryAGet(ds, bx);
  if (!(al & 0x80))
    goto loc_14e25;
  al &= 0x03;
  if (al == 0x03)
    goto loc_14e25;
  if (!(memoryAGet(ds, bp + 54) & 0x80))
    goto loc_14e28;
  goto loc_14e2b;
loc_14e03:
  bx -= 0x055c;
  bh++;
  bh &= 0x0f;
  bx += 0x055c;
  al = memoryAGet(ds, bx);
  if (!(al & 0x80))
    goto loc_14e25;
  al &= 0x03;
  if (al == 0x03)
    goto loc_14e25;
  if (memoryAGet(ds, bp + 54) & 0x80)
    goto loc_14e28;
  goto loc_14e2b;
loc_14e25:
  al = 0x01;
  return;
loc_14e28:
  al = 0x02;
  return;
loc_14e2b:
  al = 0;
}
void sub_14e2e()
{
  push(bx);
  memoryASet(ds, 0xee9f, al);
  bl = ah;
  bh = 0;
  bx <<= 1;
  bx += 0xed0f;
  ax = memoryAGet16(ds, bx);
  ax += memoryAGet16(ds, 0xee9f);
  bx = pop();
}
void sub_14e44()
{
  push(bx);
  bl = memoryAGet(ds, 0x045f);
  bl = ~bl;
  bl &= 0x07;
  ah += bl;
  memoryASet(ds, 0xee9f, al);
  bl = ah;
  bh = 0;
  bx <<= 1;
  bx += 0xeb7f;
  ax = memoryAGet16(ds, bx);
  ax += memoryAGet16(ds, 0xee9f);
  ax += 0x000b;
  bx = pop();
}
void sub_14e68()
{
  push(ds);
  ax = 0x34b1;
  ds = ax;
  ax = 0xa000;
  es = ax;
  bp = dx;
loc_14e75:
  push(cx);
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = 0x01;
  out(dx, al);
  cx = bp;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= bp;
  ax <<= 1;
  out(dx, al);
  cx = bp;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= bp;
  ax <<= 1;
  out(dx, al);
  cx = bp;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= bp;
  ax <<= 1;
  out(dx, al);
  cx = bp;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di -= bp;
  di += 0x0028;
  cx = pop();
  if (--cx)
    goto loc_14e75;
  ds = pop();
}
void sub_14ea9()
{
}
void sub_14f15()
{
  memoryASet(ds, 0xeea7, ~memoryAGet(ds, 0xeea7));
  push(ds);
  push(es);
  ax = 0x247e;
  ds = ax;
  es = ax;
  si = 0x70b2;
  di = 0x5ab2;
  cx = 0x8621;
  cx -= si;
loc_14f2d:
  al = memoryAGet(ds, si);
  tl = memoryAGet(ds, di);
  memoryASet(ds, di, al);
  al = tl;
  memoryASet(ds, si, al);
  si++;
  di++;
  if (--cx)
    goto loc_14f2d;
  es = pop();
  ds = pop();
}
void sub_14f3a()
{
  ax = 0x0001;
  dx = 0x03ce;
  out(dx, ax);
  ax = 0x0005;
  dx = 0x03ce;
  out(dx, ax);
  al = 0x08;
  ah = 0xff;
  out(dx, ax);
  al = 0x03;
  ah = 0x00;
  out(dx, ax);
loc_14f52:
  al = memoryAGet(ds, bp);
  if (al)
    goto loc_14f5b;
  return;
loc_14f5b:
  sub_14f61();
  bp++;
  goto loc_14f52;
}
void sub_14f61()
{
  bx = 0x1532;
  es = bx;
  if (memoryAGet(ds, 0xefc2) != 0x00)
    goto loc_14f70;
  goto loc_15032;
loc_14f70:
  if (al != 0x10)
    goto loc_14f77;
  goto loc_15029;
loc_14f77:
  if (al != 0x11)
    goto loc_14f7e;
  goto loc_15010;
loc_14f7e:
  ah = 0;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax += 0xefe6;
  si = ax;
  ax = 0xa000;
  es = ax;
  ax = 0;
  al = memoryAGet(ds, 0xeeaa);
  ax += memoryAGet16(ds, 0xeeab);
  di = ax;
  if (memoryAGet(ds, 0xf0b2) == 0x01)
    goto loc_14fc7;
  al = 0;
  memoryASet(es, di, al);
  memoryASet(es, di + 40, al);
  memoryASet(es, di + 80, al);
  memoryASet(es, di + 120, al);
  memoryASet(es, di + 160, al);
  memoryASet(es, di + 200, al);
  memoryASet(es, di + 240, al);
  memoryASet(es, di + 280, al);
loc_14fc7:
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = memoryAGet(ds, 0xeea8);
  out(dx, al);
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  movsb<MemAuto, MemAuto, DirAuto>();
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = 0x0f;
  out(dx, al);
  memoryASet(ds, 0xeeaa, memoryAGet(ds, 0xeeaa) + 1);
  if (memoryAGet(ds, 0xeeaa) < 0x28)
    goto loc_1500f;
  memoryASet(ds, 0xeeaa, 0x00);
  memoryASet16(ds, 0xeeab, memoryAGet16(ds, 0xeeab) + 0x0140);
loc_1500f:
  return;
loc_15010:
  al = memoryAGet(ds, bp + 1);
  cx = 0x0140;
  ah = 0;
  mul(cx);
  memoryASet16(ds, 0xeeab, ax);
  al = memoryAGet(ds, bp + 2);
  memoryASet(ds, 0xeeaa, al);
  bp += 0x0002;
  return;
loc_15029:
  bp++;
  al = memoryAGet(ds, bp);
  memoryASet(ds, 0xeea8, al);
  return;
loc_15032:
  if (al != 0x10)
    goto loc_15038;
  goto loc_15078;
loc_15038:
  if (al != 0x11)
    goto loc_1503e;
  goto loc_15059;
loc_1503e:
  push(ax);
  ax = 0xa000;
  es = ax;
  ax = pop();
  di = memoryAGet16(ds, 0xeeab);
  memoryASet(es, di, al);
  al = memoryAGet(ds, 0xeea8);
  memoryASet(es, di + 1, al);
  memoryASet16(ds, 0xeeab, memoryAGet16(ds, 0xeeab) + 0x0002);
  return;
loc_15059:
  al = memoryAGet(ds, bp + 1);
  cx = 0x0050;
  ah = 0;
  mul(cx);
  bx = ax;
  al = memoryAGet(ds, bp + 2);
  al += al;
  ah = 0;
  bx += ax;
  memoryASet16(ds, 0xeeab, bx);
  bp += 0x0002;
  return;
loc_15078:
  bp++;
  al = memoryAGet(ds, bp);
  memoryASet(ds, 0xeea8, al);
}
void sub_1509e()
{
  memoryASet(ds, 0xefc2, 0x00);
  ah = 0;
  al = 0x02;
  interrupt(0x10);
}
void sub_15164()
{
  ax = 0x0005;
  dx = 0x03ce;
  out(dx, ax);
  ax = 0xa000;
  es = ax;
  di = 0x0000;
  cx = 0x1f40;
  ax = 0;
  rep_stosb<MemAuto, DirAuto>();
}
void sub_1518e()
{
  dx = 0x03da;
loc_15191:
  in(al, dx);
  al &= 0x08;
  if (al == 0)
    goto loc_15191;
  dx = 0x03da;
loc_15199:
  in(al, dx);
  al &= 0x08;
  if (al != 0)
    goto loc_15199;
}
void sub_151ab()
{
  memoryASet16(ds, 0xf04d, 0xf0b3);
  ax = 0x1532;
  memoryASet16(ds, 0xf047, ax);
  memoryASet16(ds, 0xf04b, 0x001e);
  memoryASet16(ds, 0xf049, 0xe808);
  goto loc_15243;
  //   gap of 126 bytes
loc_15243:
  sub_125fc();
  sub_15253();
  sub_15275();
  sub_152c7();
  sub_125d7();
}
void sub_151c5()
{
  memoryASet16(ds, 0xf04d, 0xf0b3);
  ax = 0x1532;
  memoryASet16(ds, 0xf047, ax);
  memoryASet16(ds, 0xf04b, 0x001e);
  memoryASet16(ds, 0xf049, 0xe808);
  sub_125fc();
  sub_151e8();
  sub_152ae();
  goto loc_1524c;
  //   gap of 100 bytes
loc_1524c:
  sub_152c7();
  sub_125d7();
}
void sub_151e8()
{
  dx = memoryAGet16(ds, 0xf04d);
  al = 0;
  ah = 0x3d;
  interrupt(0x21);
  if (flags.carry)
    goto loc_151f8;
  memoryASet16(ds, 0xf04f, ax);
  return;
loc_151f8:
  ax = pop();
  ax = 0x1532;
  es = ax;
  di = 0xe808;
  al = 0;
  cx = 0x0004;
  rep_stosb<MemAuto, DirAuto>();
  al = 0x2e;
  cx = 0x0003;
  rep_stosb<MemAuto, DirAuto>();
  al = 0;
  cx = 0x0004;
  rep_stosb<MemAuto, DirAuto>();
  al = 0x2e;
  cx = 0x0003;
  rep_stosb<MemAuto, DirAuto>();
  al = 0;
  cx = 0x0004;
  rep_stosb<MemAuto, DirAuto>();
  al = 0x2e;
  cx = 0x0003;
  rep_stosb<MemAuto, DirAuto>();
  al = 0;
  cx = 0x0004;
  rep_stosb<MemAuto, DirAuto>();
  al = 0x2e;
  cx = 0x0003;
  rep_stosb<MemAuto, DirAuto>();
  memoryASet16(ds, 0xe824, 0x0001);
  sub_125d7();
}
void sub_15253()
{
  dx = memoryAGet16(ds, 0xf04d);
  cx = 0;
  al = 0x02;
  ah = 0x3c;
  interrupt(0x21);
  if (flags.carry)
    goto loc_1528f;
  memoryASet16(ds, 0xf04f, ax);
  return;
  //   gap of 42 bytes
loc_1528f:
  ax = pop();
  sub_125d7();
}
void sub_15275()
{
  ax = memoryAGet16(ds, 0xf047);
  bx = memoryAGet16(ds, 0xf04f);
  cx = memoryAGet16(ds, 0xf04b);
  dx = memoryAGet16(ds, 0xf049);
  push(ds);
  ds = ax;
  ah = 0x40;
  interrupt(0x21);
  ds = pop();
  if (flags.carry)
    goto loc_1528f;
  return;
loc_1528f:
  ax = pop();
  sub_125d7();
}
void sub_152ae()
{
  goto loc_152ae;
loc_1528f:
  ax = pop();
  sub_125d7();
  return;
  //   gap of 26 bytes
loc_152ae:
  ax = memoryAGet16(ds, 0xf047);
  bx = memoryAGet16(ds, 0xf04f);
  cx = 0xffff;
  dx = memoryAGet16(ds, 0xf049);
  push(ds);
  ds = ax;
  ah = 0x3f;
  interrupt(0x21);
  ds = pop();
  if (flags.carry)
    goto loc_1528f;
}
void sub_152c7()
{
  goto loc_152c7;
loc_1528f:
  ax = pop();
  sub_125d7();
  return;
  //   gap of 51 bytes
loc_152c7:
  bx = memoryAGet16(ds, 0xf04f);
  ah = 0x3e;
  interrupt(0x21);
  if (flags.carry)
    goto loc_1528f;
}

void sub_15317();
void sub_1530e()
{
  al = 0x24;
  dx = 0x0008;
  sub_15317();
}
void sub_15317()
{
  push(ds);
  push(cs);
  ds = pop();
  ah = 0x25;
  interrupt(0x21);
  ds = pop();
}
