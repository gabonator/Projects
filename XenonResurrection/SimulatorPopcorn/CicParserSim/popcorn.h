void start();
void sub_2ACA5();
void sub_2ACB0();
void sub_2AD26();
void sub_2AFD0();
void sub_2AFF1();
void sub_2B06B();
void sub_2B093();
void sub_2B141();
void sub_2B355();
void sub_2B3AB();
void sub_2B4E8();
void sub_2B72B();
void sub_2B8E5();
void sub_2B94E();
void sub_2BCFE();
void sub_2BE32();
void sub_2C0D3();
void sub_2C129();
void sub_2C1A1();
void sub_2C493();
void sub_2CAD9();
void sub_2ECE0();
void sub_2F52D();
void sub_2F5DC();
void sub_2F69A();
void sub_2F700();
void sub_2F76F();
void sub_2F9B6();
void sub_2FA3A();
void sub_2FCB9();
void sub_2FCDC();
void sub_2FCFF();
void sub_2FD91();
void sub_2FDB6();
void sub_2FFE2();
void sub_30096();
void sub_300F6();
void sub_30205();
void sub_302A0();
void sub_30560();
void sub_2ACB7();
void sub_2B17E();
void sub_2B218();
void sub_2B531();
void sub_2B5E5();
void sub_2B884();
void sub_2BCAC();
void sub_2BCE5();
void sub_2BCF1();
void sub_2BF74();
void sub_2BFD8();
void sub_2C234();
void sub_2C262();
void sub_2C26C();
void sub_2C86F();
void sub_2CBE1();
void sub_2CC54();
void sub_2CCD9();
void sub_2CD29();
void sub_2CD68();
void sub_2CDA7();
void sub_2CE3A();
void sub_2CEA1();
void sub_2CEC9();
void sub_2CEFE();
void sub_2D09F();
void sub_2D3F7();
void sub_2D447();
void sub_2D4A1();
void sub_2DA3E();
void sub_2DB03();
void sub_2DD66();
void sub_2DE52();
void sub_2DE77();
void sub_2E288();
void sub_2E31B();
void sub_2E9B5();
void sub_2EDF4();
void sub_2F54F();
void sub_2F577();
void sub_2F79A();
void sub_2F957();
void sub_2F9DB();
void sub_2FA0A();
void sub_2FB78();
void sub_2FB93();
void sub_2FD60();
void sub_2FDD6();
void sub_300AA();
void sub_30663();
void sub_30676();
void sub_307A0();
void sub_307D5();
void sub_2B1B8();
void sub_2B63D();
void sub_2C0C7();
void sub_2CA43();
void sub_2CA70();
void sub_2CF36();
void sub_2D16D();
void sub_2D375();
void sub_2DC8B();
void sub_2DCFD();
void sub_2EDD1();
void sub_2EE05();
void sub_2F8E1();
void sub_2F97D();
void sub_2FA24();
void sub_2FBC7();
void sub_2FBF3();
void sub_2FC11();
void sub_2FC39();
void sub_2FC65();
void sub_2FF37();
void sub_2FFAD();
void sub_30068();
void sub_30617();
void sub_306FD();
void sub_30856();
void sub_2D3D7();

void start()
{
    WORD _cs = _seg004;
    _ax = _seg003;                              //mov ax, seg seg003
    _ss = _ax;                                  //mov ss, ax
    _sp = 0x80;                                 //mov sp, 80h
    _ax = _seg000;                              //mov ax, seg seg000
    _es = _ax;                                  //mov es, ax
    _di = 0x13a0;                               //mov di, 13A0h
    _si = 0x80;                                 //mov si, 80h
    _cx = 0x20;                                 //mov cx, 20h
    _flags.direction = false;                   //cld
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _ds = _ax;                                  //mov ds, ax
    sub_302A0();                                //call sub_302A0
    _ah = 0x19;                                 //mov ah, 19h
    _interrupt(0x21);                           //int 21h
    memory(_ds, 0x141B) = _al;                  //mov byte_1141B, al
    if (memory(_ds, 0x13A0) == 0)               //jz short loc_2ADAA
      goto loc_2ADAA;
    _ch = _ch ^ _ch;                            //xor ch, ch
    _cl = memory(_ds, 0x13A0);                  //mov cl, byte_113A0
    _cl -= 1;                                   //dec cl
    if (_cl == 0)                               //jz short loc_2ADAA
      goto loc_2ADAA;
    _si = 0x13a2;                               //mov si, 13A2h
loc_2AD6C:                                      //loc_2AD6C:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    if (_al != 0x20)                            //jnz short loc_2AD77
      goto loc_2AD77;
    _cl -= 1;                                   //dec cl
    if (_cl == 0)                               //jz short loc_2ADAA
      goto loc_2ADAA;
    goto loc_2AD6C;                             //jmp short loc_2AD6C
loc_2AD77:                                      //loc_2AD77:
    _si -= 1;                                   //dec si
    _di = 0x1428;                               //mov di, 1428h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _si = 0x1428;                               //mov si, 1428h
loc_2AD80:                                      //loc_2AD80:
    if (memory(_ds, _si) != 0x2e)               //jnz short loc_2AD88
      goto loc_2AD88;
    _si += 1;                                   //inc si
    goto loc_2AD80;                             //jmp short loc_2AD80
loc_2AD88:                                      //loc_2AD88:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz short loc_2AD93
      goto loc_2AD93;
    if (_al == 0x2e)                            //jz short loc_2ADA7
      goto loc_2ADA7;
    goto loc_2AD88;                             //jmp short loc_2AD88
loc_2AD93:                                      //loc_2AD93:
    _si -= 1;                                   //dec si
    memory(_ds, _si) = 0x2e;                    //mov byte ptr [si], 2Eh
    memory(_ds, _si + 1) = 0x50;                //mov byte ptr [si+1], 50h
    memory(_ds, _si + 2) = 0x50;                //mov byte ptr [si+2], 50h
    memory(_ds, _si + 3) = 0x43;                //mov byte ptr [si+3], 43h
    memory(_ds, _si + 4) = 0;                   //mov byte ptr [si+4], 0
loc_2ADA7:                                      //loc_2ADA7:
    sub_2B4E8();                                //call sub_2B4E8
loc_2ADAA:                                      //loc_2ADAA:
    
    
    //std::cout << "gabo insert test\n";
    //sub_2B4E8();                                //call sub_2B4E8
    
    
    memory16(_ds, 0x2D47) = 5842;               //mov word_12D47, 16D2h
    memory(_ds, 0x3F1B) = 0;                    //mov byte_13F1B, 0
    memory(_cs, 0x84) = 1;                      //mov cs:byte_2ACA4, 1
    //sub_2F9B6();                                //call sub_2F9B6
    // GABO
    sub_2C0D3();                                //call sub_2C0D3
    _ax = 0x0005;                               //mov ax, 5
    _interrupt(0x10);                           //int 10h
    sub_2AFD0();                                //call sub_2AFD0
    _sync();
    sub_2B3AB();                                //call sub_2B3AB
    _sync();
    sub_300F6();                                //call sub_300F6
    _sync();
    sub_30205();                                //call sub_30205
    _sync();
    sub_2F69A();                                //call sub_2F69A
    _sync();
    sub_2F5DC();                                //call sub_2F5DC
    _sync();
    _ax = _seg000;                              //mov ax, seg seg000
    _es = _ax;                                  //mov es, ax
    sub_2FCB9();                                //call sub_2FCB9
    _sync();
    memory16(_ds, 0x1405) = _sp;                //mov word_11405, sp
    memory16(_ds, 0x2D45) = 5842;               //mov word_12D45, 16D2h
    sub_2AFF1();                                //call sub_2AFF1
    _sync();
    _ah = _ah ^ _ah;                            //xor ah, ah
    _interrupt(0x33);                           //int 33h
loc_2ADF1:                                      //loc_2ADF1:
    sub_2ACB0();                                //call sub_2ACB0
loc_2ADF4:                                      //loc_2ADF4:
    sub_2AD26();                                //call sub_2AD26
    sub_2FCDC();                                //call sub_2FCDC
    if (memory16(_ds, 0x2D47) == 5842)          //jz short loc_2AE05
      goto loc_2AE05;
    sub_2F52D();                                //call sub_2F52D
loc_2AE05:                                      //loc_2AE05:
    _push(_es);                                 //push es
    memory16(_ds, 0x1413) = 0x50;               //mov word_11413, 50h
    sub_30096();                                //call sub_30096
    _es = _pop();                               //pop es
    memory(_ds, 0x13C4) = 2;                    //mov byte_113C4, 2
    memory16(_ds, 0x13C5) = 16158;              //mov word_113C5, 3F1Eh
    _ax = 0xffff;                               //mov ax, 0FFFFh
    _cx = 0x0003;                               //mov cx, 3
    _di = 0x0000;                               //mov di, 0
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
loc_2AE26:                                      //loc_2AE26:
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(0x16);                           //int 16h
    if (!_flags.zero)                           //jnz short loc_2AE2F
      goto loc_2AE2F;
    goto loc_2AED4;                             //jmp loc_2AED4
loc_2AE2F:                                      //loc_2AE2F:
    _ah = 0x00;                                 //mov ah, 0
    _interrupt(0x16);                           //int 16h
    if (_ax != 0x4300)                          //jnz short loc_2AE3E
      goto loc_2AE3E;
    memory(_cs, 0x84) = memory(_cs, 0x84) ^ 1;  //xor cs:byte_2ACA4, 1
loc_2AE3E:                                      //loc_2AE3E:
    if (_ax != 0x4200)                          //jnz short loc_2AE49
      goto loc_2AE49;
    sub_2FDB6();                                //call sub_2FDB6
    goto loc_2AED4;                             //jmp loc_2AED4
loc_2AE49:                                      //loc_2AE49:
    if (_ax != 0x4100)                          //jnz short loc_2AE59
      goto loc_2AE59;
    memory(_ds, 0x3F1B) = 0;                    //mov byte_13F1B, 0
    memory16(_ds, 0x3F1C) = 16139;              //mov word_13F1C, 3F0Bh
loc_2AE59:                                      //loc_2AE59:
    if (memory(_ds, 0x3F1B) == 1)               //jz short loc_2AE63
      goto loc_2AE63;
    sub_2FD91();                                //call sub_2FD91
loc_2AE63:                                      //loc_2AE63:
    if (_ax != 0x4400)                          //jnz short loc_2AE79
      goto loc_2AE79;
    sub_2F700();                                //call sub_2F700
loc_2AE6B:                                      //loc_2AE6B:
    _ah = 0x00;                                 //mov ah, 0
    _interrupt(0x16);                           //int 16h
    if (_ax == 0x4400)                          //jz short loc_2AE6B
      goto loc_2AE6B;
    sub_2F76F();                                //call sub_2F76F
    goto loc_2AE26;                             //jmp short loc_2AE26
loc_2AE79:                                      //loc_2AE79:
    if (_ax == 0x3b00)                          //jz short loc_2AEF4
      goto loc_2AEF4;
    if (_ax != 0x3d00)                          //jnz short loc_2AE94
      goto loc_2AE94;
    if (memory16(_ds, 0x2D47) == 5716)          //jz short loc_2AE94
      goto loc_2AE94;
    memory16(_ds, 0x2D47) = 5716;               //mov word_12D47, 1654h
    sub_2F52D();                                //call sub_2F52D
loc_2AE94:                                      //loc_2AE94:
    if (_ax != 0x3e00)                          //jnz short loc_2AEAA
      goto loc_2AEAA;
    if (memory16(_ds, 0x2D47) == 5842)          //jz short loc_2AEAA
      goto loc_2AEAA;
    memory16(_ds, 0x2D47) = 5842;               //mov word_12D47, 16D2h
    sub_2F52D();                                //call sub_2F52D
loc_2AEAA:                                      //loc_2AEAA:
    if (_ax != 0x3f00)                          //jnz short loc_2AEB5
      goto loc_2AEB5;
    sub_2C1A1();                                //call sub_2C1A1
    goto loc_2ADF1;                             //jmp loc_2ADF1
loc_2AEB5:                                      //loc_2AEB5:
    if (_ax != 0x4000)                          //jnz short loc_2AEC0
      goto loc_2AEC0;
    sub_2FA3A();                                //call sub_2FA3A
    goto loc_2ADF1;                             //jmp loc_2ADF1
loc_2AEC0:                                      //loc_2AEC0:
    if (_ax == 0x3c00)                          //jz short loc_2AEE8
      goto loc_2AEE8;
    if (_ax != 0x011b)                          //jnz short loc_2AED4
      goto loc_2AED4;
    _ax = 0x0003;                               //mov ax, 3
    _interrupt(0x10);                           //int 10h
    _ax = 0x4c00;                               //mov ax, 4C00h
    _interrupt(0x21);                           //int 21h
loc_2AED4:                                      //loc_2AED4:
    _bx = memory16(_ds, 0x13C5);                //mov bx, word_113C5
    if (memory(_ds, _bx) == 0)                  //jz short loc_2AEE8
      goto loc_2AEE8;
    _push(_es);                                 //push es
    sub_2FFE2();                                //call sub_2FFE2
    _es = _pop();                               //pop es
    sub_2FCFF();                                //call sub_2FCFF
    goto loc_2AE26;                             //jmp loc_2AE26
loc_2AEE8:                                      //loc_2AEE8:
    sub_2ACA5();                                //call sub_2ACA5
    sub_2BE32();                                //call sub_2BE32
    sub_2C129();                                //call sub_2C129
    goto loc_2AF15;                             //jmp loc_2AF15
loc_2AEF4:                                      //loc_2AEF4:
    _ax = memory16(_ds, 0x2D47);                //mov ax, word_12D47
    memory16(_ds, 0x2D45) = _ax;                //mov word_12D45, ax
    sub_2ACA5();                                //call sub_2ACA5
    sub_2BCFE();                                //call sub_2BCFE
    if (_al != 0xff)                            //jnz short loc_2AF07
      goto loc_2AF07;
    goto loc_2ADF4;                             //jmp loc_2ADF4
loc_2AF07:                                      //loc_2AF07:
    sub_2B8E5();                                //call sub_2B8E5
    if (memory16(_ds, 0x2D45) != 5842)          //jnz short loc_2AF15
      goto loc_2AF15;
    sub_2AFD0();                                //call sub_2AFD0
loc_2AF15:                                      //loc_2AF15:
    _si = 0x344f;                               //mov si, 344Fh
    _di = 0x13d5;                               //mov di, 13D5h
    _cx = 0x0006;                               //mov cx, 6
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    memory16(_ds, 0x13CD) = 12336;              //mov word_113CD, 3030h
    memory16(_ds, 0x13CF) = 12336;              //mov word_113CF, 3030h
    memory16(_ds, 0x13D1) = 12336;              //mov word_113D1, 3030h
    memory16(_ds, 0x13D3) = 12338;              //mov word_113D3, 3032h
    memory(_ds, 0x3F0A) = 0;                    //mov byte_13F0A, 0
    _al = memory(_ds, 0x3F08);                  //mov al, byte_13F08
    memory(_ds, 0x3F09) = _al;                  //mov byte_13F09, al
    memory(_ds, 0x13C9) = 5;                    //mov byte_113C9, 5
    _dl = 0x1e;                                 //mov dl, 1Eh
    sub_2ECE0();                                //call sub_2ECE0
    _al = _ah;                                  //mov al, ah
    if (memory16(_ds, 0x2D45) == 6021)          //jz short loc_2AF59
      goto loc_2AF59;
    _al = _al ^ _al;                            //xor al, al
loc_2AF59:                                      //loc_2AF59:
    memory(_ds, 0x13CC) = _al;                  //mov byte_113CC, al
    _dl = 0xb0;                                 //mov dl, 0B0h
    _ax = _dl * _al;                            //mul dl
    _ax += 0x0c;                                //add ax, 0Ch
    memory16(_ds, 0x13CA) = _ax;                //mov word_113CA, ax
    sub_2B72B();                                //call sub_2B72B
    goto loc_2AFB8;                             //jmp loc_2AFB8
loc_2AF6C:                                      //loc_2AF6C:
    sub_2CAD9();                                //call sub_2CAD9
loc_2AF6F:                                      //loc_2AF6F:
    sub_2C493();                                //call sub_2C493
    _pushf();                                   //pushf
    sub_2ACB0();                                //call sub_2ACB0
    _popf();                                    //popf
    std::cout << "loc_2AF6F: ignore\n";
    //_ASSERT(0);
//    if (_FIXME_)                                //jnb short loc_2AF96
//      goto loc_2AF96;
    sub_2B355();                                //call sub_2B355
    if (memory(_ds, 0x3F1B) == 1)               //jz short loc_2AF87
      goto loc_2AF87;
    memory(_ds, 0x13C9) -= 1;                   //dec byte_113C9
loc_2AF87:                                      //loc_2AF87:
    if (memory(_ds, 0x2E78) != 1)               //jnz short loc_2AF6F
      goto loc_2AF6F;
    sub_2B093();                                //call sub_2B093
    sub_2B94E();                                //call sub_2B94E
    goto loc_2AF6C;                             //jmp short loc_2AF6C
loc_2AF96:                                      //loc_2AF96:
    sub_2B141();                                //call sub_2B141
    memory16(_ds, 0x13CA) += 0xb0;              //add word_113CA, 0B0h
    memory(_ds, 0x13CC) += 1;                   //inc byte_113CC
    if (memory(_ds, 0x13CC) != 0x32)            //jnz short loc_2AFB8
      goto loc_2AFB8;
    memory(_ds, 0x13CC) = 0;                    //mov byte_113CC, 0
    memory16(_ds, 0x13CA) = 0x0c;               //mov word_113CA, 0Ch
    sub_30560();                                //call sub_30560
loc_2AFB8:                                      //loc_2AFB8:
    sub_2B06B();                                //call sub_2B06B
    _si = memory16(_ds, 0x13CA);                //mov si, word_113CA
    _di = 0x2f10;                               //mov di, 2F10h
    _push(_ds);                                 //push ds
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _cx = 0xb0;                                 //mov cx, 0B0h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _ds = _pop();                               //pop ds
    goto loc_2AF6C;                             //jmp short loc_2AF6C
}

void sub_2ACA5()
{
    _al = 0xb6;                                 //mov al, 0B6h
    _out(0x43, _al);                            //out 43h, al
    _in(_al, 0x61);                             //in al, 61h
    _al |= 0x03;                                //or al, 3
    _out(0x61, _al);                            //out 61h, al
}

void sub_2ACB0()
{
    _in(_al, 0x61);                             //in al, 61h
    _al &= 0xfc;                                //and al, 0FCh
    _out(0x61, _al);                            //out 61h, al
}

void sub_2AD26()
{
    return;
    //GABO
    //_ASSERT(0); // keyb infinite loop
loc_2AD26:
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(0x16);                           //int 16h
    if (_flags.zero)                            //jz short locret_2AD32
      goto locret_2AD32;
    _ah = _ah ^ _ah;                            //xor ah, ah
    _interrupt(0x16);                           //int 16h
    // TODO: PARSER - goto entry namiesto call
    goto loc_2AD26;                         //jmp short sub_2AD26
locret_2AD32:                                   //locret_2AD32:
    return;
}

void sub_2AFD0()
{
    _push(_es);                                 //push es
    _ah = 0x35;                                 //mov ah, 35h
    _al = 0x09;                                 //mov al, 9
    _interrupt(0x21);                           //int 21h
    memory16(_ds, 0x2D41) = _bx;                //mov ds:2D41h, bx
    memory16(_ds, 0x2D43) = _es;                //mov word ptr ds:2D43h, es
    _es = _pop();                               //pop es
    _push(_ds);                                 //push ds
    _ax = _seg004;                              //mov ax, seg seg004
    _ds = _ax;                                  //mov ds, ax
    _ah = 0x25;                                 //mov ah, 25h
    _al = 0x09;                                 //mov al, 9
    _dx = 0x03e3;                               //mov dx, 3E3h
    _interrupt(0x21);                           //int 21h
    _ds = _pop();                               //pop ds
}

void sub_2AFF1()
{
    _push(_ds);                                 //push ds
    _dx = memory16(_ds, 0x2D41);                //mov dx, ds:2D41h
    _ax = memory16(_ds, 0x2D43);                //mov ax, ds:2D43h
    _ds = _ax;                                  //mov ds, ax
    _ah = 0x25;                                 //mov ah, 25h
    _al = 0x09;                                 //mov al, 9
    _interrupt(0x21);                           //int 21h
    _ds = _pop();                               //pop ds
}

void sub_2B06B()
{
    _al = memory(_ds, 0x13CC);                  //mov al, ds:13CCh
    _ah = _ah ^ _ah;                            //xor ah, ah
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _bp = _es;                                  //mov bp, es
    _si = _seg002;                              //mov si, seg seg002
    _es = _si;                                  //mov es, si
    _si = 0x0000;                               //mov si, 0
    _si += _ax;                                 //add si, ax
    _ax = memory16(_es, _si);                   //mov ax, es:[si]
    memory16(_ds, 0x3136) = _ax;                //mov ds:3136h, ax
    _al = memory(_es, _si + 2);                 //mov al, es:[si+2]
    memory(_ds, 0x3135) = _al;                  //mov ds:3135h, al
    memory(_ds, 0x3134) = _al;                  //mov ds:3134h, al
    _es = _bp;                                  //mov es, bp
}

void sub_2B093()
{
    _si = 0xa346;                               //mov si, 0A346h
    _di = 0x2d8c;                               //mov di, 2D8Ch
    _cx = 0x27;                                 //mov cx, 27h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _push(_es);                                 //push es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _dl = 0x08;                                 //mov dl, 8
    _di = 0x1cc2;                               //mov di, 1CC2h
loc_2B0A9:                                      //loc_2B0A9:
    _push(_di);                                 //push di
    _cx = 0x18;                                 //mov cx, 18h
    _ax = _ax ^ _ax;                            //xor ax, ax
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di = _pop();                               //pop di
    if (_di < 0x2000)                           //jb short loc_2B0BE
      goto loc_2B0BE;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2B0C2;                             //jmp short loc_2B0C2
loc_2B0BE:                                      //loc_2B0BE:
    _di += 0x2000;                              //add di, 2000h
loc_2B0C2:                                      //loc_2B0C2:
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2B0A9
      goto loc_2B0A9;
    _es = _pop();                               //pop es
    memory(_ds, 0x2D3B) = 1;                    //mov byte ptr ds:2D3Bh, 1
    _bl = memory(_ds, 0x2D39);                  //mov bl, ds:2D39h
    _bl |= _bl;                                 //or bl, bl
    if (_bl == 0)                               //jz short loc_2B10B
      goto loc_2B10B;
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bx <<= 1;                                  //shl bx, 1
    _si = memory16(_ds, _bx + 11549);           //mov si, [bx+2D1Dh]
    _cl = 0x06;                                 //mov cl, 6
loc_2B0DE:                                      //loc_2B0DE:
    _push(_cx);                                 //push cx
    _push(_si);                                 //push si
    _si = memory16(_ds, _si);                   //mov si, [si]
    _dx = 0x03da;                               //mov dx, 3DAh
loc_2B0E5:                                      //loc_2B0E5:
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x08))                          //jz short loc_2B0E5
      goto loc_2B0E5;
loc_2B0EA:                                      //loc_2B0EA:
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x08)                             //jnz short loc_2B0EA
      goto loc_2B0EA;
    sub_2CDA7();                                //call sub_2CDA7
    _si = _pop();                               //pop si
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    _cx = 0x96;                                 //mov cx, 96h
loc_2B0F8:                                      //loc_2B0F8:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2B0F8
      goto loc_2B0F8;
    _cx = _pop();                               //pop cx
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2B0DE
      goto loc_2B0DE;
    _si = 0x2d8c;                               //mov si, 2D8Ch
    _di = 0x2e57;                               //mov di, 2E57h
    sub_2CEA1();                                //call sub_2CEA1
loc_2B10B:                                      //loc_2B10B:
    _si = 0x9bb0;                               //mov si, 9BB0h
loc_2B10E:                                      //loc_2B10E:
    _push(_si);                                 //push si
    _si = memory16(_ds, _si);                   //mov si, [si]
    _si |= _si;                                 //or si, si
    if (_si == 0)                               //jz short loc_2B132
      goto loc_2B132;
    _dx = 0x03da;                               //mov dx, 3DAh
loc_2B118:                                      //loc_2B118:
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x08))                          //jz short loc_2B118
      goto loc_2B118;
loc_2B11D:                                      //loc_2B11D:
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x08)                             //jnz short loc_2B11D
      goto loc_2B11D;
    sub_2CEC9();                                //call sub_2CEC9
    _cx = 0x96;                                 //mov cx, 96h
loc_2B128:                                      //loc_2B128:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2B128
      goto loc_2B128;
    _si = _pop();                               //pop si
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    goto loc_2B10E;                             //jmp short loc_2B10E
loc_2B132:                                      //loc_2B132:
    _si = _pop();                               //pop si
    if (memory(_ds, 0x13C9) != 0)               //jnz short locret_2B140
      goto locret_2B140;
    sub_2AFF1();                                //call sub_2AFF1
    sub_2FDD6();                                //call sub_2FDD6
locret_2B140:                                   //locret_2B140:
    return;
}

void sub_2B141()
{
    _bx = memory16(_ds, 0x3144);                //mov bx, ds:3144h
loc_2B145:                                      //loc_2B145:
    if (_bx == 0xffff)                          //jz short loc_2B174
      goto loc_2B174;
    _push(_bx);                                 //push bx
    if (memory16(_ds, _bx) != 14070)            //jnz short loc_2B158
      goto loc_2B158;
    sub_2E31B();                                //call sub_2E31B
    goto loc_2B161;                             //jmp loc_2B161
loc_2B158:                                      //loc_2B158:
    if (memory16(_ds, _bx) != 13918)            //jnz short loc_2B161
      goto loc_2B161;
    sub_2E288();                                //call sub_2E288
loc_2B161:                                      //loc_2B161:
    _bx = _pop();                               //pop bx
    _cx = memory16(_ds, 0x3138);                //mov cx, ds:3138h
    _dx = memory16(_ds, _bx + 12);              //mov dx, [bx+0Ch]
    memory16(_ds, _bx + 12) = _cx;              //mov [bx+0Ch], cx
    memory16(_ds, 0x3138) = _bx;                //mov ds:3138h, bx
    _bx = _dx;                                  //mov bx, dx
    goto loc_2B145;                             //jmp short loc_2B145
loc_2B174:                                      //loc_2B174:
    memory16(_ds, 0x3144) = 0xffff;             //mov word ptr ds:3144h, 0FFFFh
    sub_2B218();                                //call sub_2B218
}

void sub_2B355()
{
    sub_2B06B();                                //call sub_2B06B
    _bx = memory16(_ds, 0x3144);                //mov bx, ds:3144h
    memory16(_ds, 0x3142) = 12600;              //mov word ptr ds:3142h, 3138h
loc_2B362:                                      //loc_2B362:
    if (_bx == 0xffff)                          //jz short loc_2B39E
      goto loc_2B39E;
    if (memory16(_ds, _bx) == 15039)            //jz short loc_2B3A2
      goto loc_2B3A2;
    _push(_bx);                                 //push bx
    if (memory16(_ds, _bx) != 14070)            //jnz short loc_2B37B
      goto loc_2B37B;
    sub_2E31B();                                //call sub_2E31B
    goto loc_2B384;                             //jmp loc_2B384
loc_2B37B:                                      //loc_2B37B:
    if (memory16(_ds, _bx) != 13918)            //jnz short loc_2B384
      goto loc_2B384;
    sub_2E288();                                //call sub_2E288
loc_2B384:                                      //loc_2B384:
    _bx = _pop();                               //pop bx
    _cx = memory16(_ds, 0x3138);                //mov cx, ds:3138h
    _dx = memory16(_ds, _bx + 12);              //mov dx, [bx+0Ch]
    memory16(_ds, _bx + 12) = _cx;              //mov [bx+0Ch], cx
    memory16(_ds, 0x3138) = _bx;                //mov ds:3138h, bx
    _si = memory16(_ds, 0x3142);                //mov si, ds:3142h
    memory16(_ds, _si + 12) = _dx;              //mov [si+0Ch], dx
    _bx = _dx;                                  //mov bx, dx
    goto loc_2B362;                             //jmp short loc_2B362
loc_2B39E:                                      //loc_2B39E:
    sub_2B218();                                //call sub_2B218
    return;                                     //retn
loc_2B3A2:                                      //loc_2B3A2:
    memory16(_ds, 0x3142) = _bx;                //mov ds:3142h, bx
    _bx = memory16(_ds, _bx + 12);              //mov bx, [bx+0Ch]
    goto loc_2B362;                             //jmp short loc_2B362
}

void sub_2B3AB()
{
    _push(_es);                                 //push es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _dl = 0xff;                                 //mov dl, 0FFh
    _di = 0x213f;                               //mov di, 213Fh
    _bx = 0x1a;                                 //mov bx, 1Ah
loc_2B3B9:                                      //loc_2B3B9:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _dh = 0x04;                                 //mov dh, 4
loc_2B3BD:                                      //loc_2B3BD:
    _cx = 0x32;                                 //mov cx, 32h
loc_2B3C0:                                      //loc_2B3C0:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2B3C0
      goto loc_2B3C0;
    _cx = 0x31;                                 //mov cx, 31h
    _push(_di);                                 //push di
    _al = 0x55;                                 //mov al, 55h
    _flags.carry = true;                        //stc
    _rcl(_ah, 1);//rcl ah, 1
    _flags.carry = true;                        //stc
    _rcl(_ah, 1);//rcl ah, 1
    _al &= _ah;                                 //and al, ah
    _push(_di);                                 //push di
    _push(_ax);                                 //push ax
    _bp = _dx;                                  //mov bp, dx
    _dx = 0x03da;                               //mov dx, 3DAh
loc_2B3DA:                                      //loc_2B3DA:
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x08))                          //jz short loc_2B3DA
      goto loc_2B3DA;
loc_2B3DF:                                      //loc_2B3DF:
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x08)                             //jnz short loc_2B3DF
      goto loc_2B3DF;
    _dx = _bp;                                  //mov dx, bp
    _ax = _pop();                               //pop ax
loc_2B3E7:                                      //loc_2B3E7:
    _stosb<MemVideo, DirAuto>();                 //stosb
    _di += 0x4f;                                //add di, 4Fh
    if (--_cx)                                  //loop loc_2B3E7
      goto loc_2B3E7;
    _di = _pop();                               //pop di
    _di -= 0x1fb0;                              //sub di, 1FB0h
    _cx = 0x31;                                 //mov cx, 31h
loc_2B3F5:                                      //loc_2B3F5:
    _stosb<MemAuto, DirAuto>();                 //stosb
    _di += 0x4f;                                //add di, 4Fh
    if (--_cx)                                  //loop loc_2B3F5
      goto loc_2B3F5;
    if (_bx != 0x0001)                          //jnz short loc_2B43B
      goto loc_2B43B;
    _di = 0x213f;                               //mov di, 213Fh
    _al = 0x55;                                 //mov al, 55h
    _flags.carry = false;                       //clc
    _rcl(_dl, 1);//rcl dl, 1
    _flags.carry = false;                       //clc
    _rcl(_dl, 1);//rcl dl, 1
    _al &= _dl;                                 //and al, dl
    _cx = 0x31;                                 //mov cx, 31h
    _cx = 0x31;                                 //mov cx, 31h
    _push(_di);                                 //push di
    _push(_ax);                                 //push ax
    _bp = _dx;                                  //mov bp, dx
    _dx = 0x03da;                               //mov dx, 3DAh
loc_2B41A:                                      //loc_2B41A:
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x08))                          //jz short loc_2B41A
      goto loc_2B41A;
loc_2B41F:                                      //loc_2B41F:
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x08)                             //jnz short loc_2B41F
      goto loc_2B41F;
    _dx = _bp;                                  //mov dx, bp
    _ax = _pop();                               //pop ax
loc_2B427:                                      //loc_2B427:
    _stosb<MemAuto, DirAuto>();                 //stosb
    _di += 0x4f;                                //add di, 4Fh
    if (--_cx)                                  //loop loc_2B427
      goto loc_2B427;
    _di = _pop();                               //pop di
    _di -= 0x1fb0;                              //sub di, 1FB0h
    _cx = 0x31;                                 //mov cx, 31h
loc_2B435:                                      //loc_2B435:
    _stosb<MemAuto, DirAuto>();                 //stosb
    _di += 0x4f;                                //add di, 4Fh
    if (--_cx)                                  //loop loc_2B435
      goto loc_2B435;
loc_2B43B:                                      //loc_2B43B:
    _di = _pop();                               //pop di
    _dh -= 1;                                   //dec dh
    if (_dh == 0)                               //jz short loc_2B443
      goto loc_2B443;
    goto loc_2B3BD;                             //jmp loc_2B3BD
loc_2B443:                                      //loc_2B443:
    _di -= 1;                                   //dec di
    _bx -= 1;                                   //dec bx
    if (_bx == 0)                               //jz short loc_2B44A
      goto loc_2B44A;
    goto loc_2B3B9;                             //jmp loc_2B3B9
loc_2B44A:                                      //loc_2B44A:
    _cx = 0x32;                                 //mov cx, 32h
loc_2B44D:                                      //loc_2B44D:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2B44D
      goto loc_2B44D;
    _es = _pop();                               //pop es
    _cx = 0x0001;                               //mov cx, 1
loc_2B456:                                      //loc_2B456:
    _push(_cx);                                 //push cx
    _ax = 0x1b;                                 //mov ax, 1Bh
    _ax = _cl * _al;                            //mul cl
    _cx = _ax;                                  //mov cx, ax
    _bp = _ax;                                  //mov bp, ax
    _si = 0x8318;                               //mov si, 8318h
    _si -= _cx;                                 //sub si, cx
    _di = 0x1aef;                               //mov di, 1AEFh
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _si = 0x1aef;                               //mov si, 1AEFh
    _bx = _bx ^ _bx;                            //xor bx, bx
loc_2B46F:                                      //loc_2B46F:
    if (_bx == _bp)                             //jz short loc_2B49D
      goto loc_2B49D;
    if (_bx >= 0xbd)                            //jnb short loc_2B49D
      goto loc_2B49D;
    _al = memory(_ds, _si);                     //mov al, [si]
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cl = 0x04;                                 //mov cl, 4
loc_2B47F:                                      //loc_2B47F:
    _flags.carry = !!(_al & 0x80);              //shl al, 1
    _al <<= 1;
    if (_flags.carry)                           //jb short loc_2B48D
      goto loc_2B48D;
    _rcl(_ah, 1);  //rcl ah, 1
    _al <<= 1;                                  //shl al, 1
    _flags.carry = false;                       //clc
    _rcl(_ah, 1);//rcl ah, 1
    goto loc_2B493;                             //jmp loc_2B493
loc_2B48D:                                      //loc_2B48D:
    _rcl(_ah, 1);//rcl ah, 1
    _flags.carry = !!(_al & 0x80);              //shl al, 1
    _al <<= 1;
    _rcl(_ah, 1);                               //rcl ah, 1
loc_2B493:                                      //loc_2B493:
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2B47F
      goto loc_2B47F;
    memory(_ds, _si) = _ah;                     //mov [si], ah
    _si += 1;                                   //inc si
    _bx += 1;                                   //inc bx
    goto loc_2B46F;                             //jmp short loc_2B46F
loc_2B49D:                                      //loc_2B49D:
    _cx = _pop();                               //pop cx
    _push(_cx);                                 //push cx
    _push(_es);                                 //push es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _si = 0x1aef;                               //mov si, 1AEFh
    _di = 0x34;                                 //mov di, 34h
    _bx = _cx;                                  //mov bx, cx
    _dx = 0x03da;                               //mov dx, 3DAh
loc_2B4B0:                                      //loc_2B4B0:
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x08))                          //jz short loc_2B4B0
      goto loc_2B4B0;
loc_2B4B5:                                      //loc_2B4B5:
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x08)                             //jnz short loc_2B4B5
      goto loc_2B4B5;
loc_2B4BA:                                      //loc_2B4BA:
    _push(_di);                                 //push di
    _cx = 0x1b;                                 //mov cx, 1Bh
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di = _pop();                               //pop di
    if (_di < 0x2000)                           //jb short loc_2B4CD
      goto loc_2B4CD;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2B4D1;                             //jmp short loc_2B4D1
loc_2B4CD:                                      //loc_2B4CD:
    _di += 0x2000;                              //add di, 2000h
loc_2B4D1:                                      //loc_2B4D1:
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz short loc_2B4BA
      goto loc_2B4BA;
    _es = _pop();                               //pop es
    _cx = 0x28;                                 //mov cx, 28h
loc_2B4D8:                                      //loc_2B4D8:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2B4D8
      goto loc_2B4D8;
    _cx = _pop();                               //pop cx
    _cx += 1;                                   //inc cx
    if (_cx == 0x6a)                            //jz short locret_2B4E7
      goto locret_2B4E7;
    goto loc_2B456;                             //jmp loc_2B456
locret_2B4E7:                                   //locret_2B4E7:
    return;
}

void sub_2B4E8()
{
    _dx = 0x1428;                               //mov dx, 1428h
    _ax = 0x3d00;                               //mov ax, 3D00h
    _interrupt(0x21);                           //int 21h
    if (_flags.carry)                           //jb short loc_2B517
      goto loc_2B517;
    _bx = _ax;                                  //mov bx, ax
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
    _dx = 0x0006;                               //mov dx, 6
    _cx = 0x21b6;                               //mov cx, 21B6h
    _ah = 0x3f;                                 //mov ah, 3Fh
    _interrupt(0x21);                           //int 21h
    _si = 0x0000;                               //mov si, 0
    _di = 0x0006;                               //mov di, 6
    _cx = 0x0006;                               //mov cx, 6
    _ASSERT(0);
   // _repne_cmpsb();                             //repne cmpsb
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    if (!_flags.zero)                           //jnz short loc_2B524
      goto loc_2B524;
    return;                                     //retn
loc_2B517:                                      //loc_2B517:
    _ax = _pop();                               //pop ax
    _dx = 0x2a8f;                               //mov dx, 2A8Fh
    _ah = 0x09;                                 //mov ah, 9
    _interrupt(0x21);                           //int 21h
    _ax = 0x4c00;                               //mov ax, 4C00h
    _interrupt(0x21);                           //int 21h
loc_2B524:                                      //loc_2B524:
    _ax = _pop();                               //pop ax
    _dx = 0x2ac3;                               //mov dx, 2AC3h
    _ah = 0x09;                                 //mov ah, 9
    _interrupt(0x21);                           //int 21h
    _ax = 0x4c00;                               //mov ax, 4C00h
    _interrupt(0x21);                           //int 21h
    _STOP_("sp-trace-fail");                    //sub_2B4E8 endp_failed
    _STOP_("continues");                        //sub_2B531 proc near
}

void sub_2B72B() // panel sa vysuva
{
    _sync();
    _si = 0x13d5;                               //mov si, 13D5h
    _di = 0x86ee;                               //mov di, 86EEh
    _cl = 0x0c;                                 //mov cl, 0Ch
loc_2B733:                                      //loc_2B733:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _push(_si);                                 //push si
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _si = 0x9020;                               //mov si, 9020h
    if (_al != 0x2d)                            //jnz short loc_2B743
      goto loc_2B743;
    _al = 0x0b;                                 //mov al, 0Bh
    goto loc_2B75B;                             //jmp loc_2B75B
loc_2B743:                                      //loc_2B743:
    if (_al != 0x20)                            //jnz short loc_2B74C
      goto loc_2B74C;
    _al = _al ^ _al;                            //xor al, al
    goto loc_2B75B;                             //jmp loc_2B75B
loc_2B74C:                                      //loc_2B74C:
    if (_al > 0x39)                             //ja short loc_2B755
      goto loc_2B755;
    _al -= 0x2f;                                //sub al, 2Fh
    goto loc_2B75B;                             //jmp loc_2B75B
loc_2B755:                                      //loc_2B755:
    if (_al < 0x41)                             //jb short loc_2B75B
      goto loc_2B75B;
    _al -= 0x35;                                //sub al, 35h
loc_2B75B:                                      //loc_2B75B:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cl = 0x03;                                 //mov cl, 3
    _ax <<= _cl;                                //shl ax, cl
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    _bx += _ax;                                 //add bx, ax
    _si += _bx;                                 //add si, bx
    _cx = 0x0c;                                 //mov cx, 0Ch
loc_2B76C:                                      //loc_2B76C:
    _movsw<MemAuto, MemAuto, DirAuto>();        //movsw
    //_sync();
    _di += 0x1a;                                //add di, 1Ah
    if (--_cx)                                  //loop loc_2B76C
      goto loc_2B76C;
    _di = _pop();                               //pop di
    _cx = _pop();                               //pop cx
    _si = _pop();                               //pop si
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2B733
      goto loc_2B733;
    _si = 0x13cd;                               //mov si, 13CDh
    _di = 0x8962;                               //mov di, 8962h
    _cl = 0x06;                                 //mov cl, 6
loc_2B783:                                      //loc_2B783:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    //_sync();
    _push(_si);                                 //push si
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _si = 0x9020;                               //mov si, 9020h
    if (_al > 0x20)                             //ja short loc_2B793
      goto loc_2B793;
    _al = _al ^ _al;                            //xor al, al
    goto loc_2B7A7;                             //jmp loc_2B7A7
loc_2B793:                                      //loc_2B793:
    if (_al > 0x39)                             //ja short loc_2B79C
      goto loc_2B79C;
    _al -= 0x2f;                                //sub al, 2Fh
    goto loc_2B7A7;                             //jmp loc_2B7A7
loc_2B79C:                                      //loc_2B79C:
    if (_al < 0x41)                             //jb short loc_2B7A5
      goto loc_2B7A5;
    _al -= 0x35;                                //sub al, 35h
    goto loc_2B7A7;                             //jmp loc_2B7A7
loc_2B7A5:                                      //loc_2B7A5:
    _al = 0x0b;                                 //mov al, 0Bh
loc_2B7A7:                                      //loc_2B7A7:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cl = 0x03;                                 //mov cl, 3
    _ax <<= _cl;                                //shl ax, cl
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    _bx += _ax;                                 //add bx, ax
    _si += _bx;                                 //add si, bx
    _cx = 0x0c;                                 //mov cx, 0Ch
loc_2B7B8:                                      //loc_2B7B8:
    _movsw<MemAuto, MemAuto, DirAuto>();        //movsw
    //_sync();
    _di += 0x1a;                                //add di, 1Ah
    if (--_cx)                                  //loop loc_2B7B8
      goto loc_2B7B8;
    _di = _pop();                               //pop di
    _cx = _pop();                               //pop cx
    _si = _pop();                               //pop si
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2B783
      goto loc_2B783;
    _si = 0x48e7;                               //mov si, 48E7h
    _di = 0x8cc0;                               //mov di, 8CC0h
    _dl = 0x01;                                 //mov dl, 1
loc_2B7CF:                                      //loc_2B7CF:
    _push(_di);                                 //push di
    _al = _dl;                                  //mov al, dl
    _al -= 1;                                   //dec al
    _ah = _ah ^ _ah;                            //xor ah, ah
    _bl = _al;                                  //mov bl, al
    _bl &= 0x03;                                //and bl, 3
    _al &= 0xfc;                                //and al, 0FCh
    _di += _ax;                                 //add di, ax
    _ax = 0xa8;                                 //mov ax, 0A8h
    _ax = _bl * _al;                            //mul bl
    _di += _ax;                                 //add di, ax
    if (_dl > memory(_ds, 0x13C9))              //ja short loc_2B807
      goto loc_2B807;
    _push(_si);                                 //push si
    _al = 0x05;                                 //mov al, 5
loc_2B7EF:                                      //loc_2B7EF:
    _cx = 0x0002;                               //mov cx, 2
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    //_sync();
    _di += 0x18;                                //add di, 18h
    _al -= 1;                                   //dec al
    if (_al != 0)                               //jnz short loc_2B7EF
      goto loc_2B7EF;
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dl += 1;                                   //inc dl
    if (_dl != 0x0d)                            //jnz short loc_2B7CF
      goto loc_2B7CF;
    goto loc_2B825;                             //jmp loc_2B825
loc_2B807:                                      //loc_2B807:
    _push(_si);                                 //push si
    _al = 0x05;                                 //mov al, 5
loc_2B80A:                                      //loc_2B80A:
    _cx = 0x0002;                               //mov cx, 2
    _bp = _ax;                                  //mov bp, ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
 //   _sync();
    _di += 0x18;                                //add di, 18h
    _ax = _bp;                                  //mov ax, bp
    _al -= 1;                                   //dec al
    if (_al != 0)                               //jnz short loc_2B80A
      goto loc_2B80A;
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dl += 1;                                   //inc dl
    if (_dl != 0x0d)                            //jnz short loc_2B7CF
      goto loc_2B7CF;
loc_2B825:                                      //loc_2B825:
    _bp = _es;                                  //mov bp, es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _bx = 0x0001;                               //mov bx, 1
    _di = 0x3f24;                               //mov di, 3F24h
loc_2B832:                                      //loc_2B832:
    if (_bx == 0x5e)                            //jz short loc_2B881
      goto loc_2B881;
    _push(_bx);                                 //push bx
    _push(_di);                                 //push di
    _si = 0x85f0;                               //mov si, 85F0h
    _dx = 0x03da;                               //mov dx, 3DAh
loc_2B83F:                                      //loc_2B83F:
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x08))                          //jz short loc_2B83F
      goto loc_2B83F;
loc_2B844:                                      //loc_2B844:
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x08)                             //jnz short loc_2B844
      goto loc_2B844;
loc_2B849:                                      //loc_2B849:
    _push(_di);                                 //push di
    _cx = 0x0e;                                 //mov cx, 0Eh
//    std::cout << "es:di = " << std::hex << _di << " <- ds:si= " << _si << "\n";
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    // TODO: tuto je to zle
    _di = _pop();                               //pop di
    if (_di < 0x2000)                           //jb short loc_2B85C
      goto loc_2B85C;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2B860;                             //jmp short loc_2B860
loc_2B85C:                                      //loc_2B85C:
    _di += 0x2000;                              //add di, 2000h
loc_2B860:                                      //loc_2B860:
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz short loc_2B849
      goto loc_2B849;
    _cx = 0x32;                                 //mov cx, 32h
loc_2B866:                                      //loc_2B866:
    sub_2C26C();                                //call sub_2C26C
    //_sync();
    if (--_cx)                                  //loop loc_2B866
      goto loc_2B866;
    _di = _pop();                               //pop di
    if (_di >= 0x2000)                          //jnb short loc_2B879
      goto loc_2B879;
    _di += 0x1fb0;                              //add di, 1FB0h
    goto loc_2B87D;                             //jmp loc_2B87D
loc_2B879:                                      //loc_2B879:
    ///_sync();
    _di -= 0x2000;                              //sub di, 2000h
loc_2B87D:                                      //loc_2B87D:
    _bx = _pop();                               //pop bx
    _bx += 1;                                   //inc bx
    goto loc_2B832;                             //jmp short loc_2B832
loc_2B881:                                      //loc_2B881:
    _es = _bp;                                  //mov es, bp
}

void sub_2B8E5()
{
    std::cout << "priprava panela??\n";
    return;
    _di = 0x344f;                               //mov di, 344Fh
    _bl = memory(_ds, 0x3F08);                  //mov bl, ds:3F08h
loc_2B8EC:                                      //loc_2B8EC:
    memory(_ds, _di + 12) = 5;                  //mov byte ptr [di+0Ch], 5
    memory16(_ds, _di + 13) = 0x0c;             //mov word ptr [di+0Dh], 0Ch
    memory(_ds, _di + 15) = 0;                  //mov byte ptr [di+0Fh], 0
    memory16(_ds, _di + 16) = 12336;            //mov word ptr [di+10h], 3030h
    memory16(_ds, _di + 18) = 12336;            //mov word ptr [di+12h], 3030h
    memory16(_ds, _di + 20) = 12336;            //mov word ptr [di+14h], 3030h
    _push(_di);                                 //push di
    _si = 0x0c;                                 //mov si, 0Ch
    _di += 0x16;                                //add di, 16h
    _push(_ds);                                 //push ds
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _cx = 0x58;                                 //mov cx, 58h
    
    for (int i =0; i<_cx*2; i++)
    memory(_es, _di+i) ^= 0xff; //memory(_ds, _si+i) ^ 0xff;
    
    //_rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _ds = _pop();                               //pop ds
    _di = _pop();                               //pop di
    memory16(_ds, _di + 198) = 0xffff;          //mov word ptr [di+0C6h], 0FFFFh
    memory16(_ds, _di + 200) = 0xffff;          //mov word ptr [di+0C8h], 0FFFFh
    memory16(_ds, _di + 202) = 0xffff;          //mov word ptr [di+0CAh], 0FFFFh
    memory16(_ds, _di + 204) = 0xffff;          //mov word ptr [di+0CCh], 0FFFFh
    memory16(_ds, _di + 206) = 0xffff;          //mov word ptr [di+0CEh], 0FFFFh
    memory16(_ds, _di + 208) = 0xffff;          //mov word ptr [di+0D0h], 0FFFFh
    memory(_ds, _di + 210) = 0;                 //mov byte ptr [di+0D2h], 0
    _di += 0x011b;                              //add di, 11Bh
    _bl -= 1;                                   //dec bl
    if (_bl != 0)                               //jnz short loc_2B8EC
      goto loc_2B8EC;
}

void sub_2B94E()
{
    memory(_ds, 0x2E78) = 0;                    //mov byte ptr ds:2E78h, 0
    if (memory(_ds, 0x13C9) != 0)               //jnz short loc_2B98B
      goto loc_2B98B;
    memory(_ds, 0x2E78) = 1;                    //mov byte ptr ds:2E78h, 1
    memory(_ds, 0x3F09) -= 1;                   //dec byte ptr ds:3F09h
    if (memory(_ds, 0x3F09) != 0)               //jnz short loc_2B98B
      goto loc_2B98B;
    _ax = _pop();                               //pop ax
    _di = 0x344f;                               //mov di, 344Fh
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bl = memory(_ds, 0x3F0A);                  //mov bl, ds:3F0Ah
    _ax = 0x011b;                               //mov ax, 11Bh
    _ax = _bx * _al;                            //mul bx
    _di += _ax;                                 //add di, ax
    _ax = memory16(_ds, 0x13CD);                //mov ax, ds:13CDh
    memory16(_ds, _di + 16) = _ax;              //mov [di+10h], ax
    _ax = memory16(_ds, 0x13CF);                //mov ax, ds:13CFh
    memory16(_ds, _di + 18) = _ax;              //mov [di+12h], ax
    _ax = memory16(_ds, 0x13D1);                //mov ax, ds:13D1h
    memory16(_ds, _di + 20) = _ax;              //mov [di+14h], ax
    goto loc_2BAC3;                             //jmp loc_2BAC3
loc_2B98B:                                      //loc_2B98B:
    if (memory(_ds, 0x3F09) != 1)               //jnz short loc_2B99D
      goto loc_2B99D;
    if (memory(_ds, 0x2E78) == 1)               //jz short loc_2B99D
      goto loc_2B99D;
    _ax = _pop();                               //pop ax
    _ASSERT(0);
    //goto loc_2AF6F;                             //jmp loc_2AF6F
loc_2B99D:                                      //loc_2B99D:
    _di = 0x344f;                               //mov di, 344Fh
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bl = memory(_ds, 0x3F0A);                  //mov bl, ds:3F0Ah
    _ax = 0x011b;                               //mov ax, 11Bh
    _ax = _bx * _al;                            //mul bx
    _di += _ax;                                 //add di, ax
    _bp = _di;                                  //mov bp, di
    _al = memory(_ds, 0x13C9);                  //mov al, ds:13C9h
    memory(_ds, _di + 12) = _al;                //mov [di+0Ch], al
    _ax = memory16(_ds, 0x13CA);                //mov ax, ds:13CAh
    memory16(_ds, _di + 13) = _ax;              //mov [di+0Dh], ax
    _al = memory(_ds, 0x13CC);                  //mov al, ds:13CCh
    memory(_ds, _di + 15) = _al;                //mov [di+0Fh], al
    _ax = memory16(_ds, 0x13CD);                //mov ax, ds:13CDh
    memory16(_ds, _di + 16) = _ax;              //mov [di+10h], ax
    _ax = memory16(_ds, 0x13CF);                //mov ax, ds:13CFh
    memory16(_ds, _di + 18) = _ax;              //mov [di+12h], ax
    _ax = memory16(_ds, 0x13D1);                //mov ax, ds:13D1h
    memory16(_ds, _di + 20) = _ax;              //mov [di+14h], ax
    _si = 0x2f10;                               //mov si, 2F10h
    _di += 0x16;                                //add di, 16h
    _cx = 0x58;                                 //mov cx, 58h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _di = _bp;                                  //mov di, bp
    _si = 0x30b0;                               //mov si, 30B0h
    _di += 0xc6;                                //add di, 0C6h
    _cx = 0x0006;                               //mov cx, 6
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _di = _bp;                                  //mov di, bp
    memory(_ds, _di + 210) = 0;                 //mov byte ptr [di+0D2h], 0
    _di += 0xd3;                                //add di, 0D3h
    _bx = memory16(_ds, 0x3144);                //mov bx, ds:3144h
loc_2B9FB:                                      //loc_2B9FB:
    if (_bx == 0xffff)                          //jz short loc_2BA15
      goto loc_2BA15;
    _push(_di);                                 //push di
    _di = _bp;                                  //mov di, bp
    memory(_ds, _di + 210) += 1;                //inc byte ptr [di+0D2h]
    _di = _pop();                               //pop di
    _si = _bx;                                  //mov si, bx
    _cx = 0x0006;                               //mov cx, 6
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _bx = memory16(_ds, _bx + 12);              //mov bx, [bx+0Ch]
    goto loc_2B9FB;                             //jmp short loc_2B9FB
loc_2BA15:                                      //loc_2BA15:
    _bx = memory16(_ds, 0x3144);                //mov bx, ds:3144h
loc_2BA19:                                      //loc_2BA19:
    if (_bx == 0xffff)                          //jz short loc_2BA31
      goto loc_2BA31;
    _cx = memory16(_ds, 0x3138);                //mov cx, ds:3138h
    _dx = memory16(_ds, _bx + 12);              //mov dx, [bx+0Ch]
    memory16(_ds, _bx + 12) = _cx;              //mov [bx+0Ch], cx
    memory16(_ds, 0x3138) = _bx;                //mov ds:3138h, bx
    _bx = _dx;                                  //mov bx, dx
    goto loc_2BA19;                             //jmp short loc_2BA19
loc_2BA31:                                      //loc_2BA31:
    memory16(_ds, 0x3144) = 0xffff;             //mov word ptr ds:3144h, 0FFFFh
loc_2BA37:                                      //loc_2BA37:
    memory(_ds, 0x3F0A) += 1;                   //inc byte ptr ds:3F0Ah
    _bl = memory(_ds, 0x3F0A);                  //mov bl, ds:3F0Ah
    if (_bl != memory(_ds, 0x3F08))             //jnz short loc_2BA4C
      goto loc_2BA4C;
    memory(_ds, 0x3F0A) = 0;                    //mov byte ptr ds:3F0Ah, 0
    _bl = _bl ^ _bl;                            //xor bl, bl
loc_2BA4C:                                      //loc_2BA4C:
    _si = 0x344f;                               //mov si, 344Fh
    _ax = 0x011b;                               //mov ax, 11Bh
    _bh = _bh ^ _bh;                            //xor bh, bh
    _ax = _bx * _al;                            //mul bx
    _si += _ax;                                 //add si, ax
    if (memory(_ds, _si + 12) == 0)             //jz short loc_2BA37
      goto loc_2BA37;
    _di = 0x13d5;                               //mov di, 13D5h
    _cx = 0x0006;                               //mov cx, 6
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    memory(_ds, 0x13C9) = _al;                  //mov ds:13C9h, al
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_ds, 0x13CA) = _ax;                //mov ds:13CAh, ax
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    memory(_ds, 0x13CC) = _al;                  //mov ds:13CCh, al
    _di = 0x13cd;                               //mov di, 13CDh
    _cx = 0x0003;                               //mov cx, 3
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _di = 0x2f10;                               //mov di, 2F10h
    _cx = 0x58;                                 //mov cx, 58h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _di = 0x30b0;                               //mov di, 30B0h
    _cx = 0x0006;                               //mov cx, 6
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz short loc_2BAA1
      goto loc_2BAA1;
loc_2BA8F:                                      //loc_2BA8F:
    _push(_ax);                                 //push ax
    _di = _si;                                  //mov di, si
    sub_2DE52();                                //call sub_2DE52
    _xchg(_si, _di);                            //xchg si, di
    _cx = 0x0006;                               //mov cx, 6
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _ax = _pop();                               //pop ax
    _al -= 1;                                   //dec al
    if (_al != 0)                               //jnz short loc_2BA8F
      goto loc_2BA8F;
loc_2BAA1:                                      //loc_2BAA1:
    sub_2B72B();                                //call sub_2B72B
    sub_2B06B();                                //call sub_2B06B
    _ax = memory16(_ds, 0x13CD);                //mov ax, ds:13CDh
    _ax &= 0x0e0f;                              //and ax, 0E0Fh
    _ah += 1;                                   //inc ah
    _ah += 1;                                   //inc ah
    if (_ah < 0x0a)                             //jb short loc_2BABA
      goto loc_2BABA;
    _al += 1;                                   //inc al
    _ah = _ah ^ _ah;                            //xor ah, ah
loc_2BABA:                                      //loc_2BABA:
    _ax += 0x3030;                              //add ax, 3030h
    _xchg(_ah, _al);                            //xchg ah, al
    memory16(_ds, 0x13D3) = _ax;                //mov ds:13D3h, ax
    return;                                     //retn
loc_2BAC3:                                      //loc_2BAC3:
    if (memory(_ds, 0x3F08) != 1)               //jnz short loc_2BACD
      goto loc_2BACD;
    goto loc_2BC73;                             //jmp loc_2BC73
loc_2BACD:                                      //loc_2BACD:
    _di = 0x2f18;                               //mov di, 2F18h
    _ax = _ax ^ _ax;                            //xor ax, ax
    _cx = 0x54;                                 //mov cx, 54h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    sub_2CAD9();                                //call sub_2CAD9
    _dl = memory(_ds, 0x3F08);                  //mov dl, ds:3F08h
    _di = 0x1aef;                               //mov di, 1AEFh
    _si = 0x344f;                               //mov si, 344Fh
    _push(_si);                                 //push si
    _cx = 0x0006;                               //mov cx, 6
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _si += 0x0004;                              //add si, 4
    _cx = 0x0003;                               //mov cx, 3
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _si = _pop();                               //pop si
    _si += 0x011b;                              //add si, 11Bh
    _dl -= 1;                                   //dec dl
    _dh = 0x01;                                 //mov dh, 1
loc_2BAFB:                                      //loc_2BAFB:
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _bp = _si;                                  //mov bp, si
    sub_2BCAC();                                //call sub_2BCAC
    _si = _bp;                                  //mov si, bp
    _cx = 0x0006;                               //mov cx, 6
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _si += 0x0004;                              //add si, 4
    _cx = 0x0003;                               //mov cx, 3
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _si = _bp;                                  //mov si, bp
    _si += 0x011b;                              //add si, 11Bh
    _di = _pop();                               //pop di
    _di += 0x12;                                //add di, 12h
    _dx = _pop();                               //pop dx
    _dh += 1;                                   //inc dh
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2BAFB
      goto loc_2BAFB;
    _push(_es);                                 //push es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _di = 0xf2;                                 //mov di, 0F2h
    _ax = 0xaaaa;                               //mov ax, 0AAAAh
    _cx = 0x18;                                 //mov cx, 18h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di = 0x20f2;                               //mov di, 20F2h
    _dl = 0x18;                                 //mov dl, 18h
    _al = 0x20;                                 //mov al, 20h
    sub_2BCE5();                                //call sub_2BCE5
    _di += 0x01b0;                              //add di, 1B0h
    _dl = 0x07;                                 //mov dl, 7
    _al = 0x20;                                 //mov al, 20h
    sub_2BCE5();                                //call sub_2BCE5
    _al = 0x43;                                 //mov al, 43h
    sub_2B884();                                //call sub_2B884
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _al = 0x4c;                                 //mov al, 4Ch
    sub_2B884();                                //call sub_2B884
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _al = 0x41;                                 //mov al, 41h
    sub_2B884();                                //call sub_2B884
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _al = 0x53;                                 //mov al, 53h
    sub_2B884();                                //call sub_2B884
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _al = 0x53;                                 //mov al, 53h
    sub_2B884();                                //call sub_2B884
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _al = 0x45;                                 //mov al, 45h
    sub_2B884();                                //call sub_2B884
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _al = 0x4d;                                 //mov al, 4Dh
    sub_2B884();                                //call sub_2B884
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _al = 0x45;                                 //mov al, 45h
    sub_2B884();                                //call sub_2B884
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _al = 0x4e;                                 //mov al, 4Eh
    sub_2B884();                                //call sub_2B884
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _al = 0x54;                                 //mov al, 54h
    sub_2B884();                                //call sub_2B884
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _dl = 0x07;                                 //mov dl, 7
    _al = 0x20;                                 //mov al, 20h
    sub_2BCE5();                                //call sub_2BCE5
    _di += 0x01b0;                              //add di, 1B0h
    _dl = 0x05;                                 //mov dl, 5
    _al = 0x20;                                 //mov al, 20h
    sub_2BCE5();                                //call sub_2BCE5
    _dl = 0x0e;                                 //mov dl, 0Eh
    _al = 0x2d;                                 //mov al, 2Dh
    sub_2BCE5();                                //call sub_2BCE5
    _al = 0x20;                                 //mov al, 20h
    _dl = 0x05;                                 //mov dl, 5
    sub_2BCE5();                                //call sub_2BCE5
    _di += 0x01b0;                              //add di, 1B0h
    _dl = 0x18;                                 //mov dl, 18h
    _al = 0x20;                                 //mov al, 20h
    sub_2BCE5();                                //call sub_2BCE5
    _di += 0x01b0;                              //add di, 1B0h
    _dl = memory(_ds, 0x3F08);                  //mov dl, ds:3F08h
    _si = 0x1aef;                               //mov si, 1AEFh
loc_2BBC4:                                      //loc_2BBC4:
    _push(_dx);                                 //push dx
    _push(_si);                                 //push si
    _dl = 0x02;                                 //mov dl, 2
    _al = 0x20;                                 //mov al, 20h
    sub_2BCE5();                                //call sub_2BCE5
    _si = _pop();                               //pop si
    _dl = 0x0c;                                 //mov dl, 0Ch
    sub_2BCF1();                                //call sub_2BCF1
    _push(_si);                                 //push si
    _dl = 0x02;                                 //mov dl, 2
    _al = 0x20;                                 //mov al, 20h
    sub_2BCE5();                                //call sub_2BCE5
    _si = _pop();                               //pop si
    _dl = 0x06;                                 //mov dl, 6
    sub_2BCF1();                                //call sub_2BCF1
    _al = 0x20;                                 //mov al, 20h
    _dl = 0x02;                                 //mov dl, 2
    _push(_si);                                 //push si
    sub_2BCE5();                                //call sub_2BCE5
    _si = _pop();                               //pop si
    _di += 0x01b0;                              //add di, 1B0h
    _ax = 0xaaaa;                               //mov ax, 0AAAAh
    _cx = 0x18;                                 //mov cx, 18h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di -= 0x30;                                //sub di, 30h
    if (_di < 0x2000)                           //jb short loc_2BC05
      goto loc_2BC05;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2BC09;                             //jmp short loc_2BC09
loc_2BC05:                                      //loc_2BC05:
    _di += 0x2000;                              //add di, 2000h
loc_2BC09:                                      //loc_2BC09:
    _cx = 0x18;                                 //mov cx, 18h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di -= 0x30;                                //sub di, 30h
    if (_di < 0x2000)                           //jb short loc_2BC1D
      goto loc_2BC1D;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2BC21;                             //jmp short loc_2BC21
loc_2BC1D:                                      //loc_2BC1D:
    _di += 0x2000;                              //add di, 2000h
loc_2BC21:                                      //loc_2BC21:
    _dx = _pop();                               //pop dx
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2BBC4
      goto loc_2BBC4;
loc_2BC26:                                      //loc_2BC26:
    if (_di == 0x1f42)                          //jz short loc_2BC49
      goto loc_2BC49;
    _ax = 0xaaaa;                               //mov ax, 0AAAAh
    _cx = 0x18;                                 //mov cx, 18h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di -= 0x30;                                //sub di, 30h
    if (_di < 0x2000)                           //jb short loc_2BC43
      goto loc_2BC43;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2BC47;                             //jmp short loc_2BC47
loc_2BC43:                                      //loc_2BC43:
    _di += 0x2000;                              //add di, 2000h
loc_2BC47:                                      //loc_2BC47:
    goto loc_2BC26;                             //jmp short loc_2BC26
loc_2BC49:                                      //loc_2BC49:
    _es = _pop();                               //pop es
    if (memory16(_ds, 0x2D45) != 5842)          //jnz short loc_2BC55
      goto loc_2BC55;
    sub_2AFF1();                                //call sub_2AFF1
loc_2BC55:                                      //loc_2BC55:
    _dl = 0xc8;                                 //mov dl, 0C8h
loc_2BC57:                                      //loc_2BC57:
    _cx = 0xc8;                                 //mov cx, 0C8h
loc_2BC5A:                                      //loc_2BC5A:
    sub_2C26C();                                //call sub_2C26C
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(0x16);                           //int 16h
    if (_flags.zero)                            //jz short loc_2BC6A
      goto loc_2BC6A;
    _ah = _ah ^ _ah;                            //xor ah, ah
    _interrupt(0x16);                           //int 16h
    goto loc_2BC86;                             //jmp loc_2BC86
loc_2BC6A:                                      //loc_2BC6A:
    if (--_cx)                                  //loop loc_2BC5A
      goto loc_2BC5A;
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2BC57
      goto loc_2BC57;
    goto loc_2BC86;                             //jmp loc_2BC86
loc_2BC73:                                      //loc_2BC73:
    _si = 0x344f;                               //mov si, 344Fh
    _di = 0x1aef;                               //mov di, 1AEFh
    _cx = 0x0006;                               //mov cx, 6
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _si += 0x0004;                              //add si, 4
    _cx = 0x0003;                               //mov cx, 3
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
loc_2BC86:                                      //loc_2BC86:
    if (memory16(_ds, 0x2D45) != 5842)          //jnz short loc_2BC91
      goto loc_2BC91;
    sub_2AFF1();                                //call sub_2AFF1
loc_2BC91:                                      //loc_2BC91:
    if (memory16(_ds, 0x2D45) == 6021)          //jz short loc_2BC9F
      goto loc_2BC9F;
    sub_2F957();                                //call sub_2F957
    sub_2F9DB();                                //call sub_2F9DB
loc_2BC9F:                                      //loc_2BC9F:
    sub_2FA3A();                                //call sub_2FA3A
    sub_2B17E();                                //call sub_2B17E
    _sp = memory16(_ds, 0x1405);                //mov sp, ds:1405h
    _ASSERT(0);
    //goto loc_2ADF1;                             //jmp loc_2ADF1
    _STOP_("sp-trace-fail");                    //sub_2B94E endp_failed
    _STOP_("continues");                        //sub_2BCAC proc near
}

void sub_2BCFE()
{
    memory(_ds, 0x3F08) = 0;                    //mov byte ptr ds:3F08h, 0
    sub_2BE32();                                //call sub_2BE32
    sub_2AD26();                                //call sub_2AD26
    _push(_es);                                 //push es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _di = 0x0142;                               //mov di, 142h
loc_2BD12:                                      //loc_2BD12:
    _push(_di);                                 //push di
    _ax = 0xaaaa;                               //mov ax, 0AAAAh
    _cx = 0x18;                                 //mov cx, 18h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di -= 0x30;                                //sub di, 30h
    if (_di < 0x2000)                           //jb short loc_2BD2A
      goto loc_2BD2A;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2BD2E;                             //jmp short loc_2BD2E
loc_2BD2A:                                      //loc_2BD2A:
    _di += 0x2000;                              //add di, 2000h
loc_2BD2E:                                      //loc_2BD2E:
    _push(_di);                                 //push di
    _si = 0x13e1;                               //mov si, 13E1h
    _dl = 0x18;                                 //mov dl, 18h
    sub_2BCF1();                                //call sub_2BCF1
    _di = _pop();                               //pop di
    _di += 0x01e0;                              //add di, 1E0h
    _ax = 0xaaaa;                               //mov ax, 0AAAAh
    _cx = 0x18;                                 //mov cx, 18h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di = _pop();                               //pop di
    _push(_di);                                 //push di
    if (_di < 0x2000)                           //jb short loc_2BD52
      goto loc_2BD52;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2BD56;                             //jmp short loc_2BD56
loc_2BD52:                                      //loc_2BD52:
    _di += 0x2000;                              //add di, 2000h
loc_2BD56:                                      //loc_2BD56:
    _di += 0x16;                                //add di, 16h
    sub_2BFD8();                                //call sub_2BFD8
    std::cout << "Skip loc_2BD56\n";
//    if (_FIXME_)                                //jnb short loc_2BD86
//      goto loc_2BD86;
    _di = _pop();                               //pop di
    _dl = 0x0e;                                 //mov dl, 0Eh
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_2BD63:                                      //loc_2BD63:
    _cx = 0x18;                                 //mov cx, 18h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
//    _sync();
    _di -= 0x30;                                //sub di, 30h
    if (_di < 0x2000)                           //jb short loc_2BD77
      goto loc_2BD77;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2BD7B;                             //jmp short loc_2BD7B
loc_2BD77:                                      //loc_2BD77:
    _di += 0x2000;                              //add di, 2000h
loc_2BD7B:                                      //loc_2BD7B:
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2BD63
      goto loc_2BD63;
    _es = _pop();                               //pop es
    memory(_ds, 0x13E9) = 0x31;                 //mov byte ptr ds:13E9h, 31h
    _sync();
    return;                                     //retn
loc_2BD86:                                      //loc_2BD86:
    if (_al != 0xff)                            //jnz short loc_2BD8D
      goto loc_2BD8D;
    goto loc_2BE2A;                             //jmp loc_2BE2A
loc_2BD8D:                                      //loc_2BD8D:
    memory(_ds, 0x3F08) += 1;                   //inc byte ptr ds:3F08h
    if (memory(_ds, 0x3F08) != 9)               //jnz short loc_2BD9B
      goto loc_2BD9B;
    goto loc_2BE2A;                             //jmp loc_2BE2A
loc_2BD9B:                                      //loc_2BD9B:
    _di = _pop();                               //pop di
    _di += 0x0280;                              //add di, 280h
    _bp = _di;                                  //mov bp, di
    _al = 0x3f;                                 //mov al, 3Fh
    _stosb<MemAuto, DirAuto>();                 //stosb
    _ax = 0xffff;                               //mov ax, 0FFFFh
    _cx = 0x17;                                 //mov cx, 17h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _al = 0xfc;                                 //mov al, 0FCh
    _stosb<MemAuto, DirAuto>();                 //stosb
    _di = _bp;                                  //mov di, bp
    if (_di < 0x2000)                           //jb short loc_2BDBE
      goto loc_2BDBE;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2BDC2;                             //jmp short loc_2BDC2
loc_2BDBE:                                      //loc_2BDBE:
    _di += 0x2000;                              //add di, 2000h
loc_2BDC2:                                      //loc_2BDC2:
    _bp = _di;                                  //mov bp, di
    _al = 0xf5;                                 //mov al, 0F5h
    _stosb<MemAuto, DirAuto>();                 //stosb
    _al = 0x55;                                 //mov al, 55h
    _cx = 0x2f;                                 //mov cx, 2Fh
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    _di = _bp;                                  //mov di, bp
    if (_di < 0x2000)                           //jb short loc_2BDDC
      goto loc_2BDDC;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2BDE0;                             //jmp short loc_2BDE0
loc_2BDDC:                                      //loc_2BDDC:
    _di += 0x2000;                              //add di, 2000h
loc_2BDE0:                                      //loc_2BDE0:
    _bp = _di;                                  //mov bp, di
    _al = 0xd5;                                 //mov al, 0D5h
    _stosb<MemAuto, DirAuto>();                 //stosb
    _al = 0x15;                                 //mov al, 15h
    _cx = 0x2f;                                 //mov cx, 2Fh
    _rep_stosb<MemAuto, DirAuto>();             //rep stosb
    _di = _bp;                                  //mov di, bp
    if (_di < 0x2000)                           //jb short loc_2BDFA
      goto loc_2BDFA;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2BDFE;                             //jmp short loc_2BDFE
loc_2BDFA:                                      //loc_2BDFA:
    _di += 0x2000;                              //add di, 2000h
loc_2BDFE:                                      //loc_2BDFE:
    _bp = _di;                                  //mov bp, di
    _al = 0x15;                                 //mov al, 15h
    _stosb<MemAuto, DirAuto>();                 //stosb
    _ax = 0x5555;                               //mov ax, 5555h
    _cx = 0x17;                                 //mov cx, 17h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _al = 0x54;                                 //mov al, 54h
    _stosb<MemAuto, DirAuto>();                 //stosb
    memory(_ds, 0x13E9) += 1;                   //inc byte ptr ds:13E9h
    _di = _bp;                                  //mov di, bp
    if (_di < 0x2000)                           //jb short loc_2BE20
      goto loc_2BE20;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2BE24;                             //jmp short loc_2BE24
loc_2BE20:                                      //loc_2BE20:
    _di += 0x2000;                              //add di, 2000h
loc_2BE24:                                      //loc_2BE24:
    _di += 0x50;                                //add di, 50h
    goto loc_2BD12;                             //jmp loc_2BD12
loc_2BE2A:                                      //loc_2BE2A:
    _di = _pop();                               //pop di
    _es = _pop();                               //pop es
    memory(_ds, 0x13E9) = 0x31;                 //mov byte ptr ds:13E9h, 31h
}

void sub_2BE32()
{
    WORD _cs = _seg004;
    memory(_cs, 0x5C6D) = 0;                    //mov cs:byte_3088D, 0
    _push(_es);                                 //push es
    _dx = 0xb800;                               //mov dx, 0B800h
    _es = _dx;                                  //mov es, dx
    _di = 0x1e50;                               //mov di, 1E50h
    _bp = _di;                                  //mov bp, di
    _ax = 0xffff;                               //mov ax, 0FFFFh
    sub_2BF74();                                //call sub_2BF74
    _di = _bp;                                  //mov di, bp
    if (_di < 0x2000)                           //jb short loc_2BE57
      goto loc_2BE57;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2BE5B;                             //jmp short loc_2BE5B
loc_2BE57:                                      //loc_2BE57:
    _di += 0x2000;                              //add di, 2000h
loc_2BE5B:                                      //loc_2BE5B:
    _bp = _di;                                  //mov bp, di
    _ax = 0x5555;                               //mov ax, 5555h
    sub_2BF74();                                //call sub_2BF74
    _di = _bp;                                  //mov di, bp
    if (_di < 0x2000)                           //jb short loc_2BE71
      goto loc_2BE71;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2BE75;                             //jmp short loc_2BE75
loc_2BE71:                                      //loc_2BE71:
    _di += 0x2000;                              //add di, 2000h
loc_2BE75:                                      //loc_2BE75:
    _bp = _di;                                  //mov bp, di
    _ax = 0x5454;                               //mov ax, 5454h
    sub_2BF74();                                //call sub_2BF74
    _di = _bp;                                  //mov di, bp
    if (_di < 0x2000)                           //jb short loc_2BE8B
      goto loc_2BE8B;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2BE8F;                             //jmp short loc_2BE8F
loc_2BE8B:                                      //loc_2BE8B:
    _di += 0x2000;                              //add di, 2000h
loc_2BE8F:                                      //loc_2BE8F:
    _bp = _di;                                  //mov bp, di
    _ax = 0x5555;                               //mov ax, 5555h
    sub_2BF74();                                //call sub_2BF74
    _di = _bp;                                  //mov di, bp
    if (_di < 0x2000)                           //jb short loc_2BEA5
      goto loc_2BEA5;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2BEA9;                             //jmp short loc_2BEA9
loc_2BEA5:                                      //loc_2BEA5:
    _di += 0x2000;                              //add di, 2000h
loc_2BEA9:                                      //loc_2BEA9:
    _bp = _di;                                  //mov bp, di
    _ax = 0x0000;                               //mov ax, 0
    sub_2BF74();                                //call sub_2BF74
    _di = _bp;                                  //mov di, bp
    if (_di < 0x2000)                           //jb short loc_2BEBF
      goto loc_2BEBF;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2BEC3;                             //jmp short loc_2BEC3
loc_2BEBF:                                      //loc_2BEBF:
    _di += 0x2000;                              //add di, 2000h
loc_2BEC3:                                      //loc_2BEC3:
    _ax = 0x0000;                               //mov ax, 0
    sub_2BF74();                                //call sub_2BF74
    _di = 0x3e00;                               //mov di, 3E00h
    _push(_ds);                                 //push ds
    _ax = 0xb800;                               //mov ax, 0B800h
    _ds = _ax;                                  //mov ds, ax
    _dl = 0xc2;                                 //mov dl, 0C2h
loc_2BED4:                                      //loc_2BED4:
    _bp = _di;                                  //mov bp, di
    _push(_dx);                                 //push dx
    _dx = 0x03da;                               //mov dx, 3DAh
loc_2BEDA:                                      //loc_2BEDA:
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x08))                          //jz short loc_2BEDA
      goto loc_2BEDA;
loc_2BEDF:                                      //loc_2BEDF:
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x08)                             //jnz short loc_2BEDF
      goto loc_2BEDF;
    _dx = _pop();                               //pop dx
    _dh = 0x06;                                 //mov dh, 6
loc_2BEE7:                                      //loc_2BEE7:
    _si = _di;                                  //mov si, di
    if (_di < 0x2000)                           //jb short loc_2BEF5
      goto loc_2BEF5;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2BEF9;                             //jmp short loc_2BEF9
loc_2BEF5:                                      //loc_2BEF5:
    _di += 0x2000;                              //add di, 2000h
loc_2BEF9:                                      //loc_2BEF9:
    _xchg(_si, _di);                            //xchg si, di
    _cx = 0x1a;                                 //mov cx, 1Ah
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _di = _si;                                  //mov di, si
    _di -= 0x34;                                //sub di, 34h
    _dh -= 1;                                   //dec dh
    if (_dh != 0)                               //jnz short loc_2BEE7
      goto loc_2BEE7;
    if (_di < 0x2000)                           //jb short loc_2BF15
      goto loc_2BF15;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2BF19;                             //jmp short loc_2BF19
loc_2BF15:                                      //loc_2BF15:
    _di += 0x2000;                              //add di, 2000h
loc_2BF19:                                      //loc_2BF19:
    _al = memory(_cs, 0x5C6D);                  //mov al, cs:byte_3088D
    _bl = 0x50;                                 //mov bl, 50h
    _al &= 0x03;                                //and al, 3
    if (_al != 0)                               //jnz short loc_2BF25
      goto loc_2BF25;
    _bl = 0x10;                                 //mov bl, 10h
loc_2BF25:                                      //loc_2BF25:
    _al = 0x0d;                                 //mov al, 0Dh
    _stosb<MemAuto, DirAuto>();                 //stosb
    _al = _bl;                                  //mov al, bl
    _stosb<MemAuto, DirAuto>();                 //stosb
    _ax = 0x0000;                               //mov ax, 0
    _cx = 0x18;                                 //mov cx, 18h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _al = 0x0d;                                 //mov al, 0Dh
    _stosb<MemAuto, DirAuto>();                 //stosb
    _al = _bl;                                  //mov al, bl
    _stosb<MemAuto, DirAuto>();                 //stosb
    memory(_cs, 0x5C6D) += 1;                   //inc cs:byte_3088D
    _di = _bp;                                  //mov di, bp
    if (_di < 0x2000)                           //jb short loc_2BF4D
      goto loc_2BF4D;
    _di -= 0x2000;                              //sub di, 2000h
    goto loc_2BF51;                             //jmp loc_2BF51
loc_2BF4D:                                      //loc_2BF4D:
    _di += 0x1fb0;                              //add di, 1FB0h
loc_2BF51:                                      //loc_2BF51:
    _cx = 0x05dc;                               //mov cx, 5DCh
loc_2BF54:                                      //loc_2BF54:
    if (--_cx)                                  //loop loc_2BF54
      goto loc_2BF54;
    _dl -= 1;                                   //dec dl
    if (_dl == 0)                               //jz short loc_2BF5D
      goto loc_2BF5D;
    goto loc_2BED4;                             //jmp loc_2BED4
loc_2BF5D:                                      //loc_2BF5D:
    _ds = _pop();                               //pop ds
    _es = _pop();                               //pop es
    sub_2B531();                                //call sub_2B531
    _bx = 0x0005;                               //mov bx, 5
loc_2BF65:                                      //loc_2BF65:
    _cx = 0x0147;                               //mov cx, 147h
loc_2BF68:                                      //loc_2BF68:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2BF68
      goto loc_2BF68;
    _bx -= 1;                                   //dec bx
    if (_bx != 0)                               //jnz short loc_2BF65
      goto loc_2BF65;
    sub_2B5E5();                                //call sub_2B5E5
}

void sub_2C0D3()
{
    _bp = 0x4903;                               //mov bp, 4903h
    _dh = 0x04;                                 //mov dh, 4
loc_2C0D8:                                      //loc_2C0D8:
    _dl = 0x03;                                 //mov dl, 3
    _si = _bp;                                  //mov si, bp
loc_2C0DC:                                      //loc_2C0DC:
    _di = _si;                                  //mov di, si
    _di += 0x4d;                                //add di, 4Dh
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _cx = 0x4d;                                 //mov cx, 4Dh
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di = _pop();                               //pop di
    _cl = 0x07;                                 //mov cl, 7
loc_2C0EB:                                      //loc_2C0EB:
    _ch = 0x02;                                 //mov ch, 2
loc_2C0ED:                                      //loc_2C0ED:
    _flags.carry = memory(_ds, _di) & 1; // PARSER: mohol sam
    memory(_ds, _di) >>= 1;                     //shr byte ptr [di], 1
    _rcr(memory(_ds, _di + 1), 1);
    _rcr(memory(_ds, _di + 2), 1);
    _rcr(memory(_ds, _di + 3), 1);
    _rcr(memory(_ds, _di + 4), 1);
    _rcr(memory(_ds, _di + 5), 1);
    _rcr(memory(_ds, _di + 6), 1);
    _rcr(memory(_ds, _di + 7), 1);
    _rcr(memory(_ds, _di + 8), 1);
    _rcr(memory(_ds, _di + 9), 1);
    _rcr(memory(_ds, _di + 10), 1);
    _ch -= 1;                                   //dec ch
    if (_ch != 0)                               //jnz short loc_2C0ED
      goto loc_2C0ED;
    _di += 0x0b;                                //add di, 0Bh
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2C0EB
      goto loc_2C0EB;
    _si = _pop();                               //pop si
    _si += 0x4d;                                //add si, 4Dh
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2C0DC
      goto loc_2C0DC;
    _bp += 0x0134;                              //add bp, 134h
    _dh -= 1;                                   //dec dh
    if (_dh != 0)                               //jnz short loc_2C0D8
      goto loc_2C0D8;
}

void sub_2C129()
{
    WORD _cs = _seg004;
    memory16(_ds, 0x2D45) = 6021;               //mov word ptr ds:2D45h, 1785h
    memory(_cs, 0x1784) = 0xff;                 //mov cs:byte_2C3A4, 0FFh
    _di = 0x344f;                               //mov di, 344Fh
    _push(_di);                                 //push di
    _si = 0x13f9;                               //mov si, 13F9h
    _cx = 0x0006;                               //mov cx, 6
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _di = _pop();                               //pop di
    memory(_ds, _di + 12) = 5;                  //mov byte ptr [di+0Ch], 5
    memory16(_ds, _di + 13) = 0x0c;             //mov word ptr [di+0Dh], 0Ch
    memory(_ds, _di + 15) = 0;                  //mov byte ptr [di+0Fh], 0
    memory16(_ds, _di + 16) = 12336;            //mov word ptr [di+10h], 3030h
    memory16(_ds, _di + 18) = 12336;            //mov word ptr [di+12h], 3030h
    memory16(_ds, _di + 20) = 12336;            //mov word ptr [di+14h], 3030h
    _push(_di);                                 //push di
    _si = 0x0c;                                 //mov si, 0Ch
    _di += 0x16;                                //add di, 16h
    _push(_ds);                                 //push ds
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _cx = 0x58;                                 //mov cx, 58h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _ds = _pop();                               //pop ds
    _di = _pop();                               //pop di
    memory16(_ds, _di + 198) = 0xffff;          //mov word ptr [di+0C6h], 0FFFFh
    memory16(_ds, _di + 200) = 0xffff;          //mov word ptr [di+0C8h], 0FFFFh
    memory16(_ds, _di + 202) = 0xffff;          //mov word ptr [di+0CAh], 0FFFFh
    memory16(_ds, _di + 204) = 0xffff;          //mov word ptr [di+0CCh], 0FFFFh
    memory16(_ds, _di + 206) = 0xffff;          //mov word ptr [di+0CEh], 0FFFFh
    memory16(_ds, _di + 208) = 0xffff;          //mov word ptr [di+0D0h], 0FFFFh
    memory(_ds, _di + 211) = 0;                 //mov byte ptr [di+0D3h], 0
    memory(_ds, 0x3F08) = 1;                    //mov byte ptr ds:3F08h, 1
}

void sub_2C1A1()
{
    _ax = 0x0001;                               //mov ax, 1
    _interrupt(0x10);                           //int 10h
    _ah = 0x01;                                 //mov ah, 1
    _cx = 0xffff;                               //mov cx, 0FFFFh
    _interrupt(0x10);                           //int 10h
    sub_2AFD0();                                //call sub_2AFD0
    _push(_es);                                 //push es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _di = _di ^ _di;                            //xor di, di
    _ah = 0x03;                                 //mov ah, 3
    _al = 0xc9;                                 //mov al, 0C9h
    _stosw<MemAuto, DirAuto>();                 //stosw
    _al = 0xcd;                                 //mov al, 0CDh
    _cx = 0x26;                                 //mov cx, 26h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _al = 0xbb;                                 //mov al, 0BBh
    _stosw<MemAuto, DirAuto>();                 //stosw
    _dl = 0x17;                                 //mov dl, 17h
loc_2C1C9:                                      //loc_2C1C9:
    _al = 0xba;                                 //mov al, 0BAh
    _stosw<MemAuto, DirAuto>();                 //stosw
    _ah = 0x07;                                 //mov ah, 7
    _al = 0x20;                                 //mov al, 20h
    _cx = 0x26;                                 //mov cx, 26h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _ah = 0x03;                                 //mov ah, 3
    _al = 0xba;                                 //mov al, 0BAh
    _stosw<MemAuto, DirAuto>();                 //stosw
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2C1C9
      goto loc_2C1C9;
    _al = 0xc8;                                 //mov al, 0C8h
    _stosw<MemAuto, DirAuto>();                 //stosw
    _al = 0xcd;                                 //mov al, 0CDh
    _cx = 0x26;                                 //mov cx, 26h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _al = 0xbc;                                 //mov al, 0BCh
    _stosw<MemAuto, DirAuto>();                 //stosw
    _si = 0x2b03;                               //mov si, 2B03h
    _di = 0x62;                                 //mov di, 62h
    sub_2C262();                                //call sub_2C262
    _si = 0x2b1a;                               //mov si, 2B1Ah
    _di = 0x069a;                               //mov di, 69Ah
    sub_2C262();                                //call sub_2C262
    memory16(_ds, 0x2D4F) = 0;                  //mov word ptr ds:2D4Fh, 0
    memory(_ds, 0x2D51) = 0;                    //mov byte ptr ds:2D51h, 0
    _bl = _bl ^ _bl;                            //xor bl, bl
    _si = 0x2d5c;                               //mov si, 2D5Ch
    _di = 0x014c;                               //mov di, 14Ch
loc_2C210:                                      //loc_2C210:
    _push(_di);                                 //push di
    sub_2C262();                                //call sub_2C262
    _push(_si);                                 //push si
    memory(_ds, 0x2D49) = 1;                    //mov byte ptr ds:2D49h, 1
    sub_2C234();                                //call sub_2C234
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _di += 0xa0;                                //add di, 0A0h
    _bl += 1;                                   //inc bl
    if (_bl != 0x03)                            //jnz short loc_2C210
      goto loc_2C210;
    _es = _pop();                               //pop es
    sub_2AFF1();                                //call sub_2AFF1
    _ax = 0x0005;                               //mov ax, 5
    _interrupt(0x10);                           //int 10h
}

void seg004_2D45();

void sub_2C493()
{
    WORD ptr = 0;
    WORD _cs = _seg004;
    _bp = _es;                                  //mov bp, es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _al = memory(_ds, 0x13CC);                  //mov al, ds:13CCh
    _al += 1;                                   //inc al
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cl = 0x0a;                                 //mov cl, 0Ah
    _div(_cl);                                  //div cl
    _ax += 0x3030;                              //add ax, 3030h
    memory16(_ds, 0x1410) = _ax;                //mov ds:1410h, ax
    _di = 0x177e;                               //mov di, 177Eh
    _ax = 0xaaaa;                               //mov ax, 0AAAAh
    _cx = 0x0c;                                 //mov cx, 0Ch
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di = 0x377e;                               //mov di, 377Eh
    _push(_di);                                 //push di
    _si = 0x1407;                               //mov si, 1407h
    _dl = 0x0c;                                 //mov dl, 0Ch
    sub_2BCF1();                                //call sub_2BCF1
    _di = _pop();                               //pop di
    _di += 0x01e0;                              //add di, 1E0h
    _ax = 0xaaaa;                               //mov ax, 0AAAAh
    _cx = 0x0c;                                 //mov cx, 0Ch
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _es = _bp;                                  //mov es, bp
    _ax = _ax ^ _ax;                            //xor ax, ax
    _interrupt(0x33);                           //int 33h
    _ax = 0x0f;                                 //mov ax, 0Fh
    _cx = 0x0e;                                 //mov cx, 0Eh
    _dx = 0x0a;                                 //mov dx, 0Ah
    _interrupt(0x33);                           //int 33h
    sub_2C86F();                                //call sub_2C86F
    _bp = _es;                                  //mov bp, es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _di = 0x177e;                               //mov di, 177Eh
    _dl = 0x0e;                                 //mov dl, 0Eh
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_2C4F1:                                      //loc_2C4F1:
    _cx = 0x0c;                                 //mov cx, 0Ch
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di -= 0x18;                                //sub di, 18h
    if (_di < 0x2000)                           //jb short loc_2C505
      goto loc_2C505;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    _sync();
    goto loc_2C509;                             //jmp short loc_2C509
loc_2C505:                                      //loc_2C505:
    _di += 0x2000;                              //add di, 2000h
loc_2C509:                                      //loc_2C509:
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2C4F1
      goto loc_2C4F1;
    _es = _bp;                                  //mov es, bp
    _cx = 0x64;                                 //mov cx, 64h
    _dx = 0xb8;                                 //mov dx, 0B8h
    memory(_ds, 0x2E54) = _cl;                  //mov ds:2E54h, cl
    memory(_ds, 0x2E55) = _cl;                  //mov ds:2E55h, cl
    _ax = 0x0000;                               //mov ax, 0
    memory(_ds, 0x2D39) = _al;                  //mov ds:2D39h, al
    _di = 0x2d0d;                               //mov di, 2D0Dh
    _ax = memory16(_ds, _di + 2);               //mov ax, [di+2]
    memory(_ds, 0x2D3F) = 0xac;                 //mov byte ptr ds:2D3Fh, 0ACh
    memory(_ds, 0x2D3E) = 8;                    //mov byte ptr ds:2D3Eh, 8
    memory(_ds, 0x2D40) = 5;                    //mov byte ptr ds:2D40h, 5
    memory(_ds, 0x2D4B) = 5;                    //mov byte ptr ds:2D4Bh, 5
    memory(_ds, 0x2D3A) = _al;                  //mov ds:2D3Ah, al
    _cx <<= 1;                                  //shl cx, 1
    _ax = 0x0004;                               //mov ax, 4
    _interrupt(0x33);                           //int 33h
    _di = 0x2e57;                               //mov di, 2E57h
    _bl = memory(_ds, 0x2E54);                  //mov bl, ds:2E54h
    sub_2CEFE();                                //call sub_2CEFE
    _si = 0x4903;                               //mov si, 4903h
    _di = 0x2d8c;                               //mov di, 2D8Ch
    _cx = 0x27;                                 //mov cx, 27h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    memory(_ds, 0x2E73) = 1;                    //mov byte ptr ds:2E73h, 1
    _si = 0x48fb;                               //mov si, 48FBh
    _di = 0x2ea1;                               //mov di, 2EA1h
    _di += 0x0004;                              //add di, 4
    _cx = 0x0004;                               //mov cx, 4
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    memory16(_ds, 0x1489) = 500;                //mov word ptr ds:1489h, 1F4h
    memory(_ds, 0x2D4D) = 0;                    //mov byte ptr ds:2D4Dh, 0
    memory(_ds, 0x2D4E) = 0;                    //mov byte ptr ds:2D4Eh, 0
    memory(_ds, 0x2D4B) = 0;                    //mov byte ptr ds:2D4Bh, 0
    memory(_ds, 0x2D4C) = 0;                    //mov byte ptr ds:2D4Ch, 0
    memory(_ds, 0x1485) = 0xfa;                 //mov byte ptr ds:1485h, 0FAh
    memory(_ds, 0x1486) = 0xfa;                 //mov byte ptr ds:1486h, 0FAh
    std::cout << "loc_2C5A5: error!!!";
    if (memory(_cs, 0x2C26C) == 0xc3)           //jz short loc_2C5A5
      goto loc_2C5A5;
    memory(_ds, 0x1485) = 3;                    //mov byte ptr ds:1485h, 3
    memory(_ds, 0x1486) = 3;                    //mov byte ptr ds:1486h, 3
loc_2C5A5:                                      //loc_2C5A5:
    memory16(_ds, 0x148B) = 20000;              //mov word ptr ds:148Bh, 4E20h
    memory(_ds, 0x313A) = 0;                    //mov byte ptr ds:313Ah, 0
    memory(_ds, 0x33D5) = 0;                    //mov byte ptr ds:33D5h, 0
    memory(_ds, 0x33D6) = 0;                    //mov byte ptr ds:33D6h, 0
    memory(_ds, 0x3384) = 0;                    //mov byte ptr ds:3384h, 0
    memory(_ds, 0x2D3B) = 0;                    //mov byte ptr ds:2D3Bh, 0
    memory(_ds, 0x2E81) = 0;                    //mov byte ptr ds:2E81h, 0
    memory(_ds, 0x2E75) = 0;                    //mov byte ptr ds:2E75h, 0
    memory(_ds, 0x2E78) = 0;                    //mov byte ptr ds:2E78h, 0
    memory(_ds, 0x2E79) = 0;                    //mov byte ptr ds:2E79h, 0
    memory(_ds, 0x2E7E) = 0;                    //mov byte ptr ds:2E7Eh, 0
    _di = 0x2ea1;                               //mov di, 2EA1h
    memory(_ds, _di) = 0x70;                    //mov byte ptr [di], 70h
    memory(_ds, _di + 2) = 0x70;                //mov byte ptr [di+2], 70h
    memory(_ds, _di + 1) = 0xb5;                //mov byte ptr [di+1], 0B5h
    memory(_ds, _di + 3) = 0xb5;                //mov byte ptr [di+3], 0B5h
    memory(_ds, _di + 22) = 1;                  //mov byte ptr [di+16h], 1
    memory(_ds, _di + 23) = 2;                  //mov byte ptr [di+17h], 2
    memory(_ds, _di + 20) = 0;                  //mov byte ptr [di+14h], 0
    memory(_ds, _di + 21) = 1;                  //mov byte ptr [di+15h], 1
    _al = memory(_ds, _di);                     //mov al, [di]
    memory(_ds, _di + 24) = _al;                //mov [di+18h], al
    _al = memory(_ds, _di + 1);                 //mov al, [di+1]
    memory(_ds, _di + 25) = _al;                //mov [di+19h], al
    memory(_ds, _di + 26) = 0;                  //mov byte ptr [di+1Ah], 0
    memory(_ds, _di + 27) = 0;                  //mov byte ptr [di+1Bh], 0
    memory(_ds, _di + 28) = 1;                  //mov byte ptr [di+1Ch], 1
    memory(_ds, _di + 29) = 0;                  //mov byte ptr [di+1Dh], 0
    memory(_ds, _di + 58) = 0;                  //mov byte ptr [di+3Ah], 0
    memory(_ds, _di + 88) = 0;                  //mov byte ptr [di+58h], 0
    _si = _di;                                  //mov si, di
    _si += 0x0004;                              //add si, 4
    _bl = memory(_ds, _di);                     //mov bl, [di]
    _al = memory(_ds, _di + 1);                 //mov al, [di+1]
    sub_2D4A1();                                //call sub_2D4A1
    _ax = 0x0007;                               //mov ax, 7
    _cx = 0x10;                                 //mov cx, 10h
    _dx = 0x0168;                               //mov dx, 168h
    _interrupt(0x33);                           //int 33h
    if (memory16(_ds, 0x2D45) != 5842)          //jnz short loc_2C645
      goto loc_2C645;
    sub_2AFF1();                                //call sub_2AFF1
loc_2C645:                                      //loc_2C645:
    sub_2AD26();                                //call sub_2AD26
    if (memory16(_ds, 0x2D45) != 5842)          //jnz short loc_2C653
      goto loc_2C653;
    sub_2AFD0();                                //call sub_2AFD0
loc_2C653:                                      //loc_2C653:
    if (memory16(_ds, 0x2D45) == 6021)          //jz short loc_2C682
      goto loc_2C682;
    memory16(_ds, 0x2E7A) = 2000;               //mov word ptr ds:2E7Ah, 7D0h
loc_2C661:                                      //loc_2C661:
    memory16(_ds, 0x2E7A) -= 1;                 //dec word ptr ds:2E7Ah
    if (memory16(_ds, 0x2E7A) == 0)             //jz short loc_2C682
      goto loc_2C682;
    _cx = 0x0f;                                 //mov cx, 0Fh
loc_2C66A:                                      //loc_2C66A:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2C66A
      goto loc_2C66A;
    
    ptr = memory(_ds, 0x2D45);
    seg004_2D45();
//    std::cout << "Should call " << std::hex << ptr << "\n";
    //_STOP_("call word ptr ds:2D45h");           //call word ptr ds:2D45h
    if (memory(_ds, 0x2D4C) == 1)               //jz short loc_2C682
      goto loc_2C682;
    _si = 0x4903;                               //mov si, 4903h
    sub_2CE3A();                                //call sub_2CE3A
    goto loc_2C661;                             //jmp short loc_2C661
loc_2C682:                                      //loc_2C682:
    _ax = memory16(_ds, 0x1489);                //mov ax, ds:1489h
    memory16(_ds, 0x1487) = _ax;                //mov ds:1487h, ax
    _bp = _es;                                  //mov bp, es
    _si = _seg002;                              //mov si, seg seg002
    _es = _si;                                  //mov es, si
    memory(_ds, 0x3134) -= 1;                   //dec byte ptr ds:3134h
    if (memory(_ds, 0x3134) != 0)               //jnz short loc_2C6B2
      goto loc_2C6B2;
    _al = memory(_ds, 0x3135);                  //mov al, ds:3135h
    memory(_ds, 0x3134) = _al;                  //mov ds:3134h, al
    memory16(_ds, 0x3136) += 2;                 //add word ptr ds:3136h, 2
    _si = memory16(_ds, 0x3136);                //mov si, ds:3136h
    if (memory16(_es, _si) != 0xffff)           //jnz short loc_2C6B2
      goto loc_2C6B2;
    _ax = memory16(_es, _si + 2);               //mov ax, es:[si+2]
    memory16(_ds, 0x3136) = _ax;                //mov ds:3136h, ax
loc_2C6B2:                                      //loc_2C6B2:
    _es = _bp;                                  //mov es, bp
    if (memory(_ds, 0x2E73) != 0)               //jnz short loc_2C6C5
      goto loc_2C6C5;
    sub_2EDF4();                                //call sub_2EDF4
    memory(_ds, 0x2E78) = 1;                    //mov byte ptr ds:2E78h, 1
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_2C6C5:                                      //loc_2C6C5:
    if (memory(_ds, 0x2F10) != 0)               //jnz short loc_2C6D1
      goto loc_2C6D1;
    sub_2EDF4();                                //call sub_2EDF4
    _flags.carry = false;                       //clc
    return;                                     //retn
loc_2C6D1:                                      //loc_2C6D1:

//    ptr = memory(_ds, 0x2D45);
//    std::cout << "Should call " << std::hex << ptr << "\n";

    seg004_2D45();
//    _STOP_("call word ptr ds:2D45h");           //call word ptr ds:2D45h
    if (memory(_ds, 0x2D3B) != 0)               //jnz short loc_2C6EE
      goto loc_2C6EE;
    _bx = _bx ^ _bx;                            //xor bx, bx
    _bl = memory(_ds, 0x2D39);                  //mov bl, ds:2D39h
    _bx <<= 1;                                  //shl bx, 1
    _bx <<= 1;                                  //shl bx, 1
    _si = 0x2d0d;                               //mov si, 2D0Dh
    _si = memory16(_ds, _bx + _si);             //mov si, [bx+si]
    sub_2CE3A();                                //call sub_2CE3A
loc_2C6EE:                                      //loc_2C6EE:
    if (memory(_ds, 0x2E7E) == 0)               //jz short loc_2C6F8
      goto loc_2C6F8;
    sub_2DB03();                                //call sub_2DB03
loc_2C6F8:                                      //loc_2C6F8:
    memory16(_ds, 0x148B) -= 1;                 //dec word ptr ds:148Bh
    if (memory16(_ds, 0x148B) != 0)             //jnz short loc_2C715
      goto loc_2C715;
    memory16(_ds, 0x148B) = 25000;              //mov word ptr ds:148Bh, 61A8h
    if (memory(_ds, 0x1486) == 0xff)            //jz short loc_2C70F
      goto loc_2C70F;
    memory(_ds, 0x1486) += 1;                   //inc byte ptr ds:1486h
loc_2C70F:                                      //loc_2C70F:
    _al = memory(_ds, 0x1486);                  //mov al, ds:1486h
    memory(_ds, 0x1485) = _al;                  //mov ds:1485h, al
loc_2C715:                                      //loc_2C715:
    memory(_ds, 0x1485) -= 1;                   //dec byte ptr ds:1485h
    if (memory(_ds, 0x1485) != 0)               //jnz short loc_2C724
      goto loc_2C724;
    _al = memory(_ds, 0x1486);                  //mov al, ds:1486h
    memory(_ds, 0x1485) = _al;                  //mov ds:1485h, al
    goto loc_2C76D;                             //jmp loc_2C76D
loc_2C724:                                      //loc_2C724:
    _cl = 0x03;                                 //mov cl, 3
    _si = 0x2ea1;                               //mov si, 2EA1h
loc_2C729:                                      //loc_2C729:
    _push(_cx);                                 //push cx
    if (memory(_ds, _si + 28) == 0)             //jz short loc_2C765
      goto loc_2C765;
    if (memory(_ds, _si + 28) >= 3)             //jnb short loc_2C765
      goto loc_2C765;
    if (memory(_ds, 0x2E75) != 1)               //jnz short loc_2C742
      goto loc_2C742;
    sub_2DA3E();                                //call sub_2DA3E
    if (_FIXME_)                                //jnb short loc_2C765
      goto loc_2C765;
loc_2C742:                                      //loc_2C742:
    sub_2D3F7();                                //call sub_2D3F7
    sub_2D447();                                //call sub_2D447
    std::cout << "loc_2C742: Ignore\n";
    //if (_FIXME_)                                //jnb short loc_2C755
//      goto loc_2C755;
    _cx = _pop();                               //pop cx
    sub_2EDF4();                                //call sub_2EDF4
    memory(_ds, 0x2E78) = 1;                    //mov byte ptr ds:2E78h, 1
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_2C755:                                      //loc_2C755:
    if (memory(_ds, 0x2F10) != 0)               //jnz short loc_2C762
      goto loc_2C762;
    _cx = _pop();                               //pop cx
    sub_2EDF4();                                //call sub_2EDF4
    _flags.carry = false;                       //clc
    return;                                     //retn
loc_2C762:                                      //loc_2C762:
    sub_2D09F();                                //call sub_2D09F
loc_2C765:                                      //loc_2C765:
    _si += 0x1e;                                //add si, 1Eh
    _cx = _pop();                               //pop cx
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2C729
      goto loc_2C729;
loc_2C76D:                                      //loc_2C76D:
    memory16(_ds, 0x3142) = 12600;              //mov word ptr ds:3142h, 3138h
    _bx = memory16(_ds, 0x3144);                //mov bx, ds:3144h
loc_2C777:                                      //loc_2C777:
    if (_bx == 0xffff)                          //jz short loc_2C79B
      goto loc_2C79B;
    _push(_bx);                                 //push bx
    _STOP_("call word ptr [bx]");               //call word ptr [bx]
    _bx = _pop();                               //pop bx
    if (memory(_ds, 0x313A) != 0)               //jnz short loc_2C791
      goto loc_2C791;
    memory16(_ds, 0x3142) = _bx;                //mov ds:3142h, bx
    _bx = memory16(_ds, _bx + 12);              //mov bx, [bx+0Ch]
    goto loc_2C777;                             //jmp short loc_2C777
loc_2C791:                                      //loc_2C791:
    _cx = memory16(_ds, _bx + 12);              //mov cx, [bx+0Ch]
    sub_2DE77();                                //call sub_2DE77
    _bx = _cx;                                  //mov bx, cx
    goto loc_2C777;                             //jmp short loc_2C777
loc_2C79B:                                      //loc_2C79B:
    if (memory(_ds, 0x2E81) == 0)               //jz short loc_2C7E4
      goto loc_2C7E4;
    memory(_ds, 0x2E84) -= 1;                   //dec byte ptr ds:2E84h
    if (memory(_ds, 0x2E84) != 0)               //jnz short loc_2C7D3
      goto loc_2C7D3;
    _bp = _es;                                  //mov bp, es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _di = memory16(_ds, 0x2E85);                //mov di, ds:2E85h
    _ax = _ax ^ _ax;                            //xor ax, ax
    _stosw<MemAuto, DirAuto>();                 //stosw
    _di -= 1;                                   //dec di
    _di -= 1;                                   //dec di
    if (_di < 0x2000)                           //jb short loc_2C7C4
      goto loc_2C7C4;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2C7C8;                             //jmp short loc_2C7C8
loc_2C7C4:                                      //loc_2C7C4:
    _di += 0x2000;                              //add di, 2000h
loc_2C7C8:                                      //loc_2C7C8:
    memory16(_ds, 0x2E85) = _di;                //mov ds:2E85h, di
    memory(_ds, 0x2E84) = 0xc8;                 //mov byte ptr ds:2E84h, 0C8h
    _es = _bp;                                  //mov es, bp
loc_2C7D3:                                      //loc_2C7D3:
    memory16(_ds, 0x2E82) -= 1;                 //dec word ptr ds:2E82h
    if (memory16(_ds, 0x2E82) != 0)             //jnz short loc_2C7E4
      goto loc_2C7E4;
    memory(_ds, 0x2E81) = 0;                    //mov byte ptr ds:2E81h, 0
    _dx = 0x1554;                               //mov dx, 1554h
    sub_2DD66();                                //call sub_2DD66
loc_2C7E4:                                      //loc_2C7E4:
    if (memory(_ds, 0x2E79) == 0)               //jz short loc_2C828
      goto loc_2C828;
    memory16(_ds, 0x2E7C) -= 1;                 //dec word ptr ds:2E7Ch
    if (memory16(_ds, 0x2E7C) != 0)             //jnz short loc_2C81D
      goto loc_2C81D;
    _bp = _es;                                  //mov bp, es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _di = memory16(_ds, 0x2E87);                //mov di, ds:2E87h
    _ax = _ax ^ _ax;                            //xor ax, ax
    _stosw<MemAuto, DirAuto>();                 //stosw
    _di -= 1;                                   //dec di
    _di -= 1;                                   //dec di
    if (_di < 0x2000)                           //jb short loc_2C80D
      goto loc_2C80D;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2C811;                             //jmp short loc_2C811
loc_2C80D:                                      //loc_2C80D:
    _di += 0x2000;                              //add di, 2000h
loc_2C811:                                      //loc_2C811:
    memory16(_ds, 0x2E87) = _di;                //mov ds:2E87h, di
    memory16(_ds, 0x2E7C) = 400;                //mov word ptr ds:2E7Ch, 190h
    _es = _bp;                                  //mov es, bp
loc_2C81D:                                      //loc_2C81D:
    memory16(_ds, 0x2E7A) -= 1;                 //dec word ptr ds:2E7Ah
    if (memory16(_ds, 0x2E7A) != 0)             //jnz short loc_2C828
      goto loc_2C828;
    memory(_ds, 0x2E79) = 0;                    //mov byte ptr ds:2E79h, 0
loc_2C828:                                      //loc_2C828:
    _ah = 0x03;                                 //mov ah, 3
    _ah = _ah - memory(_ds, 0x33D6);            //sub ah, ds:33D6h
    if (_ah == 0)                               //jz short loc_2C839
      goto loc_2C839;
loc_2C830:                                      //loc_2C830:
    _cx = 0xb4;                                 //mov cx, 0B4h
loc_2C833:                                      //loc_2C833:
    if (--_cx)                                  //loop loc_2C833
      goto loc_2C833;
    _ah -= 1;                                   //dec ah
    if (_ah != 0)                               //jnz short loc_2C830
      goto loc_2C830;
loc_2C839:                                      //loc_2C839:
    if (memory(_ds, 0x2E79) == 1)               //jz short loc_2C853
      goto loc_2C853;
    if (memory(_ds, 0x33D5) == 3)               //jz short loc_2C853
      goto loc_2C853;
    _dl = 0x86;                                 //mov dl, 86h
    sub_2ECE0();                                //call sub_2ECE0
    _ah |= _ah;                                 //or ah, ah
    if (_ah != 0)                               //jnz short loc_2C853
      goto loc_2C853;
    sub_2E9B5();                                //call sub_2E9B5
loc_2C853:                                      //loc_2C853:
    sub_2ACB7();                                //call sub_2ACB7
    _cx = memory16(_ds, 0x1487);                //mov cx, ds:1487h
loc_2C85A:                                      //loc_2C85A:
    if (--_cx)                                  //loop loc_2C85A
      goto loc_2C85A;
    sub_2C26C();                                //call sub_2C26C
    goto loc_2C682;                             //jmp loc_2C682
}

void sub_2E7CC()
{
    _flags.interrupt = false;                   //cli
    _push(_es);                                 //push es
    _push(_ds);                                 //push ds
    _di = 0xb800;                               //mov di, 0B800h
    _es = _di;                                  //mov es, di
    _di = _seg002;                              //mov di, seg seg002
    _ds = _di;                                  //mov ds, di
    _ch = _ch ^ _ch;                            //xor ch, ch
    _di = _cx;                                  //mov di, cx
    _di >>= 1;                                  //shr di, 1
    _di >>= 1;                                  //shr di, 1
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (!_flags.carry)                          //jnb short loc_2E7E9
      goto loc_2E7E9;
    _di += 0x2000;                              //add di, 2000h
loc_2E7E9:                                      //loc_2E7E9:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cl = 0x04;                                 //mov cl, 4
    _ax <<= _cl;                                //shl ax, cl
    _di += _ax;                                 //add di, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _cx = 0x0008;                               //mov cx, 8
loc_2E7FA:                                      //loc_2E7FA:
    _movsw<MemAuto, MemAuto, DirAuto>();        //movsw
    _movsw<MemAuto, MemAuto, DirAuto>();        //movsw
    _di -= 0x0004;                              //sub di, 4
    if (_di < 0x2000)                           //jb short loc_2E80D
      goto loc_2E80D;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    if (--_cx)                                  //loop loc_2E7FA
      goto loc_2E7FA;
    goto loc_2E813;                             //jmp short loc_2E813
loc_2E80D:                                      //loc_2E80D:
    _di += 0x2000;                              //add di, 2000h
    if (--_cx)                                  //loop loc_2E7FA
      goto loc_2E7FA;
loc_2E813:                                      //loc_2E813:
    _ds = _pop();                               //pop ds
    _es = _pop();                               //pop es
    _flags.interrupt = true;                    //sti
}

void seg004_2D45()
{
    _dh = 0;
    _cl = 5;
    _dx <<= _cl;
    _si += _dx;
    _cx = _pop();
    sub_2E7CC();
    _di = _pop();
    sub_2DE52();
    _dx = _pop();
    memory16(_ds, _si) = 0x3ABF;
    _ax = memory16(_ds, _di+2);
    memory16(_ds, _si+2) = _ax;
    memory(_ds, _si+4) = _dl;
    memory(_ds, 0x2F10)--;

}

void sub_2CAD9()
{
    _sync();
    /*
    for (int i=0; i<20; i++)
    {
        memory(0x1000, 0x6dcf+i) = 0xff;
        memory(0x1000, 0x6dff+i) = 0xff;
        memory(0x1000, 0x6e2f+i) = 0xff;
    }
    */
    _push(_es);                                 //push es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _si = 0x6d9f;                               //mov si, 6D9Fh
    _bl = 0x08;                                 //mov bl, 8
loc_2CAE4:                                      //loc_2CAE4:
    _push(_si);                                 //push si
    sub_2CD29();                                //call sub_2CD29
    _si = _pop();                               //pop si
    _di = 0x3ef2;                               //mov di, 3EF2h
    _cx = 0x18;                                 //mov cx, 18h
    // es:di <- ds:si
    std::cout << std::hex << _es << ":" << _di << " <- " << _ds << ":" << _si << " count=" << std::dec << _cx << "\n";
    _rep_movsw<MemVideo, MemAuto, DirAuto>();    //rep movsw
    _cx = 0x07d0;                               //mov cx, 7D0h
    _sync();
loc_2CAF4:                                      //loc_2CAF4:
    if (--_cx)                                  //loop loc_2CAF4
      goto loc_2CAF4;
    _bl -= 1;                                   //dec bl
    if (_bl != 0)                               //jnz short loc_2CAE4
      goto loc_2CAE4;
    _si = 0x6d36;                               //mov si, 6D36h
    _bl = 0x13;                                 //mov bl, 13h
loc_2CB00:                                      //loc_2CB00:
    _push(_si);                                 //push si
    sub_2CD29();                                //call sub_2CD29
    _si = _pop();                               //pop si
    _di = 0x3f08;                               //mov di, 3F08h
    _cx = 0x0005;                               //mov cx, 5
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _cx = 0x08fc;                               //mov cx, 8FCh
loc_2CB10:                                      //loc_2CB10:
    if (--_cx)                                  //loop loc_2CB10
      goto loc_2CB10;
    _bl -= 1;                                   //dec bl
    if (_bl != 0)                               //jnz short loc_2CB00
      goto loc_2CB00;
    _es = _pop();                               //pop es
    memory(_ds, 0x2F0F) = 0xc2;                 //mov byte ptr ds:2F0Fh, 0C2h
    memory(_ds, 0x2F0E) = 0xbd;                 //mov byte ptr ds:2F0Eh, 0BDh
    memory(_ds, 0x2F0D) = 0xb8;                 //mov byte ptr ds:2F0Dh, 0B8h
    memory(_ds, 0x2F0C) = 0xb3;                 //mov byte ptr ds:2F0Ch, 0B3h
loc_2CB2C:                                      //loc_2CB2C:
    if (memory(_ds, 0x2F0C) == 0x0c)            //jz short loc_2CB77
      goto loc_2CB77;
    _al = memory(_ds, 0x2F0C);                  //mov al, ds:2F0Ch
    _al -= 0x07;                                //sub al, 7
    sub_2CBE1();                                //call sub_2CBE1
    _cx = _cx ^ _cx;                            //xor cx, cx
loc_2CB3D:                                      //loc_2CB3D:
    _push(_cx);                                 //push cx
    _cx <<= 1;                                  //shl cx, 1
    _cx <<= 1;                                  //shl cx, 1
    _si = 0x2efc;                               //mov si, 2EFCh
    _si += _cx;                                 //add si, cx
    memory(_ds, _si) += 1;                      //inc byte ptr [si]
    _dl = memory(_ds, _si + 1);                 //mov dl, [si+1]
    if (_dl != memory(_ds, _si))                //jnz short loc_2CB66
      goto loc_2CB66;
    memory(_ds, _si) = 0;                       //mov byte ptr [si], 0
    _cx = _pop();                               //pop cx
    _push(_cx);                                 //push cx
    _di = 0x2f0c;                               //mov di, 2F0Ch
    _di += _cx;                                 //add di, cx
    memory(_ds, _di) -= 1;                      //dec byte ptr [di]
    _al = memory(_ds, _di);                     //mov al, [di]
    _bl = 0x60;                                 //mov bl, 60h
    _si = memory16(_ds, _si + 2);               //mov si, [si+2]
//    _sync();
    sub_2CCD9();                                //call sub_2CCD9
//    _sync();
loc_2CB66:                                      //loc_2CB66:
    _cx = _pop();                               //pop cx
    _cx += 1;                                   //inc cx
    if (_cx != 0x0004)                          //jnz short loc_2CB3D
      goto loc_2CB3D;
    _cx = 0x0a;                                 //mov cx, 0Ah
loc_2CB70:                                      //loc_2CB70:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2CB70
      goto loc_2CB70;
    ///_sync();
    goto loc_2CB2C;                             //jmp short loc_2CB2C
loc_2CB77:                                      //loc_2CB77:
    if (memory(_ds, 0x2F0C) == 0xb3)            //jz short loc_2CBCE
      goto loc_2CBCE;
    _al = memory(_ds, 0x2F0C);                  //mov al, ds:2F0Ch
    _al -= 0x06;                                //sub al, 6
    _push(_ax);                                 //push ax
    sub_2CC54();                                //call sub_2CC54
    _ax = _pop();                               //pop ax
    _ax += 1;                                   //inc ax
    sub_2CBE1();                                //call sub_2CBE1
    _cx = 0x0003;                               //mov cx, 3
loc_2CB8F:                                      //loc_2CB8F:
    _bp = _cx;                                  //mov bp, cx
    _cx <<= 1;                                  //shl cx, 1
    _cx <<= 1;                                  //shl cx, 1
    _si = 0x2efc;                               //mov si, 2EFCh
    _si += _cx;                                 //add si, cx
    _push(_si);                                 //push si
    if (memory(_ds, _si) != 0)                  //jnz short loc_2CBB8
      goto loc_2CBB8;
    _dl = memory(_ds, _si + 1);                 //mov dl, [si+1]
    memory(_ds, _si) = _dl;                     //mov [si], dl
    _cx = _bp;                                  //mov cx, bp
    _di = 0x2f0c;                               //mov di, 2F0Ch
    _di += _cx;                                 //add di, cx
    memory(_ds, _di) += 1;                      //inc byte ptr [di]
    _al = memory(_ds, _di);                     //mov al, [di]
    _bl = 0x60;                                 //mov bl, 60h
    _si = memory16(_ds, _si + 2);               //mov si, [si+2]
    sub_2CCD9();                                //call sub_2CCD9
loc_2CBB8:                                      //loc_2CBB8:
    _si = _pop();                               //pop si
    memory(_ds, _si) -= 1;                      //dec byte ptr [si]
    _cx = _bp;                                  //mov cx, bp
    _cx -= 1;                                   //dec cx
    if (_cx != 0xffff)                          //jnz short loc_2CB8F
      goto loc_2CB8F;
    _cx = 0x0a;                                 //mov cx, 0Ah
loc_2CBC7:                                      //loc_2CBC7:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2CBC7
      goto loc_2CBC7;
    goto loc_2CB77;                             //jmp short loc_2CB77
loc_2CBCE:                                      //loc_2CBCE:
    _cx = 0x1b;                                 //mov cx, 1Bh
loc_2CBD1:                                      //loc_2CBD1:
    _push(_cx);                                 //push cx
    sub_2CD68();                                //call sub_2CD68
    _cx = 0x0c;                                 //mov cx, 0Ch
loc_2CBD8:                                      //loc_2CBD8:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2CBD8
      goto loc_2CBD8;
    _cx = _pop();                               //pop cx
    if (--_cx)                                  //loop loc_2CBD1
      goto loc_2CBD1;
}

void sub_2ECE0()
{
    _push(_es);                                 //push es
    _ax = 0x0000;                               //mov ax, 0
    _es = _ax;                                  //mov es, ax
    //_ax = memory16(_es, 0x46C);                 //mov ax, es:46Ch
    //_ax = _ax + memory16(_es, 0x46E);           //add ax, es:46Eh
    _ax += rand();
    _es = _pop();                               //pop es
    _push(_si);                                 //push si
    _push(_dx);                                 //push dx
    _si = 0x3164;                               //mov si, 3164h
    _dh = 0x0a;                                 //mov dh, 0Ah
loc_2ECF7:                                      //loc_2ECF7:
    _ax = _ax + memory16(_ds, _si);             //add ax, [si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    _dh -= 1;                                   //dec dh
    if (_dh != 0)                               //jnz short loc_2ECF7
      goto loc_2ECF7;
    _ax = _ax + memory16(_ds, 0x33D2);          //add ax, ds:33D2h
    memory16(_ds, 0x33D2) += 24261;             //add word ptr ds:33D2h, 5EC5h
    _al += _ah;                                 //add al, ah
    _ah = _ah ^ _ah;                            //xor ah, ah
    _div(_dl);                                  //div dl
    _dx = _pop();                               //pop dx
    _si = _pop();                               //pop si
}

void sub_2F52D()
{
    _push(_ax);                                 //push ax
    _push(_es);                                 //push es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _di = 0x0bfe;                               //mov di, 0BFEh
    sub_2F54F();                                //call sub_2F54F
    _di = 0x0bfe;                               //mov di, 0BFEh
    sub_2F577();                                //call sub_2F577
    _di = 0x088e;                               //mov di, 88Eh
    sub_2F577();                                //call sub_2F577
    _di = 0x088e;                               //mov di, 88Eh
    sub_2F54F();                                //call sub_2F54F
    _es = _pop();                               //pop es
    _ax = _pop();                               //pop ax
}

void sub_2F5DC()
{
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _bp = 0x490a;                               //mov bp, 490Ah
    _bh = 0x01;                                 //mov bh, 1
loc_2F5E6:                                      //loc_2F5E6:
    _si = _bp;                                  //mov si, bp
    _bl = 0x04;                                 //mov bl, 4
loc_2F5EA:                                      //loc_2F5EA:
    _push(_si);                                 //push si
    _dx = 0x03da;                               //mov dx, 3DAh
loc_2F5EE:                                      //loc_2F5EE:
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x08))                          //jz short loc_2F5EE
      goto loc_2F5EE;
loc_2F5F3:                                      //loc_2F5F3:
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x08)                             //jnz short loc_2F5F3
      goto loc_2F5F3;
    _di = 0x1900;                               //mov di, 1900h
    _dl = 0x07;                                 //mov dl, 7
loc_2F5FD:                                      //loc_2F5FD:
    _ch = _ch ^ _ch;                            //xor ch, ch
    _cl = _bh;                                  //mov cl, bh
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _cl = _bh;                                  //mov cl, bh
    _di -= _cx;                                 //sub di, cx
    _si -= _cx;                                 //sub si, cx
    _si += 0x0b;                                //add si, 0Bh
    if (_di < 0x2000)                           //jb short loc_2F618
      goto loc_2F618;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2F61C;                             //jmp short loc_2F61C
loc_2F618:                                      //loc_2F618:
    _di += 0x2000;                              //add di, 2000h
loc_2F61C:                                      //loc_2F61C:
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2F5FD
      goto loc_2F5FD;
    _cx = 0x19;                                 //mov cx, 19h
loc_2F623:                                      //loc_2F623:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2F623
      goto loc_2F623;
    _si = _pop();                               //pop si
    _si += 0x4d;                                //add si, 4Dh
    _bl -= 1;                                   //dec bl
    if (_bl != 0)                               //jnz short loc_2F5EA
      goto loc_2F5EA;
    _bh += 1;                                   //inc bh
    _bp -= 1;                                   //dec bp
    if (_bp != 0x4902)                          //jnz short loc_2F5E6
      goto loc_2F5E6;
    _bp = 0x4903;                               //mov bp, 4903h
    _bh = _bh ^ _bh;                            //xor bh, bh
loc_2F63E:                                      //loc_2F63E:
    _si = _bp;                                  //mov si, bp
    _bl = 0x04;                                 //mov bl, 4
loc_2F642:                                      //loc_2F642:
    _push(_si);                                 //push si
    _dx = 0x03da;                               //mov dx, 3DAh
loc_2F646:                                      //loc_2F646:
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x08))                          //jz short loc_2F646
      goto loc_2F646;
loc_2F64B:                                      //loc_2F64B:
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x08)                             //jnz short loc_2F64B
      goto loc_2F64B;
    _di = 0x1900;                               //mov di, 1900h
    _ch = _ch ^ _ch;                            //xor ch, ch
    _cl = _bh;                                  //mov cl, bh
    _di += _cx;                                 //add di, cx
    _dl = 0x07;                                 //mov dl, 7
loc_2F65B:                                      //loc_2F65B:
    _cx = 0x0008;                               //mov cx, 8
    _al = 0x00;                                 //mov al, 0
    _stosb<MemAuto, DirAuto>();                 //stosb
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _cl = _bh;                                  //mov cl, bh
    _di -= 0x0009;                              //sub di, 9
    _si -= 0x0008;                              //sub si, 8
    _si += 0x0b;                                //add si, 0Bh
    if (_di < 0x2000)                           //jb short loc_2F67A
      goto loc_2F67A;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2F67E;                             //jmp short loc_2F67E
loc_2F67A:                                      //loc_2F67A:
    _di += 0x2000;                              //add di, 2000h
loc_2F67E:                                      //loc_2F67E:
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2F65B
      goto loc_2F65B;
    _cx = 0x19;                                 //mov cx, 19h
loc_2F685:                                      //loc_2F685:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2F685
      goto loc_2F685;
    _si = _pop();                               //pop si
    _si += 0x4d;                                //add si, 4Dh
    _bl -= 1;                                   //dec bl
    if (_bl != 0)                               //jnz short loc_2F642
      goto loc_2F642;
    _bh += 1;                                   //inc bh
    if (_bh != 0x16)                            //jnz short loc_2F63E
      goto loc_2F63E;
}

void sub_2F69A()
{
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _bl = 0x1a;                                 //mov bl, 1Ah
    _bp = 0x488a;                               //mov bp, 488Ah
loc_2F6A4:                                      //loc_2F6A4:
    _ax = 0xb800;                               //mov ax, 0B800h
    _ds = _ax;                                  //mov ds, ax
    _bh = 0x19;                                 //mov bh, 19h
    _di = 0x1b33;                               //mov di, 1B33h
    _dx = 0x03da;                               //mov dx, 3DAh
loc_2F6B1:                                      //loc_2F6B1:
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x08))                          //jz short loc_2F6B1
      goto loc_2F6B1;
loc_2F6B6:                                      //loc_2F6B6:
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x08)                             //jnz short loc_2F6B6
      goto loc_2F6B6;
loc_2F6BB:                                      //loc_2F6BB:
    _si = _di;                                  //mov si, di
    if (_di < 0x2000)                           //jb short loc_2F6C9
      goto loc_2F6C9;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2F6CD;                             //jmp short loc_2F6CD
loc_2F6C9:                                      //loc_2F6C9:
    _di += 0x2000;                              //add di, 2000h
loc_2F6CD:                                      //loc_2F6CD:
    _xchg(_si, _di);                            //xchg si, di
    _cx = 0x31;                                 //mov cx, 31h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _si -= 0x31;                                //sub si, 31h
    _di = _si;                                  //mov di, si
    _bh -= 1;                                   //dec bh
    if (_bh != 0)                               //jnz short loc_2F6BB
      goto loc_2F6BB;
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _si = _bp;                                  //mov si, bp
    _di = 0x3ef3;                               //mov di, 3EF3h
    _cx = 0x31;                                 //mov cx, 31h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _bp = _si;                                  //mov bp, si
    _cx = 0x19;                                 //mov cx, 19h
loc_2F6F1:                                      //loc_2F6F1:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2F6F1
      goto loc_2F6F1;
    _bl -= 1;                                   //dec bl
    if (_bl != 0)                               //jnz short loc_2F6A4
      goto loc_2F6A4;
    _ax = _seg000;                              //mov ax, seg seg000
    _ds = _ax;                                  //mov ds, ax
}

void sub_2F700()
{
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    sub_2ACB0();                                //call sub_2ACB0
    _ax = 0xb800;                               //mov ax, 0B800h
    _ds = _ax;                                  //mov ds, ax
    _ax = _seg000;                              //mov ax, seg seg000
    _es = _ax;                                  //mov es, ax
    _si = _si ^ _si;                            //xor si, si
    _di = 0x1aef;                               //mov di, 1AEFh
    _cx = 0x07d0;                               //mov cx, 7D0h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _dx = 0x03d8;                               //mov dx, 3D8h
    _al = 0x09;                                 //mov al, 9
    _out(_dx, _al);                             //out dx, al
    _si = 0x4b91;                               //mov si, 4B91h
    sub_2F79A();                                //call sub_2F79A
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _cx = 0xffff;                               //mov cx, 0FFFFh
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(0x10);                           //int 10h
    _di = _di ^ _di;                            //xor di, di
    _si = 0x2298;                               //mov si, 2298h
    _ah = 0x07;                                 //mov ah, 7
loc_2F742:                                      //loc_2F742:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz short loc_2F75E
      goto loc_2F75E;
    if (_al != 0x5b)                            //jnz short loc_2F74F
      goto loc_2F74F;
    _ah = 0x70;                                 //mov ah, 70h
    goto loc_2F742;                             //jmp short loc_2F742
loc_2F74F:                                      //loc_2F74F:
    if (_al != 0x9c)                            //jnz short loc_2F757
      goto loc_2F757;
    _ah = 0x07;                                 //mov ah, 7
    goto loc_2F742;                             //jmp short loc_2F742
loc_2F757:                                      //loc_2F757:
    if (_al == 0x24)                            //jz short loc_2F766
      goto loc_2F766;
    _stosw<MemAuto, DirAuto>();                 //stosw
    goto loc_2F742;                             //jmp short loc_2F742
loc_2F75E:                                      //loc_2F75E:
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
    return;                                     //retn
loc_2F766:                                      //loc_2F766:
    _cx = 0x0008;                               //mov cx, 8
    _al = 0x20;                                 //mov al, 20h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    goto loc_2F742;                             //jmp short loc_2F742
}

void sub_2F76F()
{
    _push(_es);                                 //push es
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _dx = 0x03d8;                               //mov dx, 3D8h
    _al = 0x0e;                                 //mov al, 0Eh
    _out(_dx, _al);                             //out dx, al
    _si = 0x4b9d;                               //mov si, 4B9Dh
    sub_2F79A();                                //call sub_2F79A
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _di = _di ^ _di;                            //xor di, di
    _si = 0x1aef;                               //mov si, 1AEFh
    _cx = 0x07d0;                               //mov cx, 7D0h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    sub_2ACA5();                                //call sub_2ACA5
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
    _es = _pop();                               //pop es
}

void sub_2F9B6()
{
    _al = memory(_ds, 0x141B);                  //mov al, ds:141Bh
    sub_2FA0A();                                //call sub_2FA0A
    if (_FIXME_)                                //jnb short loc_2F9BF
      goto loc_2F9BF;
locret_2F9BE:                                   //locret_2F9BE:
    return;                                     //retn
loc_2F9BF:                                      //loc_2F9BF:
    _ah = 0x3d;                                 //mov ah, 3Dh
    _al = _al ^ _al;                            //xor al, al
    _dx = 0x141c;                               //mov dx, 141Ch
    _interrupt(0x21);                           //int 21h
    if (_flags.carry)                           //jb short locret_2F9BE
      goto locret_2F9BE;
    _bx = _ax;                                  //mov bx, ax
    _ah = 0x3f;                                 //mov ah, 3Fh
    _dx = 0x3e42;                               //mov dx, 3E42h
    _cx = 0xb4;                                 //mov cx, 0B4h
    _interrupt(0x21);                           //int 21h
    _ah = 0x3e;                                 //mov ah, 3Eh
    _interrupt(0x21);                           //int 21h
}

void sub_2FA3A()
{
    _push(_es);                                 //push es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    sub_2FB93();                                //call sub_2FB93
    _di = 0x0142;                               //mov di, 142h
    _ax = 0xaaaa;                               //mov ax, 0AAAAh
    _cx = 0x18;                                 //mov cx, 18h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di = 0x2142;                               //mov di, 2142h
    _dl = 0x07;                                 //mov dl, 7
    _al = 0x20;                                 //mov al, 20h
    sub_2BCE5();                                //call sub_2BCE5
    _al = 0x48;                                 //mov al, 48h
    sub_2B884();                                //call sub_2B884
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _al = 0x49;                                 //mov al, 49h
    sub_2B884();                                //call sub_2B884
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _al = 0x47;                                 //mov al, 47h
    sub_2B884();                                //call sub_2B884
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _al = 0x48;                                 //mov al, 48h
    sub_2B884();                                //call sub_2B884
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _al = 0x20;                                 //mov al, 20h
    sub_2B884();                                //call sub_2B884
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _al = 0x53;                                 //mov al, 53h
    sub_2B884();                                //call sub_2B884
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _al = 0x43;                                 //mov al, 43h
    sub_2B884();                                //call sub_2B884
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _al = 0x4f;                                 //mov al, 4Fh
    sub_2B884();                                //call sub_2B884
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _al = 0x52;                                 //mov al, 52h
    sub_2B884();                                //call sub_2B884
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _al = 0x45;                                 //mov al, 45h
    sub_2B884();                                //call sub_2B884
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _dl = 0x07;                                 //mov dl, 7
    _al = 0x20;                                 //mov al, 20h
    sub_2BCE5();                                //call sub_2BCE5
    _di += 0x01b0;                              //add di, 1B0h
    _dl = 0x05;                                 //mov dl, 5
    _al = 0x20;                                 //mov al, 20h
    sub_2BCE5();                                //call sub_2BCE5
    _dl = 0x0e;                                 //mov dl, 0Eh
    _al = 0x2d;                                 //mov al, 2Dh
    sub_2BCE5();                                //call sub_2BCE5
    _al = 0x20;                                 //mov al, 20h
    _dl = 0x05;                                 //mov dl, 5
    sub_2BCE5();                                //call sub_2BCE5
    _di += 0x01b0;                              //add di, 1B0h
    _dl = 0x18;                                 //mov dl, 18h
    _al = 0x20;                                 //mov al, 20h
    sub_2BCE5();                                //call sub_2BCE5
    _di += 0x01b0;                              //add di, 1B0h
    _dl = 0x0a;                                 //mov dl, 0Ah
    _si = 0x3e42;                               //mov si, 3E42h
loc_2FAD2:                                      //loc_2FAD2:
    _push(_dx);                                 //push dx
    _push(_si);                                 //push si
    _dl = 0x02;                                 //mov dl, 2
    _al = 0x20;                                 //mov al, 20h
    sub_2BCE5();                                //call sub_2BCE5
    _si = _pop();                               //pop si
    _dl = 0x0c;                                 //mov dl, 0Ch
    sub_2BCF1();                                //call sub_2BCF1
    _push(_si);                                 //push si
    _dl = 0x02;                                 //mov dl, 2
    _al = 0x20;                                 //mov al, 20h
    sub_2BCE5();                                //call sub_2BCE5
    _si = _pop();                               //pop si
    _dl = 0x06;                                 //mov dl, 6
    sub_2BCF1();                                //call sub_2BCF1
    _al = 0x20;                                 //mov al, 20h
    _dl = 0x02;                                 //mov dl, 2
    _push(_si);                                 //push si
    sub_2BCE5();                                //call sub_2BCE5
    _si = _pop();                               //pop si
    _di += 0x01b0;                              //add di, 1B0h
    _ax = 0xaaaa;                               //mov ax, 0AAAAh
    _cx = 0x18;                                 //mov cx, 18h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di -= 0x30;                                //sub di, 30h
    if (_di < 0x2000)                           //jb short loc_2FB13
      goto loc_2FB13;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2FB17;                             //jmp short loc_2FB17
loc_2FB13:                                      //loc_2FB13:
    _di += 0x2000;                              //add di, 2000h
loc_2FB17:                                      //loc_2FB17:
    _cx = 0x18;                                 //mov cx, 18h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di -= 0x30;                                //sub di, 30h
    if (_di < 0x2000)                           //jb short loc_2FB2B
      goto loc_2FB2B;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2FB2F;                             //jmp short loc_2FB2F
loc_2FB2B:                                      //loc_2FB2B:
    _di += 0x2000;                              //add di, 2000h
loc_2FB2F:                                      //loc_2FB2F:
    _dx = _pop();                               //pop dx
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2FAD2
      goto loc_2FAD2;
loc_2FB34:                                      //loc_2FB34:
    if (_di == 0x1e02)                          //jz short loc_2FB57
      goto loc_2FB57;
    _ax = 0xaaaa;                               //mov ax, 0AAAAh
    _cx = 0x18;                                 //mov cx, 18h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di -= 0x30;                                //sub di, 30h
    if (_di < 0x2000)                           //jb short loc_2FB51
      goto loc_2FB51;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2FB55;                             //jmp short loc_2FB55
loc_2FB51:                                      //loc_2FB51:
    _di += 0x2000;                              //add di, 2000h
loc_2FB55:                                      //loc_2FB55:
    goto loc_2FB34;                             //jmp short loc_2FB34
loc_2FB57:                                      //loc_2FB57:
    _dl = 0xff;                                 //mov dl, 0FFh
loc_2FB59:                                      //loc_2FB59:
    _cx = 0x0181;                               //mov cx, 181h
loc_2FB5C:                                      //loc_2FB5C:
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(0x16);                           //int 16h
    if (_flags.zero)                            //jz short loc_2FB68
      goto loc_2FB68;
    _ah = _ah ^ _ah;                            //xor ah, ah
    _interrupt(0x16);                           //int 16h
    _es = _pop();                               //pop es
    return;                                     //retn
loc_2FB68:                                      //loc_2FB68:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2FB5C
      goto loc_2FB5C;
    _push(_dx);                                 //push dx
    sub_2FB78();                                //call sub_2FB78
    _dx = _pop();                               //pop dx
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2FB59
      goto loc_2FB59;
    _es = _pop();                               //pop es
}

void sub_2FCB9()
{
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = _seg001;                              //mov ax, seg seg001
    _es = _ax;                                  //mov es, ax
    _ax = 0xb800;                               //mov ax, 0B800h
    _ds = _ax;                                  //mov ds, ax
    _flags.interrupt = false;                   //cli
    _di = 0x3df0;                               //mov di, 3DF0h
    _si = _si ^ _si;                            //xor si, si
    _cx = 0x0fa0;                               //mov cx, 0FA0h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _si = 0x2000;                               //mov si, 2000h
    _cx = 0x0fa0;                               //mov cx, 0FA0h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _flags.interrupt = true;                    //sti
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_2FCDC()
{
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _flags.interrupt = false;                   //cli
    _si = 0x3df0;                               //mov si, 3DF0h
    _di = _di ^ _di;                            //xor di, di
    _cx = 0x0fa0;                               //mov cx, 0FA0h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _di = 0x2000;                               //mov di, 2000h
    _cx = 0x0fa0;                               //mov cx, 0FA0h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _flags.interrupt = true;                    //sti
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
}

void sub_2FCFF()
{
    if (memory(_ds, 0x13C4) != 2)               //jnz short loc_2FD2A
      goto loc_2FD2A;
    memory(_ds, 0x13C4) = 0x80;                 //mov byte ptr ds:13C4h, 80h
    memory16(_ds, 0x13C5) += 1;                 //inc word ptr ds:13C5h
    _si = memory16(_ds, 0x13C5);                //mov si, ds:13C5h
    _al = memory(_ds, _si);                     //mov al, [si]
    _al = _al ^ 0xaa;                           //xor al, 0AAh
    _al -= 0x20;                                //sub al, 20h
    _cl = 0x06;                                 //mov cl, 6
    _ax = _cl * _al;                            //mul cl
    _ax += 0xa3c0;                              //add ax, 0A3C0h
    _si = _ax;                                  //mov si, ax
    _di = 0x0000;                               //mov di, 0
    _cx = 0x0003;                               //mov cx, 3
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
loc_2FD2A:                                      //loc_2FD2A:
    _push(_es);                                 //push es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    sub_2FD60();                                //call sub_2FD60
    _si = 0x0000;                               //mov si, 0
    _di = 0x38a9;                               //mov di, 38A9h
    _cl = 0x06;                                 //mov cl, 6
loc_2FD3B:                                      //loc_2FD3B:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _al = _al & memory(_ds, 0x13C4);            //and al, ds:13C4h
    if (_al == 0)                               //jz short loc_2FD46
      goto loc_2FD46;
    memoryVideoXor(_es, _di, 3);    //xor byte ptr es:[di], 3
loc_2FD46:                                      //loc_2FD46:
    if (_di < 0x2000)                           //jb short loc_2FD52
      goto loc_2FD52;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2FD56;                             //jmp short loc_2FD56
loc_2FD52:                                      //loc_2FD52:
    _di += 0x2000;                              //add di, 2000h
loc_2FD56:                                      //loc_2FD56:
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2FD3B
      goto loc_2FD3B;
    memory(_ds, 0x13C4) >>= 1;                  //shr byte ptr ds:13C4h, 1
    _es = _pop();                               //pop es
}

void sub_2FD91()
{
    _push(_ax);                                 //push ax
    _bx = memory16(_ds, 0x3F1C);                //mov bx, ds:3F1Ch
    _bl = memory(_ds, _bx);                     //mov bl, [bx]
    if (_al != _bl)                             //jnz short loc_2FDAE
      goto loc_2FDAE;
    if (_bl != 0x0d)                            //jnz short loc_2FDA8
      goto loc_2FDA8;
    memory(_ds, 0x3F1B) = 1;                    //mov byte ptr ds:3F1Bh, 1
    _ax = _pop();                               //pop ax
    return;                                     //retn
loc_2FDA8:                                      //loc_2FDA8:
    memory16(_ds, 0x3F1C) += 1;                 //inc word ptr ds:3F1Ch
    _ax = _pop();                               //pop ax
    return;                                     //retn
loc_2FDAE:                                      //loc_2FDAE:
    memory16(_ds, 0x3F1C) = 16139;              //mov word ptr ds:3F1Ch, 3F0Bh
    _ax = _pop();                               //pop ax
}

void sub_2FDB6()
{
    memory(_ds, 0x13C8) += 0x10;                //add byte ptr ds:13C8h, 10h
    if (memory(_ds, 0x13C8) != 0)               //jnz short loc_2FDCE
      goto loc_2FDCE;
    memory(_ds, 0x13C7) = memory(_ds, 0x13C7) ^ 4;//xor byte ptr ds:13C7h, 4
    _al = memory(_ds, 0x13C7);                  //mov al, ds:13C7h
    _dx = 0x03d8;                               //mov dx, 3D8h
    _out(_dx, _al);                             //out dx, al
loc_2FDCE:                                      //loc_2FDCE:
    _al = memory(_ds, 0x13C8);                  //mov al, ds:13C8h
    _dx = 0x03d9;                               //mov dx, 3D9h
    _out(_dx, _al);                             //out dx, al
}

void sub_2FFE2() // point shower
{
    int temp = 0;
    _si = 0x148d;                               //mov si, 148Dh
    _cx = memory16(_ds, 0x1413);                //mov cx, ds:1413h
    
    //_cx = 1; // gabo
loc_2FFE9: //loc_2FFE9:
//    if (_si==0x148d)
//        std::cout << "point " << std::dec << (int)((_si - 0x148d)/16) << " x=" << (int) memory16(_ds, _si)
//            << " y= " << std::dec << (int) memory16(_ds, _si+8) << "\n";
        
//    std::cout << "point " << std::dec << (int)((_si - 0x148d)/16) << " x=" << (int) memory16(_ds, _si)
//    << " y= " << std::dec << (int) memory16(_ds, _si+8) << " v="
//    << (int) memory16(_ds, _si+4) << ", " << (int) memory16(_ds, _si+6) << ", "
//    << (int) memory16(_ds, _si+2) << ", " << (int) memory16(_ds, _si+10) << ",\n";
    temp ++;
    _bp = _cx;                                  //mov bp, cx
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _ax = _ax + memory16(_ds, _si + 4);         //add ax, [si+4]
    _ax = _ax - memory16(_ds, _si + 6);         //sub ax, [si+6]
    if (_ax > 0x013f)                           //ja short loc_3000F
      goto loc_3000F;
    _cx = _ax;                                  //mov cx, ax
    _ax = memory16(_ds, _si + 8);               //mov ax, [si+8]
    _ax = _ax + memory16(_ds, _si + 2);         //add ax, [si+2]
    _ax = _ax - memory16(_ds, _si + 10);        //sub ax, [si+0Ah]
    if (_ax > 0xc7)                             //ja short loc_3000F
      goto loc_3000F;
    _dx = _ax;                                  //mov dx, ax
    // cx = x, dx=y
    //_cx += temp; // gabo
    _ax = 0x0c83;                               //mov ax, 0C83h
    _interrupt(0x10);                           //int 10h
loc_3000F:                                      //loc_3000F:
    _dx = _dx ^ _dx;                            //xor dx, dx
    _ax = memory16(_ds, _si + 12);              //mov ax, [si+0Ch]
    memory16(_ds, _si + 6) += _ax;              //add [si+6], ax
    _cx = memory16(_ds, _si + 6);               //mov cx, [si+6]
    _ax = memory16(_ds, _si + 14);              //mov ax, [si+0Eh]
    _ax = (short)_cx * (char)_al;                            //imul cx
    _ax = (short)_cx * (char)_al;                            //imul cx
    _cx = 0x64;                                 //mov cx, 64h
    _idiv(_cx);                                 //idiv cx
    memory16(_ds, _si + 8) = _ax;               //mov [si+8], ax
    _ax = _ax + memory16(_ds, _si + 2);         //add ax, [si+2]
    _ax = _ax - memory16(_ds, _si + 10);        //sub ax, [si+0Ah]
    if (_ax > 0xc7)                             //ja short loc_3004A
      goto loc_3004A;
    _dx = _ax;                                  //mov dx, ax
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _ax = _ax + memory16(_ds, _si + 4);         //add ax, [si+4]
    _ax = _ax - memory16(_ds, _si + 6);         //sub ax, [si+6]
    if (_ax > 0x013f)                           //ja short loc_3004A
      goto loc_3004A;
    _cx = _ax;                                  //mov cx, ax
    //_dx -= temp; // gabo
    _ax = 0x0c83;                               //mov ax, 0C83h
    _interrupt(0x10);                           //int 10h
loc_3004A:                                      //loc_3004A:
    _ax = memory16(_ds, _si + 8);               //mov ax, [si+8]
    _ax = _ax + memory16(_ds, _si + 2);         //add ax, [si+2]
    _ax = _ax - memory16(_ds, _si + 10);        //sub ax, [si+0Ah]
    if (_ax > 0xc7)                             //ja short loc_30063
      goto loc_30063;
loc_30058:                                      //loc_30058:
    _si += 0x10;                                //add si, 10h
    _cx = _bp;                                  //mov cx, bp
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2FFE9
      goto loc_2FFE9;
    _sync();
    return;                                     //retn
loc_30063:                                      //loc_30063:
    sub_300AA();                                //call sub_300AA
    goto loc_30058;                             //jmp short loc_30058
}

void sub_30096() // shower point innit
{
    _si = 0x148d;                               //mov si, 148Dh
    _cx = memory16(_ds, 0x1413);                //mov cx, ds:1413h
loc_3009D:                                      //loc_3009D:
    _bp = _cx;                                  //mov bp, cx
    sub_300AA();                                //call sub_300AA
    _si += 0x10;                                //add si, 10h
    _cx = _bp;                                  //mov cx, bp
    if (--_cx)                                  //loop loc_3009D
      goto loc_3009D;
}

void sub_300F6()
{
    _push(_ds);                                 //push ds
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _flags.direction = true;                    //std
    _si = 0x7c6e;                               //mov si, 7C6Eh
    _di = 0x3f3f;                               //mov di, 3F3Fh
    _cx = 0x5b;                                 //mov cx, 5Bh
loc_3010B:                                      //loc_3010B:
    _bp = _cx;                                  //mov bp, cx
    _bx = _di;                                  //mov bx, di
    _cx = 0x0c;                                 //mov cx, 0Ch
    _rep_movsw<MemAuto, MemAuto, DirBackward>();    //rep movsw
    _di = _bx;                                  //mov di, bx
    if (_di > 0x2000)                           //ja short loc_30122
      goto loc_30122;
    _di += 0x1fb0;                              //add di, 1FB0h
    goto loc_30126;                             //jmp short loc_30126
loc_30122:                                      //loc_30122:
    _di -= 0x2000;                              //sub di, 2000h
loc_30126:                                      //loc_30126:
    _bx = _di;                                  //mov bx, di
    _ax = 0xffff;                               //mov ax, 0FFFFh
    _cx = 0x0a;                                 //mov cx, 0Ah
    _di -= 0x0004;                              //sub di, 4
    _rep_stosw<MemAuto, DirBackward>();             //rep stosw
    _di = _bx;                                  //mov di, bx
    _cx = 0x32;                                 //mov cx, 32h
loc_30138:                                      //loc_30138:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_30138
      goto loc_30138;
    _cx = _bp;                                  //mov cx, bp
    if (--_cx)                                  //loop loc_3010B
      goto loc_3010B;
    _si = 0x7c6e;                               //mov si, 7C6Eh
    _di = 0x3f3f;                               //mov di, 3F3Fh
    _cx = 0x5a;                                 //mov cx, 5Ah
loc_3014A:                                      //loc_3014A:
    _bp = _cx;                                  //mov bp, cx
    _bx = _di;                                  //mov bx, di
    _cx = 0x0c;                                 //mov cx, 0Ch
    _rep_movsw<MemAuto, MemAuto, DirBackward>();    //rep movsw
    _di = _bx;                                  //mov di, bx
    if (_di > 0x2000)                           //ja short loc_30161
      goto loc_30161;
    _di += 0x1fb0;                              //add di, 1FB0h
    goto loc_30165;                             //jmp short loc_30165
loc_30161:                                      //loc_30161:
    _di -= 0x2000;                              //sub di, 2000h
loc_30165:                                      //loc_30165:
    _bx = _di;                                  //mov bx, di
    _ax = 0xffff;                               //mov ax, 0FFFFh
    _cx = 0x0a;                                 //mov cx, 0Ah
    _di -= 0x0004;                              //sub di, 4
loc_30170:                                      //loc_30170:
    memoryVideoXor(_es, _di, _ax);//xor es:[di], ax
    _di -= 1;                                   //dec di
    _di -= 1;                                   //dec di
    if (--_cx)                                  //loop loc_30170
      goto loc_30170;
    _di = _bx;                                  //mov di, bx
    _cx = 0x32;                                 //mov cx, 32h
loc_3017C:                                      //loc_3017C:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_3017C
      goto loc_3017C;
    _cx = _bp;                                  //mov cx, bp
    if (--_cx)                                  //loop loc_3014A
      goto loc_3014A;
    _flags.direction = false;                   //cld
    _si = 0x6b60;                               //mov si, 6B60h
    _di = 0x3119;                               //mov di, 3119h
    _cx = 0x5b;                                 //mov cx, 5Bh
loc_3018F:                                      //loc_3018F:
    _bp = _cx;                                  //mov bp, cx
    _bx = _di;                                  //mov bx, di
    _cx = 0x0c;                                 //mov cx, 0Ch
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _di = _bx;                                  //mov di, bx
    if (_di > 0x2000)                           //ja short loc_301A6
      goto loc_301A6;
    _di += 0x2000;                              //add di, 2000h
    goto loc_301AA;                             //jmp short loc_301AA
loc_301A6:                                      //loc_301A6:
    _di -= 0x1fb0;                              //sub di, 1FB0h
loc_301AA:                                      //loc_301AA:
    _bx = _di;                                  //mov bx, di
    _ax = 0xffff;                               //mov ax, 0FFFFh
    _cx = 0x0a;                                 //mov cx, 0Ah
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di = _bx;                                  //mov di, bx
    _cx = 0x32;                                 //mov cx, 32h
loc_301B9:                                      //loc_301B9:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_301B9
      goto loc_301B9;
    _cx = _bp;                                  //mov cx, bp
    if (--_cx)                                  //loop loc_3018F
      goto loc_3018F;
    _si = 0x6b60;                               //mov si, 6B60h
    _di = 0x1119;                               //mov di, 1119h
    _cx = 0x5c;                                 //mov cx, 5Ch
loc_301CB:                                      //loc_301CB:
    _bp = _cx;                                  //mov bp, cx
    _bx = _di;                                  //mov bx, di
    _cx = 0x0c;                                 //mov cx, 0Ch
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _di = _bx;                                  //mov di, bx
    if (_di > 0x2000)                           //ja short loc_301E2
      goto loc_301E2;
    _di += 0x2000;                              //add di, 2000h
    goto loc_301E6;                             //jmp short loc_301E6
loc_301E2:                                      //loc_301E2:
    _di -= 0x1fb0;                              //sub di, 1FB0h
loc_301E6:                                      //loc_301E6:
    _bx = _di;                                  //mov bx, di
    _ax = 0xffff;                               //mov ax, 0FFFFh
    _cx = 0x0a;                                 //mov cx, 0Ah
loc_301EE:                                      //loc_301EE:
    memoryVideoXor(_es, _di, _ax);//xor es:[di], ax
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_301EE
      goto loc_301EE;
    _di = _bx;                                  //mov di, bx
    _cx = 0x32;                                 //mov cx, 32h
loc_301FA:                                      //loc_301FA:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_301FA
      goto loc_301FA;
    _cx = _bp;                                  //mov cx, bp
    if (--_cx)                                  //loop loc_301CB
      goto loc_301CB;
    _ds = _pop();                               //pop ds
}

void sub_30205()
{
    _dl = 0x34;                                 //mov dl, 34h
    _di = 0x0230;                               //mov di, 230h
loc_3020A:                                      //loc_3020A:
    _bx = _di;                                  //mov bx, di
    _al = 0xc0;                                 //mov al, 0C0h
    _dh = 0x04;                                 //mov dh, 4
loc_30210:                                      //loc_30210:
    _al &= 0x55;                                //and al, 55h
    _bp = _di;                                  //mov bp, di
    _cl = 0x07;                                 //mov cl, 7
loc_30216:                                      //loc_30216:
    memoryVideoSet(_es, _di, _al);                     //mov es:[di], al
    _di += 0x0370;                              //add di, 370h
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_30216
      goto loc_30216;
    _cx = 0x19;                                 //mov cx, 19h
loc_30224:                                      //loc_30224:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_30224
      goto loc_30224;
    _flags.carry = true;                        //stc
    _rcr(_al, 1); //rcr al, 1
    _flags.carry = true;                        //stc
    _rcr(_al, 1); //rcr al, 1
    _di = _bp;                                  //mov di, bp
    _dh -= 1;                                   //dec dh
    if (_dh != 0)                               //jnz short loc_30210
      goto loc_30210;
    _di = _bx;                                  //mov di, bx
    _di += 1;                                   //inc di
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_3020A
      goto loc_3020A;
    _push(_ds);                                 //push ds
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _si = 0x4db7;                               //mov si, 4DB7h
    _bp = 0xa0;                                 //mov bp, 0A0h
    _dh = 0x07;                                 //mov dh, 7
loc_3024A:                                      //loc_3024A:
    _push(_si);                                 //push si
    _bx = 0x0001;                               //mov bx, 1
loc_3024E:                                      //loc_3024E:
    _push(_si);                                 //push si
    _di = _bp;                                  //mov di, bp
    _push(_dx);                                 //push dx
    _dx = 0x03da;                               //mov dx, 3DAh
loc_30255:                                      //loc_30255:
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x08))                          //jz short loc_30255
      goto loc_30255;
loc_3025A:                                      //loc_3025A:
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x08)                             //jnz short loc_3025A
      goto loc_3025A;
    _dx = _pop();                               //pop dx
    _dl = 0x15;                                 //mov dl, 15h
loc_30262:                                      //loc_30262:
    _cx = _bx;                                  //mov cx, bx
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _si -= _bx;                                 //sub si, bx
    _si += 0x34;                                //add si, 34h
    _di -= _bx;                                 //sub di, bx
    if (_di < 0x2000)                           //jb short loc_30279
      goto loc_30279;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_3027D;                             //jmp short loc_3027D
loc_30279:                                      //loc_30279:
    _di += 0x2000;                              //add di, 2000h
loc_3027D:                                      //loc_3027D:
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_30262
      goto loc_30262;
    _si = _pop();                               //pop si
    _si -= 1;                                   //dec si
    _cx = 0x0a;                                 //mov cx, 0Ah
loc_30286:                                      //loc_30286:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_30286
      goto loc_30286;
    _bx += 1;                                   //inc bx
    if (_bx != 0x35)                            //jnz short loc_3024E
      goto loc_3024E;
    _si = _pop();                               //pop si
    _si += 0x0444;                              //add si, 444h
    _bp += 0x0370;                              //add bp, 370h
    _dh -= 1;                                   //dec dh
    if (_dh != 0)                               //jnz short loc_3024A
      goto loc_3024A;
    _ds = _pop();                               //pop ds
}

void sub_302A0()
{
    WORD _cs = _seg004;
    _push(_es);                                 //push es
    _ax = 0x3568;                               //mov ax, 3568h
    _interrupt(0x21);                           //int 21h
    if (_bx == 0x0001)                          //jz short loc_302B4
      goto loc_302B4;
    _bx |= _bx;                                 //or bx, bx
    if (_bx != 0)                               //jnz short loc_302BA
      goto loc_302BA;
    _bx = 0x6f;                                 //mov bx, 6Fh
    goto loc_302BA;                             //jmp short loc_302BA
loc_302B4:                                      //loc_302B4:
    memory(_cs, 0x2C26C) = 0xc3;                //mov byte ptr cs:sub_2C26C, 0C3h
loc_302BA:                                      //loc_302BA:
    _bx -= 1;                                   //dec bx
    memory16(_cs, 0x164E) = _bx;                //mov word ptr cs:loc_2C26D+1, bx
    _es = _pop();                               //pop es
}

void sub_30560()
{
    _dl = 0x32;                                 //mov dl, 32h
loc_30562:                                      //loc_30562:
    _cx = 0xc8;                                 //mov cx, 0C8h
loc_30565:                                      //loc_30565:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_30565
      goto loc_30565;
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_30562
      goto loc_30562;
    _di = 0x2f18;                               //mov di, 2F18h
    _ax = _ax ^ _ax;                            //xor ax, ax
    _cx = 0x54;                                 //mov cx, 54h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    sub_2CAD9();                                //call sub_2CAD9
    _push(_es);                                 //push es
    _push(_ds);                                 //push ds
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _bh = 0x01;                                 //mov bh, 1
    _bp = 0x3ef2;                               //mov bp, 3EF2h
loc_3058C:                                      //loc_3058C:
    _bl = _bh;                                  //mov bl, bh
    _di = _bp;                                  //mov di, bp
    _si = 0x7c70;                               //mov si, 7C70h
    _dx = 0x03da;                               //mov dx, 3DAh
loc_30596:                                      //loc_30596:
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x08))                          //jz short loc_30596
      goto loc_30596;
loc_3059B:                                      //loc_3059B:
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x08)                             //jnz short loc_3059B
      goto loc_3059B;
loc_305A0:                                      //loc_305A0:
    _cx = 0x0d;                                 //mov cx, 0Dh
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _di -= 0x1a;                                //sub di, 1Ah
    if (_di < 0x2000)                           //jb short loc_305B4
      goto loc_305B4;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_305B8;                             //jmp short loc_305B8
loc_305B4:                                      //loc_305B4:
    _di += 0x2000;                              //add di, 2000h
loc_305B8:                                      //loc_305B8:
    _bl -= 1;                                   //dec bl
    if (_bl != 0)                               //jnz short loc_305A0
      goto loc_305A0;
    if (_bp < 0x2000)                           //jb short loc_305C8
      goto loc_305C8;
    _bp -= 0x2000;                              //sub bp, 2000h
    goto loc_305CC;                             //jmp short loc_305CC
loc_305C8:                                      //loc_305C8:
    _bp += 0x1fb0;                              //add bp, 1FB0h
loc_305CC:                                      //loc_305CC:
    _cx = 0x0005;                               //mov cx, 5
loc_305CF:                                      //loc_305CF:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_305CF
      goto loc_305CF;
    _bh += 1;                                   //inc bh
    if (_bh != 0x5c)                            //jnz short loc_3058C
      goto loc_3058C;
    _si = 0x2825;                               //mov si, 2825h
    _bh = _bh ^ _bh;                            //xor bh, bh
loc_305E0:                                      //loc_305E0:
    _bl = 0x05;                                 //mov bl, 5
loc_305E2:                                      //loc_305E2:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz short loc_305F1
      goto loc_305F1;
    _push(_bx);                                 //push bx
    _push(_si);                                 //push si
    sub_307A0();                                //call sub_307A0
    _si = _pop();                               //pop si
    _bx = _pop();                               //pop bx
    sub_307D5();                                //call sub_307D5
loc_305F1:                                      //loc_305F1:
    _bl -= 1;                                   //dec bl
    if (_bl != 0)                               //jnz short loc_305E2
      goto loc_305E2;
    _bh += 1;                                   //inc bh
    if (_bh != 0x18)                            //jnz short loc_305E0
      goto loc_305E0;
    _ds = _pop();                               //pop ds
    sub_2AFF1();                                //call sub_2AFF1
    sub_30663();                                //call sub_30663
loc_30603:                                      //loc_30603:
    sub_30676();                                //call sub_30676
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(0x16);                           //int 16h
    if (_flags.zero)                            //jz short loc_30613
      goto loc_30613;
    _ah = _ah ^ _ah;                            //xor ah, ah
    _interrupt(0x16);                           //int 16h
    goto loc_30615;                             //jmp loc_30615
loc_30613:                                      //loc_30613:
    goto loc_30603;                             //jmp short loc_30603
loc_30615:                                      //loc_30615:
    _es = _pop();                               //pop es
}

void sub_2ACB7()
{
    WORD _cs = _seg004;
    _push(_ds);                                 //push ds
    _ax = _seg004;                              //mov ax, seg seg004
    _ds = _ax;                                  //mov ds, ax
    _al = memory(_ds, 0xF4);                    //mov al, byte_2AD14
    _al |= _al;                                 //or al, al
    if (_al != 0)                               //jnz short loc_2ACE7
      goto loc_2ACE7;
    memory(_ds, 0xF5) -= 1;                     //dec byte_2AD15
    if (memory(_ds, 0xF5) != 0)                 //jnz short loc_2ACE5
      goto loc_2ACE5;
loc_2ACCA:                                      //loc_2ACCA:
    _si = memory16(_ds, 0xF6);                  //mov si, word_2AD16
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_2AD0A
      goto loc_2AD0A;
    memory16(_ds, 0xF6) = _si;                  //mov word_2AD16, si
    memory(_ds, 0xF5) = _ah;                    //mov byte_2AD15, ah
    _ah = _al;                                  //mov ah, al
    _al = 0x01;                                 //mov al, 1
    _out(0x42, _al);                            //out 42h, al
    _al = _ah;                                  //mov al, ah
    _out(0x42, _al);                            //out 42h, al
loc_2ACE5:                                      //loc_2ACE5:
    _ds = _pop();                               //pop ds
    return;                                     //retn
loc_2ACE7:                                      //loc_2ACE7:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _al -= 1;                                   //dec al
    memory(_ds, 0xF4) = _ah;                    //mov ds:0F4h, ah
    if (memory(_cs, 0x84) == 0)                 //jz short loc_2ACE5
      goto loc_2ACE5;
    _ax <<= 1;                                  //shl ax, 1
    _ax += 0xf8;                                //add ax, 0F8h
    _si = _ax;                                  //mov si, ax
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_ds, 0xF6) = _ax;                  //mov ds:0F6h, ax
    _in(_al, 0x61);                             //in al, 61h
    _al |= 0x03;                                //or al, 3
    _out(0x61, _al);                            //out 61h, al
    goto loc_2ACCA;                             //jmp short loc_2ACCA
loc_2AD0A:                                      //loc_2AD0A:
    _in(_al, 0x61);                             //in al, 61h
    _al &= 0xfc;                                //and al, 0FCh
    _out(0x61, _al);                            //out 61h, al
    _al = 0xff;                                 //mov al, 0FFh
    goto loc_2ACE5;                             //jmp short loc_2ACE5
}

void sub_2B17E()
{
    _bx = memory16(_ds, 0x3144);                //mov bx, ds:3144h
loc_2B182:                                      //loc_2B182:
    if (_bx == 0xffff)                          //jz short loc_2B1B1
      goto loc_2B1B1;
    _push(_bx);                                 //push bx
    if (memory16(_ds, _bx) != 14070)            //jnz short loc_2B195
      goto loc_2B195;
    sub_2E31B();                                //call sub_2E31B
    goto loc_2B19E;                             //jmp loc_2B19E
loc_2B195:                                      //loc_2B195:
    if (memory16(_ds, _bx) != 13918)            //jnz short loc_2B19E
      goto loc_2B19E;
    sub_2E288();                                //call sub_2E288
loc_2B19E:                                      //loc_2B19E:
    _bx = _pop();                               //pop bx
    _cx = memory16(_ds, 0x3138);                //mov cx, ds:3138h
    _dx = memory16(_ds, _bx + 12);              //mov dx, [bx+0Ch]
    memory16(_ds, _bx + 12) = _cx;              //mov [bx+0Ch], cx
    memory16(_ds, 0x3138) = _bx;                //mov ds:3138h, bx
    _bx = _dx;                                  //mov bx, dx
    goto loc_2B182;                             //jmp short loc_2B182
loc_2B1B1:                                      //loc_2B1B1:
    memory16(_ds, 0x3144) = 0xffff;             //mov word ptr ds:3144h, 0FFFFh
}

void sub_2B218()
{
    _si = 0x33d7;                               //mov si, 33D7h
    _cl = 0x04;                                 //mov cl, 4
loc_2B21D:                                      //loc_2B21D:
    _push(_cx);                                 //push cx
    _push(_si);                                 //push si
    _cl = memory(_ds, _si);                     //mov cl, [si]
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    memory(_ds, _si + 3) = 0;                   //mov byte ptr [si+3], 0
    _al -= 0x0a;                                //sub al, 0Ah
    _si = 0x6078;                               //mov si, 6078h
    _flags.interrupt = false;                   //cli
    _push(_es);                                 //push es
    _dx = 0xb800;                               //mov dx, 0B800h
    _es = _dx;                                  //mov es, dx
    _ch = _ch ^ _ch;                            //xor ch, ch
    _di = _cx;                                  //mov di, cx
    _di >>= 1;                                  //shr di, 1
    _di >>= 1;                                  //shr di, 1
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (!_flags.carry)                          //jnb short loc_2B244
      goto loc_2B244;
    _di += 0x2000;                              //add di, 2000h
loc_2B244:                                      //loc_2B244:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cl = 0x04;                                 //mov cl, 4
    _ax <<= _cl;                                //shl ax, cl
    _di += _ax;                                 //add di, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _dh = 0x25;                                 //mov dh, 25h
loc_2B254:                                      //loc_2B254:
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    if (_di < 0x2000)                           //jb short loc_2B264
      goto loc_2B264;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2B268;                             //jmp short loc_2B268
loc_2B264:                                      //loc_2B264:
    _di += 0x2000;                              //add di, 2000h
loc_2B268:                                      //loc_2B268:
    _dh -= 1;                                   //dec dh
    if (_dh != 0)                               //jnz short loc_2B254
      goto loc_2B254;
    _es = _pop();                               //pop es
    _flags.interrupt = true;                    //sti
    _si = _pop();                               //pop si
    _si += 0x0004;                              //add si, 4
    _cx = _pop();                               //pop cx
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2B21D
      goto loc_2B21D;
    _push(_es);                                 //push es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _ax = 0x0000;                               //mov ax, 0
    _di = 0xa2;                                 //mov di, 0A2h
    _cx = 0x18;                                 //mov cx, 18h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di = 0x20a2;                               //mov di, 20A2h
    _cx = 0x18;                                 //mov cx, 18h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _es = _pop();                               //pop es
    _di = 0x2f18;                               //mov di, 2F18h
    _al = 0x06;                                 //mov al, 6
    _ah = 0x0e;                                 //mov ah, 0Eh
    _push(_es);                                 //push es
    _dx = 0xb800;                               //mov dx, 0B800h
    _es = _dx;                                  //mov es, dx
loc_2B29E:                                      //loc_2B29E:
    _ch = 0x0c;                                 //mov ch, 0Ch
    _cl = 0x08;                                 //mov cl, 8
loc_2B2A2:                                      //loc_2B2A2:
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _bp = _di;                                  //mov bp, di
    _si = 0x3080;                               //mov si, 3080h
    _dh = _dh ^ _dh;                            //xor dh, dh
    _dl = memory(_ds, _di);                     //mov dl, [di]
    if (_dl != 0x0c)                            //jnz short loc_2B2B8
      goto loc_2B2B8;
    sub_2F8E1();                                //call sub_2F8E1
    goto loc_2B314;                             //jmp loc_2B314
loc_2B2B8:                                      //loc_2B2B8:
    if (_dl == 0x04)                            //jz short loc_2B313
      goto loc_2B313;
    _dx <<= 1;                                  //shl dx, 1
    _si += _dx;                                 //add si, dx
    _si = memory16(_ds, _si);                   //mov si, [si]
    if (_dl < 0x30)                             //jb short loc_2B2CE
      goto loc_2B2CE;
    _push(_ds);                                 //push ds
    _di = _seg002;                              //mov di, seg seg002
    _ds = _di;                                  //mov ds, di
loc_2B2CE:                                      //loc_2B2CE:
    _flags.interrupt = false;                   //cli
    _ch = _ch ^ _ch;                            //xor ch, ch
    _di = _cx;                                  //mov di, cx
    _di >>= 1;                                  //shr di, 1
    _di >>= 1;                                  //shr di, 1
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (!_flags.carry)                          //jnb short loc_2B2DF
      goto loc_2B2DF;
    _di += 0x2000;                              //add di, 2000h
loc_2B2DF:                                      //loc_2B2DF:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cl = 0x04;                                 //mov cl, 4
    _ax <<= _cl;                                //shl ax, cl
    _di += _ax;                                 //add di, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _cx = 0x0008;                               //mov cx, 8
loc_2B2F0:                                      //loc_2B2F0:
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memoryVideoSet16(_es, _di + 2, _ax);               //mov es:[di+2], ax
    if (_di < 0x2000)                           //jb short loc_2B307
      goto loc_2B307;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    if (--_cx)                                  //loop loc_2B2F0
      goto loc_2B2F0;
    goto loc_2B30D;                             //jmp short loc_2B30D
loc_2B307:                                      //loc_2B307:
    _di += 0x2000;                              //add di, 2000h
    if (--_cx)                                  //loop loc_2B2F0
      goto loc_2B2F0;
loc_2B30D:                                      //loc_2B30D:
    if (_dl < 0x30)                             //jb short loc_2B313
      goto loc_2B313;
    _ds = _pop();                               //pop ds
loc_2B313:                                      //loc_2B313:
    _flags.interrupt = true;                    //sti
loc_2B314:                                      //loc_2B314:
    _di = _bp;                                  //mov di, bp
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
    _di += 1;                                   //inc di
    _cl += 0x10;                                //add cl, 10h
    _ch -= 1;                                   //dec ch
    if (_ch == 0)                               //jz short loc_2B322
      goto loc_2B322;
    goto loc_2B2A2;                             //jmp short loc_2B2A2
loc_2B322:                                      //loc_2B322:
    _al += 0x08;                                //add al, 8
    _ah -= 1;                                   //dec ah
    if (_ah == 0)                               //jz short loc_2B32B
      goto loc_2B32B;
    goto loc_2B29E;                             //jmp loc_2B29E
loc_2B32B:                                      //loc_2B32B:
    _di = 0xb800;                               //mov di, 0B800h
    _es = _di;                                  //mov es, di
    _di = 0x1272;                               //mov di, 1272h
    _ax = 0x0000;                               //mov ax, 0
    _dl = 0x29;                                 //mov dl, 29h
loc_2B338:                                      //loc_2B338:
    _bp = _di;                                  //mov bp, di
    _cx = 0x18;                                 //mov cx, 18h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di = _bp;                                  //mov di, bp
    _di += 0x2000;                              //add di, 2000h
    _cx = 0x18;                                 //mov cx, 18h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di = _bp;                                  //mov di, bp
    _di += 0x50;                                //add di, 50h
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2B338
      goto loc_2B338;
    _es = _pop();                               //pop es
    //sub_2B355();
    // PARSER:keep assert!!
    return;                                     //retn
    _STOP_("sp-trace-fail");                    //sub_2B218 endp_failed
    _STOP_("continues");                        //sub_2B355 proc near
}

void sub_2B531()
{
    _bp = _es;                                  //mov bp, es
    _dx = 0xb800;                               //mov dx, 0B800h
    _es = _dx;                                  //mov es, dx
    _di = 0x0000;                               //mov di, 0
    _cx = 0x64;                                 //mov cx, 64h
loc_2B53E:                                      //loc_2B53E:
    memoryVideoSet16(_es, _di, 20493);                 //mov word ptr es:[di], 500Dh
    memoryVideoSet16(_es, _di + 0x32, 20493);            //mov word ptr es:[di+32h], 500Dh
    _di += 0x50;                                //add di, 50h
    if (--_cx)                                  //loop loc_2B53E
      goto loc_2B53E;
    _cx = 0x32;                                 //mov cx, 32h
    _di = 0x2000;                               //mov di, 2000h
loc_2B554:                                      //loc_2B554:
    memoryVideoSet16(_es, _di, 20493);                 //mov word ptr es:[di], 500Dh
    // PARSER memory???
    memoryVideoSet16(_es, _di + 0x32, 20493);            //mov word ptr es:[di+32h], 500Dh
    memoryVideoSet16(_es, _di + 0x50, 4109);             //mov word ptr es:[di+50h], 100Dh
    memoryVideoSet16(_es, _di + 0x82, 4109);             //mov word ptr es:[di+82h], 100Dh
    _di += 0xa0;                                //add di, 0A0h
    if (--_cx)                                  //loop loc_2B554
      goto loc_2B554;
    _di = 0x0000;                               //mov di, 0
    _cx = 0x19;                                 //mov cx, 19h
    _ax = 0xffff;                               //mov ax, 0FFFFh
loc_2B57B:                                      //loc_2B57B:
    _stosw<MemAuto, DirAuto>();                 //stosw
    if (--_cx)                                  //loop loc_2B57B
      goto loc_2B57B;
    _di = 0x50;                                 //mov di, 50h
    _cx = 0x19;                                 //mov cx, 19h
    _ax = 0x1515;                               //mov ax, 1515h
loc_2B587:                                      //loc_2B587:
    _stosw<MemAuto, DirAuto>();                 //stosw
    if (--_cx)                                  //loop loc_2B587
      goto loc_2B587;
    _di = 0x2000;                               //mov di, 2000h
    _cx = 0x32;                                 //mov cx, 32h
loc_2B590:                                      //loc_2B590:
    memoryVideoSet(_es, _di, 0x55);                    //mov byte ptr es:[di], 55h
    memoryVideoSet(_es, _di + 80, 0x55);               //mov byte ptr es:[di+50h], 55h
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_2B590
      goto loc_2B590;
    _di = 0x0000;                               //mov di, 0
    _si = 0x48d2;                               //mov si, 48D2h
    _al = 0x07;                                 //mov al, 7
loc_2B5A4:                                      //loc_2B5A4:
    _push(_di);                                 //push di
    _cx = 0x0003;                               //mov cx, 3
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di = _pop();                               //pop di
    if (_di < 0x2000)                           //jb short loc_2B5B7
      goto loc_2B5B7;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2B5BB;                             //jmp short loc_2B5BB
loc_2B5B7:                                      //loc_2B5B7:
    _di += 0x2000;                              //add di, 2000h
loc_2B5BB:                                      //loc_2B5BB:
    _al -= 1;                                   //dec al
    if (_al != 0)                               //jnz short loc_2B5A4
      goto loc_2B5A4;
    _di = 0x31;                                 //mov di, 31h
    _si = 0x48bd;                               //mov si, 48BDh
    _al = 0x07;                                 //mov al, 7
loc_2B5C7:                                      //loc_2B5C7:
    _push(_di);                                 //push di
    _cx = 0x0003;                               //mov cx, 3
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di = _pop();                               //pop di
    if (_di < 0x2000)                           //jb short loc_2B5DA
      goto loc_2B5DA;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2B5DE;                             //jmp short loc_2B5DE
loc_2B5DA:                                      //loc_2B5DA:
    _di += 0x2000;                              //add di, 2000h
loc_2B5DE:                                      //loc_2B5DE:
    _al -= 1;                                   //dec al
    if (_al != 0)                               //jnz short loc_2B5C7
      goto loc_2B5C7;
    _es = _bp;                                  //mov es, bp
}

void sub_2B5E5()
{
    _bp = _es;                                  //mov bp, es
    _dx = 0xb800;                               //mov dx, 0B800h
    _es = _dx;                                  //mov es, dx
    _di = 0x1cc0;                               //mov di, 1CC0h
    _ch = _ch ^ _ch;                            //xor ch, ch
loc_2B5F1:                                      //loc_2B5F1:
    _push(_di);                                 //push di
    _push(_di);                                 //push di
    sub_2B63D();                                //call sub_2B63D
    _di = _pop();                               //pop di
    _di -= 0x07d0;                              //sub di, 7D0h
    _push(_di);                                 //push di
    sub_2B63D();                                //call sub_2B63D
    _di = _pop();                               //pop di
    _di -= 0x0820;                              //sub di, 820h
    _push(_di);                                 //push di
    sub_2B63D();                                //call sub_2B63D
    _di = _pop();                               //pop di
    _di -= 0x0780;                              //sub di, 780h
    _push(_di);                                 //push di
    sub_2B63D();                                //call sub_2B63D
    _di = _pop();                               //pop di
    _di = _pop();                               //pop di
    if (_di < 0x2000)                           //jb short loc_2B61F
      goto loc_2B61F;
    _di -= 0x2000;                              //sub di, 2000h
    goto loc_2B623;                             //jmp short loc_2B623
loc_2B61F:                                      //loc_2B61F:
    _di += 0x1fb0;                              //add di, 1FB0h
loc_2B623:                                      //loc_2B623:
    _push(_cx);                                 //push cx
    _cx = 0x0147;                               //mov cx, 147h
loc_2B627:                                      //loc_2B627:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2B627
      goto loc_2B627;
    _cx = _pop();                               //pop cx
    _ch += 1;                                   //inc ch
    if (_ch == 0x06)                            //jz short loc_2B637
      goto loc_2B637;
    goto loc_2B5F1;                             //jmp short loc_2B5F1
loc_2B637:                                      //loc_2B637:
    _es = _bp;                                  //mov es, bp
    sub_2B1B8();                                //call sub_2B1B8
}

void sub_2B884()
{
    _push(_cx);                                 //push cx
    _push(_di);                                 //push di
    _si = 0x9020;                               //mov si, 9020h
    if (_al != 0x3a)                            //jnz short loc_2B892
      goto loc_2B892;
    _al = 0x26;                                 //mov al, 26h
    goto loc_2B8BC;                             //jmp loc_2B8BC
loc_2B892:                                      //loc_2B892:
    if (_al != 0xff)                            //jnz short loc_2B89B
      goto loc_2B89B;
    _al = 0x27;                                 //mov al, 27h
    goto loc_2B8BC;                             //jmp loc_2B8BC
loc_2B89B:                                      //loc_2B89B:
    if (_al != 0x2d)                            //jnz short loc_2B8A4
      goto loc_2B8A4;
    _al = 0x0b;                                 //mov al, 0Bh
    goto loc_2B8BC;                             //jmp loc_2B8BC
loc_2B8A4:                                      //loc_2B8A4:
    if (_al != 0x20)                            //jnz short loc_2B8AD
      goto loc_2B8AD;
    _al = _al ^ _al;                            //xor al, al
    goto loc_2B8BC;                             //jmp loc_2B8BC
loc_2B8AD:                                      //loc_2B8AD:
    if (_al > 0x39)                             //ja short loc_2B8B6
      goto loc_2B8B6;
    _al -= 0x2f;                                //sub al, 2Fh
    goto loc_2B8BC;                             //jmp loc_2B8BC
loc_2B8B6:                                      //loc_2B8B6:
    if (_al < 0x41)                             //jb short loc_2B8A4
      goto loc_2B8A4;
    _al -= 0x35;                                //sub al, 35h
loc_2B8BC:                                      //loc_2B8BC:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cl = 0x03;                                 //mov cl, 3
    _ax <<= _cl;                                //shl ax, cl
    _bx = _ax;                                  //mov bx, ax
    _bx <<= 1;                                  //shl bx, 1
    _bx += _ax;                                 //add bx, ax
    _si += _bx;                                 //add si, bx
    _cx = 0x0c;                                 //mov cx, 0Ch
loc_2B8CD:                                      //loc_2B8CD:
    _movsw<MemAuto, MemAuto, DirAuto>();        //movsw
    _di -= 1;                                   //dec di
    _di -= 1;                                   //dec di
    if (_di < 0x2000)                           //jb short loc_2B8DC
      goto loc_2B8DC;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2B8E0;                             //jmp short loc_2B8E0
loc_2B8DC:                                      //loc_2B8DC:
    _di += 0x2000;                              //add di, 2000h
loc_2B8E0:                                      //loc_2B8E0:
    if (--_cx)                                  //loop loc_2B8CD
      goto loc_2B8CD;
    _di = _pop();                               //pop di
    _cx = _pop();                               //pop cx
}

void sub_2BCAC()
{
    _si += 0x10;                                //add si, 10h
    _di += 0x0c;                                //add di, 0Ch
loc_2BCB2:                                      //loc_2BCB2:
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _di -= 0x12;                                //sub di, 12h
    _cl = 0x06;                                 //mov cl, 6
loc_2BCB9:                                      //loc_2BCB9:
    _al = memory(_ds, _si);                     //mov al, [si]
    _si += 1;                                   //inc si
    _scasb();                                   //scasb
    if (_FIXME_)                                //ja short loc_2BCCB
      goto loc_2BCCB;
    if ((short)_si < 0)                         //jb short loc_2BCC5
      goto loc_2BCC5;
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2BCB9
      goto loc_2BCB9;
loc_2BCC5:                                      //loc_2BCC5:
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _di -= 0x0c;                                //sub di, 0Ch
    return;                                     //retn
loc_2BCCB:                                      //loc_2BCCB:
    _di = _pop();                               //pop di
    _di -= 0x0c;                                //sub di, 0Ch
    _si = _di;                                  //mov si, di
    _si -= 0x12;                                //sub si, 12h
    _cx = 0x0009;                               //mov cx, 9
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _di -= 0x18;                                //sub di, 18h
    _si = _pop();                               //pop si
    _dh -= 1;                                   //dec dh
    if (_dh != 0)                               //jnz short loc_2BCB2
      goto loc_2BCB2;
    _di -= 0x0c;                                //sub di, 0Ch
}

void sub_2BCE5()
{
    _push(_ax);                                 //push ax
    sub_2B884();                                //call sub_2B884
    _ax = _pop();                               //pop ax
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _dl -= 1;                                   //dec dl
if (_dl != 0)                                   //jnz short sub_2BCE5
  {sub_2BCE5(); return; };
}

void sub_2BCF1()
{
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _push(_si);                                 //push si
    sub_2B884();                                //call sub_2B884
    _si = _pop();                               //pop si
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _dl -= 1;                                   //dec dl
if (_dl != 0)                                   //jnz short sub_2BCF1
  {sub_2BCF1(); return; };
}

void sub_2BF74()
{
    WORD _cs = _seg004;
    _si = 0x48d2;                               //mov si, 48D2h
    _dl = memory(_cs, 0x5C6D);                  //mov dl, cs:byte_3088D
    _dh = _dl;                                  //mov dh, dl
    _dl <<= 1;                                  //shl dl, 1
    _dl += _dh;                                 //add dl, dh
    _dh = _dh ^ _dh;                            //xor dh, dh
    _si += _dx;                                 //add si, dx
    _cx = 0x0003;                               //mov cx, 3
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _cx = 0x17;                                 //mov cx, 17h
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _si = 0x48bd;                               //mov si, 48BDh
    _si += _dx;                                 //add si, dx
    _cx = 0x0003;                               //mov cx, 3
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    memory(_cs, 0x5C6D) += 1;                   //inc cs:byte_3088D
}

void sub_2BFD8() // enter name
{
    _si = 0x344f;                               //mov si, 344Fh
    _al = memory(_ds, 0x13E9);                  //mov al, ds:13E9h
    _al -= 0x31;                                //sub al, 31h
    _ah = _ah ^ _ah;                            //xor ah, ah
    _bx = 0x011b;                               //mov bx, 11Bh
    _ax = _bx * _al;                            //mul bx
    _si += _ax;                                 //add si, ax
    _dh = _dh ^ _dh;                            //xor dh, dh
    _di -= 1;                                   //dec di
    _di -= 1;                                   //dec di
    sub_2C0C7();                                //call sub_2C0C7
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
loc_2BFF2:                                      //loc_2BFF2:
    _ah = 0x07;                                 //mov ah, 7
    _interrupt(0x21);                           //int 21h
    if (_al == 0x1b)                            //jz short loc_2C036
      goto loc_2C036;
    if (_al == 0x08)                            //jz short loc_2BFA0
    {
        _ASSERT(0);
     // goto loc_2BFA0;
    }
    if (_al == 0x0d)                            //jz short loc_2C036
      goto loc_2C036;
    if (_al < 0x60)                             //jb short loc_2C008
      goto loc_2C008;
    _al &= 0xdf;                                //and al, 0DFh
loc_2C008:                                      //loc_2C008:
    if (_al == 0x20)                            //jz short loc_2C020
      goto loc_2C020;
    if (_al == 0x2d)                            //jz short loc_2C020
      goto loc_2C020;
    if (_al < 0x30)                             //jb short loc_2BFF2
      goto loc_2BFF2;
    if (_al > 0x5a)                             //ja short loc_2BFF2
      goto loc_2BFF2;
    if (_al >= 0x41)                            //jnb short loc_2C020
      goto loc_2C020;
    if (_al > 0x39)                             //ja short loc_2BFF2
      goto loc_2BFF2;
loc_2C020:                                      //loc_2C020:
    if (_dh == 0x0c)                            //jz short loc_2BFF2
      goto loc_2BFF2;
    memory(_ds, _si) = _al;                     //mov [si], al
    _si += 1;                                   //inc si
    _dh += 1;                                   //inc dh
    _push(_si);                                 //push si
    sub_2B884();                                //call sub_2B884
    sub_2C0C7();                                //call sub_2C0C7
    _sync();
    _si = _pop();                               //pop si
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    goto loc_2BFF2;                             //jmp short loc_2BFF2
loc_2C036:                                      //loc_2C036:
    if (_al == 0x1b)                            //jz short loc_2C047
      goto loc_2C047;
    _dh |= _dh;                                 //or dh, dh
    if (_dh != 0)                               //jnz short loc_2C04B
      goto loc_2C04B;
    if (memory(_ds, 0x3F08) == 0)               //jz short loc_2C096
      goto loc_2C096;
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_2C047:                                      //loc_2C047:
    _al = 0xff;                                 //mov al, 0FFh
    _flags.carry = false;                       //clc
    return;                                     //retn
loc_2C04B:                                      //loc_2C04B:
    _dl = 0x0d;                                 //mov dl, 0Dh
    _dl -= _dh;                                 //sub dl, dh
    _bl = _dl;                                  //mov bl, dl
    _bl -= 1;                                   //dec bl
    _push(_bx);                                 //push bx
loc_2C054:                                      //loc_2C054:
    memory(_ds, _si) = 0x20;                    //mov byte ptr [si], 20h
    _push(_si);                                 //push si
    _al = 0x20;                                 //mov al, 20h
    sub_2B884();                                //call sub_2B884
    _sync();
    _si = _pop();                               //pop si
    _si += 1;                                   //inc si
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2C054
      goto loc_2C054;
    _si = 0x344f;                               //mov si, 344Fh
    _al = memory(_ds, 0x13E9);                  //mov al, ds:13E9h
    _al -= 0x31;                                //sub al, 31h
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cx = 0x011b;                               //mov cx, 11Bh
    _ax = _cx * _al;                            //mul cx
    _si += _ax;                                 //add si, ax
    _si += 0x0a;                                //add si, 0Ah
    _bx = _pop();                               //pop bx
    _bl >>= 1;                                  //shr bl, 1
    if (_bl == 0)                               //jz short loc_2C094
      goto loc_2C094;
loc_2C07E:                                      //loc_2C07E:
    _push(_si);                                 //push si
    _cl = 0x0b;                                 //mov cl, 0Bh
loc_2C081:                                      //loc_2C081:
    _al = memory(_ds, _si);                     //mov al, [si]
    memory(_ds, _si + 1) = _al;                 //mov [si+1], al
    _si -= 1;                                   //dec si
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2C081
      goto loc_2C081;
    memory(_ds, _si + 1) = 0x20;                //mov byte ptr [si+1], 20h
    _si = _pop();                               //pop si
    _bl -= 1;                                   //dec bl
    if (_bl != 0)                               //jnz short loc_2C07E
      goto loc_2C07E;
loc_2C094:                                      //loc_2C094:
    _flags.carry = false;                       //clc
    return;                                     //retn
loc_2C096:                                      //loc_2C096:
    _push(_cx);                                 //push cx
    _push(_si);                                 //push si
    _si = 0x344f;                               //mov si, 344Fh
    _cl = 0x0c;                                 //mov cl, 0Ch
loc_2C09D:                                      //loc_2C09D:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz short loc_2C0A8
      goto loc_2C0A8;
    _cl -= 1;                                   //dec cl
    if (_cl == 0)                               //jz short loc_2C0AE
      goto loc_2C0AE;
    goto loc_2C09D;                             //jmp short loc_2C09D
loc_2C0A8:                                      //loc_2C0A8:
    _si = _pop();                               //pop si
    _cx = _pop();                               //pop cx
    goto loc_2BFF2;                             //jmp loc_2BFF2
    return;                                     //retn
loc_2C0AE:                                      //loc_2C0AE:
    _push(_di);                                 //push di
    _si = 0x344f;                               //mov si, 344Fh
    _cl = 0x0c;                                 //mov cl, 0Ch
loc_2C0B4:                                      //loc_2C0B4:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _push(_si);                                 //push si
    sub_2B884();                                //call sub_2B884
    _si = _pop();                               //pop si
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2C0B4
      goto loc_2C0B4;
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _cx = _pop();                               //pop cx
    _dh = 0x0c;                                 //mov dh, 0Ch
    goto loc_2C094;                             //jmp short loc_2C094
}

void sub_2C234()
{
    _ah = memory(_ds, 0x2D49);                  //mov ah, ds:2D49h
    _ah &= 0x7f;                                //and ah, 7Fh
    _bh = _bl;                                  //mov bh, bl
    _bh |= _bh;                                 //or bh, bh
    if (_bh == 0)                               //jz short loc_2C24D
      goto loc_2C24D;
    _si = 0x2d4f;                               //mov si, 2D4Fh
loc_2C244:                                      //loc_2C244:
if (_ah == memory(_ds, _si))                    //jz short sub_2C234
  {sub_2C234(); return; };
    _si += 1;                                   //inc si
    _bh -= 1;                                   //dec bh
    if (_bh != 0)                               //jnz short loc_2C244
      goto loc_2C244;
loc_2C24D:                                      //loc_2C24D:
    _si = 0x2d52;                               //mov si, 2D52h
loc_2C250:                                      //loc_2C250:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz short loc_2C25B
      goto loc_2C25B;
if (_ah == _al)                                 //jz short sub_2C234
  {sub_2C234(); return; };
    goto loc_2C250;                             //jmp short loc_2C250
loc_2C25B:                                      //loc_2C25B:
    _bh = _bh ^ _bh;                            //xor bh, bh
    memory(_ds, _bx + 11599) = _ah;             //mov [bx+2D4Fh], ah
}

void sub_2C262()
{
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz short locret_2C26B
      goto locret_2C26B;
    _stosb<MemAuto, DirAuto>();                 //stosb
    _di += 1;                                   //inc di
{sub_2C262(); return; };                        //jmp short sub_2C262
locret_2C26B:                                   //locret_2C26B:
    return;
}

void sub_2C26C() // variable code delay??
{
    _push(_cx);                                 //push cx
loc_2C26D:                                      //loc_2C26D:
    _cx = 0x0001;                               //mov cx, 1
loc_2C270:                                      //loc_2C270:
    if (--_cx)                                  //loop loc_2C270
      goto loc_2C270;
    _cx = _pop();                               //pop cx
}

void sub_2C86F()
{
    memory(_ds, 0x2E54) = 0xc8;                 //mov byte ptr ds:2E54h, 0C8h
    _cl = memory(_ds, 0x33F3);                  //mov cl, ds:33F3h
    _al = memory(_ds, 0x33F4);                  //mov al, ds:33F4h
    _al -= 1;                                   //dec al
    _si = 0x770d;                               //mov si, 770Dh
    _ch = 0x05;                                 //mov ch, 5
loc_2C882:                                      //loc_2C882:
    _push(_es);                                 //push es
    _dx = 0xb800;                               //mov dx, 0B800h
    _es = _dx;                                  //mov es, dx
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_si);                                 //push si
    _si = memory16(_ds, _si);                   //mov si, [si]
    _flags.interrupt = false;                   //cli
    _ch = _ch ^ _ch;                            //xor ch, ch
    _di = _cx;                                  //mov di, cx
    _di >>= 1;                                  //shr di, 1
    _di >>= 1;                                  //shr di, 1
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (!_flags.carry)                          //jnb short loc_2C89E
      goto loc_2C89E;
    _di += 0x2000;                              //add di, 2000h
loc_2C89E:                                      //loc_2C89E:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cl = 0x04;                                 //mov cl, 4
    _ax <<= _cl;                                //shl ax, cl
    _di += _ax;                                 //add di, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _cl = 0x13;                                 //mov cl, 13h
loc_2C8AE:                                      //loc_2C8AE:
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    if (_di < 0x2000)                           //jb short loc_2C8C2
      goto loc_2C8C2;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2C8AE
      goto loc_2C8AE;
    goto loc_2C8CA;                             //jmp short loc_2C8CA
loc_2C8C2:                                      //loc_2C8C2:
    _di += 0x2000;                              //add di, 2000h
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2C8AE
      goto loc_2C8AE;
loc_2C8CA:                                      //loc_2C8CA:
    _flags.interrupt = true;                    //sti
    _si = _pop();                               //pop si
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    _cx = 0x012c;                               //mov cx, 12Ch
loc_2C8D1:                                      //loc_2C8D1:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2C8D1
      goto loc_2C8D1;
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
    _ch -= 1;                                   //dec ch
    _es = _pop();                               //pop es
    if (_ch != 0)                               //jnz short loc_2C882
      goto loc_2C882;
    _di = 0x3a7c;                               //mov di, 3A7Ch
    _al = memory(_ds, 0x13C9);                  //mov al, ds:13C9h
    _al -= 1;                                   //dec al
    _ah = _ah ^ _ah;                            //xor ah, ah
    _bl = _al;                                  //mov bl, al
    _bl &= 0x03;                                //and bl, 3
    _al &= 0xfc;                                //and al, 0FCh
    _di += _ax;                                 //add di, ax
    _bl |= _bl;                                 //or bl, bl
    if (_bl == 0)                               //jz short loc_2C8FC
      goto loc_2C8FC;
loc_2C8F4:                                      //loc_2C8F4:
    _di += 0xf0;                                //add di, 0F0h
    _bl -= 1;                                   //dec bl
    if (_bl != 0)                               //jnz short loc_2C8F4
      goto loc_2C8F4;
loc_2C8FC:                                      //loc_2C8FC:
    _bp = _es;                                  //mov bp, es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _dl = 0x05;                                 //mov dl, 5
loc_2C907:                                      //loc_2C907:
    _cx = 0x0002;                               //mov cx, 2
    _rep_stosw<MemAuto, DirAuto>();             //rep stosw
    _di -= 0x0004;                              //sub di, 4
    if (_di < 0x2000)                           //jb short loc_2C91B
      goto loc_2C91B;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2C91F;                             //jmp short loc_2C91F
loc_2C91B:                                      //loc_2C91B:
    _di += 0x2000;                              //add di, 2000h
loc_2C91F:                                      //loc_2C91F:
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2C907
      goto loc_2C907;
    _es = _bp;                                  //mov es, bp
    memory16(_ds, 0x1468) = 29989;              //mov word ptr ds:1468h, 7525h
    memory(_ds, 0x2E54) = 0xc6;                 //mov byte ptr ds:2E54h, 0C6h
    _cl = 0xc8;                                 //mov cl, 0C8h
    sub_2CA70();                                //call sub_2CA70
    memory16(_ds, 0x1468) += 2;                 //add word ptr ds:1468h, 2
    _al = 0x09;                                 //mov al, 9
loc_2C93C:                                      //loc_2C93C:
    _push(_ax);                                 //push ax
    _cx = 0x4b;                                 //mov cx, 4Bh
loc_2C940:                                      //loc_2C940:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2C940
      goto loc_2C940;
    _cl = memory(_ds, 0x2E54);                  //mov cl, ds:2E54h
    sub_2CA43();                                //call sub_2CA43
    memory(_ds, 0x2E54) -= 1;                   //dec byte ptr ds:2E54h
    memory(_ds, 0x2E54) -= 1;                   //dec byte ptr ds:2E54h
    _ax = _pop();                               //pop ax
    _al -= 1;                                   //dec al
    if (_al != 0)                               //jnz short loc_2C93C
      goto loc_2C93C;
    _cl = memory(_ds, 0x33F3);                  //mov cl, ds:33F3h
    _al = memory(_ds, 0x33F4);                  //mov al, ds:33F4h
    _al -= 1;                                   //dec al
    _si = 0x7717;                               //mov si, 7717h
    _ch = 0x14;                                 //mov ch, 14h
loc_2C967:                                      //loc_2C967:
    _push(_cx);                                 //push cx
    _push(_ax);                                 //push ax
    _push(_es);                                 //push es
    _flags.carry = _ch & 1;                     //shr ch, 1
    _ch >>= 1;
    if (_flags.carry)                           //jb short loc_2C9BB
      goto loc_2C9BB;
    _flags.carry = _ch & 1;                     //shr ch, 1
    _ch >>= 1;
    if (_flags.carry)                           //jb short loc_2C9BB
      goto loc_2C9BB;
    _dx = 0xb800;                               //mov dx, 0B800h
    _es = _dx;                                  //mov es, dx
    _push(_si);                                 //push si
    _si = memory16(_ds, _si);                   //mov si, [si]
    _flags.interrupt = false;                   //cli
    _ch = _ch ^ _ch;                            //xor ch, ch
    _di = _cx;                                  //mov di, cx
    _di >>= 1;                                  //shr di, 1
    _di >>= 1;                                  //shr di, 1
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (!_flags.carry)                          //jnb short loc_2C98B
      goto loc_2C98B;
    _di += 0x2000;                              //add di, 2000h
loc_2C98B:                                      //loc_2C98B:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cl = 0x04;                                 //mov cl, 4
    _ax <<= _cl;                                //shl ax, cl
    _di += _ax;                                 //add di, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _cl = 0x13;                                 //mov cl, 13h
loc_2C99B:                                      //loc_2C99B:
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    if (_di < 0x2000)                           //jb short loc_2C9AF
      goto loc_2C9AF;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2C99B
      goto loc_2C99B;
    goto loc_2C9B7;                             //jmp short loc_2C9B7
loc_2C9AF:                                      //loc_2C9AF:
    _di += 0x2000;                              //add di, 2000h
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2C99B
      goto loc_2C99B;
loc_2C9B7:                                      //loc_2C9B7:
    _flags.interrupt = true;                    //sti
    _si = _pop();                               //pop si
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
loc_2C9BB:                                      //loc_2C9BB:
    _cx = 0x4b;                                 //mov cx, 4Bh
loc_2C9BE:                                      //loc_2C9BE:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2C9BE
      goto loc_2C9BE;
    _es = _pop();                               //pop es
    _push(_si);                                 //push si
    _cl = memory(_ds, 0x2E54);                  //mov cl, ds:2E54h
    sub_2CA43();                                //call sub_2CA43
    memory(_ds, 0x2E54) -= 2;                   //sub byte ptr ds:2E54h, 2
    _si = _pop();                               //pop si
    _ax = _pop();                               //pop ax
    _cx = _pop();                               //pop cx
    _ch -= 1;                                   //dec ch
    if (_ch != 0)                               //jnz short loc_2C967
      goto loc_2C967;
    _cx = 0x4b;                                 //mov cx, 4Bh
loc_2C9DB:                                      //loc_2C9DB:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2C9DB
      goto loc_2C9DB;
loc_2C9E0:                                      //loc_2C9E0:
    if (memory(_ds, 0x2E54) < 0x6d)             //jb short loc_2C9FD
      goto loc_2C9FD;
    _cl = memory(_ds, 0x2E54);                  //mov cl, ds:2E54h
    sub_2CA43();                                //call sub_2CA43
    memory(_ds, 0x2E54) -= 2;                   //sub byte ptr ds:2E54h, 2
    _cx = 0x4b;                                 //mov cx, 4Bh
loc_2C9F6:                                      //loc_2C9F6:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2C9F6
      goto loc_2C9F6;
    goto loc_2C9E0;                             //jmp short loc_2C9E0
loc_2C9FD:                                      //loc_2C9FD:
    _cx = 0x0000;                               //mov cx, 0
loc_2CA00:                                      //loc_2CA00:
    if (--_cx)                                  //loop loc_2CA00
      goto loc_2CA00;
    _si = 0x75db;                               //mov si, 75DBh
    _bp = _es;                                  //mov bp, es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _ah = 0x06;                                 //mov ah, 6
loc_2CA0E:                                      //loc_2CA0E:
    _push(_si);                                 //push si
    _di = 0x1cd9;                               //mov di, 1CD9h
    _si = memory16(_ds, _si);                   //mov si, [si]
    _al = 0x07;                                 //mov al, 7
loc_2CA16:                                      //loc_2CA16:
    _push(_di);                                 //push di
    _cx = 0x0007;                               //mov cx, 7
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di = _pop();                               //pop di
    if (_di < 0x2000)                           //jb short loc_2CA29
      goto loc_2CA29;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2CA2D;                             //jmp short loc_2CA2D
loc_2CA29:                                      //loc_2CA29:
    _di += 0x2000;                              //add di, 2000h
loc_2CA2D:                                      //loc_2CA2D:
    _al -= 1;                                   //dec al
    if (_al != 0)                               //jnz short loc_2CA16
      goto loc_2CA16;
    _si = _pop();                               //pop si
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    _cx = 0x0147;                               //mov cx, 147h
loc_2CA37:                                      //loc_2CA37:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2CA37
      goto loc_2CA37;
    _ah -= 1;                                   //dec ah
    if (_ah != 0)                               //jnz short loc_2CA0E
      goto loc_2CA0E;
    _es = _bp;                                  //mov es, bp
}

void sub_2CBE1()
{
    _flags.interrupt = false;                   //cli
    _push(_es);                                 //push es
    _dx = 0xb800;                               //mov dx, 0B800h
    _es = _dx;                                  //mov es, dx
    _di = _di ^ _di;                            //xor di, di
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (!_flags.carry)                          //jnb short loc_2CBF2
      goto loc_2CBF2;
    _di += 0x2000;                              //add di, 2000h
loc_2CBF2:                                      //loc_2CBF2:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cl = 0x04;                                 //mov cl, 4
    _ax <<= _cl;                                //shl ax, cl
    _di += _ax;                                 //add di, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _di += 0x0002;                              //add di, 2
    _si = 0x6d95;                               //mov si, 6D95h
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bl = memory(_ds, 0x2EFB);                  //mov bl, ds:2EFBh
    _bl >>= 1;                                  //shr bl, 1
    _bl >>= 1;                                  //shr bl, 1
    _bl >>= 1;                                  //shr bl, 1
    _bx <<= 1;                                  //shl bx, 1
    _si += _bx;                                 //add si, bx
    _si = memory16(_ds, _si);                   //mov si, [si]
    _dh = 0x08;                                 //mov dh, 8
loc_2CC1A:                                      //loc_2CC1A:
    _push(_di);                                 //push di
    _cx = 0x18;                                 //mov cx, 18h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _di = _pop();                               //pop di
    if (_di < 0x2000)                           //jb short loc_2CC2D
      goto loc_2CC2D;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2CC31;                             //jmp short loc_2CC31
loc_2CC2D:                                      //loc_2CC2D:
    _di += 0x2000;                              //add di, 2000h
loc_2CC31:                                      //loc_2CC31:
    _dh -= 1;                                   //dec dh
    if (_dh != 0)                               //jnz short loc_2CC1A
      goto loc_2CC1A;
    _es = _pop();                               //pop es
    _flags.interrupt = true;                    //sti
    _al = memory(_ds, 0x2EFB);                  //mov al, ds:2EFBh
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (_flags.carry)                           //jb short loc_2CC4F
      goto loc_2CC4F;
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (_flags.carry)                           //jb short loc_2CC4F
      goto loc_2CC4F;
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (_flags.carry)                           //jb short loc_2CC4F
      goto loc_2CC4F;
    if (_al != 0x04)                            //jnz short loc_2CC4F
      goto loc_2CC4F;
    memory(_ds, 0x2EFB) = 0xff;                 //mov byte ptr ds:2EFBh, 0FFh
loc_2CC4F:                                      //loc_2CC4F:
    memory(_ds, 0x2EFB) += 1;                   //inc byte ptr ds:2EFBh
}

void sub_2CC54()
{
    _flags.interrupt = false;                   //cli
    _push(_es);                                 //push es
    _push(_ax);                                 //push ax
    _dx = 0xb800;                               //mov dx, 0B800h
    _es = _dx;                                  //mov es, dx
    _di = _di ^ _di;                            //xor di, di
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (!_flags.carry)                          //jnb short loc_2CC66
      goto loc_2CC66;
    _di += 0x2000;                              //add di, 2000h
loc_2CC66:                                      //loc_2CC66:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cl = 0x04;                                 //mov cl, 4
    _ax <<= _cl;                                //shl ax, cl
    _di += _ax;                                 //add di, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _di += 0x0002;                              //add di, 2
    _ax = _pop();                               //pop ax
    _al -= 0x06;                                //sub al, 6
    _bl = _al;                                  //mov bl, al
    _dl = _al;                                  //mov dl, al
    _dl &= 0x07;                                //and dl, 7
    _dh = _dh ^ _dh;                            //xor dh, dh
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _si = 0x2f18;                               //mov si, 2F18h
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cl = 0x03;                                 //mov cl, 3
    _al >>= _cl;                                //shr al, cl
    _cl = 0x0c;                                 //mov cl, 0Ch
    _ax = _cl * _al;                            //mul cl
    _si += _ax;                                 //add si, ax
    _cl = 0x00;                                 //mov cl, 0
loc_2CC98:                                      //loc_2CC98:
    _push(_si);                                 //push si
    _ah = _ah ^ _ah;                            //xor ah, ah
    _al = memory(_ds, _si);                     //mov al, [si]
    if (_al != 0x0c)                            //jnz short loc_2CCA9
      goto loc_2CCA9;
    _al = _bl;                                  //mov al, bl
    sub_2EE05();                                //call sub_2EE05
    goto loc_2CCCE;                             //jmp loc_2CCCE
loc_2CCA9:                                      //loc_2CCA9:
    _ax <<= 1;                                  //shl ax, 1
    _si = 0x3080;                               //mov si, 3080h
    _si += _ax;                                 //add si, ax
    _si = memory16(_ds, _si);                   //mov si, [si]
    if (_ax < 0x30)                             //jb short loc_2CCBF
      goto loc_2CCBF;
    _push(_ds);                                 //push ds
    _push(_ax);                                 //push ax
    _ax = _seg002;                              //mov ax, seg seg002
    _ds = _ax;                                  //mov ds, ax
    _ax = _pop();                               //pop ax
loc_2CCBF:                                      //loc_2CCBF:
    _si += _dx;                                 //add si, dx
    _push(_cx);                                 //push cx
    _cx = 0x0002;                               //mov cx, 2
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _cx = _pop();                               //pop cx
    if (_ax < 0x30)                             //jb short loc_2CCCE
      goto loc_2CCCE;
    _ds = _pop();                               //pop ds
loc_2CCCE:                                      //loc_2CCCE:
    _si = _pop();                               //pop si
    _si += 1;                                   //inc si
    _cl += 1;                                   //inc cl
    if (_cl != 0x0c)                            //jnz short loc_2CC98
      goto loc_2CC98;
    _es = _pop();                               //pop es
    return;                                     //retn
    _STOP_("sp-trace-fail");                    //sub_2CC54 endp_failed
    _STOP_("continues");                        //sub_2CCD9 proc near
}

void sub_2CCD9()
{
    _flags.interrupt = false;                   //cli
    _push(_es);                                 //push es
    _dx = 0xb800;                               //mov dx, 0B800h
    _es = _dx;                                  //mov es, dx
    _bh = _bh ^ _bh;                            //xor bh, bh
    _di = _bx;                                  //mov di, bx
    _di >>= 1;                                  //shr di, 1
    _di >>= 1;                                  //shr di, 1
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (!_flags.carry)                          //jnb short loc_2CCF0
      goto loc_2CCF0;
    _di += 0x2000;                              //add di, 2000h
loc_2CCF0:                                      //loc_2CCF0:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cl = 0x04;                                 //mov cl, 4
    _ax <<= _cl;                                //shl ax, cl
    _di += _ax;                                 //add di, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _cl = 0x06;                                 //mov cl, 6
loc_2CD00:                                      //loc_2CD00:
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memoryVideoSet16(_es, _di + 2, _ax);               //mov es:[di+2], ax
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    memoryVideoSet(_es, _di + 4, _al);                 //mov es:[di+4], al
    if (_di < 0x2000)                           //jb short loc_2CD1E
      goto loc_2CD1E;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2CD00
      goto loc_2CD00;
    goto loc_2CD26;                             //jmp short loc_2CD26
loc_2CD1E:                                      //loc_2CD1E:
    _di += 0x2000;                              //add di, 2000h
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2CD00
      goto loc_2CD00;
loc_2CD26:                                      //loc_2CD26:
    _es = _pop();                               //pop es
    _flags.interrupt = true;                    //sti
}

void sub_2CD29()
{
    _push(_es);                                 //push es
    _push(_ds);                                 //push ds
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _ds = _ax;                                  //mov ds, ax
    _di = 0x1ae2;                               //mov di, 1AE2h
    _dl = 0x1b;                                 //mov dl, 1Bh
loc_2CD37:                                      //loc_2CD37:
    _push(_di);                                 //push di
    _si = _di;                                  //mov si, di
    if (_si < 0x2000)                           //jb short loc_2CD47
      goto loc_2CD47;
    _si -= 0x1fb0;                              //sub si, 1FB0h
    goto loc_2CD4B;                             //jmp loc_2CD4B
loc_2CD47:                                      //loc_2CD47:
    _si += 0x2000;                              //add si, 2000h
loc_2CD4B:                                      //loc_2CD4B:
    _cx = 0x18;                                 //mov cx, 18h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _di = _pop();                               //pop di
    if (_di < 0x2000)                           //jb short loc_2CD5D
      goto loc_2CD5D;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2CD61;                             //jmp short loc_2CD61
loc_2CD5D:                                      //loc_2CD5D:
    _di += 0x2000;                              //add di, 2000h
loc_2CD61:                                      //loc_2CD61:
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2CD37
      goto loc_2CD37;
    _ds = _pop();                               //pop ds
    _es = _pop();                               //pop es
}

void sub_2CD68()
{
    _push(_es);                                 //push es
    _push(_ds);                                 //push ds
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _ds = _ax;                                  //mov ds, ax
    _si = 0x1ef2;                               //mov si, 1EF2h
    _dl = 0x1b;                                 //mov dl, 1Bh
loc_2CD76:                                      //loc_2CD76:
    _push(_si);                                 //push si
    _di = _si;                                  //mov di, si
    if (_di < 0x2000)                           //jb short loc_2CD85
      goto loc_2CD85;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2CD89;                             //jmp short loc_2CD89
loc_2CD85:                                      //loc_2CD85:
    _di += 0x2000;                              //add di, 2000h
loc_2CD89:                                      //loc_2CD89:
    _cx = 0x18;                                 //mov cx, 18h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _si = _pop();                               //pop si
    if (_si < 0x2000)                           //jb short loc_2CD9C
      goto loc_2CD9C;
    _si -= 0x2000;                              //sub si, 2000h
    goto loc_2CDA0;                             //jmp loc_2CDA0
loc_2CD9C:                                      //loc_2CD9C:
    _si += 0x1fb0;                              //add si, 1FB0h
loc_2CDA0:                                      //loc_2CDA0:
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2CD76
      goto loc_2CD76;
    _ds = _pop();                               //pop ds
    _es = _pop();                               //pop es
}

void sub_2CDA7()
{
    if (memory(_ds, 0x2D3B) != 0)               //jnz short loc_2CDB8
      goto loc_2CDB8;
    _al = memory(_ds, 0x2E55);                  //mov al, ds:2E55h
    if (memory(_ds, 0x2E54) != _al)             //jnz short loc_2CDB8
      goto loc_2CDB8;
    return;                                     //retn
loc_2CDB8:                                      //loc_2CDB8:
    memory16(_ds, 0x1487) -= 499;               //sub word ptr ds:1487h, 1F3h
    _bp = _si;                                  //mov bp, si
    _di = 0x2e65;                               //mov di, 2E65h
    _si = 0x2e57;                               //mov si, 2E57h
    _cx = 0x0007;                               //mov cx, 7
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _si = 0x2d8c;                               //mov si, 2D8Ch
    _di = 0x2ddc;                               //mov di, 2DDCh
    _cx = 0x27;                                 //mov cx, 27h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _di = 0x2e57;                               //mov di, 2E57h
    _bl = memory(_ds, 0x2E54);                  //mov bl, ds:2E54h
    memory(_ds, 0x2E55) = _bl;                  //mov ds:2E55h, bl
    _dl = _bl;                                  //mov dl, bl
    sub_2CEFE();                                //call sub_2CEFE
    _si = _bp;                                  //mov si, bp
    _di = 0x2d8c;                               //mov di, 2D8Ch
    _cx = 0x27;                                 //mov cx, 27h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _dl &= 0x03;                                //and dl, 3
    if (_dl == 0)                               //jz short loc_2CE27
      goto loc_2CE27;
    _dl <<= 1;                                  //shl dl, 1
loc_2CDF7:                                      //loc_2CDF7:
    _di = 0x2d8c;                               //mov di, 2D8Ch
    _cl = 0x07;                                 //mov cl, 7
loc_2CDFC:                                      //loc_2CDFC:
    memory(_ds, _di) >>= 1;                     //shr byte ptr [di], 1
    _ASSERT(0 /* check carry */); _rcr(memory(_ds, _di + 1), 1);
    _ASSERT(0 /* check carry */); _rcr(memory(_ds, _di + 2), 1);
    _ASSERT(0 /* check carry */); _rcr(memory(_ds, _di + 3), 1);
    _ASSERT(0 /* check carry */); _rcr(memory(_ds, _di + 4), 1);
    _ASSERT(0 /* check carry */); _rcr(memory(_ds, _di + 5), 1);
    _ASSERT(0 /* check carry */); _rcr(memory(_ds, _di + 6), 1);
    _ASSERT(0 /* check carry */); _rcr(memory(_ds, _di + 7), 1);
    _ASSERT(0 /* check carry */); _rcr(memory(_ds, _di + 8), 1);
    _ASSERT(0 /* check carry */); _rcr(memory(_ds, _di + 9), 1);
    _ASSERT(0 /* check carry */); _rcr(memory(_ds, _di + 10), 1);
    _di += 0x0b;                                //add di, 0Bh
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2CDFC
      goto loc_2CDFC;
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2CDF7
      goto loc_2CDF7;
loc_2CE27:                                      //loc_2CE27:
    _si = 0x2ddc;                               //mov si, 2DDCh
    _di = 0x2e65;                               //mov di, 2E65h
    sub_2CEA1();                                //call sub_2CEA1
    _si = 0x2d8c;                               //mov si, 2D8Ch
    _di = 0x2e57;                               //mov di, 2E57h
    sub_2CEA1();                                //call sub_2CEA1
}

void sub_2CE3A()
{
    if (memory(_ds, 0x2D3B) != 0)               //jnz short loc_2CE4B
      goto loc_2CE4B;
    _al = memory(_ds, 0x2E55);                  //mov al, ds:2E55h
    if (memory(_ds, 0x2E54) != _al)             //jnz short loc_2CE4B
      goto loc_2CE4B;
    return;                                     //retn
loc_2CE4B:                                      //loc_2CE4B:
    memory16(_ds, 0x1487) -= 480;               //sub word ptr ds:1487h, 1E0h
    _bp = _si;                                  //mov bp, si
    _di = 0x2e65;                               //mov di, 2E65h
    _si = 0x2e57;                               //mov si, 2E57h
    _cx = 0x0007;                               //mov cx, 7
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _si = 0x2d8c;                               //mov si, 2D8Ch
    _di = 0x2ddc;                               //mov di, 2DDCh
    _cx = 0x27;                                 //mov cx, 27h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _di = 0x2e57;                               //mov di, 2E57h
    _bl = memory(_ds, 0x2E54);                  //mov bl, ds:2E54h
    memory(_ds, 0x2E55) = _bl;                  //mov ds:2E55h, bl
    _dl = _bl;                                  //mov dl, bl
    sub_2CEFE();                                //call sub_2CEFE
    _si = _bp;                                  //mov si, bp
    _dl &= 0x03;                                //and dl, 3
    if (_dl == 0)                               //jz short loc_2CE86
      goto loc_2CE86;
    _al = 0x4d;                                 //mov al, 4Dh
    _ax = _dl * _al;                            //mul dl
    _si += _ax;                                 //add si, ax
loc_2CE86:                                      //loc_2CE86:
    _di = 0x2d8c;                               //mov di, 2D8Ch
    _cx = 0x27;                                 //mov cx, 27h
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _si = 0x2ddc;                               //mov si, 2DDCh
    _di = 0x2e65;                               //mov di, 2E65h
    sub_2CEA1();                                //call sub_2CEA1
    _si = 0x2d8c;                               //mov si, 2D8Ch
    _di = 0x2e57;                               //mov di, 2E57h
    sub_2CEA1();                                //call sub_2CEA1
}

void sub_2CEA1()
{
    _flags.interrupt = false;                   //cli
    _bp = _es;                                  //mov bp, es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _cx = 0x0007;                               //mov cx, 7
loc_2CEAC:                                      //loc_2CEAC:
    _dx = _cx;                                  //mov dx, cx
    _bx = memory16(_ds, _di);                   //mov bx, [di]
    _cx = 0x0005;                               //mov cx, 5
loc_2CEB3:                                      //loc_2CEB3:
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_es, _bx) = memory16(_es, _bx) ^ _ax;//xor es:[bx], ax
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    if (--_cx)                                  //loop loc_2CEB3
      goto loc_2CEB3;
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    memory(_es, _bx) = memory(_es, _bx) ^ _al;  //xor es:[bx], al
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _cx = _dx;                                  //mov cx, dx
    if (--_cx)                                  //loop loc_2CEAC
      goto loc_2CEAC;
    _es = _bp;                                  //mov es, bp
    _flags.interrupt = true;                    //sti
}

void sub_2CEC9()
{
    _push(_es);                                 //push es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _bl = memory(_ds, 0x2E54);                  //mov bl, ds:2E54h
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bl >>= 1;                                  //shr bl, 1
    _bl >>= 1;                                  //shr bl, 1
    _bx += 0x1cc0;                              //add bx, 1CC0h
    _di = _bx;                                  //mov di, bx
    _dl = 0x10;                                 //mov dl, 10h
loc_2CEE1:                                      //loc_2CEE1:
    _push(_di);                                 //push di
    _cx = 0x0007;                               //mov cx, 7
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di = _pop();                               //pop di
    if (_di < 0x2000)                           //jb short loc_2CEF4
      goto loc_2CEF4;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2CEF8;                             //jmp short loc_2CEF8
loc_2CEF4:                                      //loc_2CEF4:
    _di += 0x2000;                              //add di, 2000h
loc_2CEF8:                                      //loc_2CEF8:
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2CEE1
      goto loc_2CEE1;
    _es = _pop();                               //pop es
    _sync();
}

void sub_2CEFE()
{
    _al = _bl;                                  //mov al, bl
    _ah = _ah ^ _ah;                            //xor ah, ah
    _al >>= 1;                                  //shr al, 1
    _al >>= 1;                                  //shr al, 1
    _ax += 0x1cc0;                              //add ax, 1CC0h
    memory16(_ds, _di) = _ax;                   //mov [di], ax
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _ax += 0x2000;                              //add ax, 2000h
    memory16(_ds, _di) = _ax;                   //mov [di], ax
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _ax -= 0x1fb0;                              //sub ax, 1FB0h
    memory16(_ds, _di) = _ax;                   //mov [di], ax
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _ax += 0x2000;                              //add ax, 2000h
    memory16(_ds, _di) = _ax;                   //mov [di], ax
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _ax -= 0x1fb0;                              //sub ax, 1FB0h
    memory16(_ds, _di) = _ax;                   //mov [di], ax
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _ax += 0x2000;                              //add ax, 2000h
    memory16(_ds, _di) = _ax;                   //mov [di], ax
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _ax -= 0x1fb0;                              //sub ax, 1FB0h
    memory16(_ds, _di) = _ax;                   //mov [di], ax
}

void sub_2D09F()
{
    WORD _cs = _seg004;
    if (memory(_ds, _si + 29) < 0x23)           //jb short loc_2D0C7
      goto loc_2D0C7;
    memory(_ds, _si + 29) = 0;                  //mov byte ptr [si+1Dh], 0
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    memory16(_ds, _si + 24) = _ax;              //mov [si+18h], ax
    memory16(_ds, _si + 26) = 0;                //mov word ptr [si+1Ah], 0
    _dl = 0x05;                                 //mov dl, 5
    sub_2ECE0();                                //call sub_2ECE0
    _ah += 1;                                   //inc ah
    memory(_ds, _si + 22) = _ah;                //mov [si+16h], ah
    _dl = 0x05;                                 //mov dl, 5
    sub_2ECE0();                                //call sub_2ECE0
    _ah += 1;                                   //inc ah
    memory(_ds, _si + 23) = _ah;                //mov [si+17h], ah
loc_2D0C7:                                      //loc_2D0C7:
    _al = memory(_ds, _si);                     //mov al, [si]
    _bl = memory(_ds, _si + 1);                 //mov bl, [si+1]
    if (_al > 0x08)                             //ja short loc_2D0DE
      goto loc_2D0DE;
    memory(_cs, 0xF4) = 2;                      //mov cs:byte_2AD14, 2
    memory(_ds, _si + 20) = 0;                  //mov byte ptr [si+14h], 0
    _dl = 0x09;                                 //mov dl, 9
    goto loc_2D0EE;                             //jmp short loc_2D0EE
loc_2D0DE:                                      //loc_2D0DE:
    if (_al < 0xc4)                             //jb short loc_2D0FF
      goto loc_2D0FF;
    memory(_cs, 0xF4) = 2;                      //mov cs:byte_2AD14, 2
    memory(_ds, _si + 20) = 1;                  //mov byte ptr [si+14h], 1
    _dl = 0xc3;                                 //mov dl, 0C3h
loc_2D0EE:                                      //loc_2D0EE:
    memory(_ds, _si + 26) = 1;                  //mov byte ptr [si+1Ah], 1
    memory(_ds, _si + 27) = 0;                  //mov byte ptr [si+1Bh], 0
    memory(_ds, _si + 24) = _dl;                //mov [si+18h], dl
    memory(_ds, _si + 25) = _bl;                //mov [si+19h], bl
    memory(_ds, _si + 29) += 1;                 //inc byte ptr [si+1Dh]
loc_2D0FF:                                      //loc_2D0FF:
    if (_bl > 0x04)                             //ja short loc_2D123
      goto loc_2D123;
    memory(_cs, 0xF4) = 2;                      //mov cs:byte_2AD14, 2
    memory(_ds, _si + 21) = 0;                  //mov byte ptr [si+15h], 0
    _dl = _bl;                                  //mov dl, bl
    _dl += 1;                                   //inc dl
    memory(_ds, _si + 29) += 1;                 //inc byte ptr [si+1Dh]
    memory(_ds, _si + 26) = 0;                  //mov byte ptr [si+1Ah], 0
    memory(_ds, _si + 27) = 1;                  //mov byte ptr [si+1Bh], 1
    memory(_ds, _si + 24) = _al;                //mov [si+18h], al
    memory(_ds, _si + 25) = _dl;                //mov [si+19h], dl
loc_2D123:                                      //loc_2D123:
    sub_2D16D();                                //call sub_2D16D
    if (memory(_ds, _si + 1) == 0xc4)           //jz short loc_2D131
      goto loc_2D131;
    sub_2CF36();                                //call sub_2CF36
    _flags.carry = false;                       //clc
    return;                                     //retn
loc_2D131:                                      //loc_2D131:
    if (memory(_ds, 0x2E81) == 1)               //jz short loc_2D150
      goto loc_2D150;
    _bl = memory(_ds, _si);                     //mov bl, [si]
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    memory(_ds, _si + 28) = 0;                  //mov byte ptr [si+1Ch], 0
    _bp = _si;                                  //mov bp, si
    _si += 0x0004;                              //add si, 4
    sub_2D4A1();                                //call sub_2D4A1
    _si = _bp;                                  //mov si, bp
    memory(_ds, 0x2E73) -= 1;                   //dec byte ptr ds:2E73h
    return;                                     //retn
loc_2D150:                                      //loc_2D150:
    memory(_cs, 0xF4) = 2;                      //mov cs:byte_2AD14, 2
    _al = memory(_ds, _si);                     //mov al, [si]
    memory(_ds, _si + 24) = _al;                //mov [si+18h], al
    memory(_ds, _si + 25) = 0xc3;               //mov byte ptr [si+19h], 0C3h
    memory(_ds, _si + 21) = 1;                  //mov byte ptr [si+15h], 1
    memory(_ds, _si + 26) = 1;                  //mov byte ptr [si+1Ah], 1
    memory(_ds, _si + 27) = 1;                  //mov byte ptr [si+1Bh], 1
    _flags.carry = false;                       //clc
}

void sub_2D3F7()
{
    _ch = memory(_ds, _si + 26);                //mov ch, [si+1Ah]
    _cl = memory(_ds, _si + 27);                //mov cl, [si+1Bh]
    _al = memory(_ds, _si + 23);                //mov al, [si+17h]
    if (_al < memory(_ds, _si + 22))            //jb short loc_2D418
      goto loc_2D418;
    _al = _ch;                                  //mov al, ch
    _bl = memory(_ds, _si + 22);                //mov bl, [si+16h]
    _ax = _bl * _al;                            //mul bl
    _bl = memory(_ds, _si + 23);                //mov bl, [si+17h]
    _div(_bl);                                  //div bl
    _bl = _ch;                                  //mov bl, ch
    memory(_ds, _si + 26) += 1;                 //inc byte ptr [si+1Ah]
    goto loc_2D42B;                             //jmp short loc_2D42B
loc_2D418:                                      //loc_2D418:
    _al = _cl;                                  //mov al, cl
    _bl = memory(_ds, _si + 23);                //mov bl, [si+17h]
    _ax = _bl * _al;                            //mul bl
    _bl = memory(_ds, _si + 22);                //mov bl, [si+16h]
    _div(_bl);                                  //div bl
    _bl = _al;                                  //mov bl, al
    _al = _cl;                                  //mov al, cl
    memory(_ds, _si + 27) += 1;                 //inc byte ptr [si+1Bh]
loc_2D42B:                                      //loc_2D42B:
    if (memory(_ds, _si + 20) == 0)             //jz short loc_2D433
      goto loc_2D433;
    _bl = -_bl;                                 //neg bl
loc_2D433:                                      //loc_2D433:
    if (memory(_ds, _si + 21) == 0)             //jz short loc_2D43B
      goto loc_2D43B;
    _al = -_al;                                 //neg al
loc_2D43B:                                      //loc_2D43B:
    _bl = _bl + memory(_ds, _si + 24);          //add bl, [si+18h]
    memory(_ds, _si) = _bl;                     //mov [si], bl
    _al = _al + memory(_ds, _si + 25);          //add al, [si+19h]
    memory(_ds, _si + 1) = _al;                 //mov [si+1], al
}

void sub_2D447()
{
    _bp = _si;                                  //mov bp, si
    _si += 0x0004;                              //add si, 4
    _di = _bp;                                  //mov di, bp
    _di += 0x0c;                                //add di, 0Ch
    _cx = 0x0004;                               //mov cx, 4
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _si = 0x48fb;                               //mov si, 48FBh
    _di = _bp;                                  //mov di, bp
    _di += 0x0004;                              //add di, 4
    _cx = 0x0004;                               //mov cx, 4
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _si = _bp;                                  //mov si, bp
    _dl = memory(_ds, _si);                     //mov dl, [si]
    _dl &= 0x03;                                //and dl, 3
    if (_dl == 0)                               //jz short loc_2D47F
      goto loc_2D47F;
    _dl <<= 1;                                  //shl dl, 1
    _dh = 0x04;                                 //mov dh, 4
    _di = _bp;                                  //mov di, bp
    _di += 0x0004;                              //add di, 4
loc_2D475:                                      //loc_2D475:
    _cl = _dl;                                  //mov cl, dl
    _ror(memory16(_ds, _di), _cl);              //ror word ptr [di], cl
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _dh -= 1;                                   //dec dh
    if (_dh != 0)                               //jnz short loc_2D475
      goto loc_2D475;
loc_2D47F:                                      //loc_2D47F:
    _bl = memory(_ds, _si + 2);                 //mov bl, [si+2]
    _al = memory(_ds, _si + 3);                 //mov al, [si+3]
    _si += 0x0c;                                //add si, 0Ch
    sub_2D4A1();                                //call sub_2D4A1
    _si = _bp;                                  //mov si, bp
    _bl = memory(_ds, _si);                     //mov bl, [si]
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    memory(_ds, _si + 2) = _bl;                 //mov [si+2], bl
    memory(_ds, _si + 3) = _al;                 //mov [si+3], al
    _si += 0x0004;                              //add si, 4
    sub_2D4A1();                                //call sub_2D4A1
    _si = _bp;                                  //mov si, bp
}

void sub_2D4A1()
{
    _flags.interrupt = false;                   //cli
    _dx = _es;                                  //mov dx, es
    _cx = 0xb800;                               //mov cx, 0B800h
    _es = _cx;                                  //mov es, cx
    _bh = _bh ^ _bh;                            //xor bh, bh
    _di = _bx;                                  //mov di, bx
    _di >>= 1;                                  //shr di, 1
    _di >>= 1;                                  //shr di, 1
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (!_flags.carry)                          //jnb short loc_2D4B9
      goto loc_2D4B9;
    _di += 0x2000;                              //add di, 2000h
loc_2D4B9:                                      //loc_2D4B9:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _cx = 0x0004;                               //mov cx, 4
loc_2D4CE:                                      //loc_2D4CE:
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memoryVideoXor16(_es, _di, _ax);//xor es:[di], ax
    if (_di < 0x2000)                           //jb short loc_2D4E1
      goto loc_2D4E1;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    if (--_cx)                                  //loop loc_2D4CE
      goto loc_2D4CE;
    _es = _dx;                                  //mov es, dx
    return;                                     //retn
loc_2D4E1:                                      //loc_2D4E1:
    _di += 0x2000;                              //add di, 2000h
    if (--_cx)                                  //loop loc_2D4CE
      goto loc_2D4CE;
    _es = _dx;                                  //mov es, dx
    _flags.interrupt = true;                    //sti
}

void sub_2DA3E()
{
    WORD _cs = _seg004;
    if (memory(_ds, 0x2D3B) == 0)               //jz short loc_2DA47
      goto loc_2DA47;
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_2DA47:                                      //loc_2DA47:
    if (memory16(_ds, 0x2E76) != 560)           //jnz short loc_2DAA3
      goto loc_2DAA3;
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    if (_al >= 0xb5)                            //jnb short loc_2DA5E
      goto loc_2DA5E;
loc_2DA56:                                      //loc_2DA56:
    memory16(_ds, 0x2E76) = 560;                //mov word ptr ds:2E76h, 230h
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_2DA5E:                                      //loc_2DA5E:
    if (_al > 0xbe)                             //ja short loc_2DA56
      goto loc_2DA56;
    _ah = memory(_ds, 0x2E54);                  //mov ah, ds:2E54h
    _ah -= 0x03;                                //sub ah, 3
    _bl = memory(_ds, _si);                     //mov bl, [si]
    if (_bl < _ah)                              //jb short loc_2DA56
      goto loc_2DA56;
    _bl -= _ah;                                 //sub bl, ah
    _ah = memory(_ds, 0x2D3A);                  //mov ah, ds:2D3Ah
    _ah += 0x03;                                //add ah, 3
    if (_bl > _ah)                              //ja short loc_2DA56
      goto loc_2DA56;
    memory(_ds, _si + 1) = 0xb5;                //mov byte ptr [si+1], 0B5h
    memory(_ds, _si + 28) = 2;                  //mov byte ptr [si+1Ch], 2
    _al = memory(_ds, 0x1486);                  //mov al, ds:1486h
    _ah = _ah ^ _ah;                            //xor ah, ah
    memory16(_ds, 0x2E76) -= _ax;               //sub ds:2E76h, ax
    _al = memory(_ds, _si);                     //mov al, [si]
    _al = _al - memory(_ds, 0x2E54);            //sub al, ds:2E54h
    memory(_ds, 0x2E56) = _al;                  //mov ds:2E56h, al
    _push(_si);                                 //push si
    sub_2D447();                                //call sub_2D447
    _si = _pop();                               //pop si
    memory(_cs, 0xF4) = 7;                      //mov cs:byte_2AD14, 7
    _flags.carry = false;                       //clc
    return;                                     //retn
loc_2DAA3:                                      //loc_2DAA3:
    if (memory(_ds, _si + 28) == 2)             //jz short loc_2DAAB
      goto loc_2DAAB;
    _flags.carry = true;                        //stc
    return;                                     //retn
loc_2DAAB:                                      //loc_2DAAB:
    if (memory(_ds, 0x2D4C) == 1)               //jz short loc_2DAD9
      goto loc_2DAD9;
    memory16(_ds, 0x2E76) -= 1;                 //dec word ptr ds:2E76h
    if (memory16(_ds, 0x2E76) == 0)             //jz short loc_2DAD9
      goto loc_2DAD9;
    _al = memory(_ds, 0x1486);                  //mov al, ds:1486h
    _al -= 1;                                   //dec al
    if (_al != memory(_ds, 0x1485))             //jnz short loc_2DAC9
      goto loc_2DAC9;
    memory16(_ds, 0x2E76) -= 1;                 //dec word ptr ds:2E76h
    if (memory16(_ds, 0x2E76) == 0)             //jz short loc_2DAD9
      goto loc_2DAD9;
loc_2DAC9:                                      //loc_2DAC9:
    _al = memory(_ds, 0x2E54);                  //mov al, ds:2E54h
    _al = _al + memory(_ds, 0x2E56);            //add al, ds:2E56h
    memory(_ds, _si) = _al;                     //mov [si], al
    _push(_si);                                 //push si
    sub_2D447();                                //call sub_2D447
    _si = _pop();                               //pop si
    _flags.carry = false;                       //clc
    return;                                     //retn
loc_2DAD9:                                      //loc_2DAD9:
    memory16(_ds, 0x2E76) = 560;                //mov word ptr ds:2E76h, 230h
    sub_2D09F();                                //call sub_2D09F
    memory(_ds, _si + 21) = 1;                  //mov byte ptr [si+15h], 1
    memory(_ds, _si + 1) = 0xb4;                //mov byte ptr [si+1], 0B4h
    _al = memory(_ds, _si);                     //mov al, [si]
    memory(_ds, _si + 24) = _al;                //mov [si+18h], al
    memory(_ds, _si + 25) = 0xb4;               //mov byte ptr [si+19h], 0B4h
    memory16(_ds, _si + 26) = 0;                //mov word ptr [si+1Ah], 0
    memory(_ds, _si + 28) = 1;                  //mov byte ptr [si+1Ch], 1
    _push(_si);                                 //push si
    sub_2D447();                                //call sub_2D447
    _si = _pop();                               //pop si
    _flags.carry = true;                        //stc
}

void sub_2DB03()
{
    WORD _cs = _seg004;
    if (memory(_ds, 0x2D3B) != 0)               //jnz short locret_2DB1B
      goto locret_2DB1B;
    if (memory(_ds, 0x2E7E) != 2)               //jnz short loc_2DB14
      goto loc_2DB14;
    goto loc_2DB9F;                             //jmp loc_2DB9F
loc_2DB14:                                      //loc_2DB14:
    if (memory(_ds, 0x2D4C) == 1)               //jz short loc_2DB1C
      goto loc_2DB1C;
locret_2DB1B:                                   //locret_2DB1B:
    return;                                     //retn
loc_2DB1C:                                      //loc_2DB1C:
    _bl = memory(_ds, 0x2E54);                  //mov bl, ds:2E54h
    _bl += 0x04;                                //add bl, 4
    memory(_cs, 0xF4) = 5;                      //mov cs:byte_2AD14, 5
    memory(_ds, 0x2E80) = _bl;                  //mov ds:2E80h, bl
    _al = memory(_ds, 0x2E7F);                  //mov al, ds:2E7Fh
    _bp = _bx;                                  //mov bp, bx
    _si = _ax;                                  //mov si, ax
    sub_2DCFD();                                //call sub_2DCFD
    _push(_es);                                 //push es
    _dx = 0xb800;                               //mov dx, 0B800h
    _es = _dx;                                  //mov es, dx
    if (_di < 0x2000)                           //jb short loc_2DB49
      goto loc_2DB49;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2DB4D;                             //jmp short loc_2DB4D
loc_2DB49:                                      //loc_2DB49:
    _di += 0x2000;                              //add di, 2000h
loc_2DB4D:                                      //loc_2DB4D:
    memory(_es, _di) = memory(_es, _di) ^ _al;  //xor es:[di], al
    if (_di < 0x2000)                           //jb short loc_2DB5C
      goto loc_2DB5C;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2DB60;                             //jmp short loc_2DB60
loc_2DB5C:                                      //loc_2DB5C:
    _di += 0x2000;                              //add di, 2000h
loc_2DB60:                                      //loc_2DB60:
    memory(_es, _di) = memory(_es, _di) ^ _al;  //xor es:[di], al
    _ax = _si;                                  //mov ax, si
    _bx = _bp;                                  //mov bx, bp
    _bl += 0x13;                                //add bl, 13h
    sub_2DCFD();                                //call sub_2DCFD
    if (_di < 0x2000)                           //jb short loc_2DB79
      goto loc_2DB79;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2DB7D;                             //jmp short loc_2DB7D
loc_2DB79:                                      //loc_2DB79:
    _di += 0x2000;                              //add di, 2000h
loc_2DB7D:                                      //loc_2DB7D:
    memory(_es, _di) = memory(_es, _di) ^ _al;  //xor es:[di], al
    if (_di < 0x2000)                           //jb short loc_2DB8C
      goto loc_2DB8C;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2DB90;                             //jmp short loc_2DB90
loc_2DB8C:                                      //loc_2DB8C:
    _di += 0x2000;                              //add di, 2000h
loc_2DB90:                                      //loc_2DB90:
    memory(_es, _di) = memory(_es, _di) ^ _al;  //xor es:[di], al
    _es = _pop();                               //pop es
    memory(_ds, 0x2E7F) = 0xb1;                 //mov byte ptr ds:2E7Fh, 0B1h
    memory(_ds, 0x2E7E) = 2;                    //mov byte ptr ds:2E7Eh, 2
    return;                                     //retn
loc_2DB9F:                                      //loc_2DB9F:
    _bl = memory(_ds, 0x2E80);                  //mov bl, ds:2E80h
    _al = memory(_ds, 0x2E7F);                  //mov al, ds:2E7Fh
    _si = _ax;                                  //mov si, ax
    _bp = _bx;                                  //mov bp, bx
    _push(_es);                                 //push es
    _dx = 0xb800;                               //mov dx, 0B800h
    _es = _dx;                                  //mov es, dx
    sub_2DCFD();                                //call sub_2DCFD
    if (_di < 0x2000)                           //jb short loc_2DBBF
      goto loc_2DBBF;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2DBC3;                             //jmp short loc_2DBC3
loc_2DBBF:                                      //loc_2DBBF:
    _di += 0x2000;                              //add di, 2000h
loc_2DBC3:                                      //loc_2DBC3:
    memory(_es, _di) = memory(_es, _di) ^ _al;  //xor es:[di], al
    _di += 0x50;                                //add di, 50h
    memory(_es, _di) = memory(_es, _di) ^ _al;  //xor es:[di], al
    if (_di < 0x2000)                           //jb short loc_2DBD8
      goto loc_2DBD8;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2DBDC;                             //jmp short loc_2DBDC
loc_2DBD8:                                      //loc_2DBD8:
    _di += 0x2000;                              //add di, 2000h
loc_2DBDC:                                      //loc_2DBDC:
    memory(_es, _di) = memory(_es, _di) ^ _al;  //xor es:[di], al
    _ax = _si;                                  //mov ax, si
    _bx = _bp;                                  //mov bx, bp
    _bl += 0x13;                                //add bl, 13h
    sub_2DCFD();                                //call sub_2DCFD
    if (_di < 0x2000)                           //jb short loc_2DBF5
      goto loc_2DBF5;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2DBF9;                             //jmp short loc_2DBF9
loc_2DBF5:                                      //loc_2DBF5:
    _di += 0x2000;                              //add di, 2000h
loc_2DBF9:                                      //loc_2DBF9:
    memory(_es, _di) = memory(_es, _di) ^ _al;  //xor es:[di], al
    _di += 0x50;                                //add di, 50h
    memory(_es, _di) = memory(_es, _di) ^ _al;  //xor es:[di], al
    if (_di < 0x2000)                           //jb short loc_2DC0E
      goto loc_2DC0E;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2DC12;                             //jmp short loc_2DC12
loc_2DC0E:                                      //loc_2DC0E:
    _di += 0x2000;                              //add di, 2000h
loc_2DC12:                                      //loc_2DC12:
    memory(_es, _di) = memory(_es, _di) ^ _al;  //xor es:[di], al
    _es = _pop();                               //pop es
    memory(_ds, 0x2E7F) -= 1;                   //dec byte ptr ds:2E7Fh
    memory(_ds, 0x2E7F) -= 1;                   //dec byte ptr ds:2E7Fh
    _ax = _si;                                  //mov ax, si
    if (_al < 0x04)                             //jb short loc_2DC80
      goto loc_2DC80;
    _ax = _si;                                  //mov ax, si
    _bx = _bp;                                  //mov bx, bp
    _xchg(_bl, _al);                            //xchg bl, al
    _al -= 0x08;                                //sub al, 8
    _bl -= 0x06;                                //sub bl, 6
    memory(_ds, 0x2E74) = 0;                    //mov byte ptr ds:2E74h, 0
    _si = 0x2e89;                               //mov si, 2E89h
    sub_2D375();                                //call sub_2D375
    _al += 0x13;                                //add al, 13h
    sub_2D375();                                //call sub_2D375
    if (memory(_ds, 0x2E74) == 0)               //jz short locret_2DC7F
      goto locret_2DC7F;
    _bp = 0x0000;                               //mov bp, 0
    _cl = 0x02;                                 //mov cl, 2
    _si = 0x2e89;                               //mov si, 2E89h
loc_2DC4E:                                      //loc_2DC4E:
    _push(_cx);                                 //push cx
    _push(_si);                                 //push si
    if (memory16(_ds, _si) == 0)                //jz short loc_2DC63
      goto loc_2DC63;
    _di = memory16(_ds, _si);                   //mov di, [si]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bl = memory(_ds, _di);                     //mov bl, [di]
    _bl <<= 1;                                  //shl bl, 1
    _bx += 0x3044;                              //add bx, 3044h
    _STOP_("call word ptr [bx]");               //call word ptr [bx]
loc_2DC63:                                      //loc_2DC63:
    _si = _pop();                               //pop si
    _cx = _pop();                               //pop cx
    _si += 0x0004;                              //add si, 4
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2DC4E
      goto loc_2DC4E;
    _al = memory(_ds, 0x2E7F);                  //mov al, ds:2E7Fh
    _al += 1;                                   //inc al
    _al += 1;                                   //inc al
    _bl = memory(_ds, 0x2E80);                  //mov bl, ds:2E80h
    sub_2DC8B();                                //call sub_2DC8B
    memory(_ds, 0x2E7F) = 0xb3;                 //mov byte ptr ds:2E7Fh, 0B3h
locret_2DC7F:                                   //locret_2DC7F:
    return;                                     //retn
loc_2DC80:                                      //loc_2DC80:
    _bx = _bp;                                  //mov bx, bp
    sub_2DC8B();                                //call sub_2DC8B
    memory(_ds, 0x2E7F) = 0xb3;                 //mov byte ptr ds:2E7Fh, 0B3h
}

void sub_2DD66()
{
    _push(_es);                                 //push es
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _di = 0x3ef2;                               //mov di, 3EF2h
    _cx = 0x18;                                 //mov cx, 18h
loc_2DD72:                                      //loc_2DD72:
    memory16(_es, _di) = memory16(_es, _di) ^ _dx;//xor es:[di], dx
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_2DD72
      goto loc_2DD72;
    _es = _pop();                               //pop es
}

void sub_2DE52()
{
    _si = memory16(_ds, 0x3138);                //mov si, ds:3138h
    _dx = memory16(_ds, _si + 12);              //mov dx, [si+0Ch]
    memory16(_ds, 0x3138) = _dx;                //mov ds:3138h, dx
    _push(_bx);                                 //push bx
    _bx = 0x3138;                               //mov bx, 3138h
loc_2DE61:                                      //loc_2DE61:
    if (memory16(_ds, _bx + 12) == 0xffff)      //jz short loc_2DE6D
      goto loc_2DE6D;
    _bx = memory16(_ds, _bx + 12);              //mov bx, [bx+0Ch]
    goto loc_2DE61;                             //jmp short loc_2DE61
loc_2DE6D:                                      //loc_2DE6D:
    memory16(_ds, _si + 12) = 0xffff;           //mov word ptr [si+0Ch], 0FFFFh
    memory16(_ds, _bx + 12) = _si;              //mov [bx+0Ch], si
    _bx = _pop();                               //pop bx
}

void sub_2DE77()
{
    _dx = memory16(_ds, _bx + 12);              //mov dx, [bx+0Ch]
    _si = memory16(_ds, 0x3142);                //mov si, ds:3142h
    memory16(_ds, _si + 12) = _dx;              //mov [si+0Ch], dx
    _dx = memory16(_ds, 0x3138);                //mov dx, ds:3138h
    memory16(_ds, _bx + 12) = _dx;              //mov [bx+0Ch], dx
    memory16(_ds, 0x3138) = _bx;                //mov ds:3138h, bx
    memory(_ds, 0x313A) = 0;                    //mov byte ptr ds:313Ah, 0
}

void sub_2E288()
{
    _di = memory16(_ds, _bx + 2);               //mov di, [bx+2]
    memory(_ds, _di) = 3;                       //mov byte ptr [di], 3
locret_2E28E:                                   //locret_2E28E:
    return;
}

void sub_2E31B()
{
    _cl = memory(_ds, 0x2F11);                  //mov cl, ds:2F11h
    _si = 0x2f12;                               //mov si, 2F12h
loc_2E322:                                      //loc_2E322:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _ah = _ah ^ _ah;                            //xor ah, ah
    _di = 0x2f18;                               //mov di, 2F18h
    _di += _ax;                                 //add di, ax
    memory(_ds, _di) = 9;                       //mov byte ptr [di], 9
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2E322
      goto loc_2E322;
    memory(_ds, 0x313A) = 1;                    //mov byte ptr ds:313Ah, 1
locret_2E336:                                   //locret_2E336:
    return;
}

void sub_2E9B5()
{
    _dl = 0x04;                                 //mov dl, 4
    sub_2ECE0();                                //call sub_2ECE0
    _al = _ah;                                  //mov al, ah
    _ah = _ah ^ _ah;                            //xor ah, ah
    _al <<= 1;                                  //shl al, 1
    _al <<= 1;                                  //shl al, 1
    _si = _ax;                                  //mov si, ax
    _si += 0x33d7;                              //add si, 33D7h
    _ASSERT(0);
//    if (memory(_ds, _si + 3) != 0)              //jnz short nullsub_1
//      goto nullsub_1;
    _al = memory(_ds, _si + 2);                 //mov al, [si+2]
    _di = _ax;                                  //mov di, ax
    _di += 0x2f18;                              //add di, 2F18h
    _ASSERT(0);
//    if (memory(_ds, _di) != 0)                  //jnz short nullsub_1
//      goto nullsub_1;
//    if (memory(_ds, _di + 12) != 0)             //jnz short nullsub_1
//      goto nullsub_1;
    memory(_ds, _si + 3) = 1;                   //mov byte ptr [si+3], 1
    memory(_ds, 0x33D5) += 1;                   //inc byte ptr ds:33D5h
    _di = _si;                                  //mov di, si
    sub_2DE52();                                //call sub_2DE52
    _cl = memory(_ds, _di);                     //mov cl, [di]
    _al = memory(_ds, _di + 1);                 //mov al, [di+1]
    memory16(_ds, _si) = 14605;                 //mov word ptr [si], 390Dh
    memory16(_ds, _si + 2) = _di;               //mov [si+2], di
    memory(_ds, _si + 4) = _cl;                 //mov [si+4], cl
    memory(_ds, _si + 5) = _al;                 //mov [si+5], al
    memory16(_ds, _si + 6) = 0;                 //mov word ptr [si+6], 0
    memory16(_ds, _si + 8) = 700;               //mov word ptr [si+8], 2BCh
    memory16(_ds, _si + 10) = 24654;            //mov word ptr [si+0Ah], 604Eh
}

void sub_2EDF4()
{
    _di = 0x1a77;                               //mov di, 1A77h
    _ax = _ax ^ _ax;                            //xor ax, ax
    sub_2EDD1();                                //call sub_2EDD1
    _di = 0x1a8b;                               //mov di, 1A8Bh
    _ax = _ax ^ _ax;                            //xor ax, ax
    sub_2EDD1();                                //call sub_2EDD1
}

void sub_2F54F()
{
    _si = 0x4890;                               //mov si, 4890h
    _dl = 0x09;                                 //mov dl, 9
loc_2F554:                                      //loc_2F554:
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_es, _di) = memory16(_es, _di) ^ _ax;//xor es:[di], ax
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_es, _di + 2) = memory16(_es, _di + 2) ^ _ax;
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    memory(_es, _di + 4) = memory(_es, _di + 4) ^ _al;
    if (_di < 0x2000)                           //jb short loc_2F56E
      goto loc_2F56E;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2F572;                             //jmp short loc_2F572
loc_2F56E:                                      //loc_2F56E:
    _di += 0x2000;                              //add di, 2000h
loc_2F572:                                      //loc_2F572:
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2F554
      goto loc_2F554;
}

void sub_2F577()
{
    _ax = _ax ^ _ax;                            //xor ax, ax
    _dl = 0x04;                                 //mov dl, 4
loc_2F57B:                                      //loc_2F57B:
    memory16(_es, _di) = memory16(_es, _di) ^ _ax;//xor es:[di], ax
    memory16(_es, _di + 2) = memory16(_es, _di + 2) ^ _ax;
    memory(_es, _di + 4) = memory(_es, _di + 4) ^ _al;
    if (_di < 0x2000)                           //jb short loc_2F592
      goto loc_2F592;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2F596;                             //jmp short loc_2F596
loc_2F592:                                      //loc_2F592:
    _di += 0x2000;                              //add di, 2000h
loc_2F596:                                      //loc_2F596:
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2F57B
      goto loc_2F57B;
    _ax = 0x5555;                               //mov ax, 5555h
    memory16(_es, _di) = memory16(_es, _di) ^ _ax;//xor es:[di], ax
    memory16(_es, _di + 2) = memory16(_es, _di + 2) ^ _ax;
    memory(_es, _di + 4) = memory(_es, _di + 4) ^ _al;
    if (_di < 0x2000)                           //jb short loc_2F5B4
      goto loc_2F5B4;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2F5B8;                             //jmp short loc_2F5B8
loc_2F5B4:                                      //loc_2F5B4:
    _di += 0x2000;                              //add di, 2000h
loc_2F5B8:                                      //loc_2F5B8:
    _ax = _ax ^ _ax;                            //xor ax, ax
    _dl = 0x04;                                 //mov dl, 4
loc_2F5BC:                                      //loc_2F5BC:
    memory16(_es, _di) = memory16(_es, _di) ^ _ax;//xor es:[di], ax
    memory16(_es, _di + 2) = memory16(_es, _di + 2) ^ _ax;
    memory(_es, _di + 4) = memory(_es, _di + 4) ^ _al;
    if (_di < 0x2000)                           //jb short loc_2F5D3
      goto loc_2F5D3;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2F5D7;                             //jmp short loc_2F5D7
loc_2F5D3:                                      //loc_2F5D3:
    _di += 0x2000;                              //add di, 2000h
loc_2F5D7:                                      //loc_2F5D7:
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2F5BC
      goto loc_2F5BC;
}

void sub_2F79A()
{
    WORD _cs = _seg004;
    _dx = 0x03d0;                               //mov dx, 3D0h
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cx = 0x0c;                                 //mov cx, 0Ch
loc_2F7A2:                                      //loc_2F7A2:
    _al = _ah;                                  //mov al, ah
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _ah += 1;                                   //inc ah
    _al = memory16(_cs, _si);                   //mov al, cs:[si]
    _out(_dx, _al);                             //out dx, al
    _si += 1;                                   //inc si
    _dx -= 1;                                   //dec dx
    if (--_cx)                                  //loop loc_2F7A2
      goto loc_2F7A2;
}

void sub_2F957()
{
    _dl = memory(_ds, 0x3F08);                  //mov dl, ds:3F08h
    _di = 0x3ef6;                               //mov di, 3EF6h
    _si = 0x1aef;                               //mov si, 1AEFh
    _dh = 0x0a;                                 //mov dh, 0Ah
loc_2F963:                                      //loc_2F963:
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _bp = _si;                                  //mov bp, si
    sub_2F97D();                                //call sub_2F97D
    _si = _bp;                                  //mov si, bp
    _cx = 0x0009;                               //mov cx, 9
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _si = _bp;                                  //mov si, bp
    _si += 0x12;                                //add si, 12h
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2F963
      goto loc_2F963;
}

void sub_2F9DB()
{
    _al = memory(_ds, 0x141B);                  //mov al, ds:141Bh
    sub_2FA24();                                //call sub_2FA24
    if (_FIXME_)                                //jnb short loc_2F9E4
      goto loc_2F9E4;
locret_2F9E3:                                   //locret_2F9E3:
    return;                                     //retn
loc_2F9E4:                                      //loc_2F9E4:
    _ah = 0x3d;                                 //mov ah, 3Dh
    _al = 0x01;                                 //mov al, 1
    _dx = 0x141c;                               //mov dx, 141Ch
    _interrupt(0x21);                           //int 21h
    if (_flags.carry)                           //jb short locret_2F9E3
      goto locret_2F9E3;
    _bx = _ax;                                  //mov bx, ax
    _ah = 0x42;                                 //mov ah, 42h
    _al = 0x00;                                 //mov al, 0
    _cx = _cx ^ _cx;                            //xor cx, cx
    _dx = _dx ^ _dx;                            //xor dx, dx
    _interrupt(0x21);                           //int 21h
    _ah = 0x40;                                 //mov ah, 40h
    _dx = 0x3e42;                               //mov dx, 3E42h
    _cx = 0xb4;                                 //mov cx, 0B4h
    _interrupt(0x21);                           //int 21h
    _ah = 0x3e;                                 //mov ah, 3Eh
    _interrupt(0x21);                           //int 21h
}

void sub_2FA0A()
{
    _push(_bp);                                 //push bp
    _push(_ax);                                 //push ax
    _ah = 0x00;                                 //mov ah, 0
    _interrupt(0x13);                           //int 13h
    _ah = 0x0d;                                 //mov ah, 0Dh
    _interrupt(0x21);                           //int 21h
    _ax = _pop();                               //pop ax
    _push(_ax);                                 //push ax
    _dx = _dx ^ _dx;                            //xor dx, dx
    _cx = 0x0001;                               //mov cx, 1
    _bx = 0x0000;                               //mov bx, 0
    _interrupt(0x25);                           //int 25h
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
    _bp = _pop();                               //pop bp
    return;                                     //retn
    _STOP_("sp-trace-fail");                    //sub_2FA0A endp_failed
    _STOP_("continues");                        //sub_2FA24 proc near
}

void sub_2FB78()
{
    WORD _cs = _seg004;
    _si = 0x507d;                               //mov si, 507Dh
    _dh = 0x0e;                                 //mov dh, 0Eh
loc_2FB7D:                                      //loc_2FB7D:
    _di = memory16(_cs, _si);                   //mov di, cs:[si]
    sub_2FC11();                                //call sub_2FC11
    sub_2FBC7();                                //call sub_2FBC7
    sub_2FBF3();                                //call sub_2FBF3
    memory16(_cs, _si) = _di;                   //mov cs:[si], di
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    _dh -= 1;                                   //dec dh
    if (_dh != 0)                               //jnz short loc_2FB7D
      goto loc_2FB7D;
}

void sub_2FB93()
{
    WORD _cs = _seg004;
    _di = _di ^ _di;                            //xor di, di
    sub_2FC39();                                //call sub_2FC39
    _di = 0x1e00;                               //mov di, 1E00h
    sub_2FC39();                                //call sub_2FC39
    _di = 0x0140;                               //mov di, 140h
    sub_2FC65();                                //call sub_2FC65
    _di = 0x0172;                               //mov di, 172h
    sub_2FC65();                                //call sub_2FC65
    _di = _di ^ _di;                            //xor di, di
    _si = 0x507d;                               //mov si, 507Dh
    _cl = 0x0e;                                 //mov cl, 0Eh
loc_2FBB1:                                      //loc_2FBB1:
    memory16(_cs, _si) = _di;                   //mov cs:[si], di
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    sub_2FBF3();                                //call sub_2FBF3
    _ch = 0x07;                                 //mov ch, 7
loc_2FBBB:                                      //loc_2FBBB:
    sub_2FBC7();                                //call sub_2FBC7
    _ch -= 1;                                   //dec ch
    if (_ch != 0)                               //jnz short loc_2FBBB
      goto loc_2FBBB;
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2FBB1
      goto loc_2FBB1;
}

void sub_2FD60()
{
    BYTE t = 0;
    
    _ch = 0x06;                                 //mov ch, 6
    _di = 0x38a9;                               //mov di, 38A9h
loc_2FD65:                                      //loc_2FD65:
    _cl = 0x02;                                 //mov cl, 2
loc_2FD67:                                      //loc_2FD67:
    _push(_di);                                 //push di
    _flags.carry = true;                        //stc
    memoryVideoShl(_es, _di, 1);                     //shl byte ptr es:[di], 1
    _di -= 1;                                   //dec di
    _bl = 0x0d;                                 //mov bl, 0Dh
loc_2FD6F: //loc_2FD6F:
    t = memoryVideoGet(_es, _di);
    _rcl(t, 1);
    memoryVideoSet(_es, _di, t);
    _di -= 1;                                   //dec di
    _bl -= 1;                                   //dec bl
    if (_bl != 0)                               //jnz short loc_2FD6F
      goto loc_2FD6F;
    _di = _pop();                               //pop di
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2FD67
      goto loc_2FD67;
    if (_di < 0x2000)                           //jb short loc_2FD88
      goto loc_2FD88;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2FD8C;                             //jmp short loc_2FD8C
loc_2FD88:                                      //loc_2FD88:
    _di += 0x2000;                              //add di, 2000h
loc_2FD8C:                                      //loc_2FD8C:
    _ch -= 1;                                   //dec ch
    if (_ch != 0)                               //jnz short loc_2FD65
      goto loc_2FD65;
}

void sub_2FDD6()
{
    _push(_es);                                 //push es
    _push(_ds);                                 //push ds
    _ax = _ds;                                  //mov ax, ds
    _es = _ax;                                  //mov es, ax
    _ax = 0xb800;                               //mov ax, 0B800h
    _ds = _ax;                                  //mov ds, ax
    _di = 0x0000;                               //mov di, 0
    _si = 0x0008;                               //mov si, 8
    _cx = 0x96;                                 //mov cx, 96h
loc_2FDEA:                                      //loc_2FDEA:
    _bp = _cx;                                  //mov bp, cx
    _cx = 0x21;                                 //mov cx, 21h
    _bx = _si;                                  //mov bx, si
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _si = _bx;                                  //mov si, bx
    if (_si < 0x2000)                           //jb short loc_2FE01
      goto loc_2FE01;
    _si -= 0x1fb0;                              //sub si, 1FB0h
    goto loc_2FE05;                             //jmp short loc_2FE05
loc_2FE01:                                      //loc_2FE01:
    _si += 0x2000;                              //add si, 2000h
loc_2FE05:                                      //loc_2FE05:
    _cx = _bp;                                  //mov cx, bp
    if (--_cx)                                  //loop loc_2FDEA
      goto loc_2FDEA;
    _ax = _seg000;                              //mov ax, seg seg000
    _ds = _ax;                                  //mov ds, ax
    memory16(_ds, 0x13C0) = 8;                  //mov word_113C0, 8
    memory16(_ds, 0x13C2) = 0x21;               //mov word_113C2, 21h
    _cx = 0x87;                                 //mov cx, 87h
loc_2FE1D:                                      //loc_2FE1D:
    _push(_cx);                                 //push cx
    _ax = _seg000;                              //mov ax, seg seg000
    _es = _ax;                                  //mov es, ax
    _ds = _ax;                                  //mov ds, ax
    _di = 0x1aef;                               //mov di, 1AEFh
    _si = memory16(_ds, 0x13C2);                //mov si, word_113C2
    _cx = 0x01ef;                               //mov cx, 1EFh
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _si = 0xa6d0;                               //mov si, 0A6D0h
    _di = 0x1aef;                               //mov di, 1AEFh
    _cx = 0x01ef;                               //mov cx, 1EFh
loc_2FE3A:                                      //loc_2FE3A:
    _ah = memory(_ds, _si);                     //mov ah, [si]
    _al = memory(_ds, _di);                     //mov al, [di]
    _bh = _al;                                  //mov bh, al
    _dx = _ax;                                  //mov dx, ax
    _al &= 0xc0;                                //and al, 0C0h
    if (_al != 0)                               //jnz short loc_2FE4D
      goto loc_2FE4D;
    _ah &= 0xc0;                                //and ah, 0C0h
    _bh += _ah;                                 //add bh, ah
    _ah = _dh;                                  //mov ah, dh
loc_2FE4D:                                      //loc_2FE4D:
    _al = _dl;                                  //mov al, dl
    _al &= 0x30;                                //and al, 30h
    if (_al != 0)                               //jnz short loc_2FE5A
      goto loc_2FE5A;
    _ah &= 0x30;                                //and ah, 30h
    _bh += _ah;                                 //add bh, ah
    _ah = _dh;                                  //mov ah, dh
loc_2FE5A:                                      //loc_2FE5A:
    _al = _dl;                                  //mov al, dl
    _al &= 0x0c;                                //and al, 0Ch
    if (_al != 0)                               //jnz short loc_2FE67
      goto loc_2FE67;
    _ah &= 0x0c;                                //and ah, 0Ch
    _bh += _ah;                                 //add bh, ah
    _ah = _dh;                                  //mov ah, dh
loc_2FE67:                                      //loc_2FE67:
    _al = _dl;                                  //mov al, dl
    _al &= 0x03;                                //and al, 3
    if (_al != 0)                               //jnz short loc_2FE72
      goto loc_2FE72;
    _ah &= 0x03;                                //and ah, 3
    _bh += _ah;                                 //add bh, ah
loc_2FE72:                                      //loc_2FE72:
    memory(_ds, _di) = _bh;                     //mov [di], bh
    _di += 1;                                   //inc di
    _si += 1;                                   //inc si
    if (--_cx)                                  //loop loc_2FE3A
      goto loc_2FE3A;
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _di = memory16(_ds, 0x13C0);                //mov di, word_113C0
    _si = memory16(_ds, 0x13C2);                //mov si, word_113C2
    _cx = 0x21;                                 //mov cx, 21h
    _si -= _cx;                                 //sub si, cx
    _bx = _di;                                  //mov bx, di
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di = _bx;                                  //mov di, bx
    if (_di < 0x2000)                           //jb short loc_2FE9C
      goto loc_2FE9C;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2FEA0;                             //jmp short loc_2FEA0
loc_2FE9C:                                      //loc_2FE9C:
    _di += 0x2000;                              //add di, 2000h
loc_2FEA0:                                      //loc_2FEA0:
    memory16(_ds, 0x13C0) = _di;                //mov word_113C0, di
    _si = 0x1aef;                               //mov si, 1AEFh
    _cx = 0x0f;                                 //mov cx, 0Fh
loc_2FEAA:                                      //loc_2FEAA:
    _bp = _cx;                                  //mov bp, cx
    _cx = 0x21;                                 //mov cx, 21h
    _bx = _di;                                  //mov bx, di
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _di = _bx;                                  //mov di, bx
    if (_di < 0x2000)                           //jb short loc_2FEC1
      goto loc_2FEC1;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2FEC5;                             //jmp short loc_2FEC5
loc_2FEC1:                                      //loc_2FEC1:
    _di += 0x2000;                              //add di, 2000h
loc_2FEC5:                                      //loc_2FEC5:
    _cx = _bp;                                  //mov cx, bp
    if (--_cx)                                  //loop loc_2FEAA
      goto loc_2FEAA;
    memory16(_ds, 0x13C2) += 0x21;              //add word_113C2, 21h
    _cx = _pop();                               //pop cx
    _cx -= 1;                                   //dec cx
    if (_cx == 0)                               //jz short loc_2FED5
      goto loc_2FED5;
    goto loc_2FE1D;                             //jmp loc_2FE1D
loc_2FED5:                                      //loc_2FED5:
    _cx = 0x1c20;                               //mov cx, 1C20h
loc_2FED8:                                      //loc_2FED8:
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(0x16);                           //int 16h
    if (_flags.zero)                            //jz short loc_2FEE5
      goto loc_2FEE5;
    _ah = 0x00;                                 //mov ah, 0
    _interrupt(0x16);                           //int 16h
    goto loc_2FF34;                             //jmp loc_2FF34
loc_2FEE5:                                      //loc_2FEE5:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2FED8
      goto loc_2FED8;
    _ds = _pop();                               //pop ds
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _bx = 0xa8bf;                               //mov bx, 0A8BFh
    _di = 0x34f0;                               //mov di, 34F0h
    _dh = 0x07;                                 //mov dh, 7
loc_2FEF8:                                      //loc_2FEF8:
    _push(_di);                                 //push di
    _di = _di + memory16(_ds, _bx);             //add di, [bx]
    _bp = _di;                                  //mov bp, di
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _si = memory16(_ds, _bx);                   //mov si, [bx]
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    sub_2FFAD();                                //call sub_2FFAD
    if (_FIXME_)                                //jb short loc_2FF2C
      goto loc_2FF2C;
    _di = _bp;                                  //mov di, bp
    sub_2FFAD();                                //call sub_2FFAD
    _di = _bp;                                  //mov di, bp
    _si = 0xabab;                               //mov si, 0ABABh
    sub_2FFAD();                                //call sub_2FFAD
    if (_FIXME_)                                //jb short loc_2FF2C
      goto loc_2FF2C;
    _di = _bp;                                  //mov di, bp
    sub_2FFAD();                                //call sub_2FFAD
    if (_FIXME_)                                //jb short loc_2FF2C
      goto loc_2FF2C;
    _di = _bp;                                  //mov di, bp
    sub_2FFAD();                                //call sub_2FFAD
    if (_FIXME_)                                //jb short loc_2FF2C
      goto loc_2FF2C;
    _di = _pop();                               //pop di
    _dh -= 1;                                   //dec dh
    if (_dh == 0)                               //jz short loc_2FF2D
      goto loc_2FF2D;
    goto loc_2FEF8;                             //jmp short loc_2FEF8
loc_2FF2C:                                      //loc_2FF2C:
    _di = _pop();                               //pop di
loc_2FF2D:                                      //loc_2FF2D:
    if (_FIXME_)                                //jb short loc_2FF32
      goto loc_2FF32;
    sub_2FF37();                                //call sub_2FF37
loc_2FF32:                                      //loc_2FF32:
    _es = _pop();                               //pop es
    return;                                     //retn
loc_2FF34:                                      //loc_2FF34:
    _ds = _pop();                               //pop ds
    _es = _pop();                               //pop es
}

void sub_300AA()
{
    memory16(_ds, _si) = 0x68;                  //mov word ptr [si], 68h
    memory16(_ds, _si + 2) = 0xa0;              //mov word ptr [si+2], 0A0h
    _dx = 0x0006;                               //mov dx, 6
    sub_30068();                                //call sub_30068
    _ax += 0x0008;                              //add ax, 8
    memory16(_ds, _si + 14) = _ax;              //mov [si+0Eh], ax
    _dx = 0x46;                                 //mov dx, 46h
    sub_30068();                                //call sub_30068
    _ax -= 0x23;                                //sub ax, 23h
    if (_ax != 0)                               //jnz short loc_300CD
      goto loc_300CD;
    _ax = 0x0a;                                 //mov ax, 0Ah
loc_300CD:                                      //loc_300CD:
    memory16(_ds, _si + 4) = _ax;               //mov [si+4], ax
    memory16(_ds, _si + 6) = _ax;               //mov [si+6], ax
    _dx = 0xffff;                               //mov dx, 0FFFFh
    if (_ax < 0x8000)                           //jb short loc_300DE
      goto loc_300DE;
    _dx = 0x0001;                               //mov dx, 1
loc_300DE:                                      //loc_300DE:
    memory16(_ds, _si + 12) = _dx;              //mov [si+0Ch], dx
    _ax = memory16(_ds, _si + 14);              //mov ax, [si+0Eh]
    _ax = memory16(_ds, _si + 4) * _al;         //imul word ptr [si+4]
    _ax = memory16(_ds, _si + 4) * _al;         //imul word ptr [si+4]
    _cx = 0x64;                                 //mov cx, 64h
    _idiv(_cx);                                 //idiv cx
    memory16(_ds, _si + 10) = _ax;              //mov [si+0Ah], ax
    memory16(_ds, _si + 8) = _ax;               //mov [si+8], ax
}

void sub_30663()
{
    _si = 0x148d;                               //mov si, 148Dh
    _cx = memory16(_ds, 0x1413);                //mov cx, ds:1413h
loc_3066A:                                      //loc_3066A:
    _bp = _cx;                                  //mov bp, cx
    sub_30617();                                //call sub_30617
    _si += 0x10;                                //add si, 10h
    _cx = _bp;                                  //mov cx, bp
    if (--_cx)                                  //loop loc_3066A
      goto loc_3066A;
}

void sub_30676()
{
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _si = 0x148d;                               //mov si, 148Dh
    _cx = memory16(_ds, 0x1413);                //mov cx, ds:1413h
loc_30682:                                      //loc_30682:
    _bp = _cx;                                  //mov bp, cx
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _ax = _ax + memory16(_ds, _si + 4);         //add ax, [si+4]
    _ax = _ax - memory16(_ds, _si + 6);         //sub ax, [si+6]
    if (_ax > 0x013f)                           //ja short loc_306A6
      goto loc_306A6;
    _cx = _ax;                                  //mov cx, ax
    _ax = memory16(_ds, _si + 8);               //mov ax, [si+8]
    _ax = _ax + memory16(_ds, _si + 2);         //add ax, [si+2]
    _ax = _ax - memory16(_ds, _si + 10);        //sub ax, [si+0Ah]
    if (_ax > 0xc7)                             //ja short loc_306A6
      goto loc_306A6;
    _dx = _ax;                                  //mov dx, ax
    sub_306FD();                                //call sub_306FD
loc_306A6:                                      //loc_306A6:
    _dx = _dx ^ _dx;                            //xor dx, dx
    _ax = memory16(_ds, _si + 12);              //mov ax, [si+0Ch]
    memory16(_ds, _si + 6) += _ax;              //add [si+6], ax
    _cx = memory16(_ds, _si + 6);               //mov cx, [si+6]
    _ax = memory16(_ds, _si + 14);              //mov ax, [si+0Eh]
    _ax = _cx * _al;                            //imul cx
    _ax = _cx * _al;                            //imul cx
    _cx = 0x64;                                 //mov cx, 64h
    _idiv(_cx);                                 //idiv cx
    memory16(_ds, _si + 8) = _ax;               //mov [si+8], ax
    _ax = _ax + memory16(_ds, _si + 2);         //add ax, [si+2]
    _ax = _ax - memory16(_ds, _si + 10);        //sub ax, [si+0Ah]
    if (_ax > 0xc7)                             //ja short loc_306DF
      goto loc_306DF;
    _dx = _ax;                                  //mov dx, ax
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _ax = _ax + memory16(_ds, _si + 4);         //add ax, [si+4]
    _ax = _ax - memory16(_ds, _si + 6);         //sub ax, [si+6]
    if (_ax > 0x013f)                           //ja short loc_306DF
      goto loc_306DF;
    _cx = _ax;                                  //mov cx, ax
    sub_306FD();                                //call sub_306FD
loc_306DF:                                      //loc_306DF:
    _ax = memory16(_ds, _si + 8);               //mov ax, [si+8]
    _ax = _ax + memory16(_ds, _si + 2);         //add ax, [si+2]
    _ax = _ax - memory16(_ds, _si + 10);        //sub ax, [si+0Ah]
    if (_ax > 0xc7)                             //ja short loc_306F8
      goto loc_306F8;
loc_306ED:                                      //loc_306ED:
    _si += 0x10;                                //add si, 10h
    _cx = _bp;                                  //mov cx, bp
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_30682
      goto loc_30682;
    return;                                     //retn
loc_306F8:                                      //loc_306F8:
    sub_30617();                                //call sub_30617
    goto loc_306ED;                             //jmp short loc_306ED
}

void sub_307A0()
{
    _dx = _dx ^ _dx;                            //xor dx, dx
    _si = 0x289d;                               //mov si, 289Dh
loc_307A5:                                      //loc_307A5:
    _cx = 0x0f;                                 //mov cx, 0Fh
loc_307A8:                                      //loc_307A8:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_307A8
      goto loc_307A8;
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short locret_307D4
      goto locret_307D4;
    _bp = _ax;                                  //mov bp, ax
    _push(_dx);                                 //push dx
    _dx = 0x03da;                               //mov dx, 3DAh
loc_307B8:                                      //loc_307B8:
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x08))                          //jz short loc_307B8
      goto loc_307B8;
loc_307BD:                                      //loc_307BD:
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x08)                             //jnz short loc_307BD
      goto loc_307BD;
    _dx = _pop();                               //pop dx
    _ax = _bp;                                  //mov ax, bp
    sub_30856();                                //call sub_30856
    _ax = _bp;                                  //mov ax, bp
    _xchg(_ax, _dx);                            //xchg ax, dx
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz short loc_307A5
      goto loc_307A5;
    sub_30856();                                //call sub_30856
    goto loc_307A5;                             //jmp short loc_307A5
locret_307D4:                                   //locret_307D4:
    return;
}

void sub_307D5()
{
    _push(_bx);                                 //push bx
    _bl <<= 1;                                  //shl bl, 1
    _bl <<= 1;                                  //shl bl, 1
    _bl <<= 1;                                  //shl bl, 1
    _bh = 0x50;                                 //mov bh, 50h
    _bh -= _bl;                                 //sub bh, bl
    memory(_ds, 0x2823) = _bh;                  //mov ds:2823h, bh
loc_307E4:                                      //loc_307E4:
    if (_dh == memory(_ds, 0x2823))             //jz short loc_30815
      goto loc_30815;
    _ax = _dx;                                  //mov ax, dx
    _ah -= 0x04;                                //sub ah, 4
    _cx = 0x0f;                                 //mov cx, 0Fh
loc_307F2:                                      //loc_307F2:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_307F2
      goto loc_307F2;
    _bp = _ax;                                  //mov bp, ax
    _push(_dx);                                 //push dx
    _dx = 0x03da;                               //mov dx, 3DAh
loc_307FD:                                      //loc_307FD:
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x08))                          //jz short loc_307FD
      goto loc_307FD;
loc_30802:                                      //loc_30802:
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x08)                             //jnz short loc_30802
      goto loc_30802;
    _dx = _pop();                               //pop dx
    _ax = _bp;                                  //mov ax, bp
    sub_30856();                                //call sub_30856
    _ax = _bp;                                  //mov ax, bp
    _xchg(_ax, _dx);                            //xchg ax, dx
    sub_30856();                                //call sub_30856
    goto loc_307E4;                             //jmp short loc_307E4
loc_30815:                                      //loc_30815:
    _bx = _pop();                               //pop bx
    _push(_bx);                                 //push bx
    _bh <<= 1;                                  //shl bh, 1
    _bh <<= 1;                                  //shl bh, 1
    _bh <<= 1;                                  //shl bh, 1
    _bh += 0x08;                                //add bh, 8
    memory(_ds, 0x2823) = _bh;                  //mov ds:2823h, bh
loc_30824:                                      //loc_30824:
    if (_dl == memory(_ds, 0x2823))             //jz short loc_30854
      goto loc_30854;
    _ax = _dx;                                  //mov ax, dx
    _al -= 0x04;                                //sub al, 4
    _cx = 0x0f;                                 //mov cx, 0Fh
loc_30831:                                      //loc_30831:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_30831
      goto loc_30831;
    _bp = _ax;                                  //mov bp, ax
    _push(_dx);                                 //push dx
    _dx = 0x03da;                               //mov dx, 3DAh
loc_3083C:                                      //loc_3083C:
    _in(_al, _dx);                              //in al, dx
    if (!(_al & 0x08))                          //jz short loc_3083C
      goto loc_3083C;
loc_30841:                                      //loc_30841:
    _in(_al, _dx);                              //in al, dx
    if (_al & 0x08)                             //jnz short loc_30841
      goto loc_30841;
    _dx = _pop();                               //pop dx
    _ax = _bp;                                  //mov ax, bp
    sub_30856();                                //call sub_30856
    _ax = _bp;                                  //mov ax, bp
    _xchg(_ax, _dx);                            //xchg ax, dx
    sub_30856();                                //call sub_30856
    goto loc_30824;                             //jmp short loc_30824
loc_30854:                                      //loc_30854:
    _bx = _pop();                               //pop bx
}

void sub_2B1B8()
{
    _si = 0x33d7;                               //mov si, 33D7h
    _cl = 0x08;                                 //mov cl, 8
loc_2B1BD:                                      //loc_2B1BD:
    _push(_cx);                                 //push cx
    _push(_si);                                 //push si
    _cl = memory(_ds, _si);                     //mov cl, [si]
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    memory(_ds, _si + 3) = 0;                   //mov byte ptr [si+3], 0
    _al -= 0x0a;                                //sub al, 0Ah
    _si = 0x6078;                               //mov si, 6078h
    _flags.interrupt = false;                   //cli
    _push(_es);                                 //push es
    _dx = 0xb800;                               //mov dx, 0B800h
    _es = _dx;                                  //mov es, dx
    _ch = _ch ^ _ch;                            //xor ch, ch
    _di = _cx;                                  //mov di, cx
    _di >>= 1;                                  //shr di, 1
    _di >>= 1;                                  //shr di, 1
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (!_flags.carry)                          //jnb short loc_2B1E4
      goto loc_2B1E4;
    _di += 0x2000;                              //add di, 2000h
loc_2B1E4:                                      //loc_2B1E4:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cl = 0x04;                                 //mov cl, 4
    _ax <<= _cl;                                //shl ax, cl
    _di += _ax;                                 //add di, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _dh = 0x1f;                                 //mov dh, 1Fh
loc_2B1F4:                                      //loc_2B1F4:
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memoryVideoSet16(_es, _di, _ax);                   //mov es:[di], ax
    if (_di < 0x2000)                           //jb short loc_2B204
      goto loc_2B204;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2B208;                             //jmp short loc_2B208
loc_2B204:                                      //loc_2B204:
    _di += 0x2000;                              //add di, 2000h
loc_2B208:                                      //loc_2B208:
    _dh -= 1;                                   //dec dh
    if (_dh != 0)                               //jnz short loc_2B1F4
      goto loc_2B1F4;
    _es = _pop();                               //pop es
    _flags.interrupt = true;                    //sti
    _si = _pop();                               //pop si
    _si += 0x0004;                              //add si, 4
    _cx = _pop();                               //pop cx
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2B1BD
      goto loc_2B1BD;
}

void sub_2B63D()
{
    memoryVideoSet16(_es, _di, 16385);                 //mov word ptr es:[di], 4001h
    // PARSER PROBLEM 16
    memoryVideoSet16(_es, _di + 0x32, 16385);            //mov word ptr es:[di+32h], 4001h
    if (_di < 0x2000)                           //jb short loc_2B654
      goto loc_2B654;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2B658;                             //jmp short loc_2B658
loc_2B654:                                      //loc_2B654:
    _di += 0x2000;                              //add di, 2000h
loc_2B658:                                      //loc_2B658:
    memoryVideoSet16(_es, _di, 20495);                 //mov word ptr es:[di], 500Fh
    memoryVideoSet16(_es, _di + 0x32, 20495);            //mov word ptr es:[di+32h], 500Fh
    if (_di < 0x2000)                           //jb short loc_2B66F
      goto loc_2B66F;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2B673;                             //jmp short loc_2B673
loc_2B66F:                                      //loc_2B66F:
    _di += 0x2000;                              //add di, 2000h
loc_2B673:                                      //loc_2B673:
    memoryVideoSet16(_es, _di, 17461);                 //mov word ptr es:[di], 4435h
    memoryVideoSet16(_es, _di + 0x32, 17461);            //mov word ptr es:[di+32h], 4435h
    if (_di < 0x2000)                           //jb short loc_2B68A
      goto loc_2B68A;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2B68E;                             //jmp short loc_2B68E
loc_2B68A:                                      //loc_2B68A:
    _di += 0x2000;                              //add di, 2000h
loc_2B68E:                                      //loc_2B68E:
    _ch |= _ch;                                 //or ch, ch
    if (_ch == 0)                               //jz short loc_2B6CE
      goto loc_2B6CE;
    _cl = _ch;                                  //mov cl, ch
loc_2B694:                                      //loc_2B694:
    memoryVideoSet16(_es, _di, 0xd43f);                //mov word ptr es:[di], 0D43Fh
    memoryVideoSet16(_es, _di + 0x32, 0xd43f);           //mov word ptr es:[di+32h], 0D43Fh
    if (_di < 0x2000)                           //jb short loc_2B6AB
      goto loc_2B6AB;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2B6AF;                             //jmp short loc_2B6AF
loc_2B6AB:                                      //loc_2B6AB:
    _di += 0x2000;                              //add di, 2000h
loc_2B6AF:                                      //loc_2B6AF:
    memoryVideoSet16(_es, _di, 4101);                  //mov word ptr es:[di], 1005h
    memoryVideoSet16(_es, _di + 0x32, 4101);             //mov word ptr es:[di+32h], 1005h
    if (_di < 0x2000)                           //jb short loc_2B6C6
      goto loc_2B6C6;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2B6CA;                             //jmp short loc_2B6CA
loc_2B6C6:                                      //loc_2B6C6:
    _di += 0x2000;                              //add di, 2000h
loc_2B6CA:                                      //loc_2B6CA:
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2B694
      goto loc_2B694;
loc_2B6CE:                                      //loc_2B6CE:
    memoryVideoSet16(_es, _di, 0xd43f);                //mov word ptr es:[di], 0D43Fh
    memoryVideoSet16(_es, _di + 0x32, 0xd43f);           //mov word ptr es:[di+32h], 0D43Fh
    if (_di < 0x2000)                           //jb short loc_2B6E5
      goto loc_2B6E5;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2B6E9;                             //jmp short loc_2B6E9
loc_2B6E5:                                      //loc_2B6E5:
    _di += 0x2000;                              //add di, 2000h
loc_2B6E9:                                      //loc_2B6E9:
    memoryVideoSet16(_es, _di, 17461);                 //mov word ptr es:[di], 4435h
    memoryVideoSet16(_es, _di + 0x32, 17461);            //mov word ptr es:[di+32h], 4435h
    if (_di < 0x2000)                           //jb short loc_2B700
      goto loc_2B700;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2B704;                             //jmp short loc_2B704
loc_2B700:                                      //loc_2B700:
    _di += 0x2000;                              //add di, 2000h
loc_2B704:                                      //loc_2B704:
    memoryVideoSet16(_es, _di, 20495);                 //mov word ptr es:[di], 500Fh
    memoryVideoSet16(_es, _di + 0x32, 20495);            //mov word ptr es:[di+32h], 500Fh
    if (_di < 0x2000)                           //jb short loc_2B71B
      goto loc_2B71B;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2B71F;                             //jmp short loc_2B71F
loc_2B71B:                                      //loc_2B71B:
    _di += 0x2000;                              //add di, 2000h
loc_2B71F:                                      //loc_2B71F:
    memoryVideoSet16(_es, _di, 16385);                 //mov word ptr es:[di], 4001h
    memoryVideoSet16(_es, _di + 0x32, 16385);            //mov word ptr es:[di+32h], 4001h
}

void sub_2C0C7()
{
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _push(_si);                                 //push si
    _al = 0xff;                                 //mov al, 0FFh
    sub_2B884();                                //call sub_2B884
    _si = _pop();                               //pop si
    _di -= 1;                                   //dec di
    _di -= 1;                                   //dec di
}

void sub_2CA43()
{
    _push(_cx);                                 //push cx
    _cl += 1;                                   //inc cl
    _cl += 1;                                   //inc cl
    memory16(_ds, 0x1468) -= 2;                 //sub word ptr ds:1468h, 2
    sub_2CA70();                                //call sub_2CA70
    _cx = _pop();                               //pop cx
    memory16(_ds, 0x1468) += 2;                 //add word ptr ds:1468h, 2
    sub_2CA70();                                //call sub_2CA70
    memory16(_ds, 0x1468) += 2;                 //add word ptr ds:1468h, 2
    _si = memory16(_ds, 0x1468);                //mov si, ds:1468h
    if (memory16(_ds, _si) == 0xffff)           //jz short loc_2CA69
      goto loc_2CA69;
    return;                                     //retn
loc_2CA69:                                      //loc_2CA69:
    memory16(_ds, 0x1468) = 29985;              //mov word ptr ds:1468h, 7521h
}

void sub_2CA70() // gula sa gula
{
    _si = memory16(_ds, 0x1468);                //mov si, ds:1468h
    _si = memory16(_ds, _si);                   //mov si, [si]
    _di = 0x146a;                               //mov di, 146Ah
    _bp = _cx;                                  //mov bp, cx
    _cx = 0x15;                                 //mov cx, 15h
    _rep_movsb<MemAuto, MemAuto, DirAuto>();    //rep movsb
    _cx = _bp;                                  //mov cx, bp
    _cl &= 0x03;                                //and cl, 3
    if (_cl == 0)                               //jz short loc_2CAA1
      goto loc_2CAA1;
    _cl <<= 1;                                  //shl cl, 1
loc_2CA89:                                      //loc_2CA89:
    _si = 0x146a;                               //mov si, 146Ah
    _dh = 0x07;                                 //mov dh, 7
loc_2CA8E:                                      //loc_2CA8E:
    _flags.carry = memory(_ds, _si) & 1;
    //TODO: parser moze sam
    memory(_ds, _si) >>= 1;                     //shr byte ptr [si], 1
    _rcr(memory(_ds, _si + 1), 1);
    _rcr(memory(_ds, _si + 2), 1);
    _si += 0x0003;                              //add si, 3
    _dh -= 1;                                   //dec dh
    if (_dh != 0)                               //jnz short loc_2CA8E
      goto loc_2CA8E;
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2CA89
      goto loc_2CA89;
loc_2CAA1:                                      //loc_2CAA1:
    _push(_es);                                 //push es
    _dx = 0xb800;                               //mov dx, 0B800h
    _es = _dx;                                  //mov es, dx
    _cx = _bp;                                  //mov cx, bp
    _ch = _ch ^ _ch;                            //xor ch, ch
    _di = _cx;                                  //mov di, cx
    _di >>= 1;                                  //shr di, 1
    _di >>= 1;                                  //shr di, 1
    _di += 0x1cc0;                              //add di, 1CC0h
    _si = 0x146a;                               //mov si, 146Ah
    _cl = 0x07;                                 //mov cl, 7
loc_2CABA:                                      //loc_2CABA:
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memoryVideoXor16(_es, _di, _ax);//xor es:[di], ax
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    memoryVideoXor(_es, _di + 2, _al);
    if (_di < 0x2000)                           //jb short loc_2CACF
      goto loc_2CACF;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2CAD3;                             //jmp short loc_2CAD3
loc_2CACF:                                      //loc_2CACF:
    _di += 0x2000;                              //add di, 2000h
loc_2CAD3:                                      //loc_2CAD3:
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2CABA
      goto loc_2CABA;
    _es = _pop();                               //pop es
    _sync();
}

void sub_2CF36()
{
    WORD _cs = _seg004;
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    if (_al >= 0xb5)                            //jnb short loc_2CF3E
      goto loc_2CF3E;
locret_2CF3D:                                   //locret_2CF3D:
    return;                                     //retn
loc_2CF3E:                                      //loc_2CF3E:
    if (_al == 0xb5)                            //jz short loc_2CFBF
      goto loc_2CFBF;
    if (_al > 0xbe)                             //ja short locret_2CF3D
      goto locret_2CF3D;
    if (memory(_ds, _si + 21) == 1)             //jz short loc_2CFBF
      goto loc_2CFBF;
    _ah = memory(_ds, 0x2E54);                  //mov ah, ds:2E54h
    _ah -= 0x03;                                //sub ah, 3
    _bl = memory(_ds, _si);                     //mov bl, [si]
    _cl = 0x01;                                 //mov cl, 1
    if (_bl == _ah)                             //jz short loc_2CF68
      goto loc_2CF68;
    _bl -= _ah;                                 //sub bl, ah
    _ah = memory(_ds, 0x2D3A);                  //mov ah, ds:2D3Ah
    _ah += 0x03;                                //add ah, 3
    if (_bl != _ah)                             //jnz short locret_2CF3D
      goto locret_2CF3D;
    _cl = 0x00;                                 //mov cl, 0
loc_2CF68:                                      //loc_2CF68:
    _al -= 0xb6;                                //sub al, 0B6h
    if (_al > 0x05)                             //ja short loc_2CF74
      goto loc_2CF74;
    memory(_ds, _si + 21) = 1;                  //mov byte ptr [si+15h], 1
    goto loc_2CF78;                             //jmp short loc_2CF78
loc_2CF74:                                      //loc_2CF74:
    memory(_ds, _si + 21) = 0;                  //mov byte ptr [si+15h], 0
loc_2CF78:                                      //loc_2CF78:
    memory(_ds, _si + 20) = _cl;                //mov [si+14h], cl
    _cl |= _cl;                                 //or cl, cl
    if (_cl != 0)                               //jnz short loc_2CF8B
      goto loc_2CF8B;
    _ah = memory(_ds, 0x2E54);                  //mov ah, ds:2E54h
    _ah = _ah + memory(_ds, 0x2D3A);            //add ah, ds:2D3Ah
    _ah += 1;                                   //inc ah
    goto loc_2CF92;                             //jmp short loc_2CF92
loc_2CF8B:                                      //loc_2CF8B:
    _ah = memory(_ds, 0x2E54);                  //mov ah, ds:2E54h
    _ah -= 0x04;                                //sub ah, 4
loc_2CF92:                                      //loc_2CF92:
    memory(_ds, _si + 24) = _ah;                //mov [si+18h], ah
    _ah = memory(_ds, _si + 1);                 //mov ah, [si+1]
    memory(_ds, _si + 25) = _ah;                //mov [si+19h], ah
    memory(_ds, _si + 26) = 1;                  //mov byte ptr [si+1Ah], 1
    memory(_ds, _si + 27) = 1;                  //mov byte ptr [si+1Bh], 1
    memory(_ds, _si + 29) = 0;                  //mov byte ptr [si+1Dh], 0
    _ah = _ah ^ _ah;                            //xor ah, ah
    _al <<= 1;                                  //shl al, 1
    _di = 0x2e42;                               //mov di, 2E42h
    _di += _ax;                                 //add di, ax
    _ax = memory16(_ds, _di);                   //mov ax, [di]
    memory(_ds, _si + 23) = _ah;                //mov [si+17h], ah
    memory(_ds, _si + 22) = _al;                //mov [si+16h], al
    memory(_cs, 0xF4) = 1;                      //mov cs:byte_2AD14, 1
locret_2CFBE:                                   //locret_2CFBE:
    return;                                     //retn
loc_2CFBF:                                      //loc_2CFBF:
    _al = memory(_ds, 0x2E54);                  //mov al, ds:2E54h
    _al -= 0x03;                                //sub al, 3
    _bl = memory(_ds, _si);                     //mov bl, [si]
    if (_bl < _al)                              //jb short locret_2CFBE
      goto locret_2CFBE;
    _bl -= _al;                                 //sub bl, al
    if (_bl > 0x0a)                             //ja short loc_2D018
      goto loc_2D018;
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bl <<= 1;                                  //shl bl, 1
    _di = 0x2e2c;                               //mov di, 2E2Ch
    _di += _bx;                                 //add di, bx
    _ax = memory16(_ds, _di);                   //mov ax, [di]
    memory(_ds, _si + 23) = _ah;                //mov [si+17h], ah
    memory(_ds, _si + 22) = _al;                //mov [si+16h], al
    memory(_ds, _si + 20) = 1;                  //mov byte ptr [si+14h], 1
    _ah = memory(_ds, _si + 1);                 //mov ah, [si+1]
    if (memory(_ds, _si + 1) == 0xbe)           //jz short loc_2CFF7
      goto loc_2CFF7;
    memory(_ds, _si + 21) = 1;                  //mov byte ptr [si+15h], 1
    _ah -= 1;                                   //dec ah
    goto loc_2CFFD;                             //jmp short loc_2CFFD
loc_2CFF7:                                      //loc_2CFF7:
    memory(_ds, _si + 21) = 0;                  //mov byte ptr [si+15h], 0
    _ah += 1;                                   //inc ah
loc_2CFFD:                                      //loc_2CFFD:
    _al = memory(_ds, _si);                     //mov al, [si]
    memory(_ds, _si + 24) = _al;                //mov [si+18h], al
    memory(_ds, _si + 25) = _ah;                //mov [si+19h], ah
    memory(_ds, _si + 26) = 1;                  //mov byte ptr [si+1Ah], 1
    memory(_ds, _si + 27) = 1;                  //mov byte ptr [si+1Bh], 1
    memory(_ds, _si + 29) = 0;                  //mov byte ptr [si+1Dh], 0
    memory(_cs, 0xF4) = 1;                      //mov cs:byte_2AD14, 1
    return;                                     //retn
loc_2D018:                                      //loc_2D018:
    _al = memory(_ds, 0x2D3A);                  //mov al, ds:2D3Ah
    _al += 0x03;                                //add al, 3
    if (_bl > _al)                              //ja short locret_2CFBE
      goto locret_2CFBE;
    _al -= _bl;                                 //sub al, bl
    if (_al > 0x0a)                             //ja short loc_2D06D
      goto loc_2D06D;
    _ah = _ah ^ _ah;                            //xor ah, ah
    _al <<= 1;                                  //shl al, 1
    _di = 0x2e2c;                               //mov di, 2E2Ch
    _di += _ax;                                 //add di, ax
    _bx = memory16(_ds, _di);                   //mov bx, [di]
    memory(_ds, _si + 23) = _bh;                //mov [si+17h], bh
    memory(_ds, _si + 22) = _bl;                //mov [si+16h], bl
    memory(_ds, _si + 20) = 0;                  //mov byte ptr [si+14h], 0
    _ah = memory(_ds, _si + 1);                 //mov ah, [si+1]
    if (_ah == 0xbe)                            //jz short loc_2D04C
      goto loc_2D04C;
    memory(_ds, _si + 21) = 1;                  //mov byte ptr [si+15h], 1
    _ah -= 1;                                   //dec ah
    goto loc_2D052;                             //jmp short loc_2D052
loc_2D04C:                                      //loc_2D04C:
    memory(_ds, _si + 21) = 0;                  //mov byte ptr [si+15h], 0
    _ah += 1;                                   //inc ah
loc_2D052:                                      //loc_2D052:
    _al = memory(_ds, _si);                     //mov al, [si]
    memory(_ds, _si + 24) = _al;                //mov [si+18h], al
    memory(_ds, _si + 25) = _ah;                //mov [si+19h], ah
    memory(_ds, _si + 26) = 1;                  //mov byte ptr [si+1Ah], 1
    memory(_ds, _si + 27) = 1;                  //mov byte ptr [si+1Bh], 1
    memory(_ds, _si + 29) = 0;                  //mov byte ptr [si+1Dh], 0
    memory(_cs, 0xF4) = 1;                      //mov cs:byte_2AD14, 1
    return;                                     //retn
loc_2D06D:                                      //loc_2D06D:
    _ah = memory(_ds, _si + 1);                 //mov ah, [si+1]
    if (memory(_ds, _si + 1) == 0xbe)           //jz short loc_2D07E
      goto loc_2D07E;
    memory(_ds, _si + 21) = 1;                  //mov byte ptr [si+15h], 1
    _ah -= 1;                                   //dec ah
    goto loc_2D084;                             //jmp short loc_2D084
loc_2D07E:                                      //loc_2D07E:
    memory(_ds, _si + 21) = 0;                  //mov byte ptr [si+15h], 0
    _ah += 1;                                   //inc ah
loc_2D084:                                      //loc_2D084:
    _al = memory(_ds, _si);                     //mov al, [si]
    memory(_ds, _si + 24) = _al;                //mov [si+18h], al
    memory(_ds, _si + 25) = _ah;                //mov [si+19h], ah
    memory(_ds, _si + 26) = 1;                  //mov byte ptr [si+1Ah], 1
    memory(_ds, _si + 27) = 1;                  //mov byte ptr [si+1Bh], 1
    memory(_ds, _si + 29) = 0;                  //mov byte ptr [si+1Dh], 0
    memory(_cs, 0xF4) = 1;                      //mov cs:byte_2AD14, 1
}

void sub_2D16D()
{
    _bp = _si;                                  //mov bp, si
    memory(_ds, 0x2E74) = 0;                    //mov byte ptr ds:2E74h, 0
    _si = 0x2e89;                               //mov si, 2E89h
    _al -= 0x08;                                //sub al, 8
    _bl -= 0x06;                                //sub bl, 6
    sub_2D375();                                //call sub_2D375
    _al += 0x03;                                //add al, 3
    sub_2D375();                                //call sub_2D375
    _bl += 0x03;                                //add bl, 3
    sub_2D375();                                //call sub_2D375
    _al -= 0x03;                                //sub al, 3
    sub_2D375();                                //call sub_2D375
    _si = _bp;                                  //mov si, bp
    _al = memory(_ds, 0x2E74);                  //mov al, ds:2E74h
    _al |= _al;                                 //or al, al
    if (_al != 0)                               //jnz short loc_2D199
      goto loc_2D199;
    return;                                     //retn
loc_2D199:                                      //loc_2D199:
    if (_al != 0x02)                            //jnz short loc_2D1A0
      goto loc_2D1A0;
    goto loc_2D225;                             //jmp loc_2D225
loc_2D1A0:                                      //loc_2D1A0:
    if (_al == 0x03)                            //jz short loc_2D1E3
      goto loc_2D1E3;
    _di = 0x2e99;                               //mov di, 2E99h
    _si = 0x2e89;                               //mov si, 2E89h
loc_2D1AA:                                      //loc_2D1AA:
    if (memory16(_ds, _si) != 0)                //jnz short loc_2D1B7
      goto loc_2D1B7;
    _si += 0x0004;                              //add si, 4
    _di += 0x0002;                              //add di, 2
    goto loc_2D1AA;                             //jmp short loc_2D1AA
loc_2D1B7:                                      //loc_2D1B7:
    _si = _bp;                                  //mov si, bp
    _dx = memory16(_ds, _di);                   //mov dx, [di]
    memory(_ds, _si + 21) = _dh;                //mov [si+15h], dh
    memory(_ds, _si + 20) = _dl;                //mov [si+14h], dl
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    _bl = memory(_ds, _si);                     //mov bl, [si]
    _dh |= _dh;                                 //or dh, dh
    if (_dh == 0)                               //jz short loc_2D1CE
      goto loc_2D1CE;
    _al -= 1;                                   //dec al
    goto loc_2D1D0;                             //jmp short loc_2D1D0
loc_2D1CE:                                      //loc_2D1CE:
    _al += 1;                                   //inc al
loc_2D1D0:                                      //loc_2D1D0:
    memory(_ds, _si + 25) = _al;                //mov [si+19h], al
    _dl |= _dl;                                 //or dl, dl
    if (_dl == 0)                               //jz short loc_2D1DB
      goto loc_2D1DB;
    _bl -= 1;                                   //dec bl
    goto loc_2D1DD;                             //jmp short loc_2D1DD
loc_2D1DB:                                      //loc_2D1DB:
    _bl += 1;                                   //inc bl
loc_2D1DD:                                      //loc_2D1DD:
    memory(_ds, _si + 24) = _bl;                //mov [si+18h], bl
    goto loc_2D2FD;                             //jmp loc_2D2FD
loc_2D1E3:                                      //loc_2D1E3:
    if (memory(_ds, _si + 20) != 0)             //jnz short loc_2D1F6
      goto loc_2D1F6;
    memory(_ds, _si + 20) = 1;                  //mov byte ptr [si+14h], 1
    _bl = memory(_ds, _si);                     //mov bl, [si]
    _bl -= 1;                                   //dec bl
    memory(_ds, _si + 24) = _bl;                //mov [si+18h], bl
    goto loc_2D201;                             //jmp short loc_2D201
loc_2D1F6:                                      //loc_2D1F6:
    memory(_ds, _si + 20) = 0;                  //mov byte ptr [si+14h], 0
    _bl = memory(_ds, _si);                     //mov bl, [si]
    _bl += 1;                                   //inc bl
    memory(_ds, _si + 24) = _bl;                //mov [si+18h], bl
loc_2D201:                                      //loc_2D201:
    if (memory(_ds, _si + 21) != 0)             //jnz short loc_2D216
      goto loc_2D216;
    memory(_ds, _si + 21) = 1;                  //mov byte ptr [si+15h], 1
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    _al -= 1;                                   //dec al
    memory(_ds, _si + 25) = _al;                //mov [si+19h], al
    goto loc_2D2FD;                             //jmp loc_2D2FD
loc_2D216:                                      //loc_2D216:
    memory(_ds, _si + 21) = 0;                  //mov byte ptr [si+15h], 0
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    _al += 1;                                   //inc al
    memory(_ds, _si + 25) = _al;                //mov [si+19h], al
    goto loc_2D2FD;                             //jmp loc_2D2FD
loc_2D225:                                      //loc_2D225:
    if (memory16(_ds, 0x2E89) == 0)             //jz short loc_2D296
      goto loc_2D296;
    if (memory16(_ds, 0x2E91) == 0)             //jz short loc_2D235
      goto loc_2D235;
    goto loc_2D1E3;                             //jmp short loc_2D1E3
loc_2D235:                                      //loc_2D235:
    if (memory16(_ds, 0x2E8D) == 0)             //jz short loc_2D26A
      goto loc_2D26A;
    if (memory(_ds, _si + 21) != 0)             //jnz short loc_2D256
      goto loc_2D256;
    memory(_ds, _si + 21) = 1;                  //mov byte ptr [si+15h], 1
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    _al -= 1;                                   //dec al
    memory(_ds, _si + 25) = _al;                //mov [si+19h], al
    _bl = memory(_ds, _si);                     //mov bl, [si]
    memory(_ds, _si + 24) = _bl;                //mov [si+18h], bl
    goto loc_2D2FD;                             //jmp loc_2D2FD
loc_2D256:                                      //loc_2D256:
    memory(_ds, _si + 21) = 0;                  //mov byte ptr [si+15h], 0
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    _al += 1;                                   //inc al
    memory(_ds, _si + 25) = _al;                //mov [si+19h], al
    _bl = memory(_ds, _si);                     //mov bl, [si]
    memory(_ds, _si + 24) = _bl;                //mov [si+18h], bl
    goto loc_2D2FD;                             //jmp loc_2D2FD
loc_2D26A:                                      //loc_2D26A:
    if (memory(_ds, _si + 20) != 0)             //jnz short loc_2D283
      goto loc_2D283;
    memory(_ds, _si + 20) = 1;                  //mov byte ptr [si+14h], 1
    _bl = memory(_ds, _si);                     //mov bl, [si]
    _bl -= 1;                                   //dec bl
    memory(_ds, _si + 24) = _bl;                //mov [si+18h], bl
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    memory(_ds, _si + 25) = _al;                //mov [si+19h], al
    goto loc_2D2FD;                             //jmp short loc_2D2FD
loc_2D283:                                      //loc_2D283:
    memory(_ds, _si + 20) = 0;                  //mov byte ptr [si+14h], 0
    _bl = memory(_ds, _si);                     //mov bl, [si]
    _bl += 1;                                   //inc bl
    memory(_ds, _si + 24) = _bl;                //mov [si+18h], bl
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    memory(_ds, _si + 25) = _al;                //mov [si+19h], al
    goto loc_2D2FD;                             //jmp short loc_2D2FD
loc_2D296:                                      //loc_2D296:
    if (memory16(_ds, 0x2E8D) == 0)             //jz short loc_2D2A7
      goto loc_2D2A7;
    if (memory16(_ds, 0x2E99) == 0)             //jz short loc_2D2D3
      goto loc_2D2D3;
    goto loc_2D1E3;                             //jmp loc_2D1E3
loc_2D2A7:                                      //loc_2D2A7:
    if (memory(_ds, _si + 21) != 0)             //jnz short loc_2D2C0
      goto loc_2D2C0;
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    _al -= 1;                                   //dec al
    memory(_ds, _si + 25) = _al;                //mov [si+19h], al
    _bl = memory(_ds, _si);                     //mov bl, [si]
    memory(_ds, _si + 24) = _bl;                //mov [si+18h], bl
    memory(_ds, _si + 21) = 1;                  //mov byte ptr [si+15h], 1
    goto loc_2D2FD;                             //jmp short loc_2D2FD
loc_2D2C0:                                      //loc_2D2C0:
    memory(_ds, _si + 21) = 0;                  //mov byte ptr [si+15h], 0
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    _al += 1;                                   //inc al
    memory(_ds, _si + 25) = _al;                //mov [si+19h], al
    _bl = memory(_ds, _si);                     //mov bl, [si]
    memory(_ds, _si + 24) = _bl;                //mov [si+18h], bl
    goto loc_2D2FD;                             //jmp short loc_2D2FD
loc_2D2D3:                                      //loc_2D2D3:
    if (memory(_ds, _si + 20) != 0)             //jnz short loc_2D2EC
      goto loc_2D2EC;
    _bl = memory(_ds, _si);                     //mov bl, [si]
    _bl -= 1;                                   //dec bl
    memory(_ds, _si + 24) = _bl;                //mov [si+18h], bl
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    memory(_ds, _si + 25) = _al;                //mov [si+19h], al
    memory(_ds, _si + 20) = 1;                  //mov byte ptr [si+14h], 1
    goto loc_2D2FD;                             //jmp short loc_2D2FD
loc_2D2EC:                                      //loc_2D2EC:
    memory(_ds, _si + 20) = 0;                  //mov byte ptr [si+14h], 0
    _bl = memory(_ds, _si);                     //mov bl, [si]
    _bl += 1;                                   //inc bl
    memory(_ds, _si + 24) = _bl;                //mov [si+18h], bl
    _al = memory(_ds, _si + 1);                 //mov al, [si+1]
    memory(_ds, _si + 25) = _al;                //mov [si+19h], al
loc_2D2FD:                                      //loc_2D2FD:
    if (memory(_ds, 0x2E74) != 3)               //jnz short loc_2D32E
      goto loc_2D32E;
    if (memory16(_ds, 0x2E89) == 0)             //jz short loc_2D328
      goto loc_2D328;
    if (memory16(_ds, 0x2E91) == 0)             //jz short loc_2D320
      goto loc_2D320;
    memory16(_ds, 0x2E8D) = 0;                  //mov word ptr ds:2E8Dh, 0
    memory16(_ds, 0x2E95) = 0;                  //mov word ptr ds:2E95h, 0
    goto loc_2D32E;                             //jmp short loc_2D32E
loc_2D320:                                      //loc_2D320:
    memory16(_ds, 0x2E89) = 0;                  //mov word ptr ds:2E89h, 0
    goto loc_2D32E;                             //jmp short loc_2D32E
loc_2D328:                                      //loc_2D328:
    memory16(_ds, 0x2E91) = 0;                  //mov word ptr ds:2E91h, 0
loc_2D32E:                                      //loc_2D32E:
    memory(_ds, _si + 26) = 1;                  //mov byte ptr [si+1Ah], 1
    memory(_ds, _si + 27) = 1;                  //mov byte ptr [si+1Bh], 1
    _si = 0x2e89;                               //mov si, 2E89h
    _cx = 0x0003;                               //mov cx, 3
loc_2D33C:                                      //loc_2D33C:
    _ax = memory16(_ds, _si);                   //mov ax, [si]
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz short loc_2D349
      goto loc_2D349;
    _si += 0x0004;                              //add si, 4
    if (--_cx)                                  //loop loc_2D33C
      goto loc_2D33C;
    goto loc_2D351;                             //jmp short loc_2D351
loc_2D349:                                      //loc_2D349:
    sub_2D3D7();                                //call sub_2D3D7
    _si += 0x0004;                              //add si, 4
    if (--_cx)                                  //loop loc_2D33C
      goto loc_2D33C;
loc_2D351:                                      //loc_2D351:
    _cx = 0x0004;                               //mov cx, 4
    _si = 0x2e89;                               //mov si, 2E89h
loc_2D357:                                      //loc_2D357:
    _push(_cx);                                 //push cx
    _push(_si);                                 //push si
    _di = memory16(_ds, _si);                   //mov di, [si]
    _di |= _di;                                 //or di, di
    if (_di == 0)                               //jz short loc_2D36B
      goto loc_2D36B;
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bl = memory(_ds, _di);                     //mov bl, [di]
    _bx <<= 1;                                  //shl bx, 1
    _bx += 0x3044;                              //add bx, 3044h
    _STOP_("call word ptr [bx]");               //call word ptr [bx]
loc_2D36B:                                      //loc_2D36B:
    _si = _pop();                               //pop si
    _cx = _pop();                               //pop cx
    _si += 0x0004;                              //add si, 4
    if (--_cx)                                  //loop loc_2D357
      goto loc_2D357;
    _si = _bp;                                  //mov si, bp
}

void sub_2D375()
{
    _cx = _ax;                                  //mov cx, ax
    _dx = _bx;                                  //mov dx, bx
    if (_al > 0xbf)                             //ja short loc_2D3A7
      goto loc_2D3A7;
    if (_bl > 0xc4)                             //ja short loc_2D3A7
      goto loc_2D3A7;
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bl &= 0xf8;                                //and bl, 0F8h
    _di = _bx;                                  //mov di, bx
    _bl >>= 1;                                  //shr bl, 1
    _di += _bx;                                 //add di, bx
    _ah = _ah ^ _ah;                            //xor ah, ah
    _al >>= 1;                                  //shr al, 1
    _al >>= 1;                                  //shr al, 1
    _al >>= 1;                                  //shr al, 1
    _al >>= 1;                                  //shr al, 1
    _di += _ax;                                 //add di, ax
    _di += 0x2f18;                              //add di, 2F18h
    _al = memory(_ds, _di);                     //mov al, [di]
    if (_al == 0x0c)                            //jz short loc_2D3A7
      goto loc_2D3A7;
    _al |= _al;                                 //or al, al
    if (_al != 0)                               //jnz short loc_2D3B3
      goto loc_2D3B3;
loc_2D3A7:                                      //loc_2D3A7:
    memory16(_ds, _si) = 0;                     //mov word ptr [si], 0
    _si += 0x0004;                              //add si, 4
    _ax = _cx;                                  //mov ax, cx
    _bx = _dx;                                  //mov bx, dx
    return;                                     //retn
loc_2D3B3:                                      //loc_2D3B3:
    memory16(_ds, _si) = _di;                   //mov [si], di
    memory(_ds, 0x2E74) += 1;                   //inc byte ptr ds:2E74h
    _ax = _cx;                                  //mov ax, cx
    _bx = _dx;                                  //mov bx, dx
    _ah = _al;                                  //mov ah, al
    _ah &= 0xf0;                                //and ah, 0F0h
    _bh = _bl;                                  //mov bh, bl
    _bh &= 0xf8;                                //and bh, 0F8h
    _ah += 0x08;                                //add ah, 8
    _bh += 0x06;                                //add bh, 6
    memory(_ds, _si + 2) = _ah;                 //mov [si+2], ah
    memory(_ds, _si + 3) = _bh;                 //mov [si+3], bh
    _si += 0x0004;                              //add si, 4
}

void sub_2DC8B()
{
    _push(_bp);                                 //push bp
    _push(_si);                                 //push si
    _push(_dx);                                 //push dx
    _push(_cx);                                 //push cx
    _si = _ax;                                  //mov si, ax
    _bp = _bx;                                  //mov bp, bx
    sub_2DCFD();                                //call sub_2DCFD
    if (_di < 0x2000)                           //jb short loc_2DCA2
      goto loc_2DCA2;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2DCA6;                             //jmp short loc_2DCA6
loc_2DCA2:                                      //loc_2DCA2:
    _di += 0x2000;                              //add di, 2000h
loc_2DCA6:                                      //loc_2DCA6:
    _push(_es);                                 //push es
    _dx = 0xb800;                               //mov dx, 0B800h
    _es = _dx;                                  //mov es, dx
    memory(_es, _di) = memory(_es, _di) ^ _al;  //xor es:[di], al
    if (_di < 0x2000)                           //jb short loc_2DCBB
      goto loc_2DCBB;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2DCBF;                             //jmp short loc_2DCBF
loc_2DCBB:                                      //loc_2DCBB:
    _di += 0x2000;                              //add di, 2000h
loc_2DCBF:                                      //loc_2DCBF:
    memory(_es, _di) = memory(_es, _di) ^ _al;  //xor es:[di], al
    _ax = _si;                                  //mov ax, si
    _bx = _bp;                                  //mov bx, bp
    _bl += 0x13;                                //add bl, 13h
    sub_2DCFD();                                //call sub_2DCFD
    if (_di < 0x2000)                           //jb short loc_2DCD8
      goto loc_2DCD8;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2DCDC;                             //jmp short loc_2DCDC
loc_2DCD8:                                      //loc_2DCD8:
    _di += 0x2000;                              //add di, 2000h
loc_2DCDC:                                      //loc_2DCDC:
    memory(_es, _di) = memory(_es, _di) ^ _al;  //xor es:[di], al
    if (_di < 0x2000)                           //jb short loc_2DCEB
      goto loc_2DCEB;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2DCEF;                             //jmp short loc_2DCEF
loc_2DCEB:                                      //loc_2DCEB:
    _di += 0x2000;                              //add di, 2000h
loc_2DCEF:                                      //loc_2DCEF:
    memory(_es, _di) = memory(_es, _di) ^ _al;  //xor es:[di], al
    _es = _pop();                               //pop es
    _cx = _pop();                               //pop cx
    _dx = _pop();                               //pop dx
    _si = _pop();                               //pop si
    _bp = _pop();                               //pop bp
    memory(_ds, 0x2E7E) = 1;                    //mov byte ptr ds:2E7Eh, 1
}

void sub_2DCFD()
{
    _flags.interrupt = false;                   //cli
    _push(_es);                                 //push es
    _push(_bx);                                 //push bx
    _dx = 0xb800;                               //mov dx, 0B800h
    _es = _dx;                                  //mov es, dx
    _bh = _bh ^ _bh;                            //xor bh, bh
    _di = _bx;                                  //mov di, bx
    _di >>= 1;                                  //shr di, 1
    _di >>= 1;                                  //shr di, 1
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (!_flags.carry)                          //jnb short loc_2DD15
      goto loc_2DD15;
    _di += 0x2000;                              //add di, 2000h
loc_2DD15:                                      //loc_2DD15:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cl = 0x04;                                 //mov cl, 4
    _ax <<= _cl;                                //shl ax, cl
    _di += _ax;                                 //add di, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _bx = _pop();                               //pop bx
    _al = 0xc0;                                 //mov al, 0C0h
    _ch = _ch ^ _ch;                            //xor ch, ch
    _cl = _bl;                                  //mov cl, bl
    _cl &= 0x03;                                //and cl, 3
    _cl <<= 1;                                  //shl cl, 1
    if (_cx == 0)                               //jcxz short loc_2DD33
      goto loc_2DD33;
    _al >>= _cl;                                //shr al, cl
loc_2DD33:                                      //loc_2DD33:
    memory(_es, _di) = memory(_es, _di) ^ _al;  //xor es:[di], al
    _es = _pop();                               //pop es
    _flags.interrupt = true;                    //sti
}

void sub_2EDD1()
{
    _push(_es);                                 //push es
    _push(_cx);                                 //push cx
    _cx = 0xb800;                               //mov cx, 0B800h
    _es = _cx;                                  //mov es, cx
    _cx = 0x19;                                 //mov cx, 19h
loc_2EDDB:                                      //loc_2EDDB:
    _stosw<MemAuto, DirAuto>();                 //stosw
    _di -= 1;                                   //dec di
    _di -= 1;                                   //dec di
    if (_di < 0x2000)                           //jb short loc_2EDEA
      goto loc_2EDEA;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2EDEE;                             //jmp short loc_2EDEE
loc_2EDEA:                                      //loc_2EDEA:
    _di += 0x2000;                              //add di, 2000h
loc_2EDEE:                                      //loc_2EDEE:
    _cx -= 1;                                   //dec cx
    if (_cx != 0)                               //jnz short loc_2EDDB
      goto loc_2EDDB;
    _cx = _pop();                               //pop cx
    _es = _pop();                               //pop es
}

void sub_2EE05()
{
    _push(_ds);                                 //push ds
    _push(_cx);                                 //push cx
    _si = _seg001;                              //mov si, seg seg001
    _ds = _si;                                  //mov ds, si
    _ah = _ah ^ _ah;                            //xor ah, ah
    _ch = _cl;                                  //mov ch, cl
    _cl = 0x04;                                 //mov cl, 4
    _ax <<= _cl;                                //shl ax, cl
    _si = _ax;                                  //mov si, ax
    _ax <<= 1;                                  //shl ax, 1
    _si += _ax;                                 //add si, ax
    _si += 0x28f0;                              //add si, 28F0h
    _cl = _ch;                                  //mov cl, ch
    _ch = _ch ^ _ch;                            //xor ch, ch
    _cx <<= 1;                                  //shl cx, 1
    _cx <<= 1;                                  //shl cx, 1
    _si += _cx;                                 //add si, cx
    _cx = 0x0002;                               //mov cx, 2
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _cx = _pop();                               //pop cx
    _ds = _pop();                               //pop ds
}

void sub_2F8E1()
{
    _flags.interrupt = false;                   //cli
    _push(_es);                                 //push es
    _push(_ds);                                 //push ds
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _ah = _ah ^ _ah;                            //xor ah, ah
    _al -= 0x06;                                //sub al, 6
    _ch = _cl;                                  //mov ch, cl
    _cl = 0x04;                                 //mov cl, 4
    _ax <<= _cl;                                //shl ax, cl
    _si = _ax;                                  //mov si, ax
    _ax <<= 1;                                  //shl ax, 1
    _si += _ax;                                 //add si, ax
    _si += 0x28f0;                              //add si, 28F0h
    _cl = _ch;                                  //mov cl, ch
    _ch = _ch ^ _ch;                            //xor ch, ch
    _cx >>= 1;                                  //shr cx, 1
    _cx >>= 1;                                  //shr cx, 1
    _cx -= 1;                                   //dec cx
    _cx -= 1;                                   //dec cx
    _si += _cx;                                 //add si, cx
    _ax = 0xb800;                               //mov ax, 0B800h
    _es = _ax;                                  //mov es, ax
    _ax = _seg001;                              //mov ax, seg seg001
    _ds = _ax;                                  //mov ds, ax
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
    _ch = _ch ^ _ch;                            //xor ch, ch
    _di = _cx;                                  //mov di, cx
    _di >>= 1;                                  //shr di, 1
    _di >>= 1;                                  //shr di, 1
    _flags.carry = _al & 1;                     //shr al, 1
    _al >>= 1;
    if (!_flags.carry)                          //jnb short loc_2F922
      goto loc_2F922;
    _di += 0x2000;                              //add di, 2000h
loc_2F922:                                      //loc_2F922:
    _ah = _ah ^ _ah;                            //xor ah, ah
    _cl = 0x04;                                 //mov cl, 4
    _ax <<= _cl;                                //shl ax, cl
    _di += _ax;                                 //add di, ax
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _cx = 0x0008;                               //mov cx, 8
loc_2F933:                                      //loc_2F933:
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_es, _di) = _ax;                   //mov es:[di], ax
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_es, _di + 2) = _ax;               //mov es:[di+2], ax
    _si += 0x2c;                                //add si, 2Ch
    if (_di < 0x2000)                           //jb short loc_2F94D
      goto loc_2F94D;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    if (--_cx)                                  //loop loc_2F933
      goto loc_2F933;
    goto loc_2F953;                             //jmp short loc_2F953
loc_2F94D:                                      //loc_2F94D:
    _di += 0x2000;                              //add di, 2000h
    if (--_cx)                                  //loop loc_2F933
      goto loc_2F933;
loc_2F953:                                      //loc_2F953:
    _ds = _pop();                               //pop ds
    _es = _pop();                               //pop es
    _flags.interrupt = true;                    //sti
}

void sub_2F97D()
{
    _si += 0x0c;                                //add si, 0Ch
    _di += 0x0c;                                //add di, 0Ch
loc_2F983:                                      //loc_2F983:
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _di -= 0x12;                                //sub di, 12h
    _cl = 0x06;                                 //mov cl, 6
loc_2F98A:                                      //loc_2F98A:
    _al = memory(_ds, _si);                     //mov al, [si]
    _si += 1;                                   //inc si
    _scasb();                                   //scasb
    if (_FIXME_)                                //ja short loc_2F99C
      goto loc_2F99C;
    if ((short)_si < 0)                         //jb short loc_2F996
      goto loc_2F996;
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2F98A
      goto loc_2F98A;
loc_2F996:                                      //loc_2F996:
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
    _di -= 0x0c;                                //sub di, 0Ch
    return;                                     //retn
loc_2F99C:                                      //loc_2F99C:
    _di = _pop();                               //pop di
    _di -= 0x0c;                                //sub di, 0Ch
    _si = _di;                                  //mov si, di
    _si -= 0x12;                                //sub si, 12h
    _cx = 0x0009;                               //mov cx, 9
    _rep_movsw<MemAuto, MemAuto, DirAuto>();    //rep movsw
    _di -= 0x18;                                //sub di, 18h
    _si = _pop();                               //pop si
    _dh -= 1;                                   //dec dh
    if (_dh != 0)                               //jnz short loc_2F983
      goto loc_2F983;
    _di -= 0x0c;                                //sub di, 0Ch
}

void sub_2FA24()
{
    sub_2FA0A();                                //call sub_2FA0A
    if (_FIXME_)                                //jnb short loc_2FA2A
      goto loc_2FA2A;
    return;                                     //retn
loc_2FA2A:                                      //loc_2FA2A:
    _push(_ax);                                 //push ax
    _push(_bp);                                 //push bp
    _dx = _dx ^ _dx;                            //xor dx, dx
    _cx = 0x0001;                               //mov cx, 1
    _bx = 0x0000;                               //mov bx, 0
    _interrupt(0x26);                           //int 26h
    _cx = _pop();                               //pop cx
    _bp = _pop();                               //pop bp
    _ax = _pop();                               //pop ax
    return;                                     //retn
    _STOP_("sp-trace-fail");                    //sub_2FA24 endp_failed
    _STOP_("continues");                        //sub_2FA3A proc near
}

void sub_2FBC7()
{
    _ax = _di;                                  //mov ax, di
    _bl = 0x50;                                 //mov bl, 50h
    _div(_bl);                                  //div bl
    _al |= _al;                                 //or al, al
    if (_al == 0)                               //jz short loc_2FBE6
      goto loc_2FBE6;
    if (_al != 0x60)                            //jnz short loc_2FBDC
      goto loc_2FBDC;
    _ah |= _ah;                                 //or ah, ah
    if (_ah == 0)                               //jz short loc_2FBEE
      goto loc_2FBEE;
    _di -= 1;                                   //dec di
    _di -= 1;                                   //dec di
    return;                                     //retn
loc_2FBDC:                                      //loc_2FBDC:
    if (_ah != 0x32)                            //jnz short loc_2FBEE
      goto loc_2FBEE;
loc_2FBE1:                                      //loc_2FBE1:
    _di += 0x0140;                              //add di, 140h
    return;                                     //retn
loc_2FBE6:                                      //loc_2FBE6:
    if (_ah == 0x32)                            //jz short loc_2FBE1
      goto loc_2FBE1;
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    return;                                     //retn
loc_2FBEE:                                      //loc_2FBEE:
    _di -= 0x0140;                              //sub di, 140h
}

void sub_2FBF3()
{
    _push(_di);                                 //push di
    _dl = 0x08;                                 //mov dl, 8
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_2FBF8:                                      //loc_2FBF8:
    memory16(_es, _di) = _ax;                   //mov es:[di], ax
    if (_di < 0x2000)                           //jb short loc_2FC07
      goto loc_2FC07;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2FC0B;                             //jmp short loc_2FC0B
loc_2FC07:                                      //loc_2FC07:
    _di += 0x2000;                              //add di, 2000h
loc_2FC0B:                                      //loc_2FC0B:
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2FBF8
      goto loc_2FBF8;
    _di = _pop();                               //pop di
}

void sub_2FC11()
{
    WORD _cs = _seg004;
    _push(_si);                                 //push si
    _push(_di);                                 //push di
    _si = 0x506d;                               //mov si, 506Dh
    _dl = 0x08;                                 //mov dl, 8
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_2FC1A:                                      //loc_2FC1A:
    _ax = memory16(_cs, _si);                   //mov ax, cs:[si]
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    memory16(_es, _di) = _ax;                   //mov es:[di], ax
    if (_di < 0x2000)                           //jb short loc_2FC2E
      goto loc_2FC2E;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2FC32;                             //jmp short loc_2FC32
loc_2FC2E:                                      //loc_2FC2E:
    _di += 0x2000;                              //add di, 2000h
loc_2FC32:                                      //loc_2FC32:
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz short loc_2FC1A
      goto loc_2FC1A;
    _di = _pop();                               //pop di
    _si = _pop();                               //pop si
}

void sub_2FC39()
{
    WORD _cs = _seg004;
    _bl = 0x1a;                                 //mov bl, 1Ah
loc_2FC3B:                                      //loc_2FC3B:
    _si = 0x506d;                               //mov si, 506Dh
    _push(_di);                                 //push di
    _cl = 0x08;                                 //mov cl, 8
loc_2FC41:                                      //loc_2FC41:
    _ax = memory16(_cs, _si);                   //mov ax, cs:[si]
    memory16(_es, _di) = _ax;                   //mov es:[di], ax
    if (_di < 0x2000)                           //jb short loc_2FC53
      goto loc_2FC53;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2FC57;                             //jmp short loc_2FC57
loc_2FC53:                                      //loc_2FC53:
    _di += 0x2000;                              //add di, 2000h
loc_2FC57:                                      //loc_2FC57:
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2FC41
      goto loc_2FC41;
    _di = _pop();                               //pop di
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    _bl -= 1;                                   //dec bl
    if (_bl != 0)                               //jnz short loc_2FC3B
      goto loc_2FC3B;
}

void sub_2FC65()
{
    WORD _cs = _seg004;
    _bl = 0x17;                                 //mov bl, 17h
loc_2FC67:                                      //loc_2FC67:
    _si = 0x506d;                               //mov si, 506Dh
    _cl = 0x08;                                 //mov cl, 8
loc_2FC6C:                                      //loc_2FC6C:
    _ax = memory16(_cs, _si);                   //mov ax, cs:[si]
    memory16(_es, _di) = _ax;                   //mov es:[di], ax
    if (_di < 0x2000)                           //jb short loc_2FC7E
      goto loc_2FC7E;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2FC82;                             //jmp short loc_2FC82
loc_2FC7E:                                      //loc_2FC7E:
    _di += 0x2000;                              //add di, 2000h
loc_2FC82:                                      //loc_2FC82:
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2FC6C
      goto loc_2FC6C;
    _bl -= 1;                                   //dec bl
    if (_bl != 0)                               //jnz short loc_2FC67
      goto loc_2FC67;
}

void sub_2FF37()
{
    _di = 0x34f8;                               //mov di, 34F8h
    _dh = 0x08;                                 //mov dh, 8
loc_2FF3C:                                      //loc_2FF3C:
    _bx = 0xb7a2;                               //mov bx, 0B7A2h
loc_2FF3F:                                      //loc_2FF3F:
    if (memory16(_ds, _bx) == 0xffff)           //jz short loc_2FF7F
      goto loc_2FF7F;
    _push(_di);                                 //push di
    _si = memory16(_ds, _bx);                   //mov si, [bx]
    _ch = 0x0f;                                 //mov ch, 0Fh
loc_2FF4A:                                      //loc_2FF4A:
    _bp = _di;                                  //mov bp, di
    _movsw<MemAuto, MemAuto, DirAuto>();        //movsw
    _movsw<MemAuto, MemAuto, DirAuto>();        //movsw
    _si += 1;                                   //inc si
    _di = _bp;                                  //mov di, bp
    if (_di < 0x2000)                           //jb short loc_2FF5D
      goto loc_2FF5D;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2FF61;                             //jmp short loc_2FF61
loc_2FF5D:                                      //loc_2FF5D:
    _di += 0x2000;                              //add di, 2000h
loc_2FF61:                                      //loc_2FF61:
    _ch -= 1;                                   //dec ch
    if (_ch != 0)                               //jnz short loc_2FF4A
      goto loc_2FF4A;
    _di = _pop();                               //pop di
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    _cx = 0x64;                                 //mov cx, 64h
loc_2FF6B:                                      //loc_2FF6B:
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(0x16);                           //int 16h
    if (_flags.zero)                            //jz short loc_2FF78
      goto loc_2FF78;
    _ah = _ah ^ _ah;                            //xor ah, ah
    _interrupt(0x16);                           //int 16h
    goto locret_2FFAC;                          //jmp locret_2FFAC
loc_2FF78:                                      //loc_2FF78:
    sub_2C26C();                                //call sub_2C26C
    if (--_cx)                                  //loop loc_2FF6B
      goto loc_2FF6B;
    goto loc_2FF3F;                             //jmp short loc_2FF3F
loc_2FF7F:                                      //loc_2FF7F:
    _ax = _ax ^ _ax;                            //xor ax, ax
    _push(_di);                                 //push di
    _ch = 0x0f;                                 //mov ch, 0Fh
loc_2FF84:                                      //loc_2FF84:
    _bp = _di;                                  //mov bp, di
    _stosw<MemAuto, DirAuto>();                 //stosw
    _stosw<MemAuto, DirAuto>();                 //stosw
    _di = _bp;                                  //mov di, bp
    if (_di < 0x2000)                           //jb short loc_2FF96
      goto loc_2FF96;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2FF9A;                             //jmp short loc_2FF9A
loc_2FF96:                                      //loc_2FF96:
    _di += 0x2000;                              //add di, 2000h
loc_2FF9A:                                      //loc_2FF9A:
    _ch -= 1;                                   //dec ch
    if (_ch != 0)                               //jnz short loc_2FF84
      goto loc_2FF84;
    _di = _pop();                               //pop di
    if (_dh != 0x05)                            //jnz short loc_2FFA5
      goto loc_2FFA5;
    _di += 1;                                   //inc di
loc_2FFA5:                                      //loc_2FFA5:
    _di += 0x0004;                              //add di, 4
    _dh -= 1;                                   //dec dh
    if (_dh != 0)                               //jnz short loc_2FF3C
      goto loc_2FF3C;
locret_2FFAC:                                   //locret_2FFAC:
    return;
}

void sub_2FFAD()
{
    _cl = 0x0f;                                 //mov cl, 0Fh
loc_2FFAF:                                      //loc_2FFAF:
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_es, _di) = _ax;                   //mov es:[di], ax
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_es, _di + 2) = _ax;               //mov es:[di+2], ax
    if (_di < 0x2000)                           //jb short loc_2FFC4
      goto loc_2FFC4;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_2FFC8;                             //jmp short loc_2FFC8
loc_2FFC4:                                      //loc_2FFC4:
    _di += 0x2000;                              //add di, 2000h
loc_2FFC8:                                      //loc_2FFC8:
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz short loc_2FFAF
      goto loc_2FFAF;
    _cx = 0x04b0;                               //mov cx, 4B0h
loc_2FFCF:                                      //loc_2FFCF:
    _ah = 0x01;                                 //mov ah, 1
    _interrupt(0x16);                           //int 16h
    if (_flags.zero)                            //jz short loc_2FFDC
      goto loc_2FFDC;
    _ah = _ah ^ _ah;                            //xor ah, ah
    _interrupt(0x16);                           //int 16h
    goto loc_2FFE0;                             //jmp loc_2FFE0
loc_2FFDC:                                      //loc_2FFDC:
    if (--_cx)                                  //loop loc_2FFCF
      goto loc_2FFCF;
    _flags.carry = false;                       //clc
    return;                                     //retn
loc_2FFE0:                                      //loc_2FFE0:
    _flags.carry = true;                        //stc
}

void sub_30068() // random
{
    //_ax =  rand() % _dx; // gabo!!
    //return;
    _di = 0x148d;                               //mov di, 148Dh
    _cx = memory16(_ds, 0x1413);                //mov cx, ds:1413h
loc_3006F:                                      //loc_3006F:
    _ax = _ax + memory16(_ds, _di);             //add ax, [di]
    _di += 1;                                   //inc di
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_3006F
      goto loc_3006F;
    _cx = _ds;                                  //mov cx, ds
    _bx = _bx ^ _bx;                            //xor bx, bx
    _ds = _bx;                                  //mov ds, bx
    // bios tick count 0000:046c http://www.vcfed.org/forum/entry.php?720-Variable-FPS-Animation-with-DDA
    // GABO
    //_ax = _ax + memory16(_ds, 0x46C);           //add ax, ds:46Ch
    //_ax = _ax + memory16(_ds, 0x46E);           //add ax, ds:46Eh
    _ax += rand();
    _ds = _cx;                                  //mov ds, cx
    _ax = _ax + memory16(_ds, 0x1ACD);          //add ax, ds:1ACDh
    _cx = _dx;                                  //mov cx, dx
    _dx = _dx ^ _dx;                            //xor dx, dx
    _div(_cx);                                  //div cx
    memory16(_ds, 0x1ACD) += _ax;               //add ds:1ACDh, ax
    _ax = _dx;                                  //mov ax, dx
}

void sub_30617()
{
    memory16(_ds, _si) = 0x68;                  //mov word ptr [si], 68h
    memory16(_ds, _si + 2) = 0x98;              //mov word ptr [si+2], 98h
    _dx = 0x0003;                               //mov dx, 3
    sub_30068();                                //call sub_30068
    _ax += 0x0008;                              //add ax, 8
    memory16(_ds, _si + 14) = _ax;              //mov [si+0Eh], ax
    _dx = 0x46;                                 //mov dx, 46h
    sub_30068();                                //call sub_30068
    _ax -= 0x23;                                //sub ax, 23h
    if (_ax != 0)                               //jnz short loc_3063A
      goto loc_3063A;
    _ax = 0x0a;                                 //mov ax, 0Ah
loc_3063A:                                      //loc_3063A:
    memory16(_ds, _si + 4) = _ax;               //mov [si+4], ax
    memory16(_ds, _si + 6) = _ax;               //mov [si+6], ax
    _dx = 0xffff;                               //mov dx, 0FFFFh
    if (_ax < 0x8000)                           //jb short loc_3064B
      goto loc_3064B;
    _dx = 0x0001;                               //mov dx, 1
loc_3064B:                                      //loc_3064B:
    memory16(_ds, _si + 12) = _dx;              //mov [si+0Ch], dx
    _ax = memory16(_ds, _si + 14);              //mov ax, [si+0Eh]
    _ax = memory16(_ds, _si + 4) * _al;         //imul word ptr [si+4]
    _ax = memory16(_ds, _si + 4) * _al;         //imul word ptr [si+4]
    _cx = 0x64;                                 //mov cx, 64h
    _idiv(_cx);                                 //idiv cx
    memory16(_ds, _si + 10) = _ax;              //mov [si+0Ah], ax
    memory16(_ds, _si + 8) = _ax;               //mov [si+8], ax
}

void sub_306FD()
{
    _flags.carry = _dx & 1;                     //shr dx, 1
    _dx >>= 1;
    if (_flags.carry)                           //jb short loc_30750
      goto loc_30750;
    _di = _di ^ _di;                            //xor di, di
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _ax = _dx;                                  //mov ax, dx
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax += _dx;                                 //add ax, dx
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _flags.carry = _cx & 1;                     //shr cx, 1
    _cx >>= 1;
    _ax = _ax + _ax + _flags.carry;;            //adc ax, ax
    _flags.carry = _cx & 1;                     //shr cx, 1
    _cx >>= 1;
    if (!_flags.carry)                          //jnb short loc_30722
      goto loc_30722;
    _ax += 0x0002;                              //add ax, 2
loc_30722:                                      //loc_30722:
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _cx;                                 //add di, cx
    _ax += 0x1acf;                              //add ax, 1ACFh
    _dx = _si;                                  //mov dx, si
    _si = _ax;                                  //mov si, ax
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_es, _di) = memory16(_es, _di) ^ _ax;//xor es:[di], ax
    _di += 0x2000;                              //add di, 2000h
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_es, _di) = memory16(_es, _di) ^ _ax;//xor es:[di], ax
    _di -= 0x1fb0;                              //sub di, 1FB0h
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_es, _di) = memory16(_es, _di) ^ _ax;//xor es:[di], ax
    _di += 0x2000;                              //add di, 2000h
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_es, _di) = memory16(_es, _di) ^ _ax;//xor es:[di], ax
    _si = _dx;                                  //mov si, dx
    return;                                     //retn
loc_30750:                                      //loc_30750:
    _di = 0x2000;                               //mov di, 2000h
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _dx <<= 1;                                  //shl dx, 1
    _ax = _dx;                                  //mov ax, dx
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax += _dx;                                 //add ax, dx
    _ax <<= 1;                                  //shl ax, 1
    _di += _ax;                                 //add di, ax
    _ax = _ax ^ _ax;                            //xor ax, ax
    _flags.carry = _cx & 1;                     //shr cx, 1
    _cx >>= 1;
    _ax = _ax + _ax + _flags.carry;;            //adc ax, ax
    _flags.carry = _cx & 1;                     //shr cx, 1
    _cx >>= 1;
    if (!_flags.carry)                          //jnb short loc_30772
      goto loc_30772;
    _ax += 0x0002;                              //add ax, 2
loc_30772:                                      //loc_30772:
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _di += _cx;                                 //add di, cx
    _ax += 0x1acf;                              //add ax, 1ACFh
    _dx = _si;                                  //mov dx, si
    _si = _ax;                                  //mov si, ax
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_es, _di) = memory16(_es, _di) ^ _ax;//xor es:[di], ax
    _di -= 0x1fb0;                              //sub di, 1FB0h
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_es, _di) = memory16(_es, _di) ^ _ax;//xor es:[di], ax
    _di += 0x2000;                              //add di, 2000h
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_es, _di) = memory16(_es, _di) ^ _ax;//xor es:[di], ax
    _di -= 0x1fb0;                              //sub di, 1FB0h
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_es, _di) = memory16(_es, _di) ^ _ax;//xor es:[di], ax
    _si = _dx;                                  //mov si, dx
}

void sub_30856()
{
    _al >>= 1;                                  //shr al, 1
    _al >>= 1;                                  //shr al, 1
    _bl = _ah;                                  //mov bl, ah
    _ah = _ah ^ _ah;                            //xor ah, ah
    _di = _ax;                                  //mov di, ax
    _flags.carry = _bl & 1;                     //shr bl, 1
    _bl >>= 1;
    if (!_flags.carry)                          //jnb short loc_30868
      goto loc_30868;
    _di += 0x2000;                              //add di, 2000h
loc_30868:                                      //loc_30868:
    _al = 0x50;                                 //mov al, 50h
    _ax = _bl * _al;                            //mul bl
    _di += _ax;                                 //add di, ax
    _push(_si);                                 //push si
    _si = 0x28d9;                               //mov si, 28D9h
    _cx = 0x0008;                               //mov cx, 8
loc_30875:                                      //loc_30875:
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    memory16(_es, _di) = memory16(_es, _di) ^ _ax;//xor es:[di], ax
    if (_di < 0x2000)                           //jb short loc_30885
      goto loc_30885;
    _di -= 0x1fb0;                              //sub di, 1FB0h
    goto loc_30889;                             //jmp short loc_30889
loc_30885:                                      //loc_30885:
    _di += 0x2000;                              //add di, 2000h
loc_30889:                                      //loc_30889:
    if (--_cx)                                  //loop loc_30875
      goto loc_30875;
    _si = _pop();                               //pop si
}

void sub_2D3D7()
{
    _dx = _cx;                                  //mov dx, cx
    _ax = memory16(_ds, _si + 2);               //mov ax, [si+2]
    _di = _si;                                  //mov di, si
loc_2D3DE:                                      //loc_2D3DE:
    _di += 0x0004;                              //add di, 4
    if (memory16(_ds, _di) == 0)                //jz short loc_2D3EB
      goto loc_2D3EB;
    if (memory16(_ds, _di + 2) == _ax)          //jz short loc_2D3F0
      goto loc_2D3F0;
loc_2D3EB:                                      //loc_2D3EB:
    if (--_cx)                                  //loop loc_2D3DE
      goto loc_2D3DE;
    _cx = _dx;                                  //mov cx, dx
    return;                                     //retn
loc_2D3F0:                                      //loc_2D3F0:
    memory16(_ds, _di) = 0;                     //mov word ptr [di], 0
    _cx = _dx;                                  //mov cx, dx
}

