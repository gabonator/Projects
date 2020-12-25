void sub_104F3();
void sub_10541();
void sub_10674();
void sub_10AD5();
void sub_1196F();
void sub_11A04();
void sub_11C0A();
void sub_11C56();
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
void sub_1215B();
void sub_122C1();
void sub_122E1();
void sub_122F9();
void sub_12311();
void sub_12329();
void sub_1237C();
void sub_12536();
void sub_1257E();
void sub_125C6();
void sub_12662();
void sub_12676();
void sub_12809();
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
void sub_13801();
void sub_13914();
void sub_123D4();
void sub_123EC();
void sub_12404();
void sub_1241C();
void sub_12434();
void sub_1244C();
void sub_11E7D();

// Imports:
void sub_120A0();
void sub_109B5();
void sub_12311();
void sub_122F9();
void sub_125E3();
void sub_12872();

void sub_12CC7();
void sub_12CEA();
void sub_1268A();
void sub_1269E();
void sub_122C1();


void sub_104F3()
{
    _flags.direction = false;                     //cld
loc_104F4:                                        //loc_104F4:
    _si = 0x8e8a;                                 //mov si, 8E8Ah
loc_104F7:                                        //loc_104F7:
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    if (_al == 0x00)                              //jz short loc_10520
      goto loc_10520;
    _ax = _si;                                    //mov ax, si
    _ax -= 0x8e8b;                                //sub ax, 8E8Bh
    if (_ax == 0x3b)                              //jz short loc_10520
      goto loc_10520;
    if (_ax == 0x3c)                              //jz short loc_10520
      goto loc_10520;
    if (_ax == 0x3d)                              //jz short loc_10520
      goto loc_10520;
    if (_ax == 0x3e)                              //jz short loc_10520
      goto loc_10520;
    if (_ax == 0x2a)                              //jz short loc_10520
      goto loc_10520;
    if (_ax == 0x36)                              //jz short loc_10520
      goto loc_10520;
    return;                                       //retn
loc_10520:                                        //loc_10520:
    if (_si != 0x8f0a)                            //jnz short loc_104F7
      goto loc_104F7;
    goto loc_104F4;                               //jmp short loc_104F4
}

void sub_10541()
{
    _cx = 0x4e20;                                 //mov cx, 4E20h
loc_10544:                                        //loc_10544:
    _si = 0x8e8a;                                 //mov si, 8E8Ah
    _ah = 0x00;                                   //mov ah, 0
    _flags.direction = false;                     //cld
loc_1054A:                                        //loc_1054A:
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    if (_al == 0x00)                              //jz short loc_10557
      goto loc_10557;
    _ah = 0x01;                                   //mov ah, 1
    if (_si != memory16(_ds, 0x8F0B))             //jnz short loc_1055F
      goto loc_1055F;
loc_10557:                                        //loc_10557:
    if (_si == 0x8f0a)                            //jz short loc_1055F
      goto loc_1055F;
    goto loc_1054A;                               //jmp short loc_1054A
loc_1055F:                                        //loc_1055F:
    ///
    if (_si == 0x8f0b)                                  //jz short loc_10578
      goto loc_10578;
    memory16(_ds, 0x8F0B) = _si;                  //mov word_1C95B, si
    _si -= 0x8e8b;                                //sub si, 8E8Bh
    _al = memory(_ds, _si + 90);                  //mov al, [si+5Ah]
    if (_al == 0x00)                              //jz short loc_10576
      goto loc_10576;
    if ((char)_al >= 0 /*CHECK*/)                 //jns short locret_10575
      goto locret_10575;
    _al = 0x00;                                   //mov al, 0
locret_10575:                                     //locret_10575:
    return;                                       //retn
loc_10576:                                        //loc_10576:
    goto loc_10583;                               //jmp short loc_10583
loc_10578:                                        //loc_10578:
    if (_ah != 0x00)                              //jnz short loc_10583
      goto loc_10583;
    memory16(_ds, 0x8F0B) = 0;                    //mov word_1C95B, 0
loc_10583:                                        //loc_10583:
    if (--_cx)                                    //loop loc_10544
      goto loc_10544;
    _al = 0x00;                                   //mov al, 0
}

void sub_10674()
{
    _push(_di);                                   //push di
    _push(_cx);                                   //push cx
    _cx = 0x0000;                                 //mov cx, 0
    _ax = 0x3c00;                                 //mov ax, 3C00h
    _interrupt(0x21);                             //int 21h
    _cx = _pop();                                 //pop cx
    _dx = _pop();                                 //pop dx
    if (!_flags.carry)                            //jnb short loc_10683
      goto loc_10683;
    return;                                       //retn
loc_10683:                                        //loc_10683:
    memory16(_ds, 0x8F1E) = _ax;                  //mov word_1C96E, ax
    _bx = _ax;                                    //mov bx, ax
    _ax = 0x4000;                                 //mov ax, 4000h
    _interrupt(0x21);                             //int 21h
    if (!_flags.carry)                            //jnb short loc_10690
      goto loc_10690;
    return;                                       //retn
loc_10690:                                        //loc_10690:
    _ax = 0x3e00;                                 //mov ax, 3E00h
    _bx = memory16(_ds, 0x8F1E);                  //mov bx, word_1C96E
    _interrupt(0x21);                             //int 21h
}

void sub_10AD5()
{
    _push(_bp);                                   //push bp
    _bp = _sp;                                    //mov bp, sp
    _bx = stack16(_bp, 4);                        //mov bx, [bp+arg_0]
    _bx <<= 1;                                    //shl bx, 1
    _si = _bx;                                    //mov si, bx
    _al = memory(_ds, 0x9502);                    //mov al, byte_1CF52
    if (_al != 0x01)                              //jnz short loc_10AEC
      goto loc_10AEC;
    _si += 0x80;                                  //add si, 80h
    goto loc_10AF4;                               //jmp short loc_10AF4
loc_10AEC:                                        //loc_10AEC:
    if (_al != 0x02)                              //jnz short loc_10AF4
      goto loc_10AF4;
    _si += 0x0100;                                //add si, 100h
loc_10AF4:                                        //loc_10AF4:
    _ax = memory16(_ds, _si - 27991);             //mov ax, [si-6D57h]
    _ax = _ax & memory16(_ds, _bx + -28119);      //and ax, [bx-6DD7h]
    if (_ax == 0x0000)                            //jz short loc_10B51
      goto loc_10B51;
    _bl = _ah;                                    //mov bl, ah
    _bl >>= 1;                                    //shr bl, 1
    _bl >>= 1;                                    //shr bl, 1
    _bh = 0x00;                                   //mov bh, 0
    _cl = memory(_ds, _bx + 693);                 //mov cl, [bx+2B5h]
    if (_cl == 0x00)                              //jz short loc_10B51
      goto loc_10B51;
    memory16(_ds, 0x942C) = 0x0a;                 //mov word_1CE7C, 0Ah
    _bx <<= 1;                                    //shl bx, 1
    _dx = memory16(_ds, _bx + 714);               //mov dx, [bx+2CAh]
    _dx -= 0x0e;                                  //sub dx, 0Eh
    _bx = memory16(_ds, _bx + 756);               //mov bx, [bx+2F4h]
    _cx = 0x0a;                                   //mov cx, 0Ah
loc_10B28:                                        //loc_10B28:
    _flags.carry = _ax & 1;                       //shr ax, 1
    _ax >>= 1;
    if (!_flags.carry)                            //jnb short loc_10B48
      goto loc_10B48;
    _push(_bx);                                   //push bx
    _bx -= _dx;                                   //sub bx, dx
    if ((short)_bx > (short)stack16(_bp, 6))      //jg short loc_10B47
      goto loc_10B47;
    _bx += _dx;                                   //add bx, dx
    _bx += _dx;                                   //add bx, dx
    if ((short)_bx < (short)stack16(_bp, 6))      //jl short loc_10B47
      goto loc_10B47;
    _ax = _pop();                                 //pop ax
    _ax = 0x0001;                                 //mov ax, 1
    _bx = memory16(_ds, 0x942C);                  //mov bx, word_1CE7C
    goto loc_10B54;                               //jmp short loc_10B54
loc_10B47:                                        //loc_10B47:
    _bx = _pop();                                 //pop bx
loc_10B48:                                        //loc_10B48:
    _bx -= 0x18;                                  //sub bx, 18h
    memory16(_ds, 0x942C) -= 1;                   //dec word_1CE7C
    if (--_cx)                                    //loop loc_10B28
      goto loc_10B28;
loc_10B51:                                        //loc_10B51:
    _ax = 0x0000;                                 //mov ax, 0
loc_10B54:                                        //loc_10B54:
    _bp = _pop();                                 //pop bp
    _stackReduce(4);                              //retn 4
    return;
}

void sub_1196F()
{
    _al = memory(_ds, 0x1B8E);                    //mov al, byte_155DE
    if (_al != 0x00)                              //jnz short loc_11982
      goto loc_11982;
    memory(_ds, 0x951D) = 0xf0;                   //mov byte_1CF6D, 0F0h
    memory(_ds, 0x94FF) = 1;                      //mov byte_1CF4F, 1
    goto locret_11992;                            //jmp short locret_11992
loc_11982:                                        //loc_11982:
    _push(_si);                                   //push si
    memory(_ds, 0x1B8E) = 0;                      //mov byte_155DE, 0
    _si = 0x1b8a;                                 //mov si, 1B8Ah
    _bx = 0x0d49;                                 //mov bx, 0D49h
    sub_12121();                                  //call sub_12121
    _si = _pop();                                 //pop si
locret_11992:                                     //locret_11992:
    return;
}

