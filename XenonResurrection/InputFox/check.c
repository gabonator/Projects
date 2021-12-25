void sub_1c61() // -- draw sprite
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
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _si = 0x567e;                               //mov si, 0x567e
loc_1c72:                                       //loc_1c72:
    memory16(_ds, 21114) = _si;                 //mov word ptr [0x527a], si
    if (memory16(_ds, _si + 4) != 0xffff)   //jnz loc_1c7f
        goto loc_1c7f;
    goto loc_24a9;                              //jmp loc_24a9
loc_1c7f:                                       //loc_1c7f:
    _ax = _ax ^ _ax;                            //xor ax, ax
    memory(_cs, 0x1C49) = _al;                  //mov cs:[0x1c49], al
    memory(_cs, 0x1C53) = _al;                  //mov cs:[0x1c53], al
    memory(_cs, 0x1C56) = _al;                  //mov cs:[0x1c56], al
    memory(_cs, 0x1C57) = _al;                  //mov cs:[0x1c57], al
    memory16(_cs, 0x1C46) = _ax;                //mov cs:[0x1c46], ax
    memory(_ds, _si + 5) &= 0xdf;               //and byte ptr [si+0x5], 0xdf
    _bx = memory16(_ds, _si + 4);               //mov bx, word ptr [si+0x4]
    _flags.carry = !!(_bx & 0x8000);            //shl bx, 1
    _bx <<= 1;
    _rcl(memory(_cs, 0x1C48), 1);               //rcl byte ptr cs:[0x1c48], 1
    _al = 0x01;                                 //mov al, 0x1
    if (!(_bh & 0x80))                          //jz loc_1caf
        goto loc_1caf;
    _al = 0x41;                                 //mov al, 0x41
    _bh &= 0x7f;                                //and bh, 0x7f
loc_1caf:                                       //loc_1caf:
    memory(_cs, 0x1C5E) = _al;                  //mov cs:[0x1c5e], al
    _dx = memory16(_ds, _bx + 26213);           //mov dx, word ptr [bx+0x6665]
    _al = memory(_ds, _bx + 26927);             //mov al, byte ptr [bx+0x692f]
    if (!(memory(_cs, 0x1C48) & 0x01))          //jz loc_1cc9
        goto loc_1cc9;
    _al = _al - memory(_ds, _bx + 26213);       //sub al, byte ptr [bx+0x6665]
    _al = -_al;                                 //neg al
loc_1cc9:                                       //loc_1cc9:
    _cbw();                                     //cbw
    _ax = -_ax;                                 //neg ax
    _ax = _ax + memory16(_ds, _si);             //add ax, word ptr [si]
    _cx = memory16(_ds, 21104);                 //mov cx, word ptr [0x5270]
    _cx <<= 1;                                  //shl cx, 1
    _cx <<= 1;                                  //shl cx, 1
    _cx <<= 1;                                  //shl cx, 1
    _cx <<= 1;                                  //shl cx, 1
    _ax -= _cx;                                 //sub ax, cx
    _cx = _ax;                                  //mov cx, ax
    memory16(_cs, 0x1C50) = _ax;                //mov cs:[0x1c50], ax
    if ((short)_ax < (short)0x0140)             //jl loc_1cea
        goto loc_1cea;
    goto loc_24a9;                              //jmp loc_24a9
loc_1cea:                                       //loc_1cea:
    _flags.carry = (_cl + _dl) >= 0x100;        //add cl, dl
    _cl += _dl;
    _ch = _ch + 0x00 + _flags.carry;            //adc ch, 0x0
    if ((_ch & 0x80) == 0)                                //jns loc_1cf4
        goto loc_1cf4;
    goto loc_24a9;                              //jmp loc_24a9
loc_1cf4:                                       //loc_1cf4:
    _al = memory(_ds, _bx + 26928);             //mov al, byte ptr [bx+0x6930]
    _cbw();                                     //cbw
    _ax = _ax + memory16(_ds, _si + 2);         //add ax, word ptr [si+0x2]
    _ax += 1;                                   //inc ax
    _cx = memory16(_ds, 21106);                 //mov cx, word ptr [0x5272]
    _cx <<= 1;                                  //shl cx, 1
    _cx <<= 1;                                  //shl cx, 1
    _cx <<= 1;                                  //shl cx, 1
    _cx <<= 1;                                  //shl cx, 1
    _flags.carry2 = (short)_ax > (short)_cx;
    _ax -= _cx;                                 //sub ax, cx
    if (_flags.carry2)                                //jg loc_1d10
        goto loc_1d10;
    goto loc_24a9;                              //jmp loc_24a9
loc_1d10:                                       //loc_1d10:
    memory16(_ds, 0x5278) = _ax;                //mov [0x5278], ax
    memory(_cs, 0x1C52) = _dh;                  //mov byte ptr cs:[0x1c52], dh
    memory(_cs, 0x1C4C) = _dh;                  //mov byte ptr cs:[0x1c4c], dh
    _flags.carry = _al < _dh;                   //sub al, dh
    _al -= _dh;
    _ah -= 0x00 + _flags.carry;                 //sbb ah, 0x0
    if ((short)_ax < (short)0x00c0)             //jl loc_1d2a
        goto loc_1d2a;
    goto loc_24a9;                              //jmp loc_24a9
loc_1d2a:                                       //loc_1d2a:
    memory16(_cs, 0x1C4E) = _ax;                //mov cs:[0x1c4e], ax
    _cl = memory(_cs, 0x0);                     //mov cl, byte ptr cs:[0x0]
    _dl >>= _cl;                                //shr dl, cl
    memory(_cs, 0x1C4A) = _dl;                  //mov byte ptr cs:[0x1c4a], dl
    memory(_cs, 0x1C4B) = _dl;                  //mov byte ptr cs:[0x1c4b], dl
    _dh = _dh ^ _dh;                            //xor dh, dh
    _cx = _cx ^ _cx;                            //xor cx, cx
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (!_flags.sign)                           //jns loc_1d5a
        goto loc_1d5a;
    _ax = -_ax;                                 //neg ax
    memory(_cs, 0x1C52) -= _al;                 //sub byte ptr cs:[0x1c52], al
    _mul(_dl);                                  //mul dl
    _cx = _ax;                                  //mov cx, ax
    memory16(_cs, 0x1C46) = _ax;                //mov cs:[0x1c46], ax
    _di = _di ^ _di;                            //xor di, di
    goto loc_1d60;                              //jmp loc_1d60
loc_1d5a:                                       //loc_1d5a:
    _mul(memory(_ds, 21084));                   //mul byte ptr [0x525c]
    _di = _ax;                                  //mov di, ax
