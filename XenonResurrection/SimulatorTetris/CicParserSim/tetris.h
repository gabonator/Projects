void start();
void sub_1859B();
void sub_185AC();
void sub_186B6();
void sub_18768();
void sub_1880D();
void sub_18870();
void sub_1888B();
void sub_188AB();
void sub_188B9();
void sub_188CD();
void sub_188E1();
void sub_18923();
void sub_18935();
void sub_189A1();
void sub_189F8();
void sub_18A09();
void sub_18A49();
void sub_18A8D();
void sub_18AAB();
void sub_18B13();
void sub_18B2A();
void sub_18B35();
void sub_18B4E();
void sub_18B77();
void sub_18BB2();
void sub_18BED();
void sub_18C30();
void sub_18D4C();
void sub_18DCF();
void sub_18DF7();
void sub_19093();
void sub_1909A();
void sub_190C8();
void sub_190F6();
void sub_19111();
void sub_1914B();
void sub_1916C();
void sub_1918B();
void loc_191C4();
void sub_192A7();
void sub_193B4();
void sub_193C1();
void sub_19433();
void sub_1961F();
void sub_19645();
void sub_1966E();
void sub_196F9();
void sub_1973C();
void loc_199CA();
void sub_19A02();
void sub_19A8B();
void loc_19B26();
void sub_19B30();
void sub_19B5C();
void loc_19BBD();
void sub_19BCA();
void sub_19C06();
void sub_19C18();
void sub_19C38();
void sub_19C43();
void sub_19C59();
void sub_1A042();
void sub_1A069();
void sub_1A108();
void sub_1A10C();
void sub_1A110();
void sub_1A114();
void sub_1A11B();
void sub_1A196();
void sub_1A1C4();
void sub_1A209();
void sub_1A26D();
void sub_1A322();
void sub_1A34A();
void sub_1A3AC();
void sub_1A3DE();
void sub_1A40E();
void sub_1A4C8();
void sub_1A63C();
void sub_1A699();
void sub_1A6D3();
void sub_1A71B();
void loc_1A784();
void sub_1A7D2();
void sub_1A802();
void sub_1A833();
void sub_1A876();
void sub_1A8FC();
void sub_1A941();
void sub_1A947();
void sub_1A9BB();
void sub_1A9D8();
void sub_1AA67();
void sub_1AB24();
void sub_1AB3E();
void sub_1AB61();
void sub_1ABFC();
void loc_1AC7A();
void sub_1ACAE();
void sub_1AD03();
void sub_1AD74();
void sub_1ADF9();
void sub_1AE5E();
void sub_1AF12();
void sub_1AF23();
void sub_1AF58();
void sub_1AF7C();
void nullsub_1() { }

void start()  // Entry function
{
    WORD _cs = _seg003;

    _push(_ds);                                 //push ds
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_ax);                                 //push ax
    _push(_ds);                                 //push ds
    _ax = _seg002;                              //mov ax, seg seg002
    _ds = _ax;                                  //mov ds, ax
    _cx = _cx ^ _cx;                            //xor cx, cx
    _dh = 0x18;                                 //mov dh, 18h
    _dl = 0x4f;                                 //mov dl, 4Fh
    _bh = _bh ^ _bh;                            //xor bh, bh
    _al = _al ^ _al;                            //xor al, al
    _ah = 0x06;                                 //mov ah, 6
    _interrupt(16);                             //int 10h
    _ax = 0x0001;                               //mov ax, 1
    _interrupt(16);                             //int 10h
    _dx = 0x0096;                               //mov dx, 96h
    _ah = 0x09;                                 //mov ah, 9
    _interrupt(33);                             //int 21h
    _dx = 0x00cb;                               //mov dx, 0CBh
    _ah = 0x0a;                                 //mov ah, 0Ah
    _interrupt(33);                             //int 21h
    _ah = memory(_ds, 0xCD);                    //mov ah, byte_1019D
    if (_ah != 0x79)                            //jnz short loc_183D8
        goto loc_183D8;
    goto loc_183E5;                             //jmp short loc_183E5
loc_183D8:                                      //loc_183D8:
    if (_ah == 0x59)                            //jz short loc_183E5
        goto loc_183E5;
    memory(_ds, 0xCF) = 0x00;                   //mov byte_1019F, 0
    goto loc_183EA;                             //jmp short loc_183EA
    _STOP_("db 90h");                           //db 90h
loc_183E5:                                      //loc_183E5:
    memory(_ds, 0xCF) = 0x01;                   //mov byte_1019F, 1
loc_183EA:                                      //loc_183EA:
    sub_18A09();                                //call sub_18A09
    _bx = 0x0c80;                               //mov bx, 0C80h
    _ah = 0x4a;                                 //mov ah, 4Ah
    _interrupt(33);                             //int 21h
    memory(_ds, 0x5E39) = 0x00;                 //mov byte_15F09, 0
    sub_18AAB();                                //call sub_18AAB
    if (memory(_ds, 0x5D9D) != 0x01)            //jnz short loc_18406
        goto loc_18406;
    goto loc_18571;                             //jmp loc_18571
loc_18406:                                      //loc_18406:
    sub_18A49();                                //call sub_18A49
    _ax = _seg001;                              //mov ax, seg seg001
    _es = _ax;                                  //mov es, ax
    _ds = _pop();                               //pop ds
    _si = 0x0080;                               //mov si, 80h
    _di = 0x0000;                               //mov di, 0
    _cx = 0x0080;                               //mov cx, 80h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _ax = _seg002;                              //mov ax, seg seg002
    _ds = _ax;                                  //mov ds, ax
    memory(_cs, 0x0) = 0x00;                    //mov cs:byte_18390, 0
    if (memory(_es, 0x0) != 0x02)               //jnz short loc_18449
        goto loc_18449;
    if (memory(_es, 0x2) == 0x48)               //jz short loc_1843D
        goto loc_1843D;
    if (memory(_es, 0x2) != 0x68)               //jnz short loc_18449
        goto loc_18449;
loc_1843D:                                      //loc_1843D:
    memory(_cs, 0x0) = 0x01;                    //mov cs:byte_18390, 1
    sub_18BB2();                                //call sub_18BB2
    goto loc_18468;                             //jmp short loc_18468
    _STOP_("db 90h");                           //db 90h
loc_18449:                                      //loc_18449:
    memory(_ds, 0x5D9C) = 0x00;                 //mov byte_15E6C, 0
    memory(_ds, 0x5D9D) = 0x00;                 //mov byte_15E6D, 0
    _ax = 0xf000;                               //mov ax, 0F000h
    _es = _ax;                                  //mov es, ax
    _al = memoryBiosGet(_es, 0xFFFE);                  //mov al, es:0FFFEh
    if (_al != 0xfd)                            //jnz short loc_18465
        goto loc_18465;
    memory(_ds, 0x5D9C) = 0x01;                 //mov byte_15E6C, 1
loc_18465:                                      //loc_18465:
    sub_1A6D3();                                //call sub_1A6D3
loc_18468:                                      //loc_18468:
    sub_19C43();                                //call sub_19C43
    _ax = _seg002;                              //mov ax, seg seg002
    _es = _ax;                                  //mov es, ax
    _ds = _ax;                                  //mov ds, ax
    _dx = 0x0201;                               //mov dx, 201h
    _si = 0x0008;                               //mov si, 8
    _bx = _bx ^ _bx;                            //xor bx, bx
    _ah = 0x01;                                 //mov ah, 1
loc_1847C:                                      //loc_1847C:
    sub_1859B();                                //call sub_1859B
    _bx += _cx;                                 //add bx, cx
    _si -= 1;                                   //dec si
    if (_si != 0)                               //jnz short loc_1847C
        goto loc_1847C;
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _flags.carry = _bx & 1;                     //shr bx, 1
    _bx >>= 1;
    _bx = _bx + 0x0000 + _flags.carry;          //adc bx, 0
    memory16(_ds, 0x92) = _bx;                  //mov word_10162, bx
    _si = 0x0008;                               //mov si, 8
    _bx = _bx ^ _bx;                            //xor bx, bx
    _ah = 0x02;                                 //mov ah, 2
loc_18498:                                      //loc_18498:
    sub_1859B();                                //call sub_1859B
    _bx += _cx;                                 //add bx, cx
    _si -= 1;                                   //dec si
    if (_si != 0)                               //jnz short loc_18498
        goto loc_18498;
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _flags.carry = _bx & 1;                     //shr bx, 1
    _bx >>= 1;
    _bx = _bx + 0x0000 + _flags.carry;          //adc bx, 0
    memory16(_ds, 0x94) = _bx;                  //mov word_10164, bx
    _push(_es);                                 //push es
    _ax = 0xf000;                               //mov ax, 0F000h
    _es = _ax;                                  //mov es, ax
    if (memoryBiosGet(_es, 0xFFFE) == 0xfc)            //jz short loc_184C4
        goto loc_184C4;
    memory16(_ds, 0x90) = 0x0018;               //mov word_10160, 18h
    goto loc_184CA;                             //jmp short loc_184CA
loc_184C4:                                      //loc_184C4:
    memory16(_ds, 0x90) = 0x0096;               //mov word_10160, 96h
loc_184CA:                                      //loc_184CA:
    _es = _pop();                               //pop es
    memory(_ds, 0x5D11) = 0x00;                 //mov byte_15DE1, 0
    _dx = 0x4612;                               //mov dx, 4612h
    _cx = 0x3e84;                               //mov cx, 3E84h
    memory16(_ds, 0x4610) = 0x0243;             //mov word_146E0, 243h
    sub_1914B();                                //call sub_1914B
    sub_18DF7();                                //call sub_18DF7
    if (memory(_ds, 0x5E39) != 0x01)            //jnz short loc_184EC
        goto loc_184EC;
    goto loc_18571;                             //jmp loc_18571
loc_184EC:                                      //loc_184EC:
    memory16(_ds, 0x4289) = 0x4321;             //mov word_14359, 4321h
loc_184F2:                                      //loc_184F2:
    sub_196F9();                                //call sub_196F9
    memory16(_ds, 0x5D25) = 0xffff;             //mov word_15DF5, 0FFFFh
    sub_19433();                                //call sub_19433
    if (memory(_ds, 0x5E39) != 0x01)            //jnz short loc_18508
        goto loc_18508;
    goto loc_18571;                             //jmp short loc_18571
loc_18508:                                      //loc_18508:
    _bx = memory16(_ds, 0x40C9);                //mov bx, word_14199
    _bx |= _bx;                                 //or bx, bx
    if (_bx != 0)                               //jnz short loc_18522
        goto loc_18522;
    _dx = 0x5d9e;                               //mov dx, 5D9Eh
    _cx = 0x3e82;                               //mov cx, 3E82h
    memory16(_ds, 0x4610) = 0x0245;             //mov word_146E0, 245h
    sub_1914B();                                //call sub_1914B
    goto loc_18531;                             //jmp short loc_18531
loc_18522:                                      //loc_18522:
    _bx -= 1;                                   //dec bx
    _bx <<= 1;                                  //shl bx, 1
    _ds = memory16(_ds, _bx + 24048);           //mov ds, word ptr [bx+5DF0h]
    sub_18B2A();                                //call sub_18B2A
    _ax = _seg002;                              //mov ax, seg seg002
    _ds = _ax;                                  //mov ds, ax
loc_18531:                                      //loc_18531:
    sub_19C59();                                //call sub_19C59
    if (memory(_ds, 0x5E39) == 0x01)            //jz short loc_18571
        goto loc_18571;
    sub_192A7();                                //call sub_192A7
    sub_1973C();                                //call sub_1973C
    _bp = 0x44b1;                               //mov bp, 44B1h
    memory16(_ds, 0x42E2) = 0x0007;             //mov word_143B2, 7
    memory16(_ds, 0x42E4) = 0x00be;             //mov word_143B4, 0BEh
    sub_1A947();                                //call sub_1A947
loc_18553:                                      //loc_18553:
    sub_19C06();                                //call sub_19C06
    sub_19BCA();                                //call sub_19BCA
    sub_19C18();                                //call sub_19C18
    if (_ah == 0x31)                            //jz short loc_18571
        goto loc_18571;
    if (_ah != 0x15)                            //jnz short loc_18553
        goto loc_18553;
    sub_19C38();                                //call sub_19C38
    memory16(_ds, 0x4289) += 0x6539;            //add word_14359, 6539h
    goto loc_184F2;                             //jmp short loc_184F2
loc_18571:                                      //loc_18571:
    std::cout << "Exit game\n";
    sub_1A699();                                //call sub_1A699
    sub_18B13();                                //call sub_18B13
    _ax = 0x0040;                               //mov ax, 40h
    _es = _ax;                                  //mov es, ax
    memory(_es, 0x17) &= 0xdf;                  //and byte ptr es:17h, 0DFh
    _ax = _seg002;                              //mov ax, seg seg002
    _es = _ax;                                  //mov es, ax
    _ax = 0x0003;                               //mov ax, 3
    _interrupt(16);                             //int 10h
    if (memory(_ds, 0x5D9D) == 0x00)            //jz short locret_1859A
        goto locret_1859A;
    _ah = 0x09;                                 //mov ah, 9
    _dx = 0x5d65;                               //mov dx, 5D65h
    _interrupt(33);                             //int 21h
locret_1859A:                                   //locret_1859A:
    return;                                     //retf
    _STOP_("sp-trace-fail");                    //start  endp_failed
    _STOP_("continues");                        //sub_1859B proc near
}

void sub_1859B()
{
    _dx = 0x0201;                               //mov dx, 201h
    _cx = 0x0400;                               //mov cx, 400h
loc_185A1:                                      //loc_185A1:
    if (--_cx)                                  //loop loc_185A1
        goto loc_185A1;
    _out(_dx, _al);                             //out dx, al
loc_185A4:                                      //loc_185A4:
    _in(_al, _dx);                              //in al, dx
    if (--_cx && _ah & _al)                     //loopne loc_185A4
        goto loc_185A4;
    _cx = -_cx;                                 //neg cx
}

void sub_185AC()
{
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_bp);                                 //push bp
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = _seg002;                              //mov ax, seg seg002
    _ds = _ax;                                  //mov ds, ax
    _dx = 0x0201;                               //mov dx, 201h
    _cx = 0x0400;                               //mov cx, 400h
loc_185BF:                                      //loc_185BF:
    if (--_cx)                                  //loop loc_185BF
        goto loc_185BF;
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x10)                             //jnz short loc_185D0
        goto loc_185D0;
loc_185C6:                                      //loc_185C6:
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x10))                          //jz short loc_185C6
        goto loc_185C6;
    _ah = 0x1c;                                 //mov ah, 1Ch
    goto loc_1862E;                             //jmp short loc_1862E
loc_185D0:                                      //loc_185D0:
    _ax = _ax ^ _ax;                            //xor ax, ax
    _ah += 1;                                   //inc ah
    sub_1859B();                                //call sub_1859B
    _si = _cx;                                  //mov si, cx
    _ah += 1;                                   //inc ah
    sub_1859B();                                //call sub_1859B
    _dx = _cx;                                  //mov dx, cx
    _bp = _bp ^ _bp;                            //xor bp, bp
    _di = _di ^ _di;                            //xor di, di
    _si = _si - memory16(_ds, 0x92);            //sub si, word_10162
    _bp = _si;                                  //mov bp, si
    if ((short)_si >= (short)0x0000)            //jge short loc_185F1
        goto loc_185F1;
    _si = -_si;                                 //neg si
loc_185F1:                                      //loc_185F1:
    _dx = _dx - memory16(_ds, 0x94);            //sub dx, word_10164
    _di = _dx;                                  //mov di, dx
    if ((short)_dx >= (short)0x0000)            //jge short loc_185FE
        goto loc_185FE;
    _dx = -_dx;                                 //neg dx
loc_185FE:                                      //loc_185FE:
    if ((short)_si < (short)_dx)                //jl short loc_18617
        goto loc_18617;
    if ((short)_si < (short)memory16(_ds, 0x90))//jl short loc_1862C
        goto loc_1862C;
    if ((short)_bp < (short)0x0000)             //jl short loc_18612
        goto loc_18612;
    _ah = 0x4d;                                 //mov ah, 4Dh
    goto loc_1862E;                             //jmp short loc_1862E
loc_18612:                                      //loc_18612:
    _ah = 0x4b;                                 //mov ah, 4Bh
    goto loc_1862E;                             //jmp short loc_1862E
    _STOP_("db 90h");                           //db 90h
loc_18617:                                      //loc_18617:
    if ((short)_dx < (short)memory16(_ds, 0x90))//jl short loc_1862C
        goto loc_1862C;
    if ((short)_di < (short)0x0000)             //jl short loc_18627
        goto loc_18627;
    _ah = 0x50;                                 //mov ah, 50h
    goto loc_1862E;                             //jmp short loc_1862E
    _STOP_("db 90h");                           //db 90h
loc_18627:                                      //loc_18627:
    _ah = 0x48;                                 //mov ah, 48h
    goto loc_1862E;                             //jmp short loc_1862E
loc_1862C:                                      //loc_1862C:
    _ah = _ah ^ _ah;                            //xor ah, ah
loc_1862E:                                      //loc_1862E:
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _bp = _pop();                               //pop bp
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
}

void sub_186B6() // draw sprites
{
    WORD _cs = _seg003;

    _push(_es);                                 //push es
    _push(_ds);                                 //push ds
    _si = _seg002;                              //mov si, seg seg002
    _ds = _si;                                  //mov ds, si
    _si = 0xa000;                               //mov si, 0A000h
    _es = _si;                                  //mov es, si
    _bp = 0x5dc0;                               //mov bp, 5DC0h
    _bp += 0x0008;                              //add bp, 8
    _bx = _bx ^ _bx;                            //xor bx, bx
    _bx += 0x0002;                              //add bx, 2
    memory16(_cs, 0x324) = _bx;                 //mov cs:word_186B4, bx
    memory16(_cs, 0x31C) = 0x0008;              //mov cs:word_186AC, 8
loc_186DA:                                      //loc_186DA:
    _si = 0x0010;                               //mov si, 10h
    memory16(_ds, _bx + 208) = _bp;             //mov [bx+0D0h], bp
    _cx = memory16(_cs, _bx + 677);             //mov cx, cs:[bx+2A5h]
    memory16(_cs, 0x31A) = _cx;                 //mov cs:word_186AA, cx
    _push(_bp);                                 //push bp
    sub_1880D();                                //call sub_1880D
    _bp = _pop();                               //pop bp
    _bx = memory16(_cs, 0x324);                 //mov bx, cs:word_186B4
    _bp = _bp + memory16(_cs, 0x31C);           //add bp, cs:word_186AC
    _bx += 0x0002;                              //add bx, 2
    memory16(_cs, 0x324) = _bx;                 //mov cs:word_186B4, bx
    if ((short)_bx < (short)0x0010)             //jl short loc_186DA
        goto loc_186DA;
    _si = 0x0080;                               //mov si, 80h
    memory16(_ds, _bx + 208) = _bp;             //mov [bx+0D0h], bp
    _cx = memory16(_cs, _bx + 677);             //mov cx, cs:[bx+2A5h]
    memory16(_cs, 0x31A) = _cx;                 //mov cs:word_186AA, cx
    _push(_bp);                                 //push bp
    sub_1880D();                                //call sub_1880D
    _bp = _pop();                               //pop bp
    _bx = memory16(_cs, 0x324);                 //mov bx, cs:word_186B4
    _bp = _bp + memory16(_cs, 0x31C);           //add bp, cs:word_186AC
    _bx += 0x0002;                              //add bx, 2
    memory16(_cs, 0x324) = _bx;                 //mov cs:word_186B4, bx
    memory16(_cs, 0x31C) = 0x002d;              //mov cs:word_186AC, 2Dh
    _cx = 0x0315;                               //mov cx, 315h
    memory16(_cs, 0x31A) = _cx;                 //mov cs:word_186AA, cx
loc_1873E:                                      //loc_1873E:
    _si = memory16(_ds, _bx + 24563);           //mov si, [bx+5FF3h]
    _si += 0x0002;                              //add si, 2
    memory16(_ds, _bx + 208) = _bp;             //mov [bx+0D0h], bp
    _push(_bp);                                 //push bp
    sub_1880D();                                //call sub_1880D
    _bp = _pop();                               //pop bp
    _bx = memory16(_cs, 0x324);                 //mov bx, cs:word_186B4
    _bp = _bp + memory16(_cs, 0x31C);           //add bp, cs:word_186AC
    _bx += 0x0002;                              //add bx, 2
    memory16(_cs, 0x324) = _bx;                 //mov cs:word_186B4, bx
    if ((short)_bx < (short)0x0028)             //jl short loc_1873E
        goto loc_1873E;
    _ds = _pop();                               //pop ds
    _es = _pop();                               //pop es
}

void sub_18768()
{
    WORD _cs = _seg003;

    _bx = memory16(_cs, 0x320);                 //mov bx, cs:word_186B0
    sub_1888B();                                //call sub_1888B
    _di = memory16(_cs, 0x31E);                 //mov di, cs:word_186AE
    _si = memory16(_cs, 0x320);                 //mov si, cs:word_186B0
    sub_18870();                                //call sub_18870
    _di = memory16(_cs, 0x31E);                 //mov di, cs:word_186AE
    _si = memory16(_cs, 0x320);                 //mov si, cs:word_186B0
    memory16(_cs, 0x31E) = _si;                 //mov cs:word_186AE, si
    memory16(_cs, 0x320) = _di;                 //mov cs:word_186B0, di
}

void sub_1880D() // ega draw
{
    WORD _cs = _seg003;
    _sync();
    if (memory(_ds, 0x6471) == 0x01)            //jz short locret_1886F
        goto locret_1886F;
    _al = 0x0f;                                 //mov al, 0Fh
    sub_188B9();                                //call sub_188B9
    _al = 0x02;                                 //mov al, 2
    sub_188CD();                                //call sub_188CD
    _dx = 0x03ce;                               //mov dx, 3CEh
    _al = 0x08;                                 //mov al, 8
    _out(_dx, _al);                             //out dx, al
    _dx = 0;                                    //sub dx, dx
    _bx = memory16(_cs, 0x31A);                 //mov bx, cs:word_186AA
    _ax = memory16(_cs, 0x31C);                 //mov ax, cs:word_186AC
    _cl = 0x06;                                 //mov cl, 6
loc_18831:                                      //loc_18831:
    _push(_ax);                                 //push ax
    _ch = 0x80;                                 //mov ch, 80h
loc_18834:                                      //loc_18834:
    _ah = 0x04;                                 //mov ah, 4
    _dl = memory(_ds, _si);                     //mov dl, [si]
    _si += 1;                                   //inc si
    _push(_si);                                 //push si
loc_1883A:                                      //loc_1883A:
    _di = _dx;                                  //mov di, dx
    _di &= 0x00c0;                              //and di, 0C0h
    _di >>= _cl;                                //shr di, cl
    _si = _dx;                                  //mov si, dx
    _dx = 0x03cf;                               //mov dx, 3CFh
    _al = _ch;                                  //mov al, ch
    _out(_dx, _al);                             //out dx, al
    _dx = _si;                                  //mov dx, si
    _al = memoryVideoGet(_es, _bp + 0);                 //mov al, es:[bp+0]
    _al = memory(_cs, _bx + _di);               //mov al, cs:[bx+di]
    memoryVideoSet(_es, _bp + 0, _al);                 //mov es:[bp+0], al
    _ch >>= 1;                                  //shr ch, 1
    _ah -= 1;                                   //dec ah
    if (_ah == 0)                               //jz short loc_18861
        goto loc_18861;
    _ror(_dl, _cl);                             //ror dl, cl
    goto loc_1883A;                             //jmp short loc_1883A
loc_18861:                                      //loc_18861:
    _si = _pop();                               //pop si
    _ch |= _ch;                                 //or ch, ch
    if (_ch == 0)                               //jz short loc_18868
        goto loc_18868;
    goto loc_18834;                             //jmp short loc_18834
loc_18868:                                      //loc_18868:
    _bp += 1;                                   //inc bp
    _ax = _pop();                               //pop ax
    _ax -= 1;                                   //dec ax
    if (_ax == 0)                               //jz short locret_1886F
        goto locret_1886F;
    goto loc_18831;                             //jmp short loc_18831
locret_1886F:                                   //locret_1886F:
    return;
}

void sub_18870()
{
    _push(_es);                                 //push es
    _push(_ds);                                 //push ds
    _ax = 0xa000;                               //mov ax, 0A000h
    _es = _ax;                                  //mov es, ax
    _ds = _ax;                                  //mov ds, ax
    _al = 0x01;                                 //mov al, 1
    sub_188CD();                                //call sub_188CD
    _al = 0x0f;                                 //mov al, 0Fh
    sub_188B9();                                //call sub_188B9
    _cx = 0x1f40;                               //mov cx, 1F40h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _ds = _pop();                               //pop ds
    _es = _pop();                               //pop es
}

void sub_1888B()
{
    _push(_es);                                 //push es
    _ax = 0xa000;                               //mov ax, 0A000h
    _es = _ax;                                  //mov es, ax
    sub_188AB();                                //call sub_188AB
    _dx = 0x03d4;                               //mov dx, 3D4h
    _al = 0x0d;                                 //mov al, 0Dh
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _al = _bl;                                  //mov al, bl
    _out(_dx, _al);                             //out dx, al
    _dx -= 1;                                   //dec dx
    _al = 0x0c;                                 //mov al, 0Ch
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _al = _bh;                                  //mov al, bh
    _out(_dx, _al);                             //out dx, al
    sub_188AB();                                //call sub_188AB
    _es = _pop();                               //pop es
}

void sub_188AB()
{
    _dx = 0x03da;                               //mov dx, 3DAh
loc_188AE:                                      //loc_188AE:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x08;                                //and al, 8
    if (_al != 0)                               //jnz short loc_188AE
        goto loc_188AE;
loc_188B3:                                      //loc_188B3:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x08;                                //and al, 8
    if (_al == 0)                               //jz short loc_188B3
        goto loc_188B3;
}

void sub_188B9()
{
    if (_ds != 0xa000)//??
    {
        if (memory(_ds, 0x6471) == 0x01)            //jz short locret_188E0
            goto locret_188CC;
    } else {
        if (memoryVideoGet(_ds, 0x6471) == 0x01)            //jz short locret_188E0
            goto locret_188CC;
    }

    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _dx = 0x03c4;                               //mov dx, 3C4h
    _al = 0x02;                                 //mov al, 2
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _ax = _pop();                               //pop ax
    _out(_dx, _al);                             //out dx, al
    _dx = _pop();                               //pop dx
locret_188CC:                                   //locret_188CC:
    return;
}

void sub_188CD()
{
    if (_ds != 0xa000)//??
    {
        if (memory(_ds, 0x6471) == 0x01)            //jz short locret_188E0
            goto locret_188E0;
    } else {
        if (memoryVideoGet(_ds, 0x6471) == 0x01)            //jz short locret_188E0
            goto locret_188E0;
    }
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _dx = 0x03ce;                               //mov dx, 3CEh
    _al = 0x05;                                 //mov al, 5
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _ax = _pop();                               //pop ax
    _out(_dx, _al);                             //out dx, al
    _dx = _pop();                               //pop dx
locret_188E0:                                   //locret_188E0:
    return;
}

void sub_188E1()
{
    if (_ds != 0xa000)//??
    {
        if (memory(_ds, 0x6471) == 0x01)            //jz short locret_188E0
            goto locret_188F4;
    } else {
        if (memoryVideoGet(_ds, 0x6471) == 0x01)            //jz short locret_188E0
            goto locret_188F4;
    }
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _dx = 0x03ce;                               //mov dx, 3CEh
    _al = 0x08;                                 //mov al, 8
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _ax = _pop();                               //pop ax
    _out(_dx, _al);                             //out dx, al
    _dx = _pop();                               //pop dx
locret_188F4:                                   //locret_188F4:
    return;
}

void sub_18923()
{
    if (memory(_ds, 0x6471) == 0x01)            //jz short locret_18934
        goto locret_18934;
    _push(_dx);                                 //push dx
    _ah = _al;                                  //mov ah, al
    _dx = 0x03ce;                               //mov dx, 3CEh
    _al = 0x03;                                 //mov al, 3
    _out(_dx, _ax);                             //out dx, ax
    _dx = _pop();                               //pop dx
locret_18934:                                   //locret_18934:
    return;
}

void sub_18935()
{
    WORD _cs = _seg003;

    _push(_es);                                 //push es
    _ax = _cs;                                  //mov ax, cs
    _es = _ax;                                  //mov es, ax
    _dx = memory16(_cs, 0x5C6);                 //mov dx, cs:word_18956
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _di = 0x05c8;                               //mov di, 5C8h
    _cx = 0x0019;                               //mov cx, 19h
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_1894D:                                      //loc_1894D:
    _stosw<MemAuto, DirAuto>();                 //stosw
    _ax += _dx;                                 //add ax, dx
    if (--_cx)                                  //loop loc_1894D
        goto loc_1894D;
    _es = _pop();                               //pop es
}

void sub_189A1()
{
    WORD _cs = _seg003;

    _bh = _bh ^ _bh;                            //xor bh, bh
    _bl = _dh;                                  //mov bl, dh
    _cl = 0x03;                                 //mov cl, 3
    _bx >>= _cl;                                //shr bx, cl
    _bx <<= 1;                                  //shl bx, 1
    _di = memory16(_cs, _bx + 1480);            //mov di, cs:[bx+5C8h]
    _cl = _dh;                                  //mov cl, dh
    _cx &= 0x0007;                              //and cx, 7
    if (_cx == 0)                               //jz short loc_189BF
        goto loc_189BF;
loc_189B8:                                      //loc_189B8:
    _di = _di + memory16(_cs, 0x5C6);           //add di, cs:word_18956
    if (--_cx)                                  //loop loc_189B8
        goto loc_189B8;
loc_189BF:                                      //loc_189BF:
    _di = _di + memory16(_cs, 0x320);           //add di, cs:word_186B0
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bl = _dl;                                  //mov bl, dl
    _di += _bx;                                 //add di, bx
}

void sub_189F8()
{
    _push(_ds);                                 //push ds
    _ax = _seg002;                              //mov ax, seg seg002
    _ds = _ax;                                  //mov ds, ax
    sub_18935();                                //call sub_18935
    sub_1A9BB();                                //call sub_1A9BB
    sub_186B6();                                //call sub_186B6
    _ds = _pop();                               //pop ds
}

void sub_18A09()
{
    _push(_es);                                 //push es
    _ax = 0x0040;                               //mov ax, 40h
    _es = _ax;                                  //mov es, ax
    _bx = memoryBiosGet16(_es, 0x6C);                  //mov bx, es:6Ch
    _cx = _cx ^ _cx;                            //xor cx, cx
    _ax = 0x000a;                               //mov ax, 0Ah
loc_18A1B:                                      //loc_18A1B:
    //_STOP_("goto $+2");                         //jmp short $+2
loc_18A1D:                                      //loc_18A1D:
    if (--_cx)                                  //loop loc_18A1B
        goto loc_18A1B;
    _ax -= 1;                                   //dec ax
    if (_ax != 0)                               //jnz short loc_18A1B
        goto loc_18A1B;
    _ax = memoryBiosGet16(_es, 0x6C);                  //mov ax, es:6Ch
    _ax -= _bx;                                 //sub ax, bx
    _bx = 0x0053;                               //mov bx, 53h
    _xchg(_ax, _bx);                            //xchg ax, bx
    _dx = _dx ^ _dx;                            //xor dx, dx
    _div(_bx);                                  //div bx
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_18A3D
        goto loc_18A3D;
    memory16(_ds, 0x5E41) = 0x0001;             //mov word ptr ds:5E41h, 1
    goto loc_18A47;                             //jmp short loc_18A47
    _STOP_("db 90h");                           //db 90h
loc_18A3D:                                      //loc_18A3D:
    _bx = 0x0bb8;                               //mov bx, 0BB8h
    _dx = _dx ^ _dx;                            //xor dx, dx
    _mul(_bx);                                  //mul bx
    memory16(_ds, 0x5E41) = _ax;                //mov ds:5E41h, ax
loc_18A47:                                      //loc_18A47:
    _es = _pop();                               //pop es
}

void sub_18A49()
{
    memory(_ds, 0x42E6) = 0x01;                 //mov byte ptr ds:42E6h, 1
loc_18A4E:                                      //loc_18A4E:
    _bx = _bx ^ _bx;                            //xor bx, bx
    _bl = memory(_ds, 0x42E6);                  //mov bl, ds:42E6h
    _bx -= 1;                                   //dec bx
    _bx <<= 1;                                  //shl bx, 1
    _bp = _bx;                                  //mov bp, bx
    _dx = memory16(_ds, _bx + 24030);           //mov dx, [bx+5DDEh]
    _cx = 0x3e82;                               //mov cx, 3E82h
    memory16(_ds, 0x4610) = 0x0245;             //mov word ptr ds:4610h, 245h
    sub_1914B();                                //call sub_1914B
    _di = _di ^ _di;                            //xor di, di
    _dx = memory16(_ds, 0x5E04);                //mov dx, ds:5E04h
    _ax = memory16(_ds, _bp + 24048);           //mov ax, ds:[bp+5DF0h]
    _es = _ax;                                  //mov es, ax
    _si = 0x0247;                               //mov si, 247h
    sub_18A8D();                                //call sub_18A8D
    memory(_ds, 0x42E6) += 1;                   //inc byte ptr ds:42E6h
    _bx = _bx ^ _bx;                            //xor bx, bx
    _bl = memory(_ds, 0x42E6);                  //mov bl, ds:42E6h
    if ((short)_bx <= (short)memory16(_ds, 0x5E02))//jle short loc_18A4E
        goto loc_18A4E;
}

