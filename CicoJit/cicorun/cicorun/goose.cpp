#include "cicoemu.h"
#include <stdio.h>

using namespace CicoContext;
void sub_10010();
void sub_11108();
void sub_1176c();
void sub_11783();
void sub_110c6();
void sub_117ac();
void sub_117d6();
void sub_118a9();
void sub_11a9e();
void sub_11993();
void sub_119c2();
void sub_12e02();
void sub_12fe8();
void sub_1300a();
void sub_116fe();
void sub_112cb();
void sub_112eb();
void sub_115fc();
void sub_116df();
void sub_116d6();
void sub_11740();
void sub_11384();
void sub_113a8();
void sub_114f0();
void sub_110f3();
void sub_118c7();
void sub_11429();
void sub_117f4();
void sub_1171f();
void sub_11b09();
void sub_11b4a();
void sub_12f50();
void sub_112a7();
void sub_10600();
void sub_1333c();
void sub_12762();
void sub_105ec();
void sub_10442();
void sub_10588();
void sub_10591();
void sub_1382a();
void sub_100a9();
void sub_100cf();
void sub_100fd();
void sub_11b80();
void sub_11bb9();
void sub_11b57();
void sub_11c78();
void sub_10a51();
void sub_11c56();
void sub_11c33();
void sub_11d1e();
void sub_11cd9();
void sub_10b58();
void sub_13840();
void sub_12121();
void sub_1215b();
void sub_11f0b();
void sub_12005();
void sub_11fba();
void sub_11a04();
void sub_1309d();
void sub_13084();
void sub_13130();
void sub_13059();
void sub_110a0();
void sub_107fd();
void sub_12092();
void sub_10ad5();
void sub_11c0a();
void sub_120db();
void sub_12662();
void sub_12047();
void sub_120f0();
void sub_12676();
void sub_11def();
void sub_1196f();
void sub_12099();
void sub_12b28();
void sub_10637();
void sub_133b3();
void sub_133d7();
void sub_10644();
void sub_10103();
void sub_10da7();
void sub_13423();
void sub_121dc();
void sub_101c0();
void sub_10fda();
void sub_132fe();
void sub_10b8e();
void sub_134a8();
void sub_131a4();
void sub_1220d();
void sub_13383();
void sub_108ba();
void sub_13914();
void sub_1315e();
void sub_13170();
void sub_13181();
void sub_13191();
void sub_1268a();
void sub_120a0();
void sub_109b5();
void sub_1269e();
void sub_11e7d();
void sub_12cea();
void sub_1064d();
void sub_1279f();
void sub_128da();
void sub_139b8();
void sub_13472();
void sub_10d98();
void sub_13498();
void sub_129db();
void sub_101ad();
void sub_1019d();
void sub_109a4();
void sub_1069a();
void sub_10e3d();
void sub_13439();
void sub_12200();
void sub_1264a();
void sub_12a7f();
void sub_122b1();
void sub_1033b();
void sub_12c45();
void sub_10529();
void sub_10e07();
void sub_10f3c();
void sub_10dc0();
void sub_10e84();
void sub_10bdc();
void sub_136d4();
void sub_135bc();
void sub_131e7();
void sub_13209();
void sub_12714();
void sub_1252f();
void sub_12542();
void sub_12577();
void sub_1258a();
void sub_125bf();
void sub_125d2();
void sub_12464();
void sub_1239b();
void sub_1094a();
void sub_109e9();
void sub_10a1b();
void sub_122c1();
void sub_12809();
void sub_12959();
void sub_12907();
void sub_133e5();
void sub_13291();
void sub_10b7c();
void sub_10541();
void sub_12a64();
void sub_10674();
void sub_107af();
void sub_10bc5();
void sub_1250b();
void sub_12553();
void sub_1259b();
void sub_1237c();
void sub_122e1();
void sub_122f9();
void sub_12311();
void sub_12c07();
void sub_12c9a();
void sub_104f3();
void sub_12d9a();
void sub_12329();
void sub_12ddc();
void sub_12df6();
void sub_10f9d();
void sub_10c24();
void sub_13801();
void sub_125e3();
void sub_12536();
void sub_1257e();
void sub_125c6();
void sub_12872();
void sub_129ae();
void sub_1296f();
void sub_123d4();
void sub_123ec();
void sub_12404();
void sub_1241c();
void sub_12434();
void sub_1244c();
void sub_12cc7();