loc_1d60:                                       //loc_1d60:
    _di = _di + memory16(_ds, 21098);           //add di, word ptr [0x526a]
    memory16(_cs, 0x1C58) = _di;                //mov word ptr cs:[0x1c58], di
    _ax = memory16(_ds, _bx + 24004);           //mov ax, word ptr [bx+0x5dc4]
    memory16(_cs, 0x1C5C) = _ax;                //mov cs:[0x1c5c], ax
    _ax = memory16(_ds, _bx + 23204);           //mov ax, word ptr [bx+0x5aa4]
    _ax += _cx;                                 //add ax, cx
    memory16(_cs, 0x1C5A) = _ax;                //mov cs:[0x1c5a], ax
    _ax = memory16(_ds, 0x5278);                //mov ax, [0x5278]
    _flags.carry2 = (short)_ax <= (short)0x00c0;
    _ax -= 0x00c0;                              //sub ax, 0xc0
    if (_flags.carry2)                                //jle loc_1d8f
        goto loc_1d8f;
    memory(_cs, 0x1C52) -= _al;                 //sub byte ptr cs:[0x1c52], al
    _mul(_dl);                                  //mul dl
    memory16(_cs, 0x1C46) += _ax;               //add word ptr cs:[0x1c46], ax
loc_1d8f:                                       //loc_1d8f:
    _ax = memory16(_cs, 0x1C50);                //mov ax, cs:[0x1c50]
    _flags.sign = !!(_ax & 0x8000);             //or ax, ax
    _ax |= _ax;
    if (!_flags.sign)                           //jns loc_1db0
        goto loc_1db0;
    _cl = memory(_cs, 0x0);                     //mov cl, byte ptr cs:[0x0]
    _sar(_ax, _cl);                             //sar ax, cl
    memory(_cs, 0x1C4A) += _al;                 //add byte ptr cs:[0x1c4a], al
    _al = -_al;                                 //neg al
    memory(_cs, 0x1C53) = _al;                  //mov cs:[0x1c53], al
    memory(_cs, 0x1C49) += 1;                   //inc byte ptr cs:[0x1c49]
    goto loc_1de8;                              //jmp loc_1de8
loc_1db0:                                       //loc_1db0:
    _cl = memory(_cs, 0x0);                     //mov cl, byte ptr cs:[0x0]
    _sar(_ax, _cl);                             //sar ax, cl
    memory16(_cs, 0x1C58) += _ax;               //add word ptr cs:[0x1c58], ax
    _ax = memory16(_cs, 0x1C50);                //mov ax, cs:[0x1c50]
    _cl = memory(_cs, 0x0);                     //mov cl, byte ptr cs:[0x0]
    _ax >>= _cl;                                //shr ax, cl
    _flags.carry = (_al + memory(_cs, 0x1C4A)) >= 0x100;
    _al = _al + memory(_cs, 0x1C4A);
    _ah = _ah + 0x00 + _flags.carry;            //adc ah, 0x0
    _flags.carry = _ax < memory16(_ds, 21084);  //sub ax, word ptr [0x525c]
    _ax = _ax - memory16(_ds, 21084);
    if (_flags.carry)                           //jc loc_1de8
        goto loc_1de8;
    memory(_cs, 0x1C4A) -= _al;                 //sub byte ptr cs:[0x1c4a], al
    memory(_cs, 0x1C49) += 1;                   //inc byte ptr cs:[0x1c49]
    memory(_cs, 0x1C56) = _al;                  //mov cs:[0x1c56], al
    memory(_cs, 0x1C57) = (~memory(_cs, 0x1C57));//not byte ptr cs:[0x1c57]
loc_1de8:                                       //loc_1de8:
    memory(_ds, _si + 5) |= 0x20;               //or byte ptr [si+0x5], 0x20
    if (memory(_cs, 0x1) < 0x03)                //jc loc_1df7
        goto loc_1df7;
    goto loc_203a;                              //jmp loc_203a
loc_1df7:                                       //loc_1df7:
    if (memory(_cs, 0x1C5E) == 0x01)            //jz loc_1e02
        goto loc_1e02;
    goto loc_24a9;                              //jmp loc_24a9
loc_1e02:                                       //loc_1e02:
    _al = memory(_cs, 0x1C4B);                  //mov al, cs:[0x1c4b]
    _mul(memory(_cs, 0x1C4C));                  //mul byte ptr cs:[0x1c4c]
    memory16(_cs, 0x1C5F) = _ax;                //mov cs:[0x1c5f], ax
    _es = memory16(_ds, 21090);                 //mov es, word ptr [0x5262]
    _di = memory16(_cs, 0x1C58);                //mov di, word ptr cs:[0x1c58]
    _ds = memory16(_cs, 0x1C5C);                //mov ds, word ptr cs:[0x1c5c]
    _bx = memory16(_cs, 0x1C5F);                //mov bx, word ptr cs:[0x1c5f]
    _si = memory16(_cs, 0x1C5A);                //mov si, word ptr cs:[0x1c5a]
    _dl = memory(_cs, 0x1C52);                  //mov dl, byte ptr cs:[0x1c52]
    if (memory(_cs, 0x1C49) != 0x00)            //jnz loc_1ea3
        goto loc_1ea3;
    if (memory16(_cs, 0x1C50) & 0x0003)         //jnz loc_1ea3
        goto loc_1ea3;
    _dh = memory(_cs, 0x1C4A);                  //mov dh, byte ptr cs:[0x1c4a]
    _ch = _ch ^ _ch;                            //xor ch, ch
    _cl = _dh;                                  //mov cl, dh
    if (memory(_cs, 0x1C48) & 0x01)             //jnz loc_1e6c
        goto loc_1e6c;
    _bp = 0x0050;                               //mov bp, 0x50
    _bp -= _cx;                                 //sub bp, cx
loc_1e53:                                       //loc_1e53:
    _cx >>= 1;                                  //shr cx, 1
loc_1e55:                                       //loc_1e55:
    _ax = memory16(_es, _di);                   //mov ax, word ptr es:[di]
    _ax = _ax & memory16(_ds, _bx + _si);       //and ax, word ptr [bx+si]
    _ax = _ax | memory16(_ds, _si);             //or ax, word ptr [si]
    _stosw<MemData, DirForward>();              //stosw
    _si += 1;                                   //inc si
    _si += 1;                                   //inc si
    if (--_cx)                                  //loop loc_1e55
        goto loc_1e55;
    _cl = _dh;                                  //mov cl, dh
    _di += _bp;                                 //add di, bp
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz loc_1e53
        goto loc_1e53;
    goto loc_24a9;                              //jmp loc_24a9
loc_1e6c:                                       //loc_1e6c:
    _bp = _bx;                                  //mov bp, bx
    _bx = 0x330e;                               //mov bx, 0x330e
    _di += _cx;                                 //add di, cx
    _di -= 1;                                   //dec di
loc_1e74:                                       //loc_1e74:
    _cx >>= 1;                                  //shr cx, 1
