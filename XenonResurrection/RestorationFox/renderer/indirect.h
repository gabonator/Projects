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
void sub_14e5();
void sub_157c();
void sub_147a();
void sub_147d();
void sub_1585();
void sub_14dd();
void sub_158c();
void sub_1591();

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
        case 0x47fa: sub_47fa(); return; // move
        case 0x4df9: sub_4df9(); return; // jump
        case 0x47b7: sub_47b7(); return; // down
        case 0x47d3: sub_47d3(); return; // down move
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
        case 0x48d6: sub_48d6(); return; // throw item
        case 0x622e: sub_622e(); return;
        case 0x4833: sub_4833(); return; // ladder
        
        case 0x14e5: /*sub_14e5();*/ return; // sound
        case 0x157c: sub_157c(); return; // sound
        case 0x147a: sub_147a(); return; // sound
        case 0x1585: sub_1585(); return; // sound
        case 0x147d: sub_147d(); return; // sound
        case 0x14dd: sub_14dd(); return; // sound
        case 0x158c: sub_158c(); return;
        case 0x1591: sub_1591(); return;
    }
    std::cout << "Ignore indirect " << ofs << "\n";
    //_ASSERT(0);
}


#if 0
void sub_15a7();
void sub_13c2();
void sub_16e5();
void sub_14e9(int pc = 0);
void sub_147d();
void sub_16e5();

// play melody
void sub_12ab(int pc = 0);

void sub_15de()
{
    _ah = memory(_ds, _bx);                     //mov ah, byte ptr [bx]
    _al = _dl;                                  //mov al, dl
    _al += 0x60;                                //add al, 0x60
    sub_15a7();                                 //call sub_15a7
    _ah = memory(_ds, _bx + 1);                 //mov ah, byte ptr [bx+0x1]
    _al = _dl;                                  //mov al, dl
    _al += 0x80;                                //add al, 0x80
    sub_15a7();                                 //call sub_15a7
    _ah = memory(_ds, _bx + 2);                 //mov ah, byte ptr [bx+0x2]
    _al = _dl;                                  //mov al, dl
    _al += 0x40;                                //add al, 0x40
    sub_15a7();                                 //call sub_15a7
    _ah = memory(_ds, _bx + 3);                 //mov ah, byte ptr [bx+0x3]
    _al = _dl;                                  //mov al, dl
    _al += 0x20;                                //add al, 0x20
    sub_15a7();                                 //call sub_15a7
    _ah = memory(_ds, _bx + 4);                 //mov ah, byte ptr [bx+0x4]
    _al = _dl;                                  //mov al, dl
    _al += 0xe0;                                //add al, 0xe0
    sub_15a7();                                 //call sub_15a7
}

void sub_122b()
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
    _ax = 0x168f;                               //mov ax, 0x168f
    _ds = _ax;                                  //mov ds, ax
    _ax = 0x20b6;                               //mov ax, 0x20b6
    sub_15a7();                                 //call sub_15a7
    _flags.interrupt = false;                   //cli
    _bx = 0x0b9a;                               //mov bx, 0xb9a
    _dl = 0x13;                                 //mov dl, 0x13
    sub_15de();                                 //call sub_15de
    _dl -= 0x03;                                //sub dl, 0x3
    _bx += 0x0005;                              //add bx, 0x5
    sub_15de();                                 //call sub_15de
    _ah = memory(_ds, _bx + 5);                 //mov ah, byte ptr [bx+0x5]
    _al = 0xc6;                                 //mov al, 0xc6
    sub_15a7();                                 //call sub_15a7
    memory(_ds, 372) = 0x00;                    //mov byte ptr [0x174], 0x0
    _flags.interrupt = true;                    //sti
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}

