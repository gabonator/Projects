#if 0
#include "cico32.h"

void fixReloc(uint16_t seg);
void sub_341b0();

void start()
{
    headerSize = 0x0130;
    loadAddress = 0x1000;
    endAddress = 0x3700;
    cs = 0x341b;
    ds = 0x340b;
    es = 0x340b;
    ss = 0x1000;
    sp = 0x0400;
    load("", "rick1.exe", 159936);
    fixReloc(cs);
    sub_341b0();
}


void sub_341b0();
void sub_34356();
void sub_343b0();
void sub_343fa();
void sub_34420();
void sub_3442b();
void sub_34442();
void sub_34470();
void sub_3447f();
void sub_344b9();
void sub_344c4();
void sub_344e7();
void sub_345e3();
void sub_345f5();
void sub_345fd();
void sub_34720();
void sub_34802();
void sub_34811();
void sub_348a8();
void sub_348e6();
void sub_34936();
void sub_34947();
void sub_3496b();
void sub_34986();
void sub_34a2e();
void sub_34d08();
void sub_34dc8();
void sub_34e4c();
void sub_34ecd();
void sub_34edf();
void sub_34f00();
void sub_34f2c();
void sub_34fe7();
void sub_3505d();
void sub_3508b();
void sub_350da();
void sub_3510e();
void sub_35131();
void sub_3519f();
void sub_3520a();
void sub_3523f();
void sub_35262();
void sub_352aa();
void sub_352c5();
void sub_352ea();
void sub_3536c();
void sub_35445();
void sub_3545e();
void sub_3546c();
void sub_354c7();
void sub_354fb();
void sub_3555c();
void sub_3559d();
void sub_356ec();
void sub_35b7f();
void sub_35c76();
void sub_35ce3();
void sub_35d5e();
void sub_35dc5();
void sub_35e32();
void sub_35e63();
void sub_35e97();
void sub_35ee0();
void sub_35f0e();
void sub_35f4e();
void sub_35f5c();
void sub_35f97();
void sub_35fbe();
void sub_36026();
void sub_3612b();
void sub_36139();
void sub_36150();
void sub_36161();
void sub_3619f();
void sub_361e8();
void sub_36239();
void sub_36395();
void sub_363b5();
void sub_363f1();
void sub_36413();
void sub_3653b();
void sub_36742();
void sub_3680a();
void sub_36819();
void sub_36853();
void sub_36a8b();
void sub_36ce2();
void sub_36cfd();
void sub_36d04();
void sub_36d18();