loc_1e76:                                       //loc_1e76:
    _ax = memory16(_ds, _bp + _si + 0);         //mov ax, word ptr ds:[bp+si]
    _xlat();                                    //xlat
    memory(_es, _di) &= _al;                    //and byte ptr es:[di], al
    _lodsb<MemData, DirForward>();              //lodsb
    _xlat();                                    //xlat
    memory(_es, _di) |= _al;                    //or byte ptr es:[di], al
    _di -= 1;                                   //dec di
    _al = _ah;                                  //mov al, ah
    _xlat();                                    //xlat
    memory(_es, _di) &= _al;                    //and byte ptr es:[di], al
    _lodsb<MemData, DirForward>();              //lodsb
    _xlat();                                    //xlat
    memory(_es, _di) |= _al;                    //or byte ptr es:[di], al
    _di -= 1;                                   //dec di
    if (--_cx)                                  //loop loc_1e76
        goto loc_1e76;
    _cl = _dh;                                  //mov cl, dh
    _di += _cx;                                 //add di, cx
    _di += 0x0050;                              //add di, 0x50
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz loc_1e74
        goto loc_1e74;
loc_1ea0:                                       //loc_1ea0:
    goto loc_24a9;                              //jmp loc_24a9
loc_1ea3:                                       //loc_1ea3:
    if (memory(_cs, 0x1C4A) == 0x00)            //jz loc_1ea0
        goto loc_1ea0;
    _cl = memory(_cs, 0x1C50);                  //mov cl, byte ptr cs:[0x1c50]
    _cl &= 0x03;                                //and cl, 0x3
    _cl <<= 1;                                  //shl cl, 1
    _ch = 0xff;                                 //mov ch, 0xff
    _ch <<= _cl;                                //shl ch, cl
    if (memory(_cs, 0x1C48) & 0x01)             //jnz loc_1f3e
        goto loc_1f3e;
loc_1ec1:                                       //loc_1ec1:
    _al = memory(_cs, 0x1C4A);                  //mov al, cs:[0x1c4a]
    _cbw();                                     //cbw
    _bp = _ax;                                  //mov bp, ax
    _al = memory(_cs, 0x1C53);                  //mov al, cs:[0x1c53]
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    _ch = (~_ch);                               //not ch
    _dx = 0xff00;                               //mov dx, 0xff00
    _dh &= _ch;                                 //and dh, ch
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz loc_1ee4
        goto loc_1ee4;
    _dh = memory(_ds, _bx + _si + -1);          //mov dh, byte ptr [bx+si-0x1]
    _dh &= _ch;                                 //and dh, ch
    _dl = memory(_ds, _si - 1);                 //mov dl, byte ptr [si-0x1]
    _dl &= _ch;                                 //and dl, ch
loc_1ee4:                                       //loc_1ee4:
    _ch = (~_ch);                               //not ch
loc_1ee6:                                       //loc_1ee6:
    _al = memory(_ds, _bx + _si);               //mov al, byte ptr [bx+si]
    _ah = _al;                                  //mov ah, al
    _al &= _ch;                                 //and al, ch
    _al |= _dh;                                 //or al, dh
    _ror(_al, _cl);                             //ror al, cl
    memory(_es, _di) &= _al;                    //and byte ptr es:[di], al
    _lodsb<MemData, DirForward>();              //lodsb
    _dh = _al;                                  //mov dh, al
    _al &= _ch;                                 //and al, ch
    _al |= _dl;                                 //or al, dl
    _ror(_al, _cl);                             //ror al, cl
    memory(_es, _di) |= _al;                    //or byte ptr es:[di], al
    _ch = (~_ch);                               //not ch
    _dl = _dh;                                  //mov dl, dh
    _dh = _ah;                                  //mov dh, ah
    _dl &= _ch;                                 //and dl, ch
    _dh &= _ch;                                 //and dh, ch
    _ch = (~_ch);                               //not ch
    _di += 1;                                   //inc di
    _bp -= 1;                                   //dec bp
    if (_bp != 0)                               //jnz loc_1ee6
        goto loc_1ee6;
    if (memory(_cs, 0x1C57) != 0x00)            //jnz loc_1f23
        goto loc_1f23;
    _dh |= _ch;                                 //or dh, ch
    _ror(_dh, _cl);                             //ror dh, cl
    _ror(_dl, _cl);                             //ror dl, cl
    memory(_es, _di) &= _dh;                    //and byte ptr es:[di], dh
    memory(_es, _di) |= _dl;                    //or byte ptr es:[di], dl
loc_1f23:                                       //loc_1f23:
    _al = memory(_cs, 0x1C4A);                  //mov al, cs:[0x1c4a]
    _cbw();                                     //cbw
    _di -= _ax;                                 //sub di, ax
    _di += 0x0050;                              //add di, 0x50
    _al = memory(_cs, 0x1C56);                  //mov al, cs:[0x1c56]
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    memory(_cs, 0x1C52) -= 1;                   //dec byte ptr cs:[0x1c52]
    if (memory(_cs, 0x1C52) != 0)               //jnz loc_1ec1
        goto loc_1ec1;
    goto loc_24a9;                              //jmp loc_24a9
loc_1f3e:                                       //loc_1f3e:
    _al = memory(_cs, 0x1C53);                  //mov al, cs:[0x1c53]
    memory(_cs, 0x1C54) = _al;                  //mov cs:[0x1c54], al
    _cl = memory(_cs, 0x1C50);                  //mov cl, byte ptr cs:[0x1c50]
    _cl &= 0x03;                                //and cl, 0x3
    _cl -= 0x04;                                //sub cl, 0x4
    _cl = -_cl;                                 //neg cl
    _cl &= 0x03;                                //and cl, 0x3
    _cl <<= 1;                                  //shl cl, 1
    _ch = 0xff;                                 //mov ch, 0xff
    _ch >>= _cl;                                //shr ch, cl
    _bp = _bx;                                  //mov bp, bx
    _bx = 0x330e;                               //mov bx, 0x330e
    if (memory(_cs, 0x1C53) == 0x00)            //jz loc_1f7d
        goto loc_1f7d;
    _di -= 1;                                   //dec di
    if (!(memory16(_cs, 0x1C50) & 0x0003))      //jz loc_1f7d
        goto loc_1f7d;
    memory(_cs, 0x1C53) -= 1;                   //dec byte ptr cs:[0x1c53]
    memory(_cs, 0x1C4A) += 1;                   //inc byte ptr cs:[0x1c4a]
loc_1f7d:                                       //loc_1f7d:
    if (memory(_cs, 0x1C57) == 0x00)            //jz loc_1f9a
        goto loc_1f9a;
    _di -= 1;                                   //dec di
    if (!(memory16(_cs, 0x1C50) & 0x0003))      //jz loc_1f9a
        goto loc_1f9a;
    _di += 1;                                   //inc di
    memory(_cs, 0x1C4A) -= 1;                   //dec byte ptr cs:[0x1c4a]
    memory(_cs, 0x1C56) += 1;                   //inc byte ptr cs:[0x1c56]