void sub_133b()
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
    _ax = 0x168f;                               //mov ax, 0x168f
    _ds = _ax;                                  //mov ds, ax
    if (memory(_ds, 372) == 0x00)               //jz loc_1381
        goto loc_1381;
    _al = 0xbd;                                 //mov al, 0xbd
    _ah = 0xef;                                 //mov ah, 0xef
    _ah = _ah & memory(_ds, 2329);              //and ah, byte ptr [0x919]
    sub_15a7();                                 //call sub_15a7
    _ax = 0x57a6;                               //mov ax, 0x57a6
    sub_15a7();                                 //call sub_15a7
    _ax = 0x01b6;                               //mov ax, 0x1b6
    sub_15a7();                                 //call sub_15a7
    _ax = 0x05b6;                               //mov ax, 0x5b6
    sub_15a7();                                 //call sub_15a7
    _al = 0xbd;                                 //mov al, 0xbd
    _ah = 0x10;                                 //mov ah, 0x10
    _ah = _ah | memory(_ds, 2329);              //or ah, byte ptr [0x919]
    sub_15a7();                                 //call sub_15a7
    memory16(_ds, 370) -= 1;                    //dec word ptr [0x172]
    if (memory16(_ds, 370) != 0)                //jnz loc_1381
        goto loc_1381;
    sub_122b();                                 //call sub_122b
loc_1381:                                       //loc_1381:
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}
void loc_1454();

void sub_12ab(int pc)
{
    if (pc == 0x12e5)
        goto loc_12e5;
    
    _push(_ax);                                 //push ax
    _push(_bx);                                 //push bx
    _push(_cx);                                 //push cx
    _push(_dx);                                 //push dx
    _push(_di);                                 //push di
    _push(_si);                                 //push si
    _push(_ds);                                 //push ds
    _push(_es);                                 //push es
    _push(_bp);                                 //push bp
    _flags.direction = false;                   //cld
    _ax = 0x168f;                               //mov ax, 0x168f
    _ds = _ax;                                  //mov ds, ax
    memory(_ds, 2432) -= 1;                     //dec byte ptr [0x980]
    if (memory(_ds, 2432) != 0)                 //jnz loc_12c8
        goto loc_12c8;
    _al = memory(_ds, 0x981);                   //mov al, [0x981]
    memory(_ds, 0x980) = _al;                   //mov [0x980], al
    goto loc_1331;                              //jmp loc_1331
loc_12c8:                                       //loc_12c8:
    memory16(_ds, 2325) = 0x09b3;               //mov word ptr [0x915], 0x9b3
loc_12ce:                                       //loc_12ce:
    _di = memory16(_ds, 2325);                  //mov di, word ptr [0x915]
    _si = memory16(_ds, _di + 13);              //mov si, word ptr [di+0xd]
    if (_si == 0xffff)                      //jz loc_1331
        goto loc_1331;
    if (_si == 0xfffe)                      //jz loc_1327
        goto loc_1327;
    
    _flags.carry2 = memory(_ds, _di + 7) > 0x01;
    memory(_ds, _di + 7) -= 0x01;               //sub byte ptr [di+0x7], 0x1
    if (_flags.carry2)                                //ja loc_1327
        goto loc_1327;
loc_12e5:                                       //loc_12e5:
    _bh = _bh ^ _bh;                            //xor bh, bh
    _lodsb<MemData, DirForward>();              //lodsb
    if (!(_al & 0x80))                          //jz loc_12ef
        goto loc_12ef;
    loc_1454();                    //jmp loc_1454
    return;
loc_12ef:                                       //loc_12ef:
    _ah = _al;                                  //mov ah, al
    _ah &= 0x0f;                                //and ah, 0xf
    _cl = _ah;                                  //mov cl, ah
    _xchg(memory(_ds, _di + 8), _cl);           //xchg byte ptr [di+0x8], cl
    memory(_ds, _di + 15) = _cl;                //mov byte ptr [di+0xf], cl
    _cl = 0x04;                                 //mov cl, 0x4
    _al >>= _cl;                                //shr al, cl
    memory(_ds, _di + 9) = _al;                 //mov byte ptr [di+0x9], al
    _bl = memory(_ds, _di + 8);                 //mov bl, byte ptr [di+0x8]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _bx + 2406);            //mov ax, word ptr [bx+0x966]
    _cl = memory(_ds, _di + 9);                 //mov cl, byte ptr [di+0x9]
    sub_13c2();                                 //call sub_13c2
    _al = 0x60;                                 //mov al, 0x60
    _cl = memory(_ds, _di);                     //mov cl, byte ptr [di]
    if (_cl != 0x07)                            //jnz loc_1322
        goto loc_1322;
    _al = 0x40;                                 //mov al, 0x40
    _cl = memory(_ds, _di + 3);                 //mov cl, byte ptr [di+0x3]
loc_1322:                                       //loc_1322:
    _al >>= _cl;                                //shr al, cl
    memory(_ds, _di + 7) = _al;                 //mov byte ptr [di+0x7], al
loc_1327:                                       //loc_1327:
    memory16(_ds, _di + 13) = _si;              //mov word ptr [di+0xd], si
    memory16(_ds, 2325) += 0x0011;              //add word ptr [0x915], 0x11 -- move block
    goto loc_12ce;                              //jmp loc_12ce
loc_1331:                                       //loc_1331:
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
}