void sub_11A04()
{
    _ax = memory16(_ds, 0x1B8F);                  //mov ax, word_155DF
    _ax = _ax - memory16(_ds, _si + 5);           //sub ax, [si+5]
    _ax -= 0x0c;
    _flags.sign = (short)(_ax) < 0;      //sub ax, 0Ch
    if (!_flags.sign)                              //jns short loc_11A11
      goto loc_11A11;
    _ax = -_ax;                                   //neg ax
loc_11A11:                                        //loc_11A11:
    _cx = memory16(_ds, 0x1B91);                  //mov cx, word_155E1
    _flags.sign = (short)(_cx - memory16(_ds, _si + 7)) < 0;
    _cx = _cx - memory16(_ds, _si + 7);
    if (!_flags.sign)                              //jns short loc_11A1C
      goto loc_11A1C;
    _cx = -_cx;                                   //neg cx
loc_11A1C:                                        //loc_11A1C:
    _bl = memory(_ds, _si + 4);                   //mov bl, [si+4]
    _bl >>= 1;                                    //shr bl, 1
    _ax += _cx;                                   //add ax, cx
    if (_ax > 0x40)                               //ja short loc_11A32
      goto loc_11A32;
    if (_bl == 0x06)                              //jz short loc_11A30
      goto loc_11A30;
    memory(_ds, _si + 4) += 1;                    //inc byte ptr [si+4]
loc_11A30:                                        //loc_11A30:
    goto loc_11A3A;                               //jmp short loc_11A3A
loc_11A32:                                        //loc_11A32:
    if (_bl == 0x00)                              //jz short loc_11A3A
      goto loc_11A3A;
    memory(_ds, _si + 4) -= 1;                    //dec byte ptr [si+4]
loc_11A3A:                                        //loc_11A3A:
    if (_bl != 0x06)                              //jnz short loc_11A45
      goto loc_11A45;
    memory(_ds, _si + 2) = 0;                     //mov byte ptr [si+2], 0
    goto loc_11A56;                               //jmp short loc_11A56
loc_11A45:                                        //loc_11A45:
    _push(_bx);                                   //push bx
    memory(_ds, _si + 2) = 7;                     //mov byte ptr [si+2], 7
    _bh = 0x00;                                   //mov bh, 0
    _bx <<= 1;                                    //shl bx, 1
    _ax = memory16(_ds, _bx + 5239);              //mov ax, [bx+1477h]
    memory16(_ds, _si + 15) = _ax;                //mov [si+0Fh], ax
    _bx = _pop();                                 //pop bx
loc_11A56:                                        //loc_11A56:
    if (_bl < 0x01)                               //jb short loc_11A9A
      goto loc_11A9A;
    _ax = memory16(_ds, 0x1B8F);                  //mov ax, word_155DF
    _ax = _ax - memory16(_ds, _si + 5);           //sub ax, [si+5]
    _ax -= 0x0c;
    _flags.sign = (short)_ax < 0;      //sub ax, 0Ch
    if (!_flags.sign)                              //jns short loc_11A73
      goto loc_11A73;
    _ax = -_ax;                                   //neg ax
    if (_ax > 0x18)                               //ja short loc_11A71
      goto loc_11A71;
    memory16(_ds, 0x1B8F) += 1;                   //inc word_155DF
loc_11A71:                                        //loc_11A71:
    goto loc_11A7E;                               //jmp short loc_11A7E
loc_11A73:                                        //loc_11A73:
    if (_ax == 0)                                 //jz short loc_11A7E
      goto loc_11A7E;
    if (_ax > 0x18)                               //ja short loc_11A7E
      goto loc_11A7E;
    memory16(_ds, 0x1B8F) -= 1;                   //dec word_155DF
loc_11A7E:                                        //loc_11A7E:
    if (_cx > 0x0008)                             //ja short loc_11A9A
      goto loc_11A9A;
    if (_ax > 0x0008)                             //ja short loc_11A9A
      goto loc_11A9A;
    _al = memory(_ds, 0x1B9C);                    //mov al, byte_155EC
    if (_al == 0x11)                              //jz short loc_11A9A
      goto loc_11A9A;
    _ax = memory16(_ds, 0x1B8F);                  //mov ax, word_155DF
    memory16(_ds, 0x950A) = _ax;                  //mov word_1CF5A, ax
    memory(_ds, 0x94FF) = 1;                      //mov byte_1CF4F, 1
loc_11A9A:                                        //loc_11A9A:
    sub_110C6();                                  //call sub_110C6
}

void sub_11C0A()
{
    _push(_bp);                                   //push bp
    _bp = _sp;                                    //mov bp, sp
    _bx = stack16(_bp, 6);                        //mov bx, [bp+arg_2]
    _cx = stack16(_bp, 4);                        //mov cx, [bp+arg_0]
    _si = 0x1b8a;                                 //mov si, 1B8Ah
loc_11C16:                                        //loc_11C16:
    _al = memory(_ds, _si);                       //mov al, [si]
    if (_al & 0x80)                               //jnz short loc_11C2F
      goto loc_11C2F;
    if (!(_al & 0x08))                            //jz short loc_11C2A
      goto loc_11C2A;
    if (_cl != memory(_ds, _si + 20))             //jnz short loc_11C2A
      goto loc_11C2A;
    if (_bl == memory(_ds, _si + 19))             //jz short loc_11C2F
      goto loc_11C2F;
loc_11C2A:                                        //loc_11C2A:
    _si += 0x17;                                  //add si, 17h
    goto loc_11C16;                               //jmp short loc_11C16
loc_11C2F:                                        //loc_11C2F:
    _bp = _pop();                                 //pop bp
    _stackReduce(4);                              //retn 4
    return;
}

void sub_11C56()
{
    _ax = -_ax;                                   //neg ax
    memory16(_ds, 0x9544) = _ax;                  //mov word_1CF94, ax
    _push(_ax);                                   //push ax
    _al = 0x06;                                   //mov al, 6
    sub_13840();                                  //call sub_13840
    _ax = _pop();                                 //pop ax
    _ax = _bx;                                    //mov ax, bx
    _push(_ax);                                   //push ax
    _al = memory(_ds, 0x1B9E);                    //mov al, byte_155EE
    _ah = 0x00;                                   //mov ah, 0
    _push(_ax);                                   //push ax
    sub_11C0A();                                  //call sub_11C0A
    _al = memory(_ds, _si);                       //mov al, [si]
    if (_al & 0x80)                               //jnz short locret_11C77
      goto locret_11C77;
    sub_120DB();                                  //call sub_120DB
locret_11C77:                                     //locret_11C77:
    return;
}

void sub_11CD9()
{
    _ax = memory16(_ds, 0x9439);                  //mov ax, word_1CE89
    memory16(_ds, _si + 5) = _ax;                 //mov [si+5], ax
    _ax = memory16(_ds, 0x9441);                  //mov ax, word_1CE91
    _ax += 0x0006;                                //add ax, 6
    _ax &= 0x03ff;                                //and ax, 3FFh
    memory16(_ds, _si + 7) = _ax;                 //mov [si+7], ax
    _al = memory(_ds, 0x9446);                    //mov al, byte_1CE96
    memory(_ds, _si + 4) = _al;                   //mov [si+4], al
    _bl = _al;                                    //mov bl, al
    _bh = 0x00;                                   //mov bh, 0
    _cl = memory(_ds, _bx + 3513);                //mov cl, [bx+0DB9h]
    _al = memory(_ds, 0x944A);                    //mov al, byte_1CE9A
    _al += 0x06;                                  //add al, 6
    memory(_ds, _si + 3) = _al;                   //mov [si+3], al
    _al = memory(_ds, _si);                       //mov al, [si]
    if (_al & 0x20)                               //jnz short loc_11D10
      goto loc_11D10;
    memory16(_ds, _si + 5) -= 8;                  //sub word ptr [si+5], 8
    memory(_ds, _si + 3) += _cl;                  //add [si+3], cl
    goto loc_11D17;                               //jmp short loc_11D17
loc_11D10:                                        //loc_11D10:
    memory16(_ds, _si + 5) += 8;                  //add word ptr [si+5], 8
    memory(_ds, _si + 3) -= _cl;                  //sub [si+3], cl
loc_11D17:                                        //loc_11D17:
    _bx = 0x0dda;                                 //mov bx, 0DDAh
    sub_12121();                                  //call sub_12121
}

