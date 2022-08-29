void entry();
void sub_01a6();
void sub_0200();
void sub_024a();
void sub_0270();
void sub_027b();
void sub_0292();
void sub_02c0();
void sub_02cf();
void sub_0309();
void sub_0314();
void sub_0337();
void sub_0348();
void sub_0433();
void sub_0445();
void sub_044d();
void sub_0455();
void sub_045d();
void sub_0478();
void sub_04a1();
void sub_04ba();
void sub_04e7();
void sub_04fb();
void sub_0570();
void sub_0652();
void sub_0661();
void sub_06e8();
void sub_06e9();
void sub_06f8();
void sub_0736();
void sub_0786();
void sub_0797();
void sub_07bb();
void sub_07c9();
void sub_07d6();
void sub_087e();
void sub_0b58();
void sub_0c18();
void sub_0c9c();
void sub_0d1d();
void sub_0d2f();
void sub_0d50();
void sub_0d7c();
void sub_0e37();
void sub_0ead();
void sub_0edb();
void sub_0f2a();
void sub_0f5e();
void sub_0f81();
void sub_0fef();
void sub_105a();
void sub_108f();
void sub_10b2();
void sub_10fa();
void sub_1115();
void sub_113a();
void sub_11bc(int pc = 0);
void sub_1295();
void sub_12ae();
void sub_12bc();
void sub_1317();
void sub_134b();
void sub_13ac();
void sub_13ed();
void sub_1448();
void sub_153c();
void sub_19cf();
void sub_1a01();
void sub_1a48();
void sub_1ac6();
void sub_1b33();
void sub_1bae();
void sub_1c15();
void sub_1c82();
void sub_1cb3();
void sub_1ce7();
void sub_1d30();
void sub_1d5e();
void sub_1d9e();
void sub_1dac();
void sub_1de7();
void sub_1e0e();
void sub_1e76();
void sub_1f7b();
void sub_1f89();
void sub_1fa0();
void sub_1fb1();
void sub_1fef();
void sub_2038();
void sub_2089();
void sub_21e5();
void sub_2205();
void sub_2241();
void sub_2263();
void sub_228c();
void sub_22cb();
void sub_2313(int pc = 0);
void sub_238b();
void sub_2440(int pc = 0);
void sub_2575();
void sub_2592();
void sub_259a();
void sub_259b();
void sub_25a3();
void sub_264b();
void sub_265a();
void sub_2669(int pc = 0);
void sub_26a3();
void sub_2861();
void sub_28db();
void sub_2b32();
void sub_2b4d();
void sub_2b54();
void sub_2b68();
void sub_2b83();
void sub_2b90();
void entry()
{
    sub_0570();                                 //call sub_0570
    sub_0314();                                 //call sub_0314
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
loc_000b:                                       //loc_000b:
    sub_0433();                                 //call sub_0433
    if (_flags.zero)                                //jz loc_000b
        goto loc_000b;
    sub_1b33();                                 //call sub_1b33 -- hall of fame
loc_0013:                                       //loc_0013:
    sub_0433();                                 //call sub_0433
    if (_flags.zero)                                //jz loc_0013
        goto loc_0013;
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _bx = 0x88f0;                               //mov bx, 0x88f0
    _cx = 0x020b;                               //mov cx, 0x20b
loc_0025:                                       //loc_0025:
    memory(_ds, _bx) &= 0x7f;                   //and byte ptr [bx], 0x7f
    _bx += 0x0005;                              //add bx, 0x5
    if (--_cx)                                  //loop loc_0025
        goto loc_0025;
    memory(_ds, 32144) = 0x00;                  //mov byte ptr [0x7d90], 0x0
    memory(_ds, 32145) = 0x00;                  //mov byte ptr [0x7d91], 0x0
    memory(_ds, 32326) = 0x06;                  //mov byte ptr [0x7e46], 0x6
    memory(_ds, 32325) = 0x06;                  //mov byte ptr [0x7e45], 0x6
    memory(_ds, 32327) = 0x06;                  //mov byte ptr [0x7e47], 0x6
    _push(_ds);                                 //push ds
    _ax = 0x1fc1;                               //mov ax, 0x1fc1
    _ds = _ax;                                  //mov ds, ax
    memory16(_ds, 18702) = 0x3030;              //mov word ptr [0x490e], 0x3030
    memory16(_ds, 18704) = 0x3030;              //mov word ptr [0x4910], 0x3030
    memory16(_ds, 18706) = 0x3030;              //mov word ptr [0x4912], 0x3030
    _ds = _pop();                               //pop ds
    sub_1ac6();                                 //call sub_1ac6
    sub_0797();                                 //call sub_0797
    _al = memory(_ds, 0x80ef);                  //mov al, [0x80ef]
    memory(_ds, 0x7e80) = _al;                  //mov [0x7e80], al
    _ax = memory16(_ds, 0x80f1);                //mov ax, [0x80f1]
    memory16(_ds, 0x7e82) = _ax;                //mov [0x7e82], ax
    memory(_ds, 32396) = 0x18;                  //mov byte ptr [0x7e8c], 0x18
    memory(_ds, 32398) = 0x15;                  //mov byte ptr [0x7e8e], 0x15
    _di = memory16(_ds, 33011);                 //mov di, word ptr [0x80f3]
    _bx = memory16(_ds, 33013);                 //mov bx, word ptr [0x80f5]
    sub_0e37();                                 //call sub_0e37
    _al = memory(_ds, 0x7e46);                  //mov al, [0x7e46]
    _al &= _al;                                 //and al, al
    if (_al != 0)                               //jnz loc_00c7
        goto loc_00c7;
loc_0090:                                       //loc_0090:
    sub_07d6();                                 //call sub_07d6
loc_0093:                                       //loc_0093:
    sub_2b4d();                                 //call sub_2b4d
    _ax = 0x1fc1;                               //mov ax, 0x1fc1
    _ds = _ax;                                  //mov ds, ax
    _ax = 0xb800;                               //mov ax, 0xb800
    _es = _ax;                                  //mov es, ax
    _bx = 0x4864;                               //mov bx, 0x4864
    memory16(_ds, 18634) = 0xaaaa;              //mov word ptr [0x48ca], 0xaaaa
    _di = 0x0c8f;                               //mov di, 0xc8f
    sub_1f7b();                                 //call sub_1f7b
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
loc_00b4:                                       //loc_00b4:
    sub_0433();                                 //call sub_0433
    if (_FIXME_)                                //jnz loc_00b4
        goto loc_00b4;
loc_00b9:                                       //loc_00b9:
    sub_0433();                                 //call sub_0433
    if (_FIXME_)                                //jz loc_00b9
        goto loc_00b9;
    sub_265a();                                 //call sub_265a
    sub_2038();                                 //call sub_2038
    goto loc_000b;                              //jmp loc_000b
loc_00c7:                                       //loc_00c7:
    memory(_ds, 32146) = 0x00;                  //mov byte ptr [0x7d92], 0x0
    memory(_ds, 32117) = 0x00;                  //mov byte ptr [0x7d75], 0x0
    memory(_ds, 32382) = 0x01;                  //mov byte ptr [0x7e7e], 0x1
    memory(_ds, 32325) = 0x06;                  //mov byte ptr [0x7e45], 0x6
    memory(_ds, 32327) = 0x06;                  //mov byte ptr [0x7e47], 0x6
    sub_0d50();                                 //call sub_0d50
    sub_0309();                                 //call sub_0309
loc_00e6:                                       //loc_00e6:
    sub_044d();                                 //call sub_044d
    if (_flags.zero)                                //jz loc_0090
        goto loc_0090;
    if (memory(_ds, 32323) != 0x01)             //jnz loc_00f5
        goto loc_00f5;
    goto loc_0198;                              //jmp loc_0198
loc_00f5:                                       //loc_00f5:
    _ah = 0x01;                                 //mov ah, 0x1
    _interrupt(22);                             //int 0x16
    if (!_flags.zero)                           //jnz loc_00fe
        goto loc_00fe;
loc_00fe:                                       //loc_00fe:
    _ah = 0x02;                                 //mov ah, 0x2
    _interrupt(22);                             //int 0x16
    if (!_flags.zero)                           //jnz loc_0107
        goto loc_0107;
loc_0107:                                       //loc_0107:
    sub_2241();                                 //call sub_2241
    sub_0270();                                 //call sub_0270
    sub_01a6();                                 //call sub_01a6
    sub_0445();                                 //call sub_0445
    if (!_flags.zero)                                //jnz loc_012a
        goto loc_012a;
    sub_2b4d();                                 //call sub_2b4d -- keyb something
loc_011b:                                       //loc_011b:
    sub_0445();                                 //call sub_0445
    if (_flags.zero)                                //jz loc_011b
        goto loc_011b;
loc_0120:                                       //loc_0120:
    sub_0445();                                 //call sub_0445
    if (!_flags.zero)                                //jnz loc_0120
        goto loc_0120;
loc_0125:                                       //loc_0125:
    sub_0445();                                 //call sub_0445
    if (_flags.zero)                                //jz loc_0125
        goto loc_0125;
loc_012a:                                       //loc_012a:
    _al = memory(_ds, 0x7d92);                  //mov al, [0x7d92]
    _al &= _al;                                 //and al, al
    if (_al == 0)                               //jz loc_0143
        goto loc_0143;
    _al = memory(_ds, 0x7e46);                  //mov al, [0x7e46]
    _al -= 1;                                   //dec al
    memory(_ds, 0x7e46) = _al;                  //mov [0x7e46], al
    if (_al != 0)                               //jnz loc_0141
        goto loc_0141;
    goto loc_0090;                              //jmp loc_0090
loc_0141:                                       //loc_0141:
    goto loc_00c7;                              //jmp loc_00c7
loc_0143:                                       //loc_0143:
    _al = memory(_ds, 0x7d76);                  //mov al, [0x7d76]
    _al &= _al;                                 //and al, al
    if (_al == 0)                               //jz loc_015c
        goto loc_015c;
    sub_0d7c();                                 //call sub_0d7c
    _al = memory(_ds, 0x7d91);                  //mov al, [0x7d91]
    _al &= _al;                                 //and al, al
    if (_al == 0)                               //jz loc_015a
        goto loc_015a;
    goto loc_0093;                              //jmp loc_0093
loc_015a:                                       //loc_015a:
    goto loc_00e6;                              //jmp loc_00e6
loc_015c:                                       //loc_015c:
    sub_07d6();                                 //call sub_07d6
    sub_0200();                                 //call sub_0200
    sub_2b32();                                 //call sub_2b32
    sub_07bb();                                 //call sub_07bb
    sub_2b32();                                 //call sub_2b32
    sub_07bb();                                 //call sub_07bb
    sub_0c18();                                 //call sub_0c18 -- draw player
    _al = memory(_ds, 0x7d75);                  //mov al, [0x7d75]
    _al &= _al;                                 //and al, al
    if (_al != 0)                               //jnz loc_0195
        goto loc_0195;
    _al = memory(_ds, 0x7e82);                  //mov al, [0x7e82]
    //std::cout << "vert position " << (int)_al << "\n";
    if (_al < 0xcc)                             //jc loc_018b
        goto loc_018b;
    sub_0f81();                                 //call sub_0f81
    goto loc_0195;                              //jmp loc_0195
    _STOP_("db 90h");                           //db 90h
loc_018b:                                       //loc_018b:
    if (_al >= 0x60)                            //jnc loc_0195
        goto loc_0195;
    sub_0fef();                                 //call sub_0fef
loc_0195:                                       //loc_0195:
    goto loc_00e6;                              //jmp loc_00e6
loc_0198:                                       //loc_0198:
    sub_0652();                                 //call sub_0652
    sub_0337();                                 //call sub_0337
    sub_2b4d();                                 //call sub_2b4d
    _ax = 0x4c00;                               //mov ax, 0x4c00
    _interrupt(33);                             //int 0x21
    _STOP_("sp-trace-fail");                    //entry endp_failed
    _STOP_("continues");                        //sub_01a6 proc near
}

void sub_01a6()
{
    if (memory(_ds, 32143) != 0x00)             //jnz loc_01b1
        goto loc_01b1;
    return;                                     //ret
loc_01b1:                                       //loc_01b1:
    memory(_ds, 32149) -= 1;                    //dec byte ptr [0x7d95]
    if (memory(_ds, 32149) == 0x00)             //jz loc_01c0
        goto loc_01c0;
    return;                                     //ret
loc_01c0:                                       //loc_01c0:
    memory(_ds, 32149) = 0x1e;                  //mov byte ptr [0x7d95], 0x1e
    _push(_ds);                                 //push ds
    _ax = 0x1fc1;                               //mov ax, 0x1fc1
    _ds = _ax;                                  //mov ds, ax
    if (memory16(_ds, 18716) != 0x0000)         //jnz loc_01eb
        goto loc_01eb;
    if (memory16(_ds, 18718) != 0x0000)         //jnz loc_01eb
        goto loc_01eb;
    if (memory(_ds, 18720) != 0x00)             //jnz loc_01eb
        goto loc_01eb;
    _ds = _pop();                               //pop ds
    return;                                     //ret
loc_01eb:                                       //loc_01eb:
    _bx = 0x491f;                               //mov bx, 0x491f
loc_01ee:                                       //loc_01ee:
    memory(_ds, _bx) -= 1;                      //dec byte ptr [bx]
    if (!(memory(_ds, _bx) & 0x80))             //jz loc_01fe
        goto loc_01fe;
    memory(_ds, _bx) = 0x09;                    //mov byte ptr [bx], 0x9
    _bx -= 1;                                   //dec bx
    goto loc_01ee;                              //jmp loc_01ee
loc_01fe:                                       //loc_01fe:
    _ds = _pop();                               //pop ds
}

void sub_0200()
{
    _al = memory(_ds, 0x7e45);                  //mov al, [0x7e45]
    if (_al == memory(_ds, 32147))              //jz loc_0224
        goto loc_0224;
    memory(_ds, 0x7d93) = _al;                  //mov [0x7d93], al
    memory16(_ds, 29495) = 0x0101;              //mov word ptr [0x7337], 0x101
    memory16(_ds, 29497) = 0x0101;              //mov word ptr [0x7339], 0x101
    memory16(_ds, 29499) = 0x0101;              //mov word ptr [0x733b], 0x101
    sub_02c0();                                 //call sub_02c0
loc_0224:                                       //loc_0224:
    _al = memory(_ds, 0x7e47);                  //mov al, [0x7e47]
    if (_al != memory(_ds, 32148))              //jnz loc_0231
        goto loc_0231;
    return;                                     //ret
loc_0231:                                       //loc_0231:
    memory(_ds, 0x7d94) = _al;                  //mov [0x7d94], al
    memory16(_ds, 29503) = 0x0101;              //mov word ptr [0x733f], 0x101
    memory16(_ds, 29505) = 0x0101;              //mov word ptr [0x7341], 0x101
    memory16(_ds, 29507) = 0x0101;              //mov word ptr [0x7343], 0x101
    sub_02cf();                                 //call sub_02cf
}

void sub_024a()
{
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _bx = memory16(_ds, 32328);                 //mov bx, word ptr [0x7e48]
    _bx = _bx + memory16(_ds, 32330);           //add bx, word ptr [0x7e4a]
    _bx += 0x000d;                              //add bx, 0xd
    _cx = memory16(_ds, 32332);                 //mov cx, word ptr [0x7e4c]
    _bx += _cx;                                 //add bx, cx
    _al = 0;                                    //sub al, al
    _al = _al ^ _bl;                            //xor al, bl
    _al = _al ^ _ch;                            //xor al, ch
    _al = _al ^ _cl;                            //xor al, cl
    _al = _al ^ _bh;                            //xor al, bh
    _bl = _al;                                  //mov bl, al
    memory16(_ds, 32328) = _bx;                 //mov word ptr [0x7e48], bx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
}

void sub_0270()
{
    _flags.carry = (memory16(_ds, 32330) + 0x0001) >= 0x10000;
    memory16(_ds, 32330) += 0x0001;
    memory16(_ds, 32332) = memory16(_ds, 32332) + 0x0000 + _flags.carry;
}

void sub_027b()
{
    _push(_ds);                                 //push ds
    _di = 0x0145;                               //mov di, 0x145
    _ax = 0x1fc1;                               //mov ax, 0x1fc1
    _ds = _ax;                                  //mov ds, ax
    _ax = 0xb800;                               //mov ax, 0xb800
    _es = _ax;                                  //mov es, ax
    _bx = 0x490e;                               //mov bx, 0x490e
    sub_1f89();                                 //call sub_1f89
    _ds = _pop();                               //pop ds
}

void sub_0292()
{
    _push(_ds);                                 //push ds
    _ax = 0x1fc1;                               //mov ax, 0x1fc1
    _ds = _ax;                                  //mov ds, ax
    _si += 0x0004;                              //add si, 0x4
    _di = 0x4913;                               //mov di, 0x4913
    _cx = 0x0005;                               //mov cx, 0x5
    _flags.carry = false;                       //clc
loc_02a2:                                       //loc_02a2:
    _al = memory(_ds, _di);                     //mov al, byte ptr [di]
    _al = _al + memory(_ds, _si) + _flags.carry;
    if (_al < 0x3a)                             //jc loc_02b0
    {
        _flags.carry = true; // TODO: need to check
        goto loc_02b0;
    }
    _al -= 0x0a;                                //sub al, 0xa
    _flags.carry = false;                       //clc
loc_02b0:                                       //loc_02b0:
    _cmc();                                     //cmc
    memory(_ds, _di) = _al;                     //mov byte ptr [di], al
    _di -= 1;                                   //dec di
    _si -= 1;                                   //dec si
    if (--_cx)                                  //loop loc_02a2
        goto loc_02a2;
    _al = memory(_ds, _di);                     //mov al, byte ptr [di]
    _al = _al + 0x00 + _flags.carry;   //TODO: check //adc al, 0x0
    memory(_ds, _di) = _al;                     //mov byte ptr [di], al
    _ds = _pop();                               //pop ds
    {sub_027b(); return; };                     //
}

void loc_02ea();

void sub_02c0()
{
    _cl = memory(_ds, 32325);                   //mov cl, byte ptr [0x7e45]
    _ch = 0;                                    //sub ch, ch
    _al = 0x01;                                 //mov al, 0x1
    _di = 0x014d;                               //mov di, 0x14d
    loc_02ea();
    return;
    //_STOP_("goto loc_02ea");                    //jmp loc_02ea
    _STOP_("db 90h");                           //db 90h
    _STOP_("sp-trace-fail");                    //sub_02c0 endp_failed
    _STOP_("continues");                        //sub_02cf proc near
}

void sub_02cf()
{
    _cl = memory(_ds, 32327);                   //mov cl, byte ptr [0x7e47]
    _ch = 0;                                    //sub ch, ch
    _al = 0x02;                                 //mov al, 0x2
    _di = 0x0155;                               //mov di, 0x155
    loc_02ea();                              //jmp loc_02ea
}

void loc_02de()                                       //loc_02de:
{
    _cl = memory(_ds, 32326);                   //mov cl, byte ptr [0x7e46]
    _ch = 0;                                    //sub ch, ch
    _al = 0x03;                                 //mov al, 0x3
    _di = 0x015d;                               //mov di, 0x15d
loc_02ea:
    loc_02ea();
}

void loc_02ea()                                       //loc_02ea:
{
    if (_cx != 0x0000)                          //jnz loc_02f3
        goto loc_02f3;
    return;                                     //ret
loc_02f3:                                       //loc_02f3:
    _push(_ds);                                 //push ds
    _bx = 0x1fc1;                               //mov bx, 0x1fc1
    _ds = _bx;                                  //mov ds, bx
    _bx = 0xb800;                               //mov bx, 0xb800
    _es = _bx;                                  //mov es, bx
loc_02fe:                                       //loc_02fe:
    _push(_cx);                                 //push cx
    _push(_ax);                                 //push ax
    sub_1fa0();                                 //call sub_1fa0
    _ax = _pop();                               //pop ax
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_02fe
        goto loc_02fe;
    _ds = _pop();                               //pop ds
}

void sub_0309()
{
    sub_027b();                                 //call sub_027b
    sub_02c0();                                 //call sub_02c0
    sub_02cf();                                 //call sub_02cf
    loc_02de();
    //_STOP_("goto loc_02de");                    //jmp loc_02de
}

void sub_0314()
{
    _push(_ds);                                 //push ds
    _ah = 0x35;                                 //mov ah, 0x35
    _al = 0x09;                                 //mov al, 0x9
    _interrupt(33);                             //int 0x21
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    memory16(_ds, 32318) = _es;                 //mov word ptr [0x7e3e], es
    memory16(_ds, 32320) = _bx;                 //mov word ptr [0x7e40], bx
    _ah = 0x25;                                 //mov ah, 0x25
    _al = 0x09;                                 //mov al, 0x9
    _dx = _cs;                                  //mov dx, cs
    _ds = _dx;                                  //mov ds, dx
    _dx = 0x0348;                               //mov dx, 0x348
    _interrupt(33);                             //int 0x21
    _ds = _pop();                               //pop ds
}

void sub_0337()
{
    _push(_ds);                                 //push ds
    _dx = memory16(_ds, 32320);                 //mov dx, word ptr [0x7e40]
    _ds = memory16(_ds, 32318);                 //mov ds, word ptr [0x7e3e]
    _ah = 0x25;                                 //mov ah, 0x25
    _al = 0x09;                                 //mov al, 0x9
    _interrupt(33);                             //int 0x21
    _ds = _pop();                               //pop ds
}

void sub_0348()
{
    _flags.interrupt = true;                    //sti
    _push(_ax);                                 //push ax
    _push(_ds);                                 //push ds
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _in(_al, 96);                               //in al, 0x60
    memory(_ds, 0x7e43) = _al;                  //mov [0x7e43], al
    _in(_al, 97);                               //in al, 0x61
    _al |= 0x80;                                //or al, 0x80
    _out(97, _al);                              //out 0x61, al
    _al &= 0x7f;                                //and al, 0x7f
    _out(97, _al);                              //out 0x61, al
    _push(_bx);                                 //push bx
    _al = memory(_ds, 0x7e43);                  //mov al, [0x7e43]
    _ah = _al;                                  //mov ah, al
    _ah &= 0x80;                                //and ah, 0x80
    if (_ah == 0)                               //jz loc_03ce
        goto loc_03ce;
    _bl = memory(_ds, 32324);                   //mov bl, byte ptr [0x7e44]
    _al &= 0x7f;                                //and al, 0x7f
    if (_al != 0x18)                            //jnz loc_0380
        goto loc_0380;
    _bl &= 0xf7;                                //and bl, 0xf7
    goto loc_041d;                              //jmp loc_041d
loc_0380:                                       //loc_0380:
    if (_al != 0x25)                            //jnz loc_038d
        goto loc_038d;
    _bl &= 0xfb;                                //and bl, 0xfb
    goto loc_041d;                              //jmp loc_041d
loc_038d:                                       //loc_038d:
    if (_al != 0x2c)                            //jnz loc_039a
        goto loc_039a;
    _bl &= 0xfd;                                //and bl, 0xfd
    goto loc_041d;                              //jmp loc_041d
loc_039a:                                       //loc_039a:
    if (_al != 0x2d)                            //jnz loc_03a7
        goto loc_03a7;
    _bl &= 0xfe;                                //and bl, 0xfe
    goto loc_041d;                              //jmp loc_041d
    _STOP_("db 90h");                           //db 90h
loc_03a7:                                       //loc_03a7:
    if (_al != 0x39)                            //jnz loc_03b4
        goto loc_03b4;
    _bl &= 0xef;                                //and bl, 0xef
    goto loc_041d;                              //jmp loc_041d
    _STOP_("db 90h");                           //db 90h
loc_03b4:                                       //loc_03b4:
    if (_al != 0x19)                            //jnz loc_03c1
        goto loc_03c1;
    _bl &= 0x7f;                                //and bl, 0x7f
    goto loc_0427;                              //jmp loc_0427
    _STOP_("db 90h");                           //db 90h
loc_03c1:                                       //loc_03c1:
    if (_al != 0x12)                            //jnz loc_0427
        goto loc_0427;
    _bl &= 0xbf;                                //and bl, 0xbf
    goto loc_0427;                              //jmp loc_0427
    _STOP_("db 90h");                           //db 90h
loc_03ce:                                       //loc_03ce:
    _bl = memory(_ds, 32324);                   //mov bl, byte ptr [0x7e44]
    if (_al != 0x18)                            //jnz loc_03df
        goto loc_03df;
    _bl |= 0x08;                                //or bl, 0x8
    goto loc_041d;                              //jmp loc_041d
    _STOP_("db 90h");                           //db 90h
loc_03df:                                       //loc_03df:
    if (_al != 0x25)                            //jnz loc_03ec
        goto loc_03ec;
    _bl |= 0x04;                                //or bl, 0x4
    goto loc_041d;                              //jmp loc_041d
    _STOP_("db 90h");                           //db 90h
loc_03ec:                                       //loc_03ec:
    if (_al != 0x2c)                            //jnz loc_03f9
        goto loc_03f9;
    _bl |= 0x02;                                //or bl, 0x2
    goto loc_041d;                              //jmp loc_041d
    _STOP_("db 90h");                           //db 90h
loc_03f9:                                       //loc_03f9:
    if (_al != 0x2d)                            //jnz loc_0406
        goto loc_0406;
    _bl |= 0x01;                                //or bl, 0x1
    goto loc_041d;                              //jmp loc_041d
    _STOP_("db 90h");                           //db 90h
loc_0406:                                       //loc_0406:
    if (_al != 0x39)                            //jnz loc_0413
        goto loc_0413;
    _bl |= 0x10;                                //or bl, 0x10
    goto loc_041d;                              //jmp loc_041d
    _STOP_("db 90h");                           //db 90h
loc_0413:                                       //loc_0413:
    if (_al != 0x19)                            //jnz loc_041d
        goto loc_041d;
    _bl |= 0x80;                                //or bl, 0x80
loc_041d:                                       //loc_041d:
    if (_al != 0x12)                            //jnz loc_0427
        goto loc_0427;
    _bl |= 0x40;                                //or bl, 0x40
loc_0427:                                       //loc_0427:
    memory(_ds, 32324) = _bl;                   //mov byte ptr [0x7e44], bl -- set keyboard char
    _bx = _pop();                               //pop bx
    _ds = _pop();                               //pop ds
    _al = 0x61;                                 //mov al, 0x61
    _out(32, _al);                              //out 0x20, al
    _ax = _pop();                               //pop ax
    return;                                     //iret
    _STOP_("sp-trace-fail");                    //sub_0348 endp_failed
    _STOP_("continues");                        //sub_0433 proc near
}

void sub_0433()
{
    _sync();
    _al = memory(_ds, 0x7e44);                  //mov al, [0x7e44]
    _al &= 0x10;                                //and al, 0x10
    if (_al == 0)                               //jz loc_0440
        goto loc_0440;
    _al = 0;                                    //sub al, al
    _flags.zero = true;
    return;                                     //ret
loc_0440:                                       //loc_0440:
    _al = 0;                                    //sub al, al
    _al -= 1;                                   //dec al
    _flags.zero = false;
}
extern int check;
void sub_0445()
{
    _sync();
    check =0;
    _al = memory(_ds, 0x7e44);                  //mov al, [0x7e44]
    check =1;
    _al &= 0x80;                                //and al, 0x80
    _flags.zero = _al == 0x80;
}

void sub_044d()
{
    check =0;
    _sync();
    _al = memory(_ds, 0x7e44);                  //mov al, [0x7e44]
    check =1;
    _al &= 0x40;                                //and al, 0x40
    _flags.zero = _al == 0x40;
}

void sub_0455()
{
    _sync();
    check =0;
   
    _al = memory(_ds, 0x7e44);                  //mov al, [0x7e44]
    check =1;
   
    _al &= 0x80;                                //and al, 0x80
    _flags.zero = _al == 0x80;
}

void sub_045d()
{
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    _ah = 0x01;                                 //mov ah, 0x1
    _interrupt(22);                             //int 0x16
loc_0464:                                       //loc_0464:
    assert(0);
    if (!_flags.zero)                           //jnz loc_0476
        goto loc_0476;
    sub_265a();                                 //call sub_265a
    _ah = 0;                                    //sub ah, ah
    _interrupt(22);                             //int 0x16
    _ah = 0x01;                                 //mov ah, 0x1
    _interrupt(22);                             //int 0x16
    if (_flags.zero)                            //jz loc_0464
        goto loc_0464;
loc_0476:                                       //loc_0476:
    _bp = _pop();                               //pop bp
}

void sub_0478()
{
    memory(_ds, 38270) = 0x00;                  //mov byte ptr [0x957e], 0x0
    _ah = 0x3d;                                 //mov ah, 0x3d
    _al = 0x00;                                 //mov al, 0x0
    _interrupt(33);                             //int 0x21
    if (_flags.carry)                           //jc loc_048c
        goto loc_048c;
    memory16(_ds, 0x957f) = _ax;                //mov [0x957f], ax
    return;                                     //ret
loc_048c:                                       //loc_048c:
    memory(_ds, 38270) = 0x01;                  //mov byte ptr [0x957e], 0x1
    _dx = 0x1fc1;                               //mov dx, 0x1fc1
    _push(_ds);                                 //push ds
    _ds = _dx;                                  //mov ds, dx
    _al += 0x30;                                //add al, 0x30
    memory(_ds, 0x490e) = _al;                  //mov [0x490e], al
    _ds = _pop();                               //pop ds
    sub_027b();                                 //call sub_027b
}

void sub_04a1()
{
    memory(_ds, 38270) = 0x00;                  //mov byte ptr [0x957e], 0x0
    _bx = memory16(_ds, 38271);                 //mov bx, word ptr [0x957f]
    _ah = 0x3f;                                 //mov ah, 0x3f
    _interrupt(33);                             //int 0x21
    if (_flags.carry)                           //jc loc_04b4
        goto loc_04b4;
    return;                                     //ret
loc_04b4:                                       //loc_04b4:
    memory(_ds, 38270) = 0x02;                  //mov byte ptr [0x957e], 0x2
}

void sub_04ba()
{
    memory(_ds, 38270) = 0x00;                  //mov byte ptr [0x957e], 0x0
    _bx = memory16(_ds, 38271);                 //mov bx, word ptr [0x957f]
    _push(_cx);                                 //push cx
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _ah = 0x40;                                 //mov ah, 0x40
    _interrupt(33);                             //int 0x21
    _cx = _pop();                               //pop cx
    if (_flags.carry)                           //jc loc_04e1
        goto loc_04e1;
    if (_ax != _cx)                             //jnz loc_04db
        goto loc_04db;
    return;                                     //ret
loc_04db:                                       //loc_04db:
    memory(_ds, 38270) = 0x05;                  //mov byte ptr [0x957e], 0x5
    return;                                     //ret
loc_04e1:                                       //loc_04e1:
    memory(_ds, 38270) = 0x04;                  //mov byte ptr [0x957e], 0x4
}

void sub_04e7()
{
    _ah = 0x3f;                                 //mov ah, 0x3f
    _bx = memory16(_ds, 38271);                 //mov bx, word ptr [0x957f]
    _interrupt(33);                             //int 0x21
    if (_flags.carry)                           //jc loc_04f5
        goto loc_04f5;
    return;                                     //ret
loc_04f5:                                       //loc_04f5:
    memory(_ds, 38270) = 0x03;                  //mov byte ptr [0x957e], 0x3
}

