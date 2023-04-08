#include "cicoemu.h"
using namespace CicoContext;

void sub_10000();

void start()
{
  headerSize = 0x0200;
  ds = 0x1000;
  cs = 0x1000;
  ss = 0x1f60;
  sp = 0x07d0;
  sub_10000();
}
void sub_10000();
void sub_102a3();
void sub_102bc();
void sub_10343();
void sub_1036d();
void sub_1051c();
void sub_10595();
void sub_10669();
void sub_106f8();
void sub_108ad();
void sub_108d0();
void sub_1090a();
void sub_10944();
void sub_10992();
void sub_109aa();
void sub_109dc();
void sub_10a21();
void sub_10a65();
void sub_10a90();
void sub_10aa5();
void sub_10ad3();
void sub_10ae8();
void sub_10b7e();
void sub_10bfb();
void sub_10c63();
void sub_10cae();
void sub_10cc3();
void sub_10cdc();
void sub_10cf4();
void sub_10d09();
void sub_10d28();
void sub_10d32();
void sub_10d82();
void sub_10e32();
void sub_10eb5();
void sub_10f38();
void sub_10f52();
void sub_1108d();
void sub_110f2();
void sub_11312();
void sub_11327();
void sub_114e4();
void sub_114f2();
void sub_11540();
void sub_1154e();
void sub_115e8();
void sub_11b2c();
void sub_11b65();
void sub_11c57();
void sub_11c9a();
void sub_11cd6();
void sub_11cff();
void sub_11d24();
void sub_11d4e();
void sub_11d7d();
void sub_11dab();
void sub_11dc0();
void sub_11e25();
void sub_11e3a();
void sub_11e6b();
void sub_11eb3();
void sub_11fb9();
void sub_120b0();
void sub_12249();
void sub_12265();
void sub_12289();
void sub_10000()
{
  flags.direction = false;
  ax = 0x122a;
  ds = ax;
//  in(al, 0x61);
//  al &= 0xfc;
//  out(0x0061, al);
//  ax = 0x000d;
//  interrupt(0x10);
//  ax = 0x0f00;
//  interrupt(0x10);
//  if (al != 0x0d)
//    goto loc_10027;
//  ax = 0x1200;
//  bx = 0x0010;
//  interrupt(0x10);
//  if ((char)bl >= (char)0x03)
//    goto loc_10038;
//loc_10027:
//  ax = 0x0002;
//  interrupt(0x10);
//  ah = 0x09;
//  dx = 0x0;
//  interrupt(0x21);
//  ah = 0x4c;
//  interrupt(0x21);
loc_10038:
//  sub_1051c();
  bx = 0x179;
  sub_1036d();
  dx = 0x21f;
  ax = 0x3d00;
  interrupt(0x21);
  if (!flags.carry)
    goto loc_10050;
  goto loc_1026d;
loc_10050:
  bp = ax;
  push(ds);
  ax = 0xa000;
  ds = ax;
  es = ax;
  ah = 0x01;
  bx = 0;
  sub_10a90();
  dx = 0x8000;
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x02;
  bx = 0x0001;
  sub_10a90();
  dx = 0x8000;
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x04;
  bx = 0x0002;
  sub_10a90();
  dx = 0x8000;
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x08;
  bx = 0x0003;
  sub_10a90();
  dx = 0x8000;
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ax = 0x3e00;
  interrupt(0x21);
  ds = pop();
  bx = 0x81;
  ax = 0x0001;
  cx = 0x0004;
  sub_102a3();
  cx = 0x8000;
  sub_10ad3();
  sub_102bc();
  ax = 0x000a;
  sub_10343();
  dx = 0x235;
  ax = 0x3d00;
  interrupt(0x21);
  if (!flags.carry)
    goto loc_100de;
  goto loc_1026d;
loc_100de:
  bp = ax;
  push(ds);
  ax = 0xa000;
  ds = ax;
  es = ax;
  ah = 0x01;
  bx = 0;
  sub_10a90();
  dx = 0xa000;
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x02;
  bx = 0x0001;
  sub_10a90();
  dx = 0xa000;
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x04;
  bx = 0x0002;
  sub_10a90();
  dx = 0xa000;
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x08;
  bx = 0x0003;
  sub_10a90();
  dx = 0xa000;
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ax = 0x3e00;
  interrupt(0x21);
  ds = pop();
  dx = 0x22a;
  ax = 0x3d00;
  interrupt(0x21);
  if (!flags.carry)
    goto loc_1014f;
  goto loc_1026d;
loc_1014f:
  bp = ax;
  push(ds);
  ax = 0xa000;
  ds = ax;
  es = ax;
  ah = 0x01;
  bx = 0;
  sub_10a90();
  dx = 0x0000;
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  si = 0;
  di = 0x2000;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  ah = 0x02;
  bx = 0x0001;
  sub_10a90();
  dx = 0x0000;
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  si = 0;
  di = 0x2000;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  ah = 0x04;
  bx = 0x0002;
  sub_10a90();
  dx = 0x0000;
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  si = 0;
  di = 0x2000;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  ah = 0x08;
  bx = 0x0003;
  sub_10a90();
  dx = 0x0000;
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  si = 0;
  di = 0x2000;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  ax = 0x3e00;
  interrupt(0x21);
  ds = pop();
  sub_102a3();
  cx = 0xa000;
  sub_10ad3();
  sub_102bc();
  dx = 0x240;
  ax = 0x3d00;
  interrupt(0x21);
  if (!flags.carry)
    goto loc_101e8;
  goto loc_1026d;
loc_101e8:
  bp = ax;
  push(ds);
  ax = 0xa000;
  ds = ax;
  es = ax;
  ah = 0x01;
  bx = 0;
  sub_10a90();
  dx = 0x8000;
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x02;
  bx = 0x0001;
  sub_10a90();
  dx = 0x8000;
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x04;
  bx = 0x0002;
  sub_10a90();
  dx = 0x8000;
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x08;
  bx = 0x0003;
  sub_10a90();
  dx = 0x8000;
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ax = 0x3e00;
  interrupt(0x21);
  ds = pop();
  ax = 0;
  es = ax;
  cl = memoryAGet(es, 0x041a);
  memoryASet(es, 0x041c, cl);
  interrupt(0x16);
  cx = 0x8000;
  sub_10ad3();
  ax = 0;
  interrupt(0x16);
  cx = 0x2000;
  sub_10ad3();
  goto loc_10270;
loc_1026d:
  goto loc_10356;
loc_10270:
  ax = 0x0002;
  cx = 0x0005;
loc_10277:
  ax = 0x0001;
  sub_10343();
  push(cx);
  sub_11c57();
  cx = pop();
  if (--cx)
    goto loc_10277;
  ax = 0x0003;
  ax = 0x0000;
  ax = 0x0003;
  sub_10343();
  sub_11c9a();
  bx = 0x1c5;
  ax = 0x0001;
  cx = 0x0001;
  goto loc_105e2;
  //   gap of 179 bytes
loc_10356:
  ax = 0x0002;
  sub_10595();
  ax = 0x0002;
  interrupt(0x10);
  bx = 0x21d;
  sub_1036d();
  ah = 0x4c;
  interrupt(0x21);
  //   gap of 629 bytes
loc_105e2:
  bx = 0x6bc3;
  al = memoryAGet(ds, 0x003d);
  ah = 0;
  ax <<= 1;
  bx += ax;
  si = memoryAGet16(ds, bx);
  di = 0x6af8;
  push(ds);
  es = pop();
  ax = 0x1ef8;
  ds = ax;
  cx = 0x00cb;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  push(es);
  ds = pop();
  dx = 0x6af8;
  ax = 0x3d00;
  interrupt(0x21);
  if (!flags.carry)
    goto loc_10611;
  goto loc_10627;
  //   gap of 1 bytes
loc_10611:
  bx = ax;
  dx = 0x260;
  cx = 0x4000;
  ax = 0x3f00;
  interrupt(0x21);
  ax = 0x3e00;
  interrupt(0x21);
  goto loc_1062a;
  //   gap of 1 bytes
loc_10627:
  goto loc_10356;
loc_1062a:
  if (memoryAGet(ds, 0x003d) != 0x06)
    goto loc_10645;
  if (memoryAGet(ds, 0x004a) == 0x01)
    goto loc_10645;
  push(ds);
  es = pop();
  ax = 0;
  di = 0x264;
  cx = 0x4000;
  rep_stosb<MemAuto, DirAuto>();
loc_10645:
  dx = 0x6b06;
  cx = 0x4266;
  sub_10669();
  dx = 0x6b14;
  cx = 0x476a;
  sub_10669();
  dx = 0x6b22;
  cx = 0x4c6e;
  sub_10669();
  goto loc_10685;
  //   gap of 29 bytes
loc_10685:
  si = 0x6b34;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x51a8;
  dx = 0x6aa8;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a4, al);
  sub_106f8();
  si = 0x6b45;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x57e8;
  dx = 0x6abc;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a5, al);
  sub_106f8();
  si = 0x6b56;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x5e28;
  dx = 0x6ad0;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a6, al);
  sub_106f8();
  si = 0x6b67;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x6468;
  dx = 0x6ae4;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a7, al);
  sub_106f8();
loc_106f5:
  goto loc_1078b;
  //   gap of 147 bytes
loc_1078b:
  al = memoryAGet(ds, 0x003e);
  dx = 0x426a;
  cx = 0x6b78;
  if (!al)
    goto loc_107ae;
  dx = 0x476e;
  cx = 0x6b91;
  al--;
  if (al == 0)
    goto loc_107ae;
  dx = 0x4c72;
  cx = 0x6baa;
loc_107ae:
  memoryASet16(ds, 0x4264, dx);
  memoryASet16(ds, 0x5172, cx);
  sub_10944();
  if ((char)memoryAGet(ds, 0x003b) < (char)0x00)
    goto loc_107eb;
  si = memoryAGet16(ds, 0x5172);
  si = si + 0x5; /*chk4*/
  al = memoryAGet(ds, 0x003b);
  ah = memoryAGet(ds, 0x003c);
  cx = 0x0003;
loc_107d1:
  if (al != memoryAGet(ds, si + 2))
    goto loc_107db;
  if (ah == memoryAGet(ds, si + 3))
    goto loc_107e3;
loc_107db:
  si += 0x0004;
  if (--cx)
    goto loc_107d1;
  goto loc_10356;
loc_107e3:
  ax = memoryAGet16(ds, si);
  ah += 0x01;
  memoryASet16(ds, 0x6bd3, ax);
loc_107eb:
  memoryASet(ds, 0xca34, 0x00);
  cx = 0x0005;
  bx = 0xffffca90;
  ax = 0xffff;
loc_107fa:
  memoryASet16(ds, bx, ax);
  bx += 0x0006;
  if (--cx)
    goto loc_107fa;
  ax = memoryAGet16(ds, 0x6bd3);
  memoryASet16(ds, 0x003f, ax);
  al = ah;
  ah = 0;
  flags.carry = ax < 0x000b;
  ax -= 0x000b;
  if (!flags.carry)
    goto loc_10812;
  ax = 0;
loc_10812:
  if (ax < 0x00e8)
    goto loc_1081a;
  ax = 0x00e8;
loc_1081a:
  memoryASet16(ds, 0x0041, ax);
  si = memoryAGet16(ds, 0x5172);
  si = si + 0x11; /*chk4*/
  di = 0x5174;
  cx = 0x0004;
loc_1082b:
  al = memoryAGet(ds, si);
  if (al != 0xff)
    goto loc_10837;
  memoryASet(ds, di + 11, 0xff);
  goto loc_10881;
loc_10837:
  push(cx);
  ah = 0;
  cx = ax;
  bx = 0x51a4;
  bx += ax;
  bl = memoryAGet(ds, bx);
  memoryASet(ds, di + 5, bl);
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  cx <<= 1;
  cx <<= 1;
  ax += cx;
  dx = 0x6aa8;
  dx += ax;
  memoryASet16(ds, di + 7, dx);
  al = memoryAGet(ds, si + 1);
  memoryASet(ds, di + 6, al);
  memoryASet(ds, di + 9, 0x00);
  memoryASet(ds, di + 10, 0x00);
  memoryASet(ds, di + 4, 0x14);
  memoryASet(ds, di + 11, 0x00);
  if (al < 0x80)
    goto loc_10880;
  memoryASet(ds, di + 6, memoryAGet(ds, di + 6) - 0x80);
  memoryASet(ds, di + 11, 0x02);
loc_10880:
  cx = pop();
loc_10881:
  di += 0x000c;
  si += 0x0002;
  if (--cx)
    goto loc_1082b;
  if (memoryAGet(ds, 0x003b) == 0xfe)
    goto loc_108a2;
  if (memoryAGet(ds, 0x003b) == 0xff)
    goto loc_1089f;
  sub_10b7e();
  memoryASet(ds, 0x003b, 0xff);
loc_1089f:
  goto loc_11174;
loc_108a2:
  sub_110f2();
  memoryASet(ds, 0x003b, 0xff);
  goto loc_11174;
  //   gap of 1607 bytes
loc_10ef4:
  sub_109aa();
  memoryASet16(ds, 0xc8fa, 0x0010);
  memoryASet16(ds, 0xc8fc, 0x0030);
  si = 0xffffbce4;
  di = memoryAGet16(ds, 0xca30);
  di += 0x0a05;
  sub_10f38();
  sub_10d28();
  bx = 0xffffc9e5;
  ax = 0x0001;
  cx = 0x0002;
loc_10f20:
  cx = 0;
  es = cx;
  cl = memoryAGet(es, 0x041a);
  memoryASet(es, 0x041c, cl);
  ax = 0;
  interrupt(0x16);
  sub_120b0();
  goto loc_10356;
  //   gap of 59 bytes
loc_10f73:
  sub_1108d();
  cx = 0x0014;
loc_10f79:
  push(cx);
  bx = 0xffffc979;
  ax = 0x0001;
  cx = 0x0003;
  al = 0x0a;
  sub_11e6b();
  ax = 0x0001;
  sub_10343();
  cx = pop();
  if (--cx)
    goto loc_10f79;
loc_10f93:
  if (memoryAGet(ds, 0x0043) == 0x00)
    goto loc_10fc2;
  cx = 0x000a;
loc_10f9d:
  push(cx);
  bx = 0xffffc979;
  ax = 0x0001;
  cx = 0x0003;
  al = 0x0a;
  sub_11e6b();
  ax = 0x0001;
  sub_10343();
  cx = pop();
  if (--cx)
    goto loc_10f9d;
  sub_11c9a();
  ax = 0x0003;
  sub_10343();
  goto loc_10f93;
loc_10fc2:
  bx = 0x81;
  ax = 0x0001;
  cx = 0x0004;
  dx = 0xffffc8fe;
  ax = 0x3d00;
  interrupt(0x21);
  if (!flags.carry)
    goto loc_10fdb;
  goto loc_10356;
loc_10fdb:
  bp = ax;
  push(ds);
  ax = ds;
  es = ax;
  ax = 0xa000;
  ds = ax;
  ah = 0x01;
  bx = 0;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x02;
  bx = 0x0001;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x04;
  bx = 0x0002;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x08;
  bx = 0x0003;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ax = 0x3e00;
  interrupt(0x21);
  ds = pop();
  sub_102a3();
  sub_11312();
  sub_102bc();
  ax = 0x0014;
  sub_10343();
  ax = 0;
  es = ax;
  cl = memoryAGet(es, 0x041a);
  memoryASet(es, 0x041c, cl);
  ax = 0;
  interrupt(0x16);
  sub_109aa();
  memoryASet16(ds, 0xc8fa, 0x0010);
  memoryASet16(ds, 0xc8fc, 0x0030);
  si = 0xffffbce4;
  di = memoryAGet16(ds, 0xca30);
  di += 0x0a05;
  sub_10f38();
  sub_11312();
  goto loc_10f20;
  //   gap of 231 bytes
loc_11174:
  cx = 0;
  es = cx;
  cl = memoryAGet(es, 0x041a);
  memoryASet(es, 0x041c, cl);
  if (memoryAGet(cs, 0x03ea) == 0x01)
    goto loc_111a1;
  if (memoryAGet(ds, 0xca33) == 0x01)
    goto loc_11174;
  if (memoryAGet(cs, 0x0388) == 0x01)
    goto loc_11174;
  al = memoryAGet(ds, 0x0047);
  memoryASet(ds, 0xca37, al);
  goto loc_11174;
loc_111a1:
  memoryASet(cs, 0x03ea, 0x00);
  if (memoryAGet(ds, 0xca3c) == 0x00)
    goto loc_111bc;
  memoryASet(ds, 0xca3c, memoryAGet(ds, 0xca3c) - 1);
  if (memoryAGet(ds, 0xca3c) != 0x01)
    goto loc_111bc;
  goto loc_10f73;
loc_111bc:
  ch = memoryAGet(ds, 0xca32);
  ch++;
  if (ch != 0x04)
    goto loc_111c9;
  ch = 0x01;
loc_111c9:
  memoryASet(ds, 0xca32, ch);
  memoryASet(ds, 0xca3a, 0x00);
  if (memoryAGet(ds, 0xca3b) == 0x00)
    goto loc_111e0;
  memoryASet(ds, 0xca3b, memoryAGet(ds, 0xca3b) - 1);
  sub_11cff();
loc_111e0:
  if (memoryAGet(ds, 0xca34) == 0x00)
    goto loc_111ed;
  sub_10e32();
  goto loc_11303;
loc_111ed:
  si = memoryAGet16(ds, 0x003f);
  if (memoryAGet(ds, 0xca33) == 0x00)
    goto loc_111fb;
  goto loc_113e8;
loc_111fb:
  if (memoryAGet(cs, 0x0388) != 0x01)
    goto loc_11212;
  if (memoryAGet(ds, 0xca37) == 0x01)
    goto loc_11218;
  memoryASet(ds, 0xca33, 0x01);
  goto loc_113e8;
loc_11212:
  al = memoryAGet(ds, 0x0047);
  memoryASet(ds, 0xca37, al);
loc_11218:
  if (memoryAGet(cs, 0x0387) != 0x01)
    goto loc_1124a;
  di = memoryAGet16(ds, 0x5172);
  bx = di + 0x5; /*chk4*/
  cx = 0x0003;
  ax = si;
loc_1122c:
  dx = memoryAGet16(ds, bx);
  if (al != dl)
    goto loc_11245;
  dh = -dh;
  dh += ah;
  if (dh >= 0x03)
    goto loc_11245;
  if (memoryAGet(ds, 0x0049) != 0x01)
    goto loc_11245;
  goto loc_115bd;
loc_11245:
  bx += 0x0004;
  if (--cx)
    goto loc_1122c;
loc_1124a:
  if (memoryAGet(cs, 0x0389) != 0x01)
    goto loc_1125e;
  if (memoryAGet(ds, 0x004b) != 0x01)
    goto loc_1125e;
  sub_10d82();
  goto loc_111e0;
loc_1125e:
  memoryASet(ds, 0xca35, 0x00);
  if (memoryAGet(cs, 0x039a) != 0x01)
    goto loc_11273;
  memoryASet(ds, 0xca35, 0xfb);
  sub_114e4();
loc_11273:
  if (memoryAGet(cs, 0x039c) != 0x01)
    goto loc_11283;
  memoryASet(ds, 0xca35, 0x05);
  sub_11540();
loc_11283:
  ax = si;
  al += 0x04;
  sub_108ad();
  cl = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)cl)
    goto loc_112c0;
  if (!(ah & 0x01))
    goto loc_1129c;
  if ((char)memoryAGet(ds, bx + 1) > (char)cl)
    goto loc_112c0;
loc_1129c:
  memoryASet(ds, 0xca36, 0x08);
  if ((char)memoryAGet(ds, 0xca35) < (char)0x00)
    goto loc_112b1;
  if (memoryAGet(ds, 0xca35) == 0x00)
    goto loc_112b6;
  memoryASet(ds, 0xca35, 0x02);
  goto loc_112b6;
loc_112b1:
  memoryASet(ds, 0xca35, 0xfe);
loc_112b6:
  memoryASet(ds, 0xca33, 0x01);
  memoryASet(ds, 0xca37, 0x01);
loc_112c0:
  memoryASet16(ds, 0x003f, si);
  if (memoryAGet(cs, 0x0386) != 0x01)
    goto loc_112cf;
  sub_10eb5();
loc_112cf:
  if (memoryAGet(cs, 0x03a1) != 0x01)
    goto loc_112ef;
  if (memoryAGet(ds, 0x0046) == 0x00)
    goto loc_112fd;
  ax = si;
  al++;
  sub_11b2c();
  if (memoryAGet(ds, 0xca3d) == 0x01)
    goto loc_112f8;
  sub_11d7d();
loc_112ef:
  memoryASet(ds, 0xca3d, memoryAGet(ds, 0xca3d) - 1);
  if (memoryAGet(ds, 0xca3d) != 0)
    goto loc_112fd;
  sub_11d4e();
loc_112f8:
  memoryASet(ds, 0xca3d, 0x02);
loc_112fd:
  sub_109aa();
  sub_109dc();
loc_11303:
  sub_115e8();
  sub_11b65();
  sub_11327();
  sub_11312();
  goto loc_11174;
  //   gap of 82 bytes
loc_11364:
  ax = si;
  memoryASet16(ds, 0x003f, ax);
  if ((char)al > (char)0x13)
    goto loc_11393;
  memoryASet(ds, 0xca3a, 0x04);
  cx = 0x0014;
  cl -= al;
  cx <<= 1;
  cx <<= 1;
  cx <<= 1;
  push(cx);
  sub_109aa();
  cx = pop();
  bx = 0x0020;
  bx -= cx;
  sub_10ae8();
  sub_11312();
  ax = 0x0001;
  sub_10343();
loc_11393:
  sub_109aa();
  sub_11312();
  ax = 0x0002;
  sub_10343();
  ax = 0x0001;
  bx = 0xffffca5e;
  cx = 0x0004;
  ax = 0x000f;
  sub_10343();
  if (memoryAGet(ds, 0x0043) != 0x00)
    goto loc_113ba;
  goto loc_10ef4;
loc_113ba:
  sub_11c9a();
  memoryASet(ds, 0xca32, 0x00);
  memoryASet(ds, 0xca33, 0x00);
  memoryASet(ds, 0xca35, 0x00);
  memoryASet(ds, 0xca36, 0x00);
  memoryASet(ds, 0xca37, 0x00);
  memoryASet(ds, 0xca3a, 0x00);
  memoryASet(ds, 0xca3b, 0x06);
  memoryASet(ds, 0xca3d, 0x02);
  goto loc_107eb;
loc_113e8:
  memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) - 1);
  if (memoryAGet(ds, 0xca37) == 0)
    goto loc_113fd;
  if (memoryAGet(cs, 0x0388) != 0x01)
    goto loc_11401;
  memoryASet(ds, 0xca36, memoryAGet(ds, 0xca36) - 0x07);
  goto loc_11401;
loc_113fd:
  memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) + 1);
loc_11401:
  al = memoryAGet(ds, 0xca36);
  cl = al;
  al = sar(al, 1);
  al = sar(al, 1);
  al = sar(al, 1);
  bx = si;
  bl += al;
  if (stop(/*71*/))
    goto loc_11414;
  bl = 0x00;
loc_11414:
  si = bx;
  if (bl < 0x11)
    goto loc_1141e;
  goto loc_11364;
loc_1141e:
  if (memoryAGet(ds, 0x003d) != 0x02)
    goto loc_11428;
  cl -= 0x02;
loc_11428:
  cl += 0x05;
  if ((char)cl < (char)0x18)
    goto loc_11432;
  cl = 0x17;
loc_11432:
  memoryASet(ds, 0xca36, cl);
  cl = memoryAGet(ds, 0xca35);
  if (memoryAGet(cs, 0x039a) != 0x01)
    goto loc_11450;
  memoryASet(ds, 0xca39, 0x05);
  cl--;
  if ((char)cl >= (char)0xfb)
    goto loc_11450;
  cl = 0xfb;
loc_11450:
  if (memoryAGet(cs, 0x039c) != 0x01)
    goto loc_11466;
  memoryASet(ds, 0xca39, 0x00);
  cl++;
  if ((char)cl <= (char)0x05)
    goto loc_11466;
  cl = 0x05;
loc_11466:
  memoryASet(ds, 0xca35, cl);
  if ((char)cl >= 0)
    goto loc_11475;
  memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) + 1);
  sub_114f2();
loc_11475:
  al = memoryAGet(ds, 0xca35);
  if (stop(/*condition!*/))
    goto loc_11483;
  memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) - 1);
  sub_1154e();
loc_11483:
  ax = si;
  sub_108ad();
  dl = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)dl)
    goto loc_1149a;
  if (!(ah & 0x01))
    goto loc_1149f;
  if ((char)memoryAGet(ds, bx + 1) <= (char)dl)
    goto loc_1149f;
loc_1149a:
  memoryASet(ds, 0xca36, 0x08);
loc_1149f:
  if ((char)memoryAGet(ds, 0xca36) <= (char)0x00)
    goto loc_114c1;
  cx = si;
  ax = cx;
  al += 0x05;
  sub_108ad();
  dl = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)dl)
    goto loc_114c9;
  if (!(ah & 0x01))
    goto loc_114c1;
  if ((char)memoryAGet(ds, bx + 1) > (char)dl)
    goto loc_114c9;
loc_114c1:
  memoryASet(ds, 0xca3a, 0x04);
  goto loc_112c0;
loc_114c9:
  if (cl < 0x0f)
    goto loc_114d0;
  goto loc_114c1;
loc_114d0:
  cl++;
  cl &= 0xfe;
  si = cx;
  memoryASet(ds, 0xca33, 0x00);
  memoryASet(ds, 0xca36, 0x00);
  goto loc_112c0;
  //   gap of 217 bytes
