void sub_16058();
void sub_160EF();
void sub_1426A();
void sub_141A1();
void sub_14191();
void sub_10D5F();
void sub_21836();
void sub_15863();
void sub_10831();
void sub_10A0D();
void sub_10A51();
void sub_10AFB();
void sub_10D1B();
void sub_10D81();
void sub_10DE7();
void sub_159AA();
void sub_10B3F();
void sub_1595D();
void sub_1F3A7();
void sub_1F38C();
void sub_1F3D7();
void sub_205A9();
void sub_2058D();
void sub_211CC();
void sub_20CBB();
void sub_20CFE();
void sub_1F492();
void sub_10ED9();
void sub_205AE();
void sub_10EF1();
void sub_160A5();
void sub_2098C();
void sub_20A2E();
void sub_20A47();
void sub_20A5C();
void sub_20AC0();
void sub_1F3C7();
void sub_1F371();
void sub_209E9();
void sub_20A1D();
void sub_20A3C();
void sub_20973();


// imports
void loc_23030() { _ASSERT(0); };
void nullsub_2() { _ASSERT(0); };
void sub_2183D() { _ASSERT(0); };
void sub_21870() { _ASSERT(0); };
void sub_22163() { _ASSERT(0); };
void sub_22168() { _ASSERT(0); };
void sub_22495() { _ASSERT(0); };
void sub_224F5() { _ASSERT(0); };
void sub_229C0() { _ASSERT(0); };
void sub_2300D() { _ASSERT(0); };
void sub_23023() { _ASSERT(0); };
void sub_23077() { _ASSERT(0); };
void sub_2412B() { _ASSERT(0); };
void sub_24162() { _ASSERT(0); };
void sub_24488() { _ASSERT(0); };
void sub_244EC() { _ASSERT(0); };
void sub_24AAA() { _ASSERT(0); };




void sub_16058()
{
    memory(_ds, 0x8F53) = 0;                      //mov byte_31483, 0
    memory16(_ds, 0x8F50) = 512;                  //mov word_31480, 200h
loc_16063:                                        //loc_16063:
    memory16(_ds, 0x8F50) >>= 1;                  //shr word_31480, 1
    sub_160EF();                                  //call sub_160EF
    if (!(_bx & _bx))                             //jz short locret_160A4
      goto locret_160A4;
    if (memory16(_ds, 0x8F50) == 0)               //jz short loc_1607F
      goto loc_1607F;
    if (_bl < 0x20)                               //jb short loc_16063
      goto loc_16063;
    if (_bh < 0x20)                               //jb short loc_16063
      goto loc_16063;
loc_1607F:                                        //loc_1607F:
    _bh >>= 1;                                    //shr bh, 1
    _bl >>= 1;                                    //shr bl, 1
    memory16(_ds, 0x8F4E) = _bx;                  //mov word_3147E, bx
    _al = _bh;                                    //mov al, bh
    _bh <<= 1;                                    //shl bh, 1
    _bh += _al;                                   //add bh, al
    _al = _bl;                                    //mov al, bl
    _bl <<= 1;                                    //shl bl, 1
    _bl += _al;                                   //add bl, al
    memory16(_ds, 0x8F4C) = _bx;                  //mov word_3147C, bx
    _ax = memory16(_ds, 0x8F4D);                  //mov ax, word_3147C+1
    _xchg(_ah, _al);                              //xchg ah, al
    memory16(_ds, 0x8F4D) = _ax;                  //mov word_3147C+1, ax
    memory(_ds, 0x8F53) = 0xff;                   //mov byte_31483, 0FFh
locret_160A4:                                     //locret_160A4:
    return;
}

void sub_160EF()  // Joystick
{
    _flags.interrupt = false;                     //cli
    _dx = 0x0201;                                 //mov dx, 201h
    _bp = 0x0100;                                 //mov bp, 100h
    _out(_dx, _al);                               //out dx, al
    _bx = _bx ^ _bx;                              //xor bx, bx
loc_160F9:                                        //loc_160F9:
    _in(_al, _dx);                                //in al, dx
    if (!(_al & 0x01))                            //jz short loc_16100
      goto loc_16100;
    _bh += 1;                                     //inc bh
loc_16100:                                        //loc_16100:
    if (!(_al & 0x02))                            //jz short loc_16106
      goto loc_16106;
    _bl += 1;                                     //inc bl
loc_16106:                                        //loc_16106:
    if (!(_al & 0x03))                            //jz short loc_16114
      goto loc_16114;
    _ax = memory16(_ds, 0x8F50);                  //mov ax, word_31480
loc_1610D:                                        //loc_1610D:
    _ax -= 1;                                     //dec ax
    if ((short)_ax >= 0)                          //jns short loc_1610D
      goto loc_1610D;
    _bp -= 1;                                     //dec bp
    if (_bp != 0)                                 //jnz short loc_160F9
      goto loc_160F9;
    _in(_al, _dx);                                //in al, dx
loc_16114:                                        //loc_16114:
    _flags.interrupt = true;                      //sti
}

