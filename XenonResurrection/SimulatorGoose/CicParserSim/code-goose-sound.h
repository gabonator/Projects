void sub_1387D();
void sub_13914();
void sub_139A3();
void sub_139DB();
void sub_13A3B();

void sub_1387D()
{
    _al = memory(_ds, 0x955E);                    //mov al, byte_1CFAE
    if (_al == 0x00)                              //jz short loc_1389B
      goto loc_1389B;
    _al = memory(_ds, 0x9506);                    //mov al, byte_1CF56
    if (_al == 0x00)                              //jz short loc_13890
      goto loc_13890;
    sub_139DB();                                  //call sub_139DB
    goto loc_1389B;                               //jmp short loc_1389B
loc_13890:                                        //loc_13890:
    memory16(_ds, 0x955F) = 0;                    //mov word_1CFAF, 0
    memory(_ds, 0x955E) = 0;                      //mov byte_1CFAE, 0
loc_1389B:                                        //loc_1389B:
    _al = memory(_ds, 0x9550);                    //mov al, byte_1CFA0
    if (_al != 0x00)                              //jnz short loc_138A3
      goto loc_138A3;
    return;                                       //retn
loc_138A3:                                        //loc_138A3:
    memory(_ds, 0x9557) -= 1;                     //dec byte_1CFA7
    if (memory(_ds, 0x9557) != 0)                 //jnz short loc_138D4
      goto loc_138D4;
    _al = memory(_ds, 0x9506);                    //mov al, byte_1CF56
    if (_al != 0x00)                              //jnz short loc_138B4
      goto loc_138B4;
    sub_139A3();                                  //call sub_139A3
    return;                                       //retn
loc_138B4:                                        //loc_138B4:
    _al = memory(_ds, 0x9551);                    //mov al, byte_1CFA1
    if (_al == 0x00)                              //jz short loc_138D0
      goto loc_138D0;
    memory(_ds, 0x9550) = _al;                    //mov byte_1CFA0, al
    _bl = memory(_ds, 0x9552);                    //mov bl, byte_1CFA2
    memory(_ds, 0x9551) = _bl;                    //mov byte_1CFA1, bl
    memory(_ds, 0x9552) = 0;                      //mov byte_1CFA2, 0
    sub_13914();                                  //call sub_13914
    goto locret_138D3;                            //jmp short locret_138D3
loc_138D0:                                        //loc_138D0:
    sub_139A3();                                  //call sub_139A3
locret_138D3:                                     //locret_138D3:
    return;                                       //retn
loc_138D4:                                        //loc_138D4:
    _ax = memory16(_ds, 0x9558);                  //mov ax, word_1CFA8
    _ax = _ax + memory16(_ds, 0x955A);            //add ax, word_1CFAA
    memory16(_ds, 0x9558) = _ax;                  //mov word_1CFA8, ax
    _al = memory(_ds, 0x9553);                    //mov al, byte_1CFA3
    if (_al == 0x00)                              //jz short loc_138FD
      goto loc_138FD;
    _bl = memory(_ds, 0x9554);                    //mov bl, byte_1CFA4
    memory(_ds, 0x9554) += 1;                     //inc byte_1CFA4
    _bx &= 0x0f;                                  //and bx, 0Fh
    _bx <<= 1;                                    //shl bx, 1
    _bx = _bx + memory16(_ds, 0x9555);            //add bx, word_1CFA5
    _ax = memory16(_ds, _bx);                     //mov ax, [bx]
    memory16(_ds, 0x955C) = _ax;                  //mov word_1CFAC, ax
    goto loc_13903;                               //jmp short loc_13903
loc_138FD:                                        //loc_138FD:
    memory16(_ds, 0x955C) = 0;                    //mov word_1CFAC, 0
loc_13903:                                        //loc_13903:
    _ax = memory16(_ds, 0x9558);                  //mov ax, word_1CFA8
    memory16(_ds, 0x955C) += _ax;                 //add word_1CFAC, ax
    _ax = memory16(_ds, 0x955C);                  //mov ax, word_1CFAC
    _out(0x42, _al);                              //out 42h, al
    _al = _ah;                                    //mov al, ah
    _out(0x42, _al);                              //out 42h, al
}