loc_115bd:
  push(bx);
  ax = memoryAGet16(ds, bx);
  sub_10bfb();
  bx = pop();
  al = memoryAGet(ds, 0x003d);
  memoryASet(ds, 0x003b, al);
  al = memoryAGet(ds, 0x003e);
  memoryASet(ds, 0x003c, al);
  al = memoryAGet(ds, bx + 3);
  memoryASet(ds, 0x003e, al);
  al = memoryAGet(ds, bx + 2);
  memoryASet(ds, 0x003d, al);
  if (al == memoryAGet(ds, 0x003b))
    goto loc_115e5;
  goto loc_105e2;
loc_115e5:
  goto loc_1078b;
}
void sub_102a3()
{
  ax = 0x1000;
  bx = 0x0002;
  interrupt(0x10);
  ax = 0x1000;
  bx = 0x000a;
  interrupt(0x10);
  ax = 0x1000;
  bx = 0x000c;
  interrupt(0x10);
}
void sub_102bc()
{
  ax = 0x1000;
  bx = 0x1802;
  interrupt(0x10);
  ax = 0x1000;
  bx = 0x180a;
  interrupt(0x10);
  ax = 0x1000;
  bx = 0x180c;
  interrupt(0x10);
  ax = 0x0001;
  sub_10343();
  ax = 0x1000;
  bx = 0x0702;
  interrupt(0x10);
  ax = 0x1000;
  bx = 0x070a;
  interrupt(0x10);
  ax = 0x1000;
  bx = 0x070c;
  interrupt(0x10);
  ax = 0x0001;
  sub_10343();
  ax = 0x1000;
  bx = 0x0702;
  interrupt(0x10);
  ax = 0x1000;
  bx = 0x1f0a;
  interrupt(0x10);
  ax = 0x1000;
  bx = 0x1f0c;
  interrupt(0x10);
  ax = 0x0001;
  sub_10343();
  ax = 0x1000;
  bx = 0x0202;
  interrupt(0x10);
  ax = 0x1000;
  bx = 0x1a0a;
  interrupt(0x10);
  ax = 0x1000;
  bx = 0x1f0c;
  interrupt(0x10);
  ax = 0x0001;
  sub_10343();
  ax = 0x1000;
  bx = 0x1c0c;
  interrupt(0x10);
  ax = 0x0001;
  sub_10343();
}
void sub_10343()
{
    sync();
//loc_10343:
//  if (memoryAGet(cs, 0x03ea) != 0x01)
//    goto loc_10343;
//  memoryASet(cs, 0x03ea, 0x00);
//  ax--;
//  if (ax != 0)
//    goto loc_10343;
}
void sub_1036d()
{
loc_1036d:
  al = memoryAGet(ds, bx);
  bx++;
  al ^= 0x25;
  if (al == 0x1a)
    return;
  push(bx);
  bx = 0x0007;
  ah = 0x0e;
  interrupt(0x10);
  bx = pop();
  goto loc_1036d;
}
void sub_1051c()
{
  push(ds);
  ax = 0;
  ds = ax;
  flags.interrupts = false;
  bx = 0x382;
  ax = memoryAGet16(ds, 0x0026);
  memoryASet16(cs, bx + 2, ax);
  ax = memoryAGet16(ds, 0x0024);
  memoryASet16(cs, bx, ax);
  ax = 0x3a2;
  memoryASet16(ds, 0x0024, ax);
  memoryASet16(ds, 0x0026, cs);
  bx = 0x3e6;
  ax = memoryAGet16(ds, 0x0022);
  memoryASet16(cs, bx + 2, ax);
  ax = memoryAGet16(ds, 0x0020);
  memoryASet16(cs, bx, ax);
  ax = 0x3f5;
  memoryASet16(ds, 0x0020, ax);
  memoryASet16(ds, 0x0022, cs);
  bx = 0x3df;
  ax = memoryAGet16(ds, 0x008e);
  memoryASet16(cs, bx + 2, ax);
  ax = memoryAGet16(ds, 0x008c);
  memoryASet16(cs, bx, ax);
  ax = 0x3e3;
  memoryASet16(ds, 0x008c, ax);
  memoryASet16(ds, 0x008e, cs);
  bx = 0x49f;
  ax = memoryAGet16(ds, 0x000e);
  memoryASet16(cs, bx + 2, ax);
  ax = memoryAGet16(ds, 0x000c);
  memoryASet16(cs, bx, ax);
  ax = 0x4a3;
  memoryASet16(ds, 0x000c, ax);
  memoryASet16(ds, 0x000e, cs);
  flags.interrupts = true;
  ds = pop();
}
void sub_10595()
{
  push(ds);
  ax = 0;
  ds = ax;
  flags.interrupts = false;
  bx = 0x382;
  ax = memoryAGet16(cs, bx + 2);
  memoryASet16(ds, 0x0026, ax);
  ax = memoryAGet16(cs, bx);
  memoryASet16(ds, 0x0024, ax);
  bx = 0x3e6;
  ax = memoryAGet16(cs, bx + 2);
  memoryASet16(ds, 0x0022, ax);
  ax = memoryAGet16(cs, bx);
  memoryASet16(ds, 0x0020, ax);
  bx = 0x3df;
  ax = memoryAGet16(cs, bx + 2);
  memoryASet16(ds, 0x008e, ax);
  ax = memoryAGet16(cs, bx);
  memoryASet16(ds, 0x008c, ax);
  bx = 0x49f;
  ax = memoryAGet16(cs, bx + 2);
  memoryASet16(ds, 0x000e, ax);
  ax = memoryAGet16(cs, bx);
  memoryASet16(ds, 0x000c, ax);
  flags.interrupts = true;
  ds = pop();
}
void sub_10669()
{
  goto loc_10669;
loc_10356:
  ax = 0x0002;
  sub_10595();
  ax = 0x0002;
  interrupt(0x10);
  bx = 0x21d;
  sub_1036d();
  ah = 0x4c;
  interrupt(0x21);
  //   gap of 698 bytes
loc_10627:
  goto loc_10356;
  //   gap of 63 bytes
loc_10669:
  push(cx);
  ax = 0x3d00;
  interrupt(0x21);
  if (!flags.carry)
    goto loc_10674;
  cx = pop();
  goto loc_10627;
loc_10674:
  bx = ax;
  dx = pop();
  cx = 0x0504;
  ax = 0x3f00;
  interrupt(0x21);
  ax = 0x3e00;
  interrupt(0x21);
}
void sub_106f8()
{
  goto loc_106f8;
loc_10356:
  ax = 0x0002;
  sub_10595();
  ax = 0x0002;
  interrupt(0x10);
  bx = 0x21d;
  sub_1036d();
  ah = 0x4c;
  interrupt(0x21);
  //   gap of 698 bytes
loc_10627:
  goto loc_10356;
  //   gap of 206 bytes
loc_106f8:
  push(dx);
  al = memoryAGet(ds, si);
  ah = 0;
  if (memoryAGet(ds, si + 1) == 0x01)
    goto loc_10705;
  ax <<= 1;
loc_10705:
  bx = ax;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  bx <<= 1;
  bx <<= 1;
  bx <<= 1;
  bx <<= 1;
  bx <<= 1;
  ax += bx;
  push(ax);
  dx = si + 0x3; /*chk4*/
  ax = 0x3d00;
  interrupt(0x21);
  if (!flags.carry)
    goto loc_1072f;
  goto loc_10627;
loc_1072f:
  bx = ax;
  dx = di;
  cx = pop();
  ax = 0x3f00;
  interrupt(0x21);
  ax = 0x3e00;
  interrupt(0x21);
  bx = pop();
  push(bx);
  dx = di;
  cl = memoryAGet(ds, si);
loc_10744:
  memoryASet16(ds, bx, dx);
  bx += 0x0002;
  dx += 0x00a0;
  cl--;
  if (cl != 0)
    goto loc_10744;
  if (memoryAGet(ds, si + 2) == 0x00)
    goto loc_10761;
  dx -= 0x0140;
  memoryASet16(ds, bx, dx);
  dx += 0x0140;
loc_10761:
  if (memoryAGet(ds, si + 1) == 0x02)
    goto loc_10769;
  dx = di;
loc_10769:
  bx = pop();
  push(bx);
  bx += 0x000a;
  cl = memoryAGet(ds, si);
loc_10770:
  memoryASet16(ds, bx, dx);
  bx += 0x0002;
  dx += 0x00a0;
  cl--;
  if (cl != 0)
    goto loc_10770;
  if (memoryAGet(ds, si + 2) == 0x00)
    goto loc_10789;
  dx -= 0x0140;
  memoryASet16(ds, bx, dx);
loc_10789:
  bx = pop();
}
void sub_108ad()
{
  push(ax);
  bl = ah;
  bh = 0;
  ah = 0;
  bx >>= 1;
  ax >>= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax += bx;
  bx = memoryAGet16(ds, 0x4264);
  bx += ax;
  ax = pop();
}
void sub_108d0()
{
  cx = ax;
  bl = ah;
  bh = 0;
  ah = 0;
  bx >>= 1;
  ax >>= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax += bx;
  bx = memoryAGet16(ds, 0x4264);
  bx += ax;
  ax = cx;
  cl = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)cl)
    goto loc_10908;
  if (!(ah & 0x01))
    goto loc_10906;
  if ((char)memoryAGet(ds, bx + 1) > (char)cl)
    goto loc_10908;
loc_10906:
  flags.carry = false;
  return;
loc_10908:
  flags.carry = true;
}
void sub_1090a()
{
  cx = ax;
  bl = ah;
  bh = 0;
  ah = 0;
  bx >>= 1;
  ax >>= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax += bx;
  bx = memoryAGet16(ds, 0x4264);
  bx += ax;
  ax = cx;
  cl = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)cl)
    goto loc_10942;
  if (!(al & 0x01))
    goto loc_10940;
  if ((char)memoryAGet(ds, bx + 128) > (char)cl)
    goto loc_10942;
loc_10940:
  flags.carry = false;
  return;
loc_10942:
  flags.carry = true;
}
void sub_10944()
{
  ax = 0xa000;
  es = ax;
  cx = 0x0a80;
  di = 0x4000;
  si = memoryAGet16(ds, 0x4264);
loc_10953:
  lodsb<MemAuto, DirAuto>();
  ah = 0;
  push(si);
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  si = 0x264;
  si += ax;
  ah = 0x01;
  sub_10992();
  ah = 0x02;
  sub_10992();
  ah = 0x04;
  sub_10992();
  ah = 0x08;
  sub_10992();
  di += 0x0002;
  si = pop();
  cl--;
  if (cl != 0)
    goto loc_10953;
  di += 0x0f00;
  cl = 0x80;
  ch--;
  if (ch != 0)
    goto loc_10953;
}
void sub_10992()
{
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = ah;
  out(dx, al);
  bx = 0x0010;
  push(di);
loc_109a0:
  movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x00fe;
  bx--;
  if (bx != 0)
    goto loc_109a0;
  di = pop();
}
void sub_109aa()
{
  push(ds);
  si = 0x4000;
  si += memoryAGet16(ds, 0x0041);
  di = memoryAGet16(ds, 0xca30);
  di += 0x0141;
  ax = 0xa000;
  es = ax;
  ds = ax;
  ah = 0x01;
  bx = 0;
  sub_10a65();
  ah = 0x02;
  bx++;
  sub_10a65();
  ah = 0x04;
  bx++;
  sub_10a65();
  ah = 0x08;
  bx++;
  sub_10a65();
  ds = pop();
}
void sub_109dc()
{
  si = 0x6be0;
  al = memoryAGet(ds, 0xca39);
  ah = memoryAGet(ds, 0xca3a);
  al += ah;
  ah = 0;
  dx = ax;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  dx <<= 1;
  dx <<= 1;
  dx <<= 1;
  dx <<= 1;
  dx <<= 1;
  ax += dx;
  ax <<= 1;
  si += ax;
  cx = 0x0020;
  bp = si;
  bp += 0x0100;
  ax = memoryAGet16(ds, 0x003f);
  dx = memoryAGet16(ds, 0x0041);
  ah -= dl;
  sub_10a21();
}
void sub_10a21()
{
  di = memoryAGet16(ds, 0xca30);
  di += 0x0141;
  dl = ah;
  dh = 0;
  ah = 0;
  bh = al;
  bl = 0;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax += bx;
  ax += dx;
  di += ax;
  ah = 0x01;
  bx = 0;
  sub_10aa5();
  ah = 0x02;
  bx = 0x0001;
  sub_10aa5();
  ah = 0x04;
  bx = 0x0002;
  sub_10aa5();
  ah = 0x08;
  bx = 0x0003;
  sub_10aa5();
}
void sub_10a65()
{
  push(si);
  push(di);
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = ah;
  out(dx, al);
  dx = 0x03ce;
  al = 0x04;
  out(dx, al);
  dx++;
  al = bl;
  out(dx, al);
  dx = 0x00a0;
loc_10a7e:
  cx = 0x000c;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  si += 0x00e8;
  di += 0x0010;
  dx--;
  if (dx != 0)
    goto loc_10a7e;
  di = pop();
  si = pop();
}
void sub_10a90()
{
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = ah;
  out(dx, al);
  dx = 0x03ce;
  al = 0x04;
  out(dx, al);
  dx++;
  al = bl;
  out(dx, al);
}
void sub_10aa5()
{
  push(di);
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = ah;
  out(dx, al);
  dx = 0x03ce;
  al = 0x04;
  out(dx, al);
  dx++;
  al = bl;
  out(dx, al);
  bx = bp;
  dx = cx;
loc_10abe:
  ax = memoryAGet16(ds, bx);
  memoryASet16(es, di, memoryAGet16(es, di) & ax);
  lodsw<MemAuto, DirAuto>();
  memoryASet16(es, di, memoryAGet16(es, di) | ax);
  di += 0x0028;
  bx += 0x0002;
  if (--cx)
    goto loc_10abe;
  cx = dx;
  di = pop();
}
void sub_10ad3()
{
  dx = 0x03d4;
  al = 0x0c;
  out(dx, al);
  dx++;
  al = ch;
  out(dx, al);
  dx = 0x03d4;
  al = 0x0d;
  out(dx, al);
  dx++;
  al = cl;
  out(dx, al);
}
void sub_10ae8()
{
  push(bx);
  push(cx);
  si = 0x6be0;
  al = memoryAGet(ds, 0xca39);
  ah = memoryAGet(ds, 0xca3a);
  al += ah;
  ah = 0;
  dx = ax;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  dx <<= 1;
  dx <<= 1;
  dx <<= 1;
  dx <<= 1;
  dx <<= 1;
  ax += dx;
  ax <<= 1;
  si += ax;
  bp = si;
  bp += 0x0100;
  ax = memoryAGet16(ds, 0x003f);
  dx = memoryAGet16(ds, 0x0041);
  ah -= dl;
  cx = pop();
  di = memoryAGet16(ds, 0xca30);
  di += 0x0141;
  dl = ah;
  dh = 0;
  ah = 0;
  bh = al;
  bl = 0;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax += bx;
  ax += dx;
  di += ax;
  ah = 0x01;
  bx = 0;
  sub_10aa5();
  bx = pop();
  si += bx;
  si += bx;
  push(bx);
  ah = 0x02;
  bx = 0x0001;
  sub_10aa5();
  bx = pop();
  si += bx;
  si += bx;
  push(bx);
  ah = 0x04;
  bx = 0x0002;
  sub_10aa5();
  bx = pop();
  si += bx;
  si += bx;
  ah = 0x08;
  bx = 0x0003;
  sub_10aa5();
}
void sub_10b7e()
{
  ax = memoryAGet16(ds, 0x003f);
  bx = memoryAGet16(ds, 0x0041);
  ah -= bl;
  ah -= 0x01;
  dl = ah;
  dh = 0;
  ah = 0;
  bh = al;
  bl = 0;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax += bx;
  ax += dx;
  di = 0x0141;
  di += ax;
  memoryASet16(ds, 0xc8f0, di);
  ax = 0x0003;
  sub_10343();
  bx = 0xffffc909;
  ax = 0x0001;
  cx = 0x0004;
  sub_109aa();
  sub_10d28();
  sub_109aa();
  sub_10cf4();
  sub_109dc();
  sub_10c63();
  sub_10d28();
  sub_109aa();
  sub_10cf4();
  sub_109dc();
  sub_10d28();
  sub_109aa();
  sub_10c63();
  sub_10cf4();
  sub_10c63();
  sub_109dc();
  sub_10d28();
  sub_109aa();
  sub_109dc();
  sub_10d28();
}
void sub_10bfb()
{
  bx = memoryAGet16(ds, 0x0041);
  ah -= bl;
  dl = ah;
  dh = 0;
  ah = 0;
  bh = al;
  bl = 0;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax += bx;
  ax += dx;
  di = 0x0141;
  di += ax;
  memoryASet16(ds, 0xc8f0, di);
  bx = 0xffffc909;
  ax = 0x0001;
  cx = 0x0004;
  sub_109aa();
  sub_10cf4();
  sub_10c63();
  sub_109dc();
  sub_10d28();
  sub_109aa();
  sub_10cf4();
  sub_109dc();
  sub_10d28();
  sub_109aa();
  sub_10c63();
  sub_10cf4();
  sub_109dc();
  sub_10c63();
  sub_10d28();
  sub_109aa();
  sub_10d28();
}
void sub_10c63()
{
  bx = 0x6b30;
  al = memoryAGet(ds, bx);
  sub_10cae();
  si++;
  di = memoryAGet16(ds, 0xc8f0);
  push(bx);
  sub_10cc3();
  bx = pop();
  al = memoryAGet(ds, bx + 1);
  sub_10cae();
  di = memoryAGet16(ds, 0xc8f0);
  di += 0x0003;
  push(bx);
  sub_10cc3();
  bx = pop();
  al = memoryAGet(ds, bx + 2);
  sub_10cae();
  si++;
  di = memoryAGet16(ds, 0xc8f0);
  di += 0x0280;
  push(bx);
  sub_10cc3();
  bx = pop();
  al = memoryAGet(ds, bx + 3);
  sub_10cae();
  di = memoryAGet16(ds, 0xc8f0);
  di += 0x0283;
  sub_10cc3();
}
void sub_10cae()
{
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  si = 0x264;
  si += ax;
}
void sub_10cc3()
{
  di += memoryAGet16(ds, 0xca30);
  ah = 0x01;
  sub_10cdc();
  ah = 0x02;
  sub_10cdc();
  ah = 0x04;
  sub_10cdc();
  ah = 0x08;
  sub_10cdc();
}
void sub_10cdc()
{
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = ah;
  out(dx, al);
  bx = 0x0010;
  push(di);
loc_10cea:
  movsb<MemAuto, MemAuto, DirAuto>();
  si++;
  di += 0x0027;
  bx--;
  if (bx != 0)
    goto loc_10cea;
  di = pop();
}
void sub_10cf4()
{
  ah = 0x01;
  sub_10d09();
  ah = 0x02;
  sub_10d09();
  ah = 0x04;
  sub_10d09();
  ah = 0x08;
  sub_10d09();
}
void sub_10d09()
{
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = ah;
  out(dx, al);
  di = memoryAGet16(ds, 0xc8f0);
  di += memoryAGet16(ds, 0xca30);
  cx = 0x0020;
  ax = 0;
loc_10d20:
  stosw<MemAuto, DirAuto>();
  stosw<MemAuto, DirAuto>();
  di += 0x0024;
  if (--cx)
    goto loc_10d20;
}
void sub_10d28()
{
  ax = 0x0001;
  sub_10343();
  sub_11312();
}
void sub_10d32()
{
  bx = 0xffffc931;
  ax = 0x0001;
  cx = 0x0004;
  cx = 0x0008;
  si = 0x7cc0;
loc_10d44:
  push(cx);
  push(si);
  push(cx);
  sub_109aa();
  cx = pop();
  if ((short)cx <= (short)0x0004)
    goto loc_10d53;
  sub_109dc();
loc_10d53:
  sub_115e8();
  si = pop();
  push(si);
  bp = si;
  bp += 0x0100;
  dx = memoryAGet16(ds, 0x0041);
  ax = memoryAGet16(ds, 0x003f);
  ah -= dl;
  cx = 0x0020;
  sub_10a21();
  sub_11327();
  sub_11312();
  ax = 0x0001;
  sub_10343();
  si = pop();
  si += 0x0140;
  cx = pop();
  if (--cx)
    goto loc_10d44;
}
void sub_10d82()
{
  ax = memoryAGet16(ds, 0x003f);
  bx = memoryAGet16(ds, 0x0041);
  dx = bx;
  memoryASet(ds, 0xc8f7, 0x00);
  bl = -bl;
  bl += ah;
  if (memoryAGet(ds, 0xca39) == 0x00)
    goto loc_10db8;
  memoryASet16(ds, 0xc8f8, 0xffff);
  flags.carry = bl < 0x06;
  bl -= 0x06;
  if (flags.carry)
    goto loc_10e10;
  ah -= 0x06;
  flags.carry = bl < 0x0a;
  bl -= 0x0a;
  if (!flags.carry)
    goto loc_10dde;
  bl = -bl;
  flags.carry = dl < bl;
  dl -= bl;
  if (!flags.carry)
    goto loc_10dda;
  bl += dl;
  goto loc_10dda;
loc_10db8:
  memoryASet16(ds, 0xc8f8, 0x0001);
  if (bl >= 0x11)
    goto loc_10e10;
  ah += 0x06;
  bl += 0x06;
  bl -= 0x0c;
  if (stop(/*71*/))
    goto loc_10dde;
  dl += bl;
  if ((char)dl <= (char)0xe8)
    goto loc_10dda;
  dl -= 0xe8;
  bl -= dl;
loc_10dda:
  memoryASet(ds, 0xc8f7, bl);
loc_10dde:
  cl = memoryAGet(ds, 0x0260);
  al = 0x12;
  ah &= 0xfe;
  sub_108ad();
loc_10dea:
  if ((char)memoryAGet(ds, bx) > (char)cl)
    goto loc_10dfd;
  bx -= 0x0080;
  al -= 0x02;
  if (al != 0)
    goto loc_10dea;
  goto loc_10e10;
  //   gap of 1 bytes
loc_10df9:
  if ((char)memoryAGet(ds, bx) <= (char)cl)
    goto loc_10e0b;
loc_10dfd:
  dx = 0x0002;
loc_10e00:
  bx -= 0x0080;
  flags.carry = al < 0x02;
  al -= 0x02;
  if (!flags.carry)
    goto loc_10df9;
  goto loc_10e10;
  //   gap of 1 bytes
loc_10e0b:
  dx--;
  if (dx != 0)
    goto loc_10e00;
  goto loc_10e13;
loc_10e10:
  ax = memoryAGet16(ds, 0x003f);
loc_10e13:
  memoryASet(ds, 0xc8f2, 0x00);
  memoryASet16(ds, 0xc8f3, ax);
  ax = memoryAGet16(ds, 0x003f);
  memoryASet16(ds, 0xc8f5, ax);
  memoryASet(ds, 0xca34, 0x01);
  bx = 0xffffc959;
  ax = 0x0001;
  cx = 0x0002;
}
void sub_10e32()
{
  if (memoryAGet(ds, 0xc8f7) == 0x00)
    goto loc_10e45;
  bx = memoryAGet16(ds, 0xc8f8);
  memoryASet16(ds, 0x0041, memoryAGet16(ds, 0x0041) + bx);
  memoryASet(ds, 0xc8f7, memoryAGet(ds, 0xc8f7) - 1);
loc_10e45:
  sub_109aa();
  if (memoryAGet(ds, 0xc8f2) != 0x03)
    goto loc_10e55;
  ax = memoryAGet16(ds, 0xc8f3);
  memoryASet16(ds, 0x003f, ax);
loc_10e55:
  sub_109dc();
  al = memoryAGet(ds, 0xc8f2);
  if (al == 0x05)
    goto loc_10e7e;
  ah = 0;
  ax <<= 1;
  si = 0xffff999a;
  si += ax;
  si = memoryAGet16(ds, si);
  bp = si;
  bp += 0x0100;
  ax = memoryAGet16(ds, 0xc8f5);
  ah -= memoryAGet(ds, 0x0041);
  cx = 0x0020;
  sub_10a21();
loc_10e7e:
  al = memoryAGet(ds, 0xc8f2);
  flags.carry = al < 0x01;
  al -= 0x01;
  if (flags.carry)
    goto loc_10ea4;
  ah = 0;
  ax <<= 1;
  si = 0xffff999a;
  si += ax;
  si = memoryAGet16(ds, si);
  bp = si;
  bp += 0x0100;
  ax = memoryAGet16(ds, 0xc8f3);
  ah -= memoryAGet(ds, 0x0041);
  cx = 0x0020;
  sub_10a21();
loc_10ea4:
  memoryASet(ds, 0xc8f2, memoryAGet(ds, 0xc8f2) + 1);
  if (memoryAGet(ds, 0xc8f2) != 0x06)
    return;
  memoryASet(ds, 0xca34, 0x00);
}
void sub_10eb5()
{
  goto loc_10eb5;
loc_10356:
  ax = 0x0002;
  sub_10595();
  ax = 0x0002;
  interrupt(0x10);
  bx = 0x21d;
  sub_1036d();
  ah = 0x4c;
  interrupt(0x21);
  //   gap of 2888 bytes
loc_10eb5:
  sub_109aa();
  memoryASet16(ds, 0xc8fa, 0x0010);
  memoryASet16(ds, 0xc8fc, 0x0030);
  si = 0xffffb0e4;
  di = memoryAGet16(ds, 0xca30);
  di += 0x0a05;
  sub_10f38();
  sub_10d28();
  cx = 0;
  es = cx;
  cl = memoryAGet(es, 0x041a);
  memoryASet(es, 0x041c, cl);
  ax = 0;
  interrupt(0x16);
  if (al != 0x71)
    goto loc_10eef;
loc_10eec:
  goto loc_10356;
loc_10eef:
  if (al == 0x51)
    goto loc_10eec;
}
void sub_10f38()
{
  ax = 0xa000;
  es = ax;
  ah = 0x01;
  sub_10f52();
  ah = 0x02;
  sub_10f52();
  ah = 0x04;
  sub_10f52();
  ah = 0x08;
  sub_10f52();
}
void sub_10f52()
{
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = ah;
  out(dx, al);
  push(di);
  dx = di;
  bx = memoryAGet16(ds, 0xc8fc);
loc_10f63:
  cx = memoryAGet16(ds, 0xc8fa);
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  dx += 0x0028;
  di = dx;
  bx--;
  if (bx != 0)
    goto loc_10f63;
  di = pop();
}
void sub_1108d()
{
  bx = 0xffffc985;
  ax = 0x0001;
  cx = 0x0004;
  sub_109aa();
  sub_109dc();
  sub_11312();
  ax = 0x0001;
  sub_10343();
  cx = 0x000c;
  si = 0xffff8a80;
loc_110ae:
  push(cx);
  push(si);
  push(cx);
  sub_109aa();
  cx = pop();
  if ((short)cx <= (short)0x0006)
    goto loc_110bd;
  sub_109dc();
loc_110bd:
  si = pop();
  push(si);
  bp = si;
  bp += 0x0100;
  dx = memoryAGet16(ds, 0x0041);
  ax = memoryAGet16(ds, 0x003f);
  ah -= dl;
  cx = 0x0020;
  sub_10a21();
  sub_11312();
  ax = 0x0001;
  sub_10343();
  si = pop();
  si += 0x0140;
  cx = pop();
  if (--cx)
    goto loc_110ae;
  sub_109aa();
  sub_11312();
  ax = 0x0006;
  sub_10343();
}
void sub_110f2()
{
  cx = 0x000f;
loc_110f5:
  push(cx);
  sub_109aa();
  sub_11327();
  sub_11312();
  ax = 0x0001;
  sub_10343();
  cx = pop();
  if (--cx)
    goto loc_110f5;
  ax = 0x0004;
  if (!ax)
    goto loc_11115;
  cx = 0x0001;
  goto loc_110f5;
loc_11115:
  bx = 0xffffc985;
  ax = 0x0001;
  cx = 0x0004;
  cx = 0x000c;
  si = 0xffff8a80;
loc_11127:
  push(cx);
  push(si);
  push(cx);
  sub_109aa();
  cx = pop();
  if ((short)cx > (short)0x0006)
    goto loc_11136;
  sub_109dc();
loc_11136:
  si = pop();
  push(si);
  bp = si;
  bp += 0x0100;
  dx = memoryAGet16(ds, 0x0041);
  ax = memoryAGet16(ds, 0x003f);
  ah -= dl;
  cx = 0x0020;
  sub_10a21();
  sub_11327();
  sub_11312();
  ax = 0x0001;
  sub_10343();
  si = pop();
  si += 0x0140;
  cx = pop();
  if (--cx)
    goto loc_11127;
  sub_109aa();
  sub_109dc();
  sub_11327();
  sub_11312();
  ax = 0x0001;
  sub_10343();
}
void sub_11312()
{
  cx = memoryAGet16(ds, 0xca30);
  sub_10ad3();
  cx -= 0x2000;
  if (cx == 0)
    goto loc_11322;
  cx = 0x2000;
loc_11322:
  memoryASet16(ds, 0xca30, cx);
}
void sub_11327()
{
  di = memoryAGet16(ds, 0x5172);
  if (memoryAGet(ds, di) == 0xff)
    return;
  bx = 0x51;
  al = memoryAGet(ds, 0x003e);
  al <<= 1;
  al <<= 1;
  al <<= 1;
  al <<= 1;
  al += memoryAGet(ds, 0x003d);
  ah = 0;
  bx += ax;
  if (memoryAGet(ds, bx) == 0x01)
    return;
  ax = memoryAGet16(ds, di + 1);
  dx = memoryAGet16(ds, 0x0041);
  ah -= dl;
  if ((char)ah < 0)
    return;
  if ((char)ah > (char)0x16)
    return;
  bl = memoryAGet(ds, di);
  sub_11fb9();
}
void sub_114e4()
{
  goto loc_114e4;
loc_10356:
  ax = 0x0002;
  sub_10595();
  ax = 0x0002;
  interrupt(0x10);
  bx = 0x21d;
  sub_1036d();
  ah = 0x4c;
  interrupt(0x21);
  //   gap of 629 bytes
loc_105e2:
  bx = 0x6bc3;
  al = memoryAGet(ds, 0x003d);
  ah = 0;
  ax <<= 1;
  bx += ax;
  si = memoryAGet16(ds, bx);
  di = 0x6af8;
  push(ds);
  es = pop();
  ax = 0x1ef8;
  ds = ax;
  cx = 0x00cb;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  push(es);
  ds = pop();
  dx = 0x6af8;
  ax = 0x3d00;
  interrupt(0x21);
  if (!flags.carry)
    goto loc_10611;
  goto loc_10627;
  //   gap of 1 bytes
loc_10611:
  bx = ax;
  dx = 0x260;
  cx = 0x4000;
  ax = 0x3f00;
  interrupt(0x21);
  ax = 0x3e00;
  interrupt(0x21);
  goto loc_1062a;
  //   gap of 1 bytes
loc_10627:
  goto loc_10356;
loc_1062a:
  if (memoryAGet(ds, 0x003d) != 0x06)
    goto loc_10645;
  if (memoryAGet(ds, 0x004a) == 0x01)
    goto loc_10645;
  push(ds);
  es = pop();
  ax = 0;
  di = 0x264;
  cx = 0x4000;
  rep_stosb<MemAuto, DirAuto>();
loc_10645:
  dx = 0x6b06;
  cx = 0x4266;
  sub_10669();
  dx = 0x6b14;
  cx = 0x476a;
  sub_10669();
  dx = 0x6b22;
  cx = 0x4c6e;
  sub_10669();
  goto loc_10685;
  //   gap of 29 bytes
loc_10685:
  si = 0x6b34;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x51a8;
  dx = 0x6aa8;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a4, al);
  sub_106f8();
  si = 0x6b45;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x57e8;
  dx = 0x6abc;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a5, al);
  sub_106f8();
  si = 0x6b56;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x5e28;
  dx = 0x6ad0;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a6, al);
  sub_106f8();
  si = 0x6b67;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x6468;
  dx = 0x6ae4;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a7, al);
  sub_106f8();
