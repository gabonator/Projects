void start();
void sub_13F3D(int pc = 0);
void sub_13FEE();
void sub_140C1();
void sub_140F6();
void sub_14119();
void sub_141D6();
void sub_1431E();
void loc_14327();
void sub_14332();
void sub_14396();
void sub_143FA();
void sub_1444F();
void sub_14521();
void sub_1456E();
void sub_14587();
void sub_14601();
void sub_1461B();
void sub_14639();
void sub_14791();
void sub_147BA();
void sub_147E7();
void sub_1487F();
void sub_14BA3();
void sub_14BFA();
void sub_14CE4();
void sub_14D8C();
void sub_14E49();
void sub_14E74();
void sub_14EE9();
void sub_14F52();
void sub_14FB4();
void loc_1501E();
void sub_15079();
void sub_15097();
void sub_150E5();
void loc_15118();
void sub_1513F();
void sub_1514D();
void sub_15248();
void sub_152B4();
void sub_152C7();
void sub_153F0();
void sub_154AA();
void sub_154E6();
void sub_1556B();
void sub_155C9();
void sub_155E2();
void sub_1564C();
void sub_15666();
void sub_1568B();
void sub_15697();
void sub_156E7();
void sub_158E0();
void sub_158EC();
void sub_158F3();
void sub_159B3();
void sub_15B67();
void sub_15C46();
void sub_15C79();
void sub_15C9A();
void sub_15CB2();
void sub_15CC3();
void sub_15CC8();
void sub_15D2B();
void sub_15D31();
void loc_15D3C();
void sub_15D57();
void sub_15D7C();
void sub_15DAA();
void sub_15DB2();
void sub_15DFA();
void sub_15E6F();
void sub_15ECC();
void sub_15EDD();
void sub_15F15();
void sub_15F3A();
void sub_15F62();
void sub_15FA8();
void sub_15FC4();
void sub_1602F();
void loc_1603E(int pc = 0);
void sub_1610E();
void sub_16138();
void sub_1616A();
void sub_16184();
void sub_161B6();
void sub_161D8();
void sub_16202();
void sub_16216();
void sub_1622F();
void sub_1623A();
void sub_16299();
void sub_162CC();
void sub_162FF();
void sub_16332();
void sub_16365();
void sub_16398();
void sub_163CB();
void sub_163FE();
void sub_16431();
void sub_164BF();
void sub_165E5();
void sub_16703();
void sub_167C7();
void sub_1680D();
void sub_168F2();
void sub_16919();
void sub_16998();
void sub_16A07();
void sub_16A2A();
void sub_16A4D();
void sub_16CA8();
void sub_16CCD();
void sub_16D16();
void loc_16D3D();
void sub_16E1B();
void sub_16E59();
void loc_16E88();
void sub_16F07();
void sub_16F47();
void sub_16F87();
void sub_16FAB();
void sub_16FD3();
void sub_17192();
void sub_171AF();
void sub_172B1();
void loc_172E6();
void sub_172F7();
void sub_1741F();
void sub_174D1();
void sub_1752C();
void sub_1756C();
void sub_175AC();
void sub_175D0();
void sub_175F8();
void sub_1763F();
void sub_17680();
void sub_1769B();
void sub_176C7();
void sub_176FC();
void sub_17738();
void sub_17772();
void sub_1778E();
void sub_17805();
void sub_1787C();
void sub_17885();
void sub_1793C();
void sub_179E3();
void sub_17A24();
void sub_17A68();
void sub_17A71();
void sub_17A8C();
void sub_17AAD();
void sub_17ACE();
void sub_17AEF();
void sub_17B10();
void sub_17B14();
void sub_17B2A();
void sub_17B46();
void sub_17B62();
void sub_17B7E();
void sub_17B9A();
void sub_17BCB();
void sub_17C31();
void sub_17D17();
void sub_17D32();
void sub_17DD8();
void sub_17E3A();
void sub_17EC6();
void sub_17F06();
void sub_17F1E();
void sub_17F44();
void sub_17F76();
void sub_17F7B();
void sub_180A7();
void sub_180D2();
void sub_180E0(int pc = 0);
void sub_1813A();
void loc_1819F();
void sub_181A3();
void sub_181C1();
void loc_181E6();
void sub_181FA();
void sub_1822B();
void sub_1826D();
void start()  // Entry function
{
    WORD _cs = _seg002;

    _push(_ds);                                 //push ds
    _ax = 0x0000;                               //mov ax, 0
    _push(_ax);                                 //push ax
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _interrupt(18);                             //int 12h
    _cl = 0x06;                                 //mov cl, 6
    _ax <<= _cl;                                //shl ax, cl
    _bx = _cs;                                  //mov bx, cs
    _bx += 0x1000;                              //add bx, 1000h
    _ax -= _bx;                                 //sub ax, bx
    if (_ax > 0x1000)                           //ja short loc_13EF5
      goto loc_13EF5;
    _ax = 0x0003;                               //mov ax, 3
    _interrupt(16);                             //int 10h
    _lea(_dx, _ds, 0x0377);                     //lea dx, unk_10577
    _ah = 0x09;                                 //mov ah, 9
    _interrupt(33);                             //int 21h
    _ah = 0x4c;                                 //mov ah, 4Ch
    _interrupt(33);                             //int 21h
loc_13EF5:                                      //loc_13EF5:
    memory16(_ds, 0x261) = _bx;                 //mov word_10461, bx
    _ax = 0x024b;                               //mov ax, 24Bh
    _cl = 0x04;                                 //mov cl, 4
    _ax >>= _cl;                                //shr ax, cl
    _ax += 1;                                   //inc ax
    _bx += _ax;                                 //add bx, ax
    memory16(_ds, 0x263) = _bx;                 //mov word_10463, bx
    _ax = 0x0211;                               //mov ax, 211h
    _cl = 0x04;                                 //mov cl, 4
    _ax >>= _cl;                                //shr ax, cl
    _ax += 1;                                   //inc ax
    _bx += _ax;                                 //add bx, ax
    memory16(_ds, 0x265) = _bx;                 //mov word_10465, bx
    _bx += _ax;                                 //add bx, ax
    memory16(_ds, 0x267) = _bx;                 //mov word_10467, bx
    _bx += _ax;                                 //add bx, ax
    memory16(_ds, 0x269) = _bx;                 //mov word_10469, bx
    _bx += _ax;                                 //add bx, ax
    memory16(_ds, 0x26B) = _bx;                 //mov word_1046B, bx
    sub_181C1();                                //call sub_181C1
    memory(_ds, 0x111D) = 0x00;                 //mov byte_1131D, 0
    _ax = 0x0010;                               //mov ax, 10h
    _interrupt(16);                             //int 10h
    sub_13F3D();                                //call sub_13F3D
    _ax = 0x0003;                               //mov ax, 3
    _interrupt(16);                             //int 10h
    return;                                     //retf
    _STOP_("sp-trace-fail");                    //start  endp_failed
    _STOP_("continues");                        //sub_13F3D proc near
}

void sub_13F3D(int pc)
{
    if (pc == 0x13FB9)
        goto loc_13FB9;
    
    memory16(_ds, 0x251) = _sp;                 //mov word_10451, sp
    sub_15CC3();                                //call sub_15CC3
    memory(_ds, 0x1451) = _ch;                  //mov byte_11651, ch
    memory(_ds, 0x1452) = _cl;                  //mov byte_11652, cl
    memory(_ds, 0x1453) = _dh;                  //mov byte_11653, dh
    _ax = memory16(_ds, 0x261);                 //mov ax, word_10461
    sub_14601();                                //call sub_14601
    sub_140F6();                                //call sub_140F6
    sub_15CC8();                                //call sub_15CC8
    sub_13FEE();                                //call sub_13FEE
    sub_1787C();                                //call sub_1787C
    sub_147BA();                                //call sub_147BA
loc_13F65:                                      //loc_13F65:
    _ax = 0x0003;                               //mov ax, 3
    _interrupt(16);                             //int 10h
    _cx = 0x2000;                               //mov cx, 2000h
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(16);                             //int 10h
    _bl = 0x00;                                 //mov bl, 0
    _ax = 0x1003;                               //mov ax, 1003h
    _interrupt(16);                             //int 10h
    _es = memory16(_ds, 0x24F);                 //mov es, word_1044F
    sub_147BA();                                //call sub_147BA
    if (memory(_ds, 0x212A) != 0x01)            //jnz short loc_13F89
      goto loc_13F89;
    sub_153F0();                                //call sub_153F0
loc_13F89:                                      //loc_13F89:
    sub_1487F();                                //call sub_1487F
    if (memory(_ds, 0x65) == 0x01)              //jz short loc_13FE7
      goto loc_13FE7;
loc_13F93:                                      //loc_13F93:
    _ax = memory16(_ds, 0x261);                 //mov ax, word_10461
    sub_1461B();                                //call sub_1461B
    _ax = 0x0010;                               //mov ax, 10h
    _interrupt(16);                             //int 10h
    _al = memory(_ds, 0x650);                   //mov al, byte_10850
    memory(_ds, 0x64F) = _al;                   //mov byte_1084F, al
    memory(_ds, 0x64E) = 0x01;                  //mov byte_1084E, 1
    if (memory(_ds, 0x64F) != 0x01)             //jnz short loc_13FB6
      goto loc_13FB6;
    sub_14119();                                //call sub_14119
    goto loc_13FB9;                             //jmp short loc_13FB9
loc_13FB6:                                      //loc_13FB6:
    sub_141D6();                                //call sub_141D6
loc_13FB9:                                      //loc_13FB9:
    _sp = memory16(_ds, 0x251);                 //mov sp, word_10451
    _in(_al, 97);                               //in al, 61h
    _al &= 0xfc;                                //and al, 0FCh
    _out(97, _al);                              //out 61h, al
    memory16(_ds, 0x5A8) = 0x0000;              //mov word_107A8, 0
    _lea(_si, _ds, 0x05ac);                     //lea si, unk_107AC
    memory16(_ds, 0x5AA) = _si;                 //mov word_107AA, si
    if (memory(_ds, 0x65) == 0x01)              //jz short loc_13FE7
      goto loc_13FE7;
    if (memory(_ds, 0x63) == 0x01)              //jz short loc_13F93
      goto loc_13F93;
    memory(_ds, 0x64E) = 0x00;                  //mov byte_1084E, 0
    goto loc_13F65;                             //jmp loc_13F65
loc_13FE7:                                      //loc_13FE7:
    sub_15B67();                                //call sub_15B67
    sub_15D57();                                //call sub_15D57
}

void sub_13FEE()
{
    _lea(_dx, _ds, 0x251a);                     //lea dx, unk_1271A
    _ah = 0x09;                                 //mov ah, 9
    _interrupt(33);                             //int 21h
    sub_15CC3();                                //call sub_15CC3
    memory16(_ds, 0x2518) = _dx;                //mov word_12718, dx
    _cx = 0x0010;                               //mov cx, 10h
loc_14000:                                      //loc_14000:
    _push(_cx);                                 //push cx
    _cx = 0xfde8;                               //mov cx, 0FDE8h
loc_14004:                                      //loc_14004:
    if (--_cx)                                  //loop loc_14004
      goto loc_14004;
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_14000
      goto loc_14000;
    sub_140C1();                                //call sub_140C1
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _dx = memory16(_ds, _bx + 9574);            //mov dx, [bx+2566h]
    _bx >>= 1;                                  //shr bx, 1
    if ((short)_bx < (short)0x0050)             //jl short loc_1403C
      goto loc_1403C;
    if ((short)_bx < (short)0x03e8)             //jl short loc_14028
      goto loc_14028;
    goto loc_140BA;                             //jmp loc_140BA
loc_14028:                                      //loc_14028:
    _si = 0x009f;                               //mov si, 9Fh
    _cx = 0x0050;                               //mov cx, 50h
loc_1402E:                                      //loc_1402E:
    _cx += 0x0014;                              //add cx, 14h
    _si += 1;                                   //inc si
    if ((short)_cx < (short)_bx)                //jl short loc_1402E
      goto loc_1402E;
    _dl = memory(_ds, _si + 9574);              //mov dl, [si+2566h]
    _dh = 0x00;                                 //mov dh, 0
loc_1403C:                                      //loc_1403C:
    if (memory(_ds, 0x2517) <= 0x01)            //jbe short loc_14058
      goto loc_14058;
    memory(_ds, 0x2517) -= 1;                   //dec byte_12717
    _ax = memory16(_ds, 0x2513);                //mov ax, word_12713
    _ax -= 0x0006;                              //sub ax, 6
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    memory16(_ds, 0x1120) += _ax;               //add word_11320, ax
    goto loc_14077;                             //jmp short loc_14077
loc_14058:                                      //loc_14058:
    if (memory16(_ds, 0x2513) >= 0x000f)        //jnb short loc_14097
      goto loc_14097;
    memory(_ds, 0x2517) = 0x0e;                 //mov byte_12717, 0Eh
    _cx = memory16(_ds, 0x2513);                //mov cx, word_12713
    _cx -= 0x0006;                              //sub cx, 6
    _cx <<= 1;                                  //shl cx, 1
    _cx <<= 1;                                  //shl cx, 1
    memory16(_ds, 0x1120) += _cx;               //add word_11320, cx
    memory16(_ds, 0x2513) += 1;                 //inc word_12713
loc_14077:                                      //loc_14077:
    if (memory16(_ds, 0x2513) & 0x0001)         //jnz short loc_14091
      goto loc_14091;
    if (memory(_ds, 0x2517) != 0x07)            //jnz short loc_14091
      goto loc_14091;
    memory16(_ds, 0x2141) += 0x0140;            //add word_12341, 140h
    memory16(_ds, 0x215F) += 0x0004;            //add word_1235F, 4
loc_14091:                                      //loc_14091:
    if ((short)_dx > (short)memory16(_ds, 0x1120))//jg short loc_1403C
      goto loc_1403C;
loc_14097:                                      //loc_14097:
    if (memory16(_ds, 0x1120) < 0x0064)         //jb short loc_140BA
      goto loc_140BA;
    memory(_ds, 0x50E) >>= 1;                   //shr byte_1070E, 1
    if (memory16(_ds, 0x1120) < 0x00c8)         //jb short loc_140BA
      goto loc_140BA;
    memory(_ds, 0x50E) >>= 1;                   //shr byte_1070E, 1
    if (memory16(_ds, 0x1120) < 0x012c)         //jb short loc_140BA
      goto loc_140BA;
    memory(_ds, 0x50E) >>= 1;                   //shr byte_1070E, 1
loc_140BA:                                      //loc_140BA:
    _ax = memory16(_ds, 0x1120);                //mov ax, word_11320
    memory16(_ds, 0x401) = _ax;                 //mov word_10601, ax
}

void sub_140C1()
{
    sub_15CC3();                                //call sub_15CC3
    _ax = memory16(_ds, 0x2518);                //mov ax, word_12718
    _bh = 0x00;                                 //mov bh, 0
    _bl = _dl;                                  //mov bl, dl
    if (_ah == _dh)                             //jz short loc_140F1
      goto loc_140F1;
    if ((char)_ah < (char)_dh)                  //jl short loc_140DA
      goto loc_140DA;
    _ah = -_ah;                                 //neg ah
    _ah += 0x3c;                                //add ah, 3Ch
    _dh += _ah;                                 //add dh, ah
    _ah = 0x00;                                 //mov ah, 0
loc_140DA:                                      //loc_140DA:
    _dh -= 1;                                   //dec dh
    if (_ah == _dh)                             //jz short loc_140E5
      goto loc_140E5;
    _bx += 0x0064;                              //add bx, 64h
    goto loc_140DA;                             //jmp short loc_140DA
loc_140E5:                                      //loc_140E5:
    _ah = 0x00;                                 //mov ah, 0
    _ax = -_ax;                                 //neg ax
    _ax += 0x0063;                              //add ax, 63h
    _bx += _ax;                                 //add bx, ax
    goto locret_140F5;                          //jmp short locret_140F5
    _STOP_("db 90h");                           //db 90h
loc_140F1:                                      //loc_140F1:
    _ah = 0x00;                                 //mov ah, 0
    _bx -= _ax;                                 //sub bx, ax
locret_140F5:                                   //locret_140F5:
    return;
}

void sub_140F6()
{
    _ax = 0x1222;                               //mov ax, 1222h
    _di = 0x002c;                               //mov di, 2Ch
    _cx = 0x000b;                               //mov cx, 0Bh
loc_140FF:                                      //loc_140FF:
    _push(_cx);                                 //push cx
    _cx = 0x0013;                               //mov cx, 13h
loc_14103:                                      //loc_14103:
    memory16(_ds, _di + 1617) = _ax;            //mov [di+651h], ax
    _ax += 0x0004;                              //add ax, 4
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_14103
      goto loc_14103;
    _ax += 0x0734;                              //add ax, 734h
    _di += 0x0004;                              //add di, 4
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_140FF
      goto loc_140FF;
}

void sub_14119()
{
    memory(_ds, 0x253) = 0x00;                  //mov byte_10453, 0
    memory16(_ds, 0x3D3) = 0x0000;              //mov word ptr unk_105D3, 0
    memory16(_ds, 0x3D7) = 0x0000;              //mov word_105D7, 0
    memory(_ds, 0x2127) = 0x00;                 //mov byte_12327, 0
loc_1412F:                                      //loc_1412F:
    sub_143FA();                                //call sub_143FA
    _ax = memory16(_ds, 0x263);                 //mov ax, word_10463
    sub_14601();                                //call sub_14601
    memory16(_ds, 0x3D5) = 0x0001;              //mov word_105D5, 1
loc_1413E:                                      //loc_1413E:
    sub_1456E();                                //call sub_1456E
    sub_1444F();                                //call sub_1444F
    sub_158F3();                                //call sub_158F3
loc_14147:                                      //loc_14147:
    sub_14587();                                //call sub_14587
    _sync();
    if (memory(_ds, 0x63) == 0x01)              //jz short loc_141D0
      goto loc_141D0;
    sub_16202();                                //call sub_16202
    if (memory16(_ds, 0x66) != 0x0000)          //jnz short loc_14147
      goto loc_14147;
    sub_158F3();                                //call sub_158F3
    if (memory(_ds, 0x65) == 0x01)              //jz short loc_141D0
      goto loc_141D0;
    if (memory(_ds, 0x246) == 0x01)             //jz short loc_141D0
      goto loc_141D0;
    if (memory16(_ds, 0x224) == 0x0000)         //jz short loc_141CB
      goto loc_141CB;
    if (memory(_ds, 0x22A) == 0x00)             //jz short loc_1417F
      goto loc_1417F;
    memory(_ds, 0x22A) -= 0x14;                 //sub byte_1042A, 14h
loc_1417F:                                      //loc_1417F:
    _ax = memory16(_ds, 0x263);                 //mov ax, word_10463
    sub_1461B();                                //call sub_1461B
    if (memory(_ds, 0x1449) == 0x01)            //jz short loc_141A0
      goto loc_141A0;
    if (memory16(_ds, 0x3D5) == 0x0003)         //jz short loc_141A0
      goto loc_141A0;
    memory16(_ds, 0x3D5) += 1;                  //inc word_105D5
    _bx = memory16(_ds, 0x3D3);                 //mov bx, word ptr unk_105D3
    sub_15DB2();                                //call sub_15DB2
    goto loc_1413E;                             //jmp short loc_1413E
loc_141A0:                                      //loc_141A0:
    if (memory(_ds, 0x1449) != 0x01)            //jnz short loc_141B1
      goto loc_141B1;
    if (memory16(_ds, 0x3D3) != 0x0002)         //jnz short loc_141B1
      goto loc_141B1;
    _STOP_("goto loc_15021");                   //jmp loc_15021
loc_141B1:                                      //loc_141B1:
    memory16(_ds, 0x3D3) += 0x0002;             //add word ptr unk_105D3, 2
    if (memory16(_ds, 0x3D3) != 0x0006)         //jnz short loc_141C8
      goto loc_141C8;
    memory16(_ds, 0x3D3) = 0x0000;              //mov word ptr unk_105D3, 0
    memory16(_ds, 0x3D7) += 0x0006;             //add word_105D7, 6
loc_141C8:                                      //loc_141C8:
    goto loc_1412F;                             //jmp loc_1412F
loc_141CB:                                      //loc_141CB:
    memory(_ds, 0x212A) = 0x01;                 //mov byte_1232A, 1
loc_141D0:                                      //loc_141D0:
    memory(_ds, 0x2127) = 0x01;                 //mov byte_12327, 1
}

void sub_141D6()
{
    memory(_ds, 0x2127) = 0x00;                 //mov byte_12327, 0
    memory(_ds, 0x217) = 0x01;                  //mov byte ptr word_10417, 1
    memory16(_ds, 0x3D3) = 0x0000;              //mov word ptr unk_105D3, 0
    sub_143FA();                                //call sub_143FA
    sub_1456E();                                //call sub_1456E
    _ax = memory16(_ds, 0x269);                 //mov ax, word_10469
    sub_14601();                                //call sub_14601
    _ax = memory16(_ds, 0x265);                 //mov ax, word_10465
    sub_14601();                                //call sub_14601
    goto loc_141FE;                             //jmp short loc_141FE
    _STOP_("db 90h");                           //db 90h
loc_141FB:                                      //loc_141FB:
    sub_143FA();                                //call sub_143FA
loc_141FE:                                      //loc_141FE:
    _ax = memory16(_ds, 0x263);                 //mov ax, word_10463
    sub_14601();                                //call sub_14601
    memory16(_ds, 0x21A) = 0x0001;              //mov word_1041A, 1
loc_1420A:                                      //loc_1420A:
    sub_1456E();                                //call sub_1456E
    sub_1444F();                                //call sub_1444F
    sub_158F3();                                //call sub_158F3
    _ax = memory16(_ds, 0x21A);                 //mov ax, word_1041A
    memory16(_ds, 0x3D5) = _ax;                 //mov word_105D5, ax
loc_14219:                                      //loc_14219:
    sub_14587();                                //call sub_14587
    if (memory(_ds, 0x63) != 0x01)              //jnz short loc_14226
      goto loc_14226;
    _STOP_("goto nullsub_1");                   //jmp nullsub_1
loc_14226:                                      //loc_14226:
    if (memory(_ds, 0x64) != 0x01)              //jnz short loc_14233
      goto loc_14233;
    sub_14332();                                //call sub_14332
    goto loc_142A7;                             //jmp short loc_142A7
    _STOP_("db 90h");                           //db 90h
loc_14233:                                      //loc_14233:
    sub_16202();                                //call sub_16202
    if (memory16(_ds, 0x66) != 0x0000)          //jnz short loc_14219
      goto loc_14219;
    sub_158F3();                                //call sub_158F3
    if (memory(_ds, 0x65) != 0x01)              //jnz short loc_1424A
      goto loc_1424A;
    _STOP_("goto nullsub_1");                   //jmp nullsub_1
loc_1424A:                                      //loc_1424A:
    _ax = memory16(_ds, 0x263);                 //mov ax, word_10463
    sub_1461B();                                //call sub_1461B
    if (memory16(_ds, 0x21A) == 0x0003)         //jz short loc_14264
      goto loc_14264;
    memory16(_ds, 0x21A) += 1;                  //inc word_1041A
    _bx = memory16(_ds, 0x218);                 //mov bx, word_10417+1
    sub_15DB2();                                //call sub_15DB2
    goto loc_1420A;                             //jmp short loc_1420A
loc_14264:                                      //loc_14264:
    memory16(_ds, 0x218) += 0x0002;             //add word_10417+1, 2
    memory16(_ds, 0x3D3) += 0x0002;             //add word ptr unk_105D3, 2
    if (memory16(_ds, 0x218) != 0x0006)         //jnz short loc_14286
      goto loc_14286;
    memory16(_ds, 0x218) = 0x0000;              //mov word_10417+1, 0
    memory16(_ds, 0x3D3) = 0x0000;              //mov word ptr unk_105D3, 0
    memory16(_ds, 0x21C) += 0x0006;             //add word_1041C, 6
loc_14286:                                      //loc_14286:
    goto loc_141FB;                             //jmp loc_141FB
loc_14289:                                      //loc_14289:
    sub_143FA();                                //call sub_143FA
    _ax = memory16(_ds, 0x265);                 //mov ax, word_10465
    sub_14601();                                //call sub_14601
    memory16(_ds, 0x220) = 0x0001;              //mov word_10420, 1
loc_14298:                                      //loc_14298:
    sub_1456E();                                //call sub_1456E
    sub_1444F();                                //call sub_1444F
    sub_158F3();                                //call sub_158F3
    _ax = memory16(_ds, 0x220);                 //mov ax, word_10420
    memory16(_ds, 0x3D5) = _ax;                 //mov word_105D5, ax
loc_142A7:                                      //loc_142A7:
    sub_14587();                                //call sub_14587
    if (memory(_ds, 0x63) != 0x01)              //jnz short loc_142B4
      goto loc_142B4;
    _STOP_("goto nullsub_1");                   //jmp short nullsub_1
loc_142B4:                                      //loc_142B4:
    if (memory(_ds, 0x64) != 0x01)              //jnz short loc_142C8
      goto loc_142C8;
    sub_14396();                                //call sub_14396
    if (memory(_ds, 0x2127) == 0x01)            //jz short nullsub_1
      _STOP_("goto nullsub_1");
    goto loc_14219;                             //jmp loc_14219
loc_142C8:                                      //loc_142C8:
    sub_16202();                                //call sub_16202
    if (memory16(_ds, 0x66) != 0x0000)          //jnz short loc_142A7
      goto loc_142A7;
    sub_158F3();                                //call sub_158F3
    if (memory(_ds, 0x65) != 0x01)              //jnz short loc_142DF
      goto loc_142DF;
    _STOP_("goto nullsub_1");                   //jmp short nullsub_1
    _STOP_("db 90h");                           //db 90h
loc_142DF:                                      //loc_142DF:
    _ax = memory16(_ds, 0x265);                 //mov ax, word_10465
    sub_1461B();                                //call sub_1461B
    if (memory16(_ds, 0x220) == 0x0003)         //jz short loc_142F9
      goto loc_142F9;
    memory16(_ds, 0x220) += 1;                  //inc word_10420
    _bx = memory16(_ds, 0x21E);                 //mov bx, word_1041E
    sub_15DB2();                                //call sub_15DB2
    goto loc_14298;                             //jmp short loc_14298
loc_142F9:                                      //loc_142F9:
    memory16(_ds, 0x21E) += 0x0002;             //add word_1041E, 2
    memory16(_ds, 0x3D3) += 0x0002;             //add word ptr unk_105D3, 2
    if (memory16(_ds, 0x21E) != 0x0006)         //jnz short loc_1431B
      goto loc_1431B;
    memory16(_ds, 0x21E) = 0x0000;              //mov word_1041E, 0
    memory16(_ds, 0x3D3) = 0x0000;              //mov word ptr unk_105D3, 0
    memory16(_ds, 0x222) += 0x0006;             //add word_10422, 6
loc_1431B:                                      //loc_1431B:
    goto loc_14289;                             //jmp loc_14289
}

void sub_1431E()
{
    memory(_ds, 0x212A) = 0x01;                 //mov byte_1232A, 1
    sub_14639();                                //call sub_14639
}

void loc_14327()
{
    memory(_ds, 0x212A) = 0x01;                 //mov byte_1232A, 1
    memory(_ds, 0x2127) = 0x01;                 //mov byte_12327, 1
}

void sub_14332()
{
    memory(_ds, 0x64) = 0x00;                   //mov byte_10264, 0
    sub_158F3();                                //call sub_158F3
    _ax = memory16(_ds, 0x267);                 //mov ax, word_10467
    sub_14601();                                //call sub_14601
    if (memory16(_ds, 0x226) != 0x0001)         //jnz short loc_1434A
      goto loc_1434A;
    sub_1431E();                                //call sub_1431E
loc_1434A:                                      //loc_1434A:
    memory16(_ds, 0x226) -= 1;                  //dec word_10426
    _ax = memory16(_ds, 0x228);                 //mov ax, word_10428
    memory16(_ds, 0x224) = _ax;                 //mov word_10424, ax
    if (memory(_ds, 0x22B) == 0x00)             //jz short loc_14360
      goto loc_14360;
    memory(_ds, 0x22B) -= 0x14;                 //sub byte_1042B, 14h
loc_14360:                                      //loc_14360:
    _al = memory(_ds, 0x22C);                   //mov al, byte_1042C
    memory(_ds, 0x22A) = _al;                   //mov byte_1042A, al
    _ax = memory16(_ds, 0x211);                 //mov ax, word_10411
    memory16(_ds, 0x213) = _ax;                 //mov word_10413, ax
    _ax = memory16(_ds, 0x215);                 //mov ax, word_10415
    memory16(_ds, 0x211) = _ax;                 //mov word_10411, ax
    memory(_ds, 0x217) = 0x02;                  //mov byte ptr word_10417, 2
    sub_158F3();                                //call sub_158F3
    _ax = memory16(_ds, 0x21E);                 //mov ax, word_1041E
    memory16(_ds, 0x3D3) = _ax;                 //mov word ptr unk_105D3, ax
    if (_ax == memory16(_ds, 0x218))            //jz short loc_14389
      goto loc_14389;
    sub_143FA();                                //call sub_143FA
loc_14389:                                      //loc_14389:
    _ax = memory16(_ds, 0x269);                 //mov ax, word_10469
    sub_1461B();                                //call sub_1461B
    sub_15DFA();                                //call sub_15DFA
    sub_1444F();                                //call sub_1444F
}

void sub_14396()
{
    memory(_ds, 0x64) = 0x00;                   //mov byte_10264, 0
    sub_158F3();                                //call sub_158F3
    _ax = memory16(_ds, 0x269);                 //mov ax, word_10469
    sub_14601();                                //call sub_14601
    if (memory16(_ds, 0x228) != 0x0001)         //jnz short loc_143AE
      goto loc_143AE;
{loc_14327(); return; };                        //
loc_143AE:                                      //loc_143AE:
    memory16(_ds, 0x228) -= 1;                  //dec word_10428
    _ax = memory16(_ds, 0x226);                 //mov ax, word_10426
    memory16(_ds, 0x224) = _ax;                 //mov word_10424, ax
    if (memory(_ds, 0x22C) == 0x00)             //jz short loc_143C4
      goto loc_143C4;
    memory(_ds, 0x22C) -= 0x14;                 //sub byte_1042C, 14h
loc_143C4:                                      //loc_143C4:
    _al = memory(_ds, 0x22B);                   //mov al, byte_1042B
    memory(_ds, 0x22A) = _al;                   //mov byte_1042A, al
    _ax = memory16(_ds, 0x211);                 //mov ax, word_10411
    memory16(_ds, 0x215) = _ax;                 //mov word_10415, ax
    _ax = memory16(_ds, 0x213);                 //mov ax, word_10413
    memory16(_ds, 0x211) = _ax;                 //mov word_10411, ax
    memory(_ds, 0x217) = 0x01;                  //mov byte ptr word_10417, 1
    sub_158F3();                                //call sub_158F3
    _ax = memory16(_ds, 0x218);                 //mov ax, word_10417+1
    memory16(_ds, 0x3D3) = _ax;                 //mov word ptr unk_105D3, ax
    if (_ax == memory16(_ds, 0x21E))            //jz short loc_143ED
      goto loc_143ED;
    sub_143FA();                                //call sub_143FA
loc_143ED:                                      //loc_143ED:
    _ax = memory16(_ds, 0x267);                 //mov ax, word_10467
    sub_1461B();                                //call sub_1461B
    sub_15DFA();                                //call sub_15DFA
    sub_1444F();                                //call sub_1444F
    return;                                     //retn
    _STOP_("sp-trace-fail");                    //sub_14396 endp_failed
    _STOP_("continues");                        //sub_143FA proc near
}

void sub_143FA()
{
    _bx = memory16(_ds, 0x3D3);                 //mov bx, word ptr unk_105D3
    _ax = memory16(_ds, _bx + 3801);            //mov ax, [bx+0ED9h]
    memory16(_ds, 0x203) = _ax;                 //mov word_10403, ax
    _dx = memory16(_ds, _bx + 985);             //mov dx, [bx+3D9h]
    sub_17F06();                                //call sub_17F06
    _ax = 0xa6d6;                               //mov ax, 0A6D6h
    sub_17F7B();                                //call sub_17F7B
    _bx = memory16(_ds, 0x3D3);                 //mov bx, word ptr unk_105D3
    _dx = memory16(_ds, _bx + 995);             //mov dx, [bx+3E3h]
    sub_17F06();                                //call sub_17F06
    _lea(_si, _ds, 0x110a);                     //lea si, unk_1130A
    sub_180A7();                                //call sub_180A7
    _ax = memory16(_ds, 0x24B);                 //mov ax, word_1044B
    sub_17F7B();                                //call sub_17F7B
    _bx = memory16(_ds, 0x3D3);                 //mov bx, word ptr unk_105D3
    sub_15DB2();                                //call sub_15DB2
    _bx = memory16(_ds, 0x3D3);                 //mov bx, word ptr unk_105D3
    sub_15E6F();                                //call sub_15E6F
    _bx = memory16(_ds, 0x3D3);                 //mov bx, word ptr unk_105D3
    _si = memory16(_ds, _bx + 1015);            //mov si, [bx+3F7h]
    sub_180A7();                                //call sub_180A7
    _es = memory16(_ds, 0x24B);                 //mov es, word_1044B
    _ax = 0x0105;                               //mov ax, 105h
    _dx = 0x03ce;                               //mov dx, 3CEh
    _out(_dx, _ax);                             //out dx, ax
}

void sub_1444F()
{
    _es = memory16(_ds, 0x24B);                 //mov es, word_1044B
    sub_167C7();                                //call sub_167C7
    if (memory(_ds, 0x64F) == 0x02)             //jz short loc_14488
      goto loc_14488;
    sub_1763F();                                //call sub_1763F
    _di = 0x049c;                               //mov di, 49Ch
    sub_1769B();                                //call sub_1769B
    memory16(_ds, 0x107F) = 0x0c6c;             //mov word_1127F, 0C6Ch
    sub_16A4D();                                //call sub_16A4D
    sub_165E5();                                //call sub_165E5
    _di = 0x003c;                               //mov di, 3Ch
    _cx = 0x0005;                               //mov cx, 5
    _dx = 0x0014;                               //mov dx, 14h
    memory16(_ds, 0x107F) = 0x0c6c;             //mov word_1127F, 0C6Ch
    sub_14521();                                //call sub_14521
    sub_172B1();                                //call sub_172B1
    return;                                     //retn
loc_14488:                                      //loc_14488:
    _si = 0xd890;                               //mov si, 0D890h
    _si += 0x0014;                              //add si, 14h
    _di = 0x0000;                               //mov di, 0
    if (memory(_ds, 0x217) != 0x01)             //jnz short loc_1449E
      goto loc_1449E;
    _si += 0x0010;                              //add si, 10h
    _di += 0x003c;                              //add di, 3Ch
loc_1449E:                                      //loc_1449E:
    sub_17680();                                //call sub_17680
    _push(memory16(_ds, 0x217));                //push word_10417
    memory(_ds, 0x217) = 0x01;                  //mov byte ptr word_10417, 1
    _di = 0x0460;                               //mov di, 460h
    sub_1769B();                                //call sub_1769B
    memory(_ds, 0x217) = 0x02;                  //mov byte ptr word_10417, 2
    _di = 0x049c;                               //mov di, 49Ch
    sub_1769B();                                //call sub_1769B
    memory16(_ds, 0x217) = _pop();              //pop word_10417
    _push(memory16(_ds, 0x211));                //push word_10411
    memory16(_ds, 0x107D) = 0xd890;             //mov word_1127D, 0D890h
    memory16(_ds, 0x107F) = 0x0c38;             //mov word_1127F, 0C38h
    _ax = memory16(_ds, 0x213);                 //mov ax, word_10413
    if (memory(_ds, 0x217) != 0x01)             //jnz short loc_144E1
      goto loc_144E1;
    memory16(_ds, 0x107F) += 0x0034;            //add word_1127F, 34h
    _ax = memory16(_ds, 0x215);                 //mov ax, word_10415
loc_144E1:                                      //loc_144E1:
    memory16(_ds, 0x211) = _ax;                 //mov word_10411, ax
    _push(memory16(_ds, 0x211));                //push word_10411
    sub_16A4D();                                //call sub_16A4D
    memory16(_ds, 0x211) = _pop();              //pop word_10411
    sub_176FC();                                //call sub_176FC
    memory16(_ds, 0x211) = _pop();              //pop word_10411
    sub_165E5();                                //call sub_165E5
    _di = 0x0000;                               //mov di, 0
    _cx = 0x00c8;                               //mov cx, 0C8h
    _dx = 0x0014;                               //mov dx, 14h
    memory16(_ds, 0x107F) = 0x0c38;             //mov word_1127F, 0C38h
    if (memory(_ds, 0x217) == 0x01)             //jz short loc_1451A
      goto loc_1451A;
    _di += 0x003c;                              //add di, 3Ch
    _dx += 0x0010;                              //add dx, 10h
    memory16(_ds, 0x107F) += 0x0034;            //add word_1127F, 34h
loc_1451A:                                      //loc_1451A:
    sub_14521();                                //call sub_14521
    sub_172B1();                                //call sub_172B1
}

void sub_14521()
{
loc_14521:
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _si = 0xd890;                               //mov si, 0D890h
    _si += _dx;                                 //add si, dx
    sub_17680();                                //call sub_17680
    memory16(_ds, 0x107D) = 0xd890;             //mov word_1127D, 0D890h
    sub_176FC();                                //call sub_176FC
    memory16(_ds, 0x111E) = 0x0096;             //mov word_1131E, 96h
    sub_17805();                                //call sub_17805
    _di = _pop();                               //pop di
    _push(_di);                                 //push di
    _push(_ax);                                 //push ax
    _si = 0xd660;                               //mov si, 0D660h
    _si += _dx;                                 //add si, dx
    sub_17680();                                //call sub_17680
    memory16(_ds, 0x107D) = 0xd660;             //mov word_1127D, 0D660h
    sub_176FC();                                //call sub_176FC
    _ax = _pop();                               //pop ax
    _di = _pop();                               //pop di
    _cx = _pop();                               //pop cx
    if (memory(_ds, 0x1122) == 0x01)            //jz short locret_1456D
      goto locret_1456D;
    memory16(_ds, 0x111E) = 0x0096;             //mov word_1131E, 96h
    sub_17805();                                //call sub_17805
    if (memory(_ds, 0x1122) == 0x01)            //jz short locret_1456D
      goto locret_1456D;
    if (--_cx)                                  //loop sub_14521
      goto loc_14521;
locret_1456D:                                   //locret_1456D:
    return;
}

void sub_1456E()
{
    _si = memory16(_ds, 0x203);                 //mov si, word_10403
    _lea(_di, _ds, 0x018d);                     //lea di, unk_1038D
    _cx = 0x005c;                               //mov cx, 5Ch
    sub_15DAA();                                //call sub_15DAA
    _lea(_si, _ds, 0x1053);                     //lea si, unk_11253
    _bx = 0xffff;                               //mov bx, 0FFFFh
    sub_15D7C();                                //call sub_15D7C
}

void sub_14587()
{
    if (memory(_ds, 0x5A) >= 0x14)              //jnb short loc_1459B
      goto loc_1459B;
    if (memory(_ds, 0x5A) <= 0x08)              //jbe short loc_1459B
      goto loc_1459B;
    sub_16998();                                //call sub_16998
    goto loc_1459E;                             //jmp short loc_1459E
    _STOP_("db 90h");                           //db 90h
loc_1459B:                                      //loc_1459B:
    sub_16A4D();                                //call sub_16A4D
loc_1459E:                                      //loc_1459E:
    sub_15F62();                                //call sub_15F62
    if (memory(_ds, 0x62) == 0x01)              //jz short locret_14600
      goto locret_14600;
    sub_15ECC();                                //call sub_15ECC
    sub_15FA8();                                //call sub_15FA8
    _bx = 0x0000;                               //mov bx, 0
loc_145B1:                                      //loc_145B1:
    memory16(_ds, 0x207) = _bx;                 //mov word_10407, bx
    if (memory(_ds, _bx + 104) == 0x4d)         //jz short loc_145DE
      goto loc_145DE;
    memory(_ds, _bx + 521) += 1;                //inc byte ptr [bx+209h]
    if (memory(_ds, _bx + 521) != 0x0f)         //jnz short loc_145D5
      goto loc_145D5;
    memory(_ds, _bx + 521) = 0x00;              //mov byte ptr [bx+209h], 0
    sub_16FD3();                                //call sub_16FD3
    sub_15FC4();                                //call sub_15FC4
    sub_15F15();                                //call sub_15F15
loc_145D5:                                      //loc_145D5:
    sub_16FD3();                                //call sub_16FD3
    sub_15FC4();                                //call sub_15FC4
    goto loc_145F7;                             //jmp short loc_145F7
loc_145DE:                                      //loc_145DE:
    memory(_ds, _bx + 525) += 1;                //inc byte ptr [bx+20Dh]
    if (memory(_ds, _bx + 525) != 0x08)         //jnz short loc_145F1
      goto loc_145F1;
    memory(_ds, _bx + 525) = 0x00;              //mov byte ptr [bx+20Dh], 0
    goto loc_145F7;                             //jmp short loc_145F7
    _STOP_("db 90h");                           //db 90h
loc_145F1:                                      //loc_145F1:
    sub_16FD3();                                //call sub_16FD3
    sub_15FC4();                                //call sub_15FC4
loc_145F7:                                      //loc_145F7:
    sub_15F15();                                //call sub_15F15
    _bx += 1;                                   //inc bx
    if (_bx != 0x0004)                          //jnz short loc_145B1
      goto loc_145B1;
locret_14600:                                   //locret_14600:
    return;
}

void sub_14601()
{
    _push(_es);                                 //push es
    _es = _ax;                                  //mov es, ax
    _si = 0x0000;                               //mov si, 0
    _di = 0x0000;                               //mov di, 0
    _cx = 0x0211;                               //mov cx, 211h
    if (_ax != memory16(_ds, 0x261))            //jnz short loc_14616
      goto loc_14616;
    _cx = 0x024b;                               //mov cx, 24Bh
loc_14616:                                      //loc_14616:
    _flags.direction = false;                   //cld
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _es = _pop();                               //pop es
}

void sub_1461B()
{
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _cx = 0x0211;                               //mov cx, 211h
    if (_ax != memory16(_ds, 0x261))            //jnz short loc_14629
      goto loc_14629;
    _cx = 0x024b;                               //mov cx, 24Bh
loc_14629:                                      //loc_14629:
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    _ds = _ax;                                  //mov ds, ax
    _si = 0x0000;                               //mov si, 0
    _di = 0x0000;                               //mov di, 0
    _flags.direction = false;                   //cld
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_14639()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_bp);                                 //push bp
    _push(_es);                                 //push es
    _push(_ds);                                 //push ds
    memory(_ds, 0x2127) = 0x01;                 //mov byte ptr ds:2127h, 1
    sub_158F3();                                //call sub_158F3
    _in(_al, 97);                               //in al, 61h
    _al &= 0xfc;                                //and al, 0FCh
    _out(97, _al);                              //out 61h, al
loc_14650:                                      //loc_14650:
    _es = memory16(_ds, 0x26B);                 //mov es, word ptr ds:26Bh
    _ax = 0xa000;                               //mov ax, 0A000h
    _push(_ds);                                 //push ds
    _ds = _ax;                                  //mov ds, ax
    _si = _si ^ _si;                            //xor si, si
    _di = _di ^ _di;                            //xor di, di
    _dx = 0x03ce;                               //mov dx, 3CEh
    _cx = 0x2000;                               //mov cx, 2000h
loc_14664:                                      //loc_14664:
    _ax = 0x0304;                               //mov ax, 304h
    _out(_dx, _ax);                             //out dx, ax
    _bl = memory(_ds, _si);                     //mov bl, [si]
    memory(_es, _di) = _bl;                     //mov es:[di], bl
    _ah -= 1;                                   //dec ah
    _out(_dx, _ax);                             //out dx, ax
    _bl = memory(_ds, _si);                     //mov bl, [si]
    memory(_es, _di + 1) = _bl;                 //mov es:[di+1], bl
    _ah -= 1;                                   //dec ah
    _out(_dx, _ax);                             //out dx, ax
    _bl = memory(_ds, _si);                     //mov bl, [si]
    memory(_es, _di + 2) = _bl;                 //mov es:[di+2], bl
    _ah -= 1;                                   //dec ah
    _out(_dx, _ax);                             //out dx, ax
    _bl = memory(_ds, _si);                     //mov bl, [si]
    memory(_es, _di + 3) = _bl;                 //mov es:[di+3], bl
    _si += 1;                                   //inc si
    _di += 0x0004;                              //add di, 4
    if (--_cx)                                  //loop loc_14664
      goto loc_14664;
    if (_si > 0x4000)                           //ja short loc_1469C
      goto loc_1469C;
    _si = 0x4000;                               //mov si, 4000h
    _cx = 0x18c0;                               //mov cx, 18C0h
    goto loc_14664;                             //jmp short loc_14664
loc_1469C:                                      //loc_1469C:
    _ds = _pop();                               //pop ds
    memory16(_ds, 0x26B) += 0x0e30;             //add word ptr ds:26Bh, 0E30h
    _ax = 0x0003;                               //mov ax, 3
    _al |= 0x80;                                //or al, 80h
    _interrupt(16);                             //int 10h
    _cx = 0x2000;                               //mov cx, 2000h
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(16);                             //int 10h
    _bl = 0x00;                                 //mov bl, 0
    _ax = 0x1003;                               //mov ax, 1003h
    _interrupt(16);                             //int 10h
    sub_147BA();                                //call sub_147BA
    _es = memory16(_ds, 0x24F);                 //mov es, word ptr ds:24Fh
    if (memory(_ds, 0x212A) != 0x01)            //jnz short loc_146CF
      goto loc_146CF;
    sub_14791();                                //call sub_14791
    sub_153F0();                                //call sub_153F0
    goto loc_146DC;                             //jmp short loc_146DC
    _STOP_("db 90h");                           //db 90h
loc_146CF:                                      //loc_146CF:
    sub_1487F();                                //call sub_1487F
    if (memory(_ds, 0x62) != 0x01)              //jnz short loc_146DC
      goto loc_146DC;
    goto loc_1477A;                             //jmp loc_1477A
loc_146DC:                                      //loc_146DC:
    _ax = 0x0010;                               //mov ax, 10h
    _al |= 0x80;                                //or al, 80h
    _interrupt(16);                             //int 10h
    _lea(_si, _ds, 0x110A);                     //lea si, ds:110Ah
    sub_180A7();                                //call sub_180A7
    memory16(_ds, 0x26B) -= 0x0e30;             //sub word ptr ds:26Bh, 0E30h
    _es = memory16(_ds, 0x26B);                 //mov es, word ptr ds:26Bh
    _ax = 0xa000;                               //mov ax, 0A000h
    _push(_ds);                                 //push ds
    _ds = _ax;                                  //mov ds, ax
    _si = _si ^ _si;                            //xor si, si
    _di = _di ^ _di;                            //xor di, di
    _ax = 0x0005;                               //mov ax, 5
    _dx = 0x03ce;                               //mov dx, 3CEh
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0xff08;                               //mov ax, 0FF08h
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0f00;                               //mov ax, 0F00h
    _out(_dx, _ax);                             //out dx, ax
    _cx = 0x2000;                               //mov cx, 2000h
loc_14710:                                      //loc_14710:
    _ax = 0x0003;                               //mov ax, 3
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0f01;                               //mov ax, 0F01h
    _out(_dx, _ax);                             //out dx, ax
    memory(_ds, _di) = _bl;                     //mov [di], bl
    _ax = 0x0803;                               //mov ax, 803h
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0e01;                               //mov ax, 0E01h
    _out(_dx, _ax);                             //out dx, ax
    _ah = memory(_ds, _di);                     //mov ah, [di]
    _bx = memory16(_es, _si + 2);               //mov bx, es:[si+2]
    memory(_ds, _di) = _bh;                     //mov [di], bh
    _ah = 0x0d;                                 //mov ah, 0Dh
    _out(_dx, _ax);                             //out dx, ax
    _ah = memory(_ds, _di);                     //mov ah, [di]
    memory(_ds, _di) = _bl;                     //mov [di], bl
    _ah = 0x0b;                                 //mov ah, 0Bh
    _out(_dx, _ax);                             //out dx, ax
    _ah = memory(_ds, _di);                     //mov ah, [di]
    _bx = memory16(_es, _si);                   //mov bx, es:[si]
    memory(_ds, _di) = _bh;                     //mov [di], bh
    _ah = 0x07;                                 //mov ah, 7
    _out(_dx, _ax);                             //out dx, ax
    _ah = memory(_ds, _di);                     //mov ah, [di]
    memory(_ds, _di) = _bl;                     //mov [di], bl
    _si += 0x0004;                              //add si, 4
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_14710
      goto loc_14710;
    if (_di > 0x4000)                           //ja short loc_14756
      goto loc_14756;
    _di = 0x4000;                               //mov di, 4000h
    _cx = 0x18c0;                               //mov cx, 18C0h
    goto loc_14710;                             //jmp short loc_14710
loc_14756:                                      //loc_14756:
    _ds = _pop();                               //pop ds
    _bx = memory16(_ds, 0x3D3);                 //mov bx, ds:3D3h
    _si = memory16(_ds, _bx + 1015);            //mov si, [bx+3F7h]
    sub_180A7();                                //call sub_180A7
    _ax = 0x0105;                               //mov ax, 105h
    _dx = 0x03ce;                               //mov dx, 3CEh
    _out(_dx, _ax);                             //out dx, ax
    _es = memory16(_ds, 0x24B);                 //mov es, word ptr ds:24Bh
    if (memory(_ds, 0x2129) != 0x01)            //jnz short loc_1477A
      goto loc_1477A;
    sub_181A3();                                //call sub_181A3
    goto loc_14650;                             //jmp loc_14650
loc_1477A:                                      //loc_1477A:
    sub_158F3();                                //call sub_158F3
    memory(_ds, 0x2127) = 0x00;                 //mov byte ptr ds:2127h, 0
    memory(_ds, 0x212A) = 0x00;                 //mov byte ptr ds:212Ah, 0
    _ds = _pop();                               //pop ds
    _es = _pop();                               //pop es
    _bp = _pop();                               //pop bp
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_14791()
{
    _push(_ax);                                 //push ax
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _es = memory16(_ds, 0x24F);                 //mov es, word ptr ds:24Fh
    _ah = 0x00;                                 //mov ah, 0
    _al = 0x20;                                 //mov al, 20h
    _di = _di ^ _di;                            //xor di, di
    _cx = 0x07d0;                               //mov cx, 7D0h
    if (memory(_ds, 0x212A) != 0x01)            //jnz short loc_147AE
      goto loc_147AE;
    _di = 0x0320;                               //mov di, 320h
    _cx = 0x0640;                               //mov cx, 640h
loc_147AE:                                      //loc_147AE:
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_147AE
      goto loc_147AE;
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _ax = _pop();                               //pop ax
}

void sub_147BA()
{
    _ax = 0x1110;                               //mov ax, 1110h
    _bh = 0x0e;                                 //mov bh, 0Eh
    _bl = 0x01;                                 //mov bl, 1
    _cx = 0x00c6;                               //mov cx, 0C6h
    _dx = 0x0000;                               //mov dx, 0
    _push(_es);                                 //push es
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    _lea(_bp, _ds, 0x2639);                     //lea bp, ds:2639h
    _interrupt(16);                             //int 10h
    _es = _pop();                               //pop es
    _ax = 0x1201;                               //mov ax, 1201h
    _bl = 0x30;                                 //mov bl, 30h
    _interrupt(16);                             //int 10h
    _lea(_si, _ds, 0x1093);                     //lea si, ds:1093h
    sub_180A7();                                //call sub_180A7
    _ax = 0x1103;                               //mov ax, 1103h
    _bl = 0x04;                                 //mov bl, 4
    _interrupt(16);                             //int 10h
}

void sub_147E7()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _es = memory16(_ds, 0x24F);                 //mov es, word ptr ds:24Fh
    if (memory(_ds, 0x212A) == 0x01)            //jz short loc_14805
      goto loc_14805;
    _ax = 0x0020;                               //mov ax, 20h
    _di = 0x0000;                               //mov di, 0
    _cx = 0x0190;                               //mov cx, 190h
loc_147FD:                                      //loc_147FD:
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_147FD
      goto loc_147FD;
loc_14805:                                      //loc_14805:
    _di = 0x000c;                               //mov di, 0Ch
    _ah = 0x08;                                 //mov ah, 8
    _al = 0x0f;                                 //mov al, 0Fh
    _cx = 0x0003;                               //mov cx, 3
loc_1480F:                                      //loc_1480F:
    _push(_cx);                                 //push cx
    _ah += 1;                                   //inc ah
    _cx = 0x000b;                               //mov cx, 0Bh
loc_14815:                                      //loc_14815:
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    _di += 0x0002;                              //add di, 2
    _al += 1;                                   //inc al
    if (--_cx)                                  //loop loc_14815
      goto loc_14815;
    _di += 0x008a;                              //add di, 8Ah
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_1480F
      goto loc_1480F;
    _di = 0x0032;                               //mov di, 32h
    _bx = 0x0000;                               //mov bx, 0
    _al = 0x42;                                 //mov al, 42h
    _cx = 0x0004;                               //mov cx, 4
loc_14831:                                      //loc_14831:
    _push(_cx);                                 //push cx
    _ah = memory(_ds, _bx + 9781);              //mov ah, [bx+2635h]
    _bx += 1;                                   //inc bx
    _cx = 0x0021;                               //mov cx, 21h
loc_1483A:                                      //loc_1483A:
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    _di += 0x0002;                              //add di, 2
    _al += 1;                                   //inc al
    if (--_cx)                                  //loop loc_1483A
      goto loc_1483A;
    _di += 0x005e;                              //add di, 5Eh
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_14831
      goto loc_14831;
    _di = 0x0088;                               //mov di, 88h
    _ah = 0x0e;                                 //mov ah, 0Eh
    _al = 0x30;                                 //mov al, 30h
    _cx = 0x0003;                               //mov cx, 3
loc_14854:                                      //loc_14854:
    _push(_cx);                                 //push cx
    _cx = 0x0006;                               //mov cx, 6
loc_14858:                                      //loc_14858:
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    _di += 0x0002;                              //add di, 2
    _al += 1;                                   //inc al
    if (--_cx)                                  //loop loc_14858
      goto loc_14858;
    _di += 0x0094;                              //add di, 94h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_14854
      goto loc_14854;
    _ax = 0x1003;                               //mov ax, 1003h
    _bl = 0x00;                                 //mov bl, 0
    _interrupt(16);                             //int 10h
    // TODO: parser!
    memoryVideoOr(_es, 0x8D, 0xf0);                  //or byte ptr es:8Dh, 0F0h
    memoryVideoOr(_es, 0x131, 0x90);                 //or byte ptr es:131h, 90h
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_1487F()
{
    memory(_ds, 0x62) = 0x00;                   //mov byte ptr ds:62h, 0
    memory(_ds, 0x2128) = 0x00;                 //mov byte ptr ds:2128h, 0
    memory(_ds, 0x2129) = 0x00;                 //mov byte ptr ds:2129h, 0
    memory(_ds, 0x212A) = 0x00;                 //mov byte ptr ds:212Ah, 0
    sub_14791();                                //call sub_14791
loc_14896:                                      //loc_14896:
    sub_147E7();                                //call sub_147E7
    memory16(_ds, 0x2143) = 0x0140;             //mov word ptr ds:2143h, 140h
    memory16(_ds, 0x2161) = 0x0000;             //mov word ptr ds:2161h, 0
    if (memory(_ds, 0x64E) != 0x01)             //jnz short loc_148B8
      goto loc_148B8;
    memory16(_ds, 0x2143) = 0x0280;             //mov word ptr ds:2143h, 280h
    memory16(_ds, 0x2161) = 0x0004;             //mov word ptr ds:2161h, 4
loc_148B8:                                      //loc_148B8:
    _bx = 0x0000;                               //mov bx, 0
    _cx = 0x0005;                               //mov cx, 5
loc_148BE:                                      //loc_148BE:
    _push(_cx);                                 //push cx
    _ah = 0x07;                                 //mov ah, 7
    if (_bx != 0x0004)                          //jnz short loc_148C8
      goto loc_148C8;
    _ah = 0x04;                                 //mov ah, 4
loc_148C8:                                      //loc_148C8:
    sub_14E74();                                //call sub_14E74
    _si = memory16(_ds, _bx + 8491);            //mov si, [bx+212Bh]
    _di = memory16(_ds, _bx + 8501);            //mov di, [bx+2135h]
    _dx = 0x0000;                               //mov dx, 0
    _cx = memory16(_ds, _bx + 8531);            //mov cx, [bx+2153h]
loc_148DA:                                      //loc_148DA:
    _push(_cx);                                 //push cx
    _ah = 0x04;                                 //mov ah, 4
    if (_bx != 0x0004)                          //jnz short loc_148E4
      goto loc_148E4;
    _ah = 0x01;                                 //mov ah, 1
loc_148E4:                                      //loc_148E4:
    if (_dx == 0x0000)                          //jz short loc_148F1
      goto loc_148F1;
    if (_dx == memory16(_ds, _bx + 8511))       //jz short loc_148F1
      goto loc_148F1;
    _ah = 0x07;                                 //mov ah, 7
loc_148F1:                                      //loc_148F1:
    _cx = 0x000a;                               //mov cx, 0Ah
loc_148F4:                                      //loc_148F4:
    _al = memory(_ds, _si);                     //mov al, [si]
    memoryVideoSet16(_es, _di, _ax);            //mov es:[di], ax
    _si += 1;                                   //inc si
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_148F4
      goto loc_148F4;
    _di += 0x012c;                              //add di, 12Ch
    _dx += 0x0140;                              //add dx, 140h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_148DA
      goto loc_148DA;
    _bx += 0x0002;                              //add bx, 2
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_148BE
      goto loc_148BE;
    _ah = 0x04;                                 //mov ah, 4
    sub_14BFA();                                //call sub_14BFA
    _bx = 0x0004;                               //mov bx, 4
    if (memory(_ds, 0x1449) != 0x01)            //jnz short loc_14922
      goto loc_14922;
    _bx = 0x0000;                               //mov bx, 0
loc_14922:                                      //loc_14922:
    sub_14CE4();                                //call sub_14CE4
loc_14925:                                      //loc_14925:
    sub_181A3();                                //call sub_181A3
    if (_al == 0x00)                            //jz short loc_1492F
      goto loc_1492F;
    goto loc_14AED;                             //jmp loc_14AED
loc_1492F:                                      //loc_1492F:
    if (_ah != 0x48)                            //jnz short loc_14942
      goto loc_14942;
    if (_bx == 0x0002)                          //jz short loc_14945
      goto loc_14945;
loc_14939:                                      //loc_14939:
    _dl = 0x07;                                 //mov dl, 7
    _ax = memory16(_ds, _bx + 8511);            //mov ax, [bx+213Fh]
    goto loc_1499B;                             //jmp short loc_1499B
loc_14942:                                      //loc_14942:
    goto loc_149DA;                             //jmp loc_149DA
loc_14945:                                      //loc_14945:
    if (memory(_ds, 0x2517) >= 0x0e)            //jnb short loc_14966
      goto loc_14966;
    memory(_ds, 0x2517) += 1;                   //inc byte ptr ds:2517h
    _ax = memory16(_ds, 0x2513);                //mov ax, ds:2513h
    _ax -= 0x0006;                              //sub ax, 6
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    memory16(_ds, 0x1120) -= _ax;               //sub ds:1120h, ax
    _ah = 0x01;                                 //mov ah, 1
    sub_14BFA();                                //call sub_14BFA
    goto loc_1498A;                             //jmp short loc_1498A
loc_14966:                                      //loc_14966:
    if (memory16(_ds, 0x2513) <= 0x0007)        //jbe short loc_14925
      goto loc_14925;
    memory(_ds, 0x2517) = 0x01;                 //mov byte ptr ds:2517h, 1
    memory16(_ds, 0x2513) -= 1;                 //dec word ptr ds:2513h
    _cx = memory16(_ds, 0x2513);                //mov cx, ds:2513h
    _cx -= 0x0006;                              //sub cx, 6
    _cx <<= 1;                                  //shl cx, 1
    _cx <<= 1;                                  //shl cx, 1
    memory16(_ds, 0x1120) -= _cx;               //sub ds:1120h, cx
    _ah = 0x01;                                 //mov ah, 1
    sub_14BFA();                                //call sub_14BFA
loc_1498A:                                      //loc_1498A:
    if (memory16(_ds, 0x2513) & 0x0001)         //jnz short loc_14999
      goto loc_14999;
    if (memory(_ds, 0x2517) == 0x08)            //jz short loc_14939
      goto loc_14939;
loc_14999:                                      //loc_14999:
    goto loc_14925;                             //jmp short loc_14925
loc_1499B:                                      //loc_1499B:
    _di = memory16(_ds, _bx + 8501);            //mov di, [bx+2135h]
    _di += _ax;                                 //add di, ax
    _cx = 0x000a;                               //mov cx, 0Ah
    if (_bx != 0x0002)                          //jnz short loc_149AC
      goto loc_149AC;
    _cx = 0x0009;                               //mov cx, 9
loc_149AC:                                      //loc_149AC:
    memoryVideoSet(_es, _di + 1, _dl);          //mov es:[di+1], dl
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_149AC
      goto loc_149AC;
    if (_dl != 0x01)                            //jnz short loc_149BD
      goto loc_149BD;
    goto loc_14922;                             //jmp loc_14922
loc_149BD:                                      //loc_149BD:
    _ax -= 0x0140;                              //sub ax, 140h
    memory16(_ds, _bx + 8541) -= 0x0004;        //sub word ptr [bx+215Dh], 4
    if ((short)_ax >= (short)0x0140)            //jge short loc_149D2
      goto loc_149D2;
    memory16(_ds, _bx + 8541) += 0x0004;        //add word ptr [bx+215Dh], 4
    _ax += 0x0140;                              //add ax, 140h
loc_149D2:                                      //loc_149D2:
    memory16(_ds, _bx + 8511) = _ax;            //mov [bx+213Fh], ax
    _dl = 0x01;                                 //mov dl, 1
    goto loc_1499B;                             //jmp short loc_1499B
loc_149DA:                                      //loc_149DA:
    if (_ah != 0x50)                            //jnz short loc_149ED
      goto loc_149ED;
    if (_bx == 0x0002)                          //jz short loc_149F0
      goto loc_149F0;
loc_149E4:                                      //loc_149E4:
    _dl = 0x07;                                 //mov dl, 7
    _ax = memory16(_ds, _bx + 8511);            //mov ax, [bx+213Fh]
    goto loc_14A47;                             //jmp short loc_14A47
    _STOP_("db 90h");                           //db 90h
loc_149ED:                                      //loc_149ED:
    goto loc_14A7F;                             //jmp loc_14A7F
loc_149F0:                                      //loc_149F0:
    if (memory(_ds, 0x2517) <= 0x01)            //jbe short loc_14A11
      goto loc_14A11;
    memory(_ds, 0x2517) -= 1;                   //dec byte ptr ds:2517h
    _ax = memory16(_ds, 0x2513);                //mov ax, ds:2513h
    _ax -= 0x0006;                              //sub ax, 6
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    memory16(_ds, 0x1120) += _ax;               //add ds:1120h, ax
    _ah = 0x01;                                 //mov ah, 1
    sub_14BFA();                                //call sub_14BFA
    goto loc_14A35;                             //jmp short loc_14A35
    _STOP_("db 90h");                           //db 90h
loc_14A11:                                      //loc_14A11:
    if (memory16(_ds, 0x2513) >= 0x000f)        //jnb short loc_14A44
      goto loc_14A44;
    memory(_ds, 0x2517) = 0x0e;                 //mov byte ptr ds:2517h, 0Eh
    _cx = memory16(_ds, 0x2513);                //mov cx, ds:2513h
    _cx -= 0x0006;                              //sub cx, 6
    _cx <<= 1;                                  //shl cx, 1
    _cx <<= 1;                                  //shl cx, 1
    memory16(_ds, 0x1120) += _cx;               //add ds:1120h, cx
    memory16(_ds, 0x2513) += 1;                 //inc word ptr ds:2513h
    _ah = 0x01;                                 //mov ah, 1
    sub_14BFA();                                //call sub_14BFA
loc_14A35:                                      //loc_14A35:
    if (memory16(_ds, 0x2513) & 0x0001)         //jnz short loc_14A44
      goto loc_14A44;
    if (memory(_ds, 0x2517) == 0x07)            //jz short loc_149E4
      goto loc_149E4;
loc_14A44:                                      //loc_14A44:
    goto loc_14925;                             //jmp loc_14925
loc_14A47:                                      //loc_14A47:
    _di = memory16(_ds, _bx + 8501);            //mov di, [bx+2135h]
    _di += _ax;                                 //add di, ax
    _cx = 0x0009;                               //mov cx, 9
loc_14A50:                                      //loc_14A50:
    memoryVideoSet(_es, _di + 1, _dl);          //mov es:[di+1], dl
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_14A50
      goto loc_14A50;
    if (_dl != 0x01)                            //jnz short loc_14A61
      goto loc_14A61;
    goto loc_14922;                             //jmp loc_14922
loc_14A61:                                      //loc_14A61:
    _ax += 0x0140;                              //add ax, 140h
    memory16(_ds, _bx + 8541) += 0x0004;        //add word ptr [bx+215Dh], 4
    if ((short)_ax <= (short)memory16(_ds, _bx + 8521))
      goto loc_14A77;
    _ax -= 0x0140;                              //sub ax, 140h
    memory16(_ds, _bx + 8541) -= 0x0004;        //sub word ptr [bx+215Dh], 4
loc_14A77:                                      //loc_14A77:
    memory16(_ds, _bx + 8511) = _ax;            //mov [bx+213Fh], ax
    _dl = 0x01;                                 //mov dl, 1
    goto loc_14A47;                             //jmp short loc_14A47
loc_14A7F:                                      //loc_14A7F:
    if (_ah != 0x4b)                            //jnz short loc_14A92
      goto loc_14A92;
    if (_bx == 0x0000)                          //jz short loc_14AEA
      goto loc_14AEA;
    memory16(_ds, 0x26E) = 0xfffe;              //mov word ptr ds:26Eh, 0FFFEh
    goto loc_14AA2;                             //jmp short loc_14AA2
loc_14A92:                                      //loc_14A92:
    if (_ah != 0x4d)                            //jnz short loc_14AEA
      goto loc_14AEA;
    if (_bx == 0x0008)                          //jz short loc_14AEA
      goto loc_14AEA;
    memory16(_ds, 0x26E) = 0x0002;              //mov word ptr ds:26Eh, 2
loc_14AA2:                                      //loc_14AA2:
    _dl = 0x04;                                 //mov dl, 4
    _ah = 0x07;                                 //mov ah, 7
    sub_14E74();                                //call sub_14E74
    if (_bx != 0x0002)                          //jnz short loc_14AB3
      goto loc_14AB3;
    _ah = 0x04;                                 //mov ah, 4
    sub_14BFA();                                //call sub_14BFA
loc_14AB3:                                      //loc_14AB3:
    _di = memory16(_ds, _bx + 8501);            //mov di, [bx+2135h]
    _bp = memory16(_ds, _bx + 8511);            //mov bp, [bx+213Fh]
    _cx = 0x0009;                               //mov cx, 9
loc_14ABE:                                      //loc_14ABE:
    memoryVideoSet(_es, _di + 1, _dl);          //mov es:[di+1], dl
    memoryVideoSet(_es, _bp + _di + 1, _dl);    //mov es:[bp+di+1], dl
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_14ABE
      goto loc_14ABE;
    if (_dl != 0x01)                            //jnz short loc_14AD3
      goto loc_14AD3;
    goto loc_14922;                             //jmp loc_14922
loc_14AD3:                                      //loc_14AD3:
    _dl = 0x01;                                 //mov dl, 1
    _bx = _bx + memory16(_ds, 0x26E);           //add bx, ds:26Eh
    _ah = 0x04;                                 //mov ah, 4
    sub_14E74();                                //call sub_14E74
    if (_bx != 0x0002)                          //jnz short loc_14AB3
      goto loc_14AB3;
    _ah = 0x01;                                 //mov ah, 1
    sub_14BFA();                                //call sub_14BFA
    goto loc_14AB3;                             //jmp short loc_14AB3
loc_14AEA:                                      //loc_14AEA:
    goto loc_14922;                             //jmp loc_14922
loc_14AED:                                      //loc_14AED:
    if (_al != 0x0d)                            //jnz short loc_14B21
      goto loc_14B21;
    sub_14D8C();                                //call sub_14D8C
    if (memory(_ds, 0x31F) != 0x01)             //jnz short loc_14B08
      goto loc_14B08;
    memory(_ds, 0x31F) = 0x00;                  //mov byte ptr ds:31Fh, 0
    memory(_ds, 0x212A) = 0x00;                 //mov byte ptr ds:212Ah, 0
    goto loc_14925;                             //jmp loc_14925
loc_14B08:                                      //loc_14B08:
    if (memory(_ds, 0x212A) != 0x01)            //jnz short loc_14B17
      goto loc_14B17;
    memory(_ds, 0x212A) = 0x00;                 //mov byte ptr ds:212Ah, 0
    goto loc_14896;                             //jmp loc_14896
loc_14B17:                                      //loc_14B17:
    if (memory(_ds, 0x2128) != 0x01)            //jnz short loc_14AEA
      goto loc_14AEA;
    _STOP_("goto nullsub_2");                   //jmp nullsub_2
loc_14B21:                                      //loc_14B21:
    if ((char)_al < (char)0x61)                 //jl short loc_14B27
      goto loc_14B27;
    _al -= 0x20;                                //sub al, 20h
loc_14B27:                                      //loc_14B27:
    _dx = 0x0000;                               //mov dx, 0
    _si = _bx;                                  //mov si, bx
    _si >>= 1;                                  //shr si, 1
    _si += _bx;                                 //add si, bx
    _si += _bx;                                 //add si, bx
    _bp = 0x0140;                               //mov bp, 140h
    _cx = 0x0005;                               //mov cx, 5
loc_14B38:                                      //loc_14B38:
    if (_al == memory(_ds, _si + 8561))         //jz short loc_14B4B
      goto loc_14B4B;
    _si += 1;                                   //inc si
    _dx += 0x0004;                              //add dx, 4
    _bp += 0x0140;                              //add bp, 140h
    if (--_cx)                                  //loop loc_14B38
      goto loc_14B38;
    goto loc_14922;                             //jmp loc_14922
loc_14B4B:                                      //loc_14B4B:
    memory16(_ds, _bx + 8541) = _dx;            //mov [bx+215Dh], dx
    if (_bx != 0x0002)                          //jnz short loc_14B76
      goto loc_14B76;
    memory(_ds, 0x2517) = 0x07;                 //mov byte ptr ds:2517h, 7
    _di = memory16(_ds, _bx + 8541);            //mov di, [bx+215Dh]
    _di >>= 1;                                  //shr di, 1
    memory16(_ds, 0x2513) = 0x0007;             //mov word ptr ds:2513h, 7
    memory16(_ds, 0x2513) += _di;               //add ds:2513h, di
    _di = memory16(_ds, _di + 8551);            //mov di, [di+2167h]
    memory16(_ds, 0x1120) = _di;                //mov ds:1120h, di
    _ah = 0x01;                                 //mov ah, 1
    sub_14BFA();                                //call sub_14BFA
loc_14B76:                                      //loc_14B76:
    sub_14BA3();                                //call sub_14BA3
    _dl = 0x07;                                 //mov dl, 7
    _ax = memory16(_ds, _bx + 8511);            //mov ax, [bx+213Fh]
loc_14B7F:                                      //loc_14B7F:
    _di = memory16(_ds, _bx + 8501);            //mov di, [bx+2135h]
    _di += _ax;                                 //add di, ax
    _cx = 0x0009;                               //mov cx, 9
loc_14B88:                                      //loc_14B88:
    memoryVideoSet(_es, _di + 1, _dl);          //mov es:[di+1], dl
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_14B88
      goto loc_14B88;
    if (_dl != 0x01)                            //jnz short loc_14B99
      goto loc_14B99;
    goto loc_14922;                             //jmp loc_14922
loc_14B99:                                      //loc_14B99:
    _ax = _bp;                                  //mov ax, bp
    memory16(_ds, _bx + 8511) = _bp;            //mov [bx+213Fh], bp
    _dl = 0x01;                                 //mov dl, 1
    goto loc_14B7F;                             //jmp short loc_14B7F
}

void sub_14BA3()
{
    if (_bx != 0x0004)                          //jnz short loc_14BD0
      goto loc_14BD0;
    if (_al != 0x43)                            //jnz short locret_14BF8
      goto locret_14BF8;
    if (memory16(_ds, _bx + 8511) != 0x0280)    //jnz short loc_14BBE
      goto loc_14BBE;
    _bp = 0x03c0;                               //mov bp, 3C0h
    memory16(_ds, _bx + 8541) = 0x0008;         //mov word ptr [bx+215Dh], 8
    return;                                     //retn
loc_14BBE:                                      //loc_14BBE:
    if (memory16(_ds, _bx + 8511) != 0x03c0)    //jnz short locret_14BF8
      goto locret_14BF8;
    _bp = 0x0280;                               //mov bp, 280h
    memory16(_ds, _bx + 8541) = 0x0004;         //mov word ptr [bx+215Dh], 4
    return;                                     //retn
loc_14BD0:                                      //loc_14BD0:
    if (_bx != 0x0008)                          //jnz short locret_14BF8
      goto locret_14BF8;
    if (memory16(_ds, _bx + 8511) != 0x0140)    //jnz short loc_14BE7
      goto loc_14BE7;
    _bp = 0x0280;                               //mov bp, 280h
    memory16(_ds, _bx + 8541) = 0x0004;         //mov word ptr [bx+215Dh], 4
    return;                                     //retn
loc_14BE7:                                      //loc_14BE7:
    if (memory16(_ds, _bx + 8511) != 0x0280)    //jnz short locret_14BF8
      goto locret_14BF8;
    _bp = 0x0140;                               //mov bp, 140h
    memory16(_ds, _bx + 8541) = 0x0000;         //mov word ptr [bx+215Dh], 0
locret_14BF8:                                   //locret_14BF8:
    return;
}

void sub_14BFA()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_es);                                 //push es
    _push(_di);                                 //push di
    _es = memory16(_ds, 0x24F);                 //mov es, word ptr ds:24Fh
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_dx);                                 //push dx
    _dx = memory16(_ds, 0x2513);                //mov dx, ds:2513h
    _dl = -_dl;                                 //neg dl
    _dl += 0x0f;                                //add dl, 0Fh
    _dl <<= 1;                                  //shl dl, 1
    _bl = _dl;                                  //mov bl, dl
    _dl <<= 1;                                  //shl dl, 1
    _dl <<= 1;                                  //shl dl, 1
    _dl <<= 1;                                  //shl dl, 1
    _dl -= _bl;                                 //sub dl, bl
    _dl = _dl + memory(_ds, 0x2517);            //add dl, ds:2517h
    _di = 0x03f4;                               //mov di, 3F4h
    _lea(_bx, _ds, 0x1079);                     //lea bx, ds:1079h
loc_14C25:                                      //loc_14C25:
    _al = 0x00;                                 //mov al, 0
loc_14C27:                                      //loc_14C27:
    if ((short)_dx < (short)memory16(_ds, _bx)) //jl short loc_14C31
      goto loc_14C31;
    _al += 1;                                   //inc al
    _dx = _dx - memory16(_ds, _bx);             //sub dx, [bx]
    goto loc_14C27;                             //jmp short loc_14C27
loc_14C31:                                      //loc_14C31:
    _al += 0x30;                                //add al, 30h
    memoryVideoSet16(_es, _di, _ax);            //mov es:[di], ax
    _di += 0x0002;                              //add di, 2
    _bx += 0x0002;                              //add bx, 2
    _al = 0x0a;                                 //mov al, 0Ah
    if (memory(_ds, _bx + -2) != _al)           //jnz short loc_14C25
      goto loc_14C25;
    _al = _dl;                                  //mov al, dl
    _al += 0x30;                                //add al, 30h
    memoryVideoSet16(_es, _di, _ax);            //mov es:[di], ax
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    _ah += 0x08;                                //add ah, 8
    memory16(_ds, 0x2515) = 0x0000;             //mov word ptr ds:2515h, 0
    if (memory16(_ds, 0x2513) <= 0x000f)        //jbe short loc_14C63
      goto loc_14C63;
    memory16(_ds, 0x2513) = 0x000f;             //mov word ptr ds:2513h, 0Fh
loc_14C63:                                      //loc_14C63:
    if ((short)memory16(_ds, 0x2513) >= (short)0x0007)
      goto loc_14C70;
    memory16(_ds, 0x2513) = 0x0007;             //mov word ptr ds:2513h, 7
loc_14C70:                                      //loc_14C70:
    if ((short)memory16(_ds, 0x2513) <= (short)0x0007)
      goto loc_14C90;
    _cx = memory16(_ds, 0x2513);                //mov cx, ds:2513h
    _cx -= 0x0007;                              //sub cx, 7
    _al = 0x00;                                 //mov al, 0
    _di = 0x0538;                               //mov di, 538h
loc_14C83:                                      //loc_14C83:
    memoryVideoSet16(_es, _di, _ax);            //mov es:[di], ax
    memoryVideoSet16(_es, _di + 2, _ax);        //mov es:[di+2], ax
    _di += 0x00a0;                              //add di, 0A0h
    if (--_cx)                                  //loop loc_14C83
      goto loc_14C83;
loc_14C90:                                      //loc_14C90:
    _cx = memory16(_ds, 0x2513);                //mov cx, ds:2513h
    _cx += 0x0001;                              //add cx, 1
    memory16(_ds, 0x2515) = 0x0000;             //mov word ptr ds:2515h, 0
loc_14C9D:                                      //loc_14C9D:
    memory16(_ds, 0x2515) += 0x00a0;            //add word ptr ds:2515h, 0A0h
    if (--_cx)                                  //loop loc_14C9D
      goto loc_14C9D;
    memory16(_ds, 0x2515) += 0x0038;            //add word ptr ds:2515h, 38h
    _di = memory16(_ds, 0x2515);                //mov di, ds:2515h
    _al = memory(_ds, 0x2517);                  //mov al, ds:2517h
    memoryVideoSet16(_es, _di, _ax);            //mov es:[di], ax
    memoryVideoSet16(_es, _di + 2, _ax);        //mov es:[di+2], ax
    if (memory16(_ds, 0x2513) >= 0x000f)        //jnb short loc_14CDF
      goto loc_14CDF;
    _cx = 0x000f;                               //mov cx, 0Fh
    _cx = _cx - memory16(_ds, 0x2513);          //sub cx, ds:2513h
    _al = 0x0e;                                 //mov al, 0Eh
    memory16(_ds, 0x2515) += 0x00a0;            //add word ptr ds:2515h, 0A0h
    _di = memory16(_ds, 0x2515);                //mov di, ds:2515h
loc_14CD2:                                      //loc_14CD2:
    memoryVideoSet16(_es, _di, _ax);            //mov es:[di], ax
    memoryVideoSet16(_es, _di + 2, _ax);        //mov es:[di+2], ax
    _di += 0x00a0;                              //add di, 0A0h
    if (--_cx)                                  //loop loc_14CD2
      goto loc_14CD2;
loc_14CDF:                                      //loc_14CDF:
    _di = _pop();                               //pop di
    _es = _pop();                               //pop es
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_14CE4()
{
    _ah = 0x04;                                 //mov ah, 4
    _al = 0x20;                                 //mov al, 20h
    _di = 0x0d20;                               //mov di, 0D20h
    _cx = 0x00f0;                               //mov cx, 0F0h
loc_14CEE:                                      //loc_14CEE:
    memoryVideoSet16(_es, _di, _ax);            //mov es:[di], ax
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_14CEE
      goto loc_14CEE;
    _si = memory16(_ds, _bx + 8902);            //mov si, [bx+22C6h]
    if (memory(_ds, 0x64E) != 0x01)             //jnz short loc_14D05
      goto loc_14D05;
    _si = memory16(_ds, _bx + 8892);            //mov si, [bx+22BCh]
loc_14D05:                                      //loc_14D05:
    _si = _si + memory16(_ds, _bx + 8541);      //add si, [bx+215Dh]
    _push(_si);                                 //push si
    _push(_si);                                 //push si
    _push(_si);                                 //push si
    _si = memory16(_ds, _si);                   //mov si, [si]
    _al = memory(_ds, _si);                     //mov al, [si]
    _si = _pop();                               //pop si
    _si += 0x0002;                              //add si, 2
    _si = memory16(_ds, _si);                   //mov si, [si]
    _di = 0x0e10;                               //mov di, 0E10h
    if (_si == 0x0000)                          //jz short loc_14D20
      goto loc_14D20;
    _al = _al + memory(_ds, _si);               //add al, [si]
loc_14D20:                                      //loc_14D20:
    _ah = 0x00;                                 //mov ah, 0
    _di -= _ax;                                 //sub di, ax
    _di >>= 1;                                  //shr di, 1
    _di <<= 1;                                  //shl di, 1
    _push(_di);                                 //push di
    _bp = _ax;                                  //mov bp, ax
    _bp <<= 1;                                  //shl bp, 1
    _ah = 0x01;                                 //mov ah, 1
    _di -= 0x00a2;                              //sub di, 0A2h
    memoryVideoSet(_es, _di + -2, 0xda);        //mov byte ptr es:[di-2], 0DAh
    memoryVideoSet(_es, _di + 158, 0xb3);       //mov byte ptr es:[di+9Eh], 0B3h
    memoryVideoSet(_es, _di + 318, 0xc0);       //mov byte ptr es:[di+13Eh], 0C0h
    memoryVideoSet(_es, _bp + _di + 4, 0xbf);   //mov byte ptr es:[bp+di+4], 0BFh
    memoryVideoSet(_es, _bp + _di + 164, 0xb3); //mov byte ptr es:[bp+di+0A4h], 0B3h
    memoryVideoSet(_es, _bp + _di + 324, 0xd9); //mov byte ptr es:[bp+di+144h], 0D9h
    _bp >>= 1;                                  //shr bp, 1
    _bp += 0x0002;                              //add bp, 2
    _cx = 0x0002;                               //mov cx, 2
loc_14D5D:                                      //loc_14D5D:
    _push(_cx);                                 //push cx
    _cx = _bp;                                  //mov cx, bp
loc_14D60:                                      //loc_14D60:
    memoryVideoSet(_es, _di, 0xc4);             //mov byte ptr es:[di], 0C4h
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_14D60
      goto loc_14D60;
    _di += 0x0140;                              //add di, 140h
    _di -= _bp;                                 //sub di, bp
    _di -= _bp;                                 //sub di, bp
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_14D5D
      goto loc_14D5D;
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _si = memory16(_ds, _si);                   //mov si, [si]
    _si += 1;                                   //inc si
    sub_15C79();                                //call sub_15C79
    _si = _pop();                               //pop si
    _si += 0x0002;                              //add si, 2
    _si = memory16(_ds, _si);                   //mov si, [si]
    if (_si == 0x0000)                          //jz short locret_14D8B
      goto locret_14D8B;
    _si += 1;                                   //inc si
    sub_15C79();                                //call sub_15C79
locret_14D8B:                                   //locret_14D8B:
    return;
}

void sub_14D8C()
{
    if (_bx == 0x0000)                          //jz short loc_14D99
      goto loc_14D99;
    _dx = _bx;                                  //mov dx, bx
    _bx = 0x0004;                               //mov bx, 4
    goto loc_14DF0;                             //jmp short loc_14DF0
    _STOP_("db 90h");                           //db 90h
loc_14D99:                                      //loc_14D99:
    if (memory16(_ds, _bx + 8511) != 0x0140)    //jnz short loc_14DB7
      goto loc_14DB7;
    memory(_ds, 0x212A) = 0x01;                 //mov byte ptr ds:212Ah, 1
    sub_14791();                                //call sub_14791
    _ah = 0x04;                                 //mov ah, 4
    sub_154E6();                                //call sub_154E6
    sub_14791();                                //call sub_14791
    memory(_ds, 0x212A) = 0x01;                 //mov byte ptr ds:212Ah, 1
    return;                                     //retn
loc_14DB7:                                      //loc_14DB7:
    if (memory16(_ds, _bx + 8511) != 0x0280)    //jnz short loc_14DD2
      goto loc_14DD2;
    sub_14EE9();                                //call sub_14EE9
    if (memory(_ds, 0x31F) == 0x01)             //jz short loc_14DCC
      goto loc_14DCC;
    sub_14791();                                //call sub_14791
loc_14DCC:                                      //loc_14DCC:
    memory(_ds, 0x212A) = 0x01;                 //mov byte ptr ds:212Ah, 1
    return;                                     //retn
loc_14DD2:                                      //loc_14DD2:
    if (memory16(_ds, _bx + 8511) != 0x03c0)    //jnz short loc_14DDE
      goto loc_14DDE;
    sub_14FB4();                                //call sub_14FB4
    return;                                     //retn
loc_14DDE:                                      //loc_14DDE:
    if (memory(_ds, 0x64E) != 0x01)             //jnz short locret_14DEF
      goto locret_14DEF;
    memory(_ds, 0x2129) = 0x01;                 //mov byte ptr ds:2129h, 1
    memory(_ds, 0x2128) = 0x01;                 //mov byte ptr ds:2128h, 1
locret_14DEF:                                   //locret_14DEF:
    return;                                     //retn
loc_14DF0:                                      //loc_14DF0:
    if (memory16(_ds, _bx + 8511) != 0x0140)    //jnz short loc_14E09
      goto loc_14E09;
    sub_14E49();                                //call sub_14E49
    memory(_ds, 0x64E) = 0x00;                  //mov byte ptr ds:64Eh, 0
    memory(_ds, 0x63) = 0x01;                   //mov byte ptr ds:63h, 1
    sub_13F3D(0x13FB9);
    return;                                     //retn
loc_14E09:                                      //loc_14E09:
    if (memory16(_ds, _bx + 8511) != 0x0280)    //jnz short loc_14E24
      goto loc_14E24;
    if (memory(_ds, 0x64E) == 0x01)             //jz short loc_14E1B
      goto loc_14E1B;
    _bx = _dx;                                  //mov bx, dx
    return;                                     //retn
loc_14E1B:                                      //loc_14E1B:
    memory(_ds, 0x2128) = 0x01;                 //mov byte ptr ds:2128h, 1
    sub_14E49();                                //call sub_14E49
    return;                                     //retn
loc_14E24:                                      //loc_14E24:
    if (memory16(_ds, _bx + 8511) != 0x03c0)    //jnz short loc_14E30
      goto loc_14E30;
    sub_152C7();                                //call sub_152C7
    return;                                     //retn
loc_14E30:                                      //loc_14E30:
    memory16(_ds, 0x66) = 0x0000;               //mov word ptr ds:66h, 0
    memory(_ds, 0x62) = 0x01;                   //mov byte ptr ds:62h, 1
    memory(_ds, 0x65) = 0x01;                   //mov byte ptr ds:65h, 1
    memory(_ds, 0x2128) = 0x01;                 //mov byte ptr ds:2128h, 1
    _STOP_("goto loc_13FB9");                   //jmp loc_13FB9
}

void sub_14E49()
{
    _bx = 0x0006;                               //mov bx, 6
    memory(_ds, 0x650) = 0x01;                  //mov byte ptr ds:650h, 1
    if (memory16(_ds, _bx + 8511) == 0x0140)    //jz short loc_14E5E
      goto loc_14E5E;
    memory(_ds, 0x650) = 0x02;                  //mov byte ptr ds:650h, 2
loc_14E5E:                                      //loc_14E5E:
    _bx = 0x0008;                               //mov bx, 8
    memory(_ds, 0x5A7) = 0x01;                  //mov byte ptr ds:5A7h, 1
    if (memory16(_ds, _bx + 8511) == 0x0140)    //jz short locret_14E73
      goto locret_14E73;
    memory(_ds, 0x5A7) = 0x00;                  //mov byte ptr ds:5A7h, 0
locret_14E73:                                   //locret_14E73:
    return;
}

void sub_14E74()
{
    _lea(_si, _ds, 0x2266);                     //lea si, ds:2266h
    if (_ah != 0x04)                            //jnz short loc_14E81
      goto loc_14E81;
    _lea(_si, _ds, 0x2291);                     //lea si, ds:2291h
loc_14E81:                                      //loc_14E81:
    _di = memory16(_ds, _bx + 8501);            //mov di, [bx+2135h]
    _di -= 0x00a4;                              //sub di, 0A4h
    _cx = 0x000e;                               //mov cx, 0Eh
loc_14E8C:                                      //loc_14E8C:
    _al = memory(_ds, _si);                     //mov al, [si]
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    _si += 1;                                   //inc si
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_14E8C
      goto loc_14E8C;
    _di += 0x0084;                              //add di, 84h
    _al = memory(_ds, _si + 28);                //mov al, [si+1Ch]
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    _di += 0x001a;                              //add di, 1Ah
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    _di += 0x0086;                              //add di, 86h
    _cx = 0x000e;                               //mov cx, 0Eh
loc_14EAE:                                      //loc_14EAE:
    _al = memory(_ds, _si);                     //mov al, [si]
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    _si += 1;                                   //inc si
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_14EAE
      goto loc_14EAE;
    _al = memory(_ds, _si + 14);                //mov al, [si+0Eh]
    _cx = memory16(_ds, _bx + 8531);            //mov cx, [bx+2153h]
    _cx -= 1;                                   //dec cx
    _cx <<= 1;                                  //shl cx, 1
    _cx -= 1;                                   //dec cx
    _di -= 0x0002;                              //sub di, 2
loc_14EC7:                                      //loc_14EC7:
    _di += 0x0086;                              //add di, 86h
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    _di += 0x001a;                              //add di, 1Ah
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    if (--_cx)                                  //loop loc_14EC7
      goto loc_14EC7;
    _di += 0x0086;                              //add di, 86h
    _cx = 0x000e;                               //mov cx, 0Eh
loc_14EDD:                                      //loc_14EDD:
    _al = memory(_ds, _si);                     //mov al, [si]
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    _si += 1;                                   //inc si
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_14EDD
      goto loc_14EDD;
}

void sub_14EE9()
{
    _lea(_dx, _ds, 0x2FF);                      //lea dx, ds:2FFh
    sub_17F06();                                //call sub_17F06
    if (memory(_ds, 0x31F) == 0x00)             //jz short loc_14EFF
      goto loc_14EFF;
    _lea(_si, _ds, 0x13B0);                     //lea si, ds:13B0h
    sub_15666();                                //call sub_15666
    return;                                     //retn
loc_14EFF:                                      //loc_14EFF:
    _si = _si ^ _si;                            //xor si, si
    _di = _di ^ _di;                            //xor di, di
    sub_14F52();                                //call sub_14F52
loc_14F06:                                      //loc_14F06:
    sub_181A3();                                //call sub_181A3
    if (_al == 0x1b)                            //jz short loc_14F11
      goto loc_14F11;
    if (_al != 0x0d)                            //jnz short loc_14F16
      goto loc_14F16;
loc_14F11:                                      //loc_14F11:
    _es = memory16(_ds, 0x24F);                 //mov es, word ptr ds:24Fh
    return;                                     //retn
loc_14F16:                                      //loc_14F16:
    if (_al != 0x00)                            //jnz short loc_14F06
      goto loc_14F06;
    if (_ah != 0x48)                            //jnz short loc_14F22
      goto loc_14F22;
    goto loc_14F2A;                             //jmp short loc_14F2A
loc_14F22:                                      //loc_14F22:
    if (_ah != 0x50)                            //jnz short loc_14F06
      goto loc_14F06;
    goto loc_14F47;                             //jmp short loc_14F47
loc_14F2A:                                      //loc_14F2A:
    if (_bx == 0x0000)                          //jz short loc_14F06
      goto loc_14F06;
    _si = _bx;                                  //mov si, bx
    _cx = 0x001a;                               //mov cx, 1Ah
loc_14F34:                                      //loc_14F34:
    _si -= 1;                                   //dec si
    if (_si == 0)                               //jz short loc_14F42
      goto loc_14F42;
    if (memory(_es, _si) != 0x0d)               //jnz short loc_14F34
      goto loc_14F34;
    if (--_cx)                                  //loop loc_14F34
      goto loc_14F34;
    _si += 0x0002;                              //add si, 2
loc_14F42:                                      //loc_14F42:
    sub_14F52();                                //call sub_14F52
    goto loc_14F06;                             //jmp short loc_14F06
loc_14F47:                                      //loc_14F47:
    if (memory(_es, _si) == 0x1a)               //jz short loc_14F06
      goto loc_14F06;
    sub_14F52();                                //call sub_14F52
    goto loc_14F06;                             //jmp short loc_14F06
}

void sub_14F52()
{
    _es = memory16(_ds, 0x24F);                 //mov es, word ptr ds:24Fh
    sub_14791();                                //call sub_14791
    _ah = 0x04;                                 //mov ah, 4
    _bx = _si;                                  //mov bx, si
    _cx = 0x0019;                               //mov cx, 19h
loc_14F60:                                      //loc_14F60:
    _push(_di);                                 //push di
loc_14F61:                                      //loc_14F61:
    _es = memory16(_ds, 0x26B);                 //mov es, word ptr ds:26Bh
    _al = memory(_es, _si);                     //mov al, es:[si]
    _si += 1;                                   //inc si
    if (_al == 0x0d)                            //jz short loc_14F79
      goto loc_14F79;
    _es = memory16(_ds, 0x24F);                 //mov es, word ptr ds:24Fh
    memory16(_es, _di) = _ax;                   //mov es:[di], ax
    _di += 0x0002;                              //add di, 2
    goto loc_14F61;                             //jmp short loc_14F61
loc_14F79:                                      //loc_14F79:
    _si += 1;                                   //inc si
    _di = _pop();                               //pop di
    _di += 0x00a0;                              //add di, 0A0h
    if (--_cx)                                  //loop loc_14F60
      goto loc_14F60;
    _lea(_di, _ds, 0x13D4);                     //lea di, ds:13D4h
    if (_bx == 0x0000)                          //jz short loc_14F98
      goto loc_14F98;
    _lea(_di, _ds, 0x13FA);                     //lea di, ds:13FAh
    if (memory(_es, _si) != 0x1a)               //jnz short loc_14F98
      goto loc_14F98;
    _lea(_di, _ds, 0x1423);                     //lea di, ds:1423h
loc_14F98:                                      //loc_14F98:
    _push(_si);                                 //push si
    _si = _di;                                  //mov si, di
    _es = memory16(_ds, 0x24F);                 //mov es, word ptr ds:24Fh
    sub_15666();                                //call sub_15666
    _es = memory16(_ds, 0x26B);                 //mov es, word ptr ds:26Bh
    _si = _pop();                               //pop si
    _di = _di ^ _di;                            //xor di, di
    _push(_bx);                                 //push bx
    _push(_dx);                                 //push dx
    _dx = 0x1a00;                               //mov dx, 1A00h
    sub_158EC();                                //call sub_158EC
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
}

void sub_14FB4()
{
    if (memory(_ds, 0x64E) != 0x01)             //jnz short loc_14FCD
      goto loc_14FCD;
    _lea(_si, _ds, 0x1178);                     //lea si, ds:1178h
    sub_15666();                                //call sub_15666
    _di = 0x082c;                               //mov di, 82Ch
    sub_1514D();                                //call sub_1514D
    if (_al == 0x59)                            //jz short loc_14FCD
      goto loc_14FCD;
    return;                                     //retn
loc_14FCD:                                      //loc_14FCD:
    _al = memory(_ds, 0x254);                   //mov al, ds:254h
    memory(_ds, 0x255) = _al;                   //mov ds:255h, al
    memory(_ds, 0x254) = 0x00;                  //mov byte ptr ds:254h, 0
loc_14FD8:                                      //loc_14FD8:
    memory16(_ds, 0x310D) = 0x0000;             //mov word ptr ds:310Dh, 0
    _lea(_dx, _ds, 0x249);                      //lea dx, ds:249h
loc_14FE2:                                      //loc_14FE2:
    sub_150E5();                                //call sub_150E5
    if (memory(_ds, 0x249) != 0x0d)             //jnz short loc_14FE2
      goto loc_14FE2;
    memory16(_ds, 0x111B) = 0x3039;             //mov word ptr ds:111Bh, 3039h
    memory(_ds, 0x111D) = 0x00;                 //mov byte ptr ds:111Dh, 0
    memory(_ds, 0x1449) = 0x01;                 //mov byte ptr ds:1449h, 1
    memory16(_ds, 0x2145) = 0x0140;             //mov word ptr ds:2145h, 140h
    memory16(_ds, 0x2163) = 0x0000;             //mov word ptr ds:2163h, 0
    sub_14E49();                                //call sub_14E49
    memory16(_ds, 0x2143) = 0x0140;             //mov word ptr ds:2143h, 140h
    memory16(_ds, 0x2161) = 0x0000;             //mov word ptr ds:2161h, 0
    _bx = 0x0004;                               //mov bx, 4
{sub_14D8C(); return; };                        //
}

void loc_1501E()
{
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
loc_15021:                                      //loc_15021:
    memory(_ds, 0x1449) = 0x00;                 //mov byte ptr ds:1449h, 0
    sub_175F8();                                //call sub_175F8
    memory(_ds, 0x144A) = 0x01;                 //mov byte ptr ds:144Ah, 1
    sub_17885();                                //call sub_17885
    memory(_ds, 0x144A) = 0x00;                 //mov byte ptr ds:144Ah, 0
    if (_ax == 0xffff)                          //jz short loc_15052
      goto loc_15052;
    sub_15079();                                //call sub_15079
    memory16(_ds, 0x66) = 0x0000;               //mov word ptr ds:66h, 0
    memory(_ds, 0x62) = 0x01;                   //mov byte ptr ds:62h, 1
    memory(_ds, 0x246) = 0x01;                  //mov byte ptr ds:246h, 1
    _ax = 0xffff;                               //mov ax, 0FFFFh
    return;                                     //retn
loc_15052:                                      //loc_15052:
    _STOP_("goto loc_14FD8");                   //jmp short loc_14FD8
    _STOP_("db 80h, 3Eh, 49h, 14h, 1, 74h, 0C3h, 0C6h,...");
    _STOP_("db 1, 8Dh, 16h, 0Fh, 31h, 0B4h, 3Ch, 0B1h,...");
    _STOP_("db 0A3h, 1Bh, 3, 0C7h, 6, 1Bh, 11h, 39h, 3...");
    _STOP_("db 1Dh, 11h, 0, 0C3h");             //db 1Dh, 11h, 0, 0C3h
}

void sub_15079()
{
    memory(_ds, 0x1449) = 0x00;                 //mov byte ptr ds:1449h, 0
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _bx = memory16(_ds, 0x31B);                 //mov bx, ds:31Bh
    _ah = 0x3e;                                 //mov ah, 3Eh
    _interrupt(33);                             //int 21h
    memory16(_ds, 0x144B) = 0x0000;             //mov word ptr ds:144Bh, 0
    _al = memory(_ds, 0x255);                   //mov al, ds:255h
    memory(_ds, 0x254) = _al;                   //mov ds:254h, al
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_15097()
{
    if (_ax == 0xffff)                          //jz short loc_150B3
      goto loc_150B3;
    sub_15079();                                //call sub_15079
    memory16(_ds, 0x66) = 0x0000;               //mov word ptr ds:66h, 0
    memory(_ds, 0x62) = 0x01;                   //mov byte ptr ds:62h, 1
    memory(_ds, 0x246) = 0x01;                  //mov byte ptr ds:246h, 1
    _ax = 0xffff;                               //mov ax, 0FFFFh
    return;                                     //retn
loc_150B3:                                      //loc_150B3:
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    if (memory16(_ds, 0x247) != 0x0000)         //jnz short loc_150D3
      goto loc_150D3;
    _lea(_dx, _ds, 0x249);                      //lea dx, ds:249h
    sub_150E5();                                //call sub_150E5
    _ax = memory16(_ds, 0x249);                 //mov ax, ds:249h
    if (_ax != 0xffff)                          //jnz short loc_150DA
      goto loc_150DA;
    _lea(_dx, _ds, 0x247);                      //lea dx, ds:247h
    sub_150E5();                                //call sub_150E5
loc_150D3:                                      //loc_150D3:
    memory16(_ds, 0x247) -= 1;                  //dec word ptr ds:247h
    _ax = 0xffff;                               //mov ax, 0FFFFh
loc_150DA:                                      //loc_150DA:
    if (_al != 0x1b)                            //jnz short loc_150E1
      goto loc_150E1;
{loc_1501E(); return; };                        //
loc_150E1:                                      //loc_150E1:
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    return;                                     //retn
    _STOP_("sp-trace-fail");                    //sub_15097 endp_failed
    _STOP_("continues");                        //sub_150E5 proc near
}

void sub_150E5()
{
    _push(_si);                                 //push si
    _push(_bx);                                 //push bx
    _bx = _dx;                                  //mov bx, dx
    _si = memory16(_ds, 0x310D);                //mov si, ds:310Dh
    memory16(_ds, 0x310D) += 0x0002;            //add word ptr ds:310Dh, 2
    _ax = memory16(_ds, _si + 12559);           //mov ax, [si+310Fh]
    memory16(_ds, _bx) = _ax;                   //mov [bx], ax
    _bx = _pop();                               //pop bx
    _si = _pop();                               //pop si
}

void loc_15118()
{
    memory16(_ds, 0x247) = _ax;                 //mov ds:247h, ax
    _lea(_dx, _ds, 0x247);                      //lea dx, ds:247h
    sub_1513F();                                //call sub_1513F
    memory16(_ds, 0x247) = 0x0000;              //mov word ptr ds:247h, 0
    goto loc_1513B;                             //jmp short loc_1513B
    _STOP_("db 90h");                           //db 90h
loc_1512B:                                      //loc_1512B:
    memory16(_ds, 0x247) += 1;                  //inc word ptr ds:247h
    _ASSERT(0);
//    if (_FIXME_)                                //jnb short loc_1513B
//      goto loc_1513B;
    _lea(_dx, _ds, 0x249);                      //lea dx, ds:249h
    sub_1513F();                                //call sub_1513F
    sub_1513F();                                //call sub_1513F
loc_1513B:                                      //loc_1513B:
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
}

void sub_1513F()
{
    _push(_ax);                                 //push ax
    _ah = 0x40;                                 //mov ah, 40h
    _bx = memory16(_ds, 0x31B);                 //mov bx, ds:31Bh
    _cx = 0x0002;                               //mov cx, 2
    _interrupt(33);                             //int 21h
    _ax = _pop();                               //pop ax
}

void sub_1514D()
{
    memory16(_ds, 0x26E) = _di;                 //mov ds:26Eh, di
    _si = 0x0000;                               //mov si, 0
    _cx = 0x0004;                               //mov cx, 4
loc_15157:                                      //loc_15157:
    _push(_cx);                                 //push cx
    _cx = 0x0007;                               //mov cx, 7
loc_1515B:                                      //loc_1515B:
    _ax = memory16(_es, _di);                   //mov ax, es:[di]
    memory16(_ds, _si + 4388) = _ax;            //mov [si+1124h], ax
    _si += 0x0002;                              //add si, 2
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_1515B
      goto loc_1515B;
    _di += 0x0092;                              //add di, 92h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_15157
      goto loc_15157;
    _ah = 0x04;                                 //mov ah, 4
    _si = 0x0000;                               //mov si, 0
    _di = memory16(_ds, 0x26E);                 //mov di, ds:26Eh
    _cx = 0x0004;                               //mov cx, 4
loc_1517D:                                      //loc_1517D:
    _push(_cx);                                 //push cx
    _cx = 0x0007;                               //mov cx, 7
loc_15181:                                      //loc_15181:
    _al = memory(_ds, _si + 4444);              //mov al, [si+115Ch]
    memory16(_es, _di) = _ax;                   //mov es:[di], ax
    _si += 1;                                   //inc si
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_15181
      goto loc_15181;
    _di += 0x0092;                              //add di, 92h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_1517D
      goto loc_1517D;
    _ah = 0x01;                                 //mov ah, 1
    _di = memory16(_ds, 0x26E);                 //mov di, ds:26Eh
    memory(_es, _di + 165) = _ah;               //mov es:[di+0A5h], ah
    memory(_es, _di + 167) = _ah;               //mov es:[di+0A7h], ah
    memory(_es, _di + 169) = _ah;               //mov es:[di+0A9h], ah
loc_151AA:                                      //loc_151AA:
    sub_181A3();                                //call sub_181A3
    if (_al == 0x00)                            //jz short loc_151CB
      goto loc_151CB;
    if (_al == 0x1b)                            //jz short loc_15214
      goto loc_15214;
    if (_al == 0x0d)                            //jz short loc_15219
      goto loc_15219;
    if (_al == 0x59)                            //jz short loc_151D7
      goto loc_151D7;
    if (_al == 0x79)                            //jz short loc_151D7
      goto loc_151D7;
    if (_al == 0x4e)                            //jz short loc_151E6
      goto loc_151E6;
    if (_al == 0x6e)                            //jz short loc_151E6
      goto loc_151E6;
    goto loc_151AA;                             //jmp short loc_151AA
loc_151CB:                                      //loc_151CB:
    if (_ah == 0x48)                            //jz short loc_151D7
      goto loc_151D7;
    if (_ah == 0x50)                            //jz short loc_151E6
      goto loc_151E6;
    goto loc_151AA;                             //jmp short loc_151AA
loc_151D7:                                      //loc_151D7:
    if (memory(_ds, 0x1123) == 0x59)            //jz short loc_151AA
      goto loc_151AA;
    memory(_ds, 0x1123) = 0x59;                 //mov byte ptr ds:1123h, 59h
    goto loc_151F2;                             //jmp short loc_151F2
loc_151E6:                                      //loc_151E6:
    if (memory(_ds, 0x1123) == 0x4e)            //jz short loc_151AA
      goto loc_151AA;
    memory(_ds, 0x1123) = 0x4e;                 //mov byte ptr ds:1123h, 4Eh
loc_151F2:                                      //loc_151F2:
    _di = memory16(_ds, 0x26E);                 //mov di, ds:26Eh
    _cx = 0x0003;                               //mov cx, 3
loc_151F9:                                      //loc_151F9:
    _ah = memory(_es, _di + 165);               //mov ah, es:[di+0A5h]
    _al = memory(_es, _di + 325);               //mov al, es:[di+145h]
    memory(_es, _di + 165) = _al;               //mov es:[di+0A5h], al
    memory(_es, _di + 325) = _ah;               //mov es:[di+145h], ah
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_151F9
      goto loc_151F9;
    goto loc_151AA;                             //jmp short loc_151AA
loc_15214:                                      //loc_15214:
    memory(_ds, 0x1123) = 0x45;                 //mov byte ptr ds:1123h, 45h
loc_15219:                                      //loc_15219:
    _al = memory(_ds, 0x1123);                  //mov al, ds:1123h
    _push(_ax);                                 //push ax
    memory(_ds, 0x1123) = 0x59;                 //mov byte ptr ds:1123h, 59h
    _si = 0x0000;                               //mov si, 0
    _di = memory16(_ds, 0x26E);                 //mov di, ds:26Eh
    _cx = 0x0004;                               //mov cx, 4
loc_1522C:                                      //loc_1522C:
    _push(_cx);                                 //push cx
    _cx = 0x0007;                               //mov cx, 7
loc_15230:                                      //loc_15230:
    _ax = memory16(_ds, _si + 4388);            //mov ax, [si+1124h]
    memory16(_es, _di) = _ax;                   //mov es:[di], ax
    _si += 0x0002;                              //add si, 2
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_15230
      goto loc_15230;
    _di += 0x0092;                              //add di, 92h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_1522C
      goto loc_1522C;
    _ax = _pop();                               //pop ax
}

void sub_15248()
{
    if (_al != 0x45)                            //jnz short loc_1524D
      goto loc_1524D;
    return;                                     //retn
loc_1524D:                                      //loc_1524D:
    if (_al != 0x4b)                            //jnz short loc_1525C
      goto loc_1525C;
    memory(_ds, 0x254) = 0x00;                  //mov byte ptr ds:254h, 0
    memory(_ds, 0x11C1) = 0x4b;                 //mov byte ptr ds:11C1h, 4Bh
    return;                                     //retn
loc_1525C:                                      //loc_1525C:
    _dx = 0x0201;                               //mov dx, 201h
    _al = 0x00;                                 //mov al, 0
    _out(_dx, _al);                             //out dx, al
    _cx = 0x2710;                               //mov cx, 2710h
loc_15265:                                      //loc_15265:
    _in(_al, _dx);                              //in al, dx
    if (--_cx)                                  //loop loc_15265
      goto loc_15265;
    if (_al != 0xff)                            //jnz short loc_15288
      goto loc_15288;
    _lea(_si, _ds, 0x12E9);                     //lea si, ds:12E9h
    sub_15666();                                //call sub_15666
    _di = 0x0af4;                               //mov di, 0AF4h
    sub_1514D();                                //call sub_1514D
    if (_al == 0x59)                            //jz short loc_15288
      goto loc_15288;
loc_1527D:                                      //loc_1527D:
    memory(_ds, 0x254) = 0x00;                  //mov byte ptr ds:254h, 0
    memory(_ds, 0x11C1) = 0x4b;                 //mov byte ptr ds:11C1h, 4Bh
    return;                                     //retn
loc_15288:                                      //loc_15288:
    _lea(_si, _ds, 0x132A);                     //lea si, ds:132Ah
    sub_15666();                                //call sub_15666
loc_1528F:                                      //loc_1528F:
    sub_181A3();                                //call sub_181A3
    if (_al == 0x1b)                            //jz short loc_1527D
      goto loc_1527D;
    if (_al != 0x0d)                            //jnz short loc_1528F
      goto loc_1528F;
    _ax = _ax ^ _ax;                            //xor ax, ax
    _ah += 1;                                   //inc ah
    sub_152B4();                                //call sub_152B4
    memory16(_ds, 0x257) = _cx;                 //mov ds:257h, cx
    _ah += 1;                                   //inc ah
    sub_152B4();                                //call sub_152B4
    memory16(_ds, 0x259) = _cx;                 //mov ds:259h, cx
    memory(_ds, 0x254) = 0x01;                  //mov byte ptr ds:254h, 1
}

void sub_152B4()
{
    _dx = 0x0201;                               //mov dx, 201h
    _cx = 0x0400;                               //mov cx, 400h
loc_152BA:                                      //loc_152BA:
    if (--_cx)                                  //loop loc_152BA
      goto loc_152BA;
    _al = 0x00;                                 //mov al, 0
    _out(_dx, _al);                             //out dx, al
loc_152BF:                                      //loc_152BF:
    _in(_al, _dx);                              //in al, dx
    if (--_cx && _ah & _al)                     //loopne loc_152BF
      goto loc_152BF;
    _cx = -_cx;                                 //neg cx
}

void sub_152C7()
{
    _al = memory(_ds, 0x11C1);                  //mov al, ds:11C1h
    memory(_ds, 0x11C2) = _al;                  //mov ds:11C2h, al
    _di = memory16(_ds, 0x11BF);                //mov di, ds:11BFh
    _si = 0x0000;                               //mov si, 0
    _cx = 0x0007;                               //mov cx, 7
loc_152D7:                                      //loc_152D7:
    _push(_cx);                                 //push cx
    _cx = 0x000e;                               //mov cx, 0Eh
loc_152DB:                                      //loc_152DB:
    _ax = memory16(_es, _di);                   //mov ax, es:[di]
    memory16(_ds, _si + 4547) = _ax;            //mov [si+11C3h], ax
    _si += 0x0002;                              //add si, 2
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_152DB
      goto loc_152DB;
    _di += 0x0084;                              //add di, 84h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_152D7
      goto loc_152D7;
    _si = 0x0000;                               //mov si, 0
    _di = memory16(_ds, 0x11BF);                //mov di, ds:11BFh
    _cx = 0x0007;                               //mov cx, 7
loc_152FB:                                      //loc_152FB:
    _push(_cx);                                 //push cx
    _cx = 0x000e;                               //mov cx, 0Eh
loc_152FF:                                      //loc_152FF:
    _al = memory(_ds, _si + 4743);              //mov al, [si+1287h]
    _ah = 0x04;                                 //mov ah, 4
    if (_al > 0x7b)                             //ja short loc_1530B
      goto loc_1530B;
    _ah = 0x01;                                 //mov ah, 1
loc_1530B:                                      //loc_1530B:
    memory16(_es, _di) = _ax;                   //mov es:[di], ax
    _si += 1;                                   //inc si
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_152FF
      goto loc_152FF;
    _di += 0x0084;                              //add di, 84h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_152FB
      goto loc_152FB;
    _cx = 0x0008;                               //mov cx, 8
    _di = memory16(_ds, 0x11BF);                //mov di, ds:11BFh
    _di += 0x01e7;                              //add di, 1E7h
    if (memory(_ds, 0x11C1) == 0x4a)            //jz short loc_15331
      goto loc_15331;
    _di += 0x0140;                              //add di, 140h
loc_15331:                                      //loc_15331:
    memory(_es, _di) = _ah;                     //mov es:[di], ah
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_15331
      goto loc_15331;
    _lea(_si, _ds, 0x1360);                     //lea si, ds:1360h
    sub_15666();                                //call sub_15666
loc_15340:                                      //loc_15340:
    sub_181A3();                                //call sub_181A3
    if (_al == 0x00)                            //jz short loc_15361
      goto loc_15361;
    if (_al == 0x1b)                            //jz short loc_153B8
      goto loc_153B8;
    if (_al == 0x0d)                            //jz short loc_153C3
      goto loc_153C3;
    if (_al == 0x4b)                            //jz short loc_1536D
      goto loc_1536D;
    if (_al == 0x6b)                            //jz short loc_1536D
      goto loc_1536D;
    if (_al == 0x4a)                            //jz short loc_15383
      goto loc_15383;
    if (_al == 0x6a)                            //jz short loc_15383
      goto loc_15383;
    goto loc_15340;                             //jmp short loc_15340
loc_15361:                                      //loc_15361:
    if (_ah == 0x48)                            //jz short loc_1536D
      goto loc_1536D;
    if (_ah == 0x50)                            //jz short loc_15383
      goto loc_15383;
    goto loc_15340;                             //jmp short loc_15340
loc_1536D:                                      //loc_1536D:
    if (memory(_ds, 0x11C1) == 0x4b)            //jz short loc_15340
      goto loc_15340;
    memory(_ds, 0x11C1) = 0x4b;                 //mov byte ptr ds:11C1h, 4Bh
    _lea(_si, _ds, 0x1360);                     //lea si, ds:1360h
    sub_15666();                                //call sub_15666
    goto loc_15396;                             //jmp short loc_15396
    _STOP_("db 90h");                           //db 90h
loc_15383:                                      //loc_15383:
    if (memory(_ds, 0x11C1) == 0x4a)            //jz short loc_15340
      goto loc_15340;
    memory(_ds, 0x11C1) = 0x4a;                 //mov byte ptr ds:11C1h, 4Ah
    _lea(_si, _ds, 0x1388);                     //lea si, ds:1388h
    sub_15666();                                //call sub_15666
loc_15396:                                      //loc_15396:
    _di = memory16(_ds, 0x11BF);                //mov di, ds:11BFh
    _cx = 0x0008;                               //mov cx, 8
loc_1539D:                                      //loc_1539D:
    _ah = memory(_es, _di + 487);               //mov ah, es:[di+1E7h]
    _al = memory(_es, _di + 807);               //mov al, es:[di+327h]
    memory(_es, _di + 487) = _al;               //mov es:[di+1E7h], al
    memory(_es, _di + 807) = _ah;               //mov es:[di+327h], ah
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_1539D
      goto loc_1539D;
    goto loc_15340;                             //jmp short loc_15340
loc_153B8:                                      //loc_153B8:
    _al = memory(_ds, 0x11C2);                  //mov al, ds:11C2h
    memory(_ds, 0x11C1) = _al;                  //mov ds:11C1h, al
    _al = 0x45;                                 //mov al, 45h
    goto loc_153C6;                             //jmp short loc_153C6
    _STOP_("db 90h");                           //db 90h
loc_153C3:                                      //loc_153C3:
    _al = memory(_ds, 0x11C1);                  //mov al, ds:11C1h
loc_153C6:                                      //loc_153C6:
    _push(_ax);                                 //push ax
    sub_15248();                                //call sub_15248
    _si = 0x0000;                               //mov si, 0
    _di = memory16(_ds, 0x11BF);                //mov di, ds:11BFh
    _cx = 0x0007;                               //mov cx, 7
loc_153D4:                                      //loc_153D4:
    _push(_cx);                                 //push cx
    _cx = 0x000e;                               //mov cx, 0Eh
loc_153D8:                                      //loc_153D8:
    _ax = memory16(_ds, _si + 4547);            //mov ax, [si+11C3h]
    memory16(_es, _di) = _ax;                   //mov es:[di], ax
    _si += 0x0002;                              //add si, 2
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_153D8
      goto loc_153D8;
    _di += 0x0084;                              //add di, 84h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_153D4
      goto loc_153D4;
    _ax = _pop();                               //pop ax
}

void sub_153F0()
{
    memory(_ds, 0x212A) = 0x00;                 //mov byte ptr ds:212Ah, 0
    memory(_ds, 0x2120) = 0x08;                 //mov byte ptr ds:2120h, 8
    memory16(_ds, 0x211E) = 0x0500;             //mov word ptr ds:211Eh, 500h
    _ax = memory16(_ds, 0x211);                 //mov ax, ds:211h
    _bx = 0x0000;                               //mov bx, 0
loc_15406:                                      //loc_15406:
    if ((short)_ax <= (short)memory16(_ds, _bx + 6712))
      goto loc_1540F;
    goto loc_15496;                             //jmp loc_15496
loc_1540F:                                      //loc_1540F:
    memory(_ds, 0x2120) += 1;                   //inc byte ptr ds:2120h
    memory16(_ds, 0x211E) += 0x00a0;            //add word ptr ds:211Eh, 0A0h
    _bx += 0x0002;                              //add bx, 2
    if (_bx != 0x0014)                          //jnz short loc_15406
      goto loc_15406;
    if (memory(_ds, 0x64F) == 0x02)             //jz short loc_15442
      goto loc_15442;
    memory(_ds, 0x1A36) = 0x01;                 //mov byte ptr ds:1A36h, 1
    memory(_ds, 0x1E98) = 0x20;                 //mov byte ptr ds:1E98h, 20h
    memory(_ds, 0x1E99) = 0x20;                 //mov byte ptr ds:1E99h, 20h
    _lea(_di, _ds, 0x1EC3);                     //lea di, ds:1EC3h
    _lea(_bp, _ds, 0x194E);                     //lea bp, ds:194Eh
    goto loc_1547F;                             //jmp short loc_1547F
loc_15442:                                      //loc_15442:
    memory(_ds, 0x1A36) = 0x02;                 //mov byte ptr ds:1A36h, 2
    if (memory(_ds, 0x217) == 0x02)             //jz short loc_15468
      goto loc_15468;
    memory(_ds, 0x1A37) = 0x01;                 //mov byte ptr ds:1A37h, 1
    memory(_ds, 0x1EE2) = 0x20;                 //mov byte ptr ds:1EE2h, 20h
    memory(_ds, 0x1EE3) = 0x20;                 //mov byte ptr ds:1EE3h, 20h
    _lea(_di, _ds, 0x1F0D);                     //lea di, ds:1F0Dh
    _lea(_bp, _ds, 0x1983);                     //lea bp, ds:1983h
    goto loc_1547F;                             //jmp short loc_1547F
loc_15468:                                      //loc_15468:
    memory(_ds, 0x1A37) = 0x00;                 //mov byte ptr ds:1A37h, 0
    memory(_ds, 0x1F2C) = 0x20;                 //mov byte ptr ds:1F2Ch, 20h
    memory(_ds, 0x1F2D) = 0x20;                 //mov byte ptr ds:1F2Dh, 20h
    _lea(_di, _ds, 0x1F57);                     //lea di, ds:1F57h
    _lea(_bp, _ds, 0x19B8);                     //lea bp, ds:19B8h
loc_1547F:                                      //loc_1547F:
    memory(_ds, 0x1A33) = 0x01;                 //mov byte ptr ds:1A33h, 1
    memory16(_ds, 0x1A34) = 0x0064;             //mov word ptr ds:1A34h, 64h
    sub_156E7();                                //call sub_156E7
    _ah = 0x04;                                 //mov ah, 4
    sub_154E6();                                //call sub_154E6
    sub_180E0();                                //call sub_180E0
    return;                                     //retn
loc_15496:                                      //loc_15496:
    memory(_ds, 0x1A33) = 0x00;                 //mov byte ptr ds:1A33h, 0
    sub_15697();                                //call sub_15697
    sub_159B3();                                //call sub_159B3
    sub_14791();                                //call sub_14791
    _ah = 0x04;                                 //mov ah, 4
    sub_154E6();                                //call sub_154E6
}

void sub_154AA()
{
    sub_147E7();                                //call sub_147E7
    _lea(_si, _ds, 0x1A4E);                     //lea si, ds:1A4Eh
    _di = 0x0288;                               //mov di, 288h
    sub_15C79();                                //call sub_15C79
    _lea(_si, _ds, 0x1E96);                     //lea si, ds:1E96h
    if (memory(_ds, 0x1A36) == 0x01)            //jz short loc_154D4
      goto loc_154D4;
    _lea(_si, _ds, 0x1EE0);                     //lea si, ds:1EE0h
    if (memory(_ds, 0x1A37) == 0x01)            //jz short loc_154D4
      goto loc_154D4;
    sub_15C79();                                //call sub_15C79
    _lea(_si, _ds, 0x1F2A);                     //lea si, ds:1F2Ah
loc_154D4:                                      //loc_154D4:
    sub_15C79();                                //call sub_15C79
    _lea(_si, _ds, 0x1F74);                     //lea si, ds:1F74h
    sub_15C79();                                //call sub_15C79
    _lea(_si, _ds, 0x24FE);                     //lea si, ds:24FEh
    sub_1564C();                                //call sub_1564C
}

void sub_154E6()
{
    _bh = _ah;                                  //mov bh, ah
loc_154E8:                                      //loc_154E8:
    _ah = _bh;                                  //mov ah, bh
    sub_154AA();                                //call sub_154AA
    memory(_ds, 0x212A) = 0x01;                 //mov byte ptr ds:212Ah, 1
    _lea(_si, _ds, 0x209C);                     //lea si, ds:209Ch
    sub_15666();                                //call sub_15666
    sub_1556B();                                //call sub_1556B
    if (_al == 0x00)                            //jz short locret_1556A
      goto locret_1556A;
    if (_al != 0x20)                            //jnz short locret_1556A
      goto locret_1556A;
    _push(_bx);                                 //push bx
    sub_15B67();                                //call sub_15B67
    sub_155C9();                                //call sub_155C9
    _bx = _pop();                               //pop bx
    _ah = _bh;                                  //mov ah, bh
    _lea(_si, _ds, 0x14C5);                     //lea si, ds:14C5h
    _di = 0x0008;                               //mov di, 8
    sub_15C79();                                //call sub_15C79
    _lea(_si, _ds, 0x170E);                     //lea si, ds:170Eh
    _di = 0x0532;                               //mov di, 532h
    sub_15C79();                                //call sub_15C79
    _lea(_si, _ds, 0x194B);                     //lea si, ds:194Bh
    if (memory(_ds, 0x1A36) == 0x01)            //jz short loc_1553F
      goto loc_1553F;
    _lea(_si, _ds, 0x1980);                     //lea si, ds:1980h
    if (memory(_ds, 0x1A37) == 0x01)            //jz short loc_1553F
      goto loc_1553F;
    sub_15C79();                                //call sub_15C79
    _lea(_si, _ds, 0x19B5);                     //lea si, ds:19B5h
loc_1553F:                                      //loc_1553F:
    sub_15C79();                                //call sub_15C79
    _lea(_si, _ds, 0x19EA);                     //lea si, ds:19EAh
    sub_15C79();                                //call sub_15C79
    _lea(_si, _ds, 0x2508);                     //lea si, ds:2508h
    sub_1564C();                                //call sub_1564C
    _lea(_si, _ds, 0x20DE);                     //lea si, ds:20DEh
    sub_15666();                                //call sub_15666
    sub_1556B();                                //call sub_1556B
    memory(_ds, 0x212A) = 0x00;                 //mov byte ptr ds:212Ah, 0
    if (_al == 0x00)                            //jz short locret_1556A
      goto locret_1556A;
    if (_al != 0x20)                            //jnz short locret_1556A
      goto locret_1556A;
    goto loc_154E8;                             //jmp loc_154E8
locret_1556A:                                   //locret_1556A:
    return;
}

void sub_1556B()
{
loc_1556B:
    _push(_bx);                                 //push bx
    _bl = 0x02;                                 //mov bl, 2
    memory(_ds, 0x2512) += 1;                   //inc byte ptr ds:2512h
    memory(_ds, 0x2512) &= 0x3f;                //and byte ptr ds:2512h, 3Fh
    memory(_ds, 0x2512) |= 0x38;                //or byte ptr ds:2512h, 38h
    if (memory(_ds, 0x2512) != 0x38)            //jnz short loc_15587
      goto loc_15587;
    memory(_ds, 0x2512) += 1;                   //inc byte ptr ds:2512h
loc_15587:                                      //loc_15587:
    _bh = memory(_ds, 0x2512);                  //mov bh, ds:2512h
    _ax = 0x1000;                               //mov ax, 1000h
    _interrupt(16);                             //int 10h
    _bx = _pop();                               //pop bx
    _push(memory16(_ds, 0x1120));               //push word ptr ds:1120h
    _push(memory16(_ds, 0x401));                //push word ptr ds:401h
    memory16(_ds, 0x1120) = _pop();             //pop word ptr ds:1120h
    memory16(_ds, 0x111E) = 0x01f4;             //mov word ptr ds:111Eh, 1F4h
    sub_17805();                                //call sub_17805
    memory16(_ds, 0x1120) = _pop();             //pop word ptr ds:1120h
    if (memory(_ds, 0x1122) == 0x00)            //jz short sub_1556B
      goto loc_1556B;
    if (memory(_ds, 0x256) == 0x00)             //jz short loc_155C5
      goto loc_155C5;
    if (_al == 0x0d)                            //jz short locret_155C8
      goto locret_155C8;
    if (_al != 0x1b)                            //jnz short sub_1556B
      goto loc_1556B;
    _al = 0x20;                                 //mov al, 20h
    goto locret_155C8;                          //jmp short locret_155C8
    _STOP_("db 90h");                           //db 90h
loc_155C5:                                      //loc_155C5:
    sub_180E0();                                //call sub_180E0
locret_155C8:                                   //locret_155C8:
    return;
}

void sub_155C9()
{
    _push(_bx);                                 //push bx
    _lea(_bp, _ds, 0x1A1F);                     //lea bp, ds:1A1Fh
    _lea(_di, _ds, 0x1525);                     //lea di, ds:1525h
    sub_155E2();                                //call sub_155E2
    _lea(_bp, _ds, 0x1A29);                     //lea bp, ds:1A29h
    _lea(_di, _ds, 0x156E);                     //lea di, ds:156Eh
    sub_155E2();                                //call sub_155E2
    _bx = _pop();                               //pop bx
}

void sub_155E2()
{
    _bx = _bx ^ _bx;                            //xor bx, bx
    _si = _si ^ _si;                            //xor si, si
    memory(_ds, 0x1456) = 0x00;                 //mov byte ptr ds:1456h, 0
loc_155EB:                                      //loc_155EB:
    _cx = memory16(_ds, _bx + 5207);            //mov cx, [bx+1457h]
    _bx += _bp;                                 //add bx, bp
    _dx = memory16(_ds, _bx);                   //mov dx, [bx]
    _bx -= _bp;                                 //sub bx, bp
    if (_dx != 0x0000)                          //jnz short loc_1560F
      goto loc_1560F;
    if (memory(_ds, 0x1456) == 0x01)            //jz short loc_1560F
      goto loc_1560F;
    _si = _si + memory16(_ds, _bx + 5207);      //add si, [bx+1457h]
    _al = 0x20;                                 //mov al, 20h
loc_15607:                                      //loc_15607:
    memory(_ds, _di) = _al;                     //mov [di], al
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_15607
      goto loc_15607;
    goto loc_15643;                             //jmp short loc_15643
    _STOP_("db 90h");                           //db 90h
loc_1560F:                                      //loc_1560F:
    _push(_bx);                                 //push bx
    memory(_ds, 0x1456) = 0x01;                 //mov byte ptr ds:1456h, 1
    _ax = memory16(_ds, _bx + 5223);            //mov ax, [bx+1467h]
    _lea(_bx, _ds, 0x1075);                     //lea bx, ds:1075h
    _bx += _ax;                                 //add bx, ax
    _ah = 0x04;                                 //mov ah, 4
    _push(_dx);                                 //push dx
    sub_15C46();                                //call sub_15C46
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
    _cx = _cx - memory16(_ds, _bx + 5215);      //sub cx, [bx+145Fh]
    _si = _si + memory16(_ds, _bx + 5215);      //add si, [bx+145Fh]
    _di += 1;                                   //inc di
loc_15630:                                      //loc_15630:
    _al = memory(_ds, _si + 5274);              //mov al, [si+149Ah]
    if (_dx != 0x0001)                          //jnz short loc_1563D
      goto loc_1563D;
    _al = memory(_ds, _si + 5231);              //mov al, [si+146Fh]
loc_1563D:                                      //loc_1563D:
    memory(_ds, _di) = _al;                     //mov [di], al
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_15630
      goto loc_15630;
loc_15643:                                      //loc_15643:
    _bx += 0x0002;                              //add bx, 2
    if (_bx != 0x0008)                          //jnz short loc_155EB
      goto loc_155EB;
}

void sub_1564C()
{
    _ah = 0x02;                                 //mov ah, 2
    _di = 0x05a2;                               //mov di, 5A2h
    _cx = 0x000a;                               //mov cx, 0Ah
loc_15654:                                      //loc_15654:
    _al = memory(_ds, _si);                     //mov al, [si]
    memory16(_es, _di) = _ax;                   //mov es:[di], ax
    memory16(_es, _di + 154) = _ax;             //mov es:[di+9Ah], ax
    _si += 1;                                   //inc si
    _di += 0x00a0;                              //add di, 0A0h
    if (--_cx)                                  //loop loc_15654
      goto loc_15654;
}

void sub_15666()
{
    _ah = 0x04;                                 //mov ah, 4
    _al = 0x20;                                 //mov al, 20h
    _cx = 0x00f0;                               //mov cx, 0F0h
    _di = 0x0dc0;                               //mov di, 0DC0h
    _bp = 0x0eb0;                               //mov bp, 0EB0h
    if (_si >= 0x13d4)                          //jnb short loc_1567F
      goto loc_1567F;
    _di = 0x0d20;                               //mov di, 0D20h
    _bp = 0x0e10;                               //mov bp, 0E10h
loc_1567F:                                      //loc_1567F:
    memory16(_es, _di) = _ax;                   //mov es:[di], ax
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_1567F
      goto loc_1567F;
    sub_1568B();                                //call sub_1568B
}

void sub_1568B()
{
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _si += 0x0002;                              //add si, 2
    _push(_si);                                 //push si
    _push(_si);                                 //push si
    _di = _bp;                                  //mov di, bp
    _STOP_("goto loc_14D20");                   //jmp loc_14D20
}

void sub_15697()
{
    _push(_bx);                                 //push bx
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    _lea(_si, _ds, 0x1A4A);                     //lea si, ds:1A4Ah
    _di = _si;                                  //mov di, si
    _di += 0x0002;                              //add di, 2
    _cx = 0x000a;                               //mov cx, 0Ah
    _bx >>= 1;                                  //shr bx, 1
    _cx -= _bx;                                 //sub cx, bx
    _flags.direction = true;                    //std
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    memory16(_ds, _di) = _ax;                   //mov [di], ax
    _lea(_si, _ds, 0x1DC2);                     //lea si, ds:1DC2h
    _di = _si;                                  //mov di, si
    _di += 0x0049;                              //add di, 49h
    _cx = 0x0009;                               //mov cx, 9
    _cx -= _bx;                                 //sub cx, bx
    if (_cx == 0x0000)                          //jz short loc_156D6
      goto loc_156D6;
loc_156C2:                                      //loc_156C2:
    _push(_cx);                                 //push cx
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _cx = 0x003f;                               //mov cx, 3Fh
    _flags.direction = false;                   //cld
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _si -= 0x0049;                              //sub si, 49h
    _di -= 0x0049;                              //sub di, 49h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_156C2
      goto loc_156C2;
loc_156D6:                                      //loc_156D6:
    memory16(_ds, 0x211C) = _di;                //mov ds:211Ch, di
    _dl = 0x20;                                 //mov dl, 20h
    _cx = 0x0022;                               //mov cx, 22h
loc_156DF:                                      //loc_156DF:
    memory(_ds, _di) = _dl;                     //mov [di], dl
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_156DF
      goto loc_156DF;
    _di += 0x0003;                              //add di, 3
    _STOP_("sp-trace-fail");                    //sub_15697 endp_failed
    _STOP_("continues");                        //sub_156E7 proc near
}

void sub_156E7()
{
    _dx = _ax;                                  //mov dx, ax
    _lea(_bx, _ds, 0x1075);                     //lea bx, ds:1075h
loc_156ED:                                      //loc_156ED:
    _al = 0x00;                                 //mov al, 0
loc_156EF:                                      //loc_156EF:
    if ((short)_dx < (short)memory16(_ds, _bx)) //jl short loc_156F9
      goto loc_156F9;
    _al += 1;                                   //inc al
    _dx = _dx - memory16(_ds, _bx);             //sub dx, [bx]
    goto loc_156EF;                             //jmp short loc_156EF
loc_156F9:                                      //loc_156F9:
    _al += 0x30;                                //add al, 30h
    memory(_ds, _di) = _al;                     //mov [di], al
    _di += 1;                                   //inc di
    _bx += 0x0002;                              //add bx, 2
    _al = 0x0a;                                 //mov al, 0Ah
    if (memory(_ds, _bx + -2) != _al)           //jnz short loc_156ED
      goto loc_156ED;
    _al = _dl;                                  //mov al, dl
    _al += 0x30;                                //add al, 30h
    memory(_ds, _di) = _al;                     //mov [di], al
    _di += 0x0005;                              //add di, 5
    sub_15CB2();                                //call sub_15CB2
    _al = _cl;                                  //mov al, cl
    sub_15C9A();                                //call sub_15C9A
    _al = _dh;                                  //mov al, dh
    sub_15C9A();                                //call sub_15C9A
    _al = _dl;                                  //mov al, dl
    sub_15C9A();                                //call sub_15C9A
    sub_15CC3();                                //call sub_15CC3
    _di += 0x0002;                              //add di, 2
    _al = _ch;                                  //mov al, ch
    sub_15C9A();                                //call sub_15C9A
    _al = _cl;                                  //mov al, cl
    sub_15C9A();                                //call sub_15C9A
    if (memory(_ds, 0x1A33) != 0x01)            //jnz short loc_1573D
      goto loc_1573D;
    _STOP_("goto loc_159E4");                   //jmp loc_159E4
loc_1573D:                                      //loc_1573D:
    _es = memory16(_ds, 0x24F);                 //mov es, word ptr ds:24Fh
    _ah = 0x07;                                 //mov ah, 7
    sub_154AA();                                //call sub_154AA
    _di = memory16(_ds, 0x211E);                //mov di, ds:211Eh
    memory(_es, _di + 13) = 0x05;               //mov byte ptr es:[di+0Dh], 5
    memory(_es, _di + 15) = 0x05;               //mov byte ptr es:[di+0Fh], 5
    _di += 0x0019;                              //add di, 19h
    _cx = 0x0022;                               //mov cx, 22h
loc_1575A:                                      //loc_1575A:
    memory(_es, _di) = 0x04;                    //mov byte ptr es:[di], 4
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_1575A
      goto loc_1575A;
    _di += 0x0006;                              //add di, 6
    _cx = 0x0006;                               //mov cx, 6
loc_15769:                                      //loc_15769:
    memory(_es, _di) = 0x05;                    //mov byte ptr es:[di], 5
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_15769
      goto loc_15769;
    _di += 0x0006;                              //add di, 6
    _cx = 0x0008;                               //mov cx, 8
loc_15778:                                      //loc_15778:
    memory(_es, _di) = 0x04;                    //mov byte ptr es:[di], 4
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_15778
      goto loc_15778;
    _di += 0x0006;                              //add di, 6
    _cx = 0x0005;                               //mov cx, 5
loc_15787:                                      //loc_15787:
    memory(_es, _di) = 0x04;                    //mov byte ptr es:[di], 4
    _di += 0x0002;                              //add di, 2
    if (--_cx)                                  //loop loc_15787
      goto loc_15787;
    _lea(_si, _ds, 0x1FBE);                     //lea si, ds:1FBEh
    if (memory(_ds, 0x64F) == 0x01)             //jz short loc_157AA
      goto loc_157AA;
    _lea(_si, _ds, 0x1FE2);                     //lea si, ds:1FE2h
    if (memory(_ds, 0x217) == 0x01)             //jz short loc_157AA
      goto loc_157AA;
    _lea(_si, _ds, 0x2011);                     //lea si, ds:2011h
loc_157AA:                                      //loc_157AA:
    sub_15666();                                //call sub_15666
    _si = 0x0000;                               //mov si, 0
    _di = memory16(_ds, 0x211C);                //mov di, ds:211Ch
    _dh = memory(_ds, 0x2120);                  //mov dh, ds:2120h
    _dl = 0x0c;                                 //mov dl, 0Ch
    sub_158EC();                                //call sub_158EC
    _cx = 0x0607;                               //mov cx, 607h
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(16);                             //int 10h
loc_157C4:                                      //loc_157C4:
    sub_181A3();                                //call sub_181A3
    if (_al == 0x0d)                            //jz short loc_1582C
      goto loc_1582C;
    if (_al == 0x09)                            //jz short loc_1580D
      goto loc_1580D;
    if (_al == 0x08)                            //jz short loc_157DF
      goto loc_157DF;
    if (_al == 0x00)                            //jz short loc_157DA
      goto loc_157DA;
    goto loc_158BD;                             //jmp loc_158BD
loc_157DA:                                      //loc_157DA:
    if (_ah != 0x53)                            //jnz short loc_157C4
      goto loc_157C4;
loc_157DF:                                      //loc_157DF:
    _al = 0x20;                                 //mov al, 20h
    if (_dl == memory(_ds, _si + 8481))         //jz short loc_15806
      goto loc_15806;
    if (_dl != memory(_ds, _si + 8484))         //jnz short loc_157F1
      goto loc_157F1;
    if (memory(_ds, _di) != _al)                //jnz short loc_15806
      goto loc_15806;
loc_157F1:                                      //loc_157F1:
    _di -= 1;                                   //dec di
    _dl -= 1;                                   //dec dl
    if (_dl == 0x3c)                            //jz short loc_157F1
      goto loc_157F1;
    if (_dl == 0x3f)                            //jz short loc_157F1
      goto loc_157F1;
    if (_dl == 0x47)                            //jz short loc_157F1
      goto loc_157F1;
    sub_158EC();                                //call sub_158EC
loc_15806:                                      //loc_15806:
    memory(_ds, _di) = _al;                     //mov [di], al
    sub_158E0();                                //call sub_158E0
    goto loc_157C4;                             //jmp short loc_157C4
loc_1580D:                                      //loc_1580D:
    _si += 1;                                   //inc si
    if (_si != 0x0003)                          //jnz short loc_15816
      goto loc_15816;
    _si = 0x0000;                               //mov si, 0
loc_15816:                                      //loc_15816:
    _dl = memory(_ds, _si + 8481);              //mov dl, [si+2121h]
    sub_158EC();                                //call sub_158EC
    _push(_dx);                                 //push dx
    _dh = 0x00;                                 //mov dh, 0
    _di = memory16(_ds, 0x211C);                //mov di, ds:211Ch
    _dx -= 0x000c;                              //sub dx, 0Ch
    _di += _dx;                                 //add di, dx
    _dx = _pop();                               //pop dx
    goto loc_157C4;                             //jmp short loc_157C4
loc_1582C:                                      //loc_1582C:
    _cx = 0x2000;                               //mov cx, 2000h
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(16);                             //int 10h
    _si = memory16(_ds, 0x211C);                //mov si, ds:211Ch
    _si += 0x0025;                              //add si, 25h
    _cx = 0x0019;                               //mov cx, 19h
    memory(_ds, 0x1A36) = 0x01;                 //mov byte ptr ds:1A36h, 1
    _lea(_di, _ds, 0x1EC3);                     //lea di, ds:1EC3h
    if (memory(_ds, 0x64F) == 0x01)             //jz short loc_1586B
      goto loc_1586B;
    memory(_ds, 0x1A37) = 0x00;                 //mov byte ptr ds:1A37h, 0
    memory(_ds, 0x1A36) = 0x02;                 //mov byte ptr ds:1A36h, 2
    _lea(_di, _ds, 0x1F57);                     //lea di, ds:1F57h
    if (memory(_ds, 0x217) == 0x02)             //jz short loc_1586B
      goto loc_1586B;
    memory(_ds, 0x1A37) = 0x01;                 //mov byte ptr ds:1A37h, 1
    _lea(_di, _ds, 0x1F0D);                     //lea di, ds:1F0Dh
loc_1586B:                                      //loc_1586B:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    memory16(_ds, _di) = _ax;                   //mov [di], ax
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_1586B
      goto loc_1586B;
    _dx = _pop();                               //pop dx
    _push(_dx);                                 //push dx
    _dx >>= 1;                                  //shr dx, 1
    _dx += 0x0001;                              //add dx, 1
    _lea(_bx, _ds, 0x107B);                     //lea bx, ds:107Bh
    _di -= 0x0044;                              //sub di, 44h
    if (memory(_ds, 0x217) == 0x01)             //jz short loc_158B4
      goto loc_158B4;
    if (_dx > memory16(_ds, 0x1A34))            //ja short loc_158B4
      goto loc_158B4;
    if (memory16(_ds, 0x1A34) != 0x000a)        //jnz short loc_158A2
      goto loc_158A2;
    memory(_ds, 0x1EE2) = 0x20;                 //mov byte ptr ds:1EE2h, 20h
    memory(_ds, 0x1EE3) = 0x20;                 //mov byte ptr ds:1EE3h, 20h
    goto loc_158B4;                             //jmp short loc_158B4
loc_158A2:                                      //loc_158A2:
    _push(_dx);                                 //push dx
    _push(_bx);                                 //push bx
    _push(_di);                                 //push di
    _dx = memory16(_ds, 0x1A34);                //mov dx, ds:1A34h
    _dx += 1;                                   //inc dx
    _lea(_di, _ds, 0x1EE2);                     //lea di, ds:1EE2h
    sub_15C46();                                //call sub_15C46
    _di = _pop();                               //pop di
    _bx = _pop();                               //pop bx
    _dx = _pop();                               //pop dx
loc_158B4:                                      //loc_158B4:
    memory16(_ds, 0x1A34) = _dx;                //mov ds:1A34h, dx
    sub_15C46();                                //call sub_15C46
    _bx = _pop();                               //pop bx
    return;                                     //retn
loc_158BD:                                      //loc_158BD:
    memory(_ds, _di) = _al;                     //mov [di], al
    sub_158E0();                                //call sub_158E0
    if (_dl == memory(_ds, _si + 8484))         //jz short loc_158DD
      goto loc_158DD;
loc_158C8:                                      //loc_158C8:
    _di += 1;                                   //inc di
    _dl += 1;                                   //inc dl
    if (_dl == 0x3c)                            //jz short loc_158C8
      goto loc_158C8;
    if (_dl == 0x3f)                            //jz short loc_158C8
      goto loc_158C8;
    if (_dl == 0x47)                            //jz short loc_158C8
      goto loc_158C8;
    sub_158EC();                                //call sub_158EC
loc_158DD:                                      //loc_158DD:
    goto loc_157C4;                             //jmp loc_157C4
    _STOP_("sp-trace-fail");                    //sub_156E7 endp_failed
    _STOP_("continues");                        //sub_158E0 proc near
}

void sub_158E0()
{
    _ah = 0x09;                                 //mov ah, 9
    _bh = 0x00;                                 //mov bh, 0
    _bl = 0x04;                                 //mov bl, 4
    _cx = 0x0001;                               //mov cx, 1
    _interrupt(16);                             //int 10h
}

void sub_158EC()
{
    _ah = 0x02;                                 //mov ah, 2
    _bh = 0x00;                                 //mov bh, 0
    _interrupt(16);                             //int 10h
}

void sub_158F3()
{
    if (memory(_ds, 0x22D) == 0x01)             //jz short loc_1590F
      goto loc_1590F;
    memory(_ds, 0x22D) = 0x01;                  //mov byte ptr ds:22Dh, 1
    sub_15CC3();                                //call sub_15CC3
    memory(_ds, 0x230) = _ch;                   //mov ds:230h, ch
    memory(_ds, 0x231) = _cl;                   //mov ds:231h, cl
    memory(_ds, 0x232) = _dh;                   //mov ds:232h, dh
    return;                                     //retn
loc_1590F:                                      //loc_1590F:
    memory(_ds, 0x22D) = 0x00;                  //mov byte ptr ds:22Dh, 0
    memory16(_ds, 0x22E) = 0x0000;              //mov word ptr ds:22Eh, 0
    sub_15CC3();                                //call sub_15CC3
    if (_dh >= memory(_ds, 0x232))              //jnb short loc_15933
      goto loc_15933;
    memory(_ds, 0x22E) = 0x01;                  //mov byte ptr ds:22Eh, 1
    _al = 0x3c;                                 //mov al, 3Ch
    _al = _al - memory(_ds, 0x232);             //sub al, ds:232h
    _dh += _al;                                 //add dh, al
    goto loc_15937;                             //jmp short loc_15937
    _STOP_("db 90h");                           //db 90h
loc_15933:                                      //loc_15933:
    _dh = _dh - memory(_ds, 0x232);             //sub dh, ds:232h
loc_15937:                                      //loc_15937:
    if (_cl >= memory(_ds, 0x231))              //jnb short loc_1594D
      goto loc_1594D;
    memory(_ds, 0x22F) = 0x01;                  //mov byte ptr ds:22Fh, 1
    _al = 0x3c;                                 //mov al, 3Ch
    _al = _al - memory(_ds, 0x231);             //sub al, ds:231h
    _cl += _al;                                 //add cl, al
    goto loc_1595A;                             //jmp short loc_1595A
    _STOP_("db 90h");                           //db 90h
loc_1594D:                                      //loc_1594D:
    _cl = _cl - memory(_ds, 0x231);             //sub cl, ds:231h
    if (memory(_ds, 0x22E) == 0x00)             //jz short loc_1595A
      goto loc_1595A;
    _cl -= 1;                                   //dec cl
loc_1595A:                                      //loc_1595A:
    if (_ch >= memory(_ds, 0x230))              //jnb short loc_15974
      goto loc_15974;
    _al = 0x18;                                 //mov al, 18h
    if (memory(_ds, 0x22E) == 0x00)             //jz short loc_1596B
      goto loc_1596B;
    _al -= 1;                                   //dec al
loc_1596B:                                      //loc_1596B:
    _al = _al - memory(_ds, 0x230);             //sub al, ds:230h
    _ch += _al;                                 //add ch, al
    goto loc_15981;                             //jmp short loc_15981
loc_15974:                                      //loc_15974:
    _ch = _ch - memory(_ds, 0x230);             //sub ch, ds:230h
    if (memory(_ds, 0x22F) == 0x00)             //jz short loc_15981
      goto loc_15981;
    _ch -= 1;                                   //dec ch
loc_15981:                                      //loc_15981:
    _lea(_si, _ds, 0x23A);                      //lea si, ds:23Ah
    if (memory(_ds, 0x217) == 0x01)             //jz short loc_15990
      goto loc_15990;
    _lea(_si, _ds, 0x243);                      //lea si, ds:243h
loc_15990:                                      //loc_15990:
    _dh = _dh + memory(_ds, _si + 2);           //add dh, [si+2]
    if (_dh < 0x3c)                             //jb short loc_1599D
      goto loc_1599D;
    _cl += 1;                                   //inc cl
    _dh -= 0x3c;                                //sub dh, 3Ch
loc_1599D:                                      //loc_1599D:
    memory(_ds, _si + 2) = _dh;                 //mov [si+2], dh
    _cl = _cl + memory(_ds, _si + 1);           //add cl, [si+1]
    if (_cl < 0x3c)                             //jb short loc_159AD
      goto loc_159AD;
    _ch += 1;                                   //inc ch
    _cl -= 0x3c;                                //sub cl, 3Ch
loc_159AD:                                      //loc_159AD:
    memory(_ds, _si + 1) = _cl;                 //mov [si+1], cl
    memory(_ds, _si) += _ch;                    //add [si], ch
}

void sub_159B3()
{
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    _lea(_si, _ds, 0x18B1);                     //lea si, ds:18B1h
    _di = _si;                                  //mov di, si
    _di += 0x0034;                              //add di, 34h
    _cx = 0x0009;                               //mov cx, 9
    _bx >>= 1;                                  //shr bx, 1
    _cx -= _bx;                                 //sub cx, bx
    if (_cx == 0x0000)                          //jz short loc_159DE
      goto loc_159DE;
loc_159CA:                                      //loc_159CA:
    _push(_cx);                                 //push cx
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _cx = 0x002e;                               //mov cx, 2Eh
    _flags.direction = false;                   //cld
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _si -= 0x0034;                              //sub si, 34h
    _di -= 0x0034;                              //sub di, 34h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_159CA
      goto loc_159CA;
loc_159DE:                                      //loc_159DE:
    _es = memory16(_ds, 0x24F);                 //mov es, word ptr ds:24Fh
    _bp = _di;                                  //mov bp, di
loc_159E4:                                      //loc_159E4:
    _lea(_si, _ds, 0x234);                      //lea si, ds:234h
    if (memory(_ds, 0x217) == 0x01)             //jz short loc_159F3
      goto loc_159F3;
    _lea(_si, _ds, 0x23D);                      //lea si, ds:23Dh
loc_159F3:                                      //loc_159F3:
    _al = memory(_ds, _si + 6);                 //mov al, [si+6]
    _di = _bp;                                  //mov di, bp
    sub_15C9A();                                //call sub_15C9A
    _al = memory(_ds, _si + 7);                 //mov al, [si+7]
    sub_15C9A();                                //call sub_15C9A
    _al = memory(_ds, _si + 8);                 //mov al, [si+8]
    sub_15C9A();                                //call sub_15C9A
    _push(_si);                                 //push si
    _lea(_si, _ds, 0x3D3);                      //lea si, ds:3D3h
    if (memory(_ds, 0x64F) == 0x01)             //jz short loc_15A22
      goto loc_15A22;
    _lea(_si, _ds, 0x218);                      //lea si, ds:218h
    if (memory(_ds, 0x217) == 0x01)             //jz short loc_15A22
      goto loc_15A22;
    _lea(_si, _ds, 0x21E);                      //lea si, ds:21Eh
loc_15A22:                                      //loc_15A22:
    _di = _bp;                                  //mov di, bp
    _dx = memory16(_ds, _si);                   //mov dx, [si]
    _dx = _dx + memory16(_ds, _si + 4);         //add dx, [si+4]
    _dx >>= 1;                                  //shr dx, 1
    _dx += 1;                                   //inc dx
    _di += 0x000b;                              //add di, 0Bh
    _lea(_bx, _ds, 0x107B);                     //lea bx, ds:107Bh
    sub_15C46();                                //call sub_15C46
    _dx = memory16(_ds, _si + 2);               //mov dx, [si+2]
    _di += 0x0003;                              //add di, 3
    _lea(_bx, _ds, 0x107B);                     //lea bx, ds:107Bh
    sub_15C46();                                //call sub_15C46
    _si = _pop();                               //pop si
    _ah = 0x00;                                 //mov ah, 0
    _al = memory(_ds, _si + 6);                 //mov al, [si+6]
    if (_al <= 0x11)                            //jbe short loc_15A4F
      goto loc_15A4F;
    _al = 0x11;                                 //mov al, 11h
loc_15A4F:                                      //loc_15A4F:
    _cx = 0x0e10;                               //mov cx, 0E10h
    _mul(_cx);                                  //mul cx
    _dx = _ax;                                  //mov dx, ax
    _ah = 0x00;                                 //mov ah, 0
    _al = memory(_ds, _si + 7);                 //mov al, [si+7]
    _cx = 0x003c;                               //mov cx, 3Ch
    _mul(_cx);                                  //mul cx
    _dx += _ax;                                 //add dx, ax
    _ah = 0x00;                                 //mov ah, 0
    _al = memory(_ds, _si + 8);                 //mov al, [si+8]
    _dx += _ax;                                 //add dx, ax
    _cx = _dx;                                  //mov cx, dx
    _ax = 0x0000;                               //mov ax, 0
    _dx = memory16(_ds, _si);                   //mov dx, [si]
    _ah = _dl;                                  //mov ah, dl
    _dl = _dh;                                  //mov dl, dh
    _dh = 0x00;                                 //mov dh, 0
    _div(_cx);                                  //div cx
    _dx = _ax;                                  //mov dx, ax
    _di = _bp;                                  //mov di, bp
    _di += 0x0015;                              //add di, 15h
    _lea(_bx, _ds, 0x1075);                     //lea bx, ds:1075h
    sub_15C46();                                //call sub_15C46
    _di = _bp;                                  //mov di, bp
    _dx = memory16(_ds, _si);                   //mov dx, [si]
    _di += 0x001e;                              //add di, 1Eh
    _lea(_bx, _ds, 0x1075);                     //lea bx, ds:1075h
    sub_15C46();                                //call sub_15C46
    _di = _bp;                                  //mov di, bp
    _dx = memory16(_ds, _si + 2);               //mov dx, [si+2]
    if (_dx <= 0x03e7)                          //jbe short loc_15AA2
      goto loc_15AA2;
    _dx = 0x03e7;                               //mov dx, 3E7h
loc_15AA2:                                      //loc_15AA2:
    _di += 0x0026;                              //add di, 26h
    _lea(_bx, _ds, 0x1079);                     //lea bx, ds:1079h
    sub_15C46();                                //call sub_15C46
    _dx = memory16(_ds, _si + 4);               //mov dx, [si+4]
    if (_dx <= 0x0063)                          //jbe short loc_15AB7
      goto loc_15AB7;
    _dx = 0x0063;                               //mov dx, 63h
loc_15AB7:                                      //loc_15AB7:
    _di += 0x0004;                              //add di, 4
    _lea(_bx, _ds, 0x107B);                     //lea bx, ds:107Bh
    sub_15C46();                                //call sub_15C46
    if (memory(_ds, 0x1A33) == 0x01)            //jz short loc_15B06
      goto loc_15B06;
    _si = _bp;                                  //mov si, bp
    _bp += 0x0003;                              //add bp, 3
    _cx = 0x002f;                               //mov cx, 2Fh
    memory(_ds, 0x1A36) = 0x01;                 //mov byte ptr ds:1A36h, 1
    _lea(_di, _ds, 0x194E);                     //lea di, ds:194Eh
    if (memory(_ds, 0x64F) == 0x01)             //jz short loc_15AFE
      goto loc_15AFE;
    memory(_ds, 0x1A37) = 0x00;                 //mov byte ptr ds:1A37h, 0
    memory(_ds, 0x1A36) = 0x02;                 //mov byte ptr ds:1A36h, 2
    _lea(_di, _ds, 0x19B8);                     //lea di, ds:19B8h
    if (memory(_ds, 0x217) == 0x02)             //jz short loc_15AFE
      goto loc_15AFE;
    memory(_ds, 0x1A37) = 0x01;                 //mov byte ptr ds:1A37h, 1
    _lea(_di, _ds, 0x1983);                     //lea di, ds:1983h
loc_15AFE:                                      //loc_15AFE:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    memory16(_ds, _di) = _ax;                   //mov [di], ax
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_15AFE
      goto loc_15AFE;
loc_15B06:                                      //loc_15B06:
    _ax = memory16(_ds, 0x1A2B);                //mov ax, ds:1A2Bh
    _bx = memory16(_ds, 0x1A2D);                //mov bx, ds:1A2Dh
    _cx = memory16(_ds, 0x1A2F);                //mov cx, ds:1A2Fh
    _dx = memory16(_ds, 0x1A31);                //mov dx, ds:1A31h
    _lea(_si, _ds, 0x23A);                      //lea si, ds:23Ah
    if (memory(_ds, 0x217) == 0x01)             //jz short loc_15B24
      goto loc_15B24;
    _lea(_si, _ds, 0x243);                      //lea si, ds:243h
loc_15B24:                                      //loc_15B24:
    _dl = _dl + memory(_ds, _si + 2);           //add dl, [si+2]
    if (_dx < 0x003c)                           //jb short loc_15B31
      goto loc_15B31;
    _cl += 1;                                   //inc cl
    _dx -= 0x003c;                              //sub dx, 3Ch
loc_15B31:                                      //loc_15B31:
    memory16(_ds, 0x1A31) = _dx;                //mov ds:1A31h, dx
    _cl = _cl + memory(_ds, _si + 1);           //add cl, [si+1]
    if (_cx < 0x003c)                           //jb short loc_15B42
      goto loc_15B42;
    _bl += 1;                                   //inc bl
    _cx -= 0x003c;                              //sub cx, 3Ch
loc_15B42:                                      //loc_15B42:
    memory16(_ds, 0x1A2F) = _cx;                //mov ds:1A2Fh, cx
    _bl = _bl + memory(_ds, _si);               //add bl, [si]
loc_15B48:                                      //loc_15B48:
    if (_bx < 0x0018)                           //jb short loc_15B53
      goto loc_15B53;
    _bx -= 0x0018;                              //sub bx, 18h
    _ax += 1;                                   //inc ax
    goto loc_15B48;                             //jmp short loc_15B48
loc_15B53:                                      //loc_15B53:
    memory16(_ds, 0x1A2D) = _bx;                //mov ds:1A2Dh, bx
    if (_ax <= 0x0007)                          //jbe short loc_15B63
      goto loc_15B63;
    _ax -= 0x0007;                              //sub ax, 7
    memory16(_ds, 0x1A29) += 1;                 //inc word ptr ds:1A29h
loc_15B63:                                      //loc_15B63:
    memory16(_ds, 0x1A2B) = _ax;                //mov ds:1A2Bh, ax
}

void sub_15B67()
{
    sub_15CC3();                                //call sub_15CC3
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    memory16(_ds, 0x1454) = 0x0000;             //mov word ptr ds:1454h, 0
    if (_dh >= memory(_ds, 0x1453))             //jnb short loc_15B88
      goto loc_15B88;
    memory(_ds, 0x1454) = 0x01;                 //mov byte ptr ds:1454h, 1
    _al = 0x3c;                                 //mov al, 3Ch
    _al = _al - memory(_ds, 0x1453);            //sub al, ds:1453h
    _dh += _al;                                 //add dh, al
    goto loc_15B8C;                             //jmp short loc_15B8C
loc_15B88:                                      //loc_15B88:
    _dh = _dh - memory(_ds, 0x1453);            //sub dh, ds:1453h
loc_15B8C:                                      //loc_15B8C:
    if (_cl >= memory(_ds, 0x1452))             //jnb short loc_15BA2
      goto loc_15BA2;
    memory(_ds, 0x1455) = 0x01;                 //mov byte ptr ds:1455h, 1
    _al = 0x3c;                                 //mov al, 3Ch
    _al = _al - memory(_ds, 0x1452);            //sub al, ds:1452h
    _cl += _al;                                 //add cl, al
    goto loc_15BAF;                             //jmp short loc_15BAF
loc_15BA2:                                      //loc_15BA2:
    _cl = _cl - memory(_ds, 0x1452);            //sub cl, ds:1452h
    if (memory(_ds, 0x1454) == 0x00)            //jz short loc_15BAF
      goto loc_15BAF;
    _cl -= 1;                                   //dec cl
loc_15BAF:                                      //loc_15BAF:
    if (_ch >= memory(_ds, 0x1451))             //jnb short loc_15BC9
      goto loc_15BC9;
    _al = 0x18;                                 //mov al, 18h
    if (memory(_ds, 0x1454) == 0x00)            //jz short loc_15BC0
      goto loc_15BC0;
    _al -= 1;                                   //dec al
loc_15BC0:                                      //loc_15BC0:
    _al = _al - memory(_ds, 0x1451);            //sub al, ds:1451h
    _ch += _al;                                 //add ch, al
    goto loc_15BD6;                             //jmp short loc_15BD6
    _STOP_("db 90h");                           //db 90h
loc_15BC9:                                      //loc_15BC9:
    _ch = _ch - memory(_ds, 0x1451);            //sub ch, ds:1451h
    if (memory(_ds, 0x1455) == 0x00)            //jz short loc_15BD6
      goto loc_15BD6;
    _ch -= 1;                                   //dec ch
loc_15BD6:                                      //loc_15BD6:
    memory(_ds, 0x1451) = _ch;                  //mov ds:1451h, ch
    memory(_ds, 0x1452) = _cl;                  //mov ds:1452h, cl
    memory(_ds, 0x1453) = _dh;                  //mov ds:1453h, dh
    _ax = memory16(_ds, 0x1A21);                //mov ax, ds:1A21h
    _bx = memory16(_ds, 0x1A23);                //mov bx, ds:1A23h
    _cx = memory16(_ds, 0x1A25);                //mov cx, ds:1A25h
    _dx = memory16(_ds, 0x1A27);                //mov dx, ds:1A27h
    _lea(_si, _ds, 0x1451);                     //lea si, ds:1451h
    _dl = _dl + memory(_ds, _si + 2);           //add dl, [si+2]
    if (_dx < 0x003c)                           //jb short loc_15C02
      goto loc_15C02;
    _cl += 1;                                   //inc cl
    _dx -= 0x003c;                              //sub dx, 3Ch
loc_15C02:                                      //loc_15C02:
    memory16(_ds, 0x1A27) = _dx;                //mov ds:1A27h, dx
    _cl = _cl + memory(_ds, _si + 1);           //add cl, [si+1]
    if (_cx < 0x003c)                           //jb short loc_15C13
      goto loc_15C13;
    _bl += 1;                                   //inc bl
    _cx -= 0x003c;                              //sub cx, 3Ch
loc_15C13:                                      //loc_15C13:
    memory16(_ds, 0x1A25) = _cx;                //mov ds:1A25h, cx
    _bl = _bl + memory(_ds, _si);               //add bl, [si]
loc_15C19:                                      //loc_15C19:
    if (_bx < 0x0018)                           //jb short loc_15C24
      goto loc_15C24;
    _bx -= 0x0018;                              //sub bx, 18h
    _ax += 1;                                   //inc ax
    goto loc_15C19;                             //jmp short loc_15C19
loc_15C24:                                      //loc_15C24:
    memory16(_ds, 0x1A23) = _bx;                //mov ds:1A23h, bx
    if (_ax <= 0x0007)                          //jbe short loc_15C34
      goto loc_15C34;
    _ax -= 0x0007;                              //sub ax, 7
    memory16(_ds, 0x1A1F) += 1;                 //inc word ptr ds:1A1Fh
loc_15C34:                                      //loc_15C34:
    memory16(_ds, 0x1A21) = _ax;                //mov ds:1A21h, ax
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    memory(_ds, 0x1451) = _ch;                  //mov ds:1451h, ch
    memory(_ds, 0x1452) = _cl;                  //mov ds:1452h, cl
    memory(_ds, 0x1453) = _dh;                  //mov ds:1453h, dh
}

void sub_15C46()
{
    _ah = 0x00;                                 //mov ah, 0
loc_15C48:                                      //loc_15C48:
    _al = 0x00;                                 //mov al, 0
loc_15C4A:                                      //loc_15C4A:
    if ((short)_dx < (short)memory16(_ds, _bx)) //jl short loc_15C54
      goto loc_15C54;
    _al += 1;                                   //inc al
    _dx = _dx - memory16(_ds, _bx);             //sub dx, [bx]
    goto loc_15C4A;                             //jmp short loc_15C4A
loc_15C54:                                      //loc_15C54:
    _al += 0x30;                                //add al, 30h
    if (_al != 0x30)                            //jnz short loc_15C64
      goto loc_15C64;
    if (_ah != 0x00)                            //jnz short loc_15C66
      goto loc_15C66;
    _al = 0x20;                                 //mov al, 20h
    goto loc_15C66;                             //jmp short loc_15C66
loc_15C64:                                      //loc_15C64:
    _ah += 1;                                   //inc ah
loc_15C66:                                      //loc_15C66:
    memory(_ds, _di) = _al;                     //mov [di], al
    _di += 1;                                   //inc di
    _bx += 0x0002;                              //add bx, 2
    _al = 0x0a;                                 //mov al, 0Ah
    if (memory(_ds, _bx + -2) != _al)           //jnz short loc_15C48
      goto loc_15C48;
    _dl += 0x30;                                //add dl, 30h
    memory(_ds, _di) = _dl;                     //mov [di], dl
}

void sub_15C79()
{
    _push(_di);                                 //push di
loc_15C7A:                                      //loc_15C7A:
    _al = memory(_ds, _si);                     //mov al, [si]
    _si += 1;                                   //inc si
    if (_al != 0xff)                            //jnz short loc_15C86
      goto loc_15C86;
    memory16(_ds, 0x26E) = _pop();              //pop word ptr ds:26Eh
    return;                                     //retn
loc_15C86:                                      //loc_15C86:
    if (_al != 0x0d)                            //jnz short loc_15C92
      goto loc_15C92;
    _di = _pop();                               //pop di
    _di += 0x00a0;                              //add di, 0A0h
    _push(_di);                                 //push di
    goto loc_15C7A;                             //jmp short loc_15C7A
loc_15C92:                                      //loc_15C92:
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    _di += 0x0002;                              //add di, 2
    goto loc_15C7A;                             //jmp short loc_15C7A
}

void sub_15C9A()
{
    _ah = 0x00;                                 //mov ah, 0
loc_15C9C:                                      //loc_15C9C:
    if (_al < 0x0a)                             //jb short loc_15CA6
      goto loc_15CA6;
    _al -= 0x0a;                                //sub al, 0Ah
    _ah += 1;                                   //inc ah
    goto loc_15C9C;                             //jmp short loc_15C9C
loc_15CA6:                                      //loc_15CA6:
    _ax += 0x3030;                              //add ax, 3030h
    memory(_ds, _di) = _ah;                     //mov [di], ah
    memory(_ds, _di + 1) = _al;                 //mov [di+1], al
    _di += 0x0003;                              //add di, 3
}

void sub_15CB2()
{
    _ah = 0x2a;                                 //mov ah, 2Ah
    _interrupt(33);                             //int 21h
    _cx -= 0x0708;                              //sub cx, 708h
loc_15CBA:                                      //loc_15CBA:
    _cx -= 0x0064;                              //sub cx, 64h
    if (_cx >= 0x0064)                          //jnb short loc_15CBA
      goto loc_15CBA;
}

void sub_15CC3()
{
    _ah = 0x2c;                                 //mov ah, 2Ch
    _interrupt(33);                             //int 21h
}

void sub_15CC8()
{
    _lea(_dx, _ds, 0x30C);                      //lea dx, ds:30Ch
    _ah = 0x3d;                                 //mov ah, 3Dh
    _al = 0x02;                                 //mov al, 2
    _interrupt(33);                             //int 21h
    if (!_flags.carry)                          //jnb short loc_15D3C
      _STOP_("goto loc_15D3C");
    sub_15CB2();                                //call sub_15CB2
    memory(_ds, 0x26D) = _cl;                   //mov ds:26Dh, cl
    _lea(_di, _ds, 0x1A4E);                     //lea di, ds:1A4Eh
    _di += 0x015a;                              //add di, 15Ah
    _cx = 0x000a;                               //mov cx, 0Ah
loc_15CE6:                                      //loc_15CE6:
    sub_15D2B();                                //call sub_15D2B
    _di += 0x0040;                              //add di, 40h
    if (--_cx)                                  //loop loc_15CE6
      goto loc_15CE6;
    _di += 0x004a;                              //add di, 4Ah
    sub_15D2B();                                //call sub_15D2B
    _di += 0x0041;                              //add di, 41h
    sub_15D2B();                                //call sub_15D2B
    _di += 0x0041;                              //add di, 41h
    sub_15D2B();                                //call sub_15D2B
    sub_15CC3();                                //call sub_15CC3
    _dx = _cx;                                  //mov dx, cx
    _lea(_di, _ds, 0x1A4E);                     //lea di, ds:1A4Eh
    _di += 0x0165;                              //add di, 165h
    _cx = 0x000a;                               //mov cx, 0Ah
loc_15D10:                                      //loc_15D10:
    sub_15D31();                                //call sub_15D31
    _di += 0x0043;                              //add di, 43h
    if (--_cx)                                  //loop loc_15D10
      goto loc_15D10;
    _di += 0x004a;                              //add di, 4Ah
    sub_15D31();                                //call sub_15D31
    _di += 0x0044;                              //add di, 44h
    sub_15D31();                                //call sub_15D31
    _di += 0x0044;                              //add di, 44h
    sub_15D31();                                //call sub_15D31
}

void sub_15D2B()
{
    _al = memory(_ds, 0x26D);                   //mov al, ds:26Dh
    sub_15C9A();                                //call sub_15C9A
//    _STOP_("sp-trace-fail");                    //sub_15D2B endp_failed
//    _STOP_("continues");                        //sub_15D31 proc near
    sub_15D31();
}

void sub_15D31()
{
    _al = _dh;                                  //mov al, dh
    sub_15C9A();                                //call sub_15C9A
    _al = _dl;                                  //mov al, dl
    sub_15C9A();                                //call sub_15C9A
}

void loc_15D3C()
{
    memory16(_ds, 0x319) = _ax;                 //mov ds:319h, ax
    _bx = memory16(_ds, 0x319);                 //mov bx, ds:319h
    _cx = 0x08ad;                               //mov cx, 8ADh
    _lea(_dx, _ds, 0x170E);                     //lea dx, ds:170Eh
    _ah = 0x3f;                                 //mov ah, 3Fh
    _interrupt(33);                             //int 21h
    _bx = memory16(_ds, 0x319);                 //mov bx, ds:319h
    _ah = 0x3e;                                 //mov ah, 3Eh
    _interrupt(33);                             //int 21h
}

void sub_15D57()
{
    _lea(_dx, _ds, 0x30C);                      //lea dx, ds:30Ch
    _ah = 0x3c;                                 //mov ah, 3Ch
    _cl = 0x20;                                 //mov cl, 20h
    _interrupt(33);                             //int 21h
    memory16(_ds, 0x319) = _ax;                 //mov ds:319h, ax
    _bx = memory16(_ds, 0x319);                 //mov bx, ds:319h
    _cx = 0x08ad;                               //mov cx, 8ADh
    _lea(_dx, _ds, 0x170E);                     //lea dx, ds:170Eh
    _ah = 0x40;                                 //mov ah, 40h
    _interrupt(33);                             //int 21h
    _bx = memory16(_ds, 0x319);                 //mov bx, ds:319h
    _ah = 0x3e;                                 //mov ah, 3Eh
    _interrupt(33);                             //int 21h
}

void sub_15D7C()
{
    if (_bx == 0xffff)                          //jz short loc_15D87
      goto loc_15D87;
    _cx = 0x0001;                               //mov cx, 1
    goto loc_15D8D;                             //jmp short loc_15D8D
    _STOP_("db 90h");                           //db 90h
loc_15D87:                                      //loc_15D87:
    _bx = 0x0000;                               //mov bx, 0
    _cx = 0x0004;                               //mov cx, 4
loc_15D8D:                                      //loc_15D8D:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    memory16(_ds, _bx + 491) = _ax;             //mov [bx+1EBh], ax
    _ax = memory16(_ds, _si + 2);               //mov ax, [si+2]
    memory16(_ds, _bx + 499) = _ax;             //mov [bx+1F3h], ax
    _ax = memory16(_ds, _si + 4);               //mov ax, [si+4]
    memory16(_ds, _bx + 507) = _ax;             //mov [bx+1FBh], ax
    _bx += 0x0002;                              //add bx, 2
    if (--_cx)                                  //loop loc_15D8D
      goto loc_15D8D;
    _bx -= 0x0002;                              //sub bx, 2
}

void sub_15DAA()
{
    _push(_es);                                 //push es
    _push(_ds);                                 //push ds
    _es = _pop();                               //pop es
    _flags.direction = false;                   //cld
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _es = _pop();                               //pop es
}

void sub_15DB2()
{
    _bx = memory16(_ds, _bx + 1005);            //mov bx, [bx+3EDh]
    _es = memory16(_ds, 0x24B);                 //mov es, word ptr ds:24Bh
    _di = 0x1222;                               //mov di, 1222h
    _bx += 0x0016;                              //add bx, 16h
    _cx = 0x000b;                               //mov cx, 0Bh
loc_15DC3:                                      //loc_15DC3:
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _cx = 0x0013;                               //mov cx, 13h
loc_15DC8:                                      //loc_15DC8:
    if (memory(_ds, _bx) != 0x20)               //jnz short loc_15DE8
      goto loc_15DE8;
    _push(_cx);                                 //push cx
    _si = 0x6da4;                               //mov si, 6DA4h
    sub_1610E();                                //call sub_1610E
    _di -= 0x0780;                              //sub di, 780h
    _cx = _pop();                               //pop cx
    goto loc_15DE8;                             //jmp short loc_15DE8
    _push(_cx);                                 //push cx
    _si = 0x6da8;                               //mov si, 6DA8h
    sub_1610E();                                //call sub_1610E
    _di -= 0x0780;                              //sub di, 780h
    _cx = _pop();                               //pop cx
loc_15DE8:                                      //loc_15DE8:
    _di += 0x0004;                              //add di, 4
    _bx += 1;                                   //inc bx
    if (--_cx)                                  //loop loc_15DC8
      goto loc_15DC8;
    _bx += 0x0002;                              //add bx, 2
    _di = _pop();                               //pop di
    _di += 0x0780;                              //add di, 780h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_15DC3
      goto loc_15DC3;
}

void sub_15DFA()
{
    _bx = 0x0000;                               //mov bx, 0
    _di = 0x1222;                               //mov di, 1222h
    _bx += 0x0016;                              //add bx, 16h
    _cx = 0x000b;                               //mov cx, 0Bh
loc_15E06:                                      //loc_15E06:
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _cx = 0x0013;                               //mov cx, 13h
loc_15E0B:                                      //loc_15E0B:
    _si = 0x6da4;                               //mov si, 6DA4h
    if (memory(_ds, _bx + 124) & 0x08)          //jnz short loc_15E1F
      goto loc_15E1F;
    if (!(memory(_ds, _bx + 124) & 0x01))       //jz short loc_15E28
      goto loc_15E28;
    _si = 0x6da0;                               //mov si, 6DA0h
loc_15E1F:                                      //loc_15E1F:
    _push(_cx);                                 //push cx
    sub_1610E();                                //call sub_1610E
    _di -= 0x0780;                              //sub di, 780h
    _cx = _pop();                               //pop cx
loc_15E28:                                      //loc_15E28:
    _di += 0x0004;                              //add di, 4
    _bx += 1;                                   //inc bx
    if (--_cx)                                  //loop loc_15E0B
      goto loc_15E0B;
    _bx += 0x0002;                              //add bx, 2
    _di = _pop();                               //pop di
    _di += 0x0780;                              //add di, 780h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_15E06
      goto loc_15E06;
    if (memory(_ds, 0x34) == 0x00)              //jz short loc_15E4B
      goto loc_15E4B;
    _si = memory16(_ds, 0x12);                  //mov si, ds:12h
    _di = memory16(_ds, 0x37);                  //mov di, ds:37h
    sub_1610E();                                //call sub_1610E
loc_15E4B:                                      //loc_15E4B:
    if (memory(_ds, 0x3B) == 0x01)              //jz short loc_15E64
      goto loc_15E64;
    if (memory(_ds, 0x3C) != 0x01)              //jnz short loc_15E64
      goto loc_15E64;
    _si = memory16(_ds, 0x16);                  //mov si, ds:16h
    _di = memory16(_ds, 0x3F);                  //mov di, ds:3Fh
    sub_1610E();                                //call sub_1610E
loc_15E64:                                      //loc_15E64:
    if (memory16(_ds, 0x3D3) != 0x0000)         //jnz short locret_15E6E
      goto locret_15E6E;
    sub_168F2();                                //call sub_168F2
locret_15E6E:                                   //locret_15E6E:
    return;
}

void sub_15E6F()
{
    _bx = memory16(_ds, _bx + 1005);            //mov bx, [bx+3EDh]
    memory16(_ds, 0x66) = 0x00d1;               //mov word ptr ds:66h, 0D1h
    _lea(_di, _ds, 0x92);                       //lea di, ds:92h
    _bx += 0x0016;                              //add bx, 16h
    _cx = 0x000b;                               //mov cx, 0Bh
loc_15E83:                                      //loc_15E83:
    _push(_cx);                                 //push cx
    _cx = 0x0013;                               //mov cx, 13h
loc_15E87:                                      //loc_15E87:
    _al = 0xf9;                                 //mov al, 0F9h
    if (memory(_ds, _bx) == 0x20)               //jz short loc_15E94
      goto loc_15E94;
    _al &= 0xf6;                                //and al, 0F6h
    memory16(_ds, 0x66) -= 1;                   //dec word ptr ds:66h
loc_15E94:                                      //loc_15E94:
    if (memory(_ds, _bx + -21) == 0x20)         //jz short loc_15E9C
      goto loc_15E9C;
    _al &= 0x7f;                                //and al, 7Fh
loc_15E9C:                                      //loc_15E9C:
    if (memory(_ds, _bx + 21) == 0x20)          //jz short loc_15EA4
      goto loc_15EA4;
    _al &= 0xbf;                                //and al, 0BFh
loc_15EA4:                                      //loc_15EA4:
    if (memory(_ds, _bx + -1) == 0x20)          //jz short loc_15EAC
      goto loc_15EAC;
    _al &= 0xdf;                                //and al, 0DFh
loc_15EAC:                                      //loc_15EAC:
    if (memory(_ds, _bx + 1) == 0x20)           //jz short loc_15EB4
      goto loc_15EB4;
    _al &= 0xef;                                //and al, 0EFh
loc_15EB4:                                      //loc_15EB4:
    memory(_ds, _di) = _al;                     //mov [di], al
    _bx += 1;                                   //inc bx
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_15E87
      goto loc_15E87;
    _bx += 0x0002;                              //add bx, 2
    _di += 0x0002;                              //add di, 2
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_15E83
      goto loc_15E83;
    _di = 0x0073;                               //mov di, 73h
    memory(_ds, _di + 124) |= 0x40;             //or byte ptr [di+7Ch], 40h
}

void loc_15EEB(int pc = 0);
void sub_15ECC()
{
    _si = memory16(_ds, 0x5AA);                 //mov si, ds:5AAh
    if (_si == 0x05ac)                          //jz short loc_15EEB
    {
        loc_15EEB();
        return;
    }
    _ax = memory16(_ds, 0x5A8);                 //mov ax, ds:5A8h
    if (_ax != memory16(_ds, _si))              //jnz short loc_15F06
    {
        loc_15EEB(0x15F06);
        return;
    }
//    _STOP_("sp-trace-fail");                    //sub_15ECC endp_failed
//    _STOP_("continues");                        //sub_15EDD proc near
//    sub_15EDD();
}

void sub_15EDD()
{
    memory16(_ds, 0x5A8) = 0x0000;              //mov word ptr ds:5A8h, 0
    _lea(_si, _ds, 0x5AC);                      //lea si, ds:5ACh
    memory16(_ds, 0x5AA) = _si;                 //mov ds:5AAh, si
    loc_15EEB();
}

void loc_15EEB(int pc)                                      //loc_15EEB:
{
    if (pc == 0x15F06)
        goto loc_15F06;
    _ax = 0x0000;                               //mov ax, 0
    _bp = memory16(_ds, 0x190);                 //mov bp, ds:190h
    if (!(memory(_ds, _bp + 124) & 0x08))       //jz short loc_15F12
      goto loc_15F12;
    _al = memory(_ds, 0x18F);                   //mov al, ds:18Fh
    _al <<= 1;                                  //shl al, 1
    _si += _ax;                                 //add si, ax
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    goto loc_15F12;                             //jmp short loc_15F12
loc_15F06:                                      //loc_15F06:
    _si += 0x0002;                              //add si, 2
    _si += _ax;                                 //add si, ax
    memory16(_ds, 0x5A8) += 0x0002;             //add word ptr ds:5A8h, 2
    _ax = memory16(_ds, _si);                   //mov ax, [si]
loc_15F12:                                      //loc_15F12:
    sub_15F3A();                                //call sub_15F3A
//    _STOP_("sp-trace-fail");                    //sub_15EDD endp_failed
//    _STOP_("continues");                        //sub_15F15 proc near
    sub_15F15(); 
}

void sub_15F15()
{
    if (memory16(_ds, 0x1120) > 0x0001)         //ja short loc_15F1D
      goto loc_15F1D;
    return;                                     //retn
loc_15F1D:                                      //loc_15F1D:
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _bx = memory16(_ds, 0x1120);                //mov bx, ds:1120h
loc_15F23:                                      //loc_15F23:
    _cx = 0x0008;                               //mov cx, 8
    if (memory(_ds, 0x254) == 0x00)             //jz short loc_15F30
      goto loc_15F30;
    _cx = 0x0005;                               //mov cx, 5
loc_15F30:                                      //loc_15F30:
    if (--_cx)                                  //loop loc_15F30
      goto loc_15F30;
    _cx = _bx;                                  //mov cx, bx
    _bx -= 1;                                   //dec bx
    if (--_cx)                                  //loop loc_15F23
      goto loc_15F23;
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
}

void sub_15F3A()
{
    if (memory(_ds, 0x5A7) == 0x00)             //jz short loc_15F5B
      goto loc_15F5B;
    if (_ax == 0x0000)                          //jz short loc_15F5B
      goto loc_15F5B;
    _push(_ax);                                 //push ax
    _al = 0xb6;                                 //mov al, 0B6h
    _out(67, _al);                              //out 43h, al
    _ax = _pop();                               //pop ax
    _out(66, _al);                              //out 42h, al
    //_STOP_("goto $+2");                         //jmp short $+2
loc_15F50:                                      //loc_15F50:
    _al = _ah;                                  //mov al, ah
    _out(66, _al);                              //out 42h, al
    _in(_al, 97);                               //in al, 61h
    _al |= 0x03;                                //or al, 3
    _out(97, _al);                              //out 61h, al
    return;                                     //retn
loc_15F5B:                                      //loc_15F5B:
    _in(_al, 97);                               //in al, 61h
    _al &= 0xfc;                                //and al, 0FCh
    _out(97, _al);                              //out 61h, al
}

void sub_15F62()
{
    sub_180E0();                                //call sub_180E0
    if (_al != 0x00)                            //jnz short loc_15FA0
      goto loc_15FA0;
    if (_ah != 0x48)                            //jnz short loc_15F74
      goto loc_15F74;
    memory(_ds, 0x18E) = 0x18;                  //mov byte ptr ds:18Eh, 18h
    return;                                     //retn
loc_15F74:                                      //loc_15F74:
    if (_ah != 0x50)                            //jnz short loc_15F7F
      goto loc_15F7F;
    memory(_ds, 0x18E) = 0x10;                  //mov byte ptr ds:18Eh, 10h
    return;                                     //retn
loc_15F7F:                                      //loc_15F7F:
    if (_ah != 0x4b)                            //jnz short loc_15F8A
      goto loc_15F8A;
    memory(_ds, 0x18E) = 0x08;                  //mov byte ptr ds:18Eh, 8
    return;                                     //retn
loc_15F8A:                                      //loc_15F8A:
    if (_ah != 0x4d)                            //jnz short loc_15F95
      goto loc_15F95;
    memory(_ds, 0x18E) = 0x00;                  //mov byte ptr ds:18Eh, 0
    return;                                     //retn
loc_15F95:                                      //loc_15F95:
    if (_ah != 0x3b)                            //jnz short locret_15FA7
      goto locret_15FA7;
    memory(_ds, 0x253) = memory(_ds, 0x253) ^ 0x01;//xor byte ptr ds:253h, 1
    return;                                     //retn
loc_15FA0:                                      //loc_15FA0:
    if (_al != 0x1b)                            //jnz short locret_15FA7
      goto locret_15FA7;
    sub_14639();                                //call sub_14639
locret_15FA7:                                   //locret_15FA7:
    return;
}

void sub_15FA8()
{
    _ax = memory16(_ds, 0x190);                 //mov ax, ds:190h
    _bx = 0x0000;                               //mov bx, 0
loc_15FAE:                                      //loc_15FAE:
    if (_ax <= 0x0028)                          //jbe short loc_15FB9
      goto loc_15FB9;
    _ax -= 0x0015;                              //sub ax, 15h
    _bx += 1;                                   //inc bx
    goto loc_15FAE;                             //jmp short loc_15FAE
loc_15FB9:                                      //loc_15FB9:
    _ax -= 0x0016;                              //sub ax, 16h
    memory16(_ds, 0x1071) = _ax;                //mov ds:1071h, ax
    memory16(_ds, 0x1073) = _bx;                //mov ds:1073h, bx
}

void sub_15FC4()
{
    _bx = memory16(_ds, 0x207);                 //mov bx, ds:207h
    if (memory(_ds, _bx + 414) == 0x07)         //jz short loc_15FD0
      goto loc_15FD0;
    return;                                     //retn
loc_15FD0:                                      //loc_15FD0:
    sub_1826D();                                //call sub_1826D
    if (_ah > memory(_ds, 0x22A))               //ja short loc_1603E
    { loc_1603E(); return; }
    memory(_ds, 0x106D) = 0x00;                 //mov byte ptr ds:106Dh, 0
    memory(_ds, 0x106E) = 0x01;                 //mov byte ptr ds:106Eh, 1
    memory(_ds, 0x106F) = 0x02;                 //mov byte ptr ds:106Fh, 2
    memory(_ds, 0x1070) = 0x03;                 //mov byte ptr ds:1070h, 3
    _si = 0x0000;                               //mov si, 0
    _flags.carry = _ah & 1;                     //shr ah, 1
    _ah >>= 1;
    _rcl(_si, 1);                               //rcl si, 1
    _flags.carry = _ah & 1;                     //shr ah, 1
    _ah >>= 1;
    _rcl(_si, 1);                               //rcl si, 1
    _dh = memory(_ds, _si + 4205);              //mov dh, [si+106Dh]
    sub_1602F();                                //call sub_1602F
    _si = 0x0000;                               //mov si, 0
    _flags.carry = _ah & 1;                     //shr ah, 1
    _ah >>= 1;
    _rcl(_si, 1);                               //rcl si, 1
    if (!(_ah & 0x01))                          //jz short loc_1600C
      goto loc_1600C;
    _si += 1;                                   //inc si
loc_1600C:                                      //loc_1600C:
    _dl = memory(_ds, _si + 4205);              //mov dl, [si+106Dh]
    sub_1602F();                                //call sub_1602F
    _bh = memory(_ds, 0x106D);                  //mov bh, ds:106Dh
    _bl = memory(_ds, 0x106E);                  //mov bl, ds:106Eh
    if (!(_ah & 0x02))                          //jz short loc_1602A
      goto loc_1602A;
    memory(_ds, 0x26D) = _bh;                   //mov ds:26Dh, bh
    _bh = _bl;                                  //mov bh, bl
    _bl = memory(_ds, 0x26D);                   //mov bl, ds:26Dh
loc_1602A:                                      //loc_1602A:
    _ax = _dx;                                  //mov ax, dx
    loc_1603E(0x160AC);
}

void sub_1602F()
{
loc_1602F:
    _al = memory(_ds, _si + 4206);              //mov al, [si+106Eh]
    memory(_ds, _si + 4205) = _al;              //mov [si+106Dh], al
    _si += 1;                                   //inc si
    if (_si < 0x0004)                           //jb short sub_1602F
      goto loc_1602F;
}

void loc_1603E(int pc)
{
    if (pc == 0x160AC)
        goto loc_160AC;
    
    _bx <<= 1;                                  //shl bx, 1
    _cx = memory16(_ds, _bx + 418);             //mov cx, [bx+1A2h]
    _dx = 0x0000;                               //mov dx, 0
loc_16047:                                      //loc_16047:
    if (_cx <= 0x0028)                          //jbe short loc_16052
      goto loc_16052;
    _cx -= 0x0015;                              //sub cx, 15h
    _dx += 1;                                   //inc dx
    goto loc_16047;                             //jmp short loc_16047
loc_16052:                                      //loc_16052:
    _cx -= 0x0016;                              //sub cx, 16h
    _ax = 0x0103;                               //mov ax, 103h
    _bx = 0x0002;                               //mov bx, 2
    _si = memory16(_ds, 0x207);                 //mov si, ds:207h
    if (memory(_ds, _si + 104) == 0x47)         //jz short loc_1606F
      goto loc_1606F;
    memory16(_ds, 0x26E) = _ax;                 //mov ds:26Eh, ax
    _ax = _bx;                                  //mov ax, bx
    _bx = memory16(_ds, 0x26E);                 //mov bx, ds:26Eh
loc_1606F:                                      //loc_1606F:
    _cx = _cx - memory16(_ds, 0x1071);          //sub cx, ds:1071h
    if ((short)_cx >= 0)                        //jns short loc_16081
      goto loc_16081;
    memory(_ds, 0x26D) = _ah;                   //mov ds:26Dh, ah
    _ah = _bh;                                  //mov ah, bh
    _bh = memory(_ds, 0x26D);                   //mov bh, ds:26Dh
    _cx = -_cx;                                 //neg cx
loc_16081:                                      //loc_16081:
    _dx = _dx - memory16(_ds, 0x1073);          //sub dx, ds:1073h
    if ((short)_dx >= 0)                        //jns short loc_16092
      goto loc_16092;
    memory(_ds, 0x26D) = _al;                   //mov ds:26Dh, al
    _al = _bl;                                  //mov al, bl
    _bl = memory(_ds, 0x26D);                   //mov bl, ds:26Dh
    _dx = -_dx;                                 //neg dx
loc_16092:                                      //loc_16092:
    if (_cx > _dx)                              //ja short loc_160A2
      goto loc_160A2;
    memory(_ds, 0x26D) = _ah;                   //mov ds:26Dh, ah
    _ah = _al;                                  //mov ah, al
    _al = memory(_ds, 0x26D);                   //mov al, ds:26Dh
    goto loc_160AC;                             //jmp short loc_160AC
loc_160A2:                                      //loc_160A2:
    memory(_ds, 0x26D) = _bh;                   //mov ds:26Dh, bh
    _bh = _bl;                                  //mov bh, bl
    _bl = memory(_ds, 0x26D);                   //mov bl, ds:26Dh
loc_160AC:                                      //loc_160AC:
    memory(_ds, 0x106D) = _ah;                  //mov ds:106Dh, ah
    memory(_ds, 0x106E) = _al;                  //mov ds:106Eh, al
    memory(_ds, 0x106F) = _bh;                  //mov ds:106Fh, bh
    memory(_ds, 0x1070) = _bl;                  //mov ds:1070h, bl
    _bx = memory16(_ds, 0x207);                 //mov bx, ds:207h
    _bx <<= 1;                                  //shl bx, 1
    _bp = memory16(_ds, _bx + 418);             //mov bp, [bx+1A2h]
    _bx >>= 1;                                  //shr bx, 1
    _si = 0x0000;                               //mov si, 0
loc_160CA:                                      //loc_160CA:
    _ah = memory(_ds, _si + 4205);              //mov ah, [si+106Dh]
    _cl = _ah;                                  //mov cl, ah
    _al = 0x10;                                 //mov al, 10h
    _al <<= _cl;                                //shl al, cl
    _al = _al & memory(_ds, _bp + 124);         //and al, ds:[bp+7Ch]
    if (_al == 0)                               //jz short loc_16101
      goto loc_16101;
    _ah <<= 1;                                  //shl ah, 1
    _ah <<= 1;                                  //shl ah, 1
    _ah <<= 1;                                  //shl ah, 1
    _al = _ah;                                  //mov al, ah
    _al = _al ^ memory(_ds, _bx + 406);         //xor al, [bx+196h]
    if (_al != 0x08)                            //jnz short loc_16109
      goto loc_16109;
    _al = memory(_ds, _bp + 124);               //mov al, ds:[bp+7Ch]
    _dl = 0x00;                                 //mov dl, 0
    _cl = 0x04;                                 //mov cl, 4
loc_160F4:                                      //loc_160F4:
    _rol(_al, 1);                               //rol al, 1
    if (_al >= 0x08)                            //jnb short loc_160FA
      goto loc_160FA;
    _dl += 1;                                   //inc dl
loc_160FA:                                      //loc_160FA:
    if (--_cx)                                  //loop loc_160F4
      goto loc_160F4;
    if (_dl == 0x01)                            //jz short loc_16109
      goto loc_16109;
loc_16101:                                      //loc_16101:
    _si += 1;                                   //inc si
    if (_si != 0x0004)                          //jnz short loc_160CA
      goto loc_160CA;
    _ah = 0xff;                                 //mov ah, 0FFh
loc_16109:                                      //loc_16109:
    memory(_ds, _bx + 410) = _ah;               //mov [bx+19Ah], ah
}

void sub_1610E()
{
    _cx = 0x0018;                               //mov cx, 18h
loc_16111:                                      //loc_16111:
    _al = memoryVideoGet(_es, _si);             //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);              //mov es:[di], al
    _al = memoryVideoGet(_es, _si + 1);         //mov al, es:[si+1]
    memoryVideoSet(_es, _di + 1, _al);          //mov es:[di+1], al
    _al = memoryVideoGet(_es, _si + 2);         //mov al, es:[si+2]
    memoryVideoSet(_es, _di + 2, _al);          //mov es:[di+2], al
    _al = memoryVideoGet(_es, _si + 3);         //mov al, es:[si+3]
    memoryVideoSet(_es, _di + 3, _al);          //mov es:[di+3], al
    _si += 0x0050;                              //add si, 50h
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_16111
      goto loc_16111;
}

void sub_16138()
{
    _cx = 0x0018;                               //mov cx, 18h
loc_1613B:                                      //loc_1613B:
    _al = memory(_es, _si);                     //mov al, es:[si]
    memory(_es, _di) = _al;                     //mov es:[di], al
    _al = memory(_es, _si + 1);                 //mov al, es:[si+1]
    memory(_es, _di + 1) = _al;                 //mov es:[di+1], al
    _al = memory(_es, _si + 2);                 //mov al, es:[si+2]
    memory(_es, _di + 2) = _al;                 //mov es:[di+2], al
    _al = memory(_es, _si + 3);                 //mov al, es:[si+3]
    memory(_es, _di + 3) = _al;                 //mov es:[di+3], al
    _al = memory(_es, _si + 3);                 //mov al, es:[si+3]
    memory(_es, _di + 4) = _al;                 //mov es:[di+4], al
    _si += 0x0050;                              //add si, 50h
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_1613B
      goto loc_1613B;
}

void sub_1616A()
{
    _cx = 0x0030;                               //mov cx, 30h
loc_1616D:                                      //loc_1616D:
    _al = memoryVideoGet(_es, _si);             //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);              //mov es:[di], al
    _al = memoryVideoGet(_es, _si + 1);         //mov al, es:[si+1]
    memoryVideoSet(_es, _di + 1, _al);          //mov es:[di+1], al
    _si += 0x0050;                              //add si, 50h
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_1616D
      goto loc_1616D;
}

void sub_16184()
{
    _cx = 0x0018;                               //mov cx, 18h
loc_16187:                                      //loc_16187:
    _al = memoryVideoGet(_es, _si);             //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);              //mov es:[di], al
    _al = memoryVideoGet(_es, _si + 1);         //mov al, es:[si+1]
    memoryVideoSet(_es, _di + 1, _al);          //mov es:[di+1], al
    _al = memoryVideoGet(_es, _si + 2);         //mov al, es:[si+2]
    memoryVideoSet(_es, _di + 2, _al);          //mov es:[di+2], al
    _al = memoryVideoGet(_es, _si + 3);         //mov al, es:[si+3]
    memoryVideoSet(_es, _di + 3, _al);          //mov es:[di+3], al
    _al = memoryVideoGet(_es, _si + 4);         //mov al, es:[si+4]
    memoryVideoSet(_es, _di + 4, _al);          //mov es:[di+4], al
    _si += 0x0050;                              //add si, 50h
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_16187
      goto loc_16187;
}

void sub_161B6()
{
    _cx = 0x000c;                               //mov cx, 0Ch
loc_161B9:                                      //loc_161B9:
    _al = memoryVideoGet(_es, _si);             //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);              //mov es:[di], al
    _al = memoryVideoGet(_es, _si + 1);         //mov al, es:[si+1]
    memoryVideoSet(_es, _di + 1, _al);          //mov es:[di+1], al
    _al = memoryVideoGet(_es, _si + 2);         //mov al, es:[si+2]
    memoryVideoSet(_es, _di + 2, _al);          //mov es:[di+2], al
    _si += 0x0050;                              //add si, 50h
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_161B9
      goto loc_161B9;
}

void sub_161D8()
{
    _cx = 0x000c;                               //mov cx, 0Ch
loc_161DB:                                      //loc_161DB:
    _al = memoryVideoGet(_es, _si);             //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);              //mov es:[di], al
    _al = memoryVideoGet(_es, _si + 1);         //mov al, es:[si+1]
    memoryVideoSet(_es, _di + 1, _al);          //mov es:[di+1], al
    _al = memoryVideoGet(_es, _si + 2);         //mov al, es:[si+2]
    memoryVideoSet(_es, _di + 2, _al);          //mov es:[di+2], al
    _al = memoryVideoGet(_es, _si + 3);         //mov al, es:[si+3]
    memoryVideoSet(_es, _di + 3, _al);          //mov es:[di+3], al
    _si += 0x0050;                              //add si, 50h
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_161DB
      goto loc_161DB;
}

void sub_16202()
{
    sub_164BF();                                //call sub_164BF
    sub_16431();                                //call sub_16431
    sub_165E5();                                //call sub_165E5
    sub_16919();                                //call sub_16919
    _bx = memory16(_ds, 0x3D3);                 //mov bx, ds:3D3h
    _indirectCall(0, memory16(_ds, _bx+0x50F));
    //_STOP_("goto word ptr [bx+50Fh]");          //jmp word ptr [bx+50Fh]
}

void sub_16216()
{
    sub_16703();                                //call sub_16703
    sub_1680D();                                //call sub_1680D
    sub_16299();                                //call sub_16299
    sub_16332();                                //call sub_16332
    sub_16365();                                //call sub_16365
    sub_16398();                                //call sub_16398
    sub_163CB();                                //call sub_163CB
    sub_163FE();                                //call sub_163FE
}

void sub_1622F()
{
    sub_1623A();                                //call sub_1623A
    sub_162CC();                                //call sub_162CC
    sub_162FF();                                //call sub_162FF
}

void sub_1623A()
{
    if (memory(_ds, 0x1B) == 0x00)              //jz short loc_16246
      goto loc_16246;
    memory(_ds, 0x1B) -= 1;                     //dec byte ptr ds:1Bh
    return;                                     //retn
loc_16246:                                      //loc_16246:
    memory(_ds, 0x1B) = 0x01;                   //mov byte ptr ds:1Bh, 1
    _si = memory16(_ds, 0x51D);                 //mov si, ds:51Dh
    _si = _si + memory16(_ds, 0x1D);            //add si, ds:1Dh
    _di = memory16(_ds, 0x51F);                 //mov di, ds:51Fh
    _cx = 0x000c;                               //mov cx, 0Ch
loc_1625A:                                      //loc_1625A:
    _push(_cx);                                 //push cx
    _cx = 0x0008;                               //mov cx, 8
loc_1625E:                                      //loc_1625E:
    _al = memory(_es, _si);                     //mov al, es:[si]
    memory(_es, _di) = _al;                     //mov es:[di], al
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_1625E
      goto loc_1625E;
    _si += 0x0048;                              //add si, 48h
    _di += 0x0048;                              //add di, 48h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_1625A
      goto loc_1625A;
    _ax = 0x03c0;                               //mov ax, 3C0h
    if (!(memory(_ds, 0x1C) & 0x01))            //jz short loc_1627E
      goto loc_1627E;
    _ax = 0xfc48;                               //mov ax, 0FC48h
loc_1627E:                                      //loc_1627E:
    memory16(_ds, 0x1D) += _ax;                 //add ds:1Dh, ax
    if (memory(_ds, 0x1C) != 0x0a)              //jnz short loc_16294
      goto loc_16294;
    memory(_ds, 0x1C) = 0xff;                   //mov byte ptr ds:1Ch, 0FFh
    memory16(_ds, 0x1D) = 0x0000;               //mov word ptr ds:1Dh, 0
loc_16294:                                      //loc_16294:
    memory(_ds, 0x1C) += 1;                     //inc byte ptr ds:1Ch
}

void sub_16299()
{
    if (memory(_ds, 0x18) == 0x00)              //jz short loc_162A5
      goto loc_162A5;
    memory(_ds, 0x18) -= 1;                     //dec byte ptr ds:18h
    return;                                     //retn
loc_162A5:                                      //loc_162A5:
    memory(_ds, 0x18) = 0x01;                   //mov byte ptr ds:18h, 1
    _si = memory16(_ds, 0x519);                 //mov si, ds:519h
    _si = _si + memory16(_ds, 0x19);            //add si, ds:19h
    _di = memory16(_ds, 0x51B);                 //mov di, ds:51Bh
    sub_1610E();                                //call sub_1610E
    memory16(_ds, 0x19) += 0x0004;              //add word ptr ds:19h, 4
    if (memory16(_ds, 0x19) != 0x0014)          //jnz short locret_162CB
      goto locret_162CB;
    memory16(_ds, 0x19) = 0x0000;               //mov word ptr ds:19h, 0
locret_162CB:                                   //locret_162CB:
    return;
}

void sub_162CC()
{
    if (memory(_ds, 0x1F) == 0x00)              //jz short loc_162D8
      goto loc_162D8;
    memory(_ds, 0x1F) -= 1;                     //dec byte ptr ds:1Fh
    return;                                     //retn
loc_162D8:                                      //loc_162D8:
    memory(_ds, 0x1F) = 0x01;                   //mov byte ptr ds:1Fh, 1
    _si = memory16(_ds, 0x521);                 //mov si, ds:521h
    _si = _si + memory16(_ds, 0x20);            //add si, ds:20h
    _di = memory16(_ds, 0x523);                 //mov di, ds:523h
    sub_1610E();                                //call sub_1610E
    memory16(_ds, 0x20) += 0x0004;              //add word ptr ds:20h, 4
    if (memory16(_ds, 0x20) != 0x0050)          //jnz short locret_162FE
      goto locret_162FE;
    memory16(_ds, 0x20) = 0x0000;               //mov word ptr ds:20h, 0
locret_162FE:                                   //locret_162FE:
    return;
}

void sub_162FF()
{
    if (memory(_ds, 0x22) == 0x00)              //jz short loc_1630B
      goto loc_1630B;
    memory(_ds, 0x22) -= 1;                     //dec byte ptr ds:22h
    return;                                     //retn
loc_1630B:                                      //loc_1630B:
    memory(_ds, 0x22) = 0x05;                   //mov byte ptr ds:22h, 5
    _si = memory16(_ds, 0x525);                 //mov si, ds:525h
    _si = _si + memory16(_ds, 0x23);            //add si, ds:23h
    _di = memory16(_ds, 0x527);                 //mov di, ds:527h
    sub_1610E();                                //call sub_1610E
    memory16(_ds, 0x23) += 0x0004;              //add word ptr ds:23h, 4
    if (memory16(_ds, 0x23) != 0x0018)          //jnz short locret_16331
      goto locret_16331;
    memory16(_ds, 0x23) = 0x0000;               //mov word ptr ds:23h, 0
locret_16331:                                   //locret_16331:
    return;
}

void sub_16332()
{
    if (memory(_ds, 0x25) == 0x00)              //jz short loc_1633E
      goto loc_1633E;
    memory(_ds, 0x25) -= 1;                     //dec byte ptr ds:25h
    return;                                     //retn
loc_1633E:                                      //loc_1633E:
    memory(_ds, 0x25) = 0x01;                   //mov byte ptr ds:25h, 1
    _si = memory16(_ds, 0x529);                 //mov si, ds:529h
    _si = _si + memory16(_ds, 0x26);            //add si, ds:26h
    _di = memory16(_ds, 0x52B);                 //mov di, ds:52Bh
    sub_1610E();                                //call sub_1610E
    memory16(_ds, 0x26) += 0x0004;              //add word ptr ds:26h, 4
    if (memory16(_ds, 0x26) != 0x0010)          //jnz short locret_16364
      goto locret_16364;
    memory16(_ds, 0x26) = 0x0000;               //mov word ptr ds:26h, 0
locret_16364:                                   //locret_16364:
    return;
}

void sub_16365()
{
    if (memory(_ds, 0x28) == 0x00)              //jz short loc_16371
      goto loc_16371;
    memory(_ds, 0x28) -= 1;                     //dec byte ptr ds:28h
    return;                                     //retn
loc_16371:                                      //loc_16371:
    memory(_ds, 0x28) = 0x01;                   //mov byte ptr ds:28h, 1
    _si = memory16(_ds, 0x52D);                 //mov si, ds:52Dh
    _si = _si + memory16(_ds, 0x29);            //add si, ds:29h
    _di = memory16(_ds, 0x52F);                 //mov di, ds:52Fh
    sub_1616A();                                //call sub_1616A
    memory16(_ds, 0x29) += 0x0002;              //add word ptr ds:29h, 2
    if (memory16(_ds, 0x29) != 0x000c)          //jnz short locret_16397
      goto locret_16397;
    memory16(_ds, 0x29) = 0x0000;               //mov word ptr ds:29h, 0
locret_16397:                                   //locret_16397:
    return;
}

void sub_16398()
{
    if (memory(_ds, 0x2B) == 0x00)              //jz short loc_163A4
      goto loc_163A4;
    memory(_ds, 0x2B) -= 1;                     //dec byte ptr ds:2Bh
    return;                                     //retn
loc_163A4:                                      //loc_163A4:
    memory(_ds, 0x2B) = 0x01;                   //mov byte ptr ds:2Bh, 1
    _si = memory16(_ds, 0x531);                 //mov si, ds:531h
    _si = _si + memory16(_ds, 0x2C);            //add si, ds:2Ch
    _di = memory16(_ds, 0x533);                 //mov di, ds:533h
    sub_16184();                                //call sub_16184
    memory16(_ds, 0x2C) += 0x0005;              //add word ptr ds:2Ch, 5
    if (memory16(_ds, 0x2C) != 0x0019)          //jnz short locret_163CA
      goto locret_163CA;
    memory16(_ds, 0x2C) = 0x0000;               //mov word ptr ds:2Ch, 0
locret_163CA:                                   //locret_163CA:
    return;
}

void sub_163CB()
{
    if (memory(_ds, 0x2E) == 0x00)              //jz short loc_163D7
      goto loc_163D7;
    memory(_ds, 0x2E) -= 1;                     //dec byte ptr ds:2Eh
    return;                                     //retn
loc_163D7:                                      //loc_163D7:
    memory(_ds, 0x2E) = 0x01;                   //mov byte ptr ds:2Eh, 1
    _si = memory16(_ds, 0x535);                 //mov si, ds:535h
    _si = _si + memory16(_ds, 0x2F);            //add si, ds:2Fh
    _di = memory16(_ds, 0x537);                 //mov di, ds:537h
    sub_161B6();                                //call sub_161B6
    memory16(_ds, 0x2F) += 0x0003;              //add word ptr ds:2Fh, 3
    if (memory16(_ds, 0x2F) != 0x000c)          //jnz short locret_163FD
      goto locret_163FD;
    memory16(_ds, 0x2F) = 0x0000;               //mov word ptr ds:2Fh, 0
locret_163FD:                                   //locret_163FD:
    return;
}

void sub_163FE()
{
    if (memory(_ds, 0x31) == 0x00)              //jz short loc_1640A
      goto loc_1640A;
    memory(_ds, 0x31) -= 1;                     //dec byte ptr ds:31h
    return;                                     //retn
loc_1640A:                                      //loc_1640A:
    memory(_ds, 0x31) = 0x01;                   //mov byte ptr ds:31h, 1
    _si = memory16(_ds, 0x539);                 //mov si, ds:539h
    _si = _si + memory16(_ds, 0x32);            //add si, ds:32h
    _di = memory16(_ds, 0x53B);                 //mov di, ds:53Bh
    sub_161D8();                                //call sub_161D8
    memory16(_ds, 0x32) += 0x0004;              //add word ptr ds:32h, 4
    if (memory16(_ds, 0x32) != 0x000c)          //jnz short locret_16430
      goto locret_16430;
    memory16(_ds, 0x32) = 0x0000;               //mov word ptr ds:32h, 0
locret_16430:                                   //locret_16430:
    return;
}

void sub_16431()
{
    memory16(_ds, 0x4E) = 0x0044;               //mov word ptr ds:4Eh, 44h
    _bx = 0x0000;                               //mov bx, 0
loc_1643A:                                      //loc_1643A:
    if (memory16(_ds, _bx + 442) == 0x0000)     //jz short loc_16478
      goto loc_16478;
    if (memory16(_ds, _bx + 442) < 0x0008)      //jb short loc_1646B
      goto loc_1646B;
    if (memory16(_ds, _bx + 442) > 0x002e)      //ja short loc_16478
      goto loc_16478;
    if (!(memory16(_ds, _bx + 442) & 0x0001))   //jz short locret_164BE
      goto locret_164BE;
    if (memory16(_ds, _bx + 442) & 0x0001)      //jnz short loc_16462
      goto loc_16462;
    memory16(_ds, 0x4E) = 0x004e;               //mov word ptr ds:4Eh, 4Eh
    goto loc_16478;                             //jmp short loc_16478
loc_16462:                                      //loc_16462:
    memory16(_ds, 0x4E) = 0x0055;               //mov word ptr ds:4Eh, 55h
    goto loc_16478;                             //jmp short loc_16478
    _STOP_("db 90h");                           //db 90h
loc_1646B:                                      //loc_1646B:
    if (memory16(_ds, 0x4E) == 0x0055)          //jz short loc_16478
      goto loc_16478;
    memory16(_ds, 0x4E) = 0x0044;               //mov word ptr ds:4Eh, 44h
loc_16478:                                      //loc_16478:
    _bx += 0x0002;                              //add bx, 2
    if (_bx != 0x0008)                          //jnz short loc_1643A
      goto loc_1643A;
    if (memory16(_ds, 0x4E) != 0x0055)          //jnz short loc_164A3
      goto loc_164A3;
    if (memory16(_ds, 0x4C) == 0x0020)          //jz short locret_164BE
      goto locret_164BE;
    memory16(_ds, 0x4C) += 0x0004;              //add word ptr ds:4Ch, 4
    _si = memory16(_ds, 0x48);                  //mov si, ds:48h
    _si = _si + memory16(_ds, 0x4C);            //add si, ds:4Ch
    _di = memory16(_ds, 0x4A);                  //mov di, ds:4Ah
    sub_1610E();                                //call sub_1610E
    return;                                     //retn
loc_164A3:                                      //loc_164A3:
    if (memory16(_ds, 0x4C) == 0xfffc)          //jz short locret_164BE
      goto locret_164BE;
    _si = memory16(_ds, 0x48);                  //mov si, ds:48h
    _si = _si + memory16(_ds, 0x4C);            //add si, ds:4Ch
    _di = memory16(_ds, 0x4A);                  //mov di, ds:4Ah
    sub_1610E();                                //call sub_1610E
    memory16(_ds, 0x4C) -= 0x0004;              //sub word ptr ds:4Ch, 4
locret_164BE:                                   //locret_164BE:
    return;
}

void sub_164BF()
{
    if (memory(_ds, 0x34) != 0x00)              //jnz short loc_164C9
      goto loc_164C9;
    goto loc_16577;                             //jmp loc_16577
loc_164C9:                                      //loc_164C9:
    memory16(_ds, 0x35) -= 1;                   //dec word ptr ds:35h
    if (memory16(_ds, 0x35) == 0)               //jz short loc_16541
      goto loc_16541;
    _bp = memory16(_ds, 0x190);                 //mov bp, ds:190h
    if (_bp != memory16(_ds, 0x10))             //jnz short locret_16540
      goto locret_16540;
    if (memory(_ds, 0x34) != 0x01)              //jnz short locret_16540
      goto locret_16540;
    memory(_ds, 0x34) = 0x02;                   //mov byte ptr ds:34h, 2
    memory16(_ds, 0x35) = 0x0032;               //mov word ptr ds:35h, 32h
    sub_1826D();                                //call sub_1826D
    _al = _ah;                                  //mov al, ah
    _ax &= 0x0006;                              //and ax, 6
    _si = _ax;                                  //mov si, ax
    _ax = memory16(_ds, _si + 1389);            //mov ax, [si+56Dh]
    _bx = memory16(_ds, _si + 1397);            //mov bx, [si+575h]
    _si = memory16(_ds, 0x39);                  //mov si, ds:39h
    _ax = _ax + memory16(_ds, _si + 1357);      //add ax, [si+54Dh]
    _bx = _bx + memory16(_ds, _si + 1373);      //add bx, [si+55Dh]
    memory16(_ds, 0x12) = _ax;                  //mov ds:12h, ax
    memory16(_ds, 0x211) += _bx;                //add ds:211h, bx
    sub_176FC();                                //call sub_176FC
    _si = memory16(_ds, 0x12);                  //mov si, ds:12h
    memory16(_ds, 0x205) = _si;                 //mov ds:205h, si
    _di = memory16(_ds, 0x37);                  //mov di, ds:37h
    sub_1610E();                                //call sub_1610E
    memory16(_ds, 0x5A8) = 0x0000;              //mov word ptr ds:5A8h, 0
    _lea(_ax, _ds, 0x5D0);                      //lea ax, ds:5D0h
    memory16(_ds, 0x5AA) = _ax;                 //mov ds:5AAh, ax
    _lea(_di, _ds, 0x238);                      //lea di, ds:238h
    if (memory(_ds, 0x217) == 0x01)             //jz short loc_1653E
      goto loc_1653E;
    _lea(_di, _ds, 0x241);                      //lea di, ds:241h
loc_1653E:                                      //loc_1653E:
    memory16(_ds, _di) += 1;                    //inc word ptr [di]
locret_16540:                                   //locret_16540:
    return;                                     //retn
loc_16541:                                      //loc_16541:
    memory(_ds, 0x34) = 0x00;                   //mov byte ptr ds:34h, 0
    sub_1826D();                                //call sub_1826D
    _al = _ah;                                  //mov al, ah
    _ax &= 0x007f;                              //and ax, 7Fh
    _ax += 0x0150;                              //add ax, 150h
    memory16(_ds, 0x35) = _ax;                  //mov ds:35h, ax
    _si = 0x6da0;                               //mov si, 6DA0h
    _bx = memory16(_ds, 0x10);                  //mov bx, ds:10h
    memory(_ds, _bx + 124) &= 0xfb;             //and byte ptr [bx+7Ch], 0FBh
    if (!(memory(_ds, _bx + 124) & 0x08))       //jz short loc_1656A
      goto loc_1656A;
    _si = 0x6da4;                               //mov si, 6DA4h
loc_1656A:                                      //loc_1656A:
    _di = memory16(_ds, 0x37);                  //mov di, ds:37h
    sub_1610E();                                //call sub_1610E
    memory16(_ds, 0x10) = 0x0000;               //mov word ptr ds:10h, 0
loc_16577:                                      //loc_16577:
    memory16(_ds, 0x35) -= 1;                   //dec word ptr ds:35h
    if (memory16(_ds, 0x35) == 0)               //jz short loc_1657E
      goto loc_1657E;
    return;                                     //retn
loc_1657E:                                      //loc_1657E:
    memory(_ds, 0x34) = 0x01;                   //mov byte ptr ds:34h, 1
    sub_1826D();                                //call sub_1826D
    _al = _ah;                                  //mov al, ah
    _ax &= 0x003f;                              //and ax, 3Fh
    _ax += 0x00a8;                              //add ax, 0A8h
    memory16(_ds, 0x35) = _ax;                  //mov ds:35h, ax
    sub_1826D();                                //call sub_1826D
    _al = _ah;                                  //mov al, ah
    _ax &= 0x000e;                              //and ax, 0Eh
    memory16(_ds, 0x39) = _ax;                  //mov ds:39h, ax
    _si = _ax;                                  //mov si, ax
    _ax = memory16(_ds, _si + 1341);            //mov ax, [si+53Dh]
    _si = memory16(_ds, 0x3D5);                 //mov si, ds:3D5h
    _si -= 1;                                   //dec si
    _si <<= 1;                                  //shl si, 1
    _ax = _ax + memory16(_ds, _si + 1389);      //add ax, [si+56Dh]
    memory16(_ds, 0x12) = _ax;                  //mov ds:12h, ax
loc_165B0:                                      //loc_165B0:
    sub_1826D();                                //call sub_1826D
    _bl = _ah;                                  //mov bl, ah
    _bh = 0x00;                                 //mov bh, 0
    _bx += 0x000b;                              //add bx, 0Bh
    if (!(memory(_ds, _bx + 124) & 0x01))       //jz short loc_165B0
      goto loc_165B0;
    if (!(memory(_ds, _bx + 124) & 0x02))       //jz short loc_165CA
      goto loc_165CA;
    goto loc_165B0;                             //jmp short loc_165B0
loc_165CA:                                      //loc_165CA:
    memory16(_ds, 0x10) = _bx;                  //mov ds:10h, bx
    memory(_ds, _bx + 124) |= 0x04;             //or byte ptr [bx+7Ch], 4
    _bx <<= 1;                                  //shl bx, 1
    _si = memory16(_ds, 0x12);                  //mov si, ds:12h
    _di = memory16(_ds, _bx + 1617);            //mov di, [bx+651h]
    memory16(_ds, 0x37) = _di;                  //mov ds:37h, di
    sub_1610E();                                //call sub_1610E
}

void sub_165E5()
{
    _bx = 0x0000;                               //mov bx, 0
loc_165E8:                                      //loc_165E8:
    if (memory16(_ds, _bx + 108) == 0x0000)     //jz short loc_1661B
      goto loc_1661B;
    memory16(_ds, _bx + 108) -= 1;              //dec word ptr [bx+6Ch]
    if (memory16(_ds, _bx + 108) != 0x0032)     //jnz short loc_16604
      goto loc_16604;
    _lea(_si, _ds, 0x105F);                     //lea si, ds:105Fh
    sub_15D7C();                                //call sub_15D7C
    goto loc_1661B;                             //jmp short loc_1661B
loc_16604:                                      //loc_16604:
    if (memory16(_ds, _bx + 108) != 0x0000)     //jnz short loc_1661B
      goto loc_1661B;
    _bx >>= 1;                                  //shr bx, 1
    memory(_ds, _bx + 104) = 0x47;              //mov byte ptr [bx+68h], 47h
    _bx <<= 1;                                  //shl bx, 1
    _lea(_si, _ds, 0x1053);                     //lea si, ds:1053h
    sub_15D7C();                                //call sub_15D7C
loc_1661B:                                      //loc_1661B:
    if (memory16(_ds, _bx + 116) == 0x0000)     //jz short loc_1665C
      goto loc_1665C;
    memory16(_ds, _bx + 116) -= 1;              //dec word ptr [bx+74h]
    if (memory16(_ds, _bx + 116) != 0x0000)     //jnz short loc_1665C
      goto loc_1665C;
    _bx <<= 1;                                  //shl bx, 1
    _di = memory16(_ds, _bx + 0);               //mov di, [bx+0]
    memory16(_ds, _bx + 0) = 0x0000;            //mov word ptr [bx+0], 0
    memory16(_ds, _bx + 2) = 0x0000;            //mov word ptr [bx+2], 0
    _bx >>= 1;                                  //shr bx, 1
    _si = 0x6da0;                               //mov si, 6DA0h
    memory(_ds, _di + 124) &= 0xfb;             //and byte ptr [di+7Ch], 0FBh
    if (!(memory(_ds, _di + 124) & 0x08))       //jz short loc_16653
      goto loc_16653;
    _si = 0x6da4;                               //mov si, 6DA4h
loc_16653:                                      //loc_16653:
    _di <<= 1;                                  //shl di, 1
    _di = memory16(_ds, _di + 1617);            //mov di, [di+651h]
    sub_1610E();                                //call sub_1610E
loc_1665C:                                      //loc_1665C:
    _bx += 0x0002;                              //add bx, 2
    if (_bx != 0x0008)                          //jnz short loc_165E8
      goto loc_165E8;
    _bx = 0x0000;                               //mov bx, 0
loc_16667:                                      //loc_16667:
    if (memory16(_ds, _bx + 80) != 0x00ff)      //jnz short loc_16672
      goto loc_16672;
    goto loc_166F7;                             //jmp loc_166F7
loc_16672:                                      //loc_16672:
    _bp = memory16(_ds, _bx + 450);             //mov bp, [bx+1C2h]
    if (_bp != memory16(_ds, 0x190))            //jnz short loc_166D8
      goto loc_166D8;
    memory(_ds, _bp + 124) &= 0xfd;             //and byte ptr ds:[bp+7Ch], 0FDh
    memory16(_ds, 0x5A8) = 0x0000;              //mov word ptr ds:5A8h, 0
    _lea(_ax, _ds, 0x5BC);                      //lea ax, ds:5BCh
    memory16(_ds, 0x5AA) = _ax;                 //mov ds:5AAh, ax
    memory16(_ds, _bx + 80) = 0x00ff;           //mov word ptr [bx+50h], 0FFh
    memory16(_ds, 0x58) = 0x0000;               //mov word ptr ds:58h, 0
    _bp = 0x0000;                               //mov bp, 0
loc_1669E:                                      //loc_1669E:
    memory(_ds, _bp + 104) = 0x4d;              //mov byte ptr ds:[bp+68h], 4Dh
    sub_1826D();                                //call sub_1826D
    _al = _ah;                                  //mov al, ah
    _ax &= 0x007f;                              //and ax, 7Fh
    _ax += 0x00eb;                              //add ax, 0EBh
    _bp <<= 1;                                  //shl bp, 1
    memory16(_ds, _bp + 108) = _ax;             //mov ds:[bp+6Ch], ax
    _bp >>= 1;                                  //shr bp, 1
    _bp += 1;                                   //inc bp
    if (_bp != 0x0004)                          //jnz short loc_1669E
      goto loc_1669E;
    _si = 0x6da4;                               //mov si, 6DA4h
    _di = memory16(_ds, _bx + 458);             //mov di, [bx+1CAh]
    sub_1610E();                                //call sub_1610E
    _lea(_si, _ds, 0x1059);                     //lea si, ds:1059h
    _bx = 0xffff;                               //mov bx, 0FFFFh
    sub_15D7C();                                //call sub_15D7C
    _si = 0x6da4;                               //mov si, 6DA4h
    goto loc_166F7;                             //jmp short loc_166F7
loc_166D8:                                      //loc_166D8:
    memory(_ds, _bp + 124) |= 0x02;             //or byte ptr ds:[bp+7Ch], 2
    memory16(_ds, _bx + 80) += 0x0004;          //add word ptr [bx+50h], 4
    memory16(_ds, _bx + 80) &= 0x003f;          //and word ptr [bx+50h], 3Fh
    _si = memory16(_ds, 0x57D);                 //mov si, ds:57Dh
    _si = _si + memory16(_ds, _bx + 80);        //add si, [bx+50h]
    _di = memory16(_ds, _bx + 458);             //mov di, [bx+1CAh]
    sub_1610E();                                //call sub_1610E
loc_166F7:                                      //loc_166F7:
    _bx += 0x0002;                              //add bx, 2
    if (_bx == 0x0008)                          //jz short locret_16702
      goto locret_16702;
    goto loc_16667;                             //jmp loc_16667
locret_16702:                                   //locret_16702:
    return;
}

void sub_16703()
{
    if (memory(_ds, 0x3B) != 0x01)              //jnz short loc_1670B
      goto loc_1670B;
    return;                                     //retn
loc_1670B:                                      //loc_1670B:
    if (memory(_ds, 0x3C) != 0x00)              //jnz short loc_16715
      goto loc_16715;
    goto loc_16775;                             //jmp short loc_16775
    _STOP_("db 90h");                           //db 90h
loc_16715:                                      //loc_16715:
    memory16(_ds, 0x3D) -= 1;                   //dec word ptr ds:3Dh
    if (memory16(_ds, 0x3D) == 0)               //jz short loc_1673E
      goto loc_1673E;
    _bp = memory16(_ds, 0x190);                 //mov bp, ds:190h
    if (_bp != memory16(_ds, 0x14))             //jnz short locret_1673D
      goto locret_1673D;
    memory(_ds, 0x3B) = 0x01;                   //mov byte ptr ds:3Bh, 1
    sub_167C7();                                //call sub_167C7
    memory16(_ds, 0x5A8) = 0x0000;              //mov word ptr ds:5A8h, 0
    _lea(_ax, _ds, 0x5D0);                      //lea ax, ds:5D0h
    memory16(_ds, 0x5AA) = _ax;                 //mov ds:5AAh, ax
    goto loc_16751;                             //jmp short loc_16751
    _STOP_("db 90h");                           //db 90h
locret_1673D:                                   //locret_1673D:
    return;                                     //retn
loc_1673E:                                      //loc_1673E:
    memory(_ds, 0x3C) = 0x00;                   //mov byte ptr ds:3Ch, 0
    sub_1826D();                                //call sub_1826D
    _al = _ah;                                  //mov al, ah
    _ax &= 0x001f;                              //and ax, 1Fh
    _ax += 0x001e;                              //add ax, 1Eh
    memory16(_ds, 0x3D) = _ax;                  //mov ds:3Dh, ax
loc_16751:                                      //loc_16751:
    _si = 0x6da0;                               //mov si, 6DA0h
    _bx = memory16(_ds, 0x14);                  //mov bx, ds:14h
    memory(_ds, _bx + 124) &= 0xfb;             //and byte ptr [bx+7Ch], 0FBh
    if (!(memory(_ds, _bx + 124) & 0x08))       //jz short loc_16767
      goto loc_16767;
    _si = 0x6da4;                               //mov si, 6DA4h
loc_16767:                                      //loc_16767:
    _di = memory16(_ds, 0x3F);                  //mov di, ds:3Fh
    sub_1610E();                                //call sub_1610E
    memory16(_ds, 0x14) = 0x0000;               //mov word ptr ds:14h, 0
    return;                                     //retn
loc_16775:                                      //loc_16775:
    memory16(_ds, 0x3D) -= 1;                   //dec word ptr ds:3Dh
    if (memory16(_ds, 0x3D) == 0)               //jz short loc_1677C
      goto loc_1677C;
    return;                                     //retn
loc_1677C:                                      //loc_1677C:
    memory(_ds, 0x3C) = 0x01;                   //mov byte ptr ds:3Ch, 1
    sub_1826D();                                //call sub_1826D
    _al = _ah;                                  //mov al, ah
    _ax &= 0x003f;                              //and ax, 3Fh
    _ax += 0x00a8;                              //add ax, 0A8h
    memory16(_ds, 0x3D) = _ax;                  //mov ds:3Dh, ax
loc_1678F:                                      //loc_1678F:
    sub_1826D();                                //call sub_1826D
    _bl = _ah;                                  //mov bl, ah
    _bh = 0x00;                                 //mov bh, 0
    _bx += 0x000b;                              //add bx, 0Bh
    if (!(memory(_ds, _bx + 124) & 0x01))       //jz short loc_1678F
      goto loc_1678F;
    if (!(memory(_ds, _bx + 124) & 0x02))       //jz short loc_167A9
      goto loc_167A9;
    goto loc_1678F;                             //jmp short loc_1678F
loc_167A9:                                      //loc_167A9:
    memory16(_ds, 0x14) = _bx;                  //mov ds:14h, bx
    memory(_ds, _bx + 124) |= 0x04;             //or byte ptr [bx+7Ch], 4
    _bx <<= 1;                                  //shl bx, 1
    _si = 0xa996;                               //mov si, 0A996h
    memory16(_ds, 0x16) = _si;                  //mov ds:16h, si
    _di = memory16(_ds, _bx + 1617);            //mov di, [bx+651h]
    memory16(_ds, 0x3F) = _di;                  //mov ds:3Fh, di
    sub_1610E();                                //call sub_1610E
}

void sub_167C7()
{
    if (memory16(_ds, 0x3D3) == 0x0000)         //jz short loc_167CF
      goto loc_167CF;
    return;                                     //retn
loc_167CF:                                      //loc_167CF:
    _di = 0x004e;                               //mov di, 4Eh
    if (memory(_ds, 0x64F) == 0x01)             //jz short loc_167E3
      goto loc_167E3;
    if (memory(_ds, 0x217) == 0x02)             //jz short loc_167E3
      goto loc_167E3;
    _di = 0x0012;                               //mov di, 12h
loc_167E3:                                      //loc_167E3:
    _cx = 0x0007;                               //mov cx, 7
    _si = 0xd660;                               //mov si, 0D660h
    _si += 0x003f;                              //add si, 3Fh
    if (memory(_ds, 0x3B) != 0x01)              //jnz short loc_167F6
      goto loc_167F6;
    _si = 0xd695;                               //mov si, 0D695h
loc_167F6:                                      //loc_167F6:
    _al = memoryVideoGet(_es, _si);             //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);              //mov es:[di], al
    _al = memoryVideoGet(_es, _si + 1);         //mov al, es:[si+1]
    memoryVideoSet(_es, _di + 1, _al);          //mov es:[di+1], al
    _si += 0x0050;                              //add si, 50h
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_167F6
      goto loc_167F6;
}

void sub_1680D()
{
    if (memory(_ds, 0x3B) == 0x01)              //jz short loc_16815
      goto loc_16815;
    return;                                     //retn
loc_16815:                                      //loc_16815:
    if (memory(_ds, 0x43) == 0x4f)              //jz short loc_1687D
      goto loc_1687D;
    if (memory(_ds, 0x43) != 0x43)              //jnz short loc_16826
      goto loc_16826;
    goto loc_168B5;                             //jmp loc_168B5
loc_16826:                                      //loc_16826:
    _ax = memory16(_ds, 0x190);                 //mov ax, ds:190h
    _cx = 0x0005;                               //mov cx, 5
    if (memory(_ds, 0x42) == 0x4f)              //jz short loc_16841
      goto loc_16841;
    _lea(_si, _ds, 0x593);                      //lea si, ds:593h
loc_16837:                                      //loc_16837:
    if (_ax == memory16(_ds, _si))              //jz short loc_1687D
      goto loc_1687D;
    _si += 0x0002;                              //add si, 2
    if (--_cx)                                  //loop loc_16837
      goto loc_16837;
    return;                                     //retn
loc_16841:                                      //loc_16841:
    _bx = 0x0000;                               //mov bx, 0
    if (memory(_ds, 0x41) == 0x01)              //jz short loc_16859
      goto loc_16859;
    _lea(_si, _ds, 0x59D);                      //lea si, ds:59Dh
loc_1684F:                                      //loc_1684F:
    if (_ax == memory16(_ds, _si))              //jz short loc_16859
      goto loc_16859;
    _si += 0x0002;                              //add si, 2
    if (--_cx)                                  //loop loc_1684F
      goto loc_1684F;
    return;                                     //retn
loc_16859:                                      //loc_16859:
    _ax = memory16(_ds, _bx + 418);             //mov ax, [bx+1A2h]
    if (_ax == 0x0036)                          //jz short loc_16877
      goto loc_16877;
    if (_ax == 0x004b)                          //jz short loc_16877
      goto loc_16877;
    if (_ax == 0x0060)                          //jz short loc_16877
      goto loc_16877;
    _bx += 0x0002;                              //add bx, 2
    if (_bx != 0x0008)                          //jnz short loc_16859
      goto loc_16859;
    goto loc_168B5;                             //jmp short loc_168B5
    _STOP_("db 90h");                           //db 90h
loc_16877:                                      //loc_16877:
    memory(_ds, 0x41) = 0x01;                   //mov byte ptr ds:41h, 1
    return;                                     //retn
loc_1687D:                                      //loc_1687D:
    memory16(_ds, 0x46) -= 1;                   //dec word ptr ds:46h
    if (memory16(_ds, 0x46) != 0)               //jnz short locret_168F1
      goto locret_168F1;
    memory16(_ds, 0x46) = 0x0002;               //mov word ptr ds:46h, 2
    memory(_ds, 0x43) = 0x4f;                   //mov byte ptr ds:43h, 4Fh
    memory16(_ds, 0x44) += 0x0006;              //add word ptr ds:44h, 6
    sub_168F2();                                //call sub_168F2
    if (memory16(_ds, 0x44) != 0x0030)          //jnz short locret_168F1
      goto locret_168F1;
    _bx = 0x004b;                               //mov bx, 4Bh
    memory(_ds, _bx + 145) |= 0x80;             //or byte ptr [bx+91h], 80h
    memory(_ds, _bx + 103) |= 0x40;             //or byte ptr [bx+67h], 40h
    memory(_ds, 0x42) = 0x4f;                   //mov byte ptr ds:42h, 4Fh
    memory(_ds, 0x43) = 0x4e;                   //mov byte ptr ds:43h, 4Eh
    return;                                     //retn
loc_168B5:                                      //loc_168B5:
    memory16(_ds, 0x46) -= 1;                   //dec word ptr ds:46h
    if (memory16(_ds, 0x46) != 0)               //jnz short locret_168F1
      goto locret_168F1;
    memory16(_ds, 0x46) = 0x0002;               //mov word ptr ds:46h, 2
    memory(_ds, 0x43) = 0x43;                   //mov byte ptr ds:43h, 43h
    memory(_ds, 0x41) = 0x00;                   //mov byte ptr ds:41h, 0
    memory16(_ds, 0x44) -= 0x0006;              //sub word ptr ds:44h, 6
    sub_168F2();                                //call sub_168F2
    _bx = 0x004b;                               //mov bx, 4Bh
    memory(_ds, _bx + 145) &= 0x7f;             //and byte ptr [bx+91h], 7Fh
    memory(_ds, _bx + 103) &= 0xbf;             //and byte ptr [bx+67h], 0BFh
    if (memory16(_ds, 0x44) != 0x0000)          //jnz short locret_168F1
      goto locret_168F1;
    memory(_ds, 0x42) = 0x43;                   //mov byte ptr ds:42h, 43h
    memory(_ds, 0x43) = 0x4e;                   //mov byte ptr ds:43h, 4Eh
locret_168F1:                                   //locret_168F1:
    return;
}

void sub_168F2()
{
    _si = memory16(_ds, 0x58F);                 //mov si, ds:58Fh
    _si = _si + memory16(_ds, 0x44);            //add si, ds:44h
    _di = memory16(_ds, 0x591);                 //mov di, ds:591h
    _cx = 0x0018;                               //mov cx, 18h
loc_16901:                                      //loc_16901:
    _push(_cx);                                 //push cx
    _cx = 0x0006;                               //mov cx, 6
loc_16905:                                      //loc_16905:
    _al = memoryVideoGet(_es, _si);                     //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);                     //mov es:[di], al
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_16905
      goto loc_16905;
    _si += 0x004a;                              //add si, 4Ah
    _di += 0x004a;                              //add di, 4Ah
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_16901
      goto loc_16901;
}

void sub_16919()
{
    if (memory16(_ds, 0x66) != 0x0000)          //jnz short locret_16997
      goto locret_16997;
    if (memory(_ds, 0x62) == 0x01)              //jz short locret_16997
      goto locret_16997;
    if (memory(_ds, 0x5B) == 0x00)              //jz short loc_1694D
      goto loc_1694D;
    _di = memory16(_ds, 0x5C);                  //mov di, ds:5Ch
    if (memory(_ds, 0x5A) > 0x0a)               //ja short loc_1693F
      goto loc_1693F;
    _di += 0x0002;                              //add di, 2
    _di &= 0x0002;                              //and di, 2
loc_1693F:                                      //loc_1693F:
    _di += 0x0004;                              //add di, 4
    _di = memory16(_ds, _di + 474);             //mov di, [di+1DAh]
    memory16(_ds, 0x194) = _di;                 //mov ds:194h, di
    goto loc_1695D;                             //jmp short loc_1695D
    _STOP_("db 90h");                           //db 90h
loc_1694D:                                      //loc_1694D:
    if (memory(_ds, 0x18F) & 0x01)              //jnz short loc_1695D
      goto loc_1695D;
    _al = memory(_ds, 0x18D);                   //mov al, ds:18Dh
    memory(_ds, 0x18E) = _al;                   //mov ds:18Eh, al
    sub_16A4D();                                //call sub_16A4D
loc_1695D:                                      //loc_1695D:
    sub_15EDD();                                //call sub_15EDD
    _si = 0xb860;                               //mov si, 0B860h
    _cx = 0x0010;                               //mov cx, 10h
loc_16966:                                      //loc_16966:
    _push(_cx);                                 //push cx
    _push(_si);                                 //push si
    _di = memory16(_ds, 0x194);                 //mov di, ds:194h
    sub_1610E();                                //call sub_1610E
    if (memory(_ds, 0x42) == 0x43)              //jz short loc_1697E
      goto loc_1697E;
    memory(_ds, 0x43) = 0x43;                   //mov byte ptr ds:43h, 43h
    sub_1680D();                                //call sub_1680D
loc_1697E:                                      //loc_1697E:
    _si = _pop();                               //pop si
    _si += 0x0004;                              //add si, 4
    memory16(_ds, 0x111E) = 0x0064;             //mov word ptr ds:111Eh, 64h
    sub_1778E();                                //call sub_1778E
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_16966
      goto loc_16966;
    memory16(_ds, 0x111E) = 0x05dc;             //mov word ptr ds:111Eh, 5DCh
    sub_1778E();                                //call sub_1778E
locret_16997:                                   //locret_16997:
    return;
}

void sub_16998()
{
    if (memory(_ds, 0x5A) != 0x00)              //jnz short loc_16A02
      goto loc_16A02;
    memory(_ds, 0x5B) = 0x00;                   //mov byte ptr ds:5Bh, 0
    _di = memory16(_ds, 0x194);                 //mov di, ds:194h
    if (_bp != memory16(_ds, 0x1D2))            //jnz short loc_169D1
      goto loc_169D1;
    _cl = memory(_ds, 0x1E2);                   //mov cl, ds:1E2h
    if (_cl == memory(_ds, 0x18D))              //jz short loc_169C2
      goto loc_169C2;
    if (_cl != memory(_ds, 0x18E))              //jnz short locret_16A06
      goto locret_16A06;
    memory(_ds, 0x18D) = _cl;                   //mov ds:18Dh, cl
loc_169C2:                                      //loc_169C2:
    memory16(_ds, 0x5C) = 0x0000;               //mov word ptr ds:5Ch, 0
    _al = memory(_ds, 0x1E7);                   //mov al, ds:1E7h
    memory(_ds, 0x1E6) = _al;                   //mov ds:1E6h, al
    goto loc_169F7;                             //jmp short loc_169F7
    _STOP_("db 90h");                           //db 90h
loc_169D1:                                      //loc_169D1:
    if (_bp != memory16(_ds, 0x1D4))            //jnz short locret_16A06
      goto locret_16A06;
    _cl = memory(_ds, 0x1E3);                   //mov cl, ds:1E3h
    if (_cl == memory(_ds, 0x18D))              //jz short loc_169EB
      goto loc_169EB;
    if (_cl != memory(_ds, 0x18E))              //jnz short locret_16A06
      goto locret_16A06;
    memory(_ds, 0x18D) = _cl;                   //mov ds:18Dh, cl
loc_169EB:                                      //loc_169EB:
    memory16(_ds, 0x5C) = 0x0002;               //mov word ptr ds:5Ch, 2
    _al = memory(_ds, 0x1E8);                   //mov al, ds:1E8h
    memory(_ds, 0x1E6) = _al;                   //mov ds:1E6h, al
loc_169F7:                                      //loc_169F7:
    memory(_ds, 0x5A) = 0x1b;                   //mov byte ptr ds:5Ah, 1Bh
    memory(_ds, 0x5B) = 0x01;                   //mov byte ptr ds:5Bh, 1
    return;                                     //retn
loc_16A02:                                      //loc_16A02:
    memory(_ds, 0x5A) -= 1;                     //dec byte ptr ds:5Ah
locret_16A06:                                   //locret_16A06:
    return;
}

void sub_16A07()
{
    _cl = memory(_ds, 0x1E5);                   //mov cl, ds:1E5h
    memory(_ds, 0x18E) = _cl;                   //mov ds:18Eh, cl
    memory(_ds, 0x18D) = _cl;                   //mov ds:18Dh, cl
    _bp = memory16(_ds, 0x1DC);                 //mov bp, ds:1DCh
    memory16(_ds, 0x194) = _bp;                 //mov ds:194h, bp
    _bp = memory16(_ds, 0x1D8);                 //mov bp, ds:1D8h
    memory16(_ds, 0x190) = _bp;                 //mov ds:190h, bp
    _al = memory(_ds, 0x1E8);                   //mov al, ds:1E8h
    memory(_ds, 0x1E6) = _al;                   //mov ds:1E6h, al
}

void sub_16A2A()
{
    _cl = memory(_ds, 0x1E4);                   //mov cl, ds:1E4h
    memory(_ds, 0x18E) = _cl;                   //mov ds:18Eh, cl
    memory(_ds, 0x18D) = _cl;                   //mov ds:18Dh, cl
    _bp = memory16(_ds, 0x1DA);                 //mov bp, ds:1DAh
    memory16(_ds, 0x194) = _bp;                 //mov ds:194h, bp
    _bp = memory16(_ds, 0x1D6);                 //mov bp, ds:1D6h
    memory16(_ds, 0x190) = _bp;                 //mov ds:190h, bp
    _al = memory(_ds, 0x1E7);                   //mov al, ds:1E7h
    memory(_ds, 0x1E6) = _al;                   //mov ds:1E6h, al
}

void sub_16A4D()
{
    if (memory(_ds, 0x18E) != 0xff)             //jnz short loc_16A57
      goto loc_16A57;
    goto loc_16C87;                             //jmp loc_16C87
loc_16A57:                                      //loc_16A57:
    sub_16CA8();                                //call sub_16CA8
    _bp = memory16(_ds, 0x190);                 //mov bp, ds:190h
    _bl = memory(_ds, 0x18F);                   //mov bl, ds:18Fh
    _bl += 1;                                   //inc bl
    _bl &= 0x07;                                //and bl, 7
    memory(_ds, 0x18F) = _bl;                   //mov ds:18Fh, bl
    if (_bl != 0x00)                            //jnz short loc_16A73
      goto loc_16A73;
    goto loc_16B04;                             //jmp loc_16B04
loc_16A73:                                      //loc_16A73:
    memory(_ds, 0x233) = 0x00;                  //mov byte ptr ds:233h, 0
    _dh = memory(_ds, 0x18D);                   //mov dh, ds:18Dh
    _dl = memory(_ds, 0x18E);                   //mov dl, ds:18Eh
    if (_dh == _dl)                             //jz short loc_16A8B
      goto loc_16A8B;
    _dl = _dl ^ _dh;                            //xor dl, dh
    if (!(_dl & 0x10))                          //jz short loc_16AA6
      goto loc_16AA6;
loc_16A8B:                                      //loc_16A8B:
    if (_dh != 0x00)                            //jnz short loc_16A93
      goto loc_16A93;
    goto loc_16C1A;                             //jmp loc_16C1A
loc_16A93:                                      //loc_16A93:
    if (_dh != 0x08)                            //jnz short loc_16A9B
      goto loc_16A9B;
    goto loc_16C53;                             //jmp loc_16C53
loc_16A9B:                                      //loc_16A9B:
    if (_dh != 0x10)                            //jnz short loc_16AA3
      goto loc_16AA3;
    goto loc_16BF6;                             //jmp loc_16BF6
loc_16AA3:                                      //loc_16AA3:
    goto loc_16BCA;                             //jmp loc_16BCA
loc_16AA6:                                      //loc_16AA6:
    if (memory(_ds, 0x5B) == 0x00)              //jz short loc_16AE6
      goto loc_16AE6;
    memory(_ds, 0x5A) = -memory(_ds, 0x5A);     //neg byte ptr ds:5Ah
    memory(_ds, 0x5A) += 0x1a;                  //add byte ptr ds:5Ah, 1Ah
    _dh = memory(_ds, 0x18E);                   //mov dh, ds:18Eh
    memory(_ds, 0x18D) = _dh;                   //mov ds:18Dh, dh
    memory(_ds, 0x18F) = memory(_ds, 0x18F) ^ 0xff;//xor byte ptr ds:18Fh, 0FFh
    memory(_ds, 0x18F) += 1;                    //inc byte ptr ds:18Fh
    memory(_ds, 0x18F) &= 0x07;                 //and byte ptr ds:18Fh, 7
    _ax = memory16(_ds, 0x190);                 //mov ax, ds:190h
    _bx = memory16(_ds, 0x192);                 //mov bx, ds:192h
    memory16(_ds, 0x190) = _bx;                 //mov ds:190h, bx
    memory16(_ds, 0x192) = _ax;                 //mov ds:192h, ax
    memory16(_ds, 0x5C) += 0x0002;              //add word ptr ds:5Ch, 2
    memory16(_ds, 0x5C) &= 0x0002;              //and word ptr ds:5Ch, 2
    goto loc_16A8B;                             //jmp short loc_16A8B
loc_16AE6:                                      //loc_16AE6:
    _dh = memory(_ds, 0x18E);                   //mov dh, ds:18Eh
    memory(_ds, 0x18D) = _dh;                   //mov ds:18Dh, dh
    memory(_ds, 0x18F) = memory(_ds, 0x18F) ^ 0xff;//xor byte ptr ds:18Fh, 0FFh
    memory(_ds, 0x18F) += 1;                    //inc byte ptr ds:18Fh
    memory(_ds, 0x18F) &= 0x07;                 //and byte ptr ds:18Fh, 7
    if (_bl >= 0x06)                            //jnb short loc_16B04
      goto loc_16B04;
    goto loc_16B8D;                             //jmp loc_16B8D
loc_16B04:                                      //loc_16B04:
    if (memory(_ds, 0x233) == 0x01)             //jz short loc_16B21
      goto loc_16B21;
    memory(_ds, 0x233) = 0x01;                  //mov byte ptr ds:233h, 1
    _lea(_si, _ds, 0x234);                      //lea si, ds:234h
    if (memory(_ds, 0x217) == 0x01)             //jz short loc_16B1F
      goto loc_16B1F;
    _lea(_si, _ds, 0x23D);                      //lea si, ds:23Dh
loc_16B1F:                                      //loc_16B1F:
    memory16(_ds, _si) += 1;                    //inc word ptr [si]
loc_16B21:                                      //loc_16B21:
    if (!(memory(_ds, _bp + 124) & 0x08))       //jz short loc_16B42
      goto loc_16B42;
    memory16(_ds, 0x211) += 1;                  //inc word ptr ds:211h
    sub_176FC();                                //call sub_176FC
    memory16(_ds, 0x66) -= 1;                   //dec word ptr ds:66h
    memory(_ds, _bp + 124) &= 0xf7;             //and byte ptr ds:[bp+7Ch], 0F7h
    if (_bl == 0x00)                            //jz short loc_16B42
      goto loc_16B42;
    goto loc_16B8D;                             //jmp short loc_16B8D
loc_16B42:                                      //loc_16B42:
    sub_16998();                                //call sub_16998
    _dh = memory(_ds, 0x18D);                   //mov dh, ds:18Dh
    if (memory(_ds, 0x5A) != 0x00)              //jnz short loc_16B8D
      goto loc_16B8D;
    _cl = memory(_ds, 0x18E);                   //mov cl, ds:18Eh
    _dh = _cl;                                  //mov dh, cl
    _ror(_cl, 1);                               //ror cl, 1
    _ror(_cl, 1);                               //ror cl, 1
    _ror(_cl, 1);                               //ror cl, 1
    _al = 0x10;                                 //mov al, 10h
    _rol(_al, _cl);                             //rol al, cl
    if (!(memory(_ds, _bp + 124) & _al))        //jz short loc_16B6E
      goto loc_16B6E;
    memory(_ds, 0x18D) = _dh;                   //mov ds:18Dh, dh
    goto loc_16B8D;                             //jmp short loc_16B8D
loc_16B6E:                                      //loc_16B6E:
    _cl = memory(_ds, 0x18D);                   //mov cl, ds:18Dh
    _dh = _cl;                                  //mov dh, cl
    _ror(_cl, 1);                               //ror cl, 1
    _ror(_cl, 1);                               //ror cl, 1
    _ror(_cl, 1);                               //ror cl, 1
    _al = 0x10;                                 //mov al, 10h
    _rol(_al, _cl);                             //rol al, cl
    if (memory(_ds, _bp + 124) & _al)           //jnz short loc_16B8D
      goto loc_16B8D;
    memory(_ds, 0x18F) = 0x07;                  //mov byte ptr ds:18Fh, 7
    goto loc_16C87;                             //jmp loc_16C87
loc_16B8D:                                      //loc_16B8D:
    memory16(_ds, 0x192) = _bp;                 //mov ds:192h, bp
    if (_dh != 0x00)                            //jnz short loc_16BA0
      goto loc_16BA0;
    memory16(_ds, 0x190) += 1;                  //inc word ptr ds:190h
    sub_16CA8();                                //call sub_16CA8
    goto loc_16C1A;                             //jmp short loc_16C1A
loc_16BA0:                                      //loc_16BA0:
    if (_dh != 0x08)                            //jnz short loc_16BAF
      goto loc_16BAF;
    memory16(_ds, 0x190) -= 1;                  //dec word ptr ds:190h
    sub_16CA8();                                //call sub_16CA8
    goto loc_16C53;                             //jmp loc_16C53
loc_16BAF:                                      //loc_16BAF:
    if (_dh != 0x10)                            //jnz short loc_16BBF
      goto loc_16BBF;
    memory16(_ds, 0x190) += 0x0015;             //add word ptr ds:190h, 15h
    sub_16CA8();                                //call sub_16CA8
    goto loc_16BF6;                             //jmp short loc_16BF6
    _STOP_("db 90h");                           //db 90h
loc_16BBF:                                      //loc_16BBF:
    memory16(_ds, 0x190) -= 0x0015;             //sub word ptr ds:190h, 15h
    sub_16CA8();                                //call sub_16CA8
    goto loc_16BCA;                             //jmp short loc_16BCA
loc_16BCA:                                      //loc_16BCA:
    _di = memory16(_ds, 0x194);                 //mov di, ds:194h
    if (memory(_ds, 0x5A) > 0x0a)               //ja short loc_16BE3
      goto loc_16BE3;
    if (memory(_ds, 0x5B) != 0x01)              //jnz short loc_16BE3
      goto loc_16BE3;
    _di -= 0x00f0;                              //sub di, 0F0h
    goto loc_16BEE;                             //jmp short loc_16BEE
    _STOP_("db 90h");                           //db 90h
loc_16BE3:                                      //loc_16BE3:
    _di += 0x0690;                              //add di, 690h
    sub_16F07();                                //call sub_16F07
    _di -= 0x0870;                              //sub di, 870h
loc_16BEE:                                      //loc_16BEE:
    memory16(_ds, 0x194) = _di;                 //mov ds:194h, di
    sub_16CCD();                                //call sub_16CCD
    return;                                     //retn
loc_16BF6:                                      //loc_16BF6:
    _di = memory16(_ds, 0x194);                 //mov di, ds:194h
    if (memory(_ds, 0x5A) > 0x08)               //ja short loc_16C0F
      goto loc_16C0F;
    if (memory(_ds, 0x5B) != 0x01)              //jnz short loc_16C0F
      goto loc_16C0F;
    _di += 0x00f0;                              //add di, 0F0h
    goto loc_16C12;                             //jmp short loc_16C12
    _STOP_("db 90h");                           //db 90h
loc_16C0F:                                      //loc_16C0F:
    sub_16F47();                                //call sub_16F47
loc_16C12:                                      //loc_16C12:
    memory16(_ds, 0x194) = _di;                 //mov ds:194h, di
    sub_16CCD();                                //call sub_16CCD
    return;                                     //retn
loc_16C1A:                                      //loc_16C1A:
    _di = memory16(_ds, 0x194);                 //mov di, ds:194h
    if (memory(_ds, 0x5A) > 0x08)               //ja short loc_16C2C
      goto loc_16C2C;
    if (memory(_ds, 0x5B) == 0x01)              //jz short loc_16C3F
      goto loc_16C3F;
loc_16C2C:                                      //loc_16C2C:
    if (!(memory(_ds, 0x18F) & 0x01))           //jz short loc_16C4F
      goto loc_16C4F;
    sub_16F87();                                //call sub_16F87
    _di += 1;                                   //inc di
    memory16(_ds, 0x194) = _di;                 //mov ds:194h, di
    sub_16CCD();                                //call sub_16CCD
    return;                                     //retn
loc_16C3F:                                      //loc_16C3F:
    if (!(memory(_ds, 0x18F) & 0x01))           //jz short loc_16C4F
      goto loc_16C4F;
    _di += 1;                                   //inc di
    memory16(_ds, 0x194) = _di;                 //mov ds:194h, di
    sub_16CCD();                                //call sub_16CCD
    return;                                     //retn
loc_16C4F:                                      //loc_16C4F:
    sub_16E1B();                                //call sub_16E1B
    return;                                     //retn
loc_16C53:                                      //loc_16C53:
    _di = memory16(_ds, 0x194);                 //mov di, ds:194h
    if (memory(_ds, 0x5A) > 0x08)               //ja short loc_16C65
      goto loc_16C65;
    if (memory(_ds, 0x5B) == 0x01)              //jz short loc_16C73
      goto loc_16C73;
loc_16C65:                                      //loc_16C65:
    if (!(memory(_ds, 0x18F) & 0x01))           //jz short loc_16C7E
      goto loc_16C7E;
    sub_16FAB();                                //call sub_16FAB
    sub_16CCD();                                //call sub_16CCD
    return;                                     //retn
loc_16C73:                                      //loc_16C73:
    if (!(memory(_ds, 0x18F) & 0x01))           //jz short loc_16C7E
      goto loc_16C7E;
    sub_16CCD();                                //call sub_16CCD
    return;                                     //retn
loc_16C7E:                                      //loc_16C7E:
    _di -= 1;                                   //dec di
    memory16(_ds, 0x194) = _di;                 //mov ds:194h, di
    sub_16E1B();                                //call sub_16E1B
    return;                                     //retn
loc_16C87:                                      //loc_16C87:
    _si = memory16(_ds, 0x1E9);                 //mov si, ds:1E9h
    _di = memory16(_ds, 0x194);                 //mov di, ds:194h
    _cx = 0x0018;                               //mov cx, 18h
    if (memory(_ds, 0x18F) & 0x01)              //jnz short loc_16CA4
      goto loc_16CA4;
    if (memory(_ds, 0x18D) & 0x10)              //jnz short loc_16CA4
      goto loc_16CA4;
    sub_16E59();                                //call sub_16E59
    return;                                     //retn
loc_16CA4:                                      //loc_16CA4:
    sub_16D16();                                //call sub_16D16
}

void sub_16CA8()
{
    memory16(_ds, 0x205) = 0x6da0;              //mov word ptr ds:205h, 6DA0h
    _bp = memory16(_ds, 0x192);                 //mov bp, ds:192h
    if (!(memory(_ds, _bp + 124) & 0x04))       //jz short loc_16CBE
      goto loc_16CBE;
    sub_17192();                                //call sub_17192
    return;                                     //retn
loc_16CBE:                                      //loc_16CBE:
    if (!(memory(_ds, _bp + 124) & 0x08))       //jz short locret_16CCC
      goto locret_16CCC;
    memory16(_ds, 0x205) = 0x6da4;              //mov word ptr ds:205h, 6DA4h
locret_16CCC:                                   //locret_16CCC:
    return;
}

void sub_16CCD()
{
    _bh = 0x00;                                 //mov bh, 0
    _bl = memory(_ds, 0x18D);                   //mov bl, ds:18Dh
    _bp = memory16(_ds, 0x190);                 //mov bp, ds:190h
    if (memory(_ds, _bp + 124) & 0x08)          //jnz short loc_16CEA
      goto loc_16CEA;
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _si = memory16(_ds, _bx + 4197);            //mov si, [bx+1065h]
    goto loc_16D08;                             //jmp short loc_16D08
loc_16CEA:                                      //loc_16CEA:
    _si = 0x6d60;                               //mov si, 6D60h
    if (memory(_ds, 0x18F) & 0x01)              //jnz short loc_16CF7
      goto loc_16CF7;
    _si = 0x74c0;                               //mov si, 74C0h
loc_16CF7:                                      //loc_16CF7:
    _bx += _bx;                                 //add bx, bx
    _dh = 0x00;                                 //mov dh, 0
    _dl = memory(_ds, 0x18F);                   //mov dl, ds:18Fh
    _dl &= 0xfe;                                //and dl, 0FEh
    _bx += _dx;                                 //add bx, dx
    _bx += _dx;                                 //add bx, dx
    _si += _bx;                                 //add si, bx
loc_16D08:                                      //loc_16D08:
    memory16(_ds, 0x1E9) = _si;                 //mov ds:1E9h, si
    if (memory(_ds, 0x5A) != 0x00)              //jnz short loc_16D3D
    { loc_16D3D(); return; }
    _cx = 0x0018;                               //mov cx, 18h
//    _STOP_("sp-trace-fail");                    //sub_16CCD endp_failed
//    _STOP_("continues");                        //sub_16D16 proc near
    sub_16D16();
}

void sub_16D16()
{
loc_16D16:
    _al = memoryVideoGet(_es, _si);             //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);              //mov es:[di], al
    _al = memoryVideoGet(_es, _si + 1);         //mov al, es:[si+1]
    memoryVideoSet(_es, _di + 1, _al);          //mov es:[di+1], al
    _al = memoryVideoGet(_es, _si + 2);         //mov al, es:[si+2]
    memoryVideoSet(_es, _di + 2, _al);          //mov es:[di+2], al
    _al = memoryVideoGet(_es, _si + 3);         //mov al, es:[si+3]
    memoryVideoSet(_es, _di + 3, _al);          //mov es:[di+3], al
    _si += 0x0050;                              //add si, 50h
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop sub_16D16
      goto loc_16D16;
}

void loc_16D3D()
{
    memory(_ds, 0x5A) -= 1;                     //dec byte ptr ds:5Ah
    if (memory(_ds, 0x18F) != 0x07)             //jnz short loc_16D53
      goto loc_16D53;
    _lea(_si, _ds, 0x5E);                       //lea si, ds:5Eh
    _si = _si + memory16(_ds, 0x5C);            //add si, ds:5Ch
    _indirectCall(_ds, _si);                    //call word ptr [si]
    return;                                     //retn
loc_16D53:                                      //loc_16D53:
    _cx = 0x0018;                               //mov cx, 18h
    _bx = 0x0004;                               //mov bx, 4
    if (memory(_ds, 0x1E6) > 0x01)              //ja short loc_16DB8
      goto loc_16DB8;
    if (memory(_ds, 0x1E6) == 0x01)             //jz short loc_16D9A
      goto loc_16D9A;
    _dx = _cx;                                  //mov dx, cx
    _cl = memory(_ds, 0x18F);                   //mov cl, ds:18Fh
    _cl += 1;                                   //inc cl
    if (memory(_ds, 0x5A) > 0x0a)               //ja short loc_16D88
      goto loc_16D88;
    _cl = -_cl;                                 //neg cl
    _cl += 0x08;                                //add cl, 8
loc_16D76:                                      //loc_16D76:
    _dl -= 0x03;                                //sub dl, 3
    _si += 0x00f0;                              //add si, 0F0h
    _di += 0x00f0;                              //add di, 0F0h
    if (--_cx)                                  //loop loc_16D76
      goto loc_16D76;
    _cx = _dx;                                  //mov cx, dx
    goto loc_16E00;                             //jmp short loc_16E00
loc_16D88:                                      //loc_16D88:
    _dl -= 0x03;                                //sub dl, 3
    _si += 0x00f0;                              //add si, 0F0h
    _di += 0x00f0;                              //add di, 0F0h
    if (--_cx)                                  //loop loc_16D88
      goto loc_16D88;
    _cx = _dx;                                  //mov cx, dx
    goto loc_16E00;                             //jmp short loc_16E00
loc_16D9A:                                      //loc_16D9A:
    _dl = memory(_ds, 0x18F);                   //mov dl, ds:18Fh
    _dl += _dl;                                 //add dl, dl
    _dl = _dl + memory(_ds, 0x18F);             //add dl, ds:18Fh
    _dl += 0x03;                                //add dl, 3
    if (memory(_ds, 0x5A) > 0x0a)               //ja short loc_16DB3
      goto loc_16DB3;
    _dl = -_dl;                                 //neg dl
    _dl += 0x18;                                //add dl, 18h
loc_16DB3:                                      //loc_16DB3:
    _cl -= _dl;                                 //sub cl, dl
    goto loc_16E00;                             //jmp short loc_16E00
loc_16DB8:                                      //loc_16DB8:
    if (memory(_ds, 0x1E6) == 0x03)             //jz short loc_16DE9
      goto loc_16DE9;
    _bl = memory(_ds, 0x18F);                   //mov bl, ds:18Fh
    _bl >>= 1;                                  //shr bl, 1
    _bl += 1;                                   //inc bl
    _dx = _bx;                                  //mov dx, bx
    if (memory(_ds, 0x5A) < 0x0a)               //jb short loc_16DDC
      goto loc_16DDC;
    _bl = -_bl;                                 //neg bl
    _bl += 0x04;                                //add bl, 4
    _si += _dx;                                 //add si, dx
    _di += _dx;                                 //add di, dx
    goto loc_16E00;                             //jmp short loc_16E00
loc_16DDC:                                      //loc_16DDC:
    _si += 0x0004;                              //add si, 4
    _si -= _bx;                                 //sub si, bx
    _di += 0x0004;                              //add di, 4
    _di -= _bx;                                 //sub di, bx
    goto loc_16E00;                             //jmp short loc_16E00
    _STOP_("db 90h");                           //db 90h
loc_16DE9:                                      //loc_16DE9:
    _bl = memory(_ds, 0x18F);                   //mov bl, ds:18Fh
    _bl >>= 1;                                  //shr bl, 1
    _bl += 1;                                   //inc bl
    if (memory(_ds, 0x5A) < 0x0a)               //jb short loc_16E00
      goto loc_16E00;
    _bl = -_bl;                                 //neg bl
    _bl += 0x04;                                //add bl, 4
    goto loc_16E00;                             //jmp short loc_16E00
loc_16E00:                                      //loc_16E00:
    _push(_cx);                                 //push cx
    _cx = _bx;                                  //mov cx, bx
loc_16E03:                                      //loc_16E03:
    _al = memoryVideoGet(_es, _si);                     //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);                     //mov es:[di], al
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_16E03
      goto loc_16E03;
    _si += 0x0050;                              //add si, 50h
    _si -= _bx;                                 //sub si, bx
    _di += 0x0050;                              //add di, 50h
    _di -= _bx;                                 //sub di, bx
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_16E00
      goto loc_16E00;
}

void sub_16E1B()
{
    _bh = 0x00;                                 //mov bh, 0
    _bl = memory(_ds, 0x18D);                   //mov bl, ds:18Dh
    _ax = _bx;                                  //mov ax, bx
    _bx += _bx;                                 //add bx, bx
    _ax >>= 1;                                  //shr ax, 1
    _bx += _ax;                                 //add bx, ax
    _bp = memory16(_ds, 0x190);                 //mov bp, ds:190h
    if (!(memory(_ds, _bp + 124) & 0x08))       //jz short loc_16E46
      goto loc_16E46;
    _dh = 0x00;                                 //mov dh, 0
    _dl = memory(_ds, 0x18F);                   //mov dl, ds:18Fh
    _dl &= 0xfe;                                //and dl, 0FEh
    _bx += _dx;                                 //add bx, dx
    _bx += _dx;                                 //add bx, dx
    _dx >>= 1;                                  //shr dx, 1
    _bx += _dx;                                 //add bx, dx
loc_16E46:                                      //loc_16E46:
    _si = 0xc760;                               //mov si, 0C760h
    _si += _bx;                                 //add si, bx
    memory16(_ds, 0x1E9) = _si;                 //mov ds:1E9h, si
    if (memory(_ds, 0x5A) != 0x00)              //jnz short loc_16E88
    {
        loc_16E88();
        return;
    }
        //TODO: PARSER
      //_STOP_("goto loc_16E88");
    _cx = 0x0018;                               //mov cx, 18h
//    _STOP_("sp-trace-fail");                    //sub_16E1B endp_failed
//    _STOP_("continues");                        //sub_16E59 proc near
    sub_16E59();
}

void sub_16E59()
{
loc_16E59:
    _al = memoryVideoGet(_es, _si);             //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);              //mov es:[di], al
    _al = memoryVideoGet(_es, _si + 1);         //mov al, es:[si+1]
    memoryVideoSet(_es, _di + 1, _al);          //mov es:[di+1], al
    _al = memoryVideoGet(_es, _si + 2);         //mov al, es:[si+2]
    memoryVideoSet(_es, _di + 2, _al);          //mov es:[di+2], al
    _al = memoryVideoGet(_es, _si + 3);         //mov al, es:[si+3]
    memoryVideoSet(_es, _di + 3, _al);          //mov es:[di+3], al
    _al = memoryVideoGet(_es, _si + 4);         //mov al, es:[si+4]
    memoryVideoSet(_es, _di + 4, _al);          //mov es:[di+4], al
    _si += 0x0050;                              //add si, 50h
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop sub_16E59
      goto loc_16E59;
}

void loc_16E88()
{
    memory(_ds, 0x5A) -= 1;                     //dec byte ptr ds:5Ah
    if (memory(_ds, 0x18F) != 0x07)             //jnz short loc_16E9E
      goto loc_16E9E;
    _lea(_si, _ds, 0x5E);                       //lea si, ds:5Eh
    _si = _si + memory16(_ds, 0x5C);            //add si, ds:5Ch
    _indirectCall(_ds, _si);                    //call word ptr [si]
    return;                                     //retn
loc_16E9E:                                      //loc_16E9E:
    _cx = 0x0018;                               //mov cx, 18h
    _bx = 0x0005;                               //mov bx, 5
    if (memory(_ds, 0x1E6) == 0x03)             //jz short loc_16ED5
      goto loc_16ED5;
    _bl = memory(_ds, 0x18F);                   //mov bl, ds:18Fh
    _bl >>= 1;                                  //shr bl, 1
    _bl += 1;                                   //inc bl
    _dx = _bx;                                  //mov dx, bx
    if (memory(_ds, 0x5A) < 0x0a)               //jb short loc_16EC8
      goto loc_16EC8;
    _bl = -_bl;                                 //neg bl
    _bl += 0x05;                                //add bl, 5
    _si += _dx;                                 //add si, dx
    _di += _dx;                                 //add di, dx
    goto loc_16EEC;                             //jmp short loc_16EEC
loc_16EC8:                                      //loc_16EC8:
    _si += 0x0005;                              //add si, 5
    _si -= _bx;                                 //sub si, bx
    _di += 0x0005;                              //add di, 5
    _di -= _bx;                                 //sub di, bx
    goto loc_16EEC;                             //jmp short loc_16EEC
    _STOP_("db 90h");                           //db 90h
loc_16ED5:                                      //loc_16ED5:
    _bl = memory(_ds, 0x18F);                   //mov bl, ds:18Fh
    _bl >>= 1;                                  //shr bl, 1
    _bl += 1;                                   //inc bl
    if (memory(_ds, 0x5A) <= 0x08)              //jbe short loc_16EEC
      goto loc_16EEC;
    _bl = -_bl;                                 //neg bl
    _bl += 0x05;                                //add bl, 5
    goto loc_16EEC;                             //jmp short loc_16EEC
loc_16EEC:                                      //loc_16EEC:
    _push(_cx);                                 //push cx
    _cx = _bx;                                  //mov cx, bx
loc_16EEF:                                      //loc_16EEF:
    _al = memoryVideoGet(_es, _si);             //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);              //mov es:[di], al
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_16EEF
      goto loc_16EEF;
    _si += 0x0050;                              //add si, 50h
    _si -= _bx;                                 //sub si, bx
    _di += 0x0050;                              //add di, 50h
    _di -= _bx;                                 //sub di, bx
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_16EEC
      goto loc_16EEC;
}

void sub_16F07()
{
    _si = memory16(_ds, 0x205);                 //mov si, ds:205h
    _si += 0x0780;                              //add si, 780h
    _ch = 0x00;                                 //mov ch, 0
    _cl = memory(_ds, 0x18F);                   //mov cl, ds:18Fh
    _cl += 1;                                   //inc cl
loc_16F17:                                      //loc_16F17:
    _si -= 0x00f0;                              //sub si, 0F0h
    if (--_cx)                                  //loop loc_16F17
      goto loc_16F17;
    _cx = 0x0003;                               //mov cx, 3
loc_16F20:                                      //loc_16F20:
    _al = memoryVideoGet(_es, _si);             //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);              //mov es:[di], al
    _al = memoryVideoGet(_es, _si + 1);         //mov al, es:[si+1]
    memoryVideoSet(_es, _di + 1, _al);          //mov es:[di+1], al
    _al = memoryVideoGet(_es, _si + 2);         //mov al, es:[si+2]
    memoryVideoSet(_es, _di + 2, _al);          //mov es:[di+2], al
    _al = memoryVideoGet(_es, _si + 3);         //mov al, es:[si+3]
    memoryVideoSet(_es, _di + 3, _al);          //mov es:[di+3], al
    _si += 0x0050;                              //add si, 50h
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_16F20
      goto loc_16F20;
}

void sub_16F47()
{
    _si = memory16(_ds, 0x205);                 //mov si, ds:205h
    _ch = 0x00;                                 //mov ch, 0
    _cl = memory(_ds, 0x18F);                   //mov cl, ds:18Fh
    _cl += 1;                                   //inc cl
    _si -= 0x00f0;                              //sub si, 0F0h
loc_16F57:                                      //loc_16F57:
    _si += 0x00f0;                              //add si, 0F0h
    if (--_cx)                                  //loop loc_16F57
      goto loc_16F57;
    _cx = 0x0003;                               //mov cx, 3
loc_16F60:                                      //loc_16F60:
    _al = memoryVideoGet(_es, _si);             //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);              //mov es:[di], al
    _al = memoryVideoGet(_es, _si + 1);         //mov al, es:[si+1]
    memoryVideoSet(_es, _di + 1, _al);          //mov es:[di+1], al
    _al = memoryVideoGet(_es, _si + 2);         //mov al, es:[si+2]
    memoryVideoSet(_es, _di + 2, _al);          //mov es:[di+2], al
    _al = memoryVideoGet(_es, _si + 3);         //mov al, es:[si+3]
    memoryVideoSet(_es, _di + 3, _al);          //mov es:[di+3], al
    _si += 0x0050;                              //add si, 50h
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_16F60
      goto loc_16F60;
}

void sub_16F87()
{
    _si = memory16(_ds, 0x205);                 //mov si, ds:205h
    _ch = 0x00;                                 //mov ch, 0
    _cl = memory(_ds, 0x18F);                   //mov cl, ds:18Fh
    _cl >>= 1;                                  //shr cl, 1
    _si += _cx;                                 //add si, cx
    _cx = 0x0018;                               //mov cx, 18h
loc_16F98:                                      //loc_16F98:
    _al = memoryVideoGet(_es, _si);                     //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);                     //mov es:[di], al
    _di += 0x0050;                              //add di, 50h
    _si += 0x0050;                              //add si, 50h
    if (--_cx)                                  //loop loc_16F98
      goto loc_16F98;
    _di -= 0x0780;                              //sub di, 780h
}

void sub_16FAB()
{
    _si = memory16(_ds, 0x205);                 //mov si, ds:205h
    _si += 0x0003;                              //add si, 3
    _ch = 0x00;                                 //mov ch, 0
    _cl = memory(_ds, 0x18F);                   //mov cl, ds:18Fh
    _cl >>= 1;                                  //shr cl, 1
    _si -= _cx;                                 //sub si, cx
    _cx = 0x0018;                               //mov cx, 18h
loc_16FBF:                                      //loc_16FBF:
    _al = memoryVideoGet(_es, _si);                     //mov al, es:[si]
    memoryVideoSet(_es, _di + 4, _al);                 //mov es:[di+4], al
    _di += 0x0050;                              //add di, 50h
    _si += 0x0050;                              //add si, 50h
    if (--_cx)                                  //loop loc_16FBF
      goto loc_16FBF;
    _di -= 0x0780;                              //sub di, 780h
}

void sub_16FD3()
{
    _bx = memory16(_ds, 0x207);                 //mov bx, ds:207h
    _bx <<= 1;                                  //shl bx, 1
    if (memory16(_ds, _bx + 442) == 0x0000)     //jz short loc_16FEC
      goto loc_16FEC;
    memory16(_ds, _bx + 442) -= 1;              //dec word ptr [bx+1BAh]
    if (memory16(_ds, _bx + 442) <= 0x0017)     //jbe short loc_16FEC
      goto loc_16FEC;
    return;                                     //retn
loc_16FEC:                                      //loc_16FEC:
    _bx >>= 1;                                  //shr bx, 1
    _al = memory(_ds, _bx + 410);               //mov al, [bx+19Ah]
    _bx <<= 1;                                  //shl bx, 1
    if (_al != 0xff)                            //jnz short loc_16FFB
      goto loc_16FFB;
    goto loc_1712D;                             //jmp loc_1712D
loc_16FFB:                                      //loc_16FFB:
    memory16(_ds, 0x205) = 0x6da0;              //mov word ptr ds:205h, 6DA0h
    _bp = memory16(_ds, _bx + 426);             //mov bp, [bx+1AAh]
    _bx >>= 1;                                  //shr bx, 1
    if (memory(_ds, _bx + 414) != 0x07)         //jnz short loc_17016
      goto loc_17016;
    _bx <<= 1;                                  //shl bx, 1
    _bp = memory16(_ds, _bx + 418);             //mov bp, [bx+1A2h]
    _bx >>= 1;                                  //shr bx, 1
loc_17016:                                      //loc_17016:
    if (!(memory(_ds, _bp + 124) & 0x04))       //jz short loc_17024
      goto loc_17024;
    sub_17192();                                //call sub_17192
    goto loc_17032;                             //jmp short loc_17032
loc_17024:                                      //loc_17024:
    if (!(memory(_ds, _bp + 124) & 0x08))       //jz short loc_17032
      goto loc_17032;
    memory16(_ds, 0x205) = 0x6da4;              //mov word ptr ds:205h, 6DA4h
loc_17032:                                      //loc_17032:
    _bx <<= 1;                                  //shl bx, 1
    _bp = memory16(_ds, _bx + 418);             //mov bp, [bx+1A2h]
    _bx >>= 1;                                  //shr bx, 1
    _al = memory(_ds, _bx + 414);               //mov al, [bx+19Eh]
    _al += 1;                                   //inc al
    _al &= 0x07;                                //and al, 7
    memory(_ds, _bx + 414) = _al;               //mov [bx+19Eh], al
    _al = memory(_ds, _bx + 414);               //mov al, [bx+19Eh]
    if (_al == 0x00)                            //jz short loc_17055
      goto loc_17055;
    _dh = memory(_ds, _bx + 406);               //mov dh, [bx+196h]
    goto loc_17090;                             //jmp short loc_17090
    _STOP_("db 90h");                           //db 90h
loc_17055:                                      //loc_17055:
    _dh = memory(_ds, _bx + 410);               //mov dh, [bx+19Ah]
    memory(_ds, _bx + 406) = _dh;               //mov [bx+196h], dh
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 426) = _bp;             //mov [bx+1AAh], bp
    if (_dh != 0x00)                            //jnz short loc_1706F
      goto loc_1706F;
    memory16(_ds, _bx + 418) += 1;              //inc word ptr [bx+1A2h]
    goto loc_170E9;                             //jmp short loc_170E9
    _STOP_("db 90h");                           //db 90h
loc_1706F:                                      //loc_1706F:
    if (_dh != 0x08)                            //jnz short loc_1707B
      goto loc_1707B;
    memory16(_ds, _bx + 418) -= 1;              //dec word ptr [bx+1A2h]
    goto loc_1710B;                             //jmp loc_1710B
loc_1707B:                                      //loc_1707B:
    if (_dh != 0x10)                            //jnz short loc_17088
      goto loc_17088;
    memory16(_ds, _bx + 418) += 0x0015;         //add word ptr [bx+1A2h], 15h
    goto loc_170C6;                             //jmp short loc_170C6
loc_17088:                                      //loc_17088:
    memory16(_ds, _bx + 418) -= 0x0015;         //sub word ptr [bx+1A2h], 15h
    goto loc_170AA;                             //jmp short loc_170AA
loc_17090:                                      //loc_17090:
    _bx <<= 1;                                  //shl bx, 1
    if (_dh != 0x00)                            //jnz short loc_1709A
      goto loc_1709A;
    goto loc_170E9;                             //jmp short loc_170E9
loc_1709A:                                      //loc_1709A:
    if (_dh != 0x08)                            //jnz short loc_170A2
      goto loc_170A2;
    goto loc_1710B;                             //jmp short loc_1710B
loc_170A2:                                      //loc_170A2:
    if (_dh != 0x10)                            //jnz short loc_170AA
      goto loc_170AA;
    goto loc_170C6;                             //jmp short loc_170C6
loc_170AA:                                      //loc_170AA:
    _di = memory16(_ds, _bx + 434);             //mov di, [bx+1B2h]
    _di += 0x0690;                              //add di, 690h
    _bx >>= 1;                                  //shr bx, 1
    sub_1752C();                                //call sub_1752C
    _di -= 0x0870;                              //sub di, 870h
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 434) = _di;             //mov [bx+1B2h], di
    _bx >>= 1;                                  //shr bx, 1
    goto loc_17140;                             //jmp short loc_17140
loc_170C6:                                      //loc_170C6:
    _di = memory16(_ds, _bx + 434);             //mov di, [bx+1B2h]
    _di += 0x00f0;                              //add di, 0F0h
    if (memory16(_ds, _bx + 442) > 0x000f)      //ja short loc_170E0
      goto loc_170E0;
    _di -= 0x00f0;                              //sub di, 0F0h
    _bx >>= 1;                                  //shr bx, 1
    sub_1756C();                                //call sub_1756C
    _bx <<= 1;                                  //shl bx, 1
loc_170E0:                                      //loc_170E0:
    memory16(_ds, _bx + 434) = _di;             //mov [bx+1B2h], di
    _bx >>= 1;                                  //shr bx, 1
    goto loc_17140;                             //jmp short loc_17140
    _STOP_("db 90h");                           //db 90h
loc_170E9:                                      //loc_170E9:
    _di = memory16(_ds, _bx + 434);             //mov di, [bx+1B2h]
    _bx >>= 1;                                  //shr bx, 1
    if (memory(_ds, _bx + 414) & 0x01)          //jnz short loc_170FC
      goto loc_170FC;
    sub_174D1();                                //call sub_174D1
    goto loc_17143;                             //jmp short loc_17143
loc_170FC:                                      //loc_170FC:
    sub_175AC();                                //call sub_175AC
    _di += 1;                                   //inc di
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 434) = _di;             //mov [bx+1B2h], di
    _bx >>= 1;                                  //shr bx, 1
    goto loc_17140;                             //jmp short loc_17140
    _STOP_("db 90h");                           //db 90h
loc_1710B:                                      //loc_1710B:
    _di = memory16(_ds, _bx + 434);             //mov di, [bx+1B2h]
    _bx >>= 1;                                  //shr bx, 1
    if (memory(_ds, _bx + 414) & 0x01)          //jnz short loc_17127
      goto loc_17127;
    _di -= 1;                                   //dec di
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 434) = _di;             //mov [bx+1B2h], di
    _bx >>= 1;                                  //shr bx, 1
    sub_174D1();                                //call sub_174D1
    goto loc_17143;                             //jmp short loc_17143
    _STOP_("db 90h");                           //db 90h
loc_17127:                                      //loc_17127:
    sub_175D0();                                //call sub_175D0
    goto loc_17140;                             //jmp short loc_17140
    _STOP_("db 90h");                           //db 90h
loc_1712D:                                      //loc_1712D:
    _di = memory16(_ds, _bx + 434);             //mov di, [bx+1B2h]
    _bx >>= 1;                                  //shr bx, 1
    if (memory(_ds, _bx + 414) & 0x01)          //jnz short loc_17140
      goto loc_17140;
    sub_174D1();                                //call sub_174D1
    goto loc_17143;                             //jmp short loc_17143
loc_17140:                                      //loc_17140:
    sub_1741F();                                //call sub_1741F
loc_17143:                                      //loc_17143:
    _bx = memory16(_ds, 0x207);                 //mov bx, ds:207h
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _bx + 434);             //mov ax, [bx+1B2h]
    _ax += 0x0693;                              //add ax, 693h
    _ax = _ax - memory16(_ds, 0x194);           //sub ax, ds:194h
    if (_ax <= 0x0d20)                          //jbe short loc_1715A
      goto loc_1715A;
    return;                                     //retn
loc_1715A:                                      //loc_1715A:
    if (_ax <= 0x0006)                          //jbe short loc_17181
      goto loc_17181;
    if (_ax == 0x0690)                          //jz short loc_17181
      goto loc_17181;
    if (_ax == 0x0696)                          //jz short loc_17181
      goto loc_17181;
    _dx = 0x00f1;                               //mov dx, 0F1h
    _cx = 0x000e;                               //mov cx, 0Eh
loc_1716F:                                      //loc_1716F:
    if (_ax < _dx)                              //jb short locret_17180
      goto locret_17180;
    _dx += 0x0004;                              //add dx, 4
    if (_ax < _dx)                              //jb short loc_17181
      goto loc_17181;
    _dx += 0x00ec;                              //add dx, 0ECh
    if (--_cx)                                  //loop loc_1716F
      goto loc_1716F;
locret_17180:                                   //locret_17180:
    return;                                     //retn
loc_17181:                                      //loc_17181:
    _bx >>= 1;                                  //shr bx, 1
    if (memory(_ds, _bx + 104) == 0x4d)         //jz short loc_1718E
      goto loc_1718E;
    sub_171AF();                                //call sub_171AF
    return;                                     //retn
loc_1718E:                                      //loc_1718E:
    sub_172F7();                                //call sub_172F7
}

void sub_17192()
{
    _push(_bx);                                 //push bx
    _bx = 0x0000;                               //mov bx, 0
loc_17196:                                      //loc_17196:
    if (_bp == memory16(_ds, _bx + 0))          //jz short loc_171A5
      goto loc_171A5;
    _bx += 0x0004;                              //add bx, 4
    if (_bx != 0x0018)                          //jnz short loc_17196
      goto loc_17196;
    return;                                     //retn
loc_171A5:                                      //loc_171A5:
    _bx = memory16(_ds, _bx + 2);               //mov bx, [bx+2]
    memory16(_ds, 0x205) = _bx;                 //mov ds:205h, bx
    _bx = _pop();                               //pop bx
    return;                                     //retn
    _STOP_("sp-trace-fail");                    //sub_17192 endp_failed
    _STOP_("continues");                        //sub_171AF proc near
}

void sub_171AF()
{
    _bx = 0x0000;                               //mov bx, 0
    sub_15DFA();                                //call sub_15DFA
    _si = memory16(_ds, 0x3D3);                 //mov si, ds:3D3h
    _si = memory16(_ds, _si + 3801);            //mov si, [si+0ED9h]
    memory16(_ds, 0x203) = _si;                 //mov ds:203h, si
    _si += 0x0009;                              //add si, 9
    _lea(_di, _ds, 0x196);                      //lea di, ds:196h
    _cx = 0x0053;                               //mov cx, 53h
    _cx -= 0x0027;                              //sub cx, 27h
    sub_15DAA();                                //call sub_15DAA
    _lea(_si, _ds, 0x1053);                     //lea si, ds:1053h
    _bx = 0xffff;                               //mov bx, 0FFFFh
    sub_15D7C();                                //call sub_15D7C
    memory16(_ds, 0x5A8) = 0x0000;              //mov word ptr ds:5A8h, 0
    _lea(_ax, _ds, 0x5E4);                      //lea ax, ds:5E4h
    memory16(_ds, 0x5AA) = _ax;                 //mov ds:5AAh, ax
    _si = 0xb0e0;                               //mov si, 0B0E0h
    _di = memory16(_ds, 0x194);                 //mov di, ds:194h
    _cx = 0x0010;                               //mov cx, 10h
    if (memory(_ds, 0x5B) == 0x00)              //jz short loc_17211
      goto loc_17211;
    _di = memory16(_ds, 0x5C);                  //mov di, ds:5Ch
    if (memory(_ds, 0x5A) > 0x0a)               //ja short loc_1720A
      goto loc_1720A;
    _di += 0x0002;                              //add di, 2
    _di &= 0x0002;                              //and di, 2
loc_1720A:                                      //loc_1720A:
    _di += 0x0004;                              //add di, 4
    _di = memory16(_ds, _di + 474);             //mov di, [di+1DAh]
loc_17211:                                      //loc_17211:
    _push(_cx);                                 //push cx
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    sub_1610E();                                //call sub_1610E
    sub_15ECC();                                //call sub_15ECC
    sub_16431();                                //call sub_16431
    memory16(_ds, 0x111E) = 0x0064;             //mov word ptr ds:111Eh, 64h
    sub_1778E();                                //call sub_1778E
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _si += 0x0004;                              //add si, 4
    _cx = _pop();                               //pop cx
    _sync();
    if (--_cx)                                  //loop loc_17211
      goto loc_17211;
    _cx = 0x0005;                               //mov cx, 5
loc_17231:                                      //loc_17231:
    _push(_cx);                                 //push cx
    sub_15ECC();                                //call sub_15ECC
    memory16(_ds, 0x111E) = 0x0064;             //mov word ptr ds:111Eh, 64h
    sub_1778E();                                //call sub_1778E
    _sync();
    _cx = _pop();                               //pop cx
    if (_al == 0x1b)                            //jz short locret_172B0
      goto locret_172B0;
    if (--_cx)                                  //loop loc_17231
      goto loc_17231;
    memory16(_ds, 0x111E) = 0x05dc;             //mov word ptr ds:111Eh, 5DCh
    sub_17805();                                //call sub_17805
    _si = 0x6da0;                               //mov si, 6DA0h
    _bx = memory16(_ds, 0x190);                 //mov bx, ds:190h
    if (!(memory(_ds, _bx + 124) & 0x08))       //jz short loc_1725F
      goto loc_1725F;
    _si = 0x6da4;                               //mov si, 6DA4h
loc_1725F:                                      //loc_1725F:
    sub_1610E();                                //call sub_1610E
    if (memory(_ds, 0x34) == 0x00)              //jz short loc_17274
      goto loc_17274;
    _si = memory16(_ds, 0x12);                  //mov si, ds:12h
    _di = memory16(_ds, 0x37);                  //mov di, ds:37h
    sub_1610E();                                //call sub_1610E
loc_17274:                                      //loc_17274:
    if (memory(_ds, 0x64F) != 0x02)             //jnz short loc_17281
      goto loc_17281;
    memory(_ds, 0x64) = 0x01;                   //mov byte ptr ds:64h, 1
    return;                                     //retn
loc_17281:                                      //loc_17281:
    if (memory(_ds, 0x253) == 0x01)             //jz short loc_1729A
      goto loc_1729A;
    memory16(_ds, 0x224) -= 1;                  //dec word ptr ds:224h
    if (memory16(_ds, 0x224) != 0)              //jnz short loc_1729A
      goto loc_1729A;
    memory16(_ds, 0x66) = 0x0000;               //mov word ptr ds:66h, 0
    memory(_ds, 0x62) = 0x01;                   //mov byte ptr ds:62h, 1
    return;                                     //retn
loc_1729A:                                      //loc_1729A:
    sub_1444F();                                //call sub_1444F
    if (memory16(_ds, 0x224) == 0x0000)         //jz short locret_172B0
      goto locret_172B0;
    sub_172B1();                                //call sub_172B1
    memory16(_ds, 0x111E) = 0x0bb8;             //mov word ptr ds:111Eh, 0BB8h
    sub_17805();                                //call sub_17805
locret_172B0:                                   //locret_172B0:
    return;
}

void sub_172B1()
{
    _di = 0x0460;                               //mov di, 460h
    _al = memory(_ds, 0x64F);                   //mov al, ds:64Fh
    _al = _al + memory(_ds, 0x217);             //add al, ds:217h
    if (_al == 0x03)                            //jz short loc_172C2
      goto loc_172C2;
    _di = 0x049c;                               //mov di, 49Ch
loc_172C2:                                      //loc_172C2:
    _ax = memory16(_ds, 0x224);                 //mov ax, ds:224h
    _ax -= 1;                                   //dec ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _si = 0xd69f;                               //mov si, 0D69Fh
    if (memory16(_ds, 0x3D3) != 0x0002)         //jnz short loc_172D9
      goto loc_172D9;
    _si = 0xad48;                               //mov si, 0AD48h
loc_172D9:                                      //loc_172D9:
    _cx = 0x0001;                               //mov cx, 1
    sub_176C7();                                //call sub_176C7
}

void loc_172E6()
{
loc_172E6:
    memory(_es, _di) = _al;                     //mov es:[di], al
    memory(_es, _di + 1) = _al;                 //mov es:[di+1], al
    memory(_es, _di + 2) = _al;                 //mov es:[di+2], al
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_172E6
      goto loc_172E6;
}

void sub_172F7()
{
    _lea(_di, _ds, 0x236);                      //lea di, ds:236h
    if (memory(_ds, 0x217) == 0x01)             //jz short loc_17306
      goto loc_17306;
    _lea(_di, _ds, 0x23F);                      //lea di, ds:23Fh
loc_17306:                                      //loc_17306:
    memory16(_ds, _di) += 1;                    //inc word ptr [di]
    memory16(_ds, 0x5A8) = 0x0000;              //mov word ptr ds:5A8h, 0
    _lea(_ax, _ds, 0x610);                      //lea ax, ds:610h
    memory16(_ds, 0x5AA) = _ax;                 //mov ds:5AAh, ax
    _bx = memory16(_ds, 0x207);                 //mov bx, ds:207h
    memory(_ds, _bx + 104) = 0x47;              //mov byte ptr [bx+68h], 47h
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 108) = 0x0000;          //mov word ptr [bx+6Ch], 0
    _lea(_si, _ds, 0x1053);                     //lea si, ds:1053h
    _push(_bx);                                 //push bx
    sub_15D7C();                                //call sub_15D7C
    _bx = _pop();                               //pop bx
    sub_1826D();                                //call sub_1826D
    _al = _ah;                                  //mov al, ah
    _ax &= 0x00ff;                              //and ax, 0FFh
    _ax += 0x0064;                              //add ax, 64h
    memory16(_ds, _bx + 442) = _ax;             //mov [bx+1BAh], ax
    _si = 0x6da0;                               //mov si, 6DA0h
    _di = memory16(_ds, _bx + 434);             //mov di, [bx+1B2h]
    _bx >>= 1;                                  //shr bx, 1
    if (memory(_ds, _bx + 414) & 0x01)          //jnz short loc_1735B
      goto loc_1735B;
    if (memory(_ds, _bx + 406) & 0x10)          //jnz short loc_1735B
      goto loc_1735B;
    sub_16138();                                //call sub_16138
    goto loc_1735E;                             //jmp short loc_1735E
    _STOP_("db 90h");                           //db 90h
loc_1735B:                                      //loc_1735B:
    sub_1610E();                                //call sub_1610E
loc_1735E:                                      //loc_1735E:
    _bx <<= 1;                                  //shl bx, 1
    memory16(_ds, _bx + 116) = 0x0032;          //mov word ptr [bx+74h], 32h
    _si = memory16(_ds, 0x58);                  //mov si, ds:58h
    _dx = memory16(_ds, _si + 1415);            //mov dx, [si+587h]
    _si = memory16(_ds, _si + 1407);            //mov si, [si+57Fh]
    _di = memory16(_ds, _bx + 418);             //mov di, [bx+1A2h]
    _bx <<= 1;                                  //shl bx, 1
    _bp = memory16(_ds, _bx + 0);               //mov bp, [bx+0]
    memory(_ds, _bp + 124) &= 0xfb;             //and byte ptr ds:[bp+7Ch], 0FBh
    memory16(_ds, _bx + 0) = _di;               //mov [bx+0], di
    memory16(_ds, _bx + 2) = _si;               //mov [bx+2], si
    _bx >>= 1;                                  //shr bx, 1
    memory(_ds, _di + 124) |= 0x04;             //or byte ptr [di+7Ch], 4
    _di <<= 1;                                  //shl di, 1
    _di = memory16(_ds, _di + 1617);            //mov di, [di+651h]
    sub_1610E();                                //call sub_1610E
    _di = memory16(_ds, _bx + 426);             //mov di, [bx+1AAh]
    if (!(memory(_ds, _di + 124) & 0x08))       //jz short loc_173B1
      goto loc_173B1;
    _di <<= 1;                                  //shl di, 1
    _di = memory16(_ds, _di + 1617);            //mov di, [di+651h]
    _si = 0x6da4;                               //mov si, 6DA4h
    sub_1610E();                                //call sub_1610E
loc_173B1:                                      //loc_173B1:
    _bx >>= 1;                                  //shr bx, 1
    _cx = 0x0003;                               //mov cx, 3
    _si = memory16(_ds, 0x203);                 //mov si, ds:203h
    _si += 0x0009;                              //add si, 9
    _lea(_di, _ds, 0x196);                      //lea di, ds:196h
    _di += _bx;                                 //add di, bx
loc_173C3:                                      //loc_173C3:
    _al = memory(_ds, _si);                     //mov al, [si]
    memory(_ds, _di) = _al;                     //mov [di], al
    _si += 0x0004;                              //add si, 4
    _di += 0x0004;                              //add di, 4
    if (--_cx)                                  //loop loc_173C3
      goto loc_173C3;
    _di += _bx;                                 //add di, bx
    _cx = 0x0003;                               //mov cx, 3
loc_173D4:                                      //loc_173D4:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    memory16(_ds, _di) = _ax;                   //mov [di], ax
    _si += 0x0008;                              //add si, 8
    _di += 0x0008;                              //add di, 8
    if (--_cx)                                  //loop loc_173D4
      goto loc_173D4;
    memory16(_ds, 0x211) += _dx;                //add ds:211h, dx
    sub_176FC();                                //call sub_176FC
    memory16(_ds, 0x58) += 0x0002;              //add word ptr ds:58h, 2
    _bp = 0x0000;                               //mov bp, 0
    if (memory16(_ds, 0x58) == 0x0008)          //jz short loc_173F7
      goto loc_173F7;
    return;                                     //retn
loc_173F7:                                      //loc_173F7:
    memory16(_ds, 0x58) = 0x0000;               //mov word ptr ds:58h, 0
    memory(_ds, _bp + 104) = 0x47;              //mov byte ptr ds:[bp+68h], 47h
    _bp <<= 1;                                  //shl bp, 1
    memory16(_ds, _bp + 108) = 0x0000;          //mov word ptr ds:[bp+6Ch], 0
    _bp >>= 1;                                  //shr bp, 1
    _bp += 1;                                   //inc bp
    if (_bp != 0x0004)                          //jnz short loc_173F7
      goto loc_173F7;
    _lea(_si, _ds, 0x1053);                     //lea si, ds:1053h
    _bx = 0xffff;                               //mov bx, 0FFFFh
    sub_15D7C();                                //call sub_15D7C
}

void sub_1741F()
{
    _dh = 0x00;                                 //mov dh, 0
    _dl = memory(_ds, _bx + 414);               //mov dl, [bx+19Eh]
    _bx <<= 1;                                  //shl bx, 1
    _si = memory16(_ds, _bx + 491);             //mov si, [bx+1EBh]
    _bx >>= 1;                                  //shr bx, 1
    _ah = _dh;                                  //mov ah, dh
    _al = memory(_ds, _bx + 406);               //mov al, [bx+196h]
    if (!(_al & 0x10))                          //jz short loc_17447
      goto loc_17447;
    _si += 0x0020;                              //add si, 20h
    if (_dl & 0x01)                             //jnz short loc_17447
      goto loc_17447;
    _bx <<= 1;                                  //shl bx, 1
    _si = memory16(_ds, _bx + 499);             //mov si, [bx+1F3h]
    _bx >>= 1;                                  //shr bx, 1
loc_17447:                                      //loc_17447:
    _dl &= 0xfe;                                //and dl, 0FEh
    _dx <<= 1;                                  //shl dx, 1
    _si += _dx;                                 //add si, dx
    _al &= 0x08;                                //and al, 8
    _ax <<= 1;                                  //shl ax, 1
    _si += _ax;                                 //add si, ax
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _bx + 442);             //mov ax, [bx+1BAh]
    _bx >>= 1;                                  //shr bx, 1
    if (_ax > 0x0010)                           //ja short loc_1748B
      goto loc_1748B;
    _cx = 0x0018;                               //mov cx, 18h
loc_17464:                                      //loc_17464:
    _al = memoryVideoGet(_es, _si);             //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);              //mov es:[di], al
    _al = memoryVideoGet(_es, _si + 1);         //mov al, es:[si+1]
    memoryVideoSet(_es, _di + 1, _al);          //mov es:[di+1], al
    _al = memoryVideoGet(_es, _si + 2);         //mov al, es:[si+2]
    memoryVideoSet(_es, _di + 2, _al);          //mov es:[di+2], al
    _al = memoryVideoGet(_es, _si + 3);         //mov al, es:[si+3]
    memoryVideoSet(_es, _di + 3, _al);          //mov es:[di+3], al
    _si += 0x0050;                              //add si, 50h
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_17464
      goto loc_17464;
    return;                                     //retn
loc_1748B:                                      //loc_1748B:
    _cx = 0x0018;                               //mov cx, 18h
    _dx = _cx;                                  //mov dx, cx
    _cl = memory(_ds, _bx + 414);               //mov cl, [bx+19Eh]
    _cl += 1;                                   //inc cl
    _cl = -_cl;                                 //neg cl
    _cl += 0x08;                                //add cl, 8
loc_1749B:                                      //loc_1749B:
    _dl -= 0x03;                                //sub dl, 3
    _si += 0x00f0;                              //add si, 0F0h
    _di += 0x00f0;                              //add di, 0F0h
    if (--_cx)                                  //loop loc_1749B
      goto loc_1749B;
    _cx = _dx;                                  //mov cx, dx
loc_174AA:                                      //loc_174AA:
    _al = memoryVideoGet(_es, _si);             //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);              //mov es:[di], al
    _al = memoryVideoGet(_es, _si + 1);         //mov al, es:[si+1]
    memoryVideoSet(_es, _di + 1, _al);          //mov es:[di+1], al
    _al = memoryVideoGet(_es, _si + 2);         //mov al, es:[si+2]
    memoryVideoSet(_es, _di + 2, _al);          //mov es:[di+2], al
    _al = memoryVideoGet(_es, _si + 3);         //mov al, es:[si+3]
    memoryVideoSet(_es, _di + 3, _al);          //mov es:[di+3], al
    _si += 0x0050;                              //add si, 50h
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_174AA
      goto loc_174AA;
}

void sub_174D1()
{
    _ch = 0x00;                                 //mov ch, 0
    _cl = memory(_ds, _bx + 406);               //mov cl, [bx+196h]
    _ax = _cx;                                  //mov ax, cx
    _cx += _cx;                                 //add cx, cx
    _ax >>= 1;                                  //shr ax, 1
    _cx += _ax;                                 //add cx, ax
    _dh = 0x00;                                 //mov dh, 0
    _dl = memory(_ds, _bx + 414);               //mov dl, [bx+19Eh]
    _dl &= 0xfe;                                //and dl, 0FEh
    _cx += _dx;                                 //add cx, dx
    _cx += _dx;                                 //add cx, dx
    _dx >>= 1;                                  //shr dx, 1
    _cx += _dx;                                 //add cx, dx
    _bx <<= 1;                                  //shl bx, 1
    _si = memory16(_ds, _bx + 507);             //mov si, [bx+1FBh]
    _bx >>= 1;                                  //shr bx, 1
    _si += _cx;                                 //add si, cx
    _cx = 0x0018;                               //mov cx, 18h
loc_174FD:                                      //loc_174FD:
    _al = memoryVideoGet(_es, _si);             //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);              //mov es:[di], al
    _al = memoryVideoGet(_es, _si + 1);         //mov al, es:[si+1]
    memoryVideoSet(_es, _di + 1, _al);          //mov es:[di+1], al
    _al = memoryVideoGet(_es, _si + 2);         //mov al, es:[si+2]
    memoryVideoSet(_es, _di + 2, _al);          //mov es:[di+2], al
    _al = memoryVideoGet(_es, _si + 3);         //mov al, es:[si+3]
    memoryVideoSet(_es, _di + 3, _al);          //mov es:[di+3], al
    _al = memoryVideoGet(_es, _si + 4);         //mov al, es:[si+4]
    memoryVideoSet(_es, _di + 4, _al);          //mov es:[di+4], al
    _si += 0x0050;                              //add si, 50h
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_174FD
      goto loc_174FD;
}

void sub_1752C()
{
    _si = memory16(_ds, 0x205);                 //mov si, ds:205h
    _si += 0x0780;                              //add si, 780h
    _ch = 0x00;                                 //mov ch, 0
    _cl = memory(_ds, _bx + 414);               //mov cl, [bx+19Eh]
    _cl += 1;                                   //inc cl
loc_1753C:                                      //loc_1753C:
    _si -= 0x00f0;                              //sub si, 0F0h
    if (--_cx)                                  //loop loc_1753C
      goto loc_1753C;
    _cx = 0x0003;                               //mov cx, 3
loc_17545:                                      //loc_17545:
    _al = memoryVideoGet(_es, _si);             //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);              //mov es:[di], al
    _al = memoryVideoGet(_es, _si + 1);         //mov al, es:[si+1]
    memoryVideoSet(_es, _di + 1, _al);          //mov es:[di+1], al
    _al = memoryVideoGet(_es, _si + 2);         //mov al, es:[si+2]
    memoryVideoSet(_es, _di + 2, _al);          //mov es:[di+2], al
    _al = memoryVideoGet(_es, _si + 3);         //mov al, es:[si+3]
    memoryVideoSet(_es, _di + 3, _al);          //mov es:[di+3], al
    _si += 0x0050;                              //add si, 50h
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_17545
      goto loc_17545;
}

void sub_1756C()
{
    _si = memory16(_ds, 0x205);                 //mov si, ds:205h
    _ch = 0x00;                                 //mov ch, 0
    _cl = memory(_ds, _bx + 414);               //mov cl, [bx+19Eh]
    _cl += 1;                                   //inc cl
    _si -= 0x00f0;                              //sub si, 0F0h
loc_1757C:                                      //loc_1757C:
    _si += 0x00f0;                              //add si, 0F0h
    if (--_cx)                                  //loop loc_1757C
      goto loc_1757C;
    _cx = 0x0003;                               //mov cx, 3
loc_17585:                                      //loc_17585:
    _al = memoryVideoGet(_es, _si);             //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);              //mov es:[di], al
    _al = memoryVideoGet(_es, _si + 1);         //mov al, es:[si+1]
    memoryVideoSet(_es, _di + 1, _al);          //mov es:[di+1], al
    _al = memoryVideoGet(_es, _si + 2);         //mov al, es:[si+2]
    memoryVideoSet(_es, _di + 2, _al);          //mov es:[di+2], al
    _al = memoryVideoGet(_es, _si + 3);         //mov al, es:[si+3]
    memoryVideoSet(_es, _di + 3, _al);          //mov es:[di+3], al
    _si += 0x0050;                              //add si, 50h
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_17585
      goto loc_17585;
}

void sub_175AC()
{
    _si = memory16(_ds, 0x205);                 //mov si, ds:205h
    _ch = 0x00;                                 //mov ch, 0
    _cl = memory(_ds, _bx + 414);               //mov cl, [bx+19Eh]
    _cl >>= 1;                                  //shr cl, 1
    _si += _cx;                                 //add si, cx
    _cx = 0x0018;                               //mov cx, 18h
loc_175BD:                                      //loc_175BD:
    _al = memoryVideoGet(_es, _si);                     //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);                     //mov es:[di], al
    _di += 0x0050;                              //add di, 50h
    _si += 0x0050;                              //add si, 50h
    if (--_cx)                                  //loop loc_175BD
      goto loc_175BD;
    _di -= 0x0780;                              //sub di, 780h
}

void sub_175D0()
{
    _si = memory16(_ds, 0x205);                 //mov si, ds:205h
    _si += 0x0003;                              //add si, 3
    _ch = 0x00;                                 //mov ch, 0
    _cl = memory(_ds, _bx + 414);               //mov cl, [bx+19Eh]
    _cl >>= 1;                                  //shr cl, 1
    _si -= _cx;                                 //sub si, cx
    _cx = 0x0018;                               //mov cx, 18h
loc_175E4:                                      //loc_175E4:
    _al = memoryVideoGet(_es, _si);                     //mov al, es:[si]
    memoryVideoSet(_es, _di + 4, _al);                 //mov es:[di+4], al
    _di += 0x0050;                              //add di, 50h
    _si += 0x0050;                              //add si, 50h
    if (--_cx)                                  //loop loc_175E4
      goto loc_175E4;
    _di -= 0x0780;                              //sub di, 780h
}

void sub_175F8()
{
    _ax = 0x0005;                               //mov ax, 5
    _dx = 0x03ce;                               //mov dx, 3CEh
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0000;                               //mov ax, 0
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0001;                               //mov ax, 1
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0002;                               //mov ax, 2
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0003;                               //mov ax, 3
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0004;                               //mov ax, 4
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0f07;                               //mov ax, 0F07h
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0xff08;                               //mov ax, 0FF08h
    _out(_dx, _ax);                             //out dx, ax
    _es = memory16(_ds, 0x24B);                 //mov es, word ptr ds:24Bh
    _di = _di ^ _di;                            //xor di, di
    _dx = 0x03ce;                               //mov dx, 3CEh
    _ah = 0x0f;                                 //mov ah, 0Fh
    _al = 0x00;                                 //mov al, 0
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0f01;                               //mov ax, 0F01h
    _out(_dx, _ax);                             //out dx, ax
    _cx = 0x36b0;                               //mov cx, 36B0h
    _flags.direction = false;                   //cld
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _ax = 0x0001;                               //mov ax, 1
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0105;                               //mov ax, 105h
    _dx = 0x03ce;                               //mov dx, 3CEh
    _out(_dx, _ax);                             //out dx, ax
}

void sub_1763F()
{
    _si = 0xd890;                               //mov si, 0D890h
    _si += 0x0034;                              //add si, 34h
    _di = 0x0001;                               //mov di, 1
    _cx = 0x0007;                               //mov cx, 7
loc_1764B:                                      //loc_1764B:
    _push(_cx);                                 //push cx
    _cx = 0x0012;                               //mov cx, 12h
loc_1764F:                                      //loc_1764F:
    _al = memoryVideoGet(_es, _si);                     //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);                     //mov es:[di], al
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_1764F
      goto loc_1764F;
    _si += 0x003e;                              //add si, 3Eh
    _di += 0x003e;                              //add di, 3Eh
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_1764B
      goto loc_1764B;
    _push(memory16(_ds, 0x211));                //push word ptr ds:211h
    _ax = memory16(_ds, 0x1A38);                //mov ax, ds:1A38h
    memory16(_ds, 0x211) = _ax;                 //mov ds:211h, ax
    memory16(_ds, 0x107D) = 0xd890;             //mov word ptr ds:107Dh, 0D890h
    memory16(_ds, 0x107F) = 0x0c38;             //mov word ptr ds:107Fh, 0C38h
    sub_176FC();                                //call sub_176FC
    memory16(_ds, 0x211) = _pop();              //pop word ptr ds:211h
}

void sub_17680()
{
    _cx = 0x0007;                               //mov cx, 7
loc_17683:                                      //loc_17683:
    _push(_cx);                                 //push cx
    _cx = 0x0010;                               //mov cx, 10h
loc_17687:                                      //loc_17687:
    _al = memoryVideoGet(_es, _si);                     //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);                     //mov es:[di], al
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_17687
      goto loc_17687;
    _si += 0x0040;                              //add si, 40h
    _di += 0x0040;                              //add di, 40h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_17683
      goto loc_17683;
}

void loc_176B5();                                      //loc_176B5:

void sub_1769B()
{
    _cx = memory16(_ds, 0x224);                 //mov cx, ds:224h
    if (memory(_ds, 0x64F) == 0x01)             //jz short loc_176B5
    { loc_176B5(); return; }
    _cx = memory16(_ds, 0x226);                 //mov cx, ds:226h
    if (memory(_ds, 0x217) == 0x01)             //jz short loc_176B5
    { loc_176B5(); return; }
    _cx = memory16(_ds, 0x228);                 //mov cx, ds:228h
}
void loc_176B5()                                      //loc_176B5:
{
    if (_cx == 0x0000)                          //jz short locret_176FB
      _STOP_("goto locret_176FB");
    _si = 0xd6a7;                               //mov si, 0D6A7h
    if (memory16(_ds, 0x3D3) != 0x0002)         //jnz short sub_176C7
    {
        sub_176C7();
        return;
    }
    _si = 0xad50;                               //mov si, 0AD50h
    _STOP_("sp-trace-fail");                    //sub_1769B endp_failed
    _STOP_("continues");                        //sub_176C7 proc near
}

void sub_176C7()
{
    _push(_cx);                                 //push cx
    _cx = 0x0002;                               //mov cx, 2
loc_176CB:                                      //loc_176CB:
    _push(_cx);                                 //push cx
    _cx = 0x0009;                               //mov cx, 9
loc_176CF:                                      //loc_176CF:
    _al = memoryVideoGet(_es, _si);             //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);              //mov es:[di], al
    _al = memoryVideoGet(_es, _si + 1);         //mov al, es:[si+1]
    memoryVideoSet(_es, _di + 1, _al);          //mov es:[di+1], al
    _al = memoryVideoGet(_es, _si + 2);         //mov al, es:[si+2]
    memoryVideoSet(_es, _di + 2, _al);          //mov es:[di+2], al
    _si += 0x0050;                              //add si, 50h
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_176CF
      goto loc_176CF;
    _si += 0xfd34;                              //add si, 0FD34h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_176CB
      goto loc_176CB;
    _di += 0xfa64;                              //add di, 0FA64h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_176B5
        loc_176B5();
locret_176FB:                                   //locret_176FB:
    return;
}

void sub_176FC()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_dx);                                 //push dx
    _dx = memory16(_ds, 0x211);                 //mov dx, ds:211h
    _di = memory16(_ds, 0x107F);                //mov di, ds:107Fh
    _lea(_bx, _ds, 0x1075);                     //lea bx, ds:1075h
loc_1770B:                                      //loc_1770B:
    _al = 0x00;                                 //mov al, 0
loc_1770D:                                      //loc_1770D:
    if ((short)_dx < (short)memory16(_ds, _bx)) //jl short loc_17717
      goto loc_17717;
    _al += 1;                                   //inc al
    _dx = _dx - memory16(_ds, _bx);             //sub dx, [bx]
    goto loc_1770D;                             //jmp short loc_1770D
loc_17717:                                      //loc_17717:
    sub_17738();                                //call sub_17738
    _di += 0x0002;                              //add di, 2
    _bx += 0x0002;                              //add bx, 2
    _al = 0x0a;                                 //mov al, 0Ah
    if (memory(_ds, _bx + -2) != _al)           //jnz short loc_1770B
      goto loc_1770B;
    _al = _dl;                                  //mov al, dl
    sub_17738();                                //call sub_17738
    _di += 0x0002;                              //add di, 2
    _al = 0x00;                                 //mov al, 0
    sub_17738();                                //call sub_17738
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_17738()
{
    _push(_ax);                                 //push ax
    _ax = _es;                                  //mov ax, es
    _ax = _pop();                               //pop ax
    if (_ax == memory16(_ds, 0x24F))            //jz short loc_1776A
      goto loc_1776A;
    _si = memory16(_ds, 0x107D);                //mov si, ds:107Dh
    _ah = 0x00;                                 //mov ah, 0
    _al += _al;                                 //add al, al
    _si += _ax;                                 //add si, ax
    _cx = 0x0007;                               //mov cx, 7
loc_1774F:                                      //loc_1774F:
    _al = memoryVideoGet(_es, _si);                     //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);                     //mov es:[di], al
    _al = memoryVideoGet(_es, _si + 1);                 //mov al, es:[si+1]
    memoryVideoSet(_es, _di + 1, _al);                 //mov es:[di+1], al
    _si += 0x0050;                              //add si, 50h
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_1774F
      goto loc_1774F;
    _di -= 0x0230;                              //sub di, 230h
    return;                                     //retn
loc_1776A:                                      //loc_1776A:
    _ah = 0x04;                                 //mov ah, 4
    _al += 0x30;                                //add al, 30h
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
}

void sub_17772()
{
    if (memory16(_ds, 0x1120) > 0x0001)         //ja short loc_1777A
      goto loc_1777A;
    return;                                     //retn
loc_1777A:                                      //loc_1777A:
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _bx = memory16(_ds, 0x1120);                //mov bx, ds:1120h
loc_17780:                                      //loc_17780:
    _cx = memory16(_ds, 0x111E);                //mov cx, ds:111Eh
loc_17784:                                      //loc_17784:
    if (--_cx)                                  //loop loc_17784
      goto loc_17784;
    _cx = _bx;                                  //mov cx, bx
    _bx -= 1;                                   //dec bx
    if (--_cx)                                  //loop loc_17780
      goto loc_17780;
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
}

void sub_1778E()
{
    memory(_ds, 0x1122) = 0x00;                 //mov byte ptr ds:1122h, 0
    if (memory16(_ds, 0x1120) > 0x0001)         //ja short loc_177AE
      goto loc_177AE;
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(22);                             //int 16h
    if (_flags.zero)                            //jz short loc_177AA
      goto loc_177AA;
    memory(_ds, 0x1122) = 0x01;                 //mov byte ptr ds:1122h, 1
    _ah = 0x00;                                 //mov ah, 0
    _interrupt(22);                             //int 16h
    return;                                     //retn
loc_177AA:                                      //loc_177AA:
    _ax = 0xffff;                               //mov ax, 0FFFFh
    return;                                     //retn
loc_177AE:                                      //loc_177AE:
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _bx = memory16(_ds, 0x1120);                //mov bx, ds:1120h
    if (memory(_ds, 0x254) == 0x00)             //jz short loc_177C6
      goto loc_177C6;
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _bx += 1;                                   //inc bx
loc_177C6:                                      //loc_177C6:
    _cx = memory16(_ds, 0x111E);                //mov cx, ds:111Eh
loc_177CA:                                      //loc_177CA:
    if (--_cx)                                  //loop loc_177CA
      goto loc_177CA;
    if (memory(_ds, 0x1449) == 0x00)            //jz short loc_177DC
      goto loc_177DC;
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(22);                             //int 16h
    if (!_flags.zero)                           //jnz short loc_177FD
      goto loc_177FD;
    goto loc_177E4;                             //jmp short loc_177E4
loc_177DC:                                      //loc_177DC:
    sub_180E0();                                //call sub_180E0
    if (_ax != 0xffff)                          //jnz short loc_177EC
      goto loc_177EC;
loc_177E4:                                      //loc_177E4:
    _cx = _bx;                                  //mov cx, bx
    _bx -= 1;                                   //dec bx
    if (--_cx)                                  //loop loc_177C6
      goto loc_177C6;
    goto loc_17802;                             //jmp short loc_17802
loc_177EC:                                      //loc_177EC:
    if (_al != 0x1b)                            //jnz short loc_177E4
      goto loc_177E4;
    if (memory(_ds, 0x2127) != 0x00)            //jnz short loc_177FD
      goto loc_177FD;
    sub_14639();                                //call sub_14639
    goto loc_17802;                             //jmp short loc_17802
    _STOP_("db 90h");                           //db 90h
loc_177FD:                                      //loc_177FD:
    memory(_ds, 0x1122) = 0x01;                 //mov byte ptr ds:1122h, 1
loc_17802:                                      //loc_17802:
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
}

void sub_17805()
{
    memory(_ds, 0x1122) = 0x00;                 //mov byte ptr ds:1122h, 0
    if (memory16(_ds, 0x1120) > 0x0001)         //ja short loc_17825
      goto loc_17825;
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(22);                             //int 16h
    if (_flags.zero)                            //jz short loc_17821
      goto loc_17821;
    memory(_ds, 0x1122) = 0x01;                 //mov byte ptr ds:1122h, 1
    _ah = 0x00;                                 //mov ah, 0
    _interrupt(22);                             //int 16h
    return;                                     //retn
loc_17821:                                      //loc_17821:
    _ax = 0xffff;                               //mov ax, 0FFFFh
    return;                                     //retn
loc_17825:                                      //loc_17825:
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _bx = memory16(_ds, 0x1120);                //mov bx, ds:1120h
    if (memory(_ds, 0x254) == 0x00)             //jz short loc_1783D
      goto loc_1783D;
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _bx += 1;                                   //inc bx
loc_1783D:                                      //loc_1783D:
    _cx = memory16(_ds, 0x111E);                //mov cx, ds:111Eh
loc_17841:                                      //loc_17841:
    if (--_cx)                                  //loop loc_17841
      goto loc_17841;
    _sync();
    if (memory(_ds, 0x1449) == 0x00)            //jz short loc_17853
      goto loc_17853;
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(22);                             //int 16h
    if (!_flags.zero)                           //jnz short loc_17874
      goto loc_17874;
    goto loc_1785B;                             //jmp short loc_1785B
    _STOP_("db 90h");                           //db 90h
loc_17853:                                      //loc_17853:
    sub_180D2();                                //call sub_180D2
    if (_ax != 0xffff)                          //jnz short loc_17863
      goto loc_17863;
loc_1785B:                                      //loc_1785B:
    _cx = _bx;                                  //mov cx, bx
    _bx -= 1;                                   //dec bx
    if (--_cx)                                  //loop loc_1783D
      goto loc_1783D;
    goto loc_17879;                             //jmp short loc_17879
    _STOP_("db 90h");                           //db 90h
loc_17863:                                      //loc_17863:
    if (_al != 0x1b)                            //jnz short loc_17874
      goto loc_17874;
    if (memory(_ds, 0x2127) != 0x00)            //jnz short loc_17874
      goto loc_17874;
    sub_14639();                                //call sub_14639
    goto loc_17879;                             //jmp short loc_17879
loc_17874:                                      //loc_17874:
    memory(_ds, 0x1122) = 0x01;                 //mov byte ptr ds:1122h, 1
loc_17879:                                      //loc_17879:
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
}

void sub_1787C()
{
    sub_180E0();                                //call sub_180E0
    if (_ax == 0xffff)                          //jz short sub_17885
        sub_17885();
}

void sub_17885()
{
    _ax = memory16(_ds, 0x3FF);                 //mov ax, ds:3FFh
    memory16(_ds, 0x111E) = _ax;                //mov ds:111Eh, ax
    _ax = memory16(_ds, 0x401);                 //mov ax, ds:401h
    _bx = memory16(_ds, 0x1120);                //mov bx, ds:1120h
    memory16(_ds, 0x401) = _bx;                 //mov ds:401h, bx
    memory16(_ds, 0x1120) = _ax;                //mov ds:1120h, ax
    _lea(_dx, _ds, 0x270);                      //lea dx, ds:270h
    sub_17F06();                                //call sub_17F06
    _ax = memory16(_ds, 0x24D);                 //mov ax, ds:24Dh
    sub_17F7B();                                //call sub_17F7B
    _lea(_si, _ds, 0x110A);                     //lea si, ds:110Ah
    sub_180A7();                                //call sub_180A7
    sub_175F8();                                //call sub_175F8
    sub_1793C();                                //call sub_1793C
    _lea(_si, _ds, 0x10B5);                     //lea si, ds:10B5h
    sub_180A7();                                //call sub_180A7
    _es = memory16(_ds, 0x24B);                 //mov es, word ptr ds:24Bh
    memory16(_ds, 0x405) = 0x7fd0;              //mov word ptr ds:405h, 7FD0h
    memory16(_ds, 0x407) = 0x9286;              //mov word ptr ds:407h, 9286h
    memory16(_ds, 0x409) = 0x2d5d;              //mov word ptr ds:409h, 2D5Dh
    memory16(_ds, 0x40B) = 0x2d89;              //mov word ptr ds:40Bh, 2D89h
    memory16(_ds, 0x411) = 0x0091;              //mov word ptr ds:411h, 91h
    memory16(_ds, 0x413) = 0x0007;              //mov word ptr ds:413h, 7
    memory16(_ds, 0x40D) = 0x0050;              //mov word ptr ds:40Dh, 50h
    memory16(_ds, 0x40F) = 0xffb0;              //mov word ptr ds:40Fh, 0FFB0h
    sub_17C31();                                //call sub_17C31
    _si = 0xb720;                               //mov si, 0B720h
    _di = 0x2a9e;                               //mov di, 2A9Eh
    sub_17D32();                                //call sub_17D32
    if (_ax != 0xffff)                          //jnz short loc_1791F
      goto loc_1791F;
loc_178FF:                                      //loc_178FF:
    sub_17A24();                                //call sub_17A24
    sub_17C31();                                //call sub_17C31
    sub_180E0();                                //call sub_180E0
    _sync();
    if (_ax != 0xffff)                          //jnz short loc_1791F
      goto loc_1791F;
    if (memory(_ds, 0x144A) != 0x01)            //jnz short loc_178FF
      goto loc_178FF;
    if (memory16(_ds, 0x411) != 0x0091)         //jnz short loc_178FF
      goto loc_178FF;
    _ax = 0xffff;                               //mov ax, 0FFFFh
loc_1791F:                                      //loc_1791F:
    _bx = memory16(_ds, 0x111E);                //mov bx, ds:111Eh
    memory16(_ds, 0x3FF) = _bx;                 //mov ds:3FFh, bx
    _bx = memory16(_ds, 0x401);                 //mov bx, ds:401h
    _cx = memory16(_ds, 0x1120);                //mov cx, ds:1120h
    memory16(_ds, 0x401) = _cx;                 //mov ds:401h, cx
    memory16(_ds, 0x1120) = _bx;                //mov ds:1120h, bx
    _lea(_dx, _ds, 0x270);                      //lea dx, ds:270h
}

void sub_1793C()
{
    sub_179E3();                                //call sub_179E3
    _si = 0xbaa4;                               //mov si, 0BAA4h
    _di = 0x19b7;                               //mov di, 19B7h
    _cx = 0x0033;                               //mov cx, 33h
loc_17948:                                      //loc_17948:
    _push(_cx);                                 //push cx
    _cx = 0x0022;                               //mov cx, 22h
loc_1794C:                                      //loc_1794C:
    _al = memoryVideoGet(_es, _si);                     //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);                     //mov es:[di], al
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_1794C
      goto loc_1794C;
    _si += 0x002e;                              //add si, 2Eh
    _di += 0x002e;                              //add di, 2Eh
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_17948
      goto loc_17948;
    _bx = _bx ^ _bx;                            //xor bx, bx
    _cx = 0x000a;                               //mov cx, 0Ah
loc_17964:                                      //loc_17964:
    _push(_cx);                                 //push cx
    _si = 0xbad0;                               //mov si, 0BAD0h
    _di = memory16(_ds, _bx + 1045);            //mov di, [bx+415h]
    _bx += 0x0002;                              //add bx, 2
    _cx = 0x0042;                               //mov cx, 42h
loc_17972:                                      //loc_17972:
    _push(_cx);                                 //push cx
    _cx = 0x000c;                               //mov cx, 0Ch
loc_17976:                                      //loc_17976:
    _al = memoryVideoGet(_es, _si);                     //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);                     //mov es:[di], al
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_17976
      goto loc_17976;
    _si += 0x0044;                              //add si, 44h
    _di += 0x0044;                              //add di, 44h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_17972
      goto loc_17972;
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_17964
      goto loc_17964;
    _si = 0xd200;                               //mov si, 0D200h
    _di = 0x46b8;                               //mov di, 46B8h
    _cx = 0x0003;                               //mov cx, 3
loc_17995:                                      //loc_17995:
    _push(_cx);                                 //push cx
    _cx = 0x0009;                               //mov cx, 9
loc_17999:                                      //loc_17999:
    _push(_cx);                                 //push cx
    _cx = 0x0020;                               //mov cx, 20h
loc_1799D:                                      //loc_1799D:
    _al = memoryVideoGet(_es, _si);                     //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);                     //mov es:[di], al
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_1799D
      goto loc_1799D;
    _si += 0x0030;                              //add si, 30h
    _di += 0x0030;                              //add di, 30h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_17999
      goto loc_17999;
    _di += 0x0f00;                              //add di, 0F00h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_17995
      goto loc_17995;
    _di = 0x4988;                               //mov di, 4988h
    _cx = 0x0002;                               //mov cx, 2
loc_179BD:                                      //loc_179BD:
    _push(_cx);                                 //push cx
    _si = 0xcbe0;                               //mov si, 0CBE0h
    _cx = 0x0030;                               //mov cx, 30h
loc_179C4:                                      //loc_179C4:
    _push(_cx);                                 //push cx
    _cx = 0x0020;                               //mov cx, 20h
loc_179C8:                                      //loc_179C8:
    _al = memoryVideoGet(_es, _si);                     //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);                     //mov es:[di], al
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_179C8
      goto loc_179C8;
    _si += 0x0030;                              //add si, 30h
    _di += 0x0030;                              //add di, 30h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_179C4
      goto loc_179C4;
    _di += 0x02d0;                              //add di, 2D0h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_179BD
      goto loc_179BD;
}

void sub_179E3()
{
    _si = 0xd062;                               //mov si, 0D062h
    _di = 0x6901;                               //mov di, 6901h
    _cx = 0x000d;                               //mov cx, 0Dh
loc_179EC:                                      //loc_179EC:
    _push(_cx);                                 //push cx
    _cx = 0x000b;                               //mov cx, 0Bh
loc_179F0:                                      //loc_179F0:
    _al = memoryVideoGet(_es, _si);                     //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);                     //mov es:[di], al
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_179F0
      goto loc_179F0;
    _si += 0x0045;                              //add si, 45h
    _di += 0x0045;                              //add di, 45h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_179EC
      goto loc_179EC;
    _si = 0xd602;                               //mov si, 0D602h
    _di = 0x6948;                               //mov di, 6948h
    _cx = 0x000d;                               //mov cx, 0Dh
loc_17A0C:                                      //loc_17A0C:
    _push(_cx);                                 //push cx
    _cx = 0x0007;                               //mov cx, 7
loc_17A10:                                      //loc_17A10:
    _al = memoryVideoGet(_es, _si);                     //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);                     //mov es:[di], al
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_17A10
      goto loc_17A10;
    _si += 0x0049;                              //add si, 49h
    _di += 0x0049;                              //add di, 49h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_17A0C
      goto loc_17A0C;
}

void sub_17A24()
{
    WORD _cs = _seg002;

    _dx = 0x03ce;                               //mov dx, 3CEh
    _ax = 0x0205;                               //mov ax, 205h
    _out(_dx, _ax);                             //out dx, ax
    _bx = 0x0000;                               //mov bx, 0
loc_17A2E:                                      //loc_17A2E:
    memory16(_ds, 0x429) = _bx;                 //mov ds:429h, bx
    _di = memory16(_ds, _bx + 1171);            //mov di, [bx+493h]
    _di = memory16(_ds, _di + 1224);            //mov di, [di+4C8h]
    _push(_bx);                                 //push bx
    _ax = memory16(_ds, _bx + 1119);            //mov ax, [bx+45Fh]
    _bx = memory16(_ds, _bx + 1067);            //mov bx, [bx+42Bh]
    _indirectCall(_cs, _di);                    //call di
    _bx = _pop();                               //pop bx
    memory16(_ds, _bx + 1171) += 0x0002;        //add word ptr [bx+493h], 2
    if (memory16(_ds, _bx + 1171) <= 0x0040)    //jbe short loc_17A58
      goto loc_17A58;
    memory16(_ds, _bx + 1171) = 0x0000;         //mov word ptr [bx+493h], 0
loc_17A58:                                      //loc_17A58:
    _bx += 0x0002;                              //add bx, 2
    if (_bx <= 0x0032)                          //jbe short loc_17A2E
      goto loc_17A2E;
    _dx = 0x03ce;                               //mov dx, 3CEh
    _ax = 0x0105;                               //mov ax, 105h
    _out(_dx, _ax);                             //out dx, ax
}

void sub_17A68()
{
    memory(_ds, 0x4C7) = 0x00;                  //mov byte ptr ds:4C7h, 0
    sub_17B9A();                                //call sub_17B9A
}

void sub_17A71()
{
    memory(_ds, 0x4C7) = 0x00;                  //mov byte ptr ds:4C7h, 0
    _ax -= 1;                                   //dec ax
    sub_17B9A();                                //call sub_17B9A
    _ax += 0x0002;                              //add ax, 2
    sub_17B9A();                                //call sub_17B9A
    _ax -= 1;                                   //dec ax
    _bx -= 1;                                   //dec bx
    sub_17B9A();                                //call sub_17B9A
    _bx += 0x0002;                              //add bx, 2
    sub_17B9A();                                //call sub_17B9A
}

void sub_17A8C()
{
    memory(_ds, 0x4C7) = 0x09;                  //mov byte ptr ds:4C7h, 9
    _ax += 0x0002;                              //add ax, 2
    sub_17B9A();                                //call sub_17B9A
    _ax -= 0x0004;                              //sub ax, 4
    sub_17B9A();                                //call sub_17B9A
    _ax += 0x0002;                              //add ax, 2
    _bx += 0x0002;                              //add bx, 2
    sub_17B9A();                                //call sub_17B9A
    _bx -= 0x0004;                              //sub bx, 4
    sub_17B9A();                                //call sub_17B9A
}

void sub_17AAD()
{
    memory(_ds, 0x4C7) = 0x09;                  //mov byte ptr ds:4C7h, 9
    _ax += 0x0003;                              //add ax, 3
    sub_17B9A();                                //call sub_17B9A
    _ax -= 0x0006;                              //sub ax, 6
    sub_17B9A();                                //call sub_17B9A
    _ax += 0x0003;                              //add ax, 3
    _bx += 0x0003;                              //add bx, 3
    sub_17B9A();                                //call sub_17B9A
    _bx -= 0x0006;                              //sub bx, 6
    sub_17B9A();                                //call sub_17B9A
}

void sub_17ACE()
{
    memory(_ds, 0x4C7) = 0x06;                  //mov byte ptr ds:4C7h, 6
    _ax += 0x0004;                              //add ax, 4
    sub_17B9A();                                //call sub_17B9A
    _ax -= 0x0008;                              //sub ax, 8
    sub_17B9A();                                //call sub_17B9A
    _ax += 0x0004;                              //add ax, 4
    _bx += 0x0004;                              //add bx, 4
    sub_17B9A();                                //call sub_17B9A
    _bx -= 0x0008;                              //sub bx, 8
    sub_17B9A();                                //call sub_17B9A
}

void sub_17AEF()
{
    memory(_ds, 0x4C7) = 0x06;                  //mov byte ptr ds:4C7h, 6
    _ax += 0x0005;                              //add ax, 5
    sub_17B9A();                                //call sub_17B9A
    _ax -= 0x000a;                              //sub ax, 0Ah
    sub_17B9A();                                //call sub_17B9A
    _ax += 0x0005;                              //add ax, 5
    _bx += 0x0005;                              //add bx, 5
    sub_17B9A();                                //call sub_17B9A
    _bx -= 0x000a;                              //sub bx, 0Ah
    sub_17B9A();                                //call sub_17B9A
}

void sub_17B10()
{
    sub_17BCB();                                //call sub_17BCB
}

void sub_17B14()
{
    _ax -= 1;                                   //dec ax
    sub_17BCB();                                //call sub_17BCB
    _ax += 0x0002;                              //add ax, 2
    sub_17BCB();                                //call sub_17BCB
    _ax -= 1;                                   //dec ax
    _bx -= 1;                                   //dec bx
    sub_17BCB();                                //call sub_17BCB
    _bx += 0x0002;                              //add bx, 2
    sub_17BCB();                                //call sub_17BCB
}

void sub_17B2A()
{
    _ax += 0x0002;                              //add ax, 2
    sub_17BCB();                                //call sub_17BCB
    _ax -= 0x0004;                              //sub ax, 4
    sub_17BCB();                                //call sub_17BCB
    _ax += 0x0002;                              //add ax, 2
    _bx += 0x0002;                              //add bx, 2
    sub_17BCB();                                //call sub_17BCB
    _bx -= 0x0004;                              //sub bx, 4
    sub_17BCB();                                //call sub_17BCB
}

void sub_17B46()
{
    _ax += 0x0003;                              //add ax, 3
    sub_17BCB();                                //call sub_17BCB
    _ax -= 0x0006;                              //sub ax, 6
    sub_17BCB();                                //call sub_17BCB
    _ax += 0x0003;                              //add ax, 3
    _bx += 0x0003;                              //add bx, 3
    sub_17BCB();                                //call sub_17BCB
    _bx -= 0x0006;                              //sub bx, 6
    sub_17BCB();                                //call sub_17BCB
}

void sub_17B62()
{
    _ax += 0x0004;                              //add ax, 4
    sub_17BCB();                                //call sub_17BCB
    _ax -= 0x0008;                              //sub ax, 8
    sub_17BCB();                                //call sub_17BCB
    _ax += 0x0004;                              //add ax, 4
    _bx += 0x0004;                              //add bx, 4
    sub_17BCB();                                //call sub_17BCB
    _bx -= 0x0008;                              //sub bx, 8
    sub_17BCB();                                //call sub_17BCB
}

void sub_17B7E()
{
    _ax += 0x0005;                              //add ax, 5
    sub_17BCB();                                //call sub_17BCB
    _ax -= 0x000a;                              //sub ax, 0Ah
    sub_17BCB();                                //call sub_17BCB
    _ax += 0x0005;                              //add ax, 5
    _bx += 0x0005;                              //add bx, 5
    sub_17BCB();                                //call sub_17BCB
    _bx -= 0x000a;                              //sub bx, 0Ah
    sub_17BCB();                                //call sub_17BCB
}

void sub_17B9A()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _cl = _bl;                                  //mov cl, bl
    _dx = 0x0050;                               //mov dx, 50h
    _mul(_dx);                                  //mul dx
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _bx += _ax;                                 //add bx, ax
    _cl &= 0x07;                                //and cl, 7
    _cl = _cl ^ 0x07;                           //xor cl, 7
    _ah = 0x01;                                 //mov ah, 1
    _ah <<= _cl;                                //shl ah, cl
    _dx = 0x03ce;                               //mov dx, 3CEh
    _al = 0x08;                                 //mov al, 8
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0003;                               //mov ax, 3
    _out(_dx, _ax);                             //out dx, ax
    _al = memoryVideoGet(_es, _bx);                     //mov al, es:[bx]
    _al = memory(_ds, 0x4C7);                   //mov al, ds:4C7h
    memoryVideoSet(_es, _bx, _al);                     //mov es:[bx], al
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_17BCB()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _cl = _bl;                                  //mov cl, bl
    _dx = 0x0050;                               //mov dx, 50h
    _mul(_dx);                                  //mul dx
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _bx >>= 1;                                  //shr bx, 1
    _bx += _ax;                                 //add bx, ax
    _cl &= 0x07;                                //and cl, 7
    _cl = _cl ^ 0x07;                           //xor cl, 7
    _ah = 0x01;                                 //mov ah, 1
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _bx += 0xa0ed;                              //add bx, 0A0EDh
    if (memory16(_ds, 0x429) <= 0x0024)         //jbe short loc_17BF6
      goto loc_17BF6;
    _bx += 0xeb95;                              //add bx, 0EB95h
loc_17BF6:                                      //loc_17BF6:
    _ch = _ah;                                  //mov ch, ah
    _ch <<= _cl;                                //shl ch, cl
    _si = _bx;                                  //mov si, bx
    _bl = _bl ^ _bl;                            //xor bl, bl
    _dx = 0x03ce;                               //mov dx, 3CEh
    _ax = 0x0304;                               //mov ax, 304h
loc_17C04:                                      //loc_17C04:
    _out(_dx, _ax);                             //out dx, ax
    _bh = memoryVideoGet(_es, _si);                     //mov bh, es:[si]
    _bh &= _ch;                                 //and bh, ch
    _bh = -_bh;                                 //neg bh
    _rol(_bx, 1);                               //rol bx, 1
    _flags.carry = (char)_ah >= 1;
    _ah -= 1;                                   //dec ah
    if (_flags.carry)                                //jge short loc_17C04
      goto loc_17C04;
    memory(_ds, 0x4C7) = _bl;                   //mov ds:4C7h, bl
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    _ah <<= _cl;                                //shl ah, cl
    _dx = 0x03ce;                               //mov dx, 3CEh
    _al = 0x08;                                 //mov al, 8
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0003;                               //mov ax, 3
    _out(_dx, _ax);                             //out dx, ax
    _al = memoryVideoGet(_es, _bx);                     //mov al, es:[bx]
    _al = memory(_ds, 0x4C7);                   //mov al, ds:4C7h
    memoryVideoSet(_es, _bx, _al);                     //mov es:[bx], al
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_17C31()
{
    sub_17772();                                //call sub_17772
    _si = memory16(_ds, 0x405);                 //mov si, ds:405h
    _di = memory16(_ds, 0x409);                 //mov di, ds:409h
    sub_17D17();                                //call sub_17D17
    _si = memory16(_ds, 0x407);                 //mov si, ds:407h
    _di = memory16(_ds, 0x40B);                 //mov di, ds:40Bh
    sub_17D17();                                //call sub_17D17
    memory16(_ds, 0x411) += 1;                  //inc word ptr ds:411h
    memory16(_ds, 0x413) += 1;                  //inc word ptr ds:413h
    if (memory16(_ds, 0x411) != 0x0123)         //jnz short loc_17C68
      goto loc_17C68;
    memory16(_ds, 0x411) = 0x0000;              //mov word ptr ds:411h, 0
    memory16(_ds, 0x40D) = -memory16(_ds, 0x40D);//neg word ptr ds:40Dh
    memory16(_ds, 0x40F) = -memory16(_ds, 0x40F);//neg word ptr ds:40Fh
loc_17C68:                                      //loc_17C68:
    _si = memory16(_ds, 0x40D);                 //mov si, ds:40Dh
    _di = memory16(_ds, 0x40F);                 //mov di, ds:40Fh
    memory16(_ds, 0x409) += _si;                //add ds:409h, si
    memory16(_ds, 0x40B) += _di;                //add ds:40Bh, di
    _ax = memory16(_ds, 0x413);                 //mov ax, ds:413h
    if (_ax != 0x001f)                          //jnz short loc_17CF7
      goto loc_17CF7;
    memory16(_ds, 0x413) = 0xffff;              //mov word ptr ds:413h, 0FFFFh
    memory16(_ds, 0x405) = 0x6d60;              //mov word ptr ds:405h, 6D60h
    memory16(_ds, 0x407) = 0xa4f6;              //mov word ptr ds:407h, 0A4F6h
    if (memory(_ds, 0x404) == 0x00)             //jz short locret_17D16
      goto locret_17D16;
    if (memory(_ds, 0x404) == 0x02)             //jz short loc_17CD0
      goto loc_17CD0;
    if (memory(_ds, 0x404) == 0x03)             //jz short loc_17CEB
      goto loc_17CEB;
    memory16(_ds, 0x111E) -= 1;                 //dec word ptr ds:111Eh
    sub_140C1();                                //call sub_140C1
    _al = 0x41;                                 //mov al, 41h
    if (_bx >= 0x0078)                          //jnb short loc_17CBC
      goto loc_17CBC;
    _al = 0x42;                                 //mov al, 42h
    memory16(_ds, 0x111E) += 0x0002;            //add word ptr ds:111Eh, 2
loc_17CBC:                                      //loc_17CBC:
    if (_al != memory(_ds, 0x403))              //jnz short loc_17CCA
      goto loc_17CCA;
    sub_15CC3();                                //call sub_15CC3
    memory16(_ds, 0x2518) = _dx;                //mov ds:2518h, dx
    return;                                     //retn
loc_17CCA:                                      //loc_17CCA:
    memory(_ds, 0x404) = 0x00;                  //mov byte ptr ds:404h, 0
    return;                                     //retn
loc_17CD0:                                      //loc_17CD0:
    memory16(_ds, 0x111E) -= 1;                 //dec word ptr ds:111Eh
    sub_140C1();                                //call sub_140C1
    memory(_ds, 0x403) = 0x41;                  //mov byte ptr ds:403h, 41h
    if (_bx >= 0x0078)                          //jnb short loc_17CEB
      goto loc_17CEB;
    memory(_ds, 0x403) = 0x42;                  //mov byte ptr ds:403h, 42h
    memory16(_ds, 0x111E) += 0x0002;            //add word ptr ds:111Eh, 2
loc_17CEB:                                      //loc_17CEB:
    memory(_ds, 0x404) -= 1;                    //dec byte ptr ds:404h
    sub_15CC3();                                //call sub_15CC3
    memory16(_ds, 0x2518) = _dx;                //mov ds:2518h, dx
    return;                                     //retn
loc_17CF7:                                      //loc_17CF7:
    _ax &= 0x0007;                              //and ax, 7
    if (_ax != 0x0007)                          //jnz short loc_17D0C
      goto loc_17D0C;
    memory16(_ds, 0x405) += 0x122a;             //add word ptr ds:405h, 122Ah
    memory16(_ds, 0x407) -= 0x122a;             //sub word ptr ds:407h, 122Ah
    return;                                     //retn
loc_17D0C:                                      //loc_17D0C:
    memory16(_ds, 0x405) += 0x000a;             //add word ptr ds:405h, 0Ah
    memory16(_ds, 0x407) -= 0x000a;             //sub word ptr ds:407h, 0Ah
locret_17D16:                                   //locret_17D16:
    return;
}

void sub_17D17()
{
    _cx = 0x003b;                               //mov cx, 3Bh
loc_17D1A:                                      //loc_17D1A:
    _push(_cx);                                 //push cx
    _cx = 0x000a;                               //mov cx, 0Ah
loc_17D1E:                                      //loc_17D1E:
    _al = memoryVideoGet(_es, _si);                     //mov al, es:[si]
    memoryVideoSet(_es, _di, _al);                     //mov es:[di], al
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_17D1E
      goto loc_17D1E;
    _si += 0x0046;                              //add si, 46h
    _di += 0x0046;                              //add di, 46h
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_17D1A
      goto loc_17D1A;
}

void sub_17D32()
{
    _ax = 0x0205;                               //mov ax, 205h
    _dx = 0x03ce;                               //mov dx, 3CEh
    _out(_dx, _ax);                             //out dx, ax
    _al = 0x03;                                 //mov al, 3
    _ah = 0x00;                                 //mov ah, 0
    _out(_dx, _ax);                             //out dx, ax
    memory16(_ds, 0x50A) = 0x01fe;              //mov word ptr ds:50Ah, 1FEh
    memory16(_ds, 0x50C) = 0x00ff;              //mov word ptr ds:50Ch, 0FFh
    _push(_di);                                 //push di
    _push(_dx);                                 //push dx
    sub_17DD8();                                //call sub_17DD8
    sub_17E3A();                                //call sub_17E3A
    _dx = _pop();                               //pop dx
    _di = _pop();                               //pop di
    _cl = memory(_ds, 0x50E);                   //mov cl, ds:50Eh
    _cx |= 0x0010;                              //or cx, 10h
loc_17D5B:                                      //loc_17D5B:
    _flags.carry = _cl & 1;                     //shr cl, 1
    _cl >>= 1;
    if (!_flags.carry)                          //jnb short loc_17D5B
      goto loc_17D5B;
loc_17D5F:                                      //loc_17D5F:
    _push(_cx);                                 //push cx
    _cl = memory(_ds, 0x50E);                   //mov cl, ds:50Eh
    memory16(_ds, 0x50A) >>= _cl;               //shr word ptr ds:50Ah, cl
    memory16(_ds, 0x50A) &= 0xfffe;             //and word ptr ds:50Ah, 0FFFEh
    memory16(_ds, 0x50C) >>= _cl;               //shr word ptr ds:50Ch, cl
    _bp = 0x3660;                               //mov bp, 3660h
    _cx = 0x06cc;                               //mov cx, 6CCh
loc_17D77:                                      //loc_17D77:
    sub_180E0();                                //call sub_180E0
    if (_ax == 0xffff)                          //jz short loc_17D81
      goto loc_17D81;
    _cx = _pop();                               //pop cx
    return;                                     //retn
loc_17D81:                                      //loc_17D81:
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _es = memory16(_ds, 0x26B);                 //mov es, word ptr ds:26Bh
    _di = _di + memory16(_es, _bp + 0);         //add di, es:[bp+0]
    _si = memory16(_es, _bp + 2);               //mov si, es:[bp+2]
    _bp += 0x0004;                              //add bp, 4
    _cx = 0x0008;                               //mov cx, 8
    memory(_ds, 0x1081) = 0x80;                 //mov byte ptr ds:1081h, 80h
loc_17D9A:                                      //loc_17D9A:
    _es = memory16(_ds, 0x26B);                 //mov es, word ptr ds:26Bh
    _push(_si);                                 //push si
    sub_17EC6();                                //call sub_17EC6
    _bl = 0x0f;                                 //mov bl, 0Fh
    if (_si > 0x365f)                           //ja short loc_17DAD
      goto loc_17DAD;
    _bl = memory(_es, _si);                     //mov bl, es:[si]
loc_17DAD:                                      //loc_17DAD:
    _si = _pop();                               //pop si
    _si += 1;                                   //inc si
    _es = memory16(_ds, 0x24B);                 //mov es, word ptr ds:24Bh
    _al = 0x08;                                 //mov al, 8
    _ah = memory(_ds, 0x1081);                  //mov ah, ds:1081h
    _out(_dx, _ax);                             //out dx, ax
    memory(_ds, 0x1081) >>= 1;                  //shr byte ptr ds:1081h, 1
    _al = memoryVideoGet(_es, _di);                     //mov al, es:[di]
    memoryVideoSet(_es, _di, _bl);                     //mov es:[di], bl
    if (--_cx)                                  //loop loc_17D9A
      goto loc_17D9A;
    _di = _pop();                               //pop di
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_17D77
      goto loc_17D77;
    _sync();
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_17D5F
      goto loc_17D5F;
    _ax = 0x0105;                               //mov ax, 105h
    _dx = 0x03ce;                               //mov dx, 3CEh
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0xffff;                               //mov ax, 0FFFFh
}

void sub_17DD8()
{
    _di = 0x0000;                               //mov di, 0
    _cx = 0x0057;                               //mov cx, 57h
loc_17DDE:                                      //loc_17DDE:
    _push(_cx);                                 //push cx
    _cx = 0x0014;                               //mov cx, 14h
loc_17DE2:                                      //loc_17DE2:
    _push(_cx);                                 //push cx
    _es = memory16(_ds, 0x24B);                 //mov es, word ptr ds:24Bh
    _dx = 0x03ce;                               //mov dx, 3CEh
    _ax = 0x0304;                               //mov ax, 304h
    _out(_dx, _ax);                             //out dx, ax
    _bh = memoryVideoGet(_es, _si);                     //mov bh, es:[si]
    _dx = 0x03ce;                               //mov dx, 3CEh
    _ax = 0x0204;                               //mov ax, 204h
    _out(_dx, _ax);                             //out dx, ax
    _bl = memoryVideoGet(_es, _si);                     //mov bl, es:[si]
    _dx = 0x03ce;                               //mov dx, 3CEh
    _ax = 0x0104;                               //mov ax, 104h
    _out(_dx, _ax);                             //out dx, ax
    _ch = memoryVideoGet(_es, _si);                     //mov ch, es:[si]
    _dx = 0x03ce;                               //mov dx, 3CEh
    _ax = 0x0004;                               //mov ax, 4
    _out(_dx, _ax);                             //out dx, ax
    _cl = memoryVideoGet(_es, _si);                     //mov cl, es:[si]
    _ax = _cx;                                  //mov ax, cx
    _es = memory16(_ds, 0x26B);                 //mov es, word ptr ds:26Bh
    _cx = 0x0008;                               //mov cx, 8
loc_17E18:                                      //loc_17E18:
    _flags.carry = !!(_bh & 0x80);              //shl bh, 1
    _bh <<= 1;
    _rcl(memory(_es, _di), 1);                  //rcl byte ptr es:[di], 1
    _flags.carry = !!(_bl & 0x80);              //shl bl, 1
    _bl <<= 1;
    _rcl(memory(_es, _di), 1);                  //rcl byte ptr es:[di], 1
    _flags.carry = !!(_ah & 0x80);              //shl ah, 1
    _ah <<= 1;
    _rcl(memory(_es, _di), 1);                  //rcl byte ptr es:[di], 1
    _flags.carry = !!(_al & 0x80);              //shl al, 1
    _al <<= 1;
    _rcl(memory(_es, _di), 1);                  //rcl byte ptr es:[di], 1
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_17E18
      goto loc_17E18;
    _si += 1;                                   //inc si
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_17DE2
      goto loc_17DE2;
    _si += 0x003c;                              //add si, 3Ch
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_17DDE
      goto loc_17DDE;
}

void sub_17E3A()
{
    _es = memory16(_ds, 0x26B);                 //mov es, word ptr ds:26Bh
    _bp = 0x0000;                               //mov bp, 0
    _di = 0x0000;                               //mov di, 0
    _ax = 0x0000;                               //mov ax, 0
    _cx = 0x0057;                               //mov cx, 57h
loc_17E4A:                                      //loc_17E4A:
    _push(_cx);                                 //push cx
    _cx = 0x0014;                               //mov cx, 14h
loc_17E4E:                                      //loc_17E4E:
    memory16(_es, _di + 20880) = _bp;           //mov es:[di+5190h], bp
    _di += 0x0002;                              //add di, 2
    memory16(_es, _di + 20880) = _ax;           //mov es:[di+5190h], ax
    _di += 0x0002;                              //add di, 2
    _ax += 0x0008;                              //add ax, 8
    _bp += 1;                                   //inc bp
    if (--_cx)                                  //loop loc_17E4E
      goto loc_17E4E;
    _bp += 0x003c;                              //add bp, 3Ch
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_17E4A
      goto loc_17E4A;
    _bp = 0x6cbc;                               //mov bp, 6CBCh
    _di = 0x3660;                               //mov di, 3660h
loc_17E70:                                      //loc_17E70:
    sub_181FA();                                //call sub_181FA
    _ah &= 0x07;                                //and ah, 7
    if (_ax <= 0x06cb)                          //jbe short loc_17E7E
      goto loc_17E7E;
    _ax -= 0x0134;                              //sub ax, 134h
loc_17E7E:                                      //loc_17E7E:
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _bx = _ax;                                  //mov bx, ax
loc_17E84:                                      //loc_17E84:
    _ax = memory16(_es, _bx + 20880);           //mov ax, es:[bx+5190h]
    if (_ax != 0xffff)                          //jnz short loc_17E95
      goto loc_17E95;
    _bx >>= 1;                                  //shr bx, 1
    _bl &= 0xfc;                                //and bl, 0FCh
    goto loc_17E84;                             //jmp short loc_17E84
loc_17E95:                                      //loc_17E95:
    memory16(_es, _di) = _ax;                   //mov es:[di], ax
    _dx = memory16(_es, _bx + 20882);           //mov dx, es:[bx+5192h]
    memory16(_es, _di + 2) = _dx;               //mov es:[di+2], dx
    _di += 0x0004;                              //add di, 4
    _ax = memory16(_es, _bp + 0);               //mov ax, es:[bp+0]
    _dx = memory16(_es, _bp + 2);               //mov dx, es:[bp+2]
    memory16(_es, _bx + 20880) = _ax;           //mov es:[bx+5190h], ax
    memory16(_es, _bx + 20882) = _dx;           //mov es:[bx+5192h], dx
    memory16(_es, _bp + 0) = 0xffff;            //mov word ptr es:[bp+0], 0FFFFh
    _bp -= 0x0004;                              //sub bp, 4
    if (_di != 0x5190)                          //jnz short loc_17E70
      goto loc_17E70;
}

void sub_17EC6()
{
    _push(_cx);                                 //push cx
    _bx = memory16(_ds, 0x50A);                 //mov bx, ds:50Ah
    _cx = memory16(_ds, 0x50C);                 //mov cx, ds:50Ch
    sub_181FA();                                //call sub_181FA
    _push(_ax);                                 //push ax
    _ax &= _bx;                                 //and ax, bx
    _si += _ax;                                 //add si, ax
    _si -= _cx;                                 //sub si, cx
    _ax = _pop();                               //pop ax
    memory(_ds, 0x26D) = _bl;                   //mov ds:26Dh, bl
    _bl = _bh;                                  //mov bl, bh
    _bh = memory(_ds, 0x26D);                   //mov bh, ds:26Dh
    _ax &= _bx;                                 //and ax, bx
    _ax >>= 1;                                  //shr ax, 1
    _si += _ax;                                 //add si, ax
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _si += _ax;                                 //add si, ax
    memory(_ds, 0x26D) = _cl;                   //mov ds:26Dh, cl
    _cl = _ch;                                  //mov cl, ch
    _ch = memory(_ds, 0x26D);                   //mov ch, ds:26Dh
    _cx >>= 1;                                  //shr cx, 1
    _si -= _cx;                                 //sub si, cx
    _cx >>= 1;                                  //shr cx, 1
    _cx >>= 1;                                  //shr cx, 1
    _si -= _cx;                                 //sub si, cx
    _cx = _pop();                               //pop cx
}

void sub_17F06()
{
    sub_17F1E();                                //call sub_17F1E
    if (memory(_ds, 0x31F) == 0x01)             //jz short locret_17F1D
      goto locret_17F1D;
    memory16(_ds, 0x319) = _ax;                 //mov ds:319h, ax
    sub_17F44();                                //call sub_17F44
    _bx = memory16(_ds, 0x319);                 //mov bx, ds:319h
    sub_17F76();                                //call sub_17F76
locret_17F1D:                                   //locret_17F1D:
    return;
}

void sub_17F1E()
{
    _ah = 0x3d;                                 //mov ah, 3Dh
    _al = 0x02;                                 //mov al, 2
    _interrupt(33);                             //int 21h
    if (_flags.carry)                           //jb short loc_17F27
      goto loc_17F27;
    return;                                     //retn
loc_17F27:                                      //loc_17F27:
    if (_dx != 0x02ff)                          //jnz short loc_17F33
      goto loc_17F33;
    memory(_ds, 0x31F) = 0x01;                  //mov byte ptr ds:31Fh, 1
    return;                                     //retn
loc_17F33:                                      //loc_17F33:
    _ax = 0x0003;                               //mov ax, 3
    _interrupt(16);                             //int 10h
    _lea(_dx, _ds, 0x320);                      //lea dx, ds:320h
    _ah = 0x09;                                 //mov ah, 9
    _interrupt(33);                             //int 21h
    _ah = 0x4c;                                 //mov ah, 4Ch
    _interrupt(33);                             //int 21h
}

void sub_17F44()
{
    _ah = 0x42;                                 //mov ah, 42h
    _al = 0x02;                                 //mov al, 2
    _cx = 0x0000;                               //mov cx, 0
    _dx = 0x0000;                               //mov dx, 0
    _bx = memory16(_ds, 0x319);                 //mov bx, ds:319h
    _interrupt(33);                             //int 21h
    memory16(_ds, 0x31D) = _ax;                 //mov ds:31Dh, ax
    _ah = 0x42;                                 //mov ah, 42h
    _al = 0x00;                                 //mov al, 0
    _dx = 0x0000;                               //mov dx, 0
    _interrupt(33);                             //int 21h
    _bx = memory16(_ds, 0x319);                 //mov bx, ds:319h
    _cx = memory16(_ds, 0x31D);                 //mov cx, ds:31Dh
    _dx = 0x0000;                               //mov dx, 0
    _ah = 0x3f;                                 //mov ah, 3Fh
    _push(_ds);                                 //push ds
    _ds = memory16(_ds, 0x26B);                 //mov ds, word ptr ds:26Bh
    _interrupt(33);                             //int 21h
    _ds = _pop();                               //pop ds
}

void sub_17F76()
{
    _ah = 0x3e;                                 //mov ah, 3Eh
    _interrupt(33);                             //int 21h
}

void sub_17F7B()
{
    _push(_ds);                                 //push ds
    _ds = memory16(_ds, 0x26B);                 //mov ds, word ptr ds:26Bh
    _es = _ax;                                  //mov es, ax
    _si = _si ^ _si;                            //xor si, si
    _di = _di ^ _di;                            //xor di, di
    _ax = 0x0005;                               //mov ax, 5
    _dx = 0x03ce;                               //mov dx, 3CEh
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0xff08;                               //mov ax, 0FF08h
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0003;                               //mov ax, 3
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0000;                               //mov ax, 0
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0f01;                               //mov ax, 0F01h
    _out(_dx, _ax);                             //out dx, ax
    _cx = 0x6d60;                               //mov cx, 6D60h
    _flags.direction = false;                   //cld
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    _di = _di ^ _di;                            //xor di, di
    _ax = 0x0000;                               //mov ax, 0
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x1003;                               //mov ax, 1003h
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0701;                               //mov ax, 701h
    _out(_dx, _ax);                             //out dx, ax
    _bh = 0x01;                                 //mov bh, 1
    _cx = 0x0050;                               //mov cx, 50h
loc_17FB6:                                      //loc_17FB6:
    _push(_cx);                                 //push cx
    _cx = 0x015e;                               //mov cx, 15Eh
loc_17FBA:                                      //loc_17FBA:
    _bh -= 1;                                   //dec bh
    if (!(_bh & 0x7f))                          //jz short loc_17FCC
      goto loc_17FCC;
    if (_bh & 0x80)                             //jnz short loc_17FD2
      goto loc_17FD2;
    _bl = memory(_ds, _si);                     //mov bl, [si]
    _si += 1;                                   //inc si
    goto loc_17FD2;                             //jmp short loc_17FD2
loc_17FCC:                                      //loc_17FCC:
    _bh = memory(_ds, _si);                     //mov bh, [si]
    _si += 1;                                   //inc si
    _bl = memory(_ds, _si);                     //mov bl, [si]
    _si += 1;                                   //inc si
loc_17FD2:                                      //loc_17FD2:
    _al = memoryVideoGet(_es, _di);                     //mov al, es:[di]
    memoryVideoSet(_es, _di, _bl);                     //mov es:[di], bl
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_17FBA
      goto loc_17FBA;
    _di -= 0x6d5f;                              //sub di, 6D5Fh
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_17FB6
      goto loc_17FB6;
    _di = 0x0000;                               //mov di, 0
    _bh = 0x01;                                 //mov bh, 1
    _ax = 0x1003;                               //mov ax, 1003h
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0b01;                               //mov ax, 0B01h
    _out(_dx, _ax);                             //out dx, ax
    _cx = 0x0050;                               //mov cx, 50h
loc_17FF4:                                      //loc_17FF4:
    _push(_cx);                                 //push cx
    _cx = 0x015e;                               //mov cx, 15Eh
loc_17FF8:                                      //loc_17FF8:
    _bh -= 1;                                   //dec bh
    if (!(_bh & 0x7f))                          //jz short loc_1800A
      goto loc_1800A;
    if (_bh & 0x80)                             //jnz short loc_18010
      goto loc_18010;
    _bl = memory(_ds, _si);                     //mov bl, [si]
    _si += 1;                                   //inc si
    goto loc_18010;                             //jmp short loc_18010
loc_1800A:                                      //loc_1800A:
    _bh = memory(_ds, _si);                     //mov bh, [si]
    _si += 1;                                   //inc si
    _bl = memory(_ds, _si);                     //mov bl, [si]
    _si += 1;                                   //inc si
loc_18010:                                      //loc_18010:
    _al = memoryVideoGet(_es, _di);                     //mov al, es:[di]
    memoryVideoSet(_es, _di, _bl);                     //mov es:[di], bl
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_17FF8
      goto loc_17FF8;
    _di -= 0x6d5f;                              //sub di, 6D5Fh
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_17FF4
      goto loc_17FF4;
    _di = 0x0000;                               //mov di, 0
    _bh = 0x01;                                 //mov bh, 1
    _ax = 0x1003;                               //mov ax, 1003h
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0d01;                               //mov ax, 0D01h
    _out(_dx, _ax);                             //out dx, ax
    _cx = 0x0050;                               //mov cx, 50h
loc_18032:                                      //loc_18032:
    _push(_cx);                                 //push cx
    _cx = 0x015e;                               //mov cx, 15Eh
loc_18036:                                      //loc_18036:
    _bh -= 1;                                   //dec bh
    if (!(_bh & 0x7f))                          //jz short loc_18048
      goto loc_18048;
    if (_bh & 0x80)                             //jnz short loc_1804E
      goto loc_1804E;
    _bl = memory(_ds, _si);                     //mov bl, [si]
    _si += 1;                                   //inc si
    goto loc_1804E;                             //jmp short loc_1804E
loc_18048:                                      //loc_18048:
    _bh = memory(_ds, _si);                     //mov bh, [si]
    _si += 1;                                   //inc si
    _bl = memory(_ds, _si);                     //mov bl, [si]
    _si += 1;                                   //inc si
loc_1804E:                                      //loc_1804E:
    _al = memoryVideoGet(_es, _di);                     //mov al, es:[di]
    memoryVideoSet(_es, _di, _bl);                     //mov es:[di], bl
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_18036
      goto loc_18036;
    _di -= 0x6d5f;                              //sub di, 6D5Fh
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_18032
      goto loc_18032;
    _di = 0x0000;                               //mov di, 0
    _bh = 0x01;                                 //mov bh, 1
    _ax = 0x1003;                               //mov ax, 1003h
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0e01;                               //mov ax, 0E01h
    _out(_dx, _ax);                             //out dx, ax
    _cx = 0x0050;                               //mov cx, 50h
loc_18070:                                      //loc_18070:
    _push(_cx);                                 //push cx
    _cx = 0x015e;                               //mov cx, 15Eh
loc_18074:                                      //loc_18074:
    _bh -= 1;                                   //dec bh
    if (!(_bh & 0x7f))                          //jz short loc_18086
      goto loc_18086;
    if (_bh & 0x80)                             //jnz short loc_1808C
      goto loc_1808C;
    _bl = memory(_ds, _si);                     //mov bl, [si]
    _si += 1;                                   //inc si
    goto loc_1808C;                             //jmp short loc_1808C
loc_18086:                                      //loc_18086:
    _bh = memory(_ds, _si);                     //mov bh, [si]
    _si += 1;                                   //inc si
    _bl = memory(_ds, _si);                     //mov bl, [si]
    _si += 1;                                   //inc si
loc_1808C:                                      //loc_1808C:
    _al = memoryVideoGet(_es, _di);                     //mov al, es:[di]
    memoryVideoSet(_es, _di, _bl);                     //mov es:[di], bl
    _di += 0x0050;                              //add di, 50h
    if (--_cx)                                  //loop loc_18074
      goto loc_18074;
    _di -= 0x6d5f;                              //sub di, 6D5Fh
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_18070
      goto loc_18070;
    _ax = 0x0105;                               //mov ax, 105h
    _dx = 0x03ce;                               //mov dx, 3CEh
    _out(_dx, _ax);                             //out dx, ax
    _ds = _pop();                               //pop ds
}

void sub_180A7()
{
    _ax = 0x0040;                               //mov ax, 40h
    _es = _ax;                                  //mov es, ax
    _dx = memoryBiosGet16(_es, 0x63);                  //mov dx, es:63h
    _dl += 0x06;                                //add dl, 6
    _push(_dx);                                 //push dx
    _flags.interrupt = false;                   //cli
    _in(_al, _dx);                              //in al, dx
    _dl = 0xc0;                                 //mov dl, 0C0h
    _bx = 0x0000;                               //mov bx, 0
loc_180BC:                                      //loc_180BC:
    _al = _bl;                                  //mov al, bl
    _out(_dx, _al);                             //out dx, al
    _al = memory(_ds, _bx + _si);               //mov al, [bx+si]
    _out(_dx, _al);                             //out dx, al
    _bl += 1;                                   //inc bl
    if (_bl != 0x10)                            //jnz short loc_180BC
      goto loc_180BC;
    _dx = _pop();                               //pop dx
    _in(_al, _dx);                              //in al, dx
    _dl = 0xc0;                                 //mov dl, 0C0h
    _al = 0x20;                                 //mov al, 20h
    _out(_dx, _al);                             //out dx, al
    _flags.interrupt = true;                    //sti
}

void sub_180D2()
{
    memory(_ds, 0x256) = 0x00;                  //mov byte ptr ds:256h, 0
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(22);                             //int 16h
    if (_flags.zero)                            //jz short loc_180F5
        sub_180E0(0x180F5);
    else
        sub_180E0(0x180FF);                   //jmp short loc_180FF
}

void sub_180E0(int pc)
{
    if (pc == 0x180F5)
        goto loc_180F5;
    if (pc == 0x180FF)
        goto loc_180FF;
    
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(22);                             //int 16h
    if (_flags.zero)                            //jz short loc_180F5
      goto loc_180F5;
loc_180E6:                                      //loc_180E6:
    _ah = 0x00;                                 //mov ah, 0
    _interrupt(22);                             //int 16h
    _push(_ax);                                 //push ax
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(22);                             //int 16h
    _ax = _pop();                               //pop ax
    if (!_flags.zero)                           //jnz short loc_180E6
      goto loc_180E6;
    goto loc_180FF;                             //jmp short loc_180FF
    _STOP_("db 90h");                           //db 90h
loc_180F5:                                      //loc_180F5:
    if (memory(_ds, 0x254) != 0x00)             //jnz short loc_1810A
      goto loc_1810A;
    _ax = 0xffff;                               //mov ax, 0FFFFh
loc_180FF:                                      //loc_180FF:
    if (memory(_ds, 0x1449) == 0x00)            //jz short locret_18109
      goto locret_18109;
    sub_15097();                                //call sub_15097
locret_18109:                                   //locret_18109:
    return;                                     //retn
loc_1810A:                                      //loc_1810A:
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    memory(_ds, 0x256) = 0x01;                  //mov byte ptr ds:256h, 1
    _dx = 0x0201;                               //mov dx, 201h
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x10)                             //jnz short loc_1811F
      goto loc_1811F;
    _al = 0x0d;                                 //mov al, 0Dh
{loc_1819F(); return; };                        //
loc_1811F:                                      //loc_1811F:
    if (_al & 0x20)                             //jnz short loc_18128
      goto loc_18128;
    _al = 0x1b;                                 //mov al, 1Bh
{loc_1819F(); return; };                        //
loc_18128:                                      //loc_18128:
    sub_1813A();                                //call sub_1813A
    _push(_ax);                                 //push ax
    sub_1813A();                                //call sub_1813A
    _bx = _pop();                               //pop bx
    if (_ax == _bx)                             //jz short loc_18137
      goto loc_18137;
    _ax = 0xffff;                               //mov ax, 0FFFFh
loc_18137:                                      //loc_18137:
{loc_1819F(); return; };                        //
}

void sub_1813A()
{
    _ax = _ax ^ _ax;                            //xor ax, ax
    _ah += 1;                                   //inc ah
    sub_152B4();                                //call sub_152B4
    _bx = _cx;                                  //mov bx, cx
    _ah += 1;                                   //inc ah
    sub_152B4();                                //call sub_152B4
    if (_bx >= memory16(_ds, 0x257))            //jnb short loc_18159
      goto loc_18159;
    _bx = -_bx;                                 //neg bx
    _bx = _bx + memory16(_ds, 0x257);           //add bx, ds:257h
    _dh = 0x02;                                 //mov dh, 2
    goto loc_1815F;                             //jmp short loc_1815F
    _STOP_("db 90h");                           //db 90h
loc_18159:                                      //loc_18159:
    _bx = _bx - memory16(_ds, 0x257);           //sub bx, ds:257h
    _dh = 0x00;                                 //mov dh, 0
loc_1815F:                                      //loc_1815F:
    if (_bx >= 0x0064)                          //jnb short loc_18167
      goto loc_18167;
    _bx = 0x0000;                               //mov bx, 0
loc_18167:                                      //loc_18167:
    if (_cx >= memory16(_ds, 0x259))            //jnb short loc_18178
      goto loc_18178;
    _cx = -_cx;                                 //neg cx
    _cx = _cx + memory16(_ds, 0x259);           //add cx, ds:259h
    _dl = 0x00;                                 //mov dl, 0
    goto loc_1817E;                             //jmp short loc_1817E
loc_18178:                                      //loc_18178:
    _cx = _cx - memory16(_ds, 0x259);           //sub cx, ds:259h
    _dl = 0x08;                                 //mov dl, 8
loc_1817E:                                      //loc_1817E:
    if (_cx >= 0x0064)                          //jnb short loc_1818B
      goto loc_1818B;
    if (_bx == 0x0000)                          //jz short loc_1819B
      goto loc_1819B;
    _cx = 0x0000;                               //mov cx, 0
loc_1818B:                                      //loc_1818B:
    _al = 0x00;                                 //mov al, 0
    if (_bx < _cx)                              //jb short loc_18196
      goto loc_18196;
    _ah = 0x4d;                                 //mov ah, 4Dh
    _ah -= _dh;                                 //sub ah, dh
    return;                                     //retn
loc_18196:                                      //loc_18196:
    _ah = 0x48;                                 //mov ah, 48h
    _ah += _dl;                                 //add ah, dl
    return;                                     //retn
loc_1819B:                                      //loc_1819B:
    _ax = 0xffff;                               //mov ax, 0FFFFh
}

void loc_1819F()
{
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
}

void sub_181A3()
{
loc_181A3:
    _sync();
    sub_180E0();                                //call sub_180E0
    if (_ax != 0xffff)                          //jnz short loc_181B0
      goto loc_181B0;
    memory16(_ds, 0x25F) = _ax;                 //mov ds:25Fh, ax
    goto loc_181A3;                             //jmp short sub_181A3
loc_181B0:                                      //loc_181B0:
    if (memory(_ds, 0x256) == 0x00)             //jz short locret_181C0
      goto locret_181C0;
    if (_ax == memory16(_ds, 0x25F))            //jz short sub_181A3
      goto loc_181A3;
    memory16(_ds, 0x25F) = _ax;                 //mov ds:25Fh, ax
locret_181C0:                                   //locret_181C0:
    return;
}

void sub_181C1()
{
    _ah = 0x00;                                 //mov ah, 0
    _interrupt(26);                             //int 1Ah
    _dx |= 0x0001;                              //or dx, 1
    memory16(_ds, 0x111B) = _dx;                //mov ds:111Bh, dx
    if (memory(_ds, 0x1449) != 0x01)            //jnz short locret_181D9
      goto locret_181D9;
    memory16(_ds, 0x111B) = 0x3039;             //mov word ptr ds:111Bh, 3039h
locret_181D9:                                   //locret_181D9:
    return;
}

void loc_181E6()
{
    _ah &= 0x01;                                //and ah, 1
    return;                                     //retn
    sub_1822B();                                //call sub_1822B
    _ah &= 0x01;                                //and ah, 1
    if ((short)_ax > (short)0x015d)             //jg short loc_181F6
      goto loc_181F6;
    return;                                     //retn
loc_181F6:                                      //loc_181F6:
    _ah &= 0x00;                                //and ah, 0
}

void sub_181FA()
{
    _push(_bx);                                 //push bx
    _push(_dx);                                 //push dx
    _bx = memory16(_ds, 0x111B);                //mov bx, ds:111Bh
    _dx = _bx;                                  //mov dx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _dx;                                 //add bx, dx
    _bx += _bx;                                 //add bx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _dx;                                 //add bx, dx
    _al = _bh;                                  //mov al, bh
    _dx = _bx;                                  //mov dx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _dx;                                 //add bx, dx
    _bx += _bx;                                 //add bx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _dx;                                 //add bx, dx
    memory16(_ds, 0x111B) = _bx;                //mov ds:111Bh, bx
    _ah = _bh;                                  //mov ah, bh
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
}

void sub_1822B()
{
    _ah = memory(_ds, 0x111D);                  //mov ah, ds:111Dh
    _ah += 0x02;                                //add ah, 2
    if ((char)_ah < (char)0x64)                 //jl short loc_1823C
      goto loc_1823C;
    _ah = 0x00;                                 //mov ah, 0
    sub_181C1();                                //call sub_181C1
loc_1823C:                                      //loc_1823C:
    memory(_ds, 0x111D) = _ah;                  //mov ds:111Dh, ah
    _bx = memory16(_ds, 0x111B);                //mov bx, ds:111Bh
    _dx = _bx;                                  //mov dx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _dx;                                 //add bx, dx
    _bx += _bx;                                 //add bx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _dx;                                 //add bx, dx
    _al = _bh;                                  //mov al, bh
    _dx = _bx;                                  //mov dx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _dx;                                 //add bx, dx
    _bx += _bx;                                 //add bx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _bx;                                 //add bx, bx
    _bx += _dx;                                 //add bx, dx
    memory16(_ds, 0x111B) = _bx;                //mov ds:111Bh, bx
    _ah = _bh;                                  //mov ah, bh
}

void sub_1826D()
{
    _push(_bx);                                 //push bx
    _push(_dx);                                 //push dx
    _ah = memory(_ds, 0x111D);                  //mov ah, ds:111Dh
    _ah += 1;                                   //inc ah
    if ((char)_ah < (char)0x64)                 //jl short loc_1827F
      goto loc_1827F;
    _ah = 0x00;                                 //mov ah, 0
    sub_181C1();                                //call sub_181C1
loc_1827F:                                      //loc_1827F:
    memory(_ds, 0x111D) = _ah;                  //mov ds:111Dh, ah
    _ax = memory16(_ds, 0x111B);                //mov ax, ds:111Bh
    _bx = _ax;                                  //mov bx, ax
    _ax += _ax;                                 //add ax, ax
    _ax += _ax;                                 //add ax, ax
    _ax += _bx;                                 //add ax, bx
    _ax += _ax;                                 //add ax, ax
    _ax += _ax;                                 //add ax, ax
    _ax += _ax;                                 //add ax, ax
    _ax += _bx;                                 //add ax, bx
    memory16(_ds, 0x111B) = _ax;                //mov ds:111Bh, ax
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
}