void sub_341b0()
{
    sub_34720();
    sub_344c4();
    ax = 0x1040;
    ds = ax;
loc_341bb:
    sub_345e3();
    if (flags.zero)
        goto loc_341bb;
    sub_35ce3();
loc_341c3:
    sub_345e3();
    if (flags.zero)
        goto loc_341c3;
    ax = 0x1040;
    ds = ax;
    es = ax;
    bx = 0x88f0;
    cx = 0x020b;
loc_341d5:
    memoryASet(ds, bx, memoryAGet(ds, bx) & 0x7f);
    bx += 0x0005;
    if (--cx)
        goto loc_341d5;
    memoryASet(ds, 0x7d90, 0x00);
    memoryASet(ds, 0x7d91, 0x00);
    memoryASet(ds, 0x7e46, 0x06);
    memoryASet(ds, 0x7e45, 0x06);
    memoryASet(ds, 0x7e47, 0x06);
    push(ds);
    ax = 0x1fc1;
    ds = ax;
    memoryASet16(ds, 0x490e, 0x3030);
    memoryASet16(ds, 0x4910, 0x3030);
    memoryASet16(ds, 0x4912, 0x3030);
    ds = pop();
    sub_35c76();
    sub_34947();
    al = memoryAGet(ds, 0x80ef);
    memoryASet(ds, 0x7e80, al);
    ax = memoryAGet16(ds, 0x80f1);
    memoryASet16(ds, 0x7e82, ax);
    memoryASet(ds, 0x7e8c, 0x18);
    memoryASet(ds, 0x7e8e, 0x15);
    di = memoryAGet16(ds, 0x80f3);
    bx = memoryAGet16(ds, 0x80f5);
    sub_34fe7();
    al = memoryAGet(ds, 0x7e46);
    if (al)
        goto loc_34277;
loc_34240:
    sub_34986();
loc_34243:
    sub_36cfd();
    ax = 0x1fc1;
    ds = ax;
    ax = 0xb800;
    es = ax;
    bx = 0x4864;
    memoryASet16(ds, 0x48ca, 0xaaaa);
    di = 0x0c8f;
    sub_3612b();
    ax = 0x1040;
    ds = ax;
loc_34264:
    sub_345e3();
    if (!flags.zero)
        goto loc_34264;
loc_34269:
    sub_345e3();
    if (flags.zero)
        goto loc_34269;
    sub_3680a();
    sub_361e8();
    goto loc_341bb;
loc_34277:
    memoryASet(ds, 0x7d92, 0x00);
    memoryASet(ds, 0x7d75, 0x00);
    memoryASet(ds, 0x7e7e, 0x01);
    memoryASet(ds, 0x7e45, 0x06);
    memoryASet(ds, 0x7e47, 0x06);
    sub_34f00();
    sub_344b9();
loc_34296:
    sub_345fd();
    if (flags.zero)
        goto loc_34240;
    if (memoryAGet(ds, 0x7e43) != 0x01)
        goto loc_342a5;
    goto loc_34348;
loc_342a5:
//    ah = 0x01;
//    interrupt(0x16);
//    if (!flags.zero)
//        goto loc_342ae;
loc_342ae:
//    ah = 0x02;
//    interrupt(0x16);
//    if (!flags.zero)
//        goto loc_342b7;
loc_342b7:
    sub_363f1();
    sub_34420();
    sub_34356();
    sub_345f5();
    if (!flags.zero)
        goto loc_342da;
    sub_36cfd();
loc_342cb:
    sub_345f5();
    if (flags.zero)
        goto loc_342cb;
loc_342d0:
    sub_345f5();
    if (!flags.zero)
        goto loc_342d0;
loc_342d5:
    sub_345f5();
    if (flags.zero)
        goto loc_342d5;
loc_342da:
    al = memoryAGet(ds, 0x7d92);
    if (!al)
        goto loc_342f3;
    al = memoryAGet(ds, 0x7e46);
    al--;
    memoryASet(ds, 0x7e46, al);
    if (al)
        goto loc_342f1;
    goto loc_34240;
loc_342f1:
    goto loc_34277;
loc_342f3:
    al = memoryAGet(ds, 0x7d76);
    if (!al)
        goto loc_3430c;
    sub_34f2c();
    al = memoryAGet(ds, 0x7d91);
    if (!al)
        goto loc_3430a;
    goto loc_34243;
loc_3430a:
    goto loc_34296;
loc_3430c:
    sync();
    sub_34986();
    sub_343b0();
    sub_36ce2();
    sub_3496b();
    sub_36ce2();
    sub_3496b();
    sub_34dc8();
    al = memoryAGet(ds, 0x7d75);
    if (al)
        goto loc_34345;
    al = memoryAGet(ds, 0x7e82);
    if (al < 0xcc)
        goto loc_3433b;
    sub_35131();
    goto loc_34345;
  // gap 1 bytes
loc_3433b:
    if (al >= 0x60)
        goto loc_34345;
    sub_3519f();
loc_34345:
    goto loc_34296;
loc_34348:
    sub_34802();
    sub_344e7();
    sub_36cfd();
    ax = 0x4c00;
    interrupt(0x21);
    stop("terminating");
}
void sub_34356()
{
    if (memoryAGet(ds, 0x7d8f) != 0x00)
        goto loc_34361;
    return;
loc_34361:
    memoryASet(ds, 0x7d95, memoryAGet(ds, 0x7d95) - 1);
    if (memoryAGet(ds, 0x7d95) == 0x00)
        goto loc_34370;
    return;
loc_34370:
    memoryASet(ds, 0x7d95, 0x1e);
    push(ds);
    ax = 0x1fc1;
    ds = ax;
    if (memoryAGet16(ds, 0x491c) != 0x0000)
        goto loc_3439b;
    if (memoryAGet16(ds, 0x491e) != 0x0000)
        goto loc_3439b;
    if (memoryAGet(ds, 0x4920) != 0x00)
        goto loc_3439b;
    ds = pop();
    return;
loc_3439b:
    bx = 0x491f;
loc_3439e:
    memoryASet(ds, bx, memoryAGet(ds, bx) - 1);
    if (!(memoryAGet(ds, bx) & 0x80))
        goto loc_343ae;
    memoryASet(ds, bx, 0x09);
    bx--;
    goto loc_3439e;
loc_343ae:
    ds = pop();
}
void sub_343b0()
{
    al = memoryAGet(ds, 0x7e45);
    if (al == memoryAGet(ds, 0x7d93))
        goto loc_343d4;
    memoryASet(ds, 0x7d93, al);
    memoryASet16(ds, 0x7337, 0x0101);
    memoryASet16(ds, 0x7339, 0x0101);
    memoryASet16(ds, 0x733b, 0x0101);
    sub_34470();
loc_343d4:
    al = memoryAGet(ds, 0x7e47);
    if (al != memoryAGet(ds, 0x7d94))
        goto loc_343e1;
    return;
loc_343e1:
    memoryASet(ds, 0x7d94, al);
    memoryASet16(ds, 0x733f, 0x0101);
    memoryASet16(ds, 0x7341, 0x0101);
    memoryASet16(ds, 0x7343, 0x0101);
    sub_3447f();
}
void sub_343fa()
{
    push(bx);
    push(cx);
    bx = memoryAGet16(ds, 0x7e48);
    bx += memoryAGet16(ds, 0x7e4a);
    bx += 0x000d;
    cx = memoryAGet16(ds, 0x7e4c);
    bx += cx;
    al = 0;
    al ^= bl;
    al ^= ch;
    al ^= cl;
    al ^= bh;
    bl = al;
    memoryASet16(ds, 0x7e48, bx);
    cx = pop();
    bx = pop();
}
void sub_34420()
{
    flags.carry = (memoryAGet16(ds, 0x7e4a) + 0x0001) >= 0x10000;
    memoryASet16(ds, 0x7e4a, memoryAGet16(ds, 0x7e4a) + 0x0001);
    memoryASet16(ds, 0x7e4c, memoryAGet16(ds, 0x7e4c) + (0x0000 + flags.carry));
}
void sub_3442b()
{
    push(ds);
    di = 0x0145;
    ax = 0x1fc1;
    ds = ax;
    ax = 0xb800;
    es = ax;
    bx = 0x490e;
    sub_36139();
    ds = pop();
}
void sub_34442()
{
    goto loc_34442;
loc_3442b:
    push(ds);
    di = 0x0145;
    ax = 0x1fc1;
    ds = ax;
    ax = 0xb800;
    es = ax;
    bx = 0x490e;
    sub_36139();
    ds = pop();
    return;
loc_34442:
    push(ds);
    ax = 0x1fc1;
    ds = ax;
    si += 0x0004;
    di = 0x4913;
    cx = 0x0005;
    flags.carry = 0;
loc_34452:
    al = memoryAGet(ds, di);
    al += memoryAGet(ds, si) + flags.carry;
    flags.carry = al < 0x3a;
    if (flags.carry)
        goto loc_34460;
    al -= 0x0a;
    flags.carry = 0;
loc_34460:
    flags.carry = !flags.carry;
    memoryASet(ds, di, al);
    di--;
    si--;
    if (--cx)
        goto loc_34452;
    al = memoryAGet(ds, di);
    al += 0x00 + flags.carry;
    memoryASet(ds, di, al);
    ds = pop();
    goto loc_3442b;
}
void sub_34470()
{
    cl = memoryAGet(ds, 0x7e45);
    ch = 0;
    al = 0x01;
    di = 0x014d;
    goto loc_3449a;
  // gap 28 bytes
loc_3449a:
    if (cx != 0x0000)
        goto loc_344a3;
    return;
loc_344a3:
    push(ds);
    bx = 0x1fc1;
    ds = bx;
    bx = 0xb800;
    es = bx;
loc_344ae:
    push(cx);
    push(ax);
    sub_36150();
    ax = pop();
    cx = pop();
    if (--cx)
        goto loc_344ae;
    ds = pop();
}
void sub_3447f()
{
    cl = memoryAGet(ds, 0x7e47);
    ch = 0;
    al = 0x02;
    di = 0x0155;
    goto loc_3449a;
  // gap 13 bytes
loc_3449a:
    if (cx != 0x0000)
        goto loc_344a3;
    return;
loc_344a3:
    push(ds);
    bx = 0x1fc1;
    ds = bx;
    bx = 0xb800;
    es = bx;
loc_344ae:
    push(cx);
    push(ax);
    sub_36150();
    ax = pop();
    cx = pop();
    if (--cx)
        goto loc_344ae;
    ds = pop();
}
void sub_344b9()
{
    goto loc_344b9;
loc_3448e:
    cl = memoryAGet(ds, 0x7e46);
    ch = 0;
    al = 0x03;
    di = 0x015d;
    if (cx != 0x0000)
        goto loc_344a3;
    return;
loc_344a3:
    push(ds);
    bx = 0x1fc1;
    ds = bx;
    bx = 0xb800;
    es = bx;
loc_344ae:
    push(cx);
    push(ax);
    sub_36150();
    ax = pop();
    cx = pop();
    if (--cx)
        goto loc_344ae;
    ds = pop();
    return;
loc_344b9:
    sub_3442b();
    sub_34470();
    sub_3447f();
    goto loc_3448e;
}
void sub_344c4()
{
    push(ds);
    ah = 0x35;
    al = 0x09;
    interrupt(0x21);
    ax = 0x1040;
    ds = ax;
    memoryASet16(ds, 0x7e3e, es);
    memoryASet16(ds, 0x7e40, bx);
    ah = 0x25;
    al = 0x09;
    dx = cs;
    ds = dx;
    dx = 0x0348;
    interrupt(0x21);
    ds = pop();
}
void sub_344e7()
{
    push(ds);
    dx = memoryAGet16(ds, 0x7e40);
    ds = memoryAGet16(ds, 0x7e3e);
    ah = 0x25;
    al = 0x09;
    interrupt(0x21);
    ds = pop();
}
void sub_345e3() // +returnZero
{
    sync();
    al = memoryAGet(ds, 0x7e44);
    al &= 0x10;
    if (!al)
        goto loc_345f0;
    flags.zero = 1;
    al = 0;
    return;
loc_345f0:
    al = 0;
    al--;
    flags.zero = !al;
}
void sub_345f5() // +returnZero
{
    al = memoryAGet(ds, 0x7e44);
    al &= 0x80;
    flags.zero = al == 0x80;
}
void sub_345fd() // +returnZero
{
    al = memoryAGet(ds, 0x7e44);
    al &= 0x40;
    flags.zero = al == 0x40;
}
void sub_34720()
{
loc_34720:
    ah = 0x4a;
    bx = 0x3000;
    interrupt(0x21);
    ax = 0x1040;
    ds = ax;
    es = ax;
    ax = 0x2455;
    memoryASet16(ds, 0x9661, ax);
    ah = 0x48;
    bx = 0x0fff;
    interrupt(0x21);
    if (flags.carry)
        goto loc_34720;
    memoryASet16(ds, 0x9663, ax);
    ah = 0x48;
    bx = 0x0fff;
    interrupt(0x21);
    if (flags.carry)
        goto loc_34720;
    memoryASet16(ds, 0x9665, ax);
    ah = 0x48;
    bx = 0x0fff;
    interrupt(0x21);
    if (flags.carry)
        goto loc_34720;
    memoryASet16(ds, 0x9667, ax);
    ah = 0x0f;
    interrupt(0x10);
    memoryASet(ds, 0x7e42, al);
    ax = 0x000d;
    interrupt(0x10);
    ax = 0x1040;
    ds = ax;
    sub_348a8();
    ax = 0x1fc1;
    ds = ax;
    ax = 0x1040;
    es = ax;
    si = 0x0000;
    di = 0x223a;
    cx = 0x2000;
    flags.direction = 0;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    dx = 0x2000;
    sub_34811();
    ax = 0x1fc1;
    ds = ax;
    ax = 0x1040;
    es = ax;
    si = 0x2000;
    di = 0x223a;
    cx = 0x2000;
    flags.direction = 0;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    dx = 0x2800;
    sub_34811();
    ax = 0x1040;
    ds = ax;
    es = ax;
    si = 0x9810;
    di = 0x223a;
    cx = 0x2000;
    flags.direction = 0;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    dx = 0x3000;
    sub_34811();
    ax = 0x1040;
    ds = ax;
    es = ax;
    si = 0xd810;
    di = 0x223a;
    cx = 0x2000;
    flags.direction = 0;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    dx = 0x3800;
    sub_34811();
    ax = 0x1fc1;
    es = ax;
    memoryASet(ds, 0x7d90, 0x00);
    sub_34936();
    ax = 0x9810;
    memoryASet16(ds, 0x7d5e, ax);
    ax = 0x3000;
    memoryASet16(ds, 0x971a, ax);
    dx = 0x03ce;
    ax = 0x0105;
    out16(dx, ax);
    ax = 0x0001;
    out16(dx, ax);
    dx = 0x03c4;
    ax = 0x0f02;
    out16(dx, ax);
}
void sub_34802()
{
    push(ds);
    ax = 0x1040;
    ds = ax;
    al = memoryAGet(ds, 0x7e42);
    ah = 0x00;
    interrupt(0x10);
    ds = pop();
}
void sub_34811()
{
    sp -= 2;
    push(ds);
    push(bp);
    push(dx);
    bp = sp;
    dx = 0x03ce;
    ax = 0x0001;
    out16(dx, ax);
    al = 0x03;
    out16(dx, ax);
    al = 0x05;
    out16(dx, ax);
    ax = 0xff08;
    out16(dx, ax);
    ax = 0xa000;
    es = ax;
    ax = 0x1040;
    ds = ax;
    dx = 0x03c4;
    ax = 0x0102;
    out16(dx, ax);
    di = memoryAGet16(ss, bp);
    cx = 0x0800;
    si = 0x223a;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    cx = 0x0800;
    si = 0x423a;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    ax = 0x0202;
    out16(dx, ax);
    di = memoryAGet16(ss, bp);
    cx = 0x0800;
    si = 0x2a3a;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    cx = 0x0800;
    si = 0x4a3a;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    ax = 0x0402;
    out16(dx, ax);
    di = memoryAGet16(ss, bp);
    si = 0x323a;
    cx = 0x0800;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    si = 0x523a;
    cx = 0x0800;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    ax = 0x0802;
    out16(dx, ax);
    di = pop();
    cx = 0x0800;
    si = 0x3a3a;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    cx = 0x0800;
    si = 0x5a3a;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    dx = 0x03c4;
    ax = 0x0f02;
    out16(dx, ax);
    bp = pop();
    ds = pop();
    sp += 2;
}
void sub_348a8()
{
    push(ds);
    push(es);
    dx = 0;
    ax = 0x1040;
    ds = ax;
    dx = memoryAGet16(ds, 0x9663);
    ax = 0x2455;
    ds = ax;
    es = dx;
    sub_348e6();
    ax = 0x1040;
    ds = ax;
    dx = memoryAGet16(ds, 0x9665);
    push(es);
    ds = pop();
    ax = dx;
    es = ax;
    sub_348e6();
    ax = 0x1040;
    ds = ax;
    dx = memoryAGet16(ds, 0x9667);
    push(es);
    ds = pop();
    ax = dx;
    es = ax;
    sub_348e6();
    es = pop();
    ds = pop();
}
void sub_348e6()
{
    di = 0x0000;
    cx = 0x009a;
loc_348ec:
    push(cx);
    push(di);
    cx = 0x0015;
loc_348f1:
    push(cx);
    ax = memoryAGet16(ds, di);
    bx = memoryAGet16(ds, di + 10);
    flags.carry = 1;
    ax = rcr16(ax, 0x0001);
    bx = rcr16(bx, 0x0001);
    flags.carry = 1;
    ax = rcr16(ax, 0x0001);
    bx = rcr16(bx, 0x0001);
    memoryASet16(es, di, ax);
    memoryASet16(es, di + 10, bx);
    di += 0x0002;
    cx = 0x0004;
loc_3490e:
    ax = memoryAGet16(ds, di);
    bx = memoryAGet16(ds, di + 10);
    flags.carry = ax & 1;
    ax >>= 1;
    bx = rcr16(bx, 0x0001);
    flags.carry = ax & 1;
    ax >>= 1;
    bx = rcr16(bx, 0x0001);
    memoryASet16(es, di, ax);
    memoryASet16(es, di + 10, bx);
    di += 0x0002;
    if (--cx)
        goto loc_3490e;
    di += 0x000a;
    cx = pop();
    if (--cx)
        goto loc_348f1;
    di = pop();
    di += 0x01a4;
    cx = pop();
    if (--cx)
        goto loc_348ec;
}
void sub_34936()
{
    ax = 0x1040;
    ds = ax;
    es = ax;
    dx = 0x9709;
    ax = 0x1002;
    interrupt(0x10);
}
void sub_34947()
{
    push(es);
    ax = 0xa000;
    es = ax;
    dx = 0x03ce;
    ax = 0x0005;
    out16(dx, ax);
    al = 0x01;
    out16(dx, ax);
    al = 0x05;
    out16(dx, ax);
    ax = 0;
    di = ax;
    ax = di;
    cx = 0x0fa0;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    ax = 0x0105;
    out16(dx, ax);
    es = pop();
}
void sub_3496b()
{
    dx = 0x03da;
loc_3496e:
    al = in8(dx);
    al &= 0x08;
    if (al)
        goto loc_3496e;
loc_34973:
    al = in8(dx);
    al &= 0x08;
    if (!al)
        goto loc_34973;
}
void sub_34986()
{
    dx = 0x03ce;
    ax = 0x0001;
    out16(dx, ax);
    al = 0x03;
    out16(dx, ax);
    ax = 0x1040;
    ds = ax;
    es = ax;
    ax = 0x023a;
    memoryASet16(ds, 0x7d96, ax);
    ax = 0x0002;
    memoryASet16(ds, 0x7e3c, ax);
    si = 0x7e4e;
loc_349a6:
    al = memoryAGet(ds, si);
    if (!al)
        goto loc_349b9;
    if (al == 0xff)
        goto loc_349be;
    sub_34a2e();
loc_349b9:
    si += 0x0030;
    goto loc_349a6;
loc_349be:
    dx = 0x03ce;
    ax = 0x0001;
    out16(dx, ax);
    al = 0x03;
    out16(dx, ax);
    al = 0x05;
    out16(dx, ax);
    ax = 0xff08;
    out16(dx, ax);
    ax = 0xa000;
    es = ax;
    bx = memoryAGet16(ds, 0x7e3c);
    bx -= 0x0002;
    dx = 0x03c4;
    ax = 0x0102;
    out16(dx, ax);
    si = 0x023a;
    di = 0x4000;
    cx = bx;
loc_349ea:
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    if (--cx)
        goto loc_349ea;
    ah = 0x02;
    out16(dx, ax);
    si = 0x0a3a;
    di = 0x4000;
    cx = bx;
loc_349fb:
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    if (--cx)
        goto loc_349fb;
    ah = 0x04;
    out16(dx, ax);
    si = 0x123a;
    di = 0x4000;
    cx = bx;
loc_34a0c:
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    if (--cx)
        goto loc_34a0c;
    ah = 0x08;
    out16(dx, ax);
    si = 0x1a3a;
    di = 0x4000;
    cx = bx;
loc_34a1d:
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    if (--cx)
        goto loc_34a1d;
    ah = 0x0f;
    out16(dx, ax);
    dx = 0x03ce;
    ax = 0x0105;
    out16(dx, ax);
}
void sub_34a2e()
{
    push(si);
    bl = memoryAGet(ds, si + 8);
    bh = 0;
    bx += bx;
    bx += 0x0100;
    ax = memoryAGet16(ds, bx);
    push(ax);
    ax = memoryAGet16(ds, si + 4);
    dl = al;
    ax &= 0x01f8;
    ax += ax;
    ax += ax;
    bx = memoryAGet16(ds, si + 2);
    dh = bl;
    cl = 0x03;
    bx >>= cl;
    ax += bx;
    ax += 0x778e;
    si = ax;
    dl &= 0x07;
    if (!(dl & 0x04))
        goto loc_34a67;
    goto loc_34bab;
loc_34a67:
    di = memoryAGet16(ds, 0x7d96);
    sub_34d08();
    si += 0x0020;
    sub_34d08();
    si += 0x0020;
    sub_34d08();
    si += 0xffc1;
    sub_34d08();
    si += 0x0020;
    sub_34d08();
    si += 0x0020;
    sub_34d08();
    si += 0xffc1;
    sub_34d08();
    si += 0x0020;
    sub_34d08();
    si += 0x0020;
    sub_34d08();
    si += 0xffc1;
    sub_34d08();
    si += 0x0020;
    sub_34d08();
    si += 0x0020;
    sub_34d08();
    memoryASet16(ds, 0x7d96, di);
    di -= 0x0060;
    al = dl;
    ah = 0x00;
    di += ax;
    si = pop();
    bl = dh;
    bh = 0x00;
    bl &= 0x06;
    ax = 0x9661;
    bx += ax;
    push(ds);
    push(es);
    push(ds);
    es = pop();
    ax = memoryAGet16(ds, bx);
    ds = ax;
    cx = 0x0015;
loc_34ad5:
    ax = lodsw<DS_SI>();
    bh = memoryAGet(es, di);
    bl = memoryAGet(es, di + 24);
    bx &= ax;
    bx |= memoryAGet16(ds, si);
    si++;
    si++;
    memoryASet(es, di, bh);
    memoryASet(es, di + 24, bl);
    bh = memoryAGet(es, di + 2048);
    bl = memoryAGet(es, di + 2072);
    bx &= ax;
    bx |= memoryAGet16(ds, si);
    si++;
    si++;
    memoryASet(es, di + 2048, bh);
    memoryASet(es, di + 2072, bl);
    bh = memoryAGet(es, di + 4096);
    bl = memoryAGet(es, di + 4120);
    bx &= ax;
    bx |= memoryAGet16(ds, si);
    si++;
    si++;
    memoryASet(es, di + 4096, bh);
    memoryASet(es, di + 4120, bl);
    bh = memoryAGet(es, di + 6144);
    bl = memoryAGet(es, di + 6168);
    bx &= ax;
    bx |= memoryAGet16(ds, si);
    si++;
    si++;
    memoryASet(es, di + 6144, bh);
    memoryASet(es, di + 6168, bl);
    ax = lodsw<DS_SI>();
    bh = memoryAGet(es, di + 48);
    bl = memoryAGet(es, di + 72);
    bx &= ax;
    bx |= memoryAGet16(ds, si);
    si++;
    si++;
    memoryASet(es, di + 48, bh);
    memoryASet(es, di + 72, bl);
    bh = memoryAGet(es, di + 2096);
    bl = memoryAGet(es, di + 2120);
    bx &= ax;
    bx |= memoryAGet16(ds, si);
    si++;
    si++;
    memoryASet(es, di + 2096, bh);
    memoryASet(es, di + 2120, bl);
    bh = memoryAGet(es, di + 4144);
    bl = memoryAGet(es, di + 4168);
    bx &= ax;
    bx |= memoryAGet16(ds, si);
    si++;
    si++;
    memoryASet(es, di + 4144, bh);
    memoryASet(es, di + 4168, bl);
    bh = memoryAGet(es, di + 6192);
    bl = memoryAGet(es, di + 6216);
    bx &= ax;
    bx |= memoryAGet16(ds, si);
    si++;
    si++;
    memoryASet(es, di + 6192, bh);
    memoryASet(es, di + 6216, bl);
    di++;
    cx--;
    if (!cx)
        goto loc_34ba7;
    goto loc_34ad5;
loc_34ba7:
    es = pop();
    ds = pop();
    si = pop();
    return;
loc_34bab:
    di = memoryAGet16(ds, 0x7d96);
    sub_34d08();
    si += 0x0020;
    sub_34d08();
    si += 0x0020;
    sub_34d08();
    si += 0x0020;
    sub_34d08();
    si += 0xffa1;
    sub_34d08();
    si += 0x0020;
    sub_34d08();
    si += 0x0020;
    sub_34d08();
    si += 0x0020;
    sub_34d08();
    si += 0xffa1;
    sub_34d08();
    si += 0x0020;
    sub_34d08();
    si += 0x0020;
    sub_34d08();
    si += 0x0020;
    sub_34d08();
    si += 0xffa1;
    sub_34d08();
    si += 0x0020;
    sub_34d08();
    si += 0x0020;
    sub_34d08();
    si += 0x0020;
    sub_34d08();
    memoryASet16(ds, 0x7d96, di);
    di -= 0x0080;
    al = dl;
    ah = 0x00;
    di += ax;
    si = pop();
    bl = dh;
    bh = 0x00;
    bl &= 0x06;
    ax = 0x9661;
    bx += ax;
    push(ds);
    push(es);
    push(ds);
    es = pop();
    ax = memoryAGet16(ds, bx);
    ds = ax;
    cx = 0x0015;
loc_34c32:
    ax = lodsw<DS_SI>();
    bh = memoryAGet(es, di);
    bl = memoryAGet(es, di + 32);
    bx &= ax;
    bx |= memoryAGet16(ds, si);
    si++;
    si++;
    memoryASet(es, di, bh);
    memoryASet(es, di + 32, bl);
    bh = memoryAGet(es, di + 2048);
    bl = memoryAGet(es, di + 2080);
    bx &= ax;
    bx |= memoryAGet16(ds, si);
    si++;
    si++;
    memoryASet(es, di + 2048, bh);
    memoryASet(es, di + 2080, bl);
    bh = memoryAGet(es, di + 4096);
    bl = memoryAGet(es, di + 4128);
    bx &= ax;
    bx |= memoryAGet16(ds, si);
    si++;
    si++;
    memoryASet(es, di + 4096, bh);
    memoryASet(es, di + 4128, bl);
    bh = memoryAGet(es, di + 6144);
    bl = memoryAGet(es, di + 6176);
    bx &= ax;
    bx |= memoryAGet16(ds, si);
    si++;
    si++;
    memoryASet(es, di + 6144, bh);
    memoryASet(es, di + 6176, bl);
    ax = lodsw<DS_SI>();
    bh = memoryAGet(es, di + 64);
    bl = memoryAGet(es, di + 96);
    bx &= ax;
    bx |= memoryAGet16(ds, si);
    si++;
    si++;
    memoryASet(es, di + 64, bh);
    memoryASet(es, di + 96, bl);
    bh = memoryAGet(es, di + 2112);
    bl = memoryAGet(es, di + 2144);
    bx &= ax;
    bx |= memoryAGet16(ds, si);
    si++;
    si++;
    memoryASet(es, di + 2112, bh);
    memoryASet(es, di + 2144, bl);
    bh = memoryAGet(es, di + 4160);
    bl = memoryAGet(es, di + 4192);
    bx &= ax;
    bx |= memoryAGet16(ds, si);
    si++;
    si++;
    memoryASet(es, di + 4160, bh);
    memoryASet(es, di + 4192, bl);
    bh = memoryAGet(es, di + 6208);
    bl = memoryAGet(es, di + 6240);
    bx &= ax;
    bx |= memoryAGet16(ds, si);
    si++;
    si++;
    memoryASet(es, di + 6208, bh);
    memoryASet(es, di + 6240, bl);
    di++;
    cx--;
    if (!cx)
        goto loc_34d04;
    goto loc_34c32;
loc_34d04:
    es = pop();
    ds = pop();
    si = pop();
}
void sub_34d08()
{
    bx = 0x0000;
    bl = memoryAGet(ds, si);
    ah = 0;
    al = memoryAGet(ds, bx);
    flags.zero = !(al & 0x08);
    al = bl;
    if (flags.zero)
        goto loc_34d25;
    ax = memoryAGet16(ds, 0x7e3c);
    ax++;
    memoryASet16(ds, 0x7e3c, ax);
    di += 0x0008;
    return;
loc_34d25:
    push(si);
    si -= 0x778e;
    si += 0x720e;
    cx = memoryAGet16(ds, 0x7d5e);
    bl = memoryAGet(ds, si);
    if (bl < 0x02)
        goto loc_34d41;
    al = bl;
    cx = 0x022a;
loc_34d41:
    bx = memoryAGet16(ds, 0x7e3c);
    memoryASet(ds, si, bl);
    bx++;
    memoryASet16(ds, 0x7e3c, bx);
    ax += ax;
    ax += ax;
    ax += ax;
    ax += cx;
    si = ax;
    ax = memoryAGet16(ds, si + 6144);
    memoryASet16(es, di + 6144, ax);
    ax = memoryAGet16(ds, si + 4096);
    memoryASet16(es, di + 4096, ax);
    ax = memoryAGet16(ds, si + 2048);
    memoryASet16(es, di + 2048, ax);
    movsw<ES_DI, DS_SI>();
    ax = memoryAGet16(ds, si + 6144);
    memoryASet16(es, di + 6144, ax);
    ax = memoryAGet16(ds, si + 4096);
    memoryASet16(es, di + 4096, ax);
    ax = memoryAGet16(ds, si + 2048);
    memoryASet16(es, di + 2048, ax);
    movsw<ES_DI, DS_SI>();
    ax = memoryAGet16(ds, si + 6144);
    memoryASet16(es, di + 6144, ax);
    ax = memoryAGet16(ds, si + 4096);
    memoryASet16(es, di + 4096, ax);
    ax = memoryAGet16(ds, si + 2048);
    memoryASet16(es, di + 2048, ax);
    movsw<ES_DI, DS_SI>();
    ax = memoryAGet16(ds, si + 6144);
    memoryASet16(es, di + 6144, ax);
    ax = memoryAGet16(ds, si + 4096);
    memoryASet16(es, di + 4096, ax);
    ax = memoryAGet16(ds, si + 2048);
    memoryASet16(es, di + 2048, ax);
    movsw<ES_DI, DS_SI>();
    si = pop();
}
void sub_34dc8()
{
    ax = 0x1040;
    es = ax;
    ds = ax;
    sub_3505d();
    ax = 0xa000;
    es = ax;
    si = 0x730e;
    di = 0x0004;
    bx = 0x0018;
loc_34de0:
    cx = 0x0020;
    ax = 0;
loc_34de5:
    al |= memoryAGet(ds, si);
    if (al)
        goto loc_34df8;
loc_34dec:
    di++;
    si++;
    if (--cx)
        goto loc_34de5;
    di += 0x0120;
    bx--;
    if (bx)
        goto loc_34de0;
    return;
loc_34df8:
    push(bx);
    push(di);
    push(si);
    push(ds);
    if (ax != 0x0001)
        goto loc_34e44;
    memoryASet(ds, si, 0x00);
    si -= 0x730e;
    si += 0x788e;
    ah = 0x00;
    al = memoryAGet(ds, si);
    bx = memoryAGet16(ds, 0x971a);
loc_34e17:
    push(es);
    ds = pop();
    ax += ax;
    ax += ax;
    ax += ax;
    ax += bx;
    si = ax;
    bx = 0x0027;
    movsb<ES_DI, DS_SI>();
    di += bx;
    movsb<ES_DI, DS_SI>();
    di += bx;
    movsb<ES_DI, DS_SI>();
    di += bx;
    movsb<ES_DI, DS_SI>();
    di += bx;
    movsb<ES_DI, DS_SI>();
    di += bx;
    movsb<ES_DI, DS_SI>();
    di += bx;
    movsb<ES_DI, DS_SI>();
    di += bx;
    movsb<ES_DI, DS_SI>();
    ds = pop();
    si = pop();
    di = pop();
    bx = pop();
    ax = 0;
    goto loc_34dec;
loc_34e44:
    memoryASet(ds, si, 0x01);
    bx = 0x3ff0;
    goto loc_34e17;
}
void sub_34e4c()
{
    ax = 0x1040;
    es = ax;
    ds = ax;
    sub_3505d();
    ax = 0xa000;
    es = ax;
    si = 0x730e;
    di = 0x0004;
    bx = 0x0018;
loc_34e64:
    cx = 0x0020;
    ax = 0;
loc_34e69:
    al |= memoryAGet(ds, si);
    if (al)
        goto loc_34e7c;
loc_34e70:
    di++;
    si++;
    if (--cx)
        goto loc_34e69;
    di += 0x0120;
    bx--;
    if (bx)
        goto loc_34e64;
    return;
loc_34e7c:
    push(bx);
    push(di);
    push(si);
    push(ds);
    if (ax != 0x0001)
        goto loc_34ec8;
    memoryASet(ds, si, 0x00);
    si -= 0x730e;
    si += 0x788e;
    ah = 0x00;
    al = memoryAGet(ds, si);
    bx = memoryAGet16(ds, 0x971a);
loc_34e9b:
    push(es);
    ds = pop();
    ax += ax;
    ax += ax;
    ax += ax;
    ax += bx;
    si = ax;
    bx = 0x0027;
    movsb<ES_DI, DS_SI>();
    di += bx;
    movsb<ES_DI, DS_SI>();
    di += bx;
    movsb<ES_DI, DS_SI>();
    di += bx;
    movsb<ES_DI, DS_SI>();
    di += bx;
    movsb<ES_DI, DS_SI>();
    di += bx;
    movsb<ES_DI, DS_SI>();
    di += bx;
    movsb<ES_DI, DS_SI>();
    di += bx;
    movsb<ES_DI, DS_SI>();
    ds = pop();
    si = pop();
    di = pop();
    bx = pop();
    ax = 0;
    goto loc_34e70;
loc_34ec8:
    bx = 0x3ff0;
    goto loc_34e9b;
}
void sub_34ecd()
{
    ax = 0x1040;
    ds = ax;
    si = 0x730e;
    cx = 0x0300;
loc_34ed8:
    memoryASet(ds, si, 0x01);
    si++;
    if (--cx)
        goto loc_34ed8;
}
void sub_34edf()
{
    al = memoryAGet(ds, 0x7d68);
    memoryASet(ds, 0x7d88, al);
    ax = memoryAGet16(ds, 0x7e82);
    memoryASet16(ds, 0x7d8a, ax);
    al = memoryAGet(ds, 0x7e80);
    memoryASet(ds, 0x7d89, al);
    al = memoryAGet(ds, 0x7e8a);
    memoryASet(ds, 0x7d8c, al);
    al = memoryAGet(ds, 0x7e38);
    ah = 0;
    memoryASet(ds, 0x7d8d, al);
}
void sub_34f00()
{
    al = memoryAGet(ds, 0x7d88);
    memoryASet(ds, 0x7d68, al);
    al = memoryAGet(ds, 0x7d89);
    memoryASet(ds, 0x7e80, al);
    ax = memoryAGet16(ds, 0x7d8a);
    memoryASet16(ds, 0x7e82, ax);
    al = memoryAGet(ds, 0x7d8c);
    memoryASet(ds, 0x7e8a, al);
    bl = memoryAGet(ds, 0x7d8d);
    memoryASet(ds, 0x7e38, bl);
    memoryASet(ds, 0x7d85, 0x00);
    di = memoryAGet16(ds, 0x7d60);
    goto loc_34fe7;
  // gap 187 bytes
loc_34fe7:
    memoryASet16(ds, 0x7d60, di);
    memoryASet(ds, 0x7d76, 0x00);
    si = 0x7d0e;
    cx = 0x9810;
    dx = 0x3000;
    ax = memoryAGet16(ds, di);
    if (!ax)
        goto loc_3500b;
    si = 0x7d1e;
    cx = 0xd810;
    dx = 0x3800;
loc_3500b:
    memoryASet16(ds, 0x7d5e, cx);
    memoryASet16(ds, 0x971a, dx);
    ax = memoryAGet16(ds, di + 2);
    memoryASet16(ds, 0x7e3a, ax);
    memoryASet(ds, 0x7e38, bl);
    ax = memoryAGet16(ds, di + 4);
    memoryASet16(ds, 0x7d62, ax);
    ax = memoryAGet16(ds, di + 6);
    memoryASet16(ds, 0x7d64, ax);
    sub_35445();
    sub_3508b();
    sub_36819();
    dh = memoryAGet(ds, 0x7e38);
    dh += 0x08;
    dl = 0x18;
    sub_36239();
    dh = memoryAGet(ds, 0x7e38);
    dl = 0x08;
    sub_36239();
    dh = memoryAGet(ds, 0x7e38);
    dh += 0x20;
    dl = 0x08;
    sub_36239();
    sub_34ecd();
    sub_34e4c();
    sub_34edf();
}
void sub_34f2c()
{
    memoryASet(ds, 0x7d76, 0x00);
    memoryASet(ds, 0x7d8f, 0x00);
    si = memoryAGet16(ds, 0x7d62);
    ax = memoryAGet16(ds, 0x7e82);
    ax >>= 1;
    ax >>= 1;
    ax >>= 1;
    al += memoryAGet(ds, 0x7e38);
    cl = al;
    bl = memoryAGet(ds, 0x7d77);
loc_34f4d:
    if (bl == memoryAGet(ds, si))
        goto loc_34f54;
    goto loc_34fe1;
loc_34f54:
    al = cl;
    al -= memoryAGet(ds, si + 1);
    if (al < 0x03)
        goto loc_34f60;
    goto loc_34fe1;
loc_34f60:
    al = memoryAGet(ds, si + 1);
    al -= memoryAGet(ds, si + 4);
    bl = memoryAGet(ds, 0x7e38);
    bl -= al;
    bh = 0;
    di = memoryAGet16(ds, si + 2);
    if (di != 0x00ff)
        goto loc_34fe7;
    memoryASet(ds, 0x7e45, 0x06);
    memoryASet(ds, 0x7e47, 0x06);
    al = memoryAGet(ds, 0x7d90);
    al++;
    memoryASet(ds, 0x7d90, al);
    if (al != 0x04)
        goto loc_34fa1;
    al = memoryAGet(ds, 0x7e46);
    al++;
    memoryASet(ds, 0x4916, al);
    si = 0x4916;
    sub_34442();
loc_34fa1:
    push(ds);
    sub_35c76();
    ds = pop();
    al = memoryAGet(ds, 0x7d90);
    if (al < 0x04)
        goto loc_34fb6;
    memoryASet(ds, 0x7d91, 0xff);
    return;
loc_34fb6:
    bl = memoryAGet(ds, 0x7d90);
    bh = 0;
    bx += bx;
    bx += bx;
    bx += bx;
    bx += 0x80ef;
    al = memoryAGet(ds, bx);
    memoryASet(ds, 0x7e80, al);
    bx++;
    bx++;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, 0x7e82, ax);
    bx++;
    bx++;
    di = memoryAGet16(ds, bx);
    bx++;
    bx++;
    bx = memoryAGet16(ds, bx);
    sub_34fe7();
    sub_344b9();
    return;
