void sub_15C8B();
void sub_10DA3();
void sub_1011C();
void sub_1019A();
void sub_10230();
void sub_102A8();
void sub_104C9();
void sub_102D4();
void sub_10174();
void sub_10373();
void sub_1034C();
void sub_103DD();
void sub_103FD();
void sub_10423();

// imports
void nullsub_1();
void sub_2138B() {_ASSERT(0);}
void sub_22CD9() {_ASSERT(0);}

void sub_15C8B()  // load all files: x2spr.dat, x2weaps.dat, shop.dat, gr.dat
{
    _dx = 0x41c8;                                 //mov dx, 41C8h
    _ax = 0x449b;                                 //mov ax, 449Bh
    _es = _ax;                                    //mov es, ax
    _di = _di ^ _di;                              //xor di, di
    sub_1011C();                                  //call sub_1011C
    _dx = 0x41d2;                                 //mov dx, 41D2h
    _ax = 0x449b;                                 //mov ax, 449Bh
    _es = _ax;                                    //mov es, ax
    _di = 0x6be6;                                 //mov di, 6BE6h
    sub_1011C();                                  //call sub_1011C
    _dx = 0x41de;                                 //mov dx, 41DEh
    _ax = 0x449b;                                 //mov ax, 449Bh
    _es = _ax;                                    //mov es, ax
    _di = 0xabbc;                                 //mov di, 0ABBCh
    sub_1011C();                                  //call sub_1011C
    _dx = 0x41e7;                                 //mov dx, 41E7h
    _ax = 0x3824;                                 //mov ax, 3824h
    _es = _ax;                                    //mov es, ax
    _di = _di ^ _di;                              //xor di, di
    sub_1011C();                                  //call sub_1011C
    sub_10DA3();                                  //call sub_10DA3
}

void sub_10DA3()  // Fix bitmap?
{
    _bp = memory16(_ds, 0x3044);                  //mov bp, word_2B574
    _bp <<= 1;                                    //shl bp, 1
    _bp <<= 1;                                    //shl bp, 1
    switch (_bp)                                  //call cs:off_10DB1[bp]
    {
      case 0: break;
      case 4: sub_22CD9(); break;
      case 8: sub_2138B(); break;
      case 12: break;
      case 16: sub_2138B(); break;
      default:
        _ASSERT(0);
    }
}

void sub_1011C()  // Opens and reads whole file
{
    _ax = 0x3d00;                                 //mov ax, 3D00h
    _interrupt(0x21);                             //int 21h
    if (!_flags.carry)                            //jnb short loc_10126
      goto loc_10126;
    _STOP_("exit program");                       //jmp loc_15E04
loc_10126:                                        //loc_10126:
    _push(_ds);                                   //push ds
    _bx = 0x2565;                                 //mov bx, 2565h
    _ds = _bx;                                    //mov ds, bx
    memory16(_ds, 0x236C) = _di;                  //mov word_279BC, di
    memory16(_ds, 0x236E) = _es;                  //mov word_279BE, es
    _es = _bx;                                    //mov es, bx
    memory16(_ds, 0x2370) = _ax;                  //mov word_279C0, ax
    _ah = 0x3f;                                   //mov ah, 3Fh
    _bx = memory16(_ds, 0x2370);                  //mov bx, word_279C0
    _cx = 0x0200;                                 //mov cx, 200h
    _dx = 0x216c;                                 //mov dx, 216Ch
    _interrupt(0x21);                             //int 21h
    if (!_flags.carry)                            //jnb short loc_1014C
      goto loc_1014C;
    _STOP_("exit program");                       //jmp loc_15E04
loc_1014C:                                        //loc_1014C:
    _ax = memory16(_ds, 0x2177);                  //mov ax, word_277C7
    memory16(_ds, 0x0) = _ax;                     //mov word_25650, ax
    _ax = memory16(_ds, 0x2179);                  //mov ax, word_277C9
    memory16(_ds, 0x2) = _ax;                     //mov word_25652, ax
    _al = memory(_ds, 0x216C);                    //mov al, byte_277BC
    _ah = _ah ^ _ah;                              //xor ah, ah
    _ax += 0x216e;                                //add ax, 216Eh
    memory16(_ds, 0x216A) = _ax;                  //mov word_277BA, ax
    sub_1019A();                                  //call sub_1019A
    _ah = 0x3e;                                   //mov ah, 3Eh
    _bx = memory16(_ds, 0x2370);                  //mov bx, word_279C0
    _interrupt(0x21);                             //int 21h
    _ax = _pop();                                 //pop ax
    _ds = _ax;                                    //mov ds, ax
    _es = _ax;                                    //mov es, ax
}

