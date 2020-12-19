void start();
void sub_24B90();
void sub_105A3();
void sub_107ED();
void sub_15E8A();
void sub_15E5E();
void sub_15C8B();
void sub_13C75();
void sub_15EC3();
void sub_15E7A();

// imports
void sub_10000();
void sub_1011C();
void sub_1066E() {_ASSERT(0);};
void sub_106FE();
void sub_1080F() {_ASSERT(0);};
void sub_10985() {_ASSERT(0);};
void sub_10A2F() {_ASSERT(0);};
void sub_10A95() {_ASSERT(0);};
void sub_10BA5() {_ASSERT(0);};
void sub_10D5F();
void sub_10D81();
void sub_10DA3();
void sub_10E2B() {_ASSERT(0);};
void sub_10E4D() {_ASSERT(0);};
void sub_10E6F() {_ASSERT(0);};
void sub_10E91() {_ASSERT(0);};
void sub_10FF0() {_ASSERT(0);};
void sub_11827() {_ASSERT(0);};
void sub_118F5() {_ASSERT(0);};
void sub_1193C() {_ASSERT(0);};
void sub_11A62() {_ASSERT(0);};
void sub_11A65() {_ASSERT(0);};
void sub_11B43() {_ASSERT(0);};
void sub_12B22() {_ASSERT(0);};
void sub_13319() {_ASSERT(0);};
void sub_135EB() {_ASSERT(0);};
void sub_13615() {_ASSERT(0);};
void sub_13682() {_ASSERT(0);};
void sub_1373D() {_ASSERT(0);};
void sub_13760() {_ASSERT(0);};
void sub_137A9() {_ASSERT(0);};
void sub_14191();
void sub_1426A();
void sub_14675() {_ASSERT(0);};
void sub_14A69() {_ASSERT(0);};
void sub_15863();
void sub_15926() {_ASSERT(0);};
void sub_159C8() {_ASSERT(0);};
void sub_15B21() {_ASSERT(0);};
void sub_15C0F() {_ASSERT(0);};
void sub_15CC5() {_ASSERT(0);};
void sub_16058();
void sub_160A5();
void sub_24EFC() {_ASSERT(0);};
void sub_24CD5() {_ASSERT(0);};
void sub_24D33() {_ASSERT(0);};
void sub_24F05() {_ASSERT(0);};


// imports
void sub_10067();
void sub_10089();
void sub_10097();
void sub_10101();

void sub_1011C();
void sub_1019A();
void sub_10230();
void sub_102A8();
void sub_102D4();
void sub_1034C();
void sub_10174();
void sub_10373();
void sub_103DD();
void sub_103FD();
void sub_10423();
void sub_104C9();



void sub_1426A();
void sub_141A1();
void sub_14191();



void start()
{
  _ax = 0x2853;                                   //mov ax, 2853h
  _ds = _ax;                                      //mov ds, ax
  _es = _ax;                                      //mov es, ax
  _flags.direction = false;                        //cld
  memory16(_ds, 0x8E6A) = _sp;                    //mov word_3139A, sp
  sub_105A3();                                    //call sub_105A3
  memory16(_ds, 0x8E6C) = 0;                      //mov word_3139C, 0
  sub_107ED();                                    //call sub_107ED
  memory16(_ds, 0x8E88) = 0;                      //mov word_313B8, 0
  memory16(_ds, 0x8E8A) = 0;                      //mov word_313BA, 0
  _push(_es);                                     //push es
  _ax = _ax ^ _ax;                                //xor ax, ax
  _es = _ax;                                      //mov es, ax
  _flags.interrupt = false;                        //cli
  memory16(_es, 512) = 0;                         //mov word ptr es:200h, 0
  memory16(_es, 514) = 9401;                      //mov word ptr es:202h, 24B9h
  _flags.interrupt = true;                         //sti
  _es = _pop();                                   //pop es
  _ah = 0x22;                                     //mov ah, 22h
  _al = 0x16;                                     //mov al, 16h
  _interrupt(0x80);                               //int 80h
  sub_15E8A();                                    //call sub_15E8A
  memory16(_ds, 0x3048) = 0;                      //mov word_2B578, 0
loc_1053B:                                        //loc_1053B:                   // timing sync
    /*
  if ((short)memory16(_ds, 0x3048) < (short)0x28) //jl short loc_1053B
    goto loc_1053B;
     */
  sub_15E5E();                                    //call sub_15E5E
  sub_15C8B();                                    //call sub_15C8B
  _ax = _ds;                                      //mov ax, ds
  _es = _ax;                                      //mov es, ax
  sub_13C75();                                    //call sub_13C75
loc_1054F:                                        //loc_1054F:
  if (memory16(_ds, 0x3044) != 4)                 //jnz short loc_10585
    goto loc_10585;
  _dx = 0x03b8;                                   //mov dx, 3B8h
  _al = 0x00;                                     //mov al, 0
  _out(_dx, _al);                                 //out dx, al
  _dx = 0x03b4;                                   //mov dx, 3B4h
  _si = 0x2ee0;                                   //mov si, 2EE0h
  _cx = 0x0009;                                   //mov cx, 9
loc_10565:                                        //loc_10565:
  _lodsw<MemAuto, DirAuto>();                     //lodsw
  _out(_dx, _ax);                                 //out dx, ax
  if (--_cx)                                      //loop loc_10565
    goto loc_10565;
  _push(_es);                                     //push es
  _ax = 0xb000;                                   //mov ax, 0B000h
  _es = _ax;                                      //mov es, ax
  _di = _di ^ _di;                                //xor di, di
  _cx = 0x4000;                                   //mov cx, 4000h
  _ax = _ax ^ _ax;                                //xor ax, ax
  _rep_stosw<MemAuto, DirAuto>();                 //rep stosw
  _es = _pop();                                   //pop es
  _dx = 0x03b8;                                   //mov dx, 3B8h
  _al = 0x08;                                     //mov al, 8
  _out(_dx, _al);                                 //out dx, al
  _dx = 0x03bf;                                   //mov dx, 3BFh
  _al = 0x00;                                     //mov al, 0
  _out(_dx, _al);                                 //out dx, al
loc_10585:                                        //loc_10585:
  _ah = 0x01;                                     //mov ah, 1
  _interrupt(0x80);                               //int 80h
  sub_15EC3();                                    //call sub_15EC3
  sub_15E7A();                                    //call sub_15E7A
  _ax = 0x0003;                                   //mov ax, 3
  if (memory16(_ds, 0x3044) != 4)                 //jnz short loc_1059C
    goto loc_1059C;
  _ax = 0x0007;                                   //mov ax, 7
loc_1059C:                                        //loc_1059C:
  _interrupt(0x10);                               //int 10h
  _ax = 0x4c00;                                   //mov ax, 4C00h
  _interrupt(0x21);                               //int 21h
}