void start()
{
  cs = 0x1000;
  ss = 0x1cfc;
  sp = 0x0100;
  sub_10010();
}
// extracting 1000:0010, converted 1, to convert 35, failed 0
void sub_10010()
{
ax = 0x13a5;
ds = ax;
bx = 0x9670;
bx += 0x000f;
bx >>= 1;
bx >>= 1;
bx >>= 1;
bx >>= 1;
ax += bx;
memory16(ds, 0x94e8) = ax;
ax += 0x0800;
memory16(ds, 0x94ea) = ax;
ax += 0x0800;
memory16(ds, 0x94ec) = ax;
ax += 0x0800;
memory16(ds, 0x94ee) = ax;
ax += 0x0800;
memory16(ds, 0x94f0) = ax;
ax += 0x0800;
memory16(ds, 0x94f2) = ax;
ax += 0x0800;
memory16(ds, 0x94f4) = ax;
ax += 0x0800;
memory16(ds, 0x94f6) = ax;
interrupt(0x12);
if (ax >= 0x0200)
goto loc_10067;
dx = 0x0007;
ah = 0x09;
interrupt(0x21);
ax = 0x4c00;
interrupt(0x21);
goto loc_1006e;
loc_10067:
dx = 0x002a;
ah = 0x09;
interrupt(0x21);
loc_1006e:
sub_10600();
sub_1333c();
sub_12762();
sub_105ec();
sub_10442();
sub_10588();
sub_10591();
sub_1382a();
memory(ds, 0x9501) = 0x00;
loc_1008b:
sub_100a9();
sub_100cf();
sub_100fd();
goto loc_1008b;
}
// extracting 1000:1108, converted 2, to convert 45, failed 0
void sub_11108()
{
sub_11b80();
sub_11bb9();
bx = memory16(ds, 0x954c);
ax = memory16(ds, 0x952c);
if (!(bl & 0x01))
goto loc_11131;
ax -= 0x0001;
if ((short)ax < 0)
goto loc_11127;
if ((short)ax <= (short)0x0004)
goto loc_11127;
ax = 0x0004;
loc_11127:
if ((short)ax >= (short)0xffe8)
goto loc_1112f;
ax = 0xffe8;
loc_1112f:
goto loc_11158;
loc_11131:
if (!(bl & 0x02))
goto loc_1114d;
ax += 0x0001;
if ((short)ax >= 0)
goto loc_11143;
if ((short)ax >= (short)0xfffc)
goto loc_11143;
ax = 0xfffc;
loc_11143:
if ((short)ax <= (short)0x0018)
goto loc_1114b;
ax = 0x0018;
loc_1114b:
goto loc_11158;
loc_1114d:
if (ax == 0x0000)
goto loc_11158;
if ((short)ax <= (short)0x0000)
goto loc_11157;
ax--;
goto loc_11158;
loc_11157:
ax++;
loc_11158:
memory16(ds, 0x952c) = ax;
ax += 0x0003;
sar(ax, 1);
sar(ax, 1);
ax += memory16(ds, 0x1b8f);
if ((short)ax >= (short)0x0014)
goto loc_11174;
ax = 0x0014;
memory16(ds, 0x952c) = 0x0000;
loc_11174:
if ((short)ax <= (short)0x00ec)
goto loc_11182;
ax = 0x00ec;
memory16(ds, 0x952c) = 0x0000;
loc_11182:
memory16(ds, 0x1b8f) = ax;
al = memory(ds, 0x1b8e);
if (al == 0x00)
goto loc_1118f;
sub_11b57();
loc_1118f:
sub_11c78();
sub_10a51();
if (ax == 0x0000)
goto loc_1119f;
sub_11c56();
goto loc_111bc;
loc_1119f:
memory(ds, 0x1b9e)++;
memory(ds, 0x1b9e) &= 0x3f;
sub_10a51();
if (ax == 0x0000)
goto loc_111b3;
sub_11c56();
loc_111b3:
memory(ds, 0x1b9e)--;
memory(ds, 0x1b9e) &= 0x3f;
loc_111bc:
ax = memory16(ds, 0x9542);
if ((short)ax > (short)0x0000)
goto loc_111c8;
sub_11c33();
return;
loc_111c8:
al = memory(ds, 0x1b8e);
if (al != 0x00)
goto loc_111de;
memory(ds, 0x9515)++;
al = memory(ds, 0x9515);
if (al < 0x04)
goto loc_111dd;
sub_11c33();
loc_111dd:
return;
loc_111de:
ax = memory16(ds, 0x953e);
if ((short)ax <= (short)0x0000)
goto loc_111f0;
ax = memory16(ds, 0x954c);
if (!(al & 0x80))
goto loc_111f0;
sub_11d1e();
loc_111f0:
ax = memory16(ds, 0x954c);
bl = memory(ds, 0x951a);
if (!(al & 0x40))
goto loc_11235;
if (bl != 0x00)
goto loc_11224;
ax = memory16(ds, 0x9536);
if (ax <= 0x0000)
goto loc_11222;
memory(ds, 0x951a) = 0x01;
si = 0x0dc3;
memory(ds, si) &= 0xdf;
sub_11cd9();
sub_10b58();
memory16(ds, 0x9538)--;
al = 0x01;
sub_13840();
loc_11222:
goto loc_11233;
loc_11224:
if (bl != 0x02)
goto loc_11233;
memory(ds, 0x951a) = 0x03;
al = 0x02;
sub_13840();
loc_11233:
goto loc_1124b;
loc_11235:
if (bl != 0x01)
goto loc_11241;
memory(ds, 0x951a) = 0x02;
goto loc_1124b;
loc_11241:
if (bl != 0x03)
goto loc_1124b;
memory(ds, 0x951a) = 0x00;
loc_1124b:
ax = memory16(ds, 0x954c);
bl = memory(ds, 0x951b);
if (!(al & 0x20))
goto loc_11290;
if (bl != 0x00)
goto loc_1127f;
ax = memory16(ds, 0x9536);
if (ax <= 0x0000)
goto loc_1127d;
memory(ds, 0x951b) = 0x01;
si = 0x0dc3;
memory(ds, si) |= 0x20;
sub_11cd9();
sub_10b58();
memory16(ds, 0x9538)--;
al = 0x01;
sub_13840();
loc_1127d:
goto loc_1128e;
loc_1127f:
if (bl != 0x02)
goto loc_1128e;
memory(ds, 0x951b) = 0x03;
al = 0x02;
sub_13840();
loc_1128e:
return;
loc_11290:
if (bl != 0x01)
goto loc_1129c;
memory(ds, 0x951b) = 0x02;
return;
loc_1129c:
if (bl != 0x03)
return;
memory(ds, 0x951b) = 0x00;
}
// extracting 1000:176c, converted 3, to convert 63, failed 0
void sub_1176c()
{
memory(ds, si + 22)++;
al = memory(ds, si + 22);
al >>= 1;
al &= 0x03;
memory(ds, si + 4) = al;
bx = 0x0e2b;
sub_12121();
sub_110c6();
}
// extracting 1000:1783, converted 4, to convert 64, failed 0
void sub_11783()
{
memory(ds, si + 22)++;
al = memory(ds, si + 22);
al >>= 1;
al &= 0x07;
if (al < 0x06)
goto loc_11797;
al = 0x00;
memory(ds, si + 22) = 0x00;
loc_11797:
bl = al;
bh = 0x00;
al = memory(ds, bx + 3660);
memory(ds, si + 4) = al;
bx = 0x0e52;
sub_12121();
sub_110c6();
}
// extracting 1000:10c6, converted 5, to convert 65, failed 0
void sub_110c6()
{
al = memory(ds, si + 3);
al += memory(ds, si + 12);
cbw();
ax = -ax;
ax += memory16(ds, si + 7);
ax &= 0x03ff;
bx = memory16(ds, 0x9528);
bx += 0x00a0;
bx &= 0x03ff;
if (ax >= bx)
goto loc_110e8;
ax += 0x0400;
loc_110e8:
ax -= bx;
if (ax >= 0x0200)
return;
memory(ds, si) = 0x00;
}
// extracting 1000:17ac, converted 6, to convert 64, failed 0
void sub_117ac()
{
sub_1215b();
if (cx == 0x0000)
goto loc_117cc;
memory(ds, si + 22)--;
if ((char)memory(ds, si + 22) >= 0)
goto loc_117c4;
memory(ds, si + 22) = 0x08;
memory(ds, 0x9518) = 0x01;
goto loc_117c9;
loc_117c4:
memory(ds, 0x9518) = 0x00;
loc_117c9:
sub_11f0b();
loc_117cc:
bx = 0x0e73;
sub_12121();
sub_110c6();
}
// extracting 1000:17d6, converted 7, to convert 67, failed 0
void sub_117d6()
{
sub_1215b();
if (cx == 0x0000)
goto loc_117ea;
memory(ds, si + 22)--;
if ((char)memory(ds, si + 22) >= 0)
goto loc_117ea;
memory(ds, si + 22) = 0x12;
sub_12005();
loc_117ea:
bx = 0x0e9c;
sub_12121();
sub_110c6();
}
// extracting 1000:18a9, converted 8, to convert 70, failed 0
void sub_118a9()
{
sub_1215b();
if (cx == 0x0000)
goto loc_118bd;
memory(ds, si + 22)--;
if ((char)memory(ds, si + 22) >= 0)
goto loc_118bd;
memory(ds, si + 22) = 0x28;
sub_11fba();
loc_118bd:
bx = 0x0ec5;
sub_12121();
sub_110c6();
}
// extracting 1000:1a9e, converted 9, to convert 73, failed 0
void sub_11a9e()
{
sub_110c6();
al = memory(ds, si);
if (al != 0x00)
goto loc_11aa8;
return;
loc_11aa8:
bx = memory16(ds, 0x1b91);
bx -= memory16(ds, si + 7);
if ((short)bx >= 0)
goto loc_11abb;
if ((short)bx >= (short)0xfff0)
goto loc_11aba;
memory(ds, si + 2) = 0x01;
loc_11aba:
return;
loc_11abb:
if ((short)bx <= (short)0x0020)
goto loc_11ac1;
return;
loc_11ac1:
ax = memory16(ds, 0x1b8f);
ax -= memory16(ds, si + 5);
ax -= 0x000c;
if ((short)ax >= 0)
goto loc_11ad9;
ax = -ax;
if (ax >= 0x0018)
goto loc_11ad7;
memory16(ds, 0x1b8f)++;
loc_11ad7:
goto loc_11ae7;
loc_11ad9:
if (ax >= 0x0018)
goto loc_11ae7;
if (ax == 0x0000)
goto loc_11ae7;
memory16(ds, 0x1b8f)--;
loc_11ae7:
if (bx <= 0x0008)
goto loc_11aed;
return;
loc_11aed:
if (ax > 0x0002)
goto loc_11af8;
memory16(ds, 0x9538)++;
return;
loc_11af8:
if (ax >= 0x0024)
return;
memory16(ds, 0x9542) = 0x0000;
al = 0x06;
sub_13840();
}
// extracting 1000:1993, converted 10, to convert 73, failed 0
void sub_11993()
{
sub_11a04();
al = memory(ds, 0x94ff);
if (al != 0x01)
return;
al = memory(ds, 0x9501);
bl = al;
al <<= 1;
bl += al;
bl += memory(ds, 0x9502);
bh = 0x00;
bx <<= 1;
ax = memory16(ds, bx + 5269);
bh = ah;
ax &= 0x03ff;
memory16(ds, 0x950c) = ax;
bh &= 0xc0;
memory(ds, 0x951d) = bh;
}
// extracting 1000:19c2, converted 11, to convert 73, failed 0
void sub_119c2()
{
sub_11a04();
al = memory(ds, 0x94ff);
if (al != 0x01)
return;
al = memory(ds, 0x9501);
bl = al;
al <<= 1;
bl += al;
bl += memory(ds, 0x9502);
bh = 0x00;
bx <<= 1;
ax = memory16(ds, bx + 5317);
bh = ah;
ax &= 0x03ff;
memory16(ds, 0x950c) = ax;
bh &= 0xc0;
memory(ds, 0x951d) = bh;
memory(ds, 0x950e) = 0x01;
al = memory(ds, 0x9502);
al++;
if (al <= 0x02)
goto loc_11a00;
al = 0x00;
loc_11a00:
memory(ds, 0x9502) = al;
}
// extracting 1000:2e02, converted 12, to convert 73, failed 0
void sub_12e02()
{
push(si);
sub_11b80();
sub_1309d();
pop(si);
ax = memory16(ds, 0x952a);
ax >>= 1;
ax >>= 1;
ax >>= 1;
bx = memory16(ds, 0x954c);
if (!(bl & 0x01))
goto loc_12e23;
ax = -ax;
ax -= 0x0003;
goto loc_12e30;
loc_12e23:
if (!(bl & 0x02))
goto loc_12e2d;
ax += 0x0003;
goto loc_12e30;
loc_12e2d:
ax = 0x0000;
loc_12e30:
memory16(ds, 0x9522) = ax;
al = memory(ds, si + 22);
ax &= 0x007f;
if (al <= 0x3f)
goto loc_12e48;
al = -al;
al += 0x7f;
sub_13084();
ax = -ax;
goto loc_12e4b;
loc_12e48:
sub_13084();
loc_12e4b:
memory16(ds, 0x9520) = ax;
ax = memory16(ds, 0x951e);
ax += memory16(ds, 0x9522);
ax += memory16(ds, 0x9520);
if (ax == 0)
goto loc_12e6a;
if ((short)ax >= 0)
goto loc_12e63;
ax++;
if ((short)ax >= 0)
goto loc_12e61;
ax++;
loc_12e61:
goto loc_12e6a;
loc_12e63:
ax--;
if ((short)ax <= (short)0x0000)
goto loc_12e6a;
ax--;
loc_12e6a:
if ((short)ax <= (short)0x0040)
goto loc_12e74;
ax = 0x0040;
goto loc_12e7c;
loc_12e74:
if ((short)ax >= (short)0xffc0)
goto loc_12e7c;
ax = 0xffc0;
loc_12e7c:
memory16(ds, 0x951e) = ax;
sar(ax, 1);
sar(ax, 1);
memory(ds, si + 22) += al;
al = memory(ds, si + 22);
ax &= 0x007f;
bx = ax;
al = memory(ds, bx + 5749);
cbw();
ax <<= 1;
ax += 0x0080;
memory16(ds, si + 5) = ax;
al = memory(ds, bx + 5877);
cbw();
ax <<= 1;
ax += 0x0080;
push(bx);
if (ax == 0x0000)
goto loc_12ebe;
bx = ax;
ax <<= 1;
ax <<= 1;
ax += bx;
ax <<= 1;
ax += 0x0005;
bl = 0x0c;
div(bl);
ah = 0x00;
loc_12ebe:
pop(bx);
memory16(ds, si + 7) = ax;
al = memory(ds, bx + 6005);
memory(ds, si + 4) = al;
bx = 0x1594;
sub_12121();
al = memory(ds, 0x94e6);
memory(ds, 0x94e7) = al;
al = memory(ds, 0x94e5);
memory(ds, 0x94e6) = al;
al = memory(ds, 0x1ba0);
memory(ds, 0x94e5) = al;
ax = memory16(ds, 0x954c);
bl = memory(ds, 0x951a);
if (!(al & 0x40))
goto loc_12f02;
if (bl != 0x02)
goto loc_12f00;
memory(ds, 0x951a) = 0x03;
al = 0x02;
sub_13840();
memory(ds, 0x951c) = 0x02;
loc_12f00:
goto loc_12f18;
loc_12f02:
if (bl != 0x01)
goto loc_12f0e;
memory(ds, 0x951a) = 0x02;
goto loc_12f18;
loc_12f0e:
if (bl != 0x03)
goto loc_12f18;
memory(ds, 0x951a) = 0x00;
loc_12f18:
ax = memory16(ds, 0x954c);
bl = memory(ds, 0x951b);
if (!(al & 0x20))
goto loc_12f39;
if (bl != 0x02)
goto loc_12f37;
memory(ds, 0x951b) = 0x03;
al = 0x02;
sub_13840();
memory(ds, 0x951c) = 0x02;
loc_12f37:
return;
loc_12f39:
if (bl != 0x01)
goto loc_12f45;
memory(ds, 0x951b) = 0x02;
return;
loc_12f45:
if (bl != 0x03)
return;
memory(ds, 0x951b) = 0x00;
}
// extracting 1000:2fe8, converted 13, to convert 78, failed 0
void sub_12fe8()
{
bx = memory16(ds, 0x9525);
bx >>= 1;
bx >>= 1;
bx >>= 1;
bx &= 0x001f;
al = memory(ds, bx + 6666);
memory(ds, 0x9549) = al;
al = memory(ds, bx + 6634);
memory(ds, si + 4) = al;
bx = 0x1929;
sub_12121();
}
// extracting 1000:300a, converted 14, to convert 78, failed 0
void sub_1300a()
{
ax = memory16(ds, 0x9547);
ax -= memory16(ds, si + 19);
ax >>= 1;
ax >>= 1;
ax >>= 1;
if (ax <= 0x002d)
goto loc_1301f;
memory(ds, si) = 0x00;
return;
loc_1301f:
push(ax);
sub_13130();
pop(ax);
ax >>= 1;
memory(ds, si + 4) = al;
bx = ax;
al = memory(ds, bx + 6810);
memory(ds, si + 2) = al;
bx = 0x1ac9;
sub_12121();
al = memory(ds, si + 2);
if (al == 0x02)
goto loc_13040;
return;
loc_13040:
bl = memory(ds, 0x1b8e);
bh = 0x00;
al = memory(ds, bx + 6133);
if (al == memory(ds, si + 1))
goto loc_13050;
return;
loc_13050:
al = 0x09;
sub_13840();
sub_13059();
}
// extracting 1000:16fe, converted 15, to convert 81, failed 0
void sub_116fe()
{
memory(ds, si + 22)++;
al = memory(ds, si + 22);
al >>= 1;
al >>= 1;
al &= 0x07;
if ((char)al < (char)0x05)
goto loc_11712;
memory(ds, si) = 0x00;
return;
loc_11712:
memory(ds, si + 4) = al;
bx = 0x12b5;
sub_12121();
sub_110c6();
}
// extracting 1000:12cb, converted 16, to convert 82, failed 0
void sub_112cb()
{
ax = memory16(ds, 0x952a);
ax--;
if ((short)ax < 0)
goto loc_112d4;
memory16(ds, 0x952a) = ax;
loc_112d4:
sub_11bb9();
sub_11b57();
memory(ds, 0x9514)++;
al = memory(ds, 0x9514);
if (al < 0x28)
return;
memory(ds, 0x9513) = 0x01;
}
// extracting 1000:12eb, converted 17, to convert 82, failed 0
void sub_112eb()
{
sub_110a0();
al = memory(ds, si);
if (al != 0x00)
goto loc_112f5;
return;
loc_112f5:
memory16(ds, si + 7) -= 0x0010;
memory16(ds, si + 7) &= 0x03ff;
al = memory(ds, si + 4);
if (al != 0x01)
goto loc_11312;
al = memory(ds, si + 3);
if ((char)al <= (char)0x9c)
goto loc_11310;
memory(ds, si + 3) -= 0x08;
loc_11310:
goto loc_11321;
loc_11312:
if (al != 0x02)
goto loc_11321;
al = memory(ds, si + 3);
if ((char)al >= (char)0x64)
goto loc_11321;
memory(ds, si + 3) += 0x08;
loc_11321:
push(si);
ax = memory16(ds, si + 5);
push(ax);
ax = memory16(ds, si + 7);
push(ax);
sub_107fd();
pop(si);
if ((char)al < (char)memory(ds, si + 3))
goto loc_11338;
sub_12092();
return;
loc_11338:
push(si);
ax = memory16(ds, si + 5);
push(ax);
memory(ds, si + 20) = cl;
push(cx);
sub_10ad5();
pop(si);
if (ax == 0x0000)
return;
push(si);
al = memory(ds, si + 20);
ah = 0x00;
push(bx);
push(ax);
sub_11c0a();
al = memory(ds, si);
if (al & 0x80)
goto loc_11382;
pop(bx);
push(bx);
al = memory(ds, si + 3);
al -= memory(ds, bx + 3);
if ((char)al >= 0)
goto loc_11367;
al = -al;
loc_11367:
if (al >= 0x10)
goto loc_11382;
memory(ds, si + 21)--;
if ((char)memory(ds, si + 21) >= 0)
goto loc_1137a;
sub_120db();
al = 0x06;
sub_13840();
goto loc_1137d;
loc_1137a:
sub_12662();
loc_1137d:
pop(si);
push(si);
sub_12047();
loc_11382:
pop(si);
}
// extracting 1000:15fc, converted 18, to convert 90, failed 0
void sub_115fc()
{
sub_110c6();
al = memory(ds, si);
if (al != 0x00)
goto loc_11606;
return;
loc_11606:
al = memory(ds, si + 1);
if (al != 0x02)
goto loc_11613;
memory16(ds, si + 7) += 0x0008;
goto loc_1163d;
loc_11613:
if (al != 0x00)
goto loc_1161d;
memory16(ds, si + 5) -= 0x0008;
goto loc_1163d;
loc_1161d:
if (al != 0x01)
goto loc_1162b;
memory16(ds, si + 5) -= 0x0006;
memory16(ds, si + 7) += 0x0004;
goto loc_1163d;
loc_1162b:
if (al != 0x03)
goto loc_11639;
memory16(ds, si + 5) += 0x0006;
memory16(ds, si + 7) += 0x0004;
goto loc_1163d;
loc_11639:
memory16(ds, si + 5) += 0x0008;
loc_1163d:
memory16(ds, si + 7) &= 0x03ff;
ax = memory16(ds, si + 5);
if ((short)ax >= (short)0x0004)
goto loc_1164e;
memory(ds, si) = 0x00;
return;
loc_1164e:
if ((short)ax <= (short)0x00fc)
goto loc_11657;
memory(ds, si) = 0x00;
return;
loc_11657:
al = memory(ds, si + 4);
if (al != 0x01)
goto loc_1166b;
al = memory(ds, si + 3);
if ((char)al >= (char)0x64)
goto loc_11669;
memory(ds, si + 3) += 0x04;
loc_11669:
goto loc_1167a;
loc_1166b:
if (al != 0x02)
goto loc_1167a;
al = memory(ds, si + 3);
if ((char)al <= (char)0x9c)
goto loc_1167a;
memory(ds, si + 3) -= 0x04;
loc_1167a:
push(si);
ax = memory16(ds, si + 5);
push(ax);
ax = memory16(ds, si + 7);
push(ax);
sub_107fd();
pop(si);
if ((char)al < (char)memory(ds, si + 3))
goto loc_11691;
sub_12092();
return;
loc_11691:
al = memory(ds, 0x1b9c);
if (al != 0x11)
goto loc_11699;
return;
loc_11699:
ax = memory16(ds, si + 5);
ax -= memory16(ds, 0x1b8f);
if ((short)ax >= 0)
goto loc_116a4;
ax = -ax;
loc_116a4:
if (ax >= 0x000c)
return;
ax = memory16(ds, si + 7);
ax -= memory16(ds, 0x1b91);
if ((short)ax >= 0)
goto loc_116b4;
ax = -ax;
loc_116b4:
if (ax >= 0x0008)
return;
al = memory(ds, si + 3);
al -= memory(ds, 0x1b8d);
if ((char)al >= 0)
goto loc_116c4;
al = -al;
loc_116c4:
if (al >= 0x10)
return;
memory16(ds, 0x9544) -= 0x0001;
sub_12092();
al = 0x04;
sub_13840();
}
// extracting 1000:16df, converted 19, to convert 94, failed 0
void sub_116df()
{
al = memory(ds, si + 4);
memory(ds, si + 4)++;
if (al < 0x04)
goto loc_116ed;
memory(ds, si) = 0x00;
return;
loc_116ed:
al <<= 1;
bl = al;
bh = 0x00;
ax = memory16(ds, bx + 5182);
memory16(ds, si + 15) = ax;
sub_110c6();
}
// extracting 1000:16d6, converted 20, to convert 94, failed 0
void sub_116d6()
{
memory(ds, si + 4)--;
if ((char)memory(ds, si + 4) >= 0)
return;
memory(ds, si) = 0x00;
}
// extracting 1000:1740, converted 21, to convert 93, failed 0
void sub_11740()
{
memory(ds, si + 22)++;
al = memory(ds, si + 22);
al &= 0x07;
if ((char)al < (char)0x04)
goto loc_11762;
al = memory(ds, si);
if (!(al & 0x20))
goto loc_11759;
memory(ds, 0x9517) &= 0x7f;
goto loc_1175e;
loc_11759:
memory(ds, 0x9517) &= 0xfe;
loc_1175e:
memory(ds, si) = 0x00;
return;
loc_11762:
memory(ds, si + 4) = al;
bx = 0x133d;
sub_12121();
}
// extracting 1000:1384, converted 22, to convert 93, failed 0
void sub_11384()
{
al = memory(ds, 0x1b9c);
if (al != 0x11)
goto loc_1138e;
memory(ds, si) = 0x00;
loc_1138e:
sub_11cd9();
al = memory(ds, si);
if (al & 0x20)
goto loc_1139c;
al = memory(ds, 0x951a);
goto loc_1139f;
loc_1139c:
al = memory(ds, 0x951b);
loc_1139f:
if (al != 0x03)
return;
memory(ds, si + 18) = 0x19;
}
// extracting 1000:13a8, converted 23, to convert 93, failed 0
void sub_113a8()
{
sub_110a0();
al = memory(ds, si);
if (al != 0x00)
goto loc_113b2;
return;
loc_113b2:
memory16(ds, si + 7) -= 0x0006;
memory16(ds, si + 7) &= 0x03ff;
push(si);
ax = memory16(ds, si + 5);
push(ax);
ax = memory16(ds, si + 7);
push(ax);
sub_107fd();
pop(si);
al += 0x04;
memory(ds, si + 3) = al;
memory(ds, si + 20) = cl;
memory(ds, si + 4) = bl;
bx = 0x0dda;
sub_12121();
al = memory(ds, si + 4);
if (al != 0x00)
goto loc_113f5;
memory16(ds, si + 7) += 0x0004;
memory16(ds, si + 7) &= 0x03ff;
memory(ds, si + 21)--;
if ((char)memory(ds, si + 21) >= 0)
goto loc_113f5;
sub_120f0();
memory(ds, si) = 0x00;
return;
loc_113f5:
push(si);
ax = memory16(ds, si + 5);
push(ax);
cl = memory(ds, si + 20);
ch = 0x00;
push(cx);
sub_10ad5();
pop(si);
if (ax == 0x0000)
return;
push(si);
al = memory(ds, si + 20);
ah = 0x00;
push(bx);
push(ax);
sub_11c0a();
al = memory(ds, si);
if (al & 0x80)
goto loc_11427;
sub_120db();
al = 0x06;
sub_13840();
pop(si);
push(si);
memory(ds, si) = 0x00;
loc_11427:
pop(si);
}
// extracting 1000:14f0, converted 24, to convert 100, failed 0
void sub_114f0()
{
memory16(ds, si + 7) += 0x0001;
push(si);
ax = memory16(ds, si + 5);
push(ax);
ax = memory16(ds, si + 7);
push(ax);
sub_107fd();
pop(si);
memory(ds, si + 3) = al;
memory(ds, si + 20) = cl;
memory(ds, si + 4) = bl;
bl = memory(ds, si + 1);
bh = 0x00;
bx <<= 1;
bx = memory16(ds, bx + 4065);
sub_12121();
al = memory(ds, 0x1b9c);
if (al == 0x11)
goto loc_11548;
ax = memory16(ds, si + 5);
ax -= memory16(ds, 0x1b8f);
if ((short)ax >= 0)
goto loc_1152a;
ax = -ax;
loc_1152a:
if (ax >= 0x001a)
goto loc_11548;
ax = memory16(ds, si + 7);
ax -= memory16(ds, 0x1b91);
if ((short)ax >= 0)
goto loc_1153a;
ax = -ax;
loc_1153a:
if (ax >= 0x0012)
goto loc_11548;
memory16(ds, 0x9544) -= 0x000c;
memory(ds, si + 21) = 0xff;
loc_11548:
di = 0x1ba1;
loc_1154b:
al = memory(ds, si + 21);
if ((char)al >= (char)0x00)
goto loc_11561;
al = 0x07;
sub_13840();
sub_120f0();
memory(ds, si) = 0x00;
sub_12676();
return;
loc_11561:
al = memory(ds, di);
if (al & 0x80)
goto loc_115c0;
if (!(al & 0x40))
goto loc_115bb;
push(di);
ax = memory16(ds, di + 5);
ax -= memory16(ds, si + 5);
if ((short)ax >= 0)
goto loc_11576;
ax = -ax;
loc_11576:
if (ax >= 0x0014)
goto loc_115ba;
ax = memory16(ds, di + 7);
ax -= memory16(ds, si + 7);
if ((short)ax >= 0)
goto loc_11585;
ax = -ax;
loc_11585:
if (ax >= 0x0010)
goto loc_115ba;
al = memory(ds, di + 18);
if (al != 0x19)
goto loc_1159a;
memory(ds, si + 21) = 0xff;
memory(ds, di) = 0x00;
goto loc_115ba;
loc_1159a:
al = memory(ds, di + 3);
al -= memory(ds, si + 3);
if ((char)al >= 0)
goto loc_115a4;
al = -al;
loc_115a4:
if (al >= 0x10)
goto loc_115ba;
memory(ds, si + 21)--;
push(si);
si = di;
sub_12092();
al = 0x03;
sub_13840();
sub_12662();
pop(si);
loc_115ba:
pop(di);
loc_115bb:
di += 0x0017;
goto loc_1154b;
loc_115c0:
al = memory(ds, 0x1b9c);
if (al == 0x11)
goto loc_115f8;
ax = memory16(ds, 0x1b91);
if (ax <= memory16(ds, si + 7))
goto loc_115f8;
ax = memory16(ds, 0x1b8f);
ax -= memory16(ds, si + 5);
if ((short)ax >= 0)
goto loc_115d9;
ax = -ax;
loc_115d9:
if (ax >= 0x0020)
goto loc_115f8;
memory(ds, si + 22)--;
if ((char)memory(ds, si + 22) >= 0)
goto loc_115ee;
memory(ds, si + 22) = 0x07;
memory(ds, 0x9518) = 0x01;
goto loc_115f3;
loc_115ee:
memory(ds, 0x9518) = 0x00;
loc_115f3:
push(si);
sub_11def();
pop(si);
loc_115f8:
sub_110c6();
}
// extracting 1000:10f3, converted 25, to convert 109, failed 0
void sub_110f3()
{
memory(ds, si + 22)++;
al = memory(ds, si + 22);
if (al <= 0x08)
goto loc_110ff;
al = 0x08;
loc_110ff:
ah = 0x00;
memory16(ds, si + 7) -= ax;
sub_110a0();
}
// extracting 1000:18c7, converted 26, to convert 109, failed 0
void sub_118c7()
{
al = memory(ds, 0x952e);
al &= memory(ds, 0x952f);
al &= memory(ds, 0x9530);
al &= memory(ds, 0x9531);
al &= memory(ds, 0x9532);
al &= memory(ds, 0x9533);
if (al != 0)
goto loc_118e4;
sub_110c6();
return;
loc_118e4:
ax = memory16(ds, 0x1b8f);
ax -= memory16(ds, si + 5);
ax -= 0x000c;
if ((short)ax >= 0)
goto loc_118f1;
ax = -ax;
loc_118f1:
cx = memory16(ds, 0x1b91);
cx -= 0x0008;
cx -= memory16(ds, si + 7);
if ((short)cx >= 0)
goto loc_118ff;
cx = -cx;
loc_118ff:
bl = memory(ds, si + 4);
bl >>= 1;
ax += cx;
if (ax > 0x0040)
goto loc_11915;
if (bl == 0x08)
goto loc_11913;
memory(ds, si + 4)++;
loc_11913:
goto loc_1191d;
loc_11915:
if (bl == 0x00)
goto loc_1191d;
memory(ds, si + 4)--;
loc_1191d:
push(bx);
bh = 0x00;
bx <<= 1;
ax = memory16(ds, bx + 5251);
memory16(ds, si + 15) = ax;
pop(bx);
if (bl < 0x02)
goto loc_1196b;
ax = memory16(ds, 0x1b8f);
ax -= memory16(ds, si + 5);
ax -= 0x000c;
if ((short)ax >= 0)
goto loc_11947;
ax = -ax;
if (ax > 0x0018)
goto loc_11945;
memory16(ds, 0x1b8f)++;
loc_11945:
goto loc_11952;
loc_11947:
if (ax == 0)
goto loc_11952;
if (ax > 0x0018)
goto loc_11952;
memory16(ds, 0x1b8f)--;
loc_11952:
if (bl != 0x08)
goto loc_1196b;
if (cx > 0x0008)
goto loc_1196b;
if (ax > 0x0008)
goto loc_1196b;
al = memory(ds, 0x1b9c);
if (al == 0x11)
goto loc_1196b;
sub_1196f();
loc_1196b:
sub_110c6();
}
// extracting 1000:1429, converted 27, to convert 111, failed 0
void sub_11429()
{
sub_110c6();
al = memory(ds, si);
if (al != 0x00)
goto loc_11433;
return;
loc_11433:
al = memory(ds, si + 1);
if (al != 0x02)
goto loc_11440;
memory16(ds, si + 7) += 0x0005;
goto loc_1146a;
loc_11440:
if (al != 0x00)
goto loc_1144a;
memory16(ds, si + 5) -= 0x0005;
goto loc_1146a;
loc_1144a:
if (al != 0x01)
goto loc_11458;
memory16(ds, si + 5) -= 0x0003;
memory16(ds, si + 7) += 0x0002;
goto loc_1146a;
loc_11458:
if (al != 0x03)
goto loc_11466;
memory16(ds, si + 5) += 0x0003;
memory16(ds, si + 7) += 0x0002;
goto loc_1146a;
loc_11466:
memory16(ds, si + 5) += 0x0005;
loc_1146a:
memory16(ds, si + 7) &= 0x03ff;
ax = memory16(ds, si + 5);
if ((short)ax >= (short)0x000c)
goto loc_1147b;
memory(ds, si) = 0x00;
return;
loc_1147b:
if ((short)ax <= (short)0x00f4)
goto loc_11484;
memory(ds, si) = 0x00;
return;
loc_11484:
push(si);
ax = memory16(ds, si + 5);
push(ax);
ax = memory16(ds, si + 7);
push(ax);
sub_107fd();
pop(si);
al += 0x08;
memory(ds, si + 3) = al;
memory(ds, si + 20) = cl;
memory(ds, si + 4) = bl;
bl = memory(ds, si + 1);
bh = 0x00;
bx <<= 1;
bx = memory16(ds, bx + 4351);
sub_12121();
al = memory(ds, 0x1b9c);
if (al != 0x11)
goto loc_114b2;
return;
loc_114b2:
ax = memory16(ds, si + 5);
ax -= memory16(ds, 0x1b8f);
if ((short)ax >= 0)
goto loc_114bd;
ax = -ax;
loc_114bd:
if (ax >= 0x0010)
return;
ax = memory16(ds, si + 7);
ax -= memory16(ds, 0x1b91);
ax -= 0x0008;
if ((short)ax >= 0)
goto loc_114d0;
ax = -ax;
loc_114d0:
if (ax >= 0x0010)
return;
al = 0x05;
sub_13840();
memory16(ds, 0x9544) -= 0x0064;
memory(ds, 0x12a0) = 0x01;
sub_120f0();
memory(ds, 0x12a0) = 0x05;
memory(ds, si) = 0x00;
}
// extracting 1000:17f4, converted 28, to convert 115, failed 0
void sub_117f4()
{
sub_110c6();
al = memory(ds, si);
if (al != 0x00)
goto loc_117fe;
return;
loc_117fe:
al = memory(ds, si + 1);
if (al != 0x02)
goto loc_1180b;
memory16(ds, si + 7) += 0x0003;
goto loc_11835;
loc_1180b:
if (al != 0x00)
goto loc_11815;
memory16(ds, si + 5) -= 0x0004;
goto loc_11835;
loc_11815:
if (al != 0x01)
goto loc_11823;
memory16(ds, si + 5) -= 0x0004;
memory16(ds, si + 7) += 0x0003;
goto loc_11835;
loc_11823:
if (al != 0x03)
goto loc_11831;
memory16(ds, si + 5) += 0x0004;
memory16(ds, si + 7) += 0x0003;
goto loc_11835;
loc_11831:
memory16(ds, si + 5) += 0x0004;
loc_11835:
memory16(ds, si + 7) &= 0x03ff;
ax = memory16(ds, si + 5);
if ((short)ax >= (short)0x0008)
goto loc_11846;
memory(ds, si) = 0x00;
return;
loc_11846:
if ((short)ax <= (short)0x00f8)
goto loc_1184f;
memory(ds, si) = 0x00;
return;
loc_1184f:
memory(ds, si + 22)++;
bl = memory(ds, si + 22);
if (bl < 0x10)
goto loc_1185e;
sub_12099();
return;
loc_1185e:
bh = 0x00;
al = memory(ds, bx + 5223);
memory(ds, si + 3) += al;
al = memory(ds, 0x1b9c);
if (al != 0x11)
goto loc_1186f;
return;
loc_1186f:
ax = memory16(ds, si + 5);
ax -= memory16(ds, 0x1b8f);
if ((short)ax >= 0)
goto loc_1187a;
ax = -ax;
loc_1187a:
if (ax >= 0x000e)
return;
ax = memory16(ds, si + 7);
ax -= memory16(ds, 0x1b91);
if ((short)ax >= 0)
goto loc_1188a;
ax = -ax;
loc_1188a:
if (ax >= 0x000a)
return;
al = memory(ds, si + 3);
al -= memory(ds, 0x1b8d);
if ((char)al >= 0)
goto loc_1189a;
al = -al;
loc_1189a:
if (al >= 0x10)
return;
memory16(ds, 0x9544) -= 0x000a;
al = 0x05;
sub_13840();
}
// extracting 1000:171f, converted 29, to convert 117, failed 0
void sub_1171f()
{
memory(ds, si + 22)++;
al = memory(ds, si + 22);
al >>= 1;
al >>= 1;
al &= 0x07;
if ((char)al < (char)0x06)
goto loc_11733;
memory(ds, si) = 0x00;
return;
loc_11733:
memory(ds, si + 4) = al;
bx = 0x12f5;
sub_12121();
sub_110c6();
}
// extracting 1000:1b09, converted 30, to convert 118, failed 0
void sub_11b09()
{
sub_110c6();
al = memory(ds, si);
if (al != 0x00)
goto loc_11b13;
return;
loc_11b13:
al = memory(ds, 0x1b9c);
if (al != 0x11)
goto loc_11b1b;
return;
loc_11b1b:
ax = memory16(ds, si + 5);
ax -= memory16(ds, 0x1b8f);
if ((short)ax >= 0)
goto loc_11b26;
ax = -ax;
loc_11b26:
if (ax >= 0x0012)
return;
ax = memory16(ds, si + 7);
ax -= memory16(ds, 0x1b91);
if ((short)ax >= 0)
goto loc_11b36;
ax = -ax;
loc_11b36:
if (ax >= 0x0010)
return;
memory(ds, si) = 0x00;
al = memory(ds, si + 1);
sub_12b28();
al = 0x0a;
sub_13840();
}
// extracting 1000:1b4a, converted 31, to convert 120, failed 0
void sub_11b4a()
{
memory16(ds, si + 7) -= 0x0002;
memory16(ds, si + 7) &= 0x03ff;
sub_110a0();
}
// extracting 1000:2f50, converted 32, to convert 120, failed 0
void sub_12f50()
{
al = memory(ds, si);
if (al & 0x20)
goto loc_12f5e;
ah = memory(ds, 0x951a);
al = 0xf8;
goto loc_12f64;
loc_12f5e:
ah = memory(ds, 0x951b);
al = 0x08;
loc_12f64:
if (ah == 0x03)
goto loc_12f6e;
if (ah != 0x00)
goto loc_12f90;
loc_12f6e:
memory(ds, si) = 0x00;
si = 0x1ba1;
loc_12f74:
al = memory(ds, si);
if (al & 0x80)
goto loc_12f8f;
if (!(al & 0x01))
goto loc_12f8a;
al = memory(ds, si + 18);
if (al != 0x0f)
goto loc_12f8a;
push(si);
sub_13059();
pop(si);
loc_12f8a:
si += 0x0017;
goto loc_12f74;
loc_12f8f:
return;
loc_12f90:
al += memory(ds, 0x94e7);
ax &= 0x007f;
bx = ax;
al = memory(ds, bx + 5749);
cbw();
cx = ax;
sar(cx, 1);
ax += cx;
ax += 0x0080;
memory16(ds, si + 5) = ax;
al = memory(ds, bx + 5877);
cbw();
cx = ax;
sar(cx, 1);
ax += cx;
ax += 0x0080;
if (ax == 0x0000)
goto loc_12fd0;
bx = ax;
ax <<= 1;
ax <<= 1;
ax += bx;
ax <<= 1;
ax += 0x0005;
bl = 0x0c;
div(bl);
ah = 0x00;
loc_12fd0:
bl = memory(ds, 0x1ba0);
bx &= 0x007f;
memory16(ds, si + 7) = ax;
al = memory(ds, bx + 6290);
memory(ds, si + 4) = al;
bx = 0x1811;
sub_12121();
}
// extracting 1000:12a7, converted 33, to convert 121, failed 0
void sub_112a7()
{
ax = memory16(ds, 0x952a);
ax -= 0x0003;
if ((short)ax < 0)
goto loc_112b4;
memory16(ds, 0x952a) = ax;
goto loc_112b7;
loc_112b4:
sub_11c33();
loc_112b7:
sub_11bb9();
sub_11b57();
si = 0x1b8a;
bx = 0x0d49;
memory(ds, si + 4) = 0x0a;
sub_12121();
}
// extracting 1000:0600, converted 34, to convert 124, failed 0
void sub_10600()
{
dx = 0x01e2;
ax = memory16(ds, 0x94e8);
sub_10637();
dx = 0x01ea;
ax = memory16(ds, 0x94ea);
sub_10637();
dx = 0x01f2;
ax = memory16(ds, 0x94ec);
sub_10637();
dx = 0x01f9;
ax = memory16(ds, 0x94ee);
sub_10637();
dx = 0x0203;
ax = memory16(ds, 0x94f0);
sub_10637();
dx = 0x020b;
ax = memory16(ds, 0x94f2);
sub_10637();
}
// extracting 1000:333c, converted 35, to convert 129, failed 0
void sub_1333c()
{
ax = 0x000d;
interrupt(0x10);
ax = 0xa000;
memory16(ds, 0x94fa) = ax;
ax += 0x0200;
memory16(ds, 0x94f8) = ax;
ax = 0x0000;
sub_133b3();
ax = memory16(ds, 0x94f8);
bx = memory16(ds, 0x94fa);
memory16(ds, 0x94f8) = bx;
memory16(ds, 0x94fa) = ax;
sub_133d7();
bx = memory16(ds, 0x94fa);
bx <<= 1;
bx <<= 1;
bx <<= 1;
bx <<= 1;
flags.interrupts = false;
dx = 0x03d4;
ah = bh;
al = 0x0c;
out(dx, ax);
ah = bl;
al++;
out(dx, ax);
flags.interrupts = true;
sub_133d7();
}
// extracting 1000:2762, converted 36, to convert 131, failed 0
void sub_12762()
{
cx = 0x0012;
ax = ds;
es = ax;
di = 0x94af;
flags.direction = false;
ax = 0x0000;
rep_stosw<MemAuto, DirAuto>();
cx = 0x002a;
di = 0x9455;
al = 0x2e;
ah = 0x2e;
rep_stosw<MemAuto, DirAuto>();
memory(ds, 0x9455) = 0x5f;
al = 0x00;
cx = 0x0007;
si = 0x94da;
loc_1278b:
memory(ds, si) = al;
al++;
si++;
if (--cx)
goto loc_1278b;
di = 0x9455;
dx = 0x1506;
cx = 0x008c;
sub_10644();
}
// extracting 1000:05ec, converted 37, to convert 131, failed 0
void sub_105ec()
{
push(ds);
dx = 0x05fc;
ax = cs;
ds = ax;
al = 0x24;
ah = 0x25;
interrupt(0x21);
pop(ds);
}
// extracting 1000:0442, converted 38, to convert 130, failed 0
void sub_10442()
{
memory16(ds, 0x8f0b) = 0x0000;
memory16(ds, 0x8f0d) = 0x004b;
memory16(ds, 0x8f0f) = 0x004d;
memory16(ds, 0x8f11) = 0x0048;
memory16(ds, 0x8f13) = 0x0050;
memory16(ds, 0x8f15) = 0x0039;
memory16(ds, 0x8f17) = 0x0031;
memory16(ds, 0x8f19) = 0x0032;
memory16(ds, 0x8f1b) = 0x0010;
ax = ds;
es = ax;
ax = 0x0000;
cx = 0x0040;
di = 0x8e8a;
rep_stosw<MemAuto, DirAuto>();
al = 0x09;
ah = 0x35;
interrupt(0x21);
memory16(ds, 0x8e84) = bx;
memory16(ds, 0x8e82) = es;
push(ds);
dx = 0x04b7;
ax = cs;
ds = ax;
al = 0x09;
ah = 0x25;
interrupt(0x21);
pop(ds);
}
// extracting 1000:0588, converted 39, to convert 129, failed 0
void sub_10588()
{
ax = 0x0000;
interrupt(0x33);
memory(ds, 0x8f0a) = al;
}
// extracting 1000:0591, converted 40, to convert 128, failed 0
void sub_10591()
{
al = 0x1c;
ah = 0x35;
interrupt(0x21);
memory16(ds, 0x8e88) = bx;
memory16(ds, 0x8e86) = es;
push(ds);
dx = 0x05ce;
ax = cs;
ds = ax;
al = 0x1c;
ah = 0x25;
interrupt(0x21);
pop(ds);
al = 0x36;
out(0x0043, al);
ax = 0x4d0e;
out(0x0040, al);
al = ah;
out(0x0040, al);
}
// extracting 1000:382a, converted 41, to convert 127, failed 0
void sub_1382a()
{
al = 0x00;
memory(ds, 0x9550) = al;
memory(ds, 0x9551) = al;
memory(ds, 0x9552) = al;
memory(ds, 0x9506) = 0x01;
memory(ds, 0x9505) = 0x00;
}
// extracting 1000:00a9, converted 42, to convert 126, failed 0
void sub_100a9()
{
sub_10103();
memory(ds, 0x9500) = 0x00;
memory(ds, 0x94fe) = 0x01;
memory(ds, 0x94fc) = 0x10;
memory(ds, 0x94ff) = 0x00;
memory(ds, 0x9502) = 0x00;
sub_10da7();
sub_13423();
sub_121dc();
}
// extracting 1000:00cf, converted 43, to convert 129, failed 0
void sub_100cf()
{
loc_100cf:
sub_101c0();
sub_10fda();
al = memory(ds, 0x94ff);
if (al != 0x00)
goto loc_100e4;
sub_132fe();
sub_10b8e();
goto loc_100ed;
loc_100e4:
sub_134a8();
sub_131a4();
sub_10b8e();
loc_100ed:
sub_1220d();
sub_13383();
al = memory(ds, 0x9500);
if (al != 0x00)
return;
goto loc_100cf;
}
// extracting 1000:00fd, converted 44, to convert 137, failed 0
void sub_100fd()
{
memory(ds, 0x0006) = 0x01;
}
// extracting 1000:1b80, converted 45, to convert 136, failed 0
void sub_11b80()
{
bx = memory16(ds, 0x952a);
ax = memory16(ds, 0x953a);
if ((short)ax > (short)0x0000)
goto loc_11b91;
ax = 0x0008;
goto loc_11b94;
loc_11b91:
ax = memory16(ds, 0x954c);
loc_11b94:
if (!(al & 0x04))
goto loc_11ba3;
bx++;
if ((short)bx <= (short)0x0040)
goto loc_11ba1;
bx = 0x0040;
loc_11ba1:
goto loc_11bb4;
loc_11ba3:
if (!(al & 0x08))
goto loc_11bb4;
bx -= 0x0002;
if ((short)bx >= (short)memory16(ds, 0x94fc))
goto loc_11bb4;
bx = memory16(ds, 0x94fc);
loc_11bb4:
memory16(ds, 0x952a) = bx;
}
// extracting 1000:1bb9, converted 46, to convert 135, failed 0
void sub_11bb9()
{
bx = memory16(ds, 0x952a);
bx += 0x000f;
bx >>= 1;
bx >>= 1;
bx >>= 1;
ax = bx;
ax--;
bx >>= 1;
ax += memory16(ds, 0x950f);
if (ax <= 0x008b)
goto loc_11bdd;
ax = 0x0000;
memory16(ds, 0x953c) = 0xffff;
loc_11bdd:
memory16(ds, 0x950f) = ax;
ax = memory16(ds, 0x9528);
ax -= bx;
ax &= 0x03ff;
memory16(ds, 0x9528) = ax;
ax = memory16(ds, 0x9528);
ax >>= 1;
ax >>= 1;
ax >>= 1;
ax >>= 1;
ax -= 0x0003;
ax &= 0x003f;
if (ax == memory16(ds, 0x9507))
return;
memory16(ds, 0x9507) = ax;
push(ax);
sub_108ba();
}
// extracting 1000:1b57, converted 47, to convert 135, failed 0
void sub_11b57()
{
ax = memory16(ds, 0x1b8f);
push(ax);
ax = memory16(ds, 0x9528);
ax += 0x0070;
ax &= 0x03ff;
memory16(ds, 0x1b91) = ax;
push(ax);
sub_107fd();
memory(ds, 0x1b8d) = al;
memory(ds, 0x1b9e) = cl;
memory(ds, 0x1b8e) = bl;
si = 0x1b8a;
bx = 0x0d49;
sub_12121();
}
// extracting 1000:1c78, converted 48, to convert 136, failed 0
void sub_11c78()
{
ax = memory16(ds, 0x9437);
memory16(ds, 0x9439) = ax;
ax = memory16(ds, 0x9435);
memory16(ds, 0x9437) = ax;
ax = memory16(ds, 0x9433);
memory16(ds, 0x9435) = ax;
ax = memory16(ds, 0x1b8f);
memory16(ds, 0x9433) = ax;
ax = memory16(ds, 0x943f);
memory16(ds, 0x9441) = ax;
ax = memory16(ds, 0x943d);
memory16(ds, 0x943f) = ax;
ax = memory16(ds, 0x943b);
memory16(ds, 0x943d) = ax;
ax = memory16(ds, 0x1b91);
memory16(ds, 0x943b) = ax;
al = memory(ds, 0x9445);
memory(ds, 0x9446) = al;
al = memory(ds, 0x9444);
memory(ds, 0x9445) = al;
al = memory(ds, 0x9443);
memory(ds, 0x9444) = al;
al = memory(ds, 0x1b8e);
memory(ds, 0x9443) = al;
al = memory(ds, 0x9449);
memory(ds, 0x944a) = al;
al = memory(ds, 0x9448);
memory(ds, 0x9449) = al;
al = memory(ds, 0x9447);
memory(ds, 0x9448) = al;
al = memory(ds, 0x1b8d);
memory(ds, 0x9447) = al;
}
// extracting 1000:0a51, converted 49, to convert 135, failed 0
void sub_10a51()
{
bl = memory(ds, 0x1b9e);
bh = 0x00;
bx <<= 1;
si = bx;
al = memory(ds, 0x9502);
if (al != 0x01)
goto loc_10a68;
si += 0x0080;
goto loc_10a70;
loc_10a68:
if (al != 0x02)
goto loc_10a70;
si += 0x0100;
loc_10a70:
ax = memory16(ds, si + 37545);
ax &= memory16(ds, bx + 37417);
if (ax == 0x0000)
goto loc_10ad1;
bl = ah;
bl >>= 1;
bl >>= 1;
bh = 0x00;
cl = memory(ds, bx + 693);
if (cl == 0x00)
goto loc_10ad1;
memory(ds, 0x9429) = cl;
memory16(ds, 0x942c) = 0x000a;
bx <<= 1;
dx = memory16(ds, bx + 714);
bx = memory16(ds, bx + 756);
cx = 0x000a;
loc_10aa5:
flags.carry = ax & 1;
ax >>= 1;
if (!flags.carry)
goto loc_10ac8;
push(bx);
bx -= dx;
if ((short)bx > (short)memory16(ds, 0x1b8f))
goto loc_10ac7;
bx += dx;
bx += dx;
if ((short)bx < (short)memory16(ds, 0x1b8f))
goto loc_10ac7;
pop(ax);
al = memory(ds, 0x9429);
ah = 0x00;
bx = memory16(ds, 0x942c);
return;
loc_10ac7:
pop(bx);
loc_10ac8:
bx -= 0x0018;
memory16(ds, 0x942c)--;
if (--cx)
goto loc_10aa5;
loc_10ad1:
ax = 0x0000;
}
// extracting 1000:1c56, converted 50, to convert 134, failed 0
void sub_11c56()
{
ax = -ax;
memory16(ds, 0x9544) = ax;
push(ax);
al = 0x06;
sub_13840();
pop(ax);
ax = bx;
push(ax);
al = memory(ds, 0x1b9e);
ah = 0x00;
push(ax);
sub_11c0a();
al = memory(ds, si);
if (al & 0x80)
return;
sub_120db();
}
// extracting 1000:1c33, converted 51, to convert 134, failed 0
void sub_11c33()
{
al = memory(ds, 0x1b9c);
if (al != 0x11)
goto loc_11c3b;
return;
loc_11c3b:
al = 0x0c;
sub_13840();
si = 0x1b8a;
sub_120f0();
memory(ds, 0x1b9c) = 0x11;
memory(ds, 0x1b8c) = 0x00;
memory(ds, 0x9514) = 0x00;
}
// extracting 1000:1d1e, converted 52, to convert 134, failed 0
void sub_11d1e()
{
si = 0x135e;
memory(ds, si) &= 0xdf;
bl = memory(ds, 0x1b8e);
bh = 0x00;
al = memory(ds, bx + 5021);
memory(ds, si + 4) = al;
al = memory(ds, bx + 4981);
cbw();
ax += memory16(ds, 0x1b8f);
memory16(ds, si + 5) = ax;
ax = memory16(ds, 0x1b91);
ax -= 0x0004;
ax &= 0x03ff;
memory16(ds, si + 7) = ax;
al = memory(ds, 0x1b8d);
al += memory(ds, bx + 5001);
memory(ds, si + 3) = al;
bl = memory(ds, si + 4);
bh = 0x00;
al = memory(ds, bx + 5031);
memory(ds, si + 10) = al;
bx <<= 1;
ax = memory16(ds, bx + 5034);
memory16(ds, si + 15) = ax;
sub_10b58();
si = 0x0ff7;
ax = memory16(ds, 0x1363);
memory16(ds, si + 5) = ax;
ax = memory16(ds, 0x1365);
memory16(ds, si + 7) = ax;
al = memory(ds, 0x1361);
memory(ds, si + 3) = al;
memory(ds, 0x9516)++;
bl = memory(ds, 0x9516);
bx &= 0x000f;
al = memory(ds, bx + 4071);
memory(ds, si + 4) = al;
bx = 0x100e;
sub_12121();
sub_10b58();
si = 0x135e;
memory(ds, si) |= 0x20;
bl = memory(ds, 0x1b8e);
bh = 0x00;
al = memory(ds, bx + 4991);
cbw();
ax += memory16(ds, 0x1b8f);
memory16(ds, si + 5) = ax;
al = memory(ds, 0x1b8d);
al += memory(ds, bx + 5011);
memory(ds, si + 3) = al;
sub_10b58();
si = 0x0ff7;
ax = memory16(ds, 0x1363);
memory16(ds, si + 5) = ax;
ax = memory16(ds, 0x1365);
memory16(ds, si + 7) = ax;
al = memory(ds, 0x1361);
memory(ds, si + 3) = al;
sub_10b58();
ax = memory16(ds, 0x9511);
ax += bx;
if (ax <= 0x0010)
goto loc_11deb;
ax = 0x0000;
memory16(ds, 0x9540) = 0xffff;
loc_11deb:
memory16(ds, 0x9511) = ax;
}
// extracting 1000:1cd9, converted 53, to convert 138, failed 0
void sub_11cd9()
{
ax = memory16(ds, 0x9439);
memory16(ds, si + 5) = ax;
ax = memory16(ds, 0x9441);
ax += 0x0006;
ax &= 0x03ff;
memory16(ds, si + 7) = ax;
al = memory(ds, 0x9446);
memory(ds, si + 4) = al;
bl = al;
bh = 0x00;
cl = memory(ds, bx + 3513);
al = memory(ds, 0x944a);
al += 0x06;
memory(ds, si + 3) = al;
al = memory(ds, si);
if (al & 0x20)
goto loc_11d10;
memory16(ds, si + 5) -= 0x0008;
memory(ds, si + 3) += cl;
goto loc_11d17;
loc_11d10:
memory16(ds, si + 5) += 0x0008;
memory(ds, si + 3) -= cl;
loc_11d17:
bx = 0x0dda;
sub_12121();
}
// extracting 1000:0b58, converted 54, to convert 138, failed 0
void sub_10b58()
{
ax = 0x13a5;
es = ax;
di = 0x1b8a;
loc_10b60:
al = memory(ds, di);
if (al & 0x80)
goto loc_10b78;
if (al & 0x01)
goto loc_10b73;
push(di);
cx = 0x0017;
flags.direction = false;
rep_movsb<MemAuto, MemAuto, DirAuto>();
pop(si);
return;
loc_10b73:
di += 0x0017;
goto loc_10b60;
loc_10b78:
si = 0x0000;
}
// extracting 1000:3840, converted 55, to convert 137, failed 0
void sub_13840()
{
ah = memory(ds, 0x955e);
if (ah == 0x00)
goto loc_1384a;
return;
loc_1384a:
ah = memory(ds, 0x9506);
if (ah != 0x00)
goto loc_13854;
return;
loc_13854:
ah = memory(ds, 0x9550);
if (ah != 0x00)
goto loc_13866;
push(bx);
memory(ds, 0x9550) = al;
sub_13914();
pop(bx);
return;
loc_13866:
ah = memory(ds, 0x9551);
if (ah != 0x00)
goto loc_13873;
memory(ds, 0x9551) = al;
return;
loc_13873:
if (al <= memory(ds, 0x9552))
return;
memory(ds, 0x9552) = al;
}
// extracting 1000:2121, converted 56, to convert 132, failed 0
void sub_12121()
{
cl = memory(ds, bx);
ch = 0x00;
bx++;
al = memory(ds, si + 4);
ah = 0x00;
di = ax;
al = memory(ds, bx + di);
memory(ds, si + 9) = al;
bx += cx;
al = memory(ds, bx + di);
memory(ds, si + 10) = al;
bx += cx;
al = memory(ds, bx + di);
memory(ds, si + 11) = al;
bx += cx;
al = memory(ds, bx + di);
memory(ds, si + 12) = al;
bx += cx;
di <<= 1;
di <<= 1;
ax = memory16(ds, bx + di);
memory16(ds, si + 13) = ax;
bx += 0x0002;
ax = memory16(ds, bx + di);
memory16(ds, si + 15) = ax;
}
// extracting 1000:215b, converted 57, to convert 128, failed 0
void sub_1215b()
{
cx = 0x0001;
ax = memory16(ds, 0x1b91);
ax -= memory16(ds, si + 7);
if ((short)ax <= (short)0x008c)
goto loc_12171;
memory(ds, si + 4) = 0x02;
cx = 0x0000;
return;
loc_12171:
if ((short)ax >= (short)0xfff0)
goto loc_121a0;
ah = memory(ds, si + 4);
al = memory(ds, si);
if (!(al & 0x20))
goto loc_1218d;
ah++;
if ((char)ah <= (char)0x04)
goto loc_1218b;
memory(ds, si) &= 0xdf;
ah = 0x04;
loc_1218b:
goto loc_12199;
loc_1218d:
ah--;
if ((char)ah >= (char)0x00)
goto loc_12199;
memory(ds, si) |= 0x20;
ah = 0x00;
loc_12199:
memory(ds, si + 4) = ah;
cx = 0x0000;
return;
loc_121a0:
bx = memory16(ds, 0x1b8f);
bx -= memory16(ds, si + 5);
if ((short)bx >= 0)
goto loc_121c2;
if ((short)bx <= (short)0xffe0)
goto loc_121b3;
memory(ds, si + 4) = 0x02;
return;
loc_121b3:
if ((short)ax <= (short)0x0020)
goto loc_121bd;
memory(ds, si + 4) = 0x01;
return;
loc_121bd:
memory(ds, si + 4) = 0x00;
return;
loc_121c2:
if ((short)bx >= (short)0x0020)
goto loc_121cc;
memory(ds, si + 4) = 0x02;
return;
loc_121cc:
if ((short)ax <= (short)0x0020)
goto loc_121d6;
memory(ds, si + 4) = 0x03;
return;
loc_121d6:
memory(ds, si + 4) = 0x04;
}
// extracting 1000:1f0b, converted 58, to convert 127, failed 0
void sub_11f0b()
{
push(si);
memory(ds, 0x9516)++;
bl = memory(ds, 0x9516);
bx &= 0x000f;
al = memory(ds, bx + 4071);
memory(ds, 0x0ffb) = al;
di = 0x0ff7;
bl = memory(ds, si + 4);
bh = 0x00;
al = memory(ds, bx + 5129);
cbw();
ax += memory16(ds, si + 5);
memory16(ds, di + 5) = ax;
al = memory(ds, bx + 5134);
cbw();
ax += memory16(ds, si + 7);
ax &= 0x03ff;
memory16(ds, di + 7) = ax;
al = memory(ds, si + 3);
al += 0x04;
memory(ds, di + 3) = al;
bx <<= 1;
bx = memory16(ds, bx + 4143);
si = di;
sub_12121();
sub_10b58();
if (si == 0x0000)
goto loc_11f63;
pop(ax);
push(ax);
if (ax <= si)
goto loc_11f63;
sub_116d6();
loc_11f63:
pop(si);
al = memory(ds, 0x9518);
if (al != 0x00)
goto loc_11f6c;
return;
loc_11f6c:
push(si);
di = 0x13b0;
bl = memory(ds, si + 4);
bh = 0x00;
memory(ds, di + 1) = bl;
ax = memory16(ds, 0x0ffc);
memory16(ds, di + 5) = ax;
ax = memory16(ds, 0x0ffe);
memory16(ds, di + 7) = ax;
al = memory(ds, 0x0ffa);
memory(ds, di + 3) = al;
al = memory(ds, bx + 5139);
memory(ds, di + 9) = al;
al = memory(ds, bx + 5144);
memory(ds, di + 10) = al;
memory(ds, di + 4) = 0x00;
bx <<= 1;
ax = memory16(ds, bx + 5149);
memory16(ds, di + 15) = ax;
si = di;
sub_10b58();
if (si == 0x0000)
goto loc_11fb8;
pop(ax);
push(ax);
if (ax <= si)
goto loc_11fb8;
sub_115fc();
loc_11fb8:
pop(si);
}
// extracting 1000:2005, converted 59, to convert 128, failed 0
void sub_12005()
{
push(si);
di = 0x1446;
bl = memory(ds, si + 4);
memory(ds, di + 1) = bl;
bh = 0x00;
al = memory(ds, bx + 5213);
cbw();
ax += memory16(ds, si + 5);
memory16(ds, di + 5) = ax;
al = memory(ds, bx + 5218);
cbw();
ax += memory16(ds, si + 7);
ax &= 0x03ff;
memory16(ds, di + 7) = ax;
al = memory(ds, si + 3);
al += 0x08;
memory(ds, di + 3) = al;
si = di;
sub_10b58();
if (si == 0x0000)
goto loc_12045;
pop(ax);
push(ax);
if (ax <= si)
goto loc_12045;
sub_117f4();
loc_12045:
pop(si);
}
// extracting 1000:1fba, converted 60, to convert 126, failed 0
void sub_11fba()
{
push(si);
di = 0x10e8;
bl = memory(ds, si + 4);
memory(ds, di + 1) = bl;
bh = 0x00;
al = memory(ds, bx + 4318);
cbw();
ax += memory16(ds, si + 5);
memory16(ds, di + 5) = ax;
al = memory(ds, bx + 4323);
cbw();
ax += memory16(ds, si + 7);
ax &= 0x03ff;
memory16(ds, di + 7) = ax;
al = memory(ds, si + 3);
al += 0x08;
memory(ds, di + 3) = al;
bx <<= 1;
bx = memory16(ds, bx + 4351);
si = di;
sub_12121();
sub_10b58();
if (si == 0x0000)
goto loc_12003;
pop(ax);
push(ax);
if (ax <= si)
goto loc_12003;
sub_11429();
loc_12003:
pop(si);
}
// extracting 1000:1a04, converted 61, to convert 124, failed 0
void sub_11a04()
{
ax = memory16(ds, 0x1b8f);
ax -= memory16(ds, si + 5);
ax -= 0x000c;
if ((short)ax >= 0)
goto loc_11a11;
ax = -ax;
loc_11a11:
cx = memory16(ds, 0x1b91);
cx -= memory16(ds, si + 7);
if ((short)cx >= 0)
goto loc_11a1c;
cx = -cx;
loc_11a1c:
bl = memory(ds, si + 4);
bl >>= 1;
ax += cx;
if (ax > 0x0040)
goto loc_11a32;
if (bl == 0x06)
goto loc_11a30;
memory(ds, si + 4)++;
loc_11a30:
goto loc_11a3a;
loc_11a32:
if (bl == 0x00)
goto loc_11a3a;
memory(ds, si + 4)--;
loc_11a3a:
if (bl != 0x06)
goto loc_11a45;
memory(ds, si + 2) = 0x00;
goto loc_11a56;
loc_11a45:
push(bx);
memory(ds, si + 2) = 0x07;
bh = 0x00;
bx <<= 1;
ax = memory16(ds, bx + 5239);
memory16(ds, si + 15) = ax;
pop(bx);
loc_11a56:
if (bl < 0x01)
goto loc_11a9a;
ax = memory16(ds, 0x1b8f);
ax -= memory16(ds, si + 5);
ax -= 0x000c;
if ((short)ax >= 0)
goto loc_11a73;
ax = -ax;
if (ax > 0x0018)
goto loc_11a71;
memory16(ds, 0x1b8f)++;
loc_11a71:
goto loc_11a7e;
loc_11a73:
if (ax == 0)
goto loc_11a7e;
if (ax > 0x0018)
goto loc_11a7e;
memory16(ds, 0x1b8f)--;
loc_11a7e:
if (cx > 0x0008)
goto loc_11a9a;
if (ax > 0x0008)
goto loc_11a9a;
al = memory(ds, 0x1b9c);
if (al == 0x11)
goto loc_11a9a;
ax = memory16(ds, 0x1b8f);
memory16(ds, 0x950a) = ax;
memory(ds, 0x94ff) = 0x01;
loc_11a9a:
sub_110c6();
}
// extracting 1000:309d, converted 62, to convert 122, failed 0
void sub_1309d()
{
bx = memory16(ds, 0x952a);
bx += 0x0007;
bx >>= 1;
bx >>= 1;
bx >>= 1;
bx += 0x0002;
memory16(ds, 0x9547) += bx;
ax = memory16(ds, 0x950f);
ax += bx;
if (ax <= 0x02e8)
goto loc_130c4;
ax = 0x0000;
memory16(ds, 0x953c) = 0xffff;
loc_130c4:
memory16(ds, 0x950f) = ax;
ax = memory16(ds, 0x9547);
ax -= 0x0380;
if ((short)ax >= 0)
goto loc_13124;
ax = -ax;
if (ax >= 0x0100)
goto loc_130ed;
memory16(ds, 0x9525) = ax;
al = memory(ds, 0x9524);
if (al != 0x00)
goto loc_130eb;
si = 0x1912;
sub_10b58();
memory(ds, 0x9524) = 0x01;
loc_130eb:
goto loc_13122;
loc_130ed:
ax = memory16(ds, 0x9547);
ax >>= 1;
ax >>= 1;
ax >>= 1;
ax >>= 1;
ax >>= 1;
ax >>= 1;
if (al == memory(ds, 0x9527))
goto loc_13122;
memory(ds, 0x9527) = al;
bl = al;
bh = 0x00;
bx += memory16(ds, 0x94e2);
al = memory(ds, bx);
if (al == 0x00)
goto loc_13122;
si = 0x1ab2;
memory(ds, si + 1) = al;
ax = memory16(ds, 0x9547);
memory16(ds, si + 19) = ax;
sub_10b58();
loc_13122:
return;
loc_13124:
memory(ds, 0x94ff) = 0x00;
ax = memory16(ds, 0x950c);
memory16(ds, 0x9528) = ax;
}
// extracting 1000:3084, converted 63, to convert 123, failed 0
void sub_13084()
{
al -= 0x05;
if ((char)al >= 0)
goto loc_1308d;
ax = 0x0000;
return;
loc_1308d:
if (al <= 0x38)
goto loc_13093;
al = 0x38;
loc_13093:
al >>= 1;
ah = 0x00;
ax = -ax;
ax -= 0x0003;
}
// extracting 1000:3130, converted 64, to convert 117, failed 0
void sub_13130()
{
bl = al;
bh = 0x00;
cl = memory(ds, bx + 6762);
ch = 0x00;
al = memory(ds, si + 1);
if (al == 0x01)
goto loc_1315e;
if (al == 0x02)
goto loc_13167;
if (al == 0x03)
goto loc_13170;
if (al == 0x04)
goto loc_13178;
if (al == 0x05)
goto loc_13181;
if (al == 0x06)
goto loc_13188;
if (al == 0x07)
goto loc_13191;
if (al == 0x08)
goto loc_1319b;
return;
loc_1315e:
cx = -cx;
cx += 0x006a;
memory16(ds, si + 7) = cx;
return;
loc_13167:
push(cx);
sub_1315e();
pop(cx);
sub_13170();
return;
loc_13170:
cx += 0x0080;
memory16(ds, si + 5) = cx;
return;
loc_13178:
push(cx);
sub_13170();
pop(cx);
sub_13181();
return;
loc_13181:
cx += 0x006a;
memory16(ds, si + 7) = cx;
return;
loc_13188:
push(cx);
sub_13181();
pop(cx);
sub_13191();
return;
loc_13191:
cx = -cx;
cx += 0x0080;
memory16(ds, si + 5) = cx;
return;
loc_1319b:
push(cx);
sub_13191();
pop(cx);
sub_1315e();
}
// extracting 1000:3059, converted 65, to convert 122, failed 0
void sub_13059()
{
memory(ds, si) = 0x00;
al = memory(ds, 0x951d);
if (al != 0x40)
goto loc_1306a;
memory16(ds, 0x9540) += 0x0006;
return;
loc_1306a:
if (al != 0x80)
goto loc_13075;
memory16(ds, 0x953c) += 0x0004;
return;
loc_13075:
if (al != 0xc0)
goto loc_13080;
memory16(ds, 0x9544) += 0x0008;
return;
loc_13080:
sub_1268a();
}
// extracting 1000:10a0, converted 66, to convert 118, failed 0
void sub_110a0()
{
al = memory(ds, si + 10);
al -= memory(ds, si + 3);
al -= memory(ds, si + 12);
cbw();
ax += memory16(ds, si + 7);
ax &= 0x03ff;
bx = memory16(ds, 0x9528);
if (ax >= bx)
goto loc_110bb;
ax += 0x0400;
loc_110bb:
ax -= bx;
if (ax <= 0x0200)
return;
memory(ds, si) = 0x00;
}
// extracting 1000:07fd, converted 67, to convert 117, failed 0
void sub_107fd()
{
push(bp);
bp = sp;
sp -= 0x0008;
ax = memory16(ss, bp + 6);
ax += 0x0010;
cl = 0x18;
div(cl);
push(ax);
ah = 0x00;
memory16(ss, bp - 2) = ax;
pop(ax);
al = ah;
ah = 0x00;
cl = 0x03;
div(cl);
ah = 0x00;
memory16(ss, bp - 4) = ax;
ax = memory16(ss, bp + 4);
ax &= 0x03ff;
ax >>= 1;
ax >>= 1;
ax >>= 1;
ax >>= 1;
ax = -ax;
ax += 0x003f;
memory16(ss, bp - 6) = ax;
ax = memory16(ss, bp + 4);
ax &= 0x000f;
ax >>= 1;
memory16(ss, bp - 8) = ax;
ax = memory16(ss, bp - 6);
ax <<= 1;
ax <<= 1;
bx = ax;
ax <<= 1;
bx += ax;
bx += 0x8f29;
si = bx;
bx += memory16(ss, bp - 2);
al = memory(ds, bx);
ah = 0x00;
push(ax);
ax <<= 1;
bx = ax;
bx = memory16(ds, bx + 1603);
ax = memory16(ss, bp - 8);
ax <<= 1;
ax <<= 1;
ax <<= 1;
bx += ax;
bx += memory16(ss, bp - 4);
cl = memory(ds, bx);
push(cx);
cl &= 0x1f;
if (!(cl & 0x10))
goto loc_10881;
cl |= 0xe0;
loc_10881:
dx = memory16(ss, bp - 2);
flags.direction = false;
loc_10885:
if (dx == 0x0000)
goto loc_10896;
lodsb<MemAuto, DirAuto>();
bh = 0x00;
bl = al;
cl += memory(ds, bx + 1393);
dx--;
goto loc_10885;
loc_10896:
al = cl;
cbw();
pop(cx);
pop(bx);
if (cl & 0x80)
goto loc_108a6;
bl = memory(ds, bx + 1435);
goto loc_108aa;
loc_108a6:
bl = memory(ds, bx + 1477);
loc_108aa:
bh = 0x00;
cx = memory16(ss, bp - 6);
cx = -cx;
cx += 0x003f;
sp = bp;
pop(bp);
sp += 4;
}
// extracting 1000:2092, converted 68, to convert 116, failed 0
void sub_12092()
{
di = 0x1427;
sub_120a0();
}
// extracting 1000:0ad5, converted 69, to convert 116, failed 0
void sub_10ad5()
{
push(bp);
bp = sp;
bx = memory16(ss, bp + 4);
bx <<= 1;
si = bx;
al = memory(ds, 0x9502);
if (al != 0x01)
goto loc_10aec;
si += 0x0080;
goto loc_10af4;
loc_10aec:
if (al != 0x02)
goto loc_10af4;
si += 0x0100;
loc_10af4:
ax = memory16(ds, si + 37545);
ax &= memory16(ds, bx + 37417);
if (ax == 0x0000)
goto loc_10b51;
bl = ah;
bl >>= 1;
bl >>= 1;
bh = 0x00;
cl = memory(ds, bx + 693);
if (cl == 0x00)
goto loc_10b51;
memory16(ds, 0x942c) = 0x000a;
bx <<= 1;
dx = memory16(ds, bx + 714);
dx -= 0x000e;
bx = memory16(ds, bx + 756);
cx = 0x000a;
loc_10b28:
flags.carry = ax & 1;
ax >>= 1;
if (!flags.carry)
goto loc_10b48;
push(bx);
bx -= dx;
if ((short)bx > (short)memory16(ss, bp + 6))
goto loc_10b47;
bx += dx;
bx += dx;
if ((short)bx < (short)memory16(ss, bp + 6))
goto loc_10b47;
pop(ax);
ax = 0x0001;
bx = memory16(ds, 0x942c);
goto loc_10b54;
loc_10b47:
pop(bx);
loc_10b48:
bx -= 0x0018;
memory16(ds, 0x942c)--;
if (--cx)
goto loc_10b28;
loc_10b51:
ax = 0x0000;
loc_10b54:
pop(bp);
sp += 4;
}
// extracting 1000:1c0a, converted 70, to convert 115, failed 0
void sub_11c0a()
{
push(bp);
bp = sp;
bx = memory16(ss, bp + 6);
cx = memory16(ss, bp + 4);
si = 0x1b8a;
loc_11c16:
al = memory(ds, si);
if (al & 0x80)
goto loc_11c2f;
if (!(al & 0x08))
goto loc_11c2a;
if (cl != memory(ds, si + 20))
goto loc_11c2a;
if (bl == memory(ds, si + 19))
goto loc_11c2f;
loc_11c2a:
si += 0x0017;
goto loc_11c16;
loc_11c2f:
pop(bp);
sp += 4;
}
// extracting 1000:20db, converted 71, to convert 114, failed 0
void sub_120db()
{
sub_12676();
sub_120f0();
push(si);
al = memory(ds, si + 19);
ah = 0x00;
push(ax);
al = memory(ds, si + 20);
push(ax);
sub_109b5();
}
// extracting 1000:2662, converted 72, to convert 115, failed 0
void sub_12662()
{
ax = 0x0000;
push(ax);
ax = 0x0000;
push(ax);
ax = 0x0001;
push(ax);
ax = 0x0000;
push(ax);
sub_1269e();
}
// extracting 1000:2047, converted 73, to convert 115, failed 0
void sub_12047()
{
al = memory(ds, si);
bl = memory(ds, 0x9517);
if (!(al & 0x20))
goto loc_12072;
if (bl & 0x80)
goto loc_1206d;
memory(ds, 0x9517) |= 0x80;
memory(ds, 0x1326) |= 0x20;
di = 0x1326;
sub_120a0();
al = 0x03;
sub_13840();
goto loc_12070;
loc_1206d:
memory(ds, si) = 0x00;
loc_12070:
return;
loc_12072:
if (bl & 0x01)
goto loc_1208e;
memory(ds, 0x9517) |= 0x01;
memory(ds, 0x1326) &= 0xdf;
di = 0x1326;
sub_120a0();
al = 0x03;
sub_13840();
return;
loc_1208e:
memory(ds, si) = 0x00;
}
// extracting 1000:20f0, converted 74, to convert 107, failed 0
void sub_120f0()
{
push(si);
ax = memory16(ds, si + 5);
memory16(ds, 0x12a3) = ax;
ax = memory16(ds, si + 7);
memory16(ds, 0x12a5) = ax;
al = memory(ds, si + 3);
memory(ds, 0x12a1) = al;
al = memory(ds, si);
if (!(al & 0x10))
goto loc_12119;
memory16(ds, 0x12a3) -= 0x000c;
memory16(ds, 0x12a5) -= 0x0008;
memory16(ds, 0x12a5) &= 0x03ff;
loc_12119:
si = 0x129e;
sub_10b58();
pop(si);
}
// extracting 1000:2676, converted 75, to convert 99, failed 0
void sub_12676()
{
ax = 0x0000;
push(ax);
ax = 0x0001;
push(ax);
ax = 0x0005;
push(ax);
ax = 0x0000;
push(ax);
sub_1269e();
}
// extracting 1000:1def, converted 76, to convert 96, failed 0
void sub_11def()
{
memory(ds, 0x9516)++;
bl = memory(ds, 0x9516);
bx &= 0x000f;
al = memory(ds, bx + 4071);
memory(ds, 0x0ffb) = al;
al = memory(ds, si + 1);
if (al != 0x00)
goto loc_11e2e;
bl = memory(ds, si + 4);
bh = 0x00;
cl = memory(ds, bx + 5069);
ax = 0xfffd;
bx = 0x0008;
sub_11e7d();
bl = memory(ds, si + 4);
bh = 0x00;
cl = memory(ds, bx + 5079);
ax = 0x0003;
bx = 0x0008;
sub_11e7d();
return;
loc_11e2e:
if (al != 0x01)
goto loc_11e46;
bl = memory(ds, si + 4);
bh = 0x00;
cl = memory(ds, bx + 5089);
ax = 0x0000;
bx = 0x0008;
sub_11e7d();
return;
loc_11e46:
bl = memory(ds, si + 4);
bh = 0x00;
cl = memory(ds, bx + 5099);
ax = 0xfff9;
bx = 0x0008;
sub_11e7d();
bl = memory(ds, si + 4);
bh = 0x00;
cl = memory(ds, bx + 5109);
ax = 0x0000;
bx = 0x000b;
sub_11e7d();
bl = memory(ds, si + 4);
bh = 0x00;
cl = memory(ds, bx + 5119);
ax = 0x0007;
bx = 0x0008;
sub_11e7d();
}
// extracting 1000:196f, converted 77, to convert 98, failed 0
void sub_1196f()
{
al = memory(ds, 0x1b8e);
if (al != 0x00)
goto loc_11982;
memory(ds, 0x951d) = 0xf0;
memory(ds, 0x94ff) = 0x01;
return;
loc_11982:
push(si);
memory(ds, 0x1b8e) = 0x00;
si = 0x1b8a;
bx = 0x0d49;
sub_12121();
pop(si);
}
// extracting 1000:2099, converted 78, to convert 91, failed 0
void sub_12099()
{
di = 0x12de;
sub_120a0();
}
// extracting 1000:2b28, converted 79, to convert 87, failed 0
void sub_12b28()
{
push(ax);
ax = 0x0000;
push(ax);
ax = 0x0001;
push(ax);
ax = 0x0005;
push(ax);
ax = 0x0000;
push(ax);
sub_1269e();
pop(ax);
if (al == 0x00)
goto loc_12b59;
if (al == 0x01)
goto loc_12b76;
if (al == 0x02)
goto loc_12b93;
if (al == 0x03)
goto loc_12bb0;
if (al == 0x04)
goto loc_12bcd;
if (al != 0x05)
goto loc_12b58;
goto loc_12bea;
loc_12b58:
return;
loc_12b59:
memory(ds, 0x952e) = 0x01;
ax = 0x2f78;
push(ax);
ax = 0x1b82;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x0008;
push(ax);
ax = 0x0004;
push(ax);
sub_12cea();
return;
loc_12b76:
memory(ds, 0x952f) = 0x01;
ax = 0x2f78;
push(ax);
ax = 0x1cc2;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x0008;
push(ax);
ax = 0x0004;
push(ax);
sub_12cea();
return;
loc_12b93:
memory(ds, 0x9530) = 0x01;
ax = 0x2f78;
push(ax);
ax = 0x1e02;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x0008;
push(ax);
ax = 0x0004;
push(ax);
sub_12cea();
return;
loc_12bb0:
memory(ds, 0x9531) = 0x01;
ax = 0x2f78;
push(ax);
ax = 0x1b85;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x0008;
push(ax);
ax = 0x0004;
push(ax);
sub_12cea();
return;
loc_12bcd:
memory(ds, 0x9532) = 0x01;
ax = 0x2f78;
push(ax);
ax = 0x1cc5;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x0008;
push(ax);
ax = 0x0004;
push(ax);
sub_12cea();
return;
loc_12bea:
memory(ds, 0x9533) = 0x01;
ax = 0x2f78;
push(ax);
ax = 0x1e05;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x0008;
push(ax);
ax = 0x0004;
push(ax);
sub_12cea();
}
// extracting 1000:0637, converted 80, to convert 85, failed 0
void sub_10637()
{
memory16(ds, 0x8f20) = ax;
di = 0x0000;
cx = 0x7d00;
sub_1064d();
}
// extracting 1000:33b3, converted 81, to convert 80, failed 0
void sub_133b3()
{
push(ax);
ax = memory16(ds, 0x94f8);
es = ax;
di = 0x0000;
dx = 0x03ce;
pop(ax);
ah = al;
al = 0x00;
out(dx, ax);
ax = 0x0f01;
out(dx, ax);
flags.direction = false;
cx = 0x0fa0;
rep_stosw<MemVideo, DirAuto>();
ax = 0x0000;
out(dx, ax);
al++;
out(dx, ax);
}
// extracting 1000:33d7, converted 82, to convert 79, failed 0
void sub_133d7()
{
dx = 0x03da;
loc_133da:
in(al, dx);
al &= 0x08;
if (al == 0)
goto loc_133da;
loc_133df:
in(al, dx);
al &= 0x08;
if (al != 0)
goto loc_133df;
}
// extracting 1000:0644, converted 83, to convert 77, failed 0
void sub_10644()
{
ax = ds;
memory16(ds, 0x8f20) = ax;
sub_1064d();
}
// extracting 1000:0103, converted 84, to convert 77, failed 0
void sub_10103()
{
al = memory(ds, 0x0006);
if (al == 0x00)
goto loc_10115;
memory16(ds, 0x8e7e) = 0x00da;
sub_1279f();
goto loc_1011e;
loc_10115:
memory16(ds, 0x8e7e) = 0x00e9;
sub_128da();
loc_1011e:
sub_139b8();
sub_13472();
memory(ds, 0x9503) = 0x01;
memory16(ds, 0x8e80) = 0x0000;
sub_10d98();
loc_10132:
sub_101c0();
sub_10fda();
sub_13498();
sub_10b8e();
sub_13383();
ax = memory16(ds, 0x954c);
if (ax & 0x0080)
goto loc_10197;
memory16(ds, 0x8e80)++;
bx = memory16(ds, 0x8e80);
if (bx & 0x0007)
goto loc_10195;
bx >>= 1;
bx >>= 1;
bx >>= 1;
bx += memory16(ds, 0x8e7e);
al = memory(ds, bx);
if (al == 0x00)
goto loc_10195;
if (al == 0xff)
goto loc_10197;
if (al != 0xfe)
goto loc_10180;
al = memory(ds, 0x9546);
if (al == 0x00)
goto loc_1017b;
sub_129db();
goto loc_1017e;
loc_1017b:
sub_101ad();
loc_1017e:
goto loc_10195;
loc_10180:
if (al & 0x80)
goto loc_10189;
sub_1019d();
goto loc_10195;
loc_10189:
al &= 0x3f;
push(ax);
sub_1019d();
pop(ax);
al++;
sub_1019d();
loc_10195:
goto loc_10132;
loc_10197:
memory(ds, 0x9503) = 0x00;
}
// extracting 1000:0da7, converted 85, to convert 91, failed 0
void sub_10da7()
{
sub_109a4();
sub_1069a();
memory(ds, 0x9519) = 0x00;
memory(ds, 0x951a) = 0x00;
memory(ds, 0x951b) = 0x00;
sub_10e3d();
}
// extracting 1000:3423, converted 86, to convert 93, failed 0
void sub_13423()
{
ax = 0x0000;
sub_133b3();
sub_13439();
sub_13383();
ax = 0x0000;
sub_133b3();
sub_13439();
}
// extracting 1000:21dc, converted 87, to convert 97, failed 0
void sub_121dc()
{
ax = 0x403c;
push(ax);
ax = 0x1e11;
push(ax);
ax = 0x0038;
push(ax);
ax = 0x0007;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
sub_12200();
sub_1264a();
sub_12a7f();
sub_122b1();
}
// extracting 1000:01c0, converted 88, to convert 101, failed 0
void sub_101c0()
{
bx = 0x8e8a;
si = 0x003d;
al = memory(ds, bx + si);
if (al == 0x00)
goto loc_101d5;
si = 0x003e;
loc_101cf:
al = memory(ds, bx + si);
if (al == 0x00)
goto loc_101cf;
loc_101d5:
si = 0x003b;
al = memory(ds, bx + si);
if (al == 0x00)
goto loc_101e1;
sub_1033b();
loc_101e1:
bx = 0x8e8a;
si = memory16(ds, 0x8f0d);
al = memory(ds, bx + si);
if (al == 0x00)
goto loc_101f6;
memory16(ds, 0x954c) = 0x0001;
goto loc_1020e;
loc_101f6:
si = memory16(ds, 0x8f0f);
al = memory(ds, bx + si);
if (al == 0x00)
goto loc_10208;
memory16(ds, 0x954c) = 0x0002;
goto loc_1020e;
loc_10208:
memory16(ds, 0x954c) = 0x0000;
loc_1020e:
si = memory16(ds, 0x8f11);
al = memory(ds, bx + si);
if (al == 0x00)
goto loc_1021f;
memory16(ds, 0x954c) |= 0x0004;
goto loc_1022e;
loc_1021f:
si = memory16(ds, 0x8f13);
al = memory(ds, bx + si);
if (al == 0x00)
goto loc_1022e;
memory16(ds, 0x954c) |= 0x0008;
loc_1022e:
si = memory16(ds, 0x8f15);
al = memory(ds, bx + si);
if (al == 0x00)
goto loc_1023e;
memory16(ds, 0x954c) |= 0x0080;
loc_1023e:
si = memory16(ds, 0x8f17);
al = memory(ds, bx + si);
if (al == 0x00)
goto loc_1024d;
memory16(ds, 0x954c) |= 0x0040;
loc_1024d:
si = memory16(ds, 0x8f19);
al = memory(ds, bx + si);
if (al == 0x00)
goto loc_1025c;
memory16(ds, 0x954c) |= 0x0020;
loc_1025c:
si = memory16(ds, 0x8f1b);
al = memory(ds, bx + si);
if (al == 0x00)
goto loc_1028c;
sub_12c45();
bx = 0x8e8a;
loc_1026c:
al = memory(ds, bx + 21);
if (al != 0x00)
goto loc_1027c;
al = memory(ds, bx + 49);
if (al != 0x00)
goto loc_1027c;
goto loc_1026c;
loc_1027c:
bx = 0x8e8a;
al = memory(ds, bx + 21);
if (al == 0x00)
goto loc_10289;
stop(); // jmp loc_10096
loc_10289:
sub_10529();
loc_1028c:
bx = 0x8e8a;
si = 0x003c;
al = memory(ds, bx + si);
if (al == 0x00)
goto loc_102c5;
al = memory(ds, 0x9505);
if (al != 0x00)
goto loc_102b0;
al = 0x0e;
sub_13840();
memory(ds, 0x9505) = 0x01;
memory(ds, 0x9506) = 0x00;
goto loc_102c3;
loc_102b0:
if (al != 0x02)
goto loc_102c3;
memory(ds, 0x9505) = 0x03;
memory(ds, 0x9506) = 0x01;
al = 0x0d;
sub_13840();
loc_102c3:
goto loc_102dc;
loc_102c5:
al = memory(ds, 0x9505);
if (al != 0x01)
goto loc_102d3;
memory(ds, 0x9505) = 0x02;
goto loc_102dc;
loc_102d3:
if (al != 0x03)
goto loc_102dc;
memory(ds, 0x9505) = 0x00;
loc_102dc:
al = memory(ds, 0x8f0a);
if (al != 0x00)
goto loc_102e4;
return;
loc_102e4:
ax = 0x0003;
interrupt(0x33);
if (!(bx & 0x0001))
goto loc_102f5;
memory16(ds, 0x954c) |= 0x0080;
loc_102f5:
if (!(bx & 0x0002))
goto loc_10300;
memory16(ds, 0x954c) |= 0x0020;
loc_10300:
ax = memory16(ds, 0x954c);
ax &= 0x000f;
if (ax == 0)
goto loc_10309;
return;
loc_10309:
ax = 0x000b;
interrupt(0x33);
if ((short)cx >= (short)0xfffb)
goto loc_1031a;
memory16(ds, 0x954c) |= 0x0001;
goto loc_10324;
loc_1031a:
if ((short)cx <= (short)0x0005)
goto loc_10324;
memory16(ds, 0x954c) |= 0x0002;
loc_10324:
if ((short)dx >= (short)0xfff6)
goto loc_10330;
memory16(ds, 0x954c) |= 0x0004;
return;
loc_10330:
if ((short)dx <= (short)0x000a)
return;
memory16(ds, 0x954c) |= 0x0008;
}
// extracting 1000:0fda, converted 89, to convert 105, failed 0
void sub_10fda()
{
loc_10fda:
al = memory(ds, 0x94ff);
memory(ds, 0x9509) = al;
si = 0x1b8a;
loc_10fe3:
al = memory(ds, 0x9513);
if (al == 0x00)
goto loc_10ff5;
sub_10e07();
al = memory(ds, 0x9500);
if (al == 0x00)
goto loc_10fda;
return;
loc_10ff5:
al = memory(ds, 0x94ff);
if (al == memory(ds, 0x9509))
goto loc_11036;
if (al != 0x01)
goto loc_1100e;
al = 0x0b;
sub_13840();
sub_10f3c();
goto loc_10fda;
stop(); //   gap of 2 bytes
loc_1100e:
al = 0x0b;
sub_13840();
al = memory(ds, 0x951d);
if (al != 0xf0)
goto loc_1101f;
sub_10dc0();
goto loc_11034;
loc_1101f:
al = memory(ds, 0x1ba0);
al &= 0x7f;
if (al <= 0x28)
goto loc_11031;
if (al >= 0x58)
goto loc_11031;
memory(ds, 0x9432) = 0x01;
loc_11031:
sub_10e84();
loc_11034:
goto loc_10fda;
loc_11036:
al = memory(ds, si);
if (al & 0x80)
return;
if (!(al & 0x02))
goto loc_11054;
push(si);
bl = memory(ds, si + 18);
if (bl == 0x00)
goto loc_11053;
bh = 0x00;
bx--;
bx <<= 1;
callIndirect(memory16(cs, bx + 4186));
loc_11053:
pop(si);
loc_11054:
si += 0x0017;
goto loc_10fe3;
}
// extracting 1000:32fe, converted 90, to convert 110, failed 0
void sub_132fe()
{
dx = 0x03ce;
ax = 0x0105;
out(dx, ax);
ax = memory16(ds, 0x94f8);
es = ax;
di = 0x0144;
ax = memory16(ds, 0x9528);
ax <<= 1;
ax <<= 1;
ax <<= 1;
ax <<= 1;
ax <<= 1;
si = ax;
push(ds);
ax = 0xa800;
ds = ax;
flags.direction = false;
cx = 0x00a0;
loc_13326:
push(cx);
cx = 0x0020;
rep_movsb<MemVideo, MemVideo, DirAuto>();
si &= 0x7fff;
di += 0x0008;
pop(cx);
if (--cx)
goto loc_13326;
pop(ds);
ax = 0x0005;
out(dx, ax);
}
// extracting 1000:0b8e, converted 91, to convert 109, failed 0
void sub_10b8e()
{
ax = memory16(ds, 0x94f8);
memory16(ds, 0x942e) = ax;
memory16(cs, 0x0d93) = 0x0028;
memory16(ds, 0x9430) = 0x0001;
cx = 0x0007;
loc_10ba4:
si = 0x1b8a;
loc_10ba7:
al = memory(ds, si);
if (al & 0x80)
goto loc_10bc2;
if (!(al & 0x01))
goto loc_10bbd;
if (cl != memory(ds, si + 2))
goto loc_10bbd;
push(cx);
push(si);
sub_10bdc();
pop(si);
pop(cx);
loc_10bbd:
si += 0x0017;
goto loc_10ba7;
loc_10bc2:
if (--cx)
goto loc_10ba4;
}
// extracting 1000:34a8, converted 92, to convert 109, failed 0
void sub_134a8()
{
di = 0x0000;
ax = memory16(ds, 0x94f4);
es = ax;
ax = 0x0000;
cx = 0x1000;
flags.direction = false;
rep_stosw<MemAuto, DirAuto>();
ax = 0x004f;
push(ax);
ax = 0x00ff;
push(ax);
ax = 0x00b0;
push(ax);
ax = 0x0000;
push(ax);
sub_136d4();
ax = 0x004f;
push(ax);
ax = 0x0000;
push(ax);
ax = 0x00b0;
push(ax);
ax = 0x00ff;
push(ax);
sub_136d4();
ax = 0x0000;
push(ax);
ax = 0x004f;
push(ax);
ax = 0x00ff;
push(ax);
ax = 0x00b0;
push(ax);
sub_136d4();
ax = 0x0000;
push(ax);
ax = 0x00b0;
push(ax);
ax = 0x00ff;
push(ax);
ax = 0x004f;
push(ax);
sub_136d4();
ax = memory16(ds, 0x9547);
ax &= 0x003f;
memory16(ds, 0x954e) = ax;
bx = ax;
ax += 0x0040;
push(ax);
al = memory(ds, bx + 8156);
ah = 0x00;
push(ax);
sub_135bc();
ax = memory16(ds, 0x954e);
if (ax <= 0x000c)
goto loc_13527;
return;
loc_13527:
bx = memory16(ds, 0x954e);
al = memory(ds, bx + 8220);
ah = 0x00;
ax += 0x0080;
push(ax);
ax = 0x0000;
push(ax);
ax = 0x00ff;
push(ax);
al = memory(ds, bx + 8233);
ah = 0x00;
ax = -ax;
ax += 0x007f;
push(ax);
sub_136d4();
bx = memory16(ds, 0x954e);
al = memory(ds, bx + 8220);
ah = 0x00;
ax = -ax;
ax += 0x007f;
push(ax);
ax = 0x0000;
push(ax);
ax = 0x0000;
push(ax);
al = memory(ds, bx + 8233);
ah = 0x00;
ax = -ax;
ax += 0x007f;
push(ax);
sub_136d4();
bx = memory16(ds, 0x954e);
al = memory(ds, bx + 8220);
ah = 0x00;
ax += 0x0080;
push(ax);
ax = 0x00ff;
push(ax);
ax = 0x00ff;
push(ax);
al = memory(ds, bx + 8233);
ah = 0x00;
ax += 0x0080;
push(ax);
sub_136d4();
bx = memory16(ds, 0x954e);
al = memory(ds, bx + 8220);
ah = 0x00;
ax = -ax;
ax += 0x007f;
push(ax);
ax = 0x00ff;
push(ax);
ax = 0x0000;
push(ax);
al = memory(ds, bx + 8233);
ah = 0x00;
ax += 0x0080;
push(ax);
sub_136d4();
}
// extracting 1000:31a4, converted 93, to convert 117, failed 0
void sub_131a4()
{
ax = memory16(ds, 0x94f8);
es = ax;
di = 0x0144;
bx = memory16(ds, 0x94f4);
si = 0x0340;
sub_131e7();
ax = ~ax;
ax &= 0x000f;
ah = al;
al = 0x01;
dx = 0x03ce;
out(dx, ax);
sub_13209();
ah = al;
al = 0x00;
out(dx, ax);
push(ds);
ds = bx;
flags.direction = false;
cx = 0x00a0;
loc_131d2:
push(cx);
cx = 0x0020;
rep_movsb<MemVideo, MemAuto, DirAuto>();
di += 0x0008;
pop(cx);
if (--cx)
goto loc_131d2;
pop(ds);
ax = 0x0000;
out(dx, ax);
al++;
out(dx, ax);
}
// extracting 1000:220d, converted 94, to convert 117, failed 0
void sub_1220d()
{
memory(ds, 0x944c)++;
al = memory(ds, 0x944c);
al &= 0x03;
if (al != 0)
goto loc_12228;
ax = 0x0000;
push(ax);
push(ax);
push(ax);
al = memory(ds, 0x94fe);
push(ax);
sub_1269e();
sub_12714();
loc_12228:
ax = memory16(ds, 0x953c);
if (ax == 0x0000)
goto loc_12246;
if ((short)ax >= 0)
goto loc_12237;
sub_1252f();
goto loc_12240;
loc_12237:
cx = ax;
loc_12239:
push(cx);
sub_12542();
pop(cx);
if (--cx)
goto loc_12239;
loc_12240:
memory16(ds, 0x953c) = 0x0000;
loc_12246:
ax = memory16(ds, 0x9540);
if (ax == 0x0000)
goto loc_12264;
if ((short)ax >= 0)
goto loc_12255;
sub_12577();
goto loc_1225e;
loc_12255:
cx = ax;
loc_12257:
push(cx);
sub_1258a();
pop(cx);
if (--cx)
goto loc_12257;
loc_1225e:
memory16(ds, 0x9540) = 0x0000;
loc_12264:
ax = memory16(ds, 0x9544);
if (ax == 0x0000)
goto loc_1228a;
if ((short)ax >= 0)
goto loc_1227b;
ax = -ax;
cx = ax;
loc_12272:
push(cx);
sub_125bf();
pop(cx);
if (--cx)
goto loc_12272;
goto loc_12284;
loc_1227b:
cx = ax;
loc_1227d:
push(cx);
sub_125d2();
pop(cx);
if (--cx)
goto loc_1227d;
loc_12284:
memory16(ds, 0x9544) = 0x0000;
loc_1228a:
ax = memory16(ds, 0x9538);
if (ax == 0x0000)
return;
if ((short)ax >= 0)
goto loc_122a1;
ax = -ax;
cx = ax;
loc_12298:
push(cx);
sub_12464();
pop(cx);
if (--cx)
goto loc_12298;
goto loc_122aa;
loc_122a1:
cx = ax;
loc_122a3:
push(cx);
sub_1239b();
pop(cx);
if (--cx)
goto loc_122a3;
loc_122aa:
memory16(ds, 0x9538) = 0x0000;
}
// extracting 1000:3383, converted 95, to convert 126, failed 0
void sub_13383()
{
ax = memory16(ds, 0x94f8);
bx = memory16(ds, 0x94fa);
memory16(ds, 0x94f8) = bx;
memory16(ds, 0x94fa) = ax;
bx = memory16(ds, 0x94fa);
bx <<= 1;
bx <<= 1;
bx <<= 1;
bx <<= 1;
flags.interrupts = false;
dx = 0x03d4;
ah = bh;
al = 0x0c;
out(dx, ax);
flags.interrupts = true;
dx = 0x03da;
loc_133aa:
in(al, dx);
al &= 0x08;
if (al != 0)
goto loc_133aa;
sub_133d7();
}
// extracting 1000:08ba, converted 96, to convert 126, failed 0
void sub_108ba()
{
push(bp);
bp = sp;
bx = memory16(ss, bp + 4);
bx <<= 1;
ax = memory16(ds, bx + 37417);
if (ax == 0x0000)
goto loc_10946;
push(ax);
ah >>= 1;
ah >>= 1;
bl = ah;
bh = 0x00;
bx <<= 1;
si = memory16(ds, bx + 651);
if (ah < 0x0f)
goto loc_10902;
if (ah > 0x14)
goto loc_10902;
ah -= 0x0f;
memory(ds, si + 1) = ah;
bl = ah;
bh = 0x00;
al = memory(ds, bx + 38190);
if (al == 0x00)
goto loc_108f9;
pop(ax);
goto loc_10946;
loc_108f9:
bx <<= 1;
ax = memory16(ds, bx + 814);
memory16(ds, si + 15) = ax;
loc_10902:
memory(ds, si + 19) = 0x0a;
ax = memory16(ss, bp + 4);
memory(ds, si + 20) = al;
pop(ax);
cx = 0x000a;
loc_10910:
flags.carry = ax & 1;
ax >>= 1;
if (!flags.carry)
goto loc_10941;
push(ax);
push(cx);
sub_1094a();
al = memory(ds, si + 19);
ah = 0x00;
push(ax);
ax = memory16(ss, bp + 4);
push(ax);
sub_109e9();
if (ax == 0x0000)
goto loc_10932;
push(si);
sub_10b58();
pop(si);
goto loc_1093f;
loc_10932:
push(si);
sub_10b58();
if (si == 0x0000)
goto loc_1093e;
sub_10a1b();
loc_1093e:
pop(si);
loc_1093f:
pop(cx);
pop(ax);
loc_10941:
memory(ds, si + 19)--;
if (--cx)
goto loc_10910;
loc_10946:
pop(bp);
sp += 2;
}
// extracting 1000:3914, converted 97, to convert 117, failed 0
void sub_13914()
{
al--;
bl = al;
bh = 0x00;
bx <<= 1;
bx = memory16(ds, bx + 35812);
al = memory(ds, bx + 1);
memory(ds, 0x9557) = al;
if (bx != 0x8c2c)
goto loc_13941;
ax = memory16(ds, 0x9536);
ah = al;
al = 0x00;
ax <<= 1;
ax <<= 1;
ax = -ax;
ax += 0x1f40;
memory16(ds, 0x8c2e) = ax;
goto loc_13966;
loc_13941:
if (bx != 0x8c32)
goto loc_13966;
al = memory(ds, 0x1ba0);
ax &= 0x007f;
if (ax <= 0x003f)
goto loc_13957;
ax -= 0x0040;
goto loc_1395c;
loc_13957:
ax = -ax;
ax += 0x003f;
loc_1395c:
ax <<= 1;
ax <<= 1;
ax += 0x0190;
memory16(ds, 0x8c34) = ax;
loc_13966:
ax = memory16(ds, bx + 2);
memory16(ds, 0x9558) = ax;
ax = memory16(ds, bx + 4);
memory16(ds, 0x955a) = ax;
bl = memory(ds, bx);
memory(ds, 0x9553) = bl;
if ((char)bl <= (char)0x00)
goto loc_1398f;
bl--;
bh = 0x00;
bx <<= 1;
ax = memory16(ds, bx + 35932);
memory16(ds, 0x9555) = ax;
memory(ds, 0x9554) = 0x00;
loc_1398f:
al = 0xb6;
out(0x0043, al);
ax = memory16(ds, 0x9558);
out(0x0042, al);
al = ah;
out(0x0042, al);
in(al, 0x61);
al |= 0x03;
out(0x0061, al);
}
// extracting 1000:315e, converted 98, to convert 103, failed 0
void sub_1315e()
{
cx = -cx;
cx += 0x006a;
memory16(ds, si + 7) = cx;
}
// extracting 1000:3170, converted 99, to convert 102, failed 0
void sub_13170()
{
cx += 0x0080;
memory16(ds, si + 5) = cx;
}
// extracting 1000:3181, converted 100, to convert 100, failed 0
void sub_13181()
{
cx += 0x006a;
memory16(ds, si + 7) = cx;
}
// extracting 1000:3191, converted 101, to convert 98, failed 0
void sub_13191()
{
cx = -cx;
cx += 0x0080;
memory16(ds, si + 5) = cx;
}
// extracting 1000:268a, converted 102, to convert 95, failed 0
void sub_1268a()
{
ax = 0x0002;
push(ax);
ax = 0x0005;
push(ax);
ax = 0x0000;
push(ax);
ax = 0x0000;
push(ax);
sub_1269e();
}
// extracting 1000:20a0, converted 103, to convert 95, failed 0
void sub_120a0()
{
al = memory(ds, di);
memory(ds, si) = al;
al = memory(ds, di + 2);
memory(ds, si + 2) = al;
al = memory(ds, di + 22);
memory(ds, si + 22) = al;
al = memory(ds, di + 4);
memory(ds, si + 4) = al;
al = memory(ds, di + 9);
memory(ds, si + 9) = al;
al = memory(ds, di + 10);
memory(ds, si + 10) = al;
al = memory(ds, di + 11);
memory(ds, si + 11) = al;
al = memory(ds, di + 12);
memory(ds, si + 12) = al;
ax = memory16(ds, di + 15);
memory16(ds, si + 15) = ax;
al = memory(ds, di + 18);
memory(ds, si + 18) = al;
}
// extracting 1000:09b5, converted 104, to convert 92, failed 0
void sub_109b5()
{
push(bp);
bp = sp;
si = memory16(ss, bp + 8);
sub_10a1b();
bx = memory16(ss, bp + 6);
bx <<= 1;
cx = memory16(ds, bx + 3307);
bx = memory16(ss, bp + 4);
bx <<= 1;
al = memory(ds, 0x9502);
if (al != 0x01)
goto loc_109d9;
bx += 0x0080;
goto loc_109e1;
loc_109d9:
if (al != 0x02)
goto loc_109e1;
bx += 0x0100;
loc_109e1:
memory16(ds, bx + 37545) &= cx;
pop(bp);
sp += 6;
}
// extracting 1000:269e, converted 105, to convert 92, failed 0
void sub_1269e()
{
push(bp);
bp = sp;
al = memory(ds, 0x94ae);
al += memory(ss, bp + 4);
if (al <= 0x09)
goto loc_126b1;
al -= 0x0a;
memory(ds, 0x94ad)++;
loc_126b1:
memory(ds, 0x94ae) = al;
al = memory(ds, 0x94ad);
al += memory(ss, bp + 6);
if (al <= 0x09)
goto loc_126c4;
al -= 0x0a;
memory(ds, 0x94ac)++;
loc_126c4:
memory(ds, 0x94ad) = al;
al = memory(ds, 0x94ac);
al += memory(ss, bp + 8);
if (al <= 0x09)
goto loc_126d7;
al -= 0x0a;
memory(ds, 0x94ab)++;
loc_126d7:
memory(ds, 0x94ac) = al;
al = memory(ds, 0x94ab);
al += memory(ss, bp + 10);
if (al <= 0x09)
goto loc_126ea;
al -= 0x0a;
memory(ds, 0x94aa)++;
loc_126ea:
memory(ds, 0x94ab) = al;
al = memory(ds, 0x94aa);
if (al <= 0x09)
goto loc_12701;
al -= 0x0a;
memory(ds, 0x94a9)++;
push(ax);
push(si);
sub_122c1();
pop(si);
pop(ax);
loc_12701:
memory(ds, 0x94aa) = al;
al = memory(ds, 0x94a9);
if (al <= 0x09)
goto loc_1270d;
al -= 0x0a;
loc_1270d:
memory(ds, 0x94a9) = al;
pop(bp);
sp += 8;
}
// extracting 1000:1e7d, converted 106, to convert 86, failed 0
void sub_11e7d()
{
push(si);
di = 0x0ff7;
ax += memory16(ds, si + 5);
memory16(ds, di + 5) = ax;
bx += memory16(ds, si + 7);
bx &= 0x03ff;
memory16(ds, di + 7) = bx;
cl += memory(ds, si + 3);
memory(ds, di + 3) = cl;
si = di;
bx = 0x1039;
sub_12121();
sub_10b58();
if (si == 0x0000)
goto loc_11eb0;
pop(ax);
push(ax);
if (ax <= si)
goto loc_11eb0;
sub_116d6();
loc_11eb0:
pop(si);
al = memory(ds, 0x9518);
if (al != 0x00)
goto loc_11eb9;
return;
loc_11eb9:
push(si);
bl = memory(ds, si + 4);
bh = 0x00;
si = 0x13b0;
al = memory(ds, bx + 5021);
memory(ds, si + 4) = al;
ax = memory16(ds, 0x0ffc);
memory16(ds, si + 5) = ax;
ax = memory16(ds, 0x0ffe);
memory16(ds, si + 7) = ax;
al = memory(ds, 0x0ffa);
memory(ds, si + 3) = al;
memory(ds, si + 1) = 0x02;
bl = memory(ds, si + 4);
bh = 0x00;
al = memory(ds, bx + 5031);
memory(ds, si + 10) = al;
memory(ds, si + 9) = 0x04;
bx <<= 1;
ax = memory16(ds, bx + 5063);
memory16(ds, si + 15) = ax;
sub_10b58();
if (si == 0x0000)
goto loc_11f09;
pop(ax);
push(ax);
if (ax <= si)
goto loc_11f09;
sub_115fc();
loc_11f09:
pop(si);
}
// extracting 1000:2cea, converted 107, to convert 82, failed 0
void sub_12cea()
{
push(bp);
bp = sp;
ax = 0xa000;
es = ax;
di = memory16(ss, bp + 10);
bx = memory16(ss, bp + 4);
bx = memory16(ds, bx + 38120);
si = memory16(ss, bp + 12);
push(ds);
push(bx);
dx = 0x03ce;
ax = 0x0a05;
out(dx, ax);
ax = 0x0007;
out(dx, ax);
cx = memory16(ss, bp + 8);
cx >>= 1;
ah = 0x80;
al = 0x08;
pop(ds);
bx = memory16(ss, bp + 6);
loc_12d19:
push(ax);
push(bx);
push(cx);
push(di);
push(si);
loc_12d1e:
bh = 0x22;
loc_12d20:
bl = memory(ds, si);
si++;
if (bh != bl)
goto loc_12d3d;
ah >>= 1;
if (ah != 0)
goto loc_12d32;
ah = 0x40;
di++;
if (--cx)
goto loc_12d20;
goto loc_12d76;
loc_12d32:
ah >>= 1;
if (ah != 0)
goto loc_12d39;
ah = 0x80;
di++;
loc_12d39:
if (--cx)
goto loc_12d20;
goto loc_12d76;
loc_12d3d:
bh = bl;
bl >>= 1;
bl >>= 1;
bl >>= 1;
bl >>= 1;
if (bl == 0x02)
goto loc_12d55;
out(dx, ax);
memoryVideoAnd(es, di, bl);
memoryVideoAnd(es, di + 8192, bl);
loc_12d55:
ah >>= 1;
if (ah != 0)
goto loc_12d5c;
ah = 0x80;
di++;
loc_12d5c:
bh &= 0x0f;
if (bh == 0x02)
goto loc_12d6d;
out(dx, ax);
memoryVideoAnd(es, di, bh);
memoryVideoAnd(es, di + 8192, bh);
loc_12d6d:
ah >>= 1;
if (ah != 0)
goto loc_12d74;
ah = 0x80;
di++;
loc_12d74:
if (--cx)
goto loc_12d1e;
loc_12d76:
pop(si);
si += 0x00a0;
pop(di);
di += 0x0028;
di &= 0x7fff;
pop(cx);
pop(bx);
pop(ax);
bx--;
if (bx != 0)
goto loc_12d19;
pop(ds);
ax = 0xff08;
out(dx, ax);
ax = 0x0005;
out(dx, ax);
ax = 0x0f07;
out(dx, ax);
pop(bp);
sp += 10;
}
// extracting 1000:064d, converted 108, to convert 76, failed 0
void sub_1064d()
{
push(di);
push(cx);
ax = 0x3d00;
interrupt(0x21);
pop(cx);
pop(dx);
if (!flags.carry)
goto loc_10659;
return;
loc_10659:
memory16(ds, 0x8f1e) = ax;
bx = ax;
ax = memory16(ds, 0x8f20);
push(ds);
ds = ax;
ax = 0x3f00;
interrupt(0x21);
pop(ds);
ax = 0x3e00;
bx = memory16(ds, 0x8f1e);
interrupt(0x21);
}
// extracting 1000:279f, converted 109, to convert 74, failed 0
void sub_1279f()
{
sub_12809();
al = memory(ds, 0x94e0);
if (al != 0x00)
goto loc_127af;
memory(ds, 0x9546) = 0x00;
return;
loc_127af:
memory(ds, 0x9546) = 0x01;
bl = al;
bl <<= 1;
bl += al;
bh = 0x00;
bx <<= 1;
push(bx);
bx += 0x94a9;
si = 0x94a9;
cx = 0x0006;
loc_127c9:
lodsb<MemAuto, DirAuto>();
memory(ds, bx) = al;
bx++;
if (--cx)
goto loc_127c9;
pop(bx);
bx <<= 1;
bx += 0x9455;
memory16(ds, 0x9451) = bx;
si = 0x9455;
cx = 0x000c;
loc_127e0:
lodsb<MemAuto, DirAuto>();
memory(ds, bx) = al;
bx++;
if (--cx)
goto loc_127e0;
si = 0x94da;
loc_127e9:
al = memory(ds, si);
if (al == 0x00)
goto loc_127f2;
si++;
goto loc_127e9;
loc_127f2:
al = memory(ds, 0x94e0);
memory(ds, si) = al;
memory(ds, 0x94e0) = 0x00;
si -= 0x94da;
ax = si;
memory(ds, 0x9450) = al;
sub_128da();
}
// extracting 1000:28da, converted 110, to convert 75, failed 0
void sub_128da()
{
si = 0x94da;
di = 0x01b1;
cx = 0x0006;
loc_128e3:
push(cx);
di += 0x0002;
ax = memory16(ds, di);
di += 0x0002;
push(si);
push(di);
sub_12959();
pop(di);
pop(si);
di += 0x0002;
ax = memory16(ds, di);
di += 0x0002;
push(si);
push(di);
sub_12907();
pop(di);
pop(si);
si++;
pop(cx);
if (--cx)
goto loc_128e3;
}
// extracting 1000:39b8, converted 111, to convert 76, failed 0
void sub_139b8()
{
memory(ds, 0x9561) = 0x00;
memory16(ds, 0x955f) = 0x0000;
memory(ds, 0x955e) = 0x01;
al = memory(ds, 0x9546);
if (al != 0x00)
goto loc_139d4;
ax = 0x8dec;
goto loc_139d7;
loc_139d4:
ax = 0x8d4c;
loc_139d7:
memory16(ds, 0x9562) = ax;
}
// extracting 1000:3472, converted 112, to convert 75, failed 0
void sub_13472()
{
si = 0x0000;
bx = memory16(ds, 0x94f2);
sub_133e5();
sub_13383();
si = 0x0000;
bx = memory16(ds, 0x94f2);
sub_133e5();
ax = memory16(ds, 0x94f8);
push(ax);
ax = 0xa000;
ax += 0x0400;
push(ax);
sub_13291();
}
// extracting 1000:0d98, converted 113, to convert 78, failed 0
void sub_10d98()
{
memory16(ds, 0x9528) = 0x001a;
memory(ds, 0x9513) = 0x00;
sub_10b7c();
}
// extracting 1000:3498, converted 114, to convert 76, failed 0
void sub_13498()
{
ax = 0xa000;
ax += 0x0400;
push(ax);
ax = memory16(ds, 0x94f8);
push(ax);
sub_13291();
}
// extracting 1000:29db, converted 115, to convert 74, failed 0
void sub_129db()
{
memory16(ds, 0x9453) = 0x0000;
loc_129e1:
ax = memory16(ds, 0x9453);
if (ax >= 0x000c)
goto loc_12a39;
sub_10541();
if (al == 0x00)
goto loc_12a39;
if (al != 0x08)
goto loc_12a0d;
bx = memory16(ds, 0x9451);
bx += memory16(ds, 0x9453);
memory(ds, bx) = 0x2e;
memory16(ds, 0x9453)--;
if ((short)memory16(ds, 0x9453) >= 0)
goto loc_12a0b;
memory16(ds, 0x9453) = 0x0000;
loc_12a0b:
goto loc_12a1b;
loc_12a0d:
bx = memory16(ds, 0x9451);
bx += memory16(ds, 0x9453);
memory(ds, bx) = al;
memory16(ds, 0x9453)++;
loc_12a1b:
bx = memory16(ds, 0x9453);
if (bx >= 0x000c)
goto loc_12a2b;
bx += memory16(ds, 0x9451);
memory(ds, bx) = 0x5f;
loc_12a2b:
sub_12a64();
sub_13498();
sub_10b8e();
sub_13383();
goto loc_129e1;
loc_12a39:
bx = memory16(ds, 0x9453);
if (bx >= 0x000c)
goto loc_12a52;
bx += memory16(ds, 0x9451);
al = memory(ds, bx);
if (al != 0x5f)
goto loc_12a52;
memory(ds, bx) = 0x2e;
sub_12a64();
loc_12a52:
di = 0x9455;
dx = 0x1506;
cx = 0x008c;
sub_10674();
memory(ds, 0x9546) = 0x00;
}
// extracting 1000:01ad, converted 116, to convert 80, failed 0
void sub_101ad()
{
cx = 0x1f40;
loc_101b0:
push(cx);
sub_101c0();
pop(cx);
ax = memory16(ds, 0x954c);
if (!(al & 0x80))
goto loc_101bd;
return;
loc_101bd:
if (--cx)
goto loc_101b0;
}
// extracting 1000:019d, converted 117, to convert 80, failed 0
void sub_1019d()
{
si = 0x0109;
memory(ds, si + 4) = al;
bx = 0x0120;
sub_12121();
sub_10b58();
}
// extracting 1000:09a4, converted 118, to convert 79, failed 0
void sub_109a4()
{
di = 0x92a9;
cx = 0x00c0;
ax = ds;
es = ax;
ax = 0xffff;
flags.direction = false;
rep_stosw<MemAuto, DirAuto>();
}
// extracting 1000:069a, converted 119, to convert 78, failed 0
void sub_1069a()
{
al = memory(ds, 0x9501);
bl = al;
bl <<= 1;
bl += al;
bl += memory(ds, 0x9502);
bh = 0x00;
bx <<= 1;
si = memory16(ds, bx + 580);
di = 0x9229;
cx = 0x0040;
ax = ds;
es = ax;
ax = 0x0000;
flags.direction = false;
rep_stosw<MemAuto, DirAuto>();
di = 0x9229;
loc_106c2:
lodsb<MemAuto, DirAuto>();
if (al == 0xff)
goto loc_106eb;
al <<= 1;
al <<= 1;
ah = al;
lodsb<MemAuto, DirAuto>();
al <<= 1;
bl = al;
bh = 0x00;
al = 0x00;
ax |= memory16(ds, bx + 3287);
cx = ax;
lodsb<MemAuto, DirAuto>();
al = -al;
al += 0x3f;
al <<= 1;
bl = al;
memory16(ds, bx + 37417) |= cx;
goto loc_106c2;
loc_106eb:
al = memory(ds, 0x9501);
bl = al;
bl <<= 1;
bl += al;
bl += memory(ds, 0x9502);
bh = 0x00;
bx <<= 1;
si = memory16(ds, bx + 532);
di = 0x8f29;
cx = 0x0300;
bl = 0x00;
loc_10708:
bl--;
if ((char)bl >= 0)
goto loc_1072c;
lodsb<MemAuto, DirAuto>();
dl = al;
dl &= 0x3f;
al &= 0xc0;
if (al != 0)
goto loc_1071a;
bl = 0x00;
goto loc_1072c;
loc_1071a:
if (al != 0x40)
goto loc_10722;
bl = 0x01;
goto loc_1072c;
loc_10722:
if (al != 0x80)
goto loc_1072a;
bl = 0x02;
goto loc_1072c;
loc_1072a:
bl = 0x03;
loc_1072c:
memory(ds, di) = dl;
di++;
if (--cx)
goto loc_10708;
di = 0x0000;
ax = 0xa800;
es = ax;
dx = 0x03ce;
ah = 0x00;
al = 0x00;
out(dx, ax);
ax = 0x0f01;
out(dx, ax);
cx = 0x4000;
rep_stosw<MemVideo, DirAuto>();
ax = 0x8f29;
memory16(ds, 0x8f25) = ax;
memory16(ds, 0x8f23) = 0x03f0;
cx = 0x0040;
loc_10759:
push(cx);
memory(ds, 0x8f22) = 0x00;
sub_107af();
memory16(ds, 0x0279) = 0x0000;
memory(ds, 0x027d) = 0x08;
memory16(ds, 0x0283) += 0x0008;
si = 0x0274;
sub_10bc5();
memory16(ds, 0x0279) = 0x0008;
memory(ds, 0x027d) = 0x18;
cx = 0x000a;
loc_10786:
push(cx);
sub_107af();
si = 0x0274;
sub_10bc5();
memory16(ds, 0x0279) += 0x0018;
pop(cx);
if (--cx)
goto loc_10786;
memory(ds, 0x027d) = 0x08;
sub_107af();
si = 0x0274;
sub_10bc5();
memory16(ds, 0x8f23) -= 0x0010;
pop(cx);
if (--cx)
goto loc_10759;
}
// extracting 1000:0e3d, converted 120, to convert 83, failed 0
void sub_10e3d()
{
bl = memory(ds, 0x9501);
bh = 0x00;
bx <<= 1;
ax = memory16(ds, bx + 5365);
ax &= 0x03ff;
memory16(ds, 0x9528) = ax;
ax = memory16(ds, 0x94fc);
memory16(ds, 0x952a) = ax;
memory16(ds, 0x950a) = 0x0080;
memory(ds, 0x950e) = 0x00;
memory16(ds, 0x950f) = 0x0000;
memory16(ds, 0x9511) = 0x0000;
memory(ds, 0x9513) = 0x00;
memory(ds, 0x9515) = 0x00;
memory(ds, 0x9517) = 0x00;
memory(ds, 0x9432) = 0x00;
sub_10e84();
}
// extracting 1000:3439, converted 121, to convert 82, failed 0
void sub_13439()
{
ax = memory16(ds, 0x94f8);
es = ax;
di = 0x011c;
ax = 0xffff;
cx = 0x0010;
rep_stosw<MemVideo, DirAuto>();
di = 0x1a44;
cx = 0x0010;
rep_stosw<MemVideo, DirAuto>();
di = 0x011b;
al = 0x01;
cx = 0x00a2;
loc_13459:
memoryVideoSet(es, di, al);
di += 0x0028;
if (--cx)
goto loc_13459;
di = 0x013c;
al = 0x80;
cx = 0x00a2;
loc_13469:
memoryVideoSet(es, di, al);
di += 0x0028;
if (--cx)
goto loc_13469;
}
// extracting 1000:2200, converted 122, to convert 77, failed 0
void sub_12200()
{
sub_1250b();
sub_12553();
sub_1259b();
sub_1237c();
}
// extracting 1000:264a, converted 123, to convert 80, failed 0
void sub_1264a()
{
al = 0x00;
memory(ds, 0x94a9) = al;
memory(ds, 0x94aa) = al;
memory(ds, 0x94ab) = al;
memory(ds, 0x94ac) = al;
memory(ds, 0x94ad) = al;
memory(ds, 0x94ae) = al;
sub_12714();
}
// extracting 1000:2a7f, converted 124, to convert 80, failed 0
void sub_12a7f()
{
memory(ds, 0x952e) = 0x00;
memory(ds, 0x952f) = 0x00;
memory(ds, 0x9530) = 0x00;
memory(ds, 0x9531) = 0x00;
memory(ds, 0x9532) = 0x00;
memory(ds, 0x9533) = 0x00;
ax = 0x1178;
push(ax);
ax = 0x1b82;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x0008;
push(ax);
ax = 0x0004;
push(ax);
sub_12cea();
ax = 0x1678;
push(ax);
ax = 0x1cc2;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x0008;
push(ax);
ax = 0x0004;
push(ax);
sub_12cea();
ax = 0x1b78;
push(ax);
ax = 0x1e02;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x0008;
push(ax);
ax = 0x0004;
push(ax);
sub_12cea();
ax = 0x2078;
push(ax);
ax = 0x1b85;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x0008;
push(ax);
ax = 0x0004;
push(ax);
sub_12cea();
ax = 0x2578;
push(ax);
ax = 0x1cc5;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x0008;
push(ax);
ax = 0x0004;
push(ax);
sub_12cea();
ax = 0x2a78;
push(ax);
ax = 0x1e05;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x0008;
push(ax);
ax = 0x0004;
push(ax);
sub_12cea();
}
// extracting 1000:22b1, converted 125, to convert 85, failed 0
void sub_122b1()
{
memory16(ds, 0x9534) = 0x0003;
sub_122e1();
sub_122f9();
sub_12311();
}
// extracting 1000:033b, converted 126, to convert 87, failed 0
void sub_1033b()
{
sub_12c07();
al = 0x04;
sub_12c9a();
sub_104f3();
memory16(ds, 0x8f15) = ax;
al = 0x00;
sub_12c9a();
loc_1034e:
sub_104f3();
if (ax == memory16(ds, 0x8f15))
goto loc_1034e;
memory16(ds, 0x8f0d) = ax;
al = 0x01;
sub_12c9a();
loc_1035f:
sub_104f3();
if (ax == memory16(ds, 0x8f15))
goto loc_1035f;
if (ax == memory16(ds, 0x8f0d))
goto loc_1035f;
memory16(ds, 0x8f0f) = ax;
al = 0x02;
sub_12c9a();
loc_10376:
sub_104f3();
if (ax == memory16(ds, 0x8f15))
goto loc_10376;
if (ax == memory16(ds, 0x8f0d))
goto loc_10376;
if (ax == memory16(ds, 0x8f0f))
goto loc_10376;
memory16(ds, 0x8f11) = ax;
al = 0x03;
sub_12c9a();
loc_10393:
sub_104f3();
if (ax == memory16(ds, 0x8f15))
goto loc_10393;
if (ax == memory16(ds, 0x8f0d))
goto loc_10393;
if (ax == memory16(ds, 0x8f0f))
goto loc_10393;
if (ax == memory16(ds, 0x8f11))
goto loc_10393;
memory16(ds, 0x8f13) = ax;
al = 0x06;
sub_12c9a();
loc_103b6:
sub_104f3();
if (ax == memory16(ds, 0x8f15))
goto loc_103b6;
if (ax == memory16(ds, 0x8f0d))
goto loc_103b6;
if (ax == memory16(ds, 0x8f0f))
goto loc_103b6;
if (ax == memory16(ds, 0x8f11))
goto loc_103b6;
if (ax == memory16(ds, 0x8f13))
goto loc_103b6;
memory16(ds, 0x8f17) = ax;
al = 0x07;
sub_12c9a();
loc_103df:
sub_104f3();
if (ax == memory16(ds, 0x8f15))
goto loc_103df;
if (ax == memory16(ds, 0x8f0d))
goto loc_103df;
if (ax == memory16(ds, 0x8f0f))
goto loc_103df;
if (ax == memory16(ds, 0x8f11))
goto loc_103df;
if (ax == memory16(ds, 0x8f13))
goto loc_103df;
if (ax == memory16(ds, 0x8f17))
goto loc_103df;
memory16(ds, 0x8f19) = ax;
al = 0x05;
sub_12c9a();
loc_1040e:
sub_104f3();
if (ax == memory16(ds, 0x8f15))
goto loc_1040e;
if (ax == memory16(ds, 0x8f0d))
goto loc_1040e;
if (ax == memory16(ds, 0x8f0f))
goto loc_1040e;
if (ax == memory16(ds, 0x8f11))
goto loc_1040e;
if (ax == memory16(ds, 0x8f13))
goto loc_1040e;
if (ax == memory16(ds, 0x8f17))
goto loc_1040e;
if (ax == memory16(ds, 0x8f19))
goto loc_1040e;
memory16(ds, 0x8f1b) = ax;
sub_10529();
}
// extracting 1000:2c45, converted 127, to convert 104, failed 0
void sub_12c45()
{
ax = 0x0aac;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x0028;
push(ax);
ax = 0x0005;
push(ax);
sub_12d9a();
ax = 0x0b4d;
push(ax);
ax = 0x000e;
push(ax);
ax = 0x0020;
push(ax);
ax = 0x0002;
push(ax);
sub_12d9a();
ax = 0x7592;
push(ax);
ax = 0x0c8f;
push(ax);
ax = 0x0028;
push(ax);
ax = 0x000c;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
ax = 0x1ab8;
push(ax);
ax = 0x0ce4;
push(ax);
ax = 0x0020;
push(ax);
ax = 0x000d;
push(ax);
ax = 0x0004;
push(ax);
sub_12cea();
}
// extracting 1000:0529, converted 128, to convert 107, failed 0
void sub_10529()
{
loc_10529:
si = 0x8e8a;
ah = 0x00;
loc_1052e:
lodsb<MemAuto, DirAuto>();
if (al == 0x00)
goto loc_10535;
ah++;
loc_10535:
if (si != 0x8f0a)
goto loc_1052e;
if (ah != 0x00)
goto loc_10529;
}
// extracting 1000:0e07, converted 129, to convert 104, failed 0
void sub_10e07()
{
ax = memory16(ds, 0x9534);
if (ax != 0x0000)
goto loc_10e15;
memory(ds, 0x9500) = 0x01;
return;
loc_10e15:
sub_12329();
al = memory(ds, 0x9502);
if (al == 0x00)
goto loc_10e27;
memory(ds, 0x9502) = 0x00;
sub_1069a();
loc_10e27:
sub_12200();
memory(ds, 0x9519) = 0x01;
memory(ds, 0x951a) = 0x00;
memory(ds, 0x951b) = 0x00;
sub_10e3d();
}
// extracting 1000:0f3c, converted 130, to convert 106, failed 0
void sub_10f3c()
{
memory(ds, 0x951c) = 0x00;
sub_12ddc();
memory16(ds, 0x9528) = 0x001a;
memory16(ds, 0x9547) = 0x0000;
memory16(ds, 0x951e) = 0x0000;
memory(ds, 0x9524) = 0x00;
memory(ds, 0x9549) = 0x03;
sub_10b7c();
si = 0x0d04;
sub_10b58();
sub_12df6();
al = memory(ds, 0x951a);
if (al == 0x00)
goto loc_10f84;
memory(ds, 0x951a) = 0x01;
si = 0x0d1b;
memory(ds, si) &= 0xdf;
sub_12f50();
sub_10b58();
loc_10f84:
al = memory(ds, 0x951b);
if (al == 0x00)
return;
memory(ds, 0x951b) = 0x01;
si = 0x0d1b;
memory(ds, si) |= 0x20;
sub_12f50();
sub_10b58();
}
// extracting 1000:0dc0, converted 131, to convert 112, failed 0
void sub_10dc0()
{
memory(ds, 0x94fe)++;
al = memory(ds, 0x94fe);
if (al < 0x06)
goto loc_10dd3;
memory16(ds, 0x94fc) = 0x0030;
goto loc_10de5;
loc_10dd3:
if (al < 0x03)
goto loc_10ddf;
memory16(ds, 0x94fc) = 0x0020;
goto loc_10de5;
loc_10ddf:
memory16(ds, 0x94fc) = 0x0010;
loc_10de5:
memory(ds, 0x9501)++;
al = memory(ds, 0x9501);
if (al <= 0x07)
goto loc_10df5;
memory(ds, 0x9501) = 0x01;
loc_10df5:
sub_109a4();
sub_1069a();
memory(ds, 0x9519) = 0x00;
sub_10e3d();
sub_12a7f();
}
// extracting 1000:0e84, converted 132, to convert 115, failed 0
void sub_10e84()
{
al = memory(ds, 0x950e);
if (al == 0x00)
goto loc_10e93;
memory(ds, 0x950e) = 0x00;
sub_1069a();
loc_10e93:
memory16(ds, 0x952c) = 0x0000;
sub_10b7c();
si = 0x0d32;
sub_10b58();
ax = memory16(ds, 0x950a);
memory16(ds, 0x1b8f) = ax;
sub_11b57();
ax = memory16(ds, 0x9528);
ax >>= 1;
ax >>= 1;
ax >>= 1;
ax >>= 1;
ax -= 0x0003;
ax &= 0x003f;
memory16(ds, 0x9507) = ax;
cx = 0x000f;
loc_10ec2:
push(cx);
push(ax);
push(ax);
sub_108ba();
pop(ax);
pop(cx);
ax++;
ax &= 0x003f;
if (--cx)
goto loc_10ec2;
al = memory(ds, 0x9432);
if (al == 0x00)
goto loc_10eea;
si = 0x1b8a;
bx = 0x0d49;
memory(ds, si + 4) = 0x0a;
sub_12121();
memory(ds, 0x1b9c) = 0x23;
return;
loc_10eea:
al = memory(ds, 0x9519);
if (al == 0x00)
goto loc_10f08;
memory(ds, 0x9519) = 0x00;
si = 0x0da2;
ax = memory16(ds, 0x1b91);
memory16(ds, si + 7) = ax;
al = memory(ds, 0x1b8d);
memory(ds, si + 3) = al;
sub_10b58();
loc_10f08:
sub_10f9d();
al = memory(ds, 0x951a);
if (al == 0x00)
goto loc_10f23;
memory(ds, 0x951a) = 0x01;
si = 0x0dc3;
memory(ds, si) &= 0xdf;
sub_11cd9();
sub_10b58();
loc_10f23:
al = memory(ds, 0x951b);
if (al == 0x00)
return;
memory(ds, 0x951b) = 0x01;
si = 0x0dc3;
memory(ds, si) |= 0x20;
sub_11cd9();
sub_10b58();
}
// extracting 1000:0bdc, converted 133, to convert 126, failed 0
void sub_10bdc()
{
al = memory(ds, si + 11);
cbw();
bx = memory16(ds, si + 5);
bx -= ax;
push(bx);
al = memory(ds, si + 3);
al += memory(ds, si + 12);
cbw();
ax = -ax;
ax += memory16(ds, si + 7);
push(ax);
al = memory(ds, si + 9);
ah = 0x00;
push(ax);
al = memory(ds, si + 10);
ah = 0x00;
push(ax);
bx = memory16(ds, si + 13);
bx = memory16(ds, bx + 38120);
al = memory(ds, si + 17);
memory(cs, 0x0d95) = al;
cl = al;
cl <<= 1;
cl <<= 1;
cl <<= 1;
cl <<= 1;
al |= cl;
memory(cs, 0x0d96) = al;
si = memory16(ds, si + 15);
sub_10c24();
}
// extracting 1000:36d4, converted 134, to convert 126, failed 0
void sub_136d4()
{
push(bp);
bp = sp;
sp -= 0x000a;
ax = memory16(ds, 0x94f4);
es = ax;
ax = memory16(ss, bp + 8);
if (ax == 0x0000)
goto loc_136fa;
bx = ax;
ax <<= 1;
ax <<= 1;
ax += bx;
ax <<= 1;
ax += 0x0005;
bl = 0x0c;
div(bl);
ah = 0x00;
loc_136fa:
memory16(ss, bp + 8) = ax;
ax = memory16(ss, bp + 4);
if (ax == 0x0000)
goto loc_13718;
bx = ax;
ax <<= 1;
ax <<= 1;
ax += bx;
ax <<= 1;
ax += 0x0005;
bl = 0x0c;
div(bl);
ah = 0x00;
loc_13718:
memory16(ss, bp + 4) = ax;
ax = memory16(ss, bp + 10);
bx = memory16(ss, bp + 6);
if (bx >= ax)
goto loc_13737;
memory16(ss, bp + 10) = bx;
memory16(ss, bp + 6) = ax;
ax = memory16(ss, bp + 8);
bx = memory16(ss, bp + 4);
memory16(ss, bp + 8) = bx;
memory16(ss, bp + 4) = ax;
loc_13737:
ax = memory16(ss, bp + 6);
ax -= memory16(ss, bp + 10);
memory16(ss, bp - 2) = ax;
ax = memory16(ss, bp + 4);
ax -= memory16(ss, bp + 8);
if ((short)ax >= 0)
goto loc_13751;
ax = -ax;
memory16(ss, bp - 10) = 0xffe0;
goto loc_13756;
loc_13751:
memory16(ss, bp - 10) = 0x0020;
loc_13756:
memory16(ss, bp - 4) = ax;
cx = memory16(ss, bp - 2);
if (cx == 0x0000)
goto loc_137db;
if (ax != 0x0000)
goto loc_13769;
goto loc_137ed;
loc_13769:
if (ax >= memory16(ss, bp - 2))
goto loc_137a4;
ax = memory16(ss, bp - 2);
ax >>= 1;
memory16(ss, bp - 6) = ax;
sub_13801();
cx = memory16(ss, bp - 2);
loc_1377c:
al >>= 1;
if (al != 0)
goto loc_13783;
al = 0x80;
di++;
di &= 0xffff;
loc_13783:
bx = memory16(ss, bp - 6);
bx += memory16(ss, bp - 4);
memory16(ss, bp - 6) = bx;
if (bx <= memory16(ss, bp - 2))
goto loc_1379d;
bx -= memory16(ss, bp - 2);
memory16(ss, bp - 6) = bx;
bx = memory16(ss, bp - 10);
di += memory16(ss, bp - 10);
di &= 0xffff;
loc_1379d:
memory(es, di) |= al;
if (--cx)
goto loc_1377c;
goto loc_137d5;
loc_137a4:
ax = memory16(ss, bp - 4);
ax >>= 1;
memory16(ss, bp - 6) = ax;
sub_13801();
cx = memory16(ss, bp - 4);
loc_137b2:
di += memory16(ss, bp - 10);
di &= 0xffff;
bx = memory16(ss, bp - 6);
bx += memory16(ss, bp - 2);
memory16(ss, bp - 6) = bx;
if (bx <= memory16(ss, bp - 4))
goto loc_137d0;
bx -= memory16(ss, bp - 4);
memory16(ss, bp - 6) = bx;
al >>= 1;
if (al != 0)
goto loc_137d0;
al = 0x80;
di++;
di &= 0xffff;
loc_137d0:
memory(es, di) |= al;
if (--cx)
goto loc_137b2;
loc_137d5:
sp = bp;
pop(bp);
sp += 8;
return;
loc_137db:
sub_13801();
cx = memory16(ss, bp - 4);
if (cx == 0)
goto loc_137d5;
loc_137e3:
di += memory16(ss, bp - 10);
memory(es, di) |= al;
if (--cx)
goto loc_137e3;
goto loc_137d5;
loc_137ed:
sub_13801();
cx = memory16(ss, bp - 2);
loc_137f3:
al >>= 1;
if (al != 0)
goto loc_137fa;
al = 0x80;
di++;
di &= 0xffff;
loc_137fa:
memory(es, di) |= al;
if (--cx)
goto loc_137f3;
goto loc_137d5;
}
// extracting 1000:35bc, converted 135, to convert 126, failed 0
void sub_135bc()
{
push(bp);
bp = sp;
loc_135bf:
ax = 0x007f;
ax -= memory16(ss, bp + 4);
push(ax);
ax = 0x007f;
ax -= memory16(ss, bp + 6);
push(ax);
ax = 0x0080;
ax += memory16(ss, bp + 4);
push(ax);
ax = 0x007f;
ax -= memory16(ss, bp + 6);
push(ax);
sub_136d4();
ax = 0x0080;
ax += memory16(ss, bp + 4);
push(ax);
ax = 0x007f;
ax -= memory16(ss, bp + 6);
push(ax);
ax = 0x0080;
ax += memory16(ss, bp + 6);
push(ax);
ax = 0x007f;
ax -= memory16(ss, bp + 4);
push(ax);
sub_136d4();
ax = 0x0080;
ax += memory16(ss, bp + 6);
push(ax);
ax = 0x007f;
ax -= memory16(ss, bp + 4);
push(ax);
ax = 0x0080;
ax += memory16(ss, bp + 6);
push(ax);
ax = 0x0080;
ax += memory16(ss, bp + 4);
push(ax);
sub_136d4();
ax = 0x0080;
ax += memory16(ss, bp + 4);
push(ax);
ax = 0x0080;
ax += memory16(ss, bp + 6);
push(ax);
ax = 0x0080;
ax += memory16(ss, bp + 6);
push(ax);
ax = 0x0080;
ax += memory16(ss, bp + 4);
push(ax);
sub_136d4();
ax = 0x007f;
ax -= memory16(ss, bp + 4);
push(ax);
ax = 0x0080;
ax += memory16(ss, bp + 6);
push(ax);
ax = 0x0080;
ax += memory16(ss, bp + 4);
push(ax);
ax = 0x0080;
ax += memory16(ss, bp + 6);
push(ax);
sub_136d4();
ax = 0x007f;
ax -= memory16(ss, bp + 6);
push(ax);
ax = 0x0080;
ax += memory16(ss, bp + 4);
push(ax);
ax = 0x007f;
ax -= memory16(ss, bp + 4);
push(ax);
ax = 0x0080;
ax += memory16(ss, bp + 6);
push(ax);
sub_136d4();
ax = 0x007f;
ax -= memory16(ss, bp + 6);
push(ax);
ax = 0x007f;
ax -= memory16(ss, bp + 4);
push(ax);
ax = 0x007f;
ax -= memory16(ss, bp + 6);
push(ax);
ax = 0x0080;
ax += memory16(ss, bp + 4);
push(ax);
sub_136d4();
ax = 0x007f;
ax -= memory16(ss, bp + 6);
push(ax);
ax = 0x007f;
ax -= memory16(ss, bp + 4);
push(ax);
ax = 0x007f;
ax -= memory16(ss, bp + 4);
push(ax);
ax = 0x007f;
ax -= memory16(ss, bp + 6);
push(ax);
sub_136d4();
ax = memory16(ss, bp + 6);
ax >>= 1;
if (al <= memory(ds, 0x9549))
goto loc_136d0;
memory16(ss, bp + 6) = ax;
ax = memory16(ss, bp + 4);
ax >>= 1;
memory16(ss, bp + 4) = ax;
goto loc_135bf;
loc_136d0:
pop(bp);
sp += 4;
}
// extracting 1000:31e7, converted 136, to convert 129, failed 0
void sub_131e7()
{
al = memory(ds, 0x951d);
if (al != 0x40)
goto loc_131f3;
ax = 0x0002;
return;
loc_131f3:
if (al != 0x80)
goto loc_131fc;
ax = 0x0004;
return;
loc_131fc:
if (al != 0xc0)
goto loc_13205;
ax = 0x0001;
return;
loc_13205:
ax = 0x0003;
}
// extracting 1000:3209, converted 137, to convert 128, failed 0
void sub_13209()
{
al = memory(ds, 0x951c);
if (al != 0x00)
goto loc_13215;
ax = 0x0000;
return;
loc_13215:
if (al != 0x01)
goto loc_13223;
ax = 0x0007;
memory(ds, 0x951c) = 0x00;
return;
loc_13223:
ax = 0x000f;
memory(ds, 0x951c) = 0x01;
}
// extracting 1000:2714, converted 138, to convert 126, failed 0
void sub_12714()
{
memory(ds, 0x944d) = 0x01;
si = 0x94a9;
cx = 0x0006;
dx = 0x0000;
loc_12722:
push(cx);
lodsb<MemAuto, DirAuto>();
if (al == 0x00)
goto loc_1272d;
memory(ds, 0x944d) = 0x00;
loc_1272d:
cl = memory(ds, 0x944d);
if (cl != 0x00)
goto loc_1275e;
push(dx);
push(si);
bh = 0x00;
bl = al;
bx <<= 1;
ax = memory16(ds, bx + 5471);
push(ax);
bx = dx;
ax = memory16(ds, bx + 5491);
push(ax);
ax = 0x0010;
push(ax);
ax = 0x0009;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
pop(si);
pop(dx);
dx += 0x0002;
loc_1275e:
pop(cx);
if (--cx)
goto loc_12722;
}
// extracting 1000:252f, converted 139, to convert 126, failed 0
void sub_1252f()
{
ax = memory16(ds, 0x953a);
ax--;
if ((short)ax >= 0)
goto loc_12536;
return;
loc_12536:
memory16(ds, 0x953a) = ax;
push(ax);
ax = 0x1b88;
push(ax);
sub_125e3();
}
// extracting 1000:2542, converted 140, to convert 126, failed 0
void sub_12542()
{
ax = memory16(ds, 0x953a);
if (ax < 0x002c)
goto loc_1254b;
return;
loc_1254b:
sub_12536();
memory16(ds, 0x953a)++;
}
// extracting 1000:2577, converted 141, to convert 126, failed 0
void sub_12577()
{
ax = memory16(ds, 0x953e);
ax--;
if ((short)ax >= 0)
goto loc_1257e;
return;
loc_1257e:
memory16(ds, 0x953e) = ax;
push(ax);
ax = 0x1cc8;
push(ax);
sub_125e3();
}
// extracting 1000:258a, converted 142, to convert 126, failed 0
void sub_1258a()
{
ax = memory16(ds, 0x953e);
if (ax < 0x0030)
goto loc_12593;
return;
loc_12593:
sub_1257e();
memory16(ds, 0x953e)++;
}
// extracting 1000:25bf, converted 143, to convert 126, failed 0
void sub_125bf()
{
ax = memory16(ds, 0x9542);
ax--;
if ((short)ax >= 0)
goto loc_125c6;
return;
loc_125c6:
memory16(ds, 0x9542) = ax;
push(ax);
ax = 0x1e08;
push(ax);
sub_125e3();
}
// extracting 1000:25d2, converted 144, to convert 126, failed 0
void sub_125d2()
{
ax = memory16(ds, 0x9542);
if (ax < 0x0038)
goto loc_125db;
return;
loc_125db:
sub_125c6();
memory16(ds, 0x9542)++;
}
// extracting 1000:2464, converted 145, to convert 126, failed 0
void sub_12464()
{
ax = memory16(ds, 0x9536);
memory16(ds, 0x9536)--;
if ((short)memory16(ds, 0x9536) >= 0)
goto loc_12474;
memory16(ds, 0x9536) = 0x0000;
return;
loc_12474:
if (ax == 0x0001)
goto loc_12493;
if (ax == 0x0002)
goto loc_124a7;
if (ax == 0x0003)
goto loc_124bb;
if (ax == 0x0004)
goto loc_124cf;
if (ax == 0x0005)
goto loc_124e3;
if (ax == 0x0006)
goto loc_124f7;
return;
loc_12493:
ax = 0x1b99;
push(ax);
ax = 0x0002;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0000;
push(ax);
sub_12d9a();
return;
loc_124a7:
ax = 0x1b9b;
push(ax);
ax = 0x0002;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0000;
push(ax);
sub_12d9a();
return;
loc_124bb:
ax = 0x1b9d;
push(ax);
ax = 0x0002;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0000;
push(ax);
sub_12d9a();
return;
loc_124cf:
ax = 0x1b9f;
push(ax);
ax = 0x0002;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0000;
push(ax);
sub_12d9a();
return;
loc_124e3:
ax = 0x1ba1;
push(ax);
ax = 0x0002;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0000;
push(ax);
sub_12d9a();
return;
loc_124f7:
ax = 0x1ba3;
push(ax);
ax = 0x0002;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0000;
push(ax);
sub_12d9a();
}
// extracting 1000:239b, converted 146, to convert 131, failed 0
void sub_1239b()
{
memory16(ds, 0x9536)++;
ax = memory16(ds, 0x9536);
if (ax <= 0x0006)
goto loc_123ae;
memory16(ds, 0x9536) = 0x0006;
return;
loc_123ae:
push(ax);
al = 0x08;
sub_13840();
pop(ax);
if (ax == 0x0001)
goto loc_123d4;
if (ax == 0x0002)
goto loc_123ec;
if (ax == 0x0003)
goto loc_12404;
if (ax == 0x0004)
goto loc_1241c;
if (ax == 0x0005)
goto loc_12434;
if (ax == 0x0006)
goto loc_1244c;
return;
loc_123d4:
ax = 0x43ee;
push(ax);
ax = 0x1b99;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
return;
loc_123ec:
ax = 0x43ee;
push(ax);
ax = 0x1b9b;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
return;
loc_12404:
ax = 0x43ee;
push(ax);
ax = 0x1b9d;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
return;
loc_1241c:
ax = 0x43ee;
push(ax);
ax = 0x1b9f;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
return;
loc_12434:
ax = 0x43ee;
push(ax);
ax = 0x1ba1;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
return;
loc_1244c:
ax = 0x43ee;
push(ax);
ax = 0x1ba3;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
}
// extracting 1000:094a, converted 147, to convert 136, failed 0
void sub_1094a()
{
dl = memory(ds, si + 19);
push(si);
al = 0x3f;
al -= memory(ds, si + 20);
al <<= 1;
al <<= 1;
ah = 0x00;
si = ax;
ax <<= 1;
si += ax;
si += 0x8f29;
cl = 0x00;
flags.direction = false;
loc_10966:
if (dl == 0x00)
goto loc_10978;
lodsb<MemAuto, DirAuto>();
bh = 0x00;
bl = al;
cl += memory(ds, bx + 1393);
dl--;
goto loc_10966;
loc_10978:
pop(si);
memory(ds, si + 3) = cl;
al = memory(ds, si + 20);
ah = 0x00;
ax <<= 1;
ax <<= 1;
ax <<= 1;
ax <<= 1;
memory16(ds, si + 7) = ax;
al = memory(ds, si + 19);
ah = 0x00;
ax <<= 1;
cx = ax;
ax <<= 1;
ax += cx;
ax <<= 1;
ax <<= 1;
ax -= 0x0004;
memory16(ds, si + 5) = ax;
}
// extracting 1000:09e9, converted 148, to convert 135, failed 0
void sub_109e9()
{
push(bp);
bp = sp;
bx = memory16(ss, bp + 6);
bx <<= 1;
cx = memory16(ds, bx + 3307);
bx = memory16(ss, bp + 4);
bx <<= 1;
al = memory(ds, 0x9502);
if (al != 0x01)
goto loc_10a07;
bx += 0x0080;
goto loc_10a0f;
loc_10a07:
if (al != 0x02)
goto loc_10a0f;
bx += 0x0100;
loc_10a0f:
cx = ~cx;
ax = memory16(ds, bx + 37545);
ax &= cx;
pop(bp);
sp += 4;
}
// extracting 1000:0a1b, converted 149, to convert 132, failed 0
void sub_10a1b()
{
al = memory(ds, si + 18);
al <<= 1;
bl = al;
bh = 0x00;
di = memory16(ds, bx + 798);
al = memory(ds, di);
memory(ds, si) = al;
al = memory(ds, di + 9);
memory(ds, si + 9) = al;
al = memory(ds, di + 10);
memory(ds, si + 10) = al;
al = memory(ds, di + 11);
memory(ds, si + 11) = al;
al = memory(ds, di + 12);
memory(ds, si + 12) = al;
ax = memory16(ds, di + 15);
memory16(ds, si + 15) = ax;
al = memory(ds, di + 18);
memory(ds, si + 18) = al;
}
// extracting 1000:22c1, converted 150, to convert 129, failed 0
void sub_122c1()
{
memory16(ds, 0x9534)++;
ax = memory16(ds, 0x9534);
if (ax <= 0x0003)
goto loc_122d4;
memory16(ds, 0x9534) = 0x0003;
return;
loc_122d4:
if (ax == 0x0003)
goto loc_12311;
if (ax == 0x0002)
goto loc_122f9;
if (ax == 0x0001)
goto loc_122e1;
return;
loc_122e1:
ax = 0x43e6;
push(ax);
ax = 0x1b90;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
return;
loc_122f9:
ax = 0x43e6;
push(ax);
ax = 0x1b93;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
return;
loc_12311:
ax = 0x43e6;
push(ax);
ax = 0x1b96;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
}
// extracting 1000:2809, converted 151, to convert 126, failed 0
void sub_12809()
{
al = memory(ds, 0x94da);
memory(ds, 0x94d3) = al;
al = memory(ds, 0x94db);
memory(ds, 0x94d4) = al;
al = memory(ds, 0x94dc);
memory(ds, 0x94d5) = al;
al = memory(ds, 0x94dd);
memory(ds, 0x94d6) = al;
al = memory(ds, 0x94de);
memory(ds, 0x94d7) = al;
al = memory(ds, 0x94df);
memory(ds, 0x94d8) = al;
al = memory(ds, 0x94e0);
memory(ds, 0x94d9) = al;
si = 0x94d3;
di = 0x94da;
cx = 0x0007;
loc_1283c:
push(cx);
push(si);
loc_1283e:
al = memory(ds, si);
if (al != 0xff)
goto loc_12847;
si++;
goto loc_1283e;
loc_12847:
if (si == 0x94d9)
goto loc_12865;
bx = si;
loc_1284f:
bx++;
al = memory(ds, bx);
if (al == 0xff)
goto loc_1285f;
sub_12872();
if (al == 0x00)
goto loc_1285f;
si = bx;
loc_1285f:
if (bx != 0x94d9)
goto loc_1284f;
loc_12865:
al = memory(ds, si);
memory(ds, si) = 0xff;
memory(ds, di) = al;
di++;
pop(si);
pop(cx);
if (--cx)
goto loc_1283c;
}
// extracting 1000:2959, converted 152, to convert 125, failed 0
void sub_12959()
{
memory16(ds, 0x944e) = ax;
al = memory(ds, si);
ah = al;
al <<= 1;
al += ah;
ah = 0x00;
ax <<= 1;
ax <<= 1;
ax += 0x9455;
si = ax;
cx = 0x000c;
dx = 0x0000;
loc_12975:
push(cx);
lodsb<MemAuto, DirAuto>();
push(si);
push(dx);
if (al != 0x20)
goto loc_12982;
ax = 0x6546;
goto loc_129a0;
loc_12982:
if (al != 0x2e)
goto loc_1298b;
ax = 0x6f6c;
goto loc_129a0;
loc_1298b:
if (al != 0x5f)
goto loc_12994;
ax = 0x764c;
goto loc_129a0;
loc_12994:
al -= 0x41;
ah = al;
al <<= 1;
al += ah;
al <<= 1;
ah = 0x00;
loc_129a0:
push(ax);
push(dx);
sub_129ae();
pop(dx);
dx += 0x0006;
pop(si);
pop(cx);
if (--cx)
goto loc_12975;
}
// extracting 1000:2907, converted 153, to convert 125, failed 0
void sub_12907()
{
memory16(ds, 0x944e) = ax;
al = memory(ds, si);
ah = al;
al <<= 1;
al += ah;
ah = 0x00;
ax <<= 1;
ax += 0x94a9;
si = ax;
memory(ds, 0x944d) = 0x01;
cx = 0x0006;
dx = 0x0000;
loc_12926:
push(cx);
lodsb<MemAuto, DirAuto>();
if (al == 0x00)
goto loc_12931;
memory(ds, 0x944d) = 0x00;
loc_12931:
cl = memory(ds, 0x944d);
if (cl == 0x00)
goto loc_1293f;
ax = 0x6f6c;
goto loc_12949;
loc_1293f:
bh = 0x00;
bl = al;
bx <<= 1;
ax = memory16(ds, bx + 5503);
loc_12949:
push(dx);
push(si);
push(ax);
push(dx);
sub_129ae();
pop(si);
pop(dx);
dx += 0x0006;
pop(cx);
if (--cx)
goto loc_12926;
}
// extracting 1000:33e5, converted 154, to convert 125, failed 0
void sub_133e5()
{
ax = memory16(ds, 0x94f8);
es = ax;
di = 0x0000;
dx = 0x03ce;
ax = 0x0805;
out(dx, ax);
ax = 0x0007;
out(dx, ax);
dl = 0xc4;
ax = 0x0802;
push(ds);
ds = bx;
loc_13400:
out(dx, ax);
push(ax);
push(di);
cx = 0x1f40;
loc_13406:
lodsb<MemAuto, DirAuto>();
memoryVideoAnd(es, di, al);
di++;
if (--cx)
goto loc_13406;
pop(di);
pop(ax);
ah >>= 1;
if (ah != 0)
goto loc_13400;
pop(ds);
ax = 0x0f02;
out(dx, ax);
dl = 0xce;
ax = 0x0005;
out(dx, ax);
ax = 0x0f07;
out(dx, ax);
}
// extracting 1000:3291, converted 155, to convert 122, failed 0
void sub_13291()
{
push(bp);
bp = sp;
ax = memory16(ss, bp + 4);
es = ax;
di = 0x0144;
bx = memory16(ss, bp + 6);
si = 0x0144;
dx = 0x03ce;
ax = 0x0105;
out(dx, ax);
push(ds);
ds = bx;
flags.direction = false;
cx = 0x00a0;
loc_132b0:
push(cx);
cx = 0x0020;
rep_movsb<MemVideo, MemVideo, DirAuto>();
si += 0x0008;
di += 0x0008;
pop(cx);
if (--cx)
goto loc_132b0;
pop(ds);
ax = 0x0005;
out(dx, ax);
pop(bp);
sp += 4;
}
// extracting 1000:0b7c, converted 156, to convert 121, failed 0
void sub_10b7c()
{
si = 0x1b8a;
loc_10b7f:
al = memory(ds, si);
if (al & 0x80)
return;
memory(ds, si) = 0x00;
si += 0x0017;
goto loc_10b7f;
}
// extracting 1000:0541, converted 157, to convert 119, failed 0
void sub_10541()
{
cx = 0x4e20;
loc_10544:
si = 0x8e8a;
ah = 0x00;
flags.direction = false;
loc_1054a:
lodsb<MemAuto, DirAuto>();
if (al == 0x00)
goto loc_10557;
ah = 0x01;
flags.zero = si == memory16(ds, 0x8f0b);
if (si != memory16(ds, 0x8f0b))
goto loc_1055f;
loc_10557:
flags.zero = si == 0x8f0a;
if (si == 0x8f0a)
goto loc_1055f;
goto loc_1054a;
loc_1055f:
if (flags.zero)
goto loc_10578;
memory16(ds, 0x8f0b) = si;
si -= 0x8e8b;
al = memory(ds, si + 90);
if (al == 0x00)
goto loc_10576;
if ((char)al >= 0)
goto loc_10575;
al = 0x00;
loc_10575:
return;
loc_10576:
goto loc_10583;
loc_10578:
if (ah != 0x00)
goto loc_10583;
memory16(ds, 0x8f0b) = 0x0000;
loc_10583:
if (--cx)
goto loc_10544;
al = 0x00;
}
// extracting 1000:2a64, converted 158, to convert 118, failed 0
void sub_12a64()
{
si = memory16(ds, 0x9451);
bl = memory(ds, 0x9450);
bh = 0x00;
bx <<= 1;
bx <<= 1;
bx <<= 1;
ax = memory16(ds, bx + 435);
memory16(ds, 0x944e) = ax;
sub_1296f();
}
// extracting 1000:0674, converted 159, to convert 114, failed 0
void sub_10674()
{
push(di);
push(cx);
cx = 0x0000;
ax = 0x3c00;
interrupt(0x21);
pop(cx);
pop(dx);
if (!flags.carry)
goto loc_10683;
return;
loc_10683:
memory16(ds, 0x8f1e) = ax;
bx = ax;
ax = 0x4000;
interrupt(0x21);
if (!flags.carry)
goto loc_10690;
return;
loc_10690:
ax = 0x3e00;
bx = memory16(ds, 0x8f1e);
interrupt(0x21);
}
// extracting 1000:07af, converted 160, to convert 110, failed 0
void sub_107af()
{
al = memory(ds, 0x8f22);
memory(ds, 0x0277) = al;
bx = memory16(ds, 0x8f25);
al = memory(ds, bx);
bx++;
memory16(ds, 0x8f25) = bx;
bh = 0x00;
bl = al;
al = memory(ds, bx + 1309);
memory(ds, 0x027e) = al;
al = memory(ds, bx + 1393);
memory(ds, 0x8f22) += al;
al = memory(ds, bx + 1351);
cbw();
ax += memory16(ds, 0x8f23);
memory16(ds, 0x027b) = ax;
if (bx < 0x0026)
goto loc_107ec;
memory16(ds, 0x0281) = 0x0002;
goto loc_107f2;
loc_107ec:
memory16(ds, 0x0281) = 0x0004;
loc_107f2:
bx <<= 1;
bx = memory16(ds, bx + 1519);
memory16(ds, 0x0283) = bx;
}
// extracting 1000:0bc5, converted 161, to convert 109, failed 0
void sub_10bc5()
{
ax = 0xa800;
memory16(ds, 0x942e) = ax;
memory16(cs, 0x0d93) = 0x0020;
memory16(ds, 0x9430) = 0x0000;
sub_10bdc();
}
// extracting 1000:250b, converted 162, to convert 104, failed 0
void sub_1250b()
{
memory16(ds, 0x953a) = 0x002c;
memory16(ds, 0x953c) = 0x0000;
ax = 0x48f6;
push(ax);
ax = 0x1b88;
push(ax);
ax = 0x002c;
push(ax);
ax = 0x0007;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
}
// extracting 1000:2553, converted 163, to convert 104, failed 0
void sub_12553()
{
memory16(ds, 0x953e) = 0x0030;
memory16(ds, 0x9540) = 0x0000;
ax = 0x2ce6;
push(ax);
ax = 0x1cc8;
push(ax);
ax = 0x0030;
push(ax);
ax = 0x0007;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
}
// extracting 1000:259b, converted 164, to convert 104, failed 0
void sub_1259b()
{
memory16(ds, 0x9542) = 0x0038;
memory16(ds, 0x9544) = 0x0000;
ax = 0x4496;
push(ax);
ax = 0x1e08;
push(ax);
ax = 0x0038;
push(ax);
ax = 0x0007;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
}
// extracting 1000:237c, converted 165, to convert 104, failed 0
void sub_1237c()
{
memory16(ds, 0x9536) = 0x0006;
memory16(ds, 0x9538) = 0x0000;
sub_123d4();
sub_123ec();
sub_12404();
sub_1241c();
sub_12434();
sub_1244c();
}
// extracting 1000:22e1, converted 166, to convert 102, failed 0
void sub_122e1()
{
ax = 0x43e6;
push(ax);
ax = 0x1b90;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
}
// extracting 1000:22f9, converted 167, to convert 102, failed 0
void sub_122f9()
{
ax = 0x43e6;
push(ax);
ax = 0x1b93;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
}
// extracting 1000:2311, converted 168, to convert 102, failed 0
void sub_12311()
{
ax = 0x43e6;
push(ax);
ax = 0x1b96;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
}
// extracting 1000:2c07, converted 169, to convert 102, failed 0
void sub_12c07()
{
ax = 0x0a0b;
push(ax);
ax = 0x0013;
push(ax);
ax = 0x0030;
push(ax);
ax = 0x0005;
push(ax);
sub_12d9a();
ax = 0x0aac;
push(ax);
ax = 0x0011;
push(ax);
ax = 0x0028;
push(ax);
ax = 0x0002;
push(ax);
sub_12d9a();
ax = 0x5a5c;
push(ax);
ax = 0x0b4d;
push(ax);
ax = 0x0078;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0004;
push(ax);
sub_12cea();
}
// extracting 1000:2c9a, converted 170, to convert 104, failed 0
void sub_12c9a()
{
push(ax);
ax = 0x0dcc;
push(ax);
ax = 0x0011;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0002;
push(ax);
sub_12d9a();
pop(ax);
if (al != 0x06)
goto loc_12cbc;
al = 0x00;
sub_12cc7();
al = 0x06;
goto loc_12cc7;
loc_12cbc:
if (al != 0x07)
goto loc_12cc7;
al = 0x01;
sub_12cc7();
al = 0x07;
loc_12cc7:
bl = al;
bh = 0x00;
bx <<= 1;
ax = memory16(ds, bx + 5407);
push(ax);
ax = memory16(ds, bx + 5423);
push(ax);
ax = memory16(ds, bx + 5439);
push(ax);
ax = memory16(ds, bx + 5455);
push(ax);
ax = memory16(ds, bx + 5391);
push(ax);
sub_12cea();
}
// extracting 1000:04f3, converted 171, to convert 107, failed 0
void sub_104f3()
{
flags.direction = false;
loc_104f4:
si = 0x8e8a;
loc_104f7:
lodsb<MemAuto, DirAuto>();
if (al == 0x00)
goto loc_10520;
ax = si;
ax -= 0x8e8b;
if (ax == 0x003b)
goto loc_10520;
if (ax == 0x003c)
goto loc_10520;
if (ax == 0x003d)
goto loc_10520;
if (ax == 0x003e)
goto loc_10520;
if (ax == 0x002a)
goto loc_10520;
if (ax == 0x0036)
goto loc_10520;
return;
loc_10520:
if (si != 0x8f0a)
goto loc_104f7;
goto loc_104f4;
}
// extracting 1000:2d9a, converted 172, to convert 91, failed 0
void sub_12d9a()
{
push(bp);
bp = sp;
ax = 0xa000;
es = ax;
di = memory16(ss, bp + 10);
dx = 0x03ce;
ax = memory16(ss, bp + 4);
ah = al;
al = 0x00;
out(dx, ax);
ax = 0x0f01;
out(dx, ax);
flags.direction = false;
bx = memory16(ss, bp + 6);
loc_12db8:
push(di);
cx = memory16(ss, bp + 8);
rep_stosb<MemVideo, DirAuto>();
pop(di);
push(di);
di += 0x2000;
cx = memory16(ss, bp + 8);
rep_stosb<MemVideo, DirAuto>();
pop(di);
di += 0x0028;
bx--;
if (bx != 0)
goto loc_12db8;
ax = 0x0000;
out(dx, ax);
al++;
out(dx, ax);
pop(bp);
sp += 8;
}
// extracting 1000:2329, converted 173, to convert 87, failed 0
void sub_12329()
{
memory16(ds, 0x9534)--;
ax = memory16(ds, 0x9534);
if (ax == 0x0002)
goto loc_12368;
if (ax == 0x0001)
goto loc_12354;
if (ax == 0x0000)
goto loc_12340;
return;
loc_12340:
ax = 0x1b90;
push(ax);
ax = 0x0002;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0000;
push(ax);
sub_12d9a();
return;
loc_12354:
ax = 0x1b93;
push(ax);
ax = 0x0002;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0000;
push(ax);
sub_12d9a();
return;
loc_12368:
ax = 0x1b96;
push(ax);
ax = 0x0002;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0000;
push(ax);
sub_12d9a();
}
// extracting 1000:2ddc, converted 174, to convert 86, failed 0
void sub_12ddc()
{
bl = memory(ds, 0x94e4);
bx &= 0x0003;
bx <<= 1;
ax = memory16(ds, bx + 6698);
memory16(ds, 0x94e2) = ax;
memory(ds, 0x94e4)++;
memory(ds, 0x9527) = 0xff;
}
// extracting 1000:2df6, converted 175, to convert 83, failed 0
void sub_12df6()
{
al = 0x00;
memory(ds, 0x94e5) = al;
memory(ds, 0x94e6) = al;
memory(ds, 0x94e7) = al;
}
// extracting 1000:0f9d, converted 176, to convert 67, failed 0
void sub_10f9d()
{
ax = memory16(ds, 0x1b8f);
memory16(ds, 0x9433) = ax;
memory16(ds, 0x9435) = ax;
memory16(ds, 0x9437) = ax;
memory16(ds, 0x9439) = ax;
ax = memory16(ds, 0x1b91);
memory16(ds, 0x943b) = ax;
memory16(ds, 0x943d) = ax;
memory16(ds, 0x943f) = ax;
memory16(ds, 0x9441) = ax;
al = memory(ds, 0x1b8e);
memory(ds, 0x9443) = al;
memory(ds, 0x9444) = al;
memory(ds, 0x9445) = al;
memory(ds, 0x9446) = al;
al = memory(ds, 0x1b8d);
memory(ds, 0x9447) = al;
memory(ds, 0x9448) = al;
memory(ds, 0x9449) = al;
memory(ds, 0x944a) = al;
}
// extracting 1000:0c24, converted 177, to convert 62, failed 0
void sub_10c24()
{
push(bp);
bp = sp;
ax = memory16(ds, 0x9430);
if (ax != 0x0000)
goto loc_10c32;
goto loc_10cbc;
loc_10c32:
ax = memory16(ss, bp + 8);
ax -= memory16(ds, 0x9528);
ax &= 0x03ff;
if (!(ax & 0x0200))
goto loc_10c44;
ax |= 0xfc00;
loc_10c44:
memory16(ss, bp + 8) = ax;
if ((short)ax >= (short)0x0000)
goto loc_10c77;
memory16(ss, bp + 4) += ax;
if ((short)memory16(ss, bp + 4) >= 0)
goto loc_10c54;
goto loc_10d8f;
loc_10c54:
if (memory16(ss, bp + 4) != 0)
goto loc_10c59;
goto loc_10d8f;
loc_10c59:
ax = -ax;
ax <<= 1;
ax <<= 1;
ax <<= 1;
cx = ax;
ax <<= 1;
ax <<= 1;
cx += ax;
cx <<= 1;
cx <<= 1;
si += cx;
ax = 0x0000;
memory16(ss, bp + 8) = ax;
goto loc_10c8f;
loc_10c77:
ax += memory16(ss, bp + 4);
ax -= 0x00a0;
if ((short)ax < 0)
goto loc_10c8f;
ax = -ax;
ax += memory16(ss, bp + 4);
if ((short)ax > (short)0x0000)
goto loc_10c8c;
goto loc_10d8f;
loc_10c8c:
memory16(ss, bp + 4) = ax;
loc_10c8f:
ax = 0x0020;
memory16(ss, bp + 10) += ax;
ax = 0x0008;
memory16(ss, bp + 8) += ax;
ax = memory16(ss, bp + 10);
if ((short)ax >= (short)0x0020)
goto loc_10cab;
ax = 0x0020;
memory16(ss, bp + 10) = ax;
goto loc_10cbc;
loc_10cab:
ax += memory16(ss, bp + 6);
if ((short)ax <= (short)0x0120)
goto loc_10cbc;
ax = 0x0120;
ax -= memory16(ss, bp + 6);
memory16(ss, bp + 10) = ax;
loc_10cbc:
push(ds);
push(bx);
dx = 0x03ce;
ax = 0x0a05;
out(dx, ax);
ax = 0x0007;
out(dx, ax);
ax = memory16(ss, bp + 10);
bx = memory16(ss, bp + 8);
push(cx);
bx <<= 1;
bx <<= 1;
bx <<= 1;
cx = memory16(cs, 0x0d93);
if (cx != 0x0028)
goto loc_10ce4;
di = bx;
goto loc_10ce7;
loc_10ce4:
di = 0x0000;
loc_10ce7:
bx <<= 1;
bx <<= 1;
di += bx;
cl = al;
ax >>= 1;
ax >>= 1;
ax >>= 1;
di += ax;
cl &= 0x07;
ax = 0x0080;
ax >>= cl;
ah = al;
bx = memory16(ds, 0x942e);
es = bx;
pop(cx);
cx = memory16(ss, bp + 6);
cx >>= 1;
al = 0x08;
pop(ds);
bx = memory16(ss, bp + 4);
loc_10d13:
push(ax);
push(bx);
push(cx);
push(di);
push(si);
loc_10d18:
bh = memory(cs, 0x0d96);
loc_10d1d:
bl = memory(ds, si);
si++;
si &= 0xffff;
if (bh != bl)
goto loc_10d3a;
ah >>= 1;
if (ah != 0)
goto loc_10d2f;
ah = 0x40;
di++;
if (--cx)
goto loc_10d1d;
goto loc_10d6d;
loc_10d2f:
ah >>= 1;
if (ah != 0)
goto loc_10d36;
ah = 0x80;
di++;
loc_10d36:
if (--cx)
goto loc_10d1d;
goto loc_10d6d;
loc_10d3a:
bh = bl;
bl >>= 1;
bl >>= 1;
bl >>= 1;
bl >>= 1;
if (bl == memory(cs, 0x0d95))
goto loc_10d4f;
out(dx, ax);
memoryVideoAnd(es, di, bl);
loc_10d4f:
ah >>= 1;
if (ah != 0)
goto loc_10d56;
ah = 0x80;
di++;
loc_10d56:
bh &= 0x0f;
if (bh == memory(cs, 0x0d95))
goto loc_10d64;
out(dx, ax);
memoryVideoAnd(es, di, bh);
loc_10d64:
ah >>= 1;
if (ah != 0)
goto loc_10d6b;
ah = 0x80;
di++;
loc_10d6b:
if (--cx)
goto loc_10d18;
loc_10d6d:
pop(si);
si += 0x00a0;
si &= 0xffff;
pop(di);
di += memory16(cs, 0x0d93);
di &= 0x7fff;
pop(cx);
pop(bx);
pop(ax);
bx--;
if (bx != 0)
goto loc_10d13;
pop(ds);
ax = 0xff08;
out(dx, ax);
ax = 0x0005;
out(dx, ax);
ax = 0x0f07;
out(dx, ax);
loc_10d8f:
pop(bp);
sp += 8;
}
// extracting 1000:3801, converted 178, to convert 61, failed 0
void sub_13801()
{
ax = memory16(ss, bp + 8);
ax <<= 1;
ax <<= 1;
ax <<= 1;
ax <<= 1;
ax <<= 1;
di = ax;
ax = memory16(ss, bp + 10);
ax >>= 1;
ax >>= 1;
ax >>= 1;
di += ax;
cx = memory16(ss, bp + 10);
cx &= 0x0007;
al = 0x80;
al >>= cl;
memory(es, di) |= al;
}
// extracting 1000:25e3, converted 179, to convert 48, failed 0
void sub_125e3()
{
push(bp);
bp = sp;
ax = 0xa000;
es = ax;
ax = memory16(ss, bp + 6);
ax >>= 1;
ax >>= 1;
ax >>= 1;
ax += memory16(ss, bp + 4);
di = ax;
dx = 0x03ce;
ax = 0x0805;
out(dx, ax);
cx = memory16(ss, bp + 6);
cx &= 0x0007;
ah = 0x80;
ah >>= cl;
al = 0x08;
out(dx, ax);
bl = ah;
ax = 0x1803;
out(dx, ax);
ax = 0x0f01;
out(dx, ax);
ax = 0x0700;
out(dx, ax);
cx = 0x0007;
loc_1261e:
al = memoryVideoGet(es, di);
if (bl & al)
goto loc_1262d;
memoryVideoSet(es, di, bl);
memoryVideoSet(es, di + 8192, bl);
loc_1262d:
di += 0x0028;
if (--cx)
goto loc_1261e;
ax = 0x0005;
out(dx, ax);
ax = 0xff08;
out(dx, ax);
ax = 0x0003;
out(dx, ax);
ax = 0x0001;
out(dx, ax);
ax = 0x0000;
out(dx, ax);
pop(bp);
sp += 4;
}
// extracting 1000:2536, converted 180, to convert 47, failed 0
void sub_12536()
{
memory16(ds, 0x953a) = ax;
push(ax);
ax = 0x1b88;
push(ax);
sub_125e3();
}
// extracting 1000:257e, converted 181, to convert 46, failed 0
void sub_1257e()
{
memory16(ds, 0x953e) = ax;
push(ax);
ax = 0x1cc8;
push(ax);
sub_125e3();
}
// extracting 1000:25c6, converted 182, to convert 45, failed 0
void sub_125c6()
{
memory16(ds, 0x9542) = ax;
push(ax);
ax = 0x1e08;
push(ax);
sub_125e3();
}
// extracting 1000:2872, converted 183, to convert 29, failed 0
void sub_12872()
{
push(si);
push(di);
al = memory(ds, si);
ah = al;
al <<= 1;
al += ah;
al <<= 1;
ah = 0x00;
ax += 0x94a9;
si = ax;
al = memory(ds, bx);
ah = al;
al <<= 1;
al += ah;
al <<= 1;
ah = 0x00;
ax += 0x94a9;
di = ax;
al = memory(ds, di);
if (al > memory(ds, si))
goto loc_128d5;
if (al < memory(ds, si))
goto loc_128d0;
al = memory(ds, di + 1);
if (al > memory(ds, si + 1))
goto loc_128d5;
if (al < memory(ds, si + 1))
goto loc_128d0;
al = memory(ds, di + 2);
if (al > memory(ds, si + 2))
goto loc_128d5;
if (al < memory(ds, si + 2))
goto loc_128d0;
al = memory(ds, di + 3);
if (al > memory(ds, si + 3))
goto loc_128d5;
if (al < memory(ds, si + 3))
goto loc_128d0;
al = memory(ds, di + 4);
if (al > memory(ds, si + 4))
goto loc_128d5;
if (al < memory(ds, si + 4))
goto loc_128d0;
al = memory(ds, di + 5);
if (al > memory(ds, si + 5))
goto loc_128d5;
if (al < memory(ds, si + 5))
goto loc_128d0;
loc_128d0:
al = 0x00;
pop(di);
pop(si);
return;
loc_128d5:
al = 0x01;
pop(di);
pop(si);
}
// extracting 1000:29ae, converted 184, to convert 28, failed 0
void sub_129ae()
{
push(bp);
bp = sp;
ax = memory16(ds, 0x94f0);
es = ax;
di = memory16(ds, 0x944e);
di += memory16(ss, bp + 4);
ax = memory16(ds, 0x94ea);
push(ds);
ds = ax;
si = memory16(ss, bp + 6);
cx = 0x000b;
loc_129c9:
movsw<MemAuto, MemAuto, DirAuto>();
movsw<MemAuto, MemAuto, DirAuto>();
movsw<MemAuto, MemAuto, DirAuto>();
di += 0x009a;
si += 0x009a;
if (--cx)
goto loc_129c9;
pop(ds);
pop(bp);
sp += 4;
}
// extracting 1000:296f, converted 185, to convert 26, failed 0
void sub_1296f()
{
cx = 0x000c;
dx = 0x0000;
loc_12975:
push(cx);
lodsb<MemAuto, DirAuto>();
push(si);
push(dx);
if (al != 0x20)
goto loc_12982;
ax = 0x6546;
goto loc_129a0;
loc_12982:
if (al != 0x2e)
goto loc_1298b;
ax = 0x6f6c;
goto loc_129a0;
loc_1298b:
if (al != 0x5f)
goto loc_12994;
ax = 0x764c;
goto loc_129a0;
loc_12994:
al -= 0x41;
ah = al;
al <<= 1;
al += ah;
al <<= 1;
ah = 0x00;
loc_129a0:
push(ax);
push(dx);
sub_129ae();
pop(dx);
dx += 0x0006;
pop(si);
pop(cx);
if (--cx)
goto loc_12975;
}
// extracting 1000:23d4, converted 186, to convert 22, failed 0
void sub_123d4()
{
ax = 0x43ee;
push(ax);
ax = 0x1b99;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
}
// extracting 1000:23ec, converted 187, to convert 22, failed 0
void sub_123ec()
{
ax = 0x43ee;
push(ax);
ax = 0x1b9b;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
}
// extracting 1000:2404, converted 188, to convert 22, failed 0
void sub_12404()
{
ax = 0x43ee;
push(ax);
ax = 0x1b9d;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
}
// extracting 1000:241c, converted 189, to convert 22, failed 0
void sub_1241c()
{
ax = 0x43ee;
push(ax);
ax = 0x1b9f;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
}
// extracting 1000:2434, converted 190, to convert 22, failed 0
void sub_12434()
{
ax = 0x43ee;
push(ax);
ax = 0x1ba1;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
}
// extracting 1000:244c, converted 191, to convert 22, failed 0
void sub_1244c()
{
ax = 0x43ee;
push(ax);
ax = 0x1ba3;
push(ax);
ax = 0x0010;
push(ax);
ax = 0x000f;
push(ax);
ax = 0x0002;
push(ax);
sub_12cea();
}
// extracting 1000:2cc7, converted 192, to convert 15, failed 0
void sub_12cc7()
{
bl = al;
bh = 0x00;
bx <<= 1;
ax = memory16(ds, bx + 5407);
push(ax);
ax = memory16(ds, bx + 5423);
push(ax);
ax = memory16(ds, bx + 5439);
push(ax);
ax = memory16(ds, bx + 5455);
push(ax);
ax = memory16(ds, bx + 5391);
push(ax);
sub_12cea();
}