void sub_1019A()
{
    _push(_si);                                   //push si
    _push(_di);                                   //push di
    _push(_bp);                                   //push bp
    _ax = memory16(_ds, 0x0);                     //mov ax, word_28530
    _ax = _ax | memory16(_ds, 0x2);               //or ax, word_28532
    if (_ax != 0)                                 //jnz short loc_101A9
      goto loc_101A9;
    goto loc_1022C;                               //jmp loc_1022C
loc_101A9:                                        //loc_101A9:
    sub_10230();                                  //call sub_10230
    sub_102A8();                                  //call sub_102A8
    _di = 0x0fc4;                                 //mov di, 0FC4h
loc_101B2:                                        //loc_101B2:
    _push(_di);                                   //push di
    sub_102D4();                                  //call sub_102D4
    _di = _ax;                                    //mov di, ax
    if ((short)_ax >= (short)0x0100)              //jge short loc_101E0
      goto loc_101E0;
    _di = _pop();                                 //pop di
    _push(_es);                                   //push es
    _push(_di);                                   //push di
    _les(_di, 0x236C);                            //les di, dword_2A89C
    _stosb<MemAuto, DirAuto>();                   //stosb
    memory16(_ds, 0x236C) = _di;                  //mov word ptr dword_2A89C, di
    _di = _pop();                                 //pop di
    _es = _pop();                                 //pop es
    memory(_ds, _di + 4399) = _al;                //mov [di+112Fh], al
    _di += 1;                                     //inc di
    _di &= 0x0fff;                                //and di, 0FFFh
    _flags.carry = memory16(_ds, 0x0) < 1;        //sub word_28530, 1
    memory16(_ds, 0x0) -= 1;
    memory16(_ds, 0x2) -= _flags.carry;           //sbb word_28532, 0
    goto loc_1021D;                               //jmp short loc_1021D
loc_101E0:                                        //loc_101E0:
    sub_1034C();                                  //call sub_1034C
    _cx = _di;                                    //mov cx, di
    _di = _pop();                                 //pop di
    _si = _di;                                    //mov si, di
    _si -= _ax;                                   //sub si, ax
    _si -= 1;                                     //dec si
    _si &= 0x0fff;                                //and si, 0FFFh
    _cx -= 0xfd;                                  //sub cx, 0FDh
    _flags.carry = memory16(_ds, 0x0) < _cx;      //sub word_28530, cx
    memory16(_ds, 0x0) -= _cx;
    memory16(_ds, 0x2) -= _flags.carry;           //sbb word_28532, 0
loc_101FC:                                        //loc_101FC:
    _al = memory(_ds, _si + 4399);                //mov al, [si+112Fh]
    memory(_ds, _di + 4399) = _al;                //mov [di+112Fh], al
    _si += 1;                                     //inc si
    _di += 1;                                     //inc di
    _si &= 0x0fff;                                //and si, 0FFFh
    _di &= 0x0fff;                                //and di, 0FFFh
    _push(_es);                                   //push es
    _push(_di);                                   //push di
    _les(_di, 0x236C);                            //les di, dword_2A89C
    _stosb<MemAuto, DirAuto>();                   //stosb
    memory16(_ds, 0x236C) = _di;                  //mov word ptr dword_2A89C, di
    _di = _pop();                                 //pop di
    _es = _pop();                                 //pop es
    if (--_cx)                                    //loop loc_101FC
      goto loc_101FC;
loc_1021D:                                        //loc_1021D:
    _ax = memory16(_ds, 0x2);                     //mov ax, word_28532
    _flags.sign = _ax & 0x8000;                   //or ax, ax
    _ax |= _ax;
    if (_flags.sign)                              //js short loc_1022C
      goto loc_1022C;
    _ax = _ax | memory16(_ds, 0x0);               //or ax, word_28530
    if (_ax == 0)                                 //jz short loc_1022C
      goto loc_1022C;
    goto loc_101B2;                               //jmp short loc_101B2
loc_1022C:                                        //loc_1022C:
    _bp = _pop();                                 //pop bp
    _di = _pop();                                 //pop di
    _si = _pop();                                 //pop si
}