void sub_04fb()
{
    _dx = 0x1040;                               //mov dx, 0x1040
    _ds = _dx;                                  //mov ds, dx
    _bh = 0x00;                                 //mov bh, 0x0
    _bx += _bx;                                 //add bx, bx
    _push(_bx);                                 //push bx
    _bx += 0x9647;                              //add bx, 0x9647
    _dx = memory16(_ds, _bx);                   //mov dx, word ptr [bx]
    memory16(_ds, 38505) = _dx;                 //mov word ptr [0x9669], dx
    _bx = _pop();                               //pop bx
    _push(_bx);                                 //push bx
    _bx += 0x962f;                              //add bx, 0x962f
    _dx = memory16(_ds, _bx);                   //mov dx, word ptr [bx]
    memory16(_ds, 38507) = _dx;                 //mov word ptr [0x966b], dx
    _bx = _pop();                               //pop bx
    _bx += 0x9615;                              //add bx, 0x9615
    _dx = memory16(_ds, _bx);                   //mov dx, word ptr [bx]
    sub_0478();                                 //call sub_0478
    _al = memory(_ds, 0x957e);                  //mov al, [0x957e]
    if (_al != 0x00)                            //jnz loc_0557
        goto loc_0557;
    _dx = 0x1040;                               //mov dx, 0x1040
    _ds = _dx;                                  //mov ds, dx
    _dx = memory16(_ds, 38507);                 //mov dx, word ptr [0x966b]
    _cx = memory16(_ds, 38505);                 //mov cx, word ptr [0x9669]
    sub_04a1();                                 //call sub_04a1
    _al = memory(_ds, 0x957e);                  //mov al, [0x957e]
    if (_al != 0x00)                            //jnz loc_0557
        goto loc_0557;
    sub_04e7();                                 //call sub_04e7
    _al = memory(_ds, 0x957e);                  //mov al, [0x957e]
    if (_al != 0x00)                            //jnz loc_0557
        goto loc_0557;
    return;                                     //ret
loc_0557:                                       //loc_0557:
    _bh = 0x00;                                 //mov bh, 0x0
    _bl = memory(_ds, 38270);                   //mov bl, byte ptr [0x957e]
    _bl -= 1;                                   //dec bl
    _bl += _bl;                                 //add bl, bl
    _bx += 0x96fc;                              //add bx, 0x96fc
    _dx = memory16(_ds, _bx);                   //mov dx, word ptr [bx]
    _ah = 0x09;                                 //mov ah, 0x9
    _interrupt(33);                             //int 0x21
    _ah = 0x08;                                 //mov ah, 0x8
    _interrupt(33);                             //int 0x21
}

void sub_0570()
{
loc_0570:
    _ah = 0x4a;                                 //mov ah, 0x4a
    _bx = 0x3000;                               //mov bx, 0x3000
    _interrupt(33);                             //int 0x21
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _ax = 0x2455;                               //mov ax, 0x2455
    memory16(_ds, 0x9661) = _ax;                //mov [0x9661], ax
    _ah = 0x48;                                 //mov ah, 0x48
    _bx = 0x0fff;                               //mov bx, 0xfff
    _interrupt(33);                             //int 0x21
    if (_flags.carry)                           //jc sub_0570
        goto loc_0570;
    memory16(_ds, 0x9663) = _ax;                //mov [0x9663], ax
    _ah = 0x48;                                 //mov ah, 0x48
    _bx = 0x0fff;                               //mov bx, 0xfff
    _interrupt(33);                             //int 0x21
    if (_flags.carry)                           //jc sub_0570
        goto loc_0570;
    memory16(_ds, 0x9665) = _ax;                //mov [0x9665], ax
    _ah = 0x48;                                 //mov ah, 0x48
    _bx = 0x0fff;                               //mov bx, 0xfff
    _interrupt(33);                             //int 0x21
    if (_flags.carry)                           //jc sub_0570
        goto loc_0570;
    memory16(_ds, 0x9667) = _ax;                //mov [0x9667], ax
    _ah = 0x0f;                                 //mov ah, 0xf
    _interrupt(16);                             //int 0x10
    memory(_ds, 0x7e42) = _al;                  //mov [0x7e42], al
    _ax = 0x000d;                               //mov ax, 0xd
    _interrupt(16);                             //int 0x10
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    sub_06f8();                                 //call sub_06f8
    _ax = 0x1fc1;                               //mov ax, 0x1fc1
    _ds = _ax;                                  //mov ds, ax
    _ax = 0x1040;                               //mov ax, 0x1040
    _es = _ax;                                  //mov es, ax
    _si = 0x0000;                               //mov si, 0x0
    _di = 0x223a;                               //mov di, 0x223a
    _cx = 0x2000;                               //mov cx, 0x2000
    _flags.direction = false;                   //cld
    _rep_movsb<MemData, MemData, DirForward>(); //rep movsb
    _dx = 0x2000;                               //mov dx, 0x2000
    sub_0661();                                 //call sub_0661
    _ax = 0x1fc1;                               //mov ax, 0x1fc1
    _ds = _ax;                                  //mov ds, ax
    _ax = 0x1040;                               //mov ax, 0x1040
    _es = _ax;                                  //mov es, ax
    _si = 0x2000;                               //mov si, 0x2000
    _di = 0x223a;                               //mov di, 0x223a
    _cx = 0x2000;                               //mov cx, 0x2000
    _flags.direction = false;                   //cld
    _rep_movsb<MemData, MemData, DirForward>(); //rep movsb
    _dx = 0x2800;                               //mov dx, 0x2800
    sub_0661();                                 //call sub_0661
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _si = 0x9810;                               //mov si, 0x9810
    _di = 0x223a;                               //mov di, 0x223a
    _cx = 0x2000;                               //mov cx, 0x2000
    _flags.direction = false;                   //cld
    _rep_movsb<MemData, MemData, DirForward>(); //rep movsb
    _dx = 0x3000;                               //mov dx, 0x3000
    sub_0661();                                 //call sub_0661
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _si = 0xd810;                               //mov si, 0xd810
    _di = 0x223a;                               //mov di, 0x223a
    _cx = 0x2000;                               //mov cx, 0x2000
    _flags.direction = false;                   //cld
    _rep_movsb<MemData, MemData, DirForward>(); //rep movsb
    _dx = 0x3800;                               //mov dx, 0x3800
    sub_0661();                                 //call sub_0661
    _ax = 0x1fc1;                               //mov ax, 0x1fc1
    _es = _ax;                                  //mov es, ax
    memory(_ds, 32144) = 0x00;                  //mov byte ptr [0x7d90], 0x0
    sub_0786();                                 //call sub_0786
    _ax = 0x9810;                               //mov ax, 0x9810
    memory16(_ds, 0x7d5e) = _ax;                //mov [0x7d5e], ax
    _ax = 0x3000;                               //mov ax, 0x3000
    memory16(_ds, 0x971a) = _ax;                //mov [0x971a], ax
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _ax = 0x0105;                               //mov ax, 0x105
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0001;                               //mov ax, 0x1
    _out(_dx, _ax);                             //out dx, ax
    _dx = 0x03c4;                               //mov dx, 0x3c4
    _ax = 0x0f02;                               //mov ax, 0xf02
    _out(_dx, _ax);                             //out dx, ax
}

void sub_0652()
{
    _push(_ds);                                 //push ds
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _al = memory(_ds, 0x7e42);                  //mov al, [0x7e42]
    _ah = 0x00;                                 //mov ah, 0x0
    _interrupt(16);                             //int 0x10
    _ds = _pop();                               //pop ds
}

void sub_0661() //BP 2608:0661
{
    _push(_ds);                                 //push ds
    _push(_bp);                                 //push bp
    _push(_dx);                                 //push dx
    _bp = _sp;                                  //mov bp, sp
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _ax = 0x0001;                               //mov ax, 0x1
    _out(_dx, _ax);                             //out dx, ax
    _al = 0x03;                                 //mov al, 0x3
    _out(_dx, _ax);                             //out dx, ax
    _al = 0x05;                                 //mov al, 0x5
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0xff08;                               //mov ax, 0xff08
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0xa000;                               //mov ax, 0xa000
    _es = _ax;                                  //mov es, ax
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _dx = 0x03c4;                               //mov dx, 0x3c4
    _ax = 0x0102;                               //mov ax, 0x102
    _out(_dx, _ax);                             //out dx, ax
    _di = memory16(_ss, _bp + 0);               //mov di, word ptr [bp+0x0]
    _cx = 0x0800;                               //mov cx, 0x800
    _si = 0x223a;                               //mov si, 0x223a
    _rep_movsb<MemVideo, MemData, DirForward>(); //rep movsb
    _cx = 0x0800;                               //mov cx, 0x800
    _si = 0x423a;                               //mov si, 0x423a
/*
        for (int i=0; i<32; i++)
            std::cout << std::hex << (int)memory(_ds, _si+i) << ", ";
        std::cout << "\n";
*/
    _rep_movsb<MemVideo, MemData, DirForward>(); //rep movsb

//    while (1)
//        _sync();

    _ax = 0x0202;                               //mov ax, 0x202
    _out(_dx, _ax);                             //out dx, ax
    _di = memory16(_ss, _bp + 0);               //mov di, word ptr [bp+0x0] -- parser
    _cx = 0x0800;                               //mov cx, 0x800
    _si = 0x2a3a;                               //mov si, 0x2a3a
    _rep_movsb<MemVideo, MemData, DirForward>(); //rep movsb
    _cx = 0x0800;                               //mov cx, 0x800
    _si = 0x4a3a;                               //mov si, 0x4a3a
    _rep_movsb<MemVideo, MemData, DirForward>(); //rep movsb
    _ax = 0x0402;                               //mov ax, 0x402
    _out(_dx, _ax);                             //out dx, ax
    
    _di = memory16(_ss, _bp + 0);               //mov di, word ptr [bp+0x0] -- parser
    _si = 0x323a;                               //mov si, 0x323a
    _cx = 0x0800;                               //mov cx, 0x800
    _rep_movsb<MemVideo, MemData, DirForward>(); //rep movsb
    _si = 0x523a;                               //mov si, 0x523a
    _cx = 0x0800;                               //mov cx, 0x800
    _rep_movsb<MemVideo, MemData, DirForward>(); //rep movsb
    _ax = 0x0802;                               //mov ax, 0x802
    _out(_dx, _ax);                             //out dx, ax
    
    _di = _pop();                               //pop di
    _cx = 0x0800;                               //mov cx, 0x800
    _si = 0x3a3a;                               //mov si, 0x3a3a
    _rep_movsb<MemVideo, MemData, DirForward>(); //rep movsb
    _cx = 0x0800;                               //mov cx, 0x800
    _si = 0x5a3a;                               //mov si, 0x5a3a
    _rep_movsb<MemVideo, MemData, DirForward>(); //rep movsb
    _dx = 0x03c4;                               //mov dx, 0x3c4
    _ax = 0x0f02;                               //mov ax, 0xf02
    _out(_dx, _ax);                             //out dx, ax
    
    _bp = _pop();                               //pop bp
    _ds = _pop();                               //pop ds
//    while (1)
//        _sync();
}
//    for (int i=0; i<32; i++)
//        std::cout << std::hex << (int)memory(_ds, _si+i) << ", ";
//    std::cout << "\n";

void sub_06e8()
{
}