loc_106f5:
  goto loc_1078b;
  //   gap of 147 bytes
loc_1078b:
  al = memoryAGet(ds, 0x003e);
  dx = 0x426a;
  cx = 0x6b78;
  if (!al)
    goto loc_107ae;
  dx = 0x476e;
  cx = 0x6b91;
  al--;
  if (al == 0)
    goto loc_107ae;
  dx = 0x4c72;
  cx = 0x6baa;
loc_107ae:
  memoryASet16(ds, 0x4264, dx);
  memoryASet16(ds, 0x5172, cx);
  sub_10944();
  if ((char)memoryAGet(ds, 0x003b) < (char)0x00)
    goto loc_107eb;
  si = memoryAGet16(ds, 0x5172);
  si = si + 0x5; /*chk4*/
  al = memoryAGet(ds, 0x003b);
  ah = memoryAGet(ds, 0x003c);
  cx = 0x0003;
loc_107d1:
  if (al != memoryAGet(ds, si + 2))
    goto loc_107db;
  if (ah == memoryAGet(ds, si + 3))
    goto loc_107e3;
loc_107db:
  si += 0x0004;
  if (--cx)
    goto loc_107d1;
  goto loc_10356;
loc_107e3:
  ax = memoryAGet16(ds, si);
  ah += 0x01;
  memoryASet16(ds, 0x6bd3, ax);
loc_107eb:
  memoryASet(ds, 0xca34, 0x00);
  cx = 0x0005;
  bx = 0xffffca90;
  ax = 0xffff;
loc_107fa:
  memoryASet16(ds, bx, ax);
  bx += 0x0006;
  if (--cx)
    goto loc_107fa;
  ax = memoryAGet16(ds, 0x6bd3);
  memoryASet16(ds, 0x003f, ax);
  al = ah;
  ah = 0;
  flags.carry = ax < 0x000b;
  ax -= 0x000b;
  if (!flags.carry)
    goto loc_10812;
  ax = 0;
loc_10812:
  if (ax < 0x00e8)
    goto loc_1081a;
  ax = 0x00e8;
loc_1081a:
  memoryASet16(ds, 0x0041, ax);
  si = memoryAGet16(ds, 0x5172);
  si = si + 0x11; /*chk4*/
  di = 0x5174;
  cx = 0x0004;
loc_1082b:
  al = memoryAGet(ds, si);
  if (al != 0xff)
    goto loc_10837;
  memoryASet(ds, di + 11, 0xff);
  goto loc_10881;
loc_10837:
  push(cx);
  ah = 0;
  cx = ax;
  bx = 0x51a4;
  bx += ax;
  bl = memoryAGet(ds, bx);
  memoryASet(ds, di + 5, bl);
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  cx <<= 1;
  cx <<= 1;
  ax += cx;
  dx = 0x6aa8;
  dx += ax;
  memoryASet16(ds, di + 7, dx);
  al = memoryAGet(ds, si + 1);
  memoryASet(ds, di + 6, al);
  memoryASet(ds, di + 9, 0x00);
  memoryASet(ds, di + 10, 0x00);
  memoryASet(ds, di + 4, 0x14);
  memoryASet(ds, di + 11, 0x00);
  if (al < 0x80)
    goto loc_10880;
  memoryASet(ds, di + 6, memoryAGet(ds, di + 6) - 0x80);
  memoryASet(ds, di + 11, 0x02);
loc_10880:
  cx = pop();
loc_10881:
  di += 0x000c;
  si += 0x0002;
  if (--cx)
    goto loc_1082b;
  if (memoryAGet(ds, 0x003b) == 0xfe)
    goto loc_108a2;
  if (memoryAGet(ds, 0x003b) == 0xff)
    goto loc_1089f;
  sub_10b7e();
  memoryASet(ds, 0x003b, 0xff);
loc_1089f:
  goto loc_11174;
loc_108a2:
  sub_110f2();
  memoryASet(ds, 0x003b, 0xff);
  goto loc_11174;
  //   gap of 1607 bytes
loc_10ef4:
  sub_109aa();
  memoryASet16(ds, 0xc8fa, 0x0010);
  memoryASet16(ds, 0xc8fc, 0x0030);
  si = 0xffffbce4;
  di = memoryAGet16(ds, 0xca30);
  di += 0x0a05;
  sub_10f38();
  sub_10d28();
  bx = 0xffffc9e5;
  ax = 0x0001;
  cx = 0x0002;
loc_10f20:
  cx = 0;
  es = cx;
  cl = memoryAGet(es, 0x041a);
  memoryASet(es, 0x041c, cl);
  ax = 0;
  interrupt(0x16);
  sub_120b0();
  goto loc_10356;
  //   gap of 59 bytes
loc_10f73:
  sub_1108d();
  cx = 0x0014;
loc_10f79:
  push(cx);
  bx = 0xffffc979;
  ax = 0x0001;
  cx = 0x0003;
  al = 0x0a;
  sub_11e6b();
  ax = 0x0001;
  sub_10343();
  cx = pop();
  if (--cx)
    goto loc_10f79;
loc_10f93:
  if (memoryAGet(ds, 0x0043) == 0x00)
    goto loc_10fc2;
  cx = 0x000a;
loc_10f9d:
  push(cx);
  bx = 0xffffc979;
  ax = 0x0001;
  cx = 0x0003;
  al = 0x0a;
  sub_11e6b();
  ax = 0x0001;
  sub_10343();
  cx = pop();
  if (--cx)
    goto loc_10f9d;
  sub_11c9a();
  ax = 0x0003;
  sub_10343();
  goto loc_10f93;
loc_10fc2:
  bx = 0x81;
  ax = 0x0001;
  cx = 0x0004;
  dx = 0xffffc8fe;
  ax = 0x3d00;
  interrupt(0x21);
  if (!flags.carry)
    goto loc_10fdb;
  goto loc_10356;
loc_10fdb:
  bp = ax;
  push(ds);
  ax = ds;
  es = ax;
  ax = 0xa000;
  ds = ax;
  ah = 0x01;
  bx = 0;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x02;
  bx = 0x0001;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x04;
  bx = 0x0002;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x08;
  bx = 0x0003;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ax = 0x3e00;
  interrupt(0x21);
  ds = pop();
  sub_102a3();
  sub_11312();
  sub_102bc();
  ax = 0x0014;
  sub_10343();
  ax = 0;
  es = ax;
  cl = memoryAGet(es, 0x041a);
  memoryASet(es, 0x041c, cl);
  ax = 0;
  interrupt(0x16);
  sub_109aa();
  memoryASet16(ds, 0xc8fa, 0x0010);
  memoryASet16(ds, 0xc8fc, 0x0030);
  si = 0xffffbce4;
  di = memoryAGet16(ds, 0xca30);
  di += 0x0a05;
  sub_10f38();
  sub_11312();
  goto loc_10f20;
  //   gap of 231 bytes
loc_11174:
  cx = 0;
  es = cx;
  cl = memoryAGet(es, 0x041a);
  memoryASet(es, 0x041c, cl);
  if (memoryAGet(cs, 0x03ea) == 0x01)
    goto loc_111a1;
  if (memoryAGet(ds, 0xca33) == 0x01)
    goto loc_11174;
  if (memoryAGet(cs, 0x0388) == 0x01)
    goto loc_11174;
  al = memoryAGet(ds, 0x0047);
  memoryASet(ds, 0xca37, al);
  goto loc_11174;
loc_111a1:
  memoryASet(cs, 0x03ea, 0x00);
  if (memoryAGet(ds, 0xca3c) == 0x00)
    goto loc_111bc;
  memoryASet(ds, 0xca3c, memoryAGet(ds, 0xca3c) - 1);
  if (memoryAGet(ds, 0xca3c) != 0x01)
    goto loc_111bc;
  goto loc_10f73;
loc_111bc:
  ch = memoryAGet(ds, 0xca32);
  ch++;
  if (ch != 0x04)
    goto loc_111c9;
  ch = 0x01;
loc_111c9:
  memoryASet(ds, 0xca32, ch);
  memoryASet(ds, 0xca3a, 0x00);
  if (memoryAGet(ds, 0xca3b) == 0x00)
    goto loc_111e0;
  memoryASet(ds, 0xca3b, memoryAGet(ds, 0xca3b) - 1);
  sub_11cff();
loc_111e0:
  if (memoryAGet(ds, 0xca34) == 0x00)
    goto loc_111ed;
  sub_10e32();
  goto loc_11303;
loc_111ed:
  si = memoryAGet16(ds, 0x003f);
  if (memoryAGet(ds, 0xca33) == 0x00)
    goto loc_111fb;
  goto loc_113e8;
loc_111fb:
  if (memoryAGet(cs, 0x0388) != 0x01)
    goto loc_11212;
  if (memoryAGet(ds, 0xca37) == 0x01)
    goto loc_11218;
  memoryASet(ds, 0xca33, 0x01);
  goto loc_113e8;
loc_11212:
  al = memoryAGet(ds, 0x0047);
  memoryASet(ds, 0xca37, al);
loc_11218:
  if (memoryAGet(cs, 0x0387) != 0x01)
    goto loc_1124a;
  di = memoryAGet16(ds, 0x5172);
  bx = di + 0x5; /*chk4*/
  cx = 0x0003;
  ax = si;
loc_1122c:
  dx = memoryAGet16(ds, bx);
  if (al != dl)
    goto loc_11245;
  dh = -dh;
  dh += ah;
  if (dh >= 0x03)
    goto loc_11245;
  if (memoryAGet(ds, 0x0049) != 0x01)
    goto loc_11245;
  goto loc_115bd;
loc_11245:
  bx += 0x0004;
  if (--cx)
    goto loc_1122c;
loc_1124a:
  if (memoryAGet(cs, 0x0389) != 0x01)
    goto loc_1125e;
  if (memoryAGet(ds, 0x004b) != 0x01)
    goto loc_1125e;
  sub_10d82();
  goto loc_111e0;
loc_1125e:
  memoryASet(ds, 0xca35, 0x00);
  if (memoryAGet(cs, 0x039a) != 0x01)
    goto loc_11273;
  memoryASet(ds, 0xca35, 0xfb);
  sub_114e4();
loc_11273:
  if (memoryAGet(cs, 0x039c) != 0x01)
    goto loc_11283;
  memoryASet(ds, 0xca35, 0x05);
  sub_11540();
loc_11283:
  ax = si;
  al += 0x04;
  sub_108ad();
  cl = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)cl)
    goto loc_112c0;
  if (!(ah & 0x01))
    goto loc_1129c;
  if ((char)memoryAGet(ds, bx + 1) > (char)cl)
    goto loc_112c0;
loc_1129c:
  memoryASet(ds, 0xca36, 0x08);
  if ((char)memoryAGet(ds, 0xca35) < (char)0x00)
    goto loc_112b1;
  if (memoryAGet(ds, 0xca35) == 0x00)
    goto loc_112b6;
  memoryASet(ds, 0xca35, 0x02);
  goto loc_112b6;
loc_112b1:
  memoryASet(ds, 0xca35, 0xfe);
loc_112b6:
  memoryASet(ds, 0xca33, 0x01);
  memoryASet(ds, 0xca37, 0x01);
loc_112c0:
  memoryASet16(ds, 0x003f, si);
  if (memoryAGet(cs, 0x0386) != 0x01)
    goto loc_112cf;
  sub_10eb5();
loc_112cf:
  if (memoryAGet(cs, 0x03a1) != 0x01)
    goto loc_112ef;
  if (memoryAGet(ds, 0x0046) == 0x00)
    goto loc_112fd;
  ax = si;
  al++;
  sub_11b2c();
  if (memoryAGet(ds, 0xca3d) == 0x01)
    goto loc_112f8;
  sub_11d7d();
loc_112ef:
  memoryASet(ds, 0xca3d, memoryAGet(ds, 0xca3d) - 1);
  if (memoryAGet(ds, 0xca3d) != 0)
    goto loc_112fd;
  sub_11d4e();
loc_112f8:
  memoryASet(ds, 0xca3d, 0x02);
loc_112fd:
  sub_109aa();
  sub_109dc();
loc_11303:
  sub_115e8();
  sub_11b65();
  sub_11327();
  sub_11312();
  goto loc_11174;
  //   gap of 82 bytes
loc_11364:
  ax = si;
  memoryASet16(ds, 0x003f, ax);
  if ((char)al > (char)0x13)
    goto loc_11393;
  memoryASet(ds, 0xca3a, 0x04);
  cx = 0x0014;
  cl -= al;
  cx <<= 1;
  cx <<= 1;
  cx <<= 1;
  push(cx);
  sub_109aa();
  cx = pop();
  bx = 0x0020;
  bx -= cx;
  sub_10ae8();
  sub_11312();
  ax = 0x0001;
  sub_10343();
loc_11393:
  sub_109aa();
  sub_11312();
  ax = 0x0002;
  sub_10343();
  ax = 0x0001;
  bx = 0xffffca5e;
  cx = 0x0004;
  ax = 0x000f;
  sub_10343();
  if (memoryAGet(ds, 0x0043) != 0x00)
    goto loc_113ba;
  goto loc_10ef4;
loc_113ba:
  sub_11c9a();
  memoryASet(ds, 0xca32, 0x00);
  memoryASet(ds, 0xca33, 0x00);
  memoryASet(ds, 0xca35, 0x00);
  memoryASet(ds, 0xca36, 0x00);
  memoryASet(ds, 0xca37, 0x00);
  memoryASet(ds, 0xca3a, 0x00);
  memoryASet(ds, 0xca3b, 0x06);
  memoryASet(ds, 0xca3d, 0x02);
  goto loc_107eb;
loc_113e8:
  memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) - 1);
  if (memoryAGet(ds, 0xca37) == 0)
    goto loc_113fd;
  if (memoryAGet(cs, 0x0388) != 0x01)
    goto loc_11401;
  memoryASet(ds, 0xca36, memoryAGet(ds, 0xca36) - 0x07);
  goto loc_11401;
loc_113fd:
  memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) + 1);
loc_11401:
  al = memoryAGet(ds, 0xca36);
  cl = al;
  al = sar(al, 1);
  al = sar(al, 1);
  al = sar(al, 1);
  bx = si;
  bl += al;
  if (stop(/*71*/))
    goto loc_11414;
  bl = 0x00;
loc_11414:
  si = bx;
  if (bl < 0x11)
    goto loc_1141e;
  goto loc_11364;
loc_1141e:
  if (memoryAGet(ds, 0x003d) != 0x02)
    goto loc_11428;
  cl -= 0x02;
loc_11428:
  cl += 0x05;
  if ((char)cl < (char)0x18)
    goto loc_11432;
  cl = 0x17;
loc_11432:
  memoryASet(ds, 0xca36, cl);
  cl = memoryAGet(ds, 0xca35);
  if (memoryAGet(cs, 0x039a) != 0x01)
    goto loc_11450;
  memoryASet(ds, 0xca39, 0x05);
  cl--;
  if ((char)cl >= (char)0xfb)
    goto loc_11450;
  cl = 0xfb;
loc_11450:
  if (memoryAGet(cs, 0x039c) != 0x01)
    goto loc_11466;
  memoryASet(ds, 0xca39, 0x00);
  cl++;
  if ((char)cl <= (char)0x05)
    goto loc_11466;
  cl = 0x05;
loc_11466:
  memoryASet(ds, 0xca35, cl);
  if ((char)cl >= 0)
    goto loc_11475;
  memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) + 1);
  sub_114f2();
loc_11475:
  al = memoryAGet(ds, 0xca35);
  if (stop(/*condition!*/))
    goto loc_11483;
  memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) - 1);
  sub_1154e();
loc_11483:
  ax = si;
  sub_108ad();
  dl = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)dl)
    goto loc_1149a;
  if (!(ah & 0x01))
    goto loc_1149f;
  if ((char)memoryAGet(ds, bx + 1) <= (char)dl)
    goto loc_1149f;
loc_1149a:
  memoryASet(ds, 0xca36, 0x08);
loc_1149f:
  if ((char)memoryAGet(ds, 0xca36) <= (char)0x00)
    goto loc_114c1;
  cx = si;
  ax = cx;
  al += 0x05;
  sub_108ad();
  dl = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)dl)
    goto loc_114c9;
  if (!(ah & 0x01))
    goto loc_114c1;
  if ((char)memoryAGet(ds, bx + 1) > (char)dl)
    goto loc_114c9;
loc_114c1:
  memoryASet(ds, 0xca3a, 0x04);
  goto loc_112c0;
loc_114c9:
  if (cl < 0x0f)
    goto loc_114d0;
  goto loc_114c1;
loc_114d0:
  cl++;
  cl &= 0xfe;
  si = cx;
  memoryASet(ds, 0xca33, 0x00);
  memoryASet(ds, 0xca36, 0x00);
  goto loc_112c0;
loc_114e4:
  if (memoryAGet(ds, 0xca39) == 0x05)
    goto loc_114f2;
  memoryASet(ds, 0xca39, 0x05);
  goto loc_1153f;
loc_114f2:
  ax = si;
  if (ah)
    goto loc_1150a;
  di = memoryAGet16(ds, 0x5172);
  if (memoryAGet(ds, di + 3) == 0xff)
    goto loc_1153a;
  ah = 0xfe;
  bl = memoryAGet(ds, di + 3);
  goto loc_1159e;
loc_1150a:
  ah--;
  al += 0x03;
  sub_108ad();
  al -= 0x03;
  ch = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)ch)
    goto loc_1153a;
  si = ax;
  ch = memoryAGet(ds, 0xca32);
  memoryASet(ds, 0xca3a, ch);
  bx = memoryAGet16(ds, 0x0041);
  ah -= bl;
  if (!bx)
    goto loc_1153f;
  if (ah >= 0x0a)
    goto loc_1153f;
  memoryASet16(ds, 0x0041, memoryAGet16(ds, 0x0041) - 1);
  goto loc_1153f;
loc_1153a:
  memoryASet(ds, 0xca35, 0x00);
loc_1153f:
  return;
  //   gap of 94 bytes
loc_1159e:
  memoryASet16(ds, 0x6bd3, ax);
  memoryASet(ds, 0xca36, 0x00);
  memoryASet(ds, 0x003b, 0xff);
  memoryASet(ds, 0x003e, bl);
  ax = 0x0001;
  bx = 0xffffca3e;
  cx = 0x0004;
  goto loc_1078b;
loc_115bd:
  push(bx);
  ax = memoryAGet16(ds, bx);
  sub_10bfb();
  bx = pop();
  al = memoryAGet(ds, 0x003d);
  memoryASet(ds, 0x003b, al);
  al = memoryAGet(ds, 0x003e);
  memoryASet(ds, 0x003c, al);
  al = memoryAGet(ds, bx + 3);
  memoryASet(ds, 0x003e, al);
  al = memoryAGet(ds, bx + 2);
  memoryASet(ds, 0x003d, al);
  if (al == memoryAGet(ds, 0x003b))
    goto loc_115e5;
  goto loc_105e2;
