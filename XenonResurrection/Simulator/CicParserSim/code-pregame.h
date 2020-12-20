void sub_15B21();
void sub_109EB();
void sub_15935();
void sub_15C7C();
void sub_10B83();
void sub_10BC7();
void sub_15950();
void sub_10BE9();
void sub_20B5B();
void sub_20A39();
void sub_10E2B();
void sub_1F3B5();
void sub_20B8A();
void sub_15CC5();
void sub_1F325();
void sub_1F363();
void sub_11827();
void sub_20568();
void sub_11B43();
void sub_11A19();
void sub_11AAF();
void sub_10F5A();
void sub_10F78();
void sub_15926();
void sub_10985();
void sub_20482();
void sub_1080F();
void sub_1F3EF();
void sub_10ED5();
void sub_1421C();
void sub_10A2F();
void sub_10E4D();
void sub_20854();
void sub_20919();
void sub_2095F();
void sub_10BA5();
void sub_136FC();
void sub_1370B();
void sub_20AD0();


// imports
void nullsub_4() {_ASSERT(0);};
void sub_109A7(){_ASSERT(0);};
void sub_10A73(){_ASSERT(0);};
void sub_10DC5(){_ASSERT(0);};
void sub_116A9(){_ASSERT(0);};
void sub_116BA(){_ASSERT(0);};
void sub_15B10(){_ASSERT(0);};
void sub_15E24(){_ASSERT(0);};
void sub_15E52(){_ASSERT(0);};
void sub_15E59(){_ASSERT(0);};
void sub_1F383(){_ASSERT(0);};
void sub_21844(){_ASSERT(0);};
void sub_21FF4(){_ASSERT(0);};
void sub_22152(){_ASSERT(0);};
void sub_22386(){_ASSERT(0);};
void sub_22545(){_ASSERT(0);};
void sub_225AC(){_ASSERT(0);};
void sub_22616(){_ASSERT(0);};
void sub_22634(){_ASSERT(0);};
void sub_2301B(){_ASSERT(0);};
void sub_23046(){_ASSERT(0);};
void sub_23ED2(){_ASSERT(0);};
void sub_2411A(){_ASSERT(0);};
void sub_24348(){_ASSERT(0);};
void sub_24540(){_ASSERT(0);};
void sub_245B4(){_ASSERT(0);};
void sub_24649(){_ASSERT(0);};
void sub_24679(){_ASSERT(0);};

void sub_15B21()
{
    memory16(_ds, 0x91B0) = 3;                    //mov word_316E0, 3
    sub_15935();                                  //call sub_15935
    _ax = 0x0c;                                   //mov ax, 0Ch
    _si = 0x3477;                                 //mov si, 3477h
    _cx = 0x0001;                                 //mov cx, 1
    sub_1595D();                                  //call sub_1595D
    memory(_ds, 0x8F5B) = 0;                      //mov byte_3148B, 0
    _ax = _ax ^ _ax;                              //xor ax, ax
    _push(_ax);                                   //push ax
loc_15B3E:                                        //loc_15B3E:
    sub_109EB();                                  //call sub_109EB
    memory16(_ds, 0x3752) = 0x0c;                 //mov word_2BC82, 0Ch
    _si = 0x3477;                                 //mov si, 3477h
    sub_10AFB();                                  //call sub_10AFB
    memory16(_ds, 0x3752) = 0x3c;                 //mov word_2BC82, 3Ch
    _si = 0x348b;                                 //mov si, 348Bh
    _ax = _pop();                                 //pop ax
    _push(_ax);                                   //push ax
    if (_ax & _ax)                                //jnz short loc_15B5F
      goto loc_15B5F;
    _si = 0x349f;                                 //mov si, 349Fh
loc_15B5F:                                        //loc_15B5F:
    sub_10AFB();                                  //call sub_10AFB
    memory16(_ds, 0x3752) = 0x54;                 //mov word_2BC82, 54h
    _si = 0x34b3;                                 //mov si, 34B3h
    _ax = _pop();                                 //pop ax
    _push(_ax);                                   //push ax
    if (_ax != 0x0001)                            //jnz short loc_15B75
      goto loc_15B75;
    _si = 0x34c7;                                 //mov si, 34C7h
loc_15B75:                                        //loc_15B75:
    sub_10AFB();                                  //call sub_10AFB
    memory16(_ds, 0x3752) = 0x6c;                 //mov word_2BC82, 6Ch
    _si = 0x34db;                                 //mov si, 34DBh
    if (memory(_ds, 0x8F54) != 0)                 //jnz short loc_15B8B
      goto loc_15B8B;
    _si = 0x3503;                                 //mov si, 3503h
loc_15B8B:                                        //loc_15B8B:
    _ax = _pop();                                 //pop ax
    _push(_ax);                                   //push ax
    if (_ax != 0x0002)                            //jnz short loc_15B95
      goto loc_15B95;
    _si += 0x14;                                  //add si, 14h
loc_15B95:                                        //loc_15B95:
    sub_10AFB();                                  //call sub_10AFB
    sub_15C7C();                                  //call sub_15C7C
    sub_10831();                                  //call sub_10831
    sub_10A51();                                  //call sub_10A51
    if (!(memory(_ds, 0x8F59) & 1))               //jz short loc_15BC0
      goto loc_15BC0;
    memory(_ds, 0x8F59) = 0;                      //mov byte_31489, 0
    memory16(_ds, 0x8E88) = 8;                    //mov word_313B8, 8
    _ax = _pop();                                 //pop ax
    _ax -= 1;                                     //dec ax
    _push(_ax);                                   //push ax
    if ((short)_ax >= 0)                          //jns short loc_15B3E
      goto loc_15B3E;
    _ax = _pop();                                 //pop ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    goto loc_15B3E;                               //jmp loc_15B3E
loc_15BC0:                                        //loc_15BC0:
    if (!(memory(_ds, 0x8F59) & 2))               //jz short loc_15BE4
      goto loc_15BE4;
    memory(_ds, 0x8F59) = 0;                      //mov byte_31489, 0
    memory16(_ds, 0x8E88) = 8;                    //mov word_313B8, 8
    _ax = _pop();                                 //pop ax
    _ax += 1;                                     //inc ax
    _push(_ax);                                   //push ax
    if ((short)_ax >= (short)0x0003)              //jge short loc_15BDD
      goto loc_15BDD;
    goto loc_15B3E;                               //jmp loc_15B3E
loc_15BDD:                                        //loc_15BDD:
    _ax = _pop();                                 //pop ax
    _ax = _ax ^ _ax;                              //xor ax, ax
    _push(_ax);                                   //push ax
    goto loc_15B3E;                               //jmp loc_15B3E
loc_15BE4:                                        //loc_15BE4:
    if (memory(_ds, 0x8F5B) != 0)                 //jnz short loc_15BEE
      goto loc_15BEE;
    goto loc_15B3E;                               //jmp loc_15B3E
loc_15BEE:                                        //loc_15BEE:
    memory(_ds, 0x8F5B) = 0;                      //mov byte_3148B, 0
    memory16(_ds, 0x8E88) = 9;                    //mov word_313B8, 9
    _ax = _pop();                                 //pop ax
    _push(_ax);                                   //push ax
    if (_ax != 0x0002)                            //jnz short loc_15C07
      goto loc_15C07;
    memory(_ds, 0x8F54) = (~memory(_ds, 0x8F54)); //not byte_31484
    goto loc_15B3E;                               //jmp loc_15B3E
loc_15C07:                                        //loc_15C07:
    _ax = _pop();                                 //pop ax
    _ax += 1;                                     //inc ax
    memory16(_ds, 0x8E70) = _ax;                  //mov word_313A0, ax
    sub_15950();                               //jmp sub_15950
}

