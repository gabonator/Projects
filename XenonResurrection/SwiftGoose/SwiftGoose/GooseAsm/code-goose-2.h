void sub_12959();
void sub_1296F();
void sub_129AE();
void sub_12907();
void sub_129AE();
void sub_11BB9();
void sub_108BA();
void sub_1094A();
void sub_109E9();
void sub_10A1B();
void sub_10B58();
void sub_1237C();
void sub_123D4();
void sub_123EC();
void sub_12404();
void sub_1241C();
void sub_12434();
void sub_1244C();
void sub_12CEA();



void sub_12959()
{
    memory16(_ds, 0x944E) = _ax;                  //mov word_1CE9E, ax
    _al = memory(_ds, _si);                       //mov al, [si]
    _ah = _al;                                    //mov ah, al
    _al <<= 1;                                    //shl al, 1
    _al += _ah;                                   //add al, ah
    _ah = 0x00;                                   //mov ah, 0
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax += 0x9455;                                //add ax, 9455h
    _si = _ax;                                    //mov si, ax
    //_STOP_("sp-trace-fail");                      //sub_12959 endp_failed
    //_STOP_("continues");                          //sub_1296F proc near
    sub_1296F();
}

void sub_1296F()
{
    _cx = 0x0c;                                   //mov cx, 0Ch
    _dx = 0x0000;                                 //mov dx, 0
loc_12975:                                        //loc_12975:
    _push(_cx);                                   //push cx
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    _push(_si);                                   //push si
    _push(_dx);                                   //push dx
    if (_al != 0x20)                              //jnz short loc_12982
      goto loc_12982;
    _ax = 0x6546;                                 //mov ax, 6546h
    goto loc_129A0;                               //jmp short loc_129A0
loc_12982:                                        //loc_12982:
    if (_al != 0x2e)                              //jnz short loc_1298B
      goto loc_1298B;
    _ax = 0x6f6c;                                 //mov ax, 6F6Ch
    goto loc_129A0;                               //jmp short loc_129A0
loc_1298B:                                        //loc_1298B:
    if (_al != 0x5f)                              //jnz short loc_12994
      goto loc_12994;
    _ax = 0x764c;                                 //mov ax, 764Ch
    goto loc_129A0;                               //jmp short loc_129A0
loc_12994:                                        //loc_12994:
    _al -= 0x41;                                  //sub al, 41h
    _ah = _al;                                    //mov ah, al
    _al <<= 1;                                    //shl al, 1
    _al += _ah;                                   //add al, ah
    _al <<= 1;                                    //shl al, 1
    _ah = 0x00;                                   //mov ah, 0
loc_129A0:                                        //loc_129A0:
    _push(_ax);                                   //push ax
    _push(_dx);                                   //push dx
    sub_129AE();                                  //call sub_129AE
    _dx = _pop();                                 //pop dx
    _dx += 0x0006;                                //add dx, 6
    _si = _pop();                                 //pop si
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_12975
      goto loc_12975;
}

void sub_129AE()
{
    _push(_bp);                                   //push bp
    _bp = _sp;                                    //mov bp, sp
    _ax = memory16(_ds, 0x94F0);                  //mov ax, word_1CF40
    _es = _ax;                                    //mov es, ax
    _di = memory16(_ds, 0x944E);                  //mov di, word_1CE9E
    _di = _di + stack16(_bp, 4);                  //add di, [bp+arg_0]
    _ax = memory16(_ds, 0x94EA);                  //mov ax, word_1CF3A
    _push(_ds);                                   //push ds
    _ds = _ax;                                    //mov ds, ax
    _si = stack16(_bp, 6);                        //mov si, [bp+arg_2]
    _cx = 0x0b;                                   //mov cx, 0Bh
loc_129C9:                                        //loc_129C9:
    _movsw<MemAuto, MemAuto, DirAuto>();          //movsw
    _movsw<MemAuto, MemAuto, DirAuto>();          //movsw
    _movsw<MemAuto, MemAuto, DirAuto>();          //movsw
    _di += 0x9a;                                  //add di, 9Ah
    _si += 0x9a;                                  //add si, 9Ah
    if (--_cx)                                    //loop loc_129C9
      goto loc_129C9;
    _ds = _pop();                                 //pop ds
    _bp = _pop();                                 //pop bp
    _stackReduce(4);                              //retn 4
    return;
}

void sub_12907()
{
    memory16(_ds, 0x944E) = _ax;                  //mov word_1CE9E, ax
    _al = memory(_ds, _si);                       //mov al, [si]
    _ah = _al;                                    //mov ah, al
    _al <<= 1;                                    //shl al, 1
    _al += _ah;                                   //add al, ah
    _ah = 0x00;                                   //mov ah, 0
    _ax <<= 1;                                    //shl ax, 1
    _ax += 0x94a9;                                //add ax, 94A9h
    _si = _ax;                                    //mov si, ax
    memory(_ds, 0x944D) = 1;                      //mov byte_1CE9D, 1
    _cx = 0x0006;                                 //mov cx, 6
    _dx = 0x0000;                                 //mov dx, 0
loc_12926:                                        //loc_12926:
    _push(_cx);                                   //push cx
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    if (_al == 0x00)                              //jz short loc_12931
      goto loc_12931;
    memory(_ds, 0x944D) = 0;                      //mov byte_1CE9D, 0
loc_12931:                                        //loc_12931:
    _cl = memory(_ds, 0x944D);                    //mov cl, byte_1CE9D
    if (_cl == 0x00)                              //jz short loc_1293F
      goto loc_1293F;
    _ax = 0x6f6c;                                 //mov ax, 6F6Ch
    goto loc_12949;                               //jmp short loc_12949
loc_1293F:                                        //loc_1293F:
    _bh = 0x00;                                   //mov bh, 0
    _bl = _al;                                    //mov bl, al
    _bx <<= 1;                                    //shl bx, 1
    _ax = memory16(_ds, _bx + 5503);              //mov ax, [bx+157Fh]
loc_12949:                                        //loc_12949:
    _push(_dx);                                   //push dx
    _push(_si);                                   //push si
    _push(_ax);                                   //push ax
    _push(_dx);                                   //push dx
    sub_129AE();                                  //call sub_129AE
    _si = _pop();                                 //pop si
    _dx = _pop();                                 //pop dx
    _dx += 0x0006;                                //add dx, 6
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_12926
      goto loc_12926;
}