void sub_18A8D()
{
    _dx -= 0x0002;                              //sub dx, 2
loc_18A90:                                      //loc_18A90:
    _cx = 0x0001;                               //mov cx, 1
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _ah = 0xc0;                                 //mov ah, 0C0h
    _ah &= _al;                                 //and ah, al
    if (_ah != 0xc0)                            //jnz short loc_18AA5
        goto loc_18AA5;
    _ah = 0;                                    //sub ah, ah
    _al &= 0x3f;                                //and al, 3Fh
    _cx = _ax;                                  //mov cx, ax
    _dx -= 1;                                   //dec dx
    _lodsb<MemAuto, DirAuto>();                 //lodsb
loc_18AA5:                                      //loc_18AA5:
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    _dx -= 1;                                   //dec dx
    if (_dx != 0)                               //jnz short loc_18A90
        goto loc_18A90;
}

void sub_18AAB()
{
    _cx = _cx ^ _cx;                            //xor cx, cx
loc_18AAD:                                      //loc_18AAD:
    _al = _al ^ _al;                            //xor al, al
    _ah = 0x48;                                 //mov ah, 48h
    _bx = 0x03e8;                               //mov bx, 3E8h
    _interrupt(33);                             //int 21h
    if (_flags.carry)                           //jb short loc_18ACB
        goto loc_18ACB;
    _bx = _cx;                                  //mov bx, cx
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 24048) = _ax;           //mov [bx+5DF0h], ax
    _cx += 1;                                   //inc cx
    if (_cx != 0x0009)                          //jnz short loc_18AAD
        goto loc_18AAD;
    memory16(_ds, 0x5E02) = _cx;                //mov ds:5E02h, cx
    return;                                     //retn
loc_18ACB:                                      //loc_18ACB:
    if (_ax == 0x0008)                          //jz short loc_18AD6
        goto loc_18AD6;
    memory(_ds, 0x5D9D) = 0x01;                 //mov byte ptr ds:5D9Dh, 1
    return;                                     //retn
loc_18AD6:                                      //loc_18AD6:
    memory16(_ds, 0x5E02) = _cx;                //mov ds:5E02h, cx
    _bx = _cx;                                  //mov bx, cx
    _bp = _bx;                                  //mov bp, bx
    _bp <<= 1;                                  //shl bp, 1
    _bp = memory16(_ds, _bp + 25693);           //mov bp, ds:[bp+645Dh]
    _bx -= 1;                                   //dec bx
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _bx + 24048);           //mov ax, [bx+5DF0h]
    _dx = memory16(_ds, _bx + 24072);           //mov dx, [bx+5E08h]
loc_18AF0:                                      //loc_18AF0:
    _bx = _cx;                                  //mov bx, cx
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 24048) = _ax;           //mov [bx+5DF0h], ax
    memory16(_ds, _bx + 24072) = _dx;           //mov [bx+5E08h], dx
    memory16(_ds, _bx + 25693) = _bp;           //mov [bx+645Dh], bp
    _cx += 1;                                   //inc cx
    if (_cx != 0x0009)                          //jnz short loc_18AF0
        goto loc_18AF0;
    _bx = _cx;                                  //mov bx, cx
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 24072) = _dx;           //mov [bx+5E08h], dx
    memory16(_ds, _bx + 25693) = _bp;           //mov [bx+645Dh], bp
}

void sub_18B13()
{
    _cx = memory16(_ds, 0x5E02);                //mov cx, ds:5E02h
loc_18B17:                                      //loc_18B17:
    _bx = _cx;                                  //mov bx, cx
    _bx -= 1;                                   //dec bx
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _bx + 24048);           //mov ax, [bx+5DF0h]
    _es = _ax;                                  //mov es, ax
    _ah = 0x49;                                 //mov ah, 49h
    _interrupt(33);                             //int 21h
    _cx -= 1;                                   //dec cx
    if (_cx != 0)                               //jnz short loc_18B17
        goto loc_18B17;
}

void sub_18B2A()
{
    _di = 0x0247;                               //mov di, 247h
    _si = _si ^ _si;                            //xor si, si
    _cx = 0x1f40;                               //mov cx, 1F40h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
}

void sub_18B35()
{
    _dx = 0x0050;                               //mov dx, 50h
    _dl -= _bl;                                 //sub dl, bl
    _cx = _cx ^ _cx;                            //xor cx, cx
    _ah = _al;                                  //mov ah, al
loc_18B3E:                                      //loc_18B3E:
    _cl = _bl;                                  //mov cl, bl
    _flags.carry = _cx & 1;                     //shr cx, 1
    _cx >>= 1;
    if (!_flags.carry)                          //jnb short loc_18B45
        goto loc_18B45;
    _stosb<MemAuto, DirAuto>();                 //stosb
loc_18B45:                                      //loc_18B45:
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di += _dx;                                 //add di, dx
    _bh -= 1;                                   //dec bh
    if (_bh != 0)                               //jnz short loc_18B3E
        goto loc_18B3E;
}

void sub_18B4E()
{
    memory16(_es, _di) = _si;                   //mov es:[di], si
    _cx = _cx ^ _cx;                            //xor cx, cx
    _cl = _bl;                                  //mov cl, bl
    memory16(_es, _di + 2) = _cx;               //mov es:[di+2], cx
    _cl = _bh;                                  //mov cl, bh
    memory16(_es, _di + 4) = _cx;               //mov es:[di+4], cx
    _di += 0x0006;                              //add di, 6
    _dx = 0x0050;                               //mov dx, 50h
    _dl -= _bl;                                 //sub dl, bl
loc_18B67:                                      //loc_18B67:
    _cl = _bl;                                  //mov cl, bl
    _flags.carry = _cx & 1;                     //shr cx, 1
    _cx >>= 1;
    if (!_flags.carry)                          //jnb short loc_18B6E
        goto loc_18B6E;
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
loc_18B6E:                                      //loc_18B6E:
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _si += _dx;                                 //add si, dx
    _bh -= 1;                                   //dec bh
    if (_bh != 0)                               //jnz short loc_18B67
        goto loc_18B67;
}

void sub_18B77()
{
    // GABO
    std::cout << "unk carry\n";
    _dx = memory16(_ds, 0x4289);                //mov dx, ds:4289h
    _dx = _dx + 0x8249 + _flags.carry;//adc dx, 8249h
    _cx = memory16(_ds, 0x4289);                //mov cx, ds:4289h
    _cx &= 0x000f;
    _rcr(_dx, _cl);                             //rcr dx, cl
loc_18B89:                                      //loc_18B89:
    _cx = memory16(_ds, 0x4289);                //mov cx, ds:4289h
    _cx &= 0x1fff;                              //and cx, 1FFFh
    _dx += _cx;                                 //add dx, cx
    _ax = _dx;                                  //mov ax, dx
    _ax &= 0x001f;                              //and ax, 1Fh
    _cx = memory16(_ds, 0x4289);                //mov cx, ds:4289h
    _cx &= 0x001f;                              //and cx, 1Fh
    if (_cx != _ax)                             //jnz short loc_18BAD
        goto loc_18BAD;
    _cl &= 0x0f;                                //and cl, 0Fh
    _flags.carry = _cl & 1;                     //shr cl, 1
    _cl >>= 1;
    _rcl(_dx, _cl);                             //rcl dx, cl
    goto loc_18B89;                             //jmp short loc_18B89
loc_18BAD:                                      //loc_18BAD:
    memory16(_ds, 0x4289) = _dx;                //mov ds:4289h, dx
}

void sub_18BB2()
{
    WORD _cs = _seg003;

    _cx = _cx ^ _cx;                            //xor cx, cx
    _dx = 0x03bf;                               //mov dx, 3BFh
    _ax = 0x0003;                               //mov ax, 3
    _out(_dx, _ax);                             //out dx, ax
    _cl = memory(_cs, 0x1);                     //mov cl, cs:byte_18391
    _dx = 0x03b4;                               //mov dx, 3B4h
loc_18BC3:                                      //loc_18BC3:
    _di = _cx;                                  //mov di, cx
    _al = _cl;                                  //mov al, cl
    _al -= 1;                                   //dec al
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _al = memory(_cs, _di + 1);                 //mov al, cs:[di+1]
    _out(_dx, _al);                             //out dx, al
    _dx -= 1;                                   //dec dx
    if (--_cx)                                  //loop loc_18BC3
        goto loc_18BC3;
    _bx = _es;                                  //mov bx, es
    _di = _di ^ _di;                            //xor di, di
    _ax = _ax ^ _ax;                            //xor ax, ax
    _cx = 0xb000;                               //mov cx, 0B000h
    _es = _cx;                                  //mov es, cx
    _cx = 0x4000;                               //mov cx, 4000h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _es = _bx;                                  //mov es, bx
    _dx = 0x03b8;                               //mov dx, 3B8h
    _al = 0x0a;                                 //mov al, 0Ah
    _out(_dx, _al);                             //out dx, al
}

void sub_18BED()
{
    _push(_es);                                 //push es
    _push(_ds);                                 //push ds
    _ax = _seg002;                              //mov ax, seg seg002
    _ds = _ax;                                  //mov ds, ax
    _ax = 0xb000;                               //mov ax, 0B000h
    _es = _ax;                                  //mov es, ax
    _di = _di ^ _di;                            //xor di, di
    _si = memory16(_ds, 0x40C7);                //mov si, word_14197
    _bp = 0x0064;                               //mov bp, 64h
    _cx = _cx ^ _cx;                            //xor cx, cx
    _dl = 0x28;                                 //mov dl, 28h
    _bx = 0x0050;                               //mov bx, 50h
    _ax = 0x1fb0;                               //mov ax, 1FB0h
loc_18C0C:                                      //loc_18C0C:
    _cl = _dl;                                  //mov cl, dl
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _si -= _bx;                                 //sub si, bx
    _di += _ax;                                 //add di, ax
    _cl = _dl;                                  //mov cl, dl
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _di += _ax;                                 //add di, ax
    _cl = _dl;                                  //mov cl, dl
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _si -= _bx;                                 //sub si, bx
    _di += _ax;                                 //add di, ax
    _cl = _dl;                                  //mov cl, dl
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _di -= 0x6000;                              //sub di, 6000h
    _bp -= 1;                                   //dec bp
    if (_bp != 0)                               //jnz short loc_18C0C
        goto loc_18C0C;
    _ds = _pop();                               //pop ds
    _es = _pop();                               //pop es
}

void sub_18C30()
{
    _push(_bx);                                 //push bx
    memory(_ds, 0x428F) = 0x00;                 //mov byte ptr ds:428Fh, 0
    _ax = memory16(_ds, _di);                   //mov ax, [di]
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    memory16(_ds, 0x463F) = _ax;                //mov ds:463Fh, ax
    _bx = memory16(_ds, _di + 2);               //mov bx, [di+2]
    memory16(_ds, 0x4641) = _bx;                //mov ds:4641h, bx
    memory16(_ds, 0x463D) = _bx;                //mov ds:463Dh, bx
    _ax = memory16(_ds, 0x462D);                //mov ax, ds:462Dh
    if ((short)_ax >= (short)memory16(_ds, 0x4631))//jge short loc_18CAB
        goto loc_18CAB;
    if ((short)_ax <= (short)memory16(_ds, 0x4633))//jle short loc_18CAB
        goto loc_18CAB;
    _ax = memory16(_ds, 0x462F);                //mov ax, ds:462Fh
    if ((short)_ax >= (short)memory16(_ds, 0x4637))//jge short loc_18CAB
        goto loc_18CAB;
    if ((short)_ax <= (short)memory16(_ds, 0x4635))//jle short loc_18CAB
        goto loc_18CAB;
    _dx = _ax;                                  //mov dx, ax
    _cx = _bx;                                  //mov cx, bx
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_18C93
        goto loc_18C93;
    _bx = -_bx;                                 //neg bx
    if ((short)_ax <= (short)_bx)               //jle short loc_18CAB
        goto loc_18CAB;
    _bx = -_bx;                                 //neg bx
    _bx += _ax;                                 //add bx, ax
    memory16(_ds, 0x4641) = _bx;                //mov ds:4641h, bx
    _ax = -_ax;                                 //neg ax
    _cx = memory16(_ds, 0x463F);                //mov cx, ds:463Fh
    _mul(_cl);                                  //mul cl
    _si += _ax;                                 //add si, ax
    _bp += _ax;                                 //add bp, ax
    memory16(_ds, 0x463B) = 0x0000;             //mov word ptr ds:463Bh, 0
    goto loc_18CAD;                             //jmp short loc_18CAD
    _STOP_("db 90h");                           //db 90h
loc_18C93:                                      //loc_18C93:
    _dx += _cx;                                 //add dx, cx
    if ((short)_dx < (short)memory16(_ds, 0x4637))//jl short loc_18CA5
        goto loc_18CA5;
    _dx = _dx - memory16(_ds, 0x4637);          //sub dx, ds:4637h
    _cx -= _dx;                                 //sub cx, dx
    memory16(_ds, 0x4641) = _cx;                //mov ds:4641h, cx
loc_18CA5:                                      //loc_18CA5:
    memory16(_ds, 0x463B) = _ax;                //mov ds:463Bh, ax
    goto loc_18CAD;                             //jmp short loc_18CAD
    _STOP_("db 90h");                           //db 90h
loc_18CAB:                                      //loc_18CAB:
    _bx = _pop();                               //pop bx
    return;                                     //retn
loc_18CAD:                                      //loc_18CAD:
    _ax = memory16(_ds, 0x462D);                //mov ax, ds:462Dh
    _dx = _ax;                                  //mov dx, ax
    _cx = memory16(_ds, 0x463F);                //mov cx, ds:463Fh
    memory16(_ds, 0x463D) = _cx;                //mov ds:463Dh, cx
    _bx = _cx;                                  //mov bx, cx
    _ax |= _ax;                                 //or ax, ax
    if ((short)_ax >= 0)                        //jge short loc_18CDD
        goto loc_18CDD;
    _bx = -_bx;                                 //neg bx
    if ((short)_ax <= (short)_bx)               //jle short loc_18CAB
        goto loc_18CAB;
    _bx = -_bx;                                 //neg bx
    _bx += _ax;                                 //add bx, ax
    memory16(_ds, 0x463D) = _bx;                //mov ds:463Dh, bx
    _ax = -_ax;                                 //neg ax
    _si += _ax;                                 //add si, ax
    _bp += _ax;                                 //add bp, ax
    memory16(_ds, 0x4639) = 0x0000;             //mov word ptr ds:4639h, 0
    goto loc_18CF2;                             //jmp short loc_18CF2
    _STOP_("db 90h");                           //db 90h
loc_18CDD:                                      //loc_18CDD:
    _dx += _cx;                                 //add dx, cx
    if ((short)_dx < (short)memory16(_ds, 0x4631))//jl short loc_18CEF
        goto loc_18CEF;
    _dx = _dx - memory16(_ds, 0x4631);          //sub dx, ds:4631h
    _cx -= _dx;                                 //sub cx, dx
    memory16(_ds, 0x463D) = _cx;                //mov ds:463Dh, cx
loc_18CEF:                                      //loc_18CEF:
    memory16(_ds, 0x4639) = _ax;                //mov ds:4639h, ax
loc_18CF2:                                      //loc_18CF2:
    _cx = memory16(_ds, 0x463F);                //mov cx, ds:463Fh
    _cx = _cx - memory16(_ds, 0x463D);          //sub cx, ds:463Dh
    _di = memory16(_ds, 0x463B);                //mov di, ds:463Bh
    _di <<= 1;                                  //shl di, 1
    _di <<= 1;                                  //shl di, 1
    _di <<= 1;                                  //shl di, 1
    _di <<= 1;                                  //shl di, 1
    _bx = _di;                                  //mov bx, di
    _di <<= 1;                                  //shl di, 1
    _di <<= 1;                                  //shl di, 1
    _di += _bx;                                 //add di, bx
    _di = _di + memory16(_ds, 0x4639);          //add di, ds:4639h
    _di += 0x0247;                              //add di, 247h
    _bx = memory16(_ds, 0x463D);                //mov bx, ds:463Dh
    memory(_ds, 0x428F) = 0x01;                 //mov byte ptr ds:428Fh, 1
    _dx = 0x0050;                               //mov dx, 50h
    _dx -= _bx;                                 //sub dx, bx
    _bx = _pop();                               //pop bx
    sub_18DCF();                                //call sub_18DCF
    _bx = memory16(_ds, 0x463D);                //mov bx, ds:463Dh
    _ax = memory16(_ds, 0x4641);                //mov ax, ds:4641h
    _bh = _al;                                  //mov bh, al
loc_18D31:                                      //loc_18D31:
    _ah = _bl;                                  //mov ah, bl
loc_18D33:                                      //loc_18D33:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _al = _al & memory(_es, _di);               //and al, es:[di]
    _al = _al | memory(_ds, _bp + 0);           //or al, ds:[bp+0]
    _stosb<MemAuto, DirAuto>();                 //stosb
    _bp += 1;                                   //inc bp
    _ah -= 1;                                   //dec ah
    if (_ah != 0)                               //jnz short loc_18D33
        goto loc_18D33;
    _di += _dx;                                 //add di, dx
    _si += _cx;                                 //add si, cx
    _bp += _cx;                                 //add bp, cx
    _bh -= 1;                                   //dec bh
    if (_bh != 0)                               //jnz short loc_18D31
        goto loc_18D31;
}

void sub_18D4C()
{
    if (memory16(_ds, 0x5D13) != 0x0005)        //jnz short loc_18D56
        goto loc_18D56;
    goto loc_18DC3;                             //jmp short loc_18DC3
loc_18D56:                                      //loc_18D56:
    _ax = _ax ^ _ax;                            //xor ax, ax
    _cx = 0x0064;                               //mov cx, 64h
    _di = 0x41ba;                               //mov di, 41BAh
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    if (memory16(_ds, 0x5D13) != 0x0000)        //jnz short loc_18D6A
        goto loc_18D6A;
    goto loc_18DC3;                             //jmp short loc_18DC3
loc_18D6A:                                      //loc_18D6A:
    _bx = memory16(_ds, 0x5D13);                //mov bx, ds:5D13h
    _bx -= 1;                                   //dec bx
    _bl = memory(_ds, _bx + 23841);             //mov bl, [bx+5D21h]
    _di = 0x4278;                               //mov di, 4278h
    memory16(_ds, 0x4306) = _di;                //mov ds:4306h, di
    memory(_ds, 0x42E6) = _bl;                  //mov ds:42E6h, bl
loc_18D7E:                                      //loc_18D7E:
    memory(_ds, 0x5D12) = 0x00;                 //mov byte ptr ds:5D12h, 0
    //gabo?
    _flags.carry = false;
loc_18D83:                                      //loc_18D83:
    _di = memory16(_ds, 0x4306);                //mov di, ds:4306h
    sub_18B77();                                //call sub_18B77
    _ax &= 0x000f;                              //and ax, 0Fh
    if ((short)_ax <= (short)0x0009)            //jle short loc_18D95
        goto loc_18D95;
    _ax -= 0x0006;                              //sub ax, 6
loc_18D95:                                      //loc_18D95:
    _flags.carry = (_di + _ax) > 0x10000;
    _di += _ax;                                 //add di, ax
    if (memory(_ds, _di) != 0x00)               //jnz short loc_18D83
        goto loc_18D83;
    sub_1AB3E();                                //call sub_1AB3E
    _ax &= 0x0007;                              //and ax, 7
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_18DA7
        goto loc_18DA7;
    _ax += 1;                                   //inc ax
loc_18DA7:                                      //loc_18DA7:
    memory(_ds, _di) = _al;                     //mov [di], al
    memory(_ds, 0x5D12) += 1;                   //inc byte ptr ds:5D12h
    if (memory(_ds, 0x5D12) == 0x04)            //jz short loc_18DB6
        goto loc_18DB6;
    goto loc_18D83;                             //jmp short loc_18D83
loc_18DB6:                                      //loc_18DB6:
    memory16(_ds, 0x4306) -= 0x000a;            //sub word ptr ds:4306h, 0Ah
    memory(_ds, 0x42E6) -= 1;                   //dec byte ptr ds:42E6h
    if (memory(_ds, 0x42E6) == 0)               //jz short loc_18DC3
        goto loc_18DC3;
    goto loc_18D7E;                             //jmp short loc_18D7E
loc_18DC3:                                      //loc_18DC3:
    _si = 0x41ba;                               //mov si, 41BAh
    _di = 0x40f2;                               //mov di, 40F2h
    _cx = 0x0064;                               //mov cx, 64h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
}

void sub_18DCF()
{
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    memory16(_ds, _bx) = _di;                   //mov [bx], di
    _si = _di;                                  //mov si, di
    _di = _bx;                                  //mov di, bx
    _di += 0x0002;                              //add di, 2
    _ax = memory16(_ds, 0x463D);                //mov ax, ds:463Dh
    _bl = _al;                                  //mov bl, al
    _stosw<MemAuto, DirAuto>();                 //stosw
    _ax = memory16(_ds, 0x4641);                //mov ax, ds:4641h
    _bh = _al;                                  //mov bh, al
    _stosw<MemAuto, DirAuto>();                 //stosw
    _ch = _ch ^ _ch;                            //xor ch, ch
loc_18DE9:                                      //loc_18DE9:
    _cl = _bl;                                  //mov cl, bl
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _si += _dx;                                 //add si, dx
    _bh -= 1;                                   //dec bh
    if (_bh != 0)                               //jnz short loc_18DE9
        goto loc_18DE9;
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _cx = _pop();                               //pop cx
}

void sub_18DF7()
{
    memory16(_ds, 0x592E) = 0x0000;             //mov word ptr ds:592Eh, 0
    memory16(_ds, 0x5930) = 0x0000;             //mov word ptr ds:5930h, 0
    _si = 0x0247;                               //mov si, 247h
    _dx = _dx ^ _dx;                            //xor dx, dx
    _bx = 0xc850;                               //mov bx, 0C850h
    sub_19B30();                                //call sub_19B30
    sub_19A8B();                                //call sub_19A8B
    memory16(_ds, 0x4637) = 0x00c7;             //mov word ptr ds:4637h, 0C7h
    memory16(_ds, 0x4635) = 0x0000;             //mov word ptr ds:4635h, 0
    memory16(_ds, 0x4631) = 0x0050;             //mov word ptr ds:4631h, 50h
    memory16(_ds, 0x4633) = 0xffe3;             //mov word ptr ds:4633h, 0FFE3h
    memory(_ds, 0x42E6) = 0x59;                 //mov byte ptr ds:42E6h, 59h
    memory16(_ds, 0x42E2) = 0x0050;             //mov word ptr ds:42E2h, 50h
    memory16(_ds, 0x42E4) = 0x0041;             //mov word ptr ds:42E4h, 41h
loc_18E3A:                                      //loc_18E3A:
    sub_190C8();                                //call sub_190C8
    sub_19C06();                                //call sub_19C06
    sub_19BCA();                                //call sub_19BCA
    if (memory(_ds, 0x428F) != 0x01)            //jnz short loc_18E50
        goto loc_18E50;
    _si = 0x4fd0;                               //mov si, 4FD0h
    sub_190F6();                                //call sub_190F6
loc_18E50:                                      //loc_18E50:
    if (memory(_ds, 0xCF) == 0x00)              //jz short loc_18E5F
        goto loc_18E5F;
    sub_185AC();                                //call sub_185AC
    if (_ah != 0x00)                            //jnz short loc_18E62
        goto loc_18E62;
loc_18E5F:                                      //loc_18E5F:
    sub_19C18();                                //call sub_19C18
loc_18E62:                                      //loc_18E62:
    if (_ah != 0x1c)                            //jnz short loc_18E6A
        goto loc_18E6A;
    goto loc_1908F;                             //jmp loc_1908F
loc_18E6A:                                      //loc_18E6A:
    if (_ah != 0x10)                            //jnz short loc_18E75
        goto loc_18E75;
    memory(_ds, 0x5E39) = 0x01;                 //mov byte ptr ds:5E39h, 1
    return;                                     //retn
loc_18E75:                                      //loc_18E75:
    if (_ah != 0x1f)                            //jnz short loc_18E7F
        goto loc_18E7F;
    memory(_ds, 0x5D11) = memory(_ds, 0x5D11) ^ 0x01;//xor byte ptr ds:5D11h, 1
loc_18E7F:                                      //loc_18E7F:
    memory16(_ds, 0x42E2) -= 1;                 //dec word ptr ds:42E2h
    memory(_ds, 0x42E6) -= 1;                   //dec byte ptr ds:42E6h
    if (memory(_ds, 0x42E6) != 0)               //jnz short loc_18E3A
        goto loc_18E3A;
    memory(_ds, 0x42E6) = 0x0d;                 //mov byte ptr ds:42E6h, 0Dh
    _bp = 0x593a;                               //mov bp, 593Ah
    memory16(_ds, 0x4306) = 0x0000;             //mov word ptr ds:4306h, 0
loc_18E97:                                      //loc_18E97:
    _di = 0x3df7;                               //mov di, 3DF7h
    _cx = 0x0168;                               //mov cx, 168h
    _ax = 0xffff;                               //mov ax, 0FFFFh
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    memory16(_ds, 0x42E2) = 0x0001;             //mov word ptr ds:42E2h, 1
    memory16(_ds, 0x42E4) = 0x00bf;             //mov word ptr ds:42E4h, 0BFh
    sub_1AA67();                                //call sub_1AA67
    if (memory(_ds, 0x5E39) != 0x01)            //jnz short loc_18EB9
        goto loc_18EB9;
    return;                                     //retn
loc_18EB9:                                      //loc_18EB9:
    if (memory16(_ds, 0x4306) == 0x0000)        //jz short loc_18EC3
        goto loc_18EC3;
    goto loc_1908F;                             //jmp loc_1908F
loc_18EC3:                                      //loc_18EC3:
    if (memory(_ds, 0xCF) == 0x00)              //jz short loc_18ED2
        goto loc_18ED2;
    sub_185AC();                                //call sub_185AC
    if (_ah != 0x00)                            //jnz short loc_18ED5
        goto loc_18ED5;
loc_18ED2:                                      //loc_18ED2:
    sub_19C18();                                //call sub_19C18
loc_18ED5:                                      //loc_18ED5:
    if (_ah != 0x1c)                            //jnz short loc_18EDD
        goto loc_18EDD;
    goto loc_1908F;                             //jmp loc_1908F
loc_18EDD:                                      //loc_18EDD:
    if (_ah != 0x10)                            //jnz short loc_18EE8
        goto loc_18EE8;
    memory(_ds, 0x5E39) = 0x01;                 //mov byte ptr ds:5E39h, 1
    return;                                     //retn
loc_18EE8:                                      //loc_18EE8:
    if (_ah != 0x1f)                            //jnz short loc_18EF2
        goto loc_18EF2;
    memory(_ds, 0x5D11) = memory(_ds, 0x5D11) ^ 0x01;//xor byte ptr ds:5D11h, 1
loc_18EF2:                                      //loc_18EF2:
    if (memory(_ds, 0x42E6) == 0x01)            //jz short loc_18F04
        goto loc_18F04;
    _si = 0x3df7;                               //mov si, 3DF7h
    _di = 0x3b27;                               //mov di, 3B27h
    _cx = 0x0168;                               //mov cx, 168h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
loc_18F04:                                      //loc_18F04:
    memory(_ds, 0x42E6) -= 1;                   //dec byte ptr ds:42E6h
    if (memory(_ds, 0x42E6) != 0)               //jnz short loc_18E97
        goto loc_18E97;
    sub_19093();                                //call sub_19093
    _si = 0x2547;                               //mov si, 2547h
    memory16(_ds, 0x40CB) = _si;                //mov ds:40CBh, si
    memory16(_ds, 0x241) = 0x0c80;              //mov word ptr ds:241h, 0C80h
    memory(_ds, 0x42E6) = 0x0a;                 //mov byte ptr ds:42E6h, 0Ah
loc_18F1F:                                      //loc_18F1F:
    _flags.direction = true;                    //std
    _di = 0x40c6;                               //mov di, 40C6h
    _si = 0x3e46;                               //mov si, 3E46h
    _cx = memory16(_ds, 0x241);                 //mov cx, ds:241h
    _rep_movsw<MemAuto, MemAuto, DirBackward>();    //rep movsw
    _flags.direction = false;                   //cld
    _di = memory16(_ds, 0x40CB);                //mov di, ds:40CBh
    _cx = 0x0140;                               //mov cx, 140h
    _ax = _ax ^ _ax;                            //xor ax, ax
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    sub_19C06();                                //call sub_19C06
    _cx = 0x1000;                               //mov cx, 1000h
loc_18F3E:                                      //loc_18F3E:
    if (--_cx)                                  //loop loc_18F3E
        goto loc_18F3E;
    sub_19BCA();                                //call sub_19BCA
    memory16(_ds, 0x40CB) += 0x0280;            //add word ptr ds:40CBh, 280h
    memory16(_ds, 0x241) -= 0x0140;             //sub word ptr ds:241h, 140h
    memory(_ds, 0x42E6) -= 1;                   //dec byte ptr ds:42E6h
    if (memory(_ds, 0x42E6) != 0)               //jnz short loc_18F1F
        goto loc_18F1F;
    _di = memory16(_ds, 0x40CB);                //mov di, ds:40CBh
    _ax = _ax ^ _ax;                            //xor ax, ax
    _cx = 0x0140;                               //mov cx, 140h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    sub_19C06();                                //call sub_19C06
    sub_19BCA();                                //call sub_19BCA
    memory(_ds, 0x4286) = 0xbb;                 //mov byte ptr ds:4286h, 0BBh
    memory(_ds, 0x246) = 0x02;                  //mov byte ptr ds:246h, 2
    memory(_ds, 0x4284) = 0x28;                 //mov byte ptr ds:4284h, 28h
    memory(_ds, 0x245) = 0x26;                  //mov byte ptr ds:245h, 26h
    memory(_ds, 0x4287) = 0x0d;                 //mov byte ptr ds:4287h, 0Dh
    memory(_ds, 0x42E6) = 0x07;                 //mov byte ptr ds:42E6h, 7
    memory16(_ds, 0x241) = 0x0208;              //mov word ptr ds:241h, 208h
loc_18F8A:                                      //loc_18F8A:
    _bl = memory(_ds, 0x245);                   //mov bl, ds:245h
    _dh = memory(_ds, 0x4286);                  //mov dh, ds:4286h
    _dl = memory(_ds, 0x246);                   //mov dl, ds:246h
    _bh = memory(_ds, 0x4287);                  //mov bh, ds:4287h
    _si = 0x6818;                               //mov si, 6818h
    sub_19B30();                                //call sub_19B30
    _bh = memory(_ds, 0x4287);                  //mov bh, ds:4287h
    _dl = memory(_ds, 0x4284);                  //mov dl, ds:4284h
    _si = 0x6de2;                               //mov si, 6DE2h
    sub_19B30();                                //call sub_19B30
    sub_19C06();                                //call sub_19C06
    sub_19BCA();                                //call sub_19BCA
    if (memory(_ds, 0x42E6) == 0x01)            //jz short loc_18FE7
        goto loc_18FE7;
    _dh = memory(_ds, 0x4286);                  //mov dh, ds:4286h
    _dl = 0x02;                                 //mov dl, 2
    _bh = memory(_ds, 0x4287);                  //mov bh, ds:4287h
    _bl = 0x4c;                                 //mov bl, 4Ch
    sub_1A802();                                //call sub_1A802
    memory(_ds, 0x4286) -= 0x0d;                //sub byte ptr ds:4286h, 0Dh
    if (memory(_ds, 0x42E6) != 0x02)            //jnz short loc_18FDB
        goto loc_18FDB;
    memory(_ds, 0x4286) += 0x02;                //add byte ptr ds:4286h, 2
loc_18FDB:                                      //loc_18FDB:
    if ((char)memory(_ds, 0x42E6) <= (char)0x05)//jle short loc_18FE7
        goto loc_18FE7;
    memory(_ds, 0x4287) += 0x0d;                //add byte ptr ds:4287h, 0Dh
loc_18FE7:                                      //loc_18FE7:
    memory(_ds, 0x42E6) -= 1;                   //dec byte ptr ds:42E6h
    if (memory(_ds, 0x42E6) != 0)               //jnz short loc_18F8A
        goto loc_18F8A;
    sub_19093();                                //call sub_19093
loc_18FF0:                                      //loc_18FF0:
    memory(_ds, 0x42E6) = 0x75;                 //mov byte ptr ds:42E6h, 75h
    memory16(_ds, 0x42E2) = 0x0050;             //mov word ptr ds:42E2h, 50h
    memory16(_ds, 0x42E4) = 0x0041;             //mov word ptr ds:42E4h, 41h
    memory16(_ds, 0x44DE) = 0x0058;             //mov word ptr ds:44DEh, 58h
loc_19007:                                      //loc_19007:
    sub_190C8();                                //call sub_190C8
    _al = memory(_ds, 0x428F);                  //mov al, ds:428Fh
    memory(_ds, 0x4287) = _al;                  //mov ds:4287h, al
    sub_1909A();                                //call sub_1909A
    sub_19C06();                                //call sub_19C06
    sub_19BCA();                                //call sub_19BCA
    if (memory(_ds, 0x428F) != 0x01)            //jnz short loc_1902B
        goto loc_1902B;
    _si = 0x5107;                               //mov si, 5107h
    sub_190F6();                                //call sub_190F6
    _cx = 0x0064;                               //mov cx, 64h
loc_19029:                                      //loc_19029:
    if (--_cx)                                  //loop loc_19029
        goto loc_19029;
loc_1902B:                                      //loc_1902B:
    if (memory(_ds, 0x4287) != 0x01)            //jnz short loc_19038
        goto loc_19038;
    _si = 0x4fd0;                               //mov si, 4FD0h
    sub_190F6();                                //call sub_190F6
loc_19038:                                      //loc_19038:
    if (memory(_ds, 0xCF) == 0x00)              //jz short loc_19047
        goto loc_19047;
    sub_185AC();                                //call sub_185AC
    if (_ah != 0x00)                            //jnz short loc_1904A
        goto loc_1904A;
loc_19047:                                      //loc_19047:
    sub_19C18();                                //call sub_19C18
loc_1904A:                                      //loc_1904A:
    if (_ah != 0x1f)                            //jnz short loc_19054
        goto loc_19054;
    memory(_ds, 0x5D11) = memory(_ds, 0x5D11) ^ 0x01;//xor byte ptr ds:5D11h, 1
loc_19054:                                      //loc_19054:
    if (_ah != 0x10)                            //jnz short loc_1905F
        goto loc_1905F;
    memory(_ds, 0x5E39) = 0x01;                 //mov byte ptr ds:5E39h, 1
    return;                                     //retn
loc_1905F:                                      //loc_1905F:
    if (_ah == 0xff)                            //jz short loc_19067
        goto loc_19067;
    goto loc_1908F;                             //jmp short loc_1908F
    _STOP_("db 90h");                           //db 90h
loc_19067:                                      //loc_19067:
    memory16(_ds, 0x42E2) -= 1;                 //dec word ptr ds:42E2h
    memory16(_ds, 0x44DE) -= 1;                 //dec word ptr ds:44DEh
    memory(_ds, 0x42E6) -= 1;                   //dec byte ptr ds:42E6h
    if (memory(_ds, 0x42E6) != 0)               //jnz short loc_19007
        goto loc_19007;
    if (memory(_ds, 0xCF) == 0x00)              //jz short loc_19084
        goto loc_19084;
    sub_185AC();                                //call sub_185AC
    if (_ah != 0x00)                            //jnz short loc_19087
        goto loc_19087;
loc_19084:                                      //loc_19084:
    sub_19C18();                                //call sub_19C18
loc_19087:                                      //loc_19087:
    if (_ah != 0xff)                            //jnz short loc_1908F
        goto loc_1908F;
    goto loc_18FF0;                             //jmp loc_18FF0
loc_1908F:                                      //loc_1908F:
    sub_193C1();                                //call sub_193C1
}