void sub_0d27()
{
    memory16(_cs, 0xD23) = _ax;                 //mov cs:[0xd23], ax
    memory16(_cs, 0xD25) = _ds;                 //mov word ptr cs:[0xd25], ds
    _ax = 0x168f;                               //mov ax, 0x168f
    _ds = _ax;                                  //mov ds, ax
    _flags.carry = (memory16(_ds, 1084) + 0x0001) >= 0x10000;
    memory16(_ds, 1084) += 0x0001;
    memory16(_ds, 1086) = memory16(_ds, 1086) + 0x0000 + _flags.carry;
    /*
    _push(memory16(_ds, 1077));                 //push word ptr [0x435]
    _push(memory16(_ds, 1075));                 //push word ptr [0x433]
    _ds = memory16(_cs, 0xD25);                 //mov ds, word ptr cs:[0xd25]
    _ax = memory16(_cs, 0xD23);                 //mov ax, cs:[0xd23]
     */
}

void sub_138b() // interrupt
{
    if (memory(_cs, 0x16E4) != 0x03)            //jnz loc_13a6
        goto loc_13a6;
    if (memory(_cs, 0x16E3) == 0x00)            //jz loc_13a3
        goto loc_13a3;
    sub_133b();                                 //call sub_133b
    sub_12ab();                                 //call sub_12ab
    goto loc_13a6;                              //jmp loc_13a6
loc_13a3:                                       //loc_13a3:
    sub_16e5();                                 //call sub_16e5
loc_13a6:                                       //loc_13a6:
    memory16(_cs, 0x16E0) += 1;                 //inc word ptr cs:[0x16e0]
    memory(_cs, 0x16E2) += 1;                   //inc byte ptr cs:[0x16e2]
    memory(_cs, 0x16E2) &= 0x03;                //and byte ptr cs:[0x16e2], 0x3
    if (memory(_cs, 0x16E2) == 0)               //jz loc_13bf
        goto loc_13bf;
    _push(_ax);                                 //push ax
    _al = 0x20;                                 //mov al, 0x20
    _out(32, _al);                              //out 0x20, al
    _ax = _pop();                               //pop ax
    return;                                     //iret
loc_13bf:                                       //loc_13bf:
    //_STOP_("goto loc_0d27");                    //jmp loc_0d27
    sub_0d27();
}