void sub_133E5()
{
    _ax = memory16(_ds, 0x94F8);                  //mov ax, word_1CF48
    _es = _ax;                                    //mov es, ax
    _di = 0x0000;                                 //mov di, 0
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0805;                                 //mov ax, 805h
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0007;                                 //mov ax, 7
    _out(_dx, _ax);                               //out dx, ax
    _dl = 0xc4;                                   //mov dl, 0C4h
    _ax = 0x0802;                                 //mov ax, 802h
    _push(_ds);                                   //push ds
    _ds = _bx;                                    //mov ds, bx
loc_13400:                                        //loc_13400:
    _out(_dx, _ax);                               //out dx, ax
    _push(_ax);                                   //push ax
    _push(_di);                                   //push di
    _cx = 0x1f40;                                 //mov cx, 1F40h
loc_13406:                                        //loc_13406:
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    memoryVideoSet(_es, _di, _al);                      //and es:[di], al
    _di += 1;                                     //inc di
    if (--_cx)                                    //loop loc_13406
      goto loc_13406;
    _di = _pop();                                 //pop di
    _ax = _pop();                                 //pop ax
    _ah >>= 1;                                    //shr ah, 1
    if (_ah != 0)                                 //jnz short loc_13400
      goto loc_13400;
    _ds = _pop();                                 //pop ds
    _ax = 0x0f02;                                 //mov ax, 0F02h
    _out(_dx, _ax);                               //out dx, ax
    _dl = 0xce;                                   //mov dl, 0CEh
    _ax = 0x0005;                                 //mov ax, 5
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0f07;                                 //mov ax, 0F07h
    _out(_dx, _ax);                               //out dx, ax
}

void sub_13291() // clear scr
{
    _push(_bp);                                   //push bp
    _bp = _sp;                                    //mov bp, sp
    _ax = stack16(_bp, 4);                        //mov ax, [bp+arg_0]
    _es = _ax;                                    //mov es, ax
    _di = 0x0144;                                 //mov di, 144h
    _bx = stack16(_bp, 6);                        //mov bx, [bp+arg_2]
    _si = 0x0144;                                 //mov si, 144h
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0105;                                 //mov ax, 105h
    _out(_dx, _ax);                               //out dx, ax
    _push(_ds);                                   //push ds
    _ds = _bx;                                    //mov ds, bx
    _flags.direction = false;                     //cld
    _cx = 0xa0;                                   //mov cx, 0A0h
loc_132B0:                                        //loc_132B0:
    _push(_cx);                                   //push cx
    _cx = 0x20;                                   //mov cx, 20h //////
    _rep_movsb<MemAuto, MemAuto, DirAuto>();      //rep movsb
    _si += 0x0008;                                //add si, 8
    _di += 0x0008;                                //add di, 8
    _cx = _pop();                                 //pop cx
    if (--_cx)                                    //loop loc_132B0
      goto loc_132B0;
    _ds = _pop();                                 //pop ds
    _ax = 0x0005;                                 //mov ax, 5
    _out(_dx, _ax);                               //out dx, ax
    _bp = _pop();                                 //pop bp
    _stackReduce(4);                              //retn 4
    return;
}

void sub_10B7C()
{
    _si = 0x1b8a;                                 //mov si, 1B8Ah
loc_10B7F:                                        //loc_10B7F:
    _al = memory(_ds, _si);                       //mov al, [si]
    if (_al & 0x80)                               //jnz short locret_10B8D
      goto locret_10B8D;
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
    _si += 0x17;                                  //add si, 17h
    goto loc_10B7F;                               //jmp short loc_10B7F
locret_10B8D:                                     //locret_10B8D:
    return;
}

void sub_12121() // draw tunnel bubbles
{
    _cl = memory(_ds, _bx);                       //mov cl, [bx]
    _ch = 0x00;                                   //mov ch, 0
    _bx += 1;                                     //inc bx
    _al = memory(_ds, _si + 4);                   //mov al, [si+4]
    _ah = 0x00;                                   //mov ah, 0
    _di = _ax;                                    //mov di, ax
    _al = memory(_ds, _bx + _di);                 //mov al, [bx+di]
    memory(_ds, _si + 9) = _al;                   //mov [si+9], al
    _bx += _cx;                                   //add bx, cx
    _al = memory(_ds, _bx + _di);                 //mov al, [bx+di]
    memory(_ds, _si + 10) = _al;                  //mov [si+0Ah], al
    _bx += _cx;                                   //add bx, cx
    _al = memory(_ds, _bx + _di);                 //mov al, [bx+di]
    memory(_ds, _si + 11) = _al;                  //mov [si+0Bh], al
    _bx += _cx;                                   //add bx, cx
    _al = memory(_ds, _bx + _di);                 //mov al, [bx+di]
    memory(_ds, _si + 12) = _al;                  //mov [si+0Ch], al
    _bx += _cx;                                   //add bx, cx
    _di <<= 1;                                    //shl di, 1
    _di <<= 1;                                    //shl di, 1
    _ax = memory16(_ds, _bx + _di);               //mov ax, [bx+di]
    memory16(_ds, _si + 13) = _ax;                //mov [si+0Dh], ax
    _bx += 0x0002;                                //add bx, 2
    _ax = memory16(_ds, _bx + _di);               //mov ax, [bx+di]
    memory16(_ds, _si + 15) = _ax;                //mov [si+0Fh], ax
}

void sub_10B58()
{
    _ax = _dseg;                                  //mov ax, seg dseg
    _es = _ax;                                    //mov es, ax
    _di = 0x1b8a;                                 //mov di, 1B8Ah
loc_10B60:                                        //loc_10B60:
    _al = memory(_ds, _di);                       //mov al, [di]
    if (_al & 0x80)                               //jnz short loc_10B78
      goto loc_10B78;
    if (_al & 0x01)                               //jnz short loc_10B73
      goto loc_10B73;
    _push(_di);                                   //push di
    _cx = 0x17;                                   //mov cx, 17h
    _flags.direction = false;                     //cld
    _rep_movsb<MemAuto, MemAuto, DirAuto>();      //rep movsb
    _si = _pop();                                 //pop si
    return;                                       //retn
loc_10B73:                                        //loc_10B73:
    _di += 0x17;                                  //add di, 17h
    goto loc_10B60;                               //jmp short loc_10B60
loc_10B78:                                        //loc_10B78:
    _si = 0x0000;                                 //mov si, 0
}

void sub_11BB9()
{
    _bx = memory16(_ds, 0x952A);                  //mov bx, word_1CF7A
    _bx += 0x0f;                                  //add bx, 0Fh
    _bx >>= 1;                                    //shr bx, 1
    _bx >>= 1;                                    //shr bx, 1
    _bx >>= 1;                                    //shr bx, 1
    _ax = _bx;                                    //mov ax, bx
    _ax -= 1;                                     //dec ax
    _bx >>= 1;                                    //shr bx, 1
    _ax = _ax + memory16(_ds, 0x950F);            //add ax, word_1CF5F
    if (_ax <= 0x8b)                              //jbe short loc_11BDD
      goto loc_11BDD;
    _ax = 0x0000;                                 //mov ax, 0
    memory16(_ds, 0x953C) = 0xffff;               //mov word_1CF8C, 0FFFFh
loc_11BDD:                                        //loc_11BDD:
    memory16(_ds, 0x950F) = _ax;                  //mov word_1CF5F, ax
    _ax = memory16(_ds, 0x9528);                  //mov ax, word_1CF78
    _ax -= _bx;                                   //sub ax, bx
    _ax &= 0x03ff;                                //and ax, 3FFh
    memory16(_ds, 0x9528) = _ax;                  //mov word_1CF78, ax
    _ax = memory16(_ds, 0x9528);                  //mov ax, word_1CF78
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax -= 0x0003;                                //sub ax, 3
    _ax &= 0x3f;                                  //and ax, 3Fh
    if (_ax == memory16(_ds, 0x9507))             //jz short locret_11C09
      goto locret_11C09;
    memory16(_ds, 0x9507) = _ax;                  //mov word_1CF57, ax
    _push(_ax);                                   //push ax
    sub_108BA();                                  //call sub_108BA
locret_11C09:                                     //locret_11C09:
    return;
}