void sub_109EB()
{
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    switch (_bp)                                  //call cs:off_109F9[bp]
    {
      case 0: sub_2058D(); break;
      case 4: sub_2411A(); break;
      case 8: sub_22152(); break;
      case 12: sub_2058D(); break;
      case 16: sub_22152(); break;
      default:
        _ASSERT(0);
    }
}

void sub_15935()
{
    sub_10BC7();                                  //call sub_10BC7
    _cx = 0x30;                                   //mov cx, 30h
    _di = 0x9a40;                                 //mov di, 9A40h
loc_1593E:                                        //loc_1593E:
    sub_14191();                                  //call sub_14191
    _stosw<MemAuto, DirAuto>();                   //stosw
    sub_14191();                                  //call sub_14191
    _stosw<MemAuto, DirAuto>();                   //stosw
    sub_14191();                                  //call sub_14191
    _ax &= 0x1fff;                                //and ax, 1FFFh
    _stosw<MemAuto, DirAuto>();                   //stosw
    if (--_cx)                                    //loop loc_1593E
      goto loc_1593E;
}

void sub_15C7C()
{
    _ax = memory16(_ds, 0x91B0);                  //mov ax, word_316E0
    _al += 0x30;                                  //add al, 30h
    memory(_ds, 0x33FB) = _al;                    //mov byte_2B92B, al
    _si = 0x33f3;                                 //mov si, 33F3h
    sub_10B83();                                  //call sub_10B83
}

void sub_10B83()
{
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    switch (_bp)                                  //call cs:off_10B91[bp]
    {
      case 0: sub_20A39(); break;
      case 4: sub_24540(); break;
      case 8: sub_22545(); break;
      case 12: sub_20A39(); break;
      case 16: sub_22545(); break;
      default:
        _ASSERT(0);
    }
}

void sub_10BC7()
{
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    switch (_bp)                                  //call cs:off_10BD5[bp]
    {
      case 0: sub_20B5B(); break;
      case 4: sub_24649(); break;
      case 8: sub_22616(); break;
      case 12: sub_20B5B(); break;
      case 16: sub_22616(); break;
      default:
        _ASSERT(0);
    }
}

void sub_15950()
{
    sub_10E2B();                                  //call sub_10E2B
    sub_10D81();                                  //call sub_10D81
    sub_10BE9();                                  //call sub_10BE9
    sub_1426A();                                  //call sub_1426A
}

void sub_10BE9()
{
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    switch (_bp)                                  //call cs:off_10BF7[bp]
    {
      case 0: sub_20B8A(); break;
      case 4: sub_24679(); break;
      case 8: sub_22634(); break;
      case 12: sub_20B8A(); break;
      case 16: sub_22634(); break;
      default:
        _ASSERT(0);
    }
}

void sub_20B5B()
{
    if (memory16(_ds, 0x33BC) != 0)               //jnz short loc_20B85
      goto loc_20B85;
    _push(_ds);                                   //push ds
    _ax = 0xa000;                                 //mov ax, 0A000h
    _ds = _ax;                                    //mov ds, ax
    _es = _ax;                                    //mov es, ax
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0105;                                 //mov ax, 105h
    _out(_dx, _ax);                               //out dx, ax
    _si = 0x1e00;                                 //mov si, 1E00h
    _di = 0xfec0;                                 //mov di, 0FEC0h
    _cx = 0x0140;                                 //mov cx, 140h
    _rep_movsb<MemVideo, MemVideo, DirAuto>();      //rep movsb
    _ax = 0x0005;                                 //mov ax, 5
    _out(_dx, _ax);                               //out dx, ax
    _ax = _pop();                                 //pop ax
    _ds = _ax;                                    //mov ds, ax
    _es = _ax;                                    //mov es, ax
loc_20B85:                                        //loc_20B85:
    memory(_ds, 0x33BC) += 1;                     //inc byte ptr word_2B8EC
}

void sub_20A39()
{
    _di = 0x1cd6;                                 //mov di, 1CD6h
}

void sub_10E2B()
{
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    switch (_bp)                                  //call cs:off_10E39[bp]
    {
      case 0: sub_1F383(); break;
      case 4: sub_2301B(); break;
      case 8: break;
      case 12: sub_1F3B5(); break;
      case 16: break;
      default:
        _ASSERT(0);
    }
}

void sub_1F3B5()
{
    _ax = 0x30;                                   //mov ax, 30h
    _ax = memory16(_ds, 0x991C) * _al;            //mul word_31E4C
    _dx = _ax;                                    //mov dx, ax
    _dx += 0x427d;                                //add dx, 427Dh
    sub_1F38C();                                  //call sub_1F38C
}

void sub_20B8A()
{
    memory(_ds, 0x33BC) -= 1;                     //dec byte ptr word_2B8EC
    if (memory(_ds, 0x33BC) != 0)                 //jnz short locret_20BBE
      goto locret_20BBE;
    _push(_ds);                                   //push ds
    _ax = 0xa000;                                 //mov ax, 0A000h
    _ds = _ax;                                    //mov ds, ax
    _es = _ax;                                    //mov es, ax
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0105;                                 //mov ax, 105h
    _out(_dx, _ax);                               //out dx, ax
    _di = 0x1e00;                                 //mov di, 1E00h
    _si = 0xfec0;                                 //mov si, 0FEC0h
    _cx = 0x0140;                                 //mov cx, 140h
    _rep_movsb<MemVideo, MemVideo, DirAuto>();      //rep movsb
    _di = 0x3e00;                                 //mov di, 3E00h
    _si = 0xfec0;                                 //mov si, 0FEC0h
    _cx = 0x0140;                                 //mov cx, 140h
    _rep_movsb<MemVideo, MemVideo, DirAuto>();      //rep movsb
    _ax = 0x0005;                                 //mov ax, 5
    _out(_dx, _ax);                               //out dx, ax
    _ax = _pop();                                 //pop ax
    _ds = _ax;                                    //mov ds, ax
    _es = _ax;                                    //mov es, ax
locret_20BBE:                                     //locret_20BBE:
    return;
}