loc_1f9a:                                       //loc_1f9a:
    _al = memory(_cs, 0x1C4A);                  //mov al, cs:[0x1c4a]
    _cbw();                                     //cbw
    _di += _ax;                                 //add di, ax
loc_1fa1:                                       //loc_1fa1:
    _al = memory(_cs, 0x1C4A);                  //mov al, cs:[0x1c4a]
    memory(_cs, 0x1C4D) = _al;                  //mov cs:[0x1c4d], al
    _ch = (~_ch);                               //not ch
    _dx = 0xff00;                               //mov dx, 0xff00
    _dh &= _ch;                                 //and dh, ch
    _ch = (~_ch);                               //not ch
    if (memory(_cs, 0x1C57) == 0x00)            //jz loc_1fd7
        goto loc_1fd7;
    _al = memory(_cs, 0x1C56);                  //mov al, cs:[0x1c56]
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    _al = memory(_ds, _bp + _si + -1);          //mov al, byte ptr ds:[bp+si-0x1]
    _xlat();                                    //xlat
    _dh = _al;                                  //mov dh, al
    _al = memory(_ds, _si - 1);                 //mov al, byte ptr [si-0x1]
    _xlat();                                    //xlat
    _dl = _al;                                  //mov dl, al
    memory(_cs, 0x1C4D) += 1;                   //inc byte ptr cs:[0x1c4d]
    goto loc_1ffa;                              //jmp loc_1ffa
loc_1fd7:                                       //loc_1fd7:
    _al = memory(_ds, _bp + _si + 0);           //mov al, byte ptr ds:[bp+si]
    _xlat();                                    //xlat
    _ah = _al;                                  //mov ah, al
    _al &= _ch;                                 //and al, ch
    _al |= _dh;                                 //or al, dh
    _rol(_al, _cl);                             //rol al, cl
    memory(_es, _di) &= _al;                    //and byte ptr es:[di], al
    _lodsb<MemData, DirForward>();              //lodsb
    _xlat();                                    //xlat
    _dh = _al;                                  //mov dh, al
    _al &= _ch;                                 //and al, ch
    _al |= _dl;                                 //or al, dl
    _rol(_al, _cl);                             //rol al, cl
    memory(_es, _di) |= _al;                    //or byte ptr es:[di], al
    _di -= 1;                                   //dec di
    _dl = _dh;                                  //mov dl, dh
    _dh = _ah;                                  //mov dh, ah
loc_1ffa:                                       //loc_1ffa:
    _ch = (~_ch);                               //not ch
    _dl &= _ch;                                 //and dl, ch
    _dh &= _ch;                                 //and dh, ch
    _ch = (~_ch);                               //not ch
    memory(_cs, 0x1C4D) -= 1;                   //dec byte ptr cs:[0x1c4d]
    if (memory(_cs, 0x1C4D) != 0)               //jnz loc_1fd7
        goto loc_1fd7;
    if (memory(_cs, 0x1C54) != 0x00)            //jnz loc_201d
        goto loc_201d;
    _dh |= _ch;                                 //or dh, ch
    _rol(_dh, _cl);                             //rol dh, cl
    _rol(_dl, _cl);                             //rol dl, cl
    memory(_es, _di) &= _dh;                    //and byte ptr es:[di], dh
    memory(_es, _di) |= _dl;                    //or byte ptr es:[di], dl
loc_201d:                                       //loc_201d:
    _al = memory(_cs, 0x1C4A);                  //mov al, cs:[0x1c4a]
    _cbw();                                     //cbw
    _di += _ax;                                 //add di, ax
    _di += 0x0050;                              //add di, 0x50
    _al = memory(_cs, 0x1C53);                  //mov al, cs:[0x1c53]
    _si += _ax;                                 //add si, ax
    memory(_cs, 0x1C52) -= 1;                   //dec byte ptr cs:[0x1c52]
    if (memory(_cs, 0x1C52) == 0)               //jz loc_2037
        goto loc_2037;
    goto loc_1fa1;                              //jmp loc_1fa1
loc_2037:                                       //loc_2037:
    goto loc_24a9;                              //jmp loc_24a9
loc_203a:                                       //loc_203a:
    sub_32dc();                                 //call sub_32dc
    _dx = 0x03c4;                               //mov dx, 0x3c4
    _ax = 0x0f02;                               //mov ax, 0xf02
    _out(_dx, _ax);                             //out dx, ax
    _cl = memory(_cs, 0x1C50);                  //mov cl, byte ptr cs:[0x1c50]
    _cl &= 0x07;                                //and cl, 0x7
    _ch = 0xff;                                 //mov ch, 0xff
    _ch <<= _cl;                                //shl ch, cl
    _di = memory16(_cs, 0x1C58);                //mov di, word ptr cs:[0x1c58]
    _si = memory16(_cs, 0x1C5A);                //mov si, word ptr cs:[0x1c5a]
    _dl = 0xce;                                 //mov dl, 0xce
    _al = 0x03;                                 //mov al, 0x3
    _ah = _cl;                                  //mov ah, cl
    _ah |= 0x08;                                //or ah, 0x8
    _out(_dx, _ax);                             //out dx, ax
    _bh = _ch;                                  //mov bh, ch
    _bh = (~_bh);                               //not bh
    _dh = memory(_cs, 0x1C4A);                  //mov dh, byte ptr cs:[0x1c4a]
    _cl = _dh;                                  //mov cl, dh
    _al = _cl;                                  //mov al, cl
    _cbw();                                     //cbw
    _ax -= 0x0028;                              //sub ax, 0x28
    _bp = _ax;                                  //mov bp, ax
    _dl = memory(_cs, 0x1C52);                  //mov dl, byte ptr cs:[0x1c52]
    _ds = memory16(_cs, 0x1C5C);                //mov ds, word ptr cs:[0x1c5c]
    _ax = 0xa000;                               //mov ax, 0xa000
    _es = _ax;                                  //mov es, ax
    if (memory(_cs, 0x1C48) & 0x01)             //jnz loc_2091
        goto loc_2091;
    goto loc_22e9;                              //jmp loc_22e9
loc_2091:                                       //loc_2091:
    memory(_cs, 0x1C4C) = _dl;                  //mov byte ptr cs:[0x1c4c], dl
    _dx = _bx;                                  //mov dx, bx
    _bx = 0x340e;                               //mov bx, 0x340e
    _flags.direction = true;                    //std
    _si -= 1;                                   //dec si
    if (memory(_cs, 0x1C49) == 0x00)            //jz loc_20a8
        goto loc_20a8;
    goto loc_21ef;                              //jmp loc_21ef
loc_20a8:                                       //loc_20a8:
    _al = _cl;                                  //mov al, cl
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    if (_ch == 0xff)                            //jz loc_20b5
        goto loc_20b5;
    goto loc_213c;                              //jmp loc_213c