void sub_24B90()
{
//  _cs = seg002;
  _flags.interrupt = true;                         //sti
  _push(_bx);                                     //push bx
  _push(_cx);                                     //push cx
  _push(_dx);                                     //push dx
  _push(_si);                                     //push si
  _push(_di);                                     //push di
  _push(_ds);                                     //push ds
  _push(_cs);                                     //push cs
  _ds = _pop();                                   //pop ds
  _bh = _bh ^ _bh;                                //xor bh, bh
  _bl = _ah;                                      //mov bl, ah
  _ah -= 0x10;                                    //sub ah, 10h
  if (_ah <= 0)                                   //jbe short loc_24BA5
    goto loc_24BA5;
  goto loc_24CC0;                                 //jmp loc_24CC0
loc_24BA5:                                        //loc_24BA5:
  _bl <<= 1;                                      //shl bl, 1
  switch (_bx)                                    //call off_24BDA[bx]
  {
    case 0: sub_24EFC(); break;
    case 2: sub_24CD5(); break;
    case 4: sub_24D33(); break;
    case 6: sub_24F05(); break;
    default:
      _ASSERT(0);
  }
loc_24BAB:                                        //loc_24BAB:
  _ds = _pop();                                   //pop ds
  _di = _pop();                                   //pop di
  _si = _pop();                                   //pop si
  _dx = _pop();                                   //pop dx
  _cx = _pop();                                   //pop cx
  _bx = _pop();                                   //pop bx
  return;                                         //iret
  _STOP_("db 3 dup(0), 1, 5 dup(0), 90h, 4 dup(0), 4...");
  _STOP_("db 2, 0B9h, 2, 0E7h, 2, 0EAh, 2, 8Dh, 2, 0...");
  _STOP_("db 3, 0A9h, 2, 0E2h, 2, 0F3h, 2, 0A4h, 2, ...");
  _STOP_("off_24BDA dw offset sub_24D57");        //off_24BDA dw offset sub_24D57
  _STOP_("db 10h, 99h, 79h, 90h, 5Dh, 88h, 0B6h, 80h...");
  _STOP_("db 72h, 3Bh, 6Ch, 28h, 66h, 6Ch, 60h, 3, 5...");
  _STOP_("db 15h, 51h, 88h, 4Ch, 3Ch, 48h, 2Fh, 44h,...");
  _STOP_("db 3Ch, 55h, 39h, 1Eh, 36h, 14h, 33h, 36h,...");
  _STOP_("db 0F4h, 2Ah, 8Bh, 28h, 44h, 26h, 1Eh, 24h...");
  _STOP_("db 20h, 5Fh, 1Eh, 0ABh, 1Ch, 0Fh, 1Bh, 8Ah...");
  _STOP_("db 0C1h, 16h, 7Ah, 15h, 45h, 14h, 22h, 13h...");
  _STOP_("db 11h, 17h, 10h, 30h, 0Fh, 55h, 0Eh, 87h,...");
  _STOP_("db 0Eh, 0Ch, 60h, 0Bh, 0BDh, 0Ah, 23h, 0Ah...");
  _STOP_("db 9, 86h, 8, 0Bh, 8, 98h, 7, 2Bh, 7, 0C4h...");
  _STOP_("db 7, 6, 0B0h, 5, 5Eh, 5, 11h, 5, 0C9h, 4,...");
  _STOP_("db 4, 6, 4, 0CCh, 3, 95h, 3, 62h, 3, 31h, ...");
  _STOP_("db 2, 0AFh, 2, 89h, 2, 64h, 2, 42h, 2, 21h...");
  _STOP_("db 1, 0CBh, 1, 0B1h, 1, 99h, 1, 82h, 1, 6C...");
  _STOP_("db 44h, 1, 32h, 1, 21h, 1, 30h dup(0)");//db 44h, 1, 32h, 1, 21h, 1, 30h dup(0)
loc_24CC0:                                        //loc_24CC0:
  _flags.carry = _bl < 0x20;                       //sub bl, 20h
  _bl -= 0x20;
  if (_flags.carry)                                //jb short loc_24CCC
    goto loc_24CCC;
  memory(_ds, _bx + 34) = _al;                    //mov [bx+22h], al
  goto loc_24BAB;                                 //jmp loc_24BAB
loc_24CCC:                                        //loc_24CCC:
  _bl = _ah;                                      //mov bl, ah
  _al = memory(_ds, _bx + 34);                    //mov al, [bx+22h]
  goto loc_24BAB;                                 //jmp loc_24BAB
}

void sub_105A3()
{
  memory(_ds, 0x8F57) = 0;                        //mov byte_31487, 0
  sub_10000();                                    //call sub_10000
  _ax = _ds;                                      //mov ax, ds
  _es = _ax;                                      //mov es, ax
  _ax = 0x0004;                                   //mov ax, 4
  if (memory(_ds, 0x8E59) != 0)                   //jnz short loc_105DA
    goto loc_105DA;
  _ax = 0x0003;                                   //mov ax, 3
  if (memory(_ds, 0x8E5A) != 0)                   //jnz short loc_105DA
    goto loc_105DA;
  _ax = 0x0002;                                   //mov ax, 2
  if (memory(_ds, 0x8E58) != 0)                   //jnz short loc_105DA
    goto loc_105DA;
  _ax = 0x0000;                                   //mov ax, 0
  if (memory(_ds, 0x8E5D) != 0)                   //jnz short loc_105DA
    goto loc_105DA;
  _ax = 0x0001;                                   //mov ax, 1
loc_105DA:                                        //loc_105DA:
  memory16(_ds, 0x3044) = _ax;                    //mov word_2B574, ax
  _ah = 0x0f;                                     //mov ah, 0Fh
  _interrupt(0x10);                               //int 10h
  memory(_ds, 0x2EF3) = _bh;                      //mov byte_2B423, bh
  memory(_ds, 0x2EF4) = _al;                      //mov byte_2B424, al
  memory(_ds, 0x2EF5) = _ah;                      //mov byte_2B425, ah
  _ah = 0x01;                                     //mov ah, 1
  _ch = 0x20;                                     //mov ch, 20h
  _cl = 0x20;                                     //mov cl, 20h
  _interrupt(0x10);                               //int 10h
loc_105F4:                                        //loc_105F4:
  _ax = 0x0600;                                   //mov ax, 600h
  _bh = _bh ^ _bh;                                //xor bh, bh
  _cx = _cx ^ _cx;                                //xor cx, cx
  _dl = (memory(_ds, 0x2EF5)) - 1;                //dec dl
  _dh = 0x18;                                     //mov dh, 18h
  _interrupt(0x10);                               //int 10h
loc_10605:                                        //loc_10605:
  sub_106FE();                                    //call sub_106FE
loc_10608:                                        //loc_10608:
  _ah = _ah ^ _ah;                                //xor ah, ah
  _interrupt(0x16);                               //int 16h
  if (_ah == 0x1c)                                //jz short loc_10657
    goto loc_10657;
  if (_ah == 0x41)                                //jz short loc_10652
    goto loc_10652;
  if (_ah == 0x39)                                //jz short loc_10631
    goto loc_10631;
  if (_ah == 0x50)                                //jz short loc_10631
    goto loc_10631;
  if (_ah == 0x4d)                                //jz short loc_10631
    goto loc_10631;
  if (_ah == 0x48)                                //jz short loc_10644
    goto loc_10644;
  if (_ah == 0x4b)                                //jz short loc_10644
    goto loc_10644;
  goto loc_10608;                                 //jmp short loc_10608
loc_10631:                                        //loc_10631:
  memory16(_ds, 0x3044) += 1;                     //inc word_2B574
  if ((short)memory16(_ds, 0x3044) < (short)6)    //jl short loc_10605
    goto loc_10605;
  memory16(_ds, 0x3044) = 0;                      //mov word_2B574, 0
  goto loc_10605;                                 //jmp short loc_10605
loc_10644:                                        //loc_10644:
  memory16(_ds, 0x3044) -= 1;                     //dec word_2B574
  if ((short)memory16(_ds, 0x3044) >= 0)          //jns short loc_10605
    goto loc_10605;
  memory16(_ds, 0x3044) = 5;                      //mov word_2B574, 5
  goto loc_10605;                                 //jmp short loc_10605
loc_10652:                                        //loc_10652:
  memory(_ds, 0x8F57) = 0xff;                     //mov byte_31487, 0FFh
loc_10657:                                        //loc_10657:
  if (memory16(_ds, 0x3044) != 5)                 //jnz short loc_10663
    goto loc_10663;
  sub_1066E();                                    //call sub_1066E
  goto loc_105F4;                                 //jmp short loc_105F4
loc_10663:                                        //loc_10663:
  _ax = memory16(_ds, 0x3044);                    //mov ax, word_2B574
  _bx = 0x2ef8;                                   //mov bx, 2EF8h
  _xlat();                                        //xlat
    
    std::cout << "Override gfx !!!!" << std::endl;
    _ax = 3;


    // Hercules: 4
    // CGA: 2
    // Tandy: 1
    // Ega: 0
    // VGA: 3
    
  memory16(_ds, 0x3044) = _ax;                    //mov word_2B574, ax
}
// 0x3044 = graficky adapter, VGA=3
void sub_seg001_00();
void sub_seg001_2a();
void sub_107ED() // Set video mode!!!!!
{
  _bp = ((memory16(_ds, 0x3044)) << 1) << 1;      //shl bp, 1
    switch (_bp)
    {
        case 0: sub_seg001_00(); break; // seg001 + 0
        case 4: _ASSERT(0); // seg001 + 39cd
        case 8: _ASSERT(0); // seg001 + 2060, mode 6
        case 12: sub_seg001_2a(); break;// seg001 + 2a
        case 16: _ASSERT(0); // seg001 + 207bh, b800
            
    }
        
  //_STOP_("call dword ptr cs:[bp+7FBh]");          //call dword ptr cs:[bp+7FBh]
}

