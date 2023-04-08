#include "cicoemu.h"
using namespace CicoContext;

void sub_183a1();

void start()
{
  headerSize = 0x0050;
  ds = 0x1839;
  cs = 0x1839;
  ss = 0x1000;
  sp = 0x0050;
  sub_183a1();
}
void sub_183a1();
void sub_1859b();
void sub_185ac();
void sub_186b6();
void sub_18768();
void sub_1880d();
void sub_18870();
void sub_1888b();
void sub_188ab();
void sub_188b9();
void sub_188cd();
void sub_188e1();
void sub_18923();
void sub_18935();
void sub_189a1();
void sub_189f8();
void sub_18a09();
void sub_18a49();
void sub_18a8d();
void sub_18aab();
void sub_18b13();
void sub_18b2a();
void sub_18b35();
void sub_18b4e();
void sub_18b77();
void sub_18bb2();
void sub_18bed();
void sub_18c30();
void sub_18d4c();
void sub_18dcf();
void sub_18df7();
void sub_19093();
void sub_1909a();
void sub_190c8();
void sub_190f6();
void sub_19111();
void sub_1914b();
void sub_1916c();
void sub_1918b();
void sub_192a7();
void sub_193b4();
void sub_193c1();
void sub_19433();
void sub_1961f();
void sub_19645();
void sub_1966e();
void sub_196f9();
void sub_1973c();
void sub_19a02();
void sub_19a8b();
void sub_19b30();
void sub_19b5c();
void sub_19bca();
void sub_19c06();
void sub_19c18();
void sub_19c38();
void sub_19c43();
void sub_19c59();
void sub_1a042();
void sub_1a04f();
void sub_1a069();
void sub_1a108();
void sub_1a10c();
void sub_1a110();
void sub_1a114();
void sub_1a11b();
void sub_1a196();
void sub_1a1c4();
void sub_1a209();
void sub_1a26d();
void sub_1a322();
void sub_1a34a();
void sub_1a3ac();
void sub_1a3de();
void sub_1a40e();
void sub_1a4c8();
void sub_1a63c();
void sub_1a699();
void sub_1a6d3();
void sub_1a71b();
void sub_1a7d2();
void sub_1a802();
void sub_1a833();
void sub_1a876();
void sub_1a8fc();
void sub_1a941();
void sub_1a947();
void sub_1a9bb();
void sub_1a9d8();
void sub_1aa67();
void sub_1ab24();
void sub_1ab3e();
void sub_1ab61();
void sub_1abfc();
void sub_1acae();
void sub_1ad03();
void sub_1ad74();
void sub_1adf9();
void sub_1ae5e();
void sub_1af12();
void sub_1af23();
void sub_1af58();
void sub_1af7c();
void sub_183a1()
{
  push(ds);
  ax = 0;
  push(ax);
  push(ds);
  ax = 0x100d;
  ds = ax;
  cx = 0;
  dh = 0x18;
  dl = 0x4f;
  bh = 0;
  al = 0;
  ah = 0x06;
  interrupt(0x10);
  ax = 0x0001;
  interrupt(0x10);
  dx = 0x0096;
  ah = 0x09;
  interrupt(0x21);
  dx = 0x00cb;
  ah = 0x0a;
  interrupt(0x21);
  ah = memoryAGet(ds, 0x00cd);
  if (ah != 0x79)
    goto loc_183d8;
  goto loc_183e5;
  //   gap of 1 bytes
loc_183d8:
  if (ah == 0x59)
    goto loc_183e5;
  memoryASet(ds, 0x00cf, 0x00);
  goto loc_183ea;
  //   gap of 1 bytes
loc_183e5:
  memoryASet(ds, 0x00cf, 0x01);
loc_183ea:
  sub_18a09();
  bx = 0x0c80;
  ah = 0x4a;
  interrupt(0x21);
  memoryASet(ds, 0x5e39, 0x00);
  sub_18aab();
  if (memoryAGet(ds, 0x5d9d) != 0x01)
    goto loc_18406;
  goto loc_18571;
loc_18406:
  sub_18a49();
  ax = 0x1005;
  es = ax;
  ds = pop();
  si = 0x0080;
  di = 0x0000;
  cx = 0x0080;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  ax = 0x100d;
  ds = ax;
  memoryASet(cs, 0x0000, 0x00);
  if (memoryAGet(es, 0x0000) != 0x02)
    goto loc_18449;
  if (memoryAGet(es, 0x0002) == 0x48)
    goto loc_1843d;
  if (memoryAGet(es, 0x0002) != 0x68)
    goto loc_18449;
loc_1843d:
  memoryASet(cs, 0x0000, 0x01);
  sub_18bb2();
  goto loc_18468;
  //   gap of 1 bytes
loc_18449:
  memoryASet(ds, 0x5d9c, 0x00);
  memoryASet(ds, 0x5d9d, 0x00);
  ax = 0xf000;
  es = ax;
  al = memoryAGet(es, 0xfffe);
  if (al != 0xfd)
    goto loc_18465;
  memoryASet(ds, 0x5d9c, 0x01);
loc_18465:
  sub_1a6d3();
loc_18468:
  sub_19c43();
  ax = 0x100d;
  es = ax;
  ds = ax;
  dx = 0x0201;
  si = 0x0008;
  bx = 0;
  ah = 0x01;
loc_1847c:
  sub_1859b();
  bx += cx;
  si--;
  if (si != 0)
    goto loc_1847c;
  bx >>= 1;
  bx >>= 1;
  flags.carry = bx & 1;
  bx >>= 1;
  bx += flags.carry;
  memoryASet16(ds, 0x0092, bx);
  si = 0x0008;
  bx = 0;
  ah = 0x02;
loc_18498:
  sub_1859b();
  bx += cx;
  si--;
  if (si != 0)
    goto loc_18498;
  bx >>= 1;
  bx >>= 1;
  flags.carry = bx & 1;
  bx >>= 1;
  bx += flags.carry;
  memoryASet16(ds, 0x0094, bx);
  push(es);
  ax = 0xf000;
  es = ax;
  if (memoryAGet(es, 0xfffe) == 0xfc)
    goto loc_184c4;
  memoryASet16(ds, 0x0090, 0x0018);
  goto loc_184ca;
  //   gap of 1 bytes
loc_184c4:
  memoryASet16(ds, 0x0090, 0x0096);
loc_184ca:
  es = pop();
  memoryASet(ds, 0x5d11, 0x00);
  dx = 0x4612;
  cx = 0x3e84;
  memoryASet16(ds, 0x4610, 0x0243);
  sub_1914b();
  sub_18df7();
  if (memoryAGet(ds, 0x5e39) != 0x01)
    goto loc_184ec;
  goto loc_18571;
loc_184ec:
  memoryASet16(ds, 0x4289, 0x4321);
loc_184f2:
  sub_196f9();
  memoryASet16(ds, 0x5d25, 0xffff);
  sub_19433();
  if (memoryAGet(ds, 0x5e39) != 0x01)
    goto loc_18508;
  goto loc_18571;
  //   gap of 1 bytes
loc_18508:
  bx = memoryAGet16(ds, 0x40c9);
  if (bx)
    goto loc_18522;
  dx = 0x5d9e;
  cx = 0x3e82;
  memoryASet16(ds, 0x4610, 0x0245);
  sub_1914b();
  goto loc_18531;
  //   gap of 1 bytes
loc_18522:
  bx--;
  bx <<= 1;
  ds = memoryAGet16(ds, bx + 24048);
  sub_18b2a();
  ax = 0x100d;
  ds = ax;
loc_18531:
  sub_19c59();
  if (memoryAGet(ds, 0x5e39) == 0x01)
    goto loc_18571;
  sub_192a7();
  sub_1973c();
  bp = 0x44b1;
  memoryASet16(ds, 0x42e2, 0x0007);
  memoryASet16(ds, 0x42e4, 0x00be);
  sub_1a947();
loc_18553:
  sub_19c06();
  sub_19bca();
  sub_19c18();
  if (ah == 0x31)
    goto loc_18571;
  if (ah != 0x15)
    goto loc_18553;
  sub_19c38();
  memoryASet16(ds, 0x4289, memoryAGet16(ds, 0x4289) + 0x6539);
  goto loc_184f2;
loc_18571:
  sub_1a699();
  sub_18b13();
  ax = 0x0040;
  es = ax;
  memoryASet(es, 0x0017, memoryAGet(es, 0x0017) & 0xdf);
  ax = 0x100d;
  es = ax;
  ax = 0x0003;
  interrupt(0x10);
  if (memoryAGet(ds, 0x5d9d) == 0x00)
    return;
  ah = 0x09;
  dx = 0x5d65;
  interrupt(0x21);
}
void sub_1859b()
{
  dx = 0x0201;
  cx = 0x0400;
loc_185a1:
  if (--cx)
    goto loc_185a1;
  out(dx, al);
loc_185a4:
  in(al, dx);
  if (--cx && al & ah)
    goto loc_185a4;
  cx = -cx;
}
void sub_185ac()
{
  push(bx);
  push(cx);
  push(dx);
  push(bp);
  push(si);
  push(di);
  push(ds);
  push(es);
  ax = 0x100d;
  ds = ax;
  dx = 0x0201;
  cx = 0x0400;
loc_185bf:
  if (--cx)
    goto loc_185bf;
  in(al, dx);
  if (al & 0x10)
    goto loc_185d0;
loc_185c6:
  in(al, dx);
  if (!(al & 0x10))
    goto loc_185c6;
  ah = 0x1c;
  goto loc_1862e;
  //   gap of 1 bytes
loc_185d0:
  ax = 0;
  ah++;
  sub_1859b();
  si = cx;
  ah++;
  sub_1859b();
  dx = cx;
  bp = 0;
  di = 0;
  si -= memoryAGet16(ds, 0x0092);
  bp = si;
  if ((short)si >= (short)0x0000)
    goto loc_185f1;
  si = -si;
loc_185f1:
  dx -= memoryAGet16(ds, 0x0094);
  di = dx;
  if ((short)dx >= (short)0x0000)
    goto loc_185fe;
  dx = -dx;
loc_185fe:
  if ((short)si < (short)dx)
    goto loc_18617;
  if ((short)si < (short)memoryAGet16(ds, 0x0090))
    goto loc_1862c;
  if ((short)bp < (short)0x0000)
    goto loc_18612;
  ah = 0x4d;
  goto loc_1862e;
  //   gap of 1 bytes
loc_18612:
  ah = 0x4b;
  goto loc_1862e;
  //   gap of 1 bytes
loc_18617:
  if ((short)dx < (short)memoryAGet16(ds, 0x0090))
    goto loc_1862c;
  if ((short)di < (short)0x0000)
    goto loc_18627;
  ah = 0x50;
  goto loc_1862e;
  //   gap of 1 bytes
loc_18627:
  ah = 0x48;
  goto loc_1862e;
  //   gap of 1 bytes
loc_1862c:
  ah = 0;
loc_1862e:
  es = pop();
  ds = pop();
  di = pop();
  si = pop();
  bp = pop();
  dx = pop();
  cx = pop();
  bx = pop();
}
void sub_186b6()
{
  push(es);
  push(ds);
  si = 0x100d;
  ds = si;
  si = 0xa000;
  es = si;
  bp = 0x5dc0;
  bp += 0x0008;
  bx = 0;
  bx += 0x0002;
  memoryASet16(cs, 0x0324, bx);
  memoryASet16(cs, 0x031c, 0x0008);
loc_186da:
  si = 0x0010;
  memoryASet16(ds, bx + 208, bp);
  cx = memoryAGet16(cs, bx + 677);
  memoryASet16(cs, 0x031a, cx);
  push(bp);
  sub_1880d();
  bp = pop();
  bx = memoryAGet16(cs, 0x0324);
  bp += memoryAGet16(cs, 0x031c);
  bx += 0x0002;
  memoryASet16(cs, 0x0324, bx);
  if ((short)bx < (short)0x0010)
    goto loc_186da;
  si = 0x0080;
  memoryASet16(ds, bx + 208, bp);
  cx = memoryAGet16(cs, bx + 677);
  memoryASet16(cs, 0x031a, cx);
  push(bp);
  sub_1880d();
  bp = pop();
  bx = memoryAGet16(cs, 0x0324);
  bp += memoryAGet16(cs, 0x031c);
  bx += 0x0002;
  memoryASet16(cs, 0x0324, bx);
  memoryASet16(cs, 0x031c, 0x002d);
  cx = 0x0315;
  memoryASet16(cs, 0x031a, cx);
loc_1873e:
  si = memoryAGet16(ds, bx + 24563);
  si += 0x0002;
  memoryASet16(ds, bx + 208, bp);
  push(bp);
  sub_1880d();
  bp = pop();
  bx = memoryAGet16(cs, 0x0324);
  bp += memoryAGet16(cs, 0x031c);
  bx += 0x0002;
  memoryASet16(cs, 0x0324, bx);
  if ((short)bx < (short)0x0028)
    goto loc_1873e;
  ds = pop();
  es = pop();
}
void sub_18768()
{
  bx = memoryAGet16(cs, 0x0320);
  sub_1888b();
  di = memoryAGet16(cs, 0x031e);
  si = memoryAGet16(cs, 0x0320);
  sub_18870();
  di = memoryAGet16(cs, 0x031e);
  si = memoryAGet16(cs, 0x0320);
  memoryASet16(cs, 0x031e, si);
  memoryASet16(cs, 0x0320, di);
}
void sub_1880d()
{
  if (memoryAGet(ds, 0x6471) == 0x01)
    return;
  al = 0x0f;
  sub_188b9();
  al = 0x02;
  sub_188cd();
  dx = 0x03ce;
  al = 0x08;
  out(dx, al);
  dx = 0;
  bx = memoryAGet16(cs, 0x031a);
  ax = memoryAGet16(cs, 0x031c);
  cl = 0x06;
loc_18831:
  push(ax);
  ch = 0x80;
loc_18834:
  ah = 0x04;
  dl = memoryAGet(ds, si);
  si++;
  push(si);
loc_1883a:
  di = dx;
  di &= 0x00c0;
  di >>= cl;
  si = dx;
  dx = 0x03cf;
  al = ch;
  out(dx, al);
  dx = si;
  al = memoryAGet(es, bp);
  al = memoryAGet(cs, bx + di);
  memoryASet(es, bp, al);
  ch >>= 1;
  ah--;
  if (ah == 0)
    goto loc_18861;
  dl = ror(dl, cl);
  goto loc_1883a;
loc_18861:
  si = pop();
  if (!ch)
    goto loc_18868;
  goto loc_18834;
loc_18868:
  bp++;
  ax = pop();
  ax--;
  if (ax == 0)
    return;
  goto loc_18831;
}
void sub_18870()
{
  push(es);
  push(ds);
  ax = 0xa000;
  es = ax;
  ds = ax;
  al = 0x01;
  sub_188cd();
  al = 0x0f;
  sub_188b9();
  cx = 0x1f40;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  ds = pop();
  es = pop();
}
void sub_1888b()
{
  push(es);
  ax = 0xa000;
  es = ax;
  sub_188ab();
  dx = 0x03d4;
  al = 0x0d;
  out(dx, al);
  dx++;
  al = bl;
  out(dx, al);
  dx--;
  al = 0x0c;
  out(dx, al);
  dx++;
  al = bh;
  out(dx, al);
  sub_188ab();
  es = pop();
}
void sub_188ab()
{
  dx = 0x03da;
loc_188ae:
  in(al, dx);
  al &= 0x08;
  if (al != 0)
    goto loc_188ae;
loc_188b3:
  in(al, dx);
  al &= 0x08;
  if (al == 0)
    goto loc_188b3;
}
void sub_188b9()
{
  if (memoryAGet(ds, 0x6471) == 0x01)
    return;
  push(dx);
  push(ax);
  dx = 0x03c4;
  al = 0x02;
  out(dx, al);
  dx++;
  ax = pop();
  out(dx, al);
  dx = pop();
}
void sub_188cd()
{
  if (memoryAGet(ds, 0x6471) == 0x01)
    return;
  push(dx);
  push(ax);
  dx = 0x03ce;
  al = 0x05;
  out(dx, al);
  dx++;
  ax = pop();
  out(dx, al);
  dx = pop();
}
void sub_188e1()
{
  if (memoryAGet(ds, 0x6471) == 0x01)
    return;
  push(dx);
  push(ax);
  dx = 0x03ce;
  al = 0x08;
  out(dx, al);
  dx++;
  ax = pop();
  out(dx, al);
  dx = pop();
}
void sub_18923()
{
  if (memoryAGet(ds, 0x6471) == 0x01)
    return;
  push(dx);
  ah = al;
  dx = 0x03ce;
  al = 0x03;
  out(dx, ax);
  dx = pop();
}
void sub_18935()
{
  push(es);
  ax = cs;
  es = ax;
  dx = memoryAGet16(cs, 0x05c6);
  dx <<= 1;
  dx <<= 1;
  dx <<= 1;
  di = 0x05c8;
  cx = 0x0019;
  ax = 0;
loc_1894d:
  stosw<MemAuto, DirAuto>();
  ax += dx;
  if (--cx)
    goto loc_1894d;
  es = pop();
}
void sub_189a1()
{
  bh = 0;
  bl = dh;
  cl = 0x03;
  bx >>= cl;
  bx <<= 1;
  di = memoryAGet16(cs, bx + 1480);
  cl = dh;
  cx &= 0x0007;
  if (cx == 0)
    goto loc_189bf;
loc_189b8:
  di += memoryAGet16(cs, 0x05c6);
  if (--cx)
    goto loc_189b8;
loc_189bf:
  di += memoryAGet16(cs, 0x0320);
  bh = 0;
  bl = dl;
  di += bx;
}
void sub_189f8()
{
  push(ds);
  ax = 0x100d;
  ds = ax;
  sub_18935();
  sub_1a9bb();
  sub_186b6();
  ds = pop();
}
void sub_18a09()
{
  push(es);
  ax = 0x0040;
  es = ax;
  bx = memoryAGet16(es, 0x006c);
  cx = 0;
  ax = 0x000a;
loc_18a1b:
  if (--cx)
    goto loc_18a1b;
  ax--;
  if (ax != 0)
    goto loc_18a1b;
  ax = memoryAGet16(es, 0x006c);
  ax -= bx;
  bx = 0x0053;
  tx = ax;
  ax = bx;
  bx = tx;
  dx = 0;
  div(bx);
  if (ax)
    goto loc_18a3d;
  memoryASet16(ds, 0x5e41, 0x0001);
  goto loc_18a47;
  //   gap of 1 bytes
loc_18a3d:
  bx = 0x0bb8;
  dx = 0;
  mul(bx);
  memoryASet16(ds, 0x5e41, ax);
loc_18a47:
  es = pop();
}
void sub_18a49()
{
  memoryASet(ds, 0x42e6, 0x01);
loc_18a4e:
  bx = 0;
  bl = memoryAGet(ds, 0x42e6);
  bx--;
  bx <<= 1;
  bp = bx;
  dx = memoryAGet16(ds, bx + 24030);
  cx = 0x3e82;
  memoryASet16(ds, 0x4610, 0x0245);
  sub_1914b();
  di = 0;
  dx = memoryAGet16(ds, 0x5e04);
  ax = memoryAGet16(ds, bp + 24048);
  es = ax;
  si = 0x0247;
  sub_18a8d();
  memoryASet(ds, 0x42e6, memoryAGet(ds, 0x42e6) + 1);
  bx = 0;
  bl = memoryAGet(ds, 0x42e6);
  if ((short)bx <= (short)memoryAGet16(ds, 0x5e02))
    goto loc_18a4e;
}
void sub_18a8d()
{
  dx -= 0x0002;
loc_18a90:
  cx = 0x0001;
  lodsb<MemAuto, DirAuto>();
  ah = 0xc0;
  ah &= al;
  if (ah != 0xc0)
    goto loc_18aa5;
  ah = 0;
  al &= 0x3f;
  cx = ax;
  dx--;
  lodsb<MemAuto, DirAuto>();
loc_18aa5:
  rep_stosb<MemAuto, DirAuto>();
  dx--;
  if (dx != 0)
    goto loc_18a90;
}
void sub_18aab()
{
  cx = 0;
loc_18aad:
  al = 0;
  ah = 0x48;
  bx = 0x03e8;
  interrupt(0x21);
  if (flags.carry)
    goto loc_18acb;
  bx = cx;
  bx <<= 1;
  memoryASet16(ds, bx + 24048, ax);
  cx++;
  if (cx != 0x0009)
    goto loc_18aad;
  memoryASet16(ds, 0x5e02, cx);
  return;
loc_18acb:
  if (ax == 0x0008)
    goto loc_18ad6;
  memoryASet(ds, 0x5d9d, 0x01);
  return;
loc_18ad6:
  memoryASet16(ds, 0x5e02, cx);
  bx = cx;
  bp = bx;
  bp <<= 1;
  bp = memoryAGet16(ds, bp + 25693);
  bx--;
  bx <<= 1;
  ax = memoryAGet16(ds, bx + 24048);
  dx = memoryAGet16(ds, bx + 24072);
loc_18af0:
  bx = cx;
  bx <<= 1;
  memoryASet16(ds, bx + 24048, ax);
  memoryASet16(ds, bx + 24072, dx);
  memoryASet16(ds, bx + 25693, bp);
  cx++;
  if (cx != 0x0009)
    goto loc_18af0;
  bx = cx;
  bx <<= 1;
  memoryASet16(ds, bx + 24072, dx);
  memoryASet16(ds, bx + 25693, bp);
}
void sub_18b13()
{
  cx = memoryAGet16(ds, 0x5e02);
loc_18b17:
  bx = cx;
  bx--;
  bx <<= 1;
  ax = memoryAGet16(ds, bx + 24048);
  es = ax;
  ah = 0x49;
  interrupt(0x21);
  cx--;
  if (cx != 0)
    goto loc_18b17;
}
void sub_18b2a()
{
  di = 0x0247;
  si = 0;
  cx = 0x1f40;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
}
void sub_18b35()
{
  dx = 0x0050;
  dl -= bl;
  cx = 0;
  ah = al;
loc_18b3e:
  cl = bl;
  flags.carry = cx & 1;
  cx >>= 1;
  if (!flags.carry)
    goto loc_18b45;
  stosb<MemAuto, DirAuto>();
loc_18b45:
  rep_stosw<MemAuto, DirAuto>();
  di += dx;
  bh--;
  if (bh != 0)
    goto loc_18b3e;
}
void sub_18b4e()
{
  memoryASet16(es, di, si);
  cx = 0;
  cl = bl;
  memoryASet16(es, di + 2, cx);
  cl = bh;
  memoryASet16(es, di + 4, cx);
  di += 0x0006;
  dx = 0x0050;
  dl -= bl;
loc_18b67:
  cl = bl;
  flags.carry = cx & 1;
  cx >>= 1;
  if (!flags.carry)
    goto loc_18b6e;
  movsb<MemAuto, MemAuto, DirAuto>();
loc_18b6e:
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  si += dx;
  bh--;
  if (bh != 0)
    goto loc_18b67;
}
void sub_18b77()
{
  dx = memoryAGet16(ds, 0x4289);
  flags.carry = 0;
  dx += 0x8249 + flags.carry;
  cx = memoryAGet16(ds, 0x4289);
  cx &= 0x000f;
  dx = rcr(dx, cl);
loc_18b89:
  cx = memoryAGet16(ds, 0x4289);
  cx &= 0x1fff;
  dx += cx;
  ax = dx;
  ax &= 0x001f;
  cx = memoryAGet16(ds, 0x4289);
  cx &= 0x001f;
  if (cx != ax)
    goto loc_18bad;
  cl &= 0x0f;
  flags.carry = cl & 1;
  cl >>= 1;
  dx = rcl(dx, cl);
  goto loc_18b89;
loc_18bad:
  memoryASet16(ds, 0x4289, dx);
}
void sub_18bb2()
{
  cx = 0;
  dx = 0x03bf;
  ax = 0x0003;
  out(dx, ax);
  cl = memoryAGet(cs, 0x0001);
  dx = 0x03b4;
loc_18bc3:
  di = cx;
  al = cl;
  al--;
  out(dx, al);
  dx++;
  al = memoryAGet(cs, di + 1);
  out(dx, al);
  dx--;
  if (--cx)
    goto loc_18bc3;
  bx = es;
  di = 0;
  ax = 0;
  cx = 0xb000;
  es = cx;
  cx = 0x4000;
  rep_stosw<MemAuto, DirAuto>();
  es = bx;
  dx = 0x03b8;
  al = 0x0a;
  out(dx, al);
}
void sub_18bed()
{
  push(es);
  push(ds);
  ax = 0x100d;
  ds = ax;
  ax = 0xb000;
  es = ax;
  di = 0;
  si = memoryAGet16(ds, 0x40c7);
  bp = 0x0064;
  cx = 0;
  dl = 0x28;
  bx = 0x0050;
  ax = 0x1fb0;
loc_18c0c:
  cl = dl;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  si -= bx;
  di += ax;
  cl = dl;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di += ax;
  cl = dl;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  si -= bx;
  di += ax;
  cl = dl;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di -= 0x6000;
  bp--;
  if (bp != 0)
    goto loc_18c0c;
  ds = pop();
  es = pop();
}
void sub_18c30()
{
  push(bx);
  memoryASet(ds, 0x428f, 0x00);
  ax = memoryAGet16(ds, di);
  ax >>= 1;
  ax >>= 1;
  memoryASet16(ds, 0x463f, ax);
  bx = memoryAGet16(ds, di + 2);
  memoryASet16(ds, 0x4641, bx);
  memoryASet16(ds, 0x463d, bx);
  ax = memoryAGet16(ds, 0x462d);
  if ((short)ax >= (short)memoryAGet16(ds, 0x4631))
    goto loc_18cab;
  if ((short)ax <= (short)memoryAGet16(ds, 0x4633))
    goto loc_18cab;
  ax = memoryAGet16(ds, 0x462f);
  if ((short)ax >= (short)memoryAGet16(ds, 0x4637))
    goto loc_18cab;
  if ((short)ax <= (short)memoryAGet16(ds, 0x4635))
    goto loc_18cab;
  dx = ax;
  cx = bx;
  if ((short)ax >= 0)
    goto loc_18c93;
  bx = -bx;
  if ((short)ax <= (short)bx)
    goto loc_18cab;
  bx = -bx;
  bx += ax;
  memoryASet16(ds, 0x4641, bx);
  ax = -ax;
  cx = memoryAGet16(ds, 0x463f);
  mul(cl);
  si += ax;
  bp += ax;
  memoryASet16(ds, 0x463b, 0x0000);
  goto loc_18cad;
  //   gap of 1 bytes
loc_18c93:
  dx += cx;
  if ((short)dx < (short)memoryAGet16(ds, 0x4637))
    goto loc_18ca5;
  dx -= memoryAGet16(ds, 0x4637);
  cx -= dx;
  memoryASet16(ds, 0x4641, cx);
loc_18ca5:
  memoryASet16(ds, 0x463b, ax);
  goto loc_18cad;
  //   gap of 1 bytes
loc_18cab:
  bx = pop();
  return;
loc_18cad:
  ax = memoryAGet16(ds, 0x462d);
  dx = ax;
  cx = memoryAGet16(ds, 0x463f);
  memoryASet16(ds, 0x463d, cx);
  bx = cx;
  if ((short)ax >= 0)
    goto loc_18cdd;
  bx = -bx;
  if ((short)ax <= (short)bx)
    goto loc_18cab;
  bx = -bx;
  bx += ax;
  memoryASet16(ds, 0x463d, bx);
  ax = -ax;
  si += ax;
  bp += ax;
  memoryASet16(ds, 0x4639, 0x0000);
  goto loc_18cf2;
  //   gap of 1 bytes
loc_18cdd:
  dx += cx;
  if ((short)dx < (short)memoryAGet16(ds, 0x4631))
    goto loc_18cef;
  dx -= memoryAGet16(ds, 0x4631);
  cx -= dx;
  memoryASet16(ds, 0x463d, cx);
loc_18cef:
  memoryASet16(ds, 0x4639, ax);
loc_18cf2:
  cx = memoryAGet16(ds, 0x463f);
  cx -= memoryAGet16(ds, 0x463d);
  di = memoryAGet16(ds, 0x463b);
  di <<= 1;
  di <<= 1;
  di <<= 1;
  di <<= 1;
  bx = di;
  di <<= 1;
  di <<= 1;
  di += bx;
  di += memoryAGet16(ds, 0x4639);
  di += 0x0247;
  bx = memoryAGet16(ds, 0x463d);
  memoryASet(ds, 0x428f, 0x01);
  dx = 0x0050;
  dx -= bx;
  bx = pop();
  sub_18dcf();
  bx = memoryAGet16(ds, 0x463d);
  ax = memoryAGet16(ds, 0x4641);
  bh = al;
loc_18d31:
  ah = bl;
loc_18d33:
  lodsb<MemAuto, DirAuto>();
  al &= memoryAGet(es, di);
  al |= memoryAGet(ds, bp);
  stosb<MemAuto, DirAuto>();
  bp++;
  ah--;
  if (ah != 0)
    goto loc_18d33;
  di += dx;
  si += cx;
  bp += cx;
  bh--;
  if (bh != 0)
    goto loc_18d31;
}
void sub_18d4c()
{
  if (memoryAGet16(ds, 0x5d13) != 0x0005)
    goto loc_18d56;
  goto loc_18dc3;
  //   gap of 1 bytes
loc_18d56:
  ax = 0;
  cx = 0x0064;
  di = 0x41ba;
  rep_stosw<MemAuto, DirAuto>();
  if (memoryAGet16(ds, 0x5d13) != 0x0000)
    goto loc_18d6a;
  goto loc_18dc3;
  //   gap of 1 bytes
loc_18d6a:
  bx = memoryAGet16(ds, 0x5d13);
  bx--;
  bl = memoryAGet(ds, bx + 23841);
  di = 0x4278;
  memoryASet16(ds, 0x4306, di);
  memoryASet(ds, 0x42e6, bl);
loc_18d7e:
  memoryASet(ds, 0x5d12, 0x00);
loc_18d83:
  di = memoryAGet16(ds, 0x4306);
  sub_18b77();
  ax &= 0x000f;
  if ((short)ax <= (short)0x0009)
    goto loc_18d95;
  ax -= 0x0006;
loc_18d95:
  di += ax;
  if (memoryAGet(ds, di) != 0x00)
    goto loc_18d83;
  sub_1ab3e();
  ax &= 0x0007;
  if (ax)
    goto loc_18da7;
  ax++;
loc_18da7:
  memoryASet(ds, di, al);
  memoryASet(ds, 0x5d12, memoryAGet(ds, 0x5d12) + 1);
  if (memoryAGet(ds, 0x5d12) == 0x04)
    goto loc_18db6;
  goto loc_18d83;
loc_18db6:
  memoryASet16(ds, 0x4306, memoryAGet16(ds, 0x4306) - 0x000a);
  memoryASet(ds, 0x42e6, memoryAGet(ds, 0x42e6) - 1);
  if (memoryAGet(ds, 0x42e6) == 0)
    goto loc_18dc3;
  goto loc_18d7e;
loc_18dc3:
  si = 0x41ba;
  di = 0x40f2;
  cx = 0x0064;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
}
void sub_18dcf()
{
  push(cx);
  push(di);
  push(si);
  memoryASet16(ds, bx, di);
  si = di;
  di = bx;
  di += 0x0002;
  ax = memoryAGet16(ds, 0x463d);
  bl = al;
  stosw<MemAuto, DirAuto>();
  ax = memoryAGet16(ds, 0x4641);
  bh = al;
  stosw<MemAuto, DirAuto>();
  ch = 0;
loc_18de9:
  cl = bl;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += dx;
  bh--;
  if (bh != 0)
    goto loc_18de9;
  si = pop();
  di = pop();
  cx = pop();
}
void sub_18df7()
{
  memoryASet16(ds, 0x592e, 0x0000);
  memoryASet16(ds, 0x5930, 0x0000);
  si = 0x0247;
  dx = 0;
  bx = 0xc850;
  sub_19b30();
  sub_19a8b();
  memoryASet16(ds, 0x4637, 0x00c7);
  memoryASet16(ds, 0x4635, 0x0000);
  memoryASet16(ds, 0x4631, 0x0050);
  memoryASet16(ds, 0x4633, 0xffe3);
  memoryASet(ds, 0x42e6, 0x59);
  memoryASet16(ds, 0x42e2, 0x0050);
  memoryASet16(ds, 0x42e4, 0x0041);
loc_18e3a:
  sub_190c8();
  sub_19c06();
  sub_19bca();
  if (memoryAGet(ds, 0x428f) != 0x01)
    goto loc_18e50;
  si = 0x4fd0;
  sub_190f6();
loc_18e50:
  if (memoryAGet(ds, 0x00cf) == 0x00)
    goto loc_18e5f;
  sub_185ac();
  if (ah != 0x00)
    goto loc_18e62;
loc_18e5f:
  sub_19c18();
loc_18e62:
  if (ah != 0x1c)
    goto loc_18e6a;
  goto loc_1908f;
loc_18e6a:
  if (ah != 0x10)
    goto loc_18e75;
  memoryASet(ds, 0x5e39, 0x01);
  return;
loc_18e75:
  if (ah != 0x1f)
    goto loc_18e7f;
  memoryASet(ds, 0x5d11, memoryAGet(ds, 0x5d11) ^ 0x01);
loc_18e7f:
  memoryASet16(ds, 0x42e2, memoryAGet16(ds, 0x42e2) - 1);
  memoryASet(ds, 0x42e6, memoryAGet(ds, 0x42e6) - 1);
  if (memoryAGet(ds, 0x42e6) != 0)
    goto loc_18e3a;
  memoryASet(ds, 0x42e6, 0x0d);
  bp = 0x593a;
  memoryASet16(ds, 0x4306, 0x0000);
loc_18e97:
  di = 0x3df7;
  cx = 0x0168;
  ax = 0xffff;
  rep_stosw<MemAuto, DirAuto>();
  memoryASet16(ds, 0x42e2, 0x0001);
  memoryASet16(ds, 0x42e4, 0x00bf);
  sub_1aa67();
  if (memoryAGet(ds, 0x5e39) != 0x01)
    goto loc_18eb9;
  return;
loc_18eb9:
  if (memoryAGet16(ds, 0x4306) == 0x0000)
    goto loc_18ec3;
  goto loc_1908f;
loc_18ec3:
  if (memoryAGet(ds, 0x00cf) == 0x00)
    goto loc_18ed2;
  sub_185ac();
  if (ah != 0x00)
    goto loc_18ed5;
loc_18ed2:
  sub_19c18();
loc_18ed5:
  if (ah != 0x1c)
    goto loc_18edd;
  goto loc_1908f;
loc_18edd:
  if (ah != 0x10)
    goto loc_18ee8;
  memoryASet(ds, 0x5e39, 0x01);
  return;
loc_18ee8:
  if (ah != 0x1f)
    goto loc_18ef2;
  memoryASet(ds, 0x5d11, memoryAGet(ds, 0x5d11) ^ 0x01);
loc_18ef2:
  if (memoryAGet(ds, 0x42e6) == 0x01)
    goto loc_18f04;
  si = 0x3df7;
  di = 0x3b27;
  cx = 0x0168;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
loc_18f04:
  memoryASet(ds, 0x42e6, memoryAGet(ds, 0x42e6) - 1);
  if (memoryAGet(ds, 0x42e6) != 0)
    goto loc_18e97;
  sub_19093();
  si = 0x2547;
  memoryASet16(ds, 0x40cb, si);
  memoryASet16(ds, 0x0241, 0x0c80);
  memoryASet(ds, 0x42e6, 0x0a);
loc_18f1f:
  flags.direction = true;
  di = 0x40c6;
  si = 0x3e46;
  cx = memoryAGet16(ds, 0x0241);
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  flags.direction = false;
  di = memoryAGet16(ds, 0x40cb);
  cx = 0x0140;
  ax = 0;
  rep_stosw<MemAuto, DirAuto>();
  sub_19c06();
  cx = 0x1000;
loc_18f3e:
  if (--cx)
    goto loc_18f3e;
  sub_19bca();
  memoryASet16(ds, 0x40cb, memoryAGet16(ds, 0x40cb) + 0x0280);
  memoryASet16(ds, 0x0241, memoryAGet16(ds, 0x0241) - 0x0140);
  memoryASet(ds, 0x42e6, memoryAGet(ds, 0x42e6) - 1);
  if (memoryAGet(ds, 0x42e6) != 0)
    goto loc_18f1f;
  di = memoryAGet16(ds, 0x40cb);
  ax = 0;
  cx = 0x0140;
  rep_stosw<MemAuto, DirAuto>();
  sub_19c06();
  sub_19bca();
  memoryASet(ds, 0x4286, 0xbb);
  memoryASet(ds, 0x0246, 0x02);
  memoryASet(ds, 0x4284, 0x28);
  memoryASet(ds, 0x0245, 0x26);
  memoryASet(ds, 0x4287, 0x0d);
  memoryASet(ds, 0x42e6, 0x07);
  memoryASet16(ds, 0x0241, 0x0208);
loc_18f8a:
  bl = memoryAGet(ds, 0x0245);
  dh = memoryAGet(ds, 0x4286);
  dl = memoryAGet(ds, 0x0246);
  bh = memoryAGet(ds, 0x4287);
  si = 0x6818;
  sub_19b30();
  bh = memoryAGet(ds, 0x4287);
  dl = memoryAGet(ds, 0x4284);
  si = 0x6de2;
  sub_19b30();
  sub_19c06();
  sub_19bca();
  if (memoryAGet(ds, 0x42e6) == 0x01)
    goto loc_18fe7;
  dh = memoryAGet(ds, 0x4286);
  dl = 0x02;
  bh = memoryAGet(ds, 0x4287);
  bl = 0x4c;
  sub_1a802();
  memoryASet(ds, 0x4286, memoryAGet(ds, 0x4286) - 0x0d);
  if (memoryAGet(ds, 0x42e6) != 0x02)
    goto loc_18fdb;
  memoryASet(ds, 0x4286, memoryAGet(ds, 0x4286) + 0x02);
loc_18fdb:
  if ((char)memoryAGet(ds, 0x42e6) <= (char)0x05)
    goto loc_18fe7;
  memoryASet(ds, 0x4287, memoryAGet(ds, 0x4287) + 0x0d);
loc_18fe7:
  memoryASet(ds, 0x42e6, memoryAGet(ds, 0x42e6) - 1);
  if (memoryAGet(ds, 0x42e6) != 0)
    goto loc_18f8a;
  sub_19093();
loc_18ff0:
  memoryASet(ds, 0x42e6, 0x75);
  memoryASet16(ds, 0x42e2, 0x0050);
  memoryASet16(ds, 0x42e4, 0x0041);
  memoryASet16(ds, 0x44de, 0x0058);
loc_19007:
  sub_190c8();
  al = memoryAGet(ds, 0x428f);
  memoryASet(ds, 0x4287, al);
  sub_1909a();
  sub_19c06();
  sub_19bca();
  if (memoryAGet(ds, 0x428f) != 0x01)
    goto loc_1902b;
  si = 0x5107;
  sub_190f6();
  cx = 0x0064;
loc_19029:
  if (--cx)
    goto loc_19029;
loc_1902b:
  if (memoryAGet(ds, 0x4287) != 0x01)
    goto loc_19038;
  si = 0x4fd0;
  sub_190f6();
loc_19038:
  if (memoryAGet(ds, 0x00cf) == 0x00)
    goto loc_19047;
  sub_185ac();
  if (ah != 0x00)
    goto loc_1904a;
loc_19047:
  sub_19c18();
loc_1904a:
  if (ah != 0x1f)
    goto loc_19054;
  memoryASet(ds, 0x5d11, memoryAGet(ds, 0x5d11) ^ 0x01);
loc_19054:
  if (ah != 0x10)
    goto loc_1905f;
  memoryASet(ds, 0x5e39, 0x01);
  return;
loc_1905f:
  if (ah == 0xff)
    goto loc_19067;
  goto loc_1908f;
  //   gap of 1 bytes
loc_19067:
  memoryASet16(ds, 0x42e2, memoryAGet16(ds, 0x42e2) - 1);
  memoryASet16(ds, 0x44de, memoryAGet16(ds, 0x44de) - 1);
  memoryASet(ds, 0x42e6, memoryAGet(ds, 0x42e6) - 1);
  if (memoryAGet(ds, 0x42e6) != 0)
    goto loc_19007;
  if (memoryAGet(ds, 0x00cf) == 0x00)
    goto loc_19084;
  sub_185ac();
  if (ah != 0x00)
    goto loc_19087;
loc_19084:
  sub_19c18();
loc_19087:
  if (ah != 0xff)
    goto loc_1908f;
  goto loc_18ff0;
loc_1908f:
  sub_193c1();
}
void sub_19093()
{
  dx = 0x7d00;
loc_19096:
  dx--;
  if (dx != 0)
    goto loc_19096;
}
void sub_1909a()
{
  ax = memoryAGet16(ds, 0x44de);
  memoryASet16(ds, 0x462d, ax);
  ax = memoryAGet16(ds, 0x42e4);
  memoryASet16(ds, 0x462f, ax);
  bx = memoryAGet16(ds, 0x5930);
  bx ^= 0x0001;
  memoryASet16(ds, 0x5930, bx);
  bx <<= 1;
  di = memoryAGet16(ds, bx + 22834);
  bp = memoryAGet16(ds, bx + 22838);
  si = di;
  si += 0x0004;
  bx = 0x5107;
  sub_18c30();
}
void sub_190c8()
{
  ax = memoryAGet16(ds, 0x42e2);
  memoryASet16(ds, 0x462d, ax);
  ax = memoryAGet16(ds, 0x42e4);
  memoryASet16(ds, 0x462f, ax);
  bx = memoryAGet16(ds, 0x592e);
  bx ^= 0x0001;
  memoryASet16(ds, 0x592e, bx);
  bx <<= 1;
  di = memoryAGet16(ds, bx + 22822);
  bp = memoryAGet16(ds, bx + 22826);
  si = di;
  si += 0x0004;
  bx = 0x4fd0;
  sub_18c30();
}
void sub_190f6()
{
  lodsw<MemAuto, DirAuto>();
  di = ax;
  dx = 0x0050;
  lodsw<MemAuto, DirAuto>();
  dx -= ax;
  bl = al;
  lodsw<MemAuto, DirAuto>();
  bh = al;
  ch = 0;
loc_19106:
  cl = bl;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di += dx;
  bh--;
  if (bh != 0)
    goto loc_19106;
}
void sub_19111()
{
  push(ds);
  push(es);
  ax = 0xa000;
  es = ax;
  ds = ax;
  di = si;
  si += 0x3e80;
  di += memoryAGet16(cs, 0x0320);
  push(bx);
  bh = 0;
  dx = memoryAGet16(cs, 0x05c6);
  dx -= bx;
  al = 0x01;
  sub_188cd();
  al = 0x0f;
  sub_188e1();
  bx = pop();
  ch = 0;
loc_1913c:
  cl = bl;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += dx;
  di += dx;
  bh--;
  if (bh != 0)
    goto loc_1913c;
  es = pop();
  ds = pop();
}
void sub_1914b()
{
  al = 0;
  ah = 0x3d;
  interrupt(0x21);
  memoryASet16(ds, 0x460e, ax);
  bx = memoryAGet16(ds, 0x460e);
  dx = memoryAGet16(ds, 0x4610);
  ah = 0x3f;
  interrupt(0x21);
  memoryASet16(ds, 0x5e04, ax);
  bx = memoryAGet16(ds, 0x460e);
  ah = 0x3e;
  interrupt(0x21);
}
void sub_1916c()
{
  if (memoryAGet(cs, 0x0000) != 0x01)
    goto loc_19175;
  return;
loc_19175:
  dx = 0x03d8;
  al = 0x0e;
  out(dx, al);
  dx++;
  al = 0x00;
  out(dx, al);
}
void sub_1918b()
{
//  if (memoryAGet(ds, 0x5d11) != 0x01)
//    goto loc_19193;
  return;
loc_19193:
  push(bp);
  push(bx);
  push(dx);
  bx = memoryAGet16(ds, si);
  dx = memoryAGet16(ds, si + 2);
  bp = memoryAGet16(ds, si + 4);
  in(al, 0x61);
  al &= 0xfe;
loc_191a2:
  al |= 0x02;
  out(0x0061, al);
  cx = bx;
loc_191a8:
  if (--cx)
    goto loc_191a8;
  al &= 0xfd;
  out(0x0061, al);
  bx += bp;
  cx = bx;
loc_191b2:
  if (--cx)
    goto loc_191b2;
  dx--;
  if ((short)dx >= 0)
    goto loc_191a2;
  dx = pop();
  bx = pop();
  bp = pop();
}
void sub_192a7()
{
  si = 0x45d0;
  sub_1918b();
  cx = 0x0600;
loc_192b0:
  if (--cx)
    goto loc_192b0;
  si = 0x45d6;
  sub_1918b();
  dl = 0x0f;
  dh = 0x0a;
  bl = 0x01;
  bh = 0x08;
  memoryASet16(cs, 0x031c, 0x000a);
loc_192c7:
  push(bx);
  push(dx);
  si = 0x5dc8;
  sub_19b5c();
  dx = pop();
  bx = pop();
  dl++;
  memoryASet16(cs, 0x031c, memoryAGet16(cs, 0x031c) - 1);
  if (memoryAGet16(cs, 0x031c) != 0)
    goto loc_192c7;
  push(es);
  push(ds);
  ax = 0xa000;
  ds = ax;
  es = ax;
  al = 0x01;
  sub_188cd();
  al = 0x0f;
  sub_188b9();
  al = 0xff;
  sub_188e1();
  si = 0x019f;
  memoryASet16(cs, 0x0324, si);
  di = 0x195f;
  memoryASet16(cs, 0x1022, di);
  si += memoryAGet16(cs, 0x0320);
  di += memoryAGet16(cs, 0x0320);
  bx = 0x0008;
loc_19310:
  cx = 0x000a;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x001e;
  di += 0x001e;
  bx--;
  if (bx != 0)
    goto loc_19310;
  sub_18768();
  memoryASet16(cs, 0x031c, 0x0009);
loc_19328:
  si = memoryAGet16(cs, 0x0324);
  si += memoryAGet16(cs, 0x0320);
  di = si;
  di += 0x0140;
  bx = 0x0008;
loc_1933b:
  cx = 0x000a;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x001e;
  di += 0x001e;
  bx--;
  if (bx != 0)
    goto loc_1933b;
  si = memoryAGet16(cs, 0x1022);
  si += memoryAGet16(cs, 0x0320);
  di = si;
  di -= 0x0140;
  bx = 0x0008;
loc_1935c:
  cx = 0x000a;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si += 0x001e;
  di += 0x001e;
  bx--;
  if (bx != 0)
    goto loc_1935c;
  sub_18768();
  memoryASet16(cs, 0x0324, memoryAGet16(cs, 0x0324) + 0x0140);
  memoryASet16(cs, 0x1022, memoryAGet16(cs, 0x1022) - 0x0140);
  memoryASet16(cs, 0x031c, memoryAGet16(cs, 0x031c) - 1);
  if (memoryAGet16(cs, 0x031c) != 0)
    goto loc_19328;
  ds = pop();
  es = pop();
  si = 0x0cdf;
  bx = 0x080a;
  sub_19111();
  memoryASet16(cs, 0x2018, 0x0052);
  memoryASet16(cs, 0x2016, 0x000f);
  bp = 0x43d3;
  memoryASet(cs, 0x201b, 0x0f);
  sub_1a9d8();
  sub_18768();
  sub_193b4();
  sub_1a699();
}
void sub_193b4()
{
  dx = 0x005a;
loc_193b7:
  ax = 0x1fff;
loc_193ba:
  ax--;
  if (ax != 0)
    goto loc_193ba;
  dx--;
  if (dx != 0)
    goto loc_193b7;
}
void sub_193c1()
{
  push(ds);
  push(es);
  ax = 0x100d;
  ds = ax;
  es = ax;
  cx = 0x1f40;
  ax = 0x0000;
  di = 0x0247;
  rep_stosw<MemAuto, DirAuto>();
  memoryASet16(ds, 0x5d25, 0xaaaa);
  bp = 0x5aef;
  memoryASet16(ds, 0x42e2, 0x0006);
  memoryASet(ds, 0x42e6, 0x12);
  memoryASet16(ds, 0x42e4, 0x0018);
loc_193ef:
  sub_1a947();
  push(bp);
  push(ds);
  push(es);
  sub_19c06();
  sub_19bca();
  es = pop();
  ds = pop();
  si = 0x45c4;
  sub_1918b();
  bp = pop();
  memoryASet16(ds, 0x42e4, memoryAGet16(ds, 0x42e4) + 0x0008);
  memoryASet(ds, 0x42e6, memoryAGet(ds, 0x42e6) - 1);
  if (memoryAGet(ds, 0x42e6) != 0)
    goto loc_193ef;
loc_1940f:
  push(ds);
  push(es);
  sub_19c06();
  sub_19bca();
  es = pop();
  ds = pop();
  if (memoryAGet(ds, 0x00cf) == 0x00)
    goto loc_19428;
  sub_185ac();
  if (ah != 0x00)
    goto loc_1942b;
loc_19428:
  sub_19c18();
loc_1942b:
  if (ah != 0x1c)
    goto loc_1940f;
  es = pop();
  ds = pop();
}
void sub_19433()
{
  dx = 0x5dda;
  cx = 0x3e82;
  memoryASet16(ds, 0x4610, 0x0245);
  sub_1914b();
  sub_19645();
loc_19445:
  sub_19c06();
  sub_19bca();
  if (memoryAGet(ds, 0x00cf) == 0x00)
    goto loc_1945a;
  sub_185ac();
  if (ah != 0x00)
    goto loc_1945d;
loc_1945a:
  sub_19c18();
loc_1945d:
  if (ah == 0xff)
    goto loc_19445;
  if (ah != 0x10)
    goto loc_1946d;
  memoryASet(ds, 0x5e39, 0x01);
  return;
loc_1946d:
  if (ah != 0x1f)
    goto loc_19479;
  memoryASet(ds, 0x5d11, memoryAGet(ds, 0x5d11) ^ 0x01);
  goto loc_19445;
loc_19479:
  if (ah != 0x13)
    goto loc_19483;
  sub_1966e();
  goto loc_19445;
loc_19483:
  if (ah != 0x01)
    goto loc_19495;
  sub_1a4c8();
  if (memoryAGet(ds, 0x5e39) != 0x01)
    goto loc_19493;
  return;
loc_19493:
  goto loc_19445;
loc_19495:
  memoryASet(ds, 0x0245, ah);
  sub_19645();
  ah = memoryAGet(ds, 0x0245);
  if (ah != 0x4b)
    goto loc_194bc;
loc_194a5:
  if ((short)memoryAGet16(ds, 0x40c9) > (short)0x0000)
    goto loc_194b5;
  memoryASet16(ds, 0x40c9, 0x0009);
  goto loc_1953a;
loc_194b5:
  memoryASet16(ds, 0x40c9, memoryAGet16(ds, 0x40c9) - 1);
  goto loc_1953a;
  //   gap of 1 bytes
loc_194bc:
  if (ah == 0x24)
    goto loc_194a5;
  if (ah != 0x4d)
    goto loc_194dd;
loc_194c6:
  if ((short)memoryAGet16(ds, 0x40c9) < (short)0x0009)
    goto loc_194d6;
  memoryASet16(ds, 0x40c9, 0x0000);
  goto loc_1953a;
  //   gap of 1 bytes
loc_194d6:
  memoryASet16(ds, 0x40c9, memoryAGet16(ds, 0x40c9) + 1);
  goto loc_1953a;
  //   gap of 1 bytes
loc_194dd:
  if (ah == 0x26)
    goto loc_194c6;
  if (ah == 0x48)
    goto loc_194f1;
  if (ah == 0x17)
    goto loc_194f1;
  if (ah != 0x50)
    goto loc_19505;
loc_194f1:
  ax = memoryAGet16(ds, 0x40c9);
  ax -= 0x0005;
  if (!(ax & 0x8000))
    goto loc_194ff;
  ax += 0x000a;
loc_194ff:
  memoryASet16(ds, 0x40c9, ax);
  goto loc_1953a;
  //   gap of 1 bytes
loc_19505:
  if (ah == 0x32)
    goto loc_194f1;
  if (ah != 0x0b)
    goto loc_19518;
  memoryASet16(ds, 0x40c9, 0x0000);
  goto loc_1953a;
  //   gap of 1 bytes
loc_19518:
  if (ah == 0x1c)
    goto loc_19540;
  if (ah == 0x39)
    goto loc_19540;
  if ((char)ah >= (char)0x02)
    goto loc_1952a;
  goto loc_1953a;
  //   gap of 1 bytes
loc_1952a:
  if ((char)ah <= (char)0x0a)
    goto loc_19532;
  goto loc_1953a;
  //   gap of 1 bytes
loc_19532:
  al = ah;
  ah = 0;
  ax--;
  memoryASet16(ds, 0x40c9, ax);
loc_1953a:
  sub_19645();
  goto loc_19445;
loc_19540:
  sub_19645();
  sub_1961f();
loc_19546:
  sub_19c06();
  sub_19bca();
  if (memoryAGet(ds, 0x00cf) == 0x00)
    goto loc_1955b;
  sub_185ac();
  if (ah != 0x00)
    goto loc_1955e;
loc_1955b:
  sub_19c18();
loc_1955e:
  if (ah == 0xff)
    goto loc_19546;
  if (ah != 0x10)
    goto loc_1956e;
  memoryASet(ds, 0x5e39, 0x01);
  return;
loc_1956e:
  if (ah != 0x1f)
    goto loc_1957a;
  memoryASet(ds, 0x5d11, memoryAGet(ds, 0x5d11) ^ 0x01);
  goto loc_19546;
loc_1957a:
  if (ah != 0x13)
    goto loc_19584;
  sub_1966e();
  goto loc_19546;
loc_19584:
  if (ah != 0x01)
    goto loc_19596;
  sub_1a4c8();
  if (memoryAGet(ds, 0x5e39) != 0x01)
    goto loc_19594;
  return;
loc_19594:
  goto loc_19546;
loc_19596:
  memoryASet(ds, 0x0245, ah);
  sub_1961f();
  ah = memoryAGet(ds, 0x0245);
  if (ah != 0x4b)
    goto loc_195bd;
loc_195a6:
  if ((short)memoryAGet16(ds, 0x5d13) > (short)0x0000)
    goto loc_195b6;
  memoryASet16(ds, 0x5d13, 0x0005);
  goto loc_19615;
  //   gap of 1 bytes
loc_195b6:
  memoryASet16(ds, 0x5d13, memoryAGet16(ds, 0x5d13) - 1);
  goto loc_19615;
  //   gap of 1 bytes
loc_195bd:
  if (ah == 0x24)
    goto loc_195a6;
  if (ah != 0x4d)
    goto loc_195de;
loc_195c7:
  if ((short)memoryAGet16(ds, 0x5d13) < (short)0x0005)
    goto loc_195d7;
  memoryASet16(ds, 0x5d13, 0x0000);
  goto loc_19615;
  //   gap of 1 bytes
loc_195d7:
  memoryASet16(ds, 0x5d13, memoryAGet16(ds, 0x5d13) + 1);
  goto loc_19615;
  //   gap of 1 bytes
loc_195de:
  if (ah == 0x26)
    goto loc_195c7;
  if (ah == 0x48)
    goto loc_195f2;
  if (ah == 0x17)
    goto loc_195f2;
  if (ah != 0x50)
    goto loc_19606;
loc_195f2:
  ax = memoryAGet16(ds, 0x5d13);
  ax -= 0x0003;
  if (!(ax & 0x8000))
    goto loc_19600;
  ax += 0x0006;
loc_19600:
  memoryASet16(ds, 0x5d13, ax);
  goto loc_19615;
  //   gap of 1 bytes
loc_19606:
  if (ah == 0x32)
    goto loc_195f2;
  if (ah == 0x1c)
    goto loc_1961b;
  if (ah == 0x39)
    goto loc_1961b;
loc_19615:
  sub_1961f();
  goto loc_19546;
loc_1961b:
  sub_18d4c();
}
void sub_1961f()
{
  bx = memoryAGet16(ds, 0x5d13);
  bx <<= 1;
  di = memoryAGet16(ds, bx + 23829);
  bx = 0x0014;
  ax = 0xff3f;
loc_1962f:
  memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
  memoryASet16(es, di + 2, memoryAGet16(es, di + 2) ^ 0xffff);
  memoryASet16(es, di + 4, memoryAGet16(es, di + 4) ^ 0xffff);
  di += 0x0050;
  bx--;
  if (bx != 0)
    goto loc_1962f;
}
void sub_19645()
{
  bx = memoryAGet16(ds, 0x40c9);
  bx <<= 1;
  di = 0x0247;
  di += memoryAGet16(ds, bx + 17168);
  bx = 0x0014;
  ax = 0xff3f;
loc_19658:
  memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
  memoryASet16(es, di + 2, memoryAGet16(es, di + 2) ^ 0xffff);
  memoryASet16(es, di + 4, memoryAGet16(es, di + 4) ^ 0xffff);
  di += 0x0050;
  bx--;
  if (bx != 0)
    goto loc_19658;
}
void sub_1966e()
{
  di = 0x4643;
  si = 0x2823;
  bl = 0x38;
  bh = 0x0f;
  sub_18b4e();
  memoryASet16(ds, 0x5d25, 0xffff);
  di = 0x2823;
  bl = 0x38;
  bh = 0x0f;
  al = 0;
  sub_18b35();
  di = 0x2873;
  bl = 0x38;
  bh = 0x0d;
  sub_1a04f();
  memoryASet16(ds, 0x42e2, 0x000f);
  memoryASet16(ds, 0x42e4, 0x007c);
  bp = 0x5e1e;
  sub_1a947();
loc_196a9:
  sub_19c06();
  sub_19bca();
  sub_19c18();
  if (ah != 0x31)
    goto loc_196ba;
  goto loc_196f2;
  //   gap of 1 bytes
loc_196ba:
  if (ah == 0x15)
    goto loc_196c1;
  goto loc_196a9;
loc_196c1:
  di = 0x44f0;
  bx = 0x000a;
loc_196c7:
  cx = 0x000f;
  si = 0x44e0;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  ax = 0;
  stosw<MemAuto, DirAuto>();
  stosw<MemAuto, DirAuto>();
  di++;
  bx--;
  if (bx != 0)
    goto loc_196c7;
  dx = 0x44d7;
  al = 0x02;
  ah = 0x3d;
  interrupt(0x21);
  bx = ax;
  dx = 0x44ef;
  cx = 0x00c8;
  al = 0;
  ah = 0x40;
  interrupt(0x21);
  ah = 0x3e;
  interrupt(0x21);
loc_196f2:
  si = 0x4643;
  sub_190f6();
}
void sub_196f9()
{
  ax = 0;
  memoryASet(ds, 0x5e3a, al);
  memoryASet(ds, 0x62ef, al);
  memoryASet(ds, 0x42e8, al);
  memoryASet16(ds, 0x0140, ax);
  memoryASet16(ds, 0x5d13, ax);
  memoryASet16(ds, 0x40e8, ax);
  memoryASet16(ds, 0x40f0, ax);
  memoryASet16(ds, 0x40c9, 0x0005);
  cx = 0x0007;
  di = 0x40d3;
  rep_stosw<MemAuto, DirAuto>();
  cx = 0x0007;
  di = 0x40e1;
  rep_stosb<MemAuto, DirAuto>();
  memoryASet(ds, 0x4288, al);
  memoryASet16(ds, 0x40cb, ax);
  memoryASet(ds, 0x5d10, 0x00);
  memoryASet(ds, 0x5e06, 0x00);
  memoryASet(ds, 0x5e07, 0x00);
}
void sub_1973c()
{
  dx = 0x44d7;
  al = 0;
  ah = 0x3d;
  interrupt(0x21);
  bx = ax;
  cx = 0x00c8;
  dx = 0x44ef;
  ah = 0x3f;
  interrupt(0x21);
  ah = 0x3e;
  interrupt(0x21);
  memoryASet16(ds, 0x45b7, 0x0000);
  sub_19c38();
  memoryASet16(ds, 0x5d25, 0xaaaa);
  memoryASet16(ds, 0x42e2, 0x0018);
  memoryASet16(ds, 0x42e4, 0x0017);
  bp = 0x4402;
  sub_1a947();
  di = 0x105d;
  ax = 0xaaaa;
  cx = 0x0022;
  rep_stosw<MemAuto, DirAuto>();
  di = 0x3a3d;
  cx = 0x0022;
  rep_stosw<MemAuto, DirAuto>();
  ax = memoryAGet16(ds, 0x40cb);
  memoryASet16(ds, 0x44de, ax);
  cx = 0x000a;
  si = 0x44ff;
loc_19795:
  if (ax >= memoryAGet16(ds, si))
    goto loc_197a1;
  si += 0x0014;
  if (--cx)
    goto loc_19795;
  goto loc_197db;
  //   gap of 1 bytes
loc_197a1:
  push(si);
  dl = 0x0a;
  dl -= cl;
  memoryASet(ds, 0x45b9, dl);
  cx--;
  if (cx == 0)
    goto loc_197c3;
  si = 0x45a2;
  di = si;
  di += 0x0014;
loc_197b5:
  dl = 0x14;
loc_197b7:
  dh = memoryAGet(ds, si);
  memoryASet(ds, di, dh);
  si--;
  di--;
  dl--;
  if (dl != 0)
    goto loc_197b7;
  if (--cx)
    goto loc_197b5;
loc_197c3:
  si = pop();
  memoryASet16(ds, si, ax);
  cx = memoryAGet16(ds, 0x40c9);
  memoryASet16(ds, si + 2, cx);
  cx = 0x000f;
  dh = 0x20;
loc_197d2:
  si--;
  memoryASet(ds, si, dh);
  if (--cx)
    goto loc_197d2;
  memoryASet16(ds, 0x45b7, si);
loc_197db:
  memoryASet(ds, 0x45ba, 0x00);
  memoryASet(ds, 0x45bb, 0x0e);
  memoryASet16(es, 0x42e4, 0x0037);
  cx = 0x000a;
  bp = 0x44ef;
loc_197f2:
  push(cx);
  memoryASet16(es, 0x42e2, 0x000e);
  sub_1a947();
  si = bp;
  bp += 0x0002;
  push(bp);
  di = 0x40d3;
  dl = 0x05;
  dh = 0x20;
loc_1980a:
  di--;
  memoryASet(ds, di, dh);
  dl--;
  if (dl != 0)
    goto loc_1980a;
  memoryASet16(ds, 0x0241, 0x0005);
  sub_1a7d2();
  memoryASet16(es, 0x42e2, memoryAGet16(es, 0x42e2) + 0x002e);
  bp = 0x40cd;
  sub_1a947();
  bp = pop();
  si = bp;
  bp += 0x0002;
  push(bp);
  di = 0x45bd;
  memoryASet(ds, di, 0x20);
  memoryASet16(ds, 0x0241, 0x0001);
  sub_1a7d2();
  memoryASet16(ds, 0x42e2, memoryAGet16(ds, 0x42e2) - 0x0007);
  bp = 0x45bc;
  sub_1a947();
  memoryASet16(es, 0x42e4, memoryAGet16(es, 0x42e4) + 0x000c);
  bp = pop();
  cx = pop();
  if (--cx)
    goto loc_197f2;
  memoryASet16(ds, 0x42e4, 0x0037);
  memoryASet16(ds, 0x42e2, 0x0008);
  memoryASet(ds, 0x42e6, 0x01);
  memoryASet16(ds, 0x0241, 0x0002);
loc_19868:
  si = 0x42e6;
  di = 0x44d4;
  sub_1a7d2();
  bp = 0x44d3;
  sub_1a947();
  memoryASet16(ds, 0x42e4, memoryAGet16(ds, 0x42e4) + 0x000c);
  memoryASet(ds, 0x42e6, memoryAGet(ds, 0x42e6) + 1);
  if (memoryAGet(ds, 0x42e6) != 0x0b)
    goto loc_19868;
loc_19887:
  memoryASet16(es, 0x42e4, 0x0037);
  cx = 0;
  cl = memoryAGet(ds, 0x45b9);
  bp = 0x44ef;
  memoryASet16(es, 0x42e2, 0x000e);
  if (cl == 0x00)
    goto loc_198ae;
loc_198a3:
  bp += 0x0014;
  memoryASet16(es, 0x42e4, memoryAGet16(es, 0x42e4) + 0x000c);
  if (--cx)
    goto loc_198a3;
loc_198ae:
  ax = memoryAGet16(es, 0x42e4);
  cl = 0x04;
  ax <<= cl;
  di = ax;
  ax <<= 1;
  ax <<= 1;
  di += ax;
  di += memoryAGet16(es, 0x42e2);
  di += 0x0247;
  bx = 0x0008;
  ax = 0;
loc_198cc:
  cx = 0x0010;
  rep_stosw<MemAuto, DirAuto>();
  di += 0x0030;
  bx--;
  if (bx != 0)
    goto loc_198cc;
  sub_1a947();
  if (memoryAGet16(ds, 0x45b7) != 0x0000)
    goto loc_198e4;
  goto loc_19992;
loc_198e4:
  ax = 0x0037;
  cx = 0;
  cl = memoryAGet(ds, 0x45b9);
  if (cl == 0x00)
    goto loc_198f7;
loc_198f2:
  ax += 0x000c;
  if (--cx)
    goto loc_198f2;
loc_198f7:
  cl = 0x04;
  dx = 0;
  dl = memoryAGet(ds, 0x45bb);
  ax <<= cl;
  di = ax;
  ax <<= 1;
  ax <<= 1;
  di += ax;
  di += dx;
  di += 0x0247;
  push(di);
  cx = 0x0008;
loc_19913:
  memoryASet16(es, di, memoryAGet16(es, di) ^ 0xffff);
  di += 0x0050;
  if (--cx)
    goto loc_19913;
  push(ds);
  push(es);
  sub_19c06();
  sub_19bca();
  es = pop();
  ds = pop();
  di = pop();
  cx = 0x0008;
loc_1992b:
  memoryASet16(es, di, memoryAGet16(es, di) ^ 0xffff);
  di += 0x0050;
  if (--cx)
    goto loc_1992b;
  push(ds);
  push(es);
  sub_19c06();
  sub_19bca();
  sub_19c18();
  es = pop();
  ds = pop();
  si = memoryAGet16(ds, 0x45b7);
  if (ah == 0xff)
    goto loc_1996d;
  if (ah == 0x4b)
    goto loc_19955;
  if (ah != 0x0e)
    goto loc_19970;
loc_19955:
  if (memoryAGet(ds, 0x45bb) == 0x0e)
    goto loc_1996d;
  si--;
  memoryASet(ds, 0x45ba, memoryAGet(ds, 0x45ba) - 1);
  memoryASet(ds, si, 0x20);
  memoryASet(ds, 0x45bb, memoryAGet(ds, 0x45bb) - 0x02);
  memoryASet16(ds, 0x45b7, si);
loc_1996d:
  goto loc_19887;
loc_19970:
  if (ah == 0x1c)
    goto loc_19992;
  if ((char)memoryAGet(ds, 0x45ba) >= (char)0x0f)
    goto loc_1998f;
  memoryASet(ds, si, al);
  memoryASet(ds, 0x45ba, memoryAGet(ds, 0x45ba) + 1);
  si++;
  memoryASet16(ds, 0x45b7, si);
  memoryASet(ds, 0x45bb, memoryAGet(ds, 0x45bb) + 0x02);
  goto loc_19887;
loc_1998f:
  goto loc_198e4;
loc_19992:
  dx = 0x44d7;
  al = 0x02;
  ah = 0x3d;
  interrupt(0x21);
  bx = ax;
  dx = 0x44ef;
  cx = 0x00c8;
  al = 0;
  ah = 0x40;
  interrupt(0x21);
  ah = 0x3e;
  interrupt(0x21);
}
void sub_19a02()
{
  memoryASet(ds, 0x5d97, 0x01);
  ax = 0xb000;
  es = ax;
  ch = 0;
  memoryASet(ds, 0x5d99, 0x50);
  memoryASet16(ds, 0x4610, 0x02e6);
  memoryASet16(ds, 0x5d9a, 0x004f);
loc_19a1f:
  bx = 0x0247;
  bp = memoryAGet16(ds, 0x4610);
  di = memoryAGet16(ds, 0x5d9a);
  ax = 0x4000;
  memoryASet(ds, 0x5d98, 0x64);
loc_19a32:
  push(di);
  push(di);
  si = bx;
  cl = memoryAGet(ds, 0x5d97);
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  cl = memoryAGet(ds, 0x5d97);
  si -= cx;
  di = pop();
  di += 0x2000;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si = bp;
  di = ax;
  cl = memoryAGet(ds, 0x5d97);
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si = bp;
  di = ax;
  di += 0x2000;
  cl = memoryAGet(ds, 0x5d97);
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  bx += 0x00a0;
  bp += 0x00a0;
  di = pop();
  ax += 0x0050;
  di += 0x0050;
  memoryASet(ds, 0x5d98, memoryAGet(ds, 0x5d98) - 1);
  if (memoryAGet(ds, 0x5d98) != 0)
    goto loc_19a32;
  memoryASet(ds, 0x5d97, memoryAGet(ds, 0x5d97) + 1);
  memoryASet(ds, 0x5d99, memoryAGet(ds, 0x5d99) - 1);
  if (memoryAGet(ds, 0x5d99) == 0)
    return;
  memoryASet16(ds, 0x5d9a, memoryAGet16(ds, 0x5d9a) - 1);
  memoryASet16(ds, 0x4610, memoryAGet16(ds, 0x4610) - 1);
  goto loc_19a1f;
}
void sub_19a8b()
{
  push(es);
  if (memoryAGet(cs, 0x0000) != 0x01)
    goto loc_19a99;
  sub_19a02();
  es = pop();
  return;
loc_19a99:
  memoryASet(ds, 0x5d97, 0x01);
  ax = 0xb800;
  es = ax;
  ch = 0;
  memoryASet(ds, 0x5d99, 0x50);
  memoryASet16(ds, 0x4610, 0x02e6);
  memoryASet16(ds, 0x5d9a, 0x004f);
loc_19ab6:
  bx = 0x0247;
  bp = memoryAGet16(ds, 0x4610);
  di = memoryAGet16(ds, 0x5d9a);
  ax = 0x2000;
  memoryASet(ds, 0x5d98, 0x64);
loc_19ac9:
  push(di);
  si = bx;
  cl = memoryAGet(ds, 0x5d97);
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  si = bp;
  di = ax;
  cl = memoryAGet(ds, 0x5d97);
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  bx += 0x00a0;
  bp += 0x00a0;
  di = pop();
  ax += 0x0050;
  di += 0x0050;
  memoryASet(ds, 0x5d98, memoryAGet(ds, 0x5d98) - 1);
  if (memoryAGet(ds, 0x5d98) != 0)
    goto loc_19ac9;
  memoryASet(ds, 0x5d97, memoryAGet(ds, 0x5d97) + 1);
  memoryASet(ds, 0x5d99, memoryAGet(ds, 0x5d99) - 1);
  if (memoryAGet(ds, 0x5d99) == 0)
    goto loc_19b05;
  memoryASet16(ds, 0x5d9a, memoryAGet16(ds, 0x5d9a) - 1);
  memoryASet16(ds, 0x4610, memoryAGet16(ds, 0x4610) - 1);
  goto loc_19ab6;
loc_19b05:
  es = pop();
}
void sub_19b30()
{
  ax = 0;
  al = dl;
  di = ax;
  al = dh;
  cl = 0x04;
  ax <<= cl;
  di += ax;
  ax <<= 1;
  ax <<= 1;
  di += ax;
  di += 0x0247;
  cx = 0;
  cl = bl;
  bp = 0x0050;
  bp -= cx;
loc_19b51:
  cl = bl;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di += bp;
  bh--;
  if (bh != 0)
    goto loc_19b51;
}
void sub_19b5c()
{
  push(es);
  push(ds);
  ax = 0xa000;
  es = ax;
  ds = ax;
  push(bx);
  sub_189a1();
  al = 0x01;
  sub_188cd();
  al = 0xff;
  sub_188e1();
  al = 0x0f;
  sub_188b9();
  bx = pop();
  dx = memoryAGet16(cs, 0x05c6);
  ch = 0;
  cl = bl;
  dx -= cx;
loc_19b84:
  cl = bl;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  di += dx;
  bh--;
  if (bh != 0)
    goto loc_19b84;
  ds = pop();
  es = pop();
}
void sub_19bca()
{
  push(es);
  if (memoryAGet(cs, 0x0000) != 0x01)
    goto loc_19bd8;
  sub_18bed();
  es = pop();
  return;
loc_19bd8:
  dx = ds;
  ax = 0x100d;
  ds = ax;
  si = 0x0247;
  di = 0;
  ax = 0xb800;
  es = ax;
  bp = 0x0028;
  bx = 0x0064;
loc_19bef:
  cx = bp;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  cx = bp;
  di += 0x1fb0;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  di -= 0x2000;
  bx--;
  if (bx != 0)
    goto loc_19bef;
  ds = dx;
  es = pop();
}
void sub_19c06()
{
  if (memoryAGet16(ds, 0x5e41) == 0x0001)
    return;
  cx = memoryAGet16(ds, 0x5e41);
loc_19c13:
  if (--cx)
    goto loc_19c13;
}
void sub_19c18()
{
  push(es);
  ah = 0x01;
  interrupt(0x16);
  if (!flags.zero)
    goto loc_19c24;
  ah = 0xff;
  goto loc_19c28;
  //   gap of 1 bytes
loc_19c24:
  ah = 0;
  interrupt(0x16);
loc_19c28:
  bx = 0;
  es = bx;
  bx = memoryAGet16(es, 0x041a);
  memoryASet16(es, 0x041c, bx);
  es = pop();
}
void sub_19c38()
{
  cx = 0x1f40;
  ax = 0;
  di = 0x0247;
  rep_stosw<MemAuto, DirAuto>();
}
void sub_19c43()
{
  push(es);
  ax = 0x0040;
  es = ax;
  if (memoryAGet(es, 0x0017) & 0x20)
    goto loc_19c57;
  memoryASet(es, 0x0017, memoryAGet(es, 0x0017) | 0x20);
loc_19c57:
  es = pop();
}
void sub_19c59()
{
  ax = 0x000d;
  interrupt(0x10);
  sub_189f8();
  memoryASet16(cs, 0x031e, 0x0000);
  memoryASet16(cs, 0x0320, 0x3e80);
  push(es);
  si = 0xa000;
  es = si;
  bx = memoryAGet16(ds, 0x40c9);
  bx <<= 1;
  si = memoryAGet16(cs, bx + 693);
  memoryASet16(cs, 0x031a, si);
  si = 0x0247;
  bp = 0x3e80;
  memoryASet16(cs, 0x031c, 0x1f40);
  sub_1880d();
  push(ds);
  al = 0x01;
  sub_188cd();
  al = 0x0f;
  sub_188b9();
  al = 0xff;
  sub_188e1();
  si = 0xa000;
  ds = si;
  di = memoryAGet16(cs, 0x031c);
  si = memoryAGet16(cs, 0x0320);
  cx = memoryAGet16(cs, 0x031c);
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  ds = pop();
  es = pop();
  memoryASet16(cs, 0x0320, 0x1f40);
  memoryASet(cs, 0x201b, 0x0f);
  sub_1a042();
  sub_18b77();
  sub_1ab3e();
  ax += memoryAGet16(ds, 0x4289);
  ax &= 0x0007;
  if (ax)
    goto loc_19ce0;
  ax++;
loc_19ce0:
  bx = 0;
  memoryASet(ds, 0x4283, bl);
  memoryASet(ds, 0x4282, 0x03);
  memoryASet(ds, 0x4285, bl);
  memoryASet(ds, 0x42a4, bl);
  memoryASet(ds, 0x42e1, bl);
  memoryASet(ds, 0x0244, bl);
  memoryASet(ds, 0x0142, bl);
  memoryASet16(ds, 0x428b, ax);
  ax--;
  bx = ax;
  bx <<= 1;
  memoryASet16(ds, bx + 16595, memoryAGet16(ds, bx + 16595) + 1);
  memoryASet16(ds, 0x40f0, memoryAGet16(ds, 0x40f0) + 1);
  sub_1a34a();
  if (memoryAGet(ds, 0x5e07) == 0x00)
    goto loc_19d1c;
  sub_1a11b();
loc_19d1c:
  memoryASet(ds, 0x0243, 0x01);
  sub_18b77();
  sub_1ab3e();
  ax += memoryAGet16(ds, 0x4289);
  ax &= 0x0007;
  if (ax)
    goto loc_19d33;
  ax++;
loc_19d33:
  sub_1a3ac();
  memoryASet16(ds, 0x428d, ax);
  si = 0x04df;
  bx = 0x1004;
  sub_19111();
  if (memoryAGet(ds, 0x42e8) == 0x00)
    goto loc_19d4c;
  sub_1a322();
loc_19d4c:
  al = memoryAGet(ds, 0x0142);
  if (al)
    goto loc_19d56;
  sub_1af58();
loc_19d56:
  sub_1af7c();
  bp = memoryAGet16(ds, 0x42a6);
  al = memoryAGet(ds, bp);
  ah = memoryAGet(ds, bp + 1);
  bp += 0x0002;
  bh = 0;
  bl = memoryAGet(ds, 0x4282);
  bl = memoryAGet(ds, bx + 17064);
  di = bx;
  bl = memoryAGet(ds, 0x4283);
  bx <<= 1;
  di += memoryAGet16(ds, bx + 17074);
  sub_1ad03();
  sub_18768();
  bp = memoryAGet16(ds, 0x42a6);
  al = memoryAGet(ds, bp);
  ah = memoryAGet(ds, bp + 1);
  bp += 0x0002;
  if (memoryAGet(ds, 0x4283) != 0x00)
    goto loc_19de4;
  if (memoryAGet(ds, 0x4282) != 0x03)
    goto loc_19de4;
  bx = bp;
  if (ah == 0x01)
    goto loc_19daa;
  bl += al;
loc_19daa:
  dx = 0x40f5;
  ch = ah;
loc_19daf:
  ch--;
  if (!ch)
    goto loc_19dba;
  dx += 0x000a;
  goto loc_19daf;
loc_19dba:
  ch = ah;
loc_19dbc:
  di = dx;
  si = bx;
  cl = al;
loc_19dc2:
  if (memoryAGet(es, di) == 0x00)
    goto loc_19dd5;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_19dd5;
  memoryASet(ds, 0x5d10, 0x01);
  goto loc_19fb7;
loc_19dd5:
  di++;
  si++;
  cl--;
  if (cl != 0)
    goto loc_19dc2;
  dx -= 0x000a;
  bl -= al;
  ch--;
  if (ch != 0)
    goto loc_19dbc;
loc_19de4:
  di = memoryAGet16(ds, 0x4306);
  sub_1ad03();
  if (memoryAGet(ds, 0x428f) != 0x01)
    goto loc_19e0a;
  memoryASet(ds, 0x42e1, memoryAGet(ds, 0x42e1) + 1);
  if ((char)memoryAGet(ds, 0x42e1) <= (char)0x07)
    goto loc_19e0a;
  memoryASet(ds, 0x42e1, 0x00);
  memoryASet(ds, 0x42a4, 0x00);
  goto loc_19f89;
loc_19e0a:
  ah = memoryAGet(ds, 0x4283);
  memoryASet(ds, 0x4284, ah);
  sub_19c43();
  if (memoryAGet(ds, 0x00cf) == 0x00)
    goto loc_19e24;
  sub_185ac();
  if (ah != 0x00)
    goto loc_19e29;
loc_19e24:
  sub_1a3de();
  if (!flags.carry)
    goto loc_19e3f;
loc_19e29:
  al = ah;
  di = 0x5ccb;
  cx = 0x0018;
  repne_scasb<MemAuto, DirAuto>(al);
  if (cx == 0)
    goto loc_19e3f;
  di -= 0x5ccc;
  di <<= 1;
    if (di==14) di = 8; // replace up with rotate
  switch (di)
  {
    case 0: goto loc_19e42;
    case 2: goto loc_19e42;
    case 4: goto loc_19e48;
    case 6: goto loc_19e48;
    case 8: goto loc_19e4e;
    case 10: goto loc_19e4e;
    case 12: goto loc_19e4e;
    case 14: goto loc_19ed4;
    case 16: goto loc_19ed4;
    case 18: goto loc_19f1d;
    case 20: goto loc_19eff;
    case 22: goto loc_19f1d;
    case 24: goto loc_19ef1;
    case 26: goto loc_19eff;
    case 28: goto loc_19eff;
    case 30: goto loc_19e54;
    case 32: goto loc_19e5c;
    case 34: goto loc_19e7a;
    case 36: goto loc_19f1d;
    case 38: goto loc_19f78;
    case 40: goto loc_19f83;
    case 42: goto loc_19e98;
default:
    assert(0);
  }
loc_19e3f:
  goto loc_19f50;
loc_19e42:
  sub_1abfc();
  goto loc_19f23;
loc_19e48:
  sub_1adf9();
  goto loc_19f23;
loc_19e4e:
  sub_1ae5e();
  goto loc_19f23;
loc_19e54:
  memoryASet(ds, 0x5d11, memoryAGet(ds, 0x5d11) ^ 0x01);
  goto loc_19f50;
loc_19e5c:
  memoryASet(ds, 0x5e06, memoryAGet(ds, 0x5e06) ^ 0x01);
  if (memoryAGet(ds, 0x5e06) == 0x00)
    goto loc_19e6e;
  sub_1a10c();
  goto loc_19f50;
loc_19e6e:
  si = 0x0e60;
  bx = 0x5f0d;
  sub_19111();
  goto loc_19f50;
loc_19e7a:
  memoryASet(ds, 0x5e07, memoryAGet(ds, 0x5e07) ^ 0x01);
  if (memoryAGet(ds, 0x5e07) == 0x00)
    goto loc_19e8c;
  sub_1a114();
  goto loc_19f50;
loc_19e8c:
  si = 0x0e7c;
  bx = 0x5e0b;
  sub_19111();
  goto loc_19f50;
loc_19e98:
  memoryASet(ds, 0x5e3a, memoryAGet(ds, 0x5e3a) ^ 0x01);
  if (memoryAGet(ds, 0x5e3a) == 0x00)
    goto loc_19eaa;
  sub_1a108();
  goto loc_19f50;
loc_19eaa:
  si = 0x00e6;
  bx = 0x2507;
  sub_19111();
  goto loc_19f50;
loc_19eb6:
  memoryASet(ds, 0x62ef, memoryAGet(ds, 0x62ef) ^ 0x01);
  if (memoryAGet(ds, 0x62ef) == 0x00)
    goto loc_19ec8;
  sub_1a110();
  goto loc_19f50;
loc_19ec8:
  si = 0x1dd8;
  bx = 0x0928;
  sub_19111();
  goto loc_19f50;
  //   gap of 1 bytes
loc_19ed4:
  if ((short)memoryAGet16(ds, 0x40c9) >= (short)0x0009)
    goto loc_19eee;
  sub_1a069();
  sub_1a34a();
  sub_1a042();
  if (memoryAGet(ds, 0x42e8) == 0x00)
    goto loc_19eee;
  sub_1a322();
loc_19eee:
  goto loc_19f23;
  //   gap of 1 bytes
loc_19ef1:
  sub_1a63c();
  if (memoryAGet(ds, 0x5e39) != 0x01)
    goto loc_19efc;
  return;
loc_19efc:
  goto loc_19f50;
  //   gap of 1 bytes
loc_19eff:
  memoryASet(ds, 0x42e8, memoryAGet(ds, 0x42e8) ^ 0x01);
  if (memoryAGet(ds, 0x42e8) == 0x00)
    goto loc_19f11;
  sub_1a322();
  goto loc_19f1a;
  //   gap of 1 bytes
loc_19f11:
  si = 0x04df;
  bx = 0x1004;
  sub_19111();
loc_19f1a:
  goto loc_19f50;
  //   gap of 1 bytes
loc_19f1d:
  sub_1af12();
  goto loc_19f89;
  //   gap of 1 bytes
loc_19f23:
  memoryASet(ds, 0x0244, memoryAGet(ds, 0x0244) + 1);
  if ((char)memoryAGet(ds, 0x0244) <= (char)0x05)
    goto loc_19f50;
  if (memoryAGet(ds, 0x0142) != 0x00)
    goto loc_19f38;
  sub_1af58();
loc_19f38:
  sub_1af7c();
  if (memoryAGet(ds, 0x428f) == 0x01)
    goto loc_19f57;
  memoryASet(ds, 0x4283, memoryAGet(ds, 0x4283) + 1);
  memoryASet(ds, 0x0244, 0x00);
  memoryASet(ds, 0x42a4, 0x00);
loc_19f50:
  if (memoryAGet(ds, 0x428f) != 0x01)
    goto loc_19f5e;
loc_19f57:
  memoryASet(ds, 0x42a4, memoryAGet(ds, 0x42a4) + 1);
  goto loc_19d4c;
loc_19f5e:
  if (memoryAGet(ds, 0x0142) != 0x00)
    goto loc_19f68;
  sub_1af58();
loc_19f68:
  sub_1af7c();
  if (memoryAGet(ds, 0x428f) == 0x01)
    goto loc_19f75;
  sub_1af23();
loc_19f75:
  goto loc_19d4c;
loc_19f78:
  ah = 0;
  interrupt(0x16);
  if (ah != 0x19)
    goto loc_19f78;
  goto loc_19f50;
loc_19f83:
  memoryASet(ds, 0x5e39, 0x01);
  return;
loc_19f89:
  bp = memoryAGet16(ds, 0x42a6);
  al = memoryAGet(ds, bp);
  ah = memoryAGet(ds, bp + 1);
  bp += 0x0002;
  bh = 0;
  bl = memoryAGet(ds, 0x4282);
  bl = memoryAGet(ds, bx + 17064);
  di = bx;
  bl = memoryAGet(ds, 0x4283);
  bx <<= 1;
  di += memoryAGet16(ds, bx + 17074);
  sub_1ad03();
  memoryASet16(ds, 0x0140, memoryAGet16(ds, 0x0140) ^ 0x0001);
loc_19fb7:
  if (memoryAGet16(ds, 0x40cb) < 0xff14)
    goto loc_19fc8;
  memoryASet16(ds, 0x40cb, 0xff14);
  goto loc_19fed;
  //   gap of 1 bytes
loc_19fc8:
  bx = memoryAGet16(ds, 0x40c9);
  bx <<= 1;
  ax = memoryAGet16(ds, bx + 17138);
  bx = 0;
  bl = memoryAGet(ds, 0x4284);
  ax -= bx;
  if (memoryAGet(ds, 0x42e8) == 0x00)
    goto loc_19fe9;
  ax >>= 1;
  memoryASet16(ds, 0x40cb, memoryAGet16(ds, 0x40cb) + ax);
  ax >>= 1;
loc_19fe9:
  memoryASet16(ds, 0x40cb, memoryAGet16(ds, 0x40cb) + ax);
loc_19fed:
  if (memoryAGet(ds, 0x5d10) != 0x01)
    goto loc_19ffd;
  sub_1a34a();
  sub_18768();
  return;
  //   gap of 1 bytes
loc_19ffd:
  sub_1ad74();
  sub_1ab61();
  sub_1a34a();
  sub_18768();
  if (memoryAGet16(ds, 0x4604) == 0x0000)
    goto loc_1a019;
  sub_1a40e();
  sub_1a042();
  sub_18768();
loc_1a019:
  bx = memoryAGet16(ds, 0x40c9);
  ax = memoryAGet16(ds, 0x40e8);
  bl = memoryAGet(ds, bx + 17129);
  if ((short)ax < (short)bx)
    goto loc_1a03b;
  if ((short)memoryAGet16(ds, 0x40c9) >= (short)0x0009)
    goto loc_1a03b;
  sub_1a069();
  sub_1a042();
  si = 0x45ca;
  sub_1918b();
loc_1a03b:
  ax = memoryAGet16(ds, 0x428d);
  goto loc_19ce0;
}
void sub_1a042()
{
  ax = 0x140a;
  dx = 0x0a0f;
  bp = 0x40f2;
  sub_1acae();
}
void sub_1a04f()
{
}
void sub_1a069()
{
  memoryASet16(ds, 0x40c9, memoryAGet16(ds, 0x40c9) + 1);
  bx = memoryAGet16(ds, 0x40c9);
  if ((short)bx <= (short)memoryAGet16(ds, 0x5e02))
    goto loc_1a084;
  if (memoryAGet(ds, 0x5e3a) != 0x01)
    goto loc_1a081;
  sub_1a1c4();
loc_1a081:
  return;
loc_1a084:
  bx--;
  bx <<= 1;
  ds = memoryAGet16(ds, bx + 24048);
  sub_18b2a();
  ax = 0x100d;
  ds = ax;
  push(es);
  si = 0xa000;
  es = si;
  bx = memoryAGet16(ds, 0x40c9);
  bx <<= 1;
  si = memoryAGet16(cs, bx + 693);
  memoryASet16(cs, 0x031a, si);
  si = 0x0247;
  bp = 0x3e80;
  memoryASet16(cs, 0x031c, 0x1f40);
  sub_1880d();
  push(ds);
  al = 0x01;
  sub_188cd();
  al = 0x0f;
  sub_188b9();
  al = 0xff;
  sub_188e1();
  si = 0xa000;
  ds = si;
  di = memoryAGet16(cs, 0x0320);
  si = 0x3e80;
  cx = memoryAGet16(cs, 0x031c);
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  ds = pop();
  es = pop();
  if (memoryAGet(ds, 0x5e06) != 0x01)
    goto loc_1a0e9;
  sub_1a10c();
loc_1a0e9:
  if (memoryAGet(ds, 0x5e07) != 0x01)
    goto loc_1a0f3;
  sub_1a114();
loc_1a0f3:
  if (memoryAGet(ds, 0x5e3a) != 0x01)
    goto loc_1a0fd;
  sub_1a108();
loc_1a0fd:
  if (memoryAGet(ds, 0x62ef) != 0x01)
    return;
  sub_1a110();
}
void sub_1a108()
{
  sub_1a1c4();
}
void sub_1a10c()
{
  sub_1a209();
}
void sub_1a110()
{
  sub_1a196();
}
void sub_1a114()
{
  sub_1a26d();
  sub_1a11b();
}
void sub_1a11b()
{
  memoryASet(cs, 0x201b, 0x0f);
  memoryASet(ds, 0x42e6, 0x07);
  bx = 0;
  memoryASet16(cs, 0x2018, 0x006b);
  dh = 0x6b;
  dl = 0x21;
loc_1a134:
  push(bx);
  bx = 0x0805;
  push(dx);
  sub_1a833();
  dx = pop();
  bx = pop();
  ax = bx;
  ax <<= 1;
  si = 0x40d3;
  si += ax;
  di = 0x40ce;
  push(bx);
  sub_1a7d2();
  bp = 0x40cd;
  push(dx);
  memoryASet16(cs, 0x2016, 0x0021);
  sub_1a9d8();
  dx = pop();
  dh += 0x09;
  memoryASet16(cs, 0x2018, memoryAGet16(cs, 0x2018) + 0x0009);
  bx = pop();
  bx++;
  memoryASet(ds, 0x42e6, memoryAGet(ds, 0x42e6) - 1);
  if (memoryAGet(ds, 0x42e6) != 0)
    goto loc_1a134;
  dh += 0x05;
  memoryASet16(cs, 0x2018, memoryAGet16(cs, 0x2018) + 0x0005);
  bx = 0x0805;
  push(dx);
  sub_1a833();
  dx = pop();
  si = 0x40f0;
  di = 0x40ce;
  sub_1a7d2();
  bp = 0x40cd;
  memoryASet16(cs, 0x2016, 0x0021);
  sub_1a9d8();
}
void sub_1a196()
{
  memoryASet(cs, 0x201b, 0x04);
  di = 0x1dd8;
  bx = 0x0928;
  al = 0x0f;
  sub_1a8fc();
  memoryASet16(cs, 0x2016, 0x0001);
  memoryASet16(cs, 0x2018, 0x00c0);
  bx = memoryAGet16(ds, 0x40c9);
  bx <<= 1;
  bp = memoryAGet16(ds, bx + 25693);
  sub_1a9d8();
}
void sub_1a1c4()
{
  memoryASet(cs, 0x201b, 0x0f);
  di = 0x00e6;
  bx = 0x2507;
  al = 0x00;
  sub_1a8fc();
  di = 0x010e;
  bx = 0x2307;
  sub_1a876();
  memoryASet16(cs, 0x2016, 0x001f);
  memoryASet16(cs, 0x2018, 0x0009);
  bp = 0x5e3b;
  sub_1a9d8();
  bx = memoryAGet16(ds, 0x40c9);
  bx <<= 1;
  si = memoryAGet16(ds, bx + 226);
  bh = 0x0f;
  bl = 0x03;
  dl = 0x20;
  dh = 0x15;
  sub_19b5c();
}
void sub_1a209()
{
  memoryASet(cs, 0x201b, 0x0f);
  di = 0x0e60;
  bx = 0x5f0d;
  sub_1a941();
  di = 0x0e88;
  bl = 0x0d;
  bh = 0x5d;
  sub_1a876();
  memoryASet16(cs, 0x2016, 0x0002);
  memoryASet16(cs, 0x2018, 0x005f);
  bp = 0x432c;
  sub_1a9d8();
  memoryASet(ds, 0x42e6, 0x07);
  memoryASet16(cs, 0x2018, 0x006d);
  if (memoryAGet(ds, 0x5d9c) != 0x01)
    goto loc_1a250;
  bp = 0x4392;
  goto loc_1a253;
  //   gap of 1 bytes
loc_1a250:
  bp = 0x4334;
loc_1a253:
  memoryASet16(cs, 0x2016, 0x0001);
  sub_1a9d8();
  memoryASet16(cs, 0x2018, memoryAGet16(cs, 0x2018) + 0x000b);
  memoryASet(ds, 0x42e6, memoryAGet(ds, 0x42e6) - 1);
  if (memoryAGet(ds, 0x42e6) != 0)
    goto loc_1a253;
  sub_18768();
}
void sub_1a26d()
{
  memoryASet(cs, 0x201b, 0x0f);
  di = 0x0e7c;
  bh = 0x5e;
  bl = 0x0b;
  sub_1a941();
  di = 0x0ea4;
  bh = 0x5c;
  bl = 0x0b;
  sub_1a876();
  bp = 0x4386;
  memoryASet16(cs, 0x2016, 0x001d);
  memoryASet16(cs, 0x2018, 0x005e);
  sub_1a9d8();
  dl = 0x1d;
  dh = 0x6b;
  memoryASet(ds, 0x42e6, 0x07);
  memoryASet16(cs, 0x0324, 0x0002);
loc_1a2ac:
  bx = memoryAGet16(cs, 0x0324);
  si = memoryAGet16(ds, bx + 208);
  bx = 0x0801;
  push(dx);
  sub_19b5c();
  dx = pop();
  dh += 0x09;
  memoryASet16(cs, 0x0324, memoryAGet16(cs, 0x0324) + 0x0002);
  memoryASet(ds, 0x42e6, memoryAGet(ds, 0x42e6) - 1);
  if (memoryAGet(ds, 0x42e6) != 0)
    goto loc_1a2ac;
  dh += 0x05;
  bx = memoryAGet16(cs, 0x0324);
  si = memoryAGet16(ds, bx + 208);
  bx = 0x0801;
  sub_19b5c();
  memoryASet(ds, 0x42e6, 0x07);
  memoryASet16(cs, 0x2018, 0x006b);
loc_1a2ea:
  bp = 0x4390;
  memoryASet16(cs, 0x2016, 0x001f);
  sub_1a9d8();
  memoryASet16(cs, 0x2018, memoryAGet16(cs, 0x2018) + 0x0009);
  memoryASet(ds, 0x42e6, memoryAGet(ds, 0x42e6) - 1);
  if (memoryAGet(ds, 0x42e6) != 0)
    goto loc_1a2ea;
  bp = 0x4390;
  memoryASet16(cs, 0x2018, memoryAGet16(cs, 0x2018) + 0x0005);
  memoryASet16(cs, 0x2016, 0x001f);
  sub_1a9d8();
  di = 0x1afd;
  al = 0x0f;
  bx = 0x0109;
  sub_1a8fc();
}
void sub_1a322()
{
  bp = memoryAGet16(ds, 0x428d);
  bp--;
  bp <<= 1;
  bp = memoryAGet16(ds, bp + 515);
  bp = memoryAGet16(ds, bp);
  ah = memoryAGet(ds, bp + 1);
  al = memoryAGet(ds, bp);
  bp += 0x0002;
  di = 0x04df;
  sub_1ad03();
  memoryASet16(ds, 0x0140, memoryAGet16(ds, 0x0140) ^ 0x0001);
}
void sub_1a34a()
{
  bx = memoryAGet16(ds, 0x40c9);
  bx <<= 1;
  bx = memoryAGet16(ds, bx + 24072);
  memoryASet(cs, 0x201b, bl);
  si = 0x011f;
  di = si;
  bh = 0x14;
  bl = 0x05;
  sub_19111();
  si = 0x40cb;
  di = 0x40ce;
  memoryASet16(ds, 0x0241, 0x0005);
  sub_1a7d2();
  bp = 0x40cd;
  memoryASet16(cs, 0x2016, 0x0007);
  memoryASet16(cs, 0x2018, 0x0007);
  sub_1a9d8();
  si = 0x40e8;
  di = 0x40eb;
  sub_1a7d2();
  bp = 0x40ea;
  memoryASet16(cs, 0x2016, 0x0007);
  memoryASet16(cs, 0x2018, 0x0013);
  sub_1a9d8();
}
void sub_1a3ac()
{
  bx = ax;
  bx--;
  cx = 0x0007;
loc_1a3b2:
  if (bx)
    goto loc_1a3bc;
  dx = 0x0001;
  goto loc_1a3bf;
  //   gap of 1 bytes
loc_1a3bc:
  dx = 0x0002;
loc_1a3bf:
  if (memoryAGet(ds, bx + 16609) == dl)
    goto loc_1a3cd;
  memoryASet(ds, bx + 16609, memoryAGet(ds, bx + 16609) + 1);
  bx++;
  ax = bx;
  return;
loc_1a3cd:
  memoryASet(ds, bx + 16609, 0x00);
  bx++;
  if (bx != 0x0007)
    goto loc_1a3da;
  bx = 0;
loc_1a3da:
  cx--;
  if (cx != 0)
    goto loc_1a3b2;
}
void sub_1a3de()
{
  dx = es;
  ah = 0x01;
  interrupt(0x16);
  if (!flags.zero)
    goto loc_1a3f8;
  bx = 0;
  es = bx;
  bx = memoryAGet16(es, 0x041a);
  memoryASet16(es, 0x041c, bx);
  flags.carry = false;
  es = dx;
  return;
loc_1a3f8:
  ah = 0;
  interrupt(0x16);
  bx = 0;
  es = bx;
  bx = memoryAGet16(es, 0x041a);
  memoryASet16(es, 0x041c, bx);
  flags.carry = true;
  es = dx;
}
void sub_1a40e()
{
  push(es);
  ax = 0xa000;
  es = ax;
  memoryASet(ds, 0x42e6, 0x09);
  al = 0x18;
  sub_18923();
  al = 0x00;
  sub_188cd();
  al = 0x0f;
  sub_188b9();
  al = 0xff;
  sub_188e1();
loc_1a42d:
  ax = 0;
loc_1a42f:
  memoryASet16(cs, 0x0324, ax);
  bx = ax;
  bx <<= 1;
  bp = memoryAGet16(ds, bx + 17926);
  bp <<= 1;
  di = memoryAGet16(ds, bp + 17884);
  di += memoryAGet16(cs, 0x0320);
  dx = 0x0008;
  if (memoryAGet(ds, 0x42e6) == 0x01)
    goto loc_1a467;
loc_1a451:
  cx = 0x000a;
loc_1a454:
  al = memoryAGet(es, di);
  memoryASet(es, di, 0xff);
  di++;
  if (--cx)
    goto loc_1a454;
  di += 0x001e;
  dx--;
  if (dx != 0)
    goto loc_1a451;
  goto loc_1a494;
  //   gap of 1 bytes
loc_1a467:
  al = 0x00;
  sub_18923();
  al = 0x00;
  sub_188cd();
  al = 0x0f;
  sub_188b9();
  al = 0xff;
  sub_188e1();
  bl = 0x0a;
  bh = 0x08;
  di -= memoryAGet16(cs, 0x0320);
  si = di;
  sub_19111();
  bx = memoryAGet16(cs, 0x0320);
  sub_1888b();
  goto loc_1a4b2;
  //   gap of 1 bytes
loc_1a494:
  ax = memoryAGet16(cs, 0x0324);
  ax++;
  if (ax == memoryAGet16(ds, 0x4604))
    goto loc_1a4a1;
  goto loc_1a42f;
loc_1a4a1:
  bx = memoryAGet16(cs, 0x0320);
  sub_1888b();
  memoryASet(ds, 0x42e6, memoryAGet(ds, 0x42e6) - 1);
  if (memoryAGet(ds, 0x42e6) == 0)
    goto loc_1a4b2;
  goto loc_1a42d;
loc_1a4b2:
  bx = memoryAGet16(ds, 0x4604);
  memoryASet(ds, 0x42e6, bl);
loc_1a4ba:
  si = 0x45be;
  sub_1918b();
  memoryASet(ds, 0x42e6, memoryAGet(ds, 0x42e6) - 1);
  if (memoryAGet(ds, 0x42e6) != 0)
    goto loc_1a4ba;
  es = pop();
}
void sub_1a4c8()
{
  push(es);
  ax = 0x0003;
  interrupt(0x10);
  if (memoryAGet(cs, 0x0000) != 0x01)
    goto loc_1a4dc;
  ax = 0xb000;
  goto loc_1a4df;
  //   gap of 1 bytes
loc_1a4dc:
  ax = 0xb800;
loc_1a4df:
  es = ax;
  di = 0x0096;
  si = 0x43dd;
  ah = 0x30;
  sub_1a71b();
  di = 0x0140;
  ax = 0x3f20;
  cx = 0x004b;
  rep_stosw<MemAuto, DirAuto>();
  cx = 0x0008;
  di = 0x014e;
  ax = 0x3041;
loc_1a500:
  memoryASet16(es, di, ax);
  al++;
  di += 0x0012;
  cx--;
  if (cx != 0)
    goto loc_1a500;
  memoryASet(ds, 0x42e6, 0x02);
  di = 0x01e0;
  ax = 0x3020;
  dx = ax;
loc_1a518:
  bx = 0x3030;
  cx = 0x000a;
loc_1a51e:
  memoryASet16(es, di, ax);
  memoryASet16(es, di + 2, dx);
  memoryASet16(es, di + 4, bx);
  bl++;
  di += 0x00a0;
  cx--;
  if (cx != 0)
    goto loc_1a51e;
  memoryASet(ds, 0x42e6, memoryAGet(ds, 0x42e6) - 1);
  if (memoryAGet(ds, 0x42e6) == 0)
    goto loc_1a53d;
  dx = 0x3031;
  goto loc_1a518;
loc_1a53d:
  memoryASet16(es, di, 0x3020);
  memoryASet16(es, di + 2, 0x3032);
  memoryASet16(es, di + 4, 0x3030);
  si = 0x43e3;
  di = 0x02ba;
  ah = 0x0f;
  sub_1a71b();
  di = 0x03ea;
  si = 0x4413;
  dx = di;
  bx = 0x0006;
loc_1a564:
  sub_1a71b();
  dx += 0x0012;
  di = dx;
  bx--;
  if (bx != 0)
    goto loc_1a564;
  di = 0x0506;
  si = 0x4442;
  dx = di;
  bx = 0x000c;
loc_1a57a:
  sub_1a71b();
  dx += 0x00a0;
  di = dx;
  bx--;
  if (bx != 0)
    goto loc_1a57a;
  memoryASet(ds, 0x42e6, 0x0c);
  di = 0x052a;
  memoryASet16(ds, 0x4306, di);
  memoryASet16(ds, 0x42e4, di);
loc_1a596:
  sub_1ab24();
  memoryASet16(ds, 0x4289, memoryAGet16(ds, 0x4289) + cx);
  sub_1ab3e();
  ax |= cx;
  ax &= 0x007f;
  ax |= 0x0080;
  memoryASet16(ds, 0x023f, ax);
  memoryASet16(ds, 0x42e2, 0x0006);
loc_1a5b1:
  sub_1ab3e();
  ax &= 0x003f;
  memoryASet16(ds, 0x023f, memoryAGet16(ds, 0x023f) + ax);
  si = 0x023f;
  di = 0x40ce;
  memoryASet16(ds, 0x0241, 0x0005);
  sub_1a7d2();
  di = memoryAGet16(ds, 0x42e4);
  ah = 0x0f;
  si = 0x40cd;
  sub_1a71b();
  si = 0x44ac;
  sub_1a71b();
  memoryASet16(ds, 0x42e4, memoryAGet16(ds, 0x42e4) + 0x0012);
  memoryASet16(ds, 0x42e2, memoryAGet16(ds, 0x42e2) - 1);
  if (memoryAGet16(ds, 0x42e2) != 0)
    goto loc_1a5b1;
  memoryASet16(ds, 0x4306, memoryAGet16(ds, 0x4306) + 0x00a0);
  cx = memoryAGet16(ds, 0x4306);
  memoryASet16(ds, 0x42e4, cx);
  memoryASet(ds, 0x42e6, memoryAGet(ds, 0x42e6) - 1);
  if (memoryAGet(ds, 0x42e6) == 0)
    goto loc_1a5fd;
  goto loc_1a596;
loc_1a5fd:
  sub_19c18();
  if (ah == 0x01)
    goto loc_1a623;
  if (ah != 0x10)
    goto loc_1a612;
  memoryASet(ds, 0x5e39, 0x01);
  goto loc_1a63a;
  //   gap of 1 bytes
loc_1a612:
  if (ah != 0x1f)
    goto loc_1a61f;
  memoryASet(ds, 0x5d11, memoryAGet(ds, 0x5d11) ^ 0x01);
  cx = 0x0900;
loc_1a61f:
  if (--cx)
    goto loc_1a61f;
  goto loc_1a5fd;
loc_1a623:
  if (memoryAGet(cs, 0x0000) != 0x01)
    goto loc_1a631;
  sub_18bb2();
  goto loc_1a634;
  //   gap of 1 bytes
loc_1a631:
  sub_1a699();
loc_1a634:
  sub_19c06();
  sub_19bca();
loc_1a63a:
  es = pop();
}
void sub_1a63c()
{
  ax = memoryAGet16(cs, 0x0320);
  push(ax);
  memoryASet16(cs, 0x2016, 0x0000);
  memoryASet16(cs, 0x2018, 0x0000);
  memoryASet16(cs, 0x0320, 0x7d00);
  bp = 0x430d;
  memoryASet(cs, 0x201b, 0x0f);
  sub_1a9d8();
  bx = memoryAGet16(cs, 0x0320);
  sub_1888b();
loc_1a66a:
  sub_19c18();
  if (ah == 0x01)
    goto loc_1a690;
  if (ah != 0x10)
    goto loc_1a67f;
  memoryASet(ds, 0x5e39, 0x01);
  return;
  //   gap of 1 bytes
loc_1a67f:
  if (ah != 0x1f)
    goto loc_1a68c;
  memoryASet(ds, 0x5d11, memoryAGet(ds, 0x5d11) ^ 0x01);
  cx = 0x0900;
loc_1a68c:
  if (--cx)
    goto loc_1a68c;
  goto loc_1a66a;
loc_1a690:
  ax = pop();
  memoryASet16(cs, 0x0320, ax);
  sub_18768();
}
void sub_1a699()
{
  push(es);
  ax = 0x0040;
  es = ax;
  bl = memoryAGet(es, 0x0087);
  if (!bl)
    goto loc_1a6c9;
  if (bl & 0x08)
    goto loc_1a6c9;
  ax = 0x0005;
  interrupt(0x10);
  dx = 0x03da;
loc_1a6b5:
  in(al, dx);
  if (!(al & 0x08))
    goto loc_1a6b5;
  dx = 0x03c0;
  al = 0x02;
  out(dx, al);
  al = 0x2c;
  out(dx, al);
  al = 0x20;
  out(dx, al);
  goto loc_1a6d1;
  //   gap of 1 bytes
loc_1a6c9:
  ax = 0x0004;
  interrupt(0x10);
  sub_1916c();
loc_1a6d1:
  es = pop();
}
void sub_1a6d3()
{
  push(es);
  ax = 0x0040;
  es = ax;
  bl = memoryAGet(es, 0x0087);
  if (!bl)
    goto loc_1a711;
  if (bl & 0x08)
    goto loc_1a711;
  memoryASet(cs, 0x0010, 0x01);
  ax = 0x000d;
  interrupt(0x10);
  sub_189f8();
  ax = 0x0005;
  interrupt(0x10);
  dx = 0x03da;
loc_1a6fd:
  in(al, dx);
  if (!(al & 0x08))
    goto loc_1a6fd;
  dx = 0x03c0;
  al = 0x02;
  out(dx, al);
  al = 0x2c;
  out(dx, al);
  al = 0x20;
  out(dx, al);
  goto loc_1a719;
  //   gap of 1 bytes
loc_1a711:
  ax = 0x0004;
  interrupt(0x10);
  sub_1916c();
loc_1a719:
  es = pop();
}
void sub_1a71b()
{
  lodsb<MemAuto, DirAuto>();
  cl = al;
loc_1a71e:
  lodsb<MemAuto, DirAuto>();
  stosw<MemAuto, DirAuto>();
  cl--;
  if (cl != 0)
    goto loc_1a71e;
}
void sub_1a7d2()
{
  push(dx);
  bp = 0;
  al = 0x20;
  cx = memoryAGet16(ds, 0x0241);
loc_1a7db:
  memoryASet(ds, bp + di, al);
  bp++;
  cx--;
  if (cx != 0)
    goto loc_1a7db;
  bp--;
  bx = 0x000a;
  cx = memoryAGet16(ds, 0x0241);
  cx++;
  ax = memoryAGet16(ds, si);
loc_1a7ed:
  dx = 0;
  div(bx);
  dl += 0x30;
  memoryASet(ds, bp + di, dl);
  if (ax == 0x0000)
    goto loc_1a800;
  bp--;
  cx--;
  if (cx != 0)
    goto loc_1a7ed;
loc_1a800:
  dx = pop();
}
void sub_1a802()
{
  di = 0x0247;
  ax = 0;
  al = dl;
  di += ax;
  al = dh;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  ax <<= 1;
  di += ax;
  ax <<= 1;
  ax <<= 1;
  di += ax;
  cx = 0;
  cl = bl;
  si = 0x0050;
  si -= cx;
  al = 0;
loc_1a828:
  cl = bl;
  rep_stosb<MemAuto, DirAuto>();
  di += si;
  bh--;
  if (bh != 0)
    goto loc_1a828;
}
void sub_1a833()
{
  push(es);
  ax = 0xa000;
  es = ax;
  push(bx);
  sub_189a1();
  al = 0x02;
  sub_188cd();
  al = 0x0f;
  sub_188b9();
  al = 0xff;
  sub_188e1();
  al = memoryAGet(es, di);
  al = 0x00;
  memoryASet(es, di, al);
  al = 0x01;
  sub_188cd();
  bx = pop();
  dx = memoryAGet16(cs, 0x05c6);
  ch = 0;
  cl = bl;
  dx -= cx;
  si = di;
  al = memoryAGet(es, si);
loc_1a86a:
  cl = bl;
  rep_stosb<MemAuto, DirAuto>();
  di += dx;
  bh--;
  if (bh != 0)
    goto loc_1a86a;
  es = pop();
}
void sub_1a876()
{
  push(es);
  ax = 0xa000;
  es = ax;
  di += memoryAGet16(cs, 0x0320);
  al = 0x02;
  sub_188cd();
  al = 0xff;
  sub_188e1();
  al = 0x0f;
  sub_188b9();
  al = memoryAGet(es, di);
  al = 0x06;
  dx = memoryAGet16(cs, 0x05c6);
  ch = 0;
  cl = bl;
  dx -= cx;
  rep_stosb<MemAuto, DirAuto>();
  di += dx;
  al = 0x80;
  sub_188e1();
  push(di);
  al = memoryAGet(es, di);
  al = 0x06;
  ch = 0;
  cl = bh;
  cl -= 0x02;
loc_1a8b6:
  memoryASet(es, di, al);
  di += memoryAGet16(cs, 0x05c6);
  if (--cx)
    goto loc_1a8b6;
  al = 0xff;
  sub_188e1();
  al = memoryAGet(es, di);
  al = 0x06;
  dx = memoryAGet16(cs, 0x05c6);
  ch = 0;
  cl = bl;
  dx -= cx;
  rep_stosb<MemAuto, DirAuto>();
  di = pop();
  ch = 0;
  cl = bl;
  di += cx;
  di--;
  al = 0x01;
  sub_188e1();
  al = memoryAGet(es, di);
  al = 0x06;
  ch = 0;
  cl = bh;
  cl -= 0x02;
loc_1a8f0:
  memoryASet(es, di, al);
  di += memoryAGet16(cs, 0x05c6);
  if (--cx)
    goto loc_1a8f0;
  es = pop();
}
void sub_1a8fc()
{
  push(es);
  push(bx);
  push(ax);
  ax = 0xa000;
  es = ax;
  di += memoryAGet16(cs, 0x0320);
  al = 0x02;
  sub_188cd();
  al = 0x0f;
  sub_188b9();
  al = 0xff;
  sub_188e1();
  al = memoryAGet(es, di);
  ax = pop();
  memoryASet(es, di, al);
  al = 0x01;
  sub_188cd();
  bx = pop();
  dx = memoryAGet16(cs, 0x05c6);
  ch = 0;
  cl = bl;
  dx -= cx;
  si = di;
  al = memoryAGet(es, si);
loc_1a935:
  cl = bl;
  rep_stosb<MemAuto, DirAuto>();
  di += dx;
  bh--;
  if (bh != 0)
    goto loc_1a935;
  es = pop();
}
void sub_1a941()
{
  al = 0x00;
  sub_1a8fc();
}
void sub_1a947()
{
  dx = memoryAGet16(es, 0x42e2);
  al = memoryAGet(ds, bp);
  memoryASet(es, 0x42e7, al);
loc_1a954:
  bp++;
  bh = 0;
  bl = memoryAGet(ds, bp);
  if ((char)bl > (char)0x7a)
    goto loc_1a975;
  if ((char)bl <= (char)0x5a)
    goto loc_1a968;
  bl -= 0x20;
loc_1a968:
  flags.carry = bl < 0x20;
  bl -= 0x20;
  if (flags.carry)
    goto loc_1a975;
  if ((char)bl > (char)0x5a)
    goto loc_1a975;
  goto loc_1a977;
  //   gap of 1 bytes
loc_1a975:
  bl = 0;
loc_1a977:
  cl = 0x04;
  bx <<= cl;
  si = 0x7ea4;
  si += bx;
  ax = memoryAGet16(es, 0x42e4);
  cl = 0x04;
  ax <<= cl;
  di = ax;
  ax <<= 1;
  ax <<= 1;
  di += ax;
  di += dx;
  di += 0x0247;
  cx = 0x0008;
loc_1a999:
  lodsw<MemAuto, DirAuto>();
  bx = ax;
  bx = ~bx;
  ax &= memoryAGet16(ds, 0x5d25);
  memoryASet16(es, di, memoryAGet16(es, di) & bx);
  memoryASet16(es, di, memoryAGet16(es, di) | ax);
  di += 0x0050;
  if (--cx)
    goto loc_1a999;
  memoryASet(es, 0x42e7, memoryAGet(es, 0x42e7) - 1);
  if (memoryAGet(es, 0x42e7) == 0)
    goto loc_1a9b9;
  dx += 0x0002;
  goto loc_1a954;
loc_1a9b9:
  bp++;
}
void sub_1a9bb()
{
  push(ds);
  push(es);
  cx = ds;
  es = cx;
  cx = 0xf000;
  ds = cx;
  cx = 0x01d8;
  si = 0xfa6e;
  si += 0x0100;
  di = 0x7cbc;
  rep_movsb<MemAuto, MemAuto, DirAuto>();
  es = pop();
  ds = pop();
}
void sub_1a9d8()
{
  push(es);
  cx = 0xa000;
  es = cx;
  al = 0x02;
  sub_188cd();
  al = 0x0f;
  sub_188b9();
  al = memoryAGet(ds, bp);
  memoryASet(cs, 0x201a, al);
loc_1a9f0:
  bp++;
  bh = 0;
  bl = memoryAGet(ds, bp);
  if ((char)bl > (char)0x7a)
    goto loc_1aa11;
  if ((char)bl <= (char)0x5a)
    goto loc_1aa04;
  bl -= 0x20;
loc_1aa04:
  flags.carry = bl < 0x20;
  bl -= 0x20;
  if (flags.carry)
    goto loc_1aa11;
  if ((char)bl > (char)0x5a)
    goto loc_1aa11;
  goto loc_1aa13;
  //   gap of 1 bytes
loc_1aa11:
  bl = 0;
loc_1aa13:
  cl = 0x03;
  bx <<= cl;
  si = 0x7cbc;
  si += bx;
  dx = memoryAGet16(cs, 0x2016);
  ax = memoryAGet16(cs, 0x2018);
  dh = al;
  sub_189a1();
  cx = 0x0008;
loc_1aa2d:
  dx = 0x03ce;
  al = 0x08;
  if (memoryAGet(ds, 0x6471) == 0x01)
    goto loc_1aa3a;
  out(dx, al);
loc_1aa3a:
  dx++;
  lodsb<MemAuto, DirAuto>();
  if (memoryAGet(ds, 0x6471) == 0x01)
    goto loc_1aa44;
  out(dx, al);
loc_1aa44:
  al = memoryAGet(es, di);
  al = memoryAGet(cs, 0x201b);
  memoryASet(es, di, al);
  di += memoryAGet16(cs, 0x05c6);
  if (--cx)
    goto loc_1aa2d;
  memoryASet(cs, 0x201a, memoryAGet(cs, 0x201a) - 1);
  if (memoryAGet(cs, 0x201a) == 0)
    goto loc_1aa64;
  memoryASet16(cs, 0x2016, memoryAGet16(cs, 0x2016) + 0x0001);
  goto loc_1a9f0;
loc_1aa64:
  es = pop();
  bp++;
}
void sub_1aa67()
{
  dx = memoryAGet16(es, 0x42e2);
  al = memoryAGet(ds, bp);
  memoryASet(es, 0x42e7, al);
loc_1aa74:
  bp++;
  bh = 0;
  bl = memoryAGet(ds, bp);
  if ((char)bl > (char)0x7a)
    goto loc_1aa95;
  if ((char)bl <= (char)0x5a)
    goto loc_1aa88;
  bl -= 0x20;
loc_1aa88:
  flags.carry = bl < 0x20;
  bl -= 0x20;
  if (flags.carry)
    goto loc_1aa95;
  if ((char)bl > (char)0x5a)
    goto loc_1aa95;
  goto loc_1aa97;
  //   gap of 1 bytes
loc_1aa95:
  bl = 0;
loc_1aa97:
  if (!bl)
    goto loc_1aaa1;
  si = 0x45c4;
  sub_1918b();
loc_1aaa1:
  cl = 0x04;
  bx <<= cl;
  si = 0x7ea4;
  si += bx;
  ax = memoryAGet16(es, 0x42e4);
  cl = 0x04;
  ax <<= cl;
  di = ax;
  ax <<= 1;
  ax <<= 1;
  di += ax;
  di += dx;
  di += 0x0247;
  cx = 0x0008;
loc_1aac3:
  lodsw<MemAuto, DirAuto>();
  memoryASet16(es, di, memoryAGet16(es, di) ^ ax);
  di += 0x0050;
  if (--cx)
    goto loc_1aac3;
  push(bp);
  push(dx);
  sub_19c06();
  sub_19bca();
  if (memoryAGet(ds, 0x00cf) == 0x00)
    goto loc_1aae3;
  sub_185ac();
  if (ah != 0x00)
    goto loc_1aae6;
loc_1aae3:
  sub_19c18();
loc_1aae6:
  if (ah != 0x1f)
    goto loc_1aaf3;
  memoryASet(ds, 0x5d11, memoryAGet(ds, 0x5d11) ^ 0x01);
  goto loc_1ab0e;
  //   gap of 1 bytes
loc_1aaf3:
  if (ah != 0x10)
    goto loc_1ab00;
  dx = pop();
  bp = pop();
  memoryASet(ds, 0x5e39, 0x01);
  return;
loc_1ab00:
  if (ah == 0xff)
    goto loc_1ab0e;
  dx = pop();
  bp = pop();
  memoryASet16(ds, 0x4306, 0x0001);
  return;
loc_1ab0e:
  cx = 0x3f80;
loc_1ab11:
  if (--cx)
    goto loc_1ab11;
  dx = pop();
  bp = pop();
  memoryASet(es, 0x42e7, memoryAGet(es, 0x42e7) - 1);
  if (memoryAGet(es, 0x42e7) == 0)
    goto loc_1ab22;
  dx += 0x0002;
  goto loc_1aa74;
loc_1ab22:
  bp++;
}
void sub_1ab24()
{
  ah = 0;
  interrupt(0x1a);
  flags.carry = (dx + 0x9428) >= 0x10000;
  dx += 0x9428;
  cl = 0x03;
  dx = rcr(dx, cl);
  dx += 0xf123;
  cx = dx;
  cx &= 0x0007;
  cx += 0x0005;
}
void sub_1ab3e()
{
  dx = memoryAGet16(ds, 0x4289);
  tl = 0;
  flags.carry = (dx + 0x9428 + tl) >= 0x10000;
  dx += 0x9428 + tl;
  cl = 0x03;
  dx = rcr(dx, cl);
  dx += 0x1357;
  ax = dx;
  ax &= 0x07ff;
  al = ah;
  cbw();
  memoryASet16(ds, 0x4289, dx);
  flags.carry = !!(dl & 0x80);
  dl <<= 1;
  if (!flags.carry)
    return;
  ax = -ax;
}
void sub_1ab61()
{
  dx = 0x40f2;
  bp = 0x41b0;
  memoryASet16(ds, 0x4604, 0x0000);
  memoryASet16(ds, 0x42e4, 0x0014);
loc_1ab73:
  si = bp;
  cx = 0x000a;
  ah = 0;
  memoryASet16(ds, 0x42e4, memoryAGet16(ds, 0x42e4) - 1);
loc_1ab7e:
  lodsb<MemAuto, DirAuto>();
  al |= ah;
  if (!al)
    goto loc_1ab89;
  cx--;
  if (cx != 0)
    goto loc_1ab7e;
  goto loc_1aba7;
  //   gap of 1 bytes
loc_1ab89:
  bp -= 0x000a;
  if ((short)bp >= (short)dx)
    goto loc_1ab73;
  if (dx != 0x40f2)
    goto loc_1ab99;
  return;
  //   gap of 1 bytes
loc_1ab99:
  cx = dx;
  di = 0x40f2;
  cx -= di;
  ax = 0;
  rep_stosw<MemAuto, DirAuto>();
  return;
  //   gap of 1 bytes
loc_1aba7:
  cx = memoryAGet16(ds, 0x42e4);
  bx = memoryAGet16(ds, 0x4604);
  bx <<= 1;
  memoryASet16(ds, bx + 17926, cx);
  memoryASet16(ds, 0x4604, memoryAGet16(ds, 0x4604) + 1);
  memoryASet16(ds, 0x40e8, memoryAGet16(ds, 0x40e8) + 1);
  if (bp != dx)
    goto loc_1abdc;
  ax = 0;
  di = bp;
  cx = 0x0005;
  rep_stosw<MemAuto, DirAuto>();
  dx = 0x40f2;
  if (dx == bp)
    return;
  di = dx;
  cx = bp;
  cx -= dx;
  rep_stosw<MemAuto, DirAuto>();
  return;
  //   gap of 1 bytes
loc_1abdc:
  bx = bp;
  ax = bp;
loc_1abe0:
  ax -= 0x000a;
  si = ax;
  di = bx;
  cx = 0x0005;
  rep_movsw<MemAuto, MemAuto, DirAuto>();
  if ((short)ax <= (short)dx)
    goto loc_1abf5;
  bx -= 0x000a;
  goto loc_1abe0;
loc_1abf5:
  dx += 0x000a;
  goto loc_1ab73;
}
void sub_1abfc()
{
  if (memoryAGet(ds, 0x4282) != 0x00)
    goto loc_1ac04;
  return;
loc_1ac04:
  si = memoryAGet16(ds, 0x42a6);
  di = 0x40f2;
  ax = 0;
  al = memoryAGet(ds, 0x4282);
  al--;
  di += ax;
  al = memoryAGet(ds, 0x4283);
  bx = 0x000a;
  mul(bx);
  di += ax;
  bx = di;
  dh = 0;
  dl = memoryAGet(ds, si);
  memoryASet16(ds, 0x023f, dx);
  dh = memoryAGet(ds, si + 1);
  si += 0x0002;
  bp = si;
loc_1ac30:
  cl = dh;
loc_1ac32:
  if (memoryAGet(es, di) == 0x00)
    goto loc_1ac40;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_1ac40;
  return;
  //   gap of 1 bytes
loc_1ac40:
  si += memoryAGet16(ds, 0x023f);
  di += 0x000a;
  cl--;
  if (cl != 0)
    goto loc_1ac32;
  bx++;
  bp++;
  si = bp;
  di = bx;
  dl--;
  if (dl != 0)
    goto loc_1ac30;
  memoryASet(ds, 0x4282, memoryAGet(ds, 0x4282) - 1);
}
void sub_1acae()
{
  push(es);
  cx = 0xa000;
  es = cx;
  sub_189a1();
  ch = ah;
  memoryASet(ds, 0x42a5, al);
  al = 0x01;
  sub_188cd();
  al = 0xff;
  sub_188e1();
  al = 0x0f;
  sub_188b9();
loc_1accb:
  push(di);
  cl = memoryAGet(ds, 0x42a5);
  bx = 0;
loc_1acd2:
  push(cx);
  push(di);
  bl = memoryAGet(ds, bp);
  bx <<= 1;
  si = memoryAGet16(ds, bx + 208);
  ch = 0x08;
loc_1ace0:
  al = memoryAGet(es, si);
  si++;
  stosb<MemAuto, DirAuto>();
  di += 0x0027;
  ch--;
  if (ch != 0)
    goto loc_1ace0;
  di = pop();
  di += 0x0001;
  cx = pop();
  bp++;
  cl--;
  if (cl != 0)
    goto loc_1acd2;
  di = pop();
  di += 0x0140;
  ch--;
  if (ch == 0)
    goto loc_1ad01;
  goto loc_1accb;
loc_1ad01:
  es = pop();
}
void sub_1ad03()
{
  push(es);
  cx = 0xa000;
  es = cx;
  cx = 0;
  memoryASet16(ds, 0x4306, di);
  di += memoryAGet16(cs, 0x0320);
  ch = ah;
  memoryASet(ds, 0x42a5, al);
  dx = di;
  al = 0x0f;
  sub_188b9();
  al = 0xff;
  sub_188e1();
  al = 0x01;
  sub_188cd();
loc_1ad2a:
  di = dx;
  cl = memoryAGet(ds, 0x42a5);
  bx = 0;
loc_1ad32:
  push(cx);
  push(di);
  bl = memoryAGet(ds, bp);
  if (!bl)
    goto loc_1ad58;
  bx <<= 1;
  si = memoryAGet16(ds, 0x0140);
  si <<= 1;
  si = memoryAGet16(ds, si + 327);
  si = memoryAGet16(ds, bx + si);
  ch = 0x08;
loc_1ad4c:
  al = memoryAGet(es, si);
  si++;
  stosb<MemAuto, DirAuto>();
  di += 0x0027;
  ch--;
  if (ch != 0)
    goto loc_1ad4c;
loc_1ad58:
  di = pop();
  di += 0x0001;
  cx = pop();
  bp++;
  cl--;
  if (cl != 0)
    goto loc_1ad32;
  dx += 0x0140;
  ch--;
  if (ch == 0)
    goto loc_1ad6c;
  goto loc_1ad2a;
loc_1ad6c:
  memoryASet16(ds, 0x0140, memoryAGet16(ds, 0x0140) ^ 0x0001);
  es = pop();
}
void sub_1ad74()
{
  si = memoryAGet16(ds, 0x42a6);
  ch = 0;
  cl = memoryAGet(ds, 0x4282);
  di = 0x40f2;
  di += cx;
  ah = 0;
  al = memoryAGet(ds, 0x4283);
  if (al != 0x13)
    goto loc_1ad94;
  if (memoryAGet(ds, si + 1) == 0x01)
    goto loc_1ad94;
  al--;
loc_1ad94:
  bx = 0x000a;
  mul(bx);
  di += ax;
  lodsb<MemAuto, DirAuto>();
  dh = al;
  lodsb<MemAuto, DirAuto>();
  dl = al;
  cl = dh;
  memoryASet16(ds, 0x023f, 0x000a);
  memoryASet16(ds, 0x023f, memoryAGet16(ds, 0x023f) - cx);
  if (memoryAGet(ds, 0x4283) != 0x00)
    goto loc_1adb7;
  goto loc_1add5;
  //   gap of 1 bytes
loc_1adb7:
  cl = dh;
loc_1adb9:
  if (memoryAGet(es, di) != 0x00)
    goto loc_1adc4;
  al = memoryAGet(ds, si);
  memoryASet(es, di, al);
loc_1adc4:
  si++;
  di++;
  cl--;
  if (cl != 0)
    goto loc_1adb9;
  di += memoryAGet16(ds, 0x023f);
  dl--;
  if (dl != 0)
    goto loc_1adb7;
  return;
  //   gap of 1 bytes
loc_1add5:
  cl = dh;
loc_1add7:
  if (memoryAGet(es, di) == 0x00)
    goto loc_1ade5;
  if (memoryAGet(ds, si) != 0x00)
    goto loc_1ade5;
  goto loc_1adea;
  //   gap of 1 bytes
loc_1ade5:
  al = memoryAGet(ds, si);
  memoryASet(es, di, al);
loc_1adea:
  si++;
  di++;
  cl--;
  if (cl != 0)
    goto loc_1add7;
  di += memoryAGet16(ds, 0x023f);
  dl--;
  if (dl != 0)
    goto loc_1add5;
}
void sub_1adf9()
{
  si = memoryAGet16(ds, 0x42a6);
  al = memoryAGet(ds, si);
  al += memoryAGet(ds, 0x4282);
  if ((char)al <= (char)0x09)
    goto loc_1ae08;
  return;
loc_1ae08:
  di = 0x40f2;
  ax = 0;
  al = memoryAGet(ds, 0x4283);
  bx = 0x000a;
  mul(bx);
  di += ax;
  dx = 0;
  dl = memoryAGet(ds, 0x4282);
  di += dx;
  dl = memoryAGet(ds, si);
  di += dx;
  memoryASet16(ds, 0x023f, dx);
  bx = di;
  dh = memoryAGet(ds, si + 1);
  si += 0x0001;
  si += memoryAGet16(ds, 0x023f);
  bp = si;
loc_1ae35:
  cl = dh;
loc_1ae37:
  if (memoryAGet(ds, di) == 0x00)
    goto loc_1ae44;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_1ae44;
  return;
  //   gap of 1 bytes
loc_1ae44:
  si += memoryAGet16(ds, 0x023f);
  di += 0x000a;
  cl--;
  if (cl != 0)
    goto loc_1ae37;
  bx--;
  bp--;
  di = bx;
  si = bp;
  dl--;
  if (dl != 0)
    goto loc_1ae35;
  memoryASet(ds, 0x4282, memoryAGet(ds, 0x4282) + 1);
}
void sub_1ae5e()
{
  if (memoryAGet(ds, 0x0243) != 0x01)
    goto loc_1ae66;
  return;
loc_1ae66:
  ax = 0;
  bx = memoryAGet16(ds, 0x428b);
  bx--;
  al = memoryAGet(ds, 0x4285);
  al++;
  if ((char)al <= (char)memoryAGet(ds, bx + 17114))
    goto loc_1ae7a;
  al = 0;
loc_1ae7a:
  bx <<= 1;
  bp = memoryAGet16(ds, bx + 547);
  si = memoryAGet16(ds, bx + 561);
  bp += ax;
  si += ax;
  cl = memoryAGet(ds, 0x4282);
  cl += memoryAGet(ds, si);
  if ((char)cl >= (char)0x00)
    goto loc_1ae94;
  return;
loc_1ae94:
  memoryASet(ds, 0x0246, cl);
  si = memoryAGet16(ds, bx + 515);
  memoryASet(ds, 0x0245, al);
  ax <<= 1;
  si += ax;
  si = memoryAGet16(ds, si);
  cl += memoryAGet(ds, si);
  cl--;
  if ((char)cl <= (char)0x09)
    goto loc_1aeaf;
  return;
loc_1aeaf:
  ch = memoryAGet(ds, 0x4283);
  ch += memoryAGet(ds, bp);
  memoryASet(ds, 0x4286, ch);
  ch += memoryAGet(ds, si + 1);
  if ((char)ch <= (char)0x13)
    goto loc_1aec4;
  return;
loc_1aec4:
  di = 0x40f2;
  al = memoryAGet(ds, 0x0246);
  di += ax;
  al = memoryAGet(ds, 0x4286);
  bx = 0x000a;
  mul(bx);
  di += ax;
  lodsb<MemAuto, DirAuto>();
  ah = memoryAGet(ds, si);
  si++;
  dx = 0x000a;
  dl -= al;
loc_1aedf:
  cl = al;
loc_1aee1:
  if (memoryAGet(ds, di) == 0x00)
    goto loc_1aeee;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_1aeee;
  return;
  //   gap of 1 bytes
loc_1aeee:
  si++;
  di++;
  cl--;
  if (cl != 0)
    goto loc_1aee1;
  di += dx;
  ah--;
  if (ah != 0)
    goto loc_1aedf;
  al = memoryAGet(ds, 0x0245);
  memoryASet(ds, 0x4285, al);
  al = memoryAGet(ds, 0x4286);
  memoryASet(ds, 0x4283, al);
  al = memoryAGet(ds, 0x0246);
  memoryASet(ds, 0x4282, al);
  memoryASet(ds, 0x0142, 0x00);
}
void sub_1af12()
{
loc_1af12:
  if (memoryAGet(ds, 0x428f) == 0x01)
    return;
  memoryASet(ds, 0x4283, memoryAGet(ds, 0x4283) + 1);
  sub_1af7c();
  goto loc_1af12;
}
void sub_1af23()
{
  memoryASet(ds, 0x42a4, memoryAGet(ds, 0x42a4) + 1);
  al = memoryAGet(ds, 0x42a4);
  bx = memoryAGet16(ds, 0x40c9);
  if (memoryAGet(ds, 0x0243) != 0x01)
    goto loc_1af3e;
  if ((char)al < (char)memoryAGet(ds, bx + 17050))
    return;
  goto loc_1af44;
  //   gap of 1 bytes
loc_1af3e:
  if ((char)al < (char)memoryAGet(ds, bx + 17040))
    return;
loc_1af44:
  memoryASet(ds, 0x42a4, 0x00);
  memoryASet(ds, 0x4283, memoryAGet(ds, 0x4283) + 1);
  memoryASet(ds, 0x0244, 0x00);
  memoryASet(ds, 0x0243, 0x00);
}
void sub_1af58()
{
  bp = memoryAGet16(ds, 0x428b);
  bp--;
  bp <<= 1;
  bp = memoryAGet16(ds, bp + 515);
  bx = 0;
  bl = memoryAGet(ds, 0x4285);
  bx <<= 1;
  bp += bx;
  bp = memoryAGet16(ds, bp);
  memoryASet16(ds, 0x42a6, bp);
  memoryASet(ds, 0x0142, 0x01);
}
void sub_1af7c()
{
  bp = memoryAGet16(ds, 0x42a6);
  ax = 0;
  al = memoryAGet(ds, 0x4283);
  al += memoryAGet(ds, bp + 1);
  if ((char)al <= (char)0x13)
    goto loc_1af93;
loc_1af8d:
  memoryASet(ds, 0x428f, 0x01);
  return;
loc_1af93:
  bx = 0x000a;
  mul(bx);
  cx = 0;
  cl = memoryAGet(ds, 0x4282);
  ax += cx;
  di = 0x40f2;
  di += ax;
  dx = di;
  cx = 0;
  cl = memoryAGet(ds, bp);
loc_1afad:
  memoryASet(es, di, memoryAGet(es, di) | 0x00);
  if (!memoryAGet(es, di))
    goto loc_1afb9;
  di++;
  cx--;
  if (cx != 0)
    goto loc_1afad;
  goto loc_1af8d;
loc_1afb9:
  di = dx;
  bx = 0;
  ax = 0;
  al = memoryAGet(ds, bp);
  memoryASet16(ds, 0x023f, ax);
  bl = memoryAGet(ds, bp + 1);
  bl--;
  mul(bx);
  si = 0x0002;
  si += bp;
  si += ax;
  dl = memoryAGet(ds, bp + 1);
loc_1afd9:
  cl = memoryAGet(ds, bp);
loc_1afdd:
  if (memoryAGet(ds, di) == 0x00)
    goto loc_1afe9;
  if (memoryAGet(ds, si) == 0x00)
    goto loc_1afe9;
  goto loc_1af8d;
loc_1afe9:
  si++;
  di++;
  cl--;
  if (cl != 0)
    goto loc_1afdd;
  di -= memoryAGet16(ds, 0x023f);
  di -= 0x000a;
  si -= memoryAGet16(ds, 0x023f);
  si -= memoryAGet16(ds, 0x023f);
  dl--;
  if (dl != 0)
    goto loc_1afd9;
  memoryASet(ds, 0x428f, 0x00);
}