loc_20b5:                                       //loc_20b5:
    _ch = _ch ^ _ch;                            //xor ch, ch
loc_20b7:                                       //loc_20b7:
    _lodsb<MemData, DirBackward>();              //lodsb
    _xlat();                                    //xlat
    _al = (~_al);                               //not al
    {
        int t = memoryVideoGet(_es, _di);
        memoryVideoSet(_es, _di, _al);
        _al = t;
        //_xchg(memory(_es, _di), _al);               //xchg byte ptr es:[di], al
    }
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_20b7
        goto loc_20b7;
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _al = _cl;                                  //mov al, cl
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    _si += _ax;                                 //add si, ax
    _di -= _bp;                                 //sub di, bp
    memory(_cs, 0x1C4C) -= 1;                   //dec byte ptr cs:[0x1c4c]
    if (memory(_cs, 0x1C4C) != 0)               //jnz loc_20b7
        goto loc_20b7;
    _push(_dx);                                 //push dx
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _ax = 0x1003;                               //mov ax, 0x1003
    _out(_dx, _ax);                             //out dx, ax
    _dl = 0xc4;                                 //mov dl, 0xc4
    _al = 0x02;                                 //mov al, 0x2
    _out(_dx, _al);                             //out dx, al
    _al = memory(_cs, 0x1C5E);                  //mov al, cs:[0x1c5e]
    memory(_cs, 0x1C57) = (~memory(_cs, 0x1C57));//not byte ptr cs:[0x1c57]
    _dx = _pop();                               //pop dx
loc_20ee:                                       //loc_20ee:
    _push(_dx);                                 //push dx
    memory(_cs, 0x1C4D) = _al;                  //mov cs:[0x1c4d], al
    _dx = 0x03c5;                               //mov dx, 0x3c5
    _out(_dx, _al);                             //out dx, al
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _dl = memory(_cs, 0x1C52);                  //mov dl, byte ptr cs:[0x1c52]
    memory(_cs, 0x1C4C) = _dl;                  //mov byte ptr cs:[0x1c4c], dl
    _di = memory16(_cs, 0x1C58);                //mov di, word ptr cs:[0x1c58]
    _si = _si + memory16(_cs, 0x1C46);          //add si, word ptr cs:[0x1c46]
    _dx = _pop();                               //pop dx
loc_2111:                                       //loc_2111:
    _lodsb<MemData, DirBackward>();              //lodsb
    _xlat();                                    //xlat
    {
        int t = memoryVideoGet(_es, _di);
        memoryVideoSet(_es, _di, _al);
        _al = t;
        //_xchg(memory(_es, _di), _al);               //xchg byte ptr es:[di], al
    }
    _di += 1;                                   //inc di
    if (--_cx)                                  //loop loc_2111
        goto loc_2111;
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _al = _cl;                                  //mov al, cl
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    _si += _ax;                                 //add si, ax
    _di -= _bp;                                 //sub di, bp
    memory(_cs, 0x1C4C) -= 1;                   //dec byte ptr cs:[0x1c4c]
    if (memory(_cs, 0x1C4C) != 0)               //jnz loc_2111
        goto loc_2111;
    _al = memory(_cs, 0x1C4D);                  //mov al, cs:[0x1c4d]
    _al <<= 1;                                  //shl al, 1
    if (_al < 0x10)                             //jc loc_20ee
        goto loc_20ee;
    goto loc_24a9;                              //jmp loc_24a9
loc_213c:                                       //loc_213c:
    _lodsb<MemData, DirBackward>();              //lodsb
    _xlat();                                    //xlat
    _dl = _al;                                  //mov dl, al
    _al &= _ch;                                 //and al, ch
    _al |= _ah;                                 //or al, ah
    _al = (~_al);                               //not al
    {
        int t = memoryVideoGet(_es, _di);
        memoryVideoSet(_es, _di, _al);
        _al = t;
        //_xchg(memory(_es, _di), _al);               //xchg byte ptr es:[di], al
    }
    _di += 1;                                   //inc di
    _dl &= _dh;                                 //and dl, dh
    _ah = _dl;                                  //mov ah, dl
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_213c
        goto loc_213c;
    _ah = (~_ah);                               //not ah
    {
        int t = memoryVideoGet(_es, _di);
        memoryVideoSet(_es, _di, _ah);
        _ah = t;
        //_xchg(memory(_es, _di), _ah);               //xchg byte ptr es:[di], al
    }
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _al = _cl;                                  //mov al, cl
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    _si += _ax;                                 //add si, ax
    _di -= _bp;                                 //sub di, bp
    memory(_cs, 0x1C4C) -= 1;                   //dec byte ptr cs:[0x1c4c]
    if (memory(_cs, 0x1C4C) != 0)               //jnz loc_213c
        goto loc_213c;
    _push(_dx);                                 //push dx
    _cl = memory(_cs, 0x1C50);                  //mov cl, byte ptr cs:[0x1c50]
    _cl &= 0x07;                                //and cl, 0x7
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _al = 0x03;                                 //mov al, 0x3
    _ah = _cl;                                  //mov ah, cl
    _ah |= 0x10;                                //or ah, 0x10
    _out(_dx, _ax);                             //out dx, ax
    _dl = 0xc4;                                 //mov dl, 0xc4
    _al = 0x02;                                 //mov al, 0x2
    _out(_dx, _al);                             //out dx, al
    _al = memory(_cs, 0x1C5E);                  //mov al, cs:[0x1c5e]
    memory(_cs, 0x1C57) = (~memory(_cs, 0x1C57));//not byte ptr cs:[0x1c57]
    _dx = _pop();                               //pop dx
loc_2190:                                       //loc_2190:
    _push(_dx);                                 //push dx
    memory(_cs, 0x1C4D) = _al;                  //mov cs:[0x1c4d], al
    _dx = 0x03c5;                               //mov dx, 0x3c5
    _out(_dx, _al);                             //out dx, al
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _dl = memory(_cs, 0x1C52);                  //mov dl, byte ptr cs:[0x1c52]
    memory(_cs, 0x1C4C) = _dl;                  //mov byte ptr cs:[0x1c4c], dl
    _di = memory16(_cs, 0x1C58);                //mov di, word ptr cs:[0x1c58]
    _si = _si + memory16(_cs, 0x1C46);          //add si, word ptr cs:[0x1c46]
    _dx = _pop();                               //pop dx
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_21b5:                                       //loc_21b5:
    _lodsb<MemData, DirBackward>();              //lodsb
    _xlat();                                    //xlat
    _dl = _al;                                  //mov dl, al
    _al &= _ch;                                 //and al, ch
    _al |= _ah;                                 //or al, ah
    {
        int t = memoryVideoGet(_es, _di);
        memoryVideoSet(_es, _di, _al);
        _al = t;
        //_xchg(memory(_es, _di), _al);               //xchg byte ptr es:[di], al
    }
    _di += 1;                                   //inc di
    _dl &= _dh;                                 //and dl, dh
    _ah = _dl;                                  //mov ah, dl
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_21b5
        goto loc_21b5;
    {
        int t = memoryVideoGet(_es, _di);
        memoryVideoSet(_es, _di, _ah);
        _ah = t;
        //_xchg(memory(_es, _di), _ah);               //xchg byte ptr es:[di], al
    }
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _al = _cl;                                  //mov al, cl
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    _si += _ax;                                 //add si, ax
    _di -= _bp;                                 //sub di, bp
    memory(_cs, 0x1C4C) -= 1;                   //dec byte ptr cs:[0x1c4c]
    if (memory(_cs, 0x1C4C) != 0)               //jnz loc_21b5
        goto loc_21b5;
    _al = memory(_cs, 0x1C4D);                  //mov al, cs:[0x1c4d]
    _al <<= 1;                                  //shl al, 1
    if (_al < 0x10)                             //jc loc_2190
        goto loc_2190;
    goto loc_24a9;                              //jmp loc_24a9