void sub_1094A()
{
    _dl = memory(_ds, _si + 19);                  //mov dl, [si+13h]
    _push(_si);                                   //push si
    _al = 0x3f;                                   //mov al, 3Fh
    _al = _al - memory(_ds, _si + 20);            //sub al, [si+14h]
    _al <<= 1;                                    //shl al, 1
    _al <<= 1;                                    //shl al, 1
    _ah = 0x00;                                   //mov ah, 0
    _si = _ax;                                    //mov si, ax
    _ax <<= 1;                                    //shl ax, 1
    _si += _ax;                                   //add si, ax
    _si += 0x8f29;                                //add si, 8F29h
    _cl = 0x00;                                   //mov cl, 0
    _flags.direction = false;                     //cld
loc_10966:                                        //loc_10966:
    if (_dl == 0x00)                              //jz short loc_10978
      goto loc_10978;
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    _bh = 0x00;                                   //mov bh, 0
    _bl = _al;                                    //mov bl, al
    _cl = _cl + memory(_ds, _bx + 1393);          //add cl, [bx+571h]
    _dl -= 1;                                     //dec dl
    goto loc_10966;                               //jmp short loc_10966
loc_10978:                                        //loc_10978:
    _si = _pop();                                 //pop si
    memory(_ds, _si + 3) = _cl;                   //mov [si+3], cl
    _al = memory(_ds, _si + 20);                  //mov al, [si+14h]
    _ah = 0x00;                                   //mov ah, 0
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    memory16(_ds, _si + 7) = _ax;                 //mov [si+7], ax
    _al = memory(_ds, _si + 19);                  //mov al, [si+13h]
    _ah = 0x00;                                   //mov ah, 0
    _ax <<= 1;                                    //shl ax, 1
    _cx = _ax;                                    //mov cx, ax
    _ax <<= 1;                                    //shl ax, 1
    _ax += _cx;                                   //add ax, cx
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax -= 0x0004;                                //sub ax, 4
    memory16(_ds, _si + 5) = _ax;                 //mov [si+5], ax
}

void sub_109E9()
{
    _push(_bp);                                   //push bp
    _bp = _sp;                                    //mov bp, sp
    _bx = stack16(_bp, 6);                        //mov bx, [bp+arg_2]
    _bx <<= 1;                                    //shl bx, 1
    _cx = memory16(_ds, _bx + 3307);              //mov cx, [bx+0CEBh]
    _bx = stack16(_bp, 4);                        //mov bx, [bp+arg_0]
    _bx <<= 1;                                    //shl bx, 1
    _al = memory(_ds, 0x9502);                    //mov al, byte_1CF52
    if (_al != 0x01)                              //jnz short loc_10A07
      goto loc_10A07;
    _bx += 0x80;                                  //add bx, 80h
    goto loc_10A0F;                               //jmp short loc_10A0F
loc_10A07:                                        //loc_10A07:
    if (_al != 0x02)                              //jnz short loc_10A0F
      goto loc_10A0F;
    _bx += 0x0100;                                //add bx, 100h
loc_10A0F:                                        //loc_10A0F:
    _cx = (~_cx);                                 //not cx
    _ax = memory16(_ds, _bx + -27991);            //mov ax, [bx-6D57h]
    _ax &= _cx;                                   //and ax, cx
    _bp = _pop();                                 //pop bp
    _stackReduce(4);                              //retn 4
    return;
}

void sub_10A1B()
{
    _al = memory(_ds, _si + 18);                  //mov al, [si+12h]
    _al <<= 1;                                    //shl al, 1
    _bl = _al;                                    //mov bl, al
    _bh = 0x00;                                   //mov bh, 0
    _di = memory16(_ds, _bx + 798);               //mov di, [bx+31Eh]
    _al = memory(_ds, _di);                       //mov al, [di]
    memory(_ds, _si) = _al;                       //mov [si], al
    _al = memory(_ds, _di + 9);                   //mov al, [di+9]
    memory(_ds, _si + 9) = _al;                   //mov [si+9], al
    _al = memory(_ds, _di + 10);                  //mov al, [di+0Ah]
    memory(_ds, _si + 10) = _al;                  //mov [si+0Ah], al
    _al = memory(_ds, _di + 11);                  //mov al, [di+0Bh]
    memory(_ds, _si + 11) = _al;                  //mov [si+0Bh], al
    _al = memory(_ds, _di + 12);                  //mov al, [di+0Ch]
    memory(_ds, _si + 12) = _al;                  //mov [si+0Ch], al
    _ax = memory16(_ds, _di + 15);                //mov ax, [di+0Fh]
    memory16(_ds, _si + 15) = _ax;                //mov [si+0Fh], ax
    _al = memory(_ds, _di + 18);                  //mov al, [di+12h]
    memory(_ds, _si + 18) = _al;                  //mov [si+12h], al
}