void sub_19093()
{
    _dx = 0x7d00;                               //mov dx, 7D00h
loc_19096:                                      //loc_19096:
    _dx -= 1;                                   //dec dx
    if (_dx != 0)                               //jnz short loc_19096
        goto loc_19096;
}

void sub_1909A()
{
    _ax = memory16(_ds, 0x44DE);                //mov ax, ds:44DEh
    memory16(_ds, 0x462D) = _ax;                //mov ds:462Dh, ax
    _ax = memory16(_ds, 0x42E4);                //mov ax, ds:42E4h
    memory16(_ds, 0x462F) = _ax;                //mov ds:462Fh, ax
    _bx = memory16(_ds, 0x5930);                //mov bx, ds:5930h
    _bx = _bx ^ 0x0001;                         //xor bx, 1
    memory16(_ds, 0x5930) = _bx;                //mov ds:5930h, bx
    _bx <<= 1;                                  //shl bx, 1
    _di = memory16(_ds, _bx + 22834);           //mov di, [bx+5932h]
    _bp = memory16(_ds, _bx + 22838);           //mov bp, [bx+5936h]
    _si = _di;                                  //mov si, di
    _si += 0x0004;                              //add si, 4
    _bx = 0x5107;                               //mov bx, 5107h
    sub_18C30();                                //call sub_18C30
}

void sub_190C8()
{
    _ax = memory16(_ds, 0x42E2);                //mov ax, ds:42E2h
    memory16(_ds, 0x462D) = _ax;                //mov ds:462Dh, ax
    _ax = memory16(_ds, 0x42E4);                //mov ax, ds:42E4h
    memory16(_ds, 0x462F) = _ax;                //mov ds:462Fh, ax
    _bx = memory16(_ds, 0x592E);                //mov bx, ds:592Eh
    _bx = _bx ^ 0x0001;                         //xor bx, 1
    memory16(_ds, 0x592E) = _bx;                //mov ds:592Eh, bx
    _bx <<= 1;                                  //shl bx, 1
    _di = memory16(_ds, _bx + 22822);           //mov di, [bx+5926h]
    _bp = memory16(_ds, _bx + 22826);           //mov bp, [bx+592Ah]
    _si = _di;                                  //mov si, di
    _si += 0x0004;                              //add si, 4
    _bx = 0x4fd0;                               //mov bx, 4FD0h
    sub_18C30();                                //call sub_18C30
}

void sub_190F6()
{
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    _di = _ax;                                  //mov di, ax
    _dx = 0x0050;                               //mov dx, 50h
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    _dx -= _ax;                                 //sub dx, ax
    _bl = _al;                                  //mov bl, al
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    _bh = _al;                                  //mov bh, al
    _ch = _ch ^ _ch;                            //xor ch, ch
loc_19106:                                      //loc_19106:
    _cl = _bl;                                  //mov cl, bl
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di += _dx;                                 //add di, dx
    _bh -= 1;                                   //dec bh
    if (_bh != 0)                               //jnz short loc_19106
        goto loc_19106;
}