void sub_15E8A() // TODO: tuto nastavuje timer
{
    _cs = seg000;//GABO!
  memory(_cs, 0x6009) = 3;                        //mov cs:word_16009, 3
  _ax = 0x3508;                                   //mov ax, 3508h
  _interrupt(0x21);                               //int 21h
  memory16(_ds, 0x8E62) = _bx;                    //mov word_31392, bx
  memory16(_ds, 0x8E64) = _es;                    //mov word_31394, es
  _ax = 0x2508;                                   //mov ax, 2508h
  _push(_ds);                                     //push ds
  _dx = 0x600b;                                   //mov dx, 600Bh
  _cx = _cs;                                      //mov cx, cs
  _ds = _cx;                                      //mov ds, cx
  _interrupt(0x21);                               //int 21h
  _ds = _pop();                                   //pop ds
  _flags.interrupt = false;                        //cli
  _al = 0x36;                                     //mov al, 36h
  _out(0x43, _al);                                //out 43h, al     // programmable timer
  _dx = 0x5555;                                   //mov dx, 5555h
  _al = _dl;                                      //mov al, dl
  _out(0x40, _al);                                //out 40h, al
  _al = _dh;                                      //mov al, dh
  _out(0x40, _al);                                //out 40h, al
  _in(_al, 0x61);                                 //in al, 61h // speaker
  memory(_ds, 0x3042) = _al;                      //mov byte_2B572, al
  _flags.interrupt = true;                         //sti
}

void sub_15E5E() // keyboard isr
{
  _ax = 0x3509;                                   //mov ax, 3509h
  _interrupt(0x21);                               //int 21h
  memory16(_ds, 0x8E66) = _bx;                    //mov word_31396, bx
  memory16(_ds, 0x8E68) = _es;                    //mov word_31398, es
  _ax = 0x2509;                                   //mov ax, 2509h
  _push(_ds);                                     //push ds
  _dx = _cs;                                      //mov dx, cs
  _ds = _dx;                                      //mov ds, dx
  _dx = 0x5eeb;                                   //mov dx, 5EEBh
  _interrupt(0x21);                               //int 21h
  _ds = _pop();                                   //pop ds
}