void sub_1426A()
{
    _si = 0x9a40;                                 //mov si, 9A40h
    _cx = 0x30;                                   //mov cx, 30h
loc_14270:                                        //loc_14270:
    _ax = 0xc0;                                   //mov ax, 0C0h
    sub_141A1();                                  //call sub_141A1
    memory16(_ds, _si) = _ax;                     //mov [si], ax
    _ax = 0x28;                                   //mov ax, 28h
    if (memory16(_ds, 0x3044) == 0)               //jz short loc_1429D
      goto loc_1429D;
    if (memory16(_ds, 0x3044) == 3)               //jz short loc_1429D
      goto loc_1429D;
    _ax = 0x50;                                   //mov ax, 50h
    if (memory16(_ds, 0x3044) == 2)               //jz short loc_1429D
      goto loc_1429D;
    if (memory16(_ds, 0x3044) == 4)               //jz short loc_1429D
      goto loc_1429D;
    _ax = 0xa0;                                   //mov ax, 0A0h
loc_1429D:                                        //loc_1429D:
    sub_141A1();                                  //call sub_141A1
    memory16(_ds, _si + 2) = _ax;                 //mov [si+2], ax
    memory16(_ds, _si + 4) = 0;                   //mov word ptr [si+4], 0
    _si += 0x0006;                                //add si, 6
    if (--_cx)                                    //loop loc_14270
      goto loc_14270;
}

void sub_141A1()
{
    _push(_dx);                                   //push dx
    _push(_cx);                                   //push cx
    _push(_ax);                                   //push ax
    sub_14191();                                  //call sub_14191
    _dx = _dx ^ _dx;                              //xor dx, dx
    _cx = _pop();                                 //pop cx
    _div(_cx);                                    //div cx
    _ax = _dx;                                    //mov ax, dx
    _cx = _pop();                                 //pop cx
    _dx = _pop();                                 //pop dx
}

void sub_14191()
{
    _push(_dx);                                   //push dx
    _ax = 0x6255;                                 //mov ax, 6255h
    _ax = memory16(_ds, 0x304A) * _al;            //mul word_2B57A
    _ax += 0x3619;                                //add ax, 3619h
    memory16(_ds, 0x304A) = _ax;                  //mov word_2B57A, ax
    _dx = _pop();                                 //pop dx
}

void sub_10D5F()
{
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    switch (_bp)                                  //call cs:off_10D6D[bp]
    {
      case 0: sub_1F3C7(); break;
      case 4: sub_23023(); break;
      case 8: sub_21836(); break;
      case 12: sub_1F3C7(); break;
      case 16: sub_21836(); break;
      default:
        _ASSERT(0);
    }
}

void sub_21836()
{
    WORD _cs = seg001 ;
    memory(_cs, 0x25A5) = 1;                      //mov cs:byte_21835, 1
}