void sub_10230()
{
    _push(_si);                                   //push si
    _push(_di);                                   //push di
    _ax = _ds;                                    //mov ax, ds
    _es = _ax;                                    //mov es, ax
    _flags.direction = false;                     //cld
    _ax = 0x0001;                                 //mov ax, 1
    _cx = 0x013a;                                 //mov cx, 13Ah
    _di = 0x0004;                                 //mov di, 4
    _rep_stosw<MemAuto, DirAuto>();               //rep stosw
    _ax = 0x04e6;                                 //mov ax, 4E6h
    _dx = 0x0000;                                 //mov dx, 0
    _cx = 0x013a;                                 //mov cx, 13Ah
    _di = 0x0c46;                                 //mov di, 0C46h
    _bx = 0x09d2;                                 //mov bx, 9D2h
loc_10251:                                        //loc_10251:
    _stosw<MemAuto, DirAuto>();                   //stosw
    _ax += 0x0002;                                //add ax, 2
    memory16(_ds, _bx) = _dx;                     //mov [bx], dx
    _bx += 0x0002;                                //add bx, 2
    _dx += 0x0002;                                //add dx, 2
    if (--_cx)                                    //loop loc_10251
      goto loc_10251;
    _si = 0x0000;                                 //mov si, 0
    _di = 0x0002;                                 //mov di, 2
    _bx = 0x0274;                                 //mov bx, 274h
    _cx = 0x0139;                                 //mov cx, 139h
loc_1026B:                                        //loc_1026B:
    _ax = memory16(_ds, _si + 4);                 //mov ax, [si+4]
    _ax = _ax + memory16(_ds, _di + 4);           //add ax, [di+4]
    memory16(_ds, _bx + 4) = _ax;                 //mov [bx+4], ax
    memory16(_ds, _bx + 3142) = _si;              //mov [bx+0C46h], si
    memory16(_ds, _si + 1260) = _bx;              //mov [si+4ECh], bx
    memory16(_ds, _di + 1260) = _bx;              //mov [di+4ECh], bx
    _si += 0x0004;                                //add si, 4
    _di += 0x0004;                                //add di, 4
    _bx += 0x0002;                                //add bx, 2
    if (--_cx)                                    //loop loc_1026B
      goto loc_1026B;
    _ax = _ax ^ _ax;                              //xor ax, ax
    memory16(_ds, 0x112C) = _ax;                  //mov word_2965C, ax
    memory16(_ds, 0x112C) = _ax;                  //mov word_2965C, ax
    memory(_ds, 0x112E) = _al;                    //mov byte_2965E, al
    memory(_ds, 0x112E) = _al;                    //mov byte_2965E, al
    memory16(_ds, 0x4EA) = 0xffff;                //mov word_28A1A, 0FFFFh
    memory16(_ds, 0x9D0) = _ax;                   //mov word_28F00, ax
    _di = _pop();                                 //pop di
    _si = _pop();                                 //pop si
}