void sub_139A3()
{
    _al = 0x00;                                   //mov al, 0
    memory(_ds, 0x9550) = _al;                    //mov byte_1CFA0, al
    memory(_ds, 0x9551) = _al;                    //mov byte_1CFA1, al
    memory(_ds, 0x9552) = _al;                    //mov byte_1CFA2, al
    memory(_ds, 0x9557) = _al;                    //mov byte_1CFA7, al
    _in(_al, 0x61);                               //in al, 61h
    _al &= 0xfc;                                  //and al, 0FCh
    _out(0x61, _al);                              //out 61h, al
}

void sub_139DB()
{
    memory(_ds, 0x9561) -= 1;                     //dec byte_1CFB1
    if ((char)memory(_ds, 0x9561) < 0)            //js short loc_139E2
      goto loc_139E2;
    return;                                       //retn
loc_139E2:                                        //loc_139E2:
    memory(_ds, 0x9561) = 7;                      //mov byte_1CFB1, 7
    memory(_ds, 0x8C57) = 0x0e;                   //mov byte_1C6A7, 0Eh
    memory(_ds, 0x8C56) = 4;                      //mov byte_1C6A6, 4
    _bx = memory16(_ds, 0x955F);                  //mov bx, word_1CFAF
    _si = memory16(_ds, 0x9562);                  //mov si, word_1CFB2
    _al = memory(_ds, _bx + _si);                 //mov al, [bx+si]
    if (_al != 0xff)                              //jnz short loc_13A05
      goto loc_13A05;
    memory(_ds, 0x955E) = 0;                      //mov byte_1CFAE, 0
    return;                                       //retn
loc_13A05:                                        //loc_13A05:
    if (_al != 0x00)                              //jnz short loc_13A29
      goto loc_13A29;
    _al = memory(_ds, 0x9550);                    //mov al, byte_1CFA0
    if (_al != 0x00)                              //jnz short loc_13A25
      goto loc_13A25;
    memory(_ds, 0x8C56) = 0;                      //mov byte_1C6A6, 0
    memory(_ds, 0x8C57) = 6;                      //mov byte_1C6A7, 6
    _bx &= 0x1f;                                  //and bx, 1Fh
    _al = memory(_ds, _bx + -29091);              //mov al, [bx-71A3h]
    _al -= 0x0c;                                  //sub al, 0Ch
    goto loc_13A27;                               //jmp short loc_13A27
loc_13A25:                                        //loc_13A25:
    _al = 0x00;                                   //mov al, 0
loc_13A27:                                        //loc_13A27:
    goto loc_13A33;                               //jmp short loc_13A33
loc_13A29:                                        //loc_13A29:
    if (_al != 0xfe)                              //jnz short loc_13A31
      goto loc_13A31;
    _al = 0x00;                                   //mov al, 0
    goto loc_13A33;                               //jmp short loc_13A33
loc_13A31:                                        //loc_13A31:
    _al += 0x0c;                                  //add al, 0Ch
loc_13A33:                                        //loc_13A33:
    sub_13A3B();                                  //call sub_13A3B
    memory16(_ds, 0x955F) += 1;                   //inc word_1CFAF
}

void sub_13A3B()
{
    _al -= 1;                                     //dec al
    if ((char)_al >= 0)                           //jns short loc_13A40
      goto loc_13A40;
    return;                                       //retn
loc_13A40:                                        //loc_13A40:
    _bl = _al;                                    //mov bl, al
    _bh = 0x00;                                   //mov bh, 0
    _bx <<= 1;                                    //shl bx, 1
    _ax = memory16(_ds, _bx + -29468);            //mov ax, [bx-731Ch]
    memory16(_ds, 0x8C58) = _ax;                  //mov word_1C6A8, ax
    _al = 0x0f;                                   //mov al, 0Fh
    memory(_ds, 0x9550) = _al;                    //mov byte_1CFA0, al
    sub_13914();                                  //call sub_13914
}