void sub_11D1E()
{
    _si = 0x135e;                                 //mov si, 135Eh
    memory(_ds, _si) &= 0xdf;                     //and byte ptr [si], 0DFh
    _bl = memory(_ds, 0x1B8E);                    //mov bl, byte_155DE
    _bh = 0x00;                                   //mov bh, 0
    _al = memory(_ds, _bx + 5021);                //mov al, [bx+139Dh]
    memory(_ds, _si + 4) = _al;                   //mov [si+4], al
    _al = memory(_ds, _bx + 4981);                //mov al, [bx+1375h]
    _cbw();                                       //cbw
    _ax = _ax + memory16(_ds, 0x1B8F);            //add ax, word_155DF
    memory16(_ds, _si + 5) = _ax;                 //mov [si+5], ax
    _ax = memory16(_ds, 0x1B91);                  //mov ax, word_155E1
    _ax -= 0x0004;                                //sub ax, 4
    _ax &= 0x03ff;                                //and ax, 3FFh
    memory16(_ds, _si + 7) = _ax;                 //mov [si+7], ax
    _al = memory(_ds, 0x1B8D);                    //mov al, byte_155DD
    _al = _al + memory(_ds, _bx + 5001);          //add al, [bx+1389h]
    memory(_ds, _si + 3) = _al;                   //mov [si+3], al
    _bl = memory(_ds, _si + 4);                   //mov bl, [si+4]
    _bh = 0x00;                                   //mov bh, 0
    _al = memory(_ds, _bx + 5031);                //mov al, [bx+13A7h]
    memory(_ds, _si + 10) = _al;                  //mov [si+0Ah], al
    _bx <<= 1;                                    //shl bx, 1
    _ax = memory16(_ds, _bx + 5034);              //mov ax, [bx+13AAh]
    memory16(_ds, _si + 15) = _ax;                //mov [si+0Fh], ax
    sub_10B58();                                  //call sub_10B58
    _si = 0x0ff7;                                 //mov si, 0FF7h
    _ax = memory16(_ds, 0x1363);                  //mov ax, word_14DB3
    memory16(_ds, _si + 5) = _ax;                 //mov [si+5], ax
    _ax = memory16(_ds, 0x1365);                  //mov ax, word_14DB5
    memory16(_ds, _si + 7) = _ax;                 //mov [si+7], ax
    _al = memory(_ds, 0x1361);                    //mov al, byte_14DB1
    memory(_ds, _si + 3) = _al;                   //mov [si+3], al
    memory(_ds, 0x9516) += 1;                     //inc byte_1CF66
    _bl = memory(_ds, 0x9516);                    //mov bl, byte_1CF66
    _bx &= 0x0f;                                  //and bx, 0Fh
    _al = memory(_ds, _bx + 4071);                //mov al, [bx+0FE7h]
    memory(_ds, _si + 4) = _al;                   //mov [si+4], al
    _bx = 0x100e;                                 //mov bx, 100Eh
    sub_12121();                                  //call sub_12121
    sub_10B58();                                  //call sub_10B58
    _si = 0x135e;                                 //mov si, 135Eh
    memory(_ds, _si) |= 0x20;                     //or byte ptr [si], 20h
    _bl = memory(_ds, 0x1B8E);                    //mov bl, byte_155DE
    _bh = 0x00;                                   //mov bh, 0
    _al = memory(_ds, _bx + 4991);                //mov al, [bx+137Fh]
    _cbw();                                       //cbw
    _ax = _ax + memory16(_ds, 0x1B8F);            //add ax, word_155DF
    memory16(_ds, _si + 5) = _ax;                 //mov [si+5], ax
    _al = memory(_ds, 0x1B8D);                    //mov al, byte_155DD
    _al = _al + memory(_ds, _bx + 5011);          //add al, [bx+1393h]
    memory(_ds, _si + 3) = _al;                   //mov [si+3], al
    sub_10B58();                                  //call sub_10B58
    _si = 0x0ff7;                                 //mov si, 0FF7h
    _ax = memory16(_ds, 0x1363);                  //mov ax, word_14DB3
    memory16(_ds, _si + 5) = _ax;                 //mov [si+5], ax
    _ax = memory16(_ds, 0x1365);                  //mov ax, word_14DB5
    memory16(_ds, _si + 7) = _ax;                 //mov [si+7], ax
    _al = memory(_ds, 0x1361);                    //mov al, byte_14DB1
    memory(_ds, _si + 3) = _al;                   //mov [si+3], al
    sub_10B58();                                  //call sub_10B58
    _ax = memory16(_ds, 0x9511);                  //mov ax, word_1CF61
    _ax += _bx;                                   //add ax, bx
    if (_ax <= 0x10)                              //jbe short loc_11DEB
      goto loc_11DEB;
    _ax = 0x0000;                                 //mov ax, 0
    memory16(_ds, 0x9540) = 0xffff;               //mov word_1CF90, 0FFFFh
loc_11DEB:                                        //loc_11DEB:
    memory16(_ds, 0x9511) = _ax;                  //mov word_1CF61, ax
}

void sub_11DEF()
{
    memory(_ds, 0x9516) += 1;                     //inc byte_1CF66
    _bl = memory(_ds, 0x9516);                    //mov bl, byte_1CF66
    _bx &= 0x0f;                                  //and bx, 0Fh
    _al = memory(_ds, _bx + 4071);                //mov al, [bx+0FE7h]
    memory(_ds, 0xFFB) = _al;                     //mov byte_14A4B, al
    _al = memory(_ds, _si + 1);                   //mov al, [si+1]
    if (_al != 0x00)                              //jnz short loc_11E2E
      goto loc_11E2E;
    _bl = memory(_ds, _si + 4);                   //mov bl, [si+4]
    _bh = 0x00;                                   //mov bh, 0
    _cl = memory(_ds, _bx + 5069);                //mov cl, [bx+13CDh]
    _ax = 0xfffd;                                 //mov ax, 0FFFDh
    _bx = 0x0008;                                 //mov bx, 8
    sub_11E7D();                                  //call sub_11E7D
    _bl = memory(_ds, _si + 4);                   //mov bl, [si+4]
    _bh = 0x00;                                   //mov bh, 0
    _cl = memory(_ds, _bx + 5079);                //mov cl, [bx+13D7h]
    _ax = 0x0003;                                 //mov ax, 3
    _bx = 0x0008;                                 //mov bx, 8
    sub_11E7D();                                  //call sub_11E7D
    goto locret_11E7C;                            //jmp short locret_11E7C
loc_11E2E:                                        //loc_11E2E:
    if (_al != 0x01)                              //jnz short loc_11E46
      goto loc_11E46;
    _bl = memory(_ds, _si + 4);                   //mov bl, [si+4]
    _bh = 0x00;                                   //mov bh, 0
    _cl = memory(_ds, _bx + 5089);                //mov cl, [bx+13E1h]
    _ax = 0x0000;                                 //mov ax, 0
    _bx = 0x0008;                                 //mov bx, 8
    sub_11E7D();                                  //call sub_11E7D
    goto locret_11E7C;                            //jmp short locret_11E7C
loc_11E46:                                        //loc_11E46:
    _bl = memory(_ds, _si + 4);                   //mov bl, [si+4]
    _bh = 0x00;                                   //mov bh, 0
    _cl = memory(_ds, _bx + 5099);                //mov cl, [bx+13EBh]
    _ax = 0xfff9;                                 //mov ax, 0FFF9h
    _bx = 0x0008;                                 //mov bx, 8
    sub_11E7D();                                  //call sub_11E7D
    _bl = memory(_ds, _si + 4);                   //mov bl, [si+4]
    _bh = 0x00;                                   //mov bh, 0
    _cl = memory(_ds, _bx + 5109);                //mov cl, [bx+13F5h]
    _ax = 0x0000;                                 //mov ax, 0
    _bx = 0x0b;                                   //mov bx, 0Bh
    sub_11E7D();                                  //call sub_11E7D
    _bl = memory(_ds, _si + 4);                   //mov bl, [si+4]
    _bh = 0x00;                                   //mov bh, 0
    _cl = memory(_ds, _bx + 5119);                //mov cl, [bx+13FFh]
    _ax = 0x0007;                                 //mov ax, 7
    _bx = 0x0008;                                 //mov bx, 8
    sub_11E7D();                                  //call sub_11E7D
locret_11E7C:                                     //locret_11E7C:
    return;
}

