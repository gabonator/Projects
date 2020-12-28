
void sub_135EB()
{
    if (memory16(_ds, 0x9162) != 0)             //jnz short locret_13614
      goto locret_13614;

    _di = 0x9134;                                 //mov di, 9134h
    _si = 0x916a;                                 //mov si, 916Ah
    _cx = 0x0007;                                 //mov cx, 7
loc_135FB:                                        //loc_135FB:
    _ax = memory16(_ds, _di);                     //mov ax, [di]
    memory16(_ds, _si) = _ax;                     //mov [si], ax
    if (!(_ax & _ax))                             //jz short loc_13609
      goto loc_13609;
    _bx = memory16(_ds, _di + 2);                 //mov bx, [di+2]
    _ax = memory16(_ds, _bx + 52);                //mov ax, [bx+34h]
loc_13609:                                        //loc_13609:
    memory16(_ds, _si + 2) = _ax;                 //mov [si+2], ax
    _si += 0x0004;                                //add si, 4
    _di += 0x0004;                                //add di, 4
    if (--_cx)                                    //loop loc_135FB
      goto loc_135FB;
locret_13614:                                     //locret_13614:
      return;
}

/*
void loc_1FE85()
{
    _dx = 0x03ce;                               //mov dx, 3CEh
    _ax = 0x0003;                               //mov ax, 3
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0005;                               //mov ax, 5
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0f07;                               //mov ax, 0F07h
    _out(_dx, _ax);                             //out dx, ax
    _dx = 0x03c4;                               //mov dx, 3C4h
    _ax = 0x0f02;                               //mov ax, 0F02h
    _out(_dx, _ax);                             //out dx, ax
loc_1FE9B:                                      //loc_1FE9B:
    _ax = _pop();                               //pop ax
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
}
*/
void sub_1F909()
{
    _dx = 0x03c4;                               //mov dx, 3C4h
    _al = 0x02;                                 //mov al, 2
    _out(_dx, _ax);                             //out dx, ax
    _dx = 0x03ce;                               //mov dx, 3CEh
    _push(_di);                                 //push di
    _si = _si + memory16(_ds, 0x2);             //add si, ds:2
    _bl = _bh;                                  //mov bl, bh
loc_1F919:                                      //loc_1F919:
    _al = memory(_ds, _si);                     //mov al, [si]
    _al >>= _cl;                                //shr al, cl
    memoryVideoSet(_es, _di, memoryVideoGet(_es, _di) & _al);                    //and es:[di], al
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _ah = memory(_ds, _si);                     //mov ah, [si]
    _ror(_ax, _cl);                             //ror ax, cl
    memoryVideoSet(_es, _di+1, memoryVideoGet(_es, _di+1) & _ah);                //and es:[di+1], ah
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _ah = _ah ^ _ah;                            //xor ah, ah
    _ror(_ax, _cl);                             //ror ax, cl
    memoryVideoSet(_es, _di+2, memoryVideoGet(_es, _di+2) & _ah);                //and es:[di+2], ah
    _di += 0x28;                                //add di, 28h
    _bl -= 1;                                   //dec bl
    if ((char)_bl >= 0)                         //jns short loc_1F919
      goto loc_1F919;
    _di = _pop();                               //pop di
}

void sub_1F585();

void sub_1F970()
{
    _dx = 0x03c4;                               //mov dx, 3C4h
    _al = 0x02;                                 //mov al, 2
    _out(_dx, _ax);                             //out dx, ax
    _dx = 0x03ce;                               //mov dx, 3CEh
    _push(_di);                                 //push di
    _bl = _bh;                                  //mov bl, bh
    _si = _si + memory16(_ds, 0x2);             //add si, ds:2
loc_1F980:                                      //loc_1F980:
    _al = memory(_ds, _si);                     //mov al, [si]
    _al >>= _cl;                                //shr al, cl
    memoryVideoSet(_es, _di, memoryVideoGet(_es, _di) & _al);                    //and es:[di], al
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    _ror(_ax, _cl);                             //ror ax, cl
    memoryVideoSet(_es, _di+1, memoryVideoGet(_es, _di+1) & _ah); //and es:[di+1], ah
    _di += 0x28;                                //add di, 28h
    _bl -= 1;                                   //dec bl
    if ((char)_bl >= 0)                         //jns short loc_1F980
      goto loc_1F980;
    _di = _pop();                               //pop di
}