void sub_102A8()
{
    _flags.direction = false;                     //cld
    _di = _ds;                                    //mov di, ds
    _es = _di;                                    //mov es, di
    _di = 0x112f;                                 //mov di, 112Fh
    _al = 0x00;                                   //mov al, 0
    _bx = 0x0d;                                   //mov bx, 0Dh
loc_102B5:                                        //loc_102B5:
    _cx = _bx;                                    //mov cx, bx
    _rep_stosb<MemAuto, DirAuto>();               //rep stosb
    _al += 1;                                     //inc al
    if (_al != 0)                                 //jnz short loc_102B5
      goto loc_102B5;
loc_102BD:                                        //loc_102BD:
    _stosb<MemAuto, DirAuto>();                   //stosb
    _al += 1;                                     //inc al
    if (_al != 0)                                 //jnz short loc_102BD
      goto loc_102BD;
loc_102C2:                                        //loc_102C2:
    _al -= 1;                                     //dec al
    _stosb<MemAuto, DirAuto>();                   //stosb
    if (_al != 0)                                 //jnz short loc_102C2
      goto loc_102C2;
    _cx = 0x80;                                   //mov cx, 80h
    _rep_stosb<MemAuto, DirAuto>();               //rep stosb
    _cx = 0x80;                                   //mov cx, 80h
    _al = 0x20;                                   //mov al, 20h
    _rep_stosb<MemAuto, DirAuto>();               //rep stosb
}

void sub_104C9()  // Read data
{
    _push(_si);                                   //push si
    _si = memory16(_ds, 0x216A);                  //mov si, word_2A69A
    if ((short)_si < (short)0x236c)               //jl short loc_104DA
      goto loc_104DA;
    sub_10174();                                  //call sub_10174
    _si = 0x216c;                                 //mov si, 216Ch
loc_104DA:                                        //loc_104DA:
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    _ah = _ah ^ _ah;                              //xor ah, ah
    memory16(_ds, 0x216A) = _si;                  //mov word_2A69A, si
    _si = _pop();                                 //pop si
    _cl = 0x08;                                   //mov cl, 8
    _cl = _cl - memory(_ds, 0x112E);              //sub cl, byte_2965E
    _ax <<= _cl;                                  //shl ax, cl
    _dx |= _ax;                                   //or dx, ax
    memory(_ds, 0x112E) += 8;                     //add byte_2965E, 8
}

void sub_102D4()
{
    _si = memory16(_ds, 0x112A);                  //mov si, word_2965A
    _dx = memory16(_ds, 0x112C);                  //mov dx, word_2965C
    _cl = memory(_ds, 0x112E);                    //mov cl, byte_2965E
    _cx &= 0xff;                                  //and cx, 0FFh
    goto loc_102F4;                               //jmp short loc_102F4
loc_102E6:                                        //loc_102E6:
    _si >>= 1;                                    //shr si, 1
    _flags.carry = !!(_dx & 0x8000);              //shl dx, 1
    _dx <<= 1;
    _si = _si + 0x0000 + _flags.carry;;           //adc si, 0
    _si <<= 1;                                    //shl si, 1
    _si = memory16(_ds, _si + 3142);              //mov si, [si+0C46h]
    _cx -= 1;                                     //dec cx
loc_102F4:                                        //loc_102F4:
    if (_cx == 0)                                 //jz short loc_10312
      goto loc_10312;
loc_102F6:                                        //loc_102F6:
    if (_si < 0x04e6)                             //jb short loc_102E6
      goto loc_102E6;
    memory16(_ds, 0x112C) = _dx;                  //mov word_2965C, dx
    memory(_ds, 0x112E) = _cl;                    //mov byte_2965E, cl
    _si -= 0x04e6;                                //sub si, 4E6h
    _dx = _si;                                    //mov dx, si
    sub_10373();                                  //call sub_10373
    _ax = _dx;                                    //mov ax, dx
    _ax >>= 1;                                    //shr ax, 1
    return;                                       //retn
loc_10312:                                        //loc_10312:
    _push(_si);                                   //push si
    _si = memory16(_ds, 0x216A);                  //mov si, word_2A69A
    if ((short)_si < (short)0x236c)               //jl short loc_10323
      goto loc_10323;
    sub_10174();                                  //call sub_10174
    _si = 0x216c;                                 //mov si, 216Ch
loc_10323:                                        //loc_10323:
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    _ah = _ah ^ _ah;                              //xor ah, ah
    memory16(_ds, 0x216A) = _si;                  //mov word_2A69A, si
    _si = _pop();                                 //pop si
    _dh = _al;                                    //mov dh, al
    _push(_si);                                   //push si
    _si = memory16(_ds, 0x216A);                  //mov si, word_2A69A
    if ((short)_si < (short)0x236c)               //jl short loc_1033E
      goto loc_1033E;
    sub_10174();                                  //call sub_10174
    _si = 0x216c;                                 //mov si, 216Ch
loc_1033E:                                        //loc_1033E:
    _lodsb<MemAuto, DirAuto>();                   //lodsb
    _ah = _ah ^ _ah;                              //xor ah, ah
    memory16(_ds, 0x216A) = _si;                  //mov word_2A69A, si
    _si = _pop();                                 //pop si
    _dl = _al;                                    //mov dl, al
    _cl = 0x10;                                   //mov cl, 10h
    goto loc_102F6;                               //jmp short loc_102F6
}