void sub_13C75()
{
  sub_16058();                                    //call sub_16058
  memory(_ds, 0x8F54) = 0;                        //mov byte_31484, 0
  memory16(_ds, 0x8E6E) = 1;                      //mov word_3139E, 1
  memory(_ds, 0x8F55) = 0;                        //mov byte_31485, 0
  memory(_ds, 0x8F56) = 0;                        //mov byte_31486, 0
#warning PHASE2: neviem
    std::cout << "netusim..";
  //memory16(-1, -1) = 0xbf;                        //mov word ptr ss:byte_447B0+10h, 0BFh
  sub_1426A();                                    //call sub_1426A
  memory16(_ds, 0x8E70) = 1;                      //mov word_313A0, 1
loc_13C9D:                                        //loc_13C9D:
  _sp = memory16(_ds, 0x8E6A);                    //mov sp, word_3139A
  sub_10D5F();                                    //call sub_10D5F
  memory(_ds, 0x8F58) = 0;                        //mov byte_31488, 0
  memory(_ds, 0x8F59) = 0;                        //mov byte_31489, 0
  memory(_ds, 0x8F5B) = 0;                        //mov byte_3148B, 0
  memory16(_ds, 0x8E88) = 0;                      //mov word_313B8, 0
  memory16(_ds, 0x8E8A) = 0;                      //mov word_313BA, 0
  sub_15863();                                    //call sub_15863
  sub_15B21();                                    //call sub_15B21
  sub_10D5F();                                    //call sub_10D5F
  memory16(_ds, 0x991C) = 1;                      //mov word_31E4C, 1
  memory(_ds, 0x3550) = 0x31;                     //mov byte_2BA80, 31h
  sub_15CC5();                                    //call sub_15CC5
  sub_11827();                                    //call sub_11827
  sub_11B43();                                    //call sub_11B43
  memory(_ds, 0x3727) = 0x31;                     //mov byte_2BC57, 31h
  if (memory(_ds, 0x8F5D) != 0)                   //jnz short loc_13CED
    goto loc_13CED;
  memory(_ds, 0x3727) = 0x32;                     //mov byte_2BC57, 32h
loc_13CED:                                        //loc_13CED:
  _si = 0x3715;                                   //mov si, 3715h
  memory(_ds, 0x374E) = 0xff;                     //mov byte_2BC7E, 0FFh
  sub_15926();                                    //call sub_15926
  memory(_ds, 0x374E) = 0;                        //mov byte_2BC7E, 0
  sub_10D5F();                                    //call sub_10D5F
  if (memory(_ds, 0x8F54) == 0)                   //jz short loc_13D0D
    goto loc_13D0D;
  _ah = 0x02;                                     //mov ah, 2
  _al = 0x00;                                     //mov al, 0
  _interrupt(0x80);                               //int 80h
loc_13D0D:                                        //loc_13D0D:
  sub_10985();                                    //call sub_10985
  sub_1080F();                                    //call sub_1080F
  sub_10A2F();                                    //call sub_10A2F
  sub_10E2B();                                    //call sub_10E2B
  sub_10D81();                                    //call sub_10D81
  memory(_ds, 0x8F59) = 0;                        //mov byte_31489, 0
  memory(_ds, 0x8F5B) = 0;                        //mov byte_3148B, 0
loc_13D26:                                        //loc_13D26:
  memory16(_ds, 0x919C) += 1;                     //inc word_316CC
  _ax = (memory16(_ds, 0x919C)) & 0x0003;         //and ax, 3
  if (_ax != 0)                                   //jnz short loc_13D47
    goto loc_13D47;
  _ax = memory16(_ds, 0x91AC);                    //mov ax, word_316DC
  memory16(_ds, 0x8EB0) = _ax;                    //mov word_313E0, ax
  _ax = memory16(_ds, 0x91AC);                    //mov ax, word_316DC
  memory16(_ds, 0x8EB2) = _ax + 1;                //inc word_313E2
  memory16(_ds, 0x91AC) += 2;                     //add word_316DC, 2
loc_13D47:                                        //loc_13D47:
  sub_10985();                                    //call sub_10985
  memory16(_ds, 0x919A) = 1;                      //mov word_316CA, 1
  sub_10E4D();                                    //call sub_10E4D
  sub_10BA5();                                    //call sub_10BA5
  sub_1373D();                                    //call sub_1373D
  sub_10FF0();                                    //call sub_10FF0
  sub_13682();                                    //call sub_13682
  sub_1080F();                                    //call sub_1080F
  sub_14675();                                    //call sub_14675
  sub_10A95();                                    //call sub_10A95
  sub_13615();                                    //call sub_13615
  _al = memory(_ds, 0x8F58);                      //mov al, byte_31488
  if (_al & _al)                                  //jnz short loc_13D75
    goto loc_13D75;
  goto loc_13E1A;                                 //jmp loc_13E1A
loc_13D75:                                        //loc_13D75:
  memory(_ds, 0x8F58) = 0;                        //mov byte_31488, 0
  _si = 0x3d8f;                                   //mov si, 3D8Fh
  memory(_cs, 0x3D9B) = _al;                      //mov cs:byte_13D9B, al
loc_13D81:                                        //loc_13D81:
  if (_al == memory16(_cs, _si))                  //jz short loc_13D8B
    goto loc_13D8B;
  _si += 0x0003;                                  //add si, 3
  goto loc_13D81;                                 //jmp short loc_13D81
loc_13D8B:                                        //loc_13D8B:
  ////goto word ptr cs:[si+1];                        //jmp word ptr cs:[si+1]
  _STOP_("db 19h, 0F8h, 3Dh, 1, 9Dh, 3Ch, 1Ch, 0BDh,...");
  _STOP_("db 3Dh");                               //db 3Dh
  _STOP_("byte_13D9B db 0");                      //byte_13D9B db 0
  _STOP_("db 1Ah, 3Eh, 9, 0, 1, 0, 4, 0, 2, 0, 1, 0,...");
  _STOP_("word_13DAA dw 1");                      //word_13DAA dw 1
  _STOP_("word_13DAC dw 1");                      //word_13DAC dw 1
  _ax = _ax + memory16(_ds, _bx + _si);           //add ax, [bx+si]
  memory(_ds, _bx + _si) |= _al;                  //or [bx+si], al
  _al = memory(_ds, 0x8F57);                      //mov al, byte_31487
  memory(_ds, 0x8F56) = memory(_ds, 0x8F56) ^ _al;//xor byte_31486, al
  goto loc_13E1A;                                 //jmp short loc_13E1A
  if (memory(_ds, 0x9224) != 0)                   //jnz short loc_13E1A
    goto loc_13E1A;
  if (memory16(_ds, 0x8E80) != 0)                 //jnz short loc_13DF0
    goto loc_13DF0;
  if (memory16(_ds, 0x9160) == 0)                 //jz short loc_13E1A
    goto loc_13E1A;
  memory16(_ds, 0x8E82) = 1;                      //mov word_313B2, 1
  memory16(_ds, 0x8E88) = 0x18;                   //mov word_313B8, 18h
  memory16(_ds, 0x8E80) = 1;                      //mov word_313B0, 1
  memory16(_ds, 0x9160) -= 1;                     //dec word_31690
  memory16(_ds, 0x8E84) = 0x88;                   //mov word_313B4, 88h
  goto loc_13E1A;                                 //jmp short loc_13E1A
loc_13DF0:                                        //loc_13DF0:
  memory16(_ds, 0x8E84) = 1;                      //mov word_313B4, 1
  goto loc_13E1A;                                 //jmp short loc_13E1A
  memory(_ds, 0x8F5B) = 0;                        //mov byte_3148B, 0
loc_13DFD:                                        //loc_13DFD:
  if (memory(_ds, 0x8F5B) != 0)                   //jnz short loc_13E10
    goto loc_13E10;
  if (memory(_ds, 0x8F58) != 0)                   //jnz short loc_13E10
    goto loc_13E10;
  sub_160A5();                                    //call sub_160A5
  goto loc_13DFD;                                 //jmp short loc_13DFD
loc_13E10:                                        //loc_13E10:
  memory(_ds, 0x8F58) = 0;                        //mov byte_31488, 0
  memory(_ds, 0x8F5B) = 0;                        //mov byte_3148B, 0
loc_13E1A:                                        //loc_13E1A:
  _ax = memory16(_ds, 0x9190);                    //mov ax, word_316C0
  memory16(_ds, 0xFCFE) = _ax;                    //mov word_3822E, ax
  _ax = memory16(_ds, 0x919A);                    //mov ax, word_316CA
  memory16(_ds, 0xFCE2) = _ax;                    //mov word_38212, ax
  _ax = memory16(_ds, 0xFCE2);                    //mov ax, word_38212
  if (_ax == memory16(_ds, 0x918C))               //jz short loc_13E46
    goto loc_13E46;
  memory16(_ds, 0x91A0) += 1;                     //inc word_316D0
  if ((short)memory16(_ds, 0x91A0) < (short)0x23) //jl short loc_13E4C
    goto loc_13E4C;
  memory16(_ds, 0xFCE2) <<= 1;                    //shl word_38212, 1
  _ax = memory16(_ds, 0xFCE2);                    //mov ax, word_38212
  memory16(_ds, 0x919A) = _ax;                    //mov word_316CA, ax
  goto loc_13E4C;                                 //jmp short loc_13E4C
loc_13E46:                                        //loc_13E46:
  memory16(_ds, 0x91A0) = 0;                      //mov word_316D0, 0
loc_13E4C:                                        //loc_13E4C:
  _ax = memory16(_ds, 0x9196);                    //mov ax, word_316C6
  memory16(_ds, 0xFCE6) = _ax;                    //mov word_38216, ax
  _ax = memory16(_ds, 0x918E);                    //mov ax, word_316BE
  memory16(_ds, 0xFCEA) = _ax;                    //mov word_3821A, ax
  _ax = memory16(_ds, 0x9190);                    //mov ax, word_316C0
  memory16(_ds, 0xFCEE) = _ax;                    //mov word_3821E, ax
  _ax = memory16(_ds, 0xFCE2);                    //mov ax, word_38212
  memory16(_ds, 0xFCEE) -= _ax;                   //sub word_3821E, ax
  _ax = memory16(_ds, 0x91A8);                    //mov ax, word_316D8
  if ((short)memory16(_ds, 0xFCEE) >= (short)_ax) //jge short loc_13E82
    goto loc_13E82;
  _ax = memory16(_ds, 0x91A8);                    //mov ax, word_316D8
  memory16(_ds, 0xFCEE) -= _ax;                   //sub word_3821E, ax
  _ax = memory16(_ds, 0xFCEE);                    //mov ax, word_3821E
  memory16(_ds, 0xFCE2) += _ax;                   //add word_38212, ax
  _ax = memory16(_ds, 0x91A8);                    //mov ax, word_316D8
  memory16(_ds, 0xFCEE) = _ax;                    //mov word_3821E, ax
loc_13E82:                                        //loc_13E82:
  _ax = memory16(_ds, 0x91AA);                    //mov ax, word_316DA
  if ((short)memory16(_ds, 0xFCEE) <= (short)_ax) //jle short loc_13E9F
    goto loc_13E9F;
  _ax = memory16(_ds, 0xFCEE);                    //mov ax, word_3821E
  memory16(_ds, 0xFCE2) += _ax;                   //add word_38212, ax
  _ax = memory16(_ds, 0x91AA);                    //mov ax, word_316DA
  memory16(_ds, 0xFCE2) -= _ax;                   //sub word_38212, ax
  _ax = memory16(_ds, 0x91AA);                    //mov ax, word_316DA
  memory16(_ds, 0xFCEE) = _ax;                    //mov word_3821E, ax
loc_13E9F:                                        //loc_13E9F:
  _ax = memory16(_ds, 0xFCE2);                    //mov ax, word_38212
  _flags.carry = memory16(_ds, 0xFCE6) < _ax;      //sub word_38216, ax
  memory16(_ds, 0xFCE6) -= _ax;
    _ASSERT(0);
  if (_flags.sign)                                 //js short loc_13EBB
    goto loc_13EBB;
  if ((short)memory16(_ds, 0xFCE6) < (short)0x10) //jl short loc_13EC5
    goto loc_13EC5;
  memory16(_ds, 0xFCE6) -= 0x10;                  //sub word_38216, 10h
  memory16(_ds, 0xFCEA) += 0x28;                  //add word_3821A, 28h
  goto loc_13EC5;                                 //jmp short loc_13EC5
loc_13EBB:                                        //loc_13EBB:
  memory16(_ds, 0xFCE6) += 0x10;                  //add word_38216, 10h
  memory16(_ds, 0xFCEA) -= 0x28;                  //sub word_3821A, 28h
loc_13EC5:                                        //loc_13EC5:
  _ax = memory16(_ds, 0xFCE2);                    //mov ax, word_38212
  memory16(_ds, 0x9198) = _ax;                    //mov word_316C8, ax
  _ax = memory16(_ds, 0xFCE6);                    //mov ax, word_38216
  memory16(_ds, 0x9196) = _ax;                    //mov word_316C6, ax
  _ax = memory16(_ds, 0xFCEA);                    //mov ax, word_3821A
  memory16(_ds, 0x918E) = _ax;                    //mov word_316BE, ax
  _ax = memory16(_ds, 0xFCEE);                    //mov ax, word_3821E
  memory16(_ds, 0x9190) = _ax;                    //mov word_316C0, ax
  _ax = memory16(_ds, 0x91AA);                    //mov ax, word_316DA
  if (memory16(_ds, 0xFCFE) != _ax)               //jnz short loc_13EED
    goto loc_13EED;
  if (memory(_ds, 0x8F59) & 2)                    //jnz short loc_13EF4
    goto loc_13EF4;
loc_13EED:                                        //loc_13EED:
  _ax = memory16(_ds, 0x91AE);                    //mov ax, word_316DE
  memory16(_ds, 0xFCEE) += _ax;                   //add word_3821E, ax
loc_13EF4:                                        //loc_13EF4:
  _ax = memory16(_ds, 0x91AA);                    //mov ax, word_316DA
  if ((short)memory16(_ds, 0xFCEE) > (short)_ax)  //jg short loc_13F03
    goto loc_13F03;
  _ax = memory16(_ds, 0xFCEE);                    //mov ax, word_3821E
  memory16(_ds, 0x91AA) = _ax;                    //mov word_316DA, ax
loc_13F03:                                        //loc_13F03:
  sub_10A2F();                                    //call sub_10A2F
  sub_10D81();                                    //call sub_10D81
  if (memory(_ds, 0x8F5C) != 0)                   //jnz short loc_13F13
    goto loc_13F13;
  goto loc_13FAA;                                 //jmp loc_13FAA
loc_13F13:                                        //loc_13F13:
  memory(_ds, 0x8F5C) = 0;                        //mov byte_3148C, 0
  memory16(_ds, 0x9132) = 1;                      //mov word_31662, 1
  memory16(_ds, 0x9186) = 0x27;                   //mov word_316B6, 27h
  memory(_ds, 0x8FAF) = 0xff;                     //mov byte_314DF, 0FFh
  memory16(_ds, 0x918A) -= 1;                     //dec word_316BA
  sub_10E91();                                    //call sub_10E91
  if (memory16(_ds, 0x918A) != 0)                 //jnz short loc_13F9A
    goto loc_13F9A;
  sub_10D5F();                                    //call sub_10D5F
  sub_159C8();                                    //call sub_159C8
  sub_10D5F();                                    //call sub_10D5F
  memory16(_ds, 0x91B0) -= 1;                     //dec word_316E0
  if (memory16(_ds, 0x91B0) == 0)                 //jz short loc_13F7B
    goto loc_13F7B;
  sub_15C0F();                                    //call sub_15C0F
  if (_ax == 0x0000)                              //jz short loc_13F7B
    goto loc_13F7B;
  memory16(_ds, 0x918A) = 3;                      //mov word_316BA, 3
  sub_10E91();                                    //call sub_10E91
  memory16(_ds, 0x9152) = 0;                      //mov word_31682, 0
  memory16(_ds, 0x9154) = 0;                      //mov word_31684, 0
  _di = 0x921c;                                   //mov di, 921Ch
  _cx = 0x0007;                                   //mov cx, 7
  _al = _al ^ _al;                                //xor al, al
  _rep_stosb<MemAuto, DirAuto>();                 //rep stosb
  memory16(_ds, 0x9156) = 0;                      //mov word_31686, 0
  memory16(_ds, 0x9158) = 0;                      //mov word_31688, 0
  sub_10E6F();                                    //call sub_10E6F
  goto loc_13F9A;                                 //jmp short loc_13F9A
loc_13F7B:                                        //loc_13F7B:
  _si = 0x3729;                                   //mov si, 3729h
  _cx = 0x1e;                                     //mov cx, 1Eh
  sub_15926();                                    //call sub_15926
  _bx = memory16(_ds, 0x8E7A);                    //mov bx, word_313AA
  memory(_ds, _bx + -28835) = 0;                  //mov byte ptr [bx-70A3h], 0
  _bx = _bx ^ 0x0001;                             //xor bx, 1
  if (memory(_ds, _bx + -28835) != 0)             //jnz short loc_13F9A
    goto loc_13F9A;
  goto loc_13C9D;                                 //jmp loc_13C9D
loc_13F9A:                                        //loc_13F9A:
  sub_11A62();                                    //call sub_11A62
  if (memory(_ds, 0x8F54) == 0)                   //jz short loc_13FAA
    goto loc_13FAA;
  _ah = 0x02;                                     //mov ah, 2
  _al = 0x00;                                     //mov al, 0
  _interrupt(0x80);                               //int 80h
loc_13FAA:                                        //loc_13FAA:
  if (memory16(_ds, 0x9164) == 0)                 //jz short loc_13FB4
    goto loc_13FB4;
  goto loc_13D26;                                 //jmp loc_13D26
loc_13FB4:                                        //loc_13FB4:
  if (memory(_ds, 0x8FB0) != 0)                   //jnz short loc_13FC8
    goto loc_13FC8;
  if (memory(_ds, 0x8F61) == 0)                   //jz short loc_13FC5
    goto loc_13FC5;
  goto loc_140A7;                                 //jmp loc_140A7
loc_13FC5:                                        //loc_13FC5:
  goto loc_13D26;                                 //jmp loc_13D26
loc_13FC8:                                        //loc_13FC8:
  _ah = 0x01;                                     //mov ah, 1
  _interrupt(0x80);                               //int 80h
  if ((short)memory16(_ds, 0x9190) > (short)480)  //jg short loc_1400D
    goto loc_1400D;
  _ax = memory16(_ds, 0x8EAC);                    //mov ax, word_313DC
  memory16(_ds, 0xFCE6) = _ax;                    //mov word_38216, ax
  _ax = memory16(_ds, 0xFCE6);                    //mov ax, word_38216
  memory16(_ds, 0x8F4A) = _ax;                    //mov word_3147A, ax
  memory16(_ds, 0xFCE6) += 400;                   //add word_38216, 190h
  if (memory16(_ds, 0x915C) != 0)                 //jnz short loc_1403E
    goto loc_1403E;
  _ax = memory16(_ds, 0x915A);                    //mov ax, word_3168A
  if ((short)memory16(_ds, 0xFCE6) <= (short)_ax) //jle short loc_1403E
    goto loc_1403E;
  sub_14191();                                    //call sub_14191
  _ax &= 0x0003;                                  //and ax, 3
  _dx = 0x32;                                     //mov dx, 32h
  _ax = _dx * _al;                                //mul dx
  memory16(_ds, 0xFCE6) += _ax;                   //add word_38216, ax
  _ax = memory16(_ds, 0xFCE6);                    //mov ax, word_38216
  memory16(_ds, 0x915A) = _ax;                    //mov word_3168A, ax
  goto loc_1403E;                                 //jmp short loc_1403E
loc_1400D:                                        //loc_1400D:
  _ax = memory16(_ds, 0x8EAE);                    //mov ax, word_313DE
  memory16(_ds, 0xFCE6) = _ax;                    //mov word_38216, ax
  _ax = memory16(_ds, 0xFCE6);                    //mov ax, word_38216
  memory16(_ds, 0x8F4A) = _ax;                    //mov word_3147A, ax
  if (memory16(_ds, 0x915C) != 0)                 //jnz short loc_1403E
    goto loc_1403E;
  _ax = memory16(_ds, 0x915A);                    //mov ax, word_3168A
  if ((short)memory16(_ds, 0xFCE6) <= (short)_ax) //jle short loc_1403E
    goto loc_1403E;
  sub_14191();                                    //call sub_14191
  _ax &= 0x0003;                                  //and ax, 3
  _dx = 0x32;                                     //mov dx, 32h
  _ax = _dx * _al;                                //mul dx
  memory16(_ds, 0xFCE6) += _ax;                   //add word_38216, ax
  _ax = memory16(_ds, 0xFCE6);                    //mov ax, word_38216
  memory16(_ds, 0x915A) = _ax;                    //mov word_3168A, ax
loc_1403E:                                        //loc_1403E:
  memory(_ds, 0x9223) = 0;                        //mov byte_31753, 0
  memory(_ds, 0x8FB1) = 0;                        //mov byte_314E1, 0
  if ((short)memory16(_ds, 0x9190) > (short)960)  //jg short loc_14078
    goto loc_14078;
  if (memory16(_ds, 0x991C) != 5)                 //jnz short loc_14078
    goto loc_14078;
  memory(_ds, 0x8FB1) = 0xff;                     //mov byte_314E1, 0FFh
  if (memory16(_ds, 0x8E70) != 2)                 //jnz short loc_14078
    goto loc_14078;
  _bx = (memory16(_ds, 0x8E7A)) ^ 0x0001;         //xor bx, 1
  if (memory(_ds, _bx + -28835) == 0)             //jz short loc_14078
    goto loc_14078;
  if (memory(_ds, _bx + -28833) == 0)             //jz short loc_1407E
    goto loc_1407E;
loc_14078:                                        //loc_14078:
  sub_14A69();                                    //call sub_14A69
  sub_10E91();                                    //call sub_10E91
loc_1407E:                                        //loc_1407E:
  memory(_ds, 0x8FB0) = 0;                        //mov byte_314E0, 0
  if (memory16(_ds, 0x9162) == 0)                 //jz short loc_1408D
    goto loc_1408D;
  sub_12B22();                                    //call sub_12B22
loc_1408D:                                        //loc_1408D:
  if (memory(_ds, 0x8F61) != 0)                   //jnz short loc_140A7
    goto loc_140A7;
  if (memory(_ds, 0x8F54) != 0)                   //jnz short loc_1409E
    goto loc_1409E;
  goto loc_13D26;                                 //jmp loc_13D26
loc_1409E:                                        //loc_1409E:
  _ah = 0x02;                                     //mov ah, 2
  _al = 0x00;                                     //mov al, 0
  _interrupt(0x80);                               //int 80h
  goto loc_13D26;                                 //jmp loc_13D26
loc_140A7:                                        //loc_140A7:
  memory(_ds, 0x8F61) = 0;                        //mov byte_31491, 0
  if (memory16(_ds, 0x991C) != 5)                 //jnz short loc_140CB
    goto loc_140CB;
loc_140B3:                                        //loc_140B3:
  _si = memory16(_ds, 0x9008);                    //mov si, word_31538
  if (memory16(_ds, _si) == 0)                    //jz short loc_140C1
    goto loc_140C1;
  sub_137A9();                                    //call sub_137A9
  goto loc_140B3;                                 //jmp short loc_140B3
loc_140C1:                                        //loc_140C1:
  sub_13319();                                    //call sub_13319
  sub_135EB();                                    //call sub_135EB
  memory16(_ds, 0x91B0) += 1;                     //inc word_316E0
loc_140CB:                                        //loc_140CB:
  _bx = (memory16(_ds, 0x8E7A)) ^ 0x0001;         //xor bx, 1
  if (memory(_ds, _bx + -28835) == 0)             //jz short loc_14116
    goto loc_14116;
  if (memory(_ds, _bx + -28833) != 0)             //jnz short loc_14116
    goto loc_14116;
  _bx = _bx ^ 0x0001;                             //xor bx, 1
  memory(_ds, _bx + -28833) = 0xff;               //mov byte ptr [bx-70A1h], 0FFh
  sub_118F5();                                    //call sub_118F5
  _si = memory16(_ds, 0x9054);                    //mov si, word_31584
  sub_13760();                                    //call sub_13760
  _si = memory16(_ds, 0x90EC);                    //mov si, word_3161C
  sub_13760();                                    //call sub_13760
  _si = memory16(_ds, 0x90A0);                    //mov si, word_315D0
  sub_13760();                                    //call sub_13760
  sub_11A65();                                    //call sub_11A65
  if (memory(_ds, 0x8F54) != 0)                   //jnz short loc_1410D
    goto loc_1410D;
  goto loc_13D26;                                 //jmp loc_13D26
loc_1410D:                                        //loc_1410D:
  _ah = 0x02;                                     //mov ah, 2
  _al = 0x00;                                     //mov al, 0
  _interrupt(0x80);                               //int 80h
  goto loc_13D26;                                 //jmp loc_13D26
loc_14116:                                        //loc_14116:
  sub_10D5F();                                    //call sub_10D5F
  sub_118F5();                                    //call sub_118F5
  _si = memory16(_ds, 0x9054);                    //mov si, word_31584
  sub_13760();                                    //call sub_13760
  _si = memory16(_ds, 0x90EC);                    //mov si, word_3161C
  sub_13760();                                    //call sub_13760
  _si = memory16(_ds, 0x90A0);                    //mov si, word_315D0
  sub_13760();                                    //call sub_13760
  memory16(_ds, 0x991C) += 1;                     //inc word_31E4C
  if ((short)memory16(_ds, 0x991C) < (short)6)    //jl short loc_14146
    goto loc_14146;
  memory16(_ds, 0x991C) = 1;                      //mov word_31E4C, 1
  memory16(_ds, 0x991A) += 1;                     //inc word_31E4A
loc_14146:                                        //loc_14146:
  _ax = (memory16(_ds, 0x991C)) + 0x30;           //add ax, 30h
  memory(_ds, 0x3550) = _al;                      //mov byte_2BA80, al
  sub_15CC5();                                    //call sub_15CC5
  sub_1193C();                                    //call sub_1193C
  if (memory16(_ds, 0x9162) == 0)                 //jz short loc_1415F
    goto loc_1415F;
  sub_12B22();                                    //call sub_12B22
loc_1415F:                                        //loc_1415F:
  sub_11B43();                                    //call sub_11B43
  memory(_ds, 0x8F5F) = 0;                        //mov byte_3148F, 0
  memory(_ds, 0x8F60) = 0;                        //mov byte_31490, 0
  sub_11A62();                                    //call sub_11A62
  sub_10985();                                    //call sub_10985
  sub_1080F();                                    //call sub_1080F
  sub_10A2F();                                    //call sub_10A2F
  sub_10E2B();                                    //call sub_10E2B
  sub_10D81();                                    //call sub_10D81
  if (memory(_ds, 0x8F54) != 0)                   //jnz short loc_14188
    goto loc_14188;
  goto loc_13D26;                                 //jmp loc_13D26
loc_14188:                                        //loc_14188:
  _ah = 0x02;                                     //mov ah, 2
  _al = 0x00;                                     //mov al, 0
  _interrupt(0x80);                               //int 80h
  goto loc_13D26;                                 //jmp loc_13D26
}