void sub_19111()
{
    WORD _cs = _seg003;

    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = 0xa000;                               //mov ax, 0A000h
    _es = _ax;                                  //mov es, ax
    _ds = _ax;                                  //mov ds, ax
    _di = _si;                                  //mov di, si
    _si += 0x3e80;                              //add si, 3E80h
    _di = _di + memory16(_cs, 0x320);           //add di, cs:word_186B0
    _push(_bx);                                 //push bx
    _bh = _bh ^ _bh;                            //xor bh, bh
    _dx = memory16(_cs, 0x5C6);                 //mov dx, cs:word_18956
    _dx -= _bx;                                 //sub dx, bx
    _al = 0x01;                                 //mov al, 1
    sub_188CD();                                //call sub_188CD
    _al = 0x0f;                                 //mov al, 0Fh
    sub_188E1();                                //call sub_188E1
    _bx = _pop();                               //pop bx
    _ch = _ch ^ _ch;                            //xor ch, ch
loc_1913C:                                      //loc_1913C:
    _cl = _bl;                                  //mov cl, bl
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _si += _dx;                                 //add si, dx
    _di += _dx;                                 //add di, dx
    _bh -= 1;                                   //dec bh
    if (_bh != 0)                               //jnz short loc_1913C
        goto loc_1913C;
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_1914B()
{
    _al = _al ^ _al;                            //xor al, al
    _ah = 0x3d;                                 //mov ah, 3Dh
    _interrupt(33);                             //int 21h
    memory16(_ds, 0x460E) = _ax;                //mov ds:460Eh, ax
    _bx = memory16(_ds, 0x460E);                //mov bx, ds:460Eh
    _dx = memory16(_ds, 0x4610);                //mov dx, ds:4610h
    _ah = 0x3f;                                 //mov ah, 3Fh
    _interrupt(33);                             //int 21h
    memory16(_ds, 0x5E04) = _ax;                //mov ds:5E04h, ax
    _bx = memory16(_ds, 0x460E);                //mov bx, ds:460Eh
    _ah = 0x3e;                                 //mov ah, 3Eh
    _interrupt(33);                             //int 21h
}

void sub_1916C()
{
    WORD _cs = _seg003;

    if (memory(_cs, 0x0) != 0x01)               //jnz short loc_19175
        goto loc_19175;
    return;                                     //retn
loc_19175:                                      //loc_19175:
    _dx = 0x03d8;                               //mov dx, 3D8h
    _al = 0x0e;                                 //mov al, 0Eh
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _al = 0x00;                                 //mov al, 0
    _out(_dx, _al);                             //out dx, al
}

void sub_1918B()
{
    if (memory(_ds, 0x5D11) != 0x01)            //jnz short loc_19193
        goto loc_19193;
    return;                                     //retn
loc_19193:                                      //loc_19193:
    _push(_bp);                                 //push bp
    _push(_bx);                                 //push bx
    _push(_dx);                                 //push dx
    _bx = memory16(_ds, _si);                   //mov bx, [si]
    _dx = memory16(_ds, _si + 2);               //mov dx, [si+2]
    _bp = memory16(_ds, _si + 4);               //mov bp, [si+4]
    _in(_al, 97);                               //in al, 61h
    _al &= 0xfe;                                //and al, 0FEh
loc_191A2:                                      //loc_191A2:
    _al |= 0x02;                                //or al, 2
    _out(97, _al);                              //out 61h, al
    _cx = _bx;                                  //mov cx, bx
loc_191A8:                                      //loc_191A8:
    if (--_cx)                                  //loop loc_191A8
        goto loc_191A8;
    _al &= 0xfd;                                //and al, 0FDh
    _out(97, _al);                              //out 61h, al
    _bx += _bp;                                 //add bx, bp
    _cx = _bx;                                  //mov cx, bx
loc_191B2:                                      //loc_191B2:
    if (--_cx)                                  //loop loc_191B2
        goto loc_191B2;
    _dx -= 1;                                   //dec dx
    if ((short)_dx >= 0)                        //jns short loc_191A2
        goto loc_191A2;
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
    _bp = _pop();                               //pop bp
}

void loc_191C4()
{
loc_191C4:
    if (--_cx)                                  //loop loc_191C4
        goto loc_191C4;
    _si = 0x45d6;                               //mov si, 45D6h
    sub_1918B();                                //call sub_1918B
    _di = 0x0585;                               //mov di, 585h
    memory16(_ds, 0x241) = _di;                 //mov ds:241h, di
    memory16(_ds, 0x4306) = 0x3735;             //mov word ptr ds:4306h, 3735h
    memory(_ds, 0x42E6) = 0x06;                 //mov byte ptr ds:42E6h, 6
loc_191DE:                                      //loc_191DE:
    _bx = 0x0002;                               //mov bx, 2
loc_191E1:                                      //loc_191E1:
    _ax = 0xffff;                               //mov ax, 0FFFFh
    _cx = 0x000a;                               //mov cx, 0Ah
    _di = memory16(_ds, 0x241);                 //mov di, ds:241h
    _si = _di;                                  //mov si, di
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _si += 0x0050;                              //add si, 50h
    _ax = 0x57d5;                               //mov ax, 57D5h
    _dx = 0x0006;                               //mov dx, 6
loc_191F8:                                      //loc_191F8:
    _cx = 0x000a;                               //mov cx, 0Ah
    _di = _si;                                  //mov di, si
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _si += 0x0050;                              //add si, 50h
    _dx -= 1;                                   //dec dx
    if (_dx != 0)                               //jnz short loc_191F8
        goto loc_191F8;
    _di = _si;                                  //mov di, si
    _ax = 0xffff;                               //mov ax, 0FFFFh
    _cx = 0x000a;                               //mov cx, 0Ah
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    memory16(_ds, 0x241) = _si;                 //mov ds:241h, si
    _bx -= 1;                                   //dec bx
    if (_bx == 0)                               //jz short loc_1921D
        goto loc_1921D;
    memory16(_ds, 0x241) += 0x0050;             //add word ptr ds:241h, 50h
    goto loc_191E1;                             //jmp short loc_191E1
loc_1921D:                                      //loc_1921D:
    _bx = 0x0002;                               //mov bx, 2
loc_19220:                                      //loc_19220:
    _ax = 0xffff;                               //mov ax, 0FFFFh
    _cx = 0x000a;                               //mov cx, 0Ah
    _di = memory16(_ds, 0x4306);                //mov di, ds:4306h
    _si = _di;                                  //mov si, di
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _si -= 0x0050;                              //sub si, 50h
    _ax = 0x57d5;                               //mov ax, 57D5h
    _dx = 0x0006;                               //mov dx, 6
loc_19237:                                      //loc_19237:
    _cx = 0x000a;                               //mov cx, 0Ah
    _di = _si;                                  //mov di, si
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _si -= 0x0050;                              //sub si, 50h
    _dx -= 1;                                   //dec dx
    if (_dx != 0)                               //jnz short loc_19237
        goto loc_19237;
    _di = _si;                                  //mov di, si
    _ax = 0xffff;                               //mov ax, 0FFFFh
    _cx = 0x000a;                               //mov cx, 0Ah
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    memory16(_ds, 0x4306) = _si;                //mov ds:4306h, si
    memory16(_ds, 0x4306) -= 0x0050;            //sub word ptr ds:4306h, 50h
    _bx -= 1;                                   //dec bx
    if (_bx == 0)                               //jz short loc_1925C
        goto loc_1925C;
    goto loc_19220;                             //jmp short loc_19220
loc_1925C:                                      //loc_1925C:
    memory(_ds, 0x42E6) -= 1;                   //dec byte ptr ds:42E6h
    if (memory(_ds, 0x42E6) == 0)               //jz short loc_19270
        goto loc_19270;
    sub_19C06();                                //call sub_19C06
    sub_19BCA();                                //call sub_19BCA
    memory16(_ds, 0x241) += 0x0050;             //add word ptr ds:241h, 50h
    goto loc_191DE;                             //jmp loc_191DE
loc_19270:                                      //loc_19270:
    _di = 0x1bb5;                               //mov di, 1BB5h
    _dx = 0x003c;                               //mov dx, 3Ch
    _ax = _ax ^ _ax;                            //xor ax, ax
    _bx = 0x000a;                               //mov bx, 0Ah
loc_1927B:                                      //loc_1927B:
    _cx = 0x000a;                               //mov cx, 0Ah
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di += _dx;                                 //add di, dx
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz short loc_1927B
        goto loc_1927B;
    memory16(_ds, 0x42E4) = 0x0052;             //mov word ptr ds:42E4h, 52h
    memory16(_ds, 0x42E2) = 0x001f;             //mov word ptr ds:42E2h, 1Fh
    _bp = 0x43d3;                               //mov bp, 43D3h
    memory16(_ds, 0x5D25) = 0xffff;             //mov word ptr ds:5D25h, 0FFFFh
    sub_1A947();                                //call sub_1A947
    sub_19C06();                                //call sub_19C06
    sub_19BCA();                                //call sub_19BCA
    sub_193B4();                                //call sub_193B4
}

void sub_192A7()
{
    WORD _cs = _seg003;

    _si = 0x45d0;                               //mov si, 45D0h
    sub_1918B();                                //call sub_1918B
    _cx = 0x0600;                               //mov cx, 600h
loc_192B0:                                      //loc_192B0:
    if (--_cx)                                  //loop loc_192B0
        goto loc_192B0;
    _si = 0x45d6;                               //mov si, 45D6h
    sub_1918B();                                //call sub_1918B
    _dl = 0x0f;                                 //mov dl, 0Fh
    _dh = 0x0a;                                 //mov dh, 0Ah
    _bl = 0x01;                                 //mov bl, 1
    _bh = 0x08;                                 //mov bh, 8
    memory16(_cs, 0x31C) = 0x000a;              //mov cs:word_186AC, 0Ah
loc_192C7:                                      //loc_192C7:
    _push(_bx);                                 //push bx
    _push(_dx);                                 //push dx
    _si = 0x5dc8;                               //mov si, 5DC8h
    sub_19B5C();                                //call sub_19B5C
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
    _dl += 1;                                   //inc dl
    memory16(_cs, 0x31C) -= 1;                  //dec cs:word_186AC
    if (memory16(_cs, 0x31C) != 0)              //jnz short loc_192C7
        goto loc_192C7;
    _push(_es);                                 //push es
    _push(_ds);                                 //push ds
    _ax = 0xa000;                               //mov ax, 0A000h
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _al = 0x01;                                 //mov al, 1
    sub_188CD();                                //call sub_188CD
    _al = 0x0f;                                 //mov al, 0Fh
    sub_188B9();                                //call sub_188B9
    _al = 0xff;                                 //mov al, 0FFh
    sub_188E1();                                //call sub_188E1
    _si = 0x019f;                               //mov si, 19Fh
    memory16(_cs, 0x324) = _si;                 //mov cs:word_186B4, si
    _di = 0x195f;                               //mov di, 195Fh
    memory16(_cs, 0x1022) = _di;                //mov cs:word_193B2, di
    _si = _si + memory16(_cs, 0x320);           //add si, cs:word_186B0
    _di = _di + memory16(_cs, 0x320);           //add di, cs:word_186B0
    _bx = 0x0008;                               //mov bx, 8
loc_19310:                                      //loc_19310:
    _cx = 0x000a;                               //mov cx, 0Ah
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _si += 0x001e;                              //add si, 1Eh
    _di += 0x001e;                              //add di, 1Eh
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz short loc_19310
        goto loc_19310;
    sub_18768();                                //call sub_18768
    memory16(_cs, 0x31C) = 0x0009;              //mov cs:word_186AC, 9
loc_19328:                                      //loc_19328:
    _si = memory16(_cs, 0x324);                 //mov si, cs:word_186B4
    _si = _si + memory16(_cs, 0x320);           //add si, cs:word_186B0
    _di = _si;                                  //mov di, si
    _di += 0x0140;                              //add di, 140h
    _bx = 0x0008;                               //mov bx, 8
loc_1933B:                                      //loc_1933B:
    _cx = 0x000a;                               //mov cx, 0Ah
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _si += 0x001e;                              //add si, 1Eh
    _di += 0x001e;                              //add di, 1Eh
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz short loc_1933B
        goto loc_1933B;
    _si = memory16(_cs, 0x1022);                //mov si, cs:word_193B2
    _si = _si + memory16(_cs, 0x320);           //add si, cs:word_186B0
    _di = _si;                                  //mov di, si
    _di -= 0x0140;                              //sub di, 140h
    _bx = 0x0008;                               //mov bx, 8
loc_1935C:                                      //loc_1935C:
    _cx = 0x000a;                               //mov cx, 0Ah
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _si += 0x001e;                              //add si, 1Eh
    _di += 0x001e;                              //add di, 1Eh
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz short loc_1935C
        goto loc_1935C;
    sub_18768();                                //call sub_18768
    memory16(_cs, 0x324) += 0x0140;             //add cs:word_186B4, 140h
    memory16(_cs, 0x1022) -= 0x0140;            //sub cs:word_193B2, 140h
    memory16(_cs, 0x31C) -= 1;                  //dec cs:word_186AC
    if (memory16(_cs, 0x31C) != 0)              //jnz short loc_19328
        goto loc_19328;
    _ds = _pop();                               //pop ds
    _es = _pop();                               //pop es
    _si = 0x0cdf;                               //mov si, 0CDFh
    _bx = 0x080a;                               //mov bx, 80Ah
    sub_19111();                                //call sub_19111
    memory16(_cs, 0x2018) = 0x0052;             //mov cs:word_1A3A8, 52h
    memory16(_cs, 0x2016) = 0x000f;             //mov cs:word_1A3A6, 0Fh
    _bp = 0x43d3;                               //mov bp, 43D3h
    memory(_cs, 0x201B) = 0x0f;                 //mov cs:byte_1A3AB, 0Fh
    sub_1A9D8();                                //call sub_1A9D8
    sub_18768();                                //call sub_18768
    sub_193B4();                                //call sub_193B4
    sub_1A699();                                //call sub_1A699
}

void sub_193B4()
{
    _dx = 0x005a;                               //mov dx, 5Ah
loc_193B7:                                      //loc_193B7:
    _ax = 0x1fff;                               //mov ax, 1FFFh
loc_193BA:                                      //loc_193BA:
    _ax -= 1;                                   //dec ax
    if (_ax != 0)                               //jnz short loc_193BA
        goto loc_193BA;
    _dx -= 1;                                   //dec dx
    if (_dx != 0)                               //jnz short loc_193B7
        goto loc_193B7;
}

void sub_193C1()
{
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = _seg002;                              //mov ax, seg seg002
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _cx = 0x1f40;                               //mov cx, 1F40h
    _ax = 0x0000;                               //mov ax, 0
    _di = 0x0247;                               //mov di, 247h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    memory16(_ds, 0x5D25) = 0xaaaa;             //mov word_15DF5, 0AAAAh
    _bp = 0x5aef;                               //mov bp, 5AEFh
    memory16(_ds, 0x42E2) = 0x0006;             //mov word_143B2, 6
    memory(_ds, 0x42E6) = 0x12;                 //mov byte_143B6, 12h
    memory16(_ds, 0x42E4) = 0x0018;             //mov word_143B4, 18h
loc_193EF:                                      //loc_193EF:
    sub_1A947();                                //call sub_1A947
    _push(_bp);                                 //push bp
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    sub_19C06();                                //call sub_19C06
    sub_19BCA();                                //call sub_19BCA
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = 0x45c4;                               //mov si, 45C4h
    sub_1918B();                                //call sub_1918B
    _bp = _pop();                               //pop bp
    memory16(_ds, 0x42E4) += 0x0008;            //add word ptr ds:42E4h, 8
    memory(_ds, 0x42E6) -= 1;                   //dec byte ptr ds:42E6h
    if (memory(_ds, 0x42E6) != 0)               //jnz short loc_193EF
        goto loc_193EF;
loc_1940F:                                      //loc_1940F:
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    sub_19C06();                                //call sub_19C06
    sub_19BCA();                                //call sub_19BCA
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    if (memory(_ds, 0xCF) == 0x00)              //jz short loc_19428
        goto loc_19428;
    sub_185AC();                                //call sub_185AC
    if (_ah != 0x00)                            //jnz short loc_1942B
        goto loc_1942B;
loc_19428:                                      //loc_19428:
    sub_19C18();                                //call sub_19C18
loc_1942B:                                      //loc_1942B:
    if (_ah != 0x1c)                            //jnz short loc_1940F
        goto loc_1940F;
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_19433()
{
    _dx = 0x5dda;                               //mov dx, 5DDAh
    _cx = 0x3e82;                               //mov cx, 3E82h
    memory16(_ds, 0x4610) = 0x0245;             //mov word ptr ds:4610h, 245h
    sub_1914B();                                //call sub_1914B
    sub_19645();                                //call sub_19645
loc_19445:                                      //loc_19445:
    sub_19C06();                                //call sub_19C06
    sub_19BCA();                                //call sub_19BCA
    if (memory(_ds, 0xCF) == 0x00)              //jz short loc_1945A
        goto loc_1945A;
    sub_185AC();                                //call sub_185AC
    if (_ah != 0x00)                            //jnz short loc_1945D
        goto loc_1945D;
loc_1945A:                                      //loc_1945A:
    sub_19C18();                                //call sub_19C18
loc_1945D:                                      //loc_1945D:
    if (_ah == 0xff)                            //jz short loc_19445
        goto loc_19445;
    if (_ah != 0x10)                            //jnz short loc_1946D
        goto loc_1946D;
    memory(_ds, 0x5E39) = 0x01;                 //mov byte ptr ds:5E39h, 1
    return;                                     //retn
loc_1946D:                                      //loc_1946D:
    if (_ah != 0x1f)                            //jnz short loc_19479
        goto loc_19479;
    memory(_ds, 0x5D11) = memory(_ds, 0x5D11) ^ 0x01;//xor byte ptr ds:5D11h, 1
    goto loc_19445;                             //jmp short loc_19445
loc_19479:                                      //loc_19479:
    if (_ah != 0x13)                            //jnz short loc_19483
        goto loc_19483;
    sub_1966E();                                //call sub_1966E
    goto loc_19445;                             //jmp short loc_19445
loc_19483:                                      //loc_19483:
    if (_ah != 0x01)                            //jnz short loc_19495
        goto loc_19495;
    sub_1A4C8();                                //call sub_1A4C8
    if (memory(_ds, 0x5E39) != 0x01)            //jnz short loc_19493
        goto loc_19493;
    return;                                     //retn
loc_19493:                                      //loc_19493:
    goto loc_19445;                             //jmp short loc_19445
loc_19495:                                      //loc_19495:
    memory(_ds, 0x245) = _ah;                   //mov ds:245h, ah
    sub_19645();                                //call sub_19645
    _ah = memory(_ds, 0x245);                   //mov ah, ds:245h
    if (_ah != 0x4b)                            //jnz short loc_194BC
        goto loc_194BC;
loc_194A5:                                      //loc_194A5:
    if ((short)memory16(_ds, 0x40C9) > (short)0x0000)//jg short loc_194B5
        goto loc_194B5;
    memory16(_ds, 0x40C9) = 0x0009;             //mov word ptr ds:40C9h, 9
    goto loc_1953A;                             //jmp loc_1953A
loc_194B5:                                      //loc_194B5:
    memory16(_ds, 0x40C9) -= 1;                 //dec word ptr ds:40C9h
    goto loc_1953A;                             //jmp short loc_1953A
loc_194BC:                                      //loc_194BC:
    if (_ah == 0x24)                            //jz short loc_194A5
        goto loc_194A5;
    if (_ah != 0x4d)                            //jnz short loc_194DD
        goto loc_194DD;
loc_194C6:                                      //loc_194C6:
    if ((short)memory16(_ds, 0x40C9) < (short)0x0009)//jl short loc_194D6
        goto loc_194D6;
    memory16(_ds, 0x40C9) = 0x0000;             //mov word ptr ds:40C9h, 0
    goto loc_1953A;                             //jmp short loc_1953A
loc_194D6:                                      //loc_194D6:
    memory16(_ds, 0x40C9) += 1;                 //inc word ptr ds:40C9h
    goto loc_1953A;                             //jmp short loc_1953A
    _STOP_("db 90h");                           //db 90h
loc_194DD:                                      //loc_194DD:
    if (_ah == 0x26)                            //jz short loc_194C6
        goto loc_194C6;
    if (_ah == 0x48)                            //jz short loc_194F1
        goto loc_194F1;
    if (_ah == 0x17)                            //jz short loc_194F1
        goto loc_194F1;
    if (_ah != 0x50)                            //jnz short loc_19505
        goto loc_19505;
loc_194F1:                                      //loc_194F1:
    _ax = memory16(_ds, 0x40C9);                //mov ax, ds:40C9h
    _ax -= 0x0005;                              //sub ax, 5
    if (!(_ax & 0x8000))                        //jz short loc_194FF
        goto loc_194FF;
    _ax += 0x000a;                              //add ax, 0Ah
loc_194FF:                                      //loc_194FF:
    memory16(_ds, 0x40C9) = _ax;                //mov ds:40C9h, ax
    goto loc_1953A;                             //jmp short loc_1953A
    _STOP_("db 90h");                           //db 90h
loc_19505:                                      //loc_19505:
    if (_ah == 0x32)                            //jz short loc_194F1
        goto loc_194F1;
    if (_ah != 0x0b)                            //jnz short loc_19518
        goto loc_19518;
    memory16(_ds, 0x40C9) = 0x0000;             //mov word ptr ds:40C9h, 0
    goto loc_1953A;                             //jmp short loc_1953A
loc_19518:                                      //loc_19518:
    if (_ah == 0x1c)                            //jz short loc_19540
        goto loc_19540;
    if (_ah == 0x39)                            //jz short loc_19540
        goto loc_19540;
    if ((char)_ah >= (char)0x02)                //jge short loc_1952A
        goto loc_1952A;
    goto loc_1953A;                             //jmp short loc_1953A
loc_1952A:                                      //loc_1952A:
    if ((char)_ah <= (char)0x0a)                //jle short loc_19532
        goto loc_19532;
    goto loc_1953A;                             //jmp short loc_1953A
loc_19532:                                      //loc_19532:
    _al = _ah;                                  //mov al, ah
    _ah = _ah ^ _ah;                            //xor ah, ah
    _ax -= 1;                                   //dec ax
    memory16(_ds, 0x40C9) = _ax;                //mov ds:40C9h, ax
loc_1953A:                                      //loc_1953A:
    sub_19645();                                //call sub_19645
    goto loc_19445;                             //jmp loc_19445
loc_19540:                                      //loc_19540:
    sub_19645();                                //call sub_19645
    sub_1961F();                                //call sub_1961F
loc_19546:                                      //loc_19546:
    sub_19C06();                                //call sub_19C06
    sub_19BCA();                                //call sub_19BCA
    if (memory(_ds, 0xCF) == 0x00)              //jz short loc_1955B
        goto loc_1955B;
    sub_185AC();                                //call sub_185AC
    if (_ah != 0x00)                            //jnz short loc_1955E
        goto loc_1955E;
loc_1955B:                                      //loc_1955B:
    sub_19C18();                                //call sub_19C18
loc_1955E:                                      //loc_1955E:
    if (_ah == 0xff)                            //jz short loc_19546
        goto loc_19546;
    if (_ah != 0x10)                            //jnz short loc_1956E
        goto loc_1956E;
    memory(_ds, 0x5E39) = 0x01;                 //mov byte ptr ds:5E39h, 1
    return;                                     //retn
loc_1956E:                                      //loc_1956E:
    if (_ah != 0x1f)                            //jnz short loc_1957A
        goto loc_1957A;
    memory(_ds, 0x5D11) = memory(_ds, 0x5D11) ^ 0x01;//xor byte ptr ds:5D11h, 1
    goto loc_19546;                             //jmp short loc_19546
loc_1957A:                                      //loc_1957A:
    if (_ah != 0x13)                            //jnz short loc_19584
        goto loc_19584;
    sub_1966E();                                //call sub_1966E
    goto loc_19546;                             //jmp short loc_19546
loc_19584:                                      //loc_19584:
    if (_ah != 0x01)                            //jnz short loc_19596
        goto loc_19596;
    sub_1A4C8();                                //call sub_1A4C8
    if (memory(_ds, 0x5E39) != 0x01)            //jnz short loc_19594
        goto loc_19594;
    return;                                     //retn
loc_19594:                                      //loc_19594:
    goto loc_19546;                             //jmp short loc_19546
loc_19596:                                      //loc_19596:
    memory(_ds, 0x245) = _ah;                   //mov ds:245h, ah
    sub_1961F();                                //call sub_1961F
    _ah = memory(_ds, 0x245);                   //mov ah, ds:245h
    if (_ah != 0x4b)                            //jnz short loc_195BD
        goto loc_195BD;
loc_195A6:                                      //loc_195A6:
    if ((short)memory16(_ds, 0x5D13) > (short)0x0000)//jg short loc_195B6
        goto loc_195B6;
    memory16(_ds, 0x5D13) = 0x0005;             //mov word ptr ds:5D13h, 5
    goto loc_19615;                             //jmp short loc_19615
loc_195B6:                                      //loc_195B6:
    memory16(_ds, 0x5D13) -= 1;                 //dec word ptr ds:5D13h
    goto loc_19615;                             //jmp short loc_19615
    _STOP_("db 90h");                           //db 90h
loc_195BD:                                      //loc_195BD:
    if (_ah == 0x24)                            //jz short loc_195A6
        goto loc_195A6;
    if (_ah != 0x4d)                            //jnz short loc_195DE
        goto loc_195DE;
loc_195C7:                                      //loc_195C7:
    if ((short)memory16(_ds, 0x5D13) < (short)0x0005)//jl short loc_195D7
        goto loc_195D7;
    memory16(_ds, 0x5D13) = 0x0000;             //mov word ptr ds:5D13h, 0
    goto loc_19615;                             //jmp short loc_19615
    _STOP_("db 90h");                           //db 90h
loc_195D7:                                      //loc_195D7:
    memory16(_ds, 0x5D13) += 1;                 //inc word ptr ds:5D13h
    goto loc_19615;                             //jmp short loc_19615
loc_195DE:                                      //loc_195DE:
    if (_ah == 0x26)                            //jz short loc_195C7
        goto loc_195C7;
    if (_ah == 0x48)                            //jz short loc_195F2
        goto loc_195F2;
    if (_ah == 0x17)                            //jz short loc_195F2
        goto loc_195F2;
    if (_ah != 0x50)                            //jnz short loc_19606
        goto loc_19606;
loc_195F2:                                      //loc_195F2:
    _ax = memory16(_ds, 0x5D13);                //mov ax, ds:5D13h
    _ax -= 0x0003;                              //sub ax, 3
    if (!(_ax & 0x8000))                        //jz short loc_19600
        goto loc_19600;
    _ax += 0x0006;                              //add ax, 6
loc_19600:                                      //loc_19600:
    memory16(_ds, 0x5D13) = _ax;                //mov ds:5D13h, ax
    goto loc_19615;                             //jmp short loc_19615
loc_19606:                                      //loc_19606:
    if (_ah == 0x32)                            //jz short loc_195F2
        goto loc_195F2;
    if (_ah == 0x1c)                            //jz short loc_1961B
        goto loc_1961B;
    if (_ah == 0x39)                            //jz short loc_1961B
        goto loc_1961B;
loc_19615:                                      //loc_19615:
    sub_1961F();                                //call sub_1961F
    goto loc_19546;                             //jmp loc_19546
loc_1961B:                                      //loc_1961B:
    sub_18D4C();                                //call sub_18D4C
}

void sub_1961F()
{
    _bx = memory16(_ds, 0x5D13);                //mov bx, ds:5D13h
    _bx <<= 1;                                  //shl bx, 1
    _di = memory16(_ds, _bx + 23829);           //mov di, [bx+5D15h]
    _bx = 0x0014;                               //mov bx, 14h
    _ax = 0xff3f;                               //mov ax, 0FF3Fh
loc_1962F:                                      //loc_1962F:
    memory16(_es, _di) = memory16(_es, _di) ^ _ax;//xor es:[di], ax
    memory(_es, _di + 0x2) = memory(_es, _di + 0x2) ^ 0xffff;
    memory(_es, _di + 0x4) = memory(_es, _di + 0x4) ^ 0xffff;
    _di += 0x0050;                              //add di, 50h
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz short loc_1962F
        goto loc_1962F;
}

void sub_19645()
{
    _bx = memory16(_ds, 0x40C9);                //mov bx, ds:40C9h
    _bx <<= 1;                                  //shl bx, 1
    _di = 0x0247;                               //mov di, 247h
    _di = _di + memory16(_ds, _bx + 17168);     //add di, [bx+4310h]
    _bx = 0x0014;                               //mov bx, 14h
    _ax = 0xff3f;                               //mov ax, 0FF3Fh
loc_19658:                                      //loc_19658:
    memory16(_es, _di) = memory16(_es, _di) ^ _ax;//xor es:[di], ax
    memory(_es, _di + 0x2) = memory(_es, _di + 0x2) ^ 0xffff;
    memory(_es, _di + 0x4) = memory(_es, _di + 0x4) ^ 0xffff;
    _di += 0x0050;                              //add di, 50h
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz short loc_19658
        goto loc_19658;
}

void sub_1966E()
{
    _di = 0x4643;                               //mov di, 4643h
    _si = 0x2823;                               //mov si, 2823h
    _bl = 0x38;                                 //mov bl, 38h
    _bh = 0x0f;                                 //mov bh, 0Fh
    sub_18B4E();                                //call sub_18B4E
    memory16(_ds, 0x5D25) = 0xffff;             //mov word ptr ds:5D25h, 0FFFFh
    _di = 0x2823;                               //mov di, 2823h
    _bl = 0x38;                                 //mov bl, 38h
    _bh = 0x0f;                                 //mov bh, 0Fh
    _al = _al ^ _al;                            //xor al, al
    sub_18B35();                                //call sub_18B35
    _di = 0x2873;                               //mov di, 2873h
    _bl = 0x38;                                 //mov bl, 38h
    _bh = 0x0d;                                 //mov bh, 0Dh
    nullsub_1();                                //call nullsub_1
    memory16(_ds, 0x42E2) = 0x000f;             //mov word ptr ds:42E2h, 0Fh
    memory16(_ds, 0x42E4) = 0x007c;             //mov word ptr ds:42E4h, 7Ch
    _bp = 0x5e1e;                               //mov bp, 5E1Eh
    sub_1A947();                                //call sub_1A947
loc_196A9:                                      //loc_196A9:
    sub_19C06();                                //call sub_19C06
    sub_19BCA();                                //call sub_19BCA
    sub_19C18();                                //call sub_19C18
    if (_ah != 0x31)                            //jnz short loc_196BA
        goto loc_196BA;
    goto loc_196F2;                             //jmp short loc_196F2
loc_196BA:                                      //loc_196BA:
    if (_ah == 0x15)                            //jz short loc_196C1
        goto loc_196C1;
    goto loc_196A9;                             //jmp short loc_196A9
loc_196C1:                                      //loc_196C1:
    _di = 0x44f0;                               //mov di, 44F0h
    _bx = 0x000a;                               //mov bx, 0Ah
loc_196C7:                                      //loc_196C7:
    _cx = 0x000f;                               //mov cx, 0Fh
    _si = 0x44e0;                               //mov si, 44E0h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _ax = _ax ^ _ax;                            //xor ax, ax
    _stosw<MemAuto, DirAuto>();                 //stosw
    _stosw<MemAuto, DirAuto>();                 //stosw
    _di += 1;                                   //inc di
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz short loc_196C7
        goto loc_196C7;
    _dx = 0x44d7;                               //mov dx, 44D7h
    _al = 0x02;                                 //mov al, 2
    _ah = 0x3d;                                 //mov ah, 3Dh
    _interrupt(33);                             //int 21h
    _bx = _ax;                                  //mov bx, ax
    _dx = 0x44ef;                               //mov dx, 44EFh
    _cx = 0x00c8;                               //mov cx, 0C8h
    _al = _al ^ _al;                            //xor al, al
    _ah = 0x40;                                 //mov ah, 40h
    _interrupt(33);                             //int 21h
    _ah = 0x3e;                                 //mov ah, 3Eh
    _interrupt(33);                             //int 21h
loc_196F2:                                      //loc_196F2:
    _si = 0x4643;                               //mov si, 4643h
    sub_190F6();                                //call sub_190F6
}

void sub_196F9()
{
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory(_ds, 0x5E3A) = _al;                  //mov ds:5E3Ah, al
    memory(_ds, 0x62EF) = _al;                  //mov ds:62EFh, al
    memory(_ds, 0x42E8) = _al;                  //mov ds:42E8h, al
    memory16(_ds, 0x140) = _ax;                 //mov ds:140h, ax
    memory16(_ds, 0x5D13) = _ax;                //mov ds:5D13h, ax
    memory16(_ds, 0x40E8) = _ax;                //mov ds:40E8h, ax
    memory16(_ds, 0x40F0) = _ax;                //mov ds:40F0h, ax
    memory16(_ds, 0x40C9) = 0x0005;             //mov word ptr ds:40C9h, 5
    _cx = 0x0007;                               //mov cx, 7
    _di = 0x40d3;                               //mov di, 40D3h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _cx = 0x0007;                               //mov cx, 7
    _di = 0x40e1;                               //mov di, 40E1h
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    memory(_ds, 0x4288) = _al;                  //mov ds:4288h, al
    memory16(_ds, 0x40CB) = _ax;                //mov ds:40CBh, ax
    memory(_ds, 0x5D10) = 0x00;                 //mov byte ptr ds:5D10h, 0
    memory(_ds, 0x5E06) = 0x00;                 //mov byte ptr ds:5E06h, 0
    memory(_ds, 0x5E07) = 0x00;                 //mov byte ptr ds:5E07h, 0
}

void sub_1973C()
{
    _dx = 0x44d7;                               //mov dx, 44D7h
    _al = _al ^ _al;                            //xor al, al
    _ah = 0x3d;                                 //mov ah, 3Dh
    _interrupt(33);                             //int 21h
    _bx = _ax;                                  //mov bx, ax
    _cx = 0x00c8;                               //mov cx, 0C8h
    _dx = 0x44ef;                               //mov dx, 44EFh
    _ah = 0x3f;                                 //mov ah, 3Fh
    _interrupt(33);                             //int 21h
    _ah = 0x3e;                                 //mov ah, 3Eh
    _interrupt(33);                             //int 21h
    memory16(_ds, 0x45B7) = 0x0000;             //mov word ptr ds:45B7h, 0
    sub_19C38();                                //call sub_19C38
    memory16(_ds, 0x5D25) = 0xaaaa;             //mov word ptr ds:5D25h, 0AAAAh
    memory16(_ds, 0x42E2) = 0x0018;             //mov word ptr ds:42E2h, 18h
    memory16(_ds, 0x42E4) = 0x0017;             //mov word ptr ds:42E4h, 17h
    _bp = 0x4402;                               //mov bp, 4402h
    sub_1A947();                                //call sub_1A947
    _di = 0x105d;                               //mov di, 105Dh
    _ax = 0xaaaa;                               //mov ax, 0AAAAh
    _cx = 0x0022;                               //mov cx, 22h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di = 0x3a3d;                               //mov di, 3A3Dh
    _cx = 0x0022;                               //mov cx, 22h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _ax = memory16(_ds, 0x40CB);                //mov ax, ds:40CBh
    memory16(_ds, 0x44DE) = _ax;                //mov ds:44DEh, ax
    _cx = 0x000a;                               //mov cx, 0Ah
    _si = 0x44ff;                               //mov si, 44FFh
loc_19795:                                      //loc_19795:
    if (_ax >= memory16(_ds, _si))              //jnb short loc_197A1
        goto loc_197A1;
    _si += 0x0014;                              //add si, 14h
    if (--_cx)                                  //loop loc_19795
        goto loc_19795;
    goto loc_197DB;                             //jmp short loc_197DB
    _STOP_("db 90h");                           //db 90h
loc_197A1:                                      //loc_197A1:
    _push(_si);                                 //push si
    _dl = 0x0a;                                 //mov dl, 0Ah
    _dl -= _cl;                                 //sub dl, cl
    memory(_ds, 0x45B9) = _dl;                  //mov ds:45B9h, dl
    _cx -= 1;                                   //dec cx
    if (_cx == 0)                               //jz short loc_197C3
        goto loc_197C3;
    _si = 0x45a2;                               //mov si, 45A2h
    _di = _si;                                  //mov di, si
    _di += 0x0014;                              //add di, 14h
loc_197B5:                                      //loc_197B5:
    _dl = 0x14;                                 //mov dl, 14h
loc_197B7:                                      //loc_197B7:
    _dh = memory(_ds, _si);                     //mov dh, [si]
    memory(_ds, _di) = _dh;                     //mov [di], dh
    _si -= 1;                                   //dec si
    _di -= 1;                                   //dec di
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_197B7
        goto loc_197B7;
    if (--_cx)                                  //loop loc_197B5
        goto loc_197B5;
loc_197C3:                                      //loc_197C3:
    _si = _pop();                               //pop si
    memory16(_ds, _si) = _ax;                   //mov [si], ax
    _cx = memory16(_ds, 0x40C9);                //mov cx, ds:40C9h
    memory16(_ds, _si + 2) = _cx;               //mov [si+2], cx
    _cx = 0x000f;                               //mov cx, 0Fh
    _dh = 0x20;                                 //mov dh, 20h
loc_197D2:                                      //loc_197D2:
    _si -= 1;                                   //dec si
    memory(_ds, _si) = _dh;                     //mov [si], dh
    if (--_cx)                                  //loop loc_197D2
        goto loc_197D2;
    memory16(_ds, 0x45B7) = _si;                //mov ds:45B7h, si
loc_197DB:                                      //loc_197DB:
    memory(_ds, 0x45BA) = 0x00;                 //mov byte ptr ds:45BAh, 0
    memory(_ds, 0x45BB) = 0x0e;                 //mov byte ptr ds:45BBh, 0Eh
    memory16(_es, 0x42E4) = 0x0037;             //mov word ptr es:42E4h, 37h
    _cx = 0x000a;                               //mov cx, 0Ah
    _bp = 0x44ef;                               //mov bp, 44EFh
loc_197F2:                                      //loc_197F2:
    _push(_cx);                                 //push cx
    memory16(_es, 0x42E2) = 0x000e;             //mov word ptr es:42E2h, 0Eh
    sub_1A947();                                //call sub_1A947
    _si = _bp;                                  //mov si, bp
    _bp += 0x0002;                              //add bp, 2
    _push(_bp);                                 //push bp
    _di = 0x40d3;                               //mov di, 40D3h
    _dl = 0x05;                                 //mov dl, 5
    _dh = 0x20;                                 //mov dh, 20h
loc_1980A:                                      //loc_1980A:
    _di -= 1;                                   //dec di
    memory(_ds, _di) = _dh;                     //mov [di], dh
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_1980A
        goto loc_1980A;
    memory16(_ds, 0x241) = 0x0005;              //mov word ptr ds:241h, 5
    sub_1A7D2();                                //call sub_1A7D2
    memory16(_es, 0x42E2) += 0x002e;            //add word ptr es:42E2h, 2Eh
    _bp = 0x40cd;                               //mov bp, 40CDh
    sub_1A947();                                //call sub_1A947
    _bp = _pop();                               //pop bp
    _si = _bp;                                  //mov si, bp
    _bp += 0x0002;                              //add bp, 2
    _push(_bp);                                 //push bp
    _di = 0x45bd;                               //mov di, 45BDh
    memory(_ds, _di) = 0x20;                    //mov byte ptr [di], 20h
    memory16(_ds, 0x241) = 0x0001;              //mov word ptr ds:241h, 1
    sub_1A7D2();                                //call sub_1A7D2
    memory16(_ds, 0x42E2) -= 0x0007;            //sub word ptr ds:42E2h, 7
    _bp = 0x45bc;                               //mov bp, 45BCh
    sub_1A947();                                //call sub_1A947
    memory16(_es, 0x42E4) += 0x000c;            //add word ptr es:42E4h, 0Ch
    _bp = _pop();                               //pop bp
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_197F2
        goto loc_197F2;
    memory16(_ds, 0x42E4) = 0x0037;             //mov word ptr ds:42E4h, 37h
    memory16(_ds, 0x42E2) = 0x0008;             //mov word ptr ds:42E2h, 8
    memory(_ds, 0x42E6) = 0x01;                 //mov byte ptr ds:42E6h, 1
    memory16(_ds, 0x241) = 0x0002;              //mov word ptr ds:241h, 2
loc_19868:                                      //loc_19868:
    _si = 0x42e6;                               //mov si, 42E6h
    _di = 0x44d4;                               //mov di, 44D4h
    sub_1A7D2();                                //call sub_1A7D2
    _bp = 0x44d3;                               //mov bp, 44D3h
    sub_1A947();                                //call sub_1A947
    memory16(_ds, 0x42E4) += 0x000c;            //add word ptr ds:42E4h, 0Ch
    memory(_ds, 0x42E6) += 1;                   //inc byte ptr ds:42E6h
    if (memory(_ds, 0x42E6) != 0x0b)            //jnz short loc_19868
        goto loc_19868;
loc_19887:                                      //loc_19887:
    memory16(_es, 0x42E4) = 0x0037;             //mov word ptr es:42E4h, 37h
    _cx = _cx ^ _cx;                            //xor cx, cx
    _cl = memory(_ds, 0x45B9);                  //mov cl, ds:45B9h
    _bp = 0x44ef;                               //mov bp, 44EFh
    memory16(_es, 0x42E2) = 0x000e;             //mov word ptr es:42E2h, 0Eh
    if (_cl == 0x00)                            //jz short loc_198AE
        goto loc_198AE;
loc_198A3:                                      //loc_198A3:
    _bp += 0x0014;                              //add bp, 14h
    memory16(_es, 0x42E4) += 0x000c;            //add word ptr es:42E4h, 0Ch
    if (--_cx)                                  //loop loc_198A3
        goto loc_198A3;
loc_198AE:                                      //loc_198AE:
    _ax = memory16(_es, 0x42E4);                //mov ax, es:42E4h
    _cl = 0x04;                                 //mov cl, 4
    _ax <<= _cl;                                //shl ax, cl
    _di = _ax;                                  //mov di, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _di = _di + memory16(_es, 0x42E2);          //add di, es:42E2h
    _di += 0x0247;                              //add di, 247h
    _bx = 0x0008;                               //mov bx, 8
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_198CC:                                      //loc_198CC:
    _cx = 0x0010;                               //mov cx, 10h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di += 0x0030;                              //add di, 30h
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz short loc_198CC
        goto loc_198CC;
    sub_1A947();                                //call sub_1A947
    if (memory16(_ds, 0x45B7) != 0x0000)        //jnz short loc_198E4
        goto loc_198E4;
    goto loc_19992;                             //jmp loc_19992
loc_198E4:                                      //loc_198E4:
    _ax = 0x0037;                               //mov ax, 37h
    _cx = _cx ^ _cx;                            //xor cx, cx
    _cl = memory(_ds, 0x45B9);                  //mov cl, ds:45B9h
    if (_cl == 0x00)                            //jz short loc_198F7
        goto loc_198F7;
loc_198F2:                                      //loc_198F2:
    _ax += 0x000c;                              //add ax, 0Ch
    if (--_cx)                                  //loop loc_198F2
        goto loc_198F2;
loc_198F7:                                      //loc_198F7:
    _cl = 0x04;                                 //mov cl, 4
    _dx = _dx ^ _dx;                            //xor dx, dx
    _dl = memory(_ds, 0x45BB);                  //mov dl, ds:45BBh
    _ax <<= _cl;                                //shl ax, cl
    _di = _ax;                                  //mov di, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _di += _dx;                                 //add di, dx
    _di += 0x0247;                              //add di, 247h
    _push(_di);                                 //push di
    _cx = 0x0008;                               //mov cx, 8
loc_19913:                                      //loc_19913:
    memory16(_es, _di) = memory16(_es, _di) ^ 0xffff;//xor word ptr es:[di], 0FFFFh
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_19913
        goto loc_19913;
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    sub_19C06();                                //call sub_19C06
    sub_19BCA();                                //call sub_19BCA
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _di = _pop();                               //pop di
    _cx = 0x0008;                               //mov cx, 8
loc_1992B:                                      //loc_1992B:
    memory16(_es, _di) = memory16(_es, _di) ^ 0xffff;//xor word ptr es:[di], 0FFFFh
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_1992B
        goto loc_1992B;
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    sub_19C06();                                //call sub_19C06
    sub_19BCA();                                //call sub_19BCA
    sub_19C18();                                //call sub_19C18
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = memory16(_ds, 0x45B7);                //mov si, ds:45B7h
    if (_ah == 0xff)                            //jz short loc_1996D
        goto loc_1996D;
    if (_ah == 0x4b)                            //jz short loc_19955
        goto loc_19955;
    if (_ah != 0x0e)                            //jnz short loc_19970
        goto loc_19970;
loc_19955:                                      //loc_19955:
    if (memory(_ds, 0x45BB) == 0x0e)            //jz short loc_1996D
        goto loc_1996D;
    _si -= 1;                                   //dec si
    memory(_ds, 0x45BA) -= 1;                   //dec byte ptr ds:45BAh
    memory(_ds, _si) = 0x20;                    //mov byte ptr [si], 20h
    memory(_ds, 0x45BB) -= 0x02;                //sub byte ptr ds:45BBh, 2
    memory16(_ds, 0x45B7) = _si;                //mov ds:45B7h, si
loc_1996D:                                      //loc_1996D:
    goto loc_19887;                             //jmp loc_19887
loc_19970:                                      //loc_19970:
    if (_ah == 0x1c)                            //jz short loc_19992
        goto loc_19992;
    if ((char)memory(_ds, 0x45BA) >= (char)0x0f)//jge short loc_1998F
        goto loc_1998F;
    memory(_ds, _si) = _al;                     //mov [si], al
    memory(_ds, 0x45BA) += 1;                   //inc byte ptr ds:45BAh
    _si += 1;                                   //inc si
    memory16(_ds, 0x45B7) = _si;                //mov ds:45B7h, si
    memory(_ds, 0x45BB) += 0x02;                //add byte ptr ds:45BBh, 2
    goto loc_19887;                             //jmp loc_19887
loc_1998F:                                      //loc_1998F:
    goto loc_198E4;                             //jmp loc_198E4
loc_19992:                                      //loc_19992:
    _dx = 0x44d7;                               //mov dx, 44D7h
    _al = 0x02;                                 //mov al, 2
    _ah = 0x3d;                                 //mov ah, 3Dh
    _interrupt(33);                             //int 21h
    _bx = _ax;                                  //mov bx, ax
    _dx = 0x44ef;                               //mov dx, 44EFh
    _cx = 0x00c8;                               //mov cx, 0C8h
    _al = _al ^ _al;                            //xor al, al
    _ah = 0x40;                                 //mov ah, 40h
    _interrupt(33);                             //int 21h
    _ah = 0x3e;                                 //mov ah, 3Eh
    _interrupt(33);                             //int 21h
}

void loc_199CA()
{
loc_199CA:
    _bx = _cx;                                  //mov bx, cx
    _si = _dx;                                  //mov si, dx
loc_199CE:                                      //loc_199CE:
    _push(_di);                                 //push di
    _push(_ax);                                 //push ax
loc_199D0:                                      //loc_199D0:
    _bp = memory16(_ds, _si);                   //mov bp, [si]
    memory16(_es, _di) &= _bp;                  //and es:[di], bp
    _di += 0x0002;                              //add di, 2
    _al -= 1;                                   //dec al
    if (_al == 0)                               //jz short loc_199DE
        goto loc_199DE;
    goto loc_199D0;                             //jmp short loc_199D0
loc_199DE:                                      //loc_199DE:
    _si += 0x0002;                              //add si, 2
    _ax = _pop();                               //pop ax
    _di = _pop();                               //pop di
    _di += 0x0050;                              //add di, 50h
    _bh -= 1;                                   //dec bh
    if (_bh != 0)                               //jnz short loc_199CE
        goto loc_199CE;
    _ah -= 1;                                   //dec ah
    if (_ah == 0)                               //jz short locret_199F0
        goto locret_199F0;
    goto loc_199CA;                             //jmp short loc_199CA
locret_199F0:                                   //locret_199F0:
    return;                                     //retn
    _push(_es);                                 //push es
    _bx = _bx ^ _bx;                            //xor bx, bx
    _es = _bx;                                  //mov es, bx
    _bx = memory16(_es, 0x41A);                 //mov bx, es:41Ah
    memory16(_es, 0x41C) = _bx;                 //mov es:41Ch, bx
    _es = _pop();                               //pop es
}

void sub_19A02()
{
    memory(_ds, 0x5D97) = 0x01;                 //mov byte ptr ds:5D97h, 1
    _ax = 0xb000;                               //mov ax, 0B000h
    _es = _ax;                                  //mov es, ax
    _ch = _ch ^ _ch;                            //xor ch, ch
    memory(_ds, 0x5D99) = 0x50;                 //mov byte ptr ds:5D99h, 50h
    memory16(_ds, 0x4610) = 0x02e6;             //mov word ptr ds:4610h, 2E6h
    memory16(_ds, 0x5D9A) = 0x004f;             //mov word ptr ds:5D9Ah, 4Fh
loc_19A1F:                                      //loc_19A1F:
    _bx = 0x0247;                               //mov bx, 247h
    _bp = memory16(_ds, 0x4610);                //mov bp, ds:4610h
    _di = memory16(_ds, 0x5D9A);                //mov di, ds:5D9Ah
    _ax = 0x4000;                               //mov ax, 4000h
    memory(_ds, 0x5D98) = 0x64;                 //mov byte ptr ds:5D98h, 64h
loc_19A32:                                      //loc_19A32:
    _push(_di);                                 //push di
    _push(_di);                                 //push di
    _si = _bx;                                  //mov si, bx
    _cl = memory(_ds, 0x5D97);                  //mov cl, ds:5D97h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _cl = memory(_ds, 0x5D97);                  //mov cl, ds:5D97h
    _si -= _cx;                                 //sub si, cx
    _di = _pop();                               //pop di
    _di += 0x2000;                              //add di, 2000h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _si = _bp;                                  //mov si, bp
    _di = _ax;                                  //mov di, ax
    _cl = memory(_ds, 0x5D97);                  //mov cl, ds:5D97h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _si = _bp;                                  //mov si, bp
    _di = _ax;                                  //mov di, ax
    _di += 0x2000;                              //add di, 2000h
    _cl = memory(_ds, 0x5D97);                  //mov cl, ds:5D97h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _bx += 0x00a0;                              //add bx, 0A0h
    _bp += 0x00a0;                              //add bp, 0A0h
    _di = _pop();                               //pop di
    _ax += 0x0050;                              //add ax, 50h
    _di += 0x0050;                              //add di, 50h
    memory(_ds, 0x5D98) -= 1;                   //dec byte ptr ds:5D98h
    if (memory(_ds, 0x5D98) != 0)               //jnz short loc_19A32
        goto loc_19A32;
    memory(_ds, 0x5D97) += 1;                   //inc byte ptr ds:5D97h
    memory(_ds, 0x5D99) -= 1;                   //dec byte ptr ds:5D99h
    if (memory(_ds, 0x5D99) == 0)               //jz short locret_19A8A
        goto locret_19A8A;
    memory16(_ds, 0x5D9A) -= 1;                 //dec word ptr ds:5D9Ah
    memory16(_ds, 0x4610) -= 1;                 //dec word ptr ds:4610h
    goto loc_19A1F;                             //jmp short loc_19A1F
locret_19A8A:                                   //locret_19A8A:
    return;
}

void sub_19A8B()
{
    WORD _cs = _seg003;

    _push(_es);                                 //push es
    if (memory(_cs, 0x0) != 0x01)               //jnz short loc_19A99
        goto loc_19A99;
    sub_19A02();                                //call sub_19A02
    _es = _pop();                               //pop es
    return;                                     //retn
loc_19A99:                                      //loc_19A99:
    memory(_ds, 0x5D97) = 0x01;                 //mov byte ptr ds:5D97h, 1
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _ch = _ch ^ _ch;                            //xor ch, ch
    memory(_ds, 0x5D99) = 0x50;                 //mov byte ptr ds:5D99h, 50h
    memory16(_ds, 0x4610) = 0x02e6;             //mov word ptr ds:4610h, 2E6h
    memory16(_ds, 0x5D9A) = 0x004f;             //mov word ptr ds:5D9Ah, 4Fh
loc_19AB6:                                      //loc_19AB6:
    _bx = 0x0247;                               //mov bx, 247h
    _bp = memory16(_ds, 0x4610);                //mov bp, ds:4610h
    _di = memory16(_ds, 0x5D9A);                //mov di, ds:5D9Ah
    _ax = 0x2000;                               //mov ax, 2000h
    memory(_ds, 0x5D98) = 0x64;                 //mov byte ptr ds:5D98h, 64h
loc_19AC9:                                      //loc_19AC9:
    _push(_di);                                 //push di
    _si = _bx;                                  //mov si, bx
    _cl = memory(_ds, 0x5D97);                  //mov cl, ds:5D97h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _si = _bp;                                  //mov si, bp
    _di = _ax;                                  //mov di, ax
    _cl = memory(_ds, 0x5D97);                  //mov cl, ds:5D97h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _bx += 0x00a0;                              //add bx, 0A0h
    _bp += 0x00a0;                              //add bp, 0A0h
    _di = _pop();                               //pop di
    _ax += 0x0050;                              //add ax, 50h
    _di += 0x0050;                              //add di, 50h
    memory(_ds, 0x5D98) -= 1;                   //dec byte ptr ds:5D98h
    if (memory(_ds, 0x5D98) != 0)               //jnz short loc_19AC9
        goto loc_19AC9;
    memory(_ds, 0x5D97) += 1;                   //inc byte ptr ds:5D97h
    memory(_ds, 0x5D99) -= 1;                   //dec byte ptr ds:5D99h
    if (memory(_ds, 0x5D99) == 0)               //jz short loc_19B05
        goto loc_19B05;
    memory16(_ds, 0x5D9A) -= 1;                 //dec word ptr ds:5D9Ah
    memory16(_ds, 0x4610) -= 1;                 //dec word ptr ds:4610h
    goto loc_19AB6;                             //jmp short loc_19AB6
loc_19B05:                                      //loc_19B05:
    _es = _pop();                               //pop es
}

void loc_19B26()
{
loc_19B26:
    _cx = _bx;                                  //mov cx, bx
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di += _dx;                                 //add di, dx
    _ax -= 1;                                   //dec ax
    if (_ax != 0)                               //jnz short loc_19B26
        goto loc_19B26;
}

void sub_19B30()
{
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = _dl;                                  //mov al, dl
    _di = _ax;                                  //mov di, ax
    _al = _dh;                                  //mov al, dh
    _cl = 0x04;                                 //mov cl, 4
    _ax <<= _cl;                                //shl ax, cl
    _di += _ax;                                 //add di, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _di += 0x0247;                              //add di, 247h
    _cx = _cx ^ _cx;                            //xor cx, cx
    _cl = _bl;                                  //mov cl, bl
    _bp = 0x0050;                               //mov bp, 50h
    _bp -= _cx;                                 //sub bp, cx
loc_19B51:                                      //loc_19B51:
    _cl = _bl;                                  //mov cl, bl
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di += _bp;                                 //add di, bp
    _bh -= 1;                                   //dec bh
    if (_bh != 0)                               //jnz short loc_19B51
        goto loc_19B51;
}

void sub_19B5C()
{
    WORD _cs = _seg003;

    _push(_es);                                 //push es
    _push(_ds);                                 //push ds
    _ax = 0xa000;                               //mov ax, 0A000h
    _es = _ax;                                  //mov es, ax
    _ds = _ax;                                  //mov ds, ax
    _push(_bx);                                 //push bx
    sub_189A1();                                //call sub_189A1
    _al = 0x01;                                 //mov al, 1
    sub_188CD();                                //call sub_188CD
    _al = 0xff;                                 //mov al, 0FFh
    sub_188E1();                                //call sub_188E1
    _al = 0x0f;                                 //mov al, 0Fh
    sub_188B9();                                //call sub_188B9
    _bx = _pop();                               //pop bx
    _dx = memory16(_cs, 0x5C6);                 //mov dx, cs:word_18956
    _ch = _ch ^ _ch;                            //xor ch, ch
    _cl = _bl;                                  //mov cl, bl
    _dx -= _cx;                                 //sub dx, cx
loc_19B84:                                      //loc_19B84:
    _cl = _bl;                                  //mov cl, bl
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di += _dx;                                 //add di, dx
    _bh -= 1;                                   //dec bh
    if (_bh != 0)                               //jnz short loc_19B84
        goto loc_19B84;
    _ds = _pop();                               //pop ds
    _es = _pop();                               //pop es
}

void loc_19BBD()
{
loc_19BBD:
    _cl = _bl;                                  //mov cl, bl
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di += _dx;                                 //add di, dx
    _bh -= 1;                                   //dec bh
    if (_bh != 0)                               //jnz short loc_19BBD
        goto loc_19BBD;
    _ds = _pop();                               //pop ds
    _es = _pop();                               //pop es
}

void sub_19BCA()
{
    WORD _cs = _seg003;

    _push(_es);                                 //push es
    if (memory(_cs, 0x0) != 0x01)               //jnz short loc_19BD8
        goto loc_19BD8;
    sub_18BED();                                //call sub_18BED
    _es = _pop();                               //pop es
    return;                                     //retn
loc_19BD8:                                      //loc_19BD8:
    _dx = _ds;                                  //mov dx, ds
    _ax = _seg002;                              //mov ax, seg seg002
    _ds = _ax;                                  //mov ds, ax
    _si = 0x0247;                               //mov si, 247h
    _di = _di ^ _di;                            //xor di, di
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _bp = 0x0028;                               //mov bp, 28h
    _bx = 0x0064;                               //mov bx, 64h
loc_19BEF:                                      //loc_19BEF:
    _cx = _bp;                                  //mov cx, bp
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _cx = _bp;                                  //mov cx, bp
    _di += 0x1fb0;                              //add di, 1FB0h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _di -= 0x2000;                              //sub di, 2000h
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz short loc_19BEF
        goto loc_19BEF;
    _ds = _dx;                                  //mov ds, dx
    _es = _pop();                               //pop es
}

void sub_19C06()
{
    if (memory16(_ds, 0x5E41) == 0x0001)        //jz short locret_19C17
        goto locret_19C17;
    _cx = memory16(_ds, 0x5E41);                //mov cx, ds:5E41h
loc_19C13:                                      //loc_19C13:
    _STOP_("goto $+2");                         //jmp short $+2
loc_19C15:                                      //loc_19C15:
    if (--_cx)                                  //loop loc_19C13
        goto loc_19C13;
locret_19C17:                                   //locret_19C17:
    return;
}

void sub_19C18()
{
    _sync();
    _push(_es);                                 //push es
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(22);                             //int 16h
    if (!_flags.zero)                           //jnz short loc_19C24
        goto loc_19C24;
    _ah = 0xff;                                 //mov ah, 0FFh
    goto loc_19C28;                             //jmp short loc_19C28
loc_19C24:                                      //loc_19C24:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _interrupt(22);                             //int 16h
loc_19C28:                                      //loc_19C28:
    _bx = _bx ^ _bx;                            //xor bx, bx
    _es = _bx;                                  //mov es, bx
    //gabo
//    _bx = memory16(_es, 0x41A);                 //mov bx, es:41Ah
//    memory16(_es, 0x41C) = _bx;                 //mov es:41Ch, bx
    _es = _pop();                               //pop es
}

void sub_19C38()
{
    _cx = 0x1f40;                               //mov cx, 1F40h
    _ax = _ax ^ _ax;                            //xor ax, ax
    _di = 0x0247;                               //mov di, 247h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
}

void sub_19C43()
{
    _push(_es);                                 //push es
    _ax = 0x0040;                               //mov ax, 40h
    _es = _ax;                                  //mov es, ax
    if (memoryBiosGet(_es, 0x17) & 0x20)               //jnz short loc_19C57
        goto loc_19C57;
    memoryBiosSet(_es, 0x17, memoryBiosGet(_es, 0x17) | 0x20);                  //or byte ptr es:17h, 20h
loc_19C57:                                      //loc_19C57:
    _es = _pop();                               //pop es
}

void sub_19C59()
{
    WORD _cs = _seg003;

    _ax = 0x000d;                               //mov ax, 0Dh
    _interrupt(16);                             //int 10h
    sub_189F8();                                //call sub_189F8
    memory16(_cs, 0x31E) = 0x0000;              //mov cs:word_186AE, 0
    memory16(_cs, 0x320) = 0x3e80;              //mov cs:word_186B0, 3E80h
    _push(_es);                                 //push es
    _si = 0xa000;                               //mov si, 0A000h
    _es = _si;                                  //mov es, si
    _bx = memory16(_ds, 0x40C9);                //mov bx, ds:40C9h
    _bx <<= 1;                                  //shl bx, 1
    _si = memory16(_cs, _bx + 693);             //mov si, cs:[bx+2B5h]
    memory16(_cs, 0x31A) = _si;                 //mov cs:word_186AA, si
    _si = 0x0247;                               //mov si, 247h
    _bp = 0x3e80;                               //mov bp, 3E80h
    memory16(_cs, 0x31C) = 0x1f40;              //mov cs:word_186AC, 1F40h
    // draw background
    sub_1880D();                                //call sub_1880D
    _push(_ds);                                 //push ds
    _al = 0x01;                                 //mov al, 1
    sub_188CD();                                //call sub_188CD
    _al = 0x0f;                                 //mov al, 0Fh
    sub_188B9();                                //call sub_188B9
    _al = 0xff;                                 //mov al, 0FFh
    sub_188E1();                                //call sub_188E1
    _si = 0xa000;                               //mov si, 0A000h
    _ds = _si;                                  //mov ds, si
    _di = memory16(_cs, 0x31C);                 //mov di, cs:word_186AC
    _si = memory16(_cs, 0x320);                 //mov si, cs:word_186B0
    _cx = memory16(_cs, 0x31C);                 //mov cx, cs:word_186AC
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _ds = _pop();                               //pop ds
    _es = _pop();                               //pop es
    memory16(_cs, 0x320) = 0x1f40;              //mov cs:word_186B0, 1F40h
    memory(_cs, 0x201B) = 0x0f;                 //mov cs:byte_1A3AB, 0Fh
    sub_1A042();                                //call sub_1A042
    sub_18B77();                                //call sub_18B77
    sub_1AB3E();                                //call sub_1AB3E
    _ax = _ax + memory16(_ds, 0x4289);          //add ax, ds:4289h
    _ax &= 0x0007;                              //and ax, 7
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_19CE0
        goto loc_19CE0;
    _ax += 1;                                   //inc ax
loc_19CE0:                                      //loc_19CE0:
    _bx = _bx ^ _bx;                            //xor bx, bx
    memory(_ds, 0x4283) = _bl;                  //mov ds:4283h, bl
    memory(_ds, 0x4282) = 0x03;                 //mov byte ptr ds:4282h, 3
    memory(_ds, 0x4285) = _bl;                  //mov ds:4285h, bl
    memory(_ds, 0x42A4) = _bl;                  //mov ds:42A4h, bl
    memory(_ds, 0x42E1) = _bl;                  //mov ds:42E1h, bl
    memory(_ds, 0x244) = _bl;                   //mov ds:244h, bl
    memory(_ds, 0x142) = _bl;                   //mov ds:142h, bl
    memory16(_ds, 0x428B) = _ax;                //mov ds:428Bh, ax
    _ax -= 1;                                   //dec ax
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 16595) += 1;            //inc word ptr [bx+40D3h]
    memory16(_ds, 0x40F0) += 1;                 //inc word ptr ds:40F0h
    sub_1A34A();                                //call sub_1A34A
    if (memory(_ds, 0x5E07) == 0x00)            //jz short loc_19D1C
        goto loc_19D1C;
    sub_1A11B();                                //call sub_1A11B
loc_19D1C:                                      //loc_19D1C:
    memory(_ds, 0x243) = 0x01;                  //mov byte ptr ds:243h, 1
    sub_18B77();                                //call sub_18B77
    sub_1AB3E();                                //call sub_1AB3E
    _ax = _ax + memory16(_ds, 0x4289);          //add ax, ds:4289h
    _ax &= 0x0007;                              //and ax, 7
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_19D33
        goto loc_19D33;
    _ax += 1;                                   //inc ax
loc_19D33:                                      //loc_19D33:
    sub_1A3AC();                                //call sub_1A3AC
    memory16(_ds, 0x428D) = _ax;                //mov ds:428Dh, ax
    _si = 0x04df;                               //mov si, 4DFh
    _bx = 0x1004;                               //mov bx, 1004h
    sub_19111();                                //call sub_19111
    if (memory(_ds, 0x42E8) == 0x00)            //jz short loc_19D4C
        goto loc_19D4C;
    sub_1A322();                                //call sub_1A322
loc_19D4C:                                      //loc_19D4C:
    _al = memory(_ds, 0x142);                   //mov al, ds:142h
    _al |= _al;                                 //or al, al
    if (_al != 0)                               //jnz short loc_19D56
        goto loc_19D56;
    sub_1AF58();                                //call sub_1AF58
loc_19D56:                                      //loc_19D56:
    sub_1AF7C();                                //call sub_1AF7C
    _bp = memory16(_ds, 0x42A6);                //mov bp, ds:42A6h
    _al = memory(_ds, _bp + 0);                 //mov al, ds:[bp+0]
    _ah = memory(_ds, _bp + 1);                 //mov ah, ds:[bp+1]
    _bp += 0x0002;                              //add bp, 2
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bl = memory(_ds, 0x4282);                  //mov bl, ds:4282h
    _bl = memory(_ds, _bx + 17064);             //mov bl, [bx+42A8h]
    _di = _bx;                                  //mov di, bx
    _bl = memory(_ds, 0x4283);                  //mov bl, ds:4283h
    _bx <<= 1;                                  //shl bx, 1
    _di = _di + memory16(_ds, _bx + 17074);     //add di, [bx+42B2h]
    sub_1AD03();                                //call sub_1AD03
    sub_18768();                                //call sub_18768
    _bp = memory16(_ds, 0x42A6);                //mov bp, ds:42A6h
    _al = memory(_ds, _bp + 0);                 //mov al, ds:[bp+0]
    _ah = memory(_ds, _bp + 1);                 //mov ah, ds:[bp+1]
    _bp += 0x0002;                              //add bp, 2
    if (memory(_ds, 0x4283) != 0x00)            //jnz short loc_19DE4
        goto loc_19DE4;
    if (memory(_ds, 0x4282) != 0x03)            //jnz short loc_19DE4
        goto loc_19DE4;
    _bx = _bp;                                  //mov bx, bp
    if (_ah == 0x01)                            //jz short loc_19DAA
        goto loc_19DAA;
    _bl += _al;                                 //add bl, al
loc_19DAA:                                      //loc_19DAA:
    _dx = 0x40f5;                               //mov dx, 40F5h
    _ch = _ah;                                  //mov ch, ah
loc_19DAF:                                      //loc_19DAF:
    _ch -= 1;                                   //dec ch
    _ch |= _ch;                                 //or ch, ch
    if (_ch == 0)                               //jz short loc_19DBA
        goto loc_19DBA;
    _dx += 0x000a;                              //add dx, 0Ah
    goto loc_19DAF;                             //jmp short loc_19DAF
loc_19DBA:                                      //loc_19DBA:
    _ch = _ah;                                  //mov ch, ah
loc_19DBC:                                      //loc_19DBC:
    _di = _dx;                                  //mov di, dx
    _si = _bx;                                  //mov si, bx
    _cl = _al;                                  //mov cl, al
loc_19DC2:                                      //loc_19DC2:
    if (memory(_es, _di) == 0x00)               //jz short loc_19DD5
        goto loc_19DD5;
    if (memory(_ds, _si) == 0x00)               //jz short loc_19DD5
        goto loc_19DD5;
    memory(_ds, 0x5D10) = 0x01;                 //mov byte ptr ds:5D10h, 1
    goto loc_19FB7;                             //jmp loc_19FB7
loc_19DD5:                                      //loc_19DD5:
    _di += 1;                                   //inc di
    _si += 1;                                   //inc si
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_19DC2
        goto loc_19DC2;
    _dx -= 0x000a;                              //sub dx, 0Ah
    _bl -= _al;                                 //sub bl, al
    _ch -= 1;                                   //dec ch
    if (_ch != 0)                               //jnz short loc_19DBC
        goto loc_19DBC;
loc_19DE4:                                      //loc_19DE4:
    _di = memory16(_ds, 0x4306);                //mov di, ds:4306h
    sub_1AD03();                                //call sub_1AD03
    if (memory(_ds, 0x428F) != 0x01)            //jnz short loc_19E0A
        goto loc_19E0A;
    memory(_ds, 0x42E1) += 1;                   //inc byte ptr ds:42E1h
    if ((char)memory(_ds, 0x42E1) <= (char)0x07)//jle short loc_19E0A
        goto loc_19E0A;
    memory(_ds, 0x42E1) = 0x00;                 //mov byte ptr ds:42E1h, 0
    memory(_ds, 0x42A4) = 0x00;                 //mov byte ptr ds:42A4h, 0
    goto loc_19F89;                             //jmp loc_19F89
loc_19E0A:                                      //loc_19E0A:
    _ah = memory(_ds, 0x4283);                  //mov ah, ds:4283h
    memory(_ds, 0x4284) = _ah;                  //mov ds:4284h, ah
    sub_19C43();                                //call sub_19C43
    if (memory(_ds, 0xCF) == 0x00)              //jz short loc_19E24
        goto loc_19E24;
    sub_185AC();                                //call sub_185AC
    if (_ah != 0x00)                            //jnz short loc_19E29
        goto loc_19E29;
loc_19E24:                                      //loc_19E24:
    sub_1A3DE();                                //call sub_1A3DE
    if (!_flags.carry)                                //jnb short loc_19E3F
        goto loc_19E3F;
loc_19E29:                                      //loc_19E29:
    _al = _ah;                                  //mov al, ah
    _di = 0x5ccb;                               //mov di, 5CCBh
    _cx = 0x0018;                               //mov cx, 18h
    _repne_scasb();                             //repne scasb
    if (_cx == 0)                               //jcxz short loc_19E3F
        goto loc_19E3F;
    _di -= 0x5ccc;                              //sub di, 5CCCh
    _di <<= 1;                                  //shl di, 1
    {
        switch (_indirectCall(_cs, memory16(_ds, _di + 23778)))
        {
            case 0x19F23: goto loc_19F23;
            case 0x19F89: goto loc_19F89;
            default:
                assert(0);
        }
        return;
    }
loc_19E3F:                                      //loc_19E3F:
    goto loc_19F50;                             //jmp loc_19F50
    sub_1ABFC();                                //call sub_1ABFC
    goto loc_19F23;                             //jmp loc_19F23
    sub_1ADF9();                                //call sub_1ADF9
    goto loc_19F23;                             //jmp loc_19F23
    sub_1AE5E();                                //call sub_1AE5E
    goto loc_19F23;                             //jmp loc_19F23
    memory(_ds, 0x5D11) = memory(_ds, 0x5D11) ^ 0x01;//xor byte ptr ds:5D11h, 1
    goto loc_19F50;                             //jmp loc_19F50
    memory(_ds, 0x5E06) = memory(_ds, 0x5E06) ^ 0x01;//xor byte ptr ds:5E06h, 1
    if (memory(_ds, 0x5E06) == 0x00)            //jz short loc_19E6E
        goto loc_19E6E;
    sub_1A10C();                                //call sub_1A10C
    goto loc_19F50;                             //jmp loc_19F50
loc_19E6E:                                      //loc_19E6E:
    _si = 0x0e60;                               //mov si, 0E60h
    _bx = 0x5f0d;                               //mov bx, 5F0Dh
    sub_19111();                                //call sub_19111
    goto loc_19F50;                             //jmp loc_19F50
    memory(_ds, 0x5E07) = memory(_ds, 0x5E07) ^ 0x01;//xor byte ptr ds:5E07h, 1
    if (memory(_ds, 0x5E07) == 0x00)            //jz short loc_19E8C
        goto loc_19E8C;
    sub_1A114();                                //call sub_1A114
    goto loc_19F50;                             //jmp loc_19F50
loc_19E8C:                                      //loc_19E8C:
    _si = 0x0e7c;                               //mov si, 0E7Ch
    _bx = 0x5e0b;                               //mov bx, 5E0Bh
    sub_19111();                                //call sub_19111
    goto loc_19F50;                             //jmp loc_19F50
    memory(_ds, 0x5E3A) = memory(_ds, 0x5E3A) ^ 0x01;//xor byte ptr ds:5E3Ah, 1
    if (memory(_ds, 0x5E3A) == 0x00)            //jz short loc_19EAA
        goto loc_19EAA;
    sub_1A108();                                //call sub_1A108
    goto loc_19F50;                             //jmp loc_19F50
loc_19EAA:                                      //loc_19EAA:
    _si = 0x00e6;                               //mov si, 0E6h
    _bx = 0x2507;                               //mov bx, 2507h
    sub_19111();                                //call sub_19111
    goto loc_19F50;                             //jmp loc_19F50
    memory(_ds, 0x62EF) = memory(_ds, 0x62EF) ^ 0x01;//xor byte ptr ds:62EFh, 1
    if (memory(_ds, 0x62EF) == 0x00)            //jz short loc_19EC8
        goto loc_19EC8;
    sub_1A110();                                //call sub_1A110
    goto loc_19F50;                             //jmp loc_19F50
loc_19EC8:                                      //loc_19EC8:
    _si = 0x1dd8;                               //mov si, 1DD8h
    _bx = 0x0928;                               //mov bx, 928h
    sub_19111();                                //call sub_19111
    goto loc_19F50;                             //jmp short loc_19F50
    if ((short)memory16(_ds, 0x40C9) >= (short)0x0009)
        goto loc_19EEE;
    sub_1A069();                                //call sub_1A069
    sub_1A34A();                                //call sub_1A34A
    sub_1A042();                                //call sub_1A042
    if (memory(_ds, 0x42E8) == 0x00)            //jz short loc_19EEE
        goto loc_19EEE;
    sub_1A322();                                //call sub_1A322
loc_19EEE:                                      //loc_19EEE:
    goto loc_19F23;                             //jmp short loc_19F23
    _STOP_("db 90h");                           //db 90h
    sub_1A63C();                                //call sub_1A63C
    if (memory(_ds, 0x5E39) != 0x01)            //jnz short loc_19EFC
        goto loc_19EFC;
    return;                                     //retn
loc_19EFC:                                      //loc_19EFC:
    goto loc_19F50;                             //jmp short loc_19F50
    _STOP_("db 90h");                           //db 90h
    memory(_ds, 0x42E8) = memory(_ds, 0x42E8) ^ 0x01;//xor byte ptr ds:42E8h, 1
    if (memory(_ds, 0x42E8) == 0x00)            //jz short loc_19F11
        goto loc_19F11;
    sub_1A322();                                //call sub_1A322
    goto loc_19F1A;                             //jmp short loc_19F1A
    _STOP_("db 90h");                           //db 90h
loc_19F11:                                      //loc_19F11:
    _si = 0x04df;                               //mov si, 4DFh
    _bx = 0x1004;                               //mov bx, 1004h
    sub_19111();                                //call sub_19111
loc_19F1A:                                      //loc_19F1A:
    goto loc_19F50;                             //jmp short loc_19F50
    _STOP_("db 90h");                           //db 90h
    sub_1AF12();                                //call sub_1AF12
    goto loc_19F89;                             //jmp short loc_19F89
    _STOP_("db 90h");                           //db 90h
loc_19F23:                                      //loc_19F23:
    memory(_ds, 0x244) += 1;                    //inc byte ptr ds:244h
    if ((char)memory(_ds, 0x244) <= (char)0x05) //jle short loc_19F50
        goto loc_19F50;
    if (memory(_ds, 0x142) != 0x00)             //jnz short loc_19F38
        goto loc_19F38;
    sub_1AF58();                                //call sub_1AF58
loc_19F38:                                      //loc_19F38:
    sub_1AF7C();                                //call sub_1AF7C
    if (memory(_ds, 0x428F) == 0x01)            //jz short loc_19F57
        goto loc_19F57;
    memory(_ds, 0x4283) += 1;                   //inc byte ptr ds:4283h
    memory(_ds, 0x244) = 0x00;                  //mov byte ptr ds:244h, 0
    memory(_ds, 0x42A4) = 0x00;                 //mov byte ptr ds:42A4h, 0
loc_19F50:                                      //loc_19F50:
    if (memory(_ds, 0x428F) != 0x01)            //jnz short loc_19F5E
        goto loc_19F5E;
loc_19F57:                                      //loc_19F57:
    memory(_ds, 0x42A4) += 1;                   //inc byte ptr ds:42A4h
    goto loc_19D4C;                             //jmp loc_19D4C
loc_19F5E:                                      //loc_19F5E:
    if (memory(_ds, 0x142) != 0x00)             //jnz short loc_19F68
        goto loc_19F68;
    sub_1AF58();                                //call sub_1AF58
loc_19F68:                                      //loc_19F68:
    sub_1AF7C();                                //call sub_1AF7C
    if (memory(_ds, 0x428F) == 0x01)            //jz short loc_19F75
        goto loc_19F75;
    sub_1AF23();                                //call sub_1AF23
loc_19F75:                                      //loc_19F75:
    goto loc_19D4C;                             //jmp loc_19D4C
    _STOP_("db 32h, 0E4h, 0CDh, 16h, 80h, 0FCh, 19h, 7...");
    _STOP_("db 0CDh, 0C6h, 6, 39h, 5Eh, 1, 0C3h");//db 0CDh, 0C6h, 6, 39h, 5Eh, 1, 0C3h
loc_19F89:                                      //loc_19F89:
    _bp = memory16(_ds, 0x42A6);                //mov bp, ds:42A6h
    _al = memory(_ds, _bp + 0);                 //mov al, ds:[bp+0]
    _ah = memory(_ds, _bp + 1);                 //mov ah, ds:[bp+1]
    _bp += 0x0002;                              //add bp, 2
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bl = memory(_ds, 0x4282);                  //mov bl, ds:4282h
    _bl = memory(_ds, _bx + 17064);             //mov bl, [bx+42A8h]
    _di = _bx;                                  //mov di, bx
    _bl = memory(_ds, 0x4283);                  //mov bl, ds:4283h
    _bx <<= 1;                                  //shl bx, 1
    _di = _di + memory16(_ds, _bx + 17074);     //add di, [bx+42B2h]
    sub_1AD03();                                //call sub_1AD03
    memory16(_ds, 0x140) = memory16(_ds, 0x140) ^ 0x0001;
loc_19FB7:                                      //loc_19FB7:
    if (memory16(_ds, 0x40CB) < 0xff14)         //jb short loc_19FC8
        goto loc_19FC8;
    memory16(_ds, 0x40CB) = 0xff14;             //mov word ptr ds:40CBh, 0FF14h
    goto loc_19FED;                             //jmp short loc_19FED
loc_19FC8:                                      //loc_19FC8:
    _bx = memory16(_ds, 0x40C9);                //mov bx, ds:40C9h
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _bx + 17138);           //mov ax, [bx+42F2h]
    _bx = _bx ^ _bx;                            //xor bx, bx
    _bl = memory(_ds, 0x4284);                  //mov bl, ds:4284h
    _ax -= _bx;                                 //sub ax, bx
    if (memory(_ds, 0x42E8) == 0x00)            //jz short loc_19FE9
        goto loc_19FE9;
    _ax >>= 1;                                  //shr ax, 1
    memory16(_ds, 0x40CB) += _ax;               //add ds:40CBh, ax
    _ax >>= 1;                                  //shr ax, 1
loc_19FE9:                                      //loc_19FE9:
    memory16(_ds, 0x40CB) += _ax;               //add ds:40CBh, ax
loc_19FED:                                      //loc_19FED:
    if (memory(_ds, 0x5D10) != 0x01)            //jnz short loc_19FFD
        goto loc_19FFD;
    sub_1A34A();                                //call sub_1A34A
    sub_18768();                                //call sub_18768
    goto locret_1A041;                          //jmp short locret_1A041
    _STOP_("db 90h");                           //db 90h
loc_19FFD:                                      //loc_19FFD:
    sub_1AD74();                                //call sub_1AD74
    sub_1AB61();                                //call sub_1AB61
    sub_1A34A();                                //call sub_1A34A
    sub_18768();                                //call sub_18768
    if (memory16(_ds, 0x4604) == 0x0000)        //jz short loc_1A019
        goto loc_1A019;
    sub_1A40E();                                //call sub_1A40E
    sub_1A042();                                //call sub_1A042
    sub_18768();                                //call sub_18768
loc_1A019:                                      //loc_1A019:
    _bx = memory16(_ds, 0x40C9);                //mov bx, ds:40C9h
    _ax = memory16(_ds, 0x40E8);                //mov ax, ds:40E8h
    _bl = memory(_ds, _bx + 17129);             //mov bl, [bx+42E9h]
    if ((short)_ax < (short)_bx)                //jl short loc_1A03B
        goto loc_1A03B;
    if ((short)memory16(_ds, 0x40C9) >= (short)0x0009)
        goto loc_1A03B;
    sub_1A069();                                //call sub_1A069
    sub_1A042();                                //call sub_1A042
    _si = 0x45ca;                               //mov si, 45CAh
    sub_1918B();                                //call sub_1918B
loc_1A03B:                                      //loc_1A03B:
    _ax = memory16(_ds, 0x428D);                //mov ax, ds:428Dh
    goto loc_19CE0;                             //jmp loc_19CE0
locret_1A041:                                   //locret_1A041:
    return;
}