loc_21ef:                                       //loc_21ef:
    _al = memory(_cs, 0x1C4B);                  //mov al, cs:[0x1c4b]
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
loc_21f6:                                       //loc_21f6:
    _al = memory(_cs, 0x1C53);                  //mov al, cs:[0x1c53]
    _cbw();                                     //cbw
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz loc_220a
        goto loc_220a;
    _ax -= 1;                                   //dec ax
    _si -= _ax;                                 //sub si, ax
    _lodsb<MemData, DirBackward>();              //lodsb
    _xlat();                                    //xlat
    _dl = _al;                                  //mov dl, al
    _cx += 1;                                   //inc cx
    goto loc_2219;                              //jmp loc_2219
loc_220a:                                       //loc_220a:
    _lodsb<MemData, DirBackward>();              //lodsb
    _xlat();                                    //xlat
    _dl = _al;                                  //mov dl, al
    _al &= _ch;                                 //and al, ch
    _al |= _ah;                                 //or al, ah
    _al = (~_al);                               //not al
    {
        int t = memoryVideoGet(_es, _di);
        memoryVideoSet(_es, _di, _al);
        _al = t;
        //_xchg(memory(_es, _di), _al);               //xchg byte ptr es:[di], al
    }
    _di += 1;                                   //inc di
loc_2219:                                       //loc_2219:
    _dl &= _dh;                                 //and dl, dh
    _ah = _dl;                                  //mov ah, dl
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_220a
        goto loc_220a;
    _ah = (~_ah);                               //not ah
    _ah = _ah | memory(_cs, 0x1C57);            //or ah, byte ptr cs:[0x1c57]
    {
        int t = memoryVideoGet(_es, _di);
        memoryVideoSet(_es, _di, _ah);
        _ah = t;
        //_xchg(memory(_es, _di), _ah);               //xchg byte ptr es:[di], al
    }
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _al = memory(_cs, 0x1C4B);                  //mov al, cs:[0x1c4b]
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    _al = _al - memory(_cs, 0x1C56);            //sub al, byte ptr cs:[0x1c56]
    _si += _ax;                                 //add si, ax
    _di -= _bp;                                 //sub di, bp
    memory(_cs, 0x1C4C) -= 1;                   //dec byte ptr cs:[0x1c4c]
    if (memory(_cs, 0x1C4C) != 0)               //jnz loc_21f6
        goto loc_21f6;
    _push(_dx);                                 //push dx
    _cl = memory(_cs, 0x1C50);                  //mov cl, byte ptr cs:[0x1c50]
    _cl &= 0x07;                                //and cl, 0x7
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _al = 0x03;                                 //mov al, 0x3
    _ah = _cl;                                  //mov ah, cl
    _ah |= 0x10;                                //or ah, 0x10
    _out(_dx, _ax);                             //out dx, ax
    _dl = 0xc4;                                 //mov dl, 0xc4
    _al = 0x02;                                 //mov al, 0x2
    _out(_dx, _al);                             //out dx, al
    _al = memory(_cs, 0x1C5E);                  //mov al, cs:[0x1c5e]
    memory(_cs, 0x1C57) = (~memory(_cs, 0x1C57));//not byte ptr cs:[0x1c57]
    _dx = _pop();                               //pop dx
loc_226a:                                       //loc_226a:
    _push(_dx);                                 //push dx
    memory(_cs, 0x1C4D) = _al;                  //mov cs:[0x1c4d], al
    _dx = 0x03c5;                               //mov dx, 0x3c5
    _out(_dx, _al);                             //out dx, al
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _dl = memory(_cs, 0x1C52);                  //mov dl, byte ptr cs:[0x1c52]
    memory(_cs, 0x1C4C) = _dl;                  //mov byte ptr cs:[0x1c4c], dl
    _di = memory16(_cs, 0x1C58);                //mov di, word ptr cs:[0x1c58]
    _si = _si + memory16(_cs, 0x1C46);          //add si, word ptr cs:[0x1c46]
    _dx = _pop();                               //pop dx
loc_228d:                                       //loc_228d:
    _al = memory(_cs, 0x1C53);                  //mov al, cs:[0x1c53]
    _cbw();                                     //cbw
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz loc_22a1
        goto loc_22a1;
    _ax -= 1;                                   //dec ax
    _si -= _ax;                                 //sub si, ax
    _lodsb<MemData, DirBackward>();              //lodsb
    _xlat();                                    //xlat
    _dl = _al;                                  //mov dl, al
    _cx += 1;                                   //inc cx
    goto loc_22ae;                              //jmp loc_22ae
loc_22a1:                                       //loc_22a1:
    _lodsb<MemData, DirBackward>();              //lodsb
    _xlat();                                    //xlat
    _dl = _al;                                  //mov dl, al
    _al &= _ch;                                 //and al, ch
    _al |= _ah;                                 //or al, ah
    {
        int t = memoryVideoGet(_es, _di);
        memoryVideoSet(_es, _di, _al);
        _al = t;
        //_xchg(memory(_es, _di), _ah);               //xchg byte ptr es:[di], al
    }
    _di += 1;                                   //inc di
loc_22ae:                                       //loc_22ae:
    _dl &= _dh;                                 //and dl, dh
    _ah = _dl;                                  //mov ah, dl
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_22a1
        goto loc_22a1;
    _ah = _ah & memory(_cs, 0x1C57);            //and ah, byte ptr cs:[0x1c57]
    {
        int t = memoryVideoGet(_es, _di);
        memoryVideoSet(_es, _di, _ah);
        _ah = t;
        //_xchg(memory(_es, _di), _ah);               //xchg byte ptr es:[di], al
    }
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _al = memory(_cs, 0x1C4B);                  //mov al, cs:[0x1c4b]
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    _al = _al - memory(_cs, 0x1C56);            //sub al, byte ptr cs:[0x1c56]
    _si += _ax;                                 //add si, ax
    _di -= _bp;                                 //sub di, bp
    memory(_cs, 0x1C4C) -= 1;                   //dec byte ptr cs:[0x1c4c]
    if (memory(_cs, 0x1C4C) != 0)               //jnz loc_228d
        goto loc_228d;
    _al = memory(_cs, 0x1C4D);                  //mov al, cs:[0x1c4d]
    _al <<= 1;                                  //shl al, 1
    if (_al >= 0x10)                            //jnc loc_22e6
        goto loc_22e6;
    goto loc_226a;                              //jmp loc_226a