void sub_15EC3()
{
  _flags.interrupt = false;                        //cli
  _al = memory(_ds, 0x3042);                      //mov al, byte_2B572
  _out(0x61, _al);                                //out 61h, al
  _al = 0x36;                                     //mov al, 36h
  _out(0x43, _al);                                //out 43h, al
  _dx = 0xffff;                                   //mov dx, 0FFFFh
  _al = _dl;                                      //mov al, dl
  _out(0x40, _al);                                //out 40h, al
  _al = _dh;                                      //mov al, dh
  _out(0x40, _al);                                //out 40h, al
  _in(_al, 0x61);                                 //in al, 61h
  _flags.interrupt = true;                         //sti
  _ax = 0x2508;                                   //mov ax, 2508h
  _push(_ds);                                     //push ds
  _dx = memory16(_ds, 0x8E62);                    //mov dx, word_31392
  _ds = memory16(_ds, 0x8E64);                    //mov ds, word_31394
  _interrupt(0x21);                               //int 21h
  _ds = _pop();                                   //pop ds
}

void sub_15E7A()
{
  _ax = 0x2509;                                   //mov ax, 2509h
  _push(_ds);                                     //push ds
  _dx = memory16(_ds, 0x8E66);                    //mov dx, word_31396
  _ds = memory16(_ds, 0x8E68);                    //mov ds, word_31398
  _interrupt(0x21);                               //int 21h
  _ds = _pop();                                   //pop ds
}