void sub_06e9()
{
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = 0x2455;                               //mov ax, 0x2455
    _es = _ax;                                  //mov es, ax
    _si = 0x9810;                               //mov si, 0x9810
    _rep_movsw<MemData, MemData, DirForward>(); //rep movsw
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_06f8()
{
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _dx = 0;                                    //sub dx, dx
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _dx = memory16(_ds, 38499);                 //mov dx, word ptr [0x9663]
    _ax = 0x2455;                               //mov ax, 0x2455
    _ds = _ax;                                  //mov ds, ax
    _es = _dx;                                  //mov es, dx
    sub_0736();                                 //call sub_0736
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _dx = memory16(_ds, 38501);                 //mov dx, word ptr [0x9665]
    _push(_es);                                 //push es
    _ds = _pop();                               //pop ds
    _ax = _dx;                                  //mov ax, dx
    _es = _ax;                                  //mov es, ax
    sub_0736();                                 //call sub_0736
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _dx = memory16(_ds, 38503);                 //mov dx, word ptr [0x9667]
    _push(_es);                                 //push es
    _ds = _pop();                               //pop ds
    _ax = _dx;                                  //mov ax, dx
    _es = _ax;                                  //mov es, ax
    sub_0736();                                 //call sub_0736
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_0736()
{
    _di = 0x0000;                               //mov di, 0x0
    _cx = 0x009a;                               //mov cx, 0x9a
loc_073c:                                       //loc_073c:
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _cx = 0x0015;                               //mov cx, 0x15
loc_0741:                                       //loc_0741:
    _push(_cx);                                 //push cx
    _ax = memory16(_ds, _di);                   //mov ax, word ptr [di]
    _bx = memory16(_ds, _di + 10);              //mov bx, word ptr [di+0xa]
    _flags.carry = true;                        //stc
    _rcr(_ax, 1);                               //rcr ax, 1
    _rcr(_bx, 1);                               //rcr bx, 1
    _flags.carry = true;                        //stc
    _rcr(_ax, 1);                               //rcr ax, 1
    _rcr(_bx, 1);                               //rcr bx, 1
    memory16(_es, _di) = _ax;                   //mov word ptr es:[di], ax
    memory16(_es, _di + 0xA) = _bx;             //mov word ptr es:[di+0xa], bx
    _di += 0x0002;                              //add di, 0x2
    _cx = 0x0004;                               //mov cx, 0x4
loc_075e:                                       //loc_075e:
    _ax = memory16(_ds, _di);                   //mov ax, word ptr [di]
    _bx = memory16(_ds, _di + 10);              //mov bx, word ptr [di+0xa]
    _flags.carry = _ax & 1;                     //shr ax, 1
    _ax >>= 1;
    _rcr(_bx, 1);                               //rcr bx, 1
    _flags.carry = _ax & 1;                     //shr ax, 1
    _ax >>= 1;
    _rcr(_bx, 1);                               //rcr bx, 1
    memory16(_es, _di) = _ax;                   //mov word ptr es:[di], ax
    memory16(_es, _di + 0xA) = _bx;             //mov word ptr es:[di+0xa], bx
    _di += 0x0002;                              //add di, 0x2
    if (--_cx)                                  //loop loc_075e
        goto loc_075e;
    _di += 0x000a;                              //add di, 0xa
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_0741
        goto loc_0741;
    _di = _pop();                               //pop di
    _di += 0x01a4;                              //add di, 0x1a4
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_073c
        goto loc_073c;
}

void sub_0786()
{
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _dx = 0x9709;                               //mov dx, 0x9709
    _ax = 0x1002;                               //mov ax, 0x1002
    _interrupt(16);                             //int 0x10
    return;                                     //ret
    _STOP_("db c3h");                           //db c3h
    _STOP_("sp-trace-fail");                    //sub_0786 endp_failed
    _STOP_("continues");                        //sub_0797 proc near
}

void sub_0797()
{
    _push(_es);                                 //push es
    _ax = 0xa000;                               //mov ax, 0xa000
    _es = _ax;                                  //mov es, ax
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _ax = 0x0005;                               //mov ax, 0x5
    _out(_dx, _ax);                             //out dx, ax
    _al = 0x01;                                 //mov al, 0x1
    _out(_dx, _ax);                             //out dx, ax
    _al = 0x05;                                 //mov al, 0x5
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0;                                    //sub ax, ax
    _di = _ax;                                  //mov di, ax
    _ax = _di;                                  //mov ax, di
    _cx = 0x0fa0;                               //mov cx, 0xfa0
    _rep_stosw<MemVideo, DirForward>();          //rep stosw
    _ax = 0x0105;                               //mov ax, 0x105
    _out(_dx, _ax);                             //out dx, ax
    _es = _pop();                               //pop es
}

void sub_07bb()
{
    _dx = 0x03da;                               //mov dx, 0x3da
loc_07be:                                       //loc_07be:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x08;                                //and al, 0x8
    if (_al != 0)                               //jnz loc_07be
        goto loc_07be;
loc_07c3:                                       //loc_07c3:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x08;                                //and al, 0x8
    if (_al == 0)                               //jz loc_07c3
        goto loc_07c3;
}

void sub_07c9()
{
loc_07c9:
    if (memory(_ds, 32323) != 0x39)             //jnz sub_07c9
        goto loc_07c9;
    memory(_ds, 32323) = 0x00;                  //mov byte ptr [0x7e43], 0x0
}

void sub_07d6()
{
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _ax = 0x0001;                               //mov ax, 0x1
    _out(_dx, _ax);                             //out dx, ax
    _al = 0x03;                                 //mov al, 0x3
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _ax = 0x023a;                               //mov ax, 0x23a
    memory16(_ds, 0x7d96) = _ax;                //mov [0x7d96], ax
    _ax = 0x0002;                               //mov ax, 0x2
    memory16(_ds, 0x7e3c) = _ax;                //mov [0x7e3c], ax
    _si = 0x7e4e;                               //mov si, 0x7e4e
loc_07f6:                                       //loc_07f6:
    _al = memory(_ds, _si);                     //mov al, byte ptr [si]
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz loc_0809
        goto loc_0809;
    if (_al == 0xff)                            //jz loc_080e
        goto loc_080e;
    sub_087e();                                 //call sub_087e
loc_0809:                                       //loc_0809:
    _si += 0x0030;                              //add si, 0x30
    goto loc_07f6;                              //jmp loc_07f6
loc_080e:                                       //loc_080e:
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _ax = 0x0001;                               //mov ax, 0x1
    _out(_dx, _ax);                             //out dx, ax
    _al = 0x03;                                 //mov al, 0x3
    _out(_dx, _ax);                             //out dx, ax
    _al = 0x05;                                 //mov al, 0x5
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0xff08;                               //mov ax, 0xff08
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0xa000;                               //mov ax, 0xa000
    _es = _ax;                                  //mov es, ax
    _bx = memory16(_ds, 32316);                 //mov bx, word ptr [0x7e3c]
    _bx -= 0x0002;                              //sub bx, 0x2
    _dx = 0x03c4;                               //mov dx, 0x3c4
    _ax = 0x0102;                               //mov ax, 0x102
    _out(_dx, _ax);                             //out dx, ax
    _si = 0x023a;                               //mov si, 0x23a
    _di = 0x4000;                               //mov di, 0x4000
    _cx = _bx;                                  //mov cx, bx
loc_083a:                                       //loc_083a:
    _movsw<MemVideo, MemData, DirForward>();     //movsw
    _movsw<MemVideo, MemData, DirForward>();     //movsw
    _movsw<MemVideo, MemData, DirForward>();     //movsw
    _movsw<MemVideo, MemData, DirForward>();     //movsw
    if (--_cx)                                  //loop loc_083a
        goto loc_083a;
    _ah = 0x02;                                 //mov ah, 0x2
    _out(_dx, _ax);                             //out dx, ax
    _si = 0x0a3a;                               //mov si, 0xa3a
    _di = 0x4000;                               //mov di, 0x4000
    _cx = _bx;                                  //mov cx, bx
loc_084b:                                       //loc_084b:
    _movsw<MemVideo, MemData, DirForward>();     //movsw
    _movsw<MemVideo, MemData, DirForward>();     //movsw
    _movsw<MemVideo, MemData, DirForward>();     //movsw
    _movsw<MemVideo, MemData, DirForward>();     //movsw
    if (--_cx)                                  //loop loc_084b
        goto loc_084b;
    _ah = 0x04;                                 //mov ah, 0x4
    _out(_dx, _ax);                             //out dx, ax
    _si = 0x123a;                               //mov si, 0x123a
    _di = 0x4000;                               //mov di, 0x4000
    _cx = _bx;                                  //mov cx, bx
loc_085c:                                       //loc_085c:
    _movsw<MemVideo, MemData, DirForward>();     //movsw
    _movsw<MemVideo, MemData, DirForward>();     //movsw
    _movsw<MemVideo, MemData, DirForward>();     //movsw
    _movsw<MemVideo, MemData, DirForward>();     //movsw
    if (--_cx)                                  //loop loc_085c
        goto loc_085c;
    _ah = 0x08;                                 //mov ah, 0x8
    _out(_dx, _ax);                             //out dx, ax
    _si = 0x1a3a;                               //mov si, 0x1a3a
    _di = 0x4000;                               //mov di, 0x4000
    _cx = _bx;                                  //mov cx, bx
loc_086d:                                       //loc_086d:
    _movsw<MemVideo, MemData, DirForward>();     //movsw
    _movsw<MemVideo, MemData, DirForward>();     //movsw
    _movsw<MemVideo, MemData, DirForward>();     //movsw
    _movsw<MemVideo, MemData, DirForward>();     //movsw
    if (--_cx)                                  //loop loc_086d
        goto loc_086d;
    _ah = 0x0f;                                 //mov ah, 0xf
    _out(_dx, _ax);                             //out dx, ax
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _ax = 0x0105;                               //mov ax, 0x105
    _out(_dx, _ax);                             //out dx, ax
}

void sub_087e()
{
    _push(_si);                                 //push si
    _bl = memory(_ds, _si + 8);                 //mov bl, byte ptr [si+0x8]
    _bh = 0;                                    //sub bh, bh
    _bx += _bx;                                 //add bx, bx
    _bx += 0x0100;                              //add bx, 0x100
    _ax = memory16(_ds, _bx);                   //mov ax, word ptr [bx]
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, _si + 4);               //mov ax, word ptr [si+0x4]
    _dl = _al;                                  //mov dl, al
    _ax &= 0x01f8;                              //and ax, 0x1f8
    _ax += _ax;                                 //add ax, ax
    _ax += _ax;                                 //add ax, ax
    _bx = memory16(_ds, _si + 2);               //mov bx, word ptr [si+0x2]
    _dh = _bl;                                  //mov dh, bl
    _cl = 0x03;                                 //mov cl, 0x3
    _bx >>= _cl;                                //shr bx, cl
    _ax += _bx;                                 //add ax, bx
    _ax += 0x778e;                              //add ax, 0x778e
    _si = _ax;                                  //mov si, ax
    _dl &= 0x07;                                //and dl, 0x7
    if (!(_dl & 0x04))                          //jz loc_08b7
        goto loc_08b7;
    goto loc_09fb;                              //jmp loc_09fb
loc_08b7:                                       //loc_08b7:
    _di = memory16(_ds, 32150);                 //mov di, word ptr [0x7d96]
    sub_0b58();                                 //call sub_0b58
    _si += 0x0020;                              //add si, 0x20
    sub_0b58();                                 //call sub_0b58
    _si += 0x0020;                              //add si, 0x20
    sub_0b58();                                 //call sub_0b58
    _si += 0xffc1;                          //add si, -0x3f
    sub_0b58();                                 //call sub_0b58
    _si += 0x0020;                              //add si, 0x20
    sub_0b58();                                 //call sub_0b58
    _si += 0x0020;                              //add si, 0x20
    sub_0b58();                                 //call sub_0b58
    _si += 0xffc1;                          //add si, -0x3f
    sub_0b58();                                 //call sub_0b58
    _si += 0x0020;                              //add si, 0x20
    sub_0b58();                                 //call sub_0b58
    _si += 0x0020;                              //add si, 0x20
    sub_0b58();                                 //call sub_0b58
    _si += 0xffc1;                          //add si, -0x3f
    sub_0b58();                                 //call sub_0b58
    _si += 0x0020;                              //add si, 0x20
    sub_0b58();                                 //call sub_0b58
    _si += 0x0020;                              //add si, 0x20
    sub_0b58();                                 //call sub_0b58
    memory16(_ds, 32150) = _di;                 //mov word ptr [0x7d96], di
    _di -= 0x0060;                              //sub di, 0x60
    _al = _dl;                                  //mov al, dl
    _ah = 0x00;                                 //mov ah, 0x0
    _di += _ax;                                 //add di, ax
    _si = _pop();                               //pop si
    _bl = _dh;                                  //mov bl, dh
    _bh = 0x00;                                 //mov bh, 0x0
    _bl &= 0x06;                                //and bl, 0x6
    _ax = 0x9661;                               //mov ax, 0x9661
    _bx += _ax;                                 //add bx, ax
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    _ax = memory16(_ds, _bx);                   //mov ax, word ptr [bx]
    _ds = _ax;                                  //mov ds, ax
    _cx = 0x0015;                               //mov cx, 0x15
loc_0925:                                       //loc_0925:
    _lodsw<MemData, DirForward>();              //lodsw
    _bh = memory(_es, _di);                     //mov bh, byte ptr es:[di]
    _bl = memory(_es, _di + 24);                //mov bl, byte ptr es:[di+0x18]
    _bx &= _ax;                                 //and bx, ax
    _bx = _bx | memory16(_ds, _si);             //or bx, word ptr [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory(_es, _di) = _bh;                     //mov byte ptr es:[di], bh
    memory(_es, _di + 24) = _bl;                //mov byte ptr es:[di+0x18], bl
    _bh = memory(_es, _di + 2048);              //mov bh, byte ptr es:[di+0x800]
    _bl = memory(_es, _di + 2072);              //mov bl, byte ptr es:[di+0x818]
    _bx &= _ax;                                 //and bx, ax
    _bx = _bx | memory16(_ds, _si);             //or bx, word ptr [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory(_es, _di + 2048) = _bh;              //mov byte ptr es:[di+0x800], bh
    memory(_es, _di + 2072) = _bl;              //mov byte ptr es:[di+0x818], bl
    _bh = memory(_es, _di + 4096);              //mov bh, byte ptr es:[di+0x1000]
    _bl = memory(_es, _di + 4120);              //mov bl, byte ptr es:[di+0x1018]
    _bx &= _ax;                                 //and bx, ax
    _bx = _bx | memory16(_ds, _si);             //or bx, word ptr [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory(_es, _di + 4096) = _bh;              //mov byte ptr es:[di+0x1000], bh
    memory(_es, _di + 4120) = _bl;              //mov byte ptr es:[di+0x1018], bl
    _bh = memory(_es, _di + 6144);              //mov bh, byte ptr es:[di+0x1800]
    _bl = memory(_es, _di + 6168);              //mov bl, byte ptr es:[di+0x1818]
    _bx &= _ax;                                 //and bx, ax
    _bx = _bx | memory16(_ds, _si);             //or bx, word ptr [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory(_es, _di + 6144) = _bh;              //mov byte ptr es:[di+0x1800], bh
    memory(_es, _di + 6168) = _bl;              //mov byte ptr es:[di+0x1818], bl
    _lodsw<MemData, DirForward>();              //lodsw
    _bh = memory(_es, _di + 48);                //mov bh, byte ptr es:[di+0x30]
    _bl = memory(_es, _di + 72);                //mov bl, byte ptr es:[di+0x48]
    _bx &= _ax;                                 //and bx, ax
    _bx = _bx | memory16(_ds, _si);             //or bx, word ptr [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory(_es, _di + 48) = _bh;                //mov byte ptr es:[di+0x30], bh
    memory(_es, _di + 72) = _bl;                //mov byte ptr es:[di+0x48], bl
    _bh = memory(_es, _di + 2096);              //mov bh, byte ptr es:[di+0x830]
    _bl = memory(_es, _di + 2120);              //mov bl, byte ptr es:[di+0x848]
    _bx &= _ax;                                 //and bx, ax
    _bx = _bx | memory16(_ds, _si);             //or bx, word ptr [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory(_es, _di + 2096) = _bh;              //mov byte ptr es:[di+0x830], bh
    memory(_es, _di + 2120) = _bl;              //mov byte ptr es:[di+0x848], bl
    _bh = memory(_es, _di + 4144);              //mov bh, byte ptr es:[di+0x1030]
    _bl = memory(_es, _di + 4168);              //mov bl, byte ptr es:[di+0x1048]
    _bx &= _ax;                                 //and bx, ax
    _bx = _bx | memory16(_ds, _si);             //or bx, word ptr [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory(_es, _di + 4144) = _bh;              //mov byte ptr es:[di+0x1030], bh
    memory(_es, _di + 4168) = _bl;              //mov byte ptr es:[di+0x1048], bl
    _bh = memory(_es, _di + 6192);              //mov bh, byte ptr es:[di+0x1830]
    _bl = memory(_es, _di + 6216);              //mov bl, byte ptr es:[di+0x1848]
    _bx &= _ax;                                 //and bx, ax
    _bx = _bx | memory16(_ds, _si);             //or bx, word ptr [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory(_es, _di + 6192) = _bh;              //mov byte ptr es:[di+0x1830], bh
    memory(_es, _di + 6216) = _bl;              //mov byte ptr es:[di+0x1848], bl
    _di += 1;                                   //inc di
    _cx -= 1;                                   //dec cx
    if (_cx == 0)                               //jz loc_09f7
        goto loc_09f7;
    goto loc_0925;                              //jmp loc_0925
loc_09f7:                                       //loc_09f7:
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    return;                                     //ret
loc_09fb:                                       //loc_09fb:
    _di = memory16(_ds, 32150);                 //mov di, word ptr [0x7d96]
    sub_0b58();                                 //call sub_0b58
    _si += 0x0020;                              //add si, 0x20
    sub_0b58();                                 //call sub_0b58
    _si += 0x0020;                              //add si, 0x20
    sub_0b58();                                 //call sub_0b58
    _si += 0x0020;                              //add si, 0x20
    sub_0b58();                                 //call sub_0b58
    _si += 0xffa1;                          //add si, -0x5f
    sub_0b58();                                 //call sub_0b58
    _si += 0x0020;                              //add si, 0x20
    sub_0b58();                                 //call sub_0b58
    _si += 0x0020;                              //add si, 0x20
    sub_0b58();                                 //call sub_0b58
    _si += 0x0020;                              //add si, 0x20
    sub_0b58();                                 //call sub_0b58
    _si += 0xffa1;                          //add si, -0x5f
    sub_0b58();                                 //call sub_0b58
    _si += 0x0020;                              //add si, 0x20
    sub_0b58();                                 //call sub_0b58
    _si += 0x0020;                              //add si, 0x20
    sub_0b58();                                 //call sub_0b58
    _si += 0x0020;                              //add si, 0x20
    sub_0b58();                                 //call sub_0b58
    _si += 0xffa1;                          //add si, -0x5f
    sub_0b58();                                 //call sub_0b58
    _si += 0x0020;                              //add si, 0x20
    sub_0b58();                                 //call sub_0b58
    _si += 0x0020;                              //add si, 0x20
    sub_0b58();                                 //call sub_0b58
    _si += 0x0020;                              //add si, 0x20
    sub_0b58();                                 //call sub_0b58
    memory16(_ds, 32150) = _di;                 //mov word ptr [0x7d96], di
    _di -= 0x0080;                              //sub di, 0x80
    _al = _dl;                                  //mov al, dl
    _ah = 0x00;                                 //mov ah, 0x0
    _di += _ax;                                 //add di, ax
    _si = _pop();                               //pop si
    _bl = _dh;                                  //mov bl, dh
    _bh = 0x00;                                 //mov bh, 0x0
    _bl &= 0x06;                                //and bl, 0x6
    _ax = 0x9661;                               //mov ax, 0x9661
    _bx += _ax;                                 //add bx, ax
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    _ax = memory16(_ds, _bx);                   //mov ax, word ptr [bx]
    _ds = _ax;                                  //mov ds, ax
    _cx = 0x0015;                               //mov cx, 0x15
loc_0a82:                                       //loc_0a82:
    _lodsw<MemData, DirForward>();              //lodsw
    _bh = memory(_es, _di);                     //mov bh, byte ptr es:[di]
    _bl = memory(_es, _di + 32);                //mov bl, byte ptr es:[di+0x20]
    _bx &= _ax;                                 //and bx, ax
    _bx = _bx | memory16(_ds, _si);             //or bx, word ptr [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory(_es, _di) = _bh;                     //mov byte ptr es:[di], bh
    memory(_es, _di + 32) = _bl;                //mov byte ptr es:[di+0x20], bl
    _bh = memory(_es, _di + 2048);              //mov bh, byte ptr es:[di+0x800]
    _bl = memory(_es, _di + 2080);              //mov bl, byte ptr es:[di+0x820]
    _bx &= _ax;                                 //and bx, ax
    _bx = _bx | memory16(_ds, _si);             //or bx, word ptr [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory(_es, _di + 2048) = _bh;              //mov byte ptr es:[di+0x800], bh
    memory(_es, _di + 2080) = _bl;              //mov byte ptr es:[di+0x820], bl
    _bh = memory(_es, _di + 4096);              //mov bh, byte ptr es:[di+0x1000]
    _bl = memory(_es, _di + 4128);              //mov bl, byte ptr es:[di+0x1020]
    _bx &= _ax;                                 //and bx, ax
    _bx = _bx | memory16(_ds, _si);             //or bx, word ptr [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory(_es, _di + 4096) = _bh;              //mov byte ptr es:[di+0x1000], bh
    memory(_es, _di + 4128) = _bl;              //mov byte ptr es:[di+0x1020], bl
    _bh = memory(_es, _di + 6144);              //mov bh, byte ptr es:[di+0x1800]
    _bl = memory(_es, _di + 6176);              //mov bl, byte ptr es:[di+0x1820]
    _bx &= _ax;                                 //and bx, ax
    _bx = _bx | memory16(_ds, _si);             //or bx, word ptr [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory(_es, _di + 6144) = _bh;              //mov byte ptr es:[di+0x1800], bh
    memory(_es, _di + 6176) = _bl;              //mov byte ptr es:[di+0x1820], bl
    _lodsw<MemData, DirForward>();              //lodsw
    _bh = memory(_es, _di + 64);                //mov bh, byte ptr es:[di+0x40]
    _bl = memory(_es, _di + 96);                //mov bl, byte ptr es:[di+0x60]
    _bx &= _ax;                                 //and bx, ax
    _bx = _bx | memory16(_ds, _si);             //or bx, word ptr [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory(_es, _di + 64) = _bh;                //mov byte ptr es:[di+0x40], bh
    memory(_es, _di + 96) = _bl;                //mov byte ptr es:[di+0x60], bl
    _bh = memory(_es, _di + 2112);              //mov bh, byte ptr es:[di+0x840]
    _bl = memory(_es, _di + 2144);              //mov bl, byte ptr es:[di+0x860]
    _bx &= _ax;                                 //and bx, ax
    _bx = _bx | memory16(_ds, _si);             //or bx, word ptr [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory(_es, _di + 2112) = _bh;              //mov byte ptr es:[di+0x840], bh
    memory(_es, _di + 2144) = _bl;              //mov byte ptr es:[di+0x860], bl
    _bh = memory(_es, _di + 4160);              //mov bh, byte ptr es:[di+0x1040]
    _bl = memory(_es, _di + 4192);              //mov bl, byte ptr es:[di+0x1060]
    _bx &= _ax;                                 //and bx, ax
    _bx = _bx | memory16(_ds, _si);             //or bx, word ptr [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory(_es, _di + 4160) = _bh;              //mov byte ptr es:[di+0x1040], bh
    memory(_es, _di + 4192) = _bl;              //mov byte ptr es:[di+0x1060], bl
    _bh = memory(_es, _di + 6208);              //mov bh, byte ptr es:[di+0x1840]
    _bl = memory(_es, _di + 6240);              //mov bl, byte ptr es:[di+0x1860]
    _bx &= _ax;                                 //and bx, ax
    _bx = _bx | memory16(_ds, _si);             //or bx, word ptr [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory(_es, _di + 6208) = _bh;              //mov byte ptr es:[di+0x1840], bh
    memory(_es, _di + 6240) = _bl;              //mov byte ptr es:[di+0x1860], bl
    _di += 1;                                   //inc di
    _cx -= 1;                                   //dec cx
    if (_cx == 0)                               //jz loc_0b54
        goto loc_0b54;
    goto loc_0a82;                              //jmp loc_0a82
loc_0b54:                                       //loc_0b54:
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
}

void sub_0b58()
{
    _bx = 0x0000;                               //mov bx, 0x0
    _bl = memory(_ds, _si);                     //mov bl, byte ptr [si]
    _ah = 0;                                    //sub ah, ah
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    _flags.zero = !(_al & 0x08);
    _al = _bl;                                  //mov al, bl
    if (_flags.zero)                          //jz loc_0b75 // check if block in front // TODO: PARSER PROBLEM, TEST AL, MOV AL, JZ !!!
        goto loc_0b75;
    _ax = memory16(_ds, 0x7e3c);                //mov ax, [0x7e3c]
    _ax += 1;                                   //inc ax
    memory16(_ds, 0x7e3c) = _ax;                //mov [0x7e3c], ax
    _di += 0x0008;                              //add di, 0x8
    return;                                     //ret
loc_0b75:                                       //loc_0b75:
    _push(_si);                                 //push si
    _si -= 0x778e;                              //sub si, 0x778e
    _si += 0x720e;                              //add si, 0x720e
    _cx = memory16(_ds, 32094);                 //mov cx, word ptr [0x7d5e]
    _bl = memory(_ds, _si);                     //mov bl, byte ptr [si]
    if (_bl < 0x02)                             //jc loc_0b91
        goto loc_0b91;
    _al = _bl;                                  //mov al, bl
    _cx = 0x022a;                               //mov cx, 0x22a
loc_0b91:                                       //loc_0b91:
    _bx = memory16(_ds, 32316);                 //mov bx, word ptr [0x7e3c]
    memory(_ds, _si) = _bl;                     //mov byte ptr [si], bl
    _bx += 1;                                   //inc bx
    memory16(_ds, 32316) = _bx;                 //mov word ptr [0x7e3c], bx
    _ax += _ax;                                 //add ax, ax
    _ax += _ax;                                 //add ax, ax
    _ax += _ax;                                 //add ax, ax
    _ax += _cx;                                 //add ax, cx
    _si = _ax;                                  //mov si, ax
    _ax = memory16(_ds, _si + 6144);            //mov ax, word ptr [si+0x1800]
    memory16(_es, _di + 0x1800) = _ax;          //mov word ptr es:[di+0x1800], ax
    _ax = memory16(_ds, _si + 4096);            //mov ax, word ptr [si+0x1000]
    memory16(_es, _di + 0x1000) = _ax;          //mov word ptr es:[di+0x1000], ax
    _ax = memory16(_ds, _si + 2048);            //mov ax, word ptr [si+0x800]
    memory16(_es, _di + 0x800) = _ax;           //mov word ptr es:[di+0x800], ax
    _movsw<MemData, MemData, DirForward>();     //movsw
    _ax = memory16(_ds, _si + 6144);            //mov ax, word ptr [si+0x1800]
    memory16(_es, _di + 0x1800) = _ax;          //mov word ptr es:[di+0x1800], ax
    _ax = memory16(_ds, _si + 4096);            //mov ax, word ptr [si+0x1000]
    memory16(_es, _di + 0x1000) = _ax;          //mov word ptr es:[di+0x1000], ax
    _ax = memory16(_ds, _si + 2048);            //mov ax, word ptr [si+0x800]
    memory16(_es, _di + 0x800) = _ax;           //mov word ptr es:[di+0x800], ax
    _movsw<MemData, MemData, DirForward>();     //movsw
    _ax = memory16(_ds, _si + 6144);            //mov ax, word ptr [si+0x1800]
    memory16(_es, _di + 0x1800) = _ax;          //mov word ptr es:[di+0x1800], ax
    _ax = memory16(_ds, _si + 4096);            //mov ax, word ptr [si+0x1000]
    memory16(_es, _di + 0x1000) = _ax;          //mov word ptr es:[di+0x1000], ax
    _ax = memory16(_ds, _si + 2048);            //mov ax, word ptr [si+0x800]
    memory16(_es, _di + 0x800) = _ax;           //mov word ptr es:[di+0x800], ax
    _movsw<MemData, MemData, DirForward>();     //movsw
    _ax = memory16(_ds, _si + 6144);            //mov ax, word ptr [si+0x1800]
    memory16(_es, _di + 0x1800) = _ax;          //mov word ptr es:[di+0x1800], ax
    _ax = memory16(_ds, _si + 4096);            //mov ax, word ptr [si+0x1000]
    memory16(_es, _di + 0x1000) = _ax;          //mov word ptr es:[di+0x1000], ax
    _ax = memory16(_ds, _si + 2048);            //mov ax, word ptr [si+0x800]
    memory16(_es, _di + 0x800) = _ax;           //mov word ptr es:[di+0x800], ax
    _movsw<MemData, MemData, DirForward>();     //movsw
    _si = _pop();                               //pop si
}
extern int check;
void sub_0c18()
{
    int y = 0, x = 0;
    _ax = 0x1040;                               //mov ax, 0x1040
    _es = _ax;                                  //mov es, ax
    _ds = _ax;                                  //mov ds, ax
    sub_0ead();                                 //call sub_0ead
    _ax = 0xa000;                               //mov ax, 0xa000
    _es = _ax;                                  //mov es, ax
    _si = 0x730e;                               //mov si, 0x730e
    _di = 0x0004;                               //mov di, 0x4
    _bx = 0x0018;                               //mov bx, 0x18
loc_0c30:                                       //loc_0c30:
    _cx = 0x0020;                               //mov cx, 0x20
    _ax = 0;                                    //sub ax, ax
loc_0c35:                                       //loc_0c35:
//    memory(_ds, _si) &= ~1;
    check = 0;
    _al = _al | memory(_ds, _si);               //or al, byte ptr [si]
    check = 1;
    if (_al != 0)                               //jnz loc_0c48
        goto loc_0c48;
loc_0c3c://loc_0c3c:
    x++;
    _di += 1;                                   //inc di
    _si += 1;                                   //inc si
    if (--_cx)                                  //loop loc_0c35
        goto loc_0c35;
    y++; x = 0;
    _di += 0x0120;                              //add di, 0x120
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz loc_0c30
        goto loc_0c30;
    std::cout << "\n";
    return;                                     //ret
loc_0c48:                                       //loc_0c48:
    _push(_bx);                                 //push bx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    if (_ax != 0x0001)                          //jnz loc_0c94
        goto loc_0c94;
    memory(_ds, _si) = 0x00;                    //mov byte ptr [si], 0x0
    _si -= 0x730e;                              //sub si, 0x730e
    _si += 0x788e;                              //add si, 0x788e
    _ah = 0x00;                                 //mov ah, 0x0
    _al = memory(_ds, _si);                     //mov al, byte ptr [si]
    _bx = memory16(_ds, 38682);                 //mov bx, word ptr [0x971a]
loc_0c67:                                       //loc_0c67:
    _push(_es);                                 //push es
    _ds = _pop();                               //pop ds
    _ax += _ax;                                 //add ax, ax
    _ax += _ax;                                 //add ax, ax
    _ax += _ax;                                 //add ax, ax
    _ax += _bx;                                 //add ax, bx
    _si = _ax;                                  //mov si, ax
    _bx = 0x0027;                               //mov bx, 0x27
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bx;                                 //add di, bx
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bx;                                 //add di, bx
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bx;                                 //add di, bx
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bx;                                 //add di, bx
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bx;                                 //add di, bx
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bx;                                 //add di, bx
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bx;                                 //add di, bx
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _bx = _pop();                               //pop bx
    _ax = 0;                                    //sub ax, ax
    goto loc_0c3c;                              //jmp loc_0c3c
loc_0c94:                                       //loc_0c94:
    memory(_ds, _si) = 0x01;                    //mov byte ptr [si], 0x1
    _bx = 0x3ff0;                               //mov bx, 0x3ff0
    goto loc_0c67;                              //jmp loc_0c67
}

void sub_0c9c()
{
    _ax = 0x1040;                               //mov ax, 0x1040
    _es = _ax;                                  //mov es, ax
    _ds = _ax;                                  //mov ds, ax
    sub_0ead();                                 //call sub_0ead
    _ax = 0xa000;                               //mov ax, 0xa000
    _es = _ax;                                  //mov es, ax
    _si = 0x730e;                               //mov si, 0x730e
    _di = 0x0004;                               //mov di, 0x4
    _bx = 0x0018;                               //mov bx, 0x18
loc_0cb4:                                       //loc_0cb4:
    _cx = 0x0020;                               //mov cx, 0x20
    _ax = 0;                                    //sub ax, ax
loc_0cb9:                                       //loc_0cb9:
    _al = _al | memory(_ds, _si);               //or al, byte ptr [si]
    if (_al != 0)                               //jnz loc_0ccc
        goto loc_0ccc;
loc_0cc0:                                       //loc_0cc0:
    _di += 1;                                   //inc di
    _si += 1;                                   //inc si
    if (--_cx)                                  //loop loc_0cb9
        goto loc_0cb9;
    _di += 0x0120;                              //add di, 0x120
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz loc_0cb4
        goto loc_0cb4;
    return;                                     //ret
loc_0ccc:                                       //loc_0ccc:
    _push(_bx);                                 //push bx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    if (_ax != 0x0001)                          //jnz loc_0d18
        goto loc_0d18;
    memory(_ds, _si) = 0x00;                    //mov byte ptr [si], 0x0
    _si -= 0x730e;                              //sub si, 0x730e
    _si += 0x788e;                              //add si, 0x788e
    _ah = 0x00;                                 //mov ah, 0x0
    _al = memory(_ds, _si);                     //mov al, byte ptr [si]
    _bx = memory16(_ds, 38682);                 //mov bx, word ptr [0x971a]
loc_0ceb:                                       //loc_0ceb:
    _push(_es);                                 //push es
    _ds = _pop();                               //pop ds
    _ax += _ax;                                 //add ax, ax
    _ax += _ax;                                 //add ax, ax
    _ax += _ax;                                 //add ax, ax
    _ax += _bx;                                 //add ax, bx
    _si = _ax;                                  //mov si, ax
    _bx = 0x0027;                               //mov bx, 0x27
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bx;                                 //add di, bx
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bx;                                 //add di, bx
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bx;                                 //add di, bx
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bx;                                 //add di, bx
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bx;                                 //add di, bx
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bx;                                 //add di, bx
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bx;                                 //add di, bx
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _bx = _pop();                               //pop bx
    _ax = 0;                                    //sub ax, ax
    goto loc_0cc0;                              //jmp loc_0cc0
loc_0d18:                                       //loc_0d18:
    _bx = 0x3ff0;                               //mov bx, 0x3ff0
    goto loc_0ceb;                              //jmp loc_0ceb
}

void sub_0d1d() // -- mark all for redraw
{
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _si = 0x730e;                               //mov si, 0x730e
    _cx = 0x0300;                               //mov cx, 0x300
loc_0d28:                                       //loc_0d28:
    memory(_ds, _si) = 0x01;                    //mov byte ptr [si], 0x1
    _si += 1;                                   //inc si
    if (--_cx)                                  //loop loc_0d28
        goto loc_0d28;
}

void sub_0d2f()
{
    _al = memory(_ds, 0x7d68);                  //mov al, [0x7d68]
    memory(_ds, 0x7d88) = _al;                  //mov [0x7d88], al
    _ax = memory16(_ds, 0x7e82);                //mov ax, [0x7e82]
    memory16(_ds, 0x7d8a) = _ax;                //mov [0x7d8a], ax
    _al = memory(_ds, 0x7e80);                  //mov al, [0x7e80]
    memory(_ds, 0x7d89) = _al;                  //mov [0x7d89], al
    _al = memory(_ds, 0x7e8a);                  //mov al, [0x7e8a]
    memory(_ds, 0x7d8c) = _al;                  //mov [0x7d8c], al
    _al = memory(_ds, 0x7e38);                  //mov al, [0x7e38]
    _ah = 0;                                    //sub ah, ah
    memory(_ds, 0x7d8d) = _al;                  //mov [0x7d8d], al
}

void sub_0d50()
{
    _al = memory(_ds, 0x7d88);                  //mov al, [0x7d88]
    memory(_ds, 0x7d68) = _al;                  //mov [0x7d68], al
    _al = memory(_ds, 0x7d89);                  //mov al, [0x7d89]
    memory(_ds, 0x7e80) = _al;                  //mov [0x7e80], al
    _ax = memory16(_ds, 0x7d8a);                //mov ax, [0x7d8a]
    memory16(_ds, 0x7e82) = _ax;                //mov [0x7e82], ax
    _al = memory(_ds, 0x7d8c);                  //mov al, [0x7d8c]
    memory(_ds, 0x7e8a) = _al;                  //mov [0x7e8a], al
    _bl = memory(_ds, 32141);                   //mov bl, byte ptr [0x7d8d]
    memory(_ds, 32312) = _bl;                   //mov byte ptr [0x7e38], bl
    memory(_ds, 32133) = 0x00;                  //mov byte ptr [0x7d85], 0x0
    _di = memory16(_ds, 32096);                 //mov di, word ptr [0x7d60]
    {sub_0e37(); return; };                     //
}

void sub_0d7c()
{
    memory(_ds, 32118) = 0x00;                  //mov byte ptr [0x7d76], 0x0
    memory(_ds, 32143) = 0x00;                  //mov byte ptr [0x7d8f], 0x0
    _si = memory16(_ds, 32098);                 //mov si, word ptr [0x7d62]
    _ax = memory16(_ds, 0x7e82);                //mov ax, [0x7e82]
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _al = _al + memory(_ds, 32312);             //add al, byte ptr [0x7e38]
    _cl = _al;                                  //mov cl, al
    _bl = memory(_ds, 32119);                   //mov bl, byte ptr [0x7d77]
loc_0d9d:                                       //loc_0d9d:
    if (_bl == memory(_ds, _si))                //jz loc_0da4
        goto loc_0da4;
    goto loc_0e31;                              //jmp loc_0e31
loc_0da4:                                       //loc_0da4:
    _al = _cl;                                  //mov al, cl
    _al = _al - memory(_ds, _si + 1);           //sub al, byte ptr [si+0x1]
    if (_al < 0x03)                             //jc loc_0db0
        goto loc_0db0;
    goto loc_0e31;                              //jmp loc_0e31
loc_0db0:                                       //loc_0db0:
    _al = memory(_ds, _si + 1);                 //mov al, byte ptr [si+0x1]
    _al = _al - memory(_ds, _si + 4);           //sub al, byte ptr [si+0x4]
    _bl = memory(_ds, 32312);                   //mov bl, byte ptr [0x7e38]
    _bl -= _al;                                 //sub bl, al
    _bh = 0;                                    //sub bh, bh
    _di = memory16(_ds, _si + 2);               //mov di, word ptr [si+0x2]
    if (_di != 0x00ff)                          //jnz sub_0e37
        { sub_0e37(); return; }
    memory(_ds, 32325) = 0x06;                  //mov byte ptr [0x7e45], 0x6
    memory(_ds, 32327) = 0x06;                  //mov byte ptr [0x7e47], 0x6
    _al = memory(_ds, 0x7d90);                  //mov al, [0x7d90]
    _al += 1;                                   //inc al
    memory(_ds, 0x7d90) = _al;                  //mov [0x7d90], al
    if (_al != 0x04)                            //jnz loc_0df1
        goto loc_0df1;
    _al = memory(_ds, 0x7e46);                  //mov al, [0x7e46]
    _al += 1;                                   //inc al
    memory(_ds, 0x4916) = _al;                  //mov [0x4916], al
    _si = 0x4916;                               //mov si, 0x4916
    sub_0292();                                 //call sub_0292
loc_0df1:                                       //loc_0df1:
    _push(_ds);                                 //push ds
    sub_1ac6();                                 //call sub_1ac6
    _ds = _pop();                               //pop ds
    _al = memory(_ds, 0x7d90);                  //mov al, [0x7d90]
    if (_al < 0x04)                             //jc loc_0e06
        goto loc_0e06;
    memory(_ds, 32145) = 0xff;                  //mov byte ptr [0x7d91], 0xff
    return;                                     //ret
loc_0e06:                                       //loc_0e06:
    _bl = memory(_ds, 32144);                   //mov bl, byte ptr [0x7d90]
    _bh = 0;                                    //sub bh, bh
    _bx += _bx;                                 //add bx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += 0x80ef;                              //add bx, 0x80ef
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    memory(_ds, 0x7e80) = _al;                  //mov [0x7e80], al
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _ax = memory16(_ds, _bx);                   //mov ax, word ptr [bx]
    memory16(_ds, 0x7e82) = _ax;                //mov [0x7e82], ax
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _di = memory16(_ds, _bx);                   //mov di, word ptr [bx]
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _bx = memory16(_ds, _bx);                   //mov bx, word ptr [bx]
    sub_0e37();                                 //call sub_0e37
    sub_0309();                                 //call sub_0309
    return;                                     //ret
loc_0e31:                                       //loc_0e31:
    _si += 0x0006;                              //add si, 0x6
    goto loc_0d9d;                              //jmp loc_0d9d
}

void sub_0e37()
{
    memory16(_ds, 32096) = _di;                 //mov word ptr [0x7d60], di
    memory(_ds, 32118) = 0x00;                  //mov byte ptr [0x7d76], 0x0
    _si = 0x7d0e;                               //mov si, 0x7d0e
    _cx = 0x9810;                               //mov cx, 0x9810
    _dx = 0x3000;                               //mov dx, 0x3000
    _ax = memory16(_ds, _di);                   //mov ax, word ptr [di]
    _ax &= _ax;                                 //and ax, ax
    if (_ax == 0)                               //jz loc_0e5b
        goto loc_0e5b;
    _si = 0x7d1e;                               //mov si, 0x7d1e
    _cx = 0xd810;                               //mov cx, 0xd810
    _dx = 0x3800;                               //mov dx, 0x3800
loc_0e5b:                                       //loc_0e5b:
    memory16(_ds, 32094) = _cx;                 //mov word ptr [0x7d5e], cx
    memory16(_ds, 38682) = _dx;                 //mov word ptr [0x971a], dx
    _ax = memory16(_ds, _di + 2);               //mov ax, word ptr [di+0x2]
    memory16(_ds, 0x7e3a) = _ax;                //mov [0x7e3a], ax
    memory(_ds, 32312) = _bl;                   //mov byte ptr [0x7e38], bl
    _ax = memory16(_ds, _di + 4);               //mov ax, word ptr [di+0x4]
    memory16(_ds, 0x7d62) = _ax;                //mov [0x7d62], ax
    _ax = memory16(_ds, _di + 6);               //mov ax, word ptr [di+0x6]
    memory16(_ds, 0x7d64) = _ax;                //mov [0x7d64], ax
    sub_1295();                                 //call sub_1295
    sub_0edb();                                 //call sub_0edb
    sub_2669();                                 //call sub_2669
    _dh = memory(_ds, 32312);                   //mov dh, byte ptr [0x7e38]
    _dh += 0x08;                                //add dh, 0x8
    _dl = 0x18;                                 //mov dl, 0x18
    sub_2089();                                 //call sub_2089
    _dh = memory(_ds, 32312);                   //mov dh, byte ptr [0x7e38]
    _dl = 0x08;                                 //mov dl, 0x8
    sub_2089();                                 //call sub_2089
    _dh = memory(_ds, 32312);                   //mov dh, byte ptr [0x7e38]
    _dh += 0x20;                                //add dh, 0x20
    _dl = 0x08;                                 //mov dl, 0x8
    sub_2089();                                 //call sub_2089
    sub_0d1d();                                 //call sub_0d1d
    sub_0c9c();                                 //call sub_0c9c
    sub_0d2f();                                 //call sub_0d2f
}

void sub_0ead()
{
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _ax = 0x0000;                               //mov ax, 0x0
    _di = 0x732f;                               //mov di, 0x732f
    _stosw<MemData, DirForward>();              //stosw
    _stosw<MemData, DirForward>();              //stosw
    _stosw<MemData, DirForward>();              //stosw
    _cl = memory(_ds, 32325);                   //mov cl, byte ptr [0x7e45]
    _ch = 0;                                    //sub ch, ch
    _di = 0x7337;                               //mov di, 0x7337
    _rep_stosb<MemData, DirForward>();          //rep stosb
    _cl = memory(_ds, 32327);                   //mov cl, byte ptr [0x7e47]
    _di = 0x733f;                               //mov di, 0x733f
    _rep_stosb<MemData, DirForward>();          //rep stosb
    _cl = memory(_ds, 32326);                   //mov cl, byte ptr [0x7e46]
    _di = 0x7347;                               //mov di, 0x7347
    _rep_stosb<MemData, DirForward>();          //rep stosb
}

void sub_0edb()
{
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _di = 0x778e;                               //mov di, 0x778e
    _al = memory(_ds, 0x7e38);                  //mov al, [0x7e38]
    _ah = 0;                                    //sub ah, ah
    _ax += _ax;                                 //add ax, ax
    _ax &= 0xfff8;                              //and ax, 0xfff8
    _ax = _ax + memory16(_ds, 32314);           //add ax, word ptr [0x7e3a]
    _bx = _ax;                                  //mov bx, ax
    _dh = 0x0b;                                 //mov dh, 0xb
loc_0ef7:                                       //loc_0ef7:
    _cx = 0x0008;                               //mov cx, 0x8
loc_0efa:                                       //loc_0efa:
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    _bx += 1;                                   //inc bx
    _ah = 0x00;                                 //mov ah, 0x0
    _ax += _ax;                                 //add ax, ax
    _ax += _ax;                                 //add ax, ax
    _ax += _ax;                                 //add ax, ax
    _ax += _ax;                                 //add ax, ax
    _ax += 0x423a;                              //add ax, 0x423a
    _si = _ax;                                  //mov si, ax
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di += 0x001c;                              //add di, 0x1c
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di += 0x001c;                              //add di, 0x1c
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di += 0x001c;                              //add di, 0x1c
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di += 0xffa0;                          //add di, -0x60
    if (--_cx)                                  //loop loc_0efa
        goto loc_0efa;
    _di += 0x0060;                              //add di, 0x60
    _dh -= 1;                                   //dec dh
    if (_dh != 0)                               //jnz loc_0ef7
        goto loc_0ef7;
}

void sub_0f2a()
{
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _flags.direction = false;                   //cld
    _di = 0x788e;                               //mov di, 0x788e
    _si = 0x78ae;                               //mov si, 0x78ae
    _bx = 0x730e;                               //mov bx, 0x730e
    _dl = 0x01;                                 //mov dl, 0x1
    _cx = 0x03e0;                               //mov cx, 0x3e0
loc_0f40:                                       //loc_0f40:
    _bx += 1;                                   //inc bx
    _cmpsb<MemData, MemData, DirForward>();     //cmpsb
    if (!_flags.zero)                               //jnz loc_0f4b
        goto loc_0f4b;
loc_0f47:                                       //loc_0f47:
    _cx -= 1;                                   //dec cx
    if (_cx != 0)                               //jnz loc_0f40
        goto loc_0f40;
    return;                                     //ret
loc_0f4b:                                       //loc_0f4b:
    _si -= 1;                                   //dec si
    _di -= 1;                                   //dec di
    _movsb<MemData, MemData, DirForward>();     //movsb
    _bx -= 1;                                   //dec bx
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    if (_al >= 0x02)                            //jnc loc_0f5b
        goto loc_0f5b;
    memory(_ds, _bx) = 0x01;                    //mov byte ptr [bx], 0x1
loc_0f5b:                                       //loc_0f5b:
    _bx += 1;                                   //inc bx
    goto loc_0f47;                              //jmp loc_0f47
}

void sub_0f5e()
{
    _si = 0x730e;                               //mov si, 0x730e
    _cx = 0x0400;                               //mov cx, 0x400
    _al = 0x01;                                 //mov al, 0x1
loc_0f66:                                       //loc_0f66:
    if (_al < memory(_ds, _si))                 //jc loc_0f71
        goto loc_0f71;
loc_0f6d:                                       //loc_0f6d:
    _si += 1;                                   //inc si
    if (--_cx)                                  //loop loc_0f66
        goto loc_0f66;
    return;                                     //ret
loc_0f71:                                       //loc_0f71:
    _al = memory(_ds, _si);                     //mov al, byte ptr [si]
    _si -= 0x0020;                              //sub si, 0x20
    memory(_ds, _si) = _al;                     //mov byte ptr [si], al
    _si += 0x0020;                              //add si, 0x20
    _al = 0x01;                                 //mov al, 0x1
    memory(_ds, _si) = _al;                     //mov byte ptr [si], al
    goto loc_0f6d;                              //jmp loc_0f6d
}

void sub_0f81()
{
    sub_10fa();                                 //call sub_10fa
    sub_07d6();                                 //call sub_07d6
    _cx = 0x0008;                               //mov cx, 0x8
loc_0f8a:                                       //loc_0f8a:
    _push(_cx);                                 //push cx
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    sub_0f2a();                                 //call sub_0f2a
    sub_0f5e();                                 //call sub_0f5e
    _bx = 0xfff8;                               //mov bx, 0xfff8
    sub_10b2();                                 //call sub_10b2
    _cx = 0x0001;                               //mov cx, 0x1
loc_0fa1:                                       //loc_0fa1:
    _push(_cx);                                 //push cx
    sub_07bb();                                 //call sub_07bb
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_0fa1
        goto loc_0fa1;
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _flags.direction = false;                   //cld
    _si = 0x732e;                               //mov si, 0x732e
    _di = 0x7d2e;                               //mov di, 0x7d2e
    _cx = 0x0010;                               //mov cx, 0x10
    _rep_movsw<MemData, MemData, DirForward>(); //rep movsw
    sub_0c9c();                                 //call sub_0c9c
    sub_2b32();                                 //call sub_2b32
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _flags.direction = false;                   //cld
    _si = 0x7d2e;                               //mov si, 0x7d2e
    _di = 0x732e;                               //mov di, 0x732e
    _cx = 0x0010;                               //mov cx, 0x10
    _rep_movsw<MemData, MemData, DirForward>(); //rep movsw
    _ax = memory16(_ds, 0x7e38);                //mov ax, [0x7e38]
    _ax += 1;                                   //inc ax
    memory16(_ds, 0x7e38) = _ax;                //mov [0x7e38], ax
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_0f8a
        goto loc_0f8a;
    _dh = _al;                                  //mov dh, al
    _dh += 0x20;                                //add dh, 0x20
    _dl = 0x08;                                 //mov dl, 0x8
    sub_2089();                                 //call sub_2089
    sub_0edb();                                 //call sub_0edb
    sub_0c18();                                 //call sub_0c18
}

void sub_0fef()
{
    sub_10fa();                                 //call sub_10fa
    sub_07d6();                                 //call sub_07d6
    _cx = 0x0008;                               //mov cx, 0x8
loc_0ff8:                                       //loc_0ff8:
    _push(_cx);                                 //push cx
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    sub_108f();                                 //call sub_108f
    sub_105a();                                 //call sub_105a
    _bx = 0x0008;                               //mov bx, 0x8
    sub_10b2();                                 //call sub_10b2
    _cx = 0x0001;                               //mov cx, 0x1
loc_100f:                                       //loc_100f:
    _push(_cx);                                 //push cx
    sub_07bb();                                 //call sub_07bb
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_100f
        goto loc_100f;
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _flags.direction = false;                   //cld
    _si = 0x732e;                               //mov si, 0x732e
    _di = 0x7d2e;                               //mov di, 0x7d2e
    _cx = 0x0010;                               //mov cx, 0x10
    _rep_movsw<MemData, MemData, DirForward>(); //rep movsw
    sub_0c9c();                                 //call sub_0c9c
    sub_2b32();                                 //call sub_2b32
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _flags.direction = false;                   //cld
    _si = 0x7d2e;                               //mov si, 0x7d2e
    _di = 0x732e;                               //mov di, 0x732e
    _cx = 0x0010;                               //mov cx, 0x10
    _rep_movsw<MemData, MemData, DirForward>(); //rep movsw
    _ax = memory16(_ds, 0x7e38);                //mov ax, [0x7e38]
    _ax -= 1;                                   //dec ax
    memory16(_ds, 0x7e38) = _ax;                //mov [0x7e38], ax
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_0ff8
        goto loc_0ff8;
    _dh = _al;                                  //mov dh, al
    _dl = 0x08;                                 //mov dl, 0x8
    sub_2089();                                 //call sub_2089
    sub_0edb();                                 //call sub_0edb
    sub_0c18();                                 //call sub_0c18
}

void sub_105a()
{
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _flags.direction = true;                    //std
    _di = 0x7b8e;                               //mov di, 0x7b8e
    _si = 0x7b6e;                               //mov si, 0x7b6e
    _bx = 0x760e;                               //mov bx, 0x760e
    _dl = 0x01;                                 //mov dl, 0x1
    _cx = 0x0400;                               //mov cx, 0x400
loc_1070:                                       //loc_1070:
    _bx -= 1;                                   //dec bx
    _cmpsb<MemData, MemData, DirBackward>();     //cmpsb
    if (_bx != 0)                               //jnz loc_107c
        goto loc_107c;
loc_1077:                                       //loc_1077:
    _cx -= 1;                                   //dec cx
    if (_cx != 0)                               //jnz loc_1070
        goto loc_1070;
    _flags.direction = false;                   //cld
    return;                                     //ret
loc_107c:                                       //loc_107c:
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    _movsb<MemData, MemData, DirBackward>();     //movsb
    _bx += 1;                                   //inc bx
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    if (_al >= 0x02)                            //jnc loc_108c
        goto loc_108c;
    memory(_ds, _bx) = 0x01;                    //mov byte ptr [bx], 0x1
loc_108c:                                       //loc_108c:
    _bx -= 1;                                   //dec bx
    goto loc_1077;                              //jmp loc_1077
}

void sub_108f()
{
    _si = 0x760e;                               //mov si, 0x760e
    _cx = 0x0420;                               //mov cx, 0x420
    _al = 0x01;                                 //mov al, 0x1
loc_1097:                                       //loc_1097:
    if (_al < memory(_ds, _si))                 //jc loc_10a2
        goto loc_10a2;
loc_109e:                                       //loc_109e:
    _si -= 1;                                   //dec si
    if (--_cx)                                  //loop loc_1097
        goto loc_1097;
    return;                                     //ret
loc_10a2:                                       //loc_10a2:
    _al = memory(_ds, _si);                     //mov al, byte ptr [si]
    _si += 0x0020;                              //add si, 0x20
    memory(_ds, _si) = _al;                     //mov byte ptr [si], al
    _si -= 0x0020;                              //sub si, 0x20
    _al = 0x01;                                 //mov al, 0x1
    memory(_ds, _si) = _al;                     //mov byte ptr [si], al
    goto loc_109e;                              //jmp loc_109e
}

void sub_10b2()
{
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _si = 0x7e4e;                               //mov si, 0x7e4e
loc_10ba:                                       //loc_10ba:
    if (memory(_ds, _si) == 0x00)               //jz loc_10f4
        goto loc_10f4;
    if (memory(_ds, _si) == 0xff)               //jz loc_10f9
        goto loc_10f9;
    memory16(_ds, _si + 30) += _bx;             //add word ptr [si+0x1e], bx
    memory16(_ds, _si + 24) += _bx;             //add word ptr [si+0x18], bx
    _ax = memory16(_ds, _si + 4);               //mov ax, word ptr [si+0x4]
    _ax += _bx;                                 //add ax, bx
    if (!(_ah & 0x80))                          //jz loc_10e3
        goto loc_10e3;
    memory(_ds, _si) = 0x00;                    //mov byte ptr [si], 0x0
    goto loc_10f4;                              //jmp loc_10f4
    _STOP_("db 90h");                           //db 90h
loc_10e3:                                       //loc_10e3:
    if (_ax < 0x0140)                           //jc loc_10f1
        goto loc_10f1;
    memory(_ds, _si) = 0x00;                    //mov byte ptr [si], 0x0
    goto loc_10f4;                              //jmp loc_10f4
    _STOP_("db 90h");                           //db 90h
loc_10f1:                                       //loc_10f1:
    memory16(_ds, _si + 4) = _ax;               //mov word ptr [si+0x4], ax
loc_10f4:                                       //loc_10f4:
    _si += 0x0030;                              //add si, 0x30
    goto loc_10ba;                              //jmp loc_10ba
loc_10f9:                                       //loc_10f9:
    return;
}

void sub_10fa()
{
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _ax = 0x0000;                               //mov ax, 0x0
    _di = 0x720e;                               //mov di, 0x720e
    _cx = 0x0080;                               //mov cx, 0x80
    _rep_stosw<MemData, DirForward>();          //rep stosw
    _di = 0x760e;                               //mov di, 0x760e
    _cx = 0x0080;                               //mov cx, 0x80
    _rep_stosw<MemData, DirForward>();          //rep stosw
}

void sub_1115()
{
    _dx &= 0x00f8;                              //and dx, 0xf8
    _dx += _dx;                                 //add dx, dx
    _dx += _dx;                                 //add dx, dx
    _al = _bl;                                  //mov al, bl
    _bl >>= 1;                                  //shr bl, 1
    _bl >>= 1;                                  //shr bl, 1
    _bl >>= 1;                                  //shr bl, 1
    _bh = 0;                                    //sub bh, bh
    _dx += _bx;                                 //add dx, bx
    _bx = 0x778e;                               //mov bx, 0x778e
    _bx += _dx;                                 //add bx, dx
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    _bx = 0x0000;                               //mov bx, 0x0
    _bl = _al;                                  //mov bl, al
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    _al &= 0x40;                                //and al, 0x40
    _flags.zero = _al == 0;
}

void sub_113a()
{
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_bx);                                 //push bx
    _push(_dx);                                 //push dx
    memory(_ds, 32116) = 0x00;                  //mov byte ptr [0x7d74], 0x0
    _bl += 0x04;                                //add bl, 0x4
    _cx = 0x0001;                               //mov cx, 0x1
    if (!(_dl & 0x04))                          //jz loc_1152
        goto loc_1152;
    _cx += 1;                                   //inc cx
loc_1152:                                       //loc_1152:
    _dx &= 0x01f8;                              //and dx, 0x1f8
    _dx += _dx;                                 //add dx, dx
    _dx += _dx;                                 //add dx, dx
    _al = _bl;                                  //mov al, bl
    _bl >>= 1;                                  //shr bl, 1
    _bl >>= 1;                                  //shr bl, 1
    _bl >>= 1;                                  //shr bl, 1
    _bh = 0;                                    //sub bh, bh
    _dx += _bx;                                 //add dx, bx
    _bx = 0x778e;                               //mov bx, 0x778e
    _dx += _bx;                                 //add dx, bx
    _di = _dx;                                  //mov di, dx
    _bx = 0x0000;                               //mov bx, 0x0
    _dl = 0;                                    //sub dl, dl
    _al &= 0x07;                                //and al, 0x7
    if (_al == 0)                               //jz loc_119f
        goto loc_119f;
    _bl = memory(_ds, _di);                     //mov bl, byte ptr [di]
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    _al &= 0xf0;                                //and al, 0xf0
    _dl |= _al;                                 //or dl, al
    _di += 1;                                   //inc di
    _bl = memory(_ds, _di);                     //mov bl, byte ptr [di]
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    _al &= 0xf0;                                //and al, 0xf0
    _dl |= _al;                                 //or dl, al
    _di += 1;                                   //inc di
    _bl = memory(_ds, _di);                     //mov bl, byte ptr [di]
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    _al &= 0xf0;                                //and al, 0xf0
    _dl |= _al;                                 //or dl, al
    _di += 0x001e;                              //add di, 0x1e
    memory(_ds, 32116) = _dl;                   //mov byte ptr [0x7d74], dl
    _dl = 0;                                    //sub dl, dl
    sub_11bc(0x11fc);
    return;
    //_STOP_("goto loc_11fc");                    //jmp loc_11fc
    _STOP_("db 90h");                           //db 90h
loc_119f:                                       //loc_119f:
    _bl = memory(_ds, _di);                     //mov bl, byte ptr [di]
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    _al &= 0xf0;                                //and al, 0xf0
    _dl |= _al;                                 //or dl, al
    _di += 1;                                   //inc di
    _bl = memory(_ds, _di);                     //mov bl, byte ptr [di]
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    _al &= 0xf0;                                //and al, 0xf0
    _dl |= _al;                                 //or dl, al
    _di += 0x001f;                              //add di, 0x1f
    memory(_ds, 32116) = _dl;                   //mov byte ptr [0x7d74], dl
    _dl = 0;                                    //sub dl, dl
    sub_11bc(0x1238);
    return;
    _STOP_("goto loc_1238");                    //jmp loc_1238
    _STOP_("db 90h");                           //db 90h
    _STOP_("sp-trace-fail");                    //sub_113a endp_failed
    _STOP_("continues");                        //sub_11bc proc near
}

