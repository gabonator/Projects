#include "cico32.h"

void fixReloc(uint16_t seg);
void sub_10010();

void start()
{
    headerSize = 0x0200;
    loadAddress = 0x1000;
    endAddress = 0x1d20;
    cs = 0x1000;
    ds = 0x0ff0;
    es = 0x0ff0;
    ss = 0x1cfc;
    sp = 0x0100;
    load("", "GOOSE.EXE", 53684);
    fixReloc(cs);
    sub_10010();
}

void fixReloc(uint16_t seg)
{
    memoryASet16(seg, 0x0011, memoryAGet16(seg, 0x0011) + seg); // 03a5 -> 13a5
    memoryASet16(seg, 0x04d1, memoryAGet16(seg, 0x04d1) + seg); // 03a5 -> 13a5
    memoryASet16(seg, 0x05d8, memoryAGet16(seg, 0x05d8) + seg); // 03a5 -> 13a5
    memoryASet16(seg, 0x0b59, memoryAGet16(seg, 0x0b59) + seg); // 03a5 -> 13a5
}

void sub_10010();
void sub_100a9();
void sub_100cf();
void sub_100fd();
void sub_10103();
void sub_1019d();
void sub_101ad();
void sub_101c0();
void sub_1033b();
void sub_10442();
void sub_104a5();
void sub_104f3();
void sub_10529();
void sub_10541();
void sub_10588();
void sub_10591();
void sub_105bc();
void sub_105ec();
void sub_10600();
void sub_10637();
void sub_10644();
void sub_1064d();
void sub_10674();
void sub_1069a();
void sub_107af();
void sub_107fd();
void sub_108ba();
void sub_1094a();
void sub_109a4();
void sub_109b5();
void sub_109e9();
void sub_10a1b();
void sub_10a51();
void sub_10ad5();
void sub_10b58();
void sub_10b7c();
void sub_10b8e();
void sub_10bc5();
void sub_10bdc();
void sub_10c24();
void sub_10d98();
void sub_10da7();
void sub_10dc0();
void sub_10e07();
void sub_10e3d();
void sub_10e84();
void sub_10f3c();
void sub_10f9d();
void sub_10fda();
void sub_110a0();
void sub_110c6();
void sub_110f3();
void sub_11108();
void sub_112a7();
void sub_112cb();
void sub_112eb();
void sub_11384();
void sub_113a8();
void sub_11429();
void sub_114f0();
void sub_115fc();
void sub_116d6();
void sub_116df();
void sub_116fe();
void sub_1171f();
void sub_11740();
void sub_1176c();
void sub_11783();
void sub_117ac();
void sub_117d6();
void sub_117f4();
void sub_118a9();
void sub_118c7();
void sub_1196f();
void sub_11993();
void sub_119c2();
void sub_11a04();
void sub_11a9e();
void sub_11b09();
void sub_11b4a();
void sub_11b57();
void sub_11b80();
void sub_11bb9();
void sub_11c0a();
void sub_11c33();
void sub_11c56();
void sub_11c78();
void sub_11cd9();
void sub_11d1e();
void sub_11def();
void sub_11e7d();
void sub_11f0b();
void sub_11fba();
void sub_12005();
void sub_12047();
void sub_12092();
void sub_12099();
void sub_120a0();
void sub_120db();
void sub_120f0();
void sub_12121();
void sub_1215b();
void sub_121dc();
void sub_12200();
void sub_1220d();
void sub_122b1();
void sub_122c1();
void sub_122e1();
void sub_122f9();
void sub_12311();
void sub_12329();
void sub_1237c();
void sub_1239b();
void sub_123d4();
void sub_123ec();
void sub_12404();
void sub_1241c();
void sub_12434();
void sub_1244c();
void sub_12464();
void sub_1250b();
void sub_1252f();
void sub_12536();
void sub_12542();
void sub_12553();
void sub_12577();
void sub_1257e();
void sub_1258a();
void sub_1259b();
void sub_125bf();
void sub_125c6();
void sub_125d2();
void sub_125e3();
void sub_1264a();
void sub_12662();
void sub_12676();
void sub_1268a();
void sub_1269e();
void sub_12714();
void sub_12762();
void sub_1279f();
void sub_12809();
void sub_12872();
void sub_128da();
void sub_12907();
void sub_12959();
void sub_1296f();
void sub_129ae();
void sub_129db();
void sub_12a64();
void sub_12a7f();
void sub_12b28();
void sub_12c07();
void sub_12c45();
void sub_12c9a();
void sub_12cc7();
void sub_12cea();
void sub_12d9a();
void sub_12ddc();
void sub_12df6();
void sub_12e02();
void sub_12f50();
void sub_12fe8();
void sub_1300a();
void sub_13059();
void sub_13084();
void sub_1309d();
void sub_13130();
void sub_1315e();
void sub_13170();
void sub_13181();
void sub_13191();
void sub_131a4();
void sub_131e7();
void sub_13209();
void sub_13291();
void sub_132fe();
void sub_1333c();
void sub_13383();
void sub_133b3();
void sub_133d7();
void sub_133e5();
void sub_13423();
void sub_13439();
void sub_13472();
void sub_13498();
void sub_134a8();
void sub_135bc();
void sub_136d4();
void sub_13801();
void sub_1382a();
void sub_13840();
void sub_13914();
void sub_139a3();
void sub_139b8();

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
    memoryASet16(ds, 0x94e8, ax);
    ax += 0x0800;
    memoryASet16(ds, 0x94ea, ax);
    ax += 0x0800;
    memoryASet16(ds, 0x94ec, ax);
    ax += 0x0800;
    memoryASet16(ds, 0x94ee, ax);
    ax += 0x0800;
    memoryASet16(ds, 0x94f0, ax);
    ax += 0x0800;
    memoryASet16(ds, 0x94f2, ax);
    ax += 0x0800;
    memoryASet16(ds, 0x94f4, ax);
    ax += 0x0800;
    memoryASet16(ds, 0x94f6, ax);
    interrupt(0x12);
    if (ax >= 0x0200)
        goto loc_10067;
    dx = 0x0007;
    ah = 0x09;
    interrupt(0x21);
    ax = 0x4c00;
    interrupt(0x21);
  stop();
  // gap 2 bytes
loc_10067:
    dx = 0x002a;
    ah = 0x09;
    interrupt(0x21);
    sub_10600();
    sub_1333c();
    sub_12762();
    sub_105ec();
    sub_10442();
    sub_10588();
    sub_10591();
    sub_1382a();
    memoryASet(ds, 0x9501, 0x00);
loc_1008b:
    sub_100a9();
    sub_100cf();
    sub_100fd();
    goto loc_1008b;
}
void sub_100a9()
{
    sub_10103();
    memoryASet(ds, 0x9500, 0x00);
    memoryASet(ds, 0x94fe, 0x01);
    memoryASet(ds, 0x94fc, 0x10);
    memoryASet(ds, 0x94ff, 0x00);
    memoryASet(ds, 0x9502, 0x00);
    sub_10da7();
    sub_13423();
    sub_121dc();
}
void sub_100cf()
{
loc_100cf:
    sub_101c0();
    sub_10fda();
    al = memoryAGet(ds, 0x94ff);
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
    al = memoryAGet(ds, 0x9500);
    if (al != 0x00)
        return;
    goto loc_100cf;
loc_100fc:
    return;
}
void sub_100fd()
{
    memoryASet(ds, 0x0006, 0x01);
}
void sub_10103()
{
    al = memoryAGet(ds, 0x0006);
    if (al == 0x00)
        goto loc_10115;
    memoryASet16(ds, 0x8e7e, 0x00da);
    sub_1279f();
    goto loc_1011e;
loc_10115:
    memoryASet16(ds, 0x8e7e, 0x00e9);
    sub_128da();
loc_1011e:
    sub_139b8();
    sub_13472();
    memoryASet(ds, 0x9503, 0x01);
    memoryASet16(ds, 0x8e80, 0x0000);
    sub_10d98();
loc_10132:
    sub_101c0();
    sub_10fda();
    sub_13498();
    sub_10b8e();
    sub_13383();
    ax = memoryAGet16(ds, 0x954c);
    if (ax & 0x0080)
        goto loc_10197;
    memoryASet16(ds, 0x8e80, memoryAGet16(ds, 0x8e80) + 1);
    bx = memoryAGet16(ds, 0x8e80);
    if (bx & 0x0007)
        goto loc_10195;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    bx += memoryAGet16(ds, 0x8e7e);
    al = memoryAGet(ds, bx);
    if (al == 0x00)
        goto loc_10195;
    if (al == 0xff)
        goto loc_10197;
    if (al != 0xfe)
        goto loc_10180;
    al = memoryAGet(ds, 0x9546);
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
    ax = pop();
    al++;
    sub_1019d();
loc_10195:
    goto loc_10132;
loc_10197:
    memoryASet(ds, 0x9503, 0x00);
}
void sub_1019d()
{
    si = 0x0109;
    memoryASet(ds, si + 4, al);
    bx = 0x0120;
    sub_12121();
    sub_10b58();
}
void sub_101ad()
{
    cx = 0x1f40;
loc_101b0:
    push(cx);
    sub_101c0();
    cx = pop();
    ax = memoryAGet16(ds, 0x954c);
    if (!(al & 0x80))
        goto loc_101bd;
    return;
loc_101bd:
    if (--cx)
        goto loc_101b0;
}
void sub_101c0()
{
  goto loc_101c0;
loc_10096:
    sub_139a3();
    sub_105bc();
    sub_104a5();
    ax = 0x0003;
    interrupt(0x10);
    ax = 0x4c00;
    interrupt(0x21);
  stop();
  // gap 279 bytes
loc_101c0:
    bx = 0x8e8a;
    si = 0x003d;
    al = memoryAGet(ds, bx + si);
    if (al == 0x00)
        goto loc_101d5;
    si = 0x003e;
loc_101cf:
    al = memoryAGet(ds, bx + si);
    if (al == 0x00)
        goto loc_101cf;
loc_101d5:
    si = 0x003b;
    al = memoryAGet(ds, bx + si);
    if (al == 0x00)
        goto loc_101e1;
    sub_1033b();
loc_101e1:
    bx = 0x8e8a;
    si = memoryAGet16(ds, 0x8f0d);
    al = memoryAGet(ds, bx + si);
    if (al == 0x00)
        goto loc_101f6;
    memoryASet16(ds, 0x954c, 0x0001);
    goto loc_1020e;
loc_101f6:
    si = memoryAGet16(ds, 0x8f0f);
    al = memoryAGet(ds, bx + si);
    if (al == 0x00)
        goto loc_10208;
    memoryASet16(ds, 0x954c, 0x0002);
    goto loc_1020e;
loc_10208:
    memoryASet16(ds, 0x954c, 0x0000);
loc_1020e:
    si = memoryAGet16(ds, 0x8f11);
    al = memoryAGet(ds, bx + si);
    if (al == 0x00)
        goto loc_1021f;
    memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0004);
    goto loc_1022e;
loc_1021f:
    si = memoryAGet16(ds, 0x8f13);
    al = memoryAGet(ds, bx + si);
    if (al == 0x00)
        goto loc_1022e;
    memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0008);
loc_1022e:
    si = memoryAGet16(ds, 0x8f15);
    al = memoryAGet(ds, bx + si);
    if (al == 0x00)
        goto loc_1023e;
    memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0080);
loc_1023e:
    si = memoryAGet16(ds, 0x8f17);
    al = memoryAGet(ds, bx + si);
    if (al == 0x00)
        goto loc_1024d;
    memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0040);
loc_1024d:
    si = memoryAGet16(ds, 0x8f19);
    al = memoryAGet(ds, bx + si);
    if (al == 0x00)
        goto loc_1025c;
    memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0020);
loc_1025c:
    si = memoryAGet16(ds, 0x8f1b);
    al = memoryAGet(ds, bx + si);
    if (al == 0x00)
        goto loc_1028c;
    sub_12c45();
    bx = 0x8e8a;
loc_1026c:
    al = memoryAGet(ds, bx + 21);
    if (al != 0x00)
        goto loc_1027c;
    al = memoryAGet(ds, bx + 49);
    if (al != 0x00)
        goto loc_1027c;
    goto loc_1026c;
loc_1027c:
    bx = 0x8e8a;
    al = memoryAGet(ds, bx + 21);
    if (al == 0x00)
        goto loc_10289;
    goto loc_10096;
loc_10289:
    sub_10529();
loc_1028c:
    bx = 0x8e8a;
    si = 0x003c;
    al = memoryAGet(ds, bx + si);
    if (al == 0x00)
        goto loc_102c5;
    al = memoryAGet(ds, 0x9505);
    if (al != 0x00)
        goto loc_102b0;
    al = 0x0e;
    sub_13840();
    memoryASet(ds, 0x9505, 0x01);
    memoryASet(ds, 0x9506, 0x00);
    goto loc_102c3;
loc_102b0:
    if (al != 0x02)
        goto loc_102c3;
    memoryASet(ds, 0x9505, 0x03);
    memoryASet(ds, 0x9506, 0x01);
    al = 0x0d;
    sub_13840();
loc_102c3:
    goto loc_102dc;
loc_102c5:
    al = memoryAGet(ds, 0x9505);
    if (al != 0x01)
        goto loc_102d3;
    memoryASet(ds, 0x9505, 0x02);
    goto loc_102dc;
loc_102d3:
    if (al != 0x03)
        goto loc_102dc;
    memoryASet(ds, 0x9505, 0x00);
loc_102dc:
    al = memoryAGet(ds, 0x8f0a);
    if (al != 0x00)
        goto loc_102e4;
    return;
loc_102e4:
    ax = 0x0003;
    interrupt(0x33);
    if (!(bx & 0x0001))
        goto loc_102f5;
    memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0080);
loc_102f5:
    if (!(bx & 0x0002))
        goto loc_10300;
    memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0020);
loc_10300:
    ax = memoryAGet16(ds, 0x954c);
    ax &= 0x000f;
    if (!ax)
        goto loc_10309;
    return;
loc_10309:
    ax = 0x000b;
    interrupt(0x33);
    if ((short)cx >= (short)0xfffb)
        goto loc_1031a;
    memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0001);
    goto loc_10324;
loc_1031a:
    if ((short)cx <= (short)0x0005)
        goto loc_10324;
    memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0002);
loc_10324:
    if ((short)dx >= (short)0xfff6)
        goto loc_10330;
    memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0004);
    return;
loc_10330:
    if ((short)dx <= (short)0x000a)
        return;
    memoryASet16(ds, 0x954c, memoryAGet16(ds, 0x954c) | 0x0008);