void sub_10174()  // Read data
{
    _push(_di);                                   //push di
    _push(_bx);                                   //push bx
    _push(_cx);                                   //push cx
    _push(_dx);                                   //push dx
    _ax = _ax ^ _ax;                              //xor ax, ax
    _di = 0x216c;                                 //mov di, 216Ch
    _cx = 0x0100;                                 //mov cx, 100h
    _rep_stosw<MemAuto, DirAuto>();               //rep stosw
    _bx = memory16(_ds, 0x2370);                  //mov bx, word_2A8A0
    _cx = 0x0200;                                 //mov cx, 200h
    _dx = 0x216c;                                 //mov dx, 216Ch
    _ah = 0x3f;                                   //mov ah, 3Fh
    _interrupt(0x21);                             //int 21h
    if (!_flags.carry)                            //jnb short loc_10195
      goto loc_10195;
    _STOP_("exit program");                       //jmp loc_15E04
loc_10195:                                        //loc_10195:
    _dx = _pop();                                 //pop dx
    _cx = _pop();                                 //pop cx
    _bx = _pop();                                 //pop bx
    _di = _pop();                                 //pop di
}

void sub_10373()
{
    if (memory16(_ds, 0x4E8) < 32768)             //jb short loc_1037E
      goto loc_1037E;
    sub_10423();                                  //call sub_10423
loc_1037E:                                        //loc_1037E:
    _si = memory16(_ds, _si + 2514);              //mov si, [si+9D2h]
loc_10382:                                        //loc_10382:
    _ax = memory16(_ds, _si + 4);                 //mov ax, [si+4]
    _ax += 1;                                     //inc ax
    memory16(_ds, _si + 4) = _ax;                 //mov [si+4], ax
    _di =_si + 2;            //lea di, [si+2]
    if (_ax > memory16(_ds, _di + 4))             //ja short loc_10396
      goto loc_10396;
    goto loc_103D2;                               //jmp short loc_103D2
loc_10396:                                        //loc_10396:
    _di += 1;                                     //inc di
    _di += 1;                                     //inc di
    if (_ax > memory16(_ds, _di + 4))             //ja short loc_10396
      goto loc_10396;
    _di -= 1;                                     //dec di
    _di -= 1;                                     //dec di
    _xchg(_ax, memory16(_ds, _di + 4));           //xchg ax, [di+4]
    memory16(_ds, _si + 4) = _ax;                 //mov [si+4], ax
    _bx = memory16(_ds, _si + 3142);              //mov bx, [si+0C46h]
    memory16(_ds, _bx + 1260) = _di;              //mov [bx+4ECh], di
    if (_bx >= 0x04e6)                            //jnb short loc_103BA
      goto loc_103BA;
    memory16(_ds, _bx + 1262) = _di;              //mov [bx+4EEh], di
loc_103BA:                                        //loc_103BA:
    _xchg(_bx, memory16(_ds, _di + 3142));        //xchg bx, [di+0C46h]
    memory16(_ds, _bx + 1260) = _si;              //mov [bx+4ECh], si
    if (_bx >= 0x04e6)                            //jnb short loc_103CC
      goto loc_103CC;
    memory16(_ds, _bx + 1262) = _si;              //mov [bx+4EEh], si
loc_103CC:                                        //loc_103CC:
    memory16(_ds, _si + 3142) = _bx;              //mov [si+0C46h], bx
    _si = _di;                                    //mov si, di
loc_103D2:                                        //loc_103D2:
    _si = memory16(_ds, _si + 1260);              //mov si, [si+4ECh]
    _si |= _si;                                   //or si, si
    if (_si == 0)                                 //jz short locret_103DC
      goto locret_103DC;
    goto loc_10382;                               //jmp short loc_10382
locret_103DC:                                     //locret_103DC:
    return;
}