void sub_11bc(int pc)
{
    if (pc == 0x1238)
        goto loc_1238;
    if (pc == 0x11fc)
        goto loc_11fc;
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_bx);                                 //push bx
    _push(_dx);                                 //push dx
    memory(_ds, 32103) = 0x00;                  //mov byte ptr [0x7d67], 0x0
    _bl += 0x04;                                //add bl, 0x4
    _cx = 0x0002;                               //mov cx, 0x2
    if (!(_dx & 0x0004))                        //jz loc_11d5
        goto loc_11d5;
    _cx += 1;                                   //inc cx
loc_11d5:                                       //loc_11d5:
    _dx &= 0x01f8;                              //and dx, 0x1f8
    _dx += _dx;                                 //add dx, dx
    _dx += _dx;                                 //add dx, dx
    _al = _bl;                                  //mov al, bl
    _bl >>= 1;                                  //shr bl, 1
    _bl >>= 1;                                  //shr bl, 1
    _bl >>= 1;                                  //shr bl, 1
    _bh = 0;                                    //sub bh, bh
    _dx += _bx;                                 //add dx, bx
    _bx = 0x778e;                               //mov bx, 0x778e
    _dx += _bx;                                 //add dx, bx
    _di = _dx;                                  //mov di, dx
    _bx = 0x0000;                               //mov bx, 0x0
    _dl = 0;                                    //sub dl, dl
    _al &= 0x07;                                //and al, 0x7
    if (_al == 0)                               //jz loc_1238
        goto loc_1238;
loc_11fc:                                       //loc_11fc:
    _bl = memory(_ds, _di);                     //mov bl, byte ptr [di]
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    _al &= 0x6d;                                //and al, 0x6d
    _dl |= _al;                                 //or dl, al
    _di += 1;                                   //inc di
    _bl = memory(_ds, _di);                     //mov bl, byte ptr [di]
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    _al &= 0x6f;                                //and al, 0x6f
    _dl |= _al;                                 //or dl, al
    _di += 1;                                   //inc di
    _bl = memory(_ds, _di);                     //mov bl, byte ptr [di]
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    _al &= 0x6d;                                //and al, 0x6d
    _dl |= _al;                                 //or dl, al
    _di += 0x001e;                              //add di, 0x1e
    if (--_cx)                                  //loop loc_11fc
        goto loc_11fc;
    _bl = memory(_ds, _di);                     //mov bl, byte ptr [di]
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    _al &= 0x7d;                                //and al, 0x7d
    _dl |= _al;                                 //or dl, al
    _di += 1;                                   //inc di
    _bl = memory(_ds, _di);                     //mov bl, byte ptr [di]
    _dl = _dl | memory(_ds, _bx);               //or dl, byte ptr [bx]
    _di += 1;                                   //inc di
    _bl = memory(_ds, _di);                     //mov bl, byte ptr [di]
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    _al &= 0x7d;                                //and al, 0x7d
    _dl |= _al;                                 //or dl, al
    memory(_ds, 32103) = _dl;                   //mov byte ptr [0x7d67], dl
    goto loc_125b;                              //jmp loc_125b
    _STOP_("db 90h");                           //db 90h
loc_1238:                                       //loc_1238:
    _bl = memory(_ds, _di);                     //mov bl, byte ptr [di]
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    _al &= 0x6f;                                //and al, 0x6f
    _dl |= _al;                                 //or dl, al
    _di += 1;                                   //inc di
    _bl = memory(_ds, _di);                     //mov bl, byte ptr [di]
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    _al &= 0x6f;                                //and al, 0x6f
    _dl |= _al;                                 //or dl, al
    _di += 0x001f;                              //add di, 0x1f
    if (--_cx)                                  //loop loc_1238
        goto loc_1238;
    _bl = memory(_ds, _di);                     //mov bl, byte ptr [di]
    _dl = _dl | memory(_ds, _bx);               //or dl, byte ptr [bx]
    _di += 1;                                   //inc di
    _bl = memory(_ds, _di);                     //mov bl, byte ptr [di]
    _dl = _dl | memory(_ds, _bx);               //or dl, byte ptr [bx]
    memory(_ds, 32103) = _dl;                   //mov byte ptr [0x7d67], dl
loc_125b:                                       //loc_125b:
    if (memory(_ds, 32103) & 0x40)              //jnz loc_1290
        goto loc_1290;
    if (memory(_ds, 32334) == 0x00)             //jz loc_1290
        goto loc_1290;
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
    _push(_bx);                                 //push bx
    _push(_dx);                                 //push dx
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _di = 0x808f;                               //mov di, 0x808f
    memory(_ds, _di + 2) = _bl;                 //mov byte ptr [di+0x2], bl
    memory16(_ds, _di + 4) = _dx;               //mov word ptr [di+0x4], dx
    _si = 0x7e4e;                               //mov si, 0x7e4e
    sub_12bc();                                 //call sub_12bc
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    if (_FIXME_)                                //jnz loc_1290
        goto loc_1290;
    memory(_ds, 32103) |= 0x40;                 //or byte ptr [0x7d67], 0x40
loc_1290:                                       //loc_1290:
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
}

void sub_1295()
{
    _di = 0x0000;                               //mov di, 0x0
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _cx = 0x0008;                               //mov cx, 0x8
loc_12a0:                                       //loc_12a0:
    _ax = memory16(_ds, _si);                   //mov ax, word ptr [si]
loc_12a2:                                       //loc_12a2:
    memory(_ds, _di) = _ah;                     //mov byte ptr [di], ah
    _di += 1;                                   //inc di
    _al -= 1;                                   //dec al
    if (_al != 0)                               //jnz loc_12a2
        goto loc_12a2;
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    if (--_cx)                                  //loop loc_12a0
        goto loc_12a0;
}

void sub_12ae()
{
    if (memory(_ds, 32117) == 0x00)             //jz loc_12b9
        goto loc_12b9;
    _flags.zero = false;
    return;                                     //ret
loc_12b9:                                       //loc_12b9:
    _di = 0x7e7e;                               //mov di, 0x7e7e
    sub_12bc();
    //_STOP_("sp-trace-fail");                    //sub_12ae endp_failed
    //_STOP_("continues");                        //sub_12bc proc near
}

void sub_12bc()
{
    _al = memory(_ds, _di + 2);                 //mov al, byte ptr [di+0x2]
    _al += 0x11;                                //add al, 0x11
    _ah = memory(_ds, _si + 2);                 //mov ah, byte ptr [si+0x2]
    if (_al < _ah)                              //jc loc_1312
        goto loc_1312;
    _al -= 0x0c;                                //sub al, 0xc
    _ah = _ah + memory(_ds, _si + 14);          //add ah, byte ptr [si+0xe]
    if (_ah < _al)                              //jc loc_1312
        goto loc_1312;
    _ax = memory16(_ds, _di + 4);               //mov ax, word ptr [di+0x4]
    _ax += 0x0014;                              //add ax, 0x14
    _bx = memory16(_ds, _si + 4);               //mov bx, word ptr [si+0x4]
    if (_ax < _bx)                              //jc loc_1312
        goto loc_1312;
    _ax = memory16(_ds, _di + 4);               //mov ax, word ptr [di+0x4]
    if (memory(_ds, _di) != 0x01)               //jnz loc_12ff
        goto loc_12ff;
    if (memory(_ds, 32104) == 0x00)             //jz loc_12ff
        goto loc_12ff;
    _ax += 0x0008;                              //add ax, 0x8
loc_12ff:                                       //loc_12ff:
    _cl = memory(_ds, _si + 16);                //mov cl, byte ptr [si+0x10]
    _cl -= 1;                                   //dec cl
    _ch = 0;                                    //sub ch, ch
    _bx += _cx;                                 //add bx, cx
    if (_bx < _ax)                              //jc loc_1312
        goto loc_1312;
    _al = 0;                                    //sub al, al
    _flags.zero = true;
    return;                                     //ret
loc_1312:                                       //loc_1312:
    _al = 0;                                    //sub al, al
    _al -= 1;                                   //dec al
    _flags.zero = false;
}

void sub_1317()
{
    _al = memory(_ds, _si + 2);                 //mov al, byte ptr [si+0x2]
    if (_al >= _bl)                             //jnc loc_1346
        goto loc_1346;
    _al = _al + memory(_ds, _si + 14);          //add al, byte ptr [si+0xe]
    if (_al < _bl)                              //jc loc_1346
        goto loc_1346;
    _ax = memory16(_ds, _si + 4);               //mov ax, word ptr [si+0x4]
    if (_dx < _ax)                              //jc loc_1346
        goto loc_1346;
    _cl = memory(_ds, _si + 16);                //mov cl, byte ptr [si+0x10]
    _ch = 0;                                    //sub ch, ch
    _ax += _cx;                                 //add ax, cx
    if (_ax < _dx)                              //jc loc_1346
        goto loc_1346;
    _al = 0;                                    //sub al, al
    _flags.zero = true;
    return;                                     //ret
loc_1346:                                       //loc_1346:
    _al = 0;                                    //sub al, al
    _al -= 1;                                   //dec al
    _flags.zero = false;
}

void sub_134b()
{
    _al = memory(_ds, 0x7ee0);                  //mov al, [0x7ee0]
    _ah = _al;                                  //mov ah, al
    _flags.carry = _al < 0x04;                  //sub al, 0x4
    _al -= 0x04;
    if (!_flags.carry)                          //jnc loc_1359
        goto loc_1359;
    _al = 0;                                    //sub al, al
loc_1359:                                       //loc_1359:
    _flags.carry = (_ah + 0x20) >= 0x100;       //add ah, 0x20
    _ah += 0x20;
    if (!_flags.carry)                          //jnc loc_1363
        goto loc_1363;
    _ah = 0xff;                                 //mov ah, 0xff
loc_1363:                                       //loc_1363:
    _bl = memory(_ds, _si + 2);                 //mov bl, byte ptr [si+0x2]
    if (_ah < _bl)                              //jc loc_13a7
        goto loc_13a7;
    _bl = _bl + memory(_ds, _si + 14);          //add bl, byte ptr [si+0xe]
    if (_bl < _al)                              //jc loc_13a7
        goto loc_13a7;
    _ax = memory16(_ds, 0x7ee2);                //mov ax, [0x7ee2]
    _bx = _ax;                                  //mov bx, ax
    _ax -= 0x0004;                              //sub ax, 0x4
    if (!(_ah & 0x80))                          //jz loc_1389
        goto loc_1389;
    _ax = 0;                                    //sub ax, ax
loc_1389:                                       //loc_1389:
    _bx += 0x001d;                              //add bx, 0x1d
    _cx = memory16(_ds, _si + 4);               //mov cx, word ptr [si+0x4]
    if (_bx < _cx)                              //jc loc_13a7
        goto loc_13a7;
    _dl = memory(_ds, _si + 16);                //mov dl, byte ptr [si+0x10]
    _dh = 0;                                    //sub dh, dh
    _cx += _dx;                                 //add cx, dx
    if (_cx < _ax)                              //jc loc_13a7
        goto loc_13a7;
    _al = 0;                                    //sub al, al
    _flags.zero = true;
    return;                                     //ret
loc_13a7:                                       //loc_13a7:
    _al = 0;                                    //sub al, al
    _al -= 1;                                   //dec al
    _flags.zero = false;
}

void sub_13ac()
{
    _push(_si);                                 //push si
    _di = _pop();                               //pop di
    if (!(memory(_ds, 32334) & 0x80))           //jz loc_13c3
        goto loc_13c3;
    _si = 0x7e4e;                               //mov si, 0x7e4e
    sub_12bc();                                 //call sub_12bc
    if (_FIXME_)                                //jz loc_13db
        goto loc_13db;
loc_13c3:                                       //loc_13c3:
    _cx = 0x0005;                               //mov cx, 0x5
    _si = 0x7f0e;                               //mov si, 0x7f0e
loc_13c9:                                       //loc_13c9:
    _push(_cx);                                 //push cx
    if (!(memory(_ds, _si) & 0x80))             //jz loc_13e0
        goto loc_13e0;
    sub_12bc();                                 //call sub_12bc
    if (!_flags.zero)                                //jnz loc_13e0
        goto loc_13e0;
    _cx = _pop();                               //pop cx
loc_13db:                                       //loc_13db:
    _push(_di);                                 //push di
    _si = _pop();                               //pop si
    _al = 0;                                    //sub al, al
    _flags.zero = true;
    return;                                     //ret
loc_13e0:                                       //loc_13e0:
    _si += 0x0030;                              //add si, 0x30
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_13c9
        goto loc_13c9;
    _push(_di);                                 //push di
    _si = _pop();                               //pop si
    _al = 0;                                    //sub al, al
    _al -= 1;                                   //dec al
    _flags.zero = false;
}

void sub_13ed()
{
    _al = memory(_ds, _si + 22);                //mov al, byte ptr [si+0x16]
    if (_al >= _bl)                             //jnc loc_1443
        goto loc_1443;
    _ch = _bl;                                  //mov ch, bl
    _bl = memory(_ds, _si);                     //mov bl, byte ptr [si]
    _bl &= 0x7f;                                //and bl, 0x7f
    _bh = 0;                                    //sub bh, bh
    _bx += _bx;                                 //add bx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += 0x932c;                              //add bx, 0x932c
    _ah = memory(_ds, _bx);                     //mov ah, byte ptr [bx]
    _bx += 1;                                   //inc bx
    _cl = memory(_ds, _bx);                     //mov cl, byte ptr [bx]
    _ah += _ah;                                 //add ah, ah
    _ah += _ah;                                 //add ah, ah
    _ah += _ah;                                 //add ah, ah
    _flags.carry = (_ah + _al) >= 0x100;        //add ah, al
    _ah += _al;
    if (!_flags.carry)                          //jnc loc_141e
        goto loc_141e;
    _ah = 0xff;                                 //mov ah, 0xff
loc_141e:                                       //loc_141e:
    if (_ah < _ch)                              //jc loc_1443
        goto loc_1443;
    _ax = memory16(_ds, _si + 24);              //mov ax, word ptr [si+0x18]
    if (_ax >= _dx)                             //jnc loc_1443
        goto loc_1443;
    _ch = 0;                                    //sub ch, ch
    _cx += _cx;                                 //add cx, cx
    _cx += _cx;                                 //add cx, cx
    _cx += _cx;                                 //add cx, cx
    _ax += _cx;                                 //add ax, cx
    if (_ax < _dx)                              //jc loc_1443
        goto loc_1443;
    _al = 0;                                    //sub al, al
    _flags.zero = true;
    return;                                     //ret
loc_1443:                                       //loc_1443:
    _al = 0;                                    //sub al, al
    _al -= 1;                                   //dec al
    _flags.zero = false;
}

void sub_1448()
{
    sub_153c();                                 //call sub_153c
    _al = memory(_ds, 0x7d68);                  //mov al, [0x7d68]
    memory(_ds, 0x7d69) = _al;                  //mov [0x7d69], al
    if (memory(_ds, 32117) == 0x00)             //jz loc_145c
        goto loc_145c;
    return;                                     //ret
loc_145c:                                       //loc_145c:
    if (memory(_ds, 32106) == 0x00)             //jz loc_1479
        goto loc_1479;
    memory(_ds, _si + 8) = 0x0b;                //mov byte ptr [si+0x8], 0xb
    if (memory(_ds, 32121) == 0x00)             //jz loc_1478
        goto loc_1478;
    memory(_ds, _si + 8) = 0x17;                //mov byte ptr [si+0x8], 0x17
loc_1478:                                       //loc_1478:
    return;                                     //ret
loc_1479:                                       //loc_1479:
    if (memory(_ds, 32107) == 0x00)             //jz loc_1493
        goto loc_1493;
    memory(_ds, _si + 8) = 0x0a;                //mov byte ptr [si+0x8], 0xa
    if (memory(_ds, 32121) == 0x00)             //jz loc_1478
        goto loc_1478;
    memory(_ds, _si + 8) = 0x16;                //mov byte ptr [si+0x8], 0x16
    return;                                     //ret
loc_1493:                                       //loc_1493:
    if (memory(_ds, 32109) == 0x00)             //jz loc_14b0
        goto loc_14b0;
    memory(_ds, _si + 8) = 0x0c;                //mov byte ptr [si+0x8], 0xc
    _al = memory(_ds, _si + 2);                 //mov al, byte ptr [si+0x2]
    _al = _al ^ memory(_ds, _si + 4);           //xor al, byte ptr [si+0x4]
    _al &= 0x04;                                //and al, 0x4
    if (_al == 0)                               //jz loc_1478
        goto loc_1478;
    memory(_ds, _si + 8) = 0x18;                //mov byte ptr [si+0x8], 0x18
    return;                                     //ret
loc_14b0:                                       //loc_14b0:
    if (memory(_ds, 32104) == 0x00)             //jz loc_14e9
        goto loc_14e9;
    _al = memory(_ds, 0x7d78);                  //mov al, [0x7d78]
    _al += 1;                                   //inc al
    _al &= 0x03;                                //and al, 0x3
    memory(_ds, 0x7d78) = _al;                  //mov [0x7d78], al
    if (_al != 0)                               //jnz loc_14cc
        goto loc_14cc;
    sub_2b68();                                 //call sub_2b68
loc_14cc:                                       //loc_14cc:
    _ah = 0x07;                                 //mov ah, 0x7
    if (memory(_ds, 32121) == 0x00)             //jz loc_14da
        goto loc_14da;
    _ah = 0x13;                                 //mov ah, 0x13
loc_14da:                                       //loc_14da:
    if (!(memory(_ds, _si + 2) & 0x04))         //jz loc_14e5
        goto loc_14e5;
    _ah += 1;                                   //inc ah
loc_14e5:                                       //loc_14e5:
    memory(_ds, _si + 8) = _ah;                 //mov byte ptr [si+0x8], ah
    return;                                     //ret
loc_14e9:                                       //loc_14e9:
    if (memory16(_ds, 32110) == 0x0000)         //jz loc_1506
        goto loc_1506;
    memory(_ds, _si + 8) = 0x06;                //mov byte ptr [si+0x8], 0x6
    if (memory(_ds, 32121) == 0x00)             //jz loc_153b
        goto loc_153b;
    memory(_ds, _si + 8) = 0x15;                //mov byte ptr [si+0x8], 0x15
    return;                                     //ret
loc_1506:                                       //loc_1506:
    _al = memory(_ds, 0x7d78);                  //mov al, [0x7d78]
    _al += 1;                                   //inc al
    if (_al < 0x14)                             //jc loc_1517
        goto loc_1517;
    sub_2b68();                                 //call sub_2b68
    _al = 0x04;                                 //mov al, 0x4
loc_1517:                                       //loc_1517:
    if (_al != 0x0c)                            //jnz loc_1523
        goto loc_1523;
    sub_2b68();                                 //call sub_2b68
    _al = 0x0c;                                 //mov al, 0xc
loc_1523:                                       //loc_1523:
    memory(_ds, 0x7d78) = _al;                  //mov [0x7d78], al
    _al >>= 1;                                  //shr al, 1
    _al >>= 1;                                  //shr al, 1
    _al += 0x01;                                //add al, 0x1
    if (memory(_ds, 32121) == 0x00)             //jz loc_1538
        goto loc_1538;
    _al += 0x0c;                                //add al, 0xc
loc_1538:                                       //loc_1538:
    memory(_ds, _si + 8) = _al;                 //mov byte ptr [si+0x8], al
loc_153b:                                       //loc_153b:
    return;
}