loc_115e5:
  goto loc_1078b;
}
void sub_114f2()
{
  goto loc_114f2;
loc_10356:
  ax = 0x0002;
  sub_10595();
  ax = 0x0002;
  interrupt(0x10);
  bx = 0x21d;
  sub_1036d();
  ah = 0x4c;
  interrupt(0x21);
  //   gap of 629 bytes
loc_105e2:
  bx = 0x6bc3;
  al = memoryAGet(ds, 0x003d);
  ah = 0;
  ax <<= 1;
  bx += ax;
  si = memoryAGet16(ds, bx);
  di = 0x6af8;
  push(ds);
  es = pop();
  ax = 0x1ef8;
  ds = ax;
  cx = 0x00cb;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  push(es);
  ds = pop();
  dx = 0x6af8;
  ax = 0x3d00;
  interrupt(0x21);
  if (!flags.carry)
    goto loc_10611;
  goto loc_10627;
  //   gap of 1 bytes
loc_10611:
  bx = ax;
  dx = 0x260;
  cx = 0x4000;
  ax = 0x3f00;
  interrupt(0x21);
  ax = 0x3e00;
  interrupt(0x21);
  goto loc_1062a;
  //   gap of 1 bytes
loc_10627:
  goto loc_10356;
loc_1062a:
  if (memoryAGet(ds, 0x003d) != 0x06)
    goto loc_10645;
  if (memoryAGet(ds, 0x004a) == 0x01)
    goto loc_10645;
  push(ds);
  es = pop();
  ax = 0;
  di = 0x264;
  cx = 0x4000;
  rep_stosb<MemAuto, DirAuto>();
loc_10645:
  dx = 0x6b06;
  cx = 0x4266;
  sub_10669();
  dx = 0x6b14;
  cx = 0x476a;
  sub_10669();
  dx = 0x6b22;
  cx = 0x4c6e;
  sub_10669();
  goto loc_10685;
  //   gap of 29 bytes
loc_10685:
  si = 0x6b34;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x51a8;
  dx = 0x6aa8;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a4, al);
  sub_106f8();
  si = 0x6b45;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x57e8;
  dx = 0x6abc;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a5, al);
  sub_106f8();
  si = 0x6b56;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x5e28;
  dx = 0x6ad0;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a6, al);
  sub_106f8();
  si = 0x6b67;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x6468;
  dx = 0x6ae4;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a7, al);
  sub_106f8();
loc_106f5:
  goto loc_1078b;
  //   gap of 147 bytes
loc_1078b:
  al = memoryAGet(ds, 0x003e);
  dx = 0x426a;
  cx = 0x6b78;
  if (!al)
    goto loc_107ae;
  dx = 0x476e;
  cx = 0x6b91;
  al--;
  if (al == 0)
    goto loc_107ae;
  dx = 0x4c72;
  cx = 0x6baa;
loc_107ae:
  memoryASet16(ds, 0x4264, dx);
  memoryASet16(ds, 0x5172, cx);
  sub_10944();
  if ((char)memoryAGet(ds, 0x003b) < (char)0x00)
    goto loc_107eb;
  si = memoryAGet16(ds, 0x5172);
  si = si + 0x5; /*chk4*/
  al = memoryAGet(ds, 0x003b);
  ah = memoryAGet(ds, 0x003c);
  cx = 0x0003;
loc_107d1:
  if (al != memoryAGet(ds, si + 2))
    goto loc_107db;
  if (ah == memoryAGet(ds, si + 3))
    goto loc_107e3;
loc_107db:
  si += 0x0004;
  if (--cx)
    goto loc_107d1;
  goto loc_10356;
loc_107e3:
  ax = memoryAGet16(ds, si);
  ah += 0x01;
  memoryASet16(ds, 0x6bd3, ax);
loc_107eb:
  memoryASet(ds, 0xca34, 0x00);
  cx = 0x0005;
  bx = 0xffffca90;
  ax = 0xffff;
loc_107fa:
  memoryASet16(ds, bx, ax);
  bx += 0x0006;
  if (--cx)
    goto loc_107fa;
  ax = memoryAGet16(ds, 0x6bd3);
  memoryASet16(ds, 0x003f, ax);
  al = ah;
  ah = 0;
  flags.carry = ax < 0x000b;
  ax -= 0x000b;
  if (!flags.carry)
    goto loc_10812;
  ax = 0;
loc_10812:
  if (ax < 0x00e8)
    goto loc_1081a;
  ax = 0x00e8;
loc_1081a:
  memoryASet16(ds, 0x0041, ax);
  si = memoryAGet16(ds, 0x5172);
  si = si + 0x11; /*chk4*/
  di = 0x5174;
  cx = 0x0004;
loc_1082b:
  al = memoryAGet(ds, si);
  if (al != 0xff)
    goto loc_10837;
  memoryASet(ds, di + 11, 0xff);
  goto loc_10881;
loc_10837:
  push(cx);
  ah = 0;
  cx = ax;
  bx = 0x51a4;
  bx += ax;
  bl = memoryAGet(ds, bx);
  memoryASet(ds, di + 5, bl);
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  cx <<= 1;
  cx <<= 1;
  ax += cx;
  dx = 0x6aa8;
  dx += ax;
  memoryASet16(ds, di + 7, dx);
  al = memoryAGet(ds, si + 1);
  memoryASet(ds, di + 6, al);
  memoryASet(ds, di + 9, 0x00);
  memoryASet(ds, di + 10, 0x00);
  memoryASet(ds, di + 4, 0x14);
  memoryASet(ds, di + 11, 0x00);
  if (al < 0x80)
    goto loc_10880;
  memoryASet(ds, di + 6, memoryAGet(ds, di + 6) - 0x80);
  memoryASet(ds, di + 11, 0x02);
loc_10880:
  cx = pop();
loc_10881:
  di += 0x000c;
  si += 0x0002;
  if (--cx)
    goto loc_1082b;
  if (memoryAGet(ds, 0x003b) == 0xfe)
    goto loc_108a2;
  if (memoryAGet(ds, 0x003b) == 0xff)
    goto loc_1089f;
  sub_10b7e();
  memoryASet(ds, 0x003b, 0xff);
loc_1089f:
  goto loc_11174;
loc_108a2:
  sub_110f2();
  memoryASet(ds, 0x003b, 0xff);
  goto loc_11174;
  //   gap of 1607 bytes
loc_10ef4:
  sub_109aa();
  memoryASet16(ds, 0xc8fa, 0x0010);
  memoryASet16(ds, 0xc8fc, 0x0030);
  si = 0xffffbce4;
  di = memoryAGet16(ds, 0xca30);
  di += 0x0a05;
  sub_10f38();
  sub_10d28();
  bx = 0xffffc9e5;
  ax = 0x0001;
  cx = 0x0002;
loc_10f20:
  cx = 0;
  es = cx;
  cl = memoryAGet(es, 0x041a);
  memoryASet(es, 0x041c, cl);
  ax = 0;
  interrupt(0x16);
  sub_120b0();
  goto loc_10356;
  //   gap of 59 bytes
loc_10f73:
  sub_1108d();
  cx = 0x0014;
loc_10f79:
  push(cx);
  bx = 0xffffc979;
  ax = 0x0001;
  cx = 0x0003;
  al = 0x0a;
  sub_11e6b();
  ax = 0x0001;
  sub_10343();
  cx = pop();
  if (--cx)
    goto loc_10f79;
loc_10f93:
  if (memoryAGet(ds, 0x0043) == 0x00)
    goto loc_10fc2;
  cx = 0x000a;
loc_10f9d:
  push(cx);
  bx = 0xffffc979;
  ax = 0x0001;
  cx = 0x0003;
  al = 0x0a;
  sub_11e6b();
  ax = 0x0001;
  sub_10343();
  cx = pop();
  if (--cx)
    goto loc_10f9d;
  sub_11c9a();
  ax = 0x0003;
  sub_10343();
  goto loc_10f93;
loc_10fc2:
  bx = 0x81;
  ax = 0x0001;
  cx = 0x0004;
  dx = 0xffffc8fe;
  ax = 0x3d00;
  interrupt(0x21);
  if (!flags.carry)
    goto loc_10fdb;
  goto loc_10356;
loc_10fdb:
  bp = ax;
  push(ds);
  ax = ds;
  es = ax;
  ax = 0xa000;
  ds = ax;
  ah = 0x01;
  bx = 0;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x02;
  bx = 0x0001;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x04;
  bx = 0x0002;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x08;
  bx = 0x0003;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ax = 0x3e00;
  interrupt(0x21);
  ds = pop();
  sub_102a3();
  sub_11312();
  sub_102bc();
  ax = 0x0014;
  sub_10343();
  ax = 0;
  es = ax;
  cl = memoryAGet(es, 0x041a);
  memoryASet(es, 0x041c, cl);
  ax = 0;
  interrupt(0x16);
  sub_109aa();
  memoryASet16(ds, 0xc8fa, 0x0010);
  memoryASet16(ds, 0xc8fc, 0x0030);
  si = 0xffffbce4;
  di = memoryAGet16(ds, 0xca30);
  di += 0x0a05;
  sub_10f38();
  sub_11312();
  goto loc_10f20;
  //   gap of 231 bytes
loc_11174:
  cx = 0;
  es = cx;
  cl = memoryAGet(es, 0x041a);
  memoryASet(es, 0x041c, cl);
  if (memoryAGet(cs, 0x03ea) == 0x01)
    goto loc_111a1;
  if (memoryAGet(ds, 0xca33) == 0x01)
    goto loc_11174;
  if (memoryAGet(cs, 0x0388) == 0x01)
    goto loc_11174;
  al = memoryAGet(ds, 0x0047);
  memoryASet(ds, 0xca37, al);
  goto loc_11174;
loc_111a1:
  memoryASet(cs, 0x03ea, 0x00);
  if (memoryAGet(ds, 0xca3c) == 0x00)
    goto loc_111bc;
  memoryASet(ds, 0xca3c, memoryAGet(ds, 0xca3c) - 1);
  if (memoryAGet(ds, 0xca3c) != 0x01)
    goto loc_111bc;
  goto loc_10f73;
loc_111bc:
  ch = memoryAGet(ds, 0xca32);
  ch++;
  if (ch != 0x04)
    goto loc_111c9;
  ch = 0x01;
loc_111c9:
  memoryASet(ds, 0xca32, ch);
  memoryASet(ds, 0xca3a, 0x00);
  if (memoryAGet(ds, 0xca3b) == 0x00)
    goto loc_111e0;
  memoryASet(ds, 0xca3b, memoryAGet(ds, 0xca3b) - 1);
  sub_11cff();
loc_111e0:
  if (memoryAGet(ds, 0xca34) == 0x00)
    goto loc_111ed;
  sub_10e32();
  goto loc_11303;
loc_111ed:
  si = memoryAGet16(ds, 0x003f);
  if (memoryAGet(ds, 0xca33) == 0x00)
    goto loc_111fb;
  goto loc_113e8;
loc_111fb:
  if (memoryAGet(cs, 0x0388) != 0x01)
    goto loc_11212;
  if (memoryAGet(ds, 0xca37) == 0x01)
    goto loc_11218;
  memoryASet(ds, 0xca33, 0x01);
  goto loc_113e8;
loc_11212:
  al = memoryAGet(ds, 0x0047);
  memoryASet(ds, 0xca37, al);
loc_11218:
  if (memoryAGet(cs, 0x0387) != 0x01)
    goto loc_1124a;
  di = memoryAGet16(ds, 0x5172);
  bx = di + 0x5; /*chk4*/
  cx = 0x0003;
  ax = si;
loc_1122c:
  dx = memoryAGet16(ds, bx);
  if (al != dl)
    goto loc_11245;
  dh = -dh;
  dh += ah;
  if (dh >= 0x03)
    goto loc_11245;
  if (memoryAGet(ds, 0x0049) != 0x01)
    goto loc_11245;
  goto loc_115bd;
loc_11245:
  bx += 0x0004;
  if (--cx)
    goto loc_1122c;
loc_1124a:
  if (memoryAGet(cs, 0x0389) != 0x01)
    goto loc_1125e;
  if (memoryAGet(ds, 0x004b) != 0x01)
    goto loc_1125e;
  sub_10d82();
  goto loc_111e0;
loc_1125e:
  memoryASet(ds, 0xca35, 0x00);
  if (memoryAGet(cs, 0x039a) != 0x01)
    goto loc_11273;
  memoryASet(ds, 0xca35, 0xfb);
  sub_114e4();
loc_11273:
  if (memoryAGet(cs, 0x039c) != 0x01)
    goto loc_11283;
  memoryASet(ds, 0xca35, 0x05);
  sub_11540();
loc_11283:
  ax = si;
  al += 0x04;
  sub_108ad();
  cl = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)cl)
    goto loc_112c0;
  if (!(ah & 0x01))
    goto loc_1129c;
  if ((char)memoryAGet(ds, bx + 1) > (char)cl)
    goto loc_112c0;
loc_1129c:
  memoryASet(ds, 0xca36, 0x08);
  if ((char)memoryAGet(ds, 0xca35) < (char)0x00)
    goto loc_112b1;
  if (memoryAGet(ds, 0xca35) == 0x00)
    goto loc_112b6;
  memoryASet(ds, 0xca35, 0x02);
  goto loc_112b6;
loc_112b1:
  memoryASet(ds, 0xca35, 0xfe);
loc_112b6:
  memoryASet(ds, 0xca33, 0x01);
  memoryASet(ds, 0xca37, 0x01);
loc_112c0:
  memoryASet16(ds, 0x003f, si);
  if (memoryAGet(cs, 0x0386) != 0x01)
    goto loc_112cf;
  sub_10eb5();
loc_112cf:
  if (memoryAGet(cs, 0x03a1) != 0x01)
    goto loc_112ef;
  if (memoryAGet(ds, 0x0046) == 0x00)
    goto loc_112fd;
  ax = si;
  al++;
  sub_11b2c();
  if (memoryAGet(ds, 0xca3d) == 0x01)
    goto loc_112f8;
  sub_11d7d();
loc_112ef:
  memoryASet(ds, 0xca3d, memoryAGet(ds, 0xca3d) - 1);
  if (memoryAGet(ds, 0xca3d) != 0)
    goto loc_112fd;
  sub_11d4e();
loc_112f8:
  memoryASet(ds, 0xca3d, 0x02);
loc_112fd:
  sub_109aa();
  sub_109dc();
loc_11303:
  sub_115e8();
  sub_11b65();
  sub_11327();
  sub_11312();
  goto loc_11174;
  //   gap of 82 bytes
loc_11364:
  ax = si;
  memoryASet16(ds, 0x003f, ax);
  if ((char)al > (char)0x13)
    goto loc_11393;
  memoryASet(ds, 0xca3a, 0x04);
  cx = 0x0014;
  cl -= al;
  cx <<= 1;
  cx <<= 1;
  cx <<= 1;
  push(cx);
  sub_109aa();
  cx = pop();
  bx = 0x0020;
  bx -= cx;
  sub_10ae8();
  sub_11312();
  ax = 0x0001;
  sub_10343();
loc_11393:
  sub_109aa();
  sub_11312();
  ax = 0x0002;
  sub_10343();
  ax = 0x0001;
  bx = 0xffffca5e;
  cx = 0x0004;
  ax = 0x000f;
  sub_10343();
  if (memoryAGet(ds, 0x0043) != 0x00)
    goto loc_113ba;
  goto loc_10ef4;
loc_113ba:
  sub_11c9a();
  memoryASet(ds, 0xca32, 0x00);
  memoryASet(ds, 0xca33, 0x00);
  memoryASet(ds, 0xca35, 0x00);
  memoryASet(ds, 0xca36, 0x00);
  memoryASet(ds, 0xca37, 0x00);
  memoryASet(ds, 0xca3a, 0x00);
  memoryASet(ds, 0xca3b, 0x06);
  memoryASet(ds, 0xca3d, 0x02);
  goto loc_107eb;
loc_113e8:
  memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) - 1);
  if (memoryAGet(ds, 0xca37) == 0)
    goto loc_113fd;
  if (memoryAGet(cs, 0x0388) != 0x01)
    goto loc_11401;
  memoryASet(ds, 0xca36, memoryAGet(ds, 0xca36) - 0x07);
  goto loc_11401;
loc_113fd:
  memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) + 1);
loc_11401:
  al = memoryAGet(ds, 0xca36);
  cl = al;
  al = sar(al, 1);
  al = sar(al, 1);
  al = sar(al, 1);
  bx = si;
  bl += al;
  if (stop(/*71*/))
    goto loc_11414;
  bl = 0x00;
loc_11414:
  si = bx;
  if (bl < 0x11)
    goto loc_1141e;
  goto loc_11364;
loc_1141e:
  if (memoryAGet(ds, 0x003d) != 0x02)
    goto loc_11428;
  cl -= 0x02;
loc_11428:
  cl += 0x05;
  if ((char)cl < (char)0x18)
    goto loc_11432;
  cl = 0x17;
loc_11432:
  memoryASet(ds, 0xca36, cl);
  cl = memoryAGet(ds, 0xca35);
  if (memoryAGet(cs, 0x039a) != 0x01)
    goto loc_11450;
  memoryASet(ds, 0xca39, 0x05);
  cl--;
  if ((char)cl >= (char)0xfb)
    goto loc_11450;
  cl = 0xfb;
loc_11450:
  if (memoryAGet(cs, 0x039c) != 0x01)
    goto loc_11466;
  memoryASet(ds, 0xca39, 0x00);
  cl++;
  if ((char)cl <= (char)0x05)
    goto loc_11466;
  cl = 0x05;
loc_11466:
  memoryASet(ds, 0xca35, cl);
  if ((char)cl >= 0)
    goto loc_11475;
  memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) + 1);
  sub_114f2();
loc_11475:
  al = memoryAGet(ds, 0xca35);
  if (stop(/*condition!*/))
    goto loc_11483;
  memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) - 1);
  sub_1154e();
loc_11483:
  ax = si;
  sub_108ad();
  dl = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)dl)
    goto loc_1149a;
  if (!(ah & 0x01))
    goto loc_1149f;
  if ((char)memoryAGet(ds, bx + 1) <= (char)dl)
    goto loc_1149f;
loc_1149a:
  memoryASet(ds, 0xca36, 0x08);
loc_1149f:
  if ((char)memoryAGet(ds, 0xca36) <= (char)0x00)
    goto loc_114c1;
  cx = si;
  ax = cx;
  al += 0x05;
  sub_108ad();
  dl = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)dl)
    goto loc_114c9;
  if (!(ah & 0x01))
    goto loc_114c1;
  if ((char)memoryAGet(ds, bx + 1) > (char)dl)
    goto loc_114c9;
loc_114c1:
  memoryASet(ds, 0xca3a, 0x04);
  goto loc_112c0;
loc_114c9:
  if (cl < 0x0f)
    goto loc_114d0;
  goto loc_114c1;
loc_114d0:
  cl++;
  cl &= 0xfe;
  si = cx;
  memoryASet(ds, 0xca33, 0x00);
  memoryASet(ds, 0xca36, 0x00);
  goto loc_112c0;
  //   gap of 14 bytes
loc_114f2:
  ax = si;
  if (ah)
    goto loc_1150a;
  di = memoryAGet16(ds, 0x5172);
  if (memoryAGet(ds, di + 3) == 0xff)
    goto loc_1153a;
  ah = 0xfe;
  bl = memoryAGet(ds, di + 3);
  goto loc_1159e;
loc_1150a:
  ah--;
  al += 0x03;
  sub_108ad();
  al -= 0x03;
  ch = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)ch)
    goto loc_1153a;
  si = ax;
  ch = memoryAGet(ds, 0xca32);
  memoryASet(ds, 0xca3a, ch);
  bx = memoryAGet16(ds, 0x0041);
  ah -= bl;
  if (!bx)
    goto loc_1153f;
  if (ah >= 0x0a)
    goto loc_1153f;
  memoryASet16(ds, 0x0041, memoryAGet16(ds, 0x0041) - 1);
  goto loc_1153f;
loc_1153a:
  memoryASet(ds, 0xca35, 0x00);
loc_1153f:
  return;
  //   gap of 94 bytes
loc_1159e:
  memoryASet16(ds, 0x6bd3, ax);
  memoryASet(ds, 0xca36, 0x00);
  memoryASet(ds, 0x003b, 0xff);
  memoryASet(ds, 0x003e, bl);
  ax = 0x0001;
  bx = 0xffffca3e;
  cx = 0x0004;
  goto loc_1078b;
loc_115bd:
  push(bx);
  ax = memoryAGet16(ds, bx);
  sub_10bfb();
  bx = pop();
  al = memoryAGet(ds, 0x003d);
  memoryASet(ds, 0x003b, al);
  al = memoryAGet(ds, 0x003e);
  memoryASet(ds, 0x003c, al);
  al = memoryAGet(ds, bx + 3);
  memoryASet(ds, 0x003e, al);
  al = memoryAGet(ds, bx + 2);
  memoryASet(ds, 0x003d, al);
  if (al == memoryAGet(ds, 0x003b))
    goto loc_115e5;
  goto loc_105e2;
loc_115e5:
  goto loc_1078b;
}
void sub_11540()
{
  goto loc_11540;
loc_10356:
  ax = 0x0002;
  sub_10595();
  ax = 0x0002;
  interrupt(0x10);
  bx = 0x21d;
  sub_1036d();
  ah = 0x4c;
  interrupt(0x21);
  //   gap of 629 bytes
loc_105e2:
  bx = 0x6bc3;
  al = memoryAGet(ds, 0x003d);
  ah = 0;
  ax <<= 1;
  bx += ax;
  si = memoryAGet16(ds, bx);
  di = 0x6af8;
  push(ds);
  es = pop();
  ax = 0x1ef8;
  ds = ax;
  cx = 0x00cb;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  push(es);
  ds = pop();
  dx = 0x6af8;
  ax = 0x3d00;
  interrupt(0x21);
  if (!flags.carry)
    goto loc_10611;
  goto loc_10627;
  //   gap of 1 bytes
loc_10611:
  bx = ax;
  dx = 0x260;
  cx = 0x4000;
  ax = 0x3f00;
  interrupt(0x21);
  ax = 0x3e00;
  interrupt(0x21);
  goto loc_1062a;
  //   gap of 1 bytes
loc_10627:
  goto loc_10356;
loc_1062a:
  if (memoryAGet(ds, 0x003d) != 0x06)
    goto loc_10645;
  if (memoryAGet(ds, 0x004a) == 0x01)
    goto loc_10645;
  push(ds);
  es = pop();
  ax = 0;
  di = 0x264;
  cx = 0x4000;
  rep_stosb<MemAuto, DirAuto>();
loc_10645:
  dx = 0x6b06;
  cx = 0x4266;
  sub_10669();
  dx = 0x6b14;
  cx = 0x476a;
  sub_10669();
  dx = 0x6b22;
  cx = 0x4c6e;
  sub_10669();
  goto loc_10685;
  //   gap of 29 bytes
loc_10685:
  si = 0x6b34;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x51a8;
  dx = 0x6aa8;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a4, al);
  sub_106f8();
  si = 0x6b45;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x57e8;
  dx = 0x6abc;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a5, al);
  sub_106f8();
  si = 0x6b56;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x5e28;
  dx = 0x6ad0;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a6, al);
  sub_106f8();
  si = 0x6b67;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x6468;
  dx = 0x6ae4;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a7, al);
  sub_106f8();
loc_106f5:
  goto loc_1078b;
  //   gap of 147 bytes
loc_1078b:
  al = memoryAGet(ds, 0x003e);
  dx = 0x426a;
  cx = 0x6b78;
  if (!al)
    goto loc_107ae;
  dx = 0x476e;
  cx = 0x6b91;
  al--;
  if (al == 0)
    goto loc_107ae;
  dx = 0x4c72;
  cx = 0x6baa;
loc_107ae:
  memoryASet16(ds, 0x4264, dx);
  memoryASet16(ds, 0x5172, cx);
  sub_10944();
  if ((char)memoryAGet(ds, 0x003b) < (char)0x00)
    goto loc_107eb;
  si = memoryAGet16(ds, 0x5172);
  si = si + 0x5; /*chk4*/
  al = memoryAGet(ds, 0x003b);
  ah = memoryAGet(ds, 0x003c);
  cx = 0x0003;
loc_107d1:
  if (al != memoryAGet(ds, si + 2))
    goto loc_107db;
  if (ah == memoryAGet(ds, si + 3))
    goto loc_107e3;
loc_107db:
  si += 0x0004;
  if (--cx)
    goto loc_107d1;
  goto loc_10356;
loc_107e3:
  ax = memoryAGet16(ds, si);
  ah += 0x01;
  memoryASet16(ds, 0x6bd3, ax);
loc_107eb:
  memoryASet(ds, 0xca34, 0x00);
  cx = 0x0005;
  bx = 0xffffca90;
  ax = 0xffff;
loc_107fa:
  memoryASet16(ds, bx, ax);
  bx += 0x0006;
  if (--cx)
    goto loc_107fa;
  ax = memoryAGet16(ds, 0x6bd3);
  memoryASet16(ds, 0x003f, ax);
  al = ah;
  ah = 0;
  flags.carry = ax < 0x000b;
  ax -= 0x000b;
  if (!flags.carry)
    goto loc_10812;
  ax = 0;
loc_10812:
  if (ax < 0x00e8)
    goto loc_1081a;
  ax = 0x00e8;
loc_1081a:
  memoryASet16(ds, 0x0041, ax);
  si = memoryAGet16(ds, 0x5172);
  si = si + 0x11; /*chk4*/
  di = 0x5174;
  cx = 0x0004;
loc_1082b:
  al = memoryAGet(ds, si);
  if (al != 0xff)
    goto loc_10837;
  memoryASet(ds, di + 11, 0xff);
  goto loc_10881;
loc_10837:
  push(cx);
  ah = 0;
  cx = ax;
  bx = 0x51a4;
  bx += ax;
  bl = memoryAGet(ds, bx);
  memoryASet(ds, di + 5, bl);
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  cx <<= 1;
  cx <<= 1;
  ax += cx;
  dx = 0x6aa8;
  dx += ax;
  memoryASet16(ds, di + 7, dx);
  al = memoryAGet(ds, si + 1);
  memoryASet(ds, di + 6, al);
  memoryASet(ds, di + 9, 0x00);
  memoryASet(ds, di + 10, 0x00);
  memoryASet(ds, di + 4, 0x14);
  memoryASet(ds, di + 11, 0x00);
  if (al < 0x80)
    goto loc_10880;
  memoryASet(ds, di + 6, memoryAGet(ds, di + 6) - 0x80);
  memoryASet(ds, di + 11, 0x02);