loc_34fe1:
    si += 0x0006;
    goto loc_34f4d;
loc_34fe7:
    memoryASet16(ds, 0x7d60, di);
    memoryASet(ds, 0x7d76, 0x00);
    si = 0x7d0e;
    cx = 0x9810;
    dx = 0x3000;
    ax = memoryAGet16(ds, di);
    if (!ax)
        goto loc_3500b;
    si = 0x7d1e;
    cx = 0xd810;
    dx = 0x3800;
loc_3500b:
    memoryASet16(ds, 0x7d5e, cx);
    memoryASet16(ds, 0x971a, dx);
    ax = memoryAGet16(ds, di + 2);
    memoryASet16(ds, 0x7e3a, ax);
    memoryASet(ds, 0x7e38, bl);
    ax = memoryAGet16(ds, di + 4);
    memoryASet16(ds, 0x7d62, ax);
    ax = memoryAGet16(ds, di + 6);
    memoryASet16(ds, 0x7d64, ax);
    sub_35445();
    sub_3508b();
    sub_36819();
    dh = memoryAGet(ds, 0x7e38);
    dh += 0x08;
    dl = 0x18;
    sub_36239();
    dh = memoryAGet(ds, 0x7e38);
    dl = 0x08;
    sub_36239();
    dh = memoryAGet(ds, 0x7e38);
    dh += 0x20;
    dl = 0x08;
    sub_36239();
    sub_34ecd();
    sub_34e4c();
    sub_34edf();
}
void sub_34fe7()
{
    memoryASet16(ds, 0x7d60, di);
    memoryASet(ds, 0x7d76, 0x00);
    si = 0x7d0e;
    cx = 0x9810;
    dx = 0x3000;
    ax = memoryAGet16(ds, di);
    if (!ax)
        goto loc_3500b;
    si = 0x7d1e;
    cx = 0xd810;
    dx = 0x3800;
loc_3500b:
    memoryASet16(ds, 0x7d5e, cx);
    memoryASet16(ds, 0x971a, dx);
    ax = memoryAGet16(ds, di + 2);
    memoryASet16(ds, 0x7e3a, ax);
    memoryASet(ds, 0x7e38, bl);
    ax = memoryAGet16(ds, di + 4);
    memoryASet16(ds, 0x7d62, ax);
    ax = memoryAGet16(ds, di + 6);
    memoryASet16(ds, 0x7d64, ax);
    sub_35445();
    sub_3508b();
    sub_36819();
    dh = memoryAGet(ds, 0x7e38);
    dh += 0x08;
    dl = 0x18;
    sub_36239();
    dh = memoryAGet(ds, 0x7e38);
    dl = 0x08;
    sub_36239();
    dh = memoryAGet(ds, 0x7e38);
    dh += 0x20;
    dl = 0x08;
    sub_36239();
    sub_34ecd();
    sub_34e4c();
    sub_34edf();
}
void sub_3505d()
{
    ax = 0x1040;
    ds = ax;
    es = ax;
    ax = 0x0000;
    di = 0x732f;
    stosw<ES_DI>(ax);
    stosw<ES_DI>(ax);
    stosw<ES_DI>(ax);
    cl = memoryAGet(ds, 0x7e45);
    ch = 0;
    di = 0x7337;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cl = memoryAGet(ds, 0x7e47);
    di = 0x733f;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    cl = memoryAGet(ds, 0x7e46);
    di = 0x7347;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
}
void sub_3508b()
{
    ax = 0x1040;
    ds = ax;
    es = ax;
    di = 0x778e;
    al = memoryAGet(ds, 0x7e38);
    ah = 0;
    ax += ax;
    ax &= 0xfff8;
    ax += memoryAGet16(ds, 0x7e3a);
    bx = ax;
    dh = 0x0b;
loc_350a7:
    cx = 0x0008;
loc_350aa:
    al = memoryAGet(ds, bx);
    bx++;
    ah = 0x00;
    ax += ax;
    ax += ax;
    ax += ax;
    ax += ax;
    ax += 0x423a;
    si = ax;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += 0x001c;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += 0x001c;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += 0x001c;
    movsw<ES_DI, DS_SI>();
    movsw<ES_DI, DS_SI>();
    di += 0xffa0;
    if (--cx)
        goto loc_350aa;
    di += 0x0060;
    dh--;
    if (dh)
        goto loc_350a7;
}
void sub_350da()
{
    ax = 0x1040;
    ds = ax;
    es = ax;
    flags.direction = 0;
    di = 0x788e;
    si = 0x78ae;
    bx = 0x730e;
    dl = 0x01;
    cx = 0x03e0;
loc_350f0:
    bx++;
    cmpsb<DS_SI, ES_DI>();
    if (!flags.zero)
        goto loc_350fb;
loc_350f7:
    cx--;
    if (cx)
        goto loc_350f0;
    return;
loc_350fb:
    si--;
    di--;
    movsb<ES_DI, DS_SI>();
    bx--;
    al = memoryAGet(ds, bx);
    if (al >= 0x02)
        goto loc_3510b;
    memoryASet(ds, bx, 0x01);
loc_3510b:
    bx++;
    goto loc_350f7;
}
void sub_3510e()
{
    si = 0x730e;
    cx = 0x0400;
    al = 0x01;
loc_35116:
    if (al < memoryAGet(ds, si))
        goto loc_35121;
loc_3511d:
    si++;
    if (--cx)
        goto loc_35116;
    return;
loc_35121:
    al = memoryAGet(ds, si);
    si -= 0x0020;
    memoryASet(ds, si, al);
    si += 0x0020;
    al = 0x01;
    memoryASet(ds, si, al);
    goto loc_3511d;
}
void sub_35131()
{
    sub_352aa();
    sub_34986();
    cx = 0x0008;
loc_3513a:
    push(cx);
    ax = 0x1040;
    ds = ax;
    es = ax;
    sub_350da();
    sub_3510e();
    bx = 0xfff8;
    sub_35262();
    cx = 0x0001;
loc_35151:
    push(cx);
    sub_3496b();
    cx = pop();
    if (--cx)
        goto loc_35151;
    ax = 0x1040;
    ds = ax;
    es = ax;
    flags.direction = 0;
    si = 0x732e;
    di = 0x7d2e;
    cx = 0x0010;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    sub_34e4c();
    sync();
    sub_36ce2();
    ax = 0x1040;
    ds = ax;
    es = ax;
    flags.direction = 0;
    si = 0x7d2e;
    di = 0x732e;
    cx = 0x0010;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    ax = memoryAGet16(ds, 0x7e38);
    ax++;
    memoryASet16(ds, 0x7e38, ax);
    cx = pop();
    if (--cx)
        goto loc_3513a;
    dh = al;
    dh += 0x20;
    dl = 0x08;
    sub_36239();
    sub_3508b();
    sub_34dc8();
}
void sub_3519f()
{
    sub_352aa();
    sub_34986();
    cx = 0x0008;
loc_351a8:
    push(cx);
    ax = 0x1040;
    ds = ax;
    es = ax;
    sub_3523f();
    sub_3520a();
    bx = 0x0008;
    sub_35262();
    cx = 0x0001;
loc_351bf:
    push(cx);
    sub_3496b();
    cx = pop();
    if (--cx)
        goto loc_351bf;
    ax = 0x1040;
    ds = ax;
    es = ax;
    flags.direction = 0;
    si = 0x732e;
    di = 0x7d2e;
    cx = 0x0010;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    sub_34e4c();
    sub_36ce2();
    ax = 0x1040;
    ds = ax;
    es = ax;
    flags.direction = 0;
    si = 0x7d2e;
    di = 0x732e;
    cx = 0x0010;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    ax = memoryAGet16(ds, 0x7e38);
    ax--;
    memoryASet16(ds, 0x7e38, ax);
    cx = pop();
    if (--cx)
        goto loc_351a8;
    dh = al;
    dl = 0x08;
    sub_36239();
    sub_3508b();
    sub_34dc8();
}
void sub_3520a()
{
    ax = 0x1040;
    ds = ax;
    es = ax;
    flags.direction = 1;
    di = 0x7b8e;
    si = 0x7b6e;
    bx = 0x760e;
    dl = 0x01;
    cx = 0x0400;
loc_35220:
    bx--;
    cmpsb<DS_SI, ES_DI>();
    if (!flags.zero)
        goto loc_3522c;
loc_35227:
    cx--;
    if (cx)
        goto loc_35220;
    flags.direction = 0;
    return;
loc_3522c:
    si++;
    di++;
    movsb<ES_DI, DS_SI>();
    bx++;
    al = memoryAGet(ds, bx);
    if (al >= 0x02)
        goto loc_3523c;
    memoryASet(ds, bx, 0x01);
loc_3523c:
    bx--;
    goto loc_35227;
}
void sub_3523f()
{
    si = 0x760e;
    cx = 0x0420;
    al = 0x01;
loc_35247:
    if (al < memoryAGet(ds, si))
        goto loc_35252;
loc_3524e:
    si--;
    if (--cx)
        goto loc_35247;
    return;
loc_35252:
    al = memoryAGet(ds, si);
    si += 0x0020;
    memoryASet(ds, si, al);
    si -= 0x0020;
    al = 0x01;
    memoryASet(ds, si, al);
    goto loc_3524e;
}
void sub_35262()
{
    ax = 0x1040;
    ds = ax;
    si = 0x7e4e;
loc_3526a:
    if (memoryAGet(ds, si) == 0x00)
        goto loc_352a4;
    if (memoryAGet(ds, si) == 0xff)
        goto loc_352a9;
    memoryASet16(ds, si + 30, memoryAGet16(ds, si + 30) + bx);
    memoryASet16(ds, si + 24, memoryAGet16(ds, si + 24) + bx);
    ax = memoryAGet16(ds, si + 4);
    ax += bx;
    if (!(ah & 0x80))
        goto loc_35293;
    memoryASet(ds, si, 0x00);
    goto loc_352a4;
  // gap 1 bytes
loc_35293:
    if (ax < 0x0140)
        goto loc_352a1;
    memoryASet(ds, si, 0x00);
    goto loc_352a4;
  // gap 1 bytes
loc_352a1:
    memoryASet16(ds, si + 4, ax);
loc_352a4:
    si += 0x0030;
    goto loc_3526a;
loc_352a9:
    return;
}
void sub_352aa()
{
    ax = 0x1040;
    ds = ax;
    es = ax;
    ax = 0x0000;
    di = 0x720e;
    cx = 0x0080;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
    di = 0x760e;
    cx = 0x0080;
    for (; cx != 0; --cx) stosw<ES_DI>(ax);
}
void sub_352c5() // +returnZero
{
    dx &= 0x00f8;
    dx += dx;
    dx += dx;
    al = bl;
    bl >>= 1;
    bl >>= 1;
    bl >>= 1;
    bh = 0;
    dx += bx;
    bx = 0x778e;
    bx += dx;
    al = memoryAGet(ds, bx);
    bx = 0x0000;
    bl = al;
    al = memoryAGet(ds, bx);
    flags.zero = !(al & 0x40);
    al &= 0x40;
}
void sub_352ea()
{
    push(ax);
    push(cx);
    push(bx);
    push(dx);
    memoryASet(ds, 0x7d74, 0x00);
    bl += 0x04;
    cx = 0x0001;
    if (!(dl & 0x04))
        goto loc_35302;
    cx++;
loc_35302:
    dx &= 0x01f8;
    dx += dx;
    dx += dx;
    al = bl;
    bl >>= 1;
    bl >>= 1;
    bl >>= 1;
    bh = 0;
    dx += bx;
    bx = 0x778e;
    dx += bx;
    di = dx;
    bx = 0x0000;
    dl = 0;
    al &= 0x07;
    if (!al)
        goto loc_3534f;
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, bx);
    al &= 0xf0;
    dl |= al;
    di++;
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, bx);
    al &= 0xf0;
    dl |= al;
    di++;
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, bx);
    al &= 0xf0;
    dl |= al;
    di += 0x001e;
    memoryASet(ds, 0x7d74, dl);
    dl = 0;
    goto loc_353ac;
  // gap 1 bytes
loc_3534f:
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, bx);
    al &= 0xf0;
    dl |= al;
    di++;
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, bx);
    al &= 0xf0;
    dl |= al;
    di += 0x001f;
    memoryASet(ds, 0x7d74, dl);
    dl = 0;
    goto loc_353e8;
  // gap 65 bytes
loc_353ac:
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, bx);
    al &= 0x6d;
    dl |= al;
    di++;
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, bx);
    al &= 0x6f;
    dl |= al;
    di++;
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, bx);
    al &= 0x6d;
    dl |= al;
    di += 0x001e;
    if (--cx)
        goto loc_353ac;
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, bx);
    al &= 0x7d;
    dl |= al;
    di++;
    bl = memoryAGet(ds, di);
    dl |= memoryAGet(ds, bx);
    di++;
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, bx);
    al &= 0x7d;
    dl |= al;
    memoryASet(ds, 0x7d67, dl);
    goto loc_3540b;
  // gap 1 bytes
loc_353e8:
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, bx);
    al &= 0x6f;
    dl |= al;
    di++;
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, bx);
    al &= 0x6f;
    dl |= al;
    di += 0x001f;
    if (--cx)
        goto loc_353e8;
    bl = memoryAGet(ds, di);
    dl |= memoryAGet(ds, bx);
    di++;
    bl = memoryAGet(ds, di);
    dl |= memoryAGet(ds, bx);
    memoryASet(ds, 0x7d67, dl);
loc_3540b:
    if (memoryAGet(ds, 0x7d67) & 0x40)
        goto loc_35440;
    if (memoryAGet(ds, 0x7e4e) == 0x00)
        goto loc_35440;
    dx = pop();
    bx = pop();
    push(bx);
    push(dx);
    push(si);
    push(di);
    di = 0x808f;
    memoryASet(ds, di + 2, bl);
    memoryASet16(ds, di + 4, dx);
    si = 0x7e4e;
    sub_3546c();
    di = pop();
    si = pop();
    if (!flags.zero)
        goto loc_35440;
    memoryASet(ds, 0x7d67, memoryAGet(ds, 0x7d67) | 0x40);
loc_35440:
    dx = pop();
    bx = pop();
    cx = pop();
    ax = pop();
}
void sub_3536c()
{
    push(ax);
    push(cx);
    push(bx);
    push(dx);
    memoryASet(ds, 0x7d67, 0x00);
    bl += 0x04;
    cx = 0x0002;
    if (!(dx & 0x0004))
        goto loc_35385;
    cx++;
loc_35385:
    dx &= 0x01f8;
    dx += dx;
    dx += dx;
    al = bl;
    bl >>= 1;
    bl >>= 1;
    bl >>= 1;
    bh = 0;
    dx += bx;
    bx = 0x778e;
    dx += bx;
    di = dx;
    bx = 0x0000;
    dl = 0;
    al &= 0x07;
    if (!al)
        goto loc_353e8;
loc_353ac:
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, bx);
    al &= 0x6d;
    dl |= al;
    di++;
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, bx);
    al &= 0x6f;
    dl |= al;
    di++;
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, bx);
    al &= 0x6d;
    dl |= al;
    di += 0x001e;
    if (--cx)
        goto loc_353ac;
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, bx);
    al &= 0x7d;
    dl |= al;
    di++;
    bl = memoryAGet(ds, di);
    dl |= memoryAGet(ds, bx);
    di++;
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, bx);
    al &= 0x7d;
    dl |= al;
    memoryASet(ds, 0x7d67, dl);
    goto loc_3540b;
  // gap 1 bytes
loc_353e8:
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, bx);
    al &= 0x6f;
    dl |= al;
    di++;
    bl = memoryAGet(ds, di);
    al = memoryAGet(ds, bx);
    al &= 0x6f;
    dl |= al;
    di += 0x001f;
    if (--cx)
        goto loc_353e8;
    bl = memoryAGet(ds, di);
    dl |= memoryAGet(ds, bx);
    di++;
    bl = memoryAGet(ds, di);
    dl |= memoryAGet(ds, bx);
    memoryASet(ds, 0x7d67, dl);
loc_3540b:
    if (memoryAGet(ds, 0x7d67) & 0x40)
        goto loc_35440;
    if (memoryAGet(ds, 0x7e4e) == 0x00)
        goto loc_35440;
    dx = pop();
    bx = pop();
    push(bx);
    push(dx);
    push(si);
    push(di);
    di = 0x808f;
    memoryASet(ds, di + 2, bl);
    memoryASet16(ds, di + 4, dx);
    si = 0x7e4e;
    sub_3546c();
    di = pop();
    si = pop();
    if (!flags.zero)
        goto loc_35440;
    memoryASet(ds, 0x7d67, memoryAGet(ds, 0x7d67) | 0x40);
loc_35440:
    dx = pop();
    bx = pop();
    cx = pop();
    ax = pop();
}
void sub_35445()
{
    di = 0x0000;
    ax = 0x1040;
    ds = ax;
    cx = 0x0008;
loc_35450:
    ax = memoryAGet16(ds, si);
loc_35452:
    memoryASet(ds, di, ah);
    di++;
    al--;
    if (al)
        goto loc_35452;
    si++;
    si++;
    if (--cx)
        goto loc_35450;
}
void sub_3545e() // +returnZero
{
    flags.zero = memoryAGet(ds, 0x7d75) == 0x00;
    if (flags.zero)
        goto loc_35469;
    return;
loc_35469:
    di = 0x7e7e;
    al = memoryAGet(ds, di + 2);
    al += 0x11;
    ah = memoryAGet(ds, si + 2);
    if (al < ah)
        goto loc_354c2;
    al -= 0x0c;
    ah += memoryAGet(ds, si + 14);
    if (ah < al)
        goto loc_354c2;
    ax = memoryAGet16(ds, di + 4);
    ax += 0x0014;
    bx = memoryAGet16(ds, si + 4);
    if (ax < bx)
        goto loc_354c2;
    ax = memoryAGet16(ds, di + 4);
    if (memoryAGet(ds, di) != 0x01)
        goto loc_354af;
    if (memoryAGet(ds, 0x7d68) == 0x00)
        goto loc_354af;
    ax += 0x0008;
loc_354af:
    cl = memoryAGet(ds, si + 16);
    cl--;
    ch = 0;
    bx += cx;
    if (bx < ax)
        goto loc_354c2;
    flags.zero = 1;
    al = 0;
    return;
loc_354c2:
    al = 0;
    al--;
    flags.zero = !al;
}
void sub_3546c() // +returnZero
{
    al = memoryAGet(ds, di + 2);
    al += 0x11;
    ah = memoryAGet(ds, si + 2);
    if (al < ah)
        goto loc_354c2;
    al -= 0x0c;
    ah += memoryAGet(ds, si + 14);
    if (ah < al)
        goto loc_354c2;
    ax = memoryAGet16(ds, di + 4);
    ax += 0x0014;
    bx = memoryAGet16(ds, si + 4);
    if (ax < bx)
        goto loc_354c2;
    ax = memoryAGet16(ds, di + 4);
    if (memoryAGet(ds, di) != 0x01)
        goto loc_354af;
    if (memoryAGet(ds, 0x7d68) == 0x00)
        goto loc_354af;
    ax += 0x0008;
loc_354af:
    cl = memoryAGet(ds, si + 16);
    cl--;
    ch = 0;
    bx += cx;
    if (bx < ax)
        goto loc_354c2;
    flags.zero = 1;
    al = 0;
    return;
loc_354c2:
    al = 0;
    al--;
    flags.zero = !al;
}
void sub_354c7() // +returnZero
{
    al = memoryAGet(ds, si + 2);
    if (al >= bl)
        goto loc_354f6;
    al += memoryAGet(ds, si + 14);
    if (al < bl)
        goto loc_354f6;
    ax = memoryAGet16(ds, si + 4);
    if (dx < ax)
        goto loc_354f6;
    cl = memoryAGet(ds, si + 16);
    ch = 0;
    ax += cx;
    if (ax < dx)
        goto loc_354f6;
    flags.zero = 1;
    al = 0;
    return;
loc_354f6:
    al = 0;
    al--;
    flags.zero = !al;
}