void sub_153c() // check keyboard
{
    memory(_ds, 32106) = 0x00;                  //mov byte ptr [0x7d6a], 0x0
    memory(_ds, 32107) = 0x00;                  //mov byte ptr [0x7d6b], 0x0
    _al = memory(_ds, 0x7d75);                  //mov al, [0x7d75]
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz loc_1550
        goto loc_1550;
    goto loc_195a;                              //jmp loc_195a
loc_1550:                                       //loc_1550:
    _al = memory(_ds, 0x7e44);                  //mov al, [0x7e44]
    memory(_ds, 0x7d6c) = _al;                  //mov [0x7d6c], al
    _al = memory(_ds, 0x7d6d);                  //mov al, [0x7d6d]
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz loc_1560
        goto loc_1560;
    goto loc_1873;                              //jmp loc_1873
loc_1560:                                       //loc_1560:
    memory(_ds, 32110) = 0x00;                  //mov byte ptr [0x7d6e], 0x0
    _dl = memory(_ds, 32114);                   //mov dl, byte ptr [0x7d72]
    _dh = memory(_ds, _si + 4);                 //mov dh, byte ptr [si+0x4]
    _al = memory(_ds, _si + 5);                 //mov al, byte ptr [si+0x5]
    _bx = memory16(_ds, 32112);                 //mov bx, word ptr [0x7d70]
    _ah = 0;                                    //sub ah, ah
    if (!(_bh & 0x80))                          //jz loc_157f
        goto loc_157f;
    _ah -= 1;                                   //dec ah
loc_157f:                                       //loc_157f:
    _flags.carry = (_dx + _bx) >= 0x10000;      //add dx, bx
    _dx += _bx;
    _al = _al + _ah + _flags.carry;             //adc al, ah
    _ah = _dl;                                  //mov ah, dl
    _dl = _dh;                                  //mov dl, dh
    _dh = _al;                                  //mov dh, al
    _bl = memory(_ds, _si + 2);                 //mov bl, byte ptr [si+0x2]
    _al = memory(_ds, 0x7d68);                  //mov al, [0x7d68]
    if (_al == 0x00)                            //jz loc_15ab
        goto loc_15ab;
    sub_113a();                                 //call sub_113a
    _al = memory(_ds, 0x7d74);                  //mov al, [0x7d74]
    if (_al != 0x00)                            //jnz loc_15ae
        goto loc_15ae;
    memory(_ds, 32104) = 0x00;                  //mov byte ptr [0x7d68], 0x0
    goto loc_15ae;                              //jmp loc_15ae
    _STOP_("db 90h");                           //db 90h
loc_15ab:                                       //loc_15ab:
    sub_11bc();                                 //call sub_11bc
loc_15ae:                                       //loc_15ae:
    _bh = 0xf0;                                 //mov bh, 0xf0
    _al = memory(_ds, 0x7d71);                  //mov al, [0x7d71]
    _flags.sign = !!(_al & 0x80);               //or al, al
    _al |= _al;
    if (!_flags.sign)                           //jns loc_15bc
        goto loc_15bc;
    _bh = 0xe0;                                 //mov bh, 0xe0
loc_15bc:                                       //loc_15bc:
    _al = memory(_ds, 0x7d67);                  //mov al, [0x7d67]
    _cl = _al;                                  //mov cl, al
    _al &= _bh;                                 //and al, bh
    if (_al == 0)                               //jz loc_15cb
        goto loc_15cb;
    goto loc_168f;                              //jmp loc_168f
loc_15cb:                                       //loc_15cb:
    memory(_ds, 32110) = 0xff;                  //mov byte ptr [0x7d6e], 0xff
    if (!(_cl & 0x04))                          //jz loc_15d8
        goto loc_15d8;
    {sub_19cf(); return; };                     //
loc_15d8:                                       //loc_15d8:
    memory16(_ds, _si + 4) = _dx;               //mov word ptr [si+0x4], dx
    memory(_ds, 32114) = _ah;                   //mov byte ptr [0x7d72], ah
    if (!(_cl & 0x02))                          //jz loc_15fd
        goto loc_15fd;
    _al = memory(_ds, 0x7d6c);                  //mov al, [0x7d6c]
    _al &= 0x0c;                                //and al, 0xc
    if (_al == 0)                               //jz loc_15fd
        goto loc_15fd;
    memory16(_ds, 32112) = 0x0100;              //mov word ptr [0x7d70], 0x100
    memory(_ds, 32109) = 0xff;                  //mov byte ptr [0x7d6d], 0xff
    return;                                     //ret
loc_15fd:                                       //loc_15fd:
    _dx = memory16(_ds, 32112);                 //mov dx, word ptr [0x7d70]
    _flags.sign = (short)(_dx + 0x0080) < 0;    //add dx, 0x80
    _dx += 0x0080;
    if (_flags.sign)                            //js loc_161a
        goto loc_161a;
    if (_dh < 0x08)                             //jc loc_161a
        goto loc_161a;
    memory(_ds, 32114) = 0x00;                  //mov byte ptr [0x7d72], 0x0
    _dx = 0x0800;                               //mov dx, 0x800
loc_161a:                                       //loc_161a:
    memory16(_ds, 32112) = _dx;                 //mov word ptr [0x7d70], dx
loc_161e:                                       //loc_161e:
    _al = memory(_ds, 0x7d6c);                  //mov al, [0x7d6c]
    _al &= 0x03;                                //and al, 0x3
    _al |= _al;                                 //or al, al
    if (_al != 0)                               //jnz loc_1630
        goto loc_1630;
    memory(_ds, 32120) = 0x02;                  //mov byte ptr [0x7d78], 0x2
    return;                                     //ret
loc_1630:                                       //loc_1630:
    if (_al != 0x02)                            //jnz loc_1649
        goto loc_1649;
    memory(_ds, 32121) = 0x01;                  //mov byte ptr [0x7d79], 0x1
    _ax = memory16(_ds, _si + 2);               //mov ax, word ptr [si+0x2]
    _flags.carry = (_al + 0xfe) >= 0x100;       //add al, 0xfe
    _al += 0xfe;
    if (_flags.carry)                           //jc loc_165e
        goto loc_165e;
    goto loc_19af;                              //jmp loc_19af
loc_1649:                                       //loc_1649:
    memory(_ds, 32121) = 0x00;                  //mov byte ptr [0x7d79], 0x0
    _ax = memory16(_ds, _si + 2);               //mov ax, word ptr [si+0x2]
    _ax += 0x0002;                              //add ax, 0x2
    if (_al < 0xe8)                             //jc loc_165e
        goto loc_165e;
    goto loc_19bf;                              //jmp loc_19bf
loc_165e:                                       //loc_165e:
    _dx = memory16(_ds, _si + 4);               //mov dx, word ptr [si+0x4]
    _bl = _al;                                  //mov bl, al
    _al = memory(_ds, 0x7d68);                  //mov al, [0x7d68]
    _al &= _al;                                 //and al, al
    if (_al == 0)                               //jz loc_1673
        goto loc_1673;
    sub_113a();                                 //call sub_113a
    goto loc_1676;                              //jmp loc_1676
    _STOP_("db 90h");                           //db 90h
loc_1673:                                       //loc_1673:
    sub_11bc();                                 //call sub_11bc
loc_1676:                                       //loc_1676:
    _al = memory(_ds, 0x7d67);                  //mov al, [0x7d67]
    _cl = _al;                                  //mov cl, al
    _al &= 0x70;                                //and al, 0x70
    if (_al == 0)                               //jz loc_1683
        goto loc_1683;
    return;                                     //ret
loc_1683:                                       //loc_1683:
    memory(_ds, _si + 2) = _bl;                 //mov byte ptr [si+0x2], bl
    if (!(_cl & 0x04))                          //jz loc_168e
        goto loc_168e;
    {sub_19cf(); return; };                     //
loc_168e:                                       //loc_168e:
    return;                                     //ret
loc_168f:                                       //loc_168f:
    _ax = memory16(_ds, 0x7d70);                //mov ax, [0x7d70]
    _flags.sign = !!(_ax & 0x8000);
    _ax &= _ax;
    if (!_flags.sign)                           //jns loc_16b5
        goto loc_16b5;
    memory16(_ds, 32110) = 0x00ff;              //mov word ptr [0x7d6e], 0xff
    _ax = memory16(_ds, _si + 4);               //mov ax, word ptr [si+0x4]
    _al &= 0xf8;                                //and al, 0xf8
    memory16(_ds, _si + 4) = _ax;               //mov word ptr [si+0x4], ax
    memory(_ds, 32114) = 0x00;                  //mov byte ptr [0x7d72], 0x0
    memory16(_ds, 32112) = 0x0000;              //mov word ptr [0x7d70], 0x0
    goto loc_161e;                              //jmp loc_161e
loc_16b5:                                       //loc_16b5:
    _ax = memory16(_ds, _si + 4);               //mov ax, word ptr [si+0x4]
    _al &= 0xf8;                                //and al, 0xf8
    _al |= 0x03;                                //or al, 0x3
    memory16(_ds, _si + 4) = _ax;               //mov word ptr [si+0x4], ax
    memory(_ds, 32114) = 0x00;                  //mov byte ptr [0x7d72], 0x0
    if (!(_cl & 0x20))                          //jz loc_16fc
        goto loc_16fc;
    _bx = memory16(_ds, 32112);                 //mov bx, word ptr [0x7d70]
    _al = _bh;                                  //mov al, bh
    _FIXME_;                                    //and al, al
    _al &= _al;
    if (_flags.sign)                            //js loc_16fc
        goto loc_16fc;
    if (_al < 0x02)                             //jc loc_16fc
        goto loc_16fc;
    if (!(memory(_ds, 32108) & 0x08))           //jz loc_16f0
        goto loc_16f0;
    _cx = 0xf800;                               //mov cx, 0xf800
    goto loc_16f5;                              //jmp loc_16f5
    _STOP_("db 90h");                           //db 90h
loc_16f0:                                       //loc_16f0:
    _cx = 0x00fe;                               //mov cx, 0xfe
    _cx -= _bx;                                 //sub cx, bx
loc_16f5:                                       //loc_16f5:
    memory16(_ds, 32112) = _cx;                 //mov word ptr [0x7d70], cx
    goto loc_161e;                              //jmp loc_161e
loc_16fc:                                       //loc_16fc:
    memory16(_ds, 32112) = 0x0100;              //mov word ptr [0x7d70], 0x100
    _al = memory(_ds, 0x7d6c);                  //mov al, [0x7d6c]
    _dh = _al;                                  //mov dh, al
    _al = memory(_ds, 0x7d69);                  //mov al, [0x7d69]
    _al &= _al;                                 //and al, al
    _flags.zero = _al == 0; //!!!! TODO PARSER
    _al = _dh;                                  //mov al, dh
    if (_flags.zero)                               //jz loc_1713
        goto loc_1713;
    goto loc_1808;                              //jmp loc_1808
loc_1713:                                       //loc_1713:
    if (_dh & 0x10)                             //jnz loc_171b
        goto loc_171b;
    goto loc_1808;                              //jmp loc_1808
loc_171b:                                       //loc_171b:
    _al &= 0x03;                                //and al, 0x3
    if (_al == 0)                               //jz loc_174b
        goto loc_174b;
    _ax = memory16(_ds, _si + 4);               //mov ax, word ptr [si+0x4]
    _ax += 0x000e;                              //add ax, 0xe
    memory16(_ds, 0x7d7c) = _ax;                //mov [0x7d7c], ax
    memory(_ds, 32121) = 0x01;                  //mov byte ptr [0x7d79], 0x1
    _al = memory(_ds, _si + 2);                 //mov al, byte ptr [si+0x2]
    if (!(_dh & 0x01))                          //jz loc_1742
        goto loc_1742;
    memory(_ds, 32121) = 0x00;                  //mov byte ptr [0x7d79], 0x0
    _al += 0x17;                                //add al, 0x17
loc_1742:                                       //loc_1742:
    memory(_ds, 0x7d7b) = _al;                  //mov [0x7d7b], al
    memory(_ds, 32106) = 0xff;                  //mov byte ptr [0x7d6a], 0xff
    return;                                     //ret
loc_174b:                                       //loc_174b:
    _al = _dh;                                  //mov al, dh
    _al &= 0x0c;                                //and al, 0xc
    if (_al != 0x08)                            //jnz loc_17c3
        goto loc_17c3;
    memory(_ds, 32107) = 0xff;                  //mov byte ptr [0x7d6b], 0xff
    _al = memory(_ds, 0x7d86);                  //mov al, [0x7d86]
    _al &= _al;                                 //and al, al
    if (_al == 0)                               //jz loc_1766
        goto loc_1766;
    return;                                     //ret
loc_1766:                                       //loc_1766:
    memory(_ds, 32134) = 0xff;                  //mov byte ptr [0x7d86], 0xff
    _al = memory(_ds, 0x7eae);                  //mov al, [0x7eae]
    _al &= _al;                                 //and al, al
    if (_al == 0)                               //jz loc_1776
        goto loc_1776;
    return;                                     //ret
loc_1776:                                       //loc_1776:
    _al = memory(_ds, 0x7e45);                  //mov al, [0x7e45]
    _al &= _al;                                 //and al, al
    if (_al != 0)                               //jnz loc_1781
        goto loc_1781;
    return;                                     //ret
loc_1781:                                       //loc_1781:
    _al -= 1;                                   //dec al
    memory(_ds, 0x7e45) = _al;                  //mov [0x7e45], al
    memory16(_ds, 32430) = 0x0002;              //mov word ptr [0x7eae], 0x2
    _ax = memory16(_ds, _si + 4);               //mov ax, word ptr [si+0x4]
    _ax += 0x0006;                              //add ax, 0x6
    memory16(_ds, 0x7eb2) = _ax;                //mov [0x7eb2], ax
    _al = memory(_ds, _si + 2);                 //mov al, byte ptr [si+0x2]
    memory(_ds, 0x7eb0) = _al;                  //mov [0x7eb0], al
    memory16(_ds, 32135) = 0x0008;              //mov word ptr [0x7d87], 0x8
    memory(_ds, 32438) = 0x20;                  //mov byte ptr [0x7eb6], 0x20
    _ax = 0x7d9c;                               //mov ax, 0x7d9c
    memory16(_ds, 0x7d9a) = _ax;                //mov [0x7d9a], ax
    _al = memory(_ds, 0x7d79);                  //mov al, [0x7d79]
    _al &= _al;                                 //and al, al
    if (_al != 0)                               //jnz loc_17b7
        goto loc_17b7;
    return;                                     //ret
loc_17b7:                                       //loc_17b7:
    memory16(_ds, 32135) = 0xfff8;              //mov word ptr [0x7d87], 0xfff8
    memory(_ds, 32438) = 0x21;                  //mov byte ptr [0x7eb6], 0x21
    return;                                     //ret
loc_17c3:                                       //loc_17c3:
    memory(_ds, 32134) = 0x00;                  //mov byte ptr [0x7d86], 0x0
    memory(_ds, 32120) = 0x00;                  //mov byte ptr [0x7d78], 0x0
    if (_dh & 0x04)                             //jnz loc_17d6
        goto loc_17d6;
    return;                                     //ret
loc_17d6:                                       //loc_17d6:
    if (!(memory(_ds, 32478) & 0xff))           //jz loc_17e1
        goto loc_17e1;
    return;                                     //ret
loc_17e1:                                       //loc_17e1:
    _al = memory(_ds, 0x7e47);                  //mov al, [0x7e47]
    _al &= _al;                                 //and al, al
    if (_al != 0)                               //jnz loc_17ec
        goto loc_17ec;
    return;                                     //ret
loc_17ec:                                       //loc_17ec:
    _al -= 1;                                   //dec al
    memory(_ds, 0x7e47) = _al;                  //mov [0x7e47], al
    memory(_ds, 32478) = 0x03;                  //mov byte ptr [0x7ede], 0x3
    memory(_ds, 32129) = 0x2d;                  //mov byte ptr [0x7d81], 0x2d
    _al = memory(_ds, _si + 2);                 //mov al, byte ptr [si+0x2]
    memory(_ds, 0x7ee0) = _al;                  //mov [0x7ee0], al
    _ax = memory16(_ds, _si + 4);               //mov ax, word ptr [si+0x4]
    memory16(_ds, 0x7ee2) = _ax;                //mov [0x7ee2], ax
    return;                                     //ret
loc_1808:                                       //loc_1808:
    if (!(_dh & 0x08))                          //jz loc_1832
        goto loc_1832;
    if (!(_cl & 0x02))                          //jz loc_181e
        goto loc_181e;
    memory(_ds, 32109) = 0xff;                  //mov byte ptr [0x7d6d], 0xff
    return;                                     //ret
loc_181e:                                       //loc_181e:
    memory16(_ds, 32112) = 0xfa80;              //mov word ptr [0x7d70], 0xfa80
    memory(_ds, 32114) = 0x00;                  //mov byte ptr [0x7d72], 0x0
    _ax = 0x7de9;                               //mov ax, 0x7de9
    memory16(_ds, 0x7d9a) = _ax;                //mov [0x7d9a], ax
    goto loc_161e;                              //jmp loc_161e
loc_1832:                                       //loc_1832:
    if (_dh & 0x04)                             //jnz loc_183d
        goto loc_183d;
    goto loc_161e;                              //jmp loc_161e
loc_183d:                                       //loc_183d:
    if (!(_cl & 0x80))                          //jz loc_186b
        goto loc_186b;
    _al = memory(_ds, 0x7d6c);                  //mov al, [0x7d6c]
    _al &= 0x03;                                //and al, 0x3
    if (_al != 0)                               //jnz loc_186b
        goto loc_186b;
    _al = memory(_ds, _si + 2);                 //mov al, byte ptr [si+0x2]
    _al &= 0x1f;                                //and al, 0x1f
    if (_al >= 0x0a)                            //jnc loc_186b
        goto loc_186b;
    _al = memory(_ds, _si + 2);                 //mov al, byte ptr [si+0x2]
    _al &= 0xf0;                                //and al, 0xf0
    _al |= 0x04;                                //or al, 0x4
    memory(_ds, _si + 2) = _al;                 //mov byte ptr [si+0x2], al
    memory(_ds, 32109) = 0xff;                  //mov byte ptr [0x7d6d], 0xff
    return;                                     //ret
loc_186b:                                       //loc_186b:
    memory(_ds, 32104) = 0xff;                  //mov byte ptr [0x7d68], 0xff
    goto loc_161e;                              //jmp loc_161e
loc_1873:                                       //loc_1873:
    _al = memory(_ds, 0x7d6c);                  //mov al, [0x7d6c]
    _al &= 0x0f;                                //and al, 0xf
    if (_al != 0)                               //jnz loc_1883
        goto loc_1883;
    memory(_ds, 32120) = 0x00;                  //mov byte ptr [0x7d78], 0x0
    return;                                     //ret
loc_1883:                                       //loc_1883:
    _al &= 0x0c;                                //and al, 0xc
    if (_al == 0)                               //jz loc_18f1
        goto loc_18f1;
    _dx = memory16(_ds, _si + 4);               //mov dx, word ptr [si+0x4]
    if (_al != 0x08)                            //jnz loc_189a
        goto loc_189a;
    _cx = 0xfffe;                               //mov cx, 0xfffe
    goto loc_189d;                              //jmp loc_189d
    _STOP_("db 90h");                           //db 90h
loc_189a:                                       //loc_189a:
    _cx = 0x0002;                               //mov cx, 0x2
loc_189d:                                       //loc_189d:
    _dx += _cx;                                 //add dx, cx
    _bl = memory(_ds, _si + 2);                 //mov bl, byte ptr [si+0x2]
    sub_11bc();                                 //call sub_11bc
    _al = memory(_ds, 0x7d67);                  //mov al, [0x7d67]
    _cl = _al;                                  //mov cl, al
    _al &= 0x70;                                //and al, 0x70
    if (_al == 0)                               //jz loc_18c7
        goto loc_18c7;
    if (_ch & 0x80)                             //jnz loc_18bf
        goto loc_18bf;
    memory(_ds, 32109) = 0x00;                  //mov byte ptr [0x7d6d], 0x0
    return;                                     //ret
loc_18bf:                                       //loc_18bf:
    if (!(_cl & 0x10))                          //jz loc_18f1
        goto loc_18f1;
loc_18c7:                                       //loc_18c7:
    memory16(_ds, _si + 4) = _dx;               //mov word ptr [si+0x4], dx
    if (!(_cl & 0x04))                          //jz loc_18d2
        goto loc_18d2;
    {sub_19cf(); return; };                     //
loc_18d2:                                       //loc_18d2:
    if (_cl & 0x82)                             //jnz loc_18f1
        goto loc_18f1;
    _dx = 0x0100;                               //mov dx, 0x100
    _flags.sign = !!(_cx & 0x8000);             //or cx, cx
    _cx |= _cx;
    if (!_flags.sign)                           //jns loc_18e7
        goto loc_18e7;
    _dx = 0xfd00;                               //mov dx, 0xfd00
loc_18e7:                                       //loc_18e7:
    memory16(_ds, 32112) = _dx;                 //mov word ptr [0x7d70], dx
    memory(_ds, 32109) = 0x00;                  //mov byte ptr [0x7d6d], 0x0
    return;                                     //ret
loc_18f1:                                       //loc_18f1:
    _al = memory(_ds, 0x7d6c);                  //mov al, [0x7d6c]
    _al &= 0x03;                                //and al, 0x3
    if (_al != 0)                               //jnz loc_18fc
        goto loc_18fc;
    return;                                     //ret
loc_18fc:                                       //loc_18fc:
    _flags.zero = _al == 1;
    _al = memory(_ds, _si + 2);                 //mov al, byte ptr [si+0x2]
    if (_flags.zero)                            //jz loc_1910
        goto loc_1910;
    _flags.carry = (_al + 0xfe) >= 0x100;       //add al, 0xfe
    _al += 0xfe;
    if (_flags.carry)                           //jc loc_190d
        goto loc_190d;
    goto loc_19af;                              //jmp loc_19af
loc_190d:                                       //loc_190d:
    goto loc_1919;                              //jmp loc_1919
    _STOP_("db 90h");                           //db 90h
loc_1910:                                       //loc_1910:
    _al += 0x02;                                //add al, 0x2
    if (_al < 0xe8)                             //jc loc_1919
        goto loc_1919;
    goto loc_19bf;                              //jmp loc_19bf
loc_1919:                                       //loc_1919:
    _bl = _al;                                  //mov bl, al
    _dx = memory16(_ds, _si + 4);               //mov dx, word ptr [si+0x4]
    sub_11bc();                                 //call sub_11bc
    _al = memory(_ds, 0x7d67);                  //mov al, [0x7d67]
    _cl = _al;                                  //mov cl, al
    _al &= 0x60;                                //and al, 0x60
    if (_al == 0)                               //jz loc_192e
        goto loc_192e;
    return;                                     //ret
loc_192e:                                       //loc_192e:
    memory(_ds, _si + 2) = _bl;                 //mov byte ptr [si+0x2], bl
    if (!(_cl & 0x04))                          //jz loc_1939
        goto loc_1939;
    {sub_19cf(); return; };                     //
loc_1939:                                       //loc_1939:
    _al = _cl;                                  //mov al, cl
    _al &= 0x82;                                //and al, 0x82
    if (_al == 0)                               //jz loc_1943
        goto loc_1943;
    return;                                     //ret
loc_1943:                                       //loc_1943:
    memory(_ds, 32109) = 0x00;                  //mov byte ptr [0x7d6d], 0x0
    _al = memory(_ds, 0x7d6c);                  //mov al, [0x7d6c]
    if (_al & 0x08)                             //jnz loc_1953
        goto loc_1953;
    return;                                     //ret
loc_1953:                                       //loc_1953:
    memory16(_ds, 32112) = 0xfd00;              //mov word ptr [0x7d70], 0xfd00
    return;                                     //ret
loc_195a:                                       //loc_195a:
    memory(_ds, _si + 8) = 0x19;                //mov byte ptr [si+0x8], 0x19
    if (!(memory(_ds, _si + 2) & 0x04))         //jz loc_196b
        goto loc_196b;
    memory(_ds, _si + 8) = 0x1a;                //mov byte ptr [si+0x8], 0x1a
loc_196b:                                       //loc_196b:
    _al = memory(_ds, 0x7d7a);                  //mov al, [0x7d7a]
    _al = _al + memory(_ds, _si + 2);           //add al, byte ptr [si+0x2]
    memory(_ds, _si + 2) = _al;                 //mov byte ptr [si+0x2], al
    _al = memory(_ds, 0x7d72);                  //mov al, [0x7d72]
    _ah = memory(_ds, _si + 4);                 //mov ah, byte ptr [si+0x4]
    _bl = memory(_ds, _si + 5);                 //mov bl, byte ptr [si+0x5]
    _cx = memory16(_ds, 32112);                 //mov cx, word ptr [0x7d70]
    _bh = 0x00;                                 //mov bh, 0x0
    _flags.sign = !!(_cx & 0x8000);             //or cx, cx
    _cx |= _cx;
    if (!_flags.sign)                           //jns loc_198c
        goto loc_198c;
    _bh -= 1;                                   //dec bh
loc_198c:                                       //loc_198c:
    _flags.carry = (_ax + _cx) >= 0x10000;      //add ax, cx
    _ax += _cx;
    _bl = _bl + _bh + _flags.carry;             //adc bl, bh
    memory(_ds, 0x7d72) = _al;                  //mov [0x7d72], al
    memory(_ds, _si + 4) = _ah;                 //mov byte ptr [si+0x4], ah
    memory(_ds, _si + 5) = _bl;                 //mov byte ptr [si+0x5], bl
    _cx += 0x0080;                              //add cx, 0x80
    memory16(_ds, 32112) = _cx;                 //mov word ptr [0x7d70], cx
    if (_bl != 0x01)                            //jnz loc_19ae
        goto loc_19ae;
    memory(_ds, 32146) = 0xff;                  //mov byte ptr [0x7d92], 0xff
loc_19ae:                                       //loc_19ae:
    return;                                     //ret
loc_19af:                                       //loc_19af:
    memory(_ds, 32118) = 0xff;                  //mov byte ptr [0x7d76], 0xff
    memory(_ds, 32119) = 0x00;                  //mov byte ptr [0x7d77], 0x0
    memory16(_ds, _si + 2) = 0x00e2;            //mov word ptr [si+0x2], 0xe2
    return;                                     //ret
loc_19bf:                                       //loc_19bf:
    memory(_ds, 32118) = 0xff;                  //mov byte ptr [0x7d76], 0xff
    memory(_ds, 32119) = 0x01;                  //mov byte ptr [0x7d77], 0x1
    memory16(_ds, _si + 2) = 0x0004;            //mov word ptr [si+0x2], 0x4
}

void sub_19cf()
{
    _al = memory(_ds, 0x7d75);                  //mov al, [0x7d75]
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz loc_19da
        goto loc_19da;
    return;                                     //ret
loc_19da:                                       //loc_19da:
    _ax = 0x7da9;                               //mov ax, 0x7da9
    memory16(_ds, 0x7d9a) = _ax;                //mov [0x7d9a], ax
    memory(_ds, 32117) = 0xff;                  //mov byte ptr [0x7d75], 0xff
    memory16(_ds, 32112) = 0xfc00;              //mov word ptr [0x7d70], 0xfc00
    _al = memory(_ds, 0x7e80);                  //mov al, [0x7e80]
    if (_al >= 0x80)                            //jnc loc_19fb
        goto loc_19fb;
    memory(_ds, 32122) = 0x03;                  //mov byte ptr [0x7d7a], 0x3
    return;                                     //ret
loc_19fb:                                       //loc_19fb:
    memory(_ds, 32122) = 0xfd;                  //mov byte ptr [0x7d7a], 0xfd
}

void sub_1a01()
{
    _al = memory(_ds, 0x7d87);                  //mov al, [0x7d87]
    _flags.sign = !!(_al & 0x80);
    if (!_flags.sign)                           //jns loc_1a30
        goto loc_1a30;
    _flags.carry = (_al + memory(_ds, _si + 2)) >= 0x100;
    _al = _al + memory(_ds, _si + 2);
    if (!_flags.carry)                          //jnc loc_1a44
        goto loc_1a44;
    memory(_ds, _si + 2) = _al;                 //mov byte ptr [si+0x2], al
loc_1a16:                                       //loc_1a16:
    _al += 0x0c;                                //add al, 0xc
    memory(_ds, 0x7d7e) = _al;                  //mov [0x7d7e], al
    _dx = memory16(_ds, _si + 4);               //mov dx, word ptr [si+0x4]
    _dx += 0x0005;                              //add dx, 0x5
    memory16(_ds, 32127) = _dx;                 //mov word ptr [0x7d7f], dx
    _bl = _al;                                  //mov bl, al
    sub_1115();                                 //call sub_1115
    if (!_flags.zero)                                //jnz loc_1a44
        goto loc_1a44;
    return;                                     //ret
loc_1a30:                                       //loc_1a30:
    _flags.carry = (_al + memory(_ds, _si + 2)) >= 0x100;
    _al = _al + memory(_ds, _si + 2);
    if (_flags.carry)                           //jc loc_1a44
        goto loc_1a44;
    if (_al >= 0xe8)                            //jnc loc_1a44
        goto loc_1a44;
    memory(_ds, _si + 2) = _al;                 //mov byte ptr [si+0x2], al
    goto loc_1a16;                              //jmp loc_1a16
loc_1a44:                                       //loc_1a44:
    memory(_ds, _si) = 0x00;                    //mov byte ptr [si], 0x0
}

void sub_1a48()
{
    _al = memory(_ds, 0x7d81);                  //mov al, [0x7d81]
    _al -= 1;                                   //dec al
    if (_al != 0)                               //jnz loc_1a5b
        goto loc_1a5b;
    memory(_ds, _si) = 0x00;                    //mov byte ptr [si], 0x0
    memory(_ds, 32133) = 0x00;                  //mov byte ptr [0x7d85], 0x0
    return;                                     //ret
loc_1a5b:                                       //loc_1a5b:
    memory(_ds, 0x7d81) = _al;                  //mov [0x7d81], al
    if (_al < 0x0a)                             //jc loc_1a87
        goto loc_1a87;
    if (_al != 0x0b)                            //jnz loc_1a72
        goto loc_1a72;
    _ax = 0x7e1b;                               //mov ax, 0x7e1b
    memory16(_ds, 0x7d9a) = _ax;                //mov [0x7d9a], ax
loc_1a72:                                       //loc_1a72:
    memory(_ds, _si + 8) = 0x22;                //mov byte ptr [si+0x8], 0x22
    if (!(_al & 0x01))                          //jz loc_1a81
        goto loc_1a81;
    memory(_ds, _si + 8) = 0x23;                //mov byte ptr [si+0x8], 0x23
loc_1a81:                                       //loc_1a81:
    memory(_ds, 32133) = 0x00;                  //mov byte ptr [0x7d85], 0x0
    return;                                     //ret
loc_1a87:                                       //loc_1a87:
    _ah = 0;                                    //sub ah, ah
    _al >>= 1;                                  //shr al, 1
    _di = 0x8138;                               //mov di, 0x8138
    _di += _ax;                                 //add di, ax
    _al = memory(_ds, _di);                     //mov al, byte ptr [di]
    memory(_ds, _si + 8) = _al;                 //mov byte ptr [si+0x8], al
    if (_al < 0x04)                             //jc loc_1a81
        goto loc_1a81;
    _al = memory(_ds, _si + 2);                 //mov al, byte ptr [si+0x2]
    _al += 0x0c;                                //add al, 0xc
    memory(_ds, 0x7d82) = _al;                  //mov [0x7d82], al
    _ax = memory16(_ds, _si + 4);               //mov ax, word ptr [si+0x4]
    _ax += 0x000a;                              //add ax, 0xa
    memory16(_ds, 0x7d83) = _ax;                //mov [0x7d83], ax
    memory(_ds, 32133) = 0xff;                  //mov byte ptr [0x7d85], 0xff
    _push(_si);                                 //push si
    _si = 0x7e7e;                               //mov si, 0x7e7e
    sub_134b();                                 //call sub_134b
    _si = _pop();                               //pop si
    if (!_flags.zero)                                //jnz loc_1abf
        goto loc_1abf;
    {sub_19cf(); return; };                     //
loc_1abf:                                       //loc_1abf:
    return;                                     //ret
    _STOP_("db b8h");                           //db b8h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 9ah");                           //db 9ah
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("sp-trace-fail");                    //sub_1a48 endp_failed
    _STOP_("continues");                        //sub_1ac6 proc near
}

void sub_1ac6()
{
    _push(_ds);                                 //push ds
    _al = memory(_ds, 0x7d90);                  //mov al, [0x7d90]
    _ah = 0x00;                                 //mov ah, 0x0
    _push(_ax);                                 //push ax
    memory16(_ds, 0x971e) = _ax;                //mov [0x971e], ax
    _dx = 0x1fc1;                               //mov dx, 0x1fc1
    _ds = _dx;                                  //mov ds, dx
    _dx = 0xa000;                               //mov dx, 0xa000
    _es = _dx;                                  //mov es, dx
    _ax = 0x2800;                               //mov ax, 0x2800
    memory16(_ds, 0x4907) = _ax;                //mov [0x4907], ax
    sub_0797();                                 //call sub_0797
    _bx = _pop();                               //pop bx
    _bl += _bl;                                 //add bl, bl
    _bx += 0x48cc;                              //add bx, 0x48cc
    _bx = memory16(_ds, _bx);                   //mov bx, word ptr [bx]
    _di = 0x0005;                               //mov di, 0x5
    sub_1f89();                                 //call sub_1f89
    _di = 0x0f04;                               //mov di, 0xf04
    sub_1f7b();                                 //call sub_1f7b
    _ds = _pop();                               //pop ds
    sub_1c82();                                 //call sub_1c82
    sub_1d30();                                 //call sub_1d30
    sub_1dac();                                 //call sub_1dac
    sub_1d5e();                                 //call sub_1d5e
    sub_1bae();                                 //call sub_1bae
    memory(_ds, 32323) = 0x00;                  //mov byte ptr [0x7e43], 0x0
loc_1b0d:                                       //loc_1b0d:
    sub_07bb();                                 //call sub_07bb
    sub_1d5e();                                 //call sub_1d5e
    sub_07bb();                                 //call sub_07bb
    sub_1ce7();                                 //call sub_1ce7
    sub_1bae();                                 //call sub_1bae
    sub_07bb();                                 //call sub_07bb
    sub_1d5e();                                 //call sub_1d5e
    sub_1dac();                                 //call sub_1dac
    sub_07bb();                                 //call sub_07bb
    sub_1bae();                                 //call sub_1bae
    // gabo skip
    return;
    if (memory(_ds, 32323) != 0x39)             //jnz loc_1b0d
        goto loc_1b0d;
}