void sub_1A042()
{
    _ax = 0x140a;                               //mov ax, 140Ah
    _dx = 0x0a0f;                               //mov dx, 0A0Fh
    _bp = 0x40f2;                               //mov bp, 40F2h
    sub_1ACAE();                                //call sub_1ACAE
}

void sub_1A069()
{
    WORD _cs = _seg003;

    memory16(_ds, 0x40C9) += 1;                 //inc word ptr ds:40C9h
    _bx = memory16(_ds, 0x40C9);                //mov bx, ds:40C9h
    if ((short)_bx <= (short)memory16(_ds, 0x5E02))//jle short loc_1A084
        goto loc_1A084;
    if (memory(_ds, 0x5E3A) != 0x01)            //jnz short loc_1A081
        goto loc_1A081;
    sub_1A1C4();                                //call sub_1A1C4
loc_1A081:                                      //loc_1A081:
    goto locret_1A107;                          //jmp locret_1A107
loc_1A084:                                      //loc_1A084:
    _bx -= 1;                                   //dec bx
    _bx <<= 1;                                  //shl bx, 1
    _ds = memory16(_ds, _bx + 24048);           //mov ds, word ptr [bx+5DF0h]
    sub_18B2A();                                //call sub_18B2A
    _ax = _seg002;                              //mov ax, seg seg002
    _ds = _ax;                                  //mov ds, ax
    _push(_es);                                 //push es
    _si = 0xa000;                               //mov si, 0A000h
    _es = _si;                                  //mov es, si
    _bx = memory16(_ds, 0x40C9);                //mov bx, word_14199
    _bx <<= 1;                                  //shl bx, 1
    _si = memory16(_cs, _bx + 693);             //mov si, cs:[bx+2B5h]
    memory16(_cs, 0x31A) = _si;                 //mov cs:word_186AA, si
    _si = 0x0247;                               //mov si, 247h
    _bp = 0x3e80;                               //mov bp, 3E80h
    memory16(_cs, 0x31C) = 0x1f40;              //mov cs:word_186AC, 1F40h
    sub_1880D();                                //call sub_1880D
    _push(_ds);                                 //push ds
    _al = 0x01;                                 //mov al, 1
    sub_188CD();                                //call sub_188CD
    _al = 0x0f;                                 //mov al, 0Fh
    sub_188B9();                                //call sub_188B9
    _al = 0xff;                                 //mov al, 0FFh
    sub_188E1();                                //call sub_188E1
    _si = 0xa000;                               //mov si, 0A000h
    _ds = _si;                                  //mov ds, si
    _di = memory16(_cs, 0x320);                 //mov di, cs:word_186B0
    _si = 0x3e80;                               //mov si, 3E80h
    _cx = memory16(_cs, 0x31C);                 //mov cx, cs:word_186AC
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _ds = _pop();                               //pop ds
    _es = _pop();                               //pop es
    if (memory(_ds, 0x5E06) != 0x01)            //jnz short loc_1A0E9
        goto loc_1A0E9;
    sub_1A10C();                                //call sub_1A10C
loc_1A0E9:                                      //loc_1A0E9:
    if (memory(_ds, 0x5E07) != 0x01)            //jnz short loc_1A0F3
        goto loc_1A0F3;
    sub_1A114();                                //call sub_1A114
loc_1A0F3:                                      //loc_1A0F3:
    if (memory(_ds, 0x5E3A) != 0x01)            //jnz short loc_1A0FD
        goto loc_1A0FD;
    sub_1A108();                                //call sub_1A108
loc_1A0FD:                                      //loc_1A0FD:
    if (memory(_ds, 0x62EF) != 0x01)            //jnz short locret_1A107
        goto locret_1A107;
    sub_1A110();                                //call sub_1A110
locret_1A107:                                   //locret_1A107:
    return;
}

void sub_1A108()
{
    sub_1A1C4();                                //call sub_1A1C4
}

void sub_1A10C()
{
    sub_1A209();                                //call sub_1A209
}

void sub_1A110()
{
    sub_1A196();                                //call sub_1A196
}

void sub_1A114()
{
    sub_1A26D();                                //call sub_1A26D
    sub_1A11B();                                //call sub_1A11B
}

void sub_1A11B()
{
    WORD _cs = _seg003;

    memory(_cs, 0x201B) = 0x0f;                 //mov cs:byte_1A3AB, 0Fh
    memory(_ds, 0x42E6) = 0x07;                 //mov byte ptr ds:42E6h, 7
    _bx = _bx ^ _bx;                            //xor bx, bx
    memory16(_cs, 0x2018) = 0x006b;             //mov cs:word_1A3A8, 6Bh
    _dh = 0x6b;                                 //mov dh, 6Bh
    _dl = 0x21;                                 //mov dl, 21h
loc_1A134:                                      //loc_1A134:
    _push(_bx);                                 //push bx
    _bx = 0x0805;                               //mov bx, 805h
    _push(_dx);                                 //push dx
    sub_1A833();                                //call sub_1A833
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
    _ax = _bx;                                  //mov ax, bx
    _ax <<= 1;                                  //shl ax, 1
    _si = 0x40d3;                               //mov si, 40D3h
    _si += _ax;                                 //add si, ax
    _di = 0x40ce;                               //mov di, 40CEh
    _push(_bx);                                 //push bx
    sub_1A7D2();                                //call sub_1A7D2
    _bp = 0x40cd;                               //mov bp, 40CDh
    _push(_dx);                                 //push dx
    memory16(_cs, 0x2016) = 0x0021;             //mov cs:word_1A3A6, 21h
    sub_1A9D8();                                //call sub_1A9D8
    _dx = _pop();                               //pop dx
    _dh += 0x09;                                //add dh, 9
    memory16(_cs, 0x2018) += 0x0009;            //add cs:word_1A3A8, 9
    _bx = _pop();                               //pop bx
    _bx += 1;                                   //inc bx
    memory(_ds, 0x42E6) -= 1;                   //dec byte ptr ds:42E6h
    if (memory(_ds, 0x42E6) != 0)               //jnz short loc_1A134
        goto loc_1A134;
    _dh += 0x05;                                //add dh, 5
    memory16(_cs, 0x2018) += 0x0005;            //add cs:word_1A3A8, 5
    _bx = 0x0805;                               //mov bx, 805h
    _push(_dx);                                 //push dx
    sub_1A833();                                //call sub_1A833
    _dx = _pop();                               //pop dx
    _si = 0x40f0;                               //mov si, 40F0h
    _di = 0x40ce;                               //mov di, 40CEh
    sub_1A7D2();                                //call sub_1A7D2
    _bp = 0x40cd;                               //mov bp, 40CDh
    memory16(_cs, 0x2016) = 0x0021;             //mov cs:word_1A3A6, 21h
    sub_1A9D8();                                //call sub_1A9D8
}

void sub_1A196()
{
    WORD _cs = _seg003;

    memory(_cs, 0x201B) = 0x04;                 //mov cs:byte_1A3AB, 4
    _di = 0x1dd8;                               //mov di, 1DD8h
    _bx = 0x0928;                               //mov bx, 928h
    _al = 0x0f;                                 //mov al, 0Fh
    sub_1A8FC();                                //call sub_1A8FC
    memory16(_cs, 0x2016) = 0x0001;             //mov cs:word_1A3A6, 1
    memory16(_cs, 0x2018) = 0x00c0;             //mov cs:word_1A3A8, 0C0h
    _bx = memory16(_ds, 0x40C9);                //mov bx, ds:40C9h
    _bx <<= 1;                                  //shl bx, 1
    _bp = memory16(_ds, _bx + 25693);           //mov bp, [bx+645Dh]
    sub_1A9D8();                                //call sub_1A9D8
}

void sub_1A1C4()
{
    WORD _cs = _seg003;

    memory(_cs, 0x201B) = 0x0f;                 //mov cs:byte_1A3AB, 0Fh
    _di = 0x00e6;                               //mov di, 0E6h
    _bx = 0x2507;                               //mov bx, 2507h
    _al = 0x00;                                 //mov al, 0
    sub_1A8FC();                                //call sub_1A8FC
    _di = 0x010e;                               //mov di, 10Eh
    _bx = 0x2307;                               //mov bx, 2307h
    sub_1A876();                                //call sub_1A876
    memory16(_cs, 0x2016) = 0x001f;             //mov cs:word_1A3A6, 1Fh
    memory16(_cs, 0x2018) = 0x0009;             //mov cs:word_1A3A8, 9
    _bp = 0x5e3b;                               //mov bp, 5E3Bh
    sub_1A9D8();                                //call sub_1A9D8
    _bx = memory16(_ds, 0x40C9);                //mov bx, ds:40C9h
    _bx <<= 1;                                  //shl bx, 1
    _si = memory16(_ds, _bx + 226);             //mov si, [bx+0E2h]
    _bh = 0x0f;                                 //mov bh, 0Fh
    _bl = 0x03;                                 //mov bl, 3
    _dl = 0x20;                                 //mov dl, 20h
    _dh = 0x15;                                 //mov dh, 15h
    sub_19B5C();                                //call sub_19B5C
}

void sub_1A209()
{
    WORD _cs = _seg003;

    memory(_cs, 0x201B) = 0x0f;                 //mov cs:byte_1A3AB, 0Fh
    _di = 0x0e60;                               //mov di, 0E60h
    _bx = 0x5f0d;                               //mov bx, 5F0Dh
    sub_1A941();                                //call sub_1A941
    _di = 0x0e88;                               //mov di, 0E88h
    _bl = 0x0d;                                 //mov bl, 0Dh
    _bh = 0x5d;                                 //mov bh, 5Dh
    sub_1A876();                                //call sub_1A876
    memory16(_cs, 0x2016) = 0x0002;             //mov cs:word_1A3A6, 2
    memory16(_cs, 0x2018) = 0x005f;             //mov cs:word_1A3A8, 5Fh
    _bp = 0x432c;                               //mov bp, 432Ch
    sub_1A9D8();                                //call sub_1A9D8
    memory(_ds, 0x42E6) = 0x07;                 //mov byte ptr ds:42E6h, 7
    memory16(_cs, 0x2018) = 0x006d;             //mov cs:word_1A3A8, 6Dh
    if (memory(_ds, 0x5D9C) != 0x01)            //jnz short loc_1A250
        goto loc_1A250;
    _bp = 0x4392;                               //mov bp, 4392h
    goto loc_1A253;                             //jmp short loc_1A253
loc_1A250:                                      //loc_1A250:
    _bp = 0x4334;                               //mov bp, 4334h
loc_1A253:                                      //loc_1A253:
    memory16(_cs, 0x2016) = 0x0001;             //mov cs:word_1A3A6, 1
    sub_1A9D8();                                //call sub_1A9D8
    memory16(_cs, 0x2018) += 0x000b;            //add cs:word_1A3A8, 0Bh
    memory(_ds, 0x42E6) -= 1;                   //dec byte ptr ds:42E6h
    if (memory(_ds, 0x42E6) != 0)               //jnz short loc_1A253
        goto loc_1A253;
    sub_18768();                                //call sub_18768
}

void sub_1A26D()
{
    WORD _cs = _seg003;

    memory(_cs, 0x201B) = 0x0f;                 //mov cs:byte_1A3AB, 0Fh
    _di = 0x0e7c;                               //mov di, 0E7Ch
    _bh = 0x5e;                                 //mov bh, 5Eh
    _bl = 0x0b;                                 //mov bl, 0Bh
    sub_1A941();                                //call sub_1A941
    _di = 0x0ea4;                               //mov di, 0EA4h
    _bh = 0x5c;                                 //mov bh, 5Ch
    _bl = 0x0b;                                 //mov bl, 0Bh
    sub_1A876();                                //call sub_1A876
    _bp = 0x4386;                               //mov bp, 4386h
    memory16(_cs, 0x2016) = 0x001d;             //mov cs:word_1A3A6, 1Dh
    memory16(_cs, 0x2018) = 0x005e;             //mov cs:word_1A3A8, 5Eh
    sub_1A9D8();                                //call sub_1A9D8
    _dl = 0x1d;                                 //mov dl, 1Dh
    _dh = 0x6b;                                 //mov dh, 6Bh
    memory(_ds, 0x42E6) = 0x07;                 //mov byte ptr ds:42E6h, 7
    memory16(_cs, 0x324) = 0x0002;              //mov cs:word_186B4, 2
loc_1A2AC:                                      //loc_1A2AC:
    _bx = memory16(_cs, 0x324);                 //mov bx, cs:word_186B4
    _si = memory16(_ds, _bx + 208);             //mov si, [bx+0D0h]
    _bx = 0x0801;                               //mov bx, 801h
    _push(_dx);                                 //push dx
    sub_19B5C();                                //call sub_19B5C
    _dx = _pop();                               //pop dx
    _dh += 0x09;                                //add dh, 9
    memory16(_cs, 0x324) += 0x0002;             //add cs:word_186B4, 2
    memory(_ds, 0x42E6) -= 1;                   //dec byte ptr ds:42E6h
    if (memory(_ds, 0x42E6) != 0)               //jnz short loc_1A2AC
        goto loc_1A2AC;
    _dh += 0x05;                                //add dh, 5
    _bx = memory16(_cs, 0x324);                 //mov bx, cs:word_186B4
    _si = memory16(_ds, _bx + 208);             //mov si, [bx+0D0h]
    _bx = 0x0801;                               //mov bx, 801h
    sub_19B5C();                                //call sub_19B5C
    memory(_ds, 0x42E6) = 0x07;                 //mov byte ptr ds:42E6h, 7
    memory16(_cs, 0x2018) = 0x006b;             //mov cs:word_1A3A8, 6Bh
loc_1A2EA:                                      //loc_1A2EA:
    _bp = 0x4390;                               //mov bp, 4390h
    memory16(_cs, 0x2016) = 0x001f;             //mov cs:word_1A3A6, 1Fh
    sub_1A9D8();                                //call sub_1A9D8
    memory16(_cs, 0x2018) += 0x0009;            //add cs:word_1A3A8, 9
    memory(_ds, 0x42E6) -= 1;                   //dec byte ptr ds:42E6h
    if (memory(_ds, 0x42E6) != 0)               //jnz short loc_1A2EA
        goto loc_1A2EA;
    _bp = 0x4390;                               //mov bp, 4390h
    memory16(_cs, 0x2018) += 0x0005;            //add cs:word_1A3A8, 5
    memory16(_cs, 0x2016) = 0x001f;             //mov cs:word_1A3A6, 1Fh
    sub_1A9D8();                                //call sub_1A9D8
    _di = 0x1afd;                               //mov di, 1AFDh
    _al = 0x0f;                                 //mov al, 0Fh
    _bx = 0x0109;                               //mov bx, 109h
    sub_1A8FC();                                //call sub_1A8FC
}