void sub_354fb() // +returnZero
{
    al = memoryAGet(ds, 0x7ee0);
    ah = al;
    flags.carry = al < 0x04;
    al -= 0x04;
    if (!flags.carry)
        goto loc_35509;
    al = 0;
loc_35509:
    flags.carry = (ah + 0x20) >= 0x100;
    ah += 0x20;
    if (!flags.carry)
        goto loc_35513;
    ah = 0xff;
loc_35513:
    bl = memoryAGet(ds, si + 2);
    if (ah < bl)
        goto loc_35557;
    bl += memoryAGet(ds, si + 14);
    if (bl < al)
        goto loc_35557;
    ax = memoryAGet16(ds, 0x7ee2);
    bx = ax;
    ax -= 0x0004;
    if (!(ah & 0x80))
        goto loc_35539;
    ax = 0;
loc_35539:
    bx += 0x001d;
    cx = memoryAGet16(ds, si + 4);
    if (bx < cx)
        goto loc_35557;
    dl = memoryAGet(ds, si + 16);
    dh = 0;
    cx += dx;
    if (cx < ax)
        goto loc_35557;
    flags.zero = 1;
    al = 0;
    return;
loc_35557:
    al = 0;
    flags.zero = stop("post") && !al;
    al--;
}
void sub_3555c() // +returnZero
{
    push(si);
    di = pop();
    if (!(memoryAGet(ds, 0x7e4e) & 0x80))
        goto loc_35573;
    si = 0x7e4e;
    sub_3546c();
    if (flags.zero)
        goto loc_3558b;
loc_35573:
    cx = 0x0005;
    si = 0x7f0e;
loc_35579:
    push(cx);
    if (!(memoryAGet(ds, si) & 0x80))
        goto loc_35590;
    sub_3546c();
    if (!flags.zero)
        goto loc_35590;
    cx = pop();
loc_3558b:
    push(di);
    si = pop();
    flags.zero = 1;
    al = 0;
    return;
loc_35590:
    si += 0x0030;
    cx = pop();
    if (--cx)
        goto loc_35579;
    push(di);
    si = pop();
    al = 0;
    al--;
    flags.zero = !al;
}
void sub_3559d() // +returnZero
{
    al = memoryAGet(ds, si + 22);
    if (al >= bl)
        goto loc_355f3;
    ch = bl;
    bl = memoryAGet(ds, si);
    bl &= 0x7f;
    bh = 0;
    bx += bx;
    bx += bx;
    bx += bx;
    bx += 0x932c;
    ah = memoryAGet(ds, bx);
    bx++;
    cl = memoryAGet(ds, bx);
    ah += ah;
    ah += ah;
    ah += ah;
    flags.carry = (ah + al) >= 0x100;
    ah += al;
    if (!flags.carry)
        goto loc_355ce;
    ah = 0xff;
loc_355ce:
    if (ah < ch)
        goto loc_355f3;
    ax = memoryAGet16(ds, si + 24);
    if (ax >= dx)
        goto loc_355f3;
    ch = 0;
    cx += cx;
    cx += cx;
    cx += cx;
    ax += cx;
    if (ax < dx)
        goto loc_355f3;
    flags.zero = 1;
    al = 0;
    return;
loc_355f3:
    al = 0;
    al--;
    flags.zero = !al;
}
void sub_356ec()
{
    memoryASet(ds, 0x7d6a, 0x00);
    memoryASet(ds, 0x7d6b, 0x00);
    al = memoryAGet(ds, 0x7d75);
    if (!al)
        goto loc_35700;
    goto loc_35b0a;
loc_35700:
    al = memoryAGet(ds, 0x7e44);
    memoryASet(ds, 0x7d6c, al);
    al = memoryAGet(ds, 0x7d6d);
    if (!al)
        goto loc_35710;
    goto loc_35a23;
loc_35710:
    memoryASet(ds, 0x7d6e, 0x00);
    dl = memoryAGet(ds, 0x7d72);
    dh = memoryAGet(ds, si + 4);
    al = memoryAGet(ds, si + 5);
    bx = memoryAGet16(ds, 0x7d70);
    ah = 0;
    if (!(bh & 0x80))
        goto loc_3572f;
    ah--;
loc_3572f:
    flags.carry = (dx + bx) >= 0x10000;
    dx += bx;
    al += ah + flags.carry;
    ah = dl;
    dl = dh;
    dh = al;
    bl = memoryAGet(ds, si + 2);
    al = memoryAGet(ds, 0x7d68);
    if (al == 0x00)
        goto loc_3575b;
    sub_352ea();
    al = memoryAGet(ds, 0x7d74);
    if (al != 0x00)
        goto loc_3575e;
    memoryASet(ds, 0x7d68, 0x00);
    goto loc_3575e;
  // gap 1 bytes
loc_3575b:
    sub_3536c();
loc_3575e:
    bh = 0xf0;
    al = memoryAGet(ds, 0x7d71);
    if ((char)al >= 0)
        goto loc_3576c;
    bh = 0xe0;
loc_3576c:
    al = memoryAGet(ds, 0x7d67);
    cl = al;
    al &= bh;
    if (!al)
        goto loc_3577b;
    goto loc_3583f;
loc_3577b:
    memoryASet(ds, 0x7d6e, 0xff);
    if (!(cl & 0x04))
        goto loc_35788;
    goto loc_35b7f;
loc_35788:
    memoryASet16(ds, si + 4, dx);
    memoryASet(ds, 0x7d72, ah);
    if (!(cl & 0x02))
        goto loc_357ad;
    al = memoryAGet(ds, 0x7d6c);
    al &= 0x0c;
    if (!al)
        goto loc_357ad;
    memoryASet16(ds, 0x7d70, 0x0100);
    memoryASet(ds, 0x7d6d, 0xff);
    return;
loc_357ad:
    dx = memoryAGet16(ds, 0x7d70);
    dx += 0x0080;
    if ((short)dx < 0)
        goto loc_357ca;
    if (dh < 0x08)
        goto loc_357ca;
    memoryASet(ds, 0x7d72, 0x00);
    dx = 0x0800;
loc_357ca:
    memoryASet16(ds, 0x7d70, dx);
loc_357ce:
    al = memoryAGet(ds, 0x7d6c);
    al &= 0x03;
    if (al)
        goto loc_357e0;
    memoryASet(ds, 0x7d78, 0x02);
    return;
loc_357e0:
    if (al != 0x02)
        goto loc_357f9;
    memoryASet(ds, 0x7d79, 0x01);
    ax = memoryAGet16(ds, si + 2);
    flags.carry = (al + 0xfe) >= 0x100;
    al += 0xfe;
    if (flags.carry)
        goto loc_3580e;
    goto loc_35b5f;
loc_357f9:
    memoryASet(ds, 0x7d79, 0x00);
    ax = memoryAGet16(ds, si + 2);
    ax += 0x0002;
    if (al < 0xe8)
        goto loc_3580e;
    goto loc_35b6f;
loc_3580e:
    dx = memoryAGet16(ds, si + 4);
    bl = al;
    al = memoryAGet(ds, 0x7d68);
    if (!al)
        goto loc_35823;
    sub_352ea();
    goto loc_35826;
  // gap 1 bytes
loc_35823:
    sub_3536c();
loc_35826:
    al = memoryAGet(ds, 0x7d67);
    cl = al;
    al &= 0x70;
    if (!al)
        goto loc_35833;
    return;
loc_35833:
    memoryASet(ds, si + 2, bl);
    if (!(cl & 0x04))
        goto loc_3583e;
    goto loc_35b7f;
loc_3583e:
    return;
loc_3583f:
    ax = memoryAGet16(ds, 0x7d70);
    if ((short)ax >= 0)
        goto loc_35865;
    memoryASet16(ds, 0x7d6e, 0x00ff);
    ax = memoryAGet16(ds, si + 4);
    al &= 0xf8;
    memoryASet16(ds, si + 4, ax);
    memoryASet(ds, 0x7d72, 0x00);
    memoryASet16(ds, 0x7d70, 0x0000);
    goto loc_357ce;
loc_35865:
    ax = memoryAGet16(ds, si + 4);
    al &= 0xf8;
    al |= 0x03;
    memoryASet16(ds, si + 4, ax);
    memoryASet(ds, 0x7d72, 0x00);
    if (!(cl & 0x20))
        goto loc_358ac;
    bx = memoryAGet16(ds, 0x7d70);
    al = bh;
    if ((char)al < 0)
        goto loc_358ac;
    if (al < 0x02)
        goto loc_358ac;
    if (!(memoryAGet(ds, 0x7d6c) & 0x08))
        goto loc_358a0;
    cx = 0xf800;
    goto loc_358a5;
  // gap 1 bytes
loc_358a0:
    cx = 0x00fe;
    cx -= bx;
loc_358a5:
    memoryASet16(ds, 0x7d70, cx);
    goto loc_357ce;
loc_358ac:
    memoryASet16(ds, 0x7d70, 0x0100);
    al = memoryAGet(ds, 0x7d6c);
    dh = al;
    al = memoryAGet(ds, 0x7d69);
    flags.zero = !(al & al);
    al = dh;
    if (flags.zero)
        goto loc_358c3;
    goto loc_359b8;
loc_358c3:
    if (dh & 0x10)
        goto loc_358cb;
    goto loc_359b8;
loc_358cb:
    al &= 0x03;
    if (!al)
        goto loc_358fb;
    ax = memoryAGet16(ds, si + 4);
    ax += 0x000e;
    memoryASet16(ds, 0x7d7c, ax);
    memoryASet(ds, 0x7d79, 0x01);
    al = memoryAGet(ds, si + 2);
    if (!(dh & 0x01))
        goto loc_358f2;
    memoryASet(ds, 0x7d79, 0x00);
    al += 0x17;
loc_358f2:
    memoryASet(ds, 0x7d7b, al);
    memoryASet(ds, 0x7d6a, 0xff);
    return;
loc_358fb:
    al = dh;
    al &= 0x0c;
    if (al != 0x08)
        goto loc_35973;
    memoryASet(ds, 0x7d6b, 0xff);
    al = memoryAGet(ds, 0x7d86);
    if (!al)
        goto loc_35916;
    return;
loc_35916:
    memoryASet(ds, 0x7d86, 0xff);
    al = memoryAGet(ds, 0x7eae);
    if (!al)
        goto loc_35926;
    return;
loc_35926:
    al = memoryAGet(ds, 0x7e45);
    if (al)
        goto loc_35931;
    return;
loc_35931:
    al--;
    memoryASet(ds, 0x7e45, al);
    memoryASet16(ds, 0x7eae, 0x0002);
    ax = memoryAGet16(ds, si + 4);
    ax += 0x0006;
    memoryASet16(ds, 0x7eb2, ax);
    al = memoryAGet(ds, si + 2);
    memoryASet(ds, 0x7eb0, al);
    memoryASet16(ds, 0x7d87, 0x0008);
    memoryASet(ds, 0x7eb6, 0x20);
    ax = 0x7d9c;
    memoryASet16(ds, 0x7d9a, ax);
    al = memoryAGet(ds, 0x7d79);
    if (al)
        goto loc_35967;
    return;
loc_35967:
    memoryASet16(ds, 0x7d87, 0xfff8);
    memoryASet(ds, 0x7eb6, 0x21);
    return;
loc_35973:
    memoryASet(ds, 0x7d86, 0x00);
    memoryASet(ds, 0x7d78, 0x00);
    if (dh & 0x04)
        goto loc_35986;
    return;
loc_35986:
    if (!(memoryAGet(ds, 0x7ede) & 0xff))
        goto loc_35991;
    return;
loc_35991:
    al = memoryAGet(ds, 0x7e47);
    if (al)
        goto loc_3599c;
    return;
loc_3599c:
    al--;
    memoryASet(ds, 0x7e47, al);
    memoryASet(ds, 0x7ede, 0x03);
    memoryASet(ds, 0x7d81, 0x2d);
    al = memoryAGet(ds, si + 2);
    memoryASet(ds, 0x7ee0, al);
    ax = memoryAGet16(ds, si + 4);
    memoryASet16(ds, 0x7ee2, ax);
    return;
loc_359b8:
    if (!(dh & 0x08))
        goto loc_359e2;
    if (!(cl & 0x02))
        goto loc_359ce;
    memoryASet(ds, 0x7d6d, 0xff);
    return;
loc_359ce:
    memoryASet16(ds, 0x7d70, 0xfa80);
    memoryASet(ds, 0x7d72, 0x00);
    ax = 0x7de9;
    memoryASet16(ds, 0x7d9a, ax);
    goto loc_357ce;
loc_359e2:
    if (dh & 0x04)
        goto loc_359ed;
    goto loc_357ce;
loc_359ed:
    if (!(cl & 0x80))
        goto loc_35a1b;
    al = memoryAGet(ds, 0x7d6c);
    al &= 0x03;
    if (al)
        goto loc_35a1b;
    al = memoryAGet(ds, si + 2);
    al &= 0x1f;
    if (al >= 0x0a)
        goto loc_35a1b;
    al = memoryAGet(ds, si + 2);
    al &= 0xf0;
    al |= 0x04;
    memoryASet(ds, si + 2, al);
    memoryASet(ds, 0x7d6d, 0xff);
    return;
loc_35a1b:
    memoryASet(ds, 0x7d68, 0xff);
    goto loc_357ce;
loc_35a23:
    al = memoryAGet(ds, 0x7d6c);
    al &= 0x0f;
    if (al)
        goto loc_35a33;
    memoryASet(ds, 0x7d78, 0x00);
    return;
loc_35a33:
    al &= 0x0c;
    if (!al)
        goto loc_35aa1;
    dx = memoryAGet16(ds, si + 4);
    if (al != 0x08)
        goto loc_35a4a;
    cx = 0xfffe;
    goto loc_35a4d;
  // gap 1 bytes
loc_35a4a:
    cx = 0x0002;
loc_35a4d:
    dx += cx;
    bl = memoryAGet(ds, si + 2);
    sub_3536c();
    al = memoryAGet(ds, 0x7d67);
    cl = al;
    al &= 0x70;
    if (!al)
        goto loc_35a77;
    if (ch & 0x80)
        goto loc_35a6f;
    memoryASet(ds, 0x7d6d, 0x00);
    return;
loc_35a6f:
    if (!(cl & 0x10))
        goto loc_35aa1;
loc_35a77:
    memoryASet16(ds, si + 4, dx);
    if (!(cl & 0x04))
        goto loc_35a82;
    goto loc_35b7f;
loc_35a82:
    if (cl & 0x82)
        goto loc_35aa1;
    dx = 0x0100;
    if ((short)cx >= 0)
        goto loc_35a97;
    dx = 0xfd00;
loc_35a97:
    memoryASet16(ds, 0x7d70, dx);
    memoryASet(ds, 0x7d6d, 0x00);
    return;
loc_35aa1:
    al = memoryAGet(ds, 0x7d6c);
    al &= 0x03;
    if (al)
        goto loc_35aac;
    return;
loc_35aac:
    flags.zero = al == 0x01;
    al = memoryAGet(ds, si + 2);
    if (flags.zero)
        goto loc_35ac0;
    flags.carry = (al + 0xfe) >= 0x100;
    al += 0xfe;
    if (flags.carry)
        goto loc_35abd;
    goto loc_35b5f;
loc_35abd:
    goto loc_35ac9;
  // gap 1 bytes
loc_35ac0:
    al += 0x02;
    if (al < 0xe8)
        goto loc_35ac9;
    goto loc_35b6f;
loc_35ac9:
    bl = al;
    dx = memoryAGet16(ds, si + 4);
    sub_3536c();
    al = memoryAGet(ds, 0x7d67);
    cl = al;
    al &= 0x60;
    if (!al)
        goto loc_35ade;
    return;
loc_35ade:
    memoryASet(ds, si + 2, bl);
    if (!(cl & 0x04))
        goto loc_35ae9;
    goto loc_35b7f;
loc_35ae9:
    al = cl;
    al &= 0x82;
    if (!al)
        goto loc_35af3;
    return;
loc_35af3:
    memoryASet(ds, 0x7d6d, 0x00);
    al = memoryAGet(ds, 0x7d6c);
    if (al & 0x08)
        goto loc_35b03;
    return;
loc_35b03:
    memoryASet16(ds, 0x7d70, 0xfd00);
    return;
loc_35b0a:
    memoryASet(ds, si + 8, 0x19);
    if (!(memoryAGet(ds, si + 2) & 0x04))
        goto loc_35b1b;
    memoryASet(ds, si + 8, 0x1a);
loc_35b1b:
    al = memoryAGet(ds, 0x7d7a);
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, si + 2, al);
    al = memoryAGet(ds, 0x7d72);
    ah = memoryAGet(ds, si + 4);
    bl = memoryAGet(ds, si + 5);
    cx = memoryAGet16(ds, 0x7d70);
    bh = 0x00;
    if ((short)cx >= 0)
        goto loc_35b3c;
    bh--;
loc_35b3c:
    flags.carry = (ax + cx) >= 0x10000;
    ax += cx;
    bl += bh + flags.carry;
    memoryASet(ds, 0x7d72, al);
    memoryASet(ds, si + 4, ah);
    memoryASet(ds, si + 5, bl);
    cx += 0x0080;
    memoryASet16(ds, 0x7d70, cx);
    if (bl != 0x01)
        goto loc_35b5e;
    memoryASet(ds, 0x7d92, 0xff);
loc_35b5e:
    return;
loc_35b5f:
    memoryASet(ds, 0x7d76, 0xff);
    memoryASet(ds, 0x7d77, 0x00);
    memoryASet16(ds, si + 2, 0x00e2);
    return;
loc_35b6f:
    memoryASet(ds, 0x7d76, 0xff);
    memoryASet(ds, 0x7d77, 0x01);
    memoryASet16(ds, si + 2, 0x0004);
    return;
loc_35b7f:
    al = memoryAGet(ds, 0x7d75);
    if (!al)
        goto loc_35b8a;
    return;
loc_35b8a:
    ax = 0x7da9;
    memoryASet16(ds, 0x7d9a, ax);
    memoryASet(ds, 0x7d75, 0xff);
    memoryASet16(ds, 0x7d70, 0xfc00);
    al = memoryAGet(ds, 0x7e80);
    if (al >= 0x80)
        goto loc_35bab;
    memoryASet(ds, 0x7d7a, 0x03);
    return;