//

void sub_10000()
{
  _ax = _ds;                                      //mov ax, ds
  _es = _ax;                                      //mov es, ax
  _cx = 0x0008;                                   //mov cx, 8
  _di = 0x8e58;                                   //mov di, 8E58h
  _al = 0xff;                                     //mov al, 0FFh
  _rep_stosb<MemAuto, DirAuto>();                 //rep stosb
  _ax = 0x1a00;                                   //mov ax, 1A00h
  _interrupt(0x10);                               //int 10h
  if (_al != 0x1a)                                //jnz short loc_10032
    goto loc_10032;
  if (_bl >= _bh)                                 //jnb short loc_1001D
    goto loc_1001D;
  _bl = _bh;                                      //mov bl, bh
loc_1001D:                                        //loc_1001D:
  if (_bl < 0x0b)                                 //jb short loc_1002C
    goto loc_1002C;
  if (_bl > 0x0c)                                 //ja short loc_1002C
    goto loc_1002C;
  memory(_ds, 0x8E5A) = 0;                        //mov byte_3138A, 0
loc_1002C:                                        //loc_1002C:
  memory(_ds, 0x8E58) = 0;                        //mov byte_31388, 0
  return;                                         //retn
loc_10032:                                        //loc_10032:
  memory(_ds, 0x8E59) = 0;                        //mov byte_31389, 0
  sub_10067();                                    //call sub_10067
  sub_10089();                                    //call sub_10089
  sub_10097();                                    //call sub_10097
  _dx = 0x03b4;                                   //mov dx, 3B4h
  sub_10101();                                    //call sub_10101
  if (_flags.carry)                                //jb short loc_1005C
    goto loc_1005C;
  _dl = 0xba;                                     //mov dl, 0BAh
  _in(_al, _dx);                                  //in al, dx
  _al &= 0x80;                                    //and al, 80h
  _ah = _al;                                      //mov ah, al
  _cx = 0x8000;                                   //mov cx, 8000h
loc_10052:                                        //loc_10052:
  _in(_al, _dx);                                  //in al, dx
  _al &= 0x80;                                    //and al, 80h
  if (--_cx && _al == _ah)                        //loope loc_10052
    goto loc_10052;
  if (_al == _ah)                                 //jz short loc_10061
    goto loc_10061;
  return;                                         //retn
loc_1005C:                                        //loc_1005C:
  memory(_ds, 0x8E5C) = 0;                        //mov byte_3138C, 0
loc_10061:                                        //loc_10061:
  memory(_ds, 0x8E5D) = 0;                        //mov byte_3138D, 0
}

