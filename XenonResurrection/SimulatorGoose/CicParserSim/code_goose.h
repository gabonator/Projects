void start();
void sub_100A9();
void sub_100CF();
void sub_100FD();
void sub_10442();
void sub_10588();
void sub_10591();
void sub_105EC();
void sub_10600();
void sub_12762();
void sub_1333C();
void sub_1382A();
void sub_10103();
void sub_101C0();
void sub_10637();
void sub_10644();
void sub_10B8E();
void sub_10DA7();
void sub_10FDA();
void sub_121DC();
void sub_1220D();
void sub_131A4();
void sub_132FE();
void sub_13383();
void sub_133B3();
void sub_133D7();
void sub_13423();
void sub_134A8();
void sub_1019D();
void sub_101AD();
void sub_1033B();
void sub_10529();
void sub_1064D();
void sub_1069A();
void sub_109A4();
void sub_10BDC();
void sub_10D98();
void sub_10DC0();
void sub_10E07();
void sub_10E3D();
void sub_10E84();
void sub_10F3C();
void sub_110C6();
void sub_110F3();
void sub_11108();
void sub_112A7();
void sub_112CB();
void sub_112EB();
void sub_11384();
void sub_113A8();
void sub_11429();
void sub_114F0();
void sub_115FC();
void sub_116D6();
void sub_116DF();
void sub_116FE();
void sub_1171F();
void sub_11740();
void sub_1176C();
void sub_11783();
void sub_117AC();
void sub_117D6();
void sub_117F4();
void sub_118A9();
void sub_118C7();
void sub_11993();
void sub_119C2();
void sub_11A9E();
void sub_11B09();
void sub_11B4A();
void sub_12200();
void sub_122B1();
void sub_1239B();
void sub_12464();
void sub_1252F();
void sub_12542();
void sub_12577();
void sub_1258A();
void sub_125BF();
void sub_125D2();
void sub_1264A();
void sub_1269E();
void sub_12714();
void sub_1279F();
void sub_128DA();
void sub_129DB();
void sub_12A7F();
void sub_12C45();
void sub_12CEA();
void sub_12E02();
void sub_12F50();
void sub_12FE8();
void sub_1300A();
void sub_131E7();
void sub_13209();
void sub_13439();
void sub_13472();
void sub_13498();
void sub_135BC();
void sub_136D4();
void sub_13840();
void sub_139B8();


// imports
void sub_104F3();
void sub_10541();
void sub_10674();
void sub_107AF();
void sub_107FD();
void sub_108BA();
void sub_10A51();
void sub_10AD5();
void sub_10B58();
void sub_10B7C();
void sub_10BC5();
void sub_10C24();
void sub_10F9D();
void sub_110A0();
void sub_1196F();
void sub_11A04();
void sub_11B57();
void sub_11B80();
void sub_11BB9();
void sub_11C0A();
void sub_11C33();
void sub_11C56();
void sub_11C78();
void sub_11CD9();
void sub_11D1E();
void sub_11DEF();
void sub_11F0B();
void sub_11FBA();
void sub_12005();
void sub_12047();
void sub_12092();
void sub_12099();
void sub_120DB();
void sub_120F0();
void sub_12121();
void sub_1215B();
void sub_122C1();
void sub_122E1();
void sub_122F9();
void sub_12311();
void sub_12329();
void sub_1237C();
void sub_1250B();
void sub_12536();
void sub_12553();
void sub_1257E();
void sub_1259B();
void sub_125C6();
void sub_12662();
void sub_12676();
void sub_12809();
void sub_12907();
void sub_12959();
void sub_12A64();
void sub_12B28();
void sub_12C07();
void sub_12C9A();
void sub_12D9A();
void sub_12DDC();
void sub_12DF6();
void sub_13059();
void sub_13084();
void sub_1309D();
void sub_13130();
void sub_13291();
void sub_133E5();
void sub_13801();
void sub_13914();

void sub_123D4();;
void sub_123EC();;
void sub_12404();;
void sub_1241C();;
void sub_12434();;
void sub_1244C();;


void start()
{
    _ax = _dseg;                                  //mov ax, seg dseg
    _ds = _ax;                                    //mov ds, ax
    _bx = 0x9670;                                 //mov bx, 9670h
    _bx += 0x0f;                                  //add bx, 0Fh
    _bx >>= 1;                                    //shr bx, 1
    _bx >>= 1;                                    //shr bx, 1
    _bx >>= 1;                                    //shr bx, 1
    _bx >>= 1;                                    //shr bx, 1
    _ax += _bx;                                   //add ax, bx
    memory16(_ds, 0x94E8) = _ax;                  //mov word_1CF38, ax
    _ax += 0x0800;                                //add ax, 800h
    memory16(_ds, 0x94EA) = _ax;                  //mov word_1CF3A, ax
    _ax += 0x0800;                                //add ax, 800h
    memory16(_ds, 0x94EC) = _ax;                  //mov word_1CF3C, ax
    _ax += 0x0800;                                //add ax, 800h
    memory16(_ds, 0x94EE) = _ax;                  //mov word_1CF3E, ax
    _ax += 0x0800;                                //add ax, 800h
    memory16(_ds, 0x94F0) = _ax;                  //mov word_1CF40, ax
    _ax += 0x0800;                                //add ax, 800h
    memory16(_ds, 0x94F2) = _ax;                  //mov word_1CF42, ax
    _ax += 0x0800;                                //add ax, 800h
    memory16(_ds, 0x94F4) = _ax;                  //mov word_1CF44, ax
    _ax += 0x0800;                                //add ax, 800h
    memory16(_ds, 0x94F6) = _ax;                  //mov word_1CF46, ax
    _interrupt(0x12);                             //int 12h
    if (_ax >= 0x0200)                            //jnb short loc_10067
      goto loc_10067;
    _dx = 0x0007;                                 //mov dx, 7
    _ah = 0x09;                                   //mov ah, 9
    _interrupt(0x21);                             //int 21h
    _ax = 0x4c00;                                 //mov ax, 4C00h
    _interrupt(0x21);                             //int 21h
    goto loc_1006E;                               //jmp short loc_1006E
loc_10067:                                        //loc_10067:
    _dx = 0x2a;                                   //mov dx, 2Ah
    _ah = 0x09;                                   //mov ah, 9
    _interrupt(0x21);                             //int 21h
loc_1006E:                                        //loc_1006E:
    sub_10600();                                  //call sub_10600
    sub_1333C();                                  //call sub_1333C
    sub_12762();                                  //call sub_12762
    sub_105EC();                                  //call sub_105EC
    sub_10442();                                  //call sub_10442
    sub_10588();                                  //call sub_10588
    sub_10591();                                  //call sub_10591
    sub_1382A();                                  //call sub_1382A
    memory(_ds, 0x9501) = 0;                      //mov byte_1CF51, 0
loc_1008B:                                        //loc_1008B:
    sub_100A9();                                  //call sub_100A9
    sub_100CF();                                  //call sub_100CF
    sub_100FD();                                  //call sub_100FD
    goto loc_1008B;                               //jmp short loc_1008B
}

void sub_100A9()
{
    sub_10103();                                  //call sub_10103
    memory(_ds, 0x9500) = 0;                      //mov byte_1CF50, 0
    memory(_ds, 0x94FE) = 1;                      //mov byte_1CF4E, 1
    memory(_ds, 0x94FC) = 0x10;                   //mov byte ptr word_1CF4C, 10h
    memory(_ds, 0x94FF) = 0;                      //mov byte_1CF4F, 0
    memory(_ds, 0x9502) = 0;                      //mov byte_1CF52, 0
    sub_10DA7();                                  //call sub_10DA7
    sub_13423();                                  //call sub_13423
    sub_121DC();                                  //call sub_121DC
}

void sub_100CF() // Main game loop
{
label_begin:
    sub_101C0();                                  //call sub_101C0
    sub_10FDA();                                  //call sub_10FDA
    _al = memory(_ds, 0x94FF);                    //mov al, byte_1CF4F
    if (_al != 0x00)                              //jnz short loc_100E4
      goto loc_100E4;
    sub_132FE();                                  //call sub_132FE
    sub_10B8E();                                  //call sub_10B8E
    goto loc_100ED;                               //jmp short loc_100ED
loc_100E4:                                        //loc_100E4:
    sub_134A8();                                  //call sub_134A8
    sub_131A4();                                  //call sub_131A4
    sub_10B8E();                                  //call sub_10B8E
loc_100ED:                                        //loc_100ED:
    sub_1220D();                                  //call sub_1220D
    sub_13383();                                  //call sub_13383
    _al = memory(_ds, 0x9500);                    //mov al, byte_1CF50
    if (_al != 0x00)                              //jnz short locret_100FC
      goto locret_100FC;
    // inject loop
    goto label_begin;
locret_100FC:                                     //locret_100FC:
    return;
}

void sub_100FD()
{
    memory(_ds, 0x3A56) = 1;                      //mov byte_13A56, 1
}

void sub_10442()
{
    WORD _cs = _seg000;
    memory16(_ds, 0x8F0B) = 0;                    //mov word_1C95B, 0
    memory16(_ds, 0x8F0D) = 0x4b;                 //mov word_1C95D, 4Bh
    memory16(_ds, 0x8F0F) = 0x4d;                 //mov word_1C95F, 4Dh
    memory16(_ds, 0x8F11) = 0x48;                 //mov word_1C961, 48h
    memory16(_ds, 0x8F13) = 0x50;                 //mov word_1C963, 50h
    memory16(_ds, 0x8F15) = 0x39;                 //mov word_1C965, 39h
    memory16(_ds, 0x8F17) = 0x31;                 //mov word_1C967, 31h
    memory16(_ds, 0x8F19) = 0x32;                 //mov word_1C969, 32h
    memory16(_ds, 0x8F1B) = 0x10;                 //mov word_1C96B, 10h
    _ax = _ds;                                    //mov ax, ds
    _es = _ax;                                    //mov es, ax
    _ax = 0x0000;                                 //mov ax, 0
    _cx = 0x40;                                   //mov cx, 40h
    _di = 0x8e8a;                                 //mov di, 8E8Ah
    _rep_stosw<MemAuto, DirAuto>();               //rep stosw
    _al = 0x09;                                   //mov al, 9
    _ah = 0x35;                                   //mov ah, 35h
    _interrupt(0x21);                             //int 21h
    memory16(_ds, 0x8E84) = _bx;                  //mov word_1C8D4, bx
    memory16(_ds, 0x8E82) = _es;                  //mov word_1C8D2, es
    _push(_ds);                                   //push ds
    _dx = 0x04b7;                                 //mov dx, 4B7h
    _ax = _cs;                                    //mov ax, cs
    _ds = _ax;                                    //mov ds, ax
    _al = 0x09;                                   //mov al, 9
    _ah = 0x25;                                   //mov ah, 25h
    _interrupt(0x21);                             //int 21h
    _ds = _pop();                                 //pop ds
}

void sub_10588()
{
    _ax = 0x0000;                                 //mov ax, 0
    _interrupt(0x33);                             //int 33h
    memory(_ds, 0x8F0A) = _al;                    //mov byte_1C95A, al
}

void sub_10591()
{
    WORD _cs = _seg000;
    _al = 0x1c;                                   //mov al, 1Ch
    _ah = 0x35;                                   //mov ah, 35h
    _interrupt(0x21);                             //int 21h
    memory16(_ds, 0x8E88) = _bx;                  //mov word_1C8D8, bx
    memory16(_ds, 0x8E86) = _es;                  //mov word_1C8D6, es
    _push(_ds);                                   //push ds
    _dx = 0x05ce;                                 //mov dx, 5CEh
    _ax = _cs;                                    //mov ax, cs
    _ds = _ax;                                    //mov ds, ax
    _al = 0x1c;                                   //mov al, 1Ch
    _ah = 0x25;                                   //mov ah, 25h
    _interrupt(0x21);                             //int 21h
    _ds = _pop();                                 //pop ds
    _al = 0x36;                                   //mov al, 36h
    _out(0x43, _al);                              //out 43h, al
    _ax = 0x4d0e;                                 //mov ax, 4D0Eh
    _out(0x40, _al);                              //out 40h, al
    _al = _ah;                                    //mov al, ah
    _out(0x40, _al);                              //out 40h, al
}

void sub_105EC()
{
    WORD _cs = _seg000;
    _push(_ds);                                   //push ds
    _dx = 0x05fc;                                 //mov dx, 5FCh
    _ax = _cs;                                    //mov ax, cs
    _ds = _ax;                                    //mov ds, ax
    _al = 0x24;                                   //mov al, 24h
    _ah = 0x25;                                   //mov ah, 25h
    _interrupt(0x21);                             //int 21h
    _ds = _pop();                                 //pop ds
}

void sub_10600()
{
    _dx = 0x01e2;                                 //mov dx, 1E2h
    _ax = memory16(_ds, 0x94E8);                  //mov ax, word_1CF38
    sub_10637();                                  //call sub_10637
    _dx = 0x01ea;                                 //mov dx, 1EAh
    _ax = memory16(_ds, 0x94EA);                  //mov ax, word_1CF3A
    sub_10637();                                  //call sub_10637
    _dx = 0x01f2;                                 //mov dx, 1F2h
    _ax = memory16(_ds, 0x94EC);                  //mov ax, word_1CF3C
    sub_10637();                                  //call sub_10637
    _dx = 0x01f9;                                 //mov dx, 1F9h
    _ax = memory16(_ds, 0x94EE);                  //mov ax, word_1CF3E
    sub_10637();                                  //call sub_10637
    _dx = 0x0203;                                 //mov dx, 203h
    _ax = memory16(_ds, 0x94F0);                  //mov ax, word_1CF40
    sub_10637();                                  //call sub_10637
    _dx = 0x020b;                                 //mov dx, 20Bh
    _ax = memory16(_ds, 0x94F2);                  //mov ax, word_1CF42
    sub_10637();                                  //call sub_10637
}

void sub_12762()
{
    _cx = 0x12;                                   //mov cx, 12h
    _ax = _ds;                                    //mov ax, ds
    _es = _ax;                                    //mov es, ax
    _di = 0x94af;                                 //mov di, 94AFh
    _flags.direction = false;                     //cld
    _ax = 0x0000;                                 //mov ax, 0
    _rep_stosw<MemAuto, DirAuto>();               //rep stosw
    _cx = 0x2a;                                   //mov cx, 2Ah
    _di = 0x9455;                                 //mov di, 9455h
    _al = 0x2e;                                   //mov al, 2Eh
    _ah = 0x2e;                                   //mov ah, 2Eh
    _rep_stosw<MemAuto, DirAuto>();               //rep stosw
    memory(_ds, 0x9455) = 0x5f;                   //mov byte_1CEA5, 5Fh
    _al = 0x00;                                   //mov al, 0
    _cx = 0x0007;                                 //mov cx, 7
    _si = 0x94da;                                 //mov si, 94DAh
loc_1278B:                                        //loc_1278B:
    memory(_ds, _si) = _al;                       //mov [si], al
    _al += 1;                                     //inc al
    _si += 1;                                     //inc si
    if (--_cx)                                    //loop loc_1278B
      goto loc_1278B;
    _di = 0x9455;                                 //mov di, 9455h
    _dx = 0x1506;                                 //mov dx, 1506h
    _cx = 0x8c;                                   //mov cx, 8Ch
    sub_10644();                                  //call sub_10644
}

void sub_1333C()
{
    _ax = 0x0d;                                   //mov ax, 0Dh
    _interrupt(0x10);                             //int 10h
    _ax = 0xa000;                                 //mov ax, 0A000h
    memory16(_ds, 0x94FA) = _ax;                  //mov word_1CF4A, ax
    _ax += 0x0200;                                //add ax, 200h
    memory16(_ds, 0x94F8) = _ax;                  //mov word_1CF48, ax
    _ax = 0x0000;                                 //mov ax, 0
    sub_133B3();                                  //call sub_133B3
    _ax = memory16(_ds, 0x94F8);                  //mov ax, word_1CF48
    _bx = memory16(_ds, 0x94FA);                  //mov bx, word_1CF4A
    memory16(_ds, 0x94F8) = _bx;                  //mov word_1CF48, bx
    memory16(_ds, 0x94FA) = _ax;                  //mov word_1CF4A, ax
    sub_133D7();                                  //call sub_133D7
    _bx = memory16(_ds, 0x94FA);                  //mov bx, word_1CF4A
    _bx <<= 1;                                    //shl bx, 1
    _bx <<= 1;                                    //shl bx, 1
    _bx <<= 1;                                    //shl bx, 1
    _bx <<= 1;                                    //shl bx, 1
    _flags.interrupt = false;                     //cli
    _dx = 0x03d4;                                 //mov dx, 3D4h
    _ah = _bh;                                    //mov ah, bh
    _al = 0x0c;                                   //mov al, 0Ch
    _out(_dx, _ax);                               //out dx, ax
    _ah = _bl;                                    //mov ah, bl
    _al += 1;                                     //inc al
    _out(_dx, _ax);                               //out dx, ax
    _flags.interrupt = true;                      //sti
    sub_133D7();                                  //call sub_133D7
}

void sub_1382A()
{
    _al = 0x00;                                   //mov al, 0
    memory(_ds, 0x9550) = _al;                    //mov byte_1CFA0, al
    memory(_ds, 0x9551) = _al;                    //mov byte_1CFA1, al
    memory(_ds, 0x9552) = _al;                    //mov byte_1CFA2, al
    memory(_ds, 0x9506) = 1;                      //mov byte_1CF56, 1
    memory(_ds, 0x9505) = 0;                      //mov byte_1CF55, 0
}

void sub_10103()
{
    _al = memory(_ds, 0x3A56);                    //mov al, byte_13A56
    if (_al == 0x00)                              //jz short loc_10115
      goto loc_10115;
    memory16(_ds, 0x8E7E) = 0xda;                 //mov word_1C8CE, 0DAh
    sub_1279F();                                  //call sub_1279F
    goto loc_1011E;                               //jmp short loc_1011E
loc_10115:                                        //loc_10115:
    memory16(_ds, 0x8E7E) = 0xe9;                 //mov word_1C8CE, 0E9h
    sub_128DA();                                  //call sub_128DA
loc_1011E:                                        //loc_1011E:
    sub_139B8();                                  //call sub_139B8
    sub_13472();                                  //call sub_13472
    memory(_ds, 0x9503) = 1;                      //mov byte_1CF53, 1
    memory16(_ds, 0x8E80) = 0;                    //mov word_1C8D0, 0
    sub_10D98();                                  //call sub_10D98
loc_10132:                                        //loc_10132:     -- intro loop begin
    sub_101C0();                                  //call sub_101C0
    sub_10FDA();                                  //call sub_10FDA
    sub_13498();                                  //call sub_13498 -- clear scr
    sub_10B8E();                                  //call sub_10B8E
    sub_13383();                                  //call sub_13383 -- swap pages
    _ax = memory16(_ds, 0x954C);                  //mov ax, word_1CF9C
    if (_ax & 0x80)                               //jnz short loc_10197
      goto loc_10197;
    memory16(_ds, 0x8E80) += 1;                   //inc word_1C8D0
    _bx = memory16(_ds, 0x8E80);                  //mov bx, word_1C8D0
    if (_bx & 0x0007)                             //jnz short loc_10195
      goto loc_10195;
    _bx >>= 1;                                    //shr bx, 1
    _bx >>= 1;                                    //shr bx, 1
    _bx >>= 1;                                    //shr bx, 1
    _bx = _bx + memory16(_ds, 0x8E7E);            //add bx, word_1C8CE
    _al = memory(_ds, _bx);                       //mov al, [bx]
    if (_al == 0x00)                              //jz short loc_10195
      goto loc_10195;
    if (_al == 0xff)                              //jz short loc_10197
      goto loc_10197;
    if (_al != 0xfe)                              //jnz short loc_10180
      goto loc_10180;
    _al = memory(_ds, 0x9546);                    //mov al, byte_1CF96
    if (_al == 0x00)                              //jz short loc_1017B
      goto loc_1017B;
    sub_129DB();                                  //call sub_129DB
    goto loc_1017E;                               //jmp short loc_1017E
loc_1017B:                                        //loc_1017B:
    sub_101AD();                                  //call sub_101AD
loc_1017E:                                        //loc_1017E:
    goto loc_10195;                               //jmp short loc_10195
loc_10180:                                        //loc_10180:
    if (_al & 0x80)                               //jnz short loc_10189
      goto loc_10189;
    sub_1019D();                                  //call sub_1019D
    goto loc_10195;                               //jmp short loc_10195
loc_10189:                                        //loc_10189:
    _al &= 0x3f;                                  //and al, 3Fh
    _push(_ax);                                   //push ax
    sub_1019D();                                  //call sub_1019D
    _ax = _pop();                                 //pop ax
    _al += 1;                                     //inc al
    sub_1019D();                                  //call sub_1019D
loc_10195:                                        //loc_10195:
    /// inject loop
    goto loc_10132;                               //jmp short loc_10132
loc_10197:                                        //loc_10197:
    memory(_ds, 0x9503) = 0;                      //mov byte_1CF53, 0
}

void sub_101C0()
{
    _bx = 0x8e8a;                                 //mov bx, 8E8Ah
    _si = 0x3d;                                   //mov si, 3Dh
    _al = memory(_ds, _bx + _si);                 //mov al, [bx+si]
    if (_al == 0x00)                              //jz short loc_101D5
      goto loc_101D5;
    _si = 0x3e;                                   //mov si, 3Eh
loc_101CF:                                        //loc_101CF:
    _al = memory(_ds, _bx + _si);                 //mov al, [bx+si]
    if (_al == 0x00)                              //jz short loc_101CF
      goto loc_101CF;
loc_101D5:                                        //loc_101D5:
    _si = 0x3b;                                   //mov si, 3Bh
    _al = memory(_ds, _bx + _si);                 //mov al, [bx+si]
    if (_al == 0x00)                              //jz short loc_101E1
      goto loc_101E1;
    sub_1033B();                                  //call sub_1033B
loc_101E1:                                        //loc_101E1:
    _bx = 0x8e8a;                                 //mov bx, 8E8Ah
    _si = memory16(_ds, 0x8F0D);                  //mov si, word_1C95D
    _al = memory(_ds, _bx + _si);                 //mov al, [bx+si]
    if (_al == 0x00)                              //jz short loc_101F6
      goto loc_101F6;
    memory16(_ds, 0x954C) = 1;                    //mov word_1CF9C, 1
    goto loc_1020E;                               //jmp short loc_1020E
loc_101F6:                                        //loc_101F6:
    _si = memory16(_ds, 0x8F0F);                  //mov si, word_1C95F
    _al = memory(_ds, _bx + _si);                 //mov al, [bx+si]
    if (_al == 0x00)                              //jz short loc_10208
      goto loc_10208;
    memory16(_ds, 0x954C) = 2;                    //mov word_1CF9C, 2
    goto loc_1020E;                               //jmp short loc_1020E
loc_10208:                                        //loc_10208:
    memory16(_ds, 0x954C) = 0;                    //mov word_1CF9C, 0
loc_1020E:                                        //loc_1020E:
    _si = memory16(_ds, 0x8F11);                  //mov si, word_1C961
    _al = memory(_ds, _bx + _si);                 //mov al, [bx+si]
    if (_al == 0x00)                              //jz short loc_1021F
      goto loc_1021F;
    memory16(_ds, 0x954C) |= 4;                   //or word_1CF9C, 4
    goto loc_1022E;                               //jmp short loc_1022E
loc_1021F:                                        //loc_1021F:
    _si = memory16(_ds, 0x8F13);                  //mov si, word_1C963
    _al = memory(_ds, _bx + _si);                 //mov al, [bx+si]
    if (_al == 0x00)                              //jz short loc_1022E
      goto loc_1022E;
    memory16(_ds, 0x954C) |= 8;                   //or word_1CF9C, 8
loc_1022E:                                        //loc_1022E:
    _si = memory16(_ds, 0x8F15);                  //mov si, word_1C965
    _al = memory(_ds, _bx + _si);                 //mov al, [bx+si]
    if (_al == 0x00)                              //jz short loc_1023E
      goto loc_1023E;
    memory16(_ds, 0x954C) |= 0x80;                //or word_1CF9C, 80h
loc_1023E:                                        //loc_1023E:
    _si = memory16(_ds, 0x8F17);                  //mov si, word_1C967
    _al = memory(_ds, _bx + _si);                 //mov al, [bx+si]
    if (_al == 0x00)                              //jz short loc_1024D
      goto loc_1024D;
    memory16(_ds, 0x954C) |= 0x40;                //or word_1CF9C, 40h
loc_1024D:                                        //loc_1024D:
    _si = memory16(_ds, 0x8F19);                  //mov si, word_1C969
    _al = memory(_ds, _bx + _si);                 //mov al, [bx+si]
    if (_al == 0x00)                              //jz short loc_1025C
      goto loc_1025C;
    memory16(_ds, 0x954C) |= 0x20;                //or word_1CF9C, 20h
loc_1025C:                                        //loc_1025C:
    _si = memory16(_ds, 0x8F1B);                  //mov si, word_1C96B
    _al = memory(_ds, _bx + _si);                 //mov al, [bx+si]
    if (_al == 0x00)                              //jz short loc_1028C
      goto loc_1028C;
    sub_12C45();                                  //call sub_12C45
    _bx = 0x8e8a;                                 //mov bx, 8E8Ah
loc_1026C:                                        //loc_1026C:
    _al = memory(_ds, _bx + 21);                  //mov al, [bx+15h]
    if (_al != 0x00)                              //jnz short loc_1027C
      goto loc_1027C;
    _al = memory(_ds, _bx + 49);                  //mov al, [bx+31h]
    if (_al != 0x00)                              //jnz short loc_1027C
      goto loc_1027C;
    goto loc_1026C;                               //jmp short loc_1026C
loc_1027C:                                        //loc_1027C:
    _bx = 0x8e8a;                                 //mov bx, 8E8Ah
    _al = memory(_ds, _bx + 21);                  //mov al, [bx+15h]
    if (_al == 0x00)                              //jz short loc_10289
      goto loc_10289;
    // exit game
    std::cout << "Should exit\n";
    goto loc_10096;                               //jmp loc_10096
loc_10289:                                        //loc_10289:
    sub_10529();                                  //call sub_10529
loc_1028C:                                        //loc_1028C:
    _bx = 0x8e8a;                                 //mov bx, 8E8Ah
    _si = 0x3c;                                   //mov si, 3Ch
    _al = memory(_ds, _bx + _si);                 //mov al, [bx+si]
    if (_al == 0x00)                              //jz short loc_102C5
      goto loc_102C5;
    _al = memory(_ds, 0x9505);                    //mov al, byte_1CF55
    if (_al != 0x00)                              //jnz short loc_102B0
      goto loc_102B0;
    _al = 0x0e;                                   //mov al, 0Eh
    sub_13840();                                  //call sub_13840
    memory(_ds, 0x9505) = 1;                      //mov byte_1CF55, 1
    memory(_ds, 0x9506) = 0;                      //mov byte_1CF56, 0
    goto loc_102C3;                               //jmp short loc_102C3
loc_102B0:                                        //loc_102B0:
    if (_al != 0x02)                              //jnz short loc_102C3
      goto loc_102C3;
    memory(_ds, 0x9505) = 3;                      //mov byte_1CF55, 3
    memory(_ds, 0x9506) = 1;                      //mov byte_1CF56, 1
    _al = 0x0d;                                   //mov al, 0Dh
    sub_13840();                                  //call sub_13840
loc_102C3:                                        //loc_102C3:
    goto loc_102DC;                               //jmp short loc_102DC
loc_102C5:                                        //loc_102C5:
    _al = memory(_ds, 0x9505);                    //mov al, byte_1CF55
    if (_al != 0x01)                              //jnz short loc_102D3
      goto loc_102D3;
    memory(_ds, 0x9505) = 2;                      //mov byte_1CF55, 2
    goto loc_102DC;                               //jmp short loc_102DC
loc_102D3:                                        //loc_102D3:
    if (_al != 0x03)                              //jnz short loc_102DC
      goto loc_102DC;
    memory(_ds, 0x9505) = 0;                      //mov byte_1CF55, 0
loc_102DC:                                        //loc_102DC:
    _al = memory(_ds, 0x8F0A);                    //mov al, byte_1C95A
    if (_al != 0x00)                              //jnz short loc_102E4
      goto loc_102E4;
    return;                                       //retn
loc_102E4:                                        //loc_102E4:
    _ax = 0x0003;                                 //mov ax, 3
    _interrupt(0x33);                             //int 33h
    if (!(_bx & 0x0001))                          //jz short loc_102F5
      goto loc_102F5;
    memory16(_ds, 0x954C) |= 0x80;                //or word_1CF9C, 80h
loc_102F5:                                        //loc_102F5:
    if (!(_bx & 0x0002))                          //jz short loc_10300
      goto loc_10300;
    memory16(_ds, 0x954C) |= 0x20;                //or word_1CF9C, 20h
loc_10300:                                        //loc_10300:
    _ax = memory16(_ds, 0x954C);                  //mov ax, word_1CF9C
    _ax &= 0x0f;                                  //and ax, 0Fh
    if (_ax == 0)                                 //jz short loc_10309
      goto loc_10309;
    return;                                       //retn
loc_10309:                                        //loc_10309:
    _ax = 0x0b;                                   //mov ax, 0Bh
    _interrupt(0x33);                             //int 33h
    if ((short)_cx >= (short)0xfffb)              //jge short loc_1031A
      goto loc_1031A;
    memory16(_ds, 0x954C) |= 1;                   //or word_1CF9C, 1
    goto loc_10324;                               //jmp short loc_10324
loc_1031A:                                        //loc_1031A:
    if ((short)_cx <= (short)0x0005)              //jle short loc_10324
      goto loc_10324;
    memory16(_ds, 0x954C) |= 2;                   //or word_1CF9C, 2
loc_10324:                                        //loc_10324:
    if ((short)_dx >= (short)0xfff6)              //jge short loc_10330
      goto loc_10330;
    memory16(_ds, 0x954C) |= 4;                   //or word_1CF9C, 4
    goto locret_1033A;                            //jmp short locret_1033A
loc_10330:                                        //loc_10330:
    if ((short)_dx <= (short)0x0a)                //jle short locret_1033A
      goto locret_1033A;
    memory16(_ds, 0x954C) |= 8;                   //or word_1CF9C, 8
locret_1033A:                                     //locret_1033A:
    return;
loc_10096:
    _ASSERT(0);
}