void sub_11F0B()
{
    _push(_si);                                   //push si
    memory(_ds, 0x9516) += 1;                     //inc byte_1CF66
    _bl = memory(_ds, 0x9516);                    //mov bl, byte_1CF66
    _bx &= 0x0f;                                  //and bx, 0Fh
    _al = memory(_ds, _bx + 4071);                //mov al, [bx+0FE7h]
    memory(_ds, 0xFFB) = _al;                     //mov byte_14A4B, al
    _di = 0x0ff7;                                 //mov di, 0FF7h
    _bl = memory(_ds, _si + 4);                   //mov bl, [si+4]
    _bh = 0x00;                                   //mov bh, 0
    _al = memory(_ds, _bx + 5129);                //mov al, [bx+1409h]
    _cbw();                                       //cbw
    _ax = _ax + memory16(_ds, _si + 5);           //add ax, [si+5]
    memory16(_ds, _di + 5) = _ax;                 //mov [di+5], ax
    _al = memory(_ds, _bx + 5134);                //mov al, [bx+140Eh]
    _cbw();                                       //cbw
    _ax = _ax + memory16(_ds, _si + 7);           //add ax, [si+7]
    _ax &= 0x03ff;                                //and ax, 3FFh
    memory16(_ds, _di + 7) = _ax;                 //mov [di+7], ax
    _al = memory(_ds, _si + 3);                   //mov al, [si+3]
    _al += 0x04;                                  //add al, 4
    memory(_ds, _di + 3) = _al;                   //mov [di+3], al
    _bx <<= 1;                                    //shl bx, 1
    _bx = memory16(_ds, _bx + 4143);              //mov bx, [bx+102Fh]
    _si = _di;                                    //mov si, di
    sub_12121();                                  //call sub_12121
    sub_10B58();                                  //call sub_10B58
    if (_si == 0x0000)                            //jz short loc_11F63
      goto loc_11F63;
    _ax = _pop();                                 //pop ax
    _push(_ax);                                   //push ax
    if (_ax <= _si)                               //jbe short loc_11F63
      goto loc_11F63;
    sub_116D6();                                  //call sub_116D6
loc_11F63:                                        //loc_11F63:
    _si = _pop();                                 //pop si
    _al = memory(_ds, 0x9518);                    //mov al, byte_1CF68
    if (_al != 0x00)                              //jnz short loc_11F6C
      goto loc_11F6C;
    return;                                       //retn
loc_11F6C:                                        //loc_11F6C:
    _push(_si);                                   //push si
    _di = 0x13b0;                                 //mov di, 13B0h
    _bl = memory(_ds, _si + 4);                   //mov bl, [si+4]
    _bh = 0x00;                                   //mov bh, 0
    memory(_ds, _di + 1) = _bl;                   //mov [di+1], bl
    _ax = memory16(_ds, 0xFFC);                   //mov ax, word_14A4C
    memory16(_ds, _di + 5) = _ax;                 //mov [di+5], ax
    _ax = memory16(_ds, 0xFFE);                   //mov ax, word_14A4E
    memory16(_ds, _di + 7) = _ax;                 //mov [di+7], ax
    _al = memory(_ds, 0xFFA);                     //mov al, byte_14A4A
    memory(_ds, _di + 3) = _al;                   //mov [di+3], al
    _al = memory(_ds, _bx + 5139);                //mov al, [bx+1413h]
    memory(_ds, _di + 9) = _al;                   //mov [di+9], al
    _al = memory(_ds, _bx + 5144);                //mov al, [bx+1418h]
    memory(_ds, _di + 10) = _al;                  //mov [di+0Ah], al
    memory(_ds, _di + 4) = 0;                     //mov byte ptr [di+4], 0
    _bx <<= 1;                                    //shl bx, 1
    _ax = memory16(_ds, _bx + 5149);              //mov ax, [bx+141Dh]
    memory16(_ds, _di + 15) = _ax;                //mov [di+0Fh], ax
    _si = _di;                                    //mov si, di
    sub_10B58();                                  //call sub_10B58
    if (_si == 0x0000)                            //jz short loc_11FB8
      goto loc_11FB8;
    _ax = _pop();                                 //pop ax
    _push(_ax);                                   //push ax
    if (_ax <= _si)                               //jbe short loc_11FB8
      goto loc_11FB8;
    sub_115FC();                                  //call sub_115FC
loc_11FB8:                                        //loc_11FB8:
    _si = _pop();                                 //pop si
}

void sub_11FBA()
{
    _push(_si);                                   //push si
    _di = 0x10e8;                                 //mov di, 10E8h
    _bl = memory(_ds, _si + 4);                   //mov bl, [si+4]
    memory(_ds, _di + 1) = _bl;                   //mov [di+1], bl
    _bh = 0x00;                                   //mov bh, 0
    _al = memory(_ds, _bx + 4318);                //mov al, [bx+10DEh]
    _cbw();                                       //cbw
    _ax = _ax + memory16(_ds, _si + 5);           //add ax, [si+5]
    memory16(_ds, _di + 5) = _ax;                 //mov [di+5], ax
    _al = memory(_ds, _bx + 4323);                //mov al, [bx+10E3h]
    _cbw();                                       //cbw
    _ax = _ax + memory16(_ds, _si + 7);           //add ax, [si+7]
    _ax &= 0x03ff;                                //and ax, 3FFh
    memory16(_ds, _di + 7) = _ax;                 //mov [di+7], ax
    _al = memory(_ds, _si + 3);                   //mov al, [si+3]
    _al += 0x08;                                  //add al, 8
    memory(_ds, _di + 3) = _al;                   //mov [di+3], al
    _bx <<= 1;                                    //shl bx, 1
    _bx = memory16(_ds, _bx + 4351);              //mov bx, [bx+10FFh]
    _si = _di;                                    //mov si, di
    sub_12121();                                  //call sub_12121
    sub_10B58();                                  //call sub_10B58
    if (_si == 0x0000)                            //jz short loc_12003
      goto loc_12003;
    _ax = _pop();                                 //pop ax
    _push(_ax);                                   //push ax
    if (_ax <= _si)                               //jbe short loc_12003
      goto loc_12003;
    sub_11429();                                  //call sub_11429
loc_12003:                                        //loc_12003:
    _si = _pop();                                 //pop si
}

void sub_12005()
{
    _push(_si);                                   //push si
    _di = 0x1446;                                 //mov di, 1446h
    _bl = memory(_ds, _si + 4);                   //mov bl, [si+4]
    memory(_ds, _di + 1) = _bl;                   //mov [di+1], bl
    _bh = 0x00;                                   //mov bh, 0
    _al = memory(_ds, _bx + 5213);                //mov al, [bx+145Dh]
    _cbw();                                       //cbw
    _ax = _ax + memory16(_ds, _si + 5);           //add ax, [si+5]
    memory16(_ds, _di + 5) = _ax;                 //mov [di+5], ax
    _al = memory(_ds, _bx + 5218);                //mov al, [bx+1462h]
    _cbw();                                       //cbw
    _ax = _ax + memory16(_ds, _si + 7);           //add ax, [si+7]
    _ax &= 0x03ff;                                //and ax, 3FFh
    memory16(_ds, _di + 7) = _ax;                 //mov [di+7], ax
    _al = memory(_ds, _si + 3);                   //mov al, [si+3]
    _al += 0x08;                                  //add al, 8
    memory(_ds, _di + 3) = _al;                   //mov [di+3], al
    _si = _di;                                    //mov si, di
    sub_10B58();                                  //call sub_10B58
    if (_si == 0x0000)                            //jz short loc_12045
      goto loc_12045;
    _ax = _pop();                                 //pop ax
    _push(_ax);                                   //push ax
    if (_ax <= _si)                               //jbe short loc_12045
      goto loc_12045;
    sub_117F4();                                  //call sub_117F4
loc_12045:                                        //loc_12045:
    _si = _pop();                                 //pop si
}

void sub_12047()
{
    _al = memory(_ds, _si);                       //mov al, [si]
    _bl = memory(_ds, 0x9517);                    //mov bl, byte_1CF67
    if (!(_al & 0x20))                            //jz short loc_12072
      goto loc_12072;
    if (_bl & 0x80)                               //jnz short loc_1206D
      goto loc_1206D;
    memory(_ds, 0x9517) |= 0x80;                  //or byte_1CF67, 80h
    memory(_ds, 0x1326) |= 0x20;                  //or byte_14D76, 20h
    _di = 0x1326;                                 //mov di, 1326h
    sub_120A0();                                  //call sub_120A0
    _al = 0x03;                                   //mov al, 3
    sub_13840();                                  //call sub_13840
    goto loc_12070;                               //jmp short loc_12070
loc_1206D:                                        //loc_1206D:
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
loc_12070:                                        //loc_12070:
    goto locret_12091;                            //jmp short locret_12091
loc_12072:                                        //loc_12072:
    if (_bl & 0x01)                               //jnz short loc_1208E
      goto loc_1208E;
    memory(_ds, 0x9517) |= 1;                     //or byte_1CF67, 1
    memory(_ds, 0x1326) &= 0xdf;                  //and byte_14D76, 0DFh
    _di = 0x1326;                                 //mov di, 1326h
    sub_120A0();                                  //call sub_120A0
    _al = 0x03;                                   //mov al, 3
    sub_13840();                                  //call sub_13840
    goto locret_12091;                            //jmp short locret_12091
loc_1208E:                                        //loc_1208E:
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
locret_12091:                                     //locret_12091:
    return;
}

void sub_12092()
{
    _di = 0x1427;                                 //mov di, 1427h
    sub_120A0();                                  //call sub_120A0
}

void sub_12099()
{
    _di = 0x12de;                                 //mov di, 12DEh
    sub_120A0();                                  //call sub_120A0
}

void sub_120DB()
{
    sub_12676();                                  //call sub_12676
    sub_120F0();                                  //call sub_120F0
    _push(_si);                                   //push si
    _al = memory(_ds, _si + 19);                  //mov al, [si+13h]
    _ah = 0x00;                                   //mov ah, 0
    _push(_ax);                                   //push ax
    _al = memory(_ds, _si + 20);                  //mov al, [si+14h]
    _push(_ax);                                   //push ax
    sub_109B5();                                  //call sub_109B5
}