void sub_10101()
{
  _al = 0x0f;                                     //mov al, 0Fh
  _out(_dx, _al);                                 //out dx, al
  _out(_dx, _al);                                 //out dx, al
  _dx += 1;                                       //inc dx
  _in(_al, _dx);                                  //in al, dx
  _ah = _al;                                      //mov ah, al
  _al = 0x66;                                     //mov al, 66h
  _out(_dx, _al);                                 //out dx, al
  _cx = 0x0100;                                   //mov cx, 100h
loc_1010F:                                        //loc_1010F:
  if (--_cx)                                      //loop loc_1010F
    goto loc_1010F;
  _in(_al, _dx);                                  //in al, dx
  _xchg(_al, _ah);                                //xchg al, ah
  _out(_dx, _al);                                 //out dx, al
    _flags.carry = false; // TODO: manual
  if (_ah == 0x66)                                //jz short locret_1011B
    goto locret_1011B;
  _flags.carry = true;                             //stc
locret_1011B:                                     //locret_1011B:
    return;
}

void sub_10067()
{
  _bl = 0x10;                                     //mov bl, 10h
  _ah = 0x12;                                     //mov ah, 12h
  _interrupt(0x10);                               //int 10h
  if (_bl == 0x10)                                //jz short loc_10083
    goto loc_10083;
  _ah = 0x12;                                     //mov ah, 12h
  _bl = 0x10;                                     //mov bl, 10h
  _interrupt(0x10);                               //int 10h
  if (_bl >= 0x03)                                //jnb short locret_10082
    goto locret_10082;
  memory(_ds, 0x8E5E) = 0;                        //mov byte_3138E, 0
locret_10082:                                     //locret_10082:
  return;                                         //retn
loc_10083:                                        //loc_10083:
  memory(_ds, 0x8E5A) = 0;                        //mov byte_3138A, 0
}

void sub_10089()
{
  _dx = 0x03d4;                                   //mov dx, 3D4h
  sub_10101();                                    //call sub_10101
  if (!_flags.carry)                               //jnb short locret_10096
    goto locret_10096;
  memory(_ds, 0x8E5B) = 0;                        //mov byte_3138B, 0
locret_10096:                                     //locret_10096:
    return;
}

void sub_10097()
{
  _bx = 0xb800;                                   //mov bx, 0B800h
  _es = _bx;                                      //mov es, bx
  _di = _di ^ _di;                                //xor di, di
  _push(memory16(_es, 0));                        //push word ptr es:0
  memory16(_es, 0) = 16714;                       //mov word ptr es:0, 414Ah
  _interrupt(0x12);                               //int 12h
  _ax = ((_ax + 0x3f) & 0xffc0) - 0x40;           //sub ax, 40h
  _cl = 0x06;                                     //mov cl, 6
  _ax <<= _cl;                                    //shl ax, cl
  _es = _ax;                                      //mov es, ax
  _dx = _ax;                                      //mov dx, ax
  _ax = 0x414a;                                   //mov ax, 414Ah
  _cx = 0x8000;                                   //mov cx, 8000h
loc_100C3:                                        //loc_100C3:
  _repne_scasw();                                 //repne scasw
  if (_ax == 0)                                   //jz short loc_100D6
    goto loc_100D6;
  _es = _bx;                                      //mov es, bx
  _di = _di ^ _di;                                //xor di, di
  memory16(_es, 0) = _pop();                      //pop word ptr es:0
  memory(_ds, 0x8E58) = 0;                        //mov byte_31388, 0
  return;                                         //retn
loc_100D6:                                        //loc_100D6:
  _di -= 0x0002;                                  //sub di, 2
  _es = _bx;                                      //mov es, bx
  memory16(_es, 0) = 18505;                       //mov word ptr es:0, 4849h
  _es = _dx;                                      //mov es, dx
  if (memory16(_es, _di) != 18505)                //jnz short loc_100F1
    goto loc_100F1;
  memory16(_es, 0) = _pop();                      //pop word ptr es:0
  return;                                         //retn
loc_100F1:                                        //loc_100F1:
  _es = _bx;                                      //mov es, bx
  memory16(_es, 0) = 16714;                       //mov word ptr es:0, 414Ah
  _es = _dx;                                      //mov es, dx
  _di += 0x0002;                                  //add di, 2
  goto loc_100C3;                                 //jmp short loc_100C3
}

void sub_106FE() // Zobrazi menu (herc, cga, tandy, ega, vga, customize keys)
{
  _si = 0x2efd;                                   //mov si, 2EFDh
  _cx = _cx ^ _cx;                                //xor cx, cx
loc_10703:                                        //loc_10703:
  _bl = 0x07;                                     //mov bl, 7
  if (_cx != memory16(_ds, 0x3044))               //jnz short loc_10716
    goto loc_10716;
  _bl = 0x1f;                                     //mov bl, 1Fh
  if (memory(_ds, 0x2EF4) != 7)                   //jnz short loc_10716
    goto loc_10716;
  _bl = 0xf0;                                     //mov bl, 0F0h
loc_10716:                                        //loc_10716:
  memory(_ds, 0x2EF7) = _bl;                      //mov byte_2B427, bl
  _lodsb<MemAuto, DirAuto>();                     //lodsb
  if (!(_al & _al))                               //jz short locret_10760
    goto locret_10760;
  _al = (-(_al - memory(_ds, 0x2EF5))) >> 1;      //shr al, 1
  memory(_ds, 0x2EF2) = _al;                      //mov byte_2B422, al
  _lodsb<MemAuto, DirAuto>();                     //lodsb
  memory(_ds, 0x2EF6) = _al;                      //mov byte_2B426, al
  _push(_cx);                                     //push cx
loc_1072F:                                        //loc_1072F:
  _lodsb<MemAuto, DirAuto>();                     //lodsb
  if (!(_al & _al))                               //jz short loc_1075C
    goto loc_1075C;
  _ah = 0x02;                                     //mov ah, 2
  _bh = memory(_ds, 0x2EF3);                      //mov bh, byte_2B423
  _dh = memory(_ds, 0x2EF6);                      //mov dh, byte_2B426
  _dl = memory(_ds, 0x2EF2);                      //mov dl, byte_2B422
  _interrupt(0x10);                               //int 10h
  memory(_ds, 0x2EF2) += 1;                       //inc byte_2B422
  _al = memory(_ds, _si - 1);                     //mov al, [si-1]
  _ah = 0x09;                                     //mov ah, 9
  _bl = memory(_ds, 0x2EF7);                      //mov bl, byte_2B427
  _bh = memory(_ds, 0x2EF3);                      //mov bh, byte_2B423
  _cx = 0x0001;                                   //mov cx, 1
  _interrupt(0x10);                               //int 10h
  goto loc_1072F;                                 //jmp short loc_1072F
loc_1075C:                                        //loc_1075C:
  _cx = _pop();                                   //pop cx
  _cx += 1;                                       //inc cx
  goto loc_10703;                                 //jmp short loc_10703
locret_10760:                                     //locret_10760:
    return;
}