void sub_10637()
{
    memory16(_ds, 0x8F20) = _ax;                  //mov word_1C970, ax
    _di = 0x0000;                                 //mov di, 0
    _cx = 0x7d00;                                 //mov cx, 7D00h
    sub_1064D();                                  //call sub_1064D
}

void sub_10644()
{
    _ax = _ds;                                    //mov ax, ds
    memory16(_ds, 0x8F20) = _ax;                  //mov word_1C970, ax
    sub_1064D();                                  //call sub_1064D
}

void sub_10B8E()
{
//    std::cout << "sub_10B8E ignore\n";

    WORD _cs = _seg000;
    _ax = memory16(_ds, 0x94F8);                  //mov ax, word_1CF48
    memory16(_ds, 0x942E) = _ax;                  //mov word_1CE7E, ax
    memory(_cs, 0xD93) = 0x28;                    //mov cs:word_10D93, 28h
    memory16(_ds, 0x9430) = 1;                    //mov word_1CE80, 1
    _cx = 0x0007;                                 //mov cx, 7
loc_10BA4:                                        //loc_10BA4:
    _si = 0x1b8a;                                 //mov si, 1B8Ah
loc_10BA7:                                        //loc_10BA7:
    _al = memory(_ds, _si);                       //mov al, [si]
    if (_al & 0x80)                               //jnz short loc_10BC2
      goto loc_10BC2;
    if (!(_al & 0x01))                            //jz short loc_10BBD
      goto loc_10BBD;
    if (_cl != memory(_ds, _si + 2))              //jnz short loc_10BBD
      goto loc_10BBD;
    _push(_cx);                                   //push cx
    _push(_si);                                   //push si
    sub_10BDC();                                  //call sub_10BDC
    _si = _pop();                                 //pop si
    _cx = _pop();                                 //pop cx
loc_10BBD:                                        //loc_10BBD:
    _si += 0x17;                                  //add si, 17h
    goto loc_10BA7;                               //jmp short loc_10BA7
loc_10BC2:                                        //loc_10BC2:
    if (--_cx)                                    //loop loc_10BA4
      goto loc_10BA4;
}

void sub_10DA7()
{
    sub_109A4();                                  //call sub_109A4
    sub_1069A();                                  //call sub_1069A
    memory(_ds, 0x9519) = 0;                      //mov byte_1CF69, 0
    memory(_ds, 0x951A) = 0;                      //mov byte_1CF6A, 0
    memory(_ds, 0x951B) = 0;                      //mov byte_1CF6B, 0
    sub_10E3D();                                  //call sub_10E3D
}

void sub_10FDA() // draw sprite
{
    _al = memory(_ds, 0x94FF);                    //mov al, byte_1CF4F
    memory(_ds, 0x9509) = _al;                    //mov byte_1CF59, al
    _si = 0x1b8a;                                 //mov si, 1B8Ah
loc_10FE3:                                        //loc_10FE3:
    _al = memory(_ds, 0x9513);                    //mov al, byte_1CF63
    if (_al == 0x00)                              //jz short loc_10FF5
      goto loc_10FF5;
    sub_10E07();                                  //call sub_10E07
    _al = memory(_ds, 0x9500);                    //mov al, byte_1CF50
    if (_al == 0x00)                              //jz short sub_10FDA
      sub_10FDA();
    return;                                       //retn
loc_10FF5:                                        //loc_10FF5:
    _al = memory(_ds, 0x94FF);                    //mov al, byte_1CF4F
    if (_al == memory(_ds, 0x9509))               //jz short loc_11036
      goto loc_11036;
    if (_al != 0x01)                              //jnz short loc_1100E
      goto loc_1100E;
    _al = 0x0b;                                   //mov al, 0Bh
    sub_13840();                                  //call sub_13840
    sub_10F3C();                                  //call sub_10F3C
    sub_10FDA();                               //jmp short sub_10FDA ///////
    goto loc_11036;                               //jmp short loc_11036
loc_1100E:                                        //loc_1100E:
    _al = 0x0b;                                   //mov al, 0Bh
    sub_13840();                                  //call sub_13840
    _al = memory(_ds, 0x951D);                    //mov al, byte_1CF6D
    if (_al != 0xf0)                              //jnz short loc_1101F
      goto loc_1101F;
    sub_10DC0();                                  //call sub_10DC0
    goto loc_11034;                               //jmp short loc_11034
loc_1101F:                                        //loc_1101F:
    _al = memory(_ds, 0x1BA0);                    //mov al, byte_155F0
    _al &= 0x7f;                                  //and al, 7Fh
    if (_al <= 0x28)                              //jbe short loc_11031
      goto loc_11031;
    if (_al >= 0x58)                              //jnb short loc_11031
      goto loc_11031;
    memory(_ds, 0x9432) = 1;                      //mov byte_1CE82, 1
loc_11031:                                        //loc_11031:
    sub_10E84();                                  //call sub_10E84
loc_11034:                                        //loc_11034:
    sub_10FDA();                               //jmp short sub_10FDA
    return;
loc_11036:                                        //loc_11036:
    _al = memory(_ds, _si);                       //mov al, [si]
    if (_al & 0x80)                               //jnz short locret_11059
      goto locret_11059;
    if (!(_al & 0x02))                            //jz short loc_11054
      goto loc_11054;
    _push(_si);                                   //push si
    _bl = memory(_ds, _si + 18);                  //mov bl, [si+12h]
    if (_bl == 0x00)                              //jz short loc_11053
      goto loc_11053;
    _bh = 0x00;                                   //mov bh, 0
    _bx -= 1;                                     //dec bx
    _bx <<= 1;                                    //shl bx, 1
    // FUCK!!!!!!!!!!!!! _bx >> 1 !!!!!!!!!!
    switch (_bx<<1)                                  //call cs:off_1105A[bx]
    {
      case 0: sub_11108(); break;
      case 4: sub_1176C(); break;
      case 8: sub_11783(); break;
      case 12: sub_110C6(); break;
      case 16: sub_117AC(); break;
      case 20: sub_117D6(); break;
      case 24: sub_118A9(); break;
      case 28: sub_11A9E(); break;
      case 32: sub_110C6(); break;
      case 36: sub_11993(); break;
      case 40: sub_119C2(); break;
      case 44: sub_12E02(); break;
      case 48: sub_110C6(); break;
      case 52: sub_12FE8(); break;
      case 56: sub_1300A(); break;
      case 60: sub_116FE(); break;
      case 64: sub_112CB(); break;
      case 68: sub_110C6(); break;
      case 72: sub_112EB(); break;
      case 76: sub_115FC(); break;
      case 80: sub_116DF(); break;
      case 84: sub_116D6(); break;
      case 88: sub_11740(); break;
      case 92: sub_11384(); break;
      case 96: sub_113A8(); break;
      case 100: sub_114F0(); break;
      case 104: sub_110F3(); break;
      case 108: sub_118C7(); break;
      case 112: sub_11429(); break;
      case 116: sub_117F4(); break;
      case 120: sub_1171F(); break;
      case 124: sub_11B09(); break;
      case 128: sub_11B4A(); break;
      case 132: sub_12F50(); break;
      case 136: sub_112A7(); break;
      default:
        _ASSERT(0);
    }
loc_11053:                                        //loc_11053:
    _si = _pop();                                 //pop si
loc_11054:                                        //loc_11054:
    _si += 0x17;                                  //add si, 17h
    goto loc_10FE3;                               //jmp short loc_10FE3
locret_11059:                                     //locret_11059:
    return;
}

void sub_121DC()
{
    _ax = 0x403c;                                 //mov ax, 403Ch
    _push(_ax);                                   //push ax
    _ax = 0x1e11;                                 //mov ax, 1E11h
    _push(_ax);                                   //push ax
    _ax = 0x38;                                   //mov ax, 38h
    _push(_ax);                                   //push ax
    _ax = 0x0007;                                 //mov ax, 7
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
    sub_12200();                                  //call sub_12200
    sub_1264A();                                  //call sub_1264A
    sub_12A7F();                                  //call sub_12A7F
    sub_122B1();                                  //call sub_122B1
}

void sub_1220D()
{
    memory(_ds, 0x944C) += 1;                     //inc byte_1CE9C
    _al = memory(_ds, 0x944C);                    //mov al, byte_1CE9C
    _al &= 0x03;                                  //and al, 3
    if (_al != 0)                                 //jnz short loc_12228
      goto loc_12228;
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    _push(_ax);                                   //push ax
    _push(_ax);                                   //push ax
    _al = memory(_ds, 0x94FE);                    //mov al, byte_1CF4E
    _push(_ax);                                   //push ax
    sub_1269E();                                  //call sub_1269E
    sub_12714();                                  //call sub_12714
loc_12228:                                        //loc_12228:
    _ax = memory16(_ds, 0x953C);                  //mov ax, word_1CF8C
    if (_ax == 0x0000)                            //jz short loc_12246
      goto loc_12246;
    if ((short)_ax >= 0 /*CHECK*/)                //jns short loc_12237
      goto loc_12237;
    sub_1252F();                                  //call sub_1252F
    goto loc_12240;                               //jmp short loc_12240
loc_12237:                                        //loc_12237:
    _cx = _ax;                                    //mov cx, ax
loc_12239:                                        //loc_12239:
    _push(_cx);                                   //push cx
    sub_12542();                                  //call sub_12542
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_12239
      goto loc_12239;
loc_12240:                                        //loc_12240:
    memory16(_ds, 0x953C) = 0;                    //mov word_1CF8C, 0
loc_12246:                                        //loc_12246:
    _ax = memory16(_ds, 0x9540);                  //mov ax, word_1CF90
    if (_ax == 0x0000)                            //jz short loc_12264
      goto loc_12264;
    if ((short)_ax >= 0 /*CHECK*/)                //jns short loc_12255
      goto loc_12255;
    sub_12577();                                  //call sub_12577
    goto loc_1225E;                               //jmp short loc_1225E
loc_12255:                                        //loc_12255:
    _cx = _ax;                                    //mov cx, ax
loc_12257:                                        //loc_12257:
    _push(_cx);                                   //push cx
    sub_1258A();                                  //call sub_1258A
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_12257
      goto loc_12257;
loc_1225E:                                        //loc_1225E:
    memory16(_ds, 0x9540) = 0;                    //mov word_1CF90, 0
loc_12264:                                        //loc_12264:
    _ax = memory16(_ds, 0x9544);                  //mov ax, word_1CF94
    if (_ax == 0x0000)                            //jz short loc_1228A
      goto loc_1228A;
    if ((short)_ax >= 0 /*CHECK*/)                //jns short loc_1227B
      goto loc_1227B;
    _ax = -_ax;                                   //neg ax
    _cx = _ax;                                    //mov cx, ax
loc_12272:                                        //loc_12272:
    _push(_cx);                                   //push cx
    sub_125BF();                                  //call sub_125BF
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_12272
      goto loc_12272;
    goto loc_12284;                               //jmp short loc_12284
loc_1227B:                                        //loc_1227B:
    _cx = _ax;                                    //mov cx, ax
loc_1227D:                                        //loc_1227D:
    _push(_cx);                                   //push cx
    sub_125D2();                                  //call sub_125D2
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_1227D
      goto loc_1227D;
loc_12284:                                        //loc_12284:
    memory16(_ds, 0x9544) = 0;                    //mov word_1CF94, 0
loc_1228A:                                        //loc_1228A:
    _ax = memory16(_ds, 0x9538);                  //mov ax, word_1CF88
    if (_ax == 0x0000)                            //jz short locret_122B0
      goto locret_122B0;
    if ((short)_ax >= 0 /*CHECK*/)                //jns short loc_122A1
      goto loc_122A1;
    _ax = -_ax;                                   //neg ax
    _cx = _ax;                                    //mov cx, ax
loc_12298:                                        //loc_12298:
    _push(_cx);                                   //push cx
    sub_12464();                                  //call sub_12464
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_12298
      goto loc_12298;
    goto loc_122AA;                               //jmp short loc_122AA
loc_122A1:                                        //loc_122A1:
    _cx = _ax;                                    //mov cx, ax
loc_122A3:                                        //loc_122A3:
    _push(_cx);                                   //push cx
    sub_1239B();                                  //call sub_1239B
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_122A3
      goto loc_122A3;
loc_122AA:                                        //loc_122AA:
    memory16(_ds, 0x9538) = 0;                    //mov word_1CF88, 0
locret_122B0:                                     //locret_122B0:
    return;
}

void sub_131A4()
{
    _ax = memory16(_ds, 0x94F8);                  //mov ax, word_1CF48
    _es = _ax;                                    //mov es, ax
    _di = 0x0144;                                 //mov di, 144h
    _bx = memory16(_ds, 0x94F4);                  //mov bx, word_1CF44
    _si = 0x0340;                                 //mov si, 340h
    sub_131E7();                                  //call sub_131E7
    _ax = (~_ax);                                 //not ax
    _ax &= 0x0f;                                  //and ax, 0Fh
    _ah = _al;                                    //mov ah, al
    _al = 0x01;                                   //mov al, 1
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _out(_dx, _ax);                               //out dx, ax
    sub_13209();                                  //call sub_13209
    _ah = _al;                                    //mov ah, al
    _al = 0x00;                                   //mov al, 0
    _out(_dx, _ax);                               //out dx, ax
    _push(_ds);                                   //push ds
    _ds = _bx;                                    //mov ds, bx
    _flags.direction = false;                     //cld
    _cx = 0xa0;                                   //mov cx, 0A0h
loc_131D2:                                        //loc_131D2:
    _push(_cx);                                   //push cx
    _cx = 0x20;                                   //mov cx, 20h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();      //rep movsb
    _di += 0x0008;                                //add di, 8
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_131D2
      goto loc_131D2;
    _ds = _pop();                                 //pop ds
    _ax = 0x0000;                                 //mov ax, 0
    _out(_dx, _ax);                               //out dx, ax
    _al += 1;                                     //inc al
    _out(_dx, _ax);                               //out dx, ax
}

void sub_132FE() // draw map
{
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0105;                                 //mov ax, 105h
    _out(_dx, _ax);                               //out dx, ax
    _ax = memory16(_ds, 0x94F8);                  //mov ax, word_1CF48
    _es = _ax;                                    //mov es, ax
    _di = 0x0144;                                 //mov di, 144h
    _ax = memory16(_ds, 0x9528);                  //mov ax, word_1CF78
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _si = _ax;                                    //mov si, ax
    _push(_ds);                                   //push ds
    _ax = 0xa800;                                 //mov ax, 0A800h
    _ds = _ax;                                    //mov ds, ax
    _flags.direction = false;                     //cld
    _cx = 0xa0;                                   //mov cx, 0A0h
loc_13326:                                        //loc_13326:
    _push(_cx);                                   //push cx
    _cx = 0x20;                                   //mov cx, 20h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();      //rep movsb
    _si &= 0x7fff;                                //and si, 7FFFh
    _di += 0x0008;                                //add di, 8
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_13326
      goto loc_13326;
    _ds = _pop();                                 //pop ds
    _ax = 0x0005;                                 //mov ax, 5
    _out(_dx, _ax);                               //out dx, ax
}

void sub_13383() // swap pages
{
    _ax = memory16(_ds, 0x94F8);                  //mov ax, word_1CF48
    _bx = memory16(_ds, 0x94FA);                  //mov bx, word_1CF4A
    memory16(_ds, 0x94F8) = _bx;                  //mov word_1CF48, bx
    memory16(_ds, 0x94FA) = _ax;                  //mov word_1CF4A, ax
    _bx = memory16(_ds, 0x94FA);                  //mov bx, word_1CF4A
    _bx <<= 1;                                    //shl bx, 1
    _bx <<= 1;                                    //shl bx, 1
    _bx <<= 1;                                    //shl bx, 1
    _bx <<= 1;                                    //shl bx, 1
    _flags.interrupt = false;                     //cli
    _dx = 0x03d4;                                 //mov dx, 3D4h
    _ah = _bh;                                    //mov ah, bh
    _al = 0x0c;                                   //mov al, 0Ch
    _out(_dx, _ax);                               //out dx, ax
    _flags.interrupt = true;                      //sti
    _dx = 0x03da;                                 //mov dx, 3DAh
loc_133AA:                                        //loc_133AA:
    _in(_al, _dx);                                //in al, dx
    _al &= 0x08;                                  //and al, 8
    if (_al != 0)                                 //jnz short loc_133AA
      goto loc_133AA;
    sub_133D7();                                  //call sub_133D7
}

void sub_133B3()
{
    _push(_ax);                                   //push ax
    _ax = memory16(_ds, 0x94F8);                  //mov ax, word_1CF48
    _es = _ax;                                    //mov es, ax
    _di = 0x0000;                                 //mov di, 0
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = _pop();                                 //pop ax
    _ah = _al;                                    //mov ah, al
    _al = 0x00;                                   //mov al, 0
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0f01;                                 //mov ax, 0F01h
    _out(_dx, _ax);                               //out dx, ax
    _flags.direction = false;                     //cld
    _cx = 0x0fa0;                                 //mov cx, 0FA0h
    _rep_stosw<MemAuto, DirAuto>();               //rep stosw
    _ax = 0x0000;                                 //mov ax, 0
    _out(_dx, _ax);                               //out dx, ax
    _al += 1;                                     //inc al
    _out(_dx, _ax);                               //out dx, ax
}

void sub_133D7() // vsync
{
    return;
    _dx = 0x03da;                                 //mov dx, 3DAh
loc_133DA:                                        //loc_133DA:
    _in(_al, _dx);                                //in al, dx
    _al &= 0x08;                                  //and al, 8
    if (_al == 0)                                 //jz short loc_133DA
      goto loc_133DA;
loc_133DF:                                        //loc_133DF:
    _in(_al, _dx);                                //in al, dx
    _al &= 0x08;                                  //and al, 8
    if (_al != 0)                                 //jnz short loc_133DF
      goto loc_133DF;
}

void sub_13423()
{
    _ax = 0x0000;                                 //mov ax, 0
    sub_133B3();                                  //call sub_133B3
    sub_13439();                                  //call sub_13439
    sub_13383();                                  //call sub_13383
    _ax = 0x0000;                                 //mov ax, 0
    sub_133B3();                                  //call sub_133B3
    sub_13439();                                  //call sub_13439
}

void sub_134A8() // draw lines
{
    _di = 0x0000;                                 //mov di, 0
    _ax = memory16(_ds, 0x94F4);                  //mov ax, word_1CF44
    _es = _ax;                                    //mov es, ax
    _ax = 0x0000;                                 //mov ax, 0
    _cx = 0x1000;                                 //mov cx, 1000h
    _flags.direction = false;                     //cld
    _rep_stosw<MemAuto, DirAuto>();               //rep stosw -- clear screen

    _ax = 0x4f;                                   //mov ax, 4Fh
    _push(_ax);                                   //push ax
    _ax = 0xff;                                   //mov ax, 0FFh
    _push(_ax);                                   //push ax
    _ax = 0xb0;                                   //mov ax, 0B0h
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    sub_136D4();                                  //call sub_136D4
    _ax = 0x4f;                                   //mov ax, 4Fh
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    _ax = 0xb0;                                   //mov ax, 0B0h
    _push(_ax);                                   //push ax
    _ax = 0xff;                                   //mov ax, 0FFh
    _push(_ax);                                   //push ax
    sub_136D4();                                  //call sub_136D4
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    _ax = 0x4f;                                   //mov ax, 4Fh
    _push(_ax);                                   //push ax
    _ax = 0xff;                                   //mov ax, 0FFh
    _push(_ax);                                   //push ax
    _ax = 0xb0;                                   //mov ax, 0B0h
    _push(_ax);                                   //push ax
    sub_136D4();                                  //call sub_136D4
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    _ax = 0xb0;                                   //mov ax, 0B0h
    _push(_ax);                                   //push ax
    _ax = 0xff;                                   //mov ax, 0FFh
    _push(_ax);                                   //push ax
    _ax = 0x4f;                                   //mov ax, 4Fh
    _push(_ax);                                   //push ax
    sub_136D4();                                  //call sub_136D4
    _ax = memory16(_ds, 0x9547);                  //mov ax, word_1CF97
    _ax &= 0x3f;                                  //and ax, 3Fh
    memory16(_ds, 0x954E) = _ax;                  //mov word_1CF9E, ax
    _bx = _ax;                                    //mov bx, ax
    _ax += 0x40;                                  //add ax, 40h
    _push(_ax);                                   //push ax
    _al = memory(_ds, _bx + 8156);                //mov al, [bx+1FDCh]
    _ah = 0x00;                                   //mov ah, 0
    _push(_ax);                                   //push ax
    sub_135BC();                                  //call sub_135BC
    _ax = memory16(_ds, 0x954E);                  //mov ax, word_1CF9E
    if (_ax <= 0x0c)                              //jbe short loc_13527
      goto loc_13527;
    return;                                       //retn
loc_13527:                                        //loc_13527:
    _bx = memory16(_ds, 0x954E);                  //mov bx, word_1CF9E
    _al = memory(_ds, _bx + 8220);                //mov al, [bx+201Ch]
    _ah = 0x00;                                   //mov ah, 0
    _ax += 0x80;                                  //add ax, 80h
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    _ax = 0xff;                                   //mov ax, 0FFh
    _push(_ax);                                   //push ax
    _al = memory(_ds, _bx + 8233);                //mov al, [bx+2029h]
    _ah = 0x00;                                   //mov ah, 0
    _ax = -_ax;                                   //neg ax
    _ax += 0x7f;                                  //add ax, 7Fh
    _push(_ax);                                   //push ax
    sub_136D4();                                  //call sub_136D4
    _bx = memory16(_ds, 0x954E);                  //mov bx, word_1CF9E
    _al = memory(_ds, _bx + 8220);                //mov al, [bx+201Ch]
    _ah = 0x00;                                   //mov ah, 0
    _ax = -_ax;                                   //neg ax
    _ax += 0x7f;                                  //add ax, 7Fh
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    _al = memory(_ds, _bx + 8233);                //mov al, [bx+2029h]
    _ah = 0x00;                                   //mov ah, 0
    _ax = -_ax;                                   //neg ax
    _ax += 0x7f;                                  //add ax, 7Fh
    _push(_ax);                                   //push ax
    sub_136D4();                                  //call sub_136D4
    _bx = memory16(_ds, 0x954E);                  //mov bx, word_1CF9E
    _al = memory(_ds, _bx + 8220);                //mov al, [bx+201Ch]
    _ah = 0x00;                                   //mov ah, 0
    _ax += 0x80;                                  //add ax, 80h
    _push(_ax);                                   //push ax
    _ax = 0xff;                                   //mov ax, 0FFh
    _push(_ax);                                   //push ax
    _ax = 0xff;                                   //mov ax, 0FFh
    _push(_ax);                                   //push ax
    _al = memory(_ds, _bx + 8233);                //mov al, [bx+2029h]
    _ah = 0x00;                                   //mov ah, 0
    _ax += 0x80;                                  //add ax, 80h
    _push(_ax);                                   //push ax
    sub_136D4();                                  //call sub_136D4
    _bx = memory16(_ds, 0x954E);                  //mov bx, word_1CF9E
    _al = memory(_ds, _bx + 8220);                //mov al, [bx+201Ch]
    _ah = 0x00;                                   //mov ah, 0
    _ax = -_ax;                                   //neg ax
    _ax += 0x7f;                                  //add ax, 7Fh
    _push(_ax);                                   //push ax
    _ax = 0xff;                                   //mov ax, 0FFh
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    _al = memory(_ds, _bx + 8233);                //mov al, [bx+2029h]
    _ah = 0x00;                                   //mov ah, 0
    _ax += 0x80;                                  //add ax, 80h
    _push(_ax);                                   //push ax
    sub_136D4();                                  //call sub_136D4
}

void sub_1019D()
{
    _si = 0x0109;                                 //mov si, 109h
    memory(_ds, _si + 4) = _al;                   //mov [si+4], al
    _bx = 0x0120;                                 //mov bx, 120h
    sub_12121();                                  //call sub_12121
    sub_10B58();                                  //call sub_10B58
}

void sub_101AD()
{
    _cx = 0x1f40;                                 //mov cx, 1F40h
loc_101B0:                                        //loc_101B0:
    _push(_cx);                                   //push cx
    sub_101C0();                                  //call sub_101C0
    _cx = _pop();                                 //pop cx
    _ax = memory16(_ds, 0x954C);                  //mov ax, word_1CF9C
    if (!(_al & 0x80))                            //jz short loc_101BD
      goto loc_101BD;
    return;                                       //retn
loc_101BD:                                        //loc_101BD:
    if (--_cx)                                    //loop loc_101B0
      goto loc_101B0;
}