void sub_108BA()
{
    _push(_bp);                                   //push bp
    _bp = _sp;                                    //mov bp, sp
    _bx = stack16(_bp, 4);                        //mov bx, [bp+arg_0]
    _bx <<= 1;                                    //shl bx, 1
    _ax = memory16(_ds, _bx + -28119);            //mov ax, [bx-6DD7h]
    if (_ax == 0x0000)                            //jz short loc_10946
      goto loc_10946;
    _push(_ax);                                   //push ax
    _ah >>= 1;                                    //shr ah, 1
    _ah >>= 1;                                    //shr ah, 1
    _bl = _ah;                                    //mov bl, ah
    _bh = 0x00;                                   //mov bh, 0
    _bx <<= 1;                                    //shl bx, 1
    _si = memory16(_ds, _bx + 651);               //mov si, [bx+28Bh]
    if (_ah < 0x0f)                               //jb short loc_10902
      goto loc_10902;
    if (_ah > 0x14)                               //ja short loc_10902
      goto loc_10902;
    _ah -= 0x0f;                                  //sub ah, 0Fh
    memory(_ds, _si + 1) = _ah;                   //mov [si+1], ah
    _bl = _ah;                                    //mov bl, ah
    _bh = 0x00;                                   //mov bh, 0
    _al = memory(_ds, _bx + -27346);              //mov al, [bx-6AD2h]
    if (_al == 0x00)                              //jz short loc_108F9
      goto loc_108F9;
    _ax = _pop();                                 //pop ax
    goto loc_10946;                               //jmp short loc_10946
loc_108F9:                                        //loc_108F9:
    _bx <<= 1;                                    //shl bx, 1
    _ax = memory16(_ds, _bx + 814);               //mov ax, [bx+32Eh]
    memory16(_ds, _si + 15) = _ax;                //mov [si+0Fh], ax
loc_10902:                                        //loc_10902:
    memory(_ds, _si + 19) = 0x0a;                 //mov byte ptr [si+13h], 0Ah
    _ax = stack16(_bp, 4);                        //mov ax, [bp+arg_0]
    memory(_ds, _si + 20) = _al;                  //mov [si+14h], al
    _ax = _pop();                                 //pop ax
    _cx = 0x0a;                                   //mov cx, 0Ah
loc_10910:                                        //loc_10910:
    _flags.carry = _ax & 1;                       //shr ax, 1
    _ax >>= 1;
    if (!_flags.carry)                            //jnb short loc_10941
      goto loc_10941;
    _push(_ax);                                   //push ax
    _push(_cx);                                   //push cx
    sub_1094A();                                  //call sub_1094A
    _al = memory(_ds, _si + 19);                  //mov al, [si+13h]
    _ah = 0x00;                                   //mov ah, 0
    _push(_ax);                                   //push ax
    _ax = stack16(_bp, 4);                        //mov ax, [bp+arg_0]
    _push(_ax);                                   //push ax
    sub_109E9();                                  //call sub_109E9
    if (_ax == 0x0000)                            //jz short loc_10932
      goto loc_10932;
    _push(_si);                                   //push si
    sub_10B58();                                  //call sub_10B58
    _si = _pop();                                 //pop si
    goto loc_1093F;                               //jmp short loc_1093F
loc_10932:                                        //loc_10932:
    _push(_si);                                   //push si
    sub_10B58();                                  //call sub_10B58
    if (_si == 0x0000)                            //jz short loc_1093E
      goto loc_1093E;
    sub_10A1B();                                  //call sub_10A1B
loc_1093E:                                        //loc_1093E:
    _si = _pop();                                 //pop si
loc_1093F:                                        //loc_1093F:
    _cx = _pop();                                 //pop cx
    _ax = _pop();                                 //pop ax
loc_10941:                                        //loc_10941:
    memory(_ds, _si + 19) -= 1;                   //dec byte ptr [si+13h]
    if (--_cx)                                    //loop loc_10910
      goto loc_10910;
loc_10946:                                        //loc_10946:
    _bp = _pop();                                 //pop bp
    _stackReduce(2);                              //retn 2
    return;
}

void sub_11B57()
{
    _ax = memory16(_ds, 0x1B8F);                  //mov ax, word_155DF
    _push(_ax);                                   //push ax
    _ax = memory16(_ds, 0x9528);                  //mov ax, word_1CF78
    _ax += 0x70;                                  //add ax, 70h
    _ax &= 0x03ff;                                //and ax, 3FFh
    memory16(_ds, 0x1B91) = _ax;                  //mov word_155E1, ax
    _push(_ax);                                   //push ax
    sub_107FD();                                  //call sub_107FD
    memory(_ds, 0x1B8D) = _al;                    //mov byte_155DD, al
    memory(_ds, 0x1B9E) = _cl;                    //mov byte_155EE, cl
    memory(_ds, 0x1B8E) = _bl;                    //mov byte_155DE, bl
    _si = 0x1b8a;                                 //mov si, 1B8Ah
    _bx = 0x0d49;                                 //mov bx, 0D49h
    sub_12121();                                  //call sub_12121
}

void sub_107FD()
{
    _push(_bp);                                   //push bp
    _bp = _sp;                                    //mov bp, sp
    _sp -= 0x0008;                                //sub sp, 8
    _ax = stack16(_bp, 6);                        //mov ax, [bp+arg_2]
    _ax += 0x10;                                  //add ax, 10h
    _cl = 0x18;                                   //mov cl, 18h
    _div(_cl);                                    //div cl
    _push(_ax);                                   //push ax
    _ah = 0x00;                                   //mov ah, 0
    stack16(_bp, -2) = _ax;                       //mov [bp+var_2], ax
    _ax = _pop();                                 //pop ax
    _al = _ah;                                    //mov al, ah
    _ah = 0x00;                                   //mov ah, 0
    _cl = 0x03;                                   //mov cl, 3
    _div(_cl);                                    //div cl
    _ah = 0x00;                                   //mov ah, 0
    stack16(_bp, -4) = _ax;                       //mov [bp+var_4], ax
    _ax = stack16(_bp, 4);                        //mov ax, [bp+arg_0]
    _ax &= 0x03ff;                                //and ax, 3FFh
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax = -_ax;                                   //neg ax
    _ax += 0x3f;                                  //add ax, 3Fh
    stack16(_bp, -6) = _ax;                       //mov [bp+var_6], ax
    _ax = stack16(_bp, 4);                        //mov ax, [bp+arg_0]
    _ax &= 0x0f;                                  //and ax, 0Fh
    _ax >>= 1;                                    //shr ax, 1
    stack16(_bp, -8) = _ax;                       //mov [bp+var_8], ax
    _ax = stack16(_bp, -6);                       //mov ax, [bp+var_6]
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _bx = _ax;                                    //mov bx, ax
    _ax <<= 1;                                    //shl ax, 1
    _bx += _ax;                                   //add bx, ax
    _bx += 0x8f29;                                //add bx, 8F29h
    _si = _bx;                                    //mov si, bx
    _bx = _bx + stack16(_bp, -2);                 //add bx, [bp+var_2]
    _al = memory(_ds, _bx);                       //mov al, [bx]
    _ah = 0x00;                                   //mov ah, 0
    _push(_ax);                                   //push ax
    _ax <<= 1;                                    //shl ax, 1
    _bx = _ax;                                    //mov bx, ax
    _bx = memory16(_ds, _bx + 1603);              //mov bx, [bx+643h]
    _ax = stack16(_bp, -8);                       //mov ax, [bp+var_8]
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _bx += _ax;                                   //add bx, ax
    _bx = _bx + stack16(_bp, -4);                 //add bx, [bp+var_4]
    _cl = memory(_ds, _bx);                       //mov cl, [bx]
    _push(_cx);                                   //push cx
    _cl &= 0x1f;                                  //and cl, 1Fh
    if (!(_cl & 0x10))                            //jz short loc_10881
      goto loc_10881;
    _cl |= 0xe0;                                  //or cl, 0E0h
loc_10881:                                        //loc_10881:
    _dx = stack16(_bp, -2);                       //mov dx, [bp+var_2]
    _flags.direction = false;                     //cld
loc_10885:                                        //loc_10885:
    if (_dx == 0x0000)                            //jz short loc_10896
      goto loc_10896;
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    _bh = 0x00;                                   //mov bh, 0
    _bl = _al;                                    //mov bl, al
    _cl = _cl + memory(_ds, _bx + 1393);          //add cl, [bx+571h]
    _dx -= 1;                                     //dec dx
    goto loc_10885;                               //jmp short loc_10885
loc_10896:                                        //loc_10896:
    _al = _cl;                                    //mov al, cl
    _cbw();                                       //cbw
    _cx = _pop();                                 //pop cx
    _bx = _pop();                                 //pop bx
    if (_cl & 0x80)                               //jnz short loc_108A6
      goto loc_108A6;
    _bl = memory(_ds, _bx + 1435);                //mov bl, [bx+59Bh]
    goto loc_108AA;                               //jmp short loc_108AA
loc_108A6:                                        //loc_108A6:
    _bl = memory(_ds, _bx + 1477);                //mov bl, [bx+5C5h]
loc_108AA:                                        //loc_108AA:
    _bh = 0x00;                                   //mov bh, 0
    _cx = stack16(_bp, -6);                       //mov cx, [bp+var_6]
    _cx = -_cx;                                   //neg cx
    _cx += 0x3f;                                  //add cx, 3Fh
    _sp = _bp;                                    //mov sp, bp
    _bp = _pop();                                 //pop bp
    _stackReduce(4);                              //retn 4
    return;
}