loc_1033a:
    return;
}
void sub_1033b()
{
    sub_12c07();
    al = 0x04;
    sub_12c9a();
    sub_104f3();
    memoryASet16(ds, 0x8f15, ax);
    al = 0x00;
    sub_12c9a();
loc_1034e:
    sub_104f3();
    if (ax == memoryAGet16(ds, 0x8f15))
        goto loc_1034e;
    memoryASet16(ds, 0x8f0d, ax);
    al = 0x01;
    sub_12c9a();
loc_1035f:
    sub_104f3();
    if (ax == memoryAGet16(ds, 0x8f15))
        goto loc_1035f;
    if (ax == memoryAGet16(ds, 0x8f0d))
        goto loc_1035f;
    memoryASet16(ds, 0x8f0f, ax);
    al = 0x02;
    sub_12c9a();
loc_10376:
    sub_104f3();
    if (ax == memoryAGet16(ds, 0x8f15))
        goto loc_10376;
    if (ax == memoryAGet16(ds, 0x8f0d))
        goto loc_10376;
    if (ax == memoryAGet16(ds, 0x8f0f))
        goto loc_10376;
    memoryASet16(ds, 0x8f11, ax);
    al = 0x03;
    sub_12c9a();
loc_10393:
    sub_104f3();
    if (ax == memoryAGet16(ds, 0x8f15))
        goto loc_10393;
    if (ax == memoryAGet16(ds, 0x8f0d))
        goto loc_10393;
    if (ax == memoryAGet16(ds, 0x8f0f))
        goto loc_10393;
    if (ax == memoryAGet16(ds, 0x8f11))
        goto loc_10393;
    memoryASet16(ds, 0x8f13, ax);
    al = 0x06;
    sub_12c9a();
loc_103b6:
    sub_104f3();
    if (ax == memoryAGet16(ds, 0x8f15))
        goto loc_103b6;
    if (ax == memoryAGet16(ds, 0x8f0d))
        goto loc_103b6;
    if (ax == memoryAGet16(ds, 0x8f0f))
        goto loc_103b6;
    if (ax == memoryAGet16(ds, 0x8f11))
        goto loc_103b6;
    if (ax == memoryAGet16(ds, 0x8f13))
        goto loc_103b6;
    memoryASet16(ds, 0x8f17, ax);
    al = 0x07;
    sub_12c9a();
loc_103df:
    sub_104f3();
    if (ax == memoryAGet16(ds, 0x8f15))
        goto loc_103df;
    if (ax == memoryAGet16(ds, 0x8f0d))
        goto loc_103df;
    if (ax == memoryAGet16(ds, 0x8f0f))
        goto loc_103df;
    if (ax == memoryAGet16(ds, 0x8f11))
        goto loc_103df;
    if (ax == memoryAGet16(ds, 0x8f13))
        goto loc_103df;
    if (ax == memoryAGet16(ds, 0x8f17))
        goto loc_103df;
    memoryASet16(ds, 0x8f19, ax);
    al = 0x05;
    sub_12c9a();
loc_1040e:
    sub_104f3();
    if (ax == memoryAGet16(ds, 0x8f15))
        goto loc_1040e;
    if (ax == memoryAGet16(ds, 0x8f0d))
        goto loc_1040e;
    if (ax == memoryAGet16(ds, 0x8f0f))
        goto loc_1040e;
    if (ax == memoryAGet16(ds, 0x8f11))
        goto loc_1040e;
    if (ax == memoryAGet16(ds, 0x8f13))
        goto loc_1040e;
    if (ax == memoryAGet16(ds, 0x8f17))
        goto loc_1040e;
    if (ax == memoryAGet16(ds, 0x8f19))
        goto loc_1040e;
    memoryASet16(ds, 0x8f1b, ax);
    sub_10529();
}
void sub_10442()
{
    memoryASet16(ds, 0x8f0b, 0x0000);
    memoryASet16(ds, 0x8f0d, 0x004b);
    memoryASet16(ds, 0x8f0f, 0x004d);
    memoryASet16(ds, 0x8f11, 0x0048);
    memoryASet16(ds, 0x8f13, 0x0050);
    memoryASet16(ds, 0x8f15, 0x0039);
    memoryASet16(ds, 0x8f17, 0x0031);
    memoryASet16(ds, 0x8f19, 0x0032);
    memoryASet16(ds, 0x8f1b, 0x0010);
    ax = ds;
    es = ax;
    ax = 0x0000;
    cx = 0x0040;
    di = 0x8e8a;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    al = 0x09;
    ah = 0x35;
    interrupt(0x21);
    memoryASet16(ds, 0x8e84, bx);
    memoryASet16(ds, 0x8e82, es);
    push(ds);
    dx = 0x04b7;
    ax = cs;
    ds = ax;
    al = 0x09;
    ah = 0x25;
    interrupt(0x21);
    ds = pop();
}
void sub_104a5()
{
    dx = memoryAGet16(ds, 0x8e84);
    ax = memoryAGet16(ds, 0x8e82);
    push(ds);
    ds = ax;
    al = 0x09;
    ah = 0x25;
    interrupt(0x21);
    ds = pop();
}
void sub_104f3()
{
    flags.direction = 0;
loc_104f4:
    si = 0x8e8a;
loc_104f7:
    al = lodsb<DS_SI>();
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
void sub_10529()
{
loc_10529:
    si = 0x8e8a;
    ah = 0x00;
loc_1052e:
    al = lodsb<DS_SI>();
    if (al == 0x00)
        goto loc_10535;
    ah++;
loc_10535:
    if (si != 0x8f0a)
        goto loc_1052e;
    if (ah != 0x00)
        goto loc_10529;
}
void sub_10588()
{
    ax = 0x0000;
    interrupt(0x33);
    memoryASet(ds, 0x8f0a, al);
}
void sub_10591()
{
    al = 0x1c;
    ah = 0x35;
    interrupt(0x21);
    memoryASet16(ds, 0x8e88, bx);
    memoryASet16(ds, 0x8e86, es);
    push(ds);
    dx = 0x05ce;
    ax = cs;
    ds = ax;
    al = 0x1c;
    ah = 0x25;
    interrupt(0x21);
    ds = pop();
    al = 0x36;
    out8(0x43, al);
    ax = 0x4d0e;
    out8(0x40, al);
    al = ah;
    out8(0x40, al);
}
void sub_105bc()
{
    dx = memoryAGet16(ds, 0x8e88);
    ax = memoryAGet16(ds, 0x8e86);
    push(ds);
    ds = ax;
    al = 0x1c;
    ah = 0x25;
    interrupt(0x21);
    ds = pop();
}
void sub_105ec()
{
    push(ds);
    dx = 0x05fc;
    ax = cs;
    ds = ax;
    al = 0x24;
    ah = 0x25;
    interrupt(0x21);
    ds = pop();
}
void sub_10600()
{
    dx = 0x01e2;
    ax = memoryAGet16(ds, 0x94e8);
    sub_10637();
    dx = 0x01ea;
    ax = memoryAGet16(ds, 0x94ea);
    sub_10637();
    dx = 0x01f2;
    ax = memoryAGet16(ds, 0x94ec);
    sub_10637();
    dx = 0x01f9;
    ax = memoryAGet16(ds, 0x94ee);
    sub_10637();
    dx = 0x0203;
    ax = memoryAGet16(ds, 0x94f0);
    sub_10637();
    dx = 0x020b;
    ax = memoryAGet16(ds, 0x94f2);
    sub_10637();
}
void sub_10637()
{
    memoryASet16(ds, 0x8f20, ax);
    di = 0x0000;
    cx = 0x7d00;
    sub_1064d();
}
void sub_1064d()
{
    push(di);
    push(cx);
    ax = 0x3d00;
    interrupt(0x21);
    cx = pop();
    dx = pop();
    if (!flags.carry)
        goto loc_10659;
    return;
loc_10659:
    memoryASet16(ds, 0x8f1e, ax);
    bx = ax;
    ax = memoryAGet16(ds, 0x8f20);
    push(ds);
    ds = ax;
    ax = 0x3f00;
    interrupt(0x21);
    ds = pop();
    ax = 0x3e00;
    bx = memoryAGet16(ds, 0x8f1e);
    interrupt(0x21);
}
void sub_10b58()
{
    ax = 0x13a5;
    es = ax;
    di = 0x1b8a;
loc_10b60:
    al = memoryAGet(ds, di);
    if (al & 0x80)
        goto loc_10b78;
    if (al & 0x01)
        goto loc_10b73;
    push(di);
    cx = 0x0017;
    flags.direction = 0;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = pop();
    return;
loc_10b73:
    di += 0x0017;
    goto loc_10b60;
loc_10b78:
    si = 0x0000;
}
void sub_10b8e()
{
    ax = memoryAGet16(ds, 0x94f8);
    memoryASet16(ds, 0x942e, ax);
    memoryASet16(cs, 0x0d93, 0x0028);
    memoryASet16(ds, 0x9430, 0x0001);
    cx = 0x0007;
loc_10ba4:
    si = 0x1b8a;
loc_10ba7:
    al = memoryAGet(ds, si);
    if (al & 0x80)
        goto loc_10bc2;
    if (!(al & 0x01))
        goto loc_10bbd;
    if (cl != memoryAGet(ds, si + 2))
        goto loc_10bbd;
    push(cx);
    push(si);
    sub_10bdc();
    si = pop();
    cx = pop();
loc_10bbd:
    si += 0x0017;
    goto loc_10ba7;
loc_10bc2:
    if (--cx)
        goto loc_10ba4;
}
void sub_10bdc()
{
    al = memoryAGet(ds, si + 11);
    true ? cbw() : cwde();
    bx = memoryAGet16(ds, si + 5);
    bx -= ax;
    push(bx);
    al = memoryAGet(ds, si + 3);
    al += memoryAGet(ds, si + 12);
    true ? cbw() : cwde();
    ax = -ax;
    ax += memoryAGet16(ds, si + 7);
    push(ax);
    al = memoryAGet(ds, si + 9);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ds, si + 10);
    ah = 0x00;
    push(ax);
    bx = memoryAGet16(ds, si + 13);
    bx = memoryAGet16(ds, bx + 38120);
    al = memoryAGet(ds, si + 17);
    memoryASet(cs, 0x0d95, al);
    cl = al;
    cl <<= 1;
    cl <<= 1;
    cl <<= 1;
    cl <<= 1;
    al |= cl;
    memoryASet(cs, 0x0d96, al);
    si = memoryAGet16(ds, si + 15);
    sub_10c24();
}
void sub_10c24()
{
    push(bp);
    bp = sp;
    ax = memoryAGet16(ds, 0x9430);
    if (ax != 0x0000)
        goto loc_10c32;
    goto loc_10cbc;
loc_10c32:
    ax = memoryAGet16(ss, bp + 8 - 2);
    ax -= memoryAGet16(ds, 0x9528);
    ax &= 0x03ff;
    if (!(ax & 0x0200))
        goto loc_10c44;
    ax |= 0xfc00;
loc_10c44:
    memoryASet16(ss, bp + 8 - 2, ax);
    if ((short)ax >= (short)0x0000)
        goto loc_10c77;
    memoryASet16(ss, bp + 4 - 2, memoryAGet16(ss, bp + 4 - 2) + ax);
    if ((short)memoryAGet16(ss, bp + 4 - 2) >= 0)
        goto loc_10c54;
    goto loc_10d8f;
loc_10c54:
    if (memoryAGet16(ss, bp + 4 - 2))
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
    memoryASet16(ss, bp + 8 - 2, ax);
    goto loc_10c8f;
loc_10c77:
    ax += memoryAGet16(ss, bp + 4 - 2);
    ax -= 0x00a0;
    if ((short)ax < 0)
        goto loc_10c8f;
    ax = -ax;
    ax += memoryAGet16(ss, bp + 4 - 2);
    if ((short)ax > (short)0x0000)
        goto loc_10c8c;
    goto loc_10d8f;
loc_10c8c:
    memoryASet16(ss, bp + 4 - 2, ax);
loc_10c8f:
    ax = 0x0020;
    memoryASet16(ss, bp + 10 - 2, memoryAGet16(ss, bp + 10 - 2) + ax);
    ax = 0x0008;
    memoryASet16(ss, bp + 8 - 2, memoryAGet16(ss, bp + 8 - 2) + ax);
    ax = memoryAGet16(ss, bp + 10 - 2);
    if ((short)ax >= (short)0x0020)
        goto loc_10cab;
    ax = 0x0020;
    memoryASet16(ss, bp + 10 - 2, ax);
    goto loc_10cbc;
loc_10cab:
    ax += memoryAGet16(ss, bp + 6 - 2);
    if ((short)ax <= (short)0x0120)
        goto loc_10cbc;
    ax = 0x0120;
    ax -= memoryAGet16(ss, bp + 6 - 2);
    memoryASet16(ss, bp + 10 - 2, ax);
loc_10cbc:
    push(ds);
    push(bx);
    dx = 0x03ce;
    ax = 0x0a05;
    out16(dx, ax);
    ax = 0x0007;
    out16(dx, ax);
    ax = memoryAGet16(ss, bp + 10 - 2);
    bx = memoryAGet16(ss, bp + 8 - 2);
    push(cx);
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    cx = memoryAGet16(cs, 0x0d93);
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
    bx = memoryAGet16(ds, 0x942e);
    es = bx;
    cx = pop();
    cx = memoryAGet16(ss, bp + 6 - 2);
    cx >>= 1;
    al = 0x08;
    ds = pop();
    bx = memoryAGet16(ss, bp + 4 - 2);
loc_10d13:
    push(ax);
    push(bx);
    push(cx);
    push(di);
    push(si);
loc_10d18:
    bh = memoryAGet(cs, 0x0d96);
loc_10d1d:
    bl = memoryAGet(ds, si);
    si++;
    if (bh != bl)
        goto loc_10d3a;
    ah >>= 1;
    if (ah)
        goto loc_10d2f;
    ah = 0x40;
    di++;
    if (--cx)
        goto loc_10d1d;
    goto loc_10d6d;
loc_10d2f:
    ah >>= 1;
    if (ah)
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
    if (bl == memoryAGet(cs, 0x0d95))
        goto loc_10d4f;
    out16(dx, ax);
    memoryASet(es, di, memoryAGet(es, di) & bl);
loc_10d4f:
    ah >>= 1;
    if (ah)
        goto loc_10d56;
    ah = 0x80;
    di++;
loc_10d56:
    bh &= 0x0f;
    if (bh == memoryAGet(cs, 0x0d95))
        goto loc_10d64;
    out16(dx, ax);
    memoryASet(es, di, memoryAGet(es, di) & bh);
loc_10d64:
    ah >>= 1;
    if (ah)
        goto loc_10d6b;
    ah = 0x80;
    di++;
loc_10d6b:
    if (--cx)
        goto loc_10d18;
loc_10d6d:
    si = pop();
    si += 0x00a0;
    di = pop();
    di += memoryAGet16(cs, 0x0d93);
    di &= 0x7fff;
    cx = pop();
    bx = pop();
    ax = pop();
    bx--;
    if (bx)
        goto loc_10d13;
    ds = pop();
    ax = 0xff08;
    out16(dx, ax);
    ax = 0x0005;
    out16(dx, ax);
    ax = 0x0f07;
    out16(dx, ax);
loc_10d8f:
    bp = pop();
    sp += 8;
}
void sub_10d98()
{
    memoryASet16(ds, 0x9528, 0x001a);
    memoryASet(ds, 0x9513, 0x00);
    sub_10b7c();
}
void sub_10b7c()
{
    si = 0x1b8a;
loc_10b7f:
    al = memoryAGet(ds, si);
    if (al & 0x80)
        return;
    memoryASet(ds, si, 0x00);
    si += 0x0017;
    goto loc_10b7f;
loc_10b8d:
    return;
}
void sub_10da7()
{
    sub_109a4();
    sub_1069a();
    memoryASet(ds, 0x9519, 0x00);
    memoryASet(ds, 0x951a, 0x00);
    memoryASet(ds, 0x951b, 0x00);
    sub_10e3d();
}
void sub_1069a()
{
    al = memoryAGet(ds, 0x9501);
    bl = al;
    bl <<= 1;
    bl += al;
    bl += memoryAGet(ds, 0x9502);
    bh = 0x00;
    bx <<= 1;
    si = memoryAGet16(ds, bx + 580);
    di = 0x9229;
    cx = 0x0040;
    ax = ds;
    es = ax;
    ax = 0x0000;
    flags.direction = 0;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    di = 0x9229;
loc_106c2:
    al = lodsb<DS_SI>();
    if (al == 0xff)
        goto loc_106eb;
    al <<= 1;
    al <<= 1;
    ah = al;
    al = lodsb<DS_SI>();
    al <<= 1;
    bl = al;
    bh = 0x00;
    al = 0x00;
    ax |= memoryAGet16(ds, bx + 3287);
    cx = ax;
    al = lodsb<DS_SI>();
    al = -al;
    al += 0x3f;
    al <<= 1;
    bl = al;
    memoryASet16(ds, bx + 37417, memoryAGet16(ds, bx + 37417) | cx);
    goto loc_106c2;
loc_106eb:
    al = memoryAGet(ds, 0x9501);
    bl = al;
    bl <<= 1;
    bl += al;
    bl += memoryAGet(ds, 0x9502);
    bh = 0x00;
    bx <<= 1;
    si = memoryAGet16(ds, bx + 532);
    di = 0x8f29;
    cx = 0x0300;
    bl = 0x00;
loc_10708:
    bl--;
    if ((char)bl >= 0)
        goto loc_1072c;
    al = lodsb<DS_SI>();
    dl = al;
    dl &= 0x3f;
    al &= 0xc0;
    if (al)
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
    memoryASet(ds, di, dl);
    di++;
    if (--cx)
        goto loc_10708;
    di = 0x0000;
    ax = 0xa800;
    es = ax;
    dx = 0x03ce;
    ah = 0x00;
    al = 0x00;
    out16(dx, ax);
    ax = 0x0f01;
    out16(dx, ax);
    cx = 0x4000;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    ax = 0x8f29;
    memoryASet16(ds, 0x8f25, ax);
    memoryASet16(ds, 0x8f23, 0x03f0);
    cx = 0x0040;
loc_10759:
    push(cx);
    memoryASet(ds, 0x8f22, 0x00);
    sub_107af();
    memoryASet16(ds, 0x0279, 0x0000);
    memoryASet(ds, 0x027d, 0x08);
    memoryASet16(ds, 0x0283, memoryAGet16(ds, 0x0283) + 0x0008);
    si = 0x0274;
    sub_10bc5();
    memoryASet16(ds, 0x0279, 0x0008);
    memoryASet(ds, 0x027d, 0x18);
    cx = 0x000a;
loc_10786:
    push(cx);
    sub_107af();
    si = 0x0274;
    sub_10bc5();
    memoryASet16(ds, 0x0279, memoryAGet16(ds, 0x0279) + 0x0018);
    cx = pop();
    if (--cx)
        goto loc_10786;
    memoryASet(ds, 0x027d, 0x08);
    sub_107af();
    si = 0x0274;
    sub_10bc5();
    memoryASet16(ds, 0x8f23, memoryAGet16(ds, 0x8f23) - 0x0010);
    cx = pop();
    if (--cx)
        goto loc_10759;
}
void sub_107af()
{
    al = memoryAGet(ds, 0x8f22);
    memoryASet(ds, 0x0277, al);
    bx = memoryAGet16(ds, 0x8f25);
    al = memoryAGet(ds, bx);
    bx++;
    memoryASet16(ds, 0x8f25, bx);
    bh = 0x00;
    bl = al;
    al = memoryAGet(ds, bx + 1309);
    memoryASet(ds, 0x027e, al);
    al = memoryAGet(ds, bx + 1393);
    memoryASet(ds, 0x8f22, memoryAGet(ds, 0x8f22) + al);
    al = memoryAGet(ds, bx + 1351);
    true ? cbw() : cwde();
    ax += memoryAGet16(ds, 0x8f23);
    memoryASet16(ds, 0x027b, ax);
    if (bx < 0x0026)
        goto loc_107ec;
    memoryASet16(ds, 0x0281, 0x0002);
    goto loc_107f2;
loc_107ec:
    memoryASet16(ds, 0x0281, 0x0004);
loc_107f2:
    bx <<= 1;
    bx = memoryAGet16(ds, bx + 1519);
    memoryASet16(ds, 0x0283, bx);
}
void sub_109a4()
{
    di = 0x92a9;
    cx = 0x00c0;
    ax = ds;
    es = ax;
    ax = 0xffff;
    flags.direction = 0;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
}
void sub_10bc5()
{
    ax = 0xa800;
    memoryASet16(ds, 0x942e, ax);
    memoryASet16(cs, 0x0d93, 0x0020);
    memoryASet16(ds, 0x9430, 0x0000);
    sub_10bdc();
}
void sub_10e3d()
{
    bl = memoryAGet(ds, 0x9501);
    bh = 0x00;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 5365);
    ax &= 0x03ff;
    memoryASet16(ds, 0x9528, ax);
    ax = memoryAGet16(ds, 0x94fc);
    memoryASet16(ds, 0x952a, ax);
    memoryASet16(ds, 0x950a, 0x0080);
    memoryASet(ds, 0x950e, 0x00);
    memoryASet16(ds, 0x950f, 0x0000);
    memoryASet16(ds, 0x9511, 0x0000);
    memoryASet(ds, 0x9513, 0x00);
    memoryASet(ds, 0x9515, 0x00);
    memoryASet(ds, 0x9517, 0x00);
    memoryASet(ds, 0x9432, 0x00);
    sub_10e84();
}
void sub_10e84()
{
    al = memoryAGet(ds, 0x950e);
    if (al == 0x00)
        goto loc_10e93;
    memoryASet(ds, 0x950e, 0x00);
    sub_1069a();
loc_10e93:
    memoryASet16(ds, 0x952c, 0x0000);
    sub_10b7c();
    si = 0x0d32;
    sub_10b58();
    ax = memoryAGet16(ds, 0x950a);
    memoryASet16(ds, 0x1b8f, ax);
    sub_11b57();
    ax = memoryAGet16(ds, 0x9528);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax -= 0x0003;
    ax &= 0x003f;
    memoryASet16(ds, 0x9507, ax);
    cx = 0x000f;
loc_10ec2:
    push(cx);
    push(ax);
    push(ax);
    sub_108ba();
    ax = pop();
    cx = pop();
    ax++;
    ax &= 0x003f;
    if (--cx)
        goto loc_10ec2;
    al = memoryAGet(ds, 0x9432);
    if (al == 0x00)
        goto loc_10eea;
    si = 0x1b8a;
    bx = 0x0d49;
    memoryASet(ds, si + 4, 0x0a);
    sub_12121();
    memoryASet(ds, 0x1b9c, 0x23);
    return;
loc_10eea:
    al = memoryAGet(ds, 0x9519);
    if (al == 0x00)
        goto loc_10f08;
    memoryASet(ds, 0x9519, 0x00);
    si = 0x0da2;
    ax = memoryAGet16(ds, 0x1b91);
    memoryASet16(ds, si + 7, ax);
    al = memoryAGet(ds, 0x1b8d);
    memoryASet(ds, si + 3, al);
    sub_10b58();
loc_10f08:
    sub_10f9d();
    al = memoryAGet(ds, 0x951a);
    if (al == 0x00)
        goto loc_10f23;
    memoryASet(ds, 0x951a, 0x01);
    si = 0x0dc3;
    memoryASet(ds, si, memoryAGet(ds, si) & 0xdf);
    sub_11cd9();
    sub_10b58();
loc_10f23:
    al = memoryAGet(ds, 0x951b);
    if (al == 0x00)
        return;
    memoryASet(ds, 0x951b, 0x01);
    si = 0x0dc3;
    memoryASet(ds, si, memoryAGet(ds, si) | 0x20);
    sub_11cd9();
    sub_10b58();
loc_10f3b:
    return;
}
void sub_108ba()
{
  bool temp_cf;

    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 4 - 2);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 37417);
    if (ax == 0x0000)
        goto loc_10946;
    push(ax);
    ah >>= 1;
    ah >>= 1;
    bl = ah;
    bh = 0x00;
    bx <<= 1;
    si = memoryAGet16(ds, bx + 651);
    if (ah < 0x0f)
        goto loc_10902;
    if (ah > 0x14)
        goto loc_10902;
    ah -= 0x0f;
    memoryASet(ds, si + 1, ah);
    bl = ah;
    bh = 0x00;
    al = memoryAGet(ds, bx + 38190);
    if (al == 0x00)
        goto loc_108f9;
    ax = pop();
    goto loc_10946;
loc_108f9:
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 814);
    memoryASet16(ds, si + 15, ax);
loc_10902:
    memoryASet(ds, si + 19, 0x0a);
    ax = memoryAGet16(ss, bp + 4 - 2);
    memoryASet(ds, si + 20, al);
    ax = pop();
    cx = 0x000a;
loc_10910:
    temp_cf = ax & 1;
    if (!temp_cf)
        goto loc_10941;
    push(ax);
    push(cx);
    sub_1094a();
    al = memoryAGet(ds, si + 19);
    ah = 0x00;
    push(ax);
    ax = memoryAGet16(ss, bp + 4 - 2);
    push(ax);
    sub_109e9();
    if (ax == 0x0000)
        goto loc_10932;
    push(si);
    sub_10b58();
    si = pop();
    goto loc_1093f;
loc_10932:
    push(si);
    sub_10b58();
    if (si == 0x0000)
        goto loc_1093e;
    sub_10a1b();
loc_1093e:
    si = pop();
loc_1093f:
    cx = pop();
    ax = pop();
loc_10941:
    memoryASet(ds, si + 19, memoryAGet(ds, si + 19) - 1);
    if (--cx)
        goto loc_10910;