void sub_1033B()
{
    sub_12C07();                                  //call sub_12C07
    _al = 0x04;                                   //mov al, 4
    sub_12C9A();                                  //call sub_12C9A
    sub_104F3();                                  //call sub_104F3
    memory16(_ds, 0x8F15) = _ax;                  //mov word_1C965, ax
    _al = 0x00;                                   //mov al, 0
    sub_12C9A();                                  //call sub_12C9A
loc_1034E:                                        //loc_1034E:
    sub_104F3();                                  //call sub_104F3
    if (_ax == memory16(_ds, 0x8F15))             //jz short loc_1034E
      goto loc_1034E;
    memory16(_ds, 0x8F0D) = _ax;                  //mov word_1C95D, ax
    _al = 0x01;                                   //mov al, 1
    sub_12C9A();                                  //call sub_12C9A
loc_1035F:                                        //loc_1035F:
    sub_104F3();                                  //call sub_104F3
    if (_ax == memory16(_ds, 0x8F15))             //jz short loc_1035F
      goto loc_1035F;
    if (_ax == memory16(_ds, 0x8F0D))             //jz short loc_1035F
      goto loc_1035F;
    memory16(_ds, 0x8F0F) = _ax;                  //mov word_1C95F, ax
    _al = 0x02;                                   //mov al, 2
    sub_12C9A();                                  //call sub_12C9A
loc_10376:                                        //loc_10376:
    sub_104F3();                                  //call sub_104F3
    if (_ax == memory16(_ds, 0x8F15))             //jz short loc_10376
      goto loc_10376;
    if (_ax == memory16(_ds, 0x8F0D))             //jz short loc_10376
      goto loc_10376;
    if (_ax == memory16(_ds, 0x8F0F))             //jz short loc_10376
      goto loc_10376;
    memory16(_ds, 0x8F11) = _ax;                  //mov word_1C961, ax
    _al = 0x03;                                   //mov al, 3
    sub_12C9A();                                  //call sub_12C9A
loc_10393:                                        //loc_10393:
    sub_104F3();                                  //call sub_104F3
    if (_ax == memory16(_ds, 0x8F15))             //jz short loc_10393
      goto loc_10393;
    if (_ax == memory16(_ds, 0x8F0D))             //jz short loc_10393
      goto loc_10393;
    if (_ax == memory16(_ds, 0x8F0F))             //jz short loc_10393
      goto loc_10393;
    if (_ax == memory16(_ds, 0x8F11))             //jz short loc_10393
      goto loc_10393;
    memory16(_ds, 0x8F13) = _ax;                  //mov word_1C963, ax
    _al = 0x06;                                   //mov al, 6
    sub_12C9A();                                  //call sub_12C9A
loc_103B6:                                        //loc_103B6:
    sub_104F3();                                  //call sub_104F3
    if (_ax == memory16(_ds, 0x8F15))             //jz short loc_103B6
      goto loc_103B6;
    if (_ax == memory16(_ds, 0x8F0D))             //jz short loc_103B6
      goto loc_103B6;
    if (_ax == memory16(_ds, 0x8F0F))             //jz short loc_103B6
      goto loc_103B6;
    if (_ax == memory16(_ds, 0x8F11))             //jz short loc_103B6
      goto loc_103B6;
    if (_ax == memory16(_ds, 0x8F13))             //jz short loc_103B6
      goto loc_103B6;
    memory16(_ds, 0x8F17) = _ax;                  //mov word_1C967, ax
    _al = 0x07;                                   //mov al, 7
    sub_12C9A();                                  //call sub_12C9A
loc_103DF:                                        //loc_103DF:
    sub_104F3();                                  //call sub_104F3
    if (_ax == memory16(_ds, 0x8F15))             //jz short loc_103DF
      goto loc_103DF;
    if (_ax == memory16(_ds, 0x8F0D))             //jz short loc_103DF
      goto loc_103DF;
    if (_ax == memory16(_ds, 0x8F0F))             //jz short loc_103DF
      goto loc_103DF;
    if (_ax == memory16(_ds, 0x8F11))             //jz short loc_103DF
      goto loc_103DF;
    if (_ax == memory16(_ds, 0x8F13))             //jz short loc_103DF
      goto loc_103DF;
    if (_ax == memory16(_ds, 0x8F17))             //jz short loc_103DF
      goto loc_103DF;
    memory16(_ds, 0x8F19) = _ax;                  //mov word_1C969, ax
    _al = 0x05;                                   //mov al, 5
    sub_12C9A();                                  //call sub_12C9A
loc_1040E:                                        //loc_1040E:
    sub_104F3();                                  //call sub_104F3
    if (_ax == memory16(_ds, 0x8F15))             //jz short loc_1040E
      goto loc_1040E;
    if (_ax == memory16(_ds, 0x8F0D))             //jz short loc_1040E
      goto loc_1040E;
    if (_ax == memory16(_ds, 0x8F0F))             //jz short loc_1040E
      goto loc_1040E;
    if (_ax == memory16(_ds, 0x8F11))             //jz short loc_1040E
      goto loc_1040E;
    if (_ax == memory16(_ds, 0x8F13))             //jz short loc_1040E
      goto loc_1040E;
    if (_ax == memory16(_ds, 0x8F17))             //jz short loc_1040E
      goto loc_1040E;
    if (_ax == memory16(_ds, 0x8F19))             //jz short loc_1040E
      goto loc_1040E;
    memory16(_ds, 0x8F1B) = _ax;                  //mov word_1C96B, ax
    sub_10529();                                  //call sub_10529
}

void sub_10529()
{
    _si = 0x8e8a;                                 //mov si, 8E8Ah
    _ah = 0x00;                                   //mov ah, 0
loc_1052E:                                        //loc_1052E:
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    if (_al == 0x00)                              //jz short loc_10535
      goto loc_10535;
    _ah += 1;                                     //inc ah
loc_10535:                                        //loc_10535:
    if (_si != 0x8f0a)                            //jnz short loc_1052E
      goto loc_1052E;
    if (_ah != 0x00)                              //jnz short sub_10529
      sub_10529();
}

void sub_1064D()
{
    _push(_di);                                   //push di
    _push(_cx);                                   //push cx
    _ax = 0x3d00;                                 //mov ax, 3D00h
    _interrupt(0x21);                             //int 21h
    _cx = _pop();                                 //pop cx
    _dx = _pop();                                 //pop dx
    if (!_flags.carry)                            //jnb short loc_10659
      goto loc_10659;
    return;                                       //retn
loc_10659:                                        //loc_10659:
    memory16(_ds, 0x8F1E) = _ax;                  //mov word_1C96E, ax
    _bx = _ax;                                    //mov bx, ax
    _ax = memory16(_ds, 0x8F20);                  //mov ax, word_1C970
    _push(_ds);                                   //push ds
    _ds = _ax;                                    //mov ds, ax
    _ax = 0x3f00;                                 //mov ax, 3F00h
    _interrupt(0x21);                             //int 21h
    _ds = _pop();                                 //pop ds
    _ax = 0x3e00;                                 //mov ax, 3E00h
    _bx = memory16(_ds, 0x8F1E);                  //mov bx, word_1C96E
    _interrupt(0x21);                             //int 21h
}

void sub_1069A() // draw map
{
    _al = memory(_ds, 0x9501);                    //mov al, byte_1CF51
    _bl = _al;                                    //mov bl, al
    _bl <<= 1;                                    //shl bl, 1
    _bl += _al;                                   //add bl, al
    _bl = _bl + memory(_ds, 0x9502);              //add bl, byte_1CF52
    _bh = 0x00;                                   //mov bh, 0
    _bx <<= 1;                                    //shl bx, 1
    _si = memory16(_ds, _bx + 580);               //mov si, [bx+244h]
    _di = 0x9229;                                 //mov di, 9229h
    _cx = 0x40;                                   //mov cx, 40h
    _ax = _ds;                                    //mov ax, ds
    _es = _ax;                                    //mov es, ax
    _ax = 0x0000;                                 //mov ax, 0
    _flags.direction = false;                     //cld
    _rep_stosw<MemAuto, DirAuto>();               //rep stosw
    _di = 0x9229;                                 //mov di, 9229h
loc_106C2:                                        //loc_106C2:
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    if (_al == 0xff)                              //jz short loc_106EB
      goto loc_106EB;
    _al <<= 1;                                    //shl al, 1
    _al <<= 1;                                    //shl al, 1
    _ah = _al;                                    //mov ah, al
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    _al <<= 1;                                    //shl al, 1
    _bl = _al;                                    //mov bl, al
    _bh = 0x00;                                   //mov bh, 0
    _al = 0x00;                                   //mov al, 0
    _ax = _ax | memory16(_ds, _bx + 3287);        //or ax, [bx+0CD7h]
    _cx = _ax;                                    //mov cx, ax
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    _al = -_al;                                   //neg al
    _al += 0x3f;                                  //add al, 3Fh
    _al <<= 1;                                    //shl al, 1
    _bl = _al;                                    //mov bl, al
    memory16(_ds, _bx + -28119) |= _cx;           //or [bx-6DD7h], cx
    goto loc_106C2;                               //jmp short loc_106C2
loc_106EB:                                        //loc_106EB:
    _al = memory(_ds, 0x9501);                    //mov al, byte_1CF51
    _bl = _al;                                    //mov bl, al
    _bl <<= 1;                                    //shl bl, 1
    _bl += _al;                                   //add bl, al
    _bl = _bl + memory(_ds, 0x9502);              //add bl, byte_1CF52
    _bh = 0x00;                                   //mov bh, 0
    _bx <<= 1;                                    //shl bx, 1
    _si = memory16(_ds, _bx + 532);               //mov si, [bx+214h]
    _di = 0x8f29;                                 //mov di, 8F29h
    _cx = 0x0300;                                 //mov cx, 300h
    _bl = 0x00;                                   //mov bl, 0
loc_10708:                                        //loc_10708:
    _bl -= 1;                                     //dec bl
    if ((char)_bl >= 0)                           //jns short loc_1072C
      goto loc_1072C;
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    _dl = _al;                                    //mov dl, al
    _dl &= 0x3f;                                  //and dl, 3Fh
    _al &= 0xc0;                                  //and al, 0C0h
    if (_al != 0)                                 //jnz short loc_1071A
      goto loc_1071A;
    _bl = 0x00;                                   //mov bl, 0
    goto loc_1072C;                               //jmp short loc_1072C
loc_1071A:                                        //loc_1071A:
    if (_al != 0x40)                              //jnz short loc_10722
      goto loc_10722;
    _bl = 0x01;                                   //mov bl, 1
    goto loc_1072C;                               //jmp short loc_1072C
loc_10722:                                        //loc_10722:
    if (_al != 0x80)                              //jnz short loc_1072A
      goto loc_1072A;
    _bl = 0x02;                                   //mov bl, 2
    goto loc_1072C;                               //jmp short loc_1072C
loc_1072A:                                        //loc_1072A:
    _bl = 0x03;                                   //mov bl, 3
loc_1072C:                                        //loc_1072C:
    memory(_ds, _di) = _dl;                       //mov [di], dl
    _di += 1;                                     //inc di
    if (--_cx)                                    //loop loc_10708
      goto loc_10708;
    _di = 0x0000;                                 //mov di, 0
    _ax = 0xa800;                                 //mov ax, 0A800h
    _es = _ax;                                    //mov es, ax
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ah = 0x00;                                   //mov ah, 0
    _al = 0x00;                                   //mov al, 0
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0f01;                                 //mov ax, 0F01h
    _out(_dx, _ax);                               //out dx, ax
    _cx = 0x4000;                                 //mov cx, 4000h
    _rep_stosw<MemAuto, DirAuto>();               //rep stosw
    _ax = 0x8f29;                                 //mov ax, 8F29h
    memory16(_ds, 0x8F25) = _ax;                  //mov word_1C975, ax
    memory16(_ds, 0x8F23) = 1008;                 //mov word_1C973, 3F0h
    _cx = 0x40;                                   //mov cx, 40h
loc_10759:                                        //loc_10759:
    _push(_cx);                                   //push cx
    memory(_ds, 0x8F22) = 0;                      //mov byte_1C972, 0
    sub_107AF();                                  //call sub_107AF
    memory16(_ds, 0x279) = 0;                     //mov word_13CC9, 0
    memory(_ds, 0x27D) = 8;                       //mov byte_13CCD, 8
    memory16(_ds, 0x283) += 8;                    //add word_13CD3, 8
    _si = 0x0274;                                 //mov si, 274h
    sub_10BC5();                                  //call sub_10BC5
    memory16(_ds, 0x279) = 8;                     //mov word_13CC9, 8
    memory(_ds, 0x27D) = 0x18;                    //mov byte_13CCD, 18h
    _cx = 0x0a;                                   //mov cx, 0Ah
loc_10786:                                        //loc_10786:
    _push(_cx);                                   //push cx
    sub_107AF();                                  //call sub_107AF
    _si = 0x0274;                                 //mov si, 274h
    sub_10BC5();                                  //call sub_10BC5
    memory16(_ds, 0x279) += 0x18;                 //add word_13CC9, 18h
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_10786
      goto loc_10786;
    memory(_ds, 0x27D) = 8;                       //mov byte_13CCD, 8
    sub_107AF();                                  //call sub_107AF
    _si = 0x0274;                                 //mov si, 274h
    sub_10BC5();                                  //call sub_10BC5
    memory16(_ds, 0x8F23) -= 0x10;                //sub word_1C973, 10h
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_10759
      goto loc_10759;
}

void sub_109A4()
{
    _di = 0x92a9;                                 //mov di, 92A9h
    _cx = 0xc0;                                   //mov cx, 0C0h
    _ax = _ds;                                    //mov ax, ds
    _es = _ax;                                    //mov es, ax
    _ax = 0xffff;                                 //mov ax, 0FFFFh
    _flags.direction = false;                     //cld
    _rep_stosw<MemAuto, DirAuto>();               //rep stosw
}

void sub_10BDC() // draw tile
{
    WORD _cs = _seg000;
    _al = memory(_ds, _si + 11);                  //mov al, [si+0Bh]
    _cbw();                                       //cbw
    _bx = memory16(_ds, _si + 5);                 //mov bx, [si+5]
    _bx -= _ax;                                   //sub bx, ax
    _push(_bx);                                   //push bx
    _al = memory(_ds, _si + 3);                   //mov al, [si+3]
    _al = _al + memory(_ds, _si + 12);            //add al, [si+0Ch]
    _cbw();                                       //cbw
    _ax = -_ax;                                   //neg ax
    _ax = _ax + memory16(_ds, _si + 7);           //add ax, [si+7]
    _push(_ax);                                   //push ax
    _al = memory(_ds, _si + 9);                   //mov al, [si+9]
    _ah = 0x00;                                   //mov ah, 0
    _push(_ax);                                   //push ax
    _al = memory(_ds, _si + 10);                  //mov al, [si+0Ah]
    _ah = 0x00;                                   //mov ah, 0
    _push(_ax);                                   //push ax
    _bx = memory16(_ds, _si + 13);                //mov bx, [si+0Dh]
    _bx = memory16(_ds, _bx + -27416);            //mov bx, [bx-6B18h]
    _al = memory(_ds, _si + 17);                  //mov al, [si+11h]
    memory(_cs, 0xD95) = _al;                     //mov cs:byte_10D95, al
    _cl = _al;                                    //mov cl, al
    _cl <<= 1;                                    //shl cl, 1
    _cl <<= 1;                                    //shl cl, 1
    _cl <<= 1;                                    //shl cl, 1
    _cl <<= 1;                                    //shl cl, 1
    _al |= _cl;                                   //or al, cl
    memory(_cs, 0xD96) = _al;                     //mov cs:byte_10D96, al
    _si = memory16(_ds, _si + 15);                //mov si, [si+0Fh]
    sub_10C24();                                  //call sub_10C24
}

void sub_10D98()
{
    memory16(_ds, 0x9528) = 0x1a;                 //mov word_1CF78, 1Ah
    memory(_ds, 0x9513) = 0;                      //mov byte_1CF63, 0
    sub_10B7C();                                  //call sub_10B7C
}

void sub_10DC0()
{
    memory(_ds, 0x94FE) += 1;                     //inc byte_1CF4E
    _al = memory(_ds, 0x94FE);                    //mov al, byte_1CF4E
    if (_al < 0x06)                               //jb short loc_10DD3
      goto loc_10DD3;
    memory16(_ds, 0x94FC) = 0x30;                 //mov word_1CF4C, 30h
    goto loc_10DE5;                               //jmp short loc_10DE5
loc_10DD3:                                        //loc_10DD3:
    if (_al < 0x03)                               //jb short loc_10DDF
      goto loc_10DDF;
    memory16(_ds, 0x94FC) = 0x20;                 //mov word_1CF4C, 20h
    goto loc_10DE5;                               //jmp short loc_10DE5
loc_10DDF:                                        //loc_10DDF:
    memory16(_ds, 0x94FC) = 0x10;                 //mov word_1CF4C, 10h
loc_10DE5:                                        //loc_10DE5:
    memory(_ds, 0x9501) += 1;                     //inc byte_1CF51
    _al = memory(_ds, 0x9501);                    //mov al, byte_1CF51
    if (_al <= 0x07)                              //jbe short loc_10DF5
      goto loc_10DF5;
    memory(_ds, 0x9501) = 1;                      //mov byte_1CF51, 1
loc_10DF5:                                        //loc_10DF5:
    sub_109A4();                                  //call sub_109A4
    sub_1069A();                                  //call sub_1069A
    memory(_ds, 0x9519) = 0;                      //mov byte_1CF69, 0
    sub_10E3D();                                  //call sub_10E3D
    sub_12A7F();                                  //call sub_12A7F
}

void sub_10E07()
{
    _ax = memory16(_ds, 0x9534);                  //mov ax, word_1CF84
    if (_ax != 0x0000)                            //jnz short loc_10E15
      goto loc_10E15;
    memory(_ds, 0x9500) = 1;                      //mov byte_1CF50, 1
    return;                                       //retn
loc_10E15:                                        //loc_10E15:
    sub_12329();                                  //call sub_12329
    _al = memory(_ds, 0x9502);                    //mov al, byte_1CF52
    if (_al == 0x00)                              //jz short loc_10E27
      goto loc_10E27;
    memory(_ds, 0x9502) = 0;                      //mov byte_1CF52, 0
    sub_1069A();                                  //call sub_1069A
loc_10E27:                                        //loc_10E27:
    sub_12200();                                  //call sub_12200
    memory(_ds, 0x9519) = 1;                      //mov byte_1CF69, 1
    memory(_ds, 0x951A) = 0;                      //mov byte_1CF6A, 0
    memory(_ds, 0x951B) = 0;                      //mov byte_1CF6B, 0
    sub_10E3D();                                  //call sub_10E3D
}

void sub_10E3D()
{
    _bl = memory(_ds, 0x9501);                    //mov bl, byte_1CF51
    _bh = 0x00;                                   //mov bh, 0
    _bx <<= 1;                                    //shl bx, 1
    _ax = memory16(_ds, _bx + 5365);              //mov ax, [bx+14F5h]
    _ax &= 0x03ff;                                //and ax, 3FFh
    memory16(_ds, 0x9528) = _ax;                  //mov word_1CF78, ax
    _ax = memory16(_ds, 0x94FC);                  //mov ax, word_1CF4C
    memory16(_ds, 0x952A) = _ax;                  //mov word_1CF7A, ax
    memory16(_ds, 0x950A) = 0x80;                 //mov word_1CF5A, 80h
    memory(_ds, 0x950E) = 0;                      //mov byte_1CF5E, 0
    memory16(_ds, 0x950F) = 0;                    //mov word_1CF5F, 0
    memory16(_ds, 0x9511) = 0;                    //mov word_1CF61, 0
    memory(_ds, 0x9513) = 0;                      //mov byte_1CF63, 0
    memory(_ds, 0x9515) = 0;                      //mov byte_1CF65, 0
    memory(_ds, 0x9517) = 0;                      //mov byte_1CF67, 0
    memory(_ds, 0x9432) = 0;                      //mov byte_1CE82, 0
    sub_10E84();                                  //call sub_10E84
}

void sub_10E84()
{
    _al = memory(_ds, 0x950E);                    //mov al, byte_1CF5E
    if (_al == 0x00)                              //jz short loc_10E93
      goto loc_10E93;
    memory(_ds, 0x950E) = 0;                      //mov byte_1CF5E, 0
    sub_1069A();                                  //call sub_1069A
loc_10E93:                                        //loc_10E93:
    memory16(_ds, 0x952C) = 0;                    //mov word_1CF7C, 0
    sub_10B7C();                                  //call sub_10B7C
    _si = 0x0d32;                                 //mov si, 0D32h
    sub_10B58();                                  //call sub_10B58
    _ax = memory16(_ds, 0x950A);                  //mov ax, word_1CF5A
    memory16(_ds, 0x1B8F) = _ax;                  //mov word_155DF, ax
    sub_11B57();                                  //call sub_11B57
    _ax = memory16(_ds, 0x9528);                  //mov ax, word_1CF78
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax -= 0x0003;                                //sub ax, 3
    _ax &= 0x3f;                                  //and ax, 3Fh
    memory16(_ds, 0x9507) = _ax;                  //mov word_1CF57, ax
    _cx = 0x0f;                                   //mov cx, 0Fh
loc_10EC2:                                        //loc_10EC2:
    _push(_cx);                                   //push cx
    _push(_ax);                                   //push ax
    _push(_ax);                                   //push ax
    sub_108BA();                                  //call sub_108BA
    _ax = _pop();                                 //pop ax
    _cx = _pop();                                 //pop cx
    _ax += 1;                                     //inc ax
    _ax &= 0x3f;                                  //and ax, 3Fh
    if (--_cx)                                    //loop loc_10EC2
      goto loc_10EC2;
    _al = memory(_ds, 0x9432);                    //mov al, byte_1CE82
    if (_al == 0x00)                              //jz short loc_10EEA
      goto loc_10EEA;
    _si = 0x1b8a;                                 //mov si, 1B8Ah
    _bx = 0x0d49;                                 //mov bx, 0D49h
    memory(_ds, _si + 4) = 0x0a;                  //mov byte ptr [si+4], 0Ah
    sub_12121();                                  //call sub_12121
    memory(_ds, 0x1B9C) = 0x23;                   //mov byte_155EC, 23h
    return;                                       //retn
loc_10EEA:                                        //loc_10EEA:
    _al = memory(_ds, 0x9519);                    //mov al, byte_1CF69
    if (_al == 0x00)                              //jz short loc_10F08
      goto loc_10F08;
    memory(_ds, 0x9519) = 0;                      //mov byte_1CF69, 0
    _si = 0x0da2;                                 //mov si, 0DA2h
    _ax = memory16(_ds, 0x1B91);                  //mov ax, word_155E1
    memory16(_ds, _si + 7) = _ax;                 //mov [si+7], ax
    _al = memory(_ds, 0x1B8D);                    //mov al, byte_155DD
    memory(_ds, _si + 3) = _al;                   //mov [si+3], al
    sub_10B58();                                  //call sub_10B58
loc_10F08:                                        //loc_10F08:
    sub_10F9D();                                  //call sub_10F9D
    _al = memory(_ds, 0x951A);                    //mov al, byte_1CF6A
    if (_al == 0x00)                              //jz short loc_10F23
      goto loc_10F23;
    memory(_ds, 0x951A) = 1;                      //mov byte_1CF6A, 1
    _si = 0x0dc3;                                 //mov si, 0DC3h
    memory(_ds, _si) &= 0xdf;                     //and byte ptr [si], 0DFh
    sub_11CD9();                                  //call sub_11CD9
    sub_10B58();                                  //call sub_10B58
loc_10F23:                                        //loc_10F23:
    _al = memory(_ds, 0x951B);                    //mov al, byte_1CF6B
    if (_al == 0x00)                              //jz short locret_10F3B
      goto locret_10F3B;
    memory(_ds, 0x951B) = 1;                      //mov byte_1CF6B, 1
    _si = 0x0dc3;                                 //mov si, 0DC3h
    memory(_ds, _si) |= 0x20;                     //or byte ptr [si], 20h
    sub_11CD9();                                  //call sub_11CD9
    sub_10B58();                                  //call sub_10B58
locret_10F3B:                                     //locret_10F3B:
    return;
}

void sub_10F3C()
{
    memory(_ds, 0x951C) = 0;                      //mov byte_1CF6C, 0
    sub_12DDC();                                  //call sub_12DDC
    memory16(_ds, 0x9528) = 0x1a;                 //mov word_1CF78, 1Ah
    memory16(_ds, 0x9547) = 0;                    //mov word_1CF97, 0
    memory16(_ds, 0x951E) = 0;                    //mov word_1CF6E, 0
    memory(_ds, 0x9524) = 0;                      //mov byte_1CF74, 0
    memory(_ds, 0x9549) = 3;                      //mov byte_1CF99, 3
    sub_10B7C();                                  //call sub_10B7C
    _si = 0x0d04;                                 //mov si, 0D04h
    sub_10B58();                                  //call sub_10B58
    sub_12DF6();                                  //call sub_12DF6
    _al = memory(_ds, 0x951A);                    //mov al, byte_1CF6A
    if (_al == 0x00)                              //jz short loc_10F84
      goto loc_10F84;
    memory(_ds, 0x951A) = 1;                      //mov byte_1CF6A, 1
    _si = 0x0d1b;                                 //mov si, 0D1Bh
    memory(_ds, _si) &= 0xdf;                     //and byte ptr [si], 0DFh
    sub_12F50();                                  //call sub_12F50
    sub_10B58();                                  //call sub_10B58
loc_10F84:                                        //loc_10F84:
    _al = memory(_ds, 0x951B);                    //mov al, byte_1CF6B
    if (_al == 0x00)                              //jz short locret_10F9C
      goto locret_10F9C;
    memory(_ds, 0x951B) = 1;                      //mov byte_1CF6B, 1
    _si = 0x0d1b;                                 //mov si, 0D1Bh
    memory(_ds, _si) |= 0x20;                     //or byte ptr [si], 20h
    sub_12F50();                                  //call sub_12F50
    sub_10B58();                                  //call sub_10B58
locret_10F9C:                                     //locret_10F9C:
    return;
}

void sub_110C6()
{
    _al = memory(_ds, _si + 3);                   //mov al, [si+3]
    _al = _al + memory(_ds, _si + 12);            //add al, [si+0Ch]
    _cbw();                                       //cbw
    _ax = -_ax;                                   //neg ax
    _ax = _ax + memory16(_ds, _si + 7);           //add ax, [si+7]
    _ax &= 0x03ff;                                //and ax, 3FFh
    _bx = memory16(_ds, 0x9528);                  //mov bx, word_1CF78
    _bx += 0xa0;                                  //add bx, 0A0h
    _bx &= 0x03ff;                                //and bx, 3FFh
    if (_ax >= _bx)                               //jnb short loc_110E8
      goto loc_110E8;
    _ax += 0x0400;                                //add ax, 400h
loc_110E8:                                        //loc_110E8:
    _ax -= _bx;                                   //sub ax, bx
    if (_ax >= 0x0200)                            //jnb short locret_110F2
      goto locret_110F2;
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
locret_110F2:                                     //locret_110F2:
    return;
}

void sub_110F3()
{
    memory(_ds, _si + 22) += 1;                   //inc byte ptr [si+16h]
    _al = memory(_ds, _si + 22);                  //mov al, [si+16h]
    if (_al <= 0x08)                              //jbe short loc_110FF
      goto loc_110FF;
    _al = 0x08;                                   //mov al, 8
loc_110FF:                                        //loc_110FF:
    _ah = 0x00;                                   //mov ah, 0
    memory16(_ds, _si + 7) -= _ax;                //sub [si+7], ax
    sub_110A0();                                  //call sub_110A0
}