loc_22e6:                                       //loc_22e6:
    goto loc_24a9;                              //jmp loc_24a9
loc_22e9:                                       //loc_22e9:
    if (memory(_cs, 0x1C49) == 0x00)            //jz loc_22f4
        goto loc_22f4;
    goto loc_23e2;                              //jmp loc_23e2
loc_22f4:                                       //loc_22f4:
    if (_ch != 0xff)                            //jnz loc_2354
        goto loc_2354;
    _ch = _ch ^ _ch;                            //xor ch, ch
loc_22fb:                                       //loc_22fb:
    _lodsb<MemData, DirForward>();              //lodsb
    _al = (~_al);                               //not al
    // gabo!!!
    memoryVideoGet(_es, _di);
    //_scasb();                                   //scasb
    //_di -= 1;                                   //dec di
    _stosb<MemVideo, DirForward>();              //stosb
    if (--_cx)                                  //loop loc_22fb
        goto loc_22fb;
    _cl = _dh;                                  //mov cl, dh
    _di -= _bp;                                 //sub di, bp
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz loc_22fb
        goto loc_22fb;
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _ax = 0x1003;                               //mov ax, 0x1003
    _out(_dx, _ax);                             //out dx, ax
    _dl = 0xc4;                                 //mov dl, 0xc4
    _al = 0x02;                                 //mov al, 0x2
    _out(_dx, _al);                             //out dx, al
    _al = memory(_cs, 0x1C5E);                  //mov al, cs:[0x1c5e]
loc_231b:                                       //loc_231b:
    memory(_cs, 0x1C4D) = _al;                  //mov cs:[0x1c4d], al
    _dx = 0x03c5;                               //mov dx, 0x3c5
    _out(_dx, _al);                             //out dx, al
    _dh = memory(_cs, 0x1C4A);                  //mov dh, byte ptr cs:[0x1c4a]
    _cl = _dh;                                  //mov cl, dh
    _dl = memory(_cs, 0x1C52);                  //mov dl, byte ptr cs:[0x1c52]
    _di = memory16(_cs, 0x1C58);                //mov di, word ptr cs:[0x1c58]
    _si = _si + memory16(_cs, 0x1C46);          //add si, word ptr cs:[0x1c46]
loc_2339:                                       //loc_2339:
    _lodsb<MemData, DirForward>();              //lodsb
    // gabo!!!
    memoryVideoGet(_es, _di);
    //_scasb();                                   //scasb
    //_di -= 1;                                   //dec di
    _stosb<MemVideo, DirForward>();              //stosb
    if (--_cx)                                  //loop loc_2339
        goto loc_2339;
    _di -= _bp;                                 //sub di, bp
    _cl = _dh;                                  //mov cl, dh
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz loc_2339
        goto loc_2339;
    _al = memory(_cs, 0x1C4D);                  //mov al, cs:[0x1c4d]
    _al <<= 1;                                  //shl al, 1
    if (_al < 0x10)                             //jc loc_231b
        goto loc_231b;
    goto loc_24a9;                              //jmp loc_24a9
loc_2354:                                       //loc_2354:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_2356:                                       //loc_2356:
    _lodsb<MemData, DirForward>();              //lodsb
    _bl = _al;                                  //mov bl, al
    _al &= _ch;                                 //and al, ch
    _al |= _ah;                                 //or al, ah
    _al = (~_al);                               //not al
    // gabo!!!
    memoryVideoGet(_es, _di);
    //_scasb();                                   //scasb
    //_di -= 1;                                   //dec di
    _stosb<MemVideo, DirForward>();              //stosb
    _bl &= _bh;                                 //and bl, bh
    _ah = _bl;                                  //mov ah, bl
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_2356
        goto loc_2356;
    _ah = (~_ah);                               //not ah
    {
        int t = memoryVideoGet(_es, _di);
        memoryVideoSet(_es, _di, _ah);
        _ah = t;
//        _xchg(memory(_es, _di), _ah);               //xchg byte ptr es:[di], ah
    }
    _cl = _dh;                                  //mov cl, dh
    _di -= _bp;                                 //sub di, bp
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz loc_2354
        goto loc_2354;
    _cl = memory(_cs, 0x1C50);                  //mov cl, byte ptr cs:[0x1c50]
    _cl &= 0x07;                                //and cl, 0x7
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _al = 0x03;                                 //mov al, 0x3
    _ah = _cl;                                  //mov ah, cl
    _ah |= 0x10;                                //or ah, 0x10
    _out(_dx, _ax);                             //out dx, ax
    _dl = 0xc4;                                 //mov dl, 0xc4
    _al = 0x02;                                 //mov al, 0x2
    _out(_dx, _al);                             //out dx, al
    _al = memory(_cs, 0x1C5E);                  //mov al, cs:[0x1c5e]
    memory(_cs, 0x1C57) = (~memory(_cs, 0x1C57));//not byte ptr cs:[0x1c57]
loc_2398:                                       //loc_2398:
    memory(_cs, 0x1C4D) = _al;                  //mov cs:[0x1c4d], al
    _dx = 0x03c5;                               //mov dx, 0x3c5
    _out(_dx, _al);                             //out dx, al
    _dh = memory(_cs, 0x1C4A);                  //mov dh, byte ptr cs:[0x1c4a]
    _cl = _dh;                                  //mov cl, dh
    _dl = memory(_cs, 0x1C52);                  //mov dl, byte ptr cs:[0x1c52]
    _di = memory16(_cs, 0x1C58);                //mov di, word ptr cs:[0x1c58]
    _si = _si + memory16(_cs, 0x1C46);          //add si, word ptr cs:[0x1c46]
loc_23b6:                                       //loc_23b6:
    _ax = _ax ^ _ax;                            //xor ax, ax