void sub_10C24() // draw bitmap!
{
    WORD _cs = _seg000;
    _push(_bp);                                   //push bp
    _bp = _sp;                                    //mov bp, sp
    _ax = memory16(_ds, 0x9430);                  //mov ax, word_1CE80
    if (_ax != 0x0000)                            //jnz short loc_10C32
      goto loc_10C32;
    goto loc_10CBC;                               //jmp loc_10CBC
loc_10C32:                                        //loc_10C32:
    _ax = stack16(_bp, 8);                        //mov ax, [bp+arg_4]
    _ax = _ax - memory16(_ds, 0x9528);            //sub ax, word_1CF78
    _ax &= 0x03ff;                                //and ax, 3FFh
    if (!(_ax & 0x0200))                          //jz short loc_10C44
      goto loc_10C44;
    _ax |= 0xfc00;                                //or ax, 0FC00h
loc_10C44:                                        //loc_10C44:
    stack16(_bp, 8) = _ax;                        //mov [bp+arg_4], ax
    if ((short)_ax >= (short)0x0000)              //jge short loc_10C77
      goto loc_10C77;
    _flags.sign = (short)(stack16(_bp, 4) + _ax) < 0;//add [bp+arg_0], ax
    stack16(_bp, 4) += _ax;
    if (!_flags.sign)                              //jns short loc_10C54
      goto loc_10C54;
    goto loc_10D8F;                               //jmp loc_10D8F
loc_10C54:                                        //loc_10C54:
    if (stack16(_bp, 4) != 0)                     //jnz short loc_10C59
      goto loc_10C59;
    goto loc_10D8F;                               //jmp loc_10D8F
loc_10C59:                                        //loc_10C59:
    _ax = -_ax;                                   //neg ax
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _cx = _ax;                                    //mov cx, ax
    _ax <<= 1;                                    //shl ax, 1
    _ax <<= 1;                                    //shl ax, 1
    _cx += _ax;                                   //add cx, ax
    _cx <<= 1;                                    //shl cx, 1
    _cx <<= 1;                                    //shl cx, 1
    _si += _cx;                                   //add si, cx
    _ax = 0x0000;                                 //mov ax, 0
    stack16(_bp, 8) = _ax;                        //mov [bp+arg_4], ax
    goto loc_10C8F;                               //jmp short loc_10C8F
loc_10C77:                                        //loc_10C77:
    _ax = _ax + stack16(_bp, 4);                  //add ax, [bp+arg_0]
    _ax -= 0xa0;
    _flags.sign = (short)_ax < 0;      //sub ax, 0A0h
    if (_flags.sign)                              //js short loc_10C8F
      goto loc_10C8F;
    _ax = -_ax;                                   //neg ax
    _ax = _ax + stack16(_bp, 4);                  //add ax, [bp+arg_0]
    if ((short)_ax > (short)0x0000)               //jg short loc_10C8C
      goto loc_10C8C;
    goto loc_10D8F;                               //jmp loc_10D8F
loc_10C8C:                                        //loc_10C8C:
    /// height
    _ASSERT(_ax < 100);
    stack16(_bp, 4) = _ax;                        //mov [bp+arg_0], ax
loc_10C8F:                                        //loc_10C8F:
    _ax = 0x20;                                   //mov ax, 20h
    stack16(_bp, 10) += _ax;                      //add [bp+arg_6], ax
    _ax = 0x0008;                                 //mov ax, 8
    stack16(_bp, 8) += _ax;                       //add [bp+arg_4], ax
    _ax = stack16(_bp, 10);                       //mov ax, [bp+arg_6]
    if ((short)_ax >= (short)0x20)                //jge short loc_10CAB
      goto loc_10CAB;
    _ax = 0x20;                                   //mov ax, 20h
    stack16(_bp, 10) = _ax;                       //mov [bp+arg_6], ax
    goto loc_10CBC;                               //jmp short loc_10CBC
loc_10CAB:                                        //loc_10CAB:
    _ax = _ax + stack16(_bp, 6);                  //add ax, [bp+arg_2]
    if ((short)_ax <= (short)0x0120)              //jle short loc_10CBC
      goto loc_10CBC;
    _ax = 0x0120;                                 //mov ax, 120h
    _ax = _ax - stack16(_bp, 6);                  //sub ax, [bp+arg_2]
    stack16(_bp, 10) = _ax;                       //mov [bp+arg_6], ax
    //std::cout << "draw sprite " << std::dec << (int) _ax << ", "  << "\n";

loc_10CBC:                                        //loc_10CBC:

    _push(_ds);                                   //push ds
    _push(_bx);                                   //push bx
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0a05;                                 //mov ax, 0A05h
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0007;                                 //mov ax, 7
    _out(_dx, _ax);                               //out dx, ax
    _ax = stack16(_bp, 10);                       //mov ax, [bp+arg_6]
    _bx = stack16(_bp, 8);                        //mov bx, [bp+arg_4]
//    std::cout << "draw sprite xxx " << std::dec << (int) _cx << "\n";
    _push(_cx);                                   //push cx
    _bx <<= 1;                                    //shl bx, 1
    _bx <<= 1;                                    //shl bx, 1
    _bx <<= 1;                                    //shl bx, 1
    _cx = memory(_cs, 0xD93);                     //mov cx, cs:word_10D93
    if (_cx != 0x28)                              //jnz short loc_10CE4
      goto loc_10CE4;
    _di = _bx;                                    //mov di, bx
    goto loc_10CE7;                               //jmp short loc_10CE7
loc_10CE4:                                        //loc_10CE4:
    _di = 0x0000;                                 //mov di, 0
loc_10CE7:                                        //loc_10CE7:
    _bx <<= 1;                                    //shl bx, 1
    _bx <<= 1;                                    //shl bx, 1
    _di += _bx;                                   //add di, bx
    _cl = _al;                                    //mov cl, al
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _di += _ax;                                   //add di, ax
    _cl &= 0x07;                                  //and cl, 7
    _ax = 0x80;                                   //mov ax, 80h
    _ax >>= _cl;                                  //shr ax, cl
    _ah = _al;                                    //mov ah, al
    _bx = memory16(_ds, 0x942E);                  //mov bx, word_1CE7E
    _es = _bx;                                    //mov es, bx
    _cx = _pop();                                 //pop cx
    _cx = stack16(_bp, 6);                        //mov cx, [bp+arg_2]
    _cx >>= 1;                                    //shr cx, 1
    _al = 0x08;                                   //mov al, 8
    _ds = _pop();                                 //pop ds
    _bx = stack16(_bp, 4);                        //mov bx, [bp+arg_0]
loc_10D13:                                        //loc_10D13:
    _push(_ax);                                   //push ax
    _push(_bx);                                   //push bx
    _push(_cx);                                   //push cx
    _push(_di);                                   //push di
    _push(_si);                                   //push si
loc_10D18:                                        //loc_10D18:
    _bh = memory(_cs, 0xD96);                     //mov bh, cs:byte_10D96
loc_10D1D:                                        //loc_10D1D:
    _bl = memory(_ds, _si);                       //mov bl, [si]
    _si += 1;                                     //inc si
    if (_bh != _bl)                               //jnz short loc_10D3A
      goto loc_10D3A;
    _ah >>= 1;                                    //shr ah, 1
    if (_ah != 0)                                 //jnz short loc_10D2F
      goto loc_10D2F;
    _ah = 0x40;                                   //mov ah, 40h
    _di += 1;                                     //inc di
    if (--_cx)                                    //loop loc_10D1D
      goto loc_10D1D;
    goto loc_10D6D;                               //jmp short loc_10D6D
loc_10D2F:                                        //loc_10D2F:
    _ah >>= 1;                                    //shr ah, 1
    if (_ah != 0)                                 //jnz short loc_10D36
      goto loc_10D36;
    _ah = 0x80;                                   //mov ah, 80h
    _di += 1;                                     //inc di
loc_10D36:                                        //loc_10D36:
    if (--_cx)                                    //loop loc_10D1D
      goto loc_10D1D;
    goto loc_10D6D;                               //jmp short loc_10D6D
loc_10D3A:                                        //loc_10D3A:
    _bh = _bl;                                    //mov bh, bl
    _bl >>= 1;                                    //shr bl, 1
    _bl >>= 1;                                    //shr bl, 1
    _bl >>= 1;                                    //shr bl, 1
    _bl >>= 1;                                    //shr bl, 1
    if (_bl == memory(_cs, 0xD95))                //jz short loc_10D4F
      goto loc_10D4F;
    _out(_dx, _ax);                               //out dx, ax
///    memoryVideoSet(_es, _di, 0xff);
    memoryVideoSet(_es, _di, memoryVideoGet(_es, _di) & _bl);                      //and es:[di], bl
loc_10D4F:                                        //loc_10D4F:
    _ah >>= 1;                                    //shr ah, 1
    if (_ah != 0)                                 //jnz short loc_10D56
      goto loc_10D56;
    _ah = 0x80;                                   //mov ah, 80h
    _di += 1;                                     //inc di
loc_10D56:                                        //loc_10D56:
    _bh &= 0x0f;                                  //and bh, 0Fh
    if (_bh == memory(_cs, 0xD95))                //jz short loc_10D64
      goto loc_10D64;
    _out(_dx, _ax);                               //out dx, ax
    memoryVideoSet(_es, _di, memoryVideoGet(_es, _di) & _bh);                      //and es:[di], bh
loc_10D64:                                        //loc_10D64:
    _ah >>= 1;                                    //shr ah, 1
    if (_ah != 0)                                 //jnz short loc_10D6B
      goto loc_10D6B;
    _ah = 0x80;                                   //mov ah, 80h
    _di += 1;                                     //inc di
loc_10D6B:                                        //loc_10D6B:
    if (--_cx)                                    //loop loc_10D18
      goto loc_10D18;
loc_10D6D:                                        //loc_10D6D:
    _si = _pop();                                 //pop si
    _si += 0xa0;                                  //add si, 0A0h
    _di = _pop();                                 //pop di
    _di = _di + memory(_cs, 0xD93);               //add di, cs:word_10D93
    _di &= 0x7fff;                                //and di, 7FFFh
    _cx = _pop();                                 //pop cx
    _bx = _pop();                                 //pop bx
    _ax = _pop();                                 //pop ax
    _bx -= 1;                                     //dec bx
    if (_bx != 0)                                 //jnz short loc_10D13
      goto loc_10D13;
    _ds = _pop();                                 //pop ds
    _ax = 0xff08;                                 //mov ax, 0FF08h
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0005;                                 //mov ax, 5
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0f07;                                 //mov ax, 0F07h
    _out(_dx, _ax);                               //out dx, ax
loc_10D8F:                                        //loc_10D8F:
    _bp = _pop();                                 //pop bp
    _stackReduce(8);                              //retn 8
    return;
}