void sub_13c2()
{
    std::cout << "Play block " << _di << "\n";
    _ax |= _ax;                                 //or ax, ax
    if (_ax != 0)                               //jnz loc_13c9
        goto loc_13c9;
    goto loc_144d;                              //jmp loc_144d
loc_13c9:                                       //loc_13c9:
    if (memory(_ds, _di + 6) < 0x0f)            //jc loc_1417
        goto loc_1417;
    _cl += 0x0f;                                //add cl, 0xf
    if (memory(_ds, _di + 6) == _cl)            //jz loc_13e0
        goto loc_13e0;
    sub_14e9();                                 //call sub_14e9
    _al = memory(_ds, _di + 1);                 //mov al, byte ptr [di+0x1]
    sub_147d();                                 //call sub_147d
loc_13e0:                                       //loc_13e0:
    _cl = memory(_ds, _di + 5);                 //mov cl, byte ptr [di+0x5]
    _cl -= 0x06;                                //sub cl, 0x6
    _ah = 0x10;                                 //mov ah, 0x10
    _ah >>= _cl;                                //shr ah, cl
    _ah = (~_ah);                               //not ah
    _ah = _ah & memory(_ds, 2329);              //and ah, byte ptr [0x919]
    _al = 0xbd;                                 //mov al, 0xbd
    sub_15a7();                                 //call sub_15a7
    if (memory(_ds, _di + 5) != 0x06)           //jnz loc_140d
        goto loc_140d;
    _ax = 0x57a6;                               //mov ax, 0x57a6
    sub_15a7();                                 //call sub_15a7
    _ax = 0x00b6;                               //mov ax, 0xb6
    sub_15a7();                                 //call sub_15a7
    _ax = 0x05b6;                               //mov ax, 0x5b6
    sub_15a7();                                 //call sub_15a7
loc_140d:                                       //loc_140d:
    _ah = memory(_ds, 2329);                    //mov ah, byte ptr [0x919]
    _al = 0xbd;                                 //mov al, 0xbd
    sub_15a7();                                 //call sub_15a7
    return;                                     //ret
loc_1417:                                       //loc_1417:
    _cl += 0x02;                                //add cl, 0x2
    _dx = _ax;                                  //mov dx, ax
    _ah = _dl;                                  //mov ah, dl
    _al = memory(_ds, _di + 5);                 //mov al, byte ptr [di+0x5]   tone
    _al += 0xa0;                                //add al, 0xa0                020d:1423
    sub_15a7();                                 //call sub_15a7
    if (memory(_ds, _di + 16) == 0x01)          //jz loc_143a
        goto loc_143a;
    _al = memory(_ds, _di + 5);                 //mov al, byte ptr [di+0x5]
    _al += 0xb0;                                //add al, 0xb0
    _ah = 0x00;                                 //mov ah, 0x0
    sub_15a7();                                 //call sub_15a7                tone
    _dx |= _dx;                                 //or dx, dx
    if (_dx == 0)                               //jz loc_144d
        goto loc_144d;
loc_143a:                                       //loc_143a:
    _ah = _dh;                                  //mov ah, dh
    _cl <<= 1;                                  //shl cl, 1
    _cl <<= 1;                                  //shl cl, 1
    _ah |= _cl;                                 //or ah, cl
    _ah |= 0x20;                                //or ah, 0x20
    _al = memory(_ds, _di + 5);                 //mov al, byte ptr [di+0x5]
    _al += 0xb0;                                //add al, 0xb0
    sub_15a7();                                 //call sub_15a7                 tone
loc_144d:                                       //loc_144d:
    _al = memory(_ds, _di + 4);                 //mov al, byte ptr [di+0x4]
    memory(_ds, _di + 16) = _al;                //mov byte ptr [di+0x10], al
    return;                                     //ret
}
void loc_1454()                                       //loc_1454:
{
    _ah = _al;                                  //mov ah, al
    _al &= 0x0f;                                //and al, 0xf
    _cl = 0x04;                                 //mov cl, 0x4
    _ah &= 0x70;                                //and ah, 0x70
    _ah >>= _cl;                                //shr ah, cl
    if (_ah == 0x07)                            //jz loc_146f
        goto loc_146f;
    _bl = _ah;                                  //mov bl, ah
    _bx <<= 1;                                  //shl bx, 1
    _indirectCall(memory16(_ds, _bx + 2330));   //call word ptr [bx+0x91a]
    sub_12ab(0x12e5);                    //jmp loc_12e5
    return;
loc_146f:                                       //loc_146f:
    _bl = _al;                                  //mov bl, al
    _bx <<= 1;                                  //shl bx, 1
    _indirectCall(memory16(_ds, _bx + 2344));   //call word ptr [bx+0x928]
    sub_12ab(0x12e5);                    //jmp loc_12e5
    return;
}

