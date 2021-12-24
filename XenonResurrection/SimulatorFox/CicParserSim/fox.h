void entry();
void sub_0158();
void sub_0173();
void sub_01d9();
void sub_01f8();
void sub_0244();
void sub_027b();
void sub_038a();
void sub_03ae();
void sub_03dc();
void sub_03f2();
void sub_0410();
void sub_0423();
void sub_0488();
void sub_050e();
void sub_05b7();
void sub_05c7();
void sub_065e();
void sub_0691();
void sub_06d4();
void sub_06ea();
void sub_0701();
void sub_07b0();
void sub_0805();
void sub_097b();
bool sub_0abe();
void sub_0c1e();
void sub_0c30();
void sub_0ceb();
void sub_107d();
void sub_10d3();
void sub_10ff();
void sub_1198();
void sub_11e6();
void sub_1269();
void sub_15a7();
void sub_15de();
void sub_1610();
void sub_164f();
void sub_17eb();
void sub_17fe();
void sub_183f();
void sub_18af();
void sub_191c();
void sub_1958();
void sub_1a2a();
void sub_1a59();
void sub_1a8d();
void sub_1b83();
void sub_1bb6();
void sub_1c09();
void sub_1c1a();
void sub_1c30();
void sub_1c61();
void sub_24c9();
void sub_276f();
void sub_27df();
void sub_2811();
void sub_28cd();
void sub_28f8();
void sub_2911();
void sub_294c();
void sub_2994();
void sub_29b5();
void sub_2a0d();
void sub_2ab1();
void sub_2b67();
void sub_2ba2();
void sub_2c87();
void sub_2d62();
void sub_2de8();
void sub_2df5();
void sub_2e53();
void sub_2eb7();
void sub_2f76();
void sub_2fdd();
void sub_3009();
void sub_307d();
void sub_3126();
void sub_3160();
void sub_3243();
void sub_3271();
void sub_32dc();
void sub_32f4();
void sub_3611();
void sub_3627();
void sub_372f();
void sub_378d();
void sub_37f5();
void sub_38b5();
void sub_39c7();
void sub_3d97();
void sub_3e28();
void sub_3ee8();
void sub_3f46();
void sub_3f74();
void sub_403c();
void sub_40fa();
void sub_414b();
void sub_4484();
void sub_4561();
void sub_4617();
void sub_4631();
void sub_4657();
void sub_4ae9();
void sub_4b49();
void sub_4b7d();
void sub_4bd0();
void sub_4c65();
void sub_4cf0();
void sub_4cf6();
void sub_4dc0();
void sub_4f1f();
void sub_5045();
void sub_5095();
void sub_5122();
void sub_5133();
void sub_5153();
void sub_51c6();
void sub_5252();
void sub_52ec();
void sub_5338();
void sub_53a2();
void sub_53c8();
void sub_5477();
void sub_5557();
void sub_562d();
void sub_5645();
void sub_56cc();
void sub_5737();
void sub_58b0();
void sub_58c8();
void sub_5945();
void sub_596f();
void sub_59cc();
void sub_59e7();

// imports
void sub_64ff();
void sub_6582();
void sub_65be();

bool loc_0a7e();
bool loc_0ad3();

void entry()
{
    

    _flags.interrupt = true;                    //sti
    _flags.direction = false;                   //cld
    _dx = 0xffff;                               //mov dx, 0xffff
    _si = 0x0080;                               //mov si, 0x80
    _lodsb<MemData, DirForward>();              //lodsb
    _cbw();                                     //cbw
    _cx = _ax;                                  //mov cx, ax
    if (_cx == 0)                               //jcxz loc_004f
        goto loc_004f;
loc_0013:                                       //loc_0013:
    _lodsb<MemData, DirForward>();              //lodsb
    if (_al == 0x2f)                            //jz loc_001c
        goto loc_001c;
    if (--_cx)                                  //loop loc_0013
        goto loc_0013;
    goto loc_004f;                              //jmp loc_004f
loc_001c:                                       //loc_001c:
    _lodsb<MemData, DirForward>();              //lodsb
    _al &= 0xdf;                                //and al, 0xdf
    if (_al != 0x56)                            //jnz loc_0025
        goto loc_0025;
    _dl = 0x05;                                 //mov dl, 0x5
loc_0025:                                       //loc_0025:
    if (_al != 0x45)                            //jnz loc_002b
        goto loc_002b;
    _dl = 0x03;                                 //mov dl, 0x3
loc_002b:                                       //loc_002b:
    if (_al != 0x54)                            //jnz loc_0031
        goto loc_0031;
    _dl = 0x02;                                 //mov dl, 0x2
loc_0031:                                       //loc_0031:
    if (_al != 0x43)                            //jnz loc_0037
        goto loc_0037;
    _dl = 0x01;                                 //mov dl, 0x1
loc_0037:                                       //loc_0037:
    if (_al != 0x48)                            //jnz loc_003d
        goto loc_003d;
    _dl = 0x00;                                 //mov dl, 0x0
loc_003d:                                       //loc_003d:
    if (_al != 0x42)                            //jnz loc_0043
        goto loc_0043;
    _dh = 0x00;                                 //mov dh, 0x0
loc_0043:                                       //loc_0043:
    if (_al != 0x46)                            //jnz loc_004d
        goto loc_004d;
    memory(_cs, 0x3) = 0x00;                    //mov byte ptr cs:[0x3], 0x0
loc_004d:                                       //loc_004d:
    if (--_cx)                                  //loop loc_0013
        goto loc_0013;
loc_004f:                                       //loc_004f:
    _ax = reloc(0x168f);
    _ds = _ax;                                  //mov ds, ax
    memory(_cs, 0x1) = _dl;                     //mov byte ptr cs:[0x1], dl
    memory(_cs, 0x2) = _dh;                     //mov byte ptr cs:[0x2], dh
    _ax = 0x8f01;                               //mov ax, 0x8f01
    _cl = 0x04;                                 //mov cl, 0x4
    _ax >>= _cl;                                //shr ax, cl
    _ax += 0x1690;                              //add ax, 0x1690
    memory16(_ds, 0x04c1) = _ax;                //mov [0x4c1], ax
    _push(_ds);                                 //push ds
    _ax = _ax ^ _ax;                            //xor ax, ax
    _ds = _ax;                                  //mov ds, ax
    bios16set(_ds, 144, 0x08d0);                //mov word ptr [0x90], 0x8d0
    bios16set(_ds, 146, _cs);                   //mov word ptr [0x92], cs
    _ds = _pop();                               //pop ds
    sub_17fe();                                 //call sub_17fe  - timer calib
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    sub_107d();                                 //call sub_107d -- 020d:008b
    sub_0ceb();                                 //call sub_0ceb
    sub_0701();                                 //call sub_0701
    sub_307d();                                 //call sub_307d
    sub_3160();                                 //call sub_3160
    _dx = 0x0000;                               //mov dx, 0x0
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    sub_097b();                                 //call sub_097b
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    memory16(_ds, 0x000e) = _ax;                //mov [0xe], ax
    sub_183f();                                 //call sub_183f
    sub_1198();                                 //call sub_1198
    _ax = 0x4000;                               //mov ax, 0x4000
    _out(64, _al);                              //out 0x40, al
    _al = _ah;                                  //mov al, ah
    _out(64, _al);                              //out 0x40, al
    sub_53a2();                                 //call sub_53a2 -- 20d:00b6
    sub_52ec();                                 //call sub_52ec -- 020d:00b9
    sub_24c9();                                 //call sub_24c9-- 020d:00bc
    _ax = memory16(_ds, 0x04c1);                //mov ax, [0x4c1]
    memory16(_ds, 0x000c) = _ax;                //mov [0xc], ax
loc_00c5:                                       //loc_00c5:
    _dx = memory16(_ds, 12);                    //mov dx, word ptr [0xc]
    memory16(_ds, 1217) = _dx;                  //mov word ptr [0x4c1], dx
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz loc_00e9
        goto loc_00e9;
    sub_51c6();                                 //call sub_51c6       --- main menu
    sub_3160();                                 //call sub_3160
    memory(_ds, 1051) = 0x02;                   //mov byte ptr [0x41b], 0x2
    memory(_ds, 1049) = 0x10;                   //mov byte ptr [0x419], 0x10
    memory(_ds, 1050) = 0x00;                   //mov byte ptr [0x41a], 0x0
    sub_0173();                                 //call sub_0173
loc_00e9:                                       //loc_00e9:
    sub_3160();                                 //call sub_3160
    _al = memory(_ds, 0x5250);                  //mov al, [0x5250]
    sub_2eb7();                                 //call sub_2eb7
    sub_378d();                                 //call sub_378d
    sub_56cc();                                 //call sub_56cc
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _bl = memory(_ds, 21072);                   //mov bl, byte ptr [0x5250]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _al = memory(_ds, _bx + 20620);             //mov al, byte ptr [bx+0x508c]
    _cbw();                                     //cbw
    sub_10ff();                                 //call sub_10ff
    sub_3ee8();                                 //call sub_3ee8
    sub_2d62();                                 //call sub_2d62
    sub_2c87();                                 //call sub_2c87
    sub_3271();                                 //call sub_3271
loc_0117:                                       //loc_0117:
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    memory16(_ds, 25854) += 1;                  //inc word ptr [0x64fe]
    sub_3e28();                                 //call sub_3e28
    sub_39c7();                                 //call sub_39c7
    sub_414b();                                 //call sub_414b
    sub_5945();                                 //call sub_5945
    sub_58c8();                                 //call sub_58c8
    sub_5737();                                 //call sub_5737
    sub_38b5();                                 //call sub_38b5
    sub_37f5();                                 //call sub_37f5
    sub_3f46();                                 //call sub_3f46
    sub_2ba2();                                 //call sub_2ba2
    sub_2c87();                                 //call sub_2c87
    sub_1c61();                                 //call sub_1c61
    sub_3627();                                 //call sub_3627
    if (!_flags.carry)                          //jnc loc_014c
        goto loc_014c;
    goto loc_00c5;                              //jmp loc_00c5
loc_014c:                                       //loc_014c:
    sub_05b7();                                 //call sub_05b7
    sub_0158();                                 //call sub_0158
    sub_3271();                                 //call sub_3271
    goto loc_0117;                              //jmp loc_0117
    _STOP_("db 00h");                           //db 00h
    _STOP_("sp-trace-fail");                    //entry endp_failed
    _STOP_("continues");                        //sub_0158 proc near
}

void sub_0158()
{
    

    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    if (memory(_cs, 0x16E4) != 0x03)            //jnz loc_0172
        goto loc_0172;
    if (memory(_ds, 2482) != 0x00)              //jnz loc_0172
        goto loc_0172;
    _ax = memory16(_ds, 0x0913);                //mov ax, [0x913]
    sub_10ff();                                 //call sub_10ff
loc_0172:                                       //loc_0172:
    return;
}

void sub_0173()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _ax = 0x0000;                               //mov ax, 0x0
    sub_10ff();                                 //call sub_10ff
    sub_2811();                                 //call sub_2811
    sub_01f8();                                 //call sub_01f8
    if (memory(_ds, 1050) < 0x0a)               //jc loc_01c6
        goto loc_01c6;
    sub_03f2();                                 //call sub_03f2
loc_0197:                                       //loc_0197:
    if (memory(_ds, 1050) < 0x0a)               //jc loc_01c6
        goto loc_01c6;
    _dx = 0x000a;                               //mov dx, 0xa
loc_01a1:                                       //loc_01a1:
    memory(_ds, 1050) -= 1;                     //dec byte ptr [0x41a]
    _push(_dx);                                 //push dx
    sub_0244();                                 //call sub_0244
    _dx = _pop();                               //pop dx
    _cx = 0x000f;                               //mov cx, 0xf
loc_01ad:                                       //loc_01ad:
    sub_3243();                                 //call sub_3243
    if (--_cx)                                  //loop loc_01ad
        goto loc_01ad;
    _dx -= 1;                                   //dec dx
    if (_dx != 0)                               //jnz loc_01a1
        goto loc_01a1;
    memory(_ds, 1051) += 1;                     //inc byte ptr [0x41b]
    sub_0244();                                 //call sub_0244
    _cx = 0x000a;                               //mov cx, 0xa
loc_01bf:                                       //loc_01bf:
    sub_3243();                                 //call sub_3243
    if (--_cx)                                  //loop loc_01bf
        goto loc_01bf;
    goto loc_0197;                              //jmp loc_0197
loc_01c6:                                       //loc_01c6:
    sub_0244();                                 //call sub_0244
    sub_03f2();                                 //call sub_03f2
    sub_03ae();                                 //call sub_03ae
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_01d9()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    sub_2811();                                 //call sub_2811
    sub_01f8();                                 //call sub_01f8
    sub_03f2();                                 //call sub_03f2
    sub_03ae();                                 //call sub_03ae
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_01f8()
{
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    sub_038a();                                 //call sub_038a
    memory16(_ds, 501) = 0x000d;                //mov word ptr [0x1f5], 0xd
    memory16(_ds, 503) = 0x0960;                //mov word ptr [0x1f7], 0x960
    sub_03dc();                                 //call sub_03dc
    _cl = memory(_ds, 21072);                   //mov cl, byte ptr [0x5250]
    _ch = _ch ^ _ch;                            //xor ch, ch
    _si = 0x5104;                               //mov si, 0x5104
    if (_cx == 0)                               //jcxz loc_0223
        goto loc_0223;
loc_021a:                                       //loc_021a:
    _lodsb<MemData, DirForward>();              //lodsb
    _al |= _al;                                 //or al, al
    if (_al != 0)                               //jnz loc_021a
        goto loc_021a;
    _si += 1;                                   //inc si
    if (--_cx)                                  //loop loc_021a
        goto loc_021a;
    _si -= 1;                                   //dec si
loc_0223:                                       //loc_0223:
    _bx = _bx ^ _bx;                            //xor bx, bx
loc_0225:                                       //loc_0225:
    _bx += 1;                                   //inc bx
    if (memory(_ds, _bx + _si) != 0x00)         //jnz loc_0225
        goto loc_0225;
    _bx -= 1;                                   //dec bx
    _flags.carry = _bx & 1;                     //shr bx, 1
    _bx >>= 1;
    _bl = _bl + 0x01 + _flags.carry;            //adc bl, 0x1
    memory16(_ds, 501) = 0x0014;                //mov word ptr [0x1f5], 0x14
    memory16(_ds, 503) = 0x0be0;                //mov word ptr [0x1f7], 0xbe0
    memory16(_ds, 501) -= _bx;                  //sub word ptr [0x1f5], bx
    sub_0488();                                 //call sub_0488
    //_STOP_("sp-trace-fail");                    //sub_01f8 endp_failed
    //_STOP_("continues");                        //sub_0244 proc near
    sub_0244();
}

void sub_0244()
{
    memory16(_ds, 501) = 0x000a;                //mov word ptr [0x1f5], 0xa
    memory16(_ds, 503) = 0x12c0;                //mov word ptr [0x1f7], 0x12c0
    _si = 0x0010;                               //mov si, 0x10
    sub_0488();                                 //call sub_0488
    _dl = memory(_ds, 1050);                    //mov dl, byte ptr [0x41a]
    _dh = _dh ^ _dh;                            //xor dh, dh
    sub_0423();                                 //call sub_0423
    memory16(_ds, 501) = 0x000a;                //mov word ptr [0x1f5], 0xa
    memory16(_ds, 503) = 0x14a0;                //mov word ptr [0x1f7], 0x14a0
    _si = 0x001e;                               //mov si, 0x1e
    sub_0488();                                 //call sub_0488
    _dl = memory(_ds, 1051);                    //mov dl, byte ptr [0x41b]
    _dh = _dh ^ _dh;                            //xor dh, dh
    sub_0423();                                 //call sub_0423
}

void sub_027b()
{
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_bp);                                 //push bp
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    sub_3160();                                 //call sub_3160
    sub_038a();                                 //call sub_038a
    memory16(_ds, 501) = 0x000e;                //mov word ptr [0x1f5], 0xe
    memory16(_ds, 503) = 0x0c80;                //mov word ptr [0x1f7], 0xc80
    _si = 0x002c;                               //mov si, 0x2c
    sub_0488();                                 //call sub_0488
    memory16(_ds, 501) -= 0x0004;               //sub word ptr [0x1f5], 0x4
    _dx = _dx ^ _dx;                            //xor dx, dx
    _cx = 0x0004;                               //mov cx, 0x4
loc_02aa:                                       //loc_02aa:
    memory(_ds, 1216) = 0x00;                   //mov byte ptr [0x4c0], 0x0
loc_02af:                                       //loc_02af:
    _bl = memory(_ds, 1216);                    //mov bl, byte ptr [0x4c0]
    if (_bl & 0x80)                             //jnz loc_02aa
        goto loc_02aa;
    _bh = _bh ^ _bh;                            //xor bh, bh
    _al = memory(_ds, _bx + 373);               //mov al, byte ptr [bx+0x175]
    if (_al == 0x2d)                            //jz loc_02af
        goto loc_02af;
    _ah = _al;                                  //mov ah, al
    _ah -= 0x30;                                //sub ah, 0x30
    if (_ah <= 0x09)                            //jbe loc_02cf
        goto loc_02cf;
    _ah -= 0x07;                                //sub ah, 0x7
loc_02cf:                                       //loc_02cf:
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _dl |= _ah;                                 //or dl, ah
    sub_050e();                                 //call sub_050e
    if (--_cx)                                  //loop loc_02aa
        goto loc_02aa;
    memory16(_ds, 501) = 0x000b;                //mov word ptr [0x1f5], 0xb
    memory16(_ds, 503) = 0x1040;                //mov word ptr [0x1f7], 0x1040
    _cx = _cx ^ _cx;                            //xor cx, cx
loc_02ec:                                       //loc_02ec:
    _ax = _cx;                                  //mov ax, cx
    sub_6582();                                 //call sub_6582
    if (_ax == _dx)                             //jz loc_0307
        goto loc_0307;
    _cx += 1;                                   //inc cx
    if (_cx <= 0x0014)                          //jbe loc_02ec
        goto loc_02ec;
loc_02fb:                                       //loc_02fb:
    _si = 0x0037;                               //mov si, 0x37
    sub_0488();                                 //call sub_0488
    sub_03f2();                                 //call sub_03f2
    _flags.carry = true;                        //stc
    goto loc_032a;                              //jmp loc_032a
loc_0307:                                       //loc_0307:
    _si = 0x0048;                               //mov si, 0x48
    sub_0488();                                 //call sub_0488
    _bx = _cx;                                  //mov bx, cx
    _dl = memory(_ds, _bx + 21052);             //mov dl, byte ptr [bx+0x523c]
    _dh = _dh ^ _dh;                            //xor dh, dh
    if (_dl != 0xff)                            //jnz loc_0321
        goto loc_0321;
    memory16(_ds, 501) -= 0x0009;               //sub word ptr [0x1f5], 0x9
    goto loc_02fb;                              //jmp loc_02fb
loc_0321:                                       //loc_0321:
    _push(_bx);                                 //push bx
    sub_0423();                                 //call sub_0423
    sub_03f2();                                 //call sub_03f2
    _ax = _pop();                               //pop ax
    _flags.carry = false;                       //clc
loc_032a:                                       //loc_032a:
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    return;                                     //ret
    _STOP_("db 50h");                           //db 50h
    _STOP_("db 53h");                           //db 53h
    _STOP_("db 51h");                           //db 51h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 57h");                           //db 57h
    _STOP_("db 56h");                           //db 56h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 8fh");                           //db 8fh
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db d8h");                           //db d8h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db cdh");                           //db cdh
    _STOP_("db 24h");                           //db 24h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 43h");                           //db 43h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db c7h");                           //db c7h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db f5h");                           //db f5h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db c7h");                           //db c7h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db f7h");                           //db f7h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 40h");                           //db 40h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 86h");                           //db 86h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db c7h");                           //db c7h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db f5h");                           //db f5h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db c7h");                           //db c7h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db f7h");                           //db f7h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 0ch");                           //db 0ch
    _STOP_("db beh");                           //db beh
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 20h");                           //db 20h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db a0h");                           //db a0h
    _STOP_("db 50h");                           //db 50h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 98h");                           //db 98h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 13h");                           //db 13h
    _STOP_("db 62h");                           //db 62h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db d0h");                           //db d0h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db f1h");                           //db f1h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 7bh");                           //db 7bh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db c9h");                           //db c9h
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 31h");                           //db 31h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db efh");                           //db efh
    _STOP_("db 23h");                           //db 23h
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 1fh");                           //db 1fh
    _STOP_("db 5eh");                           //db 5eh
    _STOP_("db 5fh");                           //db 5fh
    _STOP_("db 5ah");                           //db 5ah
    _STOP_("db 59h");                           //db 59h
    _STOP_("db 5bh");                           //db 5bh
    _STOP_("db 58h");                           //db 58h
    _STOP_("db c3h");                           //db c3h
    _STOP_("sp-trace-fail");                    //sub_027b endp_failed
    _STOP_("continues");                        //sub_038a proc near
}

void sub_038a()
{
    

    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _al = memory(_cs, 0x1);                     //mov al, cs:[0x1]
    if (_al == 0x05)                            //jz loc_039e
        goto loc_039e;
    if (_al >= 0x03)                            //jnc loc_03a5
        goto loc_03a5;
    return;                                     //ret
loc_039e:                                       //loc_039e:
    _dx = 0x04c4;                               //mov dx, 0x4c4
    sub_0410();                                 //call sub_0410
    return;                                     //ret
loc_03a5:                                       //loc_03a5:
    _dx = 0x04f4;                               //mov dx, 0x4f4
    _ax = 0x1002;                               //mov ax, 0x1002
    _interrupt(16);                             //int 0x10
}

void sub_03ae()
{
    

    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    sub_27df();                                 //call sub_27df
    _al = memory(_cs, 0x1);                     //mov al, cs:[0x1]
    if (_al == 0x05)                            //jz loc_03c5
        goto loc_03c5;
    if (_al >= 0x03)                            //jnc loc_03d3
        goto loc_03d3;
    return;                                     //ret
loc_03c5:                                       //loc_03c5:
    _ax = 0x1012;                               //mov ax, 0x1012
    _bx = _bx ^ _bx;                            //xor bx, bx
    _cx = 0x0010;                               //mov cx, 0x10
    _dx = 0x5057;                               //mov dx, 0x5057
    _interrupt(16);                             //int 0x10
    return;                                     //ret
loc_03d3:                                       //loc_03d3:
    _dx = 0x5035;                               //mov dx, 0x5035
    _ax = 0x1002;                               //mov ax, 0x1002
    _interrupt(16);                             //int 0x10
}

void sub_03dc()
{
    _si = 0x0059;                               //mov si, 0x59
    sub_0488();                                 //call sub_0488
    _bl = memory(_ds, 21072);                   //mov bl, byte ptr [0x5250]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _dl = memory(_ds, _bx + 21052);             //mov dl, byte ptr [bx+0x523c]
    _dh = _dh ^ _dh;                            //xor dh, dh
    sub_0423();                                 //call sub_0423
}

void sub_03f2()
{
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
loc_03f7:                                       //loc_03f7:
    sub_0805();                                 //call sub_0805
    _al = memory(_ds, 0x47e);                   //mov al, [0x47e]
    _al = _al | memory(_ds, 1067);              //or al, byte ptr [0x42b]
    //gabo
    {
        std::cout << "Ignore keyboard\n";
        _al = 1;
    }
    if (_al == 0)                               //jz loc_03f7
        goto loc_03f7;
loc_0403:                                       //loc_0403:
    sub_0805();                                 //call sub_0805
    _al = memory(_ds, 0x42b);                   //mov al, [0x42b]
    _al = _al | memory(_ds, 1150);              //or al, byte ptr [0x47e]
    if (_al != 0)                               //jnz loc_0403
        goto loc_0403;
}

void sub_0410()
{
    

    _al = memory(_cs, 0x1);                     //mov al, cs:[0x1]
    if (_al != 0x05)                            //jnz loc_0422
        goto loc_0422;
    _ax = 0x1012;                               //mov ax, 0x1012
    _bx = _bx ^ _bx;                            //xor bx, bx
    _cx = 0x0010;                               //mov cx, 0x10
    _interrupt(16);                             //int 0x10
loc_0422:                                       //loc_0422:
    return;
}

void sub_0423()
{
    memory(_ds, 1048) = 0x00;                   //mov byte ptr [0x418], 0x0
    _bx = 0x2710;                               //mov bx, 0x2710
loc_042b:                                       //loc_042b:
    _al = 0x30;                                 //mov al, 0x30
loc_042d:                                       //loc_042d:
    if (_dx < _bx)                              //jc loc_0437
        goto loc_0437;
    _dx -= _bx;                                 //sub dx, bx
    _al += 1;                                   //inc al
    goto loc_042d;                              //jmp loc_042d
loc_0437:                                       //loc_0437:
    if (_al != 0x30)                            //jnz loc_044b
        goto loc_044b;
    if (_bx == 0x0001)                          //jz loc_044b
        goto loc_044b;
    if (memory(_ds, 1048) != 0x00)              //jnz loc_044b
        goto loc_044b;
    _al = 0x20;                                 //mov al, 0x20
    goto loc_0450;                              //jmp loc_0450
loc_044b:                                       //loc_044b:
    memory(_ds, 1048) = 0x01;                   //mov byte ptr [0x418], 0x1
loc_0450:                                       //loc_0450:
    sub_050e();                                 //call sub_050e
    _ax = _bx;                                  //mov ax, bx
    _push(_dx);                                 //push dx
    _dx = _dx ^ _dx;                            //xor dx, dx
    _bx = 0x000a;                               //mov bx, 0xa
    _div(_bx);                                  //div bx
    _dx = _pop();                               //pop dx
    _bx = _ax;                                  //mov bx, ax
    _bx |= _bx;                                 //or bx, bx
    if (_bx != 0)                               //jnz loc_042b
        goto loc_042b;
    return;                                     //ret
    _STOP_("db b9h");                           //db b9h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 33h");                           //db 33h
    _STOP_("db c0h");                           //db c0h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e2h");                           //db e2h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db d0h");                           //db d0h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e2h");                           //db e2h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db d0h");                           //db d0h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e2h");                           //db e2h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db d0h");                           //db d0h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e2h");                           //db e2h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db d0h");                           //db d0h
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 76h");                           //db 76h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 30h");                           //db 30h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e2h");                           //db e2h
    _STOP_("db e1h");                           //db e1h
    _STOP_("db c3h");                           //db c3h
    _STOP_("sp-trace-fail");                    //sub_0423 endp_failed
    _STOP_("continues");                        //sub_0488 proc near
}

void sub_0488()
{
    

    _push(_ax);                                 //push ax
loc_0489:                                       //loc_0489:
    _lodsb<MemData, DirForward>();              //lodsb
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz loc_0493
        goto loc_0493;
    sub_050e();                                 //call sub_050e
    goto loc_0489;                              //jmp loc_0489
loc_0493:                                       //loc_0493:
    _ax = _pop();                               //pop ax
    return;                                     //ret
loc_0495:                                       //loc_0495:
    _dl = _al;                                  //mov dl, al
    if (memory(_ds, 1083) != 0x00)              //jnz loc_04bd
        goto loc_04bd;
    memory(_ds, 1083) += 1;                     //inc byte ptr [0x43b]
    memory16(_cs, 0x6676) = 0x0597;             //mov word ptr cs:[0x6676], 0x597
    _ds = memory16(_ds, 14);                    //mov ds, word ptr [0xe]
    _si = _si ^ _si;                            //xor si, si
    _cx = 0x0029;                               //mov cx, 0x29
loc_04b2:                                       //loc_04b2:
    _ax = 0x010c;                               //mov ax, 0x10c
    sub_65be();                                 //call sub_65be
    _si += 0x0030;                              //add si, 0x30
    if (--_cx)                                  //loop loc_04b2
        goto loc_04b2;
loc_04bd:                                       //loc_04bd:
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _di = memory16(_ds, 501);                   //mov di, word ptr [0x1f5]
    _di <<= 1;                                  //shl di, 1
    _di = _di + memory16(_ds, 503);             //add di, word ptr [0x1f7]
    memory16(_ds, 501) += 1;                    //inc word ptr [0x1f5]
    _ax = 0xb800;                               //mov ax, 0xb800
    _es = _ax;                                  //mov es, ax
    _cx = 0x0006;                               //mov cx, 0x6
    _al = _dl;                                  //mov al, dl
    if (_al != 0x20)                            //jnz loc_04ee
        goto loc_04ee;
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_04e0:                                       //loc_04e0:
    _stosw<MemData, DirForward>();              //stosw
    _di += 0x1ffe;                              //add di, 0x1ffe
    _stosw<MemData, DirForward>();              //stosw
    _di -= 0x1fb2;                              //sub di, 0x1fb2
    if (--_cx)                                  //loop loc_04e0
        goto loc_04e0;
    goto loc_050c;                              //jmp loc_050c
loc_04ee:                                       //loc_04ee:
    _al -= 0x30;                                //sub al, 0x30
    if (_al <= 0x09)                            //jbe loc_04f6
        goto loc_04f6;
    _al -= 0x02;                                //sub al, 0x2
loc_04f6:                                       //loc_04f6:
    _ds = memory16(_ds, 14);                    //mov ds, word ptr [0xe]
    _ah = 0x30;                                 //mov ah, 0x30
    _mul(_ah);                                  //mul ah
    _si = _ax;                                  //mov si, ax
loc_0500:                                       //loc_0500:
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di += 0x1ffe;                              //add di, 0x1ffe
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di -= 0x1fb2;                              //sub di, 0x1fb2
    if (--_cx)                                  //loop loc_0500
        goto loc_0500;
loc_050c:                                       //loc_050c:
    _STOP_("goto loc_058d");                    //jmp loc_058d
}

void sub_050e()
{
    

    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    if (memory(_cs, 0x1) >= 0x03)               //jnc loc_0522
        goto loc_0522;
    _STOP_("goto loc_0495");                    //jmp loc_0495
loc_0522:                                       //loc_0522:
    _di = memory16(_ds, 503);                   //mov di, word ptr [0x1f7]
    _di = _di + memory16(_ds, 501);             //add di, word ptr [0x1f5]
    _di = _di + memory16(_ds, 21096);           //add di, word ptr [0x5268]
    memory16(_ds, 501) += 1;                    //inc word ptr [0x1f5]
    if (_al != 0x20)                            //jnz loc_0556
        goto loc_0556;
    _ax = 0xa000;                               //mov ax, 0xa000
    _es = _ax;                                  //mov es, ax
    sub_32dc();                                 //call sub_32dc
    _dx = 0x03c4;                               //mov dx, 0x3c4
    _ax = 0x0f02;                               //mov ax, 0xf02
    _out(_dx, _ax);                             //out dx, ax
    _al = _al ^ _al;                            //xor al, al
    _cx = 0x000c;                               //mov cx, 0xc
loc_054a:                                       //loc_054a:
    _stosb<MemVideo, DirForward>();              //stosb
    _di += 0x0027;                              //add di, 0x27
    if (--_cx)                                  //loop loc_054a
        goto loc_054a;
    _di -= 0x01e0;                              //sub di, 0x1e0
    goto loc_058d;                              //jmp loc_058d
loc_0556:                                       //loc_0556:
    _al -= 0x30;                                //sub al, 0x30
    if (_al <= 0x09)                            //jbe loc_055e
        goto loc_055e;
    _al -= 0x02;                                //sub al, 0x2
loc_055e:                                       //loc_055e:
    _ds = memory16(_ds, 14);                    //mov ds, word ptr [0xe]
    _ah = 0x30;                                 //mov ah, 0x30
    _mul(_ah);                                  //mul ah
    _si = _ax;                                  //mov si, ax
    _ax = 0xa000;                               //mov ax, 0xa000
    _es = _ax;                                  //mov es, ax
    sub_32dc();                                 //call sub_32dc
    _dx = 0x03c4;                               //mov dx, 0x3c4
    _al = 0x02;                                 //mov al, 0x2
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _al = 0x01;                                 //mov al, 0x1
loc_0579:                                       //loc_0579:
    _out(_dx, _al);                             //out dx, al
    _cx = 0x000c;                               //mov cx, 0xc
loc_057d:                                       //loc_057d:
    _movsb<MemVideo, MemData, DirForward>();     //movsb
    _di += 0x0027;                              //add di, 0x27
    if (--_cx)                                  //loop loc_057d
        goto loc_057d;
    _di -= 0x01e0;                              //sub di, 0x1e0
    _al <<= 1;                                  //shl al, 1
    if (_al <= 0x08)                            //jbe loc_0579
        goto loc_0579;
loc_058d:                                       //loc_058d:
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    return;                                     //ret
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db aah");                           //db aah
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db ffh");                           //db ffh
    _STOP_("db ffh");                           //db ffh
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("sp-trace-fail");                    //sub_050e endp_failed
    _STOP_("continues");                        //sub_05b7 proc near
}

void sub_05b7()
{
    _flags.carry = memory(_ds, 25862) < 0x01;   //sub byte ptr [0x6506], 0x1
    memory(_ds, 25862) -= 0x01;
    memory(_ds, 25862) = memory(_ds, 25862) + 0x00 + _flags.carry;
    if (memory(_ds, 25862) == 0)                                //jz loc_05c6
        goto loc_05c6;
    sub_05c7();                                 //call sub_05c7
loc_05c6:                                       //loc_05c6:
    return;
}

void sub_05c7()
{
    

    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    if (memory(_cs, 0x1) < 0x03)                //jc loc_0636
        goto loc_0636;
    _si = memory16(_ds, 21098);                 //mov si, word ptr [0x526a]
    _si += 0x0174;                              //add si, 0x174
    _dx = 0x03c4;                               //mov dx, 0x3c4
    _ax = 0x0f02;                               //mov ax, 0xf02
    _out(_dx, _ax);                             //out dx, ax
    _dl = 0xce;                                 //mov dl, 0xce
    _ax = 0x0005;                               //mov ax, 0x5
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0003;                               //mov ax, 0x3
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0100;                               //mov ax, 0x100
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0f01;                               //mov ax, 0xf01
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0xf008;                               //mov ax, 0xf008
    _out(_dx, _ax);                             //out dx, ax
    _cl = memory(_ds, 1049);                    //mov cl, byte ptr [0x419]
    _bl = _cl;                                  //mov bl, cl
    _ch = _ch ^ _ch;                            //xor ch, ch
    _ax = 0xa000;                               //mov ax, 0xa000
    _ds = _ax;                                  //mov ds, ax
    _bp = 0x0028;                               //mov bp, 0x28
    if (_cx == 0)                               //jcxz loc_0619
        goto loc_0619;
loc_0614:                                       //loc_0614:
    sub_0691();                                 //call sub_0691
    if (--_cx)                                  //loop loc_0614
        goto loc_0614;
loc_0619:                                       //loc_0619:
    _cl = 0x10;                                 //mov cl, 0x10
    _cl -= _bl;                                 //sub cl, bl
    if (_cl == 0)                               //jz loc_0624
        goto loc_0624;
loc_061f:                                       //loc_061f:
    sub_06ea();                                 //call sub_06ea
    if (--_cx)                                  //loop loc_061f
        goto loc_061f;
loc_0624:                                       //loc_0624:
    _ax = 0x0001;                               //mov ax, 0x1
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0xff08;                               //mov ax, 0xff08
    _out(_dx, _ax);                             //out dx, ax
loc_062c:                                       //loc_062c:
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    return;                                     //ret
loc_0636:                                       //loc_0636:
    _bp = 0x004f;                               //mov bp, 0x4f
    _di = 0x02e8;                               //mov di, 0x2e8
    _es = memory16(_ds, 21090);                 //mov es, word ptr [0x5262]
    _al = 0xff;                                 //mov al, 0xff
    _cl = memory(_ds, 1049);                    //mov cl, byte ptr [0x419]
    _ch = _ch ^ _ch;                            //xor ch, ch
    if (_cx == 0)                               //jcxz loc_064f
        goto loc_064f;
loc_064a:                                       //loc_064a:
    sub_065e();                                 //call sub_065e
    if (--_cx)                                  //loop loc_064a
        goto loc_064a;
loc_064f:                                       //loc_064f:
    _cl = 0x10;                                 //mov cl, 0x10
    _cl = _cl - memory(_ds, 1049);              //sub cl, byte ptr [0x419]
    if (_cx == 0)                               //jcxz loc_062c
        goto loc_062c;
loc_0657:                                       //loc_0657:
    sub_06d4();                                 //call sub_06d4
    if (--_cx)                                  //loop loc_0657
        goto loc_0657;
    goto loc_062c;                              //jmp loc_062c
}

void sub_065e()
{
    _stosb<MemData, DirForward>();              //stosb
    _di += _bp;                                 //add di, bp
    _stosb<MemData, DirForward>();              //stosb
    _di += _bp;                                 //add di, bp
    _stosb<MemData, DirForward>();              //stosb
    _di += _bp;                                 //add di, bp
    _stosb<MemData, DirForward>();              //stosb
    _di += _bp;                                 //add di, bp
    _stosb<MemData, DirForward>();              //stosb
    _di += _bp;                                 //add di, bp
    _stosb<MemData, DirForward>();              //stosb
    _di += _bp;                                 //add di, bp
    _stosb<MemData, DirForward>();              //stosb
    _di += _bp;                                 //add di, bp
    _stosb<MemData, DirForward>();              //stosb
    _di += _bp;                                 //add di, bp
    _stosb<MemData, DirForward>();              //stosb
    _di += _bp;                                 //add di, bp
    _stosb<MemData, DirForward>();              //stosb
    _di += _bp;                                 //add di, bp
    _stosb<MemData, DirForward>();              //stosb
    _di += _bp;                                 //add di, bp
    _stosb<MemData, DirForward>();              //stosb
    _di += _bp;                                 //add di, bp
    _stosb<MemData, DirForward>();              //stosb
    _di += _bp;                                 //add di, bp
    _stosb<MemData, DirForward>();              //stosb
    _di += _bp;                                 //add di, bp
    _stosb<MemData, DirForward>();              //stosb
    _di += _bp;                                 //add di, bp
    _stosb<MemData, DirForward>();              //stosb
    _di -= 0x04af;                              //sub di, 0x4af
}

void sub_0691()
{
    memory(_ds, _si) += _al;                    //add byte ptr [si], al
    _si += _bp;                                 //add si, bp
    memory(_ds, _si) += _al;                    //add byte ptr [si], al
    _si += _bp;                                 //add si, bp
    memory(_ds, _si) += _al;                    //add byte ptr [si], al
    _si += _bp;                                 //add si, bp
    memory(_ds, _si) += _al;                    //add byte ptr [si], al
    _si += _bp;                                 //add si, bp
    memory(_ds, _si) += _al;                    //add byte ptr [si], al
    _si += _bp;                                 //add si, bp
    memory(_ds, _si) += _al;                    //add byte ptr [si], al
    _si += _bp;                                 //add si, bp
    memory(_ds, _si) += _al;                    //add byte ptr [si], al
    _si += _bp;                                 //add si, bp
    memory(_ds, _si) += _al;                    //add byte ptr [si], al
    _si += _bp;                                 //add si, bp
    memory(_ds, _si) += _al;                    //add byte ptr [si], al
    _si += _bp;                                 //add si, bp
    memory(_ds, _si) += _al;                    //add byte ptr [si], al
    _si += _bp;                                 //add si, bp
    memory(_ds, _si) += _al;                    //add byte ptr [si], al
    _si += _bp;                                 //add si, bp
    memory(_ds, _si) += _al;                    //add byte ptr [si], al
    _si += _bp;                                 //add si, bp
    memory(_ds, _si) += _al;                    //add byte ptr [si], al
    _si += _bp;                                 //add si, bp
    memory(_ds, _si) += _al;                    //add byte ptr [si], al
    _si += _bp;                                 //add si, bp
    memory(_ds, _si) += _al;                    //add byte ptr [si], al
    _si += _bp;                                 //add si, bp
    memory(_ds, _si) += _al;                    //add byte ptr [si], al
    _si -= 0x0257;                              //sub si, 0x257
}

void sub_06d4()
{
    _di += 0x01e0;                              //add di, 0x1e0
    _stosb<MemData, DirForward>();              //stosb
    _di += _bp;                                 //add di, bp
    _stosb<MemData, DirForward>();              //stosb
    _di += _bp;                                 //add di, bp
    _stosb<MemData, DirForward>();              //stosb
    _di += _bp;                                 //add di, bp
    _stosb<MemData, DirForward>();              //stosb
    _di += _bp;                                 //add di, bp
    _stosb<MemData, DirForward>();              //stosb
    _di -= 0x031f;                              //sub di, 0x31f
}

void sub_06ea()
{
    _si += 0x00f0;                              //add si, 0xf0
    memory(_ds, _si) += _al;                    //add byte ptr [si], al
    _si += _bp;                                 //add si, bp
    memory(_ds, _si) += _al;                    //add byte ptr [si], al
    _si += _bp;                                 //add si, bp
    memory(_ds, _si) += _al;                    //add byte ptr [si], al
    _si += _bp;                                 //add si, bp
    memory(_ds, _si) += _al;                    //add byte ptr [si], al
    _si -= 0x0167;                              //sub si, 0x167
}

void sub_0701()
{
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    memory(_ds, 1064) = 0x03;                   //mov byte ptr [0x428], 0x3
loc_070b:                                       //loc_070b:
    memory(_ds, 1052) = 0x00;                   //mov byte ptr [0x41c], 0x0
    memory16(_ds, 1053) = 0x0320;               //mov word ptr [0x41d], 0x320
    _dx = 0x0201;                               //mov dx, 0x201
    _cx = 0x0c80;                               //mov cx, 0xc80
    _ah = 0x03;                                 //mov ah, 0x3
    _flags.interrupt = false;                   //cli
loc_071f:                                       //loc_071f:
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x03))                          //jz loc_0727
        goto loc_0727;
    _ah &= 0x02;                                //and ah, 0x2
loc_0727:                                       //loc_0727:
    if (!(_al & 0x0c))                          //jz loc_072e
        goto loc_072e;
    _ah &= 0x01;                                //and ah, 0x1
loc_072e:                                       //loc_072e:
    if (--_cx)                                  //loop loc_071f
        goto loc_071f;
    _al = 0xff;                                 //mov al, 0xff
    if (!(_ah & 0x02))                          //jz loc_073a
        goto loc_073a;
    _al = memory(_ds, 0x42a);                   //mov al, [0x42a]
loc_073a:                                       //loc_073a:
    if (!(_ah & 0x01))                          //jz loc_0742
        goto loc_0742;
    _al = memory(_ds, 0x429);                   //mov al, [0x429]
loc_0742:                                       //loc_0742:
    memory(_ds, 0x427) = _al;                   //mov [0x427], al
    sub_07b0();                                 //call sub_07b0
    if (_flags.carry)                           //jc loc_0796
        goto loc_0796;
    if (_ax >= 0x0320)                          //jnc loc_0796
        goto loc_0796;
    if (_bx >= 0x0320)                          //jnc loc_0796
        goto loc_0796;
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz loc_0796
        goto loc_0796;
    _bx |= _bx;                                 //or bx, bx
    if (_bx == 0)                               //jz loc_0796
        goto loc_0796;
    _cl = 0x02;                                 //mov cl, 0x2
    _bp = _ax;                                  //mov bp, ax
    _ax >>= _cl;                                //shr ax, cl
    _ax -= _bp;                                 //sub ax, bp
    _ax = -_ax;                                 //neg ax
    memory16(_ds, 0x041f) = _ax;                //mov [0x41f], ax
    _ax = _bp;                                  //mov ax, bp
    _ax >>= _cl;                                //shr ax, cl
    _ax += _bp;                                 //add ax, bp
    memory16(_ds, 0x0425) = _ax;                //mov [0x425], ax
    _bp = _bx;                                  //mov bp, bx
    _bx >>= _cl;                                //shr bx, cl
    _bx -= _bp;                                 //sub bx, bp
    _bx = -_bx;                                 //neg bx
    memory16(_ds, 1057) = _bx;                  //mov word ptr [0x421], bx
    _bx = _bp;                                  //mov bx, bp
    _bx >>= _cl;                                //shr bx, cl
    _bx += _bp;                                 //add bx, bp
    memory16(_ds, 1059) = _bx;                  //mov word ptr [0x423], bx
    if (_ax >= _bx)                             //jnc loc_078f
        goto loc_078f;
    _ax = _bx;                                  //mov ax, bx
loc_078f:                                       //loc_078f:
    _ax <<= 1;                                  //shl ax, 1
    memory16(_ds, 0x041d) = _ax;                //mov [0x41d], ax
    goto loc_07ae;                              //jmp loc_07ae
loc_0796:                                       //loc_0796:
    memory(_ds, 1064) -= 1;                     //dec byte ptr [0x428]
    if (memory(_ds, 1064) == 0)                 //jz loc_07a9
        goto loc_07a9;
    _al = memory(_ds, 0x429);                   //mov al, [0x429]
    _xchg(memory(_ds, 1066), _al);              //xchg byte ptr [0x42a], al
    memory(_ds, 0x429) = _al;                   //mov [0x429], al
    goto loc_070b;                              //jmp loc_070b
loc_07a9:                                       //loc_07a9:
    memory(_ds, 1063) = 0xff;                   //mov byte ptr [0x427], 0xff
loc_07ae:                                       //loc_07ae:
    _flags.interrupt = true;                    //sti
}

void sub_07b0()
{
    _cl = memory(_ds, 1063);                    //mov cl, byte ptr [0x427]
    _flags.sign = !!(_cl & 0x80);               //or cl, cl
    _cl |= _cl;
    if (_flags.sign)                            //js loc_0802
        goto loc_0802;
    if (memory(_ds, 1052) != 0x00)              //jnz loc_0802
        goto loc_0802;
    _dx = 0x0201;                               //mov dx, 0x201
    _in(_al, _dx);                              //in al, dx
    _al >>= _cl;                                //shr al, cl
    if (_al & 0x03)                             //jnz loc_0802
        goto loc_0802;
    _al = _al ^ 0x30;                           //xor al, 0x30
    _al >>= 1;                                  //shr al, 1
    _al >>= 1;                                  //shr al, 1
    _al >>= 1;                                  //shr al, 1
    _al >>= 1;                                  //shr al, 1
    _bp = _bp ^ _bp;                            //xor bp, bp
    _di = _di ^ _di;                            //xor di, di
    _bx = _bx ^ _bx;                            //xor bx, bx
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    memory(_ds, 1067) -= _bh + _flags.carry;    //sbb byte ptr [0x42b], bh
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    memory(_ds, 1067) -= _bh + _flags.carry;    //sbb byte ptr [0x42b], bh
    _si = memory16(_ds, 1053);                  //mov si, word ptr [0x41d]
    _flags.interrupt = false;                   //cli
    _out(_dx, _al);                             //out dx, al
loc_07eb:                                       //loc_07eb:
    _in(_al, _dx);                              //in al, dx
    _al >>= _cl;                                //shr al, cl
    if (!(_al & 0x03))                          //jz loc_07fd
        goto loc_07fd;
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    _di = _di + _bp + _flags.carry;             //adc di, bp
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    _bx = _bx + _bp + _flags.carry;             //adc bx, bp
    _si -= 1;                                   //dec si
    if (_si != 0)                               //jnz loc_07eb
        goto loc_07eb;
loc_07fd:                                       //loc_07fd:
    _ax = _di;                                  //mov ax, di
    _flags.interrupt = true;                    //sti
    _flags.carry = false;                       //clc
    return;                                     //ret
loc_0802:                                       //loc_0802:
    _flags.interrupt = true;                    //sti
    _flags.carry = true;                        //stc
}

void sub_0805()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory(_ds, 0x42d) = _al;                   //mov [0x42d], al
    memory(_ds, 0x42e) = _al;                   //mov [0x42e], al
    memory(_ds, 0x42f) = _al;                   //mov [0x42f], al
    memory(_ds, 0x430) = _al;                   //mov [0x430], al
    memory(_ds, 0x42b) = _al;                   //mov [0x42b], al
    memory(_ds, 0x42c) = _al;                   //mov [0x42c], al
    sub_07b0();                                 //call sub_07b0
    if (_flags.carry)                           //jc loc_085c
        goto loc_085c;
    if (_ax > memory16(_ds, 1055))              //ja loc_0839
        goto loc_0839;
    memory(_ds, 1072) = 0xff;                   //mov byte ptr [0x430], 0xff
    goto loc_0844;                              //jmp loc_0844
loc_0839:                                       //loc_0839:
    if (_ax < memory16(_ds, 1061))              //jc loc_0844
        goto loc_0844;
    memory(_ds, 1071) = 0xff;                   //mov byte ptr [0x42f], 0xff
loc_0844:                                       //loc_0844:
    if (_bx > memory16(_ds, 1057))              //ja loc_0851
        goto loc_0851;
    memory(_ds, 1069) = 0xff;                   //mov byte ptr [0x42d], 0xff
    goto loc_085c;                              //jmp loc_085c
loc_0851:                                       //loc_0851:
    if (_bx < memory16(_ds, 1059))              //jc loc_085c
        goto loc_085c;
    memory(_ds, 1070) = 0xff;                   //mov byte ptr [0x42e], 0xff
loc_085c:                                       //loc_085c:
    _al = memory(_ds, 0x488);                   //mov al, [0x488]
    _al = _al | memory(_ds, 1212);              //or al, byte ptr [0x4bc]
    _al = _al | memory(_ds, 1129);              //or al, byte ptr [0x469]
    _al = _al | memory(_ds, 1104);              //or al, byte ptr [0x450]
    memory(_ds, 1069) |= _al;                   //or byte ptr [0x42d], al
    _al = memory(_ds, 0x490);                   //mov al, [0x490]
    _al = _al | memory(_ds, 1211);              //or al, byte ptr [0x4bb]
    _al = _al | memory(_ds, 1162);              //or al, byte ptr [0x48a]
    _al = _al | memory(_ds, 1118);              //or al, byte ptr [0x45e]
    memory(_ds, 1070) |= _al;                   //or byte ptr [0x42e], al
    _al = memory(_ds, 0x48d);                   //mov al, [0x48d]
    _al = _al | memory(_ds, 1209);              //or al, byte ptr [0x4b9]
    _al = _al | memory(_ds, 1166);              //or al, byte ptr [0x48e]
    _al = _al | memory(_ds, 1127);              //or al, byte ptr [0x467]
    memory(_ds, 1071) |= _al;                   //or byte ptr [0x42f], al
    _al = memory(_ds, 0x48b);                   //mov al, [0x48b]
    _al = _al | memory(_ds, 1210);              //or al, byte ptr [0x4ba]
    _al = _al | memory(_ds, 1131);              //or al, byte ptr [0x46b]
    _al = _al | memory(_ds, 1126);              //or al, byte ptr [0x466]
    memory(_ds, 1072) |= _al;                   //or byte ptr [0x430], al
    _al = memory(_ds, 0x45c);                   //mov al, [0x45c]
    _al = _al | memory(_ds, 1145);              //or al, byte ptr [0x479]
    _al = _al | memory(_ds, 1204);              //or al, byte ptr [0x4b4]
    _al = _al | memory(_ds, 1175);              //or al, byte ptr [0x497]
    memory(_ds, 1067) |= _al;                   //or byte ptr [0x42b], al
    _al = memory(_ds, 0x459);                   //mov al, [0x459]
    _al = _al | memory(_ds, 1156);              //or al, byte ptr [0x484]
    memory(_ds, 1068) |= _al;                   //or byte ptr [0x42c], al
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    return;                                     //ret
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db cdh");                           //db cdh
    _STOP_("db 10h");                           //db 10h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 8fh");                           //db 8fh
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db d8h");                           //db d8h
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db b3h");                           //db b3h
    _STOP_("db 6bh");                           //db 6bh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db b4h");                           //db b4h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db bah");                           //db bah
    _STOP_("db 61h");                           //db 61h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db cdh");                           //db cdh
    _STOP_("db 21h");                           //db 21h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 82h");                           //db 82h
    _STOP_("db 00h");                           //db 00h
loc_08ea:                                       //loc_08ea:
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _ax = 0x0003;                               //mov ax, 0x3
    _interrupt(16);                             //int 0x10
    _ah = 0x09;                                 //mov ah, 0x9
    _dx = 0x0077;                               //mov dx, 0x77
    _interrupt(33);                             //int 0x21
    goto loc_096c;                              //jmp loc_096c
loc_08fd:                                       //loc_08fd:
    _ax = 0x0003;                               //mov ax, 0x3
    _interrupt(16);                             //int 0x10
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _ah = 0x09;                                 //mov ah, 0x9
    _dx = 0x008a;                               //mov dx, 0x8a
    _interrupt(33);                             //int 0x21
    goto loc_096c;                              //jmp loc_096c
loc_0910:                                       //loc_0910:
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _ax = 0x0003;                               //mov ax, 0x3
    _interrupt(16);                             //int 0x10
    _di = _dx;                                  //mov di, dx
    _push(_dx);                                 //push dx
    if (memory(_ds, 1047) == 0x00)              //jz loc_092d
        goto loc_092d;
    _ah = 0x09;                                 //mov ah, 0x9
    _dx = 0x009e;                               //mov dx, 0x9e
    _interrupt(33);                             //int 0x21
    goto loc_0934;                              //jmp loc_0934
loc_092d:                                       //loc_092d:
    _ah = 0x09;                                 //mov ah, 0x9
    _dx = 0x00b1;                               //mov dx, 0xb1
    _interrupt(33);                             //int 0x21
loc_0934:                                       //loc_0934:
    _cx = 0x005a;                               //mov cx, 0x5a
    _ax = _ax ^ _ax;                            //xor ax, ax
    _repne_scasb();                             //repne scasb
    memory(_ds, _di) = 0x24;                    //mov byte ptr [di], 0x24
    _dx = _pop();                               //pop dx
    _ah = 0x09;                                 //mov ah, 0x9
    _interrupt(33);                             //int 0x21
    if (memory(_ds, 1047) == 0x01)              //jz loc_096c
        goto loc_096c;
    memory(_ds, 1219) = 0x00;                   //mov byte ptr [0x4c3], 0x0
    _ah = 0x09;                                 //mov ah, 0x9
    _dx = 0x00d5;                               //mov dx, 0xd5
    _interrupt(33);                             //int 0x21
    memory(_ds, 1216) = 0x00;                   //mov byte ptr [0x4c0], 0x0
loc_095b:                                       //loc_095b:
    _al = memory(_ds, 0x4c0);                   //mov al, [0x4c0]
    if (_al != 0x1c)                            //jnz loc_095b
        goto loc_095b;
    sub_3160();                                 //call sub_3160
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    {sub_097b(); return; };                     //
loc_096c:                                       //loc_096c:
    _ah = 0x09;                                 //mov ah, 0x9
    _dx = 0x0109;                               //mov dx, 0x109
    _interrupt(33);                             //int 0x21
    memory(_ds, 1219) = 0x00;                   //mov byte ptr [0x4c3], 0x0
    _flags.interrupt = true;                    //sti
loc_0979:                                       //loc_0979:
    goto loc_0979;                              //jmp loc_0979
}

void loc_0af6();
/*
void sub_097b()
{
    std::cout << "Calling sub_097b (cs:af2=" << memory16(_cs, 0xAF2)
    << ", cs:af4=" << memory16(_cs, 0xAF4) << ", dx="<< _dx << ")\n";

    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    memory(_cs, 0x6BB3) = 0x01;                 //mov byte ptr cs:[0x6bb3], 0x1
    _ax = 0x3d00;                               //mov ax, 0x3d00
    _interrupt(33);                             //int 0x21
    memory(_cs, 0x6BB3) = 0x00;                 //mov byte ptr cs:[0x6bb3], 0x0
    if (!_flags.carry)                          //jnc loc_0998
        goto loc_0998;
    _STOP_("goto loc_0910");                    //jmp loc_0910
loc_0998:                                       //loc_0998:
    std::cout << "Calling 0998\n";
    memory16(_cs, 0xAF2) = _ax;                 //mov cs:[0xaf2], ax
    _ax = memory16(_ds, 0x04c1);                //mov ax, [0x4c1]
    memory16(_cs, 0xAF4) = _ax;                 //mov cs:[0xaf4], ax
    _ds = _ax;                                  //mov ds, ax
    memory(_cs, 0x6BB3) = 0x01;                 //mov byte ptr cs:[0x6bb3], 0x1
    _bx = memory16(_cs, 0xAF2);                 //mov bx, word ptr cs:[0xaf2]
    _cx = 0x0006;                               //mov cx, 0x6
    _dx = 0x041a;                               //mov dx, 0x41a
    _ah = 0x3f;                                 //mov ah, 0x3f
    _interrupt(33);                             //int 0x21
    if (!_flags.carry)                          //jnc loc_09bf
        goto loc_09bf;
    _STOP_("goto loc_08fd");                    //jmp loc_08fd
loc_09bf:
    std::cout << "Calling 09bf\n";
//loc_09bf:
    memory(_cs, 0x6BB3) -= 1;                   //dec byte ptr cs:[0x6bb3]
    _si = _dx;                                  //mov si, dx
    _lodsw<MemData, DirForward>();              //lodsw
    if (_ah != 0x10)                            //jnz loc_09cf
        goto loc_09cf;
    loc_0af6();                    //jmp loc_0af6
    return;
loc_09cf:                                       //loc_09cf:
    std::cout << "Calling 09cf\n";

    _bx = _ax;                                  //mov bx, ax
    _lodsw<MemData, DirForward>();              //lodsw
    _cx = 0x0004;                               //mov cx, 0x4
loc_09d5:                                       //loc_09d5:
    std::cout << "Calling 09d5\n";

    _flags.carry = _bx & 1;                     //shr bx, 1
    _bx >>= 1;
    _rcr(_ax, 1);                               //rcr ax, 1
    if (--_cx)                                  //loop loc_09d5
        goto loc_09d5;
    _ax += 1;                                   //inc ax
    _cx = memory16(_ds, _si);                   //mov cx, word ptr [si]
    _ax = _ax + memory16(_es, 1217);            //add ax, word ptr es:[0x4c1]
    memory16(_es, 1217) = _ax;                  //mov es:[0x4c1], ax
    _ds = _ax;                                  //mov ds, ax
    _ax = memory16(_cs, 0xAF4);                 //mov ax, cs:[0xaf4]
    _es = _ax;                                  //mov es, ax
    memory(_cs, 0x6BB3) = 0x01;                 //mov byte ptr cs:[0x6bb3], 0x1
    _bx = memory16(_cs, 0xAF2);                 //mov bx, word ptr cs:[0xaf2]
    _cx = _cx;                                  //mov cx, cx
    _dx = 0x0006;                               //mov dx, 0x6
    _ah = 0x3f;                                 //mov ah, 0x3f
    _interrupt(33);                             //int 0x21
    if (!_flags.carry)                          //jnc loc_0a08
        goto loc_0a08;
    _STOP_("goto loc_08fd");                    //jmp loc_08fd
loc_0a08:                                       //loc_0a08:
    std::cout << "Calling 0a08\n";

    memory(_cs, 0x6BB3) -= 1;                   //dec byte ptr cs:[0x6bb3]
    _dl = 0x01;                                 //mov dl, 0x1
    memory16(_ds, 0) = 0x0002;                  //mov word ptr [0x0], 0x2
    _di = _di ^ _di;                            //xor di, di
loc_0a17:                                       //loc_0a17:
    //std::cout << "Calling 0a17\n";

    _bx = _bx ^ _bx;                            //xor bx, bx
    sub_0abe();                                 //call sub_0abe
    _bh |= _bh;                                 //or bh, bh
    if (_bh == 0)                               //jz loc_0a66
        goto loc_0a66;
    if (_bl < 0x02)                             //jc loc_0a35
        goto loc_0a35;
    _cl = _bl;                                  //mov cl, bl
    _ch = _ch ^ _ch;                            //xor ch, ch
    _bp = _ax;                                  //mov bp, ax
    std::cout << "Store byte at  " << _es << ":" << _di << "\n";
    if (_es >= 0xa000)
    {
        _al = memoryVideoGet(_es, _di + -1);                //mov al, byte ptr es:[di-0x1]  - mem
        _rep_stosb<MemVideo, DirForward>();          //rep stosb
    } else {
        _al = memory(_es, _di + -1);                //mov al, byte ptr es:[di-0x1]  - mem
        _rep_stosb<MemData, DirForward>();          //rep stosb
    }
    _ax = _bp;                                  //mov ax, bp
    goto loc_0a6a;                              //jmp loc_0a6a
loc_0a35:                                       //loc_0a35:
    //std::cout << "Calling 0a35\n";

    _bl |= _bl;                                 //or bl, bl
    if (_bl != 0)                               //jnz loc_0a4c
        goto loc_0a4c;
    _bx = _bx ^ _bx;                            //xor bx, bx
    sub_0abe();                                 //call sub_0abe
    _bp = _ax;                                  //mov bp, ax
    _cx = _bx;                                  //mov cx, bx
    _al = memory(_es, _di + -1);                //mov al, byte ptr es:[di-0x1]
    _rep_stosb<MemData, DirForward>();          //rep stosb
    _ax = _bp;                                  //mov ax, bp
    goto loc_0a6a;                              //jmp loc_0a6a
loc_0a4c:                                       //loc_0a4c:
    std::cout << "Calling 0a4c\n";

    _bx = _bx ^ _bx;                            //xor bx, bx
    sub_0abe();                                 //call sub_0abe
    _ch = _bl;                                  //mov ch, bl
    _bx = _bx ^ _bx;                            //xor bx, bx
    sub_0abe();                                 //call sub_0abe
    _cl = _bl;                                  //mov cl, bl
    _bp = _ax;                                  //mov bp, ax
    _al = memory(_es, _di + -1);                //mov al, byte ptr es:[di-0x1]
    _rep_stosb<MemData, DirForward>();          //rep stosb // TODO: ONLY ONCE!
    _ax = _bp;                                  //mov ax, bp
    goto loc_0a6a;                              //jmp loc_0a6a
loc_0a66:                                       //loc_0a66:
    //std::cout << "Calling 0a66\n";

    if (_es >= 0xa000)
        memoryVideoSet(_es, _di, _bl);                     //mov byte ptr es:[di], bl -- video
    else
        memory(_es, _di) = _bl;
    _di += 1;                                   //inc di
loc_0a6a:                                       //loc_0a6a:
    //std::cout << "Calling 0a6a\n";

    if (_di < 0x4000)                           //jc loc_0a17
        goto loc_0a17;
    _bx = _es;                                  //mov bx, es --- 020d:0a70 once
    _bx += 0x03ff;                              //add bx, 0x3ff
    _es = _bx;                                  //mov es, bx
    _di -= 0x3ff0;                              //sub di, 0x3ff0
    goto loc_0a6a;                              //jmp loc_0a6a
}
 */

void loc_0a17();
void sub_097b()
{
    _ax = 0x168f;                               //mov ax, 0x168f
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    memory(_cs, 0x6BB3) = 0x01;                 //mov byte ptr cs:[0x6bb3], 0x1
    _ax = 0x3d00;                               //mov ax, 0x3d00
    _interrupt(33);                             //int 0x21
    memory(_cs, 0x6BB3) = 0x00;                 //mov byte ptr cs:[0x6bb3], 0x0
    if (!_flags.carry)                          //jnc loc_0998
        goto loc_0998;
    _STOP_("goto loc_0910");                    //jmp loc_0910
loc_0998:                                       //loc_0998:
    memory16(_cs, 0xAF2) = _ax;                 //mov cs:[0xaf2], ax
    _ax = memory16(_ds, 0x04c1);                //mov ax, [0x4c1]
    memory16(_cs, 0xAF4) = _ax;                 //mov cs:[0xaf4], ax
    _ds = _ax;                                  //mov ds, ax
    memory(_cs, 0x6BB3) = 0x01;                 //mov byte ptr cs:[0x6bb3], 0x1
    _bx = memory16(_cs, 0xAF2);                 //mov bx, word ptr cs:[0xaf2]
    _cx = 0x0006;                               //mov cx, 0x6
    _dx = 0x041a;                               //mov dx, 0x41a
    _ah = 0x3f;                                 //mov ah, 0x3f
    _interrupt(33);                             //int 0x21
    if (!_flags.carry)                          //jnc loc_09bf
        goto loc_09bf;
    _STOP_("goto loc_08fd");                    //jmp loc_08fd
loc_09bf:                                       //loc_09bf:
    memory(_cs, 0x6BB3) -= 1;                   //dec byte ptr cs:[0x6bb3]
    _si = _dx;                                  //mov si, dx
    _lodsw<MemData, DirForward>();              //lodsw
    if (_ah != 0x10)                            //jnz loc_09cf
        goto loc_09cf;
    loc_0af6();                    //jmp loc_0af6
    return;
loc_09cf:                                       //loc_09cf:
    _bx = _ax;                                  //mov bx, ax
    _lodsw<MemData, DirForward>();              //lodsw
    _cx = 0x0004;                               //mov cx, 0x4
loc_09d5:                                       //loc_09d5:
    _flags.carry = _bx & 1;                     //shr bx, 1
    _bx >>= 1;
    _rcr(_ax, 1);                               //rcr ax, 1
    if (--_cx)                                  //loop loc_09d5
        goto loc_09d5;
    _ax += 1;                                   //inc ax
    _cx = memory16(_ds, _si);                   //mov cx, word ptr [si]
    _ax = _ax + memory16(_es, 1217);            //add ax, word ptr es:[0x4c1]
    memory16(_es, 1217) = _ax;                  //mov es:[0x4c1], ax
    _ds = _ax;                                  //mov ds, ax
    _ax = memory16(_cs, 0xAF4);                 //mov ax, cs:[0xaf4]
    _es = _ax;                                  //mov es, ax
    memory(_cs, 0x6BB3) = 0x01;                 //mov byte ptr cs:[0x6bb3], 0x1
    _bx = memory16(_cs, 0xAF2);                 //mov bx, word ptr cs:[0xaf2]
    _cx = _cx;                                  //mov cx, cx
    _dx = 0x0006;                               //mov dx, 0x6
    _ah = 0x3f;                                 //mov ah, 0x3f
    _interrupt(33);                             //int 0x21
    if (!_flags.carry)                          //jnc loc_0a08
        goto loc_0a08;
    _STOP_("goto loc_08fd");                    //jmp loc_08fd
loc_0a08:                                       //loc_0a08:
    memory(_cs, 0x6BB3) -= 1;                   //dec byte ptr cs:[0x6bb3]
    _dl = 0x01;                                 //mov dl, 0x1
    memory16(_ds, 0) = 0x0002;                  //mov word ptr [0x0], 0x2
    _di = _di ^ _di;                            //xor di, di
    loc_0a17();
}

void loc_0a17()
{
    std::cout << "call loc_0a17()\n";
loc_0a17:                                       //loc_0a17:
    _bx = _bx ^ _bx;                            //xor bx, bx
    {
        int check_sp = _sp;
        if (sub_0abe())                                 //call sub_0abe
            return;
        _ASSERT(_sp == check_sp);
    }
    _bh |= _bh;                                 //or bh, bh
    if (_bh == 0)                               //jz loc_0a66
        goto loc_0a66;
    if (_bl < 0x02)                             //jc loc_0a35
        goto loc_0a35;
    _cl = _bl;                                  //mov cl, bl
    _ch = _ch ^ _ch;                            //xor ch, ch
    _bp = _ax;                                  //mov bp, ax
    _al = memory(_es, _di + -1);                //mov al, byte ptr es:[di-0x1]
    _rep_stosb<MemData, DirForward>();          //rep stosb
    _ax = _bp;                                  //mov ax, bp
    goto loc_0a6a;                              //jmp loc_0a6a
loc_0a35:                                       //loc_0a35:
    _bl |= _bl;                                 //or bl, bl
    if (_bl != 0)                               //jnz loc_0a4c
        goto loc_0a4c;
    _bx = _bx ^ _bx;                            //xor bx, bx
    if (sub_0abe()) return;                                 //call sub_0abe
    _bp = _ax;                                  //mov bp, ax
    _cx = _bx;                                  //mov cx, bx
    _al = memory(_es, _di + -1);                //mov al, byte ptr es:[di-0x1]
    _rep_stosb<MemData, DirForward>();          //rep stosb
    _ax = _bp;                                  //mov ax, bp
    goto loc_0a6a;                              //jmp loc_0a6a
loc_0a4c:                                       //loc_0a4c:
    _bx = _bx ^ _bx;                            //xor bx, bx
    if (sub_0abe()) return;                                 //call sub_0abe
    _ch = _bl;                                  //mov ch, bl
    _bx = _bx ^ _bx;                            //xor bx, bx
    if (sub_0abe()) return;                                 //call sub_0abe
    _cl = _bl;                                  //mov cl, bl
    _bp = _ax;                                  //mov bp, ax
    _al = memory(_es, _di + -1);                //mov al, byte ptr es:[di-0x1]
    _rep_stosb<MemData, DirForward>();          //rep stosb
    _ax = _bp;                                  //mov ax, bp
    goto loc_0a6a;                              //jmp loc_0a6a
loc_0a66:                                       //loc_0a66:
    // differs !!!! 020d:0a66
    // 0-0, 2-8, 3-0, 5-30, 7-0, 9-18, b-0; 6-28, 8-0, a-40, c-0, e-8, 10-0
    // 0-0, 2-8, 4-0, 6-28, 8-0, a-40
    std::cout << "Write(" << _es << ":" << _di << ")=" << (int)_bl << "\n";
    memory(_es, _di) = _bl;                     //mov byte ptr es:[di], bl
    _di += 1;                                   //inc di
loc_0a6a:                                       //loc_0a6a:
    if (_di < 0x4000)                           //jc loc_0a17
        goto loc_0a17;
    _bx = _es;                                  //mov bx, es
    _bx += 0x03ff;                              //add bx, 0x3ff
    _es = _bx;                                  //mov es, bx
    _di -= 0x3ff0;                              //sub di, 0x3ff0
    goto loc_0a6a;                              //jmp loc_0a6a
}

bool loc_0a7e()                                       //loc_0a7e:
{
    std::cout << "call loc_0a7e()\n";

    memory16(_ds, 0) -= 0x0002;                 //sub word ptr [0x0], 0x2
    if (memory16(_ds, 0) != 0)                  //jnz loc_0ab9
        goto loc_0ab9;
    _push(_bx);                                 //push bx
    _push(_di);                                 //push di
    memory(_cs, 0x6BB3) = 0x01;                 //mov byte ptr cs:[0x6bb3], 0x1
    _bx = memory16(_cs, 0xAF2);                 //mov bx, word ptr cs:[0xaf2]
    _cx = 0x1000;                               //mov cx, 0x1000
    _dx = 0x041a;                               //mov dx, 0x41a
    _ah = 0x3f;                                 //mov ah, 0x3f
    _interrupt(33);                             //int 0x21
    if (!_flags.carry)                          //jnc loc_0aa1
        goto loc_0aa1;
    _STOP_("goto loc_08fd");                    //jmp loc_08fd
loc_0aa1:                                       //loc_0aa1:
    memory(_cs, 0x6BB3) -= 1;                   //dec byte ptr cs:[0x6bb3]
    memory16(_ds, 0x0000) = _ax;                //mov [0x0], ax
    _ax |= _ax;                                 //or ax, ax
    _di = _pop();                               //pop di
    _bx = _pop();                               //pop bx
    if (_ax == 0)                               //jz loc_0ad3
    {
        // TODO: drops stack frame!!!!
        return loc_0ad3(); // good TODO: exits to main func!!!!
    }
    _flags.carry = _ax & 1;                     //shr ax, 1
    _ax >>= 1;
    memory16(_ds, 0) = memory16(_ds, 0) + 0x0000 + _flags.carry;
    _si = 0x041a;                               //mov si, 0x41a
loc_0ab9:                                       //loc_0ab9:
    _lodsw<MemData, DirForward>();              //lodsw
    _xchg(_ah, _al);                            //xchg ah, al
    _dl = 0x11;                                 //mov dl, 0x11
    //_STOP_("sp-trace-fail");                    //sub_097b endp_failed
    //_STOP_("continues");                        //sub_0abe proc near
    if (sub_0abe())
    {   _ASSERT(0);
        return true;
    }
    return false;
}

bool sub_0abe()
{
loc_0abe:
    _dl -= 1;                                   //dec dl
    if (_dl == 0)                               //jz loc_0a7e
    {
        return loc_0a7e();
    }
    _flags.carry = !!(_ax & 0x8000);
    _rol(_ax, 1);                               //rol ax, 1
    if (!_flags.carry)                                //jnc loc_0ac8
        goto loc_0ac8;
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
loc_0ac8:                                       //loc_0ac8:
    _bx = memory16(_ds, _bx + 6);               //mov bx, word ptr [bx+0x6]
    _flags.sign = !!(_bh & 0x80);               //or bh, bh
    _bh |= _bh;
    if (!_flags.sign)                           //jns sub_0abe
        goto loc_0abe;
    _bh &= 0x7f;                                //and bh, 0x7f
    return false;                                     //ret
}

bool loc_0ad3()                                       //loc_0ad3:
{
    //_ax = _pop();                               //pop ax
    memory(_cs, 0x6BB3) = 0x01;                 //mov byte ptr cs:[0x6bb3], 0x1
    _bx = memory16(_cs, 0xAF2);                 //mov bx, word ptr cs:[0xaf2]
    _ah = 0x3e;                                 //mov ah, 0x3e
    _interrupt(33);                             //int 0x21
    memory(_cs, 0x6BB3) -= 1;                   //dec byte ptr cs:[0x6bb3]
    _ax = 0x168f;                               //mov ax, 0x168f
    _ds = _ax;                                  //mov ds, ax
    _ax = memory16(_cs, 0xAF4);                 //mov ax, cs:[0xaf4]
    return true;                                     //ret
}

void loc_0af6()                                       //loc_0af6:
{
    _dx = _dx ^ _dx;                            //xor dx, dx
    _cx = _cx ^ _cx;                            //xor cx, cx
    _ax = 0x4200;                               //mov ax, 0x4200
    memory(_cs, 0x6BB3) = 0x01;                 //mov byte ptr cs:[0x6bb3], 0x1
    _interrupt(33);                             //int 0x21
    memory(_cs, 0x6BB3) = 0x00;                 //mov byte ptr cs:[0x6bb3], 0x0
    _ax = 0x168f;                               //mov ax, 0x168f
    _es = _ax;                                  //mov es, ax
    _ax = memory16(_cs, 0xAF4);                 //mov ax, cs:[0xaf4]
    _ds = _ax;                                  //mov ds, ax
    _cx = 0x0004;                               //mov cx, 0x4
    _dx = 0x000e;                               //mov dx, 0xe
    _bx = memory16(_cs, 0xAF2);                 //mov bx, word ptr cs:[0xaf2]
    _ah = 0x3f;                                 //mov ah, 0x3f
    memory(_cs, 0x6BB3) = 0x01;                 //mov byte ptr cs:[0x6bb3], 0x1
    _interrupt(33);                             //int 0x21
    if (!_flags.carry)                          //jnc loc_0b30
        goto loc_0b30;
    _STOP_("goto loc_08fd");                    //jmp loc_08fd
loc_0b30:                                       //loc_0b30:
    memory(_cs, 0x6BB3) = 0x00;                 //mov byte ptr cs:[0x6bb3], 0x0
    _al = memory(_ds, 0x0f);                    //mov al, [0xf]
    _al &= 0xf0;                                //and al, 0xf0
    if (_al == 0x10)                            //jz loc_0b42
        goto loc_0b42;
    _STOP_("goto loc_08ea");                    //jmp loc_08ea
loc_0b42:                                       //loc_0b42:
    _di = _di ^ _di;                            //xor di, di
    _bx = memory16(_ds, 14);                    //mov bx, word ptr [0xe]
    _ax = memory16(_ds, 0x0010);                //mov ax, [0x10]
    _cx = 0x0004;                               //mov cx, 0x4
loc_0b4e:                                       //loc_0b4e:
    _flags.carry = _bx & 1;                     //shr bx, 1
    _bx >>= 1;
    _rcr(_ax, 1);                               //rcr ax, 1
    if (--_cx)                                  //loop loc_0b4e
        goto loc_0b4e;
    _ax += 1;                                   //inc ax
    _ax = _ax + memory16(_es, 1217);            //add ax, word ptr es:[0x4c1]
    memory16(_es, 1217) = _ax;                  //mov es:[0x4c1], ax
    _ds = _ax;                                  //mov ds, ax
    _ax = memory16(_cs, 0xAF4);                 //mov ax, cs:[0xaf4]
    _es = _ax;                                  //mov es, ax
    memory16(_ds, 0) = _di;                     //mov word ptr [0x0], di
    memory16(_ds, 2) = _di;                     //mov word ptr [0x2], di
loc_0b6e:                                       //loc_0b6e:
    sub_0c1e();                                 //call sub_0c1e
    sub_0c30();                                 //call sub_0c30
    if (_ax == 0x0101)                          //jz loc_0b8b
        goto loc_0b8b;
    memory16(_ds, 0x0005) = _ax;                //mov [0x5], ax
    memory(_ds, 0x04) = _al;                    //mov [0x4], al
    _stosb<MemData, DirForward>();              //stosb
loc_0b80:                                       //loc_0b80:
    sub_0c30();                                 //call sub_0c30
    if (_ax == 0x0100)                          //jz loc_0b6e
        goto loc_0b6e;
loc_0b8b:                                       //loc_0b8b:
    if (_ax == 0x0101)                          //jz loc_0c02
        goto loc_0c02;
    memory16(_ds, 0x0007) = _ax;                //mov [0x7], ax
    _si = 0x4010;                               //mov si, 0x4010
    if (memory16(_ds, 12) > _ax)                //ja loc_0ba3
        goto loc_0ba3;
    _dl = memory(_ds, 4);                       //mov dl, byte ptr [0x4]
    memory(_ds, _si) = _dl;                     //mov byte ptr [si], dl
    _si += 1;                                   //inc si
    _ax = memory16(_ds, 0x0005);                //mov ax, [0x5]
loc_0ba3:                                       //loc_0ba3:
    _ah |= _ah;                                 //or ah, ah
    if (_ah == 0)                               //jz loc_0bb8
        goto loc_0bb8;
    _bx = _ax;                                  //mov bx, ax
    _dl = memory(_ds, _bx + 4112);              //mov dl, byte ptr [bx+0x1010]
    memory(_ds, _si) = _dl;                     //mov byte ptr [si], dl
    _si += 1;                                   //inc si
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _bx + 8208);            //mov ax, word ptr [bx+0x2010]
    goto loc_0ba3;                              //jmp loc_0ba3
loc_0bb8:                                       //loc_0bb8:
    memory(_ds, _si) = _al;                     //mov byte ptr [si], al
    _si += 1;                                   //inc si
    memory(_ds, 0x04) = _al;                    //mov [0x4], al
loc_0bbe:                                       //loc_0bbe:
    _si -= 1;                                   //dec si
    _al = memory(_ds, _si);                     //mov al, byte ptr [si]
    _stosb<MemData, DirForward>();              //stosb
    if (_di < 0x8000)                           //jc loc_0bd3
        goto loc_0bd3;
    _ax = _es;                                  //mov ax, es
    _ax += 0x0800;                              //add ax, 0x800
    _es = _ax;                                  //mov es, ax
    _di -= 0x8000;                              //sub di, 0x8000
loc_0bd3:                                       //loc_0bd3:
    if (_si != 0x4010)                          //jnz loc_0bbe
        goto loc_0bbe;
    _bx = memory16(_ds, 12);                    //mov bx, word ptr [0xc]
    if (_bx >= 0x1000)                          //jnc loc_0bf9
        goto loc_0bf9;
    _dl = memory(_ds, 4);                       //mov dl, byte ptr [0x4]
    memory(_ds, _bx + 4112) = _dl;              //mov byte ptr [bx+0x1010], dl
    _dx = memory16(_ds, 5);                     //mov dx, word ptr [0x5]
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 8208) = _dx;            //mov word ptr [bx+0x2010], dx
    memory16(_ds, 12) += 1;                     //inc word ptr [0xc]
loc_0bf9:                                       //loc_0bf9:
    _ax = memory16(_ds, 0x0007);                //mov ax, [0x7]
    memory16(_ds, 0x0005) = _ax;                //mov [0x5], ax
    goto loc_0b80;                              //jmp loc_0b80
loc_0c02:                                       //loc_0c02:
    memory(_ds, 1219) = 0x01;                   //mov byte ptr [0x4c3], 0x1
    _bx = memory16(_cs, 0xAF2);                 //mov bx, word ptr cs:[0xaf2]
    _ah = 0x3e;                                 //mov ah, 0x3e
    _interrupt(33);                             //int 0x21
    memory(_ds, 1219) -= 1;                     //dec byte ptr [0x4c3]
    _ax = 0x168f;                               //mov ax, 0x168f
    _ds = _ax;                                  //mov ds, ax
    _ax = memory16(_cs, 0xAF4);                 //mov ax, cs:[0xaf4]
}

/*
void sub_0abe()
{
loc_0abe:
    

    _dl -= 1;                                   //dec dl
    if (_dl == 0)                               //jz loc_0a7e
    {
        loc_0a7e();
        return;
    }
    _flags.carry = !!(_ax & 0x8000); // check
    _rol(_ax, 1);                               //rol ax, 1
    if (!_flags.carry)                                //jnc loc_0ac8
        goto loc_0ac8;
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
loc_0ac8:                                       //loc_0ac8:
    _bx = memory16(_ds, _bx + 6);               //mov bx, word ptr [bx+0x6]
    _flags.sign = !!(_bh & 0x80);               //or bh, bh
    _bh |= _bh;
    if (!_flags.sign)                           //jns sub_0abe
        goto loc_0abe;
    _bh &= 0x7f;                                //and bh, 0x7f
    return;                                     //ret
}
void loc_0ad3()                                       //loc_0ad3:
{
    _ax = _pop();                               //pop ax
    memory(_cs, 0x6BB3) = 0x01;                 //mov byte ptr cs:[0x6bb3], 0x1
    _bx = memory16(_cs, 0xAF2);                 //mov bx, word ptr cs:[0xaf2]
    _ah = 0x3e;                                 //mov ah, 0x3e
    _interrupt(33);                             //int 0x21
    memory(_cs, 0x6BB3) -= 1;                   //dec byte ptr cs:[0x6bb3]
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _ax = memory16(_cs, 0xAF4);                 //mov ax, cs:[0xaf4]
    return;                                     //ret
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
}
 */
/*
void loc_0af6()                                       //loc_0af6:
{
    _dx = _dx ^ _dx;                            //xor dx, dx
    _cx = _cx ^ _cx;                            //xor cx, cx
    _ax = 0x4200;                               //mov ax, 0x4200
    memory(_cs, 0x6BB3) = 0x01;                 //mov byte ptr cs:[0x6bb3], 0x1
    _interrupt(33);                             //int 0x21
    memory(_cs, 0x6BB3) = 0x00;                 //mov byte ptr cs:[0x6bb3], 0x0
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _es = _ax;                                  //mov es, ax
    _ax = memory16(_cs, 0xAF4);                 //mov ax, cs:[0xaf4]
    _ds = _ax;                                  //mov ds, ax
    _cx = 0x0004;                               //mov cx, 0x4
    _dx = 0x000e;                               //mov dx, 0xe
    _bx = memory16(_cs, 0xAF2);                 //mov bx, word ptr cs:[0xaf2]
    _ah = 0x3f;                                 //mov ah, 0x3f
    memory(_cs, 0x6BB3) = 0x01;                 //mov byte ptr cs:[0x6bb3], 0x1
    _interrupt(33);                             //int 0x21
    if (!_flags.carry)                          //jnc loc_0b30
        goto loc_0b30;
    _STOP_("goto loc_08fd");                    //jmp loc_08fd
loc_0b30:                                       //loc_0b30:
    memory(_cs, 0x6BB3) = 0x00;                 //mov byte ptr cs:[0x6bb3], 0x0
    _al = memory(_ds, 0x0f);                    //mov al, [0xf]
    _al &= 0xf0;                                //and al, 0xf0
    if (_al == 0x10)                            //jz loc_0b42
        goto loc_0b42;
    _STOP_("goto loc_08ea");                    //jmp loc_08ea
loc_0b42:                                       //loc_0b42:
    _di = _di ^ _di;                            //xor di, di
    _bx = memory16(_ds, 14);                    //mov bx, word ptr [0xe]
    _ax = memory16(_ds, 0x0010);                //mov ax, [0x10]
    _cx = 0x0004;                               //mov cx, 0x4
loc_0b4e:                                       //loc_0b4e:
    _flags.carry = _bx & 1;                     //shr bx, 1
    _bx >>= 1;
    _rcr(_ax, 1);                               //rcr ax, 1
    if (--_cx)                                  //loop loc_0b4e
        goto loc_0b4e;
    _ax += 1;                                   //inc ax
    {
        int f =memory16(_es, 1217);
        f = f;
    }
    _ax = _ax + reloc(memory16(_es, 1217));            //add ax, word ptr es:[0x4c1]
    memory16(_es, 1217) = _ax;                  //mov es:[0x4c1], ax
    _ds = _ax;                                  //mov ds, ax
    _ax = reloc(memory16(_cs, 0xAF4));                 //mov ax, cs:[0xaf4]
    _es = _ax;                                  //mov es, ax
    memory16(_ds, 0) = _di;                     //mov word ptr [0x0], di
    memory16(_ds, 2) = _di;                     //mov word ptr [0x2], di
loc_0b6e:                                       //loc_0b6e:
    sub_0c1e();                                 //call sub_0c1e
    sub_0c30();                                 //call sub_0c30
    if (_ax == 0x0101)                          //jz loc_0b8b
        goto loc_0b8b;
    memory16(_ds, 0x0005) = _ax;                //mov [0x5], ax
    memory(_ds, 0x04) = _al;                    //mov [0x4], al
    _stosb<MemData, DirForward>();              //stosb
loc_0b80:                                       //loc_0b80:
    sub_0c30();                                 //call sub_0c30
    if (_ax == 0x0100)                          //jz loc_0b6e
        goto loc_0b6e;
loc_0b8b:                                       //loc_0b8b:
    if (_ax == 0x0101)                          //jz loc_0c02
        goto loc_0c02;
    memory16(_ds, 0x0007) = _ax;                //mov [0x7], ax
    _si = 0x4010;                               //mov si, 0x4010
    if (memory16(_ds, 12) > _ax)                //ja loc_0ba3
        goto loc_0ba3;
    _dl = memory(_ds, 4);                       //mov dl, byte ptr [0x4]
    memory(_ds, _si) = _dl;                     //mov byte ptr [si], dl
    _si += 1;                                   //inc si
    _ax = memory16(_ds, 0x0005);                //mov ax, [0x5]
loc_0ba3:                                       //loc_0ba3:
    _ah |= _ah;                                 //or ah, ah
    if (_ah == 0)                               //jz loc_0bb8
        goto loc_0bb8;
    _bx = _ax;                                  //mov bx, ax
    _dl = memory(_ds, _bx + 4112);              //mov dl, byte ptr [bx+0x1010]
    memory(_ds, _si) = _dl;                     //mov byte ptr [si], dl
    _si += 1;                                   //inc si
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _bx + 8208);            //mov ax, word ptr [bx+0x2010]
    goto loc_0ba3;                              //jmp loc_0ba3
loc_0bb8:                                       //loc_0bb8:
    memory(_ds, _si) = _al;                     //mov byte ptr [si], al
    _si += 1;                                   //inc si
    memory(_ds, 0x04) = _al;                    //mov [0x4], al
loc_0bbe:                                       //loc_0bbe:
    _si -= 1;                                   //dec si
    _al = memory(_ds, _si);                     //mov al, byte ptr [si]
    _stosb<MemData, DirForward>();              //stosb
    if (_di < 0x8000)                           //jc loc_0bd3
        goto loc_0bd3;
    _ax = _es;                                  //mov ax, es
    _ax += 0x0800;                              //add ax, 0x800
    _es = _ax;                                  //mov es, ax
    _di -= 0x8000;                              //sub di, 0x8000
loc_0bd3:                                       //loc_0bd3:
    if (_si != 0x4010)                          //jnz loc_0bbe
        goto loc_0bbe;
    _bx = memory16(_ds, 12);                    //mov bx, word ptr [0xc]
    if (_bx >= 0x1000)                          //jnc loc_0bf9
        goto loc_0bf9;
    _dl = memory(_ds, 4);                       //mov dl, byte ptr [0x4]
    memory(_ds, _bx + 4112) = _dl;              //mov byte ptr [bx+0x1010], dl
    _dx = memory16(_ds, 5);                     //mov dx, word ptr [0x5]
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 8208) = _dx;            //mov word ptr [bx+0x2010], dx
    memory16(_ds, 12) += 1;                     //inc word ptr [0xc]
loc_0bf9:                                       //loc_0bf9:
    _ax = memory16(_ds, 0x0007);                //mov ax, [0x7]
    memory16(_ds, 0x0005) = _ax;                //mov [0x5], ax
    goto loc_0b80;                              //jmp loc_0b80
loc_0c02:                                       //loc_0c02:
    memory(_ds, 1219) = 0x01;                   //mov byte ptr [0x4c3], 0x1
    _bx = memory16(_cs, 0xAF2);                 //mov bx, word ptr cs:[0xaf2]
    _ah = 0x3e;                                 //mov ah, 0x3e
    _interrupt(33);                             //int 0x21
    memory(_ds, 1219) -= 1;                     //dec byte ptr [0x4c3]
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _ax = memory16(_cs, 0xAF4);                 //mov ax, cs:[0xaf4]
}
*/
void sub_0c1e()
{
    memory16(_ds, 10) = 0x0200;                 //mov word ptr [0xa], 0x200
    memory(_ds, 9) = 0x09;                      //mov byte ptr [0x9], 0x9
    memory16(_ds, 12) = 0x0102;                 //mov word ptr [0xc], 0x102
}

void sub_0c30()
{
    

    _ax = memory16(_ds, 0x000c);                //mov ax, [0xc]
    if (memory16(_ds, 10) != _ax)               //jnz loc_0c48
        goto loc_0c48;
    if (memory(_ds, 9) == 0x0c)                 //jz loc_0c48
        goto loc_0c48;
    memory(_ds, 9) += 1;                        //inc byte ptr [0x9]
    memory16(_ds, 10) <<= 1;                    //shl word ptr [0xa], 1
loc_0c48:                                       //loc_0c48:
    _bx = memory16(_ds, 2);                     //mov bx, word ptr [0x2]
    _si = _bx;                                  //mov si, bx
    _flags.carry = (_bl + memory(_ds, 9)) >= 0x100;//add bl, byte ptr [0x9]
    _bl = _bl + memory(_ds, 9);
    _bh = _bh + 0x00 + _flags.carry;            //adc bh, 0x0
    if (memory16(_ds, 0) >= _bx)                //jnc loc_0caf
        goto loc_0caf;
    _cx = 0x1000;                               //mov cx, 0x1000
    _dx = 0x0010;                               //mov dx, 0x10
    _bx = 0x0010;                               //mov bx, 0x10
    _bx = _bx - memory16(_ds, 0);               //sub bx, word ptr [0x0]
    _bx = _bx + memory16(_ds, 2);               //add bx, word ptr [0x2]
    memory16(_ds, 2) = _bx;                     //mov word ptr [0x2], bx
    _si = _bx;                                  //mov si, bx
    _ax = memory16(_ds, 0x100e);                //mov ax, [0x100e]
    memory16(_ds, 0x000e) = _ax;                //mov [0xe], ax
    _bx = memory16(_cs, 0xAF2);                 //mov bx, word ptr cs:[0xaf2]
    _ah = 0x3f;                                 //mov ah, 0x3f
    memory(_cs, 0x6BB3) = 0x01;                 //mov byte ptr cs:[0x6bb3], 0x1
    _interrupt(33);                             //int 0x21
    if (!_flags.carry)                          //jnc loc_0c8c
        goto loc_0c8c;
    _STOP_("goto loc_08fd");                    //jmp loc_08fd
loc_0c8c:                                       //loc_0c8c:
    memory(_cs, 0x6BB3) -= 1;                   //dec byte ptr cs:[0x6bb3]
    _ax += 1;                                   //inc ax
    _ax += 1;                                   //inc ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    memory16(_ds, 0x0000) = _ax;                //mov [0x0], ax
    _push(_di);                                 //push di
    _di >>= 1;                                  //shr di, 1
    _di >>= 1;                                  //shr di, 1
    _di >>= 1;                                  //shr di, 1
    _di >>= 1;                                  //shr di, 1
    _ax = _es;                                  //mov ax, es
    _ax += _di;                                 //add ax, di
    _es = _ax;                                  //mov es, ax
    _di = _pop();                               //pop di
    _di &= 0x000f;                              //and di, 0xf
loc_0caf:                                       //loc_0caf:
    _cx = _si;                                  //mov cx, si
    _si >>= 1;                                  //shr si, 1
    _si >>= 1;                                  //shr si, 1
    _si >>= 1;                                  //shr si, 1
    _cl &= 0x07;                                //and cl, 0x7
    _ax = memory16(_ds, _si + 14);              //mov ax, word ptr [si+0xe]
    _xchg(_ah, _al);                            //xchg ah, al
    _dh = _dh ^ _dh;                            //xor dh, dh
    _ax <<= _cl;                                //shl ax, cl
    _ch = 0x10;                                 //mov ch, 0x10
    _ch -= _cl;                                 //sub ch, cl
    _flags.carry = _ch < memory(_ds, 9);        //sub ch, byte ptr [0x9]
    _ch = _ch - memory(_ds, 9);
    if (!_flags.carry)                          //jnc loc_0cd8
        goto loc_0cd8;
    _ch = -_ch;                                 //neg ch
    _cl = 0x08;                                 //mov cl, 0x8
    _cl -= _ch;                                 //sub cl, ch
    _dh = memory(_ds, _si + 16);                //mov dh, byte ptr [si+0x10]
    _dh >>= _cl;                                //shr dh, cl
loc_0cd8:                                       //loc_0cd8:
    _bl = memory(_ds, 9);                       //mov bl, byte ptr [0x9]
    _bh = _bh ^ _bh;                            //xor bh, bh
    memory16(_ds, 2) += _bx;                    //add word ptr [0x2], bx
    _cl = 0x10;                                 //mov cl, 0x10
    _cl -= _bl;                                 //sub cl, bl
    _ax >>= _cl;                                //shr ax, cl
    _al |= _dh;                                 //or al, dh
}

void sub_0ceb()
{
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _es = _ax;                                  //mov es, ax
    _si = 0x0433;                               //mov si, 0x433
    _di = 0x0020;                               //mov di, 0x20
    _cx = 0x0004;                               //mov cx, 0x4
    _flags.interrupt = false;                   //cli
    _flags.direction = false;                   //cld
loc_0d05:                                       //loc_0d05:
    _ax = bios16get(_es, _di);                   //mov ax, word ptr es:[di]
    _xchg(memory16(_ds, _si), _ax);             //xchg word ptr [si], ax
    _stosw<MemBios, DirForward>();              //stosw
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    if (--_cx)                                  //loop loc_0d05
        goto loc_0d05;
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    _di = 0x0440;                               //mov di, 0x440
    _ax = _ax ^ _ax;                            //xor ax, ax
    _cx = 0x0040;                               //mov cx, 0x40
    _rep_stosw<MemData, DirForward>();          //rep stosw
    _flags.interrupt = true;                    //sti
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
    return;                                     //ret
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 23h");                           //db 23h
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db 8ch");                           //db 8ch
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 25h");                           //db 25h
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 8fh");                           //db 8fh
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db d8h");                           //db d8h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 36h");                           //db 36h
    _STOP_("db 35h");                           //db 35h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 36h");                           //db 36h
    _STOP_("db 33h");                           //db 33h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 25h");                           //db 25h
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db a1h");                           //db a1h
    _STOP_("db 23h");                           //db 23h
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db cbh");                           //db cbh
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 53h");                           //db 53h
    _STOP_("db 50h");                           //db 50h
    _STOP_("db fch");                           //db fch
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 8fh");                           //db 8fh
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db d8h");                           //db d8h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 60h");                           //db 60h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db d8h");                           //db d8h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 61h");                           //db 61h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db e0h");                           //db e0h
    _STOP_("db 0ch");                           //db 0ch
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 61h");                           //db 61h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db c4h");                           //db c4h
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 61h");                           //db 61h
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db fbh");                           //db fbh
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db b3h");                           //db b3h
    _STOP_("db 6bh");                           //db 6bh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 7eh");                           //db 7eh
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db cdh");                           //db cdh
    _STOP_("db 10h");                           //db 10h
    _STOP_("db beh");                           //db beh
    _STOP_("db 27h");                           //db 27h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db b9h");                           //db b9h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db b4h");                           //db b4h
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db bbh");                           //db bbh
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db ach");                           //db ach
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db cdh");                           //db cdh
    _STOP_("db 10h");                           //db 10h
    _STOP_("db ebh");                           //db ebh
    _STOP_("db f7h");                           //db f7h
    _STOP_("db 32h");                           //db 32h
    _STOP_("db c0h");                           //db c0h
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 40h");                           //db 40h
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 40h");                           //db 40h
    _STOP_("db bah");                           //db bah
    _STOP_("db 40h");                           //db 40h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db ech");                           //db ech
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db e0h");                           //db e0h
    _STOP_("db ech");                           //db ech
    _STOP_("db 86h");                           //db 86h
    _STOP_("db c4h");                           //db c4h
    _STOP_("db 3dh");                           //db 3dh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db f0h");                           //db f0h
    _STOP_("db 72h");                           //db 72h
    _STOP_("db f5h");                           //db f5h
    _STOP_("db ech");                           //db ech
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db e0h");                           //db e0h
    _STOP_("db ech");                           //db ech
    _STOP_("db 86h");                           //db 86h
    _STOP_("db c4h");                           //db c4h
    _STOP_("db 3dh");                           //db 3dh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 40h");                           //db 40h
    _STOP_("db 77h");                           //db 77h
    _STOP_("db f5h");                           //db f5h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db cdh");                           //db cdh
    _STOP_("db 10h");                           //db 10h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 30h");                           //db 30h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db b0h");                           //db b0h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 42h");                           //db 42h
    _STOP_("db 32h");                           //db 32h
    _STOP_("db c0h");                           //db c0h
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 42h");                           //db 42h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 61h");                           //db 61h
    _STOP_("db 24h");                           //db 24h
    _STOP_("db fch");                           //db fch
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 61h");                           //db 61h
    _STOP_("db 8ch");                           //db 8ch
    _STOP_("db c8h");                           //db c8h
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db c0h");                           //db c0h
    _STOP_("db b9h");                           //db b9h
    _STOP_("db c9h");                           //db c9h
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db 33h");                           //db 33h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db f3h");                           //db f3h
    _STOP_("db aah");                           //db aah
    _STOP_("db bfh");                           //db bfh
    _STOP_("db f9h");                           //db f9h
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db bah");                           //db bah
    _STOP_("db 5eh");                           //db 5eh
    _STOP_("db 01h");                           //db 01h
    _STOP_("db b9h");                           //db b9h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db f3h");                           //db f3h
    _STOP_("db aah");                           //db aah
    _STOP_("db 81h");                           //db 81h
    _STOP_("db efh");                           //db efh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 40h");                           //db 40h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 4ah");                           //db 4ah
    _STOP_("db 75h");                           //db 75h
    _STOP_("db efh");                           //db efh
    _STOP_("db b0h");                           //db b0h
    _STOP_("db 20h");                           //db 20h
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 20h");                           //db 20h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 4ch");                           //db 4ch
    _STOP_("db cdh");                           //db cdh
    _STOP_("db 21h");                           //db 21h
    _STOP_("db eah");                           //db eah
    _STOP_("db f0h");                           //db f0h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db f0h");                           //db f0h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db fbh");                           //db fbh
    _STOP_("db 3dh");                           //db 3dh
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 36h");                           //db 36h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db e3h");                           //db e3h
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 61h");                           //db 61h
    _STOP_("db 24h");                           //db 24h
    _STOP_("db fch");                           //db fch
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db f6h");                           //db f6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 0ch");                           //db 0ch
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 61h");                           //db 61h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e3h");                           //db e3h
    _STOP_("db 7fh");                           //db 7fh
    _STOP_("db 32h");                           //db 32h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db a0h");                           //db a0h
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 98h");                           //db 98h
    _STOP_("db f6h");                           //db f6h
    _STOP_("db d4h");                           //db d4h
    _STOP_("db 88h");                           //db 88h
    _STOP_("db a7h");                           //db a7h
    _STOP_("db 40h");                           //db 40h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db 20h");                           //db 20h
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 20h");                           //db 20h
    _STOP_("db 58h");                           //db 58h
    _STOP_("db 5bh");                           //db 5bh
    _STOP_("db 1fh");                           //db 1fh
    _STOP_("db cfh");                           //db cfh
    _STOP_("db 50h");                           //db 50h
    _STOP_("db 53h");                           //db 53h
    _STOP_("db 51h");                           //db 51h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 57h");                           //db 57h
    _STOP_("db 56h");                           //db 56h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db fah");                           //db fah
    _STOP_("db 33h");                           //db 33h
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db d8h");                           //db d8h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db cfh");                           //db cfh
    _STOP_("db c4h");                           //db c4h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 0ch");                           //db 0ch
    _STOP_("db 00h");                           //db 00h
    _STOP_("db aah");                           //db aah
    _STOP_("db c7h");                           //db c7h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 28h");                           //db 28h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 8ch");                           //db 8ch
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 9ch");                           //db 9ch
    _STOP_("db 58h");                           //db 58h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db cch");                           //db cch
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 50h");                           //db 50h
    _STOP_("db 9dh");                           //db 9dh
    _STOP_("db fbh");                           //db fbh
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 8fh");                           //db 8fh
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 33h");                           //db 33h
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db d8h");                           //db d8h
    _STOP_("db bbh");                           //db bbh
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db b5h");                           //db b5h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db b1h");                           //db b1h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 33h");                           //db 33h
    _STOP_("db d2h");                           //db d2h
    _STOP_("db 9ch");                           //db 9ch
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 4ch");                           //db 4ch
    _STOP_("db 00h");                           //db 00h
    _STOP_("db fah");                           //db fah
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db a1h");                           //db a1h
    _STOP_("db fch");                           //db fch
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db feh");                           //db feh
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 12h");                           //db 12h
    _STOP_("db feh");                           //db feh
    _STOP_("db c1h");                           //db c1h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db f9h");                           //db f9h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db 75h");                           //db 75h
    _STOP_("db e3h");                           //db e3h
    _STOP_("db feh");                           //db feh
    _STOP_("db c5h");                           //db c5h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db fdh");                           //db fdh
    _STOP_("db 27h");                           //db 27h
    _STOP_("db 76h");                           //db 76h
    _STOP_("db dah");                           //db dah
    _STOP_("db b4h");                           //db b4h
    _STOP_("db 4ch");                           //db 4ch
    _STOP_("db cdh");                           //db cdh
    _STOP_("db 21h");                           //db 21h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 8fh");                           //db 8fh
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db d8h");                           //db d8h
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db c0h");                           //db c0h
    _STOP_("db b4h");                           //db b4h
    _STOP_("db 19h");                           //db 19h
    _STOP_("db cdh");                           //db cdh
    _STOP_("db 21h");                           //db 21h
    _STOP_("db 24h");                           //db 24h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db a2h");                           //db a2h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 59h");                           //db 59h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 73h");                           //db 73h
    _STOP_("db 37h");                           //db 37h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 54h");                           //db 54h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 73h");                           //db 73h
    _STOP_("db 32h");                           //db 32h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 36h");                           //db 36h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 4ah");                           //db 4ah
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 73h");                           //db 73h
    _STOP_("db 28h");                           //db 28h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 73h");                           //db 73h
    _STOP_("db 23h");                           //db 23h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db cdh");                           //db cdh
    _STOP_("db 10h");                           //db 10h
    _STOP_("db bah");                           //db bah
    _STOP_("db f9h");                           //db f9h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db b4h");                           //db b4h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db cdh");                           //db cdh
    _STOP_("db 21h");                           //db 21h
    _STOP_("db b4h");                           //db b4h
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db a0h");                           //db a0h
    _STOP_("db 14h");                           //db 14h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 30h");                           //db 30h
    _STOP_("db cdh");                           //db cdh
    _STOP_("db 10h");                           //db 10h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db 2dh");                           //db 2dh
    _STOP_("db cdh");                           //db cdh
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 15h");                           //db 15h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 29h");                           //db 29h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db fah");                           //db fah
    _STOP_("db 9ch");                           //db 9ch
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 17h");                           //db 17h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db b4h");                           //db b4h
    _STOP_("db 19h");                           //db 19h
    _STOP_("db cdh");                           //db cdh
    _STOP_("db 21h");                           //db 21h
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 17h");                           //db 17h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 9dh");                           //db 9dh
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 1fh");                           //db 1fh
    _STOP_("db 5eh");                           //db 5eh
    _STOP_("db 5fh");                           //db 5fh
    _STOP_("db 5ah");                           //db 5ah
    _STOP_("db 59h");                           //db 59h
    _STOP_("db 5bh");                           //db 5bh
    _STOP_("db 58h");                           //db 58h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 32h");                           //db 32h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db cdh");                           //db cdh
    _STOP_("db 13h");                           //db 13h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db bbh");                           //db bbh
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db b9h");                           //db b9h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db b6h");                           //db b6h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db ddh");                           //db ddh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 17h");                           //db 17h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 27h");                           //db 27h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3fh");                           //db 3fh
    _STOP_("db f9h");                           //db f9h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 08h");                           //db 08h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 17h");                           //db 17h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 4fh");                           //db 4fh
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 02h");                           //db 02h
    _STOP_("db a2h");                           //db a2h
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 02h");                           //db 02h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db b1h");                           //db b1h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db bbh");                           //db bbh
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 36h");                           //db 36h
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 02h");                           //db 02h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db a7h");                           //db a7h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 27h");                           //db 27h
    _STOP_("db feh");                           //db feh
    _STOP_("db c1h");                           //db c1h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db f9h");                           //db f9h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db 76h");                           //db 76h
    _STOP_("db e6h");                           //db e6h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db b1h");                           //db b1h
    _STOP_("db f7h");                           //db f7h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 92h");                           //db 92h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 73h");                           //db 73h
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 12h");                           //db 12h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db fch");                           //db fch
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 14h");                           //db 14h
    _STOP_("db a0h");                           //db a0h
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 38h");                           //db 38h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 14h");                           //db 14h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 73h");                           //db 73h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db a2h");                           //db a2h
    _STOP_("db 14h");                           //db 14h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db a1h");                           //db a1h
    _STOP_("db 12h");                           //db 12h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 15h");                           //db 15h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db f9h");                           //db f9h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 81h");                           //db 81h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 4dh");                           //db 4dh
    _STOP_("db 4fh");                           //db 4fh
    _STOP_("db 75h");                           //db 75h
    _STOP_("db dfh");                           //db dfh
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 81h");                           //db 81h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 13h");                           //db 13h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 4bh");                           //db 4bh
    _STOP_("db 54h");                           //db 54h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db d2h");                           //db d2h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 07h");                           //db 07h
    _STOP_("db bfh");                           //db bfh
    _STOP_("db 50h");                           //db 50h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 33h");                           //db 33h
    _STOP_("db dbh");                           //db dbh
    _STOP_("db 43h");                           //db 43h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 39h");                           //db 39h
    _STOP_("db 4eh");                           //db 4eh
    _STOP_("db 74h");                           //db 74h
    _STOP_("db fah");                           //db fah
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 12h");                           //db 12h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 8dh");                           //db 8dh
    _STOP_("db 79h");                           //db 79h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db 83h");                           //db 83h
    _STOP_("db fbh");                           //db fbh
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 08h");                           //db 08h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 25h");                           //db 25h
    _STOP_("db 33h");                           //db 33h
    _STOP_("db dbh");                           //db dbh
    _STOP_("db 43h");                           //db 43h
    _STOP_("db 38h");                           //db 38h
    _STOP_("db 21h");                           //db 21h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db fbh");                           //db fbh
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 12h");                           //db 12h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db fbh");                           //db fbh
    _STOP_("db 83h");                           //db 83h
    _STOP_("db fbh");                           //db fbh
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db bfh");                           //db bfh
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 33h");                           //db 33h
    _STOP_("db dbh");                           //db dbh
    _STOP_("db 4bh");                           //db 4bh
    _STOP_("db 38h");                           //db 38h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db fbh");                           //db fbh
    _STOP_("db f7h");                           //db f7h
    _STOP_("db d3h");                           //db d3h
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 12h");                           //db 12h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 81h");                           //db 81h
    _STOP_("db fbh");                           //db fbh
    _STOP_("db a8h");                           //db a8h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 84h");                           //db 84h
    _STOP_("db f8h");                           //db f8h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 9ch");                           //db 9ch
    _STOP_("db 9ah");                           //db 9ah
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 12h");                           //db 12h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db b9h");                           //db b9h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 32h");                           //db 32h
    _STOP_("db c0h");                           //db c0h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e2h");                           //db e2h
    _STOP_("db d0h");                           //db d0h
    _STOP_("db d0h");                           //db d0h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e2h");                           //db e2h
    _STOP_("db d0h");                           //db d0h
    _STOP_("db d0h");                           //db d0h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e2h");                           //db e2h
    _STOP_("db d0h");                           //db d0h
    _STOP_("db d0h");                           //db d0h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e2h");                           //db e2h
    _STOP_("db d0h");                           //db d0h
    _STOP_("db d0h");                           //db d0h
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 76h");                           //db 76h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 30h");                           //db 30h
    _STOP_("db b4h");                           //db b4h
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db cdh");                           //db cdh
    _STOP_("db 10h");                           //db 10h
    _STOP_("db e2h");                           //db e2h
    _STOP_("db e0h");                           //db e0h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 50h");                           //db 50h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db ech");                           //db ech
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db 83h");                           //db 83h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db feh");                           //db feh
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 41h");                           //db 41h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 46h");                           //db 46h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 3dh");                           //db 3dh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 46h");                           //db 46h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 46h");                           //db 46h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 3dh");                           //db 3dh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 2bh");                           //db 2bh
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db ech");                           //db ech
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db 5eh");                           //db 5eh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 6eh");                           //db 6eh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 7eh");                           //db 7eh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db fah");                           //db fah
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db ech");                           //db ech
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 46h");                           //db 46h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db ebh");                           //db ebh
    _STOP_("db eah");                           //db eah
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db ech");                           //db ech
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 46h");                           //db 46h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db a3h");                           //db a3h
    _STOP_("db feh");                           //db feh
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 46h");                           //db 46h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db a3h");                           //db a3h
    _STOP_("db fch");                           //db fch
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 81h");                           //db 81h
    _STOP_("db 66h");                           //db 66h
    _STOP_("db 08h");                           //db 08h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db feh");                           //db feh
    _STOP_("db 58h");                           //db 58h
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db cfh");                           //db cfh
    _STOP_("sp-trace-fail");                    //sub_0ceb endp_failed
    _STOP_("continues");                        //sub_107d proc near
}

void sub_107d()
{
    

    _flags.interrupt = false;                   //cli
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _es = _ax;                                  //mov es, ax
    _push(bios16get(_es, 24));                   //push word ptr es:[0x18]
    _push(bios16get(_es, 26));                   //push word ptr es:[0x1a]
    bios16set(_es, 24, 0x10bc);                 //mov word ptr es:[0x18], 0x10bc
    bios16set(_es, 26, _cs);                    //mov word ptr es:[0x1a], cs
    _al = 0x01;                                 //mov al, 0x1
    _cl = 0x20;                                 //mov cl, 0x20
    _al <<= _cl;                                //shl al, cl
    if (_al == 0x01)                            //jz loc_10b1
        goto loc_10b1;
    memory(_cs, 0x4) = 0x00;                    //mov byte ptr cs:[0x4], 0x0
    goto loc_10c5;                              //jmp loc_10c5
loc_10b1:                                       //loc_10b1:
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory(_cs, 0x4) = 0x03;                    //mov byte ptr cs:[0x4], 0x3
    goto loc_10c5;                              //jmp loc_10c5
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db c4h");                           //db c4h
    _STOP_("db 06h");                           //db 06h
loc_10c5:                                       //loc_10c5:
    bios16set(_es, 26, _pop());                 //pop word ptr es:[0x1a]
    bios16set(_es, 24, _pop());                 //pop word ptr es:[0x18]
    _flags.interrupt = true;                    //sti
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_10d3()
{
    

    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    memory(_ds, 25882) = 0x00;                  //mov byte ptr [0x651a], 0x0
loc_10dd:                                       //loc_10dd:
    /*
    //_sync(); // delay??
    _ax = memory16(_ds, 0x0431);                //mov ax, [0x431]
    _ax = _ax - memory16(_cs, 0x16E0);          //sub ax, word ptr cs:[0x16e0]
    if ((short)_ax >= 0)                        //jns loc_10e9
        goto loc_10e9;
    _ax = -_ax;                                 //neg ax
loc_10e9:                                       //loc_10e9:
    if (_ax < 0x0002)                           //jc loc_10dd
        goto loc_10dd;
    if (_ax > 0x0002)                           //ja loc_10f7
        goto loc_10f7;
    sub_3243();                                 //call sub_3243
    memory(_ds, 25882) += 1;                    //inc byte ptr [0x651a]
     */
    _sync();
loc_10f7:                                       //loc_10f7:
    _ax = memory16(_cs, 0x16E0);                //mov ax, cs:[0x16e0]
    memory16(_ds, 0x0431) = _ax;                //mov [0x431], ax
}

void sub_10ff()
{
    

    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    _dx = reloc(0x168f);                               //mov dx, reloc(0x168f)
    _ds = _dx;                                  //mov ds, dx
    _es = _dx;                                  //mov es, dx
    _bx = _ax;                                  //mov bx, ax
    if (memory(_ds, _bx + 1285) == 0x01)        //jz loc_111d
        goto loc_111d;
    memory16(_ds, 0x0913) = _ax;                //mov [0x913], ax
    goto loc_111d;                              //jmp loc_111d
loc_111d:                                       //loc_111d:
    memory(_cs, 0x16E4) |= 0x01;                //or byte ptr cs:[0x16e4], 0x1
    _flags.interrupt = false;                   //cli
    if (memory(_cs, 0x16E3) == 0x01)            //jz loc_1157
        goto loc_1157;
    _bx = _ax;                                  //mov bx, ax
    _al = memory(_ds, _bx + 2466);              //mov al, byte ptr [bx+0x9a2]
    memory(_ds, 0x980) = _al;                   //mov [0x980], al
    memory(_ds, 0x981) = _al;                   //mov [0x981], al
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _bx + 2434);            //mov ax, word ptr [bx+0x982]
    memory(_cs, 0x70A2) = 0x01;                 //mov byte ptr cs:[0x70a2], 0x1
    memory16(_ds, 0x0b07) = _ax;                //mov [0xb07], ax
    if (!(memory(_cs, 0x16E4) & 0x02))          //jz loc_118d
        goto loc_118d;
    _in(_al, 97);                               //in al, 0x61
    _al |= 0x03;                                //or al, 0x3
    _out(97, _al);                              //out 0x61, al
    goto loc_118d;                              //jmp loc_118d
loc_1157:                                       //loc_1157:
    sub_164f();                                 //call sub_164f
    _bx = 0x0515;                               //mov bx, 0x515
    _cx = _ax;                                  //mov cx, ax
    if (_cx == 0)                               //jcxz loc_116b
        goto loc_116b;
loc_1161:                                       //loc_1161:
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    if (memory16(_ds, _bx + -2) != 0xffff)  //jnz loc_1161
        goto loc_1161;
    if (--_cx)                                  //loop loc_1161
        goto loc_1161;
loc_116b:                                       //loc_116b:
    _cx = _ax;                                  //mov cx, ax
    _ax = _bx;                                  //mov ax, bx
    _bx = 0x0675;                               //mov bx, 0x675
    if (_cx == 0)                               //jcxz loc_117e
        goto loc_117e;
loc_1174:                                       //loc_1174:
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    if (memory16(_ds, _bx + -2) != 0xffff)  //jnz loc_1174
        goto loc_1174;
    if (--_cx)                                  //loop loc_1174
        goto loc_1174;
loc_117e:                                       //loc_117e:
    _si = _bx;                                  //mov si, bx
loc_1180:                                       //loc_1180:
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    if (memory16(_ds, _si) != 0xffff)       //jnz loc_1180
        goto loc_1180;
    _cx = memory16(_ds, _si - 2);               //mov cx, word ptr [si-0x2]
    sub_1269();                                 //call sub_1269
loc_118d:                                       //loc_118d:
    _flags.interrupt = true;                    //sti
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_1198()
{
    

    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    if (memory(_cs, 0x2) == 0x00)               //jz loc_11d2
        goto loc_11d2;
    _ax = 0x2001;                               //mov ax, 0x2001
    sub_15a7();                                 //call sub_15a7
    sub_1610();                                 //call sub_1610
    if (_flags.carry)                           //jc loc_11d2
        goto loc_11d2;
    _flags.interrupt = false;                   //cli
    _ax = 0x0008;                               //mov ax, 0x8
    sub_15a7();                                 //call sub_15a7
    _ax = 0x00bd;                               //mov ax, 0xbd
    sub_15a7();                                 //call sub_15a7
    sub_164f();                                 //call sub_164f
    memory(_cs, 0x16E3) = 0x01;                 //mov byte ptr cs:[0x16e3], 0x1
    _flags.interrupt = true;                    //sti
    goto loc_11dc;                              //jmp loc_11dc
loc_11d2:                                       //loc_11d2:
    _al = 0xb6;                                 //mov al, 0xb6
    _out(67, _al);                              //out 0x43, al
    _in(_al, 97);                               //in al, 0x61
    _al |= 0x03;                                //or al, 0x3
    _out(97, _al);                              //out 0x61, al
loc_11dc:                                       //loc_11dc:
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_11e6()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    _bx = reloc(0x168f);                               //mov bx, reloc(0x168f)
    _ds = _bx;                                  //mov ds, bx
    memory16(_ds, 370) = 0x000f;                //mov word ptr [0x172], 0xf
    _bl = _al;                                  //mov bl, al
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bx <<= 1;                                  //shl bx, 1
    _bx = memory16(_ds, _bx + 342);             //mov bx, word ptr [bx+0x156]
    memory(_ds, 372) = 0x01;                    //mov byte ptr [0x174], 0x1
    _flags.interrupt = false;                   //cli
    _dl = 0x13;                                 //mov dl, 0x13
    sub_15de();                                 //call sub_15de
    _dl -= 0x03;                                //sub dl, 0x3
    _bx += 0x0005;                              //add bx, 0x5
    sub_15de();                                 //call sub_15de
    _ah = memory(_ds, _bx + 5);                 //mov ah, byte ptr [bx+0x5]
    _al = 0xc6;                                 //mov al, 0xc6
    sub_15a7();                                 //call sub_15a7
    _flags.interrupt = true;                    //sti
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    return;                                     //ret
    _STOP_("db 50h");                           //db 50h
    _STOP_("db 53h");                           //db 53h
    _STOP_("db 51h");                           //db 51h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 57h");                           //db 57h
    _STOP_("db 56h");                           //db 56h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 8fh");                           //db 8fh
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db d8h");                           //db d8h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db b6h");                           //db b6h
    _STOP_("db 20h");                           //db 20h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 68h");                           //db 68h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db fah");                           //db fah
    _STOP_("db bbh");                           //db bbh
    _STOP_("db 9ah");                           //db 9ah
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db b2h");                           //db b2h
    _STOP_("db 13h");                           //db 13h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 96h");                           //db 96h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db eah");                           //db eah
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 8dh");                           //db 8dh
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 67h");                           //db 67h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 4eh");                           //db 4eh
    _STOP_("db 03h");                           //db 03h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db fbh");                           //db fbh
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 1fh");                           //db 1fh
    _STOP_("db 5eh");                           //db 5eh
    _STOP_("db 5fh");                           //db 5fh
    _STOP_("db 5ah");                           //db 5ah
    _STOP_("db 59h");                           //db 59h
    _STOP_("db 5bh");                           //db 5bh
    _STOP_("db 58h");                           //db 58h
    _STOP_("db c3h");                           //db c3h
    _STOP_("sp-trace-fail");                    //sub_11e6 endp_failed
    _STOP_("continues");                        //sub_1269 proc near
}

void sub_1269()
{
    

    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    memory(_cs, 0x16E2) = 0x00;                 //mov byte ptr cs:[0x16e2], 0x0
    memory(_ds, 2433) = _cl;                    //mov byte ptr [0x981], cl
    memory(_ds, 2432) = _cl;                    //mov byte ptr [0x980], cl
    memory16(_ds, 2327) = _bx;                  //mov word ptr [0x917], bx
    _di = 0x09b3;                               //mov di, 0x9b3
    _si = _ax;                                  //mov si, ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _dx = _dx ^ _dx;                            //xor dx, dx
    memory(_ds, 2482) = 0xff;                   //mov byte ptr [0x9b2], 0xff
loc_128d:                                       //loc_128d:
    _cx = 0x0011;                               //mov cx, 0x11
    _rep_stosb<MemData, DirForward>();          //rep stosb
    _cx = memory16(_ds, _si);                   //mov cx, word ptr [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory(_ds, 2482) += 1;                     //inc byte ptr [0x9b2]
    memory16(_ds, _di + -4) = _cx;              //mov word ptr [di-0x4], cx
    memory(_ds, _di + -12) = _dl;               //mov byte ptr [di-0xc], dl
    _dx += 1;                                   //inc dx
    if (_cx != 0xffff)                      //jnz loc_128d
        goto loc_128d;
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
    return;                                     //ret
    _STOP_("db 50h");                           //db 50h
    _STOP_("db 53h");                           //db 53h
    _STOP_("db 51h");                           //db 51h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 57h");                           //db 57h
    _STOP_("db 56h");                           //db 56h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db fch");                           //db fch
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 8fh");                           //db 8fh
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db d8h");                           //db d8h
    _STOP_("db feh");                           //db feh
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 08h");                           //db 08h
    _STOP_("db a0h");                           //db a0h
    _STOP_("db 81h");                           //db 81h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db a2h");                           //db a2h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db ebh");                           //db ebh
    _STOP_("db 69h");                           //db 69h
    _STOP_("db c7h");                           //db c7h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 15h");                           //db 15h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db b3h");                           //db b3h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 15h");                           //db 15h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db 83h");                           //db 83h
    _STOP_("db feh");                           //db feh
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 57h");                           //db 57h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db feh");                           //db feh
    _STOP_("db feh");                           //db feh
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 48h");                           //db 48h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 6dh");                           //db 6dh
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 77h");                           //db 77h
    _STOP_("db 42h");                           //db 42h
    _STOP_("db 32h");                           //db 32h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db ach");                           //db ach
    _STOP_("db a8h");                           //db a8h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db e0h");                           //db e0h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db cch");                           //db cch
    _STOP_("db 86h");                           //db 86h
    _STOP_("db 4dh");                           //db 4dh
    _STOP_("db 08h");                           //db 08h
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 4dh");                           //db 4dh
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db b1h");                           //db b1h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db d2h");                           //db d2h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 08h");                           //db 08h
    _STOP_("db 32h");                           //db 32h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e3h");                           //db e3h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 87h");                           //db 87h
    _STOP_("db 66h");                           //db 66h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 4dh");                           //db 4dh
    _STOP_("db 09h");                           //db 09h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db aeh");                           //db aeh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db 60h");                           //db 60h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db 80h");                           //db 80h
    _STOP_("db f9h");                           //db f9h
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db 40h");                           //db 40h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 4dh");                           //db 4dh
    _STOP_("db 03h");                           //db 03h
    _STOP_("db d2h");                           //db d2h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db 83h");                           //db 83h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 15h");                           //db 15h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 11h");                           //db 11h
    _STOP_("db ebh");                           //db ebh
    _STOP_("db 9dh");                           //db 9dh
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 1fh");                           //db 1fh
    _STOP_("db 5eh");                           //db 5eh
    _STOP_("db 5fh");                           //db 5fh
    _STOP_("db 5ah");                           //db 5ah
    _STOP_("db 59h");                           //db 59h
    _STOP_("db 5bh");                           //db 5bh
    _STOP_("db 58h");                           //db 58h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 50h");                           //db 50h
    _STOP_("db 53h");                           //db 53h
    _STOP_("db 51h");                           //db 51h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 57h");                           //db 57h
    _STOP_("db 56h");                           //db 56h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 8fh");                           //db 8fh
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db d8h");                           //db d8h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 31h");                           //db 31h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db bdh");                           //db bdh
    _STOP_("db b4h");                           //db b4h
    _STOP_("db efh");                           //db efh
    _STOP_("db 22h");                           //db 22h
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 19h");                           //db 19h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 4ch");                           //db 4ch
    _STOP_("db 02h");                           //db 02h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db a6h");                           //db a6h
    _STOP_("db 57h");                           //db 57h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 46h");                           //db 46h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db b6h");                           //db b6h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 40h");                           //db 40h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db b6h");                           //db b6h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 3ah");                           //db 3ah
    _STOP_("db 02h");                           //db 02h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db bdh");                           //db bdh
    _STOP_("db b4h");                           //db b4h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 19h");                           //db 19h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 2fh");                           //db 2fh
    _STOP_("db 02h");                           //db 02h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db aah");                           //db aah
    _STOP_("db feh");                           //db feh
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 1fh");                           //db 1fh
    _STOP_("db 5eh");                           //db 5eh
    _STOP_("db 5fh");                           //db 5fh
    _STOP_("db 5ah");                           //db 5ah
    _STOP_("db 59h");                           //db 59h
    _STOP_("db 5bh");                           //db 5bh
    _STOP_("db 58h");                           //db 58h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 13h");                           //db 13h
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db e3h");                           //db e3h
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 08h");                           //db 08h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 9dh");                           //db 9dh
    _STOP_("db ffh");                           //db ffh
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db ffh");                           //db ffh
    _STOP_("db ebh");                           //db ebh
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 3fh");                           //db 3fh
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db e0h");                           //db e0h
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db feh");                           //db feh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db e2h");                           //db e2h
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 26h");                           //db 26h
    _STOP_("db e2h");                           //db e2h
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 50h");                           //db 50h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db 20h");                           //db 20h
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 20h");                           //db 20h
    _STOP_("db 58h");                           //db 58h
    _STOP_("db cfh");                           //db cfh
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db f9h");                           //db f9h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 84h");                           //db 84h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 48h");                           //db 48h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db c1h");                           //db c1h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 38h");                           //db 38h
    _STOP_("db 4dh");                           //db 4dh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 9dh");                           //db 9dh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 4dh");                           //db 4dh
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db b4h");                           //db b4h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db d2h");                           //db d2h
    _STOP_("db ech");                           //db ech
    _STOP_("db f6h");                           //db f6h
    _STOP_("db d4h");                           //db d4h
    _STOP_("db 22h");                           //db 22h
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 19h");                           //db 19h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db bdh");                           //db bdh
    _STOP_("db e8h");                           //db e8h
    _STOP_("db b2h");                           //db b2h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 12h");                           //db 12h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db a6h");                           //db a6h
    _STOP_("db 57h");                           //db 57h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db a6h");                           //db a6h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db b6h");                           //db b6h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db a0h");                           //db a0h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db b6h");                           //db b6h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 9ah");                           //db 9ah
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 19h");                           //db 19h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db bdh");                           //db bdh
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 91h");                           //db 91h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db c1h");                           //db c1h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db d0h");                           //db d0h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db e2h");                           //db e2h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db a0h");                           //db a0h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 81h");                           //db 81h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db b4h");                           //db b4h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 71h");                           //db 71h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db d2h");                           //db d2h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 13h");                           //db 13h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db e6h");                           //db e6h
    _STOP_("db d0h");                           //db d0h
    _STOP_("db e1h");                           //db e1h
    _STOP_("db d0h");                           //db d0h
    _STOP_("db e1h");                           //db e1h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db e1h");                           //db e1h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db cch");                           //db cch
    _STOP_("db 20h");                           //db 20h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 5ah");                           //db 5ah
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db e0h");                           //db e0h
    _STOP_("db 24h");                           //db 24h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db b1h");                           //db b1h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 70h");                           //db 70h
    _STOP_("db d2h");                           //db d2h
    _STOP_("db ech");                           //db ech
    _STOP_("db 80h");                           //db 80h
    _STOP_("db fch");                           //db fch
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db dch");                           //db dch
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e3h");                           //db e3h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 97h");                           //db 97h
    _STOP_("db 1ah");                           //db 1ah
    _STOP_("db 09h");                           //db 09h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 76h");                           //db 76h
    _STOP_("db feh");                           //db feh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db d8h");                           //db d8h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e3h");                           //db e3h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 97h");                           //db 97h
    _STOP_("db 28h");                           //db 28h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 6bh");                           //db 6bh
    _STOP_("db feh");                           //db feh
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db feh");                           //db feh
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db cbh");                           //db cbh
    _STOP_("db b7h");                           //db b7h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e3h");                           //db e3h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 17h");                           //db 17h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 1fh");                           //db 1fh
    _STOP_("db 80h");                           //db 80h
    _STOP_("db f9h");                           //db f9h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 43h");                           //db 43h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db c8h");                           //db c8h
    _STOP_("db 32h");                           //db 32h
    _STOP_("db edh");                           //db edh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 67h");                           //db 67h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 3fh");                           //db 3fh
    _STOP_("db 80h");                           //db 80h
    _STOP_("db ech");                           //db ech
    _STOP_("db 3fh");                           //db 3fh
    _STOP_("db f6h");                           //db f6h
    _STOP_("db dch");                           //db dch
    _STOP_("db 32h");                           //db 32h
    _STOP_("db c0h");                           //db c0h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db f7h");                           //db f7h
    _STOP_("db e1h");                           //db e1h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db 3fh");                           //db 3fh
    _STOP_("db 2ah");                           //db 2ah
    _STOP_("db c4h");                           //db c4h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 05h");                           //db 05h
    _STOP_("db b7h");                           //db b7h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 9fh");                           //db 9fh
    _STOP_("db 5bh");                           //db 5bh
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db fbh");                           //db fbh
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db 77h");                           //db 77h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 9fh");                           //db 9fh
    _STOP_("db 48h");                           //db 48h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db e0h");                           //db e0h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 40h");                           //db 40h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db d3h");                           //db d3h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 29h");                           //db 29h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 32h");                           //db 32h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 80h");                           //db 80h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e3h");                           //db e3h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 17h");                           //db 17h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 1fh");                           //db 1fh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 4dh");                           //db 4dh
    _STOP_("db 05h");                           //db 05h
    _STOP_("db b4h");                           //db b4h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db d2h");                           //db d2h
    _STOP_("db ech");                           //db ech
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 19h");                           //db 19h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 19h");                           //db 19h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db ebh");                           //db ebh
    _STOP_("db 22h");                           //db 22h
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db feh");                           //db feh
    _STOP_("db c8h");                           //db c8h
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 4dh");                           //db 4dh
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 13h");                           //db 13h
    _STOP_("db b4h");                           //db b4h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db d2h");                           //db d2h
    _STOP_("db ech");                           //db ech
    _STOP_("db f6h");                           //db f6h
    _STOP_("db d4h");                           //db d4h
    _STOP_("db 22h");                           //db 22h
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 19h");                           //db 19h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 19h");                           //db 19h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db bdh");                           //db bdh
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 73h");                           //db 73h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 32h");                           //db 32h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 9fh");                           //db 9fh
    _STOP_("db 5bh");                           //db 5bh
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 77h");                           //db 77h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 97h");                           //db 97h
    _STOP_("db 48h");                           //db 48h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 32h");                           //db 32h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e3h");                           //db e3h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 17h");                           //db 17h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 1fh");                           //db 1fh
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 43h");                           //db 43h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db eah");                           //db eah
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 73h");                           //db 73h
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 6eh");                           //db 6eh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 67h");                           //db 67h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db c0h");                           //db c0h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 2ch");                           //db 2ch
    _STOP_("db 00h");                           //db 00h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 8dh");                           //db 8dh
    _STOP_("db 44h");                           //db 44h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 34h");                           //db 34h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 34h");                           //db 34h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db ach");                           //db ach
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 0ch");                           //db 0ch
    _STOP_("db c3h");                           //db c3h
    _STOP_("db feh");                           //db feh
    _STOP_("db 4dh");                           //db 4dh
    _STOP_("db 0ch");                           //db 0ch
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 34h");                           //db 34h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 46h");                           //db 46h
    _STOP_("db 46h");                           //db 46h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 58h");                           //db 58h
    _STOP_("db beh");                           //db beh
    _STOP_("db feh");                           //db feh
    _STOP_("db ffh");                           //db ffh
    _STOP_("db feh");                           //db feh
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db b2h");                           //db b2h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db fdh");                           //db fdh
    _STOP_("sp-trace-fail");                    //sub_1269 endp_failed
    _STOP_("continues");                        //sub_15a7 proc near
}

void sub_15a7()
{
    

    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    if (memory(_cs, 0x4) >= 0x03)               //jnc loc_15c8
        goto loc_15c8;
    _dx = 0x0388;                               //mov dx, 0x388
    _out(_dx, _al);                             //out dx, al
    _cx = 0x0005;                               //mov cx, 0x5
loc_15b9:                                       //loc_15b9:
    if (--_cx)                                  //loop loc_15b9
        goto loc_15b9;
    _dx += 1;                                   //inc dx
    _al = _ah;                                  //mov al, ah
    _out(_dx, _al);                             //out dx, al
    _cx = 0x0023;                               //mov cx, 0x23
loc_15c2:                                       //loc_15c2:
    if (--_cx)                                  //loop loc_15c2
        goto loc_15c2;
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
    _dx = _pop();                               //pop dx
    return;                                     //ret
loc_15c8:                                       //loc_15c8:
    _dx = 0x0388;                               //mov dx, 0x388
    _out(_dx, _al);                             //out dx, al
    _cx = 0x0014;                               //mov cx, 0x14
loc_15cf:                                       //loc_15cf:
    if (--_cx)                                  //loop loc_15cf
        goto loc_15cf;
    _dx += 1;                                   //inc dx
    _al = _ah;                                  //mov al, ah
    _out(_dx, _al);                             //out dx, al
    _cx = 0x008c;                               //mov cx, 0x8c
loc_15d8:                                       //loc_15d8:
    if (--_cx)                                  //loop loc_15d8
        goto loc_15d8;
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
    _dx = _pop();                               //pop dx
}

void sub_15de()
{
    _ah = memory(_ds, _bx);                     //mov ah, byte ptr [bx]
    _al = _dl;                                  //mov al, dl
    _al += 0x60;                                //add al, 0x60
    sub_15a7();                                 //call sub_15a7
    _ah = memory(_ds, _bx + 1);                 //mov ah, byte ptr [bx+0x1]
    _al = _dl;                                  //mov al, dl
    _al += 0x80;                                //add al, 0x80
    sub_15a7();                                 //call sub_15a7
    _ah = memory(_ds, _bx + 2);                 //mov ah, byte ptr [bx+0x2]
    _al = _dl;                                  //mov al, dl
    _al += 0x40;                                //add al, 0x40
    sub_15a7();                                 //call sub_15a7
    _ah = memory(_ds, _bx + 3);                 //mov ah, byte ptr [bx+0x3]
    _al = _dl;                                  //mov al, dl
    _al += 0x20;                                //add al, 0x20
    sub_15a7();                                 //call sub_15a7
    _ah = memory(_ds, _bx + 4);                 //mov ah, byte ptr [bx+0x4]
    _al = _dl;                                  //mov al, dl
    _al += 0xe0;                                //add al, 0xe0
    sub_15a7();                                 //call sub_15a7
}

void sub_1610()
{
    _ax = 0x6304;                               //mov ax, 0x6304
    sub_15a7();                                 //call sub_15a7
    _dx = 0x0388;                               //mov dx, 0x388
    _cx = 0x2000;                               //mov cx, 0x2000
loc_161c:                                       //loc_161c:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x60;                                //and al, 0x60
    if (_al != 0)                               //jnz loc_164d
        goto loc_164d;
    if (--_cx)                                  //loop loc_161c
        goto loc_161c;
    _ax = 0x2304;                               //mov ax, 0x2304
    sub_15a7();                                 //call sub_15a7
    _cx = 0x9fff;                               //mov cx, 0x9fff
loc_162c:                                       //loc_162c:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x60;                                //and al, 0x60
    if (_al == 0x40)                            //jz loc_1637
        goto loc_1637;
    if (--_cx)                                  //loop loc_162c
        goto loc_162c;
    goto loc_164d;                              //jmp loc_164d
loc_1637:                                       //loc_1637:
    _ax = 0x4304;                               //mov ax, 0x4304
    sub_15a7();                                 //call sub_15a7
    _cx = 0x9fff;                               //mov cx, 0x9fff
loc_1640:                                       //loc_1640:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x60;                                //and al, 0x60
    if (_al == 0x20)                            //jz loc_164b
        goto loc_164b;
    if (--_cx)                                  //loop loc_1640
        goto loc_1640;
    goto loc_164d;                              //jmp loc_164d
loc_164b:                                       //loc_164b:
    _flags.carry = false;                       //clc
    return;                                     //ret
loc_164d:                                       //loc_164d:
    _flags.carry = true;                        //stc
}

void sub_164f()
{
    _push(_ax);                                 //push ax
    _ax = 0x00b0;                               //mov ax, 0xb0
loc_1653:                                       //loc_1653:
    sub_15a7();                                 //call sub_15a7
    _ax += 1;                                   //inc ax
    if (_al < 0xb9)                             //jc loc_1653
        goto loc_1653;
    _ax = 0x00a0;                               //mov ax, 0xa0
loc_165e:                                       //loc_165e:
    sub_15a7();                                 //call sub_15a7
    _ax += 1;                                   //inc ax
    if (_al < 0xb9)                             //jc loc_165e
        goto loc_165e;
    _ax = 0x0008;                               //mov ax, 0x8
    sub_15a7();                                 //call sub_15a7
    _ax = 0x00bd;                               //mov ax, 0xbd
    sub_15a7();                                 //call sub_15a7
    _ax = 0x3f40;                               //mov ax, 0x3f40
    sub_15a7();                                 //call sub_15a7
    _ax = 0x3f41;                               //mov ax, 0x3f41
    sub_15a7();                                 //call sub_15a7
    _ax = 0x3f42;                               //mov ax, 0x3f42
    sub_15a7();                                 //call sub_15a7
    _ax = 0x3f43;                               //mov ax, 0x3f43
    sub_15a7();                                 //call sub_15a7
    _ax = 0x3f44;                               //mov ax, 0x3f44
    sub_15a7();                                 //call sub_15a7
    _ax = 0x3f45;                               //mov ax, 0x3f45
    sub_15a7();                                 //call sub_15a7
    _ax = 0x3f48;                               //mov ax, 0x3f48
    sub_15a7();                                 //call sub_15a7
    _ax = 0x3f49;                               //mov ax, 0x3f49
    sub_15a7();                                 //call sub_15a7
    _ax = 0x3f4a;                               //mov ax, 0x3f4a
    sub_15a7();                                 //call sub_15a7
    _ax = 0x3f4b;                               //mov ax, 0x3f4b
    sub_15a7();                                 //call sub_15a7
    _ax = 0x3f4c;                               //mov ax, 0x3f4c
    sub_15a7();                                 //call sub_15a7
    _ax = 0x3f4d;                               //mov ax, 0x3f4d
    sub_15a7();                                 //call sub_15a7
    _ax = 0x3f50;                               //mov ax, 0x3f50
    sub_15a7();                                 //call sub_15a7
    _ax = 0x3f51;                               //mov ax, 0x3f51
    sub_15a7();                                 //call sub_15a7
    _ax = 0x3f52;                               //mov ax, 0x3f52
    sub_15a7();                                 //call sub_15a7
    _ax = 0x3f53;                               //mov ax, 0x3f53
    sub_15a7();                                 //call sub_15a7
    _ax = 0x3f54;                               //mov ax, 0x3f54
    sub_15a7();                                 //call sub_15a7
    _ax = 0x3f55;                               //mov ax, 0x3f55
    sub_15a7();                                 //call sub_15a7
    _ax = _pop();                               //pop ax
    return;                                     //ret
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 50h");                           //db 50h
    _STOP_("db 53h");                           //db 53h
    _STOP_("db 51h");                           //db 51h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 57h");                           //db 57h
    _STOP_("db 56h");                           //db 56h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db fch");                           //db fch
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 8fh");                           //db 8fh
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db d8h");                           //db d8h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 36h");                           //db 36h
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db 83h");                           //db 83h
    _STOP_("db feh");                           //db feh
    _STOP_("db feh");                           //db feh
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db f6h");                           //db f6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 7bh");                           //db 7bh
    _STOP_("db feh");                           //db feh
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 08h");                           //db 08h
    _STOP_("db a0h");                           //db a0h
    _STOP_("db 81h");                           //db 81h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db a2h");                           //db a2h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db ebh");                           //db ebh
    _STOP_("db 6dh");                           //db 6dh
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 12h");                           //db 12h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 13h");                           //db 13h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 98h");                           //db 98h
    _STOP_("db 3ah");                           //db 3ah
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 42h");                           //db 42h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db c4h");                           //db c4h
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 42h");                           //db 42h
    _STOP_("db ebh");                           //db ebh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 77h");                           //db 77h
    _STOP_("db 4dh");                           //db 4dh
    _STOP_("db 32h");                           //db 32h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db ach");                           //db ach
    _STOP_("db a8h");                           //db a8h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 54h");                           //db 54h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db e0h");                           //db e0h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db b1h");                           //db b1h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db d2h");                           //db d2h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db a2h");                           //db a2h
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db b0h");                           //db b0h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db d2h");                           //db d2h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db 32h");                           //db 32h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e3h");                           //db e3h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 87h");                           //db 87h
    _STOP_("db 20h");                           //db 20h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db d3h");                           //db d3h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 42h");                           //db 42h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db c4h");                           //db c4h
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 42h");                           //db 42h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db 60h");                           //db 60h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db 80h");                           //db 80h
    _STOP_("db f9h");                           //db f9h
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db 40h");                           //db 40h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 12h");                           //db 12h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db d2h");                           //db d2h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db a2h");                           //db a2h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 36h");                           //db 36h
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 1fh");                           //db 1fh
    _STOP_("db 5eh");                           //db 5eh
    _STOP_("db 5fh");                           //db 5fh
    _STOP_("db 5ah");                           //db 5ah
    _STOP_("db 59h");                           //db 59h
    _STOP_("db 5bh");                           //db 5bh
    _STOP_("db 58h");                           //db 58h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db e0h");                           //db e0h
    _STOP_("db 24h");                           //db 24h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db b1h");                           //db b1h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 70h");                           //db 70h
    _STOP_("db d2h");                           //db d2h
    _STOP_("db ech");                           //db ech
    _STOP_("db 80h");                           //db 80h
    _STOP_("db fch");                           //db fch
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 08h");                           //db 08h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db dch");                           //db dch
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 87h");                           //db 87h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db ebh");                           //db ebh
    _STOP_("db 8dh");                           //db 8dh
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db d8h");                           //db d8h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e3h");                           //db e3h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 97h");                           //db 97h
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 7eh");                           //db 7eh
    _STOP_("db ffh");                           //db ffh
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 61h");                           //db 61h
    _STOP_("db 24h");                           //db 24h
    _STOP_("db fch");                           //db fch
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 61h");                           //db 61h
    _STOP_("db beh");                           //db beh
    _STOP_("db feh");                           //db feh
    _STOP_("db ffh");                           //db ffh
    _STOP_("db feh");                           //db feh
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db b2h");                           //db b2h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db ebh");                           //db ebh
    _STOP_("db bch");                           //db bch
    _STOP_("db 8dh");                           //db 8dh
    _STOP_("db 44h");                           //db 44h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 34h");                           //db 34h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 36h");                           //db 36h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 34h");                           //db 34h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 04h");                           //db 04h
    _STOP_("db a2h");                           //db a2h
    _STOP_("db 0ch");                           //db 0ch
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db 46h");                           //db 46h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db feh");                           //db feh
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 0ch");                           //db 0ch
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 34h");                           //db 34h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 46h");                           //db 46h
    _STOP_("db 46h");                           //db 46h
    _STOP_("db c3h");                           //db c3h
    _STOP_("sp-trace-fail");                    //sub_164f endp_failed
    _STOP_("continues");                        //sub_17eb proc near
}

void sub_17eb()
{
loc_17eb:
    

    _al = memory(_cs, 0x16E4);                  //mov al, cs:[0x16e4]
    _al &= 0x03;                                //and al, 0x3
    if (_al != 0x03)                            //jnz loc_17fc
        goto loc_17fc;
    if (memory(_ds, 2482) != 0x00)              //jnz sub_17eb
        goto loc_17eb;
loc_17fc:                                       //loc_17fc:
    return;                                     //ret
    _STOP_("db 00h");                           //db 00h
    _STOP_("sp-trace-fail");                    //sub_17eb endp_failed
    _STOP_("continues");                        //sub_17fe proc near
}

void sub_17fe()
{
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _ah = 0x04;                                 //mov ah, 0x4
    _interrupt(26);                             //int 0x1a
    if (_flags.carry)                           //jc loc_183d
        goto loc_183d;
    _push(_dx);                                 //push dx
    _ax = _ax ^ _ax;                            //xor ax, ax
    _bl = 0x04;                                 //mov bl, 0x4
    _bp = 0x000a;                               //mov bp, 0xa
loc_1811:                                       //loc_1811:
    _mul(_bp);                                  //mul bp
    _flags.carry = !!(_cx & 0x8000);            //shl cx, 1
    _cx <<= 1;
    _rcl(_dh, 1);                               //rcl dh, 1
    _flags.carry = !!(_cx & 0x8000);            //shl cx, 1
    _cx <<= 1;
    _rcl(_dh, 1);                               //rcl dh, 1
    _flags.carry = !!(_cx & 0x8000);            //shl cx, 1
    _cx <<= 1;
    _rcl(_dh, 1);                               //rcl dh, 1
    _flags.carry = !!(_cx & 0x8000);            //shl cx, 1
    _cx <<= 1;
    _rcl(_dh, 1);                               //rcl dh, 1
    _al += _dh;                                 //add al, dh
    _bl -= 1;                                   //dec bl
    if (_bl != 0)                               //jnz loc_1811
        goto loc_1811;
    _dx = _pop();                               //pop dx
    if (_ax >= 0x0813)                          //jnc loc_183d
        goto loc_183d;
    if (_ax != 0x07c8)                          //jnz loc_183a
        goto loc_183a;
    if (_dh >= 0x06)                            //jnc loc_183a
        goto loc_183a;
    _ax -= 1;                                   //dec ax
loc_183a:                                       //loc_183a:
    memory16(_ds, 0x000a) = _ax;                //mov [0xa], ax
loc_183d:                                       //loc_183d:
    return;                                     //ret
loc_183e:                                       //loc_183e:
    return;
}

void sub_183f()
{
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    //gabo skip!//if (memory16(_ds, 10) < 0x07cc)             //jc loc_183e
    //    return; //_STOP_("goto loc_183e");
    sub_27df();                                 //call sub_27df
    sub_038a();                                 //call sub_038a
    memory16(_ds, 501) = 0x0005;                //mov word ptr [0x1f5], 0x5
    memory16(_ds, 503) = 0x0960;                //mov word ptr [0x1f7], 0x960
    _si = 0x4e6e;                               //mov si, 0x4e6e
    sub_0488();                                 //call sub_0488
    memory16(_ds, 501) = 0x0000;                //mov word ptr [0x1f5], 0x0
    memory16(_ds, 503) += 0x01e0;               //add word ptr [0x1f7], 0x1e0
    _si = 0x4e7a;                               //mov si, 0x4e7a
    sub_0488();                                 //call sub_0488
    _dx = memory16(_ds, 10);                    //mov dx, word ptr [0xa]
    sub_0423();                                 //call sub_0423
    _si = 0x4e9a;                               //mov si, 0x4e9a
    sub_0488();                                 //call sub_0488
    memory16(_ds, 501) = 0x0001;                //mov word ptr [0x1f5], 0x1
    memory16(_ds, 503) = 0x1680;                //mov word ptr [0x1f7], 0x1680
    _si = 0x4e9e;                               //mov si, 0x4e9e
    sub_0488();                                 //call sub_0488
    memory16(_ds, 501) = 0x0003;                //mov word ptr [0x1f5], 0x3
    memory16(_ds, 503) += 0x01e0;               //add word ptr [0x1f7], 0x1e0
    _si = 0x4ec3;                               //mov si, 0x4ec3
    sub_0488();                                 //call sub_0488
    sub_03f2();                                 //call sub_03f2  -- game
    sub_27df();                                 //call sub_27df
    return;                                     //ret
loc_18ae:                                       //loc_18ae:
    return;
}

void sub_18af()
{
    _al = memory(_ds, 0x45d);                   //mov al, [0x45d]
    _al = _al & memory(_ds, 1144);              //and al, byte ptr [0x478]
    _ah = _al;                                  //mov ah, al
    _ah = _ah & memory(_ds, 1105);              //and ah, byte ptr [0x451]
    if (_ah != 0)                               //jnz loc_18c4
        goto loc_18c4;
    _al = _al & memory(_ds, 1104);              //and al, byte ptr [0x450]
    if (_al == 0)                               //jz loc_18ae
        return;
loc_18c4:                                       //loc_18c4:
    _bx = 0x0001;                               //mov bx, 0x1
    _al = _al ^ _al;                            //xor al, al
loc_18c9:                                       //loc_18c9:
    if (_bl == 0x10)                            //jz loc_18e3
        goto loc_18e3;
    if (_bl == 0x11)                            //jz loc_18e3
        goto loc_18e3;
    if (_bl == 0x1d)                            //jz loc_18e3
        goto loc_18e3;
    if (_bl == 0x38)                            //jz loc_18e3
        goto loc_18e3;
    _al = _al | memory(_ds, _bx + 1088);        //or al, byte ptr [bx+0x440]
    if (_al != 0)                               //jnz loc_18ae
        _STOP_("goto loc_18ae");
loc_18e3:                                       //loc_18e3:
    _bx += 1;                                   //inc bx
    if (_bl < 0x7f)                             //jc loc_18c9
        goto loc_18c9;
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    if (memory(_ds, 1104) == 0x00)              //jz loc_1909
        goto loc_1909;
    if (memory(_ds, 1050) < 0x0a)               //jc loc_1909
        goto loc_1909;
    memory(_ds, 1051) += 1;                     //inc byte ptr [0x41b]
    memory(_ds, 1050) -= 0x0a;                  //sub byte ptr [0x41a], 0xa
loc_1909:                                       //loc_1909:
    sub_1958();                                 //call sub_1958
    sub_03f2();                                 //call sub_03f2
    sub_03ae();                                 //call sub_03ae
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_191c()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    sub_3160();                                 //call sub_3160
    sub_1958();                                 //call sub_1958
    memory16(_ds, 1084) = 0x0000;               //mov word ptr [0x43c], 0x0
loc_1936:                                       //loc_1936:
    sub_0805();                                 //call sub_0805
    if (memory(_ds, 1067) != 0x00)              //jnz loc_1948
        goto loc_1948;
    if (memory16(_ds, 1084) < 0x0168)           //jc loc_1936
        goto loc_1936;
loc_1948:                                       //loc_1948:
    memory16(_ds, 1084) = 0x0870;               //mov word ptr [0x43c], 0x870
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_1958()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _ax = 0x0009;                               //mov ax, 0x9
    sub_10ff();                                 //call sub_10ff
    sub_2811();                                 //call sub_2811
    sub_038a();                                 //call sub_038a
    memory16(_ds, 501) = 0x0005;                //mov word ptr [0x1f5], 0x5
    memory16(_ds, 503) = 0x03c0;                //mov word ptr [0x1f7], 0x3c0
    _si = 0x4ee3;                               //mov si, 0x4ee3
    sub_0488();                                 //call sub_0488
    memory16(_ds, 503) += 0x01e0;               //add word ptr [0x1f7], 0x1e0
    memory16(_ds, 501) -= 0x001e;               //sub word ptr [0x1f5], 0x1e
    _si = 0x4f02;                               //mov si, 0x4f02
    sub_0488();                                 //call sub_0488
    memory16(_ds, 503) += 0x01e0;               //add word ptr [0x1f7], 0x1e0
    memory16(_ds, 501) -= 0x001e;               //sub word ptr [0x1f5], 0x1e
    _si = 0x4f21;                               //mov si, 0x4f21
    sub_0488();                                 //call sub_0488
    memory16(_ds, 503) += 0x01e0;               //add word ptr [0x1f7], 0x1e0
    memory16(_ds, 501) -= 0x001e;               //sub word ptr [0x1f5], 0x1e
    _si = 0x4f40;                               //mov si, 0x4f40
    sub_0488();                                 //call sub_0488
    memory16(_ds, 503) += 0x01e0;               //add word ptr [0x1f7], 0x1e0
    memory16(_ds, 501) -= 0x001e;               //sub word ptr [0x1f5], 0x1e
    _si = 0x4f5f;                               //mov si, 0x4f5f
    sub_0488();                                 //call sub_0488
    memory16(_ds, 503) += 0x01e0;               //add word ptr [0x1f7], 0x1e0
    memory16(_ds, 501) -= 0x001e;               //sub word ptr [0x1f5], 0x1e
    _si = 0x4f7e;                               //mov si, 0x4f7e
    sub_0488();                                 //call sub_0488
    memory16(_ds, 503) += 0x01e0;               //add word ptr [0x1f7], 0x1e0
    memory16(_ds, 501) -= 0x001e;               //sub word ptr [0x1f5], 0x1e
    _si = 0x4f9d;                               //mov si, 0x4f9d
    sub_0488();                                 //call sub_0488
    memory16(_ds, 503) += 0x01e0;               //add word ptr [0x1f7], 0x1e0
    memory16(_ds, 501) -= 0x001e;               //sub word ptr [0x1f5], 0x1e
    _si = 0x4fbc;                               //mov si, 0x4fbc
    sub_0488();                                 //call sub_0488
    memory16(_ds, 501) = 0x000f;                //mov word ptr [0x1f5], 0xf
    memory16(_ds, 503) = 0x1770;                //mov word ptr [0x1f7], 0x1770
    _si = 0x4fdb;                               //mov si, 0x4fdb
    sub_0488();                                 //call sub_0488
    memory16(_ds, 501) = 0x0000;                //mov word ptr [0x1f5], 0x0
    memory16(_ds, 503) = 0x1a40;                //mov word ptr [0x1f7], 0x1a40
    _si = 0x4fe5;                               //mov si, 0x4fe5
    sub_0488();                                 //call sub_0488
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    return;                                     //ret
loc_1a29:                                       //loc_1a29:
    return;
}

void sub_1a2a()
{
    _al = memory(_ds, 0x45d);                   //mov al, [0x45d]
    _al = _al & memory(_ds, 1144);              //and al, byte ptr [0x478]
    _al = _al & memory(_ds, 1106);              //and al, byte ptr [0x452]
    if (_al == 0)                               //jz loc_1a29
        _STOP_("goto loc_1a29");
    _bx = 0x0001;                               //mov bx, 0x1
    _al = _al ^ _al;                            //xor al, al
loc_1a3c:                                       //loc_1a3c:
    if (_bl == 0x12)                            //jz loc_1a51
        goto loc_1a51;
    if (_bl == 0x1d)                            //jz loc_1a51
        goto loc_1a51;
    if (_bl == 0x38)                            //jz loc_1a51
        goto loc_1a51;
    _al = _al | memory(_ds, _bx + 1088);        //or al, byte ptr [bx+0x440]
    if (_al != 0)                               //jnz loc_1a29
        _STOP_("goto loc_1a29");
loc_1a51:                                       //loc_1a51:
    _bx += 1;                                   //inc bx
    if (_bl < 0x7f)                             //jc loc_1a3c
        goto loc_1a3c;
    _STOP_("goto loc_1a61");                    //jmp loc_1a61
}

void sub_1a59()
{
    if (memory16(_ds, 10) < 0x07c8)             //jc loc_1a29
        _STOP_("goto loc_1a29");
loc_1a61:                                       //loc_1a61:
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    _dx = 0x500e;                               //mov dx, 0x500e
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    sub_097b();                                 //call sub_097b
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    memory16(_ds, 0x04c1) = _ax;                //mov [0x4c1], ax
    memory16(_ds, 0x4e52) = _ax;                //mov [0x4e52], ax
    sub_1a8d();                                 //call sub_1a8d
    _ax = 0x0009;                               //mov ax, 0x9
    sub_10ff();                                 //call sub_10ff
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_1a8d()
{
    

    sub_3160();                                 //call sub_3160
    if (memory(_cs, 0x1) != 0x05)               //jnz loc_1ae4
        goto loc_1ae4;
    _ax = 0x000d;                               //mov ax, 0xd
    _interrupt(16);                             //int 0x10
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _dx = 0x4e54;                               //mov dx, 0x4e54
    _ax = 0x1002;                               //mov ax, 0x1002
    _interrupt(16);                             //int 0x10
    _dx = 0x03c8;                               //mov dx, 0x3c8
    _al = _al ^ _al;                            //xor al, al
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _cx = 0x0010;                               //mov cx, 0x10
    _al = _al ^ _al;                            //xor al, al
loc_1ab8:                                       //loc_1ab8:
    _out(_dx, _al);                             //out dx, al
    goto loc_1abb;                              //jmp loc_1abb
loc_1abb:                                       //loc_1abb:
    _out(_dx, _al);                             //out dx, al
    goto loc_1abe;                              //jmp loc_1abe
loc_1abe:                                       //loc_1abe:
    _out(_dx, _al);                             //out dx, al
    _al += 0x04;                                //add al, 0x4
    if (--_cx)                                  //loop loc_1ab8
        goto loc_1ab8;
    _ax = 0xa000;                               //mov ax, 0xa000
    _es = _ax;                                  //mov es, ax
    _ds = memory16(_ds, 20050);                 //mov ds, word ptr [0x4e52]
    _si = _si ^ _si;                            //xor si, si
    _dx = 0x03c4;                               //mov dx, 0x3c4
    _ax = 0x0102;                               //mov ax, 0x102
loc_1ad4:                                       //loc_1ad4:
    _out(_dx, _ax);                             //out dx, ax
    _cx = 0x0fa0;                               //mov cx, 0xfa0
    _di = _di ^ _di;                            //xor di, di
    _rep_movsw<MemData, MemData, DirForward>(); //rep movsw
    _ah <<= 1;                                  //shl ah, 1
    if (_ah <= 0x08)                            //jbe loc_1ad4
        goto loc_1ad4;
    return;                                     //ret
loc_1ae4:                                       //loc_1ae4:
    if (memory(_cs, 0x1) == 0x00)               //jz loc_1af1
        goto loc_1af1;
    _ax = 0x0006;                               //mov ax, 0x6
    _interrupt(16);                             //int 0x10
loc_1af1:                                       //loc_1af1:
    _ax = 0xb800;                               //mov ax, 0xb800
    _es = _ax;                                  //mov es, ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _di = _di ^ _di;                            //xor di, di
    _cx = 0x3e80;                               //mov cx, 0x3e80
    _rep_stosw<MemData, DirForward>();          //rep stosw
    memory(_ds, 20074) = 0x00;                  //mov byte ptr [0x4e6a], 0x0
    memory16(_ds, 20072) = 0x0000;              //mov word ptr [0x4e68], 0x0
    memory(_ds, 20077) = 0x00;                  //mov byte ptr [0x4e6d], 0x0
    memory16(_ds, 20075) = 0x0000;              //mov word ptr [0x4e6b], 0x0
    _bx = _bx ^ _bx;                            //xor bx, bx
loc_1b17:                                       //loc_1b17:
    sub_1bb6();                                 //call sub_1bb6
    _push(_ax);                                 //push ax
    _bx += _ax;                                 //add bx, ax
    if ((short)_bx < (short)0x0010)             //jl loc_1b30
        goto loc_1b30;
    sub_1b83();                                 //call sub_1b83
    sub_1c09();                                 //call sub_1c09
    _ax &= 0x0001;                              //and ax, 0x1
    _bx -= 0x0010;                              //sub bx, 0x10
    _bx += _ax;                                 //add bx, ax
loc_1b30:                                       //loc_1b30:
    memory16(_ds, 20072) += 1;                  //inc word ptr [0x4e68]
    _ax = _pop();                               //pop ax
    _bx += _ax;                                 //add bx, ax
    if ((short)_bx < (short)0x0010)             //jl loc_1b4a
        goto loc_1b4a;
    sub_1b83();                                 //call sub_1b83
    sub_1c09();                                 //call sub_1c09
    _ax &= 0x0001;                              //and ax, 0x1
    _bx -= 0x0010;                              //sub bx, 0x10
    _bx += _ax;                                 //add bx, ax
loc_1b4a:                                       //loc_1b4a:
    memory16(_ds, 20072) += 1;                  //inc word ptr [0x4e68]
    if (memory16(_ds, 20072) < 0x0280)          //jc loc_1b67
        goto loc_1b67;
    memory16(_ds, 20072) = 0x0000;              //mov word ptr [0x4e68], 0x0
    memory(_ds, 20074) += 1;                    //inc byte ptr [0x4e6a]
    if (memory(_ds, 20074) >= 0xc8)             //jnc loc_1b82
        goto loc_1b82;
loc_1b67:                                       //loc_1b67:
    if (memory16(_ds, 20075) < 0x0140)          //jc loc_1b80
        goto loc_1b80;
    memory16(_ds, 20075) = 0x0000;              //mov word ptr [0x4e6b], 0x0
    memory(_ds, 20077) += 1;                    //inc byte ptr [0x4e6d]
    if (memory(_ds, 20077) >= 0xc8)             //jnc loc_1b82
        goto loc_1b82;
loc_1b80:                                       //loc_1b80:
    goto loc_1b17;                              //jmp loc_1b17
loc_1b82:                                       //loc_1b82:
    return;
}

void sub_1b83()
{
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _al = memory(_ds, 0x4e6a);                  //mov al, [0x4e6a]
    _al >>= 1;                                  //shr al, 1
    _ah = 0x50;                                 //mov ah, 0x50
    _mul(_ah);                                  //mul ah
    if (!(memory(_ds, 20074) & 0x01))           //jz loc_1b99
        goto loc_1b99;
    _ax += 0x2000;                              //add ax, 0x2000
loc_1b99:                                       //loc_1b99:
    _di = _ax;                                  //mov di, ax
    _ax = memory16(_ds, 0x4e68);                //mov ax, [0x4e68]
    _cl = 0x03;                                 //mov cl, 0x3
    _ax >>= _cl;                                //shr ax, cl
    _di += _ax;                                 //add di, ax
    _cl = memory(_ds, 20072);                   //mov cl, byte ptr [0x4e68]
    _cl &= 0x07;                                //and cl, 0x7
    _ah = 0x80;                                 //mov ah, 0x80
    _ah >>= _cl;                                //shr ah, cl
    memory(_es, _di) |= _ah;                    //or byte ptr es:[di], ah
    _di = _pop();                               //pop di
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
}

void sub_1bb6()
{
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _al = memory(_ds, 0x4e6d);                  //mov al, [0x4e6d]
    _ah = 0x28;                                 //mov ah, 0x28
    _mul(_ah);                                  //mul ah
    _di = _di ^ _di;                            //xor di, di
    _di &= 0xfff0;                              //and di, 0xfff0
    _di += _ax;                                 //add di, ax
    _ax = memory16(_ds, 0x4e6b);                //mov ax, [0x4e6b]
    _cl = 0x03;                                 //mov cl, 0x3
    _ax >>= _cl;                                //shr ax, cl
    _di += _ax;                                 //add di, ax
    _cl = memory(_ds, 20075);                   //mov cl, byte ptr [0x4e6b]
    _cl &= 0x07;                                //and cl, 0x7
    _ah = 0x80;                                 //mov ah, 0x80
    _ah >>= _cl;                                //shr ah, cl
    _al = _al ^ _al;                            //xor al, al
    _push(_ds);                                 //push ds
    _ds = memory16(_ds, 20050);                 //mov ds, word ptr [0x4e52]
    if (!(memory(_ds, _di) & _ah))              //jz loc_1be7
        goto loc_1be7;
    _al += 1;                                   //inc al
loc_1be7:                                       //loc_1be7:
    if (!(memory(_ds, _di + 8000) & _ah))       //jz loc_1bef
        goto loc_1bef;
    _al += 0x02;                                //add al, 0x2
loc_1bef:                                       //loc_1bef:
    if (!(memory(_ds, _di + 16000) & _ah))      //jz loc_1bf7
        goto loc_1bf7;
    _al += 0x04;                                //add al, 0x4
loc_1bf7:                                       //loc_1bf7:
    if (!(memory(_ds, _di + 24000) & _ah))      //jz loc_1bff
        goto loc_1bff;
    _al += 0x08;                                //add al, 0x8
loc_1bff:                                       //loc_1bff:
    _ds = _pop();                               //pop ds
    _ah = _ah ^ _ah;                            //xor ah, ah
    memory16(_ds, 20075) += 1;                  //inc word ptr [0x4e6b]
    _di = _pop();                               //pop di
    _cx = _pop();                               //pop cx
}

void sub_1c09()
{
    _ax = memory16(_ds, 0x4e65);                //mov ax, [0x4e65]
    _ax += 0x9248;                              //add ax, 0x9248
    _ror(_ax, 1);                               //ror ax, 1
    _ror(_ax, 1);                               //ror ax, 1
    _ror(_ax, 1);                               //ror ax, 1
    memory16(_ds, 0x4e65) = _ax;                //mov [0x4e65], ax
    return;                                     //ret
    _STOP_("db 00h");                           //db 00h
    _STOP_("sp-trace-fail");                    //sub_1c09 endp_failed
    _STOP_("continues");                        //sub_1c1a proc near
}

void sub_1c1a()
{
    

    if (memory(_cs, 0x1) < 0x03)                //jc loc_1c2f
        goto loc_1c2f;
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _dx = 0x03da;                               //mov dx, 0x3da
    _in(_al, _dx);                              //in al, dx
    _dl = 0xc0;                                 //mov dl, 0xc0
    _al = 0x20;                                 //mov al, 0x20
    _out(_dx, _al);                             //out dx, al
    _ax = _pop();                               //pop ax
    _dx = _pop();                               //pop dx
loc_1c2f:                                       //loc_1c2f:
    return;
}

void sub_1c30()
{
    

    if (memory(_cs, 0x1) < 0x03)                //jc loc_1c45
        goto loc_1c45;
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _dx = 0x03da;                               //mov dx, 0x3da
    _in(_al, _dx);                              //in al, dx
    _dl = 0xc0;                                 //mov dl, 0xc0
    _al = _al ^ _al;                            //xor al, al
    _out(_dx, _al);                             //out dx, al
    _ax = _pop();                               //pop ax
    _dx = _pop();                               //pop dx
loc_1c45:                                       //loc_1c45:
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
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("sp-trace-fail");                    //sub_1c30 endp_failed
    _STOP_("continues");                        //sub_1c61 proc near
}

void sub_1c61()
{
    

    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _si = 0x567e;                               //mov si, 0x567e
loc_1c72:                                       //loc_1c72:
    memory16(_ds, 21114) = _si;                 //mov word ptr [0x527a], si
    if (memory16(_ds, _si + 4) != 0xffff)   //jnz loc_1c7f
        goto loc_1c7f;
    goto loc_24a9;                              //jmp loc_24a9
loc_1c7f:                                       //loc_1c7f:
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory(_cs, 0x1C49) = _al;                  //mov cs:[0x1c49], al
    memory(_cs, 0x1C53) = _al;                  //mov cs:[0x1c53], al
    memory(_cs, 0x1C56) = _al;                  //mov cs:[0x1c56], al
    memory(_cs, 0x1C57) = _al;                  //mov cs:[0x1c57], al
    memory16(_cs, 0x1C46) = _ax;                //mov cs:[0x1c46], ax
    memory(_ds, _si + 5) &= 0xdf;               //and byte ptr [si+0x5], 0xdf
    _bx = memory16(_ds, _si + 4);               //mov bx, word ptr [si+0x4]
    _flags.carry = !!(_bx & 0x8000);            //shl bx, 1
    _bx <<= 1;
    _rcl(memory(_cs, 0x1C48), 1);               //rcl byte ptr cs:[0x1c48], 1
    _al = 0x01;                                 //mov al, 0x1
    if (!(_bh & 0x80))                          //jz loc_1caf
        goto loc_1caf;
    _al = 0x41;                                 //mov al, 0x41
    _bh &= 0x7f;                                //and bh, 0x7f
loc_1caf:                                       //loc_1caf:
    memory(_cs, 0x1C5E) = _al;                  //mov cs:[0x1c5e], al
    _dx = memory16(_ds, _bx + 26213);           //mov dx, word ptr [bx+0x6665]
    _al = memory(_ds, _bx + 26927);             //mov al, byte ptr [bx+0x692f]
    if (!(memory(_cs, 0x1C48) & 0x01))          //jz loc_1cc9
        goto loc_1cc9;
    _al = _al - memory(_ds, _bx + 26213);       //sub al, byte ptr [bx+0x6665]
    _al = -_al;                                 //neg al
loc_1cc9:                                       //loc_1cc9:
    _cbw();                                     //cbw
    _ax = -_ax;                                 //neg ax
    _ax = _ax + memory16(_ds, _si);             //add ax, word ptr [si]
    _cx = memory16(_ds, 21104);                 //mov cx, word ptr [0x5270]
    _cx <<= 1;                                  //shl cx, 1
    _cx <<= 1;                                  //shl cx, 1
    _cx <<= 1;                                  //shl cx, 1
    _cx <<= 1;                                  //shl cx, 1
    _ax -= _cx;                                 //sub ax, cx
    _cx = _ax;                                  //mov cx, ax
    memory16(_cs, 0x1C50) = _ax;                //mov cs:[0x1c50], ax
    if ((short)_ax < (short)0x0140)             //jl loc_1cea
        goto loc_1cea;
    goto loc_24a9;                              //jmp loc_24a9
loc_1cea:                                       //loc_1cea:
    _flags.carry = (_cl + _dl) >= 0x100;        //add cl, dl
    _cl += _dl;
    _ch = _ch + 0x00 + _flags.carry;            //adc ch, 0x0
    if ((_ch & 0x80) == 0)                                //jns loc_1cf4
        goto loc_1cf4;
    goto loc_24a9;                              //jmp loc_24a9
loc_1cf4:                                       //loc_1cf4:
    _al = memory(_ds, _bx + 26928);             //mov al, byte ptr [bx+0x6930]
    _cbw();                                     //cbw
    _ax = _ax + memory16(_ds, _si + 2);         //add ax, word ptr [si+0x2]
    _ax += 1;                                   //inc ax
    _cx = memory16(_ds, 21106);                 //mov cx, word ptr [0x5272]
    _cx <<= 1;                                  //shl cx, 1
    _cx <<= 1;                                  //shl cx, 1
    _cx <<= 1;                                  //shl cx, 1
    _cx <<= 1;                                  //shl cx, 1
    _flags.carry2 = (short)_ax > (short)_cx;
    _ax -= _cx;                                 //sub ax, cx
    if (_flags.carry2)                                //jg loc_1d10
        goto loc_1d10;
    goto loc_24a9;                              //jmp loc_24a9
loc_1d10:                                       //loc_1d10:
    memory16(_ds, 0x5278) = _ax;                //mov [0x5278], ax
    memory(_cs, 0x1C52) = _dh;                  //mov byte ptr cs:[0x1c52], dh
    memory(_cs, 0x1C4C) = _dh;                  //mov byte ptr cs:[0x1c4c], dh
    _flags.carry = _al < _dh;                   //sub al, dh
    _al -= _dh;
    _ah -= 0x00 + _flags.carry;                 //sbb ah, 0x0
    if ((short)_ax < (short)0x00c0)             //jl loc_1d2a
        goto loc_1d2a;
    goto loc_24a9;                              //jmp loc_24a9
loc_1d2a:                                       //loc_1d2a:
    memory16(_cs, 0x1C4E) = _ax;                //mov cs:[0x1c4e], ax
    _cl = memory(_cs, 0x0);                     //mov cl, byte ptr cs:[0x0]
    _dl >>= _cl;                                //shr dl, cl
    memory(_cs, 0x1C4A) = _dl;                  //mov byte ptr cs:[0x1c4a], dl
    memory(_cs, 0x1C4B) = _dl;                  //mov byte ptr cs:[0x1c4b], dl
    _dh = _dh ^ _dh;                            //xor dh, dh
    _cx = _cx ^ _cx;                            //xor cx, cx
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (!_flags.sign)                           //jns loc_1d5a
        goto loc_1d5a;
    _ax = -_ax;                                 //neg ax
    memory(_cs, 0x1C52) -= _al;                 //sub byte ptr cs:[0x1c52], al
    _mul(_dl);                                  //mul dl
    _cx = _ax;                                  //mov cx, ax
    memory16(_cs, 0x1C46) = _ax;                //mov cs:[0x1c46], ax
    _di = _di ^ _di;                            //xor di, di
    goto loc_1d60;                              //jmp loc_1d60
loc_1d5a:                                       //loc_1d5a:
    _mul(memory(_ds, 21084));                   //mul byte ptr [0x525c]
    _di = _ax;                                  //mov di, ax
loc_1d60:                                       //loc_1d60:
    _di = _di + memory16(_ds, 21098);           //add di, word ptr [0x526a]
    memory16(_cs, 0x1C58) = _di;                //mov word ptr cs:[0x1c58], di
    _ax = memory16(_ds, _bx + 24004);           //mov ax, word ptr [bx+0x5dc4]
    memory16(_cs, 0x1C5C) = _ax;                //mov cs:[0x1c5c], ax
    _ax = memory16(_ds, _bx + 23204);           //mov ax, word ptr [bx+0x5aa4]
    _ax += _cx;                                 //add ax, cx
    memory16(_cs, 0x1C5A) = _ax;                //mov cs:[0x1c5a], ax
    _ax = memory16(_ds, 0x5278);                //mov ax, [0x5278]
    _flags.carry2 = (short)_ax <= (short)0x00c0;
    _ax -= 0x00c0;                              //sub ax, 0xc0
    if (_flags.carry2)                                //jle loc_1d8f
        goto loc_1d8f;
    memory(_cs, 0x1C52) -= _al;                 //sub byte ptr cs:[0x1c52], al
    _mul(_dl);                                  //mul dl
    memory16(_cs, 0x1C46) += _ax;               //add word ptr cs:[0x1c46], ax
loc_1d8f:                                       //loc_1d8f:
    _ax = memory16(_cs, 0x1C50);                //mov ax, cs:[0x1c50]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (!_flags.sign)                           //jns loc_1db0
        goto loc_1db0;
    _cl = memory(_cs, 0x0);                     //mov cl, byte ptr cs:[0x0]
    _sar(_ax, _cl);                             //sar ax, cl
    memory(_cs, 0x1C4A) += _al;                 //add byte ptr cs:[0x1c4a], al
    _al = -_al;                                 //neg al
    memory(_cs, 0x1C53) = _al;                  //mov cs:[0x1c53], al
    memory(_cs, 0x1C49) += 1;                   //inc byte ptr cs:[0x1c49]
    goto loc_1de8;                              //jmp loc_1de8
loc_1db0:                                       //loc_1db0:
    _cl = memory(_cs, 0x0);                     //mov cl, byte ptr cs:[0x0]
    _sar(_ax, _cl);                             //sar ax, cl
    memory16(_cs, 0x1C58) += _ax;               //add word ptr cs:[0x1c58], ax
    _ax = memory16(_cs, 0x1C50);                //mov ax, cs:[0x1c50]
    _cl = memory(_cs, 0x0);                     //mov cl, byte ptr cs:[0x0]
    _ax >>= _cl;                                //shr ax, cl
    _flags.carry = (_al + memory(_cs, 0x1C4A)) >= 0x100;
    _al = _al + memory(_cs, 0x1C4A);
    _ah = _ah + 0x00 + _flags.carry;            //adc ah, 0x0
    _flags.carry = _ax < memory16(_ds, 21084);  //sub ax, word ptr [0x525c]
    _ax = _ax - memory16(_ds, 21084);
    if (_flags.carry)                           //jc loc_1de8
        goto loc_1de8;
    memory(_cs, 0x1C4A) -= _al;                 //sub byte ptr cs:[0x1c4a], al
    memory(_cs, 0x1C49) += 1;                   //inc byte ptr cs:[0x1c49]
    memory(_cs, 0x1C56) = _al;                  //mov cs:[0x1c56], al
    memory(_cs, 0x1C57) = (~memory(_cs, 0x1C57));//not byte ptr cs:[0x1c57]
loc_1de8:                                       //loc_1de8:
    memory(_ds, _si + 5) |= 0x20;               //or byte ptr [si+0x5], 0x20
    if (memory(_cs, 0x1) < 0x03)                //jc loc_1df7
        goto loc_1df7;
    goto loc_203a;                              //jmp loc_203a
loc_1df7:                                       //loc_1df7:
    if (memory(_cs, 0x1C5E) == 0x01)            //jz loc_1e02
        goto loc_1e02;
    goto loc_24a9;                              //jmp loc_24a9
loc_1e02:                                       //loc_1e02:
    _al = memory(_cs, 0x1C4B);                  //mov al, cs:[0x1c4b]
    _mul(memory(_cs, 0x1C4C));                  //mul byte ptr cs:[0x1c4c]
    memory16(_cs, 0x1C5F) = _ax;                //mov cs:[0x1c5f], ax
    _es = memory16(_ds, 21090);                 //mov es, word ptr [0x5262]
    _di = memory16(_cs, 0x1C58);                //mov di, word ptr cs:[0x1c58]
    _ds = memory16(_cs, 0x1C5C);                //mov ds, word ptr cs:[0x1c5c]
    _bx = memory16(_cs, 0x1C5F);                //mov bx, word ptr cs:[0x1c5f]
    _si = memory16(_cs, 0x1C5A);                //mov si, word ptr cs:[0x1c5a]
    _dl = memory(_cs, 0x1C52);                  //mov dl, byte ptr cs:[0x1c52]
    if (memory(_cs, 0x1C49) != 0x00)            //jnz loc_1ea3
        goto loc_1ea3;
    if (memory16(_cs, 0x1C50) & 0x0003)         //jnz loc_1ea3
        goto loc_1ea3;
    _dh = memory(_cs, 0x1C4A);                  //mov dh, byte ptr cs:[0x1c4a]
    _ch = _ch ^ _ch;                            //xor ch, ch
    _cl = _dh;                                  //mov cl, dh
    if (memory(_cs, 0x1C48) & 0x01)             //jnz loc_1e6c
        goto loc_1e6c;
    _bp = 0x0050;                               //mov bp, 0x50
    _bp -= _cx;                                 //sub bp, cx
loc_1e53:                                       //loc_1e53:
    _cx >>= 1;                                  //shr cx, 1
loc_1e55:                                       //loc_1e55:
    _ax = memory16(_es, _di);                   //mov ax, word ptr es:[di]
    _ax = _ax & memory16(_ds, _bx + _si);       //and ax, word ptr [bx+si]
    _ax = _ax | memory16(_ds, _si);             //or ax, word ptr [si]
    _stosw<MemData, DirForward>();              //stosw
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    if (--_cx)                                  //loop loc_1e55
        goto loc_1e55;
    _cl = _dh;                                  //mov cl, dh
    _di += _bp;                                 //add di, bp
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz loc_1e53
        goto loc_1e53;
    goto loc_24a9;                              //jmp loc_24a9
loc_1e6c:                                       //loc_1e6c:
    _bp = _bx;                                  //mov bp, bx
    _bx = 0x330e;                               //mov bx, 0x330e
    _di += _cx;                                 //add di, cx
    _di -= 1;                                   //dec di
loc_1e74:                                       //loc_1e74:
    _cx >>= 1;                                  //shr cx, 1
loc_1e76:                                       //loc_1e76:
    _ax = memory16(_ds, _bp + _si + 0);         //mov ax, word ptr ds:[bp+si]
    _xlat();                                    //xlat
    memory(_es, _di) &= _al;                    //and byte ptr es:[di], al
    _lodsb<MemData, DirForward>();              //lodsb
    _xlat();                                    //xlat
    memory(_es, _di) |= _al;                    //or byte ptr es:[di], al
    _di -= 1;                                   //dec di
    _al = _ah;                                  //mov al, ah
    _xlat();                                    //xlat
    memory(_es, _di) &= _al;                    //and byte ptr es:[di], al
    _lodsb<MemData, DirForward>();              //lodsb
    _xlat();                                    //xlat
    memory(_es, _di) |= _al;                    //or byte ptr es:[di], al
    _di -= 1;                                   //dec di
    if (--_cx)                                  //loop loc_1e76
        goto loc_1e76;
    _cl = _dh;                                  //mov cl, dh
    _di += _cx;                                 //add di, cx
    _di += 0x0050;                              //add di, 0x50
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz loc_1e74
        goto loc_1e74;
loc_1ea0:                                       //loc_1ea0:
    goto loc_24a9;                              //jmp loc_24a9
loc_1ea3:                                       //loc_1ea3:
    if (memory(_cs, 0x1C4A) == 0x00)            //jz loc_1ea0
        goto loc_1ea0;
    _cl = memory(_cs, 0x1C50);                  //mov cl, byte ptr cs:[0x1c50]
    _cl &= 0x03;                                //and cl, 0x3
    _cl <<= 1;                                  //shl cl, 1
    _ch = 0xff;                                 //mov ch, 0xff
    _ch <<= _cl;                                //shl ch, cl
    if (memory(_cs, 0x1C48) & 0x01)             //jnz loc_1f3e
        goto loc_1f3e;
loc_1ec1:                                       //loc_1ec1:
    _al = memory(_cs, 0x1C4A);                  //mov al, cs:[0x1c4a]
    _cbw();                                     //cbw
    _bp = _ax;                                  //mov bp, ax
    _al = memory(_cs, 0x1C53);                  //mov al, cs:[0x1c53]
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    _ch = (~_ch);                               //not ch
    _dx = 0xff00;                               //mov dx, 0xff00
    _dh &= _ch;                                 //and dh, ch
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz loc_1ee4
        goto loc_1ee4;
    _dh = memory(_ds, _bx + _si + -1);          //mov dh, byte ptr [bx+si-0x1]
    _dh &= _ch;                                 //and dh, ch
    _dl = memory(_ds, _si - 1);                 //mov dl, byte ptr [si-0x1]
    _dl &= _ch;                                 //and dl, ch
loc_1ee4:                                       //loc_1ee4:
    _ch = (~_ch);                               //not ch
loc_1ee6:                                       //loc_1ee6:
    _al = memory(_ds, _bx + _si);               //mov al, byte ptr [bx+si]
    _ah = _al;                                  //mov ah, al
    _al &= _ch;                                 //and al, ch
    _al |= _dh;                                 //or al, dh
    _ror(_al, _cl);                             //ror al, cl
    memory(_es, _di) &= _al;                    //and byte ptr es:[di], al
    _lodsb<MemData, DirForward>();              //lodsb
    _dh = _al;                                  //mov dh, al
    _al &= _ch;                                 //and al, ch
    _al |= _dl;                                 //or al, dl
    _ror(_al, _cl);                             //ror al, cl
    memory(_es, _di) |= _al;                    //or byte ptr es:[di], al
    _ch = (~_ch);                               //not ch
    _dl = _dh;                                  //mov dl, dh
    _dh = _ah;                                  //mov dh, ah
    _dl &= _ch;                                 //and dl, ch
    _dh &= _ch;                                 //and dh, ch
    _ch = (~_ch);                               //not ch
    _di += 1;                                   //inc di
    _bp -= 1;                                   //dec bp
    if (_bp != 0)                               //jnz loc_1ee6
        goto loc_1ee6;
    if (memory(_cs, 0x1C57) != 0x00)            //jnz loc_1f23
        goto loc_1f23;
    _dh |= _ch;                                 //or dh, ch
    _ror(_dh, _cl);                             //ror dh, cl
    _ror(_dl, _cl);                             //ror dl, cl
    memory(_es, _di) &= _dh;                    //and byte ptr es:[di], dh
    memory(_es, _di) |= _dl;                    //or byte ptr es:[di], dl
loc_1f23:                                       //loc_1f23:
    _al = memory(_cs, 0x1C4A);                  //mov al, cs:[0x1c4a]
    _cbw();                                     //cbw
    _di -= _ax;                                 //sub di, ax
    _di += 0x0050;                              //add di, 0x50
    _al = memory(_cs, 0x1C56);                  //mov al, cs:[0x1c56]
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    memory(_cs, 0x1C52) -= 1;                   //dec byte ptr cs:[0x1c52]
    if (memory(_cs, 0x1C52) != 0)               //jnz loc_1ec1
        goto loc_1ec1;
    goto loc_24a9;                              //jmp loc_24a9
loc_1f3e:                                       //loc_1f3e:
    _al = memory(_cs, 0x1C53);                  //mov al, cs:[0x1c53]
    memory(_cs, 0x1C54) = _al;                  //mov cs:[0x1c54], al
    _cl = memory(_cs, 0x1C50);                  //mov cl, byte ptr cs:[0x1c50]
    _cl &= 0x03;                                //and cl, 0x3
    _cl -= 0x04;                                //sub cl, 0x4
    _cl = -_cl;                                 //neg cl
    _cl &= 0x03;                                //and cl, 0x3
    _cl <<= 1;                                  //shl cl, 1
    _ch = 0xff;                                 //mov ch, 0xff
    _ch >>= _cl;                                //shr ch, cl
    _bp = _bx;                                  //mov bp, bx
    _bx = 0x330e;                               //mov bx, 0x330e
    if (memory(_cs, 0x1C53) == 0x00)            //jz loc_1f7d
        goto loc_1f7d;
    _di -= 1;                                   //dec di
    if (!(memory16(_cs, 0x1C50) & 0x0003))      //jz loc_1f7d
        goto loc_1f7d;
    memory(_cs, 0x1C53) -= 1;                   //dec byte ptr cs:[0x1c53]
    memory(_cs, 0x1C4A) += 1;                   //inc byte ptr cs:[0x1c4a]
loc_1f7d:                                       //loc_1f7d:
    if (memory(_cs, 0x1C57) == 0x00)            //jz loc_1f9a
        goto loc_1f9a;
    _di -= 1;                                   //dec di
    if (!(memory16(_cs, 0x1C50) & 0x0003))      //jz loc_1f9a
        goto loc_1f9a;
    _di += 1;                                   //inc di
    memory(_cs, 0x1C4A) -= 1;                   //dec byte ptr cs:[0x1c4a]
    memory(_cs, 0x1C56) += 1;                   //inc byte ptr cs:[0x1c56]
loc_1f9a:                                       //loc_1f9a:
    _al = memory(_cs, 0x1C4A);                  //mov al, cs:[0x1c4a]
    _cbw();                                     //cbw
    _di += _ax;                                 //add di, ax
loc_1fa1:                                       //loc_1fa1:
    _al = memory(_cs, 0x1C4A);                  //mov al, cs:[0x1c4a]
    memory(_cs, 0x1C4D) = _al;                  //mov cs:[0x1c4d], al
    _ch = (~_ch);                               //not ch
    _dx = 0xff00;                               //mov dx, 0xff00
    _dh &= _ch;                                 //and dh, ch
    _ch = (~_ch);                               //not ch
    if (memory(_cs, 0x1C57) == 0x00)            //jz loc_1fd7
        goto loc_1fd7;
    _al = memory(_cs, 0x1C56);                  //mov al, cs:[0x1c56]
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    _al = memory(_ds, _bp + _si + -1);          //mov al, byte ptr ds:[bp+si-0x1]
    _xlat();                                    //xlat
    _dh = _al;                                  //mov dh, al
    _al = memory(_ds, _si - 1);                 //mov al, byte ptr [si-0x1]
    _xlat();                                    //xlat
    _dl = _al;                                  //mov dl, al
    memory(_cs, 0x1C4D) += 1;                   //inc byte ptr cs:[0x1c4d]
    goto loc_1ffa;                              //jmp loc_1ffa
loc_1fd7:                                       //loc_1fd7:
    _al = memory(_ds, _bp + _si + 0);           //mov al, byte ptr ds:[bp+si]
    _xlat();                                    //xlat
    _ah = _al;                                  //mov ah, al
    _al &= _ch;                                 //and al, ch
    _al |= _dh;                                 //or al, dh
    _rol(_al, _cl);                             //rol al, cl
    memory(_es, _di) &= _al;                    //and byte ptr es:[di], al
    _lodsb<MemData, DirForward>();              //lodsb
    _xlat();                                    //xlat
    _dh = _al;                                  //mov dh, al
    _al &= _ch;                                 //and al, ch
    _al |= _dl;                                 //or al, dl
    _rol(_al, _cl);                             //rol al, cl
    memory(_es, _di) |= _al;                    //or byte ptr es:[di], al
    _di -= 1;                                   //dec di
    _dl = _dh;                                  //mov dl, dh
    _dh = _ah;                                  //mov dh, ah
loc_1ffa:                                       //loc_1ffa:
    _ch = (~_ch);                               //not ch
    _dl &= _ch;                                 //and dl, ch
    _dh &= _ch;                                 //and dh, ch
    _ch = (~_ch);                               //not ch
    memory(_cs, 0x1C4D) -= 1;                   //dec byte ptr cs:[0x1c4d]
    if (memory(_cs, 0x1C4D) != 0)               //jnz loc_1fd7
        goto loc_1fd7;
    if (memory(_cs, 0x1C54) != 0x00)            //jnz loc_201d
        goto loc_201d;
    _dh |= _ch;                                 //or dh, ch
    _rol(_dh, _cl);                             //rol dh, cl
    _rol(_dl, _cl);                             //rol dl, cl
    memory(_es, _di) &= _dh;                    //and byte ptr es:[di], dh
    memory(_es, _di) |= _dl;                    //or byte ptr es:[di], dl
loc_201d:                                       //loc_201d:
    _al = memory(_cs, 0x1C4A);                  //mov al, cs:[0x1c4a]
    _cbw();                                     //cbw
    _di += _ax;                                 //add di, ax
    _di += 0x0050;                              //add di, 0x50
    _al = memory(_cs, 0x1C53);                  //mov al, cs:[0x1c53]
    _si += _ax;                                 //add si, ax
    memory(_cs, 0x1C52) -= 1;                   //dec byte ptr cs:[0x1c52]
    if (memory(_cs, 0x1C52) == 0)               //jz loc_2037
        goto loc_2037;
    goto loc_1fa1;                              //jmp loc_1fa1
loc_2037:                                       //loc_2037:
    goto loc_24a9;                              //jmp loc_24a9
loc_203a:                                       //loc_203a:
    sub_32dc();                                 //call sub_32dc
    _dx = 0x03c4;                               //mov dx, 0x3c4
    _ax = 0x0f02;                               //mov ax, 0xf02
    _out(_dx, _ax);                             //out dx, ax
    _cl = memory(_cs, 0x1C50);                  //mov cl, byte ptr cs:[0x1c50]
    _cl &= 0x07;                                //and cl, 0x7
    _ch = 0xff;                                 //mov ch, 0xff
    _ch <<= _cl;                                //shl ch, cl
    _di = memory16(_cs, 0x1C58);                //mov di, word ptr cs:[0x1c58]
    _si = memory16(_cs, 0x1C5A);                //mov si, word ptr cs:[0x1c5a]
    _dl = 0xce;                                 //mov dl, 0xce
    _al = 0x03;                                 //mov al, 0x3
    _ah = _cl;                                  //mov ah, cl
    _ah |= 0x08;                                //or ah, 0x8
    _out(_dx, _ax);                             //out dx, ax
    _bh = _ch;                                  //mov bh, ch
    _bh = (~_bh);                               //not bh
    _dh = memory(_cs, 0x1C4A);                  //mov dh, byte ptr cs:[0x1c4a]
    _cl = _dh;                                  //mov cl, dh
    _al = _cl;                                  //mov al, cl
    _cbw();                                     //cbw
    _ax -= 0x0028;                              //sub ax, 0x28
    _bp = _ax;                                  //mov bp, ax
    _dl = memory(_cs, 0x1C52);                  //mov dl, byte ptr cs:[0x1c52]
    _ds = memory16(_cs, 0x1C5C);                //mov ds, word ptr cs:[0x1c5c]
    _ax = 0xa000;                               //mov ax, 0xa000
    _es = _ax;                                  //mov es, ax
    if (memory(_cs, 0x1C48) & 0x01)             //jnz loc_2091
        goto loc_2091;
    goto loc_22e9;                              //jmp loc_22e9
loc_2091:                                       //loc_2091:
    memory(_cs, 0x1C4C) = _dl;                  //mov byte ptr cs:[0x1c4c], dl
    _dx = _bx;                                  //mov dx, bx
    _bx = 0x340e;                               //mov bx, 0x340e
    _flags.direction = true;                    //std
    _si -= 1;                                   //dec si
    if (memory(_cs, 0x1C49) == 0x00)            //jz loc_20a8
        goto loc_20a8;
    goto loc_21ef;                              //jmp loc_21ef
loc_20a8:                                       //loc_20a8:
    _al = _cl;                                  //mov al, cl
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    if (_ch == 0xff)                            //jz loc_20b5
        goto loc_20b5;
    goto loc_213c;                              //jmp loc_213c
loc_20b5:                                       //loc_20b5:
    _ch = _ch ^ _ch;                            //xor ch, ch
loc_20b7:                                       //loc_20b7:
    _lodsb<MemData, DirForward>();              //lodsb
    _xlat();                                    //xlat
    _al = (~_al);                               //not al
    _xchg(memory(_es, _di), _al);               //xchg byte ptr es:[di], al
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_20b7
        goto loc_20b7;
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _al = _cl;                                  //mov al, cl
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    _si += _ax;                                 //add si, ax
    _di -= _bp;                                 //sub di, bp
    memory(_cs, 0x1C4C) -= 1;                   //dec byte ptr cs:[0x1c4c]
    if (memory(_cs, 0x1C4C) != 0)               //jnz loc_20b7
        goto loc_20b7;
    _push(_dx);                                 //push dx
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _ax = 0x1003;                               //mov ax, 0x1003
    _out(_dx, _ax);                             //out dx, ax
    _dl = 0xc4;                                 //mov dl, 0xc4
    _al = 0x02;                                 //mov al, 0x2
    _out(_dx, _al);                             //out dx, al
    _al = memory(_cs, 0x1C5E);                  //mov al, cs:[0x1c5e]
    memory(_cs, 0x1C57) = (~memory(_cs, 0x1C57));//not byte ptr cs:[0x1c57]
    _dx = _pop();                               //pop dx
loc_20ee:                                       //loc_20ee:
    _push(_dx);                                 //push dx
    memory(_cs, 0x1C4D) = _al;                  //mov cs:[0x1c4d], al
    _dx = 0x03c5;                               //mov dx, 0x3c5
    _out(_dx, _al);                             //out dx, al
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _dl = memory(_cs, 0x1C52);                  //mov dl, byte ptr cs:[0x1c52]
    memory(_cs, 0x1C4C) = _dl;                  //mov byte ptr cs:[0x1c4c], dl
    _di = memory16(_cs, 0x1C58);                //mov di, word ptr cs:[0x1c58]
    _si = _si + memory16(_cs, 0x1C46);          //add si, word ptr cs:[0x1c46]
    _dx = _pop();                               //pop dx
loc_2111:                                       //loc_2111:
    _lodsb<MemData, DirForward>();              //lodsb
    _xlat();                                    //xlat
    _xchg(memory(_es, _di), _al);               //xchg byte ptr es:[di], al
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_2111
        goto loc_2111;
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _al = _cl;                                  //mov al, cl
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    _si += _ax;                                 //add si, ax
    _di -= _bp;                                 //sub di, bp
    memory(_cs, 0x1C4C) -= 1;                   //dec byte ptr cs:[0x1c4c]
    if (memory(_cs, 0x1C4C) != 0)               //jnz loc_2111
        goto loc_2111;
    _al = memory(_cs, 0x1C4D);                  //mov al, cs:[0x1c4d]
    _al <<= 1;                                  //shl al, 1
    if (_al < 0x10)                             //jc loc_20ee
        goto loc_20ee;
    goto loc_24a9;                              //jmp loc_24a9
loc_213c:                                       //loc_213c:
    _lodsb<MemData, DirForward>();              //lodsb
    _xlat();                                    //xlat
    _dl = _al;                                  //mov dl, al
    _al &= _ch;                                 //and al, ch
    _al |= _ah;                                 //or al, ah
    _al = (~_al);                               //not al
    _xchg(memory(_es, _di), _al);               //xchg byte ptr es:[di], al
    _di += 1;                                   //inc di
    _dl &= _dh;                                 //and dl, dh
    _ah = _dl;                                  //mov ah, dl
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_213c
        goto loc_213c;
    _ah = (~_ah);                               //not ah
    _xchg(memory(_es, _di), _ah);               //xchg byte ptr es:[di], ah
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _al = _cl;                                  //mov al, cl
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    _si += _ax;                                 //add si, ax
    _di -= _bp;                                 //sub di, bp
    memory(_cs, 0x1C4C) -= 1;                   //dec byte ptr cs:[0x1c4c]
    if (memory(_cs, 0x1C4C) != 0)               //jnz loc_213c
        goto loc_213c;
    _push(_dx);                                 //push dx
    _cl = memory(_cs, 0x1C50);                  //mov cl, byte ptr cs:[0x1c50]
    _cl &= 0x07;                                //and cl, 0x7
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _al = 0x03;                                 //mov al, 0x3
    _ah = _cl;                                  //mov ah, cl
    _ah |= 0x10;                                //or ah, 0x10
    _out(_dx, _ax);                             //out dx, ax
    _dl = 0xc4;                                 //mov dl, 0xc4
    _al = 0x02;                                 //mov al, 0x2
    _out(_dx, _al);                             //out dx, al
    _al = memory(_cs, 0x1C5E);                  //mov al, cs:[0x1c5e]
    memory(_cs, 0x1C57) = (~memory(_cs, 0x1C57));//not byte ptr cs:[0x1c57]
    _dx = _pop();                               //pop dx
loc_2190:                                       //loc_2190:
    _push(_dx);                                 //push dx
    memory(_cs, 0x1C4D) = _al;                  //mov cs:[0x1c4d], al
    _dx = 0x03c5;                               //mov dx, 0x3c5
    _out(_dx, _al);                             //out dx, al
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _dl = memory(_cs, 0x1C52);                  //mov dl, byte ptr cs:[0x1c52]
    memory(_cs, 0x1C4C) = _dl;                  //mov byte ptr cs:[0x1c4c], dl
    _di = memory16(_cs, 0x1C58);                //mov di, word ptr cs:[0x1c58]
    _si = _si + memory16(_cs, 0x1C46);          //add si, word ptr cs:[0x1c46]
    _dx = _pop();                               //pop dx
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_21b5:                                       //loc_21b5:
    _lodsb<MemData, DirForward>();              //lodsb
    _xlat();                                    //xlat
    _dl = _al;                                  //mov dl, al
    _al &= _ch;                                 //and al, ch
    _al |= _ah;                                 //or al, ah
    _xchg(memory(_es, _di), _al);               //xchg byte ptr es:[di], al
    _di += 1;                                   //inc di
    _dl &= _dh;                                 //and dl, dh
    _ah = _dl;                                  //mov ah, dl
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_21b5
        goto loc_21b5;
    _xchg(memory(_es, _di), _ah);               //xchg byte ptr es:[di], ah
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _al = _cl;                                  //mov al, cl
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    _si += _ax;                                 //add si, ax
    _di -= _bp;                                 //sub di, bp
    memory(_cs, 0x1C4C) -= 1;                   //dec byte ptr cs:[0x1c4c]
    if (memory(_cs, 0x1C4C) != 0)               //jnz loc_21b5
        goto loc_21b5;
    _al = memory(_cs, 0x1C4D);                  //mov al, cs:[0x1c4d]
    _al <<= 1;                                  //shl al, 1
    if (_al < 0x10)                             //jc loc_2190
        goto loc_2190;
    goto loc_24a9;                              //jmp loc_24a9
loc_21ef:                                       //loc_21ef:
    _al = memory(_cs, 0x1C4B);                  //mov al, cs:[0x1c4b]
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
loc_21f6:                                       //loc_21f6:
    _al = memory(_cs, 0x1C53);                  //mov al, cs:[0x1c53]
    _cbw();                                     //cbw
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz loc_220a
        goto loc_220a;
    _ax -= 1;                                   //dec ax
    _si -= _ax;                                 //sub si, ax
    _lodsb<MemData, DirForward>();              //lodsb
    _xlat();                                    //xlat
    _dl = _al;                                  //mov dl, al
    _cx += 1;                                   //inc cx
    goto loc_2219;                              //jmp loc_2219
loc_220a:                                       //loc_220a:
    _lodsb<MemData, DirForward>();              //lodsb
    _xlat();                                    //xlat
    _dl = _al;                                  //mov dl, al
    _al &= _ch;                                 //and al, ch
    _al |= _ah;                                 //or al, ah
    _al = (~_al);                               //not al
    _xchg(memory(_es, _di), _al);               //xchg byte ptr es:[di], al
    _di += 1;                                   //inc di
loc_2219:                                       //loc_2219:
    _dl &= _dh;                                 //and dl, dh
    _ah = _dl;                                  //mov ah, dl
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_220a
        goto loc_220a;
    _ah = (~_ah);                               //not ah
    _ah = _ah | memory(_cs, 0x1C57);            //or ah, byte ptr cs:[0x1c57]
    _xchg(memory(_es, _di), _ah);               //xchg byte ptr es:[di], ah
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _al = memory(_cs, 0x1C4B);                  //mov al, cs:[0x1c4b]
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    _al = _al - memory(_cs, 0x1C56);            //sub al, byte ptr cs:[0x1c56]
    _si += _ax;                                 //add si, ax
    _di -= _bp;                                 //sub di, bp
    memory(_cs, 0x1C4C) -= 1;                   //dec byte ptr cs:[0x1c4c]
    if (memory(_cs, 0x1C4C) != 0)               //jnz loc_21f6
        goto loc_21f6;
    _push(_dx);                                 //push dx
    _cl = memory(_cs, 0x1C50);                  //mov cl, byte ptr cs:[0x1c50]
    _cl &= 0x07;                                //and cl, 0x7
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _al = 0x03;                                 //mov al, 0x3
    _ah = _cl;                                  //mov ah, cl
    _ah |= 0x10;                                //or ah, 0x10
    _out(_dx, _ax);                             //out dx, ax
    _dl = 0xc4;                                 //mov dl, 0xc4
    _al = 0x02;                                 //mov al, 0x2
    _out(_dx, _al);                             //out dx, al
    _al = memory(_cs, 0x1C5E);                  //mov al, cs:[0x1c5e]
    memory(_cs, 0x1C57) = (~memory(_cs, 0x1C57));//not byte ptr cs:[0x1c57]
    _dx = _pop();                               //pop dx
loc_226a:                                       //loc_226a:
    _push(_dx);                                 //push dx
    memory(_cs, 0x1C4D) = _al;                  //mov cs:[0x1c4d], al
    _dx = 0x03c5;                               //mov dx, 0x3c5
    _out(_dx, _al);                             //out dx, al
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _dl = memory(_cs, 0x1C52);                  //mov dl, byte ptr cs:[0x1c52]
    memory(_cs, 0x1C4C) = _dl;                  //mov byte ptr cs:[0x1c4c], dl
    _di = memory16(_cs, 0x1C58);                //mov di, word ptr cs:[0x1c58]
    _si = _si + memory16(_cs, 0x1C46);          //add si, word ptr cs:[0x1c46]
    _dx = _pop();                               //pop dx
loc_228d:                                       //loc_228d:
    _al = memory(_cs, 0x1C53);                  //mov al, cs:[0x1c53]
    _cbw();                                     //cbw
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz loc_22a1
        goto loc_22a1;
    _ax -= 1;                                   //dec ax
    _si -= _ax;                                 //sub si, ax
    _lodsb<MemData, DirForward>();              //lodsb
    _xlat();                                    //xlat
    _dl = _al;                                  //mov dl, al
    _cx += 1;                                   //inc cx
    goto loc_22ae;                              //jmp loc_22ae
loc_22a1:                                       //loc_22a1:
    _lodsb<MemData, DirForward>();              //lodsb
    _xlat();                                    //xlat
    _dl = _al;                                  //mov dl, al
    _al &= _ch;                                 //and al, ch
    _al |= _ah;                                 //or al, ah
    _xchg(memory(_es, _di), _al);               //xchg byte ptr es:[di], al
    _di += 1;                                   //inc di
loc_22ae:                                       //loc_22ae:
    _dl &= _dh;                                 //and dl, dh
    _ah = _dl;                                  //mov ah, dl
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_22a1
        goto loc_22a1;
    _ah = _ah & memory(_cs, 0x1C57);            //and ah, byte ptr cs:[0x1c57]
    _xchg(memory(_es, _di), _ah);               //xchg byte ptr es:[di], ah
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _al = memory(_cs, 0x1C4B);                  //mov al, cs:[0x1c4b]
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    _al = _al - memory(_cs, 0x1C56);            //sub al, byte ptr cs:[0x1c56]
    _si += _ax;                                 //add si, ax
    _di -= _bp;                                 //sub di, bp
    memory(_cs, 0x1C4C) -= 1;                   //dec byte ptr cs:[0x1c4c]
    if (memory(_cs, 0x1C4C) != 0)               //jnz loc_228d
        goto loc_228d;
    _al = memory(_cs, 0x1C4D);                  //mov al, cs:[0x1c4d]
    _al <<= 1;                                  //shl al, 1
    if (_al >= 0x10)                            //jnc loc_22e6
        goto loc_22e6;
    goto loc_226a;                              //jmp loc_226a
loc_22e6:                                       //loc_22e6:
    goto loc_24a9;                              //jmp loc_24a9
loc_22e9:                                       //loc_22e9:
    if (memory(_cs, 0x1C49) == 0x00)            //jz loc_22f4
        goto loc_22f4;
    goto loc_23e2;                              //jmp loc_23e2
loc_22f4:                                       //loc_22f4:
    if (_ch != 0xff)                            //jnz loc_2354
        goto loc_2354;
    _ch = _ch ^ _ch;                            //xor ch, ch
loc_22fb:                                       //loc_22fb:
    _lodsb<MemData, DirForward>();              //lodsb
    _al = (~_al);                               //not al
    // gabo!!!
    memoryVideoGet(_es, _di);
    //_scasb();                                   //scasb
    //_di -= 1;                                   //dec di
    _stosb<MemVideo, DirForward>();              //stosb
    if (--_cx)                                  //loop loc_22fb
        goto loc_22fb;
    _cl = _dh;                                  //mov cl, dh
    _di -= _bp;                                 //sub di, bp
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz loc_22fb
        goto loc_22fb;
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _ax = 0x1003;                               //mov ax, 0x1003
    _out(_dx, _ax);                             //out dx, ax
    _dl = 0xc4;                                 //mov dl, 0xc4
    _al = 0x02;                                 //mov al, 0x2
    _out(_dx, _al);                             //out dx, al
    _al = memory(_cs, 0x1C5E);                  //mov al, cs:[0x1c5e]
loc_231b:                                       //loc_231b:
    memory(_cs, 0x1C4D) = _al;                  //mov cs:[0x1c4d], al
    _dx = 0x03c5;                               //mov dx, 0x3c5
    _out(_dx, _al);                             //out dx, al
    _dh = memory(_cs, 0x1C4A);                  //mov dh, byte ptr cs:[0x1c4a]
    _cl = _dh;                                  //mov cl, dh
    _dl = memory(_cs, 0x1C52);                  //mov dl, byte ptr cs:[0x1c52]
    _di = memory16(_cs, 0x1C58);                //mov di, word ptr cs:[0x1c58]
    _si = _si + memory16(_cs, 0x1C46);          //add si, word ptr cs:[0x1c46]
loc_2339:                                       //loc_2339:
    _lodsb<MemData, DirForward>();              //lodsb
    // gabo!!!
    memoryVideoGet(_es, _di);
    //_scasb();                                   //scasb
    //_di -= 1;                                   //dec di
    _stosb<MemVideo, DirForward>();              //stosb
    if (--_cx)                                  //loop loc_2339
        goto loc_2339;
    _di -= _bp;                                 //sub di, bp
    _cl = _dh;                                  //mov cl, dh
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz loc_2339
        goto loc_2339;
    _al = memory(_cs, 0x1C4D);                  //mov al, cs:[0x1c4d]
    _al <<= 1;                                  //shl al, 1
    if (_al < 0x10)                             //jc loc_231b
        goto loc_231b;
    goto loc_24a9;                              //jmp loc_24a9
loc_2354:                                       //loc_2354:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_2356:                                       //loc_2356:
    _lodsb<MemData, DirForward>();              //lodsb
    _bl = _al;                                  //mov bl, al
    _al &= _ch;                                 //and al, ch
    _al |= _ah;                                 //or al, ah
    _al = (~_al);                               //not al
    _scasb();                                   //scasb
    _di -= 1;                                   //dec di
    _stosb<MemData, DirForward>();              //stosb
    _bl &= _bh;                                 //and bl, bh
    _ah = _bl;                                  //mov ah, bl
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_2356
        goto loc_2356;
    _ah = (~_ah);                               //not ah
    _xchg(memory(_es, _di), _ah);               //xchg byte ptr es:[di], ah
    _cl = _dh;                                  //mov cl, dh
    _di -= _bp;                                 //sub di, bp
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz loc_2354
        goto loc_2354;
    _cl = memory(_cs, 0x1C50);                  //mov cl, byte ptr cs:[0x1c50]
    _cl &= 0x07;                                //and cl, 0x7
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _al = 0x03;                                 //mov al, 0x3
    _ah = _cl;                                  //mov ah, cl
    _ah |= 0x10;                                //or ah, 0x10
    _out(_dx, _ax);                             //out dx, ax
    _dl = 0xc4;                                 //mov dl, 0xc4
    _al = 0x02;                                 //mov al, 0x2
    _out(_dx, _al);                             //out dx, al
    _al = memory(_cs, 0x1C5E);                  //mov al, cs:[0x1c5e]
    memory(_cs, 0x1C57) = (~memory(_cs, 0x1C57));//not byte ptr cs:[0x1c57]
loc_2398:                                       //loc_2398:
    memory(_cs, 0x1C4D) = _al;                  //mov cs:[0x1c4d], al
    _dx = 0x03c5;                               //mov dx, 0x3c5
    _out(_dx, _al);                             //out dx, al
    _dh = memory(_cs, 0x1C4A);                  //mov dh, byte ptr cs:[0x1c4a]
    _cl = _dh;                                  //mov cl, dh
    _dl = memory(_cs, 0x1C52);                  //mov dl, byte ptr cs:[0x1c52]
    _di = memory16(_cs, 0x1C58);                //mov di, word ptr cs:[0x1c58]
    _si = _si + memory16(_cs, 0x1C46);          //add si, word ptr cs:[0x1c46]
loc_23b6:                                       //loc_23b6:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_23b8:                                       //loc_23b8:
    _lodsb<MemData, DirForward>();              //lodsb
    _bl = _al;                                  //mov bl, al
    _al &= _ch;                                 //and al, ch
    _al |= _ah;                                 //or al, ah
    _scasb();                                   //scasb
    _di -= 1;                                   //dec di
    _stosb<MemData, DirForward>();              //stosb
    _bl &= _bh;                                 //and bl, bh
    _ah = _bl;                                  //mov ah, bl
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_23b8
        goto loc_23b8;
    _xchg(memory(_es, _di), _ah);               //xchg byte ptr es:[di], ah
    _cl = _dh;                                  //mov cl, dh
    _di -= _bp;                                 //sub di, bp
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz loc_23b6
        goto loc_23b6;
    _al = memory(_cs, 0x1C4D);                  //mov al, cs:[0x1c4d]
    _al <<= 1;                                  //shl al, 1
    if (_al < 0x10)                             //jc loc_2398
        goto loc_2398;
    goto loc_24a9;                              //jmp loc_24a9
loc_23e2:                                       //loc_23e2:
    _al = memory(_cs, 0x1C53);                  //mov al, cs:[0x1c53]
    _cbw();                                     //cbw
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz loc_23f4
        goto loc_23f4;
    _ax -= 1;                                   //dec ax
    _cx += 1;                                   //inc cx
    _si += _ax;                                 //add si, ax
    _lodsb<MemData, DirForward>();              //lodsb
    _bl = _al;                                  //mov bl, al
    goto loc_2400;                              //jmp loc_2400
loc_23f4:                                       //loc_23f4:
    _lodsb<MemData, DirForward>();              //lodsb
    _bl = _al;                                  //mov bl, al
    _al &= _ch;                                 //and al, ch
    _al |= _ah;                                 //or al, ah
    _al = (~_al);                               //not al
    _scasb();                                   //scasb
    _di -= 1;                                   //dec di
    _stosb<MemData, DirForward>();              //stosb
loc_2400:                                       //loc_2400:
    _bl &= _bh;                                 //and bl, bh
    _ah = _bl;                                  //mov ah, bl
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_23f4
        goto loc_23f4;
    _ah = (~_ah);                               //not ah
    _ah = _ah | memory(_cs, 0x1C57);            //or ah, byte ptr cs:[0x1c57]
    _xchg(memory(_es, _di), _ah);               //xchg byte ptr es:[di], ah
    _al = memory(_cs, 0x1C56);                  //mov al, cs:[0x1c56]
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _di -= _bp;                                 //sub di, bp
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz loc_23e2
        goto loc_23e2;
    _cl = memory(_cs, 0x1C50);                  //mov cl, byte ptr cs:[0x1c50]
    _cl &= 0x07;                                //and cl, 0x7
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _al = 0x03;                                 //mov al, 0x3
    _ah = _cl;                                  //mov ah, cl
    _ah |= 0x10;                                //or ah, 0x10
    _out(_dx, _ax);                             //out dx, ax
    _dl = 0xc4;                                 //mov dl, 0xc4
    _al = 0x02;                                 //mov al, 0x2
    _out(_dx, _al);                             //out dx, al
    _al = memory(_cs, 0x1C5E);                  //mov al, cs:[0x1c5e]
    memory(_cs, 0x1C57) = (~memory(_cs, 0x1C57));//not byte ptr cs:[0x1c57]
loc_2445:                                       //loc_2445:
    memory(_cs, 0x1C4D) = _al;                  //mov cs:[0x1c4d], al
    _dx = 0x03c5;                               //mov dx, 0x3c5
    _out(_dx, _al);                             //out dx, al
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _dl = memory(_cs, 0x1C52);                  //mov dl, byte ptr cs:[0x1c52]
    _di = memory16(_cs, 0x1C58);                //mov di, word ptr cs:[0x1c58]
    _si = _si + memory16(_cs, 0x1C46);          //add si, word ptr cs:[0x1c46]
loc_2461:                                       //loc_2461:
    _al = memory(_cs, 0x1C53);                  //mov al, cs:[0x1c53]
    _cbw();                                     //cbw
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz loc_2473
        goto loc_2473;
    _ax -= 1;                                   //dec ax
    _cx += 1;                                   //inc cx
    _si += _ax;                                 //add si, ax
    _lodsb<MemData, DirForward>();              //lodsb
    _bl = _al;                                  //mov bl, al
    goto loc_247d;                              //jmp loc_247d
loc_2473:                                       //loc_2473:
    _lodsb<MemData, DirForward>();              //lodsb
    _bl = _al;                                  //mov bl, al
    _al &= _ch;                                 //and al, ch
    _al |= _ah;                                 //or al, ah
    _scasb();                                   //scasb
    _di -= 1;                                   //dec di
    _stosb<MemData, DirForward>();              //stosb
loc_247d:                                       //loc_247d:
    _bl &= _bh;                                 //and bl, bh
    _ah = _bl;                                  //mov ah, bl
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_2473
        goto loc_2473;
    _ah = _ah & memory(_cs, 0x1C57);            //and ah, byte ptr cs:[0x1c57]
    _xchg(memory(_es, _di), _ah);               //xchg byte ptr es:[di], ah
    _al = memory(_cs, 0x1C56);                  //mov al, cs:[0x1c56]
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _di -= _bp;                                 //sub di, bp
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz loc_2461
        goto loc_2461;
    _al = memory(_cs, 0x1C4D);                  //mov al, cs:[0x1c4d]
    _al <<= 1;                                  //shl al, 1
    if (_al < 0x10)                             //jc loc_2445
        goto loc_2445;
loc_24a9:                                       //loc_24a9:
    _flags.direction = false;                   //cld
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _si = memory16(_ds, 21114);                 //mov si, word ptr [0x527a]
    _si -= 0x0012;                              //sub si, 0x12
    if (_si < 0x527c)                           //jc loc_24bf
        goto loc_24bf;
    goto loc_1c72;                              //jmp loc_1c72
loc_24bf:                                       //loc_24bf:
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_24c9()
{
    

    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    if (memory(_cs, 0x1) >= 0x03)               //jnc loc_24f1
        goto loc_24f1;
    _ax = memory16(_ds, 0x04c1);                //mov ax, [0x4c1]
    memory16(_ds, 0x5262) = _ax;                //mov [0x5262], ax
    _ax += 0x0400;                              //add ax, 0x400
    memory16(_ds, 0x5264) = _ax;                //mov [0x5264], ax
    memory16(_ds, 1217) += 0x0800;              //add word ptr [0x4c1], 0x800
loc_24f1:                                       //loc_24f1:
    _si = 0x7255;                               //mov si, 0x7255
    _bx = _bx ^ _bx;                            //xor bx, bx
loc_24f6:                                       //loc_24f6:
    _lodsw<MemData, DirForward>();              //lodsw
    if (_ax == 0xffff)                          //jz loc_251a
        goto loc_251a;
loc_24fc:                                       //loc_24fc:
    if (_ax == _bx)                             //jz loc_2508
        goto loc_2508;
    memory(_ds, _bx + 28869) = 0x00;            //mov byte ptr [bx+0x70c5], 0x0
    _bx += 1;                                   //inc bx
    goto loc_24fc;                              //jmp loc_24fc
loc_2508:                                       //loc_2508:
    _lodsw<MemData, DirForward>();              //lodsw
loc_2509:                                       //loc_2509:
    memory(_ds, _bx + 28869) = 0x01;            //mov byte ptr [bx+0x70c5], 0x1
    _bx += 1;                                   //inc bx
    _ax -= 1;                                   //dec ax
    if (_ax != 0)                               //jnz loc_2509
        goto loc_2509;
    goto loc_24f6;                              //jmp loc_24f6
loc_2514:                                       //loc_2514:
    memory(_ds, _bx + 28869) = 0x00;            //mov byte ptr [bx+0x70c5], 0x0
    _bx += 1;                                   //inc bx
loc_251a:                                       //loc_251a:
    if (_bx == 0x0190)                          //jz loc_2514
        goto loc_2514;
    _dx = 0x501a;                               //mov dx, 0x501a
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    sub_097b();                                 //call sub_097b --- 020d:2525 logo 2 on screen, no change
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    memory16(_ds, 0x5260) = _ax;                //mov [0x5260], ax
    _bx = _bx ^ _bx;                            //xor bx, bx
loc_252f:                                       //loc_252f:
    _al = memory(_ds, _bx + 26214);             //mov al, byte ptr [bx+0x6666]
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz loc_2543
        goto loc_2543;
    memory(_ds, _bx + 26928) -= _al;            //sub byte ptr [bx+0x6930], al
    memory(_ds, _bx + 26928) = -memory(_ds, _bx + 26928);
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    goto loc_252f;                              //jmp loc_252f
loc_2543:                                       //loc_2543:
    if (memory(_cs, 0x1) < 0x03)                //jc loc_254e
        goto loc_254e;
    goto loc_263e;                              //jmp loc_263e
loc_254e:                                       //loc_254e:
    _si = _si ^ _si;                            //xor si, si
    memory16(_cs, 0x6676) = 0x274f;             //mov word ptr cs:[0x6676], 0x274f
    _ax = memory16(_ds, 0x5260);                //mov ax, [0x5260]
    memory16(_ds, 0x5268) = _ax;                //mov [0x5268], ax
    memory16(_ds, 21086) = 0x0000;              //mov word ptr [0x525e], 0x0
    _es = memory16(_ds, 1217);                  //mov es, word ptr [0x4c1]
loc_2567:                                       //loc_2567:
    _push(_es);                                 //push es
    _ax = 0xb800;                               //mov ax, 0xb800
    _es = _ax;                                  //mov es, ax
    _di = 0x1ef0;                               //mov di, 0x1ef0
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _cx = memory16(_ds, 21086);                 //mov cx, word ptr [0x525e]
    _dx = _cx;                                  //mov dx, cx
    _dx >>= 1;                                  //shr dx, 1
    _dx >>= 1;                                  //shr dx, 1
    _di += _dx;                                 //add di, dx
    _al = 0xc0;                                 //mov al, 0xc0
    _cl &= 0x03;                                //and cl, 0x3
    _cl <<= 1;                                  //shl cl, 1
    _al >>= _cl;                                //shr al, cl
    memory(_es, _di) |= _al;                    //or byte ptr es:[di], al
    _es = _pop();                               //pop es
    _ax = _si;                                  //mov ax, si
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    memory16(_ds, 21096) += _ax;                //add word ptr [0x5268], ax
    _si &= 0x000f;                              //and si, 0xf
    _di = _di ^ _di;                            //xor di, di
    _bx = memory16(_ds, 21086);                 //mov bx, word ptr [0x525e]
    memory16(_ds, 21086) += 1;                  //inc word ptr [0x525e]
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _bx + 26213);           //mov ax, word ptr [bx+0x6665]
    _dx = _ax;                                  //mov dx, ax
    _mul(_ah);                                  //mul ah
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    if (_ax == 0)                               //jz loc_2608
        goto loc_2608;
    _cx = _ax;                                  //mov cx, ax
    _push(_si);                                 //push si
    _ds = memory16(_ds, 21096);                 //mov ds, word ptr [0x5268]
    _rep_movsw<MemData, MemData, DirForward>(); //rep movsw
    _si = _pop();                               //pop si
    _bx = _ax;                                  //mov bx, ax
    _al = _dh;                                  //mov al, dh
    _ah = _dl;                                  //mov ah, dl
    _ah >>= 1;                                  //shr ah, 1
    _ah >>= 1;                                  //shr ah, 1
    _ah >>= 1;                                  //shr ah, 1
    sub_65be();                                 //call sub_65be
    _si += _bx;                                 //add si, bx
    _bx >>= 1;                                  //shr bx, 1
    _bp = _bx;                                  //mov bp, bx
    _di = _di ^ _di;                            //xor di, di
loc_25da:                                       //loc_25da:
    _al = memory(_es, _di);                     //mov al, byte ptr es:[di]
    _di += _bx;                                 //add di, bx
    _al = _al | memory(_es, _di);               //or al, byte ptr es:[di]
    _di += _bx;                                 //add di, bx
    _al = _al | memory(_es, _di);               //or al, byte ptr es:[di]
    _al = _al | memory(_es, _bx + _di);         //or al, byte ptr es:[bx+di]
    _di -= _bx;                                 //sub di, bx
    _di -= _bx;                                 //sub di, bx
    _cx = 0x0008;                               //mov cx, 0x8
loc_25f1:                                       //loc_25f1:
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    _rcr(_dx, 1);                               //rcr dx, 1
    _sar(_dx, 1);                               //sar dx, 1
    if (--_cx)                                  //loop loc_25f1
        goto loc_25f1;
    _xchg(_dh, _dl);                            //xchg dh, dl
    _dx = (~_dx);                               //not dx
    memory16(_ds, _si) = _dx;                   //mov word ptr [si], dx
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    _bp -= 1;                                   //dec bp
    if (_bp != 0)                               //jnz loc_25da
        goto loc_25da;
    goto loc_2567;                              //jmp loc_2567
loc_2608:                                       //loc_2608:
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _di = _di ^ _di;                            //xor di, di
    _bx = memory16(_ds, 21088);                 //mov bx, word ptr [0x5260]
    _cx = _cx ^ _cx;                            //xor cx, cx
loc_2615:                                       //loc_2615:
    memory16(_ds, _di + 24004) = _bx;           //mov word ptr [di+0x5dc4], bx
    memory16(_ds, _di + 23204) = _cx;           //mov word ptr [di+0x5aa4], cx
    _ax = memory16(_ds, _di + 26213);           //mov ax, word ptr [di+0x6665]
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _mul(_ah);                                  //mul ah
    _ax >>= 1;                                  //shr ax, 1
    if (_ax == 0)                               //jz loc_263b
        goto loc_263b;
    _cx += _ax;                                 //add cx, ax
    if (_cx < 0x1000)                           //jc loc_2615
        goto loc_2615;
    _cx -= 0x1000;                              //sub cx, 0x1000
    _bx += 0x0100;                              //add bx, 0x100
    goto loc_2615;                              //jmp loc_2615
loc_263b:                                       //loc_263b:
    goto loc_273d;                              //jmp loc_273d
loc_263e:                                       //loc_263e:
    _flags.direction = true;                    //std
    _ax = memory16(_ds, 0x04c1);                //mov ax, [0x4c1]
    _bx = memory16(_ds, 21088);                 //mov bx, word ptr [0x5260]
    _ax -= _bx;                                 //sub ax, bx
    _bp = _ax;                                  //mov bp, ax
    _dx = _ax;                                  //mov dx, ax
    _dx >>= 1;                                  //shr dx, 1
    _dx >>= 1;                                  //shr dx, 1
    _dx += 1;                                   //inc dx
    _ax += _dx;                                 //add ax, dx
    _ax += _bx;                                 //add ax, bx
    memory16(_ds, 0x04c1) = _ax;                //mov [0x4c1], ax
    _ax -= 1;                                   //dec ax
    _bx = _ax;                                  //mov bx, ax
    _ax -= _dx;                                 //sub ax, dx
loc_265d:                                       //loc_265d:
    _ds = _ax;                                  //mov ds, ax
    _es = _bx;                                  //mov es, bx
    _si = 0x000f;                               //mov si, 0xf
    _di = _si;                                  //mov di, si
    _cx = 0x0010;                               //mov cx, 0x10
    _rep_movsb<MemData, MemData, DirBackward>(); //rep movsb
    _ax -= 1;                                   //dec ax
    _bx -= 1;                                   //dec bx
    _bp -= 1;                                   //dec bp
    if (_bp != 0)                               //jnz loc_265d
        goto loc_265d;
    _flags.direction = false;                   //cld
    _dx = reloc(0x168f);                               //mov dx, reloc(0x168f)
    _ds = _dx;                                  //mov ds, dx
    _ax += 1;                                   //inc ax
    _bx += 1;                                   //inc bx
    memory16(_ds, 0x5087) = _ax;                //mov [0x5087], ax
    memory16(_ds, 20617) = _bx;                 //mov word ptr [0x5089], bx
    _bx = 0x6665;                               //mov bx, 0x6665
    _si = _si ^ _si;                            //xor si, si
    _di = _di ^ _di;                            //xor di, di
loc_2686:                                       //loc_2686:
    _ax = _si;                                  //mov ax, si
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    memory16(_ds, 20617) += _ax;                //add word ptr [0x5089], ax
    _si &= 0x000f;                              //and si, 0xf
    _ax = _di;                                  //mov ax, di
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    memory16(_ds, 20615) += _ax;                //add word ptr [0x5087], ax
    _di &= 0x000f;                              //and di, 0xf
    _ax = memory16(_ds, _bx);                   //mov ax, word ptr [bx]
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz loc_26f2
        goto loc_26f2;
    _ror(_al, 1);                               //ror al, 1
    _ror(_al, 1);                               //ror al, 1
    _ror(_al, 1);                               //ror al, 1
    if (!(_al & 0xe0))                          //jz loc_26bc
        goto loc_26bc;
    _al &= 0x1f;                                //and al, 0x1f
    _al += 1;                                   //inc al
loc_26bc:                                       //loc_26bc:
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _mul(_ah);                                  //mul ah
    _bp = _ax;                                  //mov bp, ax
    _es = memory16(_ds, 20615);                 //mov es, word ptr [0x5087]
    _ds = memory16(_ds, 20617);                 //mov ds, word ptr [0x5089]
    _cx = _bp;                                  //mov cx, bp
    _push(_si);                                 //push si
loc_26cd:                                       //loc_26cd:
    _al = memory(_ds, _si);                     //mov al, byte ptr [si]
    _al = _al | memory(_ds, _bp + _si + 0);     //or al, byte ptr ds:[bp+si]
    _si += _bp;                                 //add si, bp
    _al = _al | memory(_ds, _bp + _si + 0);     //or al, byte ptr ds:[bp+si]
    _si += _bp;                                 //add si, bp
    _al = _al | memory(_ds, _bp + _si + 0);     //or al, byte ptr ds:[bp+si]
    _si -= _bp;                                 //sub si, bp
    _si -= _bp;                                 //sub si, bp
    _stosb<MemData, DirForward>();              //stosb
    _si += 1;                                   //inc si
    if (--_cx)                                  //loop loc_26cd
        goto loc_26cd;
    _si = _pop();                               //pop si
    _cx = _bp;                                  //mov cx, bp
    _cx <<= 1;                                  //shl cx, 1
    _rep_movsw<MemData, MemData, DirForward>(); //rep movsw
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    goto loc_2686;                              //jmp loc_2686
loc_26f2:                                       //loc_26f2:
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _bx = memory16(_ds, 21088);                 //mov bx, word ptr [0x5260]
    _si = 0x6665;                               //mov si, 0x6665
    _di = _di ^ _di;                            //xor di, di
    _dx = _dx ^ _dx;                            //xor dx, dx
loc_2704:                                       //loc_2704:
    _lodsw<MemData, DirForward>();              //lodsw
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz loc_273d
        goto loc_273d;
    _ror(_al, 1);                               //ror al, 1
    _ror(_al, 1);                               //ror al, 1
    _ror(_al, 1);                               //ror al, 1
    if (!(_al & 0xe0))                          //jz loc_2717
        goto loc_2717;
    _al &= 0x1f;                                //and al, 0x1f
    _al += 1;                                   //inc al
loc_2717:                                       //loc_2717:
    _mul(_ah);                                  //mul ah
    _bp = _ax;                                  //mov bp, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax += _bp;                                 //add ax, bp
    memory16(_ds, _di + 23204) = _dx;           //mov word ptr [di+0x5aa4], dx
    memory16(_ds, _di + 24004) = _bx;           //mov word ptr [di+0x5dc4], bx
    if (_dx < 0x1000)                           //jc loc_2737
        goto loc_2737;
    _dx -= 0x1000;                              //sub dx, 0x1000
    _bx += 0x0100;                              //add bx, 0x100
loc_2737:                                       //loc_2737:
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _dx += _ax;                                 //add dx, ax
    goto loc_2704;                              //jmp loc_2704
loc_273d:                                       //loc_273d:
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
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
    _STOP_("db ffh");                           //db ffh
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db aah");                           //db aah
    _STOP_("db aah");                           //db aah
    _STOP_("db aah");                           //db aah
    _STOP_("db aah");                           //db aah
    _STOP_("db aah");                           //db aah
    _STOP_("db aah");                           //db aah
    _STOP_("db aah");                           //db aah
    _STOP_("db aah");                           //db aah
    _STOP_("db 00h");                           //db 00h
    _STOP_("db aah");                           //db aah
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db aah");                           //db aah
    _STOP_("db aah");                           //db aah
    _STOP_("db ffh");                           //db ffh
    _STOP_("db ffh");                           //db ffh
    _STOP_("sp-trace-fail");                    //sub_24c9 endp_failed
    _STOP_("continues");                        //sub_276f proc near
}

void sub_276f()
{
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    sub_2c87();                                 //call sub_2c87
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    sub_27df();                                 //call sub_27df
    sub_32f4();                                 //call sub_32f4
    _bp = 0x0002;                               //mov bp, 0x2
    _di = 0x0c92;                               //mov di, 0xc92
loc_2789:                                       //loc_2789:
    sub_3243();                                 //call sub_3243
    _cx = _bp;                                  //mov cx, bp
loc_278e:                                       //loc_278e:
    sub_28cd();                                 //call sub_28cd
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_278e
        goto loc_278e;
    _di -= 1;                                   //dec di
    _di -= 1;                                   //dec di
    _cx = _bp;                                  //mov cx, bp
    _cx -= 1;                                   //dec cx
loc_279a:                                       //loc_279a:
    _di += 0x0190;                              //add di, 0x190
    sub_28cd();                                 //call sub_28cd
    if (--_cx)                                  //loop loc_279a
        goto loc_279a;
    _cx = _bp;                                  //mov cx, bp
    _cx -= 1;                                   //dec cx
loc_27a6:                                       //loc_27a6:
    _di -= 1;                                   //dec di
    _di -= 1;                                   //dec di
    sub_28cd();                                 //call sub_28cd
    if (--_cx)                                  //loop loc_27a6
        goto loc_27a6;
    _cx = _bp;                                  //mov cx, bp
    _cx -= 1;                                   //dec cx
loc_27b0:                                       //loc_27b0:
    _di -= 0x0190;                              //sub di, 0x190
    sub_28cd();                                 //call sub_28cd
    if (--_cx)                                  //loop loc_27b0
        goto loc_27b0;
    _bp += 1;                                   //inc bp
    _bp += 1;                                   //inc bp
    _di -= 0x0192;                              //sub di, 0x192
    if (_bp < 0x0014)                           //jc loc_2789
        goto loc_2789;
    _di = memory16(_ds, 21098);                 //mov di, word ptr [0x526a]
    _si = memory16(_ds, 21096);                 //mov si, word ptr [0x5268]
    _ax = 0xa000;                               //mov ax, 0xa000
    _es = _ax;                                  //mov es, ax
    _ds = _ax;                                  //mov ds, ax
    _cx = 0x1e00;                               //mov cx, 0x1e00
    _rep_movsb<MemVideo, MemVideo, DirForward>(); //rep movsb
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
}

void sub_27df()
{
    

    if (memory(_cs, 0x1) >= 0x03)               //jnc loc_27ec
        goto loc_27ec;
    sub_3160();                                 //call sub_3160
    goto loc_2810;                              //jmp loc_2810
loc_27ec:                                       //loc_27ec:
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_es);                                 //push es
    sub_32dc();                                 //call sub_32dc
    _ax = 0xa000;                               //mov ax, 0xa000
    _es = _ax;                                  //mov es, ax
    _dx = 0x03c4;                               //mov dx, 0x3c4
    _ax = 0x0f02;                               //mov ax, 0xf02
    _out(_dx, _ax);                             //out dx, ax
    _di = memory16(_ds, 21096);                 //mov di, word ptr [0x5268]
    _cx = 0x0f00;                               //mov cx, 0xf00
    _ax = _ax ^ _ax;                            //xor ax, ax
    _rep_stosw<MemVideo, DirForward>();          //rep stosw
    _es = _pop();                               //pop es
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
loc_2810:                                       //loc_2810:
    return;
}

void sub_2811()
{
    

    if (memory(_cs, 0x1) >= 0x03)               //jnc loc_281d
        goto loc_281d;
    sub_3160();                                 //call sub_3160
    return;                                     //ret
loc_281d:                                       //loc_281d:
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    sub_32dc();                                 //call sub_32dc
    _dx = 0x03c4;                               //mov dx, 0x3c4
    _ax = 0x0f02;                               //mov ax, 0xf02
    _out(_dx, _ax);                             //out dx, ax
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _di = memory16(_ds, 21096);                 //mov di, word ptr [0x5268]
    _cx = 0x0014;                               //mov cx, 0x14
    memory16(_cs, 0x274D) = 0x0026;             //mov word ptr cs:[0x274d], 0x26
    memory16(_cs, 0x274B) = 0x1c70;             //mov word ptr cs:[0x274b], 0x1c70
loc_2847:                                       //loc_2847:
    sub_3243();                                 //call sub_3243
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    memory16(_cs, 0x2747) = 0x0000;             //mov word ptr cs:[0x2747], 0x0
    memory16(_cs, 0x2749) = 0x0000;             //mov word ptr cs:[0x2749], 0x0
loc_285a:                                       //loc_285a:
    _di = _di + memory16(_cs, 0x2749);          //add di, word ptr cs:[0x2749]
    sub_28f8();                                 //call sub_28f8
    _di = _di + memory16(_cs, 0x274B);          //add di, word ptr cs:[0x274b]
    sub_28f8();                                 //call sub_28f8
    _di = _di - memory16(_cs, 0x274B);          //sub di, word ptr cs:[0x274b]
    _di = _di - memory16(_cs, 0x2749);          //sub di, word ptr cs:[0x2749]
    if (memory16(_cs, 0x2747) <= 0x1c70)        //jbe loc_2883
        goto loc_2883;
    _di += 0x1c70;                              //add di, 0x1c70
    goto loc_2888;                              //jmp loc_2888
loc_2883:                                       //loc_2883:
    _di = _di + memory16(_cs, 0x2747);          //add di, word ptr cs:[0x2747]
loc_2888:                                       //loc_2888:
    sub_28f8();                                 //call sub_28f8
    _di = _di + memory16(_cs, 0x274D);          //add di, word ptr cs:[0x274d]
    sub_28f8();                                 //call sub_28f8
    _di = _di - memory16(_cs, 0x274D);          //sub di, word ptr cs:[0x274d]
    _di = _di - memory16(_cs, 0x2747);          //sub di, word ptr cs:[0x2747]
    memory16(_cs, 0x2747) += 0x0190;            //add word ptr cs:[0x2747], 0x190
    memory16(_cs, 0x2749) += 0x0002;            //add word ptr cs:[0x2749], 0x2
    if (--_cx)                                  //loop loc_285a
        goto loc_285a;
    _di = _pop();                               //pop di
    _di += 0x0192;                              //add di, 0x192
    memory16(_cs, 0x274D) -= 0x0004;            //sub word ptr cs:[0x274d], 0x4
    memory16(_cs, 0x274B) -= 0x0320;            //sub word ptr cs:[0x274b], 0x320
    _cx = _pop();                               //pop cx
    _cx -= 1;                                   //dec cx
    _cx -= 1;                                   //dec cx
    if (_cx != 0)                               //jnz loc_2847
        goto loc_2847;
    sub_32dc();                                 //call sub_32dc
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
}

void sub_28cd()
{
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _si = _di;                                  //mov si, di
    _si = _si + memory16(_ds, 21098);           //add si, word ptr [0x526a]
    _di = _di + memory16(_ds, 21096);           //add di, word ptr [0x5268]
    _ax = 0xa000;                               //mov ax, 0xa000
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _cx = 0x000a;                               //mov cx, 0xa
loc_28e7:                                       //loc_28e7:
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += 0x0026;                              //add di, 0x26
    _si += 0x0026;                              //add si, 0x26
    if (--_cx)                                  //loop loc_28e7
        goto loc_28e7;
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
}

void sub_28f8()
{
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _push(_es);                                 //push es
    _ax = 0xa000;                               //mov ax, 0xa000
    _es = _ax;                                  //mov es, ax
    _cx = 0x000a;                               //mov cx, 0xa
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_2906:                                       //loc_2906:
    _stosw<MemVideo, DirForward>();              //stosw
    _di += 0x0026;                              //add di, 0x26
    if (--_cx)                                  //loop loc_2906
        goto loc_2906;
    _es = _pop();                               //pop es
    _di = _pop();                               //pop di
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
}

void sub_2911()
{
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    if (memory16(_ds, 21106) == 0x0000)         //jz loc_2946
        goto loc_2946;
    memory16(_ds, 21106) -= 1;                  //dec word ptr [0x5272]
    _ax = memory16(_ds, 0x5276);                //mov ax, [0x5276]
    _ax -= 1;                                   //dec ax
    if ((short)_ax >= 0)                        //jns loc_292e
        goto loc_292e;
    _ax = 0x000b;                               //mov ax, 0xb
loc_292e:                                       //loc_292e:
    _di = _di ^ _di;                            //xor di, di
    memory16(_ds, 0x5276) = _ax;                //mov [0x5276], ax
    _ax = memory16(_ds, 0x5274);                //mov ax, [0x5274]
    sub_2b67();                                 //call sub_2b67
    _ah = memory(_ds, 21106);                   //mov ah, byte ptr [0x5272]
    _al = memory(_ds, 0x5270);                  //mov al, [0x5270]
    sub_2a0d();                                 //call sub_2a0d
    _flags.carry = false;                       //clc
    goto loc_2947;                              //jmp loc_2947
loc_2946:                                       //loc_2946:
    _flags.carry = true;                        //stc
loc_2947:                                       //loc_2947:
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
}

void sub_294c()
{
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _al = memory(_ds, 0x508b);                  //mov al, [0x508b]
    _ah = _ah ^ _ah;                            //xor ah, ah
    _ax -= 0x000c;                              //sub ax, 0xc
    if (memory16(_ds, 21106) >= _ax)            //jnc loc_298e
        goto loc_298e;
    memory16(_ds, 21106) += 1;                  //inc word ptr [0x5272]
    _ax = memory16(_ds, 0x5276);                //mov ax, [0x5276]
    _ax += 1;                                   //inc ax
    if (_ax < 0x000c)                           //jc loc_2972
        goto loc_2972;
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_2972:                                       //loc_2972:
    _di = 0x1b80;                               //mov di, 0x1b80
    memory16(_ds, 0x5276) = _ax;                //mov [0x5276], ax
    _ax = memory16(_ds, 0x5274);                //mov ax, [0x5274]
    sub_2b67();                                 //call sub_2b67
    _ah = memory(_ds, 21106);                   //mov ah, byte ptr [0x5272]
    _al = memory(_ds, 0x5270);                  //mov al, [0x5270]
    _ax += 0x0b00;                              //add ax, 0xb00
    sub_2a0d();                                 //call sub_2a0d
    _flags.carry = false;                       //clc
    goto loc_298f;                              //jmp loc_298f
loc_298e:                                       //loc_298e:
    _flags.carry = true;                        //stc
loc_298f:                                       //loc_298f:
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
}

void sub_2994()
{
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _di = _di ^ _di;                            //xor di, di
    if (memory16(_ds, 21104) == 0x0000)         //jz loc_2a07
    {
//        _STOP_("goto loc_2a07");
        _flags.carry = true;                        //stc
        _di = _pop();                               //pop di
        _dx = _pop();                               //pop dx
        _cx = _pop();                               //pop cx
        _ax = _pop();                               //pop ax
        return;
    }
    memory16(_ds, 21104) -= 1;                  //dec word ptr [0x5270]
    _ax = memory16(_ds, 0x5274);                //mov ax, [0x5274]
    _ax -= 1;                                   //dec ax
    if ((short)_ax >= 0)                        //jns loc_29f2
        _STOP_("goto loc_29f2");
    _ax = 0x0013;                               //mov ax, 0x13
    _STOP_("goto loc_29f2");                    //jmp loc_29f2
}

void sub_29b5()
{
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _ax = memory16(_ds, 0x527c);                //mov ax, [0x527c]
    _sar(_ax, 1);                               //sar ax, 1
    _sar(_ax, 1);                               //sar ax, 1
    _sar(_ax, 1);                               //sar ax, 1
    _sar(_ax, 1);                               //sar ax, 1
    _ax -= 0x0014;                              //sub ax, 0x14
    if ((short)memory16(_ds, 32061) >= (short)_ax)//jge loc_29d7
        goto loc_29d7;
    _ax = 0x00ec;                               //mov ax, 0xec
    goto loc_29da;                              //jmp loc_29da
loc_29d7:                                       //loc_29d7:
    _ax = memory16(_ds, 0x7d3d);                //mov ax, [0x7d3d]
loc_29da:                                       //loc_29da:
    if (memory16(_ds, 21104) >= _ax)            //jnc loc_2a07
        goto loc_2a07;
    _di = 0x0013;                               //mov di, 0x13
    memory16(_ds, 21104) += 1;                  //inc word ptr [0x5270]
    _ax = memory16(_ds, 0x5274);                //mov ax, [0x5274]
    _ax += 1;                                   //inc ax
    if (_ax < 0x0014)                           //jc loc_29f2
        goto loc_29f2;
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_29f2:                                       //loc_29f2:
    memory16(_ds, 0x5274) = _ax;                //mov [0x5274], ax
    sub_2b67();                                 //call sub_2b67
    _ah = memory(_ds, 21106);                   //mov ah, byte ptr [0x5272]
    _al = memory(_ds, 0x5270);                  //mov al, [0x5270]
    _ax += _di;                                 //add ax, di
    sub_2ab1();                                 //call sub_2ab1
    _flags.carry = false;                       //clc
    goto loc_2a08;                              //jmp loc_2a08
loc_2a07:                                       //loc_2a07:
    _flags.carry = true;                        //stc
loc_2a08:                                       //loc_2a08:
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
}

void sub_2a0d()
{
    

    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    if (memory(_cs, 0x1) < 0x03)                //jc loc_2a6c
        goto loc_2a6c;
    sub_32f4();                                 //call sub_32f4
    _si = _ax;                                  //mov si, ax
    _di = _di + memory16(_ds, 21094);           //add di, word ptr [0x5266]
    _dx = memory16(_ds, 21108);                 //mov dx, word ptr [0x5274]
    _bx = 0x63e4;                               //mov bx, 0x63e4
    _ds = memory16(_ds, 21100);                 //mov ds, word ptr [0x526c]
    _cx = 0x0014;                               //mov cx, 0x14
loc_2a36:                                       //loc_2a36:
    if (_di < 0x5c80)                           //jc loc_2a40
        goto loc_2a40;
    _di -= 0x1e00;                              //sub di, 0x1e00
loc_2a40:                                       //loc_2a40:
    _lodsb<MemData, DirForward>();              //lodsb
    _ah = _al;                                  //mov ah, al
    _xlat();                                    //xlat
    memory(_es, 25845) |= _al;                  //or byte ptr es:[0x64f5], al
    _al = _ah;                                  //mov al, ah
    _push(_es);                                 //push es
    _bp = 0xa000;                               //mov bp, 0xa000
    _es = _bp;                                  //mov es, bp
    sub_2df5();                                 //call sub_2df5
    _es = _pop();                               //pop es
    _dx += 1;                                   //inc dx
    if (_dx < 0x0014)                           //jc loc_2a61
        goto loc_2a61;
    _di -= 0x0028;                              //sub di, 0x28
    _dx = _dx ^ _dx;                            //xor dx, dx
loc_2a61:                                       //loc_2a61:
    if (--_cx)                                  //loop loc_2a36
        goto loc_2a36;
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
    return;                                     //ret
loc_2a6c:                                       //loc_2a6c:
    _si = _ax;                                  //mov si, ax
    _di <<= 1;                                  //shl di, 1
    _di = _di + memory16(_ds, 21094);           //add di, word ptr [0x5266]
    _dx = memory16(_ds, 21108);                 //mov dx, word ptr [0x5274]
    _bx = 0x63e4;                               //mov bx, 0x63e4
    _ds = memory16(_ds, 21100);                 //mov ds, word ptr [0x526c]
    _cx = 0x0014;                               //mov cx, 0x14
loc_2a82:                                       //loc_2a82:
    if (_di < 0x3c00)                           //jc loc_2a8c
        goto loc_2a8c;
    _di -= 0x3c00;                              //sub di, 0x3c00
loc_2a8c:                                       //loc_2a8c:
    _lodsb<MemData, DirForward>();              //lodsb
    _ah = _al;                                  //mov ah, al
    _xlat();                                    //xlat
    memory(_es, 25845) |= _al;                  //or byte ptr es:[0x64f5], al
    _al = _ah;                                  //mov al, ah
    sub_2e53();                                 //call sub_2e53
    _dx += 1;                                   //inc dx
    if (_dx < 0x0014)                           //jc loc_2aa6
        goto loc_2aa6;
    _di -= 0x0050;                              //sub di, 0x50
    _dx = _dx ^ _dx;                            //xor dx, dx
loc_2aa6:                                       //loc_2aa6:
    if (--_cx)                                  //loop loc_2a82
        goto loc_2a82;
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
}

void sub_2ab1()
{
    

    if (memory(_cs, 0x1) < 0x03)                //jc loc_2b0d
        goto loc_2b0d;
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    sub_32f4();                                 //call sub_32f4
    _si = _ax;                                  //mov si, ax
    _ax = _di;                                  //mov ax, di
    _di <<= 1;                                  //shl di, 1
    _di = _di + memory16(_ds, 21094);           //add di, word ptr [0x5266]
    _ax = _ax + memory16(_ds, 21108);           //add ax, word ptr [0x5274]
    if (_ax < 0x0014)                           //jc loc_2ad6
        goto loc_2ad6;
    _di -= 0x0028;                              //sub di, 0x28
loc_2ad6:                                       //loc_2ad6:
    _ds = memory16(_ds, 21100);                 //mov ds, word ptr [0x526c]
    _cx = 0x000c;                               //mov cx, 0xc
    _bx = 0x63e4;                               //mov bx, 0x63e4
loc_2ae0:                                       //loc_2ae0:
    if (_di < 0x5c80)                           //jc loc_2aea
        goto loc_2aea;
    _di -= 0x1e00;                              //sub di, 0x1e00
loc_2aea:                                       //loc_2aea:
    _lodsb<MemData, DirForward>();              //lodsb
    _ah = _al;                                  //mov ah, al
    _xlat();                                    //xlat
    memory(_es, 25845) |= _al;                  //or byte ptr es:[0x64f5], al
    _al = _ah;                                  //mov al, ah
    _push(_es);                                 //push es
    _dx = 0xa000;                               //mov dx, 0xa000
    _es = _dx;                                  //mov es, dx
    sub_2df5();                                 //call sub_2df5
    _es = _pop();                               //pop es
    _si += 0x00ff;                              //add si, 0xff
    _di += 0x027e;                              //add di, 0x27e
    if (--_cx)                                  //loop loc_2ae0
        goto loc_2ae0;
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    return;                                     //ret
loc_2b0d:                                       //loc_2b0d:
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    _si = _ax;                                  //mov si, ax
    _ax = _di;                                  //mov ax, di
    _di <<= 1;                                  //shl di, 1
    _di <<= 1;                                  //shl di, 1
    _di = _di + memory16(_ds, 21094);           //add di, word ptr [0x5266]
    _ax = _ax + memory16(_ds, 21108);           //add ax, word ptr [0x5274]
    if (_ax < 0x0014)                           //jc loc_2b30
        goto loc_2b30;
    _di -= 0x0050;                              //sub di, 0x50
loc_2b30:                                       //loc_2b30:
    _ds = memory16(_ds, 21100);                 //mov ds, word ptr [0x526c]
    _cx = 0x000c;                               //mov cx, 0xc
    _bx = 0x63e4;                               //mov bx, 0x63e4
loc_2b3a:                                       //loc_2b3a:
    if (_di < 0x3c00)                           //jc loc_2b44
        goto loc_2b44;
    _di -= 0x3c00;                              //sub di, 0x3c00
loc_2b44:                                       //loc_2b44:
    _lodsb<MemData, DirForward>();              //lodsb
    _ah = _al;                                  //mov ah, al
    _xlat();                                    //xlat
    memory(_es, 25845) |= _al;                  //or byte ptr es:[0x64f5], al
    _al = _ah;                                  //mov al, ah
    sub_2e53();                                 //call sub_2e53
    _si += 0x00ff;                              //add si, 0xff
    _di += 0x04fc;                              //add di, 0x4fc
    if (--_cx)                                  //loop loc_2b3a
        goto loc_2b3a;
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_2b67()
{
    

    if (memory(_cs, 0x1) < 0x03)                //jc loc_2b88
        goto loc_2b88;
    _ax <<= 1;                                  //shl ax, 1
    _dh = memory(_ds, 21110);                   //mov dh, byte ptr [0x5276]
    _dl = _dl ^ _dl;                            //xor dl, dl
    _bx = _dx;                                  //mov bx, dx
    _bx <<= 1;                                  //shl bx, 1
    _dx >>= 1;                                  //shr dx, 1
    _ax += _dx;                                 //add ax, dx
    _ax += _bx;                                 //add ax, bx
    _ax += 0x3e80;                              //add ax, 0x3e80
    memory16(_ds, 0x5266) = _ax;                //mov [0x5266], ax
    return;                                     //ret
loc_2b88:                                       //loc_2b88:
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _push(_ax);                                 //push ax
    _ax = 0x0500;                               //mov ax, 0x500
    _dl = memory(_ds, 21110);                   //mov dl, byte ptr [0x5276]
    _dh = _dh ^ _dh;                            //xor dh, dh
    _mul(_dx);                                  //mul dx
    _dx = _pop();                               //pop dx
    _ax += _dx;                                 //add ax, dx
    memory16(_ds, 0x5266) = _ax;                //mov [0x5266], ax
    return;                                     //ret
loc_2b9f:                                       //loc_2b9f:
    _STOP_("goto loc_2c7d");                    //jmp loc_2c7d
}

void sub_2ba2()
{
    

    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _es = memory16(_ds, 21100);                 //mov es, word ptr [0x526c]
    sub_32f4();                                 //call sub_32f4
    if (memory(_ds, 25845) == 0x00)             //jz loc_2b9f
    {
        //_STOP_("goto loc_2b9f");
        _bp = _pop();                               //pop bp
        _es = _pop();                               //pop es
        _ds = _pop();                               //pop ds
        _si = _pop();                               //pop si
        _di = _pop();                               //pop di
        _dx = _pop();                               //pop dx
        _cx = _pop();                               //pop cx
        _bx = _pop();                               //pop bx
        _ax = _pop();                               //pop ax
        return;
    }
    if (memory(_ds, 25852) & 0x03)              //jnz loc_2b9f
    {
        //_STOP_("goto loc_2b9f");
        _bp = _pop();                               //pop bp
        _es = _pop();                               //pop es
        _ds = _pop();                               //pop ds
        _si = _pop();                               //pop si
        _di = _pop();                               //pop di
        _dx = _pop();                               //pop dx
        _cx = _pop();                               //pop cx
        _bx = _pop();                               //pop bx
        _ax = _pop();                               //pop ax
        return;
    }
    memory(_ds, 25845) = 0x00;                  //mov byte ptr [0x64f5], 0x0
    _ah = memory(_ds, 21106);                   //mov ah, byte ptr [0x5272]
    _al = memory(_ds, 0x5270);                  //mov al, [0x5270]
    _si = _ax;                                  //mov si, ax
    _ch = 0x0c;                                 //mov ch, 0xc
    _bh = _bh ^ _bh;                            //xor bh, bh
    _di = memory16(_ds, 21094);                 //mov di, word ptr [0x5266]
    if (memory(_cs, 0x1) >= 0x03)               //jnc loc_2c32
        goto loc_2c32;
loc_2be3:                                       //loc_2be3:
    _dx = memory16(_ds, 21108);                 //mov dx, word ptr [0x5274]
    _cl = 0x14;                                 //mov cl, 0x14
loc_2be9:                                       //loc_2be9:
    _bl = memory(_es, _si);                     //mov bl, byte ptr es:[si]
    if (memory(_ds, _bx + 25572) == 0x00)       //jz loc_2c11
        goto loc_2c11;
    memory(_ds, 25845) = 0x01;                  //mov byte ptr [0x64f5], 0x1
    _al = _bl;                                  //mov al, bl
    _bx = memory16(_ds, 25846);                 //mov bx, word ptr [0x64f6]
    _xlat();                                    //xlat
    _bh = _bh ^ _bh;                            //xor bh, bh
    if (_di < 0x3c00)                           //jc loc_2c0b
        goto loc_2c0b;
    _di -= 0x3c00;                              //sub di, 0x3c00
loc_2c0b:                                       //loc_2c0b:
    sub_2e53();                                 //call sub_2e53
    _di -= 0x0004;                              //sub di, 0x4
loc_2c11:                                       //loc_2c11:
    _dx += 1;                                   //inc dx
    if (_dx < 0x0014)                           //jc loc_2c1c
        goto loc_2c1c;
    _di -= 0x0050;                              //sub di, 0x50
    _dx = _dx ^ _dx;                            //xor dx, dx
loc_2c1c:                                       //loc_2c1c:
    _di += 0x0004;                              //add di, 0x4
    _si += 1;                                   //inc si
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_2be9
        goto loc_2be9;
    _di += 0x0500;                              //add di, 0x500
    _si += 0x00ec;                              //add si, 0xec
    _ch -= 1;                                   //dec ch
    if (_ch != 0)                               //jnz loc_2be3
        goto loc_2be3;
    goto loc_2c7d;                              //jmp loc_2c7d
loc_2c32:                                       //loc_2c32:
    _dx = memory16(_ds, 21108);                 //mov dx, word ptr [0x5274]
    _cl = 0x14;                                 //mov cl, 0x14
loc_2c38:                                       //loc_2c38:
    _bl = memory(_es, _si);                     //mov bl, byte ptr es:[si]
    if (memory(_ds, _bx + 25572) == 0x00)       //jz loc_2c5f
        goto loc_2c5f;
    memory(_ds, 25845) = 0x01;                  //mov byte ptr [0x64f5], 0x1
    _al = _bl;                                  //mov al, bl
    _bx = memory16(_ds, 25846);                 //mov bx, word ptr [0x64f6]
    _xlat();                                    //xlat
    _bh = _bh ^ _bh;                            //xor bh, bh
    if (_di < 0x5c80)                           //jc loc_2c5a
        goto loc_2c5a;
    _di -= 0x1e00;                              //sub di, 0x1e00
loc_2c5a:                                       //loc_2c5a:
    sub_2de8();                                 //call sub_2de8
    _di -= 1;                                   //dec di
    _di -= 1;                                   //dec di
loc_2c5f:                                       //loc_2c5f:
    _dx += 1;                                   //inc dx
    if (_dx < 0x0014)                           //jc loc_2c6a
        goto loc_2c6a;
    _di -= 0x0028;                              //sub di, 0x28
    _dx = _dx ^ _dx;                            //xor dx, dx
loc_2c6a:                                       //loc_2c6a:
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _si += 1;                                   //inc si
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_2c38
        goto loc_2c38;
    _di += 0x0280;                              //add di, 0x280
    _si += 0x00ec;                              //add si, 0xec
    _ch -= 1;                                   //dec ch
    if (_ch != 0)                               //jnz loc_2c32
        goto loc_2c32;
loc_2c7d:                                       //loc_2c7d:
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_2c87()
{
    

    if (memory(_cs, 0x1) < 0x03)                //jc loc_2cfb
        goto loc_2cfb;
    _push(_bx);                                 //push bx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    sub_32f4();                                 //call sub_32f4
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _si = memory16(_ds, 21094);                 //mov si, word ptr [0x5266]
    _di = memory16(_ds, 21098);                 //mov di, word ptr [0x526a]
    _dl = 0x14;                                 //mov dl, 0x14
    _dh = memory(_ds, 21108);                   //mov dh, byte ptr [0x5274]
    _dl -= _dh;                                 //sub dl, dh
    _dl <<= 1;                                  //shl dl, 1
    _dh <<= 1;                                  //shl dh, 1
    _bp = 0x000c;                               //mov bp, 0xc
    _bp = _bp - memory16(_ds, 21110);           //sub bp, word ptr [0x5276]
    _cl = 0x04;                                 //mov cl, 0x4
    _bp <<= _cl;                                //shl bp, cl
    _ax = 0xa000;                               //mov ax, 0xa000
    _es = _ax;                                  //mov es, ax
    _ds = _ax;                                  //mov ds, ax
    _ch = _ch ^ _ch;                            //xor ch, ch
    _ax = 0x0028;                               //mov ax, 0x28
    _bx = 0x00c0;                               //mov bx, 0xc0
    _bx -= _bp;                                 //sub bx, bp
loc_2ccc:                                       //loc_2ccc:
    _cl = _dl;                                  //mov cl, dl
    _rep_movsb<MemVideo, MemVideo, DirForward>(); //rep movsb
    _si -= _ax;                                 //sub si, ax
    _cl = _dh;                                  //mov cl, dh
    _rep_movsb<MemVideo, MemVideo, DirForward>(); //rep movsb
    _si += _ax;                                 //add si, ax
    _bp -= 1;                                   //dec bp
    if (_bp != 0)                               //jnz loc_2ccc
        goto loc_2ccc;
    _bx |= _bx;                                 //or bx, bx
    if (_bx == 0)                               //jz loc_2cf5
        goto loc_2cf5;
    _si = 0x3e80;                               //mov si, 0x3e80
    _cl = _dh;                                  //mov cl, dh
    _si += _cx;                                 //add si, cx
loc_2ce6:                                       //loc_2ce6:
    _cl = _dl;                                  //mov cl, dl
    _rep_movsb<MemVideo, MemVideo, DirForward>(); //rep movsb
    _si -= _ax;                                 //sub si, ax
    _cl = _dh;                                  //mov cl, dh
    _rep_movsb<MemVideo, MemVideo, DirForward>(); //rep movsb
    _si += _ax;                                 //add si, ax
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz loc_2ce6
        goto loc_2ce6;
loc_2cf5:                                       //loc_2cf5:
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _bx = _pop();                               //pop bx
    return;                                     //ret
loc_2cfb:                                       //loc_2cfb:
    _push(_bx);                                 //push bx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _si = memory16(_ds, 21094);                 //mov si, word ptr [0x5266]
    _di = _di ^ _di;                            //xor di, di
    _dl = 0x14;                                 //mov dl, 0x14
    _dh = memory(_ds, 21108);                   //mov dh, byte ptr [0x5274]
    _dl -= _dh;                                 //sub dl, dh
    _dl <<= 1;                                  //shl dl, 1
    _dh <<= 1;                                  //shl dh, 1
    _bp = 0x000c;                               //mov bp, 0xc
    _bp = _bp - memory16(_ds, 21110);           //sub bp, word ptr [0x5276]
    _cl = 0x04;                                 //mov cl, 0x4
    _bp <<= _cl;                                //shl bp, cl
    _es = memory16(_ds, 21090);                 //mov es, word ptr [0x5262]
    _ds = memory16(_ds, 21092);                 //mov ds, word ptr [0x5264]
    _ch = _ch ^ _ch;                            //xor ch, ch
    _ax = 0x0050;                               //mov ax, 0x50
    _bx = 0x00c0;                               //mov bx, 0xc0
    _bx -= _bp;                                 //sub bx, bp
loc_2d34:                                       //loc_2d34:
    _cl = _dl;                                  //mov cl, dl
    _rep_movsw<MemVideo, MemVideo, DirForward>(); //rep movsw
    _si -= _ax;                                 //sub si, ax
    _cl = _dh;                                  //mov cl, dh
    _rep_movsw<MemVideo, MemVideo, DirForward>(); //rep movsw
    _si += _ax;                                 //add si, ax
    _bp -= 1;                                   //dec bp
    if (_bp != 0)                               //jnz loc_2d34
        goto loc_2d34;
    _bx |= _bx;                                 //or bx, bx
    if (_bx == 0)                               //jz loc_2d5c
        goto loc_2d5c;
    _cl = _dh;                                  //mov cl, dh
    _si = _cx;                                  //mov si, cx
    _si += _cx;                                 //add si, cx
loc_2d4d:                                       //loc_2d4d:
    _cl = _dl;                                  //mov cl, dl
    _rep_movsw<MemVideo, MemVideo, DirForward>(); //rep movsw
    _si -= _ax;                                 //sub si, ax
    _cl = _dh;                                  //mov cl, dh
    _rep_movsw<MemVideo, MemVideo, DirForward>(); //rep movsw
    _si += _ax;                                 //add si, ax
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz loc_2d4d
        goto loc_2d4d;
loc_2d5c:                                       //loc_2d5c:
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _bx = _pop();                               //pop bx
}

void sub_2d62()
{
    

    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    sub_2811();                                 //call sub_2811
    memory16(_ds, 0x5270) = _ax;                //mov [0x5270], ax
    memory16(_ds, 0x5272) = _ax;                //mov [0x5272], ax
    memory16(_ds, 0x5274) = _ax;                //mov [0x5274], ax
    memory16(_ds, 0x5276) = _ax;                //mov [0x5276], ax
    sub_2b67();                                 //call sub_2b67
    _di = memory16(_ds, 21094);                 //mov di, word ptr [0x5266]
    _es = memory16(_ds, 21100);                 //mov es, word ptr [0x526c]
    _si = _si ^ _si;                            //xor si, si
    if (memory(_cs, 0x1) < 0x03)                //jc loc_2daf
        goto loc_2daf;
    sub_32f4();                                 //call sub_32f4
    _ch = 0x0c;                                 //mov ch, 0xc
loc_2d94:                                       //loc_2d94:
    _cl = 0x14;                                 //mov cl, 0x14
loc_2d96:                                       //loc_2d96:
    _al = memory(_es, _si);                     //mov al, byte ptr es:[si]
    sub_2de8();                                 //call sub_2de8
    _si += 1;                                   //inc si
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_2d96
        goto loc_2d96;
    _si += 0x00ec;                              //add si, 0xec
    _di += 0x0258;                              //add di, 0x258
    _ch -= 1;                                   //dec ch
    if (_ch != 0)                               //jnz loc_2d94
        goto loc_2d94;
    goto loc_2dca;                              //jmp loc_2dca
loc_2daf:                                       //loc_2daf:
    _ch = 0x0c;                                 //mov ch, 0xc
loc_2db1:                                       //loc_2db1:
    _cl = 0x14;                                 //mov cl, 0x14
loc_2db3:                                       //loc_2db3:
    _al = memory(_es, _si);                     //mov al, byte ptr es:[si]
    sub_2e53();                                 //call sub_2e53
    _si += 1;                                   //inc si
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_2db3
        goto loc_2db3;
    _si += 0x00ec;                              //add si, 0xec
    _di += 0x04b0;                              //add di, 0x4b0
    _ch -= 1;                                   //dec ch
    if (_ch != 0)                               //jnz loc_2db1
        goto loc_2db1;
loc_2dca:                                       //loc_2dca:
    sub_3f46();                                 //call sub_3f46
    _al = memory(_ds, 0x6521);                  //mov al, [0x6521]
    _al = _al | memory(_ds, 25888);             //or al, byte ptr [0x6520]
    if (_al != 0)                               //jnz loc_2dca
        goto loc_2dca;
    sub_276f();                                 //call sub_276f
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    return;                                     //ret
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 6fh");                           //db 6fh
    _STOP_("db 81h");                           //db 81h
    _STOP_("db c7h");                           //db c7h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("sp-trace-fail");                    //sub_2d62 endp_failed
    _STOP_("continues");                        //sub_2de8 proc near
}

void sub_2de8()
{
    _push(_dx);                                 //push dx
    _push(_es);                                 //push es
    _dx = 0xa000;                               //mov dx, 0xa000
    _es = _dx;                                  //mov es, dx
    sub_2df5();                                 //call sub_2df5
    _es = _pop();                               //pop es
    _dx = _pop();                               //pop dx
}

void sub_2df5()
{
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _ah = _ah ^ _ah;                            //xor ah, ah
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _si = _ax;                                  //mov si, ax
    _si += 0x5dc0;                              //add si, 0x5dc0
    _push(_es);                                 //push es
    _ds = _pop();                               //pop ds
    _bp = 0x0026;                               //mov bp, 0x26
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bp;                                 //add di, bp
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bp;                                 //add di, bp
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bp;                                 //add di, bp
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bp;                                 //add di, bp
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bp;                                 //add di, bp
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bp;                                 //add di, bp
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bp;                                 //add di, bp
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bp;                                 //add di, bp
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bp;                                 //add di, bp
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bp;                                 //add di, bp
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bp;                                 //add di, bp
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bp;                                 //add di, bp
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bp;                                 //add di, bp
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bp;                                 //add di, bp
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di += _bp;                                 //add di, bp
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _movsb<MemVideo, MemVideo, DirForward>();     //movsb
    _di -= 0x0258;                              //sub di, 0x258
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
}

void sub_2e53()
{
    

    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_bp);                                 //push bp
    _push(_es);                                 //push es
    _ah = _al;                                  //mov ah, al
    _al = _al ^ _al;                            //xor al, al
    _ax >>= 1;                                  //shr ax, 1
    _si = _ax;                                  //mov si, ax
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _es = memory16(_ds, 21092);                 //mov es, word ptr [0x5264]
    _ds = memory16(_cs, 0xB95E);                //mov ds, word ptr cs:[0xb95e]
    _bp = 0x004c;                               //mov bp, 0x4c
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di += _bp;                                 //add di, bp
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di += _bp;                                 //add di, bp
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di += _bp;                                 //add di, bp
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di += _bp;                                 //add di, bp
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di += _bp;                                 //add di, bp
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di += _bp;                                 //add di, bp
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di += _bp;                                 //add di, bp
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di += _bp;                                 //add di, bp
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di += _bp;                                 //add di, bp
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di += _bp;                                 //add di, bp
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di += _bp;                                 //add di, bp
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di += _bp;                                 //add di, bp
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di += _bp;                                 //add di, bp
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di += _bp;                                 //add di, bp
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di += _bp;                                 //add di, bp
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    _di -= 0x04b0;                              //sub di, 0x4b0
    _es = _pop();                               //pop es
    _bp = _pop();                               //pop bp
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
}

void sub_2eb7()
{
    _push(_ds);                                 //push ds
    _dx = reloc(0x168f);                               //mov dx, reloc(0x168f)
    _ds = _dx;                                  //mov ds, dx
    _es = _dx;                                  //mov es, dx
    memory(_ds, 0x5250) = _al;                  //mov [0x5250], al
    _al += 0x30;                                //add al, 0x30
    if (_al <= 0x39)                            //jbe loc_2eca
        goto loc_2eca;
    _al += 0x07;                                //add al, 0x7
loc_2eca:                                       //loc_2eca:
    memory(_ds, 0x5256) = _al;                  //mov [0x5256], al
    _di = 0x72a3;                               //mov di, 0x72a3
    _cx = 0x0bf4;                               //mov cx, 0xbf4
    _al = 0xff;                                 //mov al, 0xff
    _rep_stosb<MemData, DirForward>();          //rep stosb
    _di = 0x527c;                               //mov di, 0x527c
    _cx = 0x020a;                               //mov cx, 0x20a
    _rep_stosw<MemData, DirForward>();          //rep stosw
    sub_32dc();                                 //call sub_32dc
    _dx = 0x5251;                               //mov dx, 0x5251
    sub_097b();                                 //call sub_097b
    memory16(_ds, 0x526c) = _ax;                //mov [0x526c], ax
    _push(_ax);                                 //push ax
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _al = memory(_ds, 0x5250);                  //mov al, [0x5250]
    _ah = 0x03;                                 //mov ah, 0x3
    _mul(_ah);                                  //mul ah
    _si = _ax;                                  //mov si, ax
    _si += 0x50c8;                              //add si, 0x50c8
    _di = 0x5081;                               //mov di, 0x5081
    _cx = 0x0003;                               //mov cx, 0x3
    _rep_movsb<MemData, MemData, DirForward>(); //rep movsb
    _dx = 0x5057;                               //mov dx, 0x5057
    sub_0410();                                 //call sub_0410
    _ax = _pop();                               //pop ax
    sub_3009();                                 //call sub_3009
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _es = _ax;                                  //mov es, ax
    _di = 0x72a3;                               //mov di, 0x72a3
    _cx = 0x0180;                               //mov cx, 0x180
    _rep_movsw<MemData, MemData, DirForward>(); //rep movsw
    _cx = 0x00f0;                               //mov cx, 0xf0
    _rep_movsb<MemData, MemData, DirForward>(); //rep movsb
    _cl = 0x03;                                 //mov cl, 0x3
    _rep_movsw<MemData, MemData, DirForward>(); //rep movsw
    _cx = 0x0514;                               //mov cx, 0x514
    _rep_movsb<MemData, MemData, DirForward>(); //rep movsb
    _cx = 0x0190;                               //mov cx, 0x190
    _rep_movsb<MemData, MemData, DirForward>(); //rep movsb
    _movsw<MemData, MemData, DirForward>();     //movsw
    _cx = 0x008c;                               //mov cx, 0x8c
    _rep_movsb<MemData, MemData, DirForward>(); //rep movsb
    _cx = 0x00c8;                               //mov cx, 0xc8
    _rep_movsb<MemData, MemData, DirForward>(); //rep movsb
    _movsw<MemData, MemData, DirForward>();     //movsw
    _movsw<MemData, MemData, DirForward>();     //movsw
    sub_2f76();                                 //call sub_2f76
    sub_2fdd();                                 //call sub_2fdd
    _ax = memory16(_ds, 0x7695);                //mov ax, [0x7695]
    memory16(_ds, 0x64e4) = _ax;                //mov [0x64e4], ax
    _ax = memory16(_ds, 0x7697);                //mov ax, [0x7697]
    memory16(_ds, 0x64e6) = _ax;                //mov [0x64e6], ax
    _si = 0x7dcb;                               //mov si, 0x7dcb
    _cx = 0x000a;                               //mov cx, 0xa
loc_2f57:                                       //loc_2f57:
    if (memory(_es, _si + 7) < 0x08)            //jc loc_2f64
        goto loc_2f64;
    memory16(_es, _si + 4) = 0xffff;            //mov word ptr es:[si+0x4], 0xffff
loc_2f64:                                       //loc_2f64:
    _si += 0x0014;                              //add si, 0x14
    if (--_cx)                                  //loop loc_2f57
        goto loc_2f57;
    _si = 0x75a3;                               //mov si, 0x75a3
    _di = 0x7e97;                               //mov di, 0x7e97
    _cx = 0x08f4;                               //mov cx, 0x8f4
    _rep_movsb<MemData, MemData, DirForward>(); //rep movsb
    _ds = _pop();                               //pop ds
}

void sub_2f76()
{
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _bx = _bx ^ _bx;                            //xor bx, bx
    _cx = 0x0100;                               //mov cx, 0x100
    _dl = _dl ^ _dl;                            //xor dl, dl
loc_2f82:                                       //loc_2f82:
    if (memory(_ds, _bx + 29859) & 0x80)        //jnz loc_2f9c
        goto loc_2f9c;
    memory(_ds, _bx + 24804) = _bl;             //mov byte ptr [bx+0x60e4], bl
    memory(_ds, _bx + 25060) = _bl;             //mov byte ptr [bx+0x61e4], bl
    memory(_ds, _bx + 25316) = _bl;             //mov byte ptr [bx+0x62e4], bl
    memory(_ds, _bx + 25572) = 0x00;            //mov byte ptr [bx+0x63e4], 0x0
    goto loc_2fd3;                              //jmp loc_2fd3
loc_2f9c:                                       //loc_2f9c:
    _dl = 0x01;                                 //mov dl, 0x1
    _al = _bl;                                  //mov al, bl
    memory(_ds, _bx + 24804) = _al;             //mov byte ptr [bx+0x60e4], al
    memory(_ds, _bx + 25062) = _al;             //mov byte ptr [bx+0x61e6], al
    memory(_ds, _bx + 25317) = _al;             //mov byte ptr [bx+0x62e5], al
    _ax += 1;                                   //inc ax
    memory(_ds, _bx + 24805) = _al;             //mov byte ptr [bx+0x60e5], al
    memory(_ds, _bx + 25060) = _al;             //mov byte ptr [bx+0x61e4], al
    memory(_ds, _bx + 25318) = _al;             //mov byte ptr [bx+0x62e6], al
    _ax += 1;                                   //inc ax
    memory(_ds, _bx + 24806) = _al;             //mov byte ptr [bx+0x60e6], al
    memory(_ds, _bx + 25061) = _al;             //mov byte ptr [bx+0x61e5], al
    memory(_ds, _bx + 25316) = _al;             //mov byte ptr [bx+0x62e4], al
    memory(_ds, _bx + 25572) = 0x01;            //mov byte ptr [bx+0x63e4], 0x1
    memory16(_ds, _bx + 25573) = 0x0101;        //mov word ptr [bx+0x63e5], 0x101
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
loc_2fd3:                                       //loc_2fd3:
    _bx += 1;                                   //inc bx
    _bh |= _bh;                                 //or bh, bh
    if (_bh == 0)                               //jz loc_2f82
        goto loc_2f82;
    memory(_ds, 25845) = _dl;                   //mov byte ptr [0x64f5], dl
}

void sub_2fdd()
{
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _es = memory16(_ds, 21100);                 //mov es, word ptr [0x526c]
    _si = 0x7bad;                               //mov si, 0x7bad
    _cx = 0x0064;                               //mov cx, 0x64
loc_2ff2:                                       //loc_2ff2:
    _di = memory16(_ds, _si + 2);               //mov di, word ptr [si+0x2]
    if (_di == 0xffff)                      //jz loc_2ffd
        goto loc_2ffd;
    _al = memory(_ds, _si);                     //mov al, byte ptr [si]
    _stosb<MemData, DirForward>();              //stosb
loc_2ffd:                                       //loc_2ffd:
    _si += 0x0004;                              //add si, 0x4
    if (--_cx)                                  //loop loc_2ff2
        goto loc_2ff2;
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
}

void sub_3009()
{
    

    _bl = memory(_ds, 21072);                   //mov bl, byte ptr [0x5250]
    _bh = memory(_ds, _bx + 20640);             //mov bh, byte ptr [bx+0x50a0]
    memory(_ds, 20619) = _bh;                   //mov byte ptr [0x508b], bh
    if (memory(_cs, 0x1) >= 0x03)               //jnc loc_3044
        goto loc_3044;
    _bl = _bl ^ _bl;                            //xor bl, bl
    _cl = 0x04;                                 //mov cl, 0x4
    _bx >>= _cl;                                //shr bx, cl
    _ax += _bx;                                 //add ax, bx
    _ds = _ax;                                  //mov ds, ax
    _si = _si ^ _si;                            //xor si, si
    memory16(_cs, 0xB95E) = _ax;                //mov cs:[0xb95e], ax
    memory16(_cs, 0x6676) = 0x66b8;             //mov word ptr cs:[0x6676], 0x66b8
    _cx = 0x0100;                               //mov cx, 0x100
loc_3037:                                       //loc_3037:
    _ax = 0x0210;                               //mov ax, 0x210
    sub_65be();                                 //call sub_65be
    _si += 0x0080;                              //add si, 0x80
    if (--_cx)                                  //loop loc_3037
        goto loc_3037;
    return;                                     //ret
loc_3044:                                       //loc_3044:
    _bl = _bl ^ _bl;                            //xor bl, bl
    _cl = 0x04;                                 //mov cl, 0x4
    _bx >>= _cl;                                //shr bx, cl
    _ax += _bx;                                 //add ax, bx
    memory16(_ds, 0x04c1) = _ax;                //mov [0x4c1], ax
    _ds = _ax;                                  //mov ds, ax
    _si = _si ^ _si;                            //xor si, si
    _ax = 0xa000;                               //mov ax, 0xa000
    _es = _ax;                                  //mov es, ax
    _di = 0x5dc0;                               //mov di, 0x5dc0
    _dx = 0x03c4;                               //mov dx, 0x3c4
    _al = 0x02;                                 //mov al, 0x2
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _bx = 0x0100;                               //mov bx, 0x100
loc_3065:                                       //loc_3065:
    _al = 0x01;                                 //mov al, 0x1
loc_3067:                                       //loc_3067:
    _out(_dx, _al);                             //out dx, al
    _cx = 0x0010;                               //mov cx, 0x10
    _rep_movsw<MemVideo, MemData, DirForward>(); //rep movsw
    _di -= 0x0020;                              //sub di, 0x20
    _al <<= 1;                                  //shl al, 1
    if (_al < 0x10)                             //jc loc_3067
        goto loc_3067;
    _di += 0x0020;                              //add di, 0x20
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz loc_3065
        goto loc_3065;
}

void sub_307d()
{
    

    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    if (memory(_cs, 0x1) == 0xff)               //jz loc_308d
        goto loc_308d;
    {sub_3160(); return; };                     //
loc_308d:                                       //loc_308d:
    _ax = 0x000d;                               //mov ax, 0xd
    _interrupt(16);                             //int 0x10
    _dx = 0x03c8;                               //mov dx, 0x3c8
    _al = 0x40;                                 //mov al, 0x40
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _cx = 0x001e;                               //mov cx, 0x1e
    _si = 0x5057;                               //mov si, 0x5057
loc_309f:                                       //loc_309f:
    _lodsb<MemData, DirForward>();              //lodsb
    _al &= 0x3f;                                //and al, 0x3f
    _out(_dx, _al);                             //out dx, al
    if (--_cx)                                  //loop loc_309f
        goto loc_309f;
    _cx = 0x001e;                               //mov cx, 0x1e
    _si -= _cx;                                 //sub si, cx
    _al = 0x40;                                 //mov al, 0x40
    _dl = 0xc7;                                 //mov dl, 0xc7
    _out(_dx, _al);                             //out dx, al
    _dl = 0xc9;                                 //mov dl, 0xc9
loc_30b1:                                       //loc_30b1:
    _ah = memory(_ds, _si);                     //mov ah, byte ptr [si]
    _si += 1;                                   //inc si
    _ah &= 0x3f;                                //and ah, 0x3f
    _in(_al, _dx);                              //in al, dx
    //gabo //if (_al != _ah)                             //jnz loc_30ca
        //goto loc_30ca;
    if (--_cx)                                  //loop loc_30b1
        goto loc_30b1;
    sub_3126();                                 //call sub_3126
    if (_flags.carry)                           //jc loc_30e6
        goto loc_30e6;
    memory(_cs, 0x1) = 0x05;                    //mov byte ptr cs:[0x1], 0x5
    return;                                     //ret
loc_30ca:                                       //loc_30ca:
    sub_3126();                                 //call sub_3126
    if (_flags.carry)                           //jc loc_30e6
        goto loc_30e6;
    memory(_cs, 0x1) = 0x04;                    //mov byte ptr cs:[0x1], 0x4
    _ah = 0x12;                                 //mov ah, 0x12
    _bl = 0x10;                                 //mov bl, 0x10
    _interrupt(16);                             //int 0x10
    _bl |= _bl;                                 //or bl, bl
    if (_bl != 0)                               //jnz loc_3125
        goto loc_3125;
    memory(_cs, 0x1) = 0x03;                    //mov byte ptr cs:[0x1], 0x3
    return;                                     //ret
loc_30e6:                                       //loc_30e6:
    _ax = 0x0003;                               //mov ax, 0x3
    _interrupt(16);                             //int 0x10
    _ah = 0x0f;                                 //mov ah, 0xf
    _interrupt(16);                             //int 0x10
    if (_ax == 0x5003)                          //jz loc_30fb
        goto loc_30fb;
    memory(_cs, 0x1) = 0x00;                    //mov byte ptr cs:[0x1], 0x0
    return;                                     //ret
loc_30fb:                                       //loc_30fb:
    memory(_cs, 0x1) = 0x02;                    //mov byte ptr cs:[0x1], 0x2
    _ax = 0x0009;                               //mov ax, 0x9
    _interrupt(16);                             //int 0x10
    _ax = 0xb800;                               //mov ax, 0xb800
    _es = _ax;                                  //mov es, ax
    memory(_es, 16384) = 0xff;                  //mov byte ptr es:[0x4000], 0xff
    _al = memory(_es, 16384);                   //mov al, es:[0x4000]
    _ah = memory(_es, 0);                       //mov ah, byte ptr es:[0x0]
    if (_ax == 0x00ff)                          //jz loc_3125
        goto loc_3125;
    memory(_cs, 0x1) = 0x01;                    //mov byte ptr cs:[0x1], 0x1
loc_3125:                                       //loc_3125:
    return;
}

void sub_3126()
{
    _ax = 0x000d;                               //mov ax, 0xd
    _interrupt(16);                             //int 0x10
    _ax = 0xa000;                               //mov ax, 0xa000
    _es = _ax;                                  //mov es, ax
    _dx = 0x03c4;                               //mov dx, 0x3c4
    _ax = 0x0102;                               //mov ax, 0x102
    _out(_dx, _ax);                             //out dx, ax
    _dl = 0xce;                                 //mov dl, 0xce
    _ax = 0x0005;                               //mov ax, 0x5
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0004;                               //mov ax, 0x4
    _out(_dx, _ax);                             //out dx, ax
    _al = 0x51;                                 //mov al, 0x51
    memoryVideoSet(_es, 8192, _al);                    //mov es:[0x2000], al
    if (memoryVideoGet(_es, 8192) != _al)               //jnz loc_315e
        goto loc_315e;
    _ax = 0x0103;                               //mov ax, 0x103
    _out(_dx, _ax);                             //out dx, ax
    memoryVideoSet(_es, _si, 0xaa);                    //mov byte ptr es:[si], 0xaa
    //gabo //if (memoryVideoGet(_es, _si) != 0x55)               //jnz loc_315e
    //    goto loc_315e;
    _flags.carry = false;                       //clc
    return;                                     //ret
loc_315e:                                       //loc_315e:
    _flags.carry = true;                        //stc
}

void sub_3160()
{
    

    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    
    _al = memory(_cs, 0x1);                     //mov al, cs:[0x1]
    if (_al == 0x01)                            //jz loc_31c5
        goto loc_31c5;  // -- CGA
    if (_al == 0x02)                            //jz loc_31c5
        goto loc_31c5;  // -- CGA
    if (_al == 0x00)                            //jz loc_31e9
        goto loc_31e9;  // -- HERCULES
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _ax = 0x000d;                               //mov ax, 0xd
    _interrupt(16);                             //int 0x10
    _dx = 0x03d4;                               //mov dx, 0x3d4
    _ax = 0x2411;                               //mov ax, 0x2411
    _out(_dx, _ax);                             //out dx, ax
    memory16(_ds, 21096) = 0x0000;              //mov word ptr [0x5268], 0x0
    memory16(_ds, 21098) = 0x1f40;              //mov word ptr [0x526a], 0x1f40
    _al = memory(_cs, 0x1);                     //mov al, cs:[0x1]
    if (_al == 0x05)                            //jz loc_31a4
        goto loc_31a4;
    if (_al >= 0x03)                            //jnc loc_31bb
        goto loc_31bb;
loc_31a4:                                       //loc_31a4:
    _dx = 0x5046;                               //mov dx, 0x5046
    _ax = 0x1002;                               //mov ax, 0x1002
    _interrupt(16);                             //int 0x10
    _ax = 0x1012;                               //mov ax, 0x1012
    _bx = _bx ^ _bx;                            //xor bx, bx
    _cx = 0x0010;                               //mov cx, 0x10
    _dx = 0x5057;                               //mov dx, 0x5057
    _interrupt(16);                             //int 0x10
    goto loc_31e7;                              //jmp loc_31e7
loc_31bb:                                       //loc_31bb:
    _dx = 0x5035;                               //mov dx, 0x5035
    _ax = 0x1002;                               //mov ax, 0x1002
    _interrupt(16);                             //int 0x10
    goto loc_31e7;                              //jmp loc_31e7
loc_31c5:                                       //loc_31c5:
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    memory16(_ds, 21098) = 0x0000;              //mov word ptr [0x526a], 0x0
    memory16(_ds, 21096) = 0x0000;              //mov word ptr [0x5268], 0x0
    memory16(_ds, 21084) = 0x0050;              //mov word ptr [0x525c], 0x50
    memory(_cs, 0x0) = 0x02;                    //mov byte ptr cs:[0x0], 0x2
    _ax = 0x0004;                               //mov ax, 0x4
    _interrupt(16);                             //int 0x10
loc_31e7:                                       //loc_31e7:
    goto loc_3239;                              //jmp loc_3239
loc_31e9:                                       //loc_31e9:
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    memory16(_ds, 21098) = 0x0000;              //mov word ptr [0x526a], 0x0
    memory16(_ds, 21096) = 0x0000;              //mov word ptr [0x5268], 0x0
    memory16(_ds, 21084) = 0x0050;              //mov word ptr [0x525c], 0x50
    memory(_cs, 0x0) = 0x02;                    //mov byte ptr cs:[0x0], 0x2
    _si = 0x5025;                               //mov si, 0x5025
    _dx = 0x03bf;                               //mov dx, 0x3bf
    _al = 0x03;                                 //mov al, 0x3
    _out(_dx, _al);                             //out dx, al
    _dl = 0xb8;                                 //mov dl, 0xb8
    _al = 0x82;                                 //mov al, 0x82
    _out(_dx, _al);                             //out dx, al
    _dl = 0xb4;                                 //mov dl, 0xb4
    _cx = 0x000e;                               //mov cx, 0xe
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_321b:                                       //loc_321b:
    _al = _ah;                                  //mov al, ah
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _lodsb<MemData, DirForward>();              //lodsb
    _out(_dx, _al);                             //out dx, al
    _dx -= 1;                                   //dec dx
    _ah += 1;                                   //inc ah
    if (--_cx)                                  //loop loc_321b
        goto loc_321b;
    _cx = 0x2000;                               //mov cx, 0x2000
    _ax = 0xb800;                               //mov ax, 0xb800
    _es = _ax;                                  //mov es, ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _di = _di ^ _di;                            //xor di, di
    _rep_stosw<MemData, DirForward>();          //rep stosw
    _dl = 0xb8;                                 //mov dl, 0xb8
    _al = 0x8a;                                 //mov al, 0x8a
    _out(_dx, _al);                             //out dx, al
loc_3239:                                       //loc_3239:
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_3243()
{
    

    _push(_ax);                                 //push ax
    _push(_dx);                                 //push dx
    if (memory(_cs, 0x1) == 0x00)               //jz loc_325f
        goto loc_325f;
    _dx = 0x03da;                               //mov dx, 0x3da
    _ah = 0x08;                                 //mov ah, 0x8
loc_3252:                                       //loc_3252:
    _in(_al, _dx);                              //in al, dx
    if (_ah & _al)                              //jnz loc_3252
        goto loc_3252;
loc_3257:                                       //loc_3257:
    _in(_al, _dx);                              //in al, dx
    if (!(_ah & _al))                           //jz loc_3257
        goto loc_3257;
    _dx = _pop();                               //pop dx
    _ax = _pop();                               //pop ax
    return;                                     //ret
loc_325f:                                       //loc_325f:
    _dx = 0x03ba;                               //mov dx, 0x3ba
    _ah = 0x01;                                 //mov ah, 0x1
loc_3264:                                       //loc_3264:
    _in(_al, _dx);                              //in al, dx
    if (_ah & _al)                              //jnz loc_3264
        goto loc_3264;
loc_3269:                                       //loc_3269:
    _in(_al, _dx);                              //in al, dx
    if (!(_ah & _al))                           //jz loc_3269
        goto loc_3269;
    _dx = _pop();                               //pop dx
    _ax = _pop();                               //pop ax
}

void sub_3271()
{
    

    if (memory(_cs, 0x1) < 0x03)                //jc loc_32a4
        goto loc_32a4;
    sub_10d3();                                 //call sub_10d3
    _dx = 0x03d4;                               //mov dx, 0x3d4
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _bx = memory16(_ds, 21098);                 //mov bx, word ptr [0x526a]
    _al = 0x0d;                                 //mov al, 0xd
    _ah = _bl;                                  //mov ah, bl
    _out(_dx, _ax);                             //out dx, ax
    _ax -= 1;                                   //dec ax
    _ah = _bh;                                  //mov ah, bh
    _out(_dx, _ax);                             //out dx, ax
    _xchg(memory16(_ds, 21096), _bx);           //xchg word ptr [0x5268], bx
    memory16(_ds, 21098) = _bx;                 //mov word ptr [0x526a], bx
    if (memory(_ds, 25882) == 0x00)             //jz loc_32a3
        goto loc_32a3;
    sub_3243();                                 //call sub_3243
loc_32a3:                                       //loc_32a3:
    return;                                     //ret
loc_32a4:                                       //loc_32a4:
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _ds = memory16(_ds, 21090);                 //mov ds, word ptr [0x5262]
    _si = _si ^ _si;                            //xor si, si
    _ax = 0xb800;                               //mov ax, 0xb800
    _es = _ax;                                  //mov es, ax
    _di = _di ^ _di;                            //xor di, di
    _dx = 0x0060;                               //mov dx, 0x60
    _ax = 0x0028;                               //mov ax, 0x28
loc_32be:                                       //loc_32be:
    _cx = _ax;                                  //mov cx, ax
    _rep_movsw<MemData, MemData, DirForward>(); //rep movsw
    _di += 0x1fb0;                              //add di, 0x1fb0
    _cx = _ax;                                  //mov cx, ax
    _rep_movsw<MemData, MemData, DirForward>(); //rep movsw
    _di -= 0x2000;                              //sub di, 0x2000
    _dx -= 1;                                   //dec dx
    if (_dx != 0)                               //jnz loc_32be
        goto loc_32be;
    sub_10d3();                                 //call sub_10d3
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
    _dx = _pop();                               //pop dx
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_32dc()
{
    

    if (memory(_cs, 0x1) < 0x03)                //jc loc_32f3
        goto loc_32f3;
    _push(_ax);                                 //push ax
    _push(_dx);                                 //push dx
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _ax = 0x0005;                               //mov ax, 0x5
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0003;                               //mov ax, 0x3
    _out(_dx, _ax);                             //out dx, ax
    _dx = _pop();                               //pop dx
    _ax = _pop();                               //pop ax
loc_32f3:                                       //loc_32f3:
    return;
}

void sub_32f4()
{
    

    if (memory(_cs, 0x1) < 0x03)                //jc loc_330d
        goto loc_330d;
    _push(_ax);                                 //push ax
    _push(_dx);                                 //push dx
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _ax = 0x0105;                               //mov ax, 0x105
    _out(_dx, _ax);                             //out dx, ax
    _dl = 0xc4;                                 //mov dl, 0xc4
    _ax = 0x0f02;                               //mov ax, 0xf02
    _out(_dx, _ax);                             //out dx, ax
    _dx = _pop();                               //pop dx
    _ax = _pop();                               //pop ax
loc_330d:                                       //loc_330d:
    return;                                     //ret
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 40h");                           //db 40h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 50h");                           //db 50h
    _STOP_("db 90h");                           //db 90h
    _STOP_("db d0h");                           //db d0h
    _STOP_("db 20h");                           //db 20h
    _STOP_("db 60h");                           //db 60h
    _STOP_("db a0h");                           //db a0h
    _STOP_("db e0h");                           //db e0h
    _STOP_("db 30h");                           //db 30h
    _STOP_("db 70h");                           //db 70h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db f0h");                           //db f0h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 44h");                           //db 44h
    _STOP_("db 84h");                           //db 84h
    _STOP_("db c4h");                           //db c4h
    _STOP_("db 14h");                           //db 14h
    _STOP_("db 54h");                           //db 54h
    _STOP_("db 94h");                           //db 94h
    _STOP_("db d4h");                           //db d4h
    _STOP_("db 24h");                           //db 24h
    _STOP_("db 64h");                           //db 64h
    _STOP_("db a4h");                           //db a4h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 34h");                           //db 34h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db b4h");                           //db b4h
    _STOP_("db f4h");                           //db f4h
    _STOP_("db 08h");                           //db 08h
    _STOP_("db 48h");                           //db 48h
    _STOP_("db 88h");                           //db 88h
    _STOP_("db c8h");                           //db c8h
    _STOP_("db 18h");                           //db 18h
    _STOP_("db 58h");                           //db 58h
    _STOP_("db 98h");                           //db 98h
    _STOP_("db d8h");                           //db d8h
    _STOP_("db 28h");                           //db 28h
    _STOP_("db 68h");                           //db 68h
    _STOP_("db a8h");                           //db a8h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 38h");                           //db 38h
    _STOP_("db 78h");                           //db 78h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db f8h");                           //db f8h
    _STOP_("db 0ch");                           //db 0ch
    _STOP_("db 4ch");                           //db 4ch
    _STOP_("db 8ch");                           //db 8ch
    _STOP_("db cch");                           //db cch
    _STOP_("db 1ch");                           //db 1ch
    _STOP_("db 5ch");                           //db 5ch
    _STOP_("db 9ch");                           //db 9ch
    _STOP_("db dch");                           //db dch
    _STOP_("db 2ch");                           //db 2ch
    _STOP_("db 6ch");                           //db 6ch
    _STOP_("db ach");                           //db ach
    _STOP_("db ech");                           //db ech
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 7ch");                           //db 7ch
    _STOP_("db bch");                           //db bch
    _STOP_("db fch");                           //db fch
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 41h");                           //db 41h
    _STOP_("db 81h");                           //db 81h
    _STOP_("db c1h");                           //db c1h
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 51h");                           //db 51h
    _STOP_("db 91h");                           //db 91h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db 21h");                           //db 21h
    _STOP_("db 61h");                           //db 61h
    _STOP_("db a1h");                           //db a1h
    _STOP_("db e1h");                           //db e1h
    _STOP_("db 31h");                           //db 31h
    _STOP_("db 71h");                           //db 71h
    _STOP_("db b1h");                           //db b1h
    _STOP_("db f1h");                           //db f1h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 85h");                           //db 85h
    _STOP_("db c5h");                           //db c5h
    _STOP_("db 15h");                           //db 15h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 95h");                           //db 95h
    _STOP_("db d5h");                           //db d5h
    _STOP_("db 25h");                           //db 25h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db a5h");                           //db a5h
    _STOP_("db e5h");                           //db e5h
    _STOP_("db 35h");                           //db 35h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db b5h");                           //db b5h
    _STOP_("db f5h");                           //db f5h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 49h");                           //db 49h
    _STOP_("db 89h");                           //db 89h
    _STOP_("db c9h");                           //db c9h
    _STOP_("db 19h");                           //db 19h
    _STOP_("db 59h");                           //db 59h
    _STOP_("db 99h");                           //db 99h
    _STOP_("db d9h");                           //db d9h
    _STOP_("db 29h");                           //db 29h
    _STOP_("db 69h");                           //db 69h
    _STOP_("db a9h");                           //db a9h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 39h");                           //db 39h
    _STOP_("db 79h");                           //db 79h
    _STOP_("db b9h");                           //db b9h
    _STOP_("db f9h");                           //db f9h
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db 4dh");                           //db 4dh
    _STOP_("db 8dh");                           //db 8dh
    _STOP_("db cdh");                           //db cdh
    _STOP_("db 1dh");                           //db 1dh
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 9dh");                           //db 9dh
    _STOP_("db ddh");                           //db ddh
    _STOP_("db 2dh");                           //db 2dh
    _STOP_("db 6dh");                           //db 6dh
    _STOP_("db adh");                           //db adh
    _STOP_("db edh");                           //db edh
    _STOP_("db 3dh");                           //db 3dh
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db bdh");                           //db bdh
    _STOP_("db fdh");                           //db fdh
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 42h");                           //db 42h
    _STOP_("db 82h");                           //db 82h
    _STOP_("db c2h");                           //db c2h
    _STOP_("db 12h");                           //db 12h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 92h");                           //db 92h
    _STOP_("db d2h");                           //db d2h
    _STOP_("db 22h");                           //db 22h
    _STOP_("db 62h");                           //db 62h
    _STOP_("db a2h");                           //db a2h
    _STOP_("db e2h");                           //db e2h
    _STOP_("db 32h");                           //db 32h
    _STOP_("db 72h");                           //db 72h
    _STOP_("db b2h");                           //db b2h
    _STOP_("db f2h");                           //db f2h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 46h");                           //db 46h
    _STOP_("db 86h");                           //db 86h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 56h");                           //db 56h
    _STOP_("db 96h");                           //db 96h
    _STOP_("db d6h");                           //db d6h
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 66h");                           //db 66h
    _STOP_("db a6h");                           //db a6h
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 36h");                           //db 36h
    _STOP_("db 76h");                           //db 76h
    _STOP_("db b6h");                           //db b6h
    _STOP_("db f6h");                           //db f6h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db 4ah");                           //db 4ah
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db cah");                           //db cah
    _STOP_("db 1ah");                           //db 1ah
    _STOP_("db 5ah");                           //db 5ah
    _STOP_("db 9ah");                           //db 9ah
    _STOP_("db dah");                           //db dah
    _STOP_("db 2ah");                           //db 2ah
    _STOP_("db 6ah");                           //db 6ah
    _STOP_("db aah");                           //db aah
    _STOP_("db eah");                           //db eah
    _STOP_("db 3ah");                           //db 3ah
    _STOP_("db 7ah");                           //db 7ah
    _STOP_("db bah");                           //db bah
    _STOP_("db fah");                           //db fah
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 4eh");                           //db 4eh
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db ceh");                           //db ceh
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 5eh");                           //db 5eh
    _STOP_("db 9eh");                           //db 9eh
    _STOP_("db deh");                           //db deh
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db 6eh");                           //db 6eh
    _STOP_("db aeh");                           //db aeh
    _STOP_("db eeh");                           //db eeh
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 7eh");                           //db 7eh
    _STOP_("db beh");                           //db beh
    _STOP_("db feh");                           //db feh
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 43h");                           //db 43h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 13h");                           //db 13h
    _STOP_("db 53h");                           //db 53h
    _STOP_("db 93h");                           //db 93h
    _STOP_("db d3h");                           //db d3h
    _STOP_("db 23h");                           //db 23h
    _STOP_("db 63h");                           //db 63h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db e3h");                           //db e3h
    _STOP_("db 33h");                           //db 33h
    _STOP_("db 73h");                           //db 73h
    _STOP_("db b3h");                           //db b3h
    _STOP_("db f3h");                           //db f3h
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 47h");                           //db 47h
    _STOP_("db 87h");                           //db 87h
    _STOP_("db c7h");                           //db c7h
    _STOP_("db 17h");                           //db 17h
    _STOP_("db 57h");                           //db 57h
    _STOP_("db 97h");                           //db 97h
    _STOP_("db d7h");                           //db d7h
    _STOP_("db 27h");                           //db 27h
    _STOP_("db 67h");                           //db 67h
    _STOP_("db a7h");                           //db a7h
    _STOP_("db e7h");                           //db e7h
    _STOP_("db 37h");                           //db 37h
    _STOP_("db 77h");                           //db 77h
    _STOP_("db b7h");                           //db b7h
    _STOP_("db f7h");                           //db f7h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db 4bh");                           //db 4bh
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db cbh");                           //db cbh
    _STOP_("db 1bh");                           //db 1bh
    _STOP_("db 5bh");                           //db 5bh
    _STOP_("db 9bh");                           //db 9bh
    _STOP_("db dbh");                           //db dbh
    _STOP_("db 2bh");                           //db 2bh
    _STOP_("db 6bh");                           //db 6bh
    _STOP_("db abh");                           //db abh
    _STOP_("db ebh");                           //db ebh
    _STOP_("db 3bh");                           //db 3bh
    _STOP_("db 7bh");                           //db 7bh
    _STOP_("db bbh");                           //db bbh
    _STOP_("db fbh");                           //db fbh
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 4fh");                           //db 4fh
    _STOP_("db 8fh");                           //db 8fh
    _STOP_("db cfh");                           //db cfh
    _STOP_("db 1fh");                           //db 1fh
    _STOP_("db 5fh");                           //db 5fh
    _STOP_("db 9fh");                           //db 9fh
    _STOP_("db dfh");                           //db dfh
    _STOP_("db 2fh");                           //db 2fh
    _STOP_("db 6fh");                           //db 6fh
    _STOP_("db afh");                           //db afh
    _STOP_("db efh");                           //db efh
    _STOP_("db 3fh");                           //db 3fh
    _STOP_("db 7fh");                           //db 7fh
    _STOP_("db bfh");                           //db bfh
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 40h");                           //db 40h
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 20h");                           //db 20h
    _STOP_("db a0h");                           //db a0h
    _STOP_("db 60h");                           //db 60h
    _STOP_("db e0h");                           //db e0h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 90h");                           //db 90h
    _STOP_("db 50h");                           //db 50h
    _STOP_("db d0h");                           //db d0h
    _STOP_("db 30h");                           //db 30h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db 70h");                           //db 70h
    _STOP_("db f0h");                           //db f0h
    _STOP_("db 08h");                           //db 08h
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 48h");                           //db 48h
    _STOP_("db c8h");                           //db c8h
    _STOP_("db 28h");                           //db 28h
    _STOP_("db a8h");                           //db a8h
    _STOP_("db 68h");                           //db 68h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 18h");                           //db 18h
    _STOP_("db 98h");                           //db 98h
    _STOP_("db 58h");                           //db 58h
    _STOP_("db d8h");                           //db d8h
    _STOP_("db 38h");                           //db 38h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 78h");                           //db 78h
    _STOP_("db f8h");                           //db f8h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 84h");                           //db 84h
    _STOP_("db 44h");                           //db 44h
    _STOP_("db c4h");                           //db c4h
    _STOP_("db 24h");                           //db 24h
    _STOP_("db a4h");                           //db a4h
    _STOP_("db 64h");                           //db 64h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 14h");                           //db 14h
    _STOP_("db 94h");                           //db 94h
    _STOP_("db 54h");                           //db 54h
    _STOP_("db d4h");                           //db d4h
    _STOP_("db 34h");                           //db 34h
    _STOP_("db b4h");                           //db b4h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db f4h");                           //db f4h
    _STOP_("db 0ch");                           //db 0ch
    _STOP_("db 8ch");                           //db 8ch
    _STOP_("db 4ch");                           //db 4ch
    _STOP_("db cch");                           //db cch
    _STOP_("db 2ch");                           //db 2ch
    _STOP_("db ach");                           //db ach
    _STOP_("db 6ch");                           //db 6ch
    _STOP_("db ech");                           //db ech
    _STOP_("db 1ch");                           //db 1ch
    _STOP_("db 9ch");                           //db 9ch
    _STOP_("db 5ch");                           //db 5ch
    _STOP_("db dch");                           //db dch
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db bch");                           //db bch
    _STOP_("db 7ch");                           //db 7ch
    _STOP_("db fch");                           //db fch
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 82h");                           //db 82h
    _STOP_("db 42h");                           //db 42h
    _STOP_("db c2h");                           //db c2h
    _STOP_("db 22h");                           //db 22h
    _STOP_("db a2h");                           //db a2h
    _STOP_("db 62h");                           //db 62h
    _STOP_("db e2h");                           //db e2h
    _STOP_("db 12h");                           //db 12h
    _STOP_("db 92h");                           //db 92h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db d2h");                           //db d2h
    _STOP_("db 32h");                           //db 32h
    _STOP_("db b2h");                           //db b2h
    _STOP_("db 72h");                           //db 72h
    _STOP_("db f2h");                           //db f2h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 4ah");                           //db 4ah
    _STOP_("db cah");                           //db cah
    _STOP_("db 2ah");                           //db 2ah
    _STOP_("db aah");                           //db aah
    _STOP_("db 6ah");                           //db 6ah
    _STOP_("db eah");                           //db eah
    _STOP_("db 1ah");                           //db 1ah
    _STOP_("db 9ah");                           //db 9ah
    _STOP_("db 5ah");                           //db 5ah
    _STOP_("db dah");                           //db dah
    _STOP_("db 3ah");                           //db 3ah
    _STOP_("db bah");                           //db bah
    _STOP_("db 7ah");                           //db 7ah
    _STOP_("db fah");                           //db fah
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 86h");                           //db 86h
    _STOP_("db 46h");                           //db 46h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 26h");                           //db 26h
    _STOP_("db a6h");                           //db a6h
    _STOP_("db 66h");                           //db 66h
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 96h");                           //db 96h
    _STOP_("db 56h");                           //db 56h
    _STOP_("db d6h");                           //db d6h
    _STOP_("db 36h");                           //db 36h
    _STOP_("db b6h");                           //db b6h
    _STOP_("db 76h");                           //db 76h
    _STOP_("db f6h");                           //db f6h
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db 4eh");                           //db 4eh
    _STOP_("db ceh");                           //db ceh
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db aeh");                           //db aeh
    _STOP_("db 6eh");                           //db 6eh
    _STOP_("db eeh");                           //db eeh
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 9eh");                           //db 9eh
    _STOP_("db 5eh");                           //db 5eh
    _STOP_("db deh");                           //db deh
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db beh");                           //db beh
    _STOP_("db 7eh");                           //db 7eh
    _STOP_("db feh");                           //db feh
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 81h");                           //db 81h
    _STOP_("db 41h");                           //db 41h
    _STOP_("db c1h");                           //db c1h
    _STOP_("db 21h");                           //db 21h
    _STOP_("db a1h");                           //db a1h
    _STOP_("db 61h");                           //db 61h
    _STOP_("db e1h");                           //db e1h
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 91h");                           //db 91h
    _STOP_("db 51h");                           //db 51h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db 31h");                           //db 31h
    _STOP_("db b1h");                           //db b1h
    _STOP_("db 71h");                           //db 71h
    _STOP_("db f1h");                           //db f1h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 49h");                           //db 49h
    _STOP_("db c9h");                           //db c9h
    _STOP_("db 29h");                           //db 29h
    _STOP_("db a9h");                           //db a9h
    _STOP_("db 69h");                           //db 69h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 19h");                           //db 19h
    _STOP_("db 99h");                           //db 99h
    _STOP_("db 59h");                           //db 59h
    _STOP_("db d9h");                           //db d9h
    _STOP_("db 39h");                           //db 39h
    _STOP_("db b9h");                           //db b9h
    _STOP_("db 79h");                           //db 79h
    _STOP_("db f9h");                           //db f9h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 85h");                           //db 85h
    _STOP_("db 45h");                           //db 45h
    _STOP_("db c5h");                           //db c5h
    _STOP_("db 25h");                           //db 25h
    _STOP_("db a5h");                           //db a5h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db e5h");                           //db e5h
    _STOP_("db 15h");                           //db 15h
    _STOP_("db 95h");                           //db 95h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db d5h");                           //db d5h
    _STOP_("db 35h");                           //db 35h
    _STOP_("db b5h");                           //db b5h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db f5h");                           //db f5h
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db 8dh");                           //db 8dh
    _STOP_("db 4dh");                           //db 4dh
    _STOP_("db cdh");                           //db cdh
    _STOP_("db 2dh");                           //db 2dh
    _STOP_("db adh");                           //db adh
    _STOP_("db 6dh");                           //db 6dh
    _STOP_("db edh");                           //db edh
    _STOP_("db 1dh");                           //db 1dh
    _STOP_("db 9dh");                           //db 9dh
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db ddh");                           //db ddh
    _STOP_("db 3dh");                           //db 3dh
    _STOP_("db bdh");                           //db bdh
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db fdh");                           //db fdh
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db 43h");                           //db 43h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 23h");                           //db 23h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 63h");                           //db 63h
    _STOP_("db e3h");                           //db e3h
    _STOP_("db 13h");                           //db 13h
    _STOP_("db 93h");                           //db 93h
    _STOP_("db 53h");                           //db 53h
    _STOP_("db d3h");                           //db d3h
    _STOP_("db 33h");                           //db 33h
    _STOP_("db b3h");                           //db b3h
    _STOP_("db 73h");                           //db 73h
    _STOP_("db f3h");                           //db f3h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 4bh");                           //db 4bh
    _STOP_("db cbh");                           //db cbh
    _STOP_("db 2bh");                           //db 2bh
    _STOP_("db abh");                           //db abh
    _STOP_("db 6bh");                           //db 6bh
    _STOP_("db ebh");                           //db ebh
    _STOP_("db 1bh");                           //db 1bh
    _STOP_("db 9bh");                           //db 9bh
    _STOP_("db 5bh");                           //db 5bh
    _STOP_("db dbh");                           //db dbh
    _STOP_("db 3bh");                           //db 3bh
    _STOP_("db bbh");                           //db bbh
    _STOP_("db 7bh");                           //db 7bh
    _STOP_("db fbh");                           //db fbh
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 87h");                           //db 87h
    _STOP_("db 47h");                           //db 47h
    _STOP_("db c7h");                           //db c7h
    _STOP_("db 27h");                           //db 27h
    _STOP_("db a7h");                           //db a7h
    _STOP_("db 67h");                           //db 67h
    _STOP_("db e7h");                           //db e7h
    _STOP_("db 17h");                           //db 17h
    _STOP_("db 97h");                           //db 97h
    _STOP_("db 57h");                           //db 57h
    _STOP_("db d7h");                           //db d7h
    _STOP_("db 37h");                           //db 37h
    _STOP_("db b7h");                           //db b7h
    _STOP_("db 77h");                           //db 77h
    _STOP_("db f7h");                           //db f7h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 8fh");                           //db 8fh
    _STOP_("db 4fh");                           //db 4fh
    _STOP_("db cfh");                           //db cfh
    _STOP_("db 2fh");                           //db 2fh
    _STOP_("db afh");                           //db afh
    _STOP_("db 6fh");                           //db 6fh
    _STOP_("db efh");                           //db efh
    _STOP_("db 1fh");                           //db 1fh
    _STOP_("db 9fh");                           //db 9fh
    _STOP_("db 5fh");                           //db 5fh
    _STOP_("db dfh");                           //db dfh
    _STOP_("db 3fh");                           //db 3fh
    _STOP_("db bfh");                           //db bfh
    _STOP_("db 7fh");                           //db 7fh
    _STOP_("db ffh");                           //db ffh
loc_350e:                                       //loc_350e:
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    memory(_ds, 21072) = 0x00;                  //mov byte ptr [0x5250], 0x0
    memory(_ds, 25880) = 0x00;                  //mov byte ptr [0x6518], 0x0
    _di = 0x527c;                               //mov di, 0x527c
    _cx = 0x003a;                               //mov cx, 0x3a
loc_3525:                                       //loc_3525:
    memory16(_ds, _di + 4) = 0xffff;            //mov word ptr [di+0x4], 0xffff
    _di += 0x0012;                              //add di, 0x12
    if (--_cx)                                  //loop loc_3525
        goto loc_3525;
    memory16(_ds, 21120) = 0x0157;              //mov word ptr [0x5280], 0x157
    memory16(_ds, 21116) = 0xff9c;              //mov word ptr [0x527c], 0xff9c
    memory16(_ds, 21118) = 0x00b4;              //mov word ptr [0x527e], 0xb4
    memory16(_ds, 21128) = 0x6609;              //mov word ptr [0x5288], 0x6609
    memory16(_ds, 21174) = 0x0151;              //mov word ptr [0x52b6], 0x151
    memory16(_ds, 21170) = 0x01a4;              //mov word ptr [0x52b2], 0x1a4
    memory16(_ds, 21172) = 0x00b4;              //mov word ptr [0x52b4], 0xb4
    memory16(_ds, 21182) = 0x65e3;              //mov word ptr [0x52be], 0x65e3
loc_355f:                                       //loc_355f:
    sub_3f46();                                 //call sub_3f46
    sub_2ba2();                                 //call sub_2ba2
    _si = 0x527c;                               //mov si, 0x527c
    memory16(_ds, _si) += 0x0003;               //add word ptr [si], 0x3
    sub_3611();                                 //call sub_3611
    _si = 0x52b2;                               //mov si, 0x52b2
    memory16(_ds, _si) -= 0x0003;               //sub word ptr [si], 0x3
    sub_3611();                                 //call sub_3611
    sub_2c87();                                 //call sub_2c87
    sub_1c61();                                 //call sub_1c61
    sub_3271();                                 //call sub_3271
    _ax = memory16(_ds, 0x527c);                //mov ax, [0x527c]
    _ax += 0x001c;                              //add ax, 0x1c
    if ((short)memory16(_ds, 21170) > (short)_ax)//jg loc_355f
        goto loc_355f;
    memory16(_ds, 21174) = 0x815a;              //mov word ptr [0x52b6], 0x815a
    memory16(_ds, 21170) -= 0x0018;             //sub word ptr [0x52b2], 0x18
    _si = 0x527c;                               //mov si, 0x527c
    memory16(_ds, 21128) = 0x661d;              //mov word ptr [0x5288], 0x661d
    memory16(_ds, 21118) -= 0x0010;             //sub word ptr [0x527e], 0x10
    _cx = 0x0010;                               //mov cx, 0x10
loc_35a8:                                       //loc_35a8:
    _push(_cx);                                 //push cx
    sub_3611();                                 //call sub_3611
    sub_3f46();                                 //call sub_3f46
    sub_2ba2();                                 //call sub_2ba2
    sub_2c87();                                 //call sub_2c87
    sub_1c61();                                 //call sub_1c61
    sub_3271();                                 //call sub_3271
    memory16(_ds, 21118) += 1;                  //inc word ptr [0x527e]
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_35a8
        goto loc_35a8;
    memory16(_ds, 21120) = 0x0163;              //mov word ptr [0x5280], 0x163
    _si = 0x663f;                               //mov si, 0x663f
loc_35cb:                                       //loc_35cb:
    _lodsb<MemData, DirForward>();              //lodsb
    _ah = _ah ^ _ah;                            //xor ah, ah
    memory16(_ds, 0x527c) = _ax;                //mov [0x527c], ax
    _lodsb<MemData, DirForward>();              //lodsb
    _ah = _ah ^ _ah;                            //xor ah, ah
    memory16(_ds, 0x527e) = _ax;                //mov [0x527e], ax
    _push(_si);                                 //push si
    sub_3f46();                                 //call sub_3f46
    sub_2ba2();                                 //call sub_2ba2
    sub_2c87();                                 //call sub_2c87
    sub_1c61();                                 //call sub_1c61
    sub_3271();                                 //call sub_3271
    sub_0805();                                 //call sub_0805
    _si = _pop();                               //pop si
    if (memory(_ds, 1067) != 0x00)              //jnz loc_35fd
        goto loc_35fd;
    _ax = memory16(_ds, _si);                   //mov ax, word ptr [si]
    if (_ax != 0xffdc)                          //jnz loc_35cb
        goto loc_35cb;
    _si += _ax;                                 //add si, ax
    goto loc_35cb;                              //jmp loc_35cb
loc_35fd:                                       //loc_35fd:
    _ax = 0x014f;                               //mov ax, 0x14f
    _dx = 0x0150;                               //mov dx, 0x150
    _si = 0x527c;                               //mov si, 0x527c
    sub_372f();                                 //call sub_372f
    sub_1a59();                                 //call sub_1a59
    _ax = 0x0001;                               //mov ax, 0x1
    _flags.carry = true;                        //stc
}

void sub_3611()
{
    _bx = memory16(_ds, _si + 12);              //mov bx, word ptr [si+0xc]
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
loc_3616:                                       //loc_3616:
    _ax = memory16(_ds, _bx);                   //mov ax, word ptr [bx]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (!_flags.sign)                           //jns loc_3620
        goto loc_3620;
    _bx += _ax;                                 //add bx, ax
    goto loc_3616;                              //jmp loc_3616
loc_3620:                                       //loc_3620:
    memory16(_ds, _si + 4) = _ax;               //mov word ptr [si+0x4], ax
    memory16(_ds, _si + 12) = _bx;              //mov word ptr [si+0xc], bx
}

void sub_3627()
{
    _ax = _ax ^ _ax;                            //xor ax, ax
    if (memory(_ds, 25881) == 0x01)             //jz loc_364e
        goto loc_364e;
    _ax += 1;                                   //inc ax
    if (memory(_ds, 25879) != 0x01)             //jnz loc_363b
        goto loc_363b;
    goto loc_3710;                              //jmp loc_3710
loc_363b:                                       //loc_363b:
    if (memory(_ds, 25878) == 0x01)             //jz loc_3660
        goto loc_3660;
    if (memory(_ds, 25880) != 0x01)             //jnz loc_364c
        goto loc_364c;
    _STOP_("goto loc_350e");                    //jmp loc_350e
loc_364c:                                       //loc_364c:
    _flags.carry = false;                       //clc
    return;                                     //ret
loc_364e:                                       //loc_364e:
    sub_0173();                                 //call sub_0173
    memory(_ds, 1049) = 0x10;                   //mov byte ptr [0x419], 0x10
    sub_378d();                                 //call sub_378d
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, 0x64fa) = _ax;                //mov [0x64fa], ax
    _flags.carry = true;                        //stc
    return;                                     //ret
loc_3660:                                       //loc_3660:
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    _ax = 0x0001;                               //mov ax, 0x1
    sub_10ff();                                 //call sub_10ff
    sub_4ae9();                                 //call sub_4ae9
    memory16(_ds, 21120) = 0x000d;              //mov word ptr [0x5280], 0xd
    memory16(_ds, 21130) = 0x000f;              //mov word ptr [0x528a], 0xf
    _cx = 0x003c;                               //mov cx, 0x3c
loc_3681:                                       //loc_3681:
    _push(_cx);                                 //push cx
    sub_2c87();                                 //call sub_2c87
    sub_39c7();                                 //call sub_39c7
    sub_1c61();                                 //call sub_1c61
    sub_3271();                                 //call sub_3271
    sub_3243();                                 //call sub_3243
    _ax = memory16(_ds, 0x528a);                //mov ax, [0x528a]
    _ax -= 1;                                   //dec ax
    if ((short)_ax >= (short)0xfff0)            //jge loc_369d
        goto loc_369d;
    _ax = 0xfff0;                               //mov ax, 0xfff0
loc_369d:                                       //loc_369d:
    memory16(_ds, 0x528a) = _ax;                //mov [0x528a], ax
    memory16(_ds, 21118) -= _ax;                //sub word ptr [0x527e], ax
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_3681
        goto loc_3681;
    sub_378d();                                 //call sub_378d
    _ax = memory16(_ds, 0x64e4);                //mov ax, [0x64e4]
    memory16(_ds, 0x527c) = _ax;                //mov [0x527c], ax
    _ax = memory16(_ds, 0x64e6);                //mov ax, [0x64e6]
    memory16(_ds, 0x527e) = _ax;                //mov [0x527e], ax
    if (memory16(_ds, 25850) == 0x0000)         //jz loc_36e3
        goto loc_36e3;
    _si = 0x52a0;                               //mov si, 0x52a0
    _cx = 0x0028;                               //mov cx, 0x28
loc_36c3:                                       //loc_36c3:
    _bx = memory16(_ds, _si + 4);               //mov bx, word ptr [si+0x4]
    _bh &= 0x1f;                                //and bh, 0x1f
    _bx -= 0x0038;                              //sub bx, 0x38
    if (_bx > 0x0001)                           //ja loc_36de
        goto loc_36de;
    _ax = memory16(_ds, 0x64f8);                //mov ax, [0x64f8]
    memory16(_ds, _si) = _ax;                   //mov word ptr [si], ax
    _ax = memory16(_ds, 0x64fa);                //mov ax, [0x64fa]
    memory16(_ds, _si + 2) = _ax;               //mov word ptr [si+0x2], ax
    goto loc_36e3;                              //jmp loc_36e3
loc_36de:                                       //loc_36de:
    _si += 0x0012;                              //add si, 0x12
    if (--_cx)                                  //loop loc_36c3
        goto loc_36c3;
loc_36e3:                                       //loc_36e3:
    memory(_ds, 1049) = 0x10;                   //mov byte ptr [0x419], 0x10
    sub_17eb();                                 //call sub_17eb
    _ax = 0x0000;                               //mov ax, 0x0
    sub_10ff();                                 //call sub_10ff
    sub_01d9();                                 //call sub_01d9
    _bl = memory(_ds, 21072);                   //mov bl, byte ptr [0x5250]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _al = memory(_ds, _bx + 20620);             //mov al, byte ptr [bx+0x508c]
    _cbw();                                     //cbw
    sub_10ff();                                 //call sub_10ff
    sub_2d62();                                 //call sub_2d62
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    _flags.carry = false;                       //clc
    return;                                     //ret
loc_3710:                                       //loc_3710:
    _ax = 0x0002;                               //mov ax, 0x2
    sub_10ff();                                 //call sub_10ff
    memory(_ds, 1049) = 0x10;                   //mov byte ptr [0x419], 0x10
    memory(_ds, 1050) = 0x00;                   //mov byte ptr [0x41a], 0x0
    memory16(_ds, 21120) = 0x000d;              //mov word ptr [0x5280], 0xd
    _si = 0x528e;                               //mov si, 0x528e
    _ax = 0x014d;                               //mov ax, 0x14d
    _dx = 0x014e;                               //mov dx, 0x14e
    _STOP_("sp-trace-fail");                    //sub_3627 endp_failed
    _STOP_("continues");                        //sub_372f proc near
}

void sub_372f()
{
    _lea(_di, _ds, _si + 18);                   //lea di, [si+0x12]
    _cl = 0x04;                                 //mov cl, 0x4
    memory16(_ds, _si + 4) = _ax;               //mov word ptr [si+0x4], ax
    _ax = memory16(_ds, 0x5270);                //mov ax, [0x5270]
    _ax <<= _cl;                                //shl ax, cl
    _ax -= 0x0076;                              //sub ax, 0x76
    memory16(_ds, _si) = _ax;                   //mov word ptr [si], ax
    _ax = memory16(_ds, 0x5272);                //mov ax, [0x5272]
    _ax <<= _cl;                                //shl ax, cl
    _ax += 0x0064;                              //add ax, 0x64
    memory16(_ds, _si + 2) = _ax;               //mov word ptr [si+0x2], ax
    memory16(_ds, _di + 4) = _dx;               //mov word ptr [di+0x4], dx
    _ax = memory16(_ds, 0x5270);                //mov ax, [0x5270]
    _ax <<= _cl;                                //shl ax, cl
    _ax += 0x01b6;                              //add ax, 0x1b6
    memory16(_ds, _di) = _ax;                   //mov word ptr [di], ax
    _ax = memory16(_ds, 0x5272);                //mov ax, [0x5272]
    _ax <<= _cl;                                //shl ax, cl
    _ax += 0x0064;                              //add ax, 0x64
    memory16(_ds, _di + 2) = _ax;               //mov word ptr [di+0x2], ax
    _cx = 0x001f;                               //mov cx, 0x1f
loc_3767:                                       //loc_3767:
    _push(_cx);                                 //push cx
    sub_2c87();                                 //call sub_2c87
    sub_1c61();                                 //call sub_1c61
    sub_3271();                                 //call sub_3271
    _cx = _pop();                               //pop cx
    memory16(_ds, _si) += 0x0008;               //add word ptr [si], 0x8
    memory16(_ds, _di) -= 0x0008;               //sub word ptr [di], 0x8
    if (--_cx)                                  //loop loc_3767
        goto loc_3767;
    sub_1a2a();                                 //call sub_1a2a
    memory(_ds, 21072) = 0x00;                  //mov byte ptr [0x5250], 0x0
    memory16(_ds, 25850) = 0x0000;              //mov word ptr [0x64fa], 0x0
    _ax = 0x0001;                               //mov ax, 0x1
    _flags.carry = true;                        //stc
}

void sub_378d()
{
    _push(_ax);                                 //push ax
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _di = 0x64fc;                               //mov di, 0x64fc
    _cx = 0x002b;                               //mov cx, 0x2b
    _al = 0x00;                                 //mov al, 0x0
    _rep_stosb<MemData, DirForward>();          //rep stosb
    _si = 0x7e97;                               //mov si, 0x7e97
    _di = 0x75a3;                               //mov di, 0x75a3
    _cx = 0x08f4;                               //mov cx, 0x8f4
    _rep_movsb<MemData, MemData, DirForward>(); //rep movsb
    memory(_ds, 0x6504) = _al;                  //mov [0x6504], al
    memory(_ds, 0x6510) = _al;                  //mov [0x6510], al
    memory(_ds, 25873) = 0x04;                  //mov byte ptr [0x6511], 0x4
    memory(_ds, 0x650d) = _al;                  //mov [0x650d], al
    memory(_ds, 0x6512) = _al;                  //mov [0x6512], al
    memory(_ds, 0x6514) = _al;                  //mov [0x6514], al
    memory(_ds, 0x6513) = _al;                  //mov [0x6513], al
    memory(_ds, 0x6505) = _al;                  //mov [0x6505], al
    memory(_ds, 0x650a) = _al;                  //mov [0x650a], al
    memory(_ds, 0x6509) = _al;                  //mov [0x6509], al
    memory(_ds, 0x6502) = _al;                  //mov [0x6502], al
    memory(_ds, 0x6517) = _al;                  //mov [0x6517], al
    memory(_ds, 0x6519) = _al;                  //mov [0x6519], al
    memory(_ds, 0x6516) = _al;                  //mov [0x6516], al
    memory(_ds, 0x651b) = _al;                  //mov [0x651b], al
    memory(_ds, 0x6500) = _al;                  //mov [0x6500], al
    _ax = 0xffff;                               //mov ax, 0xffff
    _si = 0x5600;                               //mov si, 0x5600
    _cx = 0x0004;                               //mov cx, 0x4
loc_37e5:                                       //loc_37e5:
    memory16(_ds, _si + 4) = _ax;               //mov word ptr [si+0x4], ax
    _si += 0x0012;                              //add si, 0x12
    if (--_cx)                                  //loop loc_37e5
        goto loc_37e5;
    sub_56cc();                                 //call sub_56cc
    sub_3ee8();                                 //call sub_3ee8
    _ax = _pop();                               //pop ax
}

void sub_37f5()
{
    if (memory(_ds, 21127) != 0x00)             //jnz loc_3820
        goto loc_3820;
    if (memory(_ds, 25884) != 0x01)             //jnz loc_3820
        goto loc_3820;
    if (memory16(_ds, 25886) < 0x008c)          //jc loc_3820
        goto loc_3820;
    _al = 0x1d;                                 //mov al, 0x1d
    if (memory16(_ds, 25886) < 0x00af)          //jc loc_381d
        goto loc_381d;
    _al = _al ^ _al;                            //xor al, al
    memory16(_ds, 25886) = 0x0000;              //mov word ptr [0x651e], 0x0
loc_381d:                                       //loc_381d:
    memory(_ds, 0x5280) = _al;                  //mov [0x5280], al
loc_3820:                                       //loc_3820:
    _si = 0x528e;                               //mov si, 0x528e
    _cx = 0x0029;                               //mov cx, 0x29
    _bx = memory16(_ds, 25854);                 //mov bx, word ptr [0x64fe]
loc_382a:                                       //loc_382a:
    _ax = memory16(_ds, _si + 4);               //mov ax, word ptr [si+0x4]
    if (!(_ah & 0x20))                          //jz loc_38ab
        goto loc_38ab;
    if (_ax == 0xffff)                          //jz loc_38ab
        goto loc_38ab;
    if (_bl & 0x07)                             //jnz loc_386f
        goto loc_386f;
    _dl = _al;                                  //mov dl, al
    _dl -= 0x38;                                //sub dl, 0x38
    if (_dl == 0)                               //jz loc_384f
        goto loc_384f;
    if (_dl > 0x01)                             //ja loc_385a
        goto loc_385a;
    if (memory(_ds, 25854) & 0x3f)              //jnz loc_38ab
        goto loc_38ab;
loc_384f:                                       //loc_384f:
    _dl = _dl ^ 0x01;                           //xor dl, 0x1
    _dl += 0x38;                                //add dl, 0x38
    memory(_ds, _si + 4) = _dl;                 //mov byte ptr [si+0x4], dl
    goto loc_38ab;                              //jmp loc_38ab
loc_385a:                                       //loc_385a:
    _dl = _al;                                  //mov dl, al
    _dl -= 0x33;                                //sub dl, 0x33
    if (_dl > 0x01)                             //ja loc_386f
        goto loc_386f;
    _dl = _dl ^ 0x01;                           //xor dl, 0x1
    _dl += 0x33;                                //add dl, 0x33
    memory(_ds, _si + 4) = _dl;                 //mov byte ptr [si+0x4], dl
    goto loc_38ab;                              //jmp loc_38ab
loc_386f:                                       //loc_386f:
    if (_bl & 0x01)                             //jnz loc_38ab
        goto loc_38ab;
    _dl = _al;                                  //mov dl, al
    _dl -= 0x36;                                //sub dl, 0x36
    if (_dl > 0x01)                             //ja loc_38ab
        goto loc_38ab;
    _dl = 0x37;                                 //mov dl, 0x37
    if (memory(_ds, _si + 8) == 0x00)           //jz loc_38a6
        goto loc_38a6;
    _dh = 0x01;                                 //mov dh, 0x1
    if (memory(_ds, 25873) <= 0x01)             //jbe loc_3891
        goto loc_3891;
    _dh = _dh ^ _dh;                            //xor dh, dh
loc_3891:                                       //loc_3891:
    memory(_ds, _si + 8) &= _dh;                //and byte ptr [si+0x8], dh
    _dl -= 1;                                   //dec dl
    if (_al == 0x36)                            //jz loc_38a6
        goto loc_38a6;
    _di = memory16(_ds, _si + 9);               //mov di, word ptr [si+0x9]
    memory16(_ds, _di + 2) += 0x0005;           //add word ptr [di+0x2], 0x5
    memory(_ds, 25873) = 0x03;                  //mov byte ptr [0x6511], 0x3
loc_38a6:                                       //loc_38a6:
    memory(_ds, _si + 4) = _dl;                 //mov byte ptr [si+0x4], dl
    goto loc_38ab;                              //jmp loc_38ab
loc_38ab:                                       //loc_38ab:
    _si += 0x0012;                              //add si, 0x12
    _cx -= 1;                                   //dec cx
    if (_cx == 0)                               //jz loc_38b4
        goto loc_38b4;
    goto loc_382a;                              //jmp loc_382a
loc_38b4:                                       //loc_38b4:
    return;
}

void sub_38b5()
{
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    if (memory(_ds, 25853) != 0x00)             //jnz loc_3937
        goto loc_3937;
    if (memory(_ds, 21072) != 0x09)             //jnz loc_38d6
        goto loc_38d6;
    _ax = memory16(_ds, 0x5292);                //mov ax, [0x5292]
    _ah &= 0x1f;                                //and ah, 0x1f
    _ax -= 0x0038;                              //sub ax, 0x38
    if (_ax > 0x0001)                           //ja loc_3937
        goto loc_3937;
loc_38d6:                                       //loc_38d6:
    if (memory(_ds, 21072) != 0x10)             //jnz loc_38e2
        goto loc_38e2;
    memory(_ds, 25880) = 0x01;                  //mov byte ptr [0x6518], 0x1
loc_38e2:                                       //loc_38e2:
    _ax = memory16(_ds, 0x527c);                //mov ax, [0x527c]
    _al &= 0xf0;                                //and al, 0xf0
    if (memory16(_ds, 32403) == _ax)            //jz loc_38f6
        goto loc_38f6;
    _ax -= 0x0010;                              //sub ax, 0x10
    if (memory16(_ds, 32403) != _ax)            //jnz loc_3937
        goto loc_3937;
loc_38f6:                                       //loc_38f6:
    _ax = memory16(_ds, 0x527e);                //mov ax, [0x527e]
    _al &= 0xf0;                                //and al, 0xf0
    if (memory16(_ds, 32405) == _ax)            //jz loc_390a
        goto loc_390a;
    _ax -= 0x0010;                              //sub ax, 0x10
    if (memory16(_ds, 32405) != _ax)            //jnz loc_3937
        goto loc_3937;
loc_390a:                                       //loc_390a:
    _ax = 0x0004;                               //mov ax, 0x4
    sub_10ff();                                 //call sub_10ff
    sub_17eb();                                 //call sub_17eb
    sub_2811();                                 //call sub_2811
    _bl = memory(_ds, 21072);                   //mov bl, byte ptr [0x5250]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _si = 0x523c;                               //mov si, 0x523c
    _al = memory(_ds, _bx + _si);               //mov al, byte ptr [bx+si]
    _ax += 1;                                   //inc ax
loc_3922:                                       //loc_3922:
    if (memory(_ds, _si) == _al)                //jz loc_3929
        goto loc_3929;
    _si += 1;                                   //inc si
    goto loc_3922;                              //jmp loc_3922
loc_3929:                                       //loc_3929:
    _ax = _si;                                  //mov ax, si
    _ax -= 0x523c;                              //sub ax, 0x523c
    memory(_ds, 0x5250) = _al;                  //mov [0x5250], al
    memory(_ds, 25881) = 0x01;                  //mov byte ptr [0x6519], 0x1
    return;                                     //ret
loc_3937:                                       //loc_3937:
    if (memory(_ds, 25872) == 0x00)             //jz loc_395d
        goto loc_395d;
    _cl = 0x04;                                 //mov cl, 0x4
    _ax = memory16(_ds, 0x527e);                //mov ax, [0x527e]
    _sar(_ax, _cl);                             //sar ax, cl
    _dh = _al;                                  //mov dh, al
    _ax = memory16(_ds, 0x527c);                //mov ax, [0x527c]
    _sar(_ax, _cl);                             //sar ax, cl
    _dl = _al;                                  //mov dl, al
    _si = 0x7d3f;                               //mov si, 0x7d3f
    _cx = 0x0014;                               //mov cx, 0x14
loc_3954:                                       //loc_3954:
    if (memory16(_ds, _si) == _dx)              //jz loc_395e
        goto loc_395e;
    _si += 0x0007;                              //add si, 0x7
    if (--_cx)                                  //loop loc_3954
        goto loc_3954;
loc_395d:                                       //loc_395d:
    return;                                     //ret
loc_395e:                                       //loc_395e:
    memory16(_ds, 21122) = 0x0000;              //mov word ptr [0x5282], 0x0
    memory16(_ds, 21130) = 0x0000;              //mov word ptr [0x528a], 0x0
    sub_2811();                                 //call sub_2811
    _push(memory16(_ds, 32061));                //push word ptr [0x7d3d]
    _push(_si);                                 //push si
    memory16(_ds, 32061) = 0x00ec;              //mov word ptr [0x7d3d], 0xec
    _ax = memory16(_ds, _si + 4);               //mov ax, word ptr [si+0x4]
    _cl = 0x04;                                 //mov cl, 0x4
    _dl = _al;                                  //mov dl, al
    _dh = _dh ^ _dh;                            //xor dh, dh
    _dx <<= _cl;                                //shl dx, cl
    memory16(_ds, 21116) = _dx;                 //mov word ptr [0x527c], dx
    _dl = _ah;                                  //mov dl, ah
    _dh = _dh ^ _dh;                            //xor dh, dh
    _dx <<= _cl;                                //shl dx, cl
    memory16(_ds, 21118) = _dx;                 //mov word ptr [0x527e], dx
    _ax = memory16(_ds, _si + 2);               //mov ax, word ptr [si+0x2]
loc_3994:                                       //loc_3994:
    if (memory(_ds, 21106) == _ah)              //jz loc_39a6
        goto loc_39a6;
    if (memory(_ds, 21106) < _ah)               //jc loc_39a1
        goto loc_39a1;
    sub_2911();                                 //call sub_2911
    goto loc_3994;                              //jmp loc_3994
loc_39a1:                                       //loc_39a1:
    sub_294c();                                 //call sub_294c
    goto loc_3994;                              //jmp loc_3994
loc_39a6:                                       //loc_39a6:
    if (memory(_ds, 21104) == _al)              //jz loc_39b8
        goto loc_39b8;
    if (memory(_ds, 21104) < _al)               //jc loc_39b3
        goto loc_39b3;
    sub_2994();                                 //call sub_2994
    goto loc_39a6;                              //jmp loc_39a6
loc_39b3:                                       //loc_39b3:
    sub_29b5();                                 //call sub_29b5
    goto loc_39a6;                              //jmp loc_39a6
loc_39b8:                                       //loc_39b8:
    _si = _pop();                               //pop si
    memory16(_ds, 32061) = _pop();              //pop word ptr [0x7d3d]
    _al = memory(_ds, _si + 6);                 //mov al, byte ptr [si+0x6]
    memory(_ds, 0x6502) = _al;                  //mov [0x6502], al
    sub_276f();                                 //call sub_276f
}

void sub_39c7()
{
    if (memory(_ds, 25873) != 0x00)             //jnz loc_39d1
        goto loc_39d1;
    goto loc_3d96;                              //jmp loc_3d96
loc_39d1:                                       //loc_39d1:
    _es = memory16(_ds, 21100);                 //mov es, word ptr [0x526c]
    memory16(_ds, 25835) = 0x0028;              //mov word ptr [0x64eb], 0x28
    _si = 0x52a0;                               //mov si, 0x52a0
    _cl = 0x04;                                 //mov cl, 0x4
loc_39e0:                                       //loc_39e0:
    if (memory16(_ds, _si + 4) != 0xffff)   //jnz loc_39e9
        goto loc_39e9;
    goto loc_3d8a;                              //jmp loc_3d8a
loc_39e9:                                       //loc_39e9:
    _ax = memory16(_ds, _si);                   //mov ax, word ptr [si]
    if ((short)_ax > (short)0x0008)             //jg loc_39fa
        goto loc_39fa;
    memory16(_ds, _si + 6) = 0x0020;            //mov word ptr [si+0x6], 0x20
    memory16(_ds, _si + 14) = 0x0000;           //mov word ptr [si+0xe], 0x0
loc_39fa:                                       //loc_39fa:
    if ((short)_ax < (short)0x0ff8)             //jl loc_3a09
        goto loc_3a09;
    memory16(_ds, _si + 6) = 0xffe0;            //mov word ptr [si+0x6], 0xffe0
    memory16(_ds, _si + 14) = 0x0000;           //mov word ptr [si+0xe], 0x0
loc_3a09:                                       //loc_3a09:
    _ah = memory(_ds, _si + 4);                 //mov ah, byte ptr [si+0x4]
    _al = _ah;                                  //mov al, ah
    if (memory16(_ds, 25854) & 0x0003)          //jnz loc_3a42
        goto loc_3a42;
    if ((short)memory16(_ds, _si + 14) <= (short)0x0000)
        goto loc_3a42;
    if (memory(_ds, 25859) == 0x02)             //jz loc_3a42
        goto loc_3a42;
    _al -= 0x31;                                //sub al, 0x31
    if (_al == 0)                               //jz loc_3a30
        goto loc_3a30;
    _al -= 1;                                   //dec al
    if (_al != 0)                               //jnz loc_3a42
        goto loc_3a42;
    memory16(_ds, _si + 6) = 0x0000;            //mov word ptr [si+0x6], 0x0
loc_3a30:                                       //loc_3a30:
    _sar(memory16(_ds, _si + 6), 1);            //sar word ptr [si+0x6], 1
    memory16(_ds, _si + 4) += 1;                //inc word ptr [si+0x4]
    memory(_ds, 25859) = 0x01;                  //mov byte ptr [0x6503], 0x1
    memory(_ds, 25860) = 0xc8;                  //mov byte ptr [0x6504], 0xc8
    goto loc_3a85;                              //jmp loc_3a85
loc_3a42:                                       //loc_3a42:
    _ah -= 0x33;                                //sub ah, 0x33
    if (_ah > 0x01)                             //ja loc_3a85
        goto loc_3a85;
    memory(_ds, 25873) = 0x04;                  //mov byte ptr [0x6511], 0x4
    if (memory(_ds, 25859) == 0x00)             //jz loc_3a6f
        goto loc_3a6f;
    _dx = _dx ^ _dx;                            //xor dx, dx
    memory16(_ds, _si + 12) = _dx;              //mov word ptr [si+0xc], dx
    _ax = memory16(_ds, 0x527e);                //mov ax, [0x527e]
    _ax -= 0x0008;                              //sub ax, 0x8
    if (memory16(_ds, _si + 2) == _ax)          //jz loc_3a6c
        goto loc_3a6c;
    _dl = 0x10;                                 //mov dl, 0x10
    if ((short)memory16(_ds, _si + 2) < (short)_ax)//jl loc_3a6c
        goto loc_3a6c;
    _dx = -_dx;                                 //neg dx
loc_3a6c:                                       //loc_3a6c:
    memory16(_ds, _si + 14) = _dx;              //mov word ptr [si+0xe], dx
loc_3a6f:                                       //loc_3a6f:
    if (memory(_ds, 25860) != 0x00)             //jnz loc_3a85
        goto loc_3a85;
    memory16(_ds, _si + 4) = 0x0031;            //mov word ptr [si+0x4], 0x31
    memory16(_ds, _si + 6) = 0x0000;            //mov word ptr [si+0x6], 0x0
    memory(_ds, 25859) = 0x02;                  //mov byte ptr [0x6503], 0x2
loc_3a85:                                       //loc_3a85:
    if (memory16(_ds, _si + 6) != 0x0000)       //jnz loc_3a8e
        goto loc_3a8e;
    goto loc_3b25;                              //jmp loc_3b25
loc_3a8e:                                       //loc_3a8e:
    _ax = memory16(_ds, _si + 2);               //mov ax, word ptr [si+0x2]
    _sar(_ax, _cl);                             //sar ax, cl
    if (memory(_ds, _si + 2) & 0x0f)            //jnz loc_3a9a
        goto loc_3a9a;
    _ax -= 1;                                   //dec ax
loc_3a9a:                                       //loc_3a9a:
    _xchg(_al, _ah);                            //xchg al, ah
    _di = memory16(_ds, _si);                   //mov di, word ptr [si]
    _sar(_di, _cl);                             //sar di, cl
    _di += _ax;                                 //add di, ax
    _bx = 0x72a3;                               //mov bx, 0x72a3
    _al = memory(_es, _di);                     //mov al, byte ptr es:[di]
    _xlat();                                    //xlat
    _al &= 0x01;                                //and al, 0x1
    if (_al != 0)                               //jnz loc_3ade
        goto loc_3ade;
    _ax = memory16(_ds, _si);                   //mov ax, word ptr [si]
    _dx = memory16(_ds, _si + 6);               //mov dx, word ptr [si+0x6]
    _sar(_dx, _cl);                             //sar dx, cl
    _dx += _ax;                                 //add dx, ax
    _sar(_dx, _cl);                             //sar dx, cl
    _sar(_ax, _cl);                             //sar ax, cl
    if (_ax == _dx)                             //jz loc_3ae8
        goto loc_3ae8;
    _ax = 0x0001;                               //mov ax, 0x1
    if (!(memory(_ds, _si + 7) & 0x80))         //jz loc_3ac9
        goto loc_3ac9;
    _ax = -_ax;                                 //neg ax
loc_3ac9:                                       //loc_3ac9:
    _di += _ax;                                 //add di, ax
    _dx = memory16(_ds, _si);                   //mov dx, word ptr [si]
    _sar(_dx, _cl);                             //sar dx, cl
    _ax += _dx;                                 //add ax, dx
    if (_ax >= 0x0100)                          //jnc loc_3ade
        goto loc_3ade;
    _al = memory(_es, _di);                     //mov al, byte ptr es:[di]
    _xlat();                                    //xlat
    _al &= 0x01;                                //and al, 0x1
    if (_al == 0)                               //jz loc_3ae8
        goto loc_3ae8;
loc_3ade:                                       //loc_3ade:
    memory16(_ds, _si + 6) = -memory16(_ds, _si + 6);//neg word ptr [si+0x6]
    _ax = memory16(_ds, _si + 6);               //mov ax, word ptr [si+0x6]
    _sar(_ax, _cl);                             //sar ax, cl
    memory16(_ds, _si) += _ax;                  //add word ptr [si], ax
loc_3ae8:                                       //loc_3ae8:
    memory(_ds, 25873) = 0x04;                  //mov byte ptr [0x6511], 0x4
    _ax = memory16(_ds, _si + 14);              //mov ax, word ptr [si+0xe]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (!_flags.sign)                           //jns loc_3af6
        goto loc_3af6;
    _ax = -_ax;                                 //neg ax
loc_3af6:                                       //loc_3af6:
    _dx = 0x0003;                               //mov dx, 0x3
    if (_ax < 0x0010)                           //jc loc_3b00
        goto loc_3b00;
    _dl = 0x01;                                 //mov dl, 0x1
loc_3b00:                                       //loc_3b00:
    _ax = memory16(_ds, _si + 6);               //mov ax, word ptr [si+0x6]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (!_flags.sign)                           //jns loc_3b09
        goto loc_3b09;
    _dx = -_dx;                                 //neg dx
loc_3b09:                                       //loc_3b09:
    _bp = _ax;                                  //mov bp, ax
    _sar(_ax, _cl);                             //sar ax, cl
    memory16(_ds, _si) += _ax;                  //add word ptr [si], ax
    _ax = _bp;                                  //mov ax, bp
    _ax -= _dx;                                 //sub ax, dx
    _dx = _ax;                                  //mov dx, ax
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (!_flags.sign)                           //jns loc_3b1b
        goto loc_3b1b;
    _ax = -_ax;                                 //neg ax
loc_3b1b:                                       //loc_3b1b:
    if (_ax >= 0x0010)                          //jnc loc_3b22
        goto loc_3b22;
    _dx = _dx ^ _dx;                            //xor dx, dx
loc_3b22:                                       //loc_3b22:
    memory16(_ds, _si + 6) = _dx;               //mov word ptr [si+0x6], dx
loc_3b25:                                       //loc_3b25:
    _ax = memory16(_ds, _si + 2);               //mov ax, word ptr [si+0x2]
    _sar(_ax, _cl);                             //sar ax, cl
    memory16(_ds, 0x64ed) = _ax;                //mov [0x64ed], ax
    _xchg(_al, _ah);                            //xchg al, ah
    _di = memory16(_ds, _si);                   //mov di, word ptr [si]
    _sar(_di, _cl);                             //sar di, cl
    _di += _ax;                                 //add di, ax
    if ((short)memory16(_ds, _si + 14) >= (short)0x0000)
        goto loc_3b8a;
    _bx = memory16(_ds, _si + 4);               //mov bx, word ptr [si+0x4]
    _bh &= 0x1f;                                //and bh, 0x1f
    _bx <<= 1;                                  //shl bx, 1
    _al = memory(_ds, _bx + 27640);             //mov al, byte ptr [bx+0x6bf8]
    _al >>= _cl;                                //shr al, cl
    _cbw();                                     //cbw
    _ax += 1;                                   //inc ax
    _xchg(_al, _ah);                            //xchg al, ah
    _di -= _ax;                                 //sub di, ax
    _bx = 0x74a3;                               //mov bx, 0x74a3
    _al = memory(_es, _di);                     //mov al, byte ptr es:[di]
    _xlat();                                    //xlat
    _al &= 0x7f;                                //and al, 0x7f
    if (_al != 0)                               //jnz loc_3b78
        goto loc_3b78;
    _ax = memory16(_ds, _si + 14);              //mov ax, word ptr [si+0xe]
    _sar(_ax, _cl);                             //sar ax, cl
    _ax = _ax + memory16(_ds, _si + 2);         //add ax, word ptr [si+0x2]
    _ax = _ax - memory16(_ds, 25837);           //sub ax, word ptr [0x64ed]
    if (_ax != 0)                               //jnz loc_3b6b
        goto loc_3b6b;
    goto loc_3d5a;                              //jmp loc_3d5a
loc_3b6b:                                       //loc_3b6b:
    _al = memory(_es, (_di + 65280) & 0xffff);             //mov al, byte ptr es:[di+0xff00]
    _xlat();                                    //xlat
    _al &= 0x7f;                                //and al, 0x7f
    if (_al != 0)                               //jnz loc_3b78
        goto loc_3b78;
    goto loc_3d5a;                              //jmp loc_3d5a
loc_3b78:                                       //loc_3b78:
    memory16(_ds, _si + 14) = 0x0000;           //mov word ptr [si+0xe], 0x0
    _push(_si);                                 //push si
    sub_5133();                                 //call sub_5133
    if (!_flags.zero)                                //jnz loc_3b87
        goto loc_3b87;
    memory(_ds, _si + 2) &= 0xf0;               //and byte ptr [si+0x2], 0xf0
loc_3b87:                                       //loc_3b87:
    goto loc_3d8a;                              //jmp loc_3d8a
loc_3b8a:                                       //loc_3b8a:
    _ax = memory16(_ds, _si + 4);               //mov ax, word ptr [si+0x4]
    _dx = _ax;                                  //mov dx, ax
    _dh &= 0x1f;                                //and dh, 0x1f
    if (memory(_ds, _si + 11) & 0x01)           //jnz loc_3ba8
        goto loc_3ba8;
    _bx = _dx;                                  //mov bx, dx
    if (!(memory(_ds, _bx + 28441) & 0x08))     //jz loc_3bb8
        goto loc_3bb8;
    if ((short)memory16(_ds, _si + 14) < (short)0x00a0)
        goto loc_3bb8;
loc_3ba8:                                       //loc_3ba8:
    if (!(_ah & 0x20))                          //jz loc_3bb0
        goto loc_3bb0;
    goto loc_3d5a;                              //jmp loc_3d5a
loc_3bb0:                                       //loc_3bb0:
    memory16(_ds, _si + 4) = 0xffff;            //mov word ptr [si+0x4], 0xffff
    goto loc_3d8a;                              //jmp loc_3d8a
loc_3bb8:                                       //loc_3bb8:
    _bx = 0x72a3;                               //mov bx, 0x72a3
    _al = memory(_es, _di);                     //mov al, byte ptr es:[di]
    _ah = _al;                                  //mov ah, al
    _xlat();                                    //xlat
    _xchg(_ah, _al);                            //xchg ah, al
    _bx = 0x73a3;                               //mov bx, 0x73a3
    _xlat();                                    //xlat
    if ((short)memory16(_ds, _si + 2) > (short)0x0006)
        goto loc_3bd1;
    _al = _al ^ _al;                            //xor al, al
    goto loc_3be8;                              //jmp loc_3be8
loc_3bd1:                                       //loc_3bd1:
    _dl = memory(_ds, 20619);                   //mov dl, byte ptr [0x508b]
    _dh = _dh ^ _dh;                            //xor dh, dh
    _dx <<= _cl;                                //shl dx, cl
    if ((short)memory16(_ds, _si + 2) < (short)_dx)//jl loc_3be8
        goto loc_3be8;
    _al = _al ^ _al;                            //xor al, al
    _dx += 0x0040;                              //add dx, 0x40
    if ((short)memory16(_ds, _si + 2) >= (short)_dx)//jge loc_3bfe
        goto loc_3bfe;
loc_3be8:                                       //loc_3be8:
    if (_al == 0x09)                            //jz loc_3bfe
        goto loc_3bfe;
    if (_al != 0x08)                            //jnz loc_3c03
        goto loc_3c03;
    _dx = memory16(_ds, _si + 4);               //mov dx, word ptr [si+0x4]
    _dh &= 0x1f;                                //and dh, 0x1f
    if (_dx != 0x0027)                          //jnz loc_3bfe
        goto loc_3bfe;
    goto loc_3b78;                              //jmp loc_3b78
loc_3bfe:                                       //loc_3bfe:
    memory16(_ds, _si + 4) = 0xffff;            //mov word ptr [si+0x4], 0xffff
loc_3c03:                                       //loc_3c03:
    if (_al == 0x06)                            //jz loc_3c13
        goto loc_3c13;
    _ah &= 0x01;                                //and ah, 0x1
    _al |= _ah;                                 //or al, ah
    _al &= 0x07;                                //and al, 0x7
    if (_al == 0)                               //jz loc_3c13
        goto loc_3c13;
    goto loc_3b78;                              //jmp loc_3b78
loc_3c13:                                       //loc_3c13:
    _dx = memory16(_ds, _si + 14);              //mov dx, word ptr [si+0xe]
    _sar(_dx, _cl);                             //sar dx, cl
    _dx = _dx + memory16(_ds, _si + 2);         //add dx, word ptr [si+0x2]
    _sar(_dx, _cl);                             //sar dx, cl
    _dx = _dx - memory16(_ds, 25837);           //sub dx, word ptr [0x64ed]
    if (_dx == 0)                               //jz loc_3c70
        goto loc_3c70;
    memory16(_ds, 25837) = _dx;                 //mov word ptr [0x64ed], dx
    _push(_bx);                                 //push bx
    _bx = memory16(_ds, _si + 4);               //mov bx, word ptr [si+0x4]
    sub_5045();                                 //call sub_5045
    _bx = _pop();                               //pop bx
    if (_flags.carry)                                //jc loc_3c7b
        goto loc_3c7b;
    _dx = memory16(_ds, 25837);                 //mov dx, word ptr [0x64ed]
loc_3c35:                                       //loc_3c35:
    _di += 0x0100;                              //add di, 0x100
    _al = memory(_es, _di);                     //mov al, byte ptr es:[di]
    _push(_bx);                                 //push bx
    _bx = 0x72a3;                               //mov bx, 0x72a3
    _ah = _al;                                  //mov ah, al
    _xlat();                                    //xlat
    _xchg(_ah, _al);                            //xchg ah, al
    _bx = _pop();                               //pop bx
    _xlat();                                    //xlat
    if (_al == 0x09)                            //jz loc_3bfe
        goto loc_3bfe;
    if (_al != 0x08)                            //jnz loc_3c5d
        goto loc_3c5d;
    _dx = memory16(_ds, _si + 4);               //mov dx, word ptr [si+0x4]
    _dh &= 0x1f;                                //and dh, 0x1f
    if (_dx != 0x0027)                          //jnz loc_3c5d
        goto loc_3c5d;
    goto loc_3ced;                              //jmp loc_3ced
loc_3c5d:                                       //loc_3c5d:
    if (_al == 0x06)                            //jz loc_3c6d
        goto loc_3c6d;
    _ah &= 0x01;                                //and ah, 0x1
    _al |= _ah;                                 //or al, ah
    _al &= 0x07;                                //and al, 0x7
    if (_al == 0)                               //jz loc_3c6d
        goto loc_3c6d;
    goto loc_3ced;                              //jmp loc_3ced
loc_3c6d:                                       //loc_3c6d:
    _dx -= 1;                                   //dec dx
    if (_dx != 0)                               //jnz loc_3c35
        goto loc_3c35;
loc_3c70:                                       //loc_3c70:
    _bx = memory16(_ds, _si + 4);               //mov bx, word ptr [si+0x4]
    sub_5045();                                 //call sub_5045
    if (_flags.carry)                                //jc loc_3c7b
        goto loc_3c7b;
    goto loc_3d5a;                              //jmp loc_3d5a
loc_3c7b:                                       //loc_3c7b:
    memory16(_ds, _si + 12) = 0x0000;           //mov word ptr [si+0xc], 0x0
    _di = _ax;                                  //mov di, ax
    _push(_si);                                 //push si
    sub_5133();                                 //call sub_5133
    if (!_flags.zero)                                //jnz loc_3cd4
        goto loc_3cd4;
    _push(_di);                                 //push di
    sub_5133();                                 //call sub_5133
    if (!_flags.zero)                                //jnz loc_3c9e
        goto loc_3c9e;
    memory16(_ds, _si + 2) = _dx;               //mov word ptr [si+0x2], dx
    memory16(_ds, _si + 14) = 0x0000;           //mov word ptr [si+0xe], 0x0
    memory16(_ds, _si + 12) = 0x0000;           //mov word ptr [si+0xc], 0x0
    goto loc_3d8a;                              //jmp loc_3d8a
loc_3c9e:                                       //loc_3c9e:
    memory(_ds, _di + 8) |= 0x01;               //or byte ptr [di+0x8], 0x1
    memory16(_ds, _di + 9) = _si;               //mov word ptr [di+0x9], si
    _ax = memory16(_ds, _si + 14);              //mov ax, word ptr [si+0xe]
    _ax = -_ax;                                 //neg ax
    _sar(_ax, 1);                               //sar ax, 1
    _bx = _ax;                                  //mov bx, ax
    _flags.sign = (short)(_ax + 0x0010) < 0;    //add ax, 0x10
    _ax += 0x0010;
    if (!_flags.sign)                           //jns loc_3cb8
        goto loc_3cb8;
    _flags.sign = (short)(_bx + 0x0020) < 0;    //add bx, 0x20
    _bx += 0x0020;
    if (_flags.sign)                            //js loc_3cc3
        goto loc_3cc3;
loc_3cb8:                                       //loc_3cb8:
    memory16(_ds, _si + 14) = 0x0000;           //mov word ptr [si+0xe], 0x0
    memory16(_ds, _si + 2) = _dx;               //mov word ptr [si+0x2], dx
    goto loc_3d8a;                              //jmp loc_3d8a
loc_3cc3:                                       //loc_3cc3:
    memory16(_ds, _di + 14) = _bx;              //mov word ptr [di+0xe], bx
    memory16(_ds, _si + 14) = _ax;              //mov word ptr [si+0xe], ax
    _ax = memory16(_ds, _si + 6);               //mov ax, word ptr [si+0x6]
    _sar(_ax, 1);                               //sar ax, 1
    memory16(_ds, _di + 6) = _ax;               //mov word ptr [di+0x6], ax
    goto loc_3d5a;                              //jmp loc_3d5a
loc_3cd4:                                       //loc_3cd4:
    _push(_di);                                 //push di
    sub_5133();                                 //call sub_5133
    if (!_flags.zero)                                //jnz loc_3ceb
        goto loc_3ceb;
    memory16(_ds, _si + 2) = _dx;               //mov word ptr [si+0x2], dx
    if (memory16(_ds, _si + 14) >= 0x0010)      //jnc loc_3d3f
        goto loc_3d3f;
    memory16(_ds, _si + 14) = 0x0000;           //mov word ptr [si+0xe], 0x0
    goto loc_3d8a;                              //jmp loc_3d8a
loc_3ceb:                                       //loc_3ceb:
    goto loc_3c9e;                              //jmp loc_3c9e
loc_3ced:                                       //loc_3ced:
    _push(_si);                                 //push si
    sub_5133();                                 //call sub_5133
    if (!_flags.zero)                                //jnz loc_3d37
        goto loc_3d37;
    memory16(_ds, _si + 14) = 0x0000;           //mov word ptr [si+0xe], 0x0
    memory(_ds, _si + 2) &= 0xf0;               //and byte ptr [si+0x2], 0xf0
    memory16(_ds, _si + 2) += 0x0010;           //add word ptr [si+0x2], 0x10
    _al = memory(_ds, _si + 4);                 //mov al, byte ptr [si+0x4]
    _al -= 0x31;                                //sub al, 0x31
    if (_al > 0x03)                             //ja loc_3d12
        goto loc_3d12;
    memory(_ds, _si + 4) = 0x31;                //mov byte ptr [si+0x4], 0x31
    memory(_ds, 25859) = 0x00;                  //mov byte ptr [0x6503], 0x0
loc_3d12:                                       //loc_3d12:
    if (!(memory(_ds, _si + 5) & 0x20))         //jz loc_3d8a
        goto loc_3d8a;
    if (memory16(_ds, 21138) != 0xffff)     //jnz loc_3d8a
        goto loc_3d8a;
    memory(_ds, 25861) = 0x20;                  //mov byte ptr [0x6505], 0x20
    _ax = memory16(_ds, _si + 2);               //mov ax, word ptr [si+0x2]
    memory16(_ds, 0x5290) = _ax;                //mov [0x5290], ax
    _ax = memory16(_ds, _si);                   //mov ax, word ptr [si]
    memory16(_ds, 0x528e) = _ax;                //mov [0x528e], ax
    memory16(_ds, 21138) = 0x002e;              //mov word ptr [0x5292], 0x2e
    goto loc_3d8a;                              //jmp loc_3d8a
loc_3d37:                                       //loc_3d37:
    memory(_ds, _si + 2) &= 0xf0;               //and byte ptr [si+0x2], 0xf0
    memory16(_ds, _si + 2) += 0x0010;           //add word ptr [si+0x2], 0x10
loc_3d3f:                                       //loc_3d3f:
    memory(_ds, 25873) = 0x04;                  //mov byte ptr [0x6511], 0x4
    memory16(_ds, _si + 12) = 0x0000;           //mov word ptr [si+0xc], 0x0
    _ax = memory16(_ds, _si + 14);              //mov ax, word ptr [si+0xe]
    _ax = -_ax;                                 //neg ax
    _ax += 0x0030;                              //add ax, 0x30
    if ((short)_ax < (short)0)            //jl loc_3d55
        goto loc_3d55;
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_3d55:                                       //loc_3d55:
    memory16(_ds, _si + 14) = _ax;              //mov word ptr [si+0xe], ax
    goto loc_3d8a;                              //jmp loc_3d8a
loc_3d5a:                                       //loc_3d5a:
    _dl = 0x0f;                                 //mov dl, 0xf
    _bx = memory16(_ds, _si + 4);               //mov bx, word ptr [si+0x4]
    _bh &= 0x1f;                                //and bh, 0x1f
    if (_bl >= 0x65)                            //jnc loc_3d6b
        goto loc_3d6b;
    _dl = memory(_ds, _bx + 28512);             //mov dl, byte ptr [bx+0x6f60]
loc_3d6b:                                       //loc_3d6b:
    _ax = memory16(_ds, _si + 14);              //mov ax, word ptr [si+0xe]
    _sar(_ax, _cl);                             //sar ax, cl
    if (_ax == 0)                                //jz loc_3d77
        goto loc_3d77;
    memory(_ds, 25873) = 0x04;                  //mov byte ptr [0x6511], 0x4
loc_3d77:                                       //loc_3d77:
    memory16(_ds, _si + 2) += _ax;              //add word ptr [si+0x2], ax
    if ((char)_al >= (char)_dl)                 //jge loc_3d87
        goto loc_3d87;
    memory16(_ds, _si + 14) += 0x0010;          //add word ptr [si+0xe], 0x10
    if ((short)memory16(_ds, _si + 14) <= (short)0)
        goto loc_3d87;
    memory16(_ds, _si + 12) += 1;               //inc word ptr [si+0xc]
loc_3d87:                                       //loc_3d87:
    sub_3d97();                                 //call sub_3d97
loc_3d8a:                                       //loc_3d8a:
    _si += 0x0012;                              //add si, 0x12
    memory16(_ds, 25835) -= 1;                  //dec word ptr [0x64eb]
    if (memory16(_ds, 25835) == 0)              //jz loc_3d96
        goto loc_3d96;
    goto loc_39e0;                              //jmp loc_39e0
loc_3d96:                                       //loc_3d96:
    return;
}

void sub_3d97()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_dx);                                 //push dx
    if (memory16(_ds, _si + 12) >= 0x000a)      //jnc loc_3da3
        goto loc_3da3;
    goto loc_3e24;                              //jmp loc_3e24
loc_3da3:                                       //loc_3da3:
    if ((short)memory16(_ds, 21130) >= (short)0x00c0)//jge loc_3e24
        goto loc_3e24;
    _ax = memory16(_ds, 0x527e);                //mov ax, [0x527e]
    _ax = _ax - memory16(_ds, _si + 2);         //sub ax, word ptr [si+0x2]
    if ((short)_ax >= 0)                        //jns loc_3db5
        goto loc_3db5;
    _ax = -_ax;                                 //neg ax
loc_3db5:                                       //loc_3db5:
    if (_ax >= 0x0020)                          //jnc loc_3e24
        goto loc_3e24;
    _ax = memory16(_ds, 0x527c);                //mov ax, [0x527c]
    _ax = _ax - memory16(_ds, _si);             //sub ax, word ptr [si]
    if ((short)_ax >= 0)                        //jns loc_3dc3
        goto loc_3dc3;
    _ax = -_ax;                                 //neg ax
loc_3dc3:                                       //loc_3dc3:
    if (_ax >= 0x0020)                          //jnc loc_3e24
        goto loc_3e24;
    _bx = memory16(_ds, _si + 4);               //mov bx, word ptr [si+0x4]
    _bh &= 0x1f;                                //and bh, 0x1f
    _bx <<= 1;                                  //shl bx, 1
    _bl = memory(_ds, _bx + 27639);             //mov bl, byte ptr [bx+0x6bf7]
    _ax = memory16(_ds, _si);                   //mov ax, word ptr [si]
    _dx = memory16(_ds, 21116);                 //mov dx, word ptr [0x527c]
    if ((short)_ax <= (short)_dx)               //jle loc_3de1
        goto loc_3de1;
    _xchg(_ax, _dx);                            //xchg ax, dx
    _bl = 0x18;                                 //mov bl, 0x18
loc_3de1:                                       //loc_3de1:
    _bh = _bh ^ _bh;                            //xor bh, bh
    _ax += _bx;                                 //add ax, bx
    if ((short)_ax < (short)_dx)                //jl loc_3e24
        goto loc_3e24;
    _ax = memory16(_ds, _si + 2);               //mov ax, word ptr [si+0x2]
    _dx = memory16(_ds, 21118);                 //mov dx, word ptr [0x527e]
    _bx = memory16(_ds, _si + 4);               //mov bx, word ptr [si+0x4]
    _bh &= 0x1f;                                //and bh, 0x1f
    _bx <<= 1;                                  //shl bx, 1
    _bl = memory(_ds, _bx + 27640);             //mov bl, byte ptr [bx+0x6bf8]
    _bl -= 1;                                   //dec bl
    if ((short)_ax >= (short)_dx)               //jge loc_3e05
        goto loc_3e05;
    _xchg(_ax, _dx);                            //xchg ax, dx
    _bl = 0x20;                                 //mov bl, 0x20
loc_3e05:                                       //loc_3e05:
    _bh = _bh ^ _bh;                            //xor bh, bh
    _ax -= _bx;                                 //sub ax, bx
    if ((short)_ax >= (short)_dx)               //jge loc_3e24
        goto loc_3e24;
    _al = 0x05;                                 //mov al, 0x5
    sub_11e6();                                 //call sub_11e6
    memory(_ds, 25875) = 0x18;                  //mov byte ptr [0x6513], 0x18
    if (!(memory(_ds, _si + 11) & 0x02))        //jz loc_3e24
        goto loc_3e24;
    sub_59cc();                                 //call sub_59cc
    memory(_ds, _si + 11) &= 0xfd;              //and byte ptr [si+0xb], 0xfd
loc_3e24:                                       //loc_3e24:
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_3e28()
{
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _bp = 0xffff;                               //mov bp, 0xffff
    memory16(_ds, 22092) = _bp;                 //mov word ptr [0x564c], bp
    memory16(_ds, 22110) = _bp;                 //mov word ptr [0x565e], bp
    memory16(_ds, 22128) = _bp;                 //mov word ptr [0x5670], bp
    memory16(_ds, 22146) = _bp;                 //mov word ptr [0x5682], bp
    _si = 0x7dcb;                               //mov si, 0x7dcb
    _di = 0x5648;                               //mov di, 0x5648
    _ax = memory16(_ds, 0x5270);                //mov ax, [0x5270]
    _dx = memory16(_ds, 21106);                 //mov dx, word ptr [0x5272]
    _cl = 0x04;                                 //mov cl, 0x4
    _ax <<= _cl;                                //shl ax, cl
    _dx <<= _cl;                                //shl dx, cl
    _cx = 0x000a;                               //mov cx, 0xa
loc_3e56:                                       //loc_3e56:
    if (memory16(_ds, _si + 4) == _bp)          //jz loc_3ec7
        goto loc_3ec7;
    _push(_ax);                                 //push ax
    _push(_dx);                                 //push dx
    _al = memory(_ds, _si + 7);                 //mov al, byte ptr [si+0x7]
    _cbw();                                     //cbw
    _dl = memory(_ds, _si + 6);                 //mov dl, byte ptr [si+0x6]
    if (_dl != 0x00)                            //jnz loc_3e6e
        goto loc_3e6e;
    memory16(_ds, _si + 2) -= _ax;              //sub word ptr [si+0x2], ax
    goto loc_3ed0;                              //jmp loc_3ed0
loc_3e6e:                                       //loc_3e6e:
    if (_dl != 0x02)                            //jnz loc_3e78
        goto loc_3e78;
    memory16(_ds, _si + 2) += _ax;              //add word ptr [si+0x2], ax
    goto loc_3ed0;                              //jmp loc_3ed0
loc_3e78:                                       //loc_3e78:
    if (_dl != 0x01)                            //jnz loc_3e81
        goto loc_3e81;
    memory16(_ds, _si) += _ax;                  //add word ptr [si], ax
    goto loc_3ed0;                              //jmp loc_3ed0
loc_3e81:                                       //loc_3e81:
    if (_dl != 0x03)                            //jnz loc_3e8a
        goto loc_3e8a;
    memory16(_ds, _si) -= _ax;                  //sub word ptr [si], ax
    goto loc_3ed0;                              //jmp loc_3ed0
loc_3e8a:                                       //loc_3e8a:
    _dx = _pop();                               //pop dx
    _ax = _pop();                               //pop ax
    _bx = memory16(_ds, _si);                   //mov bx, word ptr [si]
    _bx += 0x0010;                              //add bx, 0x10
    _flags.carry = _bx < _ax;                   //sub bx, ax
    _bx -= _ax;
    if (_flags.carry)                           //jc loc_3ec7
        goto loc_3ec7;
    _bx -= 0x0020;                              //sub bx, 0x20
    if ((short)_bx > (short)0x0140)             //jg loc_3ec7
        goto loc_3ec7;
    _bx = memory16(_ds, _si + 2);               //mov bx, word ptr [si+0x2]
    _flags.carry = _bx < _dx;                   //sub bx, dx
    _bx -= _dx;
    if (_flags.carry)                           //jc loc_3ec7
        goto loc_3ec7;
    _bx -= 0x0010;                              //sub bx, 0x10
    if ((short)_bx > (short)0x00c0)             //jg loc_3ec7
        goto loc_3ec7;
    _bx = memory16(_ds, _si + 4);               //mov bx, word ptr [si+0x4]
    _bx += 0x001e;                              //add bx, 0x1e
    memory16(_ds, _di + 4) = _bx;               //mov word ptr [di+0x4], bx
    _bx = memory16(_ds, _si);                   //mov bx, word ptr [si]
    memory16(_ds, _di) = _bx;                   //mov word ptr [di], bx
    _bx = memory16(_ds, _si + 2);               //mov bx, word ptr [si+0x2]
    memory16(_ds, _di + 2) = _bx;               //mov word ptr [di+0x2], bx
    memory16(_ds, _di + 9) = _si;               //mov word ptr [di+0x9], si
    _di += 0x0012;                              //add di, 0x12
loc_3ec7:                                       //loc_3ec7:
    _si += 0x0014;                              //add si, 0x14
    _cx -= 1;                                   //dec cx
    if (_cx == 0)                               //jz loc_3ecf
        goto loc_3ecf;
    goto loc_3e56;                              //jmp loc_3e56
loc_3ecf:                                       //loc_3ecf:
    return;                                     //ret
loc_3ed0:                                       //loc_3ed0:
    memory16(_ds, _si + 17) += 1;               //inc word ptr [si+0x11]
    _ax = memory16(_ds, _si + 17);              //mov ax, word ptr [si+0x11]
    if (memory16(_ds, _si + 10) != _ax)         //jnz loc_3e8a
        goto loc_3e8a;
    _dl = _dl ^ 0x02;                           //xor dl, 0x2
    memory16(_ds, _si + 17) = 0x0000;           //mov word ptr [si+0x11], 0x0
    memory(_ds, _si + 6) = _dl;                 //mov byte ptr [si+0x6], dl
    goto loc_3e8a;                              //jmp loc_3e8a
}

void sub_3ee8()
{
    _push(_bx);                                 //push bx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _di = 0x527c;                               //mov di, 0x527c
    _cx = 0x020a;                               //mov cx, 0x20a
    _ax = _ax ^ _ax;                            //xor ax, ax
    _rep_stosw<MemData, DirForward>();          //rep stosw
    _di = 0x527c;                               //mov di, 0x527c
    _cx = 0x003a;                               //mov cx, 0x3a
loc_3f02:                                       //loc_3f02:
    memory16(_ds, _di + 4) = 0xffff;            //mov word ptr [di+0x4], 0xffff
    _di += 0x0012;                              //add di, 0x12
    if (--_cx)                                  //loop loc_3f02
        goto loc_3f02;
    _si = 0x52a0;                               //mov si, 0x52a0
    _di = 0x75a3;                               //mov di, 0x75a3
    _cx = 0x0028;                               //mov cx, 0x28
loc_3f15:                                       //loc_3f15:
    _ax = memory16(_ds, _di);                   //mov ax, word ptr [di]
    memory16(_ds, _si + 4) = _ax;               //mov word ptr [si+0x4], ax
    _ax = memory16(_ds, _di + 2);               //mov ax, word ptr [di+0x2]
    memory16(_ds, _si) = _ax;                   //mov word ptr [si], ax
    _ax = memory16(_ds, _di + 4);               //mov ax, word ptr [di+0x4]
    memory16(_ds, _si + 2) = _ax;               //mov word ptr [si+0x2], ax
    memory(_ds, _si + 11) = 0x00;               //mov byte ptr [si+0xb], 0x0
    _si += 0x0012;                              //add si, 0x12
    _di += 0x0006;                              //add di, 0x6
    if (--_cx)                                  //loop loc_3f15
        goto loc_3f15;
    memory(_ds, 25873) = 0x04;                  //mov byte ptr [0x6511], 0x4
    _ax = memory16(_ds, 0x7695);                //mov ax, [0x7695]
    memory16(_ds, 0x527c) = _ax;                //mov [0x527c], ax
    _ax = memory16(_ds, 0x7697);                //mov ax, [0x7697]
    memory16(_ds, 0x527e) = _ax;                //mov [0x527e], ax
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _bx = _pop();                               //pop bx
}

void sub_3f46()
{
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    memory(_ds, 25852) += 1;                    //inc byte ptr [0x64fc]
    if (memory(_ds, 25852) & 0x03)              //jnz loc_3f66
        goto loc_3f66;
    _ax = memory16(_ds, 0x64f6);                //mov ax, [0x64f6]
    _ah += 1;                                   //inc ah
    if (_ax != 0x63e4)                          //jnz loc_3f63
        goto loc_3f63;
    _ah -= 0x03;                                //sub ah, 0x3
loc_3f63:                                       //loc_3f63:
    memory16(_ds, 0x64f6) = _ax;                //mov [0x64f6], ax
loc_3f66:                                       //loc_3f66:
    if (memory(_ds, 25858) != 0x00)             //jnz loc_3f73
        goto loc_3f73;
    sub_403c();                                 //call sub_403c
    sub_3f74();                                 //call sub_3f74
loc_3f73:                                       //loc_3f73:
    return;
}

void sub_3f74()
{
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    if (memory16(_ds, 21130) != 0x0000)         //jnz loc_3f85
        goto loc_3f85;
    memory(_ds, 25889) = 0x00;                  //mov byte ptr [0x6521], 0x0
loc_3f85:                                       //loc_3f85:
    _dx = memory16(_ds, 21118);                 //mov dx, word ptr [0x527e]
    _cl = 0x04;                                 //mov cl, 0x4
    _sar(_dx, _cl);                             //sar dx, cl
    _dx = _dx - memory16(_ds, 21106);           //sub dx, word ptr [0x5272]
    if (memory(_ds, 25889) != 0x00)             //jnz loc_3fcf
        goto loc_3fcf;
    if (memory16(_ds, 21130) != 0x0000)         //jnz loc_3fa6
        goto loc_3fa6;
    if (memory(_ds, 25869) == 0x00)             //jz loc_3fb8
        goto loc_3fb8;
loc_3fa6:                                       //loc_3fa6:
    _ax = 0x0003;                               //mov ax, 0x3
    if ((short)_dx >= (short)0x000a)            //jge loc_3fc8
        goto loc_3fc8;
    _ax = 0x0009;                               //mov ax, 0x9
    if ((short)_dx > (short)0x0002)             //jg loc_3fcf
        goto loc_3fcf;
    goto loc_3fc8;                              //jmp loc_3fc8
loc_3fb8:                                       //loc_3fb8:
    _ax = 0x000a;                               //mov ax, 0xa
    if ((short)_dx >= (short)0x000b)            //jge loc_3fc8
        goto loc_3fc8;
    _ax = 0x0009;                               //mov ax, 0x9
    if ((short)_dx > (short)0x0002)             //jg loc_3fcf
        goto loc_3fcf;
loc_3fc8:                                       //loc_3fc8:
    memory16(_ds, 0x6524) = _ax;                //mov [0x6524], ax
    memory(_ds, 25889) += 1;                    //inc byte ptr [0x6521]
loc_3fcf:                                       //loc_3fcf:
    _ax = memory16(_ds, 0x7693);                //mov ax, [0x7693]
    _ax += 0x000c;                              //add ax, 0xc
    _ax <<= _cl;                                //shl ax, cl
    if (memory16(_ds, 21118) > _ax)             //ja loc_3fe8
        goto loc_3fe8;
    _bx = memory16(_ds, 21106);                 //mov bx, word ptr [0x5272]
    _bx -= 1;                                   //dec bx
    if ((short)memory16(_ds, 30355) < (short)_bx)//jl loc_4031
        goto loc_4031;
loc_3fe8:                                       //loc_3fe8:
    _ax = memory16(_ds, 0x7693);                //mov ax, [0x7693]
    _ax = _ax - memory16(_ds, 21106);           //sub ax, word ptr [0x5272]
    if (_ax >= 0x0005)                          //jnc loc_4005
        goto loc_4005;
    _ax = memory16(_ds, 0x7693);                //mov ax, [0x7693]
    _ax += 0x000c;                              //add ax, 0xc
    _ax <<= _cl;                                //shl ax, cl
    _ax = _ax - memory16(_ds, 21118);           //sub ax, word ptr [0x527e]
    if (_ax < 0x0070)                           //jc loc_402a
        goto loc_402a;
loc_4005:                                       //loc_4005:
    if (memory(_ds, 25889) == 0x00)             //jz loc_403b
        goto loc_403b;
    if (memory16(_ds, 25892) == _dx)            //jz loc_4036
        goto loc_4036;
    if ((short)memory16(_ds, 25892) > (short)_dx)//jg loc_4031
        goto loc_4031;
    _ax = memory16(_ds, 0x7693);                //mov ax, [0x7693]
    _dx = _ax;                                  //mov dx, ax
    _dx += 0x000c;                              //add dx, 0xc
    _dx <<= _cl;                                //shl dx, cl
    if (memory16(_ds, 21118) > _dx)             //ja loc_402a
        goto loc_402a;
    if (memory16(_ds, 21106) > _ax)             //ja loc_4036
        goto loc_4036;
loc_402a:                                       //loc_402a:
    sub_294c();                                 //call sub_294c
    if (_flags.carry)                                //jc loc_4036
        goto loc_4036;
    goto loc_403b;                              //jmp loc_403b
loc_4031:                                       //loc_4031:
    sub_2911();                                 //call sub_2911
    if (_FIXME_)                                //jnc loc_403b
        goto loc_403b;
loc_4036:                                       //loc_4036:
    memory(_ds, 25889) = 0x00;                  //mov byte ptr [0x6521], 0x0
loc_403b:                                       //loc_403b:
    return;
}

void sub_403c()
{
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _dx = memory16(_ds, 21116);                 //mov dx, word ptr [0x527c]
    _cl = 0x04;                                 //mov cl, 0x4
    _sar(_dx, _cl);                             //sar dx, cl
    _dx = _dx - memory16(_ds, 21104);           //sub dx, word ptr [0x5270]
    if (memory(_ds, 25888) == 0x00)             //jz loc_4057
        goto loc_4057;
    goto loc_40d7;                              //jmp loc_40d7
loc_4057:                                       //loc_4057:
    if (memory16(_ds, 25886) < 0x0016)          //jc loc_40c6
        goto loc_40c6;
    _al = memory(_ds, 0x5287);                  //mov al, [0x5287]
    _al &= 0x0f;                                //and al, 0xf
    if (_al != 0x01)                            //jnz loc_40a1
        goto loc_40a1;
    _ax = memory16(_ds, 0x5282);                //mov ax, [0x5282]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (!_flags.sign)                           //jns loc_4070
        goto loc_4070;
    _ax = -_ax;                                 //neg ax
loc_4070:                                       //loc_4070:
    if (_ax == 0x0040)                          //jz loc_407e
        goto loc_407e;
    if ((short)memory16(_ds, 21120) < (short)0x0000)//jl loc_409c
        goto loc_409c;
    goto loc_408a;                              //jmp loc_408a
loc_407e:                                       //loc_407e:
    if ((short)memory16(_ds, 21122) < 0 /*CHECK*/)//js loc_4097
        goto loc_4097;
    if ((short)_dx < (short)0x000d)             //jl loc_40d7
        goto loc_40d7;
loc_408a:                                       //loc_408a:
    _ax = 0x0002;                               //mov ax, 0x2
loc_408d:                                       //loc_408d:
    memory16(_ds, 0x6522) = _ax;                //mov [0x6522], ax
    memory(_ds, 25888) = 0x01;                  //mov byte ptr [0x6520], 0x1
    goto loc_40d7;                              //jmp loc_40d7
loc_4097:                                       //loc_4097:
    if ((short)_dx > (short)0x0007)             //jg loc_40d7
        goto loc_40d7;
loc_409c:                                       //loc_409c:
    _ax = 0x0012;                               //mov ax, 0x12
    goto loc_408d;                              //jmp loc_408d
loc_40a1:                                       //loc_40a1:
    _ax = memory16(_ds, 0x5282);                //mov ax, [0x5282]
    _ax = _ax | memory16(_ds, 21130);           //or ax, word ptr [0x528a]
    if (_ax != 0)                               //jnz loc_40c6
        goto loc_40c6;
    if (memory16(_ds, 25886) != 0x0021)         //jnz loc_40c6
        goto loc_40c6;
    sub_40fa();                                 //call sub_40fa
    memory16(_ds, 0x6522) = _ax;                //mov [0x6522], ax
    goto loc_40bf;                              //jmp loc_40bf
loc_40b9:                                       //loc_40b9:
    memory16(_ds, 25890) = 0x000a;              //mov word ptr [0x6522], 0xa
loc_40bf:                                       //loc_40bf:
    memory(_ds, 25888) = 0x01;                  //mov byte ptr [0x6520], 0x1
    goto loc_40d7;                              //jmp loc_40d7
loc_40c6:                                       //loc_40c6:
    if (memory(_ds, 25888) != 0x00)             //jnz loc_40d7
        goto loc_40d7;
    if ((short)_dx > (short)0x0012)             //jg loc_40b9
        goto loc_40b9;
    if ((short)_dx < (short)0x0002)             //jl loc_40b9
        goto loc_40b9;
loc_40d7:                                       //loc_40d7:
    if (memory(_ds, 25888) == 0x00)             //jz loc_40f9
        goto loc_40f9;
    if (memory16(_ds, 25890) == _dx)            //jz loc_40f4
        goto loc_40f4;
    if ((short)memory16(_ds, 25890) > (short)_dx)//jg loc_40ed
        goto loc_40ed;
    sub_29b5();                                 //call sub_29b5
    if (_FIXME_)                                //jc loc_40f4
        goto loc_40f4;
    goto loc_40f9;                              //jmp loc_40f9
loc_40ed:                                       //loc_40ed:
    sub_2994();                                 //call sub_2994
    if (_flags.carry)                           //jc loc_40f4
        goto loc_40f4;
    goto loc_40f9;                              //jmp loc_40f9
loc_40f4:                                       //loc_40f4:
    memory(_ds, 25888) = 0x00;                  //mov byte ptr [0x6520], 0x0
loc_40f9:                                       //loc_40f9:
    return;
}

void sub_40fa()
{
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_si);                                 //push si
    _dx = memory16(_ds, 21116);                 //mov dx, word ptr [0x527c]
    _si = 0x5570;                               //mov si, 0x5570
    _cx = 0x0008;                               //mov cx, 0x8
    _ax = 0x000a;                               //mov ax, 0xa
loc_410b:                                       //loc_410b:
    if (memory16(_ds, _si + 4) == 0xffff)   //jz loc_4133
        goto loc_4133;
    _bx = _bx ^ _bx;                            //xor bx, bx
    _bl = _bl + 0x00 + _flags.carry; _ASSERT(0);//adc bl, 0x0
    _bh = memory(_ds, 21121);                   //mov bh, byte ptr [0x5281]
    _rol(_bh, 1);                               //rol bh, 1
    _bh &= 0x01;                                //and bh, 0x1
    _bl = _bl ^ _bh;                            //xor bl, bh
    if (_bl == 0)                               //jz loc_4133
        goto loc_4133;
    _bx = memory16(_ds, _si);                   //mov bx, word ptr [si]
    _bx -= _dx;                                 //sub bx, dx
    if ((short)_bx >= 0)                        //jns loc_412d
        goto loc_412d;
    _bx = -_bx;                                 //neg bx
loc_412d:                                       //loc_412d:
    if (_bx < 0x00c8)                           //jc loc_4146
        goto loc_4146;
loc_4133:                                       //loc_4133:
    _si += 0x0012;                              //add si, 0x12
    if (--_cx)                                  //loop loc_410b
        goto loc_410b;
    _ax = 0x0003;                               //mov ax, 0x3
    if (!(memory16(_ds, 21121) & 0x0080))       //jz loc_4146
        goto loc_4146;
    _ax = 0x0011;                               //mov ax, 0x11
loc_4146:                                       //loc_4146:
    _si = _pop();                               //pop si
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
}

void sub_414b()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    if (memory(_ds, 25878) != 0x00)             //jnz loc_4171
        goto loc_4171;
    if (memory(_ds, 1147) == 0x00)              //jz loc_4171
        goto loc_4171;
    sub_4dc0();                                 //call sub_4dc0
    memory(_ds, 25878) -= 1;                    //dec byte ptr [0x6516]
    goto loc_447a;                              //jmp loc_447a
loc_4171:                                       //loc_4171:
    if (memory(_ds, 1148) == 0x00)              //jz loc_4187
        goto loc_4187;
    memory(_ds, 25879) = 0x01;                  //mov byte ptr [0x6517], 0x1
loc_417d:                                       //loc_417d:
    if (memory(_ds, 1148) == 0x00)              //jz loc_417d
        goto loc_417d;
    goto loc_447a;                              //jmp loc_447a
loc_4187:                                       //loc_4187:
    if (memory(_ds, 1106) == 0x00)              //jz loc_4193
        goto loc_4193;
    memory(_ds, 25862) = 0x32;                  //mov byte ptr [0x6506], 0x32
loc_4193:                                       //loc_4193:
    if (memory(_ds, 1150) == 0x00)              //jz loc_41ad
        goto loc_41ad;
loc_419a:                                       //loc_419a:
    if (memory(_ds, 1150) != 0x00)              //jnz loc_419a
        goto loc_419a;
    sub_27df();                                 //call sub_27df
    sub_01f8();                                 //call sub_01f8
    sub_03f2();                                 //call sub_03f2
    sub_03ae();                                 //call sub_03ae
loc_41ad:                                       //loc_41ad:
    sub_18af();                                 //call sub_18af
    _es = memory16(_ds, 21100);                 //mov es, word ptr [0x526c]
    _si = 0x527c;                               //mov si, 0x527c
    sub_4b49();                                 //call sub_4b49
    sub_0805();                                 //call sub_0805
    _ax = 0x550b;                               //mov ax, 0x550b
    if (memory(_ds, 25875) == 0x00)             //jz loc_41ca
        goto loc_41ca;
    goto loc_428a;                              //jmp loc_428a
loc_41ca:                                       //loc_41ca:
    _al = 0x0c;                                 //mov al, 0xc
    _al = _al + memory(_ds, 25857);             //add al, byte ptr [0x6501]
    if (memory(_ds, 25876) == 0x00)             //jz loc_41da
        goto loc_41da;
    goto loc_428a;                              //jmp loc_428a
loc_41da:                                       //loc_41da:
    memory(_ds, 25857) = 0x00;                  //mov byte ptr [0x6501], 0x0
    _al = 0xaa;                                 //mov al, 0xaa
    if (memory(_ds, 1071) == 0x00)              //jz loc_41eb
        goto loc_41eb;
    _ax = 0x0101;                               //mov ax, 0x101
loc_41eb:                                       //loc_41eb:
    if (memory(_ds, 1072) == 0x00)              //jz loc_41f5
        goto loc_41f5;
    _ax = 0xff01;                               //mov ax, 0xff01
loc_41f5:                                       //loc_41f5:
    if (memory(_ds, 25869) == 0x00)             //jz loc_4200
        goto loc_4200;
    _al = 0x06;                                 //mov al, 0x6
    goto loc_4242;                              //jmp loc_4242
loc_4200:                                       //loc_4200:
    if (memory(_ds, 25870) != 0x00)             //jnz loc_4215
        goto loc_4215;
    if (memory(_ds, 25871) == 0x06)             //jz loc_4220
        goto loc_4220;
    if (memory(_ds, 1070) == 0x00)              //jz loc_4220
        goto loc_4220;
loc_4215:                                       //loc_4215:
    if (_ah == 0x55)                            //jz loc_421e
        goto loc_421e;
    _al = 0x03;                                 //mov al, 0x3
    goto loc_4220;                              //jmp loc_4220
loc_421e:                                       //loc_421e:
    _al = 0x05;                                 //mov al, 0x5
loc_4220:                                       //loc_4220:
    if (memory(_ds, 25870) != 0x00)             //jnz loc_4242
        goto loc_4242;
    if (memory(_ds, 1069) == 0x00)              //jz loc_4242
        goto loc_4242;
    if (memory(_ds, 25871) != 0x00)             //jnz loc_4242
        goto loc_4242;
    _al = 0x02;                                 //mov al, 0x2
    if (memory(_ds, _si + 11) != 0x05)          //jnz loc_4242
        goto loc_4242;
    memory(_ds, 25874) = 0x64;                  //mov byte ptr [0x6512], 0x64
loc_4242:                                       //loc_4242:
    if (_al != 0xaa)                            //jnz loc_4248
        goto loc_4248;
    _al = _al ^ _al;                            //xor al, al
loc_4248:                                       //loc_4248:
    if (memory(_ds, 1067) == 0x00)              //jz loc_4280
        goto loc_4280;
    if (memory(_ds, 25870) != 0x00)             //jnz loc_4280
        goto loc_4280;
    if (memory(_ds, 25866) != 0x00)             //jnz loc_428a
        goto loc_428a;
    if (_al == 0x03)                            //jz loc_4265
        goto loc_4265;
    if (_al != 0x05)                            //jnz loc_426e
        goto loc_426e;
loc_4265:                                       //loc_4265:
    memory(_ds, 25867) = 0x00;                  //mov byte ptr [0x650b], 0x0
    _al = 0x07;                                 //mov al, 0x7
    goto loc_428a;                              //jmp loc_428a
loc_426e:                                       //loc_426e:
    if (memory(_ds, 25865) == 0x00)             //jz loc_428a
        goto loc_428a;
    if (memory(_ds, 25867) == 0x00)             //jz loc_428a
        goto loc_428a;
    _al = 0x08;                                 //mov al, 0x8
    goto loc_428a;                              //jmp loc_428a
loc_4280:                                       //loc_4280:
    memory(_ds, 25867) = 0x01;                  //mov byte ptr [0x650b], 0x1
    memory(_ds, 25868) = 0x00;                  //mov byte ptr [0x650c], 0x0
loc_428a:                                       //loc_428a:
    _al = _al + memory(_ds, 25865);             //add al, byte ptr [0x6509]
    if (_ah != 0x55)                            //jnz loc_4296
        goto loc_4296;
    _ah = memory(_ds, _si + 10);                //mov ah, byte ptr [si+0xa]
loc_4296:                                       //loc_4296:
    _dl = memory(_ds, 1072);                    //mov dl, byte ptr [0x430]
    _dl = _dl | memory(_ds, 1071);              //or dl, byte ptr [0x42f]
    memory(_ds, 25863) = _dl;                   //mov byte ptr [0x6507], dl
    _dl = memory(_ds, 1069);                    //mov dl, byte ptr [0x42d]
    _dl = _dl | memory(_ds, 1070);              //or dl, byte ptr [0x42e]
    memory(_ds, 25864) = _dl;                   //mov byte ptr [0x6508], dl
    _cwd();                                     //cwd
    _dl |= _ah;                                 //or dl, ah
    if (memory16(_ds, _si + 9) == _dx)          //jz loc_42c1
        goto loc_42c1;
    memory16(_ds, _si + 9) = _dx;               //mov word ptr [si+0x9], dx
loc_42b9:                                       //loc_42b9:
    memory16(_ds, 25886) = 0x0001;              //mov word ptr [0x651e], 0x1
    goto loc_42e1;                              //jmp loc_42e1
loc_42c1:                                       //loc_42c1:
    if (_al == 0x01)                            //jz loc_42c9
        goto loc_42c9;
    if (_al != 0x00)                            //jnz loc_42d2
        goto loc_42d2;
loc_42c9:                                       //loc_42c9:
    if (memory(_ds, 25874) == 0x00)             //jz loc_42d2
        goto loc_42d2;
    _al += 0x09;                                //add al, 0x9
loc_42d2:                                       //loc_42d2:
    if (memory(_ds, _si + 11) != _al)           //jnz loc_42b9
        goto loc_42b9;
    _flags.carry = (memory16(_ds, 25886) + 0x0001) >= 0x10000;
    memory16(_ds, 25886) += 0x0001;
    memory16(_ds, 25886) -= 0x0000 + _flags.carry;//sbb word ptr [0x651e], 0x0
loc_42e1:                                       //loc_42e1:
    _cbw();                                     //cbw
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    _indirectCall(memory16(_ds, _bx + 28411));  //call word ptr [bx+0x6efb]
    _ax = memory16(_ds, _si + 6);               //mov ax, word ptr [si+0x6]
    _cl = 0x04;                                 //mov cl, 0x4
    _sar(_ax, _cl);                             //sar ax, cl
    memory16(_ds, _si) += _ax;                  //add word ptr [si], ax
    if ((short)memory16(_ds, _si) < (short)0x0008)//jl loc_42fe
        goto loc_42fe;
    if (memory16(_ds, _si) < 0x0ff8)            //jc loc_4300
        goto loc_4300;
loc_42fe:                                       //loc_42fe:
    memory16(_ds, _si) -= _ax;                  //sub word ptr [si], ax
loc_4300:                                       //loc_4300:
    _ax = memory16(_ds, _si + 14);              //mov ax, word ptr [si+0xe]
    _cl = 0x04;                                 //mov cl, 0x4
    _sar(_ax, _cl);                             //sar ax, cl
    memory16(_ds, _si + 2) += _ax;              //add word ptr [si+0x2], ax
    sub_4484();                                 //call sub_4484
    _al = memory(_ds, 0x650a);                  //mov al, [0x650a]
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz loc_4378
        goto loc_4378;
    _cl = 0x04;                                 //mov cl, 0x4
    _ax = memory16(_ds, 0x5294);                //mov ax, [0x5294]
    _sar(_ax, _cl);                             //sar ax, cl
    _ax = _ax + memory16(_ds, 21134);           //add ax, word ptr [0x528e]
    if (_ax >= 0x1000)                          //jnc loc_436b
        goto loc_436b;
    _bx = memory16(_ds, 21104);                 //mov bx, word ptr [0x5270]
    _bx <<= _cl;                                //shl bx, cl
    _bx -= 0x0028;                              //sub bx, 0x28
    if ((short)_bx > (short)_ax)                //jg loc_436b
        goto loc_436b;
    _bx += 0x0190;                              //add bx, 0x190
    if ((short)_bx < (short)_ax)                //jl loc_436b
        goto loc_436b;
    memory16(_ds, 0x528e) = _ax;                //mov [0x528e], ax
    _ax = memory16(_ds, 0x529c);                //mov ax, [0x529c]
    _sar(_ax, _cl);                             //sar ax, cl
    _ax = _ax + memory16(_ds, 21136);           //add ax, word ptr [0x5290]
    _bl = memory(_ds, 20619);                   //mov bl, byte ptr [0x508b]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bx <<= _cl;                                //shl bx, cl
    if (_ax >= _bx)                             //jnc loc_436b
        goto loc_436b;
    _bx = memory16(_ds, 21106);                 //mov bx, word ptr [0x5272]
    _bx <<= _cl;                                //shl bx, cl
    _bx -= 0x0014;                              //sub bx, 0x14
    if ((short)_bx > (short)_ax)                //jg loc_436b
        goto loc_436b;
    _bx += 0x00e8;                              //add bx, 0xe8
    if ((short)_bx < (short)_ax)                //jl loc_436b
        goto loc_436b;
    memory16(_ds, 0x5290) = _ax;                //mov [0x5290], ax
    goto loc_4376;                              //jmp loc_4376
loc_436b:                                       //loc_436b:
    memory16(_ds, 21138) = 0xffff;              //mov word ptr [0x5292], 0xffff
    memory(_ds, 25866) = 0x00;                  //mov byte ptr [0x650a], 0x0
loc_4376:                                       //loc_4376:
    goto loc_43ea;                              //jmp loc_43ea
loc_4378:                                       //loc_4378:
    if (memory(_ds, 25865) == 0x00)             //jz loc_43ea
        goto loc_43ea;
    _bx = memory16(_ds, 21120);                 //mov bx, word ptr [0x5280]
    _dx = _bx;                                  //mov dx, bx
    _dh &= 0x1f;                                //and dh, 0x1f
    _al = memory(_ds, 0x5287);                  //mov al, [0x5287]
    if (memory(_ds, 25869) != 0x00)             //jnz loc_43ab
        goto loc_43ab;
    if (_al == 0x15)                            //jz loc_439a
        goto loc_439a;
    if (_al != 0x17)                            //jnz loc_43ab
        goto loc_43ab;
loc_439a:                                       //loc_439a:
    _ax = memory16(_ds, _si + 2);               //mov ax, word ptr [si+0x2]
    _ax -= 0x0004;                              //sub ax, 0x4
    memory16(_ds, 0x5290) = _ax;                //mov [0x5290], ax
    sub_5122();                                 //call sub_5122
    memory16(_ds, 0x528e) = _ax;                //mov [0x528e], ax
    goto loc_43ea;                              //jmp loc_43ea
loc_43ab:                                       //loc_43ab:
    _al &= 0x0f;                                //and al, 0xf
    if (_dx == 0x000e)                          //jz loc_43ba
        goto loc_43ba;
    if (_al == 0x07)                            //jz loc_43ea
        goto loc_43ea;
    if (_al == 0x08)                            //jz loc_43ea
        goto loc_43ea;
loc_43ba:                                       //loc_43ba:
    _ax = memory16(_ds, 0x527c);                //mov ax, [0x527c]
    _ax += 1;                                   //inc ax
    _ax += 1;                                   //inc ax
    _flags.carry = _dx < 0x0017;                //sub dx, 0x17
    _dx -= 0x0017;
    if (_flags.carry)                           //jc loc_43d4
        goto loc_43d4;
    if (_dx > 0x0001)                           //ja loc_43d4
        goto loc_43d4;
    _ax -= 0x000a;                              //sub ax, 0xa
    if (!(_bh & 0x80))                          //jz loc_43d4
        goto loc_43d4;
    _ax += 0x0012;                              //add ax, 0x12
loc_43d4:                                       //loc_43d4:
    _bh &= 0x1f;                                //and bh, 0x1f
    memory16(_ds, 0x528e) = _ax;                //mov [0x528e], ax
    _ax = memory16(_ds, 0x527e);                //mov ax, [0x527e]
    _bx <<= 1;                                  //shl bx, 1
    _flags.carry = _al < memory(_ds, _bx + 27640);//sub al, byte ptr [bx+0x6bf8]
    _al = _al - memory(_ds, _bx + 27640);
    _ah -= 0x00 + _flags.carry;                 //sbb ah, 0x0
    _ax += 1;                                   //inc ax
    memory16(_ds, 0x5290) = _ax;                //mov [0x5290], ax
loc_43ea:                                       //loc_43ea:
    if (memory(_ds, 25877) == 0x00)             //jz loc_43fd
        goto loc_43fd;
    memory(_ds, 25877) -= 1;                    //dec byte ptr [0x6515]
    if (memory(_ds, 25877) != 0)                //jnz loc_43fd
        goto loc_43fd;
    memory16(_ds, 21138) = 0xffff;              //mov word ptr [0x5292], 0xffff
loc_43fd:                                       //loc_43fd:
    _dx = 0x0001;                               //mov dx, 0x1
    _flags.carry = memory(_ds, 25883) < _dl;    //sub byte ptr [0x651b], dl
    memory(_ds, 25883) -= _dl;
    memory(_ds, 25883) = memory(_ds, 25883) + _dh + _flags.carry;
    _flags.carry = memory(_ds, 25878) < _dl;    //sub byte ptr [0x6516], dl
    memory(_ds, 25878) -= _dl;
    memory(_ds, 25878) = memory(_ds, 25878) + _dh + _flags.carry;
    _flags.carry = memory(_ds, 25860) < _dl;    //sub byte ptr [0x6504], dl
    memory(_ds, 25860) -= _dl;
    memory(_ds, 25860) = memory(_ds, 25860) + _dh + _flags.carry;
    _flags.carry = memory(_ds, 25872) < _dl;    //sub byte ptr [0x6510], dl
    memory(_ds, 25872) -= _dl;
    memory(_ds, 25872) = memory(_ds, 25872) + _dh + _flags.carry;
    _flags.carry = memory(_ds, 25873) < _dl;    //sub byte ptr [0x6511], dl
    memory(_ds, 25873) -= _dl;
    memory(_ds, 25873) = memory(_ds, 25873) + _dh + _flags.carry;
    _flags.carry = memory(_ds, 25874) < _dl;    //sub byte ptr [0x6512], dl
    memory(_ds, 25874) -= _dl;
    memory(_ds, 25874) = memory(_ds, 25874) + _dh + _flags.carry;
    _flags.carry = memory(_ds, 25876) < _dl;    //sub byte ptr [0x6514], dl
    memory(_ds, 25876) -= _dl;
    memory(_ds, 25876) = memory(_ds, 25876) + _dh + _flags.carry;
    if (memory16(_ds, 21130) != 0x0000)         //jnz loc_4447
        goto loc_4447;
    _flags.carry = memory(_ds, 25875) < _dl;    //sub byte ptr [0x6513], dl
    memory(_ds, 25875) -= _dl;
    memory(_ds, 25875) = memory(_ds, 25875) + _dh + _flags.carry;
loc_4447:                                       //loc_4447:
    _ax = memory16(_ds, 0x5282);                //mov ax, [0x5282]
    _ax = _ax | memory16(_ds, 21130);           //or ax, word ptr [0x528a]
    if (_ax != 0)                               //jnz loc_4454
        goto loc_4454;
    memory(_ds, 25876) = _dh;                   //mov byte ptr [0x6514], dh
loc_4454:                                       //loc_4454:
    _flags.carry = memory(_ds, 25861) < _dl;    //sub byte ptr [0x6505], dl
    memory(_ds, 25861) -= _dl;
    memory(_ds, 25861) = memory(_ds, 25861) + _dh + _flags.carry;
    if (memory(_ds, 25861)==0)                                //jz loc_447a
        goto loc_447a;
    if (memory(_ds, 25861) & 0x03)              //jnz loc_447a
        goto loc_447a;
    memory16(_ds, 21138) += 1;                  //inc word ptr [0x5292]
    if (memory(_ds, 21138) != 0x31)             //jnz loc_447a
        goto loc_447a;
    memory16(_ds, 21138) = 0xffff;              //mov word ptr [0x5292], 0xffff
    memory(_ds, 25861) = _dh;                   //mov byte ptr [0x6505], dh
loc_447a:                                       //loc_447a:
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_4484()
{
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _si = 0x527c;                               //mov si, 0x527c
    _ax = memory16(_ds, 0x527e);                //mov ax, [0x527e]
    _cl = 0x04;                                 //mov cl, 0x4
    _sar(_ax, _cl);                             //sar ax, cl
    _ax -= 1;                                   //dec ax
    _xchg(_al, _ah);                            //xchg al, ah
    _bx = memory16(_ds, 21120);                 //mov bx, word ptr [0x5280]
    _bh &= 0x1f;                                //and bh, 0x1f
    _bx <<= 1;                                  //shl bx, 1
    _dh = memory(_ds, _bx + 27640);             //mov dh, byte ptr [bx+0x6bf8]
    _bx = 0x0008;                               //mov bx, 0x8
    if ((short)memory16(_ds, 21122) > (short)0x0000)//jg loc_44b1
        goto loc_44b1;
    if ((short)memory16(_ds, 21122) < (short)0x0000)//jl loc_44af
        goto loc_44af;
    _bx = _bx ^ _bx;                            //xor bx, bx
loc_44af:                                       //loc_44af:
    _bx = -_bx;                                 //neg bx
loc_44b1:                                       //loc_44b1:
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _bx = memory16(_ds, 21116);                 //mov bx, word ptr [0x527c]
    _sar(_bx, _cl);                             //sar bx, cl
    _bx += _ax;                                 //add bx, ax
    if ((short)memory16(_ds, 21118) <= (short)0x0000)//jle loc_44d9
        goto loc_44d9;
    _al = memory(_ds, 0x508b);                  //mov al, [0x508b]
    _ah = _ah ^ _ah;                            //xor ah, ah
    _ax += 1;                                   //inc ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    if ((short)memory16(_ds, 21118) <= (short)_ax)//jle loc_44d9
        goto loc_44d9;
    sub_4dc0();                                 //call sub_4dc0
loc_44d9:                                       //loc_44d9:
    memory(_ds, 25894) = 0x00;                  //mov byte ptr [0x6526], 0x0
    _al = memory(_ds, 0x527c);                  //mov al, [0x527c]
    _al &= 0x0f;                                //and al, 0xf
    _flags.carry = _al < 0x04;                  //sub al, 0x4
    _al -= 0x04;
    _bx -= 0x0000 + _flags.carry;               //sbb bx, 0x0
    _bp = _bx;                                  //mov bp, bx
    sub_4561();                                 //call sub_4561
    if (memory(_ds, 25894) != 0x01)             //jnz loc_4539
        goto loc_4539;
    _flags.carry = (_al + 0x08) >= 0x100;       //add al, 0x8
    _al += 0x08;
    _bx = _bx + 0x0000 + _flags.carry;          //adc bx, 0x0
    _cmc();                                     //cmc
    _bx = _bx + 0x0000 + _flags.carry; _ASSERT(0);//adc bx, 0x0
    if (_bx == _bp)                             //jz loc_4506
        goto loc_4506;
    sub_4561();                                 //call sub_4561
loc_4506:                                       //loc_4506:
    if (memory(_ds, 25894) != 0x01)             //jnz loc_4539
        goto loc_4539;
    if (memory(_ds, 25872) != 0x00)             //jnz loc_4536
        goto loc_4536;
    if (memory(_ds, 25875) != 0x00)             //jnz loc_4536
        goto loc_4536;
    sub_4657();                                 //call sub_4657
    if (memory(_ds, 25894) != 0x01)             //jnz loc_4539
        goto loc_4539;
    sub_4f1f();                                 //call sub_4f1f
    if (memory(_ds, 25894) == 0x01)             //jz loc_4536
        goto loc_4536;
    memory(_ds, 21124) = 0x00;                  //mov byte ptr [0x5284], 0x0
    goto loc_4539;                              //jmp loc_4539
loc_4536:                                       //loc_4536:
    sub_4c65();                                 //call sub_4c65
loc_4539:                                       //loc_4539:
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    if ((short)memory16(_ds, 21118) <= (short)0x0000)//jle loc_455d
        goto loc_455d;
    _bx = _bx + memory16(_ds, 21116);           //add bx, word ptr [0x527c]
    _sar(_bx, _cl);                             //sar bx, cl
    _bx += _ax;                                 //add bx, ax
    sub_4617();                                 //call sub_4617
    goto loc_4552;                              //jmp loc_4552
loc_454f:                                       //loc_454f:
    sub_4631();                                 //call sub_4631
loc_4552:                                       //loc_4552:
    _flags.carry = _bx < 0x0100;                //sub bx, 0x100
    _bx -= 0x0100;
    if (_flags.carry)                           //jc loc_455d
        goto loc_455d;
    _flags.carry2 = _dh > 0x10;
    _dh -= 0x10;                                //sub dh, 0x10
    if (_flags.carry2)                                //ja loc_454f
        goto loc_454f;
loc_455d:                                       //loc_455d:
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
}

void sub_4561()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_bp);                                 //push bp
    memory(_ds, 25884) = 0x00;                  //mov byte ptr [0x651c], 0x0
    memory(_ds, 25870) = 0x00;                  //mov byte ptr [0x650e], 0x0
    memory(_ds, 25869) = 0x00;                  //mov byte ptr [0x650d], 0x0
    if ((short)memory16(_ds, 21118) > (short)0xffff)
        goto loc_4585;
    sub_4c65();                                 //call sub_4c65
    memory(_ds, 25894) = 0xff;                  //mov byte ptr [0x6526], 0xff
    goto loc_4613;                              //jmp loc_4613
loc_4585:                                       //loc_4585:
    _al = memory(_ds, 0x5287);                  //mov al, [0x5287]
    _al &= 0x0f;                                //and al, 0xf
    if (_al == 0x02)                            //jz loc_45a5
        goto loc_45a5;
    _push(_bx);                                 //push bx
    _lea(_di, _ds, _bx + 256);                  //lea di, [bx+0x100]
    _al = memory(_es, _di);                     //mov al, byte ptr es:[di]
    _bx = 0x73a3;                               //mov bx, 0x73a3
    _xlat();                                    //xlat
    _ah = _ah ^ _ah;                            //xor ah, ah
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    _indirectCall(memory16(_ds, _bx + 29309));  //call word ptr [bx+0x727d]
    _bx = _pop();                               //pop bx
loc_45a5:                                       //loc_45a5:
    _flags.carry = _bx < 0x0100;                //sub bx, 0x100
    _bx -= 0x0100;
    if (_flags.carry)                           //jc loc_4613
        goto loc_4613;
    if ((short)memory16(_ds, 21130) > (short)0x0000)//jg loc_4613
        goto loc_4613;
    _di = _bx;                                  //mov di, bx
    _ah = memory(_es, _bx);                     //mov ah, byte ptr es:[bx]
    _al = memory(_es, _bx + 256);               //mov al, byte ptr es:[bx+0x100]
    _bx = 0x72a3;                               //mov bx, 0x72a3
    _xlat();                                    //xlat
    _xchg(_al, _ah);                            //xchg al, ah
    _bx = 0x74a3;                               //mov bx, 0x74a3
    _xlat();                                    //xlat
    _al &= 0x7f;                                //and al, 0x7f
    _bl = _al;                                  //mov bl, al
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bx <<= 1;                                  //shl bx, 1
    _push(_ax);                                 //push ax
    _indirectCall(memory16(_ds, _bx + 29337));  //call word ptr [bx+0x7299]
    _ax = _pop();                               //pop ax
    _ah &= 0x01;                                //and ah, 0x1
    if (_ah == 0)                               //jz loc_4613
        goto loc_4613;
    if ((short)memory16(_ds, 21118) <= (short)0x0000)//jle loc_4613
        goto loc_4613;
    _dx = 0xffff;                               //mov dx, 0xffff
    _bx = 0x72a3;                               //mov bx, 0x72a3
    if ((short)memory16(_ds, 21122) > (short)0x0000)//jg loc_45ef
        goto loc_45ef;
    _dx = -_dx;                                 //neg dx
loc_45ef:                                       //loc_45ef:
    _push(_di);                                 //push di
    _di += _dx;                                 //add di, dx
    _al = memory(_es, _di + 256);               //mov al, byte ptr es:[di+0x100]
    _xlat();                                    //xlat
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz loc_460c
        goto loc_460c;
    _dx = -_dx;                                 //neg dx
    _di += _dx;                                 //add di, dx
    _di += _dx;                                 //add di, dx
    _al = memory(_es, _di + 256);               //mov al, byte ptr es:[di+0x100]
    _xlat();                                    //xlat
    _al |= _al;                                 //or al, al
    if (_al != 0)                               //jnz loc_4612
        goto loc_4612;
loc_460c:                                       //loc_460c:
    _dx <<= 1;                                  //shl dx, 1
    memory16(_ds, 21116) += _dx;                //add word ptr [0x527c], dx
loc_4612:                                       //loc_4612:
    _di = _pop();                               //pop di
loc_4613:                                       //loc_4613:
    _bp = _pop();                               //pop bp
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_4617()
{
    _push(_bx);                                 //push bx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _di = _bx;                                  //mov di, bx
    _al = memory(_es, _bx);                     //mov al, byte ptr es:[bx]
    _bx = 0x72a3;                               //mov bx, 0x72a3
    _xlat();                                    //xlat
    _ah = _ah ^ _ah;                            //xor ah, ah
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    _indirectCall(memory16(_ds, _bx + 29295));  //call word ptr [bx+0x726f]
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
}

void sub_4631()
{
    _push(_bx);                                 //push bx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _di = _bx;                                  //mov di, bx
    _al = memory(_es, _bx);                     //mov al, byte ptr es:[bx]
    _bx = 0x72a3;                               //mov bx, 0x72a3
    _xlat();                                    //xlat
    if (_al == 0x04)                            //jz loc_4645
        goto loc_4645;
    if (_al != 0x02)                            //jnz loc_464f
        goto loc_464f;
loc_4645:                                       //loc_4645:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    _indirectCall(memory16(_ds, _bx + 29295));  //call word ptr [bx+0x726f]
loc_464f:                                       //loc_464f:
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
    return;                                     //ret
loc_4653:                                       //loc_4653:
    return;                                     //ret
loc_4654:                                       //loc_4654:
    _STOP_("goto loc_4735");                    //jmp loc_4735
}

void sub_4657()
{
    if ((short)memory16(_ds, 21130) < (short)0x0000)//jl loc_4653
        _STOP_("goto loc_4653");
    if (memory(_ds, 25872) != 0x00)             //jnz loc_4653
        _STOP_("goto loc_4653");
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    _si = 0x5648;                               //mov si, 0x5648
    _cx = 0x0004;                               //mov cx, 0x4
loc_4674:                                       //loc_4674:
    if (memory16(_ds, _si + 4) == 0xffff)   //jz loc_4654
        _STOP_("goto loc_4654");
    if (!(memory(_ds, _si + 5) & 0x20))         //jz loc_4654
        _STOP_("goto loc_4654");
    _ax = memory16(_ds, _si);                   //mov ax, word ptr [si]
    _ax = _ax - memory16(_ds, 21116);           //sub ax, word ptr [0x527c]
    if ((short)_ax >= 0)                        //jns loc_468a
        goto loc_468a;
    _ax = -_ax;                                 //neg ax
loc_468a:                                       //loc_468a:
    if (_ax >= 0x0040)                          //jnc loc_4654
        _STOP_("goto loc_4654");
    _ax = memory16(_ds, _si + 2);               //mov ax, word ptr [si+0x2]
    _ax = _ax - memory16(_ds, 21118);           //sub ax, word ptr [0x527e]
    if ((short)_ax >= 0)                        //jns loc_469a
        goto loc_469a;
    _ax = -_ax;                                 //neg ax
loc_469a:                                       //loc_469a:
    if (_ax >= 0x0010)                          //jnc loc_4654
        _STOP_("goto loc_4654");
    _ax = memory16(_ds, _si);                   //mov ax, word ptr [si]
    _dx = memory16(_ds, 21116);                 //mov dx, word ptr [0x527c]
    _flags.carry = _dl < memory(_ds, 26927);    //sub dl, byte ptr [0x692f]
    _dl = _dl - memory(_ds, 26927);
    _dh -= 0x00 + _flags.carry;                 //sbb dh, 0x0
    _bl = memory(_ds, 27639);                   //mov bl, byte ptr [0x6bf7]
    if ((short)_dx < (short)_ax)                //jl loc_46c1
        goto loc_46c1;
    _bx = memory16(_ds, _si + 4);               //mov bx, word ptr [si+0x4]
    _bh &= 0x1f;                                //and bh, 0x1f
    _bx <<= 1;                                  //shl bx, 1
    _bl = memory(_ds, _bx + 27639);             //mov bl, byte ptr [bx+0x6bf7]
    _xchg(_ax, _dx);                            //xchg ax, dx
loc_46c1:                                       //loc_46c1:
    _bh = _bh ^ _bh;                            //xor bh, bh
    _dx += _bx;                                 //add dx, bx
    if ((short)_dx <= (short)_ax)               //jle loc_4735
        goto loc_4735;
    _ax = memory16(_ds, _si + 2);               //mov ax, word ptr [si+0x2]
    _dx = memory16(_ds, 21118);                 //mov dx, word ptr [0x527e]
    _flags.carry = _dl < 0x06;                  //sub dl, 0x6
    _dl -= 0x06;
    _dh -= 0x00 + _flags.carry;                 //sbb dh, 0x0
    _bl = 0x08;                                 //mov bl, 0x8
    if ((short)_dx < (short)_ax)                //jl loc_46e9
        goto loc_46e9;
    _bx = memory16(_ds, _si + 4);               //mov bx, word ptr [si+0x4]
    _bh &= 0x1f;                                //and bh, 0x1f
    _bx <<= 1;                                  //shl bx, 1
    _bl = memory(_ds, _bx + 27640);             //mov bl, byte ptr [bx+0x6bf8]
    _xchg(_ax, _dx);                            //xchg ax, dx
loc_46e9:                                       //loc_46e9:
    _bh = _bh ^ _bh;                            //xor bh, bh
    _dx += _bx;                                 //add dx, bx
    if ((short)_dx <= (short)_ax)               //jle loc_4735
        goto loc_4735;
    if (memory16(_ds, 25886) != 0x000e)         //jnz loc_46fe
        goto loc_46fe;
    memory16(_ds, 25886) = 0x0010;              //mov word ptr [0x651e], 0x10
loc_46fe:                                       //loc_46fe:
    memory(_ds, 25894) = 0x00;                  //mov byte ptr [0x6526], 0x0
    _ax = memory16(_ds, _si + 2);               //mov ax, word ptr [si+0x2]
    memory16(_ds, 0x527e) = _ax;                //mov [0x527e], ax
    sub_4cf0();                                 //call sub_4cf0
    _bx = memory16(_ds, _si + 9);               //mov bx, word ptr [si+0x9]
    _al = memory(_ds, _bx + 7);                 //mov al, byte ptr [bx+0x7]
    _cbw();                                     //cbw
    _dl = memory(_ds, _bx + 6);                 //mov dl, byte ptr [bx+0x6]
    if (_dl == 0x01)                            //jz loc_472f
        goto loc_472f;
    if (_dl == 0x02)                            //jz loc_4729
        goto loc_4729;
    _ax = -_ax;                                 //neg ax
    if (_dl == 0x03)                            //jz loc_472f
        goto loc_472f;
    goto loc_473e;                              //jmp loc_473e
loc_4729:                                       //loc_4729:
    memory16(_ds, 21118) += _ax;                //add word ptr [0x527e], ax
    goto loc_473e;                              //jmp loc_473e
loc_472f:                                       //loc_472f:
    memory16(_ds, 21116) += _ax;                //add word ptr [0x527c], ax
    goto loc_473e;                              //jmp loc_473e
loc_4735:                                       //loc_4735:
    _si += 0x0012;                              //add si, 0x12
    _cx -= 1;                                   //dec cx
    if (_cx == 0)                               //jz loc_473e
        goto loc_473e;
    goto loc_4674;                              //jmp loc_4674
loc_473e:                                       //loc_473e:
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    return;                                     //ret
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 1dh");                           //db 1dh
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db feh");                           //db feh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 1dh");                           //db 1dh
    _STOP_("db 65h");                           //db 65h
    _STOP_("db bdh");                           //db bdh
    _STOP_("db 30h");                           //db 30h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 57h");                           //db 57h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db bdh");                           //db bdh
    _STOP_("db 40h");                           //db 40h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 18h");                           //db 18h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db aah");                           //db aah
    _STOP_("db 04h");                           //db 04h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db bfh");                           //db bfh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 50h");                           //db 50h
    _STOP_("db 53h");                           //db 53h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db a2h");                           //db a2h
    _STOP_("db 87h");                           //db 87h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 73h");                           //db 73h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 79h");                           //db 79h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db f7h");                           //db f7h
    _STOP_("db d8h");                           //db d8h
    _STOP_("db 3dh");                           //db 3dh
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 1dh");                           //db 1dh
    _STOP_("db a0h");                           //db a0h
    _STOP_("db 81h");                           //db 81h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db d0h");                           //db d0h
    _STOP_("db c0h");                           //db c0h
    _STOP_("db d0h");                           //db d0h
    _STOP_("db c4h");                           //db c4h
    _STOP_("db 25h");                           //db 25h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 3ah");                           //db 3ah
    _STOP_("db c4h");                           //db c4h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 32h");                           //db 32h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 83h");                           //db 83h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e3h");                           //db e3h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 9fh");                           //db 9fh
    _STOP_("db bfh");                           //db bfh
    _STOP_("db 6eh");                           //db 6eh
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 36h");                           //db 36h
    _STOP_("db 85h");                           //db 85h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db e6h");                           //db e6h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 5ah");                           //db 5ah
    _STOP_("db 5bh");                           //db 5bh
    _STOP_("db 58h");                           //db 58h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 58h");                           //db 58h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 6dh");                           //db 6dh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 28h");                           //db 28h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db c7h");                           //db c7h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 04h");                           //db 04h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 51h");                           //db 51h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db bdh");                           //db bdh
    _STOP_("db 20h");                           //db 20h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 9eh");                           //db 9eh
    _STOP_("db 03h");                           //db 03h
    _STOP_("db a1h");                           //db a1h
    _STOP_("db 82h");                           //db 82h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 79h");                           //db 79h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db f7h");                           //db f7h
    _STOP_("db d8h");                           //db d8h
    _STOP_("db 3dh");                           //db 3dh
    _STOP_("db 20h");                           //db 20h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 73h");                           //db 73h
    _STOP_("db 0ch");                           //db 0ch
    _STOP_("db b0h");                           //db b0h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 85h");                           //db 85h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db bdh");                           //db bdh
    _STOP_("db 40h");                           //db 40h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 24h");                           //db 24h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db bdh");                           //db bdh
    _STOP_("db 30h");                           //db 30h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 70h");                           //db 70h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 17h");                           //db 17h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db c7h");                           //db c7h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 82h");                           //db 82h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db f5h");                           //db f5h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db 04h");                           //db 04h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db c5h");                           //db c5h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db ebh");                           //db ebh
    _STOP_("db eeh");                           //db eeh
    _STOP_("db bdh");                           //db bdh
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db a4h");                           //db a4h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db e3h");                           //db e3h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db f8h");                           //db f8h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 08h");                           //db 08h
    _STOP_("db bdh");                           //db bdh
    _STOP_("db 40h");                           //db 40h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 3dh");                           //db 3dh
    _STOP_("db 03h");                           //db 03h
    _STOP_("db ebh");                           //db ebh
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 77h");                           //db 77h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 0ch");                           //db 0ch
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 17h");                           //db 17h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 33h");                           //db 33h
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 38h");                           //db 38h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 08h");                           //db 08h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 64h");                           //db 64h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 98h");                           //db 98h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db d8h");                           //db d8h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e3h");                           //db e3h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db a0h");                           //db a0h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db b5h");                           //db b5h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 7ch");                           //db 7ch
    _STOP_("db 52h");                           //db 52h
    _STOP_("db f0h");                           //db f0h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 7ch");                           //db 7ch
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 08h");                           //db 08h
    _STOP_("db bbh");                           //db bbh
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 73h");                           //db 73h
    _STOP_("db b1h");                           //db b1h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db a1h");                           //db a1h
    _STOP_("db 7eh");                           //db 7eh
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 24h");                           //db 24h
    _STOP_("db f0h");                           //db f0h
    _STOP_("db d3h");                           //db d3h
    _STOP_("db e0h");                           //db e0h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 7ch");                           //db 7ch
    _STOP_("db 52h");                           //db 52h
    _STOP_("db d3h");                           //db d3h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 03h");                           //db 03h
    _STOP_("db f8h");                           //db f8h
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 6ch");                           //db 6ch
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 05h");                           //db 05h
    _STOP_("db d7h");                           //db d7h
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 1dh");                           //db 1dh
    _STOP_("db bah");                           //db bah
    _STOP_("db f0h");                           //db f0h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 45h");                           //db 45h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db d7h");                           //db d7h
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db f7h");                           //db f7h
    _STOP_("db dah");                           //db dah
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db d7h");                           //db d7h
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 33h");                           //db 33h
    _STOP_("db d2h");                           //db d2h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 7ch");                           //db 7ch
    _STOP_("db 52h");                           //db 52h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 40h");                           //db 40h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 2dh");                           //db 2dh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db f7h");                           //db f7h
    _STOP_("db d8h");                           //db d8h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 52h");                           //db 52h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 43h");                           //db 43h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 58h");                           //db 58h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 13h");                           //db 13h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 39h");                           //db 39h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 4eh");                           //db 4eh
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 33h");                           //db 33h
    _STOP_("db c0h");                           //db c0h
    _STOP_("db bah");                           //db bah
    _STOP_("db 60h");                           //db 60h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 2dh");                           //db 2dh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 18h");                           //db 18h
    _STOP_("db bah");                           //db bah
    _STOP_("db 20h");                           //db 20h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 92h");                           //db 92h
    _STOP_("db f6h");                           //db f6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 81h");                           //db 81h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db f7h");                           //db f7h
    _STOP_("db d8h");                           //db d8h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 7eh");                           //db 7eh
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db ebh");                           //db ebh
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 90h");                           //db 90h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db d2h");                           //db d2h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 13h");                           //db 13h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 92h");                           //db 92h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e7h");                           //db e7h
    _STOP_("db 1fh");                           //db 1fh
    _STOP_("db 83h");                           //db 83h
    _STOP_("db fbh");                           //db fbh
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 73h");                           //db 73h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db f6h");                           //db f6h
    _STOP_("db 87h");                           //db 87h
    _STOP_("db 19h");                           //db 19h
    _STOP_("db 6fh");                           //db 6fh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 17h");                           //db 17h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db c5h");                           //db c5h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 64h");                           //db 64h
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 57h");                           //db 57h
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db d0h");                           //db d0h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db fah");                           //db fah
    _STOP_("db d1h");                           //db d1h
    _STOP_("db fah");                           //db fah
    _STOP_("db 2bh");                           //db 2bh
    _STOP_("db c2h");                           //db c2h
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 47h");                           //db 47h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db ebh");                           //db ebh
    _STOP_("db 11h");                           //db 11h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 94h");                           //db 94h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 9ch");                           //db 9ch
    _STOP_("db 52h");                           //db 52h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 9dh");                           //db 9dh
    _STOP_("db c8h");                           //db c8h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 85h");                           //db 85h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db b4h");                           //db b4h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db c9h");                           //db c9h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 84h");                           //db 84h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 0ch");                           //db 0ch
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 44h");                           //db 44h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 40h");                           //db 40h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 39h");                           //db 39h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 6dh");                           //db 6dh
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 64h");                           //db 64h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 47h");                           //db 47h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db b1h");                           //db b1h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db d3h");                           //db d3h
    _STOP_("db f8h");                           //db f8h
    _STOP_("db 86h");                           //db 86h
    _STOP_("db e0h");                           //db e0h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db f8h");                           //db f8h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 07h");                           //db 07h
    _STOP_("db d3h");                           //db d3h
    _STOP_("db f8h");                           //db f8h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db f8h");                           //db f8h
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 05h");                           //db 05h
    _STOP_("db bbh");                           //db bbh
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 73h");                           //db 73h
    _STOP_("db d7h");                           //db d7h
    _STOP_("db 24h");                           //db 24h
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 13h");                           //db 13h
    _STOP_("db bah");                           //db bah
    _STOP_("db d0h");                           //db d0h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db c4h");                           //db c4h
    _STOP_("db d7h");                           //db d7h
    _STOP_("db 24h");                           //db 24h
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db f7h");                           //db f7h
    _STOP_("db dah");                           //db dah
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 64h");                           //db 64h
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 57h");                           //db 57h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 31h");                           //db 31h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db bfh");                           //db bfh
    _STOP_("db a0h");                           //db a0h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db b9h");                           //db b9h
    _STOP_("db 30h");                           //db 30h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 7eh");                           //db 7eh
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 7ch");                           //db 7ch
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 2bh");                           //db 2bh
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 79h");                           //db 79h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db f7h");                           //db f7h
    _STOP_("db d8h");                           //db d8h
    _STOP_("db 3dh");                           //db 3dh
    _STOP_("db 14h");                           //db 14h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db f6h");                           //db f6h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db c2h");                           //db c2h
    _STOP_("db 2bh");                           //db 2bh
    _STOP_("db 05h");                           //db 05h
    _STOP_("db f6h");                           //db f6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 81h");                           //db 81h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db f7h");                           //db f7h
    _STOP_("db d8h");                           //db d8h
    _STOP_("db 3dh");                           //db 3dh
    _STOP_("db 14h");                           //db 14h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db e1h");                           //db e1h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db f9h");                           //db f9h
    _STOP_("db 08h");                           //db 08h
    _STOP_("db 77h");                           //db 77h
    _STOP_("db 13h");                           //db 13h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e7h");                           //db e7h
    _STOP_("db 1fh");                           //db 1fh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 87h");                           //db 87h
    _STOP_("db 7ah");                           //db 7ah
    _STOP_("db 6fh");                           //db 6fh
    _STOP_("db 24h");                           //db 24h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db c1h");                           //db c1h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e7h");                           //db e7h
    _STOP_("db 1fh");                           //db 1fh
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e3h");                           //db e3h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 9fh");                           //db 9fh
    _STOP_("db f7h");                           //db f7h
    _STOP_("db 6bh");                           //db 6bh
    _STOP_("db a1h");                           //db a1h
    _STOP_("db 7ch");                           //db 7ch
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 3bh");                           //db 3bh
    _STOP_("db c2h");                           //db c2h
    _STOP_("db 7eh");                           //db 7eh
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 92h");                           //db 92h
    _STOP_("db b3h");                           //db b3h
    _STOP_("db 20h");                           //db 20h
    _STOP_("db 32h");                           //db 32h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 03h");                           //db 03h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 3bh");                           //db 3bh
    _STOP_("db c2h");                           //db c2h
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db a0h");                           //db a0h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 7eh");                           //db 7eh
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e7h");                           //db e7h
    _STOP_("db 1fh");                           //db 1fh
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e3h");                           //db e3h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 9fh");                           //db 9fh
    _STOP_("db f8h");                           //db f8h
    _STOP_("db 6bh");                           //db 6bh
    _STOP_("db feh");                           //db feh
    _STOP_("db cbh");                           //db cbh
    _STOP_("db 3bh");                           //db 3bh
    _STOP_("db c2h");                           //db c2h
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 92h");                           //db 92h
    _STOP_("db b3h");                           //db b3h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db 32h");                           //db 32h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 2bh");                           //db 2bh
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 3bh");                           //db 3bh
    _STOP_("db c2h");                           //db c2h
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db 7ch");                           //db 7ch
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 34h");                           //db 34h
    _STOP_("db a1h");                           //db a1h
    _STOP_("db 7ch");                           //db 7ch
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 2bh");                           //db 2bh
    _STOP_("db 05h");                           //db 05h
    _STOP_("db f6h");                           //db f6h
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db f7h");                           //db f7h
    _STOP_("db d8h");                           //db d8h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 78h");                           //db 78h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 09h");                           //db 09h
    _STOP_("db c7h");                           //db c7h
    _STOP_("db 47h");                           //db 47h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e7h");                           //db e7h
    _STOP_("db 1fh");                           //db 1fh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 9fh");                           //db 9fh
    _STOP_("db 7ah");                           //db 7ah
    _STOP_("db 6fh");                           //db 6fh
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e3h");                           //db e3h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 32h");                           //db 32h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e3h");                           //db e3h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 9fh");                           //db 9fh
    _STOP_("db c5h");                           //db c5h
    _STOP_("db 6fh");                           //db 6fh
    _STOP_("db 83h");                           //db 83h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 51h");                           //db 51h
    _STOP_("db c7h");                           //db c7h
    _STOP_("db 33h");                           //db 33h
    _STOP_("db c0h");                           //db c0h
    _STOP_("db a2h");                           //db a2h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 87h");                           //db 87h
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 92h");                           //db 92h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 15h");                           //db 15h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 31h");                           //db 31h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db a1h");                           //db a1h
    _STOP_("db 7eh");                           //db 7eh
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 2dh");                           //db 2dh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 90h");                           //db 90h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db 52h");                           //db 52h
    _STOP_("db ebh");                           //db ebh
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 7eh");                           //db 7eh
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 7ch");                           //db 7ch
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db c7h");                           //db c7h
    _STOP_("db 12h");                           //db 12h
    _STOP_("db 49h");                           //db 49h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db e7h");                           //db e7h
    _STOP_("db feh");                           //db feh
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 0ch");                           //db 0ch
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db c3h");                           //db c3h
    _STOP_("sp-trace-fail");                    //sub_4657 endp_failed
    _STOP_("continues");                        //sub_4ae9 proc near
}

void sub_4ae9()
{
    if (memory16(_ds, 21138) == 0xffff)     //jz loc_4b48
        goto loc_4b48;
    if (memory(_ds, 25865) == 0x00)             //jz loc_4b48
        goto loc_4b48;
    _push(_ax);                                 //push ax
    _push(_di);                                 //push di
    _di = 0x528e;                               //mov di, 0x528e
    _ax = 0xffff;                               //mov ax, 0xffff
loc_4aff:                                       //loc_4aff:
    _di += 0x0012;                              //add di, 0x12
    if (memory16(_ds, _di + 4) != _ax)          //jnz loc_4aff
        goto loc_4aff;
    _xchg(memory16(_ds, 21138), _ax);           //xchg word ptr [0x5292], ax
    memory16(_ds, _di + 4) = _ax;               //mov word ptr [di+0x4], ax
    _ah &= 0x1f;                                //and ah, 0x1f
    _al = 0x00;                                 //mov al, 0x0
    if (_ax < 0x0065)                           //jc loc_4b1a
        goto loc_4b1a;
    _al += 1;                                   //inc al
loc_4b1a:                                       //loc_4b1a:
    memory(_ds, _di + 11) = _al;                //mov byte ptr [di+0xb], al
    _ax = memory16(_ds, 0x528e);                //mov ax, [0x528e]
    memory16(_ds, _di) = _ax;                   //mov word ptr [di], ax
    _ax = memory16(_ds, 0x5290);                //mov ax, [0x5290]
    memory16(_ds, _di + 2) = _ax;               //mov word ptr [di+0x2], ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory(_ds, 0x6509) = _al;                  //mov [0x6509], al
    memory16(_ds, _di + 12) = _ax;              //mov word ptr [di+0xc], ax
    memory16(_ds, _di + 14) = _ax;              //mov word ptr [di+0xe], ax
    memory16(_ds, _di + 6) = _ax;               //mov word ptr [di+0x6], ax
    memory(_ds, _di + 8) = _al;                 //mov byte ptr [di+0x8], al
    _ax += 1;                                   //inc ax
    memory(_ds, 0x650c) = _al;                  //mov [0x650c], al
    memory(_ds, 25873) = 0x04;                  //mov byte ptr [0x6511], 0x4
    memory16(_ds, 25833) = _di;                 //mov word ptr [0x64e9], di
    _di = _pop();                               //pop di
    _ax = _pop();                               //pop ax
loc_4b48:                                       //loc_4b48:
    return;
}

void sub_4b49()
{
    if (memory(_ds, 1113) == 0x00)              //jz loc_4b7c
        goto loc_4b7c;
loc_4b50:                                       //loc_4b50:
    if (memory(_ds, 1113) != 0x00)              //jnz loc_4b50
        goto loc_4b50;
    sub_2c87();                                 //call sub_2c87
    _push(memory16(_ds, 21120));                //push word ptr [0x5280]
    memory16(_ds, 21120) = 0x001d;              //mov word ptr [0x5280], 0x1d
    sub_1c61();                                 //call sub_1c61
    sub_3271();                                 //call sub_3271
    memory16(_ds, 21120) = _pop();              //pop word ptr [0x5280]
loc_4b6e:                                       //loc_4b6e:
    if (memory(_ds, 1113) == 0x00)              //jz loc_4b6e
        goto loc_4b6e;
loc_4b75:                                       //loc_4b75:
    if (memory(_ds, 1113) != 0x00)              //jnz loc_4b75
        goto loc_4b75;
loc_4b7c:                                       //loc_4b7c:
    return;
}

void sub_4b7d()
{
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_bp);                                 //push bp
    _ax = _ax ^ _ax;                            //xor ax, ax
    if (memory(_ds, 25863) == 0x00)             //jz loc_4b95
        goto loc_4b95;
    _ax = memory16(_ds, 0x5285);                //mov ax, [0x5285]
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
loc_4b95:                                       //loc_4b95:
    _cl = memory(_ds, 21124);                   //mov cl, byte ptr [0x5284]
    _sar(_ax, _cl);                             //sar ax, cl
    _dx = memory16(_ds, 21122);                 //mov dx, word ptr [0x5282]
    _dx += _ax;                                 //add dx, ax
    if ((short)_dx >= (short)_bp)               //jge loc_4bad
        goto loc_4bad;
    _bp = -_bp;                                 //neg bp
    if ((short)_dx <= (short)_bp)               //jle loc_4bad
        goto loc_4bad;
    _bp = _dx;                                  //mov bp, dx
loc_4bad:                                       //loc_4bad:
    memory16(_ds, 21122) = _bp;                 //mov word ptr [0x5282], bp
    _bp = _pop();                               //pop bp
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
    return;                                     //ret
    _STOP_("db 50h");                           //db 50h
    _STOP_("db 51h");                           //db 51h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db c2h");                           //db c2h
    _STOP_("db e0h");                           //db e0h
    _STOP_("db f7h");                           //db f7h
    _STOP_("db ddh");                           //db ddh
    _STOP_("db 3bh");                           //db 3bh
    _STOP_("db d5h");                           //db d5h
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db eah");                           //db eah
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 5ah");                           //db 5ah
    _STOP_("db 59h");                           //db 59h
    _STOP_("db 58h");                           //db 58h
    _STOP_("db c3h");                           //db c3h
    _STOP_("sp-trace-fail");                    //sub_4b7d endp_failed
    _STOP_("continues");                        //sub_4bd0 proc near
}

void sub_4bd0()
{
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _dx = memory16(_ds, 21130);                 //mov dx, word ptr [0x528a]
    _dx += 0x0010;                              //add dx, 0x10
    if ((short)_dx >= (short)_bp)               //jge loc_4be0
        goto loc_4be0;
    _bp = _dx;                                  //mov bp, dx
loc_4be0:                                       //loc_4be0:
    memory16(_ds, 21130) = _bp;                 //mov word ptr [0x528a], bp
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
    return;                                     //ret
    _STOP_("db 51h");                           //db 51h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 32h");                           //db 32h
    _STOP_("db edh");                           //db edh
    _STOP_("db a1h");                           //db a1h
    _STOP_("db 82h");                           //db 82h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 79h");                           //db 79h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db f7h");                           //db f7h
    _STOP_("db d8h");                           //db d8h
    _STOP_("db feh");                           //db feh
    _STOP_("db c5h");                           //db c5h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 84h");                           //db 84h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db bah");                           //db bah
    _STOP_("db 0ch");                           //db 0ch
    _STOP_("db 00h");                           //db 00h
    _STOP_("db d3h");                           //db d3h
    _STOP_("db eah");                           //db eah
    _STOP_("db 2bh");                           //db 2bh
    _STOP_("db c2h");                           //db c2h
    _STOP_("db 73h");                           //db 73h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 33h");                           //db 33h
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db edh");                           //db edh
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db f7h");                           //db f7h
    _STOP_("db d8h");                           //db d8h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 82h");                           //db 82h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 5ah");                           //db 5ah
    _STOP_("db 59h");                           //db 59h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 38h");                           //db 38h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 87h");                           //db 87h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db a2h");                           //db a2h
    _STOP_("db 87h");                           //db 87h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 9fh");                           //db 9fh
    _STOP_("db bfh");                           //db bfh
    _STOP_("db 6eh");                           //db 6eh
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db ebh");                           //db ebh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 50h");                           //db 50h
    _STOP_("db 53h");                           //db 53h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 0bh");                           //db 0bh
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 79h");                           //db 79h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db d8h");                           //db d8h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 36h");                           //db 36h
    _STOP_("db 85h");                           //db 85h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db e6h");                           //db e6h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 43h");                           //db 43h
    _STOP_("db 43h");                           //db 43h
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 5ah");                           //db 5ah
    _STOP_("db 5bh");                           //db 5bh
    _STOP_("db 58h");                           //db 58h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db bdh");                           //db bdh
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db ffh");                           //db ffh
    _STOP_("db b0h");                           //db b0h
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 85h");                           //db 85h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db c3h");                           //db c3h
    _STOP_("sp-trace-fail");                    //sub_4bd0 endp_failed
    _STOP_("continues");                        //sub_4c65 proc near
}

void sub_4c65()
{
    memory(_ds, 25871) = 0x06;                  //mov byte ptr [0x650f], 0x6
    if (memory(_ds, 25876) != 0x00)             //jnz loc_4ca1
        goto loc_4ca1;
    _push(_ax);                                 //push ax
    _push(_bp);                                 //push bp
    _bp = 0x0040;                               //mov bp, 0x40
    sub_4b7d();                                 //call sub_4b7d
    _bp = 0x00c0;                               //mov bp, 0xc0
    sub_4bd0();                                 //call sub_4bd0
    if (memory(_ds, 25875) == 0x00)             //jz loc_4c8a
        goto loc_4c8a;
    _al = 0x0f;                                 //mov al, 0xf
    goto loc_4c95;                              //jmp loc_4c95
loc_4c8a:                                       //loc_4c8a:
    _al = 0x0a;                                 //mov al, 0xa
    if (memory(_ds, 25865) == 0x00)             //jz loc_4c95
        goto loc_4c95;
    _al = 0x15;                                 //mov al, 0x15
loc_4c95:                                       //loc_4c95:
    _ah = memory(_ds, 21125);                   //mov ah, byte ptr [0x5285]
    _ah &= 0x80;                                //and ah, 0x80
    memory16(_ds, 0x5280) = _ax;                //mov [0x5280], ax
    _bp = _pop();                               //pop bp
    _ax = _pop();                               //pop ax
loc_4ca1:                                       //loc_4ca1:
    return;                                     //ret
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 50h");                           //db 50h
    _STOP_("db a1h");                           //db a1h
    _STOP_("db 82h");                           //db 82h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db f8h");                           //db f8h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db f8h");                           //db f8h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db f8h");                           //db f8h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db f8h");                           //db f8h
    _STOP_("db 29h");                           //db 29h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 7ch");                           //db 7ch
    _STOP_("db 52h");                           //db 52h
    _STOP_("db c7h");                           //db c7h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 82h");                           //db 82h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 14h");                           //db 14h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 13h");                           //db 13h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 14h");                           //db 14h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 14h");                           //db 14h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 58h");                           //db 58h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 1ch");                           //db 1ch
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 84h");                           //db 84h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db 02h");                           //db 02h
    _STOP_("db ebh");                           //db ebh
    _STOP_("db b7h");                           //db b7h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 7eh");                           //db 7eh
    _STOP_("db 52h");                           //db 52h
    _STOP_("db f0h");                           //db f0h
    _STOP_("sp-trace-fail");                    //sub_4c65 endp_failed
    _STOP_("continues");                        //sub_4cf0 proc near
}

void sub_4cf0()
{
    memory16(_ds, 21130) = 0x0000;              //mov word ptr [0x528a], 0x0
    _STOP_("sp-trace-fail");                    //sub_4cf0 endp_failed
    _STOP_("continues");                        //sub_4cf6 proc near
}

void sub_4cf6()
{
    _flags.carry = memory(_ds, 25871) < 0x01;   //sub byte ptr [0x650f], 0x1
    memory(_ds, 25871) -= 0x01;
    memory(_ds, 25871) = memory(_ds, 25871) + 0x00 + _flags.carry;
    memory(_ds, 25885) = 0x00;                  //mov byte ptr [0x651d], 0x0
    memory(_ds, 25894) = 0x02;                  //mov byte ptr [0x6526], 0x2
    return;                                     //ret
    _STOP_("db c3h");                           //db c3h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 99h");                           //db 99h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 50h");                           //db 50h
    _STOP_("db 53h");                           //db 53h
    _STOP_("db 51h");                           //db 51h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 57h");                           //db 57h
    _STOP_("db 56h");                           //db 56h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 55h");                           //db 55h
    _STOP_("db beh");                           //db beh
    _STOP_("db adh");                           //db adh
    _STOP_("db 7bh");                           //db 7bh
    _STOP_("db b9h");                           //db b9h
    _STOP_("db 64h");                           //db 64h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 39h");                           //db 39h
    _STOP_("db 7ch");                           //db 7ch
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db e2h");                           //db e2h
    _STOP_("db f6h");                           //db f6h
    _STOP_("db ebh");                           //db ebh
    _STOP_("db 64h");                           //db 64h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db fdh");                           //db fdh
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db c9h");                           //db c9h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 68h");                           //db 68h
    _STOP_("db 0ch");                           //db 0ch
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 44h");                           //db 44h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 88h");                           //db 88h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db b3h");                           //db b3h
    _STOP_("db 50h");                           //db 50h
    _STOP_("db b7h");                           //db b7h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db 2eh");                           //db 2eh
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 07h");                           //db 07h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db a6h");                           //db a6h
    _STOP_("db e5h");                           //db e5h
    _STOP_("db b3h");                           //db b3h
    _STOP_("db 28h");                           //db 28h
    _STOP_("db b7h");                           //db b7h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db c7h");                           //db c7h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db c4h");                           //db c4h
    _STOP_("db 32h");                           //db 32h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db b2h");                           //db b2h
    _STOP_("db 0ch");                           //db 0ch
    _STOP_("db f6h");                           //db f6h
    _STOP_("db f2h");                           //db f2h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db c3h");                           //db c3h
    _STOP_("db f6h");                           //db f6h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e0h");                           //db e0h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e0h");                           //db e0h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e0h");                           //db e0h
    _STOP_("db d1h");                           //db d1h
    _STOP_("db e0h");                           //db e0h
    _STOP_("db 50h");                           //db 50h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db c7h");                           //db c7h
    _STOP_("db 32h");                           //db 32h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db b2h");                           //db b2h
    _STOP_("db 14h");                           //db 14h
    _STOP_("db f6h");                           //db f6h
    _STOP_("db f2h");                           //db f2h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db c4h");                           //db c4h
    _STOP_("db 32h");                           //db 32h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db cfh");                           //db cfh
    _STOP_("db d3h");                           //db d3h
    _STOP_("db e0h");                           //db e0h
    _STOP_("db 5fh");                           //db 5fh
    _STOP_("db 03h");                           //db 03h
    _STOP_("db f8h");                           //db f8h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 44h");                           //db 44h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 5ah");                           //db 5ah
    _STOP_("db e0h");                           //db e0h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db f5h");                           //db f5h
    _STOP_("db 64h");                           //db 64h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db f8h");                           //db f8h
    _STOP_("db ebh");                           //db ebh
    _STOP_("db 01h");                           //db 01h
    _STOP_("db f9h");                           //db f9h
    _STOP_("db 5dh");                           //db 5dh
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 1fh");                           //db 1fh
    _STOP_("db 5eh");                           //db 5eh
    _STOP_("db 5fh");                           //db 5fh
    _STOP_("db 5ah");                           //db 5ah
    _STOP_("db 59h");                           //db 59h
    _STOP_("db 5bh");                           //db 5bh
    _STOP_("db 58h");                           //db 58h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 5fh");                           //db 5fh
    _STOP_("db c3h");                           //db c3h
    _STOP_("db a0h");                           //db a0h
    _STOP_("db 50h");                           //db 50h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 50h");                           //db 50h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 50h");                           //db 50h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 58h");                           //db 58h
    _STOP_("db a2h");                           //db a2h
    _STOP_("db 50h");                           //db 50h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 48h");                           //db 48h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 56h");                           //db 56h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db b5h");                           //db b5h
    _STOP_("db c3h");                           //db c3h
    _STOP_("sp-trace-fail");                    //sub_4cf6 endp_failed
    _STOP_("continues");                        //sub_4dc0 proc near
}

void sub_4dc0()
{
    sub_59e7();                                 //call sub_59e7
    memory(_ds, 25878) = 0x02;                  //mov byte ptr [0x6516], 0x2
    return;                                     //ret
    _STOP_("db b8h");                           //db b8h
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 30h");                           //db 30h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 24h");                           //db 24h
    _STOP_("db a1h");                           //db a1h
    _STOP_("db 7ch");                           //db 7ch
    _STOP_("db 52h");                           //db 52h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 64h");                           //db 64h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 16h");                           //db 16h
    _STOP_("db 7eh");                           //db 7eh
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 16h");                           //db 16h
    _STOP_("db e6h");                           //db e6h
    _STOP_("db 64h");                           //db 64h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 92h");                           //db 92h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e7h");                           //db e7h
    _STOP_("db 1fh");                           //db 1fh
    _STOP_("db 83h");                           //db 83h
    _STOP_("db ebh");                           //db ebh
    _STOP_("db 38h");                           //db 38h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db fbh");                           //db fbh
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 77h");                           //db 77h
    _STOP_("db 07h");                           //db 07h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db f8h");                           //db f8h
    _STOP_("db 64h");                           //db 64h
    _STOP_("db 89h");                           //db 89h
    _STOP_("db 16h");                           //db 16h
    _STOP_("db fah");                           //db fah
    _STOP_("db 64h");                           //db 64h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db a6h");                           //db a6h
    _STOP_("db feh");                           //db feh
    _STOP_("db c3h");                           //db c3h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db d8h");                           //db d8h
    _STOP_("db feh");                           //db feh
    _STOP_("db c3h");                           //db c3h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 84h");                           //db 84h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db e9h");                           //db e9h
    _STOP_("db c8h");                           //db c8h
    _STOP_("db feh");                           //db feh
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 8fh");                           //db 8fh
    _STOP_("db feh");                           //db feh
    _STOP_("db e8h");                           //db e8h
    _STOP_("db c2h");                           //db c2h
    _STOP_("db feh");                           //db feh
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 84h");                           //db 84h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db b9h");                           //db b9h
    _STOP_("db feh");                           //db feh
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 84h");                           //db 84h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db b0h");                           //db b0h
    _STOP_("db feh");                           //db feh
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 84h");                           //db 84h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 13h");                           //db 13h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db c4h");                           //db c4h
    _STOP_("db a0h");                           //db a0h
    _STOP_("db 87h");                           //db 87h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 24h");                           //db 24h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db bfh");                           //db bfh
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db bbh");                           //db bbh
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 07h");                           //db 07h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db b7h");                           //db b7h
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 08h");                           //db 08h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db f6h");                           //db f6h
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 05h");                           //db 05h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db e8h");                           //db e8h
    _STOP_("db a8h");                           //db a8h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db c7h");                           //db c7h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 7eh");                           //db 7eh
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 08h");                           //db 08h
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db 1eh");                           //db 1eh
    _STOP_("db 6ch");                           //db 6ch
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 9dh");                           //db 9dh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 1fh");                           //db 1fh
    _STOP_("db 32h");                           //db 32h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db a7h");                           //db a7h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 73h");                           //db 73h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db fch");                           //db fch
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db cbh");                           //db cbh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 2dh");                           //db 2dh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 3dh");                           //db 3dh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 74h");                           //db 74h
    _STOP_("db c2h");                           //db c2h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db feh");                           //db feh
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 16h");                           //db 16h
    _STOP_("db c7h");                           //db c7h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 7eh");                           //db 7eh
    _STOP_("db 52h");                           //db 52h
    _STOP_("db f0h");                           //db f0h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 7eh");                           //db 7eh
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 1dh");                           //db 1dh
    _STOP_("db 65h");                           //db 65h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db c3h");                           //db c3h
    _STOP_("db a0h");                           //db a0h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 56h");                           //db 56h
    _STOP_("db 3ch");                           //db 3ch
    _STOP_("db 15h");                           //db 15h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 4bh");                           //db 4bh
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 3fh");                           //db 3fh
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 23h");                           //db 23h
    _STOP_("db fch");                           //db fch
    _STOP_("db 53h");                           //db 53h
    _STOP_("db 57h");                           //db 57h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 64h");                           //db 64h
    _STOP_("db b1h");                           //db b1h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 45h");                           //db 45h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db d3h");                           //db d3h
    _STOP_("db f8h");                           //db f8h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db f8h");                           //db f8h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 05h");                           //db 05h
    _STOP_("db d3h");                           //db d3h
    _STOP_("db f8h");                           //db f8h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db d8h");                           //db d8h
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db fbh");                           //db fbh
    _STOP_("db 8eh");                           //db 8eh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 6ch");                           //db 6ch
    _STOP_("db 52h");                           //db 52h
    _STOP_("db bbh");                           //db bbh
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 72h");                           //db 72h
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 05h");                           //db 05h
    _STOP_("db d7h");                           //db d7h
    _STOP_("db 24h");                           //db 24h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 14h");                           //db 14h
    _STOP_("db bah");                           //db bah
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 45h");                           //db 45h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db d7h");                           //db d7h
    _STOP_("db 24h");                           //db 24h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 02h");                           //db 02h
    _STOP_("db f7h");                           //db f7h
    _STOP_("db dah");                           //db dah
    _STOP_("db 8bh");                           //db 8bh
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db e9h");                           //db e9h
    _STOP_("db 64h");                           //db 64h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db 15h");                           //db 15h
    _STOP_("db 5fh");                           //db 5fh
    _STOP_("db 5bh");                           //db 5bh
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db 11h");                           //db 11h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 82h");                           //db 82h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 1dh");                           //db 1dh
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 0ah");                           //db 0ah
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 0dh");                           //db 0dh
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 01h");                           //db 01h
    _STOP_("db c3h");                           //db c3h
loc_4f1c:                                       //loc_4f1c:
    _STOP_("goto loc_503b");                    //jmp loc_503b
}

void sub_4f1f()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    if ((short)memory16(_ds, _si + 14) < (short)0x0000)
        _STOP_("goto loc_4f1c");
    _si = 0x527c;                               //mov si, 0x527c
    _bx = _bx ^ _bx;                            //xor bx, bx
    sub_5045();                                 //call sub_5045
    if (_FIXME_)                                //jnc loc_4f1c
        _STOP_("goto loc_4f1c");
    memory16(_ds, 21118) = _dx;                 //mov word ptr [0x527e], dx
    _di = _ax;                                  //mov di, ax
    _al = memory(_ds, _di + 4);                 //mov al, byte ptr [di+0x4]
    _al -= 0x36;                                //sub al, 0x36
    if (_al > 0x01)                             //ja loc_4f4e
        goto loc_4f4e;
    memory(_ds, _di + 8) |= 0x02;               //or byte ptr [di+0x8], 0x2
    memory16(_ds, _di + 9) = _si;               //mov word ptr [di+0x9], si
loc_4f4e:                                       //loc_4f4e:
    _al = memory(_ds, _di + 4);                 //mov al, byte ptr [di+0x4]
    _al -= 0x33;                                //sub al, 0x33
    if (_al > 0x01)                             //ja loc_4f7b
        goto loc_4f7b;
    _ax = 0x0060;                               //mov ax, 0x60
    _dl = memory(_ds, 21121);                   //mov dl, byte ptr [0x5281]
    _dl &= 0x80;                                //and dl, 0x80
    if (_dl == 0)                               //jz loc_4f65
        goto loc_4f65;
    _ax = -_ax;                                 //neg ax
loc_4f65:                                       //loc_4f65:
    memory(_ds, _di + 5) &= 0x7f;               //and byte ptr [di+0x5], 0x7f
    memory(_ds, _di + 5) |= _dl;                //or byte ptr [di+0x5], dl
    memory16(_ds, _di + 6) = _ax;               //mov word ptr [di+0x6], ax
    memory(_ds, 25873) = 0x04;                  //mov byte ptr [0x6511], 0x4
    memory(_ds, 25859) = 0x00;                  //mov byte ptr [0x6503], 0x0
    goto loc_4fb9;                              //jmp loc_4fb9
loc_4f7b:                                       //loc_4f7b:
    if ((short)memory16(_ds, 25886) <= (short)0x000a)//jle loc_4fb9
        goto loc_4fb9;
    if (memory(_ds, 21127) & 0x0f)              //jnz loc_4fb9
        goto loc_4fb9;
    if (memory16(_ds, 21130) != 0x0000)         //jnz loc_4fb9
        goto loc_4fb9;
    _al = memory(_ds, _di + 4);                 //mov al, byte ptr [di+0x4]
    if (_al == 0x53)                            //jz loc_4f9b
        goto loc_4f9b;
    if (_al != 0x5e)                            //jnz loc_4fb9
        goto loc_4fb9;
loc_4f9b:                                       //loc_4f9b:
    _ax = 0x0030;                               //mov ax, 0x30
    if (!(memory(_ds, 21121) & 0x80))           //jz loc_4fa7
        goto loc_4fa7;
    _ax = -_ax;                                 //neg ax
loc_4fa7:                                       //loc_4fa7:
    memory16(_ds, _di + 6) = _ax;               //mov word ptr [di+0x6], ax
    _ah &= 0x80;                                //and ah, 0x80
    memory(_ds, _di + 5) &= 0x7f;               //and byte ptr [di+0x5], 0x7f
    memory(_ds, _di + 5) |= _ah;                //or byte ptr [di+0x5], ah
    memory(_ds, 25873) = 0x04;                  //mov byte ptr [0x6511], 0x4
loc_4fb9:                                       //loc_4fb9:
    _dx = 0x0010;                               //mov dx, 0x10
    _ax = memory16(_ds, _di + 6);               //mov ax, word ptr [di+0x6]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (_ax == 0)                               //jz loc_4fcc
        goto loc_4fcc;
    if (!_flags.sign)                           //jns loc_4fc7
        goto loc_4fc7;
    _dx = _dx ^ _dx;                            //xor dx, dx
loc_4fc7:                                       //loc_4fc7:
    _ax += _dx;                                 //add ax, dx
    memory16(_ds, 0x5282) = _ax;                //mov [0x5282], ax
loc_4fcc:                                       //loc_4fcc:
    if (memory(_ds, 25872) != 0x00)             //jnz loc_5029
        goto loc_5029;
    if ((short)memory16(_ds, 21130) <= (short)0x0030)//jle loc_5029
        goto loc_5029;
    _push(_di);                                 //push di
    sub_5133();                                 //call sub_5133
    if (_FIXME_)                                //jz loc_5029
        goto loc_5029;
    _ax = memory16(_ds, 0x528a);                //mov ax, [0x528a]
    _dx = 0xfff0;                               //mov dx, 0xfff0
    if (memory(_ds, 1069) == 0x00)              //jz loc_4ff0
        goto loc_4ff0;
    _dx = 0x0030;                               //mov dx, 0x30
loc_4ff0:                                       //loc_4ff0:
    if (memory(_ds, 1070) != 0x00)              //jnz loc_4ffb
        goto loc_4ffb;
    _flags.sign = (short)(_ax + _dx) < 0;       //add ax, dx
    _ax += _dx;
    if (!_flags.sign)                           //jns loc_4ffd
        goto loc_4ffd;
loc_4ffb:                                       //loc_4ffb:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_4ffd:                                       //loc_4ffd:
    _ax = -_ax;                                 //neg ax
    memory16(_ds, 0x528a) = _ax;                //mov [0x528a], ax
    memory16(_ds, 25886) = 0x0000;              //mov word ptr [0x651e], 0x0
    if (memory16(_ds, _di + 14) != 0x0000)      //jnz loc_503b
        goto loc_503b;
    _al = 0x0c;                                 //mov al, 0xc
    sub_11e6();                                 //call sub_11e6
    _ax = memory16(_ds, 0x528a);                //mov ax, [0x528a]
    _ax = -_ax;                                 //neg ax
    memory16(_ds, _di + 14) = _ax;              //mov word ptr [di+0xe], ax
    _cl = 0x04;                                 //mov cl, 0x4
    _sar(_ax, _cl);                             //sar ax, cl
    memory16(_ds, _di + 2) -= _ax;              //sub word ptr [di+0x2], ax
    memory(_ds, 25873) = 0x04;                  //mov byte ptr [0x6511], 0x4
    goto loc_503b;                              //jmp loc_503b
loc_5029:                                       //loc_5029:
    _ax = memory16(_ds, _di + 14);              //mov ax, word ptr [di+0xe]
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz loc_5038
        goto loc_5038;
    memory16(_ds, 0x528a) = _ax;                //mov [0x528a], ax
    sub_4cf6();                                 //call sub_4cf6
    goto loc_503b;                              //jmp loc_503b
loc_5038:                                       //loc_5038:
    sub_4cf0();                                 //call sub_4cf0
loc_503b:                                       //loc_503b:
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_5045()
{
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _bh &= 0x1f;                                //and bh, 0x1f
    _bx <<= 1;                                  //shl bx, 1
    _al = memory(_ds, _bx + 27639);             //mov al, byte ptr [bx+0x6bf7]
    _ah = _ah ^ _ah;                            //xor ah, ah
    memory16(_ds, 0x64ef) = _ax;                //mov [0x64ef], ax
    _bl = memory(_ds, _bx + 26213);             //mov bl, byte ptr [bx+0x6665]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _ax = memory16(_ds, _si);                   //mov ax, word ptr [si]
    _dx = memory16(_ds, _si + 2);               //mov dx, word ptr [si+0x2]
    _bx >>= 1;                                  //shr bx, 1
    _ax -= _bx;                                 //sub ax, bx
    memory16(_ds, 0x64f1) = _ax;                //mov [0x64f1], ax
    memory16(_ds, 25843) = _dx;                 //mov word ptr [0x64f3], dx
    _cx = 0x0028;                               //mov cx, 0x28
    _di = 0x52a0;                               //mov di, 0x52a0
loc_5071:                                       //loc_5071:
    if (_si == _di)                             //jz loc_508c
        goto loc_508c;
    _bx = memory16(_ds, _di + 4);               //mov bx, word ptr [di+0x4]
    if (_bx == 0xffff)                      //jz loc_508c
        goto loc_508c;
    _bh &= 0x1f;                                //and bh, 0x1f
    if (!(memory(_ds, _bx + 28441) & 0x01))     //jz loc_508c
        goto loc_508c;
    sub_5153();                                 //call sub_5153
    if (_flags.carry)                           //jc loc_5092
        goto loc_5092;
loc_508c:                                       //loc_508c:
    _di += 0x0012;                              //add di, 0x12
    if (--_cx)                                  //loop loc_5071
        goto loc_5071;
    _flags.carry = false;                       //clc
loc_5092:                                       //loc_5092:
    _di = _pop();                               //pop di
    _cx = _pop();                               //pop cx
}

void sub_5095()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_dx);                                 //push dx
    _ax = memory16(_ds, _si);                   //mov ax, word ptr [si]
    _ax = _ax - memory16(_ds, _di);             //sub ax, word ptr [di]
    if ((short)_ax >= 0)                        //jns loc_50a0
        goto loc_50a0;
    _ax = -_ax;                                 //neg ax
loc_50a0:                                       //loc_50a0:
    if (_ax >= 0x0040)                          //jnc loc_511d
        goto loc_511d;
    _ax = memory16(_ds, _si + 2);               //mov ax, word ptr [si+0x2]
    _ax = _ax - memory16(_ds, _di + 2);         //sub ax, word ptr [di+0x2]
    if ((short)_ax >= 0)                        //jns loc_50af
        goto loc_50af;
    _ax = -_ax;                                 //neg ax
loc_50af:                                       //loc_50af:
    if (_ax >= 0x0046)                          //jnc loc_511d
        goto loc_511d;
    _ax = memory16(_ds, _si + 2);               //mov ax, word ptr [si+0x2]
    _dx = memory16(_ds, _di + 2);               //mov dx, word ptr [di+0x2]
    _bx = memory16(_ds, _si + 4);               //mov bx, word ptr [si+0x4]
    if ((short)_ax >= (short)_dx)               //jge loc_50c5
        goto loc_50c5;
    _xchg(_ax, _dx);                            //xchg ax, dx
    _bx = memory16(_ds, _di + 4);               //mov bx, word ptr [di+0x4]
loc_50c5:                                       //loc_50c5:
    _bh &= 0x1f;                                //and bh, 0x1f
    _bx <<= 1;                                  //shl bx, 1
    _bl = memory(_ds, _bx + 27640);             //mov bl, byte ptr [bx+0x6bf8]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bx -= 0x0003;                              //sub bx, 0x3
    _ax -= _bx;                                 //sub ax, bx
    if ((short)_ax >= (short)_dx)               //jge loc_511d
        goto loc_511d;
    _bx = memory16(_ds, _si + 4);               //mov bx, word ptr [si+0x4]
    _bh &= 0x1f;                                //and bh, 0x1f
    _bx <<= 1;                                  //shl bx, 1
    _bp = _bx;                                  //mov bp, bx
    _al = memory(_ds, _bx + 26927);             //mov al, byte ptr [bx+0x692f]
    _ah = _ah ^ _ah;                            //xor ah, ah
    _dx = memory16(_ds, _si);                   //mov dx, word ptr [si]
    _dx -= _ax;                                 //sub dx, ax
    _bx = memory16(_ds, _di + 4);               //mov bx, word ptr [di+0x4]
    _bh &= 0x1f;                                //and bh, 0x1f
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _di);                   //mov ax, word ptr [di]
    _flags.carry = _al < memory(_ds, _bx + 26927);//sub al, byte ptr [bx+0x692f]
    _al = _al - memory(_ds, _bx + 26927);
    _ah -= 0x00 + _flags.carry;                 //sbb ah, 0x0
    _bl = memory(_ds, _bx + 27639);             //mov bl, byte ptr [bx+0x6bf7]
    _bl >>= 1;                                  //shr bl, 1
    if ((short)_ax < (short)_dx)                //jl loc_5110
        goto loc_5110;
    _xchg(_ax, _dx);                            //xchg ax, dx
    _bl = memory(_ds, _bp + 27639);             //mov bl, byte ptr ds:[bp+0x6bf7]
    _bl >>= 1;                                  //shr bl, 1
loc_5110:                                       //loc_5110:
    _bh = _bh ^ _bh;                            //xor bh, bh
    _ax += _bx;                                 //add ax, bx
    if ((short)_ax <= (short)_dx)               //jle loc_511d
        goto loc_511d;
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    _flags.carry = true;                        //stc
    return;                                     //ret
loc_511d:                                       //loc_511d:
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    _flags.carry = false;                       //clc
}

void sub_5122()
{
    _ax = memory16(_ds, _si);                   //mov ax, word ptr [si]
    _dx = 0x000c;                               //mov dx, 0xc
    if (!(memory(_ds, _si + 5) & 0x80))         //jz loc_5130
        goto loc_5130;
    _dx = 0xfff6;                               //mov dx, 0xfff6
loc_5130:                                       //loc_5130:
    _ax += _dx;                                 //add ax, dx
}

void sub_5133()
{
    _push(_bx);                                 //push bx
    _push(_bp);                                 //push bp
    _bp = _sp;                                  //mov bp, sp
    ///_STOP_("db 01h");                           //db 01h
    //word ptr [BP + param_1+0x4]
    // gabo stack
    _bx = memory16(_ss, _bp + 0 + 0x4);
    _bx = memory16(_ds, _bx + 4);               //mov bx, word ptr [bx+0x4]
    _bh &= 0x1f;                                //and bh, 0x1f
    if (_bl < 0x65)                             //jc loc_5149
        goto loc_5149;
    _bx = _bx ^ _bx;                            //xor bx, bx
    _flags.zero = 1;
    goto loc_514e;                              //jmp loc_514e
loc_5149:                                       //loc_5149:
loc_514e:                                       //loc_514e:
    _bp = _pop();                               //pop bp
    _bx = _pop();                               //pop bx
    _stackReduce(2);                            //ret 0x2
    _flags.zero = 0;
    return;
}

void sub_5153()
{
    _bx = memory16(_ds, _di);                   //mov bx, word ptr [di]
    _bx -= _ax;                                 //sub bx, ax
    if ((short)_bx >= 0)                        //jns loc_515b
        goto loc_515b;
    _bx = -_bx;                                 //neg bx
loc_515b:                                       //loc_515b:
    if (_bx > 0x0040)                           //ja loc_51c3
        goto loc_51c3;
    _bx = memory16(_ds, _di + 2);               //mov bx, word ptr [di+0x2]
    _bx -= _dx;                                 //sub bx, dx
    if ((short)_bx >= 0)                        //jns loc_5169
        goto loc_5169;
    _bx = -_bx;                                 //neg bx
loc_5169:                                       //loc_5169:
    if (_bx > 0x0046)                           //ja loc_51c3
        goto loc_51c3;
    _bx = memory16(_ds, _di + 4);               //mov bx, word ptr [di+0x4]
    _bh &= 0x1f;                                //and bh, 0x1f
    _bx <<= 1;                                  //shl bx, 1
    _bp = _bx;                                  //mov bp, bx
    _bl = memory(_ds, _bx + 27639);             //mov bl, byte ptr [bx+0x6bf7]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _push(_bx);                                 //push bx
    _bx >>= 1;                                  //shr bx, 1
    _dx = memory16(_ds, _di);                   //mov dx, word ptr [di]
    _dx -= _bx;                                 //sub dx, bx
    _bx = _pop();                               //pop bx
    if ((short)_dx <= (short)_ax)               //jle loc_518f
        goto loc_518f;
    _xchg(_ax, _dx);                            //xchg ax, dx
    _bx = memory16(_ds, 25839);                 //mov bx, word ptr [0x64ef]
loc_518f:                                       //loc_518f:
    _dx += _bx;                                 //add dx, bx
    if ((short)_dx <= (short)_ax)               //jle loc_51bc
        goto loc_51bc;
    _bl = memory(_ds, _bp + 27640);             //mov bl, byte ptr ds:[bp+0x6bf8]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bp = _bx;                                  //mov bp, bx
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _dx = memory16(_ds, _di + 2);               //mov dx, word ptr [di+0x2]
    _ax = memory16(_ds, 0x64f3);                //mov ax, [0x64f3]
    _dx -= _bx;                                 //sub dx, bx
    if ((short)_dx < (short)_ax)                //jl loc_51bc
        goto loc_51bc;
    _dx += _bx;                                 //add dx, bx
    _dx -= _bp;                                 //sub dx, bp
    if ((short)_dx > (short)_ax)                //jg loc_51bc
        goto loc_51bc;
    _ax = _di;                                  //mov ax, di
    _flags.carry = true;                        //stc
    return;                                     //ret
loc_51bc:                                       //loc_51bc:
    _ax = memory16(_ds, 0x64f1);                //mov ax, [0x64f1]
    _dx = memory16(_ds, 25843);                 //mov dx, word ptr [0x64f3]
loc_51c3:                                       //loc_51c3:
    _flags.carry = false;                       //clc
    return;                                     //ret
    _STOP_("db 00h");                           //db 00h
    _STOP_("sp-trace-fail");                    //sub_5153 endp_failed
    _STOP_("continues");                        //sub_51c6 proc near
}

void sub_51c6()
{
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    sub_5338();                                 //call sub_5338
    memory16(_ds, 1084) = 0x0000;               //mov word ptr [0x43c], 0x0
loc_51d4:                                       //loc_51d4:
    memory(_ds, 34772) = 0x00;                  //mov byte ptr [0x87d4], 0x0
loc_51d9:                                       //loc_51d9:
    if (memory16(_ds, 10) < 0x07c8)             //jc loc_51f1
        goto loc_51f1;
    if (memory16(_ds, 1084) < 0x0ca8)           //jc loc_51f1
        goto loc_51f1;
    sub_191c();                                 //call sub_191c
    sub_53c8();                                 //call sub_53c8       -- VGA
    goto loc_51d4;                              //jmp loc_51d4
loc_51f1:                                       //loc_51f1:
    sub_0805();                                 //call sub_0805
    _sync();
    if (memory(_ds, 1069) == 0x00)              //jz loc_520b
        goto loc_520b;
    if (memory(_ds, 34772) == 0x00)             //jz loc_520b
        goto loc_520b;
    sub_5252();                                 //call sub_5252
    memory(_ds, 34772) -= 1;                    //dec byte ptr [0x87d4]
    goto loc_51d9;                              //jmp loc_51d9
loc_520b:                                       //loc_520b:
    if (memory(_ds, 1070) == 0x00)              //jz loc_5222
        goto loc_5222;
    if (memory(_ds, 34772) != 0x00)             //jnz loc_5222
        goto loc_5222;
    sub_5252();                                 //call sub_5252
    memory(_ds, 34772) += 1;                    //inc byte ptr [0x87d4]
    goto loc_51d9;                              //jmp loc_51d9
loc_5222:                                       //loc_5222:
    if (memory(_ds, 1067) != 0x00)              //jnz loc_522b
        goto loc_522b;
    goto loc_51d9;                              //jmp loc_51d9
loc_522b:                                       //loc_522b:
    if (memory(_ds, 34772) == 0x00)             //jz loc_5244
        goto loc_5244;
    sub_027b();                                 //call sub_027b
    if (_FIXME_)                                //jc loc_523a
        goto loc_523a;
    memory(_ds, 0x5250) = _al;                  //mov [0x5250], al
loc_523a:                                       //loc_523a:
    sub_53c8();                                 //call sub_53c8
    memory(_ds, 34772) = 0x00;                  //mov byte ptr [0x87d4], 0x0
    goto loc_51d9;                              //jmp loc_51d9
loc_5244:                                       //loc_5244:
    sub_0805();                                 //call sub_0805
    if (memory(_ds, 1067) != 0x00)              //jnz loc_5244
        goto loc_5244;
    sub_5645();                                 //call sub_5645
}

void sub_5252()
{
    

    _al = memory(_cs, 0x1);                     //mov al, cs:[0x1]
    if (_al == 0x05)                            //jz loc_5260
        goto loc_5260;
    if (_al >= 0x03)                            //jnc loc_528b
        goto loc_528b;
    goto loc_52bb;                              //jmp loc_52bb
loc_5260:                                       //loc_5260:
    _push(_ds);                                 //push ds
    _ax = 0xa000;                               //mov ax, 0xa000
    _ds = _ax;                                  //mov ds, ax
    _si = 0xc878;                               //mov si, 0xc878
    _di = 0xd8b8;                               //mov di, 0xd8b8
    _dx = 0x0008;                               //mov dx, 0x8
loc_526f:                                       //loc_526f:
    _cx = 0x0004;                               //mov cx, 0x4
loc_5272:                                       //loc_5272:
    _ax = memoryVideoGet16(_ds, _di);                   //mov ax, word ptr [di]
    {
        int t = memoryVideoGet16(_ds, _si);
        memoryVideoSet16(_ds, _si, _ax);
        _ax = t;
    //_xchg(memory16(_ds, _si), _ax);             //xchg word ptr [si], ax
    }
    memoryVideoSet16(_ds, _di, _ax);                   //mov word ptr [di], ax
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_5272
        goto loc_5272;
    _si += 0x0138;                              //add si, 0x138
    _di += 0x0138;                              //add di, 0x138
    _dx -= 1;                                   //dec dx
    if (_dx != 0)                               //jnz loc_526f
        goto loc_526f;
    _ds = _pop();                               //pop ds
    return;                                     //ret
loc_528b:                                       //loc_528b:
    _push(_ds);                                 //push ds
    _ax = 0xa000;                               //mov ax, 0xa000
    _ds = _ax;                                  //mov ds, ax
    sub_32f4();                                 //call sub_32f4
    _cx = 0x0008;                               //mov cx, 0x8
    _si = 0x190f;                               //mov si, 0x190f
    _di = 0x1b17;                               //mov di, 0x1b17
loc_529d:                                       //loc_529d:
    _al = memory(_ds, _si);                     //mov al, byte ptr [si]
    memory(_ds, 0x00) = _al;                    //mov [0x0], al
    _al = memory(_ds, _di);                     //mov al, byte ptr [di]
    memory(_ds, _si) = _al;                     //mov byte ptr [si], al
    _al = memory(_ds, 0x00);                    //mov al, [0x0]
    memory(_ds, _di) = _al;                     //mov byte ptr [di], al
    _al = memory(_ds, 0x01);                    //mov al, [0x1]
    memory(_ds, 0x00) = _al;                    //mov [0x0], al
    _si += 0x0028;                              //add si, 0x28
    _di += 0x0028;                              //add di, 0x28
    if (--_cx)                                  //loop loc_529d
        goto loc_529d;
    _ds = _pop();                               //pop ds
    return;                                     //ret
loc_52bb:                                       //loc_52bb:
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = 0xb800;                               //mov ax, 0xb800
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _cx = 0x0005;                               //mov cx, 0x5
    _si = 0x191e;                               //mov si, 0x191e
    _di = 0x1afe;                               //mov di, 0x1afe
loc_52cd:                                       //loc_52cd:
    _ax = memory16(_ds, _si);                   //mov ax, word ptr [si]
    _xchg(memory16(_es, _di), _ax);             //xchg word ptr es:[di], ax
    memory16(_ds, _si) = _ax;                   //mov word ptr [si], ax
    _ax = memory16(_ds, _si + 8192);            //mov ax, word ptr [si+0x2000]
    _xchg(memory16(_es, _di + 0x2000), _ax);    //xchg word ptr es:[di+0x2000], ax
    memory16(_ds, _si + 8192) = _ax;            //mov word ptr [si+0x2000], ax
    _si += 0x0050;                              //add si, 0x50
    _di += 0x0050;                              //add di, 0x50
    if (--_cx)                                  //loop loc_52cd
        goto loc_52cd;
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_52ec()
{
    

    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _al = memory(_cs, 0x1);                     //mov al, cs:[0x1]
    if (_al != 0x05)                            //jnz loc_5315
        goto loc_5315;
    _push(_ds);                                 //push ds
    _dx = 0x878c;                               //mov dx, 0x878c
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    sub_097b();                                 //call sub_097b
    // eax=11e9 (1ffc, asiok), bx=5 (7!?), cx=204 (ok), dx=8a (ok)
    // si=e7f(ok), di=4100(ok)
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    memory16(_ds, 0x04c1) = _ax;                //mov [0x4c1], ax
    memory16(_ds, 0x526c) = _ax;                //mov [0x526c], ax
    _ax = 0x000f;                               //mov ax, 0xf
    sub_10ff();                                 //call sub_10ff
    sub_5557();                                 //call sub_5557   -- VGA
    _ds = _pop();                               //pop ds
    return;                                     //ret
loc_5315:                                       //loc_5315:
    _push(_ds);                                 //push ds
    _dx = 0x8796;                               //mov dx, 0x8796
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    sub_097b();                                 //call sub_097b
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    memory16(_ds, 0x04c1) = _ax;                //mov [0x4c1], ax
    memory16(_ds, 0x526c) = _ax;                //mov [0x526c], ax
    _ax = 0x000f;                               //mov ax, 0xf
    sub_10ff();                                 //call sub_10ff
    memory16(_cs, 0x6676) = 0x6678;             //mov word ptr cs:[0x6676], 0x6678
    sub_5477();                                 //call sub_5477
    _ds = _pop();                               //pop ds
}

void sub_5338()
{
    

    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _al = memory(_cs, 0x1);                     //mov al, cs:[0x1]
    if (_al == 0x05)                            //jz loc_534b
        goto loc_534b;
    if (_al >= 0x03)                            //jnc loc_5373
        goto loc_5373;
    goto loc_5373;                              //jmp loc_5373
loc_534b:                                       //loc_534b:
    _push(_ds);                                 //push ds
    _dx = 0x87a3;                               //mov dx, 0x87a3
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    sub_097b();                                 //call sub_097b
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    memory16(_ds, 0x04c1) = _ax;                //mov [0x4c1], ax
    memory16(_ds, 0x526c) = _ax;                //mov [0x526c], ax
    if (memory(_ds, 34771) == 0x00)             //jz loc_5366
        goto loc_5366;
    sub_03f2();                                 //call sub_03f2
loc_5366:                                       //loc_5366:
    memory(_ds, 34771) = 0x01;                  //mov byte ptr [0x87d3], 0x1
    sub_5645();                                 //call sub_5645
    sub_5557();                                 //call sub_5557
    _ds = _pop();                               //pop ds
    return;                                     //ret
loc_5373:                                       //loc_5373:
    _push(_ds);                                 //push ds
    _dx = 0x87ac;                               //mov dx, 0x87ac
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    sub_097b();                                 //call sub_097b
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    memory16(_ds, 0x04c1) = _ax;                //mov [0x4c1], ax
    memory16(_ds, 0x526c) = _ax;                //mov [0x526c], ax
    if (memory(_ds, 34771) == 0x00)             //jz loc_538e
        goto loc_538e;
    sub_03f2();                                 //call sub_03f2
loc_538e:                                       //loc_538e:
    memory(_ds, 34771) = 0x01;                  //mov byte ptr [0x87d3], 0x1
    sub_1c30();                                 //call sub_1c30
    memory16(_cs, 0x6676) = 0x6698;             //mov word ptr cs:[0x6676], 0x6698
    sub_5477();                                 //call sub_5477
    _ds = _pop();                               //pop ds
}

void sub_53a2()
{
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _push(_ds);                                 //push ds
    _dx = 0x87b8;                               //mov dx, 0x87b8
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    sub_097b();                                 //call sub_097b
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    memory16(_ds, 0x04c1) = _ax;                //mov [0x4c1], ax
    memory16(_ds, 0x526c) = _ax;                //mov [0x526c], ax
    sub_5557();                                 //call sub_5557
    _cx = 0x0046;                               //mov cx, 0x46
loc_53be:                                       //loc_53be:
    sub_3243();                                 //call sub_3243
    if (--_cx)                                  //loop loc_53be
        goto loc_53be;
    sub_5645();                                 //call sub_5645
    _ds = _pop();                               //pop ds
}

void sub_53c8()
{
    

    _al = memory(_cs, 0x1);                     //mov al, cs:[0x1]
    if (_al == 0x05)                            //jz loc_53d9
        goto loc_53d9;
    if (_al < 0x03)                             //jc loc_53d7
        goto loc_53d7;
    {sub_5477(); return; };                     //
loc_53d7:                                       //loc_53d7:
    goto loc_5425;                              //jmp loc_5425
loc_53d9:                                       //loc_53d9:
    _push(_ds);                                 //push ds
    _ax = 0x0013;                               //mov ax, 0x13  ---- set VGA!!!!!!
    _interrupt(16);                             //int 0x10
    sub_1c30();                                 //call sub_1c30
    sub_3243();                                 //call sub_3243
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _ds = memory16(_ds, 21100);                 //mov ds, word ptr [0x526c]
    _si = _si ^ _si;                            //xor si, si
    _ax = 0xa000;                               //mov ax, 0xa000
    _es = _ax;                                  //mov es, ax
    _dx = 0x03c8;                               //mov dx, 0x3c8
    _al = 0x00;                                 //mov al, 0x0
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _cx = 0x0100;                               //mov cx, 0x100
loc_53ff:                                       //loc_53ff:
    _lodsb<MemData, DirForward>();              //lodsb
    goto loc_5402;                              //jmp loc_5402
loc_5402:                                       //loc_5402:
    _out(_dx, _al);                             //out dx, al
    _lodsb<MemData, DirForward>();              //lodsb
    goto loc_5406;                              //jmp loc_5406
loc_5406:                                       //loc_5406:
    _out(_dx, _al);                             //out dx, al
    _lodsb<MemData, DirForward>();              //lodsb
    goto loc_540a;                              //jmp loc_540a
loc_540a:                                       //loc_540a:
    _out(_dx, _al);                             //out dx, al
    if (--_cx)                                  //loop loc_53ff
        goto loc_53ff;
    _si = _ds;                                  //mov si, ds
    _si += 0x0030;                              //add si, 0x30
    _ds = _si;                                  //mov ds, si
    _si = _si ^ _si;                            //xor si, si
    _cx = 0x7d00;                               //mov cx, 0x7d00
    _di = _di ^ _di;                            //xor di, di
    _rep_movsw<MemData, MemData, DirForward>(); //rep movsw
    sub_3243();                                 //call sub_3243
    sub_1c1a();                                 //call sub_1c1a
    _ds = _pop();                               //pop ds
    return;                                     //ret
loc_5425:                                       //loc_5425:
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _ds = memory16(_ds, 21100);                 //mov ds, word ptr [0x526c]
    goto loc_544d;                              //jmp loc_544d
loc_5439:                                       //loc_5439:
    sub_3160();                                 //call sub_3160
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _ds = memory16(_ds, 21100);                 //mov ds, word ptr [0x526c]
    _si = _si ^ _si;                            //xor si, si
    _ax = 0x28c8;                               //mov ax, 0x28c8
    sub_65be();                                 //call sub_65be
loc_544d:                                       //loc_544d:
    _si = _si ^ _si;                            //xor si, si
    _di = _di ^ _di;                            //xor di, di
    _ax = 0xb800;                               //mov ax, 0xb800
    _es = _ax;                                  //mov es, ax
    _dx = 0x0064;                               //mov dx, 0x64
loc_5459:                                       //loc_5459:
    _cx = 0x0028;                               //mov cx, 0x28
    _rep_movsw<MemData, MemData, DirForward>(); //rep movsw
    _di += 0x1fb0;                              //add di, 0x1fb0
    _cl = 0x28;                                 //mov cl, 0x28
    _rep_movsw<MemData, MemData, DirForward>(); //rep movsw
    _di -= 0x2000;                              //sub di, 0x2000
    _dx -= 1;                                   //dec dx
    if (_dx != 0)                               //jnz loc_5459
        goto loc_5459;
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_5477()
{
    

    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    if (memory(_cs, 0x1) < 0x03)                //jc loc_5439
        _STOP_("goto loc_5439");
    _ax = 0x000d;                               //mov ax, 0xd
    _interrupt(16);                             //int 0x10
    sub_1c30();                                 //call sub_1c30
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _ds = memory16(_ds, 21100);                 //mov ds, word ptr [0x526c]
    _si = _si ^ _si;                            //xor si, si
    _di = _di ^ _di;                            //xor di, di
    _ax = 0xa000;                               //mov ax, 0xa000
    _es = _ax;                                  //mov es, ax
    _dx = 0x03c4;                               //mov dx, 0x3c4
    _ax = 0x0102;                               //mov ax, 0x102
loc_54a8:                                       //loc_54a8:
    _out(_dx, _ax);                             //out dx, ax
    _cx = 0x0fa0;                               //mov cx, 0xfa0
    _rep_movsw<MemData, MemData, DirForward>(); //rep movsw
    _di = _di ^ _di;                            //xor di, di
    _ah <<= 1;                                  //shl ah, 1
    if (_ah < 0x10)                             //jc loc_54a8
        goto loc_54a8;
    sub_1c1a();                                 //call sub_1c1a
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    return;                                     //ret
loc_54c4:                                       //loc_54c4:
    sub_3160();                                 //call sub_3160
    sub_562d();                                 //call sub_562d
    _bx = 0x66e0;                               //mov bx, 0x66e0
    _ax = 0xb800;                               //mov ax, 0xb800
    _es = _ax;                                  //mov es, ax
    _di = _di ^ _di;                            //xor di, di
    _dl = 0xc8;                                 //mov dl, 0xc8
loc_54d6:                                       //loc_54d6:
    _ch = 0x50;                                 //mov ch, 0x50
loc_54d8:                                       //loc_54d8:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cl = 0x04;                                 //mov cl, 0x4
loc_54dc:                                       //loc_54dc:
    _lodsb<MemData, DirForward>();              //lodsb
    _xlat();                                    //xlat
    _flags.carry = !!(_al & 0x80);              //shl al, 1
    _al <<= 1;
    _rcl(_ah, 1);                               //rcl ah, 1
    _flags.carry = !!(_al & 0x80);              //shl al, 1
    _al <<= 1;
    _rcl(_ah, 1);                               //rcl ah, 1
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_54dc
        goto loc_54dc;
    memory(_es, _di) = _ah;                     //mov byte ptr es:[di], ah
    _di += 1;                                   //inc di
    _ch -= 1;                                   //dec ch
    if (_ch != 0)                               //jnz loc_54d8
        goto loc_54d8;
    if ((short)_di < (short)0x2000)             //jl loc_54ff
        goto loc_54ff;
    _di -= 0x2000;                              //sub di, 0x2000
    goto loc_5503;                              //jmp loc_5503
loc_54ff:                                       //loc_54ff:
    _di += 0x1fb0;                              //add di, 0x1fb0
loc_5503:                                       //loc_5503:
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz loc_54d6
        goto loc_54d6;
    return;                                     //ret
loc_5508:                                       //loc_5508:
    _ax = 0x000d;                               //mov ax, 0xd
    _interrupt(16);                             //int 0x10
    sub_1c30();                                 //call sub_1c30
    sub_562d();                                 //call sub_562d
    _dx = 0x03c4;                               //mov dx, 0x3c4
    _al = 0x02;                                 //mov al, 0x2
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _bl = 0x01;                                 //mov bl, 0x1
loc_551c:                                       //loc_551c:
    _al = _bl;                                  //mov al, bl
    _out(_dx, _al);                             //out dx, al
loc_551f:                                       //loc_551f:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cl = 0x08;                                 //mov cl, 0x8
loc_5523:                                       //loc_5523:
    _lodsb<MemData, DirForward>();              //lodsb
    if (!(_bl & _al))                           //jz loc_5529
        goto loc_5529;
    _flags.carry = true;                        //stc
loc_5529:                                       //loc_5529:
    _ASSERT(0); /* unk previous */ _rcl(_ah, 1);//rcl ah, 1
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_5523
        goto loc_5523;
    _al = _ah;                                  //mov al, ah
    _stosb<MemData, DirForward>();              //stosb
    if (_si < 0xfa00)                           //jc loc_551f
        goto loc_551f;
    _di = _di ^ _di;                            //xor di, di
    _si -= 0xfa00;                              //sub si, 0xfa00
    _bl <<= 1;                                  //shl bl, 1
    if (_bl < 0x10)                             //jc loc_551c
        goto loc_551c;
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _es = _ax;                                  //mov es, ax
    _dx = 0x87c2;                               //mov dx, 0x87c2
    _ax = 0x1002;                               //mov ax, 0x1002
    _interrupt(16);                             //int 0x10
    sub_1c1a();                                 //call sub_1c1a
    return;                                     //ret
    _STOP_("db 00h");                           //db 00h
    _STOP_("sp-trace-fail");                    //sub_5477 endp_failed
    _STOP_("continues");                        //sub_5557 proc near
}

void sub_5557()
{
    

    _al = memory(_cs, 0x1);                     //mov al, cs:[0x1]
    if (_al == 0x05)                            //jz loc_5566
        goto loc_5566;
    if (_al >= 0x03)                            //jnc loc_5508
        _STOP_("goto loc_5508");
    _STOP_("goto loc_54c4");                    //jmp loc_54c4
loc_5566:                                       //loc_5566:
    _push(_ds);                                 //push ds
    _ax = 0x0013;                               //mov ax, 0x13 ------ VGA
    _interrupt(16);                             //int 0x10
    sub_1c30();                                 //call sub_1c30
    sub_3243();                                 //call sub_3243
    _dx = 0x03c8;                               //mov dx, 0x3c8
    _al = 0x00;                                 //mov al, 0x0
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _cx = 0x0300;                               //mov cx, 0x300
loc_557c:                                       //loc_557c:
    _out(_dx, _al);                             //out dx, al
    if (--_cx)                                  //loop loc_557c
        goto loc_557c;
    sub_562d();                                 //call sub_562d
    _cx = 0x7d00;                               //mov cx, 0x7d00
    _rep_movsw<MemVideo, MemData, DirForward>(); //rep movsw
    sub_3243();                                 //call sub_3243
    sub_1c1a();                                 //call sub_1c1a
    _si = _ds;                                  //mov si, ds
    _si -= 0x0030;                              //sub si, 0x30
    _ds = _si;                                  //mov ds, si
loc_5594:                                       //loc_5594:
    memory(_cs, 0x5556) = 0x00;                 //mov byte ptr cs:[0x5556], 0x0
    _si = _si ^ _si;                            //xor si, si
    _bp = _bp ^ _bp;                            //xor bp, bp
loc_559e:                                       //loc_559e:
    if (memory(_cs, 0x5556) & 0x0f)             //jnz loc_55a9
        goto loc_55a9;
    _sync();
    sub_3243();                                 //call sub_3243 -- sync
loc_55a9:                                       //loc_55a9:
    if (memory(_cs, 0x3) == 0x00)               //jz loc_561d
        goto loc_561d;
    _dx = 0x03c7;                               //mov dx, 0x3c7
    _al = memory(_cs, 0x5556);                  //mov al, cs:[0x5556]
    _out(_dx, _al);                             //out dx, al
    _dl = 0xc9;                                 //mov dl, 0xc9
    goto loc_55bd;                              //jmp loc_55bd
loc_55bd:                                       //loc_55bd:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x3f;                                //and al, 0x3f
    _ah = _al;                                  //mov ah, al
    goto loc_55c4;                              //jmp loc_55c4
loc_55c4:                                       //loc_55c4:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x3f;                                //and al, 0x3f
    _bl = _al;                                  //mov bl, al
    goto loc_55cb;                              //jmp loc_55cb
loc_55cb:                                       //loc_55cb:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x3f;                                //and al, 0x3f
    _bh = _al;                                  //mov bh, al
    _dl = 0xc8;                                 //mov dl, 0xc8
    _al = memory(_cs, 0x5556);                  //mov al, cs:[0x5556]
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _al = _ah;                                  //mov al, ah
    //std::cout << "check R " << (int)memory(_ds, _si) << " " << (int)_al << "\n";
    if (memory(_ds, _si) <= _al)                //jbe loc_55e5
        goto loc_55e5;
    if (_al > 0x3d)                             //ja loc_55e5
        goto loc_55e5;
    _al += 0x02;                                //add al, 0x2
    //std::cout << " +a ";
    _bp += 1;                                   //inc bp
loc_55e5:                                       //loc_55e5:
    _out(_dx, _al);                             //out dx, al
    _al = _bl;                                  //mov al, bl
    //std::cout << "check G " << (int)memory(_ds, _si+1) << " " << (int)_al << "\n";
    if (memory(_ds, _si + 1) <= _al)            //jbe loc_55f4
        goto loc_55f4;
    if (_al > 0x3d)                             //ja loc_55f4
        goto loc_55f4;
    _al += 0x02;                                //add al, 0x2
    _bp += 1;                                   //inc bp
    //std::cout << " +b ";
loc_55f4:                                       //loc_55f4:
    _out(_dx, _al);                             //out dx, al
    _al = _bh;                                  //mov al, bh
    //std::cout << "check B " << (int)memory(_ds, _si+2) << " " << (int)_al << "\n";

    if (memory(_ds, _si + 2) <= _al)            //jbe loc_5603
        goto loc_5603;
    if (_al > 0x3d)                             //ja loc_5603
        goto loc_5603;
    _al += 0x02;                                //add al, 0x2
    _bp += 1;                                   //inc bp
    //std::cout << " +c ";

loc_5603:                                       //loc_5603:
    _out(_dx, _al);                             //out dx, al
    _si += 0x0003;                              //add si, 0x3
    {
    int phase = memory(_cs, 0x5556);
    memory(_cs, 0x5556) += 1;                   //inc byte ptr cs:[0x5556]
    }
    if (memory(_cs, 0x5556) < 0x40)             //jc loc_559e
        goto loc_559e;
    _bp |= _bp;                                 //or bp, bp
    
    
    _sync();
    
    if (_bp == 0)                               //jz loc_561b
        goto loc_561b;
    
    goto loc_5594;                              //jmp loc_5594
loc_561b:                                       //loc_561b:
    goto loc_562b;                              //jmp loc_562b
loc_561d:                                       //loc_561d:
    _dx = 0x03c8;                               //mov dx, 0x3c8
    _al = 0x00;                                 //mov al, 0x0
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _cx = 0x00c0;                               //mov cx, 0xc0
loc_5627:                                       //loc_5627:
    _lodsb<MemData, DirForward>();              //lodsb
    _out(_dx, _al);                             //out dx, al
    if (--_cx)                                  //loop loc_5627
        goto loc_5627;
loc_562b:                                       //loc_562b:
     
    _ds = _pop();                               //pop ds
}

void sub_562d()
{
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _si = memory16(_ds, 21100);                 //mov si, word ptr [0x526c]
    _si += 0x0030;                              //add si, 0x30
    _ds = _si;                                  //mov ds, si
    _si = _si ^ _si;                            //xor si, si
    _ax = 0xa000;                               //mov ax, 0xa000
    _es = _ax;                                  //mov es, ax
    _di = _di ^ _di;                            //xor di, di
}

void sub_5645()
{
loc_5645:
    

    if (memory(_cs, 0x3) == 0x00)               //jz loc_56cb
        goto loc_56cb;
    _al = memory(_cs, 0x1);                     //mov al, cs:[0x1]
    if (_al == 0x05)                            //jz loc_5656
        goto loc_5656;
    return;                                     //ret
loc_5656:                                       //loc_5656:
    memory(_cs, 0x5556) = 0x00;                 //mov byte ptr cs:[0x5556], 0x0
    _bp = _bp ^ _bp;                            //xor bp, bp
loc_565e:                                       //loc_565e:
    if (memory(_cs, 0x5556) & 0x0f)             //jnz loc_5669
        goto loc_5669;
    sub_3243();                                 //call sub_3243
loc_5669:                                       //loc_5669:
    _dx = 0x03c7;                               //mov dx, 0x3c7
    _al = memory(_cs, 0x5556);                  //mov al, cs:[0x5556]
    _out(_dx, _al);                             //out dx, al
    _dl = 0xc9;                                 //mov dl, 0xc9
    goto loc_5675;                              //jmp loc_5675
loc_5675:                                       //loc_5675:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x3f;                                //and al, 0x3f
    _ah = _al;                                  //mov ah, al
    goto loc_567c;                              //jmp loc_567c
loc_567c:                                       //loc_567c:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x3f;                                //and al, 0x3f
    _bl = _al;                                  //mov bl, al
    goto loc_5683;                              //jmp loc_5683
loc_5683:                                       //loc_5683:
    _in(_al, _dx);                              //in al, dx
    // 00, 3c, 14, 20, 08, 00, 00, 00, 00, 00
    _al &= 0x3f;                                //and al, 0x3f
    _bh = _al;                                  //mov bh, al
    _dl = 0xc8;                                 //mov dl, 0xc8
    _al = memory(_cs, 0x5556);                  //mov al, cs:[0x5556]
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _al = _ah;                                  //mov al, ah
    _flags.carry = _al < 0x01;                  //sub al, 0x1
    _al -= 0x01;
    _al = _al + 0x00 + _flags.carry;            //adc al, 0x0
    _flags.carry = _al < 0x01;                  //sub al, 0x1
    _al -= 0x01;
    _al = _al + 0x00 + _flags.carry;            //adc al, 0x0
    _bp |= _ax;                                 //or bp, ax
    _out(_dx, _al);                             //out dx, al
    _al = _bl;                                  //mov al, bl
    _flags.carry = _al < 0x01;                  //sub al, 0x1
    _al -= 0x01;
    _al = _al + 0x00 + _flags.carry;            //adc al, 0x0
    _flags.carry = _al < 0x01;                  //sub al, 0x1
    _al -= 0x01;
    _al = _al + 0x00 + _flags.carry;            //adc al, 0x0
    _bp |= _ax;                                 //or bp, ax
    _out(_dx, _al);                             //out dx, al
    _al = _bh;                                  //mov al, bh
    _flags.carry = _al < 0x01;                  //sub al, 0x1
    _al -= 0x01;
    _al = _al + 0x00 + _flags.carry;            //adc al, 0x0
    _flags.carry = _al < 0x01;                  //sub al, 0x1
    _al -= 0x01;
    _al = _al + 0x00 + _flags.carry;            //adc al, 0x0
    _bp |= _ax;                                 //or bp, ax
    _out(_dx, _al);                             //out dx, al
    memory(_cs, 0x5556) += 1;                   //inc byte ptr cs:[0x5556]
    if (memory(_cs, 0x5556) < 0x40)             //jc loc_565e
        goto loc_565e;
    
    
    //_ax = 0; _bx = 0; _bp = 0; std::cout << "gabo skip\n";
    
    
    _bp |= _bp;                                 //or bp, bp -- 020d:56c4
    if (_bp == 0)                               //jz loc_56cb
        goto loc_56cb;
    goto loc_5645;                              //jmp sub_5645
loc_56cb:                                       //loc_56cb:
    return;
}

void sub_56cc()
{
    _push(_si);                                 //push si
    _push(_cx);                                 //push cx
    _push(_bx);                                 //push bx
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _si = 0x7699;                               //mov si, 0x7699
    _cx = 0x0032;                               //mov cx, 0x32
    memory(_ds, 25853) = 0x00;                  //mov byte ptr [0x64fd], 0x0
loc_56df:                                       //loc_56df:
    _di = 0x87d3;                               //mov di, 0x87d3
    _ax = memory16(_ds, _si + 4);               //mov ax, word ptr [si+0x4]
    if (_ax == 0xffff)                          //jz loc_5700
        goto loc_5700;
    _ah &= 0x1f;                                //and ah, 0x1f
loc_56ed:                                       //loc_56ed:
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    if (memory16(_ds, _di) != _ax)              //jnz loc_56ed
        goto loc_56ed;
    memory16(_ds, _si + 10) = _di;              //mov word ptr [si+0xa], di
    _di = _ax;                                  //mov di, ax
    _al = memory(_ds, _di + 28869);             //mov al, byte ptr [di+0x70c5]
    memory(_ds, 25853) += _al;                  //add byte ptr [0x64fd], al
loc_5700:                                       //loc_5700:
    _si += 0x001a;                              //add si, 0x1a
    if (--_cx)                                  //loop loc_56df
        goto loc_56df;
    _si = 0x7dcb;                               //mov si, 0x7dcb
    _cx = 0x000a;                               //mov cx, 0xa
loc_570b:                                       //loc_570b:
    _ax = memory16(_ds, _si + 12);              //mov ax, word ptr [si+0xc]
    memory16(_ds, _si) = _ax;                   //mov word ptr [si], ax
    _ax = memory16(_ds, _si + 14);              //mov ax, word ptr [si+0xe]
    memory16(_ds, _si + 2) = _ax;               //mov word ptr [si+0x2], ax
    _al = memory(_ds, _si + 16);                //mov al, byte ptr [si+0x10]
    memory(_ds, _si + 6) = _al;                 //mov byte ptr [si+0x6], al
    memory16(_ds, _si + 17) = 0x0000;           //mov word ptr [si+0x11], 0x0
    _si += 0x0014;                              //add si, 0x14
    if (--_cx)                                  //loop loc_570b
        goto loc_570b;
    _bl = memory(_ds, 21072);                   //mov bl, byte ptr [0x5250]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _al = memory(_ds, _bx + 20660);             //mov al, byte ptr [bx+0x50b4]
    memory(_ds, 0x64e8) = _al;                  //mov [0x64e8], al
    _bx = _pop();                               //pop bx
    _cx = _pop();                               //pop cx
    _si = _pop();                               //pop si
}

void sub_5737()
{
    _si = 0x7699;                               //mov si, 0x7699
    _di = 0x5570;                               //mov di, 0x5570
    _bp = 0xffff;                               //mov bp, 0xffff
    memory16(_ds, 21876) = _bp;                 //mov word ptr [0x5574], bp
    memory16(_ds, 21894) = _bp;                 //mov word ptr [0x5586], bp
    memory16(_ds, 21912) = _bp;                 //mov word ptr [0x5598], bp
    memory16(_ds, 21930) = _bp;                 //mov word ptr [0x55aa], bp
    memory16(_ds, 21948) = _bp;                 //mov word ptr [0x55bc], bp
    memory16(_ds, 21966) = _bp;                 //mov word ptr [0x55ce], bp
    memory16(_ds, 21984) = _bp;                 //mov word ptr [0x55e0], bp
    memory16(_ds, 22002) = _bp;                 //mov word ptr [0x55f2], bp
    _ax = memory16(_ds, 0x5270);                //mov ax, [0x5270]
    _dx = memory16(_ds, 21106);                 //mov dx, word ptr [0x5272]
    _cl = 0x04;                                 //mov cl, 0x4
    _ax <<= _cl;                                //shl ax, cl
    _dx <<= _cl;                                //shl dx, cl
    _cx = 0x0032;                               //mov cx, 0x32
loc_5770:                                       //loc_5770:
    if (memory16(_ds, _si + 4) != _bp)          //jnz loc_5778
        goto loc_5778;
    goto loc_58a6;                              //jmp loc_58a6
loc_5778:                                       //loc_5778:
    memory(_ds, _si + 5) &= 0xdf;               //and byte ptr [si+0x5], 0xdf
    _bx = memory16(_ds, _si);                   //mov bx, word ptr [si]
    _bx += 0x0020;                              //add bx, 0x20
    _flags.carry = _bx < _ax;                   //sub bx, ax
    _bx -= _ax;
    if (!_flags.carry)                          //jnc loc_5788
        goto loc_5788;
    goto loc_589d;                              //jmp loc_589d
loc_5788:                                       //loc_5788:
    _bx -= 0x0040;                              //sub bx, 0x40
    if ((short)_bx <= (short)0x0140)            //jle loc_5794
        goto loc_5794;
    goto loc_589d;                              //jmp loc_589d
loc_5794:                                       //loc_5794:
    _bx = memory16(_ds, _si + 2);               //mov bx, word ptr [si+0x2]
    _flags.carry = _bx < _dx;                   //sub bx, dx
    _bx -= _dx;
    if (!_flags.carry)                          //jnc loc_579e
        goto loc_579e;
    goto loc_589d;                              //jmp loc_589d
loc_579e:                                       //loc_579e:
    _bx -= 0x0020;                              //sub bx, 0x20
    if ((short)_bx <= (short)0x00c0)            //jle loc_57aa
        goto loc_57aa;
    goto loc_589d;                              //jmp loc_589d
loc_57aa:                                       //loc_57aa:
    memory(_ds, _si + 5) |= 0x20;               //or byte ptr [si+0x5], 0x20
    _push(_ax);                                 //push ax
    _push(_dx);                                 //push dx
    sub_64ff();                                 //call sub_64ff
    memory16(_ds, _di + 9) = _si;               //mov word ptr [di+0x9], si
    _bx = memory16(_ds, _si);                   //mov bx, word ptr [si]
    memory16(_ds, _di) = _bx;                   //mov word ptr [di], bx
    _bx = memory16(_ds, _si + 2);               //mov bx, word ptr [si+0x2]
    memory16(_ds, _di + 2) = _bx;               //mov word ptr [di+0x2], bx
    _push(_cx);                                 //push cx
    _push(_si);                                 //push si
    if (!(memory(_ds, _si + 7) & 0xc0))         //jz loc_57cb
        goto loc_57cb;
    goto loc_5891;                              //jmp loc_5891
loc_57cb:                                       //loc_57cb:
    if (memory(_ds, 25876) != 0x00)             //jnz loc_57e8
        goto loc_57e8;
    if (memory16(_ds, _si + 4) != 0x05aa)       //jnz loc_57dc
        goto loc_57dc;
    goto loc_5891;                              //jmp loc_5891
loc_57dc:                                       //loc_57dc:
    _bx = memory16(_ds, _si + 6);               //mov bx, word ptr [si+0x6]
    _bh &= 0x1f;                                //and bh, 0x1f
    _bx <<= 1;                                  //shl bx, 1
    _indirectCall(memory16(_ds, _bx + 36571));  //call word ptr [bx+0x8edb]
loc_57e8:                                       //loc_57e8:
    if (memory(_ds, 25873) == 0x00)             //jz loc_5825
        goto loc_5825;
    _si = 0x52a0;                               //mov si, 0x52a0
    _cx = 0x0028;                               //mov cx, 0x28
loc_57f5:                                       //loc_57f5:
    if (memory16(_ds, _si + 6) != 0x0000)       //jnz loc_580a
        goto loc_580a;
    _ax = memory16(_ds, _si + 14);              //mov ax, word ptr [si+0xe]
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz loc_5820
        goto loc_5820;
    _ax = memory16(_ds, _si + 12);              //mov ax, word ptr [si+0xc]
    if (_ax < 0x000a)                           //jc loc_5820
        goto loc_5820;
loc_580a:                                       //loc_580a:
    _ax = _bx;                                  //mov ax, bx
    _bx = memory16(_ds, _si + 4);               //mov bx, word ptr [si+0x4]
    _bh &= 0x1f;                                //and bh, 0x1f
    _bx = _ax;                                  //mov bx, ax
    if (memory(_ds, _bx + 28441) & 0x10)        //jnz loc_5820
        goto loc_5820;
    sub_5095();                                 //call sub_5095
    if (_flags.carry)                           //jc loc_584e
        goto loc_584e;
loc_5820:                                       //loc_5820:
    _si += 0x0012;                              //add si, 0x12
    if (--_cx)                                  //loop loc_57f5
        goto loc_57f5;
loc_5825:                                       //loc_5825:
    if (memory(_ds, 25866) == 0x00)             //jz loc_5891
        goto loc_5891;
    if (memory(_ds, 25865) != 0x00)             //jnz loc_5891
        goto loc_5891;
    _si = 0x528e;                               //mov si, 0x528e
    if (memory16(_ds, _si + 4) == 0xffff)   //jz loc_5891
        goto loc_5891;
    sub_5095();                                 //call sub_5095
    if (!_flags.carry)                          //jnc loc_5891
        goto loc_5891;
    memory(_ds, 25883) = 0x00;                  //mov byte ptr [0x651b], 0x0
    memory16(_ds, _si + 4) = 0xffff;            //mov word ptr [si+0x4], 0xffff
    sub_58b0();                                 //call sub_58b0
loc_584e:                                       //loc_584e:
    if (memory(_ds, _si + 4) == 0x49)           //jz loc_5857
        goto loc_5857;
    memory16(_ds, _si + 6) = -memory16(_ds, _si + 6);//neg word ptr [si+0x6]
loc_5857:                                       //loc_5857:
    _al = 0x01;                                 //mov al, 0x1
    sub_11e6();                                 //call sub_11e6
    memory(_ds, 25866) = 0x00;                  //mov byte ptr [0x650a], 0x0
    _bx = memory16(_ds, _di + 4);               //mov bx, word ptr [di+0x4]
    _bh &= 0x1f;                                //and bh, 0x1f
    if (memory(_ds, _bx + 28768) == 0x00)       //jz loc_5888
        goto loc_5888;
    if (memory(_ds, 25883) != 0x00)             //jnz loc_5891
        goto loc_5891;
    memory(_ds, 25883) = 0x0a;                  //mov byte ptr [0x651b], 0xa
    memory(_ds, _di + 5) |= 0x40;               //or byte ptr [di+0x5], 0x40
    memory(_ds, 25832) -= 1;                    //dec byte ptr [0x64e8]
    if (memory(_ds, 25832) != 0)                //jnz loc_5891
        goto loc_5891;
    memory(_ds, 25853) -= 1;                    //dec byte ptr [0x64fd]
loc_5888:                                       //loc_5888:
    _bp = _sp;                                  //mov bp, sp
    _si = memory16(_ds, _bp + 0);               //mov si, word ptr [bp+0x0]
    memory(_ds, _si + 7) |= 0x80;               //or byte ptr [si+0x7], 0x80
loc_5891:                                       //loc_5891:
    _si = _pop();                               //pop si
    _cx = _pop();                               //pop cx
    _bp = 0xffff;                               //mov bp, 0xffff
    _di += 0x0012;                              //add di, 0x12
    _dx = _pop();                               //pop dx
    _ax = _pop();                               //pop ax
    goto loc_58a6;                              //jmp loc_58a6
loc_589d:                                       //loc_589d:
    if (!(memory(_ds, _si + 7) & 0xc0))         //jz loc_58a6
        goto loc_58a6;
    memory16(_ds, _si + 4) = _bp;               //mov word ptr [si+0x4], bp
loc_58a6:                                       //loc_58a6:
    _si += 0x001a;                              //add si, 0x1a
    _cx -= 1;                                   //dec cx
    if (_cx == 0)                               //jz loc_58af
        goto loc_58af;
    goto loc_5770;                              //jmp loc_5770
loc_58af:                                       //loc_58af:
    return;
}

void sub_58b0()
{
    memory16(_ds, 21138) = 0x002d;              //mov word ptr [0x5292], 0x2d
    memory16(_ds, 21140) = 0x0000;              //mov word ptr [0x5294], 0x0
    memory16(_ds, 21148) = 0x0000;              //mov word ptr [0x529c], 0x0
    memory(_ds, 25877) = 0x05;                  //mov byte ptr [0x6515], 0x5
}

void sub_58c8()
{
    _si = 0x5600;                               //mov si, 0x5600
    _dx = 0x0004;                               //mov dx, 0x4
    _cl = 0x04;                                 //mov cl, 0x4
loc_58d0:                                       //loc_58d0:
    if (memory16(_ds, _si + 4) == 0xffff)   //jz loc_5926
        goto loc_5926;
    _ax = memory16(_ds, _si + 6);               //mov ax, word ptr [si+0x6]
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz loc_58f0
        goto loc_58f0;
    _sar(_ax, _cl);                             //sar ax, cl
    memory16(_ds, _si) += _ax;                  //add word ptr [si], ax
    _ax = memory16(_ds, _si);                   //mov ax, word ptr [si]
    _ax >>= _cl;                                //shr ax, cl
    _flags.carry = _ax < memory16(_ds, 21104);  //sub ax, word ptr [0x5270]
    _ax = _ax - memory16(_ds, 21104);
    if (_flags.carry)                           //jc loc_590a
        goto loc_590a;
    if ((short)_ax > (short)0x0014)             //jg loc_590a
        goto loc_590a;
loc_58f0:                                       //loc_58f0:
    _ax = memory16(_ds, _si + 14);              //mov ax, word ptr [si+0xe]
    if (_ax == 0x0014)                          //jz loc_5911
        goto loc_5911;
    _sar(_ax, _cl);                             //sar ax, cl
    memory16(_ds, _si + 2) += _ax;              //add word ptr [si+0x2], ax
    _ax = memory16(_ds, _si + 2);               //mov ax, word ptr [si+0x2]
    _ax >>= _cl;                                //shr ax, cl
    _flags.carry = _ax < memory16(_ds, 21106);  //sub ax, word ptr [0x5272]
    _ax = _ax - memory16(_ds, 21106);
    if (_flags.carry)                           //jc loc_590a
        goto loc_590a;
    if ((short)_ax <= (short)0x00c0)            //jle loc_5911
        goto loc_5911;
loc_590a:                                       //loc_590a:
    memory16(_ds, _si + 4) = 0xffff;            //mov word ptr [si+0x4], 0xffff
    goto loc_5926;                              //jmp loc_5926
loc_5911:                                       //loc_5911:
    _di = 0x527c;                               //mov di, 0x527c
    sub_5095();                                 //call sub_5095
    if (!_flags.carry)                          //jnc loc_5926
        goto loc_5926;
    _bp = 0x0046;                               //mov bp, 0x46
    _ax = memory16(_ds, _si);                   //mov ax, word ptr [si]
    _ax = _ax - memory16(_ds, _si + 6);         //sub ax, word ptr [si+0x6]
    sub_596f();                                 //call sub_596f
    goto loc_590a;                              //jmp loc_590a
loc_5926:                                       //loc_5926:
    _si += 0x0012;                              //add si, 0x12
    _dx -= 1;                                   //dec dx
    if (_dx != 0)                               //jnz loc_58d0
        goto loc_58d0;
    return;                                     //ret
    _STOP_("db bfh");                           //db bfh
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 56h");                           //db 56h
    _STOP_("db 51h");                           //db 51h
    _STOP_("db b9h");                           //db b9h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db ffh");                           //db ffh
    _STOP_("db 75h");                           //db 75h
    _STOP_("db 03h");                           //db 03h
    _STOP_("db 59h");                           //db 59h
    _STOP_("db f8h");                           //db f8h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 83h");                           //db 83h
    _STOP_("db c7h");                           //db c7h
    _STOP_("db 12h");                           //db 12h
    _STOP_("db e2h");                           //db e2h
    _STOP_("db f2h");                           //db f2h
    _STOP_("db 59h");                           //db 59h
    _STOP_("db f9h");                           //db f9h
    _STOP_("db c3h");                           //db c3h
    _STOP_("sp-trace-fail");                    //sub_58c8 endp_failed
    _STOP_("continues");                        //sub_5945 proc near
}

void sub_5945()
{
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    memory16(_ds, 36531) = 0x0032;              //mov word ptr [0x8eb3], 0x32
    _si = 0x7699;                               //mov si, 0x7699
loc_5953:                                       //loc_5953:
    if (memory16(_ds, _si + 4) == 0xffff)   //jz loc_5965
        goto loc_5965;
    _bx = memory16(_ds, _si + 6);               //mov bx, word ptr [si+0x6]
    _bh &= 0x1f;                                //and bh, 0x1f
    _bx <<= 1;                                  //shl bx, 1
    _indirectCall(memory16(_ds, _bx + 36533));  //call word ptr [bx+0x8eb5]
loc_5965:                                       //loc_5965:
    _si += 0x001a;                              //add si, 0x1a
    memory16(_ds, 36531) -= 1;                  //dec word ptr [0x8eb3]
    if (memory16(_ds, 36531) != 0)              //jnz loc_5953
        goto loc_5953;
}

void sub_596f()
{
    _push(_ax);                                 //push ax
    _al = 0x04;                                 //mov al, 0x4
    sub_11e6();                                 //call sub_11e6
    _ax = _pop();                               //pop ax
    sub_59cc();                                 //call sub_59cc
    sub_59cc();                                 //call sub_59cc
    memory(_ds, 25876) = 0x18;                  //mov byte ptr [0x6514], 0x18
    memory(_ds, 25875) = 0x00;                  //mov byte ptr [0x6513], 0x0
    memory(_ds, 21127) = 0x00;                  //mov byte ptr [0x5287], 0x0
    if ((short)memory16(_ds, 21116) > (short)_ax)//jg loc_5993
        goto loc_5993;
    _bp = -_bp;                                 //neg bp
loc_5993:                                       //loc_5993:
    memory16(_ds, 21122) = _bp;                 //mov word ptr [0x5282], bp
    memory16(_ds, 21130) = 0xff80;              //mov word ptr [0x528a], 0xff80
    sub_4ae9();                                 //call sub_4ae9
    return;                                     //ret
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 32h");                           //db 32h
    _STOP_("db feh");                           //db feh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 19h");                           //db 19h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 19h");                           //db 19h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db 76h");                           //db 76h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 19h");                           //db 19h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 10h");                           //db 10h
    _STOP_("db feh");                           //db feh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 1ah");                           //db 1ah
    _STOP_("db 04h");                           //db 04h
    _STOP_("db c3h");                           //db c3h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 3eh");                           //db 3eh
    _STOP_("db 1bh");                           //db 1bh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db 09h");                           //db 09h
    _STOP_("db 74h");                           //db 74h
    _STOP_("db 04h");                           //db 04h
    _STOP_("db feh");                           //db feh
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 1bh");                           //db 1bh
    _STOP_("db 04h");                           //db 04h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db c3h");                           //db c3h
    _STOP_("sp-trace-fail");                    //sub_596f endp_failed
    _STOP_("continues");                        //sub_59cc proc near
}

void sub_59cc()
{
    memory(_ds, 25862) = 0x32;                  //mov byte ptr [0x6506], 0x32
    if (memory(_ds, 25878) != 0x00)             //jnz loc_59e6
        goto loc_59e6;
    memory(_ds, 1049) -= 1;                     //dec byte ptr [0x419]
    if ((char)memory(_ds, 1049) >= 0)           //jns loc_59e6
        goto loc_59e6;
    memory(_ds, 1049) = 0x00;                   //mov byte ptr [0x419], 0x0
    sub_59e7();                                 //call sub_59e7
loc_59e6:                                       //loc_59e6:
    return;
}

void sub_59e7()
{
    memory(_ds, 25878) = 0x0a;                  //mov byte ptr [0x6516], 0xa
    if (memory(_ds, 1051) == 0x00)              //jz loc_59fd
        goto loc_59fd;
    memory(_ds, 1051) -= 1;                     //dec byte ptr [0x41b]
    memory(_ds, 25862) = 0x00;                  //mov byte ptr [0x6506], 0x0
    return;                                     //ret
loc_59fd:                                       //loc_59fd:
    memory(_ds, 25879) = 0x01;                  //mov byte ptr [0x6517], 0x1
}


// imports
void sub_64ff() { _ASSERT(0); }
void sub_6582() { _ASSERT(0); }
void sub_65be() { _ASSERT(0); }