void sub_1215B()
{
    _cx = 0x0001;                                 //mov cx, 1
    _ax = memory16(_ds, 0x1B91);                  //mov ax, word_155E1
    _ax = _ax - memory16(_ds, _si + 7);           //sub ax, [si+7]
    if ((short)_ax <= (short)0x8c)                //jle short loc_12171
      goto loc_12171;
    memory(_ds, _si + 4) = 2;                     //mov byte ptr [si+4], 2
    _cx = 0x0000;                                 //mov cx, 0
    return;                                       //retn
loc_12171:                                        //loc_12171:
    if ((short)_ax >= (short)0xfff0)              //jge short loc_121A0
      goto loc_121A0;
    _ah = memory(_ds, _si + 4);                   //mov ah, [si+4]
    _al = memory(_ds, _si);                       //mov al, [si]
    if (!(_al & 0x20))                            //jz short loc_1218D
      goto loc_1218D;
    _ah += 1;                                     //inc ah
    if ((char)_ah <= (char)0x04)                  //jle short loc_1218B
      goto loc_1218B;
    memory(_ds, _si) &= 0xdf;                     //and byte ptr [si], 0DFh
    _ah = 0x04;                                   //mov ah, 4
loc_1218B:                                        //loc_1218B:
    goto loc_12199;                               //jmp short loc_12199
loc_1218D:                                        //loc_1218D:
    _ah -= 1;                                     //dec ah
    if ((char)_ah >= (char)0x00)                  //jge short loc_12199
      goto loc_12199;
    memory(_ds, _si) |= 0x20;                     //or byte ptr [si], 20h
    _ah = 0x00;                                   //mov ah, 0
loc_12199:                                        //loc_12199:
    memory(_ds, _si + 4) = _ah;                   //mov [si+4], ah
    _cx = 0x0000;                                 //mov cx, 0
    return;                                       //retn
loc_121A0:                                        //loc_121A0:
    _bx = memory16(_ds, 0x1B8F);                  //mov bx, word_155DF
    _flags.sign = (short)(_bx - memory16(_ds, _si + 5)) < 0;
    _bx = _bx - memory16(_ds, _si + 5);
    if (!_flags.sign)                              //jns short loc_121C2
      goto loc_121C2;
    if ((short)_bx <= (short)0xffe0)              //jle short loc_121B3
      goto loc_121B3;
    memory(_ds, _si + 4) = 2;                     //mov byte ptr [si+4], 2
    return;                                       //retn
loc_121B3:                                        //loc_121B3:
    if ((short)_ax <= (short)0x20)                //jle short loc_121BD
      goto loc_121BD;
    memory(_ds, _si + 4) = 1;                     //mov byte ptr [si+4], 1
    return;                                       //retn
loc_121BD:                                        //loc_121BD:
    memory(_ds, _si + 4) = 0;                     //mov byte ptr [si+4], 0
    return;                                       //retn
loc_121C2:                                        //loc_121C2:
    if ((short)_bx >= (short)0x20)                //jge short loc_121CC
      goto loc_121CC;
    memory(_ds, _si + 4) = 2;                     //mov byte ptr [si+4], 2
    return;                                       //retn
loc_121CC:                                        //loc_121CC:
    if ((short)_ax <= (short)0x20)                //jle short loc_121D6
      goto loc_121D6;
    memory(_ds, _si + 4) = 3;                     //mov byte ptr [si+4], 3
    return;                                       //retn
loc_121D6:                                        //loc_121D6:
    memory(_ds, _si + 4) = 4;                     //mov byte ptr [si+4], 4
}

void sub_122C1()
{
    memory16(_ds, 0x9534) += 1;                   //inc word_1CF84
    _ax = memory16(_ds, 0x9534);                  //mov ax, word_1CF84
    if (_ax <= 0x0003)                            //jbe short loc_122D4
      goto loc_122D4;
    memory16(_ds, 0x9534) = 3;                    //mov word_1CF84, 3
    return;                                       //retn
loc_122D4:                                        //loc_122D4:
    if (_ax == 0x0003)                            //jz short sub_12311
    { sub_12311(); return; }
    if (_ax == 0x0002)                            //jz short sub_122F9
    { sub_122F9(); return; }
    if (_ax == 0x0001)                            //jz short sub_122E1
    { sub_122E1(); return; }
}

void sub_122E1()
{
    _ax = 0x43e6;                                 //mov ax, 43E6h
    _push(_ax);                                   //push ax
    _ax = 0x1b90;                                 //mov ax, 1B90h
    _push(_ax);                                   //push ax
    _ax = 0x10;                                   //mov ax, 10h
    _push(_ax);                                   //push ax
    _ax = 0x0f;                                   //mov ax, 0Fh
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
}

void sub_122F9()
{
    _ax = 0x43e6;                                 //mov ax, 43E6h
    _push(_ax);                                   //push ax
    _ax = 0x1b93;                                 //mov ax, 1B93h
    _push(_ax);                                   //push ax
    _ax = 0x10;                                   //mov ax, 10h
    _push(_ax);                                   //push ax
    _ax = 0x0f;                                   //mov ax, 0Fh
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
}

void sub_12311()
{
    _ax = 0x43e6;                                 //mov ax, 43E6h
    _push(_ax);                                   //push ax
    _ax = 0x1b96;                                 //mov ax, 1B96h
    _push(_ax);                                   //push ax
    _ax = 0x10;                                   //mov ax, 10h
    _push(_ax);                                   //push ax
    _ax = 0x0f;                                   //mov ax, 0Fh
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
}

void sub_12329()
{
    memory16(_ds, 0x9534) -= 1;                   //dec word_1CF84
    _ax = memory16(_ds, 0x9534);                  //mov ax, word_1CF84
    if (_ax == 0x0002)                            //jz short loc_12368
      goto loc_12368;
    if (_ax == 0x0001)                            //jz short loc_12354
      goto loc_12354;
    if (_ax == 0x0000)                            //jz short loc_12340
      goto loc_12340;
    return;                                       //retn
loc_12340:                                        //loc_12340:
    _ax = 0x1b90;                                 //mov ax, 1B90h
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    _ax = 0x0f;                                   //mov ax, 0Fh
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    sub_12D9A();                                  //call sub_12D9A
    return;                                       //retn
loc_12354:                                        //loc_12354:
    _ax = 0x1b93;                                 //mov ax, 1B93h
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    _ax = 0x0f;                                   //mov ax, 0Fh
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    sub_12D9A();                                  //call sub_12D9A
    return;                                       //retn
loc_12368:                                        //loc_12368:
    _ax = 0x1b96;                                 //mov ax, 1B96h
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    _ax = 0x0f;                                   //mov ax, 0Fh
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    sub_12D9A();                                  //call sub_12D9A
}

void sub_1237C()
{
    memory16(_ds, 0x9536) = 6;                    //mov word_1CF86, 6
    memory16(_ds, 0x9538) = 0;                    //mov word_1CF88, 0
    sub_123D4();                                  //call sub_123D4
    sub_123EC();                                  //call sub_123EC
    sub_12404();                                  //call sub_12404
    sub_1241C();                                  //call sub_1241C
    sub_12434();                                  //call sub_12434
    sub_1244C();                                  //call sub_1244C
}

void sub_12536()
{
    memory16(_ds, 0x953A) = _ax;                  //mov word_1CF8A, ax
    _push(_ax);                                   //push ax
    _ax = 0x1b88;                                 //mov ax, 1B88h
    _push(_ax);                                   //push ax
    sub_125E3();                                  //call sub_125E3
}

void sub_1257E()
{
    memory16(_ds, 0x953E) = _ax;                  //mov word_1CF8E, ax
    _push(_ax);                                   //push ax
    _ax = 0x1cc8;                                 //mov ax, 1CC8h
    _push(_ax);                                   //push ax
    sub_125E3();                                  //call sub_125E3
}

void sub_125C6()
{
    memory16(_ds, 0x9542) = _ax;                  //mov word_1CF92, ax
    _push(_ax);                                   //push ax
    _ax = 0x1e08;                                 //mov ax, 1E08h
    _push(_ax);                                   //push ax
    sub_125E3();                                  //call sub_125E3
}

void sub_12662()
{
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    _ax = 0x0001;                                 //mov ax, 1
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    sub_1269E();                                  //call sub_1269E
}

void sub_12676()
{
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    _ax = 0x0001;                                 //mov ax, 1
    _push(_ax);                                   //push ax
    _ax = 0x0005;                                 //mov ax, 5
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    sub_1269E();                                  //call sub_1269E
}

void sub_12809()
{
    _al = memory(_ds, 0x94DA);                    //mov al, byte_1CF2A
    memory(_ds, 0x94D3) = _al;                    //mov byte_1CF23, al
    _al = memory(_ds, 0x94DB);                    //mov al, byte_1CF2B
    memory(_ds, 0x94D4) = _al;                    //mov byte_1CF24, al
    _al = memory(_ds, 0x94DC);                    //mov al, byte_1CF2C
    memory(_ds, 0x94D5) = _al;                    //mov byte_1CF25, al
    _al = memory(_ds, 0x94DD);                    //mov al, byte_1CF2D
    memory(_ds, 0x94D6) = _al;                    //mov byte_1CF26, al
    _al = memory(_ds, 0x94DE);                    //mov al, byte_1CF2E
    memory(_ds, 0x94D7) = _al;                    //mov byte_1CF27, al
    _al = memory(_ds, 0x94DF);                    //mov al, byte_1CF2F
    memory(_ds, 0x94D8) = _al;                    //mov byte_1CF28, al
    _al = memory(_ds, 0x94E0);                    //mov al, byte_1CF30
    memory(_ds, 0x94D9) = _al;                    //mov byte_1CF29, al
    _si = 0x94d3;                                 //mov si, 94D3h
    _di = 0x94da;                                 //mov di, 94DAh
    _cx = 0x0007;                                 //mov cx, 7
loc_1283C:                                        //loc_1283C:
    _push(_cx);                                   //push cx
    _push(_si);                                   //push si
loc_1283E:                                        //loc_1283E:
    _al = memory(_ds, _si);                       //mov al, [si]
    if (_al != 0xff)                              //jnz short loc_12847
      goto loc_12847;
    _si += 1;                                     //inc si
    goto loc_1283E;                               //jmp short loc_1283E
loc_12847:                                        //loc_12847:
    if (_si == 0x94d9)                            //jz short loc_12865
      goto loc_12865;
    _bx = _si;                                    //mov bx, si
loc_1284F:                                        //loc_1284F:
    _bx += 1;                                     //inc bx
    _al = memory(_ds, _bx);                       //mov al, [bx]
    if (_al == 0xff)                              //jz short loc_1285F
      goto loc_1285F;
    sub_12872();                                  //call sub_12872
    if (_al == 0x00)                              //jz short loc_1285F
      goto loc_1285F;
    _si = _bx;                                    //mov si, bx
loc_1285F:                                        //loc_1285F:
    if (_bx != 0x94d9)                            //jnz short loc_1284F
      goto loc_1284F;
loc_12865:                                        //loc_12865:
    _al = memory(_ds, _si);                       //mov al, [si]
    memory(_ds, _si) = 0xff;                      //mov byte ptr [si], 0FFh
    memory(_ds, _di) = _al;                       //mov [di], al
    _di += 1;                                     //inc di
    _si = _pop();                                 //pop si
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_1283C
      goto loc_1283C;
}