void loc_1FE85();

void loc_1F93B()
{
loc_1F93B:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _al >>= _cl;                                //shr al, cl
    _out(_dx, _al);                             //out dx, al
    memoryVideoSet(_es, _di, memoryVideoGet(_es, _di) | _al);                    //or es:[di], al
    _ah = memory(_ds, _si - 1);                 //mov ah, [si-1]
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _ror(_ax, _cl);                             //ror ax, cl
    _out(_dx, _al);                             //out dx, al
    memoryVideoSet(_es, _di + 1,  memoryVideoGet(_es, _di + 1) | _al);                //or es:[di+1], al
    _di += 0x28;                                //add di, 28h
    _bl -= 1;                                   //dec bl
    if ((char)_bl >= 0)                         //jns short loc_1F93B
      goto loc_1F93B;
    _di = _pop();                               //pop di
    _dx -= 1;                                   //dec dx
    sub_1FE70();                                //call sub_1FE70
    _ah = 0x01;                                 //mov ah, 1
    sub_1F970();                                //call sub_1F970
    _ah = 0x02;                                 //mov ah, 2
    sub_1F970();                                //call sub_1F970
    _ah = 0x04;                                 //mov ah, 4
    sub_1F970();                                //call sub_1F970
    _ah = 0x08;                                 //mov ah, 8
    sub_1F970();                                //call sub_1F970
    loc_1FE85();                             //jmp loc_1FE85
    return;
}

void loc_1FE85()
{
    _dx = 0x03ce;                               //mov dx, 3CEh
    _ax = 0x0003;                               //mov ax, 3
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0005;                               //mov ax, 5
    _out(_dx, _ax);                             //out dx, ax
    _ax = 0x0f07;                               //mov ax, 0F07h
    _out(_dx, _ax);                             //out dx, ax
    _dx = 0x03c4;                               //mov dx, 3C4h
    _ax = 0x0f02;                               //mov ax, 0F02h
    _out(_dx, _ax);                             //out dx, ax
loc_1FE9B:                                      //loc_1FE9B:
    _ax = _pop();                               //pop ax
    _ds = _ax;                                  //mov ds, ax
    _es = _ax;                                  //mov es, ax
}

void loc_1F8C1()
{
    _bp += _cx;                                 //add bp, cx
    if ((short)_bp <= (short)0x10)              //jle short loc_1F93B
    {loc_1F93B(); return;
        
    }
loc_1F8C8:                                      //loc_1F8C8:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _al >>= _cl;                                //shr al, cl
    _out(_dx, _al);                             //out dx, al
    memoryVideoSet(_es, _di, memoryVideoGet(_es, _di) | _al);                    //or es:[di], al
    _ah = memory(_ds, _si - 1);                 //mov ah, [si-1]
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _ror(_ax, _cl);                             //ror ax, cl
    _out(_dx, _al);                             //out dx, al
    memoryVideoSet(_es, _di+1, memoryVideoGet(_es, _di+1) | _al);                //or es:[di+1], al
    _ah = memory(_ds, _si - 1);                 //mov ah, [si-1]
    _al = _al ^ _al;                            //xor al, al
    _ror(_ax, _cl);                             //ror ax, cl
    _out(_dx, _al);                             //out dx, al
    memoryVideoSet(_es, _di+2, memoryVideoGet(_es, _di+2) | _al);                //or es:[di+2], al
    _di += 0x28;                                //add di, 28h
    _bl -= 1;                                   //dec bl
    if ((char)_bl >= 0)                         //jns short loc_1F8C8
      goto loc_1F8C8;
    _di = _pop();                               //pop di
    _dx -= 1;                                   //dec dx
    sub_1FE70();                                //call sub_1FE70
    _ah = 0x01;                                 //mov ah, 1
    sub_1F909();                                //call sub_1F909
    _ah = 0x02;                                 //mov ah, 2
    sub_1F909();                                //call sub_1F909
    _ah = 0x04;                                 //mov ah, 4
    sub_1F909();                                //call sub_1F909
    _ah = 0x08;                                 //mov ah, 8
    sub_1F909();                                //call sub_1F909
    //goto loc_1FE85;                             //jmp loc_1FE85
    loc_1FE85();
}