void sub_15CC5()
{
    _ax = memory16(_ds, 0x991C);                  //mov ax, word_31E4C
    if (_ax != memory16(_ds, 0x8E6C))             //jnz short loc_15CD1
      goto loc_15CD1;
    goto locret_15E03;                            //jmp locret_15E03
loc_15CD1:                                        //loc_15CD1:
    memory16(_ds, 0x8E6C) = _ax;                  //mov word_3139C, ax
    sub_15B10();                                  //call sub_15B10
    _ax = memory16(_ds, 0x991C);                  //mov ax, word_31E4C
    _al += 0x30;                                  //add al, 30h
    memory(_ds, 0x41EF) = _al;                    //mov byte_2C71F, al
    memory(_ds, 0x41FA) = _al;                    //mov byte_2C72A, al
    memory(_ds, 0x4206) = _al;                    //mov byte_2C736, al
    memory(_ds, 0x4215) = _al;                    //mov byte_2C745, al
    memory(_ds, 0x4222) = _al;                    //mov byte_2C752, al
    memory(_ds, 0x4231) = _al;                    //mov byte_2C761, al
    _dx = 0x41ee;                                 //mov dx, 41EEh
    sub_15E24();                                  //call sub_15E24
    memory16(_ds, 0x8E60) = _ax;                  //mov word_31390, ax
    _bx = _ax;                                    //mov bx, ax
    _cx = 0x2ee0;                                 //mov cx, 2EE0h
    _dx = 0xdf16;                                 //mov dx, 0DF16h
    sub_15E52();                                  //call sub_15E52
    _bx = memory16(_ds, 0x8E60);                  //mov bx, word_31390
    sub_15E59();                                  //call sub_15E59
    _di = _di ^ _di;                              //xor di, di
    _si = 0xdf16;                                 //mov si, 0DF16h
    _ch = _ch ^ _ch;                              //xor ch, ch
loc_15D10:                                        //loc_15D10:
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    _cl = _al;                                    //mov cl, al
    _rep_movsw<MemAuto, MemAuto, DirAuto>();      //rep movsw
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    _cl = _al;                                    //mov cl, al
    _ax = _ax ^ _ax;                              //xor ax, ax
    _rep_stosw<MemAuto, DirAuto>();               //rep stosw
    if ((short)_di >= (short)0x2ee0)              //jge short loc_15D28
      goto loc_15D28;
    if ((short)_di < (short)0x2ee0)               //jl short loc_15D10
      goto loc_15D10;
loc_15D28:                                        //loc_15D28:
    _dx = 0x4214;                                 //mov dx, 4214h
    sub_15E24();                                  //call sub_15E24
    memory16(_ds, 0x8E60) = _ax;                  //mov word_31390, ax
    _bx = _ax;                                    //mov bx, ax
    _cx = 0x082a;                                 //mov cx, 82Ah
    _dx = 0xd274;                                 //mov dx, 0D274h
    sub_15E52();                                  //call sub_15E52
    _bx = memory16(_ds, 0x8E60);                  //mov bx, word_31390
    sub_15E59();                                  //call sub_15E59
    _dx = 0x4221;                                 //mov dx, 4221h
    sub_15E24();                                  //call sub_15E24
    memory16(_ds, 0x8E60) = _ax;                  //mov word_31390, ax
    _bx = _ax;                                    //mov bx, ax
    _cx = 0x0392;                                 //mov cx, 392h
    _dx = 0xda9e;                                 //mov dx, 0DA9Eh
    sub_15E52();                                  //call sub_15E52
    _bx = memory16(_ds, 0x8E60);                  //mov bx, word_31390
    sub_15E59();                                  //call sub_15E59
    _dx = 0x4230;                                 //mov dx, 4230h
    sub_15E24();                                  //call sub_15E24
    memory16(_ds, 0x8E60) = _ax;                  //mov word_31390, ax
    _bx = _ax;                                    //mov bx, ax
    _cx = 0x1e96;                                 //mov cx, 1E96h
    _dx = 0xde30;                                 //mov dx, 0DE30h
    sub_15E52();                                  //call sub_15E52
    _bx = memory16(_ds, 0x8E60);                  //mov bx, word_31390
    sub_15E59();                                  //call sub_15E59
    _si = 0xde30;                                 //mov si, 0DE30h
    _cx = 0x73;                                   //mov cx, 73h
    _ax = 0xdf16;                                 //mov ax, 0DF16h
loc_15D82:                                        //loc_15D82:
    memory16(_ds, _si) += _ax;                    //add [si], ax
    _si += 0x0002;                                //add si, 2
    if (--_cx)                                    //loop loc_15D82
      goto loc_15D82;
    _dx = 0x41f9;                                 //mov dx, 41F9h
    sub_15E24();                                  //call sub_15E24
    memory16(_ds, 0x8E60) = _ax;                  //mov word_31390, ax
    _bx = _ax;                                    //mov bx, ax
    _cx = 0xe480;                                 //mov cx, 0E480h
    _dx = _dx ^ _dx;                              //xor dx, dx
    _ax = 0x63d0;                                 //mov ax, 63D0h
    _push(_ds);                                   //push ds
    _ds = _ax;                                    //mov ds, ax
    sub_15E52();                                  //call sub_15E52
    _ds = _pop();                                 //pop ds
    _bx = memory16(_ds, 0x8E60);                  //mov bx, word_31390
    sub_15E59();                                  //call sub_15E59
    _push(_es);                                   //push es
    _ax = 0x5489;                                 //mov ax, 5489h
    _es = _ax;                                    //mov es, ax
    _ax = _ax ^ _ax;                              //xor ax, ax
    _di = _di ^ _di;                              //xor di, di
    _cx = 0x7a34;                                 //mov cx, 7A34h
    _rep_stosw<MemAuto, DirAuto>();               //rep stosw
    _es = _pop();                                 //pop es
    _dx = 0x4205;                                 //mov dx, 4205h
    sub_15E24();                                  //call sub_15E24
    memory16(_ds, 0x8E60) = _ax;                  //mov word_31390, ax
    _bx = _ax;                                    //mov bx, ax
    _cx = 0xf468;                                 //mov cx, 0F468h
    _dx = 0x0000;                                 //mov dx, 0
    _ax = 0x5489;                                 //mov ax, 5489h
    _push(_ds);                                   //push ds
    _ds = _ax;                                    //mov ds, ax
    sub_15E52();                                  //call sub_15E52
    _ds = _pop();                                 //pop ds
    _bx = memory16(_ds, 0x8E60);                  //mov bx, word_31390
    sub_15E59();                                  //call sub_15E59
    _push(_ds);                                   //push ds
    _ax = 0x63d0;                                 //mov ax, 63D0h
    _ds = _ax;                                    //mov ds, ax
    _si = _si ^ _si;                              //xor si, si
    _di = 0x5538;                                 //mov di, 5538h
    _cx = 0x1c90;                                 //mov cx, 1C90h
loc_15DEA:                                        //loc_15DEA:
    _lodsw<MemAuto, DirAuto>();                   //lodsw
    _dx = _ax;                                    //mov dx, ax
    _lodsw<MemAuto, DirAuto>();                   //lodsw
    _dx |= _ax;                                   //or dx, ax
    _lodsw<MemAuto, DirAuto>();                   //lodsw
    _dx |= _ax;                                   //or dx, ax
    _lodsw<MemAuto, DirAuto>();                   //lodsw
    _ax |= _dx;                                   //or ax, dx
    _stosw<MemAuto, DirAuto>();                   //stosw
    if (--_cx)                                    //loop loc_15DEA
      goto loc_15DEA;
    _ds = _pop();                                 //pop ds
    sub_10DC5();                                  //call sub_10DC5
    sub_15950();                                  //call sub_15950
    sub_10D5F();                                  //call sub_10D5F
locret_15E03:                                     //locret_15E03:
    return;
}