void sub_107AF() // draw map
{
    _al = memory(_ds, 0x8F22);                    //mov al, byte_1C972
    memory(_ds, 0x277) = _al;                     //mov byte_13CC7, al
    _bx = memory16(_ds, 0x8F25);                  //mov bx, word_1C975
    _al = memory(_ds, _bx);                       //mov al, [bx]
    _bx += 1;                                     //inc bx
    memory16(_ds, 0x8F25) = _bx;                  //mov word_1C975, bx
    _bh = 0x00;                                   //mov bh, 0
    _bl = _al;                                    //mov bl, al
    _al = memory(_ds, _bx + 1309);                //mov al, [bx+51Dh]
    memory(_ds, 0x27E) = _al;                     //mov byte_13CCE, al
    _al = memory(_ds, _bx + 1393);                //mov al, [bx+571h]
    memory(_ds, 0x8F22) += _al;                   //add byte_1C972, al
    _al = memory(_ds, _bx + 1351);                //mov al, [bx+547h]
    _cbw();                                       //cbw
    _ax = _ax + memory16(_ds, 0x8F23);            //add ax, word_1C973
    memory16(_ds, 0x27B) = _ax;                   //mov word_13CCB, ax
    if (_bx < 0x26)                               //jb short loc_107EC
      goto loc_107EC;
    memory16(_ds, 0x281) = 2;                     //mov word_13CD1, 2
    goto loc_107F2;                               //jmp short loc_107F2
loc_107EC:                                        //loc_107EC:
    memory16(_ds, 0x281) = 4;                     //mov word_13CD1, 4
loc_107F2:                                        //loc_107F2:
    _bx <<= 1;                                    //shl bx, 1
    _bx = memory16(_ds, _bx + 1519);              //mov bx, [bx+5EFh]
    memory16(_ds, 0x283) = _bx;                   //mov word_13CD3, bx
}

void sub_10BC5() // draw map
{
    WORD _cs = _seg000;
    _ax = 0xa800;                                 //mov ax, 0A800h
    memory16(_ds, 0x942E) = _ax;                  //mov word_1CE7E, ax
    memory(_cs, 0xD93) = 0x20;                    //mov cs:word_10D93, 20h
    memory16(_ds, 0x9430) = 0;                    //mov word_1CE80, 0
    sub_10BDC();                                  //call sub_10BDC
}