void sub_15863()
{
    _ax = _ax ^ _ax;                              //xor ax, ax
    _ah = 0x02;                                   //mov ah, 2
    _al = 0x00;                                   //mov al, 0
    _interrupt(0x80);                             //int 80h
    memory16(_ds, 0x3754) = 13861;                //mov word_2BC84, 3625h
    memory16(_ds, 0x3752) = 0x78;                 //mov word_2BC82, 78h
    memory16(_ds, 0x3750) = 0;                    //mov word_2BC80, 0
    _di = 0x9a40;                                 //mov di, 9A40h
    _cx = 0x30;                                   //mov cx, 30h
loc_15883:                                        //loc_15883:
    sub_14191();                                  //call sub_14191
    _stosw<MemAuto, DirAuto>();                   //stosw
    sub_14191();                                  //call sub_14191
    _stosw<MemAuto, DirAuto>();                   //stosw
    sub_14191();                                  //call sub_14191
    _ax &= 0x1fff;                                //and ax, 1FFFh
    _stosw<MemAuto, DirAuto>();                   //stosw
    if (--_cx)                                    //loop loc_15883
      goto loc_15883;
    sub_10DE7();                                  //call sub_10DE7
    sub_10D81();                                  //call sub_10D81
    if (memory(_ds, 0x8F5B) != 0)                 //jnz short loc_15916
      goto loc_15916;
loc_158A1:                                        //loc_158A1:
    sub_10A0D();                                  //call sub_10A0D
    sub_10D1B();                                  //call sub_10D1B
    if ((short)memory16(_ds, 0x3750) < (short)0x12)//jl short loc_158D9
      goto loc_158D9;
    memory16(_ds, 0x3752) = 0x78;                 //mov word_2BC82, 78h
    _si = memory16(_ds, 0x3754);                  //mov si, word_2BC84
    sub_10AFB();                                  //call sub_10AFB
    if ((short)memory16(_ds, 0x3750) < (short)0x24)//jl short loc_158D9
      goto loc_158D9;
    if ((short)memory16(_ds, 0x3750) >= (short)0x36)//jge short loc_158D9
      goto loc_158D9;
    memory16(_ds, 0x3752) = 0x96;                 //mov word_2BC82, 96h
    _si = memory16(_ds, 0x3754);                  //mov si, word_2BC84
    _si += 0x14;                                  //add si, 14h
    sub_10AFB();                                  //call sub_10AFB
loc_158D9:                                        //loc_158D9:
    sub_10831();                                  //call sub_10831
    if (memory(_ds, 0x8F5B) != 0)                 //jnz short loc_15916
      goto loc_15916;
    sub_10A51();                                  //call sub_10A51
    memory16(_ds, 0x3750) += 1;                   //inc word_2BC80
    if (memory16(_ds, 0x3750) != 0x48)            //jnz short loc_158A1
      goto loc_158A1;
    memory16(_ds, 0x3750) = 0;                    //mov word_2BC80, 0
    memory16(_ds, 0x3754) += 0x28;                //add word_2BC84, 28h
    if (memory16(_ds, 0x3754) != 14101)           //jnz short loc_158A1
      goto loc_158A1;
    sub_159AA();                                  //call sub_159AA
    if (memory(_ds, 0x8F5B) != 0)                 //jnz short loc_15916
      goto loc_15916;
    memory16(_ds, 0x3754) = 13861;                //mov word_2BC84, 3625h
    goto loc_158A1;                               //jmp short loc_158A1
loc_15916:                                        //loc_15916:
    memory(_ds, 0x8F5B) = 0;                      //mov byte_3148B, 0
    _ah = 0x01;                                   //mov ah, 1
    _interrupt(0x80);                             //int 80h
    sub_10DE7();                                  //call sub_10DE7
    sub_10D81();                                  //call sub_10D81
}

void sub_10831()
{
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    switch (_bp)                                  //call cs:off_1083F[bp]
    {
      case 0: sub_1F492(); break;
      case 4: sub_23077(); break;
      case 8: sub_21870(); break;
      case 12: sub_1F492(); break;
      case 16: sub_21870(); break;
      default:
        _ASSERT(0);
    }
}

void sub_10A0D()
{
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    switch (_bp)                                  //call cs:off_10A1B[bp]
    {
      case 0: sub_205A9(); break;
      case 4: sub_2412B(); break;
      case 8: sub_22163(); break;
      case 12: sub_205A9(); break;
      case 16: sub_22163(); break;
      default:
        _ASSERT(0);
    }
}

void sub_10A51()
{
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    switch (_bp)                                  //call cs:off_10A5F[bp]
    {
      case 0: sub_205AE(); break;
      case 4: sub_24162(); break;
      case 8: sub_22168(); break;
      case 12: sub_205AE(); break;
      case 16: sub_22168(); break;
      default:
        _ASSERT(0);
    }
}

void sub_10AFB()
{
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    switch (_bp)                                  //call cs:off_10B09[bp]
    {
      case 0: sub_2098C(); break;
      case 4: sub_24488(); break;
      case 8: sub_22495(); break;
      case 12: sub_2098C(); break;
      case 16: sub_22495(); break;
      default:
        _ASSERT(0);
    }
}

void sub_10D1B()
{
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    switch (_bp)                                  //call cs:off_10D29[bp]
    {
      case 0: sub_211CC(); break;
      case 4: sub_24AAA(); break;
      case 8: sub_229C0(); break;
      case 12: sub_211CC(); break;
      case 16: sub_229C0(); break;
      default:
        _ASSERT(0);
    }
}

void sub_10D81()
{
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    switch (_bp)                                  //call cs:off_10D8F[bp]
    {
      case 0: sub_1F3D7(); break;
      case 4: loc_23030(); break;
      case 8: sub_2183D(); break;
      case 12: sub_1F3D7(); break;
      case 16: sub_2183D(); break;
      default:
        _ASSERT(0);
    }
}

void sub_10DE7()
{
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    switch (_bp)                                  //call cs:off_10DF5[bp]
    {
      case 0: sub_1F371(); break;
      case 4: sub_2300D(); break;
      case 8: break;
      case 12: sub_1F3A7(); break;
      case 16: break;
      default:
        _ASSERT(0);
    }
}

void sub_159AA()
{
    _ax = 0x0c;                                   //mov ax, 0Ch
    _si = 0x352b;                                 //mov si, 352Bh
    _cx = 0x0001;                                 //mov cx, 1
    sub_1595D();                                  //call sub_1595D
    _cx = 0x55;                                   //mov cx, 55h
loc_159B9:                                        //loc_159B9:
    _push(_cx);                                   //push cx
    sub_10B3F();                                  //call sub_10B3F
    _cx = _pop();                                 //pop cx
    if (memory(_ds, 0x8F5B) != 0)                 //jnz short locret_159C7
      goto locret_159C7;
    if (--_cx)                                    //loop loc_159B9
      goto loc_159B9;
locret_159C7:                                     //locret_159C7:
    return;
}