loc_10946:
    bp = pop();
    sp += 2;
}
void sub_1094a()
{
    dl = memoryAGet(ds, si + 19);
    push(si);
    al = 0x3f;
    al -= memoryAGet(ds, si + 20);
    al <<= 1;
    al <<= 1;
    ah = 0x00;
    si = ax;
    ax <<= 1;
    si += ax;
    si += 0x8f29;
    cl = 0x00;
    flags.direction = 0;
loc_10966:
    if (dl == 0x00)
        goto loc_10978;
    al = lodsb<DS_SI>();
    bh = 0x00;
    bl = al;
    cl += memoryAGet(ds, bx + 1393);
    dl--;
    goto loc_10966;
loc_10978:
    si = pop();
    memoryASet(ds, si + 3, cl);
    al = memoryAGet(ds, si + 20);
    ah = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    memoryASet16(ds, si + 7, ax);
    al = memoryAGet(ds, si + 19);
    ah = 0x00;
    ax <<= 1;
    cx = ax;
    ax <<= 1;
    ax += cx;
    ax <<= 1;
    ax <<= 1;
    ax -= 0x0004;
    memoryASet16(ds, si + 5, ax);
}
void sub_109e9()
{
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 6 - 2);
    bx <<= 1;
    cx = memoryAGet16(ds, bx + 3307);
    bx = memoryAGet16(ss, bp + 4 - 2);
    bx <<= 1;
    al = memoryAGet(ds, 0x9502);
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
    ax = memoryAGet16(ds, bx + 37545);
    ax &= cx;
    bp = pop();
    sp += 4;
}
void sub_10a1b()
{
    al = memoryAGet(ds, si + 18);
    al <<= 1;
    bl = al;
    bh = 0x00;
    di = memoryAGet16(ds, bx + 798);
    al = memoryAGet(ds, di);
    memoryASet(ds, si, al);
    al = memoryAGet(ds, di + 9);
    memoryASet(ds, si + 9, al);
    al = memoryAGet(ds, di + 10);
    memoryASet(ds, si + 10, al);
    al = memoryAGet(ds, di + 11);
    memoryASet(ds, si + 11, al);
    al = memoryAGet(ds, di + 12);
    memoryASet(ds, si + 12, al);
    ax = memoryAGet16(ds, di + 15);
    memoryASet16(ds, si + 15, ax);
    al = memoryAGet(ds, di + 18);
    memoryASet(ds, si + 18, al);
}
void sub_10f9d()
{
    ax = memoryAGet16(ds, 0x1b8f);
    memoryASet16(ds, 0x9433, ax);
    memoryASet16(ds, 0x9435, ax);
    memoryASet16(ds, 0x9437, ax);
    memoryASet16(ds, 0x9439, ax);
    ax = memoryAGet16(ds, 0x1b91);
    memoryASet16(ds, 0x943b, ax);
    memoryASet16(ds, 0x943d, ax);
    memoryASet16(ds, 0x943f, ax);
    memoryASet16(ds, 0x9441, ax);
    al = memoryAGet(ds, 0x1b8e);
    memoryASet(ds, 0x9443, al);
    memoryASet(ds, 0x9444, al);
    memoryASet(ds, 0x9445, al);
    memoryASet(ds, 0x9446, al);
    al = memoryAGet(ds, 0x1b8d);
    memoryASet(ds, 0x9447, al);
    memoryASet(ds, 0x9448, al);
    memoryASet(ds, 0x9449, al);
    memoryASet(ds, 0x944a, al);
}
void sub_10fda()
{
loc_10fda:
    al = memoryAGet(ds, 0x94ff);
    memoryASet(ds, 0x9509, al);
    si = 0x1b8a;
loc_10fe3:
    al = memoryAGet(ds, 0x9513);
    if (al == 0x00)
        goto loc_10ff5;
    sub_10e07();
    al = memoryAGet(ds, 0x9500);
    if (al == 0x00)
        goto loc_10fda;
    return;
loc_10ff5:
    al = memoryAGet(ds, 0x94ff);
    if (al == memoryAGet(ds, 0x9509))
        goto loc_11036;
    if (al != 0x01)
        goto loc_1100e;
    al = 0x0b;
    sub_13840();
    sub_10f3c();
    goto loc_10fda;
  // gap 2 bytes
loc_1100e:
    al = 0x0b;
    sub_13840();
    al = memoryAGet(ds, 0x951d);
    if (al != 0xf0)
        goto loc_1101f;
    sub_10dc0();
    goto loc_11034;
loc_1101f:
    al = memoryAGet(ds, 0x1ba0);
    al &= 0x7f;
    if (al <= 0x28)
        goto loc_11031;
    if (al >= 0x58)
        goto loc_11031;
    memoryASet(ds, 0x9432, 0x01);
loc_11031:
    sub_10e84();
loc_11034:
    goto loc_10fda;
loc_11036:
    al = memoryAGet(ds, si);
    if (al & 0x80)
        return;
    if (!(al & 0x02))
        goto loc_11054;
    push(si);
    bl = memoryAGet(ds, si + 18);
    if (bl == 0x00)
        goto loc_11053;
    bh = 0x00;
    bx--;
    bx <<= 1;
  switch (bx)
  {
    case 0: sub_11108(); break;
    case 2: sub_1176c(); break;
    case 4: sub_11783(); break;
    case 6: sub_110c6(); break;
    case 8: sub_117ac(); break;
    case 10: sub_117d6(); break;
    case 12: sub_118a9(); break;
    case 14: sub_11a9e(); break;
    case 16: sub_110c6(); break;
    case 18: sub_11993(); break;
    case 20: sub_119c2(); break;
    case 22: sub_12e02(); break;
    case 24: sub_110c6(); break;
    case 26: sub_12fe8(); break;
    case 28: sub_1300a(); break;
    case 30: sub_116fe(); break;
    case 32: sub_112cb(); break;
    case 34: sub_110c6(); break;
    case 36: sub_112eb(); break;
    case 38: sub_115fc(); break;
    case 40: sub_116df(); break;
    case 42: sub_116d6(); break;
    case 44: sub_11740(); break;
    case 46: sub_11384(); break;
    case 48: sub_113a8(); break;
    case 50: sub_114f0(); break;
    case 52: sub_110f3(); break;
    case 54: sub_118c7(); break;
    case 56: sub_11429(); break;
    case 58: sub_117f4(); break;
    case 60: sub_1171f(); break;
    case 62: sub_11b09(); break;
    case 64: sub_11b4a(); break;
    case 66: sub_12f50(); break;
    case 68: sub_112a7(); break;
    default:
      stop();
  }
loc_11053:
    si = pop();
loc_11054:
    si += 0x0017;
    goto loc_10fe3;
loc_11059:
    return;
}
void sub_10dc0()
{
    memoryASet(ds, 0x94fe, memoryAGet(ds, 0x94fe) + 1);
    al = memoryAGet(ds, 0x94fe);
    if (al < 0x06)
        goto loc_10dd3;
    memoryASet16(ds, 0x94fc, 0x0030);
    goto loc_10de5;
loc_10dd3:
    if (al < 0x03)
        goto loc_10ddf;
    memoryASet16(ds, 0x94fc, 0x0020);
    goto loc_10de5;
loc_10ddf:
    memoryASet16(ds, 0x94fc, 0x0010);
loc_10de5:
    memoryASet(ds, 0x9501, memoryAGet(ds, 0x9501) + 1);
    al = memoryAGet(ds, 0x9501);
    if (al <= 0x07)
        goto loc_10df5;
    memoryASet(ds, 0x9501, 0x01);
loc_10df5:
    sub_109a4();
    sub_1069a();
    memoryASet(ds, 0x9519, 0x00);
    sub_10e3d();
    sub_12a7f();
}
void sub_10e07()
{
    ax = memoryAGet16(ds, 0x9534);
    if (ax != 0x0000)
        goto loc_10e15;
    memoryASet(ds, 0x9500, 0x01);
    return;
loc_10e15:
    sub_12329();
    al = memoryAGet(ds, 0x9502);
    if (al == 0x00)
        goto loc_10e27;
    memoryASet(ds, 0x9502, 0x00);
    sub_1069a();
loc_10e27:
    sub_12200();
    memoryASet(ds, 0x9519, 0x01);
    memoryASet(ds, 0x951a, 0x00);
    memoryASet(ds, 0x951b, 0x00);
    sub_10e3d();
}
void sub_10f3c()
{
    memoryASet(ds, 0x951c, 0x00);
    sub_12ddc();
    memoryASet16(ds, 0x9528, 0x001a);
    memoryASet16(ds, 0x9547, 0x0000);
    memoryASet16(ds, 0x951e, 0x0000);
    memoryASet(ds, 0x9524, 0x00);
    memoryASet(ds, 0x9549, 0x03);
    sub_10b7c();
    si = 0x0d04;
    sub_10b58();
    sub_12df6();
    al = memoryAGet(ds, 0x951a);
    if (al == 0x00)
        goto loc_10f84;
    memoryASet(ds, 0x951a, 0x01);
    si = 0x0d1b;
    memoryASet(ds, si, memoryAGet(ds, si) & 0xdf);
    sub_12f50();
    sub_10b58();
loc_10f84:
    al = memoryAGet(ds, 0x951b);
    if (al == 0x00)
        return;
    memoryASet(ds, 0x951b, 0x01);
    si = 0x0d1b;
    memoryASet(ds, si, memoryAGet(ds, si) | 0x20);
    sub_12f50();
    sub_10b58();
loc_10f9c:
    return;
}
void sub_110c6()
{
    al = memoryAGet(ds, si + 3);
    al += memoryAGet(ds, si + 12);
    true ? cbw() : cwde();
    ax = -ax;
    ax += memoryAGet16(ds, si + 7);
    ax &= 0x03ff;
    bx = memoryAGet16(ds, 0x9528);
    bx += 0x00a0;
    bx &= 0x03ff;
    if (ax >= bx)
        goto loc_110e8;
    ax += 0x0400;
loc_110e8:
    ax -= bx;
    if (ax >= 0x0200)
        return;
    memoryASet(ds, si, 0x00);
loc_110f2:
    return;
}
void sub_110f3()
{
    memoryASet(ds, si + 22, memoryAGet(ds, si + 22) + 1);
    al = memoryAGet(ds, si + 22);
    if (al <= 0x08)
        goto loc_110ff;
    al = 0x08;
loc_110ff:
    ah = 0x00;
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) - ax);
    sub_110a0();
}
void sub_110a0()
{
    al = memoryAGet(ds, si + 10);
    al -= memoryAGet(ds, si + 3);
    al -= memoryAGet(ds, si + 12);
    true ? cbw() : cwde();
    ax += memoryAGet16(ds, si + 7);
    ax &= 0x03ff;
    bx = memoryAGet16(ds, 0x9528);
    if (ax >= bx)
        goto loc_110bb;
    ax += 0x0400;
loc_110bb:
    ax -= bx;
    if (ax <= 0x0200)
        return;
    memoryASet(ds, si, 0x00);
loc_110c5:
    return;
}
void sub_11108()
{
    sub_11b80();
    sub_11bb9();
    bx = memoryAGet16(ds, 0x954c);
    ax = memoryAGet16(ds, 0x952c);
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
    memoryASet16(ds, 0x952c, ax);
    ax += 0x0003;
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    ax += memoryAGet16(ds, 0x1b8f);
    if ((short)ax >= (short)0x0014)
        goto loc_11174;
    ax = 0x0014;
    memoryASet16(ds, 0x952c, 0x0000);
loc_11174:
    if ((short)ax <= (short)0x00ec)
        goto loc_11182;
    ax = 0x00ec;
    memoryASet16(ds, 0x952c, 0x0000);
loc_11182:
    memoryASet16(ds, 0x1b8f, ax);
    al = memoryAGet(ds, 0x1b8e);
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
    memoryASet(ds, 0x1b9e, memoryAGet(ds, 0x1b9e) + 1);
    memoryASet(ds, 0x1b9e, memoryAGet(ds, 0x1b9e) & 0x3f);
    sub_10a51();
    if (ax == 0x0000)
        goto loc_111b3;
    sub_11c56();
loc_111b3:
    memoryASet(ds, 0x1b9e, memoryAGet(ds, 0x1b9e) - 1);
    memoryASet(ds, 0x1b9e, memoryAGet(ds, 0x1b9e) & 0x3f);
loc_111bc:
    ax = memoryAGet16(ds, 0x9542);
    if ((short)ax > (short)0x0000)
        goto loc_111c8;
    sub_11c33();
    return;
loc_111c8:
    al = memoryAGet(ds, 0x1b8e);
    if (al != 0x00)
        goto loc_111de;
    memoryASet(ds, 0x9515, memoryAGet(ds, 0x9515) + 1);
    al = memoryAGet(ds, 0x9515);
    if (al < 0x04)
        return;
    sub_11c33();
loc_111dd:
    return;
loc_111de:
    ax = memoryAGet16(ds, 0x953e);
    if ((short)ax <= (short)0x0000)
        goto loc_111f0;
    ax = memoryAGet16(ds, 0x954c);
    if (!(al & 0x80))
        goto loc_111f0;
    sub_11d1e();
loc_111f0:
    ax = memoryAGet16(ds, 0x954c);
    bl = memoryAGet(ds, 0x951a);
    if (!(al & 0x40))
        goto loc_11235;
    if (bl != 0x00)
        goto loc_11224;
    ax = memoryAGet16(ds, 0x9536);
    if (ax <= 0x0000)
        goto loc_11222;
    memoryASet(ds, 0x951a, 0x01);
    si = 0x0dc3;
    memoryASet(ds, si, memoryAGet(ds, si) & 0xdf);
    sub_11cd9();
    sub_10b58();
    memoryASet16(ds, 0x9538, memoryAGet16(ds, 0x9538) - 1);
    al = 0x01;
    sub_13840();
loc_11222:
    goto loc_11233;
loc_11224:
    if (bl != 0x02)
        goto loc_11233;
    memoryASet(ds, 0x951a, 0x03);
    al = 0x02;
    sub_13840();
loc_11233:
    goto loc_1124b;
loc_11235:
    if (bl != 0x01)
        goto loc_11241;
    memoryASet(ds, 0x951a, 0x02);
    goto loc_1124b;
loc_11241:
    if (bl != 0x03)
        goto loc_1124b;
    memoryASet(ds, 0x951a, 0x00);
loc_1124b:
    ax = memoryAGet16(ds, 0x954c);
    bl = memoryAGet(ds, 0x951b);
    if (!(al & 0x20))
        goto loc_11290;
    if (bl != 0x00)
        goto loc_1127f;
    ax = memoryAGet16(ds, 0x9536);
    if (ax <= 0x0000)
        goto loc_1127d;
    memoryASet(ds, 0x951b, 0x01);
    si = 0x0dc3;
    memoryASet(ds, si, memoryAGet(ds, si) | 0x20);
    sub_11cd9();
    sub_10b58();
    memoryASet16(ds, 0x9538, memoryAGet16(ds, 0x9538) - 1);
    al = 0x01;
    sub_13840();
loc_1127d:
    goto loc_1128e;
loc_1127f:
    if (bl != 0x02)
        goto loc_1128e;
    memoryASet(ds, 0x951b, 0x03);
    al = 0x02;
    sub_13840();
loc_1128e:
    return;
loc_11290:
    if (bl != 0x01)
        goto loc_1129c;
    memoryASet(ds, 0x951b, 0x02);
    return;
loc_1129c:
    if (bl != 0x03)
        return;
    memoryASet(ds, 0x951b, 0x00);
loc_112a6:
    return;
}
void sub_10a51()
{
  bool temp_cf;

    bl = memoryAGet(ds, 0x1b9e);
    bh = 0x00;
    bx <<= 1;
    si = bx;
    al = memoryAGet(ds, 0x9502);
    if (al != 0x01)
        goto loc_10a68;
    si += 0x0080;
    goto loc_10a70;
loc_10a68:
    if (al != 0x02)
        goto loc_10a70;
    si += 0x0100;
loc_10a70:
    ax = memoryAGet16(ds, si + 37545);
    ax &= memoryAGet16(ds, bx + 37417);
    if (ax == 0x0000)
        goto loc_10ad1;
    bl = ah;
    bl >>= 1;
    bl >>= 1;
    bh = 0x00;
    cl = memoryAGet(ds, bx + 693);
    if (cl == 0x00)
        goto loc_10ad1;
    memoryASet(ds, 0x9429, cl);
    memoryASet16(ds, 0x942c, 0x000a);
    bx <<= 1;
    dx = memoryAGet16(ds, bx + 714);
    bx = memoryAGet16(ds, bx + 756);
    cx = 0x000a;
loc_10aa5:
    temp_cf = ax & 1;
    if (!temp_cf)
        goto loc_10ac8;
    push(bx);
    bx -= dx;
    if ((short)bx > (short)memoryAGet16(ds, 0x1b8f))
        goto loc_10ac7;
    bx += dx;
    bx += dx;
    if ((short)bx < (short)memoryAGet16(ds, 0x1b8f))
        goto loc_10ac7;
    ax = pop();
    al = memoryAGet(ds, 0x9429);
    ah = 0x00;
    bx = memoryAGet16(ds, 0x942c);
    return;
loc_10ac7:
    bx = pop();
loc_10ac8:
    bx -= 0x0018;
    memoryASet16(ds, 0x942c, memoryAGet16(ds, 0x942c) - 1);
    if (--cx)
        goto loc_10aa5;
loc_10ad1:
    ax = 0x0000;
}
void sub_112a7()
{
    ax = memoryAGet16(ds, 0x952a);
    ax -= 0x0003;
    if ((short)ax < 0)
        goto loc_112b4;
    memoryASet16(ds, 0x952a, ax);
    goto loc_112b7;
loc_112b4:
    sub_11c33();
loc_112b7:
    sub_11bb9();
    sub_11b57();
    si = 0x1b8a;
    bx = 0x0d49;
    memoryASet(ds, si + 4, 0x0a);
    sub_12121();
}
void sub_112cb()
{
    ax = memoryAGet16(ds, 0x952a);
    ax--;
    if ((short)ax < 0)
        goto loc_112d4;
    memoryASet16(ds, 0x952a, ax);
loc_112d4:
    sub_11bb9();
    sub_11b57();
    memoryASet(ds, 0x9514, memoryAGet(ds, 0x9514) + 1);
    al = memoryAGet(ds, 0x9514);
    if (al < 0x28)
        return;
    memoryASet(ds, 0x9513, 0x01);
loc_112ea:
    return;
}
void sub_112eb()
{
    sub_110a0();
    al = memoryAGet(ds, si);
    if (al != 0x00)
        goto loc_112f5;
    return;
loc_112f5:
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) - 0x0010);
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) & 0x03ff);
    al = memoryAGet(ds, si + 4);
    if (al != 0x01)
        goto loc_11312;
    al = memoryAGet(ds, si + 3);
    if ((char)al <= (char)0x9c)
        goto loc_11310;
    memoryASet(ds, si + 3, memoryAGet(ds, si + 3) - 0x08);
loc_11310:
    goto loc_11321;
loc_11312:
    if (al != 0x02)
        goto loc_11321;
    al = memoryAGet(ds, si + 3);
    if ((char)al >= (char)0x64)
        goto loc_11321;
    memoryASet(ds, si + 3, memoryAGet(ds, si + 3) + 0x08);
loc_11321:
    push(si);
    ax = memoryAGet16(ds, si + 5);
    push(ax);
    ax = memoryAGet16(ds, si + 7);
    push(ax);
    sub_107fd();
    si = pop();
    if ((char)al < (char)memoryAGet(ds, si + 3))
        goto loc_11338;
    sub_12092();
    return;
loc_11338:
    push(si);
    ax = memoryAGet16(ds, si + 5);
    push(ax);
    memoryASet(ds, si + 20, cl);
    push(cx);
    sub_10ad5();
    si = pop();
    if (ax == 0x0000)
        return;
    push(si);
    al = memoryAGet(ds, si + 20);
    ah = 0x00;
    push(bx);
    push(ax);
    sub_11c0a();
    al = memoryAGet(ds, si);
    if (al & 0x80)
        goto loc_11382;
    bx = pop();
    push(bx);
    al = memoryAGet(ds, si + 3);
    al -= memoryAGet(ds, bx + 3);
    if ((char)al >= 0)
        goto loc_11367;
    al = -al;
loc_11367:
    if (al >= 0x10)
        goto loc_11382;
    memoryASet(ds, si + 21, memoryAGet(ds, si + 21) - 1);
    if ((char)memoryAGet(ds, si + 21) >= 0)
        goto loc_1137a;
    sub_120db();
    al = 0x06;
    sub_13840();
    goto loc_1137d;
loc_1137a:
    sub_12662();
loc_1137d:
    si = pop();
    push(si);
    sub_12047();
loc_11382:
    si = pop();
loc_11383:
    return;
}
void sub_107fd()
{
    push(bp);
    bp = sp;
    sp -= 0x0008;
    ax = memoryAGet16(ss, bp + 6 - 2);
    ax += 0x0010;
    cl = 0x18;
    div8(cl);
    push(ax);
    ah = 0x00;
    memoryASet16(ss, bp - 2 - 2, ax);
    ax = pop();
    al = ah;
    ah = 0x00;
    cl = 0x03;
    div8(cl);
    ah = 0x00;
    memoryASet16(ss, bp - 4 - 2, ax);
    ax = memoryAGet16(ss, bp + 4 - 2);
    ax &= 0x03ff;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax = -ax;
    ax += 0x003f;
    memoryASet16(ss, bp - 6 - 2, ax);
    ax = memoryAGet16(ss, bp + 4 - 2);
    ax &= 0x000f;
    ax >>= 1;
    memoryASet16(ss, bp - 8 - 2, ax);
    ax = memoryAGet16(ss, bp - 6 - 2);
    ax <<= 1;
    ax <<= 1;
    bx = ax;
    ax <<= 1;
    bx += ax;
    bx += 0x8f29;
    si = bx;
    bx += memoryAGet16(ss, bp - 2 - 2);
    al = memoryAGet(ds, bx);
    ah = 0x00;
    push(ax);
    ax <<= 1;
    bx = ax;
    bx = memoryAGet16(ds, bx + 1603);
    ax = memoryAGet16(ss, bp - 8 - 2);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    bx += ax;
    bx += memoryAGet16(ss, bp - 4 - 2);
    cl = memoryAGet(ds, bx);
    push(cx);
    cl &= 0x1f;
    if (!(cl & 0x10))
        goto loc_10881;
    cl |= 0xe0;
loc_10881:
    dx = memoryAGet16(ss, bp - 2 - 2);
    flags.direction = 0;
loc_10885:
    if (dx == 0x0000)
        goto loc_10896;
    al = lodsb<DS_SI>();
    bh = 0x00;
    bl = al;
    cl += memoryAGet(ds, bx + 1393);
    dx--;
    goto loc_10885;
loc_10896:
    al = cl;
    true ? cbw() : cwde();
    cx = pop();
    bx = pop();
    if (cl & 0x80)
        goto loc_108a6;
    bl = memoryAGet(ds, bx + 1435);
    goto loc_108aa;
loc_108a6:
    bl = memoryAGet(ds, bx + 1477);
loc_108aa:
    bh = 0x00;
    cx = memoryAGet16(ss, bp - 6 - 2);
    cx = -cx;
    cx += 0x003f;
    sp = bp;
    bp = pop();
    sp += 4;
}
void sub_10ad5()
{
  bool temp_cf;

    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 4 - 2);
    bx <<= 1;
    si = bx;
    al = memoryAGet(ds, 0x9502);
    if (al != 0x01)
        goto loc_10aec;
    si += 0x0080;
    goto loc_10af4;
loc_10aec:
    if (al != 0x02)
        goto loc_10af4;
    si += 0x0100;
loc_10af4:
    ax = memoryAGet16(ds, si + 37545);
    ax &= memoryAGet16(ds, bx + 37417);
    if (ax == 0x0000)
        goto loc_10b51;
    bl = ah;
    bl >>= 1;
    bl >>= 1;
    bh = 0x00;
    cl = memoryAGet(ds, bx + 693);
    if (cl == 0x00)
        goto loc_10b51;
    memoryASet16(ds, 0x942c, 0x000a);
    bx <<= 1;
    dx = memoryAGet16(ds, bx + 714);
    dx -= 0x000e;
    bx = memoryAGet16(ds, bx + 756);
    cx = 0x000a;
loc_10b28:
    temp_cf = ax & 1;
    if (!temp_cf)
        goto loc_10b48;
    push(bx);
    bx -= dx;
    if ((short)bx > (short)memoryAGet16(ss, bp + 6 - 2))
        goto loc_10b47;
    bx += dx;
    bx += dx;
    if ((short)bx < (short)memoryAGet16(ss, bp + 6 - 2))
        goto loc_10b47;
    ax = pop();
    ax = 0x0001;
    bx = memoryAGet16(ds, 0x942c);
    goto loc_10b54;
loc_10b47:
    bx = pop();
loc_10b48:
    bx -= 0x0018;
    memoryASet16(ds, 0x942c, memoryAGet16(ds, 0x942c) - 1);
    if (--cx)
        goto loc_10b28;
loc_10b51:
    ax = 0x0000;
loc_10b54:
    bp = pop();
    sp += 4;
}
void sub_11384()
{
    al = memoryAGet(ds, 0x1b9c);
    if (al != 0x11)
        goto loc_1138e;
    memoryASet(ds, si, 0x00);
loc_1138e:
    sub_11cd9();
    al = memoryAGet(ds, si);
    if (al & 0x20)
        goto loc_1139c;
    al = memoryAGet(ds, 0x951a);
    goto loc_1139f;
loc_1139c:
    al = memoryAGet(ds, 0x951b);
loc_1139f:
    if (al != 0x03)
        return;
    memoryASet(ds, si + 18, 0x19);
loc_113a7:
    return;
}
void sub_113a8()
{
    sub_110a0();
    al = memoryAGet(ds, si);
    if (al != 0x00)
        goto loc_113b2;
    return;
loc_113b2:
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) - 0x0006);
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) & 0x03ff);
    push(si);
    ax = memoryAGet16(ds, si + 5);
    push(ax);
    ax = memoryAGet16(ds, si + 7);
    push(ax);
    sub_107fd();
    si = pop();
    al += 0x04;
    memoryASet(ds, si + 3, al);
    memoryASet(ds, si + 20, cl);
    memoryASet(ds, si + 4, bl);
    bx = 0x0dda;
    sub_12121();
    al = memoryAGet(ds, si + 4);
    if (al != 0x00)
        goto loc_113f5;
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0004);
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) & 0x03ff);
    memoryASet(ds, si + 21, memoryAGet(ds, si + 21) - 1);
    if ((char)memoryAGet(ds, si + 21) >= 0)
        goto loc_113f5;
    sub_120f0();
    memoryASet(ds, si, 0x00);
    return;
loc_113f5:
    push(si);
    ax = memoryAGet16(ds, si + 5);
    push(ax);
    cl = memoryAGet(ds, si + 20);
    ch = 0x00;
    push(cx);
    sub_10ad5();
    si = pop();
    if (ax == 0x0000)
        return;
    push(si);
    al = memoryAGet(ds, si + 20);
    ah = 0x00;
    push(bx);
    push(ax);
    sub_11c0a();
    al = memoryAGet(ds, si);
    if (al & 0x80)
        goto loc_11427;
    sub_120db();
    al = 0x06;
    sub_13840();
    si = pop();
    push(si);
    memoryASet(ds, si, 0x00);
loc_11427:
    si = pop();
loc_11428:
    return;
}
void sub_11429()
{
    sub_110c6();
    al = memoryAGet(ds, si);
    if (al != 0x00)
        goto loc_11433;
    return;
loc_11433:
    al = memoryAGet(ds, si + 1);
    if (al != 0x02)
        goto loc_11440;
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0005);
    goto loc_1146a;
loc_11440:
    if (al != 0x00)
        goto loc_1144a;
    memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) - 0x0005);
    goto loc_1146a;