void sub_1F2D5()
{
  _di = 0x973e;                                   //mov di, 973Eh
  _ax = _ax ^ _ax;                                //xor ax, ax
  _cx = 0xc8;                                     //mov cx, 0C8h
loc_1F2DD:                                        //loc_1F2DD:
  _stosw<MemAuto, DirAuto>();                     //stosw
  _ax += 0x28;                                    //add ax, 28h
  if (--_cx)                                      //loop loc_1F2DD
    goto loc_1F2DD;
}

void sub_seg001_00() // vga
{
    sub_1F2D5();
    _ax = 0x0d;
    _interrupt(0x10);
    _ax = 0x1002;
    _dx = 0x425d;
    _interrupt(0x10);
    _ax = 0x1001;
    _bh = 0;
    _interrupt(0x10);
    _ax = 0x40;
    _es = _ax;
    _dx = memory16(0x0040, 0x0063);
    memory16(_ds, /*0x2c787-0x28530*/ 0x4257) = _dx;
    _ax = _ds;
    _es = _ax;
}

void sub_seg001_2a() // vga?
{
    sub_1F2D5();
    _ax = 0x0d;
    _interrupt(0x10);
    _ax = 0x40;
    _es = _ax;
    _dx = memory16(_es, 0x63); // 0040:0063 = Video controller base I/O port address
    int ppp = memory16(_ds, /*0x2c787-0x28530*/ 0x4257);
    memory16(_ds, /*0x2c787-0x28530*/ 0x4257) = _dx;
    _ax = _ds;
    _es = _ax;
}

void sub_1034C()
{
  sub_103DD();                                    //call sub_103DD
  _si = _ax;                                      //mov si, ax
  _dl = memory(_ds, _si + 9074);                  //mov dl, [si+2372h]
  _dh = 0x00;                                     //mov dh, 0
  _cl = 0x06;                                     //mov cl, 6
  _dx <<= _cl;                                    //shl dx, cl
  _push(_dx);                                     //push dx
  _cl = memory(_ds, _si + 9330);                  //mov cl, [si+2472h]
    _ASSERT(_cl >= 2);
  _ch = 0x00;                                     //mov ch, 0
  _cx -= 0x0002;                                  //sub cx, 2
  sub_103FD();                                    //call sub_103FD
  _ax |= _si;                                     //or ax, si
  _rol(_ax, _cl);                                 //rol ax, cl
  _ax &= 0x3f;                                    //and ax, 3Fh
  _dx = _pop();                                   //pop dx
  _ax += _dx;                                     //add ax, dx
}

void sub_103DD()
{
  _dx = memory16(_ds, 0x112C);                    //mov dx, word_2965C
  if ((char)memory(_ds, 0x112E) > (char)8)        //jg short loc_103EB
    goto loc_103EB;
  sub_104C9();                                    //call sub_104C9
loc_103EB:                                        //loc_103EB:
  _xchg(_dl, _dh);                                //xchg dl, dh
  _ax = _dx;                                      //mov ax, dx
  _dl = _dl ^ _dl;                                //xor dl, dl
  memory16(_ds, 0x112C) = _dx;                    //mov word_2965C, dx
  memory(_ds, 0x112E) -= 8;                       //sub byte_2965E, 8
  _ah = _ah ^ _ah;                                //xor ah, ah
}

void sub_103FD()
{
  _push(_cx);                                     //push cx
  _dx = memory16(_ds, 0x112C);                    //mov dx, word_2965C
  if ((char)memory(_ds, 0x112E) > (char)8)        //jg short loc_1040C
    goto loc_1040C;
  sub_104C9();                                    //call sub_104C9  -- read data 2565:216c
loc_1040C:                                        //loc_1040C:
  _cx = _pop();                                   //pop cx
  _ax = _dx;                                      //mov ax, dx
  _dx <<= _cl;                                    //shl dx, cl
  memory16(_ds, 0x112C) = _dx;                    //mov word_2965C, dx
  memory(_ds, 0x112E) -= _cl;                     //sub byte_2965E, cl
  _dx = 0xffff;                                   //mov dx, 0FFFFh
  _dx >>= _cl;                                    //shr dx, cl
  _dx = (~_dx);                                   //not dx
  _ax &= _dx;                                     //and ax, dx
}

void sub_10423()
{
  _push(_si);                                     //push si
  _ax = _ds;                                      //mov ax, ds
  _es = _ax;                                      //mov es, ax
  _si = _si ^ _si;                                //xor si, si
  _di = _si;                                      //mov di, si
loc_1042C:                                        //loc_1042C:
  if (memory16(_ds, _si + 3142) < 1254)           //jb short loc_10449
    goto loc_10449;
  _ax = memory16(_ds, _si + 4);                   //mov ax, [si+4]
  _ax += 1;                                       //inc ax
  _ax >>= 1;                                      //shr ax, 1
  memory16(_ds, _di + 4) = _ax;                   //mov [di+4], ax
  _ax = memory16(_ds, _si + 3142);                //mov ax, [si+0C46h]
  memory16(_ds, _di + 3142) = _ax;                //mov [di+0C46h], ax
  _di += 1;                                       //inc di
  _di += 1;                                       //inc di
loc_10449:                                        //loc_10449:
  _si += 1;                                       //inc si
  _si += 1;                                       //inc si
  if (_si < 0x04e6)                               //jb short loc_1042C
    goto loc_1042C;
  _si = _si ^ _si;                                //xor si, si
  _di = 0x0274;                                   //mov di, 274h
loc_10456:                                        //loc_10456:
  _bx = _si;                                      //mov bx, si
  _bx += 1;                                       //inc bx
  _bx += 1;                                       //inc bx
  _ax = memory16(_ds, _si + 4);                   //mov ax, [si+4]
  _ax = _ax + memory16(_ds, _bx + 4);             //add ax, [bx+4]
  memory16(_ds, _di + 4) = _ax;                   //mov [di+4], ax
  _bx = _di;                                      //mov bx, di
loc_10468:                                        //loc_10468:
  _bx -= 1;                                       //dec bx
  _bx -= 1;                                       //dec bx
  if (_ax < memory16(_ds, _bx + 4))               //jb short loc_10468
    goto loc_10468;
  _bx += 1;                                       //inc bx
  _bx += 1;                                       //inc bx
  _cx = _di;                                      //mov cx, di
  _cx -= _bx;                                     //sub cx, bx
  _cx >>= 1;                                      //shr cx, 1
  _flags.direction = true;                         //std
  _push(_cx);                                     //push cx
  _push(_si);                                     //push si
  _push(_di);                                     //push di
  _lea(_si, memory16(_ds, _di + 4));              //lea si, [di+4]
  _di = _si;                                      //mov di, si
  _si -= 1;                                       //dec si
  _si -= 1;                                       //dec si
  _rep_movsw<MemAuto, MemAuto, DirAuto>();        //rep movsw
  memory16(_ds, _bx + 4) = _ax;                   //mov [bx+4], ax
  _di = _pop();                                   //pop di
  _si = _pop();                                   //pop si
  _cx = _pop();                                   //pop cx
  _push(_si);                                     //push si
  _push(_di);                                     //push di
  _lea(_si, memory16(_ds, _di + 3142));           //lea si, [di+0C46h]
  _di = _si;                                      //mov di, si
  _si -= 1;                                       //dec si
  _si -= 1;                                       //dec si
  _rep_movsw<MemAuto, MemAuto, DirAuto>();        //rep movsw
  _di = _pop();                                   //pop di
  _si = _pop();                                   //pop si
  memory16(_ds, _bx + 3142) = _si;                //mov [bx+0C46h], si
  _si += 0x0004;                                  //add si, 4
  _di += 0x0002;                                  //add di, 2
  if (_di < 0x04e6)                               //jb short loc_10456
    goto loc_10456;
  _si = _si ^ _si;                                //xor si, si
loc_104AD:                                        //loc_104AD:
  _di = memory16(_ds, _si + 3142);                //mov di, [si+0C46h]
  memory16(_ds, _di + 1260) = _si;                //mov [di+4ECh], si
  if (_di >= 0x04e6)                              //jnb short loc_104BF
    goto loc_104BF;
  memory16(_ds, _di + 1262) = _si;                //mov [di+4EEh], si
loc_104BF:                                        //loc_104BF:
  _si += 1;                                       //inc si
  _si += 1;                                       //inc si
  if (_si < 0x04e6)                               //jb short loc_104AD
    goto loc_104AD;
  _si = _pop();                                   //pop si
}