void sub_1F585()
{
    _ASSERT(_ds == 0x2853);
    _ax = 0x449b;                               //mov ax, 449Bh
    if (!(_si & 0x0001))                        //jz short loc_1F592
      goto loc_1F592;
    _si -= 1;                                   //dec si
    _ax = 0x5489;                               //mov ax, 5489h
loc_1F592:                                      //loc_1F592:
    _di = memory16(_ds, 0x425B);                //mov di, word_2C78B
    _push(_ds);                                 //push ds
    _ds = _ax;                                  //mov ds, ax
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    _cx -= _ax;                                 //sub cx, ax
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    _dx -= _ax;                                 //sub dx, ax
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    _bp = _ax;                                  //mov bp, ax
    _lodsw<MemAuto, DirAuto>();                 //lodsw
    _bx = _ax;                                  //mov bx, ax
    if ((short)_cx < (short)0x0140)             //jl short loc_1F5AE
      goto loc_1F5AE;
    goto loc_1FE9B;                             //jmp loc_1FE9B
loc_1F5AE:                                      //loc_1F5AE:
    //_ASSERT(0);
    if ((short)_dx < (short)memory16(_ss, 0x10))                    //jl short loc_1F5B8
      goto loc_1F5B8;
    goto loc_1FE9B;                             //jmp loc_1FE9B
loc_1F5B8:                                      //loc_1F5B8:
    _ax = _cx;                                  //mov ax, cx
    _ax += _bp;                                 //add ax, bp
    if ((short)_ax > 0 /*CHECK*/)                //jg short loc_1F5C1
      goto loc_1F5C1;
    goto loc_1FE9B;                             //jmp loc_1FE9B
loc_1F5C1:                                      //loc_1F5C1:
    _ax = _dx;                                  //mov ax, dx
    _flags.sign = (short)(_ax + _bx) < 0;       //add ax, bx
    _ax += _bx;
    if (!_flags.sign)                           //jns short loc_1F5CA
      goto loc_1F5CA;
    goto loc_1FE9B;                             //jmp loc_1FE9B
loc_1F5CA:                                      //loc_1F5CA:
    memory16(_ds, 0x0) = 0;                     //mov word ptr unk_54890, 0
    memory16(_ds, 0x2) = 0;                     //mov word ptr ds:2, 0
    if ((short)_ax <= (short)memory16(_ss, 0x10))                   //jle short loc_1F5E7
      goto loc_1F5E7;
    _ax -= memory16(_ss, 0x10);                             //sub ax, ss:10h
    _bx -= _ax;                                 //sub bx, ax
    memory16(_ds, 0x2) = _ax;                   //mov ds:2, ax
loc_1F5E7:                                      //loc_1F5E7:
    if ((short)_dx >= 0)                        //jns short loc_1F5F9
      goto loc_1F5F9;
    _bx += _dx;                                 //add bx, dx
    _dx = -_dx;                                 //neg dx
    memory16(_ds, 0x0) = _dx;                   //mov word ptr unk_54890, dx
    memory16(_ds, 0x2) = _dx;                   //mov ds:2, dx
    _dx = _dx ^ _dx;                            //xor dx, dx
loc_1F5F9:                                      //loc_1F5F9:
    if ((short)_bp <= (short)0x0008)            //jle short loc_1F63F
      goto loc_1F63F;
    _ax = memory16(_ds, 0x0);                   //mov ax, word ptr unk_54890
    _ax = _ax | memory16(_ds, 0x2);             //or ax, ds:2
    if (_ax == 0)                               //jz short loc_1F63F
      goto loc_1F63F;
    if ((short)_bp > (short)0x10)               //jg short loc_1F616
      goto loc_1F616;
    memory16(_ds, 0x0) <<= 1;                   //shl word ptr unk_54890, 1
    memory16(_ds, 0x2) <<= 1;                   //shl word ptr ds:2, 1
    goto loc_1F63F;                             //jmp short loc_1F63F
loc_1F616:                                      //loc_1F616:
    if ((short)_bp > (short)0x18)               //jg short loc_1F62F
      goto loc_1F62F;
    _ax = memory16(_ds, 0x0);                   //mov ax, word ptr unk_54890
    _ax <<= 1;                                  //shl ax, 1
    memory16(_ds, 0x0) += _ax;                  //add word ptr unk_54890, ax
    _ax = memory16(_ds, 0x2);                   //mov ax, ds:2
    _ax <<= 1;                                  //shl ax, 1
    memory16(_ds, 0x2) += _ax;                  //add ds:2, ax
    goto loc_1F63F;                             //jmp short loc_1F63F
loc_1F62F:                                      //loc_1F62F:
    memory16(_ds, 0x0) <<= 1;                   //shl word ptr unk_54890, 1
    memory16(_ds, 0x0) <<= 1;                   //shl word ptr unk_54890, 1
    memory16(_ds, 0x2) <<= 1;                   //shl word ptr ds:2, 1
    memory16(_ds, 0x2) <<= 1;                   //shl word ptr ds:2, 1
loc_1F63F:                                      //loc_1F63F:
    _ax = 0x28;                                 //mov ax, 28h
    _ax = _dx * _al;                            //mul dx
    _di += _ax;                                 //add di, ax
    if ((short)_cx >= 0)                        //jns short loc_1F64D
      goto loc_1F64D;
    goto loc_1FA46;                             //jmp loc_1FA46
loc_1F64D:                                      //loc_1F64D:
    _ax = _cx;                                  //mov ax, cx
    _ax += _bp;                                 //add ax, bp
    if ((short)_ax <= (short)0x0140)            //jle short loc_1F659
      goto loc_1F659;
    goto loc_1FC5C;                             //jmp loc_1FC5C
loc_1F659:                                      //loc_1F659:

    _dx = _cx;                                  //mov dx, cx
    _dx >>= 1;                                  //shr dx, 1
    _dx >>= 1;                                  //shr dx, 1
    _dx >>= 1;                                  //shr dx, 1
    _di += _dx;                                 //add di, dx
    _cx &= 0x0007;                              //and cx, 7
    _ax = 0xa000;                               //mov ax, 0A000h
    _es = _ax;                                  //mov es, ax
    _dx = 0x03ce;                               //mov dx, 3CEh
    _ax = 0x0f01;                               //mov ax, 0F01h
    _out(_dx, _ax);                             //out dx, ax
    _push(_di);                                 //push di
    _bh = _bl;                                  //mov bh, bl
    _al = 0x08;                                 //mov al, 8
    _out(_dx, _al);                             //out dx, al
    _dx += 1;                                   //inc dx
    _ch = _ch ^ _ch;                            //xor ch, ch
    std::cout << "WTF?\n";
    _si = _si + memory16(_ds, 0x0);             //add si, word ptr unk_54890
    if ((short)_bp > (short)0x0008)             //jg short loc_1F687
      goto loc_1F687;
    goto loc_1F997;                             //jmp loc_1F997
loc_1F687:                                      //loc_1F687:
    if ((short)_bp > (short)0x10)               //jg short loc_1F68F
      goto loc_1F68F;
    goto loc_1F8C1;                             //jmp loc_1F8C1
loc_1F68F:                                      //loc_1F68F:
    if ((short)_bp > (short)0x18)               //jg short loc_1F697
      goto loc_1F697;
    goto loc_1F7C0;                             //jmp loc_1F7C0
loc_1F697:                                      //loc_1F697:
    _bp += _cx;                                 //add bp, cx
    if ((short)_bp > (short)0x20)               //jg short loc_1F6A1
      goto loc_1F6A1;
    goto loc_1F73C;                             //jmp loc_1F73C
loc_1F6A1:                                      //loc_1F6A1:
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _al >>= _cl;                                //shr al, cl
    _out(_dx, _al);                             //out dx, al
    memoryVideoSet(_es, _di, memoryVideoGet(_es, _di) | _al);                    //or es:[di], al
    _ah = memory(_ds, _si - 1);                 //mov ah, [si-1]
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _ror(_ax, _cl);                             //ror ax, cl
    _out(_dx, _al);                             //out dx, al
    memoryVideoSet(_es, _di + 1, memoryVideoGet(_es, _di + 1) | _al);                //or es:[di+1], al
    _ah = memory(_ds, _si - 1);                 //mov ah, [si-1]
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _ror(_ax, _cl);                             //ror ax, cl
    _out(_dx, _al);                             //out dx, al
    memoryVideoSet(_es, _di + 2, memoryVideoGet(_es, _di + 2) | _al);                //or es:[di+1], al
    _ah = memory(_ds, _si - 1);                 //mov ah, [si-1]
    _lodsb<MemAuto, DirAuto>();                 //lodsb
    _ror(_ax, _cl);                             //ror ax, cl
    _out(_dx, _al);                             //out dx, al
    memoryVideoSet(_es, _di + 3, memoryVideoGet(_es, _di + 3) | _al);                //or es:[di+1], al
    _ah = memory(_ds, _si - 1);                 //mov ah, [si-1]
    _al = _al ^ _al;                            //xor al, al
    _ror(_ax, _cl);                             //ror ax, cl
    _out(_dx, _al);                             //out dx, al
    memoryVideoSet(_es, _di + 4, memoryVideoGet(_es, _di + 4) | _al);                //or es:[di+1], al
    _di += 0x28;                                //add di, 28h
    _bl -= 1;                                   //dec bl
    if ((char)_bl >= 0)                         //jns short loc_1F6A1
      goto loc_1F6A1;
    _di = _pop();                               //pop di
    _dx -= 1;                                   //dec dx
    //_ASSERT(_ds == 0x2853);
    sub_1FE70();                                //call sub_1FE70
    _ah = 0x01;                                 //mov ah, 1
    sub_1F6F8();                                //call sub_1F6F8
    _ah = 0x02;                                 //mov ah, 2
    sub_1F6F8();                                //call sub_1F6F8
    _ah = 0x04;                                 //mov ah, 4
    sub_1F6F8();                                //call sub_1F6F8
    _ah = 0x08;                                 //mov ah, 8
    sub_1F6F8();                                //call sub_1F6F8
    goto loc_1FE85;                             //jmp loc_1FE85

loc_1FE9B:
    _ax = _pop();
    _ds = _ax;
    _es = _ax;
    _ASSERT(_ds == 0x2853);
    return;

loc_1FE85:
    loc_1FE85();
    _ASSERT(_ds == 0x2853);
    return;
loc_1F997:    _ASSERT(0);
loc_1FA46:    _ASSERT(0);
loc_1F8C1:
    //_ASSERT(_ds == 0x2853);
    loc_1F8C1();
    _ASSERT(_ds == 0x2853);
    return;
loc_1F73C:    _ASSERT(0);
loc_1FC5C:    _ASSERT(0);
loc_1F7C0:    _ASSERT(0);

}