loc_1144a:
    if (al != 0x01)
        goto loc_11458;
    memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) - 0x0003);
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0002);
    goto loc_1146a;
loc_11458:
    if (al != 0x03)
        goto loc_11466;
    memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) + 0x0003);
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0002);
    goto loc_1146a;
loc_11466:
    memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) + 0x0005);
loc_1146a:
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) & 0x03ff);
    ax = memoryAGet16(ds, si + 5);
    if ((short)ax >= (short)0x000c)
        goto loc_1147b;
    memoryASet(ds, si, 0x00);
    return;
loc_1147b:
    if ((short)ax <= (short)0x00f4)
        goto loc_11484;
    memoryASet(ds, si, 0x00);
    return;
loc_11484:
    push(si);
    ax = memoryAGet16(ds, si + 5);
    push(ax);
    ax = memoryAGet16(ds, si + 7);
    push(ax);
    sub_107fd();
    si = pop();
    al += 0x08;
    memoryASet(ds, si + 3, al);
    memoryASet(ds, si + 20, cl);
    memoryASet(ds, si + 4, bl);
    bl = memoryAGet(ds, si + 1);
    bh = 0x00;
    bx <<= 1;
    bx = memoryAGet16(ds, bx + 4351);
    sub_12121();
    al = memoryAGet(ds, 0x1b9c);
    if (al != 0x11)
        goto loc_114b2;
    return;
loc_114b2:
    ax = memoryAGet16(ds, si + 5);
    ax -= memoryAGet16(ds, 0x1b8f);
    if ((short)ax >= 0)
        goto loc_114bd;
    ax = -ax;
loc_114bd:
    if (ax >= 0x0010)
        return;
    ax = memoryAGet16(ds, si + 7);
    ax -= memoryAGet16(ds, 0x1b91);
    ax -= 0x0008;
    if ((short)ax >= 0)
        goto loc_114d0;
    ax = -ax;
loc_114d0:
    if (ax >= 0x0010)
        return;
    al = 0x05;
    sub_13840();
    memoryASet16(ds, 0x9544, memoryAGet16(ds, 0x9544) - 0x0064);
    memoryASet(ds, 0x12a0, 0x01);
    sub_120f0();
    memoryASet(ds, 0x12a0, 0x05);
    memoryASet(ds, si, 0x00);
loc_114ef:
    return;
}
void sub_114f0()
{
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0001);
    push(si);
    ax = memoryAGet16(ds, si + 5);
    push(ax);
    ax = memoryAGet16(ds, si + 7);
    push(ax);
    sub_107fd();
    si = pop();
    memoryASet(ds, si + 3, al);
    memoryASet(ds, si + 20, cl);
    memoryASet(ds, si + 4, bl);
    bl = memoryAGet(ds, si + 1);
    bh = 0x00;
    bx <<= 1;
    bx = memoryAGet16(ds, bx + 4065);
    sub_12121();
    al = memoryAGet(ds, 0x1b9c);
    if (al == 0x11)
        goto loc_11548;
    ax = memoryAGet16(ds, si + 5);
    ax -= memoryAGet16(ds, 0x1b8f);
    if ((short)ax >= 0)
        goto loc_1152a;
    ax = -ax;
loc_1152a:
    if (ax >= 0x001a)
        goto loc_11548;
    ax = memoryAGet16(ds, si + 7);
    ax -= memoryAGet16(ds, 0x1b91);
    if ((short)ax >= 0)
        goto loc_1153a;
    ax = -ax;
loc_1153a:
    if (ax >= 0x0012)
        goto loc_11548;
    memoryASet16(ds, 0x9544, memoryAGet16(ds, 0x9544) - 0x000c);
    memoryASet(ds, si + 21, 0xff);
loc_11548:
    di = 0x1ba1;
loc_1154b:
    al = memoryAGet(ds, si + 21);
    if ((char)al >= (char)0x00)
        goto loc_11561;
    al = 0x07;
    sub_13840();
    sub_120f0();
    memoryASet(ds, si, 0x00);
    sub_12676();
    return;
loc_11561:
    al = memoryAGet(ds, di);
    if (al & 0x80)
        goto loc_115c0;
    if (!(al & 0x40))
        goto loc_115bb;
    push(di);
    ax = memoryAGet16(ds, di + 5);
    ax -= memoryAGet16(ds, si + 5);
    if ((short)ax >= 0)
        goto loc_11576;
    ax = -ax;
loc_11576:
    if (ax >= 0x0014)
        goto loc_115ba;
    ax = memoryAGet16(ds, di + 7);
    ax -= memoryAGet16(ds, si + 7);
    if ((short)ax >= 0)
        goto loc_11585;
    ax = -ax;
loc_11585:
    if (ax >= 0x0010)
        goto loc_115ba;
    al = memoryAGet(ds, di + 18);
    if (al != 0x19)
        goto loc_1159a;
    memoryASet(ds, si + 21, 0xff);
    memoryASet(ds, di, 0x00);
    goto loc_115ba;
loc_1159a:
    al = memoryAGet(ds, di + 3);
    al -= memoryAGet(ds, si + 3);
    if ((char)al >= 0)
        goto loc_115a4;
    al = -al;
loc_115a4:
    if (al >= 0x10)
        goto loc_115ba;
    memoryASet(ds, si + 21, memoryAGet(ds, si + 21) - 1);
    push(si);
    si = di;
    sub_12092();
    al = 0x03;
    sub_13840();
    sub_12662();
    si = pop();
loc_115ba:
    di = pop();
loc_115bb:
    di += 0x0017;
    goto loc_1154b;
loc_115c0:
    al = memoryAGet(ds, 0x1b9c);
    if (al == 0x11)
        goto loc_115f8;
    ax = memoryAGet16(ds, 0x1b91);
    if (ax <= memoryAGet16(ds, si + 7))
        goto loc_115f8;
    ax = memoryAGet16(ds, 0x1b8f);
    ax -= memoryAGet16(ds, si + 5);
    if ((short)ax >= 0)
        goto loc_115d9;
    ax = -ax;
loc_115d9:
    if (ax >= 0x0020)
        goto loc_115f8;
    memoryASet(ds, si + 22, memoryAGet(ds, si + 22) - 1);
    if ((char)memoryAGet(ds, si + 22) >= 0)
        goto loc_115ee;
    memoryASet(ds, si + 22, 0x07);
    memoryASet(ds, 0x9518, 0x01);
    goto loc_115f3;
loc_115ee:
    memoryASet(ds, 0x9518, 0x00);
loc_115f3:
    push(si);
    sub_11def();
    si = pop();
loc_115f8:
    sub_110c6();
}
void sub_115fc()
{
    sub_110c6();
    al = memoryAGet(ds, si);
    if (al != 0x00)
        goto loc_11606;
    return;
loc_11606:
    al = memoryAGet(ds, si + 1);
    if (al != 0x02)
        goto loc_11613;
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0008);
    goto loc_1163d;
loc_11613:
    if (al != 0x00)
        goto loc_1161d;
    memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) - 0x0008);
    goto loc_1163d;
loc_1161d:
    if (al != 0x01)
        goto loc_1162b;
    memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) - 0x0006);
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0004);
    goto loc_1163d;
loc_1162b:
    if (al != 0x03)
        goto loc_11639;
    memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) + 0x0006);
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0004);
    goto loc_1163d;
loc_11639:
    memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) + 0x0008);
loc_1163d:
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) & 0x03ff);
    ax = memoryAGet16(ds, si + 5);
    if ((short)ax >= (short)0x0004)
        goto loc_1164e;
    memoryASet(ds, si, 0x00);
    return;
loc_1164e:
    if ((short)ax <= (short)0x00fc)
        goto loc_11657;
    memoryASet(ds, si, 0x00);
    return;
loc_11657:
    al = memoryAGet(ds, si + 4);
    if (al != 0x01)
        goto loc_1166b;
    al = memoryAGet(ds, si + 3);
    if ((char)al >= (char)0x64)
        goto loc_11669;
    memoryASet(ds, si + 3, memoryAGet(ds, si + 3) + 0x04);
loc_11669:
    goto loc_1167a;
loc_1166b:
    if (al != 0x02)
        goto loc_1167a;
    al = memoryAGet(ds, si + 3);
    if ((char)al <= (char)0x9c)
        goto loc_1167a;
    memoryASet(ds, si + 3, memoryAGet(ds, si + 3) - 0x04);
loc_1167a:
    push(si);
    ax = memoryAGet16(ds, si + 5);
    push(ax);
    ax = memoryAGet16(ds, si + 7);
    push(ax);
    sub_107fd();
    si = pop();
    if ((char)al < (char)memoryAGet(ds, si + 3))
        goto loc_11691;
    sub_12092();
    return;
loc_11691:
    al = memoryAGet(ds, 0x1b9c);
    if (al != 0x11)
        goto loc_11699;
    return;
loc_11699:
    ax = memoryAGet16(ds, si + 5);
    ax -= memoryAGet16(ds, 0x1b8f);
    if ((short)ax >= 0)
        goto loc_116a4;
    ax = -ax;
loc_116a4:
    if (ax >= 0x000c)
        return;
    ax = memoryAGet16(ds, si + 7);
    ax -= memoryAGet16(ds, 0x1b91);
    if ((short)ax >= 0)
        goto loc_116b4;
    ax = -ax;
loc_116b4:
    if (ax >= 0x0008)
        return;
    al = memoryAGet(ds, si + 3);
    al -= memoryAGet(ds, 0x1b8d);
    if ((char)al >= 0)
        goto loc_116c4;
    al = -al;
loc_116c4:
    if (al >= 0x10)
        return;
    memoryASet16(ds, 0x9544, memoryAGet16(ds, 0x9544) - 0x0001);
    sub_12092();
    al = 0x04;
    sub_13840();
loc_116d5:
    return;
}
void sub_116d6()
{
    memoryASet(ds, si + 4, memoryAGet(ds, si + 4) - 1);
    if ((char)memoryAGet(ds, si + 4) >= 0)
        return;
    memoryASet(ds, si, 0x00);
loc_116de:
    return;
}
void sub_116df()
{
    al = memoryAGet(ds, si + 4);
    memoryASet(ds, si + 4, memoryAGet(ds, si + 4) + 1);
    if (al < 0x04)
        goto loc_116ed;
    memoryASet(ds, si, 0x00);
    return;
loc_116ed:
    al <<= 1;
    bl = al;
    bh = 0x00;
    ax = memoryAGet16(ds, bx + 5182);
    memoryASet16(ds, si + 15, ax);
    sub_110c6();
}
void sub_116fe()
{
    memoryASet(ds, si + 22, memoryAGet(ds, si + 22) + 1);
    al = memoryAGet(ds, si + 22);
    al >>= 1;
    al >>= 1;
    al &= 0x07;
    if ((char)al < (char)0x05)
        goto loc_11712;
    memoryASet(ds, si, 0x00);
    return;
loc_11712:
    memoryASet(ds, si + 4, al);
    bx = 0x12b5;
    sub_12121();
    sub_110c6();
}
void sub_1171f()
{
    memoryASet(ds, si + 22, memoryAGet(ds, si + 22) + 1);
    al = memoryAGet(ds, si + 22);
    al >>= 1;
    al >>= 1;
    al &= 0x07;
    if ((char)al < (char)0x06)
        goto loc_11733;
    memoryASet(ds, si, 0x00);
    return;
loc_11733:
    memoryASet(ds, si + 4, al);
    bx = 0x12f5;
    sub_12121();
    sub_110c6();
}
void sub_11740()
{
    memoryASet(ds, si + 22, memoryAGet(ds, si + 22) + 1);
    al = memoryAGet(ds, si + 22);
    al &= 0x07;
    if ((char)al < (char)0x04)
        goto loc_11762;
    al = memoryAGet(ds, si);
    if (!(al & 0x20))
        goto loc_11759;
    memoryASet(ds, 0x9517, memoryAGet(ds, 0x9517) & 0x7f);
    goto loc_1175e;
loc_11759:
    memoryASet(ds, 0x9517, memoryAGet(ds, 0x9517) & 0xfe);
loc_1175e:
    memoryASet(ds, si, 0x00);
    return;
loc_11762:
    memoryASet(ds, si + 4, al);
    bx = 0x133d;
    sub_12121();
}
void sub_1176c()
{
    memoryASet(ds, si + 22, memoryAGet(ds, si + 22) + 1);
    al = memoryAGet(ds, si + 22);
    al >>= 1;
    al &= 0x03;
    memoryASet(ds, si + 4, al);
    bx = 0x0e2b;
    sub_12121();
    sub_110c6();
}
void sub_11783()
{
    memoryASet(ds, si + 22, memoryAGet(ds, si + 22) + 1);
    al = memoryAGet(ds, si + 22);
    al >>= 1;
    al &= 0x07;
    if (al < 0x06)
        goto loc_11797;
    al = 0x00;
    memoryASet(ds, si + 22, 0x00);
loc_11797:
    bl = al;
    bh = 0x00;
    al = memoryAGet(ds, bx + 3660);
    memoryASet(ds, si + 4, al);
    bx = 0x0e52;
    sub_12121();
    sub_110c6();
}
void sub_117ac()
{
    sub_1215b();
    if (cx == 0x0000)
        goto loc_117cc;
    memoryASet(ds, si + 22, memoryAGet(ds, si + 22) - 1);
    if ((char)memoryAGet(ds, si + 22) >= 0)
        goto loc_117c4;
    memoryASet(ds, si + 22, 0x08);
    memoryASet(ds, 0x9518, 0x01);
    goto loc_117c9;
loc_117c4:
    memoryASet(ds, 0x9518, 0x00);
loc_117c9:
    sub_11f0b();
loc_117cc:
    bx = 0x0e73;
    sub_12121();
    sub_110c6();
}
void sub_117d6()
{
    sub_1215b();
    if (cx == 0x0000)
        goto loc_117ea;
    memoryASet(ds, si + 22, memoryAGet(ds, si + 22) - 1);
    if ((char)memoryAGet(ds, si + 22) >= 0)
        goto loc_117ea;
    memoryASet(ds, si + 22, 0x12);
    sub_12005();
loc_117ea:
    bx = 0x0e9c;
    sub_12121();
    sub_110c6();
}
void sub_117f4()
{
    sub_110c6();
    al = memoryAGet(ds, si);
    if (al != 0x00)
        goto loc_117fe;
    return;
loc_117fe:
    al = memoryAGet(ds, si + 1);
    if (al != 0x02)
        goto loc_1180b;
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0003);
    goto loc_11835;
loc_1180b:
    if (al != 0x00)
        goto loc_11815;
    memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) - 0x0004);
    goto loc_11835;
loc_11815:
    if (al != 0x01)
        goto loc_11823;
    memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) - 0x0004);
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0003);
    goto loc_11835;
loc_11823:
    if (al != 0x03)
        goto loc_11831;
    memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) + 0x0004);
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) + 0x0003);
    goto loc_11835;
loc_11831:
    memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) + 0x0004);
loc_11835:
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) & 0x03ff);
    ax = memoryAGet16(ds, si + 5);
    if ((short)ax >= (short)0x0008)
        goto loc_11846;
    memoryASet(ds, si, 0x00);
    return;
loc_11846:
    if ((short)ax <= (short)0x00f8)
        goto loc_1184f;
    memoryASet(ds, si, 0x00);
    return;
loc_1184f:
    memoryASet(ds, si + 22, memoryAGet(ds, si + 22) + 1);
    bl = memoryAGet(ds, si + 22);
    if (bl < 0x10)
        goto loc_1185e;
    sub_12099();
    return;
loc_1185e:
    bh = 0x00;
    al = memoryAGet(ds, bx + 5223);
    memoryASet(ds, si + 3, memoryAGet(ds, si + 3) + al);
    al = memoryAGet(ds, 0x1b9c);
    if (al != 0x11)
        goto loc_1186f;
    return;
loc_1186f:
    ax = memoryAGet16(ds, si + 5);
    ax -= memoryAGet16(ds, 0x1b8f);
    if ((short)ax >= 0)
        goto loc_1187a;
    ax = -ax;
loc_1187a:
    if (ax >= 0x000e)
        return;
    ax = memoryAGet16(ds, si + 7);
    ax -= memoryAGet16(ds, 0x1b91);
    if ((short)ax >= 0)
        goto loc_1188a;
    ax = -ax;
loc_1188a:
    if (ax >= 0x000a)
        return;
    al = memoryAGet(ds, si + 3);
    al -= memoryAGet(ds, 0x1b8d);
    if ((char)al >= 0)
        goto loc_1189a;
    al = -al;
loc_1189a:
    if (al >= 0x10)
        return;
    memoryASet16(ds, 0x9544, memoryAGet16(ds, 0x9544) - 0x000a);
    al = 0x05;
    sub_13840();
loc_118a8:
    return;
}
void sub_118a9()
{
    sub_1215b();
    if (cx == 0x0000)
        goto loc_118bd;
    memoryASet(ds, si + 22, memoryAGet(ds, si + 22) - 1);
    if ((char)memoryAGet(ds, si + 22) >= 0)
        goto loc_118bd;
    memoryASet(ds, si + 22, 0x28);
    sub_11fba();
loc_118bd:
    bx = 0x0ec5;
    sub_12121();
    sub_110c6();
}
void sub_118c7()
{
    al = memoryAGet(ds, 0x952e);
    al &= memoryAGet(ds, 0x952f);
    al &= memoryAGet(ds, 0x9530);
    al &= memoryAGet(ds, 0x9531);
    al &= memoryAGet(ds, 0x9532);
    al &= memoryAGet(ds, 0x9533);
    if (al)
        goto loc_118e4;
    sub_110c6();
    return;
loc_118e4:
    ax = memoryAGet16(ds, 0x1b8f);
    ax -= memoryAGet16(ds, si + 5);
    ax -= 0x000c;
    if ((short)ax >= 0)
        goto loc_118f1;
    ax = -ax;
loc_118f1:
    cx = memoryAGet16(ds, 0x1b91);
    cx -= 0x0008;
    cx -= memoryAGet16(ds, si + 7);
    if ((short)cx >= 0)
        goto loc_118ff;
    cx = -cx;
loc_118ff:
    bl = memoryAGet(ds, si + 4);
    bl >>= 1;
    ax += cx;
    if (ax > 0x0040)
        goto loc_11915;
    if (bl == 0x08)
        goto loc_11913;
    memoryASet(ds, si + 4, memoryAGet(ds, si + 4) + 1);
loc_11913:
    goto loc_1191d;
loc_11915:
    if (bl == 0x00)
        goto loc_1191d;
    memoryASet(ds, si + 4, memoryAGet(ds, si + 4) - 1);
loc_1191d:
    push(bx);
    bh = 0x00;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 5251);
    memoryASet16(ds, si + 15, ax);
    bx = pop();
    if (bl < 0x02)
        goto loc_1196b;
    ax = memoryAGet16(ds, 0x1b8f);
    ax -= memoryAGet16(ds, si + 5);
    ax -= 0x000c;
    if ((short)ax >= 0)
        goto loc_11947;
    ax = -ax;
    if (ax > 0x0018)
        goto loc_11945;
    memoryASet16(ds, 0x1b8f, memoryAGet16(ds, 0x1b8f) + 1);
loc_11945:
    goto loc_11952;
loc_11947:
    if (!ax)
        goto loc_11952;
    if (ax > 0x0018)
        goto loc_11952;
    memoryASet16(ds, 0x1b8f, memoryAGet16(ds, 0x1b8f) - 1);
loc_11952:
    if (bl != 0x08)
        goto loc_1196b;
    if (cx > 0x0008)
        goto loc_1196b;
    if (ax > 0x0008)
        goto loc_1196b;
    al = memoryAGet(ds, 0x1b9c);
    if (al == 0x11)
        goto loc_1196b;
    sub_1196f();
loc_1196b:
    sub_110c6();
}
void sub_1196f()
{
    al = memoryAGet(ds, 0x1b8e);
    if (al != 0x00)
        goto loc_11982;
    memoryASet(ds, 0x951d, 0xf0);
    memoryASet(ds, 0x94ff, 0x01);
    return;
loc_11982:
    push(si);
    memoryASet(ds, 0x1b8e, 0x00);
    si = 0x1b8a;
    bx = 0x0d49;
    sub_12121();
    si = pop();
loc_11992:
    return;
}
void sub_11993()
{
    sub_11a04();
    al = memoryAGet(ds, 0x94ff);
    if (al != 0x01)
        return;
    al = memoryAGet(ds, 0x9501);
    bl = al;
    al <<= 1;
    bl += al;
    bl += memoryAGet(ds, 0x9502);
    bh = 0x00;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 5269);
    bh = ah;
    ax &= 0x03ff;
    memoryASet16(ds, 0x950c, ax);
    bh &= 0xc0;
    memoryASet(ds, 0x951d, bh);
loc_119c1:
    return;
}
void sub_119c2()
{
    sub_11a04();
    al = memoryAGet(ds, 0x94ff);
    if (al != 0x01)
        return;
    al = memoryAGet(ds, 0x9501);
    bl = al;
    al <<= 1;
    bl += al;
    bl += memoryAGet(ds, 0x9502);
    bh = 0x00;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 5317);
    bh = ah;
    ax &= 0x03ff;
    memoryASet16(ds, 0x950c, ax);
    bh &= 0xc0;
    memoryASet(ds, 0x951d, bh);
    memoryASet(ds, 0x950e, 0x01);
    al = memoryAGet(ds, 0x9502);
    al++;
    if (al <= 0x02)
        goto loc_11a00;
    al = 0x00;
loc_11a00:
    memoryASet(ds, 0x9502, al);
loc_11a03:
    return;
}
void sub_11a04()
{
    ax = memoryAGet16(ds, 0x1b8f);
    ax -= memoryAGet16(ds, si + 5);
    ax -= 0x000c;
    if ((short)ax >= 0)
        goto loc_11a11;
    ax = -ax;
loc_11a11:
    cx = memoryAGet16(ds, 0x1b91);
    cx -= memoryAGet16(ds, si + 7);
    if ((short)cx >= 0)
        goto loc_11a1c;
    cx = -cx;
loc_11a1c:
    bl = memoryAGet(ds, si + 4);
    bl >>= 1;
    ax += cx;
    if (ax > 0x0040)
        goto loc_11a32;
    if (bl == 0x06)
        goto loc_11a30;
    memoryASet(ds, si + 4, memoryAGet(ds, si + 4) + 1);
loc_11a30:
    goto loc_11a3a;
loc_11a32:
    if (bl == 0x00)
        goto loc_11a3a;
    memoryASet(ds, si + 4, memoryAGet(ds, si + 4) - 1);
loc_11a3a:
    if (bl != 0x06)
        goto loc_11a45;
    memoryASet(ds, si + 2, 0x00);
    goto loc_11a56;
loc_11a45:
    push(bx);
    memoryASet(ds, si + 2, 0x07);
    bh = 0x00;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 5239);
    memoryASet16(ds, si + 15, ax);
    bx = pop();