void sub_1b33()
{
    _push(_ds);                                 //push ds
loc_1b34:                                       //loc_1b34:
    _dx = 0x1fc1;                               //mov dx, 0x1fc1
    _ds = _dx;                                  //mov ds, dx
    _dx = 0xb800;                               //mov dx, 0xb800
    _es = _dx;                                  //mov es, dx
    _ax = 0x2000;                               //mov ax, 0x2000
    memory16(_ds, 0x4907) = _ax;                //mov [0x4907], ax
    sub_0797();                                 //call sub_0797
    _bx = 0x4642;                               //mov bx, 0x4642
    _di = 0x0004;                               //mov di, 0x4
    sub_1f7b();                                 //call sub_1f7b
    _di = 0x0647;                               //mov di, 0x647
    sub_1f7b();                                 //call sub_1f7b
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _cx = 0x01f4;                               //mov cx, 0x1f4
loc_1b5e:                                       //loc_1b5e:
    sub_07bb();                                 //call sub_07bb
    sub_0433();                                 //call sub_0433
    if (_flags.zero)                                //jz loc_1baa
        goto loc_1baa;
    if (--_cx)                                  //loop loc_1b5e
        goto loc_1b5e;
    sub_0797();                                 //call sub_0797
    _dx = 0x1fc1;                               //mov dx, 0x1fc1
    _ds = _dx;                                  //mov ds, dx
    _dx = 0xb800;                               //mov dx, 0xb800
    _es = _dx;                                  //mov es, dx
    _ax = 0x0000;                               //mov ax, 0x0
    memory16(_ds, 0x4905) = _ax;                //mov [0x4905], ax
    sub_0797();                                 //call sub_0797
    _bx = 0x47a1;                               //mov bx, 0x47a1
    _di = 0x0284;                               //mov di, 0x284
    sub_1f7b();                                 //call sub_1f7b
    _bx = 0x4888;                               //mov bx, 0x4888
    _di = 0x0c89;                               //mov di, 0xc89
    sub_1f7b();                                 //call sub_1f7b
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _cx = 0x01f4;                               //mov cx, 0x1f4
loc_1b9b:                                       //loc_1b9b:
    sub_07bb();                                 //call sub_07bb
    sub_0433();                                 //call sub_0433
    if (_flags.zero)                                //jz loc_1baa
        goto loc_1baa;
    if (--_cx)                                  //loop loc_1b9b
        goto loc_1b9b;
    goto loc_1b34;                              //jmp loc_1b34
loc_1baa:                                       //loc_1baa:
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_1bae()
{
    _ax = memory16(_ds, 0x9720);                //mov ax, [0x9720]
    _bx = _ax;                                  //mov bx, ax
    _bx &= 0x0003;                              //and bx, 0x3
    _bx += _bx;                                 //add bx, bx
    _flags.carry = (_bx + 0x9661) >= 0x10000;
    _bx += 0x9661;                              //add bx, 0x9661
    _cx = memory16(_ds, _bx);                   //mov cx, word ptr [bx]
    _rcr(_ax, 1); //rcr ax, 1
    _rcr(_ax, 1);                               //rcr ax, 1
    _ax &= 0x0003;                              //and ax, 0x3
    _di = 0x03d0;                               //mov di, 0x3d0
    _di += _ax;                                 //add di, ax
    _ax = memory16(_ds, 0x9724);                //mov ax, [0x9724]
    _dx = 0x0050;                               //mov dx, 0x50
    _mul(_dx);                                  //mul dx
    _di += _ax;                                 //add di, ax
    _bl = memory(_ds, 38696);                   //mov bl, byte ptr [0x9728]
    _bh = 0;                                    //sub bh, bh
    _bx += _bx;                                 //add bx, bx
    _bx += 0x0100;                              //add bx, 0x100
    _si = memory16(_ds, _bx);                   //mov si, word ptr [bx]
    _push(_ds);                                 //push ds
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _ax = 0x0001;                               //mov ax, 0x1
    _out(_dx, _ax);                             //out dx, ax
    _al = 0x03;                                 //mov al, 0x3
    _out(_dx, _ax);                             //out dx, ax
    _al = 0x05;                                 //mov al, 0x5
    _out(_dx, _ax);                             //out dx, ax
    _ds = _cx;                                  //mov ds, cx
    _cx = 0x0015;                               //mov cx, 0x15
loc_1bf5:                                       //loc_1bf5:
    sub_1c15();                                 //call sub_1c15
    sub_1c15();                                 //call sub_1c15
    _di += 0x0024;                              //add di, 0x24
    if (--_cx)                                  //loop loc_1bf5
        goto loc_1bf5;
    _ax = 0x0f02;                               //mov ax, 0xf02
    _out(_dx, _ax);                             //out dx, ax
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _ax = 0x0105;                               //mov ax, 0x105
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0001;                               //mov ax, 0x1
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0xff08;                               //mov ax, 0xff08
    _out(_dx, _ax);                             //out dx, ax
    _ds = _pop();                               //pop ds
}

void sub_1c15()
{
    _di += 1;                                   //inc di
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _lodsw<MemData, DirForward>();              //lodsw
    _al = (~_al);                               //not al
    _ah = _al;                                  //mov ah, al
    _al = 0x08;                                 //mov al, 0x8
    _out(_dx, _ax);                             //out dx, ax
    _dx = 0x03c4;                               //mov dx, 0x3c4
    _ax = 0x0f02;                               //mov ax, 0xf02
    _out(_dx, _ax);                             //out dx, ax
    _ah = memoryVideoGet(_es, _di);                     //mov ah, byte ptr es:[di]
    _ah = 0x01;                                 //mov ah, 0x1
    _out(_dx, _ax);                             //out dx, ax
    _lodsw<MemData, DirForward>();              //lodsw
    memoryVideoSet(_es, _di, _al);                     //mov byte ptr es:[di], al
    _ax = 0x0202;                               //mov ax, 0x202
    _out(_dx, _ax);                             //out dx, ax
    _lodsw<MemData, DirForward>();              //lodsw
    memoryVideoSet(_es, _di, _al);                     //mov byte ptr es:[di], al
    _ax = 0x0402;                               //mov ax, 0x402
    _out(_dx, _ax);                             //out dx, ax
    _lodsw<MemData, DirForward>();              //lodsw
    memoryVideoSet(_es, _di, _al);                     //mov byte ptr es:[di], al
    _ax = 0x0802;                               //mov ax, 0x802
    _out(_dx, _ax);                             //out dx, ax
    _lodsw<MemData, DirForward>();              //lodsw
    memoryVideoSet(_es, _di, _al);                     //mov byte ptr es:[di], al
    _di -= 1;                                   //dec di
    _si -= 0x0009;                              //sub si, 0x9
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _lodsw<MemData, DirForward>();              //lodsw
    _al = (~_al);                               //not al
    _ah = _al;                                  //mov ah, al
    _al = 0x08;                                 //mov al, 0x8
    _out(_dx, _ax);                             //out dx, ax
    _dx = 0x03c4;                               //mov dx, 0x3c4
    _ax = 0x0f02;                               //mov ax, 0xf02
    _out(_dx, _ax);                             //out dx, ax
    _ah = memoryVideoGet(_es, _di);                     //mov ah, byte ptr es:[di]
    _ah = 0x01;                                 //mov ah, 0x1
    _out(_dx, _ax);                             //out dx, ax
    _lodsw<MemData, DirForward>();              //lodsw
    memoryVideoSet(_es, _di, _al);                     //mov byte ptr es:[di], al
    _ax = 0x0202;                               //mov ax, 0x202
    _out(_dx, _ax);                             //out dx, ax
    _lodsw<MemData, DirForward>();              //lodsw
    memoryVideoSet(_es, _di, _al);                     //mov byte ptr es:[di], al
    _ax = 0x0402;                               //mov ax, 0x402
    _out(_dx, _ax);                             //out dx, ax
    _lodsw<MemData, DirForward>();              //lodsw
    memoryVideoSet(_es, _di, _al);                     //mov byte ptr es:[di], al
    _ax = 0x0802;                               //mov ax, 0x802
    _out(_dx, _ax);                             //out dx, ax
    _lodsb<MemData, DirForward>();              //lodsb
    _stosb<MemVideo, DirForward>();              //stosb
    _di += 1;                                   //inc di
}

void sub_1c82()
{
    _bx = memory16(_ds, 38686);                 //mov bx, word ptr [0x971e]
    _bx += _bx;                                 //add bx, bx
    _bx += 0x974c;                              //add bx, 0x974c
    _ax = memory16(_ds, _bx);                   //mov ax, word ptr [bx]
    memory16(_ds, 0x972a) = _ax;                //mov [0x972a], ax
    memory16(_ds, 38704) = 0x0000;              //mov word ptr [0x9730], 0x0
    _bx = _ax;                                  //mov bx, ax
    _ax = memory16(_ds, _bx);                   //mov ax, word ptr [bx]
    memory16(_ds, 0x9720) = _ax;                //mov [0x9720], ax
    _ax = memory16(_ds, _bx + 2);               //mov ax, word ptr [bx+0x2]
    memory16(_ds, 0x9724) = _ax;                //mov [0x9724], ax
    _bx += 0x0004;                              //add bx, 0x4
    memory16(_ds, 38702) = _bx;                 //mov word ptr [0x972e], bx
    sub_1cb3();                                 //call sub_1cb3
    memory(_ds, 38704) -= 1;                    //dec byte ptr [0x9730]
}

void sub_1cb3()
{
    _bx = memory16(_ds, 38702);                 //mov bx, word ptr [0x972e]
    _ax = memory16(_ds, _bx);                   //mov ax, word ptr [bx]
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz loc_1ce3
        goto loc_1ce3;
    memory16(_ds, 0x972c) = _ax;                //mov [0x972c], ax
    _ax = memory16(_ds, _bx + 2);               //mov ax, word ptr [bx+0x2]
    memory16(_ds, 0x9722) = _ax;                //mov [0x9722], ax
    _ax = memory16(_ds, _bx + 4);               //mov ax, word ptr [bx+0x4]
    memory16(_ds, 0x9726) = _ax;                //mov [0x9726], ax
    _ax = memory16(_ds, _bx + 6);               //mov ax, word ptr [bx+0x6]
    memory16(_ds, 0x9732) = _ax;                //mov [0x9732], ax
    _bx += 0x0008;                              //add bx, 0x8
    memory16(_ds, 38702) = _bx;                 //mov word ptr [0x972e], bx
    memory16(_ds, 38708) = 0x0000;              //mov word ptr [0x9734], 0x0
    return;                                     //ret
loc_1ce3:                                       //loc_1ce3:
    memory16(_ds, 0x9730) = _ax;                //mov [0x9730], ax
}

void sub_1ce7()
{
    if (memory16(_ds, 38704) == 0x0000)         //jz sub_1d30
        { sub_1d30(); return; }
    _ah = 0;                                    //sub ah, ah
    _bx = memory16(_ds, 38708);                 //mov bx, word ptr [0x9734]
    _si = memory16(_ds, 38706);                 //mov si, word ptr [0x9732]
    _al = memory(_ds, _bx + _si);               //mov al, byte ptr [bx+si]
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz loc_1d09
        goto loc_1d09;
    memory16(_ds, 0x9734) = _ax;                //mov [0x9734], ax
    _ax = memory16(_ds, _si);                   //mov ax, word ptr [si]
loc_1d09:                                       //loc_1d09:
    memory16(_ds, 0x9728) = _ax;                //mov [0x9728], ax
    memory16(_ds, 38708) += 1;                  //inc word ptr [0x9734]
    _ax = memory16(_ds, 0x9720);                //mov ax, [0x9720]
    _ax = _ax + memory16(_ds, 38690);           //add ax, word ptr [0x9722]
    memory16(_ds, 0x9720) = _ax;                //mov [0x9720], ax
    _ax = memory16(_ds, 0x9724);                //mov ax, [0x9724]
    _ax = _ax + memory16(_ds, 38694);           //add ax, word ptr [0x9726]
    memory16(_ds, 0x9724) = _ax;                //mov [0x9724], ax
    memory16(_ds, 38700) -= 1;                  //dec word ptr [0x972c]
    if (memory16(_ds, 38700) != 0)              //jnz sub_1d30
        { sub_1d30(); return; }
    sub_1cb3();                                 //call sub_1cb3
    sub_1d30();
}

void sub_1d30()
{
    _bx = memory16(_ds, 38686);                 //mov bx, word ptr [0x971e]
    _push(_ds);                                 //push ds
    _cx = 0x1fc1;                               //mov cx, 0x1fc1
    _ds = _cx;                                  //mov ds, cx
    _di = 0x03d0;                               //mov di, 0x3d0
    _cx = 0x0006;                               //mov cx, 0x6
    _bx += 0x4909;                              //add bx, 0x4909
    _dl = memory(_ds, _bx);                     //mov dl, byte ptr [bx]
loc_1d46:                                       //loc_1d46:
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _cx = 0x0006;                               //mov cx, 0x6
loc_1d4b:                                       //loc_1d4b:
    _al = _dl;                                  //mov al, dl
    sub_1fb1();                                 //call sub_1fb1
    _dl += 1;                                   //inc dl
    if (--_cx)                                  //loop loc_1d4b
        goto loc_1d4b;
    _di = _pop();                               //pop di
    _di += 0x0140;                              //add di, 0x140
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_1d46
        goto loc_1d46;
    _ds = _pop();                               //pop ds
}

void sub_1d5e()
{
    _al = memory(_ds, 0x971c);                  //mov al, [0x971c]
    _al += 1;                                   //inc al
    memory(_ds, 0x971c) = _al;                  //mov [0x971c], al
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ds = _pop();                               //pop ds
    _al &= 0x01;                                //and al, 0x1
    if (_al == 0)                               //jz loc_1d87
        goto loc_1d87;
    _dx = 0x0022;                               //mov dx, 0x22
    _si = 0x2828;                               //mov si, 0x2828
    _di = 0x0290;                               //mov di, 0x290
    sub_1d9e();                                 //call sub_1d9e
    _si = 0x2a00;                               //mov si, 0x2a00
    _di = 0x0b50;                               //mov di, 0xb50
    sub_1d9e();                                 //call sub_1d9e
    _ds = _pop();                               //pop ds
    return;                                     //ret
loc_1d87:                                       //loc_1d87:
    _dx = 0x0022;                               //mov dx, 0x22
    _si = 0x2a00;                               //mov si, 0x2a00
    _di = 0x0290;                               //mov di, 0x290
    sub_1d9e();                                 //call sub_1d9e
    _si = 0x2830;                               //mov si, 0x2830
    _di = 0x0b50;                               //mov di, 0xb50
    sub_1d9e();                                 //call sub_1d9e
    _ds = _pop();                               //pop ds
}

void sub_1d9e()
{
    _cx = 0x0008;                               //mov cx, 0x8
loc_1da1:                                       //loc_1da1:
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _stosb<MemVideo, DirForward>();              //stosb
    _stosb<MemVideo, DirForward>();              //stosb
    _stosb<MemVideo, DirForward>();              //stosb
    _stosb<MemVideo, DirForward>();              //stosb
    _stosb<MemVideo, DirForward>();              //stosb
    _di += _dx;                                 //add di, dx
    if (--_cx)                                  //loop loc_1da1
        goto loc_1da1;
}

void sub_1dac()
{
    _al = memory(_ds, 0x971c);                  //mov al, [0x971c]
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ds = _pop();                               //pop ds
    _al &= 0x02;                                //and al, 0x2
    if (_al == 0)                               //jz loc_1dd0
        goto loc_1dd0;
    _dx = 0x0028;                               //mov dx, 0x28
    _si = 0x2820;                               //mov si, 0x2820
    _di = 0x028f;                               //mov di, 0x28f
    sub_1de7();                                 //call sub_1de7
    _si = 0x2820;                               //mov si, 0x2820
    _di = 0x0296;                               //mov di, 0x296
    sub_1de7();                                 //call sub_1de7
    _ds = _pop();                               //pop ds
    return;                                     //ret
loc_1dd0:                                       //loc_1dd0:
    _dx = 0x0028;                               //mov dx, 0x28
    _si = 0x2958;                               //mov si, 0x2958
    _di = 0x028f;                               //mov di, 0x28f
    sub_1de7();                                 //call sub_1de7
    _si = 0x2958;                               //mov si, 0x2958
    _di = 0x0296;                               //mov di, 0x296
    sub_1de7();                                 //call sub_1de7
    _ds = _pop();                               //pop ds
}

void sub_1de7()
{
    _cx = 0x0008;                               //mov cx, 0x8
loc_1dea:                                       //loc_1dea:
    _lodsb<MemVideo, DirForward>();              //lodsb
    memoryVideoSet(_ds, _di, _al);                     //mov byte ptr [di], al
    memoryVideoSet(_ds, _di + 320, _al);               //mov byte ptr [di+0x140], al
    memoryVideoSet(_ds, _di + 640, _al);               //mov byte ptr [di+0x280], al
    memoryVideoSet(_ds, _di + 960, _al);               //mov byte ptr [di+0x3c0], al
    memoryVideoSet(_ds, _di + 1280, _al);              //mov byte ptr [di+0x500], al
    memoryVideoSet(_ds, _di + 1600, _al);              //mov byte ptr [di+0x640], al
    memoryVideoSet(_ds, _di + 1920, _al);              //mov byte ptr [di+0x780], al
    memoryVideoSet(_ds, _di + 2240, _al);              //mov byte ptr [di+0x8c0], al
    _di += _dx;                                 //add di, dx
    if (--_cx)                                  //loop loc_1dea
        goto loc_1dea;
}

void sub_1e0e()
{
    _push(_ds);                                 //push ds
    _al = 0x00;                                 //mov al, 0x0
    memory(_ds, 0x48f4) = _al;                  //mov [0x48f4], al
    memory(_ds, 0x48f5) = _al;                  //mov [0x48f5], al
    memory(_ds, 0x48f6) = _al;                  //mov [0x48f6], al
    _dx = 0x1fc1;                               //mov dx, 0x1fc1
    _ds = _dx;                                  //mov ds, dx
    _es = _dx;                                  //mov es, dx
    _cx = 0x000a;                               //mov cx, 0xa
    _di = 0x48fb;                               //mov di, 0x48fb
    _al = 0x3b;                                 //mov al, 0x3b
    _rep_stosb<MemData, DirForward>();          //rep stosb
    _dx = 0xa000;                               //mov dx, 0xa000
    _es = _dx;                                  //mov es, dx
    _ax = 0x2000;                               //mov ax, 0x2000
    memory16(_ds, 0x4907) = _ax;                //mov [0x4907], ax
    sub_0797();                                 //call sub_0797
    _bx = 0x457d;                               //mov bx, 0x457d
    _di = 0x0004;                               //mov di, 0x4
    sub_1f7b();                                 //call sub_1f7b
    _di = 0x0649;                               //mov di, 0x649
    sub_1f89();                                 //call sub_1f89
    _di = 0x0a0e;                               //mov di, 0xa0e
    sub_1f7b();                                 //call sub_1f7b
    _di = 0x17cf;                               //mov di, 0x17cf
    sub_1f89();                                 //call sub_1f89
    _ax = 0x1040;                               //mov ax, 0x1040
    _es = _ax;                                  //mov es, ax
loc_1e59:                                       //loc_1e59:
    sub_07bb();                                 //call sub_07bb
    sub_07bb();                                 //call sub_07bb
    sub_07bb();                                 //call sub_07bb
    sub_07bb();                                 //call sub_07bb
    if (memory(_ds, 18678) == 0x0a)             //jz loc_1e74
        goto loc_1e74;
    sub_1e76();                                 //call sub_1e76
    goto loc_1e59;                              //jmp loc_1e59
loc_1e74:                                       //loc_1e74:
    _ds = _pop();                               //pop ds
}

void sub_1e76()
{
    _al = memory(_es, 32324);                   //mov al, es:[0x7e44]
    _bx = memory16(_ds, 18676);                 //mov bx, word ptr [0x48f4]
    if (!(_al & 0x10))                          //jz loc_1e88
        goto loc_1e88;
    goto loc_1f17;                              //jmp loc_1f17
loc_1e88:                                       //loc_1e88:
    if (!(_al & 0x01))                          //jz loc_1e9b
        goto loc_1e9b;
    _bl += 1;                                   //inc bl
    if (_bl != 0x06)                            //jnz loc_1e9b
        goto loc_1e9b;
    _bl = 0x05;                                 //mov bl, 0x5
loc_1e9b:                                       //loc_1e9b:
    if (!(_al & 0x02))                          //jz loc_1eab
        goto loc_1eab;
    _bl -= 1;                                   //dec bl
    if ((char)_bl >= 0)                         //jns loc_1eab
        goto loc_1eab;
    _bl = 0x00;                                 //mov bl, 0x0
loc_1eab:                                       //loc_1eab:
    if (!(_al & 0x04))                          //jz loc_1ebe
        goto loc_1ebe;
    _bh += 1;                                   //inc bh
    if (_bh != 0x05)                            //jnz loc_1ebe
        goto loc_1ebe;
    _bh = 0x04;                                 //mov bh, 0x4
loc_1ebe:                                       //loc_1ebe:
    if (!(_al & 0x08))                          //jz loc_1ece
        goto loc_1ece;
    _bh -= 1;                                   //dec bh
    if ((char)_bh >= 0)                         //jns loc_1ece
        goto loc_1ece;
    _bh = 0x00;                                 //mov bh, 0x0
loc_1ece:                                       //loc_1ece:
    memory16(_ds, 18676) = _bx;                 //mov word ptr [0x48f4], bx
    _bx = memory16(_ds, 18676);                 //mov bx, word ptr [0x48f4]
    _bh += _bh;                                 //add bh, bh
    _al = _bh;                                  //mov al, bh
    _al += _al;                                 //add al, al
    _al += _bh;                                 //add al, bh
    _al += _bl;                                 //add al, bl
    _ah = 0x00;                                 //mov ah, 0x0
    _bx = 0x48d6;                               //mov bx, 0x48d6
    _bx += _ax;                                 //add bx, ax
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    memory(_ds, 0x48f7) = _al;                  //mov [0x48f7], al
    _di = memory16(_ds, 18680);                 //mov di, word ptr [0x48f8]
    _al = 0x40;                                 //mov al, 0x40
    sub_1fa0();                                 //call sub_1fa0
    _bx = memory16(_ds, 18676);                 //mov bx, word ptr [0x48f4]
    _al = _bh;                                  //mov al, bh
    _ah = 0x00;                                 //mov ah, 0x0
    _dx = 0x0280;                               //mov dx, 0x280
    _mul(_dx);                                  //mul dx
    _bl += _bl;                                 //add bl, bl
    _bh = 0x00;                                 //mov bh, 0x0
    _di = 0x0b4e;                               //mov di, 0xb4e
    _di += _ax;                                 //add di, ax
    _di += _bx;                                 //add di, bx
    memory16(_ds, 18680) = _di;                 //mov word ptr [0x48f8], di
    _al = 0x3e;                                 //mov al, 0x3e
    sub_1fa0();                                 //call sub_1fa0
    return;                                     //ret
loc_1f17:                                       //loc_1f17:
    _push(_es);                                 //push es
    _ax = 0xa000;                               //mov ax, 0xa000
    _es = _ax;                                  //mov es, ax
    _al = memory(_ds, 0x48f7);                  //mov al, [0x48f7]
    if (_al != 0x3d)                            //jnz loc_1f2f
        goto loc_1f2f;
    memory(_ds, 18678) = 0x0a;                  //mov byte ptr [0x48f6], 0xa
    goto loc_1f71;                              //jmp loc_1f71
    _STOP_("db 90h");                           //db 90h
loc_1f2f:                                       //loc_1f2f:
    if (_al != 0x3c)                            //jnz loc_1f51
        goto loc_1f51;
    if (memory(_ds, 18678) == 0x00)             //jz loc_1f71
        goto loc_1f71;
    memory(_ds, 18678) -= 1;                    //dec byte ptr [0x48f6]
    _bl = memory(_ds, 18678);                   //mov bl, byte ptr [0x48f6]
    _al = 0x3b;                                 //mov al, 0x3b
    memory(_ds, 18678) -= 1;                    //dec byte ptr [0x48f6]
    goto loc_1f55;                              //jmp loc_1f55
    _STOP_("db 90h");                           //db 90h
loc_1f51:                                       //loc_1f51:
    _bl = memory(_ds, 18678);                   //mov bl, byte ptr [0x48f6]
loc_1f55:                                       //loc_1f55:
    _bh = _al;                                  //mov bh, al
    _push(_bx);                                 //push bx
    _bh = 0;                                    //sub bh, bh
    _di = 0x17cf;                               //mov di, 0x17cf
    _di += _bx;                                 //add di, bx
    sub_1fb1();                                 //call sub_1fb1
    _bx = _pop();                               //pop bx
    _al = _bh;                                  //mov al, bh
    _bh = 0;                                    //sub bh, bh
    _bx += 0x48fb;                              //add bx, 0x48fb
    memory(_ds, _bx) = _al;                     //mov byte ptr [bx], al
    memory(_ds, 18678) += 1;                    //inc byte ptr [0x48f6]
loc_1f71:                                       //loc_1f71:
    _es = _pop();                               //pop es
loc_1f72:                                       //loc_1f72:
    if (memory(_es, 32324) & 0x10)              //jnz loc_1f72
        goto loc_1f72;
}

void sub_1f7b()
{
loc_1f7b:
    _push(_di);                                 //push di
    sub_1f89();                                 //call sub_1f89
    _di = _pop();                               //pop di
    _di += 0x0140;                              //add di, 0x140
    if (_al != 0xfe)                            //jnz sub_1f7b
        goto loc_1f7b;
}

void sub_1f89()
{
loc_1f89:
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    _bx += 1;                                   //inc bx
    if (_al == 0xff)                            //jz loc_1f9f
        goto loc_1f9f;
    if (_al == 0xfe)                            //jz loc_1f9f
        goto loc_1f9f;
    sub_1fa0();                                 //call sub_1fa0
    goto loc_1f89;                              //jmp sub_1f89
loc_1f9f:                                       //loc_1f9f:
    return;
}

void sub_1fa0()
{
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_dx);                                 //push dx
    _dx = 0xa000;                               //mov dx, 0xa000
    _es = _dx;                                  //mov es, dx
    _ds = _dx;                                  //mov ds, dx
    _dx = _pop();                               //pop dx
    sub_1fb1();                                 //call sub_1fb1
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_1fb1()
{
    _push(_es);                                 //push es
    _push(_ds);                                 //push ds
    _push(_di);                                 //push di
    _push(_cx);                                 //push cx
    _cx = 0x1fc1;                               //mov cx, 0x1fc1
    _ds = _cx;                                  //mov ds, cx
    _cx = memory16(_ds, 18695);                 //mov cx, word ptr [0x4907]
    _push(_es);                                 //push es
    _ds = _pop();                               //pop ds
    _ah = 0x00;                                 //mov ah, 0x0
    _ax += _ax;                                 //add ax, ax
    _ax += _ax;                                 //add ax, ax
    _ax += _ax;                                 //add ax, ax
    _ax += _cx;                                 //add ax, cx
    _si = _ax;                                  //mov si, ax
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += 0x0027;                              //add di, 0x27
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += 0x0027;                              //add di, 0x27
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += 0x0027;                              //add di, 0x27
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += 0x0027;                              //add di, 0x27
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += 0x0027;                              //add di, 0x27
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += 0x0027;                              //add di, 0x27
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += 0x0027;                              //add di, 0x27
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _cx = _pop();                               //pop cx
    _di = _pop();                               //pop di
    _di += 1;                                   //inc di
    _ds = _pop();                               //pop ds
    _es = _pop();                               //pop es
}

void sub_1fef()
{
    _push(_ds);                                 //push ds
    _ax = 0x1fc1;                               //mov ax, 0x1fc1
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _di = 0x4785;                               //mov di, 0x4785
    _si = 0x4769;                               //mov si, 0x4769
loc_1ffd:                                       //loc_1ffd:
    if (_si == _bx)                             //jz loc_2011
        goto loc_2011;
    _cx = 0x000d;                               //mov cx, 0xd
    _rep_movsw<MemData, MemData, DirForward>(); //rep movsw
    _di -= 0x0036;                              //sub di, 0x36
    _si -= 0x0036;                              //sub si, 0x36
    goto loc_1ffd;                              //jmp loc_1ffd
loc_2011:                                       //loc_2011:
    _cx = 0x000d;                               //mov cx, 0xd
    _rep_movsw<MemData, MemData, DirForward>(); //rep movsw
    _ax = memory16(_ds, 0x490e);                //mov ax, [0x490e]
    memory16(_ds, _bx) = _ax;                   //mov word ptr [bx], ax
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _ax = memory16(_ds, 0x4910);                //mov ax, [0x4910]
    memory16(_ds, _bx) = _ax;                   //mov word ptr [bx], ax
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _ax = memory16(_ds, 0x4912);                //mov ax, [0x4912]
    memory16(_ds, _bx) = _ax;                   //mov word ptr [bx], ax
    _bx += 0x000c;                              //add bx, 0xc
    _di = _bx;                                  //mov di, bx
    _si = 0x48fb;                               //mov si, 0x48fb
    _cx = 0x000a;                               //mov cx, 0xa
    _rep_movsb<MemData, MemData, DirForward>(); //rep movsb
    _ds = _pop();                               //pop ds
}

void sub_2038()
{
    _ax = 0x1fc1;                               //mov ax, 0x1fc1
    _ds = _ax;                                  //mov ds, ax
    _si = 0x46a5;                               //mov si, 0x46a5
    _cx = 0x0008;                               //mov cx, 0x8
loc_2043:                                       //loc_2043:
    _di = 0x490e;                               //mov di, 0x490e
    _al = memory(_ds, _si);                     //mov al, byte ptr [si]
    if (_al < memory(_ds, _di))                 //jc loc_207b
        goto loc_207b;
    if (_al != memory(_ds, _di))                //jnz loc_206f
        goto loc_206f;
    _push(_si);                                 //push si
    _bx = 0x0005;                               //mov bx, 0x5
loc_2058:                                       //loc_2058:
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    _al = memory(_ds, _si);                     //mov al, byte ptr [si]
    if (_al < memory(_ds, _di))                 //jc loc_207a
        goto loc_207a;
    if (_al != memory(_ds, _di))                //jnz loc_206e
        goto loc_206e;
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz loc_2058
        goto loc_2058;
    goto loc_207a;                              //jmp loc_207a
    _STOP_("db 90h");                           //db 90h
loc_206e:                                       //loc_206e:
    _si = _pop();                               //pop si
loc_206f:                                       //loc_206f:
    _si += 0x001c;                              //add si, 0x1c
    if (--_cx)                                  //loop loc_2043
        goto loc_2043;
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    return;                                     //ret
loc_207a:                                       //loc_207a:
    _si = _pop();                               //pop si
loc_207b:                                       //loc_207b:
    _push(_si);                                 //push si
    sub_1e0e();                                 //call sub_1e0e
    _bx = _pop();                               //pop bx
    sub_1fef();                                 //call sub_1fef
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
}

void sub_2089()
{
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _di = memory16(_ds, 32100);                 //mov di, word ptr [0x7d64]
loc_2094:                                       //loc_2094:
    _al = memory(_ds, _di);                     //mov al, byte ptr [di]
    if (_al != 0xff)                            //jnz loc_209e
        goto loc_209e;
    return;                                     //ret
loc_209e:                                       //loc_209e:
    if (_al >= _dh)                             //jnc loc_20aa
        goto loc_20aa;
    _di += 0x0005;                              //add di, 0x5
    goto loc_2094;                              //jmp loc_2094
loc_20aa:                                       //loc_20aa:
    _dh += _dl;                                 //add dh, dl
loc_20ac:                                       //loc_20ac:
    _al = memory(_ds, _di);                     //mov al, byte ptr [di]
    if (_al != 0xff)                            //jnz loc_20b6
        goto loc_20b6;
    return;                                     //ret
loc_20b6:                                       //loc_20b6:
    if (_al < _dh)                              //jc loc_20be
        goto loc_20be;
    return;                                     //ret
loc_20be:                                       //loc_20be:
    _push(_dx);                                 //push dx
    _al &= 0xf8;                                //and al, 0xf8
    _dl = _al;                                  //mov dl, al
    _al = memory(_ds, _di + 1);                 //mov al, byte ptr [di+0x1]
    _flags.sign = !!(_al & 0x80);                                    //and al, al
    _al &= _al;
    if (!_flags.sign)                           //jns loc_20d0
        goto loc_20d0;
    goto loc_21de;                              //jmp loc_21de
loc_20d0:                                       //loc_20d0:
    if (!(memory(_ds, _di + 2) & 0x02))         //jz loc_20f0
        goto loc_20f0;
    if (memory(_ds, 32334) == 0x00)             //jz loc_20e6
        goto loc_20e6;
    goto loc_21de;                              //jmp loc_21de
loc_20e6:                                       //loc_20e6:
    _si = 0x7e4e;                               //mov si, 0x7e4e
    memory(_ds, _si + 38) = 0x00;               //mov byte ptr [si+0x26], 0x0
    goto loc_210d;                              //jmp loc_210d
    _STOP_("db 90h");                           //db 90h
loc_20f0:                                       //loc_20f0:
    if (_al >= 0x10)                            //jnc loc_2102
        goto loc_2102;
    sub_2205();                                 //call sub_2205
    if (_flags.zero)                                //jz loc_210d
        goto loc_210d;
    goto loc_21de;                              //jmp loc_21de
loc_2102:                                       //loc_2102:
    sub_21e5();                                 //call sub_21e5
    if (_flags.zero)                                //jz loc_210d
        goto loc_210d;
    goto loc_21de;                              //jmp loc_21de
loc_210d:                                       //loc_210d:
    memory(_ds, _si) = _al;                     //mov byte ptr [si], al
    _al = memory(_ds, _di + 3);                 //mov al, byte ptr [di+0x3]
    _dh = _al;                                  //mov dh, al
    _al &= 0xf8;                                //and al, 0xf8
    memory(_ds, _si + 2) = _al;                 //mov byte ptr [si+0x2], al
    memory(_ds, _si + 28) = _al;                //mov byte ptr [si+0x1c], al
    _dh &= 0x07;                                //and dh, 0x7
    _dl = _dl - memory(_ds, 32312);             //sub dl, byte ptr [0x7e38]
    _dl += _dh;                                 //add dl, dh
    _dh = 0;                                    //sub dh, dh
    _dx += _dx;                                 //add dx, dx
    _dx += _dx;                                 //add dx, dx
    _dx += _dx;                                 //add dx, dx
    if (memory(_ds, _di + 2) & 0x02)            //jnz loc_2139
        goto loc_2139;
    _dx += 0x0003;                              //add dx, 0x3
loc_2139:                                       //loc_2139:
    memory16(_ds, _si + 4) = _dx;               //mov word ptr [si+0x4], dx
    memory16(_ds, _si + 30) = _dx;              //mov word ptr [si+0x1e], dx
    memory16(_ds, _si + 12) = 0x0000;           //mov word ptr [si+0xc], 0x0
    _bl = memory(_ds, _di + 1);                 //mov bl, byte ptr [di+0x1]
    _bh = 0;                                    //sub bh, bh
    _bx += _bx;                                 //add bx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += 0x9326;                              //add bx, 0x9326
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    memory(_ds, _si + 14) = _al;                //mov byte ptr [si+0xe], al
    _bx += 1;                                   //inc bx
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    memory(_ds, _si + 16) = _al;                //mov byte ptr [si+0x10], al
    _bx += 1;                                   //inc bx
    _ax = memory16(_ds, _bx);                   //mov ax, word ptr [bx]
    memory16(_ds, _si + 32) = _ax;              //mov word ptr [si+0x20], ax
    memory(_ds, _si + 8) = _al;                 //mov byte ptr [si+0x8], al
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _ax = memory16(_ds, _bx);                   //mov ax, word ptr [bx]
    memory16(_ds, _si + 34) = _ax;              //mov word ptr [si+0x22], ax
    memory16(_ds, _si + 18) = _di;              //mov word ptr [si+0x12], di
    _al = memory(_ds, _di + 2);                 //mov al, byte ptr [di+0x2]
    memory(_ds, _si + 20) = _al;                //mov byte ptr [si+0x14], al
    if (!(_al & 0x04))                          //jz loc_2181
        goto loc_2181;
    memory(_ds, _si) |= 0x80;                   //or byte ptr [si], 0x80
loc_2181:                                       //loc_2181:
    _al = memory(_ds, _di + 2);                 //mov al, byte ptr [di+0x2]
    _al &= 0xf0;                                //and al, 0xf0
    if (_al != 0xf0)                            //jnz loc_219b
        goto loc_219b;
    if (_si < 0x7ffe)                           //jc loc_219b
        goto loc_219b;
    _cl = memory(_ds, _bx);                     //mov cl, byte ptr [bx]
    memory(_ds, _si + 32) = _cl;                //mov byte ptr [si+0x20], cl
loc_219b:                                       //loc_219b:
    _al = memory(_ds, _di + 4);                 //mov al, byte ptr [di+0x4]
    _dl = _al;                                  //mov dl, al
    _al &= 0xf8;                                //and al, 0xf8
    memory(_ds, _si + 22) = _al;                //mov byte ptr [si+0x16], al
    _dl &= 0x07;                                //and dl, 0x7
    _al = _dl;                                  //mov al, dl
    _al += _al;                                 //add al, al
    _al += _al;                                 //add al, al
    _al += _al;                                 //add al, al
    _al += _al;                                 //add al, al
    _al += _al;                                 //add al, al
    memory(_ds, _si + 46) = _al;                //mov byte ptr [si+0x2e], al
    _bl = memory(_ds, 32312);                   //mov bl, byte ptr [0x7e38]
    _al = memory(_ds, _di);                     //mov al, byte ptr [di]
    _al &= 0xf8;                                //and al, 0xf8
    _al -= _bl;                                 //sub al, bl
    _al += _dl;                                 //add al, dl
    _ah = 0;                                    //sub ah, ah
    _ax += _ax;                                 //add ax, ax
    _ax += _ax;                                 //add ax, ax
    _ax += _ax;                                 //add ax, ax
    _ax += 0x0003;                              //add ax, 0x3
    memory16(_ds, _si + 24) = _ax;              //mov word ptr [si+0x18], ax
    memory(_ds, _si + 40) = 0x00;               //mov byte ptr [si+0x28], 0x0
    memory(_ds, _si + 42) = 0x00;               //mov byte ptr [si+0x2a], 0x0
    memory16(_ds, _si + 44) = 0x0000;           //mov word ptr [si+0x2c], 0x0
loc_21de:                                       //loc_21de:
    _dx = _pop();                               //pop dx
    _di += 0x0005;                              //add di, 0x5
    goto loc_20ac;                              //jmp loc_20ac
}

void sub_21e5()
{
    _push(_ax);                                 //push ax
    _si = 0x7f0e;                               //mov si, 0x7f0e
    _cx = 0x0005;                               //mov cx, 0x5
    _ax = 0;                                    //sub ax, ax
loc_21ee:                                       //loc_21ee:
    if (_ax != memory16(_ds, _si))              //jnz loc_21fb
        goto loc_21fb;
    _ax = _pop();                               //pop ax
    memory(_ds, _si + 38) = 0x00;               //mov byte ptr [si+0x26], 0x0
    _flags.zero = true;
    return;                                     //ret
loc_21fb:                                       //loc_21fb:
    _si += 0x0030;                              //add si, 0x30
    if (--_cx)                                  //loop loc_21ee
        goto loc_21ee;
    _ax = 0;                                    //sub ax, ax
    _ax += 1;                                   //inc ax
    _ax = _pop();                               //pop ax
    _flags.zero = false;
}

void sub_2205()
{
    _push(_ax);                                 //push ax
    _si = 0x7ffe;                               //mov si, 0x7ffe
    _cx = 0x0003;                               //mov cx, 0x3
    _ax = 0;                                    //sub ax, ax
loc_220e:                                       //loc_220e:
    if (_al == memory(_ds, _si))                //jz loc_221d
        goto loc_221d;
    if (_di == memory16(_ds, _si + 18))         //jz loc_223c
        goto loc_223c;
loc_221d:                                       //loc_221d:
    _si += 0x0030;                              //add si, 0x30
    if (--_cx)                                  //loop loc_220e
        goto loc_220e;
    _si = 0x7ffe;                               //mov si, 0x7ffe
    _cx = 0x0003;                               //mov cx, 0x3
    _ax = 0;                                    //sub ax, ax
loc_222a:                                       //loc_222a:
    if (_ax != memory16(_ds, _si))              //jnz loc_2237
        goto loc_2237;
    _ax = _pop();                               //pop ax
    memory(_ds, _si + 38) = 0x02;               //mov byte ptr [si+0x26], 0x2
    _flags.zero = true;
    return;                                     //ret
loc_2237:                                       //loc_2237:
    _si += 0x0030;                              //add si, 0x30
    if (--_cx)                                  //loop loc_222a
        goto loc_222a;
loc_223c:                                       //loc_223c:
    _ax = 0;                                    //sub ax, ax
    _ax += 1;                                   //inc ax
    _flags.zero = false;
    _ax = _pop();                               //pop ax
}

void sub_2241()
{
    _ax = 0x1040;                               //mov ax, 0x1040
    _ds = _ax;                                  //mov ds, ax
    _si = 0x7e4e;                               //mov si, 0x7e4e
loc_2249:                                       //loc_2249:
    _ax = memory16(_ds, _si);                   //mov ax, word ptr [si]
    _ax &= _ax;                                 //and ax, ax
    if (_ax == 0)                               //jz loc_225d
        goto loc_225d;
    if (_ax == 0x00ff)                          //jz loc_2262
        goto loc_2262;
    sub_2263();                                 //call sub_2263
loc_225d:                                       //loc_225d:
    _si += 0x0030;                              //add si, 0x30
    goto loc_2249;                              //jmp loc_2249
loc_2262:                                       //loc_2262:
    return;
}

void sub_2263()
{
    _bx = 0x1040;                               //mov bx, 0x1040
    _ds = _bx;                                  //mov ds, bx
    _es = _bx;                                  //mov es, bx
    _al &= 0x7f;                                //and al, 0x7f
    if (_al != 0x47)                            //jnz loc_2276
        goto loc_2276;
    sub_2440(0x2501);
    return;
loc_2276:                                       //loc_2276:
    if (_al < 0x18)                             //jc loc_2281
        goto loc_2281;
    sub_2669(0x268f);
    return;

    //_STOP_("goto loc_268f");                    //jmp loc_268f
    _STOP_("db c3h");                           //db c3h
loc_2281:                                       //loc_2281:
    _ah = 0;                                    //sub ah, ah
    _ax += _ax;                                 //add ax, ax
    _ax += 0x80bf;                              //add ax, 0x80bf
    _di = _ax;                                  //mov di, ax
    _indirectCall(memory16(_ds, _di));
}

void sub_228c()
{
    memory(_ds, _si + 8) = 0x00;                //mov byte ptr [si+0x8], 0x0
    if (memory(_ds, 32143) != 0x00)             //jnz loc_229b
        goto loc_229b;
    return;                                     //ret
loc_229b:                                       //loc_229b:
    _bl = memory(_ds, 32384);                   //mov bl, byte ptr [0x7e80]
    _bl += 0x0c;                                //add bl, 0xc
    _dx = memory16(_ds, 32386);                 //mov dx, word ptr [0x7e82]
    _dx += 0x000a;                              //add dx, 0xa
    sub_13ed();                                 //call sub_13ed
    if (_flags.zero)                                //jz loc_22b2
        goto loc_22b2;
    return;                                     //ret
loc_22b2:                                       //loc_22b2:
    memory(_ds, 32143) = 0x00;                  //mov byte ptr [0x7d8f], 0x0
    _push(_si);                                 //push si
    _si = 0x491c;                               //mov si, 0x491c
    sub_0292();                                 //call sub_0292
    _si = _pop();                               //pop si
    memory(_ds, _si) = 0x00;                    //mov byte ptr [si], 0x0
    _ax = 0x7df2;                               //mov ax, 0x7df2
    memory16(_ds, 0x7d9a) = _ax;                //mov [0x7d9a], ax
    {sub_2592(); return; };                     //
}

void sub_22cb()
{
    memory(_ds, _si + 8) = 0x00;                //mov byte ptr [si+0x8], 0x0
    _bl = memory(_ds, 32384);                   //mov bl, byte ptr [0x7e80]
    _bl += 0x0c;                                //add bl, 0xc
    _dx = memory16(_ds, 32386);                 //mov dx, word ptr [0x7e82]
    _dx += 0x000a;                              //add dx, 0xa
    sub_13ed();                                 //call sub_13ed
    if (_flags.zero)                                //jz loc_22e6
        goto loc_22e6;
    return;                                     //ret
loc_22e6:                                       //loc_22e6:
    memory(_ds, _si) = 0x00;                    //mov byte ptr [si], 0x0
    memory(_ds, 32143) = 0xff;                  //mov byte ptr [0x7d8f], 0xff
    memory(_ds, 32149) = 0x1e;                  //mov byte ptr [0x7d95], 0x1e
    _ax = 0x7df2;                               //mov ax, 0x7df2
    memory16(_ds, 0x7d9a) = _ax;                //mov [0x7d9a], ax
    _push(_ds);                                 //push ds
    _ax = 0x1fc1;                               //mov ax, 0x1fc1
    _ds = _ax;                                  //mov ds, ax
    memory16(_ds, 18716) = 0x0200;              //mov word ptr [0x491c], 0x200
    memory16(_ds, 18718) = 0x0000;              //mov word ptr [0x491e], 0x0
    memory16(_ds, 18719) = 0x0000;              //mov word ptr [0x491f], 0x0
    _ds = _pop();                               //pop ds
}

void sub_2313(int pc)
{
    if (pc == 0x2318)
        goto loc_2318;
    
    memory(_ds, 32142) = 0xff;                  //mov byte ptr [0x7d8e], 0xff
loc_2318:                                       //loc_2318:
    sub_238b();                                 //call sub_238b
    sub_13ac();                                 //call sub_13ac
    if (!_flags.zero)                                //jnz loc_2323
        goto loc_2323;
    sub_2440(0x24c4);                    //jmp loc_24c4
    return;
loc_2323:                                       //loc_2323:
    if (memory(_ds, 32430) == 0x00)             //jz loc_2352
        goto loc_2352;
    _bl = memory(_ds, 32432);                   //mov bl, byte ptr [0x7eb0]
    if (memory(_ds, 32135) & 0x80)              //jnz loc_233e
        goto loc_233e;
    _bl += 0x18;                                //add bl, 0x18
loc_233e:                                       //loc_233e:
    _dx = memory16(_ds, 32434);                 //mov dx, word ptr [0x7eb2]
    sub_1317();                                 //call sub_1317
    if (!_flags.zero)                                //jnz loc_2352
        goto loc_2352;
    memory(_ds, 32430) = 0x00;                  //mov byte ptr [0x7eae], 0x0
    sub_2440(0x24c4);                    //jmp loc_24c4
    return;
loc_2352:                                       //loc_2352:
    if (memory(_ds, 32133) == 0x00)             //jz loc_2364
        goto loc_2364;
    sub_134b();                                 //call sub_134b
    if (!_flags.zero)                                //jnz loc_2364
        goto loc_2364;
    sub_2440(0x24c4);                    //jmp loc_24c4
    return;
loc_2364:                                       //loc_2364:
    if (memory(_ds, 32106) == 0x00)             //jz loc_2382
        goto loc_2382;
    _bl = memory(_ds, 32123);                   //mov bl, byte ptr [0x7d7b]
    _dx = memory16(_ds, 32124);                 //mov dx, word ptr [0x7d7c]
    sub_1317();                                 //call sub_1317
    if (!_flags.zero)                                //jnz loc_2382
        goto loc_2382;
    memory(_ds, _si + 46) = 0x14;               //mov byte ptr [si+0x2e], 0x14
loc_2382:                                       //loc_2382:
    sub_12ae();                                 //call sub_12ae
    if (!_flags.zero)                                //jnz loc_238a
        goto loc_238a;
    {sub_19cf(); return; };                     //
loc_238a:                                       //loc_238a:
    return;
}

void sub_238b()
{
    _dl = memory(_ds, _si + 42);                //mov dl, byte ptr [si+0x2a]
    _dh = memory(_ds, _si + 4);                 //mov dh, byte ptr [si+0x4]
    _al = memory(_ds, _si + 5);                 //mov al, byte ptr [si+0x5]
    _cx = memory16(_ds, _si + 44);              //mov cx, word ptr [si+0x2c]
    _ah = 0;                                    //sub ah, ah
    if (!(_ch & 0x80))                          //jz loc_23a3
        goto loc_23a3;
    _ah -= 1;                                   //dec ah
loc_23a3:                                       //loc_23a3:
    _flags.carry = (_dx + _cx) >= 0x10000;      //add dx, cx
    _dx += _cx;
    _al = _al + _ah + _flags.carry;             //adc al, ah
    _ah = _dl;                                  //mov ah, dl
    _dl = _dh;                                  //mov dl, dh
    _dh = _al;                                  //mov dh, al
    if (_dx < 0x0140)                           //jc loc_23bc
        goto loc_23bc;
    sub_265a();                                 //call sub_265a
    _STOP_("goto loc_24fd");                    //jmp loc_24fd
loc_23bc:                                       //loc_23bc:
    _bl = memory(_ds, _si + 2);                 //mov bl, byte ptr [si+0x2]
    sub_11bc();                                 //call sub_11bc
    _al = memory(_ds, 0x7d67);                  //mov al, [0x7d67]
    _al &= 0xf0;                                //and al, 0xf0
    if (_al != 0)                               //jnz loc_23f1
        goto loc_23f1;
    _al = memory(_ds, 0x7d67);                  //mov al, [0x7d67]
    _al &= 0x04;                                //and al, 0x4
    if (_al == 0)                               //jz loc_23d6
        goto loc_23d6;
    _STOP_("goto loc_24c4");                    //jmp loc_24c4
loc_23d6:                                       //loc_23d6:
    memory16(_ds, _si + 4) = _dx;               //mov word ptr [si+0x4], dx
    memory(_ds, _si + 42) = _ah;                //mov byte ptr [si+0x2a], ah
    _ax = memory16(_ds, _si + 44);              //mov ax, word ptr [si+0x2c]
    _ax += 0x0080;                              //add ax, 0x80
    if (_ah < 0x08)                             //jc loc_23ed
        goto loc_23ed;
    _ax = 0x0800;                               //mov ax, 0x800
loc_23ed:                                       //loc_23ed:
    memory16(_ds, _si + 44) = _ax;              //mov word ptr [si+0x2c], ax
    return;                                     //ret
loc_23f1:                                       //loc_23f1:
    _bl = memory(_ds, _si + 2);                 //mov bl, byte ptr [si+0x2]
    _bl &= 0x1c;                                //and bl, 0x1c
    _bl >>= 1;                                  //shr bl, 1
    _bl >>= 1;                                  //shr bl, 1
    _bl >>= 1;                                  //shr bl, 1
    _bh = 0;                                    //sub bh, bh
    _bx += 0x8143;                              //add bx, 0x8143
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    if (!(memory(_ds, _si + 38) & 0x80))        //jz loc_2410
        goto loc_2410;
    _al += 0x03;                                //add al, 0x3
loc_2410:                                       //loc_2410:
    _al = _al + memory(_ds, _si + 32);          //add al, byte ptr [si+0x20]
    memory(_ds, _si + 8) = _al;                 //mov byte ptr [si+0x8], al
    memory16(_ds, _si + 44) = 0x0080;           //mov word ptr [si+0x2c], 0x80
    _ax = memory16(_ds, _si + 4);               //mov ax, word ptr [si+0x4]
    _al &= 0xf8;                                //and al, 0xf8
    _al |= 0x03;                                //or al, 0x3
    memory16(_ds, _si + 4) = _ax;               //mov word ptr [si+0x4], ax
    _al = memory(_ds, _si + 46);                //mov al, byte ptr [si+0x2e]
    _al &= _al;                                 //and al, al
    if (_al == 0)                               //jz loc_2435
        goto loc_2435;
    _al -= 1;                                   //dec al
    memory(_ds, _si + 46) = _al;                //mov byte ptr [si+0x2e], al
    return;                                     //ret
loc_2435:                                       //loc_2435:
    _al = memory(_ds, _si + 38);                //mov al, byte ptr [si+0x26]
    _al &= _al;                                 //and al, al
    if (_al != 0)                               //jnz loc_2447
    {
        _flags.sign = !!(_al & 0x80);
        sub_2440(0x2447);
    }
}

void sub_2440(int pc)
{
    if (pc == 0x2447)
        goto loc_2447;
    if (pc == 0x24c4)
        goto loc_24c4;
    if (pc == 0x2501)
        goto loc_2501;
    _al = 0x02;                                 //mov al, 0x2
    memory(_ds, _si + 38) = _al;                //mov byte ptr [si+0x26], al
    _al &= _al;
    _flags.sign = !!(_al & 0x80);
loc_2447:                                       //loc_2447:
    if (!_flags.sign)                           //jns loc_2457
        goto loc_2457;
    _flags.carry = (_al + memory(_ds, _si + 2)) >= 0x100;
    _al = _al + memory(_ds, _si + 2);
    if (_flags.carry)                           //jc loc_2461
        goto loc_2461;
    goto loc_24bc;                              //jmp loc_24bc
    _STOP_("db 90h");                           //db 90h
loc_2457:                                       //loc_2457:
    _al = _al + memory(_ds, _si + 2);           //add al, byte ptr [si+0x2]
    if (_al >= 0xe8)                            //jnc loc_24bc
        goto loc_24bc;
loc_2461:                                       //loc_2461:
    _bl = _al;                                  //mov bl, al
    _dx = memory16(_ds, _si + 4);               //mov dx, word ptr [si+0x4]
    sub_11bc();                                 //call sub_11bc
    _al = memory(_ds, 0x7d67);                  //mov al, [0x7d67]
    _al &= 0xf0;                                //and al, 0xf0
    if (_al != 0)                               //jnz loc_24bc
        goto loc_24bc;
    _al = memory(_ds, 0x7d67);                  //mov al, [0x7d67]
    if (_al & 0x04)                             //jnz loc_24c4
        goto loc_24c4;
    memory(_ds, _si + 2) = _bl;                 //mov byte ptr [si+0x2], bl
    _al = memory(_ds, 0x7d8e);                  //mov al, [0x7d8e]
    _al &= _al;                                 //and al, al
    if (_al == 0)                               //jz loc_24a9
        goto loc_24a9;
    _al = memory(_ds, _si + 2);                 //mov al, byte ptr [si+0x2]
    _cl = _al;                                  //mov cl, al
    _al &= 0x1e;                                //and al, 0x1e
    if (_al == 0x10)                            //jz loc_2499
        goto loc_2499;
loc_2498:                                       //loc_2498:
    return;                                     //ret
loc_2499:                                       //loc_2499:
    _al = memory(_ds, 0x7e80);                  //mov al, [0x7e80]
    memory(_ds, _si + 38) = 0xfe;               //mov byte ptr [si+0x26], 0xfe
    if (_al < _cl)                              //jc loc_2498
        goto loc_2498;
    memory(_ds, _si + 38) = 0x02;               //mov byte ptr [si+0x26], 0x2
    return;                                     //ret
loc_24a9:                                       //loc_24a9:
    _al = memory(_ds, _si + 22);                //mov al, byte ptr [si+0x16]
    _al >>= 1;                                  //shr al, 1
    _cl = _al;                                  //mov cl, al
    _al = memory(_ds, _si + 40);                //mov al, byte ptr [si+0x28]
    _al += 1;                                   //inc al
    memory(_ds, _si + 40) = _al;                //mov byte ptr [si+0x28], al
    if (_al < _cl)                              //jc loc_2498
        goto loc_2498;
loc_24bc:                                       //loc_24bc:
    memory(_ds, _si + 40) = 0x00;               //mov byte ptr [si+0x28], 0x0
    memory(_ds, _si + 38) = -memory(_ds, _si + 38);//neg byte ptr [si+0x26]
    return;                                     //ret
loc_24c4:                                       //loc_24c4:
    memory(_ds, _si) = 0x47;                    //mov byte ptr [si], 0x47
    memory16(_ds, _si + 44) = 0xfc00;           //mov word ptr [si+0x2c], 0xfc00
    _ax = 0x7da9;                               //mov ax, 0x7da9
    memory16(_ds, 0x7d9a) = _ax;                //mov [0x7d9a], ax
    _push(_si);                                 //push si
    _si = 0x4928;                               //mov si, 0x4928
    sub_0292();                                 //call sub_0292
    _si = _pop();                               //pop si
    if (!(memory(_ds, _si + 20) & 0x01))        //jz loc_24ea
        goto loc_24ea;
    _bx = memory16(_ds, _si + 18);              //mov bx, word ptr [si+0x12]
    _bx += 1;                                   //inc bx
    memory(_ds, _bx) |= 0x80;                   //or byte ptr [bx], 0x80
loc_24ea:                                       //loc_24ea:
    memory(_ds, _si + 38) = 0x02;               //mov byte ptr [si+0x26], 0x2
    if (memory(_ds, _si + 2) >= 0x80)           //jnc loc_24f8
        goto loc_24f8;
    return;                                     //ret
loc_24f8:                                       //loc_24f8:
    memory(_ds, _si + 38) = 0xfe;               //mov byte ptr [si+0x26], 0xfe
    return;                                     //ret
loc_24fd:                                       //loc_24fd:
    memory(_ds, _si) = 0x00;                    //mov byte ptr [si], 0x0
    return;                                     //ret
loc_2501:                                       //loc_2501:
    _ah = memory(_ds, _si + 32);                //mov ah, byte ptr [si+0x20]
    _ah += 0x06;                                //add ah, 0x6
    if (!(memory(_ds, _si + 2) & 0x04))         //jz loc_2512
        goto loc_2512;
    _ah += 1;                                   //inc ah
loc_2512:                                       //loc_2512:
    memory(_ds, _si + 8) = _ah;                 //mov byte ptr [si+0x8], ah
    _dl = memory(_ds, _si + 42);                //mov dl, byte ptr [si+0x2a]
    _dh = memory(_ds, _si + 4);                 //mov dh, byte ptr [si+0x4]
    _al = memory(_ds, _si + 5);                 //mov al, byte ptr [si+0x5]
    _cx = memory16(_ds, _si + 44);              //mov cx, word ptr [si+0x2c]
    _ah = 0;                                    //sub ah, ah
    _flags.sign = !!(_ch & 0x80);
    if (!_flags.sign)                           //jns loc_252c
        goto loc_252c;
    _ah -= 1;                                   //dec ah
loc_252c:                                       //loc_252c:
    _flags.carry = (_dx + _cx) >= 0x10000;      //add dx, cx
    _dx += _cx;
    _al = _al + _ah + _flags.carry;             //adc al, ah
    _al &= _al;                                 //and al, al
    if (_al == 0)                               //jz loc_253b
        goto loc_253b;
    memory(_ds, _si) = 0x00;                    //mov byte ptr [si], 0x0
    return;                                     //ret
loc_253b:                                       //loc_253b:
    memory(_ds, _si + 42) = _dl;                //mov byte ptr [si+0x2a], dl
    memory(_ds, _si + 4) = _dh;                 //mov byte ptr [si+0x4], dh
    memory(_ds, _si + 5) = _al;                 //mov byte ptr [si+0x5], al
    _ax = memory16(_ds, _si + 44);              //mov ax, word ptr [si+0x2c]
    _ax += 0x0080;                              //add ax, 0x80
    memory16(_ds, _si + 44) = _ax;              //mov word ptr [si+0x2c], ax
    _al = memory(_ds, _si + 38);                //mov al, byte ptr [si+0x26]
    _flags.sign == !!(_al & 0x80);
    if (!_flags.sign)                           //jns loc_2568
        goto loc_2568;
    _flags.carry = (_al + memory(_ds, _si + 2)) >= 0x100;
    _al = _al + memory(_ds, _si + 2);
    memory(_ds, _si + 2) = _al;                 //mov byte ptr [si+0x2], al
    if (!_flags.carry)                          //jnc loc_2563
        goto loc_2563;
loc_2562:                                       //loc_2562:
    return;                                     //ret
loc_2563:                                       //loc_2563:
    memory(_ds, _si + 2) = 0x00;                //mov byte ptr [si+0x2], 0x0
    return;                                     //ret
loc_2568:                                       //loc_2568:
    _flags.carry = (_al + memory(_ds, _si + 2)) >= 0x100;
    _al = _al + memory(_ds, _si + 2);
    memory(_ds, _si + 2) = _al;                 //mov byte ptr [si+0x2], al
    if (!_flags.carry)                          //jnc loc_2562
        goto loc_2562;
    memory(_ds, _si + 2) = 0xe8;                //mov byte ptr [si+0x2], 0xe8
}

void sub_2575()
{
    sub_12ae();                                 //call sub_12ae
    if (_flags.zero)                                //jz loc_257e
        goto loc_257e;
    return;                                     //ret
loc_257e:                                       //loc_257e:
    memory(_ds, _si) = 0x00;                    //mov byte ptr [si], 0x0
    _push(_si);                                 //push si
    _si = 0x492e;                               //mov si, 0x492e
    sub_0292();                                 //call sub_0292
    _si = _pop();                               //pop si
    _ax = 0x7df2;                               //mov ax, 0x7df2
    memory16(_ds, 0x7d9a) = _ax;                //mov [0x7d9a], ax
    {sub_2592(); return; };                     //
    _STOP_("db 90h");                           //db 90h
    _STOP_("sp-trace-fail");                    //sub_2575 endp_failed
    _STOP_("continues");                        //sub_2592 proc near
}

void sub_2592()
{
    _bx = memory16(_ds, _si + 18);              //mov bx, word ptr [si+0x12]
    _bx += 1;                                   //inc bx
    memory(_ds, _bx) |= 0x80;                   //or byte ptr [bx], 0x80
}

void sub_259a()
{
}

void sub_259b()
{
    memory(_ds, 32142) = 0x00;                  //mov byte ptr [0x7d8e], 0x0
    sub_2313(0x2318);
    //_STOP_("goto loc_2318");                    //jmp loc_2318
}

void sub_25a3()
{
    assert(0);
    if (!(memory(_ds, _si) & 0x80))             //jz loc_25ca
        goto loc_25ca;
    _bl = memory(_ds, _si + 38);                //mov bl, byte ptr [si+0x26]
    _bl >>= 1;                                  //shr bl, 1
    _bh = 0;                                    //sub bh, bh
    _bx += 0x8138;                              //add bx, 0x8138
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    memory(_ds, _si + 8) = _al;                 //mov byte ptr [si+0x8], al
    memory(_ds, _si + 38) -= 1;                 //dec byte ptr [si+0x26]
    if (memory(_ds, _si + 38) != 0)             //jnz loc_25c9
        goto loc_25c9;
    memory(_ds, _si) = 0x00;                    //mov byte ptr [si], 0x0
    sub_2592();                                 //call sub_2592
loc_25c9:                                       //loc_25c9:
    return;                                     //ret
loc_25ca:                                       //loc_25ca:
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    sub_12ae();                                 //call sub_12ae
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    if (_FIXME_)                                //jz loc_2629
        goto loc_2629;
    _al = memory(_ds, 0x7d6a);                  //mov al, [0x7d6a]
    _al &= _al;                                 //and al, al
    if (_al == 0)                               //jz loc_25f8
        goto loc_25f8;
    _bl = memory(_ds, 32123);                   //mov bl, byte ptr [0x7d7b]
    _dx = memory16(_ds, 32124);                 //mov dx, word ptr [0x7d7c]
    sub_1317();                                 //call sub_1317
    if (_FIXME_)                                //jnz loc_25f8
        goto loc_25f8;
loc_25f0:                                       //loc_25f0:
    memory(_ds, _si + 38) = 0x0a;               //mov byte ptr [si+0x26], 0xa
    memory(_ds, _si) |= 0x80;                   //or byte ptr [si], 0x80
    return;                                     //ret
loc_25f8:                                       //loc_25f8:
    _al = memory(_ds, 0x7eae);                  //mov al, [0x7eae]
    _al &= _al;                                 //and al, al
    if (_al == 0)                               //jz loc_2619
        goto loc_2619;
    _bl = memory(_ds, 32126);                   //mov bl, byte ptr [0x7d7e]
    _dx = memory16(_ds, 32127);                 //mov dx, word ptr [0x7d7f]
    sub_1317();                                 //call sub_1317
    if (_FIXME_)                                //jnz loc_2619
        goto loc_2619;
    memory(_ds, 32430) = 0x00;                  //mov byte ptr [0x7eae], 0x0
    goto loc_25f0;                              //jmp loc_25f0
loc_2619:                                       //loc_2619:
    _al = memory(_ds, 0x7d85);                  //mov al, [0x7d85]
    _al &= _al;                                 //and al, al
    if (_al == 0)                               //jz loc_2628
        goto loc_2628;
    sub_134b();                                 //call sub_134b
    if (_FIXME_)                                //jz loc_25f0
        goto loc_25f0;
loc_2628:                                       //loc_2628:
    return;                                     //ret
loc_2629:                                       //loc_2629:
    _ax = 0x7df2;                               //mov ax, 0x7df2
    memory16(_ds, 0x7d9a) = _ax;                //mov [0x7d9a], ax
    _al = memory(_ds, _si);                     //mov al, byte ptr [si]
    memory(_ds, _si) = 0x00;                    //mov byte ptr [si], 0x0
    if (_al != 0x10)                            //jnz loc_2643
        goto loc_2643;
    memory(_ds, 32327) = 0x06;                  //mov byte ptr [0x7e47], 0x6
    {sub_2592(); return; };                     //
loc_2643:                                       //loc_2643:
    memory(_ds, 32325) = 0x06;                  //mov byte ptr [0x7e45], 0x6
    {sub_2592(); return; };                     //
}

void sub_264b()
{
    _push(_ds);                                 //push ds
    _push(_bx);                                 //push bx
    _bx = 0xb800;                               //mov bx, 0xb800
    _ds = _bx;                                  //mov ds, bx
    _bx = 0x0044;                               //mov bx, 0x44
    memory16(_ds, _bx) = _ax;                   //mov word ptr [bx], ax
    _bx = _pop();                               //pop bx
    _ds = _pop();                               //pop ds
}

void sub_265a()
{
    _push(_ds);                                 //push ds
    _push(_bx);                                 //push bx
    _bx = 0xb800;                               //mov bx, 0xb800
    _ds = _bx;                                  //mov ds, bx
    _bx = 0x004e;                               //mov bx, 0x4e
    memory16(_ds, _bx) += 1;                    //inc word ptr [bx]
    _bx = _pop();                               //pop bx
    _ds = _pop();                               //pop ds
}

void sub_2669(int pc)
{
    if (pc == 0x268f)
        goto loc_268f;
    
    memory(_ds, 32133) = 0x00;                  //mov byte ptr [0x7d85], 0x0
    memory(_ds, 32106) = 0x00;                  //mov byte ptr [0x7d6a], 0x0
    _si = 0x7e4e;                               //mov si, 0x7e4e
loc_2676:                                       //loc_2676:
    _al = memory(_ds, _si);                     //mov al, byte ptr [si]
    if (_al != 0xff)                            //jnz loc_2680
        goto loc_2680;
    return;                                     //ret
loc_2680:                                       //loc_2680:
    if (_al == 0x01)                            //jz loc_268a
        goto loc_268a;
    memory(_ds, _si) = 0x00;                    //mov byte ptr [si], 0x0
loc_268a:                                       //loc_268a:
    _si += 0x0030;                              //add si, 0x30
    goto loc_2676;                              //jmp loc_2676
loc_268f:                                       //loc_268f:
    sub_26a3();                                 //call sub_26a3
    if (!(memory(_ds, _si) & 0x80))             //jz loc_26a2
        goto loc_26a2;
    sub_12ae();                                 //call sub_12ae
    if (!_flags.zero)                                //jnz loc_26a2
        goto loc_26a2;
    {sub_19cf(); return; };                     //
loc_26a2:                                       //loc_26a2:
    return;
}

void sub_26a3()
{
loc_26a3:
    _al = memory(_ds, _si + 38);                //mov al, byte ptr [si+0x26]
    _ah = 0;                                    //sub ah, ah
    _bx = memory16(_ds, _si + 32);              //mov bx, word ptr [si+0x20]
    _cx = _bx;                                  //mov cx, bx
    _bx += _ax;                                 //add bx, ax
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    if (_al != 0xff)                            //jnz loc_26bc
        goto loc_26bc;
    _bx = _cx;                                  //mov bx, cx
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
loc_26bc:                                       //loc_26bc:
    memory(_ds, _si + 8) = _al;                 //mov byte ptr [si+0x8], al
    _al = memory(_ds, _si + 38);                //mov al, byte ptr [si+0x26]
    _al &= _al;                                 //and al, al
    if (_al != 0)                               //jnz loc_26c9
        goto loc_26c9;
    goto loc_27a7;                              //jmp loc_27a7
loc_26c9:                                       //loc_26c9:
    _ah = 0;                                    //sub ah, ah
    _bx = _cx;                                  //mov bx, cx
    _bx += _ax;                                 //add bx, ax
    if (memory(_ds, _bx) != 0xff)               //jnz loc_26de
        goto loc_26de;
    memory(_ds, _si + 38) = 0x01;               //mov byte ptr [si+0x26], 0x1
    goto loc_26f5;                              //jmp loc_26f5
    _STOP_("db 90h");                           //db 90h
loc_26de:                                       //loc_26de:
    _al += 1;                                   //inc al
    memory(_ds, _si + 38) = _al;                //mov byte ptr [si+0x26], al
    _ah = 0;                                    //sub ah, ah
    _bx = _cx;                                  //mov bx, cx
    _bx += _ax;                                 //add bx, ax
    if (memory(_ds, _bx) != 0xff)               //jnz loc_26f5
        goto loc_26f5;
    memory(_ds, _si + 38) = 0x01;               //mov byte ptr [si+0x26], 0x1
loc_26f5:                                       //loc_26f5:
    _bx = memory16(_ds, _si + 36);              //mov bx, word ptr [si+0x24]
    _al = memory(_ds, _si + 40);                //mov al, byte ptr [si+0x28]
loc_26fb:                                       //loc_26fb:
    if (_al < memory(_ds, _bx))                 //jc loc_2757
        goto loc_2757;
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    if (memory(_ds, _bx) != 0xff)               //jnz loc_274d
        goto loc_274d;
loc_270d:                                       //loc_270d:
    _al = memory(_ds, 0x7d75);                  //mov al, [0x7d75]
    _al &= _al;                                 //and al, al
    if (_al != 0)                               //jnz loc_2724
        goto loc_2724;
    if (!(memory(_ds, _si + 20) & 0x01))        //jz loc_2724
        goto loc_2724;
loc_2720:                                       //loc_2720:
    memory(_ds, _si) = 0x00;                    //mov byte ptr [si], 0x0
    return;                                     //ret
loc_2724:                                       //loc_2724:
    _al = memory(_ds, _si);                     //mov al, byte ptr [si]
    _al &= 0x7f;                                //and al, 0x7f
    if (!(memory(_ds, _si + 20) & 0x04))        //jz loc_2733
        goto loc_2733;
    _al |= 0x80;                                //or al, 0x80
loc_2733:                                       //loc_2733:
    memory(_ds, _si) = _al;                     //mov byte ptr [si], al
    memory(_ds, _si + 38) = 0x00;               //mov byte ptr [si+0x26], 0x0
    _al = memory(_ds, _si + 28);                //mov al, byte ptr [si+0x1c]
    memory(_ds, _si + 2) = _al;                 //mov byte ptr [si+0x2], al
    _ax = memory16(_ds, _si + 30);              //mov ax, word ptr [si+0x1e]
    if (_ax >= 0x0140)                          //jnc loc_2720
        goto loc_2720;
    memory16(_ds, _si + 4) = _ax;               //mov word ptr [si+0x4], ax
    goto loc_26a3;                              //jmp sub_26a3
loc_274d:                                       //loc_274d:
    memory16(_ds, _si + 36) = _bx;              //mov word ptr [si+0x24], bx
    _al = 0x00;                                 //mov al, 0x0
    memory(_ds, _si + 40) = _al;                //mov byte ptr [si+0x28], al
    goto loc_26fb;                              //jmp loc_26fb
loc_2757:                                       //loc_2757:
    _al += 1;                                   //inc al
    memory(_ds, _si + 40) = _al;                //mov byte ptr [si+0x28], al
    _bx += 1;                                   //inc bx
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    //_FIXME_;                                    //and al, al
    //_al &= _al;
    _flags.sign = !!(_al & 0x80);
    if (!_flags.sign)                           //jns loc_276e
        goto loc_276e;
    _flags.carry = (_al + memory(_ds, _si + 2)) >= 0x100;
    _al = _al + memory(_ds, _si + 2);
    if (!_flags.carry)                          //jnc loc_270d
        goto loc_270d;
    goto loc_2777;                              //jmp loc_2777
    _STOP_("db 90h");                           //db 90h
loc_276e:                                       //loc_276e:
    _flags.carry = (_al + memory(_ds, _si + 2)) >= 0x100;
    _al = _al + memory(_ds, _si + 2);
    if (_flags.carry)                           //jc loc_270d
        goto loc_270d;
    if (_al >= 0xe8)                            //jnc loc_270d
        goto loc_270d;
loc_2777:                                       //loc_2777:
    memory(_ds, _si + 2) = _al;                 //mov byte ptr [si+0x2], al
    _bx += 1;                                   //inc bx
    _cl = memory(_ds, _bx);                     //mov cl, byte ptr [bx]
    _ch = 0;                                    //sub ch, ch
    _ax = memory16(_ds, _si + 4);               //mov ax, word ptr [si+0x4]
    //_FIXME_;                                    //and cl, cl
    //_cl &= _cl;
    _flags.sign = !!(_cl & 0x80);
    if (!_flags.sign)                           //jns loc_278b
        goto loc_278b;
    _ch -= 1;                                   //dec ch
loc_278b:                                       //loc_278b:
    _ax += _cx;                                 //add ax, cx
    _ah &= _ah;                                 //and ah, ah
    if (_ah == 0)                               //jz loc_27a3
        goto loc_27a3;
    if (_ah == 0x01)                            //jz loc_279c
        goto loc_279c;
    goto loc_270d;                              //jmp loc_270d
loc_279c:                                       //loc_279c:
    if (_al < 0x40)                             //jc loc_27a3
        goto loc_27a3;
    goto loc_270d;                              //jmp loc_270d
loc_27a3:                                       //loc_27a3:
    memory16(_ds, _si + 4) = _ax;               //mov word ptr [si+0x4], ax
    return;                                     //ret
loc_27a7:                                       //loc_27a7:
    _al = memory(_ds, _si + 20);                //mov al, byte ptr [si+0x14]
    if (!(_al & 0x80))                          //jz loc_27ca
        goto loc_27ca;
    _bl = memory(_ds, 32384);                   //mov bl, byte ptr [0x7e80]
    _bl += 0x0c;                                //add bl, 0xc
    _dx = memory16(_ds, 32386);                 //mov dx, word ptr [0x7e82]
    _dx += 0x000a;                              //add dx, 0xa
    sub_13ed();                                 //call sub_13ed
    if (_flags.zero)                                //jz loc_2836
        goto loc_2836;
    _al = memory(_ds, _si + 20);                //mov al, byte ptr [si+0x14]
loc_27ca:                                       //loc_27ca:
    if (!(_al & 0x40))                          //jz loc_27ee
        goto loc_27ee;
    _al = memory(_ds, 0x7d6a);                  //mov al, [0x7d6a]
    _al &= _al;                                 //and al, al
    if (_al == 0)                               //jz loc_27eb
        goto loc_27eb;
    _bl = memory(_ds, 32123);                   //mov bl, byte ptr [0x7d7b]
    _dx = memory16(_ds, 32124);                 //mov dx, word ptr [0x7d7c]
    sub_13ed();                                 //call sub_13ed
    if (_FIXME_)                                //jz loc_2836
        goto loc_2836;
loc_27eb:                                       //loc_27eb:
    _al = memory(_ds, _si + 20);                //mov al, byte ptr [si+0x14]
loc_27ee:                                       //loc_27ee:
    if (!(_al & 0x20))                          //jz loc_281a
        goto loc_281a;
    _al = memory(_ds, 0x7eae);                  //mov al, [0x7eae]
    _al &= _al;                                 //and al, al
    if (_al == 0)                               //jz loc_2817
        goto loc_2817;
    _bl = memory(_ds, 32126);                   //mov bl, byte ptr [0x7d7e]
    _dx = memory16(_ds, 32127);                 //mov dx, word ptr [0x7d7f]
    sub_13ed();                                 //call sub_13ed
    if (_FIXME_)                                //jnz loc_2817
        goto loc_2817;
    memory(_ds, 32430) = 0x00;                  //mov byte ptr [0x7eae], 0x0
    goto loc_2836;                              //jmp loc_2836
    _STOP_("db 90h");                           //db 90h
loc_2817:                                       //loc_2817:
    _al = memory(_ds, _si + 20);                //mov al, byte ptr [si+0x14]
loc_281a:                                       //loc_281a:
    if (_al & 0x10)                             //jnz loc_2822
        goto loc_2822;
loc_2821:                                       //loc_2821:
    return;                                     //ret
loc_2822:                                       //loc_2822:
    _al = memory(_ds, 0x7d85);                  //mov al, [0x7d85]
    _al &= _al;                                 //and al, al
    if (_al == 0)                               //jz loc_2821
        goto loc_2821;
    _bl = memory(_ds, 32130);                   //mov bl, byte ptr [0x7d82]
    _dx = memory16(_ds, 32131);                 //mov dx, word ptr [0x7d83]
    sub_13ed();                                 //call sub_13ed
    if (_FIXME_)                                //jnz loc_2821
        goto loc_2821;
loc_2836:                                       //loc_2836:
    if (memory(_ds, 32117) == 0x00)             //jz loc_2841
        goto loc_2841;
    return;                                     //ret
loc_2841:                                       //loc_2841:
    _al = memory(_ds, _si);                     //mov al, byte ptr [si]
    _al &= 0x7f;                                //and al, 0x7f
    if (!(memory(_ds, _si + 20) & 0x08))        //jz loc_2850
        goto loc_2850;
    _al |= 0x80;                                //or al, 0x80
loc_2850:                                       //loc_2850:
    memory(_ds, _si) = _al;                     //mov byte ptr [si], al
    memory(_ds, _si + 38) = 0x01;               //mov byte ptr [si+0x26], 0x1
    memory(_ds, _si + 40) = 0x00;               //mov byte ptr [si+0x28], 0x0
    _ax = memory16(_ds, _si + 34);              //mov ax, word ptr [si+0x22]
    memory16(_ds, _si + 36) = _ax;              //mov word ptr [si+0x24], ax
}

void sub_2861()
{
    sub_28db();                                 //call sub_28db
    sub_12ae();                                 //call sub_12ae
    if (!_flags.zero)                                //jnz loc_286f
        goto loc_286f;
    sub_19cf();                                 //call sub_19cf
loc_286f:                                       //loc_286f:
    sub_13ac();                                 //call sub_13ac
    if (!_flags.zero)                                //jnz loc_2877
        goto loc_2877;
    _STOP_("goto loc_24c4");                    //jmp loc_24c4
loc_2877:                                       //loc_2877:
    _al = memory(_ds, 0x7eae);                  //mov al, [0x7eae]
    _al &= _al;                                 //and al, al
    if (_al != 0)                               //jnz loc_2884
        goto loc_2884;
    goto loc_28ac;                              //jmp loc_28ac
    _STOP_("db 90h");                           //db 90h
loc_2884:                                       //loc_2884:
    _bl = memory(_ds, 32432);                   //mov bl, byte ptr [0x7eb0]
    _dx = memory16(_ds, 32434);                 //mov dx, word ptr [0x7eb2]
    _dx += 0x0006;                              //add dx, 0x6
    if (memory(_ds, 32135) & 0x80)              //jnz loc_289c
        goto loc_289c;
    _bl += 0x18;                                //add bl, 0x18
loc_289c:                                       //loc_289c:
    sub_1317();                                 //call sub_1317
    if (!_flags.zero)                                //jnz loc_28ac
        goto loc_28ac;
    memory(_ds, 32430) = 0x00;                  //mov byte ptr [0x7eae], 0x0
    _STOP_("goto loc_24c4");                    //jmp loc_24c4
loc_28ac:                                       //loc_28ac:
    _al = memory(_ds, 0x7d85);                  //mov al, [0x7d85]
    _al &= _al;                                 //and al, al
    if (_al == 0)                               //jz loc_28be
        goto loc_28be;
    sub_134b();                                 //call sub_134b
    if (!_flags.zero)                                //jnz loc_28be
        goto loc_28be;
    _STOP_("goto loc_24c4");                    //jmp loc_24c4
loc_28be:                                       //loc_28be:
    _al = memory(_ds, 0x7d6a);                  //mov al, [0x7d6a]
    _al &= _al;                                 //and al, al
    if (_al != 0)                               //jnz loc_28c9
        goto loc_28c9;
loc_28c8:                                       //loc_28c8:
    return;                                     //ret
loc_28c9:                                       //loc_28c9:
    _bl = memory(_ds, 32123);                   //mov bl, byte ptr [0x7d7b]
    _dx = memory16(_ds, 32124);                 //mov dx, word ptr [0x7d7c]
    sub_1317();                                 //call sub_1317
    if (!_flags.zero)                                //jnz loc_28c8
        goto loc_28c8;
    memory(_ds, _si + 46) = 0x14;               //mov byte ptr [si+0x2e], 0x14
}

void sub_28db()
{
    _al = memory(_ds, _si + 46);                //mov al, byte ptr [si+0x2e]
    _al &= _al;                                 //and al, al
    if (_al == 0)                               //jz loc_28e8
        goto loc_28e8;
    memory(_ds, _si + 46) -= 1;                 //dec byte ptr [si+0x2e]
loc_28e8:                                       //loc_28e8:
    if (memory(_ds, _si + 38) == 0xff)          //jz loc_28f1
        goto loc_28f1;
    goto loc_29ca;                              //jmp loc_29ca
loc_28f1:                                       //loc_28f1:
    if (memory(_ds, _si + 46) == 0x00)          //jz loc_28fb
        goto loc_28fb;
    return;                                     //ret
loc_28fb:                                       //loc_28fb:
    _al = memory(_ds, _si + 32);                //mov al, byte ptr [si+0x20]
    _al += 0x08;                                //add al, 0x8
    _ah = memory(_ds, _si + 4);                 //mov ah, byte ptr [si+0x4]
    _ah = _ah ^ memory(_ds, _si + 2);           //xor ah, byte ptr [si+0x2]
    _ah &= 0x04;                                //and ah, 0x4
    if (_ah == 0)                               //jz loc_2910
        goto loc_2910;
    _al += 1;                                   //inc al
loc_2910:                                       //loc_2910:
    memory(_ds, _si + 8) = _al;                 //mov byte ptr [si+0x8], al
    _ax = memory16(_ds, 0x7e82);                //mov ax, [0x7e82]
    _al &= 0xfe;                                //and al, 0xfe
    _bx = memory16(_ds, _si + 4);               //mov bx, word ptr [si+0x4]
    _bl &= 0xfe;                                //and bl, 0xfe
    if (_ax != _bx)                             //jnz loc_2968
        goto loc_2968;
loc_2925:                                       //loc_2925:
    _al = memory(_ds, _si + 2);                 //mov al, byte ptr [si+0x2]
    _ah = 0x02;                                 //mov ah, 0x2
    if (_al < memory(_ds, 32384))               //jc loc_2935
        goto loc_2935;
    _ah = 0xfe;                                 //mov ah, 0xfe
loc_2935:                                       //loc_2935:
    memory(_ds, _si + 40) = _ah;                //mov byte ptr [si+0x28], ah
    _al += _ah;                                 //add al, ah
    _bl = _al;                                  //mov bl, al
    _dx = memory16(_ds, _si + 4);               //mov dx, word ptr [si+0x4]
    sub_11bc();                                 //call sub_11bc
    _al = memory(_ds, 0x7d67);                  //mov al, [0x7d67]
    _al &= 0x70;                                //and al, 0x70
    if (_al == 0)                               //jz loc_294d
        goto loc_294d;
    return;                                     //ret
loc_294d:                                       //loc_294d:
    _al = memory(_ds, 0x7d67);                  //mov al, [0x7d67]
    _al &= 0x04;                                //and al, 0x4
    if (_al == 0)                               //jz loc_2957
        goto loc_2957;
    _STOP_("goto loc_24c4");                    //jmp loc_24c4
loc_2957:                                       //loc_2957:
    memory(_ds, _si + 2) = _bl;                 //mov byte ptr [si+0x2], bl
    _al = memory(_ds, 0x7d67);                  //mov al, [0x7d67]
    _FIXME_;                                    //and al, 0x82
    _al &= 0x82;
    if (_al == 0)                               //jz loc_2965
        goto loc_2965;
    return;                                     //ret
loc_2965:                                       //loc_2965:
    goto loc_29c6;                              //jmp loc_29c6
    _STOP_("db 90h");                           //db 90h
loc_2968:                                       //loc_2968:
    _ax = 0xfffe;                               //mov ax, 0xfffe
    if (_flags.carry)                           //jc loc_2973
        goto loc_2973;
    _ax = 0x0002;                               //mov ax, 0x2
loc_2973:                                       //loc_2973:
    _bx += _ax;                                 //add bx, ax
    _push(_ax);                                 //push ax
    if (_bh == 0x00)                            //jz loc_2990
        goto loc_2990;
    if (_bh == 0x01)                            //jz loc_298b
        goto loc_298b;
loc_2986:                                       //loc_2986:
    memory(_ds, _si) = 0x00;                    //mov byte ptr [si], 0x0
    _ax = _pop();                               //pop ax
    return;                                     //ret
loc_298b:                                       //loc_298b:
    if (_bl >= 0x40)                            //jnc loc_2986
        goto loc_2986;
loc_2990:                                       //loc_2990:
    _dx = _bx;                                  //mov dx, bx
    _bl = memory(_ds, _si + 2);                 //mov bl, byte ptr [si+0x2]
    sub_11bc();                                 //call sub_11bc
    _al = memory(_ds, 0x7d67);                  //mov al, [0x7d67]
    _al &= 0x70;                                //and al, 0x70
    _ax = _pop();                               //pop ax
    if (_al == 0)                               //jz loc_29b8
        goto loc_29b8;
    if (_ah & 0x80)                             //jnz loc_29b2
        goto loc_29b2;
    memory(_ds, _si + 38) = 0x00;               //mov byte ptr [si+0x26], 0x0
    goto loc_29ca;                              //jmp loc_29ca
    _STOP_("db 90h");                           //db 90h
loc_29b2:                                       //loc_29b2:
    _dx = memory16(_ds, _si + 4);               //mov dx, word ptr [si+0x4]
    goto loc_2925;                              //jmp loc_2925
loc_29b8:                                       //loc_29b8:
    _al = memory(_ds, 0x7d67);                  //mov al, [0x7d67]
    memory16(_ds, _si + 4) = _dx;               //mov word ptr [si+0x4], dx
    _al &= 0x82;                                //and al, 0x82
    if (_al == 0)                               //jz loc_29c6
        goto loc_29c6;
    return;                                     //ret
loc_29c6:                                       //loc_29c6:
    memory(_ds, _si + 38) = 0x00;               //mov byte ptr [si+0x26], 0x0
loc_29ca:                                       //loc_29ca:
    _dl = memory(_ds, _si + 42);                //mov dl, byte ptr [si+0x2a]
    _dh = memory(_ds, _si + 4);                 //mov dh, byte ptr [si+0x4]
    _al = memory(_ds, _si + 5);                 //mov al, byte ptr [si+0x5]
    _bx = memory16(_ds, _si + 44);              //mov bx, word ptr [si+0x2c]
    _ah = 0;                                    //sub ah, ah
    if (!(_bh & 0x80))                          //jz loc_29e2
        goto loc_29e2;
    _ah -= 1;                                   //dec ah
loc_29e2:                                       //loc_29e2:
    _flags.carry = (_dx + _bx) >= 0x10000;      //add dx, bx
    _dx += _bx;
    _al = _al + _ah + _flags.carry;             //adc al, ah
    _ah = _dl;                                  //mov ah, dl
    _dl = _dh;                                  //mov dl, dh
    _dh = _al;                                  //mov dh, al
    _bl = memory(_ds, _si + 2);                 //mov bl, byte ptr [si+0x2]
    sub_11bc();                                 //call sub_11bc
    _al = memory(_ds, 0x7d67);                  //mov al, [0x7d67]
    _al &= 0x70;                                //and al, 0x70
    if (_al != 0)                               //jnz loc_2a5b
        goto loc_2a5b;
    _al = memory(_ds, 0x7d67);                  //mov al, [0x7d67]
    _al &= 0x04;                                //and al, 0x4
    if (_al == 0)                               //jz loc_2a06
        goto loc_2a06;
    _STOP_("goto loc_24c4");                    //jmp loc_24c4
loc_2a06:                                       //loc_2a06:
    if (_dh == 0x00)                            //jz loc_2a1a
        goto loc_2a1a;
    if (_dl < 0x40)                             //jc loc_2a1a
        goto loc_2a1a;
    memory(_ds, _si) = 0x00;                    //mov byte ptr [si], 0x0
    return;                                     //ret
loc_2a1a:                                       //loc_2a1a:
    _al = memory(_ds, 0x7d67);                  //mov al, [0x7d67]
    _al &= 0x80;                                //and al, 0x80
    if (_al == 0)                               //jz loc_2a40
        goto loc_2a40;
    _al = memory(_ds, _si + 2);                 //mov al, byte ptr [si+0x2]
    _al &= 0x07;                                //and al, 0x7
    if (_al != 0x04)                            //jnz loc_2a5b
        goto loc_2a5b;
    _cx = memory16(_ds, 32386);                 //mov cx, word ptr [0x7e82]
    if (_dx >= _cx)                             //jnc loc_2a5b
        goto loc_2a5b;
    memory(_ds, _si + 38) = 0xff;               //mov byte ptr [si+0x26], 0xff
    return;                                     //ret
loc_2a40:                                       //loc_2a40:
    memory16(_ds, _si + 4) = _dx;               //mov word ptr [si+0x4], dx
    memory(_ds, _si + 42) = _bl;                //mov byte ptr [si+0x2a], bl
    _ax = memory16(_ds, _si + 44);              //mov ax, word ptr [si+0x2c]
    _ax += 0x0080;                              //add ax, 0x80
    if (_ah < 0x08)                             //jc loc_2a57
        goto loc_2a57;
    _ax = 0x0800;                               //mov ax, 0x800
loc_2a57:                                       //loc_2a57:
    memory16(_ds, _si + 44) = _ax;              //mov word ptr [si+0x2c], ax
    return;                                     //ret
loc_2a5b:                                       //loc_2a5b:
    _al = memory(_ds, _si + 4);                 //mov al, byte ptr [si+0x4]
    _al &= 0xf8;                                //and al, 0xf8
    _al |= 0x03;                                //or al, 0x3
    memory(_ds, _si + 4) = _al;                 //mov byte ptr [si+0x4], al
    memory16(_ds, _si + 44) = 0x0100;           //mov word ptr [si+0x2c], 0x100
    if (memory(_ds, _si + 46) == 0x00)          //jz loc_2a74
        goto loc_2a74;
    return;                                     //ret
loc_2a74:                                       //loc_2a74:
    _al = memory(_ds, 0x7d67);                  //mov al, [0x7d67]
    _al &= 0x02;                                //and al, 0x2
    if (_al == 0)                               //jz loc_2a9d
        goto loc_2a9d;
    _al = memory(_ds, _si + 2);                 //mov al, byte ptr [si+0x2]
    _al &= 0x0e;                                //and al, 0xe
    if (_al != 0x04)                            //jnz loc_2a9d
        goto loc_2a9d;
    _dx = memory16(_ds, 32386);                 //mov dx, word ptr [0x7e82]
    _ax = memory16(_ds, _si + 4);               //mov ax, word ptr [si+0x4]
    if (_dx >= _ax)                             //jnc loc_2a9d
        goto loc_2a9d;
    memory(_ds, _si + 38) = 0xff;               //mov byte ptr [si+0x26], 0xff
    return;                                     //ret
loc_2a9d:                                       //loc_2a9d:
    _bx = 0x8143;                               //mov bx, 0x8143
    if (!(memory(_ds, _si + 40) & 0x80))        //jz loc_2aac
        goto loc_2aac;
    _bx = 0x8147;                               //mov bx, 0x8147
loc_2aac:                                       //loc_2aac:
    _al = memory(_ds, _si + 2);                 //mov al, byte ptr [si+0x2]
    _al &= 0x0e;                                //and al, 0xe
    _ah = 0;                                    //sub ah, ah
    _al >>= 1;                                  //shr al, 1
    _al >>= 1;                                  //shr al, 1
    _al >>= 1;                                  //shr al, 1
    _bx += _ax;                                 //add bx, ax
    _al = memory(_ds, _bx);                     //mov al, byte ptr [bx]
    _al = _al + memory(_ds, _si + 32);          //add al, byte ptr [si+0x20]
    memory(_ds, _si + 8) = _al;                 //mov byte ptr [si+0x8], al
    _al = memory(_ds, _si + 40);                //mov al, byte ptr [si+0x28]
    _al &= _al;                                 //and al, al
    if (_al != 0)                               //jnz loc_2ad5
    {
        _flags.sign = !!(_al & 0x80);
        goto loc_2ad5;
    }
    memory(_ds, _si + 40) = 0x02;               //mov byte ptr [si+0x28], 0x2
    _al = 0x02;                                 //mov al, 0x2
    _flags.sign = !!(_al & 0x80);
loc_2ad5:                                       //loc_2ad5:
    if (!_flags.sign)                           //jns loc_2ae5
        goto loc_2ae5;
    _flags.carry = (_al + memory(_ds, _si + 2)) >= 0x100;
    _al = _al + memory(_ds, _si + 2);
    if (_flags.carry)                           //jc loc_2aef
        goto loc_2aef;
    goto loc_2b22;                              //jmp loc_2b22
    _STOP_("db 90h");                           //db 90h
loc_2ae5:                                       //loc_2ae5:
    _al = _al + memory(_ds, _si + 2);           //add al, byte ptr [si+0x2]
    if (_al >= 0xe8)                            //jnc loc_2b22
        goto loc_2b22;
loc_2aef:                                       //loc_2aef:
    _bl = _al;                                  //mov bl, al
    _dx = memory16(_ds, _si + 4);               //mov dx, word ptr [si+0x4]
    sub_11bc();                                 //call sub_11bc
    _al = memory(_ds, 0x7d67);                  //mov al, [0x7d67]
    _al &= 0xf0;                                //and al, 0xf0
    if (_al != 0)                               //jnz loc_2b22
        goto loc_2b22;
    memory(_ds, _si + 2) = _bl;                 //mov byte ptr [si+0x2], bl
    _bl &= 0x1e;                                //and bl, 0x1e
    if (_bl == 0x08)                            //jz loc_2b10
        goto loc_2b10;
    return;                                     //ret
loc_2b10:                                       //loc_2b10:
    sub_024a();                                 //call sub_024a
    _al &= 0x01;                                //and al, 0x1
    _ah = 0x02;                                 //mov ah, 0x2
    if (_al == 0)                               //jz loc_2b1e
        goto loc_2b1e;
    _ah = 0xfe;                                 //mov ah, 0xfe
loc_2b1e:                                       //loc_2b1e:
    memory(_ds, _si + 40) = _ah;                //mov byte ptr [si+0x28], ah
    return;                                     //ret
loc_2b22:                                       //loc_2b22:
    _al = memory(_ds, _si + 40);                //mov al, byte ptr [si+0x28]
    _al = -_al;                                 //neg al
    _flags.zero = !!(_al & 0x80);
    if (!_flags.zero)                                //jnz loc_2b2e
        goto loc_2b2e;
    _al = 0x02;                                 //mov al, 0x2
loc_2b2e:                                       //loc_2b2e:
    memory(_ds, _si + 40) = _al;                //mov byte ptr [si+0x28], al
}

void sub_2b32()
{
    _si = memory16(_ds, 32154);                 //mov si, word ptr [0x7d9a]
    _ch = memory(_ds, _si);                     //mov ch, byte ptr [si]
    _ch &= _ch;                                 //and ch, ch
    if (_ch != 0)                               //jnz loc_2b42
        goto loc_2b42;
    {sub_2b4d(); return; };                     //
    _STOP_("db 90h");                           //db 90h
loc_2b42:                                       //loc_2b42:
    memory16(_ds, 32154) += 0x0001;             //add word ptr [0x7d9a], 0x1
    _cl = 0x00;                                 //mov cl, 0x0
    sub_2b54();                                 //call sub_2b54
}

void sub_2b4d()
{
    _in(_al, 97);                               //in al, 0x61
    _al &= 0xfd;                                //and al, 0xfd
    _out(97, _al);                              //out 0x61, al
}

void sub_2b54()
{
    _dx = 0x0043;                               //mov dx, 0x43
    _al = 0xb6;                                 //mov al, 0xb6
    _out(_dx, _al);                             //out dx, al
    _dx -= 1;                                   //dec dx
    _al = _cl;                                  //mov al, cl
    _out(_dx, _al);                             //out dx, al
    _al = _ch;                                  //mov al, ch
    _out(_dx, _al);                             //out dx, al
    _in(_al, 97);                               //in al, 0x61
    _al |= 0x03;                                //or al, 0x3
    _out(97, _al);                              //out 0x61, al
}

void sub_2b68()
{
    _bx = 0x0003;                               //mov bx, 0x3
loc_2b6b:                                       //loc_2b6b:
    _in(_al, 97);                               //in al, 0x61
    _al &= 0xfc;                                //and al, 0xfc
    _out(97, _al);                              //out 0x61, al
    _cx = 0x0320;                               //mov cx, 0x320
loc_2b74:                                       //loc_2b74:
    if (--_cx)                                  //loop loc_2b74
        goto loc_2b74;
    _al |= 0x02;                                //or al, 0x2
    _out(97, _al);                              //out 0x61, al
    _cx = 0x02bc;                               //mov cx, 0x2bc
loc_2b7d:                                       //loc_2b7d:
    if (--_cx)                                  //loop loc_2b7d
        goto loc_2b7d;
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz loc_2b6b
        goto loc_2b6b;
}

void sub_2b83()
{
    _push(_ax);                                 //push ax
    _push(_dx);                                 //push dx
    _al = _ah;                                  //mov al, ah
    sub_2b90();                                 //call sub_2b90
    _dx = _pop();                               //pop dx
    _dl += 1;                                   //inc dl
    _dl += 1;                                   //inc dl
    _ax = _pop();                               //pop ax
    _STOP_("sp-trace-fail");                    //sub_2b83 endp_failed
    _STOP_("continues");                        //sub_2b90 proc near
}

void sub_2b90()
{
    _cx = 0x1040;                               //mov cx, 0x1040
    _ds = _cx;                                  //mov ds, cx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_cx);                                 //push cx
    _push(_es);                                 //push es
    _push(_dx);                                 //push dx
    _di = 0x8132;                               //mov di, 0x8132
    _ah = 0;                                    //sub ah, ah
    _push(_ax);                                 //push ax
    _al &= 0xf0;                                //and al, 0xf0
    _cl = 0x04;                                 //mov cl, 0x4
    _al >>= _cl;                                //shr al, cl
    _si = 0x8122;                               //mov si, 0x8122
    _si += _ax;                                 //add si, ax
    _al = memory(_ds, _si);                     //mov al, byte ptr [si]
    memory(_ds, _di) = _al;                     //mov byte ptr [di], al
    _di += 1;                                   //inc di
    _ax = _pop();                               //pop ax
    _al &= 0x0f;                                //and al, 0xf
    _si = 0x8122;                               //mov si, 0x8122
    _si += _ax;                                 //add si, ax
    _al = memory(_ds, _si);                     //mov al, byte ptr [si]
    memory(_ds, _di) = _al;                     //mov byte ptr [di], al
    _di -= 1;                                   //dec di
    _dx = _pop();                               //pop dx
    _ax = 0x1301;                               //mov ax, 0x1301
    _bx = 0x0007;                               //mov bx, 0x7
    _cx = 0x0002;                               //mov cx, 0x2
    _bp = 0x1040;                               //mov bp, 0x1040
    _es = _bp;                                  //mov es, bp
    _bp = 0x8132;                               //mov bp, 0x8132
    _interrupt(16);                             //int 0x10
    _es = _pop();                               //pop es
    _cx = _pop();                               //pop cx
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    return;                                     //ret
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
}