void sub_1F325()
{
    _push(_ds);                                   //push ds
    _ax = 0x63d0;                                 //mov ax, 63D0h
    _ds = _ax;                                    //mov ds, ax
    _ax = 0xa000;                                 //mov ax, 0A000h
    _es = _ax;                                    //mov es, ax
    _di = 0x4000;                                 //mov di, 4000h
    _dx = 0x03c4;                                 //mov dx, 3C4h
    _ax = 0x0102;                                 //mov ax, 102h
    _si = _si ^ _si;                              //xor si, si
    sub_1F363();                                  //call sub_1F363
    _ah = 0x02;                                   //mov ah, 2
    _si = 0x0002;                                 //mov si, 2
    sub_1F363();                                  //call sub_1F363
    _ah = 0x04;                                   //mov ah, 4
    _si = 0x0004;                                 //mov si, 4
    sub_1F363();                                  //call sub_1F363
    _ah = 0x08;                                   //mov ah, 8
    _si = 0x0006;                                 //mov si, 6
    sub_1F363();                                  //call sub_1F363
    _dx = 0x03c4;                                 //mov dx, 3C4h
    _ax = 0x0f02;                                 //mov ax, 0F02h
    _out(_dx, _ax);                               //out dx, ax
    _ax = _pop();                                 //pop ax
    _ds = _ax;                                    //mov ds, ax
    _es = _ax;                                    //mov es, ax
}

void sub_1F363()
{
    _out(_dx, _ax);                               //out dx, ax
    _push(_di);                                   //push di
    _cx = 0x1c90;                                 //mov cx, 1C90h
loc_1F368:                                        //loc_1F368:
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _si += 0x0006;                                //add si, 6
    if (--_cx)                                    //loop loc_1F368
      goto loc_1F368;
    _di = _pop();                                 //pop di
}

void sub_11827()
{
    memory(_ds, 0x8F5C) = 0;                      //mov byte_3148C, 0
    memory(_ds, 0x8F5D) = 0xff;                   //mov byte_3148D, 0FFh
    memory16(_ds, 0x991E) = 8;                    //mov word_31E4E, 8
    memory16(_ds, 0x991A) = 1;                    //mov word_31E4A, 1
    memory16(_ds, 0x8E7A) = 0;                    //mov word_313AA, 0
    memory(_ds, 0x8F5E) = 0;                      //mov byte_3148E, 0
    if (memory16(_ds, 0x8E70) != 2)               //jnz short loc_11854
      goto loc_11854;
    memory(_ds, 0x8F5E) = 0xff;                   //mov byte_3148E, 0FFh
loc_11854:                                        //loc_11854:
    memory(_ds, 0x8F5F) = 0;                      //mov byte_3148F, 0
    memory(_ds, 0x8F60) = 0;                      //mov byte_31490, 0
    sub_109A7();                                  //call sub_109A7
    sub_10A73();                                  //call sub_10A73
    memory(_ds, 0x8F61) = 0;                      //mov byte_31491, 0
    _si = 0x9f4c;                                 //mov si, 9F4Ch
    _cx = 0x9e;                                   //mov cx, 9Eh
    memory16(_ds, 0x8E7C) = _si;                  //mov word_313AC, si
loc_11873:                                        //loc_11873:
    memory16(_ds, _si) = 0;                       //mov word ptr [si], 0
    _lea(_di, memory16(_ds, _si + 76));           //lea di, [si+4Ch]
    memory16(_ds, _si + 8) = _di;                 //mov [si+8], di
    _si = _di;                                    //mov si, di
    if (--_cx)                                    //loop loc_11873
      goto loc_11873;
    memory16(_ds, _si) = 0;                       //mov word ptr [si], 0
    memory16(_ds, _si + 8) = 0;                   //mov word ptr [si+8], 0
    _di = 0x9c80;                                 //mov di, 9C80h
    _ax = 0xffff;                                 //mov ax, 0FFFFh
    _cx = 0x0140;                                 //mov cx, 140h
    _rep_stosw<MemAuto, DirAuto>();               //rep stosw
    sub_116A9();                                  //call sub_116A9
    sub_116BA();                                  //call sub_116BA
    if (memory(_ds, 0x8F5E) == 0)                 //jz short loc_118AD
      goto loc_118AD;
    sub_11A19();                                  //call sub_11A19
    sub_116BA();                                  //call sub_116BA
    sub_11A19();                                  //call sub_11A19
    goto locret_118BC;                            //jmp short locret_118BC
loc_118AD:                                        //loc_118AD:
    sub_11A19();                                  //call sub_11A19
    memory16(_ds, 0x918A) = 0;                    //mov word_316BA, 0
    sub_10E91();                                  //call sub_10E91
    sub_11A19();                                  //call sub_11A19
locret_118BC:                                     //locret_118BC:
    return;
}

void sub_20568()
{
    sub_2058D();                                  //call near ptr sub_2058D
    _ax = memory16(_ds, 0x425B);                  //mov ax, word_2C78B
    _bx = memory16(_ds, 0x4259);                  //mov bx, word_2C789
    memory16(_ds, 0x425B) = _bx;                  //mov word_2C78B, bx
    memory16(_ds, 0x4259) = _ax;                  //mov word_2C789, ax
    sub_2058D();                                  //call near ptr sub_2058D
    _ax = memory16(_ds, 0x425B);                  //mov ax, word_2C78B
    _bx = memory16(_ds, 0x4259);                  //mov bx, word_2C789
    memory16(_ds, 0x425B) = _bx;                  //mov word_2C78B, bx
    memory16(_ds, 0x4259) = _ax;                  //mov word_2C789, ax
}

void sub_11B43()
{
    _si = 0x0000;                                 //mov si, 0
    _di = 0x0000;                                 //mov di, 0
    _cx = 0x1770;                                 //mov cx, 1770h
    _ax = 0x2565;                                 //mov ax, 2565h
    _es = _ax;                                    //mov es, ax
    _rep_movsw<MemAuto, MemAuto, DirAuto>();      //rep movsw
    _ax = _ds;                                    //mov ax, ds
    _es = _ax;                                    //mov es, ax
    memory16(_ds, 0x8F32) = 0;                    //mov word_31462, 0
    memory16(_ds, 0x8E86) = 0;                    //mov word_313B6, 0
    _di = 0x8e8c;                                 //mov di, 8E8Ch
    _cx = 0x10;                                   //mov cx, 10h
    _ax = _ax ^ _ax;                              //xor ax, ax
    _rep_stosw<MemAuto, DirAuto>();               //rep stosw
    memory(_ds, 0x8FB0) = 0;                      //mov byte_314E0, 0
    memory(_ds, 0x8F59) = 0;                      //mov byte_31489, 0
    memory(_ds, 0x8F5B) = 0;                      //mov byte_3148B, 0
    sub_11AAF();                                  //call sub_11AAF
    if (memory16(_ds, 0x8E70) != 2)               //jnz short locret_11B8F
      goto locret_11B8F;
    sub_11A19();                                  //call sub_11A19
    sub_11AAF();                                  //call sub_11AAF
    sub_11A19();                                  //call sub_11A19
locret_11B8F:                                     //locret_11B8F:
    return;
}