void sub_11108()
{
    sub_11B80();                                  //call sub_11B80
    sub_11BB9();                                  //call sub_11BB9
    _bx = memory16(_ds, 0x954C);                  //mov bx, word_1CF9C
    _ax = memory16(_ds, 0x952C);                  //mov ax, word_1CF7C
    if (!(_bl & 0x01))                            //jz short loc_11131
      goto loc_11131;
    _flags.sign = (short)(_ax - 0x0001) < 0;      //sub ax, 1
    _ax -= 0x0001;
    if (_flags.sign)                              //js short loc_11127
      goto loc_11127;
    if ((short)_ax <= (short)0x0004)              //jle short loc_11127
      goto loc_11127;
    _ax = 0x0004;                                 //mov ax, 4
loc_11127:                                        //loc_11127:
    if ((short)_ax >= (short)0xffe8)              //jge short loc_1112F
      goto loc_1112F;
    _ax = 0xffe8;                                 //mov ax, 0FFE8h
loc_1112F:                                        //loc_1112F:
    goto loc_11158;                               //jmp short loc_11158
loc_11131:                                        //loc_11131:
    if (!(_bl & 0x02))                            //jz short loc_1114D
      goto loc_1114D;
    _flags.sign = (short)(_ax + 0x0001) < 0;      //add ax, 1
    _ax += 0x0001;
    if (!_flags.sign)                              //jns short loc_11143
      goto loc_11143;
    if ((short)_ax >= (short)0xfffc)              //jge short loc_11143
      goto loc_11143;
    _ax = 0xfffc;                                 //mov ax, 0FFFCh
loc_11143:                                        //loc_11143:
    if ((short)_ax <= (short)0x18)                //jle short loc_1114B
      goto loc_1114B;
    _ax = 0x18;                                   //mov ax, 18h
loc_1114B:                                        //loc_1114B:
    goto loc_11158;                               //jmp short loc_11158
loc_1114D:                                        //loc_1114D:
    if (_ax == 0x0000)                            //jz short loc_11158
      goto loc_11158;
    if ((short)_ax <= (short)0x0000)              //jle short loc_11157
      goto loc_11157;
    _ax -= 1;                                     //dec ax
    goto loc_11158;                               //jmp short loc_11158
loc_11157:                                        //loc_11157:
    _ax += 1;                                     //inc ax
loc_11158:                                        //loc_11158:
    memory16(_ds, 0x952C) = _ax;                  //mov word_1CF7C, ax
    _ax += 0x0003;                                //add ax, 3
    _sar(_ax, 1);                                 //sar ax, 1
    _sar(_ax, 1);                                 //sar ax, 1
    _ax = _ax + memory16(_ds, 0x1B8F);            //add ax, word_155DF
    if ((short)_ax >= (short)0x14)                //jge short loc_11174
      goto loc_11174;
    _ax = 0x14;                                   //mov ax, 14h
    memory16(_ds, 0x952C) = 0;                    //mov word_1CF7C, 0
loc_11174:                                        //loc_11174:
    if ((short)_ax <= (short)0xec)                //jle short loc_11182
      goto loc_11182;
    _ax = 0xec;                                   //mov ax, 0ECh
    memory16(_ds, 0x952C) = 0;                    //mov word_1CF7C, 0
loc_11182:                                        //loc_11182:
    memory16(_ds, 0x1B8F) = _ax;                  //mov word_155DF, ax
    _al = memory(_ds, 0x1B8E);                    //mov al, byte_155DE
    if (_al == 0x00)                              //jz short loc_1118F
      goto loc_1118F;
    sub_11B57();                                  //call sub_11B57
loc_1118F:                                        //loc_1118F:
    sub_11C78();                                  //call sub_11C78
    sub_10A51();                                  //call sub_10A51
    if (_ax == 0x0000)                            //jz short loc_1119F
      goto loc_1119F;
    sub_11C56();                                  //call sub_11C56
    goto loc_111BC;                               //jmp short loc_111BC
loc_1119F:                                        //loc_1119F:
    memory(_ds, 0x1B9E) += 1;                     //inc byte_155EE
    memory(_ds, 0x1B9E) &= 0x3f;                  //and byte_155EE, 3Fh
    sub_10A51();                                  //call sub_10A51
    if (_ax == 0x0000)                            //jz short loc_111B3
      goto loc_111B3;
    sub_11C56();                                  //call sub_11C56
loc_111B3:                                        //loc_111B3:
    memory(_ds, 0x1B9E) -= 1;                     //dec byte_155EE
    memory(_ds, 0x1B9E) &= 0x3f;                  //and byte_155EE, 3Fh
loc_111BC:                                        //loc_111BC:
    _ax = memory16(_ds, 0x9542);                  //mov ax, word_1CF92
    if ((short)_ax > (short)0x0000)               //jg short loc_111C8
      goto loc_111C8;
    sub_11C33();                                  //call sub_11C33
    return;                                       //retn
loc_111C8:                                        //loc_111C8:
    _al = memory(_ds, 0x1B8E);                    //mov al, byte_155DE
    if (_al != 0x00)                              //jnz short loc_111DE
      goto loc_111DE;
    memory(_ds, 0x9515) += 1;                     //inc byte_1CF65
    _al = memory(_ds, 0x9515);                    //mov al, byte_1CF65
    if (_al < 0x04)                               //jb short locret_111DD
      goto locret_111DD;
    sub_11C33();                                  //call sub_11C33
locret_111DD:                                     //locret_111DD:
    return;                                       //retn
loc_111DE:                                        //loc_111DE:
    _ax = memory16(_ds, 0x953E);                  //mov ax, word_1CF8E
    if ((short)_ax <= (short)0x0000)              //jle short loc_111F0
      goto loc_111F0;
    _ax = memory16(_ds, 0x954C);                  //mov ax, word_1CF9C
    if (!(_al & 0x80))                            //jz short loc_111F0
      goto loc_111F0;
    sub_11D1E();                                  //call sub_11D1E
loc_111F0:                                        //loc_111F0:
    _ax = memory16(_ds, 0x954C);                  //mov ax, word_1CF9C
    _bl = memory(_ds, 0x951A);                    //mov bl, byte_1CF6A
    if (!(_al & 0x40))                            //jz short loc_11235
      goto loc_11235;
    if (_bl != 0x00)                              //jnz short loc_11224
      goto loc_11224;
    _ax = memory16(_ds, 0x9536);                  //mov ax, word_1CF86
    if (_ax <= 0x0000)                            //jbe short loc_11222
      goto loc_11222;
    memory(_ds, 0x951A) = 1;                      //mov byte_1CF6A, 1
    _si = 0x0dc3;                                 //mov si, 0DC3h
    memory(_ds, _si) &= 0xdf;                     //and byte ptr [si], 0DFh
    sub_11CD9();                                  //call sub_11CD9
    sub_10B58();                                  //call sub_10B58
    memory16(_ds, 0x9538) -= 1;                   //dec word_1CF88
    _al = 0x01;                                   //mov al, 1
    sub_13840();                                  //call sub_13840
loc_11222:                                        //loc_11222:
    goto loc_11233;                               //jmp short loc_11233
loc_11224:                                        //loc_11224:
    if (_bl != 0x02)                              //jnz short loc_11233
      goto loc_11233;
    memory(_ds, 0x951A) = 3;                      //mov byte_1CF6A, 3
    _al = 0x02;                                   //mov al, 2
    sub_13840();                                  //call sub_13840
loc_11233:                                        //loc_11233:
    goto loc_1124B;                               //jmp short loc_1124B
loc_11235:                                        //loc_11235:
    if (_bl != 0x01)                              //jnz short loc_11241
      goto loc_11241;
    memory(_ds, 0x951A) = 2;                      //mov byte_1CF6A, 2
    goto loc_1124B;                               //jmp short loc_1124B
loc_11241:                                        //loc_11241:
    if (_bl != 0x03)                              //jnz short loc_1124B
      goto loc_1124B;
    memory(_ds, 0x951A) = 0;                      //mov byte_1CF6A, 0
loc_1124B:                                        //loc_1124B:
    _ax = memory16(_ds, 0x954C);                  //mov ax, word_1CF9C
    _bl = memory(_ds, 0x951B);                    //mov bl, byte_1CF6B
    if (!(_al & 0x20))                            //jz short loc_11290
      goto loc_11290;
    if (_bl != 0x00)                              //jnz short loc_1127F
      goto loc_1127F;
    _ax = memory16(_ds, 0x9536);                  //mov ax, word_1CF86
    if (_ax <= 0x0000)                            //jbe short loc_1127D
      goto loc_1127D;
    memory(_ds, 0x951B) = 1;                      //mov byte_1CF6B, 1
    _si = 0x0dc3;                                 //mov si, 0DC3h
    memory(_ds, _si) |= 0x20;                     //or byte ptr [si], 20h
    sub_11CD9();                                  //call sub_11CD9
    sub_10B58();                                  //call sub_10B58
    memory16(_ds, 0x9538) -= 1;                   //dec word_1CF88
    _al = 0x01;                                   //mov al, 1
    sub_13840();                                  //call sub_13840
loc_1127D:                                        //loc_1127D:
    goto loc_1128E;                               //jmp short loc_1128E
loc_1127F:                                        //loc_1127F:
    if (_bl != 0x02)                              //jnz short loc_1128E
      goto loc_1128E;
    memory(_ds, 0x951B) = 3;                      //mov byte_1CF6B, 3
    _al = 0x02;                                   //mov al, 2
    sub_13840();                                  //call sub_13840
loc_1128E:                                        //loc_1128E:
    goto locret_112A6;                            //jmp short locret_112A6
loc_11290:                                        //loc_11290:
    if (_bl != 0x01)                              //jnz short loc_1129C
      goto loc_1129C;
    memory(_ds, 0x951B) = 2;                      //mov byte_1CF6B, 2
    goto locret_112A6;                            //jmp short locret_112A6
loc_1129C:                                        //loc_1129C:
    if (_bl != 0x03)                              //jnz short locret_112A6
      goto locret_112A6;
    memory(_ds, 0x951B) = 0;                      //mov byte_1CF6B, 0
locret_112A6:                                     //locret_112A6:
    return;
}

void sub_112A7()
{
    _ax = memory16(_ds, 0x952A);                  //mov ax, word_1CF7A
    _flags.sign = (short)(_ax - 0x0003) < 0;      //sub ax, 3
    _ax -= 0x0003;
    if (_flags.sign)                              //js short loc_112B4
      goto loc_112B4;
    memory16(_ds, 0x952A) = _ax;                  //mov word_1CF7A, ax
    goto loc_112B7;                               //jmp short loc_112B7
loc_112B4:                                        //loc_112B4:
    sub_11C33();                                  //call sub_11C33
loc_112B7:                                        //loc_112B7:
    sub_11BB9();                                  //call sub_11BB9
    sub_11B57();                                  //call sub_11B57
    _si = 0x1b8a;                                 //mov si, 1B8Ah
    _bx = 0x0d49;                                 //mov bx, 0D49h
    memory(_ds, _si + 4) = 0x0a;                  //mov byte ptr [si+4], 0Ah
    sub_12121();                                  //call sub_12121
}

void sub_112CB()
{
    _ax = memory16(_ds, 0x952A);                  //mov ax, word_1CF7A
    _ax -= 1;                                     //dec ax
    if ((short)_ax < 0)                           //js short loc_112D4
      goto loc_112D4;
    memory16(_ds, 0x952A) = _ax;                  //mov word_1CF7A, ax
loc_112D4:                                        //loc_112D4:
    sub_11BB9();                                  //call sub_11BB9
    sub_11B57();                                  //call sub_11B57
    memory(_ds, 0x9514) += 1;                     //inc byte_1CF64
    _al = memory(_ds, 0x9514);                    //mov al, byte_1CF64
    if (_al < 0x28)                               //jb short locret_112EA
      goto locret_112EA;
    memory(_ds, 0x9513) = 1;                      //mov byte_1CF63, 1
locret_112EA:                                     //locret_112EA:
    return;
}

void sub_112EB()
{
    sub_110A0();                                  //call sub_110A0
    _al = memory(_ds, _si);                       //mov al, [si]
    if (_al != 0x00)                              //jnz short loc_112F5
      goto loc_112F5;
    return;                                       //retn
loc_112F5:                                        //loc_112F5:
    memory16(_ds, _si + 7) -= 0x10;               //sub word ptr [si+7], 10h
    memory16(_ds, _si + 7) &= 1023;               //and word ptr [si+7], 3FFh
    _al = memory(_ds, _si + 4);                   //mov al, [si+4]
    if (_al != 0x01)                              //jnz short loc_11312
      goto loc_11312;
    _al = memory(_ds, _si + 3);                   //mov al, [si+3]
    if ((char)_al <= (char)0x9c)                  //jle short loc_11310
      goto loc_11310;
    memory(_ds, _si + 3) -= 8;                    //sub byte ptr [si+3], 8
loc_11310:                                        //loc_11310:
    goto loc_11321;                               //jmp short loc_11321
loc_11312:                                        //loc_11312:
    if (_al != 0x02)                              //jnz short loc_11321
      goto loc_11321;
    _al = memory(_ds, _si + 3);                   //mov al, [si+3]
    if ((char)_al >= (char)0x64)                  //jge short loc_11321
      goto loc_11321;
    memory(_ds, _si + 3) += 8;                    //add byte ptr [si+3], 8
loc_11321:                                        //loc_11321:
    _push(_si);                                   //push si
    _ax = memory16(_ds, _si + 5);                 //mov ax, [si+5]
    _push(_ax);                                   //push ax
    _ax = memory16(_ds, _si + 7);                 //mov ax, [si+7]
    _push(_ax);                                   //push ax
    sub_107FD();                                  //call sub_107FD
    _si = _pop();                                 //pop si
    if ((char)_al < (char)memory(_ds, _si + 3))   //jl short loc_11338
      goto loc_11338;
    sub_12092();                                  //call sub_12092
    goto locret_11383;                            //jmp short locret_11383
loc_11338:                                        //loc_11338:
    _push(_si);                                   //push si
    _ax = memory16(_ds, _si + 5);                 //mov ax, [si+5]
    _push(_ax);                                   //push ax
    memory(_ds, _si + 20) = _cl;                  //mov [si+14h], cl
    _push(_cx);                                   //push cx
    sub_10AD5();                                  //call sub_10AD5
    _si = _pop();                                 //pop si
    if (_ax == 0x0000)                            //jz short locret_11383
      goto locret_11383;
    _push(_si);                                   //push si
    _al = memory(_ds, _si + 20);                  //mov al, [si+14h]
    _ah = 0x00;                                   //mov ah, 0
    _push(_bx);                                   //push bx
    _push(_ax);                                   //push ax
    sub_11C0A();                                  //call sub_11C0A
    _al = memory(_ds, _si);                       //mov al, [si]
    if (_al & 0x80)                               //jnz short loc_11382
      goto loc_11382;
    _bx = _pop();                                 //pop bx
    _push(_bx);                                   //push bx
    _al = memory(_ds, _si + 3);                   //mov al, [si+3]
    _flags.sign = (char)(_al - memory(_ds, _bx + 3)) < 0;
    _al = _al - memory(_ds, _bx + 3);
    if (!_flags.sign)                              //jns short loc_11367
      goto loc_11367;
    _al = -_al;                                   //neg al
loc_11367:                                        //loc_11367:
    if (_al >= 0x10)                              //jnb short loc_11382
      goto loc_11382;
    memory(_ds, _si + 21) -= 1;                   //dec byte ptr [si+15h]
    if ((char)memory(_ds, _si + 21) >= 0)         //jns short loc_1137A
      goto loc_1137A;
    sub_120DB();                                  //call sub_120DB
    _al = 0x06;                                   //mov al, 6
    sub_13840();                                  //call sub_13840
    goto loc_1137D;                               //jmp short loc_1137D
loc_1137A:                                        //loc_1137A:
    sub_12662();                                  //call sub_12662
loc_1137D:                                        //loc_1137D:
    _si = _pop();                                 //pop si
    _push(_si);                                   //push si
    sub_12047();                                  //call sub_12047
loc_11382:                                        //loc_11382:
    _si = _pop();                                 //pop si
locret_11383:                                     //locret_11383:
    return;
}

void sub_11384()
{
    _al = memory(_ds, 0x1B9C);                    //mov al, byte_155EC
    if (_al != 0x11)                              //jnz short loc_1138E
      goto loc_1138E;
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
loc_1138E:                                        //loc_1138E:
    sub_11CD9();                                  //call sub_11CD9
    _al = memory(_ds, _si);                       //mov al, [si]
    if (_al & 0x20)                               //jnz short loc_1139C
      goto loc_1139C;
    _al = memory(_ds, 0x951A);                    //mov al, byte_1CF6A
    goto loc_1139F;                               //jmp short loc_1139F
loc_1139C:                                        //loc_1139C:
    _al = memory(_ds, 0x951B);                    //mov al, byte_1CF6B
loc_1139F:                                        //loc_1139F:
    if (_al != 0x03)                              //jnz short locret_113A7
      goto locret_113A7;
    memory(_ds, _si + 18) = 0x19;                 //mov byte ptr [si+12h], 19h
locret_113A7:                                     //locret_113A7:
    return;
}

void sub_113A8()
{
    sub_110A0();                                  //call sub_110A0
    _al = memory(_ds, _si);                       //mov al, [si]
    if (_al != 0x00)                              //jnz short loc_113B2
      goto loc_113B2;
    return;                                       //retn
loc_113B2:                                        //loc_113B2:
    memory16(_ds, _si + 7) -= 6;                  //sub word ptr [si+7], 6
    memory16(_ds, _si + 7) &= 1023;               //and word ptr [si+7], 3FFh
    _push(_si);                                   //push si
    _ax = memory16(_ds, _si + 5);                 //mov ax, [si+5]
    _push(_ax);                                   //push ax
    _ax = memory16(_ds, _si + 7);                 //mov ax, [si+7]
    _push(_ax);                                   //push ax
    sub_107FD();                                  //call sub_107FD
    _si = _pop();                                 //pop si
    _al += 0x04;                                  //add al, 4
    memory(_ds, _si + 3) = _al;                   //mov [si+3], al
    memory(_ds, _si + 20) = _cl;                  //mov [si+14h], cl
    memory(_ds, _si + 4) = _bl;                   //mov [si+4], bl
    _bx = 0x0dda;                                 //mov bx, 0DDAh
    sub_12121();                                  //call sub_12121
    _al = memory(_ds, _si + 4);                   //mov al, [si+4]
    if (_al != 0x00)                              //jnz short loc_113F5
      goto loc_113F5;
    memory16(_ds, _si + 7) += 4;                  //add word ptr [si+7], 4
    memory16(_ds, _si + 7) &= 1023;               //and word ptr [si+7], 3FFh
    memory(_ds, _si + 21) -= 1;                   //dec byte ptr [si+15h]
    if ((char)memory(_ds, _si + 21) >= 0)         //jns short loc_113F5
      goto loc_113F5;
    sub_120F0();                                  //call sub_120F0
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
    return;                                       //retn
loc_113F5:                                        //loc_113F5:
    _push(_si);                                   //push si
    _ax = memory16(_ds, _si + 5);                 //mov ax, [si+5]
    _push(_ax);                                   //push ax
    _cl = memory(_ds, _si + 20);                  //mov cl, [si+14h]
    _ch = 0x00;                                   //mov ch, 0
    _push(_cx);                                   //push cx
    sub_10AD5();                                  //call sub_10AD5
    _si = _pop();                                 //pop si
    if (_ax == 0x0000)                            //jz short locret_11428
      goto locret_11428;
    _push(_si);                                   //push si
    _al = memory(_ds, _si + 20);                  //mov al, [si+14h]
    _ah = 0x00;                                   //mov ah, 0
    _push(_bx);                                   //push bx
    _push(_ax);                                   //push ax
    sub_11C0A();                                  //call sub_11C0A
    _al = memory(_ds, _si);                       //mov al, [si]
    if (_al & 0x80)                               //jnz short loc_11427
      goto loc_11427;
    sub_120DB();                                  //call sub_120DB
    _al = 0x06;                                   //mov al, 6
    sub_13840();                                  //call sub_13840
    _si = _pop();                                 //pop si
    _push(_si);                                   //push si
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
loc_11427:                                        //loc_11427:
    _si = _pop();                                 //pop si
locret_11428:                                     //locret_11428:
    return;
}

void sub_11429()
{
    sub_110C6();                                  //call sub_110C6
    _al = memory(_ds, _si);                       //mov al, [si]
    if (_al != 0x00)                              //jnz short loc_11433
      goto loc_11433;
    return;                                       //retn
loc_11433:                                        //loc_11433:
    _al = memory(_ds, _si + 1);                   //mov al, [si+1]
    if (_al != 0x02)                              //jnz short loc_11440
      goto loc_11440;
    memory16(_ds, _si + 7) += 5;                  //add word ptr [si+7], 5
    goto loc_1146A;                               //jmp short loc_1146A
loc_11440:                                        //loc_11440:
    if (_al != 0x00)                              //jnz short loc_1144A
      goto loc_1144A;
    memory16(_ds, _si + 5) -= 5;                  //sub word ptr [si+5], 5
    goto loc_1146A;                               //jmp short loc_1146A
loc_1144A:                                        //loc_1144A:
    if (_al != 0x01)                              //jnz short loc_11458
      goto loc_11458;
    memory16(_ds, _si + 5) -= 3;                  //sub word ptr [si+5], 3
    memory16(_ds, _si + 7) += 2;                  //add word ptr [si+7], 2
    goto loc_1146A;                               //jmp short loc_1146A
loc_11458:                                        //loc_11458:
    if (_al != 0x03)                              //jnz short loc_11466
      goto loc_11466;
    memory16(_ds, _si + 5) += 3;                  //add word ptr [si+5], 3
    memory16(_ds, _si + 7) += 2;                  //add word ptr [si+7], 2
    goto loc_1146A;                               //jmp short loc_1146A
loc_11466:                                        //loc_11466:
    memory16(_ds, _si + 5) += 5;                  //add word ptr [si+5], 5
loc_1146A:                                        //loc_1146A:
    memory16(_ds, _si + 7) &= 1023;               //and word ptr [si+7], 3FFh
    _ax = memory16(_ds, _si + 5);                 //mov ax, [si+5]
    if ((short)_ax >= (short)0x0c)                //jge short loc_1147B
      goto loc_1147B;
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
    return;                                       //retn
loc_1147B:                                        //loc_1147B:
    if ((short)_ax <= (short)0xf4)                //jle short loc_11484
      goto loc_11484;
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
    return;                                       //retn
loc_11484:                                        //loc_11484:
    _push(_si);                                   //push si
    _ax = memory16(_ds, _si + 5);                 //mov ax, [si+5]
    _push(_ax);                                   //push ax
    _ax = memory16(_ds, _si + 7);                 //mov ax, [si+7]
    _push(_ax);                                   //push ax
    sub_107FD();                                  //call sub_107FD
    _si = _pop();                                 //pop si
    _al += 0x08;                                  //add al, 8
    memory(_ds, _si + 3) = _al;                   //mov [si+3], al
    memory(_ds, _si + 20) = _cl;                  //mov [si+14h], cl
    memory(_ds, _si + 4) = _bl;                   //mov [si+4], bl
    _bl = memory(_ds, _si + 1);                   //mov bl, [si+1]
    _bh = 0x00;                                   //mov bh, 0
    _bx <<= 1;                                    //shl bx, 1
    _bx = memory16(_ds, _bx + 4351);              //mov bx, [bx+10FFh]
    sub_12121();                                  //call sub_12121
    _al = memory(_ds, 0x1B9C);                    //mov al, byte_155EC
    if (_al != 0x11)                              //jnz short loc_114B2
      goto loc_114B2;
    return;                                       //retn
loc_114B2:                                        //loc_114B2:
    _ax = memory16(_ds, _si + 5);                 //mov ax, [si+5]
    _flags.sign = (short)(_ax - memory16(_ds, 0x1B8F)) < 0;
    _ax = _ax - memory16(_ds, 0x1B8F);
    if (!_flags.sign)                              //jns short loc_114BD
      goto loc_114BD;
    _ax = -_ax;                                   //neg ax
loc_114BD:                                        //loc_114BD:
    if (_ax >= 0x10)                              //jnb short locret_114EF
      goto locret_114EF;
    _ax = memory16(_ds, _si + 7);                 //mov ax, [si+7]
    _ax = _ax - memory16(_ds, 0x1B91);            //sub ax, word_155E1
    _flags.sign = (short)(_ax - 0x0008) < 0;      //sub ax, 8
    _ax -= 0x0008;
    if (!_flags.sign)                              //jns short loc_114D0
      goto loc_114D0;
    _ax = -_ax;                                   //neg ax
loc_114D0:                                        //loc_114D0:
    if (_ax >= 0x10)                              //jnb short locret_114EF
      goto locret_114EF;
    _al = 0x05;                                   //mov al, 5
    sub_13840();                                  //call sub_13840
    memory16(_ds, 0x9544) -= 0x64;                //sub word_1CF94, 64h
    memory(_ds, 0x12A0) = 1;                      //mov byte_14CF0, 1
    sub_120F0();                                  //call sub_120F0
    memory(_ds, 0x12A0) = 5;                      //mov byte_14CF0, 5
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
locret_114EF:                                     //locret_114EF:
    return;
}

