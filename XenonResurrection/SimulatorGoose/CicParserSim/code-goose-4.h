void sub_120A0();
void sub_109B5();
void sub_12311();
void sub_122F9();
void sub_125E3();

void sub_12CC7();
void sub_12CEA();
void sub_1268A();
void sub_1269E();
void sub_122C1();

void sub_120A0()
{
    _al = memory(_ds, _di);                       //mov al, [di]
    memory(_ds, _si) = _al;                       //mov [si], al
    _al = memory(_ds, _di + 2);                   //mov al, [di+2]
    memory(_ds, _si + 2) = _al;                   //mov [si+2], al
    _al = memory(_ds, _di + 22);                  //mov al, [di+16h]
    memory(_ds, _si + 22) = _al;                  //mov [si+16h], al
    _al = memory(_ds, _di + 4);                   //mov al, [di+4]
    memory(_ds, _si + 4) = _al;                   //mov [si+4], al
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

void sub_109B5()
{
    _push(_bp);                                   //push bp
    _bp = _sp;                                    //mov bp, sp
    _si = stack16(_bp, 8);                        //mov si, [bp+arg_4]
    sub_10A1B();                                  //call sub_10A1B
    _bx = stack16(_bp, 6);                        //mov bx, [bp+arg_2]
    _bx <<= 1;                                    //shl bx, 1
    _cx = memory16(_ds, _bx + 3307);              //mov cx, [bx+0CEBh]
    _bx = stack16(_bp, 4);                        //mov bx, [bp+arg_0]
    _bx <<= 1;                                    //shl bx, 1
    _al = memory(_ds, 0x9502);                    //mov al, byte_1CF52
    if (_al != 0x01)                              //jnz short loc_109D9
      goto loc_109D9;
    _bx += 0x80;                                  //add bx, 80h
    goto loc_109E1;                               //jmp short loc_109E1
loc_109D9:                                        //loc_109D9:
    if (_al != 0x02)                              //jnz short loc_109E1
      goto loc_109E1;
    _bx += 0x0100;                                //add bx, 100h
loc_109E1:                                        //loc_109E1:
    memory16(_ds, _bx + -27991) &= _cx;           //and [bx-6D57h], cx
    _bp = _pop();                                 //pop bp
    _stackReduce(6);                              //retn 6
    return;
}


void sub_125E3()
{
    _push(_bp);                                   //push bp
    _bp = _sp;                                    //mov bp, sp
    _ax = 0xa000;                                 //mov ax, 0A000h
    _es = _ax;                                    //mov es, ax
    _ax = stack16(_bp, 6);                        //mov ax, [bp+arg_2]
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax >>= 1;                                    //shr ax, 1
    _ax = _ax + stack16(_bp, 4);                  //add ax, [bp+arg_0]
    _di = _ax;                                    //mov di, ax
    _dx = 0x03ce;                                 //mov dx, 3CEh
    _ax = 0x0805;                                 //mov ax, 805h
    _out(_dx, _ax);                               //out dx, ax
    _cx = stack16(_bp, 6);                        //mov cx, [bp+arg_2]
    _cx &= 0x0007;                                //and cx, 7
    _ah = 0x80;                                   //mov ah, 80h
    _ah >>= _cl;                                  //shr ah, cl
    _al = 0x08;                                   //mov al, 8
    _out(_dx, _ax);                               //out dx, ax
    _bl = _ah;                                    //mov bl, ah
    _ax = 0x1803;                                 //mov ax, 1803h
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0f01;                                 //mov ax, 0F01h
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0700;                                 //mov ax, 700h
    _out(_dx, _ax);                               //out dx, ax
    _cx = 0x0007;                                 //mov cx, 7
loc_1261E:                                        //loc_1261E:
    _al = memoryVideoGet(_es, _di);                       //mov al, es:[di]
    if (_al & _bl)                                //jnz short loc_1262D
      goto loc_1262D;
    memoryVideoSet(_es, _di, _bl);                       //mov es:[di], bl
    memoryVideoSet(_es, _di + 8192, _bl);                //mov es:[di+2000h], bl
loc_1262D:                                        //loc_1262D:
    _di += 0x28;                                  //add di, 28h
    if (--_cx)                                    //loop loc_1261E
      goto loc_1261E;
    _ax = 0x0005;                                 //mov ax, 5
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0xff08;                                 //mov ax, 0FF08h
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0003;                                 //mov ax, 3
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0001;                                 //mov ax, 1
    _out(_dx, _ax);                               //out dx, ax
    _ax = 0x0000;                                 //mov ax, 0
    _out(_dx, _ax);                               //out dx, ax
    _bp = _pop();                                 //pop bp
    _stackReduce(4);                              //retn 4
    return;
}

void sub_12872()
{
    _push(_si);                                   //push si
    _push(_di);                                   //push di
    _al = memory(_ds, _si);                       //mov al, [si]
    _ah = _al;                                    //mov ah, al
    _al <<= 1;                                    //shl al, 1
    _al += _ah;                                   //add al, ah
    _al <<= 1;                                    //shl al, 1
    _ah = 0x00;                                   //mov ah, 0
    _ax += 0x94a9;                                //add ax, 94A9h
    _si = _ax;                                    //mov si, ax
    _al = memory(_ds, _bx);                       //mov al, [bx]
    _ah = _al;                                    //mov ah, al
    _al <<= 1;                                    //shl al, 1
    _al += _ah;                                   //add al, ah
    _al <<= 1;                                    //shl al, 1
    _ah = 0x00;                                   //mov ah, 0
    _ax += 0x94a9;                                //add ax, 94A9h
    _di = _ax;                                    //mov di, ax
    _al = memory(_ds, _di);                       //mov al, [di]
    if (_al > memory(_ds, _si))                   //ja short loc_128D5
      goto loc_128D5;
    if (_al < memory(_ds, _si))                   //jb short loc_128D0
      goto loc_128D0;
    _al = memory(_ds, _di + 1);                   //mov al, [di+1]
    if (_al > memory(_ds, _si + 1))               //ja short loc_128D5
      goto loc_128D5;
    if (_al < memory(_ds, _si + 1))               //jb short loc_128D0
      goto loc_128D0;
    _al = memory(_ds, _di + 2);                   //mov al, [di+2]
    if (_al > memory(_ds, _si + 2))               //ja short loc_128D5
      goto loc_128D5;
    if (_al < memory(_ds, _si + 2))               //jb short loc_128D0
      goto loc_128D0;
    _al = memory(_ds, _di + 3);                   //mov al, [di+3]
    if (_al > memory(_ds, _si + 3))               //ja short loc_128D5
      goto loc_128D5;
    if (_al < memory(_ds, _si + 3))               //jb short loc_128D0
      goto loc_128D0;
    _al = memory(_ds, _di + 4);                   //mov al, [di+4]
    if (_al > memory(_ds, _si + 4))               //ja short loc_128D5
      goto loc_128D5;
    if (_al < memory(_ds, _si + 4))               //jb short loc_128D0
      goto loc_128D0;
    _al = memory(_ds, _di + 5);                   //mov al, [di+5]
    if (_al > memory(_ds, _si + 5))               //ja short loc_128D5
      goto loc_128D5;
    if (_al < memory(_ds, _si + 5))               //jb short $+2
    {
        _ASSERT(0);
     // goto $+2;
    }
loc_128D0:                                        //loc_128D0:
    _al = 0x00;                                   //mov al, 0
    _di = _pop();                                 //pop di
    _si = _pop();                                 //pop si
    return;                                       //retn
loc_128D5:                                        //loc_128D5:
    _al = 0x01;                                   //mov al, 1
    _di = _pop();                                 //pop di
    _si = _pop();                                 //pop si
}

void sub_12CC7()
{
    _bl = _al;                                    //mov bl, al
    _bh = 0x00;                                   //mov bh, 0
    _bx <<= 1;                                    //shl bx, 1
    _ax = memory16(_ds, _bx + 5407);              //mov ax, [bx+151Fh]
    _push(_ax);                                   //push ax
    _ax = memory16(_ds, _bx + 5423);              //mov ax, [bx+152Fh]
    _push(_ax);                                   //push ax
    _ax = memory16(_ds, _bx + 5439);              //mov ax, [bx+153Fh]
    _push(_ax);                                   //push ax
    _ax = memory16(_ds, _bx + 5455);              //mov ax, [bx+154Fh]
    _push(_ax);                                   //push ax
    _ax = memory16(_ds, _bx + 5391);              //mov ax, [bx+150Fh]
    _push(_ax);                                   //push ax
    sub_12CEA();                                  //call sub_12CEA
}


void sub_1268A()
{
    _ax = 0x0002;                                 //mov ax, 2
    _push(_ax);                                   //push ax
    _ax = 0x0005;                                 //mov ax, 5
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    _ax = 0x0000;                                 //mov ax, 0
    _push(_ax);                                   //push ax
    sub_1269E();                                  //call sub_1269E
}