loc_10880:
  cx = pop();
loc_10881:
  di += 0x000c;
  si += 0x0002;
  if (--cx)
    goto loc_1082b;
  if (memoryAGet(ds, 0x003b) == 0xfe)
    goto loc_108a2;
  if (memoryAGet(ds, 0x003b) == 0xff)
    goto loc_1089f;
  sub_10b7e();
  memoryASet(ds, 0x003b, 0xff);
loc_1089f:
  goto loc_11174;
loc_108a2:
  sub_110f2();
  memoryASet(ds, 0x003b, 0xff);
  goto loc_11174;
  //   gap of 1607 bytes
loc_10ef4:
  sub_109aa();
  memoryASet16(ds, 0xc8fa, 0x0010);
  memoryASet16(ds, 0xc8fc, 0x0030);
  si = 0xffffbce4;
  di = memoryAGet16(ds, 0xca30);
  di += 0x0a05;
  sub_10f38();
  sub_10d28();
  bx = 0xffffc9e5;
  ax = 0x0001;
  cx = 0x0002;
loc_10f20:
  cx = 0;
  es = cx;
  cl = memoryAGet(es, 0x041a);
  memoryASet(es, 0x041c, cl);
  ax = 0;
  interrupt(0x16);
  sub_120b0();
  goto loc_10356;
  //   gap of 59 bytes
loc_10f73:
  sub_1108d();
  cx = 0x0014;
loc_10f79:
  push(cx);
  bx = 0xffffc979;
  ax = 0x0001;
  cx = 0x0003;
  al = 0x0a;
  sub_11e6b();
  ax = 0x0001;
  sub_10343();
  cx = pop();
  if (--cx)
    goto loc_10f79;
loc_10f93:
  if (memoryAGet(ds, 0x0043) == 0x00)
    goto loc_10fc2;
  cx = 0x000a;
loc_10f9d:
  push(cx);
  bx = 0xffffc979;
  ax = 0x0001;
  cx = 0x0003;
  al = 0x0a;
  sub_11e6b();
  ax = 0x0001;
  sub_10343();
  cx = pop();
  if (--cx)
    goto loc_10f9d;
  sub_11c9a();
  ax = 0x0003;
  sub_10343();
  goto loc_10f93;
loc_10fc2:
  bx = 0x81;
  ax = 0x0001;
  cx = 0x0004;
  dx = 0xffffc8fe;
  ax = 0x3d00;
  interrupt(0x21);
  if (!flags.carry)
    goto loc_10fdb;
  goto loc_10356;
loc_10fdb:
  bp = ax;
  push(ds);
  ax = ds;
  es = ax;
  ax = 0xa000;
  ds = ax;
  ah = 0x01;
  bx = 0;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x02;
  bx = 0x0001;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x04;
  bx = 0x0002;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x08;
  bx = 0x0003;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ax = 0x3e00;
  interrupt(0x21);
  ds = pop();
  sub_102a3();
  sub_11312();
  sub_102bc();
  ax = 0x0014;
  sub_10343();
  ax = 0;
  es = ax;
  cl = memoryAGet(es, 0x041a);
  memoryASet(es, 0x041c, cl);
  ax = 0;
  interrupt(0x16);
  sub_109aa();
  memoryASet16(ds, 0xc8fa, 0x0010);
  memoryASet16(ds, 0xc8fc, 0x0030);
  si = 0xffffbce4;
  di = memoryAGet16(ds, 0xca30);
  di += 0x0a05;
  sub_10f38();
  sub_11312();
  goto loc_10f20;
  //   gap of 231 bytes
loc_11174:
  cx = 0;
  es = cx;
  cl = memoryAGet(es, 0x041a);
  memoryASet(es, 0x041c, cl);
  if (memoryAGet(cs, 0x03ea) == 0x01)
    goto loc_111a1;
  if (memoryAGet(ds, 0xca33) == 0x01)
    goto loc_11174;
  if (memoryAGet(cs, 0x0388) == 0x01)
    goto loc_11174;
  al = memoryAGet(ds, 0x0047);
  memoryASet(ds, 0xca37, al);
  goto loc_11174;
loc_111a1:
  memoryASet(cs, 0x03ea, 0x00);
  if (memoryAGet(ds, 0xca3c) == 0x00)
    goto loc_111bc;
  memoryASet(ds, 0xca3c, memoryAGet(ds, 0xca3c) - 1);
  if (memoryAGet(ds, 0xca3c) != 0x01)
    goto loc_111bc;
  goto loc_10f73;
loc_111bc:
  ch = memoryAGet(ds, 0xca32);
  ch++;
  if (ch != 0x04)
    goto loc_111c9;
  ch = 0x01;
loc_111c9:
  memoryASet(ds, 0xca32, ch);
  memoryASet(ds, 0xca3a, 0x00);
  if (memoryAGet(ds, 0xca3b) == 0x00)
    goto loc_111e0;
  memoryASet(ds, 0xca3b, memoryAGet(ds, 0xca3b) - 1);
  sub_11cff();
loc_111e0:
  if (memoryAGet(ds, 0xca34) == 0x00)
    goto loc_111ed;
  sub_10e32();
  goto loc_11303;
loc_111ed:
  si = memoryAGet16(ds, 0x003f);
  if (memoryAGet(ds, 0xca33) == 0x00)
    goto loc_111fb;
  goto loc_113e8;
loc_111fb:
  if (memoryAGet(cs, 0x0388) != 0x01)
    goto loc_11212;
  if (memoryAGet(ds, 0xca37) == 0x01)
    goto loc_11218;
  memoryASet(ds, 0xca33, 0x01);
  goto loc_113e8;
loc_11212:
  al = memoryAGet(ds, 0x0047);
  memoryASet(ds, 0xca37, al);
loc_11218:
  if (memoryAGet(cs, 0x0387) != 0x01)
    goto loc_1124a;
  di = memoryAGet16(ds, 0x5172);
  bx = di + 0x5; /*chk4*/
  cx = 0x0003;
  ax = si;
loc_1122c:
  dx = memoryAGet16(ds, bx);
  if (al != dl)
    goto loc_11245;
  dh = -dh;
  dh += ah;
  if (dh >= 0x03)
    goto loc_11245;
  if (memoryAGet(ds, 0x0049) != 0x01)
    goto loc_11245;
  goto loc_115bd;
loc_11245:
  bx += 0x0004;
  if (--cx)
    goto loc_1122c;
loc_1124a:
  if (memoryAGet(cs, 0x0389) != 0x01)
    goto loc_1125e;
  if (memoryAGet(ds, 0x004b) != 0x01)
    goto loc_1125e;
  sub_10d82();
  goto loc_111e0;
loc_1125e:
  memoryASet(ds, 0xca35, 0x00);
  if (memoryAGet(cs, 0x039a) != 0x01)
    goto loc_11273;
  memoryASet(ds, 0xca35, 0xfb);
  sub_114e4();
loc_11273:
  if (memoryAGet(cs, 0x039c) != 0x01)
    goto loc_11283;
  memoryASet(ds, 0xca35, 0x05);
  sub_11540();
loc_11283:
  ax = si;
  al += 0x04;
  sub_108ad();
  cl = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)cl)
    goto loc_112c0;
  if (!(ah & 0x01))
    goto loc_1129c;
  if ((char)memoryAGet(ds, bx + 1) > (char)cl)
    goto loc_112c0;
loc_1129c:
  memoryASet(ds, 0xca36, 0x08);
  if ((char)memoryAGet(ds, 0xca35) < (char)0x00)
    goto loc_112b1;
  if (memoryAGet(ds, 0xca35) == 0x00)
    goto loc_112b6;
  memoryASet(ds, 0xca35, 0x02);
  goto loc_112b6;
loc_112b1:
  memoryASet(ds, 0xca35, 0xfe);
loc_112b6:
  memoryASet(ds, 0xca33, 0x01);
  memoryASet(ds, 0xca37, 0x01);
loc_112c0:
  memoryASet16(ds, 0x003f, si);
  if (memoryAGet(cs, 0x0386) != 0x01)
    goto loc_112cf;
  sub_10eb5();
loc_112cf:
  if (memoryAGet(cs, 0x03a1) != 0x01)
    goto loc_112ef;
  if (memoryAGet(ds, 0x0046) == 0x00)
    goto loc_112fd;
  ax = si;
  al++;
  sub_11b2c();
  if (memoryAGet(ds, 0xca3d) == 0x01)
    goto loc_112f8;
  sub_11d7d();
loc_112ef:
  memoryASet(ds, 0xca3d, memoryAGet(ds, 0xca3d) - 1);
  if (memoryAGet(ds, 0xca3d) != 0)
    goto loc_112fd;
  sub_11d4e();
loc_112f8:
  memoryASet(ds, 0xca3d, 0x02);
loc_112fd:
  sub_109aa();
  sub_109dc();
loc_11303:
  sub_115e8();
  sub_11b65();
  sub_11327();
  sub_11312();
  goto loc_11174;
  //   gap of 82 bytes
loc_11364:
  ax = si;
  memoryASet16(ds, 0x003f, ax);
  if ((char)al > (char)0x13)
    goto loc_11393;
  memoryASet(ds, 0xca3a, 0x04);
  cx = 0x0014;
  cl -= al;
  cx <<= 1;
  cx <<= 1;
  cx <<= 1;
  push(cx);
  sub_109aa();
  cx = pop();
  bx = 0x0020;
  bx -= cx;
  sub_10ae8();
  sub_11312();
  ax = 0x0001;
  sub_10343();
loc_11393:
  sub_109aa();
  sub_11312();
  ax = 0x0002;
  sub_10343();
  ax = 0x0001;
  bx = 0xffffca5e;
  cx = 0x0004;
  ax = 0x000f;
  sub_10343();
  if (memoryAGet(ds, 0x0043) != 0x00)
    goto loc_113ba;
  goto loc_10ef4;
loc_113ba:
  sub_11c9a();
  memoryASet(ds, 0xca32, 0x00);
  memoryASet(ds, 0xca33, 0x00);
  memoryASet(ds, 0xca35, 0x00);
  memoryASet(ds, 0xca36, 0x00);
  memoryASet(ds, 0xca37, 0x00);
  memoryASet(ds, 0xca3a, 0x00);
  memoryASet(ds, 0xca3b, 0x06);
  memoryASet(ds, 0xca3d, 0x02);
  goto loc_107eb;
loc_113e8:
  memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) - 1);
  if (memoryAGet(ds, 0xca37) == 0)
    goto loc_113fd;
  if (memoryAGet(cs, 0x0388) != 0x01)
    goto loc_11401;
  memoryASet(ds, 0xca36, memoryAGet(ds, 0xca36) - 0x07);
  goto loc_11401;
loc_113fd:
  memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) + 1);
loc_11401:
  al = memoryAGet(ds, 0xca36);
  cl = al;
  al = sar(al, 1);
  al = sar(al, 1);
  al = sar(al, 1);
  bx = si;
  bl += al;
  if (stop(/*71*/))
    goto loc_11414;
  bl = 0x00;
loc_11414:
  si = bx;
  if (bl < 0x11)
    goto loc_1141e;
  goto loc_11364;
loc_1141e:
  if (memoryAGet(ds, 0x003d) != 0x02)
    goto loc_11428;
  cl -= 0x02;
loc_11428:
  cl += 0x05;
  if ((char)cl < (char)0x18)
    goto loc_11432;
  cl = 0x17;
loc_11432:
  memoryASet(ds, 0xca36, cl);
  cl = memoryAGet(ds, 0xca35);
  if (memoryAGet(cs, 0x039a) != 0x01)
    goto loc_11450;
  memoryASet(ds, 0xca39, 0x05);
  cl--;
  if ((char)cl >= (char)0xfb)
    goto loc_11450;
  cl = 0xfb;
loc_11450:
  if (memoryAGet(cs, 0x039c) != 0x01)
    goto loc_11466;
  memoryASet(ds, 0xca39, 0x00);
  cl++;
  if ((char)cl <= (char)0x05)
    goto loc_11466;
  cl = 0x05;
loc_11466:
  memoryASet(ds, 0xca35, cl);
  if ((char)cl >= 0)
    goto loc_11475;
  memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) + 1);
  sub_114f2();
loc_11475:
  al = memoryAGet(ds, 0xca35);
  if (stop(/*condition!*/))
    goto loc_11483;
  memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) - 1);
  sub_1154e();
loc_11483:
  ax = si;
  sub_108ad();
  dl = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)dl)
    goto loc_1149a;
  if (!(ah & 0x01))
    goto loc_1149f;
  if ((char)memoryAGet(ds, bx + 1) <= (char)dl)
    goto loc_1149f;
loc_1149a:
  memoryASet(ds, 0xca36, 0x08);
loc_1149f:
  if ((char)memoryAGet(ds, 0xca36) <= (char)0x00)
    goto loc_114c1;
  cx = si;
  ax = cx;
  al += 0x05;
  sub_108ad();
  dl = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)dl)
    goto loc_114c9;
  if (!(ah & 0x01))
    goto loc_114c1;
  if ((char)memoryAGet(ds, bx + 1) > (char)dl)
    goto loc_114c9;
loc_114c1:
  memoryASet(ds, 0xca3a, 0x04);
  goto loc_112c0;
loc_114c9:
  if (cl < 0x0f)
    goto loc_114d0;
  goto loc_114c1;
loc_114d0:
  cl++;
  cl &= 0xfe;
  si = cx;
  memoryASet(ds, 0xca33, 0x00);
  memoryASet(ds, 0xca36, 0x00);
  goto loc_112c0;
  //   gap of 86 bytes
loc_1153a:
  memoryASet(ds, 0xca35, 0x00);
loc_1153f:
  return;
loc_11540:
  if (memoryAGet(ds, 0xca39) == 0x00)
    goto loc_1154e;
  memoryASet(ds, 0xca39, 0x00);
  goto loc_1153f;
loc_1154e:
  ax = si;
  if (ah != 0xfe)
    goto loc_11567;
  di = memoryAGet16(ds, 0x5172);
  if (memoryAGet(ds, di + 4) == 0xff)
    goto loc_1153a;
  ah = 0;
  bl = memoryAGet(ds, di + 4);
  goto loc_1159e;
  //   gap of 1 bytes
loc_11567:
  if (stop(/*1*/))
    goto loc_1153a;
  ah += 0x02;
  al += 0x03;
  sub_108ad();
  al -= 0x03;
  ah--;
  ch = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)ch)
    goto loc_1153a;
  si = ax;
  ch = memoryAGet(ds, 0xca32);
  memoryASet(ds, 0xca3a, ch);
  bx = memoryAGet16(ds, 0x0041);
  ah -= bl;
  if ((short)bx >= (short)0x00e8)
    goto loc_1153f;
  if ((char)ah <= (char)0x0c)
    goto loc_1153f;
  memoryASet16(ds, 0x0041, memoryAGet16(ds, 0x0041) + 1);
  goto loc_1153f;
loc_1159e:
  memoryASet16(ds, 0x6bd3, ax);
  memoryASet(ds, 0xca36, 0x00);
  memoryASet(ds, 0x003b, 0xff);
  memoryASet(ds, 0x003e, bl);
  ax = 0x0001;
  bx = 0xffffca3e;
  cx = 0x0004;
  goto loc_1078b;
loc_115bd:
  push(bx);
  ax = memoryAGet16(ds, bx);
  sub_10bfb();
  bx = pop();
  al = memoryAGet(ds, 0x003d);
  memoryASet(ds, 0x003b, al);
  al = memoryAGet(ds, 0x003e);
  memoryASet(ds, 0x003c, al);
  al = memoryAGet(ds, bx + 3);
  memoryASet(ds, 0x003e, al);
  al = memoryAGet(ds, bx + 2);
  memoryASet(ds, 0x003d, al);
  if (al == memoryAGet(ds, 0x003b))
    goto loc_115e5;
  goto loc_105e2;
loc_115e5:
  goto loc_1078b;
}
void sub_1154e()
{
  goto loc_1154e;
loc_10356:
  ax = 0x0002;
  sub_10595();
  ax = 0x0002;
  interrupt(0x10);
  bx = 0x21d;
  sub_1036d();
  ah = 0x4c;
  interrupt(0x21);
  //   gap of 629 bytes
loc_105e2:
  bx = 0x6bc3;
  al = memoryAGet(ds, 0x003d);
  ah = 0;
  ax <<= 1;
  bx += ax;
  si = memoryAGet16(ds, bx);
  di = 0x6af8;
  push(ds);
  es = pop();
  ax = 0x1ef8;
  ds = ax;
  cx = 0x00cb;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  push(es);
  ds = pop();
  dx = 0x6af8;
  ax = 0x3d00;
  interrupt(0x21);
  if (!flags.carry)
    goto loc_10611;
  goto loc_10627;
  //   gap of 1 bytes
loc_10611:
  bx = ax;
  dx = 0x260;
  cx = 0x4000;
  ax = 0x3f00;
  interrupt(0x21);
  ax = 0x3e00;
  interrupt(0x21);
  goto loc_1062a;
  //   gap of 1 bytes
loc_10627:
  goto loc_10356;
loc_1062a:
  if (memoryAGet(ds, 0x003d) != 0x06)
    goto loc_10645;
  if (memoryAGet(ds, 0x004a) == 0x01)
    goto loc_10645;
  push(ds);
  es = pop();
  ax = 0;
  di = 0x264;
  cx = 0x4000;
  rep_stosb<MemAuto, DirAuto>();
loc_10645:
  dx = 0x6b06;
  cx = 0x4266;
  sub_10669();
  dx = 0x6b14;
  cx = 0x476a;
  sub_10669();
  dx = 0x6b22;
  cx = 0x4c6e;
  sub_10669();
  goto loc_10685;
  //   gap of 29 bytes
loc_10685:
  si = 0x6b34;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x51a8;
  dx = 0x6aa8;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a4, al);
  sub_106f8();
  si = 0x6b45;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x57e8;
  dx = 0x6abc;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a5, al);
  sub_106f8();
  si = 0x6b56;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x5e28;
  dx = 0x6ad0;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a6, al);
  sub_106f8();
  si = 0x6b67;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x6468;
  dx = 0x6ae4;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a7, al);
  sub_106f8();
loc_106f5:
  goto loc_1078b;
  //   gap of 147 bytes
loc_1078b:
  al = memoryAGet(ds, 0x003e);
  dx = 0x426a;
  cx = 0x6b78;
  if (!al)
    goto loc_107ae;
  dx = 0x476e;
  cx = 0x6b91;
  al--;
  if (al == 0)
    goto loc_107ae;
  dx = 0x4c72;
  cx = 0x6baa;
loc_107ae:
  memoryASet16(ds, 0x4264, dx);
  memoryASet16(ds, 0x5172, cx);
  sub_10944();
  if ((char)memoryAGet(ds, 0x003b) < (char)0x00)
    goto loc_107eb;
  si = memoryAGet16(ds, 0x5172);
  si = si + 0x5; /*chk4*/
  al = memoryAGet(ds, 0x003b);
  ah = memoryAGet(ds, 0x003c);
  cx = 0x0003;
loc_107d1:
  if (al != memoryAGet(ds, si + 2))
    goto loc_107db;
  if (ah == memoryAGet(ds, si + 3))
    goto loc_107e3;
loc_107db:
  si += 0x0004;
  if (--cx)
    goto loc_107d1;
  goto loc_10356;
loc_107e3:
  ax = memoryAGet16(ds, si);
  ah += 0x01;
  memoryASet16(ds, 0x6bd3, ax);
loc_107eb:
  memoryASet(ds, 0xca34, 0x00);
  cx = 0x0005;
  bx = 0xffffca90;
  ax = 0xffff;
loc_107fa:
  memoryASet16(ds, bx, ax);
  bx += 0x0006;
  if (--cx)
    goto loc_107fa;
  ax = memoryAGet16(ds, 0x6bd3);
  memoryASet16(ds, 0x003f, ax);
  al = ah;
  ah = 0;
  flags.carry = ax < 0x000b;
  ax -= 0x000b;
  if (!flags.carry)
    goto loc_10812;
  ax = 0;
loc_10812:
  if (ax < 0x00e8)
    goto loc_1081a;
  ax = 0x00e8;
loc_1081a:
  memoryASet16(ds, 0x0041, ax);
  si = memoryAGet16(ds, 0x5172);
  si = si + 0x11; /*chk4*/
  di = 0x5174;
  cx = 0x0004;
loc_1082b:
  al = memoryAGet(ds, si);
  if (al != 0xff)
    goto loc_10837;
  memoryASet(ds, di + 11, 0xff);
  goto loc_10881;
loc_10837:
  push(cx);
  ah = 0;
  cx = ax;
  bx = 0x51a4;
  bx += ax;
  bl = memoryAGet(ds, bx);
  memoryASet(ds, di + 5, bl);
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  cx <<= 1;
  cx <<= 1;
  ax += cx;
  dx = 0x6aa8;
  dx += ax;
  memoryASet16(ds, di + 7, dx);
  al = memoryAGet(ds, si + 1);
  memoryASet(ds, di + 6, al);
  memoryASet(ds, di + 9, 0x00);
  memoryASet(ds, di + 10, 0x00);
  memoryASet(ds, di + 4, 0x14);
  memoryASet(ds, di + 11, 0x00);
  if (al < 0x80)
    goto loc_10880;
  memoryASet(ds, di + 6, memoryAGet(ds, di + 6) - 0x80);
  memoryASet(ds, di + 11, 0x02);
loc_10880:
  cx = pop();
loc_10881:
  di += 0x000c;
  si += 0x0002;
  if (--cx)
    goto loc_1082b;
  if (memoryAGet(ds, 0x003b) == 0xfe)
    goto loc_108a2;
  if (memoryAGet(ds, 0x003b) == 0xff)
    goto loc_1089f;
  sub_10b7e();
  memoryASet(ds, 0x003b, 0xff);
loc_1089f:
  goto loc_11174;
loc_108a2:
  sub_110f2();
  memoryASet(ds, 0x003b, 0xff);
  goto loc_11174;
  //   gap of 1607 bytes
loc_10ef4:
  sub_109aa();
  memoryASet16(ds, 0xc8fa, 0x0010);
  memoryASet16(ds, 0xc8fc, 0x0030);
  si = 0xffffbce4;
  di = memoryAGet16(ds, 0xca30);
  di += 0x0a05;
  sub_10f38();
  sub_10d28();
  bx = 0xffffc9e5;
  ax = 0x0001;
  cx = 0x0002;
loc_10f20:
  cx = 0;
  es = cx;
  cl = memoryAGet(es, 0x041a);
  memoryASet(es, 0x041c, cl);
  ax = 0;
  interrupt(0x16);
  sub_120b0();
  goto loc_10356;
  //   gap of 59 bytes
loc_10f73:
  sub_1108d();
  cx = 0x0014;
loc_10f79:
  push(cx);
  bx = 0xffffc979;
  ax = 0x0001;
  cx = 0x0003;
  al = 0x0a;
  sub_11e6b();
  ax = 0x0001;
  sub_10343();
  cx = pop();
  if (--cx)
    goto loc_10f79;
loc_10f93:
  if (memoryAGet(ds, 0x0043) == 0x00)
    goto loc_10fc2;
  cx = 0x000a;
loc_10f9d:
  push(cx);
  bx = 0xffffc979;
  ax = 0x0001;
  cx = 0x0003;
  al = 0x0a;
  sub_11e6b();
  ax = 0x0001;
  sub_10343();
  cx = pop();
  if (--cx)
    goto loc_10f9d;
  sub_11c9a();
  ax = 0x0003;
  sub_10343();
  goto loc_10f93;
loc_10fc2:
  bx = 0x81;
  ax = 0x0001;
  cx = 0x0004;
  dx = 0xffffc8fe;
  ax = 0x3d00;
  interrupt(0x21);
  if (!flags.carry)
    goto loc_10fdb;
  goto loc_10356;
loc_10fdb:
  bp = ax;
  push(ds);
  ax = ds;
  es = ax;
  ax = 0xa000;
  ds = ax;
  ah = 0x01;
  bx = 0;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x02;
  bx = 0x0001;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x04;
  bx = 0x0002;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x08;
  bx = 0x0003;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ax = 0x3e00;
  interrupt(0x21);
  ds = pop();
  sub_102a3();
  sub_11312();
  sub_102bc();
  ax = 0x0014;
  sub_10343();
  ax = 0;
  es = ax;
  cl = memoryAGet(es, 0x041a);
  memoryASet(es, 0x041c, cl);
  ax = 0;
  interrupt(0x16);
  sub_109aa();
  memoryASet16(ds, 0xc8fa, 0x0010);
  memoryASet16(ds, 0xc8fc, 0x0030);
  si = 0xffffbce4;
  di = memoryAGet16(ds, 0xca30);
  di += 0x0a05;
  sub_10f38();
  sub_11312();
  goto loc_10f20;
  //   gap of 231 bytes
loc_11174:
  cx = 0;
  es = cx;
  cl = memoryAGet(es, 0x041a);
  memoryASet(es, 0x041c, cl);
  if (memoryAGet(cs, 0x03ea) == 0x01)
    goto loc_111a1;
  if (memoryAGet(ds, 0xca33) == 0x01)
    goto loc_11174;
  if (memoryAGet(cs, 0x0388) == 0x01)
    goto loc_11174;
  al = memoryAGet(ds, 0x0047);
  memoryASet(ds, 0xca37, al);
  goto loc_11174;
loc_111a1:
  memoryASet(cs, 0x03ea, 0x00);
  if (memoryAGet(ds, 0xca3c) == 0x00)
    goto loc_111bc;
  memoryASet(ds, 0xca3c, memoryAGet(ds, 0xca3c) - 1);
  if (memoryAGet(ds, 0xca3c) != 0x01)
    goto loc_111bc;
  goto loc_10f73;