loc_23b8:                                       //loc_23b8:
    _lodsb<MemData, DirForward>();              //lodsb
    _bl = _al;                                  //mov bl, al
    _al &= _ch;                                 //and al, ch
    _al |= _ah;                                 //or al, ah
    // gabo!!!
    memoryVideoGet(_es, _di);
    //_scasb();                                   //scasb
    //_di -= 1;                                   //dec di
    _stosb<MemVideo, DirForward>();              //stosb
    _bl &= _bh;                                 //and bl, bh
    _ah = _bl;                                  //mov ah, bl
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_23b8
        goto loc_23b8;
    {
        int t = memoryVideoGet(_es, _di);
        memoryVideoSet(_es, _di, _ah);
        _ah = t;
//        _xchg(memory(_es, _di), _ah);               //xchg byte ptr es:[di], ah
    }
    _cl = _dh;                                  //mov cl, dh
    _di -= _bp;                                 //sub di, bp
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz loc_23b6
        goto loc_23b6;
    _al = memory(_cs, 0x1C4D);                  //mov al, cs:[0x1c4d]
    _al <<= 1;                                  //shl al, 1
    if (_al < 0x10)                             //jc loc_2398
        goto loc_2398;
    goto loc_24a9;                              //jmp loc_24a9
loc_23e2:                                       //loc_23e2:
    _al = memory(_cs, 0x1C53);                  //mov al, cs:[0x1c53]
    _cbw();                                     //cbw
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz loc_23f4
        goto loc_23f4;
    _ax -= 1;                                   //dec ax
    _cx += 1;                                   //inc cx
    _si += _ax;                                 //add si, ax
    _lodsb<MemData, DirForward>();              //lodsb
    _bl = _al;                                  //mov bl, al
    goto loc_2400;                              //jmp loc_2400
loc_23f4:                                       //loc_23f4:
    _lodsb<MemData, DirForward>();              //lodsb
    _bl = _al;                                  //mov bl, al
    _al &= _ch;                                 //and al, ch
    _al |= _ah;                                 //or al, ah
    _al = (~_al);                               //not al
    memoryVideoGet(_es, _di);
    //_scasb();                                   //scasb
    //_di -= 1;                                   //dec di
    _stosb<MemVideo, DirForward>();              //stosb
loc_2400:                                       //loc_2400:
    _bl &= _bh;                                 //and bl, bh
    _ah = _bl;                                  //mov ah, bl
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_23f4
        goto loc_23f4;
    _ah = (~_ah);                               //not ah
    _ah = _ah | memory(_cs, 0x1C57);            //or ah, byte ptr cs:[0x1c57]
    {
        int t = memoryVideoGet(_es, _di);
        memoryVideoSet(_es, _di, _ah);
        _ah = t;
//        _xchg(memory(_es, _di), _ah);               //xchg byte ptr es:[di], ah
    }
    _al = memory(_cs, 0x1C56);                  //mov al, cs:[0x1c56]
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _di -= _bp;                                 //sub di, bp
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz loc_23e2
        goto loc_23e2;
    _cl = memory(_cs, 0x1C50);                  //mov cl, byte ptr cs:[0x1c50]
    _cl &= 0x07;                                //and cl, 0x7
    _dx = 0x03ce;                               //mov dx, 0x3ce
    _al = 0x03;                                 //mov al, 0x3
    _ah = _cl;                                  //mov ah, cl
    _ah |= 0x10;                                //or ah, 0x10
    _out(_dx, _ax);                             //out dx, ax
    _dl = 0xc4;                                 //mov dl, 0xc4
    _al = 0x02;                                 //mov al, 0x2
    _out(_dx, _al);                             //out dx, al
    _al = memory(_cs, 0x1C5E);                  //mov al, cs:[0x1c5e]
    memory(_cs, 0x1C57) = (~memory(_cs, 0x1C57));//not byte ptr cs:[0x1c57]
loc_2445:                                       //loc_2445:
    memory(_cs, 0x1C4D) = _al;                  //mov cs:[0x1c4d], al
    _dx = 0x03c5;                               //mov dx, 0x3c5
    _out(_dx, _al);                             //out dx, al
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _dl = memory(_cs, 0x1C52);                  //mov dl, byte ptr cs:[0x1c52]
    _di = memory16(_cs, 0x1C58);                //mov di, word ptr cs:[0x1c58]
    _si = _si + memory16(_cs, 0x1C46);          //add si, word ptr cs:[0x1c46]
loc_2461:                                       //loc_2461:
    _al = memory(_cs, 0x1C53);                  //mov al, cs:[0x1c53]
    _cbw();                                     //cbw
    _ax |= _ax;                                 //or ax, ax
    if (_ax == 0)                               //jz loc_2473
        goto loc_2473;
    _ax -= 1;                                   //dec ax
    _cx += 1;                                   //inc cx
    _si += _ax;                                 //add si, ax
    _lodsb<MemData, DirForward>();              //lodsb
    _bl = _al;                                  //mov bl, al
    goto loc_247d;                              //jmp loc_247d
loc_2473:                                       //loc_2473:
    _lodsb<MemData, DirForward>();              //lodsb
    _bl = _al;                                  //mov bl, al
    _al &= _ch;                                 //and al, ch
    _al |= _ah;                                 //or al, ah
    // gabo!!!
    memoryVideoGet(_es, _di);
    //_scasb();                                   //scasb
    //_di -= 1;                                   //dec di
    _di -= 1;                                   //dec di
    _stosb<MemVideo, DirForward>();              //stosb
loc_247d:                                       //loc_247d:
    _bl &= _bh;                                 //and bl, bh
    _ah = _bl;                                  //mov ah, bl
    _cl -= 1;                                   //dec cl
    if (_cl != 0)                               //jnz loc_2473
        goto loc_2473;
    _ah = _ah & memory(_cs, 0x1C57);            //and ah, byte ptr cs:[0x1c57]
    {
        int t = memoryVideoGet(_es, _di);
        memoryVideoSet(_es, _di, _ah);
        _ah = t;
//        _xchg(memory(_es, _di), _ah);               //xchg byte ptr es:[di], ah
    }
    _al = memory(_cs, 0x1C56);                  //mov al, cs:[0x1c56]
    _cbw();                                     //cbw
    _si += _ax;                                 //add si, ax
    _cl = memory(_cs, 0x1C4A);                  //mov cl, byte ptr cs:[0x1c4a]
    _di -= _bp;                                 //sub di, bp
    _dl -= 1;                                   //dec dl
    if (_dl != 0)                               //jnz loc_2461
        goto loc_2461;
    _al = memory(_cs, 0x1C4D);                  //mov al, cs:[0x1c4d]
    _al <<= 1;                                  //shl al, 1
    if (_al < 0x10)                             //jc loc_2445
        goto loc_2445;
loc_24a9:                                       //loc_24a9:
    _flags.direction = false;                   //cld
    _ax = reloc(0x168f);                               //mov ax, reloc(0x168f)
    _ds = _ax;                                  //mov ds, ax
    _si = memory16(_ds, 21114);                 //mov si, word ptr [0x527a]
    _si -= 0x0012;                              //sub si, 0x12
    if (_si < 0x527c)                           //jc loc_24bf
        goto loc_24bf;
    goto loc_1c72;                              //jmp loc_1c72
loc_24bf:                                       //loc_24bf:
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