void sub_11A19()
{
    _si = 0xce80;                                 //mov si, 0CE80h
    _di = 0x8fb2;                                 //mov di, 8FB2h
    _cx = 0x0146;                                 //mov cx, 146h
loc_11A22:                                        //loc_11A22:
    _lodsw<MemAuto, DirAuto>();                   //lodsw
    _bx = memory16(_ds, _di);                     //mov bx, [di]
    memory16(_ds, _si - 2) = _bx;                 //mov [si-2], bx
    _stosw<MemAuto, DirAuto>();                   //stosw
    if (--_cx)                                    //loop loc_11A22
      goto loc_11A22;
    _si = 0x9f00;                                 //mov si, 9F00h
    _di = 0x8f62;                                 //mov di, 8F62h
    _cx = 0x4c;                                   //mov cx, 4Ch
loc_11A34:                                        //loc_11A34:
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    _ah = memory(_ds, _di);                       //mov ah, [di]
    memory(_ds, _si - 1) = _ah;                   //mov [si-1], ah
    _stosb<MemAuto, DirAuto>();                   //stosb
    if (--_cx)                                    //loop loc_11A34
      goto loc_11A34;
    _si = 0x0000;                                 //mov si, 0
    _di = 0x0000;                                 //mov di, 0
    _cx = 0x1770;                                 //mov cx, 1770h
    _ax = 0x2565;                                 //mov ax, 2565h
    _es = _ax;                                    //mov es, ax
loc_11A4B:                                        //loc_11A4B:
    _lodsw<MemAuto, DirAuto>();                   //lodsw
    _bx = memory16(_es, _di);                     //mov bx, es:[di]
    memory16(_ds, _si - 2) = _bx;                 //mov [si-2], bx
    _stosw<MemAuto, DirAuto>();                   //stosw
    if (--_cx)                                    //loop loc_11A4B
      goto loc_11A4B;
    _ax = _ds;                                    //mov ax, ds
    _es = _ax;                                    //mov es, ax
    memory16(_ds, 0x8E7A) = memory16(_ds, 0x8E7A) ^ 1;
    sub_10F5A();                                  //call sub_10F5A
}

void sub_11AAF()
{
    memory16(_ds, 0x918E) = 11520;                //mov word_316BE, 2D00h
    memory16(_ds, 0x9196) = 0;                    //mov word_316C6, 0
    memory16(_ds, 0x9190) = 4608;                 //mov word_316C0, 1200h
    memory16(_ds, 0x9192) = 32750;                //mov word_316C2, 7FEEh
    memory16(_ds, 0x9194) = 32750;                //mov word_316C4, 7FEEh
    memory16(_ds, 0x91AE) = 0x10;                 //mov word_316DE, 10h
    _ax = memory16(_ds, 0x9F12);                  //mov ax, word_32442
    memory16(_ds, 0x91A2) = _ax;                  //mov word_316D2, ax
    _ax = memory16(_ds, 0x9F16);                  //mov ax, word_32446
    memory16(_ds, 0x91A4) = _ax;                  //mov word_316D4, ax
    _ax = memory16(_ds, 0x9190);                  //mov ax, word_316C0
    memory16(_ds, 0x91A6) = _ax;                  //mov word_316D6, ax
    _ax = memory16(_ds, 0x915A);                  //mov ax, word_3168A
    memory16(_ds, 0x9166) = _ax;                  //mov word_31696, ax
    _ax = memory16(_ds, 0x915C);                  //mov ax, word_3168C
    memory16(_ds, 0x9168) = _ax;                  //mov word_31698, ax
    memory16(_ds, 0x9198) = 1;                    //mov word_316C8, 1
    memory16(_ds, 0x919A) = 0;                    //mov word_316CA, 0
    memory16(_ds, 0x919E) = 0;                    //mov word_316CE, 0
    sub_10F78();                                  //call sub_10F78
    memory16(_ds, 0x91A0) = 0;                    //mov word_316D0, 0
    memory16(_ds, 0x8E7E) = 0;                    //mov word_313AE, 0
    memory16(_ds, 0x919C) = 0;                    //mov word_316CC, 0
    memory16(_ds, 0x915A) = 0;                    //mov word_3168A, 0
    memory16(_ds, 0x915C) = 0;                    //mov word_3168C, 0
    memory16(_ds, 0x9166) = 0;                    //mov word_31696, 0
    memory16(_ds, 0x9168) = 0;                    //mov word_31698, 0
    memory16(_ds, 0x9164) = 0;                    //mov word_31694, 0
    memory16(_ds, 0x91AC) = 1;                    //mov word_316DC, 1
    memory16(_ds, 0x91B2) = 0;                    //mov word_316E2, 0
}

void sub_10F5A()
{
    memory16(_ds, 0x8E74) = _bx;                  //mov word_313A4, bx
    _bx = memory16(_ds, 0x991C);                  //mov bx, word_31E4C
    _bx <<= 1;                                    //shl bx, 1
    _push(memory16(_cs, _bx + 3948));             //push word ptr cs:[bx+0F6Ch]
    _bx = memory16(_ds, 0x8E74);                  //mov bx, word_313A4
}

void sub_10F78()
{
    memory16(_ds, 0x8E74) = _bx;                  //mov word_313A4, bx
    _bx = memory16(_ds, 0x991C);                  //mov bx, word_31E4C
    _bx <<= 1;                                    //shl bx, 1
    _push(memory16(_cs, _bx + 3978));             //push word ptr cs:[bx+0F8Ah]
    _bx = memory16(_ds, 0x8E74);                  //mov bx, word_313A4
}

void sub_15926()
{
    _push(_si);                                   //push si
    _push(_cx);                                   //push cx
    sub_15935();                                  //call sub_15935
    _cx = _pop();                                 //pop cx
    _si = _pop();                                 //pop si
    _ax = 0x64;                                   //mov ax, 64h
    sub_1595D();                                  //call sub_1595D
    sub_15950();                               //jmp short sub_15950
}

void sub_10985()
{
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    switch (_bp)                                  //call cs:off_10993[bp]
    {
      case 0: sub_20482(); break;
      case 4: sub_23ED2(); break;
      case 8: sub_21FF4(); break;
      case 12: sub_20482(); break;
      case 16: sub_21FF4(); break;
      default:
        _ASSERT(0);
    }
}