void sub_10B3F()
{
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    switch (_bp)                                  //call cs:off_10B4D[bp]
    {
      case 0: sub_209E9(); break;
      case 4: sub_244EC(); break;
      case 8: sub_224F5(); break;
      case 12: sub_209E9(); break;
      case 16: sub_224F5(); break;
      default:
        _ASSERT(0);
    }
}

void sub_1595D() // label screen with starfields
{
    memory16(_ds, 0x3752) = _ax;                  //mov word_2BC82, ax
    memory16(_ds, 0x3754) = _si;                  //mov word_2BC84, si
    if (memory(_ds, 0x374E) == 0)                 //jz short loc_1598F
      goto loc_1598F;
    sub_10DE7();                                  //call sub_10DE7
loc_1596E:                                        //loc_1596E:
    sub_10A0D();                                  //call sub_10A0D
    _si = memory16(_ds, 0x3754);                  //mov si, word_2BC84
    sub_10AFB();                                  //call sub_10AFB
    sub_10831();                                  //call sub_10831
    sub_10A51();                                  //call sub_10A51
    sub_10D81();                                  //call sub_10D81
    if (memory(_ds, 0x8F5B) == 0)                 //jz short loc_1596E
      goto loc_1596E;
    memory(_ds, 0x8F5B) = 0;                      //mov byte_3148B, 0
    goto locret_159A9;                            //jmp short locret_159A9
loc_1598F:                                        //loc_1598F:
    _push(_cx);                                   //push cx
    sub_10A0D();                                  //call sub_10A0D
    _si = memory16(_ds, 0x3754);                  //mov si, word_2BC84
    sub_10AFB();                                  //call sub_10AFB
    sub_10831();                                  //call sub_10831
    sub_10A51();                                  //call sub_10A51
    sub_10DE7();                                  //call sub_10DE7
    sub_10D81();                                  //call sub_10D81
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_1598F
      goto loc_1598F;
locret_159A9:                                     //locret_159A9:
    return;
}

void sub_1F3A7()
{
    _dx = 0x427d;                                 //mov dx, 427Dh
    sub_1F38C();                                  //call sub_1F38C
}

void sub_1F38C()
{
    _push(_dx);                                   //push dx
    _ax = 0x1012;                                 //mov ax, 1012h
    _bx = _bx ^ _bx;                              //xor bx, bx
    _cx = 0x10;                                   //mov cx, 10h
    _interrupt(0x10);                             //int 10h
    _dx = _pop();                                 //pop dx
    _ax = 0x1012;                                 //mov ax, 1012h
    _dx += 0x18;                                  //add dx, 18h
    _bx = 0x10;                                   //mov bx, 10h
    _cx = 0x0008;                                 //mov cx, 8
    _interrupt(0x10);                             //int 10h
}

void sub_1F3D7() // set palette
{
    WORD _cs = seg001 ;
    if (memory(_cs, 0x136) == 0)                  //jz short locret_1F3EE
      goto locret_1F3EE;
    memory(_cs, 0x136) = 0;                       //mov cs:byte_1F3C6, 0
    _ax = 0x1000;                                 //mov ax, 1000h
    _bl = 0x12;                                   //mov bl, 12h
    _bh = 0x0f;                                   //mov bh, 0Fh
    _interrupt(0x10);                             //int 10h
locret_1F3EE:                                     //locret_1F3EE:
    return;
}

void sub_205A9()
{
    sub_2058D();                                  //call near ptr sub_2058D
}

void sub_2058D()
{
    _push(_es);                                   //push es
    _ax = 0xa000;                                 //mov ax, 0A000h
    _es = _ax;                                    //mov es, ax
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0f01;                                 //mov ax, 0F01h
    _out(_dx, _ax);                               //out dx, ax
    _di = memory16(_ds, 0x425B);                  //mov di, word_2C78B
    _cx = 0x1f40;                                 //mov cx, 1F40h
    _rep_stosb<MemVideo, DirAuto>();               //rep stosb
    _ax = 0x0001;                                 //mov ax, 1
    _out(_dx, _ax);                               //out dx, ax
    _es = _pop();                                 //pop es
}

void sub_211CC()
{
    _si = 0xaf80;                                 //mov si, 0AF80h
    _di = 0x0786;                                 //mov di, 786h
    _dx = 0x0d;                                   //mov dx, 0Dh
    _cx = 0x36;                                   //mov cx, 36h
    sub_20CBB();                                  //call sub_20CBB
}