void sub_1A322()
{
    _bp = memory16(_ds, 0x428D);                //mov bp, ds:428Dh
    _bp -= 1;                                   //dec bp
    _bp <<= 1;                                  //shl bp, 1
    _bp = memory16(_ds, _bp + 515);             //mov bp, ds:[bp+203h]
    _bp = memory16(_ds, _bp + 0);               //mov bp, ds:[bp+0]
    _ah = memory(_ds, _bp + 1);                 //mov ah, ds:[bp+1]
    _al = memory(_ds, _bp + 0);                 //mov al, ds:[bp+0]
    _bp += 0x0002;                              //add bp, 2
    _di = 0x04df;                               //mov di, 4DFh
    sub_1AD03();                                //call sub_1AD03
    memory16(_ds, 0x140) = memory16(_ds, 0x140) ^ 0x0001;
}

void sub_1A34A()
{
    WORD _cs = _seg003;

    _bx = memory16(_ds, 0x40C9);                //mov bx, ds:40C9h
    _bx <<= 1;                                  //shl bx, 1
    _bx = memory16(_ds, _bx + 24072);           //mov bx, [bx+5E08h]
    memory(_cs, 0x201B) = _bl;                  //mov cs:byte_1A3AB, bl
    _si = 0x011f;                               //mov si, 11Fh
    _di = _si;                                  //mov di, si
    _bh = 0x14;                                 //mov bh, 14h
    _bl = 0x05;                                 //mov bl, 5
    sub_19111();                                //call sub_19111
    _si = 0x40cb;                               //mov si, 40CBh
    _di = 0x40ce;                               //mov di, 40CEh
    memory16(_ds, 0x241) = 0x0005;              //mov word ptr ds:241h, 5
    sub_1A7D2();                                //call sub_1A7D2
    _bp = 0x40cd;                               //mov bp, 40CDh
    memory16(_cs, 0x2016) = 0x0007;             //mov cs:word_1A3A6, 7
    memory16(_cs, 0x2018) = 0x0007;             //mov cs:word_1A3A8, 7
    sub_1A9D8();                                //call sub_1A9D8
    _si = 0x40e8;                               //mov si, 40E8h
    _di = 0x40eb;                               //mov di, 40EBh
    sub_1A7D2();                                //call sub_1A7D2
    _bp = 0x40ea;                               //mov bp, 40EAh
    memory16(_cs, 0x2016) = 0x0007;             //mov cs:word_1A3A6, 7
    memory16(_cs, 0x2018) = 0x0013;             //mov cs:word_1A3A8, 13h
    sub_1A9D8();                                //call sub_1A9D8
}

void sub_1A3AC()
{
    _bx = _ax;                                  //mov bx, ax
    _bx -= 1;                                   //dec bx
    _cx = 0x0007;                               //mov cx, 7
loc_1A3B2:                                      //loc_1A3B2:
    _bx |= _bx;                                 //or bx, bx
    if (_bx != 0)                               //jnz short loc_1A3BC
        goto loc_1A3BC;
    _dx = 0x0001;                               //mov dx, 1
    goto loc_1A3BF;                             //jmp short loc_1A3BF
loc_1A3BC:                                      //loc_1A3BC:
    _dx = 0x0002;                               //mov dx, 2
loc_1A3BF:                                      //loc_1A3BF:
    if (memory(_ds, _bx + 16609) == _dl)        //jz short loc_1A3CD
        goto loc_1A3CD;
    memory(_ds, _bx + 16609) += 1;              //inc byte ptr [bx+40E1h]
    _bx += 1;                                   //inc bx
    _ax = _bx;                                  //mov ax, bx
    return;                                     //retn
loc_1A3CD:                                      //loc_1A3CD:
    memory(_ds, _bx + 16609) = 0x00;            //mov byte ptr [bx+40E1h], 0
    _bx += 1;                                   //inc bx
    if (_bx != 0x0007)                          //jnz short loc_1A3DA
        goto loc_1A3DA;
    _bx = _bx ^ _bx;                            //xor bx, bx
loc_1A3DA:                                      //loc_1A3DA:
    _cx -= 1;                                   //dec cx
    if (_cx != 0)                               //jnz short loc_1A3B2
        goto loc_1A3B2;
}

void sub_1A3DE()
{
    _dx = _es;                                  //mov dx, es
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(22);                             //int 16h
    if (!_flags.zero)                           //jnz short loc_1A3F8
        goto loc_1A3F8;
    _bx = _bx ^ _bx;                            //xor bx, bx
    _es = _bx;                                  //mov es, bx
    // gabo
//    _bx = memory16(_es, 0x41A);                 //mov bx, es:41Ah
//    memory16(_es, 0x41C) = _bx;                 //mov es:41Ch, bx
    _flags.carry = false;                       //clc
    _es = _dx;                                  //mov es, dx
    return;                                     //retn
loc_1A3F8:                                      //loc_1A3F8:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _interrupt(22);                             //int 16h
    _bx = _bx ^ _bx;                            //xor bx, bx
    _es = _bx;                                  //mov es, bx
    // gabo
//    _bx = memory16(_es, 0x41A);                 //mov bx, es:41Ah
//    memory16(_es, 0x41C) = _bx;                 //mov es:41Ch, bx
    _flags.carry = true;                        //stc
    _es = _dx;                                  //mov es, dx
}

void sub_1A40E()
{
    WORD _cs = _seg003;

    _push(_es);                                 //push es
    _ax = 0xa000;                               //mov ax, 0A000h
    _es = _ax;                                  //mov es, ax
    memory(_ds, 0x42E6) = 0x09;                 //mov byte ptr ds:42E6h, 9
    _al = 0x18;                                 //mov al, 18h
    sub_18923();                                //call sub_18923
    _al = 0x00;                                 //mov al, 0
    sub_188CD();                                //call sub_188CD
    _al = 0x0f;                                 //mov al, 0Fh
    sub_188B9();                                //call sub_188B9
    _al = 0xff;                                 //mov al, 0FFh
    sub_188E1();                                //call sub_188E1
loc_1A42D:                                      //loc_1A42D:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_1A42F:                                      //loc_1A42F:
    memory16(_cs, 0x324) = _ax;                 //mov cs:word_186B4, ax
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    _bp = memory16(_ds, _bx + 17926);           //mov bp, [bx+4606h]
    _bp <<= 1;                                  //shl bp, 1
    _di = memory16(_ds, _bp + 17884);           //mov di, ds:[bp+45DCh]
    _di = _di + memory16(_cs, 0x320);           //add di, cs:word_186B0
    _dx = 0x0008;                               //mov dx, 8
    if (memory(_ds, 0x42E6) == 0x01)            //jz short loc_1A467
        goto loc_1A467;
loc_1A451:                                      //loc_1A451:
    _cx = 0x000a;                               //mov cx, 0Ah
loc_1A454:                                      //loc_1A454:
    _al = memoryVideoGet(_es, _di);                     //mov al, es:[di]
    memoryVideoSet(_es, _di, 0xff);                    //mov byte ptr es:[di], 0FFh
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_1A454
        goto loc_1A454;
    _di += 0x001e;                              //add di, 1Eh
    _dx -= 1;                                   //dec dx
    if (_dx != 0)                               //jnz short loc_1A451
        goto loc_1A451;
    goto loc_1A494;                             //jmp short loc_1A494
    _STOP_("db 90h");                           //db 90h
loc_1A467:                                      //loc_1A467:
    _al = 0x00;                                 //mov al, 0
    sub_18923();                                //call sub_18923
    _al = 0x00;                                 //mov al, 0
    sub_188CD();                                //call sub_188CD
    _al = 0x0f;                                 //mov al, 0Fh
    sub_188B9();                                //call sub_188B9
    _al = 0xff;                                 //mov al, 0FFh
    sub_188E1();                                //call sub_188E1
    _bl = 0x0a;                                 //mov bl, 0Ah
    _bh = 0x08;                                 //mov bh, 8
    _di = _di - memory16(_cs, 0x320);           //sub di, cs:word_186B0
    _si = _di;                                  //mov si, di
    sub_19111();                                //call sub_19111
    _bx = memory16(_cs, 0x320);                 //mov bx, cs:word_186B0
    sub_1888B();                                //call sub_1888B
    goto loc_1A4B2;                             //jmp short loc_1A4B2
loc_1A494:                                      //loc_1A494:
    _ax = memory16(_cs, 0x324);                 //mov ax, cs:word_186B4
    _ax += 1;                                   //inc ax
    if (_ax == memory16(_ds, 0x4604))           //jz short loc_1A4A1
        goto loc_1A4A1;
    goto loc_1A42F;                             //jmp short loc_1A42F
loc_1A4A1:                                      //loc_1A4A1:
    _bx = memory16(_cs, 0x320);                 //mov bx, cs:word_186B0
    sub_1888B();                                //call sub_1888B
    memory(_ds, 0x42E6) -= 1;                   //dec byte ptr ds:42E6h
    if (memory(_ds, 0x42E6) == 0)               //jz short loc_1A4B2
        goto loc_1A4B2;
    goto loc_1A42D;                             //jmp loc_1A42D
loc_1A4B2:                                      //loc_1A4B2:
    _bx = memory16(_ds, 0x4604);                //mov bx, ds:4604h
    memory(_ds, 0x42E6) = _bl;                  //mov ds:42E6h, bl
loc_1A4BA:                                      //loc_1A4BA:
    _si = 0x45be;                               //mov si, 45BEh
    sub_1918B();                                //call sub_1918B
    memory(_ds, 0x42E6) -= 1;                   //dec byte ptr ds:42E6h
    if (memory(_ds, 0x42E6) != 0)               //jnz short loc_1A4BA
        goto loc_1A4BA;
    _es = _pop();                               //pop es
}

void sub_1A4C8()
{
    WORD _cs = _seg003;

    _push(_es);                                 //push es
    _ax = 0x0003;                               //mov ax, 3
    _interrupt(16);                             //int 10h
    if (memory(_cs, 0x0) != 0x01)               //jnz short loc_1A4DC
        goto loc_1A4DC;
    _ax = 0xb000;                               //mov ax, 0B000h
    goto loc_1A4DF;                             //jmp short loc_1A4DF
loc_1A4DC:                                      //loc_1A4DC:
    _ax = 0xb800;                               //mov ax, 0B800h
loc_1A4DF:                                      //loc_1A4DF:
    _es = _ax;                                  //mov es, ax
    _di = 0x0096;                               //mov di, 96h
    _si = 0x43dd;                               //mov si, 43DDh
    _ah = 0x30;                                 //mov ah, 30h
    sub_1A71B();                                //call sub_1A71B
    _di = 0x0140;                               //mov di, 140h
    _ax = 0x3f20;                               //mov ax, 3F20h
    _cx = 0x004b;                               //mov cx, 4Bh
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _cx = 0x0008;                               //mov cx, 8
    _di = 0x014e;                               //mov di, 14Eh
    _ax = 0x3041;                               //mov ax, 3041h
loc_1A500:                                      //loc_1A500:
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    _al += 1;                                   //inc al
    _di += 0x0012;                              //add di, 12h
    _cx -= 1;                                   //dec cx
    if (_cx != 0)                               //jnz short loc_1A500
        goto loc_1A500;
    memory(_ds, 0x42E6) = 0x02;                 //mov byte ptr ds:42E6h, 2
    _di = 0x01e0;                               //mov di, 1E0h
    _ax = 0x3020;                               //mov ax, 3020h
    _dx = _ax;                                  //mov dx, ax
loc_1A518:                                      //loc_1A518:
    _bx = 0x3030;                               //mov bx, 3030h
    _cx = 0x000a;                               //mov cx, 0Ah
loc_1A51E:                                      //loc_1A51E:
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    memoryVideoSet16(_es, _di + 2, _dx);               //mov es:[di+2], dx
    memoryVideoSet16(_es, _di + 4, _bx);               //mov es:[di+4], bx
    _bl += 1;                                   //inc bl
    _di += 0x00a0;                              //add di, 0A0h
    _cx -= 1;                                   //dec cx
    if (_cx != 0)                               //jnz short loc_1A51E
        goto loc_1A51E;
    memory(_ds, 0x42E6) -= 1;                   //dec byte ptr ds:42E6h
    if (memory(_ds, 0x42E6) == 0)               //jz short loc_1A53D
        goto loc_1A53D;
    _dx = 0x3031;                               //mov dx, 3031h
    goto loc_1A518;                             //jmp short loc_1A518
loc_1A53D:                                      //loc_1A53D:
    // TODO: PARSER GABO mov word ptr memory???
    memoryVideoSet16(_es, _di, 0x3020);                //mov word ptr es:[di], 3020h
    memoryVideoSet16(_es, _di + 0x2, 0x3032);            //mov word ptr es:[di+2], 3032h
    memoryVideoSet16(_es, _di + 0x4, 0x3030);            //mov word ptr es:[di+4], 3030h
    _si = 0x43e3;                               //mov si, 43E3h
    _di = 0x02ba;                               //mov di, 2BAh
    _ah = 0x0f;                                 //mov ah, 0Fh
    sub_1A71B();                                //call sub_1A71B
    _di = 0x03ea;                               //mov di, 3EAh
    _si = 0x4413;                               //mov si, 4413h
    _dx = _di;                                  //mov dx, di
    _bx = 0x0006;                               //mov bx, 6
loc_1A564:                                      //loc_1A564:
    sub_1A71B();                                //call sub_1A71B
    _dx += 0x0012;                              //add dx, 12h
    _di = _dx;                                  //mov di, dx
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz short loc_1A564
        goto loc_1A564;
    _di = 0x0506;                               //mov di, 506h
    _si = 0x4442;                               //mov si, 4442h
    _dx = _di;                                  //mov dx, di
    _bx = 0x000c;                               //mov bx, 0Ch
loc_1A57A:                                      //loc_1A57A:
    sub_1A71B();                                //call sub_1A71B
    _dx += 0x00a0;                              //add dx, 0A0h
    _di = _dx;                                  //mov di, dx
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz short loc_1A57A
        goto loc_1A57A;
    memory(_ds, 0x42E6) = 0x0c;                 //mov byte ptr ds:42E6h, 0Ch
    _di = 0x052a;                               //mov di, 52Ah
    memory16(_ds, 0x4306) = _di;                //mov ds:4306h, di
    memory16(_ds, 0x42E4) = _di;                //mov ds:42E4h, di
loc_1A596:                                      //loc_1A596:
    sub_1AB24();                                //call sub_1AB24
    memory16(_ds, 0x4289) += _cx;               //add ds:4289h, cx
    sub_1AB3E();                                //call sub_1AB3E
    _ax |= _cx;                                 //or ax, cx
    _ax &= 0x007f;                              //and ax, 7Fh
    _ax |= 0x0080;                              //or ax, 80h
    memory16(_ds, 0x23F) = _ax;                 //mov ds:23Fh, ax
    memory16(_ds, 0x42E2) = 0x0006;             //mov word ptr ds:42E2h, 6
loc_1A5B1:                                      //loc_1A5B1:
    sub_1AB3E();                                //call sub_1AB3E
    _ax &= 0x003f;                              //and ax, 3Fh
    memory16(_ds, 0x23F) += _ax;                //add ds:23Fh, ax
    _si = 0x023f;                               //mov si, 23Fh
    _di = 0x40ce;                               //mov di, 40CEh
    memory16(_ds, 0x241) = 0x0005;              //mov word ptr ds:241h, 5
    sub_1A7D2();                                //call sub_1A7D2
    _di = memory16(_ds, 0x42E4);                //mov di, ds:42E4h
    _ah = 0x0f;                                 //mov ah, 0Fh
    _si = 0x40cd;                               //mov si, 40CDh
    sub_1A71B();                                //call sub_1A71B
    _si = 0x44ac;                               //mov si, 44ACh
    sub_1A71B();                                //call sub_1A71B
    memory16(_ds, 0x42E4) += 0x0012;            //add word ptr ds:42E4h, 12h
    memory16(_ds, 0x42E2) -= 1;                 //dec word ptr ds:42E2h
    if (memory16(_ds, 0x42E2) != 0)             //jnz short loc_1A5B1
        goto loc_1A5B1;
    memory16(_ds, 0x4306) += 0x00a0;            //add word ptr ds:4306h, 0A0h
    _cx = memory16(_ds, 0x4306);                //mov cx, ds:4306h
    memory16(_ds, 0x42E4) = _cx;                //mov ds:42E4h, cx
    memory(_ds, 0x42E6) -= 1;                   //dec byte ptr ds:42E6h
    if (memory(_ds, 0x42E6) == 0)               //jz short loc_1A5FD
        goto loc_1A5FD;
    goto loc_1A596;                             //jmp short loc_1A596
loc_1A5FD:                                      //loc_1A5FD:
    sub_19C18();                                //call sub_19C18
    if (_ah == 0x01)                            //jz short loc_1A623
        goto loc_1A623;
    if (_ah != 0x10)                            //jnz short loc_1A612
        goto loc_1A612;
    memory(_ds, 0x5E39) = 0x01;                 //mov byte ptr ds:5E39h, 1
    goto loc_1A63A;                             //jmp short loc_1A63A
loc_1A612:                                      //loc_1A612:
    if (_ah != 0x1f)                            //jnz short loc_1A61F
        goto loc_1A61F;
    memory(_ds, 0x5D11) = memory(_ds, 0x5D11) ^ 0x01;//xor byte ptr ds:5D11h, 1
    _cx = 0x0900;                               //mov cx, 900h
loc_1A61F:                                      //loc_1A61F:
    if (--_cx)                                  //loop loc_1A61F
        goto loc_1A61F;
    goto loc_1A5FD;                             //jmp short loc_1A5FD
loc_1A623:                                      //loc_1A623:
    if (memory(_cs, 0x0) != 0x01)               //jnz short loc_1A631
        goto loc_1A631;
    sub_18BB2();                                //call sub_18BB2
    goto loc_1A634;                             //jmp short loc_1A634
    _STOP_("db 90h");                           //db 90h
loc_1A631:                                      //loc_1A631:
    sub_1A699();                                //call sub_1A699
loc_1A634:                                      //loc_1A634:
    sub_19C06();                                //call sub_19C06
    sub_19BCA();                                //call sub_19BCA
loc_1A63A:                                      //loc_1A63A:
    _es = _pop();                               //pop es
}

void sub_1A63C()
{
    WORD _cs = _seg003;

    _ax = memory16(_cs, 0x320);                 //mov ax, cs:word_186B0
    _push(_ax);                                 //push ax
    memory16(_cs, 0x2016) = 0x0000;             //mov cs:word_1A3A6, 0
    memory16(_cs, 0x2018) = 0x0000;             //mov cs:word_1A3A8, 0
    memory16(_cs, 0x320) = 0x7d00;              //mov cs:word_186B0, 7D00h
    _bp = 0x430d;                               //mov bp, 430Dh
    memory(_cs, 0x201B) = 0x0f;                 //mov cs:byte_1A3AB, 0Fh
    sub_1A9D8();                                //call sub_1A9D8
    _bx = memory16(_cs, 0x320);                 //mov bx, cs:word_186B0
    sub_1888B();                                //call sub_1888B
loc_1A66A:                                      //loc_1A66A:
    sub_19C18();                                //call sub_19C18
    if (_ah == 0x01)                            //jz short loc_1A690
        goto loc_1A690;
    if (_ah != 0x10)                            //jnz short loc_1A67F
        goto loc_1A67F;
    memory(_ds, 0x5E39) = 0x01;                 //mov byte ptr ds:5E39h, 1
    goto locret_1A698;                          //jmp short locret_1A698
    _STOP_("db 90h");                           //db 90h
loc_1A67F:                                      //loc_1A67F:
    if (_ah != 0x1f)                            //jnz short loc_1A68C
        goto loc_1A68C;
    memory(_ds, 0x5D11) = memory(_ds, 0x5D11) ^ 0x01;//xor byte ptr ds:5D11h, 1
    _cx = 0x0900;                               //mov cx, 900h
loc_1A68C:                                      //loc_1A68C:
    if (--_cx)                                  //loop loc_1A68C
        goto loc_1A68C;
    goto loc_1A66A;                             //jmp short loc_1A66A
loc_1A690:                                      //loc_1A690:
    _ax = _pop();                               //pop ax
    memory16(_cs, 0x320) = _ax;                 //mov cs:word_186B0, ax
    sub_18768();                                //call sub_18768
locret_1A698:                                   //locret_1A698:
    return;                                     //retn
    _STOP_("sp-trace-fail");                    //sub_1A63C endp_failed
    _STOP_("continues");                        //sub_1A699 proc near
}

void sub_1A699()
{
    _push(_es);                                 //push es
    _ax = 0x0040;                               //mov ax, 40h
    _es = _ax;                                  //mov es, ax
    _bl = memoryBiosGet(_es, 0x87);                    //mov bl, es:87h
    _bl |= _bl;                                 //or bl, bl
    if (_bl == 0)                               //jz short loc_1A6C9
        goto loc_1A6C9;
    if (_bl & 0x08)                             //jnz short loc_1A6C9
        goto loc_1A6C9;
    _ax = 0x0005;                               //mov ax, 5
    _interrupt(16);                             //int 10h
    _dx = 0x03da;                               //mov dx, 3DAh
loc_1A6B5:                                      //loc_1A6B5:
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x08))                          //jz short loc_1A6B5
        goto loc_1A6B5;
    _dx = 0x03c0;                               //mov dx, 3C0h
    _al = 0x02;                                 //mov al, 2
    _out(_dx, _al);                             //out dx, al
    _al = 0x2c;                                 //mov al, 2Ch
    _out(_dx, _al);                             //out dx, al
    _al = 0x20;                                 //mov al, 20h
    _out(_dx, _al);                             //out dx, al
    goto loc_1A6D1;                             //jmp short loc_1A6D1
    _STOP_("db 90h");                           //db 90h
loc_1A6C9:                                      //loc_1A6C9:
    _ax = 0x0004;                               //mov ax, 4
    _interrupt(16);                             //int 10h
    sub_1916C();                                //call sub_1916C
loc_1A6D1:                                      //loc_1A6D1:
    _es = _pop();                               //pop es
}

void sub_1A6D3()
{
    WORD _cs = _seg003;

    _push(_es);                                 //push es
    _ax = 0x0040;                               //mov ax, 40h
    _es = _ax;                                  //mov es, ax
    _bl = memoryBiosGet(_es, 0x87);                    //mov bl, es:87h
    _bl |= _bl;                                 //or bl, bl
    if (_bl == 0)                               //jz short loc_1A711
        goto loc_1A711;
    if (_bl & 0x08)                             //jnz short loc_1A711
        goto loc_1A711;
    memory(_cs, 0x10) = 0x01;                   //mov cs:byte_183A0, 1
    _ax = 0x000d;                               //mov ax, 0Dh
    _interrupt(16);                             //int 10h
    sub_189F8();                                //call sub_189F8
    _ax = 0x0005;                               //mov ax, 5
    _interrupt(16);                             //int 10h
    _dx = 0x03da;                               //mov dx, 3DAh
loc_1A6FD:                                      //loc_1A6FD:
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x08))                          //jz short loc_1A6FD
        goto loc_1A6FD;
    _dx = 0x03c0;                               //mov dx, 3C0h
    _al = 0x02;                                 //mov al, 2
    _out(_dx, _al);                             //out dx, al
    _al = 0x2c;                                 //mov al, 2Ch
    _out(_dx, _al);                             //out dx, al
    _al = 0x20;                                 //mov al, 20h
    _out(_dx, _al);                             //out dx, al
    goto loc_1A719;                             //jmp short loc_1A719
    _STOP_("db 90h");                           //db 90h
loc_1A711:                                      //loc_1A711:
    _ax = 0x0004;                               //mov ax, 4
    _interrupt(16);                             //int 10h
    sub_1916C();                                //call sub_1916C
loc_1A719:                                      //loc_1A719:
    _es = _pop();                               //pop es
}

void sub_1A71B()
{
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _cl = _al;                                  //mov cl, al
loc_1A71E:                                      //loc_1A71E:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _stosw<MemAuto, DirAuto>();                 //stosw
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_1A71E
        goto loc_1A71E;
}

void loc_1A784()
{
loc_1A784:
    _push(_bx);                                 //push bx
    _bx = 0x080a;                               //mov bx, 80Ah
    sub_1A802();                                //call sub_1A802
    _bx = _pop();                               //pop bx
    _ax = _bx;                                  //mov ax, bx
    _ax <<= 1;                                  //shl ax, 1
    _si = 0x40d3;                               //mov si, 40D3h
    _si += _ax;                                 //add si, ax
    _di = 0x40ce;                               //mov di, 40CEh
    _push(_bx);                                 //push bx
    sub_1A7D2();                                //call sub_1A7D2
    _bp = 0x40cd;                               //mov bp, 40CDh
    _push(_dx);                                 //push dx
    sub_1A947();                                //call sub_1A947
    _dx = _pop();                               //pop dx
    _dh += 0x09;                                //add dh, 9
    memory16(_ds, 0x42E4) += 0x0009;            //add word ptr ds:42E4h, 9
    _bx = _pop();                               //pop bx
    _bx += 1;                                   //inc bx
    memory(_ds, 0x42E6) -= 1;                   //dec byte ptr ds:42E6h
    if (memory(_ds, 0x42E6) != 0)               //jnz short loc_1A784
        goto loc_1A784;
    _dh += 0x05;                                //add dh, 5
    memory16(_ds, 0x42E4) += 0x0005;            //add word ptr ds:42E4h, 5
    _bx = 0x080a;                               //mov bx, 80Ah
    sub_1A802();                                //call sub_1A802
    _si = 0x40f0;                               //mov si, 40F0h
    _di = 0x40ce;                               //mov di, 40CEh
    sub_1A7D2();                                //call sub_1A7D2
    _bp = 0x40cd;                               //mov bp, 40CDh
    sub_1A947();                                //call sub_1A947
}

void sub_1A7D2()
{
    _push(_dx);                                 //push dx
    _bp = _bp ^ _bp;                            //xor bp, bp
    _al = 0x20;                                 //mov al, 20h
    _cx = memory16(_ds, 0x241);                 //mov cx, ds:241h
loc_1A7DB:                                      //loc_1A7DB:
    memory(_ds, _bp + _di) = _al;               //mov ds:[bp+di], al
    _bp += 1;                                   //inc bp
    _cx -= 1;                                   //dec cx
    if (_cx != 0)                               //jnz short loc_1A7DB
        goto loc_1A7DB;
    _bp -= 1;                                   //dec bp
    _bx = 0x000a;                               //mov bx, 0Ah
    _cx = memory16(_ds, 0x241);                 //mov cx, ds:241h
    _cx += 1;                                   //inc cx
    _ax = memory16(_ds, _si);                   //mov ax, [si]
loc_1A7ED:                                      //loc_1A7ED:
    _dx = _dx ^ _dx;                            //xor dx, dx
    _div(_bx);                                  //div bx
    _dl += 0x30;                                //add dl, 30h
    memory(_ds, _bp + _di) = _dl;               //mov ds:[bp+di], dl
    if (_ax == 0x0000)                          //jz short loc_1A800
        goto loc_1A800;
    _bp -= 1;                                   //dec bp
    _cx -= 1;                                   //dec cx
    if (_cx != 0)                               //jnz short loc_1A7ED
        goto loc_1A7ED;
loc_1A800:                                      //loc_1A800:
    _dx = _pop();                               //pop dx
}

void sub_1A802()
{
    _di = 0x0247;                               //mov di, 247h
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = _dl;                                  //mov al, dl
    _di += _ax;                                 //add di, ax
    _al = _dh;                                  //mov al, dh
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _cx = _cx ^ _cx;                            //xor cx, cx
    _cl = _bl;                                  //mov cl, bl
    _si = 0x0050;                               //mov si, 50h
    _si -= _cx;                                 //sub si, cx
    _al = _al ^ _al;                            //xor al, al
loc_1A828:                                      //loc_1A828:
    _cl = _bl;                                  //mov cl, bl
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    _di += _si;                                 //add di, si
    _bh -= 1;                                   //dec bh
    if (_bh != 0)                               //jnz short loc_1A828
        goto loc_1A828;
}

void sub_1A833()
{
    WORD _cs = _seg003;

    _push(_es);                                 //push es
    _ax = 0xa000;                               //mov ax, 0A000h
    _es = _ax;                                  //mov es, ax
    _push(_bx);                                 //push bx
    sub_189A1();                                //call sub_189A1
    _al = 0x02;                                 //mov al, 2
    sub_188CD();                                //call sub_188CD
    _al = 0x0f;                                 //mov al, 0Fh
    sub_188B9();                                //call sub_188B9
    _al = 0xff;                                 //mov al, 0FFh
    sub_188E1();                                //call sub_188E1
    _al = memory(_es, _di);                     //mov al, es:[di]
    _al = 0x00;                                 //mov al, 0
    memory(_es, _di) = _al;                     //mov es:[di], al
    _al = 0x01;                                 //mov al, 1
    sub_188CD();                                //call sub_188CD
    _bx = _pop();                               //pop bx
    _dx = memory16(_cs, 0x5C6);                 //mov dx, cs:word_18956
    _ch = _ch ^ _ch;                            //xor ch, ch
    _cl = _bl;                                  //mov cl, bl
    _dx -= _cx;                                 //sub dx, cx
    _si = _di;                                  //mov si, di
    _al = memory(_es, _si);                     //mov al, es:[si]
loc_1A86A:                                      //loc_1A86A:
    _cl = _bl;                                  //mov cl, bl
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    _di += _dx;                                 //add di, dx
    _bh -= 1;                                   //dec bh
    if (_bh != 0)                               //jnz short loc_1A86A
        goto loc_1A86A;
    _es = _pop();                               //pop es
}

void sub_1A876()
{
    WORD _cs = _seg003;

    _push(_es);                                 //push es
    _ax = 0xa000;                               //mov ax, 0A000h
    _es = _ax;                                  //mov es, ax
    _di = _di + memory16(_cs, 0x320);           //add di, cs:word_186B0
    _al = 0x02;                                 //mov al, 2
    sub_188CD();                                //call sub_188CD
    _al = 0xff;                                 //mov al, 0FFh
    sub_188E1();                                //call sub_188E1
    _al = 0x0f;                                 //mov al, 0Fh
    sub_188B9();                                //call sub_188B9
    _al = memory(_es, _di);                     //mov al, es:[di]
    _al = 0x06;                                 //mov al, 6
    _dx = memory16(_cs, 0x5C6);                 //mov dx, cs:word_18956
    _ch = _ch ^ _ch;                            //xor ch, ch
    _cl = _bl;                                  //mov cl, bl
    _dx -= _cx;                                 //sub dx, cx
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    _di += _dx;                                 //add di, dx
    _al = 0x80;                                 //mov al, 80h
    sub_188E1();                                //call sub_188E1
    _push(_di);                                 //push di
    _al = memory(_es, _di);                     //mov al, es:[di]
    _al = 0x06;                                 //mov al, 6
    _ch = _ch ^ _ch;                            //xor ch, ch
    _cl = _bh;                                  //mov cl, bh
    _cl -= 0x02;                                //sub cl, 2
loc_1A8B6:                                      //loc_1A8B6:
    memory(_es, _di) = _al;                     //mov es:[di], al
    _di = _di + memory16(_cs, 0x5C6);           //add di, cs:word_18956
    if (--_cx)                                  //loop loc_1A8B6
        goto loc_1A8B6;
    _al = 0xff;                                 //mov al, 0FFh
    sub_188E1();                                //call sub_188E1
    _al = memory(_es, _di);                     //mov al, es:[di]
    _al = 0x06;                                 //mov al, 6
    _dx = memory16(_cs, 0x5C6);                 //mov dx, cs:word_18956
    _ch = _ch ^ _ch;                            //xor ch, ch
    _cl = _bl;                                  //mov cl, bl
    _dx -= _cx;                                 //sub dx, cx
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    _di = _pop();                               //pop di
    _ch = _ch ^ _ch;                            //xor ch, ch
    _cl = _bl;                                  //mov cl, bl
    _di += _cx;                                 //add di, cx
    _di -= 1;                                   //dec di
    _al = 0x01;                                 //mov al, 1
    sub_188E1();                                //call sub_188E1
    _al = memory(_es, _di);                     //mov al, es:[di]
    _al = 0x06;                                 //mov al, 6
    _ch = _ch ^ _ch;                            //xor ch, ch
    _cl = _bh;                                  //mov cl, bh
    _cl -= 0x02;                                //sub cl, 2
loc_1A8F0:                                      //loc_1A8F0:
    memory(_es, _di) = _al;                     //mov es:[di], al
    _di = _di + memory16(_cs, 0x5C6);           //add di, cs:word_18956
    if (--_cx)                                  //loop loc_1A8F0
        goto loc_1A8F0;
    _es = _pop();                               //pop es
}