void sub_1034C()
{
    sub_103DD();                                  //call sub_103DD
    _si = _ax;                                    //mov si, ax
    _dl = memory(_ds, _si + 9074);                //mov dl, [si+2372h]
    _dh = 0x00;                                   //mov dh, 0
    _cl = 0x06;                                   //mov cl, 6
    _dx <<= _cl;                                  //shl dx, cl
    _push(_dx);                                   //push dx
    _cl = memory(_ds, _si + 9330);                //mov cl, [si+2472h]
    _ch = 0x00;                                   //mov ch, 0
    _cx -= 0x0002;                                //sub cx, 2
    sub_103FD();                                  //call sub_103FD
    _ax |= _si;                                   //or ax, si
    _rol(_ax, _cl);                               //rol ax, cl
    _ax &= 0x3f;                                  //and ax, 3Fh
    _dx = _pop();                                 //pop dx
    _ax += _dx;                                   //add ax, dx
}

void sub_103DD()
{
    _dx = memory16(_ds, 0x112C);                  //mov dx, word_2965C
    if ((char)memory(_ds, 0x112E) > (char)8)      //jg short loc_103EB
      goto loc_103EB;
    sub_104C9();                                  //call sub_104C9
loc_103EB:                                        //loc_103EB:
    _xchg(_dl, _dh);                              //xchg dl, dh
    _ax = _dx;                                    //mov ax, dx
    _dl = _dl ^ _dl;                              //xor dl, dl
    memory16(_ds, 0x112C) = _dx;                  //mov word_2965C, dx
    memory(_ds, 0x112E) -= 8;                     //sub byte_2965E, 8
    _ah = _ah ^ _ah;                              //xor ah, ah
}

void sub_103FD()
{
    _push(_cx);                                   //push cx
    _dx = memory16(_ds, 0x112C);                  //mov dx, word_2965C
    if ((char)memory(_ds, 0x112E) > (char)8)      //jg short loc_1040C
      goto loc_1040C;
    sub_104C9();                                  //call sub_104C9
loc_1040C:                                        //loc_1040C:
    _cx = _pop();                                 //pop cx
    _ax = _dx;                                    //mov ax, dx
    _dx <<= _cl;                                  //shl dx, cl
    memory16(_ds, 0x112C) = _dx;                  //mov word_2965C, dx
    memory(_ds, 0x112E) -= _cl;                   //sub byte_2965E, cl
    _dx = 0xffff;                                 //mov dx, 0FFFFh
    _dx >>= _cl;                                  //shr dx, cl
    _dx = (~_dx);                                 //not dx
    _ax &= _dx;                                   //and ax, dx
}