void sub_114F0()
{
    memory16(_ds, _si + 7) += 1;                  //add word ptr [si+7], 1
    _push(_si);                                   //push si
    _ax = memory16(_ds, _si + 5);                 //mov ax, [si+5]
    _push(_ax);                                   //push ax
    _ax = memory16(_ds, _si + 7);                 //mov ax, [si+7]
    _push(_ax);                                   //push ax
    sub_107FD();                                  //call sub_107FD
    _si = _pop();                                 //pop si
    memory(_ds, _si + 3) = _al;                   //mov [si+3], al
    memory(_ds, _si + 20) = _cl;                  //mov [si+14h], cl
    memory(_ds, _si + 4) = _bl;                   //mov [si+4], bl
    _bl = memory(_ds, _si + 1);                   //mov bl, [si+1]
    _bh = 0x00;                                   //mov bh, 0
    _bx <<= 1;                                    //shl bx, 1
    _bx = memory16(_ds, _bx + 4065);              //mov bx, [bx+0FE1h]
    sub_12121();                                  //call sub_12121
    _al = memory(_ds, 0x1B9C);                    //mov al, byte_155EC
    if (_al == 0x11)                              //jz short loc_11548
      goto loc_11548;
    _ax = memory16(_ds, _si + 5);                 //mov ax, [si+5]
    _flags.sign = (short)(_ax - memory16(_ds, 0x1B8F)) < 0;
    _ax = _ax - memory16(_ds, 0x1B8F);
    if (!_flags.sign)                              //jns short loc_1152A
      goto loc_1152A;
    _ax = -_ax;                                   //neg ax
loc_1152A:                                        //loc_1152A:
    if (_ax >= 0x1a)                              //jnb short loc_11548
      goto loc_11548;
    _ax = memory16(_ds, _si + 7);                 //mov ax, [si+7]
    _flags.sign = (short)(_ax - memory16(_ds, 0x1B91)) < 0;
    _ax = _ax - memory16(_ds, 0x1B91);
    if (!_flags.sign)                              //jns short loc_1153A
      goto loc_1153A;
    _ax = -_ax;                                   //neg ax
loc_1153A:                                        //loc_1153A:
    if (_ax >= 0x12)                              //jnb short loc_11548
      goto loc_11548;
    memory16(_ds, 0x9544) -= 0x0c;                //sub word_1CF94, 0Ch
    memory(_ds, _si + 21) = 0xff;                 //mov byte ptr [si+15h], 0FFh
loc_11548:                                        //loc_11548:
    _di = 0x1ba1;                                 //mov di, 1BA1h
loc_1154B:                                        //loc_1154B:
    _al = memory(_ds, _si + 21);                  //mov al, [si+15h]
    if ((char)_al >= (char)0x00)                  //jge short loc_11561
      goto loc_11561;
    _al = 0x07;                                   //mov al, 7
    sub_13840();                                  //call sub_13840
    sub_120F0();                                  //call sub_120F0
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
    sub_12676();                                  //call sub_12676
    return;                                       //retn
loc_11561:                                        //loc_11561:
    _al = memory(_ds, _di);                       //mov al, [di]
    if (_al & 0x80)                               //jnz short loc_115C0
      goto loc_115C0;
    if (!(_al & 0x40))                            //jz short loc_115BB
      goto loc_115BB;
    _push(_di);                                   //push di
    _ax = memory16(_ds, _di + 5);                 //mov ax, [di+5]
    _flags.sign = (short)(_ax - memory16(_ds, _si + 5)) < 0;
    _ax = _ax - memory16(_ds, _si + 5);
    if (!_flags.sign)                              //jns short loc_11576
      goto loc_11576;
    _ax = -_ax;                                   //neg ax
loc_11576:                                        //loc_11576:
    if (_ax >= 0x14)                              //jnb short loc_115BA
      goto loc_115BA;
    _ax = memory16(_ds, _di + 7);                 //mov ax, [di+7]
    _flags.sign = (short)(_ax - memory16(_ds, _si + 7)) < 0;
    _ax = _ax - memory16(_ds, _si + 7);
    if (!_flags.sign)                              //jns short loc_11585
      goto loc_11585;
    _ax = -_ax;                                   //neg ax
loc_11585:                                        //loc_11585:
    if (_ax >= 0x10)                              //jnb short loc_115BA
      goto loc_115BA;
    _al = memory(_ds, _di + 18);                  //mov al, [di+12h]
    if (_al != 0x19)                              //jnz short loc_1159A
      goto loc_1159A;
    memory(_ds, _si + 21) = 0xff;                 //mov byte ptr [si+15h], 0FFh
    memory(_ds, _di) = 0;                         //mov byte ptr [di], 0
    goto loc_115BA;                               //jmp short loc_115BA
loc_1159A:                                        //loc_1159A:
    _al = memory(_ds, _di + 3);                   //mov al, [di+3]
    _flags.sign = (char)(_al - memory(_ds, _si + 3)) < 0;
    _al = _al - memory(_ds, _si + 3);
    if (!_flags.sign)                              //jns short loc_115A4
      goto loc_115A4;
    _al = -_al;                                   //neg al
loc_115A4:                                        //loc_115A4:
    if (_al >= 0x10)                              //jnb short loc_115BA
      goto loc_115BA;
    memory(_ds, _si + 21) -= 1;                   //dec byte ptr [si+15h]
    _push(_si);                                   //push si
    _si = _di;                                    //mov si, di
    sub_12092();                                  //call sub_12092
    _al = 0x03;                                   //mov al, 3
    sub_13840();                                  //call sub_13840
    sub_12662();                                  //call sub_12662
    _si = _pop();                                 //pop si
loc_115BA:                                        //loc_115BA:
    _di = _pop();                                 //pop di
loc_115BB:                                        //loc_115BB:
    _di += 0x17;                                  //add di, 17h
    goto loc_1154B;                               //jmp short loc_1154B
loc_115C0:                                        //loc_115C0:
    _al = memory(_ds, 0x1B9C);                    //mov al, byte_155EC
    if (_al == 0x11)                              //jz short loc_115F8
      goto loc_115F8;
    _ax = memory16(_ds, 0x1B91);                  //mov ax, word_155E1
    if (_ax <= memory16(_ds, _si + 7))            //jbe short loc_115F8
      goto loc_115F8;
    _ax = memory16(_ds, 0x1B8F);                  //mov ax, word_155DF
    _flags.sign = (short)(_ax - memory16(_ds, _si + 5)) < 0;
    _ax = _ax - memory16(_ds, _si + 5);
    if (!_flags.sign)                              //jns short loc_115D9
      goto loc_115D9;
    _ax = -_ax;                                   //neg ax
loc_115D9:                                        //loc_115D9:
    if (_ax >= 0x20)                              //jnb short loc_115F8
      goto loc_115F8;
    memory(_ds, _si + 22) -= 1;                   //dec byte ptr [si+16h]
    if ((char)memory(_ds, _si + 22) >= 0)         //jns short loc_115EE
      goto loc_115EE;
    memory(_ds, _si + 22) = 7;                    //mov byte ptr [si+16h], 7
    memory(_ds, 0x9518) = 1;                      //mov byte_1CF68, 1
    goto loc_115F3;                               //jmp short loc_115F3
loc_115EE:                                        //loc_115EE:
    memory(_ds, 0x9518) = 0;                      //mov byte_1CF68, 0
loc_115F3:                                        //loc_115F3:
    _push(_si);                                   //push si
    sub_11DEF();                                  //call sub_11DEF
    _si = _pop();                                 //pop si
loc_115F8:                                        //loc_115F8:
    sub_110C6();                                  //call sub_110C6
}

void sub_115FC()
{
    sub_110C6();                                  //call sub_110C6
    _al = memory(_ds, _si);                       //mov al, [si]
    if (_al != 0x00)                              //jnz short loc_11606
      goto loc_11606;
    return;                                       //retn
loc_11606:                                        //loc_11606:
    _al = memory(_ds, _si + 1);                   //mov al, [si+1]
    if (_al != 0x02)                              //jnz short loc_11613
      goto loc_11613;
    memory16(_ds, _si + 7) += 8;                  //add word ptr [si+7], 8
    goto loc_1163D;                               //jmp short loc_1163D
loc_11613:                                        //loc_11613:
    if (_al != 0x00)                              //jnz short loc_1161D
      goto loc_1161D;
    memory16(_ds, _si + 5) -= 8;                  //sub word ptr [si+5], 8
    goto loc_1163D;                               //jmp short loc_1163D
loc_1161D:                                        //loc_1161D:
    if (_al != 0x01)                              //jnz short loc_1162B
      goto loc_1162B;
    memory16(_ds, _si + 5) -= 6;                  //sub word ptr [si+5], 6
    memory16(_ds, _si + 7) += 4;                  //add word ptr [si+7], 4
    goto loc_1163D;                               //jmp short loc_1163D
loc_1162B:                                        //loc_1162B:
    if (_al != 0x03)                              //jnz short loc_11639
      goto loc_11639;
    memory16(_ds, _si + 5) += 6;                  //add word ptr [si+5], 6
    memory16(_ds, _si + 7) += 4;                  //add word ptr [si+7], 4
    goto loc_1163D;                               //jmp short loc_1163D
loc_11639:                                        //loc_11639:
    memory16(_ds, _si + 5) += 8;                  //add word ptr [si+5], 8
loc_1163D:                                        //loc_1163D:
    memory16(_ds, _si + 7) &= 1023;               //and word ptr [si+7], 3FFh
    _ax = memory16(_ds, _si + 5);                 //mov ax, [si+5]
    if ((short)_ax >= (short)0x0004)              //jge short loc_1164E
      goto loc_1164E;
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
    return;                                       //retn
loc_1164E:                                        //loc_1164E:
    if ((short)_ax <= (short)0xfc)                //jle short loc_11657
      goto loc_11657;
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
    return;                                       //retn
loc_11657:                                        //loc_11657:
    _al = memory(_ds, _si + 4);                   //mov al, [si+4]
    if (_al != 0x01)                              //jnz short loc_1166B
      goto loc_1166B;
    _al = memory(_ds, _si + 3);                   //mov al, [si+3]
    if ((char)_al >= (char)0x64)                  //jge short loc_11669
      goto loc_11669;
    memory(_ds, _si + 3) += 4;                    //add byte ptr [si+3], 4
loc_11669:                                        //loc_11669:
    goto loc_1167A;                               //jmp short loc_1167A
loc_1166B:                                        //loc_1166B:
    if (_al != 0x02)                              //jnz short loc_1167A
      goto loc_1167A;
    _al = memory(_ds, _si + 3);                   //mov al, [si+3]
    if ((char)_al <= (char)0x9c)                  //jle short loc_1167A
      goto loc_1167A;
    memory(_ds, _si + 3) -= 4;                    //sub byte ptr [si+3], 4
loc_1167A:                                        //loc_1167A:
    _push(_si);                                   //push si
    _ax = memory16(_ds, _si + 5);                 //mov ax, [si+5]
    _push(_ax);                                   //push ax
    _ax = memory16(_ds, _si + 7);                 //mov ax, [si+7]
    _push(_ax);                                   //push ax
    sub_107FD();                                  //call sub_107FD
    _si = _pop();                                 //pop si
    if ((char)_al < (char)memory(_ds, _si + 3))   //jl short loc_11691
      goto loc_11691;
    sub_12092();                                  //call sub_12092
    goto locret_116D5;                            //jmp short locret_116D5
loc_11691:                                        //loc_11691:
    _al = memory(_ds, 0x1B9C);                    //mov al, byte_155EC
    if (_al != 0x11)                              //jnz short loc_11699
      goto loc_11699;
    return;                                       //retn
loc_11699:                                        //loc_11699:
    _ax = memory16(_ds, _si + 5);                 //mov ax, [si+5]
    _flags.sign = (short)(_ax - memory16(_ds, 0x1B8F)) < 0;
    _ax = _ax - memory16(_ds, 0x1B8F);
    if (!_flags.sign)                              //jns short loc_116A4
      goto loc_116A4;
    _ax = -_ax;                                   //neg ax
loc_116A4:                                        //loc_116A4:
    if (_ax >= 0x0c)                              //jnb short locret_116D5
      goto locret_116D5;
    _ax = memory16(_ds, _si + 7);                 //mov ax, [si+7]
    _flags.sign = (short)(_ax - memory16(_ds, 0x1B91)) < 0;
    _ax = _ax - memory16(_ds, 0x1B91);
    if (!_flags.sign)                              //jns short loc_116B4
      goto loc_116B4;
    _ax = -_ax;                                   //neg ax
loc_116B4:                                        //loc_116B4:
    if (_ax >= 0x0008)                            //jnb short locret_116D5
      goto locret_116D5;
    _al = memory(_ds, _si + 3);                   //mov al, [si+3]
    _flags.sign = (char)(_al - memory(_ds, 0x1B8D)) < 0;
    _al = _al - memory(_ds, 0x1B8D);
    if (!_flags.sign)                              //jns short loc_116C4
      goto loc_116C4;
    _al = -_al;                                   //neg al
loc_116C4:                                        //loc_116C4:
    if (_al >= 0x10)                              //jnb short locret_116D5
      goto locret_116D5;
    memory16(_ds, 0x9544) -= 1;                   //sub word_1CF94, 1
    sub_12092();                                  //call sub_12092
    _al = 0x04;                                   //mov al, 4
    sub_13840();                                  //call sub_13840
locret_116D5:                                     //locret_116D5:
    return;
}

void sub_116D6()
{
    memory(_ds, _si + 4) -= 1;                    //dec byte ptr [si+4]
    if ((char)memory(_ds, _si + 4) >= 0)          //jns short locret_116DE
      goto locret_116DE;
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
locret_116DE:                                     //locret_116DE:
    return;
}

void sub_116DF()
{
    _al = memory(_ds, _si + 4);                   //mov al, [si+4]
    memory(_ds, _si + 4) += 1;                    //inc byte ptr [si+4]
    if (_al < 0x04)                               //jb short loc_116ED
      goto loc_116ED;
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
    return;                                       //retn
loc_116ED:                                        //loc_116ED:
    _al <<= 1;                                    //shl al, 1
    _bl = _al;                                    //mov bl, al
    _bh = 0x00;                                   //mov bh, 0
    _ax = memory16(_ds, _bx + 5182);              //mov ax, [bx+143Eh]
    memory16(_ds, _si + 15) = _ax;                //mov [si+0Fh], ax
    sub_110C6();                                  //call sub_110C6
}

void sub_116FE()
{
    memory(_ds, _si + 22) += 1;                   //inc byte ptr [si+16h]
    _al = memory(_ds, _si + 22);                  //mov al, [si+16h]
    _al >>= 1;                                    //shr al, 1
    _al >>= 1;                                    //shr al, 1
    _al &= 0x07;                                  //and al, 7
    if ((char)_al < (char)0x05)                   //jl short loc_11712
      goto loc_11712;
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
    return;                                       //retn
loc_11712:                                        //loc_11712:
    memory(_ds, _si + 4) = _al;                   //mov [si+4], al
    _bx = 0x12b5;                                 //mov bx, 12B5h
    sub_12121();                                  //call sub_12121
    sub_110C6();                                  //call sub_110C6
}

void sub_1171F()
{
    memory(_ds, _si + 22) += 1;                   //inc byte ptr [si+16h]
    _al = memory(_ds, _si + 22);                  //mov al, [si+16h]
    _al >>= 1;                                    //shr al, 1
    _al >>= 1;                                    //shr al, 1
    _al &= 0x07;                                  //and al, 7
    if ((char)_al < (char)0x06)                   //jl short loc_11733
      goto loc_11733;
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
    return;                                       //retn
loc_11733:                                        //loc_11733:
    memory(_ds, _si + 4) = _al;                   //mov [si+4], al
    _bx = 0x12f5;                                 //mov bx, 12F5h
    sub_12121();                                  //call sub_12121
    sub_110C6();                                  //call sub_110C6
}

void sub_11740()
{
    memory(_ds, _si + 22) += 1;                   //inc byte ptr [si+16h]
    _al = memory(_ds, _si + 22);                  //mov al, [si+16h]
    _al &= 0x07;                                  //and al, 7
    if ((char)_al < (char)0x04)                   //jl short loc_11762
      goto loc_11762;
    _al = memory(_ds, _si);                       //mov al, [si]
    if (!(_al & 0x20))                            //jz short loc_11759
      goto loc_11759;
    memory(_ds, 0x9517) &= 0x7f;                  //and byte_1CF67, 7Fh
    goto loc_1175E;                               //jmp short loc_1175E
loc_11759:                                        //loc_11759:
    memory(_ds, 0x9517) &= 0xfe;                  //and byte_1CF67, 0FEh
loc_1175E:                                        //loc_1175E:
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
    return;                                       //retn
loc_11762:                                        //loc_11762:
    memory(_ds, _si + 4) = _al;                   //mov [si+4], al
    _bx = 0x133d;                                 //mov bx, 133Dh
    sub_12121();                                  //call sub_12121
}

void sub_1176C()
{
    memory(_ds, _si + 22) += 1;                   //inc byte ptr [si+16h]
    _al = memory(_ds, _si + 22);                  //mov al, [si+16h]
    _al >>= 1;                                    //shr al, 1
    _al &= 0x03;                                  //and al, 3
    memory(_ds, _si + 4) = _al;                   //mov [si+4], al
    _bx = 0x0e2b;                                 //mov bx, 0E2Bh
    sub_12121();                                  //call sub_12121
    sub_110C6();                                  //call sub_110C6
}

void sub_11783()
{
    memory(_ds, _si + 22) += 1;                   //inc byte ptr [si+16h]
    _al = memory(_ds, _si + 22);                  //mov al, [si+16h]
    _al >>= 1;                                    //shr al, 1
    _al &= 0x07;                                  //and al, 7
    if (_al < 0x06)                               //jb short loc_11797
      goto loc_11797;
    _al = 0x00;                                   //mov al, 0
    memory(_ds, _si + 22) = 0;                    //mov byte ptr [si+16h], 0
loc_11797:                                        //loc_11797:
    _bl = _al;                                    //mov bl, al
    _bh = 0x00;                                   //mov bh, 0
    _al = memory(_ds, _bx + 3660);                //mov al, [bx+0E4Ch]
    memory(_ds, _si + 4) = _al;                   //mov [si+4], al
    _bx = 0x0e52;                                 //mov bx, 0E52h
    sub_12121();                                  //call sub_12121
    sub_110C6();                                  //call sub_110C6
}

void sub_117AC()
{
    sub_1215B();                                  //call sub_1215B
    if (_cx == 0x0000)                            //jz short loc_117CC
      goto loc_117CC;
    memory(_ds, _si + 22) -= 1;                   //dec byte ptr [si+16h]
    if ((char)memory(_ds, _si + 22) >= 0)         //jns short loc_117C4
      goto loc_117C4;
    memory(_ds, _si + 22) = 8;                    //mov byte ptr [si+16h], 8
    memory(_ds, 0x9518) = 1;                      //mov byte_1CF68, 1
    goto loc_117C9;                               //jmp short loc_117C9
loc_117C4:                                        //loc_117C4:
    memory(_ds, 0x9518) = 0;                      //mov byte_1CF68, 0
loc_117C9:                                        //loc_117C9:
    sub_11F0B();                                  //call sub_11F0B
loc_117CC:                                        //loc_117CC:
    _bx = 0x0e73;                                 //mov bx, 0E73h
    sub_12121();                                  //call sub_12121
    sub_110C6();                                  //call sub_110C6
}

void sub_117D6()
{
    sub_1215B();                                  //call sub_1215B
    if (_cx == 0x0000)                            //jz short loc_117EA
      goto loc_117EA;
    memory(_ds, _si + 22) -= 1;                   //dec byte ptr [si+16h]
    if ((char)memory(_ds, _si + 22) >= 0)         //jns short loc_117EA
      goto loc_117EA;
    memory(_ds, _si + 22) = 0x12;                 //mov byte ptr [si+16h], 12h
    sub_12005();                                  //call sub_12005
loc_117EA:                                        //loc_117EA:
    _bx = 0x0e9c;                                 //mov bx, 0E9Ch
    sub_12121();                                  //call sub_12121
    sub_110C6();                                  //call sub_110C6
}

void sub_117F4()
{
    sub_110C6();                                  //call sub_110C6
    _al = memory(_ds, _si);                       //mov al, [si]
    if (_al != 0x00)                              //jnz short loc_117FE
      goto loc_117FE;
    return;                                       //retn
loc_117FE:                                        //loc_117FE:
    _al = memory(_ds, _si + 1);                   //mov al, [si+1]
    if (_al != 0x02)                              //jnz short loc_1180B
      goto loc_1180B;
    memory16(_ds, _si + 7) += 3;                  //add word ptr [si+7], 3
    goto loc_11835;                               //jmp short loc_11835
loc_1180B:                                        //loc_1180B:
    if (_al != 0x00)                              //jnz short loc_11815
      goto loc_11815;
    memory16(_ds, _si + 5) -= 4;                  //sub word ptr [si+5], 4
    goto loc_11835;                               //jmp short loc_11835
loc_11815:                                        //loc_11815:
    if (_al != 0x01)                              //jnz short loc_11823
      goto loc_11823;
    memory16(_ds, _si + 5) -= 4;                  //sub word ptr [si+5], 4
    memory16(_ds, _si + 7) += 3;                  //add word ptr [si+7], 3
    goto loc_11835;                               //jmp short loc_11835
loc_11823:                                        //loc_11823:
    if (_al != 0x03)                              //jnz short loc_11831
      goto loc_11831;
    memory16(_ds, _si + 5) += 4;                  //add word ptr [si+5], 4
    memory16(_ds, _si + 7) += 3;                  //add word ptr [si+7], 3
    goto loc_11835;                               //jmp short loc_11835
loc_11831:                                        //loc_11831:
    memory16(_ds, _si + 5) += 4;                  //add word ptr [si+5], 4
loc_11835:                                        //loc_11835:
    memory16(_ds, _si + 7) &= 1023;               //and word ptr [si+7], 3FFh
    _ax = memory16(_ds, _si + 5);                 //mov ax, [si+5]
    if ((short)_ax >= (short)0x0008)              //jge short loc_11846
      goto loc_11846;
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
    return;                                       //retn
loc_11846:                                        //loc_11846:
    if ((short)_ax <= (short)0xf8)                //jle short loc_1184F
      goto loc_1184F;
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
    return;                                       //retn
loc_1184F:                                        //loc_1184F:
    memory(_ds, _si + 22) += 1;                   //inc byte ptr [si+16h]
    _bl = memory(_ds, _si + 22);                  //mov bl, [si+16h]
    if (_bl < 0x10)                               //jb short loc_1185E
      goto loc_1185E;
    sub_12099();                                  //call sub_12099
    return;                                       //retn
loc_1185E:                                        //loc_1185E:
    _bh = 0x00;                                   //mov bh, 0
    _al = memory(_ds, _bx + 5223);                //mov al, [bx+1467h]
    memory(_ds, _si + 3) += _al;                  //add [si+3], al
    _al = memory(_ds, 0x1B9C);                    //mov al, byte_155EC
    if (_al != 0x11)                              //jnz short loc_1186F
      goto loc_1186F;
    return;                                       //retn
loc_1186F:                                        //loc_1186F:
    _ax = memory16(_ds, _si + 5);                 //mov ax, [si+5]
    _flags.sign = (short)(_ax - memory16(_ds, 0x1B8F)) < 0;
    _ax = _ax - memory16(_ds, 0x1B8F);
    if (!_flags.sign)                              //jns short loc_1187A
      goto loc_1187A;
    _ax = -_ax;                                   //neg ax
loc_1187A:                                        //loc_1187A:
    if (_ax >= 0x0e)                              //jnb short locret_118A8
      goto locret_118A8;
    _ax = memory16(_ds, _si + 7);                 //mov ax, [si+7]
    _flags.sign = (short)(_ax - memory16(_ds, 0x1B91)) < 0;
    _ax = _ax - memory16(_ds, 0x1B91);
    if (!_flags.sign)                              //jns short loc_1188A
      goto loc_1188A;
    _ax = -_ax;                                   //neg ax
loc_1188A:                                        //loc_1188A:
    if (_ax >= 0x0a)                              //jnb short locret_118A8
      goto locret_118A8;
    _al = memory(_ds, _si + 3);                   //mov al, [si+3]
    _flags.sign = (char)(_al - memory(_ds, 0x1B8D)) < 0;
    _al = _al - memory(_ds, 0x1B8D);
    if (!_flags.sign)                              //jns short loc_1189A
      goto loc_1189A;
    _al = -_al;                                   //neg al
loc_1189A:                                        //loc_1189A:
    if (_al >= 0x10)                              //jnb short locret_118A8
      goto locret_118A8;
    memory16(_ds, 0x9544) -= 0x0a;                //sub word_1CF94, 0Ah
    _al = 0x05;                                   //mov al, 5
    sub_13840();                                  //call sub_13840
locret_118A8:                                     //locret_118A8:
    return;
}

void sub_118A9()
{
    sub_1215B();                                  //call sub_1215B
    if (_cx == 0x0000)                            //jz short loc_118BD
      goto loc_118BD;
    memory(_ds, _si + 22) -= 1;                   //dec byte ptr [si+16h]
    if ((char)memory(_ds, _si + 22) >= 0)         //jns short loc_118BD
      goto loc_118BD;
    memory(_ds, _si + 22) = 0x28;                 //mov byte ptr [si+16h], 28h
    sub_11FBA();                                  //call sub_11FBA
loc_118BD:                                        //loc_118BD:
    _bx = 0x0ec5;                                 //mov bx, 0EC5h
    sub_12121();                                  //call sub_12121
    sub_110C6();                                  //call sub_110C6
}

void sub_118C7()
{
    _al = memory(_ds, 0x952E);                    //mov al, byte_1CF7E
    _al = _al & memory(_ds, 0x952F);              //and al, byte_1CF7F
    _al = _al & memory(_ds, 0x9530);              //and al, byte_1CF80
    _al = _al & memory(_ds, 0x9531);              //and al, byte_1CF81
    _al = _al & memory(_ds, 0x9532);              //and al, byte_1CF82
    _al = _al & memory(_ds, 0x9533);              //and al, byte_1CF83
    if (_al != 0)                                 //jnz short loc_118E4
      goto loc_118E4;
    sub_110C6();                                  //call sub_110C6
    return;                                       //retn
loc_118E4:                                        //loc_118E4:
    _ax = memory16(_ds, 0x1B8F);                  //mov ax, word_155DF
    _ax = _ax - memory16(_ds, _si + 5);           //sub ax, [si+5]
    _ASSERT(0);
//    _flags.sign = (_FIXME_)(_ax - 0x0c) < 0;      //sub ax, 0Ch
    _ax -= 0x0c;
    if (!_flags.sign)                              //jns short loc_118F1
      goto loc_118F1;
    _ax = -_ax;                                   //neg ax
loc_118F1:                                        //loc_118F1:
    _cx = memory16(_ds, 0x1B91);                  //mov cx, word_155E1
    _cx -= 0x0008;                                //sub cx, 8
    _flags.sign = (short)(_cx - memory16(_ds, _si + 7)) < 0;
    _cx = _cx - memory16(_ds, _si + 7);
    if (!_flags.sign)                              //jns short loc_118FF
      goto loc_118FF;
    _cx = -_cx;                                   //neg cx
loc_118FF:                                        //loc_118FF:
    _bl = memory(_ds, _si + 4);                   //mov bl, [si+4]
    _bl >>= 1;                                    //shr bl, 1
    _ax += _cx;                                   //add ax, cx
    if (_ax > 0x40)                               //ja short loc_11915
      goto loc_11915;
    if (_bl == 0x08)                              //jz short loc_11913
      goto loc_11913;
    memory(_ds, _si + 4) += 1;                    //inc byte ptr [si+4]
loc_11913:                                        //loc_11913:
    goto loc_1191D;                               //jmp short loc_1191D
loc_11915:                                        //loc_11915:
    if (_bl == 0x00)                              //jz short loc_1191D
      goto loc_1191D;
    memory(_ds, _si + 4) -= 1;                    //dec byte ptr [si+4]
loc_1191D:                                        //loc_1191D:
    _push(_bx);                                   //push bx
    _bh = 0x00;                                   //mov bh, 0
    _bx <<= 1;                                    //shl bx, 1
    _ax = memory16(_ds, _bx + 5251);              //mov ax, [bx+1483h]
    memory16(_ds, _si + 15) = _ax;                //mov [si+0Fh], ax
    _bx = _pop();                                 //pop bx
    if (_bl < 0x02)                               //jb short loc_1196B
      goto loc_1196B;
    _ax = memory16(_ds, 0x1B8F);                  //mov ax, word_155DF
    _ax = _ax - memory16(_ds, _si + 5);           //sub ax, [si+5]
    _ASSERT(0);
    //_flags.sign = (_FIXME_)(_ax - 0x0c) < 0;      //sub ax, 0Ch
    _ax -= 0x0c;
    if (!_flags.sign)                              //jns short loc_11947
      goto loc_11947;
    _ax = -_ax;                                   //neg ax
    if (_ax > 0x18)                               //ja short loc_11945
      goto loc_11945;
    memory16(_ds, 0x1B8F) += 1;                   //inc word_155DF
loc_11945:                                        //loc_11945:
    goto loc_11952;                               //jmp short loc_11952
loc_11947:                                        //loc_11947:
    if (_ax == 0)                                 //jz short loc_11952
      goto loc_11952;
    if (_ax > 0x18)                               //ja short loc_11952
      goto loc_11952;
    memory16(_ds, 0x1B8F) -= 1;                   //dec word_155DF
loc_11952:                                        //loc_11952:
    if (_bl != 0x08)                              //jnz short loc_1196B
      goto loc_1196B;
    if (_cx > 0x0008)                             //ja short loc_1196B
      goto loc_1196B;
    if (_ax > 0x0008)                             //ja short loc_1196B
      goto loc_1196B;
    _al = memory(_ds, 0x1B9C);                    //mov al, byte_155EC
    if (_al == 0x11)                              //jz short loc_1196B
      goto loc_1196B;
    sub_1196F();                                  //call sub_1196F
loc_1196B:                                        //loc_1196B:
    sub_110C6();                                  //call sub_110C6
}