loc_35bab:
    memoryASet(ds, 0x7d7a, 0xfd);
}
void sub_35b7f()
{
    al = memoryAGet(ds, 0x7d75);
    if (!al)
        goto loc_35b8a;
    return;
loc_35b8a:
    ax = 0x7da9;
    memoryASet16(ds, 0x7d9a, ax);
    memoryASet(ds, 0x7d75, 0xff);
    memoryASet16(ds, 0x7d70, 0xfc00);
    al = memoryAGet(ds, 0x7e80);
    if (al >= 0x80)
        goto loc_35bab;
    memoryASet(ds, 0x7d7a, 0x03);
    return;
loc_35bab:
    memoryASet(ds, 0x7d7a, 0xfd);
}
void sub_35c76()
{
    push(ds);
    al = memoryAGet(ds, 0x7d90);
    ah = 0x00;
    push(ax);
    memoryASet16(ds, 0x971e, ax);
    dx = 0x1fc1;
    ds = dx;
    dx = 0xa000;
    es = dx;
    ax = 0x2800;
    memoryASet16(ds, 0x4907, ax);
    sub_34947();
    bx = pop();
    bl += bl;
    bx += 0x48cc;
    bx = memoryAGet16(ds, bx);
    di = 0x0005;
    sub_36139();
    di = 0x0f04;
    sub_3612b();
    ds = pop();
    sub_35e32();
    sub_35ee0();
    sub_35f5c();
    sub_35f0e();
    sub_35d5e();
    memoryASet(ds, 0x7e43, 0x00);
loc_35cbd:
    sync();
    sub_3496b();
    sub_35f0e();
    sub_3496b();
    sub_35e97();
    sub_35d5e();
    sub_3496b();
    sub_35f0e();
    sub_35f5c();
    sub_3496b();
    sub_35d5e();
    if (memoryAGet(ds, 0x7e43) != 0x39)
        goto loc_35cbd;
}
void sub_35ce3()
{
    push(ds);
loc_35ce4:
    dx = 0x1fc1;
    ds = dx;
    dx = 0xb800;
    es = dx;
    ax = 0x2000;
    memoryASet16(ds, 0x4907, ax);
    sub_34947();
    bx = 0x4642;
    di = 0x0004;
    sub_3612b();
    di = 0x0647;
    sub_3612b();
    ax = 0x1040;
    ds = ax;
    cx = 0x01f4;
loc_35d0e:
    sub_3496b();
    sub_345e3();
    if (flags.zero)
        goto loc_35d5a;
    if (--cx)
        goto loc_35d0e;
    sub_34947();
    dx = 0x1fc1;
    ds = dx;
    dx = 0xb800;
    es = dx;
    ax = 0x0000;
    memoryASet16(ds, 0x4905, ax);
    sub_34947();
    bx = 0x47a1;
    di = 0x0284;
    sub_3612b();
    bx = 0x4888;
    di = 0x0c89;
    sub_3612b();
    ax = 0x1040;
    ds = ax;
    cx = 0x01f4;
loc_35d4b:
    sub_3496b();
    sub_345e3();
    if (flags.zero)
        goto loc_35d5a;
    if (--cx)
        goto loc_35d4b;
    goto loc_35ce4;
loc_35d5a:
    push(ds);
    es = pop();
    ds = pop();
}
void sub_35d5e()
{
    ax = memoryAGet16(ds, 0x9720);
    bx = ax;
    bx &= 0x0003;
    bx += bx;
    flags.carry = (bx + 0x9661) >= 0x10000;
    bx += 0x9661;
    cx = memoryAGet16(ds, bx);
    ax = rcr16(ax, 0x0001);
    ax = rcr16(ax, 0x0001);
    ax &= 0x0003;
    di = 0x03d0;
    di += ax;
    ax = memoryAGet16(ds, 0x9724);
    dx = 0x0050;
    mul16(dx);
    di += ax;
    bl = memoryAGet(ds, 0x9728);
    bh = 0;
    bx += bx;
    bx += 0x0100;
    si = memoryAGet16(ds, bx);
    push(ds);
    dx = 0x03ce;
    ax = 0x0001;
    out16(dx, ax);
    al = 0x03;
    out16(dx, ax);
    al = 0x05;
    out16(dx, ax);
    ds = cx;
    cx = 0x0015;
loc_35da5:
    sub_35dc5();
    sub_35dc5();
    di += 0x0024;
    if (--cx)
        goto loc_35da5;
    ax = 0x0f02;
    out16(dx, ax);
    dx = 0x03ce;
    ax = 0x0105;
    out16(dx, ax);
    ax = 0x0001;
    out16(dx, ax);
    ax = 0xff08;
    out16(dx, ax);
    ds = pop();
}
void sub_35dc5()
{
    di++;
    dx = 0x03ce;
    ax = lodsw<DS_SI>();
    al = ~al;
    ah = al;
    al = 0x08;
    out16(dx, ax);
    dx = 0x03c4;
    ax = 0x0f02;
    out16(dx, ax);
    ah = memoryAGet(es, di);
    ah = 0x01;
    out16(dx, ax);
    ax = lodsw<DS_SI>();
    memoryASet(es, di, al);
    ax = 0x0202;
    out16(dx, ax);
    ax = lodsw<DS_SI>();
    memoryASet(es, di, al);
    ax = 0x0402;
    out16(dx, ax);
    ax = lodsw<DS_SI>();
    memoryASet(es, di, al);
    ax = 0x0802;
    out16(dx, ax);
    ax = lodsw<DS_SI>();
    memoryASet(es, di, al);
    di--;
    si -= 0x0009;
    dx = 0x03ce;
    ax = lodsw<DS_SI>();
    al = ~al;
    ah = al;
    al = 0x08;
    out16(dx, ax);
    dx = 0x03c4;
    ax = 0x0f02;
    out16(dx, ax);
    ah = memoryAGet(es, di);
    ah = 0x01;
    out16(dx, ax);
    ax = lodsw<DS_SI>();
    memoryASet(es, di, al);
    ax = 0x0202;
    out16(dx, ax);
    ax = lodsw<DS_SI>();
    memoryASet(es, di, al);
    ax = 0x0402;
    out16(dx, ax);
    ax = lodsw<DS_SI>();
    memoryASet(es, di, al);
    ax = 0x0802;
    out16(dx, ax);
    al = lodsb<DS_SI>();
    stosb<ES_DI>(al);
    di++;
}
void sub_35e32()
{
    bx = memoryAGet16(ds, 0x971e);
    bx += bx;
    bx += 0x974c;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, 0x972a, ax);
    memoryASet16(ds, 0x9730, 0x0000);
    bx = ax;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, 0x9720, ax);
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, 0x9724, ax);
    bx += 0x0004;
    memoryASet16(ds, 0x972e, bx);
    sub_35e63();
    memoryASet(ds, 0x9730, memoryAGet(ds, 0x9730) - 1);
}
void sub_35e63()
{
    bx = memoryAGet16(ds, 0x972e);
    ax = memoryAGet16(ds, bx);
    if (!ax)
        goto loc_35e93;
    memoryASet16(ds, 0x972c, ax);
    ax = memoryAGet16(ds, bx + 2);
    memoryASet16(ds, 0x9722, ax);
    ax = memoryAGet16(ds, bx + 4);
    memoryASet16(ds, 0x9726, ax);
    ax = memoryAGet16(ds, bx + 6);
    memoryASet16(ds, 0x9732, ax);
    bx += 0x0008;
    memoryASet16(ds, 0x972e, bx);
    memoryASet16(ds, 0x9734, 0x0000);
    return;
loc_35e93:
    memoryASet16(ds, 0x9730, ax);
}
void sub_35e97()
{
    if (memoryAGet16(ds, 0x9730) == 0x0000)
        goto loc_35ee0;
    ah = 0;
    bx = memoryAGet16(ds, 0x9734);
    si = memoryAGet16(ds, 0x9732);
    al = memoryAGet(ds, bx + si);
    if (ax)
        goto loc_35eb9;
    memoryASet16(ds, 0x9734, ax);
    ax = memoryAGet16(ds, si);
loc_35eb9:
    memoryASet16(ds, 0x9728, ax);
    memoryASet16(ds, 0x9734, memoryAGet16(ds, 0x9734) + 1);
    ax = memoryAGet16(ds, 0x9720);
    ax += memoryAGet16(ds, 0x9722);
    memoryASet16(ds, 0x9720, ax);
    ax = memoryAGet16(ds, 0x9724);
    ax += memoryAGet16(ds, 0x9726);
    memoryASet16(ds, 0x9724, ax);
    memoryASet16(ds, 0x972c, memoryAGet16(ds, 0x972c) - 1);
    if (memoryAGet16(ds, 0x972c))
        goto loc_35ee0;
    sub_35e63();
loc_35ee0:
    bx = memoryAGet16(ds, 0x971e);
    push(ds);
    cx = 0x1fc1;
    ds = cx;
    di = 0x03d0;
    cx = 0x0006;
    bx += 0x4909;
    dl = memoryAGet(ds, bx);
loc_35ef6:
    push(cx);
    push(di);
    cx = 0x0006;
loc_35efb:
    al = dl;
    sub_36161();
    dl++;
    if (--cx)
        goto loc_35efb;
    di = pop();
    di += 0x0140;
    cx = pop();
    if (--cx)
        goto loc_35ef6;
    ds = pop();
}
void sub_35ee0()
{
    bx = memoryAGet16(ds, 0x971e);
    push(ds);
    cx = 0x1fc1;
    ds = cx;
    di = 0x03d0;
    cx = 0x0006;
    bx += 0x4909;
    dl = memoryAGet(ds, bx);
loc_35ef6:
    push(cx);
    push(di);
    cx = 0x0006;
loc_35efb:
    al = dl;
    sub_36161();
    dl++;
    if (--cx)
        goto loc_35efb;
    di = pop();
    di += 0x0140;
    cx = pop();
    if (--cx)
        goto loc_35ef6;
    ds = pop();
}
void sub_35f0e()
{
    al = memoryAGet(ds, 0x971c);
    al++;
    memoryASet(ds, 0x971c, al);
    push(ds);
    push(es);
    ds = pop();
    al &= 0x01;
    if (!al)
        goto loc_35f37;
    dx = 0x0022;
    si = 0x2828;
    di = 0x0290;
    sub_35f4e();
    si = 0x2a00;
    di = 0x0b50;
    sub_35f4e();
    ds = pop();
    return;
loc_35f37:
    dx = 0x0022;
    si = 0x2a00;
    di = 0x0290;
    sub_35f4e();
    si = 0x2830;
    di = 0x0b50;
    sub_35f4e();
    ds = pop();
}
void sub_35f4e()
{
    cx = 0x0008;
loc_35f51:
    movsb<ES_DI, DS_SI>();
    stosb<ES_DI>(al);
    stosb<ES_DI>(al);
    stosb<ES_DI>(al);
    stosb<ES_DI>(al);
    stosb<ES_DI>(al);
    di += dx;
    if (--cx)
        goto loc_35f51;
}
void sub_35f5c()
{
    al = memoryAGet(ds, 0x971c);
    push(ds);
    push(es);
    ds = pop();
    al &= 0x02;
    if (!al)
        goto loc_35f80;
    dx = 0x0028;
    si = 0x2820;
    di = 0x028f;
    sub_35f97();
    si = 0x2820;
    di = 0x0296;
    sub_35f97();
    ds = pop();
    return;
loc_35f80:
    dx = 0x0028;
    si = 0x2958;
    di = 0x028f;
    sub_35f97();
    si = 0x2958;
    di = 0x0296;
    sub_35f97();
    ds = pop();
}
void sub_35f97()
{
    cx = 0x0008;
loc_35f9a:
    al = lodsb<DS_SI>();
    memoryASet(ds, di, al);
    memoryASet(ds, di + 320, al);
    memoryASet(ds, di + 640, al);
    memoryASet(ds, di + 960, al);
    memoryASet(ds, di + 1280, al);
    memoryASet(ds, di + 1600, al);
    memoryASet(ds, di + 1920, al);
    memoryASet(ds, di + 2240, al);
    di += dx;
    if (--cx)
        goto loc_35f9a;
}
void sub_35fbe()
{
    push(ds);
    al = 0x00;
    memoryASet(ds, 0x48f4, al);
    memoryASet(ds, 0x48f5, al);
    memoryASet(ds, 0x48f6, al);
    dx = 0x1fc1;
    ds = dx;
    es = dx;
    cx = 0x000a;
    di = 0x48fb;
    al = 0x3b;
    for (; cx != 0; --cx) stosb<ES_DI>(al);
    dx = 0xa000;
    es = dx;
    ax = 0x2000;
    memoryASet16(ds, 0x4907, ax);
    sub_34947();
    bx = 0x457d;
    di = 0x0004;
    sub_3612b();
    di = 0x0649;
    sub_36139();
    di = 0x0a0e;
    sub_3612b();
    di = 0x17cf;
    sub_36139();
    ax = 0x1040;
    es = ax;
loc_36009:
    sub_3496b();
    sub_3496b();
    sub_3496b();
    sub_3496b();
    if (memoryAGet(ds, 0x48f6) == 0x0a)
        goto loc_36024;
    sub_36026();
    goto loc_36009;
loc_36024:
    ds = pop();
}
void sub_36026()
{
    al = memoryAGet(es, 0x7e44);
    bx = memoryAGet16(ds, 0x48f4);
    if (!(al & 0x10))
        goto loc_36038;
    goto loc_360c7;
loc_36038:
    if (!(al & 0x01))
        goto loc_3604b;
    bl++;
    if (bl != 0x06)
        goto loc_3604b;
    bl = 0x05;
loc_3604b:
    if (!(al & 0x02))
        goto loc_3605b;
    bl--;
    if ((char)bl >= 0)
        goto loc_3605b;
    bl = 0x00;
loc_3605b:
    if (!(al & 0x04))
        goto loc_3606e;
    bh++;
    if (bh != 0x05)
        goto loc_3606e;
    bh = 0x04;
loc_3606e:
    if (!(al & 0x08))
        goto loc_3607e;
    bh--;
    if ((char)bh >= 0)
        goto loc_3607e;
    bh = 0x00;
loc_3607e:
    memoryASet16(ds, 0x48f4, bx);
    bx = memoryAGet16(ds, 0x48f4);
    bh += bh;
    al = bh;
    al += al;
    al += bh;
    al += bl;
    ah = 0x00;
    bx = 0x48d6;
    bx += ax;
    al = memoryAGet(ds, bx);
    memoryASet(ds, 0x48f7, al);
    di = memoryAGet16(ds, 0x48f8);
    al = 0x40;
    sub_36150();
    bx = memoryAGet16(ds, 0x48f4);
    al = bh;
    ah = 0x00;
    dx = 0x0280;
    mul16(dx);
    bl += bl;
    bh = 0x00;
    di = 0x0b4e;
    di += ax;
    di += bx;
    memoryASet16(ds, 0x48f8, di);
    al = 0x3e;
    sub_36150();
    return;
loc_360c7:
    push(es);
    ax = 0xa000;
    es = ax;
    al = memoryAGet(ds, 0x48f7);
    if (al != 0x3d)
        goto loc_360df;
    memoryASet(ds, 0x48f6, 0x0a);
    goto loc_36121;
  // gap 1 bytes
loc_360df:
    if (al != 0x3c)
        goto loc_36101;
    if (memoryAGet(ds, 0x48f6) == 0x00)
        goto loc_36121;
    memoryASet(ds, 0x48f6, memoryAGet(ds, 0x48f6) - 1);
    bl = memoryAGet(ds, 0x48f6);
    al = 0x3b;
    memoryASet(ds, 0x48f6, memoryAGet(ds, 0x48f6) - 1);
    goto loc_36105;
  // gap 1 bytes
loc_36101:
    bl = memoryAGet(ds, 0x48f6);
loc_36105:
    bh = al;
    push(bx);
    bh = 0;
    di = 0x17cf;
    di += bx;
    sub_36161();
    bx = pop();
    al = bh;
    bh = 0;
    bx += 0x48fb;
    memoryASet(ds, bx, al);
    memoryASet(ds, 0x48f6, memoryAGet(ds, 0x48f6) + 1);
loc_36121:
    es = pop();
loc_36122:
    sync(); return;
    sync();
    if (memoryAGet(es, 0x7e44) & 0x10)
        goto loc_36122;
}
void sub_3612b()
{
loc_3612b:
    push(di);
    sub_36139();
    di = pop();
    di += 0x0140;
    if (al != 0xfe)
        goto loc_3612b;
}
void sub_36139()
{
loc_36139:
    al = memoryAGet(ds, bx);
    bx++;
    if (al == 0xff)
        goto loc_3614f;
    if (al == 0xfe)
        goto loc_3614f;
    sub_36150();
    goto loc_36139;
loc_3614f:
    return;
}
void sub_36150()
{
    push(ds);
    push(es);
    push(dx);
    dx = 0xa000;
    es = dx;
    ds = dx;
    dx = pop();
    sub_36161();
    es = pop();
    ds = pop();
}
void sub_36161()
{
    push(es);
    push(ds);
    push(di);
    push(cx);
    cx = 0x1fc1;
    ds = cx;
    cx = memoryAGet16(ds, 0x4907);
    push(es);
    ds = pop();
    ah = 0x00;
    ax += ax;
    ax += ax;
    ax += ax;
    ax += cx;
    si = ax;
    movsb<ES_DI, DS_SI>();
    di += 0x0027;
    movsb<ES_DI, DS_SI>();
    di += 0x0027;
    movsb<ES_DI, DS_SI>();
    di += 0x0027;
    movsb<ES_DI, DS_SI>();
    di += 0x0027;
    movsb<ES_DI, DS_SI>();
    di += 0x0027;
    movsb<ES_DI, DS_SI>();
    di += 0x0027;
    movsb<ES_DI, DS_SI>();
    di += 0x0027;
    movsb<ES_DI, DS_SI>();
    cx = pop();
    di = pop();
    di++;
    ds = pop();
    es = pop();
}
void sub_3619f()
{
    push(ds);
    ax = 0x1fc1;
    ds = ax;
    es = ax;
    di = 0x4785;
    si = 0x4769;
loc_361ad:
    if (si == bx)
        goto loc_361c1;
    cx = 0x000d;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    di -= 0x0036;
    si -= 0x0036;
    goto loc_361ad;
loc_361c1:
    cx = 0x000d;
    for (; cx != 0; --cx) movsw<ES_DI, DS_SI>();
    ax = memoryAGet16(ds, 0x490e);
    memoryASet16(ds, bx, ax);
    bx++;
    bx++;
    ax = memoryAGet16(ds, 0x4910);
    memoryASet16(ds, bx, ax);
    bx++;
    bx++;
    ax = memoryAGet16(ds, 0x4912);
    memoryASet16(ds, bx, ax);
    bx += 0x000c;
    di = bx;
    si = 0x48fb;
    cx = 0x000a;
    for (; cx != 0; --cx) movsb<ES_DI, DS_SI>();
    ds = pop();
}
void sub_361e8()
{
    ax = 0x1fc1;
    ds = ax;
    si = 0x46a5;
    cx = 0x0008;
loc_361f3:
    di = 0x490e;
    al = memoryAGet(ds, si);
    if (al < memoryAGet(ds, di))
        goto loc_3622b;
    if (al != memoryAGet(ds, di))
        goto loc_3621f;
    push(si);
    bx = 0x0005;
loc_36208:
    si++;
    di++;
    al = memoryAGet(ds, si);
    if (al < memoryAGet(ds, di))
        goto loc_3622a;
    if (al != memoryAGet(ds, di))
        goto loc_3621e;
    bx--;
    if (bx)
        goto loc_36208;
    goto loc_3622a;
  // gap 1 bytes
loc_3621e:
    si = pop();
loc_3621f:
    si += 0x001c;
    if (--cx)
        goto loc_361f3;
    ax = 0x1040;
    ds = ax;
    return;
loc_3622a:
    si = pop();
loc_3622b:
    push(si);
    sub_35fbe();
    bx = pop();
    sub_3619f();
    ax = 0x1040;
    ds = ax;
}
void sub_36239()
{
    ax = 0x1040;
    ds = ax;
    es = ax;
    di = memoryAGet16(ds, 0x7d64);
loc_36244:
    al = memoryAGet(ds, di);
    if (al != 0xff)
        goto loc_3624e;
    return;
loc_3624e:
    if (al >= dh)
        goto loc_3625a;
    di += 0x0005;
    goto loc_36244;
loc_3625a:
    dh += dl;
loc_3625c:
    al = memoryAGet(ds, di);
    if (al != 0xff)
        goto loc_36266;
    return;
loc_36266:
    if (al < dh)
        goto loc_3626e;
    return;
loc_3626e:
    push(dx);
    al &= 0xf8;
    dl = al;
    al = memoryAGet(ds, di + 1);
    if ((char)al >= 0)
        goto loc_36280;
    goto loc_3638e;
loc_36280:
    if (!(memoryAGet(ds, di + 2) & 0x02))
        goto loc_362a0;
    if (memoryAGet(ds, 0x7e4e) == 0x00)
        goto loc_36296;
    goto loc_3638e;
loc_36296:
    si = 0x7e4e;
    memoryASet(ds, si + 38, 0x00);
    goto loc_362bd;
  // gap 1 bytes
loc_362a0:
    if (al >= 0x10)
        goto loc_362b2;
    sub_363b5();
    if (flags.zero)
        goto loc_362bd;
    goto loc_3638e;
loc_362b2:
    sub_36395();
    if (flags.zero)
        goto loc_362bd;
    goto loc_3638e;
loc_362bd:
    memoryASet(ds, si, al);
    al = memoryAGet(ds, di + 3);
    dh = al;
    al &= 0xf8;
    memoryASet(ds, si + 2, al);
    memoryASet(ds, si + 28, al);
    dh &= 0x07;
    dl -= memoryAGet(ds, 0x7e38);
    dl += dh;
    dh = 0;
    dx += dx;
    dx += dx;
    dx += dx;
    if (memoryAGet(ds, di + 2) & 0x02)
        goto loc_362e9;
    dx += 0x0003;
loc_362e9:
    memoryASet16(ds, si + 4, dx);
    memoryASet16(ds, si + 30, dx);
    memoryASet16(ds, si + 12, 0x0000);
    bl = memoryAGet(ds, di + 1);
    bh = 0;
    bx += bx;
    bx += bx;
    bx += bx;
    bx += 0x9326;
    al = memoryAGet(ds, bx);
    memoryASet(ds, si + 14, al);
    bx++;
    al = memoryAGet(ds, bx);
    memoryASet(ds, si + 16, al);
    bx++;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, si + 32, ax);
    memoryASet(ds, si + 8, al);
    bx++;
    bx++;
    ax = memoryAGet16(ds, bx);
    memoryASet16(ds, si + 34, ax);
    memoryASet16(ds, si + 18, di);
    al = memoryAGet(ds, di + 2);
    memoryASet(ds, si + 20, al);
    if (!(al & 0x04))
        goto loc_36331;
    memoryASet(ds, si, memoryAGet(ds, si) | 0x80);