loc_111bc:
  ch = memoryAGet(ds, 0xca32);
  ch++;
  if (ch != 0x04)
    goto loc_111c9;
  ch = 0x01;
loc_111c9:
  memoryASet(ds, 0xca32, ch);
  memoryASet(ds, 0xca3a, 0x00);
  if (memoryAGet(ds, 0xca3b) == 0x00)
    goto loc_111e0;
  memoryASet(ds, 0xca3b, memoryAGet(ds, 0xca3b) - 1);
  sub_11cff();
loc_111e0:
  if (memoryAGet(ds, 0xca34) == 0x00)
    goto loc_111ed;
  sub_10e32();
  goto loc_11303;
loc_111ed:
  si = memoryAGet16(ds, 0x003f);
  if (memoryAGet(ds, 0xca33) == 0x00)
    goto loc_111fb;
  goto loc_113e8;
loc_111fb:
  if (memoryAGet(cs, 0x0388) != 0x01)
    goto loc_11212;
  if (memoryAGet(ds, 0xca37) == 0x01)
    goto loc_11218;
  memoryASet(ds, 0xca33, 0x01);
  goto loc_113e8;
loc_11212:
  al = memoryAGet(ds, 0x0047);
  memoryASet(ds, 0xca37, al);
loc_11218:
  if (memoryAGet(cs, 0x0387) != 0x01)
    goto loc_1124a;
  di = memoryAGet16(ds, 0x5172);
  bx = di + 0x5; /*chk4*/
  cx = 0x0003;
  ax = si;
loc_1122c:
  dx = memoryAGet16(ds, bx);
  if (al != dl)
    goto loc_11245;
  dh = -dh;
  dh += ah;
  if (dh >= 0x03)
    goto loc_11245;
  if (memoryAGet(ds, 0x0049) != 0x01)
    goto loc_11245;
  goto loc_115bd;
loc_11245:
  bx += 0x0004;
  if (--cx)
    goto loc_1122c;
loc_1124a:
  if (memoryAGet(cs, 0x0389) != 0x01)
    goto loc_1125e;
  if (memoryAGet(ds, 0x004b) != 0x01)
    goto loc_1125e;
  sub_10d82();
  goto loc_111e0;
loc_1125e:
  memoryASet(ds, 0xca35, 0x00);
  if (memoryAGet(cs, 0x039a) != 0x01)
    goto loc_11273;
  memoryASet(ds, 0xca35, 0xfb);
  sub_114e4();
loc_11273:
  if (memoryAGet(cs, 0x039c) != 0x01)
    goto loc_11283;
  memoryASet(ds, 0xca35, 0x05);
  sub_11540();
loc_11283:
  ax = si;
  al += 0x04;
  sub_108ad();
  cl = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)cl)
    goto loc_112c0;
  if (!(ah & 0x01))
    goto loc_1129c;
  if ((char)memoryAGet(ds, bx + 1) > (char)cl)
    goto loc_112c0;
loc_1129c:
  memoryASet(ds, 0xca36, 0x08);
  if ((char)memoryAGet(ds, 0xca35) < (char)0x00)
    goto loc_112b1;
  if (memoryAGet(ds, 0xca35) == 0x00)
    goto loc_112b6;
  memoryASet(ds, 0xca35, 0x02);
  goto loc_112b6;
loc_112b1:
  memoryASet(ds, 0xca35, 0xfe);
loc_112b6:
  memoryASet(ds, 0xca33, 0x01);
  memoryASet(ds, 0xca37, 0x01);
loc_112c0:
  memoryASet16(ds, 0x003f, si);
  if (memoryAGet(cs, 0x0386) != 0x01)
    goto loc_112cf;
  sub_10eb5();
loc_112cf:
  if (memoryAGet(cs, 0x03a1) != 0x01)
    goto loc_112ef;
  if (memoryAGet(ds, 0x0046) == 0x00)
    goto loc_112fd;
  ax = si;
  al++;
  sub_11b2c();
  if (memoryAGet(ds, 0xca3d) == 0x01)
    goto loc_112f8;
  sub_11d7d();
loc_112ef:
  memoryASet(ds, 0xca3d, memoryAGet(ds, 0xca3d) - 1);
  if (memoryAGet(ds, 0xca3d) != 0)
    goto loc_112fd;
  sub_11d4e();
loc_112f8:
  memoryASet(ds, 0xca3d, 0x02);
loc_112fd:
  sub_109aa();
  sub_109dc();
loc_11303:
  sub_115e8();
  sub_11b65();
  sub_11327();
  sub_11312();
  goto loc_11174;
  //   gap of 82 bytes
loc_11364:
  ax = si;
  memoryASet16(ds, 0x003f, ax);
  if ((char)al > (char)0x13)
    goto loc_11393;
  memoryASet(ds, 0xca3a, 0x04);
  cx = 0x0014;
  cl -= al;
  cx <<= 1;
  cx <<= 1;
  cx <<= 1;
  push(cx);
  sub_109aa();
  cx = pop();
  bx = 0x0020;
  bx -= cx;
  sub_10ae8();
  sub_11312();
  ax = 0x0001;
  sub_10343();
loc_11393:
  sub_109aa();
  sub_11312();
  ax = 0x0002;
  sub_10343();
  ax = 0x0001;
  bx = 0xffffca5e;
  cx = 0x0004;
  ax = 0x000f;
  sub_10343();
  if (memoryAGet(ds, 0x0043) != 0x00)
    goto loc_113ba;
  goto loc_10ef4;
loc_113ba:
  sub_11c9a();
  memoryASet(ds, 0xca32, 0x00);
  memoryASet(ds, 0xca33, 0x00);
  memoryASet(ds, 0xca35, 0x00);
  memoryASet(ds, 0xca36, 0x00);
  memoryASet(ds, 0xca37, 0x00);
  memoryASet(ds, 0xca3a, 0x00);
  memoryASet(ds, 0xca3b, 0x06);
  memoryASet(ds, 0xca3d, 0x02);
  goto loc_107eb;
loc_113e8:
  memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) - 1);
  if (memoryAGet(ds, 0xca37) == 0)
    goto loc_113fd;
  if (memoryAGet(cs, 0x0388) != 0x01)
    goto loc_11401;
  memoryASet(ds, 0xca36, memoryAGet(ds, 0xca36) - 0x07);
  goto loc_11401;
loc_113fd:
  memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) + 1);
loc_11401:
  al = memoryAGet(ds, 0xca36);
  cl = al;
  al = sar(al, 1);
  al = sar(al, 1);
  al = sar(al, 1);
  bx = si;
  bl += al;
  if (stop(/*71*/))
    goto loc_11414;
  bl = 0x00;
loc_11414:
  si = bx;
  if (bl < 0x11)
    goto loc_1141e;
  goto loc_11364;
loc_1141e:
  if (memoryAGet(ds, 0x003d) != 0x02)
    goto loc_11428;
  cl -= 0x02;
loc_11428:
  cl += 0x05;
  if ((char)cl < (char)0x18)
    goto loc_11432;
  cl = 0x17;
loc_11432:
  memoryASet(ds, 0xca36, cl);
  cl = memoryAGet(ds, 0xca35);
  if (memoryAGet(cs, 0x039a) != 0x01)
    goto loc_11450;
  memoryASet(ds, 0xca39, 0x05);
  cl--;
  if ((char)cl >= (char)0xfb)
    goto loc_11450;
  cl = 0xfb;
loc_11450:
  if (memoryAGet(cs, 0x039c) != 0x01)
    goto loc_11466;
  memoryASet(ds, 0xca39, 0x00);
  cl++;
  if ((char)cl <= (char)0x05)
    goto loc_11466;
  cl = 0x05;
loc_11466:
  memoryASet(ds, 0xca35, cl);
  if ((char)cl >= 0)
    goto loc_11475;
  memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) + 1);
  sub_114f2();
loc_11475:
  al = memoryAGet(ds, 0xca35);
  if (stop(/*condition!*/))
    goto loc_11483;
  memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) - 1);
  sub_1154e();
loc_11483:
  ax = si;
  sub_108ad();
  dl = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)dl)
    goto loc_1149a;
  if (!(ah & 0x01))
    goto loc_1149f;
  if ((char)memoryAGet(ds, bx + 1) <= (char)dl)
    goto loc_1149f;
loc_1149a:
  memoryASet(ds, 0xca36, 0x08);
loc_1149f:
  if ((char)memoryAGet(ds, 0xca36) <= (char)0x00)
    goto loc_114c1;
  cx = si;
  ax = cx;
  al += 0x05;
  sub_108ad();
  dl = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)dl)
    goto loc_114c9;
  if (!(ah & 0x01))
    goto loc_114c1;
  if ((char)memoryAGet(ds, bx + 1) > (char)dl)
    goto loc_114c9;
loc_114c1:
  memoryASet(ds, 0xca3a, 0x04);
  goto loc_112c0;
loc_114c9:
  if (cl < 0x0f)
    goto loc_114d0;
  goto loc_114c1;
loc_114d0:
  cl++;
  cl &= 0xfe;
  si = cx;
  memoryASet(ds, 0xca33, 0x00);
  memoryASet(ds, 0xca36, 0x00);
  goto loc_112c0;
  //   gap of 86 bytes
loc_1153a:
  memoryASet(ds, 0xca35, 0x00);
loc_1153f:
  return;
  //   gap of 14 bytes
loc_1154e:
  ax = si;
  if (ah != 0xfe)
    goto loc_11567;
  di = memoryAGet16(ds, 0x5172);
  if (memoryAGet(ds, di + 4) == 0xff)
    goto loc_1153a;
  ah = 0;
  bl = memoryAGet(ds, di + 4);
  goto loc_1159e;
  //   gap of 1 bytes
loc_11567:
  if (stop(/*1*/))
    goto loc_1153a;
  ah += 0x02;
  al += 0x03;
  sub_108ad();
  al -= 0x03;
  ah--;
  ch = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)ch)
    goto loc_1153a;
  si = ax;
  ch = memoryAGet(ds, 0xca32);
  memoryASet(ds, 0xca3a, ch);
  bx = memoryAGet16(ds, 0x0041);
  ah -= bl;
  if ((short)bx >= (short)0x00e8)
    goto loc_1153f;
  if ((char)ah <= (char)0x0c)
    goto loc_1153f;
  memoryASet16(ds, 0x0041, memoryAGet16(ds, 0x0041) + 1);
  goto loc_1153f;
loc_1159e:
  memoryASet16(ds, 0x6bd3, ax);
  memoryASet(ds, 0xca36, 0x00);
  memoryASet(ds, 0x003b, 0xff);
  memoryASet(ds, 0x003e, bl);
  ax = 0x0001;
  bx = 0xffffca3e;
  cx = 0x0004;
  goto loc_1078b;
loc_115bd:
  push(bx);
  ax = memoryAGet16(ds, bx);
  sub_10bfb();
  bx = pop();
  al = memoryAGet(ds, 0x003d);
  memoryASet(ds, 0x003b, al);
  al = memoryAGet(ds, 0x003e);
  memoryASet(ds, 0x003c, al);
  al = memoryAGet(ds, bx + 3);
  memoryASet(ds, 0x003e, al);
  al = memoryAGet(ds, bx + 2);
  memoryASet(ds, 0x003d, al);
  if (al == memoryAGet(ds, 0x003b))
    goto loc_115e5;
  goto loc_105e2;
loc_115e5:
  goto loc_1078b;
}
void sub_115e8()
{
  goto loc_115e8;
loc_10356:
  ax = 0x0002;
  sub_10595();
  ax = 0x0002;
  interrupt(0x10);
  bx = 0x21d;
  sub_1036d();
  ah = 0x4c;
  interrupt(0x21);
  //   gap of 629 bytes
loc_105e2:
  bx = 0x6bc3;
  al = memoryAGet(ds, 0x003d);
  ah = 0;
  ax <<= 1;
  bx += ax;
  si = memoryAGet16(ds, bx);
  di = 0x6af8;
  push(ds);
  es = pop();
  ax = 0x1ef8;
  ds = ax;
  cx = 0x00cb;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  push(es);
  ds = pop();
  dx = 0x6af8;
  ax = 0x3d00;
  interrupt(0x21);
  if (!flags.carry)
    goto loc_10611;
  goto loc_10627;
  //   gap of 1 bytes
loc_10611:
  bx = ax;
  dx = 0x260;
  cx = 0x4000;
  ax = 0x3f00;
  interrupt(0x21);
  ax = 0x3e00;
  interrupt(0x21);
  goto loc_1062a;
  //   gap of 1 bytes
loc_10627:
  goto loc_10356;
loc_1062a:
  if (memoryAGet(ds, 0x003d) != 0x06)
    goto loc_10645;
  if (memoryAGet(ds, 0x004a) == 0x01)
    goto loc_10645;
  push(ds);
  es = pop();
  ax = 0;
  di = 0x264;
  cx = 0x4000;
  rep_stosb<MemAuto, DirAuto>();
loc_10645:
  dx = 0x6b06;
  cx = 0x4266;
  sub_10669();
  dx = 0x6b14;
  cx = 0x476a;
  sub_10669();
  dx = 0x6b22;
  cx = 0x4c6e;
  sub_10669();
  goto loc_10685;
  //   gap of 29 bytes
loc_10685:
  si = 0x6b34;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x51a8;
  dx = 0x6aa8;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a4, al);
  sub_106f8();
  si = 0x6b45;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x57e8;
  dx = 0x6abc;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a5, al);
  sub_106f8();
  si = 0x6b56;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x5e28;
  dx = 0x6ad0;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a6, al);
  sub_106f8();
  si = 0x6b67;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_106f5;
  di = 0x6468;
  dx = 0x6ae4;
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, si + 2);
  memoryASet(ds, 0x51a7, al);
  sub_106f8();
loc_106f5:
  goto loc_1078b;
  //   gap of 147 bytes
loc_1078b:
  al = memoryAGet(ds, 0x003e);
  dx = 0x426a;
  cx = 0x6b78;
  if (!al)
    goto loc_107ae;
  dx = 0x476e;
  cx = 0x6b91;
  al--;
  if (al == 0)
    goto loc_107ae;
  dx = 0x4c72;
  cx = 0x6baa;
loc_107ae:
  memoryASet16(ds, 0x4264, dx);
  memoryASet16(ds, 0x5172, cx);
  sub_10944();
  if ((char)memoryAGet(ds, 0x003b) < (char)0x00)
    goto loc_107eb;
  si = memoryAGet16(ds, 0x5172);
  si = si + 0x5; /*chk4*/
  al = memoryAGet(ds, 0x003b);
  ah = memoryAGet(ds, 0x003c);
  cx = 0x0003;
loc_107d1:
  if (al != memoryAGet(ds, si + 2))
    goto loc_107db;
  if (ah == memoryAGet(ds, si + 3))
    goto loc_107e3;
loc_107db:
  si += 0x0004;
  if (--cx)
    goto loc_107d1;
  goto loc_10356;
loc_107e3:
  ax = memoryAGet16(ds, si);
  ah += 0x01;
  memoryASet16(ds, 0x6bd3, ax);
loc_107eb:
  memoryASet(ds, 0xca34, 0x00);
  cx = 0x0005;
  bx = 0xffffca90;
  ax = 0xffff;
loc_107fa:
  memoryASet16(ds, bx, ax);
  bx += 0x0006;
  if (--cx)
    goto loc_107fa;
  ax = memoryAGet16(ds, 0x6bd3);
  memoryASet16(ds, 0x003f, ax);
  al = ah;
  ah = 0;
  flags.carry = ax < 0x000b;
  ax -= 0x000b;
  if (!flags.carry)
    goto loc_10812;
  ax = 0;
loc_10812:
  if (ax < 0x00e8)
    goto loc_1081a;
  ax = 0x00e8;
loc_1081a:
  memoryASet16(ds, 0x0041, ax);
  si = memoryAGet16(ds, 0x5172);
  si = si + 0x11; /*chk4*/
  di = 0x5174;
  cx = 0x0004;
loc_1082b:
  al = memoryAGet(ds, si);
  if (al != 0xff)
    goto loc_10837;
  memoryASet(ds, di + 11, 0xff);
  goto loc_10881;
loc_10837:
  push(cx);
  ah = 0;
  cx = ax;
  bx = 0x51a4;
  bx += ax;
  bl = memoryAGet(ds, bx);
  memoryASet(ds, di + 5, bl);
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  cx <<= 1;
  cx <<= 1;
  ax += cx;
  dx = 0x6aa8;
  dx += ax;
  memoryASet16(ds, di + 7, dx);
  al = memoryAGet(ds, si + 1);
  memoryASet(ds, di + 6, al);
  memoryASet(ds, di + 9, 0x00);
  memoryASet(ds, di + 10, 0x00);
  memoryASet(ds, di + 4, 0x14);
  memoryASet(ds, di + 11, 0x00);
  if (al < 0x80)
    goto loc_10880;
  memoryASet(ds, di + 6, memoryAGet(ds, di + 6) - 0x80);
  memoryASet(ds, di + 11, 0x02);
loc_10880:
  cx = pop();
loc_10881:
  di += 0x000c;
  si += 0x0002;
  if (--cx)
    goto loc_1082b;
  if (memoryAGet(ds, 0x003b) == 0xfe)
    goto loc_108a2;
  if (memoryAGet(ds, 0x003b) == 0xff)
    goto loc_1089f;
  sub_10b7e();
  memoryASet(ds, 0x003b, 0xff);
loc_1089f:
  goto loc_11174;
loc_108a2:
  sub_110f2();
  memoryASet(ds, 0x003b, 0xff);
  goto loc_11174;
  //   gap of 1607 bytes
loc_10ef4:
  sub_109aa();
  memoryASet16(ds, 0xc8fa, 0x0010);
  memoryASet16(ds, 0xc8fc, 0x0030);
  si = 0xffffbce4;
  di = memoryAGet16(ds, 0xca30);
  di += 0x0a05;
  sub_10f38();
  sub_10d28();
  bx = 0xffffc9e5;
  ax = 0x0001;
  cx = 0x0002;
loc_10f20:
  cx = 0;
  es = cx;
  cl = memoryAGet(es, 0x041a);
  memoryASet(es, 0x041c, cl);
  ax = 0;
  interrupt(0x16);
  sub_120b0();
  goto loc_10356;
  //   gap of 59 bytes
loc_10f73:
  sub_1108d();
  cx = 0x0014;
loc_10f79:
  push(cx);
  bx = 0xffffc979;
  ax = 0x0001;
  cx = 0x0003;
  al = 0x0a;
  sub_11e6b();
  ax = 0x0001;
  sub_10343();
  cx = pop();
  if (--cx)
    goto loc_10f79;
loc_10f93:
  if (memoryAGet(ds, 0x0043) == 0x00)
    goto loc_10fc2;
  cx = 0x000a;
loc_10f9d:
  push(cx);
  bx = 0xffffc979;
  ax = 0x0001;
  cx = 0x0003;
  al = 0x0a;
  sub_11e6b();
  ax = 0x0001;
  sub_10343();
  cx = pop();
  if (--cx)
    goto loc_10f9d;
  sub_11c9a();
  ax = 0x0003;
  sub_10343();
  goto loc_10f93;
loc_10fc2:
  bx = 0x81;
  ax = 0x0001;
  cx = 0x0004;
  dx = 0xffffc8fe;
  ax = 0x3d00;
  interrupt(0x21);
  if (!flags.carry)
    goto loc_10fdb;
  goto loc_10356;
loc_10fdb:
  bp = ax;
  push(ds);
  ax = ds;
  es = ax;
  ax = 0xa000;
  ds = ax;
  ah = 0x01;
  bx = 0;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x02;
  bx = 0x0001;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x04;
  bx = 0x0002;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ah = 0x08;
  bx = 0x0003;
  sub_10a90();
  dx = memoryAGet16(es, 0xca30);
  cx = 0x1f40;
  ax = 0x3f00;
  bx = bp;
  interrupt(0x21);
  ax = 0x3e00;
  interrupt(0x21);
  ds = pop();
  sub_102a3();
  sub_11312();
  sub_102bc();
  ax = 0x0014;
  sub_10343();
  ax = 0;
  es = ax;
  cl = memoryAGet(es, 0x041a);
  memoryASet(es, 0x041c, cl);
  ax = 0;
  interrupt(0x16);
  sub_109aa();
  memoryASet16(ds, 0xc8fa, 0x0010);
  memoryASet16(ds, 0xc8fc, 0x0030);
  si = 0xffffbce4;
  di = memoryAGet16(ds, 0xca30);
  di += 0x0a05;
  sub_10f38();
  sub_11312();
  goto loc_10f20;
  //   gap of 231 bytes
loc_11174:
  cx = 0;
  es = cx;
  cl = memoryAGet(es, 0x041a);
  memoryASet(es, 0x041c, cl);
  if (memoryAGet(cs, 0x03ea) == 0x01)
    goto loc_111a1;
  if (memoryAGet(ds, 0xca33) == 0x01)
    goto loc_11174;
  if (memoryAGet(cs, 0x0388) == 0x01)
    goto loc_11174;
  al = memoryAGet(ds, 0x0047);
  memoryASet(ds, 0xca37, al);
  goto loc_11174;
loc_111a1:
  memoryASet(cs, 0x03ea, 0x00);
  if (memoryAGet(ds, 0xca3c) == 0x00)
    goto loc_111bc;
  memoryASet(ds, 0xca3c, memoryAGet(ds, 0xca3c) - 1);
  if (memoryAGet(ds, 0xca3c) != 0x01)
    goto loc_111bc;
  goto loc_10f73;
loc_111bc:
  ch = memoryAGet(ds, 0xca32);
  ch++;
  if (ch != 0x04)
    goto loc_111c9;
  ch = 0x01;
loc_111c9:
  memoryASet(ds, 0xca32, ch);
  memoryASet(ds, 0xca3a, 0x00);
  if (memoryAGet(ds, 0xca3b) == 0x00)
    goto loc_111e0;
  memoryASet(ds, 0xca3b, memoryAGet(ds, 0xca3b) - 1);
  sub_11cff();
loc_111e0:
  if (memoryAGet(ds, 0xca34) == 0x00)
    goto loc_111ed;
  sub_10e32();
  goto loc_11303;
loc_111ed:
  si = memoryAGet16(ds, 0x003f);
  if (memoryAGet(ds, 0xca33) == 0x00)
    goto loc_111fb;
  goto loc_113e8;
loc_111fb:
  if (memoryAGet(cs, 0x0388) != 0x01)
    goto loc_11212;
  if (memoryAGet(ds, 0xca37) == 0x01)
    goto loc_11218;
  memoryASet(ds, 0xca33, 0x01);
  goto loc_113e8;
loc_11212:
  al = memoryAGet(ds, 0x0047);
  memoryASet(ds, 0xca37, al);
loc_11218:
  if (memoryAGet(cs, 0x0387) != 0x01)
    goto loc_1124a;
  di = memoryAGet16(ds, 0x5172);
  bx = di + 0x5; /*chk4*/
  cx = 0x0003;
  ax = si;
loc_1122c:
  dx = memoryAGet16(ds, bx);
  if (al != dl)
    goto loc_11245;
  dh = -dh;
  dh += ah;
  if (dh >= 0x03)
    goto loc_11245;
  if (memoryAGet(ds, 0x0049) != 0x01)
    goto loc_11245;
  goto loc_115bd;
loc_11245:
  bx += 0x0004;
  if (--cx)
    goto loc_1122c;
loc_1124a:
  if (memoryAGet(cs, 0x0389) != 0x01)
    goto loc_1125e;
  if (memoryAGet(ds, 0x004b) != 0x01)
    goto loc_1125e;
  sub_10d82();
  goto loc_111e0;
loc_1125e:
  memoryASet(ds, 0xca35, 0x00);
  if (memoryAGet(cs, 0x039a) != 0x01)
    goto loc_11273;
  memoryASet(ds, 0xca35, 0xfb);
  sub_114e4();
loc_11273:
  if (memoryAGet(cs, 0x039c) != 0x01)
    goto loc_11283;
  memoryASet(ds, 0xca35, 0x05);
  sub_11540();
loc_11283:
  ax = si;
  al += 0x04;
  sub_108ad();
  cl = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)cl)
    goto loc_112c0;
  if (!(ah & 0x01))
    goto loc_1129c;
  if ((char)memoryAGet(ds, bx + 1) > (char)cl)
    goto loc_112c0;
loc_1129c:
  memoryASet(ds, 0xca36, 0x08);
  if ((char)memoryAGet(ds, 0xca35) < (char)0x00)
    goto loc_112b1;
  if (memoryAGet(ds, 0xca35) == 0x00)
    goto loc_112b6;
  memoryASet(ds, 0xca35, 0x02);
  goto loc_112b6;
loc_112b1:
  memoryASet(ds, 0xca35, 0xfe);
loc_112b6:
  memoryASet(ds, 0xca33, 0x01);
  memoryASet(ds, 0xca37, 0x01);
loc_112c0:
  memoryASet16(ds, 0x003f, si);
  if (memoryAGet(cs, 0x0386) != 0x01)
    goto loc_112cf;
  sub_10eb5();
loc_112cf:
  if (memoryAGet(cs, 0x03a1) != 0x01)
    goto loc_112ef;
  if (memoryAGet(ds, 0x0046) == 0x00)
    goto loc_112fd;
  ax = si;
  al++;
  sub_11b2c();
  if (memoryAGet(ds, 0xca3d) == 0x01)
    goto loc_112f8;
  sub_11d7d();
loc_112ef:
  memoryASet(ds, 0xca3d, memoryAGet(ds, 0xca3d) - 1);
  if (memoryAGet(ds, 0xca3d) != 0)
    goto loc_112fd;
  sub_11d4e();