void sub_11993()
{
    sub_11A04();                                  //call sub_11A04
    _al = memory(_ds, 0x94FF);                    //mov al, byte_1CF4F
    if (_al != 0x01)                              //jnz short locret_119C1
      goto locret_119C1;
    _al = memory(_ds, 0x9501);                    //mov al, byte_1CF51
    _bl = _al;                                    //mov bl, al
    _al <<= 1;                                    //shl al, 1
    _bl += _al;                                   //add bl, al
    _bl = _bl + memory(_ds, 0x9502);              //add bl, byte_1CF52
    _bh = 0x00;                                   //mov bh, 0
    _bx <<= 1;                                    //shl bx, 1
    _ax = memory16(_ds, _bx + 5269);              //mov ax, [bx+1495h]
    _bh = _ah;                                    //mov bh, ah
    _ax &= 0x03ff;                                //and ax, 3FFh
    memory16(_ds, 0x950C) = _ax;                  //mov word_1CF5C, ax
    _bh &= 0xc0;                                  //and bh, 0C0h
    memory(_ds, 0x951D) = _bh;                    //mov byte_1CF6D, bh
locret_119C1:                                     //locret_119C1:
    return;
}

void sub_119C2()
{
    sub_11A04();                                  //call sub_11A04
    _al = memory(_ds, 0x94FF);                    //mov al, byte_1CF4F
    if (_al != 0x01)                              //jnz short locret_11A03
      goto locret_11A03;
    _al = memory(_ds, 0x9501);                    //mov al, byte_1CF51
    _bl = _al;                                    //mov bl, al
    _al <<= 1;                                    //shl al, 1
    _bl += _al;                                   //add bl, al
    _bl = _bl + memory(_ds, 0x9502);              //add bl, byte_1CF52
    _bh = 0x00;                                   //mov bh, 0
    _bx <<= 1;                                    //shl bx, 1
    _ax = memory16(_ds, _bx + 5317);              //mov ax, [bx+14C5h]
    _bh = _ah;                                    //mov bh, ah
    _ax &= 0x03ff;                                //and ax, 3FFh
    memory16(_ds, 0x950C) = _ax;                  //mov word_1CF5C, ax
    _bh &= 0xc0;                                  //and bh, 0C0h
    memory(_ds, 0x951D) = _bh;                    //mov byte_1CF6D, bh
    memory(_ds, 0x950E) = 1;                      //mov byte_1CF5E, 1
    _al = memory(_ds, 0x9502);                    //mov al, byte_1CF52
    _al += 1;                                     //inc al
    if (_al <= 0x02)                              //jbe short loc_11A00
      goto loc_11A00;
    _al = 0x00;                                   //mov al, 0
loc_11A00:                                        //loc_11A00:
    memory(_ds, 0x9502) = _al;                    //mov byte_1CF52, al
locret_11A03:                                     //locret_11A03:
    return;
}

void sub_11A9E()
{
    sub_110C6();                                  //call sub_110C6
    _al = memory(_ds, _si);                       //mov al, [si]
    if (_al != 0x00)                              //jnz short loc_11AA8
      goto loc_11AA8;
    return;                                       //retn
loc_11AA8:                                        //loc_11AA8:
    _bx = memory16(_ds, 0x1B91);                  //mov bx, word_155E1
    _flags.sign = (short)(_bx - memory16(_ds, _si + 7)) < 0;
    _bx = _bx - memory16(_ds, _si + 7);
    if (!_flags.sign)                              //jns short loc_11ABB
      goto loc_11ABB;
    if ((short)_bx >= (short)0xfff0)              //jge short locret_11ABA
      goto locret_11ABA;
    memory(_ds, _si + 2) = 1;                     //mov byte ptr [si+2], 1
locret_11ABA:                                     //locret_11ABA:
    return;                                       //retn
loc_11ABB:                                        //loc_11ABB:
    if ((short)_bx <= (short)0x20)                //jle short loc_11AC1
      goto loc_11AC1;
    return;                                       //retn
loc_11AC1:                                        //loc_11AC1:
    _ax = memory16(_ds, 0x1B8F);                  //mov ax, word_155DF
    _ax = _ax - memory16(_ds, _si + 5);           //sub ax, [si+5]
    _ax -= 0x0c;
    _flags.sign = (short)(_ax) < 0;      //sub ax, 0Ch
    if (!_flags.sign)                              //jns short loc_11AD9
      goto loc_11AD9;
    _ax = -_ax;                                   //neg ax
    if (_ax >= 0x18)                              //jnb short loc_11AD7
      goto loc_11AD7;
    memory16(_ds, 0x1B8F) += 1;                   //inc word_155DF
loc_11AD7:                                        //loc_11AD7:
    goto loc_11AE7;                               //jmp short loc_11AE7
loc_11AD9:                                        //loc_11AD9:
    if (_ax >= 0x18)                              //jnb short loc_11AE7
      goto loc_11AE7;
    if (_ax == 0x0000)                            //jz short loc_11AE7
      goto loc_11AE7;
    memory16(_ds, 0x1B8F) -= 1;                   //dec word_155DF
loc_11AE7:                                        //loc_11AE7:
    if (_bx <= 0x0008)                            //jbe short loc_11AED
      goto loc_11AED;
    return;                                       //retn
loc_11AED:                                        //loc_11AED:
    if (_ax > 0x0002)                             //ja short loc_11AF8
      goto loc_11AF8;
    memory16(_ds, 0x9538) += 1;                   //inc word_1CF88
    goto locret_11B08;                            //jmp short locret_11B08
loc_11AF8:                                        //loc_11AF8:
    if (_ax >= 0x24)                              //jnb short locret_11B08
      goto locret_11B08;
    memory16(_ds, 0x9542) = 0;                    //mov word_1CF92, 0
    _al = 0x06;                                   //mov al, 6
    sub_13840();                                  //call sub_13840
locret_11B08:                                     //locret_11B08:
    return;
}

void sub_11B09()
{
    sub_110C6();                                  //call sub_110C6
    _al = memory(_ds, _si);                       //mov al, [si]
    if (_al != 0x00)                              //jnz short loc_11B13
      goto loc_11B13;
    return;                                       //retn
loc_11B13:                                        //loc_11B13:
    _al = memory(_ds, 0x1B9C);                    //mov al, byte_155EC
    if (_al != 0x11)                              //jnz short loc_11B1B
      goto loc_11B1B;
    return;                                       //retn
loc_11B1B:                                        //loc_11B1B:
    _ax = memory16(_ds, _si + 5);                 //mov ax, [si+5]
    _flags.sign = (short)(_ax - memory16(_ds, 0x1B8F)) < 0;
    _ax = _ax - memory16(_ds, 0x1B8F);
    if (!_flags.sign)                              //jns short loc_11B26
      goto loc_11B26;
    _ax = -_ax;                                   //neg ax
loc_11B26:                                        //loc_11B26:
    if (_ax >= 0x12)                              //jnb short locret_11B49
      goto locret_11B49;
    _ax = memory16(_ds, _si + 7);                 //mov ax, [si+7]
    _flags.sign = (short)(_ax - memory16(_ds, 0x1B91)) < 0;
    _ax = _ax - memory16(_ds, 0x1B91);
    if (!_flags.sign)                              //jns short loc_11B36
      goto loc_11B36;
    _ax = -_ax;                                   //neg ax
loc_11B36:                                        //loc_11B36:
    if (_ax >= 0x10)                              //jnb short locret_11B49
      goto locret_11B49;
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
    _al = memory(_ds, _si + 1);                   //mov al, [si+1]
    sub_12B28();                                  //call sub_12B28
    _al = 0x0a;                                   //mov al, 0Ah
    sub_13840();                                  //call sub_13840
locret_11B49:                                     //locret_11B49:
    return;
}

void sub_11B4A()
{
    memory16(_ds, _si + 7) -= 2;                  //sub word ptr [si+7], 2
    memory16(_ds, _si + 7) &= 1023;               //and word ptr [si+7], 3FFh
    sub_110A0();                                  //call sub_110A0
}

void sub_12200()
{
    sub_1250B();                                  //call sub_1250B
    sub_12553();                                  //call sub_12553
    sub_1259B();                                  //call sub_1259B
    sub_1237C();                                  //call sub_1237C
}

void sub_122B1()
{
    memory16(_ds, 0x9534) = 3;                    //mov word_1CF84, 3
    sub_122E1();                                  //call sub_122E1
    sub_122F9();                                  //call sub_122F9
    sub_12311();                                  //call sub_12311
}

void sub_1239B()
{
    memory16(_ds, 0x9536) += 1;                   //inc word_1CF86
    _ax = memory16(_ds, 0x9536);                  //mov ax, word_1CF86
    if (_ax <= 0x0006)                            //jbe short loc_123AE
      goto loc_123AE;
    memory16(_ds, 0x9536) = 6;                    //mov word_1CF86, 6
    return;                                       //retn
loc_123AE:                                        //loc_123AE:
    _push(_ax);                                   //push ax
    _al = 0x08;                                   //mov al, 8
    sub_13840();                                  //call sub_13840
    _ax = _pop();                                 //pop ax
    if (_ax == 0x0001)                            //jz short sub_123D4
    {sub_123D4(); return;}
    if (_ax == 0x0002)                            //jz short sub_123EC
    {sub_123EC(); return;}
    if (_ax == 0x0003)                            //jz short sub_12404
    {sub_12404(); return;}
    if (_ax == 0x0004)                            //jz short sub_1241C
    {sub_1241C(); return;}
    if (_ax == 0x0005)                            //jz short sub_12434
    {sub_12434(); return;}
    if (_ax == 0x0006)                            //jz short sub_1244C
    {sub_1244C(); return;}
}

void sub_12464()
{
    _ax = memory16(_ds, 0x9536);                  //mov ax, word_1CF86
    memory16(_ds, 0x9536) -= 1;                   //dec word_1CF86
    if ((short)memory16(_ds, 0x9536) >= 0)        //jns short loc_12474
      goto loc_12474;
    memory16(_ds, 0x9536) = 0;                    //mov word_1CF86, 0
    return;                                       //retn
loc_12474:                                        //loc_12474:
    if (_ax == 0x0001)                            //jz short loc_12493
      goto loc_12493;
    if (_ax == 0x0002)                            //jz short loc_124A7
      goto loc_124A7;
    if (_ax == 0x0003)                            //jz short loc_124BB
      goto loc_124BB;
    if (_ax == 0x0004)                            //jz short loc_124CF
      goto loc_124CF;
    if (_ax == 0x0005)                            //jz short loc_124E3
      goto loc_124E3;
    if (_ax == 0x0006)                            //jz short loc_124F7
      goto loc_124F7;
    return;                                       //retn
loc_12493:                                        //loc_12493:
    _ax = 0x1b99;                                 //mov ax, 1B99h
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    _ax = 0x0f;                                   //mov ax, 0Fh
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    sub_12D9A();                                  //call sub_12D9A
    return;                                       //retn
loc_124A7:                                        //loc_124A7:
    _ax = 0x1b9b;                                 //mov ax, 1B9Bh
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    _ax = 0x0f;                                   //mov ax, 0Fh
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    sub_12D9A();                                  //call sub_12D9A
    return;                                       //retn
loc_124BB:                                        //loc_124BB:
    _ax = 0x1b9d;                                 //mov ax, 1B9Dh
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    _ax = 0x0f;                                   //mov ax, 0Fh
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    sub_12D9A();                                  //call sub_12D9A
    return;                                       //retn
loc_124CF:                                        //loc_124CF:
    _ax = 0x1b9f;                                 //mov ax, 1B9Fh
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    _ax = 0x0f;                                   //mov ax, 0Fh
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    sub_12D9A();                                  //call sub_12D9A
    return;                                       //retn
loc_124E3:                                        //loc_124E3:
    _ax = 0x1ba1;                                 //mov ax, 1BA1h
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    _ax = 0x0f;                                   //mov ax, 0Fh
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    sub_12D9A();                                  //call sub_12D9A
    return;                                       //retn
loc_124F7:                                        //loc_124F7:
    _ax = 0x1ba3;                                 //mov ax, 1BA3h
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    _ax = 0x0f;                                   //mov ax, 0Fh
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    sub_12D9A();                                  //call sub_12D9A
}

void sub_1252F()
{
    _ax = memory16(_ds, 0x953A);                  //mov ax, word_1CF8A
    _ax -= 1;                                     //dec ax
    if ((short)_ax >= 0)                          //jns short sub_12536
      sub_12536();
}

void sub_12542()
{
    _ax = memory16(_ds, 0x953A);                  //mov ax, word_1CF8A
    if (_ax < 0x2c)                               //jb short loc_1254B
      goto loc_1254B;
    return;                                       //retn
loc_1254B:                                        //loc_1254B:
    sub_12536();                                  //call sub_12536
    memory16(_ds, 0x953A) += 1;                   //inc word_1CF8A
}

void sub_12577()
{
    _ax = memory16(_ds, 0x953E);                  //mov ax, word_1CF8E
    _ax -= 1;                                     //dec ax
    if ((short)_ax >= 0)                          //jns short sub_1257E
      sub_1257E();
}

void sub_1258A()
{
    _ax = memory16(_ds, 0x953E);                  //mov ax, word_1CF8E
    if (_ax < 0x30)                               //jb short loc_12593
      goto loc_12593;
    return;                                       //retn
loc_12593:                                        //loc_12593:
    sub_1257E();                                  //call sub_1257E
    memory16(_ds, 0x953E) += 1;                   //inc word_1CF8E
}

void sub_125BF()
{
    _ax = memory16(_ds, 0x9542);                  //mov ax, word_1CF92
    _ax -= 1;                                     //dec ax
    if ((short)_ax >= 0)                          //jns short sub_125C6
      sub_125C6();
}

void sub_125D2()
{
    _ax = memory16(_ds, 0x9542);                  //mov ax, word_1CF92
    if (_ax < 0x38)                               //jb short loc_125DB
      goto loc_125DB;
    return;                                       //retn
loc_125DB:                                        //loc_125DB:
    sub_125C6();                                  //call sub_125C6
    memory16(_ds, 0x9542) += 1;                   //inc word_1CF92
}

void sub_1264A()
{
    _al = 0x00;                                   //mov al, 0
    memory(_ds, 0x94A9) = _al;                    //mov byte_1CEF9, al
    memory(_ds, 0x94AA) = _al;                    //mov byte_1CEFA, al
    memory(_ds, 0x94AB) = _al;                    //mov byte_1CEFB, al
    memory(_ds, 0x94AC) = _al;                    //mov byte_1CEFC, al
    memory(_ds, 0x94AD) = _al;                    //mov byte_1CEFD, al
    memory(_ds, 0x94AE) = _al;                    //mov byte_1CEFE, al
    sub_12714();                                  //call sub_12714
}

void sub_1269E()
{
    _push(_bp);                                   //push bp
    _bp = _sp;                                    //mov bp, sp
    _al = memory(_ds, 0x94AE);                    //mov al, byte_1CEFE
    _al = _al + stack16(_bp, 4);                  //add al, [bp+arg_0]
    if (_al <= 0x09)                              //jbe short loc_126B1
      goto loc_126B1;
    _al -= 0x0a;                                  //sub al, 0Ah
    memory(_ds, 0x94AD) += 1;                     //inc byte_1CEFD
loc_126B1:                                        //loc_126B1:
    memory(_ds, 0x94AE) = _al;                    //mov byte_1CEFE, al
    _al = memory(_ds, 0x94AD);                    //mov al, byte_1CEFD
    _al = _al + stack16(_bp, 6);                  //add al, [bp+arg_2]
    if (_al <= 0x09)                              //jbe short loc_126C4
      goto loc_126C4;
    _al -= 0x0a;                                  //sub al, 0Ah
    memory(_ds, 0x94AC) += 1;                     //inc byte_1CEFC
loc_126C4:                                        //loc_126C4:
    memory(_ds, 0x94AD) = _al;                    //mov byte_1CEFD, al
    _al = memory(_ds, 0x94AC);                    //mov al, byte_1CEFC
    _al = _al + stack16(_bp, 8);                  //add al, [bp+arg_4]
    if (_al <= 0x09)                              //jbe short loc_126D7
      goto loc_126D7;
    _al -= 0x0a;                                  //sub al, 0Ah
    memory(_ds, 0x94AB) += 1;                     //inc byte_1CEFB
loc_126D7:                                        //loc_126D7:
    memory(_ds, 0x94AC) = _al;                    //mov byte_1CEFC, al
    _al = memory(_ds, 0x94AB);                    //mov al, byte_1CEFB
    _al = _al + stack16(_bp, 10);                 //add al, [bp+arg_6]
    if (_al <= 0x09)                              //jbe short loc_126EA
      goto loc_126EA;
    _al -= 0x0a;                                  //sub al, 0Ah
    memory(_ds, 0x94AA) += 1;                     //inc byte_1CEFA
loc_126EA:                                        //loc_126EA:
    memory(_ds, 0x94AB) = _al;                    //mov byte_1CEFB, al
    _al = memory(_ds, 0x94AA);                    //mov al, byte_1CEFA
    if (_al <= 0x09)                              //jbe short loc_12701
      goto loc_12701;
    _al -= 0x0a;                                  //sub al, 0Ah
    memory(_ds, 0x94A9) += 1;                     //inc byte_1CEF9
    _push(_ax);                                   //push ax
    _push(_si);                                   //push si
    sub_122C1();                                  //call sub_122C1
    _si = _pop();                                 //pop si
    _ax = _pop();                                 //pop ax
loc_12701:                                        //loc_12701:
    memory(_ds, 0x94AA) = _al;                    //mov byte_1CEFA, al
    _al = memory(_ds, 0x94A9);                    //mov al, byte_1CEF9
    if (_al <= 0x09)                              //jbe short loc_1270D
      goto loc_1270D;
    _al -= 0x0a;                                  //sub al, 0Ah
loc_1270D:                                        //loc_1270D:
    memory(_ds, 0x94A9) = _al;                    //mov byte_1CEF9, al
    _bp = _pop();                                 //pop bp
    _stackReduce(8);                              //retn 8
    return;
}

void sub_12714()
{
    memory(_ds, 0x944D) = 1;                      //mov byte_1CE9D, 1
    _si = 0x94a9;                                 //mov si, 94A9h
    _cx = 0x0006;                                 //mov cx, 6
    _dx = 0x0000;                                 //mov dx, 0
loc_12722:                                        //loc_12722:
    _push(_cx);                                   //push cx
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    if (_al == 0x00)                              //jz short loc_1272D
      goto loc_1272D;
    memory(_ds, 0x944D) = 0;                      //mov byte_1CE9D, 0
loc_1272D:                                        //loc_1272D:
    _cl = memory(_ds, 0x944D);                    //mov cl, byte_1CE9D
    if (_cl != 0x00)                              //jnz short loc_1275E
      goto loc_1275E;
    _push(_dx);                                   //push dx
    _push(_si);                                   //push si
    _bh = 0x00;                                   //mov bh, 0
    _bl = _al;                                    //mov bl, al
    _bx <<= 1;                                    //shl bx, 1
    _ax = memory16(_ds, _bx + 5471);              //mov ax, [bx+155Fh]
    _push(_ax);                                   //push ax
    _bx = _dx;                                    //mov bx, dx
    _ax = memory16(_ds, _bx + 5491);              //mov ax, [bx+1573h]
    _push(_ax);                                   //push ax
    _ax = 0x10;                                   //mov ax, 10h
    _push(_ax);                                   //push ax
    _ax = 0x0009;                                 //mov ax, 9
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
    _si = _pop();                                 //pop si
    _dx = _pop();                                 //pop dx
    _dx += 0x0002;                                //add dx, 2
loc_1275E:                                        //loc_1275E:
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_12722
      goto loc_12722;
}

void sub_1279F()
{
    sub_12809();                                  //call sub_12809
    _al = memory(_ds, 0x94E0);                    //mov al, byte_1CF30
    if (_al != 0x00)                              //jnz short loc_127AF
      goto loc_127AF;
    memory(_ds, 0x9546) = 0;                      //mov byte_1CF96, 0
    return;                                       //retn
loc_127AF:                                        //loc_127AF:
    memory(_ds, 0x9546) = 1;                      //mov byte_1CF96, 1
    _bl = _al;                                    //mov bl, al
    _bl <<= 1;                                    //shl bl, 1
    _bl += _al;                                   //add bl, al
    _bh = 0x00;                                   //mov bh, 0
    _bx <<= 1;                                    //shl bx, 1
    _push(_bx);                                   //push bx
    _bx += 0x94a9;                                //add bx, 94A9h
    _si = 0x94a9;                                 //mov si, 94A9h
    _cx = 0x0006;                                 //mov cx, 6
loc_127C9:                                        //loc_127C9:
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    memory(_ds, _bx) = _al;                       //mov [bx], al
    _bx += 1;                                     //inc bx
    if (--_cx)                                    //loop loc_127C9
      goto loc_127C9;
    _bx = _pop();                                 //pop bx
    _bx <<= 1;                                    //shl bx, 1
    _bx += 0x9455;                                //add bx, 9455h
    memory16(_ds, 0x9451) = _bx;                  //mov word_1CEA1, bx
    _si = 0x9455;                                 //mov si, 9455h
    _cx = 0x0c;                                   //mov cx, 0Ch
loc_127E0:                                        //loc_127E0:
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    memory(_ds, _bx) = _al;                       //mov [bx], al
    _bx += 1;                                     //inc bx
    if (--_cx)                                    //loop loc_127E0
      goto loc_127E0;
    _si = 0x94da;                                 //mov si, 94DAh
loc_127E9:                                        //loc_127E9:
    _al = memory(_ds, _si);                       //mov al, [si]
    if (_al == 0x00)                              //jz short loc_127F2
      goto loc_127F2;
    _si += 1;                                     //inc si
    goto loc_127E9;                               //jmp short loc_127E9
loc_127F2:                                        //loc_127F2:
    _al = memory(_ds, 0x94E0);                    //mov al, byte_1CF30
    memory(_ds, _si) = _al;                       //mov [si], al
    memory(_ds, 0x94E0) = 0;                      //mov byte_1CF30, 0
    _si -= 0x94da;                                //sub si, 94DAh
    _ax = _si;                                    //mov ax, si
    memory(_ds, 0x9450) = _al;                    //mov byte_1CEA0, al
    sub_128DA();                                  //call sub_128DA
}

void sub_128DA()
{
    _si = 0x94da;                                 //mov si, 94DAh
    _di = 0x01b1;                                 //mov di, 1B1h
    _cx = 0x0006;                                 //mov cx, 6
loc_128E3:                                        //loc_128E3:
    _push(_cx);                                   //push cx
    _di += 0x0002;                                //add di, 2
    _ax = memory16(_ds, _di);                     //mov ax, [di]
    _di += 0x0002;                                //add di, 2
    _push(_si);                                   //push si
    _push(_di);                                   //push di
    sub_12959();                                  //call sub_12959
    _di = _pop();                                 //pop di
    _si = _pop();                                 //pop si
    _di += 0x0002;                                //add di, 2
    _ax = memory16(_ds, _di);                     //mov ax, [di]
    _di += 0x0002;                                //add di, 2
    _push(_si);                                   //push si
    _push(_di);                                   //push di
    sub_12907();                                  //call sub_12907
    _di = _pop();                                 //pop di
    _si = _pop();                                 //pop si
    _si += 1;                                     //inc si
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_128E3
      goto loc_128E3;
}

void sub_129DB()
{
    memory16(_ds, 0x9453) = 0;                    //mov word_1CEA3, 0
loc_129E1:                                        //loc_129E1:
    _ax = memory16(_ds, 0x9453);                  //mov ax, word_1CEA3
    if (_ax >= 0x0c)                              //jnb short loc_12A39
      goto loc_12A39;
    sub_10541();                                  //call sub_10541
    if (_al == 0x00)                              //jz short loc_12A39
      goto loc_12A39;
    if (_al != 0x08)                              //jnz short loc_12A0D
      goto loc_12A0D;
    _bx = memory16(_ds, 0x9451);                  //mov bx, word_1CEA1
    _bx = _bx + memory16(_ds, 0x9453);            //add bx, word_1CEA3
    memory(_ds, _bx) = 0x2e;                      //mov byte ptr [bx], 2Eh
    memory16(_ds, 0x9453) -= 1;                   //dec word_1CEA3
    if ((short)memory16(_ds, 0x9453) >= 0)        //jns short loc_12A0B
      goto loc_12A0B;
    memory16(_ds, 0x9453) = 0;                    //mov word_1CEA3, 0
loc_12A0B:                                        //loc_12A0B:
    goto loc_12A1B;                               //jmp short loc_12A1B
loc_12A0D:                                        //loc_12A0D:
    _bx = memory16(_ds, 0x9451);                  //mov bx, word_1CEA1
    _bx = _bx + memory16(_ds, 0x9453);            //add bx, word_1CEA3
    memory(_ds, _bx) = _al;                       //mov [bx], al
    memory16(_ds, 0x9453) += 1;                   //inc word_1CEA3
loc_12A1B:                                        //loc_12A1B:
    _bx = memory16(_ds, 0x9453);                  //mov bx, word_1CEA3
    if (_bx >= 0x0c)                              //jnb short loc_12A2B
      goto loc_12A2B;
    _bx = _bx + memory16(_ds, 0x9451);            //add bx, word_1CEA1
    memory(_ds, _bx) = 0x5f;                      //mov byte ptr [bx], 5Fh
loc_12A2B:                                        //loc_12A2B:
    sub_12A64();                                  //call sub_12A64
    sub_13498();                                  //call sub_13498
    sub_10B8E();                                  //call sub_10B8E
    sub_13383();                                  //call sub_13383
    goto loc_129E1;                               //jmp short loc_129E1
loc_12A39:                                        //loc_12A39:
    _bx = memory16(_ds, 0x9453);                  //mov bx, word_1CEA3
    if (_bx >= 0x0c)                              //jnb short loc_12A52
      goto loc_12A52;
    _bx = _bx + memory16(_ds, 0x9451);            //add bx, word_1CEA1
    _al = memory(_ds, _bx);                       //mov al, [bx]
    if (_al != 0x5f)                              //jnz short loc_12A52
      goto loc_12A52;
    memory(_ds, _bx) = 0x2e;                      //mov byte ptr [bx], 2Eh
    sub_12A64();                                  //call sub_12A64
loc_12A52:                                        //loc_12A52:
    _di = 0x9455;                                 //mov di, 9455h
    _dx = 0x1506;                                 //mov dx, 1506h
    _cx = 0x8c;                                   //mov cx, 8Ch
    sub_10674();                                  //call sub_10674
    memory(_ds, 0x9546) = 0;                      //mov byte_1CF96, 0
}