loc_36331:
    al = memoryAGet(ds, di + 2);
    al &= 0xf0;
    if (al != 0xf0)
        goto loc_3634b;
    if (si < 0x7ffe)
        goto loc_3634b;
    cl = memoryAGet(ds, bx);
    memoryASet(ds, si + 32, cl);
loc_3634b:
    al = memoryAGet(ds, di + 4);
    dl = al;
    al &= 0xf8;
    memoryASet(ds, si + 22, al);
    dl &= 0x07;
    al = dl;
    al += al;
    al += al;
    al += al;
    al += al;
    al += al;
    memoryASet(ds, si + 46, al);
    bl = memoryAGet(ds, 0x7e38);
    al = memoryAGet(ds, di);
    al &= 0xf8;
    al -= bl;
    al += dl;
    ah = 0;
    ax += ax;
    ax += ax;
    ax += ax;
    ax += 0x0003;
    memoryASet16(ds, si + 24, ax);
    memoryASet(ds, si + 40, 0x00);
    memoryASet(ds, si + 42, 0x00);
    memoryASet16(ds, si + 44, 0x0000);
loc_3638e:
    dx = pop();
    di += 0x0005;
    goto loc_3625c;
}
void sub_36395() // +returnZero
{
    push(ax);
    si = 0x7f0e;
    cx = 0x0005;
    ax = 0;
loc_3639e:
    flags.zero = ax == memoryAGet16(ds, si);
    if (!flags.zero)
        goto loc_363ab;
    ax = pop();
    memoryASet(ds, si + 38, 0x00);
    return;
loc_363ab:
    si += 0x0030;
    if (--cx)
        goto loc_3639e;
    ax = 0;
    flags.zero = !ax;
    ax++;
    ax = pop();
}
void sub_363b5() // +returnZero
{
    push(ax);
    si = 0x7ffe;
    cx = 0x0003;
    ax = 0;
loc_363be:
    if (al == memoryAGet(ds, si))
        goto loc_363cd;
    if (di == memoryAGet16(ds, si + 18))
        goto loc_363ec;
loc_363cd:
    si += 0x0030;
    if (--cx)
        goto loc_363be;
    si = 0x7ffe;
    cx = 0x0003;
    ax = 0;
loc_363da:
    flags.zero = ax == memoryAGet16(ds, si);
    if (!flags.zero)
        goto loc_363e7;
    ax = pop();
    memoryASet(ds, si + 38, 0x02);
    return;
loc_363e7:
    si += 0x0030;
    if (--cx)
        goto loc_363da;
loc_363ec:
    ax = 0;
    flags.zero = !ax;
    ax++;
    ax = pop();
}
void sub_363f1()
{
    ax = 0x1040;
    ds = ax;
    si = 0x7e4e;
loc_363f9:
    ax = memoryAGet16(ds, si);
    if (!ax)
        goto loc_3640d;
    if (ax == 0x00ff)
        goto loc_36412;
    sub_36413();
loc_3640d:
    si += 0x0030;
    goto loc_363f9;
loc_36412:
    return;
}
void sub_36413()
{
    goto loc_36413;
loc_355f8:
    sub_356ec();
    al = memoryAGet(ds, 0x7d68);
    memoryASet(ds, 0x7d69, al);
    if (memoryAGet(ds, 0x7d75) == 0x00)
        goto loc_3560c;
    return;
loc_3560c:
    if (memoryAGet(ds, 0x7d6a) == 0x00)
        goto loc_35629;
    memoryASet(ds, si + 8, 0x0b);
    if (memoryAGet(ds, 0x7d79) == 0x00)
        goto loc_35628;
    memoryASet(ds, si + 8, 0x17);
loc_35628:
    return;
loc_35629:
    if (memoryAGet(ds, 0x7d6b) == 0x00)
        goto loc_35643;
    memoryASet(ds, si + 8, 0x0a);
    if (memoryAGet(ds, 0x7d79) == 0x00)
        goto loc_35628;
    memoryASet(ds, si + 8, 0x16);
    return;
loc_35643:
    if (memoryAGet(ds, 0x7d6d) == 0x00)
        goto loc_35660;
    memoryASet(ds, si + 8, 0x0c);
    al = memoryAGet(ds, si + 2);
    al ^= memoryAGet(ds, si + 4);
    al &= 0x04;
    if (!al)
        goto loc_35628;
    memoryASet(ds, si + 8, 0x18);
    return;
loc_35660:
    if (memoryAGet(ds, 0x7d68) == 0x00)
        goto loc_35699;
    al = memoryAGet(ds, 0x7d78);
    al++;
    al &= 0x03;
    memoryASet(ds, 0x7d78, al);
    if (al)
        goto loc_3567c;
    sub_36d18();
loc_3567c:
    ah = 0x07;
    if (memoryAGet(ds, 0x7d79) == 0x00)
        goto loc_3568a;
    ah = 0x13;
loc_3568a:
    if (!(memoryAGet(ds, si + 2) & 0x04))
        goto loc_35695;
    ah++;
loc_35695:
    memoryASet(ds, si + 8, ah);
    return;
loc_35699:
    if (memoryAGet16(ds, 0x7d6e) == 0x0000)
        goto loc_356b6;
    memoryASet(ds, si + 8, 0x06);
    if (memoryAGet(ds, 0x7d79) == 0x00)
        goto loc_356eb;
    memoryASet(ds, si + 8, 0x15);
    return;
loc_356b6:
    al = memoryAGet(ds, 0x7d78);
    al++;
    if (al < 0x14)
        goto loc_356c7;
    sub_36d18();
    al = 0x04;
loc_356c7:
    if (al != 0x0c)
        goto loc_356d3;
    sub_36d18();
    al = 0x0c;
loc_356d3:
    memoryASet(ds, 0x7d78, al);
    al >>= 1;
    al >>= 1;
    al += 0x01;
    if (memoryAGet(ds, 0x7d79) == 0x00)
        goto loc_356e8;
    al += 0x0c;
loc_356e8:
    memoryASet(ds, si + 8, al);
loc_356eb:
    return;
  // gap 1171 bytes
loc_35b7f:
    al = memoryAGet(ds, 0x7d75);
    if (!al)
        goto loc_35b8a;
    return;
loc_35b8a:
    ax = 0x7da9;
    memoryASet16(ds, 0x7d9a, ax);
    memoryASet(ds, 0x7d75, 0xff);
    memoryASet16(ds, 0x7d70, 0xfc00);
    al = memoryAGet(ds, 0x7e80);
    if (al >= 0x80)
        goto loc_35bab;
    memoryASet(ds, 0x7d7a, 0x03);
    return;
loc_35bab:
    memoryASet(ds, 0x7d7a, 0xfd);
    return;
loc_35bb1:
    al = memoryAGet(ds, 0x7d87);
    if ((char)al >= 0)
        goto loc_35be0;
    flags.carry = (al + memoryAGet(ds, si + 2)) >= 0x100;
    al += memoryAGet(ds, si + 2);
    if (!flags.carry)
        goto loc_35bf4;
    memoryASet(ds, si + 2, al);
loc_35bc6:
    al += 0x0c;
    memoryASet(ds, 0x7d7e, al);
    dx = memoryAGet16(ds, si + 4);
    dx += 0x0005;
    memoryASet16(ds, 0x7d7f, dx);
    bl = al;
    sub_352c5();
    if (!flags.zero)
        goto loc_35bf4;
    return;
loc_35be0:
    flags.carry = (al + memoryAGet(ds, si + 2)) >= 0x100;
    al += memoryAGet(ds, si + 2);
    if (flags.carry)
        goto loc_35bf4;
    if (al >= 0xe8)
        goto loc_35bf4;
    memoryASet(ds, si + 2, al);
    goto loc_35bc6;
loc_35bf4:
    memoryASet(ds, si, 0x00);
    return;
loc_35bf8:
    al = memoryAGet(ds, 0x7d81);
    al--;
    if (al)
        goto loc_35c0b;
    memoryASet(ds, si, 0x00);
    memoryASet(ds, 0x7d85, 0x00);
    return;
loc_35c0b:
    memoryASet(ds, 0x7d81, al);
    if (al < 0x0a)
        goto loc_35c37;
    if (al != 0x0b)
        goto loc_35c22;
    ax = 0x7e1b;
    memoryASet16(ds, 0x7d9a, ax);
loc_35c22:
    memoryASet(ds, si + 8, 0x22);
    if (!(al & 0x01))
        goto loc_35c31;
    memoryASet(ds, si + 8, 0x23);
loc_35c31:
    memoryASet(ds, 0x7d85, 0x00);
    return;
loc_35c37:
    ah = 0;
    al >>= 1;
    di = 0x8138;
    di += ax;
    al = memoryAGet(ds, di);
    memoryASet(ds, si + 8, al);
    if (al < 0x04)
        goto loc_35c31;
    al = memoryAGet(ds, si + 2);
    al += 0x0c;
    memoryASet(ds, 0x7d82, al);
    ax = memoryAGet16(ds, si + 4);
    ax += 0x000a;
    memoryASet16(ds, 0x7d83, ax);
    memoryASet(ds, 0x7d85, 0xff);
    push(si);
    si = 0x7e7e;
    sub_354fb();
    si = pop();
    if (!flags.zero)
        goto loc_35c6f;
    goto loc_35b7f;
loc_35c6f:
    return;
  // gap 1955 bytes
loc_36413:
    bx = 0x1040;
    ds = bx;
    es = bx;
    al &= 0x7f;
    if (al != 0x47)
        goto loc_36426;
    goto loc_366b1;
loc_36426:
    if (al < 0x18)
        goto loc_36431;
    goto loc_3683f;
  // gap 1 bytes
loc_36431:
    ah = 0;
    ax += ax;
//    ax += 0x80bf;
    di = ax;
    switch (di)
    {
        case 0: goto loc_3674a;
        case 2: goto loc_355f8;
        case 4: goto loc_35bb1;
        case 6: goto loc_35bf8;
        case 8: goto loc_3674b;
        case 10: goto loc_364c3;
        case 12: goto loc_36a11;
        case 14: goto loc_3674b;
        case 16: goto loc_364c3;
        case 18: goto loc_36a11;
        case 20: goto loc_3674b;
        case 22: goto loc_364c3;
        case 24: goto loc_36a11;
        case 26: goto loc_3674b;
        case 28: goto loc_364c3;
        case 30: goto loc_36a11;
        case 32: goto loc_36753;
        case 34: goto loc_36753;
        case 36: goto loc_36725;
        case 38: goto loc_36725;
        case 40: goto loc_36725;
        case 42: goto loc_36725;
        case 44: goto loc_3647b;
        case 46: goto loc_3643c;
        default:
            stop();
    }
loc_3643c:
    memoryASet(ds, si + 8, 0x00);
    if (memoryAGet(ds, 0x7d8f) != 0x00)
        goto loc_3644b;
    return;
loc_3644b:
    bl = memoryAGet(ds, 0x7e80);
    bl += 0x0c;
    dx = memoryAGet16(ds, 0x7e82);
    dx += 0x000a;
    sub_3559d();
    if (flags.zero)
        goto loc_36462;
    return;
loc_36462:
    memoryASet(ds, 0x7d8f, 0x00);
    push(si);
    si = 0x491c;
    sub_34442();
    si = pop();
    memoryASet(ds, si, 0x00);
    ax = 0x7df2;
    memoryASet16(ds, 0x7d9a, ax);
    goto loc_36742;
loc_3647b:
    memoryASet(ds, si + 8, 0x00);
    bl = memoryAGet(ds, 0x7e80);
    bl += 0x0c;
    dx = memoryAGet16(ds, 0x7e82);
    dx += 0x000a;
    sub_3559d();
    if (flags.zero)
        goto loc_36496;
    return;
loc_36496:
    memoryASet(ds, si, 0x00);
    memoryASet(ds, 0x7d8f, 0xff);
    memoryASet(ds, 0x7d95, 0x1e);
    ax = 0x7df2;
    memoryASet16(ds, 0x7d9a, ax);
    push(ds);
    ax = 0x1fc1;
    ds = ax;
    memoryASet16(ds, 0x491c, 0x0200);
    memoryASet16(ds, 0x491e, 0x0000);
    memoryASet16(ds, 0x491f, 0x0000);
    ds = pop();
    return;
loc_364c3:
    memoryASet(ds, 0x7d8e, 0xff);
loc_364c8:
    sub_3653b();
    sub_3555c();
    if (!flags.zero)
        goto loc_364d3;
    goto loc_36674;
loc_364d3:
    if (memoryAGet(ds, 0x7eae) == 0x00)
        goto loc_36502;
    bl = memoryAGet(ds, 0x7eb0);
    if (memoryAGet(ds, 0x7d87) & 0x80)
        goto loc_364ee;
    bl += 0x18;
loc_364ee:
    dx = memoryAGet16(ds, 0x7eb2);
    sub_354c7();
    if (!flags.zero)
        goto loc_36502;
    memoryASet(ds, 0x7eae, 0x00);
    goto loc_36674;
loc_36502:
    if (memoryAGet(ds, 0x7d85) == 0x00)
        goto loc_36514;
    sub_354fb();
    if (!flags.zero)
        goto loc_36514;
    goto loc_36674;
loc_36514:
    if (memoryAGet(ds, 0x7d6a) == 0x00)
        goto loc_36532;
    bl = memoryAGet(ds, 0x7d7b);
    dx = memoryAGet16(ds, 0x7d7c);
    sub_354c7();
    if (!flags.zero)
        goto loc_36532;
    memoryASet(ds, si + 46, 0x14);
loc_36532:
    sub_3545e();
    if (!flags.zero)
        goto loc_3653a;
    goto loc_35b7f;
loc_3653a:
    return;
  // gap 313 bytes
loc_36674:
    memoryASet(ds, si, 0x47);
    memoryASet16(ds, si + 44, 0xfc00);
    ax = 0x7da9;
    memoryASet16(ds, 0x7d9a, ax);
    push(si);
    si = 0x4928;
    sub_34442();
    si = pop();
    if (!(memoryAGet(ds, si + 20) & 0x01))
        goto loc_3669a;
    bx = memoryAGet16(ds, si + 18);
    bx++;
    memoryASet(ds, bx, memoryAGet(ds, bx) | 0x80);
loc_3669a:
    memoryASet(ds, si + 38, 0x02);
    if (memoryAGet(ds, si + 2) >= 0x80)
        goto loc_366a8;
    return;
loc_366a8:
    memoryASet(ds, si + 38, 0xfe);
    return;
  // gap 4 bytes
loc_366b1:
    ah = memoryAGet(ds, si + 32);
    ah += 0x06;
    if (!(memoryAGet(ds, si + 2) & 0x04))
        goto loc_366c2;
    ah++;
loc_366c2:
    memoryASet(ds, si + 8, ah);
    dl = memoryAGet(ds, si + 42);
    dh = memoryAGet(ds, si + 4);
    al = memoryAGet(ds, si + 5);
    cx = memoryAGet16(ds, si + 44);
    ah = 0;
    if ((char)ch >= 0)
        goto loc_366dc;
    ah--;
loc_366dc:
    flags.carry = (dx + cx) >= 0x10000;
    dx += cx;
    al += ah + flags.carry;
    if (!al)
        goto loc_366eb;
    memoryASet(ds, si, 0x00);
    return;
loc_366eb:
    memoryASet(ds, si + 42, dl);
    memoryASet(ds, si + 4, dh);
    memoryASet(ds, si + 5, al);
    ax = memoryAGet16(ds, si + 44);
    ax += 0x0080;
    memoryASet16(ds, si + 44, ax);
    al = memoryAGet(ds, si + 38);
    if ((char)al >= 0)
        goto loc_36718;
    flags.carry = (al + memoryAGet(ds, si + 2)) >= 0x100;
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, si + 2, al);
    if (!flags.carry)
        goto loc_36713;
loc_36712:
    return;
loc_36713:
    memoryASet(ds, si + 2, 0x00);
    return;
loc_36718:
    flags.carry = (al + memoryAGet(ds, si + 2)) >= 0x100;
    al += memoryAGet(ds, si + 2);
    memoryASet(ds, si + 2, al);
    if (!flags.carry)
        goto loc_36712;
    memoryASet(ds, si + 2, 0xe8);
    return;
loc_36725:
    sub_3545e();
    if (flags.zero)
        goto loc_3672e;
    return;
loc_3672e:
    memoryASet(ds, si, 0x00);
    push(si);
    si = 0x492e;
    sub_34442();
    si = pop();
    ax = 0x7df2;
    memoryASet16(ds, 0x7d9a, ax);
    goto loc_36742;
  // gap 1 bytes
loc_36742:
    bx = memoryAGet16(ds, si + 18);
    bx++;
    memoryASet(ds, bx, memoryAGet(ds, bx) | 0x80);
    return;
loc_3674a:
    return;
loc_3674b:
    memoryASet(ds, 0x7d8e, 0x00);
    goto loc_364c8;
loc_36753:
    if (!(memoryAGet(ds, si) & 0x80))
        goto loc_3677a;
    bl = memoryAGet(ds, si + 38);
    bl >>= 1;
    bh = 0;
    bx += 0x8138;
    al = memoryAGet(ds, bx);
    memoryASet(ds, si + 8, al);
    memoryASet(ds, si + 38, memoryAGet(ds, si + 38) - 1);
    if (memoryAGet(ds, si + 38))
        goto loc_36779;
    memoryASet(ds, si, 0x00);
    sub_36742();
loc_36779:
    return;
loc_3677a:
    push(si);
    push(di);
    sub_3545e();
    di = pop();
    si = pop();
    if (flags.zero)
        goto loc_367d9;
    al = memoryAGet(ds, 0x7d6a);
    if (!al)
        goto loc_367a8;
    bl = memoryAGet(ds, 0x7d7b);
    dx = memoryAGet16(ds, 0x7d7c);
    sub_354c7();
    if (!flags.zero)
        goto loc_367a8;
loc_367a0:
    memoryASet(ds, si + 38, 0x0a);
    memoryASet(ds, si, memoryAGet(ds, si) | 0x80);
    return;
loc_367a8:
    al = memoryAGet(ds, 0x7eae);
    if (!al)
        goto loc_367c9;
    bl = memoryAGet(ds, 0x7d7e);
    dx = memoryAGet16(ds, 0x7d7f);
    sub_354c7();
    if (!flags.zero)
        goto loc_367c9;
    memoryASet(ds, 0x7eae, 0x00);
    goto loc_367a0;
loc_367c9:
    al = memoryAGet(ds, 0x7d85);
    if (!al)
        goto loc_367d8;
    sub_354fb();
    if (flags.zero)
        goto loc_367a0;
loc_367d8:
    return;
loc_367d9:
    ax = 0x7df2;
    memoryASet16(ds, 0x7d9a, ax);
    al = memoryAGet(ds, si);
    memoryASet(ds, si, 0x00);
    if (al != 0x10)
        goto loc_367f3;
    memoryASet(ds, 0x7e47, 0x06);
    goto loc_36742;
loc_367f3:
    memoryASet(ds, 0x7e45, 0x06);
    goto loc_36742;
  // gap 68 bytes