void sub_1A8FC()
{
    WORD _cs = _seg003;

    _push(_es);                                 //push es
    _push(_bx);                                 //push bx
    _push(_ax);                                 //push ax
    _ax = 0xa000;                               //mov ax, 0A000h
    _es = _ax;                                  //mov es, ax
    _di = _di + memory16(_cs, 0x320);           //add di, cs:word_186B0
    _al = 0x02;                                 //mov al, 2
    sub_188CD();                                //call sub_188CD
    _al = 0x0f;                                 //mov al, 0Fh
    sub_188B9();                                //call sub_188B9
    _al = 0xff;                                 //mov al, 0FFh
    sub_188E1();                                //call sub_188E1
    _al = memory(_es, _di);                     //mov al, es:[di]
    _ax = _pop();                               //pop ax
    memory(_es, _di) = _al;                     //mov es:[di], al
    _al = 0x01;                                 //mov al, 1
    sub_188CD();                                //call sub_188CD
    _bx = _pop();                               //pop bx
    _dx = memory16(_cs, 0x5C6);                 //mov dx, cs:word_18956
    _ch = _ch ^ _ch;                            //xor ch, ch
    _cl = _bl;                                  //mov cl, bl
    _dx -= _cx;                                 //sub dx, cx
    _si = _di;                                  //mov si, di
    _al = memory(_es, _si);                     //mov al, es:[si]
loc_1A935:                                      //loc_1A935:
    _cl = _bl;                                  //mov cl, bl
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    _di += _dx;                                 //add di, dx
    _bh -= 1;                                   //dec bh
    if (_bh != 0)                               //jnz short loc_1A935
        goto loc_1A935;
    _es = _pop();                               //pop es
}

void sub_1A941()
{
    _al = 0x00;                                 //mov al, 0
    sub_1A8FC();                                //call sub_1A8FC
}

void sub_1A947()
{
    _dx = memory16(_es, 0x42E2);                //mov dx, es:42E2h
    _al = memory(_ds, _bp + 0);                 //mov al, ds:[bp+0]
    memory(_es, 0x42E7) = _al;                  //mov es:42E7h, al
loc_1A954:                                      //loc_1A954:
    _bp += 1;                                   //inc bp
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bl = memory(_ds, _bp + 0);                 //mov bl, ds:[bp+0]
    if ((char)_bl > (char)0x7a)                 //jg short loc_1A975
        goto loc_1A975;
    if ((char)_bl <= (char)0x5a)                //jle short loc_1A968
        goto loc_1A968;
    _bl -= 0x20;                                //sub bl, 20h
loc_1A968:                                      //loc_1A968:
    _flags.carry = (char)_bl < 0x20;
    _bl -= 0x20;                                //sub bl, 20h
    if (_flags.carry)                                //jl short loc_1A975
        goto loc_1A975;
    if ((char)_bl > (char)0x5a)                 //jg short loc_1A975
        goto loc_1A975;
    goto loc_1A977;                             //jmp short loc_1A977
    _STOP_("db 90h");                           //db 90h
loc_1A975:                                      //loc_1A975:
    _bl = _bl ^ _bl;                            //xor bl, bl
loc_1A977:                                      //loc_1A977:
    _cl = 0x04;                                 //mov cl, 4
    _bx <<= _cl;                                //shl bx, cl
    _si = 0x7ea4;                               //mov si, 7EA4h
    _si += _bx;                                 //add si, bx
    _ax = memory16(_es, 0x42E4);                //mov ax, es:42E4h
    _cl = 0x04;                                 //mov cl, 4
    _ax <<= _cl;                                //shl ax, cl
    _di = _ax;                                  //mov di, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _di += _dx;                                 //add di, dx
    _di += 0x0247;                              //add di, 247h
    _cx = 0x0008;                               //mov cx, 8
loc_1A999:                                      //loc_1A999:
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    _bx = _ax;                                  //mov bx, ax
    _bx = (~_bx);                               //not bx
    _ax = _ax & memory16(_ds, 0x5D25);          //and ax, ds:5D25h
    memory16(_es, _di) &= _bx;                  //and es:[di], bx
    memory16(_es, _di) |= _ax;                  //or es:[di], ax
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_1A999
        goto loc_1A999;
    memory(_es, 0x42E7) -= 1;                   //dec byte ptr es:42E7h
    if (memory(_es, 0x42E7) == 0)               //jz short loc_1A9B9
        goto loc_1A9B9;
    _dx += 0x0002;                              //add dx, 2
    goto loc_1A954;                             //jmp short loc_1A954
loc_1A9B9:                                      //loc_1A9B9:
    _bp += 1;                                   //inc bp
}

void sub_1A9BB()
{
    unsigned char font[] = {
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x81, 0xa5, 0x81,
      0xbd, 0x99, 0x81, 0x7e, 0x7e, 0xff, 0xdb, 0xff, 0xc3, 0xe7, 0xff, 0x7e,
      0x6c, 0xfe, 0xfe, 0xfe, 0x7c, 0x38, 0x10, 0x00, 0x10, 0x38, 0x7c, 0xfe,
      0x7c, 0x38, 0x10, 0x00, 0x38, 0x7c, 0x38, 0xfe, 0xfe, 0x7c, 0x38, 0x7c,
      0x10, 0x10, 0x38, 0x7c, 0xfe, 0x7c, 0x38, 0x7c, 0x00, 0x00, 0x18, 0x3c,
      0x3c, 0x18, 0x00, 0x00, 0xff, 0xff, 0xe7, 0xc3, 0xc3, 0xe7, 0xff, 0xff,
      0x00, 0x3c, 0x66, 0x42, 0x42, 0x66, 0x3c, 0x00, 0xff, 0xc3, 0x99, 0xbd,
      0xbd, 0x99, 0xc3, 0xff, 0x0f, 0x07, 0x0f, 0x7d, 0xcc, 0xcc, 0xcc, 0x78,
      0x3c, 0x66, 0x66, 0x66, 0x3c, 0x18, 0x7e, 0x18, 0x3f, 0x33, 0x3f, 0x30,
      0x30, 0x70, 0xf0, 0xe0, 0x7f, 0x63, 0x7f, 0x63, 0x63, 0x67, 0xe6, 0xc0,
      0x99, 0x5a, 0x3c, 0xe7, 0xe7, 0x3c, 0x5a, 0x99, 0x80, 0xe0, 0xf8, 0xfe,
      0xf8, 0xe0, 0x80, 0x00, 0x02, 0x0e, 0x3e, 0xfe, 0x3e, 0x0e, 0x02, 0x00,
      0x18, 0x3c, 0x7e, 0x18, 0x18, 0x7e, 0x3c, 0x18, 0x66, 0x66, 0x66, 0x66,
      0x66, 0x00, 0x66, 0x00, 0x7f, 0xdb, 0xdb, 0x7b, 0x1b, 0x1b, 0x1b, 0x00,
      0x3e, 0x63, 0x38, 0x6c, 0x6c, 0x38, 0xcc, 0x78, 0x00, 0x00, 0x00, 0x00,
      0x7e, 0x7e, 0x7e, 0x00, 0x18, 0x3c, 0x7e, 0x18, 0x7e, 0x3c, 0x18, 0xff,
      0x18, 0x3c, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x18,
      0x7e, 0x3c, 0x18, 0x00, 0x00, 0x18, 0x0c, 0xfe, 0x0c, 0x18, 0x00, 0x00,
      0x00, 0x30, 0x60, 0xfe, 0x60, 0x30, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0,
      0xc0, 0xfe, 0x00, 0x00, 0x00, 0x24, 0x66, 0xff, 0x66, 0x24, 0x00, 0x00,
      0x00, 0x18, 0x3c, 0x7e, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7e,
      0x3c, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x30, 0x78, 0x78, 0x30, 0x30, 0x00, 0x30, 0x00, 0x6c, 0x6c, 0x6c, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x6c, 0x6c, 0xfe, 0x6c, 0xfe, 0x6c, 0x6c, 0x00,
      0x30, 0x7c, 0xc0, 0x78, 0x0c, 0xf8, 0x30, 0x00, 0x00, 0xc6, 0xcc, 0x18,
      0x30, 0x66, 0xc6, 0x00, 0x38, 0x6c, 0x38, 0x76, 0xdc, 0xcc, 0x76, 0x00,
      0x60, 0x60, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x30, 0x60, 0x60,
      0x60, 0x30, 0x18, 0x00, 0x60, 0x30, 0x18, 0x18, 0x18, 0x30, 0x60, 0x00,
      0x00, 0x66, 0x3c, 0xff, 0x3c, 0x66, 0x00, 0x00, 0x00, 0x30, 0x30, 0xfc,
      0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x60,
      0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x30, 0x30, 0x00, 0x06, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0x80, 0x00,
      0x7c, 0xc6, 0xce, 0xde, 0xf6, 0xe6, 0x7c, 0x00, 0x30, 0x70, 0x30, 0x30,
      0x30, 0x30, 0xfc, 0x00, 0x78, 0xcc, 0x0c, 0x38, 0x60, 0xcc, 0xfc, 0x00,
      0x78, 0xcc, 0x0c, 0x38, 0x0c, 0xcc, 0x78, 0x00, 0x1c, 0x3c, 0x6c, 0xcc,
      0xfe, 0x0c, 0x1e, 0x00, 0xfc, 0xc0, 0xf8, 0x0c, 0x0c, 0xcc, 0x78, 0x00,
      0x38, 0x60, 0xc0, 0xf8, 0xcc, 0xcc, 0x78, 0x00, 0xfc, 0xcc, 0x0c, 0x18,
      0x30, 0x30, 0x30, 0x00, 0x78, 0xcc, 0xcc, 0x78, 0xcc, 0xcc, 0x78, 0x00,
      0x78, 0xcc, 0xcc, 0x7c, 0x0c, 0x18, 0x70, 0x00, 0x00, 0x30, 0x30, 0x00,
      0x00, 0x30, 0x30, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x30, 0x30, 0x60,
      0x18, 0x30, 0x60, 0xc0, 0x60, 0x30, 0x18, 0x00, 0x00, 0x00, 0xfc, 0x00,
      0x00, 0xfc, 0x00, 0x00, 0x60, 0x30, 0x18, 0x0c, 0x18, 0x30, 0x60, 0x00,
      0x78, 0xcc, 0x0c, 0x18, 0x30, 0x00, 0x30, 0x00, 0x7c, 0xc6, 0xde, 0xde,
      0xde, 0xc0, 0x78, 0x00, 0x30, 0x78, 0xcc, 0xcc, 0xfc, 0xcc, 0xcc, 0x00,
      0xfc, 0x66, 0x66, 0x7c, 0x66, 0x66, 0xfc, 0x00, 0x3c, 0x66, 0xc0, 0xc0,
      0xc0, 0x66, 0x3c, 0x00, 0xf8, 0x6c, 0x66, 0x66, 0x66, 0x6c, 0xf8, 0x00,
      0xfe, 0x62, 0x68, 0x78, 0x68, 0x62, 0xfe, 0x00, 0xfe, 0x62, 0x68, 0x78,
      0x68, 0x60, 0xf0, 0x00, 0x3c, 0x66, 0xc0, 0xc0, 0xce, 0x66, 0x3e, 0x00,
      0xcc, 0xcc, 0xcc, 0xfc, 0xcc, 0xcc, 0xcc, 0x00, 0x78, 0x30, 0x30, 0x30,
      0x30, 0x30, 0x78, 0x00, 0x1e, 0x0c, 0x0c, 0x0c, 0xcc, 0xcc, 0x78, 0x00,
      0xe6, 0x66, 0x6c, 0x78, 0x6c, 0x66, 0xe6, 0x00, 0xf0, 0x60, 0x60, 0x60,
      0x62, 0x66, 0xfe, 0x00, 0xc6, 0xee, 0xfe, 0xfe, 0xd6, 0xc6, 0xc6, 0x00,
      0xc6, 0xe6, 0xf6, 0xde, 0xce, 0xc6, 0xc6, 0x00, 0x38, 0x6c, 0xc6, 0xc6,
      0xc6, 0x6c, 0x38, 0x00, 0xfc, 0x66, 0x66, 0x7c, 0x60, 0x60, 0xf0, 0x00,
      0x78, 0xcc, 0xcc, 0xcc, 0xdc, 0x78, 0x1c, 0x00, 0xfc, 0x66, 0x66, 0x7c,
      0x6c, 0x66, 0xe6, 0x00, 0x78, 0xcc, 0xe0, 0x70, 0x1c, 0xcc, 0x78, 0x00,
      0xfc, 0xb4, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00, 0xcc, 0xcc, 0xcc, 0xcc,
      0xcc, 0xcc, 0xfc, 0x00, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0x78, 0x30, 0x00,
      0xc6, 0xc6, 0xc6, 0xd6, 0xfe, 0xee, 0xc6, 0x00, 0xc6, 0xc6, 0x6c, 0x38,
      0x38, 0x6c, 0xc6, 0x00, 0xcc, 0xcc, 0xcc, 0x78, 0x30, 0x30, 0x78, 0x00,
      0xfe, 0xc6, 0x8c, 0x18, 0x32, 0x66, 0xfe, 0x00, 0x78, 0x60, 0x60, 0x60,
      0x60, 0x60, 0x78, 0x00, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x02, 0x00,
      0x78, 0x18, 0x18, 0x18, 0x18, 0x18, 0x78, 0x00, 0x10, 0x38, 0x6c, 0xc6,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff,
      0x30, 0x30, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x0c,
      0x7c, 0xcc, 0x76, 0x00, 0xe0, 0x60, 0x60, 0x7c, 0x66, 0x66, 0xdc, 0x00,
      0x00, 0x00, 0x78, 0xcc, 0xc0, 0xcc, 0x78, 0x00, 0x1c, 0x0c, 0x0c, 0x7c,
      0xcc, 0xcc, 0x76, 0x00, 0x00, 0x00, 0x78, 0xcc, 0xfc, 0xc0, 0x78, 0x00,
      0x38, 0x6c, 0x60, 0xf0, 0x60, 0x60, 0xf0, 0x00, 0x00, 0x00, 0x76, 0xcc,
      0xcc, 0x7c, 0x0c, 0xf8, 0xe0, 0x60, 0x6c, 0x76, 0x66, 0x66, 0xe6, 0x00,
      0x30, 0x00, 0x70, 0x30, 0x30, 0x30, 0x78, 0x00, 0x0c, 0x00, 0x0c, 0x0c,
      0x0c, 0xcc, 0xcc, 0x78, 0xe0, 0x60, 0x66, 0x6c, 0x78, 0x6c, 0xe6, 0x00,
      0x70, 0x30, 0x30, 0x30, 0x30, 0x30, 0x78, 0x00, 0x00, 0x00, 0xcc, 0xfe,
      0xfe, 0xd6, 0xc6, 0x00, 0x00, 0x00, 0xf8, 0xcc, 0xcc, 0xcc, 0xcc, 0x00,
      0x00, 0x00, 0x78, 0xcc, 0xcc, 0xcc, 0x78, 0x00, 0x00, 0x00, 0xdc, 0x66,
      0x66, 0x7c, 0x60, 0xf0, 0x00, 0x00, 0x76, 0xcc, 0xcc, 0x7c, 0x0c, 0x1e,
      0x00, 0x00, 0xdc, 0x76, 0x66, 0x60, 0xf0, 0x00, 0x00, 0x00, 0x7c, 0xc0,
      0x78, 0x0c, 0xf8, 0x00, 0x10, 0x30, 0x7c, 0x30, 0x30, 0x34, 0x18, 0x00,
      0x00, 0x00, 0xcc, 0xcc, 0xcc, 0xcc, 0x76, 0x00, 0x00, 0x00, 0xcc, 0xcc,
      0xcc, 0x78, 0x30, 0x00, 0x00, 0x00, 0xc6, 0xd6, 0xfe, 0xfe, 0x6c, 0x00,
      0x00, 0x00, 0xc6, 0x6c, 0x38, 0x6c, 0xc6, 0x00, 0x00, 0x00, 0xcc, 0xcc,
      0xcc, 0x7c, 0x0c, 0xf8, 0x00, 0x00, 0xfc, 0x98, 0x30, 0x64, 0xfc, 0x00,
      0x1c, 0x30, 0x30, 0xe0, 0x30, 0x30, 0x1c, 0x00, 0x18, 0x18, 0x18, 0x00,
      0x18, 0x18, 0x18, 0x00, 0xe0, 0x30, 0x30, 0x1c, 0x30, 0x30, 0xe0, 0x00,
      0x76, 0xdc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x38, 0x6c,
      0xc6, 0xc6, 0xfe, 0x00, 0x78, 0xcc, 0xc0, 0xcc, 0x78, 0x18, 0x0c, 0x78,
      0x00, 0xcc, 0x00, 0xcc, 0xcc, 0xcc, 0x7e, 0x00, 0x1c, 0x00, 0x78, 0xcc,
      0xfc, 0xc0, 0x78, 0x00, 0x7e, 0xc3, 0x3c, 0x06, 0x3e, 0x66, 0x3f, 0x00,
      0xcc, 0x00, 0x78, 0x0c, 0x7c, 0xcc, 0x7e, 0x00, 0xe0, 0x00, 0x78, 0x0c,
      0x7c, 0xcc, 0x7e, 0x00, 0x30, 0x30, 0x78, 0x0c, 0x7c, 0xcc, 0x7e, 0x00,
      0x00, 0x00, 0x78, 0xc0, 0xc0, 0x78, 0x0c, 0x38, 0x7e, 0xc3, 0x3c, 0x66,
      0x7e, 0x60, 0x3c, 0x00, 0xcc, 0x00, 0x78, 0xcc, 0xfc, 0xc0, 0x78, 0x00,
      0xe0, 0x00, 0x78, 0xcc, 0xfc, 0xc0, 0x78, 0x00, 0xcc, 0x00, 0x70, 0x30,
      0x30, 0x30, 0x78, 0x00, 0x7c, 0xc6, 0x38, 0x18, 0x18, 0x18, 0x3c, 0x00,
      0xe0, 0x00, 0x70, 0x30, 0x30, 0x30, 0x78, 0x00, 0xc6, 0x38, 0x6c, 0xc6,
      0xfe, 0xc6, 0xc6, 0x00, 0x30, 0x30, 0x00, 0x78, 0xcc, 0xfc, 0xcc, 0x00,
      0x1c, 0x00, 0xfc, 0x60, 0x78, 0x60, 0xfc, 0x00, 0x00, 0x00, 0x7f, 0x0c,
      0x7f, 0xcc, 0x7f, 0x00, 0x3e, 0x6c, 0xcc, 0xfe, 0xcc, 0xcc, 0xce, 0x00,
      0x78, 0xcc, 0x00, 0x78, 0xcc, 0xcc, 0x78, 0x00, 0x00, 0xcc, 0x00, 0x78,
      0xcc, 0xcc, 0x78, 0x00, 0x00, 0xe0, 0x00, 0x78, 0xcc, 0xcc, 0x78, 0x00,
      0x78, 0xcc, 0x00, 0xcc, 0xcc, 0xcc, 0x7e, 0x00, 0x00, 0xe0, 0x00, 0xcc,
      0xcc, 0xcc, 0x7e, 0x00, 0x00, 0xcc, 0x00, 0xcc, 0xcc, 0x7c, 0x0c, 0xf8,
      0xc3, 0x18, 0x3c, 0x66, 0x66, 0x3c, 0x18, 0x00, 0xcc, 0x00, 0xcc, 0xcc,
      0xcc, 0xcc, 0x78, 0x00, 0x18, 0x18, 0x7e, 0xc0, 0xc0, 0x7e, 0x18, 0x18,
      0x38, 0x6c, 0x64, 0xf0, 0x60, 0xe6, 0xfc, 0x00, 0xcc, 0xcc, 0x78, 0xfc,
      0x30, 0xfc, 0x30, 0x30, 0xf8, 0xcc, 0xcc, 0xfa, 0xc6, 0xcf, 0xc6, 0xc7,
      0x0e, 0x1b, 0x18, 0x3c, 0x18, 0x18, 0xd8, 0x70, 0x1c, 0x00, 0x78, 0x0c,
      0x7c, 0xcc, 0x7e, 0x00, 0x38, 0x00, 0x70, 0x30, 0x30, 0x30, 0x78, 0x00,
      0x00, 0x1c, 0x00, 0x78, 0xcc, 0xcc, 0x78, 0x00, 0x00, 0x1c, 0x00, 0xcc,
      0xcc, 0xcc, 0x7e, 0x00, 0x00, 0xf8, 0x00, 0xf8, 0xcc, 0xcc, 0xcc, 0x00,
      0xfc, 0x00, 0xcc, 0xec, 0xfc, 0xdc, 0xcc, 0x00, 0x3c, 0x6c, 0x6c, 0x3e,
      0x00, 0x7e, 0x00, 0x00, 0x38, 0x6c, 0x6c, 0x38, 0x00, 0x7c, 0x00, 0x00,
      0x30, 0x00, 0x30, 0x60, 0xc0, 0xcc, 0x78, 0x00, 0x00, 0x00, 0x00, 0xfc,
      0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x0c, 0x0c, 0x00, 0x00,
      0xc3, 0xc6, 0xcc, 0xde, 0x33, 0x66, 0xcc, 0x0f, 0xc3, 0xc6, 0xcc, 0xdb,
      0x37, 0x6f, 0xcf, 0x03, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x18, 0x00,
      0x00, 0x33, 0x66, 0xcc, 0x66, 0x33, 0x00, 0x00, 0x00, 0xcc, 0x66, 0x33,
      0x66, 0xcc, 0x00, 0x00, 0x22, 0x88, 0x22, 0x88, 0x22, 0x88, 0x22, 0x88,
      0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0xdb, 0x77, 0xdb, 0xee,
      0xdb, 0x77, 0xdb, 0xee, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
      0x18, 0x18, 0x18, 0x18, 0xf8, 0x18, 0x18, 0x18, 0x18, 0x18, 0xf8, 0x18,
      0xf8, 0x18, 0x18, 0x18, 0x36, 0x36, 0x36, 0x36, 0xf6, 0x36, 0x36, 0x36,
      0x00, 0x00, 0x00, 0x00, 0xfe, 0x36, 0x36, 0x36, 0x00, 0x00, 0xf8, 0x18,
      0xf8, 0x18, 0x18, 0x18, 0x36, 0x36, 0xf6, 0x06, 0xf6, 0x36, 0x36, 0x36,
      0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x00, 0x00, 0xfe, 0x06,
      0xf6, 0x36, 0x36, 0x36, 0x36, 0x36, 0xf6, 0x06, 0xfe, 0x00, 0x00, 0x00,
      0x36, 0x36, 0x36, 0x36, 0xfe, 0x00, 0x00, 0x00, 0x18, 0x18, 0xf8, 0x18,
      0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x18, 0x18, 0x18,
      0x18, 0x18, 0x18, 0x18, 0x1f, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18,
      0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x18, 0x18, 0x18,
      0x18, 0x18, 0x18, 0x18, 0x1f, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00,
      0xff, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0xff, 0x18, 0x18, 0x18,
      0x18, 0x18, 0x1f, 0x18, 0x1f, 0x18, 0x18, 0x18, 0x36, 0x36, 0x36, 0x36,
      0x37, 0x36, 0x36, 0x36, 0x36, 0x36, 0x37, 0x30, 0x3f, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x3f, 0x30, 0x37, 0x36, 0x36, 0x36, 0x36, 0x36, 0xf7, 0x00,
      0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xf7, 0x36, 0x36, 0x36,
      0x36, 0x36, 0x37, 0x30, 0x37, 0x36, 0x36, 0x36, 0x00, 0x00, 0xff, 0x00,
      0xff, 0x00, 0x00, 0x00, 0x36, 0x36, 0xf7, 0x00, 0xf7, 0x36, 0x36, 0x36,
      0x18, 0x18, 0xff, 0x00, 0xff, 0x00, 0x00, 0x00, 0x36, 0x36, 0x36, 0x36,
      0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0xff, 0x18, 0x18, 0x18,
      0x00, 0x00, 0x00, 0x00, 0xff, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36,
      0x3f, 0x00, 0x00, 0x00, 0x18, 0x18, 0x1f, 0x18, 0x1f, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x1f, 0x18, 0x1f, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00,
      0x3f, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0xff, 0x36, 0x36, 0x36,
      0x18, 0x18, 0xff, 0x18, 0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
      0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x18, 0x18, 0x18,
      0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
      0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
      0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0xff, 0xff, 0xff, 0xff,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x76, 0xdc, 0xc8, 0xdc, 0x76, 0x00,
      0x00, 0x78, 0xcc, 0xf8, 0xcc, 0xf8, 0xc0, 0xc0, 0x00, 0xfc, 0xcc, 0xc0,
      0xc0, 0xc0, 0xc0, 0x00, 0x00, 0xfe, 0x6c, 0x6c, 0x6c, 0x6c, 0x6c, 0x00,
      0xfc, 0xcc, 0x60, 0x30, 0x60, 0xcc, 0xfc, 0x00, 0x00, 0x00, 0x7e, 0xd8,
      0xd8, 0xd8, 0x70, 0x00, 0x00, 0x66, 0x66, 0x66, 0x66, 0x7c, 0x60, 0xc0,
      0x00, 0x76, 0xdc, 0x18, 0x18, 0x18, 0x18, 0x00, 0xfc, 0x30, 0x78, 0xcc,
      0xcc, 0x78, 0x30, 0xfc, 0x38, 0x6c, 0xc6, 0xfe, 0xc6, 0x6c, 0x38, 0x00,
      0x38, 0x6c, 0xc6, 0xc6, 0x6c, 0x6c, 0xee, 0x00, 0x1c, 0x30, 0x18, 0x7c,
      0xcc, 0xcc, 0x78, 0x00, 0x00, 0x00, 0x7e, 0xdb, 0xdb, 0x7e, 0x00, 0x00,
      0x06, 0x0c, 0x7e, 0xdb, 0xdb, 0x7e, 0x60, 0xc0, 0x38, 0x60, 0xc0, 0xf8,
      0xc0, 0x60, 0x38, 0x00, 0x78, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0x00,
      0x00, 0xfc, 0x00, 0xfc, 0x00, 0xfc, 0x00, 0x00, 0x30, 0x30, 0xfc, 0x30,
      0x30, 0x00, 0xfc, 0x00, 0x60, 0x30, 0x18, 0x30, 0x60, 0x00, 0xfc, 0x00,
      0x18, 0x30, 0x60, 0x30, 0x18, 0x00, 0xfc, 0x00, 0x0e, 0x1b, 0x1b, 0x18,
      0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xd8, 0xd8, 0x70,
      0x30, 0x30, 0x00, 0xfc, 0x00, 0x30, 0x30, 0x00, 0x00, 0x76, 0xdc, 0x00,
      0x76, 0xdc, 0x00, 0x00, 0x38, 0x6c, 0x6c, 0x38, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x18, 0x00, 0x00, 0x00, 0x0f, 0x0c, 0x0c, 0x0c, 0xec, 0x6c, 0x3c, 0x1c,
      0x78, 0x6c, 0x6c, 0x6c, 0x6c, 0x00, 0x00, 0x00, 0x70, 0x18, 0x30, 0x60,
      0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    //unsigned int font_len = 2048;

    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _cx = _ds;                                  //mov cx, ds
    _es = _cx;                                  //mov es, cx
    _cx = 0xf000;                               //mov cx, 0F000h
    _ds = _cx;                                  //mov ds, cx
    _cx = 0x01d8;                               //mov cx, 1D8h
    _si = 0xfa6e;                               //mov si, 0FA6Eh
    _si += 0x0100;                              //add si, 100h
    _di = 0x7cbc;                               //mov di, 7CBCh
//std::cout << "Ignore BIOS ROM read!?\n";
    //The 8x8 font is at F000:FA6Eh
    //gabo??????
    for (int i=0; i<_cx; i++)
        memory(_es, _di+i) = font[i+0x100];
    //_rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_1A9D8()
{
    WORD _cs = _seg003;

    _push(_es);                                 //push es
    _cx = 0xa000;                               //mov cx, 0A000h
    _es = _cx;                                  //mov es, cx
    _al = 0x02;                                 //mov al, 2
    sub_188CD();                                //call sub_188CD
    _al = 0x0f;                                 //mov al, 0Fh
    sub_188B9();                                //call sub_188B9
    _al = memory(_ds, _bp + 0);                 //mov al, ds:[bp+0]
    memory(_cs, 0x201A) = _al;                  //mov cs:byte_1A3AA, al
loc_1A9F0:                                      //loc_1A9F0:
    _bp += 1;                                   //inc bp
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bl = memory(_ds, _bp + 0);                 //mov bl, ds:[bp+0]
    if ((char)_bl > (char)0x7a)                 //jg short loc_1AA11
        goto loc_1AA11;
    if ((char)_bl <= (char)0x5a)                //jle short loc_1AA04
        goto loc_1AA04;
    _bl -= 0x20;                                //sub bl, 20h
loc_1AA04:                                      //loc_1AA04:
    _flags.carry = (char)_bl < 0x20;
    _bl -= 0x20;                                //sub bl, 20h
    if (_flags.carry)                                //jl short loc_1AA11
        goto loc_1AA11;
    if ((char)_bl > (char)0x5a)                 //jg short loc_1AA11
        goto loc_1AA11;
    goto loc_1AA13;                             //jmp short loc_1AA13
    _STOP_("db 90h");                           //db 90h
loc_1AA11:                                      //loc_1AA11:
    _bl = _bl ^ _bl;                            //xor bl, bl
loc_1AA13:                                      //loc_1AA13:
    _cl = 0x03;                                 //mov cl, 3
    _bx <<= _cl;                                //shl bx, cl
    _si = 0x7cbc;                               //mov si, 7CBCh
    _si += _bx;                                 //add si, bx
    _dx = memory16(_cs, 0x2016);                //mov dx, cs:word_1A3A6
    _ax = memory16(_cs, 0x2018);                //mov ax, cs:word_1A3A8
    _dh = _al;                                  //mov dh, al
    sub_189A1();                                //call sub_189A1
    _cx = 0x0008;                               //mov cx, 8
loc_1AA2D:                                      //loc_1AA2D:
    _dx = 0x03ce;                               //mov dx, 3CEh
    _al = 0x08;                                 //mov al, 8
    if (memory(_ds, 0x6471) == 0x01)            //jz short loc_1AA3A
        goto loc_1AA3A;
    _out(_dx, _al);                             //out dx, al
loc_1AA3A:                                      //loc_1AA3A:
    _dx += 1;                                   //inc dx
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    if (memory(_ds, 0x6471) == 0x01)            //jz short loc_1AA44
        goto loc_1AA44;
    _out(_dx, _al);                             //out dx, al
loc_1AA44:                                      //loc_1AA44:
    _al = memoryVideoGet(_es, _di);                     //mov al, es:[di]
    _al = memory(_cs, 0x201B);                  //mov al, cs:byte_1A3AB
    memoryVideoSet(_es, _di, _al);                     //mov es:[di], al
    _di = _di + memory16(_cs, 0x5C6);           //add di, cs:word_18956
    if (--_cx)                                  //loop loc_1AA2D
        goto loc_1AA2D;
    memory(_cs, 0x201A) -= 1;                   //dec cs:byte_1A3AA
    if (memory(_cs, 0x201A) == 0)               //jz short loc_1AA64
        goto loc_1AA64;
    memory16(_cs, 0x2016) += 0x0001;            //add cs:word_1A3A6, 1
    goto loc_1A9F0;                             //jmp short loc_1A9F0
loc_1AA64:                                      //loc_1AA64:
    _es = _pop();                               //pop es
    //gabo?
    _flags.carry = (_bp == 0xffff);
    _bp += 1;                                   //inc bp
}

void sub_1AA67()
{
    _dx = memory16(_es, 0x42E2);                //mov dx, es:42E2h
    _al = memory(_ds, _bp + 0);                 //mov al, ds:[bp+0]
    memory(_es, 0x42E7) = _al;                  //mov es:42E7h, al
loc_1AA74:                                      //loc_1AA74:
    _bp += 1;                                   //inc bp
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bl = memory(_ds, _bp + 0);                 //mov bl, ds:[bp+0]
    if ((char)_bl > (char)0x7a)                 //jg short loc_1AA95
        goto loc_1AA95;
    if ((char)_bl <= (char)0x5a)                //jle short loc_1AA88
        goto loc_1AA88;
    _bl -= 0x20;                                //sub bl, 20h
loc_1AA88:                                      //loc_1AA88:
    _flags.carry = (char)_bl < 0x20;
    _bl -= 0x20;                                //sub bl, 20h
    if (_flags.carry)                                //jl short loc_1AA95
        goto loc_1AA95;
    if ((char)_bl > (char)0x5a)                 //jg short loc_1AA95
        goto loc_1AA95;
    goto loc_1AA97;                             //jmp short loc_1AA97
    _STOP_("db 90h");                           //db 90h
loc_1AA95:                                      //loc_1AA95:
    _bl = _bl ^ _bl;                            //xor bl, bl
loc_1AA97:                                      //loc_1AA97:
    _bl |= _bl;                                 //or bl, bl
    if (_bl == 0)                               //jz short loc_1AAA1
        goto loc_1AAA1;
    _si = 0x45c4;                               //mov si, 45C4h
    sub_1918B();                                //call sub_1918B
loc_1AAA1:                                      //loc_1AAA1:
    _cl = 0x04;                                 //mov cl, 4
    _bx <<= _cl;                                //shl bx, cl
    _si = 0x7ea4;                               //mov si, 7EA4h
    _si += _bx;                                 //add si, bx
    _ax = memory16(_es, 0x42E4);                //mov ax, es:42E4h
    _cl = 0x04;                                 //mov cl, 4
    _ax <<= _cl;                                //shl ax, cl
    _di = _ax;                                  //mov di, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _di += _dx;                                 //add di, dx
    _di += 0x0247;                              //add di, 247h
    _cx = 0x0008;                               //mov cx, 8
loc_1AAC3:                                      //loc_1AAC3:
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_es, _di) = memory16(_es, _di) ^ _ax;//xor es:[di], ax
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_1AAC3
        goto loc_1AAC3;
    _push(_bp);                                 //push bp
    _push(_dx);                                 //push dx
    sub_19C06();                                //call sub_19C06
    sub_19BCA();                                //call sub_19BCA
    if (memory(_ds, 0xCF) == 0x00)              //jz short loc_1AAE3
        goto loc_1AAE3;
    sub_185AC();                                //call sub_185AC
    if (_ah != 0x00)                            //jnz short loc_1AAE6
        goto loc_1AAE6;
loc_1AAE3:                                      //loc_1AAE3:
    sub_19C18();                                //call sub_19C18
loc_1AAE6:                                      //loc_1AAE6:
    if (_ah != 0x1f)                            //jnz short loc_1AAF3
        goto loc_1AAF3;
    memory(_ds, 0x5D11) = memory(_ds, 0x5D11) ^ 0x01;//xor byte ptr ds:5D11h, 1
    goto loc_1AB0E;                             //jmp short loc_1AB0E
    _STOP_("db 90h");                           //db 90h
loc_1AAF3:                                      //loc_1AAF3:
    if (_ah != 0x10)                            //jnz short loc_1AB00
        goto loc_1AB00;
    _dx = _pop();                               //pop dx
    _bp = _pop();                               //pop bp
    memory(_ds, 0x5E39) = 0x01;                 //mov byte ptr ds:5E39h, 1
    return;                                     //retn
loc_1AB00:                                      //loc_1AB00:
    if (_ah == 0xff)                            //jz short loc_1AB0E
        goto loc_1AB0E;
    _dx = _pop();                               //pop dx
    _bp = _pop();                               //pop bp
    memory16(_ds, 0x4306) = 0x0001;             //mov word ptr ds:4306h, 1
    return;                                     //retn
loc_1AB0E:                                      //loc_1AB0E:
    _cx = 0x3f80;                               //mov cx, 3F80h
loc_1AB11:                                      //loc_1AB11:
    if (--_cx)                                  //loop loc_1AB11
        goto loc_1AB11;
    _dx = _pop();                               //pop dx
    _bp = _pop();                               //pop bp
    memory(_es, 0x42E7) -= 1;                   //dec byte ptr es:42E7h
    if (memory(_es, 0x42E7) == 0)               //jz short loc_1AB22
        goto loc_1AB22;
    _dx += 0x0002;                              //add dx, 2
    goto loc_1AA74;                             //jmp loc_1AA74
loc_1AB22:                                      //loc_1AB22:
    _bp += 1;                                   //inc bp
}

void sub_1AB24()
{
    _ah = _ah ^ _ah;                            //xor ah, ah
    _interrupt(26);                             //int 1Ah
    _flags.carry = (_dx + 0x9428) >= 0x10000;
    _dx += 0x9428;                              //add dx, 9428h
    _cl = 0x03;                                 //mov cl, 3
    _rcr(_dx, _cl);//rcr dx, cl
    _dx += 0xf123;                              //add dx, 0F123h
    _cx = _dx;                                  //mov cx, dx
    _cx &= 0x0007;                              //and cx, 7
    _cx += 0x0005;                              //add cx, 5
}

void sub_1AB3E()
{
    //GABO
    std::cout << "unk carry\n";
    _dx = memory16(_ds, 0x4289);                //mov dx, ds:4289h
    bool carry2  = (_dx + 0x9428 + _flags.carry) > 0x10000;
    _dx = _dx + 0x9428 + _flags.carry; //adc dx, 9428h
    _cl = 0x03;                                 //mov cl, 3
    _flags.carry = carry2;
    _rcr(_dx, _cl);//rcr dx, cl
    _dx += 0x1357;                              //add dx, 1357h
    _ax = _dx;                                  //mov ax, dx
    _ax &= 0x07ff;                              //and ax, 7FFh
    _al = _ah;                                  //mov al, ah
    _cbw();                                     //cbw
    memory16(_ds, 0x4289) = _dx;                //mov ds:4289h, dx
    _flags.carry = !!(_dl & 0x80);              //shl dl, 1
    _dl <<= 1;
    if (!_flags.carry)                          //jnb short locret_1AB60
        goto locret_1AB60;
    _ax = -_ax;                                 //neg ax
locret_1AB60:                                   //locret_1AB60:
    return;
}

void sub_1AB61()
{
    _dx = 0x40f2;                               //mov dx, 40F2h
    _bp = 0x41b0;                               //mov bp, 41B0h
    memory16(_ds, 0x4604) = 0x0000;             //mov word ptr ds:4604h, 0
    memory16(_ds, 0x42E4) = 0x0014;             //mov word ptr ds:42E4h, 14h
loc_1AB73:                                      //loc_1AB73:
    _si = _bp;                                  //mov si, bp
    _cx = 0x000a;                               //mov cx, 0Ah
    _ah = _ah ^ _ah;                            //xor ah, ah
    memory16(_ds, 0x42E4) -= 1;                 //dec word ptr ds:42E4h
loc_1AB7E:                                      //loc_1AB7E:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _al |= _ah;                                 //or al, ah
    if (_al == 0)                               //jz short loc_1AB89
        goto loc_1AB89;
    _cx -= 1;                                   //dec cx
    if (_cx != 0)                               //jnz short loc_1AB7E
        goto loc_1AB7E;
    goto loc_1ABA7;                             //jmp short loc_1ABA7
    _STOP_("db 90h");                           //db 90h
loc_1AB89:                                      //loc_1AB89:
    _bp -= 0x000a;                              //sub bp, 0Ah
    if ((short)_bp >= (short)_dx)               //jge short loc_1AB73
        goto loc_1AB73;
    if (_dx != 0x40f2)                          //jnz short loc_1AB99
        goto loc_1AB99;
    goto locret_1ABFB;                          //jmp short locret_1ABFB
    _STOP_("db 90h");                           //db 90h
loc_1AB99:                                      //loc_1AB99:
    _cx = _dx;                                  //mov cx, dx
    _di = 0x40f2;                               //mov di, 40F2h
    _cx -= _di;                                 //sub cx, di
    _ax = _ax ^ _ax;                            //xor ax, ax
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    goto locret_1ABFB;                          //jmp short locret_1ABFB
    _STOP_("db 90h");                           //db 90h
loc_1ABA7:                                      //loc_1ABA7:
    _cx = memory16(_ds, 0x42E4);                //mov cx, ds:42E4h
    _bx = memory16(_ds, 0x4604);                //mov bx, ds:4604h
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 17926) = _cx;           //mov [bx+4606h], cx
    memory16(_ds, 0x4604) += 1;                 //inc word ptr ds:4604h
    memory16(_ds, 0x40E8) += 1;                 //inc word ptr ds:40E8h
    if (_bp != _dx)                             //jnz short loc_1ABDC
        goto loc_1ABDC;
    _ax = _ax ^ _ax;                            //xor ax, ax
    _di = _bp;                                  //mov di, bp
    _cx = 0x0005;                               //mov cx, 5
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _dx = 0x40f2;                               //mov dx, 40F2h
    if (_dx == _bp)                             //jz short locret_1ABFB
        goto locret_1ABFB;
    _di = _dx;                                  //mov di, dx
    _cx = _bp;                                  //mov cx, bp
    _cx -= _dx;                                 //sub cx, dx
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    goto locret_1ABFB;                          //jmp short locret_1ABFB
loc_1ABDC:                                      //loc_1ABDC:
    _bx = _bp;                                  //mov bx, bp
    _ax = _bp;                                  //mov ax, bp
loc_1ABE0:                                      //loc_1ABE0:
    _ax -= 0x000a;                              //sub ax, 0Ah
    _si = _ax;                                  //mov si, ax
    _di = _bx;                                  //mov di, bx
    _cx = 0x0005;                               //mov cx, 5
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    if ((short)_ax <= (short)_dx)               //jle short loc_1ABF5
        goto loc_1ABF5;
    _bx -= 0x000a;                              //sub bx, 0Ah
    goto loc_1ABE0;                             //jmp short loc_1ABE0
loc_1ABF5:                                      //loc_1ABF5:
    _dx += 0x000a;                              //add dx, 0Ah
    goto loc_1AB73;                             //jmp loc_1AB73
locret_1ABFB:                                   //locret_1ABFB:
    return;
}