void sub_10F9D()
{
    _ax = memory16(_ds, 0x1B8F);                  //mov ax, word_155DF
    memory16(_ds, 0x9433) = _ax;                  //mov word_1CE83, ax
    memory16(_ds, 0x9435) = _ax;                  //mov word_1CE85, ax
    memory16(_ds, 0x9437) = _ax;                  //mov word_1CE87, ax
    memory16(_ds, 0x9439) = _ax;                  //mov word_1CE89, ax
    _ax = memory16(_ds, 0x1B91);                  //mov ax, word_155E1
    memory16(_ds, 0x943B) = _ax;                  //mov word_1CE8B, ax
    memory16(_ds, 0x943D) = _ax;                  //mov word_1CE8D, ax
    memory16(_ds, 0x943F) = _ax;                  //mov word_1CE8F, ax
    memory16(_ds, 0x9441) = _ax;                  //mov word_1CE91, ax
    _al = memory(_ds, 0x1B8E);                    //mov al, byte_155DE
    memory(_ds, 0x9443) = _al;                    //mov byte_1CE93, al
    memory(_ds, 0x9444) = _al;                    //mov byte_1CE94, al
    memory(_ds, 0x9445) = _al;                    //mov byte_1CE95, al
    memory(_ds, 0x9446) = _al;                    //mov byte_1CE96, al
    _al = memory(_ds, 0x1B8D);                    //mov al, byte_155DD
    memory(_ds, 0x9447) = _al;                    //mov byte_1CE97, al
    memory(_ds, 0x9448) = _al;                    //mov byte_1CE98, al
    memory(_ds, 0x9449) = _al;                    //mov byte_1CE99, al
    memory(_ds, 0x944A) = _al;                    //mov byte_1CE9A, al
}

void sub_1250B()
{
    memory16(_ds, 0x953A) = 0x2c;                 //mov word_1CF8A, 2Ch
    memory16(_ds, 0x953C) = 0;                    //mov word_1CF8C, 0
    _ax = 0x48f6;                                 //mov ax, 48F6h
    _push(_ax);                                   //push ax
    _ax = 0x1b88;                                 //mov ax, 1B88h
    _push(_ax);                                   //push ax
    _ax = 0x2c;                                   //mov ax, 2Ch
    _push(_ax);                                   //push ax
    _ax = 0x0007;                                 //mov ax, 7
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
}

void sub_12553()
{
    memory16(_ds, 0x953E) = 0x30;                 //mov word_1CF8E, 30h
    memory16(_ds, 0x9540) = 0;                    //mov word_1CF90, 0
    _ax = 0x2ce6;                                 //mov ax, 2CE6h
    _push(_ax);                                   //push ax
    _ax = 0x1cc8;                                 //mov ax, 1CC8h
    _push(_ax);                                   //push ax
    _ax = 0x30;                                   //mov ax, 30h
    _push(_ax);                                   //push ax
    _ax = 0x0007;                                 //mov ax, 7
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
}

void sub_1259B()
{
    memory16(_ds, 0x9542) = 0x38;                 //mov word_1CF92, 38h
    memory16(_ds, 0x9544) = 0;                    //mov word_1CF94, 0
    _ax = 0x4496;                                 //mov ax, 4496h
    _push(_ax);                                   //push ax
    _ax = 0x1e08;                                 //mov ax, 1E08h
    _push(_ax);                                   //push ax
    _ax = 0x38;                                   //mov ax, 38h
    _push(_ax);                                   //push ax
    _ax = 0x0007;                                 //mov ax, 7
    _push(_ax);                                   //push ax
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
}

void sub_11B80()
{
    _bx = memory16(_ds, 0x952A);                  //mov bx, word_1CF7A
    _ax = memory16(_ds, 0x953A);                  //mov ax, word_1CF8A
    if ((short)_ax > (short)0x0000)               //jg short loc_11B91
      goto loc_11B91;
    _ax = 0x0008;                                 //mov ax, 8
    goto loc_11B94;                               //jmp short loc_11B94
loc_11B91:                                        //loc_11B91:
    _ax = memory16(_ds, 0x954C);                  //mov ax, word_1CF9C
loc_11B94:                                        //loc_11B94:
    if (!(_al & 0x04))                            //jz short loc_11BA3
      goto loc_11BA3;
    _bx += 1;                                     //inc bx
    if ((short)_bx <= (short)0x40)                //jle short loc_11BA1
      goto loc_11BA1;
    _bx = 0x40;                                   //mov bx, 40h
loc_11BA1:                                        //loc_11BA1:
    goto loc_11BB4;                               //jmp short loc_11BB4
loc_11BA3:                                        //loc_11BA3:
    if (!(_al & 0x08))                            //jz short loc_11BB4
      goto loc_11BB4;
    _bx -= 0x0002;                                //sub bx, 2
    if ((short)_bx >= (short)memory16(_ds, 0x94FC))//jge short loc_11BB4
      goto loc_11BB4;
    _bx = memory16(_ds, 0x94FC);                  //mov bx, word_1CF4C
loc_11BB4:                                        //loc_11BB4:
    memory16(_ds, 0x952A) = _bx;                  //mov word_1CF7A, bx
}

void sub_11C78()
{
    _ax = memory16(_ds, 0x9437);                  //mov ax, word_1CE87
    memory16(_ds, 0x9439) = _ax;                  //mov word_1CE89, ax
    _ax = memory16(_ds, 0x9435);                  //mov ax, word_1CE85
    memory16(_ds, 0x9437) = _ax;                  //mov word_1CE87, ax
    _ax = memory16(_ds, 0x9433);                  //mov ax, word_1CE83
    memory16(_ds, 0x9435) = _ax;                  //mov word_1CE85, ax
    _ax = memory16(_ds, 0x1B8F);                  //mov ax, word_155DF
    memory16(_ds, 0x9433) = _ax;                  //mov word_1CE83, ax
    _ax = memory16(_ds, 0x943F);                  //mov ax, word_1CE8F
    memory16(_ds, 0x9441) = _ax;                  //mov word_1CE91, ax
    _ax = memory16(_ds, 0x943D);                  //mov ax, word_1CE8D
    memory16(_ds, 0x943F) = _ax;                  //mov word_1CE8F, ax
    _ax = memory16(_ds, 0x943B);                  //mov ax, word_1CE8B
    memory16(_ds, 0x943D) = _ax;                  //mov word_1CE8D, ax
    _ax = memory16(_ds, 0x1B91);                  //mov ax, word_155E1
    memory16(_ds, 0x943B) = _ax;                  //mov word_1CE8B, ax
    _al = memory(_ds, 0x9445);                    //mov al, byte_1CE95
    memory(_ds, 0x9446) = _al;                    //mov byte_1CE96, al
    _al = memory(_ds, 0x9444);                    //mov al, byte_1CE94
    memory(_ds, 0x9445) = _al;                    //mov byte_1CE95, al
    _al = memory(_ds, 0x9443);                    //mov al, byte_1CE93
    memory(_ds, 0x9444) = _al;                    //mov byte_1CE94, al
    _al = memory(_ds, 0x1B8E);                    //mov al, byte_155DE
    memory(_ds, 0x9443) = _al;                    //mov byte_1CE93, al
    _al = memory(_ds, 0x9449);                    //mov al, byte_1CE99
    memory(_ds, 0x944A) = _al;                    //mov byte_1CE9A, al
    _al = memory(_ds, 0x9448);                    //mov al, byte_1CE98
    memory(_ds, 0x9449) = _al;                    //mov byte_1CE99, al
    _al = memory(_ds, 0x9447);                    //mov al, byte_1CE97
    memory(_ds, 0x9448) = _al;                    //mov byte_1CE98, al
    _al = memory(_ds, 0x1B8D);                    //mov al, byte_155DD
    memory(_ds, 0x9447) = _al;                    //mov byte_1CE97, al
}