void sub_13360()
{
    _bx = 0x3377;
    sub_13389();
    _ax =  memory16(_ds, _si+0x42);
    memory16(_ds, _si+0x22) = _ax;
    memory16(_ds, _si+0x42) = 3;
    memory16(_ds, _si+0x36) = 0;
}

void sub_17132()
{
    _bx = 0x62f1;
    sub_13389();
}

void sub_17138()
{
    _bx = 0x6313;
    sub_13389();
}

void sub_16F7F()
{
    _ASSERT(0);
    std::cout << "Implement sub_16F7F()\n";
}

void sub_16F00()
{
    _ASSERT(0);
    std::cout << "Implement sub_16F00()\n";
}

void sub_16FE0()
{
    _ASSERT(0);
    std::cout << "Implement sub_16FE0()\n";
}

void sub_1705B()
{
    _ASSERT(0);
    std::cout << "Implement sub_1705B.()\n";
}

void sub_135CE()
{
    _ax = memory16(_ds, _si+8);
    memory16(_ds, 0x91A2) = _ax;
    _ax = memory16(_ds, _si+0xa);
    memory16(_ds, 0x91A4) = _ax;
    _ax = memory16(_ds, _si);
    memory16(_ds, 0x91A6) = _ax;                  //mov word_316D6, ax
    _ax = memory16(_ds, 0x915A);                  //mov ax, word_3168A
    memory16(_ds, 0x9166) = _ax;                  //mov word_31696, ax
    _ax = memory16(_ds, 0x915C);                  //mov ax, word_3168C
    memory16(_ds, 0x9168) = _ax;                  //mov word_31698, ax
}

void sub_10761()
{
    return;
}