void sub_20482()
{
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0105;                                 //mov ax, 105h
    _out(_dx, _ax);                               //out dx, ax
    _di = memory16(_ds, 0x425B);                  //mov di, word_2C78B
    _si = 0x0000;                                 //mov si, 0
    _si = _si + memory16(_ds, 0x918E);            //add si, word_316BE
    _dx = memory16(_ds, 0x9196);                  //mov dx, word_316C6
    _ax = 0xa000;                                 //mov ax, 0A000h
    _es = _ax;                                    //mov es, ax
    _cx = 0x10;                                   //mov cx, 10h
    _cx -= _dx;                                   //sub cx, dx
    _bl = 0x14;                                   //mov bl, 14h
loc_204A4:                                        //loc_204A4:
    _lodsw<MemAuto, DirAuto>();                   //lodsw
    _push(_si);                                   //push si
    _ax >>= 1;                                    //shr ax, 1
    _si = _ax;                                    //mov si, ax
    _si += _dx;                                   //add si, dx
    _si += _dx;                                   //add si, dx
    _push(_ds);                                   //push ds
    _ax = 0xa400;                                 //mov ax, 0A400h
    _ds = _ax;                                    //mov ds, ax
    _push(_di);                                   //push di
    _push(_cx);                                   //push cx
loc_204B6:                                        //loc_204B6:
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _di += 0x26;                                  //add di, 26h
    if (--_cx)                                    //loop loc_204B6
      goto loc_204B6;
    _bp = _di;                                    //mov bp, di
    _cx = _pop();                                 //pop cx
    _di = _pop();                                 //pop di
    _di += 0x0002;                                //add di, 2
    _ds = _pop();                                 //pop ds
    _si = _pop();                                 //pop si
    _bl -= 1;                                     //dec bl
    if (_bl != 0)                                 //jnz short loc_204A4
      goto loc_204A4;
    _di = _bp;                                    //mov di, bp
    _di -= 0x26;                                  //sub di, 26h
    _bx = 0x0b14;                                 //mov bx, 0B14h
    _bp = 0x26;                                   //mov bp, 26h
loc_204D5:                                        //loc_204D5:
    _lodsw<MemAuto, DirAuto>();                   //lodsw
    _push(_si);                                   //push si
    _ax >>= 1;                                    //shr ax, 1
    _si = _ax;                                    //mov si, ax
    _cx = _ds;                                    //mov cx, ds
    _ax = 0xa400;                                 //mov ax, 0A400h
    _ds = _ax;                                    //mov ds, ax
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _di += _bp;                                   //add di, bp
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _di += _bp;                                   //add di, bp
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _di += _bp;                                   //add di, bp
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _di += _bp;                                   //add di, bp
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _di += _bp;                                   //add di, bp
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _di += _bp;                                   //add di, bp
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _di += _bp;                                   //add di, bp
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _di += _bp;                                   //add di, bp
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _di += _bp;                                   //add di, bp
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _di += _bp;                                   //add di, bp
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _di += _bp;                                   //add di, bp
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _di += _bp;                                   //add di, bp
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _di += _bp;                                   //add di, bp
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _di += _bp;                                   //add di, bp
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _di += _bp;                                   //add di, bp
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _di += _bp;                                   //add di, bp
    _di -= 0x027e;                                //sub di, 27Eh
    _ds = _cx;                                    //mov ds, cx
    _si = _pop();                                 //pop si
    _bl -= 1;                                     //dec bl
    if (_bl != 0)                                 //jnz short loc_204D5
      goto loc_204D5;
    _bl = 0x14;                                   //mov bl, 14h
    _di += 0x0258;                                //add di, 258h
    _bh -= 1;                                     //dec bh
    if (_bh != 0)                                 //jnz short loc_204D5
      goto loc_204D5;
    if (!(_dx & _dx))                             //jz short loc_2055C
      goto loc_2055C;
    _bl = 0x14;                                   //mov bl, 14h
loc_2053D:                                        //loc_2053D:
    _lodsw<MemAuto, DirAuto>();                   //lodsw
    _push(_si);                                   //push si
    _ax >>= 1;                                    //shr ax, 1
    _si = _ax;                                    //mov si, ax
    _push(_ds);                                   //push ds
    _ax = 0xa400;                                 //mov ax, 0A400h
    _ds = _ax;                                    //mov ds, ax
    _push(_di);                                   //push di
    _cx = _dx;                                    //mov cx, dx
loc_2054C:                                        //loc_2054C:
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();          //movsb
    _di += _bp;                                   //add di, bp
    if (--_cx)                                    //loop loc_2054C
      goto loc_2054C;
    _di = _pop();                                 //pop di
    _di += 0x0002;                                //add di, 2
    _ds = _pop();                                 //pop ds
    _si = _pop();                                 //pop si
    _bl -= 1;                                     //dec bl
    if (_bl != 0)                                 //jnz short loc_2053D
      goto loc_2053D;
loc_2055C:                                        //loc_2055C:
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0005;                                 //mov ax, 5
    _out(_dx, _ax);                               //out dx, ax
    _ax = _ds;                                    //mov ax, ds
    _es = _ax;                                    //mov es, ax
}

void sub_1080F()
{
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    switch (_bp)                                  //call cs:off_1081D[bp]
    {
      case 0: sub_1F3EF(); break;
      case 4: sub_23046(); break;
      case 8: sub_21844(); break;
      case 12: sub_1F3EF(); break;
      case 16: sub_21844(); break;
      default:
        _ASSERT(0);
    }
}

void sub_1F3EF()
{
    _ax = memory16(_ds, 0x9198);                  //mov ax, word_316C8
    sub_10ED5();                                  //call sub_10ED5
    _push(_es);                                   //push es
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0f01;                                 //mov ax, 0F01h
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x1003;                                 //mov ax, 1003h
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0805;                                 //mov ax, 805h
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0xa000;                                 //mov ax, 0A000h
    _es = _ax;                                    //mov es, ax
    _si = 0x9a40;                                 //mov si, 9A40h
    _cx = 0x10;                                   //mov cx, 10h
    _ax = 0x0400;                                 //mov ax, 400h
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0808;                                 //mov ax, 808h
    _out(_dx, _ax);                               //out dx, ax
    _bl = _al;                                    //mov bl, al
    _bp = memory16(_ds, 0x425B);                  //mov bp, word_2C78B
loc_1F420:                                        //loc_1F420:
    _di = memory16(_ds, _si);                     //mov di, [si]
    _di <<= 1;                                    //shl di, 1
    _di = memory16(_ds, _di + -26818);            //mov di, [di-68C2h]
    _di = _di + memory16(_ds, _si + 2);           //add di, [si+2]
    _di += _bp;                                   //add di, bp
    if (!(memory(_es, _di) & _bl))                //jz short loc_1F435
      goto loc_1F435;
    memory(_es, _di) = _al;                       //mov es:[di], al
loc_1F435:                                        //loc_1F435:
    _si += 0x0006;                                //add si, 6
    if (--_cx)                                    //loop loc_1F420
      goto loc_1F420;
    _cx = 0x10;                                   //mov cx, 10h
    _ax = 0x0500;                                 //mov ax, 500h
    _out(_dx, _ax);                               //out dx, ax
loc_1F441:                                        //loc_1F441:
    _di = memory16(_ds, _si);                     //mov di, [si]
    _di <<= 1;                                    //shl di, 1
    _di = memory16(_ds, _di + -26818);            //mov di, [di-68C2h]
    _di = _di + memory16(_ds, _si + 2);           //add di, [si+2]
    _di += _bp;                                   //add di, bp
    if (!(memory(_es, _di) & _bl))                //jz short loc_1F456
      goto loc_1F456;
    memory(_es, _di) = _al;                       //mov es:[di], al
loc_1F456:                                        //loc_1F456:
    _si += 0x0006;                                //add si, 6
    if (--_cx)                                    //loop loc_1F441
      goto loc_1F441;
    _cx = 0x10;                                   //mov cx, 10h
    _ax = 0x0700;                                 //mov ax, 700h
    _out(_dx, _ax);                               //out dx, ax
loc_1F462:                                        //loc_1F462:
    _di = memory16(_ds, _si);                     //mov di, [si]
    _di <<= 1;                                    //shl di, 1
    _di = memory16(_ds, _di + -26818);            //mov di, [di-68C2h]
    _di = _di + memory16(_ds, _si + 2);           //add di, [si+2]
    _di += _bp;                                   //add di, bp
    if (!(memory(_es, _di) & _bl))                //jz short loc_1F477
      goto loc_1F477;
    memory(_es, _di) = _al;                       //mov es:[di], al
loc_1F477:                                        //loc_1F477:
    _si += 0x0006;                                //add si, 6
    if (--_cx)                                    //loop loc_1F462
      goto loc_1F462;
    _ax = 0x0000;                                 //mov ax, 0
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0001;                                 //mov ax, 1
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0003;                                 //mov ax, 3
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0005;                                 //mov ax, 5
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0xff08;                                 //mov ax, 0FF08h
    _out(_dx, _ax);                               //out dx, ax
    _es = _pop();                                 //pop es
}

