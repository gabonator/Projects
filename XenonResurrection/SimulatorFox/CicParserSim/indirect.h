void sub_5dce();
void sub_476c();
void sub_4dfd();
void sub_4e87();
void sub_63f1();
void sub_63bf();
void sub_4d0b();
void sub_4748();
void sub_47b7();
void sub_47fa();
void sub_4df9();
void sub_47b7();
void sub_47d3();
void sub_5a04();
void sub_4e88();
void sub_4d0c();
void sub_4dc9();
void sub_4d10();
void sub_4db1();
void sub_4826();
void sub_4f03();
void sub_4e2e();
void sub_495b();
void sub_48cc();
void sub_48d6();
void sub_622e();
void sub_4833();

void sub_4d0b()
{
    return;
}

void _indirectCall(int ofs)
{
    switch(ofs)
    {
        case 0x5dce: sub_5dce(); return;
        case 0x476c: sub_476c(); return; // player
        case 0x4dfd: sub_4dfd(); return;
        case 0x4e87: sub_4e87(); return;
        case 0x63f1: sub_63f1(); return;
        case 0x63bf: sub_63bf(); return;
        case 0x4d0b: sub_4d0b(); return;
        case 0x4748: sub_4748(); return; // jump
        case 0x47b4: sub_47b7(); return;
        case 0x47fa: sub_47fa(); return; // go right
        case 0x4df9: sub_4df9(); return;
        case 0x47b7: sub_47b7(); return;
        case 0x47d3: sub_47d3(); return;
        case 0x5a04: sub_5a04(); return;
        case 0x4e88: sub_4e88(); return; // block collision
        case 0x4d0c: sub_4d0c(); return; // block collision
            
        case 0x4dc9: sub_4dc9(); return; //collectable
        case 0x4d10: sub_4d10(); return; //collectable
        case 0x4db1: sub_4db1(); return; //collectable
        case 0x4826: sub_4826(); return; // hit by homeless
        case 0x4f03: sub_4f03(); return;
        case 0x4e2e: sub_4e2e(); return;
        case 0x495b: sub_495b(); return; // grab item
        case 0x48cc: sub_48cc(); return;
        case 0x48d6: sub_48d6(); return;
        case 0x622e: sub_622e(); return;
        case 0x4833: sub_4833(); return; // ladder
    }
    std::cout << "Ignore indirect " << ofs << "\n";
    //_ASSERT(0);
}