void sub_20CBB()
{
    _di = _di + memory16(_ds, 0x425B);            //add di, word_2C78B
    _push(_ds);                                   //push ds
    _ax = 0x3824;                                 //mov ax, 3824h
    _ds = _ax;                                    //mov ds, ax
    _ax = 0xa000;                                 //mov ax, 0A000h
    _es = _ax;                                    //mov es, ax
    _bp = _dx;                                    //mov bp, dx
    _dx = 0x03c4;                                 //mov dx, 3C4h
    _ax = 0x0102;                                 //mov ax, 102h
    _out(_dx, _ax);                               //out dx, ax
    sub_20CFE();                                  //call sub_20CFE
    _si += 0x0002;                                //add si, 2
    _ax = 0x0202;                                 //mov ax, 202h
    _out(_dx, _ax);                               //out dx, ax
    sub_20CFE();                                  //call sub_20CFE
    _si += 0x0002;                                //add si, 2
    _ax = 0x0402;                                 //mov ax, 402h
    _out(_dx, _ax);                               //out dx, ax
    sub_20CFE();                                  //call sub_20CFE
    _si += 0x0002;                                //add si, 2
    _ax = 0x0802;                                 //mov ax, 802h
    _out(_dx, _ax);                               //out dx, ax
    sub_20CFE();                                  //call sub_20CFE
    _ax = 0x0f02;                                 //mov ax, 0F02h
    _out(_dx, _ax);                               //out dx, ax
    _ax = _pop();                                 //pop ax
    _ds = _ax;                                    //mov ds, ax
    _es = _ax;                                    //mov es, ax
}

void sub_20CFE()
{
    _push(_si);                                   //push si
    _push(_di);                                   //push di
    _push(_cx);                                   //push cx
    _push(_bp);                                   //push bp
loc_20D02:                                        //loc_20D02:
    _push(_di);                                   //push di
    _push(_bp);                                   //push bp
loc_20D04:                                        //loc_20D04:
    _movsb<MemVideo, MemAuto, DirAuto>();          //movsb
    _movsb<MemVideo, MemAuto, DirAuto>();          //movsb
    _si += 0x0006;                                //add si, 6
    _bp -= 1;                                     //dec bp
    if (_bp != 0)                                 //jnz short loc_20D04
      goto loc_20D04;
    _bp = _pop();                                 //pop bp
    _di = _pop();                                 //pop di
    _di += 0x28;                                  //add di, 28h
    if (--_cx)                                    //loop loc_20D02
      goto loc_20D02;
    _bp = _pop();                                 //pop bp
    _cx = _pop();                                 //pop cx
    _di = _pop();                                 //pop di
    _si = _pop();                                 //pop si
}