void sub_10ED5()
{
    sub_1421C();                                  //call sub_1421C
}

void sub_1421C()
{
    _si = 0x9a40;                                 //mov si, 9A40h
    _dx = _ax;                                    //mov dx, ax
    _cl = 0x03;                                   //mov cl, 3
    _dx <<= _cl;                                  //shl dx, cl
    _bx = _ax;                                    //mov bx, ax
    _bx <<= 1;                                    //shl bx, 1
    _ax = memory16(_ds, _bx + 12422);             //mov ax, [bx+3086h]
    _cx = 0x30;                                   //mov cx, 30h
    _bp = _dx;                                    //mov bp, dx
loc_14232:                                        //loc_14232:
    _bx = memory16(_ds, _si + 4);                 //mov bx, [si+4]
    _flags.sign = (short)(_bx + _dx) < 0;         //add bx, dx
    _bx += _dx;
    if (_flags.sign)                              //jns short loc_14247
      goto loc_14247;
loc_14239:                                        //loc_14239:
    memory16(_ds, _si) -= 1;                      //dec word ptr [si]
    if ((short)memory16(_ds, _si) >= 0)           //jns short loc_14241
      goto loc_14241;
    memory16(_ds, _si) = 0xbf;                    //mov word ptr [si], 0BFh
loc_14241:                                        //loc_14241:
    _flags.sign = (short)(_bx + 0x0180) < 0;      //add bx, 180h
    _bx += 0x0180;
    if (_flags.sign)                              //js short loc_14239
      goto loc_14239;
loc_14247:                                        //loc_14247:
    if ((short)_bx < (short)0x0180)               //jl short loc_1425F
      goto loc_1425F;
    memory16(_ds, _si) += 1;                      //inc word ptr [si]
    if ((short)memory16(_ds, _si) < (short)0xc0)  //jl short loc_14259
      goto loc_14259;
    memory16(_ds, _si) = 0;                       //mov word ptr [si], 0
loc_14259:                                        //loc_14259:
    _bx -= 0x0180;                                //sub bx, 180h
    goto loc_14247;                               //jmp short loc_14247
loc_1425F:                                        //loc_1425F:
    memory16(_ds, _si + 4) = _bx;                 //mov [si+4], bx
    _si += 0x0006;                                //add si, 6
    _dx += _bp;                                   //add dx, bp
    if (--_cx)                                    //loop loc_14232
      goto loc_14232;
}