void sub_12A7F()
{
    memory(_ds, 0x952E) = 0;                      //mov byte_1CF7E, 0
    memory(_ds, 0x952F) = 0;                      //mov byte_1CF7F, 0
    memory(_ds, 0x9530) = 0;                      //mov byte_1CF80, 0
    memory(_ds, 0x9531) = 0;                      //mov byte_1CF81, 0
    memory(_ds, 0x9532) = 0;                      //mov byte_1CF82, 0
    memory(_ds, 0x9533) = 0;                      //mov byte_1CF83, 0
    _ax = 0x1178;                                 //mov ax, 1178h
    _push(_ax);                                   //push ax
    _ax = 0x1b82;                                 //mov ax, 1B82h
    _push(_ax);                                   //push ax
    _ax = 0x10;                                   //mov ax, 10h
    _push(_ax);                                   //push ax
    _ax = 0x0008;                                 //mov ax, 8
    _push(_ax);                                   //push ax
    _ax = 0x0004;                                 //mov ax, 4
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
    _ax = 0x1678;                                 //mov ax, 1678h
    _push(_ax);                                   //push ax
    _ax = 0x1cc2;                                 //mov ax, 1CC2h
    _push(_ax);                                   //push ax
    _ax = 0x10;                                   //mov ax, 10h
    _push(_ax);                                   //push ax
    _ax = 0x0008;                                 //mov ax, 8
    _push(_ax);                                   //push ax
    _ax = 0x0004;                                 //mov ax, 4
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
    _ax = 0x1b78;                                 //mov ax, 1B78h
    _push(_ax);                                   //push ax
    _ax = 0x1e02;                                 //mov ax, 1E02h
    _push(_ax);                                   //push ax
    _ax = 0x10;                                   //mov ax, 10h
    _push(_ax);                                   //push ax
    _ax = 0x0008;                                 //mov ax, 8
    _push(_ax);                                   //push ax
    _ax = 0x0004;                                 //mov ax, 4
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
    _ax = 0x2078;                                 //mov ax, 2078h
    _push(_ax);                                   //push ax
    _ax = 0x1b85;                                 //mov ax, 1B85h
    _push(_ax);                                   //push ax
    _ax = 0x10;                                   //mov ax, 10h
    _push(_ax);                                   //push ax
    _ax = 0x0008;                                 //mov ax, 8
    _push(_ax);                                   //push ax
    _ax = 0x0004;                                 //mov ax, 4
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
    _ax = 0x2578;                                 //mov ax, 2578h
    _push(_ax);                                   //push ax
    _ax = 0x1cc5;                                 //mov ax, 1CC5h
    _push(_ax);                                   //push ax
    _ax = 0x10;                                   //mov ax, 10h
    _push(_ax);                                   //push ax
    _ax = 0x0008;                                 //mov ax, 8
    _push(_ax);                                   //push ax
    _ax = 0x0004;                                 //mov ax, 4
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
    _ax = 0x2a78;                                 //mov ax, 2A78h
    _push(_ax);                                   //push ax
    _ax = 0x1e05;                                 //mov ax, 1E05h
    _push(_ax);                                   //push ax
    _ax = 0x10;                                   //mov ax, 10h
    _push(_ax);                                   //push ax
    _ax = 0x0008;                                 //mov ax, 8
    _push(_ax);                                   //push ax
    _ax = 0x0004;                                 //mov ax, 4
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
}

void sub_12C45()
{
    _ax = 0x0aac;                                 //mov ax, 0AACh
    _push(_ax);                                   //push ax
    _ax = 0x10;                                   //mov ax, 10h
    _push(_ax);                                   //push ax
    _ax = 0x28;                                   //mov ax, 28h
    _push(_ax);                                   //push ax
    _ax = 0x0005;                                 //mov ax, 5
    _push(_ax);                                   //push ax
    sub_12D9A();                                  //call sub_12D9A
    _ax = 0x0b4d;                                 //mov ax, 0B4Dh
    _push(_ax);                                   //push ax
    _ax = 0x0e;                                   //mov ax, 0Eh
    _push(_ax);                                   //push ax
    _ax = 0x20;                                   //mov ax, 20h
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    sub_12D9A();                                  //call sub_12D9A
    _ax = 0x7592;                                 //mov ax, 7592h
    _push(_ax);                                   //push ax
    _ax = 0x0c8f;                                 //mov ax, 0C8Fh
    _push(_ax);                                   //push ax
    _ax = 0x28;                                   //mov ax, 28h
    _push(_ax);                                   //push ax
    _ax = 0x0c;                                   //mov ax, 0Ch
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
    _ax = 0x1ab8;                                 //mov ax, 1AB8h
    _push(_ax);                                   //push ax
    _ax = 0x0ce4;                                 //mov ax, 0CE4h
    _push(_ax);                                   //push ax
    _ax = 0x20;                                   //mov ax, 20h
    _push(_ax);                                   //push ax
    _ax = 0x0d;                                   //mov ax, 0Dh
    _push(_ax);                                   //push ax
    _ax = 0x0004;                                 //mov ax, 4
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
}

void sub_12CEA()
{
    _push(_bp);                                   //push bp
    _bp = _sp;                                    //mov bp, sp
    _ax = 0xa000;                                 //mov ax, 0A000h
    _es = _ax;                                    //mov es, ax
    _di = stack16(_bp, 10);                       //mov di, [bp+arg_6]
    _bx = stack16(_bp, 4);                        //mov bx, [bp+arg_0]
    _bx = memory16(_ds, _bx + -27416);            //mov bx, [bx-6B18h]
    _si = stack16(_bp, 12);                       //mov si, [bp+arg_8]
    _push(_ds);                                   //push ds
    _push(_bx);                                   //push bx
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0a05;                                 //mov ax, 0A05h
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0007;                                 //mov ax, 7
    _out(_dx, _ax);                               //out dx, ax
    _cx = stack16(_bp, 8);                        //mov cx, [bp+arg_4]
    _cx >>= 1;                                    //shr cx, 1
    _ah = 0x80;                                   //mov ah, 80h
    _al = 0x08;                                   //mov al, 8
    _ds = _pop();                                 //pop ds
    _bx = stack16(_bp, 6);                        //mov bx, [bp+arg_2]
loc_12D19:                                        //loc_12D19:
    _push(_ax);                                   //push ax
    _push(_bx);                                   //push bx
    _push(_cx);                                   //push cx
    _push(_di);                                   //push di
    _push(_si);                                   //push si
loc_12D1E:                                        //loc_12D1E:
    _bh = 0x22;                                   //mov bh, 22h
loc_12D20:                                        //loc_12D20:
    _bl = memory(_ds, _si);                       //mov bl, [si]
    _si += 1;                                     //inc si
    if (_bh != _bl)                               //jnz short loc_12D3D
      goto loc_12D3D;
    _ah >>= 1;                                    //shr ah, 1
    if (_ah != 0)                                 //jnz short loc_12D32
      goto loc_12D32;
    _ah = 0x40;                                   //mov ah, 40h
    _di += 1;                                     //inc di
    if (--_cx)                                    //loop loc_12D20
      goto loc_12D20;
    goto loc_12D76;                               //jmp short loc_12D76
loc_12D32:                                        //loc_12D32:
    _ah >>= 1;                                    //shr ah, 1
    if (_ah != 0)                                 //jnz short loc_12D39
      goto loc_12D39;
    _ah = 0x80;                                   //mov ah, 80h
    _di += 1;                                     //inc di
loc_12D39:                                        //loc_12D39:
    if (--_cx)                                    //loop loc_12D20
      goto loc_12D20;
    goto loc_12D76;                               //jmp short loc_12D76
loc_12D3D:                                        //loc_12D3D:
    _bh = _bl;                                    //mov bh, bl
    _bl >>= 1;                                    //shr bl, 1
    _bl >>= 1;                                    //shr bl, 1
    _bl >>= 1;                                    //shr bl, 1
    _bl >>= 1;                                    //shr bl, 1
    if (_bl == 0x02)                              //jz short loc_12D55
      goto loc_12D55;
    _out(_dx, _ax);                               //out dx, ax
    memoryVideoSet(_es, _di, memoryVideoGet(_es, _di) & _bl);                      //and es:[di], bl
    memoryVideoSet(_es, _di + 8192, memoryVideoGet(_es, _di + 8192) & _bl);               //and es:[di+2000h], bl
loc_12D55:                                        //loc_12D55:
    _ah >>= 1;                                    //shr ah, 1
    if (_ah != 0)                                 //jnz short loc_12D5C
      goto loc_12D5C;
    _ah = 0x80;                                   //mov ah, 80h
    _di += 1;                                     //inc di
loc_12D5C:                                        //loc_12D5C:
    _bh &= 0x0f;                                  //and bh, 0Fh
    if (_bh == 0x02)                              //jz short loc_12D6D
      goto loc_12D6D;
    _out(_dx, _ax);                               //out dx, ax
    memoryVideoSet(_es, _di, memoryVideoGet(_es, _di) & _bh);                      //and es:[di], bh
    memoryVideoSet(_es, _di + 8192, memoryVideoGet(_es, _di + 8192) & _bh);               //and es:[di+2000h], bh
loc_12D6D:                                        //loc_12D6D:
    _ah >>= 1;                                    //shr ah, 1
    if (_ah != 0)                                 //jnz short loc_12D74
      goto loc_12D74;
    _ah = 0x80;                                   //mov ah, 80h
    _di += 1;                                     //inc di
loc_12D74:                                        //loc_12D74:
    if (--_cx)                                    //loop loc_12D1E
      goto loc_12D1E;
loc_12D76:                                        //loc_12D76:
    _si = _pop();                                 //pop si
    _si += 0xa0;                                  //add si, 0A0h
    _di = _pop();                                 //pop di
    _di += 0x28;                                  //add di, 28h
    _di &= 0x7fff;                                //and di, 7FFFh
    _cx = _pop();                                 //pop cx
    _bx = _pop();                                 //pop bx
    _ax = _pop();                                 //pop ax
    _bx -= 1;                                     //dec bx
    if (_bx != 0)                                 //jnz short loc_12D19
      goto loc_12D19;
    _ds = _pop();                                 //pop ds
    _ax = 0xff08;                                 //mov ax, 0FF08h
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0005;                                 //mov ax, 5
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0f07;                                 //mov ax, 0F07h
    _out(_dx, _ax);                               //out dx, ax
    _bp = _pop();                                 //pop bp
    _stackReduce(10);                             //retn 0Ah
    return;
}

void sub_12E02() // tunnel grid
{
    _push(_si);                                   //push si
    sub_11B80();                                  //call sub_11B80
    sub_1309D();                                  //call sub_1309D
    _si = _pop();                                 //pop si
    _ax = memory16(_ds, 0x952A);                  //mov ax, word_1CF7A
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _bx = memory16(_ds, 0x954C);                  //mov bx, word_1CF9C
    if (!(_bl & 0x01))                            //jz short loc_12E23
      goto loc_12E23;
    _ax = -_ax;                                   //neg ax
    _ax -= 0x0003;                                //sub ax, 3
    goto loc_12E30;                               //jmp short loc_12E30
loc_12E23:                                        //loc_12E23:
    if (!(_bl & 0x02))                            //jz short loc_12E2D
      goto loc_12E2D;
    _ax += 0x0003;                                //add ax, 3
    goto loc_12E30;                               //jmp short loc_12E30
loc_12E2D:                                        //loc_12E2D:
    _ax = 0x0000;                                 //mov ax, 0
loc_12E30:                                        //loc_12E30:
    memory16(_ds, 0x9522) = _ax;                  //mov word_1CF72, ax
    _al = memory(_ds, _si + 22);                  //mov al, [si+16h]
    _ax &= 0x7f;                                  //and ax, 7Fh
    if (_al <= 0x3f)                              //jbe short loc_12E48
      goto loc_12E48;
    _al = -_al;                                   //neg al
    _al += 0x7f;                                  //add al, 7Fh
    sub_13084();                                  //call sub_13084
    _ax = -_ax;                                   //neg ax
    goto loc_12E4B;                               //jmp short loc_12E4B
loc_12E48:                                        //loc_12E48:
    sub_13084();                                  //call sub_13084
loc_12E4B:                                        //loc_12E4B:
    memory16(_ds, 0x9520) = _ax;                  //mov word_1CF70, ax
    _ax = memory16(_ds, 0x951E);                  //mov ax, word_1CF6E
    _ax = _ax + memory16(_ds, 0x9522);            //add ax, word_1CF72
    _flags.sign = (short)(_ax + memory16(_ds, 0x9520)) < 0;
    _ax = _ax + memory16(_ds, 0x9520);
    if (_ax == 0)                                 //jz short loc_12E6A
      goto loc_12E6A;
    if (!_flags.sign)                              //jns short loc_12E63
      goto loc_12E63;
    _ax += 1;                                     //inc ax
    if ((short)_ax>=0)                                  //jns short loc_12E61
      goto loc_12E61;
    _ax += 1;                                     //inc ax
loc_12E61:                                        //loc_12E61:
    goto loc_12E6A;                               //jmp short loc_12E6A
loc_12E63:                                        //loc_12E63:
    _ax -= 1;                                     //dec ax
    if ((short)_ax <= (short)0x0000)              //jle short loc_12E6A
      goto loc_12E6A;
    _ax -= 1;                                     //dec ax
loc_12E6A:                                        //loc_12E6A:
    if ((short)_ax <= (short)0x40)                //jle short loc_12E74
      goto loc_12E74;
    _ax = 0x40;                                   //mov ax, 40h
    goto loc_12E7C;                               //jmp short loc_12E7C
loc_12E74:                                        //loc_12E74:
    if ((short)_ax >= (short)0xffc0)              //jge short loc_12E7C
      goto loc_12E7C;
    _ax = 0xffc0;                                 //mov ax, 0FFC0h
loc_12E7C:                                        //loc_12E7C:
    memory16(_ds, 0x951E) = _ax;                  //mov word_1CF6E, ax
    _sar(_ax, 1);                                 //sar ax, 1
    _sar(_ax, 1);                                 //sar ax, 1
    memory(_ds, _si + 22) += _al;                 //add [si+16h], al
    _al = memory(_ds, _si + 22);                  //mov al, [si+16h]
    _ax &= 0x7f;                                  //and ax, 7Fh
    _bx = _ax;                                    //mov bx, ax
    _al = memory(_ds, _bx + 5749);                //mov al, [bx+1675h]
    _cbw();                                       //cbw
    _ax <<= 1;                                    //shl ax, 1
    _ax += 0x80;                                  //add ax, 80h
    memory16(_ds, _si + 5) = _ax;                 //mov [si+5], ax
    _al = memory(_ds, _bx + 5877);                //mov al, [bx+16F5h]
    _cbw();                                       //cbw
    _ax <<= 1;                                    //shl ax, 1
    _ax += 0x80;                                  //add ax, 80h
    _push(_bx);                                   //push bx
    if (_ax == 0x0000)                            //jz short loc_12EBE
      goto loc_12EBE;
    _bx = _ax;                                    //mov bx, ax
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax += _bx;                                   //add ax, bx
    _ax <<= 1;                                    //shl ax, 1
    _ax += 0x0005;                                //add ax, 5
    _bl = 0x0c;                                   //mov bl, 0Ch
    _div(_bl);                                    //div bl
    _ah = 0x00;                                   //mov ah, 0
loc_12EBE:                                        //loc_12EBE:
    _bx = _pop();                                 //pop bx
    memory16(_ds, _si + 7) = _ax;                 //mov [si+7], ax
    _al = memory(_ds, _bx + 6005);                //mov al, [bx+1775h]
    memory(_ds, _si + 4) = _al;                   //mov [si+4], al
    _bx = 0x1594;                                 //mov bx, 1594h
    sub_12121();                                  //call sub_12121
    _al = memory(_ds, 0x94E6);                    //mov al, byte_1CF36
    memory(_ds, 0x94E7) = _al;                    //mov byte_1CF37, al
    _al = memory(_ds, 0x94E5);                    //mov al, byte_1CF35
    memory(_ds, 0x94E6) = _al;                    //mov byte_1CF36, al
    _al = memory(_ds, 0x1BA0);                    //mov al, byte_155F0
    memory(_ds, 0x94E5) = _al;                    //mov byte_1CF35, al
    _ax = memory16(_ds, 0x954C);                  //mov ax, word_1CF9C
    _bl = memory(_ds, 0x951A);                    //mov bl, byte_1CF6A
    if (!(_al & 0x40))                            //jz short loc_12F02
      goto loc_12F02;
    if (_bl != 0x02)                              //jnz short loc_12F00
      goto loc_12F00;
    memory(_ds, 0x951A) = 3;                      //mov byte_1CF6A, 3
    _al = 0x02;                                   //mov al, 2
    sub_13840();                                  //call sub_13840
    memory(_ds, 0x951C) = 2;                      //mov byte_1CF6C, 2
loc_12F00:                                        //loc_12F00:
    goto loc_12F18;                               //jmp short loc_12F18
loc_12F02:                                        //loc_12F02:
    if (_bl != 0x01)                              //jnz short loc_12F0E
      goto loc_12F0E;
    memory(_ds, 0x951A) = 2;                      //mov byte_1CF6A, 2
    goto loc_12F18;                               //jmp short loc_12F18
loc_12F0E:                                        //loc_12F0E:
    if (_bl != 0x03)                              //jnz short loc_12F18
      goto loc_12F18;
    memory(_ds, 0x951A) = 0;                      //mov byte_1CF6A, 0
loc_12F18:                                        //loc_12F18:
    _ax = memory16(_ds, 0x954C);                  //mov ax, word_1CF9C
    _bl = memory(_ds, 0x951B);                    //mov bl, byte_1CF6B
    if (!(_al & 0x20))                            //jz short loc_12F39
      goto loc_12F39;
    if (_bl != 0x02)                              //jnz short loc_12F37
      goto loc_12F37;
    memory(_ds, 0x951B) = 3;                      //mov byte_1CF6B, 3
    _al = 0x02;                                   //mov al, 2
    sub_13840();                                  //call sub_13840
    memory(_ds, 0x951C) = 2;                      //mov byte_1CF6C, 2
loc_12F37:                                        //loc_12F37:
    goto locret_12F4F;                            //jmp short locret_12F4F
loc_12F39:                                        //loc_12F39:
    if (_bl != 0x01)                              //jnz short loc_12F45
      goto loc_12F45;
    memory(_ds, 0x951B) = 2;                      //mov byte_1CF6B, 2
    goto locret_12F4F;                            //jmp short locret_12F4F
loc_12F45:                                        //loc_12F45:
    if (_bl != 0x03)                              //jnz short locret_12F4F
      goto locret_12F4F;
    memory(_ds, 0x951B) = 0;                      //mov byte_1CF6B, 0
locret_12F4F:                                     //locret_12F4F:
    return;
}

void sub_12F50()
{
    _al = memory(_ds, _si);                       //mov al, [si]
    if (_al & 0x20)                               //jnz short loc_12F5E
      goto loc_12F5E;
    _ah = memory(_ds, 0x951A);                    //mov ah, byte_1CF6A
    _al = 0xf8;                                   //mov al, 0F8h
    goto loc_12F64;                               //jmp short loc_12F64
loc_12F5E:                                        //loc_12F5E:
    _ah = memory(_ds, 0x951B);                    //mov ah, byte_1CF6B
    _al = 0x08;                                   //mov al, 8
loc_12F64:                                        //loc_12F64:
    if (_ah == 0x03)                              //jz short loc_12F6E
      goto loc_12F6E;
    if (_ah != 0x00)                              //jnz short loc_12F90
      goto loc_12F90;
loc_12F6E:                                        //loc_12F6E:
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
    _si = 0x1ba1;                                 //mov si, 1BA1h
loc_12F74:                                        //loc_12F74:
    _al = memory(_ds, _si);                       //mov al, [si]
    if (_al & 0x80)                               //jnz short locret_12F8F
      goto locret_12F8F;
    if (!(_al & 0x01))                            //jz short loc_12F8A
      goto loc_12F8A;
    _al = memory(_ds, _si + 18);                  //mov al, [si+12h]
    if (_al != 0x0f)                              //jnz short loc_12F8A
      goto loc_12F8A;
    _push(_si);                                   //push si
    sub_13059();                                  //call sub_13059
    _si = _pop();                                 //pop si
loc_12F8A:                                        //loc_12F8A:
    _si += 0x17;                                  //add si, 17h
    goto loc_12F74;                               //jmp short loc_12F74
locret_12F8F:                                     //locret_12F8F:
    return;                                       //retn
loc_12F90:                                        //loc_12F90:
    _al = _al + memory(_ds, 0x94E7);              //add al, byte_1CF37
    _ax &= 0x7f;                                  //and ax, 7Fh
    _bx = _ax;                                    //mov bx, ax
    _al = memory(_ds, _bx + 5749);                //mov al, [bx+1675h]
    _cbw();                                       //cbw
    _cx = _ax;                                    //mov cx, ax
    _sar(_cx, 1);                                 //sar cx, 1
    _ax += _cx;                                   //add ax, cx
    _ax += 0x80;                                  //add ax, 80h
    memory16(_ds, _si + 5) = _ax;                 //mov [si+5], ax
    _al = memory(_ds, _bx + 5877);                //mov al, [bx+16F5h]
    _cbw();                                       //cbw
    _cx = _ax;                                    //mov cx, ax
    _sar(_cx, 1);                                 //sar cx, 1
    _ax += _cx;                                   //add ax, cx
    _ax += 0x80;                                  //add ax, 80h
    if (_ax == 0x0000)                            //jz short loc_12FD0
      goto loc_12FD0;
    _bx = _ax;                                    //mov bx, ax
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax += _bx;                                   //add ax, bx
    _ax <<= 1;                                    //shl ax, 1
    _ax += 0x0005;                                //add ax, 5
    _bl = 0x0c;                                   //mov bl, 0Ch
    _div(_bl);                                    //div bl
    _ah = 0x00;                                   //mov ah, 0
loc_12FD0:                                        //loc_12FD0:
    _bl = memory(_ds, 0x1BA0);                    //mov bl, byte_155F0
    _bx &= 0x7f;                                  //and bx, 7Fh
    memory16(_ds, _si + 7) = _ax;                 //mov [si+7], ax
    _al = memory(_ds, _bx + 6290);                //mov al, [bx+1892h]
    memory(_ds, _si + 4) = _al;                   //mov [si+4], al
    _bx = 0x1811;                                 //mov bx, 1811h
    sub_12121();                                  //call sub_12121
}

void sub_12FE8()
{
    _bx = memory16(_ds, 0x9525);                  //mov bx, word_1CF75
    _bx >>= 1;                                    //shr bx, 1
    _bx >>= 1;                                    //shr bx, 1
    _bx >>= 1;                                    //shr bx, 1
    _bx &= 0x1f;                                  //and bx, 1Fh
    _al = memory(_ds, _bx + 6666);                //mov al, [bx+1A0Ah]
    memory(_ds, 0x9549) = _al;                    //mov byte_1CF99, al
    _al = memory(_ds, _bx + 6634);                //mov al, [bx+19EAh]
    memory(_ds, _si + 4) = _al;                   //mov [si+4], al
    _bx = 0x1929;                                 //mov bx, 1929h
    sub_12121();                                  //call sub_12121
}

void sub_1300A() // tunnel
{
    _ax = memory16(_ds, 0x9547);                  //mov ax, word_1CF97
    _ax = _ax - memory16(_ds, _si + 19);          //sub ax, [si+13h]
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    if (_ax <= 0x2d)                              //jbe short loc_1301F
      goto loc_1301F;
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
    return;                                       //retn
loc_1301F:                                        //loc_1301F:
    _push(_ax);                                   //push ax
    sub_13130();                                  //call sub_13130
    _ax = _pop();                                 //pop ax
    _ax >>= 1;                                    //shr ax, 1
    memory(_ds, _si + 4) = _al;                   //mov [si+4], al
    _bx = _ax;                                    //mov bx, ax
    _al = memory(_ds, _bx + 6810);                //mov al, [bx+1A9Ah]
    memory(_ds, _si + 2) = _al;                   //mov [si+2], al
    _bx = 0x1ac9;                                 //mov bx, 1AC9h
    sub_12121();                                  //call sub_12121
    _al = memory(_ds, _si + 2);                   //mov al, [si+2]
    if (_al == 0x02)                              //jz short loc_13040
      goto loc_13040;
    return;                                       //retn
loc_13040:                                        //loc_13040:
    _bl = memory(_ds, 0x1B8E);                    //mov bl, byte_155DE
    _bh = 0x00;                                   //mov bh, 0
    _al = memory(_ds, _bx + 6133);                //mov al, [bx+17F5h]
    if (_al == memory(_ds, _si + 1))              //jz short loc_13050
      goto loc_13050;
    return;                                       //retn
loc_13050:                                        //loc_13050:
    _al = 0x09;                                   //mov al, 9
    sub_13840();                                  //call sub_13840
    sub_13059();                                  //call sub_13059
}

void sub_131E7()
{
    _al = memory(_ds, 0x951D);                    //mov al, byte_1CF6D
    if (_al != 0x40)                              //jnz short loc_131F3
      goto loc_131F3;
    _ax = 0x0002;                                 //mov ax, 2
    goto locret_13208;                            //jmp short locret_13208
loc_131F3:                                        //loc_131F3:
    if (_al != 0x80)                              //jnz short loc_131FC
      goto loc_131FC;
    _ax = 0x0004;                                 //mov ax, 4
    goto locret_13208;                            //jmp short locret_13208
loc_131FC:                                        //loc_131FC:
    if (_al != 0xc0)                              //jnz short loc_13205
      goto loc_13205;
    _ax = 0x0001;                                 //mov ax, 1
    goto locret_13208;                            //jmp short locret_13208
loc_13205:                                        //loc_13205:
    _ax = 0x0003;                                 //mov ax, 3
locret_13208:                                     //locret_13208:
    return;
}

void sub_13209()
{
    _al = memory(_ds, 0x951C);                    //mov al, byte_1CF6C
    if (_al != 0x00)                              //jnz short loc_13215
      goto loc_13215;
    _ax = 0x0000;                                 //mov ax, 0
    goto locret_1322B;                            //jmp short locret_1322B
loc_13215:                                        //loc_13215:
    if (_al != 0x01)                              //jnz short loc_13223
      goto loc_13223;
    _ax = 0x0007;                                 //mov ax, 7
    memory(_ds, 0x951C) = 0;                      //mov byte_1CF6C, 0
    goto locret_1322B;                            //jmp short locret_1322B
loc_13223:                                        //loc_13223:
    _ax = 0x0f;                                   //mov ax, 0Fh
    memory(_ds, 0x951C) = 1;                      //mov byte_1CF6C, 1
locret_1322B:                                     //locret_1322B:
    return;
}

void sub_13439()
{
    _ax = memory16(_ds, 0x94F8);                  //mov ax, word_1CF48
    _es = _ax;                                    //mov es, ax
    _di = 0x011c;                                 //mov di, 11Ch
    _ax = 0xffff;                                 //mov ax, 0FFFFh
    _cx = 0x10;                                   //mov cx, 10h
    _rep_stosw<MemAuto, DirAuto>();               //rep stosw
    _di = 0x1a44;                                 //mov di, 1A44h
    _cx = 0x10;                                   //mov cx, 10h
    _rep_stosw<MemAuto, DirAuto>();               //rep stosw
    _di = 0x011b;                                 //mov di, 11Bh
    _al = 0x01;                                   //mov al, 1
    _cx = 0xa2;                                   //mov cx, 0A2h
loc_13459:                                        //loc_13459:
    memoryVideoSet(_es, _di, _al);                       //mov es:[di], al
    _di += 0x28;                                  //add di, 28h
    if (--_cx)                                    //loop loc_13459
      goto loc_13459;
    _di = 0x013c;                                 //mov di, 13Ch
    _al = 0x80;                                   //mov al, 80h
    _cx = 0xa2;                                   //mov cx, 0A2h
loc_13469:                                        //loc_13469:
    memoryVideoSet(_es, _di, _al);                       //mov es:[di], al
    _di += 0x28;                                  //add di, 28h
    if (--_cx)                                    //loop loc_13469
      goto loc_13469;
}