void sub_1F492()  // Starfields
{
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0f01;                                 //mov ax, 0F01h
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0805;                                 //mov ax, 805h
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0xa000;                                 //mov ax, 0A000h
    _es = _ax;                                    //mov es, ax
    _si = 0x9a40;                                 //mov si, 9A40h
    _cx = 0x30;                                   //mov cx, 30h
loc_1F4A8:                                        //loc_1F4A8:
    _ax = memory16(_ds, _si + 4);                 //mov ax, [si+4]
    _ax &= 0x7fff;                                //and ax, 7FFFh
    _ax -= 0x0200;                                //sub ax, 200h
    if ((short)_ax > (short)0x0200)               //jg short loc_1F4D2
      goto loc_1F4D2;
loc_1F4B6:                                        //loc_1F4B6:
    sub_10ED9();                                  //call sub_10ED9
    memory16(_ds, _si) = _ax;                     //mov [si], ax
    sub_10ED9();                                  //call sub_10ED9
    memory16(_ds, _si + 2) = _ax;                 //mov [si+2], ax
    sub_10ED9();                                  //call sub_10ED9
    _ax &= 0x1fff;                                //and ax, 1FFFh
    if ((short)_ax <= (short)0x0200)              //jle short loc_1F4B6
      goto loc_1F4B6;
loc_1F4D2:                                        //loc_1F4D2:
    memory16(_ds, _si + 4) = _ax;                 //mov [si+4], ax
    _ax = memory16(_ds, _si);                     //mov ax, [si]
    _cwd();                                       //cwd
    _flags.carry = !!(_ax & 0x8000);              //shl ax, 1
    _ax <<= 1;
    _rcl(_dx, 1);                                 //rcl dx, 1
    _flags.carry = !!(_ax & 0x8000);              //shl ax, 1
    _ax <<= 1;
    _rcl(_dx, 1);                                 //rcl dx, 1
    _flags.carry = !!(_ax & 0x8000);              //shl ax, 1
    _ax <<= 1;
    _rcl(_dx, 1);                                 //rcl dx, 1
    _flags.carry = !!(_ax & 0x8000);              //shl ax, 1
    _ax <<= 1;
    _rcl(_dx, 1);                                 //rcl dx, 1
    _idiv(memory16(_ds, _si + 4));           //idiv word ptr [si+4]
    _ax += 0xa0;                                  //add ax, 0A0h
    if (_ax >= 0x0140)                            //jnb short loc_1F4B6
      goto loc_1F4B6;
    _bx = _ax;                                    //mov bx, ax
    _ax = memory16(_ds, _si + 2);                 //mov ax, [si+2]
    _cwd();                                       //cwd
    _flags.carry = !!(_ax & 0x8000);              //shl ax, 1
    _ax <<= 1;
    _rcl(_dx, 1);                                 //rcl dx, 1
    _flags.carry = !!(_ax & 0x8000);              //shl ax, 1
    _ax <<= 1;
    _rcl(_dx, 1);                                 //rcl dx, 1
    _flags.carry = !!(_ax & 0x8000);              //shl ax, 1
    _ax <<= 1;
    _rcl(_dx, 1);                                 //rcl dx, 1
    _flags.carry = !!(_ax & 0x8000);              //shl ax, 1
    _ax <<= 1;
    _rcl(_dx, 1);                                 //rcl dx, 1
    _idiv(memory16(_ds, _si + 4));           //idiv word ptr [si+4]
    _ax += 0x64;                                  //add ax, 64h
    if (_ax >= 0xc8)                              //jnb short loc_1F4B6
      goto loc_1F4B6;
    _di = 0x28;                                   //mov di, 28h
    _ax = _di * _al;                              //mul di
    _di = _ax;                                    //mov di, ax
    _di = _di + memory16(_ds, 0x425B);            //add di, word_2C78B
    _push(_cx);                                   //push cx
    _cx = _bx;                                    //mov cx, bx
    _cx &= 0x0007;                                //and cx, 7
    _bx >>= 1;                                    //shr bx, 1
    _bx >>= 1;                                    //shr bx, 1
    _bx >>= 1;                                    //shr bx, 1
    _di += _bx;                                   //add di, bx
    _ah = 0x80;                                   //mov ah, 80h
    _ah >>= _cl;                                  //shr ah, cl
    _cx = _pop();                                 //pop cx
    if (!(memoryVideoGet(_es, _di) & _ah))                //jz short loc_1F555
      goto loc_1F555;
    _al = 0x08;                                   //mov al, 8
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _out(_dx, _ax);                               //out dx, ax
    _bx = memory16(_ds, _si + 4);                 //mov bx, [si+4]
    _xchg(_bh, _bl);                              //xchg bh, bl
    _bx >>= 1;                                    //shr bx, 1
    _bx >>= 1;                                    //shr bx, 1
    _bx &= 0x0007;                                //and bx, 7
    _ah = memory(_ds, _bx + 14141);               //mov ah, [bx+373Dh]
    _al = _al ^ _al;                              //xor al, al
    _out(_dx, _ax);                               //out dx, ax
    memoryVideoSet(_es, _di, _al);                       //mov es:[di], al
    goto loc_1F55A;                               //jmp short loc_1F55A
loc_1F555:                                        //loc_1F555:
    memory16(_ds, _si + 4) |= 32768;              //or word ptr [si+4], 8000h
loc_1F55A:                                        //loc_1F55A:
    _si += 0x0006;                                //add si, 6
    if (--_cx)                                    //loop loc_1F561
      goto loc_1F561;
    goto loc_1F564;                               //jmp short loc_1F564
loc_1F561:                                        //loc_1F561:
    goto loc_1F4A8;                               //jmp loc_1F4A8
loc_1F564:                                        //loc_1F564:
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0000;                                 //mov ax, 0
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0001;                                 //mov ax, 1
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0005;                                 //mov ax, 5
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0xff08;                                 //mov ax, 0FF08h
    _out(_dx, _ax);                               //out dx, ax
    _ax = _ds;                                    //mov ax, ds
    _es = _ax;                                    //mov es, ax
}

void sub_10ED9()
{
    sub_14191();                                  //call sub_14191
}

void sub_205AE() // Swap pages
{
    sub_10EF1();                                  //call sub_10EF1
//loc_205B3:                                        //loc_205B3:
//    if (memory16(_ds, 0x3046) == 0)               //jz short loc_205B3
//      goto loc_205B3;
    memory16(_ds, 0x3046) = 0;                    //mov word_2B576, 0
    _bx = memory16(_ds, 0x425B);                  //mov bx, word_2C78B
    _ax = memory16(_ds, 0x4259);                  //mov ax, word_2C789
    memory16(_ds, 0x425B) = _ax;                  //mov word_2C78B, ax
    memory16(_ds, 0x4259) = _bx;                  //mov word_2C789, bx
    _dx = memory16(_ds, 0x4257);                  //mov dx, word_2C787
    _dl += 0x06;                                  //add dl, 6
loc_205D5:                                        //loc_205D5:
    _in(_al, _dx);                                //in al, dx
    if (_al & 0x08)                               //jnz short loc_205D5
      goto loc_205D5;
    _dl -= 0x06;                                  //sub dl, 6
    _flags.interrupt = false;                     //cli
    _ah = _bh;                                    //mov ah, bh
    _al = 0x0c;                                   //mov al, 0Ch
    _out(_dx, _ax);                               //out dx, ax
    _flags.interrupt = true;                      //sti
    _dl += 0x06;                                  //add dl, 6
loc_205E7:                                        //loc_205E7:
    _in(_al, _dx);                                //in al, dx
    if (!(_al & 0x08))                            //jz short loc_205E7
      goto loc_205E7;
}