loc_3683f:
    sub_36853();
    if (!(memoryAGet(ds, si) & 0x80))
        goto loc_36852;
    sub_3545e();
    if (!flags.zero)
        goto loc_36852;
    goto loc_35b7f;
loc_36852:
    return;
  // gap 446 bytes
loc_36a11:
    sub_36a8b();
    sub_3545e();
    if (!flags.zero)
        goto loc_36a1f;
    sub_35b7f();
loc_36a1f:
    sub_3555c();
    if (!flags.zero)
        goto loc_36a27;
    goto loc_36674;
loc_36a27:
    al = memoryAGet(ds, 0x7eae);
    if (al)
        goto loc_36a34;
    goto loc_36a5c;
  // gap 1 bytes
loc_36a34:
    bl = memoryAGet(ds, 0x7eb0);
    dx = memoryAGet16(ds, 0x7eb2);
    dx += 0x0006;
    if (memoryAGet(ds, 0x7d87) & 0x80)
        goto loc_36a4c;
    bl += 0x18;
loc_36a4c:
    sub_354c7();
    if (!flags.zero)
        goto loc_36a5c;
    memoryASet(ds, 0x7eae, 0x00);
    goto loc_36674;
loc_36a5c:
    al = memoryAGet(ds, 0x7d85);
    if (!al)
        goto loc_36a6e;
    sub_354fb();
    if (!flags.zero)
        goto loc_36a6e;
    goto loc_36674;
loc_36a6e:
    al = memoryAGet(ds, 0x7d6a);
    if (al)
        goto loc_36a79;
loc_36a78:
    return;
loc_36a79:
    bl = memoryAGet(ds, 0x7d7b);
    dx = memoryAGet16(ds, 0x7d7c);
    sub_354c7();
    if (!flags.zero)
        goto loc_36a78;
    memoryASet(ds, si + 46, 0x14);
}
void sub_3653b()
{
    dl = memoryAGet(ds, si + 42);
    dh = memoryAGet(ds, si + 4);
    al = memoryAGet(ds, si + 5);
    cx = memoryAGet16(ds, si + 44);
    ah = 0;
    if (!(ch & 0x80))
        goto loc_36553;
    ah--;
loc_36553:
    flags.carry = (dx + cx) >= 0x10000;
    dx += cx;
    al += ah + flags.carry;
    ah = dl;
    dl = dh;
    dh = al;
    if (dx < 0x0140)
        goto loc_3656c;
    sub_3680a();
    goto loc_366ad;
loc_3656c:
    bl = memoryAGet(ds, si + 2);
    sub_3536c();
    al = memoryAGet(ds, 0x7d67);
    al &= 0xf0;
    if (al)
        goto loc_365a1;
    al = memoryAGet(ds, 0x7d67);
    al &= 0x04;
    if (!al)
        goto loc_36586;
    goto loc_36674;
loc_36586:
    memoryASet16(ds, si + 4, dx);
    memoryASet(ds, si + 42, ah);
    ax = memoryAGet16(ds, si + 44);
    ax += 0x0080;
    if (ah < 0x08)
        goto loc_3659d;
    ax = 0x0800;
loc_3659d:
    memoryASet16(ds, si + 44, ax);
    return;
loc_365a1:
    bl = memoryAGet(ds, si + 2);
    bl &= 0x1c;
    bl >>= 1;
    bl >>= 1;
    bl >>= 1;
    bh = 0;
    bx += 0x8143;
    al = memoryAGet(ds, bx);
    if (!(memoryAGet(ds, si + 38) & 0x80))
        goto loc_365c0;
    al += 0x03;
loc_365c0:
    al += memoryAGet(ds, si + 32);
    memoryASet(ds, si + 8, al);
    memoryASet16(ds, si + 44, 0x0080);
    ax = memoryAGet16(ds, si + 4);
    al &= 0xf8;
    al |= 0x03;
    memoryASet16(ds, si + 4, ax);
    al = memoryAGet(ds, si + 46);
    if (!al)
        goto loc_365e5;
    al--;
    memoryASet(ds, si + 46, al);
    return;
loc_365e5:
    al = memoryAGet(ds, si + 38);
    if (al)
        goto loc_365f7;
    return;
  // gap 7 bytes
loc_365f7:
    if ((char)al >= 0)
        goto loc_36607;
    flags.carry = (al + memoryAGet(ds, si + 2)) >= 0x100;
    al += memoryAGet(ds, si + 2);
    if (flags.carry)
        goto loc_36611;
    goto loc_3666c;
  // gap 1 bytes
loc_36607:
    al += memoryAGet(ds, si + 2);
    if (al >= 0xe8)
        goto loc_3666c;
loc_36611:
    bl = al;
    dx = memoryAGet16(ds, si + 4);
    sub_3536c();
    al = memoryAGet(ds, 0x7d67);
    al &= 0xf0;
    if (al)
        goto loc_3666c;
    al = memoryAGet(ds, 0x7d67);
    if (al & 0x04)
        goto loc_36674;
    memoryASet(ds, si + 2, bl);
    al = memoryAGet(ds, 0x7d8e);
    if (!al)
        goto loc_36659;
    al = memoryAGet(ds, si + 2);
    cl = al;
    al &= 0x1e;
    if (al == 0x10)
        goto loc_36649;
loc_36648:
    return;
loc_36649:
    al = memoryAGet(ds, 0x7e80);
    memoryASet(ds, si + 38, 0xfe);
    if (al < cl)
        goto loc_36648;
    memoryASet(ds, si + 38, 0x02);
    return;
loc_36659:
    al = memoryAGet(ds, si + 22);
    al >>= 1;
    cl = al;
    al = memoryAGet(ds, si + 40);
    al++;
    memoryASet(ds, si + 40, al);
    if (al < cl)
        goto loc_36648;
loc_3666c:
    memoryASet(ds, si + 40, 0x00);
    memoryASet(ds, si + 38, -memoryAGet(ds, si + 38));
    return;
loc_36674:
    memoryASet(ds, si, 0x47);
    memoryASet16(ds, si + 44, 0xfc00);
    ax = 0x7da9;
    memoryASet16(ds, 0x7d9a, ax);
    push(si);
    si = 0x4928;
    sub_34442();
    si = pop();
    if (!(memoryAGet(ds, si + 20) & 0x01))
        goto loc_3669a;
    bx = memoryAGet16(ds, si + 18);
    bx++;
    memoryASet(ds, bx, memoryAGet(ds, bx) | 0x80);
loc_3669a:
    memoryASet(ds, si + 38, 0x02);
    if (memoryAGet(ds, si + 2) >= 0x80)
        goto loc_366a8;
    return;
loc_366a8:
    memoryASet(ds, si + 38, 0xfe);
    return;
loc_366ad:
    memoryASet(ds, si, 0x00);
}
void sub_36742()
{
    bx = memoryAGet16(ds, si + 18);
    bx++;
    memoryASet(ds, bx, memoryAGet(ds, bx) | 0x80);
}
void sub_3680a()
{
    push(ds);
    push(bx);
    bx = 0xb800;
    ds = bx;
    bx = 0x004e;
    memoryASet16(ds, bx, memoryAGet16(ds, bx) + 1);
    bx = pop();
    ds = pop();
}
void sub_36819()
{
    memoryASet(ds, 0x7d85, 0x00);
    memoryASet(ds, 0x7d6a, 0x00);
    si = 0x7e4e;
loc_36826:
    al = memoryAGet(ds, si);
    if (al != 0xff)
        goto loc_36830;
    return;
loc_36830:
    if (al == 0x01)
        goto loc_3683a;
    memoryASet(ds, si, 0x00);
loc_3683a:
    si += 0x0030;
    goto loc_36826;
}
void sub_36853()
{
loc_36853:
    al = memoryAGet(ds, si + 38);
    ah = 0;
    bx = memoryAGet16(ds, si + 32);
    cx = bx;
    bx += ax;
    al = memoryAGet(ds, bx);
    if (al != 0xff)
        goto loc_3686c;
    bx = cx;
    al = memoryAGet(ds, bx);
loc_3686c:
    memoryASet(ds, si + 8, al);
    al = memoryAGet(ds, si + 38);
    if (al)
        goto loc_36879;
    goto loc_36957;
loc_36879:
    ah = 0;
    bx = cx;
    bx += ax;
    if (memoryAGet(ds, bx) != 0xff)
        goto loc_3688e;
    memoryASet(ds, si + 38, 0x01);
    goto loc_368a5;
  // gap 1 bytes
loc_3688e:
    al++;
    memoryASet(ds, si + 38, al);
    ah = 0;
    bx = cx;
    bx += ax;
    if (memoryAGet(ds, bx) != 0xff)
        goto loc_368a5;
    memoryASet(ds, si + 38, 0x01);
loc_368a5:
    bx = memoryAGet16(ds, si + 36);
    al = memoryAGet(ds, si + 40);
loc_368ab:
    if (al < memoryAGet(ds, bx))
        goto loc_36907;
    bx++;
    bx++;
    bx++;
    if (memoryAGet(ds, bx) != 0xff)
        goto loc_368fd;
loc_368bd:
    al = memoryAGet(ds, 0x7d75);
    if (al)
        goto loc_368d4;
    if (!(memoryAGet(ds, si + 20) & 0x01))
        goto loc_368d4;
loc_368d0:
    memoryASet(ds, si, 0x00);
    return;
loc_368d4:
    al = memoryAGet(ds, si);
    al &= 0x7f;
    if (!(memoryAGet(ds, si + 20) & 0x04))
        goto loc_368e3;
    al |= 0x80;
loc_368e3:
    memoryASet(ds, si, al);
    memoryASet(ds, si + 38, 0x00);
    al = memoryAGet(ds, si + 28);
    memoryASet(ds, si + 2, al);
    ax = memoryAGet16(ds, si + 30);
    if (ax >= 0x0140)
        goto loc_368d0;
    memoryASet16(ds, si + 4, ax);
    goto loc_36853;
loc_368fd:
    memoryASet16(ds, si + 36, bx);
    al = 0x00;
    memoryASet(ds, si + 40, al);
    goto loc_368ab;
loc_36907:
    al++;
    memoryASet(ds, si + 40, al);
    bx++;
    al = memoryAGet(ds, bx);
    if ((char)al >= 0)
        goto loc_3691e;
    flags.carry = (al + memoryAGet(ds, si + 2)) >= 0x100;
    al += memoryAGet(ds, si + 2);
    if (!flags.carry)
        goto loc_368bd;
    goto loc_36927;
  // gap 1 bytes
loc_3691e:
    flags.carry = (al + memoryAGet(ds, si + 2)) >= 0x100;
    al += memoryAGet(ds, si + 2);
    if (flags.carry)
        goto loc_368bd;
    if (al >= 0xe8)
        goto loc_368bd;
loc_36927:
    memoryASet(ds, si + 2, al);
    bx++;
    cl = memoryAGet(ds, bx);
    ch = 0;
    ax = memoryAGet16(ds, si + 4);
    if ((char)cl >= 0)
        goto loc_3693b;
    ch--;
loc_3693b:
    ax += cx;
    if (!ah)
        goto loc_36953;
    if (ah == 0x01)
        goto loc_3694c;
    goto loc_368bd;
loc_3694c:
    if (al < 0x40)
        goto loc_36953;
    goto loc_368bd;
loc_36953:
    memoryASet16(ds, si + 4, ax);
    return;
loc_36957:
    al = memoryAGet(ds, si + 20);
    if (!(al & 0x80))
        goto loc_3697a;
    bl = memoryAGet(ds, 0x7e80);
    bl += 0x0c;
    dx = memoryAGet16(ds, 0x7e82);
    dx += 0x000a;
    sub_3559d();
    if (flags.zero)
        goto loc_369e6;
    al = memoryAGet(ds, si + 20);
loc_3697a:
    if (!(al & 0x40))
        goto loc_3699e;
    al = memoryAGet(ds, 0x7d6a);
    if (!al)
        goto loc_3699b;
    bl = memoryAGet(ds, 0x7d7b);
    dx = memoryAGet16(ds, 0x7d7c);
    sub_3559d();
    if (flags.zero)
        goto loc_369e6;
loc_3699b:
    al = memoryAGet(ds, si + 20);
loc_3699e:
    if (!(al & 0x20))
        goto loc_369ca;
    al = memoryAGet(ds, 0x7eae);
    if (!al)
        goto loc_369c7;
    bl = memoryAGet(ds, 0x7d7e);
    dx = memoryAGet16(ds, 0x7d7f);
    sub_3559d();
    if (!flags.zero)
        goto loc_369c7;
    memoryASet(ds, 0x7eae, 0x00);
    goto loc_369e6;
  // gap 1 bytes
loc_369c7:
    al = memoryAGet(ds, si + 20);
loc_369ca:
    if (al & 0x10)
        goto loc_369d2;
loc_369d1:
    return;
loc_369d2:
    al = memoryAGet(ds, 0x7d85);
    if (!al)
        goto loc_369d1;
    bl = memoryAGet(ds, 0x7d82);
    dx = memoryAGet16(ds, 0x7d83);
    sub_3559d();
    if (!flags.zero)
        goto loc_369d1;
loc_369e6:
    if (memoryAGet(ds, 0x7d75) == 0x00)
        goto loc_369f1;
    return;
loc_369f1:
    al = memoryAGet(ds, si);
    al &= 0x7f;
    if (!(memoryAGet(ds, si + 20) & 0x08))
        goto loc_36a00;
    al |= 0x80;
loc_36a00:
    memoryASet(ds, si, al);
    memoryASet(ds, si + 38, 0x01);
    memoryASet(ds, si + 40, 0x00);
    ax = memoryAGet16(ds, si + 34);
    memoryASet16(ds, si + 36, ax);
}
void sub_36a8b()
{
    goto loc_36a8b;
loc_36674:
    memoryASet(ds, si, 0x47);
    memoryASet16(ds, si + 44, 0xfc00);
    ax = 0x7da9;
    memoryASet16(ds, 0x7d9a, ax);
    push(si);
    si = 0x4928;
    sub_34442();
    si = pop();
    if (!(memoryAGet(ds, si + 20) & 0x01))
        goto loc_3669a;
    bx = memoryAGet16(ds, si + 18);
    bx++;
    memoryASet(ds, bx, memoryAGet(ds, bx) | 0x80);
loc_3669a:
    memoryASet(ds, si + 38, 0x02);
    if (memoryAGet(ds, si + 2) >= 0x80)
        goto loc_366a8;
    return;
loc_366a8:
    memoryASet(ds, si + 38, 0xfe);
    return;
  // gap 990 bytes
loc_36a8b:
    al = memoryAGet(ds, si + 46);
    if (!al)
        goto loc_36a98;
    memoryASet(ds, si + 46, memoryAGet(ds, si + 46) - 1);
loc_36a98:
    if (memoryAGet(ds, si + 38) == 0xff)
        goto loc_36aa1;
    goto loc_36b7a;
loc_36aa1:
    if (memoryAGet(ds, si + 46) == 0x00)
        goto loc_36aab;
    return;
loc_36aab:
    al = memoryAGet(ds, si + 32);
    al += 0x08;
    ah = memoryAGet(ds, si + 4);
    ah ^= memoryAGet(ds, si + 2);
    ah &= 0x04;
    if (!ah)
        goto loc_36ac0;
    al++;
loc_36ac0:
    memoryASet(ds, si + 8, al);
    ax = memoryAGet16(ds, 0x7e82);
    al &= 0xfe;
    bx = memoryAGet16(ds, si + 4);
    bl &= 0xfe;
    flags.carry = ax < bx;
    if (ax != bx)
        goto loc_36b18;
loc_36ad5:
    al = memoryAGet(ds, si + 2);
    ah = 0x02;
    if (al < memoryAGet(ds, 0x7e80))
        goto loc_36ae5;
    ah = 0xfe;
loc_36ae5:
    memoryASet(ds, si + 40, ah);
    al += ah;
    bl = al;
    dx = memoryAGet16(ds, si + 4);
    sub_3536c();
    al = memoryAGet(ds, 0x7d67);
    al &= 0x70;
    if (!al)
        goto loc_36afd;
    return;
loc_36afd:
    al = memoryAGet(ds, 0x7d67);
    al &= 0x04;
    if (!al)
        goto loc_36b07;
    goto loc_36674;
loc_36b07:
    memoryASet(ds, si + 2, bl);
    al = memoryAGet(ds, 0x7d67);
    al &= 0x82;
    if (!al)
        goto loc_36b15;
    return;
loc_36b15:
    goto loc_36b76;
  // gap 1 bytes
loc_36b18:
    ax = 0xfffe;
    if (flags.carry)
        goto loc_36b23;
    ax = 0x0002;
loc_36b23:
    bx += ax;
    push(ax);
    if (bh == 0x00)
        goto loc_36b40;
    if (bh == 0x01)
        goto loc_36b3b;
loc_36b36:
    memoryASet(ds, si, 0x00);
    ax = pop();
    return;
loc_36b3b:
    if (bl >= 0x40)
        goto loc_36b36;
loc_36b40:
    dx = bx;
    bl = memoryAGet(ds, si + 2);
    sub_3536c();
    al = memoryAGet(ds, 0x7d67);
    flags.zero = !(al & 0x70);
    al &= 0x70;
    ax = pop();
    if (flags.zero)
        goto loc_36b68;
    if (ah & 0x80)
        goto loc_36b62;
    memoryASet(ds, si + 38, 0x00);
    goto loc_36b7a;
  // gap 1 bytes
loc_36b62:
    dx = memoryAGet16(ds, si + 4);
    goto loc_36ad5;
loc_36b68:
    al = memoryAGet(ds, 0x7d67);
    memoryASet16(ds, si + 4, dx);
    al &= 0x82;
    if (!al)
        goto loc_36b76;
    return;
loc_36b76:
    memoryASet(ds, si + 38, 0x00);
loc_36b7a:
    dl = memoryAGet(ds, si + 42);
    dh = memoryAGet(ds, si + 4);
    al = memoryAGet(ds, si + 5);
    bx = memoryAGet16(ds, si + 44);
    ah = 0;
    if (!(bh & 0x80))
        goto loc_36b92;
    ah--;
loc_36b92:
    flags.carry = (dx + bx) >= 0x10000;
    dx += bx;
    al += ah + flags.carry;
    ah = dl;
    dl = dh;
    dh = al;
    bl = memoryAGet(ds, si + 2);
    sub_3536c();
    al = memoryAGet(ds, 0x7d67);
    al &= 0x70;
    if (al)
        goto loc_36c0b;
    al = memoryAGet(ds, 0x7d67);
    al &= 0x04;
    if (!al)
        goto loc_36bb6;
    goto loc_36674;
loc_36bb6:
    if (dh == 0x00)
        goto loc_36bca;
    if (dl < 0x40)
        goto loc_36bca;
    memoryASet(ds, si, 0x00);
    return;
loc_36bca:
    al = memoryAGet(ds, 0x7d67);
    al &= 0x80;
    if (!al)
        goto loc_36bf0;
    al = memoryAGet(ds, si + 2);
    al &= 0x07;
    if (al != 0x04)
        goto loc_36c0b;
    cx = memoryAGet16(ds, 0x7e82);
    if (dx >= cx)
        goto loc_36c0b;
    memoryASet(ds, si + 38, 0xff);
    return;
loc_36bf0:
    memoryASet16(ds, si + 4, dx);
    memoryASet(ds, si + 42, bl);
    ax = memoryAGet16(ds, si + 44);
    ax += 0x0080;
    if (ah < 0x08)
        goto loc_36c07;
    ax = 0x0800;
loc_36c07:
    memoryASet16(ds, si + 44, ax);
    return;
loc_36c0b:
    al = memoryAGet(ds, si + 4);
    al &= 0xf8;
    al |= 0x03;
    memoryASet(ds, si + 4, al);
    memoryASet16(ds, si + 44, 0x0100);
    if (memoryAGet(ds, si + 46) == 0x00)
        goto loc_36c24;
    return;
loc_36c24:
    al = memoryAGet(ds, 0x7d67);
    al &= 0x02;
    if (!al)
        goto loc_36c4d;
    al = memoryAGet(ds, si + 2);
    al &= 0x0e;
    if (al != 0x04)
        goto loc_36c4d;
    dx = memoryAGet16(ds, 0x7e82);
    ax = memoryAGet16(ds, si + 4);
    if (dx >= ax)
        goto loc_36c4d;
    memoryASet(ds, si + 38, 0xff);
    return;
loc_36c4d:
    bx = 0x8143;
    if (!(memoryAGet(ds, si + 40) & 0x80))
        goto loc_36c5c;
    bx = 0x8147;
loc_36c5c:
    al = memoryAGet(ds, si + 2);
    al &= 0x0e;
    ah = 0;
    al >>= 1;
    al >>= 1;
    al >>= 1;
    bx += ax;
    al = memoryAGet(ds, bx);
    al += memoryAGet(ds, si + 32);
    memoryASet(ds, si + 8, al);
    al = memoryAGet(ds, si + 40);
    flags.sign = (char)al < 0;
    if (al)
        goto loc_36c85;
    memoryASet(ds, si + 40, 0x02);
    al = 0x02;
    flags.sign = (char)al < 0;
loc_36c85:
    if (!flags.sign)
        goto loc_36c95;
    flags.carry = (al + memoryAGet(ds, si + 2)) >= 0x100;
    al += memoryAGet(ds, si + 2);
    if (flags.carry)
        goto loc_36c9f;
    goto loc_36cd2;
  // gap 1 bytes
loc_36c95:
    al += memoryAGet(ds, si + 2);
    if (al >= 0xe8)
        goto loc_36cd2;
loc_36c9f:
    bl = al;
    dx = memoryAGet16(ds, si + 4);
    sub_3536c();
    al = memoryAGet(ds, 0x7d67);
    al &= 0xf0;
    if (al)
        goto loc_36cd2;
    memoryASet(ds, si + 2, bl);
    bl &= 0x1e;
    if (bl == 0x08)
        goto loc_36cc0;
    return;
loc_36cc0:
    sub_343fa();
    al &= 0x01;
    ah = 0x02;
    if (!al)
        goto loc_36cce;
    ah = 0xfe;
loc_36cce:
    memoryASet(ds, si + 40, ah);
    return;
loc_36cd2:
    al = memoryAGet(ds, si + 40);
    al = -al;
    if (al)
        goto loc_36cde;
    al = 0x02;
loc_36cde:
    memoryASet(ds, si + 40, al);
}
void sub_36ce2()
{
    si = memoryAGet16(ds, 0x7d9a);
    ch = memoryAGet(ds, si);
    if (ch)
        goto loc_36cf2;
    goto loc_36cfd;
  // gap 1 bytes
loc_36cf2:
    memoryASet16(ds, 0x7d9a, memoryAGet16(ds, 0x7d9a) + 0x0001);
    cl = 0x00;
    sub_36d04();
    return;
loc_36cfd:
    al = in8(0x61);
    al &= 0xfd;
    out8(0x61, al);
}
void sub_36cfd()
{
    al = in8(0x61);
    al &= 0xfd;
    out8(0x61, al);
}
void sub_36d04()
{
    dx = 0x0043;
    al = 0xb6;
    out8(dx, al);
    dx--;
    al = cl;
    out8(dx, al);
    al = ch;
    out8(dx, al);
    al = in8(0x61);
    al |= 0x03;
    out8(0x61, al);
}
void sub_36d18()
{
    bx = 0x0003;
loc_36d1b:
    al = in8(0x61);
    al &= 0xfc;
    out8(0x61, al);
    cx = 0x0320;
loc_36d24:
    if (--cx)
        goto loc_36d24;
    al |= 0x02;
    out8(0x61, al);
    cx = 0x02bc;
loc_36d2d:
    if (--cx)
        goto loc_36d2d;
    bx--;
    if (bx)
        goto loc_36d1b;
}
void fixReloc(uint16_t seg)
{
    memoryASet16(0x2000 + seg, 0x41b7, memoryAGet16(0x2000 + seg, 0x41b7) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x41c9, memoryAGet16(0x2000 + seg, 0x41c9) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x41f8, memoryAGet16(0x2000 + seg, 0x41f8) + seg); // 0fc1 -> 1fc1
    memoryASet16(0x2000 + seg, 0x4247, memoryAGet16(0x2000 + seg, 0x4247) + seg); // 0fc1 -> 1fc1
    memoryASet16(0x2000 + seg, 0x4260, memoryAGet16(0x2000 + seg, 0x4260) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x4377, memoryAGet16(0x2000 + seg, 0x4377) + seg); // 0fc1 -> 1fc1
    memoryASet16(0x2000 + seg, 0x4431, memoryAGet16(0x2000 + seg, 0x4431) + seg); // 0fc1 -> 1fc1
    memoryASet16(0x2000 + seg, 0x4444, memoryAGet16(0x2000 + seg, 0x4444) + seg); // 0fc1 -> 1fc1
    memoryASet16(0x2000 + seg, 0x44a5, memoryAGet16(0x2000 + seg, 0x44a5) + seg); // 0fc1 -> 1fc1
    memoryASet16(0x2000 + seg, 0x44cc, memoryAGet16(0x2000 + seg, 0x44cc) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x44fc, memoryAGet16(0x2000 + seg, 0x44fc) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x4642, memoryAGet16(0x2000 + seg, 0x4642) + seg); // 0fc1 -> 1fc1
    memoryASet16(0x2000 + seg, 0x4675, memoryAGet16(0x2000 + seg, 0x4675) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x46ac, memoryAGet16(0x2000 + seg, 0x46ac) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x46e0, memoryAGet16(0x2000 + seg, 0x46e0) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x4728, memoryAGet16(0x2000 + seg, 0x4728) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x472f, memoryAGet16(0x2000 + seg, 0x472f) + seg); // 1455 -> 2455
    memoryASet16(0x2000 + seg, 0x4765, memoryAGet16(0x2000 + seg, 0x4765) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x476d, memoryAGet16(0x2000 + seg, 0x476d) + seg); // 0fc1 -> 1fc1
    memoryASet16(0x2000 + seg, 0x4772, memoryAGet16(0x2000 + seg, 0x4772) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x4789, memoryAGet16(0x2000 + seg, 0x4789) + seg); // 0fc1 -> 1fc1
    memoryASet16(0x2000 + seg, 0x478e, memoryAGet16(0x2000 + seg, 0x478e) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x47a5, memoryAGet16(0x2000 + seg, 0x47a5) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x47be, memoryAGet16(0x2000 + seg, 0x47be) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x47d7, memoryAGet16(0x2000 + seg, 0x47d7) + seg); // 0fc1 -> 1fc1
    memoryASet16(0x2000 + seg, 0x4804, memoryAGet16(0x2000 + seg, 0x4804) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x482d, memoryAGet16(0x2000 + seg, 0x482d) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x489c, memoryAGet16(0x2000 + seg, 0x489c) + seg); // 1455 -> 2455
    memoryASet16(0x2000 + seg, 0x48ad, memoryAGet16(0x2000 + seg, 0x48ad) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x48b6, memoryAGet16(0x2000 + seg, 0x48b6) + seg); // 1455 -> 2455
    memoryASet16(0x2000 + seg, 0x48c0, memoryAGet16(0x2000 + seg, 0x48c0) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x48d2, memoryAGet16(0x2000 + seg, 0x48d2) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x4937, memoryAGet16(0x2000 + seg, 0x4937) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x4991, memoryAGet16(0x2000 + seg, 0x4991) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x4dc9, memoryAGet16(0x2000 + seg, 0x4dc9) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x4e4d, memoryAGet16(0x2000 + seg, 0x4e4d) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x4ece, memoryAGet16(0x2000 + seg, 0x4ece) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x505e, memoryAGet16(0x2000 + seg, 0x505e) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x508c, memoryAGet16(0x2000 + seg, 0x508c) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x50db, memoryAGet16(0x2000 + seg, 0x50db) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x513c, memoryAGet16(0x2000 + seg, 0x513c) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x5159, memoryAGet16(0x2000 + seg, 0x5159) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x5172, memoryAGet16(0x2000 + seg, 0x5172) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x51aa, memoryAGet16(0x2000 + seg, 0x51aa) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x51c7, memoryAGet16(0x2000 + seg, 0x51c7) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x51e0, memoryAGet16(0x2000 + seg, 0x51e0) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x520b, memoryAGet16(0x2000 + seg, 0x520b) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x5263, memoryAGet16(0x2000 + seg, 0x5263) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x52ab, memoryAGet16(0x2000 + seg, 0x52ab) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x5449, memoryAGet16(0x2000 + seg, 0x5449) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x5c81, memoryAGet16(0x2000 + seg, 0x5c81) + seg); // 0fc1 -> 1fc1
    memoryASet16(0x2000 + seg, 0x5ce5, memoryAGet16(0x2000 + seg, 0x5ce5) + seg); // 0fc1 -> 1fc1
    memoryASet16(0x2000 + seg, 0x5d07, memoryAGet16(0x2000 + seg, 0x5d07) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x5d1f, memoryAGet16(0x2000 + seg, 0x5d1f) + seg); // 0fc1 -> 1fc1
    memoryASet16(0x2000 + seg, 0x5d44, memoryAGet16(0x2000 + seg, 0x5d44) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x5ee6, memoryAGet16(0x2000 + seg, 0x5ee6) + seg); // 0fc1 -> 1fc1
    memoryASet16(0x2000 + seg, 0x5fcb, memoryAGet16(0x2000 + seg, 0x5fcb) + seg); // 0fc1 -> 1fc1
    memoryASet16(0x2000 + seg, 0x6005, memoryAGet16(0x2000 + seg, 0x6005) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x6166, memoryAGet16(0x2000 + seg, 0x6166) + seg); // 0fc1 -> 1fc1
    memoryASet16(0x2000 + seg, 0x61a1, memoryAGet16(0x2000 + seg, 0x61a1) + seg); // 0fc1 -> 1fc1
    memoryASet16(0x2000 + seg, 0x61e9, memoryAGet16(0x2000 + seg, 0x61e9) + seg); // 0fc1 -> 1fc1
    memoryASet16(0x2000 + seg, 0x6225, memoryAGet16(0x2000 + seg, 0x6225) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x6234, memoryAGet16(0x2000 + seg, 0x6234) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x623a, memoryAGet16(0x2000 + seg, 0x623a) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x63f2, memoryAGet16(0x2000 + seg, 0x63f2) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x6414, memoryAGet16(0x2000 + seg, 0x6414) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x64ab, memoryAGet16(0x2000 + seg, 0x64ab) + seg); // 0fc1 -> 1fc1
    memoryASet16(0x2000 + seg, 0x6d41, memoryAGet16(0x2000 + seg, 0x6d41) + seg); // 0040 -> 1040
    memoryASet16(0x2000 + seg, 0x6d78, memoryAGet16(0x2000 + seg, 0x6d78) + seg); // 0040 -> 1040
}