loc_11a56:
    if (bl < 0x01)
        goto loc_11a9a;
    ax = memoryAGet16(ds, 0x1b8f);
    ax -= memoryAGet16(ds, si + 5);
    ax -= 0x000c;
    if ((short)ax >= 0)
        goto loc_11a73;
    ax = -ax;
    if (ax > 0x0018)
        goto loc_11a71;
    memoryASet16(ds, 0x1b8f, memoryAGet16(ds, 0x1b8f) + 1);
loc_11a71:
    goto loc_11a7e;
loc_11a73:
    if (!ax)
        goto loc_11a7e;
    if (ax > 0x0018)
        goto loc_11a7e;
    memoryASet16(ds, 0x1b8f, memoryAGet16(ds, 0x1b8f) - 1);
loc_11a7e:
    if (cx > 0x0008)
        goto loc_11a9a;
    if (ax > 0x0008)
        goto loc_11a9a;
    al = memoryAGet(ds, 0x1b9c);
    if (al == 0x11)
        goto loc_11a9a;
    ax = memoryAGet16(ds, 0x1b8f);
    memoryASet16(ds, 0x950a, ax);
    memoryASet(ds, 0x94ff, 0x01);
loc_11a9a:
    sub_110c6();
}
void sub_11a9e()
{
    sub_110c6();
    al = memoryAGet(ds, si);
    if (al != 0x00)
        goto loc_11aa8;
    return;
loc_11aa8:
    bx = memoryAGet16(ds, 0x1b91);
    bx -= memoryAGet16(ds, si + 7);
    if ((short)bx >= 0)
        goto loc_11abb;
    if ((short)bx >= (short)0xfff0)
        return;
    memoryASet(ds, si + 2, 0x01);
loc_11aba:
    return;
loc_11abb:
    if ((short)bx <= (short)0x0020)
        goto loc_11ac1;
    return;
loc_11ac1:
    ax = memoryAGet16(ds, 0x1b8f);
    ax -= memoryAGet16(ds, si + 5);
    ax -= 0x000c;
    if ((short)ax >= 0)
        goto loc_11ad9;
    ax = -ax;
    if (ax >= 0x0018)
        goto loc_11ad7;
    memoryASet16(ds, 0x1b8f, memoryAGet16(ds, 0x1b8f) + 1);
loc_11ad7:
    goto loc_11ae7;
loc_11ad9:
    if (ax >= 0x0018)
        goto loc_11ae7;
    if (ax == 0x0000)
        goto loc_11ae7;
    memoryASet16(ds, 0x1b8f, memoryAGet16(ds, 0x1b8f) - 1);
loc_11ae7:
    if (bx <= 0x0008)
        goto loc_11aed;
    return;
loc_11aed:
    if (ax > 0x0002)
        goto loc_11af8;
    memoryASet16(ds, 0x9538, memoryAGet16(ds, 0x9538) + 1);
    return;
loc_11af8:
    if (ax >= 0x0024)
        return;
    memoryASet16(ds, 0x9542, 0x0000);
    al = 0x06;
    sub_13840();
loc_11b08:
    return;
}
void sub_11b09()
{
    sub_110c6();
    al = memoryAGet(ds, si);
    if (al != 0x00)
        goto loc_11b13;
    return;
loc_11b13:
    al = memoryAGet(ds, 0x1b9c);
    if (al != 0x11)
        goto loc_11b1b;
    return;
loc_11b1b:
    ax = memoryAGet16(ds, si + 5);
    ax -= memoryAGet16(ds, 0x1b8f);
    if ((short)ax >= 0)
        goto loc_11b26;
    ax = -ax;
loc_11b26:
    if (ax >= 0x0012)
        return;
    ax = memoryAGet16(ds, si + 7);
    ax -= memoryAGet16(ds, 0x1b91);
    if ((short)ax >= 0)
        goto loc_11b36;
    ax = -ax;
loc_11b36:
    if (ax >= 0x0010)
        return;
    memoryASet(ds, si, 0x00);
    al = memoryAGet(ds, si + 1);
    sub_12b28();
    al = 0x0a;
    sub_13840();
loc_11b49:
    return;
}
void sub_11b4a()
{
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) - 0x0002);
    memoryASet16(ds, si + 7, memoryAGet16(ds, si + 7) & 0x03ff);
    sub_110a0();
}
void sub_11b57()
{
    ax = memoryAGet16(ds, 0x1b8f);
    push(ax);
    ax = memoryAGet16(ds, 0x9528);
    ax += 0x0070;
    ax &= 0x03ff;
    memoryASet16(ds, 0x1b91, ax);
    push(ax);
    sub_107fd();
    memoryASet(ds, 0x1b8d, al);
    memoryASet(ds, 0x1b9e, cl);
    memoryASet(ds, 0x1b8e, bl);
    si = 0x1b8a;
    bx = 0x0d49;
    sub_12121();
}
void sub_11b80()
{
    bx = memoryAGet16(ds, 0x952a);
    ax = memoryAGet16(ds, 0x953a);
    if ((short)ax > (short)0x0000)
        goto loc_11b91;
    ax = 0x0008;
    goto loc_11b94;
loc_11b91:
    ax = memoryAGet16(ds, 0x954c);
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
    if ((short)bx >= (short)memoryAGet16(ds, 0x94fc))
        goto loc_11bb4;
    bx = memoryAGet16(ds, 0x94fc);
loc_11bb4:
    memoryASet16(ds, 0x952a, bx);
}
void sub_11bb9()
{
    bx = memoryAGet16(ds, 0x952a);
    bx += 0x000f;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    ax = bx;
    ax--;
    bx >>= 1;
    ax += memoryAGet16(ds, 0x950f);
    if (ax <= 0x008b)
        goto loc_11bdd;
    ax = 0x0000;
    memoryASet16(ds, 0x953c, 0xffff);
loc_11bdd:
    memoryASet16(ds, 0x950f, ax);
    ax = memoryAGet16(ds, 0x9528);
    ax -= bx;
    ax &= 0x03ff;
    memoryASet16(ds, 0x9528, ax);
    ax = memoryAGet16(ds, 0x9528);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax -= 0x0003;
    ax &= 0x003f;
    if (ax == memoryAGet16(ds, 0x9507))
        return;
    memoryASet16(ds, 0x9507, ax);
    push(ax);
    sub_108ba();
loc_11c09:
    return;
}
void sub_11c0a()
{
    push(bp);
    bp = sp;
    bx = memoryAGet16(ss, bp + 6 - 2);
    cx = memoryAGet16(ss, bp + 4 - 2);
    si = 0x1b8a;
loc_11c16:
    al = memoryAGet(ds, si);
    if (al & 0x80)
        goto loc_11c2f;
    if (!(al & 0x08))
        goto loc_11c2a;
    if (cl != memoryAGet(ds, si + 20))
        goto loc_11c2a;
    if (bl == memoryAGet(ds, si + 19))
        goto loc_11c2f;
loc_11c2a:
    si += 0x0017;
    goto loc_11c16;
loc_11c2f:
    bp = pop();
    sp += 4;
}
void sub_11c33()
{
    al = memoryAGet(ds, 0x1b9c);
    if (al != 0x11)
        goto loc_11c3b;
    return;
loc_11c3b:
    al = 0x0c;
    sub_13840();
    si = 0x1b8a;
    sub_120f0();
    memoryASet(ds, 0x1b9c, 0x11);
    memoryASet(ds, 0x1b8c, 0x00);
    memoryASet(ds, 0x9514, 0x00);
}
void sub_11c56()
{
    ax = -ax;
    memoryASet16(ds, 0x9544, ax);
    push(ax);
    al = 0x06;
    sub_13840();
    ax = pop();
    ax = bx;
    push(ax);
    al = memoryAGet(ds, 0x1b9e);
    ah = 0x00;
    push(ax);
    sub_11c0a();
    al = memoryAGet(ds, si);
    if (al & 0x80)
        return;
    sub_120db();
loc_11c77:
    return;
}
void sub_11c78()
{
    ax = memoryAGet16(ds, 0x9437);
    memoryASet16(ds, 0x9439, ax);
    ax = memoryAGet16(ds, 0x9435);
    memoryASet16(ds, 0x9437, ax);
    ax = memoryAGet16(ds, 0x9433);
    memoryASet16(ds, 0x9435, ax);
    ax = memoryAGet16(ds, 0x1b8f);
    memoryASet16(ds, 0x9433, ax);
    ax = memoryAGet16(ds, 0x943f);
    memoryASet16(ds, 0x9441, ax);
    ax = memoryAGet16(ds, 0x943d);
    memoryASet16(ds, 0x943f, ax);
    ax = memoryAGet16(ds, 0x943b);
    memoryASet16(ds, 0x943d, ax);
    ax = memoryAGet16(ds, 0x1b91);
    memoryASet16(ds, 0x943b, ax);
    al = memoryAGet(ds, 0x9445);
    memoryASet(ds, 0x9446, al);
    al = memoryAGet(ds, 0x9444);
    memoryASet(ds, 0x9445, al);
    al = memoryAGet(ds, 0x9443);
    memoryASet(ds, 0x9444, al);
    al = memoryAGet(ds, 0x1b8e);
    memoryASet(ds, 0x9443, al);
    al = memoryAGet(ds, 0x9449);
    memoryASet(ds, 0x944a, al);
    al = memoryAGet(ds, 0x9448);
    memoryASet(ds, 0x9449, al);
    al = memoryAGet(ds, 0x9447);
    memoryASet(ds, 0x9448, al);
    al = memoryAGet(ds, 0x1b8d);
    memoryASet(ds, 0x9447, al);
}
void sub_11cd9()
{
    ax = memoryAGet16(ds, 0x9439);
    memoryASet16(ds, si + 5, ax);
    ax = memoryAGet16(ds, 0x9441);
    ax += 0x0006;
    ax &= 0x03ff;
    memoryASet16(ds, si + 7, ax);
    al = memoryAGet(ds, 0x9446);
    memoryASet(ds, si + 4, al);
    bl = al;
    bh = 0x00;
    cl = memoryAGet(ds, bx + 3513);
    al = memoryAGet(ds, 0x944a);
    al += 0x06;
    memoryASet(ds, si + 3, al);
    al = memoryAGet(ds, si);
    if (al & 0x20)
        goto loc_11d10;
    memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) - 0x0008);
    memoryASet(ds, si + 3, memoryAGet(ds, si + 3) + cl);
    goto loc_11d17;
loc_11d10:
    memoryASet16(ds, si + 5, memoryAGet16(ds, si + 5) + 0x0008);
    memoryASet(ds, si + 3, memoryAGet(ds, si + 3) - cl);
loc_11d17:
    bx = 0x0dda;
    sub_12121();
}
void sub_11d1e()
{
    si = 0x135e;
    memoryASet(ds, si, memoryAGet(ds, si) & 0xdf);
    bl = memoryAGet(ds, 0x1b8e);
    bh = 0x00;
    al = memoryAGet(ds, bx + 5021);
    memoryASet(ds, si + 4, al);
    al = memoryAGet(ds, bx + 4981);
    true ? cbw() : cwde();
    ax += memoryAGet16(ds, 0x1b8f);
    memoryASet16(ds, si + 5, ax);
    ax = memoryAGet16(ds, 0x1b91);
    ax -= 0x0004;
    ax &= 0x03ff;
    memoryASet16(ds, si + 7, ax);
    al = memoryAGet(ds, 0x1b8d);
    al += memoryAGet(ds, bx + 5001);
    memoryASet(ds, si + 3, al);
    bl = memoryAGet(ds, si + 4);
    bh = 0x00;
    al = memoryAGet(ds, bx + 5031);
    memoryASet(ds, si + 10, al);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 5034);
    memoryASet16(ds, si + 15, ax);
    sub_10b58();
    si = 0x0ff7;
    ax = memoryAGet16(ds, 0x1363);
    memoryASet16(ds, si + 5, ax);
    ax = memoryAGet16(ds, 0x1365);
    memoryASet16(ds, si + 7, ax);
    al = memoryAGet(ds, 0x1361);
    memoryASet(ds, si + 3, al);
    memoryASet(ds, 0x9516, memoryAGet(ds, 0x9516) + 1);
    bl = memoryAGet(ds, 0x9516);
    bx &= 0x000f;
    al = memoryAGet(ds, bx + 4071);
    memoryASet(ds, si + 4, al);
    bx = 0x100e;
    sub_12121();
    sub_10b58();
    si = 0x135e;
    memoryASet(ds, si, memoryAGet(ds, si) | 0x20);
    bl = memoryAGet(ds, 0x1b8e);
    bh = 0x00;
    al = memoryAGet(ds, bx + 4991);
    true ? cbw() : cwde();
    ax += memoryAGet16(ds, 0x1b8f);
    memoryASet16(ds, si + 5, ax);
    al = memoryAGet(ds, 0x1b8d);
    al += memoryAGet(ds, bx + 5011);
    memoryASet(ds, si + 3, al);
    sub_10b58();
    si = 0x0ff7;
    ax = memoryAGet16(ds, 0x1363);
    memoryASet16(ds, si + 5, ax);
    ax = memoryAGet16(ds, 0x1365);
    memoryASet16(ds, si + 7, ax);
    al = memoryAGet(ds, 0x1361);
    memoryASet(ds, si + 3, al);
    sub_10b58();
    ax = memoryAGet16(ds, 0x9511);
    ax += bx;
    if (ax <= 0x0010)
        goto loc_11deb;
    ax = 0x0000;
    memoryASet16(ds, 0x9540, 0xffff);
loc_11deb:
    memoryASet16(ds, 0x9511, ax);
}
void sub_11def()
{
    memoryASet(ds, 0x9516, memoryAGet(ds, 0x9516) + 1);
    bl = memoryAGet(ds, 0x9516);
    bx &= 0x000f;
    al = memoryAGet(ds, bx + 4071);
    memoryASet(ds, 0x0ffb, al);
    al = memoryAGet(ds, si + 1);
    if (al != 0x00)
        goto loc_11e2e;
    bl = memoryAGet(ds, si + 4);
    bh = 0x00;
    cl = memoryAGet(ds, bx + 5069);
    ax = 0xfffd;
    bx = 0x0008;
    sub_11e7d();
    bl = memoryAGet(ds, si + 4);
    bh = 0x00;
    cl = memoryAGet(ds, bx + 5079);
    ax = 0x0003;
    bx = 0x0008;
    sub_11e7d();
    return;
loc_11e2e:
    if (al != 0x01)
        goto loc_11e46;
    bl = memoryAGet(ds, si + 4);
    bh = 0x00;
    cl = memoryAGet(ds, bx + 5089);
    ax = 0x0000;
    bx = 0x0008;
    sub_11e7d();
    return;
loc_11e46:
    bl = memoryAGet(ds, si + 4);
    bh = 0x00;
    cl = memoryAGet(ds, bx + 5099);
    ax = 0xfff9;
    bx = 0x0008;
    sub_11e7d();
    bl = memoryAGet(ds, si + 4);
    bh = 0x00;
    cl = memoryAGet(ds, bx + 5109);
    ax = 0x0000;
    bx = 0x000b;
    sub_11e7d();
    bl = memoryAGet(ds, si + 4);
    bh = 0x00;
    cl = memoryAGet(ds, bx + 5119);
    ax = 0x0007;
    bx = 0x0008;
    sub_11e7d();
loc_11e7c:
    return;
}
void sub_11e7d()
{
    push(si);
    di = 0x0ff7;
    ax += memoryAGet16(ds, si + 5);
    memoryASet16(ds, di + 5, ax);
    bx += memoryAGet16(ds, si + 7);
    bx &= 0x03ff;
    memoryASet16(ds, di + 7, bx);
    cl += memoryAGet(ds, si + 3);
    memoryASet(ds, di + 3, cl);
    si = di;
    bx = 0x1039;
    sub_12121();
    sub_10b58();
    if (si == 0x0000)
        goto loc_11eb0;
    ax = pop();
    push(ax);
    if (ax <= si)
        goto loc_11eb0;
    sub_116d6();
loc_11eb0:
    si = pop();
    al = memoryAGet(ds, 0x9518);
    if (al != 0x00)
        goto loc_11eb9;
    return;
loc_11eb9:
    push(si);
    bl = memoryAGet(ds, si + 4);
    bh = 0x00;
    si = 0x13b0;
    al = memoryAGet(ds, bx + 5021);
    memoryASet(ds, si + 4, al);
    ax = memoryAGet16(ds, 0x0ffc);
    memoryASet16(ds, si + 5, ax);
    ax = memoryAGet16(ds, 0x0ffe);
    memoryASet16(ds, si + 7, ax);
    al = memoryAGet(ds, 0x0ffa);
    memoryASet(ds, si + 3, al);
    memoryASet(ds, si + 1, 0x02);
    bl = memoryAGet(ds, si + 4);
    bh = 0x00;
    al = memoryAGet(ds, bx + 5031);
    memoryASet(ds, si + 10, al);
    memoryASet(ds, si + 9, 0x04);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 5063);
    memoryASet16(ds, si + 15, ax);
    sub_10b58();
    if (si == 0x0000)
        goto loc_11f09;
    ax = pop();
    push(ax);
    if (ax <= si)
        goto loc_11f09;
    sub_115fc();
loc_11f09:
    si = pop();
}
void sub_11f0b()
{
    push(si);
    memoryASet(ds, 0x9516, memoryAGet(ds, 0x9516) + 1);
    bl = memoryAGet(ds, 0x9516);
    bx &= 0x000f;
    al = memoryAGet(ds, bx + 4071);
    memoryASet(ds, 0x0ffb, al);
    di = 0x0ff7;
    bl = memoryAGet(ds, si + 4);
    bh = 0x00;
    al = memoryAGet(ds, bx + 5129);
    true ? cbw() : cwde();
    ax += memoryAGet16(ds, si + 5);
    memoryASet16(ds, di + 5, ax);
    al = memoryAGet(ds, bx + 5134);
    true ? cbw() : cwde();
    ax += memoryAGet16(ds, si + 7);
    ax &= 0x03ff;
    memoryASet16(ds, di + 7, ax);
    al = memoryAGet(ds, si + 3);
    al += 0x04;
    memoryASet(ds, di + 3, al);
    bx <<= 1;
    bx = memoryAGet16(ds, bx + 4143);
    si = di;
    sub_12121();
    sub_10b58();
    if (si == 0x0000)
        goto loc_11f63;
    ax = pop();
    push(ax);
    if (ax <= si)
        goto loc_11f63;
    sub_116d6();
loc_11f63:
    si = pop();
    al = memoryAGet(ds, 0x9518);
    if (al != 0x00)
        goto loc_11f6c;
    return;
loc_11f6c:
    push(si);
    di = 0x13b0;
    bl = memoryAGet(ds, si + 4);
    bh = 0x00;
    memoryASet(ds, di + 1, bl);
    ax = memoryAGet16(ds, 0x0ffc);
    memoryASet16(ds, di + 5, ax);
    ax = memoryAGet16(ds, 0x0ffe);
    memoryASet16(ds, di + 7, ax);
    al = memoryAGet(ds, 0x0ffa);
    memoryASet(ds, di + 3, al);
    al = memoryAGet(ds, bx + 5139);
    memoryASet(ds, di + 9, al);
    al = memoryAGet(ds, bx + 5144);
    memoryASet(ds, di + 10, al);
    memoryASet(ds, di + 4, 0x00);
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 5149);
    memoryASet16(ds, di + 15, ax);
    si = di;
    sub_10b58();
    if (si == 0x0000)
        goto loc_11fb8;
    ax = pop();
    push(ax);
    if (ax <= si)
        goto loc_11fb8;
    sub_115fc();
