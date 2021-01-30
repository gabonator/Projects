void sub_10524();
void sub_10533();
void sub_10594();
void sub_105A1();
void sub_105CC();
void sub_105F7();
void sub_10661();
void sub_10702();
void sub_10776();
void sub_1079D();
void sub_107AC();
void sub_107F1();
void sub_10836();
void sub_1087B();
void sub_1088D();
void sub_108DD();
void sub_108F7();
void sub_1091B();
void sub_10986();
void sub_109A5();
void sub_109C4();
void sub_109D3();
void sub_109EE();
void sub_10A67();
void sub_10AE7();
void sub_10BB1();
void sub_10BC4();
void sub_10C2E();
void sub_10C98();
void sub_10CCD();
void sub_10D03();
void sub_10D3D();
void sub_10D5C();
void sub_10DAA();
void sub_10DF8();
void sub_10E23();
void sub_10E40();
void sub_10E7F();
void sub_10EA6();
void sub_10EC0();
void sub_10EE8();
void sub_11162();
void sub_111F1();
void sub_112D6();
void sub_11376();
void sub_15F40();
void sub_15FE4();
void sub_16022();
void sub_16126();
void sub_1613C();
void sub_1615F();
void sub_16174();
void sub_1618F();
void loc_161CE();
void sub_16205();
void sub_16222();
void sub_16407();
void sub_1646E();
void sub_164A0();
void sub_164E1();
void sub_16519();
void sub_16555();
void sub_16591();
void sub_1686F();
void sub_168A8();
void sub_168E4();
void sub_16907();
void sub_1691D();
void sub_169E3();
void sub_16B3B();
void sub_16B9B();
void sub_16BC7();
void sub_16BF7();
void sub_16C27();
void sub_16C3D();
void sub_16C53();
void sub_16C69();
void loc_16CA1();
void sub_16CB8();
void sub_16CD7();
void sub_16D69();
void sub_16E16();
void sub_16E39();
void sub_16E66();
void sub_16E74();
void sub_16EA1();
void sub_16EB2();
void sub_16FF5();
void sub_17018();
void sub_17047();
void sub_1705D();
void sub_1709D();
void sub_170E6();
void sub_17132();
void sub_17180();
void sub_1718E();
void sub_17205();
void sub_17222();
void sub_17674();
void loc_176A0();
void sub_176E6();
void sub_176F4();
void sub_17702();
void sub_17723();
void sub_177FB();
void sub_17896();
void sub_17A31();
void sub_17A8B();
void sub_17C64();
void sub_17CF4();
void sub_17D53();
void sub_17D70();
void sub_17DFB();
void sub_17FBF();
void sub_17FF3();
void sub_18014();
void sub_1802D();
void sub_181A4();
void sub_181C6();
void sub_18351();
void sub_18A9A();
void loc_18B03();
void sub_18C83();
void sub_18CBE();
void sub_18D28();
void loc_18F9A();
void sub_19214();
void sub_1926D();
void sub_192AE();
void sub_192DA();
void sub_1930A();
void sub_1933F();
void sub_19351();
void sub_19420();
void sub_19462();
void sub_194C4();
void sub_19553();
void sub_19577();
void sub_19593();
void sub_195EA();
void sub_1961D();
void loc_19650();
void sub_196DD();
void loc_196F3();
void sub_199C8();
void sub_19AF6();
void sub_19B1C();
void sub_19B40();
void sub_19BAC();
void sub_19BDC();
void sub_19C05();
void sub_19C43();
void sub_19E18();
void sub_19EB5();
void sub_19EBB();
void sub_19ED0();
void sub_19EE5();
void loc_19F12();
void sub_19F8A();
void sub_1A102();
void sub_1A111();
void sub_1A121();
void sub_1A137();
void sub_1A13F();
void sub_1A155();
void sub_1A168();
void sub_1A16B();
void sub_1A1BC();
void sub_1A1D7();
void sub_1A1E4();
void sub_1A1E6();
void sub_1A1FD();
void sub_1A234();
void sub_1A23E();
void sub_1A24C();
void sub_1A257();
void sub_1A2C4();
void sub_1A2F6();
void sub_1A341();
void sub_1A359();
void sub_1A389();
void sub_1A3CF();
void sub_1A437();
void sub_1A44F();
void sub_1A45C();
void sub_1A54A();
void sub_1A56B();
void sub_1A592();
void sub_1A5E3();
void sub_1A5F0();
void sub_1A65B();
void sub_1A67B();
void sub_1A693();
void sub_1A69D();
void sub_1AC6D();
void sub_1AD6E();
void sub_1ADB0();
void sub_1ADB7();
void sub_1ADCB();
void sub_1AE03();
void sub_1AE81();
void sub_1AECD();
void sub_1AEE6();
void sub_1B93B();
void sub_1B95D();
void sub_1BA18();
void sub_1BA3A();
void sub_1BB3F();
void loc_1BB82();
void sub_1BC92();
void sub_1BCB7();
void sub_1BCCD();
void sub_1BF7C();
void sub_1BFA0();
void sub_1C0A8();
void sub_1C164();
void loc_1C1A2();
void sub_1C1A5();
void start();
void loc_1C3B0();
void sub_1C4BD();
void sub_1C4CA();
void sub_1C4E2();
void sub_10524()
{
    _ah = 0x0f;                                 //mov ah, 0Fh
    _interrupt(16);                             //int 10h
    memory(_ds, 0x6A) = _al;                    //mov ds:6Ah, al
    _ax = 0x000d;                               //mov ax, 0Dh
    _interrupt(16);                             //int 10h
}

void sub_10533()
{
    _ah = 0x48;                                 //mov ah, 48h
    _bx = 0x0200;                               //mov bx, 200h
    _interrupt(33);                             //int 21h
    if (!_flags.carry)                          //jnb short loc_1053F
      goto loc_1053F;
    _STOP_("goto loc_19731");                   //jmp loc_19731
loc_1053F:                                      //loc_1053F:
    memory16(_ds, 0x4C) = _ax;                  //mov ds:4Ch, ax
    _ah = 0x48;                                 //mov ah, 48h
    _bx = 0x0aaa;                               //mov bx, 0AAAh
    _interrupt(33);                             //int 21h
    if (!_flags.carry)                          //jnb short loc_1054E
      goto loc_1054E;
    _STOP_("goto loc_19731");                   //jmp loc_19731
loc_1054E:                                      //loc_1054E:
    memory16(_ds, 0x62) = _ax;                  //mov ds:62h, ax
    _ah = 0x48;                                 //mov ah, 48h
    _bx = 0x0aaa;                               //mov bx, 0AAAh
    _interrupt(33);                             //int 21h
    if (!_flags.carry)                          //jnb short loc_1055D
      goto loc_1055D;
    _STOP_("goto loc_19731");                   //jmp loc_19731
loc_1055D:                                      //loc_1055D:
    memory16(_ds, 0x64) = _ax;                  //mov ds:64h, ax
    _ah = 0x48;                                 //mov ah, 48h
    _bx = 0x0aaa;                               //mov bx, 0AAAh
    _interrupt(33);                             //int 21h
    if (!_flags.carry)                          //jnb short loc_1056C
      goto loc_1056C;
    _STOP_("goto loc_19731");                   //jmp loc_19731
loc_1056C:                                      //loc_1056C:
    memory16(_ds, 0x66) = _ax;                  //mov ds:66h, ax
    _ah = 0x48;                                 //mov ah, 48h
    _bx = 0x0aaa;                               //mov bx, 0AAAh
    _interrupt(33);                             //int 21h
    if (!_flags.carry)                          //jnb short loc_1057B
      goto loc_1057B;
    _STOP_("goto loc_19731");                   //jmp loc_19731
loc_1057B:                                      //loc_1057B:
    memory16(_ds, 0x68) = _ax;                  //mov ds:68h, ax
    _ah = 0x48;                                 //mov ah, 48h
    _bx = 0x0080;                               //mov bx, 80h
    _interrupt(33);                             //int 21h
    if (!_flags.carry)                          //jnb short loc_1058A
      goto loc_1058A;
    _STOP_("goto loc_19731");                   //jmp loc_19731
loc_1058A:                                      //loc_1058A:
    memory16(_ds, 0x52) = _ax;                  //mov ds:52h, ax
    memory16(_ds, 0x56) = 0xa400;               //mov word ptr ds:56h, 0A400h
}

void sub_10594()
{
    _ax = memory16(_ds, 0x62);                  //mov ax, ds:62h
    _cx = 0x4344;                               //mov cx, 4344h
    _dx = 0x00cd;                               //mov dx, 0CDh
    sub_1A65B();                                //call sub_1A65B
}

void sub_105A1()
{
    _ax = memory16(_ds, 0x4C);                  //mov ax, ds:4Ch
    _cx = 0x0000;                               //mov cx, 0
    _dx = 0x00e5;                               //mov dx, 0E5h
    sub_1A65B();                                //call sub_1A65B
    _cx = 0x0400;                               //mov cx, 400h
    _ax = 0xa680;                               //mov ax, 0A680h
    sub_105F7();                                //call sub_105F7
    _ax = memory16(_ds, 0x4C);                  //mov ax, ds:4Ch
    _cx = 0x0000;                               //mov cx, 0
    _dx = 0x00f1;                               //mov dx, 0F1h
    sub_1A65B();                                //call sub_1A65B
    _cx = 0x0080;                               //mov cx, 80h
    _ax = 0xa700;                               //mov ax, 0A700h
    sub_105F7();                                //call sub_105F7
}

void sub_105CC()
{
    _ax = memory16(_ds, 0x4C);                  //mov ax, ds:4Ch
    _cx = 0x0000;                               //mov cx, 0
    _dx = 0x00d9;                               //mov dx, 0D9h
    sub_1A65B();                                //call sub_1A65B
    _cx = 0x0400;                               //mov cx, 400h
    _ax = 0xa600;                               //mov ax, 0A600h
    sub_105F7();                                //call sub_105F7
    _ax = memory16(_ds, 0x4C);                  //mov ax, ds:4Ch
    _cx = 0x0000;                               //mov cx, 0
    _dx = 0x00fd;                               //mov dx, 0FDh
    sub_1A65B();                                //call sub_1A65B
    _cx = 0x0180;                               //mov cx, 180h
    _ax = 0xa980;                               //mov ax, 0A980h
    sub_105F7();                                //call sub_105F7
}

void sub_105F7()
{
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _bp = _cx;                                  //mov bp, cx
    _dx = memory16(_ds, 0x4C);                  //mov dx, ds:4Ch
    _ds = _dx;                                  //mov ds, dx
    _es = _ax;                                  //mov es, ax
    _si = _si ^ _si;                            //xor si, si
    _di = _di ^ _di;                            //xor di, di
    _push(_dx);                                 //push dx
    _ax = 0x0005;                               //mov ax, 5
    _dx = 0x03ce;                               //mov dx, 3CEh
    _out(_dx, _ax);                             //out dx, ax
    _dx = _pop();                               //pop dx
    _push(_dx);                                 //push dx
    _dx = 0x03c4;                               //mov dx, 3C4h
    _ax = 0x0102;                               //mov ax, 102h
    _out(_dx, _ax);                             //out dx, ax
    _dx = _pop();                               //pop dx
    _cx = _bp;                                  //mov cx, bp
    _di = _di ^ _di;                            //xor di, di
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _push(_dx);                                 //push dx
    _dx = 0x03c4;                               //mov dx, 3C4h
    _ax = 0x0202;                               //mov ax, 202h
    _out(_dx, _ax);                             //out dx, ax
    _dx = _pop();                               //pop dx
    _cx = _bp;                                  //mov cx, bp
    _di = _di ^ _di;                            //xor di, di
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _push(_dx);                                 //push dx
    _dx = 0x03c4;                               //mov dx, 3C4h
    _ax = 0x0402;                               //mov ax, 402h
    _out(_dx, _ax);                             //out dx, ax
    _dx = _pop();                               //pop dx
    _cx = _bp;                                  //mov cx, bp
    _di = _di ^ _di;                            //xor di, di
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _push(_dx);                                 //push dx
    _dx = 0x03c4;                               //mov dx, 3C4h
    _ax = 0x0802;                               //mov ax, 802h
    _out(_dx, _ax);                             //out dx, ax
    _dx = _pop();                               //pop dx
    _cx = _bp;                                  //mov cx, bp
    _di = _di ^ _di;                            //xor di, di
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _push(_dx);                                 //push dx
    _dx = 0x03c4;                               //mov dx, 3C4h
    _ax = 0x0f02;                               //mov ax, 0F02h
    _out(_dx, _ax);                             //out dx, ax
    _dx = _pop();                               //pop dx
    _push(_dx);                                 //push dx
    _ax = 0x0105;                               //mov ax, 105h
    _dx = 0x03ce;                               //mov dx, 3CEh
    _out(_dx, _ax);                             //out dx, ax
    _dx = _pop();                               //pop dx
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_10661()
{
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
}

void sub_10702()
{
    memory(_ds, 0x279) = 0x00;                  //mov byte ptr ds:279h, 0
    _si = 0x029a;                               //mov si, 29Ah
    _di = 0x02ce;                               //mov di, 2CEh
    _cx = 0x0033;                               //mov cx, 33h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _ax = 0x1a00;                               //mov ax, 1A00h
    _interrupt(16);                             //int 10h
    if ((char)_bl <= (char)0x05)                //jle short loc_10731
      goto loc_10731;
    if ((char)_bl < (char)0x07)                 //jl short loc_10731
      goto loc_10731;
    if ((char)_bl > (char)0x08)                 //jg short loc_10731
      goto loc_10731;
    _si = 0x028a;                               //mov si, 28Ah
    memory(_ds, 0x279) = 0x01;                  //mov byte ptr ds:279h, 1
    goto loc_1073E;                             //jmp short loc_1073E
    _STOP_("db 90h");                           //db 90h
loc_10731:                                      //loc_10731:
    _si = 0x027a;                               //mov si, 27Ah
    memory(_ds, 0x279) = 0x00;                  //mov byte ptr ds:279h, 0
    memory(_ds, 0x278) = 0x01;                  //mov byte ptr ds:278h, 1
loc_1073E:                                      //loc_1073E:
    memory(_ds, 0x301) = 0x00;                  //mov byte ptr ds:301h, 0
    _cx = 0x0010;                               //mov cx, 10h
loc_10746:                                      //loc_10746:
    _ah = 0x10;                                 //mov ah, 10h
    _al = 0x00;                                 //mov al, 0
    _bh = memory(_ds, _si);                     //mov bh, [si]
    _si += 1;                                   //inc si
    _bl = memory(_ds, 0x301);                   //mov bl, ds:301h
    memory(_ds, 0x301) += 1;                    //inc byte ptr ds:301h
    _push(_si);                                 //push si
    _push(_cx);                                 //push cx
    _interrupt(16);                             //int 10h
    _cx = _pop();                               //pop cx
    _si = _pop();                               //pop si
    if (--_cx)                                  //loop loc_10746
      goto loc_10746;
    if (memory(_ds, 0x279) != 0x01)             //jnz short loc_1076A
      goto loc_1076A;
    sub_10776();                                //call sub_10776
    sub_1079D();                                //call sub_1079D
loc_1076A:                                      //loc_1076A:
    _di = 0x029a;                               //mov di, 29Ah
    _si = 0x02ce;                               //mov si, 2CEh
    _cx = 0x0033;                               //mov cx, 33h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
}

void sub_10776()
{
    _si = 0x029a;                               //mov si, 29Ah
    memory(_ds, 0x301) = 0x00;                  //mov byte ptr ds:301h, 0
    _cx = 0x0010;                               //mov cx, 10h
loc_10781:                                      //loc_10781:
    _push(_cx);                                 //push cx
    _bh = 0x09;                                 //mov bh, 9
    _al = memory(_ds, _si);                     //mov al, [si]
    _ax = _bh * _al;                            //imul bh
    memory(_ds, _si) = _al;                     //mov [si], al
    _si += 1;                                   //inc si
    _al = memory(_ds, _si);                     //mov al, [si]
    _ax = _bh * _al;                            //imul bh
    memory(_ds, _si) = _al;                     //mov [si], al
    _si += 1;                                   //inc si
    _al = memory(_ds, _si);                     //mov al, [si]
    _ax = _bh * _al;                            //imul bh
    memory(_ds, _si) = _al;                     //mov [si], al
    _si += 1;                                   //inc si
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_10781
      goto loc_10781;
}

void sub_1079D()
{
    _bx = _bx ^ _bx;                            //xor bx, bx
    _cx = 0x0010;                               //mov cx, 10h
    _dx = 0x029a;                               //mov dx, 29Ah
    _al = 0x12;                                 //mov al, 12h
    _ah = 0x10;                                 //mov ah, 10h
    _interrupt(16);                             //int 10h
}

void sub_107AC()
{
    WORD _cs = _seg001;

    _dx = _dx ^ _dx;                            //xor dx, dx
    _cx = _dx;                                  //mov cx, dx
    _ch = _ah;                                  //mov ch, ah
    _dh = _ah;                                  //mov dh, ah
    _dx >>= 1;                                  //shr dx, 1
    _dx >>= 1;                                  //shr dx, 1
    _dx += _cx;                                 //add dx, cx
    _ah = _ah ^ _ah;                            //xor ah, ah
    _dx += _ax;                                 //add dx, ax
    _di = _dx;                                  //mov di, dx
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _es = memory16(_ds, 0x5A);                  //mov es, word ptr ds:5Ah
    _cx = 0x0027;                               //mov cx, 27h
    _ax = 0xa980;                               //mov ax, 0A980h
    _ds = _ax;                                  //mov ds, ax
loc_107CE:                                      //loc_107CE:
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory16(_cs, _si);                   //mov al, cs:[si]
    _si += 1;                                   //inc si
    if (_al == 0xff)                            //jz short loc_107EE
      goto loc_107EE;
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _bx = _si;                                  //mov bx, si
    _si = _ax;                                  //mov si, ax
    _ax = _di;                                  //mov ax, di
    sub_10661();                                //call sub_10661
    _si = _bx;                                  //mov si, bx
    _di = _ax;                                  //mov di, ax
    _di += 1;                                   //inc di
    goto loc_107CE;                             //jmp short loc_107CE
loc_107EE:                                      //loc_107EE:
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_107F1()
{
    WORD _cs = _seg001;

    _dx = _dx ^ _dx;                            //xor dx, dx
    _cx = _dx;                                  //mov cx, dx
    _ch = _ah;                                  //mov ch, ah
    _dh = _ah;                                  //mov dh, ah
    _dx >>= 1;                                  //shr dx, 1
    _dx >>= 1;                                  //shr dx, 1
    _dx += _cx;                                 //add dx, cx
    _ah = _ah ^ _ah;                            //xor ah, ah
    _dx += _ax;                                 //add dx, ax
    _di = _dx;                                  //mov di, dx
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _es = memory16(_ds, 0x5A);                  //mov es, word ptr ds:5Ah
    _cx = 0x0027;                               //mov cx, 27h
    _ax = 0xa600;                               //mov ax, 0A600h
    _ds = _ax;                                  //mov ds, ax
loc_10813:                                      //loc_10813:
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory16(_cs, _si);                   //mov al, cs:[si]
    _si += 1;                                   //inc si
    if (_al == 0xff)                            //jz short loc_10833
      goto loc_10833;
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _bx = _si;                                  //mov bx, si
    _si = _ax;                                  //mov si, ax
    _ax = _di;                                  //mov ax, di
    sub_10661();                                //call sub_10661
    _si = _bx;                                  //mov si, bx
    _di = _ax;                                  //mov di, ax
    _di += 1;                                   //inc di
    goto loc_10813;                             //jmp short loc_10813
loc_10833:                                      //loc_10833:
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_10836()
{
    WORD _cs = _seg001;

    _dx = _dx ^ _dx;                            //xor dx, dx
    _cx = _dx;                                  //mov cx, dx
    _ch = _ah;                                  //mov ch, ah
    _dh = _ah;                                  //mov dh, ah
    _dx >>= 1;                                  //shr dx, 1
    _dx >>= 1;                                  //shr dx, 1
    _dx += _cx;                                 //add dx, cx
    _ah = _ah ^ _ah;                            //xor ah, ah
    _dx += _ax;                                 //add dx, ax
    _di = _dx;                                  //mov di, dx
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _es = memory16(_ds, 0x5C);                  //mov es, word ptr ds:5Ch
    _cx = 0x0027;                               //mov cx, 27h
    _ax = 0xa600;                               //mov ax, 0A600h
    _ds = _ax;                                  //mov ds, ax
loc_10858:                                      //loc_10858:
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory16(_cs, _si);                   //mov al, cs:[si]
    _si += 1;                                   //inc si
    if (_al == 0xff)                            //jz short loc_10878
      goto loc_10878;
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _bx = _si;                                  //mov bx, si
    _si = _ax;                                  //mov si, ax
    _ax = _di;                                  //mov ax, di
    sub_10661();                                //call sub_10661
    _si = _bx;                                  //mov si, bx
    _di = _ax;                                  //mov di, ax
    _di += 1;                                   //inc di
    goto loc_10858;                             //jmp short loc_10858
loc_10878:                                      //loc_10878:
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_1087B()
{
    _cx = 0x0100;                               //mov cx, 100h
    _ax = 0x0000;                               //mov ax, 0
    _dx = 0x0008;                               //mov dx, 8
    _di = 0x2f73;                               //mov di, 2F73h
loc_10887:                                      //loc_10887:
    _stosw<MemAuto, DirAuto>();                 //stosw
    _ax += _dx;                                 //add ax, dx
    if (--_cx)                                  //loop loc_10887
      goto loc_10887;
}

void sub_1088D()
{
    WORD _cs = _seg001;

    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _es = memory16(_ds, 0x56);                  //mov es, word ptr ds:56h
    _ax = 0xa680;                               //mov ax, 0A680h
    _ds = _ax;                                  //mov ds, ax
    _cx = 0x0020;                               //mov cx, 20h
loc_1089B:                                      //loc_1089B:
    _bp = _cx;                                  //mov bp, cx
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_cs, _bx);                     //mov al, cs:[bx]
    if ((short)_ax < (short)0x00f8)             //jl short loc_108AA
      goto loc_108AA;
    sub_19593();                                //call sub_19593
loc_108AA:                                      //loc_108AA:
    _bx += 1;                                   //inc bx
    _ax <<= 1;                                  //shl ax, 1
    _ax += 0x2f73;                              //add ax, 2F73h
    _si = _ax;                                  //mov si, ax
    _si = memory16(_cs, _si);                   //mov si, cs:[si]
    _cx = 0x001f;                               //mov cx, 1Fh
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += _cx;                                 //add di, cx
    _movsb<MemVideo, MemVideo, DirAuto>();
    _di += 0xff20;                              //add di, 0FF20h
    _cx = _bp;                                  //mov cx, bp
    if (--_cx)                                  //loop loc_1089B
      goto loc_1089B;
    _di += 0x00e0;                              //add di, 0E0h
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_108DD()
{
    _bx = 0x571c;                               //mov bx, 571Ch
    _di = 0x1e00;                               //mov di, 1E00h
    sub_1088D();                                //call sub_1088D
    _di = 0x0000;                               //mov di, 0
    _bx = 0x573c;                               //mov bx, 573Ch
    _cx = 0x001a;                               //mov cx, 1Ah
loc_108EF:                                      //loc_108EF:
    _push(_cx);                                 //push cx
    sub_1088D();                                //call sub_1088D
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_108EF
      goto loc_108EF;
}

void sub_108F7()
{
    WORD _cs = _seg001;

    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short locret_1091A
      goto locret_1091A;
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _dx = _ax;                                  //mov dx, ax
    _bp = 0x0020;                               //mov bp, 20h
    _bx = 0x0008;                               //mov bx, 8
    _es = memory16(_cs, 0x5A);                  //mov es, cs:word_1045A
    _ds = memory16(_cs, 0x56);                  //mov ds, cs:word_10456
loc_1090F:                                      //loc_1090F:
    _cx = _bp;                                  //mov cx, bp
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di += _bx;                                 //add di, bx
    _dx -= 1;                                   //dec dx
    if (_dx != 0)                               //jnz short loc_1090F
      goto loc_1090F;
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
locret_1091A:                                   //locret_1091A:
    return;
}

void sub_1091B()
{
    _dx = memory16(_ds, 0x6C45);                //mov dx, ds:6C45h
    _dx += 0x00c0;                              //add dx, 0C0h
    _dx &= 0x00ff;                              //and dx, 0FFh
    if ((short)_dx > (short)memory16(_ds, 0x6C45))//jg short loc_10969
      goto loc_10969;
    _ax = _dx;                                  //mov ax, dx
    _si = 0x0000;                               //mov si, 0
    _di = 0x0144;                               //mov di, 144h
    _dx = 0x0100;                               //mov dx, 100h
    _dx = _dx - memory16(_ds, 0x6C45);          //sub dx, ds:6C45h
    _dx += _dx;                                 //add dx, dx
    _bx = 0x3173;                               //mov bx, 3173h
    _bx += _dx;                                 //add bx, dx
    _di = _di + memory16(_ds, _bx);             //add di, [bx]
    sub_108F7();                                //call sub_108F7
    _si = 0x0000;                               //mov si, 0
    _dx = memory16(_ds, 0x6C45);                //mov dx, ds:6C45h
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _si += _dx;                                 //add si, dx
    _di = 0x0144;                               //mov di, 144h
    _ax = 0x0100;                               //mov ax, 100h
    _ax = _ax - memory16(_ds, 0x6C45);          //sub ax, ds:6C45h
    sub_108F7();                                //call sub_108F7
    return;                                     //retn
loc_10969:                                      //loc_10969:
    _si = 0x0000;                               //mov si, 0
    _dx = memory16(_ds, 0x6C45);                //mov dx, ds:6C45h
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _si += _dx;                                 //add si, dx
    _di = 0x0144;                               //mov di, 144h
    _ax = 0x00c0;                               //mov ax, 0C0h
    sub_108F7();                                //call sub_108F7
}

void sub_10986()
{
    _bx = 0x573c;                               //mov bx, 573Ch
    _ax = memory16(_ds, 0x6C45);                //mov ax, ds:6C45h
    _ax &= 0x00f8;                              //and ax, 0F8h
    _ax -= 0x0008;                              //sub ax, 8
    _ax &= 0x00ff;                              //and ax, 0FFh
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di = _ax;                                  //mov di, ax
    sub_1088D();                                //call sub_1088D
}

void sub_109A5()
{
    _bx = 0x5a5c;                               //mov bx, 5A5Ch
    _ax = memory16(_ds, 0x6C45);                //mov ax, ds:6C45h
    _ax &= 0x00f8;                              //and ax, 0F8h
    _ax += 0x00d0;                              //add ax, 0D0h
    _ax &= 0x00ff;                              //and ax, 0FFh
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di = _ax;                                  //mov di, ax
    sub_1088D();                                //call sub_1088D
}

void sub_109C4()
{
    _di = 0x3173;                               //mov di, 3173h
    _ax = _ax ^ _ax;                            //xor ax, ax
    _cx = 0x0100;                               //mov cx, 100h
loc_109CC:                                      //loc_109CC:
    _stosw<MemAuto, DirAuto>();                 //stosw
    _ax += 0x0028;                              //add ax, 28h
    if (--_cx)                                  //loop loc_109CC
      goto loc_109CC;
}

void sub_109D3()
{
    memory16(_ds, 0x5A) = 0xa000;               //mov word ptr ds:5Ah, 0A000h
    memory16(_ds, 0x5C) = 0xa200;               //mov word ptr ds:5Ch, 0A200h
    memory16(_ds, 0x5E) = 0x0000;               //mov word ptr ds:5Eh, 0
    memory16(_ds, 0x60) = 0x2000;               //mov word ptr ds:60h, 2000h
}

void sub_109EE()
{
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _ax = memory16(_ds, 0x5A);                  //mov ax, ds:5Ah
    _dx = memory16(_ds, 0x5C);                  //mov dx, ds:5Ch
    memory16(_ds, 0x5C) = _ax;                  //mov ds:5Ch, ax
    memory16(_ds, 0x5A) = _dx;                  //mov ds:5Ah, dx
    _ax = memory16(_ds, 0x5E);                  //mov ax, ds:5Eh
    _dx = memory16(_ds, 0x60);                  //mov dx, ds:60h
    memory16(_ds, 0x60) = _ax;                  //mov ds:60h, ax
    memory16(_ds, 0x5E) = _dx;                  //mov ds:5Eh, dx
    _cx = memory16(_ds, 0x60);                  //mov cx, ds:60h
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _ax = 0x0040;                               //mov ax, 40h
    _es = _ax;                                  //mov es, ax
    _dx = memoryBiosGet16(_es, 0x63);           //mov dx, es:63h
    _dx += 0x0006;                              //add dx, 6
loc_10A22:                                      //loc_10A22:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x08;                                //and al, 8
    if (_al != 0)                               //jnz short loc_10A22
      goto loc_10A22;
loc_10A27:                                      //loc_10A27:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x08;                                //and al, 8
    if (_al == 0)                               //jz short loc_10A27
      goto loc_10A27;
    _dx -= 0x0006;                              //sub dx, 6
    _flags.interrupt = false;                   //cli
    _al = 0x0c;                                 //mov al, 0Ch
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _al = _ch;                                  //mov al, ch
    _out(_dx, _al);                             //out dx, al
    _dx -= 1;                                   //dec dx
    _al = 0x0d;                                 //mov al, 0Dh
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _al = _cl;                                  //mov al, cl
    _out(_dx, _al);                             //out dx, al
    _flags.interrupt = true;                    //sti
    _ah = _ch;                                  //mov ah, ch
    _ax <<= 1;                                  //shl ax, 1
    memoryBiosSet16(_es, 0x4E, _ax);            //mov es:4Eh, ax
    _ax = 0x0040;                               //mov ax, 40h
    _es = _ax;                                  //mov es, ax
    _dx = memoryBiosGet16(_es, 0x63);           //mov dx, es:63h
    _dx += 0x0006;                              //add dx, 6
loc_10A55:                                      //loc_10A55:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x08;                                //and al, 8
    if (_al != 0)                               //jnz short loc_10A55
      goto loc_10A55;
loc_10A5A:                                      //loc_10A5A:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x08;                                //and al, 8
    if (_al == 0)                               //jz short loc_10A5A
      goto loc_10A5A;
    _ax = _pop();                               //pop ax
    _dx = _pop();                               //pop dx
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_10A67()
{
    WORD _cs = _seg001;

    if (memory16(_ds, 0x9173) != 0x0000)        //jnz short loc_10A6F
      goto loc_10A6F;
    return;                                     //retn
loc_10A6F:                                      //loc_10A6F:
    _bx = memory16(_ds, 0x9175);                //mov bx, ds:9175h
    _cx = 0x0008;                               //mov cx, 8
loc_10A76:                                      //loc_10A76:
    _push(_cx);                                 //push cx
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _flags.sign = !!(_al & 0x80);               //or al, al
    _al |= _al;
    if (_al == 0)                               //jz short loc_10AD2
      goto loc_10AD2;
    if (_flags.sign)                            //js short loc_10ADC
      goto loc_10ADC;
    _dx = _dx ^ _dx;                            //xor dx, dx
    _dl = memory(_ds, _bx + 1);                 //mov dl, [bx+1]
    _cl = _dl;                                  //mov cl, dl
    _cl += 1;                                   //inc cl
    _cl &= 0x03;                                //and cl, 3
    _dl &= 0xfc;                                //and dl, 0FCh
    _dl |= _cl;                                 //or dl, cl
    memory(_ds, _bx + 1) = _dl;                 //mov [bx+1], dl
    _di = memory16(_ds, _bx + 4);               //mov di, [bx+4]
    _bp = memory16(_cs, _bx + 6);               //mov bp, cs:[bx+6]
    _si = _si ^ _si;                            //xor si, si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _es = memory16(_ds, 0x56);                  //mov es, word ptr ds:56h
    _ax = 0xa700;                               //mov ax, 0A700h
    _ds = _ax;                                  //mov ds, ax
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _si = _dx;                                  //mov si, dx
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _di += 0x001f;                              //add di, 1Fh
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _di += 0x001f;                              //add di, 1Fh
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _di += 0x001f;                              //add di, 1Fh
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _di += 0x001f;                              //add di, 1Fh
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _di += 0x001f;                              //add di, 1Fh
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _di += 0x001f;                              //add di, 1Fh
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _di += 0x001f;                              //add di, 1Fh
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
loc_10AD2:                                      //loc_10AD2:
    _bx += 0x0008;                              //add bx, 8
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_10A76
      goto loc_10A76;
    goto loc_10AE2;                             //jmp short loc_10AE2
loc_10ADC:                                      //loc_10ADC:
    _bx = 0x54fa;                               //mov bx, 54FAh
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_10A76
      goto loc_10A76;
loc_10AE2:                                      //loc_10AE2:
    memory16(_ds, 0x9175) = _bx;                //mov ds:9175h, bx
}

void sub_10AE7()
{
    WORD _cs = _seg001;

    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _bx = 0x573c;                               //mov bx, 573Ch
    _di = 0x0144;                               //mov di, 144h
    _es = memory16(_ds, 0x56);                  //mov es, word ptr ds:56h
    _ax = 0xa680;                               //mov ax, 0A680h
    _ds = _ax;                                  //mov ds, ax
    _cx = 0x0018;                               //mov cx, 18h
    _dx = memory16(_cs, 0x8BF0);                //mov dx, cs:word_18FF0
    _dx &= 0x0007;                              //and dx, 7
    if (_dx == 0)                               //jz short loc_10B43
      goto loc_10B43;
    _si = _dx;                                  //mov si, dx
    _bp = 0x0020;                               //mov bp, 20h
    _dx = _dx ^ 0x0007;                         //xor dx, 7
loc_10B0D:                                      //loc_10B0D:
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_cs, _bx);                     //mov al, cs:[bx]
    _bx += 1;                                   //inc bx
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _si += _ax;                                 //add si, ax
    _push(_dx);                                 //push dx
loc_10B1E:                                      //loc_10B1E:
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _di += 0x0027;                              //add di, 27h
    _dx -= 1;                                   //dec dx
    if ((short)_dx >= 0)                        //jns short loc_10B1E
      goto loc_10B1E;
    _dx = _pop();                               //pop dx
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _di += 1;                                   //inc di
    _bp -= 1;                                   //dec bp
    if (_bp != 0)                               //jnz short loc_10B0D
      goto loc_10B0D;
    _dx += 1;                                   //inc dx
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _ax = _dx;                                  //mov ax, dx
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _dx += _ax;                                 //add dx, ax
    _dx += 0xffe0;                              //add dx, 0FFE0h
    _di += _dx;                                 //add di, dx
    goto loc_10B80;                             //jmp short loc_10B80
    _STOP_("db 90h");                           //db 90h
loc_10B43:                                      //loc_10B43:
    _bp = 0x0020;                               //mov bp, 20h
loc_10B46:                                      //loc_10B46:
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_cs, _bx);                     //mov al, cs:[bx]
    _bx += 1;                                   //inc bx
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _si = _ax;                                  //mov si, ax
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _di += 0x0027;                              //add di, 27h
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _di += 0x0027;                              //add di, 27h
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _di += 0x0027;                              //add di, 27h
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _di += 0x0027;                              //add di, 27h
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _di += 0x0027;                              //add di, 27h
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _di += 0x0027;                              //add di, 27h
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _di += 0x0027;                              //add di, 27h
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _di += 0x0027;                              //add di, 27h
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _di += 1;                                   //inc di
    _bp -= 1;                                   //dec bp
    if (_bp != 0)                               //jnz short loc_10B46
      goto loc_10B46;
    _di += 0x0120;                              //add di, 120h
loc_10B80:                                      //loc_10B80:
    if (--_cx)                                  //loop loc_10B43
      goto loc_10B43;
    _dx = memory16(_cs, 0x8BF0);                //mov dx, cs:word_18FF0
    _dx &= 0x0007;                              //and dx, 7
    if (_dx == 0)                               //jz short loc_10BAE
      goto loc_10BAE;
    _bp = 0x0020;                               //mov bp, 20h
loc_10B8F:                                      //loc_10B8F:
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_cs, _bx);                     //mov al, cs:[bx]
    _bx += 1;                                   //inc bx
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _si = _ax;                                  //mov si, ax
    _push(_dx);                                 //push dx
loc_10BA0:                                      //loc_10BA0:
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _di += 0x0027;                              //add di, 27h
    _dx -= 1;                                   //dec dx
    if ((short)_dx >= 0)                        //jns short loc_10BA0
      goto loc_10BA0;
    _dx = _pop();                               //pop dx
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _di += 1;                                   //inc di
    _bp -= 1;                                   //dec bp
    if (_bp != 0)                               //jnz short loc_10B8F
      goto loc_10B8F;
loc_10BAE:                                      //loc_10BAE:
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_10BB1()
{
    _ax = memory16(_ds, 0x5A);                  //mov ax, ds:5Ah
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, 0x56);                  //mov ax, ds:56h
    memory16(_ds, 0x5A) = _ax;                  //mov ds:5Ah, ax
    _indirectCall(_ds, memory16(_ds, 0x3E));    //call word ptr ds:3Eh
    _ax = _pop();                               //pop ax
    memory16(_ds, 0x5A) = _ax;                  //mov ds:5Ah, ax
}

void sub_10BC4()
{
    _cx = memory16(_ds, 0x96F4);                //mov cx, ds:96F4h
    _push(_cx);                                 //push cx
    memory16(_ds, 0x96F4) = 0x0001;             //mov word ptr ds:96F4h, 1
    _push(_ax);                                 //push ax
    _push(_dx);                                 //push dx
    _indirectCall(_ds, memory16(_ds, 0x24));    //call word ptr ds:24h
    memory16(_ds, 0xB1C) = 0x0000;              //mov word ptr ds:0B1Ch, 0
    _indirectCall(_ds, memory16(_ds, 0x3E));    //call word ptr ds:3Eh
    memory16(_ds, 0xB1C) = 0x0001;              //mov word ptr ds:0B1Ch, 1
    _dx = _pop();                               //pop dx
    _ax = _pop();                               //pop ax
    sub_19351();                                //call sub_19351
    sub_19214();                                //call sub_19214
    sub_10AE7();                                //call sub_10AE7
    sub_1618F();                                //call sub_1618F
    sub_15FE4();                                //call sub_15FE4
    memory(_ds, 0x5B3E) = 0x01;                 //mov byte ptr ds:5B3Eh, 1
    sub_15F40();                                //call sub_15F40
    memory(_ds, 0x5B3E) = 0x00;                 //mov byte ptr ds:5B3Eh, 0
    sub_10BB1();                                //call sub_10BB1
    sub_19AF6();                                //call sub_19AF6
    _indirectCall(_ds, memory16(_ds, 0x1C));    //call word ptr ds:1Ch
    _si = 0x0162;                               //mov si, 162h
    _cx = 0x0010;                               //mov cx, 10h
loc_10C15:                                      //loc_10C15:
    _push(_cx);                                 //push cx
    _push(_si);                                 //push si
    sub_10C98();                                //call sub_10C98
    _indirectCall(_ds, memory16(_ds, 0x1C));    //call word ptr ds:1Ch
    _si = _pop();                               //pop si
    _cx = _pop();                               //pop cx
    _si += 0xfffe;                              //add si, 0FFFEh
    if (--_cx)                                  //loop loc_10C15
      goto loc_10C15;
    sub_17047();                                //call sub_17047
    _cx = _pop();                               //pop cx
    memory16(_ds, 0x96F4) = _cx;                //mov ds:96F4h, cx
}

void sub_10C2E()
{
    _cx = memory16(_ds, 0x96F4);                //mov cx, ds:96F4h
    _push(_cx);                                 //push cx
    memory16(_ds, 0x96F4) = 0x0001;             //mov word ptr ds:96F4h, 1
    _push(_ax);                                 //push ax
    _push(_dx);                                 //push dx
    _indirectCall(_ds, memory16(_ds, 0x24));    //call word ptr ds:24h
    memory16(_ds, 0xB1C) = 0x0000;              //mov word ptr ds:0B1Ch, 0
    _indirectCall(_ds, memory16(_ds, 0x3E));    //call word ptr ds:3Eh
    memory16(_ds, 0xB1C) = 0x0001;              //mov word ptr ds:0B1Ch, 1
    _dx = _pop();                               //pop dx
    _ax = _pop();                               //pop ax
    sub_19351();                                //call sub_19351
    sub_19214();                                //call sub_19214
    sub_1618F();                                //call sub_1618F
    sub_10AE7();                                //call sub_10AE7
    sub_15FE4();                                //call sub_15FE4
    memory(_ds, 0x5B3E) = 0x01;                 //mov byte ptr ds:5B3Eh, 1
    sub_15F40();                                //call sub_15F40
    memory(_ds, 0x5B3E) = 0x00;                 //mov byte ptr ds:5B3Eh, 0
    sub_10BB1();                                //call sub_10BB1
    sub_19AF6();                                //call sub_19AF6
    _indirectCall(_ds, memory16(_ds, 0x1C));    //call word ptr ds:1Ch
    _si = 0x0144;                               //mov si, 144h
    _cx = 0x0010;                               //mov cx, 10h
loc_10C7F:                                      //loc_10C7F:
    _push(_cx);                                 //push cx
    _push(_si);                                 //push si
    sub_10CCD();                                //call sub_10CCD
    _indirectCall(_ds, memory16(_ds, 0x1C));    //call word ptr ds:1Ch
    _si = _pop();                               //pop si
    _cx = _pop();                               //pop cx
    _si += 0x0002;                              //add si, 2
    if (--_cx)                                  //loop loc_10C7F
      goto loc_10C7F;
    sub_17047();                                //call sub_17047
    _cx = _pop();                               //pop cx
    memory16(_ds, 0x96F4) = _cx;                //mov ds:96F4h, cx
}

void sub_10C98()
{
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _bx = 0x0144;                               //mov bx, 144h
    _di = _bx;                                  //mov di, bx
    _bp = 0x00c0;                               //mov bp, 0C0h
    _es = memory16(_ds, 0x5A);                  //mov es, word ptr ds:5Ah
    _ax = memory16(_ds, 0x56);                  //mov ax, ds:56h
    _dx = memory16(_ds, 0x5C);                  //mov dx, ds:5Ch
loc_10CAD:                                      //loc_10CAD:
    _ds = _ax;                                  //mov ds, ax
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _ds = _dx;                                  //mov ds, dx
    _push(_si);                                 //push si
    _si = _bx;                                  //mov si, bx
    _cx = 0x001e;                               //mov cx, 1Eh
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _bx = _si;                                  //mov bx, si
    _si = _pop();                               //pop si
    _bx += 0x000a;                              //add bx, 0Ah
    _si += 0x0026;                              //add si, 26h
    _di += 0x0008;                              //add di, 8
    _bp -= 1;                                   //dec bp
    if (_bp != 0)                               //jnz short loc_10CAD
      goto loc_10CAD;
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_10CCD()
{
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _bx = 0x0146;                               //mov bx, 146h
    _di = 0x0144;                               //mov di, 144h
    _bp = 0x00c0;                               //mov bp, 0C0h
    _es = memory16(_ds, 0x5A);                  //mov es, word ptr ds:5Ah
    _ax = memory16(_ds, 0x56);                  //mov ax, ds:56h
    _dx = memory16(_ds, 0x5C);                  //mov dx, ds:5Ch
loc_10CE3:                                      //loc_10CE3:
    _ds = _dx;                                  //mov ds, dx
    _push(_si);                                 //push si
    _si = _bx;                                  //mov si, bx
    _cx = 0x001e;                               //mov cx, 1Eh
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _bx = _si;                                  //mov bx, si
    _si = _pop();                               //pop si
    _ds = _ax;                                  //mov ds, ax
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _movsb<MemAuto, MemAuto, DirAuto>();        //movsb
    _bx += 0x000a;                              //add bx, 0Ah
    _si += 0x0026;                              //add si, 26h
    _di += 0x0008;                              //add di, 8
    _bp -= 1;                                   //dec bp
    if (_bp != 0)                               //jnz short loc_10CE3
      goto loc_10CE3;
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_10D03()
{
    WORD _cs = _seg001;

    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = 0xa700;                               //mov ax, 0A700h
    _ds = _ax;                                  //mov ds, ax
    _es = memory16(_cs, 0x5A);                  //mov es, cs:word_1045A
    _si = 0x0100;                               //mov si, 100h
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _di ^ _di;                            //xor di, di
    _cx = 0x1f40;                               //mov cx, 1F40h
    _rep_stosb<MemVideo, DirAuto>();
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    sub_19B1C();                                //call sub_19B1C
    _indirectCall(_ds, memory16(_ds, 0x1C));    //call word ptr ds:1Ch
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = 0xa700;                               //mov ax, 0A700h
    _ds = _ax;                                  //mov ds, ax
    _es = memory16(_cs, 0x5A);                  //mov es, cs:word_1045A
    _si = 0x0100;                               //mov si, 100h
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _di ^ _di;                            //xor di, di
    _cx = 0x1f40;                               //mov cx, 1F40h
    _rep_stosb<MemVideo, DirAuto>();
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_10D3D()
{
    _ax = memory16(_ds, 0x62);                  //mov ax, ds:62h
    _cx = 0x0000;                               //mov cx, 0
    _dx = 0x010a;                               //mov dx, 10Ah
    sub_1A65B();                                //call sub_1A65B
    sub_10D5C();                                //call sub_10D5C
    _ax = memory16(_ds, 0x62);                  //mov ax, ds:62h
    _cx = 0x0000;                               //mov cx, 0
    _dx = 0x0116;                               //mov dx, 116h
    sub_1A65B();                                //call sub_1A65B
    sub_10DAA();                                //call sub_10DAA
}

void sub_10D5C()
{
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = memory16(_ds, 0x62);                  //mov ax, ds:62h
    _ds = _ax;                                  //mov ds, ax
    _ax = 0xa780;                               //mov ax, 0A780h
    _es = _ax;                                  //mov es, ax
    _si = _si ^ _si;                            //xor si, si
    _di = _di ^ _di;                            //xor di, di
    _push(_dx);                                 //push dx
    _ax = 0x0005;                               //mov ax, 5
    _dx = 0x03ce;                               //mov dx, 3CEh
    _out(_dx, _ax);                             //out dx, ax
    _dx = _pop();                               //pop dx
    _push(_dx);                                 //push dx
    _dx = 0x03c4;                               //mov dx, 3C4h
    _ax = 0x0102;                               //mov ax, 102h
    _out(_dx, _ax);                             //out dx, ax
    _dx = _pop();                               //pop dx
    _cx = 0x0fa0;                               //mov cx, 0FA0h
    _di = _di ^ _di;                            //xor di, di
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _push(_dx);                                 //push dx
    _dx = 0x03c4;                               //mov dx, 3C4h
    _ax = 0x0202;                               //mov ax, 202h
    _out(_dx, _ax);                             //out dx, ax
    _dx = _pop();                               //pop dx
    _cx = 0x0fa0;                               //mov cx, 0FA0h
    _di = _di ^ _di;                            //xor di, di
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _push(_dx);                                 //push dx
    _dx = 0x03c4;                               //mov dx, 3C4h
    _ax = 0x0f02;                               //mov ax, 0F02h
    _out(_dx, _ax);                             //out dx, ax
    _dx = _pop();                               //pop dx
    _push(_dx);                                 //push dx
    _ax = 0x0105;                               //mov ax, 105h
    _dx = 0x03ce;                               //mov dx, 3CEh
    _out(_dx, _ax);                             //out dx, ax
    _dx = _pop();                               //pop dx
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_10DAA()
{
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = memory16(_ds, 0x62);                  //mov ax, ds:62h
    _ds = _ax;                                  //mov ds, ax
    _ax = 0xa780;                               //mov ax, 0A780h
    _es = _ax;                                  //mov es, ax
    _si = _si ^ _si;                            //xor si, si
    _di = _di ^ _di;                            //xor di, di
    _push(_dx);                                 //push dx
    _ax = 0x0005;                               //mov ax, 5
    _dx = 0x03ce;                               //mov dx, 3CEh
    _out(_dx, _ax);                             //out dx, ax
    _dx = _pop();                               //pop dx
    _push(_dx);                                 //push dx
    _dx = 0x03c4;                               //mov dx, 3C4h
    _ax = 0x0402;                               //mov ax, 402h
    _out(_dx, _ax);                             //out dx, ax
    _dx = _pop();                               //pop dx
    _cx = 0x0fa0;                               //mov cx, 0FA0h
    _di = _di ^ _di;                            //xor di, di
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _push(_dx);                                 //push dx
    _dx = 0x03c4;                               //mov dx, 3C4h
    _ax = 0x0802;                               //mov ax, 802h
    _out(_dx, _ax);                             //out dx, ax
    _dx = _pop();                               //pop dx
    _cx = 0x0fa0;                               //mov cx, 0FA0h
    _di = _di ^ _di;                            //xor di, di
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _push(_dx);                                 //push dx
    _dx = 0x03c4;                               //mov dx, 3C4h
    _ax = 0x0f02;                               //mov ax, 0F02h
    _out(_dx, _ax);                             //out dx, ax
    _dx = _pop();                               //pop dx
    _push(_dx);                                 //push dx
    _ax = 0x0105;                               //mov ax, 105h
    _dx = 0x03ce;                               //mov dx, 3CEh
    _out(_dx, _ax);                             //out dx, ax
    _dx = _pop();                               //pop dx
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_10DF8()
{
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = 0xa780;                               //mov ax, 0A780h
    _ds = _ax;                                  //mov ds, ax
    _ax = 0xa000;                               //mov ax, 0A000h
    _es = _ax;                                  //mov es, ax
    _si = _si ^ _si;                            //xor si, si
    _di = _si;                                  //mov di, si
    _cx = 0x1f40;                               //mov cx, 1F40h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _ax = 0xa780;                               //mov ax, 0A780h
    _ds = _ax;                                  //mov ds, ax
    _ax = 0xa200;                               //mov ax, 0A200h
    _es = _ax;                                  //mov es, ax
    _si = _si ^ _si;                            //xor si, si
    _di = _si;                                  //mov di, si
    _cx = 0x1f40;                               //mov cx, 1F40h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_10E23()
{
    _dx = _dx ^ _dx;                            //xor dx, dx
    _dl = _ah;                                  //mov dl, ah
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _cx = _dx;                                  //mov cx, dx
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _dx += _cx;                                 //add dx, cx
    _cl = 0x03;                                 //mov cl, 3
    _dx <<= _cl;                                //shl dx, cl
    _di = _dx;                                  //mov di, dx
    _ah = _ah ^ _ah;                            //xor ah, ah
    _di += _ax;                                 //add di, ax
}

void sub_10E40()
{
    WORD _cs = _seg001;

    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = 0xa600;                               //mov ax, 0A600h
    _ds = _ax;                                  //mov ds, ax
    _es = memory16(_cs, 0x56);                  //mov es, cs:word_10456
loc_10E4C:                                      //loc_10E4C:
    _push(_cx);                                 //push cx
    _push(_si);                                 //push si
    _push(_di);                                 //push di
loc_10E4F:                                      //loc_10E4F:
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory16(_cs, _si);                   //mov al, cs:[si]
    _si += 1;                                   //inc si
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _si = _ax;                                  //mov si, ax
    _push(_cx);                                 //push cx
    _cx = 0x0027;                               //mov cx, 27h
    sub_10661();                                //call sub_10661
    _cx = _pop();                               //pop cx
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _di += 1;                                   //inc di
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_10E4F
      goto loc_10E4F;
    _di = _pop();                               //pop di
    _di += 0x0140;                              //add di, 140h
    _si = _pop();                               //pop si
    _si += 0x0020;                              //add si, 20h
    _cx = _pop();                               //pop cx
    _ch -= 1;                                   //dec ch
    if (_ch != 0)                               //jnz short loc_10E4C
      goto loc_10E4C;
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_10E7F()
{
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _es = memory16(_ds, 0x5A);                  //mov es, word ptr ds:5Ah
    _ds = memory16(_ds, 0x56);                  //mov ds, word ptr ds:56h
    _di = 0x0144;                               //mov di, 144h
    _si = _di;                                  //mov si, di
    _bp = 0x00c0;                               //mov bp, 0C0h
loc_10E91:                                      //loc_10E91:
    _cx = 0x0020;                               //mov cx, 20h
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _si += 0x0028;                              //add si, 28h
    _di += 0x0028;                              //add di, 28h
    _bp -= 1;                                   //dec bp
    if (_bp != 0)                               //jnz short loc_10E91
      goto loc_10E91;
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_10EA6()
{
    WORD _cs = _seg001;

    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = 0xa700;                               //mov ax, 0A700h
    _ds = _ax;                                  //mov ds, ax
    _es = memory16(_cs, 0x56);                  //mov es, cs:word_10456
    _si = 0x0100;                               //mov si, 100h
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _di ^ _di;                            //xor di, di
    _cx = 0x1f40;                               //mov cx, 1F40h
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_10EC0()
{
    _dx = memory16(_ds, 0x5A);                  //mov dx, ds:5Ah
    _push(_dx);                                 //push dx
    _dx = memory16(_ds, 0x56);                  //mov dx, ds:56h
    memory16(_ds, 0x5A) = _dx;                  //mov ds:5Ah, dx
    _indirectCall(_ds, memory16(_ds, 0xC));     //call word ptr ds:0Ch
    _dx = _pop();                               //pop dx
    memory16(_ds, 0x5A) = _dx;                  //mov ds:5Ah, dx
}

void sub_10EE8()
{
    WORD _cs = _seg001;

    _ax = memory16(_cs, 0x96F4);                //mov ax, cs:word_19AF4
    if (_ax == 0x0001)                          //jz short locret_10EF6
      goto locret_10EF6;
    _ax -= 1;                                   //dec ax
    memory16(_cs, 0x96F4) = _ax;                //mov cs:word_19AF4, ax
locret_10EF6:                                   //locret_10EF6:
    return;
}

void sub_11162()
{
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _es = memory16(_ds, 0x5A);                  //mov es, word ptr ds:5Ah
    _si = 0x0b00;                               //mov si, 0B00h
    _dx = 0x03ce;                               //mov dx, 3CEh
    _ax = 0x0001;                               //mov ax, 1
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0003;                               //mov ax, 3
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0005;                               //mov ax, 5
    _out(_dx, _ax);                             //out dx, ax
loc_1117A:                                      //loc_1117A:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (_flags.sign)                            //js short loc_11196
      goto loc_11196;
    if (_ax == 0)                               //jz short loc_11191
      goto loc_11191;
    if (memory16(_ds, _si + 10) == 0x00fe)      //jz short loc_11191
      goto loc_11191;
    _push(_ds);                                 //push ds
    _push(_si);                                 //push si
    _indirectCall(_ds, memory16(_ds, 0x40));    //call word ptr ds:40h
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
loc_11191:                                      //loc_11191:
    _si += 0x001c;                              //add si, 1Ch
    goto loc_1117A;                             //jmp short loc_1117A
loc_11196:                                      //loc_11196:
    _si = 0x0b56;                               //mov si, 0B56h
loc_11199:                                      //loc_11199:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _flags.sign = !!(_ah & 0x80);               //or ah, ah
    _ah |= _ah;
    if (_flags.sign)                            //js short loc_111B7
      goto loc_111B7;
    if (!(_al & 0x01))                          //jz short loc_111B2
      goto loc_111B2;
    if (memory16(_ds, _si + 10) == 0x00fe)      //jz short loc_111B2
      goto loc_111B2;
    _push(_ds);                                 //push ds
    _push(_si);                                 //push si
    _indirectCall(_ds, memory16(_ds, 0x40));    //call word ptr ds:40h
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
loc_111B2:                                      //loc_111B2:
    _si += 0x0034;                              //add si, 34h
    goto loc_11199;                             //jmp short loc_11199
loc_111B7:                                      //loc_111B7:
    _si = 0x0c28;                               //mov si, 0C28h
loc_111BA:                                      //loc_111BA:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _flags.sign = !!(_ah & 0x80);               //or ah, ah
    _ah |= _ah;
    if (_flags.sign)                            //js short loc_111D8
      goto loc_111D8;
    if (!(_al & 0x01))                          //jz short loc_111D3
      goto loc_111D3;
    if (memory16(_ds, _si + 10) == 0x00fe)      //jz short loc_111D3
      goto loc_111D3;
    _push(_ds);                                 //push ds
    _push(_si);                                 //push si
    _indirectCall(_ds, memory16(_ds, 0x40));    //call word ptr ds:40h
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
loc_111D3:                                      //loc_111D3:
    _si += 0x0034;                              //add si, 34h
    goto loc_111BA;                             //jmp short loc_111BA
loc_111D8:                                      //loc_111D8:
    _dx = 0x03c4;                               //mov dx, 3C4h
    _ax = 0x0f02;                               //mov ax, 0F02h
    _out(_dx, _ax);                             //out dx, ax
    _dl = 0xce;                                 //mov dl, 0CEh
    _ax = 0x0105;                               //mov ax, 105h
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0001;                               //mov ax, 1
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0xff08;                               //mov ax, 0FF08h
    _out(_dx, _ax);                             //out dx, ax
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_111F1()
{
    _bp = _bp ^ _bp;                            //xor bp, bp
    _ax = memory16(_ds, _si + 4);               //mov ax, [si+4]
    _ax -= 0x0038;                              //sub ax, 38h
    _dx = memory16(_ds, 0x8BF0);                //mov dx, ds:8BF0h
    _dx &= 0x0007;                              //and dx, 7
    _ax -= _dx;                                 //sub ax, dx
    if ((short)_ax >= (short)0x0008)            //jge short loc_1122C
      goto loc_1122C;
    _cx = 0x0008;                               //mov cx, 8
    _cx -= _ax;                                 //sub cx, ax
    _ax = _cx;                                  //mov ax, cx
    _cx = -_cx;                                 //neg cx
    _cx += 0x0015;                              //add cx, 15h
    if ((short)_cx > 0)                         //jg short loc_11218
      goto loc_11218;
    goto locret_112D5;                          //jmp locret_112D5
loc_11218:                                      //loc_11218:
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _dx = _ax;                                  //mov dx, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax += _dx;                                 //add ax, dx
    _bp = _ax;                                  //mov bp, ax
    _ax = 0x0140;                               //mov ax, 140h
    goto loc_11252;                             //jmp short loc_11252
loc_1122C:                                      //loc_1122C:
    if ((short)_ax <= (short)0x00b3)            //jle short loc_11241
      goto loc_11241;
    _cx = 0x00b3;                               //mov cx, 0B3h
    _cx -= _ax;                                 //sub cx, ax
    _cx += 0x0015;                              //add cx, 15h
    if ((short)_cx > 0)                         //jg short loc_1123E
      goto loc_1123E;
    goto locret_112D5;                          //jmp locret_112D5
loc_1123E:                                      //loc_1123E:
    goto loc_11244;                             //jmp short loc_11244
    _STOP_("db 90h");                           //db 90h
loc_11241:                                      //loc_11241:
    _cx = 0x0015;                               //mov cx, 15h
loc_11244:                                      //loc_11244:
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _dx = _ax;                                  //mov dx, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax += _dx;                                 //add ax, dx
loc_11252:                                      //loc_11252:
    _di = _ax;                                  //mov di, ax
    _ax = memory16(_ds, _si + 2);               //mov ax, [si+2]
    _ax += 0x0020;                              //add ax, 20h
    _ax &= 0xfff8;                              //and ax, 0FFF8h
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _di += _ax;                                 //add di, ax
    _ax = memory16(_ds, _si + 10);              //mov ax, [si+0Ah]
    if ((short)_ax < (short)0x0080)             //jl short loc_11270
      goto loc_11270;
    _ax -= 0x0040;                              //sub ax, 40h
loc_11270:                                      //loc_11270:
    _bx = 0x01a4;                               //mov bx, 1A4h
    _ax = _bx * _al;                            //mul bx
    _bx = memory16(_ds, _si + 2);               //mov bx, [si+2]
    _bx += 0x0020;                              //add bx, 20h
    _bx &= 0x0006;                              //and bx, 6
    _bx += 0x0062;                              //add bx, 62h
    _ds = memory16(_ds, _bx);                   //mov ds, word ptr [bx]
    _si = _ax;                                  //mov si, ax
    _si += _bp;                                 //add si, bp
    _bp = 0x0024;                               //mov bp, 24h
    _dh = 0x03;                                 //mov dh, 3
loc_1128D:                                      //loc_1128D:
    _push(_cx);                                 //push cx
    _cx = 0x0004;                               //mov cx, 4
loc_11291:                                      //loc_11291:
    _ah = memory(_ds, _si);                     //mov ah, [si]
    _ah |= _ah;                                 //or ah, ah
    if (_ah == 0)                               //jz short loc_112C9
      goto loc_112C9;
    _al = 0x08;                                 //mov al, 8
    _dl = 0xce;                                 //mov dl, 0CEh
    _out(_dx, _ax);                             //out dx, ax
    _dl = 0xc4;                                 //mov dl, 0C4h
    _ax = 0x0f02;                               //mov ax, 0F02h
    _out(_dx, _ax);                             //out dx, ax
    _ah = memoryVideoGet(_es, _di);             //mov ah, es:[di]
    _ah = 0x01;                                 //mov ah, 1
    _out(_dx, _ax);                             //out dx, ax
    _ah = memory(_ds, _si + 1);                 //mov ah, [si+1]
    memoryVideoSet(_es, _di, _ah);              //mov es:[di], ah
    _ah = 0x02;                                 //mov ah, 2
    _out(_dx, _ax);                             //out dx, ax
    _ah = memory(_ds, _si + 2);                 //mov ah, [si+2]
    memoryVideoSet(_es, _di, _ah);              //mov es:[di], ah
    _ah = 0x04;                                 //mov ah, 4
    _out(_dx, _ax);                             //out dx, ax
    _ah = memory(_ds, _si + 3);                 //mov ah, [si+3]
    memoryVideoSet(_es, _di, _ah);              //mov es:[di], ah
    _ah = 0x08;                                 //mov ah, 8
    _out(_dx, _ax);                             //out dx, ax
    _ah = memory(_ds, _si + 4);                 //mov ah, [si+4]
    memoryVideoSet(_es, _di, _ah);              //mov es:[di], ah
loc_112C9:                                      //loc_112C9:
    _di += 1;                                   //inc di
    _si += 0x0005;                              //add si, 5
    if (--_cx)                                  //loop loc_11291
      goto loc_11291;
    _di += _bp;                                 //add di, bp
    _cx = _pop();                               //pop cx
    _cx -= 1;                                   //dec cx
    if (_cx != 0)                               //jnz short loc_1128D
      goto loc_1128D;
locret_112D5:                                   //locret_112D5:
    return;
}

void sub_112D6()
{
    WORD _cs = _seg001;

    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ds = memory16(_ds, 0x62);                  //mov ds, word ptr ds:62h
    _bp = 0x0064;                               //mov bp, 64h
    _di = _di ^ _di;                            //xor di, di
    _si = _si ^ _si;                            //xor si, si
    _cx = 0x0888;                               //mov cx, 888h
loc_112E6:                                      //loc_112E6:
    _push(_cx);                                 //push cx
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _ah = memory(_ds, _si);                     //mov ah, [si]
    _al = memory(_ds, _si + 5);                 //mov al, [si+5]
    _bh = memory(_ds, _si + 10);                //mov bh, [si+0Ah]
    _bl = 0x00;                                 //mov bl, 0
    _push(_bp);                                 //push bp
    _cx = 0x0003;                               //mov cx, 3
loc_112F7:                                      //loc_112F7:
    _flags.carry = false;                       //clc
    _rcr(_ah, 1);                               //rcr ah, 1
    _rcr(_al, 1);                               //rcr al, 1
    _rcr(_bh, 1);                               //rcr bh, 1
    _rcr(_bl, 1);                               //rcr bl, 1
    _flags.carry = false;                       //clc
    _rcr(_ah, 1);                               //rcr ah, 1
    _rcr(_al, 1);                               //rcr al, 1
    _rcr(_bh, 1);                               //rcr bh, 1
    _rcr(_bl, 1);                               //rcr bl, 1
    _es = memory16(_cs, _bp + 0);               //mov es, word ptr cs:[bp+0]
    _bp += 1;                                   //inc bp
    _bp += 1;                                   //inc bp
    memory(_es, _di) = _ah;                     //mov es:[di], ah
    memory(_es, _di + 5) = _al;                 //mov es:[di+5], al
    memory(_es, _di + 10) = _bh;                //mov es:[di+0Ah], bh
    memory(_es, _di + 15) = _bl;                //mov es:[di+0Fh], bl
    if (--_cx)                                  //loop loc_112F7
      goto loc_112F7;
    _bp = _pop();                               //pop bp
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    _cx = 0x0004;                               //mov cx, 4
loc_11326:                                      //loc_11326:
    _push(_cx);                                 //push cx
    _ah = memory(_ds, _si);                     //mov ah, [si]
    _al = memory(_ds, _si + 5);                 //mov al, [si+5]
    _bh = memory(_ds, _si + 10);                //mov bh, [si+0Ah]
    _bl = 0x00;                                 //mov bl, 0
    _push(_bp);                                 //push bp
    _cx = 0x0003;                               //mov cx, 3
loc_11335:                                      //loc_11335:
    _flags.carry = false;                       //clc
    _rcr(_ah, 1);                               //rcr ah, 1
    _rcr(_al, 1);                               //rcr al, 1
    _rcr(_bh, 1);                               //rcr bh, 1
    _rcr(_bl, 1);                               //rcr bl, 1
    _flags.carry = false;                       //clc
    _rcr(_ah, 1);                               //rcr ah, 1
    _rcr(_al, 1);                               //rcr al, 1
    _rcr(_bh, 1);                               //rcr bh, 1
    _rcr(_bl, 1);                               //rcr bl, 1
    _es = memory16(_cs, _bp + 0);               //mov es, word ptr cs:[bp+0]
    _bp += 1;                                   //inc bp
    _bp += 1;                                   //inc bp
    memory(_es, _di) = _ah;                     //mov es:[di], ah
    memory(_es, _di + 5) = _al;                 //mov es:[di+5], al
    memory(_es, _di + 10) = _bh;                //mov es:[di+0Ah], bh
    memory(_es, _di + 15) = _bl;                //mov es:[di+0Fh], bl
    if (--_cx)                                  //loop loc_11335
      goto loc_11335;
    _bp = _pop();                               //pop bp
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_11326
      goto loc_11326;
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _si += 0x0014;                              //add si, 14h
    _di += 0x0014;                              //add di, 14h
    _cx = _pop();                               //pop cx
    _cx -= 1;                                   //dec cx
    if (_cx == 0)                               //jz short loc_11373
      goto loc_11373;
    goto loc_112E6;                             //jmp loc_112E6
loc_11373:                                      //loc_11373:
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_11376()
{
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _es = memory16(_ds, 0x5A);                  //mov es, word ptr ds:5Ah
    _si = 0x0b00;                               //mov si, 0B00h
    _dx = 0x03ce;                               //mov dx, 3CEh
    _ax = 0x0001;                               //mov ax, 1
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0003;                               //mov ax, 3
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0005;                               //mov ax, 5
    _out(_dx, _ax);                             //out dx, ax
    _si = 0x9bd6;                               //mov si, 9BD6h
loc_11391:                                      //loc_11391:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (_flags.sign)                            //js short loc_113B0
      goto loc_113B0;
    if (_ax == 0)                               //jz short loc_113AA
      goto loc_113AA;
    if (memory16(_ds, _si + 10) == 0x00fe)      //jz short loc_113AA
      goto loc_113AA;
    _push(_bx);                                 //push bx
    _push(_ds);                                 //push ds
    _push(_si);                                 //push si
    _indirectCall(_ds, memory16(_ds, 0x40));    //call word ptr ds:40h
    _si = _pop();                               //pop si
    _ds = _pop();                               //pop ds
    _bx = _pop();                               //pop bx
loc_113AA:                                      //loc_113AA:
    _si += 0x001a;                              //add si, 1Ah
    goto loc_11391;                             //jmp short loc_11391
loc_113B0:                                      //loc_113B0:
    _dx = 0x03c4;                               //mov dx, 3C4h
    _ax = 0x0f02;                               //mov ax, 0F02h
    _out(_dx, _ax);                             //out dx, ax
    _dl = 0xce;                                 //mov dl, 0CEh
    _ax = 0x0105;                               //mov ax, 105h
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0001;                               //mov ax, 1
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0xff08;                               //mov ax, 0FF08h
    _out(_dx, _ax);                             //out dx, ax
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_15F40()
{
    if (memory16(_ds, 0x762D) != 0x0001)        //jnz short loc_15F52
      goto loc_15F52;
    if (memory16(_ds, 0x762F) == 0x0001)        //jz short locret_15F51
      goto locret_15F51;
    sub_17A31();                                //call sub_17A31
locret_15F51:                                   //locret_15F51:
    return;                                     //retn
loc_15F52:                                      //loc_15F52:
    _bx = memory16(_ds, 0x5B3C);                //mov bx, ds:5B3Ch
    _bx |= _bx;                                 //or bx, bx
    if (_bx != 0)                               //jnz short loc_15F5B
      goto loc_15F5B;
    return;                                     //retn
loc_15F5B:                                      //loc_15F5B:
    _cx = memory16(_ds, 0x8BF0);                //mov cx, ds:8BF0h
    _cx >>= 1;                                  //shr cx, 1
    _cx >>= 1;                                  //shr cx, 1
    _cx >>= 1;                                  //shr cx, 1
    _cx += 0x0025;                              //add cx, 25h
loc_15F68:                                      //loc_15F68:
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _al |= _al;                                 //or al, al
    if (_al != 0)                               //jnz short loc_15F6F
      goto loc_15F6F;
    return;                                     //retn
loc_15F6F:                                      //loc_15F6F:
    _ah = _al;                                  //mov ah, al
    _bx += 1;                                   //inc bx
    _al = memory(_ds, _bx);                     //mov al, [bx]
    if (_al < _cl)                              //jb short loc_15F79
      goto loc_15F79;
    return;                                     //retn
loc_15F79:                                      //loc_15F79:
    if (!(_ah & 0x80))                          //jz short loc_15F90
      goto loc_15F90;
    _bx += 1;                                   //inc bx
loc_15F7F:                                      //loc_15F7F:
    _bx += 1;                                   //inc bx
loc_15F80:                                      //loc_15F80:
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    _al &= 0x03;                                //and al, 3
    if (_al == 0)                               //jz short loc_15F68
      goto loc_15F68;
loc_15F87:                                      //loc_15F87:
    _bx += 0x0004;                              //add bx, 4
    _al -= 1;                                   //dec al
    if (_al != 0)                               //jnz short loc_15F87
      goto loc_15F87;
    goto loc_15F68;                             //jmp short loc_15F68
loc_15F90:                                      //loc_15F90:
    _bx += 1;                                   //inc bx
    if (!(memory(_ds, _bx) & 0x80))             //jz short loc_15FD4
      goto loc_15FD4;
    _al = memory(_ds, 0x5B3E);                  //mov al, ds:5B3Eh
    _al |= _al;                                 //or al, al
    if (_al != 0)                               //jnz short loc_15FB9
      goto loc_15FB9;
    _push(_cx);                                 //push cx
    _cx = memory16(_ds, 0x8BF0);                //mov cx, ds:8BF0h
    _cx >>= 1;                                  //shr cx, 1
    _cx >>= 1;                                  //shr cx, 1
    _cx >>= 1;                                  //shr cx, 1
    _ah = _cl;                                  //mov ah, cl
    _bx -= 1;                                   //dec bx
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    _al -= _ah;                                 //sub al, ah
    _cx = _pop();                               //pop cx
    if (_al < 0x05)                             //jb short loc_15FB9
      goto loc_15FB9;
    if (_al < 0x22)                             //jb short loc_15F7F
      goto loc_15F7F;
loc_15FB9:                                      //loc_15FB9:
    _bx -= 1;                                   //dec bx
    _bx -= 1;                                   //dec bx
    _push(_bx);                                 //push bx
loc_15FBC:                                      //loc_15FBC:
    _si = _bx;                                  //mov si, bx
    sub_16205();                                //call sub_16205
    _bx = _pop();                               //pop bx
loc_15FC2:                                      //loc_15FC2:
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _cx = memory16(_ds, 0x8BF0);                //mov cx, ds:8BF0h
    _cx >>= 1;                                  //shr cx, 1
    _cx >>= 1;                                  //shr cx, 1
    _cx >>= 1;                                  //shr cx, 1
    _cx += 0x0025;                              //add cx, 25h
    goto loc_15F80;                             //jmp short loc_15F80
loc_15FD4:                                      //loc_15FD4:
    _bx -= 1;                                   //dec bx
    _bx -= 1;                                   //dec bx
    _push(_bx);                                 //push bx
    _si = _bx;                                  //mov si, bx
    _dx = _dx ^ _dx;                            //xor dx, dx
    sub_16222();                                //call sub_16222
    _bx = _pop();                               //pop bx
    if (_FIXME_)                                //jnb short loc_15FC2
      goto loc_15FC2;
    _push(_bx);                                 //push bx
    goto loc_15FBC;                             //jmp short loc_15FBC
}

void sub_15FE4()
{
    _bx = memory16(_ds, 0x8BFC);                //mov bx, ds:8BFCh
    memory16(_ds, 0x5B3C) = _bx;                //mov ds:5B3Ch, bx
    _bx |= _bx;                                 //or bx, bx
    if (_bx != 0)                               //jnz short loc_15FF1
      goto loc_15FF1;
    return;                                     //retn
loc_15FF1:                                      //loc_15FF1:
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _al |= _al;                                 //or al, al
    if (_al != 0)                               //jnz short loc_15FF8
      goto loc_15FF8;
    return;                                     //retn
loc_15FF8:                                      //loc_15FF8:
    _bx += 1;                                   //inc bx
    _cx = memory16(_ds, 0x8BF0);                //mov cx, ds:8BF0h
    _cx >>= 1;                                  //shr cx, 1
    _cx >>= 1;                                  //shr cx, 1
    _cx >>= 1;                                  //shr cx, 1
    if (_cl == memory(_ds, _bx))                //jz short loc_1601C
      goto loc_1601C;
    if (_cl < memory(_ds, _bx))                 //jb short loc_1601C
      goto loc_1601C;
    _bx += 0x0002;                              //add bx, 2
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    _al &= 0x03;                                //and al, 3
    if (_al == 0)                               //jz short loc_15FF1
      goto loc_15FF1;
loc_16013:                                      //loc_16013:
    _bx += 0x0004;                              //add bx, 4
    _al -= 1;                                   //dec al
    if (_al != 0)                               //jnz short loc_16013
      goto loc_16013;
    goto loc_15FF1;                             //jmp short loc_15FF1
loc_1601C:                                      //loc_1601C:
    _bx -= 1;                                   //dec bx
    memory16(_ds, 0x5B3C) = _bx;                //mov ds:5B3Ch, bx
}

void sub_16022()
{
    sub_16126();                                //call sub_16126
    if (!_flags.carry)                          //jnb short loc_16028
      goto loc_16028;
    return;                                     //retn
loc_16028:                                      //loc_16028:
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, _di + 50) = _ax;              //mov [di+32h], ax
    memory16(_ds, _di + 24) = _ax;              //mov [di+18h], ax
    memory16(_ds, _di + 34) = _ax;              //mov [di+22h], ax
    memory16(_ds, _di + 28) = _si;              //mov [di+1Ch], si
    _cx = _cx ^ _cx;                            //xor cx, cx
    _cl = memory(_ds, _si);                     //mov cl, [si]
    _cx += _cx;                                 //add cx, cx
    _bx = 0x117e;                               //mov bx, 117Eh
    _bx += _cx;                                 //add bx, cx
    _bx = memory16(_ds, _bx);                   //mov bx, [bx]
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _cbw();                                     //cbw
    memory16(_ds, _di + 30) = _ax;              //mov [di+1Eh], ax
    _bx += 1;                                   //inc bx
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _cbw();                                     //cbw
    memory16(_ds, _di + 32) = _ax;              //mov [di+20h], ax
    _bx += 1;                                   //inc bx
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _al &= 0xc0;                                //and al, 0C0h
    _dl = _al;                                  //mov dl, al
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_ds, _si + 3);                 //mov al, [si+3]
    _al &= 0x3c;                                //and al, 3Ch
    if (_al != 0x10)                            //jnz short loc_16072
      goto loc_16072;
    memory16(_ds, _di + 50) = 0x0060;           //mov word ptr [di+32h], 60h
    if (!(memory(_ds, _si + 3) & 0x40))         //jz short loc_16072
      goto loc_16072;
    memory16(_ds, _di + 28) = 0x0000;           //mov word ptr [di+1Ch], 0
loc_16072:                                      //loc_16072:
    _al |= 0x01;                                //or al, 1
    _al |= _dl;                                 //or al, dl
    memory(_ds, _di) = _al;                     //mov [di], al
    _al &= 0x3f;                                //and al, 3Fh
    _dl = _al;                                  //mov dl, al
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _al += _al;                                 //add al, al
    _al += _al;                                 //add al, al
    _al |= _dl;                                 //or al, dl
    memory(_ds, _di + 44) = _al;                //mov [di+2Ch], al
    _bx += 1;                                   //inc bx
    _ax = memory16(_ds, _bx);                   //mov ax, [bx]
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    memory16(_ds, _di + 36) = _ax;              //mov [di+24h], ax
    _ax = memory16(_ds, _bx);                   //mov ax, [bx]
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    memory16(_ds, _di + 22) = _ax;              //mov [di+16h], ax
    _ax = memory16(_ds, _bx);                   //mov ax, [bx]
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    memory16(_ds, _di + 40) = _ax;              //mov [di+28h], ax
    _ax = memory16(_ds, _bx);                   //mov ax, [bx]
    memory16(_ds, _di + 42) = _ax;              //mov [di+2Ah], ax
    _al = memory(_ds, _si + 2);                 //mov al, [si+2]
    _ax &= 0x001f;                              //and ax, 1Fh
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    if (!(memory(_ds, _si + 2) & 0x20))         //jz short loc_160BA
      goto loc_160BA;
    _ax += 1;                                   //inc ax
    _ax += 1;                                   //inc ax
    _ax += 1;                                   //inc ax
    _ax += 1;                                   //inc ax
loc_160BA:                                      //loc_160BA:
    memory16(_ds, _di + 2) = _ax;               //mov [di+2], ax
    _ax = memory16(_ds, 0x8BF0);                //mov ax, ds:8BF0h
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _dl = _al;                                  //mov dl, al
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    _al -= _dl;                                 //sub al, dl
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    if (!(memory(_ds, _si + 2) & 0x40))         //jz short loc_160DC
      goto loc_160DC;
    _ax += 1;                                   //inc ax
    _ax += 1;                                   //inc ax
    _ax += 1;                                   //inc ax
loc_160DC:                                      //loc_160DC:
    memory16(_ds, _di + 4) = _ax;               //mov [di+4], ax
    memory(_ds, _si) |= 0x80;                   //or byte ptr [si], 80h
    _al = memory(_ds, _di);                     //mov al, [di]
    _al &= 0x3f;                                //and al, 3Fh
    _ah = 0x29;                                 //mov ah, 29h
    if (_al != 0x21)                            //jnz short loc_160F2
      goto loc_160F2;
    memory(_ds, _di + 10) = _ah;                //mov [di+0Ah], ah
    goto locret_16125;                          //jmp short locret_16125
loc_160F2:                                      //loc_160F2:
    _ah = 0x27;                                 //mov ah, 27h
    if (_al != 0x29)                            //jnz short loc_160FE
      goto loc_160FE;
    memory(_ds, _di + 10) = _ah;                //mov [di+0Ah], ah
    goto locret_16125;                          //jmp short locret_16125
loc_160FE:                                      //loc_160FE:
    _ah = 0x28;                                 //mov ah, 28h
    if (_al != 0x2d)                            //jnz short loc_1610A
      goto loc_1610A;
    memory(_ds, _di + 10) = _ah;                //mov [di+0Ah], ah
    goto locret_16125;                          //jmp short locret_16125
loc_1610A:                                      //loc_1610A:
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bx);                                 //push bx
    _si = _di;                                  //mov si, di
    _ax = memory16(_ds, _si + 24);              //mov ax, [si+18h]
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, _si + 22);              //mov ax, [si+16h]
    _push(_ax);                                 //push ax
    sub_1718E();                                //call sub_1718E
    _ax = _pop();                               //pop ax
    memory16(_ds, _si + 22) = _ax;              //mov [si+16h], ax
    _ax = _pop();                               //pop ax
    memory16(_ds, _si + 24) = _ax;              //mov [si+18h], ax
    _bx = _pop();                               //pop bx
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
locret_16125:                                   //locret_16125:
    return;
}

void sub_16126()
{
    _di = 0x0c28;                               //mov di, 0C28h
loc_16129:                                      //loc_16129:
    _ax = memory16(_ds, _di);                   //mov ax, [di]
    _flags.sign = !!(_ah & 0x80);               //or ah, ah
    _ah |= _ah;
    if (_flags.sign)                            //js short loc_16138
      goto loc_16138;
    if (!(_al & 0x01))                          //jz short loc_1613A
      goto loc_1613A;
    _di += 0x0034;                              //add di, 34h
    goto loc_16129;                             //jmp short loc_16129
loc_16138:                                      //loc_16138:
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_1613A:                                      //loc_1613A:
    _flags.carry = false;                       //clc
}

void sub_1613C()
{
    _push(_cx);                                 //push cx
    _cx = memory16(_ds, _si + 2);               //mov cx, [si+2]
    if ((short)_cx < (short)0x0000)             //jl short loc_1615C
      goto loc_1615C;
    if ((short)_cx > (short)0x00e8)             //jg short loc_1615C
      goto loc_1615C;
    _cx = memory16(_ds, _si + 4);               //mov cx, [si+4]
    if ((short)_cx < (short)0x0000)             //jl short loc_1615C
      goto loc_1615C;
    if ((short)_cx >= (short)0x0128)            //jge short loc_1615C
      goto loc_1615C;
    _cx = _pop();                               //pop cx
    _flags.carry = false;                       //clc
    return;                                     //retn
loc_1615C:                                      //loc_1615C:
    _cx = _pop();                               //pop cx
    _flags.carry = true;                        //stc
}

void sub_1615F()
{
    if (!(memory16(_ds, _si) & 0x0001))         //jz short locret_16173
      goto locret_16173;
    _bx = memory16(_ds, _si + 28);              //mov bx, [si+1Ch]
    _bx |= _bx;                                 //or bx, bx
    if (_bx == 0)                               //jz short loc_1616F
      goto loc_1616F;
    memory(_ds, _bx) &= 0x7f;                   //and byte ptr [bx], 7Fh
loc_1616F:                                      //loc_1616F:
    memory16(_ds, _si) = 0x0000;                //mov word ptr [si], 0
locret_16173:                                   //locret_16173:
    return;
}

void sub_16174()
{
    if (!(memory16(_ds, _si) & 0x0001))         //jz short locret_1618E
      goto locret_1618E;
    _bx = memory16(_ds, _si + 28);              //mov bx, [si+1Ch]
    _bx |= _bx;                                 //or bx, bx
    if (_bx == 0)                               //jz short loc_1618A
      goto loc_1618A;
    if (memory(_ds, _bx + 3) & 0x40)            //jnz short loc_1618A
      goto loc_1618A;
    memory(_ds, _bx) &= 0x7f;                   //and byte ptr [bx], 7Fh
loc_1618A:                                      //loc_1618A:
    memory16(_ds, _si) = 0x0000;                //mov word ptr [si], 0
locret_1618E:                                   //locret_1618E:
    return;
}

void sub_1618F()
{
    _push(_si);                                 //push si
    _si = 0x0b56;                               //mov si, 0B56h
loc_16193:                                      //loc_16193:
    if (memory16(_ds, _si) == 0xffff)           //jz short loc_161AD
      goto loc_161AD;
    if (!(memory16(_ds, _si) & 0x0001))         //jz short loc_161A8
      goto loc_161A8;
    _bx = memory16(_ds, _si + 28);              //mov bx, [si+1Ch]
    memory(_ds, _bx) &= 0x7f;                   //and byte ptr [bx], 7Fh
    memory16(_ds, _si) = 0x0000;                //mov word ptr [si], 0
loc_161A8:                                      //loc_161A8:
    _si += 0x0034;                              //add si, 34h
    goto loc_16193;                             //jmp short loc_16193
loc_161AD:                                      //loc_161AD:
    _si = 0x0c28;                               //mov si, 0C28h
loc_161B0:                                      //loc_161B0:
    if (memory16(_ds, _si) == 0xffff)           //jz short loc_161CA
      goto loc_161CA;
    if (!(memory16(_ds, _si) & 0x0001))         //jz short loc_161C5
      goto loc_161C5;
    _bx = memory16(_ds, _si + 28);              //mov bx, [si+1Ch]
    memory(_ds, _bx) &= 0x7f;                   //and byte ptr [bx], 7Fh
    memory16(_ds, _si) = 0x0000;                //mov word ptr [si], 0
loc_161C5:                                      //loc_161C5:
    _si += 0x0034;                              //add si, 34h
    goto loc_161B0;                             //jmp short loc_161B0
loc_161CA:                                      //loc_161CA:
    _si = _pop();                               //pop si
}

void loc_161CE()
{
    memory(_ds, _si) |= 0x80;                   //or byte ptr [si], 80h
    memory16(_ds, 0x5DCC) = 0x0001;             //mov word ptr ds:5DCCh, 1
    memory16(_ds, 0x65E1) = 0x0018;             //mov word ptr ds:65E1h, 18h
    _si = 0x661d;                               //mov si, 661Dh
    _di = 0x6624;                               //mov di, 6624h
    _cx = 0x0006;                               //mov cx, 6
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _ax = 0x0013;                               //mov ax, 13h
    sub_1AECD();                                //call sub_1AECD
    return;                                     //retn
loc_161EF:                                      //loc_161EF:
    memory(_ds, _si) |= 0x80;                   //or byte ptr [si], 80h
    memory16(_ds, 0x5DCC) = 0x0000;             //mov word ptr ds:5DCCh, 0
    _si = 0x6624;                               //mov si, 6624h
    sub_16BC7();                                //call sub_16BC7
    _ax = 0x0001;                               //mov ax, 1
    sub_1AECD();                                //call sub_1AECD
}

void sub_16205()
{
    _ah = _ah ^ _ah;                            //xor ah, ah
    _al = memory(_ds, _si);                     //mov al, [si]
    if (_ax == 0x0078)                          //jz short loc_161CE
      _STOP_("goto loc_161CE");
    if (_ax == 0x007c)                          //jz short loc_161EF
      _STOP_("goto loc_161EF");
    if ((short)_ax >= (short)0x0075)            //jge short loc_1621C
      goto loc_1621C;
    sub_16022();                                //call sub_16022
    return;                                     //retn
loc_1621C:                                      //loc_1621C:
    sub_1691D();                                //call sub_1691D
}

void sub_16222()
{
    WORD _cs = _seg001;

    _push(memory16(_ds, 0x54F4));               //push word ptr ds:54F4h
    _push(_dx);                                 //push dx
    memory16(_ds, 0x54F4) = _pop();             //pop word ptr ds:54F4h
    _dx = _pop();                               //pop dx
    _push(memory16(_ds, 0x54F6));               //push word ptr ds:54F6h
    _push(_bx);                                 //push bx
    memory16(_ds, 0x54F6) = _pop();             //pop word ptr ds:54F6h
    _bx = _pop();                               //pop bx
    _al = memory(_ds, _si + 3);                 //mov al, [si+3]
    _al &= 0x03;                                //and al, 3
    if (_al != 0)                               //jnz short loc_1623E
      goto loc_1623E;
    return;                                     //retn
loc_1623E:                                      //loc_1623E:
    _si += 0x0004;                              //add si, 4
    _push(memory16(_ds, 0x54F8));               //push word ptr ds:54F8h
    _push(_ax);                                 //push ax
    memory16(_ds, 0x54F8) = _pop();             //pop word ptr ds:54F8h
    _ax = _pop();                               //pop ax
    _al = memory(_ds, _si + 2);                 //mov al, [si+2]
    _cl = _al;                                  //mov cl, al
    _al >>= 1;                                  //shr al, 1
    _al >>= 1;                                  //shr al, 1
    _al >>= 1;                                  //shr al, 1
    _al >>= 1;                                  //shr al, 1
    _al &= 0x0f;                                //and al, 0Fh
    _al += 1;                                   //inc al
    _ah = _al;                                  //mov ah, al
    _dx = memory16(_ds, 0x8BF0);                //mov dx, ds:8BF0h
    _dx >>= 1;                                  //shr dx, 1
    _dx >>= 1;                                  //shr dx, 1
    _dx >>= 1;                                  //shr dx, 1
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    _al -= _dl;                                 //sub al, dl
    if ((char)_al >= 0)                         //jns short loc_1627D
      goto loc_1627D;
    _flags.sign = (char)(_al + _ah) < 0;        //add al, ah
    _al += _ah;
    if (!_flags.sign)                           //jns short loc_16277
      goto loc_16277;
loc_16273:                                      //loc_16273:
    _flags.carry = false;                       //clc
    goto loc_163F5;                             //jmp loc_163F5
loc_16277:                                      //loc_16277:
    if (_al == 0)                               //jz short loc_16273
      goto loc_16273;
    _ah = _al;                                  //mov ah, al
    _al = _al ^ _al;                            //xor al, al
loc_1627D:                                      //loc_1627D:
    if (_al >= 0x20)                            //jnb short loc_16273
      goto loc_16273;
    _bx = _bx ^ _bx;                            //xor bx, bx
    _bl = _al;                                  //mov bl, al
    _bx += _bx;                                 //add bx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _bx;                                 //add bx, bx
    _ah += _ah;                                 //add ah, ah
    _ah += _ah;                                 //add ah, ah
    _ah += _ah;                                 //add ah, ah
    _cl &= 0x0f;                                //and cl, 0Fh
    _cl += 1;                                   //inc cl
    _cl += _cl;                                 //add cl, cl
    _cl += _cl;                                 //add cl, cl
    _cl += _cl;                                 //add cl, cl
    _dl = _cl;                                  //mov dl, cl
    _dh = memory(_ds, _si);                     //mov dh, [si]
    _push(_si);                                 //push si
    _al = memory(_ds, _si + 3);                 //mov al, [si+3]
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (!_flags.carry)                          //jnb short loc_162CD
      goto loc_162CD;
    _push(_bx);                                 //push bx
    _cl = _al;                                  //mov cl, al
    _push(_cx);                                 //push cx
    _si = 0x0b1c;                               //mov si, 0B1Ch
    sub_16407();                                //call sub_16407
    _cx = _pop();                               //pop cx
    _al = _cl;                                  //mov al, cl
    _bx = _pop();                               //pop bx
    if (!_flags.carry)                          //jnb short loc_162CD
      goto loc_162CD;
loc_162B8:                                      //loc_162B8:
    _si = _pop();                               //pop si
    _al = memory(_ds, _si + 3);                 //mov al, [si+3]
    _flags.sign = !!(_al & 0x80);               //or al, al
    _al |= _al;
    if (!_flags.sign)                           //jns short loc_162C3
      goto loc_162C3;
    goto loc_163F5;                             //jmp loc_163F5
loc_162C3:                                      //loc_162C3:
    _al &= 0x40;                                //and al, 40h
    if (_al != 0)                               //jnz short loc_162CB
      goto loc_162CB;
    memory(_ds, _si + 3) |= 0x80;               //or byte ptr [si+3], 80h
loc_162CB:                                      //loc_162CB:
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_162CD:                                      //loc_162CD:
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (!_flags.carry)                          //jnb short loc_162EC
      goto loc_162EC;
    _cl = _al;                                  //mov cl, al
    if (memory16(_ds, 0xB00) != 0x0001)         //jnz short loc_162EA
      goto loc_162EA;
    _push(_cx);                                 //push cx
    _push(_bx);                                 //push bx
    sub_164A0();                                //call sub_164A0
    _bx = _pop();                               //pop bx
    _cx = _pop();                               //pop cx
    if (!_flags.carry)                          //jnb short loc_162EA
      goto loc_162EA;
    memory(_ds, 0x5E20) = 0xff;                 //mov byte ptr ds:5E20h, 0FFh
    goto loc_162B8;                             //jmp short loc_162B8
loc_162EA:                                      //loc_162EA:
    _al = _cl;                                  //mov al, cl
loc_162EC:                                      //loc_162EC:
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (!_flags.carry)                          //jnb short loc_1630F
      goto loc_1630F;
    _cl = _al;                                  //mov cl, al
    if (memory16(_ds, 0xB38) != 0x0002)         //jnz short loc_1630D
      goto loc_1630D;
    _al = memory(_ds, 0xB4A);                   //mov al, ds:0B4Ah
    if ((char)_al <= (char)0x01)                //jle short loc_1630D
      goto loc_1630D;
    if ((char)_al > (char)0x04)                 //jg short loc_1630D
      goto loc_1630D;
    _push(_cx);                                 //push cx
    _push(_bx);                                 //push bx
    sub_164E1();                                //call sub_164E1
    _bx = _pop();                               //pop bx
    _cx = _pop();                               //pop cx
    if (_flags.carry)                           //jb short loc_162B8
      goto loc_162B8;
loc_1630D:                                      //loc_1630D:
    _al = _cl;                                  //mov al, cl
loc_1630F:                                      //loc_1630F:
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (!_flags.carry)                          //jnb short loc_1632F
      goto loc_1632F;
    _cl = _al;                                  //mov cl, al
    if (memory16(_ds, 0x7ECC) != 0x0001)        //jnz short loc_1632D
      goto loc_1632D;
    _push(_cx);                                 //push cx
    _push(_bx);                                 //push bx
    sub_1646E();                                //call sub_1646E
    _bx = _pop();                               //pop bx
    _cx = _pop();                               //pop cx
    if (!_flags.carry)                          //jnb short loc_1632D
      goto loc_1632D;
    _ax = 0x0014;                               //mov ax, 14h
    sub_1AECD();                                //call sub_1AECD
    goto loc_162B8;                             //jmp short loc_162B8
loc_1632D:                                      //loc_1632D:
    _al = _cl;                                  //mov al, cl
loc_1632F:                                      //loc_1632F:
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (!_flags.carry)                          //jnb short loc_16389
      goto loc_16389;
    _cl = _al;                                  //mov cl, al
    _push(_si);                                 //push si
    _si = 0x0b56;                               //mov si, 0B56h
loc_16339:                                      //loc_16339:
    _bp = memory16(_cs, _si);                   //mov bp, cs:[si]
    if (_bp == 0xffff)                          //jz short loc_1637D
      goto loc_1637D;
    if (!(_bp & 0x0001))                        //jz short loc_16378
      goto loc_16378;
    _push(memory16(_ds, 0x54F4));               //push word ptr ds:54F4h
    _push(_dx);                                 //push dx
    memory16(_ds, 0x54F4) = _pop();             //pop word ptr ds:54F4h
    _dx = _pop();                               //pop dx
    _push(memory16(_ds, 0x54F6));               //push word ptr ds:54F6h
    _push(_bx);                                 //push bx
    memory16(_ds, 0x54F6) = _pop();             //pop word ptr ds:54F6h
    _bx = _pop();                               //pop bx
    _push(_cx);                                 //push cx
    _push(_bx);                                 //push bx
    sub_16519();                                //call sub_16519
    _bx = _pop();                               //pop bx
    _cx = _pop();                               //pop cx
    _push(memory16(_ds, 0x54F4));               //push word ptr ds:54F4h
    _push(_dx);                                 //push dx
    memory16(_ds, 0x54F4) = _pop();             //pop word ptr ds:54F4h
    _dx = _pop();                               //pop dx
    _push(memory16(_ds, 0x54F6));               //push word ptr ds:54F6h
    _push(_bx);                                 //push bx
    memory16(_ds, 0x54F6) = _pop();             //pop word ptr ds:54F6h
    _bx = _pop();                               //pop bx
    if (_flags.carry)                           //jb short loc_16382
      goto loc_16382;
loc_16378:                                      //loc_16378:
    _si += 0x0034;                              //add si, 34h
    goto loc_16339;                             //jmp short loc_16339
loc_1637D:                                      //loc_1637D:
    _si = _pop();                               //pop si
    _flags.carry = false;                       //clc
    goto loc_16387;                             //jmp short loc_16387
loc_16382:                                      //loc_16382:
    _si = _pop();                               //pop si
    _flags.carry = true;                        //stc
    goto loc_162B8;                             //jmp loc_162B8
loc_16387:                                      //loc_16387:
    _al = _cl;                                  //mov al, cl
loc_16389:                                      //loc_16389:
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (!_flags.carry)                          //jnb short loc_163F0
      goto loc_163F0;
    _push(memory16(_ds, 0x54F4));               //push word ptr ds:54F4h
    _push(_dx);                                 //push dx
    memory16(_ds, 0x54F4) = _pop();             //pop word ptr ds:54F4h
    _dx = _pop();                               //pop dx
    _push(memory16(_ds, 0x54F6));               //push word ptr ds:54F6h
    _push(_bx);                                 //push bx
    memory16(_ds, 0x54F6) = _pop();             //pop word ptr ds:54F6h
    _bx = _pop();                               //pop bx
    _bx = 0x0c28;                               //mov bx, 0C28h
loc_163A4:                                      //loc_163A4:
    _al = memory(_ds, _bx + 1);                 //mov al, [bx+1]
    _flags.sign = !!(_al & 0x80);               //or al, al
    _al |= _al;
    if (_flags.sign)                            //js short loc_163F0
      goto loc_163F0;
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz short loc_163EB
      goto loc_163EB;
    if (_bx == _dx)                             //jz short loc_163EB
      goto loc_163EB;
    _si = _bx;                                  //mov si, bx
    _push(memory16(_ds, 0x54F4));               //push word ptr ds:54F4h
    _push(_dx);                                 //push dx
    memory16(_ds, 0x54F4) = _pop();             //pop word ptr ds:54F4h
    _dx = _pop();                               //pop dx
    _push(memory16(_ds, 0x54F6));               //push word ptr ds:54F6h
    _push(_bx);                                 //push bx
    memory16(_ds, 0x54F6) = _pop();             //pop word ptr ds:54F6h
    _bx = _pop();                               //pop bx
    _push(_cx);                                 //push cx
    _push(_bx);                                 //push bx
    sub_16555();                                //call sub_16555
    _bx = _pop();                               //pop bx
    _cx = _pop();                               //pop cx
    _push(memory16(_ds, 0x54F4));               //push word ptr ds:54F4h
    _push(_dx);                                 //push dx
    memory16(_ds, 0x54F4) = _pop();             //pop word ptr ds:54F4h
    _dx = _pop();                               //pop dx
    _push(memory16(_ds, 0x54F6));               //push word ptr ds:54F6h
    _push(_bx);                                 //push bx
    memory16(_ds, 0x54F6) = _pop();             //pop word ptr ds:54F6h
    _bx = _pop();                               //pop bx
    if (!_flags.carry)                          //jnb short loc_163EB
      goto loc_163EB;
    goto loc_162B8;                             //jmp loc_162B8
loc_163EB:                                      //loc_163EB:
    _bx += 0x0034;                              //add bx, 34h
    goto loc_163A4;                             //jmp short loc_163A4
loc_163F0:                                      //loc_163F0:
    _si = _pop();                               //pop si
    memory(_ds, _si + 3) &= 0x7f;               //and byte ptr [si+3], 7Fh
loc_163F5:                                      //loc_163F5:
    _push(memory16(_ds, 0x54F8));               //push word ptr ds:54F8h
    _push(_ax);                                 //push ax
    memory16(_ds, 0x54F8) = _pop();             //pop word ptr ds:54F8h
    _ax = _pop();                               //pop ax
    _al -= 1;                                   //dec al
    if (_al == 0)                               //jz short locret_16406
      goto locret_16406;
    goto loc_1623E;                             //jmp loc_1623E
locret_16406:                                   //locret_16406:
    return;
}

void sub_16407()
{
    if (memory16(_ds, 0x7E16) != 0x0001)        //jnz short loc_16410
      goto loc_16410;
    _flags.carry = false;                       //clc
    return;                                     //retn
loc_16410:                                      //loc_16410:
    _bp = memory16(_ds, 0xB1E);                 //mov bp, ds:0B1Eh
    _bp += 0x0014;                              //add bp, 14h
    _cx = _cx ^ _cx;                            //xor cx, cx
    _cl = _dh;                                  //mov cl, dh
    if ((short)_cx >= (short)_bp)               //jge short loc_1646C
      goto loc_1646C;
    _bp -= 0x0010;                              //sub bp, 10h
    _al = _dh;                                  //mov al, dh
    _dh = _dh ^ _dh;                            //xor dh, dh
    _cx += _dx;                                 //add cx, dx
    _dh = _al;                                  //mov dh, al
    if ((short)_cx <= (short)_bp)               //jle short loc_1646C
      goto loc_1646C;
    _bp = memory16(_ds, 0xB20);                 //mov bp, ds:0B20h
    _cx = _bx;                                  //mov cx, bx
    if (memory16(_ds, 0x7E04) == 0x0001)        //jz short loc_16454
      goto loc_16454;
    _bp += 0x0015;                              //add bp, 15h
    if ((short)_cx >= (short)_bp)               //jge short loc_1646C
      goto loc_1646C;
    _bp -= 0x0015;                              //sub bp, 15h
    _xchg(_al, _ah);                            //xchg al, ah
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cx += _ax;                                 //add cx, ax
    _xchg(_al, _ah);                            //xchg al, ah
    if ((short)_cx <= (short)_bp)               //jle short loc_1646C
      goto loc_1646C;
    goto loc_1646A;                             //jmp short loc_1646A
loc_16454:                                      //loc_16454:
    _bp += 0x0015;                              //add bp, 15h
    if ((short)_cx >= (short)_bp)               //jge short loc_1646C
      goto loc_1646C;
    _bp -= 0x0010;                              //sub bp, 10h
    _xchg(_al, _ah);                            //xchg al, ah
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cx += _ax;                                 //add cx, ax
    _xchg(_al, _ah);                            //xchg al, ah
    if ((short)_cx <= (short)_bp)               //jle short loc_1646C
      goto loc_1646C;
loc_1646A:                                      //loc_1646A:
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_1646C:                                      //loc_1646C:
    _flags.carry = false;                       //clc
}

void sub_1646E()
{
    _bp = memory16(_ds, 0x7ECE);                //mov bp, ds:7ECEh
    _cx = _cx ^ _cx;                            //xor cx, cx
    _cl = _dh;                                  //mov cl, dh
    if ((short)_cx > (short)_bp)                //jg short loc_1649E
      goto loc_1649E;
    _al = _dh;                                  //mov al, dh
    _dh = _dh ^ _dh;                            //xor dh, dh
    _cx += _dx;                                 //add cx, dx
    _dh = _al;                                  //mov dh, al
    if ((short)_cx < (short)_bp)                //jl short loc_1649E
      goto loc_1649E;
    _bp = memory16(_ds, 0x7ED0);                //mov bp, ds:7ED0h
    _cx = _bx;                                  //mov cx, bx
    if ((short)_cx > (short)_bp)                //jg short loc_1649E
      goto loc_1649E;
    _xchg(_al, _ah);                            //xchg al, ah
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cx += _ax;                                 //add cx, ax
    _xchg(_al, _ah);                            //xchg al, ah
    if ((short)_cx < (short)_bp)                //jl short loc_1649E
      goto loc_1649E;
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_1649E:                                      //loc_1649E:
    _flags.carry = false;                       //clc
}

void sub_164A0()
{
    WORD _cs = _seg001;

    if (memory16(_ds, 0xB00) != 0x0001)         //jnz short loc_164DF
      goto loc_164DF;
    _bp = memory16(_cs, 0xB02);                 //mov bp, cs:word_10F02
    _bp += 0x0008;                              //add bp, 8
    _cx = _cx ^ _cx;                            //xor cx, cx
    _cl = _dh;                                  //mov cl, dh
    if ((short)_cx > (short)_bp)                //jg short loc_164DF
      goto loc_164DF;
    _al = _dh;                                  //mov al, dh
    _dh = _dh ^ _dh;                            //xor dh, dh
    _cx += _dx;                                 //add cx, dx
    _dh = _al;                                  //mov dh, al
    if ((short)_cx < (short)_bp)                //jl short loc_164DF
      goto loc_164DF;
    _bp = memory16(_cs, 0xB04);                 //mov bp, cs:word_10F04
    _bp += 0x0004;                              //add bp, 4
    _cx = _bx;                                  //mov cx, bx
    if ((short)_cx > (short)_bp)                //jg short loc_164DF
      goto loc_164DF;
    _xchg(_al, _ah);                            //xchg al, ah
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cx += _ax;                                 //add cx, ax
    _xchg(_al, _ah);                            //xchg al, ah
    if ((short)_cx < (short)_bp)                //jl short loc_164DF
      goto loc_164DF;
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_164DF:                                      //loc_164DF:
    _flags.carry = false;                       //clc
}

void sub_164E1()
{
    _bp = memory16(_ds, 0xB3A);                 //mov bp, ds:0B3Ah
    _bp += 0x000c;                              //add bp, 0Ch
    _cx = _cx ^ _cx;                            //xor cx, cx
    _cl = _dh;                                  //mov cl, dh
    if ((short)_cx > (short)_bp)                //jg short loc_16517
      goto loc_16517;
    _al = _dh;                                  //mov al, dh
    _dh = _dh ^ _dh;                            //xor dh, dh
    _cx += _dx;                                 //add cx, dx
    _dh = _al;                                  //mov dh, al
    if ((short)_cx < (short)_bp)                //jl short loc_16517
      goto loc_16517;
    _bp = memory16(_ds, 0xB3C);                 //mov bp, ds:0B3Ch
    _bp += 0x000a;                              //add bp, 0Ah
    _cx = _bx;                                  //mov cx, bx
    if ((short)_cx > (short)_bp)                //jg short loc_16517
      goto loc_16517;
    _xchg(_al, _ah);                            //xchg al, ah
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cx += _ax;                                 //add cx, ax
    _xchg(_al, _ah);                            //xchg al, ah
    if ((short)_cx < (short)_bp)                //jl short loc_16517
      goto loc_16517;
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_16517:                                      //loc_16517:
    _flags.carry = false;                       //clc
}

void sub_16519()
{
    _bp = memory16(_ds, _si + 2);               //mov bp, [si+2]
    _bp += 0x0014;                              //add bp, 14h
    _cx = _cx ^ _cx;                            //xor cx, cx
    _cl = _dh;                                  //mov cl, dh
    if ((short)_cx >= (short)_bp)               //jge short loc_16553
      goto loc_16553;
    _bp -= 0x0010;                              //sub bp, 10h
    _al = _dh;                                  //mov al, dh
    _dh = _dh ^ _dh;                            //xor dh, dh
    _cx += _dx;                                 //add cx, dx
    _dh = _al;                                  //mov dh, al
    if ((short)_cx <= (short)_bp)               //jle short loc_16553
      goto loc_16553;
    _bp = memory16(_ds, _si + 4);               //mov bp, [si+4]
    _cx = _bx;                                  //mov cx, bx
    _bp += 0x0015;                              //add bp, 15h
    if ((short)_cx >= (short)_bp)               //jge short loc_16553
      goto loc_16553;
    _bp -= 0x0015;                              //sub bp, 15h
    _xchg(_al, _ah);                            //xchg al, ah
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cx += _ax;                                 //add cx, ax
    _xchg(_al, _ah);                            //xchg al, ah
    if ((short)_cx <= (short)_bp)               //jle short loc_16553
      goto loc_16553;
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_16553:                                      //loc_16553:
    _flags.carry = false;                       //clc
}

void sub_16555()
{
    _bp = memory16(_ds, _si + 2);               //mov bp, [si+2]
    _bp = _bp + memory16(_ds, _si + 30);        //add bp, [si+1Eh]
    _cx = _cx ^ _cx;                            //xor cx, cx
    _cl = _dh;                                  //mov cl, dh
    if ((short)_cx >= (short)_bp)               //jge short loc_1658F
      goto loc_1658F;
    _bp = _bp - memory16(_ds, _si + 30);        //sub bp, [si+1Eh]
    _al = _dh;                                  //mov al, dh
    _dh = _dh ^ _dh;                            //xor dh, dh
    _cx += _dx;                                 //add cx, dx
    _dh = _al;                                  //mov dh, al
    if ((short)_cx <= (short)_bp)               //jle short loc_1658F
      goto loc_1658F;
    _bp = memory16(_ds, _si + 4);               //mov bp, [si+4]
    _cx = _bx;                                  //mov cx, bx
    _bp = _bp + memory16(_ds, _si + 32);        //add bp, [si+20h]
    if ((short)_cx >= (short)_bp)               //jge short loc_1658F
      goto loc_1658F;
    _bp = _bp - memory16(_ds, _si + 32);        //sub bp, [si+20h]
    _xchg(_al, _ah);                            //xchg al, ah
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cx += _ax;                                 //add cx, ax
    _xchg(_al, _ah);                            //xchg al, ah
    if ((short)_cx <= (short)_bp)               //jle short loc_1658F
      goto loc_1658F;
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_1658F:                                      //loc_1658F:
    _flags.carry = false;                       //clc
}

void sub_16591()
{
    _al = memory(_ds, _si);                     //mov al, [si]
    _al &= 0x3f;                                //and al, 3Fh
    _ah = 0x29;                                 //mov ah, 29h
    if (_al != 0x21)                            //jnz short loc_1659E
      goto loc_1659E;
    goto loc_167D9;                             //jmp loc_167D9
loc_1659E:                                      //loc_1659E:
    _ah = 0x27;                                 //mov ah, 27h
    if (_al != 0x29)                            //jnz short loc_165A7
      goto loc_165A7;
    goto loc_167D9;                             //jmp loc_167D9
loc_165A7:                                      //loc_165A7:
    _ah = 0x28;                                 //mov ah, 28h
    if (_al != 0x2d)                            //jnz short loc_165B0
      goto loc_165B0;
    goto loc_167D9;                             //jmp loc_167D9
loc_165B0:                                      //loc_165B0:
    if (!(_al & 0x02))                          //jz short loc_165B7
      goto loc_165B7;
    goto loc_16748;                             //jmp loc_16748
loc_165B7:                                      //loc_165B7:
    _bx = memory16(_ds, _si + 36);              //mov bx, [si+24h]
loc_165BA:                                      //loc_165BA:
    _al = memory(_ds, _bx);                     //mov al, [bx]
    if (_al == 0x00)                            //jz short loc_165CF
      goto loc_165CF;
    if (_al != 0xff)                            //jnz short loc_16604
      goto loc_16604;
    _ax = memory16(_ds, _bx + 1);               //mov ax, [bx+1]
    sub_1AECD();                                //call sub_1AECD
    _bx += 0x0003;                              //add bx, 3
    goto loc_165BA;                             //jmp short loc_165BA
loc_165CF:                                      //loc_165CF:
    _bx += 1;                                   //inc bx
    _bx = memory16(_ds, _bx);                   //mov bx, [bx]
    memory16(_ds, _si + 36) = _bx;              //mov [si+24h], bx
    _al = memory(_ds, _si + 50);                //mov al, [si+32h]
    if (!(_al & 0x20))                          //jz short loc_165DF
      goto loc_165DF;
{sub_16174(); return; };                        //
loc_165DF:                                      //loc_165DF:
    if (!(_al & 0x10))                          //jz short loc_165BA
      goto loc_165BA;
    if (!(_al & 0x08))                          //jz short loc_165EE
      goto loc_165EE;
    memory(_ds, _si + 50) &= 0xf7;              //and byte ptr [si+32h], 0F7h
    goto loc_165F2;                             //jmp short loc_165F2
loc_165EE:                                      //loc_165EE:
    memory(_ds, _si + 50) &= 0xef;              //and byte ptr [si+32h], 0EFh
loc_165F2:                                      //loc_165F2:
    _al = memory(_ds, _si);                     //mov al, [si]
    _al &= 0x1c;                                //and al, 1Ch
    if (_al == 0x14)                            //jz short loc_165FD
      goto loc_165FD;
    goto loc_1679D;                             //jmp loc_1679D
loc_165FD:                                      //loc_165FD:
    memory(_ds, _si + 50) |= 0x20;              //or byte ptr [si+32h], 20h
    goto loc_1679D;                             //jmp loc_1679D
loc_16604:                                      //loc_16604:
    _bx += 1;                                   //inc bx
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _sar(_al, 1);                               //sar al, 1
    _sar(_al, 1);                               //sar al, 1
    _sar(_al, 1);                               //sar al, 1
    _sar(_al, 1);                               //sar al, 1
    if (_al != 0x07)                            //jnz short loc_16615
      goto loc_16615;
    _al += 1;                                   //inc al
loc_16615:                                      //loc_16615:
    _cbw();                                     //cbw
    memory16(_ds, _si + 46) = _ax;              //mov [si+2Eh], ax
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (!_flags.sign)                           //jns short loc_16625
      goto loc_16625;
    _flags.carry = (_ax + memory16(_ds, _si + 2)) >= 0x10000;
    _ax = _ax + memory16(_ds, _si + 2);
    if (_flags.carry)                           //jb short loc_1662A
      goto loc_1662A;
    goto loc_1662A;                             //jmp short loc_1662A
    _STOP_("db 90h");                           //db 90h
loc_16625:                                      //loc_16625:
    _flags.carry = (_ax + memory16(_ds, _si + 2)) >= 0x10000;
    _ax = _ax + memory16(_ds, _si + 2);
    if (!_flags.carry)                          //jnb short $+2
      _STOP_("goto $+2");
loc_1662A:                                      //loc_1662A:
    memory16(_ds, _si + 2) = _ax;               //mov [si+2], ax
    _dh = _dh ^ _dh;                            //xor dh, dh
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _al &= 0x0f;                                //and al, 0Fh
    if (!(_al & 0x08))                          //jz short loc_1663B
      goto loc_1663B;
    _dh -= 1;                                   //dec dh
    _al |= 0xf0;                                //or al, 0F0h
loc_1663B:                                      //loc_1663B:
    if (_al != 0x07)                            //jnz short loc_16641
      goto loc_16641;
    _al += 1;                                   //inc al
loc_16641:                                      //loc_16641:
    _dl = _al;                                  //mov dl, al
    _cbw();                                     //cbw
    memory16(_ds, _si + 48) = _ax;              //mov [si+30h], ax
    _cx = _bx;                                  //mov cx, bx
    _bx = memory16(_ds, _si + 4);               //mov bx, [si+4]
    _bx += _dx;                                 //add bx, dx
    memory16(_ds, _si + 4) = _bx;               //mov [si+4], bx
    sub_1613C();                                //call sub_1613C
    if (!_flags.carry)                          //jnb short loc_16659
      goto loc_16659;
{sub_1615F(); return; };                        //
loc_16659:                                      //loc_16659:
    _bx = _cx;                                  //mov bx, cx
    _bx -= 1;                                   //dec bx
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _cbw();                                     //cbw
    memory16(_ds, _si + 34) += 1;               //inc word ptr [si+22h]
    if (_ax == memory16(_ds, _si + 34))         //jz short loc_16669
      goto loc_16669;
    if (_ax >= memory16(_ds, _si + 34))         //jnb short loc_16673
      goto loc_16673;
loc_16669:                                      //loc_16669:
    memory16(_ds, _si + 34) = 0x0000;           //mov word ptr [si+22h], 0
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    memory16(_ds, _si + 36) = _bx;              //mov [si+24h], bx
loc_16673:                                      //loc_16673:
    sub_1718E();                                //call sub_1718E
    if (!(memory16(_ds, _si) & 0x0080))         //jz short loc_166BD
      goto loc_166BD;
    if (memory16(_ds, _si) & 0x0040)            //jnz short loc_16685
      goto loc_16685;
    goto loc_16748;                             //jmp loc_16748
loc_16685:                                      //loc_16685:
    if (memory16(_ds, 0xB38) != 0x0001)         //jnz short loc_166BD
      goto loc_166BD;
    _bx = memory16(_ds, 0xB3C);                 //mov bx, ds:0B3Ch
    _dh = memory(_ds, 0xB3A);                   //mov dh, ds:0B3Ah
    _dh += 0x08;                                //add dh, 8
    _dl = 0x08;                                 //mov dl, 8
    _ah = 0x10;                                 //mov ah, 10h
    sub_16555();                                //call sub_16555
    if (!_flags.carry)                          //jnb short loc_166BD
      goto loc_166BD;
    memory16(_ds, 0xB38) = 0x0002;              //mov word ptr ds:0B38h, 2
    memory16(_ds, 0xB50) = 0x0000;              //mov word ptr ds:0B50h, 0
    memory16(_ds, 0xB4E) = 0x7eb2;              //mov word ptr ds:0B4Eh, 7EB2h
    memory16(_ds, 0xB3C) -= 0x0005;             //sub word ptr ds:0B3Ch, 5
    memory16(_ds, 0xB4A) = 0x0000;              //mov word ptr ds:0B4Ah, 0
loc_166BD:                                      //loc_166BD:
    if (memory16(_ds, _si) & 0x0040)            //jnz short loc_166C6
      goto loc_166C6;
    goto loc_16748;                             //jmp loc_16748
loc_166C6:                                      //loc_166C6:
    if (memory16(_ds, _si + 10) == 0x00fe)      //jz short loc_16748
      goto loc_16748;
    _di = 0x0b56;                               //mov di, 0B56h
loc_166D3:                                      //loc_166D3:
    _ax = memory16(_ds, _di);                   //mov ax, [di]
    if (_ax == 0xffff)                          //jz short loc_16717
      goto loc_16717;
    if (!(_al & 0x01))                          //jz short loc_16712
      goto loc_16712;
    if (memory16(_ds, _di + 22) == 0x0001)      //jz short loc_16712
      goto loc_16712;
    _bx = memory16(_ds, _si + 4);               //mov bx, [si+4]
    _dh = memory(_ds, _si + 2);                 //mov dh, [si+2]
    _dl = memory(_ds, _si + 30);                //mov dl, [si+1Eh]
    _ah = memory(_ds, _si + 32);                //mov ah, [si+20h]
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _si = _di;                                  //mov si, di
    sub_16519();                                //call sub_16519
    if (!_flags.carry)                          //jnb short loc_16710
      goto loc_16710;
    _push(_si);                                 //push si
    _si = 0x6711;                               //mov si, 6711h
    sub_16BC7();                                //call sub_16BC7
    _si = _pop();                               //pop si
    sub_17674();                                //call sub_17674
loc_16710:                                      //loc_16710:
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
loc_16712:                                      //loc_16712:
    _di += 0x0034;                              //add di, 34h
    goto loc_166D3;                             //jmp short loc_166D3
loc_16717:                                      //loc_16717:
    if (memory16(_ds, 0x7E16) == 0x0001)        //jz short loc_16748
      goto loc_16748;
    if (!(memory(_ds, _si) & 0x40))             //jz short loc_16748
      goto loc_16748;
    _ax = memory16(_ds, _si + 10);              //mov ax, [si+0Ah]
    if (_ax == 0x00fe)                          //jz short loc_16748
      goto loc_16748;
    _bx = memory16(_ds, _si + 4);               //mov bx, [si+4]
    _dh = memory(_ds, _si + 2);                 //mov dh, [si+2]
    _dl = memory(_ds, _si + 30);                //mov dl, [si+1Eh]
    _ah = memory(_ds, _si + 32);                //mov ah, [si+20h]
    sub_16407();                                //call sub_16407
    if (!_flags.carry)                          //jnb short loc_16748
      goto loc_16748;
{sub_168A8(); return; };                        //
loc_16748:                                      //loc_16748:
    _al = memory(_ds, _si + 50);                //mov al, [si+32h]
    if (!(_al & 0x40))                          //jz short loc_16750
      goto loc_16750;
    return;                                     //retn
loc_16750:                                      //loc_16750:
    if (!(memory(_ds, _si + 50) & 0x10))        //jz short loc_1675C
      goto loc_1675C;
    if (!(memory(_ds, _si) & 0x20))             //jz short loc_1675C
      goto loc_1675C;
    return;                                     //retn
loc_1675C:                                      //loc_1675C:
    _push(_si);                                 //push si
    _dx = _si;                                  //mov dx, si
    _si = memory16(_ds, _si + 28);              //mov si, [si+1Ch]
    sub_16222();                                //call sub_16222
    _si = _pop();                               //pop si
    if (_FIXME_)                                //jb short loc_16774
      goto loc_16774;
    _al = memory(_ds, _si);                     //mov al, [si]
    _al &= 0x1c;                                //and al, 1Ch
    if (_al == 0x1c)                            //jz short loc_16771
      goto loc_16771;
    return;                                     //retn
loc_16771:                                      //loc_16771:
{sub_16174(); return; };                        //
loc_16774:                                      //loc_16774:
    _al = memory(_ds, _si);                     //mov al, [si]
    _al &= 0x1c;                                //and al, 1Ch
    if (_al != 0)                               //jnz short loc_16781
      goto loc_16781;
    _al = memory(_ds, _si);                     //mov al, [si]
    _al = _al ^ 0x02;                           //xor al, 2
    memory(_ds, _si) = _al;                     //mov [si], al
    return;                                     //retn
loc_16781:                                      //loc_16781:
    if (_al != 0x1c)                            //jnz short loc_16786
      goto loc_16786;
    return;                                     //retn
loc_16786:                                      //loc_16786:
    if (_al != 0x0c)                            //jnz short loc_1678D
      goto loc_1678D;
{sub_16174(); return; };                        //
loc_1678D:                                      //loc_1678D:
    if (!(_al & 0x08))                          //jz short loc_167CA
      goto loc_167CA;
    memory(_ds, _si + 50) |= 0x40;              //or byte ptr [si+32h], 40h
    if (!(_al & 0x10))                          //jz short loc_1679D
      goto loc_1679D;
    memory(_ds, _si + 50) |= 0x20;              //or byte ptr [si+32h], 20h
loc_1679D:                                      //loc_1679D:
    _bx = memory16(_ds, _si + 40);              //mov bx, [si+28h]
    _cx = memory16(_ds, _si + 36);              //mov cx, [si+24h]
    memory16(_ds, _si + 40) = _cx;              //mov [si+28h], cx
    memory16(_ds, _si + 36) = _bx;              //mov [si+24h], bx
    _bx = memory16(_ds, _si + 22);              //mov bx, [si+16h]
    _cx = memory16(_ds, _si + 42);              //mov cx, [si+2Ah]
    memory16(_ds, _si + 22) = _cx;              //mov [si+16h], cx
    memory16(_ds, _si + 42) = _bx;              //mov [si+2Ah], bx
    memory16(_ds, _si + 24) = 0x0000;           //mov word ptr [si+18h], 0
    memory16(_ds, _si + 18) = 0x0000;           //mov word ptr [si+12h], 0
    _al = memory(_ds, _si);                     //mov al, [si]
    _ah = memory(_ds, _si + 44);                //mov ah, [si+2Ch]
    memory(_ds, _si) = _ah;                     //mov [si], ah
    memory(_ds, _si + 44) = _al;                //mov [si+2Ch], al
    return;                                     //retn
loc_167CA:                                      //loc_167CA:
    memory(_ds, _si + 50) |= 0x10;              //or byte ptr [si+32h], 10h
    if (memory(_ds, _si) & 0x20)                //jnz short loc_167D4
      goto loc_167D4;
    return;                                     //retn
loc_167D4:                                      //loc_167D4:
    memory(_ds, _si + 50) |= 0x08;              //or byte ptr [si+32h], 8
    return;                                     //retn
loc_167D9:                                      //loc_167D9:
    memory(_ds, _si) = _al;                     //mov [si], al
    memory(_ds, _si + 10) = _ah;                //mov [si+0Ah], ah
    memory(_ds, _si + 11) = 0x00;               //mov byte ptr [si+0Bh], 0
    memory16(_ds, _si + 30) = 0x0018;           //mov word ptr [si+1Eh], 18h
    memory16(_ds, _si + 32) = 0x0015;           //mov word ptr [si+20h], 15h
    _bx = memory16(_ds, _si + 4);               //mov bx, [si+4]
    _dh = memory(_ds, _si + 2);                 //mov dh, [si+2]
    _dl = memory(_ds, _si + 30);                //mov dl, [si+1Eh]
    _ah = memory(_ds, _si + 32);                //mov ah, [si+20h]
    sub_16407();                                //call sub_16407
    if (!_flags.carry)                          //jnb short loc_16803
      goto loc_16803;
    sub_1686F();                                //call sub_1686F
    sub_16174();                                //call sub_16174
loc_16803:                                      //loc_16803:
    if (memory16(_ds, 0xB38) != 0x0002)         //jnz short loc_1683F
      goto loc_1683F;
    _al = memory(_ds, 0xB4A);                   //mov al, ds:0B4Ah
    if ((char)_al <= (char)0x01)                //jle short loc_1683F
      goto loc_1683F;
    if ((char)_al > (char)0x04)                 //jg short loc_1683F
      goto loc_1683F;
    _bx = memory16(_ds, _si + 4);               //mov bx, [si+4]
    _dh = memory(_ds, _si + 2);                 //mov dh, [si+2]
    _dl = memory(_ds, _si + 30);                //mov dl, [si+1Eh]
    _ah = memory(_ds, _si + 32);                //mov ah, [si+20h]
    if (_dh >= 0x0f)                            //jnb short loc_1682B
      goto loc_1682B;
    _dh = _dh ^ _dh;                            //xor dh, dh
    goto loc_1682E;                             //jmp short loc_1682E
    _STOP_("db 90h");                           //db 90h
loc_1682B:                                      //loc_1682B:
    _dh -= 0x10;                                //sub dh, 10h
loc_1682E:                                      //loc_1682E:
    _bx -= 0x000e;                              //sub bx, 0Eh
    _dl += 0x20;                                //add dl, 20h
    _ah += 0x1d;                                //add ah, 1Dh
    sub_164E1();                                //call sub_164E1
    if (!_flags.carry)                          //jnb short loc_1683F
      goto loc_1683F;
    sub_16174();                                //call sub_16174
loc_1683F:                                      //loc_1683F:
    if (memory16(_ds, 0xB00) != 0x0001)         //jnz short loc_16866
      goto loc_16866;
    _al = memory(_ds, _si);                     //mov al, [si]
    if (_al == 0x21)                            //jz short loc_16866
      goto loc_16866;
    _bx = memory16(_ds, _si + 4);               //mov bx, [si+4]
    _dh = memory(_ds, _si + 2);                 //mov dh, [si+2]
    _dl = memory(_ds, _si + 30);                //mov dl, [si+1Eh]
    _ah = memory(_ds, _si + 32);                //mov ah, [si+20h]
    sub_164A0();                                //call sub_164A0
    if (!_flags.carry)                          //jnb short loc_16866
      goto loc_16866;
    sub_16174();                                //call sub_16174
    memory16(_ds, 0xB00) = 0x0000;              //mov word ptr ds:0B00h, 0
loc_16866:                                      //loc_16866:
    sub_1613C();                                //call sub_1613C
    if (!_flags.carry)                          //jnb short locret_1686E
      goto locret_1686E;
    sub_1615F();                                //call sub_1615F
locret_1686E:                                   //locret_1686E:
    return;
}

void sub_1686F()
{
    _al = memory(_ds, _si);                     //mov al, [si]
    if (_al != 0x21)                            //jnz short loc_16884
      goto loc_16884;
    _push(_si);                                 //push si
    _si = 0x6717;                               //mov si, 6717h
    sub_16BC7();                                //call sub_16BC7
    _si = _pop();                               //pop si
    _ax = 0x0012;                               //mov ax, 12h
    sub_1AECD();                                //call sub_1AECD
    return;                                     //retn
loc_16884:                                      //loc_16884:
    if (_al == 0x29)                            //jz short loc_16898
      goto loc_16898;
    memory16(_ds, 0x6612) = 0x0006;             //mov word ptr ds:6612h, 6
    sub_16C3D();                                //call sub_16C3D
    _ax = 0x0011;                               //mov ax, 11h
    sub_1AECD();                                //call sub_1AECD
    return;                                     //retn
loc_16898:                                      //loc_16898:
    memory16(_ds, 0x6610) = 0x0006;             //mov word ptr ds:6610h, 6
    sub_16C27();                                //call sub_16C27
    _ax = 0x0011;                               //mov ax, 11h
    sub_1AECD();                                //call sub_1AECD
}

void sub_168A8()
{
    _ax = 0x000b;                               //mov ax, 0Bh
    sub_1AECD();                                //call sub_1AECD
    memory16(_ds, 0x7E16) = 0x0001;             //mov word ptr ds:7E16h, 1
    memory16(_ds, 0xB24) = 0xfb00;              //mov word ptr ds:0B24h, 0FB00h
    _ax = memory16(_ds, 0xB1E);                 //mov ax, ds:0B1Eh
    if ((short)_ax < (short)0x0080)             //jl short loc_168CB
      goto loc_168CB;
    memory16(_ds, 0x7E1C) = 0xfffe;             //mov word ptr ds:7E1Ch, 0FFFEh
    goto loc_168D1;                             //jmp short loc_168D1
    _STOP_("db 90h");                           //db 90h
loc_168CB:                                      //loc_168CB:
    memory16(_ds, 0x7E1C) = 0x0002;             //mov word ptr ds:7E1Ch, 2
loc_168D1:                                      //loc_168D1:
    _ax = memory16(_ds, 0x6614);                //mov ax, ds:6614h
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short locret_168E3
      goto locret_168E3;
    if (memory(_ds, 0x9804) == 0x01)            //jz short locret_168E3
      goto locret_168E3;
    memory16(_ds, 0x6614) -= 1;                 //dec word ptr ds:6614h
locret_168E3:                                   //locret_168E3:
    return;
}

void sub_168E4()
{
    if (memory16(_ds, 0x762D) != 0x0001)        //jnz short loc_168EF
      goto loc_168EF;
    sub_17A8B();                                //call sub_17A8B
    return;                                     //retn
loc_168EF:                                      //loc_168EF:
    _si = 0x0c28;                               //mov si, 0C28h
loc_168F2:                                      //loc_168F2:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (_flags.sign)                            //js short locret_16906
      goto locret_16906;
    if (!(_al & 0x01))                          //jz short loc_16901
      goto loc_16901;
    _push(_si);                                 //push si
    sub_16591();                                //call sub_16591
    _si = _pop();                               //pop si
loc_16901:                                      //loc_16901:
    _si += 0x0034;                              //add si, 34h
    goto loc_168F2;                             //jmp short loc_168F2
locret_16906:                                   //locret_16906:
    return;
}

void sub_16907()
{
    _di = 0x0b56;                               //mov di, 0B56h
loc_1690A:                                      //loc_1690A:
    _ax = memory16(_ds, _di);                   //mov ax, [di]
    _flags.sign = !!(_ah & 0x80);               //or ah, ah
    _ah |= _ah;
    if (_flags.sign)                            //js short loc_16919
      goto loc_16919;
    if (!(_al & 0x01))                          //jz short loc_1691B
      goto loc_1691B;
    _di += 0x0034;                              //add di, 34h
    goto loc_1690A;                             //jmp short loc_1690A
loc_16919:                                      //loc_16919:
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_1691B:                                      //loc_1691B:
    _flags.carry = false;                       //clc
}

void sub_1691D()
{
    sub_16907();                                //call sub_16907
    if (!_flags.carry)                          //jnb short loc_16923
      goto loc_16923;
    return;                                     //retn
loc_16923:                                      //loc_16923:
    memory16(_ds, _di + 22) = 0x0000;           //mov word ptr [di+16h], 0
    memory16(_ds, _di + 24) = 0x0000;           //mov word ptr [di+18h], 0
    memory(_ds, _si) |= 0x80;                   //or byte ptr [si], 80h
    _al = memory(_ds, _si);                     //mov al, [si]
    _al &= 0x03;                                //and al, 3
    memory(_ds, _di + 49) = 0x00;               //mov byte ptr [di+31h], 0
    memory(_ds, _di + 48) = _al;                //mov [di+30h], al
    memory16(_ds, _di + 28) = _si;              //mov [di+1Ch], si
    memory16(_ds, _di) |= 0x0001;               //or word ptr [di], 1
    _al = memory(_ds, _si);                     //mov al, [si]
    if (!(_al & 0x04))                          //jz short loc_16954
      goto loc_16954;
    memory16(_ds, _di + 10) = 0x002a;           //mov word ptr [di+0Ah], 2Ah
    memory16(_ds, _di + 50) = 0x002a;           //mov word ptr [di+32h], 2Ah
    goto loc_1695E;                             //jmp short loc_1695E
loc_16954:                                      //loc_16954:
    memory16(_ds, _di + 10) = 0x0034;           //mov word ptr [di+0Ah], 34h
    memory16(_ds, _di + 50) = 0x0034;           //mov word ptr [di+32h], 34h
loc_1695E:                                      //loc_1695E:
    _al = memory(_ds, _si + 2);                 //mov al, [si+2]
    _ax &= 0x001f;                              //and ax, 1Fh
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    memory16(_ds, _di + 2) = _ax;               //mov [di+2], ax
    _ax = memory16(_ds, 0x8BF0);                //mov ax, ds:8BF0h
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _dl = _al;                                  //mov dl, al
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    _al -= _dl;                                 //sub al, dl
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    if (!(memory(_ds, _si + 2) & 0x40))         //jz short loc_1698C
      goto loc_1698C;
    _ax += 1;                                   //inc ax
    _ax += 1;                                   //inc ax
    _ax += 1;                                   //inc ax
loc_1698C:                                      //loc_1698C:
    memory16(_ds, _di + 4) = _ax;               //mov [di+4], ax
    memory16(_ds, _di + 30) = 0x0010;           //mov word ptr [di+1Eh], 10h
    memory16(_ds, _di + 32) = 0x0015;           //mov word ptr [di+20h], 15h
    _ax = memory16(_ds, _di + 48);              //mov ax, [di+30h]
    if (_ax != 0x0001)                          //jnz short loc_169B3
      goto loc_169B3;
    _al = memory(_ds, _si + 3);                 //mov al, [si+3]
    _al &= 0x3c;                                //and al, 3Ch
    _ax <<= 1;                                  //shl ax, 1
    _ax += 0x0008;                              //add ax, 8
    memory16(_ds, _di + 18) = _ax;              //mov [di+12h], ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, _di + 20) = _ax;              //mov [di+14h], ax
loc_169B3:                                      //loc_169B3:
    memory16(_ds, _di + 8) = 0x0100;            //mov word ptr [di+8], 100h
    memory(_ds, _di + 6) = 0x00;                //mov byte ptr [di+6], 0
    memory16(_ds, _di + 16) = 0x0000;           //mov word ptr [di+10h], 0
    _ax = 0x0000;                               //mov ax, 0
    memory16(_ds, _di + 34) = _ax;              //mov [di+22h], ax
    memory16(_ds, _di + 36) = _ax;              //mov [di+24h], ax
    memory16(_ds, _di + 38) = _ax;              //mov [di+26h], ax
    memory16(_ds, _di + 40) = _ax;              //mov [di+28h], ax
    memory16(_ds, _di + 42) = _ax;              //mov [di+2Ah], ax
    memory16(_ds, _di + 44) = _ax;              //mov [di+2Ch], ax
    memory16(_ds, _di + 26) = 0x0000;           //mov word ptr [di+1Ah], 0
    memory16(_ds, _di + 16) = 0x0002;           //mov word ptr [di+10h], 2
}

void sub_169E3()
{
    if (memory16(_ds, 0x5DCC) == 0x0000)        //jz short locret_16A0E
      goto locret_16A0E;
    _ax = memory16(_ds, 0x65E1);                //mov ax, ds:65E1h
    _ax += 1;                                   //inc ax
    if (_ax != 0x0019)                          //jnz short loc_16A0B
      goto loc_16A0B;
    _si = 0x6624;                               //mov si, 6624h
    _cx = 0x0006;                               //mov cx, 6
    _al = 0x00;                                 //mov al, 0
loc_169FB:                                      //loc_169FB:
    if (_al != memory(_ds, _si))                //jnz short loc_16A03
      goto loc_16A03;
    _si += 1;                                   //inc si
    if (--_cx)                                  //loop loc_169FB
      goto loc_169FB;
    return;                                     //retn
loc_16A03:                                      //loc_16A03:
    _si = 0x662b;                               //mov si, 662Bh
    sub_16BF7();                                //call sub_16BF7
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_16A0B:                                      //loc_16A0B:
    memory16(_ds, 0x65E1) = _ax;                //mov ds:65E1h, ax
locret_16A0E:                                   //locret_16A0E:
    return;
}

void sub_16B3B()
{
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bx);                                 //push bx
    sub_16C53();                                //call sub_16C53
    sub_16C27();                                //call sub_16C27
    sub_16C3D();                                //call sub_16C3D
    _ax = 0x0004;                               //mov ax, 4
    _si = 0x6616;                               //mov si, 6616h
    _indirectCall(_ds, memory16(_ds, 0xC));     //call word ptr ds:0Ch
    _ax = 0x000d;                               //mov ax, 0Dh
    _si = 0x66f6;                               //mov si, 66F6h
    _indirectCall(_ds, memory16(_ds, 0xC));     //call word ptr ds:0Ch
    _ax = 0x0015;                               //mov ax, 15h
    _si = 0x66fd;                               //mov si, 66FDh
    _indirectCall(_ds, memory16(_ds, 0xC));     //call word ptr ds:0Ch
    _ax = 0x001e;                               //mov ax, 1Eh
    _si = 0x6704;                               //mov si, 6704h
    _indirectCall(_ds, memory16(_ds, 0xC));     //call word ptr ds:0Ch
    _ax = 0x0004;                               //mov ax, 4
    _si = 0x6616;                               //mov si, 6616h
    _indirectCall(_ds, memory16(_ds, 0xE));     //call word ptr ds:0Eh
    _ax = 0x000d;                               //mov ax, 0Dh
    _si = 0x66f6;                               //mov si, 66F6h
    _indirectCall(_ds, memory16(_ds, 0xE));     //call word ptr ds:0Eh
    _ax = 0x0015;                               //mov ax, 15h
    _si = 0x66fd;                               //mov si, 66FDh
    _indirectCall(_ds, memory16(_ds, 0xE));     //call word ptr ds:0Eh
    _ax = 0x001e;                               //mov ax, 1Eh
    _si = 0x6704;                               //mov si, 6704h
    _indirectCall(_ds, memory16(_ds, 0xE));     //call word ptr ds:0Eh
    _bx = _pop();                               //pop bx
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_16B9B()
{
    _indirectCall(_ds, memory16(_ds, 0x26));    //call word ptr ds:26h
    _indirectCall(_ds, memory16(_ds, 0x28));    //call word ptr ds:28h
    memory(_ds, 0x97DA) = 0x01;                 //mov byte ptr ds:97DAh, 1
    _cx = 0x01e0;                               //mov cx, 1E0h
loc_16BAC:                                      //loc_16BAC:
    _push(_cx);                                 //push cx
    sub_19B1C();                                //call sub_19B1C
    sub_19BDC();                                //call sub_19BDC
    if (_al & 0x10)                             //jnz short loc_16BC4
      goto loc_16BC4;
    _al = memory(_ds, 0xB888);                  //mov al, ds:0B888h
    _al &= 0x30;                                //and al, 30h
    if (_al == 0x30)                            //jz short loc_16BC4
      goto loc_16BC4;
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_16BAC
      goto loc_16BAC;
    return;                                     //retn
loc_16BC4:                                      //loc_16BC4:
{loc_1C3B0(); return; };                        //
}

void sub_16BC7()
{
    _si += 0x0005;                              //add si, 5
    _di = 0x661b;                               //mov di, 661Bh
    _bl = 0x00;                                 //mov bl, 0
    _cx = 0x0006;                               //mov cx, 6
loc_16BD2:                                      //loc_16BD2:
    _al = memory(_ds, _si);                     //mov al, [si]
    _ah = memory(_ds, _di);                     //mov ah, [di]
    _ah += _al;                                 //add ah, al
    _ah += _bl;                                 //add ah, bl
    _xchg(_al, _ah);                            //xchg al, ah
    _ah = _ah ^ _ah;                            //xor ah, ah
    if ((short)_ax < (short)0x000a)             //jl short loc_16BEE
      goto loc_16BEE;
    _bl = 0x01;                                 //mov bl, 1
    _al -= 0x0a;                                //sub al, 0Ah
    memory(_ds, _di) = _al;                     //mov [di], al
    _di -= 1;                                   //dec di
    _si -= 1;                                   //dec si
    if (--_cx)                                  //loop loc_16BD2
      goto loc_16BD2;
    return;                                     //retn
loc_16BEE:                                      //loc_16BEE:
    _bl = 0x00;                                 //mov bl, 0
    memory(_ds, _di) = _al;                     //mov [di], al
    _di -= 1;                                   //dec di
    _si -= 1;                                   //dec si
    if (--_cx)                                  //loop loc_16BD2
      goto loc_16BD2;
}

void sub_16BF7()
{
    _si += 0x0005;                              //add si, 5
    _di = 0x6629;                               //mov di, 6629h
    _bl = 0x00;                                 //mov bl, 0
    _cx = 0x0006;                               //mov cx, 6
loc_16C02:                                      //loc_16C02:
    _al = memory(_ds, _si);                     //mov al, [si]
    _ah = memory(_ds, _di);                     //mov ah, [di]
    _ah += _al;                                 //add ah, al
    _ah += _bl;                                 //add ah, bl
    _xchg(_al, _ah);                            //xchg al, ah
    _ah = _ah ^ _ah;                            //xor ah, ah
    if ((short)_ax < (short)0x000a)             //jl short loc_16C1E
      goto loc_16C1E;
    _bl = 0x01;                                 //mov bl, 1
    _al -= 0x0a;                                //sub al, 0Ah
    memory(_ds, _di) = _al;                     //mov [di], al
    _di -= 1;                                   //dec di
    _si -= 1;                                   //dec si
    if (--_cx)                                  //loop loc_16C02
      goto loc_16C02;
    return;                                     //retn
loc_16C1E:                                      //loc_16C1E:
    _bl = 0x00;                                 //mov bl, 0
    memory(_ds, _di) = _al;                     //mov [di], al
    _di -= 1;                                   //dec di
    _si -= 1;                                   //dec si
    if (--_cx)                                  //loop loc_16C02
      goto loc_16C02;
}

void sub_16C27()
{
    _di = 0x66f6;                               //mov di, 66F6h
    _cx = 0x0006;                               //mov cx, 6
    _al = 0x20;                                 //mov al, 20h
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    _cx = memory16(_ds, 0x6610);                //mov cx, ds:6610h
    _di = 0x66f6;                               //mov di, 66F6h
    _al = 0x0a;                                 //mov al, 0Ah
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
}

void sub_16C3D()
{
    _di = 0x66fd;                               //mov di, 66FDh
    _cx = 0x0006;                               //mov cx, 6
    _al = 0x20;                                 //mov al, 20h
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    _cx = memory16(_ds, 0x6612);                //mov cx, ds:6612h
    _di = 0x66fd;                               //mov di, 66FDh
    _al = 0x0b;                                 //mov al, 0Bh
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
}

void sub_16C53()
{
    _di = 0x6704;                               //mov di, 6704h
    _cx = 0x0006;                               //mov cx, 6
    _al = 0x20;                                 //mov al, 20h
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    _cx = memory16(_ds, 0x6614);                //mov cx, ds:6614h
    _di = 0x6704;                               //mov di, 6704h
    _al = 0x0c;                                 //mov al, 0Ch
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
}

void sub_16C69()
{
    _cx = 0x0008;                               //mov cx, 8
    _di = 0x6632;                               //mov di, 6632h
    _bx = 0x668d;                               //mov bx, 668Dh
loc_16C72:                                      //loc_16C72:
    _si = 0x6616;                               //mov si, 6616h
    sub_16CB8();                                //call sub_16CB8
    if (_flags.carry)                           //jb short loc_16C84
      goto loc_16C84;
    _bx += 0x000b;                              //add bx, 0Bh
    _di += 0x0007;                              //add di, 7
    if (--_cx)                                  //loop loc_16C72
      goto loc_16C72;
    _flags.carry = false;                       //clc
    return;                                     //retn
loc_16C84:                                      //loc_16C84:
    _si = 0x6663;                               //mov si, 6663h
loc_16C87:                                      //loc_16C87:
    if (_si == _di)                             //jz short loc_16C94
      goto loc_16C94;
    _al = memory(_ds, _si - 1);                 //mov al, [si-1]
    memory(_ds, _si + 6) = _al;                 //mov [si+6], al
    _si -= 1;                                   //dec si
    goto loc_16C87;                             //jmp short loc_16C87
loc_16C94:                                      //loc_16C94:
    _cx = 0x0007;                               //mov cx, 7
    _si = 0x6616;                               //mov si, 6616h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _flags.carry = true;                        //stc
}

void loc_16CA1()
{
loc_16CA1:
    if (_si == _di)                             //jz short loc_16CAE
      goto loc_16CAE;
    _al = memory(_ds, _si - 1);                 //mov al, [si-1]
    memory(_ds, _si + 10) = _al;                //mov [si+0Ah], al
    _si -= 1;                                   //dec si
    goto loc_16CA1;                             //jmp short loc_16CA1
loc_16CAE:                                      //loc_16CAE:
    _cx = 0x000b;                               //mov cx, 0Bh
    _si = 0x6671;                               //mov si, 6671h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _flags.carry = true;                        //stc
}

void sub_16CB8()
{
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _cx = 0x0006;                               //mov cx, 6
loc_16CBD:                                      //loc_16CBD:
    _al = memory(_ds, _si);                     //mov al, [si]
    _si += 1;                                   //inc si
    _ah = memory(_ds, _di);                     //mov ah, [di]
    _di += 1;                                   //inc di
    if ((char)_al < (char)_ah)                  //jl short loc_16CCF
      goto loc_16CCF;
    if ((char)_al > (char)_ah)                  //jg short loc_16CD3
      goto loc_16CD3;
    if (--_cx)                                  //loop loc_16CBD
      goto loc_16CBD;
    _di = _pop();                               //pop di
    _cx = _pop();                               //pop cx
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_16CCF:                                      //loc_16CCF:
    _di = _pop();                               //pop di
    _cx = _pop();                               //pop cx
    _flags.carry = false;                       //clc
    return;                                     //retn
loc_16CD3:                                      //loc_16CD3:
    _di = _pop();                               //pop di
    _cx = _pop();                               //pop cx
    _flags.carry = true;                        //stc
}

void sub_16CD7()
{
    _indirectCall(_ds, memory16(_ds, 0x26));    //call word ptr ds:26h
    _ax = 0x0008;                               //mov ax, 8
    _si = 0x9401;                               //mov si, 9401h
    _indirectCall(_ds, memory16(_ds, 0x46));    //call word ptr ds:46h
    _ax = 0x0108;                               //mov ax, 108h
    _si = 0x9421;                               //mov si, 9421h
    _indirectCall(_ds, memory16(_ds, 0x46));    //call word ptr ds:46h
    _ax = 0x0208;                               //mov ax, 208h
    _si = 0x9441;                               //mov si, 9441h
    _indirectCall(_ds, memory16(_ds, 0x46));    //call word ptr ds:46h
    _si = 0x668d;                               //mov si, 668Dh
    _ax = 0x0617;                               //mov ax, 617h
    _cx = 0x0008;                               //mov cx, 8
loc_16D02:                                      //loc_16D02:
    _push(_si);                                 //push si
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _indirectCall(_ds, memory16(_ds, 0xC));     //call word ptr ds:0Ch
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
    _si = _pop();                               //pop si
    _si += 0x000b;                              //add si, 0Bh
    _ah += 1;                                   //inc ah
    _ah += 1;                                   //inc ah
    if (--_cx)                                  //loop loc_16D02
      goto loc_16D02;
    _si = 0x6632;                               //mov si, 6632h
    _ax = 0x0607;                               //mov ax, 607h
    _cx = 0x0008;                               //mov cx, 8
loc_16D1E:                                      //loc_16D1E:
    _push(_si);                                 //push si
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _indirectCall(_ds, memory16(_ds, 0xC));     //call word ptr ds:0Ch
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
    _si = _pop();                               //pop si
    _si += 0x0007;                              //add si, 7
    _ah += 1;                                   //inc ah
    _ah += 1;                                   //inc ah
    if (--_cx)                                  //loop loc_16D1E
      goto loc_16D1E;
    _si = 0x6682;                               //mov si, 6682h
    _ax = 0x060d;                               //mov ax, 60Dh
    _cx = 0x0008;                               //mov cx, 8
loc_16D3A:                                      //loc_16D3A:
    _push(_si);                                 //push si
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _indirectCall(_ds, memory16(_ds, 0xC));     //call word ptr ds:0Ch
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
    _si = _pop();                               //pop si
    _ah += 1;                                   //inc ah
    _ah += 1;                                   //inc ah
    if (--_cx)                                  //loop loc_16D3A
      goto loc_16D3A;
    _indirectCall(_ds, memory16(_ds, 0x1C));    //call word ptr ds:1Ch
    memory(_ds, 0x97DA) = 0x01;                 //mov byte ptr ds:97DAh, 1
    _cx = 0x01e0;                               //mov cx, 1E0h
loc_16D57:                                      //loc_16D57:
    _push(_cx);                                 //push cx
    sub_19B1C();                                //call sub_19B1C
    sub_19BDC();                                //call sub_19BDC
    if (_al & 0x10)                             //jnz short loc_16D66
      goto loc_16D66;
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_16D57
      goto loc_16D57;
    return;                                     //retn
loc_16D66:                                      //loc_16D66:
{loc_1C3B0(); return; };                        //
}

void sub_16D69()
{
    sub_16C69();                                //call sub_16C69
    if (!_flags.carry)                          //jnb short locret_16D7D
      goto locret_16D7D;
    _push(_bx);                                 //push bx
    sub_16EB2();                                //call sub_16EB2
    _bx = _pop();                               //pop bx
    _cx = 0x000a;                               //mov cx, 0Ah
    _si = 0x6671;                               //mov si, 6671h
    _di = _bx;                                  //mov di, bx
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
locret_16D7D:                                   //locret_16D7D:
    return;
}

void sub_16E16()
{
    _ax = _ax ^ _ax;                            //xor ax, ax
    _dx = memory16(_ds, 0x69F0);                //mov dx, ds:69F0h
    _al = _dh;                                  //mov al, dh
    _al -= 0x08;                                //sub al, 8
    _ax &= 0xfffe;                              //and ax, 0FFFEh
    _bx = _ax;                                  //mov bx, ax
    _ax <<= 1;                                  //shl ax, 1
    _bx += _ax;                                 //add bx, ax
    _dh = _dh ^ _dh;                            //xor dh, dh
    _dx -= 0x000e;                              //sub dx, 0Eh
    _dx >>= 1;                                  //shr dx, 1
    _bx += _dx;                                 //add bx, dx
    _bx += 0x69f8;                              //add bx, 69F8h
    _al = memory(_ds, _bx);                     //mov al, [bx]
}

void sub_16E39()
{
    _ax = memory16(_ds, 0x69F2);                //mov ax, ds:69F2h
    _si = 0x69ee;                               //mov si, 69EEh
    _indirectCall(_ds, memory16(_ds, 0xC));     //call word ptr ds:0Ch
    _ax = memory16(_ds, 0x69F0);                //mov ax, ds:69F0h
    _si = 0x69ec;                               //mov si, 69ECh
    _indirectCall(_ds, memory16(_ds, 0xC));     //call word ptr ds:0Ch
    _indirectCall(_ds, memory16(_ds, 0x1C));    //call word ptr ds:1Ch
    _ax = memory16(_ds, 0x69F2);                //mov ax, ds:69F2h
    _si = 0x69ee;                               //mov si, 69EEh
    _indirectCall(_ds, memory16(_ds, 0xC));     //call word ptr ds:0Ch
    _ax = memory16(_ds, 0x69F0);                //mov ax, ds:69F0h
    _si = 0x69ec;                               //mov si, 69ECh
    _indirectCall(_ds, memory16(_ds, 0xC));     //call word ptr ds:0Ch
}

void sub_16E66()
{
    _ax = memory16(_ds, 0x69F0);                //mov ax, ds:69F0h
    memory16(_ds, 0x69F2) = _ax;                //mov ds:69F2h, ax
    memory16(_ds, 0x69F0) = _dx;                //mov ds:69F0h, dx
    sub_16E39();                                //call sub_16E39
}

void sub_16E74()
{
    _ax = memory16(_ds, 0x69F6);                //mov ax, ds:69F6h
    _si = 0x69ee;                               //mov si, 69EEh
    _indirectCall(_ds, memory16(_ds, 0xC));     //call word ptr ds:0Ch
    _ax = memory16(_ds, 0x69F4);                //mov ax, ds:69F4h
    _si = 0x69ec;                               //mov si, 69ECh
    _indirectCall(_ds, memory16(_ds, 0xC));     //call word ptr ds:0Ch
    _indirectCall(_ds, memory16(_ds, 0x1C));    //call word ptr ds:1Ch
    _ax = memory16(_ds, 0x69F6);                //mov ax, ds:69F6h
    _si = 0x69ee;                               //mov si, 69EEh
    _indirectCall(_ds, memory16(_ds, 0xC));     //call word ptr ds:0Ch
    _ax = memory16(_ds, 0x69F4);                //mov ax, ds:69F4h
    _si = 0x69ec;                               //mov si, 69ECh
    _indirectCall(_ds, memory16(_ds, 0xC));     //call word ptr ds:0Ch
}

void sub_16EA1()
{
    _ax = memory16(_ds, 0x69F4);                //mov ax, ds:69F4h
    memory16(_ds, 0x69F6) = _ax;                //mov ds:69F6h, ax
    memory16(_ds, 0x69F4) = _dx;                //mov ds:69F4h, dx
    sub_16E74();                                //call sub_16E74
}

void sub_16EB2()
{
    _ax = 0x090e;                               //mov ax, 90Eh
    memory16(_ds, 0x69F0) = _ax;                //mov ds:69F0h, ax
    memory16(_ds, 0x69F2) = _ax;                //mov ds:69F2h, ax
    _ax = 0x150e;                               //mov ax, 150Eh
    memory16(_ds, 0x69F4) = _ax;                //mov ds:69F4h, ax
    memory16(_ds, 0x69F6) = _ax;                //mov ds:69F6h, ax
    _di = 0x6671;                               //mov di, 6671h
    _cx = 0x000a;                               //mov cx, 0Ah
    _al = 0x0e;                                 //mov al, 0Eh
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    memory16(_ds, 0x6AB0) = 0x6671;             //mov word ptr ds:6AB0h, 6671h
    _indirectCall(_ds, memory16(_ds, 0x26));    //call word ptr ds:26h
    _ax = 0x0005;                               //mov ax, 5
    _si = 0x93a1;                               //mov si, 93A1h
    _indirectCall(_ds, memory16(_ds, 0x46));    //call word ptr ds:46h
    _ax = 0x0105;                               //mov ax, 105h
    _si = 0x93c1;                               //mov si, 93C1h
    _indirectCall(_ds, memory16(_ds, 0x46));    //call word ptr ds:46h
    _ax = 0x0205;                               //mov ax, 205h
    _si = 0x93e1;                               //mov si, 93E1h
    _indirectCall(_ds, memory16(_ds, 0x46));    //call word ptr ds:46h
    _bx = 0x69de;                               //mov bx, 69DEh
    sub_19C43();                                //call sub_19C43
    _ax = 0x140e;                               //mov ax, 140Eh
    _si = 0x6671;                               //mov si, 6671h
    _indirectCall(_ds, memory16(_ds, 0xC));     //call word ptr ds:0Ch
    _indirectCall(_ds, memory16(_ds, 0x1C));    //call word ptr ds:1Ch
    _ax = 0x0005;                               //mov ax, 5
    _si = 0x93a1;                               //mov si, 93A1h
    _indirectCall(_ds, memory16(_ds, 0x46));    //call word ptr ds:46h
    _ax = 0x0105;                               //mov ax, 105h
    _si = 0x93c1;                               //mov si, 93C1h
    _indirectCall(_ds, memory16(_ds, 0x46));    //call word ptr ds:46h
    _ax = 0x0205;                               //mov ax, 205h
    _si = 0x93e1;                               //mov si, 93E1h
    _indirectCall(_ds, memory16(_ds, 0x46));    //call word ptr ds:46h
    _bx = 0x69de;                               //mov bx, 69DEh
    sub_19C43();                                //call sub_19C43
    _ax = 0x140e;                               //mov ax, 140Eh
    _si = 0x6671;                               //mov si, 6671h
    _indirectCall(_ds, memory16(_ds, 0xC));     //call word ptr ds:0Ch
    sub_16E39();                                //call sub_16E39
    sub_16E74();                                //call sub_16E74
loc_16F3E:                                      //loc_16F3E:
    _ax = 0x140e;                               //mov ax, 140Eh
    _si = 0x6671;                               //mov si, 6671h
    _indirectCall(_ds, memory16(_ds, 0xC));     //call word ptr ds:0Ch
    _indirectCall(_ds, memory16(_ds, 0x1C));    //call word ptr ds:1Ch
    _ax = 0x140e;                               //mov ax, 140Eh
    _si = 0x6671;                               //mov si, 6671h
    _indirectCall(_ds, memory16(_ds, 0xC));     //call word ptr ds:0Ch
    _cx = 0x0006;                               //mov cx, 6
loc_16F59:                                      //loc_16F59:
    sub_19B1C();                                //call sub_19B1C
    if (--_cx)                                  //loop loc_16F59
      goto loc_16F59;
    sub_1C4CA();                                //call sub_1C4CA
    if (memory(_ds, 0x6AAF) != 0x01)            //jnz short loc_16F71
      goto loc_16F71;
    if (_al & 0x10)                             //jnz short loc_16F71
      goto loc_16F71;
    memory(_ds, 0x6AAF) = 0x00;                 //mov byte ptr ds:6AAFh, 0
loc_16F71:                                      //loc_16F71:
    _dx = memory16(_ds, 0x69F0);                //mov dx, ds:69F0h
    if (!(_al & 0x08))                          //jz short loc_16F7C
      goto loc_16F7C;
    _dh -= 0x02;                                //sub dh, 2
loc_16F7C:                                      //loc_16F7C:
    if (!(_al & 0x04))                          //jz short loc_16F83
      goto loc_16F83;
    _dh += 0x02;                                //add dh, 2
loc_16F83:                                      //loc_16F83:
    if (!(_al & 0x01))                          //jz short loc_16F8A
      goto loc_16F8A;
    _dl += 0x02;                                //add dl, 2
loc_16F8A:                                      //loc_16F8A:
    if (!(_al & 0x02))                          //jz short loc_16F91
      goto loc_16F91;
    _dl -= 0x02;                                //sub dl, 2
loc_16F91:                                      //loc_16F91:
    if (_al & 0x10)                             //jnz short loc_16FBC
      goto loc_16FBC;
    if (_dl != 0x0c)                            //jnz short loc_16F9F
      goto loc_16F9F;
    _dl = 0x0e;                                 //mov dl, 0Eh
    goto loc_16FA6;                             //jmp short loc_16FA6
    _STOP_("db 90h");                           //db 90h
loc_16F9F:                                      //loc_16F9F:
    if (_dl != 0x1a)                            //jnz short loc_16FA6
      goto loc_16FA6;
    _dl = 0x18;                                 //mov dl, 18h
loc_16FA6:                                      //loc_16FA6:
    if (_dh != 0x07)                            //jnz short loc_16FB0
      goto loc_16FB0;
    _dh = 0x09;                                 //mov dh, 9
    goto loc_16FB7;                             //jmp short loc_16FB7
loc_16FB0:                                      //loc_16FB0:
    if (_dh != 0x13)                            //jnz short loc_16FB7
      goto loc_16FB7;
    _dh = 0x11;                                 //mov dh, 11h
loc_16FB7:                                      //loc_16FB7:
    sub_16E66();                                //call sub_16E66
    goto loc_16F3E;                             //jmp short loc_16F3E
loc_16FBC:                                      //loc_16FBC:
    if (memory(_ds, 0x6AAF) != 0x01)            //jnz short loc_16FC6
      goto loc_16FC6;
    goto loc_16F3E;                             //jmp loc_16F3E
loc_16FC6:                                      //loc_16FC6:
    sub_16E16();                                //call sub_16E16
    memory(_ds, 0x6AAF) = 0x01;                 //mov byte ptr ds:6AAFh, 1
    if (_al == 0x11)                            //jz short loc_16FE2
      goto loc_16FE2;
    if (_al != 0x10)                            //jnz short loc_16FDC
      goto loc_16FDC;
    sub_16FF5();                                //call sub_16FF5
    goto loc_16F3E;                             //jmp loc_16F3E
loc_16FDC:                                      //loc_16FDC:
    sub_17018();                                //call sub_17018
    goto loc_16F3E;                             //jmp loc_16F3E
loc_16FE2:                                      //loc_16FE2:
    _si = 0x6671;                               //mov si, 6671h
    _cx = 0x000a;                               //mov cx, 0Ah
loc_16FE8:                                      //loc_16FE8:
    _al = memory(_ds, _si);                     //mov al, [si]
    if (_al != 0x0e)                            //jnz short loc_16FF1
      goto loc_16FF1;
    memory(_ds, _si) = 0x20;                    //mov byte ptr [si], 20h
loc_16FF1:                                      //loc_16FF1:
    _si += 1;                                   //inc si
    if (--_cx)                                  //loop loc_16FE8
      goto loc_16FE8;
}

void sub_16FF5()
{
    _di = memory16(_ds, 0x6AB0);                //mov di, ds:6AB0h
    _di -= 1;                                   //dec di
    if (_di == 0x6670)                          //jz short locret_17017
      goto locret_17017;
    memory(_ds, _di) = 0x0e;                    //mov byte ptr [di], 0Eh
    memory16(_ds, 0x6AB0) = _di;                //mov ds:6AB0h, di
    _dx = memory16(_ds, 0x6AB0);                //mov dx, ds:6AB0h
    _dx -= 0x6671;                              //sub dx, 6671h
    _dh = 0x15;                                 //mov dh, 15h
    _dl += 0x0e;                                //add dl, 0Eh
    sub_16EA1();                                //call sub_16EA1
locret_17017:                                   //locret_17017:
    return;
}

void sub_17018()
{
    _di = memory16(_ds, 0x6AB0);                //mov di, ds:6AB0h
    if (_di == 0x667b)                          //jz short loc_17029
      goto loc_17029;
    memory(_ds, _di) = _al;                     //mov [di], al
    _di += 1;                                   //inc di
    memory16(_ds, 0x6AB0) = _di;                //mov ds:6AB0h, di
loc_17029:                                      //loc_17029:
    _dx = memory16(_ds, 0x6AB0);                //mov dx, ds:6AB0h
    _dx -= 0x6671;                              //sub dx, 6671h
    _dh = 0x15;                                 //mov dh, 15h
    if (_dl != 0x0a)                            //jnz short loc_1703A
      goto loc_1703A;
    _dl = 0x09;                                 //mov dl, 9
loc_1703A:                                      //loc_1703A:
    _dl += 0x0e;                                //add dl, 0Eh
    _push(_ax);                                 //push ax
    sub_16EA1();                                //call sub_16EA1
    _ax = _pop();                               //pop ax
}

void sub_17047()
{
    memory16(_ds, 0x6C43) = 0x0000;             //mov word ptr ds:6C43h, 0
    _ax = memory16(_ds, 0x8BF0);                //mov ax, ds:8BF0h
    memory16(_ds, 0x6C45) = _ax;                //mov ds:6C45h, ax
    memory16(_ds, 0x6C45) &= 0x0007;            //and word ptr ds:6C45h, 7
    _indirectCall(_ds, memory16(_ds, 0x12));    //call word ptr ds:12h
}

void sub_1705D()
{
    if (memory16(_ds, 0x7E16) != 0x0001)        //jnz short loc_17065
      goto loc_17065;
    return;                                     //retn
loc_17065:                                      //loc_17065:
    _ax = memory16(_ds, 0x8BF0);                //mov ax, ds:8BF0h
    _ax &= 0x0007;                              //and ax, 7
    _dx = memory16(_ds, 0xB20);                 //mov dx, ds:0B20h
    _dx -= _ax;                                 //sub dx, ax
    if ((short)_dx >= (short)0x009b)            //jge short loc_17082
      goto loc_17082;
    _bx = memory16(_ds, 0x6C43);                //mov bx, ds:6C43h
    _flags.sign = !!(_bx & 0x8000);             //or bx, bx
    _bx |= _bx;
    if (_flags.sign)                            //js short loc_17099
      goto loc_17099;
    goto locret_1709C;                          //jmp short locret_1709C
loc_17082:                                      //loc_17082:
    if ((short)_dx < (short)0x0086)             //jl short locret_1709C
      goto locret_1709C;
    _bx = memory16(_ds, 0x6C43);                //mov bx, ds:6C43h
    _flags.sign = !!(_bx & 0x8000);             //or bx, bx
    _bx |= _bx;
    if (_bx == 0)                               //jz short locret_1709C
      goto locret_1709C;
    if (!_flags.sign)                           //jns short loc_17095
      goto loc_17095;
    goto locret_1709C;                          //jmp short locret_1709C
    _STOP_("db 90h");                           //db 90h
loc_17095:                                      //loc_17095:
    sub_170E6();                                //call sub_170E6
    return;                                     //retn
loc_17099:                                      //loc_17099:
    sub_1709D();                                //call sub_1709D
locret_1709C:                                   //locret_1709C:
    return;
}

void sub_1709D()
{
    _ax = memory16(_ds, 0x8BF0);                //mov ax, ds:8BF0h
    _dx = _ax;                                  //mov dx, ax
    _ax = _ax + memory16(_ds, 0x6C43);          //add ax, ds:6C43h
    if ((short)_ax >= (short)memory16(_ds, 0x8BF2))//jge short loc_170BB
      goto loc_170BB;
    _cx = memory16(_ds, 0x8BF2);                //mov cx, ds:8BF2h
    _cx = _cx - memory16(_ds, 0x8BF0);          //sub cx, ds:8BF0h
    memory16(_ds, 0x6C43) = _cx;                //mov ds:6C43h, cx
    _ax = memory16(_ds, 0x8BF2);                //mov ax, ds:8BF2h
loc_170BB:                                      //loc_170BB:
    memory16(_ds, 0x8BF0) = _ax;                //mov ds:8BF0h, ax
    if (_dx == _ax)                             //jz short locret_170E1
      goto locret_170E1;
    _dx &= 0x0007;                              //and dx, 7
    _flags.sign = (short)(_dx + memory16(_ds, 0x6C43)) < 0;
    _dx = _dx + memory16(_ds, 0x6C43);
    if (!_flags.sign)                           //jns short loc_170E2
      goto loc_170E2;
    sub_195EA();                                //call sub_195EA
    sub_1930A();                                //call sub_1930A
    _indirectCall(_ds, memory16(_ds, 0x14));    //call word ptr ds:14h
    sub_17180();                                //call sub_17180
    _dx = 0x0008;                               //mov dx, 8
    sub_17132();                                //call sub_17132
    sub_15FE4();                                //call sub_15FE4
locret_170E1:                                   //locret_170E1:
    return;                                     //retn
loc_170E2:                                      //loc_170E2:
    sub_17180();                                //call sub_17180
}

void sub_170E6()
{
    _ax = memory16(_ds, 0x8BF0);                //mov ax, ds:8BF0h
    _dx = _ax;                                  //mov dx, ax
    _ax = _ax + memory16(_ds, 0x6C43);          //add ax, ds:6C43h
    if ((short)_ax <= (short)memory16(_ds, 0x8BF4))//jle short loc_17104
      goto loc_17104;
    _cx = memory16(_ds, 0x8BF4);                //mov cx, ds:8BF4h
    _cx = _cx - memory16(_ds, 0x8BF0);          //sub cx, ds:8BF0h
    memory16(_ds, 0x6C43) = _cx;                //mov ds:6C43h, cx
    _ax = memory16(_ds, 0x8BF4);                //mov ax, ds:8BF4h
loc_17104:                                      //loc_17104:
    memory16(_ds, 0x8BF0) = _ax;                //mov ds:8BF0h, ax
    if (_dx == _ax)                             //jz short locret_1712D
      goto locret_1712D;
    _dx &= 0x0007;                              //and dx, 7
    _dx = _dx + memory16(_ds, 0x6C43);          //add dx, ds:6C43h
    if ((short)_dx <= (short)0x0007)            //jle short loc_1712E
      goto loc_1712E;
    sub_1961D();                                //call sub_1961D
    sub_192DA();                                //call sub_192DA
    _indirectCall(_ds, memory16(_ds, 0x16));    //call word ptr ds:16h
    sub_17180();                                //call sub_17180
    _dx = 0xfff8;                               //mov dx, 0FFF8h
    sub_17132();                                //call sub_17132
    sub_15FE4();                                //call sub_15FE4
locret_1712D:                                   //locret_1712D:
    return;                                     //retn
loc_1712E:                                      //loc_1712E:
    sub_17180();                                //call sub_17180
}

void sub_17132()
{
    _si = 0x0b00;                               //mov si, 0B00h
loc_17135:                                      //loc_17135:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (_flags.sign)                            //js short loc_17145
      goto loc_17145;
    if (_ax == 0)                               //jz short loc_17140
      goto loc_17140;
    memory16(_ds, _si + 4) += _dx;              //add [si+4], dx
loc_17140:                                      //loc_17140:
    _si += 0x001c;                              //add si, 1Ch
    goto loc_17135;                             //jmp short loc_17135
loc_17145:                                      //loc_17145:
    _si = 0x0c28;                               //mov si, 0C28h
loc_17148:                                      //loc_17148:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (_flags.sign)                            //js short loc_17162
      goto loc_17162;
    if (!(_al & 0x01))                          //jz short loc_1715D
      goto loc_1715D;
    memory16(_ds, _si + 4) += _dx;              //add [si+4], dx
    sub_1613C();                                //call sub_1613C
    if (!_flags.carry)                          //jnb short loc_1715D
      goto loc_1715D;
    sub_1615F();                                //call sub_1615F
loc_1715D:                                      //loc_1715D:
    _si += 0x0034;                              //add si, 34h
    goto loc_17148;                             //jmp short loc_17148
loc_17162:                                      //loc_17162:
    _si = 0x0b56;                               //mov si, 0B56h
loc_17165:                                      //loc_17165:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (_flags.sign)                            //js short locret_1717F
      goto locret_1717F;
    if (!(_al & 0x01))                          //jz short loc_1717A
      goto loc_1717A;
    memory16(_ds, _si + 4) += _dx;              //add [si+4], dx
    sub_1613C();                                //call sub_1613C
    if (!_flags.carry)                          //jnb short loc_1717A
      goto loc_1717A;
    sub_1615F();                                //call sub_1615F
loc_1717A:                                      //loc_1717A:
    _si += 0x0034;                              //add si, 34h
    goto loc_17165;                             //jmp short loc_17165
locret_1717F:                                   //locret_1717F:
    return;
}

void sub_17180()
{
    _ax = memory16(_ds, 0x6C45);                //mov ax, ds:6C45h
    _ax = _ax + memory16(_ds, 0x6C43);          //add ax, ds:6C43h
    _ax &= 0x00ff;                              //and ax, 0FFh
    memory16(_ds, 0x6C45) = _ax;                //mov ds:6C45h, ax
}

void sub_1718E()
{
    if (memory16(_ds, _si) & 0xffff)            //jnz short loc_17196
      goto loc_17196;
    _flags.carry = false;                       //clc
    return;                                     //retn
loc_17196:                                      //loc_17196:
    if (!(memory16(_ds, _si + 24) & 0xffff))    //jz short loc_171A2
      goto loc_171A2;
    memory16(_ds, _si + 24) -= 1;               //dec word ptr [si+18h]
    _flags.carry = false;                       //clc
    return;                                     //retn
loc_171A2:                                      //loc_171A2:
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_dx);                                 //push dx
    _dx = _dx ^ _dx;                            //xor dx, dx
    _bx = memory16(_ds, _si + 22);              //mov bx, [si+16h]
loc_171AA:                                      //loc_171AA:
    _ax = memory16(_ds, _bx);                   //mov ax, [bx]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (_flags.sign)                            //js short loc_171BB
      goto loc_171BB;
    memory16(_ds, _si + 10) = _ax;              //mov [si+0Ah], ax
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    memory16(_ds, _si + 22) = _bx;              //mov [si+16h], bx
    goto loc_171F5;                             //jmp short loc_171F5
    _STOP_("db 90h");                           //db 90h
loc_171BB:                                      //loc_171BB:
    if (_ax != 0xffff)                          //jnz short loc_171CD
      goto loc_171CD;
    _ax = memory16(_ds, _bx + 2);               //mov ax, [bx+2]
    _bx += _ax;                                 //add bx, ax
    memory16(_ds, _si + 22) = _si;              //mov [si+16h], si
    _dx = 0xffff;                               //mov dx, 0FFFFh
    goto loc_171AA;                             //jmp short loc_171AA
loc_171CD:                                      //loc_171CD:
    if (_ax != 0xfffd)                          //jnz short loc_171E0
      goto loc_171E0;
    _ax = memory16(_ds, _bx + 2);               //mov ax, [bx+2]
    sub_1AECD();                                //call sub_1AECD
    _bx += 0x0004;                              //add bx, 4
    memory16(_ds, _si + 22) = _bx;              //mov [si+16h], bx
    goto loc_171AA;                             //jmp short loc_171AA
loc_171E0:                                      //loc_171E0:
    _ax = memory16(_ds, _bx + 2);               //mov ax, [bx+2]
    memory16(_ds, _si + 24) = _ax;              //mov [si+18h], ax
    memory16(_ds, _si + 24) -= 1;               //dec word ptr [si+18h]
    _ax = memory16(_ds, _bx + 4);               //mov ax, [bx+4]
    memory16(_ds, _si + 10) = _ax;              //mov [si+0Ah], ax
    _bx += 0x0006;                              //add bx, 6
    memory16(_ds, _si + 22) = _bx;              //mov [si+16h], bx
loc_171F5:                                      //loc_171F5:
    _dx |= _dx;                                 //or dx, dx
    if (_dx != 0)                               //jnz short loc_171FE
      goto loc_171FE;
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    _flags.carry = false;                       //clc
    return;                                     //retn
loc_171FE:                                      //loc_171FE:
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    _flags.carry = true;                        //stc
}

void sub_17205()
{
    sub_177FB();                                //call sub_177FB
    _si = 0x0b56;                               //mov si, 0B56h
loc_1720B:                                      //loc_1720B:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (_flags.sign)                            //js short locret_1721F
      goto locret_1721F;
    if (!(_al & 0x01))                          //jz short loc_1721A
      goto loc_1721A;
    _push(_si);                                 //push si
    sub_17222();                                //call sub_17222
    _si = _pop();                               //pop si
loc_1721A:                                      //loc_1721A:
    _si += 0x0034;                              //add si, 34h
    goto loc_1720B;                             //jmp short loc_1720B
locret_1721F:                                   //locret_1721F:
    return;
}

void sub_17222()
{
    WORD _cs = _seg001;

    memory16(_ds, 0x6E20) = 0x0000;             //mov word ptr ds:6E20h, 0
    memory16(_ds, 0x6E03) = 0x0000;             //mov word ptr ds:6E03h, 0
    if (memory16(_ds, _si + 24) == 0x0000)      //jz short loc_17246
      goto loc_17246;
    memory16(_ds, _si + 24) -= 1;               //dec word ptr [si+18h]
    if (memory16(_ds, _si + 22) != 0x0001)      //jnz short loc_17240
      goto loc_17240;
{loc_176A0(); return; };                        //
loc_17240:                                      //loc_17240:
    memory16(_ds, 0x6E20) = 0x0001;             //mov word ptr ds:6E20h, 1
loc_17246:                                      //loc_17246:
    memory16(_ds, _si + 44) = 0x0000;           //mov word ptr [si+2Ch], 0
    memory16(_ds, _si + 46) = 0x0000;           //mov word ptr [si+2Eh], 0
    if (memory16(_ds, _si + 22) != 0x0001)      //jnz short loc_17259
      goto loc_17259;
{loc_176A0(); return; };                        //
loc_17259:                                      //loc_17259:
    if (memory16(_ds, _si + 42) != 0x0001)      //jnz short loc_17262
      goto loc_17262;
    goto loc_17644;                             //jmp loc_17644
loc_17262:                                      //loc_17262:
    memory16(_ds, _si + 44) = 0x0000;           //mov word ptr [si+2Ch], 0
    memory16(_ds, _si + 46) = 0x0000;           //mov word ptr [si+2Eh], 0
    memory16(_ds, _si + 34) = 0x0000;           //mov word ptr [si+22h], 0
    memory16(_ds, _si + 36) = 0x0000;           //mov word ptr [si+24h], 0
    memory16(_ds, _si + 38) = 0x0000;           //mov word ptr [si+26h], 0
    memory16(_ds, _si + 40) = 0x0000;           //mov word ptr [si+28h], 0
    memory(_ds, 0x796B) = 0x01;                 //mov byte ptr ds:796Bh, 1
    memory16(_ds, 0x6E03) = 0x0000;             //mov word ptr ds:6E03h, 0
    _dx = memory16(_ds, _si + 8);               //mov dx, [si+8]
    _dx += 0x0080;                              //add dx, 80h
    if ((short)_dx <= (short)0x0800)            //jle short loc_1729C
      goto loc_1729C;
    _dx = 0x0800;                               //mov dx, 800h
loc_1729C:                                      //loc_1729C:
    memory16(_ds, _si + 8) = _dx;               //mov [si+8], dx
    memory16(_ds, 0x7961) = _dx;                //mov ds:7961h, dx
    _flags.sign = !!(_dx & 0x8000);             //or dx, dx
    _dx |= _dx;
    if (_flags.sign)                            //js short loc_172AC
      goto loc_172AC;
    _ch = _ch ^ _ch;                            //xor ch, ch
    goto loc_172AE;                             //jmp short loc_172AE
loc_172AC:                                      //loc_172AC:
    _ch = 0xff;                                 //mov ch, 0FFh
loc_172AE:                                      //loc_172AE:
    _ax = memory16(_ds, _si + 4);               //mov ax, [si+4]
    _cl = memory(_ds, _si + 6);                 //mov cl, [si+6]
    _flags.carry = (_cl + _dl) >= 0x100;        //add cl, dl
    _cl += _dl;
    _flags.carry2 = (_al + _dh + _flags.carry) >= 0x100;
    _al = _al + _dh + _flags.carry;_flags.carry = flags.carry2;
    _ah = _ah + _ch + _flags.carry;             //adc ah, ch
    memory16(_ds, 0x795F) = _ax;                //mov ds:795Fh, ax
    _dx = memory16(_ds, _si + 2);               //mov dx, [si+2]
    memory16(_ds, 0x795D) = _dx;                //mov ds:795Dh, dx
    memory(_ds, 0x796B) = 0x01;                 //mov byte ptr ds:796Bh, 1
    sub_17DFB();                                //call sub_17DFB
loc_172CD:                                      //loc_172CD:
    _ch = memory(_ds, 0x7963);                  //mov ch, ds:7963h
    if (!(_ch & 0x20))                          //jz short loc_172DA
      goto loc_172DA;
{sub_17674(); return; };                        //
loc_172DA:                                      //loc_172DA:
    if (!(_ch & 0x40))                          //jz short loc_1733D
      goto loc_1733D;
    _ax = memory16(_ds, 0x7964);                //mov ax, ds:7964h
    _cl = _cl ^ _cl;                            //xor cl, cl
    _ax -= 0x0015;                              //sub ax, 15h
    memory16(_ds, 0x795F) = _ax;                //mov ds:795Fh, ax
    memory16(_ds, _si + 4) = _ax;               //mov [si+4], ax
    memory(_ds, _si + 6) = 0x00;                //mov byte ptr [si+6], 0
    memory16(_ds, _si + 34) = 0x0001;           //mov word ptr [si+22h], 1
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, 0x7966);                //mov ax, ds:7966h
    memory16(_ds, _si + 44) = _ax;              //mov [si+2Ch], ax
    _ax = _pop();                               //pop ax
    memory(_ds, 0x796B) = 0x00;                 //mov byte ptr ds:796Bh, 0
    sub_17DFB();                                //call sub_17DFB
    _ch = memory(_ds, 0x7963);                  //mov ch, ds:7963h
    if (!(_ch & 0x20))                          //jz short loc_17315
      goto loc_17315;
{sub_17674(); return; };                        //
loc_17315:                                      //loc_17315:
    _ch &= 0x06;                                //and ch, 6
    if (_ch == 0)                               //jz short loc_17321
      goto loc_17321;
    _ch = memory(_ds, 0x7963);                  //mov ch, ds:7963h
    goto loc_1735C;                             //jmp short loc_1735C
    _STOP_("db 90h");                           //db 90h
loc_17321:                                      //loc_17321:
    _bp = memory16(_cs, _si + 44);              //mov bp, cs:[si+2Ch]
    _bp = _bp | memory16(_cs, _si + 46);        //or bp, cs:[si+2Eh]
    _bp |= _bp;                                 //or bp, bp
    if (_bp == 0)                               //jz short loc_17333
      goto loc_17333;
    memory16(_ds, 0x6E03) = 0x0001;             //mov word ptr ds:6E03h, 1
loc_17333:                                      //loc_17333:
    _ch = memory(_ds, 0x7963);                  //mov ch, ds:7963h
    _dx = 0x0100;                               //mov dx, 100h
    goto loc_173E4;                             //jmp loc_173E4
loc_1733D:                                      //loc_1733D:
    if (!(_ch & 0x20))                          //jz short loc_17346
      goto loc_17346;
{sub_17674(); return; };                        //
loc_17346:                                      //loc_17346:
    if (_ch & 0x04)                             //jnz short loc_1736D
      goto loc_1736D;
    if (_ch & 0x02)                             //jnz short loc_17355
      goto loc_17355;
    goto loc_1740E;                             //jmp loc_1740E
loc_17355:                                      //loc_17355:
    _bp = memory16(_ds, _si + 8);               //mov bp, [si+8]
    _flags.sign = !!(_bp & 0x8000);             //or bp, bp
    _bp |= _bp;
    if (!_flags.sign)                           //jns short loc_1736D
      goto loc_1736D;
loc_1735C:                                      //loc_1735C:
    _ax |= 0x0007;                              //or ax, 7
    _ax += 1;                                   //inc ax
    _cl = _cl ^ _cl;                            //xor cl, cl
    memory16(_ds, _si + 8) = 0x0100;            //mov word ptr [si+8], 100h
    _dx = 0x0100;                               //mov dx, 100h
    goto loc_1740E;                             //jmp loc_1740E
loc_1736D:                                      //loc_1736D:
    if (memory16(_ds, _si + 48) != 0x0003)      //jnz short loc_17394
      goto loc_17394;
    if (!(_ch & 0x10))                          //jz short loc_17394
      goto loc_17394;
    sub_176F4();                                //call sub_176F4
    if (_flags.carry)                           //jb short loc_17394
      goto loc_17394;
    _bx = memory16(_ds, _si + 2);               //mov bx, [si+2]
    _bx &= 0x001f;                              //and bx, 1Fh
    if (_bx != 0x0004)                          //jnz short loc_17394
      goto loc_17394;
    memory16(_ds, _si + 42) = 0x0001;           //mov word ptr [si+2Ah], 1
    goto loc_1740E;                             //jmp short loc_1740E
loc_17394:                                      //loc_17394:
    memory16(_ds, _si + 42) = 0x0000;           //mov word ptr [si+2Ah], 0
    memory16(_ds, _si + 34) = 0x0001;           //mov word ptr [si+22h], 1
    _ax += 0x000c;                              //add ax, 0Ch
    _ax |= 0x0007;                              //or ax, 7
    _ax -= 0x0014;                              //sub ax, 14h
    _cl = _cl ^ _cl;                            //xor cl, cl
    memory16(_ds, _si + 4) = _ax;               //mov [si+4], ax
    memory(_ds, _si + 6) = _cl;                 //mov [si+6], cl
    _dx = 0x0100;                               //mov dx, 100h
    if (!(_ch & 0x01))                          //jz short loc_173E4
      goto loc_173E4;
    if (memory16(_ds, 0x8BEC) != 0x0003)        //jnz short loc_173E4
      goto loc_173E4;
    _dx = memory16(_ds, _si + 8);               //mov dx, [si+8]
    if ((short)_dx < (short)0x0200)             //jl short loc_173D8
      goto loc_173D8;
    _dx = -_dx;                                 //neg dx
    _dx += 0x0060;                              //add dx, 60h
    memory16(_ds, _si + 8) = _dx;               //mov [si+8], dx
    _dx = 0xf781;                               //mov dx, 0F781h
    goto loc_1740E;                             //jmp short loc_1740E
loc_173D8:                                      //loc_173D8:
    memory16(_ds, _si + 8) = 0x0100;            //mov word ptr [si+8], 100h
    _dx = 0xfa00;                               //mov dx, 0FA00h
    goto loc_1740E;                             //jmp short loc_1740E
loc_173E4:                                      //loc_173E4:
    memory16(_ds, _si + 8) = _dx;               //mov [si+8], dx
    _dx = 0xfa00;                               //mov dx, 0FA00h
    if (!(_ch & 0x01))                          //jz short loc_1740E
      goto loc_1740E;
    if (memory16(_ds, 0x8BEC) != 0x0001)        //jnz short loc_173FF
      goto loc_173FF;
    _dx = 0xfe00;                               //mov dx, 0FE00h
    goto loc_1740E;                             //jmp short loc_1740E
    _STOP_("db 90h");                           //db 90h
loc_173FF:                                      //loc_173FF:
    if (memory16(_ds, 0x8BEC) != 0x0005)        //jnz short loc_1740E
      goto loc_1740E;
    memory16(_ds, _si + 8) = 0xf781;            //mov word ptr [si+8], 0F781h
    goto loc_1743B;                             //jmp short loc_1743B
loc_1740E:                                      //loc_1740E:
    memory16(_ds, _si + 4) = _ax;               //mov [si+4], ax
    memory(_ds, _si + 6) = _cl;                 //mov [si+6], cl
    if (memory16(_ds, _si + 48) != 0x0003)      //jnz short loc_1743B
      goto loc_1743B;
    if (!(_ch & 0x08))                          //jz short loc_1743B
      goto loc_1743B;
    if (_ch & 0x10)                             //jnz short loc_1743B
      goto loc_1743B;
    sub_176F4();                                //call sub_176F4
    if (!_flags.carry)                          //jnb short loc_1743B
      goto loc_1743B;
    _bx = memory16(_ds, _si + 2);               //mov bx, [si+2]
    _bx &= 0x001f;                              //and bx, 1Fh
    if (_bx != 0x0004)                          //jnz short loc_1743B
      goto loc_1743B;
    memory16(_ds, _si + 42) = 0x0001;           //mov word ptr [si+2Ah], 1
loc_1743B:                                      //loc_1743B:
    if (memory16(_ds, 0x6E03) != 0x0001)        //jnz short loc_1744D
      goto loc_1744D;
    _dx = memory16(_ds, _si + 44);              //mov dx, [si+2Ch]
    _bx = memory16(_ds, _si + 2);               //mov bx, [si+2]
    _bx += _dx;                                 //add bx, dx
    goto loc_17573;                             //jmp loc_17573
loc_1744D:                                      //loc_1744D:
    _bp = memory16(_cs, _si + 8);               //mov bp, cs:[si+8]
    _flags.sign = !!(_bp & 0x8000);             //or bp, bp
    _bp |= _bp;
    if (_flags.sign)                            //js short loc_1745E
      goto loc_1745E;
    if (memory16(_ds, _si + 34) == 0x0001)      //jz short loc_1745E
      goto loc_1745E;
    goto loc_1746A;                             //jmp short loc_1746A
loc_1745E:                                      //loc_1745E:
    if (memory16(_ds, _si + 48) != 0x0003)      //jnz short loc_17473
      goto loc_17473;
    if (memory16(_ds, _si + 42) != 0x0001)      //jnz short loc_17473
      goto loc_17473;
loc_1746A:                                      //loc_1746A:
    _dx = 0x0000;                               //mov dx, 0
    _bx = memory16(_ds, _si + 2);               //mov bx, [si+2]
    goto loc_17573;                             //jmp loc_17573
loc_17473:                                      //loc_17473:
    _dx = memory16(_ds, _si + 16);              //mov dx, [si+10h]
    if (!(_ch & 0x01))                          //jz short loc_174A3
      goto loc_174A3;
    if (memory16(_ds, 0x8BEC) == 0x0002)        //jz short loc_1749E
      goto loc_1749E;
    if (memory16(_ds, 0x8BEC) != 0x0004)        //jnz short loc_174A3
      goto loc_174A3;
    memory16(_ds, _si + 38) = 0x0001;           //mov word ptr [si+26h], 1
    _dx = 0x0001;                               //mov dx, 1
    if (!(memory16(_ds, _si + 16) & 0x8000))    //jz short loc_174A3
      goto loc_174A3;
    _dx = -_dx;                                 //neg dx
    goto loc_174A3;                             //jmp short loc_174A3
loc_1749E:                                      //loc_1749E:
    memory16(_ds, _si + 40) = 0x0001;           //mov word ptr [si+28h], 1
loc_174A3:                                      //loc_174A3:
    if (memory16(_ds, _si + 48) != 0x0001)      //jnz short loc_174BE
      goto loc_174BE;
    memory16(_ds, _si + 20) += 1;               //inc word ptr [si+14h]
    _ax = memory16(_ds, _si + 18);              //mov ax, [si+12h]
    if (_ax != memory16(_ds, _si + 20))         //jnz short loc_174F8
      goto loc_174F8;
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, _si + 20) = _ax;              //mov [si+14h], ax
    _dx = -_dx;                                 //neg dx
    goto loc_174F8;                             //jmp short loc_174F8
loc_174BE:                                      //loc_174BE:
    if (memory16(_ds, _si + 48) != 0x0002)      //jnz short loc_174E0
      goto loc_174E0;
    _ax = memory16(_ds, _si + 2);               //mov ax, [si+2]
    _ax &= 0x000f;                              //and ax, 0Fh
    if (_ax != 0x0004)                          //jnz short loc_174F8
      goto loc_174F8;
    sub_19B40();                                //call sub_19B40
    if (memory(_ds, 0x973F) & 0x01)             //jnz short loc_174F8
      goto loc_174F8;
    sub_176E6();                                //call sub_176E6
    goto loc_174F8;                             //jmp short loc_174F8
loc_174E0:                                      //loc_174E0:
    _ax = memory16(_ds, _si + 2);               //mov ax, [si+2]
    _ax &= 0x000f;                              //and ax, 0Fh
    if (_ax != 0x0004)                          //jnz short loc_174F8
      goto loc_174F8;
    sub_19B40();                                //call sub_19B40
    if (memory(_ds, 0x973F) & 0x01)             //jnz short loc_174F8
      goto loc_174F8;
    _dx = -_dx;                                 //neg dx
loc_174F8:                                      //loc_174F8:
    _dx = _dx + memory16(_ds, _si + 44);        //add dx, [si+2Ch]
    _bx = memory16(_ds, _si + 2);               //mov bx, [si+2]
    _bx += _dx;                                 //add bx, dx
    _flags.sign = !!(_dx & 0x8000);             //or dx, dx
    _dx |= _dx;
    if (_dx == 0)                               //jz short loc_1751E
      goto loc_1751E;
    if (!_flags.sign)                           //jns short loc_17513
      goto loc_17513;
    if ((short)_bx >= (short)0x0000)            //jge short loc_1751E
      goto loc_1751E;
    _bx = 0x0000;                               //mov bx, 0
    _dx = -_dx;                                 //neg dx
    goto loc_1751E;                             //jmp short loc_1751E
    _STOP_("db 90h");                           //db 90h
loc_17513:                                      //loc_17513:
    if ((short)_bx < (short)0x00e8)             //jl short loc_1751E
      goto loc_1751E;
    _bx = 0x00e8;                               //mov bx, 0E8h
    _dx = -_dx;                                 //neg dx
loc_1751E:                                      //loc_1751E:
    _ax = memory16(_ds, _si + 4);               //mov ax, [si+4]
    memory16(_ds, 0x795F) = _ax;                //mov ds:795Fh, ax
    memory16(_ds, 0x7961) = 0xffff;             //mov word ptr ds:7961h, 0FFFFh
    memory16(_ds, 0x795D) = _bx;                //mov ds:795Dh, bx
    memory(_ds, 0x796B) = 0x01;                 //mov byte ptr ds:796Bh, 1
    sub_17DFB();                                //call sub_17DFB
    _ch = memory(_ds, 0x7963);                  //mov ch, ds:7963h
    if (!(_ch & 0x20))                          //jz short loc_17544
      goto loc_17544;
{sub_17674(); return; };                        //
loc_17544:                                      //loc_17544:
    if (!(_ch & 0x02))                          //jz short loc_17573
      goto loc_17573;
    _flags.sign = !!(_dx & 0x8000);             //or dx, dx
    _dx |= _dx;
    if (!_flags.sign)                           //jns short loc_17562
      goto loc_17562;
    _bx += 0x000c;                              //add bx, 0Ch
    _bx &= 0x00f8;                              //and bx, 0F8h
    _bx -= 0x0004;                              //sub bx, 4
    _dx = -_dx;                                 //neg dx
    memory16(_ds, _si + 20) = 0x0000;           //mov word ptr [si+14h], 0
    goto loc_17573;                             //jmp short loc_17573
loc_17562:                                      //loc_17562:
    _bx += 0x0003;                              //add bx, 3
    _bx &= 0x00f8;                              //and bx, 0F8h
    _bx -= 0x0004;                              //sub bx, 4
    _dx = -_dx;                                 //neg dx
    memory16(_ds, _si + 20) = 0x0000;           //mov word ptr [si+14h], 0
loc_17573:                                      //loc_17573:
    if (memory16(_ds, 0x6E20) == 0x0001)        //jz short loc_17584
      goto loc_17584;
    memory16(_ds, _si + 2) = _bx;               //mov [si+2], bx
    _dx |= _dx;                                 //or dx, dx
    if (_dx == 0)                               //jz short loc_17584
      goto loc_17584;
    memory16(_ds, _si + 16) = _dx;              //mov [si+10h], dx
loc_17584:                                      //loc_17584:
    if (memory16(_ds, _si + 48) != 0x0003)      //jnz short loc_17595
      goto loc_17595;
    if (_ch & 0x08)                             //jnz short loc_17595
      goto loc_17595;
    memory16(_ds, _si + 42) = 0x0000;           //mov word ptr [si+2Ah], 0
loc_17595:                                      //loc_17595:
    if (memory16(_ds, 0x6E03) == 0x0001)        //jz short loc_175A6
      goto loc_175A6;
    if (memory16(_ds, 0x6E20) == 0x0001)        //jz short loc_175A6
      goto loc_175A6;
    sub_17723();                                //call sub_17723
loc_175A6:                                      //loc_175A6:
    if (memory16(_ds, 0x7ECC) != 0x0001)        //jnz short loc_175C6
      goto loc_175C6;
    _bx = memory16(_ds, _si + 4);               //mov bx, [si+4]
    _dh = memory(_ds, _si + 2);                 //mov dh, [si+2]
    _dl = memory(_ds, _si + 30);                //mov dl, [si+1Eh]
    _ah = memory(_ds, _si + 32);                //mov ah, [si+20h]
    sub_1646E();                                //call sub_1646E
    if (!_flags.carry)                          //jnb short loc_175C6
      goto loc_175C6;
    memory16(_ds, _si + 24) = 0x0028;           //mov word ptr [si+18h], 28h
    goto loc_175DE;                             //jmp short loc_175DE
loc_175C6:                                      //loc_175C6:
    _bx = memory16(_ds, _si + 4);               //mov bx, [si+4]
    _bx += 0x0004;                              //add bx, 4
    _dh = memory(_ds, _si + 2);                 //mov dh, [si+2]
    _dh += 0x04;                                //add dh, 4
    _dl = 0x10;                                 //mov dl, 10h
    _ah = 0x15;                                 //mov ah, 15h
    sub_16407();                                //call sub_16407
    if (!_flags.carry)                          //jnb short loc_175DE
      goto loc_175DE;
{sub_168A8(); return; };                        //
loc_175DE:                                      //loc_175DE:
    if (memory16(_ds, 0xB00) != 0x0001)         //jnz short loc_175FF
      goto loc_175FF;
    _bx = memory16(_ds, _si + 4);               //mov bx, [si+4]
    _dh = memory(_ds, _si + 2);                 //mov dh, [si+2]
    _dl = memory(_ds, _si + 30);                //mov dl, [si+1Eh]
    _ah = memory(_ds, _si + 32);                //mov ah, [si+20h]
    sub_164A0();                                //call sub_164A0
    if (!_flags.carry)                          //jnb short loc_175FF
      goto loc_175FF;
    memory16(_ds, 0xB00) = 0x0000;              //mov word ptr ds:0B00h, 0
{sub_17674(); return; };                        //
    _STOP_("db 90h");                           //db 90h
loc_175FF:                                      //loc_175FF:
    if (memory16(_ds, 0xB38) != 0x0002)         //jnz short locret_17643
      goto locret_17643;
    _al = memory(_ds, 0xB4A);                   //mov al, ds:0B4Ah
    if ((char)_al <= (char)0x01)                //jle short locret_17643
      goto locret_17643;
    if ((char)_al > (char)0x04)                 //jg short locret_17643
      goto locret_17643;
    _bx = memory16(_ds, _si + 4);               //mov bx, [si+4]
    _dh = memory(_ds, _si + 2);                 //mov dh, [si+2]
    _dl = memory(_ds, _si + 30);                //mov dl, [si+1Eh]
    _ah = memory(_ds, _si + 32);                //mov ah, [si+20h]
    if (_dh >= 0x0f)                            //jnb short loc_17627
      goto loc_17627;
    _dh = _dh ^ _dh;                            //xor dh, dh
    goto loc_1762A;                             //jmp short loc_1762A
    _STOP_("db 90h");                           //db 90h
loc_17627:                                      //loc_17627:
    _dh -= 0x10;                                //sub dh, 10h
loc_1762A:                                      //loc_1762A:
    _bx -= 0x000e;                              //sub bx, 0Eh
    _dl += 0x20;                                //add dl, 20h
    _ah += 0x1d;                                //add ah, 1Dh
    sub_164E1();                                //call sub_164E1
    if (!_flags.carry)                          //jnb short locret_17643
      goto locret_17643;
    _push(_si);                                 //push si
    _si = 0x670b;                               //mov si, 670Bh
    sub_16BC7();                                //call sub_16BC7
    _si = _pop();                               //pop si
{sub_17674(); return; };                        //
    _STOP_("db 90h");                           //db 90h
locret_17643:                                   //locret_17643:
    return;                                     //retn
loc_17644:                                      //loc_17644:
    _ax = memory16(_ds, _si + 4);               //mov ax, [si+4]
    _cl = _cl ^ _cl;                            //xor cl, cl
    _bp = memory16(_ds, 0xB20);                 //mov bp, ds:0B20h
    _bp += 1;                                   //inc bp
    _bp &= 0x00fe;                              //and bp, 0FEh
    _ax &= 0x00fe;                              //and ax, 0FEh
    sub_17702();                                //call sub_17702
    memory16(_ds, 0x7961) = _bp;                //mov ds:7961h, bp
    _ax = memory16(_ds, _si + 4);               //mov ax, [si+4]
    _ax += _bp;                                 //add ax, bp
    memory16(_ds, _si + 8) = _bp;               //mov [si+8], bp
    memory16(_ds, 0x795F) = _ax;                //mov ds:795Fh, ax
    _bx = memory16(_ds, _si + 2);               //mov bx, [si+2]
    memory16(_ds, 0x795D) = _bx;                //mov ds:795Dh, bx
    sub_17DFB();                                //call sub_17DFB
    goto loc_172CD;                             //jmp loc_172CD
}

void sub_17674()
{
    _push(_si);                                 //push si
    _si = 0x670b;                               //mov si, 670Bh
    sub_16BC7();                                //call sub_16BC7
    _si = _pop();                               //pop si
    memory16(_ds, _si + 22) = 0x0001;           //mov word ptr [si+16h], 1
    memory16(_ds, _si + 8) = 0xfb00;            //mov word ptr [si+8], 0FB00h
    _ax = 0x000c;                               //mov ax, 0Ch
    sub_1AECD();                                //call sub_1AECD
    _ax = memory16(_ds, _si + 2);               //mov ax, [si+2]
    if ((short)_ax < (short)0x0080)             //jl short loc_1769A
      goto loc_1769A;
    memory16(_ds, _si + 16) = 0xfffe;           //mov word ptr [si+10h], 0FFFEh
    return;                                     //retn
loc_1769A:                                      //loc_1769A:
    memory16(_ds, _si + 16) = 0x0002;           //mov word ptr [si+10h], 2
}

void loc_176A0()
{
    _dx = memory16(_ds, _si + 8);               //mov dx, [si+8]
    _dx += 0x0080;                              //add dx, 80h
    memory16(_ds, _si + 8) = _dx;               //mov [si+8], dx
    _flags.sign = !!(_dx & 0x8000);             //or dx, dx
    _dx |= _dx;
    if (_flags.sign)                            //js short loc_176B3
      goto loc_176B3;
    _ch = _ch ^ _ch;                            //xor ch, ch
    goto loc_176B5;                             //jmp short loc_176B5
    _STOP_("db 90h");                           //db 90h
loc_176B3:                                      //loc_176B3:
    _ch = 0xff;                                 //mov ch, 0FFh
loc_176B5:                                      //loc_176B5:
    _ax = memory16(_ds, _si + 4);               //mov ax, [si+4]
    _cl = memory(_ds, _si + 6);                 //mov cl, [si+6]
    _flags.carry = (_cl + _dl) >= 0x100;        //add cl, dl
    _cl += _dl;
    _flags.carry2 = (_al + _dh + _flags.carry) >= 0x100;
    _al = _al + _dh + _flags.carry;_flags.carry = flags.carry2;
    _ah = _ah + _ch + _flags.carry;             //adc ah, ch
    if ((short)_ax <= (short)0x0110)            //jle short loc_176CA
      goto loc_176CA;
    sub_16174();                                //call sub_16174
    return;                                     //retn
loc_176CA:                                      //loc_176CA:
    memory16(_ds, _si + 4) = _ax;               //mov [si+4], ax
    memory(_ds, _si + 6) = _cl;                 //mov [si+6], cl
    _ax = memory16(_ds, 0x73EF);                //mov ax, ds:73EFh
    _ax += 0x0006;                              //add ax, 6
    _ax = _ax + memory16(_ds, _si + 50);        //add ax, [si+32h]
    memory16(_ds, _si + 10) = _ax;              //mov [si+0Ah], ax
    _ax = memory16(_ds, _si + 16);              //mov ax, [si+10h]
    _ax = _ax + memory16(_ds, _si + 2);         //add ax, [si+2]
    memory16(_ds, _si + 2) = _ax;               //mov [si+2], ax
}

void sub_176E6()
{
    if ((short)_bx <= (short)memory16(_ds, 0xB1E))//jle short loc_176F0
      goto loc_176F0;
    _dx = 0xfffe;                               //mov dx, 0FFFEh
    return;                                     //retn
loc_176F0:                                      //loc_176F0:
    _dx = 0x0002;                               //mov dx, 2
}

void sub_176F4()
{
    if ((short)_ax < (short)memory16(_ds, 0xB20))//jl short loc_176FE
      goto loc_176FE;
    if (_ax == memory16(_ds, 0xB20))            //jz short loc_17700
      goto loc_17700;
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_176FE:                                      //loc_176FE:
    _flags.carry = false;                       //clc
    return;                                     //retn
loc_17700:                                      //loc_17700:
    _flags.carry = false;                       //clc
}

void sub_17702()
{
    if (memory16(_ds, 0x6E20) != 0x0001)        //jnz short loc_1770E
      goto loc_1770E;
    _flags.carry = false;                       //clc
    _bp = 0x0000;                               //mov bp, 0
    return;                                     //retn
loc_1770E:                                      //loc_1770E:
    if ((short)_ax < (short)_bp)                //jl short loc_17719
      goto loc_17719;
    if (_ax == _bp)                             //jz short loc_1771E
      goto loc_1771E;
    _bp = 0xfffe;                               //mov bp, 0FFFEh
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_17719:                                      //loc_17719:
    _bp = 0x0002;                               //mov bp, 2
    _flags.carry = false;                       //clc
    return;                                     //retn
loc_1771E:                                      //loc_1771E:
    _bp = 0x0000;                               //mov bp, 0
    _flags.carry = false;                       //clc
}

void sub_17723()
{
    if (memory16(_ds, _si + 42) == 0x0001)      //jz short loc_17756
      goto loc_17756;
    if (memory16(_ds, _si + 38) == 0x0001)      //jz short loc_17770
      goto loc_17770;
    if (memory16(_ds, _si + 40) == 0x0001)      //jz short loc_1778B
      goto loc_1778B;
    if (memory16(_ds, _si + 34) != 0x0001)      //jnz short locret_177A6
      goto locret_177A6;
    _ax = memory16(_ds, _si + 16);              //mov ax, [si+10h]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (_flags.sign)                            //js short loc_17748
      goto loc_17748;
    _ax = 0x0000;                               //mov ax, 0
    goto loc_1774B;                             //jmp short loc_1774B
loc_17748:                                      //loc_17748:
    _ax = 0x0003;                               //mov ax, 3
loc_1774B:                                      //loc_1774B:
    _ax = _ax + memory16(_ds, 0x73E7);          //add ax, ds:73E7h
    _ax = _ax + memory16(_ds, _si + 50);        //add ax, [si+32h]
    memory16(_ds, _si + 10) = _ax;              //mov [si+0Ah], ax
    return;                                     //retn
loc_17756:                                      //loc_17756:
    if (memory16(_ds, _si + 42) != 0x0001)      //jnz short loc_17770
      goto loc_17770;
    _ax = 0x0008;                               //mov ax, 8
    if (memory16(_ds, _si + 8) == 0x0000)       //jz short loc_17769
      goto loc_17769;
    _ax = _ax + memory16(_ds, 0x73ED);          //add ax, ds:73EDh
loc_17769:                                      //loc_17769:
    _ax = _ax + memory16(_ds, _si + 50);        //add ax, [si+32h]
    memory16(_ds, _si + 10) = _ax;              //mov [si+0Ah], ax
    return;                                     //retn
loc_17770:                                      //loc_17770:
    _ax = memory16(_ds, _si + 16);              //mov ax, [si+10h]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (_flags.sign)                            //js short loc_1777D
      goto loc_1777D;
    _ax = 0x0000;                               //mov ax, 0
    goto loc_17780;                             //jmp short loc_17780
    _STOP_("db 90h");                           //db 90h
loc_1777D:                                      //loc_1777D:
    _ax = 0x0003;                               //mov ax, 3
loc_17780:                                      //loc_17780:
    _ax = _ax + memory16(_ds, 0x73E9);          //add ax, ds:73E9h
    _ax = _ax + memory16(_ds, _si + 50);        //add ax, [si+32h]
    memory16(_ds, _si + 10) = _ax;              //mov [si+0Ah], ax
    return;                                     //retn
loc_1778B:                                      //loc_1778B:
    _ax = memory16(_ds, _si + 16);              //mov ax, [si+10h]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (_flags.sign)                            //js short loc_17798
      goto loc_17798;
    _ax = 0x0000;                               //mov ax, 0
    goto loc_1779B;                             //jmp short loc_1779B
loc_17798:                                      //loc_17798:
    _ax = 0x0003;                               //mov ax, 3
loc_1779B:                                      //loc_1779B:
    _ax = _ax + memory16(_ds, 0x73EB);          //add ax, ds:73EBh
    _ax = _ax + memory16(_ds, _si + 50);        //add ax, [si+32h]
    memory16(_ds, _si + 10) = _ax;              //mov [si+0Ah], ax
    return;                                     //retn
locret_177A6:                                   //locret_177A6:
    return;
}

void sub_177FB()
{
    _ax = memory16(_ds, 0x73F1);                //mov ax, ds:73F1h
loc_177FE:                                      //loc_177FE:
    _bx = 0x73a7;                               //mov bx, 73A7h
    _bx += _ax;                                 //add bx, ax
    _dx = memory16(_ds, _bx);                   //mov dx, [bx]
    if (_dx != 0x00ff)                          //jnz short loc_17810
      goto loc_17810;
    _ax = 0x0000;                               //mov ax, 0
    goto loc_177FE;                             //jmp short loc_177FE
loc_17810:                                      //loc_17810:
    memory16(_ds, 0x73E7) = _dx;                //mov ds:73E7h, dx
    _ax += 1;                                   //inc ax
    _ax += 1;                                   //inc ax
    memory16(_ds, 0x73F1) = _ax;                //mov ds:73F1h, ax
    _ax = memory16(_ds, 0x73F3);                //mov ax, ds:73F3h
loc_1781C:                                      //loc_1781C:
    _bx = 0x73b5;                               //mov bx, 73B5h
    _bx += _ax;                                 //add bx, ax
    _dx = memory16(_ds, _bx);                   //mov dx, [bx]
    if (_dx != 0x00ff)                          //jnz short loc_1782E
      goto loc_1782E;
    _ax = 0x0000;                               //mov ax, 0
    goto loc_1781C;                             //jmp short loc_1781C
loc_1782E:                                      //loc_1782E:
    memory16(_ds, 0x73E9) = _dx;                //mov ds:73E9h, dx
    _ax += 1;                                   //inc ax
    _ax += 1;                                   //inc ax
    memory16(_ds, 0x73F3) = _ax;                //mov ds:73F3h, ax
    _ax = memory16(_ds, 0x73F5);                //mov ax, ds:73F5h
loc_1783A:                                      //loc_1783A:
    _bx = 0x73cf;                               //mov bx, 73CFh
    _bx += _ax;                                 //add bx, ax
    _dx = memory16(_ds, _bx);                   //mov dx, [bx]
    if (_dx != 0x00ff)                          //jnz short loc_1784C
      goto loc_1784C;
    _ax = 0x0000;                               //mov ax, 0
    goto loc_1783A;                             //jmp short loc_1783A
loc_1784C:                                      //loc_1784C:
    memory16(_ds, 0x73EB) = _dx;                //mov ds:73EBh, dx
    _ax += 1;                                   //inc ax
    _ax += 1;                                   //inc ax
    memory16(_ds, 0x73F5) = _ax;                //mov ds:73F5h, ax
    _ax = memory16(_ds, 0x73F7);                //mov ax, ds:73F7h
loc_17858:                                      //loc_17858:
    _bx = 0x73d7;                               //mov bx, 73D7h
    _bx += _ax;                                 //add bx, ax
    _dx = memory16(_ds, _bx);                   //mov dx, [bx]
    if (_dx != 0x00ff)                          //jnz short loc_1786A
      goto loc_1786A;
    _ax = 0x0000;                               //mov ax, 0
    goto loc_17858;                             //jmp short loc_17858
loc_1786A:                                      //loc_1786A:
    memory16(_ds, 0x73ED) = _dx;                //mov ds:73EDh, dx
    _ax += 1;                                   //inc ax
    _ax += 1;                                   //inc ax
    memory16(_ds, 0x73F7) = _ax;                //mov ds:73F7h, ax
    _ax = memory16(_ds, 0x73F9);                //mov ax, ds:73F9h
loc_17876:                                      //loc_17876:
    _bx = 0x73e1;                               //mov bx, 73E1h
    _bx += _ax;                                 //add bx, ax
    _dx = memory16(_ds, _bx);                   //mov dx, [bx]
    if (_dx != 0x00ff)                          //jnz short loc_17888
      goto loc_17888;
    _ax = 0x0000;                               //mov ax, 0
    goto loc_17876;                             //jmp short loc_17876
loc_17888:                                      //loc_17888:
    memory16(_ds, 0x73EF) = _dx;                //mov ds:73EFh, dx
    _ax += 1;                                   //inc ax
    _ax += 1;                                   //inc ax
    memory16(_ds, 0x73F9) = _ax;                //mov ds:73F9h, ax
}

void sub_17896()
{
    _bx = memory16(_ds, _si + 16);              //mov bx, [si+10h]
    _al = memory(_ds, _bx);                     //mov al, [bx]
    if (_al != 0x00)                            //jnz short loc_178A5
      goto loc_178A5;
    _bx += 1;                                   //inc bx
    _bx = memory16(_ds, _bx);                   //mov bx, [bx]
    memory16(_ds, _si + 16) = _bx;              //mov [si+10h], bx
loc_178A5:                                      //loc_178A5:
    _bx += 1;                                   //inc bx
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _sar(_al, 1);                               //sar al, 1
    _sar(_al, 1);                               //sar al, 1
    _sar(_al, 1);                               //sar al, 1
    _sar(_al, 1);                               //sar al, 1
    if (_al != 0x07)                            //jnz short loc_178B6
      goto loc_178B6;
    _al += 1;                                   //inc al
loc_178B6:                                      //loc_178B6:
    _cbw();                                     //cbw
    memory16(_ds, 0x7492) = _ax;                //mov ds:7492h, ax
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _al &= 0x0f;                                //and al, 0Fh
    if (!(_al & 0x08))                          //jz short loc_178C4
      goto loc_178C4;
    _al |= 0xf0;                                //or al, 0F0h
loc_178C4:                                      //loc_178C4:
    if (_al != 0x07)                            //jnz short loc_178CA
      goto loc_178CA;
    _al += 1;                                   //inc al
loc_178CA:                                      //loc_178CA:
    _cbw();                                     //cbw
    memory16(_ds, 0x7494) = _ax;                //mov ds:7494h, ax
    _bx -= 1;                                   //dec bx
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _cbw();                                     //cbw
    memory16(_ds, _si + 18) += 1;               //inc word ptr [si+12h]
    if (_ax == memory16(_ds, _si + 18))         //jz short loc_178DC
      goto loc_178DC;
    if (_ax >= memory16(_ds, _si + 18))         //jnb short loc_178E6
      goto loc_178E6;
loc_178DC:                                      //loc_178DC:
    memory16(_ds, _si + 18) = 0x0000;           //mov word ptr [si+12h], 0
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    memory16(_ds, _si + 16) = _bx;              //mov [si+10h], bx
loc_178E6:                                      //loc_178E6:
    _ax = memory16(_ds, 0x7492);                //mov ax, ds:7492h
    _dx = memory16(_ds, 0x7494);                //mov dx, ds:7494h
}

void sub_17A31()
{
    memory16(_ds, 0x7629) = 0x0014;             //mov word ptr ds:7629h, 14h
    _di = 0x0c28;                               //mov di, 0C28h
    _si = 0x74ee;                               //mov si, 74EEh
    _cx = 0x0005;                               //mov cx, 5
loc_17A40:                                      //loc_17A40:
    memory16(_ds, _di) = 0x0001;                //mov word ptr [di], 1
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_ds, _di + 2) = _ax;               //mov [di+2], ax
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_ds, _di + 4) = _ax;               //mov [di+4], ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, _di + 14) = _ax;              //mov [di+0Eh], ax
    memory16(_ds, _di + 12) = _ax;              //mov [di+0Ch], ax
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_ds, _di + 22) = _ax;              //mov [di+16h], ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, _di + 24) = _ax;              //mov [di+18h], ax
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_cx);                                 //push cx
    _si = _di;                                  //mov si, di
    sub_1718E();                                //call sub_1718E
    _cx = _pop();                               //pop cx
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, _di + 24) = _ax;              //mov [di+18h], ax
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_ds, _di + 16) = _ax;              //mov [di+10h], ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, _di + 18) = _ax;              //mov [di+12h], ax
    memory16(_ds, _di + 20) = _ax;              //mov [di+14h], ax
    _di += 0x0034;                              //add di, 34h
    if (--_cx)                                  //loop loc_17A40
      goto loc_17A40;
    memory16(_ds, 0xD2C) = _ax;                 //mov ds:0D2Ch, ax
    memory16(_ds, 0x762B) = _ax;                //mov ds:762Bh, ax
    memory16(_ds, 0x762F) = 0x0001;             //mov word ptr ds:762Fh, 1
}

void sub_17A8B()
{
    if (memory16(_ds, 0x762D) != 0x0001)        //jnz short locret_17A9C
      goto locret_17A9C;
    if (memory16(_ds, 0x762F) == 0x0001)        //jz short loc_17A9D
      goto loc_17A9D;
locret_17A9C:                                   //locret_17A9C:
    return;                                     //retn
loc_17A9D:                                      //loc_17A9D:
    _si = 0x0c28;                               //mov si, 0C28h
    sub_17896();                                //call sub_17896
    _cx = 0x0005;                               //mov cx, 5
loc_17AA6:                                      //loc_17AA6:
    _push(_cx);                                 //push cx
    memory16(_ds, _si + 2) += _ax;              //add [si+2], ax
    memory16(_ds, _si + 4) += _dx;              //add [si+4], dx
    _push(_ax);                                 //push ax
    _push(_dx);                                 //push dx
    sub_1718E();                                //call sub_1718E
    _dx = _pop();                               //pop dx
    _ax = _pop();                               //pop ax
    _si += 0x0034;                              //add si, 34h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_17AA6
      goto loc_17AA6;
    _dh = memory(_ds, 0xC2A);                   //mov dh, ds:0C2Ah
    _bx = memory16(_ds, 0xC2C);                 //mov bx, ds:0C2Ch
    _dl = 0x1c;                                 //mov dl, 1Ch
    _ah = 0x40;                                 //mov ah, 40h
    sub_16407();                                //call sub_16407
    if (!_flags.carry)                          //jnb short loc_17AD1
      goto loc_17AD1;
    sub_168A8();                                //call sub_168A8
    goto loc_17AEB;                             //jmp short loc_17AEB
    _STOP_("db 90h");                           //db 90h
loc_17AD1:                                      //loc_17AD1:
    _dh = memory(_ds, 0xC2A);                   //mov dh, ds:0C2Ah
    _dh += 0xec;                                //add dh, 0ECh
    _bx = memory16(_ds, 0xC2C);                 //mov bx, ds:0C2Ch
    _bx += 0x0018;                              //add bx, 18h
    _dl = 0x14;                                 //mov dl, 14h
    _ah = 0x20;                                 //mov ah, 20h
    sub_16407();                                //call sub_16407
    if (!_flags.carry)                          //jnb short loc_17AEB
      goto loc_17AEB;
    sub_168A8();                                //call sub_168A8
loc_17AEB:                                      //loc_17AEB:
    _dh = memory(_ds, 0xC2A);                   //mov dh, ds:0C2Ah
    _bx = memory16(_ds, 0xC2C);                 //mov bx, ds:0C2Ch
    _dl = 0x1c;                                 //mov dl, 1Ch
    _ah = 0x40;                                 //mov ah, 40h
    sub_164A0();                                //call sub_164A0
    if (!_flags.carry)                          //jnb short loc_17B0D
      goto loc_17B0D;
    memory16(_ds, 0xB00) = 0x0000;              //mov word ptr ds:0B00h, 0
    sub_17D53();                                //call sub_17D53
    if (!_flags.carry)                          //jnb short loc_17B0A
      goto loc_17B0A;
    goto loc_17BA5;                             //jmp loc_17BA5
loc_17B0A:                                      //loc_17B0A:
    goto loc_17B2F;                             //jmp short loc_17B2F
    _STOP_("db 90h");                           //db 90h
loc_17B0D:                                      //loc_17B0D:
    _dh = memory(_ds, 0xC2A);                   //mov dh, ds:0C2Ah
    _dh += 0xec;                                //add dh, 0ECh
    _bx = memory16(_ds, 0xC2C);                 //mov bx, ds:0C2Ch
    _bx += 0x0018;                              //add bx, 18h
    _dl = 0x14;                                 //mov dl, 14h
    _ah = 0x20;                                 //mov ah, 20h
    sub_164A0();                                //call sub_164A0
    if (!_flags.carry)                          //jnb short loc_17B2F
      goto loc_17B2F;
    memory16(_ds, 0xB00) = 0x0000;              //mov word ptr ds:0B00h, 0
    sub_17D53();                                //call sub_17D53
    if (_flags.carry)                           //jb short loc_17BA5
      goto loc_17BA5;
loc_17B2F:                                      //loc_17B2F:
    _dh = memory(_ds, 0xC2A);                   //mov dh, ds:0C2Ah
    _bx = memory16(_ds, 0xC2C);                 //mov bx, ds:0C2Ch
    _dl = 0x1c;                                 //mov dl, 1Ch
    _ah = 0x40;                                 //mov ah, 40h
    _dh -= 0x10;                                //sub dh, 10h
    _bx -= 0x000e;                              //sub bx, 0Eh
    _dl += 0x20;                                //add dl, 20h
    _ah += 0x1d;                                //add ah, 1Dh
    if (memory16(_ds, 0xB38) != 0x0002)         //jnz short loc_17B96
      goto loc_17B96;
    if ((short)memory16(_ds, 0xB4A) > (short)0x0004)//jg short loc_17B96
      goto loc_17B96;
    if ((short)memory16(_ds, 0xB4A) <= (short)0x0001)//jle short loc_17B96
      goto loc_17B96;
    sub_164E1();                                //call sub_164E1
    if (!_flags.carry)                          //jnb short loc_17B6E
      goto loc_17B6E;
    sub_17D53();                                //call sub_17D53
    if (_flags.carry)                           //jb short loc_17BA5
      goto loc_17BA5;
    sub_17D53();                                //call sub_17D53
    if (_flags.carry)                           //jb short loc_17BA5
      goto loc_17BA5;
    goto loc_17B96;                             //jmp short loc_17B96
loc_17B6E:                                      //loc_17B6E:
    _dh = memory(_ds, 0xC2A);                   //mov dh, ds:0C2Ah
    _dh += 0xec;                                //add dh, 0ECh
    _bx = memory16(_ds, 0xC2C);                 //mov bx, ds:0C2Ch
    _bx += 0x0018;                              //add bx, 18h
    _dl = 0x14;                                 //mov dl, 14h
    _ah = 0x20;                                 //mov ah, 20h
    _dh -= 0x10;                                //sub dh, 10h
    _bx -= 0x000e;                              //sub bx, 0Eh
    _dl += 0x20;                                //add dl, 20h
    _ah += 0x1d;                                //add ah, 1Dh
    sub_164E1();                                //call sub_164E1
    if (!_flags.carry)                          //jnb short loc_17B96
      goto loc_17B96;
    sub_17D53();                                //call sub_17D53
    if (_flags.carry)                           //jb short loc_17BA5
      goto loc_17BA5;
loc_17B96:                                      //loc_17B96:
    if (memory16(_ds, 0xD2C) == 0x0001)         //jz short loc_17BA1
      goto loc_17BA1;
    sub_17C64();                                //call sub_17C64
    return;                                     //retn
loc_17BA1:                                      //loc_17BA1:
    sub_17CF4();                                //call sub_17CF4
    return;                                     //retn
loc_17BA5:                                      //loc_17BA5:
    memory16(_ds, 0x762D) = 0x0000;             //mov word ptr ds:762Dh, 0
    memory16(_ds, 0x762F) = 0x0000;             //mov word ptr ds:762Fh, 0
    memory(_ds, 0x5B3E) = 0x01;                 //mov byte ptr ds:5B3Eh, 1
    _cx = 0x0005;                               //mov cx, 5
    _si = 0x758b;                               //mov si, 758Bh
    _di = 0x0c28;                               //mov di, 0C28h
loc_17BBF:                                      //loc_17BBF:
    memory16(_ds, _di) = 0x0011;                //mov word ptr [di], 11h
    memory16(_ds, _di + 50) = 0x0060;           //mov word ptr [di+32h], 60h
    memory16(_ds, _di + 28) = 0x0000;           //mov word ptr [di+1Ch], 0
    memory16(_ds, _di + 24) = 0x0000;           //mov word ptr [di+18h], 0
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_ds, _di + 22) = _ax;              //mov [di+16h], ax
    memory16(_ds, _di + 18) = 0x0000;           //mov word ptr [di+12h], 0
    memory16(_ds, _di + 20) = 0x0000;           //mov word ptr [di+14h], 0
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_ds, _di + 16) = _ax;              //mov [di+10h], ax
    _di += 0x0034;                              //add di, 34h
    if (--_cx)                                  //loop loc_17BBF
      goto loc_17BBF;
    _di = 0x0b56;                               //mov di, 0B56h
    memory16(_ds, _di) = 0x0001;                //mov word ptr [di], 1
    _ax = memory16(_ds, 0xC2A);                 //mov ax, ds:0C2Ah
    memory16(_ds, _di + 2) = _ax;               //mov [di+2], ax
    _ax = memory16(_ds, 0xC2C);                 //mov ax, ds:0C2Ch
    memory16(_ds, _di + 4) = _ax;               //mov [di+4], ax
    memory16(_ds, _di + 50) = 0x0034;           //mov word ptr [di+32h], 34h
    memory16(_ds, _di + 22) = 0x0001;           //mov word ptr [di+16h], 1
    memory16(_ds, _di + 24) = 0x0000;           //mov word ptr [di+18h], 0
    memory16(_ds, _di + 6) = 0x0000;            //mov word ptr [di+6], 0
    memory16(_ds, _di + 8) = 0xfb00;            //mov word ptr [di+8], 0FB00h
    memory16(_ds, _di + 16) = 0xfffe;           //mov word ptr [di+10h], 0FFFEh
    memory16(_ds, _di + 28) = 0x0000;           //mov word ptr [di+1Ch], 0
    memory16(_ds, 0xD2C) = 0x0000;              //mov word ptr ds:0D2Ch, 0
    if (memory16(_ds, 0x8BEE) != 0x0001)        //jnz short locret_17C63
      goto locret_17C63;
    _cx = memory16(_ds, 0x6610);                //mov cx, ds:6610h
    _cx |= _cx;                                 //or cx, cx
    if (_cx == 0)                               //jz short loc_17C3E
      goto loc_17C3E;
loc_17C34:                                      //loc_17C34:
    _si = 0x6729;                               //mov si, 6729h
    _push(_cx);                                 //push cx
    sub_16BC7();                                //call sub_16BC7
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_17C34
      goto loc_17C34;
loc_17C3E:                                      //loc_17C3E:
    _cx = memory16(_ds, 0x6612);                //mov cx, ds:6612h
    _cx |= _cx;                                 //or cx, cx
    if (_cx == 0)                               //jz short loc_17C50
      goto loc_17C50;
loc_17C46:                                      //loc_17C46:
    _si = 0x672f;                               //mov si, 672Fh
    _push(_cx);                                 //push cx
    sub_16BC7();                                //call sub_16BC7
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_17C46
      goto loc_17C46;
loc_17C50:                                      //loc_17C50:
    _cx = memory16(_ds, 0x6614);                //mov cx, ds:6614h
    _cx += 1;                                   //inc cx
    _cx |= _cx;                                 //or cx, cx
    if (_cx == 0)                               //jz short locret_17C63
      goto locret_17C63;
loc_17C59:                                      //loc_17C59:
    _si = 0x6735;                               //mov si, 6735h
    _push(_cx);                                 //push cx
    sub_16BC7();                                //call sub_16BC7
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_17C59
      goto loc_17C59;
locret_17C63:                                   //locret_17C63:
    return;
}

void sub_17C64()
{
    if (!(memory16(_ds, 0x762B) & 0xffff))      //jz short loc_17C71
      goto loc_17C71;
    memory16(_ds, 0x762B) -= 1;                 //dec word ptr ds:762Bh
    return;                                     //retn
loc_17C71:                                      //loc_17C71:
    _ax = 0x000d;                               //mov ax, 0Dh
    sub_1AECD();                                //call sub_1AECD
    memory16(_ds, 0x762B) = 0x0032;             //mov word ptr ds:762Bh, 32h
    memory16(_ds, 0xD2C) = 0x0001;              //mov word ptr ds:0D2Ch, 1
    memory16(_ds, 0xD36) = 0x0055;              //mov word ptr ds:0D36h, 55h
    _ax = memory16(_ds, 0xB1E);                 //mov ax, ds:0B1Eh
    _ax += 0x000c;                              //add ax, 0Ch
    _bx = memory16(_ds, 0xB20);                 //mov bx, ds:0B20h
    _bx += 0x000a;                              //add bx, 0Ah
    _cx = memory16(_ds, 0xC2A);                 //mov cx, ds:0C2Ah
    _cx += 0xffe4;                              //add cx, 0FFE4h
    memory16(_ds, 0xD2E) = _cx;                 //mov ds:0D2Eh, cx
    _dx = memory16(_ds, 0xC2C);                 //mov dx, ds:0C2Ch
    _dx += 0x002c;                              //add dx, 2Ch
    memory16(_ds, 0xD30) = _dx;                 //mov ds:0D30h, dx
    _ax -= _cx;                                 //sub ax, cx
    _cx = _ax;                                  //mov cx, ax
    _bx -= _dx;                                 //sub bx, dx
    _dx = _bx;                                  //mov dx, bx
loc_17CB4:                                      //loc_17CB4:
    if ((short)_ax > (short)0x0004)             //jg short loc_17CCB
      goto loc_17CCB;
    if ((short)_ax < (short)0xfffc)             //jl short loc_17CCB
      goto loc_17CCB;
    if ((short)_bx > (short)0x0004)             //jg short loc_17CCB
      goto loc_17CCB;
    if ((short)_bx < (short)0xfffc)             //jl short loc_17CCB
      goto loc_17CCB;
    goto loc_17CEC;                             //jmp short loc_17CEC
    _STOP_("db 90h");                           //db 90h
loc_17CCB:                                      //loc_17CCB:
    _sar(_ax, 1);                               //sar ax, 1
    _sar(_bx, 1);                               //sar bx, 1
    if (_ax != 0x0000)                          //jnz short loc_17CB4
      goto loc_17CB4;
    if (_bx != 0x0000)                          //jnz short loc_17CB4
      goto loc_17CB4;
    _ax = 0x0004;                               //mov ax, 4
    _bx = _ax;                                  //mov bx, ax
    if ((short)_cx >= (short)0x0000)            //jge short loc_17CE5
      goto loc_17CE5;
    _ax = -_ax;                                 //neg ax
loc_17CE5:                                      //loc_17CE5:
    if ((short)_dx >= (short)0x0000)            //jge short loc_17CE5
      goto loc_17CE5;
    _bx = -_bx;                                 //neg bx
loc_17CEC:                                      //loc_17CEC:
    memory16(_ds, 0xD3C) = _ax;                 //mov ds:0D3Ch, ax
    memory16(_ds, 0xD34) = _bx;                 //mov ds:0D34h, bx
}

void sub_17CF4()
{
    memory16(_ds, 0x762B) -= 1;                 //dec word ptr ds:762Bh
    if ((short)memory16(_ds, 0x762B) >= 0)      //jns short loc_17D00
      goto loc_17D00;
    memory16(_ds, 0x762B) = 0x0000;             //mov word ptr ds:762Bh, 0
loc_17D00:                                      //loc_17D00:
    _ax = memory16(_ds, 0xD2E);                 //mov ax, ds:0D2Eh
    _ax = _ax + memory16(_ds, 0xD3C);           //add ax, ds:0D3Ch
    memory16(_ds, 0xD2E) = _ax;                 //mov ds:0D2Eh, ax
    _dx = memory16(_ds, 0xD30);                 //mov dx, ds:0D30h
    _dx = _dx + memory16(_ds, 0xD34);           //add dx, ds:0D34h
    memory16(_ds, 0xD30) = _dx;                 //mov ds:0D30h, dx
    _ax += 0x0004;                              //add ax, 4
    if ((short)_ax <= (short)0x0004)            //jle short loc_17D4C
      goto loc_17D4C;
    if ((short)_ax >= (short)0x00fc)            //jge short loc_17D4C
      goto loc_17D4C;
    _dx += 0x0004;                              //add dx, 4
    memory16(_ds, 0x795D) = _ax;                //mov ds:795Dh, ax
    memory16(_ds, 0x795F) = _dx;                //mov ds:795Fh, dx
    sub_18014();                                //call sub_18014
    _ch = memory(_ds, 0x7963);                  //mov ch, ds:7963h
    if (_ch & 0x02)                             //jnz short loc_17D4C
      goto loc_17D4C;
    _ax -= 1;                                   //dec ax
    _ax -= 1;                                   //dec ax
    _bx = _dx;                                  //mov bx, dx
    _dh = _al;                                  //mov dh, al
    _dl = 0x04;                                 //mov dl, 4
    _ah = 0x04;                                 //mov ah, 4
    sub_16407();                                //call sub_16407
    if (!_flags.carry)                          //jnb short locret_17D52
      goto locret_17D52;
    sub_168A8();                                //call sub_168A8
loc_17D4C:                                      //loc_17D4C:
    memory16(_ds, 0xD2C) = 0x0000;              //mov word ptr ds:0D2Ch, 0
locret_17D52:                                   //locret_17D52:
    return;
}

void sub_17D53()
{
    memory16(_ds, 0x7629) -= 1;                 //dec word ptr ds:7629h
    if (memory16(_ds, 0x7629) == 0)             //jz short loc_17D5B
      goto loc_17D5B;
    _flags.carry = false;                       //clc
    return;                                     //retn
loc_17D5B:                                      //loc_17D5B:
    _flags.carry = true;                        //stc
}

void sub_17D70()
{
    _push(_si);                                 //push si
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    memory16(_ds, 0x796C) = 0x0005;             //mov word ptr ds:796Ch, 5
    memory16(_ds, 0x796E) = 0x0010;             //mov word ptr ds:796Eh, 10h
    memory16(_ds, 0x7964) = 0x7fff;             //mov word ptr ds:7964h, 7FFFh
    memory16(_ds, 0x7E02) = 0x0000;             //mov word ptr ds:7E02h, 0
    _cx = 0x0003;                               //mov cx, 3
    _dx = memory16(_ds, 0x795F);                //mov dx, ds:795Fh
    _dx &= 0x0007;                              //and dx, 7
    if ((short)_dx >= (short)0x0004)            //jge short loc_17D9F
      goto loc_17D9F;
    _cx = 0x0002;                               //mov cx, 2
loc_17D9F:                                      //loc_17D9F:
    memory(_ds, 0x796A) = 0x00;                 //mov byte ptr ds:796Ah, 0
    _bp = 0x0004;                               //mov bp, 4
    sub_17FF3();                                //call sub_17FF3
    _dx &= 0x0007;                              //and dx, 7
    if (_dx == 0)                               //jz short loc_17DD7
      goto loc_17DD7;
    _ax = _ax ^ _ax;                            //xor ax, ax
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bl = memory(_ds, _di + 21492);             //mov bl, [di+53F4h]
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bl = _bl | memory(_ds, _di + 21492);       //or bl, [di+53F4h]
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bl = _bl | memory(_ds, _di + 21492);       //or bl, [di+53F4h]
    _si += 0x001d;                              //add si, 1Dh
    _bl &= 0x02;                                //and bl, 2
    if (_bl == 0)                               //jz short loc_17E2F
      _STOP_("goto loc_17E2F");
    memory16(_ds, 0x7E02) = 0x0001;             //mov word ptr ds:7E02h, 1
    _STOP_("goto loc_17E2F");                   //jmp short loc_17E2F
    _STOP_("db 90h");                           //db 90h
loc_17DD7:                                      //loc_17DD7:
    _ax = _ax ^ _ax;                            //xor ax, ax
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bl = memory(_ds, _di + 21492);             //mov bl, [di+53F4h]
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bl = _bl | memory(_ds, _di + 21492);       //or bl, [di+53F4h]
    _si += 0x001e;                              //add si, 1Eh
    _bl &= 0x02;                                //and bl, 2
    if (_bl != 0)                               //jnz short loc_17DF2
      goto loc_17DF2;
    _STOP_("goto loc_17E8A");                   //jmp loc_17E8A
loc_17DF2:                                      //loc_17DF2:
    memory16(_ds, 0x7E02) = 0x0001;             //mov word ptr ds:7E02h, 1
    _STOP_("goto loc_17E8A");                   //jmp loc_17E8A
}

void sub_17DFB()
{
    _push(_si);                                 //push si
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    memory16(_ds, 0x796C) = 0x0000;             //mov word ptr ds:796Ch, 0
    memory16(_ds, 0x796E) = 0x0015;             //mov word ptr ds:796Eh, 15h
    memory16(_ds, 0x7964) = 0x7fff;             //mov word ptr ds:7964h, 7FFFh
    _cx = 0x0004;                               //mov cx, 4
    _dx = memory16(_ds, 0x795F);                //mov dx, ds:795Fh
    _dx &= 0x0007;                              //and dx, 7
    if ((short)_dx >= (short)0x0004)            //jge short loc_17E24
      goto loc_17E24;
    _cx = 0x0003;                               //mov cx, 3
loc_17E24:                                      //loc_17E24:
    _bp = 0x0004;                               //mov bp, 4
    sub_17FF3();                                //call sub_17FF3
    _dx &= 0x0007;                              //and dx, 7
    if (_dx == 0)                               //jz short loc_17E8A
      goto loc_17E8A;
loc_17E2F:                                      //loc_17E2F:
    _bx = _bx ^ _bx;                            //xor bx, bx
    _ax = _ax ^ _ax;                            //xor ax, ax
    goto loc_17E4E;                             //jmp short loc_17E4E
loc_17E36:                                      //loc_17E36:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bl = _bl | memory(_ds, _di + 21492);       //or bl, [di+53F4h]
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bh = _bh | memory(_ds, _di + 21492);       //or bh, [di+53F4h]
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bl = _bl | memory(_ds, _di + 21492);       //or bl, [di+53F4h]
    _si += 0x001d;                              //add si, 1Dh
loc_17E4E:                                      //loc_17E4E:
    if (--_cx)                                  //loop loc_17E36
      goto loc_17E36;
    _bl &= 0x22;                                //and bl, 22h
    _bh &= 0x2a;                                //and bh, 2Ah
    memory(_ds, 0x796A) = _bl;                  //mov ds:796Ah, bl
    memory(_ds, 0x796A) |= _bh;                 //or ds:796Ah, bh
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bl = memory(_ds, _di + 21492);             //mov bl, [di+53F4h]
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bh = memory(_ds, _di + 21492);             //mov bh, [di+53F4h]
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bl = _bl | memory(_ds, _di + 21492);       //or bl, [di+53F4h]
    _bl &= 0x27;                                //and bl, 27h
    _bh &= 0x7f;                                //and bh, 7Fh
    memory(_ds, 0x796A) |= _bl;                 //or ds:796Ah, bl
    memory(_ds, 0x796A) |= _bh;                 //or ds:796Ah, bh
    _al = memory(_ds, 0x796A);                  //mov al, ds:796Ah
    memory(_ds, 0x7963) = _al;                  //mov ds:7963h, al
    goto loc_17EC9;                             //jmp short loc_17EC9
loc_17E8A:                                      //loc_17E8A:
    _bx = _bx ^ _bx;                            //xor bx, bx
    _ax = _ax ^ _ax;                            //xor ax, ax
    goto loc_17EA2;                             //jmp short loc_17EA2
    _STOP_("db 90h");                           //db 90h
loc_17E91:                                      //loc_17E91:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bl = _bl | memory(_ds, _di + 21492);       //or bl, [di+53F4h]
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bl = _bl | memory(_ds, _di + 21492);       //or bl, [di+53F4h]
    _si += 0x001e;                              //add si, 1Eh
loc_17EA2:                                      //loc_17EA2:
    if (--_cx)                                  //loop loc_17E91
      goto loc_17E91;
    _bl &= 0x2a;                                //and bl, 2Ah
    memory(_ds, 0x796A) = _bl;                  //mov ds:796Ah, bl
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bl = memory(_ds, _di + 21492);             //mov bl, [di+53F4h]
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bl = _bl | memory(_ds, _di + 21492);       //or bl, [di+53F4h]
    _bl &= 0x7f;                                //and bl, 7Fh
    memory(_ds, 0x796A) |= _bl;                 //or ds:796Ah, bl
    _al = memory(_ds, 0x796A);                  //mov al, ds:796Ah
    memory(_ds, 0x7963) = _al;                  //mov ds:7963h, al
    goto loc_17EC9;                             //jmp short loc_17EC9
    _STOP_("db 90h");                           //db 90h
loc_17EC9:                                      //loc_17EC9:
    _ax = memory16(_ds, 0x7961);                //mov ax, ds:7961h
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (!_flags.sign)                           //jns short loc_17ED8
      goto loc_17ED8;
    _al = memory(_ds, 0x7963);                  //mov al, ds:7963h
    _al &= 0xfb;                                //and al, 0FBh
    memory(_ds, 0x7963) = _al;                  //mov ds:7963h, al
loc_17ED8:                                      //loc_17ED8:
    if (memory(_ds, 0x796B) == 0x01)            //jz short loc_17EE2
      goto loc_17EE2;
    goto loc_17FB9;                             //jmp loc_17FB9
loc_17EE2:                                      //loc_17EE2:
    _si = 0x0c28;                               //mov si, 0C28h
loc_17EE5:                                      //loc_17EE5:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    if (_ax != 0xffff)                          //jnz short loc_17EEF
      goto loc_17EEF;
    goto loc_17FB9;                             //jmp loc_17FB9
loc_17EEF:                                      //loc_17EEF:
    _al |= _al;                                 //or al, al
    if (_al != 0)                               //jnz short loc_17EF6
      goto loc_17EF6;
    goto loc_17FB3;                             //jmp loc_17FB3
loc_17EF6:                                      //loc_17EF6:
    if (_al & 0x80)                             //jnz short loc_17EFD
      goto loc_17EFD;
    goto loc_17FB3;                             //jmp loc_17FB3
loc_17EFD:                                      //loc_17EFD:
    if (!(_al & 0x40))                          //jz short loc_17F68
      goto loc_17F68;
    _cl = memory(_ds, _si + 2);                 //mov cl, [si+2]
    _di = memory16(_ds, _si + 4);               //mov di, [si+4]
    _dl = memory(_ds, _si + 30);                //mov dl, [si+1Eh]
    _bl = memory(_ds, _si + 32);                //mov bl, [si+20h]
    _ch = memory(_ds, 0x795D);                  //mov ch, ds:795Dh
    _ch += 0x04;                                //add ch, 4
    _bp = memory16(_ds, 0x795F);                //mov bp, ds:795Fh
    _bp = _bp + memory16(_ds, 0x796C);          //add bp, ds:796Ch
    _dh = 0x10;                                 //mov dh, 10h
    _bh = memory(_ds, 0x796E);                  //mov bh, ds:796Eh
    _push(_si);                                 //push si
    sub_17FBF();                                //call sub_17FBF
    _si = _pop();                               //pop si
    if (_flags.carry)                           //jb short loc_17F2F
      goto loc_17F2F;
    goto loc_17FB3;                             //jmp loc_17FB3
loc_17F2F:                                      //loc_17F2F:
    memory(_ds, 0x7963) |= 0x02;                //or byte ptr ds:7963h, 2
    if ((short)_di > (short)memory16(_ds, 0x7964))//jg short loc_17F65
      goto loc_17F65;
    _bx = memory16(_ds, 0x795F);                //mov bx, ds:795Fh
    _bx += 0x0014;                              //add bx, 14h
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_ds, 0x7962);                  //mov al, ds:7962h
    _cbw();                                     //cbw
    _ax += 0x0008;                              //add ax, 8
    _ax += _di;                                 //add ax, di
    if ((short)_bx > (short)_ax)                //jg short loc_17F65
      goto loc_17F65;
    memory16(_ds, 0x7964) = _di;                //mov ds:7964h, di
    memory16(_ds, 0x7966) = 0x0000;             //mov word ptr ds:7966h, 0
    memory16(_ds, 0x7968) = 0x0000;             //mov word ptr ds:7968h, 0
    memory(_ds, 0x7963) |= 0x40;                //or byte ptr ds:7963h, 40h
loc_17F65:                                      //loc_17F65:
    goto loc_17FB3;                             //jmp short loc_17FB3
loc_17F68:                                      //loc_17F68:
    _ax = memory16(_ds, 0x7961);                //mov ax, ds:7961h
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (_flags.sign)                            //js short loc_17FB3
      goto loc_17FB3;
    _cl = memory(_ds, _si + 2);                 //mov cl, [si+2]
    _di = memory16(_ds, _si + 4);               //mov di, [si+4]
    _dl = memory(_ds, _si + 30);                //mov dl, [si+1Eh]
    _bl = memory(_ds, 0x7962);                  //mov bl, ds:7962h
    _bl += 0x08;                                //add bl, 8
    _ch = memory(_ds, 0x795D);                  //mov ch, ds:795Dh
    _ch += 0x04;                                //add ch, 4
    _bp = memory16(_ds, 0x795F);                //mov bp, ds:795Fh
    _bp += 0x0014;                              //add bp, 14h
    _dh = 0x10;                                 //mov dh, 10h
    _bh = 0x01;                                 //mov bh, 1
    _push(_si);                                 //push si
    sub_17FBF();                                //call sub_17FBF
    _si = _pop();                               //pop si
    if (!_flags.carry)                          //jnb short loc_17FB3
      goto loc_17FB3;
    if ((short)_di > (short)memory16(_ds, 0x7964))//jg short loc_17FB3
      goto loc_17FB3;
    memory(_ds, 0x7963) |= 0x40;                //or byte ptr ds:7963h, 40h
    memory16(_ds, 0x7964) = _di;                //mov ds:7964h, di
    _ax = memory16(_ds, _si + 46);              //mov ax, [si+2Eh]
    memory16(_ds, 0x7966) = _ax;                //mov ds:7966h, ax
    _ax = memory16(_ds, _si + 48);              //mov ax, [si+30h]
    memory16(_ds, 0x7968) = _ax;                //mov ds:7968h, ax
loc_17FB3:                                      //loc_17FB3:
    _si += 0x0034;                              //add si, 34h
    goto loc_17EE5;                             //jmp loc_17EE5
loc_17FB9:                                      //loc_17FB9:
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    _si = _pop();                               //pop si
}

void sub_17FBF()
{
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = _ch;                                  //mov al, ch
    _si = _ax;                                  //mov si, ax
    _al = _dh;                                  //mov al, dh
    _si += _ax;                                 //add si, ax
    _al = _cl;                                  //mov al, cl
    if ((short)_si <= (short)_ax)               //jle short loc_17FF1
      goto loc_17FF1;
    _si = _ax;                                  //mov si, ax
    _al = _dl;                                  //mov al, dl
    _si += _ax;                                 //add si, ax
    _al = _ch;                                  //mov al, ch
    if ((short)_si <= (short)_ax)               //jle short loc_17FF1
      goto loc_17FF1;
    _cx = _cx ^ _cx;                            //xor cx, cx
    _cl = _bh;                                  //mov cl, bh
    _cx += _bp;                                 //add cx, bp
    if ((short)_cx <= (short)_di)               //jle short loc_17FF1
      goto loc_17FF1;
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = _bl;                                  //mov al, bl
    _ax += _di;                                 //add ax, di
    if ((short)_ax <= (short)_bp)               //jle short loc_17FF1
      goto loc_17FF1;
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_17FF1:                                      //loc_17FF1:
    _flags.carry = false;                       //clc
}

void sub_17FF3()
{
    _si = 0x563c;                               //mov si, 563Ch
    _dx = memory16(_ds, 0x795F);                //mov dx, ds:795Fh
    _dx &= 0xfff8;                              //and dx, 0FFF8h
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _si += _dx;                                 //add si, dx
    _dx = memory16(_ds, 0x795D);                //mov dx, ds:795Dh
    _dx += _bp;                                 //add dx, bp
    _bp = _dx;                                  //mov bp, dx
    _bp >>= 1;                                  //shr bp, 1
    _bp >>= 1;                                  //shr bp, 1
    _bp >>= 1;                                  //shr bp, 1
    _si += _bp;                                 //add si, bp
}

void sub_18014()
{
    _push(_ax);                                 //push ax
    _push(_dx);                                 //push dx
    _bp = _bp ^ _bp;                            //xor bp, bp
    sub_17FF3();                                //call sub_17FF3
    _ax = _ax ^ _ax;                            //xor ax, ax
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _al = memory(_ds, _di + 21492);             //mov al, [di+53F4h]
    memory(_ds, 0x7963) = _al;                  //mov ds:7963h, al
    sub_181C6();                                //call sub_181C6
    _dx = _pop();                               //pop dx
    _ax = _pop();                               //pop ax
}

void sub_1802D()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _cx = 0x0002;                               //mov cx, 2
    _ax = memory16(_ds, 0x795F);                //mov ax, ds:795Fh
    _ax &= 0x0007;                              //and ax, 7
    if (_ax == 0)                               //jz short loc_1803F
      goto loc_1803F;
    _cx = 0x0003;                               //mov cx, 3
loc_1803F:                                      //loc_1803F:
    _bp = 0x0008;                               //mov bp, 8
    sub_17FF3();                                //call sub_17FF3
    _dx &= 0x0007;                              //and dx, 7
    if (_dx == 0)                               //jz short loc_18083
      goto loc_18083;
    _bx = _bx ^ _bx;                            //xor bx, bx
    _ax = _ax ^ _ax;                            //xor ax, ax
    goto loc_18062;                             //jmp short loc_18062
    _STOP_("db 90h");                           //db 90h
loc_18051:                                      //loc_18051:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bl = _bl | memory(_ds, _di + 21492);       //or bl, [di+53F4h]
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bl = _bl | memory(_ds, _di + 21492);       //or bl, [di+53F4h]
    _si += 0x001e;                              //add si, 1Eh
loc_18062:                                      //loc_18062:
    if (--_cx)                                  //loop loc_18051
      goto loc_18051;
    _bl &= 0x23;                                //and bl, 23h
    _bh = _bl;                                  //mov bh, bl
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bl = memory(_ds, _di + 21492);             //mov bl, [di+53F4h]
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bl = _bl | memory(_ds, _di + 21492);       //or bl, [di+53F4h]
    _bl &= 0x27;                                //and bl, 27h
    _bh |= _bl;                                 //or bh, bl
    memory(_ds, 0x7963) = _bh;                  //mov ds:7963h, bh
    goto loc_180AE;                             //jmp short loc_180AE
    _STOP_("db 90h");                           //db 90h
loc_18083:                                      //loc_18083:
    _bx = _bx ^ _bx;                            //xor bx, bx
    _ax = _ax ^ _ax;                            //xor ax, ax
    goto loc_18094;                             //jmp short loc_18094
loc_1808A:                                      //loc_1808A:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bl = _bl | memory(_ds, _di + 21492);       //or bl, [di+53F4h]
    _si += 0x001f;                              //add si, 1Fh
loc_18094:                                      //loc_18094:
    if (--_cx)                                  //loop loc_1808A
      goto loc_1808A;
    _bl &= 0x2b;                                //and bl, 2Bh
    _bh = _bl;                                  //mov bh, bl
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _di = _ax;                                  //mov di, ax
    _bl = memory(_ds, _di + 21492);             //mov bl, [di+53F4h]
    _bl &= 0x27;                                //and bl, 27h
    _bh |= _bl;                                 //or bh, bl
    memory(_ds, 0x7963) = _bh;                  //mov ds:7963h, bh
    goto loc_180AE;                             //jmp short loc_180AE
loc_180AE:                                      //loc_180AE:
    _ax = memory16(_ds, 0x7961);                //mov ax, ds:7961h
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (!_flags.sign)                           //jns short loc_180C0
      goto loc_180C0;
    _bh = memory(_ds, 0x7963);                  //mov bh, ds:7963h
    _bh &= 0xfb;                                //and bh, 0FBh
    memory(_ds, 0x7963) = _bh;                  //mov ds:7963h, bh
loc_180C0:                                      //loc_180C0:
    if (memory(_ds, 0x796B) == 0x01)            //jz short loc_180CA
      goto loc_180CA;
    goto loc_1819F;                             //jmp loc_1819F
loc_180CA:                                      //loc_180CA:
    _si = 0x0c28;                               //mov si, 0C28h
loc_180CD:                                      //loc_180CD:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    if (_ax != 0xffff)                          //jnz short loc_180D7
      goto loc_180D7;
    goto loc_1819F;                             //jmp loc_1819F
loc_180D7:                                      //loc_180D7:
    _al |= _al;                                 //or al, al
    if (_al != 0)                               //jnz short loc_180DE
      goto loc_180DE;
    goto loc_18199;                             //jmp loc_18199
loc_180DE:                                      //loc_180DE:
    if (_al & 0x80)                             //jnz short loc_180E5
      goto loc_180E5;
    goto loc_18199;                             //jmp loc_18199
loc_180E5:                                      //loc_180E5:
    if (!(_al & 0x40))                          //jz short loc_1814E
      goto loc_1814E;
    _cl = memory(_ds, _si + 2);                 //mov cl, [si+2]
    _di = memory16(_ds, _si + 4);               //mov di, [si+4]
    _dl = memory(_ds, _si + 30);                //mov dl, [si+1Eh]
    _bl = memory(_ds, _si + 32);                //mov bl, [si+20h]
    _ch = memory(_ds, 0x795D);                  //mov ch, ds:795Dh
    _ch += 0x08;                                //add ch, 8
    _bp = memory16(_ds, 0x795F);                //mov bp, ds:795Fh
    _bp = _bp + memory16(_ds, 0x796C);          //add bp, ds:796Ch
    _dh = 0x08;                                 //mov dh, 8
    _bh = 0x10;                                 //mov bh, 10h
    _push(_si);                                 //push si
    sub_17FBF();                                //call sub_17FBF
    _si = _pop();                               //pop si
    if (_flags.carry)                           //jb short loc_18115
      goto loc_18115;
    goto loc_18199;                             //jmp loc_18199
loc_18115:                                      //loc_18115:
    memory(_ds, 0x7963) |= 0x02;                //or byte ptr ds:7963h, 2
    if ((short)_di > (short)memory16(_ds, 0x7964))//jg short loc_1814B
      goto loc_1814B;
    _bx = memory16(_ds, 0x795F);                //mov bx, ds:795Fh
    _bx += 0x0010;                              //add bx, 10h
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_ds, 0x7962);                  //mov al, ds:7962h
    _cbw();                                     //cbw
    _ax += 0x0008;                              //add ax, 8
    _ax += _di;                                 //add ax, di
    if ((short)_bx > (short)_ax)                //jg short loc_1814B
      goto loc_1814B;
    memory16(_ds, 0x7964) = _di;                //mov ds:7964h, di
    memory16(_ds, 0x7966) = 0x0000;             //mov word ptr ds:7966h, 0
    memory16(_ds, 0x7968) = 0x0000;             //mov word ptr ds:7968h, 0
    memory(_ds, 0x7963) |= 0x40;                //or byte ptr ds:7963h, 40h
loc_1814B:                                      //loc_1814B:
    goto loc_18199;                             //jmp short loc_18199
loc_1814E:                                      //loc_1814E:
    _ax = memory16(_ds, 0x7961);                //mov ax, ds:7961h
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (_flags.sign)                            //js short loc_18199
      goto loc_18199;
    _cl = memory(_ds, _si + 2);                 //mov cl, [si+2]
    _di = memory16(_ds, _si + 4);               //mov di, [si+4]
    _dl = memory(_ds, _si + 30);                //mov dl, [si+1Eh]
    _bl = memory(_ds, 0x7962);                  //mov bl, ds:7962h
    _bl += 0x08;                                //add bl, 8
    _ch = memory(_ds, 0x795D);                  //mov ch, ds:795Dh
    _ch += 0x08;                                //add ch, 8
    _bp = memory16(_ds, 0x795F);                //mov bp, ds:795Fh
    _bp += 0x000f;                              //add bp, 0Fh
    _dh = 0x08;                                 //mov dh, 8
    _bh = 0x01;                                 //mov bh, 1
    _push(_si);                                 //push si
    sub_17FBF();                                //call sub_17FBF
    _si = _pop();                               //pop si
    if (!_flags.carry)                          //jnb short loc_18199
      goto loc_18199;
    if ((short)_di > (short)memory16(_ds, 0x7964))//jg short loc_18199
      goto loc_18199;
    memory(_ds, 0x7963) |= 0x40;                //or byte ptr ds:7963h, 40h
    memory16(_ds, 0x7964) = _di;                //mov ds:7964h, di
    _ax = memory16(_ds, _si + 46);              //mov ax, [si+2Eh]
    memory16(_ds, 0x7966) = _ax;                //mov ds:7966h, ax
    _ax = memory16(_ds, _si + 48);              //mov ax, [si+30h]
    memory16(_ds, 0x7968) = _ax;                //mov ds:7968h, ax
loc_18199:                                      //loc_18199:
    _si += 0x0034;                              //add si, 34h
    goto loc_180CD;                             //jmp loc_180CD
loc_1819F:                                      //loc_1819F:
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_181A4()
{
    _al = _ch;                                  //mov al, ch
    _ah = _ah ^ _ah;                            //xor ah, ah
    _ch = _ch ^ _ch;                            //xor ch, ch
    if ((short)_ax < (short)_cx)                //jl short loc_181C4
      goto loc_181C4;
    _dh = _dh ^ _dh;                            //xor dh, dh
    _cx += _dx;                                 //add cx, dx
    if ((short)_ax > (short)_cx)                //jg short loc_181C4
      goto loc_181C4;
    if ((short)_bp < (short)_di)                //jl short loc_181C4
      goto loc_181C4;
    _bh = _bh ^ _bh;                            //xor bh, bh
    _di += _bx;                                 //add di, bx
    if ((short)_bp > (short)_di)                //jg short loc_181C4
      goto loc_181C4;
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_181C4:                                      //loc_181C4:
    _flags.carry = false;                       //clc
}

void sub_181C6()
{
    _si = 0x0c28;                               //mov si, 0C28h
loc_181C9:                                      //loc_181C9:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    if (_ax == 0xffff)                          //jz short locret_181FD
      goto locret_181FD;
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz short loc_181F8
      goto loc_181F8;
    if (!(_al & 0x80))                          //jz short loc_181F8
      goto loc_181F8;
    if (!(_al & 0x40))                          //jz short loc_181F8
      goto loc_181F8;
    _ch = memory(_ds, 0x795D);                  //mov ch, ds:795Dh
    _bp = memory16(_ds, 0x795F);                //mov bp, ds:795Fh
    _cl = memory(_ds, _si + 2);                 //mov cl, [si+2]
    _di = memory16(_ds, _si + 4);               //mov di, [si+4]
    _dl = 0x18;                                 //mov dl, 18h
    _bl = 0x15;                                 //mov bl, 15h
    sub_181A4();                                //call sub_181A4
    if (!_flags.carry)                          //jnb short loc_181F8
      goto loc_181F8;
    memory(_ds, 0x7963) |= 0x40;                //or byte ptr ds:7963h, 40h
loc_181F8:                                      //loc_181F8:
    _si += 0x0034;                              //add si, 34h
    goto loc_181C9;                             //jmp short loc_181C9
locret_181FD:                                   //locret_181FD:
    return;
}

void sub_18351()
{
    WORD _cs = _seg001;

    if (memory16(_ds, 0x7E16) != 0x0001)        //jnz short loc_1835B
      goto loc_1835B;
{loc_18F9A(); return; };                        //
loc_1835B:                                      //loc_1835B:
    sub_19C05();                                //call sub_19C05
    _ax = memory16(_ds, 0xB20);                 //mov ax, ds:0B20h
    memory16(_ds, 0x7DFE) = _ax;                //mov ds:7DFEh, ax
    memory(_ds, 0x90C2) = 0x00;                 //mov byte ptr ds:90C2h, 0
    memory16(_ds, 0x7E1A) = 0x0000;             //mov word ptr ds:7E1Ah, 0
    sub_1C4CA();                                //call sub_1C4CA
    if (!(memory16(_ds, 0x7ED2) & 0x00ff))      //jz short loc_1837F
      goto loc_1837F;
    memory16(_ds, 0x7ED2) -= 1;                 //dec word ptr ds:7ED2h
loc_1837F:                                      //loc_1837F:
    if (_al == memory(_ds, 0x7ECA))             //jz short loc_18396
      goto loc_18396;
    memory(_ds, 0x7ECA) = 0x00;                 //mov byte ptr ds:7ECAh, 0
    memory16(_ds, 0x7ECC) = 0x0000;             //mov word ptr ds:7ECCh, 0
    memory16(_ds, 0x7ED2) = 0x0000;             //mov word ptr ds:7ED2h, 0
loc_18396:                                      //loc_18396:
    if (memory16(_ds, 0x7E00) != 0x0001)        //jnz short loc_183A0
      goto loc_183A0;
{loc_18B03(); return; };                        //
loc_183A0:                                      //loc_183A0:
    _ax = memory16(_ds, 0x7E06);                //mov ax, ds:7E06h
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_183AA
      goto loc_183AA;
    goto loc_18987;                             //jmp loc_18987
loc_183AA:                                      //loc_183AA:
    memory16(_ds, 0x7E08) = 0x0000;             //mov word ptr ds:7E08h, 0
    memory16(_ds, 0x7E0A) = 0x0000;             //mov word ptr ds:7E0Ah, 0
    memory16(_ds, 0x7E0C) = 0x0000;             //mov word ptr ds:7E0Ch, 0
    memory16(_ds, 0x7E0E) = 0x0000;             //mov word ptr ds:7E0Eh, 0
    memory16(_ds, 0x7E10) = 0x0000;             //mov word ptr ds:7E10h, 0
    memory16(_ds, 0x7E14) = 0x0000;             //mov word ptr ds:7E14h, 0
    memory(_ds, 0x796B) = 0x01;                 //mov byte ptr ds:796Bh, 1
    _dx = memory16(_ds, 0xB24);                 //mov dx, ds:0B24h
    _dx += 0x0080;                              //add dx, 80h
    if ((short)_dx <= (short)0x0800)            //jle short loc_183E4
      goto loc_183E4;
    _dx = 0x0800;                               //mov dx, 800h
loc_183E4:                                      //loc_183E4:
    memory16(_ds, 0xB24) = _dx;                 //mov ds:0B24h, dx
    memory16(_ds, 0x7961) = _dx;                //mov ds:7961h, dx
    _flags.sign = !!(_dx & 0x8000);             //or dx, dx
    _dx |= _dx;
    if (_flags.sign)                            //js short loc_183F5
      goto loc_183F5;
    _ch = _ch ^ _ch;                            //xor ch, ch
    goto loc_183F7;                             //jmp short loc_183F7
    _STOP_("db 90h");                           //db 90h
loc_183F5:                                      //loc_183F5:
    _ch = 0xff;                                 //mov ch, 0FFh
loc_183F7:                                      //loc_183F7:
    _ax = memory16(_ds, 0xB20);                 //mov ax, ds:0B20h
    _cl = memory(_ds, 0xB22);                   //mov cl, ds:0B22h
    _flags.carry = (_cl + _dl) >= 0x100;        //add cl, dl
    _cl += _dl;
    _flags.carry2 = (_al + _dh + _flags.carry) >= 0x100;
    _al = _al + _dh + _flags.carry;_flags.carry = flags.carry2;
    _ah = _ah + _ch + _flags.carry;             //adc ah, ch
    memory16(_ds, 0x795F) = _ax;                //mov ds:795Fh, ax
    _dx = memory16(_ds, 0xB1E);                 //mov dx, ds:0B1Eh
    memory16(_ds, 0x795D) = _dx;                //mov ds:795Dh, dx
    memory(_ds, 0x796B) = 0x01;                 //mov byte ptr ds:796Bh, 1
    if (memory16(_ds, 0x7E04) != 0x0001)        //jnz short loc_18421
      goto loc_18421;
    sub_17D70();                                //call sub_17D70
    goto loc_18424;                             //jmp short loc_18424
    _STOP_("db 90h");                           //db 90h
loc_18421:                                      //loc_18421:
    sub_17DFB();                                //call sub_17DFB
loc_18424:                                      //loc_18424:
    _ch = memory(_ds, 0x7963);                  //mov ch, ds:7963h
    if (!(_ch & 0x40))                          //jz short loc_18485
      goto loc_18485;
    _ax = memory16(_ds, 0x7964);                //mov ax, ds:7964h
    _cl = _cl ^ _cl;                            //xor cl, cl
    _ax -= 0x0015;                              //sub ax, 15h
    memory16(_ds, 0x795F) = _ax;                //mov ds:795Fh, ax
    memory16(_ds, 0xB20) = _ax;                 //mov ds:0B20h, ax
    memory(_ds, 0xB22) = 0x00;                  //mov byte ptr ds:0B22h, 0
    memory16(_ds, 0x7E08) = 0x0001;             //mov word ptr ds:7E08h, 1
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, 0x7966);                //mov ax, ds:7966h
    memory16(_ds, 0x7E1A) = _ax;                //mov ds:7E1Ah, ax
    _ax = _pop();                               //pop ax
    memory(_ds, 0x796B) = 0x00;                 //mov byte ptr ds:796Bh, 0
    if (memory16(_ds, 0x7E04) != 0x0001)        //jnz short loc_18460
      goto loc_18460;
    sub_17D70();                                //call sub_17D70
    goto loc_18463;                             //jmp short loc_18463
loc_18460:                                      //loc_18460:
    sub_17DFB();                                //call sub_17DFB
loc_18463:                                      //loc_18463:
    _ch = memory(_ds, 0x7963);                  //mov ch, ds:7963h
    if (!(_ch & 0x20))                          //jz short loc_1846F
      goto loc_1846F;
{sub_168A8(); return; };                        //
loc_1846F:                                      //loc_1846F:
    _ch &= 0x06;                                //and ch, 6
    if (_ch == 0)                               //jz short loc_1847B
      goto loc_1847B;
    _ch = memory(_ds, 0x7963);                  //mov ch, ds:7963h
    goto loc_184A3;                             //jmp short loc_184A3
    _STOP_("db 90h");                           //db 90h
loc_1847B:                                      //loc_1847B:
    _ch = memory(_ds, 0x7963);                  //mov ch, ds:7963h
    _dx = 0x0100;                               //mov dx, 100h
    goto loc_1857C;                             //jmp loc_1857C
loc_18485:                                      //loc_18485:
    if (!(_ch & 0x20))                          //jz short loc_1848D
      goto loc_1848D;
{sub_168A8(); return; };                        //
loc_1848D:                                      //loc_1848D:
    if (_ch & 0x04)                             //jnz short loc_184DA
      goto loc_184DA;
    if (_ch & 0x02)                             //jnz short loc_1849A
      goto loc_1849A;
    goto loc_186A8;                             //jmp loc_186A8
loc_1849A:                                      //loc_1849A:
    _bp = memory16(_cs, 0xB24);                 //mov bp, cs:word_10F24
    _flags.sign = !!(_bp & 0x8000);             //or bp, bp
    _bp |= _bp;
    if (!_flags.sign)                           //jns short loc_184DA
      goto loc_184DA;
loc_184A3:                                      //loc_184A3:
    if (memory16(_ds, 0x7E06) != 0x0001)        //jnz short loc_184C8
      goto loc_184C8;
    _bp = memory16(_cs, 0xB1E);                 //mov bp, cs:word_10F1E
    _bp &= 0x001f;                              //and bp, 1Fh
    if ((short)_bp >= (short)0x000a)            //jge short loc_184C8
      goto loc_184C8;
    _bp = memory16(_cs, 0xB1E);                 //mov bp, cs:word_10F1E
    _bp &= 0x00f0;                              //and bp, 0F0h
    _bp |= 0x0004;                              //or bp, 4
    memory16(_cs, 0xB1E) = _bp;                 //mov cs:word_10F1E, bp
loc_184C8:                                      //loc_184C8:
    _ax |= 0x0007;                              //or ax, 7
    _ax += 1;                                   //inc ax
    _cl = _cl ^ _cl;                            //xor cl, cl
    memory16(_ds, 0xB24) = 0x0100;              //mov word ptr ds:0B24h, 100h
    _dx = 0x0100;                               //mov dx, 100h
    goto loc_186A8;                             //jmp loc_186A8
loc_184DA:                                      //loc_184DA:
    if (!(_ch & 0x10))                          //jz short loc_18524
      goto loc_18524;
    if (memory(_ds, 0xB884) & 0x10)             //jnz short loc_18524
      goto loc_18524;
    if (memory16(_ds, 0x7E04) == 0x0001)        //jz short loc_18524
      goto loc_18524;
    if (memory16(_ds, 0x7E06) != 0x0001)        //jnz short loc_184F8
      goto loc_184F8;
    goto loc_186A8;                             //jmp loc_186A8
loc_184F8:                                      //loc_184F8:
    if (!(memory(_ds, 0xB884) & 0x04))          //jz short loc_18524
      goto loc_18524;
    _bx = memory16(_ds, 0xB1E);                 //mov bx, ds:0B1Eh
    _bx &= 0x001f;                              //and bx, 1Fh
    if ((short)_bx >= (short)0x000a)            //jge short loc_18524
      goto loc_18524;
    _bx = memory16(_ds, 0xB1E);                 //mov bx, ds:0B1Eh
    _bx &= 0x00f0;                              //and bx, 0F0h
    _bx |= 0x0004;                              //or bx, 4
    memory16(_ds, 0xB1E) = _bx;                 //mov ds:0B1Eh, bx
    memory16(_ds, 0x7E06) = 0x0001;             //mov word ptr ds:7E06h, 1
    goto loc_186A8;                             //jmp loc_186A8
loc_18524:                                      //loc_18524:
    memory16(_ds, 0x7E06) = 0x0000;             //mov word ptr ds:7E06h, 0
    memory16(_ds, 0x7E08) = 0x0001;             //mov word ptr ds:7E08h, 1
    _ax += 0x000c;                              //add ax, 0Ch
    _ax |= 0x0007;                              //or ax, 7
    _ax -= 0x0014;                              //sub ax, 14h
    _cl = _cl ^ _cl;                            //xor cl, cl
    memory16(_ds, 0xB20) = _ax;                 //mov ds:0B20h, ax
    memory(_ds, 0xB22) = _cl;                   //mov ds:0B22h, cl
    _dx = 0x0100;                               //mov dx, 100h
    if (!(_ch & 0x01))                          //jz short loc_1857C
      goto loc_1857C;
    if (memory16(_ds, 0x8BEC) != 0x0003)        //jnz short loc_1857C
      goto loc_1857C;
    _dx = memory16(_ds, 0xB24);                 //mov dx, ds:0B24h
    if ((short)_dx < (short)0x0200)             //jl short loc_18570
      goto loc_18570;
    _dx = -_dx;                                 //neg dx
    _dx += 0x0060;                              //add dx, 60h
    memory16(_ds, 0xB24) = _dx;                 //mov ds:0B24h, dx
    _dx = 0xf781;                               //mov dx, 0F781h
    _ax = 0x0016;                               //mov ax, 16h
    sub_1AECD();                                //call sub_1AECD
    goto loc_185AB;                             //jmp short loc_185AB
loc_18570:                                      //loc_18570:
    memory16(_ds, 0xB24) = 0x0100;              //mov word ptr ds:0B24h, 100h
    _dx = 0xfa00;                               //mov dx, 0FA00h
    goto loc_185AB;                             //jmp short loc_185AB
loc_1857C:                                      //loc_1857C:
    memory16(_ds, 0xB24) = _dx;                 //mov ds:0B24h, dx
    _dx = 0xfa00;                               //mov dx, 0FA00h
    if (!(_ch & 0x01))                          //jz short loc_185AB
      goto loc_185AB;
    if (memory16(_ds, 0x8BEC) != 0x0001)        //jnz short loc_18595
      goto loc_18595;
    _dx = 0xfe00;                               //mov dx, 0FE00h
    goto loc_185AB;                             //jmp short loc_185AB
    _STOP_("db 90h");                           //db 90h
loc_18595:                                      //loc_18595:
    if (memory16(_ds, 0x8BEC) != 0x0005)        //jnz short loc_185AB
      goto loc_185AB;
    _ax = 0x0017;                               //mov ax, 17h
    sub_1AECD();                                //call sub_1AECD
    memory16(_ds, 0xB24) = 0xf781;              //mov word ptr ds:0B24h, 0F781h
    goto loc_186C1;                             //jmp loc_186C1
loc_185AB:                                      //loc_185AB:
    if (memory16(_ds, 0x7E04) != 0x0001)        //jnz short loc_185C5
      goto loc_185C5;
    if (memory16(_ds, 0x7E02) != 0x0001)        //jnz short loc_185BC
      goto loc_185BC;
    goto loc_186C1;                             //jmp loc_186C1
loc_185BC:                                      //loc_185BC:
    memory16(_ds, 0x7E04) = 0x0000;             //mov word ptr ds:7E04h, 0
    goto loc_185F2;                             //jmp short loc_185F2
    _STOP_("db 90h");                           //db 90h
loc_185C5:                                      //loc_185C5:
    if (memory(_ds, 0xB884) & 0x10)             //jnz short loc_18606
      goto loc_18606;
    if (!(memory(_ds, 0xB884) & 0x08))          //jz short loc_185F2
      goto loc_185F2;
    memory16(_ds, 0xB24) = _dx;                 //mov ds:0B24h, dx
    if (!(_ch & 0x10))                          //jz short loc_185E1
      goto loc_185E1;
    goto loc_186C1;                             //jmp loc_186C1
loc_185E1:                                      //loc_185E1:
    if (_ch & 0x08)                             //jnz short loc_185E9
      goto loc_185E9;
    goto loc_186C1;                             //jmp loc_186C1
loc_185E9:                                      //loc_185E9:
    memory16(_ds, 0x7E06) = 0x0001;             //mov word ptr ds:7E06h, 1
    goto loc_186C1;                             //jmp loc_186C1
loc_185F2:                                      //loc_185F2:
    if (memory(_ds, 0xB884) & 0x04)             //jnz short loc_185FD
      goto loc_185FD;
    goto loc_186C1;                             //jmp loc_186C1
loc_185FD:                                      //loc_185FD:
    memory16(_ds, 0x7E04) = 0x0001;             //mov word ptr ds:7E04h, 1
    goto loc_186C1;                             //jmp loc_186C1
loc_18606:                                      //loc_18606:
    if (!(memory(_ds, 0xB884) & 0x08))          //jz short loc_18611
      goto loc_18611;
    goto loc_189C2;                             //jmp loc_189C2
loc_18611:                                      //loc_18611:
    memory16(_ds, 0x7E12) = 0x0001;             //mov word ptr ds:7E12h, 1
    if (!(memory(_ds, 0xB884) & 0x04))          //jz short loc_18622
      goto loc_18622;
    goto loc_189FF;                             //jmp loc_189FF
loc_18622:                                      //loc_18622:
    _push(_ax);                                 //push ax
    _al = memory(_ds, 0xB884);                  //mov al, ds:0B884h
    if (_al != memory(_ds, 0x7ECA))             //jnz short loc_18630
      goto loc_18630;
    _ax = _pop();                               //pop ax
    goto loc_189DE;                             //jmp loc_189DE
loc_18630:                                      //loc_18630:
    _ax = _pop();                               //pop ax
    if (!(memory(_ds, 0xB884) & 0x02))          //jz short loc_1866A
      goto loc_1866A;
    memory16(_ds, 0xB36) = 0x0001;              //mov word ptr ds:0B36h, 1
    _bx = memory16(_ds, 0xB1E);                 //mov bx, ds:0B1Eh
    memory16(_ds, 0x7ECE) = _bx;                //mov ds:7ECEh, bx
    memory16(_ds, 0x7ED0) = _ax;                //mov ds:7ED0h, ax
    memory16(_ds, 0x7ED0) += 0x0008;            //add word ptr ds:7ED0h, 8
    memory16(_ds, 0x7ECC) = 0x0001;             //mov word ptr ds:7ECCh, 1
    memory16(_ds, 0x7ED2) = 0x000a;             //mov word ptr ds:7ED2h, 0Ah
    _al = memory(_ds, 0xB884);                  //mov al, ds:0B884h
    memory(_ds, 0x7ECA) = _al;                  //mov ds:7ECAh, al
    _ax = 0x0022;                               //mov ax, 22h
    sub_1AECD();                                //call sub_1AECD
    goto loc_189DE;                             //jmp loc_189DE
loc_1866A:                                      //loc_1866A:
    if (!(memory(_ds, 0xB884) & 0x01))          //jz short loc_186C1
      goto loc_186C1;
    memory16(_ds, 0xB36) = 0x0000;              //mov word ptr ds:0B36h, 0
    _bx = memory16(_ds, 0xB1E);                 //mov bx, ds:0B1Eh
    memory16(_ds, 0x7ECE) = _bx;                //mov ds:7ECEh, bx
    memory16(_ds, 0x7ECE) += 0x0018;            //add word ptr ds:7ECEh, 18h
    memory16(_ds, 0x7ED0) = _ax;                //mov ds:7ED0h, ax
    memory16(_ds, 0x7ED0) += 0x0008;            //add word ptr ds:7ED0h, 8
    memory16(_ds, 0x7ECC) = 0x0001;             //mov word ptr ds:7ECCh, 1
    memory16(_ds, 0x7ED2) = 0x000a;             //mov word ptr ds:7ED2h, 0Ah
    _al = memory(_ds, 0xB884);                  //mov al, ds:0B884h
    memory(_ds, 0x7ECA) = _al;                  //mov ds:7ECAh, al
    _ax = 0x0022;                               //mov ax, 22h
    sub_1AECD();                                //call sub_1AECD
    goto loc_189DE;                             //jmp loc_189DE
loc_186A8:                                      //loc_186A8:
    memory16(_ds, 0xB20) = _ax;                 //mov ds:0B20h, ax
    memory(_ds, 0xB22) = _cl;                   //mov ds:0B22h, cl
    _al = memory(_ds, 0xB884);                  //mov al, ds:0B884h
    _al &= 0x0c;                                //and al, 0Ch
    if (_al == 0)                               //jz short loc_186C1
      goto loc_186C1;
    if (!(_ch & 0x08))                          //jz short loc_186C1
      goto loc_186C1;
    memory16(_ds, 0x7E06) = 0x0001;             //mov word ptr ds:7E06h, 1
loc_186C1:                                      //loc_186C1:
    if (memory16(_ds, 0x7E06) != 0x0001)        //jnz short loc_186E2
      goto loc_186E2;
    if (_ch & 0x08)                             //jnz short loc_186E2
      goto loc_186E2;
    memory16(_ds, 0x7E06) = 0x0000;             //mov word ptr ds:7E06h, 0
    _bp = memory16(_cs, 0xB24);                 //mov bp, cs:word_10F24
    _flags.sign = !!(_bp & 0x8000);             //or bp, bp
    _bp |= _bp;
    if (!_flags.sign)                           //jns short loc_186E2
      goto loc_186E2;
    memory16(_ds, 0xB24) = 0xfe00;              //mov word ptr ds:0B24h, 0FE00h
loc_186E2:                                      //loc_186E2:
    if (!(memory(_ds, 0xB884) & 0x02))          //jz short loc_1871E
      goto loc_1871E;
    memory16(_ds, 0xB36) = 0x0001;              //mov word ptr ds:0B36h, 1
    _dx = 0xfffe;                               //mov dx, 0FFFEh
    if (_ch & 0x01)                             //jnz short loc_186FB
      goto loc_186FB;
    goto loc_1878A;                             //jmp loc_1878A
loc_186FB:                                      //loc_186FB:
    if (memory16(_ds, 0x8BEC) != 0x0004)        //jnz short loc_1870E
      goto loc_1870E;
    _dx = 0xffff;                               //mov dx, 0FFFFh
    memory16(_ds, 0x7E0C) = 0x0001;             //mov word ptr ds:7E0Ch, 1
    goto loc_1878A;                             //jmp short loc_1878A
loc_1870E:                                      //loc_1870E:
    if (memory16(_ds, 0x8BEC) != 0x0002)        //jnz short loc_1878A
      goto loc_1878A;
    memory16(_ds, 0x7E0E) = 0x0001;             //mov word ptr ds:7E0Eh, 1
    goto loc_1878A;                             //jmp short loc_1878A
loc_1871E:                                      //loc_1871E:
    if (!(memory(_ds, 0xB884) & 0x01))          //jz short loc_18757
      goto loc_18757;
    memory16(_ds, 0xB36) = 0x0000;              //mov word ptr ds:0B36h, 0
    _dx = 0x0002;                               //mov dx, 2
    if (!(_ch & 0x01))                          //jz short loc_1878A
      goto loc_1878A;
    if (memory16(_ds, 0x8BEC) != 0x0004)        //jnz short loc_18747
      goto loc_18747;
    _dx = 0x0001;                               //mov dx, 1
    memory16(_ds, 0x7E0C) = 0x0001;             //mov word ptr ds:7E0Ch, 1
    goto loc_1878A;                             //jmp short loc_1878A
    _STOP_("db 90h");                           //db 90h
loc_18747:                                      //loc_18747:
    if (memory16(_ds, 0x8BEC) != 0x0002)        //jnz short loc_1878A
      goto loc_1878A;
    memory16(_ds, 0x7E0E) = 0x0001;             //mov word ptr ds:7E0Eh, 1
    goto loc_1878A;                             //jmp short loc_1878A
    _STOP_("db 90h");                           //db 90h
loc_18757:                                      //loc_18757:
    _dx = _dx ^ _dx;                            //xor dx, dx
    if (_ch & 0x01)                             //jnz short loc_18767
      goto loc_18767;
    memory16(_ds, 0xB34) = 0xffff;              //mov word ptr ds:0B34h, 0FFFFh
    goto loc_1878A;                             //jmp short loc_1878A
    _STOP_("db 90h");                           //db 90h
loc_18767:                                      //loc_18767:
    if (memory16(_ds, 0x8BEC) == 0x0002)        //jz short loc_18777
      goto loc_18777;
    memory16(_ds, 0xB34) = 0xffff;              //mov word ptr ds:0B34h, 0FFFFh
    goto loc_1878A;                             //jmp short loc_1878A
    _STOP_("db 90h");                           //db 90h
loc_18777:                                      //loc_18777:
    memory16(_ds, 0x7E0A) = 0x0001;             //mov word ptr ds:7E0Ah, 1
    _dx = 0x0002;                               //mov dx, 2
    if (memory16(_ds, 0xB36) == 0x0000)         //jz short loc_1878A
      goto loc_1878A;
    _dx = 0xfffe;                               //mov dx, 0FFFEh
loc_1878A:                                      //loc_1878A:
    _dx = _dx + memory16(_ds, 0x7E1A);          //add dx, ds:7E1Ah
    _bx = memory16(_ds, 0xB1E);                 //mov bx, ds:0B1Eh
    _bx += _dx;                                 //add bx, dx
    _flags.sign = !!(_dx & 0x8000);             //or dx, dx
    _dx |= _dx;
    if (_dx == 0)                               //jz short loc_187B9
      goto loc_187B9;
    if (!_flags.sign)                           //jns short loc_187AA
      goto loc_187AA;
    if ((short)_bx >= (short)0x0000)            //jge short loc_187B9
      goto loc_187B9;
    _bx = _bx ^ _bx;                            //xor bx, bx
    memory(_ds, 0x90C2) = 0x01;                 //mov byte ptr ds:90C2h, 1
    goto loc_187B9;                             //jmp short loc_187B9
loc_187AA:                                      //loc_187AA:
    if ((short)_bx < (short)0x00e8)             //jl short loc_187B9
      goto loc_187B9;
    _bx = 0x00e8;                               //mov bx, 0E8h
    memory(_ds, 0x90C2) = 0x02;                 //mov byte ptr ds:90C2h, 2
loc_187B9:                                      //loc_187B9:
    _ax = memory16(_ds, 0xB20);                 //mov ax, ds:0B20h
    memory16(_ds, 0x795F) = _ax;                //mov ds:795Fh, ax
    memory16(_ds, 0x7961) = 0xffff;             //mov word ptr ds:7961h, 0FFFFh
    memory16(_ds, 0x795D) = _bx;                //mov ds:795Dh, bx
    memory(_ds, 0x796B) = 0x01;                 //mov byte ptr ds:796Bh, 1
    if (memory16(_ds, 0x7E04) != 0x0001)        //jnz short loc_187DB
      goto loc_187DB;
    sub_17D70();                                //call sub_17D70
    goto loc_187DE;                             //jmp short loc_187DE
    _STOP_("db 90h");                           //db 90h
loc_187DB:                                      //loc_187DB:
    sub_17DFB();                                //call sub_17DFB
loc_187DE:                                      //loc_187DE:
    _ch = memory(_ds, 0x7963);                  //mov ch, ds:7963h
    if (!(_ch & 0x20))                          //jz short loc_187EA
      goto loc_187EA;
{sub_168A8(); return; };                        //
loc_187EA:                                      //loc_187EA:
    if (!(_ch & 0x02))                          //jz short loc_18815
      goto loc_18815;
    _flags.sign = !!(_dx & 0x8000);             //or dx, dx
    _dx |= _dx;
    if (!_flags.sign)                           //jns short loc_18804
      goto loc_18804;
    _bx += 0x000c;                              //add bx, 0Ch
    _bx &= 0x00f8;                              //and bx, 0F8h
    _bx -= 0x0004;                              //sub bx, 4
    memory16(_ds, 0xB1E) = _bx;                 //mov ds:0B1Eh, bx
    goto loc_1882B;                             //jmp short loc_1882B
loc_18804:                                      //loc_18804:
    _bx += 0x0003;                              //add bx, 3
    _bx &= 0x00f8;                              //and bx, 0F8h
    _bx -= 0x0004;                              //sub bx, 4
    memory16(_ds, 0xB1E) = _bx;                 //mov ds:0B1Eh, bx
    goto loc_1882B;                             //jmp short loc_1882B
    _STOP_("db 90h");                           //db 90h
loc_18815:                                      //loc_18815:
    memory16(_ds, 0xB1E) = _bx;                 //mov ds:0B1Eh, bx
    if (memory16(_ds, 0x7E06) != 0x0001)        //jnz short loc_1882B
      goto loc_1882B;
    if (_ch & 0x08)                             //jnz short loc_1882B
      goto loc_1882B;
    memory16(_ds, 0x7E06) = 0x0000;             //mov word ptr ds:7E06h, 0
loc_1882B:                                      //loc_1882B:
    if (memory16(_ds, 0x7E00) != 0x0001)        //jnz short loc_1883E
      goto loc_1883E;
    memory16(_ds, 0xB26) = 0x000c;              //mov word ptr ds:0B26h, 0Ch
    sub_18C83();                                //call sub_18C83
    goto loc_18975;                             //jmp loc_18975
loc_1883E:                                      //loc_1883E:
    if (memory16(_ds, 0x7E06) != 0x0001)        //jnz short loc_18865
      goto loc_18865;
    memory16(_ds, 0xB26) = 0x001a;              //mov word ptr ds:0B26h, 1Ah
    _bx = memory16(_ds, 0xB1E);                 //mov bx, ds:0B1Eh
    _ax = memory16(_ds, 0xB20);                 //mov ax, ds:0B20h
    _ax = _ax ^ _bx;                            //xor ax, bx
    _ax &= 0x0004;                              //and ax, 4
    if (_ax != 0)                               //jnz short loc_1885C
      goto loc_1885C;
    goto loc_18A8F;                             //jmp loc_18A8F
loc_1885C:                                      //loc_1885C:
    memory16(_ds, 0xB26) = 0x001b;              //mov word ptr ds:0B26h, 1Bh
    goto loc_18A8F;                             //jmp loc_18A8F
loc_18865:                                      //loc_18865:
    if (memory16(_ds, 0x7E08) == 0x0001)        //jz short loc_18875
      goto loc_18875;
    memory16(_ds, 0xB26) = 0x0008;              //mov word ptr ds:0B26h, 8
    goto loc_18975;                             //jmp loc_18975
loc_18875:                                      //loc_18875:
    if (!(memory16(_ds, 0x7ED2) & 0x00ff))      //jz short loc_18886
      goto loc_18886;
    memory16(_ds, 0xB26) = 0x000a;              //mov word ptr ds:0B26h, 0Ah
    goto loc_18975;                             //jmp loc_18975
loc_18886:                                      //loc_18886:
    if (memory16(_ds, 0x7E10) != 0x0001)        //jnz short loc_18896
      goto loc_18896;
    memory16(_ds, 0xB26) = 0x0009;              //mov word ptr ds:0B26h, 9
    goto loc_18975;                             //jmp loc_18975
loc_18896:                                      //loc_18896:
    if (memory16(_ds, 0x7E14) != 0x0001)        //jnz short loc_188B6
      goto loc_188B6;
    memory16(_ds, 0xB26) = 0x0000;              //mov word ptr ds:0B26h, 0
    if (memory16(_ds, 0xB52) != 0x0000)         //jnz short loc_188AD
      goto loc_188AD;
    goto loc_18975;                             //jmp loc_18975
loc_188AD:                                      //loc_188AD:
    memory16(_ds, 0xB26) = 0x000b;              //mov word ptr ds:0B26h, 0Bh
    goto loc_18975;                             //jmp loc_18975
loc_188B6:                                      //loc_188B6:
    if (memory16(_ds, 0x7E0A) != 0x0001)        //jnz short loc_188D6
      goto loc_188D6;
    memory16(_ds, 0xB26) = 0x0006;              //mov word ptr ds:0B26h, 6
    if (memory16(_ds, 0x7E04) != 0x0001)        //jnz short loc_188CD
      goto loc_188CD;
    goto loc_18975;                             //jmp loc_18975
loc_188CD:                                      //loc_188CD:
    memory16(_ds, 0xB26) = 0x0000;              //mov word ptr ds:0B26h, 0
    goto loc_18975;                             //jmp loc_18975
loc_188D6:                                      //loc_188D6:
    if (!(memory(_ds, 0x7ECA) & 0xff))          //jz short loc_188E6
      goto loc_188E6;
    memory16(_ds, 0xB26) = 0x0000;              //mov word ptr ds:0B26h, 0
    goto loc_18975;                             //jmp loc_18975
loc_188E6:                                      //loc_188E6:
    _si = 0x7e2c;                               //mov si, 7E2Ch
    memory16(_ds, 0xB26) = 0x0006;              //mov word ptr ds:0B26h, 6
    if (memory16(_ds, 0x7E04) == 0x0001)        //jz short loc_188FF
      goto loc_188FF;
    _si = 0x7e22;                               //mov si, 7E22h
    memory16(_ds, 0xB26) = 0x0000;              //mov word ptr ds:0B26h, 0
loc_188FF:                                      //loc_188FF:
    if (memory16(_ds, 0xB34) != 0xffff)         //jnz short loc_1890F
      goto loc_1890F;
    memory16(_ds, 0xB34) = 0x0000;              //mov word ptr ds:0B34h, 0
    goto loc_18975;                             //jmp short loc_18975
    _STOP_("db 90h");                           //db 90h
loc_1890F:                                      //loc_1890F:
    _ax = 0x0001;                               //mov ax, 1
    if (memory16(_ds, 0x7E0C) == 0x0001)        //jz short loc_18926
      goto loc_18926;
    _ax = 0x0004;                               //mov ax, 4
    if (memory16(_ds, 0x7E0E) == 0x0001)        //jz short loc_18926
      goto loc_18926;
    _ax = 0x0002;                               //mov ax, 2
loc_18926:                                      //loc_18926:
    _ax = _ax + memory16(_ds, 0xB34);           //add ax, ds:0B34h
    if ((short)_ax < (short)0x0028)             //jl short loc_18932
      goto loc_18932;
    _ax -= 0x0028;                              //sub ax, 28h
loc_18932:                                      //loc_18932:
    memory16(_ds, 0xB34) = _ax;                 //mov ds:0B34h, ax
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    if (memory16(_ds, 0x7E04) != 0x0001)        //jnz short loc_18950
      goto loc_18950;
    if (!(_ax & 0x0001))                        //jz short loc_1896C
      goto loc_1896C;
    _push(_ax);                                 //push ax
    _ax = 0x0026;                               //mov ax, 26h
    sub_1AECD();                                //call sub_1AECD
    _ax = _pop();                               //pop ax
    goto loc_1896C;                             //jmp short loc_1896C
loc_18950:                                      //loc_18950:
    if (_ax == 0x0002)                          //jz short loc_18964
      goto loc_18964;
    if (_ax == 0x0005)                          //jz short loc_18964
      goto loc_18964;
    if (_ax == 0x0007)                          //jz short loc_18964
      goto loc_18964;
    if (_ax != 0x0000)                          //jnz short loc_1896C
      goto loc_1896C;
loc_18964:                                      //loc_18964:
    _push(_ax);                                 //push ax
    _ax = 0x0025;                               //mov ax, 25h
    sub_1AECD();                                //call sub_1AECD
    _ax = _pop();                               //pop ax
loc_1896C:                                      //loc_1896C:
    _si += _ax;                                 //add si, ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_ds, _si);                     //mov al, [si]
    memory16(_ds, 0xB26) = _ax;                 //mov ds:0B26h, ax
loc_18975:                                      //loc_18975:
    if (memory16(_ds, 0xB36) != 0x0000)         //jnz short loc_1897F
      goto loc_1897F;
    goto loc_18A8F;                             //jmp loc_18A8F
loc_1897F:                                      //loc_1897F:
    memory16(_ds, 0xB26) += 0x000d;             //add word ptr ds:0B26h, 0Dh
    goto loc_18A8F;                             //jmp loc_18A8F
loc_18987:                                      //loc_18987:
    _ax = memory16(_ds, 0xB20);                 //mov ax, ds:0B20h
    _cl = _cl ^ _cl;                            //xor cl, cl
    _dx = _dx ^ _dx;                            //xor dx, dx
    if (!(memory(_ds, 0xB884) & 0x08))          //jz short loc_1899C
      goto loc_1899C;
    _dx = 0xfffe;                               //mov dx, 0FFFEh
    goto loc_189A7;                             //jmp short loc_189A7
loc_1899C:                                      //loc_1899C:
    if (!(memory(_ds, 0xB884) & 0x04))          //jz short loc_189A7
      goto loc_189A7;
    _dx = 0x0002;                               //mov dx, 2
loc_189A7:                                      //loc_189A7:
    memory16(_ds, 0xB24) = _dx;                 //mov ds:0B24h, dx
    _ax += _dx;                                 //add ax, dx
    memory16(_ds, 0x7961) = _dx;                //mov ds:7961h, dx
    memory16(_ds, 0x795F) = _ax;                //mov ds:795Fh, ax
    _bx = memory16(_ds, 0xB1E);                 //mov bx, ds:0B1Eh
    memory16(_ds, 0x795D) = _bx;                //mov ds:795Dh, bx
    sub_17DFB();                                //call sub_17DFB
    goto loc_18424;                             //jmp loc_18424
loc_189C2:                                      //loc_189C2:
    memory16(_ds, 0x7E10) = 0x0001;             //mov word ptr ds:7E10h, 1
    if (memory16(_ds, 0x7E12) == 0x0000)        //jz short loc_189DE
      goto loc_189DE;
    if (!(memory16(_ds, 0x6610) & 0x00ff))      //jz short loc_189DE
      goto loc_189DE;
    if (memory16(_ds, 0xB00) != 0x0001)         //jnz short loc_189F9
      goto loc_189F9;
loc_189DE:                                      //loc_189DE:
    if (_ch & 0x01)                             //jnz short loc_189E6
      goto loc_189E6;
    goto loc_1882B;                             //jmp loc_1882B
loc_189E6:                                      //loc_189E6:
    if (memory16(_ds, 0x8BEC) == 0x0002)        //jz short loc_189F0
      goto loc_189F0;
    goto loc_1882B;                             //jmp loc_1882B
loc_189F0:                                      //loc_189F0:
    memory16(_ds, 0x7E0A) = 0x0001;             //mov word ptr ds:7E0Ah, 1
    goto loc_186C1;                             //jmp loc_186C1
loc_189F9:                                      //loc_189F9:
    sub_18A9A();                                //call sub_18A9A
    goto loc_1882B;                             //jmp loc_1882B
loc_189FF:                                      //loc_189FF:
    memory16(_ds, 0x7E14) = 0x0001;             //mov word ptr ds:7E14h, 1
    if ((short)memory16(_ds, 0xB38) >= (short)0x0001)//jge short loc_189DE
      goto loc_189DE;
    _ax = memory16(_ds, 0x6612);                //mov ax, ds:6612h
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_18A16
      goto loc_18A16;
    goto loc_1882B;                             //jmp loc_1882B
loc_18A16:                                      //loc_18A16:
    if (memory(_ds, 0x9804) == 0x01)            //jz short loc_18A21
      goto loc_18A21;
    memory16(_ds, 0x6612) -= 1;                 //dec word ptr ds:6612h
loc_18A21:                                      //loc_18A21:
    memory16(_ds, 0xB38) = 0x0001;              //mov word ptr ds:0B38h, 1
    _ax = memory16(_ds, 0xB1E);                 //mov ax, ds:0B1Eh
    memory16(_ds, 0xB3A) = _ax;                 //mov ds:0B3Ah, ax
    memory(_ds, 0xB3F) = 0x00;                  //mov byte ptr ds:0B3Fh, 0
    _ax = memory16(_ds, 0xB20);                 //mov ax, ds:0B20h
    _ax += 0x0005;                              //add ax, 5
    memory16(_ds, 0xB3C) = _ax;                 //mov ds:0B3Ch, ax
    memory(_ds, 0xB3E) = 0x00;                  //mov byte ptr ds:0B3Eh, 0
    memory16(_ds, 0xB4A) = 0x0000;              //mov word ptr ds:0B4Ah, 0
    memory16(_ds, 0xB50) = 0x0000;              //mov word ptr ds:0B50h, 0
    memory16(_ds, 0xB52) = 0x0000;              //mov word ptr ds:0B52h, 0
    memory16(_ds, 0xB40) = 0x0100;              //mov word ptr ds:0B40h, 100h
    memory16(_ds, 0xB4E) = 0x7e36;              //mov word ptr ds:0B4Eh, 7E36h
    if (!(memory(_ds, 0xB884) & 0x02))          //jz short loc_18A75
      goto loc_18A75;
    memory16(_ds, 0xB36) = 0x0001;              //mov word ptr ds:0B36h, 1
    memory16(_ds, 0xB52) = 0xfe00;              //mov word ptr ds:0B52h, 0FE00h
    goto loc_1882B;                             //jmp loc_1882B
loc_18A75:                                      //loc_18A75:
    if (memory(_ds, 0xB884) & 0x01)             //jnz short loc_18A80
      goto loc_18A80;
    goto loc_1882B;                             //jmp loc_1882B
loc_18A80:                                      //loc_18A80:
    memory16(_ds, 0xB36) = 0x0000;              //mov word ptr ds:0B36h, 0
    memory16(_ds, 0xB52) = 0x0200;              //mov word ptr ds:0B52h, 200h
    goto loc_1882B;                             //jmp loc_1882B
loc_18A8F:                                      //loc_18A8F:
    _ax = memory16(_ds, 0xB20);                 //mov ax, ds:0B20h
    _ax = _ax - memory16(_ds, 0x7DFE);          //sub ax, ds:7DFEh
    memory16(_ds, 0x6C43) = _ax;                //mov ds:6C43h, ax
}

void sub_18A9A()
{
    _ax = memory16(_ds, 0x6610);                //mov ax, ds:6610h
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short locret_18AE9
      goto locret_18AE9;
    if (memory(_ds, 0x9804) == 0x01)            //jz short loc_18AB2
      goto loc_18AB2;
    memory16(_ds, 0x6610) -= 1;                 //dec word ptr ds:6610h
loc_18AB2:                                      //loc_18AB2:
    _ax = 0x000d;                               //mov ax, 0Dh
    sub_1AECD();                                //call sub_1AECD
    memory16(_ds, 0xB00) = 0x0001;              //mov word ptr ds:0B00h, 1
    _ax = memory16(_ds, 0xB20);                 //mov ax, ds:0B20h
    _ax += 0x0007;                              //add ax, 7
    memory16(_ds, 0xB04) = _ax;                 //mov ds:0B04h, ax
    if (memory16(_ds, 0xB36) != 0x0000)         //jnz short loc_18AEA
      goto loc_18AEA;
    memory16(_ds, 0xB1A) = 0x0008;              //mov word ptr ds:0B1Ah, 8
    _ax = memory16(_ds, 0xB1E);                 //mov ax, ds:0B1Eh
    memory16(_ds, 0xB02) = _ax;                 //mov ds:0B02h, ax
    memory16(_ds, 0xB0A) = 0x001f;              //mov word ptr ds:0B0Ah, 1Fh
    memory16(_ds, 0x7E12) = 0x0000;             //mov word ptr ds:7E12h, 0
locret_18AE9:                                   //locret_18AE9:
    return;                                     //retn
loc_18AEA:                                      //loc_18AEA:
    memory16(_ds, 0xB1A) = 0xfff8;              //mov word ptr ds:0B1Ah, 0FFF8h
    _ax = memory16(_ds, 0xB1E);                 //mov ax, ds:0B1Eh
    memory16(_ds, 0xB02) = _ax;                 //mov ds:0B02h, ax
    memory16(_ds, 0xB0A) = 0x001e;              //mov word ptr ds:0B0Ah, 1Eh
    memory16(_ds, 0x7E12) = 0x0000;             //mov word ptr ds:7E12h, 0
}

void loc_18B03()
{
    WORD _cs = _seg001;

    memory16(_ds, 0x7E08) = 0x0000;             //mov word ptr ds:7E08h, 0
    memory16(_ds, 0x7E0A) = 0x0000;             //mov word ptr ds:7E0Ah, 0
    memory16(_ds, 0x7E0C) = 0x0000;             //mov word ptr ds:7E0Ch, 0
    memory16(_ds, 0x7E0E) = 0x0000;             //mov word ptr ds:7E0Eh, 0
    memory16(_ds, 0x7E10) = 0x0000;             //mov word ptr ds:7E10h, 0
    memory16(_ds, 0x7E14) = 0x0000;             //mov word ptr ds:7E14h, 0
    memory16(_ds, 0x7E06) = 0x0000;             //mov word ptr ds:7E06h, 0
    _dx = memory16(_ds, 0xB24);                 //mov dx, ds:0B24h
    _dx += 0x0040;                              //add dx, 40h
    if ((short)_dx <= (short)0x0400)            //jle short loc_18B40
      goto loc_18B40;
    _dx = 0x0400;                               //mov dx, 400h
loc_18B40:                                      //loc_18B40:
    if (!(memory(_ds, 0xB884) & 0x08))          //jz short loc_18B5E
      goto loc_18B5E;
    _dx += 0xff40;                              //add dx, 0FF40h
    if ((short)_dx >= (short)0xfc00)            //jge short loc_18B79
      goto loc_18B79;
    _dx = 0xfc00;                               //mov dx, 0FC00h
    goto loc_18B79;                             //jmp short loc_18B79
loc_18B5E:                                      //loc_18B5E:
    if (!(memory(_ds, 0xB884) & 0x04))          //jz short loc_18B79
      goto loc_18B79;
    _dx += 0x0080;                              //add dx, 80h
    if ((short)_dx <= (short)0x0400)            //jle short loc_18B79
      goto loc_18B79;
    _dx = 0x0400;                               //mov dx, 400h
loc_18B79:                                      //loc_18B79:
    memory16(_ds, 0xB24) = _dx;                 //mov ds:0B24h, dx
    memory16(_ds, 0x7961) = _dx;                //mov ds:7961h, dx
    _flags.sign = !!(_dx & 0x8000);             //or dx, dx
    _dx |= _dx;
    if (_flags.sign)                            //js short loc_18B8D
      goto loc_18B8D;
    _ch = _ch ^ _ch;                            //xor ch, ch
    goto loc_18B8F;                             //jmp short loc_18B8F
    _STOP_("db 90h");                           //db 90h
loc_18B8D:                                      //loc_18B8D:
    _ch = 0xff;                                 //mov ch, 0FFh
loc_18B8F:                                      //loc_18B8F:
    _ax = memory16(_ds, 0xB20);                 //mov ax, ds:0B20h
    _cl = memory(_ds, 0xB22);                   //mov cl, ds:0B22h
    _flags.carry = (_cl + _dl) >= 0x100;        //add cl, dl
    _cl += _dl;
    _flags.carry2 = (_al + _dh + _flags.carry) >= 0x100;
    _al = _al + _dh + _flags.carry;_flags.carry = flags.carry2;
    _ah = _ah + _ch + _flags.carry;             //adc ah, ch
    memory16(_ds, 0x795F) = _ax;                //mov ds:795Fh, ax
    _dx = memory16(_ds, 0xB1E);                 //mov dx, ds:0B1Eh
    memory16(_ds, 0x795D) = _dx;                //mov ds:795Dh, dx
    memory(_ds, 0x796B) = 0x01;                 //mov byte ptr ds:796Bh, 1
    sub_17DFB();                                //call sub_17DFB
    _ch = memory(_ds, 0x7963);                  //mov ch, ds:7963h
    if (!(_ch & 0x20))                          //jz short loc_18BBE
      goto loc_18BBE;
{sub_168A8(); return; };                        //
loc_18BBE:                                      //loc_18BBE:
    if (_ch & 0x04)                             //jnz short loc_18BEB
      goto loc_18BEB;
    if (!(_ch & 0x02))                          //jz short loc_18C00
      goto loc_18C00;
    _bp = memory16(_cs, 0xB24);                 //mov bp, cs:word_10F24
    _flags.sign = !!(_bp & 0x8000);             //or bp, bp
    _bp |= _bp;
    if (!_flags.sign)                           //jns short loc_18BEB
      goto loc_18BEB;
    _ax |= 0x0007;                              //or ax, 7
    _ax += 1;                                   //inc ax
    _dx = _dx ^ _dx;                            //xor dx, dx
    _cl = _cl ^ _cl;                            //xor cl, cl
    memory16(_ds, 0xB24) = 0x0000;              //mov word ptr ds:0B24h, 0
    goto loc_18C00;                             //jmp short loc_18C00
    _STOP_("db 90h");                           //db 90h
loc_18BEB:                                      //loc_18BEB:
    _ax += 0x000c;                              //add ax, 0Ch
    _ax |= 0x0007;                              //or ax, 7
    _ax -= 0x0014;                              //sub ax, 14h
    _cl = _cl ^ _cl;                            //xor cl, cl
    _dx = _dx ^ _dx;                            //xor dx, dx
    _cl = _cl ^ _cl;                            //xor cl, cl
    memory16(_ds, 0xB24) = 0x0000;              //mov word ptr ds:0B24h, 0
loc_18C00:                                      //loc_18C00:
    memory16(_ds, 0xB20) = _ax;                 //mov ds:0B20h, ax
    _bp = 0x0000;                               //mov bp, 0
    if (!(memory(_ds, 0xB884) & 0x02))          //jz short loc_18C1D
      goto loc_18C1D;
    _bp = 0xfffc;                               //mov bp, 0FFFCh
    memory16(_ds, 0xB36) = 0x0001;              //mov word ptr ds:0B36h, 1
    goto loc_18C31;                             //jmp short loc_18C31
    _STOP_("db 90h");                           //db 90h
loc_18C1D:                                      //loc_18C1D:
    if (!(memory(_ds, 0xB884) & 0x01))          //jz short loc_18C31
      goto loc_18C31;
    _bp = 0x0004;                               //mov bp, 4
    memory16(_ds, 0xB36) = 0x0000;              //mov word ptr ds:0B36h, 0
loc_18C31:                                      //loc_18C31:
    _bx = memory16(_ds, 0xB1E);                 //mov bx, ds:0B1Eh
    _bx += _bp;                                 //add bx, bp
    _flags.sign = !!(_bp & 0x8000);             //or bp, bp
    _bp |= _bp;
    if (_bp == 0)                               //jz short loc_18C69
      goto loc_18C69;
    if (!_flags.sign)                           //jns short loc_18C57
      goto loc_18C57;
    if ((short)_bx >= (short)0x0000)            //jge short loc_18C69
      goto loc_18C69;
    _bx = 0x0000;                               //mov bx, 0
    memory(_ds, 0x90C2) = 0x01;                 //mov byte ptr ds:90C2h, 1
    goto loc_18C69;                             //jmp short loc_18C69
    _STOP_("db 90h");                           //db 90h
loc_18C57:                                      //loc_18C57:
    if ((short)_bx < (short)0x00e8)             //jl short loc_18C69
      goto loc_18C69;
    _bx = 0x00e8;                               //mov bx, 0E8h
    memory(_ds, 0x90C2) = 0x02;                 //mov byte ptr ds:90C2h, 2
loc_18C69:                                      //loc_18C69:
    _ax = memory16(_ds, 0xB20);                 //mov ax, ds:0B20h
    memory16(_ds, 0x795F) = _ax;                //mov ds:795Fh, ax
    memory16(_ds, 0x7961) = 0xffff;             //mov word ptr ds:7961h, 0FFFFh
    memory(_ds, 0x796B) = 0x01;                 //mov byte ptr ds:796Bh, 1
    memory16(_ds, 0x795D) = _bx;                //mov ds:795Dh, bx
    _dx = _bp;                                  //mov dx, bp
    _STOP_("goto loc_187DB");                   //jmp loc_187DB
}

void sub_18C83()
{
    if (memory(_ds, 0xB884) & 0x10)             //jnz short loc_18C95
      goto loc_18C95;
    memory16(_ds, 0x7E12) = 0x0001;             //mov word ptr ds:7E12h, 1
    return;                                     //retn
loc_18C95:                                      //loc_18C95:
    memory16(_ds, 0x7E10) = 0x0001;             //mov word ptr ds:7E10h, 1
    if (memory16(_ds, 0x7E12) == 0x0000)        //jz short locret_18CBD
      goto locret_18CBD;
    if (!(memory16(_ds, 0x6610) & 0x00ff))      //jz short locret_18CBD
      goto locret_18CBD;
    if (memory16(_ds, 0xB00) == 0x0001)         //jz short locret_18CBD
      goto locret_18CBD;
{sub_18A9A(); return; };                        //
locret_18CBD:                                   //locret_18CBD:
    return;
}

void sub_18CBE()
{
    if (memory16(_ds, 0xB00) == 0x0001)         //jz short loc_18CC9
      goto loc_18CC9;
    return;                                     //retn
loc_18CC9:                                      //loc_18CC9:
    _dx = 0x0004;                               //mov dx, 4
    _ax = memory16(_ds, 0xB1A);                 //mov ax, ds:0B1Ah
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (_flags.sign)                            //js short loc_18CD9
      goto loc_18CD9;
    _dx = 0x0014;                               //mov dx, 14h
loc_18CD9:                                      //loc_18CD9:
    _ax = _ax + memory16(_ds, 0xB02);           //add ax, ds:0B02h
    _dx += _ax;                                 //add dx, ax
    if ((short)_dx < (short)0x0003)             //jl short loc_18D21
      goto loc_18D21;
    if ((short)_dx > (short)0x00fc)             //jg short loc_18D21
      goto loc_18D21;
    memory16(_ds, 0x795D) = _dx;                //mov ds:795Dh, dx
    _cx = memory16(_ds, 0xB04);                 //mov cx, ds:0B04h
    memory16(_ds, 0x795F) = _cx;                //mov ds:795Fh, cx
    memory16(_ds, 0x795F) += 0x0004;            //add word ptr ds:795Fh, 4
    sub_18014();                                //call sub_18014
    _push(_ax);                                 //push ax
    sub_181C6();                                //call sub_181C6
    _ax = _pop();                               //pop ax
    _ch = memory(_ds, 0x7963);                  //mov ch, ds:7963h
    if (_ch & 0x02)                             //jnz short loc_18D21
      goto loc_18D21;
    if (_ch & 0x40)                             //jnz short loc_18D21
      goto loc_18D21;
    memory16(_ds, 0xB02) = _ax;                 //mov ds:0B02h, ax
    return;                                     //retn
loc_18D21:                                      //loc_18D21:
    memory16(_ds, 0xB00) = 0x0000;              //mov word ptr ds:0B00h, 0
}

void sub_18D28()
{
    WORD _cs = _seg001;

    memory16(_ds, 0x7E1E) = 0x0000;             //mov word ptr ds:7E1Eh, 0
    if ((short)memory16(_ds, 0xB38) >= (short)0x0001)//jge short loc_18D39
      goto loc_18D39;
    return;                                     //retn
loc_18D39:                                      //loc_18D39:
    if ((short)memory16(_ds, 0xB38) <= (short)0x0001)//jle short loc_18D3E
      goto loc_18D3E;
    goto loc_18F57;                             //jmp loc_18F57
loc_18D3E:                                      //loc_18D3E:
    _si = 0x0b38;                               //mov si, 0B38h
    sub_1718E();                                //call sub_1718E
    if (!_flags.carry)                          //jnb short loc_18D49
      goto loc_18D49;
    goto loc_18F3A;                             //jmp loc_18F3A
loc_18D49:                                      //loc_18D49:
    _dx = memory16(_ds, 0xB40);                 //mov dx, ds:0B40h
    _dx += 0x0080;                              //add dx, 80h
    if ((short)_dx <= (short)0x0800)            //jle short loc_18D5A
      goto loc_18D5A;
    _dx = 0x0800;                               //mov dx, 800h
loc_18D5A:                                      //loc_18D5A:
    memory16(_ds, 0xB40) = _dx;                 //mov ds:0B40h, dx
    memory16(_ds, 0x7961) = _dx;                //mov ds:7961h, dx
    _flags.sign = !!(_dx & 0x8000);             //or dx, dx
    _dx |= _dx;
    if (_flags.sign)                            //js short loc_18D6B
      goto loc_18D6B;
    _ch = _ch ^ _ch;                            //xor ch, ch
    goto loc_18D6D;                             //jmp short loc_18D6D
    _STOP_("db 90h");                           //db 90h
loc_18D6B:                                      //loc_18D6B:
    _ch = 0xff;                                 //mov ch, 0FFh
loc_18D6D:                                      //loc_18D6D:
    _ax = memory16(_ds, 0xB3C);                 //mov ax, ds:0B3Ch
    _cl = memory(_ds, 0xB3E);                   //mov cl, ds:0B3Eh
    _flags.carry = (_cl + _dl) >= 0x100;        //add cl, dl
    _cl += _dl;
    _flags.carry2 = (_al + _dh + _flags.carry) >= 0x100;
    _al = _al + _dh + _flags.carry;_flags.carry = flags.carry2;
    _ah = _ah + _ch + _flags.carry;             //adc ah, ch
    _dx = _ax;                                  //mov dx, ax
    if ((short)_dx <= (short)0x0171)            //jle short loc_18D85
      goto loc_18D85;
    goto loc_18F91;                             //jmp loc_18F91
loc_18D85:                                      //loc_18D85:
    if ((short)_dx >= (short)0x0000)            //jge short loc_18D8D
      goto loc_18D8D;
    goto loc_18F91;                             //jmp loc_18F91
loc_18D8D:                                      //loc_18D8D:
    memory16(_ds, 0x795F) = _dx;                //mov ds:795Fh, dx
    _ax = memory16(_ds, 0xB3A);                 //mov ax, ds:0B3Ah
    memory16(_ds, 0x795D) = _ax;                //mov ds:795Dh, ax
    memory(_ds, 0x796B) = 0x01;                 //mov byte ptr ds:796Bh, 1
    sub_1802D();                                //call sub_1802D
    _ch = memory(_ds, 0x7963);                  //mov ch, ds:7963h
    if (!(_ch & 0x40))                          //jz short loc_18DEC
      goto loc_18DEC;
    _dx = _dx ^ _dx;                            //xor dx, dx
    _ax = memory16(_ds, 0x7964);                //mov ax, ds:7964h
    _cl = _cl ^ _cl;                            //xor cl, cl
    _ax -= 0x0010;                              //sub ax, 10h
    memory16(_ds, 0x795F) = _ax;                //mov ds:795Fh, ax
    memory16(_ds, 0xB3C) = _ax;                 //mov ds:0B3Ch, ax
    memory(_ds, 0xB3E) = 0x00;                  //mov byte ptr ds:0B3Eh, 0
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, 0x7966);                //mov ax, ds:7966h
    memory16(_ds, 0x7E1E) = _ax;                //mov ds:7E1Eh, ax
    _ax = _pop();                               //pop ax
    memory(_ds, 0x796B) = 0x00;                 //mov byte ptr ds:796Bh, 0
    sub_1802D();                                //call sub_1802D
    _ch = memory(_ds, 0x7963);                  //mov ch, ds:7963h
    if (_ch & 0x20)                             //jnz short loc_18DE4
      goto loc_18DE4;
    if (_ch & 0x06)                             //jnz short loc_18E08
      goto loc_18E08;
    memory16(_ds, 0xB40) = 0x0100;              //mov word ptr ds:0B40h, 100h
    goto loc_18E5A;                             //jmp short loc_18E5A
loc_18DE4:                                      //loc_18DE4:
    if (!(_ch & 0x20))                          //jz short loc_18DEC
      goto loc_18DEC;
    goto loc_18F3A;                             //jmp loc_18F3A
loc_18DEC:                                      //loc_18DEC:
    if (_ch & 0x04)                             //jnz short loc_18E11
      goto loc_18E11;
    if (_ch & 0x02)                             //jnz short loc_18E01
      goto loc_18E01;
    memory16(_ds, 0xB3C) = _dx;                 //mov ds:0B3Ch, dx
    memory(_ds, 0xB3E) = _cl;                   //mov ds:0B3Eh, cl
    goto loc_18E5A;                             //jmp short loc_18E5A
    _STOP_("db 90h");                           //db 90h
loc_18E01:                                      //loc_18E01:
    _ax = memory16(_ds, 0xB40);                 //mov ax, ds:0B40h
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (!_flags.sign)                           //jns short loc_18E11
      goto loc_18E11;
loc_18E08:                                      //loc_18E08:
    _dx |= 0x0007;                              //or dx, 7
    _dx += 1;                                   //inc dx
    _cl = _cl ^ _cl;                            //xor cl, cl
    goto loc_18E18;                             //jmp short loc_18E18
    _STOP_("db 90h");                           //db 90h
loc_18E11:                                      //loc_18E11:
    _dx -= 1;                                   //dec dx
    _dx &= 0x0ff8;                              //and dx, 0FF8h
    _cl = _cl ^ _cl;                            //xor cl, cl
loc_18E18:                                      //loc_18E18:
    memory16(_ds, 0xB3C) = _dx;                 //mov ds:0B3Ch, dx
    memory(_ds, 0xB3E) = _cl;                   //mov ds:0B3Eh, cl
    if (!(_ch & 0x20))                          //jz short loc_18E28
      goto loc_18E28;
    goto loc_18F3A;                             //jmp loc_18F3A
loc_18E28:                                      //loc_18E28:
    if (!(_ch & 0x01))                          //jz short loc_18E54
      goto loc_18E54;
    if (memory16(_ds, 0x8BEC) != 0x0003)        //jnz short loc_18E47
      goto loc_18E47;
    _ax = memory16(_ds, 0xB40);                 //mov ax, ds:0B40h
    if ((short)_ax < (short)0x0200)             //jl short loc_18E54
      goto loc_18E54;
    _ax = -_ax;                                 //neg ax
    _ax += 0x0060;                              //add ax, 60h
    memory16(_ds, 0xB40) = _ax;                 //mov ds:0B40h, ax
    goto loc_18E5A;                             //jmp short loc_18E5A
    _STOP_("db 90h");                           //db 90h
loc_18E47:                                      //loc_18E47:
    if (memory16(_ds, 0x8BEC) != 0x0005)        //jnz short loc_18E54
      goto loc_18E54;
    _ax = 0xf781;                               //mov ax, 0F781h
    goto loc_18E57;                             //jmp short loc_18E57
loc_18E54:                                      //loc_18E54:
    _ax = 0x0100;                               //mov ax, 100h
loc_18E57:                                      //loc_18E57:
    memory16(_ds, 0xB40) = _ax;                 //mov ds:0B40h, ax
loc_18E5A:                                      //loc_18E5A:
    _dx = memory16(_ds, 0xB52);                 //mov dx, ds:0B52h
    _bx = 0x0008;                               //mov bx, 8
    if (!(_ch & 0x01))                          //jz short loc_18E7E
      goto loc_18E7E;
    if (memory16(_ds, 0x8BEC) == 0x0001)        //jz short loc_18E92
      goto loc_18E92;
    if (memory16(_ds, 0x8BEC) == 0x0002)        //jz short loc_18EAD
      goto loc_18EAD;
    if (memory16(_ds, 0x8BEC) != 0x0004)        //jnz short loc_18E7E
      goto loc_18E7E;
    _bx = 0x0010;                               //mov bx, 10h
loc_18E7E:                                      //loc_18E7E:
    _bp = memory16(_cs, 0xB52);                 //mov bp, cs:word_10F52
    _flags.sign = !!(_bp & 0x8000);             //or bp, bp
    _bp |= _bp;
    if (_flags.sign)                            //js short loc_18E8E
      goto loc_18E8E;
    _dx -= _bx;                                 //sub dx, bx
    if ((short)_dx >= 0)                        //jns short loc_18E94
      goto loc_18E94;
    goto loc_18E92;                             //jmp short loc_18E92
loc_18E8E:                                      //loc_18E8E:
    _flags.sign = (short)(_dx + _bx) < 0;       //add dx, bx
    _dx += _bx;
    if (_flags.sign)                            //js short loc_18E94
      goto loc_18E94;
loc_18E92:                                      //loc_18E92:
    _dx = _dx ^ _dx;                            //xor dx, dx
loc_18E94:                                      //loc_18E94:
    memory16(_ds, 0xB52) = _dx;                 //mov ds:0B52h, dx
    _ax = memory16(_ds, 0x7E1E);                //mov ax, ds:7E1Eh
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _dx += _ax;                                 //add dx, ax
loc_18EAD:                                      //loc_18EAD:
    _bx = memory16(_ds, 0xB3A);                 //mov bx, ds:0B3Ah
    _cl = memory(_ds, 0xB3F);                   //mov cl, ds:0B3Fh
    _ax = memory16(_ds, 0xB3C);                 //mov ax, ds:0B3Ch
    memory16(_ds, 0x795F) = _ax;                //mov ds:795Fh, ax
    memory16(_ds, 0x7961) = 0xffff;             //mov word ptr ds:7961h, 0FFFFh
    _flags.sign = !!(_dx & 0x8000);             //or dx, dx
    _dx |= _dx;
    if (_flags.sign)                            //js short loc_18ECA
      goto loc_18ECA;
    _ch = _ch ^ _ch;                            //xor ch, ch
    goto loc_18ECC;                             //jmp short loc_18ECC
loc_18ECA:                                      //loc_18ECA:
    _ch = 0xff;                                 //mov ch, 0FFh
loc_18ECC:                                      //loc_18ECC:
    _bx = memory16(_ds, 0xB3A);                 //mov bx, ds:0B3Ah
    _cl = memory(_ds, 0xB3F);                   //mov cl, ds:0B3Fh
    _flags.carry = (_cl + _dl) >= 0x100;        //add cl, dl
    _cl += _dl;
    _flags.carry2 = (_bl + _dh + _flags.carry) >= 0x100;
    _bl = _bl + _dh + _flags.carry;_flags.carry = flags.carry2;
    _bh = _bh + _ch + _flags.carry;             //adc bh, ch
    if ((short)_bx < (short)0x00e8)             //jl short loc_18EEE
      goto loc_18EEE;
    _cl = _cl ^ _cl;                            //xor cl, cl
    _bx = 0x00e8;                               //mov bx, 0E8h
    memory16(_ds, 0xB52) = 0x0000;              //mov word ptr ds:0B52h, 0
    goto loc_18EFD;                             //jmp short loc_18EFD
loc_18EEE:                                      //loc_18EEE:
    if ((short)_bx >= (short)0x0000)            //jge short loc_18EFD
      goto loc_18EFD;
    _cl = _cl ^ _cl;                            //xor cl, cl
    _bx = _bx ^ _bx;                            //xor bx, bx
    memory16(_ds, 0xB52) = 0x0000;              //mov word ptr ds:0B52h, 0
loc_18EFD:                                      //loc_18EFD:
    memory16(_ds, 0x795D) = _bx;                //mov ds:795Dh, bx
    memory(_ds, 0x796B) = 0x01;                 //mov byte ptr ds:796Bh, 1
    sub_1802D();                                //call sub_1802D
    _ch = memory(_ds, 0x7963);                  //mov ch, ds:7963h
    if (!(_ch & 0x02))                          //jz short loc_18F2C
      goto loc_18F2C;
    _cl = _cl ^ _cl;                            //xor cl, cl
    _bp = memory16(_ds, 0xB52);                 //mov bp, ds:0B52h
    _bp = _bp + memory16(_ds, 0x7E1E);          //add bp, ds:7E1Eh
    _flags.sign = !!(_bp & 0x8000);             //or bp, bp
    _bp |= _bp;
    if (!_flags.sign)                           //jns short loc_18F27
      goto loc_18F27;
    _bx |= 0x0007;                              //or bx, 7
    _bx += 1;                                   //inc bx
    goto loc_18F2C;                             //jmp short loc_18F2C
    _STOP_("db 90h");                           //db 90h
loc_18F27:                                      //loc_18F27:
    _bx -= 1;                                   //dec bx
    _bx &= 0x00f8;                              //and bx, 0F8h
loc_18F2C:                                      //loc_18F2C:
    memory16(_ds, 0xB3A) = _bx;                 //mov ds:0B3Ah, bx
    memory(_ds, 0xB3F) = _cl;                   //mov ds:0B3Fh, cl
    if (_ch & 0x20)                             //jnz short loc_18F3A
      goto loc_18F3A;
    return;                                     //retn
loc_18F3A:                                      //loc_18F3A:
    memory16(_ds, 0xB38) = 0x0002;              //mov word ptr ds:0B38h, 2
    memory16(_ds, 0xB50) = 0x0000;              //mov word ptr ds:0B50h, 0
    memory16(_ds, 0xB4E) = 0x7eb2;              //mov word ptr ds:0B4Eh, 7EB2h
    memory16(_ds, 0xB3C) -= 0x0005;             //sub word ptr ds:0B3Ch, 5
    memory16(_ds, 0xB4A) = 0x0000;              //mov word ptr ds:0B4Ah, 0
loc_18F57:                                      //loc_18F57:
    _si = 0x0b38;                               //mov si, 0B38h
    memory16(_ds, 0xB4A) += 1;                  //inc word ptr ds:0B4Ah
    if ((char)memory(_ds, 0xB4A) <= (char)0x01) //jle short loc_18F8C
      goto loc_18F8C;
    if ((char)memory(_ds, 0xB4A) > (char)0x04)  //jg short loc_18F8C
      goto loc_18F8C;
    _dx = memory16(_ds, 0xB3A);                 //mov dx, ds:0B3Ah
    _dx -= 0x0004;                              //sub dx, 4
    if ((short)_dx >= 0)                        //jns short loc_18F77
      goto loc_18F77;
    _dx = _dx ^ _dx;                            //xor dx, dx
loc_18F77:                                      //loc_18F77:
    _xchg(_dl, _dh);                            //xchg dl, dh
    _bx = memory16(_ds, 0xB3C);                 //mov bx, ds:0B3Ch
    _bx -= 0x0004;                              //sub bx, 4
    _dl = 0x20;                                 //mov dl, 20h
    _ah = 0x1c;                                 //mov ah, 1Ch
    sub_16407();                                //call sub_16407
    if (!_flags.carry)                          //jnb short loc_18F8C
      goto loc_18F8C;
    sub_168A8();                                //call sub_168A8
loc_18F8C:                                      //loc_18F8C:
    sub_1718E();                                //call sub_1718E
    if (!_flags.carry)                          //jnb short locret_18F97
      goto locret_18F97;
loc_18F91:                                      //loc_18F91:
    memory16(_ds, 0xB38) = 0x0000;              //mov word ptr ds:0B38h, 0
locret_18F97:                                   //locret_18F97:
    return;
}

void loc_18F9A()
{
    _dx = memory16(_ds, 0xB24);                 //mov dx, ds:0B24h
    _dx += 0x0080;                              //add dx, 80h
    memory16(_ds, 0xB24) = _dx;                 //mov ds:0B24h, dx
    _flags.sign = !!(_dx & 0x8000);             //or dx, dx
    _dx |= _dx;
    if (_flags.sign)                            //js short loc_18FAF
      goto loc_18FAF;
    _ch = _ch ^ _ch;                            //xor ch, ch
    goto loc_18FB1;                             //jmp short loc_18FB1
    _STOP_("db 90h");                           //db 90h
loc_18FAF:                                      //loc_18FAF:
    _ch = 0xff;                                 //mov ch, 0FFh
loc_18FB1:                                      //loc_18FB1:
    _ax = memory16(_ds, 0xB20);                 //mov ax, ds:0B20h
    _cl = memory(_ds, 0xB22);                   //mov cl, ds:0B22h
    _flags.carry = (_cl + _dl) >= 0x100;        //add cl, dl
    _cl += _dl;
    _flags.carry2 = (_al + _dh + _flags.carry) >= 0x100;
    _al = _al + _dh + _flags.carry;_flags.carry = flags.carry2;
    _ah = _ah + _ch + _flags.carry;             //adc ah, ch
    if ((short)_ax <= (short)0x0110)            //jle short loc_18FCA
      goto loc_18FCA;
    memory16(_ds, 0x7E18) = 0x0001;             //mov word ptr ds:7E18h, 1
    return;                                     //retn
loc_18FCA:                                      //loc_18FCA:
    memory16(_ds, 0xB20) = _ax;                 //mov ds:0B20h, ax
    memory(_ds, 0xB22) = _cl;                   //mov ds:0B22h, cl
    _al = memory(_ds, 0x8B98);                  //mov al, ds:8B98h
    _al = (~_al);                               //not al
    memory(_ds, 0x8B98) = _al;                  //mov ds:8B98h, al
    _al &= 0x01;                                //and al, 1
    _ax += 0x001c;                              //add ax, 1Ch
    memory16(_ds, 0xB26) = _ax;                 //mov ds:0B26h, ax
    _ax = memory16(_ds, 0x7E1C);                //mov ax, ds:7E1Ch
    _ax = _ax + memory16(_ds, 0xB1E);           //add ax, ds:0B1Eh
    memory16(_ds, 0xB1E) = _ax;                 //mov ds:0B1Eh, ax
    return;                                     //retn
    _STOP_("word_18FEC dw 1");                  //word_18FEC dw 1
    _STOP_("word_18FEE dw 0");                  //word_18FEE dw 0
    _STOP_("word_18FF0 dw 0");                  //word_18FF0 dw 0
    _STOP_("db 3 dup(0), 1, 74h, 33h, 1Bh dup(0), 90h,...");
}

void sub_19214()
{
    _bx = memory16(_ds, 0x8BF6);                //mov bx, ds:8BF6h
    _di = 0x563c;                               //mov di, 563Ch
    _cx = 0x000a;                               //mov cx, 0Ah
    _dx = memory16(_ds, 0x8BF0);                //mov dx, ds:8BF0h
    _dx &= 0xfff8;                              //and dx, 0FFF8h
    _dx >>= 1;                                  //shr dx, 1
    _dx >>= 1;                                  //shr dx, 1
    _dx >>= 1;                                  //shr dx, 1
    _ax = _dx;                                  //mov ax, dx
    _dx &= 0xfffc;                              //and dx, 0FFFCh
    _dx >>= 1;                                  //shr dx, 1
    _dx >>= 1;                                  //shr dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _bx += _dx;                                 //add bx, dx
    memory16(_ds, 0x8BF8) = _bx;                //mov ds:8BF8h, bx
    _ax &= 0x0003;                              //and ax, 3
    memory16(_ds, 0x8BFA) = _ax;                //mov ds:8BFAh, ax
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_19257
      goto loc_19257;
    _dx = 0x0004;                               //mov dx, 4
    _dx -= _ax;                                 //sub dx, ax
    _push(_cx);                                 //push cx
    sub_1926D();                                //call sub_1926D
    _cx = _pop();                               //pop cx
    goto loc_1925C;                             //jmp short loc_1925C
    _STOP_("db 90h");                           //db 90h
loc_19257:                                      //loc_19257:
    _push(_cx);                                 //push cx
    sub_192AE();                                //call sub_192AE
    _cx = _pop();                               //pop cx
loc_1925C:                                      //loc_1925C:
    if (--_cx)                                  //loop loc_19257
      goto loc_19257;
    _dx = memory16(_ds, 0x8BFA);                //mov dx, ds:8BFAh
    _dx |= _dx;                                 //or dx, dx
    if (_dx == 0)                               //jz short locret_1926C
      goto locret_1926C;
    _ax = 0x0000;                               //mov ax, 0
    sub_1926D();                                //call sub_1926D
locret_1926C:                                   //locret_1926C:
    return;
}

void sub_1926D()
{
    _push(_di);                                 //push di
    _push(_dx);                                 //push dx
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _cx = 0x0008;                               //mov cx, 8
loc_19276:                                      //loc_19276:
    _push(_cx);                                 //push cx
    _push(_ax);                                 //push ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    _ax <<= 1;                                  //shl ax, 1
    _si = 0x8c14;                               //mov si, 8C14h
    _si += _ax;                                 //add si, ax
    _ax = _pop();                               //pop ax
    _si = memory16(_ds, _si);                   //mov si, [si]
    _si += _ax;                                 //add si, ax
    _bp = _di;                                  //mov bp, di
    _push(_dx);                                 //push dx
loc_1928C:                                      //loc_1928C:
    _cx = 0x0004;                               //mov cx, 4
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di += 0x001c;                              //add di, 1Ch
    _dx -= 1;                                   //dec dx
    if (_dx != 0)                               //jnz short loc_1928C
      goto loc_1928C;
    _dx = _pop();                               //pop dx
    _di = _bp;                                  //mov di, bp
    _di += 0x0004;                              //add di, 4
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_19276
      goto loc_19276;
    _dx = _pop();                               //pop dx
    _di = _pop();                               //pop di
    _dx -= 1;                                   //dec dx
    _dx &= 0x0003;                              //and dx, 3
    _dx += 1;                                   //inc dx
    _cl = 0x05;                                 //mov cl, 5
    _dx <<= _cl;                                //shl dx, cl
    _di += _dx;                                 //add di, dx
}

void sub_192AE()
{
    _cx = 0x0008;                               //mov cx, 8
loc_192B1:                                      //loc_192B1:
    _bp = _cx;                                  //mov bp, cx
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    _ax <<= 1;                                  //shl ax, 1
    _si = 0x8c14;                               //mov si, 8C14h
    _si += _ax;                                 //add si, ax
    _si = memory16(_ds, _si);                   //mov si, [si]
    _dx = 0x0004;                               //mov dx, 4
loc_192C4:                                      //loc_192C4:
    _cx = 0x0004;                               //mov cx, 4
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di += 0x001c;                              //add di, 1Ch
    _dx -= 1;                                   //dec dx
    if (_dx != 0)                               //jnz short loc_192C4
      goto loc_192C4;
    _di += 0xff84;                              //add di, 0FF84h
    _cx = _bp;                                  //mov cx, bp
    if (--_cx)                                  //loop loc_192B1
      goto loc_192B1;
    _di += 0x0060;                              //add di, 60h
}

void sub_192DA()
{
    _di = 0x563c;                               //mov di, 563Ch
    _si = 0x565c;                               //mov si, 565Ch
    _cx = 0x0270;                               //mov cx, 270h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _ax = memory16(_ds, 0x8BFA);                //mov ax, ds:8BFAh
    _dx = 0x0001;                               //mov dx, 1
    _bx = memory16(_ds, 0x8BF8);                //mov bx, ds:8BF8h
    _bx += 0x0050;                              //add bx, 50h
    _di = 0x5b1c;                               //mov di, 5B1Ch
    sub_1926D();                                //call sub_1926D
    memory16(_ds, 0x8BFA) += 0x0001;            //add word ptr ds:8BFAh, 1
    memory16(_ds, 0x8BFA) &= 0x0003;            //and word ptr ds:8BFAh, 3
    if (memory16(_ds, 0x8BFA) != 0)             //jnz short locret_19309
      goto locret_19309;
    memory16(_ds, 0x8BF8) += 0x0008;            //add word ptr ds:8BF8h, 8
locret_19309:                                   //locret_19309:
    return;
}

void sub_1930A()
{
    _si = 0x5b1a;                               //mov si, 5B1Ah
    _di = 0x5b3a;                               //mov di, 5B3Ah
    _flags.direction = true;                    //std
    _cx = 0x0270;                               //mov cx, 270h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _flags.direction = false;                   //cld
    _bx = memory16(_ds, 0x8BF8);                //mov bx, ds:8BF8h
    memory16(_ds, 0x8BFA) -= 1;                 //dec word ptr ds:8BFAh
    memory16(_ds, 0x8BFA) &= 0x0003;            //and word ptr ds:8BFAh, 3
    if (memory16(_ds, 0x8BFA) != 0x0003)        //jnz short loc_19332
      goto loc_19332;
    _bx -= 0x0008;                              //sub bx, 8
    memory16(_ds, 0x8BF8) = _bx;                //mov ds:8BF8h, bx
loc_19332:                                      //loc_19332:
    _di = 0x563c;                               //mov di, 563Ch
    _ax = memory16(_ds, 0x8BFA);                //mov ax, ds:8BFAh
    _dx = 0x0001;                               //mov dx, 1
    sub_1926D();                                //call sub_1926D
}

void sub_1933F()
{
    _ax = 0x3c74;                               //mov ax, 3C74h
    _di = 0x8c14;                               //mov di, 8C14h
    _dx = 0x0010;                               //mov dx, 10h
    _cx = 0x0100;                               //mov cx, 100h
loc_1934B:                                      //loc_1934B:
    _stosw<MemAuto, DirAuto>();                 //stosw
    _ax += _dx;                                 //add ax, dx
    if (--_cx)                                  //loop loc_1934B
      goto loc_1934B;
}

void sub_19351()
{
    memory16(_ds, 0xB00) = 0x0000;              //mov word ptr ds:0B00h, 0
    memory16(_ds, 0xB38) = 0x0000;              //mov word ptr ds:0B38h, 0
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, 0xB1E);                 //mov ax, ds:0B1Eh
    memory16(_ds, 0x8C00) = _ax;                //mov ds:8C00h, ax
    _ax = memory16(_ds, 0xB20);                 //mov ax, ds:0B20h
    memory16(_ds, 0x8C02) = _ax;                //mov ds:8C02h, ax
    _ax = memory16(_ds, 0xB24);                 //mov ax, ds:0B24h
    memory16(_ds, 0x8C08) = _ax;                //mov ds:8C08h, ax
    _al = memory(_ds, 0xB22);                   //mov al, ds:0B22h
    memory(_ds, 0x8C12) = _al;                  //mov ds:8C12h, al
    _ax = memory16(_ds, 0x7E02);                //mov ax, ds:7E02h
    memory16(_ds, 0x8C0A) = _ax;                //mov ds:8C0Ah, ax
    _ax = memory16(_ds, 0x7E04);                //mov ax, ds:7E04h
    memory16(_ds, 0x8C0C) = _ax;                //mov ds:8C0Ch, ax
    _ax = memory16(_ds, 0xB36);                 //mov ax, ds:0B36h
    memory16(_ds, 0x8C0E) = _ax;                //mov ds:8C0Eh, ax
    _ax = memory16(_ds, 0x7E00);                //mov ax, ds:7E00h
    memory16(_ds, 0x8C10) = _ax;                //mov ds:8C10h, ax
    _ax = _pop();                               //pop ax
    memory16(_ds, 0x8C04) = _ax;                //mov ds:8C04h, ax
    memory16(_ds, 0x8C06) = _dx;                //mov ds:8C06h, dx
    _si = 0x4c74;                               //mov si, 4C74h
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _si += _ax;                                 //add si, ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _ax = _ax + memory16(_ds, _si);             //add ax, [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    _xchg(_al, _ah);                            //xchg al, ah
    _ax += 0x3374;                              //add ax, 3374h
    memory16(_ds, 0x8BF6) = _ax;                //mov ds:8BF6h, ax
    memory16(_ds, 0x8BF2) = 0x0000;             //mov word ptr ds:8BF2h, 0
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    _xchg(_al, _ah);                            //xchg al, ah
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    memory16(_ds, 0x8BF4) = _ax;                //mov ds:8BF4h, ax
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    _xchg(_al, _ah);                            //xchg al, ah
    _ax += 0x4c74;                              //add ax, 4C74h
    memory16(_ds, 0x8BFE) = _ax;                //mov ds:8BFEh, ax
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    _xchg(_al, _ah);                            //xchg al, ah
    _ax += 0x4c74;                              //add ax, 4C74h
    memory16(_ds, 0x8BFC) = _ax;                //mov ds:8BFCh, ax
    memory16(_ds, 0x8BF0) = _dx;                //mov ds:8BF0h, dx
    sub_19577();                                //call sub_19577
}

void sub_19420()
{
    _si = 0x8fe4;                               //mov si, 8FE4h
    _ax = memory16(_ds, 0x8BEC);                //mov ax, ds:8BECh
    _ax -= 1;                                   //dec ax
    _ax <<= 1;                                  //shl ax, 1
    _si += _ax;                                 //add si, ax
    _si = memory16(_ds, _si);                   //mov si, [si]
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    memory16(_ds, 0xB1E) = _ax;                 //mov ds:0B1Eh, ax
    _ax = memory16(_ds, _si + 2);               //mov ax, [si+2]
    memory16(_ds, 0xB20) = _ax;                 //mov ds:0B20h, ax
    _ax = memory16(_ds, _si + 4);               //mov ax, [si+4]
    _dx = memory16(_ds, _si + 6);               //mov dx, [si+6]
    _cx = memory16(_ds, _si + 8);               //mov cx, [si+8]
    memory16(_ds, 0xB36) = _cx;                 //mov ds:0B36h, cx
    sub_19351();                                //call sub_19351
    sub_19214();                                //call sub_19214
    sub_19577();                                //call sub_19577
    sub_17047();                                //call sub_17047
    sub_15FE4();                                //call sub_15FE4
    memory(_ds, 0x5B3E) = 0x01;                 //mov byte ptr ds:5B3Eh, 1
    sub_15F40();                                //call sub_15F40
    memory(_ds, 0x5B3E) = 0x00;                 //mov byte ptr ds:5B3Eh, 0
}

void sub_19462()
{
    _ax = memory16(_ds, 0x8C00);                //mov ax, ds:8C00h
    memory16(_ds, 0xB1E) = _ax;                 //mov ds:0B1Eh, ax
    _ax = memory16(_ds, 0x8C02);                //mov ax, ds:8C02h
    memory16(_ds, 0xB20) = _ax;                 //mov ds:0B20h, ax
    _ax = memory16(_ds, 0x8C08);                //mov ax, ds:8C08h
    memory16(_ds, 0xB24) = _ax;                 //mov ds:0B24h, ax
    _al = memory(_ds, 0x8C12);                  //mov al, ds:8C12h
    memory(_ds, 0xB22) = _al;                   //mov ds:0B22h, al
    _ax = memory16(_ds, 0x8C0A);                //mov ax, ds:8C0Ah
    memory16(_ds, 0x7E02) = _ax;                //mov ds:7E02h, ax
    _ax = memory16(_ds, 0x8C0C);                //mov ax, ds:8C0Ch
    memory16(_ds, 0x7E04) = _ax;                //mov ds:7E04h, ax
    _ax = memory16(_ds, 0x8C0E);                //mov ax, ds:8C0Eh
    memory16(_ds, 0xB36) = _ax;                 //mov ds:0B36h, ax
    _ax = memory16(_ds, 0x8C10);                //mov ax, ds:8C10h
    memory16(_ds, 0x7E00) = _ax;                //mov ds:7E00h, ax
    _ax = memory16(_ds, 0x8C04);                //mov ax, ds:8C04h
    _dx = memory16(_ds, 0x8C06);                //mov dx, ds:8C06h
    sub_19351();                                //call sub_19351
    sub_19214();                                //call sub_19214
    sub_19577();                                //call sub_19577
    sub_17047();                                //call sub_17047
    memory16(_ds, 0x6612) = 0x0006;             //mov word ptr ds:6612h, 6
    memory16(_ds, 0x6610) = 0x0006;             //mov word ptr ds:6610h, 6
    sub_15FE4();                                //call sub_15FE4
    memory(_ds, 0x5B3E) = 0x01;                 //mov byte ptr ds:5B3Eh, 1
    sub_15F40();                                //call sub_15F40
    memory(_ds, 0x5B3E) = 0x00;                 //mov byte ptr ds:5B3Eh, 0
}

void sub_194C4()
{
    _al = memory(_ds, 0x90C2);                  //mov al, ds:90C2h
    _al |= _al;                                 //or al, al
    if (_al != 0)                               //jnz short loc_194CC
      goto loc_194CC;
    return;                                     //retn
loc_194CC:                                      //loc_194CC:
    _si = memory16(_ds, 0x8BFE);                //mov si, ds:8BFEh
loc_194D0:                                      //loc_194D0:
    _al = memory(_ds, _si);                     //mov al, [si]
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz short locret_19552
      goto locret_19552;
    _al &= 0x03;                                //and al, 3
    if (_al != memory(_ds, 0x90C2))             //jnz short loc_194F6
      goto loc_194F6;
    _ax = memory16(_ds, 0x8BF0);                //mov ax, ds:8BF0h
    _ax &= 0xfff8;                              //and ax, 0FFF8h
    _ax = _ax + memory16(_ds, 0xB20);           //add ax, ds:0B20h
    _ax += 0x0014;                              //add ax, 14h
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    if (_al == memory(_ds, _si + 1))            //jz short loc_194FB
      goto loc_194FB;
loc_194F6:                                      //loc_194F6:
    _si += 0x0004;                              //add si, 4
    goto loc_194D0;                             //jmp short loc_194D0
loc_194FB:                                      //loc_194FB:
    _al = memory(_ds, _si);                     //mov al, [si]
    _ah = _al;                                  //mov ah, al
    _ah &= 0x90;                                //and ah, 90h
    if (_ah != 0x90)                            //jnz short loc_1950A
      goto loc_1950A;
{loc_19650(); return; };                        //
loc_1950A:                                      //loc_1950A:
    if (!(_al & 0x40))                          //jz short loc_19514
      goto loc_19514;
    memory16(_ds, 0x762D) = 0x0001;             //mov word ptr ds:762Dh, 1
loc_19514:                                      //loc_19514:
    if (!(_al & 0x20))                          //jz short loc_19521
      goto loc_19521;
    memory16(_ds, 0x7E00) = 0x0001;             //mov word ptr ds:7E00h, 1
    goto loc_19527;                             //jmp short loc_19527
    _STOP_("db 90h");                           //db 90h
loc_19521:                                      //loc_19521:
    memory16(_ds, 0x7E00) = 0x0000;             //mov word ptr ds:7E00h, 0
loc_19527:                                      //loc_19527:
    _cx = _cx ^ _cx;                            //xor cx, cx
    _al = memory(_ds, _si + 2);                 //mov al, [si+2]
    _dx = _dx ^ _dx;                            //xor dx, dx
    _dl = memory(_ds, _si + 3);                 //mov dl, [si+3]
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _cx = memory16(_ds, 0xB20);                 //mov cx, ds:0B20h
    _cx += 0x0014;                              //add cx, 14h
    _cx &= 0xfff8;                              //and cx, 0FFF8h
    _dx -= _cx;                                 //sub dx, cx
    _cx = memory16(_ds, 0x8BF0);                //mov cx, ds:8BF0h
    _cx &= 0x0007;                              //and cx, 7
    _dx &= 0xfff8;                              //and dx, 0FFF8h
    _dx |= _cx;                                 //or dx, cx
    sub_19553();                                //call sub_19553
locret_19552:                                   //locret_19552:
    return;
}

void sub_19553()
{
    _bx = memory16(_ds, 0xB1E);                 //mov bx, ds:0B1Eh
    _bx |= _bx;                                 //or bx, bx
    if (_bx != 0)                               //jnz short loc_19568
      goto loc_19568;
    memory16(_ds, 0xB1E) = 0x00e8;              //mov word ptr ds:0B1Eh, 0E8h
    _indirectCall(_ds, memory16(_ds, 0x20));    //call word ptr ds:20h
    goto locret_19572;                          //jmp short locret_19572
loc_19568:                                      //loc_19568:
    memory16(_ds, 0xB1E) = 0x0000;              //mov word ptr ds:0B1Eh, 0
    _indirectCall(_ds, memory16(_ds, 0x22));    //call word ptr ds:22h
locret_19572:                                   //locret_19572:
    return;
}

void sub_19577()
{
    memory16(_ds, 0x9173) = 0x0000;             //mov word ptr ds:9173h, 0
    _si = 0x54fa;                               //mov si, 54FAh
    memory16(_ds, 0x9175) = _si;                //mov ds:9175h, si
loc_19584:                                      //loc_19584:
    _al = memory(_ds, _si);                     //mov al, [si]
    _flags.sign = !!(_al & 0x80);               //or al, al
    _al |= _al;
    if (_flags.sign)                            //js short locret_19592
      goto locret_19592;
    memory(_ds, _si) = 0x00;                    //mov byte ptr [si], 0
    _si += 0x0008;                              //add si, 8
    goto loc_19584;                             //jmp short loc_19584
locret_19592:                                   //locret_19592:
    return;
}

void sub_19593()
{
    WORD _cs = _seg001;

    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_di);                                 //push di
    _push(_ax);                                 //push ax
    _push(_cs);                                 //push cs
    _ds = _pop();                               //pop ds
    if ((short)memory16(_ds, 0x9173) < (short)0x0028)//jl short loc_195A5
      goto loc_195A5;
    _ax = _pop();                               //pop ax
    _di = _pop();                               //pop di
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    return;                                     //retn
loc_195A5:                                      //loc_195A5:
    _dx = _dx ^ _dx;                            //xor dx, dx
    _dl = _al;                                  //mov dl, al
    _dx -= 0x00f8;                              //sub dx, 0F8h
    _dx += _dx;                                 //add dx, dx
    _dx += _dx;                                 //add dx, dx
    _ax = _ax ^ _ax;                            //xor ax, ax
    sub_19B40();                                //call sub_19B40
    _al = memory(_ds, 0x973F);                  //mov al, ds:973Fh
    _cbw();                                     //cbw
    _al &= 0x03;                                //and al, 3
    _dx += _ax;                                 //add dx, ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _si = 0x54fa;                               //mov si, 54FAh
loc_195C3:                                      //loc_195C3:
    _al = memory(_ds, _si);                     //mov al, [si]
    _flags.sign = !!(_al & 0x80);               //or al, al
    _al |= _al;
    if (_flags.sign)                            //js short loc_195E0
      goto loc_195E0;
    if (_al != 0)                               //jnz short loc_195E5
      goto loc_195E5;
    memory(_ds, _si) = 0x01;                    //mov byte ptr [si], 1
    _si += 1;                                   //inc si
    memory(_ds, _si) = _dl;                     //mov [si], dl
    _si += 1;                                   //inc si
    memory16(_ds, _si) = _bx;                   //mov [si], bx
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory16(_ds, _si) = _di;                   //mov [si], di
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory16(_ds, _si) = _bp;                   //mov [si], bp
    memory16(_ds, 0x9173) += 1;                 //inc word ptr ds:9173h
loc_195E0:                                      //loc_195E0:
    _ax = _pop();                               //pop ax
    _di = _pop();                               //pop di
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    return;                                     //retn
loc_195E5:                                      //loc_195E5:
    _si += 0x0008;                              //add si, 8
    goto loc_195C3;                             //jmp short loc_195C3
}

void sub_195EA()
{
    if (memory16(_ds, 0x9173) != 0x0000)        //jnz short loc_195F2
      goto loc_195F2;
    return;                                     //retn
loc_195F2:                                      //loc_195F2:
    _si = 0x54fa;                               //mov si, 54FAh
loc_195F5:                                      //loc_195F5:
    _al = memory(_ds, _si);                     //mov al, [si]
    _flags.sign = !!(_al & 0x80);               //or al, al
    _al |= _al;
    if (_al == 0)                               //jz short loc_19617
      goto loc_19617;
    if (_flags.sign)                            //js short locret_1961C
      goto locret_1961C;
    _ax = memory16(_ds, _si + 2);               //mov ax, [si+2]
    _ax += 0x0020;                              //add ax, 20h
    if ((short)_ax < (short)0x5a7c)             //jl short loc_19614
      goto loc_19614;
    memory(_ds, _si) = 0x00;                    //mov byte ptr [si], 0
    memory16(_ds, 0x9173) -= 1;                 //dec word ptr ds:9173h
    _si += 0x0008;                              //add si, 8
    goto loc_195F5;                             //jmp short loc_195F5
loc_19614:                                      //loc_19614:
    memory16(_ds, _si + 2) = _ax;               //mov [si+2], ax
loc_19617:                                      //loc_19617:
    _si += 0x0008;                              //add si, 8
    goto loc_195F5;                             //jmp short loc_195F5
locret_1961C:                                   //locret_1961C:
    return;
}

void sub_1961D()
{
    if (memory16(_ds, 0x9173) != 0x0000)        //jnz short loc_19625
      goto loc_19625;
    return;                                     //retn
loc_19625:                                      //loc_19625:
    _si = 0x54fa;                               //mov si, 54FAh
loc_19628:                                      //loc_19628:
    _al = memory(_ds, _si);                     //mov al, [si]
    _flags.sign = !!(_al & 0x80);               //or al, al
    _al |= _al;
    if (_al == 0)                               //jz short loc_1964A
      goto loc_1964A;
    if (_flags.sign)                            //js short locret_1964F
      goto locret_1964F;
    _ax = memory16(_ds, _si + 2);               //mov ax, [si+2]
    _ax -= 0x0020;                              //sub ax, 20h
    if ((short)_ax >= (short)0x573c)            //jge short loc_19647
      goto loc_19647;
    memory(_ds, _si) = 0x00;                    //mov byte ptr [si], 0
    memory16(_ds, 0x9173) -= 1;                 //dec word ptr ds:9173h
    _si += 0x0008;                              //add si, 8
    goto loc_19628;                             //jmp short loc_19628
loc_19647:                                      //loc_19647:
    memory16(_ds, _si + 2) = _ax;               //mov [si+2], ax
loc_1964A:                                      //loc_1964A:
    _si += 0x0008;                              //add si, 8
    goto loc_19628;                             //jmp short loc_19628
locret_1964F:                                   //locret_1964F:
    return;
}

void loc_19650()
{
    _indirectCall(_ds, memory16(_ds, 0x3C));    //call word ptr ds:3Ch
    _ax = memory16(_ds, 0x8BEC);                //mov ax, ds:8BECh
    if (_ax != 0x0004)                          //jnz short loc_19687
      goto loc_19687;
    if (memory16(_ds, 0x95C4) == 0x0001)        //jz short loc_19673
      goto loc_19673;
    if (memory16(_ds, 0x8BEE) == 0x0001)        //jz short loc_19673
      goto loc_19673;
    _ax = 0x0001;                               //mov ax, 1
    sub_1A257();                                //call sub_1A257
{loc_19F12(); return; };                        //
loc_19673:                                      //loc_19673:
    memory16(_ds, 0x8BEC) += 1;                 //inc word ptr ds:8BECh
    if (memory16(_ds, 0x8BEC) != 0x0005)        //jnz short loc_19684
      goto loc_19684;
    memory16(_ds, 0x95C4) = 0x0001;             //mov word ptr ds:95C4h, 1
loc_19684:                                      //loc_19684:
    _STOP_("goto loc_1C3B9");                   //jmp loc_1C3B9
loc_19687:                                      //loc_19687:
    if (memory16(_ds, 0x8BEC) != 0x0005)        //jnz short loc_196A7
      goto loc_196A7;
    if (memory16(_ds, 0x8BEE) != 0x0001)        //jnz short loc_19698
      goto loc_19698;
    _STOP_("goto loc_19F37");                   //jmp loc_19F37
loc_19698:                                      //loc_19698:
    memory16(_ds, 0x95C4) = 0x0001;             //mov word ptr ds:95C4h, 1
    _ax = 0x0001;                               //mov ax, 1
    sub_1A257();                                //call sub_1A257
{loc_19F12(); return; };                        //
loc_196A7:                                      //loc_196A7:
    memory16(_ds, 0x8BEC) += 1;                 //inc word ptr ds:8BECh
    _STOP_("goto loc_1C3B9");                   //jmp loc_1C3B9
{loc_19F12(); return; };                        //
    _STOP_("db 4Dh, 65h, 6Dh, 6Fh, 72h, 79h, 20h, 41h,...");
    _STOP_("db 6Fh, 63h, 61h, 74h, 69h, 6Fh, 6Eh, 20h,...");
    _STOP_("db 6Fh, 72h, 3Ah, 20h, 43h, 61h, 2 dup(6Eh...");
    _STOP_("db 20h, 72h, 75h, 6Eh, 20h, 52h, 49h, 43h,...");
    _STOP_("db 0Dh, 24h");                      //db 0Dh, 24h
}

void sub_196DD()
{
    _indirectCall(_ds, memory16(_ds, 0x0));     //call word ptr ds:0
    sub_1933F();                                //call sub_1933F
    _indirectCall(_ds, memory16(_ds, 0x10));    //call word ptr ds:10h
    _indirectCall(_ds, memory16(_ds, 0x18));    //call word ptr ds:18h
    sub_1ADCB();                                //call sub_1ADCB
    sub_1BC92();                                //call sub_1BC92
}

void loc_196F3()
{
    WORD _cs = _seg001;

    _flags.interrupt = false;                   //cli
    sub_1AE03();                                //call sub_1AE03
    sub_1BCB7();                                //call sub_1BCB7
    _flags.interrupt = true;                    //sti
    _al = memory(_ds, 0x6A);                    //mov al, ds:6Ah
    _ah = _ah ^ _ah;                            //xor ah, ah
    _interrupt(16);                             //int 10h
    if (memory16(_ds, 0xAB2B) == 0x0001)        //jz short loc_1970F
      goto loc_1970F;
    sub_1ADB0();                                //call sub_1ADB0
    goto loc_1972D;                             //jmp short loc_1972D
    _STOP_("db 90h");                           //db 90h
loc_1970F:                                      //loc_1970F:
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _bx = _cs;                                  //mov bx, cs
    _es = _bx;                                  //mov es, bx
    _si = 0x0000;                               //mov si, 0
    _bx = 0xb3a7;                               //mov bx, 0B3A7h
    _interrupt(101);                            //int 65h
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
loc_1972D:                                      //loc_1972D:
    _ah = 0x4c;                                 //mov ah, 4Ch
    _interrupt(33);                             //int 21h
loc_19731:                                      //loc_19731:
    _ah = 0x09;                                 //mov ah, 9
    _dx = _seg001;                              //mov dx, seg seg001
    _ds = _dx;                                  //mov ds, dx
    _dx = 0x92b1;                               //mov dx, 92B1h
    _interrupt(33);                             //int 21h
    _ah = 0x4c;                                 //mov ah, 4Ch
    _interrupt(33);                             //int 21h
    _STOP_("db 1, 2, 7, 0Ah, 0Bh, 0Fh, 10h, 2 dup(0), ...");
    _STOP_("db 12h, 1Ch, 1Dh, 0Ah, 0Bh, 1, 27h, 1, 2, ...");
    _STOP_("db 2Dh, 2Eh, 2Fh, 2 dup(0), 2 dup(7), 0FFh...");
    _STOP_("db 0, 3, 11h, 2 dup(0), 13h, 14h, 18h, 19h...");
    _STOP_("db 21h, 28h, 29h, 3, 4, 13h, 14h, 13h, 14h...");
    _STOP_("db 2 dup(8), 0FFh, 5, 6, 9, 0Dh, 0Eh, 5, 6...");
    _STOP_("db 16h, 1Ah, 1Bh, 5, 20h, 0Dh, 22h, 15h, 2...");
    _STOP_("db 16h, 2Bh, 16h, 32h, 16h, 2 dup(0), 2 du...");
    _STOP_("db 0Bh, 0Ah, 12h, 1Ch, 1Dh, 0Ah, 0Bh, 1, 2...");
    _STOP_("db 34h, 2Ch, 2Dh, 2Ch, 0, 17h, 12h, 33h, 3...");
    _STOP_("db 1Ch, 1Dh, 2Eh, 2Fh, 3Ah, 3Bh, 0FFh, 0Ch...");
    _STOP_("db 1Eh, 1Fh, 0Ch, 21h, 3, 4, 18h, 19h, 35h...");
    _STOP_("db 13h, 0, 18h, 19h, 35h, 36h, 8, 0Ch, 14h...");
    _STOP_("db 31h, 3Ch, 3Dh, 0FFh, 0Dh, 0Eh, 0Dh, 16h...");
    _STOP_("db 22h, 5, 6, 1Ah, 1Bh, 37h, 38h, 2Bh, 16h...");
    _STOP_("db 1Bh, 37h, 38h, 9, 0Dh, 16h, 5, 20h, 32h...");
    _STOP_("db 0FFh, 39h, 1Dh, 17h, 12h, 2Ch, 0, 2Ch, ...");
    _STOP_("db 12h, 1, 27h, 2 dup(0), 1, 27h, 17h, 12h...");
    _STOP_("db 27h, 7 dup(0), 0FFh, 18h, 19h, 18h, 19h...");
    _STOP_("db 3 dup(0), 0Ch, 14h, 28h, 29h, 2 dup(0),...");
    _STOP_("db 19h, 24h, 25h, 28h, 29h, 7 dup(0), 0FFh...");
    _STOP_("db 1Bh, 15h, 2Ah, 15h, 2Ah, 2 dup(0), 0Dh,...");
    _STOP_("db 1Ah, 0, 1Ah, 1Bh, 5, 26h, 15h, 2Ah, 7 d...");
    _STOP_("db 2Eh, 2Fh, 1, 27h, 2Ch, 0, 1, 27h, 0Ah, ...");
    _STOP_("db 2 dup(0), 2Ch, 0, 1, 27h, 2Ch, 2Dh, 1, ...");
    _STOP_("db 0FFh, 30h, 31h, 28h, 29h, 13h, 0, 28h, ...");
    _STOP_("db 35h, 36h, 2 dup(0), 13h, 0, 28h, 29h, 4...");
    _STOP_("db 29h, 13h, 8 dup(0), 0FFh, 32h, 16h, 15h...");
    _STOP_("db 15h, 2Ah, 0Dh, 0Eh, 37h, 38h, 2 dup(0),...");
    _STOP_("db 2Ah, 42h, 43h, 15h, 2Ah, 15h, 2Ah, 7 du...");
    _STOP_("db 0, 0Ah, 12h, 17h, 12h, 1, 12h, 7, 1Ch, ...");
    _STOP_("db 12h dup(0), 0FFh, 13h, 0, 0Ch, 14h, 18h...");
    _STOP_("db 8, 1Eh, 1Fh, 0Ch, 21h, 12h dup(0), 0FFh...");
    _STOP_("db 16h, 1Ah, 1Bh, 15h, 16h, 9, 5, 20h, 0Dh...");
    _STOP_("db 3Eh, 3Fh, 3Eh, 3Fh, 0Ch dup(0), 0FFh, 0...");
    _STOP_("db 20h, 48h, 59h, 44h, 45h, 20h, 50h, 41h,...");
    _STOP_("db 20h, 4Ch, 4Fh, 4Eh, 44h, 4Fh, 4Eh, 0FFh...");
    _STOP_("db 54h, 48h, 45h, 20h, 49h, 43h, 45h, 20h,...");
    _STOP_("db 45h, 52h, 4Eh, 53h, 20h, 4Fh, 46h, 20h,...");
    _STOP_("db 5Ah, 49h, 41h, 0FFh, 6, 0Ch, 3, 20h, 54...");
    _STOP_("db 20h, 46h, 4Fh, 52h, 45h, 53h, 54h, 53h,...");
    _STOP_("db 20h, 56h, 45h, 47h, 45h, 54h, 41h, 42h,...");
    _STOP_("db 0FFh, 6, 0Fh, 4, 20h, 54h, 48h, 45h, 20...");
    _STOP_("db 4Fh, 4Dh, 49h, 43h, 20h, 4Dh, 55h, 44h,...");
    _STOP_("db 4Eh, 45h, 53h, 0FFh, 6, 12h, 5, 20h, 54...");
    _STOP_("db 20h, 46h, 41h, 54h, 20h, 47h, 55h, 59h,...");
    _STOP_("db 48h, 45h, 41h, 44h, 51h, 55h, 41h, 52h,...");
    _STOP_("db 53h, 0FFh");                     //db 53h, 0FFh
    _STOP_("byte_199AD db 1");                  //byte_199AD db 1
    memory16(_ds, _bx + _di) += 1;              //inc word ptr [bx+di]
    _al = _al + memory(_ds, _bp + _di + 0);     //add al, [bp+di]
    _al += 0x05;                                //add al, 5
    _STOP_("goto word ptr [bp+si]");            //jmp word ptr [bp+si]
    _STOP_("db 0, 8Eh, 95h, 2 dup(0)");         //db 0, 8Eh, 95h, 2 dup(0)
    _STOP_("byte_199C3 db 0");                  //byte_199C3 db 0
    _STOP_("word_199C4 dw 0");                  //word_199C4 dw 0
}

void sub_199C8()
{
    WORD _cs = _seg001;

    memory(_ds, 0x95AD) = 0x01;                 //mov byte_199AD, 1
    off_10426();                                //call off_10426
    _ax = 0x0706;                               //mov ax, 706h
    memory16(_ds, 0x69F0) = _ax;                //mov word_16DF0, ax
    memory16(_ds, 0x69F2) = _ax;                //mov word_16DF2, ax
    sub_16E39();                                //call sub_16E39
    _ax = 0x0008;                               //mov ax, 8
    _si = 0x9461;                               //mov si, 9461h
    off_10446();                                //call off_10446
    _ax = 0x0108;                               //mov ax, 108h
    _si = 0x9481;                               //mov si, 9481h
    off_10446();                                //call off_10446
    _ax = 0x0208;                               //mov ax, 208h
    _si = 0x94a1;                               //mov si, 94A1h
    off_10446();                                //call off_10446
    _bx = 0x95b5;                               //mov bx, 95B5h
    sub_19C43();                                //call sub_19C43
    _push(_cs);                                 //push cs
    _ds = _pop();                               //pop ds
    if (memory16(_ds, 0x95C4) != 0x0001)        //jnz short loc_19A10
      goto loc_19A10;
    _bx = 0x95bf;                               //mov bx, 95BFh
    sub_19C43();                                //call sub_19C43
loc_19A10:                                      //loc_19A10:
    off_1041C();                                //call off_1041C
    _ax = 0x0008;                               //mov ax, 8
    _si = 0x9461;                               //mov si, 9461h
    off_10446();                                //call off_10446
    _ax = 0x0108;                               //mov ax, 108h
    _si = 0x9481;                               //mov si, 9481h
    off_10446();                                //call off_10446
    _ax = 0x0208;                               //mov ax, 208h
    _si = 0x94a1;                               //mov si, 94A1h
    off_10446();                                //call off_10446
    _bx = 0x95b5;                               //mov bx, 95B5h
    sub_19C43();                                //call sub_19C43
    if (memory16(_ds, 0x95C4) != 0x0001)        //jnz short loc_19A45
      goto loc_19A45;
    _bx = 0x95bf;                               //mov bx, 95BFh
    sub_19C43();                                //call sub_19C43
loc_19A45:                                      //loc_19A45:
    memory(_ds, 0x97DA) = 0x01;                 //mov byte_19BDA, 1
loc_19A4B:                                      //loc_19A4B:
    sub_19BDC();                                //call sub_19BDC
    if (!(_al & 0x10))                          //jz short loc_19A55
      goto loc_19A55;
    goto loc_19AE0;                             //jmp loc_19AE0
loc_19A55:                                      //loc_19A55:
    if (_al == memory(_ds, 0x95C3))             //jz short loc_19A4B
      goto loc_19A4B;
    memory(_ds, 0x95C3) = _al;                  //mov byte_199C3, al
    if (!(_al & 0x08))                          //jz short loc_19A9E
      goto loc_19A9E;
    _dx = memory16(_ds, 0x69F0);                //mov dx, word_16DF0
    _dh -= 1;                                   //dec dh
    _dh -= 1;                                   //dec dh
    _dh -= 1;                                   //dec dh
    if (memory16(_ds, 0x95C4) == 0x0001)        //jz short loc_19A84
      goto loc_19A84;
    if (_dh != 0x04)                            //jnz short loc_19A95
      goto loc_19A95;
    _dh = 0x10;                                 //mov dh, 10h
    memory(_ds, 0x95AD) = 0x04;                 //mov byte_199AD, 4
    sub_16E66();                                //call sub_16E66
    goto loc_19A4B;                             //jmp short loc_19A4B
loc_19A84:                                      //loc_19A84:
    if (_dh != 0x04)                            //jnz short loc_19A95
      goto loc_19A95;
    _dh = 0x13;                                 //mov dh, 13h
    memory(_ds, 0x95AD) = 0x05;                 //mov byte_199AD, 5
    sub_16E66();                                //call sub_16E66
    goto loc_19A4B;                             //jmp short loc_19A4B
loc_19A95:                                      //loc_19A95:
    memory(_ds, 0x95AD) -= 1;                   //dec byte_199AD
    sub_16E66();                                //call sub_16E66
    goto loc_19A4B;                             //jmp short loc_19A4B
loc_19A9E:                                      //loc_19A9E:
    if (!(_al & 0x04))                          //jz short loc_19A4B
      goto loc_19A4B;
    _dx = memory16(_ds, 0x69F0);                //mov dx, word_16DF0
    _dh += 1;                                   //inc dh
    _dh += 1;                                   //inc dh
    _dh += 1;                                   //inc dh
    if (memory16(_ds, 0x95C4) == 0x0001)        //jz short loc_19AC4
      goto loc_19AC4;
    if (_dh != 0x13)                            //jnz short loc_19AD6
      goto loc_19AD6;
    _dh = 0x07;                                 //mov dh, 7
    memory(_ds, 0x95AD) = 0x01;                 //mov byte_199AD, 1
    sub_16E66();                                //call sub_16E66
    goto loc_19A4B;                             //jmp short loc_19A4B
loc_19AC4:                                      //loc_19AC4:
    if (_dh != 0x16)                            //jnz short loc_19AD6
      goto loc_19AD6;
    _dh = 0x07;                                 //mov dh, 7
    memory(_ds, 0x95AD) = 0x01;                 //mov byte_199AD, 1
    sub_16E66();                                //call sub_16E66
    goto loc_19A4B;                             //jmp loc_19A4B
loc_19AD6:                                      //loc_19AD6:
    memory(_ds, 0x95AD) += 1;                   //inc byte_199AD
    sub_16E66();                                //call sub_16E66
    goto loc_19A4B;                             //jmp loc_19A4B
loc_19AE0:                                      //loc_19AE0:
    _al = memory(_ds, 0x95AD);                  //mov al, byte_199AD
    _cbw();                                     //cbw
    _ax -= 1;                                   //dec ax
    _si = 0x95af;                               //mov si, 95AFh
    _si += _ax;                                 //add si, ax
    _al = memory(_ds, _si);                     //mov al, [si]
    _cbw();                                     //cbw
    memory16(_ds, 0x8BEC) = _ax;                //mov word_18FEC, ax
    memory16(_ds, 0x8BEE) = _ax;                //mov word_18FEE, ax
}

void sub_19AF6()
{
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, 0x96F4);                //mov ax, word_19AF4
loc_19AFB:                                      //loc_19AFB:
    _push(_ax);                                 //push ax
    _push(_es);                                 //push es
    _dx = 0x0040;                               //mov dx, 40h
    _es = _dx;                                  //mov es, dx
    _dx = memoryBiosGet16(_es, 0x63);           //mov dx, es:63h
    _es = _pop();                               //pop es
    _dl += 0x06;                                //add dl, 6
loc_19B0B:                                      //loc_19B0B:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x08;                                //and al, 8
    if (_al != 0)                               //jnz short loc_19B0B
      goto loc_19B0B;
loc_19B10:                                      //loc_19B10:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x08;                                //and al, 8
    if (_al == 0)                               //jz short loc_19B10
      goto loc_19B10;
    _ax = _pop();                               //pop ax
    _ax -= 1;                                   //dec ax
    if (_ax != 0)                               //jnz short loc_19AFB
      goto loc_19AFB;
    _ax = _pop();                               //pop ax
    _dx = _pop();                               //pop dx
}

void sub_19B1C()
{
    _push(_dx);                                 //push dx
    _push(_ax);                                 //push ax
    _push(_ax);                                 //push ax
    _push(_es);                                 //push es
    _dx = 0x0040;                               //mov dx, 40h
    _es = _dx;                                  //mov es, dx
    _dx = memoryBiosGet16(_es, 0x63);           //mov dx, es:63h
    _es = _pop();                               //pop es
    _dl += 0x06;                                //add dl, 6
loc_19B2E:                                      //loc_19B2E:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x08;                                //and al, 8
    if (_al != 0)                               //jnz short loc_19B2E
      goto loc_19B2E;
loc_19B33:                                      //loc_19B33:
    _in(_al, _dx);                              //in al, dx
    _al &= 0x08;                                //and al, 8
    if (_al == 0)                               //jz short loc_19B33
      goto loc_19B33;
    _ax = _pop();                               //pop ax
    _ax = _pop();                               //pop ax
    _dx = _pop();                               //pop dx
}

void sub_19B40()
{
    _push(_ax);                                 //push ax
    _push(_dx);                                 //push dx
    _ax = memory16(_ds, 0x973C);                //mov ax, word_19B3C
    _dx = memory16(_ds, 0x973E);                //mov dx, word_19B3E
    _xchg(_ax, _dx);                            //xchg ax, dx
    _rol(_dx, 1);                               //rol dx, 1
    _rol(_dx, 1);                               //rol dx, 1
    _rol(_dx, 1);                               //rol dx, 1
    _dx -= 0x0007;                              //sub dx, 7
    _dx = _dx ^ _ax;                            //xor dx, ax
    memory16(_ds, 0x973C) = _ax;                //mov word_19B3C, ax
    memory16(_ds, 0x973E) = _dx;                //mov word_19B3E, dx
    _dx = _pop();                               //pop dx
    _ax = _pop();                               //pop ax
}

void sub_19BAC()
{
    _al = 0x11;                                 //mov al, 11h
    if (memory(_ds, 0x97AB) == 0x01)            //jz short loc_19BCE
      goto loc_19BCE;
    if (memory(_ds, 0xB888) == _al)             //jz short loc_19BBC
      goto loc_19BBC;
    return;                                     //retn
loc_19BBC:                                      //loc_19BBC:
    if (memory(_ds, 0xB888) == _al)             //jz short loc_19BBC
      goto loc_19BBC;
loc_19BC2:                                      //loc_19BC2:
    if (memory(_ds, 0xB888) != _al)             //jnz short loc_19BC2
      goto loc_19BC2;
    memory(_ds, 0x97AB) = 0x01;                 //mov byte_19BAB, 1
    return;                                     //retn
loc_19BCE:                                      //loc_19BCE:
    if (_al == memory(_ds, 0xB888))             //jz short locret_19BD9
      goto locret_19BD9;
    memory(_ds, 0x97AB) = 0x00;                 //mov byte_19BAB, 0
locret_19BD9:                                   //locret_19BD9:
    return;
}

void sub_19BDC()
{
    sub_1C4CA();                                //call sub_1C4CA
    if (!(_al & 0x10))                          //jz short loc_19BF0
      goto loc_19BF0;
    if (memory(_ds, 0x97DA) == 0x01)            //jz short loc_19BF5
      goto loc_19BF5;
    memory(_ds, 0x97DA) = 0x01;                 //mov byte_19BDA, 1
    return;                                     //retn
loc_19BF0:                                      //loc_19BF0:
    memory(_ds, 0x97DA) = 0x00;                 //mov byte_19BDA, 0
loc_19BF5:                                      //loc_19BF5:
    _al &= 0xef;                                //and al, 0EFh
}

void sub_19C05()
{
    _pushf();                                   //pushf
    _push(_si);                                 //push si
    _push(_ax);                                 //push ax
    if (memory(_ds, 0x9804) == 0x01)            //jz short loc_19C3F
      goto loc_19C3F;
    _si = memory16(_ds, 0x97F8);                //mov si, word_19BF8
    _al = memory(_ds, 0xB888);                  //mov al, byte_1BC88
    if (_al & 0x80)                             //jnz short loc_19C39
      goto loc_19C39;
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz short loc_19C39
      goto loc_19C39;
    _ah = memory(_ds, _si);                     //mov ah, [si]
    if (_al != _ah)                             //jnz short loc_19C33
      goto loc_19C33;
    _si += 1;                                   //inc si
    memory16(_ds, 0x97F8) = _si;                //mov word_19BF8, si
    if (memory(_ds, _si) != 0xff)               //jnz short loc_19C39
      goto loc_19C39;
    memory(_ds, 0x9804) = 0x01;                 //mov byte_19C04, 1
loc_19C33:                                      //loc_19C33:
    memory16(_ds, 0x97F8) = 0x97fa;             //mov word_19BF8, 97FAh
loc_19C39:                                      //loc_19C39:
    memory(_ds, 0xB888) = 0x00;                 //mov byte_1BC88, 0
loc_19C3F:                                      //loc_19C3F:
    _ax = _pop();                               //pop ax
    _si = _pop();                               //pop si
    _popf();                                    //popf
}

void sub_19C43()
{
loc_19C43:
    _si = memory16(_ds, _bx);                   //mov si, [bx]
    _si |= _si;                                 //or si, si
    if (_si == 0)                               //jz short locret_19C59
      goto locret_19C59;
    _al = memory(_ds, _si);                     //mov al, [si]
    _si += 1;                                   //inc si
    _ah = memory(_ds, _si);                     //mov ah, [si]
    _si += 1;                                   //inc si
    _push(_bx);                                 //push bx
    off_1040C();                                //call off_1040C
    _bx = _pop();                               //pop bx
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    goto loc_19C43;                             //jmp short sub_19C43
locret_19C59:                                   //locret_19C59:
    return;
}

void sub_19E18()
{
    WORD _cs = _seg001;

    memory16(_ds, 0x9A16) = 0x0000;             //mov word_19E16, 0
    off_10426();                                //call off_10426
loc_19E22:                                      //loc_19E22:
    sub_19EBB();                                //call sub_19EBB
    _bx = 0x99b3;                               //mov bx, 99B3h
    sub_19C43();                                //call sub_19C43
    off_1041C();                                //call off_1041C
    _bx = 0x99b3;                               //mov bx, 99B3h
    sub_19C43();                                //call sub_19C43
    off_1041C();                                //call off_1041C
    memory(_ds, 0xB888) = 0x00;                 //mov byte_1BC88, 0
    _ax = memory16(_ds, 0x9A16);                //mov ax, word_19E16
    _ax <<= 1;                                  //shl ax, 1
    _di = 0x9a0c;                               //mov di, 9A0Ch
    _di += _ax;                                 //add di, ax
    _di = memory16(_ds, _di);                   //mov di, [di]
loc_19E4B:                                      //loc_19E4B:
    sub_1BF7C();                                //call sub_1BF7C
    _bx &= 0x0003;                              //and bx, 3
    if (_bx != 0)                               //jnz short loc_19E6A
      goto loc_19E6A;
    _ah = memory(_ds, 0xB888);                  //mov ah, byte_1BC88
    _flags.sign = !!(_ah & 0x80);               //or ah, ah
    _ah |= _ah;
    if (_flags.sign)                            //js short loc_19E4B
      goto loc_19E4B;
    if (_ah == 0)                               //jz short loc_19E4B
      goto loc_19E4B;
    if (_ah != 0x01)                            //jnz short loc_19E6C
      goto loc_19E6C;
    memory(_cs, 0xBDA2) = 0xc3;                 //mov byte ptr cs:loc_1C1A2, 0C3h
    _flags.carry = false;                       //clc
    return;                                     //retn
loc_19E6A:                                      //loc_19E6A:
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_19E6C:                                      //loc_19E6C:
    if (_ah != 0x1c)                            //jnz short loc_19E7D
      goto loc_19E7D;
    sub_19ED0();                                //call sub_19ED0
    _si = 0x9a06;                               //mov si, 9A06h
    sub_19EB5();                                //call sub_19EB5
    goto loc_19E9B;                             //jmp short loc_19E9B
    _STOP_("db 90h");                           //db 90h
loc_19E7D:                                      //loc_19E7D:
    _si = 0x99e5;                               //mov si, 99E5h
loc_19E80:                                      //loc_19E80:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    if (_al == 0xff)                            //jz short loc_19EB2
      goto loc_19EB2;
    if (_al != _ah)                             //jnz short loc_19E80
      goto loc_19E80;
    sub_19ED0();                                //call sub_19ED0
    _si -= 1;                                   //dec si
    _si -= 0x001a;                              //sub si, 1Ah
    _al = memory(_ds, _si);                     //mov al, [si]
    memory(_ds, 0x9A00) = _al;                  //mov byte_19E00, al
    _si = 0x9a00;                               //mov si, 9A00h
    sub_19EB5();                                //call sub_19EB5
loc_19E9B:                                      //loc_19E9B:
    memory16(_ds, 0x9A16) += 1;                 //inc word_19E16
    if (memory16(_ds, 0x9A16) != 0x0005)        //jnz short loc_19EAF
      goto loc_19EAF;
    memory16(_ds, 0x9A16) = 0x0000;             //mov word_19E16, 0
    goto loc_19E22;                             //jmp loc_19E22
loc_19EAF:                                      //loc_19EAF:
    goto loc_19E22;                             //jmp loc_19E22
loc_19EB2:                                      //loc_19EB2:
    goto loc_19E22;                             //jmp loc_19E22
}

void sub_19EB5()
{
    _cx = 0x0006;                               //mov cx, 6
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
}

void sub_19EBB()
{
    _ax = memory16(_ds, 0x9A16);                //mov ax, word_19E16
    _ax <<= 1;                                  //shl ax, 1
    _si = 0x99a9;                               //mov si, 99A9h
    _si += _ax;                                 //add si, ax
    _si = memory16(_ds, _si);                   //mov si, [si]
    _di = 0x9958;                               //mov di, 9958h
    _cx = 0x0005;                               //mov cx, 5
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
}

void sub_19ED0()
{
    _bx = 0xb874;                               //mov bx, 0B874h
    _cx = memory16(_ds, 0x9A16);                //mov cx, word_19E16
    _bx += _cx;                                 //add bx, cx
    memory(_ds, _bx) = _ah;                     //mov [bx], ah
}

void sub_19EE5()
{
    off_1043A();                                //call off_1043A
    off_10426();                                //call off_10426
    sub_16B3B();                                //call sub_16B3B
    _ax = 0x0c0f;                               //mov ax, 0C0Fh
    _si = 0x9adc;                               //mov si, 9ADCh
    off_1040C();                                //call off_1040C
    off_1041C();                                //call off_1041C
    _cx = 0x01e0;                               //mov cx, 1E0h
loc_19F01:                                      //loc_19F01:
    _push(_cx);                                 //push cx
    sub_19B1C();                                //call sub_19B1C
    sub_19BDC();                                //call sub_19BDC
    if (_al & 0x10)                             //jnz short loc_19F10
      goto loc_19F10;
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_19F01
      goto loc_19F01;
    return;                                     //retn
loc_19F10:                                      //loc_19F10:
    _cx = _pop();                               //pop cx
}

void loc_19F12()
{
    off_1043A();                                //call off_1043A
    _ax = 0x0004;                               //mov ax, 4
    memory16(_ds, 0xBDF2) = _ax;                //mov word_1C1F2, ax
    sub_1AECD();                                //call sub_1AECD
    _ax = 0x0002;                               //mov ax, 2
    memory16(_ds, 0xBDF2) = _ax;                //mov word_1C1F2, ax
    sub_1AECD();                                //call sub_1AECD
    sub_19EE5();                                //call sub_19EE5
    sub_16D69();                                //call sub_16D69
    sub_1A5E3();                                //call sub_1A5E3
    sub_16CD7();                                //call sub_16CD7
    _STOP_("goto loc_1C359");                   //jmp loc_1C359
loc_19F37:                                      //loc_19F37:
    off_1043A();                                //call off_1043A
    _ax = 0x0004;                               //mov ax, 4
    memory16(_ds, 0xBDF2) = _ax;                //mov word_1C1F2, ax
    sub_1AECD();                                //call sub_1AECD
    _ax = 0x0006;                               //mov ax, 6
    memory16(_ds, 0xBDF2) = _ax;                //mov word_1C1F2, ax
    sub_1AECD();                                //call sub_1AECD
    _ax = 0x0002;                               //mov ax, 2
    sub_1A257();                                //call sub_1A257
    sub_16D69();                                //call sub_16D69
    sub_1A5E3();                                //call sub_1A5E3
    sub_16CD7();                                //call sub_16CD7
    _STOP_("goto loc_1C359");                   //jmp loc_1C359
    _STOP_("db 44h, 4Fh, 20h, 59h, 4Fh, 55h, 20h, 57h,...");
    _STOP_("db 20h, 54h, 4Fh, 20h, 51h, 55h, 49h, 54h,...");
    _STOP_("db 49h, 53h, 20h, 47h, 41h, 4Dh, 45h, 0FFh...");
    _STOP_("db 2 dup(53h), 20h, 59h, 20h, 4Fh, 52h, 20...");
}

void sub_19F8A()
{
    WORD _cs = _seg001;

    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = 0x0c05;                               //mov ax, 0C05h
    _si = 0x9b5f;                               //mov si, 9B5Fh
    off_1040E();                                //call off_1040E
    _ax = 0x0d0e;                               //mov ax, 0D0Eh
    _si = 0x9b7d;                               //mov si, 9B7Dh
    off_1040E();                                //call off_1040E
    off_10438();                                //call off_10438
loc_19FA4:                                      //loc_19FA4:
    _al = memory(_cs, 0xB888);                  //mov al, cs:byte_1BC88
    if (_al != 0x15)                            //jnz short loc_19FB0
      goto loc_19FB0;
    _flags.carry = true;                        //stc
    goto loc_19FB5;                             //jmp short loc_19FB5
loc_19FB0:                                      //loc_19FB0:
    if (_al != 0x31)                            //jnz short loc_19FA4
      goto loc_19FA4;
    _flags.carry = false;                       //clc
loc_19FB5:                                      //loc_19FB5:
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_1A102()
{
    _di = 0x9ca8;                               //mov di, 9CA8h
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _di = memory16(_ds, _di);                   //mov di, [di]
}

void sub_1A111()
{
    _di = 0x9cfa;                               //mov di, 9CFAh
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _di = memory16(_ds, _di);                   //mov di, [di]
}

void sub_1A121()
{
    sub_1A102();                                //call sub_1A102
    memory16(_ds, _di) = 0x0001;                //mov word ptr [di], 1
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    memory16(_ds, _di + 2) = _ax;               //mov [di+2], ax
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    memory16(_ds, _di + 4) = _ax;               //mov [di+4], ax
}

void sub_1A137()
{
    sub_1A102();                                //call sub_1A102
    memory16(_ds, _di) = 0x0000;                //mov word ptr [di], 0
}

void sub_1A13F()
{
    sub_1A102();                                //call sub_1A102
    memory16(_ds, _di) = 0x0002;                //mov word ptr [di], 2
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    memory16(_ds, _di + 18) = _ax;              //mov [di+12h], ax
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    memory16(_ds, _di + 20) = _ax;              //mov [di+14h], ax
}

void sub_1A155()
{
    sub_1A102();                                //call sub_1A102
    _ax = memory16(_ds, _bx);                   //mov ax, [bx]
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _ax += 0x2314;                              //add ax, 2314h
    memory16(_ds, _di + 22) = _ax;              //mov [di+16h], ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, _di + 24) = _ax;              //mov [di+18h], ax
}

void sub_1A168()
{
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    _STOP_("sp-trace-fail");                    //sub_1A168 endp_failed
    _STOP_("continues");                        //sub_1A16B proc near
}

void sub_1A16B()
{
    _al |= _al;                                 //or al, al
    if (_al != 0)                               //jnz short loc_1A174
      goto loc_1A174;
    _indirectCall(_ds, memory16(_ds, 0x30));    //call word ptr ds:30h
    return;                                     //retn
loc_1A174:                                      //loc_1A174:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _ax -= 1;                                   //dec ax
    _ax <<= 1;                                  //shl ax, 1
    _si = 0x2314;                               //mov si, 2314h
    _si = memory16(_ds, _si);                   //mov si, [si]
    _si += 0x2314;                              //add si, 2314h
    _si += _ax;                                 //add si, ax
    _si = memory16(_ds, _si);                   //mov si, [si]
    _si += 0x2314;                              //add si, 2314h
    _si += 0x0008;                              //add si, 8
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    _ah = memory(_ds, _bx);                     //mov ah, [bx]
    _bx += 1;                                   //inc bx
    _indirectCall(_ds, memory16(_ds, 0x2C));    //call word ptr ds:2Ch
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    _si += _ax;                                 //add si, ax
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    _cl = 0x05;                                 //mov cl, 5
    _ax <<= _cl;                                //shl ax, cl
    _si += _ax;                                 //add si, ax
    _cl = memory(_ds, _bx);                     //mov cl, [bx]
    _bx += 1;                                   //inc bx
    _ch = memory(_ds, _bx);                     //mov ch, [bx]
    _bx += 1;                                   //inc bx
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _indirectCall(_ds, memory16(_ds, 0x2E));    //call word ptr ds:2Eh
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_1A1BC()
{
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    _ah = memory(_ds, _bx);                     //mov ah, [bx]
    _bx += 1;                                   //inc bx
    _si = _bx;                                  //mov si, bx
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_si);                                 //push si
    _indirectCall(_ds, memory16(_ds, 0x32));    //call word ptr ds:32h
    _si = _pop();                               //pop si
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
loc_1A1CE:                                      //loc_1A1CE:
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    if (_al != 0xff)                            //jnz short loc_1A1CE
      goto loc_1A1CE;
}

void sub_1A1D7()
{
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _cbw();                                     //cbw
    _bx += 1;                                   //inc bx
    _push(_bx);                                 //push bx
    memory16(_ds, 0xBDF2) = _ax;                //mov ds:0BDF2h, ax
    sub_1AECD();                                //call sub_1AECD
    _bx = _pop();                               //pop bx
}

void sub_1A1E4()
{
    _bx += 1;                                   //inc bx
}

void sub_1A1E6()
{
    sub_1A102();                                //call sub_1A102
    memory16(_ds, _di) = 0x0003;                //mov word ptr [di], 3
    _ax = memory16(_ds, _bx);                   //mov ax, [bx]
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _ax += 0x2314;                              //add ax, 2314h
    memory16(_ds, _di + 6) = _ax;               //mov [di+6], ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, _di + 8) = _ax;               //mov [di+8], ax
}

void sub_1A1FD()
{
    sub_1A111();                                //call sub_1A111
    memory16(_ds, _di) = 0x0001;                //mov word ptr [di], 1
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    memory16(_ds, _di + 2) = _ax;               //mov [di+2], ax
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    memory16(_ds, _di + 4) = _ax;               //mov [di+4], ax
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    memory16(_ds, _di + 6) = _ax;               //mov [di+6], ax
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    memory16(_ds, _di + 8) = _ax;               //mov [di+8], ax
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    memory16(_ds, _di + 10) = _ax;              //mov [di+0Ah], ax
    memory16(_ds, _di + 12) = 0x0000;           //mov word ptr [di+0Ch], 0
    _ax = memory16(_ds, _bx);                   //mov ax, [bx]
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _ax += 0x2314;                              //add ax, 2314h
    memory16(_ds, _di + 14) = _ax;              //mov [di+0Eh], ax
}

void sub_1A234()
{
    sub_1A111();                                //call sub_1A111
    memory16(_ds, _di) = 0x0000;                //mov word ptr [di], 0
}

void sub_1A23E()
{
    _ax = memory16(_ds, _bx);                   //mov ax, [bx]
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _ax += 0x2314;                              //add ax, 2314h
    memory16(_ds, 0x9E3C) = _bx;                //mov ds:9E3Ch, bx
    _bx = _ax;                                  //mov bx, ax
}

void sub_1A24C()
{
    _bx = memory16(_ds, 0x9E3C);                //mov bx, ds:9E3Ch
}

void sub_1A257()
{
    memory16(_ds, 0x9E51) = _sp;                //mov ds:9E51h, sp
    memory16(_ds, 0x8BF0) = 0x0000;             //mov word ptr ds:8BF0h, 0
    memory16(_ds, 0x9E55) = _ax;                //mov ds:9E55h, ax
    memory16(_ds, 0x9E53) = 0x0000;             //mov word ptr ds:9E53h, 0
    sub_1C4CA();                                //call sub_1C4CA
    if (!(_al & 0x10))                          //jz short loc_1A277
      goto loc_1A277;
    memory16(_ds, 0x9E53) = 0x0001;             //mov word ptr ds:9E53h, 1
loc_1A277:                                      //loc_1A277:
    sub_16B3B();                                //call sub_16B3B
    _indirectCall(_ds, memory16(_ds, 0x1C));    //call word ptr ds:1Ch
    sub_16B3B();                                //call sub_16B3B
    _ax = memory16(_ds, 0x9E55);                //mov ax, ds:9E55h
    _ax <<= 1;                                  //shl ax, 1
    _bx = 0x2316;                               //mov bx, 2316h
    _bx += _ax;                                 //add bx, ax
    _bx = memory16(_ds, _bx);                   //mov bx, [bx]
    _bx += 0x2314;                              //add bx, 2314h
    _di = 0x9bd6;                               //mov di, 9BD6h
    _cx = 0x0008;                               //mov cx, 8
loc_1A297:                                      //loc_1A297:
    memory16(_ds, _di) = 0x0000;                //mov word ptr [di], 0
    _di += 0x001a;                              //add di, 1Ah
    if (--_cx)                                  //loop loc_1A297
      goto loc_1A297;
    _di = 0x9cb8;                               //mov di, 9CB8h
    _cx = 0x0004;                               //mov cx, 4
loc_1A2A6:                                      //loc_1A2A6:
    memory16(_ds, _di) = 0x0000;                //mov word ptr [di], 0
    _di += 0x0010;                              //add di, 10h
    if (--_cx)                                  //loop loc_1A2A6
      goto loc_1A2A6;
loc_1A2AF:                                      //loc_1A2AF:
    _ax = _ax ^ _ax;                            //xor ax, ax
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _bx += 1;                                   //inc bx
    if (_al == 0x00)                            //jz short locret_1A2C3
      goto locret_1A2C3;
    _ax <<= 1;                                  //shl ax, 1
    _si = 0x9bb8;                               //mov si, 9BB8h
    _si += _ax;                                 //add si, ax
    _STOP_("call word ptr [si]");               //call word ptr [si]
    goto loc_1A2AF;                             //jmp short loc_1A2AF
locret_1A2C3:                                   //locret_1A2C3:
    return;
}

void sub_1A2C4()
{
    _push(_bx);                                 //push bx
    sub_1C4CA();                                //call sub_1C4CA
    _bx = _pop();                               //pop bx
    _dx = memory16(_ds, 0x9E55);                //mov dx, ds:9E55h
    if (_dx != 0x0000)                          //jnz short loc_1A2D3
      goto loc_1A2D3;
    return;                                     //retn
loc_1A2D3:                                      //loc_1A2D3:
    if (_dx != 0x0001)                          //jnz short loc_1A2F1
      goto loc_1A2F1;
    if (!(_al & 0x10))                          //jz short loc_1A2E8
      goto loc_1A2E8;
    if (memory16(_ds, 0x9E53) == 0x0001)        //jz short loc_1A2EE
      goto loc_1A2EE;
    _sp = memory16(_ds, 0x9E51);                //mov sp, ds:9E51h
    return;                                     //retn
loc_1A2E8:                                      //loc_1A2E8:
    memory16(_ds, 0x9E53) = 0x0000;             //mov word ptr ds:9E53h, 0
loc_1A2EE:                                      //loc_1A2EE:
    _al &= 0xef;                                //and al, 0EFh
    return;                                     //retn
loc_1A2F1:                                      //loc_1A2F1:
    _al &= 0xef;                                //and al, 0EFh
}

void sub_1A2F6()
{
    sub_16B3B();                                //call sub_16B3B
    memory16(_ds, 0x9EF4) = 0x0000;             //mov word ptr ds:9EF4h, 0
    _cx = _cx ^ _cx;                            //xor cx, cx
    _cl = memory(_ds, _bx);                     //mov cl, [bx]
    _bx += 1;                                   //inc bx
loc_1A304:                                      //loc_1A304:
    _push(_cx);                                 //push cx
    memory16(_ds, 0x9EF4) += 1;                 //inc word ptr ds:9EF4h
    if (memory16(_ds, 0x9EF4) != 0x0007)        //jnz short loc_1A316
      goto loc_1A316;
    memory16(_ds, 0x9EF4) = 0x0000;             //mov word ptr ds:9EF4h, 0
loc_1A316:                                      //loc_1A316:
    sub_1A389();                                //call sub_1A389
    sub_1A437();                                //call sub_1A437
    sub_1A2C4();                                //call sub_1A2C4
    if (!(_al & 0x10))                          //jz short loc_1A32A
      goto loc_1A32A;
    if (memory16(_ds, 0x9EF4) != 0x0000)        //jnz short loc_1A33D
      goto loc_1A33D;
loc_1A32A:                                      //loc_1A32A:
    _indirectCall(_ds, memory16(_ds, 0x34));    //call word ptr ds:34h
    _indirectCall(_ds, memory16(_ds, 0x44));    //call word ptr ds:44h
    sub_19B1C();                                //call sub_19B1C
    _indirectCall(_ds, memory16(_ds, 0x1C));    //call word ptr ds:1Ch
    _indirectCall(_ds, memory16(_ds, 0x38));    //call word ptr ds:38h
loc_1A33D:                                      //loc_1A33D:
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_1A304
      goto loc_1A304;
}

void sub_1A341()
{
    _si = 0x9cb8;                               //mov si, 9CB8h
loc_1A344:                                      //loc_1A344:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (_flags.sign)                            //js short locret_1A358
      goto locret_1A358;
    if (_ax == 0)                               //jz short loc_1A353
      goto loc_1A353;
    _push(_si);                                 //push si
    _push(_bx);                                 //push bx
    sub_1A359();                                //call sub_1A359
    _bx = _pop();                               //pop bx
    _si = _pop();                               //pop si
loc_1A353:                                      //loc_1A353:
    _si += 0x0010;                              //add si, 10h
    goto loc_1A344;                             //jmp short loc_1A344
locret_1A358:                                   //locret_1A358:
    return;
}

void sub_1A359()
{
    _al = memory(_ds, _si + 2);                 //mov al, [si+2]
    _ah = memory(_ds, _si + 4);                 //mov ah, [si+4]
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_si);                                 //push si
    _si = memory16(_ds, _si + 14);              //mov si, [si+0Eh]
    _indirectCall(_ds, memory16(_ds, 0x32));    //call word ptr ds:32h
    _si = _pop();                               //pop si
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    memory16(_ds, _si + 12) += 1;               //inc word ptr [si+0Ch]
    _ax = memory16(_ds, _si + 10);              //mov ax, [si+0Ah]
    if (_ax != memory16(_ds, _si + 12))         //jnz short locret_1A388
      goto locret_1A388;
    _ax = memory16(_ds, _si + 6);               //mov ax, [si+6]
    memory16(_ds, _si + 2) += _ax;              //add [si+2], ax
    _ax = memory16(_ds, _si + 8);               //mov ax, [si+8]
    memory16(_ds, _si + 4) += _ax;              //add [si+4], ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, _si + 12) = _ax;              //mov [si+0Ch], ax
locret_1A388:                                   //locret_1A388:
    return;
}

void sub_1A389()
{
    _si = 0x9bd6;                               //mov si, 9BD6h
loc_1A38C:                                      //loc_1A38C:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (_flags.sign)                            //js short locret_1A3CE
      goto locret_1A3CE;
    if (_ax == 0)                               //jz short loc_1A3C9
      goto loc_1A3C9;
    if (_ax == 0x0001)                          //jz short loc_1A3C9
      goto loc_1A3C9;
    if (_ax != 0x0002)                          //jnz short loc_1A3C2
      goto loc_1A3C2;
    _ax = memory16(_ds, _si + 18);              //mov ax, [si+12h]
    memory16(_ds, _si + 2) += _ax;              //add [si+2], ax
    if ((short)memory16(_ds, _si + 2) < (short)0x00e8)
      goto loc_1A3AF;
    memory16(_ds, _si) = 0x0000;                //mov word ptr [si], 0
loc_1A3AF:                                      //loc_1A3AF:
    if ((short)memory16(_ds, _si + 2) >= (short)0x0000)
      goto loc_1A3B9;
    memory16(_ds, _si) = 0x0000;                //mov word ptr [si], 0
loc_1A3B9:                                      //loc_1A3B9:
    _ax = memory16(_ds, _si + 20);              //mov ax, [si+14h]
    memory16(_ds, _si + 4) += _ax;              //add [si+4], ax
    goto loc_1A3C9;                             //jmp short loc_1A3C9
    _STOP_("db  90h");                          //db  90h
loc_1A3C2:                                      //loc_1A3C2:
    _push(_bx);                                 //push bx
    _push(_si);                                 //push si
    sub_1A3CF();                                //call sub_1A3CF
    _si = _pop();                               //pop si
    _bx = _pop();                               //pop bx
loc_1A3C9:                                      //loc_1A3C9:
    _si += 0x001a;                              //add si, 1Ah
    goto loc_1A38C;                             //jmp short loc_1A38C
locret_1A3CE:                                   //locret_1A3CE:
    return;
}

void sub_1A3CF()
{
    _push(_bx);                                 //push bx
    _bx = memory16(_ds, _si + 6);               //mov bx, [si+6]
    _al = memory(_ds, _bx);                     //mov al, [bx]
    if (_al != 0x00)                            //jnz short loc_1A3DF
      goto loc_1A3DF;
    _bx += 1;                                   //inc bx
    _bx = memory16(_ds, _bx);                   //mov bx, [bx]
    memory16(_ds, _si + 6) = _bx;               //mov [si+6], bx
loc_1A3DF:                                      //loc_1A3DF:
    _bx += 1;                                   //inc bx
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _sar(_al, 1);                               //sar al, 1
    _sar(_al, 1);                               //sar al, 1
    _sar(_al, 1);                               //sar al, 1
    _sar(_al, 1);                               //sar al, 1
    if (_al != 0x07)                            //jnz short loc_1A3F0
      goto loc_1A3F0;
    _al += 1;                                   //inc al
loc_1A3F0:                                      //loc_1A3F0:
    _cbw();                                     //cbw
    memory16(_ds, _si + 2) += _ax;              //add [si+2], ax
    if ((short)memory16(_ds, _si + 2) < (short)0x00e8)
      goto loc_1A3FF;
    memory16(_ds, _si) = 0x0000;                //mov word ptr [si], 0
loc_1A3FF:                                      //loc_1A3FF:
    if ((short)memory16(_ds, _si + 2) >= (short)0x0000)
      goto loc_1A409;
    memory16(_ds, _si) = 0x0000;                //mov word ptr [si], 0
loc_1A409:                                      //loc_1A409:
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _al &= 0x0f;                                //and al, 0Fh
    if (!(_al & 0x08))                          //jz short loc_1A413
      goto loc_1A413;
    _al |= 0xf0;                                //or al, 0F0h
loc_1A413:                                      //loc_1A413:
    if (_al != 0x07)                            //jnz short loc_1A419
      goto loc_1A419;
    _al += 1;                                   //inc al
loc_1A419:                                      //loc_1A419:
    _cbw();                                     //cbw
    memory16(_ds, _si + 4) += _ax;              //add [si+4], ax
    _bx -= 1;                                   //dec bx
    _al = memory(_ds, _bx);                     //mov al, [bx]
    _cbw();                                     //cbw
    memory16(_ds, _si + 8) += 1;                //inc word ptr [si+8]
    if (_ax == memory16(_ds, _si + 8))          //jz short loc_1A42B
      goto loc_1A42B;
    if (_ax >= memory16(_ds, _si + 8))          //jnb short loc_1A435
      goto loc_1A435;
loc_1A42B:                                      //loc_1A42B:
    memory16(_ds, _si + 8) = 0x0000;            //mov word ptr [si+8], 0
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    memory16(_ds, _si + 6) = _bx;               //mov [si+6], bx
loc_1A435:                                      //loc_1A435:
    _bx = _pop();                               //pop bx
}

void sub_1A437()
{
    _si = 0x9bd6;                               //mov si, 9BD6h
loc_1A43A:                                      //loc_1A43A:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (_flags.sign)                            //js short locret_1A44E
      goto locret_1A44E;
    if (_ax == 0)                               //jz short loc_1A449
      goto loc_1A449;
    _push(_bx);                                 //push bx
    _push(_si);                                 //push si
    sub_1718E();                                //call sub_1718E
    _si = _pop();                               //pop si
    _bx = _pop();                               //pop bx
loc_1A449:                                      //loc_1A449:
    _si += 0x001a;                              //add si, 1Ah
    goto loc_1A43A;                             //jmp short loc_1A43A
locret_1A44E:                                   //locret_1A44E:
    return;
}

void sub_1A44F()
{
    _ax = memory16(_ds, 0x62);                  //mov ax, ds:62h
    _cx = 0x0000;                               //mov cx, 0
    _dx = 0x00c1;                               //mov dx, 0C1h
    sub_1A65B();                                //call sub_1A65B
}

void sub_1A45C()
{
    _ax = _seg001;                              //mov ax, seg seg001
    _cx = 0x3374;                               //mov cx, 3374h
    _dx = 0x006b;                               //mov dx, 6Bh
    sub_1A65B();                                //call sub_1A65B
    _ax = _seg001;                              //mov ax, seg seg001
    _cx = 0x3974;                               //mov cx, 3974h
    _dx = 0x0077;                               //mov dx, 77h
    sub_1A65B();                                //call sub_1A65B
    _ax = _seg001;                              //mov ax, seg seg001
    _cx = 0x3c74;                               //mov cx, 3C74h
    _dx = 0x0084;                               //mov dx, 84h
    sub_1A65B();                                //call sub_1A65B
    _ax = _seg001;                              //mov ax, seg seg001
    _cx = 0x4c74;                               //mov cx, 4C74h
    _dx = 0x0091;                               //mov dx, 91h
    sub_1A65B();                                //call sub_1A65B
    _ax = _seg001;                              //mov ax, seg seg001
    _cx = 0x53f4;                               //mov cx, 53F4h
    _dx = 0x009d;                               //mov dx, 9Dh
    sub_1A65B();                                //call sub_1A65B
    _ax = _seg001;                              //mov ax, seg seg001
    _cx = 0x1180;                               //mov cx, 1180h
    _dx = 0x00aa;                               //mov dx, 0AAh
    sub_1A65B();                                //call sub_1A65B
    _ax = _seg001;                              //mov ax, seg seg001
    _cx = 0x2314;                               //mov cx, 2314h
    _dx = 0x00b6;                               //mov dx, 0B6h
    sub_1A65B();                                //call sub_1A65B
}

void sub_1A54A()
{
    _si = 0x006b;                               //mov si, 6Bh
    _ax = memory16(_ds, 0x8BEC);                //mov ax, ds:8BECh
    _ax -= 1;                                   //dec ax
    _ax += 0x0031;                              //add ax, 31h
loc_1A554:                                      //loc_1A554:
    _ah = memory(_ds, _si);                     //mov ah, [si]
    if (_ah == 0xff)                            //jz short locret_1A56A
      goto locret_1A56A;
    if ((char)_ah < (char)0x31)                 //jl short loc_1A567
      goto loc_1A567;
    if ((char)_ah > (char)0x35)                 //jg short loc_1A567
      goto loc_1A567;
    memory(_ds, _si) = _al;                     //mov [si], al
loc_1A567:                                      //loc_1A567:
    _si += 1;                                   //inc si
    goto loc_1A554;                             //jmp short loc_1A554
locret_1A56A:                                   //locret_1A56A:
    return;
}

void sub_1A56B()
{
    _indirectCall(_ds, memory16(_ds, 0x26));    //call word ptr ds:26h
    _ax = 0x0a0c;                               //mov ax, 0A0Ch
    _si = 0x94c1;                               //mov si, 94C1h
    _indirectCall(_ds, memory16(_ds, 0x46));    //call word ptr ds:46h
    _ax = 0x0b0c;                               //mov ax, 0B0Ch
    _si = 0x94e1;                               //mov si, 94E1h
    _indirectCall(_ds, memory16(_ds, 0x46));    //call word ptr ds:46h
    _ax = 0x0c0c;                               //mov ax, 0C0Ch
    _si = 0x9501;                               //mov si, 9501h
    _indirectCall(_ds, memory16(_ds, 0x46));    //call word ptr ds:46h
    _indirectCall(_ds, memory16(_ds, 0x1C));    //call word ptr ds:1Ch
}

void sub_1A592()
{
    WORD _cs = _seg001;

    _push(_cs);                                 //push cs
    _ds = _pop();                               //pop ds
    _di = 0x66f6;                               //mov di, 66F6h
    _cx = 0x0006;                               //mov cx, 6
    _al = 0x0a;                                 //mov al, 0Ah
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    memory16(_ds, 0x6610) = 0x0006;             //mov word_16A10, 6
    _di = 0x66fd;                               //mov di, 66FDh
    _cx = 0x0006;                               //mov cx, 6
    _al = 0x0b;                                 //mov al, 0Bh
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    memory16(_ds, 0x6612) = 0x0006;             //mov word_16A12, 6
    _di = 0x6704;                               //mov di, 6704h
    _cx = 0x0006;                               //mov cx, 6
    _al = 0x0c;                                 //mov al, 0Ch
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    memory16(_ds, 0x6614) = 0x0006;             //mov word_16A14, 6
    sub_1A5F0();                                //call sub_1A5F0
    off_1041A();                                //call off_1041A
    memory16(_ds, 0x8BEC) = 0x0001;             //mov word_18FEC, 1
    memory16(_ds, 0x7E16) = 0x0000;             //mov word_18216, 0
    memory16(_ds, 0x7E18) = 0x0000;             //mov word_18218, 0
    memory16(_ds, 0x7E00) = 0x0000;             //mov word_18200, 0
    _STOP_("sp-trace-fail");                    //sub_1A592 endp_failed
    _STOP_("continues");                        //sub_1A5E3 proc near
}

void sub_1A5E3()
{
    WORD _cs = _seg001;

    _push(_cs);                                 //push cs
    _ds = _pop();                               //pop ds
    _di = 0x6616;                               //mov di, 6616h
    _cx = 0x0006;                               //mov cx, 6
    _al = _al ^ _al;                            //xor al, al
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
}

void sub_1A5F0()
{
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, 0xB00) = _ax;                 //mov word_10F00, ax
    memory16(_ds, 0xB38) = _ax;                 //mov word_10F38, ax
    _ax += 1;                                   //inc ax
    memory16(_ds, 0xB1C) = _ax;                 //mov word_10F1C, ax
    _ax -= 1;                                   //dec ax
    _di = 0x0b56;                               //mov di, 0B56h
loc_1A600:                                      //loc_1A600:
    _dx = memory16(_ds, _di);                   //mov dx, [di]
    _flags.sign = !!(_dx & 0x8000);             //or dx, dx
    _dx |= _dx;
    if (_flags.sign)                            //js short loc_1A60C
      goto loc_1A60C;
    _stosw<MemAuto, DirAuto>();                 //stosw
    _di += 0x0032;                              //add di, 32h
    goto loc_1A600;                             //jmp short loc_1A600
loc_1A60C:                                      //loc_1A60C:
    _di = 0x0c28;                               //mov di, 0C28h
loc_1A60F:                                      //loc_1A60F:
    _dx = memory16(_ds, _di);                   //mov dx, [di]
    _flags.sign = !!(_dx & 0x8000);             //or dx, dx
    _dx |= _dx;
    if (_flags.sign)                            //js short locret_1A61B
      goto locret_1A61B;
    _stosw<MemAuto, DirAuto>();                 //stosw
    _di += 0x0032;                              //add di, 32h
    goto loc_1A60F;                             //jmp short loc_1A60F
locret_1A61B:                                   //locret_1A61B:
    return;
}

void sub_1A65B()
{
    memory16(_ds, 0xA255) = _ax;                //mov word_1A655, ax
    memory16(_ds, 0xA257) = _cx;                //mov word_1A657, cx
    sub_1A67B();                                //call sub_1A67B
    _push(_ds);                                 //push ds
    _bx = memory16(_ds, 0xA259);                //mov bx, word_1A659
    _ax = memory16(_ds, 0xA255);                //mov ax, word_1A655
    _dx = memory16(_ds, 0xA257);                //mov dx, word_1A657
    _ds = _ax;                                  //mov ds, ax
    sub_1A693();                                //call sub_1A693
    _ds = _pop();                               //pop ds
    sub_1A69D();                                //call sub_1A69D
}

void sub_1A67B()
{
    _ah = 0x3d;                                 //mov ah, 3Dh
    _al = 0x00;                                 //mov al, 0
    _interrupt(33);                             //int 21h
    if (_flags.carry)                           //jb short loc_1A6FB
      _STOP_("goto loc_1A6FB");
    _push(_ds);                                 //push ds
    _push(_ax);                                 //push ax
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _ax = _pop();                               //pop ax
    memory16(_ds, 0xA259) = _ax;                //mov word_1A659, ax
    _ds = _pop();                               //pop ds
}

void sub_1A693()
{
    _ah = 0x3f;                                 //mov ah, 3Fh
    _cx = 0xffff;                               //mov cx, 0FFFFh
    _interrupt(33);                             //int 21h
    if (_flags.carry)                           //jb short loc_1A6FB
      _STOP_("goto loc_1A6FB");
}

void sub_1A69D()
{
    _ah = 0x3e;                                 //mov ah, 3Eh
    _bx = memory16(_ds, 0xA259);                //mov bx, ds:0A259h
    _interrupt(33);                             //int 21h
    if (_flags.carry)                           //jb short loc_1A6FB
      goto loc_1A6FB;
    return;                                     //retn
loc_1A6A8:                                      //loc_1A6A8:
    memory16(_ds, 0xA24F) = _ax;                //mov ds:0A24Fh, ax
    memory16(_ds, 0xA251) = _bx;                //mov ds:0A251h, bx
    memory16(_ds, 0xA253) = _cx;                //mov ds:0A253h, cx
    loc_1A6E0();                                //call loc_1A6E0
    _ax = memory16(_ds, 0xA24F);                //mov ax, ds:0A24Fh
    _bx = memory16(_ds, 0xA251);                //mov bx, ds:0A251h
    _cx = memory16(_ds, 0xA253);                //mov cx, ds:0A253h
    _push(_ds);                                 //push ds
    _ds = _ax;                                  //mov ds, ax
    _dx = _bx;                                  //mov dx, bx
    loc_1A6CE();                                //call loc_1A6CE
    _ds = _pop();                               //pop ds
    sub_1A69D();                                //call sub_1A69D
    return;                                     //retn
loc_1A6CE:                                      //loc_1A6CE:
    _push(_ds);                                 //push ds
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _bx = memory16(_ds, 0xA259);                //mov bx, word_1A659
    _ds = _pop();                               //pop ds
    _ah = 0x40;                                 //mov ah, 40h
    _interrupt(33);                             //int 21h
    if (_flags.carry)                           //jb short loc_1A6FB
      goto loc_1A6FB;
    return;                                     //retn
loc_1A6E0:                                      //loc_1A6E0:
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _cx = 0x0000;                               //mov cx, 0
    _ah = 0x3c;                                 //mov ah, 3Ch
    _interrupt(33);                             //int 21h
    if (_flags.carry)                           //jb short loc_1A6FB
      goto loc_1A6FB;
    _push(_ds);                                 //push ds
    _push(_ax);                                 //push ax
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _ax = _pop();                               //pop ax
    memory16(_ds, 0xA259) = _ax;                //mov word_1A659, ax
    _ds = _pop();                               //pop ds
    return;                                     //retn
loc_1A6FB:                                      //loc_1A6FB:
    _push(_ds);                                 //push ds
    _ax = 0x0003;                               //mov ax, 3
    _interrupt(16);                             //int 10h
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _dx = 0xa21c;                               //mov dx, 0A21Ch
    _ah = 0x09;                                 //mov ah, 9
    _interrupt(33);                             //int 21h
    _ds = _pop();                               //pop ds
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    memory(_ds, 0xB888) = 0x00;                 //mov byte_1BC88, 0
loc_1A719:                                      //loc_1A719:
    _al = memory(_ds, 0xB888);                  //mov al, byte_1BC88
    if (_al == 0x00)                            //jz short loc_1A719
      goto loc_1A719;
{loc_196F3(); return; };                        //
}

void sub_1AC6D()
{
loc_1AC6D:
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    if (memory(_ds, 0xA85E) == 0xff)            //jz short loc_1AC7D
      goto loc_1AC7D;
    sub_1AEE6();                                //call sub_1AEE6
    return;                                     //retn
loc_1AC7D:                                      //loc_1AC7D:
    if (memory(_ds, 0xA860) == 0x01)            //jz short loc_1AC8A
      goto loc_1AC8A;
    memory(_ds, 0xA85E) = 0x00;                 //mov byte_1AC5E, 0
    return;                                     //retn
loc_1AC8A:                                      //loc_1AC8A:
    if (!(memory(_ds, 0xA85A) & 0xff))          //jz short loc_1AC94
      goto loc_1AC94;
    goto loc_1AD0F;                             //jmp short loc_1AD0F
loc_1AC94:                                      //loc_1AC94:
    memory16(_ds, 0xA850) = 0x0000;             //mov word_1AC50, 0
    memory(_ds, 0xA85E) = 0xff;                 //mov byte_1AC5E, 0FFh
    memory(_ds, 0xA852) -= 1;                   //dec byte_1AC52
    if (memory(_ds, 0xA852) == 0)               //jz short loc_1ACB5
      goto loc_1ACB5;
    _si = memory16(_ds, 0xA858);                //mov si, word_1AC58
    memory16(_ds, 0xA856) = _si;                //mov word_1AC56, si
    memory(_ds, 0xA85A) = 0xff;                 //mov byte_1AC5A, 0FFh
    goto loc_1AD0F;                             //jmp short loc_1AD0F
    _STOP_("db 90h");                           //db 90h
loc_1ACB5:                                      //loc_1ACB5:
    memory(_ds, 0xA852) = 0x01;                 //mov byte_1AC52, 1
    _si = memory16(_ds, 0xA854);                //mov si, word_1AC54
loc_1ACBE:                                      //loc_1ACBE:
    _al = memory(_ds, _si);                     //mov al, [si]
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _ah = _ah ^ _ah;                            //xor ah, ah
    if (_ax != 0x00ff)                          //jnz short loc_1ACD1
      goto loc_1ACD1;
    sub_1ADB0();                                //call sub_1ADB0
    memory(_ds, 0xA85E) = 0x00;                 //mov byte_1AC5E, 0
    return;                                     //retn
loc_1ACD1:                                      //loc_1ACD1:
    if ((short)_ax < (short)0x00c0)             //jl short loc_1ACE0
      goto loc_1ACE0;
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _ah = _ah ^ _ah;                            //xor ah, ah
    memory(_ds, 0xA84E) = _al;                  //mov byte_1AC4E, al
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    goto loc_1ACF3;                             //jmp short loc_1ACF3
loc_1ACE0:                                      //loc_1ACE0:
    if ((short)_ax < (short)0x0081)             //jl short loc_1ACE7
      goto loc_1ACE7;
    goto loc_1ACBE;                             //jmp short loc_1ACBE
loc_1ACE7:                                      //loc_1ACE7:
    if ((short)_ax < (short)0x0080)             //jl short loc_1ACF3
      goto loc_1ACF3;
    _ax -= 0x0080;                              //sub ax, 80h
    memory(_ds, 0xA852) = _al;                  //mov byte_1AC52, al
    _lodsb<MemAuto, DirAuto>();                 //lodsb
loc_1ACF3:                                      //loc_1ACF3:
    _bx = 0xa5e1;                               //mov bx, 0A5E1h
    _ah = _ah ^ _ah;                            //xor ah, ah
    _ax <<= 1;                                  //shl ax, 1
    _bx += _ax;                                 //add bx, ax
    _bx = memory16(_ds, _bx);                   //mov bx, [bx]
    memory16(_ds, 0xA856) = _bx;                //mov word_1AC56, bx
    memory16(_ds, 0xA854) = _si;                //mov word_1AC54, si
    memory16(_ds, 0xA858) = _bx;                //mov word_1AC58, bx
    memory(_ds, 0xA85A) = 0xff;                 //mov byte_1AC5A, 0FFh
loc_1AD0F:                                      //loc_1AD0F:
    memory16(_ds, 0xA850) -= 1;                 //dec word_1AC50
    if ((short)memory16(_ds, 0xA850) <= (short)0x0003)
      goto loc_1AD1B;
    return;                                     //retn
loc_1AD1B:                                      //loc_1AD1B:
    if (memory16(_ds, 0xA850) == 0xffff)        //jz short loc_1AD25
      goto loc_1AD25;
    goto loc_1AD6A;                             //jmp short loc_1AD6A
    _STOP_("db 90h");                           //db 90h
loc_1AD25:                                      //loc_1AD25:
    _si = memory16(_ds, 0xA856);                //mov si, word_1AC56
    _bx = 0xa7d2;                               //mov bx, 0A7D2h
loc_1AD2C:                                      //loc_1AD2C:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _ah = _ah ^ _ah;                            //xor ah, ah
    if (_ax != 0x00ff)                          //jnz short loc_1AD3C
      goto loc_1AD3C;
    memory(_ds, 0xA85A) = 0x00;                 //mov byte_1AC5A, 0
    goto loc_1AC6D;                             //jmp sub_1AC6D
loc_1AD3C:                                      //loc_1AD3C:
    if (_ax == 0x003d)                          //jz short loc_1AD60
      goto loc_1AD60;
    if ((short)_ax < (short)0x0081)             //jl short loc_1AD48
      goto loc_1AD48;
    goto loc_1AD2C;                             //jmp short loc_1AD2C
loc_1AD48:                                      //loc_1AD48:
    _al = _al + memory(_ds, 0xA84E);            //add al, byte_1AC4E
    _ax <<= 1;                                  //shl ax, 1
    _bx += _ax;                                 //add bx, ax
    _cx = memory16(_ds, _bx);                   //mov cx, [bx]
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _ah = _ah ^ _ah;                            //xor ah, ah
    memory16(_ds, 0xA856) = _si;                //mov word_1AC56, si
    memory16(_ds, 0xA850) = _ax;                //mov word_1AC50, ax
    sub_1ADB7();                                //call sub_1ADB7
    return;                                     //retn
loc_1AD60:                                      //loc_1AD60:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _ah = _ah ^ _ah;                            //xor ah, ah
    memory16(_ds, 0xA856) = _si;                //mov word_1AC56, si
    memory16(_ds, 0xA850) = _ax;                //mov word_1AC50, ax
loc_1AD6A:                                      //loc_1AD6A:
    sub_1ADB0();                                //call sub_1ADB0
}

void sub_1AD6E()
{
    _ah = _ah ^ _ah;                            //xor ah, ah
    _ax <<= 1;                                  //shl ax, 1
    _bx = _ax;                                  //mov bx, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax += _bx;                                 //add ax, bx
    _bx = 0xa64d;                               //mov bx, 0A64Dh
    _bx += _ax;                                 //add bx, ax
    _bx = memory16(_ds, _bx);                   //mov bx, [bx]
    memory16(_ds, 0xA854) = _bx;                //mov word_1AC54, bx
    memory(_ds, 0xA852) = 0x01;                 //mov byte_1AC52, 1
    memory(_ds, 0xA84E) = 0x00;                 //mov byte_1AC4E, 0
    memory16(_ds, 0xA850) = 0x0001;             //mov word_1AC50, 1
    memory16(_ds, 0xA856) = 0x0000;             //mov word_1AC56, 0
    memory16(_ds, 0xA858) = 0x0000;             //mov word_1AC58, 0
    memory(_ds, 0xA85A) = 0x00;                 //mov byte_1AC5A, 0
    memory16(_ds, 0xA85C) = 0x0000;             //mov word_1AC5C, 0
    memory(_ds, 0xA85E) = 0xff;                 //mov byte_1AC5E, 0FFh
}

void sub_1ADB0()
{
    _in(_al, 97);                               //in al, 61h
    _al &= 0xfd;                                //and al, 0FDh
    _out(97, _al);                              //out 61h, al
}

void sub_1ADB7()
{
    _dx = 0x0043;                               //mov dx, 43h
    _al = 0xb6;                                 //mov al, 0B6h
    _out(_dx, _al);                             //out dx, al
    _dx -= 1;                                   //dec dx
    _al = _cl;                                  //mov al, cl
    _out(_dx, _al);                             //out dx, al
    _al = _ch;                                  //mov al, ch
    _out(_dx, _al);                             //out dx, al
    _in(_al, 97);                               //in al, 61h
    _al |= 0x03;                                //or al, 3
    _out(97, _al);                              //out 61h, al
}

void sub_1ADCB()
{
    WORD _cs = _seg001;

    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ah = 0x35;                                 //mov ah, 35h
    _al = 0x08;                                 //mov al, 8
    _interrupt(33);                             //int 21h
    _push(_ax);                                 //push ax
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _ax = _pop();                               //pop ax
    memory16(_ds, 0xB88E) = _es;                //mov word_1BC8E, es
    memory16(_cs, 0xAA7B) = _es;                //mov cs:seg_1AE7B, es
    memory16(_ds, 0xB890) = _bx;                //mov word_1BC90, bx
    memory16(_cs, 0xAA79) = _bx;                //mov cs:word_1AE79, bx
    _ah = 0x25;                                 //mov ah, 25h
    _al = 0x08;                                 //mov al, 8
    _push(_cs);                                 //push cs
    _ds = _pop();                               //pop ds
    _dx = 0xaa28;                               //mov dx, 0AA28h
    _interrupt(33);                             //int 21h
    _ax = 0x4000;                               //mov ax, 4000h
    _out(64, _al);                              //out 40h, al
    _al = _ah;                                  //mov al, ah
    _out(64, _al);                              //out 40h, al
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_1AE03()
{
    _push(_ds);                                 //push ds
    _push(_ax);                                 //push ax
    _ax = 0x0000;                               //mov ax, 0
    _out(64, _al);                              //out 40h, al
    _al = _ah;                                  //mov al, ah
    _out(64, _al);                              //out 40h, al
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _dx = memory16(_ds, 0xB890);                //mov dx, word_1BC90
    _ds = memory16(_ds, 0xB88E);                //mov ds, word_1BC8E
    _ah = 0x25;                                 //mov ah, 25h
    _al = 0x08;                                 //mov al, 8
    _interrupt(33);                             //int 21h
    _ax = _pop();                               //pop ax
    _ds = _pop();                               //pop ds
}

void sub_1AE81()
{
    _al = memory(_ds, 0xAA26);                  //mov al, ds:0AA26h
loc_1AE84:                                      //loc_1AE84:
    if (_al == memory(_ds, 0xAA26))             //jz short loc_1AE84
      goto loc_1AE84;
    _al = memory(_ds, 0xAA26);                  //mov al, ds:0AA26h
loc_1AE8D:                                      //loc_1AE8D:
    _flags.carry = (memory(_ds, 0xAA7D) + 0x01) >= 0x100;
    memory(_ds, 0xAA7D) += 0x01;
    _flags.carry2 = (memory(_ds, 0xAA7E) + 0x00 + _flags.carry) >= 0x100;
    memory(_ds, 0xAA7E) = memory(_ds, 0xAA7E) + 0x00 + _flags.carry;_flags.carry = flags.carry2;
    _flags.carry2 = (memory(_ds, 0xAA7F) + 0x00 + _flags.carry) >= 0x100;
    memory(_ds, 0xAA7F) = memory(_ds, 0xAA7F) + 0x00 + _flags.carry;_flags.carry = flags.carry2;
    memory(_ds, 0xAA80) = memory(_ds, 0xAA80) + 0x00 + _flags.carry;
    if (_al == memory(_ds, 0xAA26))             //jz short loc_1AE8D
      goto loc_1AE8D;
    _ax = memory16(_ds, 0xAA7D);                //mov ax, ds:0AA7Dh
    if ((short)_ax < (short)0x0b00)             //jl short loc_1AEB6
      goto loc_1AEB6;
    memory16(_ds, 0x96F4) = 0x0003;             //mov word ptr ds:96F4h, 3
    return;                                     //retn
loc_1AEB6:                                      //loc_1AEB6:
    if ((short)_ax < (short)0x0700)             //jl short loc_1AEC2
      goto loc_1AEC2;
    memory16(_ds, 0x96F4) = 0x0002;             //mov word ptr ds:96F4h, 2
    return;                                     //retn
loc_1AEC2:                                      //loc_1AEC2:
    memory16(_ds, 0x96F4) = 0x0001;             //mov word ptr ds:96F4h, 1
    _indirectCall(_ds, memory16(_ds, 0x4A));    //call word ptr ds:4Ah
}

void sub_1AECD()
{
    if ((short)_ax < (short)0x000b)             //jl short loc_1AED5
      goto loc_1AED5;
{loc_1BB82(); return; };                        //
loc_1AED5:                                      //loc_1AED5:
    if (memory16(_ds, 0xAB2B) == 0x0001)        //jz short loc_1AEE0
      goto loc_1AEE0;
    sub_1AD6E();                                //call sub_1AD6E
    return;                                     //retn
loc_1AEE0:                                      //loc_1AEE0:
    _bx = _ax;                                  //mov bx, ax
    sub_1B95D();                                //call sub_1B95D
}

void sub_1AEE6()
{
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    if (memory16(_ds, 0xAB2B) == 0x0001)        //jz short locret_1AF25
      goto locret_1AF25;
    if (memory(_ds, 0xA85E) == 0xff)            //jz short locret_1AF25
      goto locret_1AF25;
    _si = memory16(_ds, 0xAB29);                //mov si, word_1AF29
    _si |= _si;                                 //or si, si
    if (_si != 0)                               //jnz short loc_1AF02
      goto loc_1AF02;
    return;                                     //retn
loc_1AF02:                                      //loc_1AF02:
    _cl = memory(_ds, _si);                     //mov cl, [si]
    _ch = _ch ^ _ch;                            //xor ch, ch
    _si += 1;                                   //inc si
    memory16(_ds, 0xAB29) = _si;                //mov word_1AF29, si
    _cx |= _cx;                                 //or cx, cx
    if (_cx == 0)                               //jz short loc_1AF1C
      goto loc_1AF1C;
    _cx += _cx;                                 //add cx, cx
    _bx = 0xa7d2;                               //mov bx, 0A7D2h
    _bx += _cx;                                 //add bx, cx
    _cx = memory16(_ds, _bx);                   //mov cx, [bx]
    sub_1ADB7();                                //call sub_1ADB7
    return;                                     //retn
loc_1AF1C:                                      //loc_1AF1C:
    memory16(_ds, 0xAB29) = 0x0000;             //mov word_1AF29, 0
    sub_1ADB0();                                //call sub_1ADB0
locret_1AF25:                                   //locret_1AF25:
    return;
}

void sub_1B93B()
{
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _ax = memory16(_ds, 0xB369);                //mov ax, word_1B769
    _ax = _ax | memory16(_ds, 0xB37D);          //or ax, word_1B77D
    _ax = _ax | memory16(_ds, 0xB391);          //or ax, word_1B791
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_1B955
      goto loc_1B955;
    memory(_ds, 0xA85E) = 0xff;                 //mov byte_1AC5E, 0FFh
    return;                                     //retn
loc_1B955:                                      //loc_1B955:
    memory(_ds, 0xA85E) = 0x00;                 //mov byte_1AC5E, 0
}

void sub_1B95D()
{
    WORD _cs = _seg001;

    _ax = _cs;                                  //mov ax, cs
    _ds = _ax;                                  //mov ds, ax
    memory16(_ds, 0xB55B) = 0x0001;             //mov word_1B95B, 1
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _bx = _cs;                                  //mov bx, cs
    _es = _bx;                                  //mov es, bx
    _si = 0x0000;                               //mov si, 0
    _bx = 0xb3a7;                               //mov bx, 0B3A7h
    _interrupt(101);                            //int 65h
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    memory16(_ds, 0xB3A7) = 0x0001;             //mov word ptr ds:0B3A7h, 1
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _bx = _cs;                                  //mov bx, cs
    _es = _bx;                                  //mov es, bx
    _si = 0x0006;                               //mov si, 6
    _bx = 0xb3a7;                               //mov bx, 0B3A7h
    _interrupt(101);                            //int 65h
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    _bx += _bx;                                 //add bx, bx
    _ax = _bx;                                  //mov ax, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _ax;                                 //add bx, ax
    _bx += 0xa64d;                              //add bx, 0A64Dh
    _di = 0xb369;                               //mov di, 0B369h
    memory16(_ds, _di) = 0x00ff;                //mov word ptr [di], 0FFh
    _ax = memory16(_ds, _bx);                   //mov ax, [bx]
    memory16(_ds, _di + 2) = _ax;               //mov [di+2], ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, _di + 16) = _ax;              //mov [di+10h], ax
    memory16(_ds, _di + 12) = _ax;              //mov [di+0Ch], ax
    memory16(_ds, _di + 18) = _ax;              //mov [di+12h], ax
    _push(_bx);                                 //push bx
    sub_1BB3F();                                //call sub_1BB3F
    _bx = _pop();                               //pop bx
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _di = 0xb37d;                               //mov di, 0B37Dh
    memory16(_ds, _di) = 0x00ff;                //mov word ptr [di], 0FFh
    _ax = memory16(_ds, _bx);                   //mov ax, [bx]
    memory16(_ds, _di + 2) = _ax;               //mov [di+2], ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, _di + 16) = _ax;              //mov [di+10h], ax
    _ax = 0x0001;                               //mov ax, 1
    memory16(_ds, _di + 12) = _ax;              //mov [di+0Ch], ax
    memory16(_ds, _di + 18) = _ax;              //mov [di+12h], ax
    _push(_bx);                                 //push bx
    sub_1BB3F();                                //call sub_1BB3F
    _bx = _pop();                               //pop bx
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _di = 0xb391;                               //mov di, 0B391h
    memory16(_ds, _di) = 0x00ff;                //mov word ptr [di], 0FFh
    _ax = memory16(_ds, _bx);                   //mov ax, [bx]
    memory16(_ds, _di + 2) = _ax;               //mov [di+2], ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory16(_ds, _di + 16) = _ax;              //mov [di+10h], ax
    _ax = 0x0002;                               //mov ax, 2
    memory16(_ds, _di + 12) = _ax;              //mov [di+0Ch], ax
    memory16(_ds, _di + 18) = _ax;              //mov [di+12h], ax
    sub_1BB3F();                                //call sub_1BB3F
    memory16(_ds, 0xB55B) = 0x0000;             //mov word ptr ds:0B55Bh, 0
}

void sub_1BA18()
{
    WORD _cs = _seg001;

    if (memory(_ds, 0xA860) == 0x01)            //jz short loc_1BA20
      goto loc_1BA20;
    return;                                     //retn
loc_1BA20:                                      //loc_1BA20:
    _ax = _cs;                                  //mov ax, cs
    _ds = _ax;                                  //mov ds, ax
    _di = 0xb369;                               //mov di, 0B369h
    sub_1BA3A();                                //call sub_1BA3A
    _di = 0xb37d;                               //mov di, 0B37Dh
    sub_1BA3A();                                //call sub_1BA3A
    _di = 0xb391;                               //mov di, 0B391h
    sub_1BA3A();                                //call sub_1BA3A
    sub_1B93B();                                //call sub_1B93B
}

void sub_1BA3A()
{
    _ax = memory16(_ds, _di);                   //mov ax, [di]
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_1BA41
      goto loc_1BA41;
    return;                                     //retn
loc_1BA41:                                      //loc_1BA41:
    _ax = memory16(_ds, _di + 12);              //mov ax, [di+0Ch]
    memory16(_ds, _di + 18) = _ax;              //mov [di+12h], ax
    _si = memory16(_ds, _di + 6);               //mov si, [di+6]
    memory(_ds, _di + 8) += 1;                  //inc byte ptr [di+8]
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    if (_al == memory(_ds, _di + 8))            //jz short loc_1BA56
      goto loc_1BA56;
    return;                                     //retn
loc_1BA56:                                      //loc_1BA56:
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    _STOP_("sp-trace-fail");                    //sub_1BA3A endp_failed
    _STOP_("continues");                        //loc_1BA58:
}

void sub_1BB3F()
{
    memory16(_ds, _di + 10) = 0x0001;           //mov word ptr [di+0Ah], 1
    _si = memory16(_ds, _di + 2);               //mov si, [di+2]
loc_1BB47:                                      //loc_1BB47:
    _al = memory(_ds, _si);                     //mov al, [si]
    if (_al != 0xff)                            //jnz short loc_1BB52
      goto loc_1BB52;
    memory16(_ds, _di) = 0x0000;                //mov word ptr [di], 0
    return;                                     //retn
loc_1BB52:                                      //loc_1BB52:
    _flags.sign = !!(_al & 0x80);               //or al, al
    _al |= _al;
    if (!_flags.sign)                           //jns short loc_1BB6C
      goto loc_1BB6C;
    if (_al != 0xc0)                            //jnz short loc_1BB64
      goto loc_1BB64;
    _si += 1;                                   //inc si
    _al = memory(_ds, _si);                     //mov al, [si]
    _cbw();                                     //cbw
    memory16(_ds, _di + 16) = _ax;              //mov [di+10h], ax
    _si += 1;                                   //inc si
    goto loc_1BB47;                             //jmp short loc_1BB47
loc_1BB64:                                      //loc_1BB64:
    _al &= 0x7f;                                //and al, 7Fh
    memory(_ds, _di + 10) = _al;                //mov [di+0Ah], al
    _si += 1;                                   //inc si
    goto loc_1BB47;                             //jmp short loc_1BB47
loc_1BB6C:                                      //loc_1BB6C:
    _si += 1;                                   //inc si
    memory16(_ds, _di + 2) = _si;               //mov [di+2], si
    _ah = _ah ^ _ah;                            //xor ah, ah
    _ax += _ax;                                 //add ax, ax
    _bx = _ax;                                  //mov bx, ax
    _bx += 0xa5e1;                              //add bx, 0A5E1h
    _si = memory16(_ds, _bx);                   //mov si, [bx]
    memory16(_ds, _di + 4) = _si;               //mov [di+4], si
    _STOP_("goto loc_1BA58");                   //jmp loc_1BA58
}

void loc_1BB82()
{
    WORD _cs = _seg001;

    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_bp);                                 //push bp
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _bx = _cs;                                  //mov bx, cs
    _ds = _bx;                                  //mov ds, bx
    _es = _bx;                                  //mov es, bx
    _ax -= 0x000b;                              //sub ax, 0Bh
    if (memory16(_ds, 0xAB2B) == 0x0001)        //jz short loc_1BB9E
      goto loc_1BB9E;
    goto loc_1BC4A;                             //jmp loc_1BC4A
loc_1BB9E:                                      //loc_1BB9E:
    if (memory(_ds, 0xA85E) != 0xff)            //jnz short loc_1BBA8
      goto loc_1BBA8;
    goto loc_1BC40;                             //jmp loc_1BC40
loc_1BBA8:                                      //loc_1BBA8:
    _ax += _ax;                                 //add ax, ax
    _ax += _ax;                                 //add ax, ax
    _si = 0xb181;                               //mov si, 0B181h
    _si += _ax;                                 //add si, ax
    _ax = memory16(_ds, 0xAB27);                //mov ax, word_1AF27
    _ax -= 1;                                   //dec ax
    if ((short)_ax >= 0)                        //jns short loc_1BBBA
      goto loc_1BBBA;
    _ax = 0x0005;                               //mov ax, 5
loc_1BBBA:                                      //loc_1BBBA:
    memory16(_ds, 0xAB27) = _ax;                //mov word_1AF27, ax
    _ax = memory16(_ds, _si + 2);               //mov ax, [si+2]
    _push(_ax);                                 //push ax
    _si = memory16(_ds, _si);                   //mov si, [si]
    _push(_si);                                 //push si
    _ax = memory16(_ds, 0xAB27);                //mov ax, word_1AF27
    memory16(_ds, 0xB3A7) = _ax;                //mov word_1B7A7, ax
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory16(_ds, 0xB3A9) = _si;                //mov word_1B7A9, si
    memory16(_ds, 0xB3AB) = _ds;                //mov word_1B7AB, ds
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _bx = _cs;                                  //mov bx, cs
    _es = _bx;                                  //mov es, bx
    _si = 0x0015;                               //mov si, 15h
    _bx = 0xb3a7;                               //mov bx, 0B3A7h
    _interrupt(101);                            //int 65h
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    _ax = memory16(_ds, 0xAB27);                //mov ax, ds:0AB27h
    memory16(_ds, 0xB3A7) = _ax;                //mov ds:0B3A7h, ax
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _bx = _cs;                                  //mov bx, cs
    _es = _bx;                                  //mov es, bx
    _si = 0x0014;                               //mov si, 14h
    _bx = 0xb3a7;                               //mov bx, 0B3A7h
    _interrupt(101);                            //int 65h
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    _ax = memory16(_ds, 0xAB27);                //mov ax, ds:0AB27h
    memory16(_ds, 0xB3A7) = _ax;                //mov ds:0B3A7h, ax
    _si = _pop();                               //pop si
    _ax = _pop();                               //pop ax
    _cbw();                                     //cbw
    memory16(_ds, 0xB3A9) = _ax;                //mov ds:0B3A9h, ax
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _bx = _cs;                                  //mov bx, cs
    _es = _bx;                                  //mov es, bx
    _si = 0x0013;                               //mov si, 13h
    _bx = 0xb3a7;                               //mov bx, 0B3A7h
    _interrupt(101);                            //int 65h
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
loc_1BC40:                                      //loc_1BC40:
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _bp = _pop();                               //pop bp
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    return;                                     //retn
loc_1BC4A:                                      //loc_1BC4A:
loc_1BC4F:                                      //loc_1BC4F:
    if (memory(_ds, 0xA85E) != 0xff)            //jnz short loc_1BC53
      goto loc_1BC53;
    goto loc_1BC40;                             //jmp short loc_1BC40
loc_1BC53:                                      //loc_1BC53:
    _dx = memory16(_ds, 0xAB29);                //mov dx, ds:0AB29h
    _dx |= _dx;                                 //or dx, dx
    if (_dx == 0)                               //jz short loc_1BC65
      goto loc_1BC65;
    if (_ax == 0x001a)                          //jz short loc_1BC40
      goto loc_1BC40;
    if (_ax == 0x001b)                          //jz short loc_1BC40
      goto loc_1BC40;
loc_1BC65:                                      //loc_1BC65:
    _ax += _ax;                                 //add ax, ax
    _si = 0xb32d;                               //mov si, 0B32Dh
    _si += _ax;                                 //add si, ax
    _si = memory16(_ds, _si);                   //mov si, [si]
    memory16(_ds, 0xAB29) = _si;                //mov ds:0AB29h, si
    goto loc_1BC40;                             //jmp short loc_1BC40
    _STOP_("byte_1BC74 db 18h, 25h, 2Ch, 2Dh, 19h, 0Ah...");
    _STOP_("byte_1BC84 db 0");                  //byte_1BC84 db 0
    _STOP_("db 90h");                           //db 90h
    _STOP_("byte_1BC86 db 0");                  //byte_1BC86 db 0
    _STOP_("db  90h");                          //db  90h
    _STOP_("byte_1BC88 db 0");                  //byte_1BC88 db 0
    _STOP_("word_1BC8A dw 0");                  //word_1BC8A dw 0
    _STOP_("word_1BC8C dw 0");                  //word_1BC8C dw 0
    _STOP_("word_1BC8E dw 0");                  //word_1BC8E dw 0
    _STOP_("word_1BC90 dw 0");                  //word_1BC90 dw 0
}

void sub_1BC92()
{
    WORD _cs = _seg001;

    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ah = 0x35;                                 //mov ah, 35h
    _al = 0x09;                                 //mov al, 9
    _interrupt(33);                             //int 21h
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    memory16(_ds, 0xB88A) = _es;                //mov word_1BC8A, es
    memory16(_ds, 0xB88C) = _bx;                //mov word_1BC8C, bx
    _ah = 0x25;                                 //mov ah, 25h
    _al = 0x09;                                 //mov al, 9
    _dx = _cs;                                  //mov dx, cs
    _ds = _dx;                                  //mov ds, dx
    _dx = 0xb8cd;                               //mov dx, 0B8CDh
    _interrupt(33);                             //int 21h
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_1BCB7()
{
    _push(_ds);                                 //push ds
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _dx = memory16(_ds, 0xB88C);                //mov dx, word_1BC8C
    _ds = memory16(_ds, 0xB88A);                //mov ds, word_1BC8A
    _ah = 0x25;                                 //mov ah, 25h
    _al = 0x09;                                 //mov al, 9
    _interrupt(33);                             //int 21h
    _ds = _pop();                               //pop ds
}

void sub_1BCCD()
{
    _pushf();                                   //pushf
    _flags.interrupt = false;                   //cli
    _push(_ax);                                 //push ax
    _push(_ds);                                 //push ds
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _in(_al, 96);                               //in al, 60h
    memory(_ds, 0xB888) = _al;                  //mov byte_1BC88, al
    _in(_al, 97);                               //in al, 61h
    _al |= 0x80;                                //or al, 80h
    _out(97, _al);                              //out 61h, al
    _al &= 0x7f;                                //and al, 7Fh
    _out(97, _al);                              //out 61h, al
    _push(_bx);                                 //push bx
    _al = memory(_ds, 0xB888);                  //mov al, byte_1BC88
    _ah = _al;                                  //mov ah, al
    _ah &= 0x80;                                //and ah, 80h
    if (_ah != 0)                               //jnz short loc_1BCF3
      goto loc_1BCF3;
    goto loc_1BE27;                             //jmp loc_1BE27
loc_1BCF3:                                      //loc_1BCF3:
    _bl = memory(_ds, 0xB886);                  //mov bl, byte_1BC86
    _al &= 0x7f;                                //and al, 7Fh
    if (_al != 0x39)                            //jnz short loc_1BD06
      goto loc_1BD06;
    _bl &= 0xef;                                //and bl, 0EFh
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BD06:                                      //loc_1BD06:
    if (_al != memory(_ds, 0xB874))             //jnz short loc_1BD15
      goto loc_1BD15;
    _bl &= 0xf7;                                //and bl, 0F7h
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BD15:                                      //loc_1BD15:
    if (_al != memory(_ds, 0xB875))             //jnz short loc_1BD24
      goto loc_1BD24;
    _bl &= 0xfb;                                //and bl, 0FBh
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BD24:                                      //loc_1BD24:
    if (_al != memory(_ds, 0xB876))             //jnz short loc_1BD33
      goto loc_1BD33;
    _bl &= 0xfd;                                //and bl, 0FDh
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BD33:                                      //loc_1BD33:
    if (_al != memory(_ds, 0xB877))             //jnz short loc_1BD42
      goto loc_1BD42;
    _bl &= 0xfe;                                //and bl, 0FEh
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BD42:                                      //loc_1BD42:
    if (_al != memory(_ds, 0xB878))             //jnz short loc_1BD51
      goto loc_1BD51;
    _bl &= 0xef;                                //and bl, 0EFh
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BD51:                                      //loc_1BD51:
    if (_al != 0x7c)                            //jnz short loc_1BD5E
      goto loc_1BD5E;
    _bl &= 0xf7;                                //and bl, 0F7h
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BD5E:                                      //loc_1BD5E:
    if (_al != 0x7b)                            //jnz short loc_1BD6B
      goto loc_1BD6B;
    _bl &= 0xfb;                                //and bl, 0FBh
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BD6B:                                      //loc_1BD6B:
    if (_al != 0x7a)                            //jnz short loc_1BD78
      goto loc_1BD78;
    _bl &= 0xfd;                                //and bl, 0FDh
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BD78:                                      //loc_1BD78:
    if (_al != 0x79)                            //jnz short loc_1BD85
      goto loc_1BD85;
    _bl &= 0xfe;                                //and bl, 0FEh
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BD85:                                      //loc_1BD85:
    if (_al != 0x77)                            //jnz short loc_1BD92
      goto loc_1BD92;
    _bl &= 0xef;                                //and bl, 0EFh
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BD92:                                      //loc_1BD92:
    if (_al != 0x48)                            //jnz short loc_1BD9F
      goto loc_1BD9F;
    _bl &= 0xf7;                                //and bl, 0F7h
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BD9F:                                      //loc_1BD9F:
    if (_al != 0x50)                            //jnz short loc_1BDAC
      goto loc_1BDAC;
    _bl &= 0xfb;                                //and bl, 0FBh
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BDAC:                                      //loc_1BDAC:
    if (_al != 0x4d)                            //jnz short loc_1BDB9
      goto loc_1BDB9;
    _bl &= 0xfe;                                //and bl, 0FEh
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BDB9:                                      //loc_1BDB9:
    if (_al != 0x4b)                            //jnz short loc_1BDC6
      goto loc_1BDC6;
    _bl &= 0xfd;                                //and bl, 0FDh
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BDC6:                                      //loc_1BDC6:
    if (_al != 0x1d)                            //jnz short loc_1BDD5
      goto loc_1BDD5;
    memory(_ds, 0xB879) &= 0xfe;                //and byte_1BC74+5, 0FEh
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BDD5:                                      //loc_1BDD5:
    if (_al != 0x38)                            //jnz short loc_1BDE4
      goto loc_1BDE4;
    memory(_ds, 0xB879) &= 0xfd;                //and byte_1BC74+5, 0FDh
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BDE4:                                      //loc_1BDE4:
    if (_al != 0x53)                            //jnz short loc_1BDF3
      goto loc_1BDF3;
    memory(_ds, 0xB879) &= 0xfb;                //and byte_1BC74+5, 0FBh
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BDF3:                                      //loc_1BDF3:
    if (_al != 0x47)                            //jnz short loc_1BE00
      goto loc_1BE00;
    _bl &= 0xf5;                                //and bl, 0F5h
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BE00:                                      //loc_1BE00:
    if (_al != 0x49)                            //jnz short loc_1BE0D
      goto loc_1BE0D;
    _bl &= 0xf6;                                //and bl, 0F6h
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BE0D:                                      //loc_1BE0D:
    if (_al != 0x4f)                            //jnz short loc_1BE1A
      goto loc_1BE1A;
    _bl &= 0xf9;                                //and bl, 0F9h
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BE1A:                                      //loc_1BE1A:
    if (_al == 0x51)                            //jz short loc_1BE21
      goto loc_1BE21;
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BE21:                                      //loc_1BE21:
    _bl &= 0xfa;                                //and bl, 0FAh
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BE27:                                      //loc_1BE27:
    _bl = memory(_ds, 0xB886);                  //mov bl, byte_1BC86
    if (_al != 0x39)                            //jnz short loc_1BE38
      goto loc_1BE38;
    _bl |= 0x10;                                //or bl, 10h
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BE38:                                      //loc_1BE38:
    if (_al != memory(_ds, 0xB874))             //jnz short loc_1BE47
      goto loc_1BE47;
    _bl |= 0x08;                                //or bl, 8
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BE47:                                      //loc_1BE47:
    if (_al != memory(_ds, 0xB875))             //jnz short loc_1BE56
      goto loc_1BE56;
    _bl |= 0x04;                                //or bl, 4
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BE56:                                      //loc_1BE56:
    if (_al != memory(_ds, 0xB876))             //jnz short loc_1BE65
      goto loc_1BE65;
    _bl |= 0x02;                                //or bl, 2
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BE65:                                      //loc_1BE65:
    if (_al != memory(_ds, 0xB877))             //jnz short loc_1BE74
      goto loc_1BE74;
    _bl |= 0x01;                                //or bl, 1
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BE74:                                      //loc_1BE74:
    if (_al != memory(_ds, 0xB878))             //jnz short loc_1BE83
      goto loc_1BE83;
    _bl |= 0x10;                                //or bl, 10h
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BE83:                                      //loc_1BE83:
    if (_al != 0x7c)                            //jnz short loc_1BE90
      goto loc_1BE90;
    _bl |= 0x08;                                //or bl, 8
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BE90:                                      //loc_1BE90:
    if (_al != 0x7b)                            //jnz short loc_1BE9D
      goto loc_1BE9D;
    _bl |= 0x04;                                //or bl, 4
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BE9D:                                      //loc_1BE9D:
    if (_al != 0x7a)                            //jnz short loc_1BEAA
      goto loc_1BEAA;
    _bl |= 0x02;                                //or bl, 2
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BEAA:                                      //loc_1BEAA:
    if (_al != 0x79)                            //jnz short loc_1BEB7
      goto loc_1BEB7;
    _bl |= 0x01;                                //or bl, 1
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BEB7:                                      //loc_1BEB7:
    if (_al != 0x77)                            //jnz short loc_1BEC4
      goto loc_1BEC4;
    _bl |= 0x10;                                //or bl, 10h
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BEC4:                                      //loc_1BEC4:
    if (_al != 0x48)                            //jnz short loc_1BED1
      goto loc_1BED1;
    _bl |= 0x08;                                //or bl, 8
    goto loc_1BF56;                             //jmp loc_1BF56
loc_1BED1:                                      //loc_1BED1:
    if (_al != 0x50)                            //jnz short loc_1BEDE
      goto loc_1BEDE;
    _bl |= 0x04;                                //or bl, 4
    goto loc_1BF56;                             //jmp short loc_1BF56
    _STOP_("db  90h");                          //db  90h
loc_1BEDE:                                      //loc_1BEDE:
    if (_al != 0x4d)                            //jnz short loc_1BEEB
      goto loc_1BEEB;
    _bl |= 0x01;                                //or bl, 1
    goto loc_1BF56;                             //jmp short loc_1BF56
    _STOP_("db  90h");                          //db  90h
loc_1BEEB:                                      //loc_1BEEB:
    if (_al != 0x4b)                            //jnz short loc_1BEF8
      goto loc_1BEF8;
    _bl |= 0x02;                                //or bl, 2
    goto loc_1BF56;                             //jmp short loc_1BF56
    _STOP_("db  90h");                          //db  90h
loc_1BEF8:                                      //loc_1BEF8:
    if (_al != 0x47)                            //jnz short loc_1BF05
      goto loc_1BF05;
    _bl |= 0x0a;                                //or bl, 0Ah
    goto loc_1BF56;                             //jmp short loc_1BF56
    _STOP_("db  90h");                          //db  90h
loc_1BF05:                                      //loc_1BF05:
    if (_al != 0x49)                            //jnz short loc_1BF12
      goto loc_1BF12;
    _bl |= 0x09;                                //or bl, 9
    goto loc_1BF56;                             //jmp short loc_1BF56
    _STOP_("db  90h");                          //db  90h
loc_1BF12:                                      //loc_1BF12:
    if (_al != 0x4f)                            //jnz short loc_1BF1F
      goto loc_1BF1F;
    _bl |= 0x06;                                //or bl, 6
    goto loc_1BF56;                             //jmp short loc_1BF56
    _STOP_("db  90h");                          //db  90h
loc_1BF1F:                                      //loc_1BF1F:
    if (_al != 0x51)                            //jnz short loc_1BF2C
      goto loc_1BF2C;
    _bl |= 0x05;                                //or bl, 5
    goto loc_1BF56;                             //jmp short loc_1BF56
    _STOP_("db  90h");                          //db  90h
loc_1BF2C:                                      //loc_1BF2C:
    if (_al != 0x1d)                            //jnz short loc_1BF3B
      goto loc_1BF3B;
    memory(_ds, 0xB879) |= 0x01;                //or byte_1BC74+5, 1
    goto loc_1BF56;                             //jmp short loc_1BF56
    _STOP_("db  90h");                          //db  90h
loc_1BF3B:                                      //loc_1BF3B:
    if (_al != 0x38)                            //jnz short loc_1BF4A
      goto loc_1BF4A;
    memory(_ds, 0xB879) |= 0x02;                //or byte_1BC74+5, 2
    goto loc_1BF56;                             //jmp short loc_1BF56
    _STOP_("db  90h");                          //db  90h
loc_1BF4A:                                      //loc_1BF4A:
    if (_al != 0x53)                            //jnz short loc_1BF56
      goto loc_1BF56;
    memory(_ds, 0xB879) |= 0x04;                //or byte_1BC74+5, 4
loc_1BF56:                                      //loc_1BF56:
    memory(_ds, 0xB886) = _bl;                  //mov byte_1BC86, bl
    _bh = memory(_ds, 0xB882);                  //mov bh, byte_1BC74+0Eh
    _bl |= _bh;                                 //or bl, bh
    memory(_ds, 0xB884) = _bl;                  //mov byte_1BC84, bl
    if (memory(_ds, 0xB879) != 0x07)            //jnz short loc_1BF73
      goto loc_1BF73;
    _STOP_("goto far ptr 0FFFFh:0");            //jmp far ptr 0FFFFh:0
loc_1BF73:                                      //loc_1BF73:
    _bx = _pop();                               //pop bx
    _ds = _pop();                               //pop ds
    _al = 0x61;                                 //mov al, 61h
    _out(32, _al);                              //out 20h, al
    _ax = _pop();                               //pop ax
    _popf();                                    //popf
}

void sub_1BF7C()
{
    _dx = 0x0201;                               //mov dx, 201h
    _ax = _ax ^ _ax;                            //xor ax, ax
    _cx = _cx ^ _cx;                            //xor cx, cx
    _in(_al, _dx);                              //in al, dx
    _ax &= 0x0030;                              //and ax, 30h
    if (_ax == 0x0030)                          //jz short loc_1BF8F
      goto loc_1BF8F;
    _cx = 0xffff;                               //mov cx, 0FFFFh
loc_1BF8F:                                      //loc_1BF8F:
    _push(_cx);                                 //push cx
    _bl = 0x01;                                 //mov bl, 1
    sub_1BFA0();                                //call sub_1BFA0
    _push(_cx);                                 //push cx
    _bl = 0x02;                                 //mov bl, 2
    sub_1BFA0();                                //call sub_1BFA0
    _dx = _cx;                                  //mov dx, cx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
}

void sub_1BFA0()
{
    _push(_dx);                                 //push dx
    _flags.interrupt = false;                   //cli
    _al = 0x00;                                 //mov al, 0
    _out(67, _al);                              //out 43h, al
    _STOP_("goto $+2");                         //jmp short $+2
loc_1BFA8:                                      //loc_1BFA8:
    _in(_al, 64);                               //in al, 40h
    _ah = _al;                                  //mov ah, al
    _STOP_("goto $+2");                         //jmp short $+2
loc_1BFAE:                                      //loc_1BFAE:
    _in(_al, 64);                               //in al, 40h
    _xchg(_ah, _al);                            //xchg ah, al
    _push(_ax);                                 //push ax
    _cx = 0x04ff;                               //mov cx, 4FFh
    _out(_dx, _al);                             //out dx, al
    _STOP_("goto $+2");                         //jmp short $+2
loc_1BFB9:                                      //loc_1BFB9:
    _in(_al, _dx);                              //in al, dx
    if (--_cx && _al & _bl)                     //loopne loc_1BFB9
      goto loc_1BFB9;
    _cx = _pop();                               //pop cx
    if (_cx != 0x0000)                          //jnz short loc_1BFC9
      goto loc_1BFC9;
    _cx = _cx ^ _cx;                            //xor cx, cx
    goto loc_1BFF7;                             //jmp short loc_1BFF7
    _STOP_("db 90h");                           //db 90h
loc_1BFC9:                                      //loc_1BFC9:
    _al = 0x00;                                 //mov al, 0
    _out(67, _al);                              //out 43h, al
    _STOP_("goto $+2");                         //jmp short $+2
loc_1BFCF:                                      //loc_1BFCF:
    _in(_al, 64);                               //in al, 40h
    _ah = _al;                                  //mov ah, al
    _STOP_("goto $+2");                         //jmp short $+2
loc_1BFD5:                                      //loc_1BFD5:
    _in(_al, 64);                               //in al, 40h
    _xchg(_ah, _al);                            //xchg ah, al
    if (_cx >= _ax)                             //jnb short loc_1BFE9
      goto loc_1BFE9;
    _push(_dx);                                 //push dx
    _dx = 0xffff;                               //mov dx, 0FFFFh
    _dx -= _ax;                                 //sub dx, ax
    _cx += _dx;                                 //add cx, dx
    _dx = _pop();                               //pop dx
    goto loc_1BFEB;                             //jmp short loc_1BFEB
    _STOP_("db 90h");                           //db 90h
loc_1BFE9:                                      //loc_1BFE9:
    _cx -= _ax;                                 //sub cx, ax
loc_1BFEB:                                      //loc_1BFEB:
    _cx &= 0x1ff0;                              //and cx, 1FF0h
    _cx >>= 1;                                  //shr cx, 1
    _cx >>= 1;                                  //shr cx, 1
    _cx >>= 1;                                  //shr cx, 1
    _cx >>= 1;                                  //shr cx, 1
loc_1BFF7:                                      //loc_1BFF7:
    _flags.interrupt = true;                    //sti
    _dx = 0x0201;                               //mov dx, 201h
    _push(_cx);                                 //push cx
    _push(_ax);                                 //push ax
    _cx = 0x04ff;                               //mov cx, 4FFh
loc_1C000:                                      //loc_1C000:
    _in(_al, _dx);                              //in al, dx
    if (--_cx && _al & 0x0f)                    //loopne loc_1C000
      goto loc_1C000;
    _ax = _pop();                               //pop ax
    _cx = _pop();                               //pop cx
    _dx = _pop();                               //pop dx
}

void sub_1C0A8()
{
    _indirectCall(_ds, memory16(_ds, 0x26));    //call word ptr ds:26h
    _bx = 0xbc80;                               //mov bx, 0BC80h
    sub_19C43();                                //call sub_19C43
    _indirectCall(_ds, memory16(_ds, 0x1C));    //call word ptr ds:1Ch
    _bx = 0xbc80;                               //mov bx, 0BC80h
    sub_19C43();                                //call sub_19C43
    _indirectCall(_ds, memory16(_ds, 0x1C));    //call word ptr ds:1Ch
loc_1C0C0:                                      //loc_1C0C0:
    sub_1BF7C();                                //call sub_1BF7C
    _bx &= 0x0003;                              //and bx, 3
    if (_bx != 0)                               //jnz short loc_1C0C0
      goto loc_1C0C0;
loc_1C0C8:                                      //loc_1C0C8:
    sub_1BF7C();                                //call sub_1BF7C
    _bx &= 0x0003;                              //and bx, 3
    if (_bx == 0)                               //jz short loc_1C0C8
      goto loc_1C0C8;
    memory16(_ds, 0xBC98) = _cx;                //mov ds:0BC98h, cx
    memory16(_ds, 0xBC9A) = _dx;                //mov ds:0BC9Ah, dx
    _indirectCall(_ds, memory16(_ds, 0x26));    //call word ptr ds:26h
    _bx = 0xbc88;                               //mov bx, 0BC88h
    sub_19C43();                                //call sub_19C43
    _indirectCall(_ds, memory16(_ds, 0x1C));    //call word ptr ds:1Ch
    _bx = 0xbc88;                               //mov bx, 0BC88h
    sub_19C43();                                //call sub_19C43
    _indirectCall(_ds, memory16(_ds, 0x1C));    //call word ptr ds:1Ch
loc_1C0F0:                                      //loc_1C0F0:
    sub_1BF7C();                                //call sub_1BF7C
    _bx &= 0x0003;                              //and bx, 3
    if (_bx != 0)                               //jnz short loc_1C0F0
      goto loc_1C0F0;
loc_1C0F8:                                      //loc_1C0F8:
    sub_1BF7C();                                //call sub_1BF7C
    _bx &= 0x0003;                              //and bx, 3
    if (_bx == 0)                               //jz short loc_1C0F8
      goto loc_1C0F8;
    memory16(_ds, 0xBC9C) = _cx;                //mov ds:0BC9Ch, cx
    memory16(_ds, 0xBC9E) = _dx;                //mov ds:0BC9Eh, dx
    _indirectCall(_ds, memory16(_ds, 0x26));    //call word ptr ds:26h
    _bx = 0xbc90;                               //mov bx, 0BC90h
    sub_19C43();                                //call sub_19C43
    _indirectCall(_ds, memory16(_ds, 0x1C));    //call word ptr ds:1Ch
    _bx = 0xbc90;                               //mov bx, 0BC90h
    sub_19C43();                                //call sub_19C43
    _indirectCall(_ds, memory16(_ds, 0x1C));    //call word ptr ds:1Ch
loc_1C120:                                      //loc_1C120:
    sub_1BF7C();                                //call sub_1BF7C
    _bx &= 0x0003;                              //and bx, 3
    if (_bx != 0)                               //jnz short loc_1C120
      goto loc_1C120;
loc_1C128:                                      //loc_1C128:
    sub_1BF7C();                                //call sub_1BF7C
    _bx &= 0x0003;                              //and bx, 3
    if (_bx == 0)                               //jz short loc_1C128
      goto loc_1C128;
    memory16(_ds, 0xBCA0) = _cx;                //mov ds:0BCA0h, cx
    memory16(_ds, 0xBCA2) = _dx;                //mov ds:0BCA2h, dx
    _ax = memory16(_ds, 0xBC9C);                //mov ax, ds:0BC9Ch
    _ax = _ax - memory16(_ds, 0xBC98);          //sub ax, ds:0BC98h
    _bx = memory16(_ds, 0xBC9E);                //mov bx, ds:0BC9Eh
    _bx = _bx - memory16(_ds, 0xBC9A);          //sub bx, ds:0BC9Ah
    _dl = 0x06;                                 //mov dl, 6
    _idiv(_dl);                                 //idiv dl
    _ax &= 0x00ff;                              //and ax, 0FFh
    _cbw();                                     //cbw
    _push(_ax);                                 //push ax
    _ax = _bx;                                  //mov ax, bx
    _dl = 0x06;                                 //mov dl, 6
    _idiv(_dl);                                 //idiv dl
    _al &= 0xff;                                //and al, 0FFh
    _cbw();                                     //cbw
    _bx = _ax;                                  //mov bx, ax
    _ax = _pop();                               //pop ax
    memory16(_ds, 0xBCA4) = _ax;                //mov ds:0BCA4h, ax
    memory16(_ds, 0xBCA6) = _bx;                //mov ds:0BCA6h, bx
}

void sub_1C164()
{
    WORD _cs = _seg001;

    sub_1C0A8();                                //call sub_1C0A8
    sub_1BF7C();                                //call sub_1BF7C
    _cx |= _dx;                                 //or cx, dx
    if (_cx != 0)                               //jnz short loc_1C175
      goto loc_1C175;
    memory(_cs, 0xBDA2) = 0xc3;                 //mov byte ptr cs:loc_1C1A2, 0C3h
    return;                                     //retn
loc_1C175:                                      //loc_1C175:
    _ax = memory16(_ds, 0xBCA0);                //mov ax, ds:0BCA0h
    _dx = memory16(_ds, 0xBCA4);                //mov dx, ds:0BCA4h
    _ax += _dx;                                 //add ax, dx
    memory16(_ds, 0xB87E) = _ax;                //mov ds:0B87Eh, ax
    _ax = memory16(_ds, 0xBCA0);                //mov ax, ds:0BCA0h
    _dx = -_dx;                                 //neg dx
    _ax += _dx;                                 //add ax, dx
    memory16(_ds, 0xB880) = _ax;                //mov ds:0B880h, ax
    _ax = memory16(_ds, 0xBCA2);                //mov ax, ds:0BCA2h
    _dx = memory16(_ds, 0xBCA6);                //mov dx, ds:0BCA6h
    _ax += _dx;                                 //add ax, dx
    memory16(_ds, 0xB87C) = _ax;                //mov ds:0B87Ch, ax
    _ax = memory16(_ds, 0xBCA2);                //mov ax, ds:0BCA2h
    _dx = -_dx;                                 //neg dx
    _ax += _dx;                                 //add ax, dx
    memory16(_ds, 0xB87A) = _ax;                //mov ds:0B87Ah, ax
}

void loc_1C1A2()
{
    _ax = _seg001;                              //mov ax, seg seg001
}

void sub_1C1A5()
{
    _ds = _ax;                                  //mov ds, ax
    sub_1BF7C();                                //call sub_1BF7C
    _bx &= 0x0003;                              //and bx, 3
    if (_bx == 0)                               //jz short loc_1C1B7
      goto loc_1C1B7;
    _bx = _bx ^ _bx;                            //xor bx, bx
    _bl |= 0x10;                                //or bl, 10h
    goto loc_1C1B9;                             //jmp short loc_1C1B9
    _STOP_("db 90h");                           //db 90h
loc_1C1B7:                                      //loc_1C1B7:
    _bx = _bx ^ _bx;                            //xor bx, bx
loc_1C1B9:                                      //loc_1C1B9:
    if (_cx < memory16(_ds, 0xB87E))            //jb short loc_1C1C5
      goto loc_1C1C5;
    _bl |= 0x01;                                //or bl, 1
    goto loc_1C1CE;                             //jmp short loc_1C1CE
    _STOP_("db 90h");                           //db 90h
loc_1C1C5:                                      //loc_1C1C5:
    if (_cx >= memory16(_ds, 0xB880))           //jnb short loc_1C1CE
      goto loc_1C1CE;
    _bl |= 0x02;                                //or bl, 2
loc_1C1CE:                                      //loc_1C1CE:
    if (_dx >= memory16(_ds, 0xB87A))           //jnb short loc_1C1DA
      goto loc_1C1DA;
    _bl |= 0x08;                                //or bl, 8
    goto loc_1C1E3;                             //jmp short loc_1C1E3
loc_1C1DA:                                      //loc_1C1DA:
    if (_dx < memory16(_ds, 0xB87C))            //jb short loc_1C1E3
      goto loc_1C1E3;
    _bl |= 0x04;                                //or bl, 4
loc_1C1E3:                                      //loc_1C1E3:
    memory(_ds, 0xB882) = _bl;                  //mov byte_1BC74+0Eh, bl
    _bh = memory(_ds, 0xB886);                  //mov bh, byte_1BC86
    _bl |= _bh;                                 //or bl, bh
    memory(_ds, 0xB884) = _bl;                  //mov byte_1BC84, bl
}

void start()
{
    WORD _cs = _seg001;

    _flags.direction = false;                   //cld
    _ah = 0x4a;                                 //mov ah, 4Ah
    _bx = 0x0e00;                               //mov bx, 0E00h
    _interrupt(33);                             //int 21h
    if (!_flags.carry)                          //jnb short loc_1C283
      goto loc_1C283;
    _STOP_("goto loc_19731");                   //jmp loc_19731
loc_1C283:                                      //loc_1C283:
    _ax = _cs;                                  //mov ax, cs
    _es = _ax;                                  //mov es, ax
    _si = 0x0080;                               //mov si, 80h
    _di = _seg001;                              //mov di, seg seg001
    _es = _di;                                  //mov es, di
    _di = 0xbdf6;                               //mov di, 0BDF6h
    _cl = memory(_ds, _si);                     //mov cl, [si]
    _ch = _ch ^ _ch;                            //xor ch, ch
    _cx += 1;                                   //inc cx
    _flags.direction = false;                   //cld
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _push(_es);                                 //push es
    _ds = _pop();                               //pop ds
    _si = 0xbdf6;                               //mov si, 0BDF6h
    _cx = 0x0080;                               //mov cx, 80h
loc_1C2A2:                                      //loc_1C2A2:
    _al = memory(_ds, _si);                     //mov al, [si]
    _si += 1;                                   //inc si
    if (_al == 0x2f)                            //jz short loc_1C2AE
      goto loc_1C2AE;
loc_1C2A9:                                      //loc_1C2A9:
    if (--_cx)                                  //loop loc_1C2A2
      goto loc_1C2A2;
    goto loc_1C2E2;                             //jmp short loc_1C2E2
loc_1C2AE:                                      //loc_1C2AE:
    _al = memory(_ds, _si);                     //mov al, [si]
    if (_al == 0x63)                            //jz short loc_1C2D3
      goto loc_1C2D3;
    if (_al == 0x43)                            //jz short loc_1C2D3
      goto loc_1C2D3;
    if (_al == 0x65)                            //jz short loc_1C2CA
      goto loc_1C2CA;
    if (_al == 0x45)                            //jz short loc_1C2CA
      goto loc_1C2CA;
    if (_al == 0x74)                            //jz short loc_1C2E5
      goto loc_1C2E5;
    if (_al == 0x54)                            //jz short loc_1C2E5
      goto loc_1C2E5;
    goto loc_1C2A9;                             //jmp short loc_1C2A9
loc_1C2CA:                                      //loc_1C2CA:
    memory16(_ds, 0x2F67) = 0x2f4f;             //mov word_13367, 2F4Fh
    goto loc_1C2E2;                             //jmp short loc_1C2E2
    _STOP_("db 90h");                           //db 90h
loc_1C2D3:                                      //loc_1C2D3:
    memory16(_ds, 0x2F67) = 0x2f57;             //mov word_13367, 2F57h
    goto loc_1C2E2;                             //jmp short loc_1C2E2
    memory16(_ds, 0x2F67) = 0x2f5f;             //mov word_13367, 2F5Fh
loc_1C2E2:                                      //loc_1C2E2:
    sub_1C4BD();                                //call sub_1C4BD
loc_1C2E5:                                      //loc_1C2E5:
    off_10402();                                //call off_10402
    _si = 0xbdf6;                               //mov si, 0BDF6h
    _cx = 0x0080;                               //mov cx, 80h
loc_1C2EF:                                      //loc_1C2EF:
    _al = memory(_ds, _si);                     //mov al, [si]
    _si += 1;                                   //inc si
    if (_al == 0x2f)                            //jz short loc_1C308
      goto loc_1C308;
    if (--_cx)                                  //loop loc_1C2EF
      goto loc_1C2EF;
    _push(_ds);                                 //push ds
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    memory16(_ds, 0xAB2B) = 0x0000;             //mov word_1AF2B, 0
    _ds = _pop();                               //pop ds
    goto loc_1C31F;                             //jmp short loc_1C31F
loc_1C308:                                      //loc_1C308:
    _al = memory(_ds, _si);                     //mov al, [si]
    if (_al == 0x61)                            //jz short loc_1C312
      goto loc_1C312;
    if (_al != 0x41)                            //jnz short loc_1C31F
      goto loc_1C31F;
loc_1C312:                                      //loc_1C312:
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    memory16(_ds, 0xAB2B) = 0x0001;             //mov word_1AF2B, 1
loc_1C31F:                                      //loc_1C31F:
    sub_196DD();                                //call sub_196DD
    sub_1AE81();                                //call sub_1AE81
    memory(_ds, 0xA860) = 0x01;                 //mov byte_1AC60, 1
    nullsub_5();                                //call nullsub_5
    off_1042A();                                //call off_1042A
    off_10408();                                //call off_10408
    sub_1A44F();                                //call sub_1A44F
    off_1040A();                                //call off_1040A
    off_1043A();                                //call off_1043A
    sub_1A592();                                //call sub_1A592
    sub_19E18();                                //call sub_19E18
    if (!_flags.carry)                          //jnb short loc_1C34B
      goto loc_1C34B;
    sub_1C164();                                //call sub_1C164
loc_1C34B:                                      //loc_1C34B:
    memory16(_ds, 0x95C4) = 0x0000;             //mov word_199C4, 0
    off_1043C();                                //call off_1043C
    memory16(_ds, 0xC0DF) = _sp;                //mov word_1C4DF, sp
loc_1C359:                                      //loc_1C359:
    _sp = memory16(_ds, 0xC0DF);                //mov sp, word_1C4DF
    off_1040A();                                //call off_1040A
    sub_1A592();                                //call sub_1A592
    off_1043A();                                //call off_1043A
    memory16(_ds, 0xBDF2) = 0x0003;             //mov word_1C1F2, 3
    _ax = memory16(_ds, 0xBDF2);                //mov ax, word_1C1F2
    sub_1AECD();                                //call sub_1AECD
    off_10428();                                //call off_10428
loc_1C378:                                      //loc_1C378:
    if (memory(_ds, 0xA85E) == 0xff)            //jz short loc_1C378
      goto loc_1C378;
    goto loc_1C398;                             //jmp short loc_1C398
loc_1C382:                                      //loc_1C382:
    if (memory(_ds, 0xA85E) == 0xff)            //jz short loc_1C395
      goto loc_1C395;
    memory16(_ds, 0xBDF2) = 0x0000;             //mov word_1C1F2, 0
    _ax = memory16(_ds, 0xBDF2);                //mov ax, word_1C1F2
    sub_1AECD();                                //call sub_1AECD
loc_1C395:                                      //loc_1C395:
    sub_16B9B();                                //call sub_16B9B
loc_1C398:                                      //loc_1C398:
    if (memory(_ds, 0xA85E) == 0xff)            //jz short loc_1C3AB
      goto loc_1C3AB;
    memory16(_ds, 0xBDF2) = 0x0000;             //mov word_1C1F2, 0
    _ax = memory16(_ds, 0xBDF2);                //mov ax, word_1C1F2
    sub_1AECD();                                //call sub_1AECD
loc_1C3AB:                                      //loc_1C3AB:
    sub_16CD7();                                //call sub_16CD7
    goto loc_1C382;                             //jmp short loc_1C382
}

void loc_1C3B0()
{
    WORD _cs = _seg001;

    memory16(_ds, 0x6614) = 0x0006;             //mov word_16A14, 6
    sub_199C8();                                //call sub_199C8
loc_1C3B9:                                      //loc_1C3B9:
    _sp = memory16(_ds, 0xC0DF);                //mov sp, word_1C4DF
    memory16(_ds, 0x6610) = 0x0006;             //mov word_16A10, 6
    memory16(_ds, 0x6612) = 0x0006;             //mov word_16A12, 6
    memory16(_ds, 0x7E00) = 0x0000;             //mov word_18200, 0
    memory16(_ds, 0x762D) = 0x0000;             //mov word_17A2D, 0
    memory16(_ds, 0x762F) = 0x0000;             //mov word_17A2F, 0
    sub_1A54A();                                //call sub_1A54A
    _push(_cs);                                 //push cs
    _ds = _pop();                               //pop ds
    sub_1A56B();                                //call sub_1A56B
    off_10404();                                //call off_10404
    off_10406();                                //call off_10406
    sub_1A45C();                                //call sub_1A45C
    sub_1C4E2();                                //call sub_1C4E2
    off_10442();                                //call off_10442
    off_10426();                                //call off_10426
    off_1043C();                                //call off_1043C
    off_10448();                                //call off_10448
    _ax = 0x0004;                               //mov ax, 4
    memory16(_ds, 0xBDF2) = _ax;                //mov word_1C1F2, ax
    sub_1AECD();                                //call sub_1AECD
    _ax = memory16(_ds, 0x8BEC);                //mov ax, word_18FEC
    _ax -= 1;                                   //dec ax
    _ax += _ax;                                 //add ax, ax
    _si = 0x2f69;                               //mov si, 2F69h
    _si += _ax;                                 //add si, ax
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    memory16(_ds, 0xBDF2) = _ax;                //mov word_1C1F2, ax
    sub_1AECD();                                //call sub_1AECD
    _ax = 0x0000;                               //mov ax, 0
    sub_1A257();                                //call sub_1A257
    sub_1A5F0();                                //call sub_1A5F0
    off_10426();                                //call off_10426
    sub_19420();                                //call sub_19420
    memory16(_ds, 0x973C) = 0x3245;             //mov word_19B3C, 3245h
    memory16(_ds, 0x973E) = 0x5432;             //mov word_19B3E, 5432h
loc_1C439:                                      //loc_1C439:
    memory16(_ds, 0x7E16) = 0x0000;             //mov word_18216, 0
    memory16(_ds, 0x7E18) = 0x0000;             //mov word_18218, 0
loc_1C445:                                      //loc_1C445:
    sub_16B3B();                                //call sub_16B3B
    if (memory16(_ds, 0x7E18) != 0x0001)        //jnz short loc_1C467
      goto loc_1C467;
    memory16(_ds, 0x762F) = 0x0000;             //mov word_17A2F, 0
    sub_1618F();                                //call sub_1618F
    sub_19462();                                //call sub_19462
    if (memory16(_ds, 0x6614) != 0x0000)        //jnz short loc_1C465
      goto loc_1C465;
{loc_19F12(); return; };                        //
loc_1C465:                                      //loc_1C465:
    goto loc_1C439;                             //jmp short loc_1C439
loc_1C467:                                      //loc_1C467:
    sub_19BAC();                                //call sub_19BAC
    sub_15F40();                                //call sub_15F40
    memory(_ds, 0x5B3E) = 0x00;                 //mov byte_15F3E, 0
    sub_169E3();                                //call sub_169E3
    sub_168E4();                                //call sub_168E4
    sub_17205();                                //call sub_17205
    sub_18351();                                //call sub_18351
    sub_18CBE();                                //call sub_18CBE
    sub_18D28();                                //call sub_18D28
    sub_1705D();                                //call sub_1705D
    off_1041E();                                //call off_1041E
    off_10424();                                //call off_10424
    off_1043E();                                //call off_1043E
    off_1041C();                                //call off_1041C
    sub_19AF6();                                //call sub_19AF6
    off_10438();                                //call off_10438
    sub_194C4();                                //call sub_194C4
    if (memory(_ds, 0xB888) != 0x10)            //jnz short loc_1C4B3
      goto loc_1C4B3;
    sub_19F8A();                                //call sub_19F8A
    if (_FIXME_)                                //jnb short loc_1C4B3
      goto loc_1C4B3;
    _STOP_("goto loc_1C359");                   //jmp loc_1C359
loc_1C4B3:                                      //loc_1C4B3:
    if (memory(_ds, 0xB888) != 0x01)            //jnz short loc_1C445
      goto loc_1C445;
{loc_196F3(); return; };                        //
}

void sub_1C4BD()
{
    WORD _cs = _seg001;

    _ax = _cs;                                  //mov ax, cs
    _cx = 0x0000;                               //mov cx, 0
    _dx = memory16(_ds, 0x2F67);                //mov dx, word_13367
    sub_1A65B();                                //call sub_1A65B
}

void sub_1C4CA()
{
    loc_1C1A2();                                //call loc_1C1A2
    _al = memory(_ds, 0xB884);                  //mov al, byte_1BC84
}

void sub_1C4E2()
{
    _ax = memory16(_ds, 0x6614);                //mov ax, word_16A14
    _ax += 1;                                   //inc ax
    if ((short)_ax > (short)0x0006)             //jg short locret_1C4EE
      goto locret_1C4EE;
    memory16(_ds, 0x6614) = _ax;                //mov word_16A14, ax
locret_1C4EE:                                   //locret_1C4EE:
    return;
}


// imports
void loc_1A6CE() { _ASSERT(0); }
void loc_1A6E0() { _ASSERT(0); }
void nullsub_5() { _ASSERT(0); }
void off_10402() { _ASSERT(0); }
void off_10404() { _ASSERT(0); }
void off_10406() { _ASSERT(0); }
void off_10408() { _ASSERT(0); }
void off_1040A() { _ASSERT(0); }
void off_1040C() { _ASSERT(0); }
void off_1040E() { _ASSERT(0); }
void off_1041A() { _ASSERT(0); }
void off_1041C() { _ASSERT(0); }
void off_1041E() { _ASSERT(0); }
void off_10424() { _ASSERT(0); }
void off_10426() { _ASSERT(0); }
void off_10428() { _ASSERT(0); }
void off_1042A() { _ASSERT(0); }
void off_10438() { _ASSERT(0); }
void off_1043A() { _ASSERT(0); }
void off_1043C() { _ASSERT(0); }
void off_1043E() { _ASSERT(0); }
void off_10442() { _ASSERT(0); }
void off_10446() { _ASSERT(0); }
void off_10448() { _ASSERT(0); }