void sub_10A2F()
{
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    switch (_bp)                                  //call cs:off_10A3D[bp]
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

void sub_10E4D()
{
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    switch (_bp)                                  //call cs:off_10E5B[bp]
    {
      case 0: sub_20854(); break;
      case 4: sub_24348(); break;
      case 8: sub_22386(); break;
      case 12: sub_20854(); break;
      case 16: sub_22386(); break;
      default:
        _ASSERT(0);
    }
}

void sub_20854()
{
    _ax = memory16(_ds, 0x9152);                  //mov ax, word_31682
    _dx = memory16(_ds, 0x9154);                  //mov dx, word_31684
    _flags.sign = (short)(_ax - memory16(_ds, 0x9156)) < 0;
    _ax = _ax - memory16(_ds, 0x9156);
    _dx -= memory16(_ds, 0x9158) + _flags.carry;  //sbb dx, word_31688
    if (_flags.sign)                              //js short loc_208CF
      goto loc_208CF;
    if (_ax != 0)                                 //jnz short loc_2086B
      goto loc_2086B;
    if (!(_ax & _ax))                             //jz short locret_208CE
      goto locret_208CE;
loc_2086B:                                        //loc_2086B:
    if (_dx & _dx)                                //jnz short loc_20879
      goto loc_20879;
    if ((short)_ax < (short)0xc8)                 //jl short loc_20894
      goto loc_20894;
    if ((short)_ax < (short)0x07d0)               //jl short loc_20887
      goto loc_20887;
loc_20879:                                        //loc_20879:
    _bx = 0x921f;                                 //mov bx, 921Fh
    _di = 0x1e06;                                 //mov di, 1E06h
    memory16(_ds, 0x9156) += 1000;                //add word_31686, 3E8h
    goto loc_2089F;                               //jmp short loc_2089F
loc_20887:                                        //loc_20887:
    _bx = 0x9220;                                 //mov bx, 9220h
    _di = 0x1e07;                                 //mov di, 1E07h
    memory16(_ds, 0x9156) += 0x64;                //add word_31686, 64h
    goto loc_2089F;                               //jmp short loc_2089F
loc_20894:                                        //loc_20894:
    _bx = 0x9221;                                 //mov bx, 9221h
    _di = 0x1e08;                                 //mov di, 1E08h
    memory16(_ds, 0x9156) += 0x0a;                //add word_31686, 0Ah
loc_2089F:                                        //loc_2089F:
    memory16(_ds, 0x9158) = memory16(_ds, 0x9158) + 0 + _flags.carry; _ASSERT(0); ;
    if (memory16(_ds, 0x8E7A) == 0)               //jz short loc_208AE
      goto loc_208AE;
    _di += 0x1b;                                  //add di, 1Bh
loc_208AE:                                        //loc_208AE:
    _si = 0x0500;                                 //mov si, 500h
loc_208B1:                                        //loc_208B1:
    memory(_ds, _bx) += 1;                        //inc byte ptr [bx]
    if ((char)memory(_ds, _bx) < (char)0x0a)      //jl short loc_208BB
      goto loc_208BB;
    memory(_ds, _bx) = 0;                         //mov byte ptr [bx], 0
loc_208BB:                                        //loc_208BB:
    _al = memory(_ds, _bx);                       //mov al, [bx]
    sub_20919();                                  //call near ptr sub_20919
    if (memory(_ds, _bx) != 0)                    //jnz short locret_208CE
      goto locret_208CE;
    _di -= 1;                                     //dec di
    _bx -= 1;                                     //dec bx
    if ((short)_bx >= (short)0x921c)              //jge short loc_208B1
      goto loc_208B1;
locret_208CE:                                     //locret_208CE:
    return;                                       //retf
loc_208CF:                                        //loc_208CF:
    _ax = memory16(_ds, 0x9156);                  //mov ax, word_31686
    memory16(_ds, 0x9152) = _ax;                  //mov word_31682, ax
    _ax = memory16(_ds, 0x9158);                  //mov ax, word_31688
    memory16(_ds, 0x9154) = _ax;                  //mov word_31684, ax
}

void sub_20919()
{
    _push(_si);                                   //push si
    _push(_cx);                                   //push cx
    _ah = _ah ^ _ah;                              //xor ah, ah
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _si += _ax;                                   //add si, ax
    _push(_ds);                                   //push ds
    _ax = 0x3824;                                 //mov ax, 3824h
    _ds = _ax;                                    //mov ds, ax
    _ax = 0xa000;                                 //mov ax, 0A000h
    _es = _ax;                                    //mov es, ax
    _dx = 0x03c4;                                 //mov dx, 3C4h
    _ax = 0x0102;                                 //mov ax, 102h
    _out(_dx, _ax);                               //out dx, ax
    sub_2095F();                                  //call sub_2095F
    _ax = 0x0202;                                 //mov ax, 202h
    _out(_dx, _ax);                               //out dx, ax
    sub_2095F();                                  //call sub_2095F
    _ax = 0x0402;                                 //mov ax, 402h
    _out(_dx, _ax);                               //out dx, ax
    sub_2095F();                                  //call sub_2095F
    _ax = 0x0802;                                 //mov ax, 802h
    _out(_dx, _ax);                               //out dx, ax
    sub_2095F();                                  //call sub_2095F
    _ax = 0x0f02;                                 //mov ax, 0F02h
    _out(_dx, _ax);                               //out dx, ax
    _ax = _pop();                                 //pop ax
    _ds = _ax;                                    //mov ds, ax
    _es = _ax;                                    //mov es, ax
    _cx = _pop();                                 //pop cx
    _si = _pop();                                 //pop si
}

void sub_2095F()
{
    _push(_di);                                   //push di
    _cx = 0x0008;                                 //mov cx, 8
loc_20963:                                        //loc_20963:
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    memory(_es, _di) = _al;                       //mov es:[di], al
    memory(_es, _di + 8192) = _al;                //mov es:[di+2000h], al
    _di += 0x28;                                  //add di, 28h
    if (--_cx)                                    //loop loc_20963
      goto loc_20963;
    _di = _pop();                                 //pop di
}

void sub_10BA5()
{
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    switch (_bp)                                  //call cs:off_10BB3[bp]
    {
      case 0: sub_20AD0(); break;
      case 4: sub_245B4(); break;
      case 8: sub_225AC(); break;
      case 12: sub_20AD0(); break;
      case 16: sub_225AC(); break;
      default:
        _ASSERT(0);
    }
}

void sub_136FC()
{
    if (memory16(_ds, _si) == 0)                  //jz short locret_1370A
      goto locret_1370A;
    _push(memory16(_ds, _si + 10));               //push word ptr [si+0Ah]
    _STOP_("call word ptr [si+2]");               //call word ptr [si+2]
    _si = _pop();                                 //pop si
    sub_136FC();                               //jmp short sub_136FC
locret_1370A:                                     //locret_1370A:
    return;
}

void sub_1370B()
{
    if (memory16(_ds, _si) == 0)                  //jz short locret_13719
      goto locret_13719;
    _push(memory16(_ds, _si + 10));               //push word ptr [si+0Ah]
    _STOP_("call word ptr [si+4]");               //call word ptr [si+4]
    _si = _pop();                                 //pop si
    sub_1370B();                               //jmp short sub_1370B
locret_13719:                                     //locret_13719:
    return;
}

void sub_20AD0()
{
    if (memory(_ds, 0x8FAF) != 0)                 //jnz short loc_20ADA
      goto loc_20ADA;
    goto locret_20B5A;                            //jmp locret_20B5A
loc_20ADA:                                        //loc_20ADA:
    memory(_ds, 0x8FAF) = 0;                      //mov byte_314DF, 0
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0e00;                                 //mov ax, 0E00h
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0f01;                                 //mov ax, 0F01h
    _out(_dx, _ax);                               //out dx, ax
    _al = 0x08;                                   //mov al, 8
    _out(_dx, _al);                               //out dx, al
    _dx += 1;                                     //inc dx
    _ax = 0xa000;                                 //mov ax, 0A000h
    _es = _ax;                                    //mov es, ax
    _bx = memory16(_ds, 0x9186);                  //mov bx, word_316B6
    if ((short)_bx <= (short)0x27)                //jle short loc_20AFF
      goto loc_20AFF;
    _bx = 0x27;                                   //mov bx, 27h
loc_20AFF:                                        //loc_20AFF:
    _bx -= 0x27;                                  //sub bx, 27h
    _bx = -_bx;                                   //neg bx
    _di = 0x1e83;                                 //mov di, 1E83h
    _al = 0x10;                                   //mov al, 10h
    if (memory16(_ds, 0x8E7A) == 0)               //jz short loc_20B15
      goto loc_20B15;
    _di = 0x1e8f;                                 //mov di, 1E8Fh
    _al = 0x02;                                   //mov al, 2
loc_20B15:                                        //loc_20B15:
    _cx = 0x27;                                   //mov cx, 27h
loc_20B18:                                        //loc_20B18:
    if (_cx != _bx)                               //jnz short loc_20B27
      goto loc_20B27;
    _push(_ax);                                   //push ax
    _dx -= 1;                                     //dec dx
    _ax = 0x0000;                                 //mov ax, 0
    _out(_dx, _ax);                               //out dx, ax
    _al = 0x08;                                   //mov al, 8
    _out(_dx, _al);                               //out dx, al
    _dx += 1;                                     //inc dx
    _ax = _pop();                                 //pop ax
loc_20B27:                                        //loc_20B27:
    _out(_dx, _al);                               //out dx, al
    memory(_es, _di) &= _al;                      //and es:[di], al
    memory(_es, _di + 40) &= _al;                 //and es:[di+28h], al
    memory(_es, _di + 80) &= _al;                 //and es:[di+50h], al
    memory(_es, _di + 8192) &= _al;               //and es:[di+2000h], al
    memory(_es, _di + 8232) &= _al;               //and es:[di+2028h], al
    memory(_es, _di + 8272) &= _al;               //and es:[di+2050h], al
    _ror(_al, 1);                                  //ror al, 1
    _flags.carry = !!(_al & 0x80);
    if (!_flags.carry)                            //jnb short loc_20B47
      goto loc_20B47;
    _di += 1;                                     //inc di
loc_20B47:                                        //loc_20B47:
    if (--_cx)                                    //loop loc_20B18
      goto loc_20B18;
    _dx -= 1;                                     //dec dx
    _ax = 0x0000;                                 //mov ax, 0
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0001;                                 //mov ax, 1
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0xff08;                                 //mov ax, 0FF08h
    _out(_dx, _ax);                               //out dx, ax
    _ax = _ds;                                    //mov ax, ds
    _es = _ax;                                    //mov es, ax
locret_20B5A:                                     //locret_20B5A:
    return;
}