void sub_10423()
{
    _push(_si);                                   //push si
    _ax = _ds;                                    //mov ax, ds
    _es = _ax;                                    //mov es, ax
    _si = _si ^ _si;                              //xor si, si
    _di = _si;                                    //mov di, si
loc_1042C:                                        //loc_1042C:
    if (memory16(_ds, _si + 3142) < 1254)         //jb short loc_10449
      goto loc_10449;
    _ax = memory16(_ds, _si + 4);                 //mov ax, [si+4]
    _ax += 1;                                     //inc ax
    _ax >>= 1;                                    //shr ax, 1
    memory16(_ds, _di + 4) = _ax;                 //mov [di+4], ax
    _ax = memory16(_ds, _si + 3142);              //mov ax, [si+0C46h]
    memory16(_ds, _di + 3142) = _ax;              //mov [di+0C46h], ax
    _di += 1;                                     //inc di
    _di += 1;                                     //inc di
loc_10449:                                        //loc_10449:
    _si += 1;                                     //inc si
    _si += 1;                                     //inc si
    if (_si < 0x04e6)                             //jb short loc_1042C
      goto loc_1042C;
    _si = _si ^ _si;                              //xor si, si
    _di = 0x0274;                                 //mov di, 274h
loc_10456:                                        //loc_10456:
    _bx = _si;                                    //mov bx, si
    _bx += 1;                                     //inc bx
    _bx += 1;                                     //inc bx
    _ax = memory16(_ds, _si + 4);                 //mov ax, [si+4]
    _ax = _ax + memory16(_ds, _bx + 4);           //add ax, [bx+4]
    memory16(_ds, _di + 4) = _ax;                 //mov [di+4], ax
    _bx = _di;                                    //mov bx, di
loc_10468:                                        //loc_10468:
    _bx -= 1;                                     //dec bx
    _bx -= 1;                                     //dec bx
    if (_ax < memory16(_ds, _bx + 4))             //jb short loc_10468
      goto loc_10468;
    _bx += 1;                                     //inc bx
    _bx += 1;                                     //inc bx
    _cx = _di;                                    //mov cx, di
    _cx -= _bx;                                   //sub cx, bx
    _cx >>= 1;                                    //shr cx, 1
    _flags.direction = true;                      //std
    _push(_cx);                                   //push cx
    _push(_si);                                   //push si
    _push(_di);                                   //push di
    _si = _di + 4;            //lea si, [di+4]
    _di = _si;                                    //mov di, si
    _si -= 1;                                     //dec si
    _si -= 1;                                     //dec si
    _rep_movsw<MemAuto, MemAuto, DirAuto>();      //rep movsw
    memory16(_ds, _bx + 4) = _ax;                 //mov [bx+4], ax
    _di = _pop();                                 //pop di
    _si = _pop();                                 //pop si
    _cx = _pop();                                 //pop cx
    _push(_si);                                   //push si
    _push(_di);                                   //push di
    _si = _di + 3142;         //lea si, [di+0C46h]
    _di = _si;                                    //mov di, si
    _si -= 1;                                     //dec si
    _si -= 1;                                     //dec si
    _rep_movsw<MemAuto, MemAuto, DirAuto>();      //rep movsw
    _di = _pop();                                 //pop di
    _si = _pop();                                 //pop si
    memory16(_ds, _bx + 3142) = _si;              //mov [bx+0C46h], si
    _si += 0x0004;                                //add si, 4
    _di += 0x0002;                                //add di, 2
    if (_di < 0x04e6)                             //jb short loc_10456
      goto loc_10456;
    _si = _si ^ _si;                              //xor si, si
loc_104AD:                                        //loc_104AD:
    _di = memory16(_ds, _si + 3142);              //mov di, [si+0C46h]
    memory16(_ds, _di + 1260) = _si;              //mov [di+4ECh], si
    if (_di >= 0x04e6)                            //jnb short loc_104BF
      goto loc_104BF;
    memory16(_ds, _di + 1262) = _si;              //mov [di+4EEh], si
loc_104BF:                                        //loc_104BF:
    _si += 1;                                     //inc si
    _si += 1;                                     //inc si
    if (_si < 0x04e6)                             //jb short loc_104AD
      goto loc_104AD;
    _si = _pop();                                 //pop si
}