void sub_14e9(int pc)
{
    if (pc==0x1512)
        goto loc_1512;
    _bl = memory(_ds, _di + 9);                 //mov bl, byte ptr [di+0x9]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bl += 0x0f;                                //add bl, 0xf
    memory(_ds, _di + 6) = _bl;                 //mov byte ptr [di+0x6], bl
    _bx <<= 1;                                  //shl bx, 1
    _bx = _bx + memory16(_ds, 2327);            //add bx, word ptr [0x917]
    _bx = memory16(_ds, _bx);                   //mov bx, word ptr [bx]
    _cl = memory(_ds, _bx);                     //mov cl, byte ptr [bx]
    memory(_ds, _di + 5) = _cl;                 //mov byte ptr [di+0x5], cl
    _ah = 0x10;                                 //mov ah, 0x10
    _cl -= 0x06;                                //sub cl, 0x6
    _ah >>= _cl;                                //shr ah, cl
    _ah = _ah | memory(_ds, 2329);              //or ah, byte ptr [0x919]
    memory(_ds, 2329) = _ah;                    //mov byte ptr [0x919], ah
    goto loc_1534;                              //jmp loc_1534
loc_1512:                                       //loc_1512:
    if (_FIXME_)                                //jc loc_1516
        goto loc_1516;
    _al -= 1;                                   //dec al
loc_1516:                                       //loc_1516:
    memory(_ds, _di + 6) = _al;                 //mov byte ptr [di+0x6], al
    _cl = memory(_ds, _di + 5);                 //mov cl, byte ptr [di+0x5]
    _flags.carry = _cl < 0x06;                  //sub cl, 0x6
    _cl -= 0x06;
    if (_flags.carry)                           //jc loc_1534
        goto loc_1534;
    _ah = 0x10;                                 //mov ah, 0x10
    _ah >>= _cl;                                //shr ah, cl
    _ah = (~_ah);                               //not ah
    _ah = _ah & memory(_ds, 2329);              //and ah, byte ptr [0x919]
    memory(_ds, 2329) = _ah;                    //mov byte ptr [0x919], ah
    _al = 0xbd;                                 //mov al, 0xbd
    sub_15a7();                                 //call sub_15a7
loc_1534:                                       //loc_1534:
    _bl = memory(_ds, _di + 5);                 //mov bl, byte ptr [di+0x5]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bl = memory(_ds, _bx + 2395);              //mov bl, byte ptr [bx+0x95b]
    if (memory(_ds, _di + 5) > 0x06)            //ja loc_1546
        goto loc_1546;
    _bl += 0x03;                                //add bl, 0x3
loc_1546:                                       //loc_1546:
    _dl = memory(_ds, _bx + 2376);              //mov dl, byte ptr [bx+0x948]
    _bl = memory(_ds, _di + 6);                 //mov bl, byte ptr [di+0x6]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bx <<= 1;                                  //shl bx, 1
    _bx = _bx + memory16(_ds, 2327);            //add bx, word ptr [0x917]
    _bx = memory16(_ds, _bx);                   //mov bx, word ptr [bx]
    if (memory(_ds, _di + 6) < 0x0f)            //jc loc_155e
        goto loc_155e;
    _bx += 1;                                   //inc bx
loc_155e:                                       //loc_155e:
    sub_15de();                                 //call sub_15de
    _dl -= 0x03;                                //sub dl, 0x3
    _bx += 0x0005;                              //add bx, 0x5
    if (memory(_ds, _di + 5) >= 0x07)           //jnc loc_157b
        goto loc_157b;
    sub_15de();                                 //call sub_15de
    _ah = memory(_ds, _bx + 5);                 //mov ah, byte ptr [bx+0x5]
    _al = memory(_ds, _di + 5);                 //mov al, byte ptr [di+0x5]
    _al += 0xc0;                                //add al, 0xc0
    sub_15a7();                                 //call sub_15a7
loc_157b:                                       //loc_157b:
    return;
}