int GetProcAt(int seg, int ofs)
{
    int map[] = {
        0x341b0, 0x341b, 0x0, 0x341b, 0x18a, 0x341b0, 0x341b, 0x18b, 0x341b, 0x1a6,
        0x34356, 0x341b, 0x1a6, 0x341b, 0x200, 0x343b0, 0x341b, 0x200, 0x341b, 0x24a,
        0x343fa, 0x341b, 0x24a, 0x341b, 0x270, 0x34420, 0x341b, 0x270, 0x341b, 0x27b,
        0x3442b, 0x341b, 0x27b, 0x341b, 0x292, 0x34442, 0x341b, 0x27b, 0x341b, 0x2c0,
        0x34470, 0x341b, 0x2c0, 0x341b, 0x2ce, 0x34470, 0x341b, 0x2ea, 0x341b, 0x309,
        0x3447f, 0x341b, 0x2cf, 0x341b, 0x2dd, 0x3447f, 0x341b, 0x2ea, 0x341b, 0x309,
        0x344b9, 0x341b, 0x2de, 0x341b, 0x314, 0x344c4, 0x341b, 0x314, 0x341b, 0x337,
        0x344e7, 0x341b, 0x337, 0x341b, 0x348, 0x345e3, 0x341b, 0x433, 0x341b, 0x445,
        0x345f5, 0x341b, 0x445, 0x341b, 0x44d, 0x345fd, 0x341b, 0x44d, 0x341b, 0x455,
        0x34720, 0x341b, 0x570, 0x341b, 0x652, 0x34802, 0x341b, 0x652, 0x341b, 0x661,
        0x34811, 0x341b, 0x661, 0x341b, 0x6e8, 0x348a8, 0x341b, 0x6f8, 0x341b, 0x736,
        0x348e6, 0x341b, 0x736, 0x341b, 0x786, 0x34936, 0x341b, 0x786, 0x341b, 0x796,
        0x34947, 0x341b, 0x797, 0x341b, 0x7bb, 0x3496b, 0x341b, 0x7bb, 0x341b, 0x7c9,
        0x34986, 0x341b, 0x7d6, 0x341b, 0x87e, 0x34a2e, 0x341b, 0x87e, 0x341b, 0xb58,
        0x34d08, 0x341b, 0xb58, 0x341b, 0xc18, 0x34dc8, 0x341b, 0xc18, 0x341b, 0xc9c,
        0x34e4c, 0x341b, 0xc9c, 0x341b, 0xd1d, 0x34ecd, 0x341b, 0xd1d, 0x341b, 0xd2f,
        0x34edf, 0x341b, 0xd2f, 0x341b, 0xd50, 0x34f00, 0x341b, 0xd50, 0x341b, 0xd7c,
        0x34f00, 0x341b, 0xe37, 0x341b, 0xead, 0x34f2c, 0x341b, 0xd7c, 0x341b, 0xead,
        0x34fe7, 0x341b, 0xe37, 0x341b, 0xead, 0x3505d, 0x341b, 0xead, 0x341b, 0xedb,
        0x3508b, 0x341b, 0xedb, 0x341b, 0xf2a, 0x350da, 0x341b, 0xf2a, 0x341b, 0xf5e,
        0x3510e, 0x341b, 0xf5e, 0x341b, 0xf81, 0x35131, 0x341b, 0xf81, 0x341b, 0xfef,
        0x3519f, 0x341b, 0xfef, 0x341b, 0x105a, 0x3520a, 0x341b, 0x105a, 0x341b, 0x108f,
        0x3523f, 0x341b, 0x108f, 0x341b, 0x10b2, 0x35262, 0x341b, 0x10b2, 0x341b, 0x10e2,
        0x35262, 0x341b, 0x10e3, 0x341b, 0x10f0, 0x35262, 0x341b, 0x10f1, 0x341b, 0x10fa,
        0x352aa, 0x341b, 0x10fa, 0x341b, 0x1115, 0x352c5, 0x341b, 0x1115, 0x341b, 0x113a,
        0x352ea, 0x341b, 0x113a, 0x341b, 0x119e, 0x352ea, 0x341b, 0x119f, 0x341b, 0x11bb,
        0x352ea, 0x341b, 0x11fc, 0x341b, 0x1237, 0x352ea, 0x341b, 0x1238, 0x341b, 0x1295,
        0x3536c, 0x341b, 0x11bc, 0x341b, 0x1237, 0x3536c, 0x341b, 0x1238, 0x341b, 0x1295,
        0x35445, 0x341b, 0x1295, 0x341b, 0x12ae, 0x3545e, 0x341b, 0x12ae, 0x341b, 0x1317,
        0x3546c, 0x341b, 0x12bc, 0x341b, 0x1317, 0x354c7, 0x341b, 0x1317, 0x341b, 0x134b,
        0x354fb, 0x341b, 0x134b, 0x341b, 0x13ac, 0x3555c, 0x341b, 0x13ac, 0x341b, 0x13ed,
        0x3559d, 0x341b, 0x13ed, 0x341b, 0x1448, 0x356ec, 0x341b, 0x153c, 0x341b, 0x15aa,
        0x356ec, 0x341b, 0x15ab, 0x341b, 0x1672, 0x356ec, 0x341b, 0x1673, 0x341b, 0x16ef,
        0x356ec, 0x341b, 0x16f0, 0x341b, 0x1899, 0x356ec, 0x341b, 0x189a, 0x341b, 0x190f,
        0x356ec, 0x341b, 0x1910, 0x341b, 0x1a01, 0x35b7f, 0x341b, 0x19cf, 0x341b, 0x1a01,
        0x35c76, 0x341b, 0x1ac6, 0x341b, 0x1b33, 0x35ce3, 0x341b, 0x1b33, 0x341b, 0x1bae,
        0x35d5e, 0x341b, 0x1bae, 0x341b, 0x1c15, 0x35dc5, 0x341b, 0x1c15, 0x341b, 0x1c82,
        0x35e32, 0x341b, 0x1c82, 0x341b, 0x1cb3, 0x35e63, 0x341b, 0x1cb3, 0x341b, 0x1ce7,
        0x35e97, 0x341b, 0x1ce7, 0x341b, 0x1d5e, 0x35ee0, 0x341b, 0x1d30, 0x341b, 0x1d5e,
        0x35f0e, 0x341b, 0x1d5e, 0x341b, 0x1d9e, 0x35f4e, 0x341b, 0x1d9e, 0x341b, 0x1dac,
        0x35f5c, 0x341b, 0x1dac, 0x341b, 0x1de7, 0x35f97, 0x341b, 0x1de7, 0x341b, 0x1e0e,
        0x35fbe, 0x341b, 0x1e0e, 0x341b, 0x1e76, 0x36026, 0x341b, 0x1e76, 0x341b, 0x1f2e,
        0x36026, 0x341b, 0x1f2f, 0x341b, 0x1f50, 0x36026, 0x341b, 0x1f51, 0x341b, 0x1f7b,
        0x3612b, 0x341b, 0x1f7b, 0x341b, 0x1f89, 0x36139, 0x341b, 0x1f89, 0x341b, 0x1fa0,
        0x36150, 0x341b, 0x1fa0, 0x341b, 0x1fb1, 0x36161, 0x341b, 0x1fb1, 0x341b, 0x1fef,
        0x3619f, 0x341b, 0x1fef, 0x341b, 0x2038, 0x361e8, 0x341b, 0x2038, 0x341b, 0x206d,
        0x361e8, 0x341b, 0x206e, 0x341b, 0x2089, 0x36239, 0x341b, 0x2089, 0x341b, 0x20ef,
        0x36239, 0x341b, 0x20f0, 0x341b, 0x21e5, 0x36395, 0x341b, 0x21e5, 0x341b, 0x2205,
        0x363b5, 0x341b, 0x2205, 0x341b, 0x2241, 0x363f1, 0x341b, 0x2241, 0x341b, 0x2263,
        0x36413, 0x341b, 0x1448, 0x341b, 0x153c, 0x36413, 0x341b, 0x19cf, 0x341b, 0x1ac0,
        0x36413, 0x341b, 0x2263, 0x341b, 0x2280, 0x36413, 0x341b, 0x2281, 0x341b, 0x238b,
        0x36413, 0x341b, 0x24c4, 0x341b, 0x24fd, 0x36413, 0x341b, 0x2501, 0x341b, 0x2591,
        0x36413, 0x341b, 0x2592, 0x341b, 0x264b, 0x36413, 0x341b, 0x268f, 0x341b, 0x26a3,
        0x36413, 0x341b, 0x2861, 0x341b, 0x2883, 0x36413, 0x341b, 0x2884, 0x341b, 0x28db,
        0x3653b, 0x341b, 0x238b, 0x341b, 0x2440, 0x3653b, 0x341b, 0x2447, 0x341b, 0x2456,
        0x3653b, 0x341b, 0x2457, 0x341b, 0x2501, 0x36742, 0x341b, 0x2592, 0x341b, 0x259a,
        0x3680a, 0x341b, 0x265a, 0x341b, 0x2669, 0x36819, 0x341b, 0x2669, 0x341b, 0x268f,
        0x36853, 0x341b, 0x26a3, 0x341b, 0x26dd, 0x36853, 0x341b, 0x26de, 0x341b, 0x276d,
        0x36853, 0x341b, 0x276e, 0x341b, 0x2816, 0x36853, 0x341b, 0x2817, 0x341b, 0x2861,
        0x36a8b, 0x341b, 0x24c4, 0x341b, 0x24fd, 0x36a8b, 0x341b, 0x28db, 0x341b, 0x2967,
        0x36a8b, 0x341b, 0x2968, 0x341b, 0x29b1, 0x36a8b, 0x341b, 0x29b2, 0x341b, 0x2ae4,
        0x36a8b, 0x341b, 0x2ae5, 0x341b, 0x2b32, 0x36ce2, 0x341b, 0x2b32, 0x341b, 0x2b41,
        0x36ce2, 0x341b, 0x2b42, 0x341b, 0x2b54, 0x36cfd, 0x341b, 0x2b4d, 0x341b, 0x2b54,
        0x36d04, 0x341b, 0x2b54, 0x341b, 0x2b68, 0x36d18, 0x341b, 0x2b68, 0x341b, 0x2b83,
    };
    for (int i=0; i<sizeof(map)/sizeof(map[0]); i+=5)
        if (seg * 16 + ofs >= map[i+1]*16 + map[i+2] && seg * 16 + ofs <= map[i+3]*16 + map[i+4])
            return map[i];
    return 0;
}
#endif