loc_112f8:
  memoryASet(ds, 0xca3d, 0x02);
loc_112fd:
  sub_109aa();
  sub_109dc();
loc_11303:
  sub_115e8();
  sub_11b65();
  sub_11327();
  sub_11312();
  goto loc_11174;
  //   gap of 82 bytes
loc_11364:
  ax = si;
  memoryASet16(ds, 0x003f, ax);
  if ((char)al > (char)0x13)
    goto loc_11393;
  memoryASet(ds, 0xca3a, 0x04);
  cx = 0x0014;
  cl -= al;
  cx <<= 1;
  cx <<= 1;
  cx <<= 1;
  push(cx);
  sub_109aa();
  cx = pop();
  bx = 0x0020;
  bx -= cx;
  sub_10ae8();
  sub_11312();
  ax = 0x0001;
  sub_10343();
loc_11393:
  sub_109aa();
  sub_11312();
  ax = 0x0002;
  sub_10343();
  ax = 0x0001;
  bx = 0xffffca5e;
  cx = 0x0004;
  ax = 0x000f;
  sub_10343();
  if (memoryAGet(ds, 0x0043) != 0x00)
    goto loc_113ba;
  goto loc_10ef4;
loc_113ba:
  sub_11c9a();
  memoryASet(ds, 0xca32, 0x00);
  memoryASet(ds, 0xca33, 0x00);
  memoryASet(ds, 0xca35, 0x00);
  memoryASet(ds, 0xca36, 0x00);
  memoryASet(ds, 0xca37, 0x00);
  memoryASet(ds, 0xca3a, 0x00);
  memoryASet(ds, 0xca3b, 0x06);
  memoryASet(ds, 0xca3d, 0x02);
  goto loc_107eb;
loc_113e8:
  memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) - 1);
  if (memoryAGet(ds, 0xca37) == 0)
    goto loc_113fd;
  if (memoryAGet(cs, 0x0388) != 0x01)
    goto loc_11401;
  memoryASet(ds, 0xca36, memoryAGet(ds, 0xca36) - 0x07);
  goto loc_11401;
loc_113fd:
  memoryASet(ds, 0xca37, memoryAGet(ds, 0xca37) + 1);
loc_11401:
  al = memoryAGet(ds, 0xca36);
  cl = al;
  al = sar(al, 1);
  al = sar(al, 1);
  al = sar(al, 1);
  bx = si;
  bl += al;
  if (stop(/*71*/))
    goto loc_11414;
  bl = 0x00;
loc_11414:
  si = bx;
  if (bl < 0x11)
    goto loc_1141e;
  goto loc_11364;
loc_1141e:
  if (memoryAGet(ds, 0x003d) != 0x02)
    goto loc_11428;
  cl -= 0x02;
loc_11428:
  cl += 0x05;
  if ((char)cl < (char)0x18)
    goto loc_11432;
  cl = 0x17;
loc_11432:
  memoryASet(ds, 0xca36, cl);
  cl = memoryAGet(ds, 0xca35);
  if (memoryAGet(cs, 0x039a) != 0x01)
    goto loc_11450;
  memoryASet(ds, 0xca39, 0x05);
  cl--;
  if ((char)cl >= (char)0xfb)
    goto loc_11450;
  cl = 0xfb;
loc_11450:
  if (memoryAGet(cs, 0x039c) != 0x01)
    goto loc_11466;
  memoryASet(ds, 0xca39, 0x00);
  cl++;
  if ((char)cl <= (char)0x05)
    goto loc_11466;
  cl = 0x05;
loc_11466:
  memoryASet(ds, 0xca35, cl);
  if ((char)cl >= 0)
    goto loc_11475;
  memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) + 1);
  sub_114f2();
loc_11475:
  al = memoryAGet(ds, 0xca35);
  if (stop(/*condition!*/))
    goto loc_11483;
  memoryASet(ds, 0xca35, memoryAGet(ds, 0xca35) - 1);
  sub_1154e();
loc_11483:
  ax = si;
  sub_108ad();
  dl = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)dl)
    goto loc_1149a;
  if (!(ah & 0x01))
    goto loc_1149f;
  if ((char)memoryAGet(ds, bx + 1) <= (char)dl)
    goto loc_1149f;
loc_1149a:
  memoryASet(ds, 0xca36, 0x08);
loc_1149f:
  if ((char)memoryAGet(ds, 0xca36) <= (char)0x00)
    goto loc_114c1;
  cx = si;
  ax = cx;
  al += 0x05;
  sub_108ad();
  dl = memoryAGet(ds, 0x0260);
  if ((char)memoryAGet(ds, bx) > (char)dl)
    goto loc_114c9;
  if (!(ah & 0x01))
    goto loc_114c1;
  if ((char)memoryAGet(ds, bx + 1) > (char)dl)
    goto loc_114c9;
loc_114c1:
  memoryASet(ds, 0xca3a, 0x04);
  goto loc_112c0;
loc_114c9:
  if (cl < 0x0f)
    goto loc_114d0;
  goto loc_114c1;
loc_114d0:
  cl++;
  cl &= 0xfe;
  si = cx;
  memoryASet(ds, 0xca33, 0x00);
  memoryASet(ds, 0xca36, 0x00);
  goto loc_112c0;
  //   gap of 217 bytes
loc_115bd:
  push(bx);
  ax = memoryAGet16(ds, bx);
  sub_10bfb();
  bx = pop();
  al = memoryAGet(ds, 0x003d);
  memoryASet(ds, 0x003b, al);
  al = memoryAGet(ds, 0x003e);
  memoryASet(ds, 0x003c, al);
  al = memoryAGet(ds, bx + 3);
  memoryASet(ds, 0x003e, al);
  al = memoryAGet(ds, bx + 2);
  memoryASet(ds, 0x003d, al);
  if (al == memoryAGet(ds, 0x003b))
    goto loc_115e5;
  goto loc_105e2;
loc_115e5:
  goto loc_1078b;
loc_115e8:
  memoryASet(ds, 0xca82, 0x00);
  si = 0x5174;
  cx = 0x0004;
loc_115f4:
  push(cx);
  if (memoryAGet(ds, si + 9) == 0x01)
    goto loc_1160c;
  if (memoryAGet(ds, si + 9) < 0x01)
    goto loc_11600;
  goto loc_116cd;
loc_11600:
  flags.carry = memoryAGet(ds, si + 4) < 0x01;
  memoryASet(ds, si + 4, memoryAGet(ds, si + 4) - 0x01);
  if (!flags.carry)
    goto loc_11609;
  goto loc_11a87;
loc_11609:
  goto loc_116c2;
loc_1160c:
  al = memoryAGet(ds, si + 4);
  al++;
  if (al != memoryAGet(ds, si + 5))
    goto loc_11618;
  al = 0;
loc_11618:
  memoryASet(ds, si + 4, al);
  al = memoryAGet(ds, si + 6);
  al--;
  if (al == 0)
    goto loc_11635;
  al--;
  if (al == 0)
    goto loc_11638;
  al--;
  if (al == 0)
    goto loc_1163b;
  al--;
  if (al == 0)
    goto loc_1163e;
  al--;
  if (al == 0)
    goto loc_11641;
  goto loc_116c2;
loc_11635:
  goto loc_11843;
loc_11638:
  goto loc_11759;
loc_1163b:
  goto loc_118e0;
loc_1163e:
  goto loc_1196d;
loc_11641:
  goto loc_119ce;
loc_11644:
  ax = memoryAGet16(ds, si);
  bx = ax;
  dx = memoryAGet16(ds, 0x003f);
  flags.carry = bh < dh;
  bh -= dh;
  if (!flags.carry)
    goto loc_11652;
  bh = -bh;
loc_11652:
  if (bh < 0x1e)
    goto loc_1165a;
  goto loc_11741;
loc_1165a:
  if (bh >= 0x02)
    goto loc_11691;
  flags.carry = bl < dl;
  bl -= dl;
  if (flags.carry)
    goto loc_11691;
  if (bl >= 0x04)
    goto loc_11691;
  memoryASet(ds, si + 9, 0x08);
  if (memoryAGet(ds, 0x0044) != 0x00)
    goto loc_1168a;
  if (memoryAGet(ds, 0xca83) != 0x00)
    goto loc_1168a;
  memoryASet(ds, 0xca83, 0x01);
  sub_10d32();
  memoryASet(ds, 0xca83, 0x00);
  goto loc_11393;
loc_1168a:
  push(si);
  sub_11d24();
  si = pop();
  goto loc_116cd;
loc_11691:
  dx = memoryAGet16(ds, 0x0041);
  ah -= dl;
  if ((char)ah < (char)0x00)
    goto loc_116c2;
  if ((char)ah > (char)0x16)
    goto loc_116c2;
  push(si);
  push(ax);
  al = memoryAGet(ds, si + 4);
  al += memoryAGet(ds, si + 10);
  ah = 0;
  ax <<= 1;
  si = memoryAGet16(ds, si + 7);
  si += ax;
  si = memoryAGet16(ds, si);
  bp = si;
  bp += 0x0080;
  cx = 0x0010;
  ax = pop();
  sub_10a21();
  si = pop();
loc_116c2:
  cx = pop();
  si += 0x000c;
  cx--;
  if (cx == 0)
    goto loc_116cc;
  goto loc_115f4;
loc_116cc:
  return;
loc_116cd:
  bl = memoryAGet(ds, si + 9);
  if (bl == 0x07)
    goto loc_116df;
  if ((char)bl < (char)0x07)
    goto loc_116e1;
  bl -= 0x06;
  if (bl != 0x07)
    goto loc_116e1;
loc_116df:
  goto loc_11741;
loc_116e1:
  ax = memoryAGet16(ds, si);
  dx = memoryAGet16(ds, 0x0041);
  ah -= dl;
  if ((char)ah < (char)0x00)
    goto loc_11741;
  if ((char)ah > (char)0x16)
    goto loc_11741;
  if ((char)bl > (char)0x04)
    goto loc_1171b;
  push(si);
  push(ax);
  al = memoryAGet(ds, si + 4);
  al += memoryAGet(ds, si + 10);
  ah = 0;
  ax <<= 1;
  si = memoryAGet16(ds, si + 7);
  si += ax;
  si = memoryAGet16(ds, si);
  bp = si;
  bp += 0x0080;
  cx = 0x0010;
  ax = pop();
  push(ax);
  sub_10a21();
  ax = pop();
  si = pop();
loc_1171b:
  push(si);
  push(ax);
  al = memoryAGet(ds, si + 9);
  ah = 0;
  al -= 0x02;
  ax <<= 1;
  si = 0xffff9984;
  si += ax;
  si = memoryAGet16(ds, si);
  bp = si;
  bp += 0x0080;
  cx = 0x0010;
  ax = pop();
  sub_10a21();
  si = pop();
  memoryASet(ds, si + 9, memoryAGet(ds, si + 9) + 1);
  goto loc_116c2;
loc_11741:
  memoryASet(ds, si + 9, 0x00);
  al = memoryAGet(ds, 0xca80);
  memoryASet(ds, si + 4, al);
  al += 0x14;
  if ((char)al < (char)0x78)
    goto loc_11753;
  al = 0x14;
loc_11753:
  memoryASet(ds, 0xca80, al);
  goto loc_116c2;
loc_11759:
  bl = memoryAGet(ds, si + 3);
  if (stop(/*condition!*/))
    goto loc_11770;
  if (stop(/*condition!*/))
    goto loc_11787;
  ax = memoryAGet16(ds, si);
  al += 0x02;
  sub_108d0();
  if (flags.carry)
    goto loc_1176d;
  goto loc_117ab;
loc_1176d:
  goto loc_1182a;
loc_11770:
  dl = bl;
  bl = sar(bl, 1);
  bl = sar(bl, 1);
  bl = sar(bl, 1);
  bl = -bl;
  ax = memoryAGet16(ds, si);
  flags.carry = al < bl;
  al -= bl;
  if (flags.carry)
    goto loc_117ae;
  sub_108d0();
  if (flags.carry)
    goto loc_117ae;
  goto loc_117b0;
loc_11787:
  dl = bl;
  bl = sar(bl, 1);
  bl = sar(bl, 1);
  bl = sar(bl, 1);
  ax = memoryAGet16(ds, si);
  al += bl;
  if ((char)al < (char)0x12)
    goto loc_117a2;
  memoryASet(ds, si + 9, 0x07);
  al = 0x12;
  memoryASet16(ds, si, ax);
  goto loc_11644;
loc_117a2:
  al++;
  sub_108d0();
  flags.carry = al == 0;
  al--;
  if (!flags.carry)
    goto loc_117b0;
loc_117ab:
  dl = memoryAGet(ds, si + 3);
loc_117ae:
  ax = memoryAGet16(ds, si);
loc_117b0:
  dl += 0x02;
  if ((char)dl < (char)0x18)
    goto loc_117ba;
  dl = 0x17;
loc_117ba:
  memoryASet(ds, si + 3, dl);
  if (memoryAGet(ds, si + 11) == 0x01)
    goto loc_1180a;
  memoryASet(ds, si + 11, memoryAGet(ds, si + 11) + 1);
  dx = memoryAGet16(ds, 0x0041);
  if (memoryAGet(ds, si + 2) != 0x01)
    goto loc_117ef;
  ah += 0x02;
  sub_1090a();
  flags.carry = ah == 0;
  ah--;
  if (!flags.carry)
    goto loc_117de;
  ah--;
  goto loc_117e9;
loc_117de:
  bh = ah;
  flags.carry = bh < dl;
  bh -= dl;
  if (flags.carry)
    goto loc_1180e;
  if (bh < 0x16)
    goto loc_1180e;
loc_117e9:
  memoryASet(ds, si + 2, 0xff);
  goto loc_1180e;
loc_117ef:
  if (!ah)
    goto loc_11804;
  ah--;
  sub_1090a();
  if (!flags.carry)
    goto loc_117fe;
  ah++;
  goto loc_11804;
loc_117fe:
  bh = ah;
  if (bh > dl)
    goto loc_1180e;
loc_11804:
  memoryASet(ds, si + 2, 0x01);
  goto loc_1180e;
loc_1180a:
  memoryASet(ds, si + 11, 0x00);
loc_1180e:
  dx = ax;
  if ((char)memoryAGet(ds, si + 3) <= (char)0x00)
    goto loc_1181d;
  al += 0x03;
  sub_108d0();
  if (flags.carry)
    goto loc_1181f;
loc_1181d:
  goto loc_1183e;
loc_1181f:
  dl++;
  dl &= 0xfe;
  memoryASet(ds, si + 3, 0x00);
  goto loc_1183e;
loc_1182a:
  ax = memoryAGet16(ds, 0x003f);
  ch = 0x01;
  dx = memoryAGet16(ds, si);
  if (ah >= dh)
    goto loc_11837;
  ch = 0xff;
loc_11837:
  memoryASet(ds, si + 2, ch);
  memoryASet(ds, si + 3, 0xf9);
loc_1183e:
  memoryASet16(ds, si, dx);
  goto loc_11644;
loc_11843:
  dx = memoryAGet16(ds, 0x0041);
  ax = memoryAGet16(ds, si);
  if ((char)memoryAGet(ds, si + 11) > (char)0x01)
    goto loc_11857;
  if (memoryAGet(ds, si + 11) != 0x01)
    goto loc_11854;
  goto loc_118d7;
loc_11854:
  memoryASet(ds, si + 11, memoryAGet(ds, si + 11) + 1);
loc_11857:
  if (memoryAGet(ds, si + 2) != 0x01)
    goto loc_11880;
  memoryASet(ds, si + 10, 0x05);
  ah += 0x02;
  sub_1090a();
  flags.carry = ah == 0;
  ah--;
  if (!flags.carry)
    goto loc_1186f;
  ah--;
  goto loc_1187a;
loc_1186f:
  bh = ah;
  flags.carry = bh < dl;
  bh -= dl;
  if (flags.carry)
    goto loc_1189d;
  if (bh < 0x16)
    goto loc_1189d;
loc_1187a:
  memoryASet(ds, si + 2, 0xff);
  goto loc_1189d;
loc_11880:
  memoryASet(ds, si + 10, 0x00);
  if (!ah)
    goto loc_11899;
  ah--;
  sub_1090a();
  if (!flags.carry)
    goto loc_11893;
  ah++;
  goto loc_11899;
loc_11893:
  bh = ah;
  if (bh > dl)
    goto loc_1189d;
loc_11899:
  memoryASet(ds, si + 2, 0x01);
loc_1189d:
  if (memoryAGet(ds, si + 3) != 0x01)
    goto loc_118be;
  if ((char)al >= (char)0x12)
    goto loc_118b8;
  al += 0x02;
  sub_108d0();
  flags.carry = al == 0;
  al--;
  if (!flags.carry)
    goto loc_118b4;
  al--;
  goto loc_118b8;
loc_118b4:
  if ((char)al < (char)0x12)
    goto loc_118db;
loc_118b8:
  memoryASet(ds, si + 3, 0xff);
  goto loc_118db;
loc_118be:
  if (!al)
    goto loc_118d1;
  al--;
  sub_108d0();
  if (!flags.carry)
    goto loc_118cd;
  al++;
  goto loc_118d1;
loc_118cd:
  if (al)
    goto loc_118db;
loc_118d1:
  memoryASet(ds, si + 3, 0x01);
  goto loc_118db;
loc_118d7:
  memoryASet(ds, si + 11, 0x00);
loc_118db:
  memoryASet16(ds, si, ax);
  goto loc_11644;
loc_118e0:
  ch = memoryAGet(ds, si + 3);
  if (stop(/*condition!*/))
    goto loc_118ea;
  goto loc_118ff;
  //   gap of 1 bytes
loc_118ea:
  ax = memoryAGet16(ds, si);
  al++;
  if ((char)al < (char)0x11)
    goto loc_118fd;
  memoryASet(ds, si + 9, 0x07);
  al = 0x12;
  memoryASet16(ds, si, ax);
  goto loc_11644;
loc_118fd:
  goto loc_11916;
loc_118ff:
  dx = memoryAGet16(ds, 0x003f);
  ch = 0x01;
  ax = memoryAGet16(ds, si);
  if (dh == ah)
    goto loc_11911;
  if (dh >= ah)
    goto loc_11913;
  ch = 0xff;
  goto loc_11913;
loc_11911:
  ch = 0;
loc_11913:
  memoryASet(ds, si + 2, ch);
loc_11916:
  if (memoryAGet(ds, si + 11) == 0x01)
    goto loc_11944;
  memoryASet(ds, si + 11, memoryAGet(ds, si + 11) + 1);
  dx = memoryAGet16(ds, 0x0041);
  if (memoryAGet(ds, si + 2) == 0x00)
    goto loc_11944;
  if ((char)memoryAGet(ds, si + 2) < (char)0x00)
    goto loc_11939;
  ah += 0x02;
  sub_1090a();
  flags.carry = ah == 0;
  ah--;
  if (!flags.carry)
    goto loc_11948;
  ah--;
  goto loc_11948;
loc_11939:
  ah--;
  sub_1090a();
  if (!flags.carry)
    goto loc_11948;
  ah++;
  goto loc_11948;
loc_11944:
  memoryASet(ds, si + 11, 0x00);
loc_11948:
  al += 0x03;
  sub_108d0();
  if (flags.carry)
    goto loc_11958;
  al -= 0x03;
  memoryASet(ds, si + 3, 0x01);
  goto loc_11968;
  //   gap of 1 bytes
loc_11958:
  al -= 0x03;
  if (memoryAGet(ds, si + 3) == 0x00)
    goto loc_11968;
  al++;
  al &= 0xfe;
  memoryASet(ds, si + 3, 0x00);
loc_11968:
  memoryASet16(ds, si, ax);
  goto loc_11644;
loc_1196d:
  dx = memoryAGet16(ds, 0x003f);
  ax = memoryAGet16(ds, si);
  if (memoryAGet(ds, si + 11) == 0x01)
    goto loc_119a5;
  memoryASet(ds, si + 11, memoryAGet(ds, si + 11) + 1);
  bx = ax;
  flags.carry = bh < dh;
  bh -= dh;
  if (bh == 0)
    goto loc_119ae;
  if (!flags.carry)
    goto loc_11996;
  memoryASet(ds, si + 10, 0x05);
  ah += 0x02;
  sub_1090a();
  flags.carry = ah == 0;
  ah--;
  if (!flags.carry)
    goto loc_119a9;
  ah--;
  goto loc_119ae;
loc_11996:
  memoryASet(ds, si + 10, 0x00);
  ah--;
  sub_1090a();
  if (!flags.carry)
    goto loc_119a9;
  ah++;
  goto loc_119ae;
loc_119a5:
  memoryASet(ds, si + 11, 0x00);
loc_119a9:
  memoryASet16(ds, si, ax);
  goto loc_11644;
loc_119ae:
  bx = ax;
  flags.carry = bl < dl;
  bl -= dl;
  if (bl == 0)
    goto loc_119a5;
  if (!flags.carry)
    goto loc_119c3;
  al += 0x02;
  sub_108d0();
  flags.carry = al == 0;
  al--;
  if (!flags.carry)
    goto loc_119a9;
  al--;
  goto loc_119a5;
loc_119c3:
  al--;
  sub_108d0();
  if (!flags.carry)
    goto loc_119a9;
  al++;
  goto loc_119a5;
loc_119ce:
  dx = memoryAGet16(ds, 0x0041);
  ax = memoryAGet16(ds, si);
  if ((char)memoryAGet(ds, si + 11) > (char)0x01)
    goto loc_119e2;
  if (memoryAGet(ds, si + 11) != 0x01)
    goto loc_119df;
  goto loc_11a7e;
loc_119df:
  memoryASet(ds, si + 11, memoryAGet(ds, si + 11) + 1);
loc_119e2:
  if (memoryAGet(ds, si + 2) != 0x01)
    goto loc_11a0b;
  memoryASet(ds, si + 10, 0x05);
  ah += 0x02;
  sub_1090a();
  flags.carry = ah == 0;
  ah--;
  if (!flags.carry)
    goto loc_119fa;
  ah--;
  goto loc_11a05;
loc_119fa:
  bh = ah;
  flags.carry = bh < dl;
  bh -= dl;
  if (flags.carry)
    goto loc_11a28;
  if (bh < 0x16)
    goto loc_11a28;
loc_11a05:
  memoryASet(ds, si + 2, 0xff);
  goto loc_11a28;
loc_11a0b:
  memoryASet(ds, si + 10, 0x00);
  if (!ah)
    goto loc_11a24;
  ah--;
  sub_1090a();
  if (!flags.carry)
    goto loc_11a1e;
  ah++;
  goto loc_11a24;
loc_11a1e:
  bh = ah;
  if (bh > dl)
    goto loc_11a28;
loc_11a24:
  memoryASet(ds, si + 2, 0x01);
loc_11a28:
  dx = memoryAGet16(ds, 0x003f);
  flags.carry = dh < ah;
  dh -= ah;
  if (dh == 0)
    goto loc_11a44;
  if (flags.carry)
    goto loc_11a3b;
  if (memoryAGet(ds, 0xca39) != 0x05)
    goto loc_11a44;
  goto loc_11a65;
loc_11a3b:
  if (memoryAGet(ds, 0xca39) != 0x00)
    goto loc_11a44;
  goto loc_11a65;
loc_11a44:
  flags.carry = dl < al;
  dl -= al;
  if (dl == 0)
    goto loc_11a82;
  if (flags.carry)
    goto loc_11a65;
  if ((char)al >= (char)0x12)
    goto loc_11a5f;
  al += 0x02;
  sub_108d0();
  flags.carry = al == 0;
  al--;
  if (!flags.carry)
    goto loc_11a5b;
  al--;
  goto loc_11a5f;
loc_11a5b:
  if ((char)al < (char)0x12)
    goto loc_11a82;
loc_11a5f:
  memoryASet(ds, si + 3, 0xff);
  goto loc_11a82;
loc_11a65:
  if (!al)
    goto loc_11a78;
  al--;
  sub_108d0();
  if (!flags.carry)
    goto loc_11a74;
  al++;
  goto loc_11a78;
loc_11a74:
  if (al)
    goto loc_11a82;
loc_11a78:
  memoryASet(ds, si + 3, 0x01);
  goto loc_11a82;
loc_11a7e:
  memoryASet(ds, si + 11, 0x00);
loc_11a82:
  memoryASet16(ds, si, ax);
  goto loc_11644;
loc_11a87:
  memoryASet(ds, si + 4, 0x00);
  if (memoryAGet(ds, 0xca82) != 0x00)
    goto loc_11ab5;
  ax = memoryAGet16(ds, 0x0041);
  ah = memoryAGet(ds, 0xca81);
  ah += 0x02;
  if (ah < 0x1f)
    goto loc_11aa3;
  ah = 0x18;
loc_11aa3:
  memoryASet(ds, 0xca81, ah);
  if (memoryAGet(ds, 0xca39) == 0x00)
    goto loc_11ab7;
  ah -= 0x16;
  flags.carry = al < ah;
  al -= ah;
  if (!flags.carry)
    goto loc_11abb;
loc_11ab5:
  goto loc_11b29;
loc_11ab7:
  al += ah;
  stop(); // jo loc_11b29
loc_11abb:
  ah = al;
  al = memoryAGet(ds, 0x003f);
  al &= 0xfe;
  al += 0x04;
  cl = memoryAGet(ds, 0x0260);
  sub_108ad();
loc_11acb:
  if ((char)memoryAGet(ds, bx) > (char)cl)
    goto loc_11ade;
  bx -= 0x0080;
  al -= 0x02;
  if (al != 0)
    goto loc_11acb;
  goto loc_116c2;
loc_11ada:
  if ((char)memoryAGet(ds, bx) <= (char)cl)
    goto loc_11ae9;
loc_11ade:
  bx -= 0x0080;
  flags.carry = al < 0x02;
  al -= 0x02;
  if (!flags.carry)
    goto loc_11ada;
  goto loc_116c2;