/*
void sub_4ca2();
void sub_4cf0();
void sub_64df();

void sub_4bb6() // jump
{
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _dx = memory16(_ds, 21130);                 //mov dx, word ptr [0x528a]
    _dx += 0xffe0;                          //add dx, -0x20
    _bp = -_bp;                                 //neg bp
    if ((short)_dx >= (short)_bp)               //jge loc_4bc8
        goto loc_4bc8;
    _bp = _dx;                                  //mov bp, dx
loc_4bc8:                                       //loc_4bc8:
    memory16(_ds, 21130) = _bp;                 //mov word ptr [0x528a], bp
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
}

void sub_4b7d()
{
    _push(_ax);                                 //push ax
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_bp);                                 //push bp
    _ax = _ax ^ _ax;                            //xor ax, ax
    if (memory(_ds, 25863) == 0x00)             //jz loc_4b95
        goto loc_4b95;
    _ax = memory16(_ds, 0x5285);                //mov ax, [0x5285]
    
    //_ax = 1; // gabo
    
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
    _ax <<= 1;                                  //shl ax, 1
loc_4b95:                                       //loc_4b95:
    _cl = memory(_ds, 21124);                   //mov cl, byte ptr [0x5284]
    _sar(_ax, _cl);                             //sar ax, cl
    _dx = memory16(_ds, 21122);                 //mov dx, word ptr [0x5282]
    _dx += _ax;                                 //add dx, ax
    if ((short)_dx >= (short)_bp)               //jge loc_4bad
        goto loc_4bad;
    _bp = -_bp;                                 //neg bp
    if ((short)_dx <= (short)_bp)               //jle loc_4bad
        goto loc_4bad;
    _bp = _dx;                                  //mov bp, dx
loc_4bad:                                       //loc_4bad:
    memory16(_ds, 21122) = _bp;                 //mov word ptr [0x5282], bp
    _bp = _pop();                               //pop bp
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _ax = _pop();                               //pop ax
}

void sub_4c12()
{
    if (memory(_ds, 21127) == _al)              //jz loc_4c25
        goto loc_4c25;
    memory(_ds, 0x5287) = _al;                  //mov [0x5287], al
    _bx = memory16(_ds, _bx + 28351);           //mov bx, word ptr [bx+0x6ebf]
    memory16(_ds, 21128) = _bx;                 //mov word ptr [0x5288], bx
    goto loc_4c29;                              //jmp loc_4c29
loc_4c25:                                       //loc_4c25:
    _bx = memory16(_ds, 21128);                 //mov bx, word ptr [0x5288]
loc_4c29:                                       //loc_4c29:
    return;
}

void sub_4c2a()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_dx);                                 //push dx
    _ax = memory16(_ds, _bx);                   //mov ax, word ptr [bx]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (!_flags.sign)                           //jns loc_4c37
        goto loc_4c37;
    _bx += _ax;                                 //add bx, ax
    _ax = memory16(_ds, _bx);                   //mov ax, word ptr [bx]
loc_4c37:                                       //loc_4c37:
    _dh = memory(_ds, 21125);                   //mov dh, byte ptr [0x5285]
    _dh &= 0x80;                                //and dh, 0x80
    _ah |= _dh;                                 //or ah, dh
    memory16(_ds, 0x5280) = _ax;                //mov [0x5280], ax
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    memory16(_ds, 21128) = _bx;                 //mov word ptr [0x5288], bx
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    return;                                     //ret
    _STOP_("db bdh");                           //db bdh
    _STOP_("db c0h");                           //db c0h
    _STOP_("db 00h");                           //db 00h
    _STOP_("db e8h");                           //db e8h
    _STOP_("db 7dh");                           //db 7dh
    _STOP_("db ffh");                           //db ffh
    _STOP_("db b0h");                           //db b0h
    _STOP_("db 0eh");                           //db 0eh
    _STOP_("db 8ah");                           //db 8ah
    _STOP_("db 26h");                           //db 26h
    _STOP_("db 85h");                           //db 85h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db e4h");                           //db e4h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db a3h");                           //db a3h
    _STOP_("db 80h");                           //db 80h
    _STOP_("db 52h");                           //db 52h
    _STOP_("db c6h");                           //db c6h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db 0fh");                           //db 0fh
    _STOP_("db 65h");                           //db 65h
    _STOP_("db 06h");                           //db 06h
    _STOP_("db c3h");                           //db c3h
    _STOP_("sp-trace-fail");                    //sub_4c2a endp_failed
    _STOP_("continues");                        //sub_4c65 proc near
}

void sub_4748()
{
    if (memory(_ds, 25885) < 0x03)              //jc loc_4755
        goto loc_4755;
    memory(_ds, 25871) = 0x06;                  //mov byte ptr [0x650f], 0x6
    return;                                     //ret
loc_4755:                                       //loc_4755:
    memory(_ds, 25885) += 1;                    //inc byte ptr [0x651d]
    _bp = 0x0030;                               //mov bp, 0x30
    sub_4bb6();                                 //call sub_4bb6 -- set jump vector dy
    _bp = 0x0040;                               //mov bp, 0x40
    sub_4b7d();                                 //call sub_4b7d
    sub_4c12();                                 //call sub_4c12
    sub_4c2a();                                 //call sub_4c2a
}

void sub_6496()
{
    _ax = memory16(_ds, _si);                   //mov ax, word ptr [si]
    memory16(_ds, _di) = _ax;                   //mov word ptr [di], ax
    _ax = memory16(_ds, _si + 2);               //mov ax, word ptr [si+0x2]
    _bx = memory16(_ds, _si + 10);              //mov bx, word ptr [si+0xa]
    _bp = _bx;                                  //mov bp, bx
    _bx = memory16(_ds, _bx + -2);              //mov bx, word ptr [bx-0x2]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _xchg(_ax, _bx);                            //xchg ax, bx
    _cbw();                                     //cbw
    _xchg(_ax, _bx);                            //xchg ax, bx
    _ax -= _bx;                                 //sub ax, bx
    memory16(_ds, _di + 2) = _ax;               //mov word ptr [di+0x2], ax
    _bx = memory16(_ds, _bp + 4);               //mov bx, word ptr ds:[bp-0x4]
    _bh &= 0x1f;                                //and bh, 0x1f
    _bx += 0x801e;                              //add bx, 0x801e
    _dx = 0x00b0;                               //mov dx, 0xb0
    _ax = memory16(_ds, 0x527c);                //mov ax, [0x527c]
    if ((short)memory16(_ds, _si) < (short)_ax) //jl loc_64c9
        goto loc_64c9;
    _dx = -_dx;                                 //neg dx
    _bh = _bh ^ 0x80;                           //xor bh, 0x80
loc_64c9:                                       //loc_64c9:
    memory16(_ds, _di + 4) = _bx;               //mov word ptr [di+0x4], bx
    memory16(_ds, _di + 6) = _dx;               //mov word ptr [di+0x6], dx
    memory16(_ds, _di + 14) = 0x0000;           //mov word ptr [di+0xe], 0x0
    _sar(_dx, 1);                               //sar dx, 1
    _sar(_dx, 1);                               //sar dx, 1
    _sar(_dx, 1);                               //sar dx, 1
    _sar(_dx, 1);                               //sar dx, 1
    memory16(_ds, _di) += _dx;                  //add word ptr [di], dx
}

void sub_592d()
{
    _di = 0x5600;                               //mov di, 0x5600
    _push(_cx);                                 //push cx
    _cx = 0x0004;                               //mov cx, 0x4
loc_5934:                                       //loc_5934:
    if (memory16(_ds, _di + 4) != 0xffff)   //jnz loc_593d
        goto loc_593d;
    _cx = _pop();                               //pop cx
    _flags.carry = false;                       //clc
    return;                                     //ret
loc_593d:                                       //loc_593d:
    _di += 0x0012;                              //add di, 0x12
    if (--_cx)                                  //loop loc_5934
        goto loc_5934;
    _cx = _pop();                               //pop cx
    _flags.carry = true;                        //stc
}

void sub_4d0b()
{
    return;
}

void sub_63c9()
{
    _ax = memory16(_ds, _si + 8);               //mov ax, word ptr [si+0x8]
    memory16(_ds, _si) -= _ax;                  //sub word ptr [si], ax
    _ax = memory16(_ds, _si);                   //mov ax, word ptr [si]
    _ax = _ax - memory16(_ds, _si + 15);        //sub ax, word ptr [si+0xf]
    _dx = _ax;                                  //mov dx, ax
    if ((short)_ax >= 0)                        //jns loc_63d9
        goto loc_63d9;
    _ax = -_ax;                                 //neg ax
loc_63d9:                                       //loc_63d9:
    if (_ax <= memory16(_ds, _si + 17))         //jbe loc_63f0
        goto loc_63f0;
    _ax = memory16(_ds, _si + 8);               //mov ax, word ptr [si+0x8]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (!_flags.sign)                           //jns loc_63e7
        goto loc_63e7;
    _ax = -_ax;                                 //neg ax
loc_63e7:                                       //loc_63e7:
    _flags.sign = !!(_dx & 0x8000);             //or dx, dx
    _dx |= _dx;
    if (!_flags.sign)                           //jns loc_63ed
        goto loc_63ed;
    _ax = -_ax;                                 //neg ax
loc_63ed:                                       //loc_63ed:
    memory16(_ds, _si + 8) = _ax;               //mov word ptr [si+0x8], ax
loc_63f0:                                       //loc_63f0:
    return;
}

void sub_63bf()
{
    _al = memory(_ds, _si + 7);                 //mov al, byte ptr [si+0x7]
    if (!(_al & 0xc0))                          //jz sub_63c9
        { sub_63c9(); return; }
    _STOP_("goto loc_5a58");                    //jmp loc_5a58
}

void sub_63f1()
{
    _al = memory(_ds, _si + 7);                 //mov al, byte ptr [si+0x7]
    if (!(_al & 0xc0))                          //jz loc_63fb
        goto loc_63fb;
    _STOP_("goto loc_5a58");                    //jmp loc_5a58
loc_63fb:                                       //loc_63fb:
    if (memory(_ds, _si + 5) & 0x20)            //jnz loc_6404
        goto loc_6404;
    goto loc_6495;                              //jmp loc_6495
loc_6404:                                       //loc_6404:
    _al = memory(_ds, _si + 18);                //mov al, byte ptr [si+0x12]
    if (!(_al & 0xc0))                          //jz loc_6414
        goto loc_6414;
    _dx = _dx ^ _dx;                            //xor dx, dx
    if (_al & 0x40)                             //jnz loc_641e
        goto loc_641e;
    _dx -= 1;                                   //dec dx
    goto loc_641e;                              //jmp loc_641e
loc_6414:                                       //loc_6414:
    _dx = _dx ^ _dx;                            //xor dx, dx
    _ax = memory16(_ds, 0x527c);                //mov ax, [0x527c]
    if ((short)memory16(_ds, _si) >= (short)_ax)//jge loc_641e
        goto loc_641e;
    _dx -= 1;                                   //dec dx
loc_641e:                                       //loc_641e:
    memory16(_ds, _si + 8) = _dx;               //mov word ptr [si+0x8], dx
    _al = memory(_ds, _si + 14);                //mov al, byte ptr [si+0xe]
    _al |= _al;                                 //or al, al
    if (_al != 0)                               //jnz loc_6476
        goto loc_6476;
    _flags.carry = memory(_ds, _si + 15) < 0x01;//sub byte ptr [si+0xf], 0x1
    memory(_ds, _si + 15) -= 0x01;
    memory(_ds, _si + 15) = memory(_ds, _si + 15) + 0x00 + _flags.carry;
    if (memory(_ds, _si + 15) != 0)                                //jnz loc_6495
        goto loc_6495;
    _ax = memory16(_ds, 0x527e);                //mov ax, [0x527e]
    _ax = _ax - memory16(_ds, _si + 2);         //sub ax, word ptr [si+0x2]
    if ((short)_ax >= 0)                        //jns loc_643c
        goto loc_643c;
    _ax = -_ax;                                 //neg ax
loc_643c:                                       //loc_643c:
    if (_ax > 0x0018)                           //ja loc_6495
        goto loc_6495;
    _ax = memory16(_ds, 0x527c);                //mov ax, [0x527c]
    _ax = _ax - memory16(_ds, _si);             //sub ax, word ptr [si]
    if ((short)_ax >= 0)                        //jns loc_644a
        goto loc_644a;
    _ax = -_ax;                                 //neg ax
loc_644a:                                       //loc_644a:
    _dx = memory16(_ds, _si + 17);              //mov dx, word ptr [si+0x11]
    _dh &= 0x3f;                                //and dh, 0x3f
    if (_dx < _ax)                              //jc loc_6495
        goto loc_6495;
    _al = memory(_ds, _si + 18);                //mov al, byte ptr [si+0x12]
    _rol(_al, 1);                               //rol al, 1
    _rol(_al, 1);                               //rol al, 1
    _al &= 0x03;                                //and al, 0x3
    if (_al == 0)                               //jz loc_646d
        goto loc_646d;
    _ax = memory16(_ds, 0x527c);                //mov ax, [0x527c]
    _dx = memory16(_ds, _si);                   //mov dx, word ptr [si]
    if (_al == 0x01)                            //jz loc_6469
        goto loc_6469;
    _xchg(_ax, _dx);                            //xchg ax, dx
loc_6469:                                       //loc_6469:
    if ((short)_ax > (short)_dx)                //jg loc_6495
        goto loc_6495;
loc_646d:                                       //loc_646d:
    memory(_ds, _si + 14) = 0x1e;               //mov byte ptr [si+0xe], 0x1e
    sub_64df();                                 //call sub_64df
    goto loc_6495;                              //jmp loc_6495
loc_6476:                                       //loc_6476:
    memory(_ds, _si + 14) -= 1;                 //dec byte ptr [si+0xe]
    if (!(memory(_ds, _si + 7) & 0x20))         //jz loc_6495
        goto loc_6495;
    memory16(_ds, _si + 10) += 0x0004;          //add word ptr [si+0xa], 0x4
    sub_592d();                                 //call sub_592d
    if (_flags.carry)                           //jc loc_6491
        goto loc_6491;
    sub_6496();                                 //call sub_6496
    _al = memory(_ds, _si + 16);                //mov al, byte ptr [si+0x10]
    memory(_ds, _si + 15) = _al;                //mov byte ptr [si+0xf], al
loc_6491:                                       //loc_6491:
    memory(_ds, _si + 14) = 0x00;               //mov byte ptr [si+0xe], 0x0
loc_6495:                                       //loc_6495:
    return;
}

void sub_4e87()
{
}

void sub_4cd8()
{
    memory(_ds, 25884) = 0x01;                  //mov byte ptr [0x651c], 0x1
    memory(_ds, 21124) = 0x00;                  //mov byte ptr [0x5284], 0x0
    if ((short)memory16(_ds, 21130) >= (short)0x0000)//jge loc_4ceb
        goto loc_4ceb;
    {sub_4ca2(); return; };                     //
loc_4ceb:                                       //loc_4ceb:
    memory(_ds, 21118) &= 0xf0;                 //and byte ptr [0x527e], 0xf0
    sub_4cf0();
}

void sub_4dfd()
{
    sub_4cd8();                                 //call sub_4cd8
}

void sub_4ca2()
{
    memory(_ds, 0x6526) |= 1;
}

void sub_4ca3()
{
    _push(_cs);                                 //push cs
    _bx += _ax;                                 //add bx, ax
    _STOP_("sp-trace-fail");                    //sub_4ca3 endp_failed
    _STOP_("continues");                        //sub_4ca8 proc near
}

void sub_4ca8()
{
    _push(_ax);                                 //push ax
    _ax = memory16(_ds, 0x5282);                //mov ax, [0x5282]
    _sar(_ax, 1);                               //sar ax, 1
    _sar(_ax, 1);                               //sar ax, 1
    _sar(_ax, 1);                               //sar ax, 1
    _sar(_ax, 1);                               //sar ax, 1
    memory16(_ds, 21116) -= _ax;                //sub word ptr [0x527c], ax
    memory16(_ds, 21122) = 0x0000;              //mov word ptr [0x5282], 0x0
    if (memory(_ds, 25876) == 0x00)             //jz loc_4cd6
        goto loc_4cd6;
    if (memory(_ds, 25871) == 0x06)             //jz loc_4cd6
        goto loc_4cd6;
    memory(_ds, 25875) = 0x14;                  //mov byte ptr [0x6513], 0x14
    memory(_ds, 25876) = 0x00;                  //mov byte ptr [0x6514], 0x0
loc_4cd6:                                       //loc_4cd6:
    _ax = _pop();                               //pop ax
}



void sub_4be8()
{
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _ch = _ch ^ _ch;                            //xor ch, ch
    _ax = memory16(_ds, 0x5282);                //mov ax, [0x5282]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (!_flags.sign)                           //jns loc_4bf7
        goto loc_4bf7;
    _ax = -_ax;                                 //neg ax
    _ch += 1;                                   //inc ch
loc_4bf7:                                       //loc_4bf7:
    _cl = memory(_ds, 21124);                   //mov cl, byte ptr [0x5284]
    _dx = 0x000c;                               //mov dx, 0xc
    _dx >>= _cl;                                //shr dx, cl
    _flags.carry = _ax < _dx;                   //sub ax, dx
    _ax -= _dx;
    if (!_flags.carry)                          //jnc loc_4c06
        goto loc_4c06;
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_4c06:                                       //loc_4c06:
    _ch |= _ch;                                 //or ch, ch
    if (_ch == 0)                               //jz loc_4c0c
        goto loc_4c0c;
    _ax = -_ax;                                 //neg ax
loc_4c0c:                                       //loc_4c0c:
    memory16(_ds, 0x5282) = _ax;                //mov [0x5282], ax
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
}

void sub_476c()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_dx);                                 //push dx
    memory(_ds, 0x5287) = _al;                  //mov [0x5287], al
    sub_4be8();                                 //call sub_4be8
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (!_flags.sign)                           //jns loc_477b
        goto loc_477b;
    _ax = -_ax;                                 //neg ax
loc_477b:                                       //loc_477b:
    if (_ax < 0x0010)                           //jc loc_479d
        goto loc_479d;
    _al = memory(_ds, 0x5281);                  //mov al, [0x5281]
    _ah = memory(_ds, 21123);                   //mov ah, byte ptr [0x5283]
    _rol(_al, 1);                               //rol al, 1
    _rol(_ah, 1);                               //rol ah, 1
    _ax &= 0x0101;                              //and ax, 0x101
    if (_al != _ah)                             //jnz loc_479d
        goto loc_479d;
    _bl = memory(_ds, 25865);                   //mov bl, byte ptr [0x6509]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bx += 0x0004;                              //add bx, 0x4
    _bx <<= 1;                                  //shl bx, 1
loc_479d:                                       //loc_479d:
    _bx = memory16(_ds, _bx + 28351);           //mov bx, word ptr [bx+0x6ebf]
    memory16(_ds, 21128) = _bx;                 //mov word ptr [0x5288], bx
    _ax = memory16(_ds, _bx);                   //mov ax, word ptr [bx]
    _dh = memory(_ds, 21125);                   //mov dh, byte ptr [0x5285]
    _dh &= 0x80;                                //and dh, 0x80
    _ah |= _dh;                                 //or ah, dh
    memory16(_ds, 0x5280) = _ax;                //mov [0x5280], ax
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}



void sub_5ee4()
{
    _ax = 0x0001;                               //mov ax, 0x1
    if ((short)memory16(_ds, _si + 8) > (short)0x0000)
        goto loc_5eef;
    _ax = -_ax;                                 //neg ax
loc_5eef:                                       //loc_5eef:
    _di -= _ax;                                 //sub di, ax
}

void sub_64df()
{
    _bx = memory16(_ds, _si + 10);              //mov bx, word ptr [si+0xa]
loc_64e2:                                       //loc_64e2:
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    if ((short)memory16(_ds, _bx) >= (short)0x0000)//jge loc_64e2
        goto loc_64e2;
    _bx += 1;                                   //inc bx
    _bx += 1;                                   //inc bx
    memory16(_ds, _si + 10) = _bx;              //mov word ptr [si+0xa], bx
}


void sub_5eca()
{
    _push(_ax);                                 //push ax
    _push(_dx);                                 //push dx
    _ax = memory16(_ds, _si + 8);               //mov ax, word ptr [si+0x8]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (!_flags.sign)                           //jns loc_5ed5
        goto loc_5ed5;
    _ax = -_ax;                                 //neg ax
loc_5ed5:                                       //loc_5ed5:
    _dx = memory16(_ds, _si);                   //mov dx, word ptr [si]
    if ((short)memory16(_ds, _si + 15) <= (short)_dx)//jle loc_5ede
        goto loc_5ede;
    _ax = -_ax;                                 //neg ax
loc_5ede:                                       //loc_5ede:
    memory16(_ds, _si + 8) = _ax;               //mov word ptr [si+0x8], ax
    _dx = _pop();                               //pop dx
    _ax = _pop();                               //pop ax
}

void sub_6567()
{
    _cl = 0x04;                                 //mov cl, 0x4
    _ax = memory16(_ds, _si + 2);               //mov ax, word ptr [si+0x2]
    _al &= 0xf0;                                //and al, 0xf0
    _ax <<= _cl;                                //shl ax, cl
    _di = memory16(_ds, _si);                   //mov di, word ptr [si]
    _di >>= _cl;                                //shr di, cl
    _di += _ax;                                 //add di, ax
    _es = memory16(_ds, 21100);                 //mov es, word ptr [0x526c]
    _al = memory(_es, _di);                     //mov al, byte ptr es:[di]
    _bx = 0x73a3;                               //mov bx, 0x73a3
    _xlat();                                    //xlat
}


void sub_64ef()
{
    _bx = memory16(_ds, _si + 10);              //mov bx, word ptr [si+0xa]
loc_64f2:                                       //loc_64f2:
    _bx -= 1;                                   //dec bx
    _bx -= 1;                                   //dec bx
    if ((short)memory16(_ds, _bx) >= (short)0x0000)//jge loc_64f2
        goto loc_64f2;
    _bx -= 1;                                   //dec bx
    _bx -= 1;                                   //dec bx
    memory16(_ds, _si + 10) = _bx;              //mov word ptr [si+0xa], bx
}

void sub_621c()
{
    _dl = memory(_ds, _si + 19);                //mov dl, byte ptr [si+0x13]
    _dh = _dh ^ _dh;                            //xor dh, dh
    _ax = memory16(_ds, 0x527c);                //mov ax, [0x527c]
    if ((short)memory16(_ds, _si) > (short)_ax) //jg loc_622a
        goto loc_622a;
    _dx = -_dx;                                 //neg dx
loc_622a:                                       //loc_622a:
    memory16(_ds, _si + 8) = _dx;               //mov word ptr [si+0x8], dx
}

void sub_5dce()
{
    _al = memory(_ds, _si + 7);                 //mov al, byte ptr [si+0x7]
    if (!(_al & 0xc0))                          //jz loc_5dd8
        goto loc_5dd8;
    _STOP_("goto loc_5a58");                    //jmp loc_5a58
loc_5dd8:                                       //loc_5dd8:
    _al = memory(_ds, _si + 14);                //mov al, byte ptr [si+0xe]
    if (_al != 0x00)                            //jnz loc_5e0e
        goto loc_5e0e;
    if (memory(_ds, 25874) != 0x00)             //jnz loc_5e44
        goto loc_5e44;
    _ax = memory16(_ds, 0x527c);                //mov ax, [0x527c]
    _ax = _ax - memory16(_ds, _si);             //sub ax, word ptr [si]
    if ((short)_ax >= 0)                        //jns loc_5def
        goto loc_5def;
    _ax = -_ax;                                 //neg ax
loc_5def:                                       //loc_5def:
    if (memory16(_ds, _si + 23) < _ax)          //jc loc_5e44
        goto loc_5e44;
    _ax = memory16(_ds, 0x527e);                //mov ax, [0x527e]
    _ax = _ax - memory16(_ds, _si + 2);         //sub ax, word ptr [si+0x2]
    if ((short)_ax >= 0)                        //jns loc_5dfe
        goto loc_5dfe;
    _ax = -_ax;                                 //neg ax
loc_5dfe:                                       //loc_5dfe:
    if (_ax > 0x001a)                           //ja loc_5e44
        goto loc_5e44;
    memory(_ds, _si + 14) += 1;                 //inc byte ptr [si+0xe]
    sub_64df();                                 //call sub_64df
    sub_621c();                                 //call sub_621c
    goto loc_5e44;                              //jmp loc_5e44
loc_5e0e:                                       //loc_5e0e:
    if (_al != 0x01)                            //jnz loc_5e4c
        goto loc_5e4c;
    if (memory(_ds, 25874) != 0x00)             //jnz loc_5e44
        goto loc_5e44;
    _ax = memory16(_ds, 0x527c);                //mov ax, [0x527c]
    _ax = _ax - memory16(_ds, _si);             //sub ax, word ptr [si]
    if ((short)_ax >= 0)                        //jns loc_5e22
        goto loc_5e22;
    _ax = -_ax;                                 //neg ax
loc_5e22:                                       //loc_5e22:
    if (memory16(_ds, _si + 23) < _ax)          //jc loc_5e45
        goto loc_5e45;
    _ax += 0x0032;                              //add ax, 0x32
    if (memory16(_ds, _si + 23) < _ax)          //jc loc_5e44
        goto loc_5e44;
    _ax = memory16(_ds, 0x527e);                //mov ax, [0x527e]
    _ax = _ax - memory16(_ds, _si + 2);         //sub ax, word ptr [si+0x2]
    if ((short)_ax >= 0)                        //jns loc_5e39
        goto loc_5e39;
    _ax = -_ax;                                 //neg ax
loc_5e39:                                       //loc_5e39:
    if (_ax > 0x003c)                           //ja loc_5e44
        goto loc_5e44;
    memory(_ds, _si + 14) += 1;                 //inc byte ptr [si+0xe]
    sub_64df();                                 //call sub_64df
loc_5e44:                                       //loc_5e44:
    return;                                     //ret
loc_5e45:                                       //loc_5e45:
    sub_64ef();                                 //call sub_64ef
    memory(_ds, _si + 14) -= 1;                 //dec byte ptr [si+0xe]
    return;                                     //ret
loc_5e4c:                                       //loc_5e4c:
    if (_al != 0x02)                            //jnz loc_5e92
        goto loc_5e92;
    sub_6567();                                 //call sub_6567
    _al |= _al;                                 //or al, al
    if (_al != 0)                               //jnz loc_5e5a
        goto loc_5e5a;
    sub_5eca();                                 //call sub_5eca
loc_5e5a:                                       //loc_5e5a:
    memory(_ds, _si + 2) &= 0xf0;               //and byte ptr [si+0x2], 0xf0
    sub_5ee4();                                 //call sub_5ee4
    _al = memory(_es, (_di + 65280)&0xffff);             //mov al, byte ptr es:[di+0xff00]
    _bx = 0x72a3;                               //mov bx, 0x72a3
    _xlat();                                    //xlat
    _al &= 0x01;                                //and al, 0x1
    if (_al == 0)                               //jz loc_5e71
        goto loc_5e71;
    sub_5eca();                                 //call sub_5eca
loc_5e71:                                       //loc_5e71:
    _ax = memory16(_ds, _si + 8);               //mov ax, word ptr [si+0x8]
    memory16(_ds, _si) -= _ax;                  //sub word ptr [si], ax
    if ((short)memory16(_ds, _si) >= 0)         //jns loc_5e7f
        goto loc_5e7f;
    _ax = -_ax;                                 //neg ax
    memory16(_ds, _si) -= _ax;                  //sub word ptr [si], ax
    memory16(_ds, _si + 8) = _ax;               //mov word ptr [si+0x8], ax
loc_5e7f:                                       //loc_5e7f:
    _ax = memory16(_ds, 0x527c);                //mov ax, [0x527c]
    _ax = _ax - memory16(_ds, _si);             //sub ax, word ptr [si]
    if ((short)_ax >= 0)                        //jns loc_5e88
        goto loc_5e88;
    _ax = -_ax;                                 //neg ax
loc_5e88:                                       //loc_5e88:
    if (_ax < 0x0280)                           //jc loc_5ec9
        goto loc_5ec9;
    memory(_ds, _si + 14) += 1;                 //inc byte ptr [si+0xe]
    goto loc_5ec9;                              //jmp loc_5ec9
loc_5e92:                                       //loc_5e92:
    if (_al != 0x03)                            //jnz loc_5ec9
        goto loc_5ec9;
    _cl = 0x04;                                 //mov cl, 0x4
    _ax = memory16(_ds, _si + 15);              //mov ax, word ptr [si+0xf]
    _sar(_ax, _cl);                             //sar ax, cl
    _ax = _ax - memory16(_ds, 21104);           //sub ax, word ptr [0x5270]
    if (_ax >= 0x0015)                          //jnc loc_5eb4
        goto loc_5eb4;
    _ax = memory16(_ds, _si + 17);              //mov ax, word ptr [si+0x11]
    _sar(_ax, _cl);                             //sar ax, cl
    _ax = _ax - memory16(_ds, 21106);           //sub ax, word ptr [0x5272]
    if (_ax <= 0x000d)                          //jbe loc_5ec9
        goto loc_5ec9;
loc_5eb4:                                       //loc_5eb4:
    _ax = memory16(_ds, _si + 15);              //mov ax, word ptr [si+0xf]
    memory16(_ds, _si) = _ax;                   //mov word ptr [si], ax
    _ax = memory16(_ds, _si + 17);              //mov ax, word ptr [si+0x11]
    memory16(_ds, _si + 2) = _ax;               //mov word ptr [si+0x2], ax
    sub_64ef();                                 //call sub_64ef
    sub_64ef();                                 //call sub_64ef
    memory(_ds, _si + 14) = 0x00;               //mov byte ptr [si+0xe], 0x0
loc_5ec9:                                       //loc_5ec9:
    return;
}



void sub_47fa()
{
    _bp = 0x0040;                               //mov bp, 0x40
    sub_4b7d();                                 //call sub_4b7d
    sub_4c12();                                 //call sub_4c12
    sub_4c2a();                                 //call sub_4c2a
}

void sub_47b7()
{
    sub_4c12();                                 //call sub_4c12
    sub_4c2a();                                 //call sub_4c2a
    sub_4be8();                                 //call sub_4be8
    if (memory16(_ds, 25886) != 0x000f)         //jnz loc_47d2
        goto loc_47d2;
    memory(_ds, 25872) = 0x06;                  //mov byte ptr [0x6510], 0x6
    memory16(_ds, 21130) = 0x0000;              //mov word ptr [0x528a], 0x0
loc_47d2:                                       //loc_47d2:
    return;
}

void sub_4df9()
{
    sub_4ca2();                                 //call sub_4ca2
}

void sub_5095()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_dx);                                 //push dx
    _ax = memory16(_ds, _si);                   //mov ax, word ptr [si]
    _ax = _ax - memory16(_ds, _di);             //sub ax, word ptr [di]
    if ((short)_ax >= 0)                        //jns loc_50a0
        goto loc_50a0;
    _ax = -_ax;                                 //neg ax
loc_50a0:                                       //loc_50a0:
    if (_ax >= 0x0040)                          //jnc loc_511d
        goto loc_511d;
    _ax = memory16(_ds, _si + 2);               //mov ax, word ptr [si+0x2]
    _ax = _ax - memory16(_ds, _di + 2);         //sub ax, word ptr [di+0x2]
    if ((short)_ax >= 0)                        //jns loc_50af
        goto loc_50af;
    _ax = -_ax;                                 //neg ax
loc_50af:                                       //loc_50af:
    if (_ax >= 0x0046)                          //jnc loc_511d
        goto loc_511d;
    _ax = memory16(_ds, _si + 2);               //mov ax, word ptr [si+0x2]
    _dx = memory16(_ds, _di + 2);               //mov dx, word ptr [di+0x2]
    _bx = memory16(_ds, _si + 4);               //mov bx, word ptr [si+0x4]
    if ((short)_ax >= (short)_dx)               //jge loc_50c5
        goto loc_50c5;
    _xchg(_ax, _dx);                            //xchg ax, dx
    _bx = memory16(_ds, _di + 4);               //mov bx, word ptr [di+0x4]
loc_50c5:                                       //loc_50c5:
    _bh &= 0x1f;                                //and bh, 0x1f
    _bx <<= 1;                                  //shl bx, 1
    _bl = memory(_ds, _bx + 27640);             //mov bl, byte ptr [bx+0x6bf8]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bx -= 0x0003;                              //sub bx, 0x3
    _ax -= _bx;                                 //sub ax, bx
    if ((short)_ax >= (short)_dx)               //jge loc_511d
        goto loc_511d;
    _bx = memory16(_ds, _si + 4);               //mov bx, word ptr [si+0x4]
    _bh &= 0x1f;                                //and bh, 0x1f
    _bx <<= 1;                                  //shl bx, 1
    _bp = _bx;                                  //mov bp, bx
    _al = memory(_ds, _bx + 26927);             //mov al, byte ptr [bx+0x692f]
    _ah = _ah ^ _ah;                            //xor ah, ah
    _dx = memory16(_ds, _si);                   //mov dx, word ptr [si]
    _dx -= _ax;                                 //sub dx, ax
    _bx = memory16(_ds, _di + 4);               //mov bx, word ptr [di+0x4]
    _bh &= 0x1f;                                //and bh, 0x1f
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _di);                   //mov ax, word ptr [di]
    _flags.carry = _al < memory(_ds, _bx + 26927);//sub al, byte ptr [bx+0x692f]
    _al = _al - memory(_ds, _bx + 26927);
    _ah -= 0x00 + _flags.carry;                 //sbb ah, 0x0
    _bl = memory(_ds, _bx + 27639);             //mov bl, byte ptr [bx+0x6bf7]
    _bl >>= 1;                                  //shr bl, 1
    if ((short)_ax < (short)_dx)                //jl loc_5110
        goto loc_5110;
    _xchg(_ax, _dx);                            //xchg ax, dx
    _bl = memory(_ds, _bp + 27639);             //mov bl, byte ptr ds:[bp+0x6bf7]
    _bl >>= 1;                                  //shr bl, 1
loc_5110:                                       //loc_5110:
    _bh = _bh ^ _bh;                            //xor bh, bh
    _ax += _bx;                                 //add ax, bx
    if ((short)_ax <= (short)_dx)               //jle loc_511d
        goto loc_511d;
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    _flags.carry = true;                        //stc
    return;                                     //ret
loc_511d:                                       //loc_511d:
    _dx = _pop();                               //pop dx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    _flags.carry = false;                       //clc
}

void sub_11e6();
void sub_59cc();
void sub_4ae9();                    
void sub_596f()
{
    _push(_ax);                                 //push ax
    _al = 0x04;                                 //mov al, 0x4
    sub_11e6();                                 //call sub_11e6
    _ax = _pop();                               //pop ax
    sub_59cc();                                 //call sub_59cc
    sub_59cc();                                 //call sub_59cc
    memory(_ds, 25876) = 0x18;                  //mov byte ptr [0x6514], 0x18
    memory(_ds, 25875) = 0x00;                  //mov byte ptr [0x6513], 0x0
    memory(_ds, 21127) = 0x00;                  //mov byte ptr [0x5287], 0x0
    if ((short)memory16(_ds, 21116) > (short)_ax)//jg loc_5993
        goto loc_5993;
    _bp = -_bp;                                 //neg bp
loc_5993:                                       //loc_5993:
    memory16(_ds, 21122) = _bp;                 //mov word ptr [0x5282], bp
    memory16(_ds, 21130) = 0xff80;              //mov word ptr [0x528a], 0xff80
    sub_4ae9();                                 //call sub_4ae9
}


void sub_5a04()
{
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    _si = 0x527c;                               //mov si, 0x527c
    sub_5095();                                 //call sub_5095
    if (!_flags.carry)                          //jnc loc_5a40
        goto loc_5a40;
    _bx = memory16(_ds, _di + 9);               //mov bx, word ptr [di+0x9]
    if (memory(_ds, _bx + 6) == 0x0b)           //jz loc_5a2c
        goto loc_5a2c;
    _ax = memory16(_ds, _bx + 4);               //mov ax, word ptr [bx+0x4]
    _ah &= 0x1f;                                //and ah, 0x1f
    if (_ax == 0x00b2)                          //jz loc_5a2c
        goto loc_5a2c;
    memory16(_ds, _bx + 8) = -memory16(_ds, _bx + 8);//neg word ptr [bx+0x8]
loc_5a2c:                                       //loc_5a2c:
    _ax = memory16(_ds, _di + 4);               //mov ax, word ptr [di+0x4]
    _ah &= 0x1f;                                //and ah, 0x1f
    _ax -= 0x009a;                              //sub ax, 0x9a
    if (_ax > 0x0002)                           //ja loc_5a3f
        goto loc_5a3f;
    memory(_ds, 25857) = 0x01;                  //mov byte ptr [0x6501], 0x1
loc_5a3f:                                       //loc_5a3f:
    _flags.carry = true;                        //stc
loc_5a40:                                       //loc_5a40:
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    if (!_flags.carry)                                //jnc loc_5a57
        goto loc_5a57;
    _bp = memory16(_ds, _si + 12);              //mov bp, word ptr [si+0xc]
    _bp |= _bp;                                 //or bp, bp
    if (_bp == 0)                               //jz loc_5a57
        goto loc_5a57;
    _ax = memory16(_ds, _si);                   //mov ax, word ptr [si]
    sub_596f();                                 //call sub_596f
loc_5a57:                                       //loc_5a57:
    return;                                     //ret
loc_5a58:                                       //loc_5a58:
    if (_al & 0x40)                             //jnz loc_5a98
        goto loc_5a98;
    memory(_ds, _si + 7) |= 0x40;               //or byte ptr [si+0x7], 0x40
    _bx = memory16(_ds, _si + 4);               //mov bx, word ptr [si+0x4]
    _bh &= 0x1f;                                //and bh, 0x1f
    _bl = memory(_ds, _bx + 28639);             //mov bl, byte ptr [bx+0x6fdf]
    _bl &= 0xf0;                                //and bl, 0xf0
    if (_bl == 0xf0)                            //jz loc_5a8f
        goto loc_5a8f;
    _cl = 0x03;                                 //mov cl, 0x3
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bx >>= _cl;                                //shr bx, cl
    _ah = memory(_ds, _si + 5);                 //mov ah, byte ptr [si+0x5]
    _ax &= 0x8000;                              //and ax, 0x8000
    _ax = _ax | memory16(_ds, _bx + 28627);     //or ax, word ptr [bx+0x6fd3]
    memory16(_ds, _si + 4) = _ax;               //mov word ptr [si+0x4], ax
    memory16(_ds, _si + 8) = 0x0000;            //mov word ptr [si+0x8], 0x0
    memory(_ds, _si + 14) = 0xff;               //mov byte ptr [si+0xe], 0xff
    return;                                     //ret
loc_5a8f:                                       //loc_5a8f:
    memory16(_ds, _si + 8) = 0xfff6;            //mov word ptr [si+0x8], 0xfff6
    memory(_ds, _si + 14) = 0x00;               //mov byte ptr [si+0xe], 0x0
loc_5a98:                                       //loc_5a98:
    if (memory(_ds, _si + 14) == 0xff)          //jz loc_5ab7
        goto loc_5ab7;
    _ax = memory16(_ds, _si + 8);               //mov ax, word ptr [si+0x8]
    memory16(_ds, _si + 2) += _ax;              //add word ptr [si+0x2], ax
    if (memory(_ds, 25877) == 0x00)             //jz loc_5aaf
        goto loc_5aaf;
    memory16(_ds, 21136) += _ax;                //add word ptr [0x5290], ax
loc_5aaf:                                       //loc_5aaf:
    if ((short)_ax >= (short)0x0014)            //jge loc_5ab7
        goto loc_5ab7;
    memory16(_ds, _si + 8) += 1;                //inc word ptr [si+0x8]
loc_5ab7:                                       //loc_5ab7:
    return;
}

void sub_47d3()
{
    sub_4c12();                                 //call sub_4c12
    sub_4c2a();                                 //call sub_4c2a
    _bp = 0x0020;                               //mov bp, 0x20
    sub_4b7d();                                 //call sub_4b7d
    _ax = memory16(_ds, 0x5282);                //mov ax, [0x5282]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (!_flags.sign)                           //jns loc_47e8
        goto loc_47e8;
    _ax = -_ax;                                 //neg ax
loc_47e8:                                       //loc_47e8:
    if (_ax >= 0x0020)                          //jnc loc_47f9
        goto loc_47f9;
    _al = 0x06;                                 //mov al, 0x6
    _ah = memory(_ds, 21125);                   //mov ah, byte ptr [0x5285]
    _ah &= 0x80;                                //and ah, 0x80
    memory16(_ds, 0x5280) = _ax;                //mov [0x5280], ax
loc_47f9:                                       //loc_47f9:
    return;
}
  */