void sub_12A64()
{
    _si = memory16(_ds, 0x9451);                  //mov si, word_1CEA1
    _bl = memory(_ds, 0x9450);                    //mov bl, byte_1CEA0
    _bh = 0x00;                                   //mov bh, 0
    _bx <<= 1;                                    //shl bx, 1
    _bx <<= 1;                                    //shl bx, 1
    _bx <<= 1;                                    //shl bx, 1
    _ax = memory16(_ds, _bx + 435);               //mov ax, [bx+1B3h]
    memory16(_ds, 0x944E) = _ax;                  //mov word_1CE9E, ax
    sub_1296F();                                  //call sub_1296F
}

void sub_12B28()
{
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    _ax = 0x0001;                                 //mov ax, 1
    _push(_ax);                                   //push ax
    _ax = 0x0005;                                 //mov ax, 5
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    sub_1269E();                                  //call sub_1269E
    _ax = _pop();                                 //pop ax
    if (_al == 0x00)                              //jz short loc_12B59
      goto loc_12B59;
    if (_al == 0x01)                              //jz short loc_12B76
      goto loc_12B76;
    if (_al == 0x02)                              //jz short loc_12B93
      goto loc_12B93;
    if (_al == 0x03)                              //jz short loc_12BB0
      goto loc_12BB0;
    if (_al == 0x04)                              //jz short loc_12BCD
      goto loc_12BCD;
    if (_al != 0x05)                              //jnz short locret_12B58
      goto locret_12B58;
    goto loc_12BEA;                               //jmp loc_12BEA
locret_12B58:                                     //locret_12B58:
    return;                                       //retn
loc_12B59:                                        //loc_12B59:
    memory(_ds, 0x952E) = 1;                      //mov byte_1CF7E, 1
    _ax = 0x2f78;                                 //mov ax, 2F78h
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
    return;                                       //retn
loc_12B76:                                        //loc_12B76:
    memory(_ds, 0x952F) = 1;                      //mov byte_1CF7F, 1
    _ax = 0x2f78;                                 //mov ax, 2F78h
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
    return;                                       //retn
loc_12B93:                                        //loc_12B93:
    memory(_ds, 0x9530) = 1;                      //mov byte_1CF80, 1
    _ax = 0x2f78;                                 //mov ax, 2F78h
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
    return;                                       //retn
loc_12BB0:                                        //loc_12BB0:
    memory(_ds, 0x9531) = 1;                      //mov byte_1CF81, 1
    _ax = 0x2f78;                                 //mov ax, 2F78h
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
    return;                                       //retn
loc_12BCD:                                        //loc_12BCD:
    memory(_ds, 0x9532) = 1;                      //mov byte_1CF82, 1
    _ax = 0x2f78;                                 //mov ax, 2F78h
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
    return;                                       //retn
loc_12BEA:                                        //loc_12BEA:
    memory(_ds, 0x9533) = 1;                      //mov byte_1CF83, 1
    _ax = 0x2f78;                                 //mov ax, 2F78h
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

void sub_12C07()
{
    _ax = 0x0a0b;                                 //mov ax, 0A0Bh
    _push(_ax);                                   //push ax
    _ax = 0x13;                                   //mov ax, 13h
    _push(_ax);                                   //push ax
    _ax = 0x30;                                   //mov ax, 30h
    _push(_ax);                                   //push ax
    _ax = 0x0005;                                 //mov ax, 5
    _push(_ax);                                   //push ax
    sub_12D9A();                                  //call sub_12D9A
    _ax = 0x0aac;                                 //mov ax, 0AACh
    _push(_ax);                                   //push ax
    _ax = 0x11;                                   //mov ax, 11h
    _push(_ax);                                   //push ax
    _ax = 0x28;                                   //mov ax, 28h
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    sub_12D9A();                                  //call sub_12D9A
    _ax = 0x5a5c;                                 //mov ax, 5A5Ch
    _push(_ax);                                   //push ax
    _ax = 0x0b4d;                                 //mov ax, 0B4Dh
    _push(_ax);                                   //push ax
    _ax = 0x78;                                   //mov ax, 78h
    _push(_ax);                                   //push ax
    _ax = 0x0f;                                   //mov ax, 0Fh
    _push(_ax);                                   //push ax
    _ax = 0x0004;                                 //mov ax, 4
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
}

void sub_12C9A()
{
    _push(_ax);                                   //push ax
    _ax = 0x0dcc;                                 //mov ax, 0DCCh
    _push(_ax);                                   //push ax
    _ax = 0x11;                                   //mov ax, 11h
    _push(_ax);                                   //push ax
    _ax = 0x0f;                                   //mov ax, 0Fh
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    sub_12D9A();                                  //call sub_12D9A
    _ax = _pop();                                 //pop ax
    if (_al != 0x06)                              //jnz short loc_12CBC
      goto loc_12CBC;
    _al = 0x00;                                   //mov al, 0
    sub_12CC7();                                  //call sub_12CC7
    _al = 0x06;                                   //mov al, 6
    sub_12CC7();                               //jmp short sub_12CC7
    return;
loc_12CBC:                                        //loc_12CBC:
    if (_al != 0x07)                              //jnz short sub_12CC7
    {sub_12CC7(); return;}
    _al = 0x01;                                   //mov al, 1
    sub_12CC7();                                  //call sub_12CC7
    _al = 0x07;                                   //mov al, 7
    _STOP_("sp-trace-fail");                      //sub_12C9A endp_failed
    _STOP_("continues");                          //sub_12CC7 proc near
}

void sub_12D9A()
{
    _push(_bp);                                   //push bp
    _bp = _sp;                                    //mov bp, sp
    _ax = 0xa000;                                 //mov ax, 0A000h
    _es = _ax;                                    //mov es, ax
    _di = stack16(_bp, 10);                       //mov di, [bp+arg_6]
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = stack16(_bp, 4);                        //mov ax, [bp+arg_0]
    _ah = _al;                                    //mov ah, al
    _al = 0x00;                                   //mov al, 0
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0f01;                                 //mov ax, 0F01h
    _out(_dx, _ax);                               //out dx, ax
    _flags.direction = false;                     //cld
    _bx = stack16(_bp, 6);                        //mov bx, [bp+arg_2]
loc_12DB8:                                        //loc_12DB8:
    _push(_di);                                   //push di
    _cx = stack16(_bp, 8);                        //mov cx, [bp+arg_4]
    _rep_stosb<MemAuto, DirAuto>();               //rep stosb
    _di = _pop();                                 //pop di
    _push(_di);                                   //push di
    _di += 0x2000;                                //add di, 2000h
    _cx = stack16(_bp, 8);                        //mov cx, [bp+arg_4]
    _rep_stosb<MemAuto, DirAuto>();               //rep stosb
    _di = _pop();                                 //pop di
    _di += 0x28;                                  //add di, 28h
    _bx -= 1;                                     //dec bx
    if (_bx != 0)                                 //jnz short loc_12DB8
      goto loc_12DB8;
    _ax = 0x0000;                                 //mov ax, 0
    _out(_dx, _ax);                               //out dx, ax
    _al += 1;                                     //inc al
    _out(_dx, _ax);                               //out dx, ax
    _bp = _pop();                                 //pop bp
    _stackReduce(8);                              //retn 8
    return;
}

void sub_12DDC()
{
    _bl = memory(_ds, 0x94E4);                    //mov bl, byte_1CF34
    _bx &= 0x0003;                                //and bx, 3
    _bx <<= 1;                                    //shl bx, 1
    _ax = memory16(_ds, _bx + 6698);              //mov ax, [bx+1A2Ah]
    memory16(_ds, 0x94E2) = _ax;                  //mov word_1CF32, ax
    memory(_ds, 0x94E4) += 1;                     //inc byte_1CF34
    memory(_ds, 0x9527) = 0xff;                   //mov byte_1CF77, 0FFh
}

void sub_12DF6()
{
    _al = 0x00;                                   //mov al, 0
    memory(_ds, 0x94E5) = _al;                    //mov byte_1CF35, al
    memory(_ds, 0x94E6) = _al;                    //mov byte_1CF36, al
    memory(_ds, 0x94E7) = _al;                    //mov byte_1CF37, al
}

void sub_13059()
{
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
    _al = memory(_ds, 0x951D);                    //mov al, byte_1CF6D
    if (_al != 0x40)                              //jnz short loc_1306A
      goto loc_1306A;
    memory16(_ds, 0x9540) += 6;                   //add word_1CF90, 6
    goto locret_13083;                            //jmp short locret_13083
loc_1306A:                                        //loc_1306A:
    if (_al != 0x80)                              //jnz short loc_13075
      goto loc_13075;
    memory16(_ds, 0x953C) += 4;                   //add word_1CF8C, 4
    goto locret_13083;                            //jmp short locret_13083
loc_13075:                                        //loc_13075:
    if (_al != 0xc0)                              //jnz short loc_13080
      goto loc_13080;
    memory16(_ds, 0x9544) += 8;                   //add word_1CF94, 8
    goto locret_13083;                            //jmp short locret_13083
loc_13080:                                        //loc_13080:
    sub_1268A();                                  //call sub_1268A
locret_13083:                                     //locret_13083:
    return;
}

void sub_13084()
{
    _flags.sign = (char)(_al - 0x05) < 0;         //sub al, 5
    _al -= 0x05;
    if (!_flags.sign)                              //jns short loc_1308D
      goto loc_1308D;
    _ax = 0x0000;                                 //mov ax, 0
    goto locret_1309C;                            //jmp short locret_1309C
loc_1308D:                                        //loc_1308D:
    if (_al <= 0x38)                              //jbe short loc_13093
      goto loc_13093;
    _al = 0x38;                                   //mov al, 38h
loc_13093:                                        //loc_13093:
    _al >>= 1;                                    //shr al, 1
    _ah = 0x00;                                   //mov ah, 0
    _ax = -_ax;                                   //neg ax
    _ax -= 0x0003;                                //sub ax, 3
locret_1309C:                                     //locret_1309C:
    return;
}

void sub_1309D() // draw tunnel grid
{
    _bx = memory16(_ds, 0x952A);                  //mov bx, word_1CF7A
    _bx += 0x0007;                                //add bx, 7
    _bx >>= 1;                                    //shr bx, 1
    _bx >>= 1;                                    //shr bx, 1
    _bx >>= 1;                                    //shr bx, 1
    _bx += 0x0002;                                //add bx, 2
    memory16(_ds, 0x9547) += _bx;                 //add word_1CF97, bx
    _ax = memory16(_ds, 0x950F);                  //mov ax, word_1CF5F
    _ax += _bx;                                   //add ax, bx
    if (_ax <= 0x02e8)                            //jbe short loc_130C4
      goto loc_130C4;
    _ax = 0x0000;                                 //mov ax, 0
    memory16(_ds, 0x953C) = 0xffff;               //mov word_1CF8C, 0FFFFh
loc_130C4:                                        //loc_130C4:
    memory16(_ds, 0x950F) = _ax;                  //mov word_1CF5F, ax
    _ax = memory16(_ds, 0x9547);                  //mov ax, word_1CF97
    _flags.sign = (short)(_ax - 0x0380) < 0;      //sub ax, 380h
    _ax -= 0x0380;
    if (!_flags.sign)                              //jns short loc_13124
      goto loc_13124;
    _ax = -_ax;                                   //neg ax
    if (_ax >= 0x0100)                            //jnb short loc_130ED
      goto loc_130ED;
    memory16(_ds, 0x9525) = _ax;                  //mov word_1CF75, ax
    _al = memory(_ds, 0x9524);                    //mov al, byte_1CF74
    if (_al != 0x00)                              //jnz short loc_130EB
      goto loc_130EB;
    _si = 0x1912;                                 //mov si, 1912h
    sub_10B58();                                  //call sub_10B58
    memory(_ds, 0x9524) = 1;                      //mov byte_1CF74, 1
loc_130EB:                                        //loc_130EB:
    goto loc_13122;                               //jmp short loc_13122
loc_130ED:                                        //loc_130ED:
    _ax = memory16(_ds, 0x9547);                  //mov ax, word_1CF97
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    if (_al == memory(_ds, 0x9527))               //jz short loc_13122
      goto loc_13122;
    memory(_ds, 0x9527) = _al;                    //mov byte_1CF77, al
    _bl = _al;                                    //mov bl, al
    _bh = 0x00;                                   //mov bh, 0
    _bx = _bx + memory16(_ds, 0x94E2);            //add bx, word_1CF32
    _al = memory(_ds, _bx);                       //mov al, [bx]
    if (_al == 0x00)                              //jz short loc_13122
      goto loc_13122;
    _si = 0x1ab2;                                 //mov si, 1AB2h
    memory(_ds, _si + 1) = _al;                   //mov [si+1], al
    _ax = memory16(_ds, 0x9547);                  //mov ax, word_1CF97
    memory16(_ds, _si + 19) = _ax;                //mov [si+13h], ax
    sub_10B58();                                  //call sub_10B58
loc_13122:                                        //loc_13122:
    goto locret_1312F;                            //jmp short locret_1312F
loc_13124:                                        //loc_13124:
    memory(_ds, 0x94FF) = 0;                      //mov byte_1CF4F, 0
    _ax = memory16(_ds, 0x950C);                  //mov ax, word_1CF5C
    memory16(_ds, 0x9528) = _ax;                  //mov word_1CF78, ax
locret_1312F:                                     //locret_1312F:
    return;
}

void sub_13170()
{
    _cx += 0x80;                                  //add cx, 80h
    memory16(_ds, _si + 5) = _cx;                 //mov [si+5], cx
}

void sub_1315E()
{
    _cx = -_cx;                                   //neg cx
    _cx += 0x6a;                                  //add cx, 6Ah
    memory16(_ds, _si + 7) = _cx;                 //mov [si+7], cx
}

void sub_13167()
{
    _push(_cx);                                   //push cx
    sub_1315E();                                  //call sub_1315E
    _cx = _pop();                                 //pop cx
    sub_13170();                                  //call sub_13170
}

void sub_13181();

void sub_13178()
{
    _push(_cx);                                   //push cx
    sub_13170();                                  //call sub_13170
    _cx = _pop();                                 //pop cx
    sub_13181();                                  //call sub_13181
}

void sub_13181()
{
    _cx += 0x6a;                                  //add cx, 6Ah
    memory16(_ds, _si + 7) = _cx;                 //mov [si+7], cx
}

void sub_13191();

void sub_13188()
{
    _push(_cx);                                   //push cx
    sub_13181();                                  //call sub_13181
    _cx = _pop();                                 //pop cx
    sub_13191();                                  //call sub_13191
}

void sub_13191()
{
    _cx = -_cx;                                   //neg cx
    _cx += 0x80;                                  //add cx, 80h
    memory16(_ds, _si + 5) = _cx;                 //mov [si+5], cx
}

void sub_1319B()
{
    _push(_cx);                                   //push cx
    sub_13191();                                  //call sub_13191
    _cx = _pop();                                 //pop cx
    sub_1315E();                                  //call sub_1315E
}

void sub_13130() // tunnel bubbles positions
{
    _bl = _al;                                    //mov bl, al
    _bh = 0x00;                                   //mov bh, 0
    _cl = memory(_ds, _bx + 6762);                //mov cl, [bx+1A6Ah]
    _ch = 0x00;                                   //mov ch, 0
    _al = memory(_ds, _si + 1);                   //mov al, [si+1]
    if (_al == 0x01)                              //jz short sub_1315E
    { sub_1315E(); return; }
    if (_al == 0x02)                              //jz short sub_13167
    { sub_13167(); return; }
    if (_al == 0x03)                              //jz short sub_13170
    { sub_13170(); return; }
    if (_al == 0x04)                              //jz short sub_13178
    { sub_13178(); return; }
    if (_al == 0x05)                              //jz short sub_13181
    { sub_13181(); return; }
    if (_al == 0x06)                              //jz short sub_13188
    { sub_13188(); return; }
    if (_al == 0x07)                              //jz short sub_13191
    { sub_13191(); return; }
    if (_al == 0x08)                              //jz short sub_1319B
    { sub_1319B(); return; }
}

void sub_13801() // put pixel
{
    //std::cout << "putpixel " << memory16(_ds, _bp + 8) << ", " << memory16(_ds, _bp + 10) << "\n";
    // PROBLEM: stack access through memory!!!!
    
    
    ///_ax = memory16(_ds, _bp + 8);                 //mov ax, [bp+8]
    _ax = stack16(_bp, 8);
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _di = _ax;                                    //mov di, ax
//    _ax = memory16(_ds, _bp + 10);                //mov ax, [bp+0Ah]
    _ax = stack16(_bp, 10);
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _di += _ax;                                   //add di, ax
    //_cx = memory16(_ds, _bp + 10);                //mov cx, [bp+0Ah]
    _cx = stack16(_bp, 10);

    _cx &= 0x0007;                                //and cx, 7
    _al = 0x80;                                   //mov al, 80h
    _al >>= _cl;                                  //shr al, cl
    memory(_es, _di) |= _al;                      //or es:[di], al
}

void sub_13914()
{
    _al -= 1;                                     //dec al
    _bl = _al;                                    //mov bl, al
    _bh = 0x00;                                   //mov bh, 0
    _bx <<= 1;                                    //shl bx, 1
    _bx = memory16(_ds, _bx + -29724);            //mov bx, [bx-741Ch]
    _al = memory(_ds, _bx + 1);                   //mov al, [bx+1]
    memory(_ds, 0x9557) = _al;                    //mov byte_1CFA7, al
    if (_bx != 0x8c2c)                            //jnz short loc_13941
      goto loc_13941;
    _ax = memory16(_ds, 0x9536);                  //mov ax, word_1CF86
    _ah = _al;                                    //mov ah, al
    _al = 0x00;                                   //mov al, 0
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax = -_ax;                                   //neg ax
    _ax += 0x1f40;                                //add ax, 1F40h
    memory16(_ds, 0x8C2E) = _ax;                  //mov word_1C67E, ax
    goto loc_13966;                               //jmp short loc_13966
loc_13941:                                        //loc_13941:
    if (_bx != 0x8c32)                            //jnz short loc_13966
      goto loc_13966;
    _al = memory(_ds, 0x1BA0);                    //mov al, byte_155F0
    _ax &= 0x7f;                                  //and ax, 7Fh
    if (_ax <= 0x3f)                              //jbe short loc_13957
      goto loc_13957;
    _ax -= 0x40;                                  //sub ax, 40h
    goto loc_1395C;                               //jmp short loc_1395C
loc_13957:                                        //loc_13957:
    _ax = -_ax;                                   //neg ax
    _ax += 0x3f;                                  //add ax, 3Fh
loc_1395C:                                        //loc_1395C:
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax += 0x0190;                                //add ax, 190h
    memory16(_ds, 0x8C34) = _ax;                  //mov word_1C684, ax
loc_13966:                                        //loc_13966:
    _ax = memory16(_ds, _bx + 2);                 //mov ax, [bx+2]
    memory16(_ds, 0x9558) = _ax;                  //mov word_1CFA8, ax
    _ax = memory16(_ds, _bx + 4);                 //mov ax, [bx+4]
    memory16(_ds, 0x955A) = _ax;                  //mov word_1CFAA, ax
    _bl = memory(_ds, _bx);                       //mov bl, [bx]
    memory(_ds, 0x9553) = _bl;                    //mov byte_1CFA3, bl
    if ((char)_bl <= (char)0x00)                  //jle short loc_1398F
      goto loc_1398F;
    _bl -= 1;                                     //dec bl
    _bh = 0x00;                                   //mov bh, 0
    _bx <<= 1;                                    //shl bx, 1
    _ax = memory16(_ds, _bx + -29604);            //mov ax, [bx-73A4h]
    memory16(_ds, 0x9555) = _ax;                  //mov word_1CFA5, ax
    memory(_ds, 0x9554) = 0;                      //mov byte_1CFA4, 0
loc_1398F:                                        //loc_1398F:
    _al = 0xb6;                                   //mov al, 0B6h
    _out(0x43, _al);                              //out 43h, al
    _ax = memory16(_ds, 0x9558);                  //mov ax, word_1CFA8
    _out(0x42, _al);                              //out 42h, al
    _al = _ah;                                    //mov al, ah
    _out(0x42, _al);                              //out 42h, al
    _in(_al, 0x61);                               //in al, 61h
    _al |= 0x03;                                  //or al, 3
    _out(0x61, _al);                              //out 61h, al
}

void sub_123D4()
{
    _ax = 0x43ee;                                 //mov ax, 43EEh
    _push(_ax);                                   //push ax
    _ax = 0x1b99;                                 //mov ax, 1B99h
    _push(_ax);                                   //push ax
    _ax = 0x10;                                   //mov ax, 10h
    _push(_ax);                                   //push ax
    _ax = 0x0f;                                   //mov ax, 0Fh
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
}

void sub_123EC()
{
    _ax = 0x43ee;                                 //mov ax, 43EEh
    _push(_ax);                                   //push ax
    _ax = 0x1b9b;                                 //mov ax, 1B9Bh
    _push(_ax);                                   //push ax
    _ax = 0x10;                                   //mov ax, 10h
    _push(_ax);                                   //push ax
    _ax = 0x0f;                                   //mov ax, 0Fh
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
}

void sub_12404()
{
    _ax = 0x43ee;                                 //mov ax, 43EEh
    _push(_ax);                                   //push ax
    _ax = 0x1b9d;                                 //mov ax, 1B9Dh
    _push(_ax);                                   //push ax
    _ax = 0x10;                                   //mov ax, 10h
    _push(_ax);                                   //push ax
    _ax = 0x0f;                                   //mov ax, 0Fh
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
}

void sub_1241C()
{
    _ax = 0x43ee;                                 //mov ax, 43EEh
    _push(_ax);                                   //push ax
    _ax = 0x1b9f;                                 //mov ax, 1B9Fh
    _push(_ax);                                   //push ax
    _ax = 0x10;                                   //mov ax, 10h
    _push(_ax);                                   //push ax
    _ax = 0x0f;                                   //mov ax, 0Fh
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
}

void sub_12434()
{
    _ax = 0x43ee;                                 //mov ax, 43EEh
    _push(_ax);                                   //push ax
    _ax = 0x1ba1;                                 //mov ax, 1BA1h
    _push(_ax);                                   //push ax
    _ax = 0x10;                                   //mov ax, 10h
    _push(_ax);                                   //push ax
    _ax = 0x0f;                                   //mov ax, 0Fh
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
}

void sub_1244C()
{
    _ax = 0x43ee;                                 //mov ax, 43EEh
    _push(_ax);                                   //push ax
    _ax = 0x1ba3;                                 //mov ax, 1BA3h
    _push(_ax);                                   //push ax
    _ax = 0x10;                                   //mov ax, 10h
    _push(_ax);                                   //push ax
    _ax = 0x0f;                                   //mov ax, 0Fh
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
}

void sub_11E7D()
{
    _push(_si);                                   //push si
    _di = 0x0ff7;                                 //mov di, 0FF7h
    _ax = _ax + memory16(_ds, _si + 5);           //add ax, [si+5]
    memory16(_ds, _di + 5) = _ax;                 //mov [di+5], ax
    _bx = _bx + memory16(_ds, _si + 7);           //add bx, [si+7]
    _bx &= 0x03ff;                                //and bx, 3FFh
    memory16(_ds, _di + 7) = _bx;                 //mov [di+7], bx
    _cl = _cl + memory(_ds, _si + 3);             //add cl, [si+3]
    memory(_ds, _di + 3) = _cl;                   //mov [di+3], cl
    _si = _di;                                    //mov si, di
    _bx = 0x1039;                                 //mov bx, 1039h
    sub_12121();                                  //call sub_12121
    sub_10B58();                                  //call sub_10B58
    if (_si == 0x0000)                            //jz short loc_11EB0
      goto loc_11EB0;
    _ax = _pop();                                 //pop ax
    _push(_ax);                                   //push ax
    if (_ax <= _si)                               //jbe short loc_11EB0
      goto loc_11EB0;
    sub_116D6();                                  //call sub_116D6
loc_11EB0:                                        //loc_11EB0:
    _si = _pop();                                 //pop si
    _al = memory(_ds, 0x9518);                    //mov al, byte_1CF68
    if (_al != 0x00)                              //jnz short loc_11EB9
      goto loc_11EB9;
    return;                                       //retn
loc_11EB9:                                        //loc_11EB9:
    _push(_si);                                   //push si
    _bl = memory(_ds, _si + 4);                   //mov bl, [si+4]
    _bh = 0x00;                                   //mov bh, 0
    _si = 0x13b0;                                 //mov si, 13B0h
    _al = memory(_ds, _bx + 5021);                //mov al, [bx+139Dh]
    memory(_ds, _si + 4) = _al;                   //mov [si+4], al
    _ax = memory16(_ds, 0xFFC);                   //mov ax, word_14A4C
    memory16(_ds, _si + 5) = _ax;                 //mov [si+5], ax
    _ax = memory16(_ds, 0xFFE);                   //mov ax, word_14A4E
    memory16(_ds, _si + 7) = _ax;                 //mov [si+7], ax
    _al = memory(_ds, 0xFFA);                     //mov al, byte_14A4A
    memory(_ds, _si + 3) = _al;                   //mov [si+3], al
    memory(_ds, _si + 1) = 2;                     //mov byte ptr [si+1], 2
    _bl = memory(_ds, _si + 4);                   //mov bl, [si+4]
    _bh = 0x00;                                   //mov bh, 0
    _al = memory(_ds, _bx + 5031);                //mov al, [bx+13A7h]
    memory(_ds, _si + 10) = _al;                  //mov [si+0Ah], al
    memory(_ds, _si + 9) = 4;                     //mov byte ptr [si+9], 4
    _bx <<= 1;                                    //shl bx, 1
    _ax = memory16(_ds, _bx + 5063);              //mov ax, [bx+13C7h]
    memory16(_ds, _si + 15) = _ax;                //mov [si+0Fh], ax
    sub_10B58();                                  //call sub_10B58
    if (_si == 0x0000)                            //jz short loc_11F09
      goto loc_11F09;
    _ax = _pop();                                 //pop ax
    _push(_ax);                                   //push ax
    if (_ax <= _si)                               //jbe short loc_11F09
      goto loc_11F09;
    sub_115FC();                                  //call sub_115FC
loc_11F09:                                        //loc_11F09:
    _si = _pop();                                 //pop si
}