loc_11ae9:
  memoryASet(ds, 0xca82, 0x01);
  memoryASet16(ds, si, ax);
  memoryASet(ds, si + 9, 0x01);
  if (memoryAGet(ds, si + 6) == 0x01)
    goto loc_11b16;
  if (memoryAGet(ds, si + 6) == 0x05)
    goto loc_11b16;
  if (memoryAGet(ds, si + 6) != 0x7f)
    goto loc_11b21;
  memoryASet(ds, 0xca82, 0x00);
  memoryASet(ds, si + 9, 0x00);
  memoryASet(ds, si + 4, 0x64);
  goto loc_116c2;
loc_11b16:
  memoryASet(ds, si + 2, 0xff);
  memoryASet(ds, si + 3, 0xff);
  goto loc_116c2;
loc_11b21:
  memoryASet(ds, si + 2, 0x00);
  memoryASet(ds, si + 3, 0x00);
loc_11b29:
  goto loc_116c2;
}
void sub_11b2c()
{
  cl = memoryAGet(ds, 0x0045);
  if (!cl)
    return;
  ch = 0;
  si = 0xffffca90;
loc_11b3a:
  if (memoryAGet16(ds, si) != 0xffff)
    goto loc_11b5f;
  memoryASet16(ds, si, ax);
  al = 0x02;
  if (memoryAGet(ds, 0xca39) == 0x00)
    goto loc_11b4c;
  al = 0xfe;
loc_11b4c:
  memoryASet(ds, si + 2, al);
  memoryASet(ds, si + 3, 0x02);
  ax = 0x0001;
  bx = 0xffffcaae;
  cx = 0x0000;
  return;
loc_11b5f:
  si += 0x0006;
  if (--cx)
    goto loc_11b3a;
}
void sub_11b65()
{
  cl = memoryAGet(ds, 0x0045);
  if (cl)
    goto loc_11b6e;
  return;
loc_11b6e:
  ch = 0;
  si = 0xffffca90;
loc_11b74:
  push(cx);
  ax = memoryAGet16(ds, si);
  if (ax == 0xffff)
    goto loc_11bef;
  dl = memoryAGet(ds, si + 2);
  if (stop(/*condition!*/))
    goto loc_11b8b;
  dl = -dl;
  flags.carry = ah < dl;
  ah -= dl;
  if (flags.carry)
    goto loc_11b9c;
  goto loc_11b8d;
loc_11b8b:
  ah += dl;
loc_11b8d:
  dx = memoryAGet16(ds, 0x0041);
  dh = ah;
  flags.carry = dh < dl;
  dh -= dl;
  if (flags.carry)
    goto loc_11b9c;
  if ((char)dh <= (char)0x16)
    goto loc_11ba2;
loc_11b9c:
  memoryASet16(ds, si, 0xffff);
  goto loc_11bef;
loc_11ba2:
  if (memoryAGet(ds, 0x0048) != 0x01)
    goto loc_11bb8;
  memoryASet(ds, si + 3, memoryAGet(ds, si + 3) - 1);
  if (memoryAGet(ds, si + 3) == 0)
    goto loc_11bb2;
  al++;
  goto loc_11bb8;
loc_11bb2:
  al--;
  memoryASet(ds, si + 3, 0x02);
loc_11bb8:
  memoryASet16(ds, si, ax);
  al = memoryAGet(ds, si + 4);
  al++;
  if (al != memoryAGet(ds, si + 5))
    goto loc_11bc6;
  al = 0;
loc_11bc6:
  memoryASet(ds, si + 4, al);
  dx = memoryAGet16(ds, 0x0041);
  ax = memoryAGet16(ds, si);
  ah -= dl;
  push(si);
  push(ax);
  al = memoryAGet(ds, si + 4);
  ah = 0;
  ax <<= 1;
  si = 0xffff9980;
  si += ax;
  si = memoryAGet16(ds, si);
  bp = si;
  bp += 0x0040;
  cx = 0x0008;
  ax = pop();
  sub_10a21();
  si = pop();
loc_11bef:
  cx = pop();
  si += 0x0006;
  cx--;
  if (cx == 0)
    goto loc_11bf9;
  goto loc_11b74;
loc_11bf9:
  si = 0xffffca90;
  cx = 0x0005;
loc_11c00:
  push(cx);
  dx = memoryAGet16(ds, si);
  if (dx == 0xffff)
    goto loc_11c32;
  di = 0x5174;
  cx = 0x0004;
loc_11c0f:
  if (memoryAGet(ds, di + 9) != 0x01)
    goto loc_11c2d;
  ax = memoryAGet16(ds, di);
  bx = dx;
  flags.carry = bl < al;
  bl -= al;
  if (flags.carry)
    goto loc_11c2d;
  if ((char)bl > (char)0x01)
    goto loc_11c2d;
  flags.carry = bh < ah;
  bh -= ah;
  if (!flags.carry)
    goto loc_11c28;
  bh = -bh;
loc_11c28:
  if ((char)bh <= (char)0x01)
    goto loc_11c39;
loc_11c2d:
  di += 0x000c;
  if (--cx)
    goto loc_11c0f;
loc_11c32:
  cx = pop();
  si += 0x0006;
  if (--cx)
    goto loc_11c00;
  return;
loc_11c39:
  memoryASet(ds, di + 9, 0x02);
  memoryASet16(ds, si, 0xffff);
  push(si);
  push(di);
  al = 0x03;
  sub_11e6b();
  di = pop();
  si = pop();
  ax = 0x0001;
  bx = 0xffffcaba;
  cx = 0x0001;
  goto loc_11c32;
}
void sub_11c57()
{
  ax = 0x0001;
  bx = 0xffffcaf5;
  cx = 0x0004;
  al = memoryAGet(ds, 0x0043);
  if (al == 0x05)
    goto loc_11c85;
  al++;
  memoryASet(ds, 0x0043, al);
  bx = 0xa000;
  es = bx;
  di = 0x1c23;
  ah = 0;
  di += ax;
  di += ax;
  di += ax;
  si = 0xffffa304; // wtf!?
    si &= 0xffff;
  goto loc_11cc1;
  //   gap of 1 bytes
loc_11c85:
  memoryASet(ds, 0xca3b, 0x06);
  al = 0x4b;
  sub_11e6b();
  al = 0x4b;
  sub_11e6b();
  al = 0x4b;
  sub_11e6b();
  return;
  //   gap of 39 bytes
loc_11cc1:
  ah = 0x01;
  sub_11cd6();
  ah = 0x02;
  sub_11cd6();
  ah = 0x04;
  sub_11cd6();
  ah = 0x08;
  sub_11cd6();
}
void sub_11c9a()
{
  al = memoryAGet(ds, 0x0043);
  if (al == 0x00)
    goto loc_11cc0;
  memoryASet(ds, 0x0043, memoryAGet(ds, 0x0043) - 1);
  bx = 0xa000;
  es = bx;
  di = 0x1c23;
  ah = 0;
  di += ax;
  di += ax;
  di += ax;
  si = 0xffffa304; // wtf!?
  si += 0x0a00;
    si &= 0xffff;

  goto loc_11cc1;
  //   gap of 1 bytes
loc_11cc0:
  return;
loc_11cc1:
  ah = 0x01;
  sub_11cd6();
  ah = 0x02;
  sub_11cd6();
  ah = 0x04;
  sub_11cd6();
  ah = 0x08;
  sub_11cd6();
}
void sub_11cd6()
{
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = ah;
  out(dx, al);
  bx = 0x0010;
  push(si);
  push(di);
loc_11ce5:
  movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0026;
  bx--;
  if (bx != 0)
    goto loc_11ce5;
  di = pop();
  si = pop();
  bx = 0x0010;
  push(di);
  di += 0x2000;
loc_11cf6:
  movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0026;
  bx--;
  if (bx != 0)
    goto loc_11cf6;
  di = pop();
}
void sub_11cff()
{
  al = memoryAGet(ds, 0x0044);
  if (al == 0x06)
    goto loc_11d1e;
  al++;
  memoryASet(ds, 0x0044, al);
  bx = 0xa000;
  es = bx;
  di = 0x0cee;
  ah = 0;
  di += ax;
  si = 0xffffb0a4;
  goto loc_11dab;
loc_11d1e:
  al = 0x12;
  sub_11e6b();
  return;
  //   gap of 135 bytes
loc_11dab:
  ah = 0x01;
  sub_11dc0();
  ah = 0x02;
  sub_11dc0();
  ah = 0x04;
  sub_11dc0();
  ah = 0x08;
  sub_11dc0();
}
void sub_11d24()
{
  bx = 0xffffcad1;
  ax = 0x0001;
  cx = 0x0002;
  al = memoryAGet(ds, 0x0044);
  if (al == 0x00)
    goto loc_11d4d;
  memoryASet(ds, 0x0044, memoryAGet(ds, 0x0044) - 1);
  bx = 0xa000;
  es = bx;
  di = 0x0cee;
  ah = 0;
  di += ax;
  si = 0xffffb024;
  goto loc_11dab;
  //   gap of 1 bytes
loc_11d4d:
  return;
  //   gap of 93 bytes
loc_11dab:
  ah = 0x01;
  sub_11dc0();
  ah = 0x02;
  sub_11dc0();
  ah = 0x04;
  sub_11dc0();
  ah = 0x08;
  sub_11dc0();
}
void sub_11d4e()
{
  al = memoryAGet(ds, 0x0046);
  if (al == 0x0c)
    goto loc_11d7c;
  al++;
  memoryASet(ds, 0x0046, al);
  ah = al;
  al++;
  al >>= 1;
  bx = 0xa000;
  es = bx;
  di = 0x088e;
  si = 0xffffb064;
  if (ah & 0x01)
    goto loc_11d75;
  si = 0xffffb0a4;
loc_11d75:
  ah = 0;
  di += ax;
  goto loc_11dab;
  //   gap of 1 bytes
loc_11d7c:
  return;
  //   gap of 46 bytes
loc_11dab:
  ah = 0x01;
  sub_11dc0();
  ah = 0x02;
  sub_11dc0();
  ah = 0x04;
  sub_11dc0();
  ah = 0x08;
  sub_11dc0();
}
void sub_11d7d()
{
  al = memoryAGet(ds, 0x0046);
  if (al == 0x00)
    goto loc_11daa;
  memoryASet(ds, 0x0046, memoryAGet(ds, 0x0046) - 1);
  ah = al;
  al++;
  al >>= 1;
  bx = 0xa000;
  es = bx;
  di = 0x088e;
  si = 0xffffb064;
  if (!(ah & 0x01))
    goto loc_11da3;
  si = 0xffffb024;
loc_11da3:
  ah = 0;
  di += ax;
  goto loc_11dab;
  //   gap of 1 bytes
loc_11daa:
  return;
loc_11dab:
  ah = 0x01;
  sub_11dc0();
  ah = 0x02;
  sub_11dc0();
  ah = 0x04;
  sub_11dc0();
  ah = 0x08;
  sub_11dc0();
}
void sub_11dab()
{
  ah = 0x01;
  sub_11dc0();
  ah = 0x02;
  sub_11dc0();
  ah = 0x04;
  sub_11dc0();
  ah = 0x08;
  sub_11dc0();
}
void sub_11dc0()
{
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = ah;
  out(dx, al);
  bx = 0x0010;
  push(si);
  push(di);
loc_11dcf:
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  bx--;
  if (bx != 0)
    goto loc_11dcf;
  di = pop();
  si = pop();
  bx = 0x0010;
  push(di);
  di += 0x2000;
loc_11de0:
  movsb<MemAuto, MemAuto, DirAuto>();
  di += 0x0027;
  bx--;
  if (bx != 0)
    goto loc_11de0;
  di = pop();
}
void sub_11e25()
{
  ah = 0x01;
  sub_11e3a();
  ah = 0x02;
  sub_11e3a();
  ah = 0x04;
  sub_11e3a();
  ah = 0x08;
  sub_11e3a();
}
void sub_11e3a()
{
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  al = ah;
  out(dx, al);
  bx = 0x0010;
  push(si);
  push(di);
loc_11e49:
  movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0026;
  bx--;
  if (bx != 0)
    goto loc_11e49;
  di = pop();
  si = pop();
  bx = 0x0010;
  push(di);
  di += 0x2000;
  si += 0x0a00;
loc_11e5e:
  movsw<MemAuto, MemAuto, DirAuto>();
  di += 0x0026;
  bx--;
  if (bx != 0)
    goto loc_11e5e;
  si -= 0x0a00;
  di = pop();
}
void sub_11e6b()
{
  bx = 0xa000;
  es = bx;
  di = 0x03e1;
  bx = 0x4d;
  push(bx);
loc_11e78:
  ah = memoryAGet(ds, bx);
  ah += al;
  al = 0;
  if (ah < 0x64)
    goto loc_11e88;
  al++;
  ah -= 0x64;
loc_11e88:
  memoryASet(ds, bx, ah);
  push(ax);
  push(bx);
  sub_11eb3();
  bx = pop();
  ax = pop();
  bx++;
  di -= 0x0002;
  if (al)
    goto loc_11e78;
  ax = pop();
  ax++;
  bx -= ax;
  if (stop(/*71*/))
    return;
  memoryASet(ds, 0x0050, memoryAGet(ds, 0x0050) + 1);
  if ((char)memoryAGet(ds, 0x0050) < (char)0x05)
    return;
  memoryASet(ds, 0x0050, 0x00);
  sub_11c57();
}
void sub_11eb3()
{
  goto loc_11eb3;
loc_11dab:
  ah = 0x01;
  sub_11dc0();
  ah = 0x02;
  sub_11dc0();
  ah = 0x04;
  sub_11dc0();
  ah = 0x08;
  sub_11dc0();
  return;
  //   gap of 243 bytes
loc_11eb3:
  di++;
  al = 0;
loc_11eb6:
  flags.carry = ah < 0x0a;
  ah -= 0x0a;
  if (flags.carry)
    goto loc_11ebf;
  al++;
  goto loc_11eb6;
loc_11ebf:
  ah += 0x0a;
  push(ax);
  al = ah;
  ah = 0;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  si = 0xffffada4;
  si += ax;
  sub_11dab();
  di--;
  ax = pop();
  ah = 0;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  si = 0xffffada4;
  si += ax;
  goto loc_11dab;
}
void sub_11fb9()
{
  goto loc_11fb9;
loc_11de9:
  al = memoryAGet(ds, 0x0045);
  if (al == 0x05)
    goto loc_11e24;
  al++;
  memoryASet(ds, 0x0045, al);
  bx = 0xa000;
  es = bx;
  di = 0x119d;
  si = 0xffff9ea4;
  ah = 0;
  bx = ax;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  bx <<= 1;
  bx <<= 1;
  bx <<= 1;
  bx <<= 1;
  bx <<= 1;
  ax += bx;
  si += ax;
  goto loc_11e25;
  //   gap of 1 bytes
loc_11e24:
  return;
loc_11e25:
  ah = 0x01;
  sub_11e3a();
  ah = 0x02;
  sub_11e3a();
  ah = 0x04;
  sub_11e3a();
  ah = 0x08;
  sub_11e3a();
  return;
  //   gap of 187 bytes
loc_11ef5:
  memoryASet(ds, 0x0048, 0x01);
  bx = 0xa000;
  es = bx;
  di = 0x11a0;
  si = 0xffff99a4;
  goto loc_11e25;
loc_11f09:
  memoryASet(ds, 0x0049, 0x01);
  bx = 0xa000;
  es = bx;
  di = 0x11a3;
  si = 0xffff9a44;
  goto loc_11e25;
loc_11f1d:
  memoryASet(ds, 0x0047, 0x05);
  bx = 0xa000;
  es = bx;
  di = 0x155d;
  si = 0xffff9ae4;
  goto loc_11e25;
loc_11f31:
  memoryASet(ds, 0x004a, 0x01);
  bx = 0xa000;
  es = bx;
  di = 0x1560;
  si = 0xffff9b84;
  goto loc_11e25;
loc_11f45:
  memoryASet(ds, 0x004b, 0x01);
  bx = 0xa000;
  es = bx;
  di = 0x1563;
  si = 0xffff9c24;
  goto loc_11e25;
loc_11f59:
  sub_11c57();
  memoryASet(ds, 0x004c, memoryAGet(ds, 0x004c) + 1);
  bx = 0xa000;
  es = bx;
  di = 0x191d;
  si = 0xffff9cc4;
  sub_11e25();
  if (memoryAGet(ds, 0x004c) == 0x03)
    goto loc_11f95;
  return;
loc_11f77:
  sub_11c57();
  memoryASet(ds, 0x004c, memoryAGet(ds, 0x004c) + 1);
  bx = 0xa000;
  es = bx;
  di = 0x1920;
  si = 0xffff9d64;
  sub_11e25();
  if (memoryAGet(ds, 0x004c) == 0x03)
    goto loc_11f95;
  return;
loc_11f95:
  memoryASet(ds, 0xca3c, 0x14);
  return;
loc_11f9b:
  sub_11c57();
  memoryASet(ds, 0x004c, memoryAGet(ds, 0x004c) + 1);
  bx = 0xa000;
  es = bx;
  di = 0x1923;
  si = 0xffff9e04;
  sub_11e25();
  if (memoryAGet(ds, 0x004c) == 0x03)
    goto loc_11f95;
  return;
loc_11fb9:
  push(ax);
  push(bx);
  bx = ax;
  ax = memoryAGet16(ds, 0x0041);
  bh += al;
  dx = memoryAGet16(ds, 0x003f);
  flags.carry = bh < dh;
  bh -= dh;
  if (!flags.carry)
    goto loc_11fcc;
  bh = -bh;
loc_11fcc:
  if (bh >= 0x02)
    goto loc_11fdd;
  flags.carry = bl < dl;
  bl -= dl;
  if (flags.carry)
    goto loc_11fdd;
  if (bl >= 0x04)
    goto loc_11fdd;
  goto loc_12024;
  //   gap of 1 bytes
loc_11fdd:
  bx = pop();
  bh = 0;
  ax = bx;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  bx <<= 1;
  bx <<= 1;
  bx <<= 1;
  bx <<= 1;
  bx <<= 1;
  ax += bx;
  si = 0xffff99a4;
  memoryASet(ds, 0xcad0, memoryAGet(ds, 0xcad0) + 1);
  if (memoryAGet(ds, 0xcad0) != 0x02)
    goto loc_12014;
  memoryASet(ds, 0xcad0, 0x00);
  si += 0x0a00;
loc_12014:
  si += ax;
  bp = si;
  bp += 0x0080;
  cx = 0x0010;
  ax = pop();
  sub_10a21();
  return;
loc_12024:
  bx = 0xffffcae1;
  ax = 0x0001;
  cx = 0x0003;
  al = 0x14;
  sub_11e6b();
  bx = 0x51;
  al = memoryAGet(ds, 0x003e);
  al <<= 1;
  al <<= 1;
  al <<= 1;
  al <<= 1;
  al += memoryAGet(ds, 0x003d);
  ah = 0;
  bx += ax;
  memoryASet(ds, bx, 0x01);
  bx = pop();
  ax = pop();
  if (bl != 0x0e)
    goto loc_12066;
  if (memoryAGet(ds, 0x0044) != 0x06)
    goto loc_12060;
  sub_11c57();
  return;
loc_12060:
  memoryASet(ds, 0xca3b, 0x06);
  return;
loc_12066:
  if (bx)
    goto loc_1206d;
  goto loc_11ef5;
loc_1206d:
  bl--;
  if (bl != 0)
    goto loc_12074;
  goto loc_11f09;
loc_12074:
  bl--;
  if (bl != 0)
    goto loc_1207b;
  goto loc_11f1d;
loc_1207b:
  bl--;
  if (bl != 0)
    goto loc_12082;
  goto loc_11f31;
loc_12082:
  bl--;
  if (bl != 0)
    goto loc_12089;
  goto loc_11f45;
loc_12089:
  bl--;
  if (bl != 0)
    goto loc_12090;
  goto loc_11f59;
loc_12090:
  bl--;
  if (bl != 0)
    goto loc_12097;
  goto loc_11f77;
loc_12097:
  bl--;
  if (bl != 0)
    goto loc_1209e;
  goto loc_11f9b;
loc_1209e:
  goto loc_11de9;
}
void sub_120b0()
{
  ax = 0x000d;
  interrupt(0x10);
  flags.direction = false;
  ax = 0x1fdd;
  ds = ax;
  ax = 0xa000;
  es = ax;
  si = 0x0;
  ah = 0x01;
  bx = 0x0000;
  sub_10a90();
  cx = 0x0fa0;
  di = 0;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  ah = 0x02;
  bx = 0x0001;
  sub_10a90();
  cx = 0x0fa0;
  di = 0;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  ah = 0x04;
  bx = 0x0002;
  sub_10a90();
  cx = 0x0fa0;
  di = 0;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  ah = 0x08;
  bx = 0x0003;
  sub_10a90();
  cx = 0x0fa0;
  di = 0;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  ah = 0;
  sub_10a90();
  ax = 0x122a;
  ds = ax;
  es = ax;
  goto loc_12112;
loc_1210e:
  ah = 0x4c;
  interrupt(0x21);
loc_12112:
  ax = 0x3d00;
  dx = 0xffffcb10;
  interrupt(0x21);
  if (flags.carry)
    goto loc_1210e;
  bx = ax;
  cx = 0x00b4;
  dx = 0xffffcb25;
  ah = 0x3f;
  interrupt(0x21);
  ah = 0x3e;
  interrupt(0x21);
  si = 0xffffcb25;
  cx = 0x000a;
loc_12135:
  push(cx);
  push(si);
  si += 0x0010;
  di = 0x4f;
  cx = 0x0003;
loc_12141:
  al = memoryAGet(ds, si);
  if ((char)al < (char)memoryAGet(ds, di))
    goto loc_12157;
  if ((char)al > (char)memoryAGet(ds, di))
    goto loc_1214d;
  si--;
  di--;
  if (--cx)
    goto loc_12141;
loc_1214d:
  si = pop();
  si += 0x0012;
  cx = pop();
  if (--cx)
    goto loc_12135;
  goto loc_12205;
loc_12157:
  si = pop();
  cx = pop();
  push(si);
  ax = 0x0012;
  mul(cl);
  cx = ax;
  di = 0xffffcbd9;
  push(si);
  push(di);
  push(cx);
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  cx = pop();
  si = pop();
  di = pop();
  di += 0x0012;
  cx -= 0x0012;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di = pop();
  push(di);
  di += 0x000e;
  si = 0x4d;
  cx = 0x0003;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  ah = 0x02;
  bh = 0x00;
  dx = 0x0a0e;
  interrupt(0x10);
  bx = 0x0009;
  dx = 0xffffcc9c;
  sub_12289();
  ah = 0x02;
  bh = 0x00;
  dx = 0x0b05;
  interrupt(0x10);
  bx = 0x000a;
  dx = 0xffffcca9;
  sub_12289();
  dx = 0xffffcc8d;
  ah = 0x0a;
  interrupt(0x21);
  cl = memoryAGet(ds, 0xcc8e);
  ch = 0;
  si = 0xffffcc8f;
  di = pop();
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  memoryASet(ds, di, 0x24);
  ah = 0x02;
  bh = 0x00;
  dx = 0x0a05;
  interrupt(0x10);
  bx = 0x0001;
  dx = 0xffffccbe;
  sub_12289();
  ah = 0x02;
  bh = 0x00;
  dx = 0x0b05;
  interrupt(0x10);
  bx = 0x0002;
  dx = 0xffffccbe;
  sub_12289();
  ax = 0x3c00;
  cx = 0;
  dx = 0xffffcb10;
  interrupt(0x21);
  if (flags.carry)
    goto loc_12205;
  bx = ax;
  cx = 0x00b4;
  dx = 0xffffcb25;
  ah = 0x40;
  interrupt(0x21);
  ah = 0x3e;
  interrupt(0x21);
loc_12205:
  cx = 0x000a;
  si = 0xffffcb25;
  dh = 0x07;
loc_1220e:
  push(cx);
  push(dx);
  dl = 0x08;
  ah = 0x02;
  bh = 0x00;
  interrupt(0x10);
  bx = 0x000b;
  dx = si;
  sub_12289();
  dx = pop();
  push(dx);
  dl = 0x18;
  ah = 0x02;
  bh = 0x00;
  interrupt(0x10);
  bx = si;
  bx += 0x000e;
  sub_12249();
  dx = pop();
  cx = pop();
  dh += 0x01;
  if (cx != 0x000a)
    goto loc_1223f;
  dh += 0x01;
loc_1223f:
  si += 0x0012;
  if (--cx)
    goto loc_1220e;
  ax = 0;
  interrupt(0x16);
}
void sub_12249()
{
  al = memoryAGet(ds, bx + 2);
  sub_12265();
  al = memoryAGet(ds, bx + 1);
  sub_12265();
  al = memoryAGet(ds, bx);
  sub_12265();
  dx = 0xffffccbb;
  bx = 0x000c;
  sub_12289();
}
void sub_12265()
{
  push(bx);
  cl = al;
  al = 0;
loc_1226a:
  flags.carry = cl < 0x0a;
  cl -= 0x0a;
  if (flags.carry)
    goto loc_12273;
  al++;
  goto loc_1226a;
loc_12273:
  al += 0x30;
  cl += 0x0a;
  push(cx);
  ah = 0x0e;
  bx = 0x000c;
  interrupt(0x10);
  ax = pop();
  al += 0x30;
  ah = 0x0e;
  interrupt(0x10);
  bx = pop();
}
void sub_12289()
{
  push(si);
  push(ax);
  si = dx;
  ah = 0x0e;
loc_1228f:
  lodsb<MemAuto, DirAuto>();
  if (al == 0x24)
    goto loc_12298;
  interrupt(0x10);
  goto loc_1228f;
loc_12298:
  ax = pop();
  si = pop();
}