void sub_1ABFC()
{
    if (memory(_ds, 0x4282) != 0x00)            //jnz short loc_1AC04
        goto loc_1AC04;
    return;                                     //retn
loc_1AC04:                                      //loc_1AC04:
    _si = memory16(_ds, 0x42A6);                //mov si, ds:42A6h
    _di = 0x40f2;                               //mov di, 40F2h
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_ds, 0x4282);                  //mov al, ds:4282h
    _al -= 1;                                   //dec al
    _di += _ax;                                 //add di, ax
    _al = memory(_ds, 0x4283);                  //mov al, ds:4283h
    _bx = 0x000a;                               //mov bx, 0Ah
    _mul(_bx);                                  //mul bx
    _di += _ax;                                 //add di, ax
    _bx = _di;                                  //mov bx, di
    _dh = _dh ^ _dh;                            //xor dh, dh
    _dl = memory(_ds, _si);                     //mov dl, [si]
    memory16(_ds, 0x23F) = _dx;                 //mov ds:23Fh, dx
    _dh = memory(_ds, _si + 1);                 //mov dh, [si+1]
    _si += 0x0002;                              //add si, 2
    _bp = _si;                                  //mov bp, si
loc_1AC30:                                      //loc_1AC30:
    _cl = _dh;                                  //mov cl, dh
loc_1AC32:                                      //loc_1AC32:
    if (memory(_es, _di) == 0x00)               //jz short loc_1AC40
        goto loc_1AC40;
    if (memory(_ds, _si) == 0x00)               //jz short loc_1AC40
        goto loc_1AC40;
    goto locret_1AC59;                          //jmp short locret_1AC59
loc_1AC40:                                      //loc_1AC40:
    _si = _si + memory16(_ds, 0x23F);           //add si, ds:23Fh
    _di += 0x000a;                              //add di, 0Ah
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_1AC32
        goto loc_1AC32;
    _bx += 1;                                   //inc bx
    _bp += 1;                                   //inc bp
    _si = _bp;                                  //mov si, bp
    _di = _bx;                                  //mov di, bx
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_1AC30
        goto loc_1AC30;
    memory(_ds, 0x4282) -= 1;                   //dec byte ptr ds:4282h
locret_1AC59:                                   //locret_1AC59:
    return;
}

void loc_1AC7A()
{
loc_1AC7A:
    _push(_di);                                 //push di
    _cl = memory(_ds, 0x42A5);                  //mov cl, ds:42A5h
    _bx = _bx ^ _bx;                            //xor bx, bx
loc_1AC81:                                      //loc_1AC81:
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _bl = memory(_ds, _bp + 0);                 //mov bl, ds:[bp+0]
    _bx <<= 1;                                  //shl bx, 1
    _si = memory16(_ds, _bx + 288);             //mov si, [bx+120h]
    _ch = 0x08;                                 //mov ch, 8
loc_1AC8F:                                      //loc_1AC8F:
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    _stosw<MemAuto, DirAuto>();                 //stosw
    _di += 0x004e;                              //add di, 4Eh
    _ch -= 1;                                   //dec ch
    if (_ch != 0)                               //jnz short loc_1AC8F
        goto loc_1AC8F;
    _di = _pop();                               //pop di
    _di += 0x0002;                              //add di, 2
    _cx = _pop();                               //pop cx
    _bp += 1;                                   //inc bp
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_1AC81
        goto loc_1AC81;
    _di = _pop();                               //pop di
    _di += 0x0280;                              //add di, 280h
    _ch -= 1;                                   //dec ch
    if (_ch == 0)                               //jz short locret_1ACAD
        goto locret_1ACAD;
    goto loc_1AC7A;                             //jmp short loc_1AC7A
locret_1ACAD:                                   //locret_1ACAD:
    return;
}

void sub_1ACAE()
{
    _push(_es);                                 //push es
    _cx = 0xa000;                               //mov cx, 0A000h
    _es = _cx;                                  //mov es, cx
    sub_189A1();                                //call sub_189A1
    _ch = _ah;                                  //mov ch, ah
    memory(_ds, 0x42A5) = _al;                  //mov ds:42A5h, al
    _al = 0x01;                                 //mov al, 1
    sub_188CD();                                //call sub_188CD
    _al = 0xff;                                 //mov al, 0FFh
    sub_188E1();                                //call sub_188E1
    _al = 0x0f;                                 //mov al, 0Fh
    sub_188B9();                                //call sub_188B9
loc_1ACCB:                                      //loc_1ACCB:
    _push(_di);                                 //push di
    _cl = memory(_ds, 0x42A5);                  //mov cl, ds:42A5h
    _bx = _bx ^ _bx;                            //xor bx, bx
loc_1ACD2:                                      //loc_1ACD2:
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _bl = memory(_ds, _bp + 0);                 //mov bl, ds:[bp+0]
    _bx <<= 1;                                  //shl bx, 1
    _si = memory16(_ds, _bx + 208);             //mov si, [bx+0D0h]
    _ch = 0x08;                                 //mov ch, 8
loc_1ACE0:                                      //loc_1ACE0:
    _al = memoryVideoGet(_es, _si);                     //mov al, es:[si]
    _si += 1;                                   //inc si
    _stosb<MemAuto, DirAuto>();                 //stosb
    _di += 0x0027;                              //add di, 27h
    _ch -= 1;                                   //dec ch
    if (_ch != 0)                               //jnz short loc_1ACE0
        goto loc_1ACE0;
    _di = _pop();                               //pop di
    _di += 0x0001;                              //add di, 1
    _cx = _pop();                               //pop cx
    _bp += 1;                                   //inc bp
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_1ACD2
        goto loc_1ACD2;
    _di = _pop();                               //pop di
    _di += 0x0140;                              //add di, 140h
    _ch -= 1;                                   //dec ch
    if (_ch == 0)                               //jz short loc_1AD01
    {
        // gabo
        _flags.carry = false;
        goto loc_1AD01;
    }
    goto loc_1ACCB;                             //jmp short loc_1ACCB
loc_1AD01:                                      //loc_1AD01:
    _es = _pop();                               //pop es
}

void sub_1AD03()
{
    WORD _cs = _seg003;

    _push(_es);                                 //push es
    _cx = 0xa000;                               //mov cx, 0A000h
    _es = _cx;                                  //mov es, cx
    _cx = _cx ^ _cx;                            //xor cx, cx
    memory16(_ds, 0x4306) = _di;                //mov ds:4306h, di
    _di = _di + memory16(_cs, 0x320);           //add di, cs:word_186B0
    _ch = _ah;                                  //mov ch, ah
    memory(_ds, 0x42A5) = _al;                  //mov ds:42A5h, al
    _dx = _di;                                  //mov dx, di
    _al = 0x0f;                                 //mov al, 0Fh
    sub_188B9();                                //call sub_188B9
    _al = 0xff;                                 //mov al, 0FFh
    sub_188E1();                                //call sub_188E1
    _al = 0x01;                                 //mov al, 1
    sub_188CD();                                //call sub_188CD
loc_1AD2A:                                      //loc_1AD2A:
    _di = _dx;                                  //mov di, dx
    _cl = memory(_ds, 0x42A5);                  //mov cl, ds:42A5h
    _bx = _bx ^ _bx;                            //xor bx, bx
loc_1AD32:                                      //loc_1AD32:
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _bl = memory(_ds, _bp + 0);                 //mov bl, ds:[bp+0]
    _bl |= _bl;                                 //or bl, bl
    if (_bl == 0)                               //jz short loc_1AD58
        goto loc_1AD58;
    _bx <<= 1;                                  //shl bx, 1
    _si = memory16(_ds, 0x140);                 //mov si, ds:140h
    _si <<= 1;                                  //shl si, 1
    _si = memory16(_ds, _si + 327);             //mov si, [si+147h]
    _si = memory16(_ds, _bx + _si);             //mov si, [bx+si]
    _ch = 0x08;                                 //mov ch, 8
loc_1AD4C:                                      //loc_1AD4C:
    _al = memoryVideoGet(_es, _si);                     //mov al, es:[si]
    _si += 1;                                   //inc si
    _stosb<MemAuto, DirAuto>();                 //stosb
    _di += 0x0027;                              //add di, 27h
    _ch -= 1;                                   //dec ch
    if (_ch != 0)                               //jnz short loc_1AD4C
        goto loc_1AD4C;
loc_1AD58:                                      //loc_1AD58:
    _di = _pop();                               //pop di
    _di += 0x0001;                              //add di, 1
    _cx = _pop();                               //pop cx
    _bp += 1;                                   //inc bp
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_1AD32
        goto loc_1AD32;
    _dx += 0x0140;                              //add dx, 140h
    _ch -= 1;                                   //dec ch
    if (_ch == 0)                               //jz short loc_1AD6C
        goto loc_1AD6C;
    goto loc_1AD2A;                             //jmp short loc_1AD2A
loc_1AD6C:                                      //loc_1AD6C:
    memory16(_ds, 0x140) = memory16(_ds, 0x140) ^ 0x0001;
    _es = _pop();                               //pop es
}

void sub_1AD74()
{
    _si = memory16(_ds, 0x42A6);                //mov si, ds:42A6h
    _ch = _ch ^ _ch;                            //xor ch, ch
    _cl = memory(_ds, 0x4282);                  //mov cl, ds:4282h
    _di = 0x40f2;                               //mov di, 40F2h
    _di += _cx;                                 //add di, cx
    _ah = _ah ^ _ah;                            //xor ah, ah
    _al = memory(_ds, 0x4283);                  //mov al, ds:4283h
    if (_al != 0x13)                            //jnz short loc_1AD94
        goto loc_1AD94;
    if (memory(_ds, _si + 1) == 0x01)           //jz short loc_1AD94
        goto loc_1AD94;
    _al -= 1;                                   //dec al
loc_1AD94:                                      //loc_1AD94:
    _bx = 0x000a;                               //mov bx, 0Ah
    _mul(_bx);                                  //mul bx
    _di += _ax;                                 //add di, ax
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _dh = _al;                                  //mov dh, al
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _dl = _al;                                  //mov dl, al
    _cl = _dh;                                  //mov cl, dh
    memory16(_ds, 0x23F) = 0x000a;              //mov word ptr ds:23Fh, 0Ah
    memory16(_ds, 0x23F) -= _cx;                //sub ds:23Fh, cx
    if (memory(_ds, 0x4283) != 0x00)            //jnz short loc_1ADB7
        goto loc_1ADB7;
    goto loc_1ADD5;                             //jmp short loc_1ADD5
    _STOP_("db 90h");                           //db 90h
loc_1ADB7:                                      //loc_1ADB7:
    _cl = _dh;                                  //mov cl, dh
loc_1ADB9:                                      //loc_1ADB9:
    if (memory(_es, _di) != 0x00)               //jnz short loc_1ADC4
        goto loc_1ADC4;
    _al = memory(_ds, _si);                     //mov al, [si]
    memory(_es, _di) = _al;                     //mov es:[di], al
loc_1ADC4:                                      //loc_1ADC4:
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_1ADB9
        goto loc_1ADB9;
    _di = _di + memory16(_ds, 0x23F);           //add di, ds:23Fh
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_1ADB7
        goto loc_1ADB7;
    goto locret_1ADF8;                          //jmp short locret_1ADF8
    _STOP_("db 90h");                           //db 90h
loc_1ADD5:                                      //loc_1ADD5:
    _cl = _dh;                                  //mov cl, dh
loc_1ADD7:                                      //loc_1ADD7:
    if (memory(_es, _di) == 0x00)               //jz short loc_1ADE5
        goto loc_1ADE5;
    if (memory(_ds, _si) != 0x00)               //jnz short loc_1ADE5
        goto loc_1ADE5;
    goto loc_1ADEA;                             //jmp short loc_1ADEA
    _STOP_("db 90h");                           //db 90h
loc_1ADE5:                                      //loc_1ADE5:
    _al = memory(_ds, _si);                     //mov al, [si]
    memory(_es, _di) = _al;                     //mov es:[di], al
loc_1ADEA:                                      //loc_1ADEA:
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_1ADD7
        goto loc_1ADD7;
    _di = _di + memory16(_ds, 0x23F);           //add di, ds:23Fh
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_1ADD5
        goto loc_1ADD5;
locret_1ADF8:                                   //locret_1ADF8:
    return;
}

void sub_1ADF9()
{
    _si = memory16(_ds, 0x42A6);                //mov si, ds:42A6h
    _al = memory(_ds, _si);                     //mov al, [si]
    _al = _al + memory(_ds, 0x4282);            //add al, ds:4282h
    if ((char)_al <= (char)0x09)                //jle short loc_1AE08
        goto loc_1AE08;
    return;                                     //retn
loc_1AE08:                                      //loc_1AE08:
    _di = 0x40f2;                               //mov di, 40F2h
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_ds, 0x4283);                  //mov al, ds:4283h
    _bx = 0x000a;                               //mov bx, 0Ah
    _mul(_bx);                                  //mul bx
    _di += _ax;                                 //add di, ax
    _dx = _dx ^ _dx;                            //xor dx, dx
    _dl = memory(_ds, 0x4282);                  //mov dl, ds:4282h
    _di += _dx;                                 //add di, dx
    _dl = memory(_ds, _si);                     //mov dl, [si]
    _di += _dx;                                 //add di, dx
    memory16(_ds, 0x23F) = _dx;                 //mov ds:23Fh, dx
    _bx = _di;                                  //mov bx, di
    _dh = memory(_ds, _si + 1);                 //mov dh, [si+1]
    _si += 0x0001;                              //add si, 1
    _si = _si + memory16(_ds, 0x23F);           //add si, ds:23Fh
    _bp = _si;                                  //mov bp, si
loc_1AE35:                                      //loc_1AE35:
    _cl = _dh;                                  //mov cl, dh
loc_1AE37:                                      //loc_1AE37:
    if (memory(_ds, _di) == 0x00)               //jz short loc_1AE44
        goto loc_1AE44;
    if (memory(_ds, _si) == 0x00)               //jz short loc_1AE44
        goto loc_1AE44;
    goto locret_1AE5D;                          //jmp short locret_1AE5D
loc_1AE44:                                      //loc_1AE44:
    _si = _si + memory16(_ds, 0x23F);           //add si, ds:23Fh
    _di += 0x000a;                              //add di, 0Ah
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_1AE37
        goto loc_1AE37;
    _bx -= 1;                                   //dec bx
    _bp -= 1;                                   //dec bp
    _di = _bx;                                  //mov di, bx
    _si = _bp;                                  //mov si, bp
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_1AE35
        goto loc_1AE35;
    memory(_ds, 0x4282) += 1;                   //inc byte ptr ds:4282h
locret_1AE5D:                                   //locret_1AE5D:
    return;
}

void sub_1AE5E()
{
    if (memory(_ds, 0x243) != 0x01)             //jnz short loc_1AE66
        goto loc_1AE66;
    return;                                     //retn
loc_1AE66:                                      //loc_1AE66:
    _ax = _ax ^ _ax;                            //xor ax, ax
    _bx = memory16(_ds, 0x428B);                //mov bx, ds:428Bh
    _bx -= 1;                                   //dec bx
    _al = memory(_ds, 0x4285);                  //mov al, ds:4285h
    _al += 1;                                   //inc al
    if ((char)_al <= (char)memory(_ds, _bx + 17114))//jle short loc_1AE7A
        goto loc_1AE7A;
    _al = _al ^ _al;                            //xor al, al
loc_1AE7A:                                      //loc_1AE7A:
    _bx <<= 1;                                  //shl bx, 1
    _bp = memory16(_ds, _bx + 547);             //mov bp, [bx+223h]
    _si = memory16(_ds, _bx + 561);             //mov si, [bx+231h]
    _bp += _ax;                                 //add bp, ax
    _si += _ax;                                 //add si, ax
    _cl = memory(_ds, 0x4282);                  //mov cl, ds:4282h
    _cl = _cl + memory(_ds, _si);               //add cl, [si]
    if ((char)_cl >= (char)0x00)                //jge short loc_1AE94
        goto loc_1AE94;
    return;                                     //retn
loc_1AE94:                                      //loc_1AE94:
    memory(_ds, 0x246) = _cl;                   //mov ds:246h, cl
    _si = memory16(_ds, _bx + 515);             //mov si, [bx+203h]
    memory(_ds, 0x245) = _al;                   //mov ds:245h, al
    _ax <<= 1;                                  //shl ax, 1
    _si += _ax;                                 //add si, ax
    _si = memory16(_ds, _si);                   //mov si, [si]
    _cl = _cl + memory(_ds, _si);               //add cl, [si]
    _cl -= 1;                                   //dec cl
    if ((char)_cl <= (char)0x09)                //jle short loc_1AEAF
        goto loc_1AEAF;
    return;                                     //retn
loc_1AEAF:                                      //loc_1AEAF:
    _ch = memory(_ds, 0x4283);                  //mov ch, ds:4283h
    _ch = _ch + memory(_ds, _bp + 0);           //add ch, ds:[bp+0]
    memory(_ds, 0x4286) = _ch;                  //mov ds:4286h, ch
    _ch = _ch + memory(_ds, _si + 1);           //add ch, [si+1]
    if ((char)_ch <= (char)0x13)                //jle short loc_1AEC4
        goto loc_1AEC4;
    return;                                     //retn
loc_1AEC4:                                      //loc_1AEC4:
    _di = 0x40f2;                               //mov di, 40F2h
    _al = memory(_ds, 0x246);                   //mov al, ds:246h
    _di += _ax;                                 //add di, ax
    _al = memory(_ds, 0x4286);                  //mov al, ds:4286h
    _bx = 0x000a;                               //mov bx, 0Ah
    _mul(_bx);                                  //mul bx
    _di += _ax;                                 //add di, ax
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _ah = memory(_ds, _si);                     //mov ah, [si]
    _si += 1;                                   //inc si
    _dx = 0x000a;                               //mov dx, 0Ah
    _dl -= _al;                                 //sub dl, al
loc_1AEDF:                                      //loc_1AEDF:
    _cl = _al;                                  //mov cl, al
loc_1AEE1:                                      //loc_1AEE1:
    if (memory(_ds, _di) == 0x00)               //jz short loc_1AEEE
        goto loc_1AEEE;
    if (memory(_ds, _si) == 0x00)               //jz short loc_1AEEE
        goto loc_1AEEE;
    goto locret_1AF11;                          //jmp short locret_1AF11
loc_1AEEE:                                      //loc_1AEEE:
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_1AEE1
        goto loc_1AEE1;
    _di += _dx;                                 //add di, dx
    _ah -= 1;                                   //dec ah
    if (_ah != 0)                               //jnz short loc_1AEDF
        goto loc_1AEDF;
    _al = memory(_ds, 0x245);                   //mov al, ds:245h
    memory(_ds, 0x4285) = _al;                  //mov ds:4285h, al
    _al = memory(_ds, 0x4286);                  //mov al, ds:4286h
    memory(_ds, 0x4283) = _al;                  //mov ds:4283h, al
    _al = memory(_ds, 0x246);                   //mov al, ds:246h
    memory(_ds, 0x4282) = _al;                  //mov ds:4282h, al
    memory(_ds, 0x142) = 0x00;                  //mov byte ptr ds:142h, 0
locret_1AF11:                                   //locret_1AF11:
    return;
}

void sub_1AF12()
{
loc_1AF12:
    if (memory(_ds, 0x428F) == 0x01)            //jz short locret_1AF22
        goto locret_1AF22;
    memory(_ds, 0x4283) += 1;                   //inc byte ptr ds:4283h
    sub_1AF7C();                                //call sub_1AF7C
    goto loc_1AF12;                             //jmp short sub_1AF12
locret_1AF22:                                   //locret_1AF22:
    return;
}

void sub_1AF23()
{
    memory(_ds, 0x42A4) += 1;                   //inc byte ptr ds:42A4h
    _al = memory(_ds, 0x42A4);                  //mov al, ds:42A4h
    _bx = memory16(_ds, 0x40C9);                //mov bx, ds:40C9h
    if (memory(_ds, 0x243) != 0x01)             //jnz short loc_1AF3E
        goto loc_1AF3E;
    if ((char)_al < (char)memory(_ds, _bx + 17050))//jl short locret_1AF57
        goto locret_1AF57;
    goto loc_1AF44;                             //jmp short loc_1AF44
loc_1AF3E:                                      //loc_1AF3E:
    if ((char)_al < (char)memory(_ds, _bx + 17040))//jl short locret_1AF57
        goto locret_1AF57;
loc_1AF44:                                      //loc_1AF44:
    memory(_ds, 0x42A4) = 0x00;                 //mov byte ptr ds:42A4h, 0
    memory(_ds, 0x4283) += 1;                   //inc byte ptr ds:4283h
    memory(_ds, 0x244) = 0x00;                  //mov byte ptr ds:244h, 0
    memory(_ds, 0x243) = 0x00;                  //mov byte ptr ds:243h, 0
locret_1AF57:                                   //locret_1AF57:
    return;
}

void sub_1AF58()
{
    _bp = memory16(_ds, 0x428B);                //mov bp, ds:428Bh
    _bp -= 1;                                   //dec bp
    _bp <<= 1;                                  //shl bp, 1
    _bp = memory16(_ds, _bp + 515);             //mov bp, ds:[bp+203h]
    _bx = _bx ^ _bx;                            //xor bx, bx
    _bl = memory(_ds, 0x4285);                  //mov bl, ds:4285h
    _bx <<= 1;                                  //shl bx, 1
    _bp += _bx;                                 //add bp, bx
    _bp = memory16(_ds, _bp + 0);               //mov bp, ds:[bp+0]
    memory16(_ds, 0x42A6) = _bp;                //mov ds:42A6h, bp
    memory(_ds, 0x142) = 0x01;                  //mov byte ptr ds:142h, 1
}

void sub_1AF7C()
{
    _bp = memory16(_ds, 0x42A6);                //mov bp, ds:42A6h
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_ds, 0x4283);                  //mov al, ds:4283h
    _al = _al + memory(_ds, _bp + 1);           //add al, ds:[bp+1]
    if ((char)_al <= (char)0x13)                //jle short loc_1AF93
        goto loc_1AF93;
loc_1AF8D:                                      //loc_1AF8D:
    memory(_ds, 0x428F) = 0x01;                 //mov byte ptr ds:428Fh, 1
    return;                                     //retn
loc_1AF93:                                      //loc_1AF93:
    _bx = 0x000a;                               //mov bx, 0Ah
    _mul(_bx);                                  //mul bx
    _cx = _cx ^ _cx;                            //xor cx, cx
    _cl = memory(_ds, 0x4282);                  //mov cl, ds:4282h
    _ax += _cx;                                 //add ax, cx
    _di = 0x40f2;                               //mov di, 40F2h
    _di += _ax;                                 //add di, ax
    _dx = _di;                                  //mov dx, di
    _cx = _cx ^ _cx;                            //xor cx, cx
    _cl = memory(_ds, _bp + 0);                 //mov cl, ds:[bp+0]
loc_1AFAD:                                      //loc_1AFAD:
    memory(_es, _di) |= 0x00;                   //or byte ptr es:[di], 0
    if (memory(_es, _di) == 0)                  //jz short loc_1AFB9
        goto loc_1AFB9;
    _di += 1;                                   //inc di
    _cx -= 1;                                   //dec cx
    if (_cx != 0)                               //jnz short loc_1AFAD
        goto loc_1AFAD;
    goto loc_1AF8D;                             //jmp short loc_1AF8D
loc_1AFB9:                                      //loc_1AFB9:
    _di = _dx;                                  //mov di, dx
    _bx = _bx ^ _bx;                            //xor bx, bx
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_ds, _bp + 0);                 //mov al, ds:[bp+0]
    memory16(_ds, 0x23F) = _ax;                 //mov ds:23Fh, ax
    _bl = memory(_ds, _bp + 1);                 //mov bl, ds:[bp+1]
    _bl -= 1;                                   //dec bl
    _mul(_bx);                                  //mul bx
    _si = 0x0002;                               //mov si, 2
    _si += _bp;                                 //add si, bp
    _si += _ax;                                 //add si, ax
    _dl = memory(_ds, _bp + 1);                 //mov dl, ds:[bp+1]
loc_1AFD9:                                      //loc_1AFD9:
    _cl = memory(_ds, _bp + 0);                 //mov cl, ds:[bp+0]
loc_1AFDD:                                      //loc_1AFDD:
    if (memory(_ds, _di) == 0x00)               //jz short loc_1AFE9
        goto loc_1AFE9;
    if (memory(_ds, _si) == 0x00)               //jz short loc_1AFE9
        goto loc_1AFE9;
    goto loc_1AF8D;                             //jmp short loc_1AF8D
loc_1AFE9:                                      //loc_1AFE9:
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_1AFDD
        goto loc_1AFDD;
    _di = _di - memory16(_ds, 0x23F);           //sub di, ds:23Fh
    _di -= 0x000a;                              //sub di, 0Ah
    _si = _si - memory16(_ds, 0x23F);           //sub si, ds:23Fh
    _si = _si - memory16(_ds, 0x23F);           //sub si, ds:23Fh
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_1AFD9
        goto loc_1AFD9;
    memory(_ds, 0x428F) = 0x00;                 //mov byte ptr ds:428Fh, 0
}