loc_11fb8:
    si = pop();
}
void sub_11fba()
{
    push(si);
    di = 0x10e8;
    bl = memoryAGet(ds, si + 4);
    memoryASet(ds, di + 1, bl);
    bh = 0x00;
    al = memoryAGet(ds, bx + 4318);
    true ? cbw() : cwde();
    ax += memoryAGet16(ds, si + 5);
    memoryASet16(ds, di + 5, ax);
    al = memoryAGet(ds, bx + 4323);
    true ? cbw() : cwde();
    ax += memoryAGet16(ds, si + 7);
    ax &= 0x03ff;
    memoryASet16(ds, di + 7, ax);
    al = memoryAGet(ds, si + 3);
    al += 0x08;
    memoryASet(ds, di + 3, al);
    bx <<= 1;
    bx = memoryAGet16(ds, bx + 4351);
    si = di;
    sub_12121();
    sub_10b58();
    if (si == 0x0000)
        goto loc_12003;
    ax = pop();
    push(ax);
    if (ax <= si)
        goto loc_12003;
    sub_11429();
loc_12003:
    si = pop();
}
void sub_12005()
{
    push(si);
    di = 0x1446;
    bl = memoryAGet(ds, si + 4);
    memoryASet(ds, di + 1, bl);
    bh = 0x00;
    al = memoryAGet(ds, bx + 5213);
    true ? cbw() : cwde();
    ax += memoryAGet16(ds, si + 5);
    memoryASet16(ds, di + 5, ax);
    al = memoryAGet(ds, bx + 5218);
    true ? cbw() : cwde();
    ax += memoryAGet16(ds, si + 7);
    ax &= 0x03ff;
    memoryASet16(ds, di + 7, ax);
    al = memoryAGet(ds, si + 3);
    al += 0x08;
    memoryASet(ds, di + 3, al);
    si = di;
    sub_10b58();
    if (si == 0x0000)
        goto loc_12045;
    ax = pop();
    push(ax);
    if (ax <= si)
        goto loc_12045;
    sub_117f4();
loc_12045:
    si = pop();
}
void sub_12047()
{
    al = memoryAGet(ds, si);
    bl = memoryAGet(ds, 0x9517);
    if (!(al & 0x20))
        goto loc_12072;
    if (bl & 0x80)
        goto loc_1206d;
    memoryASet(ds, 0x9517, memoryAGet(ds, 0x9517) | 0x80);
    memoryASet(ds, 0x1326, memoryAGet(ds, 0x1326) | 0x20);
    di = 0x1326;
    sub_120a0();
    al = 0x03;
    sub_13840();
    goto loc_12070;
loc_1206d:
    memoryASet(ds, si, 0x00);
loc_12070:
    return;
loc_12072:
    if (bl & 0x01)
        goto loc_1208e;
    memoryASet(ds, 0x9517, memoryAGet(ds, 0x9517) | 0x01);
    memoryASet(ds, 0x1326, memoryAGet(ds, 0x1326) & 0xdf);
    di = 0x1326;
    sub_120a0();
    al = 0x03;
    sub_13840();
    return;
loc_1208e:
    memoryASet(ds, si, 0x00);
loc_12091:
    return;
}
void sub_12092()
{
    di = 0x1427;
    sub_120a0();
}
void sub_12099()
{
    di = 0x12de;
    sub_120a0();
}
void sub_120a0()
{
    al = memoryAGet(ds, di);
    memoryASet(ds, si, al);
    al = memoryAGet(ds, di + 2);
    memoryASet(ds, si + 2, al);
    al = memoryAGet(ds, di + 22);
    memoryASet(ds, si + 22, al);
    al = memoryAGet(ds, di + 4);
    memoryASet(ds, si + 4, al);
    al = memoryAGet(ds, di + 9);
    memoryASet(ds, si + 9, al);
    al = memoryAGet(ds, di + 10);
    memoryASet(ds, si + 10, al);
    al = memoryAGet(ds, di + 11);
    memoryASet(ds, si + 11, al);
    al = memoryAGet(ds, di + 12);
    memoryASet(ds, si + 12, al);
    ax = memoryAGet16(ds, di + 15);
    memoryASet16(ds, si + 15, ax);
    al = memoryAGet(ds, di + 18);
    memoryASet(ds, si + 18, al);
}
void sub_120db()
{
    sub_12676();
    sub_120f0();
    push(si);
    al = memoryAGet(ds, si + 19);
    ah = 0x00;
    push(ax);
    al = memoryAGet(ds, si + 20);
    push(ax);
    sub_109b5();
}
void sub_109b5()
{
    push(bp);
    bp = sp;
    si = memoryAGet16(ss, bp + 8 - 2);
    sub_10a1b();
    bx = memoryAGet16(ss, bp + 6 - 2);
    bx <<= 1;
    cx = memoryAGet16(ds, bx + 3307);
    bx = memoryAGet16(ss, bp + 4 - 2);
    bx <<= 1;
    al = memoryAGet(ds, 0x9502);
    if (al != 0x01)
        goto loc_109d9;
    bx += 0x0080;
    goto loc_109e1;
loc_109d9:
    if (al != 0x02)
        goto loc_109e1;
    bx += 0x0100;
loc_109e1:
    memoryASet16(ds, bx + 37545, memoryAGet16(ds, bx + 37545) & cx);
    bp = pop();
    sp += 6;
}
void sub_120f0()
{
    push(si);
    ax = memoryAGet16(ds, si + 5);
    memoryASet16(ds, 0x12a3, ax);
    ax = memoryAGet16(ds, si + 7);
    memoryASet16(ds, 0x12a5, ax);
    al = memoryAGet(ds, si + 3);
    memoryASet(ds, 0x12a1, al);
    al = memoryAGet(ds, si);
    if (!(al & 0x10))
        goto loc_12119;
    memoryASet16(ds, 0x12a3, memoryAGet16(ds, 0x12a3) - 0x000c);
    memoryASet16(ds, 0x12a5, memoryAGet16(ds, 0x12a5) - 0x0008);
    memoryASet16(ds, 0x12a5, memoryAGet16(ds, 0x12a5) & 0x03ff);
loc_12119:
    si = 0x129e;
    sub_10b58();
    si = pop();
}
void sub_12121()
{
    cl = memoryAGet(ds, bx);
    ch = 0x00;
    bx++;
    al = memoryAGet(ds, si + 4);
    ah = 0x00;
    di = ax;
    al = memoryAGet(ds, bx + di);
    memoryASet(ds, si + 9, al);
    bx += cx;
    al = memoryAGet(ds, bx + di);
    memoryASet(ds, si + 10, al);
    bx += cx;
    al = memoryAGet(ds, bx + di);
    memoryASet(ds, si + 11, al);
    bx += cx;
    al = memoryAGet(ds, bx + di);
    memoryASet(ds, si + 12, al);
    bx += cx;
    di <<= 1;
    di <<= 1;
    ax = memoryAGet16(ds, bx + di);
    memoryASet16(ds, si + 13, ax);
    bx += 0x0002;
    ax = memoryAGet16(ds, bx + di);
    memoryASet16(ds, si + 15, ax);
}
void sub_1215b()
{
    cx = 0x0001;
    ax = memoryAGet16(ds, 0x1b91);
    ax -= memoryAGet16(ds, si + 7);
    if ((short)ax <= (short)0x008c)
        goto loc_12171;
    memoryASet(ds, si + 4, 0x02);
    cx = 0x0000;
    return;
loc_12171:
    if ((short)ax >= (short)0xfff0)
        goto loc_121a0;
    ah = memoryAGet(ds, si + 4);
    al = memoryAGet(ds, si);
    if (!(al & 0x20))
        goto loc_1218d;
    ah++;
    if ((char)ah <= (char)0x04)
        goto loc_1218b;
    memoryASet(ds, si, memoryAGet(ds, si) & 0xdf);
    ah = 0x04;
loc_1218b:
    goto loc_12199;
loc_1218d:
    ah--;
    if ((char)ah >= (char)0x00)
        goto loc_12199;
    memoryASet(ds, si, memoryAGet(ds, si) | 0x20);
    ah = 0x00;
loc_12199:
    memoryASet(ds, si + 4, ah);
    cx = 0x0000;
    return;
loc_121a0:
    bx = memoryAGet16(ds, 0x1b8f);
    bx -= memoryAGet16(ds, si + 5);
    if ((short)bx >= 0)
        goto loc_121c2;
    if ((short)bx <= (short)0xffe0)
        goto loc_121b3;
    memoryASet(ds, si + 4, 0x02);
    return;
loc_121b3:
    if ((short)ax <= (short)0x0020)
        goto loc_121bd;
    memoryASet(ds, si + 4, 0x01);
    return;
loc_121bd:
    memoryASet(ds, si + 4, 0x00);
    return;
loc_121c2:
    if ((short)bx >= (short)0x0020)
        goto loc_121cc;
    memoryASet(ds, si + 4, 0x02);
    return;
loc_121cc:
    if ((short)ax <= (short)0x0020)
        goto loc_121d6;
    memoryASet(ds, si + 4, 0x03);
    return;
loc_121d6:
    memoryASet(ds, si + 4, 0x04);
}
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
void sub_12200()
{
    sub_1250b();
    sub_12553();
    sub_1259b();
    sub_1237c();
}
void sub_1220d()
{
    memoryASet(ds, 0x944c, memoryAGet(ds, 0x944c) + 1);
    al = memoryAGet(ds, 0x944c);
    al &= 0x03;
    if (al)
        goto loc_12228;
    ax = 0x0000;
    push(ax);
    push(ax);
    push(ax);
    al = memoryAGet(ds, 0x94fe);
    push(ax);
    sub_1269e();
    sub_12714();
loc_12228:
    ax = memoryAGet16(ds, 0x953c);
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
    cx = pop();
    if (--cx)
        goto loc_12239;
loc_12240:
    memoryASet16(ds, 0x953c, 0x0000);
loc_12246:
    ax = memoryAGet16(ds, 0x9540);
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
    cx = pop();
    if (--cx)
        goto loc_12257;
loc_1225e:
    memoryASet16(ds, 0x9540, 0x0000);
loc_12264:
    ax = memoryAGet16(ds, 0x9544);
    if (ax == 0x0000)
        goto loc_1228a;
    if ((short)ax >= 0)
        goto loc_1227b;
    ax = -ax;
    cx = ax;
loc_12272:
    push(cx);
    sub_125bf();
    cx = pop();
    if (--cx)
        goto loc_12272;
    goto loc_12284;
loc_1227b:
    cx = ax;
loc_1227d:
    push(cx);
    sub_125d2();
    cx = pop();
    if (--cx)
        goto loc_1227d;
loc_12284:
    memoryASet16(ds, 0x9544, 0x0000);
loc_1228a:
    ax = memoryAGet16(ds, 0x9538);
    if (ax == 0x0000)
        return;
    if ((short)ax >= 0)
        goto loc_122a1;
    ax = -ax;
    cx = ax;
loc_12298:
    push(cx);
    sub_12464();
    cx = pop();
    if (--cx)
        goto loc_12298;
    goto loc_122aa;
loc_122a1:
    cx = ax;
loc_122a3:
    push(cx);
    sub_1239b();
    cx = pop();
    if (--cx)
        goto loc_122a3;
loc_122aa:
    memoryASet16(ds, 0x9538, 0x0000);
loc_122b0:
    return;
}
void sub_122b1()
{
    memoryASet16(ds, 0x9534, 0x0003);
    sub_122e1();
    sub_122f9();
    sub_12311();
}
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
void sub_12329()
{
    memoryASet16(ds, 0x9534, memoryAGet16(ds, 0x9534) - 1);
    ax = memoryAGet16(ds, 0x9534);
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
void sub_1237c()
{
    memoryASet16(ds, 0x9536, 0x0006);
    memoryASet16(ds, 0x9538, 0x0000);
    sub_123d4();
    sub_123ec();
    sub_12404();
    sub_1241c();
    sub_12434();
    sub_1244c();
}
void sub_1239b()
{
    memoryASet16(ds, 0x9536, memoryAGet16(ds, 0x9536) + 1);
    ax = memoryAGet16(ds, 0x9536);
    if (ax <= 0x0006)
        goto loc_123ae;
    memoryASet16(ds, 0x9536, 0x0006);
    return;
loc_123ae:
    push(ax);
    al = 0x08;
    sub_13840();
    ax = pop();
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
void sub_12464()
{
    ax = memoryAGet16(ds, 0x9536);
    memoryASet16(ds, 0x9536, memoryAGet16(ds, 0x9536) - 1);
    if ((short)memoryAGet16(ds, 0x9536) >= 0)
        goto loc_12474;
    memoryASet16(ds, 0x9536, 0x0000);
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
void sub_1250b()
{
    memoryASet16(ds, 0x953a, 0x002c);
    memoryASet16(ds, 0x953c, 0x0000);
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
void sub_1252f()
{
    ax = memoryAGet16(ds, 0x953a);
    ax--;
    if ((short)ax >= 0)
        goto loc_12536;
    return;
loc_12536:
    memoryASet16(ds, 0x953a, ax);
    push(ax);
    ax = 0x1b88;
    push(ax);
    sub_125e3();
}
void sub_12542()
{
    ax = memoryAGet16(ds, 0x953a);
    if (ax < 0x002c)
        goto loc_1254b;
    return;
loc_1254b:
    sub_12536();
    memoryASet16(ds, 0x953a, memoryAGet16(ds, 0x953a) + 1);
}
void sub_12536()
{
    memoryASet16(ds, 0x953a, ax);
    push(ax);
    ax = 0x1b88;
    push(ax);
    sub_125e3();
}
void sub_12553()
{
    memoryASet16(ds, 0x953e, 0x0030);
    memoryASet16(ds, 0x9540, 0x0000);
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
void sub_12577()
{
    ax = memoryAGet16(ds, 0x953e);
    ax--;
    if ((short)ax >= 0)
        goto loc_1257e;
    return;
loc_1257e:
    memoryASet16(ds, 0x953e, ax);
    push(ax);
    ax = 0x1cc8;
    push(ax);
    sub_125e3();
}
void sub_1258a()
{
    ax = memoryAGet16(ds, 0x953e);
    if (ax < 0x0030)
        goto loc_12593;
    return;
loc_12593:
    sub_1257e();
    memoryASet16(ds, 0x953e, memoryAGet16(ds, 0x953e) + 1);
}
void sub_1257e()
{
    memoryASet16(ds, 0x953e, ax);
    push(ax);
    ax = 0x1cc8;
    push(ax);
    sub_125e3();
}
void sub_1259b()
{
    memoryASet16(ds, 0x9542, 0x0038);
    memoryASet16(ds, 0x9544, 0x0000);
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
void sub_125bf()
{
    ax = memoryAGet16(ds, 0x9542);
    ax--;
    if ((short)ax >= 0)
        goto loc_125c6;
    return;
loc_125c6:
    memoryASet16(ds, 0x9542, ax);
    push(ax);
    ax = 0x1e08;
    push(ax);
    sub_125e3();
}
void sub_125d2()
{
    ax = memoryAGet16(ds, 0x9542);
    if (ax < 0x0038)
        goto loc_125db;
    return;
loc_125db:
    sub_125c6();
    memoryASet16(ds, 0x9542, memoryAGet16(ds, 0x9542) + 1);
}
void sub_125c6()
{
    memoryASet16(ds, 0x9542, ax);
    push(ax);
    ax = 0x1e08;
    push(ax);
    sub_125e3();
}
void sub_125e3()
{
    push(bp);
    bp = sp;
    ax = 0xa000;
    es = ax;
    ax = memoryAGet16(ss, bp + 6 - 2);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax += memoryAGet16(ss, bp + 4 - 2);
    di = ax;
    dx = 0x03ce;
    ax = 0x0805;
    out16(dx, ax);
    cx = memoryAGet16(ss, bp + 6 - 2);
    cx &= 0x0007;
    ah = 0x80;
    ah >>= cl;
    al = 0x08;
    out16(dx, ax);
    bl = ah;
    ax = 0x1803;
    out16(dx, ax);
    ax = 0x0f01;
    out16(dx, ax);
    ax = 0x0700;
    out16(dx, ax);
    cx = 0x0007;
loc_1261e:
    al = memoryAGet(es, di);
    if (bl & al)
        goto loc_1262d;
    memoryASet(es, di, bl);
    memoryASet(es, di + 8192, bl);
loc_1262d:
    di += 0x0028;
    if (--cx)
        goto loc_1261e;
    ax = 0x0005;
    out16(dx, ax);
    ax = 0xff08;
    out16(dx, ax);
    ax = 0x0003;
    out16(dx, ax);
    ax = 0x0001;
    out16(dx, ax);
    ax = 0x0000;
    out16(dx, ax);
    bp = pop();
    sp += 4;
}
void sub_1264a()
{
    al = 0x00;
    memoryASet(ds, 0x94a9, al);
    memoryASet(ds, 0x94aa, al);
    memoryASet(ds, 0x94ab, al);
    memoryASet(ds, 0x94ac, al);
    memoryASet(ds, 0x94ad, al);
    memoryASet(ds, 0x94ae, al);
    sub_12714();
}
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
void sub_1269e()
{
    push(bp);
    bp = sp;
    al = memoryAGet(ds, 0x94ae);
    al += memoryAGet(ss, bp + 4 - 2);
    if (al <= 0x09)
        goto loc_126b1;
    al -= 0x0a;
    memoryASet(ds, 0x94ad, memoryAGet(ds, 0x94ad) + 1);
loc_126b1:
    memoryASet(ds, 0x94ae, al);
    al = memoryAGet(ds, 0x94ad);
    al += memoryAGet(ss, bp + 6 - 2);
    if (al <= 0x09)
        goto loc_126c4;
    al -= 0x0a;
    memoryASet(ds, 0x94ac, memoryAGet(ds, 0x94ac) + 1);
loc_126c4:
    memoryASet(ds, 0x94ad, al);
    al = memoryAGet(ds, 0x94ac);
    al += memoryAGet(ss, bp + 8 - 2);
    if (al <= 0x09)
        goto loc_126d7;
    al -= 0x0a;
    memoryASet(ds, 0x94ab, memoryAGet(ds, 0x94ab) + 1);
loc_126d7:
    memoryASet(ds, 0x94ac, al);
    al = memoryAGet(ds, 0x94ab);
    al += memoryAGet(ss, bp + 10 - 2);
    if (al <= 0x09)
        goto loc_126ea;
    al -= 0x0a;
    memoryASet(ds, 0x94aa, memoryAGet(ds, 0x94aa) + 1);
loc_126ea:
    memoryASet(ds, 0x94ab, al);
    al = memoryAGet(ds, 0x94aa);
    if (al <= 0x09)
        goto loc_12701;
    al -= 0x0a;
    memoryASet(ds, 0x94a9, memoryAGet(ds, 0x94a9) + 1);
    push(ax);
    push(si);
    sub_122c1();
    si = pop();
    ax = pop();
loc_12701:
    memoryASet(ds, 0x94aa, al);
    al = memoryAGet(ds, 0x94a9);
    if (al <= 0x09)
        goto loc_1270d;
    al -= 0x0a;
loc_1270d:
    memoryASet(ds, 0x94a9, al);
    bp = pop();
    sp += 8;
}
void sub_122c1()
{
    memoryASet16(ds, 0x9534, memoryAGet16(ds, 0x9534) + 1);
    ax = memoryAGet16(ds, 0x9534);
    if (ax <= 0x0003)
        goto loc_122d4;
    memoryASet16(ds, 0x9534, 0x0003);
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
void sub_12714()
{
    memoryASet(ds, 0x944d, 0x01);
    si = 0x94a9;
    cx = 0x0006;
    dx = 0x0000;
loc_12722:
    push(cx);
    al = lodsb<DS_SI>();
    if (al == 0x00)
        goto loc_1272d;
    memoryASet(ds, 0x944d, 0x00);
loc_1272d:
    cl = memoryAGet(ds, 0x944d);
    if (cl != 0x00)
        goto loc_1275e;
    push(dx);
    push(si);
    bh = 0x00;
    bl = al;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 5471);
    push(ax);
    bx = dx;
    ax = memoryAGet16(ds, bx + 5491);
    push(ax);
    ax = 0x0010;
    push(ax);
    ax = 0x0009;
    push(ax);
    ax = 0x0002;
    push(ax);
    sub_12cea();
    si = pop();
    dx = pop();
    dx += 0x0002;
loc_1275e:
    cx = pop();
    if (--cx)
        goto loc_12722;
}
void sub_12762()
{
    cx = 0x0012;
    ax = ds;
    es = ax;
    di = 0x94af;
    flags.direction = 0;
    ax = 0x0000;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    cx = 0x002a;
    di = 0x9455;
    al = 0x2e;
    ah = 0x2e;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    memoryASet(ds, 0x9455, 0x5f);
    al = 0x00;
    cx = 0x0007;
    si = 0x94da;
loc_1278b:
    memoryASet(ds, si, al);
    al++;
    si++;
    if (--cx)
        goto loc_1278b;
    di = 0x9455;
    dx = 0x1506;
    cx = 0x008c;
    sub_10644();
}
void sub_10644()
{
    ax = ds;
    memoryASet16(ds, 0x8f20, ax);
    sub_1064d();
}
void sub_1279f()
{
    sub_12809();
    al = memoryAGet(ds, 0x94e0);
    if (al != 0x00)
        goto loc_127af;
    memoryASet(ds, 0x9546, 0x00);
    return;
loc_127af:
    memoryASet(ds, 0x9546, 0x01);
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
    al = lodsb<DS_SI>();
    memoryASet(ds, bx, al);
    bx++;
    if (--cx)
        goto loc_127c9;
    bx = pop();
    bx <<= 1;
    bx += 0x9455;
    memoryASet16(ds, 0x9451, bx);
    si = 0x9455;
    cx = 0x000c;
loc_127e0:
    al = lodsb<DS_SI>();
    memoryASet(ds, bx, al);
    bx++;
    if (--cx)
        goto loc_127e0;
    si = 0x94da;
loc_127e9:
    al = memoryAGet(ds, si);
    if (al == 0x00)
        goto loc_127f2;
    si++;
    goto loc_127e9;
loc_127f2:
    al = memoryAGet(ds, 0x94e0);
    memoryASet(ds, si, al);
    memoryASet(ds, 0x94e0, 0x00);
    si -= 0x94da;
    ax = si;
    memoryASet(ds, 0x9450, al);
    sub_128da();
}
void sub_12809()
{
    al = memoryAGet(ds, 0x94da);
    memoryASet(ds, 0x94d3, al);
    al = memoryAGet(ds, 0x94db);
    memoryASet(ds, 0x94d4, al);
    al = memoryAGet(ds, 0x94dc);
    memoryASet(ds, 0x94d5, al);
    al = memoryAGet(ds, 0x94dd);
    memoryASet(ds, 0x94d6, al);
    al = memoryAGet(ds, 0x94de);
    memoryASet(ds, 0x94d7, al);
    al = memoryAGet(ds, 0x94df);
    memoryASet(ds, 0x94d8, al);
    al = memoryAGet(ds, 0x94e0);
    memoryASet(ds, 0x94d9, al);
    si = 0x94d3;
    di = 0x94da;
    cx = 0x0007;
loc_1283c:
    push(cx);
    push(si);
loc_1283e:
    al = memoryAGet(ds, si);
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
    al = memoryAGet(ds, bx);
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
    al = memoryAGet(ds, si);
    memoryASet(ds, si, 0xff);
    memoryASet(ds, di, al);
    di++;
    si = pop();
    cx = pop();
    if (--cx)
        goto loc_1283c;
}
void sub_12872()
{
    push(si);
    push(di);
    al = memoryAGet(ds, si);
    ah = al;
    al <<= 1;
    al += ah;
    al <<= 1;
    ah = 0x00;
    ax += 0x94a9;
    si = ax;
    al = memoryAGet(ds, bx);
    ah = al;
    al <<= 1;
    al += ah;
    al <<= 1;
    ah = 0x00;
    ax += 0x94a9;
    di = ax;
    al = memoryAGet(ds, di);
    if (al > memoryAGet(ds, si))
        goto loc_128d5;
    if (al < memoryAGet(ds, si))
        goto loc_128d0;
    al = memoryAGet(ds, di + 1);
    if (al > memoryAGet(ds, si + 1))
        goto loc_128d5;
    if (al < memoryAGet(ds, si + 1))
        goto loc_128d0;
    al = memoryAGet(ds, di + 2);
    if (al > memoryAGet(ds, si + 2))
        goto loc_128d5;
    if (al < memoryAGet(ds, si + 2))
        goto loc_128d0;
    al = memoryAGet(ds, di + 3);
    if (al > memoryAGet(ds, si + 3))
        goto loc_128d5;
    if (al < memoryAGet(ds, si + 3))
        goto loc_128d0;
    al = memoryAGet(ds, di + 4);
    if (al > memoryAGet(ds, si + 4))
        goto loc_128d5;
    if (al < memoryAGet(ds, si + 4))
        goto loc_128d0;
    al = memoryAGet(ds, di + 5);
    if (al > memoryAGet(ds, si + 5))
        goto loc_128d5;
    if (al < memoryAGet(ds, si + 5))
        goto loc_128d0;
loc_128d0:
    al = 0x00;
    di = pop();
    si = pop();
    return;
loc_128d5:
    al = 0x01;
    di = pop();
    si = pop();
}
void sub_128da()
{
    si = 0x94da;
    di = 0x01b1;
    cx = 0x0006;
loc_128e3:
    push(cx);
    di += 0x0002;
    ax = memoryAGet16(ds, di);
    di += 0x0002;
    push(si);
    push(di);
    sub_12959();
    di = pop();
    si = pop();
    di += 0x0002;
    ax = memoryAGet16(ds, di);
    di += 0x0002;
    push(si);
    push(di);
    sub_12907();
    di = pop();
    si = pop();
    si++;
    cx = pop();
    if (--cx)
        goto loc_128e3;
}
void sub_12907()
{
    memoryASet16(ds, 0x944e, ax);
    al = memoryAGet(ds, si);
    ah = al;
    al <<= 1;
    al += ah;
    ah = 0x00;
    ax <<= 1;
    ax += 0x94a9;
    si = ax;
    memoryASet(ds, 0x944d, 0x01);
    cx = 0x0006;
    dx = 0x0000;
loc_12926:
    push(cx);
    al = lodsb<DS_SI>();
    if (al == 0x00)
        goto loc_12931;
    memoryASet(ds, 0x944d, 0x00);
loc_12931:
    cl = memoryAGet(ds, 0x944d);
    if (cl == 0x00)
        goto loc_1293f;
    ax = 0x6f6c;
    goto loc_12949;
loc_1293f:
    bh = 0x00;
    bl = al;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 5503);
loc_12949:
    push(dx);
    push(si);
    push(ax);
    push(dx);
    sub_129ae();
    si = pop();
    dx = pop();
    dx += 0x0006;
    cx = pop();
    if (--cx)
        goto loc_12926;
}
void sub_12959()
{
    memoryASet16(ds, 0x944e, ax);
    al = memoryAGet(ds, si);
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
    al = lodsb<DS_SI>();
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
    dx = pop();
    dx += 0x0006;
    si = pop();
    cx = pop();
    if (--cx)
        goto loc_12975;
}
void sub_129ae()
{
    push(bp);
    bp = sp;
    ax = memoryAGet16(ds, 0x94f0);
    es = ax;
    di = memoryAGet16(ds, 0x944e);
    di += memoryAGet16(ss, bp + 4 - 2);
    ax = memoryAGet16(ds, 0x94ea);
    push(ds);
    ds = ax;
    si = memoryAGet16(ss, bp + 6 - 2);
    cx = 0x000b;
loc_129c9:
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += 0x009a;
    si += 0x009a;
    if (--cx)
        goto loc_129c9;
    ds = pop();
    bp = pop();
    sp += 4;
}
void sub_129db()
{
    memoryASet16(ds, 0x9453, 0x0000);
loc_129e1:
    ax = memoryAGet16(ds, 0x9453);
    if (ax >= 0x000c)
        goto loc_12a39;
    sub_10541();
    if (al == 0x00)
        goto loc_12a39;
    if (al != 0x08)
        goto loc_12a0d;
    bx = memoryAGet16(ds, 0x9451);
    bx += memoryAGet16(ds, 0x9453);
    memoryASet(ds, bx, 0x2e);
    memoryASet16(ds, 0x9453, memoryAGet16(ds, 0x9453) - 1);
    if ((short)memoryAGet16(ds, 0x9453) >= 0)
        goto loc_12a0b;
    memoryASet16(ds, 0x9453, 0x0000);
loc_12a0b:
    goto loc_12a1b;
loc_12a0d:
    bx = memoryAGet16(ds, 0x9451);
    bx += memoryAGet16(ds, 0x9453);
    memoryASet(ds, bx, al);
    memoryASet16(ds, 0x9453, memoryAGet16(ds, 0x9453) + 1);
loc_12a1b:
    bx = memoryAGet16(ds, 0x9453);
    if (bx >= 0x000c)
        goto loc_12a2b;
    bx += memoryAGet16(ds, 0x9451);
    memoryASet(ds, bx, 0x5f);
loc_12a2b:
    sub_12a64();
    sub_13498();
    sub_10b8e();
    sub_13383();
    goto loc_129e1;
loc_12a39:
    bx = memoryAGet16(ds, 0x9453);
    if (bx >= 0x000c)
        goto loc_12a52;
    bx += memoryAGet16(ds, 0x9451);
    al = memoryAGet(ds, bx);
    if (al != 0x5f)
        goto loc_12a52;
    memoryASet(ds, bx, 0x2e);
    sub_12a64();
loc_12a52:
    di = 0x9455;
    dx = 0x1506;
    cx = 0x008c;
    sub_10674();
    memoryASet(ds, 0x9546, 0x00);
}
void sub_10541()
{
    cx = 0x4e20;
loc_10544:
    si = 0x8e8a;
    ah = 0x00;
    flags.direction = 0;
loc_1054a:
    al = lodsb<DS_SI>();
    if (al == 0x00)
        goto loc_10557;
    ah = 0x01;
    if (si != memoryAGet16(ds, 0x8f0b))
        goto loc_1055f;
loc_10557:
    if (si == 0x8f0a)
        goto loc_1055f;
    goto loc_1054a;
loc_1055f:
    if (si == 0x8f0a)
        goto loc_10578;
    memoryASet16(ds, 0x8f0b, si);
    si -= 0x8e8b;
    al = memoryAGet(ds, si + 90);
    if (al == 0x00)
        goto loc_10576;
    if ((char)al >= 0)
        return;
    al = 0x00;
loc_10575:
    return;
loc_10576:
    goto loc_10583;
loc_10578:
    if (ah != 0x00)
        goto loc_10583;
    memoryASet16(ds, 0x8f0b, 0x0000);
loc_10583:
    if (--cx)
        goto loc_10544;
    al = 0x00;
}
void sub_10674()
{
    push(di);
    push(cx);
    cx = 0x0000;
    ax = 0x3c00;
    interrupt(0x21);
    cx = pop();
    dx = pop();
    if (!flags.carry)
        goto loc_10683;
    return;
loc_10683:
    memoryASet16(ds, 0x8f1e, ax);
    bx = ax;
    ax = 0x4000;
    interrupt(0x21);
    if (!flags.carry)
        goto loc_10690;
    return;
loc_10690:
    ax = 0x3e00;
    bx = memoryAGet16(ds, 0x8f1e);
    interrupt(0x21);
}
void sub_12a64()
{
    si = memoryAGet16(ds, 0x9451);
    bl = memoryAGet(ds, 0x9450);
    bh = 0x00;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 435);
    memoryASet16(ds, 0x944e, ax);
    sub_1296f();
}
void sub_1296f()
{
    cx = 0x000c;
    dx = 0x0000;
loc_12975:
    push(cx);
    al = lodsb<DS_SI>();
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
    dx = pop();
    dx += 0x0006;
    si = pop();
    cx = pop();
    if (--cx)
        goto loc_12975;
}
void sub_12a7f()
{
    memoryASet(ds, 0x952e, 0x00);
    memoryASet(ds, 0x952f, 0x00);
    memoryASet(ds, 0x9530, 0x00);
    memoryASet(ds, 0x9531, 0x00);
    memoryASet(ds, 0x9532, 0x00);
    memoryASet(ds, 0x9533, 0x00);
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
    ax = pop();
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
        return;
    goto loc_12bea;
loc_12b58:
    return;
loc_12b59:
    memoryASet(ds, 0x952e, 0x01);
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
    memoryASet(ds, 0x952f, 0x01);
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
    memoryASet(ds, 0x9530, 0x01);
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
    memoryASet(ds, 0x9531, 0x01);
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
    memoryASet(ds, 0x9532, 0x01);
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
    memoryASet(ds, 0x9533, 0x01);
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
    ax = pop();
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
    ax = memoryAGet16(ds, bx + 5407);
    push(ax);
    ax = memoryAGet16(ds, bx + 5423);
    push(ax);
    ax = memoryAGet16(ds, bx + 5439);
    push(ax);
    ax = memoryAGet16(ds, bx + 5455);
    push(ax);
    ax = memoryAGet16(ds, bx + 5391);
    push(ax);
    sub_12cea();
}
void sub_12cc7()
{
    bl = al;
    bh = 0x00;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 5407);
    push(ax);
    ax = memoryAGet16(ds, bx + 5423);
    push(ax);
    ax = memoryAGet16(ds, bx + 5439);
    push(ax);
    ax = memoryAGet16(ds, bx + 5455);
    push(ax);
    ax = memoryAGet16(ds, bx + 5391);
    push(ax);
    sub_12cea();
}
void sub_12cea()
{
    push(bp);
    bp = sp;
    ax = 0xa000;
    es = ax;
    di = memoryAGet16(ss, bp + 10 - 2);
    bx = memoryAGet16(ss, bp + 4 - 2);
    bx = memoryAGet16(ds, bx + 38120);
    si = memoryAGet16(ss, bp + 12 - 2);
    push(ds);
    push(bx);
    dx = 0x03ce;
    ax = 0x0a05;
    out16(dx, ax);
    ax = 0x0007;
    out16(dx, ax);
    cx = memoryAGet16(ss, bp + 8 - 2);
    cx >>= 1;
    ah = 0x80;
    al = 0x08;
    ds = pop();
    bx = memoryAGet16(ss, bp + 6 - 2);
loc_12d19:
    push(ax);
    push(bx);
    push(cx);
    push(di);
    push(si);
loc_12d1e:
    bh = 0x22;
loc_12d20:
    bl = memoryAGet(ds, si);
    si++;
    if (bh != bl)
        goto loc_12d3d;
    ah >>= 1;
    if (ah)
        goto loc_12d32;
    ah = 0x40;
    di++;
    if (--cx)
        goto loc_12d20;
    goto loc_12d76;
loc_12d32:
    ah >>= 1;
    if (ah)
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
    out16(dx, ax);
    memoryASet(es, di, memoryAGet(es, di) & bl);
    memoryASet(es, di + 8192, memoryAGet(es, di + 8192) & bl);
loc_12d55:
    ah >>= 1;
    if (ah)
        goto loc_12d5c;
    ah = 0x80;
    di++;
loc_12d5c:
    bh &= 0x0f;
    if (bh == 0x02)
        goto loc_12d6d;
    out16(dx, ax);
    memoryASet(es, di, memoryAGet(es, di) & bh);
    memoryASet(es, di + 8192, memoryAGet(es, di + 8192) & bh);
loc_12d6d:
    ah >>= 1;
    if (ah)
        goto loc_12d74;
    ah = 0x80;
    di++;
loc_12d74:
    if (--cx)
        goto loc_12d1e;
loc_12d76:
    si = pop();
    si += 0x00a0;
    di = pop();
    di += 0x0028;
    di &= 0x7fff;
    cx = pop();
    bx = pop();
    ax = pop();
    bx--;
    if (bx)
        goto loc_12d19;
    ds = pop();
    ax = 0xff08;
    out16(dx, ax);
    ax = 0x0005;
    out16(dx, ax);
    ax = 0x0f07;
    out16(dx, ax);
    bp = pop();
    sp += 10;
}
void sub_12d9a()
{
    push(bp);
    bp = sp;
    ax = 0xa000;
    es = ax;
    di = memoryAGet16(ss, bp + 10 - 2);
    dx = 0x03ce;
    ax = memoryAGet16(ss, bp + 4 - 2);
    ah = al;
    al = 0x00;
    out16(dx, ax);
    ax = 0x0f01;
    out16(dx, ax);
    flags.direction = 0;
    bx = memoryAGet16(ss, bp + 6 - 2);
loc_12db8:
    push(di);
    cx = memoryAGet16(ss, bp + 8 - 2);
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    di = pop();
    push(di);
    di += 0x2000;
    cx = memoryAGet16(ss, bp + 8 - 2);
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    di = pop();
    di += 0x0028;
    bx--;
    if (bx)
        goto loc_12db8;
    ax = 0x0000;
    out16(dx, ax);
    al++;
    out16(dx, ax);
    bp = pop();
    sp += 8;
}
void sub_12ddc()
{
    bl = memoryAGet(ds, 0x94e4);
    bx &= 0x0003;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 6698);
    memoryASet16(ds, 0x94e2, ax);
    memoryASet(ds, 0x94e4, memoryAGet(ds, 0x94e4) + 1);
    memoryASet(ds, 0x9527, 0xff);
}
void sub_12df6()
{
    al = 0x00;
    memoryASet(ds, 0x94e5, al);
    memoryASet(ds, 0x94e6, al);
    memoryASet(ds, 0x94e7, al);
}
void sub_12e02()
{
    push(si);
    sub_11b80();
    sub_1309d();
    si = pop();
    ax = memoryAGet16(ds, 0x952a);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    bx = memoryAGet16(ds, 0x954c);
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
    memoryASet16(ds, 0x9522, ax);
    al = memoryAGet(ds, si + 22);
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
    memoryASet16(ds, 0x9520, ax);
    ax = memoryAGet16(ds, 0x951e);
    ax += memoryAGet16(ds, 0x9522);
    ax += memoryAGet16(ds, 0x9520);
    if (!ax)
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
    memoryASet16(ds, 0x951e, ax);
    ax = sar16(ax, 0x0001);
    ax = sar16(ax, 0x0001);
    memoryASet(ds, si + 22, memoryAGet(ds, si + 22) + al);
    al = memoryAGet(ds, si + 22);
    ax &= 0x007f;
    bx = ax;
    al = memoryAGet(ds, bx + 5749);
    true ? cbw() : cwde();
    ax <<= 1;
    ax += 0x0080;
    memoryASet16(ds, si + 5, ax);
    al = memoryAGet(ds, bx + 5877);
    true ? cbw() : cwde();
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
    div8(bl);
    ah = 0x00;
loc_12ebe:
    bx = pop();
    memoryASet16(ds, si + 7, ax);
    al = memoryAGet(ds, bx + 6005);
    memoryASet(ds, si + 4, al);
    bx = 0x1594;
    sub_12121();
    al = memoryAGet(ds, 0x94e6);
    memoryASet(ds, 0x94e7, al);
    al = memoryAGet(ds, 0x94e5);
    memoryASet(ds, 0x94e6, al);
    al = memoryAGet(ds, 0x1ba0);
    memoryASet(ds, 0x94e5, al);
    ax = memoryAGet16(ds, 0x954c);
    bl = memoryAGet(ds, 0x951a);
    if (!(al & 0x40))
        goto loc_12f02;
    if (bl != 0x02)
        goto loc_12f00;
    memoryASet(ds, 0x951a, 0x03);
    al = 0x02;
    sub_13840();
    memoryASet(ds, 0x951c, 0x02);
loc_12f00:
    goto loc_12f18;
loc_12f02:
    if (bl != 0x01)
        goto loc_12f0e;
    memoryASet(ds, 0x951a, 0x02);
    goto loc_12f18;
loc_12f0e:
    if (bl != 0x03)
        goto loc_12f18;
    memoryASet(ds, 0x951a, 0x00);
loc_12f18:
    ax = memoryAGet16(ds, 0x954c);
    bl = memoryAGet(ds, 0x951b);
    if (!(al & 0x20))
        goto loc_12f39;
    if (bl != 0x02)
        goto loc_12f37;
    memoryASet(ds, 0x951b, 0x03);
    al = 0x02;
    sub_13840();
    memoryASet(ds, 0x951c, 0x02);
loc_12f37:
    return;
loc_12f39:
    if (bl != 0x01)
        goto loc_12f45;
    memoryASet(ds, 0x951b, 0x02);
    return;
loc_12f45:
    if (bl != 0x03)
        return;
    memoryASet(ds, 0x951b, 0x00);
loc_12f4f:
    return;
}
void sub_12f50()
{
    al = memoryAGet(ds, si);
    if (al & 0x20)
        goto loc_12f5e;
    ah = memoryAGet(ds, 0x951a);
    al = 0xf8;
    goto loc_12f64;
loc_12f5e:
    ah = memoryAGet(ds, 0x951b);
    al = 0x08;
loc_12f64:
    if (ah == 0x03)
        goto loc_12f6e;
    if (ah != 0x00)
        goto loc_12f90;
loc_12f6e:
    memoryASet(ds, si, 0x00);
    si = 0x1ba1;
loc_12f74:
    al = memoryAGet(ds, si);
    if (al & 0x80)
        return;
    if (!(al & 0x01))
        goto loc_12f8a;
    al = memoryAGet(ds, si + 18);
    if (al != 0x0f)
        goto loc_12f8a;
    push(si);
    sub_13059();
    si = pop();
loc_12f8a:
    si += 0x0017;
    goto loc_12f74;
loc_12f8f:
    return;
loc_12f90:
    al += memoryAGet(ds, 0x94e7);
    ax &= 0x007f;
    bx = ax;
    al = memoryAGet(ds, bx + 5749);
    true ? cbw() : cwde();
    cx = ax;
    cx = sar16(cx, 0x0001);
    ax += cx;
    ax += 0x0080;
    memoryASet16(ds, si + 5, ax);
    al = memoryAGet(ds, bx + 5877);
    true ? cbw() : cwde();
    cx = ax;
    cx = sar16(cx, 0x0001);
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
    div8(bl);
    ah = 0x00;
loc_12fd0:
    bl = memoryAGet(ds, 0x1ba0);
    bx &= 0x007f;
    memoryASet16(ds, si + 7, ax);
    al = memoryAGet(ds, bx + 6290);
    memoryASet(ds, si + 4, al);
    bx = 0x1811;
    sub_12121();
}
void sub_12fe8()
{
    bx = memoryAGet16(ds, 0x9525);
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    bx &= 0x001f;
    al = memoryAGet(ds, bx + 6666);
    memoryASet(ds, 0x9549, al);
    al = memoryAGet(ds, bx + 6634);
    memoryASet(ds, si + 4, al);
    bx = 0x1929;
    sub_12121();
}
void sub_1300a()
{
    ax = memoryAGet16(ds, 0x9547);
    ax -= memoryAGet16(ds, si + 19);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    if (ax <= 0x002d)
        goto loc_1301f;
    memoryASet(ds, si, 0x00);
    return;
loc_1301f:
    push(ax);
    sub_13130();
    ax = pop();
    ax >>= 1;
    memoryASet(ds, si + 4, al);
    bx = ax;
    al = memoryAGet(ds, bx + 6810);
    memoryASet(ds, si + 2, al);
    bx = 0x1ac9;
    sub_12121();
    al = memoryAGet(ds, si + 2);
    if (al == 0x02)
        goto loc_13040;
    return;
loc_13040:
    bl = memoryAGet(ds, 0x1b8e);
    bh = 0x00;
    al = memoryAGet(ds, bx + 6133);
    if (al == memoryAGet(ds, si + 1))
        goto loc_13050;
    return;
loc_13050:
    al = 0x09;
    sub_13840();
    sub_13059();
}
void sub_13059()
{
    memoryASet(ds, si, 0x00);
    al = memoryAGet(ds, 0x951d);
    if (al != 0x40)
        goto loc_1306a;
    memoryASet16(ds, 0x9540, memoryAGet16(ds, 0x9540) + 0x0006);
    return;
loc_1306a:
    if (al != 0x80)
        goto loc_13075;
    memoryASet16(ds, 0x953c, memoryAGet16(ds, 0x953c) + 0x0004);
    return;
loc_13075:
    if (al != 0xc0)
        goto loc_13080;
    memoryASet16(ds, 0x9544, memoryAGet16(ds, 0x9544) + 0x0008);
    return;
loc_13080:
    sub_1268a();
loc_13083:
    return;
}
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
loc_1309c:
    return;
}
void sub_1309d()
{
    bx = memoryAGet16(ds, 0x952a);
    bx += 0x0007;
    bx >>= 1;
    bx >>= 1;
    bx >>= 1;
    bx += 0x0002;
    memoryASet16(ds, 0x9547, memoryAGet16(ds, 0x9547) + bx);
    ax = memoryAGet16(ds, 0x950f);
    ax += bx;
    if (ax <= 0x02e8)
        goto loc_130c4;
    ax = 0x0000;
    memoryASet16(ds, 0x953c, 0xffff);
loc_130c4:
    memoryASet16(ds, 0x950f, ax);
    ax = memoryAGet16(ds, 0x9547);
    ax -= 0x0380;
    if ((short)ax >= 0)
        goto loc_13124;
    ax = -ax;
    if (ax >= 0x0100)
        goto loc_130ed;
    memoryASet16(ds, 0x9525, ax);
    al = memoryAGet(ds, 0x9524);
    if (al != 0x00)
        goto loc_130eb;
    si = 0x1912;
    sub_10b58();
    memoryASet(ds, 0x9524, 0x01);
loc_130eb:
    goto loc_13122;
loc_130ed:
    ax = memoryAGet16(ds, 0x9547);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    if (al == memoryAGet(ds, 0x9527))
        goto loc_13122;
    memoryASet(ds, 0x9527, al);
    bl = al;
    bh = 0x00;
    bx += memoryAGet16(ds, 0x94e2);
    al = memoryAGet(ds, bx);
    if (al == 0x00)
        goto loc_13122;
    si = 0x1ab2;
    memoryASet(ds, si + 1, al);
    ax = memoryAGet16(ds, 0x9547);
    memoryASet16(ds, si + 19, ax);
    sub_10b58();
loc_13122:
    return;
loc_13124:
    memoryASet(ds, 0x94ff, 0x00);
    ax = memoryAGet16(ds, 0x950c);
    memoryASet16(ds, 0x9528, ax);
loc_1312f:
    return;
}
void sub_13130()
{
    bl = al;
    bh = 0x00;
    cl = memoryAGet(ds, bx + 6762);
    ch = 0x00;
    al = memoryAGet(ds, si + 1);
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
    memoryASet16(ds, si + 7, cx);
    return;
loc_13167:
    push(cx);
    sub_1315e();
    cx = pop();
    sub_13170();
    return;
loc_13170:
    cx += 0x0080;
    memoryASet16(ds, si + 5, cx);
    return;
loc_13178:
    push(cx);
    sub_13170();
    cx = pop();
    sub_13181();
    return;
loc_13181:
    cx += 0x006a;
    memoryASet16(ds, si + 7, cx);
    return;
loc_13188:
    push(cx);
    sub_13181();
    cx = pop();
    sub_13191();
    return;
loc_13191:
    cx = -cx;
    cx += 0x0080;
    memoryASet16(ds, si + 5, cx);
    return;
loc_1319b:
    push(cx);
    sub_13191();
    cx = pop();
    sub_1315e();
}
void sub_1315e()
{
    cx = -cx;
    cx += 0x006a;
    memoryASet16(ds, si + 7, cx);
}
void sub_13170()
{
    cx += 0x0080;
    memoryASet16(ds, si + 5, cx);
}
void sub_13181()
{
    cx += 0x006a;
    memoryASet16(ds, si + 7, cx);
}
void sub_13191()
{
    cx = -cx;
    cx += 0x0080;
    memoryASet16(ds, si + 5, cx);
}
void sub_131a4()
{
    ax = memoryAGet16(ds, 0x94f8);
    es = ax;
    di = 0x0144;
    bx = memoryAGet16(ds, 0x94f4);
    si = 0x0340;
    sub_131e7();
    ax = ~ax;
    ax &= 0x000f;
    ah = al;
    al = 0x01;
    dx = 0x03ce;
    out16(dx, ax);
    sub_13209();
    ah = al;
    al = 0x00;
    out16(dx, ax);
    push(ds);
    ds = bx;
    flags.direction = 0;
    cx = 0x00a0;
loc_131d2:
    push(cx);
    cx = 0x0020;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    di += 0x0008;
    cx = pop();
    if (--cx)
        goto loc_131d2;
    ds = pop();
    ax = 0x0000;
    out16(dx, ax);
    al++;
    out16(dx, ax);
}
void sub_131e7()
{
    al = memoryAGet(ds, 0x951d);
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
loc_13208:
    return;
}
void sub_13209()
{
    al = memoryAGet(ds, 0x951c);
    if (al != 0x00)
        goto loc_13215;
    ax = 0x0000;
    return;
loc_13215:
    if (al != 0x01)
        goto loc_13223;
    ax = 0x0007;
    memoryASet(ds, 0x951c, 0x00);
    return;
loc_13223:
    ax = 0x000f;
    memoryASet(ds, 0x951c, 0x01);
loc_1322b:
    return;
}
void sub_132fe()
{
    dx = 0x03ce;
    ax = 0x0105;
    out16(dx, ax);
    ax = memoryAGet16(ds, 0x94f8);
    es = ax;
    di = 0x0144;
    ax = memoryAGet16(ds, 0x9528);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    si = ax;
    push(ds);
    ax = 0xa800;
    ds = ax;
    flags.direction = 0;
    cx = 0x00a0;
loc_13326:
    push(cx);
    cx = 0x0020;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si &= 0x7fff;
    di += 0x0008;
    cx = pop();
    if (--cx)
        goto loc_13326;
    ds = pop();
    ax = 0x0005;
    out16(dx, ax);
}
void sub_1333c()
{
    ax = 0x000d;
    interrupt(0x10);
    ax = 0xa000;
    memoryASet16(ds, 0x94fa, ax);
    ax += 0x0200;
    memoryASet16(ds, 0x94f8, ax);
    ax = 0x0000;
    sub_133b3();
    ax = memoryAGet16(ds, 0x94f8);
    bx = memoryAGet16(ds, 0x94fa);
    memoryASet16(ds, 0x94f8, bx);
    memoryASet16(ds, 0x94fa, ax);
    sub_133d7();
    bx = memoryAGet16(ds, 0x94fa);
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    flags.interrupts = 0;
    dx = 0x03d4;
    ah = bh;
    al = 0x0c;
    out16(dx, ax);
    ah = bl;
    al++;
    out16(dx, ax);
    flags.interrupts = 1;
    sub_133d7();
}
void sub_13383()
{
    ax = memoryAGet16(ds, 0x94f8);
    bx = memoryAGet16(ds, 0x94fa);
    memoryASet16(ds, 0x94f8, bx);
    memoryASet16(ds, 0x94fa, ax);
    bx = memoryAGet16(ds, 0x94fa);
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    bx <<= 1;
    flags.interrupts = 0;
    dx = 0x03d4;
    ah = bh;
    al = 0x0c;
    out16(dx, ax);
    flags.interrupts = 1;
    dx = 0x03da;
loc_133aa:
    al = in8(dx);
    al &= 0x08;
    if (al)
        goto loc_133aa;
    sub_133d7();
}
void sub_133b3()
{
    push(ax);
    ax = memoryAGet16(ds, 0x94f8);
    es = ax;
    di = 0x0000;
    dx = 0x03ce;
    ax = pop();
    ah = al;
    al = 0x00;
    out16(dx, ax);
    ax = 0x0f01;
    out16(dx, ax);
    flags.direction = 0;
    cx = 0x0fa0;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    ax = 0x0000;
    out16(dx, ax);
    al++;
    out16(dx, ax);
}
void sub_133d7()
{
    dx = 0x03da;
loc_133da:
    al = in8(dx);
    al &= 0x08;
    if (!al)
        goto loc_133da;
loc_133df:
    al = in8(dx);
    al &= 0x08;
    if (al)
        goto loc_133df;
}
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
void sub_13439()
{
    ax = memoryAGet16(ds, 0x94f8);
    es = ax;
    di = 0x011c;
    ax = 0xffff;
    cx = 0x0010;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    di = 0x1a44;
    cx = 0x0010;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    di = 0x011b;
    al = 0x01;
    cx = 0x00a2;
loc_13459:
    memoryASet(es, di, al);
    di += 0x0028;
    if (--cx)
        goto loc_13459;
    di = 0x013c;
    al = 0x80;
    cx = 0x00a2;
loc_13469:
    memoryASet(es, di, al);
    di += 0x0028;
    if (--cx)
        goto loc_13469;
}
void sub_13472()
{
    si = 0x0000;
    bx = memoryAGet16(ds, 0x94f2);
    sub_133e5();
    sub_13383();
    si = 0x0000;
    bx = memoryAGet16(ds, 0x94f2);
    sub_133e5();
    ax = memoryAGet16(ds, 0x94f8);
    push(ax);
    ax = 0xa000;
    ax += 0x0400;
    push(ax);
    sub_13291();
}
void sub_13291()
{
    push(bp);
    bp = sp;
    ax = memoryAGet16(ss, bp + 4 - 2);
    es = ax;
    di = 0x0144;
    bx = memoryAGet16(ss, bp + 6 - 2);
    si = 0x0144;
    dx = 0x03ce;
    ax = 0x0105;
    out16(dx, ax);
    push(ds);
    ds = bx;
    flags.direction = 0;
    cx = 0x00a0;
loc_132b0:
    push(cx);
    cx = 0x0020;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si += 0x0008;
    di += 0x0008;
    cx = pop();
    if (--cx)
        goto loc_132b0;
    ds = pop();
    ax = 0x0005;
    out16(dx, ax);
    bp = pop();
    sp += 4;
}
void sub_133e5()
{
    ax = memoryAGet16(ds, 0x94f8);
    es = ax;
    di = 0x0000;
    dx = 0x03ce;
    ax = 0x0805;
    out16(dx, ax);
    ax = 0x0007;
    out16(dx, ax);
    dl = 0xc4;
    ax = 0x0802;
    push(ds);
    ds = bx;
loc_13400:
    out16(dx, ax);
    push(ax);
    push(di);
    cx = 0x1f40;
loc_13406:
    al = lodsb<DS_SI>();
    memoryASet(es, di, memoryAGet(es, di) & al);
    di++;
    if (--cx)
        goto loc_13406;
    di = pop();
    ax = pop();
    ah >>= 1;
    if (ah)
        goto loc_13400;
    ds = pop();
    ax = 0x0f02;
    out16(dx, ax);
    dl = 0xce;
    ax = 0x0005;
    out16(dx, ax);
    ax = 0x0f07;
    out16(dx, ax);
}
void sub_13498()
{
    ax = 0xa000;
    ax += 0x0400;
    push(ax);
    ax = memoryAGet16(ds, 0x94f8);
    push(ax);
    sub_13291();
}
void sub_134a8()
{
    di = 0x0000;
    ax = memoryAGet16(ds, 0x94f4);
    es = ax;
    ax = 0x0000;
    cx = 0x1000;
    flags.direction = 0;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
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
    ax = memoryAGet16(ds, 0x9547);
    ax &= 0x003f;
    memoryASet16(ds, 0x954e, ax);
    bx = ax;
    ax += 0x0040;
    push(ax);
    al = memoryAGet(ds, bx + 8156);
    ah = 0x00;
    push(ax);
    sub_135bc();
    ax = memoryAGet16(ds, 0x954e);
    if (ax <= 0x000c)
        goto loc_13527;
    return;
loc_13527:
    bx = memoryAGet16(ds, 0x954e);
    al = memoryAGet(ds, bx + 8220);
    ah = 0x00;
    ax += 0x0080;
    push(ax);
    ax = 0x0000;
    push(ax);
    ax = 0x00ff;
    push(ax);
    al = memoryAGet(ds, bx + 8233);
    ah = 0x00;
    ax = -ax;
    ax += 0x007f;
    push(ax);
    sub_136d4();
    bx = memoryAGet16(ds, 0x954e);
    al = memoryAGet(ds, bx + 8220);
    ah = 0x00;
    ax = -ax;
    ax += 0x007f;
    push(ax);
    ax = 0x0000;
    push(ax);
    ax = 0x0000;
    push(ax);
    al = memoryAGet(ds, bx + 8233);
    ah = 0x00;
    ax = -ax;
    ax += 0x007f;
    push(ax);
    sub_136d4();
    bx = memoryAGet16(ds, 0x954e);
    al = memoryAGet(ds, bx + 8220);
    ah = 0x00;
    ax += 0x0080;
    push(ax);
    ax = 0x00ff;
    push(ax);
    ax = 0x00ff;
    push(ax);
    al = memoryAGet(ds, bx + 8233);
    ah = 0x00;
    ax += 0x0080;
    push(ax);
    sub_136d4();
    bx = memoryAGet16(ds, 0x954e);
    al = memoryAGet(ds, bx + 8220);
    ah = 0x00;
    ax = -ax;
    ax += 0x007f;
    push(ax);
    ax = 0x00ff;
    push(ax);
    ax = 0x0000;
    push(ax);
    al = memoryAGet(ds, bx + 8233);
    ah = 0x00;
    ax += 0x0080;
    push(ax);
    sub_136d4();
}
void sub_135bc()
{
    push(bp);
    bp = sp;
loc_135bf:
    ax = 0x007f;
    ax -= memoryAGet16(ss, bp + 4 - 2);
    push(ax);
    ax = 0x007f;
    ax -= memoryAGet16(ss, bp + 6 - 2);
    push(ax);
    ax = 0x0080;
    ax += memoryAGet16(ss, bp + 4 - 2);
    push(ax);
    ax = 0x007f;
    ax -= memoryAGet16(ss, bp + 6 - 2);
    push(ax);
    sub_136d4();
    ax = 0x0080;
    ax += memoryAGet16(ss, bp + 4 - 2);
    push(ax);
    ax = 0x007f;
    ax -= memoryAGet16(ss, bp + 6 - 2);
    push(ax);
    ax = 0x0080;
    ax += memoryAGet16(ss, bp + 6 - 2);
    push(ax);
    ax = 0x007f;
    ax -= memoryAGet16(ss, bp + 4 - 2);
    push(ax);
    sub_136d4();
    ax = 0x0080;
    ax += memoryAGet16(ss, bp + 6 - 2);
    push(ax);
    ax = 0x007f;
    ax -= memoryAGet16(ss, bp + 4 - 2);
    push(ax);
    ax = 0x0080;
    ax += memoryAGet16(ss, bp + 6 - 2);
    push(ax);
    ax = 0x0080;
    ax += memoryAGet16(ss, bp + 4 - 2);
    push(ax);
    sub_136d4();
    ax = 0x0080;
    ax += memoryAGet16(ss, bp + 4 - 2);
    push(ax);
    ax = 0x0080;
    ax += memoryAGet16(ss, bp + 6 - 2);
    push(ax);
    ax = 0x0080;
    ax += memoryAGet16(ss, bp + 6 - 2);
    push(ax);
    ax = 0x0080;
    ax += memoryAGet16(ss, bp + 4 - 2);
    push(ax);
    sub_136d4();
    ax = 0x007f;
    ax -= memoryAGet16(ss, bp + 4 - 2);
    push(ax);
    ax = 0x0080;
    ax += memoryAGet16(ss, bp + 6 - 2);
    push(ax);
    ax = 0x0080;
    ax += memoryAGet16(ss, bp + 4 - 2);
    push(ax);
    ax = 0x0080;
    ax += memoryAGet16(ss, bp + 6 - 2);
    push(ax);
    sub_136d4();
    ax = 0x007f;
    ax -= memoryAGet16(ss, bp + 6 - 2);
    push(ax);
    ax = 0x0080;
    ax += memoryAGet16(ss, bp + 4 - 2);
    push(ax);
    ax = 0x007f;
    ax -= memoryAGet16(ss, bp + 4 - 2);
    push(ax);
    ax = 0x0080;
    ax += memoryAGet16(ss, bp + 6 - 2);
    push(ax);
    sub_136d4();
    ax = 0x007f;
    ax -= memoryAGet16(ss, bp + 6 - 2);
    push(ax);
    ax = 0x007f;
    ax -= memoryAGet16(ss, bp + 4 - 2);
    push(ax);
    ax = 0x007f;
    ax -= memoryAGet16(ss, bp + 6 - 2);
    push(ax);
    ax = 0x0080;
    ax += memoryAGet16(ss, bp + 4 - 2);
    push(ax);
    sub_136d4();
    ax = 0x007f;
    ax -= memoryAGet16(ss, bp + 6 - 2);
    push(ax);
    ax = 0x007f;
    ax -= memoryAGet16(ss, bp + 4 - 2);
    push(ax);
    ax = 0x007f;
    ax -= memoryAGet16(ss, bp + 4 - 2);
    push(ax);
    ax = 0x007f;
    ax -= memoryAGet16(ss, bp + 6 - 2);
    push(ax);
    sub_136d4();
    ax = memoryAGet16(ss, bp + 6 - 2);
    ax >>= 1;
    if (al <= memoryAGet(ds, 0x9549))
        goto loc_136d0;
    memoryASet16(ss, bp + 6 - 2, ax);
    ax = memoryAGet16(ss, bp + 4 - 2);
    ax >>= 1;
    memoryASet16(ss, bp + 4 - 2, ax);
    goto loc_135bf;
loc_136d0:
    bp = pop();
    sp += 4;
}
void sub_136d4()
{
    push(bp);
    bp = sp;
    sp -= 0x000a;
    ax = memoryAGet16(ds, 0x94f4);
    es = ax;
    ax = memoryAGet16(ss, bp + 8 - 2);
    if (ax == 0x0000)
        goto loc_136fa;
    bx = ax;
    ax <<= 1;
    ax <<= 1;
    ax += bx;
    ax <<= 1;
    ax += 0x0005;
    bl = 0x0c;
    div8(bl);
    ah = 0x00;
loc_136fa:
    memoryASet16(ss, bp + 8 - 2, ax);
    ax = memoryAGet16(ss, bp + 4 - 2);
    if (ax == 0x0000)
        goto loc_13718;
    bx = ax;
    ax <<= 1;
    ax <<= 1;
    ax += bx;
    ax <<= 1;
    ax += 0x0005;
    bl = 0x0c;
    div8(bl);
    ah = 0x00;
loc_13718:
    memoryASet16(ss, bp + 4 - 2, ax);
    ax = memoryAGet16(ss, bp + 10 - 2);
    bx = memoryAGet16(ss, bp + 6 - 2);
    if (bx >= ax)
        goto loc_13737;
    memoryASet16(ss, bp + 10 - 2, bx);
    memoryASet16(ss, bp + 6 - 2, ax);
    ax = memoryAGet16(ss, bp + 8 - 2);
    bx = memoryAGet16(ss, bp + 4 - 2);
    memoryASet16(ss, bp + 8 - 2, bx);
    memoryASet16(ss, bp + 4 - 2, ax);
loc_13737:
    ax = memoryAGet16(ss, bp + 6 - 2);
    ax -= memoryAGet16(ss, bp + 10 - 2);
    memoryASet16(ss, bp - 2 - 2, ax);
    ax = memoryAGet16(ss, bp + 4 - 2);
    ax -= memoryAGet16(ss, bp + 8 - 2);
    if ((short)ax >= 0)
        goto loc_13751;
    ax = -ax;
    memoryASet16(ss, bp - 10 - 2, 0xffe0);
    goto loc_13756;
loc_13751:
    memoryASet16(ss, bp - 10 - 2, 0x0020);
loc_13756:
    memoryASet16(ss, bp - 4 - 2, ax);
    cx = memoryAGet16(ss, bp - 2 - 2);
    if (cx == 0x0000)
        goto loc_137db;
    if (ax != 0x0000)
        goto loc_13769;
    goto loc_137ed;
loc_13769:
    if (ax >= memoryAGet16(ss, bp - 2 - 2))
        goto loc_137a4;
    ax = memoryAGet16(ss, bp - 2 - 2);
    ax >>= 1;
    memoryASet16(ss, bp - 6 - 2, ax);
    sub_13801();
    cx = memoryAGet16(ss, bp - 2 - 2);
loc_1377c:
    al >>= 1;
    if (al)
        goto loc_13783;
    al = 0x80;
    di++;
loc_13783:
    bx = memoryAGet16(ss, bp - 6 - 2);
    bx += memoryAGet16(ss, bp - 4 - 2);
    memoryASet16(ss, bp - 6 - 2, bx);
    if (bx <= memoryAGet16(ss, bp - 2 - 2))
        goto loc_1379d;
    bx -= memoryAGet16(ss, bp - 2 - 2);
    memoryASet16(ss, bp - 6 - 2, bx);
    bx = memoryAGet16(ss, bp - 10 - 2);
    di += memoryAGet16(ss, bp - 10 - 2);
loc_1379d:
    memoryASet(es, di, memoryAGet(es, di) | al);
    if (--cx)
        goto loc_1377c;
    goto loc_137d5;
loc_137a4:
    ax = memoryAGet16(ss, bp - 4 - 2);
    ax >>= 1;
    memoryASet16(ss, bp - 6 - 2, ax);
    sub_13801();
    cx = memoryAGet16(ss, bp - 4 - 2);
loc_137b2:
    di += memoryAGet16(ss, bp - 10 - 2);
    bx = memoryAGet16(ss, bp - 6 - 2);
    bx += memoryAGet16(ss, bp - 2 - 2);
    memoryASet16(ss, bp - 6 - 2, bx);
    if (bx <= memoryAGet16(ss, bp - 4 - 2))
        goto loc_137d0;
    bx -= memoryAGet16(ss, bp - 4 - 2);
    memoryASet16(ss, bp - 6 - 2, bx);
    al >>= 1;
    if (al)
        goto loc_137d0;
    al = 0x80;
    di++;
loc_137d0:
    memoryASet(es, di, memoryAGet(es, di) | al);
    if (--cx)
        goto loc_137b2;
loc_137d5:
    sp = bp;
    bp = pop();
    sp += 8;
  return;
loc_137db:
    sub_13801();
    cx = memoryAGet16(ss, bp - 4 - 2);
    if (cx==0)
        goto loc_137d5;
loc_137e3:
    di += memoryAGet16(ss, bp - 10 - 2);
    memoryASet(es, di, memoryAGet(es, di) | al);
    if (--cx)
        goto loc_137e3;
    goto loc_137d5;
loc_137ed:
    sub_13801();
    cx = memoryAGet16(ss, bp - 2 - 2);
loc_137f3:
    al >>= 1;
    if (al)
        goto loc_137fa;
    al = 0x80;
    di++;
loc_137fa:
    memoryASet(es, di, memoryAGet(es, di) | al);
    if (--cx)
        goto loc_137f3;
    goto loc_137d5;
}
void sub_13801()
{
    ax = memoryAGet16(ss, bp + 8 - 2);
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    ax <<= 1;
    di = ax;
    ax = memoryAGet16(ss, bp + 10 - 2);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    di += ax;
    cx = memoryAGet16(ss, bp + 10 - 2);
    cx &= 0x0007;
    al = 0x80;
    al >>= cl;
    memoryASet(es, di, memoryAGet(es, di) | al);
}
void sub_1382a()
{
    al = 0x00;
    memoryASet(ds, 0x9550, al);
    memoryASet(ds, 0x9551, al);
    memoryASet(ds, 0x9552, al);
    memoryASet(ds, 0x9506, 0x01);
    memoryASet(ds, 0x9505, 0x00);
}
void sub_13840()
{
    ah = memoryAGet(ds, 0x955e);
    if (ah == 0x00)
        goto loc_1384a;
    return;
loc_1384a:
    ah = memoryAGet(ds, 0x9506);
    if (ah != 0x00)
        goto loc_13854;
    return;
loc_13854:
    ah = memoryAGet(ds, 0x9550);
    if (ah != 0x00)
        goto loc_13866;
    push(bx);
    memoryASet(ds, 0x9550, al);
    sub_13914();
    bx = pop();
    return;
loc_13866:
    ah = memoryAGet(ds, 0x9551);
    if (ah != 0x00)
        goto loc_13873;
    memoryASet(ds, 0x9551, al);
    return;
loc_13873:
    if (al <= memoryAGet(ds, 0x9552))
        return;
    memoryASet(ds, 0x9552, al);
loc_1387c:
    return;
}
void sub_13914()
{
    al--;
    bl = al;
    bh = 0x00;
    bx <<= 1;
    bx = memoryAGet16(ds, bx + 35812);
    al = memoryAGet(ds, bx + 1);
    memoryASet(ds, 0x9557, al);
    if (bx != 0x8c2c)
        goto loc_13941;
    ax = memoryAGet16(ds, 0x9536);
    ah = al;
    al = 0x00;
    ax <<= 1;
    ax <<= 1;
    ax = -ax;
    ax += 0x1f40;
    memoryASet16(ds, 0x8c2e, ax);
    goto loc_13966;
loc_13941:
    if (bx != 0x8c32)
        goto loc_13966;
    al = memoryAGet(ds, 0x1ba0);
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
    memoryASet16(ds, 0x8c34, ax);
loc_13966:
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, 0x9558, ax);
    ax = memoryAGet16(ds, bx + 4);
    memoryASet16(ds, 0x955a, ax);
    bl = memoryAGet(ds, bx);
    memoryASet(ds, 0x9553, bl);
    if ((char)bl <= (char)0x00)
        goto loc_1398f;
    bl--;
    bh = 0x00;
    bx <<= 1;
    ax = memoryAGet16(ds, bx + 35932);
    memoryASet16(ds, 0x9555, ax);
    memoryASet(ds, 0x9554, 0x00);
loc_1398f:
    al = 0xb6;
    out8(0x43, al);
    ax = memoryAGet16(ds, 0x9558);
    out8(0x42, al);
    al = ah;
    out8(0x42, al);
    al = in8(0x61);
    al |= 0x03;
    out8(0x61, al);
}
void sub_139a3()
{
    al = 0x00;
    memoryASet(ds, 0x9550, al);
    memoryASet(ds, 0x9551, al);
    memoryASet(ds, 0x9552, al);
    memoryASet(ds, 0x9557, al);
    al = in8(0x61);
    al &= 0xfc;
    out8(0x61, al);
}
void sub_139b8()
{
    memoryASet(ds, 0x9561, 0x00);
    memoryASet16(ds, 0x955f, 0x0000);
    memoryASet(ds, 0x955e, 0x01);
    al = memoryAGet(ds, 0x9546);
    if (al != 0x00)
        goto loc_139d4;
    ax = 0x8dec;
    goto loc_139d7;
loc_139d4:
    ax = 0x8d4c;
loc_139d7:
    memoryASet16(ds, 0x9562, ax);
}