void sub_10EF1()
{
    sub_160A5();                                  //call sub_160A5
}

void sub_160A5()
{
    if (memory(_ds, 0x8F53) == 0)                 //jz short locret_160EE
      goto locret_160EE;
    sub_160EF();                                  //call sub_160EF
    _dl = _dl ^ _dl;                              //xor dl, dl
    _al &= 0x30;                                  //and al, 30h
    if (_al == 0x30)                              //jz short loc_160B9
      goto loc_160B9;
    _dl = 0x08;                                   //mov dl, 8
loc_160B9:                                        //loc_160B9:
    _ax = memory16(_ds, 0x8F4C);                  //mov ax, word_3147C
    _ASSERT(0); /* FIXME */ _rcl(_dl, 1);         //rcl dl, 1
    _ASSERT(0); /* FIXME */ _rcl(_dl, 1);         //rcl dl, 1
    _ax = memory16(_ds, 0x8F4E);                  //mov ax, word_3147E
    _ASSERT(0); /* FIXME */ _rcl(_dl, 1);         //rcl dl, 1
    _ASSERT(0); /* FIXME */ _rcl(_dl, 1);         //rcl dl, 1
    if (_dl == memory(_ds, 0x8F5A))               //jz short locret_160EE
      goto locret_160EE;
    if (!(_dl & 0x80))                            //jz short loc_160E6
      goto loc_160E6;
    if (memory(_ds, 0x8F5A) & 0x80)               //jnz short loc_160E6
      goto loc_160E6;
    memory(_ds, 0x8F5B) = 0xff;                   //mov byte_3148B, 0FFh
loc_160E6:                                        //loc_160E6:
    memory(_ds, 0x8F5A) = _dl;                    //mov byte_3148A, dl
    memory(_ds, 0x8F59) = _dl;                    //mov byte_31489, dl
locret_160EE:                                     //locret_160EE:
    return;
}

void sub_2098C()
{
    _ax = 0x28;                                   //mov ax, 28h
    _ax = memory16(_ds, 0x3752) * _al;            //mul word_2BC82
    _di = _ax;                                    //mov di, ax
    _push(memory16(_ds, _si + 20));               //push word ptr [si+14h]
    _push(_si);                                   //push si
    memory(_ds, _si + 20) = 0;                    //mov byte ptr [si+14h], 0
    sub_20A2E();                                  //call near ptr sub_20A2E
    _si = _pop();                                 //pop si
    memory16(_ds, _si + 20) = _pop();             //pop word ptr [si+14h]
}

void sub_20A2E()
{
    _bp = 0x0780;                                 //mov bp, 780h
    _cx = 0x16;                                   //mov cx, 16h
    sub_20A47();                                  //call near ptr sub_20A47
}

void sub_20A47()
{
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    if (!(_al & _al))                             //jz short locret_20A5B
      goto locret_20A5B;
    _xchg(_si, _bp);                              //xchg si, bp
    _push(_si);                                   //push si
    sub_20A5C();                                  //call near ptr sub_20A5C
    _si = _pop();                                 //pop si
    _xchg(_si, _bp);                              //xchg si, bp
    _di += 0x0002;                                //add di, 2
    sub_20A47();                      //jmp short near ptr sub_20A47
locret_20A5B:                                     //locret_20A5B:
    return;
}