void sub_10A51()
{
    _bl = memory(_ds, 0x1B9E);                    //mov bl, byte_155EE
    _bh = 0x00;                                   //mov bh, 0
    _bx <<= 1;                                    //shl bx, 1
    _si = _bx;                                    //mov si, bx
    _al = memory(_ds, 0x9502);                    //mov al, byte_1CF52
    if (_al != 0x01)                              //jnz short loc_10A68
      goto loc_10A68;
    _si += 0x80;                                  //add si, 80h
    goto loc_10A70;                               //jmp short loc_10A70
loc_10A68:                                        //loc_10A68:
    if (_al != 0x02)                              //jnz short loc_10A70
      goto loc_10A70;
    _si += 0x0100;                                //add si, 100h
loc_10A70:                                        //loc_10A70:
    _ax = memory16(_ds, _si - 27991);             //mov ax, [si-6D57h]
    _ax = _ax & memory16(_ds, _bx + -28119);      //and ax, [bx-6DD7h]
    if (_ax == 0x0000)                            //jz short loc_10AD1
      goto loc_10AD1;
    _bl = _ah;                                    //mov bl, ah
    _bl >>= 1;                                    //shr bl, 1
    _bl >>= 1;                                    //shr bl, 1
    _bh = 0x00;                                   //mov bh, 0
    _cl = memory(_ds, _bx + 693);                 //mov cl, [bx+2B5h]
    if (_cl == 0x00)                              //jz short loc_10AD1
      goto loc_10AD1;
    memory(_ds, 0x9429) = _cl;                    //mov byte_1CE79, cl
    memory16(_ds, 0x942C) = 0x0a;                 //mov word_1CE7C, 0Ah
    _bx <<= 1;                                    //shl bx, 1
    _dx = memory16(_ds, _bx + 714);               //mov dx, [bx+2CAh]
    _bx = memory16(_ds, _bx + 756);               //mov bx, [bx+2F4h]
    _cx = 0x0a;                                   //mov cx, 0Ah
loc_10AA5:                                        //loc_10AA5:
    _flags.carry = _ax & 1;                       //shr ax, 1
    _ax >>= 1;
    if (!_flags.carry)                            //jnb short loc_10AC8
      goto loc_10AC8;
    _push(_bx);                                   //push bx
    _bx -= _dx;                                   //sub bx, dx
    if ((short)_bx > (short)memory16(_ds, 0x1B8F))//jg short loc_10AC7
      goto loc_10AC7;
    _bx += _dx;                                   //add bx, dx
    _bx += _dx;                                   //add bx, dx
    if ((short)_bx < (short)memory16(_ds, 0x1B8F))//jl short loc_10AC7
      goto loc_10AC7;
    _ax = _pop();                                 //pop ax
    _al = memory(_ds, 0x9429);                    //mov al, byte_1CE79
    _ah = 0x00;                                   //mov ah, 0
    _bx = memory16(_ds, 0x942C);                  //mov bx, word_1CE7C
    return;                                       //retn
loc_10AC7:                                        //loc_10AC7:
    _bx = _pop();                                 //pop bx
loc_10AC8:                                        //loc_10AC8:
    _bx -= 0x18;                                  //sub bx, 18h
    memory16(_ds, 0x942C) -= 1;                   //dec word_1CE7C
    if (--_cx)                                    //loop loc_10AA5
      goto loc_10AA5;
loc_10AD1:                                        //loc_10AD1:
    _ax = 0x0000;                                 //mov ax, 0
}

void sub_11C33()
{
    _al = memory(_ds, 0x1B9C);                    //mov al, byte_155EC
    if (_al != 0x11)                              //jnz short loc_11C3B
      goto loc_11C3B;
    return;                                       //retn
loc_11C3B:                                        //loc_11C3B:
    _al = 0x0c;                                   //mov al, 0Ch
    sub_13840();                                  //call sub_13840
    _si = 0x1b8a;                                 //mov si, 1B8Ah
    sub_120F0();                                  //call sub_120F0
    memory(_ds, 0x1B9C) = 0x11;                   //mov byte_155EC, 11h
    memory(_ds, 0x1B8C) = 0;                      //mov byte_155DC, 0
    memory(_ds, 0x9514) = 0;                      //mov byte_1CF64, 0
}

void sub_120F0()
{
    _push(_si);                                   //push si
    _ax = memory16(_ds, _si + 5);                 //mov ax, [si+5]
    memory16(_ds, 0x12A3) = _ax;                  //mov word_14CF3, ax
    _ax = memory16(_ds, _si + 7);                 //mov ax, [si+7]
    memory16(_ds, 0x12A5) = _ax;                  //mov word_14CF5, ax
    _al = memory(_ds, _si + 3);                   //mov al, [si+3]
    memory(_ds, 0x12A1) = _al;                    //mov byte_14CF1, al
    _al = memory(_ds, _si);                       //mov al, [si]
    if (!(_al & 0x10))                            //jz short loc_12119
      goto loc_12119;
    memory16(_ds, 0x12A3) -= 0x0c;                //sub word_14CF3, 0Ch
    memory16(_ds, 0x12A5) -= 8;                   //sub word_14CF5, 8
    memory16(_ds, 0x12A5) &= 1023;                //and word_14CF5, 3FFh
loc_12119:                                        //loc_12119:
    _si = 0x129e;                                 //mov si, 129Eh
    sub_10B58();                                  //call sub_10B58
    _si = _pop();                                 //pop si
}

void sub_110A0()
{
    _al = memory(_ds, _si + 10);                  //mov al, [si+0Ah]
    _al = _al - memory(_ds, _si + 3);             //sub al, [si+3]
    _al = _al - memory(_ds, _si + 12);            //sub al, [si+0Ch]
    _cbw();                                       //cbw
    _ax = _ax + memory16(_ds, _si + 7);           //add ax, [si+7]
    _ax &= 0x03ff;                                //and ax, 3FFh
    _bx = memory16(_ds, 0x9528);                  //mov bx, word_1CF78
    if (_ax >= _bx)                               //jnb short loc_110BB
      goto loc_110BB;
    _ax += 0x0400;                                //add ax, 400h
loc_110BB:                                        //loc_110BB:
    _ax -= _bx;                                   //sub ax, bx
    if (_ax <= 0x0200)                            //jbe short locret_110C5
      goto locret_110C5;
    memory(_ds, _si) = 0;                         //mov byte ptr [si], 0
locret_110C5:                                     //locret_110C5:
    return;
}