void sub_147d()
{
    memory(_ds, _di + 1) = _al;                 //mov byte ptr [di+0x1], al
    _al += 1;                                   //inc al
    _bl = memory(_ds, _di + 6);                 //mov bl, byte ptr [di+0x6]
    _cl = _bl;                                  //mov cl, bl
    _bh = 0x00;                                 //mov bh, 0x0
    _bx <<= 1;                                  //shl bx, 1
    _bx = _bx + memory16(_ds, 2327);            //add bx, word ptr [0x917]
    _bx = memory16(_ds, _bx);                   //mov bx, word ptr [bx]
    if (_cl < 0x0f)                             //jc loc_1497
        goto loc_1497;
    _bx += 1;                                   //inc bx
loc_1497:                                       //loc_1497:
    _cl = _al;                                  //mov cl, al
    _ch = _ch ^ _ch;                            //xor ch, ch
    _ah = memory(_ds, _bx + 2);                 //mov ah, byte ptr [bx+0x2]
    _ah &= 0x3f;                                //and ah, 0x3f
    _ah -= 0x3f;                                //sub ah, 0x3f
    _ah = -_ah;                                 //neg ah
    _al = _al ^ _al;                            //xor al, al
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _ax >>= 1;                                  //shr ax, 1
    _mul(_cx);                                  //mul cx
    _al = 0x3f;                                 //mov al, 0x3f
    _al -= _ah;                                 //sub al, ah
    _bl = memory(_ds, _di + 5);                 //mov bl, byte ptr [di+0x5]
    _bh = 0x00;                                 //mov bh, 0x0
    _bl = memory(_ds, _bx + 2395);              //mov bl, byte ptr [bx+0x95b]
    if (_bl > 0x0d)                             //ja loc_14c7
        goto loc_14c7;
    _bl += 0x03;                                //add bl, 0x3
loc_14c7:                                       //loc_14c7:
    _bl = memory(_ds, _bx + 2376);              //mov bl, byte ptr [bx+0x948]
    _ah = _al;                                  //mov ah, al
    _al = _bl;                                  //mov al, bl
    _al += 0x40;                                //add al, 0x40
    sub_15a7();                                 //call sub_15a7
}

void sub_16e5()
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
    _flags.direction = false;                   //cld
    _ax = 0x168f;                               //mov ax, 0x168f
    _ds = _ax;                                  //mov ds, ax
    _si = memory16(_ds, 2823);                  //mov si, word ptr [0xb07]
    if (_si < 0xfffe)                       //jc loc_1700
        goto loc_1700;
    goto loc_1783;                              //jmp loc_1783
loc_1700:                                       //loc_1700:
    if (!(memory(_cs, 0x16E4) & 0x02))          //jz loc_1783
        goto loc_1783;
    memory(_ds, 2432) -= 1;                     //dec byte ptr [0x980]
    if (memory(_ds, 2432) != 0)                 //jnz loc_1716
        goto loc_1716;
    _al = memory(_ds, 0x981);                   //mov al, [0x981]
    memory(_ds, 0x980) = _al;                   //mov [0x980], al
    goto loc_1783;                              //jmp loc_1783
loc_1716:                                       //loc_1716:
    if (memory(_ds, 2825) != 0x02)              //jnz loc_172f
        goto loc_172f;
    if (memory(_ds, 2835) == 0x01)              //jz loc_172f
        goto loc_172f;
    _ax = 0x3a98;                               //mov ax, 0x3a98
    _out(66, _al);                              //out 0x42, al
    _al = _ah;                                  //mov al, ah
    _out(66, _al);                              //out 0x42, al
    goto loc_172f;                              //jmp loc_172f
loc_172f:                                       //loc_172f:
    memory(_ds, 2825) -= 0x01;                  //sub byte ptr [0xb09], 0x1
    if (_FIXME_)                                //ja loc_1783
        goto loc_1783;
loc_1736:                                       //loc_1736:
    _bh = _bh ^ _bh;                            //xor bh, bh
    _lodsb<MemData, DirForward>();              //lodsb
    if (_al & 0x80)                             //jnz loc_1791
        goto loc_1791;
    _ah = _al;                                  //mov ah, al
    _ah &= 0x0f;                                //and ah, 0xf
    memory(_ds, 2830) = _ah;                    //mov byte ptr [0xb0e], ah
    _cl = 0x04;                                 //mov cl, 0x4
    _al >>= _cl;                                //shr al, cl
    memory(_ds, 0xb0d) = _al;                   //mov [0xb0d], al
    _al = 0x10;                                 //mov al, 0x10
    _cl = memory(_ds, 2831);                    //mov cl, byte ptr [0xb0f]
    _al >>= _cl;                                //shr al, cl
    _bl = memory(_ds, 2830);                    //mov bl, byte ptr [0xb0e]
    _bh = _bh ^ _bh;                            //xor bh, bh
    _bx <<= 1;                                  //shl bx, 1
    _ax = memory16(_ds, _bx + 2848);            //mov ax, word ptr [bx+0xb20]
    _cl = memory(_ds, 2829);                    //mov cl, byte ptr [0xb0d]
    _ax >>= _cl;                                //shr ax, cl
    _out(66, _al);                              //out 0x42, al
    _al = _ah;                                  //mov al, ah
    _out(66, _al);                              //out 0x42, al
    _al = 0x60;                                 //mov al, 0x60
    _cl = memory(_ds, 2831);                    //mov cl, byte ptr [0xb0f]
    if (_cl != 0x07)                            //jnz loc_177e
        goto loc_177e;
    _al = 0x40;                                 //mov al, 0x40
    _cl = memory(_ds, 2834);                    //mov cl, byte ptr [0xb12]