void sub_13472()
{
    _si = 0x0000;                                 //mov si, 0
    _bx = memory16(_ds, 0x94F2);                  //mov bx, word_1CF42
    sub_133E5();                                  //call sub_133E5
    sub_13383();                                  //call sub_13383
    _si = 0x0000;                                 //mov si, 0
    _bx = memory16(_ds, 0x94F2);                  //mov bx, word_1CF42
    sub_133E5();                                  //call sub_133E5
    _ax = memory16(_ds, 0x94F8);                  //mov ax, word_1CF48
    _push(_ax);                                   //push ax
    _ax = 0xa000;                                 //mov ax, 0A000h
    _ax += 0x0400;                                //add ax, 400h
    _push(_ax);                                   //push ax
    sub_13291();                                  //call sub_13291
}

void sub_13498()
{
    _ax = 0xa000;                                 //mov ax, 0A000h
    _ax += 0x0400;                                //add ax, 400h
    _push(_ax);                                   //push ax
    _ax = memory16(_ds, 0x94F8);                  //mov ax, word_1CF48
    _push(_ax);                                   //push ax
    sub_13291();                                  //call sub_13291
}

void sub_135BC()
{
    _push(_bp);                                   //push bp
    _bp = _sp;                                    //mov bp, sp
loc_135BF:                                        //loc_135BF:
    _ax = 0x7f;                                   //mov ax, 7Fh
    _ax = _ax - stack16(_bp, 4);                  //sub ax, [bp+arg_0]
    _push(_ax);                                   //push ax
    _ax = 0x7f;                                   //mov ax, 7Fh
    _ax = _ax - stack16(_bp, 6);                  //sub ax, [bp+arg_2]
    _push(_ax);                                   //push ax
    _ax = 0x80;                                   //mov ax, 80h
    _ax = _ax + stack16(_bp, 4);                  //add ax, [bp+arg_0]
    _push(_ax);                                   //push ax
    _ax = 0x7f;                                   //mov ax, 7Fh
    _ax = _ax - stack16(_bp, 6);                  //sub ax, [bp+arg_2]
    _push(_ax);                                   //push ax
    sub_136D4();                                  //call sub_136D4
    _ax = 0x80;                                   //mov ax, 80h
    _ax = _ax + stack16(_bp, 4);                  //add ax, [bp+arg_0]
    _push(_ax);                                   //push ax
    _ax = 0x7f;                                   //mov ax, 7Fh
    _ax = _ax - stack16(_bp, 6);                  //sub ax, [bp+arg_2]
    _push(_ax);                                   //push ax
    _ax = 0x80;                                   //mov ax, 80h
    _ax = _ax + stack16(_bp, 6);                  //add ax, [bp+arg_2]
    _push(_ax);                                   //push ax
    _ax = 0x7f;                                   //mov ax, 7Fh
    _ax = _ax - stack16(_bp, 4);                  //sub ax, [bp+arg_0]
    _push(_ax);                                   //push ax
    sub_136D4();                                  //call sub_136D4
    _ax = 0x80;                                   //mov ax, 80h
    _ax = _ax + stack16(_bp, 6);                  //add ax, [bp+arg_2]
    _push(_ax);                                   //push ax
    _ax = 0x7f;                                   //mov ax, 7Fh
    _ax = _ax - stack16(_bp, 4);                  //sub ax, [bp+arg_0]
    _push(_ax);                                   //push ax
    _ax = 0x80;                                   //mov ax, 80h
    _ax = _ax + stack16(_bp, 6);                  //add ax, [bp+arg_2]
    _push(_ax);                                   //push ax
    _ax = 0x80;                                   //mov ax, 80h
    _ax = _ax + stack16(_bp, 4);                  //add ax, [bp+arg_0]
    _push(_ax);                                   //push ax
    sub_136D4();                                  //call sub_136D4
    _ax = 0x80;                                   //mov ax, 80h
    _ax = _ax + stack16(_bp, 4);                  //add ax, [bp+arg_0]
    _push(_ax);                                   //push ax
    _ax = 0x80;                                   //mov ax, 80h
    _ax = _ax + stack16(_bp, 6);                  //add ax, [bp+arg_2]
    _push(_ax);                                   //push ax
    _ax = 0x80;                                   //mov ax, 80h
    _ax = _ax + stack16(_bp, 6);                  //add ax, [bp+arg_2]
    _push(_ax);                                   //push ax
    _ax = 0x80;                                   //mov ax, 80h
    _ax = _ax + stack16(_bp, 4);                  //add ax, [bp+arg_0]
    _push(_ax);                                   //push ax
    sub_136D4();                                  //call sub_136D4
    _ax = 0x7f;                                   //mov ax, 7Fh
    _ax = _ax - stack16(_bp, 4);                  //sub ax, [bp+arg_0]
    _push(_ax);                                   //push ax
    _ax = 0x80;                                   //mov ax, 80h
    _ax = _ax + stack16(_bp, 6);                  //add ax, [bp+arg_2]
    _push(_ax);                                   //push ax
    _ax = 0x80;                                   //mov ax, 80h
    _ax = _ax + stack16(_bp, 4);                  //add ax, [bp+arg_0]
    _push(_ax);                                   //push ax
    _ax = 0x80;                                   //mov ax, 80h
    _ax = _ax + stack16(_bp, 6);                  //add ax, [bp+arg_2]
    _push(_ax);                                   //push ax
    sub_136D4();                                  //call sub_136D4
    _ax = 0x7f;                                   //mov ax, 7Fh
    _ax = _ax - stack16(_bp, 6);                  //sub ax, [bp+arg_2]
    _push(_ax);                                   //push ax
    _ax = 0x80;                                   //mov ax, 80h
    _ax = _ax + stack16(_bp, 4);                  //add ax, [bp+arg_0]
    _push(_ax);                                   //push ax
    _ax = 0x7f;                                   //mov ax, 7Fh
    _ax = _ax - stack16(_bp, 4);                  //sub ax, [bp+arg_0]
    _push(_ax);                                   //push ax
    _ax = 0x80;                                   //mov ax, 80h
    _ax = _ax + stack16(_bp, 6);                  //add ax, [bp+arg_2]
    _push(_ax);                                   //push ax
    sub_136D4();                                  //call sub_136D4
    _ax = 0x7f;                                   //mov ax, 7Fh
    _ax = _ax - stack16(_bp, 6);                  //sub ax, [bp+arg_2]
    _push(_ax);                                   //push ax
    _ax = 0x7f;                                   //mov ax, 7Fh
    _ax = _ax - stack16(_bp, 4);                  //sub ax, [bp+arg_0]
    _push(_ax);                                   //push ax
    _ax = 0x7f;                                   //mov ax, 7Fh
    _ax = _ax - stack16(_bp, 6);                  //sub ax, [bp+arg_2]
    _push(_ax);                                   //push ax
    _ax = 0x80;                                   //mov ax, 80h
    _ax = _ax + stack16(_bp, 4);                  //add ax, [bp+arg_0]
    _push(_ax);                                   //push ax
    sub_136D4();                                  //call sub_136D4
    _ax = 0x7f;                                   //mov ax, 7Fh
    _ax = _ax - stack16(_bp, 6);                  //sub ax, [bp+arg_2]
    _push(_ax);                                   //push ax
    _ax = 0x7f;                                   //mov ax, 7Fh
    _ax = _ax - stack16(_bp, 4);                  //sub ax, [bp+arg_0]
    _push(_ax);                                   //push ax
    _ax = 0x7f;                                   //mov ax, 7Fh
    _ax = _ax - stack16(_bp, 4);                  //sub ax, [bp+arg_0]
    _push(_ax);                                   //push ax
    _ax = 0x7f;                                   //mov ax, 7Fh
    _ax = _ax - stack16(_bp, 6);                  //sub ax, [bp+arg_2]
    _push(_ax);                                   //push ax
    sub_136D4();                                  //call sub_136D4
    _ax = stack16(_bp, 6);                        //mov ax, [bp+arg_2]
    _ax >>= 1;                                    //shr ax, 1
    if (_al <= memory(_ds, 0x9549))               //jbe short loc_136D0
      goto loc_136D0;
    stack16(_bp, 6) = _ax;                        //mov [bp+arg_2], ax
    _ax = stack16(_bp, 4);                        //mov ax, [bp+arg_0]
    _ax >>= 1;                                    //shr ax, 1
    stack16(_bp, 4) = _ax;                        //mov [bp+arg_0], ax
    goto loc_135BF;                               //jmp loc_135BF
loc_136D0:                                        //loc_136D0:
    _bp = _pop();                                 //pop bp
    _stackReduce(4);                              //retn 4
    return;
}


void sub_136D4()
{
    _push(_bp);                                   //push bp
    _bp = _sp;                                    //mov bp, sp
    _sp -= 0x0a;                                  //sub sp, 0Ah
    _ax = memory16(_ds, 0x94F4);                  //mov ax, word_1CF44
    _es = _ax;                                    //mov es, ax
    _ax = stack16(_bp, 8);                        //mov ax, [bp+arg_4]
    if (_ax == 0x0000)                            //jz short loc_136FA
      goto loc_136FA;
    _bx = _ax;                                    //mov bx, ax
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax += _bx;                                   //add ax, bx
    _ax <<= 1;                                    //shl ax, 1
    _ax += 0x0005;                                //add ax, 5
    _bl = 0x0c;                                   //mov bl, 0Ch
    _div(_bl);                                    //div bl
    _ah = 0x00;                                   //mov ah, 0
loc_136FA:                                        //loc_136FA:
    stack16(_bp, 8) = _ax;                        //mov [bp+arg_4], ax
    _ax = stack16(_bp, 4);                        //mov ax, [bp+arg_0]
    if (_ax == 0x0000)                            //jz short loc_13718
      goto loc_13718;
    _bx = _ax;                                    //mov bx, ax
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax += _bx;                                   //add ax, bx
    _ax <<= 1;                                    //shl ax, 1
    _ax += 0x0005;                                //add ax, 5
    _bl = 0x0c;                                   //mov bl, 0Ch
    _div(_bl);                                    //div bl
    _ah = 0x00;                                   //mov ah, 0
loc_13718:                                        //loc_13718:
    stack16(_bp, 4) = _ax;                        //mov [bp+arg_0], ax
    _ax = stack16(_bp, 10);                       //mov ax, [bp+arg_6]
    _bx = stack16(_bp, 6);                        //mov bx, [bp+arg_2]
    if (_bx >= _ax)                               //jnb short loc_13737
      goto loc_13737;
    stack16(_bp, 10) = _bx;                       //mov [bp+arg_6], bx
    stack16(_bp, 6) = _ax;                        //mov [bp+arg_2], ax
    _ax = stack16(_bp, 8);                        //mov ax, [bp+arg_4]
    _bx = stack16(_bp, 4);                        //mov bx, [bp+arg_0]
    stack16(_bp, 8) = _bx;                        //mov [bp+arg_4], bx
    stack16(_bp, 4) = _ax;                        //mov [bp+arg_0], ax
loc_13737:                                        //loc_13737:
    _ax = stack16(_bp, 6);                        //mov ax, [bp+arg_2]
    _ax = _ax - stack16(_bp, 10);                 //sub ax, [bp+arg_6]
    stack16(_bp, -2) = _ax;                       //mov [bp+var_2], ax
    _ax = stack16(_bp, 4);                        //mov ax, [bp+arg_0]
    _flags.sign = (short)(_ax - stack16(_bp, 8)) < 0;//sub ax, [bp+arg_4]
    _ax = _ax - stack16(_bp, 8);
    if (!_flags.sign)                             //jns short loc_13751
      goto loc_13751;
    _ax = -_ax;                                   //neg ax
    stack16(_bp, -10) = 0xffe0;                   //mov [bp+var_A], 0FFE0h
    goto loc_13756;                               //jmp short loc_13756
loc_13751:                                        //loc_13751:
    stack16(_bp, -10) = 0x20;                     //mov [bp+var_A], 20h
loc_13756:                                        //loc_13756:
    stack16(_bp, -4) = _ax;                       //mov [bp+var_4], ax
    _cx = stack16(_bp, -2);                       //mov cx, [bp+var_2]
    if (_cx == 0x0000)                            //jz short loc_137DB
      goto loc_137DB;
    if (_ax != 0x0000)                            //jnz short loc_13769
      goto loc_13769;
    goto loc_137ED;                               //jmp loc_137ED
loc_13769:                                        //loc_13769:
    if (_ax >= stack16(_bp, -2))                  //jnb short loc_137A4
      goto loc_137A4;
    _ax = stack16(_bp, -2);                       //mov ax, [bp+var_2]
    _ax >>= 1;                                    //shr ax, 1
    stack16(_bp, -6) = _ax;                       //mov [bp+var_6], ax
    sub_13801();                                  //call sub_13801
    _cx = stack16(_bp, -2);                       //mov cx, [bp+var_2]
loc_1377C:                                        //loc_1377C:
    _al >>= 1;                                    //shr al, 1
    if (_al != 0)                                 //jnz short loc_13783
      goto loc_13783;
    _al = 0x80;                                   //mov al, 80h
    _di += 1;                                     //inc di
loc_13783:                                        //loc_13783:
    _bx = stack16(_bp, -6);                       //mov bx, [bp+var_6]
    _bx = _bx + stack16(_bp, -4);                 //add bx, [bp+var_4]
    stack16(_bp, -6) = _bx;                       //mov [bp+var_6], bx
    if (_bx <= stack16(_bp, -2))                  //jbe short loc_1379D
      goto loc_1379D;
    _bx = _bx - stack16(_bp, -2);                 //sub bx, [bp+var_2]
    stack16(_bp, -6) = _bx;                       //mov [bp+var_6], bx
    _bx = stack16(_bp, -10);                      //mov bx, [bp+var_A]
    _di = _di + stack16(_bp, -10);                //add di, [bp+var_A]
loc_1379D:                                        //loc_1379D:
    memory(_es, _di) |= _al;                      //or es:[di], al
    if (--_cx)                                    //loop loc_1377C
      goto loc_1377C;
    goto loc_137D5;                               //jmp short loc_137D5
loc_137A4:                                        //loc_137A4:
    _ax = stack16(_bp, -4);                       //mov ax, [bp+var_4]
    _ax >>= 1;                                    //shr ax, 1
    stack16(_bp, -6) = _ax;                       //mov [bp+var_6], ax
    sub_13801();                                  //call sub_13801
    _cx = stack16(_bp, -4);                       //mov cx, [bp+var_4]
loc_137B2:                                        //loc_137B2:
    _di = _di + stack16(_bp, -10);                //add di, [bp+var_A]
    _bx = stack16(_bp, -6);                       //mov bx, [bp+var_6]
    _bx = _bx + stack16(_bp, -2);                 //add bx, [bp+var_2]
    stack16(_bp, -6) = _bx;                       //mov [bp+var_6], bx
    if (_bx <= stack16(_bp, -4))                  //jbe short loc_137D0
      goto loc_137D0;
    _bx = _bx - stack16(_bp, -4);                 //sub bx, [bp+var_4]
    stack16(_bp, -6) = _bx;                       //mov [bp+var_6], bx
    _al >>= 1;                                    //shr al, 1
    if (_al != 0)                                 //jnz short loc_137D0
      goto loc_137D0;
    _al = 0x80;                                   //mov al, 80h
    _di += 1;                                     //inc di
loc_137D0:                                        //loc_137D0:
    memory(_es, _di) |= _al;                      //or es:[di], al
    if (--_cx)                                    //loop loc_137B2
      goto loc_137B2;
loc_137D5:                                        //loc_137D5:
    _sp = _bp;                                    //mov sp, bp
    _bp = _pop();                                 //pop bp
    _stackReduce(8);                              //retn 8
    return;
loc_137DB:                                        //loc_137DB:
    sub_13801();                                  //call sub_13801
    _cx = stack16(_bp, -4);                       //mov cx, [bp+var_4]
    if (_cx == 0)                                 //jcxz short loc_137D5
      goto loc_137D5;
loc_137E3:                                        //loc_137E3:
    _di = _di + stack16(_bp, -10);                //add di, [bp+var_A]
    memory(_es, _di) |= _al;                      //or es:[di], al
    if (--_cx)                                    //loop loc_137E3
      goto loc_137E3;
    goto loc_137D5;                               //jmp short loc_137D5
loc_137ED:                                        //loc_137ED:
    sub_13801();                                  //call sub_13801
    _cx = stack16(_bp, -2);                       //mov cx, [bp+var_2]
loc_137F3:                                        //loc_137F3:
    _al >>= 1;                                    //shr al, 1
    if (_al != 0)                                 //jnz short loc_137FA
      goto loc_137FA;
    _al = 0x80;                                   //mov al, 80h
    _di += 1;                                     //inc di
loc_137FA:                                        //loc_137FA:
    memory(_es, _di) |= _al;                      //or es:[di], al
    if (--_cx)                                    //loop loc_137F3
      goto loc_137F3;
    goto loc_137D5;                               //jmp short loc_137D5
}

/*
void sub_136D4() // draw line
{
    _push(_bp);                                   //push bp
    _bp = _sp;                                    //mov bp, sp
    
    stack16(_bp, 4)  = 50;
    stack16(_bp, 6)  = 50;
    stack16(_bp, 8)  = 100;
    stack16(_bp, 10)  = 100;

    std::cout << std::dec << "line(" << stack16(_bp, 4) << ", "
    << stack16(_bp, 6) << ", "
    << stack16(_bp, 8) << ", "
    << stack16(_bp, 10) << "\n";

    _sp -= 0x0a;                                  //sub sp, 0Ah
    
    _ax = memory16(_ds, 0x94F4);                  //mov ax, word_1CF44
    _es = _ax;                                    //mov es, ax
    _ax = stack16(_bp, 8);                        //mov ax, [bp+arg_4]
    if (_ax == 0x0000)                            //jz short loc_136FA
      goto loc_136FA;
    _bx = _ax;                                    //mov bx, ax
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax += _bx;                                   //add ax, bx
    _ax <<= 1;                                    //shl ax, 1
    _ax += 0x0005;                                //add ax, 5
    _bl = 0x0c;                                   //mov bl, 0Ch
    _div(_bl);                                    //div bl
    _ah = 0x00;                                   //mov ah, 0
loc_136FA:                                        //loc_136FA:
    stack16(_bp, 8) = _ax;                        //mov [bp+arg_4], ax
    _ax = stack16(_bp, 4);                        //mov ax, [bp+arg_0]
    if (_ax == 0x0000)                            //jz short loc_13718
      goto loc_13718;
    _bx = _ax;                                    //mov bx, ax
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax += _bx;                                   //add ax, bx
    _ax <<= 1;                                    //shl ax, 1
    _ax += 0x0005;                                //add ax, 5
    _bl = 0x0c;                                   //mov bl, 0Ch
    _div(_bl);                                    //div bl
    _ah = 0x00;                                   //mov ah, 0
loc_13718:                                        //loc_13718:
    stack16(_bp, 4) = _ax;                        //mov [bp+arg_0], ax
    _ax = stack16(_bp, 10);                       //mov ax, [bp+arg_6]
    _bx = stack16(_bp, 6);                        //mov bx, [bp+arg_2]
    if (_bx >= _ax)                               //jnb short loc_13737
      goto loc_13737;
    stack16(_bp, 10) = _bx;                       //mov [bp+arg_6], bx
    stack16(_bp, 6) = _ax;                        //mov [bp+arg_2], ax
    _ax = stack16(_bp, 8);                        //mov ax, [bp+arg_4]
    _bx = stack16(_bp, 4);                        //mov bx, [bp+arg_0]
    stack16(_bp, 8) = _bx;                        //mov [bp+arg_4], bx
    stack16(_bp, 4) = _ax;                        //mov [bp+arg_0], ax
loc_13737:                                        //loc_13737:
    _ax = stack16(_bp, 6);                        //mov ax, [bp+arg_2]
    _ax = _ax - stack16(_bp, 10);                 //sub ax, [bp+arg_6]
    stack16(_bp, -2) = _ax;                       //mov [bp+var_2], ax
    _ax = stack16(_bp, 4);                        //mov ax, [bp+arg_0]
    _flags.sign = (short)(_ax - stack16(_bp, 8)) < 0;//sub ax, [bp+arg_4]
    _ax = _ax - stack16(_bp, 8);
    if (!_flags.sign)                              //jns short loc_13751
      goto loc_13751;
    _ax = -_ax;                                   //neg ax
    stack16(_bp, -10) = 0xffe0;                   //mov [bp+var_A], 0FFE0h
    goto loc_13756;                               //jmp short loc_13756
loc_13751:                                        //loc_13751:
    stack16(_bp, -10) = 0x20;                     //mov [bp+var_A], 20h
loc_13756:                                        //loc_13756:
    stack16(_bp, -4) = _ax;                       //mov [bp+var_4], ax
    _cx = stack16(_bp, -2);                       //mov cx, [bp+var_2]
    if (_cx == 0x0000)                            //jz short loc_137DB
      goto loc_137DB;
    if (_ax != 0x0000)                            //jnz short loc_13769
      goto loc_13769;
    goto loc_137ED;                               //jmp loc_137ED
loc_13769:                                        //loc_13769:
    if (_ax >= stack16(_bp, -2))                  //jnb short loc_137A4
      goto loc_137A4;
    _ax = stack16(_bp, -2);                       //mov ax, [bp+var_2]
    _ax >>= 1;                                    //shr ax, 1
    stack16(_bp, -6) = _ax;                       //mov [bp+var_6], ax
    sub_13801();                                  //call sub_13801
    _cx = stack16(_bp, -2);                       //mov cx, [bp+var_2]
loc_1377C:                                        //loc_1377C:
    _al >>= 1;                                    //shr al, 1
    if (_al != 0)                                 //jnz short loc_13783
      goto loc_13783;
    _al = 0x80;                                   //mov al, 80h
    _di += 1;                                     //inc di
loc_13783:                                        //loc_13783:
    _bx = stack16(_bp, -6);                       //mov bx, [bp+var_6]
    _bx = _bx + stack16(_bp, -4);                 //add bx, [bp+var_4]
    stack16(_bp, -6) = _bx;                       //mov [bp+var_6], bx
    if (_bx <= stack16(_bp, -2))                  //jbe short loc_1379D
      goto loc_1379D;
    _bx = _bx - stack16(_bp, -2);                 //sub bx, [bp+var_2]
    stack16(_bp, -6) = _bx;                       //mov [bp+var_6], bx
    _bx = stack16(_bp, -10);                      //mov bx, [bp+var_A]
    _di = _di + stack16(_bp, -10);                //add di, [bp+var_A]
loc_1379D:                                        //loc_1379D:
    memory(_es, _di) |= _al;                      //or es:[di], al
    if (--_cx)                                    //loop loc_1377C
      goto loc_1377C;
    goto loc_137D5;                               //jmp short loc_137D5
loc_137A4:                                        //loc_137A4:
    _ax = stack16(_bp, -4);                       //mov ax, [bp+var_4]
    _ax >>= 1;                                    //shr ax, 1
    stack16(_bp, -6) = _ax;                       //mov [bp+var_6], ax
    sub_13801();                                  //call sub_13801
    _cx = stack16(_bp, -4);                       //mov cx, [bp+var_4]
loc_137B2:                                        //loc_137B2:
    _di = _di + stack16(_bp, -10);                //add di, [bp+var_A]
    _bx = stack16(_bp, -6);                       //mov bx, [bp+var_6]
    _bx = _bx + stack16(_bp, -2);                 //add bx, [bp+var_2]
    stack16(_bp, -6) = _bx;                       //mov [bp+var_6], bx
    if (_bx <= stack16(_bp, -4))                  //jbe short loc_137D0
      goto loc_137D0;
    _bx = _bx - stack16(_bp, -4);                 //sub bx, [bp+var_4]
    stack16(_bp, -6) = _bx;                       //mov [bp+var_6], bx
    _al >>= 1;                                    //shr al, 1
    if (_al != 0)                                 //jnz short loc_137D0
      goto loc_137D0;
    _al = 0x80;                                   //mov al, 80h
    _di += 1;                                     //inc di
loc_137D0:                                        //loc_137D0:
    memory(_es, _di) |= _al;                      //or es:[di], al
    if (--_cx)                                    //loop loc_137B2
      goto loc_137B2;
loc_137D5:                                        //loc_137D5:
    _sp = _bp;                                    //mov sp, bp
    _bp = _pop();                                 //pop bp
    _stackReduce(8);                              //retn 8
    return;
loc_137DB:                                        //loc_137DB:
    sub_13801();                                  //call sub_13801
    _cx = stack16(_bp, -4);                       //mov cx, [bp+var_4]
    if (_cx == 0)                                 //jcxz short loc_137D5
      goto loc_137D5;
loc_137E3:                                        //loc_137E3:
    _di = _di + stack16(_bp, -10);                //add di, [bp+var_A]
    memory(_es, _di) |= _al;                      //or es:[di], al
    if (--_cx)                                    //loop loc_137E3
      goto loc_137E3;
    goto loc_137D5;                               //jmp short loc_137D5
loc_137ED:                                        //loc_137ED:
    sub_13801();                                  //call sub_13801
    _cx = stack16(_bp, -2);                       //mov cx, [bp+var_2]
loc_137F3:                                        //loc_137F3:
    _al >>= 1;                                    //shr al, 1
    if (_al != 0)                                 //jnz short loc_137FA
      goto loc_137FA;
    _al = 0x80;                                   //mov al, 80h
    _di += 1;                                     //inc di
loc_137FA:                                        //loc_137FA:
    memory(_es, _di) |= _al;                      //or es:[di], al
    if (--_cx)                                    //loop loc_137F3
      goto loc_137F3;
    goto loc_137D5;                               //jmp short loc_137D5
}
*/

void sub_13840()
{
    _ah = memory(_ds, 0x955E);                    //mov ah, byte_1CFAE
    if (_ah == 0x00)                              //jz short loc_1384A
      goto loc_1384A;
    return;                                       //retn
loc_1384A:                                        //loc_1384A:
    _ah = memory(_ds, 0x9506);                    //mov ah, byte_1CF56
    if (_ah != 0x00)                              //jnz short loc_13854
      goto loc_13854;
    return;                                       //retn
loc_13854:                                        //loc_13854:
    _ah = memory(_ds, 0x9550);                    //mov ah, byte_1CFA0
    if (_ah != 0x00)                              //jnz short loc_13866
      goto loc_13866;
    _push(_bx);                                   //push bx
    memory(_ds, 0x9550) = _al;                    //mov byte_1CFA0, al
    sub_13914();                                  //call sub_13914
    _bx = _pop();                                 //pop bx
    return;                                       //retn
loc_13866:                                        //loc_13866:
    _ah = memory(_ds, 0x9551);                    //mov ah, byte_1CFA1
    if (_ah != 0x00)                              //jnz short loc_13873
      goto loc_13873;
    memory(_ds, 0x9551) = _al;                    //mov byte_1CFA1, al
    return;                                       //retn
loc_13873:                                        //loc_13873:
    if (_al <= memory(_ds, 0x9552))               //jbe short locret_1387C
      goto locret_1387C;
    memory(_ds, 0x9552) = _al;                    //mov byte_1CFA2, al
locret_1387C:                                     //locret_1387C:
    return;
}

void sub_139B8()
{
    memory(_ds, 0x9561) = 0;                      //mov byte_1CFB1, 0
    memory16(_ds, 0x955F) = 0;                    //mov word_1CFAF, 0
    memory(_ds, 0x955E) = 1;                      //mov byte_1CFAE, 1
    _al = memory(_ds, 0x9546);                    //mov al, byte_1CF96
    if (_al != 0x00)                              //jnz short loc_139D4
      goto loc_139D4;
    _ax = 0x8dec;                                 //mov ax, 8DECh
    goto loc_139D7;                               //jmp short loc_139D7
loc_139D4:                                        //loc_139D4:
    _ax = 0x8d4c;                                 //mov ax, 8D4Ch
loc_139D7:                                        //loc_139D7:
    memory16(_ds, 0x9562) = _ax;                  //mov word_1CFB2, ax
}