void sub_20A5C()
{
    _push(_di);                                   //push di
    _push(_cx);                                   //push cx
    _push(_di);                                   //push di
    memory(_ds, 0x33F2) = _al;                    //mov byte_2B922, al
    _di = 0x33ca;                                 //mov di, 33CAh
    _cx = 0x33f2;                                 //mov cx, 33F2h
    _cx -= 0x33ca;                                //sub cx, 33CAh
    _cx += 1;                                     //inc cx
    _repne_scasb();                               //repne scasb
    _ax = _di;                                    //mov ax, di
    _ax -= 0x33cb;                                //sub ax, 33CBh
    _di = _pop();                                 //pop di
    if (_ax == 0x28)                              //jz short loc_20ABD
      goto loc_20ABD;
    _di = _di + memory16(_ds, 0x425B);            //add di, word_2C78B
    _cx = _pop();                                 //pop cx
    _ax = _cx * _al;                              //mul cx
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _si += _ax;                                   //add si, ax
    _push(_cx);                                   //push cx
    _push(_ds);                                   //push ds
    _ax = 0x3824;                                 //mov ax, 3824h
    _ds = _ax;                                    //mov ds, ax
    _ax = 0xa000;                                 //mov ax, 0A000h
    _es = _ax;                                    //mov es, ax
    _dx = 0x03c4;                                 //mov dx, 3C4h
    _ax = 0x0102;                                 //mov ax, 102h
    _out(_dx, _ax);                               //out dx, ax
    sub_20AC0();                                  //call sub_20AC0
    _ax = 0x0202;                                 //mov ax, 202h
    _out(_dx, _ax);                               //out dx, ax
    sub_20AC0();                                  //call sub_20AC0
    _ax = 0x0402;                                 //mov ax, 402h
    _out(_dx, _ax);                               //out dx, ax
    sub_20AC0();                                  //call sub_20AC0
    _ax = 0x0802;                                 //mov ax, 802h
    _out(_dx, _ax);                               //out dx, ax
    sub_20AC0();                                  //call sub_20AC0
    _ax = 0x0f02;                                 //mov ax, 0F02h
    _out(_dx, _ax);                               //out dx, ax
    _ax = _pop();                                 //pop ax
    _ds = _ax;                                    //mov ds, ax
    _es = _ax;                                    //mov es, ax
loc_20ABD:                                        //loc_20ABD:
    _cx = _pop();                                 //pop cx
    _di = _pop();                                 //pop di
}

void sub_20AC0()
{
    _push(_di);                                   //push di
    _push(_cx);                                   //push cx
loc_20AC2:                                        //loc_20AC2:
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    _stosb<MemVideo, DirAuto>();                   //stosb
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    memoryVideoSet(_es, _di, _al);                       //mov es:[di], al
    _di += 0x27;                                  //add di, 27h
    if (--_cx)                                    //loop loc_20AC2
      goto loc_20AC2;
    _cx = _pop();                                 //pop cx
    _di = _pop();                                 //pop di
}

void sub_1F3C7()
{
    WORD _cs = seg001 ;
    _ax = 0x1000;                                 //mov ax, 1000h
    _bl = 0x12;                                   //mov bl, 12h
    _bh = 0x00;                                   //mov bh, 0
    _interrupt(0x10);                             //int 10h
    memory(_cs, 0x136) = 1;                       //mov cs:byte_1F3C6, 1
}

void sub_1F371()
{
    _ax = 0x1002;                                 //mov ax, 1002h
    _dx = 0x425d;                                 //mov dx, 425Dh
    _interrupt(0x10);                             //int 10h
}

void sub_209E9()
{
    sub_2058D();                                  //call near ptr sub_2058D
    memory16(_ds, 0x3752) = 0x0c;                 //mov word_2BC82, 0Ch
    _si = 0x352b;                                 //mov si, 352Bh
    sub_20973();                                  //call near ptr sub_20973
    _si = 0x358f;                                 //mov si, 358Fh
    _di = 0x05f4;                                 //mov di, 5F4h
    _cx = 0x0a;                                   //mov cx, 0Ah
loc_20A03:                                        //loc_20A03:
    _push(_si);                                   //push si
    _push(_di);                                   //push di
    _push(_cx);                                   //push cx
    sub_20A1D();                                  //call near ptr sub_20A1D
    _cx = _pop();                                 //pop cx
    _di = _pop();                                 //pop di
    _si = _pop();                                 //pop si
    _si += 0x0f;                                  //add si, 0Fh
    _di += 0x0280;                                //add di, 280h
    if (--_cx)                                    //loop loc_20A03
      goto loc_20A03;
    sub_1F492();                                  //call near ptr sub_1F492
    sub_205AE();                      //jmp near ptr sub_205AE
}

void sub_20A1D()
{
    _push(memory16(_ds, _si + 15));               //push word ptr [si+0Fh]
    _push(_si);                                   //push si
    memory(_ds, _si + 15) = 0;                    //mov byte ptr [si+0Fh], 0
    sub_20A3C();                                  //call near ptr sub_20A3C
    _si = _pop();                                 //pop si
    memory16(_ds, _si + 15) = _pop();             //pop word ptr [si+0Fh]
}

void sub_20A3C()
{
    _bp = 0x2300;                                 //mov bp, 2300h
    _cx = 0x0e;                                   //mov cx, 0Eh
    sub_20A47();                                  //call near ptr sub_20A47
}

void sub_20973()
{
    _push(_si);                                   //push si
    _push(_ax);                                   //push ax
    sub_2098C();                                  //call near ptr sub_2098C
    _ax = _pop();                                 //pop ax
    _si = _pop();                                 //pop si
    memory16(_ds, 0x425B) = memory16(_ds, 0x425B) ^ 8192;
    sub_2098C();                                  //call near ptr sub_2098C
    memory16(_ds, 0x425B) = memory16(_ds, 0x425B) ^ 8192;
}