loc_177e:                                       //loc_177e:
    _al >>= _cl;                                //shr al, cl
    memory(_ds, 0xb09) = _al;                   //mov [0xb09], al
loc_1783:                                       //loc_1783:
    memory16(_ds, 2823) = _si;                  //mov word ptr [0xb07], si
    _bp = _pop();                               //pop bp
    _es = _pop();                               //pop es
    _ds = _pop();                               //pop ds
    _si = _pop();                               //pop si
    _di = _pop();                               //pop di
    _dx = _pop();                               //pop dx
    _cx = _pop();                               //pop cx
    _bx = _pop();                               //pop bx
    _ax = _pop();                               //pop ax
    return;                                     //ret
loc_1791:                                       //loc_1791:
    _ah = _al;                                  //mov ah, al
    _al &= 0x0f;                                //and al, 0xf
    _cl = 0x04;                                 //mov cl, 0x4
    _ah &= 0x70;                                //and ah, 0x70
    _ah >>= _cl;                                //shr ah, cl
    if (_ah == 0x07)                            //jz loc_17a9
        goto loc_17a9;
    _bl = _ah;                                  //mov bl, ah
    memory(_ds, _bx + 2831) = _al;              //mov byte ptr [bx+0xb0f], al
    goto loc_1736;                              //jmp loc_1736
loc_17a9:                                       //loc_17a9:
    if (_al == 0x0f)                            //jz loc_17b8
        goto loc_17b8;
    _bl = _al;                                  //mov bl, al
    _bx <<= 1;                                  //shl bx, 1
    _indirectCall(memory16(_ds, _bx + 2838));   //call word ptr [bx+0xb16]
    goto loc_1736;                              //jmp loc_1736
loc_17b8:                                       //loc_17b8:
    _in(_al, 97);                               //in al, 0x61
    _al &= 0xfc;                                //and al, 0xfc
    _out(97, _al);                              //out 0x61, al
    _si = 0xfffe;                               //mov si, 0xfffe
    memory(_ds, 2482) -= 1;                     //dec byte ptr [0x9b2]
    goto loc_1783;                              //jmp loc_1783
}

void sub_14e5()
{
    if (_al != 0x01)                            //jnz loc_1512
    {
        //_STOP_("goto loc_1512");
        sub_14e9(0x1512);
        return;
    }
    sub_14e9();
}


void sub_157c()
{
    _lea(_ax, _ds, _si + 2);                    //lea ax, [si+0x2]
    memory16(_ds, _di + 10) = _ax;              //mov word ptr [di+0xa], ax
    _si = memory16(_ds, _si);                   //mov si, word ptr [si]
}

void sub_147a()
{
    memory(_ds, _di) = _al;                     //mov byte ptr [di], al
}

void sub_1585()
{
    _si = memory16(_ds, _di + 10);              //mov si, word ptr [di+0xa]
}

void sub_14dd()
{
    memory(_ds, _di + 4) = _al;                 //mov byte ptr [di+0x4], al
}

void sub_158c()
{
    _lodsb<MemData, DirForward>();              //lodsb
    memory(_ds, _di + 12) = _al;                //mov byte ptr [di+0xc], al
}

void sub_1591()
{
    memory(_ds, _di + 12) -= 1;                 //dec byte ptr [di+0xc]
    if (memory(_ds, _di + 12) == 0)             //jz loc_1599
        goto loc_1599;
    _si = memory16(_ds, _si);                   //mov si, word ptr [si]
    return;                                     //ret
loc_1599:                                       //loc_1599:
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
}
#endif
